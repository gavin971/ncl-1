/*
 *      $Id: DataSupport.c,v 1.1 1994-07-14 20:45:41 ethan Exp $
 */
/************************************************************************
*									*
*			     Copyright (C)  1994			*
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
 *	Date:		Thu Jan 13 14:52:04 MST 1994
 *
 *	Description:	
 */

#include <ncarg/hlu/hlu.h>
#include <ncarg/hlu/NresDB.h>
#include "defs.h"
#include "Symbol.h"
#include "NclMdInc.h"
#include "y.tab.h"
#include "OpsList.h"


/*
* Probably should put stuff like this in the actual data object to avoid having to
* add objects here later
*/

long _NclObjTypeToName
#if  __STDC__ 
(NclObjTypes obj)
#else
(obj)
	NclObjTypes obj;
#endif
{
	switch(obj) {
	case Ncl_MultiDValintData:
		return(NrmStringToQuark("Ncl_MultiDValintData"));
	case Ncl_MultiDValdoubleData:
		return(NrmStringToQuark("Ncl_MultiDValdoubleData"));
	case Ncl_MultiDValbyteData:
		return(NrmStringToQuark("Ncl_MultiDValbyteData"));
	case Ncl_MultiDVallongData:
		return(NrmStringToQuark("Ncl_MultiDVallongData"));
	case Ncl_MultiDValshortData:
		return(NrmStringToQuark("Ncl_MultiDValshortData"));
	case Ncl_MultiDValfloatData:
		return(NrmStringToQuark("Ncl_MultiDValfloatData"));
	case Ncl_MultiDValcharData:
		return(NrmStringToQuark("Ncl_MultiDValcharData"));
	case Ncl_MultiDValstringData:
		return(NrmStringToQuark("Ncl_MultiDValstringData"));
	case Ncl_MultiDValHLUObjData:
		return(NrmStringToQuark("Ncl_MultiDValHLUObjData"));
	case Ncl_MultiDVallogicalData:
		return(NrmStringToQuark("Ncl_MultiDVallogicalData"));
	case Ncl_MultiDValnclfileData:
		return(NrmStringToQuark("Ncl_MultiDValnclfileData"));
	default:
		return(-1);
	}
}
unsigned int _NclKeywordToObjType
#if  __STDC__ 
(struct _NclSymbol *keywd)
#else
(keywd)
	struct _NclSymbol *keywd;
#endif
{
	if(keywd != NULL) {
		switch(keywd->type) {
		case INTEGER:
			return((unsigned int)Ncl_MultiDValintData);
		case DOUBLE:
			return((unsigned int)Ncl_MultiDValdoubleData);
		case BYTE:
			return((unsigned int)Ncl_MultiDValbyteData);
		case LONG:
			return((unsigned int)Ncl_MultiDVallongData);
		case SHORT:
			return((unsigned int)Ncl_MultiDValshortData);
		case FLOAT:
			return((unsigned int)Ncl_MultiDValfloatData);
		case CHARACTER:
			return((unsigned int)Ncl_MultiDValcharData);
		case STRNG:
			return((unsigned int)Ncl_MultiDValstringData);
		case NUMERIC:
			return(NCL_VAL_NUMERIC_MASK);
		case GRAPHIC:
			return((unsigned int)Ncl_MultiDValHLUObjData);
		case LOGICAL:
			return((unsigned int)Ncl_MultiDVallogicalData);
		case FILETYPE:
			return((unsigned int)Ncl_MultiDValnclfileData);
		default:
			return(Ncl_Obj);
		}
	} else {
		return(Ncl_Obj);
	}
}

NclObjTypes _NclBasicDataTypeToObjType
#if __STDC__
(NclBasicDataTypes dt)
#else
(dt)
	NclBasicDataTypes dt;
#endif
{
	switch(dt) {
	case NCL_short:
		return(Ncl_MultiDValshortData);
	case NCL_int:
		return(Ncl_MultiDValintData);
	case NCL_long:
		return(Ncl_MultiDVallongData);
	case NCL_float:
		return(Ncl_MultiDValfloatData);
	case NCL_double:
		return(Ncl_MultiDValdoubleData);
	case NCL_char:
		return(Ncl_MultiDValcharData);
	case NCL_byte:
		return(Ncl_MultiDValbyteData);
	case NCL_string:
		return(Ncl_MultiDValstringData);
	case NCL_logical:
		return(Ncl_MultiDVallogicalData);
	case NCL_nclfile:
		return(Ncl_MultiDValnclfileData);
	default:
		return(Ncl_Obj);
	}
}

