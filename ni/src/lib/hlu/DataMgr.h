/*
 *      $Id: DataMgr.h,v 1.1 1993-07-12 22:36:15 boote Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1993			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		DataMgr.h
 *
 *	Author:		Jeff W. Boote
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Thu Jun 24 10:25:34 MDT 1993
 *
 *	Description:	Public declarations for DataMgr class.
 */
#ifndef _NDataMgr_h
#define _NDataMgr_h

#include <ncarg/hlu/Base.h>
#include <ncarg/hlu/DataItem.h>

/* Exported Layer and LayerClass */

typedef struct _DataMgrLayerClassRec *DataMgrLayerClass;
typedef struct _DataMgrLayerRec *DataMgrLayer;

/* Exported New types to support this object class */

/*
 * Opaque type to identify a piece of data
 */
typedef struct _NhlDHandleRec *_NhlDHandle;

extern LayerClass dataMgrLayerClass;

#endif /*_NDataMgr_h */
