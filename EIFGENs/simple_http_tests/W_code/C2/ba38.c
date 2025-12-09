/*
 * Code for class BASE64
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern EIF_TYPED_VALUE F38_824(EIF_REFERENCE);
extern EIF_TYPED_VALUE F38_825(EIF_REFERENCE);
extern EIF_TYPED_VALUE F38_826(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F38_827(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F38_828(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void F38_829(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void F38_830(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern void F38_831(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F38_832(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F38_833(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F38_834(EIF_REFERENCE);
extern EIF_TYPED_VALUE F38_835(EIF_REFERENCE, EIF_TYPED_VALUE);
extern void EIF_Minit38(void);

#ifdef __cplusplus
}
#endif

#include "eif_misc.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* {BASE64}.has_error */
EIF_TYPED_VALUE F38_824 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(816,Dtype(Current)));
	return r;
}


/* {BASE64}.has_incorrect_padding */
EIF_TYPED_VALUE F38_825 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = *(EIF_BOOLEAN *)(Current + RTWA(817,Dtype(Current)));
	return r;
}


/* {BASE64}.bytes_encoded_string */
EIF_TYPED_VALUE F38_826 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "bytes_encoded_string";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc3 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc4 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc5 = (EIF_INTEGER_32) 0;
	EIF_REFERENCE loc6 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_NATURAL_8 tu1_1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(7);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,loc6);
	RTLR(3,tr1);
	RTLR(4,Result);
	RTLR(5,ur1);
	RTLR(6,ur2);
	RTLIU(7);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_INT32, &loc3);
	RTLU(SK_INT32, &loc4);
	RTLU(SK_INT32, &loc5);
	RTLU(SK_REF, &loc6);
	
	RTEAA(l_feature_name, 37, Current, 6, 1, 920);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(37, Current, 920);
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,669,266,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		RTCC(arg1, 37, l_feature_name, 1, typres0, 0x01);
	}
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 816, 0x04000000, 1); /* has_error */
	*(EIF_BOOLEAN *)(Current + RTWA(816, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 0;
	RTHOOK(2);
	RTDBGAL(6, 0xF8000124, 0, 0); /* loc6 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(826, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc6 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(3443, "upper", arg1))(arg1)).it_i4);
	ti4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(3442, "lower", arg1))(arg1)).it_i4);
	loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) (((EIF_INTEGER_32) 4L) * (EIF_INTEGER_32) ((EIF_INTEGER_32) ((EIF_INTEGER_32) ((EIF_INTEGER_32) (ti4_1 - ti4_2) + ((EIF_INTEGER_32) 1L)) + ((EIF_INTEGER_32) 2L)) / ((EIF_INTEGER_32) 3L)));
	RTHOOK(4);
	RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(3442, "lower", arg1))(arg1)).it_i4);
	loc1 = (EIF_INTEGER_32) ti4_1;
	RTHOOK(5);
	RTDBGAL(0, 0xF8000126, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(294, 0x01).id);
	ui4_1 = loc2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(4836, Dtype(tr1)))(tr1, ui4_1x);
	RTNHOOK(5,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(6);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(3443, "upper", arg1))(arg1)).it_i4);
	loc2 = (EIF_INTEGER_32) ti4_1;
	for (;;) {
		RTHOOK(7);
		if ((EIF_BOOLEAN) (loc1 > loc2)) break;
		RTHOOK(8);
		RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
		ui4_1 = loc1;
		tu1_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3441, "item", arg1))(arg1, ui4_1x)).it_n1);
		ti4_1 = (EIF_INTEGER_32) tu1_1;
		loc3 = (EIF_INTEGER_32) ti4_1;
		RTHOOK(9);
		if ((EIF_BOOLEAN) (loc1 < loc2)) {
			RTHOOK(10);
			RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
			loc1++;
			RTHOOK(11);
			RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
			ui4_1 = loc1;
			tu1_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3441, "item", arg1))(arg1, ui4_1x)).it_n1);
			ti4_1 = (EIF_INTEGER_32) tu1_1;
			loc4 = (EIF_INTEGER_32) ti4_1;
			RTHOOK(12);
			if ((EIF_BOOLEAN) (loc1 < loc2)) {
				RTHOOK(13);
				RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
				loc1++;
				RTHOOK(14);
				RTDBGAL(5, 0x10000000, 1, 0); /* loc5 */
				ui4_1 = loc1;
				tu1_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3441, "item", arg1))(arg1, ui4_1x)).it_n1);
				ti4_1 = (EIF_INTEGER_32) tu1_1;
				loc5 = (EIF_INTEGER_32) ti4_1;
			} else {
				RTHOOK(15);
				RTDBGAL(5, 0x10000000, 1, 0); /* loc5 */
				loc5 = (EIF_INTEGER_32) ((EIF_INTEGER_32) -1L);
			}
		} else {
			RTHOOK(16);
			RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
			loc4 = (EIF_INTEGER_32) ((EIF_INTEGER_32) -1L);
		}
		RTHOOK(17);
		ui4_1 = loc3;
		ui4_2 = loc4;
		ui4_3 = loc5;
		ur1 = RTCCL(loc6);
		ur2 = RTCCL(Result);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(823, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ur1x, ur2x);
		RTHOOK(18);
		RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
		loc1++;
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(19);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(9);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ur1
#undef ur2
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef arg1
}

