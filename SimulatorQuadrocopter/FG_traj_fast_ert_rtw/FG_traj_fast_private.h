/*
 * File: FG_traj_fast_private.h
 *
 * Code generated for Simulink model 'FG_traj_fast'.
 *
 * Model version                  : 1.362
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Thu May  2 14:33:59 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FG_traj_fast_private_h_
#define RTW_HEADER_FG_traj_fast_private_h_
#include "rtwtypes.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#else
#ifdef TMWTYPES_PREVIOUSLY_INCLUDED
#error This file requires rtwtypes.h to be included before tmwtypes.h
#else

/* Check for inclusion of an incorrect version of rtwtypes.h */
#ifndef RTWTYPES_ID_C08S16I32L32N32F1
#error This code was generated with a different "rtwtypes.h" than the file included
#endif                                 /* RTWTYPES_ID_C08S16I32L32N32F1 */
#endif                                 /* TMWTYPES_PREVIOUSLY_INCLUDED */
#endif                                 /* __RTWTYPES_H__ */

int_T rt_WriteMat4FileHeader(FILE *fp,
  int32_T m,
  int32_T n,
  const char_T *name);
extern void FG_traj_fast_runFastGradient(const real_T rtu_TT_PP[900], const
  real_T rtu_LL_PP[90], const real_T rtu_LL_ref_PP[2790], const real_T
  rtu_LL_U_ref_PP[900], const real_T rtu_PP[900], const real_T rtu_AA_delay[9],
  const real_T rtu_BB_delay[9], const real_T rtu_x[3], const real_T rtu_X_ref[93],
  const real_T rtu_V_max[30], real_T rtu_i_min, const real_T rtu_betas[7],
  real_T rtu_L, const real_T rtu_u_buff[3], const real_T rtu_V_init[30],
  rtB_runFastGradient_FG_traj_fas *localB);
extern void FG_traj_fa_discretekalmanfilter(real_T rtu_y, real_T rtu_y_e, real_T
  rtu_y_f, const real_T rtu_state[3], real_T rtu_state_h, const real_T rtu_A[16],
  const real_T rtu_B[4], const real_T rtu_C[12], const real_T rtu_Q[16], const
  real_T rtu_R[9], real_T rtu_u, const real_T rtu_P[16],
  rtB_discretekalmanfilter_FG_tra *localB);
extern void FG_traj__discretekalmanfilter_j(real_T rtu_y, real_T rtu_y_m, const
  real_T rtu_state[2], real_T rtu_state_n, const real_T rtu_A[9], const real_T
  rtu_B[3], const real_T rtu_C[6], const real_T rtu_Q[9], const real_T rtu_R[4],
  real_T rtu_u, const real_T rtu_P[9], rtB_discretekalmanfilter_FG_t_p *localB);
extern void FG_traj_f_MAINCONTROLLOOP1_Init(rtDW_MAINCONTROLLOOP1_FG_traj_f
  *localDW, rtP_MAINCONTROLLOOP1_FG_traj_fa *localP);
extern void FG_traj_fast_MAINCONTROLLOOP1(real_T rtu_mass, real_T rtu_x, real_T
  rtu_x_m, real_T rtu_x_p, real_T rtu_y, real_T rtu_y_k, real_T rtu_y_m, real_T
  rtu_z, real_T rtu_z_f, real_T rtu_yaw, real_T rtu_yaw_m, const real_T
  rtu_X_ref_yaw[62], const real_T rtu_X_ref_z[62], const real_T rtu_X_ref_x[93],
  real_T rtu_14, const real_T rtu_X_ref_y[93], real_T rtu_16, real_T rtu_17,
  real_T rtu_18, rtB_MAINCONTROLLOOP1_FG_traj_fa *localB,
  rtDW_MAINCONTROLLOOP1_FG_traj_f *localDW, rtP_MAINCONTROLLOOP1_FG_traj_fa
  *localP);
extern void FG_traj__EmbeddedMATLABFunction(real_T rtu_roll, real_T rtu_pitch,
  real_T rtu_pitch_bias, real_T rtu_roll_bias, real_T rtu_yaw,
  rtB_EmbeddedMATLABFunction_FG_t *localB);

#endif                                 /* RTW_HEADER_FG_traj_fast_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
