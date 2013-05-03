/*
 * File: controller_template.cpp
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

#include "controller_template.h"
#include "controller_template_private.h"

/* Block signals (auto storage) */
BlockIO_controller_template controller_template_B;

/* Block states (auto storage) */
D_Work_controller_template controller_template_DWork;

/* Real-time model */
RT_MODEL_controller_template controller_template_M_;
RT_MODEL_controller_template *const controller_template_M =
  &controller_template_M_;

/* Forward declaration for local functions */
static void controller_template_inv(const real_T x[9], real_T y[9]);

/* Forward declaration for local functions */
static void controller_template_round(real_T x[4]);
static void controller_template_round_h(real_T x[4]);

/*
 * Output and update for atomic system:
 *    '<S25>/Embedded MATLAB Function'
 *    '<S57>/Embedded MATLAB Function'
 */
void controll_EmbeddedMATLABFunction(real_T rtu_pitch_meas, real_T rtu_roll_meas,
  real_T rtu_pitch_cmd, real_T rtu_roll_cmd, real_T rtu_thrust, real_T rtu_m,
  real_T rtu_g, rtB_EmbeddedMATLABFunction_cont *localB)
{
  real_T thrust_comp;

  /* MATLAB Function 'decoupling and rotation/decoupling /Embedded MATLAB Function': '<S27>:1' */
  /* '<S27>:1:4' */
  thrust_comp = rtu_thrust / (cos(rtu_pitch_meas) * cos(rtu_roll_meas));

  /* '<S27>:1:6' */
  localB->pitch_cmd_comp = rtu_m * rtu_g / thrust_comp * rtu_pitch_cmd;

  /* '<S27>:1:7' */
  localB->roll_cmd_comp = rtu_m * rtu_g / thrust_comp * rtu_roll_cmd;

  /*  pitch_cmd_comp=pitch_cmd; */
  /*  roll_cmd_comp=roll_cmd; */
  /*  pitch_cmd_comp = atan(Fx/(-thrust_comp)); */
  /*  roll_cmd_comp = atan(Fy/(thrust_comp)); */
  /*  pitch_cmd_comp = atan(-g*m*pitch_cmd/(-thrust)); */
  /*  roll_cmd_comp = atan(g*m*roll_cmd*cos(pitch_meas)/(thrust)); */
  localB->thrust_comp = thrust_comp;
}

/*
 * Output and update for atomic system:
 *    '<S26>/Embedded MATLAB Function'
 *    '<S58>/Embedded MATLAB Function'
 */
void contro_EmbeddedMATLABFunction_l(real_T rtu_yaw, real_T rtu_pitch_cmd,
  real_T rtu_roll_cmd, real_T rtu_pitch_bias, real_T rtu_roll_bias,
  rtB_EmbeddedMATLABFunction_co_g *localB)
{
  real_T sin_yaw;
  real_T cos_yaw;

  /* MATLAB Function 'decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S28>:1' */
  /* '<S28>:1:3' */
  sin_yaw = sin(rtu_yaw);

  /* '<S28>:1:4' */
  cos_yaw = cos(rtu_yaw);

  /* '<S28>:1:6' */
  /* '<S28>:1:8' */
  /* '<S28>:1:9' */
  localB->pitch_rot = cos_yaw * rtu_pitch_cmd + -sin_yaw * rtu_roll_cmd;

  /* '<S28>:1:10' */
  localB->roll_rot = sin_yaw * rtu_pitch_cmd + cos_yaw * rtu_roll_cmd;

  /* '<S28>:1:12' */
  /* '<S28>:1:13' */
  localB->pitch_bias_rot = cos_yaw * rtu_pitch_bias + -sin_yaw * rtu_roll_bias;

  /* '<S28>:1:14' */
  localB->roll_bias_rot = sin_yaw * rtu_pitch_bias + cos_yaw * rtu_roll_bias;
}

/*
 * Output and update for atomic system:
 *    '<S11>/Embedded MATLAB Function'
 *    '<S34>/Embedded MATLAB Function'
 */
void contro_EmbeddedMATLABFunction_f(real_T rtu_roll, real_T rtu_pitch, real_T
  rtu_pitch_bias, real_T rtu_roll_bias, real_T rtu_yaw,
  rtB_EmbeddedMATLABFunction_co_c *localB)
{
  real_T sin_yaw;
  real_T cos_yaw;

  /* MATLAB Function 'rotate to world frame/Embedded MATLAB Function': '<S29>:1' */
  /* '<S29>:1:5' */
  sin_yaw = sin(rtu_yaw);

  /* '<S29>:1:6' */
  cos_yaw = cos(rtu_yaw);

  /* '<S29>:1:8' */
  /* '<S29>:1:10' */
  /* '<S29>:1:11' */
  localB->pitch_rot = cos_yaw * rtu_pitch + sin_yaw * rtu_roll;

  /* '<S29>:1:12' */
  localB->roll_rot = -sin_yaw * rtu_pitch + cos_yaw * rtu_roll;

  /* '<S29>:1:14' */
  /* '<S29>:1:15' */
  localB->pitch_bias_rot = cos_yaw * rtu_pitch_bias + sin_yaw * rtu_roll_bias;

  /* '<S29>:1:16' */
  localB->roll_bias_rot = -sin_yaw * rtu_pitch_bias + cos_yaw * rtu_roll_bias;
}

/*
 * Output and update for atomic system:
 *    '<S37>/runFastGradient'
 *    '<S39>/runFastGradient'
 */
void controller_temp_runFastGradient(const real_T rtu_TT_PP[900], const real_T
  rtu_LL_PP[90], const real_T rtu_LL_ref_PP[2790], const real_T rtu_LL_U_ref_PP
  [900], const real_T rtu_PP[900], const real_T rtu_AA_delay[9], const real_T
  rtu_BB_delay[9], const real_T rtu_x[3], const real_T rtu_X_ref[93], const
  real_T rtu_V_max[30], real_T rtu_i_min, const real_T rtu_betas[7], real_T
  rtu_L, const real_T rtu_u_buff[3], const real_T rtu_V_init[30],
  rtB_runFastGradient_controller_ *localB)
{
  real_T LL_PP_ref[30];
  real_T U_star[30];
  real_T V_min[30];
  real_T L_inv;
  real_T V_i[30];
  real_T V_ip[30];
  int32_T i;
  real_T tmp[3];
  real_T tmp_0[3];
  int32_T i_0;
  real_T tmp_1[30];
  int32_T i_1;
  real_T unnamed_idx;
  real_T unnamed_idx_0;
  real_T unnamed_idx_1;

  /* MATLAB Function 'x controller MPC FG  /runFastGradient': '<S45>:1' */
  /*  ugly, but simulink needs fix output sizes for vectors */
  /*  number of outputs u */
  /*  number of delay steps */
  /*  prediction horizon */
  /*  predict non-delayed state */
  /* '<S45>:1:14' */
  /*  TODO get U_ref from trajectory */
  /*  set optimization variables */
  /* '<S45>:1:21' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp[i_0] = rtu_AA_delay[i_0 + 6] * rtu_x[2] + (rtu_AA_delay[i_0 + 3] *
      rtu_x[1] + rtu_AA_delay[i_0] * rtu_x[0]);
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_0[i_0] = rtu_BB_delay[i_0 + 6] * rtu_u_buff[2] + (rtu_BB_delay[i_0 + 3] *
      rtu_u_buff[1] + rtu_BB_delay[i_0] * rtu_u_buff[0]);
  }

  unnamed_idx = tmp[0] + tmp_0[0];
  unnamed_idx_0 = tmp[1] + tmp_0[1];
  unnamed_idx_1 = tmp[2] + tmp_0[2];
  for (i_0 = 0; i_0 < 30; i_0++) {
    tmp_1[i_0] = 0.0;
    tmp_1[i_0] += rtu_LL_PP[3 * i_0] * unnamed_idx;
    tmp_1[i_0] += rtu_LL_PP[3 * i_0 + 1] * unnamed_idx_0;
    tmp_1[i_0] += rtu_LL_PP[3 * i_0 + 2] * unnamed_idx_1;
    V_min[i_0] = 0.0;
    for (i_1 = 0; i_1 < 93; i_1++) {
      V_min[i_0] += rtu_LL_ref_PP[93 * i_0 + i_1] * rtu_X_ref[i_1];
    }
  }

  for (i_0 = 0; i_0 < 30; i_0++) {
    unnamed_idx = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      unnamed_idx += rtu_LL_U_ref_PP[30 * i_0 + i_1] * 0.0;
    }

    LL_PP_ref[i_0] = (tmp_1[i_0] - V_min[i_0]) - unnamed_idx;
  }

  /* '<S45>:1:22' */
  /*  TODO expand to X_ref, U_ref */
  /*  run fast gradient method */
  for (i = 0; i < 30; i++) {
    V_min[i] = -rtu_V_max[i];
  }

  /*  Implementation of the fast gradient method for problem: */
  /*  J_star = min 0.5 V' TT_PP V + LL_PP V + MM  */
  /*  s.t. V_min <= V <= V_max */
  /*  */
  /*  Note: We do not assume V_min + V_max = 0! */
  /*  NOTE 2: LL_PP_t=LL_PP' is the transpose of LL_PP, this is done to */
  /*  optimize for speed */
  /*  */
  /*  The return value V is a feasible solution candidate and J is the associated cost. */
  /*  i_min is the number of iterations to be performed after initialization from */
  /*  V_init, and betas */
  /*  contains the pre-computed step-lengths whereas L is the maximum eigenvalue */
  /*  of TT_PP. */
  /*  If sol is non-empty then the */
  /*  following structure is assumed: */
  /*  sol.opt_val ... pre-computed optimal value (by another method) */
  /*  sol.eps     ... required absolute solution accuracy */
  /*  If sol is given, then the algorithm will terminate whenever J - */
  /*  sol.opt_val < sol.eps and return the actual number of iterations in */
  /*  actual_num_iters. If after i_min iterations the epsilon solution could */
  /*  not be reached, actual_num_iters = inf is returned */
  /*  */
  /*  (c) by Stefan Richter */
  /*  residuals = []; just for testing new convergence result idea */
  /*  check if there is the sol argument */
  /*  Run fast gradient method */
  /*  initialization: */
  L_inv = 1.0 / rtu_L;
  for (i_0 = 0; i_0 < 30; i_0++) {
    unnamed_idx = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      unnamed_idx += rtu_TT_PP[30 * i_1 + i_0] * rtu_V_init[i_1];
    }

    tmp_1[i_0] = unnamed_idx + LL_PP_ref[i_0];
  }

  for (i_0 = 0; i_0 < 30; i_0++) {
    unnamed_idx_1 = rtu_V_init[i_0] - L_inv * tmp_1[i_0];
    if ((rtu_V_max[i_0] <= unnamed_idx_1) || rtIsNaN(unnamed_idx_1)) {
      unnamed_idx = rtu_V_max[i_0];
    } else {
      unnamed_idx = unnamed_idx_1;
    }

    if ((V_min[i_0] >= unnamed_idx) || rtIsNaN(unnamed_idx)) {
      unnamed_idx = V_min[i_0];
    }

    V_ip[i_0] = unnamed_idx;
    U_star[i_0] = unnamed_idx_1;
    V_i[i_0] = unnamed_idx;
  }

  /*  now run the fast gradient method: */
  for (i = 0; i < (int32_T)rtu_i_min; i++) {
    for (i_0 = 0; i_0 < 30; i_0++) {
      unnamed_idx = 0.0;
      for (i_1 = 0; i_1 < 30; i_1++) {
        unnamed_idx += rtu_TT_PP[30 * i_1 + i_0] * V_ip[i_1];
      }

      tmp_1[i_0] = unnamed_idx + LL_PP_ref[i_0];
    }

    /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
    /*      convergence result idea */
    for (i_0 = 0; i_0 < 30; i_0++) {
      unnamed_idx_1 = V_ip[i_0] - L_inv * tmp_1[i_0];
      if ((rtu_V_max[i_0] <= unnamed_idx_1) || rtIsNaN(unnamed_idx_1)) {
        unnamed_idx_1 = rtu_V_max[i_0];
      }

      if ((V_min[i_0] >= unnamed_idx_1) || rtIsNaN(unnamed_idx_1)) {
        unnamed_idx = V_min[i_0];
      } else {
        unnamed_idx = unnamed_idx_1;
      }

      unnamed_idx_1 = rtu_betas[(int32_T)(1.0 + (real_T)i) - 1] * (unnamed_idx -
        V_i[i_0]);
      unnamed_idx_0 = unnamed_idx;
      unnamed_idx += unnamed_idx_1;
      U_star[i_0] = unnamed_idx_1;
      V_ip[i_0] = unnamed_idx;
      V_i[i_0] = unnamed_idx_0;
    }
  }

  /*  return values: */
  /*  plot(residuals) just for testing new convergence result idea */
  /* '<S45>:1:25' */
  /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
  /*  so don't forget to backtransform after termination: */
  /* '<S45>:1:32' */
  for (i_0 = 0; i_0 < 30; i_0++) {
    U_star[i_0] = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      U_star[i_0] += rtu_PP[30 * i_1 + i_0] * V_i[i_1];
    }
  }

  /*  save outputs for delayed system */
  /* '<S45>:1:38' */
  /*  set new initial guess */
  /* '<S45>:1:42' */
  /* '<S45>:1:44' */
  localB->u_opt = U_star[0];
  localB->u_buff_out[0] = rtu_u_buff[1];
  localB->u_buff_out[1] = rtu_u_buff[2];
  localB->u_buff_out[2] = U_star[0];
  memcpy(&localB->V_init_out[0], &V_i[1], 29U * sizeof(real_T));
  localB->V_init_out[29] = 0.0;
}

/* Function for MATLAB Function: '<S38>/discrete kalman filter' */
static void controller_template_inv(const real_T x[9], real_T y[9])
{
  real_T b_x[9];
  int32_T p;
  int32_T p_0;
  int32_T p_1;
  real_T absx;
  real_T absx_0;
  real_T absx_1;
  int32_T itmp;
  memcpy(&b_x[0], &x[0], 9U * sizeof(real_T));
  p = 0;
  p_0 = 3;
  p_1 = 6;
  absx = fabs(x[0]);
  absx_0 = fabs(x[1]);
  absx_1 = fabs(x[2]);
  if ((absx_0 > absx) && (absx_0 > absx_1)) {
    p = 3;
    p_0 = 0;
    b_x[0] = x[1];
    b_x[1] = x[0];
    b_x[3] = x[4];
    b_x[4] = x[3];
    b_x[6] = x[7];
    b_x[7] = x[6];
  } else {
    if (absx_1 > absx) {
      p = 6;
      p_1 = 0;
      b_x[0] = x[2];
      b_x[2] = x[0];
      b_x[3] = x[5];
      b_x[5] = x[3];
      b_x[6] = x[8];
      b_x[8] = x[6];
    }
  }

  absx = b_x[1] / b_x[0];
  b_x[1] /= b_x[0];
  absx_0 = b_x[2] / b_x[0];
  b_x[2] /= b_x[0];
  b_x[4] -= absx * b_x[3];
  b_x[5] -= absx_0 * b_x[3];
  b_x[7] -= absx * b_x[6];
  b_x[8] -= absx_0 * b_x[6];
  if (fabs(b_x[5]) > fabs(b_x[4])) {
    itmp = p_0;
    p_0 = p_1;
    p_1 = itmp;
    b_x[1] = absx_0;
    b_x[2] = absx;
    absx = b_x[4];
    b_x[4] = b_x[5];
    b_x[5] = absx;
    absx = b_x[7];
    b_x[7] = b_x[8];
    b_x[8] = absx;
  }

  absx = b_x[5] / b_x[4];
  b_x[5] /= b_x[4];
  b_x[8] -= absx * b_x[7];
  absx = (b_x[5] * b_x[1] - b_x[2]) / b_x[8];
  absx_0 = -(b_x[7] * absx + b_x[1]) / b_x[4];
  y[p] = ((1.0 - b_x[3] * absx_0) - b_x[6] * absx) / b_x[0];
  y[p + 1] = absx_0;
  y[p + 2] = absx;
  absx = -b_x[5] / b_x[8];
  absx_0 = (1.0 - b_x[7] * absx) / b_x[4];
  y[p_0] = -(b_x[3] * absx_0 + b_x[6] * absx) / b_x[0];
  y[p_0 + 1] = absx_0;
  y[p_0 + 2] = absx;
  absx = 1.0 / b_x[8];
  absx_0 = -b_x[7] * absx / b_x[4];
  y[p_1] = -(b_x[3] * absx_0 + b_x[6] * absx) / b_x[0];
  y[p_1 + 1] = absx_0;
  y[p_1 + 2] = absx;
}

