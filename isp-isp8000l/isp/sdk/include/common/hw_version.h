/******************************************************************************
 *
 * Copyright 2010, Dream Chip Technologies GmbH. All rights reserved.
 * No part of this work may be reproduced, modified, distributed, transmitted,
 * transcribed, or translated into any language or computer format, in any form
 * or by any means without written permission of:
 * Dream Chip Technologies GmbH, Steinriede 10, 30827 Garbsen / Berenbostel,
 * Germany
 *
 *****************************************************************************/
/**
 * @file hw_version.h
 *
 * @brief
 *   This header files contains hardware module version define informations.
 *
 *****************************************************************************/
#ifndef __HW_VERSION_H__
#define __HW_VERSION_H__


/*****************************************************************************/
/**
 * @brief   HDR module version type
 */
/*****************************************************************************/
#define VSI_ISP_HDR_NOTSUPPORT  0   //!< Not support HDR
#define VSI_ISP_HDR_V10         1   //!< Version V10
#define VSI_ISP_HDR_V11         2   //!< Version V11
#define VSI_ISP_HDR_V12         3   //!< Version V12
#define VSI_ISP_HDR_V13         4   //!< Version V13




/////////////////////////////////////////
//add Version defines
/////////////////////////////////////////
#ifdef ISP8000NANO_V1801

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_NOTSUPPORT

#elif defined ISP8000NANO_V1802

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V11

#elif defined ISP8000_V1901

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V11

#elif defined ISP8000L_V1901

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_NOTSUPPORT

#elif defined ISP8000L_V1902

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V11

#elif defined ISP8000L_V1903

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V12

#elif defined ISP8000L_V1905

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V12

#elif defined ISP8000L_V2001

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V12

#elif defined ISP8000L_V2002

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V12

#elif defined ISP8000_V2003

#define VSI_ISP_HDR_VERSION VSI_ISP_HDR_V13

#elif defined ISP8000L_V2007

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V12

#elif defined ISP8000L_V2008

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_V12

#elif defined ISP8000NANO_V2012

#define VSI_ISP_HDR_VERSION		VSI_ISP_HDR_NOTSUPPORT

#endif





#endif /* __HW_VERSION_H__ */