/* {BASE64}.encoded_string */
EIF_TYPED_VALUE F38_827 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "encoded_string";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc3 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc4 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc5 = (EIF_INTEGER_32) 0;
	EIF_REFERENCE loc6 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_NATURAL_32 tu4_1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(7);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLR(2,loc6);
	RTLR(3,tr1);
	RTLR(4,Result);
	RTLR(5,ur1);
	RTLR(6,ur2);
	RTLIU(7);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_INT32, &loc3);
	RTLU(SK_INT32, &loc4);
	RTLU(SK_INT32, &loc5);
	RTLU(SK_REF, &loc6);
	
	RTEAA(l_feature_name, 37, Current, 6, 1, 921);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(37, Current, 921);
	RTCC(arg1, 37, l_feature_name, 1, eif_new_type(292, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 816, 0x04000000, 1); /* has_error */
	*(EIF_BOOLEAN *)(Current + RTWA(816, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 0;
	RTHOOK(2);
	RTDBGAL(6, 0xF8000124, 0, 0); /* loc6 */
	tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(826, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
	loc6 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(3);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(4998, "count", arg1));
	loc2 = (EIF_INTEGER_32) (EIF_INTEGER_32) (((EIF_INTEGER_32) 4L) * (EIF_INTEGER_32) ((EIF_INTEGER_32) (ti4_1 + ((EIF_INTEGER_32) 2L)) / ((EIF_INTEGER_32) 3L)));
	RTHOOK(4);
	RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
	loc1 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 1L);
	RTHOOK(5);
	RTDBGAL(0, 0xF8000126, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(294, 0x01).id);
	ui4_1 = loc2;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(4836, Dtype(tr1)))(tr1, ui4_1x);
	RTNHOOK(5,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(6);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(4998, "count", arg1));
	loc2 = (EIF_INTEGER_32) ti4_1;
	for (;;) {
		RTHOOK(7);
		if ((EIF_BOOLEAN) (loc1 > loc2)) break;
		RTHOOK(8);
		RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
		ui4_1 = loc1;
		tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4838, "code", arg1))(arg1, ui4_1x)).it_n4);
		ti4_1 = (EIF_INTEGER_32) tu4_1;
		loc3 = (EIF_INTEGER_32) ti4_1;
		RTHOOK(9);
		if ((EIF_BOOLEAN) (loc1 < loc2)) {
			RTHOOK(10);
			RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
			loc1++;
			RTHOOK(11);
			RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
			ui4_1 = loc1;
			tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4838, "code", arg1))(arg1, ui4_1x)).it_n4);
			ti4_1 = (EIF_INTEGER_32) tu4_1;
			loc4 = (EIF_INTEGER_32) ti4_1;
			RTHOOK(12);
			if ((EIF_BOOLEAN) (loc1 < loc2)) {
				RTHOOK(13);
				RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
				loc1++;
				RTHOOK(14);
				RTDBGAL(5, 0x10000000, 1, 0); /* loc5 */
				ui4_1 = loc1;
				tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4838, "code", arg1))(arg1, ui4_1x)).it_n4);
				ti4_1 = (EIF_INTEGER_32) tu4_1;
				loc5 = (EIF_INTEGER_32) ti4_1;
			} else {
				RTHOOK(15);
				RTDBGAL(5, 0x10000000, 1, 0); /* loc5 */
				loc5 = (EIF_INTEGER_32) ((EIF_INTEGER_32) -1L);
			}
		} else {
			RTHOOK(16);
			RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
			loc4 = (EIF_INTEGER_32) ((EIF_INTEGER_32) -1L);
		}
		RTHOOK(17);
		ui4_1 = loc3;
		ui4_2 = loc4;
		ui4_3 = loc5;
		ur1 = RTCCL(loc6);
		ur2 = RTCCL(Result);
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(823, dtype))(Current, ui4_1x, ui4_2x, ui4_3x, ur1x, ur2x);
		RTHOOK(18);
		RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
		loc1++;
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(19);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(9);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef up1
#undef ur1
#undef ur2
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef arg1
}

/* {BASE64}.decoded_string */
EIF_TYPED_VALUE F38_828 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "decoded_string";
	RTEX;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_REFERENCE Result = ((EIF_REFERENCE) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(6);
	RTLR(0,arg1);
	RTLR(1,tr1);
	RTLR(2,Result);
	RTLR(3,ur1);
	RTLR(4,ur2);
	RTLR(5,Current);
	RTLIU(6);
	RTLU (SK_REF, &Result);
	RTLU(SK_REF,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 37, Current, 0, 1, 922);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(37, Current, 922);
	RTCC(arg1, 37, l_feature_name, 1, eif_new_type(292, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(0, 0xF8000126, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(294, 0x01).id);
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(4998, "count", arg1));
	ui4_1 = ti4_1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(4836, Dtype(tr1)))(tr1, ui4_1x);
	RTNHOOK(1,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	ur1 = RTCCL(arg1);
	ur2 = RTCCL(Result);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(821, dtype))(Current, ur1x, ur2x);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(3);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ur1
#undef ur2
#undef ui4_1
#undef arg1
}

/* {BASE64}.decode_string_to_buffer */
void F38_829 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "decode_string_to_buffer";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc3 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc4 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc5 = (EIF_INTEGER_32) 0;
	EIF_REFERENCE loc6 = (EIF_REFERENCE) 0;
	EIF_INTEGER_32 loc7 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc8 = (EIF_INTEGER_32) 0;
	EIF_BOOLEAN loc9 = (EIF_BOOLEAN) 0;
	EIF_CHARACTER_8 loc10 = (EIF_CHARACTER_8) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_TYPED_VALUE uc1x = {{0}, SK_CHAR8};