NclBasicDataTypes _NclKeywordToDataType
#if  __STDC__
(struct _NclSymbol *keywd)
#else
(keywd)
	struct _NclSymbol *keywd;
#endif
{

	if(keywd != NULL) {
		switch(keywd->type) {
		case INTEGER:
		case GRAPHIC:
			return(NCL_int);
		case DOUBLE:
			return(NCL_double);
		case BYTE:
			return(NCL_byte);
		case LONG:
			return(NCL_long);
		case SHORT:
			return(NCL_short);
		case FLOAT:
			return(NCL_float);
		case CHARACTER:
			return(NCL_char);
		case STRNG:
			return(NCL_string);
		case NUMERIC:
			return(NCL_numeric);
		case LOGICAL:
			return(NCL_logical);
		case FILETYPE:
			return(NCL_nclfile);
		default:
			return(NCL_none);
		}
	} else {
		return(NCL_none);
	}
}


int _NclSizeOf
#if  __STDC__
(NclBasicDataTypes data_type)
#else 
(data_type)
NclBasicDataTypes data_type;
#endif
{
	switch(data_type) {
		case NCL_short:
			return(sizeof(short));
		case NCL_int:
			return(sizeof(int));
		case NCL_long:
			return(sizeof(long));
		case NCL_float:
			return(sizeof(float));
		case NCL_double:
			return(sizeof(double));
		case NCL_char:
			return(sizeof(char));
		case NCL_byte:
			return(sizeof(char));
		case NCL_string:
			return(sizeof(int));	
		case NCL_logical:
			return(sizeof(int));	
		default:
			return(-1);
	}
}

void _NclDestroyObj
#if  __STDC__
(NclObj obj)
#else
(obj)
	NclObj obj;
#endif
{
	if(obj != NULL) {
		if((obj->obj.class_ptr != NULL)
			&&(obj->obj.class_ptr->obj_class.destroy != NULL)) {
			(*obj->obj.class_ptr->obj_class.destroy)(obj);
		} else {
			(void)NclFree((void*)obj);
		}
	} 
}


int _NclScalarCoerce
#if  __STDC__
(void *from,NclBasicDataTypes frtype,void *to,NclBasicDataTypes totype)
#else
(from,frtype,to,totype)
void *from;
NclBasicDataTypes frtype;
void *to;
NclBasicDataTypes totype;
#endif
{
	switch(frtype) {
	case NCL_short:
		switch(totype) {
		case NCL_short:
			*(short*)to= *(short*)from;
			return(1);
		case NCL_long:
			*(long*)to = *(short*)from;
			return(1);
		case NCL_int:
			*(int*)to = *(short*)from;
			return(1);
		case NCL_float:
			*(float*)to = *(short*)from;
			return(1);
		case NCL_double:
			*(double*)to = *(short*)from;
			return(1);
		case NCL_logical:
			*(int*)to = *(short*)from;
			return(1);
		default:
			return(0);
		}
	case NCL_int:
		switch(totype) {
		case NCL_long:
			*(long*)to = *(int*)from;
			return(1);
                case NCL_int:
			*(int*)to = *(int*)from;
			return(1);
                case NCL_float:
			*(float*)to = *(int*)from;
			return(1);
                case NCL_double:
			*(double*)to = *(int*)from;
			return(1);
                case NCL_logical:
			*(int*)to = *(int*)from;
			return(1);
		default:
			return(0);
		}
	case NCL_long:
		switch(totype) {
		case NCL_long:
			*(long*)to = *(long*)from;
			return(1);
		case NCL_float:
			*(float*)to = *(long*)from;
			return(1);
		case NCL_double:
			*(double*)to = *(long*)from;
			return(1);
		case NCL_logical:
			*(int*)to = *(long*)from;
			return(1);
		default:
			return(0);
		}
	case NCL_float:
		switch(totype) {
		case NCL_float:
			*(float*)to = *(float*)from;
			return(1);
		case NCL_double:
			*(double*)to = *(float*)from;
			return(1);
		default:
			return(0);
		}
	case NCL_double:
		switch(totype) {
		case NCL_double:
			*(double*)to = *(double*)from;
			return(1);
		default:
			return(0);
		}
	case NCL_char:
	case NCL_byte:
		switch(totype) {
		case NCL_byte:
		case NCL_char:
			*(char*) to = *(char*)from;
			return(1);
		default:
			return(0);
		}
	case NCL_string:
		switch(totype) {
		case NCL_string:
			*(string*)to = *(string*)from;
			return(1);
		default:
			return(0);
		}
	case NCL_logical:
	default:
		return(0);
	}
}

