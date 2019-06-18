/* -*- c-file-style: "linux" -*- */
/*
 * Copyright (c) 2014 Panasonic Corporation. All rights reserved.
 * Copyright (c) 2016-2017 Socionext Inc., all rights reserved.
 */

#ifndef OMX_Video_PSC_h
#define OMX_Video_PSC_h

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include <stdint.h>
#include <OMX_Video.h>
#include <OMX_Types.h>

#include <OMX_IVCommon_SNI.h>

/** 
 * VDC Display mode Params 
 */
typedef enum{
	OMX_OutputMode2D,
	OMX_OutputModeMAXNUM
} OMX_OUTPUTMODETYPE;

typedef enum{
	OMX_OutputDeviceVBYONE,
	OMX_OutputDeviceLVDS,
	OMX_OutputDeviceMAXNUM
} OMX_OUTPUTDEVICETYPE;

typedef enum{
	OMX_OutputFormatRGB,
	OMX_OutputFormatYUV422,
	OMX_OutputFormatYUV444,
	OMX_OutputFormatARGB,
} OMX_OUTPUTFORMATTYPE;

typedef struct OMX_OUTPUTADVANCEDTYPE {
    OMX_U32 nFrameWidthAll;
    OMX_U32 nFrameHeightAll;
} OMX_OUTPUTADVANCEDTYPE;

typedef enum {
	OMX_PANEL_PolarityPositive,
	OMX_PANEL_PolarityNegative,
	OMX_PANEL_PolarityMAXNUM,
} OMX_PANEL_POLARITYTYPE;

typedef enum {
	OMX_PANEL_ClockTypeInternal,
	OMX_PANEL_ClockTypeExternal,
	OMX_PANEL_ClockTypeFreeRun,
	OMX_PANEL_ClockTypeExternalAnalog,
	OMX_PANEL_ClockTypeMAXNUM
} OMX_PANEL_CLOCKTYPE;

typedef enum {
	OMX_PANEL_LvdsInputSelectMode0,
	OMX_PANEL_LvdsInputSelectMode1,
	OMX_PANEL_LvdsInputSelectMode2,
	OMX_PANEL_LvdsInputSelectMode3,
} OMX_PANEL_LVDSINPUTSELECTMODETYPE;

typedef enum {
	OMX_PANEL_LvdsSignalAssignVesa8bit,
	OMX_PANEL_LvdsSignalAssignVesa10bit,
	OMX_PANEL_LvdsSignalAssignJeida8bit,
	OMX_PANEL_LvdsSignalAssignJeida10bit,
	OMX_PANEL_LvdsSignalAssignJeidaVesa10bit
} OMX_PANEL_LVDSSIGNALASSIGNTYPE;

typedef enum {
	OMX_PANEL_LaneSwitchOff,
	OMX_PANEL_LaneSwitchOn,
} OMX_PANEL_LANESWITCHTYPE;

typedef enum {
	OMX_PANEL_LvdsSrsSig200mV,
	OMX_PANEL_LvdsSrsSig250mV,
	OMX_PANEL_LvdsSrsSig300mV,
	OMX_PANEL_LvdsSrsSig350mV,
	OMX_PANEL_LvdsSrsSig400mV,
	OMX_PANEL_LvdsSrsSig450mV,
	OMX_PANEL_LvdsSrsSig500mV,
	OMX_PANEL_LvdsSrsSig550mV,
} OMX_PANEL_LVDSSRSSIGTYPE;

typedef enum {
	OMX_PANEL_EmLevel0mV,
	OMX_PANEL_EmLevel150mV,
	OMX_PANEL_EmLevel300mV,
	OMX_PANEL_EmLevel450mV,
} OMX_PANEL_EMLEVELTYPE;

typedef enum {
	OMX_PANEL_EmTimeLevel0,
	OMX_PANEL_EmTimeLevel1,
	OMX_PANEL_EmTimeLevel2,
	OMX_PANEL_EmTimeLevel3,
	OMX_PANEL_EmTimeLevel4,
	OMX_PANEL_EmTimeLevel5,
	OMX_PANEL_EmTimeLevel6,
	OMX_PANEL_EmTimeLevel7,
} OMX_PANEL_EMTIMELEVELTYPE;

