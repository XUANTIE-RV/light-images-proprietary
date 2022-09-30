#!/usr/bin/python
###############################################################################
#@Copyright     Copyright (c) Imagination Technologies Ltd. All Rights Reserved
#@License       Strictly Confidential.
###############################################################################

"""
This script combines json files holding data from HWPerf streams. Files
hold data from firmware, host and client streams.
Attempt is made to change time domain of all events coming from firmware
to CPU time domain. All json objects are marked with appropriate value of
'tdomain' filed (this should help with identification of objects in the
merged json file):

        CPU packet originated from host buffer

        GPU packet originated from firmware buffer and it was impossible to
            calculate CPU time stamp from available data (probably
            synchronisation packets were not available)

      G2CPU time domain changed from GPU to CPU thanks to synchronisation
            data

  G2CPU_NTW some synchronisation data was available somewhere before this
            packet but it was lost at some point, so the time stamp of this
            packet may be inaccurate
"""

# pylint: disable=I0011,C0103,C0325,C0330,R0201,R0902,R0903,R0912

import sys
import os
import re
import json
import logging
from argparse import ArgumentParser

logging.basicConfig(level=logging.WARN, format='%(levelname)s: %(message)s')
log = logging.getLogger(__name__)

if (sys.stdout.isatty()):
    logging.addLevelName(logging.INFO, '\033[1mInfo\033[0m')
    logging.addLevelName(logging.WARN, '\033[1;35mWarning\033[0m')
    logging.addLevelName(logging.ERROR, '\033[1;31mError\033[0m')
else:
    logging.addLevelName(logging.INFO, 'Info')
    logging.addLevelName(logging.WARN, 'Warning')
    logging.addLevelName(logging.ERROR, 'Error')

def print_exception():
    """Prints exception's stack trace."""
    dummy, ex_obj, tb = sys.exc_info()
    l = tb.tb_lineno
    f = tb.tb_frame.f_code.co_filename
    print('Exception: "{}" in {}:{}'.format(ex_obj, f, l))

def s2ns(ts):
    """Converts seconds to nanoseconds."""
    return ts * 1e9

def ns2us(ts):
    """Converts nanoseconds to microseconds."""
    return int(ts / 1000.0 + 0.5)

class InvalidArgumentException(Exception):
    """Throws when invalid arguments are passed from command line."""
    def __init__(self, msg=None):
        self._msg = msg
        super(self.__class__, self).__init__()

    def __str__(self):
        return self._msg if self._msg else "InvalidArgumentException"

class WrongFormatException(Exception):
    """Streams have inconsistent format e.g. raw and normal."""
    def __init__(self):
        super(self.__class__, self).__init__()

    def __str__(self):
        return 'Files format mismatch.'

