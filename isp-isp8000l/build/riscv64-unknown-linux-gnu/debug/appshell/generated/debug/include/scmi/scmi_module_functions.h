/*******************************************************************************
 * This is an unpublished work, the copyright in which vests in sci-worx GmbH.
 * The information contained herein is the property of sci-worx GmbH and is
 * supplied without liability for errors or omissions. No part may be repro-
 * duced or used except as authorized by contract or other written permission.
 * Copyright(c) sci-worx GmbH, 2007. All rights reserved.
 *******************************************************************************
 * Module    : SCMI Module Functions
 *
 * Hierarchy : SCMI
 *
 * Purpose   : This file defines all scmi module functions
 *
 * Creator   : AGt
 *
 ******************************************************************************/


#ifndef _SCMI_MODULE_FUNCTIONS_H
#define _SCMI_MODULE_FUNCTIONS_H

#include "scmi_types.h"
#include "scmi_callbacks.h"

#if defined (__cplusplus)
extern "C" {
#endif

/** @defgroup group_module_functions Module Functions
 *  @{
 */


/*******************************************************************************
 * scmiModuleInitialize()
 *
 *******************************************************************************
 * @brief Initializes the module
 *
 * With this function a specific SCMI module is initialized. Each module
 * defines its own parameter set for initialization.
 * No SCMI function shall be called on this module until this function succeeds.
 *
 * @return Status of operation.
 */
typedef ScmiReturnType(*scmiModuleInitialize_t)
(
    void*                   p_module_instance,  /**< Module instance */
    const   ScmiParameterSet*       p_parameter_set,    /**< Initialization parameters */
    const   void*                   p_user_context,     /**< User context to be returned in callbacks */
    const   ScmiModuleCallbacks*    p_callbacks         /**< Callbacks functions for communication from module to application */
);


/*******************************************************************************
 * scmiModuleSetParameter()
 *
 *******************************************************************************
 * @brief Sets one or multiple parameters within the denoted module.
 *
 * This function is used to set the dynamic parameters of a respective module.
 * Each module defines its own parameter set IDs. Some of these may only contain
 * a single parameter, some may contain several parameters.
 * See the respective module's description for a list of all
 * possible parameter sets to be configured dynamically.
 * @note All static parameters are set in the scmiModuleInitialize_t()
 * function.
 *
 * @return Status of operation.
 */
typedef ScmiReturnType(*scmiModuleSetParameter_t)
(
    void*                   p_module_instance,  /**< Module instance */
    ScmiParameterSetId      parameter_set_id,   /**< ID of parameter set to be changed */
    const   ScmiParameterSet*       p_parameter_set     /**< Parameter set containing new values of parameters to be changed */
);


/*******************************************************************************
 * scmiModuleGetParameter()
 *
 *******************************************************************************
 * @brief Returns the value of the denoted parameter set.
 *
 * Asks the respective module to report the (dynamic) parameter set denoted by its ID.
 * The memory for the parameter set has to be provided by the calling
 * thread and will be filled by the module.
 * Each module defines its own parameter set IDs. Some of these may only contain
 * a single parameter, some may contain several parameters.
 *
 * @return Status of operation.
 */
typedef ScmiReturnType(*scmiModuleGetParameter_t)
(
    void*                   p_module_instance,  /**< Module instance */
    ScmiParameterSetId      parameter_set_id,   /**< ID of parameter set to be read */
    ScmiParameterSet*       p_parameter_set     /**< Parameter set containing values of parameters on return */
);


/*******************************************************************************
 * scmiModuleCommand()
 *
 *******************************************************************************
 * @brief Generic module depended command
 *
 * The possible values for command_id are defined by
 * the respective module.
 * \n For a list of possible module
 * commands see the respective module's documentation.
 *
 * @return Status of operation.
 */
typedef ScmiReturnType(*scmiModuleCommand_t)
(
    void*               p_module_instance,  /**< Module instance */
    ScmiCommandId       command_id,         /**< The ID of the command */
    const ScmiParameterSet*   p_parameter_set     /**< Parameter set depending on CommandID */
);


/*******************************************************************************
 * @brief Structure to pass a module's function pointers
 *
 * With this structure a module's function pointers are passed to the
 * application. By using these pointers the application can then call the module
 * functions directly.
 */
typedef struct _ScmiModuleFunctions
{
    scmiModuleInitialize_t      scmiModuleInitialize;       /**< Function pointer to initialize module */
    scmiModuleSetParameter_t    scmiModuleSetParameter;     /**< Function pointer to set parameters */
    scmiModuleGetParameter_t    scmiModuleGetParameter;     /**< Function pointer to get parameters */
    scmiModuleCommand_t         scmiModuleCommand;          /**< Function pointer to issue a command */
} ScmiModuleFunctions;


/** @} group_module_functions
 */

#if defined (__cplusplus)
}
#endif

#endif /* _SCMI_MODULE_FUNCTIONS_H */