typedef enum {
	OMX_PANEL_VboSrsSig200mV,
	OMX_PANEL_VboSrsSig250mV,
	OMX_PANEL_VboSrsSig300mV,
	OMX_PANEL_VboSrsSig350mV,
	OMX_PANEL_VboSrsSig400mV,
	OMX_PANEL_VboSrsSig450mV,
	OMX_PANEL_VboSrsSig500mV,
} OMX_PANEL_VBOSRSSIGTYPE;

typedef enum {
	OMX_SIGNAL_PolarityPositive,
	OMX_SIGNAL_PolarityNegative,
	OMX_SIGNAL_PolarityMAXNUM,
} OMX_SIGNAL_POLARITYTYPE;

typedef struct OMX_OUTPUTSIGNALTYPE
{
    OMX_U32      nPixelClock;
    OMX_BOOL     ePixelClockAdjustedBy1000Over1001;
    OMX_U32      nHorizontalTotal;
    OMX_U32      nHorizontalSync;
    OMX_U32      nHorizontalStart;
    OMX_U32      nHorizontalActive;
    OMX_U32      nVerticalTotal;
    OMX_U32      nVerticalStart;
    OMX_U32      nVerticalSync;
    OMX_U32      nVerticalActive;
    OMX_U32      nVerticalProtectMaximum;
    OMX_U32      nVerticalProtectMinimum;
    OMX_SIGNAL_POLARITYTYPE  eHorizontalSyncPolarity;
    OMX_SIGNAL_POLARITYTYPE  eVerticalSyncPolarity;
} OMX_OUTPUTSIGNALTYPE;

typedef enum
{
    OMX_PANEL_VboColor8bit,
    OMX_PANEL_VboColor10bit
} OMX_PANEL_VBOCOLORTYPE;

typedef struct OMX_OUTPUTPANELTYPE
{
    OMX_PANEL_CLOCKTYPE               eOutputClock;
    OMX_BOOL                          bDoublerSwitch;
    OMX_U32                           nHorizontalDivision;
    OMX_BOOL                          bHorizontalReverse;
    OMX_BOOL                          bVerticalReverse;
    OMX_U32                           nSsc;

    OMX_PANEL_CLOCKTYPE               eOutputClockSub;
    OMX_BOOL                          bVerticalReverseSub;
    OMX_U32                           nSscSub;

    OMX_PANEL_LVDSINPUTSELECTMODETYPE eLvdsPinAssignCommonInputSelect;
    OMX_PANEL_LVDSSIGNALASSIGNTYPE    eLvdsCommonSignalAssign;
    OMX_PANEL_LANESWITCHTYPE          eLvdsLaneSwitch[12];
    OMX_BOOL                          bLvdsPinAssignDataLaneSwap;
    OMX_BOOL                          bLvdsPinAssignClockLaneSwap;
    OMX_PANEL_POLARITYTYPE            eLvdsClockPolarity;
    OMX_PANEL_POLARITYTYPE            eLvdsLanePolarity;
    OMX_PANEL_LVDSSRSSIGTYPE          eLvdsLaneSrsSig[12];
    OMX_PANEL_EMLEVELTYPE             eLvdsLaneEmLevel[12];
    OMX_PANEL_EMTIMELEVELTYPE         eLvdsLaneCommonEmTimeLevel;
    OMX_S32                           nLvdsLaneSkew[12];

    OMX_U32                           nVboLaneSwap[8];
    OMX_PANEL_LANESWITCHTYPE          eVboLaneSwitch[8];
    OMX_U32                           nVboLaneSubSwap[4];
    OMX_PANEL_LANESWITCHTYPE          eVboLaneSubSwitch[4];
    OMX_PANEL_VBOSRSSIGTYPE           eVboLaneSrsSig[8];
    OMX_PANEL_VBOSRSSIGTYPE           eVboLaneSubSrsSig[4];

    OMX_PANEL_EMLEVELTYPE             eVboLaneEmLevel[8];
    OMX_PANEL_EMLEVELTYPE             eVboLaneSubEmLevel[4];
    OMX_PANEL_EMTIMELEVELTYPE         eVboLaneCommonEmTimeLevel;

    OMX_PANEL_EMTIMELEVELTYPE         eVboLaneSubCommonEmTimeLevel;

    OMX_PANEL_POLARITYTYPE            eVboLanePolarity[8];
    OMX_PANEL_POLARITYTYPE            eVboLaneSubPolarity[4];
    OMX_PANEL_VBOCOLORTYPE            eVboColorDepth;
    OMX_PANEL_VBOCOLORTYPE            eVboColorDepthSub;
} OMX_OUTPUTPANELTYPE;