void _NclPrint
#if  __STDC__
(NclObj obj,FILE *fp)
#else 
(obj,fp)
NclObj obj;
FILE *fp;
#endif
{
	NclObjClass oc;

	if(obj == NULL)  {
		return;
	} else {
		oc = obj->obj.class_ptr;
	}

	while(oc != NULL) {
		if(oc->obj_class.print != NULL)  {
			(*(oc->obj_class.print))(obj,fp);
			return;
		} else {
			oc = oc->obj_class.super_class;
		}
	} 
	return;
}


NclMultiDValData _NclCoerceData
#if  __STDC__
(NclMultiDValData obj, NclObjTypes coerce_to,NclScalar *new_missing)
#else
(obj, coerce_to,new_missing)
NclMultiDValData obj;
NclObjTypes coerce_to;
NclScalar *new_missing;
#endif
{
	NclDataClass oc;
        int f_selection;

	if((obj == NULL)||!(obj->obj.obj_type_mask & NCL_MD_MASK)) {
                return(NULL);
	} else {
		oc = (NclDataClass)obj->obj.class_ptr;
	}

        f_selection = (int)obj->multidval.kind;
	while((NclObjClass)oc != nclObjClass) {
        	if( oc->data_class.coerce[f_selection] != NULL) {
                	return((NclMultiDValData)((*oc->data_class.coerce[f_selection])((NclData)obj,coerce_to,new_missing)));
        	} else {
			oc = (NclDataClass)oc->obj_class.super_class;
		}
	}
}

