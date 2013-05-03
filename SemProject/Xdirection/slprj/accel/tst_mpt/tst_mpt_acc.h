#include "__cf_tst_mpt.h"
#ifndef RTW_HEADER_tst_mpt_acc_h_
#define RTW_HEADER_tst_mpt_acc_h_
#ifndef tst_mpt_acc_COMMON_INCLUDES_
#define tst_mpt_acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif
#include "tst_mpt_acc_types.h"
typedef struct { real_T B_1_0_0 [ 4 ] ; real_T B_1_1_0 [ 3760 ] ; real_T
B_1_2_0 [ 940 ] ; real_T B_1_3_0 [ 428 ] ; real_T B_1_4_0 [ 107 ] ; real_T
B_1_5_0 [ 107 ] ; real_T B_0_0_1 ; real_T B_0_0_2 ; } B_tst_mpt_T ; struct
P_tst_mpt_T_ { real_T P_0 [ 4 ] ; real_T P_1 [ 3760 ] ; real_T P_2 [ 940 ] ;
real_T P_3 [ 428 ] ; real_T P_4 [ 107 ] ; real_T P_5 [ 107 ] ; } ; extern
P_tst_mpt_T tst_mpt_rtDefaultP ;
#endif
