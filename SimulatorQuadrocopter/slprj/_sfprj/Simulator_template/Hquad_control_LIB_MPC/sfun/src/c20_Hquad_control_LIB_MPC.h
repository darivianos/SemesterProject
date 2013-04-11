#ifndef __c20_Hquad_control_LIB_MPC_h__
#define __c20_Hquad_control_LIB_MPC_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c20_ResolvedFunctionInfo
#define typedef_c20_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c20_ResolvedFunctionInfo;

#endif                                 /*typedef_c20_ResolvedFunctionInfo*/

#ifndef typedef_SFc20_Hquad_control_LIB_MPCInstanceStruct
#define typedef_SFc20_Hquad_control_LIB_MPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c20_sfEvent;
  boolean_T c20_isStable;
  boolean_T c20_doneDoubleBufferReInit;
  uint8_T c20_is_active_c20_Hquad_control_LIB_MPC;
} SFc20_Hquad_control_LIB_MPCInstanceStruct;

#endif                                 /*typedef_SFc20_Hquad_control_LIB_MPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c20_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c20_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[]);
extern void c20_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
