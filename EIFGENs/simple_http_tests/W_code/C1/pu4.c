/*
 * Code for class PUNYCODE
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern EIF_TYPED_VALUE F4_52(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F4_53(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F4_54(EIF_REFERENCE);
extern EIF_TYPED_VALUE F4_55(EIF_REFERENCE);
extern EIF_TYPED_VALUE F4_56(EIF_REFERENCE);
extern EIF_TYPED_VALUE F4_57(EIF_REFERENCE);
extern EIF_TYPED_VALUE F4_58(EIF_REFERENCE);
extern EIF_TYPED_VALUE F4_59(EIF_REFERENCE);
extern EIF_TYPED_VALUE F4_60(EIF_REFERENCE);
extern EIF_TYPED_VALUE F4_61(EIF_REFERENCE);
extern EIF_TYPED_VALUE F4_62(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F4_63(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F4_64(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F4_65(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F4_66(EIF_REFERENCE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F4_67(EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE);
extern EIF_TYPED_VALUE F4_68(EIF_REFERENCE);
extern void EIF_Minit4(void);

#ifdef __cplusplus
}
#endif

#include <ctype.h>
#include "eif_helpers.h"

#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* {PUNYCODE}.decoded_string */
EIF_TYPED_VALUE F4_52 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "decoded_string";
	RTEX;
	EIF_NATURAL_32 loc1 = (EIF_NATURAL_32) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_NATURAL_32 tu4_1;
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
	RTLU(SK_UINT32, &loc1);
	
	RTEAA(l_feature_name, 3, Current, 1, 1, 73);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(3, Current, 73);
	RTCC(arg1, 3, l_feature_name, 1, eif_new_type(289, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(0, 0xF8000129, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(297, 0x01).id);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4875, "count", arg1))(arg1)).it_i4);
	ui4_1 = ti4_1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(4836, Dtype(tr1)))(tr1, ui4_1x);
	RTNHOOK(1,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	RTDBGAL(1, 0x38000000, 1, 0); /* loc1 */
	ur1 = RTCCL(arg1);
	ur2 = RTCCL(Result);
	tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(70, dtype))(Current, ur1x, ur2x)).it_n4);
	loc1 = (EIF_NATURAL_32) tu4_1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(3);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ur1
#undef ur2
#undef ui4_1
#undef arg1
}

/* {PUNYCODE}.encoded_string */
EIF_TYPED_VALUE F4_53 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "encoded_string";
	RTEX;
	EIF_NATURAL_32 loc1 = (EIF_NATURAL_32) 0;
#define arg1 arg1x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ur2x = {{0}, SK_REF};
#define ur2 ur2x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_REFERENCE tr1 = NULL;
	EIF_INTEGER_32 ti4_1;
	EIF_NATURAL_32 tu4_1;
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
	RTLU(SK_UINT32, &loc1);
	
	RTEAA(l_feature_name, 3, Current, 1, 1, 74);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(3, Current, 74);
	RTCC(arg1, 3, l_feature_name, 1, eif_new_type(289, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(0, 0xF8000126, 0,0); /* Result */
	tr1 = RTLN(eif_new_type(294, 0x01).id);
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4875, "count", arg1))(arg1)).it_i4);
	ui4_1 = ti4_1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWC(4836, Dtype(tr1)))(tr1, ui4_1x);
	RTNHOOK(1,1);
	Result = (EIF_REFERENCE) RTCCL(tr1);
	RTHOOK(2);
	RTDBGAL(1, 0x38000000, 1, 0); /* loc1 */
	ur1 = RTCCL(arg1);
	ur2 = RTCCL(Result);
	tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(68, dtype))(Current, ur1x, ur2x)).it_n4);
	loc1 = (EIF_NATURAL_32) tu4_1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(3);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_REF; r.it_r = Result; return r; }
#undef ur1
#undef ur2
#undef ui4_1
#undef arg1
}

/* {PUNYCODE}.base */
EIF_TYPED_VALUE F4_54 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_UINT32;
	r.it_n4 = (EIF_NATURAL_32) ((EIF_NATURAL_32) 36U);
	return r;
}

/* {PUNYCODE}.tmin */
EIF_TYPED_VALUE F4_55 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_UINT32;
	r.it_n4 = (EIF_NATURAL_32) ((EIF_NATURAL_32) 1U);
	return r;
}

/* {PUNYCODE}.tmax */
EIF_TYPED_VALUE F4_56 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_UINT32;
	r.it_n4 = (EIF_NATURAL_32) ((EIF_NATURAL_32) 26U);
	return r;
}

/* {PUNYCODE}.skew */
EIF_TYPED_VALUE F4_57 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_UINT32;
	r.it_n4 = (EIF_NATURAL_32) ((EIF_NATURAL_32) 38U);
	return r;
}

/* {PUNYCODE}.damp */
EIF_TYPED_VALUE F4_58 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_UINT32;
	r.it_n4 = (EIF_NATURAL_32) ((EIF_NATURAL_32) 700U);
	return r;
}

/* {PUNYCODE}.initial_n */
EIF_TYPED_VALUE F4_59 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_UINT32;
	r.it_n4 = (EIF_NATURAL_32) ((EIF_NATURAL_32) 128U);
	return r;
}

/* {PUNYCODE}.initial_bias */
EIF_TYPED_VALUE F4_60 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_UINT32;
	r.it_n4 = (EIF_NATURAL_32) ((EIF_NATURAL_32) 72U);
	return r;
}

/* {PUNYCODE}.delimiter */
EIF_TYPED_VALUE F4_61 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_CHAR8;
	r.it_c1 = (EIF_CHARACTER_8) (EIF_CHARACTER_8) '-';
	return r;
}