#define uc1 uc1x.it_c1
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	EIF_CHARACTER_8 tc1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(6);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,Current);
	RTLR(3,loc6);
	RTLR(4,tr1);
	RTLR(5,ur1);
	RTLIU(6);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_INT32, &loc3);
	RTLU(SK_INT32, &loc4);
	RTLU(SK_INT32, &loc5);
	RTLU(SK_REF, &loc6);
	RTLU(SK_INT32, &loc7);
	RTLU(SK_INT32, &loc8);
	RTLU(SK_BOOL, &loc9);
	RTLU(SK_CHAR8, &loc10);
	
	RTEAA(l_feature_name, 37, Current, 10, 2, 923);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(37, Current, 923);
	RTCC(arg1, 37, l_feature_name, 1, eif_new_type(292, 0x01), 0x01);
	RTCC(arg2, 37, l_feature_name, 2, eif_new_type(294, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAA(Current, dtype, 816, 0x04000000, 1); /* has_error */
	*(EIF_BOOLEAN *)(Current + RTWA(816, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 0;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 817, 0x04000000, 1); /* has_incorrect_padding */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(4998, "count", arg1));
	*(EIF_BOOLEAN *)(Current + RTWA(817, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN)((EIF_INTEGER_32) (ti4_1 % ((EIF_INTEGER_32) 4L)) != ((EIF_INTEGER_32) 0L));
	RTHOOK(3);
	RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(4998, "count", arg1));
	loc3 = (EIF_INTEGER_32) ti4_1;
	RTHOOK(4);
	RTDBGAL(5, 0x10000000, 1, 0); /* loc5 */
	loc5 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 4L);
	RTHOOK(5);
	RTDBGAL(6, 0xF80001C9, 0, 0); /* loc6 */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,457,284,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		tr1 = RTLN(typres0.id);
	}
	ui4_1 = ((EIF_INTEGER_32) 0L);
	ui4_2 = ((EIF_INTEGER_32) 1L);
	ui4_3 = loc5;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(3466, Dtype(tr1)))(tr1, ui4_1x, ui4_2x, ui4_3x);
	RTNHOOK(5,1);
	loc6 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(6);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	loc2 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
	if (RTAL & CK_LOOP) {
		RTHOOK(7);
		RTCT("n = v.count", EX_LINV);
		ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(4998, "count", arg1));
		if ((EIF_BOOLEAN)(loc3 == ti4_1)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	for (;;) {
		RTHOOK(8);
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) (loc2 >= loc3) || loc9)) break;
		RTHOOK(9);
		RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
		loc1 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
		RTHOOK(10);
		RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
		loc4 = (EIF_INTEGER_32) (EIF_INTEGER_32) (loc1 + ((EIF_INTEGER_32) 1L));
		for (;;) {
			RTHOOK(11);
			tb1 = *(EIF_BOOLEAN *)(Current + RTWA(816, dtype));
			if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (loc4 > loc5) || tb1) || (EIF_BOOLEAN) (loc2 >= loc3))) break;
			RTHOOK(12);
			if ((EIF_BOOLEAN) (loc2 < loc3)) {
				RTHOOK(13);
				RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
				ur1 = RTCCL(arg1);
				ui4_1 = loc2;
				ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(824, dtype))(Current, ur1x, ui4_1x)).it_i4);
				loc2 = (EIF_INTEGER_32) ti4_1;
				RTHOOK(14);
				if ((EIF_BOOLEAN) (loc2 <= loc3)) {
					RTHOOK(15);
					RTDBGAL(10, 0x08000000, 1, 0); /* loc10 */
					ui4_1 = loc2;
					tc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3441, "item", arg1))(arg1, ui4_1x)).it_c1);
					loc10 = (EIF_CHARACTER_8) tc1;
					RTHOOK(16);
					if ((EIF_BOOLEAN)(loc10 != (EIF_CHARACTER_8) '=')) {
						RTHOOK(17);
						uc1 = loc10;
						ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(827, dtype))(Current, uc1x)).it_i4);
						ui4_1 = ti4_1;
						ui4_2 = loc4;
						(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(3152, "put", loc6))(loc6, ui4_1x, ui4_2x);
						RTHOOK(18);
						RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
						loc1++;
					}
				} else {
					RTHOOK(19);
					RTDBGAA(Current, dtype, 816, 0x04000000, 1); /* has_error */
					*(EIF_BOOLEAN *)(Current + RTWA(816, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
				}
			} else {
				RTHOOK(20);
				RTDBGAA(Current, dtype, 817, 0x04000000, 1); /* has_incorrect_padding */
				*(EIF_BOOLEAN *)(Current + RTWA(817, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
				RTHOOK(21);
				uc1 = loc10;
				ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(827, dtype))(Current, uc1x)).it_i4);
				ui4_1 = ti4_1;
				ui4_2 = loc4;
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(3152, "put", loc6))(loc6, ui4_1x, ui4_2x);
				RTHOOK(22);
				RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
				loc1++;
			}
			RTHOOK(23);
			RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
			loc4++;
		}
		RTHOOK(24);
		RTDBGAL(9, 0x04000000, 1, 0); /* loc9 */
		loc9 = (EIF_BOOLEAN) (EIF_BOOLEAN) (loc1 < loc5);
		RTHOOK(25);
		if ((EIF_BOOLEAN) (loc1 > ((EIF_INTEGER_32) 1L))) {
			RTHOOK(26);
			RTDBGAL(7, 0x10000000, 1, 0); /* loc7 */
			ui4_1 = ((EIF_INTEGER_32) 1L);
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3149, "item", loc6))(loc6, ui4_1x)).it_i4);
			ui4_1 = ((EIF_INTEGER_32) 2L);
			ti4_2 = eif_bit_shift_left(ti4_1,ui4_1);
			ui4_1 = ((EIF_INTEGER_32) 255L);
			ti4_1 = eif_bit_and(ti4_2,ui4_1);
			loc7 = (EIF_INTEGER_32) ti4_1;
			RTHOOK(27);
			RTDBGAL(8, 0x10000000, 1, 0); /* loc8 */
			ui4_1 = ((EIF_INTEGER_32) 2L);
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3149, "item", loc6))(loc6, ui4_1x)).it_i4);
			ui4_1 = ((EIF_INTEGER_32) 4L);
			ti4_2 = eif_bit_shift_right(ti4_1,ui4_1);
			ui4_1 = ((EIF_INTEGER_32) 3L);
			ti4_1 = eif_bit_and(ti4_2,ui4_1);
			loc8 = (EIF_INTEGER_32) ti4_1;
			RTHOOK(28);
			ui4_1 = loc8;
			ti4_1 = eif_bit_or(loc7,ui4_1);
			tc1 = (EIF_CHARACTER_8) ti4_1;
			uc1 = tc1;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3143, "extend", arg2))(arg2, uc1x);
			RTHOOK(29);
			if ((EIF_BOOLEAN) (loc1 > ((EIF_INTEGER_32) 2L))) {
				RTHOOK(30);
				RTDBGAL(7, 0x10000000, 1, 0); /* loc7 */
				ui4_1 = ((EIF_INTEGER_32) 2L);
				ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3149, "item", loc6))(loc6, ui4_1x)).it_i4);
				ui4_1 = ((EIF_INTEGER_32) 4L);
				ti4_2 = eif_bit_shift_left(ti4_1,ui4_1);
				ui4_1 = ((EIF_INTEGER_32) 255L);
				ti4_1 = eif_bit_and(ti4_2,ui4_1);
				loc7 = (EIF_INTEGER_32) ti4_1;
				RTHOOK(31);
				RTDBGAL(8, 0x10000000, 1, 0); /* loc8 */
				ui4_1 = ((EIF_INTEGER_32) 3L);
				ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3149, "item", loc6))(loc6, ui4_1x)).it_i4);
				ui4_1 = ((EIF_INTEGER_32) 2L);
				ti4_2 = eif_bit_shift_right(ti4_1,ui4_1);
				ui4_1 = ((EIF_INTEGER_32) 15L);
				ti4_1 = eif_bit_and(ti4_2,ui4_1);
				loc8 = (EIF_INTEGER_32) ti4_1;
				RTHOOK(32);
				ui4_1 = loc8;
				ti4_1 = eif_bit_or(loc7,ui4_1);
				tc1 = (EIF_CHARACTER_8) ti4_1;
				uc1 = tc1;
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3143, "extend", arg2))(arg2, uc1x);
				RTHOOK(33);
				if ((EIF_BOOLEAN) (loc1 > ((EIF_INTEGER_32) 3L))) {
					RTHOOK(34);
					RTDBGAL(7, 0x10000000, 1, 0); /* loc7 */
					ui4_1 = ((EIF_INTEGER_32) 4L);
					ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3149, "item", loc6))(loc6, ui4_1x)).it_i4);
					loc7 = (EIF_INTEGER_32) ti4_1;
					RTHOOK(35);
					RTDBGAL(8, 0x10000000, 1, 0); /* loc8 */
					ui4_1 = ((EIF_INTEGER_32) 3L);
					ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3149, "item", loc6))(loc6, ui4_1x)).it_i4);
					ui4_1 = ((EIF_INTEGER_32) 6L);
					ti4_2 = eif_bit_shift_left(ti4_1,ui4_1);
					ui4_1 = ((EIF_INTEGER_32) 255L);
					ti4_1 = eif_bit_and(ti4_2,ui4_1);
					loc8 = (EIF_INTEGER_32) ti4_1;
					RTHOOK(36);
					ui4_1 = loc8;
					ti4_1 = eif_bit_or(loc7,ui4_1);
					tc1 = (EIF_CHARACTER_8) ti4_1;
					uc1 = tc1;
					(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3143, "extend", arg2))(arg2, uc1x);
				}
			}
		}
		if (RTAL & CK_LOOP) {
			RTHOOK(7);
			RTCT("n = v.count", EX_LINV);
			ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(4998, "count", arg1));
			if ((EIF_BOOLEAN)(loc3 == ti4_1)) {
				RTCK;
			} else {
				RTCF;
			}
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(37);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(14);
	RTEE;