/*
 * Output and update for atomic system:
 *    '<S38>/discrete kalman filter'
 *    '<S40>/discrete kalman filter'
 */
void controller_discretekalmanfilter(real_T rtu_y, real_T rtu_y_e, real_T
  rtu_y_f, const real_T rtu_state[3], real_T rtu_state_h, const real_T rtu_A[16],
  const real_T rtu_B[4], const real_T rtu_C[12], const real_T rtu_Q[16], const
  real_T rtu_R[9], real_T rtu_u, const real_T rtu_P[16],
  rtB_discretekalmanfilter_contro *localB)
{
  real_T x[4];
  real_T P[16];
  real_T K[12];
  int8_T I[16];
  real_T tmp[9];
  real_T tmp_0[9];
  int32_T i;
  real_T P_0[12];
  real_T tmp_1[3];
  real_T I_0[16];
  int32_T i_0;
  real_T unnamed_idx;
  real_T unnamed_idx_0;
  real_T unnamed_idx_1;

  /* MATLAB Function 'x states estimator bias/discrete kalman filter': '<S47>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S47>:1:10' */
  for (i = 0; i < 4; i++) {
    /* SignalConversion: '<S47>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = (((rtu_A[i + 4] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
             8] * rtu_state[2]) + rtu_A[i + 12] * rtu_state_h) + rtu_B[i] *
      rtu_u;
  }

  /* '<S47>:1:11' */
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      I_0[i + (i_0 << 2)] = 0.0;
      I_0[i + (i_0 << 2)] += rtu_P[i_0 << 2] * rtu_A[i];
      I_0[i + (i_0 << 2)] += rtu_P[(i_0 << 2) + 1] * rtu_A[i + 4];
      I_0[i + (i_0 << 2)] += rtu_P[(i_0 << 2) + 2] * rtu_A[i + 8];
      I_0[i + (i_0 << 2)] += rtu_P[(i_0 << 2) + 3] * rtu_A[i + 12];
    }
  }

  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      P[i + (i_0 << 2)] = (((I_0[i + 4] * rtu_A[i_0 + 4] + I_0[i] * rtu_A[i_0])
                            + I_0[i + 8] * rtu_A[i_0 + 8]) + I_0[i + 12] *
                           rtu_A[i_0 + 12]) + rtu_Q[(i_0 << 2) + i];
    }
  }

  /*  Measurement update */
  /* '<S47>:1:14' */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      P_0[i + 3 * i_0] = 0.0;
      P_0[i + 3 * i_0] += P[i_0 << 2] * rtu_C[i];
      P_0[i + 3 * i_0] += P[(i_0 << 2) + 1] * rtu_C[i + 3];
      P_0[i + 3 * i_0] += P[(i_0 << 2) + 2] * rtu_C[i + 6];
      P_0[i + 3 * i_0] += P[(i_0 << 2) + 3] * rtu_C[i + 9];
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      tmp[i + 3 * i_0] = (((P_0[i + 3] * rtu_C[i_0 + 3] + P_0[i] * rtu_C[i_0]) +
                           P_0[i + 6] * rtu_C[i_0 + 6]) + P_0[i + 9] * rtu_C[i_0
                          + 9]) + rtu_R[3 * i_0 + i];
    }
  }

  controller_template_inv(tmp, tmp_0);
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      P_0[i + (i_0 << 2)] = 0.0;
      P_0[i + (i_0 << 2)] += P[i] * rtu_C[i_0];
      P_0[i + (i_0 << 2)] += P[i + 4] * rtu_C[i_0 + 3];
      P_0[i + (i_0 << 2)] += P[i + 8] * rtu_C[i_0 + 6];
      P_0[i + (i_0 << 2)] += P[i + 12] * rtu_C[i_0 + 9];
    }
  }

  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      K[i + (i_0 << 2)] = 0.0;
      K[i + (i_0 << 2)] += tmp_0[3 * i_0] * P_0[i];
      K[i + (i_0 << 2)] += tmp_0[3 * i_0 + 1] * P_0[i + 4];
      K[i + (i_0 << 2)] += tmp_0[3 * i_0 + 2] * P_0[i + 8];
    }
  }

  /* '<S47>:1:15' */
  /* '<S47>:1:16' */
  for (i = 0; i < 16; i++) {
    I[i] = 0;
  }

  I[0] = 1;
  I[5] = 1;
  I[10] = 1;
  I[15] = 1;
  for (i = 0; i < 3; i++) {
    unnamed_idx = rtu_C[i + 9] * x[3] + (rtu_C[i + 6] * x[2] + (rtu_C[i + 3] *
      x[1] + rtu_C[i] * x[0]));
    tmp_1[i] = unnamed_idx;
  }

  /* SignalConversion: '<S47>/TmpSignal ConversionAt SFunction Inport8' */
  unnamed_idx = rtu_y - tmp_1[0];
  unnamed_idx_0 = rtu_y_e - tmp_1[1];
  unnamed_idx_1 = rtu_y_f - tmp_1[2];
  for (i = 0; i < 4; i++) {
    localB->state_est[i] = ((K[i + 4] * unnamed_idx_0 + K[i] * unnamed_idx) +
      K[i + 8] * unnamed_idx_1) + x[i];
  }

  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      I_0[i + (i_0 << 2)] = (real_T)I[(i_0 << 2) + i] - ((rtu_C[3 * i_0 + 1] *
        K[i + 4] + rtu_C[3 * i_0] * K[i]) + rtu_C[3 * i_0 + 2] * K[i + 8]);
    }
  }

  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      localB->P_est[i + (i_0 << 2)] = 0.0;
      localB->P_est[i + (i_0 << 2)] += P[i_0 << 2] * I_0[i];
      localB->P_est[i + (i_0 << 2)] += P[(i_0 << 2) + 1] * I_0[i + 4];
      localB->P_est[i + (i_0 << 2)] += P[(i_0 << 2) + 2] * I_0[i + 8];
      localB->P_est[i + (i_0 << 2)] += P[(i_0 << 2) + 3] * I_0[i + 12];
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S42>/discrete kalman filter'
 *    '<S44>/discrete kalman filter'
 */
void controll_discretekalmanfilter_j(real_T rtu_y, real_T rtu_y_m, const real_T
  rtu_state[2], real_T rtu_state_n, const real_T rtu_A[9], const real_T rtu_B[3],
  const real_T rtu_C[6], const real_T rtu_Q[9], const real_T rtu_R[4], real_T
  rtu_u, const real_T rtu_P[9], rtB_discretekalmanfilter_cont_p *localB)
{
  real_T x[3];
  real_T P[9];
  real_T K[6];
  int8_T I[9];
  real_T a[4];
  real_T r;
  real_T t;
  int32_T i;
  real_T P_0[6];
  real_T tmp[2];
  real_T I_0[9];
  int32_T i_0;
  real_T c_idx;
  real_T c_idx_0;
  real_T c_idx_1;

  /* MATLAB Function 'yaw states estimator bias/discrete kalman filter': '<S53>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S53>:1:10' */
  for (i = 0; i < 3; i++) {
    /* SignalConversion: '<S53>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = ((rtu_A[i + 3] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
            6] * rtu_state_n) + rtu_B[i] * rtu_u;
  }

  /* '<S53>:1:11' */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      I_0[i + 3 * i_0] = 0.0;
      I_0[i + 3 * i_0] += rtu_P[3 * i_0] * rtu_A[i];
      I_0[i + 3 * i_0] += rtu_P[3 * i_0 + 1] * rtu_A[i + 3];
      I_0[i + 3 * i_0] += rtu_P[3 * i_0 + 2] * rtu_A[i + 6];
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      P[i + 3 * i_0] = ((I_0[i + 3] * rtu_A[i_0 + 3] + I_0[i] * rtu_A[i_0]) +
                        I_0[i + 6] * rtu_A[i_0 + 6]) + rtu_Q[3 * i_0 + i];
    }
  }

  /*  Measurement update */
  /* '<S53>:1:14' */
  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      P_0[i + (i_0 << 1)] = 0.0;
      P_0[i + (i_0 << 1)] += P[3 * i_0] * rtu_C[i];
      P_0[i + (i_0 << 1)] += P[3 * i_0 + 1] * rtu_C[i + 2];
      P_0[i + (i_0 << 1)] += P[3 * i_0 + 2] * rtu_C[i + 4];
    }
  }

  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      a[i + (i_0 << 1)] = ((P_0[i + 2] * rtu_C[i_0 + 2] + P_0[i] * rtu_C[i_0]) +
                           P_0[i + 4] * rtu_C[i_0 + 4]) + rtu_R[(i_0 << 1) + i];
    }
  }

  if (fabs(a[1]) > fabs(a[0])) {
    r = a[0] / a[1];
    t = 1.0 / (r * a[3] - a[2]);
    c_idx = a[3] / a[1] * t;
    c_idx_0 = -t;
    c_idx_1 = -a[2] / a[1] * t;
    t *= r;
  } else {
    r = a[1] / a[0];
    t = 1.0 / (a[3] - r * a[2]);
    c_idx = a[3] / a[0] * t;
    c_idx_0 = -r * t;
    c_idx_1 = -a[2] / a[0] * t;
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 2; i_0++) {
      P_0[i + 3 * i_0] = 0.0;
      P_0[i + 3 * i_0] += P[i] * rtu_C[i_0];
      P_0[i + 3 * i_0] += P[i + 3] * rtu_C[i_0 + 2];
      P_0[i + 3 * i_0] += P[i + 6] * rtu_C[i_0 + 4];
    }
  }

  for (i = 0; i < 3; i++) {
    K[i] = 0.0;
    K[i] += P_0[i] * c_idx;
    K[i] += P_0[i + 3] * c_idx_0;
    K[i + 3] = 0.0;
    K[i + 3] += P_0[i] * c_idx_1;
    K[i + 3] += P_0[i + 3] * t;
  }

  /* '<S53>:1:15' */
  /* '<S53>:1:16' */
  for (i = 0; i < 9; i++) {
    I[i] = 0;
  }

  I[0] = 1;
  I[4] = 1;
  I[8] = 1;
  for (i = 0; i < 2; i++) {
    tmp[i] = rtu_C[i + 4] * x[2] + (rtu_C[i + 2] * x[1] + rtu_C[i] * x[0]);
  }

  /* SignalConversion: '<S53>/TmpSignal ConversionAt SFunction Inport8' */
  r = rtu_y - tmp[0];
  t = rtu_y_m - tmp[1];
  for (i = 0; i < 3; i++) {
    localB->state_est[i] = (K[i + 3] * t + K[i] * r) + x[i];
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      I_0[i + 3 * i_0] = (real_T)I[3 * i_0 + i] - (rtu_C[(i_0 << 1) + 1] * K[i +
        3] + rtu_C[i_0 << 1] * K[i]);
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      localB->P_est[i + 3 * i_0] = 0.0;
      localB->P_est[i + 3 * i_0] += P[3 * i_0] * I_0[i];
      localB->P_est[i + 3 * i_0] += P[3 * i_0 + 1] * I_0[i + 3];
      localB->P_est[i + 3 * i_0] += P[3 * i_0 + 2] * I_0[i + 6];
    }
  }
}

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

/* Function for MATLAB Function: '<S17>/Ctrl_Xdir' */
static void controller_template_round(real_T x[4])
{
  x[0] = rt_roundd_snf(x[0]);
  x[1] = rt_roundd_snf(x[1]);
  x[2] = rt_roundd_snf(x[2]);
  x[3] = rt_roundd_snf(x[3]);
}

/* Function for MATLAB Function: '<S19>/Ctrl_Xdir' */
static void controller_template_round_h(real_T x[4])
{
  x[0] = rt_roundd_snf(x[0]);
  x[1] = rt_roundd_snf(x[1]);
  x[2] = rt_roundd_snf(x[2]);
  x[3] = rt_roundd_snf(x[3]);
}

