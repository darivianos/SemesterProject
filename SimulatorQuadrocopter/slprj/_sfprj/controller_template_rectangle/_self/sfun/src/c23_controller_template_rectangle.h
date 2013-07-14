#ifndef __c23_controller_template_rectangle_h__
#define __c23_controller_template_rectangle_h__

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
} SFc23_controller_template_rectangleInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c23_controller_template_rectangle_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c23_controller_template_rectangle_get_check_sum(mxArray *plhs[]);
extern void c23_controller_template_rectangle_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
