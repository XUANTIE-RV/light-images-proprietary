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
 * @file list.h
 *
 * @brief
 *   Extended data types: Linked list
 *
 *****************************************************************************/
/**
 * @defgroup module_ext_list Double Linked List
 *
 * @brief This module implements a "Double Linked List"
 *
 * @{
 *
 *****************************************************************************/
#ifndef __LIST_H__
#define __LIST_H__

#include "types.h"
#include "ext_types.h"


typedef struct _GList GList;

/**
 * @brief Structure that represents an element in the list.
 */
struct _GList {
  void* data;       /**< Pointer to object using the list for */
  GList *next;      /**< Pointer to next element in list */
  GList *prev;      /**< Pointer to prev element in list */
};


#define listNext(list) ((list) ? (((GList *) (list))->next) : NULL)
#define listPrevious(list) ((list) ? (((GList *) (list))->prev) : NULL)


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
GList* listAlloc(void);


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
GList* listAppend(GList* list, void* data);


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
GList* listPrepend(GList* list, void* data);


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
void listFree(GList* list);


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
void listFree1(GList* list);


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
GList* listCopy(GList*  list);


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
uint32_t listLength(GList* list);


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
int32_t listIndex(GList* list, const void*  data);


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
GList* listNth(GList * list, uint32_t n);


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
void* listNthData(GList* list, uint32_t n);


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
GList* listLast(GList* list);


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
GList* listConcat(GList* list1, GList* list2);


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
void listForeach(GList* list, GFunc func, void* user_data);


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
GList* listFirst(GList* list);


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
GList* listFind(GList* list,const void* data);


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
GList* listFindCustom(GList* list,const void* data, GCompareFunc func);


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
GList* listRemove(GList* list,const void* data);


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
GList* listReverse(GList* list);


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
GList* listRemoveLink(GList* list, GList* link);


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
GList* listDeleteLink(GList* list, GList* link);


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
GList* listInsertSorted(GList* list, void* data, GCompareFunc func);


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
GList* listInsertBefore(GList* list, GList* sibling, void* data);


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
GList* listSort(GList* sort, GCompareFunc func);

/* @} module_ext_list */

#endif /* __LIST_H__ */