/* {PUNYCODE}.adapt_bias */
EIF_TYPED_VALUE F4_62 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x)
{
	GTCX
	char *l_feature_name = "adapt_bias";
	RTEX;
	EIF_NATURAL_32 loc1 = (EIF_NATURAL_32) 0;
	EIF_REAL_64 loc2 = (EIF_REAL_64) 0;
#define arg1 arg1x.it_n4
#define arg2 arg2x.it_n4
#define arg3 arg3x.it_b
	EIF_REAL_64 tr8_1;
	EIF_REAL_64 tr8_2;
	EIF_REAL_64 tr8_3;
	EIF_INTEGER_64 ti8_1;
	EIF_NATURAL_32 tu4_1;
	EIF_NATURAL_32 tu4_2;
	EIF_NATURAL_32 Result = ((EIF_NATURAL_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg3x.type & SK_HEAD) == SK_REF) arg3x.it_b = * (EIF_BOOLEAN *) arg3x.it_r;
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_n4 = * (EIF_NATURAL_32 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_n4 = * (EIF_NATURAL_32 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_UINT32, &Result);
	RTLU(SK_UINT32,&arg1);
	RTLU(SK_UINT32,&arg2);
	RTLU(SK_BOOL,&arg3);
	RTLU (SK_REF, &Current);
	RTLU(SK_UINT32, &loc1);
	RTLU(SK_REAL64, &loc2);
	
	RTEAA(l_feature_name, 3, Current, 2, 3, 66);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(3, Current, 66);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
	tr8_1 = (EIF_REAL_64) (arg1);
	loc2 = (EIF_REAL_64) tr8_1;
	RTHOOK(2);
	if (arg3) {
		RTHOOK(3);
		RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
		tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(61, dtype))(Current)).it_n4);
		tr8_1 = (EIF_REAL_64) (tu4_1);
		loc2 /= tr8_1;
	} else {
		RTHOOK(4);
		RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
		tr8_1 = (EIF_REAL_64) (((EIF_INTEGER_32) 2L));
		loc2 /= tr8_1;
	}
	RTHOOK(5);
	RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
	tr8_1 = (EIF_REAL_64) (arg2);
	loc2 += (EIF_REAL_64) ((EIF_REAL_64) (loc2) /  (EIF_REAL_64) (tr8_1));
	RTHOOK(6);
	RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
	ti8_1 = (EIF_INTEGER_64) loc2;
	tr8_1 = (EIF_REAL_64) (ti8_1);
	loc2 = (EIF_REAL_64) tr8_1;
	RTHOOK(7);
	RTDBGAL(1, 0x38000000, 1, 0); /* loc1 */
	loc1 = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L);
	for (;;) {
		RTHOOK(8);
		tr8_1 = (EIF_REAL_64) (((EIF_INTEGER_32) 455L));
		if ((EIF_BOOLEAN) eif_is_less_equal_real_64 (loc2, tr8_1)) break;
		RTHOOK(9);
		RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
		tr8_2 = (EIF_REAL_64) (((EIF_INTEGER_32) 35L));
		loc2 /= tr8_2;
		RTHOOK(10);
		RTDBGAL(2, 0x20000000, 1, 0); /* loc2 */
		ti8_1 = (EIF_INTEGER_64) loc2;
		tr8_2 = (EIF_REAL_64) (ti8_1);
		loc2 = (EIF_REAL_64) tr8_2;
		RTHOOK(11);
		RTDBGAL(1, 0x38000000, 1, 0); /* loc1 */
		tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(57, dtype))(Current)).it_n4);
		loc1 += tu4_1;
	}
	RTHOOK(12);
	RTDBGAL(0, 0x38000000, 1,0); /* Result */
	tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(57, dtype))(Current)).it_n4);
	tu4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(58, dtype))(Current)).it_n4);
	tr8_2 = (EIF_REAL_64) (((EIF_NATURAL_32) ((EIF_NATURAL_32) (tu4_1 - tu4_2) + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L))));
	tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(60, dtype))(Current)).it_n4);
	tr8_3 = (EIF_REAL_64) (tu4_1);
	ti8_1 = (EIF_INTEGER_64) (EIF_REAL_64) ((EIF_REAL_64) ((EIF_REAL_64) (tr8_2 * loc2)) /  (EIF_REAL_64) ((EIF_REAL_64) (loc2 + tr8_3)));
	tu4_1 = (EIF_NATURAL_32) ti8_1;
	Result = (EIF_NATURAL_32) (EIF_NATURAL_32) (loc1 + tu4_1);
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(13);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(7);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_UINT32; r.it_n4 = Result; return r; }
#undef arg3
#undef arg2
#undef arg1
}

/* {PUNYCODE}.encoded_digit */
EIF_TYPED_VALUE F4_63 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "encoded_digit";
	RTEX;
	EIF_NATURAL_32 loc1 = (EIF_NATURAL_32) 0;
#define arg1 arg1x.it_n4
	EIF_NATURAL_32 tu4_1;
	EIF_NATURAL_32 tu4_2;
	EIF_CHARACTER_8 tc1;
	EIF_CHARACTER_8 Result = ((EIF_CHARACTER_8) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_n4 = * (EIF_NATURAL_32 *) arg1x.it_r;
	
	RTLI(1);
	RTLR(0,Current);
	RTLIU(1);
	RTLU (SK_CHAR8, &Result);
	RTLU(SK_UINT32,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_UINT32, &loc1);
	
	RTEAA(l_feature_name, 3, Current, 1, 1, 67);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(3, Current, 67);
	RTIV(Current, RTAL);
	if ((RTAL & CK_REQUIRE) || RTAC) {
		RTHOOK(1);
		RTCT("c >= 0 and c <= base - tmin", EX_PRE);
		tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(57, dtype))(Current)).it_n4);
		tu4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(58, dtype))(Current)).it_n4);
		RTTE((EIF_BOOLEAN) ((EIF_BOOLEAN) (arg1 >= (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L)) && (EIF_BOOLEAN) (arg1 <= (EIF_NATURAL_32) (tu4_1 - tu4_2))), label_1);
		RTCK;
		RTJB;
label_1:
		RTCF;
	}
body:;
	RTHOOK(2);
	if ((EIF_BOOLEAN) (arg1 > (EIF_NATURAL_32) ((EIF_INTEGER_32) 25L))) {
		RTHOOK(3);
		RTDBGAL(1, 0x38000000, 1, 0); /* loc1 */
		loc1 = (EIF_NATURAL_32) (EIF_NATURAL_32) (arg1 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 22L));
	} else {
		RTHOOK(4);
		RTDBGAL(1, 0x38000000, 1, 0); /* loc1 */
		tu4_1 = (EIF_NATURAL_32) (EIF_CHARACTER_8) 'a';
		loc1 = (EIF_NATURAL_32) (EIF_NATURAL_32) (arg1 + tu4_1);
	}
	RTHOOK(5);
	RTDBGAL(0, 0x08000000, 1,0); /* Result */
	tc1 = (EIF_CHARACTER_8) loc1;
	Result = (EIF_CHARACTER_8) tc1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(6);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_CHAR8; r.it_c1 = Result; return r; }
#undef arg1
}