typedef enum
{
  OMX_CompositePatternPortNone=0,
  OMX_CompositePatternPort1Video=0x1,
  OMX_CompositePatternPort2Video=0x2,
  OMX_CompositePatternPort3ImagePrePQ=0x4,
  OMX_CompositePatternPort3ImagePostPQ=0x8,
  OMX_CompositePatternPort4ImagePrePQ=0x10,
  OMX_CompositePatternPort4ImagePostPQ=0x20,
} OMX_COMPOSITEPATTERNTYPE;

typedef struct OMX_NATIVE_DEVICETYPE_VDC {

	OMX_OUTPUTDEVICETYPE eOutputDevice;
	OMX_OUTPUTMODETYPE eOutputMode;
	OMX_OUTPUTFORMATTYPE eOutputFormat;
	OMX_COMPOSITEPATTERNTYPE nCompositePattern;
	OMX_OUTPUTSIGNALTYPE eOutputSignal;

	OMX_OUTPUTDEVICETYPE eOutputDeviceSub;
	OMX_OUTPUTMODETYPE eOutputModeSub;
	OMX_OUTPUTFORMATTYPE eOutputFormatSub;
	OMX_COMPOSITEPATTERNTYPE nCompositePatternSub;
	OMX_OUTPUTSIGNALTYPE eOutputSignalSub;

	OMX_OUTPUTPANELTYPE eOutputPanel;
} OMX_NATIVE_DEVICETYPE_VDC;

typedef enum{
	OMX_MuteDisable,
	OMX_MuteBlack,
	OMX_MuteColored
} OMX_MUTETYPE;

/** 
 * VDC Mute configs
 *
 * STRUCT MEMBERS:
 *  nSize         : Size of the structure in bytes
 *  nVersion      : OMX specification version information
 *  nPortIndex    : Port that this structure applies to
 *  eEnableMute   : mute disable / black mute / color mute
 *  nMuteRGBColor : mute color (0x00GGBBRR) in eEnableMute is OMX_MuteColored
 */
typedef struct OMX_CONFIG_MUTETYPE {
	OMX_U32 nSize; 
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_MUTETYPE eEnableMute;
	OMX_U32  nMuteRGBColor;
} OMX_CONFIG_MUTETYPE;

/**
 * VDC ADVANCEDBACKLIGHT configs
 *
 * STRUCT MEMBERS:
 *  nSize      : Size of the structure in bytes
 *  nVersion   : OMX specification version information
 *  nPortIndex : Port that this structure applies to
 */
typedef enum{
	OMX_PANEL_PhaseVsync,
	OMX_PANEL_PhaseFreerun,
	OMX_PANEL_PhaseMAXNUM,
} OMX_PANEL_PHASETYPE;

typedef enum{
	OMX_PWM_Reset1Vsync,
	OMX_PWM_Reset2Vsync,
	OMX_PWM_Reset4Vsync,
	OMX_PWM_Reset8Vsync,
	OMX_PWM_ResetFreerun,
	OMX_PWM_ResetMAXNUM,
} OMX_PWM_RESETTYPE;

typedef enum {
	OMX_PWM_PolarityPositive,
	OMX_PWM_PolarityNegative,
	OMX_PWM_PolarityMAXNUM,
} OMX_PWM_POLARITYTYPE;


