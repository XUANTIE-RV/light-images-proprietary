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

/**
 * @file mapbuffer.h
 *
 * @brief
 *   Mapping of buffers.
 *
 *****************************************************************************/
/**
 *
 * @mainpage Module Documentation
 *
 *
 * Doc-Id: xx-xxx-xxx-xxx (NAME Implementation Specification)\n
 * Author: NAME
 *
 * DESCRIBE_HERE
 *
 *
 * The manual is divided into the following sections:
 *
 * -@subpage module_name_api_page \n
 * -@subpage module_name_page \n
 *
 * @page module_name_api_page Module Name API
 * This module is the API for the NAME. DESCRIBE IN DETAIL / ADD USECASES...
 *
 * for a detailed list of api functions refer to:
 * - @ref module_name_api
 *
 * @defgroup module_name_api Module Name API
 * @{
 */

#pragma once

#include <common/picture_buffer.h>
#include <ebase/builtins.h>
#include <ebase/trace.h>
#include <hal/hal_api.h>

/******************************************************************************
 * mapRawBuffer
 *****************************************************************************/
static bool mapRawBuffer(HalHandle_t hal, const PicBufMetaData_t *pSrcBuffer,
                         PicBufMetaData_t *pDstBuffer) {
  DCT_ASSERT(NULL != hal);

  DCT_ASSERT(NULL != pDstBuffer);
  DCT_ASSERT(NULL != pSrcBuffer);

  if ((NULL == pSrcBuffer->Data.raw.pData) ||
      (0 == pSrcBuffer->Data.raw.PicWidthPixel) ||
      (0 == pSrcBuffer->Data.raw.PicWidthBytes) ||
      (0 == pSrcBuffer->Data.raw.PicHeightPixel)) {
    MEMSET(pDstBuffer, 0, sizeof(PicBufMetaData_t));
    return false;
  }

  // copy meta data
  *pDstBuffer = *pSrcBuffer;

  pDstBuffer->Data.raw.pData = NULL;

  // get sizes & base addresses of plane
  uint32_t PlaneSize =
      pSrcBuffer->Data.raw.PicWidthBytes * pSrcBuffer->Data.raw.PicHeightPixel;
  uint32_t BaseAddr = (uint32_t)(uint64_t)(pSrcBuffer->Data.raw.pData);

  if (RET_SUCCESS != HalMapMemory(hal, BaseAddr, PlaneSize, HAL_MAPMEM_READONLY,
                                  (void **)&(pDstBuffer->Data.raw.pData))) {
    MEMSET(pDstBuffer, 0, sizeof(PicBufMetaData_t));
    return false;
  }

  return true;
}

/******************************************************************************
 * mapYCbCrBuffer
 *****************************************************************************/
