/*
 * tst_mpt.c
 *
 * Code generation for model "tst_mpt".
 *
 * Model version              : 1.1
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Thu May  2 16:50:22 2013
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
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
  real_T X[4];

  /* MATLAB Function: '<S1>/Ctrl_Xdir' incorporates:
   *  Constant: '<Root>/Constant'
   */
  /* MATLAB Function 'Explicit Ctrl1/Ctrl_Xdir': '<S2>:1' */
  /* '<S2>:1:3' */
  /* '<S2>:1:6' */
  /* '<S2>:1:7' */
  X[0] = 10000.0 * tst_mpt_P.Constant_Value[0];
  X[1] = 10000.0 * tst_mpt_P.Constant_Value[1];
  X[2] = 10000.0 * tst_mpt_P.Constant_Value[2];
  X[3] = 10000.0 * tst_mpt_P.Constant_Value[3];
  tst_mpt_round(X);

  /* '<S2>:1:9' */
  /*  Find the proper region */
  /* '<S2>:1:12' */
  /* '<S2>:1:13' */

  /* Matfile logging */
  rt_UpdateTXYLogVars(tst_mpt_M->rtwLogInfo, (&tst_mpt_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.08s, 0.0s] */
    if ((rtmGetTFinal(tst_mpt_M)!=-1) &&
        !((rtmGetTFinal(tst_mpt_M)-tst_mpt_M->Timing.taskTime0) >
          tst_mpt_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(tst_mpt_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++tst_mpt_M->Timing.clockTick0)) {
    ++tst_mpt_M->Timing.clockTickH0;
  }

  tst_mpt_M->Timing.taskTime0 = tst_mpt_M->Timing.clockTick0 *
    tst_mpt_M->Timing.stepSize0 + tst_mpt_M->Timing.clockTickH0 *
    tst_mpt_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void tst_mpt_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)tst_mpt_M, 0,
                sizeof(RT_MODEL_tst_mpt_T));
  rtmSetTFinal(tst_mpt_M, 10.0);
  tst_mpt_M->Timing.stepSize0 = 0.08;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    tst_mpt_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(tst_mpt_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(tst_mpt_M->rtwLogInfo, (NULL));
    rtliSetLogT(tst_mpt_M->rtwLogInfo, "tout");
    rtliSetLogX(tst_mpt_M->rtwLogInfo, "");
    rtliSetLogXFinal(tst_mpt_M->rtwLogInfo, "");
    rtliSetSigLog(tst_mpt_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(tst_mpt_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(tst_mpt_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(tst_mpt_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(tst_mpt_M->rtwLogInfo, 1);
    rtliSetLogY(tst_mpt_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(tst_mpt_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(tst_mpt_M->rtwLogInfo, (NULL));
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(tst_mpt_M->rtwLogInfo, 0.0, rtmGetTFinal
    (tst_mpt_M), tst_mpt_M->Timing.stepSize0, (&rtmGetErrorStatus(tst_mpt_M)));
}

/* Model terminate function */
void tst_mpt_terminate(void)
{
  /* (no terminate code required) */
}
