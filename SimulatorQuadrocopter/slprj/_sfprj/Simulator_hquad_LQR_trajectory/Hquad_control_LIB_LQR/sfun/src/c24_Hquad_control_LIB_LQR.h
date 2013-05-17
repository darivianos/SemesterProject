#ifndef __c24_Hquad_control_LIB_LQR_h__
#define __c24_Hquad_control_LIB_LQR_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  int32_T c24_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c24_doneDoubleBufferReInit;
  boolean_T c24_isStable;
  uint8_T c24_is_active_c24_Hquad_control_LIB_LQR;
  ChartInfoStruct chartInfo;
} SFc24_Hquad_control_LIB_LQRInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c24_Hquad_control_LIB_LQR_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c24_Hquad_control_LIB_LQR_get_check_sum(mxArray *plhs[]);
extern void c24_Hquad_control_LIB_LQR_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
