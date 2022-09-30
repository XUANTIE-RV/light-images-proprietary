/*******************************************************************************
 * This is an unpublished work, the copyright in which vests in sci-worx GmbH.
 * The information contained herein is the property of sci-worx GmbH and is
 * supplied without liability for errors or omissions. No part may be repro-
 * duced or used except as authorized by contract or other written permission.
 * Copyright(c) sci-worx GmbH, 2007. All rights reserved.
 *******************************************************************************
 * Module    : SCMI Module Type IDs
 *
 * Hierarchy : SCMI
 *
 * Purpose   : This file defines all scmi module type IDs
 *
 * Creator   : AGt
 *
 ******************************************************************************/


/** @file scmi_module_type_ids.h
 *  @brief sci-worx Common Media Interface (SCMI) module type IDs
 */

#ifndef _SCMI_MODULE_IDS_H
#define _SCMI_MODULE_IDS_H


#if defined (__cplusplus)
extern "C" {
#endif

/*******************************************************************************
 * @brief Enumeration of module attributes
 *
 * Each @ref SCMI_MODULE_TYPE_ID is a bit combination of a module type number
 * and optional some module type attributes. These module type attributes
 * are defined with this enumeration.
 */
enum SCMI_MODULE_ATTRIBUTE
{
    SCMI_MODULE_ATTRIBUTE_ENCODER   = 0x10000,      /**< Encoder Attribute  */
    SCMI_MODULE_ATTRIBUTE_DECODER   = 0x08000,      /**< Decoder Attribute */
    SCMI_MODULE_ATTRIBUTE_AUDIO     = 0x04000,      /**< Audio Attribute */
    SCMI_MODULE_ATTRIBUTE_VIDEO     = 0x02000,      /**< Video Attribute */
    SCMI_MODULE_ATTRIBUTE_IMAGE     = 0x01000       /**< Image Attribute */
};


/*******************************************************************************
 * @brief Enumeration of module type IDs
 *
 * To instantiate a specific media module the @ref scmiSystemCreateModule()
 * function expects a module type ID parameter of this type. This parameter
 * specifies exactly which kind of module (e.g. MPEG-4 video decoder, MP3 audio
 * encoder) should be instantiated.
 */
enum SCMI_MODULE_TYPE_ID
{
    /* video codecs */
    SCMI_MODULE_TYPE_ID_MPEG2_DECODER   = 0x000 | SCMI_MODULE_ATTRIBUTE_DECODER | SCMI_MODULE_ATTRIBUTE_VIDEO,  /**< MPEG2 decoder */
    SCMI_MODULE_TYPE_ID_MPEG2_ENCODER   = 0x000 | SCMI_MODULE_ATTRIBUTE_ENCODER | SCMI_MODULE_ATTRIBUTE_VIDEO,  /**< MPEG2 encoder */
    SCMI_MODULE_TYPE_ID_MPEG4_DECODER   = 0x001 | SCMI_MODULE_ATTRIBUTE_DECODER | SCMI_MODULE_ATTRIBUTE_VIDEO,  /**< MPEG4 decoder */
    SCMI_MODULE_TYPE_ID_MPEG4_ENCODER   = 0x001 | SCMI_MODULE_ATTRIBUTE_ENCODER | SCMI_MODULE_ATTRIBUTE_VIDEO,  /**< MPEG4 encoder     */
    SCMI_MODULE_TYPE_ID_H264_DECODER    = 0x002 | SCMI_MODULE_ATTRIBUTE_DECODER | SCMI_MODULE_ATTRIBUTE_VIDEO,  /**< H.264 decoder */
    SCMI_MODULE_TYPE_ID_H264_ENCODER    = 0x002 | SCMI_MODULE_ATTRIBUTE_ENCODER | SCMI_MODULE_ATTRIBUTE_VIDEO,  /**< H.264 encoder */
    SCMI_MODULE_TYPE_ID_VC1_DECODER     = 0x003 | SCMI_MODULE_ATTRIBUTE_DECODER | SCMI_MODULE_ATTRIBUTE_VIDEO,  /**< VC-1 decoder */
    SCMI_MODULE_TYPE_ID_VC1_ENCODER     = 0x003 | SCMI_MODULE_ATTRIBUTE_ENCODER | SCMI_MODULE_ATTRIBUTE_VIDEO,  /**< VC-1 decoder */

    /* audio codecs */
    SCMI_MODULE_TYPE_ID_AAC_DECODER     = 0x100 | SCMI_MODULE_ATTRIBUTE_DECODER | SCMI_MODULE_ATTRIBUTE_AUDIO,  /**< Aac decoder   */
    SCMI_MODULE_TYPE_ID_AAC_ENCODER     = 0x100 | SCMI_MODULE_ATTRIBUTE_ENCODER | SCMI_MODULE_ATTRIBUTE_AUDIO,  /**< Aac encoder   */
    SCMI_MODULE_TYPE_ID_MP3_DECODER     = 0x101 | SCMI_MODULE_ATTRIBUTE_DECODER | SCMI_MODULE_ATTRIBUTE_AUDIO,  /**< Mp3 decoder   */
    SCMI_MODULE_TYPE_ID_MP3_ENCODER     = 0x101 | SCMI_MODULE_ATTRIBUTE_ENCODER | SCMI_MODULE_ATTRIBUTE_AUDIO,  /**< Mp3 encoder   */
    SCMI_MODULE_TYPE_ID_AMR_DECODER     = 0x102 | SCMI_MODULE_ATTRIBUTE_DECODER | SCMI_MODULE_ATTRIBUTE_AUDIO,  /**< Amr decoder   */
    SCMI_MODULE_TYPE_ID_AMR_ENCODER     = 0x102 | SCMI_MODULE_ATTRIBUTE_ENCODER | SCMI_MODULE_ATTRIBUTE_AUDIO,  /**< Amr encoder   */

    /* still image codecs */
    SCMI_MODULE_TYPE_ID_JPEG_DECODER    = 0x200 | SCMI_MODULE_ATTRIBUTE_DECODER | SCMI_MODULE_ATTRIBUTE_IMAGE,    /**< JPEG decoder */
    SCMI_MODULE_TYPE_ID_JPEG_ENCODER    = 0x200 | SCMI_MODULE_ATTRIBUTE_ENCODER | SCMI_MODULE_ATTRIBUTE_IMAGE,    /**< JPEG encoder */
    SCMI_MODULE_TYPE_ID_NLC_DECODER     = 0x201 | SCMI_MODULE_ATTRIBUTE_DECODER | SCMI_MODULE_ATTRIBUTE_IMAGE,    /**< NLC decoder */
    SCMI_MODULE_TYPE_ID_NLC_ENCODER     = 0x201 | SCMI_MODULE_ATTRIBUTE_ENCODER | SCMI_MODULE_ATTRIBUTE_IMAGE,    /**< NLC encoder */

    /* system */
    SCMI_MODULE_TYPE_ID_NONE            = 0xFFF /**< no module. Used e.g. to report system errors. */
};


#if defined (__cplusplus)
}
#endif

#endif	/* _SCMI_MODULE_IDS_H */
