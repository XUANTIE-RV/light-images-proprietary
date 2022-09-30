/******************************************************************************\
|* Copyright (c) 2020 by VeriSilicon Holdings Co., Ltd. ("VeriSilicon")       *|
|* All Rights Reserved.                                                       *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of VeriSilicon.  This is proprietary information owned or licensed by      *|
|* VeriSilicon.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of VeriSilicon.                                         *|
|*                                                                            *|
\******************************************************************************/

#ifndef _CAMERA_DEVICE_MODULE_IDS_
#define _CAMERA_DEVICE_MODULE_IDS_

// Cam_device API header definitions
const uint32_t ISPCORE_MODULE_GROUPID_PREFIX_MASK =  0xFFFFF000;

typedef enum __MODULE_ID__ {
    ISPCORE_MODULE_DEFAULT = 0,
    ISPCORE_MODULE_AE_BEGIN                         = 0x00001000,
    ISPCORE_MODULE_AE_PROCESS                       = 0x00001001,
    ISPCORE_MODULE_AE_CFG_GET                       = 0x00001002,
    ISPCORE_MODULE_AE_CFG_SET                       = 0x00001003,
    ISPCORE_MODULE_AE_ECM_GET                       = 0x00001004,
    ISPCORE_MODULE_AE_ECM_SET                       = 0x00001005,
    ISPCORE_MODULE_AE_ENABLE_GET                    = 0x00001006,
    ISPCORE_MODULE_AE_ENABLE_SET                    = 0x00001007,
    ISPCORE_MODULE_AE_RESET                         = 0x00001008,
    ISPCORE_MODULE_AE_END,

    ISPCORE_MODULE_AF_BEGIN                         = 0x00002000,
    ISPCORE_MODULE_AF_PROCESS                       = 0x00002001,
    ISPCORE_MODULE_AF_AVI_GET                       = 0x00002002,
    ISPCORE_MODULE_AF_CFG_GET                       = 0x00002003,
    ISPCORE_MODULE_AF_CFG_SET                       = 0x00002004,
    ISPCORE_MODULE_AF_ENABLE_GET                    = 0x00002005,
    ISPCORE_MODULE_AF_ENABLE_SET                    = 0x00002006,
    ISPCORE_MODULE_AF_END,

    ISPCORE_MODULE_AVS_BEGIN                        = 0x00003000,
    ISPCORE_MODULE_AVS_PROCESS                      = 0x00003001,
    ISPCORE_MODULE_AVS_CFG_GET                      = 0x00003002,
    ISPCORE_MODULE_AVS_CFG_SET                      = 0x00003003,
    ISPCORE_MODULE_AVS_ENABLE_GET                   = 0x00003004,
    ISPCORE_MODULE_AVS_ENABLE_SET                   = 0x00003005,
    ISPCORE_MODULE_AVS_STATUS_GET                   = 0x00003006,
    ISPCORE_MODULE_AVS_END,

    ISPCORE_MODULE_AWB_BEGIN                        = 0x00004000,
    ISPCORE_MODULE_AWB_PROCESS                      = 0x00004001,
    ISPCORE_MODULE_AWB_CFG_GET                      = 0x00004002,
    ISPCORE_MODULE_AWB_CFG_SET                      = 0x00004003,
    ISPCORE_MODULE_AWB_ENABLE_GET                   = 0x00004004,
    ISPCORE_MODULE_AWB_ENABLE_SET                   = 0x00004005,
    ISPCORE_MODULE_AWB_GAIN_SET                     = 0x00004006,
    ISPCORE_MODULE_AWB_ILLUMPRO_GET                 = 0x00004007,
    ISPCORE_MODULE_AWB_RESET                        = 0x00004008,
    ISPCORE_MODULE_AWB_STATUS_GET                   = 0x00004009,
    ISPCORE_MODULE_AWB_MEAS_WIN_SET                 = 0x0000400A,
    ISPCORE_MODULE_AWB_END,

    ISPCORE_MODULE_BLS_BEGIN                        = 0x00005000,
    ISPCORE_MODULE_BLS_PROCESS                      = 0x00005001,
    ISPCORE_MODULE_BLS_CFG_GET                      = 0x00005002,
    ISPCORE_MODULE_BLS_CFG_SET                      = 0x00005003,
    ISPCORE_MODULE_BLS_END,

    ISPCORE_MODULE_CAC_BEGIN                        = 0x00006000,
    ISPCORE_MODULE_CAC_PROCESS                      = 0x00006001,
    ISPCORE_MODULE_CAC_ENABLE_GET                   = 0x00006002,
    ISPCORE_MODULE_CAC_ENABLE_SET                   = 0x00006003,
    ISPCORE_MODULE_CAC_END,

    ISPCORE_MODULE_CNR_BEGIN                        = 0x00007000,
    ISPCORE_MODULE_CNR_PROCESS                      = 0x00007001,
    ISPCORE_MODULE_CNR_CFG_GET                      = 0x00007002,
    ISPCORE_MODULE_CNR_CFG_SET                      = 0x00007003,
    ISPCORE_MODULE_CNR_ENABLE_GET                   = 0x00007004,
    ISPCORE_MODULE_CNR_ENABLE_SET                   = 0x00007005,
    ISPCORE_MODULE_CNR_END,

    ISPCORE_MODULE_CPROC_BEGIN                      = 0x00008000,
    ISPCORE_MODULE_CPROC_PROCESS                    = 0x00008001,
    ISPCORE_MODULE_CPROC_CFG_GET                    = 0x00008002,
    ISPCORE_MODULE_CPROC_CFG_SET                    = 0x00008003,
    ISPCORE_MODULE_CPROC_ENABLE_GET                 = 0x00008004,
    ISPCORE_MODULE_CPROC_ENABLE_SET                 = 0x00008005,
    ISPCORE_MODULE_CPROC_END,

    ISPCORE_MODULE_DEMOSAIC_BEGIN                   = 0x00009000,
    ISPCORE_MODULE_DEMOSAIC_PROCESS                 = 0x00009001,
    ISPCORE_MODULE_DEMOSAIC_CFG_GET                 = 0x00009002,
    ISPCORE_MODULE_DEMOSAIC_CFG_SET                 = 0x00009003,
    ISPCORE_MODULE_DEMOSAIC_ENABLE_GET              = 0x00009004,
    ISPCORE_MODULE_DEMOSAIC_ENABLE_SET              = 0x00009005,
    ISPCORE_MODULE_DEMOSAIC_END,

    ISPCORE_MODULE_DEVICE_BEGIN                     = 0x0000A000,
    ISPCORE_MODULE_DEVICE_PROCESS                   = 0x0000A001,
    ISPCORE_MODULE_DEVICE_CALIBRATIONSAVE           = 0x0000A002,
    ISPCORE_MODULE_DEVICE_CALIBRATIONLOADANDINIT    = 0x0000A003,
    ISPCORE_MODULE_DEVICE_CALIBRATIONLOAD           = 0x0000A004,
    ISPCORE_MODULE_DEVICE_INITENGINEOPERATION       = 0x0000A005,
    ISPCORE_MODULE_DEVICE_RESOLUTION_SET_SENSOR_ISP  = 0x0000A006,
    ISPCORE_MODULE_DEVICE_CAMERA_CONNECT            = 0x0000A007,

    ISPCORE_MODULE_DEVICE_CAPTUREDMA                = 0x0000A008,
    ISPCORE_MODULE_DEVICE_CAPTURESENSOR             = 0x0000A009,
    ISPCORE_MODULE_DEVICE_INPUTINFO                 = 0x0000A00A,
    ISPCORE_MODULE_DEVICE_INPUTSWITCH               = 0x0000A00B,
    ISPCORE_MODULE_DEVICE_PREVIEW                   = 0x0000A00C,
    ISPCORE_MODULE_DEVICE_BITSTREAMID               = 0x0000A00D,
    ISPCORE_MODULE_DEVICE_CAMERIC_ID                = 0x0000A00E,
    ISPCORE_MODULE_DEVICE_INPUT_CONNECT             = 0x0000A00F,
    ISPCORE_MODULE_DEVICE_INPUT_DISCONNECT          = 0x0000A010,
    ISPCORE_MODULE_DEVICE_RESET                     = 0x0000A011,
    ISPCORE_MODULE_DEVICE_RESOLUTION_GET            = 0x0000A012,
    ISPCORE_MODULE_DEVICE_RESOLUTION_SET            = 0x0000A013,
    ISPCORE_MODULE_DEVICE_STREAMING_START           = 0x0000A014,
    ISPCORE_MODULE_DEVICE_STREAMING_STOP            = 0x0000A015,
    ISPCORE_MODULE_DEVICE_CAMERA_DISCONNECT         = 0x0000A016,
    ISPCORE_MODULE_DEVICE_CAMERA_RESET              = 0x0000A017,
    ISPCORE_MODULE_DEVICE_PREVIEW_START             = 0x0000A018,
    ISPCORE_MODULE_DEVICE_PREVIEW_STOP              = 0x0000A019,
    ISPCORE_MODULE_DEVICE_GET_HALHANDLE             = 0x0000A01A,
    ISPCORE_MODULE_DEVICE_GET_METADATA              = 0x0000A01B,
    ISPCORE_MODULE_DEVICE_OUTPUT_IMAGE_FORMAT       = 0x0000A01C,
    ISPCORE_MODULE_DEVICE_STANDBY_ENABLE_SET        = 0x0000A01D,
    ISPCORE_MODULE_DEVICE_END,

    ISPCORE_MODULE_2DNR_BEGIN                       = 0x0000B000,
    ISPCORE_MODULE_2DNR_PROCESS                     = 0x0000B001,
    ISPCORE_MODULE_2DNR_CFG_GET                     = 0x0000B002,
    ISPCORE_MODULE_2DNR_CFG_SET                     = 0x0000B003,
    ISPCORE_MODULE_2DNR_ENABLE_GET                  = 0x0000B004,
    ISPCORE_MODULE_2DNR_ENABLE_SET                  = 0x0000B005,
    ISPCORE_MODULE_2DNR_RESET                       = 0x0000B006,
    ISPCORE_MODULE_2DNR_STATUS_GET                  = 0x0000B007,
    ISPCORE_MODULE_2DNR_TABLE_GET                   = 0x0000B008,
    ISPCORE_MODULE_2DNR_TABLE_SET                   = 0x0000B009,
    ISPCORE_MODULE_2DNR_END,

    ISPCORE_MODULE_3DNR_BEGIN                       = 0x0000C000,
    ISPCORE_MODULE_3DNR_PROCESS                     = 0x0000C001,
    ISPCORE_MODULE_3DNR_CFG_GET                     = 0x0000C002,
    ISPCORE_MODULE_3DNR_CFG_SET                     = 0x0000C003,
    ISPCORE_MODULE_3DNR_ENABLE_GET                  = 0x0000C004,
    ISPCORE_MODULE_3DNR_ENABLE_SET                  = 0x0000C005,
    ISPCORE_MODULE_3DNR_RESET                       = 0x0000C006,
    ISPCORE_MODULE_3DNR_STATUS_GET                  = 0x0000C007,
    ISPCORE_MODULE_3DNR_TABLE_GET                   = 0x0000C008,
    ISPCORE_MODULE_3DNR_TABLE_SET                   = 0x0000C009,
    ISPCORE_MODULE_3DNR_END,

    ISPCORE_MODULE_DPCC_BEGIN                       = 0x0000D000,
    ISPCORE_MODULE_DPCC_PROCESS                     = 0x0000D001,
    ISPCORE_MODULE_DPCC_ENABLE_GET                  = 0x0000D002,
    ISPCORE_MODULE_DPCC_ENABLE_SET                  = 0x0000D003,
    ISPCORE_MODULE_DPCC_END,

    ISPCORE_MODULE_DPF_BEGIN                        = 0x0000E000,
    ISPCORE_MODULE_DPF_PROCESS                      = 0x0000E001,
    ISPCORE_MODULE_DPF_CFG_GET                      = 0x0000E002,
    ISPCORE_MODULE_DPF_CFG_SET                      = 0x0000E003,
    ISPCORE_MODULE_DPF_ENABLE_GET                   = 0x0000E004,
    ISPCORE_MODULE_DPF_ENABLE_SET                   = 0x0000E005,
    ISPCORE_MODULE_DPF_END,

    ISPCORE_MODULE_EC_BEGIN                         = 0x0000F000,
    ISPCORE_MODULE_EC_PROCESS                       = 0x0000F001,
    ISPCORE_MODULE_EC_CFG_GET                       = 0x0000F002,
    ISPCORE_MODULE_EC_CFG_SET                       = 0x0000F003,
    ISPCORE_MODULE_EC_STATUS_GET                    = 0x0000F004,
    ISPCORE_MODULE_EC_END,

    ISPCORE_MODULE_EE_BEGIN                         = 0x00010000,
    ISPCORE_MODULE_EE_PROCESS                       = 0x00010001,
    ISPCORE_MODULE_EE_CFG_GET                       = 0x00010002,
    ISPCORE_MODULE_EE_CFG_SET                       = 0x00010003,
    ISPCORE_MODULE_EE_ENABLE_GET                    = 0x00010004,
    ISPCORE_MODULE_EE_ENABLE_SET                    = 0x00010005,
    ISPCORE_MODULE_EE_RESET                         = 0x00010006,
    ISPCORE_MODULE_EE_STATUS_GET                    = 0x00010007,
    ISPCORE_MODULE_EE_TABLE_GET                     = 0x00010008,
    ISPCORE_MODULE_EE_TABLE_SET                     = 0x00010009,
    ISPCORE_MODULE_EE_END,

    ISPCORE_MODULE_FILESYSTEM_BEGIN                 = 0x00011000,
    ISPCORE_MODULE_FILESYSTEM_PROCESS               = 0x00011001,
    ISPCORE_MODULE_FILESYSTEM_REMOVE                = 0x00011002,
    ISPCORE_MODULE_FILESYSTEM_END,

    ISPCORE_MODULE_FILTER_BEGIN                     = 0x00012000,
    ISPCORE_MODULE_FILTER_PROCESS                   = 0x00012001,
    ISPCORE_MODULE_FILTER_CFG_GET                   = 0x00012002,
    ISPCORE_MODULE_FILTER_CFG_SET                   = 0x00012003,
    ISPCORE_MODULE_FILTER_ENABLE_GET                = 0x00012004,
    ISPCORE_MODULE_FILTER_ENABLE_SET                = 0x00012005,
    ISPCORE_MODULE_FILTER_STATUS_GET                = 0x00012006,
    ISPCORE_MODULE_FILTER_TABLE_GET                 = 0x00012007,
    ISPCORE_MODULE_FILTER_TABLE_SET                 = 0x00012008,
    ISPCORE_MODULE_FILTER_END,

    ISPCORE_MODULE_GC_BEGIN                         = 0x00013000,
    ISPCORE_MODULE_GC_PROCESS                       = 0x00013001,
    ISPCORE_MODULE_GC_CURVE_GET                     = 0x00013002,
    ISPCORE_MODULE_GC_CURVE_SET                     = 0x00013003,
    ISPCORE_MODULE_GC_CFG_GET                       = 0x00013004,
    ISPCORE_MODULE_GC_CFG_SET                       = 0x00013005,
    ISPCORE_MODULE_GC_ENABLE_GET                    = 0x00013006,
    ISPCORE_MODULE_GC_ENABLE_SET                    = 0x00013007,
    ISPCORE_MODULE_GC_END,

    ISPCORE_MODULE_HDR_BEGIN                        = 0x00014000,
    ISPCORE_MODULE_HDR_PROCESS                      = 0x00014001,
    ISPCORE_MODULE_HDR_CFG_GET                      = 0x00014002,
    ISPCORE_MODULE_HDR_CFG_SET                      = 0x00014003,
    ISPCORE_MODULE_HDR_ENABLE_GET                   = 0x00014004,
    ISPCORE_MODULE_HDR_ENABLE_SET                   = 0x00014005,
    ISPCORE_MODULE_HDR_RESET                        = 0x00014006,
    ISPCORE_MODULE_HDR_END,

    ISPCORE_MODULE_IE_BEGIN                         = 0x00015000,
    ISPCORE_MODULE_IE_PROCESS                       = 0x00015001,
    ISPCORE_MODULE_IE_CFG_GET                       = 0x00015002,
    ISPCORE_MODULE_IE_CFG_SET                       = 0x00015003,
    ISPCORE_MODULE_IE_ENABLE_GET                    = 0x00015004,
    ISPCORE_MODULE_IE_ENABLE_SET                    = 0x00015005,
    ISPCORE_MODULE_IE_END,

    ISPCORE_MODULE_LSC_BEGIN                        = 0x00016000,
    ISPCORE_MODULE_LSC_PROCESS                      = 0x00016001,
    ISPCORE_MODULE_LSC_CFG_GET                      = 0x00016002,
    ISPCORE_MODULE_LSC_CFG_SET                      = 0x00016003,
    ISPCORE_MODULE_LSC_ENABLE_GET                   = 0x00016004,
    ISPCORE_MODULE_LSC_ENABLE_SET                   = 0x00016005,
    ISPCORE_MODULE_LSC_STATUS_GET                   = 0x00016006,
    ISPCORE_MODULE_LSC_END,

    ISPCORE_MODULE_REG_BEGIN                        = 0x00017000,
    ISPCORE_MODULE_REG_PROCESS                      = 0x00017001,
    ISPCORE_MODULE_REG_DESCRIPTION                  = 0x00017002,
    ISPCORE_MODULE_REG_GET                          = 0x00017003,
    ISPCORE_MODULE_REG_SET                          = 0x00017004,
    ISPCORE_MODULE_REG_END,

    ISPCORE_MODULE_SENSOR_BEGIN                     = 0x00018000,
    ISPCORE_MODULE_SENSOR_PROCESS                   = 0x00018001,
    ISPCORE_MODULE_SENSOR_CAPS                      = 0x00018002,
    ISPCORE_MODULE_SENSOR_CFG_GET                   = 0x00018003,
    ISPCORE_MODULE_SENSOR_CFG_SET                   = 0x00018004,
    ISPCORE_MODULE_SENSOR_NAME_GET                  = 0x00018005,
    ISPCORE_MODULE_SENSOR_REVISION_GET              = 0x00018006,
    ISPCORE_MODULE_SENSOR_OPEN                      = 0x00018007,
    ISPCORE_MODULE_SENSOR_IS_CONNECTED              = 0x00018008,
    ISPCORE_MODULE_SENSOR_IS_TEST_PATTERN           = 0x00018009,
    ISPCORE_MODULE_SENSOR_DRV_CHANGE                = 0x0001800A,
    ISPCORE_MODULE_SENSOR_DRV_LIST                  = 0x0001800B,
    ISPCORE_MODULE_SENSOR_INFO                      = 0x0001800C,
    ISPCORE_MODULE_SENSOR_RESOLUTION_LIST_GET       = 0x0001800D,
    ISPCORE_MODULE_SENSOR_GET_RESOLUTION_NAME       = 0x0001800E,
    ISPCORE_MODULE_SENSOR_REG_DESCRIPTION           = 0x0001800F,
    ISPCORE_MODULE_SENSOR_REG_DUMP2FILE             = 0x00018010,
    ISPCORE_MODULE_SENSOR_REG_GET                   = 0x00018011,
    ISPCORE_MODULE_SENSOR_REG_SET                   = 0x00018012,
    ISPCORE_MODULE_SENSOR_REG_TABLE                 = 0x00018013,
    ISPCORE_MODULE_SENSOR_RESOLUTION_SET            = 0x00018014,
    ISPCORE_MODULE_SENSOR_TESTPATTERN_EN_SET        = 0x00018015,
    ISPCORE_MODULE_SENSOR_CALIB_INSTALL             = 0x00018016,
    ISPCORE_MODULE_SENSOR_CALIB_UNINSTALL           = 0x00018017,
    ISPCORE_MODULE_SENSOR_RESOLUTION_SUP_GET        = 0x00018018,
    ISPCORE_MODULE_SENSOR_FPS_GET                   = 0x00018019,
    ISPCORE_MODULE_SENSOR_FPS_SET                   = 0x0001801A,
    ISPCORE_MODULE_SENSOR_QUERY                     = 0x0001801B,
    ISPCORE_MODULE_SENSOR_MODE_GET                  = 0x0001801C,
    ISPCORE_MODULE_SENSOR_MODE_SET                  = 0x0001801D,
    ISPCORE_MODULE_SENSOR_PRE_LOAD_LIB              = 0x0001801E,
    ISPCORE_MODULE_SENSOR_RES_W_GET                 = 0x0001801F,
    ISPCORE_MODULE_SENSOR_RES_H_GET                 = 0x00018020,
    ISPCORE_MODULE_SENSOR_MODE_LOCK                 = 0x00018021,
    ISPCORE_MODULE_SENSOR_END,

    ISPCORE_MODULE_SIMP_BEGIN                       = 0x00019000,
    ISPCORE_MODULE_SIMP_PROCESS                     = 0x00019001,
    ISPCORE_MODULE_SIMP_CFG_GET                     = 0x00019002,
    ISPCORE_MODULE_SIMP_CFG_SET                     = 0x00019003,
    ISPCORE_MODULE_SIMP_ENABLE_GET                  = 0x00019004,
    ISPCORE_MODULE_SIMP_ENABLE_SET                  = 0x00019005,
    ISPCORE_MODULE_SIMP_END,

    ISPCORE_MODULE_WB_BEGIN                         = 0x0001A000,
    ISPCORE_MODULE_WB_PROCESS                       = 0x0001A001,
    ISPCORE_MODULE_WB_CFG_GET                       = 0x0001A002,
    ISPCORE_MODULE_WB_CFG_SET                       = 0x0001A003,
    ISPCORE_MODULE_WB_END,

    ISPCORE_MODULE_WDR_BEGIN                        = 0x0001B000,
    ISPCORE_MODULE_WDR_PROCESS                      = 0x0001B001,
    ISPCORE_MODULE_WDR_CFG_GET                      = 0x0001B002,
    ISPCORE_MODULE_WDR_CFG_SET                      = 0x0001B003,
    ISPCORE_MODULE_WDR_ENABLE_GET                   = 0x0001B004,
    ISPCORE_MODULE_WDR_ENABLE_SET                   = 0x0001B005,
    ISPCORE_MODULE_WDR_RESET                        = 0x0001B006,
    ISPCORE_MODULE_WDR_STATUS_GET                   = 0x0001B007,
    ISPCORE_MODULE_WDR_TABLE_GET                    = 0x0001B008,
    ISPCORE_MODULE_WDR_TABLE_SET                    = 0x0001B009,
    ISPCORE_MODULE_WDR_END,

    ISPCORE_MODULE_PIPELINE_BEGIN                   = 0x0001C000,
    ISPCORE_MODULE_PIPELINE_WARM_UP                 = 0x0001C001,
    ISPCORE_MODULE_PIPELINE_SMP_MODE                = 0x0001C002,
    ISPCORE_MODULE_PIPELINE_CFG_DWE                 = 0x0001C003,
    ISPCORE_MODULE_PIPELINE_CFG_TESTPATTEN_EN       = 0x0001C004,
    ISPCORE_MODULE_PIPELINE_RESOLUTION_IS_OUT       = 0x0001C005,
    ISPCORE_MODULE_PIPELINE_RESOLUTION_MP_OUT       = 0x0001C006,
    ISPCORE_MODULE_PIPELINE_MP_OUT_IMAGE_FORMAT     = 0x0001C007,
    ISPCORE_MODULE_PIPELINE_QUERY                   = 0x0001C008,
    ISPCORE_MODULE_PIPELINE_CFG_STATUS              = 0x0001C009,
    ISPCORE_MODULE_PIPELINE_END,

    ISPCORE_MODULE_DMSC2_BEGIN                      = 0x0001D000,
    ISPCORE_MODULE_DMSC2_PROCESS                    = 0x0001D001,
    ISPCORE_MODULE_DMSC2_CFG_SET                    = 0x0001D002,
    ISPCORE_MODULE_DMSC2_CFG_GET                    = 0x0001D003,
    ISPCORE_MODULE_DMSC2_ENABLE_SET                 = 0x0001D004,
    ISPCORE_MODULE_DMSC2_ENABLE_GET                 = 0x0001D005,
    ISPCORE_MODULE_DMSC2_END,

    ISPCORE_MODULE_GE_BEGIN                         = 0x0001E000,
    ISPCORE_MODULE_GE_PROCESS                       = 0x0001E001,
    ISPCORE_MODULE_GE_CFG_SET                       = 0x0001E002,
    ISPCORE_MODULE_GE_CFG_GET                       = 0x0001E003,
    ISPCORE_MODULE_GE_ENABLE_SET                    = 0x0001E004,
    ISPCORE_MODULE_GE_ENABLE_GET                    = 0x0001E005,
    ISPCORE_MODULE_GE_END,

    ISPCORE_MODULE_RGBGAMMA_BEGIN                   = 0x0001F000,
    ISPCORE_MODULE_RGBGAMMA_PROCESS                 = 0x0001F001,
    ISPCORE_MODULE_RGBGAMMA_CFG_SET                 = 0x0001F002,
    ISPCORE_MODULE_RGBGAMMA_CFG_GET                 = 0x0001F003,
    ISPCORE_MODULE_RGBGAMMA_ENABLE_SET              = 0x0001F004,
    ISPCORE_MODULE_RGBGAMMA_ENABLE_GET              = 0x0001F005,
    ISPCORE_MODULE_RGBGAMMA_END,

    ISPCORE_MODULE_COLORADJUST_BEGIN               = 0x00020000,
    ISPCORE_MODULE_COLORADJUST_PROCESS             = 0x00020001,
    ISPCORE_MODULE_COLORADJUST_CFG_SET             = 0x00020002,
    ISPCORE_MODULE_COLORADJUST_CFG_GET             = 0x00020003,
    ISPCORE_MODULE_COLORADJUST_ENABLE_SET          = 0x00020004,
    ISPCORE_MODULE_COLORADJUST_ENABLE_GET          = 0x00020005,
    ISPCORE_MODULE_COLORADJUST_END,

    ISPCORE_MODULE_TDNR_BEGIN                      = 0x00021000,
    ISPCORE_MODULE_TDNR_PROCESS                    = 0x00021001,
    ISPCORE_MODULE_TDNR_CFG_SET                    = 0x00021002,
    ISPCORE_MODULE_TDNR_CFG_GET                    = 0x00021003,
    ISPCORE_MODULE_TDNR_ENABLE_SET                 = 0x00021004,
    ISPCORE_MODULE_TDNR_ENABLE_GET                 = 0x00021005,
    ISPCORE_MODULE_TDNR_UPDATE_CURVE               = 0x00021006,
    ISPCORE_MODULE_TDNR_END,

    ISPCORE_MODULE_DGAIN_BEGIN                      = 0x00022000,
    ISPCORE_MODULE_DGAIN_PROCESS                    = 0x00022001,
    ISPCORE_MODULE_DGAIN_CFG_SET                    = 0x00022002,
    ISPCORE_MODULE_DGAIN_CFG_GET                    = 0x00022003,
    ISPCORE_MODULE_DGAIN_ENABLE_SET                 = 0x00022004,
    ISPCORE_MODULE_DGAIN_ENABLE_GET                 = 0x00022005,
    ISPCORE_MODULE_DGAIN_END,

    ISPCORE_MODULE_DCIHIST_BEGIN                      = 0x00023000,
    ISPCORE_MODULE_DCIHIST_PROCESS                    = 0x00023001,
    ISPCORE_MODULE_DCIHIST_CFG_SET                    = 0x00023002,
    ISPCORE_MODULE_DCIHIST_CFG_GET                    = 0x00023003,
    ISPCORE_MODULE_DCIHIST_ENABLE_SET                 = 0x00023004,
    ISPCORE_MODULE_DCIHIST_ENABLE_GET                 = 0x00023005,
    ISPCORE_MODULE_DCIHIST_STATUS_GET                 = 0x00023006,
    ISPCORE_MODULE_DCIHIST_END,

    ISPCORE_MODULE_AEHDRAUTORATIO_BEGIN               = 0x00024000,
    ISPCORE_MODULE_AEHDRAUTORATIO_PROCESS             = 0x00024001,
    ISPCORE_MODULE_AEHDRAUTORATIO_CFG_SET             = 0x00024002,
    ISPCORE_MODULE_AEHDRAUTORATIO_CFG_GET             = 0x00024003,
    ISPCORE_MODULE_AEHDRAUTORATIO_ENABLE_SET          = 0x00024004,
    ISPCORE_MODULE_AEHDRAUTORATIO_ENABLE_GET          = 0x00024005,
    ISPCORE_MODULE_AEHDRAUTORATIO_END,

    ISPCORE_MODULE_END,
} ISPCORE_MODULE_ID;

