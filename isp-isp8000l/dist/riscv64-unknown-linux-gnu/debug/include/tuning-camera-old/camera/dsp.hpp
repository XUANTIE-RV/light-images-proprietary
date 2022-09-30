/*
 * Copyright (c) 2021-2022 Alibaba Group. All rights reserved.
 * License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#pragma once

#include <tuning-camera-old-config.hpp>
#include "common/interface.hpp"

#include "image.hpp"
#include "sensor.hpp"
#include "engine.hpp"

#include <hal/hal_api.h>
#include <csi_dsp_api.h>
#include <csi_dsp_task_defs.h>
#include <csi_dsp_post_process_defs.h>
#include <subdev_shared_defs.h>
#include <stdlib.h>

typedef enum{
    SUBDEV_DSP_PATH_ISP_RY,
    SUBDEV_DSP_PATH_ISP_CPU ,
    SUBDEV_DSP_PATH_VIPRE_CPU,
    SUBDEV_DSP_PATH_VIPRE_EVEN,
    SUBDEV_DSP_PATH_VIPRE_ODD,
    SUBDEV_DSP_PATH_VIPRE_RY,
    SUBDEV_DSP_PATH_CPU_CPU,
    SUBDEV_DSP_PATH_MAX

}subdev_dsp_path_e;

typedef struct dsp_path_desc{
    int path_type;
    int path_status;
    char* algo_name;
    int   algo_id;

    void* sett_ptr;
    uint32_t sett_size;
    uint32_t in_width;
	uint32_t in_height;
    uint32_t in_data_format;
    uint32_t in_line_entry;
    uint32_t in_stride;
    uint32_t in_buffer_size;
    void*   in_virtual_addr;
    uint64_t   in_phy_addr;
    uint32_t out_width;
	uint32_t out_height;
    uint32_t out_data_format;
    uint32_t out_line_entry;
    uint32_t out_stride;
    uint32_t out_buffer_size;
    uint32_t bayer_mode;
    void*   out_virtual_addr;
    uint64_t out_phy_addr;
    cam_img_param_t chl_output;

}dsp_path_desc_t;

typedef struct dsp_path_context{
    void *path_handler;
    dsp_path_desc_t  path_config;

}dsp_path_context_t;

typedef struct subdev_dsp_ctx{
    void * dsp_instance;
    dsp_path_context_t dsp_path_ctx[SUBDEV_DSP_PATH_MAX];
    cam_img_param_t input;
    cam_img_param_t output[3];
    cam_img_param_t chl_output[16];
    void* sram_pool;
}subdev_dsp_ctx_t;

struct Dsp {
    Dsp();
    ~Dsp();
    int32_t pathConfigSet();
    subdev_dsp_ctx_t *pDspCtx = nullptr;
    int DspInitPath();
    int DspSetSramPool(void * pool);
    int DspInputCfg(IsiSensorConfig_t *pSensorConfig);
    int DspChannelOutputCfg();
    int DspPathInputCfg(pp_write_line_entry_t *pp_write_line_entry);
    int DspPathInternalUpdate(struct csi_dsp_task_fe_para *cfg ,dsp_path_desc_t  *path_config);
    int DspPathOutputCfg();
    int DspPathOn();
    void* DspAlgoLibFileLoad(char *name,int* sz);
    int DspPathOff();
    int32_t DspInputOutputCfg(IsiSensorConfig_t *pSensorConfig, pp_write_line_entry_t *pp_write_line_entry);
    line_entry_path_t* DspGetPathOutParams();
    int ConverDspFmtToCamFmt(int fmt);
};

int DspPathResultHandle(void* context, void* arg);