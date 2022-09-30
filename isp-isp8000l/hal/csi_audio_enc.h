/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: fuqian.zxr <fuqian.zxr@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __CSI_AUDIO_ENC_H__
#define __CSI_AUDIO_ENC_H__

#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

#include "csi_audio_common.h"

#define CSI_AUDIO_ENC_VERSION_MAJOR	0
#define CSI_AUDIO_ENC_VERSION_MINOR	1

typedef struct csi_aenc_chn_attr
{
    PAYLOAD_TYPE_E type;
    uint32_t  numperfrm;
    uint32_t  buffersize;
}csi_aenc_chn_attr_s;

typedef struct csi_aec_frame {
    csi_audio_frame_s refframe;
    bool valid;
    bool sysbind;
}csi_aec_frame_s;

typedef struct csi_aenc_encode {
    PAYLOAD_TYPE_E type;
    uint32_t maxfrmlen;
    char name[16];
    int32_t (*openencoder)(void *encoderattr,void **encoder);
    int32_t (*encoderfrm)(void *encoder,const csi_audio_frame_s *data,uint8_t *outbuf,uint32_t *outlen);
    int32_t (*closeencoder)(void *encoder);
}csi_aenc_encode_s;

int32_t csi_adec_get_version(csi_api_version_u *version);

int32_t csi_aenc_createchn(int32_t aechn,const csi_aenc_chn_attr_s attr);
int32_t csi_aenc_destroychn(int32_t aechn);

int32_t csi_aenc_sendframe(int32_t aechn,const csi_audio_frame_s *frm,const csi_aec_frame_s *aecfrm);
int32_t csi_aenc_getstream(int32_t aechn,csi_audio_stream_s *stream,int32_t timeout);

int32_t csi_aenc_releasestream(int32_t aechn,const csi_audio_stream_s *stream);

int32_t csi_aenc_getfd(int32_t aechn);
int32_t csi_aenc_registerencoder(int32_t handle,csi_aenc_encode_s *encoder);
int32_t csi_aenc_unregisterencoder(int32_t handle);

int32_t csi_aenc_savefile(int32_t aechn,csi_audio_save_file_info_s *savefileinfo);
int32_t csi_aenc_queryfilestatus(int32_t aechn,csi_audio_file_status_s *filestatus);

int32_t csi_aec_getstreambufinfo(int32_t aechn,uint32_t *physaddr,uint32_t *size);

#endif