/* {PUNYCODE}.encode_var_int */
EIF_TYPED_VALUE F4_64 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x, EIF_TYPED_VALUE arg3x)
{
	GTCX
	char *l_feature_name = "encode_var_int";
	RTEX;
	EIF_NATURAL_32 loc1 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc2 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc3 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc4 = (EIF_NATURAL_32) 0;
	EIF_BOOLEAN loc5 = (EIF_BOOLEAN) 0;
#define arg1 arg1x.it_n4
#define arg2 arg2x.it_n4
#define arg3 arg3x.it_r
	EIF_TYPED_VALUE uu4_1x = {{0}, SK_UINT32};
#define uu4_1 uu4_1x.it_n4
	EIF_TYPED_VALUE uc1x = {{0}, SK_CHAR8};
#define uc1 uc1x.it_c1
	EIF_INTEGER_64 ti8_1;
	EIF_NATURAL_32 tu4_1;
	EIF_CHARACTER_8 tc1;
	EIF_NATURAL_32 Result = ((EIF_NATURAL_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg2x.type & SK_HEAD) == SK_REF) arg2x.it_n4 = * (EIF_NATURAL_32 *) arg2x.it_r;
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_n4 = * (EIF_NATURAL_32 *) arg1x.it_r;
	
	RTLI(2);
	RTLR(0,arg3);
	RTLR(1,Current);
	RTLIU(2);
	RTLU (SK_UINT32, &Result);
	RTLU(SK_UINT32,&arg1);
	RTLU(SK_UINT32,&arg2);
	RTLU(SK_REF,&arg3);
	RTLU (SK_REF, &Current);
	RTLU(SK_UINT32, &loc1);
	RTLU(SK_UINT32, &loc2);
	RTLU(SK_UINT32, &loc3);
	RTLU(SK_UINT32, &loc4);
	RTLU(SK_BOOL, &loc5);
	
	RTEAA(l_feature_name, 3, Current, 5, 3, 68);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(3, Current, 68);
	RTCC(arg3, 3, l_feature_name, 3, eif_new_type(294, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(3, 0x38000000, 1, 0); /* loc3 */
	loc3 = (EIF_NATURAL_32) arg2;
	RTHOOK(2);
	RTDBGAL(2, 0x38000000, 1, 0); /* loc2 */
	tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(57, dtype))(Current)).it_n4);
	loc2 = (EIF_NATURAL_32) tu4_1;
	RTHOOK(3);
	RTDBGAL(1, 0x38000000, 1, 0); /* loc1 */
	loc1 = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L);
	for (;;) {
		RTHOOK(4);
		if (loc5) break;
		RTHOOK(5);
		if ((EIF_BOOLEAN) (loc2 <= arg1)) {
			RTHOOK(6);
			RTDBGAL(4, 0x38000000, 1, 0); /* loc4 */
			tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(58, dtype))(Current)).it_n4);
			loc4 = (EIF_NATURAL_32) tu4_1;
		} else {
			RTHOOK(7);
			tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(59, dtype))(Current)).it_n4);
			if ((EIF_BOOLEAN) (loc2 >= (EIF_NATURAL_32) (arg1 + tu4_1))) {
				RTHOOK(8);
				RTDBGAL(4, 0x38000000, 1, 0); /* loc4 */
				tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(59, dtype))(Current)).it_n4);
				loc4 = (EIF_NATURAL_32) tu4_1;
			} else {
				RTHOOK(9);
				RTDBGAL(4, 0x38000000, 1, 0); /* loc4 */
				loc4 = (EIF_NATURAL_32) (EIF_NATURAL_32) (loc2 - arg1);
			}
		}
		RTHOOK(10);
		if ((EIF_BOOLEAN) (loc3 < loc4)) {
			RTHOOK(11);
			RTDBGAL(5, 0x04000000, 1, 0); /* loc5 */
			loc5 = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
		} else {
			RTHOOK(12);
			tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(57, dtype))(Current)).it_n4);
			uu4_1 = (EIF_NATURAL_32) (loc4 + (EIF_NATURAL_32) ((EIF_NATURAL_32) (loc3 - loc4) % (EIF_NATURAL_32) (tu4_1 - loc4)));
			tc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(66, dtype))(Current, uu4_1x)).it_c1);
			uc1 = tc1;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5026, "append_character", arg3))(arg3, uc1x);
			RTHOOK(13);
			RTDBGAL(1, 0x38000000, 1, 0); /* loc1 */
			loc1 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
			RTHOOK(14);
			RTDBGAL(3, 0x38000000, 1, 0); /* loc3 */
			tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(57, dtype))(Current)).it_n4);
			ti8_1 = (EIF_INTEGER_64) (EIF_REAL_64) ((EIF_REAL_64) ((EIF_NATURAL_32) (loc3 - loc4)) /  (EIF_REAL_64) ((EIF_NATURAL_32) (tu4_1 - loc4)));
			tu4_1 = (EIF_NATURAL_32) ti8_1;
			loc3 = (EIF_NATURAL_32) tu4_1;
			RTHOOK(15);
			RTDBGAL(2, 0x38000000, 1, 0); /* loc2 */
			tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(57, dtype))(Current)).it_n4);
			loc2 += tu4_1;
		}
	}
	RTHOOK(16);
	uu4_1 = loc3;
	tc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(66, dtype))(Current, uu4_1x)).it_c1);
	uc1 = tc1;
	(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5026, "append_character", arg3))(arg3, uc1x);
	RTHOOK(17);
	RTDBGAL(1, 0x38000000, 1, 0); /* loc1 */
	loc1 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
	RTHOOK(18);
	RTDBGAL(0, 0x38000000, 1,0); /* Result */
	Result = (EIF_NATURAL_32) loc1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(19);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(10);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_UINT32; r.it_n4 = Result; return r; }
#undef uu4_1
#undef uc1
#undef arg3
#undef arg2
#undef arg1
}

/* {PUNYCODE}.punycode_encode */
EIF_TYPED_VALUE F4_65 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "punycode_encode";
	RTEX;
	EIF_NATURAL_32 loc1 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc2 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc3 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc4 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc5 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc6 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc7 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc8 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc9 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc10 = (EIF_NATURAL_32) 0;
	EIF_BOOLEAN loc11 = (EIF_BOOLEAN) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE uu4_1x = {{0}, SK_UINT32};
#define uu4_1 uu4_1x.it_n4
	EIF_TYPED_VALUE uu4_2x = {{0}, SK_UINT32};
