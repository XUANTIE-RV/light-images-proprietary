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
 * @file cim_ctrl_common.h
 *
 * @brief
 *   ADD_DESCRIPTION_HERE
 *
 *****************************************************************************/
/**
 * @page module_name_page Module Name
 * Describe here what this module does.
 *
 * For a detailed list of functions and implementation detail refer to:
 * - @ref module_name
 *
 * @defgroup CIM_CTRL   AE, AWB and AF Control Module
 * @{
 *
 */
#ifndef __CIM_CTRL_COMMON_H__
#define __CIM_CTRL_COMMON_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Handle to mom ctrl process context.
 *
 * @note
 *
 */
typedef struct CimCtrlContext_s *CimCtrlContextHandle_t;



/**
 * @brief
 *
 * @note
 *
 */
enum CimCtrlCommand_e
{
	CIM_CTRL_CMD_INVALID                    = 0,
	CIM_CTRL_CMD_START                      = 1,
	CIM_CTRL_CMD_STOP                       = 2,
	CIM_CTRL_CMD_SHUTDOWN                   = 3,
	CIM_CTRL_CMD_MAX                        = 4
};



/**
 * @brief
 *
 * @note
 *
 */
typedef int32_t CimCtrlCmdId_t;



/**
 *  @brief Event signalling callback
 *
 *  Callback for signalling some event which could require application interaction.
 *  The eventId (see @ref momEventId_t) identifies the event and the content of
 *  pParam depends on the event ID.
 *
 */
typedef void (* CimCtrlCompletionCb_t)
(
    CimCtrlCmdId_t      CmdId,          /**< The Commad Id of the notifying event */
    RESULT				result,         /**< Result of the executed command */
    const void          *pUserContext   /**< User data pointer that was passed on chain creation */
);


#ifdef __cplusplus
}
#endif

/* @} module_name*/

#endif /* __CIM_CTRL_COMMON_H__ */