typedef struct OMX_CONFIG_ADVANCEDBACKLIGHTTYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;

	OMX_PANEL_POLARITYTYPE  ePwmPolarity;
	OMX_U32 nPwmDuty;
	OMX_U32 xPwmFrequency;
	OMX_U32 xPwmOffset;
	OMX_PANEL_PHASETYPE ePwmPhase;

	OMX_PWM_POLARITYTYPE ePwmAPolarity;
	OMX_PWM_RESETTYPE ePwmAReset;
	OMX_U32 nPwmAFrequencyHorizontal;
	OMX_U32 nPwmAFrequencyVertical;
	OMX_U32 nPwmADelayHorizontal;
	OMX_U32 nPwmADelayVertical;
	OMX_U32 nPwmADutyHorizontal;
	OMX_U32 nPwmADutyVertical;
	OMX_BOOL bPwmACmaskOn;

	OMX_PWM_POLARITYTYPE ePwmBPolarity;
	OMX_PWM_RESETTYPE ePwmBReset;
	OMX_U32 nPwmBFrequencyVertical;
	OMX_U32 nPwmBFrequencyHorizontal;
	OMX_U32 nPwmBDutyHorizontal;
	OMX_U32 nPwmBDutyVertical;
	OMX_U32 nPwmBDelayHorizontal;
	OMX_U32 nPwmBDelayVertical;
	OMX_BOOL bPwmBCmaskOn;

	OMX_PWM_POLARITYTYPE ePwmCPolarity;
	OMX_PWM_RESETTYPE ePwmCReset;
	OMX_U32 nPwmCFrequencyVertical;
	OMX_U32 nPwmCFrequencyHorizontal;
	OMX_U32 nPwmCDutyHorizontal;
	OMX_U32 nPwmCDutyVertical;
	OMX_U32 nPwmCDelayHorizontal;
	OMX_U32 nPwmCDelayVertical;

} OMX_CONFIG_ADVANCEDBACKLIGHTTYPE;


typedef struct OMX_CONFIG_PICTUREQUALITYCONTROLTYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;

	OMX_BOOL bEnable;
	OMX_U32  nContrastRed;
	OMX_U32  nContrastGreen;
	OMX_U32  nContrastBlue;
	OMX_U32  nBrightnessRed;
	OMX_U32  nBrightnessGreen;
	OMX_U32  nBrightnessBlue;
	OMX_U32  nContrastY;
	OMX_U32  nBrightnessY;
	OMX_U32  nOffsetY;
	OMX_U32  nOffsetU;
	OMX_U32  nOffsetV;
	OMX_U32  nSaturationU;
	OMX_U32  nSaturationV;
} OMX_CONFIG_PICTUREQUALITYCONTROLTYPE;

/* OSD Composite Mode for VEC */
typedef enum OMX_COMPOSITETYPE
{
	OMX_CompositeOSDAfterVideoProcessing,
	OMX_CompositeOSDBeforeVideoProcessing,
	OMX_CompositeOSDMax = 0x7FFFFFFF
} OMX_COMPOSITETYPE;

/* Video synchronization control for VDC */
typedef enum OMX_SYNCHROREFTYPE
{
	OMX_SynchroRefSTC,
	OMX_SynchroRefSTCDelay,
	// OMX_SynchroRefAudio,
	OMX_SynchroRefMax = 0x7FFFFFFF
} OMX_SYNCHROREFTYPE;

/* Video synchronization control for VDC */
typedef enum OMX_ASYNCHROCTRLTYPE
{
	OMX_AsynchroCtrlByVsync,
	OMX_AsynchroCtrlByFrame,
	OMX_AsynchroCtrlMax = 0x7FFFFFFF
} OMX_ASYNCHROCTRLTYPE;

typedef struct OMX_CONFIG_SYNCHRONIZETYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_BOOL bEnableSynchro;
	OMX_ASYNCHROCTRLTYPE eAsynchroCtrl;
	OMX_SYNCHROREFTYPE eSynchroRef;
	OMX_U32 nLeadThreshold;
	OMX_U32 nLagThreshold;
} OMX_CONFIG_SYNCHRONIZETYPE;

/* Current PTS for VDC */
typedef struct OMX_CONFIG_CURRENTPTSTYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_S64 pts;
	OMX_S64 stc;
} OMX_CONFIG_CURRENTPTSTYPE;

/* Video Pause for VDC */
typedef struct OMX_CONFIG_VIDEOPAUSETYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_BOOL bEnablePause;
	OMX_U32 nFlags; /* reserved */
} OMX_CONFIG_VIDEOPAUSETYPE;

/* tentative define from here for VDEC */
typedef struct {
	uint32_t fm_y_addr;            /** Frame address of luminance components */
	uint32_t fm_c_addr;            /** Frame address of chroma components */
} VDEC_FM_ADDR;

