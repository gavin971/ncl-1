/*
 *      $Id: Contour.h,v 1.16 1994-09-30 01:11:01 dbrown Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1992			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		Contour.h
 *
 *	Author:		David Brown
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Tue Nov 16 15:18:58 MST 1993
 *
 *	Description:	Public header for Contour class.
 */

#ifndef _NContour_h
#define _NContour_h

#include <ncarg/hlu/Workspace.h>
#include <ncarg/hlu/DataComm.h>
#include <ncarg/hlu/Overlay.h>
#include <ncarg/hlu/LogLinTransObj.h>
#include <ncarg/hlu/IrregularTransObj.h>
#include <ncarg/hlu/ScalarField.h>

/* Level selection modes */

typedef enum _NhlcnLevelSelectionMode { 
	NhlcnAUTOMATIC, NhlcnMANUAL, 
	NhlcnEXPLICIT, NhlcnEQUALSPACING } NhlcnLevelSelectionMode;

#define NhlTcnLevelSelectionMode "cnlevelselectionmode"

/* Level usage modes */

typedef enum _NhlcnLevelUseMode {
	NhlcnNOLINE, NhlcnLINEONLY, 
	NhlcnLABELONLY, NhlcnLINEANDLABEL
} NhlcnLevelUseMode;

#define NhlTcnLevelUseMode	"cnlevelusemode"
#define NhlTcnLevelUseModeGenArray    NhlTcnLevelUseMode NhlTGenArray

/* Line label spacing */

typedef enum _NhlcnLineLabelSpacingMode {
	NhlcnNOLABELS, NhlcnCONSTANT, 
	NhlcnRANDOMIZED, NhlcnCOMPUTED
} NhlcnLineLabelSpacingMode;

#define NhlTcnLineLabelSpacingMode	"cnlinelabelspacingmode"

/* Label scaling mode */

typedef enum _NhlcnLabelScalingMode {
	NhlcnSCALEFACTOR, NhlcnCONFINETORANGE,
	NhlcnTRIMZEROS,NhlcnMAXSIGDIGITSLEFT,
        NhlcnINTEGERLINELABELS
} NhlcnLabelScalingMode;

#define NhlTcnLabelScalingMode	"cnlabelscalinggmode"

/* label overlap flag */

typedef enum _NhlcnHighLowLabelOverlapMode {
	NhlcnIGNOREOVERLAP = 0,
	NhlcnOMITOVERINFO,
	NhlcnOMITOVERHL,
	NhlcnOMITOVERHLANDINFO,
	NhlcnOMITOVERVP,
	NhlcnOMITOVERVPANDINFO,
	NhlcnOMITOVERVPANDHL,
	NhlcnOMITOVERVPANDHLANDINFO,
	NhlcnADJUSTVP,
	NhlcnADJUSTVPOMITOVERINFO,
	NhlcnADJUSTVPOMITOVERHL,
	NhlcnADJUSTVPOMITOVERHLANDINFO
} NhlcnHighLowLabelOverlapMode;

#define NhlTcnHighLowLabelOverlapMode	"cnhighlowlabeloverlapmode"

/*
 * DataDep objects resources
 */

#define NhlNcnExplicitLabels		"cnExplicitLabels"
#define NhlCcnExplicitLabels		"CnExplicitLabels"

/*
 * Contour instance resources
 */

#define NhlNcnScalarFieldData		"cnScalarFieldData"
#define NhlNcnOutOfRangeValF		"cnOutOfRangeValF"

