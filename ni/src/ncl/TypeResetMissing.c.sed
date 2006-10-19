
/*
 *      $Id: TypeResetMissing.c.sed,v 1.2 2006-10-19 22:57:10 dbrown Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1995			*
*	     University Corporation for Atmospheric Research		*
*			     All Rights Reserved			*
*									*
************************************************************************/
/*
 *	File:		
 *
 *	Author:		Ethan Alpert
 *			National Center for Atmospheric Research
 *			PO 3000, Boulder, Colorado
 *
 *	Date:		Fri Jan 27 18:29:04 MST 1995
 *
 *	Description:	
 */


static NhlErrorTypes Ncl_Type_DATATYPE_reset_mis
#if	NhlNeedProto
(void	*val,NclScalar * old_m,NclScalar * new_m, int nval)
#else
(val,old_m,new_m,nval)
void *val;
NclScalar * old_m;
NclScalar * new_m;
int nval;
#endif
{
	DATATYPE *value = (DATATYPE*)val;
	int i;

	if((old_m == NULL)||(new_m == NULL))
		return(NhlFATAL);

	if (old_m->DATATYPEval == new_m->DATATYPEval) {
		/* nothing to do */
		return NhlNOERROR;	
	}

	for(i = 0; i < nval; i++,value++ ) {
		if(*value == old_m->DATATYPEval) {
			*value = new_m->DATATYPEval;
		}	
	}
	return(NhlNOERROR);
}