typedef enum {
	OMX_PSC_COLOR_CONV_NONE,
	OMX_PSC_COLOR_CONV_YUV420PLANAR,
	OMX_PSC_COLOR_CONV_YUV420SEMI_PLANAR,
	OMX_PSC_COLOR_CONV_RGB565,
	OMX_PSC_COLOR_CONV_ARGB8888,
	OMX_PSC_COLOR_CONV_YUV420_88L,
	OMX_PSC_COLOR_CONV_YUV420_1010L,
	OMX_PSC_COLOR_CONV_YUV420_88L_MPEG1,
	OMX_PSC_COLOR_CONV_YUV422_88L,
	OMX_PSC_COLOR_CONV_YUV444_816L
} OMX_PSC_COLOR_CONV_MODE;

typedef struct{
	OMX_U32 *phy_addr;
	OMX_U32 *log_addr;
} OMX_MEMADDR;

/* definition imported from OMX_IVCommon.h ver1.2.0 */

#if !defined(OMX_InterlaceFrameProgressive)
#define OMX_InterlaceFrameProgressive                   0x00000001
#define OMX_InterlaceInterleaveFrameTopFieldFirst       0x00000002
#define OMX_InterlaceInterleaveFrameBottomFieldFirst    0x00000004
#define OMX_InterlaceFrameTopFieldFirst                 0x00000008
#define OMX_InterlaceFrameBottomFieldFirst              0x00000010
#define OMX_InterlaceInterleaveFieldTop                 0x00000020
#define OMX_InterlaceInterleaveFieldBottom              0x00000040
#define OMX_InterlaceFrameTopField                      0x00000100
#define OMX_InterlaceFrameBottomField                   0x00000200
#define OMX_InterlaceTopField                           0x00001000
#define OMX_InterlaceBottomField                        0x00002000
#endif

#ifndef OMX_INTERLACEFORMATTYPE
typedef struct OMX_INTERLACEFORMATTYPE {
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_U32 nFormat;
	OMX_TICKS nTimeStamp;
} OMX_INTERLACEFORMATTYPE;
#endif

typedef struct {
	VDEC_FM_ADDR fm_addr;
	OMX_PSC_COLOR_CONV_MODE color_conv_mode;
	OMX_BOOL fillDone;
	OMX_MEMADDR dst_addr;
	OMX_U32 field_id;
	OMX_CONFIG_POINTTYPE offset;
	OMX_U8 rff;			/*Repeat first field */
	OMX_U8 tff;			/*Top field first */
	OMX_U8 progressive_sequence:1;	/* the coded video sequence contains only progressive frame pictures.
					   0:  the coded video sequence may contain both frame pictures
					   And field pictures and frame picture may be progressive or interlaced frames. */
	OMX_U8 progressive_frame:1;	/*1 : progressive 0 : interlace */
	OMX_U32			 picture_structure; /* AVDC_DCL_VIDEO_PIC_STRUCT_TOP:0x1 or AVDC_DCL_VIDEO_PIC_STRUCT_BOTTOM:0x2 or AVDC_DCL_VIDEO_PIC_STRUCT_FRAME:0x3 */
	OMX_U32			 field_structure;
	OMX_U16			horizontal_dec_size;
	OMX_U32                 fmid;
	OMX_INTERLACEFORMATTYPE	type;
} OMX_PSC_OUTPORT_PRIVATE_t;

typedef OMX_PSC_OUTPORT_PRIVATE_t OMX_SNI_OUTPORT_PRIVATE_t;

#ifndef RFC_TABLE_SNI
typedef struct RFC_TABLE_SNI {
    union {
        OMX_U8* pLumaBase;
        OMX_U64 dummy1;
    };
    OMX_U64 nLumaBusAddress;
    union {
        OMX_U8* pChromaBase;
        OMX_U64 dummy2;
    };
    OMX_U64 nChromaBusAddress;
} RFC_TABLE_SNI;
#endif

#ifndef DISPLAY_PRIMARIES_SNI
typedef struct DISPLAY_PRIMARIES_SNI {
    OMX_U32 x;
    OMX_U32 y;
} DISPLAY_PRIMARIES_SNI;
#endif

typedef enum {
    OMX_VIDEO_HdrInputOttB1,
    OMX_VIDEO_HdrInputOttB4E1,
    OMX_VIDEO_HdrInputOttB1E1,
    OMX_VIDEO_HdrInputHDMI,
    OMX_VIDEO_HdrInputMAXNUM
} OMX_VIDEO_HDRINPUTTYPE;
	
