/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: fuqian.zxr <fuqian.zxr@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef __CSI_AUDIO_AO_H__
#define __CSI_AUDIO_AO_H__

#include "csi_audio_common.h"

#define CSI_AO_MAX_COUNT 16
#define CSI_AO_NAME_MAX_LEN 32

#define CSI_AO_CAP_SPDIF  0x00000001 /*Is a spdif device*/
#define CSI_AO_CAP_HDMI   0x00000002 /*IS a hdmi audio*/
#define CSI_AO_CAP_CODEC  0x00000003 /*Is a codec audio*/

typedef struct csi_ao_info {
    char ai_name[CSI_AO_NAME_MAX_LEN];
    unsigned int capbilities;
}csi_ao_info_s;

typedef struct csi_ao_infos {
    unsigned int count;
    csi_ao_info_s info[CSI_AO_MAX_COUNT];
}csi_ao_infos_s;

#define CSI_AUDIO_AO_VERSION_MAJOR	0
#define CSI_AUDIO_AO_VERSION_MINOR	1

typedef struct csi_ao_chn_state {
    uint32_t chntotalnum;
    uint32_t chnfreenum;
    uint32_t chnbusynum;
}csi_ao_chn_state_s;

typedef enum csi_audio_fade_rate {
    AUIDO_FADE_RATE_1 = 0,
    AUIDO_FADE_RATE_2 = 1,
    AUIDO_FADE_RATE_4 = 2,
    AUIDO_FADE_RATE_8 = 3,
    AUIDO_FADE_RATE_16 = 4,
    AUIDO_FADE_RATE_32 = 5,
    AUIDO_FADE_RATE_64 = 6,
    AUIDO_FADE_RATE_128 = 7,
    AUIDO_FADE_RATE_BUTT
}csi_audio_fade_rate_e;

typedef struct csi_audio_fade {
    bool fade;
    csi_audio_fade_rate_e fadeinrate;
    csi_audio_fade_rate_e fadeoutrate;
}csi_audio_fade_s;

typedef struct csi_ao_vqe_config {
    int32_t hpfopen;
    int32_t anropen;
    int32_t agcopen;
    int32_t eqopen;
    int32_t worksamplerate;
    int32_t framesample;
    csi_vqe_workstate_e workstate;
    csi_audio_hpf_config_s hpfcfg;
    csi_audio_anr_config_s anrcfg;
    csi_audio_agc_config_s agccfg;
    csi_audio_eq_config_s eqcfg;
}csi_ao_vqe_config_s;

int32_t csi_ao_get_version(csi_api_version_u *version);

int32_t csi_ao_query_list(csi_ao_infos_s *infos);
int32_t csi_ao_setpubattr(int32_t aodev,csi_aio_attr_s *attr);
int32_t csi_ao_getpubattr(int32_t aodev,csi_aio_attr_s *attr);

int32_t csi_ao_enable(int32_t aodev);
int32_t csi_ao_disable(int32_t aodev);

int32_t csi_ao_enablechn(int32_t aodev,int32_t aochn);
int32_t csi_ao_disablechn(int32_t aodev,int32_t aochn);


int32_t csi_ao_sendframe(int32_t aodev,int32_t aochn,const csi_audio_frame_s *data,int32_t timeout);
int32_t csi_ao_enableresmp(int32_t aodev,int32_t aochn,csi_audio_sample_rate_e insamplerate);

int32_t csi_ao_disableresmp(int32_t aodev,int32_t aochn);
int32_t csi_ao_pausechn(int32_t aodev,int32_t aochn);

int32_t csi_ao_resumechn(int32_t aodev,int32_t aochn);
int32_t csi_ao_clearchnbuf(int32_t aodev,int32_t aochn);

int32_t csi_ao_querychnstat(int32_t aodev,int32_t aochn,csi_ao_chn_state_s *status);

int32_t csi_ao_settrackmode(int32_t aodev,csi_audio_track_mode_e trackmode);
int32_t csi_ao_gettrackmode(int32_t aodev,csi_audio_track_mode_e *trackmode);

int32_t csi_ao_setvolume(int32_t aodev,int32_t volume);
int32_t csi_ao_getvolume(int32_t aodev,int32_t *volume);

int32_t csi_ao_setmute(int32_t aodev,bool enable,csi_audio_fade_s *fade);
int32_t csi_ao_getmute(int32_t aodev,bool enable,csi_audio_fade_s *fade);

int32_t csi_ao_reset(int32_t aodev);

int32_t csi_ao_setvqeattr(int32_t aodev,int32_t aochn,csi_ao_vqe_config_s *vqeconfig);
int32_t csi_ao_getvqeattr(int32_t aodev,int32_t aochn,csi_ao_vqe_config_s *vqeconfig);

int32_t csi_ao_enablevqe(int32_t aodev,int32_t aochn);
int32_t csi_ao_disablevqe(int32_t aodev,int32_t aochn);

#endif
