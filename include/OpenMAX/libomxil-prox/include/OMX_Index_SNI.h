/* -*- c-file-style: "linux" -*- */
/*
 * Copyright (c) 2014 Panasonic Corporation. All rights reserved.
 * Copyright (c) 2016-2017 Socionext Inc., all rights reserved.
 */

#ifndef OMX_Index_PSC_h
#define OMX_Index_PSC_h

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* Each OMX header must include all required header files to allow the
 *  header to compile without errors.  The includes below are required
 *  for this header file to compile successfully 
 */
#include <OMX_Types.h>
#include <OMX_Index.h>

typedef enum OMX_PSC_INDEXTYPE {
	OMX_IndexParamVideoWindow = OMX_IndexVendorStartUnused + 1,              /**< reference: OMX_PARAM_WINDOWTYPE */
	OMX_IndexConfigVideoMute,               /**< reference: OMX_CONFIG_MUTETYPE */
	OMX_IndexConfigCommonMute,              /**< reference: OMX_CONFIG_MUTETYPE */
	OMX_IndexConfigCommonForceMute,         /**< reference: OMX_CONFIG_MUTETYPE */
	OMX_IndexConfigCommonScalerFilter,      /**< reference: OMX_CONFIG_SCALERFILTERTYPE */
	OMX_IndexConfigVideoSynchronize,        /**< reference: OMX_CONFIG_SYNCHRONIZETYPE */
	OMX_IndexConfigCommonColorSpace,        /**< reference: OMX_CONFIG_COLORSPACETYPE */
	OMX_IndexConfigCommonPremultiplied,     /**< reference: OMX_CONFIG_PREMULTIPLIEDTYPE */
	OMX_IndexConfigCommonCLUT,              /**< reference: OMX_CONFIG_CLUTTYPE */
	OMX_IndexConfigCommon3DCLUT,            /**< reference: OMX_CONFIG_3DCLUTTYPE */
	OMX_IndexConfigImageMatrix,             /**< reference: OMX_CONFIG_IMAGEMATRIXTYPE */
	OMX_IndexConfigCommonGammaLUT,          /**< reference: OMX_CONFIG_GAMMALUTTYPE */
	OMX_IndexConfigImageGammaLUT,           /**< reference: OMX_CONFIG_IMAGEGAMMALUTTYPE */

	/* for VDC */
	OMX_IndexConfigVideoCurrentPTS,         /**< reference: OMX_CONFIG_CURRENTPTSTYPE */
	OMX_IndexConfigVideoPause,              /**< reference: OMX_CONFIG_VIDEOPAUSETYPE */

	OMX_IndexConfigVideoConfigLinkMode,      /**< reference: OMX_CONFIG_CONFIGLINKTYPE */

	OMX_IndexConfigCommonAdvancedBacklight,   /**< reference: OMX_CONFIG_ADVANCEDBACKLIGHTTYPE */
	OMX_IndexConfigPictureQualityControl,     /**< reference: OMX_CONFIG_PICTUREQUALITYCONTROLTYPE */

} OMX_PSC_INDEXTYPE;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
/* File EOF */
