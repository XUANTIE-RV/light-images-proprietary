/******************************************************************************
 * This is an unpublished work, the copyright in which vests in sci-worx GmbH.
 * The information contained herein is the property of sci-worx GmbH and is
 * supplied without liability for errors or omissions. No part may be repro-
 * duced or used except as authorized by contract or other written permission.
 * Copyright(c) sci-worx GmbH, 2007. All rights reserved.
 *-----------------------------------------------------------------------------
 * Module    : SCMI callbacks
 *
 * Hierarchy : SCMI
 *
 * Purpose   : This file defines all callback functions that are used within SCMI
 *
 * Creator   : AGt
 *
 *****************************************************************************/


/** @file scmi_callbacks.h
 *  @brief sci-worx Common Media Interface (SCMI) callbacks
 */

#ifndef __SCMI_CALLBACKS_H__
#define __SCMI_CALLBACKS_H__

#include "scmi_types.h"


#if defined (__cplusplus)
extern "C" {
#endif


/** @defgroup group_callbacks Callbacks
 *  @{
 */


/*******************************************************************************
 *  scmiCbEvent()
 *
 *  @brief Event callback
 *
 *  This callback is used to signal something to the application software,
 *  e.g. an error or an information.
 *  Each module can define its own events with matching
 *  parameter sets. Note that system events always have the ModuleHandle 0.
 *  \n For a list of possible module
 *  events see the respective module's documentation.
 *
 *  @return void
 */
typedef void (*scmiCbEvent_t)
(
    void*                       p_module_instance,  /**< The calling module instance */
    ScmiEventId                 event_id,           /**< The event ID */
    const ScmiParameterSet*     p_parameter_set,    /**< The parameter set specific to this event */
    const void*                 p_user_context      /**< The user data pointer that was passed on module init */
);


/*******************************************************************************
 *  scmiCbRequest()
 *
 *  @brief Request callback
 *
 *  This callback is used to request something from the application software,
 *  e.g. an input or output buffer.
 *  Each module can define its own requests with matching
 *  parameter sets.
 *  \n For a list of possible module
 *  requests see the respective module's documentation.
 *
 *  @return SCMI_RETURN_TYPE
 */
typedef ScmiReturnType(*scmiCbRequest_t)
(
    void*                   p_module_instance,  /**< The calling module instance */
    ScmiRequestId           request_id,         /**< The request ID */
    ScmiParameterSet*       p_parameter_set,    /**< The parameter set specific to this request */
    const void*             p_user_context      /**< The user data pointer that was passed on module init */
);



/*******************************************************************************
 *  scmiCbCompleted()
 *
 *  @brief Completion of asynchronous command callback
 *
 *  Callback for signalling the completion of an asynchronous command.
 *  The command_id identifies the command
 *  The content of pParameterSet depends on uiCommandID.
 *
 *  @return void
 */
typedef void (*scmiCbCompleted_t)
(
    void*                       p_module_instance,  /**< The calling module instance */
    ScmiCommandId               command_id,         /**< The command ID of the asynchronously completed command */
    ScmiReturnType              result,             /**< Result of the asynchronous function call */
    const ScmiParameterSet*     p_parameter_set,    /**< The parameter set specific to this completion */
    const void*                 p_user_context      /**< The user data pointer that was passed on module init */
);




/*******************************************************************************
 *  @brief Structure to pass the application's callback function pointers
 *
 *  With this structure the application's callback function pointers
 *  are passed to the module by a call of @ref scmiModuleInitialize.
 */
typedef struct _ScmiModuleCallbacks
{
    scmiCbEvent_t         scmiCbEvent;      /**< Event callback */
    scmiCbRequest_t       scmiCbRequest;    /**< Request callback */
    scmiCbCompleted_t     scmiCbCompleted;  /**< Asynchronous command completed callback */
} ScmiModuleCallbacks;



/** @} group_callbacks
 */

#if defined (__cplusplus)
}
#endif

#endif  /* __SCMI_CALLBACKS_H__ */