static bool mapYCbCrBuffer(HalHandle_t hal, const PicBufMetaData_t *pSrcBuffer,
                           PicBufMetaData_t *pDstBuffer) {
  DCT_ASSERT(NULL != hal);

  DCT_ASSERT(NULL != pDstBuffer);
  DCT_ASSERT(NULL != pSrcBuffer);

  if ((NULL == pSrcBuffer->Data.raw.pData) ||
      (0 == pSrcBuffer->Data.raw.PicWidthPixel) ||
      (0 == pSrcBuffer->Data.raw.PicWidthBytes) ||
      (0 == pSrcBuffer->Data.raw.PicHeightPixel)) {
    MEMSET(pDstBuffer, 0, sizeof(PicBufMetaData_t));
    return false;
  }

  // copy meta data
  *pDstBuffer = *pSrcBuffer;

  if (PIC_BUF_LAYOUT_COMBINED == pSrcBuffer->Layout) {
    pDstBuffer->Data.YCbCr.combined.pData = NULL;

    // get sizes & base addresses of plane
    uint32_t YCPlaneSize = pSrcBuffer->Data.YCbCr.combined.PicWidthBytes *
                           pSrcBuffer->Data.YCbCr.combined.PicHeightPixel;
    uint32_t YCBaseAddr =
        (uint32_t)(uint64_t)(pSrcBuffer->Data.YCbCr.combined.pData);

    // map combined plane
    if (RET_SUCCESS !=
        HalMapMemory(hal, YCBaseAddr, YCPlaneSize, HAL_MAPMEM_READONLY,
                     (void **)&(pDstBuffer->Data.YCbCr.combined.pData))) {
      MEMSET(pDstBuffer, 0, sizeof(PicBufMetaData_t));
      return false;
    }
  } else if (PIC_BUF_LAYOUT_SEMIPLANAR == pSrcBuffer->Layout) {
    pDstBuffer->Data.YCbCr.semiplanar.Y.pData = NULL;
    pDstBuffer->Data.YCbCr.semiplanar.CbCr.pData = NULL;

    // get sizes & base addresses of planes
    uint32_t YPlaneSize = pSrcBuffer->Data.YCbCr.semiplanar.Y.PicWidthBytes *
                          pSrcBuffer->Data.YCbCr.semiplanar.Y.PicHeightPixel;
    uint32_t CbCrPlaneSize =
        pSrcBuffer->Data.YCbCr.semiplanar.CbCr.PicWidthBytes *
        pSrcBuffer->Data.YCbCr.semiplanar.CbCr.PicHeightPixel;
    uint32_t YBaseAddr =
        (uint32_t)(uint64_t)(pSrcBuffer->Data.YCbCr.semiplanar.Y.pData);
    uint32_t CbCrBaseAddr =
        (uint32_t)(uint64_t)(pSrcBuffer->Data.YCbCr.semiplanar.CbCr.pData);

    // map luma plane
    if (RET_SUCCESS !=
        HalMapMemory(hal, YBaseAddr, YPlaneSize, HAL_MAPMEM_READONLY,
                     (void **)&(pDstBuffer->Data.YCbCr.semiplanar.Y.pData))) {
      MEMSET(pDstBuffer, 0, sizeof(PicBufMetaData_t));
      return false;
    }

    // map combined chroma plane
    if (RET_SUCCESS !=
        HalMapMemory(
            hal, CbCrBaseAddr, CbCrPlaneSize, HAL_MAPMEM_READONLY,
            (void **)&(pDstBuffer->Data.YCbCr.semiplanar.CbCr.pData))) {
      (void)HalUnMapMemory(hal, pDstBuffer->Data.YCbCr.semiplanar.Y.pData);
      MEMSET(pDstBuffer, 0, sizeof(PicBufMetaData_t));
      return false;
    }
  } else if (PIC_BUF_LAYOUT_PLANAR == pSrcBuffer->Layout) {
    pDstBuffer->Data.YCbCr.planar.Y.pData = NULL;
    pDstBuffer->Data.YCbCr.planar.Cb.pData = NULL;
    pDstBuffer->Data.YCbCr.planar.Cr.pData = NULL;

    // get sizes & base addresses of planes
    uint32_t YPlaneSize = pSrcBuffer->Data.YCbCr.planar.Y.PicWidthBytes *
                          pSrcBuffer->Data.YCbCr.planar.Y.PicHeightPixel;
    uint32_t CbPlaneSize = pSrcBuffer->Data.YCbCr.planar.Cb.PicWidthBytes *
                           pSrcBuffer->Data.YCbCr.planar.Cb.PicHeightPixel;
    uint32_t CrPlaneSize = pSrcBuffer->Data.YCbCr.planar.Cr.PicWidthBytes *
                           pSrcBuffer->Data.YCbCr.planar.Cr.PicHeightPixel;
    uint32_t YBaseAddr =
        (uint32_t)(uint64_t)(pSrcBuffer->Data.YCbCr.planar.Y.pData);
    uint32_t CbBaseAddr =
        (uint32_t)(uint64_t)(pSrcBuffer->Data.YCbCr.planar.Cb.pData);
    uint32_t CrBaseAddr =
        (uint32_t)(uint64_t)(pSrcBuffer->Data.YCbCr.planar.Cr.pData);

    // map luma plane
    if (RET_SUCCESS !=
        HalMapMemory(hal, YBaseAddr, YPlaneSize, HAL_MAPMEM_READONLY,
                     (void **)&(pDstBuffer->Data.YCbCr.planar.Y.pData))) {
      MEMSET(pDstBuffer, 0, sizeof(PicBufMetaData_t));
      return false;
    }

    // map Cb plane
    if (RET_SUCCESS !=
        HalMapMemory(hal, CbBaseAddr, CbPlaneSize, HAL_MAPMEM_READONLY,
                     (void **)&(pDstBuffer->Data.YCbCr.planar.Cb.pData))) {
      (void)HalUnMapMemory(hal, pDstBuffer->Data.YCbCr.semiplanar.Y.pData);
      MEMSET(pDstBuffer, 0, sizeof(PicBufMetaData_t));
      return false;
    }

    // map Cr plane
    if (RET_SUCCESS !=
        HalMapMemory(hal, CrBaseAddr, CrPlaneSize, HAL_MAPMEM_READONLY,
                     (void **)&(pDstBuffer->Data.YCbCr.planar.Cr.pData))) {
      (void)HalUnMapMemory(hal, pDstBuffer->Data.YCbCr.planar.Cb.pData);
      (void)HalUnMapMemory(hal, pDstBuffer->Data.YCbCr.planar.Y.pData);
      MEMSET(pDstBuffer, 0, sizeof(PicBufMetaData_t));
      return false;
    }
  }

  return true;
}

