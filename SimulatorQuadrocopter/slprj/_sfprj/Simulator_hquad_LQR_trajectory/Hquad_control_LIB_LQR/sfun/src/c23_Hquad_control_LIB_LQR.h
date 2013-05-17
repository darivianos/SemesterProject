#ifndef __c23_Hquad_control_LIB_LQR_h__
#define __c23_Hquad_control_LIB_LQR_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c23_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  int32_T c23_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c23_doneDoubleBufferReInit;
  boolean_T c23_isStable;
  uint8_T c23_is_active_c23_Hquad_control_LIB_LQR;
  ChartInfoStruct chartInfo;
} SFc23_Hquad_control_LIB_LQRInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c23_Hquad_control_LIB_LQR_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c23_Hquad_control_LIB_LQR_get_check_sum(mxArray *plhs[]);
extern void c23_Hquad_control_LIB_LQR_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
