/******************************************************************************\
|* Copyright (c) 2020 by VeriSilicon Holdings Co., Ltd. ("VeriSilicon")       *|
|* All Rights Reserved.                                                       *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of VeriSilicon.  This is proprietary information owned or licensed by      *|
|* VeriSilicon.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of VeriSilicon.                                         *|
|*                                                                            *|
\******************************************************************************/

#ifndef _CAM_DCT_ASSERT_H_
#define _CAM_DCT_ASSERT_H_

/**
 *          Compile time assert. Use e.g. to check the size of certain data
 *           types. As this is evaluated at compile time, it will neither cause
 *           size nor speed overhead, and thus is does not need to be inside
 *           the NDEBUG.
 *
 *****************************************************************************/
/* we need several levels of indirection to make unique enum names working
 * we need unique enum names to be able to use DCT_ASSERT_STATIC more than
 * one time per compilation unit
 */
#define UNIQUE_ENUM_NAME(u)     assert_static__ ## u
#define GET_ENUM_NAME(x)        UNIQUE_ENUM_NAME(x)
#define DCT_ASSERT_STATIC(e)    enum { GET_ENUM_NAME(__LINE__) = 1/(e) }


#endif  // _CAM_DCT_ASSERT_H_
