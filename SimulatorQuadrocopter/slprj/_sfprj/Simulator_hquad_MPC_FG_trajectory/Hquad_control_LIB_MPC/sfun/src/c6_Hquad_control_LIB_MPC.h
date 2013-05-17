#ifndef __c6_Hquad_control_LIB_MPC_h__
#define __c6_Hquad_control_LIB_MPC_h__

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
} c6_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  int32_T c6_sfEvent;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c6_doneDoubleBufferReInit;
  boolean_T c6_isStable;
  uint8_T c6_is_active_c6_Hquad_control_LIB_MPC;
  ChartInfoStruct chartInfo;
} SFc6_Hquad_control_LIB_MPCInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c6_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[]);
extern void c6_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
