/******************************************************************************\
|* Copyright 2010, Dream Chip Technologies GmbH. used with permission by      *|
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
 * @file queue.h
 *
 * @brief
 *   Extended data types: Queue
 *
 *****************************************************************************/
/**
 * @defgroup module_ext_queue Queue
 *
 * @{
 *
 *****************************************************************************/
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "types.h"
#include "ext_types.h"
#include "list.h"


/**
 * @brief Structure that represents an element in the queue.
 */
typedef struct
{
    GList *head;        /**< Head element of queue */
    GList *tail;        /**< Tail  element of queue  */
    uint32_t length;    /**< Length  of queue  */
} GQueue;


/*****************************************************************************/
/**
 * @brief
 *
 * @param
 *
 * @return
 * @retval
 *
 *****************************************************************************/
void* queuePopHead(GQueue* queue);


/*****************************************************************************/
/**
 * @brief
 *
 * @param
 *
 * @return
 * @retval
 *
 *****************************************************************************/
void queuePushHead(GQueue* queue, void* data);

/*****************************************************************************/
/**
 * @brief
 *
 * @param
 *
 * @return
 * @retval
 *
 *****************************************************************************/
bool_t queueIsEmpty(GQueue* queue);

/*****************************************************************************/
/**
 * @brief
 *
 * @param
 *
 * @return
 * @retval
 *
 *****************************************************************************/
GQueue* queueNew(void);

/*****************************************************************************/
/**
 * @brief
 *
 * @param
 *
 * @return
 * @retval
 *
 *****************************************************************************/
void queueFree(GQueue* queue);

/* @} module_ext_queue */

#endif /* __QUEUE_H__ */
