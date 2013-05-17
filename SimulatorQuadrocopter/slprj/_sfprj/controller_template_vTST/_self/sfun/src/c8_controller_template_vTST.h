#ifndef __c8_controller_template_vTST_h__
#define __c8_controller_template_vTST_h__

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
} SFc8_controller_template_vTSTInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c8_controller_template_vTST_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c8_controller_template_vTST_get_check_sum(mxArray *plhs[]);
extern void c8_controller_template_vTST_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