#define NhlNcnLevelCount		".cnLevelCount"		/* read-only */
#define NhlNcnLevelSelectionMode	"cnLevelSelectionMode"
#define NhlNcnMaxLevelCount		"cnMaxLevelCount"
#define NhlNcnLevelSpacingF		"cnLevelSpacingF"
#define NhlNcnLabelMasking		"cnLabelMasking"
#define NhlNcnMinLevelValF		"cnMinLevelValF"
#define NhlNcnMaxLevelValF		"cnMaxLevelValF"
#define NhlNcnBelowMinLevelColor	"cnBelowMinLevelColor"
#define NhlNcnAboveMaxLevelColor	"cnAboveMaxLevelColor"
#define NhlNcnBelowMinLevelFillPattern	"cnBelowMinLevelFillPattern"
#define NhlNcnAboveMaxLevelFillPattern	"cnAboveMaxLevelFillPattern"
#define NhlNcnBelowMinLevelFillScale	"cnBelowMinLevelFillScale"
#define NhlNcnAboveMaxLevelFillScale	"cnAboveMaxLevelFillScale"
#define NhlNcnLineLabelInterval		"cnLineLabelInterval"
#define NhlNcnLabelDrawOrder		"cnLabelDrawOrder"
#define NhlNcnLineDrawOrder		"cnLineDrawOrder"
#define NhlNcnFillDrawOrder		"cnFillDrawOrder"
#define NhlNcnLinesOn			"cnLinesOn"
#define NhlNcnFillOn			"cnFillOn"

#define NhlNcnLabelScalingMode		"cnLabelScalingMode"
#define NhlNcnLabelScaleValueF		"cnLabelScaleValueF"
#define NhlNcnLabelScaleFactorF		".cnLabelScaleFactorF" /*read-only*/
#define NhlNcnMaxDataValueFormat	"cnMaxDataValueFormat"
#define NhlNcnSmoothingOn		"cnSmoothingOn"
#define NhlNcnSmoothingTensionF		"cnSmoothingTensionF"
#define NhlNcnSmoothingDistanceF	"cnSmoothingDistanceF"
#define NhlNcnCheckPointDistance	"cnCheckPointDistance"
#define NhlNcnMaxPointDistanceF		"cnMaxPointDistanceF"

#define NhlNcnMonoLevelFlag		"cnMonoLevelFlag"
#define NhlNcnMonoFillColor		"cnMonoFillColor"
#define NhlNcnMonoFillPattern		"cnMonoFillPattern"
#define NhlNcnMonoFillScale		"cnMonoFillScale"
#define NhlNcnMonoLineColor		"cnMonoLineColor"
#define NhlNcnMonoLineDashPattern	"cnMonoLineDashPattern"
#define NhlNcnMonoLineThickness		"cnMonoLineThickness"
#define NhlNcnMonoLineLabelColor	"cnMonoLineLabelColor"

#define NhlNcnLevels			"cnLevels"
#define NhlNcnLevelFlags		"cnLevelFlags"
#define NhlNcnFillColors		"cnFillColors"
#define NhlNcnFillPatterns		"cnFillPatterns"
#define NhlNcnFillScales		"cnFillScales"

#define NhlNcnLineColors		"cnLineColors"
#define NhlNcnLineDashPatterns		"cnLineDashPatterns"
#define NhlNcnLineThicknesses		"cnLineThicknesses"
#define NhlNcnLineLabelStrings		"cnLineLabelStrings"
#define NhlNcnLineLabelColors		"cnLineLabelColors"

#define NhlNcnLineDashSegLenF		"cnLineDashSegLenF"
#define NhlNcnLowUseHighLabelRes	"cnLowUseHighLabelRes"
#define NhlNcnHighUseLineLabelRes	"cnHighUseLineLabelRes"
#define NhlNcnConstFUseInfoLabelRes	"cnConstFUseInfoLabelRes"
#define NhlNcnLineLabelSpacing		"cnLineLabelSpacing"
#define NhlNcnHighLowLabelOverlapMode	"cnHighLowLabelOverlapMode"

#define NhlNcnLineLabelsOn		"cnLineLabelsOn"
#define NhlNcnLineLabelFormat		"cnLineLabelFormat"
#define NhlNcnLineLabelTextHeightF	"cnLineLabelTextHeightF"
#define NhlNcnLineLabelFont		"cnLineLabelFont"
#define NhlNcnLineLabelFontAspectF	"cnLineLabelFontAspectF"
#define NhlNcnLineLabelFontThicknessF	"cnLineLabelFontThicknessF"
#define NhlNcnLineLabelFontQuality	"cnLineLabelFontQuality"
#define NhlNcnLineLabelConstantSpacingF	"cnLineLabelConstantSpacingF"
#define NhlNcnLineLabelAngleF		"cnLineLabelAngleF"
#define NhlNcnLineLabelFuncCode		"cnLineLabelFuncCode"
#define NhlNcnLineLabelBackgroundColor	"cnLineLabelBackgroundColor"
#define NhlNcnLineLabelPerim		"cnLineLabelPerim"
#define NhlNcnLineLabelPerimSpaceF	"cnLineLabelPerimSpaceF"
#define NhlNcnLineLabelPerimThicknessF	"cnLineLabelPerimThicknessF"
#define NhlNcnLineLabelPerimColor	"cnLineLabelPerimColor"

