#ifndef __c4_Simulator_template_h__
#define __c4_Simulator_template_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc4_Simulator_templateInstanceStruct
#define typedef_SFc4_Simulator_templateInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c4_sfEvent;
  boolean_T c4_isStable;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_Simulator_template;
} SFc4_Simulator_templateInstanceStruct;

#endif                                 /*typedef_SFc4_Simulator_templateInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_Simulator_template_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c4_Simulator_template_get_check_sum(mxArray *plhs[]);
extern void c4_Simulator_template_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