// Feature control words definitions
#define AE_MODE_PARAMS			"mode"
#define AE_DAMP_OVER_PARAMS		"damp.over"
#define AE_DAMP_UNDER_PARAMS		"damp.under"
#define AE_SET_POINT_PARAMS		"set.point"
#define AE_CLM_TOLERANCE_PARAMS		"clm.tolerance"
#define AE_FLICKER_PERIOD_PARAMS	"flicker.period"
#define AE_AFPS_PARAMS			"afps"
#define AE_HIST_PARAMS_BASE64			"hist"
#define AE_LUMA_PARAMS_BASE64			"luma"
#define AE_OBJECT_REGION_PARAMS_BASE64	"object.region"
#define AE_ENABLE_PARAMS		"enable"
#define AE_RESET_PARAMS         "reset"

#define AF_AVAILABEL_PARAMS		"available"
#define AF_ALGORITHM_PARAMS		"algorithm"
#define AF_ONESHOT_PARAMS		"oneshot"
#define AF_ENABLE_PARAMS		"enable"

#define AWB_MODE_PARAMS			"mode"
#define AWB_INDEX_PARAMS		"index"
#define AWB_DAMPING_PARAMS		"damping"
#define AWB_ENABLE_PARAMS		"enable"
#define AWB_NAME_PARAMS			"name"
#define AWB_ID_PARAMS			"id"
#define AWB_DOOR_TYPE_PARAMS		"door.type"
#define AWB_AWB_TYPE_PARAMS		"awb.type"
#define AWB_AROSS_TALK_COEFF_PARAMS	"cross.talk.coeff"
#define AWB_CROSS_TALK_OFFSET_PARAMS	"cross.talk.offset"
#define AWB_COMPONENT_GAIN_PARAMS	"component.gain"
#define AWB_GAUSS_MEAN_VALUE_PARAMS	"gauss.mean.value"
#define AWB_COVARIANCE_MATRIX_PARAMS	"covariance.matrix"
#define AWB_GAUSS_FACTOR_PARAMS		"gauss.factor"
#define AWB_THRESHOLD_PARAMS		"threshold"
#define AWB_SENSOR_GAIN_PARAMS		"sensor.gain"
#define AWB_SATURATION_PARAMS		"saturation"
#define AWB_SATURATION_CURVE_PARAMS	"saturation.curve"
#define AWB_VIGNETTING_PARAMS		"vignetting"
#define AWB_VIGNETTING_CURVE_PARAMS	"vignetting.curve"
#define AWB_CC_PROFILES_PARAMS		"cc.profiles"
#define AWB_NO_PARAMS			"no"
#define AWB_PROFILE_NAME_PARAMS		"profile.name"
#define AWB_LSC_PARAMS			"lsc"
#define AWB_PROFILES_PARAMS		"profiles"
#define AWB_F_RG_PROJ_INDOOR_MIN_PARAMS		"f.rg.proj.indoor.min"
#define AWB_F_RG_PROJ_OUTDOOR_MIN_PARAMS	"f.rg.proj.outdoor.min"
#define AWB_F_RG_PROJ_MAX_PARAMS		"f.rg.proj.max"
#define AWB_F_RG_PROJ_MAX_SKY_PARAMS		"f.rg.proj.max.sky"
#define AWB_RESET_PARAMS         "reset"