#define NhlNcnHighLabelsOn		"cnHighLabelsOn"
#define NhlNcnHighLabelString		"cnHighLabelString"
#define NhlNcnHighLabelFormat		"cnHighLabelFormat"
#define NhlNcnHighLabelTextHeightF	"cnHighLabelTextHeightF"
#define NhlNcnHighLabelFont		"cnHighLabelFont"
#define NhlNcnHighLabelFontColor	"cnHighLabelFontColor"
#define NhlNcnHighLabelFontAspectF	"cnHighLabelFontAspectF"
#define NhlNcnHighLabelFontThicknessF	"cnHighLabelFontThicknessF"
#define NhlNcnHighLabelFontQuality	"cnHighLabelFontQuality"
#define NhlNcnHighLabelConstantSpacingF	"cnHighLabelConstantSpacingF"
#define NhlNcnHighLabelAngleF		"cnHighLabelAngleF"
#define NhlNcnHighLabelFuncCode		"cnHighLabelFuncCode"
#define NhlNcnHighLabelBackgroundColor	"cnHighLabelBackgroundColor"
#define NhlNcnHighLabelPerim		"cnHighLabelPerim"
#define NhlNcnHighLabelPerimSpaceF	"cnHighLabelPerimSpaceF"
#define NhlNcnHighLabelPerimThicknessF	"cnHighLabelPerimThicknessF"
#define NhlNcnHighLabelPerimColor	"cnHighLabelPerimColor"

#define NhlNcnLowLabelsOn		"cnLowLabelsOn"
#define NhlNcnLowLabelString		"cnLowLabelString"
#define NhlNcnLowLabelFormat		"cnLowLabelFormat"
#define NhlNcnLowLabelTextHeightF	"cnLowLabelTextHeightF"
#define NhlNcnLowLabelFont		"cnLowLabelFont"
#define NhlNcnLowLabelFontColor		"cnLowLabelFontColor"
#define NhlNcnLowLabelFontAspectF	"cnLowLabelFontAspectF"
#define NhlNcnLowLabelFontThicknessF	"cnLowLabelFontThicknessF"
#define NhlNcnLowLabelFontQuality	"cnLowLabelFontQuality"
#define NhlNcnLowLabelConstantSpacingF	"cnLowLabelConstantSpacingF"
#define NhlNcnLowLabelAngleF		"cnLowLabelAngleF"
#define NhlNcnLowLabelFuncCode		"cnLowLabelFuncCode"
#define NhlNcnLowLabelBackgroundColor	"cnLowLabelBackgroundColor"
#define NhlNcnLowLabelPerim		"cnLowLabelPerim"
#define NhlNcnLowLabelPerimSpaceF	"cnLowLabelPerimSpaceF"
#define NhlNcnLowLabelPerimThicknessF	"cnLowLabelPerimThicknessF"
#define NhlNcnLowLabelPerimColor	"cnLowLabelPerimColor"