/* Model step function */
void FG_traj_custom(real32_T arg_data_in[30], real32_T arg_cmd_out[4], real32_T
                    arg_ref_x[93], real32_T arg_ref_y[93], real32_T arg_ref_z[62],
                    real32_T arg_ref_yaw[62])
{
  /* local block i/o variables */
  real_T rtb_DataTypeConversion[30];
  real_T rtb_Init[4];
  real_T rtb_X_ref_x[93];
  real_T rtb_X_ref_y[93];
  real_T rtb_IntegerDelay;
  real_T rtb_IntegerDelay1;
  real_T rtb_IntegerDelay2;
  real_T rtb_IntegerDelay3;
  real_T rtb_UnitDelay1[16];
  real_T rtb_Init_k[3];
  real_T rtb_UnitDelay[3];
  real_T rtb_UnitDelay1_k[30];
  real_T rtb_UnitDelay1_f[16];
  real_T rtb_Init_i[3];
  real_T rtb_UnitDelay_d[3];
  real_T rtb_UnitDelay1_i[30];
  real_T rtb_UnitDelay1_l[9];
  real_T rtb_Init_j[2];
  real_T rtb_UnitDelay1_kr[9];
  real_T rtb_Init_n[2];
  real_T tolerance;
  int32_T minreg;
  real_T Hi[400];
  real_T Ki[100];
  real_T abspos;
  real_T sumViol;
  int32_T isinside;
  int32_T ireg;
  int32_T k;
  int32_T exitg;
  real_T Hi_0[200];
  real_T Hi_1[100];
  real_T LL_PP_ref[30];
  real_T U_star[30];
  real_T L_inv;
  real_T V_i[30];
  real_T V_ip[30];
  real_T V_i_0[30];
  real_T rtb_MultiportSwitch1;
  real_T rtb_X_ref_z[62];
  real_T rtb_X_ref_yaw[62];
  real_T rtb_MultiportSwitch2;
  real_T rtb_MultiportSwitch;
  real_T rtb_Xnew[4];
  real_T rtb_Product_g;
  real_T rtb_Saturation_l;
  real_T rtb_pitch_cmd;
  real_T rtb_roll_cmd;
  real_T rtb_thrust_cmd;
  int32_T i;
  real_T tmp[30];
  real_T rtb_X_ref_z_0[30];
  real_T tmp_0[2];
  real_T tmp_1[6];
  real_T rtb_bias_W_idx;
  real_T rtb_bias_W_idx_0;
  real_T rtb_u_buff_out_idx;
  real_T rtb_bias_W_idx_1;
  real_T rtb_bias_W_idx_2;
  real_T u;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/data_in'
   */
  for (i = 0; i < 30; i++) {
    rtb_DataTypeConversion[i] = arg_data_in[i];
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* MultiPortSwitch: '<S4>/Multiport Switch1' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  if ((int32_T)rtb_DataTypeConversion[20] == 10) {
    rtb_MultiportSwitch1 = controller_template_P.Constant1_Value_of;
  } else {
    rtb_MultiportSwitch1 = controller_template_P.Constant2_Value_l;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch1' */

  /* Switch: '<S30>/Init' incorporates:
   *  Constant: '<S30>/Initial Condition'
   *  Logic: '<S30>/FixPt Logical Operator'
   *  UnitDelay: '<S30>/FixPt Unit Delay1'
   *  UnitDelay: '<S30>/FixPt Unit Delay2'
   */
  if ((rtb_MultiportSwitch1 != 0.0) ||
      (controller_template_DWork.FixPtUnitDelay2_DSTATE != 0)) {
    rtb_Init[0] = controller_template_P.InitialCondition_Value;
    rtb_Init[1] = controller_template_P.InitialCondition_Value;
    rtb_Init[2] = controller_template_P.InitialCondition_Value;
    rtb_Init[3] = controller_template_P.InitialCondition_Value;
  } else {
    rtb_Init[0] = controller_template_DWork.FixPtUnitDelay1_DSTATE[0];
    rtb_Init[1] = controller_template_DWork.FixPtUnitDelay1_DSTATE[1];
    rtb_Init[2] = controller_template_DWork.FixPtUnitDelay1_DSTATE[2];
    rtb_Init[3] = controller_template_DWork.FixPtUnitDelay1_DSTATE[3];
  }

  for (i = 0; i < 93; i++) {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
     *  Inport: '<Root>/ref_x'
     */
    rtb_X_ref_x[i] = arg_ref_x[i];

    /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
     *  Inport: '<Root>/ref_y'
     */
    rtb_X_ref_y[i] = arg_ref_y[i];
  }

  /* End of Switch: '<S30>/Init' */
  for (i = 0; i < 62; i++) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
     *  Inport: '<Root>/ref_z'
     */
    rtb_X_ref_z[i] = arg_ref_z[i];

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Inport: '<Root>/ref_yaw'
     */
    rtb_X_ref_yaw[i] = arg_ref_yaw[i];
  }

  /* MultiPortSwitch: '<S4>/Multiport Switch2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  if ((int32_T)rtb_DataTypeConversion[20] == 4) {
    rtb_MultiportSwitch2 = controller_template_P.Constant1_Value_of;
  } else {
    rtb_MultiportSwitch2 = controller_template_P.Constant2_Value_l;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch2' */

  /* Outputs for Enabled SubSystem: '<Root>/FreeFlight Pos Ctrl' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (rtb_MultiportSwitch2 > 0.0) {
    if (!controller_template_DWork.FreeFlightPosCtrl_MODE) {
      controller_template_DWork.FreeFlightPosCtrl_MODE = TRUE;
    }

    /* MATLAB Function: '<S11>/Embedded MATLAB Function' */
    contro_EmbeddedMATLABFunction_f(rtb_DataTypeConversion[6],
      rtb_DataTypeConversion[7], rtb_Init[0], rtb_Init[1],
      rtb_DataTypeConversion[8],
      &controller_template_B.sf_EmbeddedMATLABFunction);

    /* Outputs for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* Product: '<S8>/Product' incorporates:
     *  Constant: '<S8>/gravity'
     */
    rtb_Product_g = controller_template_P.gravity_Value *
      rtb_DataTypeConversion[29];

    /* MATLAB Function: '<S17>/Ctrl_Xdir' */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/Ctrl_Xdir': '<S18>:1' */
    /* '<S18>:1:3' */
    tolerance = 1.0;

    /* '<S18>:1:5' */
    /* '<S18>:1:6' */
    minreg = -1;

    /* Saturate: '<S13>/Saturation' */
    /* '<S18>:1:7' */
    if (controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot >=
        controller_template_P.Saturation_UpperSat) {
      u = controller_template_P.Saturation_UpperSat;
    } else if (controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot <=
               controller_template_P.Saturation_LowerSat) {
      u = controller_template_P.Saturation_LowerSat;
    } else {
      u = controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot;
    }

    /* MATLAB Function: '<S17>/Ctrl_Xdir' incorporates:
     *  Saturate: '<S13>/Saturation'
     */
    rtb_Xnew[0] = 10000.0 * u;

    /* Saturate: '<S13>/Saturation1' */
    if (rtb_DataTypeConversion[10] >= controller_template_P.Saturation1_UpperSat)
    {
      u = controller_template_P.Saturation1_UpperSat;
    } else if (rtb_DataTypeConversion[10] <=
               controller_template_P.Saturation1_LowerSat) {
      u = controller_template_P.Saturation1_LowerSat;
    } else {
      u = rtb_DataTypeConversion[10];
    }

    /* MATLAB Function: '<S17>/Ctrl_Xdir' incorporates:
     *  Saturate: '<S13>/Saturation1'
     */
    rtb_Xnew[1] = 10000.0 * u;

    /* Sum: '<S13>/Add' */
    u = rtb_DataTypeConversion[0] - rtb_X_ref_x[0];

    /* Saturate: '<S13>/Saturation3' */
    if (u >= controller_template_P.Saturation3_UpperSat) {
      u = controller_template_P.Saturation3_UpperSat;
    } else {
      if (u <= controller_template_P.Saturation3_LowerSat) {
        u = controller_template_P.Saturation3_LowerSat;
      }
    }

    /* MATLAB Function: '<S17>/Ctrl_Xdir' incorporates:
     *  Saturate: '<S13>/Saturation3'
     */
    rtb_Xnew[2] = 10000.0 * u;

    /* Saturate: '<S13>/Saturation2' */
    if (rtb_DataTypeConversion[3] >= controller_template_P.Saturation2_UpperSat)
    {
      u = controller_template_P.Saturation2_UpperSat;
    } else if (rtb_DataTypeConversion[3] <=
               controller_template_P.Saturation2_LowerSat) {
      u = controller_template_P.Saturation2_LowerSat;
    } else {
      u = rtb_DataTypeConversion[3];
    }

    /* MATLAB Function: '<S17>/Ctrl_Xdir' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S17>/Constant2'
     *  Constant: '<S17>/Constant3'
     *  Constant: '<S17>/Constant4'
     *  Saturate: '<S13>/Saturation2'
     */
    rtb_Xnew[3] = 10000.0 * u;
    controller_template_round(rtb_Xnew);
    rtb_Xnew[0] /= 10000.0;
    rtb_Xnew[1] /= 10000.0;
    rtb_Xnew[2] /= 10000.0;
    u = rtb_Xnew[3] / 10000.0;

    /* '<S18>:1:9' */
    /* maxSize = max(Nc); */
    /* '<S18>:1:12' */
    memset(&Hi[0], 0, 400U * sizeof(real_T));

    /* '<S18>:1:13' */
    memset(&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S18>:1:16' */
    abspos = 1.0;

    /* '<S18>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 107) {
        /* '<S18>:1:17' */
        /* '<S18>:1:18' */
        sumViol = 0.0;

        /* '<S18>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S18>:1:23' */
        for (i = 0; i < (int32_T)controller_template_P.Constant4_Value[ireg]; i
             ++) {
          /* '<S18>:1:23' */
          /* '<S18>:1:24' */
          /* '<S18>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value[(int32_T)(((1.0 + (real_T)i) +
            abspos) - 1.0) - 1];

          /* '<S18>:1:24' */
          /* '<S18>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 99] =
            controller_template_P.Constant_Value[(int32_T)(((1.0 + (real_T)i) +
            abspos) - 1.0) + 939];

          /* '<S18>:1:24' */
          /* '<S18>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 199] =
            controller_template_P.Constant_Value[(int32_T)(((1.0 + (real_T)i) +
            abspos) - 1.0) + 1879];

          /* '<S18>:1:24' */
          /* '<S18>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 299] =
            controller_template_P.Constant_Value[(int32_T)(((1.0 + (real_T)i) +
            abspos) - 1.0) + 2819];

          /* '<S18>:1:24' */
          /* '<S18>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S18>:1:30' */
        for (k = 0; k < (int32_T)controller_template_P.Constant4_Value[ireg]; k
             ++) {
          /* '<S18>:1:30' */
          /* '<S18>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value[(int32_T)(((1.0 + (real_T)k) +
            abspos) - 1.0) - 1];

          /* '<S18>:1:30' */
        }

        /* '<S18>:1:33' */
        abspos += controller_template_P.Constant4_Value[ireg];

        /* '<S18>:1:35' */
        /* '<S18>:1:36' */
        /* '<S18>:1:38' */
        /* '<S18>:1:40' */
        for (i = 0; i < (int32_T)controller_template_P.Constant4_Value[ireg]; i
             ++) {
          /* '<S18>:1:40' */
          /* '<S18>:1:41' */
          L_inv = ((Hi[(int32_T)(1.0 + (real_T)i) - 1] * rtb_Xnew[0] + Hi
                    [(int32_T)(1.0 + (real_T)i) + 99] * rtb_Xnew[1]) + Hi
                   [(int32_T)(1.0 + (real_T)i) + 199] * rtb_Xnew[2]) + Hi
            [(int32_T)(1.0 + (real_T)i) + 299] * u;
          if (L_inv - Ki[(int32_T)(1.0 + (real_T)i) - 1] > 1.0E-8) {
            /* '<S18>:1:42' */
            /* '<S18>:1:43' */
            isinside = 0;

            /* '<S18>:1:44' */
            sumViol += L_inv - Ki[(int32_T)(1.0 + (real_T)i) - 1];
          }

          /* '<S18>:1:40' */
        }

        if (sumViol < tolerance) {
          /* '<S18>:1:48' */
          /* '<S18>:1:49' */
          tolerance = sumViol;

          /* '<S18>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S18>:1:53' */
          /* '<S18>:1:54' */
          rtb_pitch_cmd = (((controller_template_P.Constant2_Value[ireg + 107] *
                             rtb_Xnew[1] +
                             controller_template_P.Constant2_Value[ireg] *
                             rtb_Xnew[0]) +
                            controller_template_P.Constant2_Value[ireg + 214] *
                            rtb_Xnew[2]) +
                           controller_template_P.Constant2_Value[ireg + 321] * u)
            + controller_template_P.Constant3_Value[ireg];
          exitg = 1;
        } else {
          /* '<S18>:1:17' */
          ireg++;
        }
      } else {
        /* '<S18>:1:58' */
        /* '<S18>:1:59' */
        /* '<S18>:1:60' */
        rtb_pitch_cmd = (((controller_template_P.Constant2_Value[minreg + 107] *
                           rtb_Xnew[1] +
                           controller_template_P.Constant2_Value[minreg] *
                           rtb_Xnew[0]) +
                          controller_template_P.Constant2_Value[minreg + 214] *
                          rtb_Xnew[2]) +
                         controller_template_P.Constant2_Value[minreg + 321] * u)
          + controller_template_P.Constant3_Value[minreg];

        /* '<S18>:1:61' */
        /* U = U_prev; */
        exitg = 1;
      }
    } while (exitg == 0);

    /* Inport: '<S8>/bias_W' */
    rtb_bias_W_idx =
      controller_template_B.sf_EmbeddedMATLABFunction.pitch_bias_rot;
    rtb_bias_W_idx_0 =
      controller_template_B.sf_EmbeddedMATLABFunction.roll_bias_rot;
    rtb_bias_W_idx_1 = rtb_Init[2];
    rtb_bias_W_idx_2 = rtb_Init[3];

    /* MATLAB Function: '<S19>/Ctrl_Xdir' */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S20>:1' */
    /* '<S20>:1:3' */
    tolerance = 1.0;

    /* '<S20>:1:5' */
    /* '<S20>:1:6' */
    minreg = -1;

    /* Saturate: '<S14>/Saturation' */
    /* '<S20>:1:7' */
    if (controller_template_B.sf_EmbeddedMATLABFunction.roll_rot >=
        controller_template_P.Saturation_UpperSat_j) {
      u = controller_template_P.Saturation_UpperSat_j;
    } else if (controller_template_B.sf_EmbeddedMATLABFunction.roll_rot <=
               controller_template_P.Saturation_LowerSat_d) {
      u = controller_template_P.Saturation_LowerSat_d;
    } else {
      u = controller_template_B.sf_EmbeddedMATLABFunction.roll_rot;
    }

    /* MATLAB Function: '<S19>/Ctrl_Xdir' incorporates:
     *  Saturate: '<S14>/Saturation'
     */
    rtb_Xnew[0] = 10000.0 * u;

    /* Saturate: '<S14>/Saturation1' */
    if (rtb_DataTypeConversion[9] >=
        controller_template_P.Saturation1_UpperSat_b) {
      u = controller_template_P.Saturation1_UpperSat_b;
    } else if (rtb_DataTypeConversion[9] <=
               controller_template_P.Saturation1_LowerSat_l) {
      u = controller_template_P.Saturation1_LowerSat_l;
    } else {
      u = rtb_DataTypeConversion[9];
    }

    /* MATLAB Function: '<S19>/Ctrl_Xdir' incorporates:
     *  Saturate: '<S14>/Saturation1'
     */
    rtb_Xnew[1] = 10000.0 * u;

    /* Sum: '<S14>/Add' */
    u = rtb_DataTypeConversion[1] - rtb_X_ref_y[0];

    /* Saturate: '<S14>/Saturation3' */
    if (u >= controller_template_P.Saturation3_UpperSat_o) {
      u = controller_template_P.Saturation3_UpperSat_o;
    } else {
      if (u <= controller_template_P.Saturation3_LowerSat_i) {
        u = controller_template_P.Saturation3_LowerSat_i;
      }
    }

    /* MATLAB Function: '<S19>/Ctrl_Xdir' incorporates:
     *  Saturate: '<S14>/Saturation3'
     */
    rtb_Xnew[2] = 10000.0 * u;

    /* Saturate: '<S14>/Saturation2' */
    if (rtb_DataTypeConversion[4] >=
        controller_template_P.Saturation2_UpperSat_m) {
      u = controller_template_P.Saturation2_UpperSat_m;
    } else if (rtb_DataTypeConversion[4] <=
               controller_template_P.Saturation2_LowerSat_e) {
      u = controller_template_P.Saturation2_LowerSat_e;
    } else {
      u = rtb_DataTypeConversion[4];
    }

    /* MATLAB Function: '<S19>/Ctrl_Xdir' incorporates:
     *  Constant: '<S19>/Constant'
     *  Constant: '<S19>/Constant1'
     *  Constant: '<S19>/Constant2'
     *  Constant: '<S19>/Constant3'
     *  Constant: '<S19>/Constant4'
     *  Saturate: '<S14>/Saturation2'
     */
    rtb_Xnew[3] = 10000.0 * u;
    controller_template_round_h(rtb_Xnew);
    rtb_Xnew[0] /= 10000.0;
    rtb_Xnew[1] /= 10000.0;
    rtb_Xnew[2] /= 10000.0;
    u = rtb_Xnew[3] / 10000.0;

    /* '<S20>:1:9' */
    /* maxSize = max(Nc); */
    /* '<S20>:1:12' */
    memset(&Hi[0], 0, 400U * sizeof(real_T));

    /* '<S20>:1:13' */
    memset(&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S20>:1:16' */
    abspos = 1.0;

    /* '<S20>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 104) {
        /* '<S20>:1:17' */
        /* '<S20>:1:18' */
        sumViol = 0.0;

        /* '<S20>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S20>:1:23' */
        for (i = 0; i < (int32_T)controller_template_P.Constant4_Value_p[ireg];
             i++) {
          /* '<S20>:1:23' */
          /* '<S20>:1:24' */
          /* '<S20>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_n[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S20>:1:24' */
          /* '<S20>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 99] =
            controller_template_P.Constant_Value_n[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 920];

          /* '<S20>:1:24' */
          /* '<S20>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 199] =
            controller_template_P.Constant_Value_n[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 1841];

          /* '<S20>:1:24' */
          /* '<S20>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 299] =
            controller_template_P.Constant_Value_n[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 2762];

          /* '<S20>:1:24' */
          /* '<S20>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S20>:1:30' */
        for (k = 0; k < (int32_T)controller_template_P.Constant4_Value_p[ireg];
             k++) {
          /* '<S20>:1:30' */
          /* '<S20>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_o[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S20>:1:30' */
        }

        /* '<S20>:1:33' */
        abspos += controller_template_P.Constant4_Value_p[ireg];

        /* '<S20>:1:35' */
        /* '<S20>:1:36' */
        /* '<S20>:1:38' */
        /* '<S20>:1:40' */
        for (i = 0; i < (int32_T)controller_template_P.Constant4_Value_p[ireg];
             i++) {
          /* '<S20>:1:40' */
          /* '<S20>:1:41' */
          L_inv = ((Hi[(int32_T)(1.0 + (real_T)i) - 1] * rtb_Xnew[0] + Hi
                    [(int32_T)(1.0 + (real_T)i) + 99] * rtb_Xnew[1]) + Hi
                   [(int32_T)(1.0 + (real_T)i) + 199] * rtb_Xnew[2]) + Hi
            [(int32_T)(1.0 + (real_T)i) + 299] * u;
          if (L_inv - Ki[(int32_T)(1.0 + (real_T)i) - 1] > 1.0E-8) {
            /* '<S20>:1:42' */
            /* '<S20>:1:43' */
            isinside = 0;

            /* '<S20>:1:44' */
            sumViol += L_inv - Ki[(int32_T)(1.0 + (real_T)i) - 1];
          }

          /* '<S20>:1:40' */
        }

        if (sumViol < tolerance) {
          /* '<S20>:1:48' */
          /* '<S20>:1:49' */
          tolerance = sumViol;

          /* '<S20>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S20>:1:53' */
          /* '<S20>:1:54' */
          rtb_Saturation_l = (((controller_template_P.Constant2_Value_n[ireg +
                                104] * rtb_Xnew[1] +
                                controller_template_P.Constant2_Value_n[ireg] *
                                rtb_Xnew[0]) +
                               controller_template_P.Constant2_Value_n[ireg +
                               208] * rtb_Xnew[2]) +
                              controller_template_P.Constant2_Value_n[ireg + 312]
                              * u) +
            controller_template_P.Constant3_Value_a[ireg];
          exitg = 1;
        } else {
          /* '<S20>:1:17' */
          ireg++;
        }
      } else {
        /* '<S20>:1:58' */
        /* '<S20>:1:59' */
        /* '<S20>:1:60' */
        rtb_Saturation_l = (((controller_template_P.Constant2_Value_n[minreg +
                              104] * rtb_Xnew[1] +
                              controller_template_P.Constant2_Value_n[minreg] *
                              rtb_Xnew[0]) +
                             controller_template_P.Constant2_Value_n[minreg +
                             208] * rtb_Xnew[2]) +
                            controller_template_P.Constant2_Value_n[minreg + 312]
                            * u) +
          controller_template_P.Constant3_Value_a[minreg];

        /* '<S20>:1:61' */
        /* U = U_prev; */
        exitg = 1;
      }
    } while (exitg == 0);

    /* MATLAB Function: '<S23>/Ctrl_Xdir' */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S24>:1' */
    /* '<S24>:1:3' */
    tolerance = 1.0;

    /* '<S24>:1:5' */
    /* '<S24>:1:6' */
    minreg = -1;

    /* Sum: '<S16>/Add' */
    /* '<S24>:1:7' */
    u = rtb_DataTypeConversion[2] - rtb_X_ref_z[0];

    /* Saturate: '<S16>/Saturation1' */
    if (u >= controller_template_P.Saturation1_UpperSat_m) {
      u = controller_template_P.Saturation1_UpperSat_m;
    } else {
      if (u <= controller_template_P.Saturation1_LowerSat_n) {
        u = controller_template_P.Saturation1_LowerSat_n;
      }
    }

    /* MATLAB Function: '<S23>/Ctrl_Xdir' incorporates:
     *  Saturate: '<S16>/Saturation1'
     */
    rtb_u_buff_out_idx = rt_roundd_snf(10000.0 * u) / 10000.0;

    /* Saturate: '<S16>/Saturation' */
    if (rtb_DataTypeConversion[5] >= controller_template_P.Saturation_UpperSat_p)
    {
      u = controller_template_P.Saturation_UpperSat_p;
    } else if (rtb_DataTypeConversion[5] <=
               controller_template_P.Saturation_LowerSat_o) {
      u = controller_template_P.Saturation_LowerSat_o;
    } else {
      u = rtb_DataTypeConversion[5];
    }

    /* MATLAB Function: '<S23>/Ctrl_Xdir' incorporates:
     *  Constant: '<S23>/Constant'
     *  Constant: '<S23>/Constant1'
     *  Constant: '<S23>/Constant2'
     *  Constant: '<S23>/Constant3'
     *  Constant: '<S23>/Constant4'
     *  Saturate: '<S16>/Saturation'
     */
    u = rt_roundd_snf(10000.0 * u) / 10000.0;

    /* '<S24>:1:9' */
    /* maxSize = max(Nc); */
    /* '<S24>:1:12' */
    memset(&Hi_0[0], 0, 200U * sizeof(real_T));

    /* '<S24>:1:13' */
    memset(&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S24>:1:16' */
    abspos = 1.0;

    /* '<S24>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 21) {
        /* '<S24>:1:17' */
        /* '<S24>:1:18' */
        sumViol = 0.0;

        /* '<S24>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S24>:1:23' */
        for (i = 0; i < (int32_T)controller_template_P.Constant4_Value_n[ireg];
             i++) {
          /* '<S24>:1:23' */
          /* '<S24>:1:24' */
          /* '<S24>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_f[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S24>:1:24' */
          /* '<S24>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)i) + 99] =
            controller_template_P.Constant_Value_f[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 87];

          /* '<S24>:1:24' */
          /* '<S24>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S24>:1:30' */
        for (k = 0; k < (int32_T)controller_template_P.Constant4_Value_n[ireg];
             k++) {
          /* '<S24>:1:30' */
          /* '<S24>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_g[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S24>:1:30' */
        }

        /* '<S24>:1:33' */
        abspos += controller_template_P.Constant4_Value_n[ireg];

        /* '<S24>:1:35' */
        /* '<S24>:1:36' */
        /* '<S24>:1:38' */
        /* '<S24>:1:40' */
        for (i = 0; i < (int32_T)controller_template_P.Constant4_Value_n[ireg];
             i++) {
          /* '<S24>:1:40' */
          /* '<S24>:1:41' */
          L_inv = Hi_0[(int32_T)(1.0 + (real_T)i) - 1] * rtb_u_buff_out_idx +
            Hi_0[(int32_T)(1.0 + (real_T)i) + 99] * u;
          if (L_inv - Ki[(int32_T)(1.0 + (real_T)i) - 1] > 1.0E-8) {
            /* '<S24>:1:42' */
            /* '<S24>:1:43' */
            isinside = 0;

            /* '<S24>:1:44' */
            sumViol += L_inv - Ki[(int32_T)(1.0 + (real_T)i) - 1];
          }

          /* '<S24>:1:40' */
        }

        if (sumViol < tolerance) {
          /* '<S24>:1:48' */
          /* '<S24>:1:49' */
          tolerance = sumViol;

          /* '<S24>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S24>:1:53' */
          /* '<S24>:1:54' */
          rtb_roll_cmd = (controller_template_P.Constant2_Value_k[ireg + 21] * u
                          + controller_template_P.Constant2_Value_k[ireg] *
                          rtb_u_buff_out_idx) +
            controller_template_P.Constant3_Value_as[ireg];
          exitg = 1;
        } else {
          /* '<S24>:1:17' */
          ireg++;
        }
      } else {
        /* '<S24>:1:58' */
        /* '<S24>:1:59' */
        /* '<S24>:1:60' */
        rtb_roll_cmd = (controller_template_P.Constant2_Value_k[minreg + 21] * u
                        + controller_template_P.Constant2_Value_k[minreg] *
                        rtb_u_buff_out_idx) +
          controller_template_P.Constant3_Value_as[minreg];

        /* '<S24>:1:61' */
        /* U = U_prev; */
        exitg = 1;
      }
    } while (exitg == 0);

    /* Sum: '<S15>/Add' */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S22>:1' */
    /* '<S22>:1:3' */
    /* '<S22>:1:5' */
    /* '<S22>:1:6' */
    /* '<S22>:1:7' */
    u = rtb_DataTypeConversion[8] - rtb_X_ref_yaw[0];

    /* Saturate: '<S15>/Saturation' */
    if (u >= controller_template_P.Saturation_UpperSat_l) {
      u = controller_template_P.Saturation_UpperSat_l;
    } else {
      if (u <= controller_template_P.Saturation_LowerSat_b) {
        u = controller_template_P.Saturation_LowerSat_b;
      }
    }

    /* MATLAB Function: '<S21>/Ctrl_Xdir' incorporates:
     *  Constant: '<S21>/Constant'
     *  Constant: '<S21>/Constant1'
     *  Constant: '<S21>/Constant2'
     *  Constant: '<S21>/Constant3'
     *  Constant: '<S21>/Constant4'
     *  Saturate: '<S15>/Saturation'
     */
    sumViol = rt_roundd_snf(10000.0 * u) / 10000.0;

    /* '<S22>:1:9' */
    /* maxSize = max(Nc); */
    /* '<S22>:1:12' */
    /* '<S22>:1:13' */
    for (i = 0; i < 100; i++) {
      Hi_1[i] = 0.0;
      Ki[i] = 0.0;
    }

    /*  Find the proper region */
    /* '<S22>:1:16' */
    /* '<S22>:1:17' */
    /* '<S22>:1:18' */
    /* '<S22>:1:19' */
    isinside = 1;

    /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
    /* '<S22>:1:23' */
    for (i = 0; i < (int32_T)controller_template_P.Constant4_Value_m; i++) {
      /* '<S22>:1:23' */
      /* '<S22>:1:25' */
      Hi_1[(int32_T)(1.0 + (real_T)i) - 1] =
        controller_template_P.Constant_Value_d[(int32_T)(((1.0 + (real_T)i) +
        1.0) - 1.0) - 1];

      /* '<S22>:1:23' */
    }

    /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
    /* '<S22>:1:30' */
    for (k = 0; k < (int32_T)controller_template_P.Constant4_Value_m; k++) {
      /* '<S22>:1:30' */
      /* '<S22>:1:31' */
      Ki[(int32_T)(1.0 + (real_T)k) - 1] =
        controller_template_P.Constant1_Value_gz[(int32_T)(((1.0 + (real_T)k) +
        1.0) - 1.0) - 1];

      /* '<S22>:1:30' */
    }

    /* '<S22>:1:40' */
    for (i = 0; i < (int32_T)controller_template_P.Constant4_Value_m; i++) {
      /* '<S22>:1:40' */
      /* '<S22>:1:41' */
      if (Hi_1[(int32_T)(1.0 + (real_T)i) - 1] * sumViol - Ki[(int32_T)(1.0 +
           (real_T)i) - 1] > 1.0E-8) {
        /* '<S22>:1:42' */
        /* '<S22>:1:43' */
        isinside = 0;

        /* '<S22>:1:44' */
      }

      /* '<S22>:1:40' */
    }

    /*  extract the right control law */
    if (isinside == 1) {
      /* '<S22>:1:53' */
      /* '<S22>:1:54' */
      sumViol = controller_template_P.Constant2_Value_e * sumViol +
        controller_template_P.Constant3_Value_e;
    } else {
      /* '<S22>:1:60' */
      sumViol = controller_template_P.Constant2_Value_e * sumViol +
        controller_template_P.Constant3_Value_e;

      /* '<S22>:1:61' */
      /* U = U_prev; */
    }

    /* End of Outputs for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

    /* Outputs for Atomic SubSystem: '<S2>/decoupling and rotation' */
    /* Inport: '<S9>/bias_W' */
    controller_template_B.bias_W_b[0] = rtb_bias_W_idx;
    controller_template_B.bias_W_b[1] = rtb_bias_W_idx_0;
    controller_template_B.bias_W_b[2] = rtb_bias_W_idx_1;
    controller_template_B.bias_W_b[3] = rtb_bias_W_idx_2;

    /* Outputs for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* Inport: '<S9>/cmd_W' incorporates:
     *  MATLAB Function: '<S17>/Ctrl_Xdir'
     *  MATLAB Function: '<S19>/Ctrl_Xdir'
     *  MATLAB Function: '<S21>/Ctrl_Xdir'
     *  MATLAB Function: '<S23>/Ctrl_Xdir'
     *  Sum: '<S8>/Sum'
     *  Sum: '<S8>/Sum1'
     *  Sum: '<S8>/Sum2'
     *  Sum: '<S8>/Sum3'
     *  Sum: '<S8>/Sum5'
     */
    controller_template_B.cmd_W_h[0] = rtb_pitch_cmd - rtb_bias_W_idx;
    controller_template_B.cmd_W_h[1] = rtb_Saturation_l - rtb_bias_W_idx_0;
    controller_template_B.cmd_W_h[2] = (rtb_roll_cmd - rtb_bias_W_idx_1) +
      rtb_Product_g;
    controller_template_B.cmd_W_h[3] = sumViol - rtb_bias_W_idx_2;

    /* End of Outputs for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

    /* MATLAB Function: '<S25>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S25>/g'
     */
    controll_EmbeddedMATLABFunction
      (controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot,
       controller_template_B.sf_EmbeddedMATLABFunction.roll_rot,
       controller_template_B.cmd_W_h[0], controller_template_B.cmd_W_h[1],
       controller_template_B.cmd_W_h[2], rtb_DataTypeConversion[29],
       controller_template_P.g_Value,
       &controller_template_B.sf_EmbeddedMATLABFunction_m);

    /* MATLAB Function: '<S26>/Embedded MATLAB Function' */
    contro_EmbeddedMATLABFunction_l(rtb_DataTypeConversion[8],
      controller_template_B.sf_EmbeddedMATLABFunction_m.pitch_cmd_comp,
      controller_template_B.sf_EmbeddedMATLABFunction_m.roll_cmd_comp,
      controller_template_B.bias_W_b[0], controller_template_B.bias_W_b[1],
      &controller_template_B.sf_EmbeddedMATLABFunction_l);

    /* End of Outputs for SubSystem: '<S2>/decoupling and rotation' */
  } else {
    if (controller_template_DWork.FreeFlightPosCtrl_MODE) {
      controller_template_DWork.FreeFlightPosCtrl_MODE = FALSE;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/FreeFlight Pos Ctrl' */

  /* MultiPortSwitch: '<S4>/Multiport Switch' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  switch ((int32_T)rtb_DataTypeConversion[20]) {
   case 1:
   case 2:
   case 3:
    rtb_MultiportSwitch = controller_template_P.Constant1_Value_of;
    break;

   default:
    rtb_MultiportSwitch = controller_template_P.Constant2_Value_l;
    break;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch' */

  /* Outputs for Enabled SubSystem: '<Root>/pos controller' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (rtb_MultiportSwitch > 0.0) {
    if (!controller_template_DWork.poscontroller_MODE) {
      /* InitializeConditions for Atomic SubSystem: '<S7>/MAIN CONTROL LOOP1' */
      /* InitializeConditions for Delay: '<S31>/Integer Delay' */
      controller_template_DWork.IntegerDelay_DSTATE =
        controller_template_P.IntegerDelay_InitialCondition;

      /* InitializeConditions for Delay: '<S31>/Integer Delay1' */
      controller_template_DWork.IntegerDelay1_DSTATE =
        controller_template_P.IntegerDelay1_InitialCondition;

      /* InitializeConditions for Delay: '<S31>/Integer Delay2' */
      controller_template_DWork.IntegerDelay2_DSTATE =
        controller_template_P.IntegerDelay2_InitialCondition;

      /* InitializeConditions for Delay: '<S31>/Integer Delay3' */
      controller_template_DWork.IntegerDelay3_DSTATE =
        controller_template_P.IntegerDelay3_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S38>/Unit Delay1' */
      memcpy(&controller_template_DWork.UnitDelay1_DSTATE[0],
             &controller_template_P.UnitDelay1_InitialCondition[0], sizeof
             (real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
        controller_template_P.FixPtUnitDelay2_InitialConditio;

      /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_m[0] =
        controller_template_P.FixPtUnitDelay1_InitialConditio;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_m[1] =
        controller_template_P.FixPtUnitDelay1_InitialConditio;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_m[2] =
        controller_template_P.FixPtUnitDelay1_InitialConditio;

      /* InitializeConditions for UnitDelay: '<S37>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE[0] =
        controller_template_P.UnitDelay_InitialCondition[0];
      controller_template_DWork.UnitDelay_DSTATE[1] =
        controller_template_P.UnitDelay_InitialCondition[1];
      controller_template_DWork.UnitDelay_DSTATE[2] =
        controller_template_P.UnitDelay_InitialCondition[2];

      /* InitializeConditions for UnitDelay: '<S37>/Unit Delay1' */
      memcpy(&controller_template_DWork.UnitDelay1_DSTATE_f[0],
             &controller_template_P.UnitDelay1_InitialCondition_h[0], 30U *
             sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S40>/Unit Delay1' */
      memcpy(&controller_template_DWork.UnitDelay1_DSTATE_m[0],
             &controller_template_P.UnitDelay1_InitialCondition_b[0], sizeof
             (real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S49>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_f =
        controller_template_P.FixPtUnitDelay2_InitialCondit_d;

      /* InitializeConditions for UnitDelay: '<S49>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
        controller_template_P.FixPtUnitDelay1_InitialCondit_m;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
        controller_template_P.FixPtUnitDelay1_InitialCondit_m;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
        controller_template_P.FixPtUnitDelay1_InitialCondit_m;

      /* InitializeConditions for UnitDelay: '<S39>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_p[0] =
        controller_template_P.UnitDelay_InitialCondition_n[0];
      controller_template_DWork.UnitDelay_DSTATE_p[1] =
        controller_template_P.UnitDelay_InitialCondition_n[1];
      controller_template_DWork.UnitDelay_DSTATE_p[2] =
        controller_template_P.UnitDelay_InitialCondition_n[2];

      /* InitializeConditions for UnitDelay: '<S39>/Unit Delay1' */
      memcpy(&controller_template_DWork.UnitDelay1_DSTATE_mi[0],
             &controller_template_P.UnitDelay1_InitialCondition_o[0], 30U *
             sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S44>/Unit Delay1' */
      memcpy(&controller_template_DWork.UnitDelay1_DSTATE_c[0],
             &controller_template_P.UnitDelay1_InitialCondition_ou[0], 9U *
             sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S55>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_h =
        controller_template_P.FixPtUnitDelay2_InitialCondit_b;

      /* InitializeConditions for UnitDelay: '<S55>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_j[0] =
        controller_template_P.FixPtUnitDelay1_InitialCondit_p;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_j[1] =
        controller_template_P.FixPtUnitDelay1_InitialCondit_p;

      /* InitializeConditions for UnitDelay: '<S43>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_d[0] =
        controller_template_P.UnitDelay_InitialCondition_f[0];
      controller_template_DWork.UnitDelay_DSTATE_d[1] =
        controller_template_P.UnitDelay_InitialCondition_f[1];

      /* InitializeConditions for UnitDelay: '<S43>/Unit Delay1' */
      memcpy(&controller_template_DWork.UnitDelay1_DSTATE_j[0],
             &controller_template_P.UnitDelay1_InitialCondition_m[0], 30U *
             sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S42>/Unit Delay1' */
      memcpy(&controller_template_DWork.UnitDelay1_DSTATE_h[0],
             &controller_template_P.UnitDelay1_InitialCondition_oo[0], 9U *
             sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S52>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
        controller_template_P.FixPtUnitDelay2_InitialCondit_i;

      /* InitializeConditions for UnitDelay: '<S52>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_p[0] =
        controller_template_P.FixPtUnitDelay1_InitialCondit_k;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_p[1] =
        controller_template_P.FixPtUnitDelay1_InitialCondit_k;

      /* InitializeConditions for UnitDelay: '<S41>/Unit Delay' */
      for (i = 0; i < 6; i++) {
        controller_template_DWork.UnitDelay_DSTATE_j[i] =
          controller_template_P.UnitDelay_InitialCondition_k[i];
      }

      /* End of InitializeConditions for UnitDelay: '<S41>/Unit Delay' */

      /* InitializeConditions for UnitDelay: '<S41>/Unit Delay1' */
      memcpy(&controller_template_DWork.UnitDelay1_DSTATE_p[0],
             &controller_template_P.UnitDelay1_InitialCondition_g[0], 30U *
             sizeof(real_T));

      /* End of InitializeConditions for SubSystem: '<S7>/MAIN CONTROL LOOP1' */
      controller_template_DWork.poscontroller_MODE = TRUE;
    }

    /* MATLAB Function: '<S34>/Embedded MATLAB Function' */
    contro_EmbeddedMATLABFunction_f(rtb_DataTypeConversion[6],
      rtb_DataTypeConversion[7], rtb_Init[0], rtb_Init[1],
      rtb_DataTypeConversion[8],
      &controller_template_B.sf_EmbeddedMATLABFunction_h);

    /* Outputs for Atomic SubSystem: '<S7>/MAIN CONTROL LOOP1' */
    /* Delay: '<S31>/Integer Delay' */
    rtb_IntegerDelay = controller_template_DWork.IntegerDelay_DSTATE;

    /* Delay: '<S31>/Integer Delay1' */
    rtb_IntegerDelay1 = controller_template_DWork.IntegerDelay1_DSTATE;

    /* Delay: '<S31>/Integer Delay2' */
    rtb_IntegerDelay2 = controller_template_DWork.IntegerDelay2_DSTATE;

    /* Delay: '<S31>/Integer Delay3' */
    rtb_IntegerDelay3 = controller_template_DWork.IntegerDelay3_DSTATE;

    /* Product: '<S31>/Product' incorporates:
     *  Constant: '<S31>/gravity'
     */
    tolerance = controller_template_P.gravity_Value_a * rtb_DataTypeConversion
      [29];

    /* UnitDelay: '<S38>/Unit Delay1' */
    memcpy(&rtb_UnitDelay1[0], &controller_template_DWork.UnitDelay1_DSTATE[0],
           sizeof(real_T) << 4U);

    /* Switch: '<S46>/Init' incorporates:
     *  UnitDelay: '<S46>/FixPt Unit Delay1'
     *  UnitDelay: '<S46>/FixPt Unit Delay2'
     */
    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_l != 0) {
      rtb_Init_k[0] = rtb_DataTypeConversion[0];
    } else {
      rtb_Init_k[0] = controller_template_DWork.FixPtUnitDelay1_DSTATE_m[0];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_l != 0) {
      rtb_Init_k[1] = rtb_DataTypeConversion[3];
    } else {
      rtb_Init_k[1] = controller_template_DWork.FixPtUnitDelay1_DSTATE_m[1];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_l != 0) {
      rtb_Init_k[2] =
        controller_template_B.sf_EmbeddedMATLABFunction_h.pitch_rot;
    } else {
      rtb_Init_k[2] = controller_template_DWork.FixPtUnitDelay1_DSTATE_m[2];
    }

    /* End of Switch: '<S46>/Init' */

    /* MATLAB Function: '<S38>/discrete kalman filter' incorporates:
     *  Constant: '<S38>/A'
     *  Constant: '<S38>/B'
     *  Constant: '<S38>/C'
     *  Constant: '<S38>/Q'
     *  Constant: '<S38>/R'
     */
    controller_discretekalmanfilter(rtb_DataTypeConversion[0],
      rtb_DataTypeConversion[3],
      controller_template_B.sf_EmbeddedMATLABFunction_h.pitch_rot, rtb_Init_k,
      controller_template_B.sf_EmbeddedMATLABFunction_h.pitch_bias_rot, *(real_T
                                     (*)[16])&controller_template_P.A_Value[0], *
                                    (real_T (*)[4])&
      controller_template_P.B_Value[0], *(real_T (*)[12])&
      controller_template_P.C_Value[0], *(real_T (*)[16])&
      controller_template_P.Q_Value[0], *(real_T (*)[9])&
      controller_template_P.R_Value[0], rtb_IntegerDelay, rtb_UnitDelay1,
      &controller_template_B.sf_discretekalmanfilter);

    /* UnitDelay: '<S37>/Unit Delay' */
    rtb_UnitDelay[0] = controller_template_DWork.UnitDelay_DSTATE[0];
    rtb_UnitDelay[1] = controller_template_DWork.UnitDelay_DSTATE[1];
    rtb_UnitDelay[2] = controller_template_DWork.UnitDelay_DSTATE[2];

    /* UnitDelay: '<S37>/Unit Delay1' */
    memcpy(&rtb_UnitDelay1_k[0], &controller_template_DWork.UnitDelay1_DSTATE_f
           [0], 30U * sizeof(real_T));

    /* MATLAB Function: '<S37>/runFastGradient' incorporates:
     *  Constant: '<S37>/AA_delay'
     *  Constant: '<S37>/BB_delay'
     *  Constant: '<S37>/L'
     *  Constant: '<S37>/LL_PP'
     *  Constant: '<S37>/LL_U_ref_PP'
     *  Constant: '<S37>/LL_ref_PP'
     *  Constant: '<S37>/PP'
     *  Constant: '<S37>/TT_PP'
     *  Constant: '<S37>/V_max'
     *  Constant: '<S37>/betas'
     *  Constant: '<S37>/i_min'
     */
    controller_temp_runFastGradient(*(real_T (*)[900])&
      controller_template_P.TT_PP_Value[0], *(real_T (*)[90])&
      controller_template_P.LL_PP_Value[0], *(real_T (*)[2790])&
      controller_template_P.LL_ref_PP_Value[0], *(real_T (*)[900])&
      controller_template_P.LL_U_ref_PP_Value[0], *(real_T (*)[900])&
      controller_template_P.PP_Value[0], *(real_T (*)[9])&
      controller_template_P.AA_delay_Value[0], *(real_T (*)[9])&
      controller_template_P.BB_delay_Value[0],
      &controller_template_B.sf_discretekalmanfilter.state_est[0], rtb_X_ref_x, *
                                    (real_T (*)[30])&
      controller_template_P.V_max_Value[0], controller_template_P.i_min_Value,
                                    *(real_T (*)[7])&
      controller_template_P.betas_Value[0], controller_template_P.L_Value,
      rtb_UnitDelay, rtb_UnitDelay1_k, &controller_template_B.sf_runFastGradient);

    /* Saturate: '<S38>/Saturation' */
    if (controller_template_B.sf_discretekalmanfilter.state_est[3] >=
        controller_template_P.Saturation_UpperSat_e) {
      abspos = controller_template_P.Saturation_UpperSat_e;
    } else if (controller_template_B.sf_discretekalmanfilter.state_est[3] <=
               controller_template_P.Saturation_LowerSat_p) {
      abspos = controller_template_P.Saturation_LowerSat_p;
    } else {
      abspos = controller_template_B.sf_discretekalmanfilter.state_est[3];
    }

    /* End of Saturate: '<S38>/Saturation' */

    /* Sum: '<S31>/Sum' */
    rtb_pitch_cmd = controller_template_B.sf_runFastGradient.u_opt - abspos;

    /* UnitDelay: '<S40>/Unit Delay1' */
    memcpy(&rtb_UnitDelay1_f[0], &controller_template_DWork.UnitDelay1_DSTATE_m
           [0], sizeof(real_T) << 4U);

    /* Switch: '<S49>/Init' incorporates:
     *  UnitDelay: '<S49>/FixPt Unit Delay1'
     *  UnitDelay: '<S49>/FixPt Unit Delay2'
     */
    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_f != 0) {
      rtb_Init_i[0] = rtb_DataTypeConversion[1];
    } else {
      rtb_Init_i[0] = controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_f != 0) {
      rtb_Init_i[1] = rtb_DataTypeConversion[4];
    } else {
      rtb_Init_i[1] = controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_f != 0) {
      rtb_Init_i[2] = controller_template_B.sf_EmbeddedMATLABFunction_h.roll_rot;
    } else {
      rtb_Init_i[2] = controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2];
    }

    /* End of Switch: '<S49>/Init' */

    /* MATLAB Function: '<S40>/discrete kalman filter' incorporates:
     *  Constant: '<S40>/A'
     *  Constant: '<S40>/B'
     *  Constant: '<S40>/C'
     *  Constant: '<S40>/Q'
     *  Constant: '<S40>/R'
     */
    controller_discretekalmanfilter(rtb_DataTypeConversion[1],
      rtb_DataTypeConversion[4],
      controller_template_B.sf_EmbeddedMATLABFunction_h.roll_rot, rtb_Init_i,
      controller_template_B.sf_EmbeddedMATLABFunction_h.roll_bias_rot, *(real_T
                                     (*)[16])&controller_template_P.A_Value_g[0],
      *(real_T (*)[4])&controller_template_P.B_Value_f[0], *(real_T (*)[12])&
      controller_template_P.C_Value_m[0], *(real_T (*)[16])&
      controller_template_P.Q_Value_h[0], *(real_T (*)[9])&
      controller_template_P.R_Value_e[0], rtb_IntegerDelay1, rtb_UnitDelay1_f,
      &controller_template_B.sf_discretekalmanfilter_n);

    /* UnitDelay: '<S39>/Unit Delay' */
    rtb_UnitDelay_d[0] = controller_template_DWork.UnitDelay_DSTATE_p[0];
    rtb_UnitDelay_d[1] = controller_template_DWork.UnitDelay_DSTATE_p[1];
    rtb_UnitDelay_d[2] = controller_template_DWork.UnitDelay_DSTATE_p[2];

    /* UnitDelay: '<S39>/Unit Delay1' */
    memcpy(&rtb_UnitDelay1_i[0],
           &controller_template_DWork.UnitDelay1_DSTATE_mi[0], 30U * sizeof
           (real_T));

    /* MATLAB Function: '<S39>/runFastGradient' incorporates:
     *  Constant: '<S39>/AA_delay'
     *  Constant: '<S39>/BB_delay'
     *  Constant: '<S39>/L'
     *  Constant: '<S39>/LL_PP'
     *  Constant: '<S39>/LL_U_ref_PP'
     *  Constant: '<S39>/LL_ref_PP'
     *  Constant: '<S39>/PP'
     *  Constant: '<S39>/TT_PP'
     *  Constant: '<S39>/V_max'
     *  Constant: '<S39>/betas'
     *  Constant: '<S39>/i_min'
     */
    controller_temp_runFastGradient(*(real_T (*)[900])&
      controller_template_P.TT_PP_Value_n[0], *(real_T (*)[90])&
      controller_template_P.LL_PP_Value_h[0], *(real_T (*)[2790])&
      controller_template_P.LL_ref_PP_Value_l[0], *(real_T (*)[900])&
      controller_template_P.LL_U_ref_PP_Value_h[0], *(real_T (*)[900])&
      controller_template_P.PP_Value_a[0], *(real_T (*)[9])&
      controller_template_P.AA_delay_Value_j[0], *(real_T (*)[9])&
      controller_template_P.BB_delay_Value_c[0],
      &controller_template_B.sf_discretekalmanfilter_n.state_est[0], rtb_X_ref_y,
      *(real_T (*)[30])&controller_template_P.V_max_Value_g[0],
      controller_template_P.i_min_Value_l, *(real_T (*)[7])&
      controller_template_P.betas_Value_m[0], controller_template_P.L_Value_g,
      rtb_UnitDelay_d, rtb_UnitDelay1_i,
      &controller_template_B.sf_runFastGradient_a);

    /* Saturate: '<S40>/Saturation' */
    if (controller_template_B.sf_discretekalmanfilter_n.state_est[3] >=
        controller_template_P.Saturation_UpperSat_f) {
      rtb_Saturation_l = controller_template_P.Saturation_UpperSat_f;
    } else if (controller_template_B.sf_discretekalmanfilter_n.state_est[3] <=
               controller_template_P.Saturation_LowerSat_c) {
      rtb_Saturation_l = controller_template_P.Saturation_LowerSat_c;
    } else {
      rtb_Saturation_l =
        controller_template_B.sf_discretekalmanfilter_n.state_est[3];
    }

    /* End of Saturate: '<S40>/Saturation' */

    /* Sum: '<S31>/Sum1' */
    rtb_roll_cmd = controller_template_B.sf_runFastGradient_a.u_opt -
      rtb_Saturation_l;

    /* UnitDelay: '<S44>/Unit Delay1' */
    memcpy(&rtb_UnitDelay1_l[0], &controller_template_DWork.UnitDelay1_DSTATE_c
           [0], 9U * sizeof(real_T));

    /* Switch: '<S55>/Init' incorporates:
     *  UnitDelay: '<S55>/FixPt Unit Delay1'
     *  UnitDelay: '<S55>/FixPt Unit Delay2'
     */
    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_h != 0) {
      rtb_Init_j[0] = rtb_DataTypeConversion[2];
    } else {
      rtb_Init_j[0] = controller_template_DWork.FixPtUnitDelay1_DSTATE_j[0];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_h != 0) {
      rtb_Init_j[1] = rtb_DataTypeConversion[5];
    } else {
      rtb_Init_j[1] = controller_template_DWork.FixPtUnitDelay1_DSTATE_j[1];
    }

    /* End of Switch: '<S55>/Init' */

    /* MATLAB Function: '<S44>/discrete kalman filter' incorporates:
     *  Constant: '<S44>/A'
     *  Constant: '<S44>/B'
     *  Constant: '<S44>/C'
     *  Constant: '<S44>/Q'
     *  Constant: '<S44>/R'
     */
    controll_discretekalmanfilter_j(rtb_DataTypeConversion[2],
      rtb_DataTypeConversion[5], rtb_Init_j, rtb_Init[2], *(real_T (*)[9])&
      controller_template_P.A_Value_e[0], *(real_T (*)[3])&
      controller_template_P.B_Value_k[0], *(real_T (*)[6])&
      controller_template_P.C_Value_p[0], *(real_T (*)[9])&
      controller_template_P.Q_Value_g[0], *(real_T (*)[4])&
      controller_template_P.R_Value_c[0], rtb_IntegerDelay2, rtb_UnitDelay1_l,
      &controller_template_B.sf_discretekalmanfilter_d);

    /* MATLAB Function: '<S43>/runFastGradient' incorporates:
     *  Constant: '<S43>/AA_delay'
     *  Constant: '<S43>/BB_delay'
     *  Constant: '<S43>/L'
     *  Constant: '<S43>/LL_PP'
     *  Constant: '<S43>/LL_U_ref_PP'
     *  Constant: '<S43>/LL_ref_PP'
     *  Constant: '<S43>/PP'
     *  Constant: '<S43>/TT_PP'
     *  Constant: '<S43>/V_max'
     *  Constant: '<S43>/betas'
     *  Constant: '<S43>/i_min'
     *  UnitDelay: '<S43>/Unit Delay'
     *  UnitDelay: '<S43>/Unit Delay1'
     */
    /* MATLAB Function 'z controller MPC FG/runFastGradient': '<S54>:1' */
    /*  ugly, but simulink needs fix output sizes for vectors */
    /*  number of outputs u */
    /*  number of delay steps */
    /*  prediction horizon */
    /*  predict non-delayed state */
    /* '<S54>:1:14' */
    /*  TODO get U_ref from trajectory */
    /*  set optimization variables */
    /* '<S54>:1:21' */
    u = (controller_template_P.AA_delay_Value_f[0] *
         controller_template_B.sf_discretekalmanfilter_d.state_est[0] +
         controller_template_P.AA_delay_Value_f[2] *
         controller_template_B.sf_discretekalmanfilter_d.state_est[1]) +
      (controller_template_P.BB_delay_Value_n[0] *
       controller_template_DWork.UnitDelay_DSTATE_d[0] +
       controller_template_P.BB_delay_Value_n[2] *
       controller_template_DWork.UnitDelay_DSTATE_d[1]);
    rtb_bias_W_idx = (controller_template_P.AA_delay_Value_f[1] *
                      controller_template_B.sf_discretekalmanfilter_d.state_est
                      [0] + controller_template_P.AA_delay_Value_f[3] *
                      controller_template_B.sf_discretekalmanfilter_d.state_est
                      [1]) + (controller_template_P.BB_delay_Value_n[1] *
      controller_template_DWork.UnitDelay_DSTATE_d[0] +
      controller_template_P.BB_delay_Value_n[3] *
      controller_template_DWork.UnitDelay_DSTATE_d[1]);
    for (k = 0; k < 30; k++) {
      tmp[k] = 0.0;
      tmp[k] += controller_template_P.LL_PP_Value_l[k << 1] * u;
      tmp[k] += controller_template_P.LL_PP_Value_l[(k << 1) + 1] *
        rtb_bias_W_idx;
      rtb_X_ref_z_0[k] = 0.0;
      for (minreg = 0; minreg < 62; minreg++) {
        rtb_X_ref_z_0[k] += controller_template_P.LL_ref_PP_Value_d[62 * k +
          minreg] * rtb_X_ref_z[minreg];
      }
    }

    for (k = 0; k < 30; k++) {
      u = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        u += controller_template_P.LL_U_ref_PP_Value_k[30 * k + minreg] * 0.0;
      }

      LL_PP_ref[k] = (tmp[k] - rtb_X_ref_z_0[k]) - u;
    }

    /* '<S54>:1:22' */
    /*  TODO expand to X_ref, U_ref */
    /*  run fast gradient method */
    for (i = 0; i < 30; i++) {
      rtb_X_ref_z_0[i] = -controller_template_P.V_max_Value_a[i];
    }

    /*  Implementation of the fast gradient method for problem: */
    /*  J_star = min 0.5 V' TT_PP V + LL_PP V + MM  */
    /*  s.t. V_min <= V <= V_max */
    /*  */
    /*  Note: We do not assume V_min + V_max = 0! */
    /*  NOTE 2: LL_PP_t=LL_PP' is the transpose of LL_PP, this is done to */
    /*  optimize for speed */
    /*  */
    /*  The return value V is a feasible solution candidate and J is the associated cost. */
    /*  i_min is the number of iterations to be performed after initialization from */
    /*  V_init, and betas */
    /*  contains the pre-computed step-lengths whereas L is the maximum eigenvalue */
    /*  of TT_PP. */
    /*  If sol is non-empty then the */
    /*  following structure is assumed: */
    /*  sol.opt_val ... pre-computed optimal value (by another method) */
    /*  sol.eps     ... required absolute solution accuracy */
    /*  If sol is given, then the algorithm will terminate whenever J - */
    /*  sol.opt_val < sol.eps and return the actual number of iterations in */
    /*  actual_num_iters. If after i_min iterations the epsilon solution could */
    /*  not be reached, actual_num_iters = inf is returned */
    /*  */
    /*  (c) by Stefan Richter */
    /*  residuals = []; just for testing new convergence result idea */
    /*  check if there is the sol argument */
    /*  Run fast gradient method */
    /*  initialization: */
    L_inv = 1.0 / controller_template_P.L_Value_j;
    for (k = 0; k < 30; k++) {
      u = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        u += controller_template_P.TT_PP_Value_e[30 * minreg + k] *
          controller_template_DWork.UnitDelay1_DSTATE_j[minreg];
      }

      tmp[k] = u + LL_PP_ref[k];
    }

    for (k = 0; k < 30; k++) {
      rtb_bias_W_idx_0 = controller_template_DWork.UnitDelay1_DSTATE_j[k] -
        L_inv * tmp[k];
      if ((controller_template_P.V_max_Value_a[k] <= rtb_bias_W_idx_0) ||
          rtIsNaN(rtb_bias_W_idx_0)) {
        u = controller_template_P.V_max_Value_a[k];
      } else {
        u = rtb_bias_W_idx_0;
      }

      if ((rtb_X_ref_z_0[k] >= u) || rtIsNaN(u)) {
        u = rtb_X_ref_z_0[k];
      }

      V_ip[k] = u;
      U_star[k] = rtb_bias_W_idx_0;
      V_i[k] = u;
    }

    /*  now run the fast gradient method: */
    for (i = 0; i < (int32_T)controller_template_P.i_min_Value_p; i++) {
      for (k = 0; k < 30; k++) {
        u = 0.0;
        for (minreg = 0; minreg < 30; minreg++) {
          u += controller_template_P.TT_PP_Value_e[30 * minreg + k] *
            V_ip[minreg];
        }

        tmp[k] = u + LL_PP_ref[k];
      }

      /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
      /*      convergence result idea */
      for (k = 0; k < 30; k++) {
        rtb_bias_W_idx_0 = V_ip[k] - L_inv * tmp[k];
        if ((controller_template_P.V_max_Value_a[k] <= rtb_bias_W_idx_0) ||
            rtIsNaN(rtb_bias_W_idx_0)) {
          rtb_bias_W_idx_0 = controller_template_P.V_max_Value_a[k];
        }

        if ((rtb_X_ref_z_0[k] >= rtb_bias_W_idx_0) || rtIsNaN(rtb_bias_W_idx_0))
        {
          u = rtb_X_ref_z_0[k];
        } else {
          u = rtb_bias_W_idx_0;
        }

        rtb_bias_W_idx_0 = controller_template_P.betas_Value_o[(int32_T)(1.0 +
          (real_T)i) - 1] * (u - V_i[k]);
        rtb_bias_W_idx = u;
        u += rtb_bias_W_idx_0;
        U_star[k] = rtb_bias_W_idx_0;
        V_ip[k] = u;
        V_i[k] = rtb_bias_W_idx;
      }
    }

    /*  return values: */
    /*  plot(residuals) just for testing new convergence result idea */
    /* '<S54>:1:25' */
    /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
    /*  so don't forget to backtransform after termination: */
    /* '<S54>:1:32' */
    for (k = 0; k < 30; k++) {
      U_star[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        U_star[k] += controller_template_P.PP_Value_m[30 * minreg + k] *
          V_i[minreg];
      }
    }

    /*  save outputs for delayed system */
    /* '<S54>:1:38' */
    /*  set new initial guess */
    /* '<S54>:1:42' */
    /* '<S54>:1:44' */
    rtb_u_buff_out_idx = controller_template_DWork.UnitDelay_DSTATE_d[1];
    rtb_bias_W_idx_1 = U_star[0];

    /* Saturate: '<S44>/Saturation' */
    if (controller_template_B.sf_discretekalmanfilter_d.state_est[2] >=
        controller_template_P.Saturation_UpperSat_jz) {
      rtb_bias_W_idx_2 = controller_template_P.Saturation_UpperSat_jz;
    } else if (controller_template_B.sf_discretekalmanfilter_d.state_est[2] <=
               controller_template_P.Saturation_LowerSat_cp) {
      rtb_bias_W_idx_2 = controller_template_P.Saturation_LowerSat_cp;
    } else {
      rtb_bias_W_idx_2 =
        controller_template_B.sf_discretekalmanfilter_d.state_est[2];
    }

    /* End of Saturate: '<S44>/Saturation' */

    /* Sum: '<S31>/Sum2' incorporates:
     *  MATLAB Function: '<S43>/runFastGradient'
     */
    rtb_thrust_cmd = U_star[0] - rtb_bias_W_idx_2;

    /* UnitDelay: '<S42>/Unit Delay1' */
    memcpy(&rtb_UnitDelay1_kr[0],
           &controller_template_DWork.UnitDelay1_DSTATE_h[0], 9U * sizeof(real_T));

    /* Switch: '<S52>/Init' incorporates:
     *  UnitDelay: '<S52>/FixPt Unit Delay1'
     *  UnitDelay: '<S52>/FixPt Unit Delay2'
     */
    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_g != 0) {
      rtb_Init_n[0] = rtb_DataTypeConversion[8];
    } else {
      rtb_Init_n[0] = controller_template_DWork.FixPtUnitDelay1_DSTATE_p[0];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_g != 0) {
      rtb_Init_n[1] = rtb_DataTypeConversion[11];
    } else {
      rtb_Init_n[1] = controller_template_DWork.FixPtUnitDelay1_DSTATE_p[1];
    }

    /* End of Switch: '<S52>/Init' */

    /* MATLAB Function: '<S42>/discrete kalman filter' incorporates:
     *  Constant: '<S42>/A'
     *  Constant: '<S42>/B'
     *  Constant: '<S42>/C'
     *  Constant: '<S42>/Q'
     *  Constant: '<S42>/R'
     */
    controll_discretekalmanfilter_j(rtb_DataTypeConversion[8],
      rtb_DataTypeConversion[11], rtb_Init_n, rtb_Init[3], *(real_T (*)[9])&
      controller_template_P.A_Value_gk[0], *(real_T (*)[3])&
      controller_template_P.B_Value_ke[0], *(real_T (*)[6])&
      controller_template_P.C_Value_c[0], *(real_T (*)[9])&
      controller_template_P.Q_Value_n[0], *(real_T (*)[4])&
      controller_template_P.R_Value_k[0], rtb_IntegerDelay3, rtb_UnitDelay1_kr,
      &controller_template_B.sf_discretekalmanfilter_j);

    /* MATLAB Function: '<S41>/runFastGradient' incorporates:
     *  Constant: '<S41>/AA_delay'
     *  Constant: '<S41>/BB_delay'
     *  Constant: '<S41>/L'
     *  Constant: '<S41>/LL_PP'
     *  Constant: '<S41>/LL_U_ref_PP'
     *  Constant: '<S41>/LL_ref_PP'
     *  Constant: '<S41>/PP'
     *  Constant: '<S41>/TT_PP'
     *  Constant: '<S41>/V_max'
     *  Constant: '<S41>/betas'
     *  Constant: '<S41>/i_min'
     *  UnitDelay: '<S41>/Unit Delay'
     *  UnitDelay: '<S41>/Unit Delay1'
     */
    /* MATLAB Function 'yaw controller MPC FG/runFastGradient': '<S51>:1' */
    /*  ugly, but simulink needs fix output sizes for vectors */
    /*  number of outputs u */
    /*  number of delay steps */
    /*  prediction horizon */
    /*  predict non-delayed state */
    /* '<S51>:1:14' */
    /*  TODO get U_ref from trajectory */
    /*  set optimization variables */
    /* '<S51>:1:21' */
    for (k = 0; k < 2; k++) {
      tmp_0[k] = 0.0;
      for (minreg = 0; minreg < 6; minreg++) {
        tmp_0[k] += controller_template_P.BB_delay_Value_j[(minreg << 1) + k] *
          controller_template_DWork.UnitDelay_DSTATE_j[minreg];
      }
    }

    u = (controller_template_P.AA_delay_Value_e[0] *
         controller_template_B.sf_discretekalmanfilter_j.state_est[0] +
         controller_template_P.AA_delay_Value_e[2] *
         controller_template_B.sf_discretekalmanfilter_j.state_est[1]) + tmp_0[0];
    rtb_bias_W_idx = (controller_template_P.AA_delay_Value_e[1] *
                      controller_template_B.sf_discretekalmanfilter_j.state_est
                      [0] + controller_template_P.AA_delay_Value_e[3] *
                      controller_template_B.sf_discretekalmanfilter_j.state_est
                      [1]) + tmp_0[1];
    for (k = 0; k < 30; k++) {
      tmp[k] = 0.0;
      tmp[k] += controller_template_P.LL_PP_Value_o[k << 1] * u;
      tmp[k] += controller_template_P.LL_PP_Value_o[(k << 1) + 1] *
        rtb_bias_W_idx;
      rtb_X_ref_z_0[k] = 0.0;
      for (minreg = 0; minreg < 62; minreg++) {
        rtb_X_ref_z_0[k] += controller_template_P.LL_ref_PP_Value_b[62 * k +
          minreg] * rtb_X_ref_yaw[minreg];
      }
    }

    for (k = 0; k < 30; k++) {
      u = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        u += controller_template_P.LL_U_ref_PP_Value_g[30 * k + minreg] * 0.0;
      }

      LL_PP_ref[k] = (tmp[k] - rtb_X_ref_z_0[k]) - u;
    }

    /* '<S51>:1:22' */
    /*  TODO expand to X_ref, U_ref */
    /*  run fast gradient method */
    for (i = 0; i < 30; i++) {
      rtb_X_ref_z_0[i] = -controller_template_P.V_max_Value_h[i];
    }

    /*  Implementation of the fast gradient method for problem: */
    /*  J_star = min 0.5 V' TT_PP V + LL_PP V + MM  */
    /*  s.t. V_min <= V <= V_max */
    /*  */
    /*  Note: We do not assume V_min + V_max = 0! */
    /*  NOTE 2: LL_PP_t=LL_PP' is the transpose of LL_PP, this is done to */
    /*  optimize for speed */
    /*  */
    /*  The return value V is a feasible solution candidate and J is the associated cost. */
    /*  i_min is the number of iterations to be performed after initialization from */
    /*  V_init, and betas */
    /*  contains the pre-computed step-lengths whereas L is the maximum eigenvalue */
    /*  of TT_PP. */
    /*  If sol is non-empty then the */
    /*  following structure is assumed: */
    /*  sol.opt_val ... pre-computed optimal value (by another method) */
    /*  sol.eps     ... required absolute solution accuracy */
    /*  If sol is given, then the algorithm will terminate whenever J - */
    /*  sol.opt_val < sol.eps and return the actual number of iterations in */
    /*  actual_num_iters. If after i_min iterations the epsilon solution could */
    /*  not be reached, actual_num_iters = inf is returned */
    /*  */
    /*  (c) by Stefan Richter */
    /*  residuals = []; just for testing new convergence result idea */
    /*  check if there is the sol argument */
    /*  Run fast gradient method */
    /*  initialization: */
    L_inv = 1.0 / controller_template_P.L_Value_jd;
    for (k = 0; k < 30; k++) {
      u = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        u += controller_template_P.TT_PP_Value_ew[30 * minreg + k] *
          controller_template_DWork.UnitDelay1_DSTATE_p[minreg];
      }

      tmp[k] = u + LL_PP_ref[k];
    }

    for (k = 0; k < 30; k++) {
      rtb_bias_W_idx_0 = controller_template_DWork.UnitDelay1_DSTATE_p[k] -
        L_inv * tmp[k];
      if ((controller_template_P.V_max_Value_h[k] <= rtb_bias_W_idx_0) ||
          rtIsNaN(rtb_bias_W_idx_0)) {
        u = controller_template_P.V_max_Value_h[k];
      } else {
        u = rtb_bias_W_idx_0;
      }

      if ((rtb_X_ref_z_0[k] >= u) || rtIsNaN(u)) {
        u = rtb_X_ref_z_0[k];
      }

      V_ip[k] = u;
      U_star[k] = rtb_bias_W_idx_0;
      V_i_0[k] = u;
    }

    /*  now run the fast gradient method: */
    for (i = 0; i < (int32_T)controller_template_P.i_min_Value_a; i++) {
      for (k = 0; k < 30; k++) {
        u = 0.0;
        for (minreg = 0; minreg < 30; minreg++) {
          u += controller_template_P.TT_PP_Value_ew[30 * minreg + k] *
            V_ip[minreg];
        }

        tmp[k] = u + LL_PP_ref[k];
      }

      /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
      /*      convergence result idea */
      for (k = 0; k < 30; k++) {
        rtb_bias_W_idx_0 = V_ip[k] - L_inv * tmp[k];
        if ((controller_template_P.V_max_Value_h[k] <= rtb_bias_W_idx_0) ||
            rtIsNaN(rtb_bias_W_idx_0)) {
          rtb_bias_W_idx_0 = controller_template_P.V_max_Value_h[k];
        }

        if ((rtb_X_ref_z_0[k] >= rtb_bias_W_idx_0) || rtIsNaN(rtb_bias_W_idx_0))
        {
          u = rtb_X_ref_z_0[k];
        } else {
          u = rtb_bias_W_idx_0;
        }

        rtb_bias_W_idx_0 = controller_template_P.betas_Value_o5[(int32_T)(1.0 +
          (real_T)i) - 1] * (u - V_i_0[k]);
        rtb_bias_W_idx = u;
        u += rtb_bias_W_idx_0;
        U_star[k] = rtb_bias_W_idx_0;
        V_ip[k] = u;
        V_i_0[k] = rtb_bias_W_idx;
      }
    }

    /*  return values: */
    /*  plot(residuals) just for testing new convergence result idea */
    /* '<S51>:1:25' */
    /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
    /*  so don't forget to backtransform after termination: */
    /* '<S51>:1:32' */
    for (k = 0; k < 30; k++) {
      U_star[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        U_star[k] += controller_template_P.PP_Value_i[30 * minreg + k] *
          V_i_0[minreg];
      }
    }

    /* Saturate: '<S42>/Saturation' */
    /*  save outputs for delayed system */
    /* '<S51>:1:38' */
    /*  set new initial guess */
    /* '<S51>:1:42' */
    /* '<S51>:1:44' */
    if (controller_template_B.sf_discretekalmanfilter_j.state_est[2] >=
        controller_template_P.Saturation_UpperSat_o) {
      rtb_Product_g = controller_template_P.Saturation_UpperSat_o;
    } else if (controller_template_B.sf_discretekalmanfilter_j.state_est[2] <=
               controller_template_P.Saturation_LowerSat_k) {
      rtb_Product_g = controller_template_P.Saturation_LowerSat_k;
    } else {
      rtb_Product_g = controller_template_B.sf_discretekalmanfilter_j.state_est
        [2];
    }

    /* End of Saturate: '<S42>/Saturation' */

    /* Sum: '<S31>/Sum3' incorporates:
     *  MATLAB Function: '<S41>/runFastGradient'
     */
    sumViol = U_star[0] - rtb_Product_g;

    /* Update for Delay: '<S31>/Integer Delay' */
    controller_template_DWork.IntegerDelay_DSTATE = rtb_pitch_cmd;

    /* Update for Delay: '<S31>/Integer Delay1' */
    controller_template_DWork.IntegerDelay1_DSTATE = rtb_roll_cmd;

    /* Update for Delay: '<S31>/Integer Delay2' */
    controller_template_DWork.IntegerDelay2_DSTATE = rtb_thrust_cmd;

    /* Update for Delay: '<S31>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE = sumViol;

    /* Update for UnitDelay: '<S38>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE[0],
           &controller_template_B.sf_discretekalmanfilter.P_est[0], sizeof
           (real_T) << 4U);

    /* Update for UnitDelay: '<S46>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S46>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
      controller_template_P.FixPtConstant_Value;

    /* Update for UnitDelay: '<S46>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_m[0] =
      controller_template_B.sf_discretekalmanfilter.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_m[1] =
      controller_template_B.sf_discretekalmanfilter.state_est[1];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_m[2] =
      controller_template_B.sf_discretekalmanfilter.state_est[2];

    /* Update for UnitDelay: '<S37>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE[0] =
      controller_template_B.sf_runFastGradient.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE[1] =
      controller_template_B.sf_runFastGradient.u_buff_out[1];
    controller_template_DWork.UnitDelay_DSTATE[2] =
      controller_template_B.sf_runFastGradient.u_buff_out[2];

    /* Update for UnitDelay: '<S37>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_f[0],
           &controller_template_B.sf_runFastGradient.V_init_out[0], 30U * sizeof
           (real_T));

    /* Update for UnitDelay: '<S40>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_m[0],
           &controller_template_B.sf_discretekalmanfilter_n.P_est[0], sizeof
           (real_T) << 4U);

    /* Update for UnitDelay: '<S49>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S49>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_f =
      controller_template_P.FixPtConstant_Value_p;

    /* Update for UnitDelay: '<S49>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[1];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[2];

    /* Update for UnitDelay: '<S39>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_p[0] =
      controller_template_B.sf_runFastGradient_a.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE_p[1] =
      controller_template_B.sf_runFastGradient_a.u_buff_out[1];
    controller_template_DWork.UnitDelay_DSTATE_p[2] =
      controller_template_B.sf_runFastGradient_a.u_buff_out[2];

    /* Update for UnitDelay: '<S39>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_mi[0],
           &controller_template_B.sf_runFastGradient_a.V_init_out[0], 30U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S44>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_c[0],
           &controller_template_B.sf_discretekalmanfilter_d.P_est[0], 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S55>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S55>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_h =
      controller_template_P.FixPtConstant_Value_j;

    /* Update for UnitDelay: '<S55>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_j[0] =
      controller_template_B.sf_discretekalmanfilter_d.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_j[1] =
      controller_template_B.sf_discretekalmanfilter_d.state_est[1];

    /* Update for UnitDelay: '<S43>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_d[0] = rtb_u_buff_out_idx;
    controller_template_DWork.UnitDelay_DSTATE_d[1] = rtb_bias_W_idx_1;

    /* Update for UnitDelay: '<S43>/Unit Delay1' incorporates:
     *  MATLAB Function: '<S43>/runFastGradient'
     */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_j[0], &V_i[1], 29U *
           sizeof(real_T));
    controller_template_DWork.UnitDelay1_DSTATE_j[29] = 0.0;

    /* Update for UnitDelay: '<S42>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_h[0],
           &controller_template_B.sf_discretekalmanfilter_j.P_est[0], 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S52>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S52>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
      controller_template_P.FixPtConstant_Value_p5;

    /* Update for UnitDelay: '<S52>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_p[0] =
      controller_template_B.sf_discretekalmanfilter_j.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_p[1] =
      controller_template_B.sf_discretekalmanfilter_j.state_est[1];

    /* MATLAB Function: '<S41>/runFastGradient' incorporates:
     *  UnitDelay: '<S41>/Unit Delay'
     *  Update for UnitDelay: '<S41>/Unit Delay'
     */
    for (k = 0; k < 5; k++) {
      tmp_1[k] = controller_template_DWork.UnitDelay_DSTATE_j[1 + k];
    }

    tmp_1[5] = U_star[0];

    /* Update for UnitDelay: '<S41>/Unit Delay' */
    for (k = 0; k < 6; k++) {
      controller_template_DWork.UnitDelay_DSTATE_j[k] = tmp_1[k];
    }

    /* Update for UnitDelay: '<S41>/Unit Delay1' incorporates:
     *  MATLAB Function: '<S41>/runFastGradient'
     */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_p[0], &V_i_0[1], 29U *
           sizeof(real_T));
    controller_template_DWork.UnitDelay1_DSTATE_p[29] = 0.0;

    /* End of Outputs for SubSystem: '<S7>/MAIN CONTROL LOOP1' */

    /* Outputs for Atomic SubSystem: '<S7>/decoupling and rotation' */
    /* Inport: '<S32>/bias_W' */
    controller_template_B.bias_W[0] = abspos;
    controller_template_B.bias_W[1] = rtb_Saturation_l;
    controller_template_B.bias_W[2] = rtb_bias_W_idx_2;
    controller_template_B.bias_W[3] = rtb_Product_g;

    /* Inport: '<S32>/cmd_W' incorporates:
     *  Sum: '<S31>/Sum5'
     */
    controller_template_B.cmd_W[0] = rtb_pitch_cmd;
    controller_template_B.cmd_W[1] = rtb_roll_cmd;

    /* Outputs for Atomic SubSystem: '<S7>/MAIN CONTROL LOOP1' */
    controller_template_B.cmd_W[2] = rtb_thrust_cmd + tolerance;

    /* End of Outputs for SubSystem: '<S7>/MAIN CONTROL LOOP1' */
    controller_template_B.cmd_W[3] = sumViol;

    /* MATLAB Function: '<S57>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S57>/g'
     */
    controll_EmbeddedMATLABFunction
      (controller_template_B.sf_EmbeddedMATLABFunction_h.pitch_rot,
       controller_template_B.sf_EmbeddedMATLABFunction_h.roll_rot,
       controller_template_B.cmd_W[0], controller_template_B.cmd_W[1],
       controller_template_B.cmd_W[2], rtb_DataTypeConversion[29],
       controller_template_P.g_Value_j,
       &controller_template_B.sf_EmbeddedMATLABFunction_i);

    /* MATLAB Function: '<S58>/Embedded MATLAB Function' */
    contro_EmbeddedMATLABFunction_l(rtb_DataTypeConversion[8],
      controller_template_B.sf_EmbeddedMATLABFunction_i.pitch_cmd_comp,
      controller_template_B.sf_EmbeddedMATLABFunction_i.roll_cmd_comp,
      controller_template_B.bias_W[0], controller_template_B.bias_W[1],
      &controller_template_B.sf_EmbeddedMATLABFunction_f);

    /* End of Outputs for SubSystem: '<S7>/decoupling and rotation' */
  } else {
    if (controller_template_DWork.poscontroller_MODE) {
      controller_template_DWork.poscontroller_MODE = FALSE;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/pos controller' */

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/gravity'
   */
  rtb_Product_g = controller_template_P.gravity_Value_b *
    rtb_DataTypeConversion[29];

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S3>/- gravity'
   *  Product: '<S3>/Product'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    u = controller_template_B.sf_EmbeddedMATLABFunction_m.thrust_comp;
  } else if (rtb_MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    u = controller_template_B.sf_EmbeddedMATLABFunction_i.thrust_comp;
  } else {
    u = controller_template_P.gravity_Value_k * rtb_DataTypeConversion[29];
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Sum: '<S5>/Sum2' incorporates:
   *  Gain: '<S5>/trhust_cmd2thrust'
   *  Sum: '<S5>/Sum3'
   */
  L_inv = (u - rtb_Product_g) * controller_template_P.trhust_cmd2thrust_Gain +
    rtb_Product_g;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S3>/yaw'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    u = controller_template_B.cmd_W_h[3];
  } else if (rtb_MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    u = controller_template_B.cmd_W[3];
  } else {
    u = controller_template_P.yaw_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Gain: '<S5>/yaw_cmd2yaw' */
  rtb_Product_g = controller_template_P.yaw_cmd2yaw_Gain * u;

  /* ManualSwitch: '<S5>/Manual Switch' incorporates:
   *  Constant: '<S5>/yaw_rate'
   */
  if (controller_template_P.ManualSwitch_CurrentSetting != 1) {
    rtb_Product_g = controller_template_P.yaw_rate_Value;
  }

  /* End of ManualSwitch: '<S5>/Manual Switch' */

  /* Gain: '<S5>/Gain4' */
  rtb_Product_g *= controller_template_P.Gain4_Gain;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S3>/pitch'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    u = controller_template_B.sf_EmbeddedMATLABFunction_l.pitch_rot;
  } else if (rtb_MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    u = controller_template_B.sf_EmbeddedMATLABFunction_f.pitch_rot;
  } else {
    u = controller_template_P.pitch_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Outport: '<Root>/cmd_out' incorporates:
   *  Constant: '<S5>/pitch_offset'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Gain: '<S5>/Gain1'
   *  Gain: '<S5>/pitch_cmd2pitch'
   *  Sum: '<S5>/Sum1'
   */
  arg_cmd_out[0] = (real32_T)((u - controller_template_P.pitch_offset_Value) *
    controller_template_P.pitch_cmd2pitch_Gain *
    controller_template_P.Gain1_Gain);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S3>/roll'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    u = controller_template_B.sf_EmbeddedMATLABFunction_l.roll_rot;
  } else if (rtb_MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    u = controller_template_B.sf_EmbeddedMATLABFunction_f.roll_rot;
  } else {
    u = controller_template_P.roll_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Outport: '<Root>/cmd_out' incorporates:
   *  Constant: '<S5>/roll_offset'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain2'
   *  Gain: '<S5>/Gain3'
   *  Gain: '<S5>/roll_cmd2roll'
   *  Sum: '<S5>/Sum'
   */
  arg_cmd_out[1] = (real32_T)((u - controller_template_P.roll_offset_Value) *
    controller_template_P.roll_cmd2roll_Gain * controller_template_P.Gain2_Gain);
  arg_cmd_out[2] = (real32_T)(controller_template_P.Gain_Gain * L_inv *
    controller_template_P.Gain3_Gain);
  arg_cmd_out[3] = (real32_T)rtb_Product_g;

  /* Switch: '<S30>/Reset' incorporates:
   *  Constant: '<S30>/Initial Condition'
   *  Constant: '<S3>/pitch_bias'
   *  Switch: '<Root>/Switch1'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch1 != 0.0) {
    rtb_Xnew[0] = controller_template_P.InitialCondition_Value;
    rtb_Xnew[1] = controller_template_P.InitialCondition_Value;
    rtb_Xnew[2] = controller_template_P.InitialCondition_Value;
    rtb_Xnew[3] = controller_template_P.InitialCondition_Value;
  } else {
    if (rtb_MultiportSwitch2 != 0.0) {
      /* Switch: '<Root>/Switch1' */
      rtb_Xnew[0] =
        controller_template_B.sf_EmbeddedMATLABFunction_l.pitch_bias_rot;
    } else if (rtb_MultiportSwitch != 0.0) {
      /* Switch: '<Root>/Switch3' incorporates:
       *  Switch: '<Root>/Switch1'
       */
      rtb_Xnew[0] =
        controller_template_B.sf_EmbeddedMATLABFunction_f.pitch_bias_rot;
    } else {
      rtb_Xnew[0] = controller_template_P.pitch_bias_Value;
    }

    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<S3>/pitch_bias'
     *  Constant: '<S3>/roll_bias'
     *  Switch: '<Root>/Switch1'
     *  Switch: '<Root>/Switch3'
     */
    if (rtb_MultiportSwitch2 != 0.0) {
      rtb_Xnew[1] =
        controller_template_B.sf_EmbeddedMATLABFunction_l.roll_bias_rot;
    } else if (rtb_MultiportSwitch != 0.0) {
      /* Switch: '<Root>/Switch3' */
      rtb_Xnew[1] =
        controller_template_B.sf_EmbeddedMATLABFunction_f.roll_bias_rot;
    } else {
      rtb_Xnew[1] = controller_template_P.roll_bias_Value;
    }

    /* End of Switch: '<Root>/Switch1' */

    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<S3>/thrust_bias'
     *  Switch: '<Root>/Switch3'
     */
    if (rtb_MultiportSwitch2 != 0.0) {
      rtb_Xnew[2] = controller_template_B.bias_W_b[2];
    } else if (rtb_MultiportSwitch != 0.0) {
      /* Switch: '<Root>/Switch3' */
      rtb_Xnew[2] = controller_template_B.bias_W[2];
    } else {
      rtb_Xnew[2] = controller_template_P.thrust_bias_Value;
    }

    /* End of Switch: '<Root>/Switch1' */

    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<S3>/yaw_rate_bias'
     *  Switch: '<Root>/Switch3'
     */
    if (rtb_MultiportSwitch2 != 0.0) {
      rtb_Xnew[3] = controller_template_B.bias_W_b[3];
    } else if (rtb_MultiportSwitch != 0.0) {
      /* Switch: '<Root>/Switch3' */
      rtb_Xnew[3] = controller_template_B.bias_W[3];
    } else {
      rtb_Xnew[3] = controller_template_P.yaw_rate_bias_Value;
    }

    /* End of Switch: '<Root>/Switch1' */
  }

  /* End of Switch: '<S30>/Reset' */

  /* Update for UnitDelay: '<S30>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S30>/FixPt Constant'
   */
  controller_template_DWork.FixPtUnitDelay2_DSTATE =
    controller_template_P.FixPtConstant_Value_l;

  /* Update for UnitDelay: '<S30>/FixPt Unit Delay1' */
  controller_template_DWork.FixPtUnitDelay1_DSTATE[0] = rtb_Xnew[0];
  controller_template_DWork.FixPtUnitDelay1_DSTATE[1] = rtb_Xnew[1];
  controller_template_DWork.FixPtUnitDelay1_DSTATE[2] = rtb_Xnew[2];
  controller_template_DWork.FixPtUnitDelay1_DSTATE[3] = rtb_Xnew[3];
}

