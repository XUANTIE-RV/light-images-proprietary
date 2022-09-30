/*******************************************************************************
 * This is an unpublished work, the copyright in which vests in sci-worx GmbH.
 * The information contained herein is the property of sci-worx GmbH and is
 * supplied without liability for errors or omissions. No part may be repro-
 * duced or used except as authorized by contract or other written permission.
 * Copyright(c) sci-worx GmbH, 2007. All rights reserved.
 *******************************************************************************
 * Module    : SCMI System Functions
 *
 * Hierarchy : SCMI
 *
 * Purpose   : This file defines all scmi system functions
 *
 * Creator   : AGt
 *
 ******************************************************************************/

/** @file scmi_system_functions.h
 *  @brief sci-worx Common Media Interface (SCMI) system functions
 */

#ifndef _SCMI_SYSTEM_FUNCTIONS_H
#define _SCMI_SYSTEM_FUNCTIONS_H

#include "scmi_types.h"

#if defined (__cplusplus)
extern "C" {
#endif



/** @defgroup group_system_functions System Functions
 *  @{
 */

/*******************************************************************************
 * @brief Initializes an SCMI system.
 *
 * With this function an SCMI system is initialized. This function has to
 * return succesfully before any other functions can be called. Subsequent
 * calls to this function without calling @ref scmiSystemShutdown_t in between will
 * result in a "already initialized" return value.
 * The parameter set passed depends on the specific SCMI system.
 * For more information, please refer to the system's documentation
 * @return Status of operation.
 */
typedef ScmiReturnType(*scmiSystemInitialize_t)
(
    const ScmiParameterSet*  p_scmi_system_init_parameter    /**< System parameter */
);



/*******************************************************************************
 * @brief Retrieves the size of the basic memory needed by a specific module type.
 *
 * The module is addressed with a module ID defined by the respective system.
 * For a list of possible module typed ID's see the
 * respective system's documentation.
 *
 * After returning the application can allocate a memory block of the given size
 * and pass it in a call to @ref scmiSystemCreateModule_t.
 *
 * @return Size of basic memory needed by module type in bytes.
 */
typedef uint32_t (*scmiSystemGetModuleMemSize_t)
(
    ScmiModuleTypeId    module_type_id  /**< Module type ID */
);



/*******************************************************************************
 * @brief Creates an instance of a specific module.
 *
 * The module is addressed with a module ID defined by the respective system,
 * which is the same as in the call of @ref scmiSystemGetModuleMemSize_t.
 * After this function returns the application can call the module's
 * functions directly through the function pointers in \c *p_module_functions.
 * With the returned module handle the module can be specified in future calls
 * to module functions.
 *
 * The variable p_module_instance must point to a memory block of size
 * as retrieved by @ref scmiSystemGetModuleMemSize_t.
 * This pointer identifies the instance and will also be passed
 * to every module function and to @ref scmiSystemShutdownModule_t.
 * The variable p_module_functions is an out parameter which points
 * to the module's function table on return of the function.
 *
 * After returning the host application should call the
 * @ref scmiModuleInitialize_t function of this module.
 *
 * @return Status of operation.
 */
typedef ScmiReturnType(*scmiSystemCreateModule_t)
(
    ScmiModuleTypeId        module_type_id,     /**< Module type ID */
    void*                   p_module_instance,  /**< Module instance */
    ScmiModuleFunctions*    p_module_functions  /**< Module function pointers */
);


/*******************************************************************************
 * @brief Stops and shuts down a module instance
 *
 * When the function succeeds the module's handle will no longer be valid.
 *
 * @return Status of operation.
 */
typedef ScmiReturnType(*scmiSystemShutdownModule_t)
(
    void*   p_module_instance   /**< Module instance */
);

/*******************************************************************************
 * scmiSystemSetParameters()
 *
 *******************************************************************************
 * @brief Sets one or multiple parameters within an SCMI system.
 *
 * This function is used to set the dynamic parameters of an scmi system.
 * A system, like each module, defines its own parameter set IDs.
 * Some of these may only contain a single parameter, some may contain
 * several parameters. See the respective scmi system's description for a list of all
 * possible parameters sets to be configured dynamically.
 * @note All static parameters are set in the scmiSystemInitialize()
 * function.
 *
 * @return Status of operation.
 */
typedef ScmiReturnType(*scmiSystemSetParameter_t)
(
    ScmiParameterSetId    parameter_set_id,   /**< ID of parameter set to be changed */
    const ScmiParameterSet*     p_parameter_set     /**< Parameter set containing new values of parameters to be changed */
);


/*******************************************************************************
 * scmiSystemGetParameters()
 *
 *******************************************************************************
 * @brief Returns the value of the denoted parameter.
 *
 * Asks the system to report the (dynamic) parameter set denoted by its ID.
 * The memory for the parameter has to be provided by the calling
 * thread and will be filled by the scmi system.
 * A system, like each module, defines its own parameter set IDs.
 * Some of these may only contain
 * a single parameter, some may contain several parameters.
 * See the scmi system's description for a list of all possible
 * parameters sets to be read.
 *
 * @return Status of operation.
 */
typedef ScmiReturnType(*scmiSystemGetParameter_t)
(
    ScmiParameterSetId      parameter_set_id,    /**< ID of parameter set to be read */
    ScmiParameterSet*       p_parameter_set      /**< Parameter set containing values of parameters on return */
);


/*******************************************************************************
 * scmiSystemCommand()
 *
 *******************************************************************************
 * @brief Generic SCMI system command
 *
 * This is a common command function for all system-specific commands. For a
 * list of all possible commands see the system's description.
 *
 * @return Status of operation.
 */
typedef ScmiReturnType(*scmiSystemCommand_t)
(
    ScmiCommandId       command_id,         /**< The ID of the command */
    const ScmiParameterSet*   p_parameter_set     /**< Parameter set depending on CommandID */
);


/*******************************************************************************
 * @brief Shutdown an SCMI system.
 *
 * This function shuts down all currently active modules and then shuts down
 * the scmi system itself.
 *
 * @return Status of operation.
 */
typedef ScmiReturnType(*scmiSystemShutdown_t)
(
    void
);


/*******************************************************************************
 * @brief Structure holding the SCMI system function pointers
 *
 * With this structure the SCMI system function pointers are passed to the
 * application. By using these pointers the application can then call the
 * SCMI system functions directly.
 */
typedef struct _ScmiSystemFunctions
{
    scmiSystemInitialize_t         scmiSystemInitialize;        /**< Function pointer to initialize a system */
    scmiSystemGetModuleMemSize_t   scmiSystemGetModuleMemSize;  /**< Function pointer to get memory size for a module type */
    scmiSystemCreateModule_t       scmiSystemCreateModule;      /**< Function pointer to create a module instance */
    scmiSystemShutdownModule_t     scmiSystemShutdownModule;    /**< Function pointer to shut down a module instance */
    scmiSystemSetParameter_t       scmiSystemSetParameter;      /**< Function pointer to set a system parameter */
    scmiSystemGetParameter_t       scmiSystemGetParameter;      /**< Function pointer to get a system parameter */
    scmiSystemCommand_t            scmiSystemCommand;           /**< Function pointer to issue a system command */
    scmiSystemShutdown_t           scmiSystemShutdown;          /**< Function pointer to shutdown a system */
} ScmiSystemFunctions;


/** @} group_system_functions
 */

#if defined (__cplusplus)
}
#endif

#endif /* _SCMI_SYSTEM_FUNCTIONS_H */