#undef ur1
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef uc1
#undef arg2
#undef arg1
}

/* {BASE64}.decode_string_to_output_medium */
void F38_830 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "decode_string_to_output_medium";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc2 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc3 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc4 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc5 = (EIF_INTEGER_32) 0;
	EIF_REFERENCE loc6 = (EIF_REFERENCE) 0;
	EIF_INTEGER_32 loc7 = (EIF_INTEGER_32) 0;
	EIF_INTEGER_32 loc8 = (EIF_INTEGER_32) 0;
	EIF_BOOLEAN loc9 = (EIF_BOOLEAN) 0;
	EIF_CHARACTER_8 loc10 = (EIF_CHARACTER_8) 0;
	EIF_REFERENCE loc11 = (EIF_REFERENCE) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE ui4_2x = {{0}, SK_INT32};
#define ui4_2 ui4_2x.it_i4
	EIF_TYPED_VALUE ui4_3x = {{0}, SK_INT32};
#define ui4_3 ui4_3x.it_i4
	EIF_TYPED_VALUE uc1x = {{0}, SK_CHAR8};
#define uc1 uc1x.it_c1
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_BOOLEAN tb1;
	EIF_CHARACTER_8 tc1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(7);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,Current);
	RTLR(3,loc11);
	RTLR(4,tr1);
	RTLR(5,loc6);
	RTLR(6,ur1);
	RTLIU(7);
	RTLU (SK_VOID, NULL);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	RTLU(SK_INT32, &loc2);
	RTLU(SK_INT32, &loc3);
	RTLU(SK_INT32, &loc4);
	RTLU(SK_INT32, &loc5);
	RTLU(SK_REF, &loc6);
	RTLU(SK_INT32, &loc7);
	RTLU(SK_INT32, &loc8);
	RTLU(SK_BOOL, &loc9);
	RTLU(SK_CHAR8, &loc10);
	RTLU(SK_REF, &loc11);
	
	RTEAA(l_feature_name, 37, Current, 11, 2, 924);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(37, Current, 924);
	RTCC(arg1, 37, l_feature_name, 1, eif_new_type(292, 0x01), 0x01);
	RTCC(arg2, 37, l_feature_name, 2, eif_new_type(193, 0x01), 0x01);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("a_output_writable", EX_PRE);
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(2544, "is_open_write", arg2))(arg2)).it_b);
		RTTE(tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	RTDBGAA(Current, dtype, 816, 0x04000000, 1); /* has_error */
	*(EIF_BOOLEAN *)(Current + RTWA(816, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 0;
	RTHOOK(3);
	RTDBGAA(Current, dtype, 817, 0x04000000, 1); /* has_incorrect_padding */
	*(EIF_BOOLEAN *)(Current + RTWA(817, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 0;
	RTHOOK(4);
	RTDBGAL(11, 0xF8000126, 0, 0); /* loc11 */
	tr1 = RTLN(eif_new_type(294, 0x01).id);
	ui4_1 = ((EIF_INTEGER_32) 10L);
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(4836, Dtype(tr1)))(tr1, ui4_1x);
	RTNHOOK(4,1);
	loc11 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(5);
	RTDBGAL(3, 0x10000000, 1, 0); /* loc3 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(4998, "count", arg1));
	loc3 = (EIF_INTEGER_32) ti4_1;
	RTHOOK(6);
	RTDBGAL(5, 0x10000000, 1, 0); /* loc5 */
	loc5 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 4L);
	RTHOOK(7);
	RTDBGAL(6, 0xF80001C9, 0, 0); /* loc6 */
	{
		static EIF_TYPE_INDEX typarr0[] = {0xFF01,457,284,0xFFFF};
		EIF_TYPE typres0;
		static EIF_TYPE typcache0 = {INVALID_DTYPE, 0};
		
		typres0 = (typcache0.id != INVALID_DTYPE ? typcache0 : (typcache0 = eif_compound_id(Dftype(Current), typarr0)));
		tr1 = RTLN(typres0.id);
	}
	ui4_1 = ((EIF_INTEGER_32) 0L);
	ui4_2 = ((EIF_INTEGER_32) 1L);
	ui4_3 = loc5;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWC(3466, Dtype(tr1)))(tr1, ui4_1x, ui4_2x, ui4_3x);
	RTNHOOK(7,1);
	loc6 = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(8);
	RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
	loc2 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
	if (RTAL & CK_LOOP) {
		RTHOOK(9);
		RTCT("n = v.count", EX_LINV);
		ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(4998, "count", arg1));
		if ((EIF_BOOLEAN)(loc3 == ti4_1)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	for (;;) {
		RTHOOK(10);
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) (loc2 >= loc3) || loc9)) break;
		RTHOOK(11);
		RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
		loc1 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
		RTHOOK(12);
		RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
		loc4 = (EIF_INTEGER_32) (EIF_INTEGER_32) (loc1 + ((EIF_INTEGER_32) 1L));
		for (;;) {
			RTHOOK(13);
			tb1 = *(EIF_BOOLEAN *)(Current + RTWA(816, dtype));
			if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_BOOLEAN) (loc4 > loc5) || tb1) || (EIF_BOOLEAN) (loc2 >= loc3))) break;
			RTHOOK(14);
			if ((EIF_BOOLEAN) (loc2 < loc3)) {
				RTHOOK(15);
				RTDBGAL(2, 0x10000000, 1, 0); /* loc2 */
				ur1 = RTCCL(arg1);
				ui4_1 = loc2;
				ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(824, dtype))(Current, ur1x, ui4_1x)).it_i4);
				loc2 = (EIF_INTEGER_32) ti4_1;
				RTHOOK(16);
				if ((EIF_BOOLEAN) (loc2 <= loc3)) {
					RTHOOK(17);
					RTDBGAL(10, 0x08000000, 1, 0); /* loc10 */
					ui4_1 = loc2;
					tc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3441, "item", arg1))(arg1, ui4_1x)).it_c1);
					loc10 = (EIF_CHARACTER_8) tc1;
					RTHOOK(18);
					if ((EIF_BOOLEAN)(loc10 != (EIF_CHARACTER_8) '=')) {
						RTHOOK(19);
						uc1 = loc10;
						ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(827, dtype))(Current, uc1x)).it_i4);
						ui4_1 = ti4_1;
						ui4_2 = loc4;
						(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(3152, "put", loc6))(loc6, ui4_1x, ui4_2x);
						RTHOOK(20);
						RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
						loc1++;
					}
				} else {
					RTHOOK(21);
					RTDBGAA(Current, dtype, 816, 0x04000000, 1); /* has_error */
					*(EIF_BOOLEAN *)(Current + RTWA(816, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
				}
			} else {
				RTHOOK(22);
				RTDBGAA(Current, dtype, 817, 0x04000000, 1); /* has_incorrect_padding */
				*(EIF_BOOLEAN *)(Current + RTWA(817, dtype)) = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
				RTHOOK(23);
				uc1 = loc10;
				ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(827, dtype))(Current, uc1x)).it_i4);
				ui4_1 = ti4_1;
				ui4_2 = loc4;
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(3152, "put", loc6))(loc6, ui4_1x, ui4_2x);
				RTHOOK(24);
				RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
				loc1++;
			}
			RTHOOK(25);
			RTDBGAL(4, 0x10000000, 1, 0); /* loc4 */
			loc4++;
		}
		RTHOOK(26);
		RTDBGAL(9, 0x04000000, 1, 0); /* loc9 */
		loc9 = (EIF_BOOLEAN) (EIF_BOOLEAN) (loc1 < loc5);
		RTHOOK(27);
		if ((EIF_BOOLEAN) (loc1 > ((EIF_INTEGER_32) 1L))) {
			RTHOOK(28);
			RTDBGAL(7, 0x10000000, 1, 0); /* loc7 */
			ui4_1 = ((EIF_INTEGER_32) 1L);
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3149, "item", loc6))(loc6, ui4_1x)).it_i4);
			ui4_1 = ((EIF_INTEGER_32) 2L);
			ti4_2 = eif_bit_shift_left(ti4_1,ui4_1);
			ui4_1 = ((EIF_INTEGER_32) 255L);
			ti4_1 = eif_bit_and(ti4_2,ui4_1);
			loc7 = (EIF_INTEGER_32) ti4_1;
			RTHOOK(29);
			RTDBGAL(8, 0x10000000, 1, 0); /* loc8 */
			ui4_1 = ((EIF_INTEGER_32) 2L);
			ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3149, "item", loc6))(loc6, ui4_1x)).it_i4);
			ui4_1 = ((EIF_INTEGER_32) 4L);
			ti4_2 = eif_bit_shift_right(ti4_1,ui4_1);
			ui4_1 = ((EIF_INTEGER_32) 3L);
			ti4_1 = eif_bit_and(ti4_2,ui4_1);
			loc8 = (EIF_INTEGER_32) ti4_1;
			RTHOOK(30);
			ui4_1 = loc8;
			ti4_1 = eif_bit_or(loc7,ui4_1);
			tc1 = (EIF_CHARACTER_8) ti4_1;
			uc1 = tc1;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3143, "extend", loc11))(loc11, uc1x);
			RTHOOK(31);
			if ((EIF_BOOLEAN) (loc1 > ((EIF_INTEGER_32) 2L))) {
				RTHOOK(32);
				RTDBGAL(7, 0x10000000, 1, 0); /* loc7 */
				ui4_1 = ((EIF_INTEGER_32) 2L);
				ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3149, "item", loc6))(loc6, ui4_1x)).it_i4);
				ui4_1 = ((EIF_INTEGER_32) 4L);
				ti4_2 = eif_bit_shift_left(ti4_1,ui4_1);
				ui4_1 = ((EIF_INTEGER_32) 255L);
				ti4_1 = eif_bit_and(ti4_2,ui4_1);
				loc7 = (EIF_INTEGER_32) ti4_1;
				RTHOOK(33);
				RTDBGAL(8, 0x10000000, 1, 0); /* loc8 */
				ui4_1 = ((EIF_INTEGER_32) 3L);
				ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3149, "item", loc6))(loc6, ui4_1x)).it_i4);
				ui4_1 = ((EIF_INTEGER_32) 2L);
				ti4_2 = eif_bit_shift_right(ti4_1,ui4_1);
				ui4_1 = ((EIF_INTEGER_32) 15L);
				ti4_1 = eif_bit_and(ti4_2,ui4_1);
				loc8 = (EIF_INTEGER_32) ti4_1;
				RTHOOK(34);
				ui4_1 = loc8;
				ti4_1 = eif_bit_or(loc7,ui4_1);
				tc1 = (EIF_CHARACTER_8) ti4_1;
				uc1 = tc1;
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3143, "extend", loc11))(loc11, uc1x);
				RTHOOK(35);
				if ((EIF_BOOLEAN) (loc1 > ((EIF_INTEGER_32) 3L))) {
					RTHOOK(36);
					RTDBGAL(7, 0x10000000, 1, 0); /* loc7 */
					ui4_1 = ((EIF_INTEGER_32) 4L);
					ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3149, "item", loc6))(loc6, ui4_1x)).it_i4);
					loc7 = (EIF_INTEGER_32) ti4_1;
					RTHOOK(37);
					RTDBGAL(8, 0x10000000, 1, 0); /* loc8 */
					ui4_1 = ((EIF_INTEGER_32) 3L);
					ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3149, "item", loc6))(loc6, ui4_1x)).it_i4);
					ui4_1 = ((EIF_INTEGER_32) 6L);
					ti4_2 = eif_bit_shift_left(ti4_1,ui4_1);
					ui4_1 = ((EIF_INTEGER_32) 255L);
					ti4_1 = eif_bit_and(ti4_2,ui4_1);
					loc8 = (EIF_INTEGER_32) ti4_1;
					RTHOOK(38);
					ui4_1 = loc8;
					ti4_1 = eif_bit_or(loc7,ui4_1);
					tc1 = (EIF_CHARACTER_8) ti4_1;
					uc1 = tc1;
					(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3143, "extend", loc11))(loc11, uc1x);
				}
			}
			RTHOOK(39);
			ur1 = RTCCL(loc11);
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(2555, "put_string", arg2))(arg2, ur1x);
			RTHOOK(40);
			(FUNCTION_CAST(void, (EIF_REFERENCE)) RTVF(4963, "wipe_out", loc11))(loc11);
		}
		if (RTAL & CK_LOOP) {
			RTHOOK(9);
			RTCT("n = v.count", EX_LINV);
			ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(4998, "count", arg1));
			if ((EIF_BOOLEAN)(loc3 == ti4_1)) {
				RTCK;
			} else {
				RTCF;
			}
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(41);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(15);
	RTEE;
