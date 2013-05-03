/*
 * tst_mpt.h
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
#ifndef RTW_HEADER_tst_mpt_h_
#define RTW_HEADER_tst_mpt_h_
#ifndef tst_mpt_COMMON_INCLUDES_
# define tst_mpt_COMMON_INCLUDES_
#include <math.h>
#include <float.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "rt_nonfinite.h"
#endif                                 /* tst_mpt_COMMON_INCLUDES_ */

#include "tst_mpt_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Parameters (auto storage) */
struct P_tst_mpt_T_ {
  real_T Constant_Value[4];            /* Expression: zeros(4,1)
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant_Value_a[3760];       /* Expression: Hn_XdirFF
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Constant1_Value[940];         /* Expression: Kn_XdirFF
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value[428];         /* Expression: Fi_XdirFF
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant3_Value[107];         /* Expression: Gi_XdirFF
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant4_Value[107];         /* Expression: Nc_XdirFF
                                        * Referenced by: '<S1>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_tst_mpt_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_tst_mpt_T tst_mpt_P;

/* Model entry point functions */
extern void tst_mpt_initialize(void);
extern void tst_mpt_step(void);
extern void tst_mpt_terminate(void);

/* Real-time Model object */
extern RT_MODEL_tst_mpt_T *const tst_mpt_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'tst_mpt'
 * '<S1>'   : 'tst_mpt/Explicit Ctrl1'
 * '<S2>'   : 'tst_mpt/Explicit Ctrl1/Ctrl_Xdir'
 */
#endif                                 /* RTW_HEADER_tst_mpt_h_ */
