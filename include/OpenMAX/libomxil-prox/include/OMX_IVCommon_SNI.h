/* -*- c-file-style: "linux" -*- */
/*
 * Copyright (c) 2014 Panasonic Corporation. All rights reserved.
 * Copyright (c) 2016-2018 Socionext Inc., all rights reserved.
 */

#ifndef OMX_IVCommon_SNI_h
#define OMX_IVCommon_SNI_h

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <OMX_IVCommon.h>

typedef enum OMX_PSC_COLOR_FORMATTYPE {
	OMX_COLOR_FormatAYUV8888 = OMX_COLOR_FormatVendorStartUnused + 1,
	OMX_COLOR_FormatRGBA8888L_BTC,
	OMX_COLOR_FormatYUV10_TC_422PK,
	OMX_COLOR_FormatYUV8_TC_422PK,
	OMX_COLOR_FormatIndex8,
	OMX_COLOR_Format16bitARGB3454,
	OMX_COLOR_Format24bitGBR888,
	OMX_COLOR_FormatYUV30_444PK,
	OMX_COLOR_FormatYUV24_444PK,
	OMX_COLOR_FormatYUV20_422PK,
	OMX_COLOR_FormatYUV16_422PK,
} OMX_PSC_COLOR_FORMATTYPE;

/* OSD Scalig mode for VDC */
typedef enum OMX_FILTERTYPE
{
	OMX_ScalerFilterRepeat,
	OMX_ScalerFilter2Tap,
	OMX_ScalerFilter4Tap,
	OMX_ScalerFilter4TapManual,
} OMX_FILTERTYPE;

typedef struct OMX_CONFIG_SCALERFILTERTYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_FILTERTYPE nFilter;
	OMX_S8 nHcoef[64];
	OMX_S8 nVcoef[64];
} OMX_CONFIG_SCALERFILTERTYPE;

/* Premultiplied for VDC */
typedef struct OMX_CONFIG_PREMULTIPLIEDTYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_BOOL bEnablePremultiplied;
} OMX_CONFIG_PREMULTIPLIEDTYPE;

/* PlaneShow for VCC */
typedef enum{
	OMX_Show, /* default */
	OMX_Hide,
} OMX_PLANESHOWTYPE;
	
/* PlaneShow for VCC */
typedef struct OMX_CONFIG_PLANESHOWTYPE
{
	OMX_U32 nSize; 
	OMX_VERSIONTYPE nVersion; 
	OMX_U32 nPortIndex;
	OMX_PLANESHOWTYPE ePlaneShow;
} OMX_CONFIG_PLANESHOWTYPE;

typedef enum{
	OMX_CS_RGB,
	OMX_CS_YUV,
	OMX_CS_RGBCompress,
	OMX_CS_RGBFull,
	OMX_CS_REC601Compress,
	OMX_CS_REC601Full,
	OMX_CS_REC709Compress,
	OMX_CS_REC709CompressHDR,
	OMX_CS_REC709Full,
	OMX_CS_REC709FullHDR,
	OMX_CS_BT2020CLCompress,
	OMX_CS_BT2020CLFull,
	OMX_CS_BT2020CLCompressHDR,
	OMX_CS_BT2020CLFullHDR,
	OMX_CS_BT2020NCLCompress,
	OMX_CS_BT2020NCLFull,
	OMX_CS_BT2020NCLCompressHDR,
	OMX_CS_BT2020NCLFullHDR,

	OMX_CS_BT2020Compress,
	OMX_CS_BT2020Full,
	OMX_CS_BT2020HDR,
} OMX_COLORSPACETYPE;

/* ColorSpace for VEC and VCC */
typedef struct OMX_CONFIG_COLORSPACETYPE
{
	OMX_U32 nSize; 
	OMX_VERSIONTYPE nVersion; 
	OMX_U32 nPortIndex;
	OMX_COLORSPACETYPE eColorSpace;
} OMX_CONFIG_COLORSPACETYPE;

/* ScaleMode for VEC and VCC */
typedef enum{
	OMX_ScaleModeNearest,	/* Point sample */
	OMX_ScaleModeBasic,		/* 2Tap */
	OMX_ScaleModeNormal,	/* 4Tap */
	OMX_ScaleModeFine,		/* 6 or 8Tap */
} OMX_SCALEMODETYPE;

/* LUT */
typedef struct OMX_CONFIG_CLUTTYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_COLOR_FORMATTYPE eColorFormat;
	OMX_U64 nLutAddress;
} OMX_CONFIG_CLUTTYPE;

typedef struct OMX_CONFIG_IMAGEGAMMALUTTYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_BOOL bEnable;
	OMX_U64 nLutAddress;
} OMX_CONFIG_IMAGEGAMMALUTTYPE;

typedef struct OMX_CONFIG_3DCLUTTYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_U64 nLutAddress;
} OMX_CONFIG_3DCLUTTYPE;

typedef struct OMX_CONFIG_GAMMALUTTYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_U64 nLutAddress;
} OMX_CONFIG_GAMMALUTTYPE;



typedef enum{
	OMX_PRE_OFFSET_NONE,
	OMX_PRE_OFFSET_R16G16B16,
	OMX_PRE_OFFSET_R0G128B128,
	OMX_PRE_OFFSET_R16G128B128,
} OMX_MATRIX_PRE_OFFSET;

typedef enum{
	OMX_POST_OFFSET_NONE,
	OMX_POST_OFFSET_R16G16B16,
	OMX_POST_OFFSET_R0G128B128,
	OMX_POST_OFFSET_R16G128B128,
} OMX_MATRIX_POST_OFFSET;

typedef enum{
	OMX_POST_CLIP_NONE,
	OMX_POST_CLIP_R235G235B235,
	OMX_POST_CLIP_R235G240B240,
} OMX_MATRIX_POST_CLIP;

typedef struct OMX_CONFIG_IMAGEMATRIXTYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_BOOL bEnable;
	OMX_MATRIX_PRE_OFFSET ePreOffset;
	OMX_MATRIX_POST_OFFSET ePostOffset;
	OMX_MATRIX_POST_CLIP ePostClip;
	OMX_S32 nCoef11;
	OMX_S32 nCoef12;
	OMX_S32 nCoef13;
	OMX_S32 nCoef21;
	OMX_S32 nCoef22;
	OMX_S32 nCoef23;
	OMX_S32 nCoef31;
	OMX_S32 nCoef32;
	OMX_S32 nCoef33;
} OMX_CONFIG_IMAGEMATRIXTYPE;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
/* File EOF */
