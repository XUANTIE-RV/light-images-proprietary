/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: fuqian.zxr <fuqian.zxr@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef __CSI_AUDIO_AI_H__
#define __CSI_AUDIO_AI_H__

#include "csi_audio_common.h"

#define CSI_AUDIO_AI_VERSION_MAJOR	0
#define CSI_AUDIO_AI_VERSION_MINOR	1

#define VQE_DRC_SECNUM 5

#define CSI_AI_MAX_COUNT 16
#define CSI_AI_NAME_MAX_LEN 32

#define CSI_AI_CAP_SPDIF  0x00000001 /*Is a spdif device*/
#define CSI_AI_CAP_HDMI   0x00000002 /*IS a hdmi audio*/
#define CSI_AI_CAP_CODEC  0x00000003 /*Is a codec audio*/

typedef struct csi_ai_info {
    char ai_name[CSI_AI_NAME_MAX_LEN];
    unsigned int capbilities;
}csi_ai_info_s;

typedef struct csi_ai_infos {
    unsigned int count;
    csi_ai_info_s info[CSI_AI_MAX_COUNT];
}csi_ai_infos_s;

typedef struct csi_aec_frame {
    csi_audio_frame_s refframe;
    bool bvalid;
    bool bsysbind;
}csi_aec_frame_s;

typedef struct csi_aichn_frame{
    uint32_t usr_frm_depth;
}csi_aichn_frame_s;

typedef struct csi_ai_aec_config {
    bool    usrmode;
    int8_t  cngmode;
    int8_t  nearallpassenergy;
    int8_t  nearcleansupenergy;
    int16_t dthnl_sort_qth;
    int16_t echobandlow;
    int16_t echobandhigh;
    int16_t echobandlow2;
    int16_t echobandhigh2;
    int16_t erl_band[6];
    int16_t erl[7];
    int16_t voice_protect_freql;
    int16_t voice_protect_freql1;
    int32_t reserved;
}csi_ai_aec_config_s;

typedef struct csi_ai_rnr_config {
    bool    usrmode;
    int32_t nrmode;
    int32_t maxnrlevel;
    int32_t noisethresh;
}csi_ai_rnr_config_s;

typedef struct csi_ai_hdr_config {
    bool usrmode;
    int32_t mingaindb;
    int32_t maxgaindb;
    int32_t micgaindb;
    int32_t micgainstepdb;
    void *callback;
}csi_ai_hdr_config_s;

typedef struct csi_ai_drc_config {
    bool usrmode;
    int16_t attacktime;
    int16_t releasetime;
    int16_t oldlevdb[VQE_DRC_SECNUM];
    int16_t newlevdb[VQE_DRC_SECNUM];
}csi_ai_drc_config_s;


int32_t csi_ai_get_version(csi_api_version_u *version);

int32_t csi_ai_query_list(csi_ai_infos_s *infos);

int32_t csi_ai_setpubattr(int32_t aidevid,csi_aio_attr_s *aiattr);
int32_t csi_ai_getpubattr(int32_t aidevid,csi_aio_attr_s *aiattr);

int32_t csi_ai_enable(int32_t aidevid);
int32_t csi_ai_disable(int32_t aidevid);

int32_t csi_ai_enablechn(int32_t aidevid,int32_t aichn);
int32_t csi_ai_disablechn(int32_t aidevid,int32_t aichn);

int32_t csi_ai_getframe(int32_t aidev,int32_t aichn,csi_audio_frame_s *frm,csi_aec_frame_s *aecfrm,int32_t timeout);
int32_t csi_ai_releaseframe(int32_t aidev,int32_t aichn,csi_audio_frame_s *frm,csi_aec_frame_s *aecfrm);

int32_t csi_ai_setchnparam(int32_t aidev,int32_t aichn,csi_aichn_frame_s *chnparam);
int32_t csi_ai_getchnparam(int32_t aidev,int32_t aichn,csi_aichn_frame_s *chnparam);

int32_t csi_ai_enableresmp(int32_t aidev,int32_t aichn,csi_audio_sample_rate_e out_sample_rate);
int32_t csi_ai_disableresmp(int32_t aidev,int32_t aichn);

int32_t csi_ai_setvqeattr(int32_t aidev,int32_t aichn,int32_t aochn,int *level);
int32_t csi_ai_getvqeattr(int32_t aidev,int32_t aichn,int *level);

int32_t csi_ai_settalkvqeattr(int32_t aidev,int32_t aichn,int32_t aodev,int32_t aochn,int *level);
int32_t csi_ai_gettalkvqeattr(int32_t aidev,int32_t aichn,int *level);

int32_t csi_ai_setrecordvqeattr(int32_t aidev,int32_t aichn,int *level);
int32_t csi_ai_getrecordvqeattr(int32_t aidev,int32_t aichn,int *level);

int32_t csi_ai_enablevqe(int32_t aidev,int32_t aichn);
int32_t csi_ai_disablevqe(int32_t aidev,int32_t aichn);

int32_t csi_ai_settrackmode(int32_t aidev,csi_audio_track_mode_e trackmode);
int32_t csi_ai_gettrackmode(int32_t aidev,csi_audio_track_mode_e *trackmode);

int32_t csi_ai_reset(int32_t aidevid);

int32_t csi_ai_queryfilestatus(int32_t aidev,int32_t aichn,csi_audio_file_status_s *filestatus);

int32_t csi_ai_setvqevolume(int32_t aidev,int32_t aichn,int32_t volumedb);
int32_t csi_ai_getvqevolume(int32_t aidev,int32_t aichn,int32_t *volumedb);

int32_t csi_ai_enableaecrefframe(int32_t aidev,int32_t aichn,int32_t aodev,int32_t aochn);
int32_t csi_ai_disableaecrefframe(int32_t aidev,int32_t aichn);

#endif