#include "__cf_tst_mpt.h"
#include <math.h>
#include "tst_mpt_acc.h"
#include "tst_mpt_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { int32_T i ;
B_tst_mpt_T * _rtB ; P_tst_mpt_T * _rtP ; _rtP = ( ( P_tst_mpt_T * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( B_tst_mpt_T * ) _ssGetBlockIO ( S ) )
; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_1_0_0 [ 0 ] = _rtP -> P_0 [
0 ] ; _rtB -> B_1_0_0 [ 1 ] = _rtP -> P_0 [ 1 ] ; _rtB -> B_1_0_0 [ 2 ] =
_rtP -> P_0 [ 2 ] ; _rtB -> B_1_0_0 [ 3 ] = _rtP -> P_0 [ 3 ] ; memcpy ( &
_rtB -> B_1_1_0 [ 0 ] , & _rtP -> P_1 [ 0 ] , 3760U * sizeof ( real_T ) ) ;
memcpy ( & _rtB -> B_1_2_0 [ 0 ] , & _rtP -> P_2 [ 0 ] , 940U * sizeof (
real_T ) ) ; memcpy ( & _rtB -> B_1_3_0 [ 0 ] , & _rtP -> P_3 [ 0 ] , 428U *
sizeof ( real_T ) ) ; for ( i = 0 ; i < 107 ; i ++ ) { _rtB -> B_1_4_0 [ i ]
= _rtP -> P_4 [ i ] ; _rtB -> B_1_5_0 [ i ] = _rtP -> P_5 [ i ] ; }
ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock
( S , 1 , 7 , SS_CALL_MDL_OUTPUTS ) ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER ( tid
) ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S
, 0 , 1948238730U ) ; ssSetChecksumVal ( S , 1 , 468188873U ) ;
ssSetChecksumVal ( S , 2 , 2591203309U ) ; ssSetChecksumVal ( S , 3 ,
1984037850U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.1" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofGlobalBlockIO ( S ) !=
sizeof ( B_tst_mpt_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_tst_mpt_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & tst_mpt_rtDefaultP ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ;
} static void mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct *
childS ; SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ;
callSysFcns = ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ]
= ( SysOutputFcn ) ( NULL ) ; } } static void mdlTerminate ( SimStruct * S )
{ }
#include "simulink.c"