#define AVS_USER_PARAMS			"use.params"
#define AVS_ACCELERATION_PARAMS		"acceleration"
#define AVS_BASE_GAIN_PARAMS		"base.gain"
#define AVS_FALL_OFF_PARAMS		"fall.off"
#define AVS_NUM_ITP_POINTS_PARAMS	"num.itp.points"
#define AVS_THETA_PARAMS		"theta"
#define AVS_X_PARAMS			"x"
#define AVS_Y_PARAMS			"y"
#define AVS_ENABLE_PARAMS		"enable"
#define AVS_DISPLACEMENT_PARAMS		"displacement"
#define AVS_OFFSET_PARAMS		"offset"

#define BLS_RED_PARAMS		"red"
#define BLS_GREEN_R_PARAMS	"green.r"
#define BLS_GREEN_B_PARAMS	"green.b"
#define BLS_BLUE_PARAMS		"blue"

#define CAC_ENABLE_PARAMS	"enable"

#define CITF_SIZE_PARAMS	"size"
#define CITF_BIN_PARAMS		"bin"

#define CLI_NAME_PARAMS		"name"
#define CLI_NUMBER_PARAMS	"number"
#define CLI_DATE_PARAMS		"date"
#define CLI_VERSIONS_PARAMS	"versions"

#define CNR_TC1_PARAMS		"tc1"
#define CNR_TC2_PARAMS		"tc2"
#define CNR_ENABLE_PARAMS	"enable"