#define uu4_2 uu4_2x.it_n4
	EIF_TYPED_VALUE ub1x = {{0}, SK_BOOL};
#define ub1 ub1x.it_b
	EIF_TYPED_VALUE uc1x = {{0}, SK_CHAR8};
#define uc1 uc1x.it_c1
	EIF_REAL_64 tr8_1;
	EIF_INTEGER_32 ti4_1;
	EIF_NATURAL_32 tu4_1;
	EIF_CHARACTER_8 tc1;
	EIF_NATURAL_32 Result = ((EIF_NATURAL_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(4);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,Current);
	RTLR(3,ur1);
	RTLIU(4);
	RTLU (SK_UINT32, &Result);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_UINT32, &loc1);
	RTLU(SK_UINT32, &loc2);
	RTLU(SK_UINT32, &loc3);
	RTLU(SK_UINT32, &loc4);
	RTLU(SK_UINT32, &loc5);
	RTLU(SK_UINT32, &loc6);
	RTLU(SK_UINT32, &loc7);
	RTLU(SK_UINT32, &loc8);
	RTLU(SK_UINT32, &loc9);
	RTLU(SK_UINT32, &loc10);
	RTLU(SK_BOOL, &loc11);
	
	RTEAA(l_feature_name, 3, Current, 11, 2, 69);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(3, Current, 69);
	RTCC(arg1, 3, l_feature_name, 1, eif_new_type(289, 0x01), 0x01);
	RTCC(arg2, 3, l_feature_name, 2, eif_new_type(294, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(1, 0x38000000, 1, 0); /* loc1 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4875, "count", arg1))(arg1)).it_i4);
	tu4_1 = (EIF_NATURAL_32) ti4_1;
	loc1 = (EIF_NATURAL_32) tu4_1;
	RTHOOK(2);
	RTDBGAL(8, 0x38000000, 1, 0); /* loc8 */
	loc8 = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L);
	RTHOOK(3);
	RTDBGAL(9, 0x38000000, 1, 0); /* loc9 */
	loc9 = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L);
	for (;;) {
		RTHOOK(4);
		if ((EIF_BOOLEAN) ((EIF_NATURAL_32) (loc8 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L)) > loc1)) break;
		RTHOOK(5);
		RTDBGAL(10, 0x38000000, 1, 0); /* loc10 */
		ti4_1 = (EIF_INTEGER_32) loc8;
		ui4_1 = (EIF_INTEGER_32) (ti4_1 + ((EIF_INTEGER_32) 1L));
		tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4838, "code", arg1))(arg1, ui4_1x)).it_n4);
		loc10 = (EIF_NATURAL_32) tu4_1;
		RTHOOK(6);
		if ((EIF_BOOLEAN) (loc10 < (EIF_NATURAL_32) ((EIF_INTEGER_32) 128L))) {
			RTHOOK(7);
			uu4_1 = loc10;
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4935, "append_code", arg2))(arg2, uu4_1x);
			RTHOOK(8);
			RTDBGAL(9, 0x38000000, 1, 0); /* loc9 */
			loc9 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
		}
		RTHOOK(9);
		RTDBGAL(8, 0x38000000, 1, 0); /* loc8 */
		loc8 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
	}
	RTHOOK(10);
	RTDBGAL(3, 0x38000000, 1, 0); /* loc3 */
	loc3 = (EIF_NATURAL_32) loc9;
	RTHOOK(11);
	RTDBGAL(2, 0x38000000, 1, 0); /* loc2 */
	loc2 = (EIF_NATURAL_32) loc3;
	RTHOOK(12);
	if ((EIF_BOOLEAN) (loc9 > (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L))) {
		RTHOOK(13);
		tc1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(64, dtype))(Current)).it_c1);
		uc1 = tc1;
		(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(5026, "append_character", arg2))(arg2, uc1x);
		RTHOOK(14);
		RTDBGAL(9, 0x38000000, 1, 0); /* loc9 */
		loc9 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
	}
	RTHOOK(15);
	RTDBGAL(7, 0x38000000, 1, 0); /* loc7 */
	tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(62, dtype))(Current)).it_n4);
	loc7 = (EIF_NATURAL_32) tu4_1;
	RTHOOK(16);
	RTDBGAL(5, 0x38000000, 1, 0); /* loc5 */
	tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(63, dtype))(Current)).it_n4);
	loc5 = (EIF_NATURAL_32) tu4_1;
	RTHOOK(17);
	RTDBGAL(4, 0x38000000, 1, 0); /* loc4 */
	loc4 = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L);
	for (;;) {
		RTHOOK(18);
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_NATURAL_32) (loc3 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L)) > loc1) || loc11)) break;
		RTHOOK(19);
		RTDBGAL(6, 0x38000000, 1, 0); /* loc6 */
		tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(71, dtype))(Current)).it_n4);
		loc6 = (EIF_NATURAL_32) tu4_1;
		RTHOOK(20);
		RTDBGAL(8, 0x38000000, 1, 0); /* loc8 */
		loc8 = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L);
		for (;;) {
			RTHOOK(21);
			if ((EIF_BOOLEAN) ((EIF_NATURAL_32) (loc8 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L)) > loc1)) break;
			RTHOOK(22);
			RTDBGAL(10, 0x38000000, 1, 0); /* loc10 */
			ti4_1 = (EIF_INTEGER_32) loc8;
			ui4_1 = (EIF_INTEGER_32) (ti4_1 + ((EIF_INTEGER_32) 1L));
			tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4838, "code", arg1))(arg1, ui4_1x)).it_n4);
			loc10 = (EIF_NATURAL_32) tu4_1;
			RTHOOK(23);
			if ((EIF_BOOLEAN) ((EIF_BOOLEAN) (loc10 >= loc7) && (EIF_BOOLEAN) (loc10 < loc6))) {
				RTHOOK(24);
				RTDBGAL(6, 0x38000000, 1, 0); /* loc6 */
				loc6 = (EIF_NATURAL_32) loc10;
			}
			RTHOOK(25);
			RTDBGAL(8, 0x38000000, 1, 0); /* loc8 */
			loc8 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
		}
		RTHOOK(26);
		tr8_1 = (EIF_REAL_64) ((EIF_NATURAL_32) (loc6 - loc7));
		tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(71, dtype))(Current)).it_n4);
		if ((EIF_BOOLEAN) eif_is_greater_real_64 (tr8_1, (EIF_REAL_64) ((EIF_REAL_64) ((EIF_NATURAL_32) (tu4_1 - loc4)) /  (EIF_REAL_64) ((EIF_NATURAL_32) (loc3 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L)))))) {
			if (RTAL & CK_CHECK) {
				RTHOOK(27);
				RTCT("overflow", EX_CHECK);
					RTCF;
			}
			RTHOOK(28);
			RTDBGAL(11, 0x04000000, 1, 0); /* loc11 */
			loc11 = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
		} else {
			RTHOOK(29);
			RTDBGAL(4, 0x38000000, 1, 0); /* loc4 */
			loc4 += (EIF_NATURAL_32) ((EIF_NATURAL_32) (loc6 - loc7) * (EIF_NATURAL_32) (loc3 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L)));
			RTHOOK(30);
			RTDBGAL(7, 0x38000000, 1, 0); /* loc7 */
			loc7 = (EIF_NATURAL_32) loc6;
			RTHOOK(31);
			RTDBGAL(8, 0x38000000, 1, 0); /* loc8 */
			loc8 = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L);
			for (;;) {
				RTHOOK(32);
				if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_NATURAL_32) (loc8 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L)) > loc1) || loc11)) break;
				RTHOOK(33);
				RTDBGAL(10, 0x38000000, 1, 0); /* loc10 */
				ti4_1 = (EIF_INTEGER_32) loc8;
				ui4_1 = (EIF_INTEGER_32) (ti4_1 + ((EIF_INTEGER_32) 1L));
				tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4838, "code", arg1))(arg1, ui4_1x)).it_n4);
				loc10 = (EIF_NATURAL_32) tu4_1;
				RTHOOK(34);
				if ((EIF_BOOLEAN) (loc10 < loc7)) {
					RTHOOK(35);
					RTDBGAL(4, 0x38000000, 1, 0); /* loc4 */
					loc4 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
					RTHOOK(36);
					if ((EIF_BOOLEAN)(loc4 == (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L))) {
						if (RTAL & CK_CHECK) {
							RTHOOK(37);
							RTCT("overflow", EX_CHECK);
								RTCF;
						}
						RTHOOK(38);
						RTDBGAL(11, 0x04000000, 1, 0); /* loc11 */
						loc11 = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
					}
				} else {
					RTHOOK(39);
					if ((EIF_BOOLEAN)(loc10 == loc7)) {
						RTHOOK(40);
						RTDBGAL(9, 0x38000000, 1, 0); /* loc9 */
						uu4_1 = loc5;
						uu4_2 = loc4;
						ur1 = RTCCL(arg2);
						tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(67, dtype))(Current, uu4_1x, uu4_2x, ur1x)).it_n4);
						loc9 += tu4_1;
						RTHOOK(41);
						RTDBGAL(5, 0x38000000, 1, 0); /* loc5 */
						uu4_1 = loc4;
						uu4_2 = (EIF_NATURAL_32) (loc3 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L));
						ub1 = (EIF_BOOLEAN)(loc3 == loc2);
						tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(65, dtype))(Current, uu4_1x, uu4_2x, ub1x)).it_n4);
						loc5 = (EIF_NATURAL_32) tu4_1;
						RTHOOK(42);
						RTDBGAL(4, 0x38000000, 1, 0); /* loc4 */
						loc4 = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L);
						RTHOOK(43);
						RTDBGAL(3, 0x38000000, 1, 0); /* loc3 */
						loc3 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
					}
				}
				RTHOOK(44);
				if ((EIF_BOOLEAN) !loc11) {
					RTHOOK(45);
					RTDBGAL(8, 0x38000000, 1, 0); /* loc8 */
					loc8 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
				}
			}
		}
		RTHOOK(46);
		if ((EIF_BOOLEAN) !loc11) {
			RTHOOK(47);
			RTDBGAL(7, 0x38000000, 1, 0); /* loc7 */
			loc7 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
			RTHOOK(48);
			RTDBGAL(4, 0x38000000, 1, 0); /* loc4 */
			loc4 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
		}
	}
	RTHOOK(49);
	if (loc11) {
	}
	RTHOOK(50);
	RTDBGAL(0, 0x38000000, 1,0); /* Result */
	Result = (EIF_NATURAL_32) loc8;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(51);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(15);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_UINT32; r.it_n4 = Result; return r; }