/******************************************************************************
 * unmapRawBuffer
 *****************************************************************************/
static bool unmapRawBuffer(HalHandle_t hal, PicBufMetaData_t *pData) {
  DCT_ASSERT(NULL != hal);

  DCT_ASSERT(NULL != pData);

  if (RET_SUCCESS != HalUnMapMemory(hal, (void *)(pData->Data.raw.pData))) {
    return false;
  }

  MEMSET(pData, 0, sizeof(PicBufMetaData_t));
  return true;
}

/******************************************************************************
 * unmapYCbCrBuffer
 *****************************************************************************/
static bool unmapYCbCrBuffer(HalHandle_t hal, PicBufMetaData_t *pData) {
  DCT_ASSERT(NULL != hal);

  DCT_ASSERT(NULL != pData);

  if (PIC_BUF_LAYOUT_COMBINED == pData->Layout) {
    if (RET_SUCCESS !=
        HalUnMapMemory(hal, (void *)(pData->Data.YCbCr.combined.pData))) {
      return false;
    }
  } else if (PIC_BUF_LAYOUT_SEMIPLANAR == pData->Layout) {
    if (RET_SUCCESS !=
        HalUnMapMemory(hal, (void *)(pData->Data.YCbCr.semiplanar.Y.pData))) {
      return false;
    }
    pData->Data.YCbCr.semiplanar.Y.pData = NULL;

    if (RET_SUCCESS !=
        HalUnMapMemory(hal,
                       (void *)(pData->Data.YCbCr.semiplanar.CbCr.pData))) {
      return false;
    }
  } else if (PIC_BUF_LAYOUT_PLANAR == pData->Layout) {
    if (RET_SUCCESS !=
        HalUnMapMemory(hal, (void *)(pData->Data.YCbCr.planar.Y.pData))) {
      return false;
    }
    pData->Data.YCbCr.planar.Y.pData = NULL;

    if (RET_SUCCESS !=
        HalUnMapMemory(hal, (void *)(pData->Data.YCbCr.planar.Cb.pData))) {
      return false;
    }
    pData->Data.YCbCr.planar.Cb.pData = NULL;

    if (RET_SUCCESS !=
        HalUnMapMemory(hal, (void *)(pData->Data.YCbCr.planar.Cr.pData))) {
      return false;
    }
  }

  MEMSET(pData, 0, sizeof(PicBufMetaData_t));
  return true;
}

/* @} module_name_api*/