class Args(object):
    """Processes and validates command line arguments."""
    def __init__(self, args=None):
        self._clockspeed = None
        self._keepgputs = None
        self._keepsyncev = None
        self._dir = None
        self._gpu = dict()
        self._host = dict()
        self._client = dict()
        self._out = dict()

        self._devices = set()

        self._is_fw_default = False
        self._is_host_default = False
        self._is_client_default = False

        self._parser = ArgumentParser()
        self._define()
        self._parse(args)

    def _define(self):
        self._parser.add_argument('-v', '--verbose', action='count',
                          help='Verbosity level of the messages')
        self._parser.add_argument('-d', '--dir', dest='dirr',
                          help='Path to directory containing hwperf.json and'
                          ' hwperf_host.json. If not specified, current'
                          ' directory will be used.', metavar='PATH',
                          default='.')
        self._parser.add_argument('-f', '--fw', dest='fw',
                          help='File name of the json file produced from'
                          ' hwperf.bin file. If --dir option not given full'
                          ' file path needs to be specified.'
                          ' If this option is not given default name will be'
                          ' assumed (hwperf.json or hwperf.raw.json).',
                          metavar='FILE')
        self._parser.add_argument('-s', '--host', dest='host',
                          help='File name of the json file produced from'
                          ' hwperf.bin file. If --dir option not given full'
                          ' file path needs to be specified.'
                          ' If this option is not given default name will be'
                          ' assumed (hwperf_host.json or hwper_host.raw.json).',
                          metavar='FILE')
        self._parser.add_argument('-c', '--prefix', dest='client',
                          help='File name prefix of json files produced from'
                          ' hwperf_client_<pid>.bin files. If --dir option'
                          ' not given full path needs to be specified.'
                          ' If this option is not given the default prefix will'
                          ' be assumed (hwperf_client_<pid>.json).',
                          metavar='PREFIX')
        self._parser.add_argument('--clockspeed', dest='clk',
                          help='Overrides clock speed received in firmware'
                          ' packages. This is useful e.g. for emulators.'
                          ' The value is in Hz. It\'s possible to use "kHz"'
                          ' and "MHz" postfix e.g. 3.45MHz will override'
                          ' the GPU clock with value 3450000Hz.',
                          metavar='CLK')
        self._parser.add_argument('--keepgputs', dest='keepgputs',
                          action='store_true', help='If this option is used the'
                          ' GPU packets will keep original timestamps in'
                          ' "start_gpu" and "end_gpu" fileds')
        self._parser.add_argument('--keepsyncev', dest='keepsyncev',
                          action='store_true', help='If this option is used the'
                          ' synchronisation events will not be removed from'
                          ' the merged json file.')
        self._parser.add_argument('-o', '--out', dest='out',
                          help='Output file. If not given default name will be'
                          ' assumed (hwperf_merged_<iDeviceID>.json).',
                          metavar='FILE')

    def _parse(self, args=None):
        args = self._parser.parse_args(args)

        # set verbosity level
        if args.verbose:
            log.setLevel(logging.INFO)

        self._validate_clockspeed(args.clk)
        self._validate_dir(args.dirr)
        self._validate_fw_files(args.fw)
        self._validate_host_files(args.host)
        self._validate_client_files(args.client)
        self._validate_input_format()
        self._validate_out(args.out)

        self._keepgputs = args.keepgputs
        if self._clockspeed:
            log.info('GPU clock will be overwritten with specified value:'
                     ' %0.2fHz', self._clockspeed)

        self._keepsyncev = args.keepsyncev

    def _validate_clockspeed(self, clk):
        # no value so nothing to do here
        if not clk:
            return

        m = 1.0

        if clk[-3:] == 'kHz':
            m = 1e3
            clk = clk[:-3]
        elif clk[-3:] == 'MHz':
            m = 1e6
            clk = clk[:-3]

        clk = float(clk) * m

        if clk > 0:
            self._clockspeed = clk
        else:
            raise ValueError('Invalid clock value: "{}"'.format(clk))

    def _validate_dir(self, dirr):
        if not os.path.isdir(dirr):
            raise IOError('Directory `' + dirr + '` does not exist.')
        self._dir = dirr

    def _validate_fw_files(self, fw):
        if not fw:
            # # look for default names 'hwperf_fw_<iDeviceID>.json' and
            # # 'hwperf_fw_<iDeviceID>.raw.json'
            fname_re = re.compile(r'hwperf_fw_(?P<devid>\d+)\.(raw\.)*json')

            for entry in os.listdir(self._dir):
                match = fname_re.match(entry)
                if match:
                    fpath = os.path.join(self._dir, entry)
                    devid = int(match.group('devid'))
                    log.info('found firmware stream file: %s', fpath)
                    if devid not in self._gpu:
                        self._gpu[devid] = list()
                    self._gpu[devid].append(fpath)
                    self._devices.add(devid)
            self._is_fw_default = True
        else:
            fpath = os.path.join(self._dir, fw)
            if os.path.isfile(fpath):
                log.info('found firmware stream file: %s', fpath)
                self._gpu = {0: [fpath]}
                self._devices.add(0)
            else:
                raise IOError('File `{}` does not exist.'.format(fpath))

    def _validate_host_files(self, host):
        if not host:
            # look for default names 'hwperf_host_<iDeviceID>.json' and
            # 'hwperf_host_<iDeviceID>.raw.json'
            fname_re = re.compile(r'hwperf_host_(?P<devid>\d+)\.(raw\.)*json')
            for entry in os.listdir(self._dir):
                match = fname_re.match(entry)
                if match:
                    fpath = os.path.join(self._dir, entry)
                    devid = int(match.group('devid'))
                    log.info('found host stream file: %s', fpath)
                    if devid not in self._host:
                        self._host[devid] = list()
                    self._host[devid].append(fpath)
                    self._devices.add(devid)
            self._is_host_default = True
        else:
            fpath = os.path.join(self._dir, host)
            if os.path.isfile(fpath):
                log.info('found host stream file: %s', fpath)
                self._host = {0: [fpath]}
                self._devices.add(0)
            else:
                raise IOError('File `{}` does not exist.'.format(fpath))

    def _validate_client_files(self, prefix):
        fname_re = re.compile(r'hwperf_client_(?P<devid>\d+)_(?P<pid>\d+)'
                              r'\.(raw\.)*json')

        for entry in os.listdir(self._dir):
            if not prefix:
                match = fname_re.match(entry)
                if match:
                    fpath = os.path.join(self._dir, entry)
                    devid = int(match.group('devid'))
                    log.info('found client stream file: %s', fpath)
                    if devid not in self._client:
                        self._client[devid] = list()
                    self._client[devid].append(fpath)
                    self._devices.add(devid)
                self._is_client_default = True
            else:
                if entry.startswith(prefix) and entry.endswith('.json'):
                    fpath = os.path.join(self._dir, entry)
                    log.info('found client stream file: %s', fpath)
                    if 0 not in self._client:
                        self._client[0] = list()
                    self._client[0].append(fpath)
                    self._devices.add(0)

        if prefix and not self._client:
            raise IOError('No files starting with `{}` prefix found.'
                          .format(prefix))

    def _validate_input_format(self):
        """Preliminary check of the input format based on the file names."""
        if self._is_fw_default and self._is_host_default and \
           self._is_client_default:

            def file_check(lst, files):
                """Checks if file contains 'raw'."""
                is_raw = False
                for fname in files:
                    if 'raw' in fname:
                        is_raw = True
                    lst.append(is_raw)

            for devid in self._devices:
                to_check = list()

                if devid in self._client:
                    file_check(to_check, self._client[devid])
                if devid in self._gpu:
                    file_check(to_check, self._gpu[devid])
                if devid in self._host:
                    file_check(to_check, self._host[devid])

                if to_check:
                    last = to_check[0]
                    for curr in to_check[1:]:
                        if curr != last:
                            raise WrongFormatException()

    def _validate_out(self, out):
        # do output filename initialisation
        if not out:
            # after _validate_input_format() we know that files should have
            # same format so check only first file for the extension
            # we do this assumption only at this stage and don't modify filename
            # later even if the real formats don't match

            get_name = lambda l, d: 'hwperf_merged_' + str(d) + \
                ('.raw.json' if 'raw' in l[0] else '.json')

            for devid in self._devices:
                self._out[devid] = 'hwperf_merged_{}.json'.format(devid)

                if devid in self._gpu:
                    self._out[devid] = get_name(self._gpu[devid], devid)
                elif devid in self._host:
                    self._out[devid] = get_name(self._host[devid], devid)
                elif devid in self._client:
                    self._out[devid] = get_name(self._client[devid], devid)
        else:
            if self._is_fw_default and self._is_host_default \
                    and self._is_client_default:
                raise InvalidArgumentException("input file not given")

            self._out[0] = out

    def clockspeed(self):
        """Override GPU's clock speed."""
        return self._clockspeed

    def keepgputs(self):
        """Keep GPU time stamp in json file."""
        return self._keepgputs

    def keepsyncev(self):
        """Keep synchronisation events in merged json."""
        return self._keepsyncev

    def fwjson_fname(self):
        """Returns dictionary with Firmware file names."""
        return self._gpu

    def hostjson_fname(self):
        """Returns dictionary with Host file names."""
        return self._host

    def clientjson_fnames(self):
        """Returns dictionary of lists with Client file names."""
        return self._client

    def device_list(self):
        """Returns list of all device IDs that has been detected."""
        return self._devices

    def out_fname(self):
        """Returns list of all output files names as a dictionary where the
        key is iDeviceID."""
        return self._out

