/*
 * Copyright (C) 2021 Alibaba Group Holding Limited
 * Author: fuqian.zxr <fuqian.zxr@alibaba-inc.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef __CSI_AUDIO_DEC_H__
#define __CSI_AUDIO_DEC_H__

#include "csi_audio_common.h"

#define CSI_AUDIO_DEC_VERSION_MAJOR	0
#define CSI_AUDIO_DEC_VERSION_MINOR	1

typedef enum csi_adec_mode {
    ADEC_MODE_PACK = 0,
    ADEC_MODE_STREAM,
    ADEC_MODE_BUTT
}csi_adec_mode_e;

typedef struct csi_adec_ch_attr {
    PAYLOAD_TYPE_E type;
    uint32_t bufsize;
    csi_adec_mode_e mode;
    void *value;
}csi_adec_ch_attr_s;

typedef struct csi_adec_decoder {
    PAYLOAD_TYPE_E type;
    char name[16];
    int32_t (*openendecoder)(void *decoderattr,void **decoder);
    int32_t (*decoderfrm)(void *decoder,uint8_t **inbuf,int32_t leftbyte,uint16_t *outbuf,uint32_t *outlen,uint32_t *chns);
    int32_t (*getfrminfo)(void *decoder,void *info);
    int32_t (*closedecoder)(void *decoder);
    int32_t (*resetdecoder)(void *decoder);
}csi_adec_decoder_s;

typedef struct csi_audio_frame_info {
    csi_audio_frame_s *frame;
    uint32_t id;
}csi_audio_frame_info_s;

int32_t csi_adec_get_version(csi_api_version_u *version);

int32_t csi_adec_create(int32_t adchn,csi_adec_ch_attr_s);
int32_t csi_adec_destroy(int32_t adchn);

int32_t csi_adec_sendstream(int32_t adchn,const csi_audio_stream_s *stream, bool block);
int32_t csi_adec_clearchnbuf(int32_t adchn);

int32_t csi_adec_registerdecoder(int32_t handle,csi_adec_decoder_s *decoder);
int32_t csi_adec_unregisterdecoder(int32_t hanbdle);

int32_t csi_adec_getframe(int32_t adchn,csi_audio_frame_info_s *frameinfo,bool block);
int32_t csi_adec_releaseframe(int32_t adchn,csi_audio_frame_info_s *frameinfo);

int32_t csi_adec_sendendofstream(int adchn,bool instant);

#endif