#undef ur1
#undef ui4_1
#undef uu4_1
#undef uu4_2
#undef ub1
#undef uc1
#undef arg2
#undef arg1
}

/* {PUNYCODE}.decoded_digit */
EIF_TYPED_VALUE F4_66 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x)
{
	GTCX
	char *l_feature_name = "decoded_digit";
	RTEX;
	EIF_CHARACTER_32 loc1 = (EIF_CHARACTER_32) 0;
#define arg1 arg1x.it_n4
	EIF_REFERENCE tr1 = NULL;
	EIF_NATURAL_32 tu4_1;
	EIF_CHARACTER_32 tw1;
	EIF_BOOLEAN tb1;
	EIF_NATURAL_32 Result = ((EIF_NATURAL_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	if ((arg1x.type & SK_HEAD) == SK_REF) arg1x.it_n4 = * (EIF_NATURAL_32 *) arg1x.it_r;
	
	RTLI(2);
	RTLR(0,tr1);
	RTLR(1,Current);
	RTLIU(2);
	RTLU (SK_UINT32, &Result);
	RTLU(SK_UINT32,&arg1);
	RTLU (SK_REF, &Current);
	RTLU(SK_CHAR32, &loc1);
	
	RTEAA(l_feature_name, 3, Current, 1, 1, 70);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(3, Current, 70);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(1, 0x1C000000, 1, 0); /* loc1 */
	tw1 = (EIF_CHARACTER_32) arg1;
	loc1 = (EIF_CHARACTER_32) tw1;
	RTHOOK(2);
	tb1 = EIF_TEST(isdigit(loc1));
	if (tb1) {
		RTHOOK(3);
		RTDBGAL(0, 0x38000000, 1,0); /* Result */
		Result = (EIF_NATURAL_32) (EIF_NATURAL_32) (arg1 - (EIF_NATURAL_32) ((EIF_INTEGER_32) 22L));
	} else {
		RTHOOK(4);
		tr1 = RTLN(eif_new_type(275, 0x00).id);
		*(EIF_CHARACTER_32 *)tr1 = loc1;
		tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4647, "is_lower", tr1))(tr1)).it_b);
		if (tb1) {
			RTHOOK(5);
			RTDBGAL(0, 0x38000000, 1,0); /* Result */
			tu4_1 = (EIF_NATURAL_32) (EIF_CHARACTER_8) 'a';
			Result = (EIF_NATURAL_32) (EIF_NATURAL_32) (arg1 - tu4_1);
		} else {
			RTHOOK(6);
			tr1 = RTLN(eif_new_type(275, 0x00).id);
			*(EIF_CHARACTER_32 *)tr1 = loc1;
			tb1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4646, "is_upper", tr1))(tr1)).it_b);
			if (tb1) {
				RTHOOK(7);
				RTDBGAL(0, 0x38000000, 1,0); /* Result */
				tu4_1 = (EIF_NATURAL_32) (EIF_CHARACTER_8) 'A';
				Result = (EIF_NATURAL_32) (EIF_NATURAL_32) (arg1 - tu4_1);
			} else {
				RTHOOK(8);
				RTDBGAL(0, 0x38000000, 1,0); /* Result */
				tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(57, dtype))(Current)).it_n4);
				Result = (EIF_NATURAL_32) tu4_1;
			}
		}
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(9);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(4);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_UINT32; r.it_n4 = Result; return r; }
#undef arg1
}