class SyncPoint(object):
    """Represents synchronisation point between Host and Firmware time
    domains"""
    def __init__(self, tcpu=None, tgpu=None, fgpu=None):
        self.tcpu = tcpu
        self.tgpu = tgpu
        self.fgpu = fgpu
        self.tw = True

    def __str__(self):
        return 'SyncPoint: tCPU: {}; tGPU: {}; fGPU: {}'\
                .format(self.tcpu, self.tgpu, self.fgpu)

    def __eq__(self, other):
        return self.tcpu == other.tcpu and \
            self.tgpu == other.tgpu and \
            self.fgpu == other.fgpu

class Hwperf(object):
    """Base class for all HWPerf JSON streams."""
    def __init__(self, filename=None, jfile=None):
        self._js = self._load(filename, jfile)

    def _load(self, filename, jfile):
        if jfile:
            return json.load(jfile)
        else:
            with open(filename, 'r') as f:
                return json.load(f)

    def is_raw(self):
        """Returns True if RAW json."""
        return True if 'hwperf_packets' in self._js else False

    def get_json(self):
        """Returns json dictionary."""
        return self._js

    def process(self):
        """Preprocess all of the events in the stream."""
        pass

class HwperfFw(Hwperf):
    """Represents HWPerf Firmware stream."""
    def __init__(self, args, syncline, filename=None, jfile=None):
        super(self.__class__, self).__init__(filename, jfile)
        self._to_remove = list()
        self._syncline = syncline
        self._td_switch = False
        self._sync_types = {'PWRCHG': self._process_normal_pwrchg,
                            'CLKCHG': self._process_normal_clkchg,
                            '23_PWR_CHG': self._process_raw_pwrchg,
                            '1A_CLKS_CHG': self._process_raw_clkchg}
        self._clk = args.clockspeed()
        self._keepgputs = args.keepgputs()
        self._keepsyncev = args.keepsyncev

    def process(self):
        if self.is_raw():
            self._process_raw()
        else:
            self._process_normal()

    def _process_raw(self):
        packets = self._js['hwperf_packets']
        name_key = 'type'

        for packet in packets:
            self._keep_gpu_ts(packet)

            name = packet[name_key]
            if name in self._sync_types:
                self._sync_types[name](packet)
            else:
                self._process_raw_other(packet)

        if not self._keepsyncev:
            # remove synchronisation packets
            for packet in self._to_remove:
                packets.remove(packet)

    def _process_normal(self):
        packets = self._js['timeperiods']
        name_key = 'name'

        for packet in packets:
            self._keep_gpu_ts(packet)

            name = packet[name_key]
            if name in self._sync_types:
                self._sync_types[name](packet)
            else:
                self._process_normal_other(packet)

        if not self._keepsyncev:
            # remove synchronisation packets
            for packet in self._to_remove:
                packets.remove(packet)

    def _keep_gpu_ts(self, packet):
        if self._keepgputs:
            packet['start_gpu'] = packet['start']
            packet['end_gpu'] = packet['end']

    def _process_raw_pwrchg(self, packet):
        pwr_data = packet['pwrchg']
        self._process_pwrchg(packet, pwr_data)
        if self._keepsyncev:
            self._process_raw_other(packet)

    def _process_normal_pwrchg(self, packet):
        pwr_data = packet['prop']
        self._process_pwrchg(packet, pwr_data)
        if self._keepsyncev:
            self._process_normal_other(packet)

    def _process_pwrchg(self, packet, pwr_data):
        if 'PowerOn' in pwr_data['change']:
            if 'ostimestamp' not in pwr_data:
                # means that it's an old version of a packet which
                # doesn't have synchronisation info inside, so we just ignore
                # it because it's useless for us
                return

            if self._clk:
                # force clock speed
                pwr_data['gpuclockspeed'] = self._clk

            self._syncline.append(SyncPoint(int(pwr_data['ostimestamp']),
                                            int(pwr_data['crtimestamp'] * 256),
                                            float(pwr_data['gpuclockspeed'])))
        elif 'PowerOff' in pwr_data['change']:
            # We're not clearing time information but it may be
            # no longer valid. We will mark all of packets after this
            # as not trustworthy until we receive next valid synchronisation
            # packet. We're still changing time domain though.
            if self._syncline:
                self._syncline[-1].tw = False

        if not self._keepsyncev:
            self._to_remove.append(packet)

    def _process_raw_clkchg(self, packet):
        clk_data = packet['clkschgdata']
        self._process_clkchg(packet, clk_data)
        if self._keepsyncev:
            self._process_raw_other(packet)

    def _process_normal_clkchg(self, packet):
        clk_data = packet['prop']
        self._process_clkchg(packet, clk_data)
        if self._keepsyncev:
            self._process_normal_other(packet)

    def _process_clkchg(self, packet, clk_data):
        if 'ostimestamp' not in clk_data:
            # means that it's an old version of a packet which
            # doesn't have synchronisation info inside, so we just ignore
            # it because it's useless for us
            return

        if self._clk:
            # force clock speed
            clk_data['speed'] = self._clk

        self._syncline.append(SyncPoint(int(clk_data['ostimestamp']),
                                        int(clk_data['crtimestamp']) * 256,
                                        float(clk_data['speed'])))

        if not self._keepsyncev:
            self._to_remove.append(packet)

    def _process_raw_other(self, packet):
        if self._syncline:
            sync = self._syncline[-1]
            ts = int(packet['rgxtimer']) * 256

            if ts >= sync.tgpu:
                start = s2ns((ts - sync.tgpu) / sync.fgpu)
            else:
                start = -s2ns((sync.tgpu - ts) / sync.fgpu)

            packet['rgxtimer'] = ns2us(sync.tcpu + start)
            packet['tdomain'] = 'G2CPU' if sync.tw else 'G2CPU_NTW'
        else:
            # means that we didn't have any synchronisation packets
            # yet so we don't change time domain
            packet['tdomain'] = 'GPU'

        packet['source'] = 'FW'

    def _process_normal_other(self, packet):
        if self._syncline:
            sync = self._syncline[-1]

            if packet['start'] >= sync.tgpu:
                start = s2ns((packet['start'] - sync.tgpu) / sync.fgpu)
                end = s2ns((packet['end'] - sync.tgpu) / sync.fgpu)
            else:
                start = -s2ns((sync.tgpu - packet['start']) / sync.fgpu)
                end = -s2ns((sync.tgpu - packet['end']) / sync.fgpu)

            packet['start'] = ns2us(sync.tcpu + start)
            packet['end'] = ns2us(sync.tcpu + end)
            packet['tdomain'] = 'G2CPU' if sync.tw else 'G2CPU_NTW'
        else:
            # means that we didn't have any synchronisation packets
            # yet so we don't change time domain
            packet['tdomain'] = 'GPU'

        packet['source'] = 'FW'