/* Model initialize function */
void FG_traj_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(controller_template_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &controller_template_B), 0,
                sizeof(BlockIO_controller_template));

  /* states (dwork) */
  (void) memset((void *)&controller_template_DWork, 0,
                sizeof(D_Work_controller_template));

  {
    int32_T i;

    /* InitializeConditions for Enabled SubSystem: '<Root>/pos controller' */
    /* InitializeConditions for Atomic SubSystem: '<S7>/MAIN CONTROL LOOP1' */
    /* InitializeConditions for Delay: '<S31>/Integer Delay' */
    controller_template_DWork.IntegerDelay_DSTATE =
      controller_template_P.IntegerDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S31>/Integer Delay1' */
    controller_template_DWork.IntegerDelay1_DSTATE =
      controller_template_P.IntegerDelay1_InitialCondition;

    /* InitializeConditions for Delay: '<S31>/Integer Delay2' */
    controller_template_DWork.IntegerDelay2_DSTATE =
      controller_template_P.IntegerDelay2_InitialCondition;

    /* InitializeConditions for Delay: '<S31>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE =
      controller_template_P.IntegerDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S38>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE[0],
           &controller_template_P.UnitDelay1_InitialCondition[0], sizeof(real_T)
           << 4U);

    /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
      controller_template_P.FixPtUnitDelay2_InitialConditio;

    /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_m[0] =
      controller_template_P.FixPtUnitDelay1_InitialConditio;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_m[1] =
      controller_template_P.FixPtUnitDelay1_InitialConditio;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_m[2] =
      controller_template_P.FixPtUnitDelay1_InitialConditio;

    /* InitializeConditions for UnitDelay: '<S37>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE[0] =
      controller_template_P.UnitDelay_InitialCondition[0];
    controller_template_DWork.UnitDelay_DSTATE[1] =
      controller_template_P.UnitDelay_InitialCondition[1];
    controller_template_DWork.UnitDelay_DSTATE[2] =
      controller_template_P.UnitDelay_InitialCondition[2];

    /* InitializeConditions for UnitDelay: '<S37>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_f[0],
           &controller_template_P.UnitDelay1_InitialCondition_h[0], 30U * sizeof
           (real_T));

    /* InitializeConditions for UnitDelay: '<S40>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_m[0],
           &controller_template_P.UnitDelay1_InitialCondition_b[0], sizeof
           (real_T) << 4U);

    /* InitializeConditions for UnitDelay: '<S49>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_f =
      controller_template_P.FixPtUnitDelay2_InitialCondit_d;

    /* InitializeConditions for UnitDelay: '<S49>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
      controller_template_P.FixPtUnitDelay1_InitialCondit_m;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
      controller_template_P.FixPtUnitDelay1_InitialCondit_m;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
      controller_template_P.FixPtUnitDelay1_InitialCondit_m;

    /* InitializeConditions for UnitDelay: '<S39>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_p[0] =
      controller_template_P.UnitDelay_InitialCondition_n[0];
    controller_template_DWork.UnitDelay_DSTATE_p[1] =
      controller_template_P.UnitDelay_InitialCondition_n[1];
    controller_template_DWork.UnitDelay_DSTATE_p[2] =
      controller_template_P.UnitDelay_InitialCondition_n[2];

    /* InitializeConditions for UnitDelay: '<S39>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_mi[0],
           &controller_template_P.UnitDelay1_InitialCondition_o[0], 30U * sizeof
           (real_T));

    /* InitializeConditions for UnitDelay: '<S44>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_c[0],
           &controller_template_P.UnitDelay1_InitialCondition_ou[0], 9U * sizeof
           (real_T));

    /* InitializeConditions for UnitDelay: '<S55>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_h =
      controller_template_P.FixPtUnitDelay2_InitialCondit_b;

    /* InitializeConditions for UnitDelay: '<S55>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_j[0] =
      controller_template_P.FixPtUnitDelay1_InitialCondit_p;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_j[1] =
      controller_template_P.FixPtUnitDelay1_InitialCondit_p;

    /* InitializeConditions for UnitDelay: '<S43>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_d[0] =
      controller_template_P.UnitDelay_InitialCondition_f[0];
    controller_template_DWork.UnitDelay_DSTATE_d[1] =
      controller_template_P.UnitDelay_InitialCondition_f[1];

    /* InitializeConditions for UnitDelay: '<S43>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_j[0],
           &controller_template_P.UnitDelay1_InitialCondition_m[0], 30U * sizeof
           (real_T));

    /* InitializeConditions for UnitDelay: '<S42>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_h[0],
           &controller_template_P.UnitDelay1_InitialCondition_oo[0], 9U * sizeof
           (real_T));

    /* InitializeConditions for UnitDelay: '<S52>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
      controller_template_P.FixPtUnitDelay2_InitialCondit_i;

    /* InitializeConditions for UnitDelay: '<S52>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_p[0] =
      controller_template_P.FixPtUnitDelay1_InitialCondit_k;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_p[1] =
      controller_template_P.FixPtUnitDelay1_InitialCondit_k;

    /* InitializeConditions for UnitDelay: '<S41>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      controller_template_DWork.UnitDelay_DSTATE_j[i] =
        controller_template_P.UnitDelay_InitialCondition_k[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S41>/Unit Delay' */

    /* InitializeConditions for UnitDelay: '<S41>/Unit Delay1' */
    memcpy(&controller_template_DWork.UnitDelay1_DSTATE_p[0],
           &controller_template_P.UnitDelay1_InitialCondition_g[0], 30U * sizeof
           (real_T));

    /* End of InitializeConditions for SubSystem: '<S7>/MAIN CONTROL LOOP1' */
    /* End of InitializeConditions for SubSystem: '<Root>/pos controller' */
  }

  /* InitializeConditions for UnitDelay: '<S30>/FixPt Unit Delay2' */
  controller_template_DWork.FixPtUnitDelay2_DSTATE =
    controller_template_P.FixPtUnitDelay2_InitialCondit_k;

  /* InitializeConditions for UnitDelay: '<S30>/FixPt Unit Delay1' */
  controller_template_DWork.FixPtUnitDelay1_DSTATE[0] =
    controller_template_P.FixPtUnitDelay1_InitialCondit_b;
  controller_template_DWork.FixPtUnitDelay1_DSTATE[1] =
    controller_template_P.FixPtUnitDelay1_InitialCondit_b;
  controller_template_DWork.FixPtUnitDelay1_DSTATE[2] =
    controller_template_P.FixPtUnitDelay1_InitialCondit_b;
  controller_template_DWork.FixPtUnitDelay1_DSTATE[3] =
    controller_template_P.FixPtUnitDelay1_InitialCondit_b;
}

/* Model terminate function */
void controller_template_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