typedef enum {
    OMX_VIDEO_LowDelayModeDisable,
    OMX_VIDEO_LowDelayModeEnable,
    OMX_VIDEO_LowDelayModeMAXNUM
} OMX_VIDEO_LOWDELAYMODETYPE;
	
typedef struct {
    union {
        OMX_U8* pLumaBase;                  // Virtual address of the luminance buffer
        OMX_U64 dummy1;
    };
	union {
	    OMX_U64 nLumaBusAddress;            // Physical address of the luminance buffer
	    OMX_U64 nBusAddress0;				/* Physical address of the luminance buffer, YUV packed, ARGB format, etc. */
	};
    OMX_U32 nLumaSize;                  	// Size of the luminance data
    union {
        OMX_U8* pChromaBase;                // Virtual address of the chrominance buffer
        OMX_U64 dummy2;
    };
	union {
	    OMX_U64 nChromaBusAddress;          // Physical address of the chrominance buffer
	    OMX_U64 nBusAddress1;				/* Physical address of the chrominance buffer for planar format */
	};
    OMX_U32 nChromaSize;                	// Size of the chrominance data
    RFC_TABLE_SNI sRfcTable;                // RFC table data

    OMX_COLOR_FORMATTYPE eColorFormat;
    OMX_U32 nFrameWidth;
    OMX_U32 nFrameHeight;
    OMX_U32 nStride;
    OMX_U32 nSliceHeight;
    OMX_CONFIG_POINTTYPE sOffset;
    OMX_U32 nSarWidth;
    OMX_U32 nSarHeight;
    OMX_U32 xFramerate;
    OMX_INTERLACEFORMATTYPE type;
    OMX_COLORSPACETYPE eColorSpace;
    OMX_U32 nChromaSampleLoc; // 0: CenterLeft(MPEG2) / 1: CenterCenter(MPEG1) / 2: LeftTop.. (See H.265 Fig E.1)
    OMX_U32 nFrameDuration;

// derived parameter from BUFFERHEADERTYPE
	union {
	    OMX_HANDLETYPE hMarkTargetComponent;
        OMX_U64 dummy3;
	};
    OMX_U32 nTickCount;
    OMX_TICKS nTimeStamp;
    OMX_U32 nFlags;

    OMX_U32 eHdrMode;
    OMX_VIDEO_HDRINPUTTYPE eHdrInput;
	VDEC_FM_ADDR enhFmAddr;
	OMX_U32 nMetadataSize;
	union {
		OMX_PTR pHdrMetadata;
		OMX_U64 dummy4;
	};
    OMX_U32 nVideoRange; // Annex. E 0:[16-235] / 1:[0,255]
    OMX_U32 nColourPrimaries; // 1: BT.709, 2: Unspecified(default), 4:BT.470-6-M ....
    OMX_U32 nTransferCharacteristics; // 1: BT.709-5/1361 , 2:Unspecified(default) 4: BT.470-6-M 5: BT.470-6-B/G...)
    OMX_U32 nMatrixCoefficients;
    OMX_U32 preferred_transfer_characteristics_present;
    OMX_U32 preferred_transfer_characteristics;
    OMX_U32 mastering_display_colour_volume_present;
    DISPLAY_PRIMARIES_SNI display_primaries[3];
    OMX_U32 white_point_x;
    OMX_U32 white_point_y;
    OMX_U32 max_display_mastering_luminance;
    OMX_U32 min_display_mastering_luminance;
    OMX_U32 content_light_level_info_present;
    OMX_U32 max_content_light_level;
    OMX_U32 max_pic_average_light_level;
	
    OMX_VIDEO_LOWDELAYMODETYPE eLowDelayMode;
    OMX_U32 reserved_0;
    OMX_U32 reserved_1;
    OMX_U32 reserved_2;

} OMX_SNIVS_OUTPORT_PRIVATE_t;

typedef struct OMX_CONFIG_CONFIGLINKTYPE
{
	OMX_U32 nSize;
	OMX_VERSIONTYPE nVersion;
	OMX_U32 nPortIndex;
	OMX_BOOL bEnabled;
} OMX_CONFIG_CONFIGLINKTYPE;

typedef OMX_SNIVS_OUTPORT_PRIVATE_t OMX_SNIVS_PRIVATE_t;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
/* File EOF */
