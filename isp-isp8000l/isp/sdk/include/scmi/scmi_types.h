/*******************************************************************************
 * This is an unpublished work, the copyright in which vests in sci-worx GmbH.
 * The information contained herein is the property of sci-worx GmbH and is
 * supplied without liability for errors or omissions. No part may be repro-
 * duced or used except as authorized by contract or other written permission.
 * Copyright(c) sci-worx GmbH, 2007. All rights reserved.
 *******************************************************************************
 * Module    : SCMI Types
 *
 * Hierarchy : SCMI
 *
 * Purpose   : In this file all scmi core types are defined.
 *
 * Creator   : AGt
 *
 ******************************************************************************/


/** @file scmi_types.h
 *  @brief sci-worx Common Media Interface (SCMI) type definitions.
 */

#ifndef __SCMI_TYPES_H__
#define __SCMI_TYPES_H__


#if defined (__cplusplus)
extern "C" {
#endif

#include <ebase/types.h>
#include <cam_device/cam_device_buf_defs.h>
/*******************************************************************************
 * @brief The standard scmi return value type.
 *
 * All scmi functions return a value of this type. Negative values denote an
 * error, positive values a success. For a list of possible standard return
 * values see @ref SCMI_RESULT, for a list of module function specific return values
 * see the respective module's description
 */
typedef int32_t    ScmiReturnType;

/*******************************************************************************
 * @brief The standard scmi return values
 *
 * This enumeration lists the possible standard scmi return values. Note that
 * each module can define its own return values for its module functions.
 * These module specific return values should start at @ref
 * SCMI_RET_MODULE_ERROR_START for error values (descending from there) and at @ref
 * SCMI_RET_MODULE_SUCCESS_START for success values (ascending).
 */
enum SCMI_RESULT
{
    SCMI_RET_SUCCESS                =  0x00,    /**< The operation was successfully completed */
    SCMI_RET_FAILURE                = -0x01,    /**< Generic error */
    SCMI_RET_PENDING                = -0x02,    /**< The operation is ongoing */
    SCMI_RET_INVALID_MODULE_TYPE_ID = -0x03,    /**< The given module type id is invalid */
    SCMI_RET_NOT_SUPPORTED          = -0x04,    /**< The requested function is not supported */
    SCMI_RET_OUT_OF_MEMORY          = -0x05,    /**< Insufficient memory */
    SCMI_RET_TIMEOUT                = -0x06,    /**< Something timed out */
    SCMI_RET_BUSY                   = -0x07,    /**< The requested operation can't be fulfilled because the resource is busy */
    SCMI_RET_INVALID_PARM_1         = -0x08,    /**< First parameter is invalid */
    SCMI_RET_INVALID_PARM_2         = -0x09,    /**< Second parameter is invalid */
    SCMI_RET_INVALID_PARM_3         = -0x0A,    /**< Third parameter is invalid */
    SCMI_RET_INVALID_PARM_4         = -0x0B,    /**< Fourth parameter is invalid */
    SCMI_RET_INVALID_PARM_5         = -0x0C,    /**< Fifth parameter is invalid */
    SCMI_RET_INVALID_PARM_6         = -0x0D,    /**< Sixth parameter is invalid */
    SCMI_RET_CANCELLED              = -0x0E,    /**< The operation was cancelled */
    SCMI_RET_NO_DATA                = -0x0F,    /**< Insufficient data for the operation to complete */
    SCMI_RET_FULL                   = -0x10,    /**< Something is full */
    SCMI_RET_OVERFLOW               = -0x11,    /**< Something was overflowing */
    SCMI_RET_EMPTY                  = -0x12,    /**< Something is empty */
    SCMI_RET_UNDERFLOW              = -0x13,    /**< Something was underflowing */
    SCMI_RET_NOT_FOUND              = -0x14,    /**< Unsuccessful find operation */
    SCMI_RET_INVALID_HANDLE         = -0x15,    /**< The given handle is invalid */
    SCMI_RET_INVALID_CONFIG         = -0x16,    /**< Configuration is not allowed */
    SCMI_RET_NO_HARDWARE            = -0x17,    /**< Hardware not present */
    SCMI_RET_WRONG_STATE            = -0x18,    /**< Module is in wrong state */
    SCMI_RET_WRITE_ERROR            = -0x19,    /**< Write error */
    SCMI_RET_READ_ERROR             = -0x1A,    /**< Reads error */
    SCMI_RET_INVALID_ADDRESS        = -0x1B,    /**< Invalid address */
    SCMI_RET_ONLY_ONE_INSTANCE      = -0x1C,    /**< Only one instance is allowed */
    SCMI_RET_NOT_AVAILABLE          = -0x1D,    /**< Something is not available */
    SCMI_RET_INVALID_STREAM         = -0x1E,    /**< Stream could not be recognized as a valid stream of the specified standard / feature set */
    SCMI_RET_MODULE_ERROR_START     = -0x100,   /**< Start of module specific error result codes */
    SCMI_RET_MODULE_SUCCESS_START   =  0x100    /**< Start of module specific success result codes  */
};


/*******************************************************************************
 * @brief A unique ID for each type of module
 *
 * The scmiSystemCreateModule() function takes this type as a parameter
 * to determine, which kind of module it should instantiate (e.g. "MPEG-4",
 * "MP3"). Each SCMI module has a module type ID defined by each SCMI system separetely.
 * Note that you can instantiate more than one module of the same ID (if your system has
 * the appropriate resources).
 */
typedef int32_t ScmiModuleTypeId;


/*******************************************************************************
 * @brief An ID specifying a module command
 *
 * With the generic scmiModuleCommand() function each module can define its
 * own proprietary commands. These commands are differentiated by their
 * SCMI_COMMAND_ID ID. Note that a command ID is only valid within the context
 * of a specific module.
 */
typedef int32_t ScmiCommandId;

/*******************************************************************************
 * @brief An ID specifying a module or system event
 *
 * An SCMI system uses a callback function to signal events,
 * scmiCbEvent(). To differentiate between different events, a
 * SCMI_EVENT_ID parameter is used. Note that there are events common for all
 * modules as well as events proprietary to each module.
 */
typedef int32_t ScmiEventId;


/*******************************************************************************
 * @brief An ID specifying a module request
 *
 * An SCMI system uses a callback funtion to request resources,
 * scmiCbRequest(). To differentiate between different requests, a
 * SCMI_REQUEST_ID parameter is used. Note that there are requests common for all
 * modules as well as requets proprietary to each module.
 */
typedef int32_t ScmiRequestId;


/*******************************************************************************
 * @brief An ID specifying a module's parameter set
 *
 * This type is used by the functions scmiModuleSetParameters()
 * and scmiModuleGetParameters()
 */
typedef int32_t ScmiParameterSetId;


/*******************************************************************************
 * @brief Generic parameter set
 *
 * This structure is used to pass parameters in a generic way.
 * Each module defines its own parameter sets with its own parameter set IDs, that
 * are only valid in the context of the respective module.
 * (see scmiSystemCreateModule(), scmiModuleCommand(), @ref scmiCbEvent)
 */
typedef struct _ScmiParameterSet
{
    void*       p_payload;      /**< Pointer to the parameter set structure */
    uint32_t    payload_size;   /**< Size of the parameter set in bytes */
} ScmiParameterSet;


#if defined (__cplusplus)
}
#endif

#endif /* __SCMI_TYPES_H__ */