#define NhlNcnInfoLabelOn		"cnInfoLabelOn"
#define NhlNcnInfoLabelString		"cnInfoLabelString"
#define NhlNcnInfoLabelFormat		"cnInfoLabelFormat"
#define NhlNcnInfoLabelTextHeightF	"cnInfoLabelTextHeightF"
#define NhlNcnInfoLabelTextDirection	"cnInfoLabelTextDirection"
#define NhlNcnInfoLabelFont		"cnInfoLabelFont"
#define NhlNcnInfoLabelFontColor	"cnInfoLabelFontColor"
#define NhlNcnInfoLabelFontAspectF	"cnInfoLabelFontAspectF"
#define NhlNcnInfoLabelFontThicknessF	"cnInfoLabelFontThicknessF"
#define NhlNcnInfoLabelFontQuality	"cnInfoLabelFontQuality"
#define NhlNcnInfoLabelConstantSpacingF	"cnInfoLabelConstantSpacingF"
#define NhlNcnInfoLabelAngleF		"cnInfoLabelAngleF"
#define NhlNcnInfoLabelFuncCode		"cnInfoLabelFuncCode"
#define NhlNcnInfoLabelBackgroundColor	"cnInfoLabelBackgroundColor"
#define NhlNcnInfoLabelPerim		"cnInfoLabelPerim"
#define NhlNcnInfoLabelPerimSpaceF	"cnInfoLabelPerimSpaceF"
#define NhlNcnInfoLabelPerimThicknessF	"cnInfoLabelPerimThicknessF"
#define NhlNcnInfoLabelPerimColor	"cnInfoLabelPerimColor"

#define NhlNcnInfoLabelZone		"cnInfoLabelZone"
#define NhlNcnInfoLabelSide		"cnInfoLabelSide"
#define NhlNcnInfoLabelJust		"cnInfoLabelJust"
#define NhlNcnInfoLabelParallelPosF	"cnInfoLabelParallelPosF"
#define NhlNcnInfoLabelOrthogonalPosF	"cnInfoLabelOrthogonalPosF"

#define NhlNcnConstFLabelOn		"cnConstFLabelOn"
#define NhlNcnConstFLabelString		"cnConstFLabelString"
#define NhlNcnConstFLabelFormat		"cnconstFLabelFormat"
#define NhlNcnConstFLabelTextHeightF	"cnConstFLabelTextHeightF"
#define NhlNcnConstFLabelTextDirection	"cnConstFLabelTextDirection"
#define NhlNcnConstFLabelFont		"cnConstFLabelFont"
#define NhlNcnConstFLabelFontColor	"cnConstFLabelFontColor"
#define NhlNcnConstFLabelFontAspectF	"cnConstFLabelFontAspectF"
#define NhlNcnConstFLabelFontThicknessF	"cnConstFLabelFontThicknessF"
#define NhlNcnConstFLabelFontQuality	"cnConstFLabelFontQuality"
#define NhlNcnConstFLabelConstantSpacingF "cnConstFLabelConstantSpacingF"
#define NhlNcnConstFLabelAngleF		"cnConstFLabelAngleF"
#define NhlNcnConstFLabelFuncCode	"cnConstFLabelFuncCode"
#define NhlNcnConstFLabelBackgroundColor "cnConstFLabelBackgroundColor"
#define NhlNcnConstFLabelPerim		"cnConstFLabelPerim"
#define NhlNcnConstFLabelPerimSpaceF	"cnConstFLabelPerimSpaceF"
#define NhlNcnConstFLabelPerimThicknessF "cnConstFLabelPerimThicknessF"
#define NhlNcnConstFLabelPerimColor	"cnConstFLabelPerimColor"

#define NhlNcnConstFLabelZone		"cnConstFLabelZone"
#define NhlNcnConstFLabelSide		"cnConstFLabelSide"
#define NhlNcnConstFLabelJust		"cnConstFLabelJust"
#define NhlNcnConstFLabelParallelPosF	"cnConstFLabelParallelPosF"
#define NhlNcnConstFLabelOrthogonalPosF	"cnConstFLabelOrthogonalPosF"

#define NhlNcnMissingValPerim		"cnMissingValPerim"
#define NhlNcnMissingValPerimThicknessF	"cnMissingValPerimThicknessF"
#define NhlNcnMissingValPerimDashPattern "cnMissingValPerimDashPattern"
#define NhlNcnMissingValPerimColor	"cnMissingValPerimColor"
#define NhlNcnMissingValFillColor	"cnMissingValFillColor"
#define NhlNcnMissingValFillPattern	"cnMissingValFillPattern"
#define NhlNcnMissingValFillScaleF	"cnMissingValFillScaleF"