#undef ur1
#undef ui4_1
#undef ui4_2
#undef ui4_3
#undef uc1
#undef arg2
#undef arg1
}

/* {BASE64}.append_triple_encoded_to */
void F38_831 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x, EIF_TYPED_VALUE arg4x, EIF_TYPED_VALUE arg5x)
{
	GTCX
	char *l_feature_name = "append_triple_encoded_to";
	RTEX;
#define arg1 arg1x.it_i4
#define arg2 arg2x.it_i4
#define arg3 arg3x.it_i4
#define arg4 arg4x.it_r
#define arg5 arg5x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE uc1x = {{0}, SK_CHAR8};
#define uc1 uc1x.it_c1
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 ti4_2;
	EIF_INTEGER_32 ti4_3;
	EIF_CHARACTER_8 tc1;
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg3x.type & SK_HEAD) == SK_REF) arg3x.it_i4 = * (EIF_INTEGER_32 *) arg3x.it_r;
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_i4 = * (EIF_INTEGER_32 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_i4 = * (EIF_INTEGER_32 *) arg1x.it_r;
	
	RTLI(3);
	RTLR(0,arg4);
	RTLR(1,arg5);
	RTLR(2,Current);
	RTLIU(3);
	RTLU (SK_VOID, NULL);
	RTLU(SK_INT32,&arg1);
	RTLU(SK_INT32,&arg2);
	RTLU(SK_INT32,&arg3);
	RTLU(SK_REF,&arg4);
	RTLU(SK_REF,&arg5);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 37, Current, 0, 5, 925);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(37, Current, 925);
	RTCC(arg4, 37, l_feature_name, 4, eif_new_type(292, 0x01), 0x01);
	RTCC(arg5, 37, l_feature_name, 5, eif_new_type(294, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	ui4_1 = ((EIF_INTEGER_32) 2L);
	ti4_1 = eif_bit_shift_right(arg1,ui4_1);
	ui4_1 = (EIF_INTEGER_32) (((EIF_INTEGER_32) 1L) + ti4_1);
	tc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3441, "item", arg4))(arg4, ui4_1x)).it_c1);
	uc1 = tc1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3143, "extend", arg5))(arg5, uc1x);
	RTHOOK(2);
	if ((EIF_BOOLEAN) (arg2 >= ((EIF_INTEGER_32) 0L))) {
		RTHOOK(3);
		ui4_1 = ((EIF_INTEGER_32) 4L);
		ti4_1 = eif_bit_shift_left(arg1,ui4_1);
		ui4_1 = ((EIF_INTEGER_32) 63L);
		ti4_2 = eif_bit_and(ti4_1,ui4_1);
		ui4_1 = ((EIF_INTEGER_32) 4L);
		ti4_1 = eif_bit_shift_right(arg2,ui4_1);
		ui4_1 = ((EIF_INTEGER_32) 63L);
		ti4_3 = eif_bit_and(ti4_1,ui4_1);
		ui4_1 = (EIF_INTEGER_32) ((EIF_INTEGER_32) (((EIF_INTEGER_32) 1L) + ti4_2) + ti4_3);
		tc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3441, "item", arg4))(arg4, ui4_1x)).it_c1);
		uc1 = tc1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3143, "extend", arg5))(arg5, uc1x);
		RTHOOK(4);
		if ((EIF_BOOLEAN) (arg3 >= ((EIF_INTEGER_32) 0L))) {
			RTHOOK(5);
			ui4_1 = ((EIF_INTEGER_32) 2L);
			ti4_1 = eif_bit_shift_left(arg2,ui4_1);
			ui4_1 = ((EIF_INTEGER_32) 63L);
			ti4_2 = eif_bit_and(ti4_1,ui4_1);
			ui4_1 = ((EIF_INTEGER_32) 6L);
			ti4_1 = eif_bit_shift_right(arg3,ui4_1);
			ui4_1 = ((EIF_INTEGER_32) 63L);
			ti4_3 = eif_bit_and(ti4_1,ui4_1);
			ui4_1 = (EIF_INTEGER_32) ((EIF_INTEGER_32) (((EIF_INTEGER_32) 1L) + ti4_2) + ti4_3);
			tc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3441, "item", arg4))(arg4, ui4_1x)).it_c1);
			uc1 = tc1;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3143, "extend", arg5))(arg5, uc1x);
			RTHOOK(6);
			ui4_1 = ((EIF_INTEGER_32) 63L);
			ti4_1 = eif_bit_and(arg3,ui4_1);
			ui4_1 = (EIF_INTEGER_32) (((EIF_INTEGER_32) 1L) + ti4_1);
			tc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3441, "item", arg4))(arg4, ui4_1x)).it_c1);
			uc1 = tc1;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3143, "extend", arg5))(arg5, uc1x);
		} else {
			RTHOOK(7);
			ui4_1 = ((EIF_INTEGER_32) 2L);
			ti4_1 = eif_bit_shift_left(arg2,ui4_1);
			ui4_1 = ((EIF_INTEGER_32) 63L);
			ti4_2 = eif_bit_and(ti4_1,ui4_1);
			ui4_1 = (EIF_INTEGER_32) (((EIF_INTEGER_32) 1L) + ti4_2);
			tc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3441, "item", arg4))(arg4, ui4_1x)).it_c1);
			uc1 = tc1;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3143, "extend", arg5))(arg5, uc1x);
			RTHOOK(8);
			uc1 = (EIF_CHARACTER_8) '=';
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5026, "append_character", arg5))(arg5, uc1x);
		}
	} else {
		RTHOOK(9);
		ui4_1 = ((EIF_INTEGER_32) 4L);
		ti4_1 = eif_bit_shift_left(arg1,ui4_1);
		ui4_1 = ((EIF_INTEGER_32) 63L);
		ti4_2 = eif_bit_and(ti4_1,ui4_1);
		ui4_1 = (EIF_INTEGER_32) (((EIF_INTEGER_32) 1L) + ti4_2);
		tc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3441, "item", arg4))(arg4, ui4_1x)).it_c1);
		uc1 = tc1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3143, "extend", arg5))(arg5, uc1x);
		RTHOOK(10);
		uc1 = (EIF_CHARACTER_8) '=';
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5026, "append_character", arg5))(arg5, uc1x);
		RTHOOK(11);
		uc1 = (EIF_CHARACTER_8) '=';
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5026, "append_character", arg5))(arg5, uc1x);
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(12);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(7);
	RTEE;
