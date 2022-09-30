/*
 * Copyright (c) 2021 Alibaba Group. All rights reserved.
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

#ifndef CSI_CAMERA_DEV_API_H
#define CSI_CAMERA_DEV_API_H

#include <syslog.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <sys/time.h>

#include <csi_camera.h>
#include <stdlib.h>



#ifdef  __cplusplus
extern "C" {
#endif

typedef void (*cb_fn)(void*context,void*arg);
typedef struct csi_camera_dsp_algo_param{
    char* algo_name;        //加载的算法
    struct{
            cb_fn  cb;       //算法上报结果的回调函数(比如3A的结果)
            void*  context;     //回调句柄
            int    arg_size;    //回调函数的输入参数的大小
    }algo_cb;
    void* sett_ptr;         //算法的setting
    size_t sett_size;       //算法的setting的size
    int    extra_buf_num;   //算法的除了input&output buffer 额外需要的buffer 个数
    int    *extra_buf_sizes; //额外需要的buffer size list
    void   **extra_bufs;    //申请到的buffer的指针 list

} csi_camera_dsp_algo_param_t;

typedef enum line_buf_mode{
    LINE_BUF_MODE_DDR,
    LINE_BUF_MODE_SRAM,
} line_buf_mode_t;

typedef enum {
    LED_FLOODLIGHT = 1,
    LED_PROJECTION = 2,
    LED_FLOODLIGHT_PROJECTION = 3,
} flash_led_mask_t;

typedef enum {
    LED_STANDBY,
    LED_EXT_TORCH,
    LED_EXT_FLASH,
    LED_INT_TORCH,
    LED_INT_FLASH,
    LED_IR_STANDBY,
    LED_IR_ENABLE,
} flash_led_mode_mask_t;

/**
 * @description: The function load dsp firmware algo lib
 * passing algo seeting and  create bufs for dsp path in CAM.
 * @param[in] {cam_handle} cam handle
 * @param[in] {int}dsp device id should be 0/1
 * @param[in] {int} path_type for dsp in cam
 *           typedef enum dsp_path_type{
 *               DSP_PATH_ISP_RY = 0,
 *              DSP_PATH_ISP_CPU,
 *              DSP_PATH_VIPRE_DDR,
*               DSP_PATH_VIPRE_EVEN,
*                DSP_PATH_VIPRE_ODD,
*                DSP_PATH_VIPRE_RY,
*                DSP_PATH_CPU_CPU,
*               DSP_PATH_MAX,
*          } dsp_path_type_e;
 * @param[in/out] {csi_camera_dsp_algo_param_t *} point to param for algo
 * @return{int} return 0 when delete success, not 0 in case of error
 */
int csi_camera_set_dsp_algo_param(csi_cam_handle_t cam_handle, int dsp_id,int path_type, csi_camera_dsp_algo_param_t *algo_param);

/**
 * @description: The function update algo setting.
 * @param[in] {cam_handle} Sub-device output path handle
 * @param[in] {int}dsp device id should be 0/1
 * @param[in] {int} path_type for dsp in cam
 * @param[in] {void*} point to new setting for algo
  * @return{int} return 0 when delete success, not 0 in case of error
 */
int csi_camera_update_dsp_algo_setting(csi_cam_handle_t cam_handle, int dsp_id,int path_type,  void* sett_ptr);

/**
 * @description: The function update buf for dsp algo.
 * @param[in] {cam_handle} Sub-device output path handle
 * @param[in] {int}dsp device id should be 0/1
 * @param[in] {int} path_type for dsp in cam
 * @param[in] {void*} point to buf which new data is writen and should update to dsp algo
 * @param[out]  {void*} buf can be udapte for next time
  * @return{int} return 0 when delete success, not 0 in case of error
 */
int csi_camera_update_dsp_algo_buf(csi_cam_handle_t cam_handle, int dsp_id,int path_type,void*buf,void**replace_buf);

int csi_camera_set_pp_path_param(csi_cam_handle_t cam_handle, uint16_t line_num,uint16_t buf_mode);
int csi_camera_set_sensor_resolution(csi_cam_handle_t cam_handle, csi_camera_channel_id_e chn_id, char* subdev_name, unsigned int width, unsigned int height);

int csi_camera_get_active_sensor(csi_cam_handle_t cam_handle);

int csi_camera_projection_led_set_mode(csi_cam_handle_t cam_handle, flash_led_mode_mask_t led_mode);
int csi_camera_floodlight_led_set_mode(csi_cam_handle_t cam_handle, flash_led_mode_mask_t led_mode);

int csi_camera_led_enable(csi_cam_handle_t cam_handle, flash_led_mask_t mask);
int csi_camera_led_disable(csi_cam_handle_t cam_handle, flash_led_mask_t mask);

int csi_camera_floodlight_led_set_flash_bright(csi_cam_handle_t cam_handle, unsigned long ma);
int csi_camera_floodlight_led_set_torch_bright(csi_cam_handle_t cam_handle, unsigned long ma);

int csi_camera_projection_led_set_flash_bright(csi_cam_handle_t cam_handle, unsigned long ma);
int csi_camera_projection_led_set_torch_bright(csi_cam_handle_t cam_handle, unsigned long ma);

#ifdef  __cplusplus
}
#endif
#endif