/* {PUNYCODE}.punycode_decode */
EIF_TYPED_VALUE F4_67 (EIF_REFERENCE Current, EIF_TYPED_VALUE arg1x, EIF_TYPED_VALUE arg2x)
{
	GTCX
	char *l_feature_name = "punycode_decode";
	RTEX;
	EIF_NATURAL_32 loc1 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc2 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc3 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc4 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc5 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc6 = (EIF_NATURAL_32) 0;
	EIF_INTEGER_32 loc7 = (EIF_INTEGER_32) 0;
	EIF_NATURAL_32 loc8 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc9 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc10 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc11 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc12 = (EIF_NATURAL_32) 0;
	EIF_NATURAL_32 loc13 = (EIF_NATURAL_32) 0;
	EIF_BOOLEAN loc14 = (EIF_BOOLEAN) 0;
	EIF_BOOLEAN loc15 = (EIF_BOOLEAN) 0;
	EIF_NATURAL_32 loc16 = (EIF_NATURAL_32) 0;
#define arg1 arg1x.it_r
#define arg2 arg2x.it_r
	EIF_TYPED_VALUE up1x = {{0}, SK_POINTER};
#define up1 up1x.it_p
	EIF_TYPED_VALUE ur1x = {{0}, SK_REF};
#define ur1 ur1x.it_r
	EIF_TYPED_VALUE ui4_1x = {{0}, SK_INT32};
#define ui4_1 ui4_1x.it_i4
	EIF_TYPED_VALUE uu4_1x = {{0}, SK_UINT32};
#define uu4_1 uu4_1x.it_n4
	EIF_TYPED_VALUE uu4_2x = {{0}, SK_UINT32};
#define uu4_2 uu4_2x.it_n4
	EIF_TYPED_VALUE uw1x = {{0}, SK_CHAR32};
#define uw1 uw1x.it_c4
	EIF_TYPED_VALUE ub1x = {{0}, SK_BOOL};
#define ub1 ub1x.it_b
	EIF_REFERENCE tr1 = NULL;
	EIF_REAL_64 tr8_1;
	EIF_INTEGER_64 ti8_1;
	EIF_INTEGER_32 ti4_1;
	EIF_NATURAL_32 tu4_1;
	EIF_NATURAL_32 tu4_2;
	EIF_CHARACTER_32 tw1;
	EIF_NATURAL_32 Result = ((EIF_NATURAL_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	
	RTLI(5);
	RTLR(0,arg1);
	RTLR(1,arg2);
	RTLR(2,tr1);
	RTLR(3,ur1);
	RTLR(4,Current);
	RTLIU(5);
	RTLU (SK_UINT32, &Result);
	RTLU(SK_REF,&arg1);
	RTLU(SK_REF,&arg2);
	RTLU (SK_REF, &Current);
	RTLU(SK_UINT32, &loc1);
	RTLU(SK_UINT32, &loc2);
	RTLU(SK_UINT32, &loc3);
	RTLU(SK_UINT32, &loc4);
	RTLU(SK_UINT32, &loc5);
	RTLU(SK_UINT32, &loc6);
	RTLU(SK_INT32, &loc7);
	RTLU(SK_UINT32, &loc8);
	RTLU(SK_UINT32, &loc9);
	RTLU(SK_UINT32, &loc10);
	RTLU(SK_UINT32, &loc11);
	RTLU(SK_UINT32, &loc12);
	RTLU(SK_UINT32, &loc13);
	RTLU(SK_BOOL, &loc14);
	RTLU(SK_BOOL, &loc15);
	RTLU(SK_UINT32, &loc16);
	
	RTEAA(l_feature_name, 3, Current, 16, 2, 71);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(3, Current, 71);
	RTCC(arg1, 3, l_feature_name, 1, eif_new_type(289, 0x01), 0x01);
	RTCC(arg2, 3, l_feature_name, 2, eif_new_type(297, 0x01), 0x01);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(16, 0x38000000, 1, 0); /* loc16 */
	ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTVF(4875, "count", arg1))(arg1)).it_i4);
	tu4_1 = (EIF_NATURAL_32) ti4_1;
	loc16 = (EIF_NATURAL_32) tu4_1;
	for (;;) {
		RTHOOK(2);
		if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_NATURAL_32) (loc8 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L)) > loc16) || loc14)) break;
		RTHOOK(3);
		ti4_1 = (EIF_INTEGER_32) loc8;
		ui4_1 = (EIF_INTEGER_32) (ti4_1 + ((EIF_INTEGER_32) 1L));
		tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4838, "code", arg1))(arg1, ui4_1x)).it_n4);
		if ((EIF_BOOLEAN) (tu4_1 > (EIF_NATURAL_32) ((EIF_INTEGER_32) 128L))) {
			RTHOOK(4);
			RTDBGAL(14, 0x04000000, 1, 0); /* loc14 */
			loc14 = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
		}
		RTHOOK(5);
		RTDBGAL(8, 0x38000000, 1, 0); /* loc8 */
		loc8 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
	}
	RTHOOK(6);
	if (loc14) {
		RTHOOK(7);
		RTDBGAL(0, 0x38000000, 1,0); /* Result */
		Result = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L);
	} else {
		RTHOOK(8);
		RTDBGAL(7, 0x10000000, 1, 0); /* loc7 */
		tw1 = (EIF_CHARACTER_32) (EIF_CHARACTER_8) '-';
		uw1 = tw1;
		ti4_1 = (EIF_INTEGER_32) loc16;
		ui4_1 = ti4_1;
		ti4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(4841, "last_index_of", arg1))(arg1, uw1x, ui4_1x)).it_i4);
		loc7 = (EIF_INTEGER_32) ti4_1;
		RTHOOK(9);
		if ((EIF_BOOLEAN) (loc7 > ((EIF_INTEGER_32) 0L))) {
			RTHOOK(10);
			RTDBGAL(1, 0x38000000, 1, 0); /* loc1 */
			tu4_1 = (EIF_NATURAL_32) (EIF_INTEGER_32) (loc7 - ((EIF_INTEGER_32) 1L));
			loc1 = (EIF_NATURAL_32) tu4_1;
		} else {
			RTHOOK(11);
			RTDBGAL(1, 0x38000000, 1, 0); /* loc1 */
			loc1 = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L);
		}
		RTHOOK(12);
		RTDBGAL(9, 0x38000000, 1, 0); /* loc9 */
		loc9 = (EIF_NATURAL_32) loc1;
		RTHOOK(13);
		if ((EIF_BOOLEAN) (loc9 > (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L))) {
			RTHOOK(14);
			ti4_1 = (EIF_INTEGER_32) loc9;
			ui4_1 = ti4_1;
			tr1 = ((up1x = (FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4917, "head", arg1))(arg1, ui4_1x)), (((up1x.type & SK_HEAD) == SK_REF)? (EIF_REFERENCE) 0: (up1x.it_r = RTBU(up1x))), (up1x.type = SK_POINTER), up1x.it_r);
			ur1 = RTCCL(tr1);
			(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4946, "append_string_general", arg2))(arg2, ur1x);
		}
		RTHOOK(15);
		RTDBGAL(4, 0x38000000, 1, 0); /* loc4 */
		loc4 = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L);
		RTHOOK(16);
		RTDBGAL(2, 0x38000000, 1, 0); /* loc2 */
		tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(62, dtype))(Current)).it_n4);
		loc2 = (EIF_NATURAL_32) tu4_1;
		RTHOOK(17);
		RTDBGAL(12, 0x38000000, 1, 0); /* loc12 */
		tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(63, dtype))(Current)).it_n4);
		loc12 = (EIF_NATURAL_32) tu4_1;
		RTHOOK(18);
		if ((EIF_BOOLEAN) (loc1 > (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L))) {
			RTHOOK(19);
			RTDBGAL(8, 0x38000000, 1, 0); /* loc8 */
			loc8 = (EIF_NATURAL_32) (EIF_NATURAL_32) (loc1 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L));
		} else {
			RTHOOK(20);
			RTDBGAL(8, 0x38000000, 1, 0); /* loc8 */
			loc8 = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L);
		}
		for (;;) {
			RTHOOK(21);
			if ((EIF_BOOLEAN) ((EIF_BOOLEAN) ((EIF_NATURAL_32) (loc8 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L)) > loc16) || loc14)) break;
			RTHOOK(22);
			RTDBGAL(11, 0x38000000, 1, 0); /* loc11 */
			loc11 = (EIF_NATURAL_32) loc4;
			RTHOOK(23);
			RTDBGAL(6, 0x38000000, 1, 0); /* loc6 */
			loc6 = (EIF_NATURAL_32) (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
			RTHOOK(24);
			RTDBGAL(5, 0x38000000, 1, 0); /* loc5 */
			tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(57, dtype))(Current)).it_n4);
			loc5 = (EIF_NATURAL_32) tu4_1;
			RTHOOK(25);
			RTDBGAL(15, 0x04000000, 1, 0); /* loc15 */
			loc15 = (EIF_BOOLEAN) (EIF_BOOLEAN) 0;
			for (;;) {
				RTHOOK(26);
				if ((EIF_BOOLEAN) (loc14 || loc15)) break;
				RTHOOK(27);
				RTDBGAL(13, 0x38000000, 1, 0); /* loc13 */
				ti4_1 = (EIF_INTEGER_32) loc8;
				ui4_1 = (EIF_INTEGER_32) (ti4_1 + ((EIF_INTEGER_32) 1L));
				tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTVF(4838, "code", arg1))(arg1, ui4_1x)).it_n4);
				loc13 = (EIF_NATURAL_32) tu4_1;
				RTHOOK(28);
				RTDBGAL(8, 0x38000000, 1, 0); /* loc8 */
				loc8 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
				RTHOOK(29);
				RTDBGAL(10, 0x38000000, 1, 0); /* loc10 */
				uu4_1 = loc13;
				tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE)) RTWF(69, dtype))(Current, uu4_1x)).it_n4);
				loc10 = (EIF_NATURAL_32) tu4_1;
				RTHOOK(30);
				tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(71, dtype))(Current)).it_n4);
				if ((EIF_BOOLEAN)(loc10 == tu4_1)) {
					RTHOOK(31);
					RTDBGAL(14, 0x04000000, 1, 0); /* loc14 */
					loc14 = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
				} else {
					RTHOOK(32);
					tr8_1 = (EIF_REAL_64) (loc10);
					tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(71, dtype))(Current)).it_n4);
					if ((EIF_BOOLEAN) eif_is_greater_real_64 (tr8_1, (EIF_REAL_64) ((EIF_REAL_64) ((EIF_NATURAL_32) (tu4_1 - loc4)) /  (EIF_REAL_64) (loc6)))) {
						RTHOOK(33);
						RTDBGAL(14, 0x04000000, 1, 0); /* loc14 */
						loc14 = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
					} else {
						RTHOOK(34);
						RTDBGAL(4, 0x38000000, 1, 0); /* loc4 */
						loc4 += (EIF_NATURAL_32) (loc10 * loc6);
						RTHOOK(35);
						if ((EIF_BOOLEAN) (loc5 <= loc12)) {
							RTHOOK(36);
							RTDBGAL(3, 0x38000000, 1, 0); /* loc3 */
							tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(58, dtype))(Current)).it_n4);
							loc3 = (EIF_NATURAL_32) tu4_1;
						} else {
							RTHOOK(37);
							tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(59, dtype))(Current)).it_n4);
							if ((EIF_BOOLEAN) (loc5 >= (EIF_NATURAL_32) (loc12 + tu4_1))) {
								RTHOOK(38);
								RTDBGAL(3, 0x38000000, 1, 0); /* loc3 */
								tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(59, dtype))(Current)).it_n4);
								loc3 = (EIF_NATURAL_32) tu4_1;
							} else {
								RTHOOK(39);
								RTDBGAL(3, 0x38000000, 1, 0); /* loc3 */
								loc3 = (EIF_NATURAL_32) (EIF_NATURAL_32) (loc5 - loc12);
							}
						}
						RTHOOK(40);
						if ((EIF_BOOLEAN) (loc10 < loc3)) {
							RTHOOK(41);
							RTDBGAL(15, 0x04000000, 1, 0); /* loc15 */
							loc15 = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
						} else {
							RTHOOK(42);
							tr8_1 = (EIF_REAL_64) (loc6);
							tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(71, dtype))(Current)).it_n4);
							tu4_2 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(57, dtype))(Current)).it_n4);
							if ((EIF_BOOLEAN) eif_is_greater_real_64 (tr8_1, (EIF_REAL_64) ((EIF_REAL_64) (tu4_1) /  (EIF_REAL_64) ((EIF_NATURAL_32) (tu4_2 - loc3))))) {
								RTHOOK(43);
								RTDBGAL(14, 0x04000000, 1, 0); /* loc14 */
								loc14 = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
							} else {
								RTHOOK(44);
								RTDBGAL(6, 0x38000000, 1, 0); /* loc6 */
								tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(57, dtype))(Current)).it_n4);
								loc6 *= (EIF_NATURAL_32) (tu4_1 - loc3);
								RTHOOK(45);
								RTDBGAL(5, 0x38000000, 1, 0); /* loc5 */
								tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(57, dtype))(Current)).it_n4);
								loc5 += tu4_1;
							}
						}
					}
				}
			}
			RTHOOK(46);
			RTDBGAL(12, 0x38000000, 1, 0); /* loc12 */
			uu4_1 = (EIF_NATURAL_32) (loc4 - loc11);
			uu4_2 = (EIF_NATURAL_32) (loc9 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L));
			ub1 = (EIF_BOOLEAN)(loc11 == (EIF_NATURAL_32) ((EIF_INTEGER_32) 0L));
			tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTWF(65, dtype))(Current, uu4_1x, uu4_2x, ub1x)).it_n4);
			loc12 = (EIF_NATURAL_32) tu4_1;
			RTHOOK(47);
			tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(71, dtype))(Current)).it_n4);
			tr8_1 = (EIF_REAL_64) ((EIF_NATURAL_32) (tu4_1 - loc2));
			if ((EIF_BOOLEAN) eif_is_greater_real_64 ((EIF_REAL_64) ((EIF_REAL_64) (loc4) /  (EIF_REAL_64) ((EIF_NATURAL_32) (loc9 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L)))), tr8_1)) {
				RTHOOK(48);
				RTDBGAL(14, 0x04000000, 1, 0); /* loc14 */
				loc14 = (EIF_BOOLEAN) (EIF_BOOLEAN) 1;
			} else {
				RTHOOK(49);
				RTDBGAL(2, 0x38000000, 1, 0); /* loc2 */
				ti8_1 = (EIF_INTEGER_64) ((EIF_REAL_64) ((EIF_REAL_64) (loc4) /  (EIF_REAL_64) ((EIF_NATURAL_32) (loc9 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L)))));
				tu4_1 = (EIF_NATURAL_32) ti8_1;
				loc2 += tu4_1;
				RTHOOK(50);
				RTDBGAL(4, 0x38000000, 1, 0); /* loc4 */
				loc4 %= (EIF_NATURAL_32) (loc9 + (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L));
				RTHOOK(51);
				tw1 = (EIF_CHARACTER_32) loc2;
				uw1 = tw1;
				ti4_1 = (EIF_INTEGER_32) loc4;
				ui4_1 = (EIF_INTEGER_32) (ti4_1 + ((EIF_INTEGER_32) 1L));
				(FUNCTION_CAST(void, (EIF_REFERENCE, EIF_TYPED_VALUE, EIF_TYPED_VALUE)) RTVF(5106, "insert_character", arg2))(arg2, uw1x, ui4_1x);
				RTHOOK(52);
				RTDBGAL(4, 0x38000000, 1, 0); /* loc4 */
				loc4 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
			}
			RTHOOK(53);
			RTDBGAL(9, 0x38000000, 1, 0); /* loc9 */
			loc9 += (EIF_NATURAL_32) ((EIF_INTEGER_32) 1L);
		}
	}
	RTHOOK(54);
	if (loc14) {
		RTHOOK(55);
		RTDBGAL(0, 0x38000000, 1,0); /* Result */
		Result = (EIF_NATURAL_32) loc8;
	}
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(56);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(20);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_UINT32; r.it_n4 = Result; return r; }
#undef up1
#undef ur1
#undef ui4_1
#undef uu4_1
#undef uu4_2
#undef uw1
#undef ub1
#undef arg2
#undef arg1
}

