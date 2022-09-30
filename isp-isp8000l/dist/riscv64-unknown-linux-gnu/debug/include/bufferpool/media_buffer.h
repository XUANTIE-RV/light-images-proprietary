/******************************************************************************\
|* Copyright (c) <2010> by Silicon Image, Inc., used with permission by       *|
|* VeriSilicon.                                                               *|
|* Copyright (c) <2020> by VeriSilicon Holdings Co., Ltd. ("VeriSilicon")     *|
|* All Rights Reserved.                                                       *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of VeriSilicon.  This is proprietary information owned or licensed by      *|
|* VeriSilicon.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of VeriSilicon.                                         *|
|*                                                                            *|
\******************************************************************************/

/* VeriSilicon 2020 */

/**
 * @file media_buffer.h
 *
 * @brief
 *          Media Buffer interface
 *
 * <pre>
 *
 *   Principal Author: Joerg Detert
 *   Creation date:    Feb 28, 2008
 *
 * </pre>
 *
 *****************************************************************************/
#ifndef MEDIA_BUFFER_H_
#define MEDIA_BUFFER_H_


#include <ebase/types.h>
#include <ebase/dct_assert.h>

#include <scmi/scmi_types.h>
#include <cam_device/cam_device_buf_defs.h>

#if defined (__cplusplus)
extern "C" {
#endif


/**
 *  @brief Enumeration of buffer flags used by @ref ScmiBuffer
 *
 */
enum /* BUFFER_FLAGS */
{
    BUFFER_LAST             = 0x00000001,   /**< Indicates the last buffer of a sequence of buffers
                                             (e.g. last input buffer in stream, last output buffer in
                                             sequence, or last buffer of a unit of application data). */
    BUFFER_END_OF_SPLICE    = 0x00000002    /**< Indicates the last buffer of a splice. */
};


/*****************************************************************************/
/**
 * @brief   Initialize a @ref MediaBuffer_t.
 *
 * @param   pBuf    Buffer to initialize.
 *
 *****************************************************************************/
extern void MediaBufInit(MediaBuffer_t* pBuf);


/*****************************************************************************/
/**
 * @brief   Resize a @ref MediaBuffer_t.
 *
 * @param   pBuf         Buffer to adjust in size.
 * @param   frontAdjust  Relative front adjust to resize used buffer space.
 * @param   backAdjust   Relative back adjust to resize used buffer space.
 *
 *****************************************************************************/
extern void MediaBufResize(MediaBuffer_t* pBuf, uint32_t frontAdjust, uint32_t backAdjust);


/*****************************************************************************/
/**
 *
 *   Functions to get/read members of media buffer structure.
 *
 *****************************************************************************/


/*****************************************************************************/
/**
 * @brief   Returns timestamp of selected media buffer.
 *
 * @param   pBuf    Buffer of interest.
 *
 * @return  Timestamp of buffer.
 *
 *****************************************************************************/
INLINE int64_t MediaBufGetTimeStamp(const MediaBuffer_t* pBuf)
{
    DCT_ASSERT(pBuf != NULL);

    return  pBuf->buf.time_stamp;
}


/*****************************************************************************/
/**
 * @brief   Returns indication if buffer contains a frame suitable as sync point.
 *
 * @param   pBuf    Buffer of interest.
 *
 * @return  Buffer contains sync point frame or not.
 *
 *****************************************************************************/
INLINE bool_t MediaBufIsSyncPoint(const MediaBuffer_t *pBuf)
{
    DCT_ASSERT(pBuf != NULL);

    return  pBuf->syncPoint;
}


/*****************************************************************************/
/**
 * @brief   Returns indication if buffer is last one delivered by a source
 *          module.
 *
 * @param   pBuf    Buffer of interest.
 *
 * @return  Buffer is last or not.
 *
 *****************************************************************************/
INLINE bool_t MediaBufIsLast(const MediaBuffer_t *pBuf)
{
    DCT_ASSERT(pBuf != NULL);

    return pBuf->last;
}


/*****************************************************************************/
/**
 * @brief   Returns (possibly adjusted) size of media buffer.
 *
 * @param   pBuf    Buffer of interest.
 *
 * @return  Current size of buffer (i.e. size of filled underlying physical memory chunk).
 *
 *****************************************************************************/
INLINE uint32_t MediaBufGetSize(const MediaBuffer_t *pBuf)
{
    DCT_ASSERT(pBuf != NULL);

    return pBuf->buf.size;
}


/*****************************************************************************/
/**
 * @brief   Returns the base (original) size of media buffer.
 *
 * @param   pBuf    Buffer of interest.
 *
 * @return  Original (unadjusted) size of buffer (i.e. size of underlying physical memory chunk).
 *
 *****************************************************************************/
INLINE uint32_t MediaBufGetBaseSize(const MediaBuffer_t *pBuf)
{
    DCT_ASSERT(pBuf != NULL);

    return pBuf->baseSize;
}


/*****************************************************************************/
/**
 * @brief   Returns the front adjust used to resize the start of buffer space.
 *
 * @param   pBuf    Buffer of interest.
 *
 * @return  Front adjust.
 *
 *****************************************************************************/
INLINE uint32_t MediaBufGetFrontAdjust(const MediaBuffer_t *pBuf)
{
    DCT_ASSERT(pBuf != NULL);

    return (uint32_t)((uintptr_t)pBuf->buf.p_address - pBuf->baseAddress);
}


/*****************************************************************************/
/**
 * @brief   Returns the back adjust used to resize the end of buffer space.
 *
 * @param   pBuf    Buffer of interest.
 *
 * @return  Back adjust.
 *
 *****************************************************************************/
INLINE uint32_t MediaBufGetBackAdjust(const MediaBuffer_t *pBuf)
{
    DCT_ASSERT(pBuf != NULL);

    return pBuf->baseSize - (MediaBufGetFrontAdjust(pBuf) + MediaBufGetSize(pBuf));
}


/*****************************************************************************/
/**
 * @brief   Returns the data start of the selected media buffer. Note that any
 *          resizing is considered.
 *
 * @param   pBuf    Buffer of interest.
 *
 * @return  Pointer to start of data in buffer.
 *

 *****************************************************************************/
INLINE uint32_t MediaBufGetAddress(const MediaBuffer_t *pBuf)
{
    DCT_ASSERT(pBuf != NULL);

    return (uint32_t)(uintptr_t)pBuf->buf.p_address;
}


/*****************************************************************************/
/**
 * @brief   Returns the base (original) start address of the selected media
 *          buffer. Note that any resizing is _NOT_ considered.
 *
 * @param   pBuf    Buffer of interest.
 *
 * @return  Pointer to start of buffer.
 *

 *****************************************************************************/
INLINE uint32_t MediaBufGetBaseAddress(const MediaBuffer_t *pBuf)
{
    DCT_ASSERT(pBuf != NULL);

    return pBuf->baseAddress;
}


/*****************************************************************************/
/**
 * @brief   Returns the indication if metadata is available for this media
 *          buffer.
 *
 * @param   pBuf    Buffer of interest.
 *
 * @return  Metadata is available or not.
 *
 *****************************************************************************/
INLINE bool_t MediaBufHasMetaData(const MediaBuffer_t *pBuf)
{
    DCT_ASSERT(pBuf != NULL);

    return ( (bool_t)(pBuf->buf.p_meta_data != NULL) );
}


/*****************************************************************************/
/**
 * @brief   Returns the metadata for this media buffer.
 *
 * @param   pBuf    Buffer of interest.
 *
 * @return  Pointer to meta data.
 *
 *****************************************************************************/
INLINE void* MediaBufGetMetaData( const MediaBuffer_t *pBuf)
{
    DCT_ASSERT(pBuf != NULL);

    return pBuf->buf.p_meta_data;
}


/*****************************************************************************/
/**
 *   Functions to set/write members of media buffer structure
 *****************************************************************************/


/*****************************************************************************/
/**
 * @brief   Set the timestamp for this media buffer.
 *
 * @param   pBuf        Target buffer.
 * @param   timeStamp   Timestamp to set.
 *
 *****************************************************************************/
INLINE void MediaBufSetTimeStamp(MediaBuffer_t *pBuf, int64_t timeStamp)
{
    DCT_ASSERT(pBuf != NULL);

    pBuf->buf.time_stamp = timeStamp;
}


/*****************************************************************************/
/**
 * @brief   Set the sync point indication flag for this media buffer.
 *
 * @param   pBuf        Target buffer.
 * @param   syncPoint   This buffer contains a sync point frame or not.
 *
 *****************************************************************************/
INLINE void MediaBufSetIsSyncPoint(MediaBuffer_t *pBuf, bool_t syncPoint)
{
    DCT_ASSERT(pBuf != NULL);

    pBuf->syncPoint = syncPoint;
}


/*****************************************************************************/
/**
 * @brief   Set the last buffer in stream indication flag for this media buffer.
 *
 * @param   pBuf    Target buffer.
 * @param   last    Buffer is last in stream or not.
 *
 *****************************************************************************/
INLINE void MediaBufSetIsLast(MediaBuffer_t *pBuf, bool_t last)
{
    DCT_ASSERT(pBuf != NULL);

    pBuf->last = last;
}


/*****************************************************************************/
/**
 * @brief Lock a buffer of a owning buffer pool. Buffer will not be available as
 *        empty buffer until unlocked as many times as locked before
 *        and released.
 *
 * @param   pBufQueue   Pointer to Media Buffer Queue object.
 * @param   pBuf        Pointer to media buffer.
 *
 * @return  Status of operation.
 *****************************************************************************/
extern ScmiReturnType MediaBufLockBuffer(MediaBuffer_t*   pBuf);


/*****************************************************************************/
/**
 * @brief Unlock a buffer of a owning buffer pool which has previously been locked.
 *
 * @param   pBufQueue   Pointer to Media Buffer Queue object.
 * @param   pBuf        Pointer to media buffer.
 *
 * @return  Status of operation.
 *****************************************************************************/
extern ScmiReturnType MediaBufUnlockBuffer(MediaBuffer_t*   pBuf);


#if defined (__cplusplus)
}
#endif


#endif /*MEDIA_BUFFER_H_*/