NhlErrorTypes _NclCallDualOp
#if  __STDC__
(NclMultiDValData lhs_data_obj, NclMultiDValData rhs_data_obj, int operation, NclObj *result)
#else
(lhs_data_obj, rhs_data_obj, operation,result)
NclMultiDValData lhs_data_obj;
NclMultiDValData rhs_data_obj;
int operation;
NclObj *result;
#endif
{
	NclDataClass data_part;
	int f_selection;

	data_part = (NclDataClass)
		((NclDataClass)lhs_data_obj->obj.class_ptr);

	f_selection = (int)
		((lhs_data_obj->multidval.kind<< 1)
		|(rhs_data_obj->multidval.kind));
	*result = NULL;
	while(((NclObjClass) data_part != nclObjClass)&&(*result == NULL)) {
		switch(operation) {
		case MOD_OP:
		if(data_part->data_class.mod[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.mod[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case OR_OP:
		if(data_part->data_class.or[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.or[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case AND_OP:
		if(data_part->data_class.and[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.and[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case XOR_OP:
		if(data_part->data_class.xor[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.xor[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case LTSEL_OP:
		if(data_part->data_class.sel_lt[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.sel_lt[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case GTSEL_OP:
		if(data_part->data_class.sel_gt[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.sel_gt[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case PLUS_OP:
		if(data_part->data_class.plus[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.plus[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case MINUS_OP:
		if(data_part->data_class.minus[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.minus[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case MUL_OP:
		if(data_part->data_class.multiply[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.multiply[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case MAT_OP:
		if(data_part->data_class.mat[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.mat[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case DIV_OP:
		if(data_part->data_class.divide[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.divide[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case EXP_OP:
		if(data_part->data_class.exponent[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.exponent[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case LE_OP:
		if(data_part->data_class.le[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.le[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case GE_OP:
		if(data_part->data_class.ge[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.ge[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case GT_OP:
		if(data_part->data_class.gt[f_selection] != NULL) {
			*result =(NclObj) ((*data_part->data_class.gt[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case LT_OP:
		if(data_part->data_class.lt[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.lt[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case EQ_OP:
		if(data_part->data_class.eq[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.eq[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		case NE_OP:
		if(data_part->data_class.ne[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.ne[f_selection])((NclData)lhs_data_obj,(NclData)rhs_data_obj,NULL));
		}
		break;
		default:
			return(NhlFATAL);
		}
		data_part = (NclDataClass)data_part->obj_class.super_class;
	}
	if(*result != NULL) {
		return(NhlNOERROR);
	} else {
		return(NhlFATAL);
	}

}


NhlErrorTypes _NclCallMonoOp
#if  __STDC__
(NclMultiDValData operand, NclObj *result, int operation)
#else
(operand, result,operation)
NclMultiDValData operand;
NclObj *result;
int operation;
#endif
{
	NclDataClass data_part;
	int f_selection;

	data_part = (NclDataClass)((NclDataClass)operand->obj.class_ptr);

	f_selection = (int)operand->multidval.kind;

	while(((NclObjClass)data_part != nclObjClass)&&(*result == NULL)) { 
		switch(operation) {
		case NOT_OP:
		if(data_part->data_class.not[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.not[f_selection])((NclData)operand,NULL));
		}
		break;
		case NEG_OP:
		if(data_part->data_class.neg[f_selection] != NULL) {
			*result = (NclObj)((*data_part->data_class.neg[f_selection])((NclData)operand,NULL));
		}
		break;
		}
		data_part = (NclDataClass)data_part->obj_class.super_class;
	}

	if(*result != NULL) {
		return(NhlNOERROR);
	} else {
		*result = NULL;
		return(NhlFATAL); 
	}
}



struct _NclMultiDValDataRec* _NclCopyVal
#if     __STDC__
(struct _NclMultiDValDataRec * self,NclScalar *new_missing)
#else
(self,new_missing)
struct _NclMultiDValDataRec * self;
NclScalar *new_missing;
#endif
{
	NclDataClass dc;
	
	if(self == NULL) {
		return(NULL);
	}  else {
		dc = (NclDataClass)self->obj.class_ptr;
	}
	while((NclObjClass)dc != nclObjClass){
		if(dc->data_class.dup != NULL) {
			return((NclMultiDValData)(*dc->data_class.dup)((NclData)self,new_missing));
		} else {
			dc = (NclDataClass)dc->obj_class.super_class;
		}
	}
	return(NULL);
}

void _NclResetMissingValue
#if	__STDC__
(struct _NclMultiDValDataRec * self,NclScalar *missing)
#else
(self,missing)
	struct _NclMultiDValDataRec *self;
	NclScalar *missing;
#endif
{
	NclDataClass dc ;
	
	if((self == NULL)||(missing == NULL)) {
		return;
	} else {
		dc  = (NclDataClass)self->obj.class_ptr;
	}
	while((NclObjClass)dc != nclObjClass) {

		if(dc->data_class.reset_mis != NULL) {
			(*dc->data_class.reset_mis)((NclData)self,missing);
			return;
		} else {
			dc = (NclDataClass)dc->obj_class.super_class;
		}
	}
	return;
}


struct _NclMultiDValDataRec * _NclCreateVal
#if	__STDC__
( NclObj inst, NclObjClass theclass, NclObjTypes obj_type, unsigned int obj_type_mask, void *val, NclScalar *missing_value, int n_dims, int *dim_sizes, NclStatus status, NclSelectionRecord *sel_rec)
#else 
( inst, theclass, obj_type, obj_type_mask, val, missing_value, n_dims, dim_sizes, status, sel_rec)
NclObj inst;
NclObjClass theclass;
NclObjTypes obj_type;
unsigned int obj_type_mask;
void *val;
NclScalar *missing_value;
int n_dims;
int *dim_sizes;
NclStatus status;
NclSelectionRecord *sel_rec;
#endif
{

	switch(obj_type) {
        case Ncl_MultiDValdoubleData:
	        return(_NclMultiDValdoubleCreate(
			inst,
			theclass,
			obj_type,
			obj_type_mask,
			val,
			missing_value,
			n_dims,
			dim_sizes,
			status,
			sel_rec));
        case Ncl_MultiDValfloatData:
        	return(_NclMultiDValfloatCreate(
			inst,
			theclass,
			obj_type,
			obj_type_mask,
			val,
			missing_value,
			n_dims,
			dim_sizes,
			status,
			sel_rec));
        case Ncl_MultiDVallongData:
	        return(_NclMultiDVallongCreate(
			inst,
			theclass,
			obj_type,
			obj_type_mask,
			val,
			missing_value,
			n_dims,
			dim_sizes,
			status,
			sel_rec));
        case Ncl_MultiDValintData:
        	return(_NclMultiDValintCreate(
			inst,
			theclass,
			obj_type,
			obj_type_mask,
			val,
			missing_value,
			n_dims,
			dim_sizes,
			status,
			sel_rec));
        case Ncl_MultiDValshortData:
        	return(_NclMultiDValshortCreate(
			inst,
			theclass,
			obj_type,
			obj_type_mask,
			val,
			missing_value,
			n_dims,
			dim_sizes,
			status,
			sel_rec));
        case Ncl_MultiDValstringData:
       		return(_NclMultiDValstringCreate(
			inst,
			theclass,
			obj_type,
			obj_type_mask,
			val,
			missing_value,
			n_dims,
			dim_sizes,
			status,
			sel_rec));
	case Ncl_MultiDValHLUObjData:
       		return(_NclMultiDValHLUObjDataCreate(
			inst,
			theclass,
			obj_type,
			obj_type_mask,
			val,
			missing_value,
			n_dims,
			dim_sizes,
			status,
			sel_rec));
	case Ncl_MultiDVallogicalData:
       		return(_NclMultiDVallogicalCreate(
			inst,
			theclass,
			obj_type,
			obj_type_mask,
			val,
			missing_value,
			n_dims,
			dim_sizes,
			status,
			sel_rec));
	case Ncl_MultiDValnclfileData:
       		return(_NclMultiDValnclfileCreate(
			inst,
			theclass,
			obj_type,
			obj_type_mask,
			val,
			missing_value,
			n_dims,
			dim_sizes,
			status,
			sel_rec));
	case Ncl_MultiDValcharData:
        default:
                return(NULL);
        }
}


NhlErrorTypes _NclAddParent
#if __STDC__
(struct _NclObjRec * theobj, struct _NclObjRec* parent)
#else
( theobj,  parent)
struct _NclObjRec * theobj;
struct _NclObjRec* parent;
#endif
{
	NclObjClass class_ptr;


	if((theobj == NULL)||(parent == NULL)) 
		return(NhlFATAL);

	class_ptr = theobj->obj.class_ptr;

	while((class_ptr != NULL)&&(class_ptr->obj_class.add_parent == NULL)) {
		class_ptr = class_ptr->obj_class.super_class;
	}
	if(class_ptr == NULL) {
		return(NhlFATAL);
	} else {
		return((*class_ptr->obj_class.add_parent)(theobj,parent));
	}
}

NhlErrorTypes _NclDelParent
#if __STDC__
(struct _NclObjRec * theobj, struct _NclObjRec* parent)
#else
(theobj, parent)
struct _NclObjRec * theobj;
struct _NclObjRec* parent;
#endif
{
	NclObjClass class_ptr;

	if((theobj == NULL)||(parent == NULL)) 
		return(NhlFATAL);

	class_ptr = theobj->obj.class_ptr;

	while((class_ptr != NULL)&&(class_ptr->obj_class.del_parent == NULL)) {
		class_ptr = class_ptr->obj_class.super_class;
	}
	if(class_ptr == NULL) {
		return(NhlFATAL);
	} else {
		return((*class_ptr->obj_class.del_parent)(theobj,parent));
	}
}


extern int _NclGetObjRefCount
#if __STDC__
(int the_id)
#else
(the_id)
	int the_id;
#endif
{
	struct _NclObjRec * the_obj;

	the_obj = _NclGetObj(the_id);
	if(the_obj != NULL) {
		return(the_obj->obj.ref_count);
	} else {
		return(-1);
	}
}