#undef ui4_1
#undef uc1
#undef arg5
#undef arg4
#undef arg3
#undef arg2
#undef arg1
}

/* {BASE64}.next_encoded_character_position */
EIF_TYPED_VALUE F38_832 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "next_encoded_character_position";
	RTEX;
	EIF_INTEGER_32 loc1 = (EIF_INTEGER_32) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_i4
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE uc1x = {{0}, SK_CHAR8};
#define uc1 uc1x.it_c1
	EIF_INTEGER_32 ti4_1;
	EIF_BOOLEAN tb1;
	EIF_BOOLEAN tb2;
	EIF_CHARACTER_8 tc1;
	EIF_INTEGER_32 Result = ((EIF_INTEGER_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_i4 = * (EIF_INTEGER_32 *) arg2x.it_r;
	
	RTLI(2);
	RTLR(0,arg1);
	RTLR(1,Current);
	RTLIU(2);
	RTLU (SK_INT32, &Result);
	RTLU(SK_REF,&arg1);
	RTLU(SK_INT32,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_INT32, &loc1);
	
	RTEAA(l_feature_name, 37, Current, 1, 2, 926);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(37, Current, 926);
	RTCC(arg1, 37, l_feature_name, 1, eif_new_type(292, 0x01), 0x01);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("v_attached", EX_PRE);
		RTTE((EIF_BOOLEAN)(arg1 != NULL), label_1);
		RTCK;
		RTHOOK(2);
		RTCT("valid_from_pos", EX_PRE);
		ui4_1 = (EIF_INTEGER_32) (arg2 + ((EIF_INTEGER_32) 1L));
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3445, "valid_index", arg1))(arg1, ui4_1x)).it_b);
		RTTE(tb1, label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(3);
	RTDBGAL(0, 0x10000000, 1,0); /* Result */
	Result = (EIF_INTEGER_32) (EIF_INTEGER_32) (arg2 + ((EIF_INTEGER_32) 1L));
	RTHOOK(4);
	RTDBGAL(1, 0x10000000, 1, 0); /* loc1 */
	ti4_1 = *(EIF_INTEGER_32 *)(arg1 + RTVA(4998, "count", arg1));
	loc1 = (EIF_INTEGER_32) ti4_1;
	for (;;) {
		RTHOOK(5);
		tb1 = '\01';
		ui4_1 = Result;
		tc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(3441, "item", arg1))(arg1, ui4_1x)).it_c1);
		uc1 = tc1;
		tb2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(825, dtype))(Current, uc1x)).it_b);
		if (!tb2) {
			tb1 = (EIF_BOOLEAN) (Result > loc1);
		}
		if (tb1) break;
		RTHOOK(6);
		RTDBGAL(0, 0x10000000, 1,0); /* Result */
		Result++;
	}
	if (RTAL & CK_ENSURE) {
		RTHOOK(7);
		RTCT("result_after_from_pos", EX_POST);
		if ((EIF_BOOLEAN) (Result > arg2)) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(8);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(5);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_INT32; r.it_i4 = Result; return r; }