#define CPROC_BRIGHTNESS_PARAMS		"brightness"
#define CPROC_CHROMA_OUT_PARAMS		"chroma.out"
#define CPROC_CONTRAST_PARAMS		"contrast"
#define CPROC_HUE_PARAMS		"hue"
#define CPROC_LUMA_IN_PARAMS		"luma.in"
#define CPROC_LUMA_OUT_PARAMS		"luma.out"
#define CPROC_SATURATION_PARAMS		"saturation"
#define CPROC_ENABLE_PARAMS		"enable"

#define DEMOSAIC_MODE_PARAMS		"mode"
#define DEMOSAIC_THRESHOLD_PARAMS	"threshold"
#define DEMOSAIC_ENABLE_PARAMS		"enable"

#define DEVICE_CALIBRATION_FILE_PARAMS	"calibration.file"
#define DEVICE_FILE_PARAMS		"file"
#define DEVICE_SNAPSHOT_TYPE_PARAMS	"snapshot.type"
#define DEVICE_RESOLUTION_PARAMS	"resolution"
#define DEVICE_LOCK_TYPE_PARAMS		"lock.type"
#define DEVICE_COUNT_PARAMS		"count"
#define DEVICE_INDEX_PARAMS		"index"
#define DEVICE_INPUT_TYPE_PARAMS	"input.type"
#define DEVICE_SENSOR_DRIVER_PARAMS	"sensor.driver"
#define DEVICE_PREVIEW_PARAMS		"preview"
#define DEVICE_BITSTREAM_ID_PARAMS	"bitstreamid"
#define DEVICE_CAMER_ID_PARAMS		"camerid"
#define DEVICE_WIDTH_PARAMS         "width"
#define DEVICE_HEIGHT_PARAMS        "height"
#define DEVICE_FORMAT_PARAMS        "format"
#define DEVICE_FRAME_PARAMS         "frame"
#define DEVICE_FPS_PARAMS           "fps"
#define DEVICE_CAMCONNECT_PREVIEW   "camera.preview"
#define DEVICE_CAMCONNECT_PREVIEW_CALLBACK "camera.preview.callback"