#define NhlNcnGridBoundPerim		"cnGridBoundPerim"
#define NhlNcnGridBoundPerimThicknessF	"cnGridBoundPerimThicknessF"
#define NhlNcnGridBoundPerimDashPattern "cnGridBoundPerimDashPattern"
#define NhlNcnGridBoundPerimColor	"cnGridBoundPerimColor"
#define NhlNcnGridBoundFillColor	"cnGridBoundFillColor"
#define NhlNcnGridBoundFillPattern	"cnGridBoundFillPattern"
#define NhlNcnGridBoundFillScaleF	"cnGridBoundFillScaleF"

#define NhlNcnOutOfRangePerim		"cnOutOfRangePerim"
#define NhlNcnOutOfRangePerimThicknessF	"cnOutOfRangePerimThicknessF"
#define NhlNcnOutOfRangePerimDashPattern "cnOutOfRangePerimDashPattern"
#define NhlNcnOutOfRangePerimColor	"cnOutOfRangePerimColor"
#define NhlNcnOutOfRangeFillColor	"cnOutOfRangeFillColor"
#define NhlNcnOutOfRangeFillPattern	"cnOutOfRangeFillPattern"
#define NhlNcnOutOfRangeFillScaleF	"cnOutOfRangeFillScaleF"

#define NhlNcnDumpAreaMap		"cnDumpAreaMap"

/*
 * Contour class resources
 */

#define NhlCcnScalarFieldData		"CnScalarFieldData"
#define NhlCcnOutOfRangeValF		"CnOutOfRangeValF"

#define NhlCcnLevelCount		".CnLevelCount"		/* read-only */
#define NhlCcnLevelSelectionMode	"CnLevelSelectionMode"
#define NhlCcnMaxLevelCount		"CnMaxLevelCount"
#define NhlCcnLevelSpacingF		"CnLevelSpacingF"
#define NhlCcnLabelMasking		"CnLabelMasking"
#define NhlCcnMinLevelValF		"CnMinLevelValF"
#define NhlCcnMaxLevelValF		"CnMaxLevelValF"
#define NhlCcnBelowMinLevelColor	"CnBelowMinLevelColor"
#define NhlCcnBelowMinLevelFillPattern	"CnBelowMinLevelFillPattern"
#define NhlCcnBelowMinLevelFillScale	"CnBelowMinLevelFillScale"
#define NhlCcnAboveMaxLevelColor	"CnAboveMaxLevelColor"
#define NhlCcnAboveMaxLevelFillPattern	"CnAboveMaxLevelFillPattern"
#define NhlCcnAboveMaxLevelFillScale	"CnAboveMaxLevelFillScale"
#define NhlCcnLineLabelInterval		"CnLineLabelInterval"
#define NhlCcnLabelDrawOrder		"CnLabelDrawOrder"
#define NhlCcnLineDrawOrder		"CnLineDrawOrder"
#define NhlCcnFillDrawOrder		"CnFillDrawOrder"
#define NhlCcnLinesOn			"CnLinesOn"
#define NhlCcnFillOn			"CnFillOn"

#define NhlCcnLabelScalingMode		"CnLabelScalingMode"
#define NhlCcnLabelScaleValueF		"CnLabelScaleValueF"
#define NhlCcnLabelScaleFactorF		".CnLabelScaleFactorF" /*read-only*/
#define NhlCcnMaxDataValueFormat	"CnMaxDataValueFormat"
#define NhlCcnSmoothingOn		"CnSmoothingOn"
#define NhlCcnSmoothingTensionF		"CnSmoothingTensionF"
#define NhlCcnSmoothingDistanceF	"CnSmoothingDistanceF"
#define NhlCcnCheckPointDistance	"CnCheckPointDistance"
#define NhlCcnMaxPointDistanceF		"CnMaxPointDistanceF"

