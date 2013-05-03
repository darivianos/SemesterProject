/*
 * File: controller_template_private.h
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.377
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Thu May  2 17:35:50 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_template_private_h_
#define RTW_HEADER_controller_template_private_h_
#include "rtwtypes.h"
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

extern real_T rt_roundd_snf(real_T u);
extern void controll_EmbeddedMATLABFunction(real_T rtu_pitch_meas, real_T
  rtu_roll_meas, real_T rtu_pitch_cmd, real_T rtu_roll_cmd, real_T rtu_thrust,
  real_T rtu_m, real_T rtu_g, rtB_EmbeddedMATLABFunction_cont *localB);
extern void contro_EmbeddedMATLABFunction_l(real_T rtu_yaw, real_T rtu_pitch_cmd,
  real_T rtu_roll_cmd, real_T rtu_pitch_bias, real_T rtu_roll_bias,
  rtB_EmbeddedMATLABFunction_co_g *localB);
extern void contro_EmbeddedMATLABFunction_f(real_T rtu_roll, real_T rtu_pitch,
  real_T rtu_pitch_bias, real_T rtu_roll_bias, real_T rtu_yaw,
  rtB_EmbeddedMATLABFunction_co_c *localB);
extern void controller_temp_runFastGradient(const real_T rtu_TT_PP[900], const
  real_T rtu_LL_PP[90], const real_T rtu_LL_ref_PP[2790], const real_T
  rtu_LL_U_ref_PP[900], const real_T rtu_PP[900], const real_T rtu_AA_delay[9],
  const real_T rtu_BB_delay[9], const real_T rtu_x[3], const real_T rtu_X_ref[93],
  const real_T rtu_V_max[30], real_T rtu_i_min, const real_T rtu_betas[7],
  real_T rtu_L, const real_T rtu_u_buff[3], const real_T rtu_V_init[30],
  rtB_runFastGradient_controller_ *localB);
extern void controller_discretekalmanfilter(real_T rtu_y, real_T rtu_y_e, real_T
  rtu_y_f, const real_T rtu_state[3], real_T rtu_state_h, const real_T rtu_A[16],
  const real_T rtu_B[4], const real_T rtu_C[12], const real_T rtu_Q[16], const
  real_T rtu_R[9], real_T rtu_u, const real_T rtu_P[16],
  rtB_discretekalmanfilter_contro *localB);
extern void controll_discretekalmanfilter_j(real_T rtu_y, real_T rtu_y_m, const
  real_T rtu_state[2], real_T rtu_state_n, const real_T rtu_A[9], const real_T
  rtu_B[3], const real_T rtu_C[6], const real_T rtu_Q[9], const real_T rtu_R[4],
  real_T rtu_u, const real_T rtu_P[9], rtB_discretekalmanfilter_cont_p *localB);

#endif                                 /* RTW_HEADER_controller_template_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
