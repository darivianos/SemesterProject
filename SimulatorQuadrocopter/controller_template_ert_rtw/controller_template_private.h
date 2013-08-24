/*
 * File: controller_template_private.h
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.718
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Aug  6 2011)
 * C/C++ source code generated on : Sat Aug 24 17:45:15 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_template_private_h_
#define RTW_HEADER_controller_template_private_h_
#include "rtwtypes.h"
#define CALL_EVENT                     (-1)

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

extern real_T rt_roundd_snf(real_T u);
extern real_T rt_modd_snf(real_T u0, real_T u1);

/* Exported functions */
int_T rt_WriteMat4FileHeader(FILE *fp,
  int32_T m,
  int32_T n,
  const char_T *name);
extern void controlle_generate_X_ref_x_Init(rtDW_generate_X_ref_x_controlle
  *localDW);
extern void controller_tem_generate_X_ref_x(const real_T rtu_traj_x[909], real_T
  rtu_idx, rtB_generate_X_ref_x_controller *localB,
  rtDW_generate_X_ref_x_controlle *localDW);
extern void controlle_generate_X_ref_y_Init(rtDW_generate_X_ref_y_controlle
  *localDW);
extern void controller_tem_generate_X_ref_y(const real_T rtu_traj_y[909], real_T
  rtu_idx, rtB_generate_X_ref_y_controller *localB,
  rtDW_generate_X_ref_y_controlle *localDW);
extern void control_generate_X_ref_yaw_Init(rtDW_generate_X_ref_yaw_control
  *localDW);
extern void controller_t_generate_X_ref_yaw(const real_T
  rtu_X_ref_yaw_unbounded[606], real_T rtu_yaw_meas, real_T rtu_idx,
  rtB_generate_X_ref_yaw_controll *localB, rtDW_generate_X_ref_yaw_control
  *localDW);
extern void controlle_generate_X_ref_z_Init(rtDW_generate_X_ref_z_controlle
  *localDW);
extern void controller_tem_generate_X_ref_z(const real_T rtu_traj_z[606], real_T
  rtu_idx, rtB_generate_X_ref_z_controller *localB,
  rtDW_generate_X_ref_z_controlle *localDW);
extern void controller__MATLABFunction_Init(rtDW_MATLABFunction_controller_
  *localDW);
extern void controller_templ_MATLABFunction(real_T rtu_u, real_T rtu_thres,
  rtB_MATLABFunction_controller_t *localB, rtDW_MATLABFunction_controller_
  *localDW);
extern void controlle_MATLABFunction_l_Init(rtDW_MATLABFunction_controlle_o
  *localDW);
extern void controller_tem_MATLABFunction_l(real_T rtu_u, real_T rtu_thres,
  rtB_MATLABFunction_controller_p *localB, rtDW_MATLABFunction_controlle_o
  *localDW);
extern void contr_discretekalmanfilter_Init(rtDW_discretekalmanfilter_contr
  *localDW);
extern void controller_discretekalmanfilter(real_T rtu_y, real_T rtu_y_e, const
  real_T rtu_state[2], real_T rtu_state_g, const real_T rtu_A[9], const real_T
  rtu_B[3], const real_T rtu_C[6], const real_T rtu_Q[9], const real_T rtu_R[4],
  real_T rtu_u, const real_T rtu_P[9], rtB_discretekalmanfilter_contro *localB,
  rtDW_discretekalmanfilter_contr *localDW);
extern void controller_runFastGradient_Init(rtDW_runFastGradient_controller
  *localDW);
extern void controller_temp_runFastGradient(const real_T rtu_TT_PP[900], const
  real_T rtu_LL_PP[90], const real_T rtu_LL_ref_PP[2790], const real_T
  rtu_LL_U_ref_PP[900], const real_T rtu_MM[9], const real_T rtu_PP[900], const
  real_T rtu_AA_delay[9], const real_T rtu_BB_delay[9], const real_T rtu_x[3],
  const real_T rtu_X_ref[93], const real_T rtu_V_max[30], real_T rtu_i_min,
  const real_T rtu_betas[7], real_T rtu_L, const real_T rtu_u_buff[3], const
  real_T rtu_V_init[30], rtB_runFastGradient_controller_ *localB,
  rtDW_runFastGradient_controller *localDW);
extern void con_discretekalmanfilter_k_Init(rtDW_discretekalmanfilter_con_c
  *localDW);
extern void controll_discretekalmanfilter_b(real_T rtu_y, real_T rtu_y_o, real_T
  rtu_y_h, const real_T rtu_state[3], real_T rtu_state_m, const real_T rtu_A[16],
  const real_T rtu_B[4], const real_T rtu_C[12], const real_T rtu_Q[16], const
  real_T rtu_R[9], real_T rtu_u, const real_T rtu_P[16],
  rtB_discretekalmanfilter_cont_h *localB, rtDW_discretekalmanfilter_con_c
  *localDW);

#endif                                 /* RTW_HEADER_controller_template_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
