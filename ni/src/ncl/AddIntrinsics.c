

/*
 *      $Id: AddIntrinsics.c,v 1.5 1994-07-14 20:45:36 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1994			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		AddIntrinsics.c
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Mon Feb 7 11:07:41 MST 1994
 *
 *	Description:	
 */
#ifdef __cpluplus
extern "C" {
#endif
#include <stdio.h>
#include <ncarg/hlu/hlu.h>
#include <ncarg/hlu/NresDB.h>
#include "defs.h"
#include "Symbol.h"
#include "y.tab.h"

extern NhlErrorTypes _NclIAddFile(
#ifdef NhlNeedProto
void
#endif
);
extern NhlErrorTypes _NclIClear(
#ifdef NhlNeedProto
void
#endif 
);
extern NhlErrorTypes  _NclIUpdate(
#ifdef NhlNeedProto
void
#endif 
);
extern NhlErrorTypes  _NclIFrame(
#ifdef NhlNeedProto
void
#endif 
);
extern NhlErrorTypes  _NclIPrint(
#ifdef NhlNeedProto
void
#endif 
);
extern NhlErrorTypes  _NclIDelete(
#ifdef NhlNeedProto
void
#endif
);
extern NhlErrorTypes  _NclIDraw(
#ifdef NhlNeedProto
void
#endif
);

extern NhlErrorTypes  _NclIDestroy(
#ifdef NhlNeedProto
void
#endif
);
extern NhlErrorTypes  _NclIDumpStk(
#ifdef NhlNeedProto
void
#endif
);

extern NhlErrorTypes  _NclISizeOf(
#ifdef NhlNeedProto
void
#endif
);

extern NhlErrorTypes  _NclIDimSizes(
#ifdef NhlNeedProto
void
#endif
);

extern NhlErrorTypes  _NclIAny(
#ifdef NhlNeedProto
void
#endif
);

extern NhlErrorTypes  _NclIAll(
#ifdef NhlNeedProto
void
#endif
);

void _NclAddIntrinsics
#if  __STDC__
(void)
#else 
()
#endif
{
	NclArgTemplate *args;

	args = NclCalloc(1,sizeof(NclArgTemplate));
	args[0].arg_data_type = NULL;
	args[0].is_dimsizes = 0;
	_NclRegisterProc(_NclIPrint,args,"print",1,IPROC);
	args = NclCalloc(1,sizeof(NclArgTemplate));
	args[0].arg_data_type = NULL;
	args[0].is_dimsizes = 0;
	_NclRegisterProc(_NclIDelete,args,"delete",1,IPROC);
	args = NclCalloc(1,sizeof(NclArgTemplate));
	args[0].arg_data_type = _NclLookUp("graphic");
	args[0].is_dimsizes = 0;
	_NclRegisterProc(_NclIDraw,args,"draw",1,IPROC);
	args = NclCalloc(1,sizeof(NclArgTemplate));
	args[0].arg_data_type = _NclLookUp("graphic");
	args[0].is_dimsizes = 0;
	_NclRegisterProc(_NclIDestroy,args,"destroy",1,IPROC);
	args = NclCalloc(1,sizeof(NclArgTemplate));
	args[0].arg_data_type = _NclLookUp("graphic");
	args[0].is_dimsizes = 0;
	_NclRegisterProc(_NclIUpdate,args,"update",1,IPROC);
	args = NclCalloc(1,sizeof(NclArgTemplate));
	args[0].arg_data_type = _NclLookUp("graphic");
	args[0].is_dimsizes = 0;
	_NclRegisterProc(_NclIFrame,args,"frame",1,IPROC);
	args = NclCalloc(1,sizeof(NclArgTemplate));
	args[0].arg_data_type = _NclLookUp("graphic");
	args[0].is_dimsizes = 0;
	_NclRegisterProc(_NclIClear,args,"clear",1,IPROC);
	args = NclCalloc(1,sizeof(NclArgTemplate));
	args[0].arg_data_type = _NclLookUp("string");
	args[0].is_dimsizes = 1;
	args[0].dim_sizes[0] = 1;
	args[0].n_dims = 1;
	_NclRegisterProc(_NclIDumpStk,args,"dump",1,IPROC);
	args = NclCalloc(2,sizeof(NclArgTemplate));
	args[0].arg_data_type = _NclLookUp("string");
	args[0].is_dimsizes = 1;
	args[0].dim_sizes[0] = 1;
	args[0].n_dims = 1;
	args[1].arg_data_type = _NclLookUp("string");
	args[1].is_dimsizes = 1;
	args[1].dim_sizes[0] = 1;
	args[1].n_dims = 1;
	_NclRegisterProc(_NclIAddFile,args,"addfile",2,IFUNC);
	args = NclCalloc(1,sizeof(NclArgTemplate));
	args[0].arg_data_type = NULL;
	args[0].is_dimsizes = 0;
	_NclRegisterFunc(_NclISizeOf,args,"sizeof",1,IFUNC);
	args = NclCalloc(1,sizeof(NclArgTemplate));
	args[0].arg_data_type = NULL;
	args[0].is_dimsizes = 0;
	_NclRegisterFunc(_NclIDimSizes,args,"dimsizes",1,IFUNC);
	args = NclCalloc(1,sizeof(NclArgTemplate));
	args[0].arg_data_type = _NclLookUp("logical");
	args[0].is_dimsizes = 0;
	_NclRegisterFunc(_NclIAny,args,"any",1,IFUNC);
	args = NclCalloc(1,sizeof(NclArgTemplate));
	args[0].arg_data_type = _NclLookUp("logical");
	args[0].is_dimsizes = 0;
	_NclRegisterFunc(_NclIAll,args,"all",1,IFUNC);
	return;
}


#ifdef __cpluplus
}
#endif
