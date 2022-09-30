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

/*!
 *  @file        utl_fixfloat.h
 *  @version     1.0
 *  @author      Neugebauer
 *  @brief       Floatingpoint to Fixpoint and vice versa conversion
 *               routines.
 */


#ifndef __UTL_FIXFLOAT_H__
#define __UTL_FIXFLOAT_H__

/*****************************************************************************
 * Prototypes
 *****************************************************************************/

uint32_t UtlFloatToFix_U0107( float fFloat );
float  UtlFixToFloat_U0107( uint32_t ulFix );

uint32_t UtlFloatToFix_U0208( float fFloat );
float  UtlFixToFloat_U0208( uint32_t ulFix );

uint32_t UtlFloatToFix_U0408( float fFloat );
float  UtlFixToFloat_U0408( uint32_t ulFix );

uint32_t UtlFloatToFix_U0800( float fFloat );
float  UtlFixToFloat_U0800( uint32_t ulFix );

uint32_t UtlFloatToFix_U1000( float fFloat );
float  UtlFixToFloat_U1000( uint32_t ulFix );

uint32_t UtlFloatToFix_U1200( float fFloat );
float  UtlFixToFloat_U1200( uint32_t ulFix );

uint32_t UtlFloatToFix_U0010( float fFloat );
float  UtlFixToFloat_U0010( uint32_t ulFix );

uint32_t UtlFloatToFix_S0207( float fFloat );
float  UtlFixToFloat_S0207( uint32_t ulFix );

uint32_t UtlFloatToFix_S0307( float fFloat );
float  UtlFixToFloat_S0307( uint32_t ulFix );

uint32_t UtlFloatToFix_S0407( float fFloat );
float  UtlFixToFloat_S0407( uint32_t ulFix );

uint32_t UtlFloatToFix_S0504( float fFloat );
float  UtlFixToFloat_S0504( uint32_t ulFix );

uint32_t UtlFloatToFix_S0808( float fFloat );
float  UtlFixToFloat_S0808( uint32_t ulFix );

uint32_t UtlFloatToFix_S0800( float fFloat );
float  UtlFixToFloat_S0800( uint32_t ulFix );

uint32_t UtlFloatToFix_S0900( float fFloat );
float  UtlFixToFloat_S0900( uint32_t ulFix );

uint32_t UtlFloatToFix_S1200( float fFloat );
float  UtlFixToFloat_S1200( uint32_t ulFix );

uint32_t UtlFloatToFix_S0109( float fFloat );
float UtlFixToFloat_S0109( uint32_t ulFix );

uint32_t UtlFloatToFix_S0408( float fFloat );
float UtlFixToFloat_S0408( uint32_t ulFix );

uint32_t UtlFloatToFix_S0108( float fFloat );
float UtlFixToFloat_S0108( uint32_t ulFix );

uint32_t UtlFloatToFix_S0110( float fFloat );
float UtlFixToFloat_S0110( uint32_t ulFix );
uint32_t UtlValueMap( uint32_t value, uint32_t sLower, uint32_t sUpper, uint32_t dLower, uint32_t dUpper);

#endif /* __UTL_FIXfloat_H__ */

