#ifndef __c11_controller_template_h__
#define __c11_controller_template_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  ChartInfoStruct chartInfo;
} SFc11_controller_templateInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_controller_template_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c11_controller_template_get_check_sum(mxArray *plhs[]);
extern void c11_controller_template_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