#define DPCC_ENABLE_PARAMS		"enable"

#define DPF_GRADIENT_PARAMS	"gradient"
#define DPF_OFFSET_PARAMS	"offset"
#define DPF_MIN_PARAMS		"min"
#define DPF_DIV_PARAMS		"div"
#define DPF_SIGMA_GREEN_PARAMS		"sigma.green"
#define DPF_SIGMA_RED_BLUE_PARAMS	"sigma.red.blue"
#define DPF_ENABLE_PARAMS		"enable"

#define EC_GAIN_PARAMS		"gain"
#define EC_GAIN_MIN_PARAMS	"gain.min"
#define EC_GAIN_MAX_PARAMS	"gain.max"
#define EC_TIME_PARAMS		"time"
#define EC_INTEGRATION_MIN_PARAMS		"inte.min"
#define EC_INTEGRATION_MAX_PARAMS		"inte.max"
#define EC_STEP_PARAMS		"step"


#define EE_STRENGTH_PARAMS	"strength"
#define EE_SHARPEN_PARAMS	"sharpen"
#define EE_DEPURPLE_PARAMS	"depurple"
#define EE_ENABLE_PARAMS	"enable"
#define EE_AUTO_PARAMS     	"auto"
#define EE_CONFIG_PARAMS    "config"
#define EE_TABLE_PARAMS	    "table"
#define EE_GAIN_PARAMS     	"gain"
#define EE_INTERGRATION_TIME_PARAMS "intergration.time"