#undef ui4_1
#undef uc1
#undef arg2
#undef arg1
}

/* {BASE64}.in_character_map */
EIF_TYPED_VALUE F38_833 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "in_character_map";
	RTEX;
#define arg1 arg1x.it_c1
	EIF_BOOLEAN Result = ((EIF_BOOLEAN) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_c1 = * (EIF_CHARACTER_8 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_BOOL, &Result);
	RTLU(SK_CHAR8,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 37, Current, 0, 1, 927);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(37, Current, 927);
	RTIV(Current, RTAL);
	RTHOOK(1);
	switch (arg1) {
		case (EIF_CHARACTER_8) '+':
		case (EIF_CHARACTER_8) '/':
		case (EIF_CHARACTER_8) '0':
		case (EIF_CHARACTER_8) '1':
		case (EIF_CHARACTER_8) '2':
		case (EIF_CHARACTER_8) '3':
		case (EIF_CHARACTER_8) '4':
		case (EIF_CHARACTER_8) '5':
		case (EIF_CHARACTER_8) '6':
		case (EIF_CHARACTER_8) '7':
		case (EIF_CHARACTER_8) '8':
		case (EIF_CHARACTER_8) '9':
		case (EIF_CHARACTER_8) '=':
		case (EIF_CHARACTER_8) 'A':
		case (EIF_CHARACTER_8) 'B':
		case (EIF_CHARACTER_8) 'C':
		case (EIF_CHARACTER_8) 'D':
		case (EIF_CHARACTER_8) 'E':
		case (EIF_CHARACTER_8) 'F':
		case (EIF_CHARACTER_8) 'G':
		case (EIF_CHARACTER_8) 'H':
		case (EIF_CHARACTER_8) 'I':
		case (EIF_CHARACTER_8) 'J':
		case (EIF_CHARACTER_8) 'K':
		case (EIF_CHARACTER_8) 'L':
		case (EIF_CHARACTER_8) 'M':
		case (EIF_CHARACTER_8) 'N':
		case (EIF_CHARACTER_8) 'O':
		case (EIF_CHARACTER_8) 'P':
		case (EIF_CHARACTER_8) 'Q':
		case (EIF_CHARACTER_8) 'R':
		case (EIF_CHARACTER_8) 'S':
		case (EIF_CHARACTER_8) 'T':
		case (EIF_CHARACTER_8) 'U':
		case (EIF_CHARACTER_8) 'V':
		case (EIF_CHARACTER_8) 'W':
		case (EIF_CHARACTER_8) 'X':
		case (EIF_CHARACTER_8) 'Y':
		case (EIF_CHARACTER_8) 'Z':
		case (EIF_CHARACTER_8) 'a':
		case (EIF_CHARACTER_8) 'b':
		case (EIF_CHARACTER_8) 'c':
		case (EIF_CHARACTER_8) 'd':
		case (EIF_CHARACTER_8) 'e':
		case (EIF_CHARACTER_8) 'f':
		case (EIF_CHARACTER_8) 'g':
		case (EIF_CHARACTER_8) 'h':
		case (EIF_CHARACTER_8) 'i':
		case (EIF_CHARACTER_8) 'j':
		case (EIF_CHARACTER_8) 'k':
		case (EIF_CHARACTER_8) 'l':
		case (EIF_CHARACTER_8) 'm':
		case (EIF_CHARACTER_8) 'n':
		case (EIF_CHARACTER_8) 'o':
		case (EIF_CHARACTER_8) 'p':
		case (EIF_CHARACTER_8) 'q':
		case (EIF_CHARACTER_8) 'r':
		case (EIF_CHARACTER_8) 's':
		case (EIF_CHARACTER_8) 't':
		case (EIF_CHARACTER_8) 'u':
		case (EIF_CHARACTER_8) 'v':
		case (EIF_CHARACTER_8) 'w':
		case (EIF_CHARACTER_8) 'x':
		case (EIF_CHARACTER_8) 'y':
		case (EIF_CHARACTER_8) 'z':
			RTHOOK(2);
			RTDBGAL(0, 0x04000000, 1,0); /* Result */
			Result = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
			break;
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(3);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_BOOL; r.it_b = Result; return r; }
#undef arg1
}

/* {BASE64}.character_map */
RTOID (F38_834)