#define NhlCcnMonoLevelFlag		"CnMonoLevelFlag"
#define NhlCcnMonoFillColor		"CnMonoFillColor"
#define NhlCcnMonoFillPattern		"CnMonoFillPattern"
#define NhlCcnMonoFillScale		"CnMonoFillScale"
#define NhlCcnMonoLineColor		"CnMonoLineColor"
#define NhlCcnMonoLineDashPattern	"CnMonoLineDashPattern"
#define NhlCcnMonoLineThickness		"CnMonoLineThickness"
#define NhlCcnMonoLineLabelColor	"CnMonoLineLabelColor"

#define NhlCcnLevels			"CnLevels"
#define NhlCcnLevelFlags		"CnLevelFlags"
#define NhlCcnFillColors		"CnFillColors"
#define NhlCcnFillPatterns		"CnFillPatterns"
#define NhlCcnFillScales		"CnFillScales"

#define NhlCcnLineColors		"CnLineColors"
#define NhlCcnLineDashPatterns		"CnLineDashPatterns"
#define NhlCcnLineThicknesses		"CnLineThicknesses"
#define NhlCcnLineLabelStrings		"CnLineLabelStrings"
#define NhlCcnLineLabelColors		"CnLineLabelColors"

#define NhlCcnLineDashSegLenF		"CnLineDashSegLenF"
#define NhlCcnLineLabelSpacing		"CnLineLabelSpacing"

#define NhlCcnLowUseHighLabelRes	"CnLowUseHighLabelRes"
#define NhlCcnHighUseLineLabelRes	"CnHighUseLineLabelRes"
#define NhlCcnConstFUseInfoLabelRes	"CnConstFUseInfoLabelRes"
#define NhlCcnHighLowLabelOverlapMode	"CnHighLowLabelOverlapMode"

#define NhlCcnLineLabelsOn		"CnLineLabelsOn"
#define NhlCcnLineLabelFormat		"CnLineLabelFormat"
#define NhlCcnLineLabelTextHeightF	"CnLineLabelTextHeightF"
#define NhlCcnLineLabelFont		"CnLineLabelFont"
#define NhlCcnLineLabelFontAspectF	"CnLineLabelFontAspectF"
#define NhlCcnLineLabelFontThicknessF	"CnLineLabelFontThicknessF"
#define NhlCcnLineLabelFontQuality	"CnLineLabelFontQuality"
#define NhlCcnLineLabelConstantSpacingF	"CnLineLabelConstantSpacingF"
#define NhlCcnLineLabelAngleF		"CnLineLabelAngleF"
#define NhlCcnLineLabelFuncCode		"CnLineLabelFuncCode"
#define NhlCcnLineLabelBackgroundColor	"CnLineLabelBackgroundColor"
#define NhlCcnLineLabelPerim		"CnLineLabelPerim"
#define NhlCcnLineLabelPerimSpaceF	"CnLineLabelPerimSpaceF"
#define NhlCcnLineLabelPerimThicknessF	"CnLineLabelPerimThicknessF"
#define NhlCcnLineLabelPerimColor	"CnLineLabelPerimColor"

#define NhlCcnHighLabelsOn		"CnHighLabelsOn"
#define NhlCcnHighLabelString		"CnHighLabelString"
#define NhlCcnHighLabelFormat		"CnHighLabelFormat"
#define NhlCcnHighLabelTextHeightF	"CnHighLabelTextHeightF"
#define NhlCcnHighLabelFont		"CnHighLabelFont"
#define NhlCcnHighLabelFontColor	"CnHighLabelFontColor"
#define NhlCcnHighLabelFontAspectF	"CnHighLabelFontAspectF"
#define NhlCcnHighLabelFontThicknessF	"CnHighLabelFontThicknessF"
#define NhlCcnHighLabelFontQuality	"CnHighLabelFontQuality"
#define NhlCcnHighLabelConstantSpacingF	"CnHighLabelConstantSpacingF"
#define NhlCcnHighLabelAngleF		"CnHighLabelAngleF"
#define NhlCcnHighLabelFuncCode		"CnHighLabelFuncCode"
#define NhlCcnHighLabelBackgroundColor	"CnHighLabelBackgroundColor"
#define NhlCcnHighLabelPerim		"CnHighLabelPerim"
#define NhlCcnHighLabelPerimSpaceF	"CnHighLabelPerimSpaceF"
#define NhlCcnHighLabelPerimThicknessF	"CnHighLabelPerimThicknessF"
#define NhlCcnHighLabelPerimColor	"CnHighLabelPerimColor"