#define FILTER_DENOISE_PARAMS	"denoise"
#define FILTER_SHARPEN_PARAMS	"sharpen"
#define FILTER_ENABLE_PARAMS	"enable"
#define FILTER_AUTO_PARAMS		"auto"
#define FILTER_TABLE_PARAMS		"table"
#define FILTER_GAIN_PARAMS		"gain"
#define FILTER_INTERGRATION_TIME_PARAMS "intergration.time"

#define FS_FILENAME_PARAMS	"filename"


#define GC_CURVE_PARAMS_BASE64		"gc.curve.base64"
#define GC_CURVE_PARAMS		"gc.curve"
#define GC_MODE_PARAMS		"gc.mode"
#define GC_ENABLE_PARAMS    "enable"


#define HDR_EXPOSURE_RATIO_PARAMS	"exposure.ratio"
#define HDR_EXTENSION_BIT_PARAMS	"extension.bit"
#define HDR_TRANSRANGE_START "transrage.start"
#define HDR_TRANSRANGE_END   "transrage.end"
//#define HDR_RANGE_START_VALUE_PARAMS	"range.start.value"
//#define HDR_VERY_SHORT_WEIGHT_PARAMS	"very.short.weight"
#define HDR_ENABLE_PARAMS		"enable"

#define IE_MODE_PARAMS		"mode"
#define IE_RANGE_PARAMS		"range"
#define IE_CONFIG_PARAMS	"config"
#define IE_TINT_CB_PARAMS	"tint.cb"
#define IE_TINT_CR_PARAMS	"tint.cr"
#define IE_SELECTION_PARAMS	"selection"
#define IE_THRESHOLD_PARAMS	"threshold"
#define IE_EMBOSS_PARAMS	"emboss"
#define IE_COEFF_PARAMS		"coeff"
#define IE_SKETCH_PARAMS	"sketch"
#define IE_SHARPEN_PARAMS	"sharpen"
#define IE_FACTOR_PARAMS	"factor"