EIF_TYPED_VALUE F38_834 (EIF_REFERENCE Current)
{
	GTCX
	RTOTC (F38_834,929,RTMS_EX_H("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/",64,1723492911));
}

/* {BASE64}.character_to_value */
EIF_TYPED_VALUE F38_835 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "character_to_value";
	RTEX;
#define arg1 arg1x.it_c1
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE uc1x = {{0}, SK_CHAR8};
#define uc1 uc1x.it_c1
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_INTEGER_32 Result = ((EIF_INTEGER_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_c1 = * (EIF_CHARACTER_8 *) arg1x.it_r;
	
	RTLI(2);
	RTLR(0,Current);
	RTLR(1,tr1);
	RTLIU(2);
	RTLU (SK_INT32, &Result);
	RTLU(SK_CHAR8,&arg1);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 37, Current, 0, 1, 929);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(37, Current, 929);
	RTIV(Current, RTAL);
	RTHOOK(1);
	switch (arg1) {
		case (EIF_CHARACTER_8) 'A':
		case (EIF_CHARACTER_8) 'B':
		case (EIF_CHARACTER_8) 'C':
		case (EIF_CHARACTER_8) 'D':
		case (EIF_CHARACTER_8) 'E':
		case (EIF_CHARACTER_8) 'F':
		case (EIF_CHARACTER_8) 'G':
		case (EIF_CHARACTER_8) 'H':
		case (EIF_CHARACTER_8) 'I':
		case (EIF_CHARACTER_8) 'J':
		case (EIF_CHARACTER_8) 'K':
		case (EIF_CHARACTER_8) 'L':
		case (EIF_CHARACTER_8) 'M':
		case (EIF_CHARACTER_8) 'N':
		case (EIF_CHARACTER_8) 'O':
		case (EIF_CHARACTER_8) 'P':
		case (EIF_CHARACTER_8) 'Q':
		case (EIF_CHARACTER_8) 'R':
		case (EIF_CHARACTER_8) 'S':
		case (EIF_CHARACTER_8) 'T':
		case (EIF_CHARACTER_8) 'U':
		case (EIF_CHARACTER_8) 'V':
		case (EIF_CHARACTER_8) 'W':
		case (EIF_CHARACTER_8) 'X':
		case (EIF_CHARACTER_8) 'Y':
		case (EIF_CHARACTER_8) 'Z':
			RTHOOK(2);
			RTDBGAL(0, 0x10000000, 1,0); /* Result */
			ti4_1 = (EIF_INTEGER_32) (arg1);
			Result = (EIF_INTEGER_32) (EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 65L));
			break;
		case (EIF_CHARACTER_8) 'a':
		case (EIF_CHARACTER_8) 'b':
		case (EIF_CHARACTER_8) 'c':
		case (EIF_CHARACTER_8) 'd':
		case (EIF_CHARACTER_8) 'e':
		case (EIF_CHARACTER_8) 'f':
		case (EIF_CHARACTER_8) 'g':
		case (EIF_CHARACTER_8) 'h':
		case (EIF_CHARACTER_8) 'i':
		case (EIF_CHARACTER_8) 'j':
		case (EIF_CHARACTER_8) 'k':
		case (EIF_CHARACTER_8) 'l':
		case (EIF_CHARACTER_8) 'm':
		case (EIF_CHARACTER_8) 'n':
		case (EIF_CHARACTER_8) 'o':
		case (EIF_CHARACTER_8) 'p':
		case (EIF_CHARACTER_8) 'q':
		case (EIF_CHARACTER_8) 'r':
		case (EIF_CHARACTER_8) 's':
		case (EIF_CHARACTER_8) 't':
		case (EIF_CHARACTER_8) 'u':
		case (EIF_CHARACTER_8) 'v':
		case (EIF_CHARACTER_8) 'w':
		case (EIF_CHARACTER_8) 'x':
		case (EIF_CHARACTER_8) 'y':
		case (EIF_CHARACTER_8) 'z':
			RTHOOK(3);
			RTDBGAL(0, 0x10000000, 1,0); /* Result */
			ti4_1 = (EIF_INTEGER_32) (arg1);
			Result = (EIF_INTEGER_32) (EIF_INTEGER_32) ((EIF_INTEGER_32) (((EIF_INTEGER_32) 26L) + ti4_1) - ((EIF_INTEGER_32) 97L));
			break;
		case (EIF_CHARACTER_8) '0':
		case (EIF_CHARACTER_8) '1':
		case (EIF_CHARACTER_8) '2':
		case (EIF_CHARACTER_8) '3':
		case (EIF_CHARACTER_8) '4':
		case (EIF_CHARACTER_8) '5':
		case (EIF_CHARACTER_8) '6':
		case (EIF_CHARACTER_8) '7':
		case (EIF_CHARACTER_8) '8':
		case (EIF_CHARACTER_8) '9':
			RTHOOK(4);
			RTDBGAL(0, 0x10000000, 1,0); /* Result */
			ti4_1 = (EIF_INTEGER_32) (arg1);
			Result = (EIF_INTEGER_32) (EIF_INTEGER_32) ((EIF_INTEGER_32) (((EIF_INTEGER_32) 52L) + ti4_1) - ((EIF_INTEGER_32) 48L));
			break;
		case (EIF_CHARACTER_8) '+':
			RTHOOK(5);
			RTDBGAL(0, 0x10000000, 1,0); /* Result */
			Result = (EIF_INTEGER_32) ((EIF_INTEGER_32) 62L);
			break;
		case (EIF_CHARACTER_8) '/':
			RTHOOK(6);
			RTDBGAL(0, 0x10000000, 1,0); /* Result */
			Result = (EIF_INTEGER_32) ((EIF_INTEGER_32) 63L);
			break;
		default:
			RTHOOK(7);
			RTDBGAL(0, 0x10000000, 1,0); /* Result */
			Result = (EIF_INTEGER_32) ((EIF_INTEGER_32) 0L);
			break;
	}
	if (RTAL & CK_ENSURE) {
		RTHOOK(8);
		RTCT("Result = character_map.index_of (c, 1) - 1", EX_POST);
		tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(826, dtype))(Current)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
		RTNHOOK(8,1);
		uc1 = arg1;
		ui4_1 = ((EIF_INTEGER_32) 1L);
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(4976, "index_of", tr1))(tr1, uc1x, ui4_1x)).it_i4);
		if ((EIF_BOOLEAN)(Result == (EIF_INTEGER_32) (ti4_1 - ((EIF_INTEGER_32) 1L)))) {
			RTCK;
		} else {
			RTCF;
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(9);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(3);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_INT32; r.it_i4 = Result; return r; }
#undef up1
#undef ui4_1
#undef uc1
#undef arg1
}

void EIF_Minit38 (void)
{
	GTCX
	RTOTS (834,F38_834)
}


#ifdef __cplusplus
}
#endif