class HwperfHost(Hwperf):
    """Represents HWPerf Host stream."""
    def __init__(self, args, syncline, filename=None, jfile=None):
        super(self.__class__, self).__init__(filename, jfile)
        self._to_remove = list()
        self._syncline = syncline
        self._sync_types = {'CLK_SYNC': self._process_normal_clksync,
                            '04_CLK_SYNC': self._process_raw_clksync}
        self._keepsyncev = args.keepsyncev()

    def process(self):
        if self.is_raw():
            self._process_raw()
        else:
            self._process_normal()

    def _process_raw(self):
        packets = self._js['hwperf_packets']
        name_key = 'type'
        self._process(packets, name_key)

    def _process_normal(self):
        packets = self._js['timeperiods']
        name_key = 'name'
        self._process(packets, name_key)

    def _process(self, packets, name_key):
        for packet in packets:
            name = packet[name_key]

            if name in self._sync_types:
                self._sync_types[name](packet)
            else:
                self._process_other(packet)

        if not self._keepsyncev:
            # remove all synchronisation packets
            for packet in self._to_remove:
                packets.remove(packet)

    def _process_raw_clksync(self, packet):
        clk_data = packet['clksync']
        self._process_clksync(packet, clk_data)

    def _process_normal_clksync(self, packet):
        clk_data = packet['prop']
        self._process_clksync(packet, clk_data)

    def _process_clksync(self, packet, clk_data):
        self._syncline.append(SyncPoint(int(clk_data['ostimestamp']),
                                        int(clk_data['crtimestamp']) * 256,
                                        float(clk_data['speed'])))
        if not self._keepsyncev:
            self._to_remove.append(packet)

    def _process_other(self, packet):
        packet['tdomain'] = 'CPU'
        packet['source'] = 'Host'