#define LSC_ENABLE_PARAMS	"enable"
#define LSC_CONFIG_PARAMS	"config"
#define LSC_ADAPTIVE_PARAMS	"adaptive"

#define CAC_CONFIG_PARAMS	"config"

#define NR2D_GENERATION_PARAMS	"generation"
#define NR2D_DENOISE_PREGAMA_STRENGTH_PARAMS  "denoise.pregama.strength"
#define NR2D_DENOISE_STRENGTH_PARAMS "denoise.strength"
#define NR2D_SIGMA_PARAMS   	"sigma"
#define NR2D_ENABLE_PARAMS  	"enable"
#define NR2D_TABLE_PARAMS		"table"
#define NR2D_AUTO_PARAMS		"auto"
#define NR2D_GAIN_PARAMS		"gain"
#define NR2D_INTERGRATION_TIME_PARAMS "intergration.time"

#define NR3D_GENERATION_PARAMS	"generation"
#define NR3D_STRENGTH_PARAMS		"strength"
//#define NR3D_SPATIAL_DENOISE_PARAMS	"spatial.denoise"
//#define NR3D_TEMPORAL_DENOISE_PARAMS	"temporal.denoise"
#define NR3D_DELTA_FACTOR_PARAMS		"delta.factor"
#define NR3D_MOTION_FACTOR_PARAMS		"motion.factor"
#define NR3D_ENABLE_PARAMS		"enable"
#define NR3D_TABLE_PARAMS		"table"
#define NR3D_AUTO_PARAMS		"auto"
#define NR3D_GAIN_PARAMS		"gain"
#define NR3D_INTERGRATION_TIME_PARAMS "intergration.time"

#define REG_MODULE_ID_PARAMS		"module.id"
#define REG_COUNT_PARAMS		"count"
#define REG_ADDRESS_PARAMS		"address"
#define REG_PERMISSION_PARAMS		"permission"
#define REG_NAME_PARAMS			"name"
#define REG_HINT_PARAMS			"hint"
#define REG_RESET_VALUE_PARAMS		"reset.value"
#define REG_USED_BITS_PARAMS		"used.bits"
#define REG_WRITABLE_BITS_PARAMS	"writable.bits"
#define REG_REGISTERS_PARAMS		"registers"
#define REG_VALUE_PARAMS		"value"

#define BASE64_PARAMS           "base64.params"
#define BASE64_SIZE             "base64.size"
#define BASE64_BIN              "base64.bin"
#define SENSOR_CAPS_PARAMS_BASE64			"caps"
#define SENSOR_CONFIG_PARAMS_BASE64			"config"
#define SENSOR_NAME_GET           "name.get"

