/*
 * Code for class HTTP_URL
 */

#include "eif_eiffel.h"
#include "../E1/estructure.h"


#ifdef __cplusplus
extern "C" {
#endif

extern EIF_TYPED_VALUE F247_5176(EIF_REFERENCE);
extern EIF_TYPED_VALUE F247_5177(EIF_REFERENCE);
extern EIF_TYPED_VALUE F247_5178(EIF_REFERENCE);
extern EIF_TYPED_VALUE F247_5179(EIF_REFERENCE);
extern void EIF_Minit247(void);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* {HTTP_URL}.service */
RTOID (F247_5176)


EIF_TYPED_VALUE F247_5176 (EIF_REFERENCE Current)
{
	GTCX
	RTOTC (F247_5176,11816,RTMS_EX_H("http",4,1752462448));
}

/* {HTTP_URL}.default_port */
EIF_TYPED_VALUE F247_5177 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_INT32;
	r.it_i4 = (EIF_INTEGER_32) ((EIF_INTEGER_32) 80L);
	return r;
}

/* {HTTP_URL}.is_proxy_supported */
EIF_TYPED_VALUE F247_5178 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = (EIF_BOOLEAN) EIF_TRUE;
	return r;
}

/* {HTTP_URL}.has_username */
EIF_TYPED_VALUE F247_5179 (EIF_REFERENCE Current)
{
	EIF_TYPED_VALUE r;
	r.type = SK_BOOL;
	r.it_b = (EIF_BOOLEAN) EIF_TRUE;
	return r;
}

void EIF_Minit247 (void)
{
	GTCX
	RTOTS (5176,F247_5176)
}


#ifdef __cplusplus
}
#endif