#define NhlCcnLowLabelsOn		"CnLowLabelsOn"
#define NhlCcnLowLabelString		"CnLowLabelString"
#define NhlCcnLowLabelFormat		"CnLowLabelFormat"
#define NhlCcnLowLabelTextHeightF	"CnLowLabelTextHeightF"
#define NhlCcnLowLabelFont		"CnLowLabelFont"
#define NhlCcnLowLabelFontColor		"CnLowLabelFontColor"
#define NhlCcnLowLabelFontAspectF	"CnLowLabelFontAspectF"
#define NhlCcnLowLabelFontThicknessF	"CnLowLabelFontThicknessF"
#define NhlCcnLowLabelFontQuality	"CnLowLabelFontQuality"
#define NhlCcnLowLabelConstantSpacingF	"CnLowLabelConstantSpacingF"
#define NhlCcnLowLabelAngleF		"CnLowLabelAngleF"
#define NhlCcnLowLabelFuncCode		"CnLowLabelFuncCode"
#define NhlCcnLowLabelBackgroundColor	"CnLowLabelBackgroundColor"
#define NhlCcnLowLabelPerim		"CnLowLabelPerim"
#define NhlCcnLowLabelPerimSpaceF	"CnLowLabelPerimSpaceF"
#define NhlCcnLowLabelPerimThicknessF	"CnLowLabelPerimThicknessF"
#define NhlCcnLowLabelPerimColor	"CnLowLabelPerimColor"


#define NhlCcnInfoLabelOn		"CnInfoLabelOn"
#define NhlCcnInfoLabelString		"CnInfoLabelString"
#define NhlCcnInfoLabelFormat		"CnInfoLabelFormat"
#define NhlCcnInfoLabelSide		"CnInfoLabelSide"
#define NhlCcnInfoLabelPosition		"CnInfoLabelPosition"
#define NhlCcnInfoLabelJustification	"CnInfoLabelJusification"
#define NhlCcnInfoLabelXOffsetF		"CnInfoLabelXOffsetF"
#define NhlCcnInfoLabelYOffsetF		"CnInfoLabelYOffsetF"
#define NhlCcnInfoLabelTextHeightF	"CnInfoLabelTextHeightF"
#define NhlCcnInfoLabelTextDirection	"CnInfoLabelTextDirection"
#define NhlCcnInfoLabelFont		"CnInfoLabelFont"
#define NhlCcnInfoLabelFontColor	"CnInfoLabelFontColor"
#define NhlCcnInfoLabelFontAspectF	"CnInfoLabelFontAspectF"
#define NhlCcnInfoLabelFontThicknessF	"CnInfoLabelFontThicknessF"
#define NhlCcnInfoLabelFontQuality	"CnInfoLabelFontQuality"
#define NhlCcnInfoLabelConstantSpacingF	"CnInfoLabelConstantSpacingF"
#define NhlCcnInfoLabelAngleF		"CnInfoLabelAngleF"
#define NhlCcnInfoLabelFuncCode		"CnInfoLabelFuncCode"
#define NhlCcnInfoLabelBackgroundColor	"CnInfoLabelBackgroundColor"
#define NhlCcnInfoLabelPerim		"CnInfoLabelPerim"
#define NhlCcnInfoLabelPerimSpaceF	"CnInfoLabelPerimSpaceF"
#define NhlCcnInfoLabelPerimThicknessF	"CnInfoLabelPerimThicknessF"
#define NhlCcnInfoLabelPerimColor	"CnInfoLabelPerimColor"

#define NhlCcnInfoLabelZone		"CnInfoLabelZone"
#define NhlCcnInfoLabelSide		"CnInfoLabelSide"
#define NhlCcnInfoLabelJust		"CnInfoLabelJust"
#define NhlCcnInfoLabelParallelPosF	"CnInfoLabelParallelPosF"
#define NhlCcnInfoLabelOrthogonalPosF	"CnInfoLabelOrthogonalPosF"