#define SENSOR_DRIVER_FILE_PARAMS		"driver.file"
#define SENSOR_CALIB_FILE_PARAMS		"calib.file"
#define SENSOR_VALUE_PARAMS			"value"
#define SENSOR_DESCRIPTION_PARAMS		"description"
#define SENSOR_RESOLUTION_LIST_PARAMS		"resolution.list"
#define SENSOR_SENSOR_DRIVER_PARAMS     "sensor.driver"
#define SENSOR_SENSOR_I2C_NUMBER        "sensor.i2c.number"
#define SENSOR_SENSOR_DEVICEID          "sensor.deviceid"
#define SENSOR_CALIBRATION_DATA_PARAMS  "calibration.data"
#define SENSOR_SENSOR_NAME_PARAMS        "sensor.name"
#define SENSOR_SENSOR_STATE_PARAMS       "sensor.state"
#define SENSOR_SENSOR_ID_PARAMS			"sensor.id"
#define SENSOR_SENSOR_GET_RESOLUTION_NAME "resolution.name"
#define SENSOR_CONNECTION_PARAMS		"connection"
#define SENSOR_TEST_PATTERN_PARAMS		"test.pattern"
#define SENSOR_BAYER_PATTERN_PARAMS		"bayer.pattern"
#define SENSOR_BUS_WIDTH_PARAMS			"bus.width"
#define SENSOR_MIPI_MODE_PARAMS			"mipi.mode"
#define SENSOR_BLACK_LEVEL_CONTROL_PARAMS	"black.level.control"
#define SENSOR_AUTO_GAIN_CONTROL_PARAMS		"auto.gain.control"
#define SENSOR_AUTO_EXPOSURE_CONTROL_PARAMS	"auto.exposure.control"
#define SENSOR_AUTO_WHITE_BALANCE_PARAMS	"auto.white.balance"
#define SENSOR_DEFECT_PIXEL_CORRECTION_PARAMS	"defect.pixel.correction"
#define SENSOR_ADDRESS_PARAMS			"address"
#define SENSOR_DEFAULT_VALUE_PARAMS		"default.value"
#define SENSOR_NAME_PARAMS			"name"
#define SENSOR_FLAGS_PARAMS			"flags"
#define SENSOR_FILENAME_PARAMS			"filename"
#define SENSOR_REGISTERS_PARAMS			"registers"
#define SENSOR_RESOLUTION_PARAMS		"resolution"
#define SENSOR_ENABLE_PARAMS			"enable"
#define SENSOR_REG_DUMP_FILE_NAME		"reg.dump.file.name"
#define SENSOR_FPS_PARAMS			"fps"
#define SENSOR_DEVICE_NAME_PARAMS "sensor.name"
#define SENSOR_HDR_PARAMS "sensor.hdr"
#define SENSOR_MODE "mode"
#define SENSOR_RES_W "resw"
#define SENSOR_RES_H "resh"
#define ISP_DEVICE_NAME_PARAMS "isp.name"
#define CSI_DEVICE_NAME_PARAMS "csi.name"
#define CSI_DEVICE_PAD_PARAMS  "csi.pad"
#define CSI_FORMAT_PARAMS      "csi.format"


#define SIMP_ENABLE_PARAMS	"enable"
#define SIMP_FILE_PARAMS	"file"
#define SIMP_MODE_PARAMS	"mode"
#define SIMP_X_PARAMS		"x"
#define SIMP_Y_PARAMS		"y"
#define SIMP_CB_PARAMS		"cb"
#define SIMP_CR_PARAMS		"cr"

#define WB_MATRIX_PARAMS	"matrix"
#define WB_OFFSET_PARAMS	"offset"
#define WB_RED_PARAMS		"red"
#define WB_GREEN_PARAMS		"green"
#define WB_BLUE_PARAMS		"blue"
#define WB_GAINS_PARAMS		"wb.gains"
#define WB_GREEN_R_PARAMS	"green.r"
#define WB_GREEN_B_PARAMS	"green.b"

#define WDR_GENERATION_PARAMS		"generation"
#define WDR_CURVE_PARAMS		"curve"
#define WDR_D_Y_PARAMS			"d.y"
#define WDR_Y_M_PARAMS			"y.m"
#define WDR_STRENGTH_PARAMS		"strength"
#define WDR_GAIN_MAX_PARAMS		"gain.max"
#define WDR_HIGH_STRENGTH_PARAMS		"high.strength"
#define WDR_LOW_STRENGTH_PARAMS		   "low.strength"
#define WDR_STRENGTH_GLOBAL_PARAMS	"strength.global"
#define WDR_CONTRAST_PARAMS		"contrast.max"
#define WDR_FLAT_STRENGTH_PARAMS "flat_strength"
#define WDR_FLAT_THRESH_PARAMS "flat_thresh"
#define WDR_ENABLE_PARAMS		"enable"
#define WDR_AUTO_PARAMS		"auto"
#define WDR_GAIN_PARAMS		"gain"
#define WDR_INTERGRATION_TIME_PARAMS		"intergration.time"
#define WDR_TABLE_PARAMS		"table"

#define DMSC2_ENABLE_PARAMS	 "enable"
#define DMSC2_DEMOIRE_ENABLE "demoire.enable"
#define DMSC2_SHARPEN_ENABLE "sharpen.enable"
#define DMSC2_SHARPEN_LINE_ENABLE "sharpen.line.enable"
#define DMSC2_GFILTER_ENABLE "gfilter.enable"
#define DMSC2_SKIN_ENABLE "skin.enable"
#define DMSC2_DEPURPLE_ENABLE "depurple.enable"

#define RGBGAMMA_ENABLE_PARAMS	 "enable"
#define COLORADJUST_ENABLE_PARAMS	 "enable"
#define GE_ENABLE_PARAMS	 "enable"
#define GE_THRESHOLD_PARAM   "ge.threshold"
#define GE_DUMMYLINE         "ge.dummyLine"

#define TDNR_ENABLE_PARAMS	 "enable"

#define DGAIN_ENABLE_PARAMS	 "enable"
#define RECT_LEFT        "left"
#define RECT_TOP         "top"
#define RECT_WIDTH       "width"
#define RECT_HEIGHT      "height"

#endif