/* {PUNYCODE}.size_max */
EIF_TYPED_VALUE F4_68 (EIF_REFERENCE Current)
{
	GTCX
	char *l_feature_name = "size_max";
	RTEX;
	EIF_REFERENCE tr1 = NULL;
	EIF_NATURAL_32 tu4_1;
	EIF_NATURAL_32 Result = ((EIF_NATURAL_32) 0);
	
	RTCDT;
	RTSN;
	RTDA;
	RTLD;
	
	RTLI(2);
	RTLR(0,tr1);
	RTLR(1,Current);
	RTLIU(2);
	RTLU (SK_UINT32, &Result);
	RTLU (SK_REF, &Current);
	
	RTEAA(l_feature_name, 3, Current, 0, 0, 72);
	RTSA(dtype);
	RTSC;
	RTME(dtype, 0);
	RTGC;
	RTDBGEAA(3, Current, 72);
	RTIV(Current, RTAL);
	RTHOOK(1);
	RTDBGAL(0, 0x38000000, 1,0); /* Result */
	tu4_1 = (((FUNCTION_CAST(EIF_TYPED_VALUE, (EIF_REFERENCE)) RTWF(4401, 260))(Current)).it_n4);
	Result = (EIF_NATURAL_32) tu4_1;
	RTVI(Current, RTAL);
	RTRS;
	RTHOOK(2);
	RTDBGLE;
	RTMD(0);
	RTLE;
	RTLO(2);
	RTEE;
	{ EIF_TYPED_VALUE r; r.type = SK_UINT32; r.it_n4 = Result; return r; }
}

void EIF_Minit4 (void)
{
	GTCX
}


#ifdef __cplusplus
}
#endif
