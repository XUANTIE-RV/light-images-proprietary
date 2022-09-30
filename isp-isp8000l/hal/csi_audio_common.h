/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: fuqian.zxr <fuqian.zxr@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef __CSI_AUDIO_COMMON_H__
#define __CSI_AUDIO_COMMON_H__

#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include "csi_common.h"

#define MAX_AUDIO_FILE_PATH_LEN 256
#define VQE_EQ_BAND_NUM 10

typedef enum csi_audio_sample_rate {
    AUDIO_SAMPLE_RATE_8000  = 8000,  /*8K samplerate*/
    AUDIO_SAMPLE_RATE_12000 = 12000, /*12K samplerate*/
    AUDIO_SAMPLE_RATE_11025 = 11025, /*11.025K samplerate*/
    AUDIO_SAMPLE_RATE_16000 = 16000, /*16K samplerate*/
    AUDIO_SAMPLE_RATE_22050 = 22050, /*22.05k samplerate*/
    AUDIO_SAMPLE_RATE_24000 = 24000, /*24K samplerate*/
    AUDIO_SAMPLE_RATE_32000 = 32000, /*32K samplerate*/
    AUDIO_SAMPLE_RATE_44100 = 44100, /*44.1K samplerate*/
    AUDIO_SAMPLE_RATE_48000 = 48000, /*48K samplerate*/
    AUDIO_SAMPLE_RATE_64000 = 64000, /*64K samplerate*/
    AUDIO_SAMPLE_RATE_96000 = 96000, /*96K samplerate*/
    AUDIO_SAMPLE_RATE_BUTT,
}csi_audio_sample_rate_e;

typedef enum csi_audio_bit_width {
    AUDIO_BIT_WIDTH_8  = 0,  /*8bit width*/
    AUDIO_BIT_WIDTH_16 = 1,  /*16bit width*/
    AUDIO_BIT_WIDTH_24 = 2,  /*24bit width*/
    AUDIO_BIT_WIDTH_BUTT,
}csi_audio_bit_width_e;

typedef enum csi_audio_mode {
    AIO_MODE_I2S_MASTER = 0,  /* AIO I2S master mode */
    AIO_MODE_I2S_SLAVE,       /* AIO I2S slave mode */
    AIO_MODE_PCM_SLAVE_STD,   /* AIO PCM slave standard mode */
    AIO_MODE_PCM_SLAVE_NSTD,  /* AIO PCM slave non-standard mode */
    AIO_MODE_PCM_MASTER_STD,  /* AIO PCM master standard mode */
    AIO_MODE_PCM_MASTER_NSTD, /* AIO PCM master non-standard mode */
    AIO_MODE_BUTT,
}csi_audio_mode_e;

typedef enum csi_audio_sound_mode {
    AUDIO_SOUND_MODE_MONO   = 0, /*mono*/
    AUDIO_SOUND_MODE_STEREO = 1, /*stereo*/
    AUDIO_SOUND_MODE_BUTT
}csi_audio_sound_mode_e;

typedef enum csi_auido_i2stype {
    AIO_I2STYPE_INNERCODEC = 0, /*AIO I2S connect inner audio CODEC*/
    AIO_I2STYPE_INNERHDMI,      /*AIO I2S connect inner HDMI*/
    AIO_I2STYPE_EXTERN,         /*AIO I2S connect extern hardware*/
}csi_auido_i2stype_e;

typedef struct csi_aio_attr {
    csi_audio_sample_rate_e samplerate;  /*sample rate*/
    csi_audio_bit_width_e bitwidth; /*bitwidth*/
    csi_audio_mode_e workmode;    /*master or slave mode*/
    csi_audio_sound_mode_e soundmode; /*mono or steror*/
    uint32_t exflag;
    uint32_t frmnum;
    uint32_t pt_num_per_frm;
    uint32_t chncnt;
    csi_auido_i2stype_e i2stype;
}csi_aio_attr_s;

typedef struct csi_audio_frame {
    csi_audio_bit_width_e bitwidth;
    csi_audio_sound_mode_e soundmode;
    void *viraddr[2];
    uint32_t  phyaddr[2];
    uint64_t  timestamp; /*audio frame timestamp*/
    uint32_t  seq; /*audio frame seq*/
    uint32_t  len; /*data length per channel in frame*/
    uint32_t  poolid[2];
}csi_audio_frame_s;

typedef enum csi_audio_track_mode {
    AUDIO_TRACK_NORMAL = 0,
    AUDIO_TRACK_BOTH_LEFT = 1,
    AUDIO_TRACK_BOTH_RIGHT = 2,
    AUDIO_TRACK_EXCHANGE = 3,
    AUDIO_TRACK_MIX = 4,
    AUDIO_TRACK_LEFT_MUTE = 5,
    AUDIO_TRACK_RIGHT_MUTE = 6,
    AUDIO_TRACK_BOTH_MUTE = 7,
    AUDIO_TRACK_BUTT,
}csi_audio_track_mode_e;

typedef struct csi_audio_save_file_info {
    bool cfg;
    char filepath[MAX_AUDIO_FILE_PATH_LEN];
    char filename[MAX_AUDIO_FILE_PATH_LEN];
    uint32_t filesize;
}csi_audio_save_file_info_s;

typedef struct csi_audio_file_status {
    bool saving;
}csi_audio_file_status_s;

typedef enum csi_vqe_workstate {
    VQE_WORKSTATE_COMMON  = 0,
    VQE_WORKSTATE_MUSIC  = 1,
    VQE_WORKSTATE_NOISY  = 2
}csi_vqe_workstate_e;

typedef enum csi_audio_hpf_freq {
    AUDIO_HPF_FREQ_80 = 80,   /*80HZ*/
    AUDIO_HPF_FREQ_120 = 120, /*120Hz*/
    AUDIO_HPF_FREQ_150 = 150, /*150Hz*/
    AUDIO_HPF_FREQ_BUTT,
}csi_audio_hpf_freq_e;

typedef struct csi_audio_hpf_config {
    bool usrmode;
    csi_audio_hpf_freq_e hpffreq;
}csi_audio_hpf_config_s;

typedef struct csi_audio_anr_config {
    bool usrmode;
    int16_t nrintensity;
    int16_t noisedbthr;
    int8_t sp_pro_switch;
    int32_t reserved;
}csi_audio_anr_config_s;

typedef struct csi_audio_agc_config {
    bool usrmode;
    int8_t target_level;
    int8_t noise_floor;
    int8_t maxgain;
    int8_t adjustspeed;
    int8_t improvesnr;
    int8_t usehighpassfilt;
    int8_t outputmode;
    int16_t noisesupswitch;
    int32_t reserved;
}csi_audio_agc_config_s;

typedef struct csi_audio_eq_config {
    int8_t gaindb[VQE_EQ_BAND_NUM];
    int32_t reserved;
}csi_audio_eq_config_s;

typedef enum {
    PT_PCMU  = 0,
    PT_1016  = 1,
    PT_BUTT
}PAYLOAD_TYPE_E;

typedef struct csi_audio_stream {
    uint8_t *stream; /*the virtual address of stream*/
    uint32_t phyaddr; /*the physics address of stream*/
    uint32_t len;   /*stream length,by bytes*/
    uint64_t timestamp; /*frame time stamp*/
    uint32_t seq; /*frame seq,if stream is not a valid frame 0*/
}csi_audio_stream_s;

#endif