class HwperfClient(Hwperf):
    """Represents HWPerf Client stream."""
    def __init__(self, syncline, filename=None, jfile=None):
        super(self.__class__, self).__init__(filename, jfile)
        self._syncline = syncline

    def process(self):
        packets = self._js['hwperf_packets'] if self.is_raw() else \
                  self._js['timeperiods']

        for packet in packets:
            packet['tdomain'] = 'CPU'
            packet['source'] = 'Client'

class Merger(object):
    """Processes all streams and merges the files to produce complete,
    correlated JSON files."""
    def __init__(self, args):
        self._args = args
        self._syncline = dict()
        self._to_process = dict()

        # initialise list dictionary of streams to process
        for devid in args.device_list():
            self._syncline[devid] = list()
            self._to_process[devid] = list()

            if devid in args.hostjson_fname():
                for fname in args.hostjson_fname()[devid]:
                    try:
                        host = HwperfHost(self._args, self._syncline[devid],
                                          fname)
                        log.info('processing file: %s', fname)
                        host.process()
                        self._to_process[devid].append(host)
                    except Exception:
                        log.error('Error while loading "%s" file', fname,
                                exc_info=True)

            if devid in args.fwjson_fname():
                for fname in args.fwjson_fname()[devid]:
                    try:
                        fw = HwperfFw(self._args, self._syncline[devid], fname)
                        log.info('processing file: %s', fname)
                        fw.process()
                        self._to_process[devid].append(fw)
                    except Exception:
                        log.error('Error while loading "%s" file', fname,
                                exc_info=True)

            if devid in args.clientjson_fnames():
                for fname in args.clientjson_fnames()[devid]:
                    try:
                        client = HwperfClient(self._syncline[devid], fname)
                        log.info('processing file: %s', fname)
                        client.process()
                        self._to_process[devid].append(client)
                    except Exception:
                        log.error('Error while loading "%s" file', fname,
                                exc_info=True)

            # do the final check if formats of the streams match
            if self._to_process[devid]:
                is_raw = self._to_process[devid][0].is_raw()
                for j in self._to_process[devid]:
                    if j.is_raw() != is_raw:
                        raise WrongFormatException()

            # see comment in merge()
            if devid == 0:
                break

    def merge(self):
        """Merges all of the processed files."""
        if not self._to_process:
            log.error('No input data.')
            exit(1)

        for devid in self._syncline:
            if len(self._to_process[devid]) == 1 and \
               isinstance(self._to_process[devid][0], HwperfFw):
                self._change_timedomain_only(devid)
            else:
                self._merge(devid)

            # id 0 is special, it means that filename was manually given
            # so we're processing only this file
            if devid == 0:
                break

    def _change_timedomain_only(self, devid):
        log.info('No host stream data. Only time domain of stream will'
                 ' be changed.')

        self._dump_json(self._args.out_fname()[devid],
                        self._to_process[devid][0].get_json())

    def _merge(self, devid):
        if devid in self._syncline:
            if len(self._syncline[devid]) == 0:
                msg = '''No synchronisation events have been detected for iDeviceID = %d.
         Please consider enabling PWRCHG and CLKCHG events e.g.:

         $ echo 0x804000000 > /(sys/kernel/debug|proc)/pvr/apphint/X/HWPerfFWFilter

         Otherwise correlating Host and Firmware streams will be impossible.'''
                log.warning(msg, devid)
            if len(self._syncline[devid]) == 1:
                msg = '''Only one synchronisation event has been detected for iDeviceID = %d.
         If capture process was run on a device supporting APM please consider
         enabling PWRCHG and CLKCHG events e.g.:

         $ echo 0x804000000 > /(sys/kernel/debug|proc)/pvr/apphint/X/HWPerfFWFilter

         Otherwise correlating Host and Firmware streams will be impossible.'''
                log.warning(msg, devid)

        if devid in self._to_process:
            root_key = self._to_process[devid][0].get_json().keys()[0]
            ts_key = 'rgxtimer' if self._to_process[devid][0].is_raw() \
                    else 'start'

            out = list()
            for curr in self._to_process[devid]:
                j1 = out
                j2 = curr.get_json()[root_key]
                out = list()

                (i, j) = (0, 0)
                while i < len(j1) or j < len(j2):
                    if i < len(j1) and j < len(j2):
                        if j1[i][ts_key] <= j2[j][ts_key]:
                            out.append(j1[i])
                            i += 1
                        else:
                            out.append(j2[j])
                            j += 1
                    elif i < len(j1):
                        out.append(j1[i])
                        i += 1
                    else:
                        out.append(j2[j])
                        j += 1

            log.info('writing output: %s', self._args.out_fname()[devid])
            self._dump_json(self._args.out_fname()[devid], {root_key: out})

    def _dump_json(self, fpath, jsn):
        with open(fpath, 'w') as f:
            json.dump(jsn, f, indent=4)

def main():
    """ Main entry point """
    try:
        Merger(Args()).merge()
    except IOError as ex:
        log.error(ex)
    except WrongFormatException as ex:
        log.error(ex)

if __name__ == '__main__':
    main()
