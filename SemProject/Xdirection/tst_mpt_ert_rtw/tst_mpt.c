/*
 * File: tst_mpt.c
 *
 * Code generated for Simulink model 'tst_mpt'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Thu May  2 17:31:53 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "tst_mpt.h"
#include "tst_mpt_private.h"

/* Real-time model */
RT_MODEL_tst_mpt_T tst_mpt_M_;
RT_MODEL_tst_mpt_T *const tst_mpt_M = &tst_mpt_M_;

/* Forward declaration for local functions */
static void tst_mpt_round(real_T x[4]);
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = -0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Function for MATLAB Function: '<S1>/Ctrl_Xdir' */
static void tst_mpt_round(real_T x[4])
{
  x[0] = rt_roundd_snf(x[0]);
  x[1] = rt_roundd_snf(x[1]);
  x[2] = rt_roundd_snf(x[2]);
  x[3] = rt_roundd_snf(x[3]);
}

/* Model step function */
void tst_mpt_step(void)
{
  real_T A[4];

  /* MATLAB Function: '<S1>/Ctrl_Xdir' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* MATLAB Function 'Explicit Ctrl1/Ctrl_Xdir': '<S2>:1' */
  /* '<S2>:1:3' */
  /* '<S2>:1:5' */
  /* '<S2>:1:6' */
  /* '<S2>:1:7' */
  A[0] = 10000.0 * tst_mpt_P.Constant_Value[0];
  A[1] = 10000.0 * tst_mpt_P.Constant_Value[1];
  A[2] = 10000.0 * tst_mpt_P.Constant_Value[2];
  A[3] = 10000.0 * tst_mpt_P.Constant_Value[3];
  tst_mpt_round(A);

  /* '<S2>:1:9' */
  /* maxSize = max(Nc); */
  /* '<S2>:1:12' */
  /* '<S2>:1:13' */
  /*  Find the proper region */
  /* '<S2>:1:16' */
  /* '<S2>:1:17' */
}

/* Model initialize function */
void tst_mpt_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(tst_mpt_M, (NULL));
}

/* Model terminate function */
void tst_mpt_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