#define NhlCcnConstFLabelOn		"CnConstFLabelOn"
#define NhlCcnConstFLabelString		"CnConstFLabelString"
#define NhlCcnConstFLabelFormat		"CnConstFLabelFormat"
#define NhlCcnConstFLabelTextHeightF	"CnConstFLabelTextHeightF"
#define NhlCcnConstFLabelTextDirection	"CnConstFLabelTextDirection"
#define NhlCcnConstFLabelFont		"CnConstFLabelFont"
#define NhlCcnConstFLabelFontColor	"CnConstFLabelFontColor"
#define NhlCcnConstFLabelFontAspectF	"CnConstFLabelFontAspectF"
#define NhlCcnConstFLabelFontThicknessF	"CnConstFLabelFontThicknessF"
#define NhlCcnConstFLabelFontQuality	"CnConstFLabelFontQuality"
#define NhlCcnConstFLabelConstantSpacingF "CnConstFLabelConstantSpacingF"
#define NhlCcnConstFLabelAngleF		"CnConstFLabelAngleF"
#define NhlCcnConstFLabelFuncCode	"CnConstFLabelFuncCode"
#define NhlCcnConstFLabelBackgroundColor "CnConstFLabelBackgroundColor"
#define NhlCcnConstFLabelPerim		"CnConstFLabelPerim"
#define NhlCcnConstFLabelPerimSpaceF	"CnConstFLabelPerimSpaceF"
#define NhlCcnConstFLabelPerimThicknessF "CnConstFLabelPerimThicknessF"
#define NhlCcnConstFLabelPerimColor	"CnConstFLabelPerimColor"

#define NhlCcnConstFLabelZone		"CnConstFLabelZone"
#define NhlCcnConstFLabelSide		"CnConstFLabelSide"
#define NhlCcnConstFLabelJust		"CnConstFLabelJust"
#define NhlCcnConstFLabelParallelPosF	"CnConstFLabelParallelPosF"
#define NhlCcnConstFLabelOrthogonalPosF	"CnConstFLabelOrthogonalPosF"

#define NhlCcnMissingValPerim		"CnMissingValPerim"
#define NhlCcnMissingValPerimThicknessF	"CnMissingValPerimThicknessF"
#define NhlCcnMissingValPerimDashPattern "CnMissingValPerimDashPattern"
#define NhlCcnMissingValPerimColor	"CnMissingValPerimColor"
#define NhlCcnMissingValFillColor	"CnMissingValFillColor"
#define NhlCcnMissingValFillPattern	"CnMissingValFillPattern"
#define NhlCcnMissingValFillScaleF	"CnMissingValFillScaleF"

#define NhlCcnGridBoundPerim		"CnGridBoundPerim"
#define NhlCcnGridBoundPerimThicknessF	"CnGridBoundPerimThicknessF"
#define NhlCcnGridBoundPerimDashPattern "CnGridBoundPerimDashPattern"
#define NhlCcnGridBoundPerimColor	"CnGridBoundPerimColor"
#define NhlCcnGridBoundFillColor	"CnGridBoundFillColor"
#define NhlCcnGridBoundFillPattern	"CnGridBoundFillPattern"
#define NhlCcnGridBoundFillScaleF	"CnGridBoundFillScaleF"

#define NhlCcnOutOfRangePerim		"CnOutOfRangePerim"
#define NhlCcnOutOfRangePerimThicknessF	"CnOutOfRangePerimThicknessF"
#define NhlCcnOutOfRangePerimDashPattern "CnOutOfRangePerimDashPattern"
#define NhlCcnOutOfRangePerimColor	"CnOutOfRangePerimColor"
#define NhlCcnOutOfRangeFillColor	"CnOutOfRangeFillColor"
#define NhlCcnOutOfRangeFillPattern	"CnOutOfRangeFillPattern"
#define NhlCcnOutOfRangeFillScaleF	"CnOutOfRangeFillScaleF"

#define NhlCcnDumpAreaMap		"CnDumpAreaMap"

extern NhlLayerClass			NhlcontourLayerClass;

#endif /*_NContour_h */
