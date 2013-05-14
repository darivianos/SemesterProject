/*
 * File: controller_template.cpp
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.404
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Aug  6 2011)
 * C/C++ source code generated on : Tue May 14 19:09:51 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "controller_template.h"
#include "controller_template_private.h"
#include "controller_template_dt.h"

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
static void controller_template_mrdivide(const real_T A[4], real_T B, real_T y[4]);
static void controller_template_round_b(real_T x[4]);
static void controller_template_mrdivide_b(const real_T A[4], real_T B, real_T
  y[4]);
static void rate_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (controller_template_M->Timing.TaskCounters.TID[1])++;
  if ((controller_template_M->Timing.TaskCounters.TID[1]) > 3) {/* Sample time: [0.08s, 0.0s] */
    controller_template_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S25>/MATLAB Function'
 *    '<S30>/MATLAB Function'
 */
void controller__MATLABFunction_Init(rtDW_MATLABFunction_controller_ *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c7_controller_templat = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S25>/MATLAB Function'
 *    '<S30>/MATLAB Function'
 */
void controller_templ_MATLABFunction(const real_T rtu_x[4], const real_T rtu_A
  [16], const real_T rtu_B[8], real_T rtu_u, rtB_MATLABFunction_controller_t
  *localB, rtDW_MATLABFunction_controller_ *localDW)
{
  real_T tmp[4];
  int32_T i;
  real_T tmp_0[4];
  real_T tmp_1;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/PitchPropagate/MATLAB Function': '<S26>:1' */
  /* '<S26>:1:4' */
  for (i = 0; i < 4; i++) {
    tmp_1 = rtu_A[i + 12] * rtu_x[3] + (rtu_A[i + 8] * rtu_x[2] + (rtu_A[i + 4] *
      rtu_x[1] + rtu_A[i] * rtu_x[0]));
    tmp[i] = tmp_1;
  }

  for (i = 0; i < 4; i++) {
    tmp_0[i] = rtu_B[i + 4] * 0.0 + rtu_B[i] * rtu_u;
  }

  localB->y[0] = tmp[0] + tmp_0[0];
  localB->y[1] = tmp[1] + tmp_0[1];
  localB->y[2] = tmp[2] + tmp_0[2];
  localB->y[3] = tmp[3] + tmp_0[3];
}

/*
 * Initial conditions for atomic system:
 *    '<S11>/Embedded MATLAB Function'
 *    '<S50>/Embedded MATLAB Function'
 */
void con_EmbeddedMATLABFunction_Init(rtDW_EmbeddedMATLABFunction_con *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c26_Hquad_control_LIB = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S11>/Embedded MATLAB Function'
 *    '<S50>/Embedded MATLAB Function'
 */
void controll_EmbeddedMATLABFunction(real_T rtu_roll, real_T rtu_pitch, real_T
  rtu_pitch_bias, real_T rtu_roll_bias, real_T rtu_yaw,
  rtB_EmbeddedMATLABFunction_cont *localB, rtDW_EmbeddedMATLABFunction_con
  *localDW)
{
  real_T sin_yaw;
  real_T cos_yaw;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'rotate to world frame/Embedded MATLAB Function': '<S44>:1' */
  /* '<S44>:1:5' */
  sin_yaw = sin(rtu_yaw);

  /* '<S44>:1:6' */
  cos_yaw = cos(rtu_yaw);

  /* '<S44>:1:8' */
  /* '<S44>:1:10' */
  /* '<S44>:1:11' */
  localB->pitch_rot = cos_yaw * rtu_pitch + sin_yaw * rtu_roll;

  /* '<S44>:1:12' */
  localB->roll_rot = -sin_yaw * rtu_pitch + cos_yaw * rtu_roll;

  /* '<S44>:1:14' */
  /* '<S44>:1:15' */
  localB->pitch_bias_rot = cos_yaw * rtu_pitch_bias + sin_yaw * rtu_roll_bias;

  /* '<S44>:1:16' */
  localB->roll_bias_rot = -sin_yaw * rtu_pitch_bias + cos_yaw * rtu_roll_bias;
}

/*
 * Initial conditions for atomic system:
 *    '<S53>/runFastGradient'
 *    '<S55>/runFastGradient'
 */
void controller_runFastGradient_Init(rtDW_runFastGradient_controller *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c6_Hquad_control_LIB_ = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S53>/runFastGradient'
 *    '<S55>/runFastGradient'
 */
void controller_temp_runFastGradient(const real_T rtu_TT_PP[900], const real_T
  rtu_LL_PP[90], const real_T rtu_LL_ref_PP[2790], const real_T rtu_LL_U_ref_PP
  [900], const real_T rtu_MM[9], const real_T rtu_PP[900], const real_T
  rtu_AA_delay[9], const real_T rtu_BB_delay[9], const real_T rtu_x[3], const
  real_T rtu_X_ref[93], const real_T rtu_V_max[30], real_T rtu_i_min, const
  real_T rtu_betas[7], real_T rtu_L, const real_T rtu_u_buff[3], const real_T
  rtu_V_init[30], rtB_runFastGradient_controller_ *localB,
  rtDW_runFastGradient_controller *localDW)
{
  real_T LL_PP_ref[30];
  real_T U_star[30];
  real_T y[3];
  real_T L_inv;
  real_T V_i[30];
  real_T V_ip[30];
  real_T b_y[30];
  real_T d_y;
  int32_T i;
  real_T tmp[3];
  int32_T i_0;
  real_T tmp_0[3];
  real_T x_predicted[30];
  real_T tmp_1[30];
  int32_T i_1;
  real_T U_star_0;
  real_T V_i_0;
  real_T x_predicted_idx;
  real_T x_predicted_idx_0;
  real_T x_predicted_idx_1;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'x controller MPC FG  /runFastGradient': '<S61>:1' */
  /*  ugly, but simulink needs fix output sizes for vectors */
  /*  number of outputs u */
  /*  number of delay steps */
  /*  prediction horizon */
  /*  predict non-delayed state */
  /* '<S61>:1:14' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp[i_0] = rtu_AA_delay[i_0 + 6] * rtu_x[2] + (rtu_AA_delay[i_0 + 3] *
      rtu_x[1] + rtu_AA_delay[i_0] * rtu_x[0]);
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    tmp_0[i_0] = rtu_BB_delay[i_0 + 6] * rtu_u_buff[2] + (rtu_BB_delay[i_0 + 3] *
      rtu_u_buff[1] + rtu_BB_delay[i_0] * rtu_u_buff[0]);
  }

  x_predicted_idx = tmp[0] + tmp_0[0];
  x_predicted_idx_0 = tmp[1] + tmp_0[1];
  x_predicted_idx_1 = tmp[2] + tmp_0[2];

  /*  TODO get U_ref from trajectory */
  /*  set optimization variables */
  /* '<S61>:1:21' */
  for (i_0 = 0; i_0 < 30; i_0++) {
    x_predicted[i_0] = 0.0;
    x_predicted[i_0] += rtu_LL_PP[3 * i_0] * x_predicted_idx;
    x_predicted[i_0] += rtu_LL_PP[3 * i_0 + 1] * x_predicted_idx_0;
    x_predicted[i_0] += rtu_LL_PP[3 * i_0 + 2] * x_predicted_idx_1;
    tmp_1[i_0] = 0.0;
    for (i_1 = 0; i_1 < 93; i_1++) {
      tmp_1[i_0] += rtu_LL_ref_PP[93 * i_0 + i_1] * rtu_X_ref[i_1];
    }
  }

  for (i_0 = 0; i_0 < 30; i_0++) {
    d_y = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      d_y += rtu_LL_U_ref_PP[30 * i_0 + i_1] * 0.0;
    }

    LL_PP_ref[i_0] = (x_predicted[i_0] - tmp_1[i_0]) - d_y;
  }

  /* '<S61>:1:22' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    y[i_0] = rtu_MM[3 * i_0 + 2] * x_predicted_idx_1 + (rtu_MM[3 * i_0 + 1] *
      x_predicted_idx_0 + rtu_MM[3 * i_0] * x_predicted_idx);
  }

  /*  TODO expand to X_ref, U_ref */
  /*  run fast gradient method */
  for (i = 0; i < 30; i++) {
    x_predicted[i] = -rtu_V_max[i];
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
    d_y = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      d_y += rtu_TT_PP[30 * i_1 + i_0] * rtu_V_init[i_1];
    }

    tmp_1[i_0] = d_y + LL_PP_ref[i_0];
  }

  for (i_0 = 0; i_0 < 30; i_0++) {
    U_star_0 = rtu_V_init[i_0] - L_inv * tmp_1[i_0];
    d_y = (rtu_V_max[i_0] <= U_star_0) || rtIsNaN(U_star_0) ? rtu_V_max[i_0] :
      U_star_0;
    V_i_0 = (x_predicted[i_0] >= d_y) || rtIsNaN(d_y) ? x_predicted[i_0] : d_y;
    V_ip[i_0] = V_i_0;
    V_i[i_0] = V_i_0;
    U_star[i_0] = U_star_0;
  }

  /*  now run the fast gradient method: */
  for (i = 0; i <= (int32_T)rtu_i_min - 1; i++) {
    for (i_0 = 0; i_0 < 30; i_0++) {
      d_y = 0.0;
      for (i_1 = 0; i_1 < 30; i_1++) {
        d_y += rtu_TT_PP[30 * i_1 + i_0] * V_ip[i_1];
      }

      tmp_1[i_0] = d_y + LL_PP_ref[i_0];
    }

    /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
    /*      convergence result idea */
    for (i_0 = 0; i_0 < 30; i_0++) {
      U_star_0 = V_ip[i_0] - L_inv * tmp_1[i_0];
      d_y = (rtu_V_max[i_0] <= U_star_0) || rtIsNaN(U_star_0) ? rtu_V_max[i_0] :
        U_star_0;
      d_y = (x_predicted[i_0] >= d_y) || rtIsNaN(d_y) ? x_predicted[i_0] : d_y;
      U_star_0 = rtu_betas[(int32_T)(1.0 + (real_T)i) - 1] * (d_y - V_i[i_0]);
      V_i_0 = d_y;
      d_y += U_star_0;
      U_star[i_0] = U_star_0;
      V_i[i_0] = V_i_0;
      V_ip[i_0] = d_y;
    }
  }

  /*  return values: */
  L_inv = 0.0;
  d_y = 0.0;

  /*  plot(residuals) just for testing new convergence result idea */
  /* '<S61>:1:25' */
  /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
  /*  so don't forget to backtransform after termination: */
  /* '<S61>:1:32' */
  for (i_0 = 0; i_0 < 30; i_0++) {
    b_y[i_0] = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      b_y[i_0] += rtu_TT_PP[30 * i_0 + i_1] * (0.5 * V_i[i_1]);
    }

    L_inv += b_y[i_0] * V_i[i_0];
    d_y += LL_PP_ref[i_0] * V_i[i_0];
    U_star[i_0] = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      U_star[i_0] += rtu_PP[30 * i_1 + i_0] * V_i[i_1];
    }
  }

  /*  save outputs for delayed system */
  /* '<S61>:1:38' */
  /*  set new initial guess */
  /* '<S61>:1:42' */
  /* '<S61>:1:44' */
  localB->u_opt = U_star[0];
  localB->J_star = ((y[0] * x_predicted_idx + y[1] * x_predicted_idx_0) + y[2] *
                    x_predicted_idx_1) + (L_inv + d_y);
  localB->u_buff_out[0] = rtu_u_buff[1];
  localB->u_buff_out[1] = rtu_u_buff[2];
  localB->u_buff_out[2] = U_star[0];
  memcpy((void *)(&localB->V_init_out[0]), (void *)&V_i[1], 29U * sizeof(real_T));
  localB->V_init_out[29] = 0.0;
}

/* Function for MATLAB Function: '<S54>/discrete kalman filter' */
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
  memcpy((void *)&b_x[0], (void *)&x[0], 9U * sizeof(real_T));
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
    absx = b_x[3];
    b_x[3] = b_x[4];
    b_x[4] = absx;
    absx = b_x[6];
    b_x[6] = b_x[7];
    b_x[7] = absx;
  } else {
    if (absx_1 > absx) {
      p = 6;
      p_1 = 0;
      b_x[0] = x[2];
      b_x[2] = x[0];
      absx = b_x[3];
      b_x[3] = b_x[5];
      b_x[5] = absx;
      absx = b_x[6];
      b_x[6] = b_x[8];
      b_x[8] = absx;
    }
  }

  b_x[1] /= b_x[0];
  b_x[2] /= b_x[0];
  b_x[4] -= b_x[1] * b_x[3];
  b_x[5] -= b_x[2] * b_x[3];
  b_x[7] -= b_x[1] * b_x[6];
  b_x[8] -= b_x[2] * b_x[6];
  if (fabs(b_x[5]) > fabs(b_x[4])) {
    itmp = p_0;
    p_0 = p_1;
    p_1 = itmp;
    absx = b_x[1];
    b_x[1] = b_x[2];
    b_x[2] = absx;
    absx = b_x[4];
    b_x[4] = b_x[5];
    b_x[5] = absx;
    absx = b_x[7];
    b_x[7] = b_x[8];
    b_x[8] = absx;
  }

  b_x[5] /= b_x[4];
  b_x[8] -= b_x[5] * b_x[7];
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
 * Initial conditions for atomic system:
 *    '<S54>/discrete kalman filter'
 *    '<S56>/discrete kalman filter'
 */
void contr_discretekalmanfilter_Init(rtDW_discretekalmanfilter_contr *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c11_Hquad_control_LIB = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S54>/discrete kalman filter'
 *    '<S56>/discrete kalman filter'
 */
void controller_discretekalmanfilter(real_T rtu_y, real_T rtu_y_o, real_T
  rtu_y_h, const real_T rtu_state[3], real_T rtu_state_m, const real_T rtu_A[16],
  const real_T rtu_B[4], const real_T rtu_C[12], const real_T rtu_Q[16], const
  real_T rtu_R[9], real_T rtu_u, const real_T rtu_P[16],
  rtB_discretekalmanfilter_contro *localB, rtDW_discretekalmanfilter_contr
  *localDW)
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
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'x states estimator bias/discrete kalman filter': '<S63>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S63>:1:10' */
  for (i = 0; i < 4; i++) {
    /* SignalConversion: '<S63>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = (((rtu_A[i + 4] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
             8] * rtu_state[2]) + rtu_A[i + 12] * rtu_state_m) + rtu_B[i] *
      rtu_u;
  }

  /* '<S63>:1:11' */
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      I_0[i + (i_0 << 2)] = 0.0;
      I_0[i + (i_0 << 2)] = I_0[(i_0 << 2) + i] + rtu_P[i_0 << 2] * rtu_A[i];
      I_0[i + (i_0 << 2)] = rtu_P[(i_0 << 2) + 1] * rtu_A[i + 4] + I_0[(i_0 << 2)
        + i];
      I_0[i + (i_0 << 2)] = rtu_P[(i_0 << 2) + 2] * rtu_A[i + 8] + I_0[(i_0 << 2)
        + i];
      I_0[i + (i_0 << 2)] = rtu_P[(i_0 << 2) + 3] * rtu_A[i + 12] + I_0[(i_0 <<
        2) + i];
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
  /* '<S63>:1:14' */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      P_0[i + 3 * i_0] = 0.0;
      P_0[i + 3 * i_0] = P_0[3 * i_0 + i] + P[i_0 << 2] * rtu_C[i];
      P_0[i + 3 * i_0] = P[(i_0 << 2) + 1] * rtu_C[i + 3] + P_0[3 * i_0 + i];
      P_0[i + 3 * i_0] = P[(i_0 << 2) + 2] * rtu_C[i + 6] + P_0[3 * i_0 + i];
      P_0[i + 3 * i_0] = P[(i_0 << 2) + 3] * rtu_C[i + 9] + P_0[3 * i_0 + i];
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
      P_0[i + (i_0 << 2)] = P_0[(i_0 << 2) + i] + P[i] * rtu_C[i_0];
      P_0[i + (i_0 << 2)] = P_0[(i_0 << 2) + i] + P[i + 4] * rtu_C[i_0 + 3];
      P_0[i + (i_0 << 2)] = P_0[(i_0 << 2) + i] + P[i + 8] * rtu_C[i_0 + 6];
      P_0[i + (i_0 << 2)] = P_0[(i_0 << 2) + i] + P[i + 12] * rtu_C[i_0 + 9];
    }
  }

  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      K[i + (i_0 << 2)] = 0.0;
      K[i + (i_0 << 2)] = K[(i_0 << 2) + i] + tmp_0[3 * i_0] * P_0[i];
      K[i + (i_0 << 2)] = tmp_0[3 * i_0 + 1] * P_0[i + 4] + K[(i_0 << 2) + i];
      K[i + (i_0 << 2)] = tmp_0[3 * i_0 + 2] * P_0[i + 8] + K[(i_0 << 2) + i];
    }
  }

  /* '<S63>:1:15' */
  /* '<S63>:1:16' */
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

  /* SignalConversion: '<S63>/TmpSignal ConversionAt SFunction Inport8' */
  unnamed_idx = rtu_y - tmp_1[0];
  unnamed_idx_0 = rtu_y_o - tmp_1[1];
  unnamed_idx_1 = rtu_y_h - tmp_1[2];
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
      localB->P_est[i + (i_0 << 2)] = localB->P_est[(i_0 << 2) + i] + P[i_0 << 2]
        * I_0[i];
      localB->P_est[i + (i_0 << 2)] = P[(i_0 << 2) + 1] * I_0[i + 4] +
        localB->P_est[(i_0 << 2) + i];
      localB->P_est[i + (i_0 << 2)] = P[(i_0 << 2) + 2] * I_0[i + 8] +
        localB->P_est[(i_0 << 2) + i];
      localB->P_est[i + (i_0 << 2)] = P[(i_0 << 2) + 3] * I_0[i + 12] +
        localB->P_est[(i_0 << 2) + i];
    }
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S58>/discrete kalman filter'
 *    '<S60>/discrete kalman filter'
 */
void con_discretekalmanfilter_i_Init(rtDW_discretekalmanfilter_con_g *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c5_Hquad_control_LIB_ = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S58>/discrete kalman filter'
 *    '<S60>/discrete kalman filter'
 */
void controll_discretekalmanfilter_n(real_T rtu_y, real_T rtu_y_e, const real_T
  rtu_state[2], real_T rtu_state_b, const real_T rtu_A[9], const real_T rtu_B[3],
  const real_T rtu_C[6], const real_T rtu_Q[9], const real_T rtu_R[4], real_T
  rtu_u, const real_T rtu_P[9], rtB_discretekalmanfilter_cont_p *localB,
  rtDW_discretekalmanfilter_con_g *localDW)
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
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'yaw states estimator bias/discrete kalman filter': '<S69>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S69>:1:10' */
  for (i = 0; i < 3; i++) {
    /* SignalConversion: '<S69>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = ((rtu_A[i + 3] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
            6] * rtu_state_b) + rtu_B[i] * rtu_u;
  }

  /* '<S69>:1:11' */
  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      I_0[i + 3 * i_0] = 0.0;
      I_0[i + 3 * i_0] = I_0[3 * i_0 + i] + rtu_P[3 * i_0] * rtu_A[i];
      I_0[i + 3 * i_0] = rtu_P[3 * i_0 + 1] * rtu_A[i + 3] + I_0[3 * i_0 + i];
      I_0[i + 3 * i_0] = rtu_P[3 * i_0 + 2] * rtu_A[i + 6] + I_0[3 * i_0 + i];
    }
  }

  for (i = 0; i < 3; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      P[i + 3 * i_0] = ((I_0[i + 3] * rtu_A[i_0 + 3] + I_0[i] * rtu_A[i_0]) +
                        I_0[i + 6] * rtu_A[i_0 + 6]) + rtu_Q[3 * i_0 + i];
    }
  }

  /*  Measurement update */
  /* '<S69>:1:14' */
  for (i = 0; i < 2; i++) {
    for (i_0 = 0; i_0 < 3; i_0++) {
      P_0[i + (i_0 << 1)] = 0.0;
      P_0[i + (i_0 << 1)] = P_0[(i_0 << 1) + i] + P[3 * i_0] * rtu_C[i];
      P_0[i + (i_0 << 1)] = P[3 * i_0 + 1] * rtu_C[i + 2] + P_0[(i_0 << 1) + i];
      P_0[i + (i_0 << 1)] = P[3 * i_0 + 2] * rtu_C[i + 4] + P_0[(i_0 << 1) + i];
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
      P_0[i + 3 * i_0] = P_0[3 * i_0 + i] + P[i] * rtu_C[i_0];
      P_0[i + 3 * i_0] = P_0[3 * i_0 + i] + P[i + 3] * rtu_C[i_0 + 2];
      P_0[i + 3 * i_0] = P_0[3 * i_0 + i] + P[i + 6] * rtu_C[i_0 + 4];
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

  /* '<S69>:1:15' */
  /* '<S69>:1:16' */
  for (i = 0; i < 9; i++) {
    I[i] = 0;
  }

  I[0] = 1;
  I[4] = 1;
  I[8] = 1;
  for (i = 0; i < 2; i++) {
    tmp[i] = rtu_C[i + 4] * x[2] + (rtu_C[i + 2] * x[1] + rtu_C[i] * x[0]);
  }

  /* SignalConversion: '<S69>/TmpSignal ConversionAt SFunction Inport8' */
  r = rtu_y - tmp[0];
  t = rtu_y_e - tmp[1];
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
      localB->P_est[i + 3 * i_0] = localB->P_est[3 * i_0 + i] + P[3 * i_0] *
        I_0[i];
      localB->P_est[i + 3 * i_0] = P[3 * i_0 + 1] * I_0[i + 3] + localB->P_est[3
        * i_0 + i];
      localB->P_est[i + 3 * i_0] = P[3 * i_0 + 2] * I_0[i + 6] + localB->P_est[3
        * i_0 + i];
    }
  }
}

/* Function for MATLAB Function: '<S18>/Ctrl_Xdir' */
static void controller_template_round(real_T x[4])
{
  real_T b_x;
  if (fabs(x[0]) > 4.503599627370496E+15) {
    b_x = x[0];
  } else if (x[0] >= 0.5) {
    b_x = floor(x[0] + 0.5);
  } else if (x[0] > -0.5) {
    b_x = x[0] * 0.0;
  } else {
    b_x = ceil(x[0] - 0.5);
  }

  x[0] = b_x;
  if (fabs(x[1]) > 4.503599627370496E+15) {
    b_x = x[1];
  } else if (x[1] >= 0.5) {
    b_x = floor(x[1] + 0.5);
  } else if (x[1] > -0.5) {
    b_x = x[1] * 0.0;
  } else {
    b_x = ceil(x[1] - 0.5);
  }

  x[1] = b_x;
  if (fabs(x[2]) > 4.503599627370496E+15) {
    b_x = x[2];
  } else if (x[2] >= 0.5) {
    b_x = floor(x[2] + 0.5);
  } else if (x[2] > -0.5) {
    b_x = x[2] * 0.0;
  } else {
    b_x = ceil(x[2] - 0.5);
  }

  x[2] = b_x;
  if (fabs(x[3]) > 4.503599627370496E+15) {
    b_x = x[3];
  } else if (x[3] >= 0.5) {
    b_x = floor(x[3] + 0.5);
  } else if (x[3] > -0.5) {
    b_x = x[3] * 0.0;
  } else {
    b_x = ceil(x[3] - 0.5);
  }

  x[3] = b_x;
}

/* Function for MATLAB Function: '<S18>/Ctrl_Xdir' */
static void controller_template_mrdivide(const real_T A[4], real_T B, real_T y[4])
{
  y[0] = A[0] / B;
  y[1] = A[1] / B;
  y[2] = A[2] / B;
  y[3] = A[3] / B;
}

/* Function for MATLAB Function: '<S27>/Ctrl_Xdir' */
static void controller_template_round_b(real_T x[4])
{
  real_T b_x;
  if (fabs(x[0]) > 4.503599627370496E+15) {
    b_x = x[0];
  } else if (x[0] >= 0.5) {
    b_x = floor(x[0] + 0.5);
  } else if (x[0] > -0.5) {
    b_x = x[0] * 0.0;
  } else {
    b_x = ceil(x[0] - 0.5);
  }

  x[0] = b_x;
  if (fabs(x[1]) > 4.503599627370496E+15) {
    b_x = x[1];
  } else if (x[1] >= 0.5) {
    b_x = floor(x[1] + 0.5);
  } else if (x[1] > -0.5) {
    b_x = x[1] * 0.0;
  } else {
    b_x = ceil(x[1] - 0.5);
  }

  x[1] = b_x;
  if (fabs(x[2]) > 4.503599627370496E+15) {
    b_x = x[2];
  } else if (x[2] >= 0.5) {
    b_x = floor(x[2] + 0.5);
  } else if (x[2] > -0.5) {
    b_x = x[2] * 0.0;
  } else {
    b_x = ceil(x[2] - 0.5);
  }

  x[2] = b_x;
  if (fabs(x[3]) > 4.503599627370496E+15) {
    b_x = x[3];
  } else if (x[3] >= 0.5) {
    b_x = floor(x[3] + 0.5);
  } else if (x[3] > -0.5) {
    b_x = x[3] * 0.0;
  } else {
    b_x = ceil(x[3] - 0.5);
  }

  x[3] = b_x;
}

/* Function for MATLAB Function: '<S27>/Ctrl_Xdir' */
static void controller_template_mrdivide_b(const real_T A[4], real_T B, real_T
  y[4])
{
  y[0] = A[0] / B;
  y[1] = A[1] / B;
  y[2] = A[2] / B;
  y[3] = A[3] / B;
}

/* Model step function */
void FG_traj_custom(real32_T arg_data_in[30], real32_T arg_cmd_out[4], real32_T
                    arg_ref_x[93], real32_T arg_ref_y[93], real32_T arg_ref_z[62],
                    real32_T arg_ref_yaw[62])
{
  /* local block i/o variables */
  real_T rtb_Init[4];
  real_T rtb_TmpSignalConversionAtToFile[4];
  real_T rtb_IntegerDelay;
  real_T rtb_IntegerDelay1;
  real_T rtb_IntegerDelay2;
  real_T rtb_IntegerDelay3;
  real_T rtb_UnitDelay1[16];
  real_T rtb_Init_g[3];
  real_T rtb_UnitDelay[3];
  real_T rtb_UnitDelay1_o[30];
  real_T rtb_UnitDelay1_oh[16];
  real_T rtb_Init_j[3];
  real_T rtb_UnitDelay_e[3];
  real_T rtb_UnitDelay1_g[30];
  real_T rtb_UnitDelay1_j[9];
  real_T rtb_Init_d[2];
  real_T rtb_UnitDelay1_n[9];
  real_T rtb_Init_h[2];
  real_T rtb_bias_W[4];
  real_T rtb_TmpSignalConversionAtToFi_f[18];
  real_T rtb_TmpSignalConversionAtToFi_a[18];
  real_T X[4];
  int32_T flag_oob;
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
  real_T V_i[30];
  real_T V_ip[30];
  real_T b_y[30];
  real_T rtb_MultiportSwitch1;
  real_T rtb_MultiportSwitch2;
  real_T rtb_Product_l;
  real_T rtb_Gain_p;
  real_T rtb_UnitDelay2;
  real_T rtb_Gain_f;
  real_T rtb_Gain_i;
  real_T rtb_Gain_n;
  real_T rtb_Saturation_n;
  real_T rtb_Add;
  real_T rtb_pitch_cmd_b;
  real_T rtb_roll_cmd_c;
  real_T rtb_yaw_rate_cmd_g;
  int32_T i;
  real_T X_0[4];
  real_T temp[30];
  real_T tmp[30];
  real_T tmp_0[2];
  real_T temp_idx;
  real_T temp_idx_0;

  {                                    /* Sample time: [0.02s, 0.0s] */
    boolean_T rtmStopReq = FALSE;
    rtExtModePauseIfNeeded(controller_template_M->extModeInfo, 2, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(controller_template_M, TRUE);
    }

    if (rtmGetStopRequested(controller_template_M) == TRUE) {
      rtmSetErrorStatus(controller_template_M, "Simulation finished");
      return;
    }
  }

  /* RTWBLOCK_START_COMMENT */
  /* Reset subsysRan breadcrumbs */
  srClearBC(controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(controller_template_DWork.poscontroller_SubsysRanBC);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/data_in'
   */
  /* RTWBLOCK_START_COMMENT */
  for (i = 0; i < 30; i++) {
    controller_template_B.DataTypeConversion[i] = arg_data_in[i];
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* MultiPortSwitch: '<S4>/Multiport Switch1' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  if ((int32_T)controller_template_B.DataTypeConversion[20] == 10) {
    rtb_MultiportSwitch1 = controller_template_P.Constant1_Value_mr;
  } else {
    rtb_MultiportSwitch1 = controller_template_P.Constant2_Value_a;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch1' */

  /* Switch: '<S46>/Init' incorporates:
   *  Constant: '<S46>/Initial Condition'
   *  Logic: '<S46>/FixPt Logical Operator'
   *  UnitDelay: '<S46>/FixPt Unit Delay1'
   *  UnitDelay: '<S46>/FixPt Unit Delay2'
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
    controller_template_B.X_ref_x[i] = arg_ref_x[i];

    /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
     *  Inport: '<Root>/ref_y'
     */
    controller_template_B.X_ref_y[i] = arg_ref_y[i];
  }

  /* End of Switch: '<S46>/Init' */
  for (i = 0; i < 62; i++) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
     *  Inport: '<Root>/ref_z'
     */
    controller_template_B.X_ref_z[i] = arg_ref_z[i];

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Inport: '<Root>/ref_yaw'
     */
    controller_template_B.X_ref_yaw[i] = arg_ref_yaw[i];
  }

  /* MultiPortSwitch: '<S4>/Multiport Switch2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Constant: '<S4>/Constant2'
   */
  if ((int32_T)controller_template_B.DataTypeConversion[20] == 4) {
    rtb_MultiportSwitch2 = controller_template_P.Constant1_Value_mr;
  } else {
    rtb_MultiportSwitch2 = controller_template_P.Constant2_Value_a;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch2' */

  /* Outputs for Enabled SubSystem: '<Root>/FreeFlight Pos Ctrl' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (rtb_MultiportSwitch2 > 0.0) {
    if (!controller_template_DWork.FreeFlightPosCtrl_MODE) {
      /* InitializeConditions for MATLAB Function: '<S11>/Embedded MATLAB Function' */
      con_EmbeddedMATLABFunction_Init
        (&controller_template_DWork.sf_EmbeddedMATLABFunction);

      /* InitializeConditions for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
      /* InitializeConditions for MATLAB Function: '<S14>/MATLAB Function' */
      controller_template_DWork.sfEvent_fk = CALL_EVENT;
      controller_template_DWork.is_active_c8_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S18>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE =
        controller_template_P.UnitDelay2_X0;

      /* InitializeConditions for MATLAB Function: '<S25>/MATLAB Function' */
      controller__MATLABFunction_Init
        (&controller_template_DWork.sf_MATLABFunction_f);

      /* InitializeConditions for MATLAB Function: '<S18>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_kl = CALL_EVENT;
      controller_template_DWork.is_active_c1_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S20>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_d =
        controller_template_P.UnitDelay2_X0_m;

      /* InitializeConditions for UnitDelay: '<S20>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_jv =
        controller_template_P.UnitDelay_X0;

      /* InitializeConditions for UnitDelay: '<S27>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_l =
        controller_template_P.UnitDelay2_X0_d;

      /* InitializeConditions for MATLAB Function: '<S30>/MATLAB Function' */
      controller__MATLABFunction_Init
        (&controller_template_DWork.sf_MATLABFunction_k);

      /* InitializeConditions for MATLAB Function: '<S27>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_cd = CALL_EVENT;
      controller_template_DWork.is_active_c2_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S28>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_k =
        controller_template_P.UnitDelay2_X0_n;

      /* InitializeConditions for UnitDelay: '<S28>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_f =
        controller_template_P.UnitDelay_X0_f;

      /* InitializeConditions for MATLAB Function: '<S37>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_k0 = CALL_EVENT;
      controller_template_DWork.is_active_c3_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S38>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_b =
        controller_template_P.UnitDelay2_X0_o;

      /* InitializeConditions for UnitDelay: '<S38>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_fw =
        controller_template_P.UnitDelay_X0_i;

      /* InitializeConditions for UnitDelay: '<S32>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_g =
        controller_template_P.UnitDelay2_X0_ng;

      /* InitializeConditions for MATLAB Function: '<S35>/MATLAB Function' */
      controller_template_DWork.sfEvent_l = CALL_EVENT;
      controller_template_DWork.is_active_c6_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S32>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_jv = CALL_EVENT;
      controller_template_DWork.is_active_c4_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S33>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_ga =
        controller_template_P.UnitDelay2_X0_i;

      /* InitializeConditions for UnitDelay: '<S33>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_p =
        controller_template_P.UnitDelay_X0_c;

      /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_a =
        controller_template_P.UnitDelay1_X0;

      /* InitializeConditions for UnitDelay: '<S28>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_ji =
        controller_template_P.UnitDelay1_X0_d;

      /* InitializeConditions for UnitDelay: '<S33>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_c3 =
        controller_template_P.UnitDelay1_X0_j;

      /* InitializeConditions for UnitDelay: '<S38>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_m =
        controller_template_P.UnitDelay1_X0_f;

      /* End of InitializeConditions for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

      /* InitializeConditions for Atomic SubSystem: '<S2>/decoupling and rotation' */
      /* InitializeConditions for MATLAB Function: '<S40>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_c = CALL_EVENT;
      controller_template_DWork.is_active_c1_Hquad_control_LI_l = 0U;

      /* InitializeConditions for MATLAB Function: '<S41>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_j = CALL_EVENT;
      controller_template_DWork.is_active_c4_Hquad_control_LI_d = 0U;

      /* End of InitializeConditions for SubSystem: '<S2>/decoupling and rotation' */
      controller_template_DWork.FreeFlightPosCtrl_MODE = TRUE;
    }

    /* MATLAB Function: '<S11>/Embedded MATLAB Function' */
    controll_EmbeddedMATLABFunction(controller_template_B.DataTypeConversion[6],
      controller_template_B.DataTypeConversion[7], rtb_Init[0], rtb_Init[1],
      controller_template_B.DataTypeConversion[8],
      &controller_template_B.sf_EmbeddedMATLABFunction,
      &controller_template_DWork.sf_EmbeddedMATLABFunction);

    /* Outputs for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* Product: '<S8>/Product' incorporates:
     *  Constant: '<S8>/gravity'
     */
    rtb_Product_l = controller_template_P.gravity_Value *
      controller_template_B.DataTypeConversion[29];

    /* Sum: '<S14>/Add' incorporates:
     *  Constant: '<S14>/Constant'
     *  Gain: '<S21>/Slider Gain'
     *  Gain: '<S22>/Slider Gain'
     *  Sum: '<S14>/Sum'
     */
    rtb_Add = controller_template_B.DataTypeConversion[0] -
      (controller_template_P.SliderGain_Gain * controller_template_B.X_ref_x[0]
       + controller_template_P.SliderGain_Gain_e *
       controller_template_P.Constant_Value);

    /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
     *  Constant: '<S14>/Constant1'
     *  Gain: '<S23>/Slider Gain'
     */
    controller_template_DWork.sfEvent_fk = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /MATLAB Function': '<S19>:1' */
    if (rtb_Add >= controller_template_P.SliderGain_Gain_f *
        controller_template_P.Constant1_Value) {
      /* '<S19>:1:3' */
      /* '<S19>:1:4' */
      controller_template_B.y_n = 0.0;
    } else {
      /* '<S19>:1:6' */
      controller_template_B.y_n = rtb_Add;
    }

    /* End of MATLAB Function: '<S14>/MATLAB Function' */

    /* Saturate: '<S14>/Saturation3' */
    controller_template_B.Saturation3 = controller_template_B.y_n >=
      controller_template_P.Saturation3_UpperSat ?
      controller_template_P.Saturation3_UpperSat : controller_template_B.y_n <=
      controller_template_P.Saturation3_LowerSat ?
      controller_template_P.Saturation3_LowerSat : controller_template_B.y_n;

    /* RateTransition: '<S18>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Saturate: '<S14>/Saturation' */
      controller_template_B.RateTransition[0] =
        controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot >=
        controller_template_P.Saturation_UpperSat ?
        controller_template_P.Saturation_UpperSat :
        controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot <=
        controller_template_P.Saturation_LowerSat ?
        controller_template_P.Saturation_LowerSat :
        controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot;

      /* Saturate: '<S14>/Saturation1' */
      controller_template_B.RateTransition[1] =
        controller_template_B.DataTypeConversion[10] >=
        controller_template_P.Saturation1_UpperSat ?
        controller_template_P.Saturation1_UpperSat :
        controller_template_B.DataTypeConversion[10] <=
        controller_template_P.Saturation1_LowerSat ?
        controller_template_P.Saturation1_LowerSat :
        controller_template_B.DataTypeConversion[10];
      controller_template_B.RateTransition[2] =
        controller_template_B.Saturation3;

      /* Saturate: '<S14>/Saturation2' */
      controller_template_B.RateTransition[3] =
        controller_template_B.DataTypeConversion[3] >=
        controller_template_P.Saturation2_UpperSat ?
        controller_template_P.Saturation2_UpperSat :
        controller_template_B.DataTypeConversion[3] <=
        controller_template_P.Saturation2_LowerSat ?
        controller_template_P.Saturation2_LowerSat :
        controller_template_B.DataTypeConversion[3];

      /* UnitDelay: '<S18>/Unit Delay2' */
      controller_template_B.UnitDelay2 =
        controller_template_DWork.UnitDelay2_DSTATE;
    }

    /* End of RateTransition: '<S18>/Rate Transition' */

    /* MATLAB Function: '<S25>/MATLAB Function' */
    controller_templ_MATLABFunction(controller_template_B.RateTransition,
      controller_template_P.Constant_Value_d,
      controller_template_P.Constant1_Value_k, controller_template_B.UnitDelay2,
      &controller_template_B.sf_MATLABFunction_f,
      &controller_template_DWork.sf_MATLABFunction_f);

    /* MATLAB Function: '<S18>/Ctrl_Xdir' incorporates:
     *  Constant: '<S18>/Constant'
     *  Constant: '<S18>/Constant1'
     *  Constant: '<S18>/Constant2'
     *  Constant: '<S18>/Constant3'
     *  Constant: '<S18>/Constant4'
     */
    controller_template_DWork.sfEvent_kl = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/Ctrl_Xdir': '<S24>:1' */
    /* '<S24>:1:3' */
    tolerance = 1.0;

    /* '<S24>:1:5' */
    /* '<S24>:1:6' */
    minreg = -1;

    /* '<S24>:1:7' */
    X[0] = 10000.0 * controller_template_B.sf_MATLABFunction_f.y[0];
    X[1] = 10000.0 * controller_template_B.sf_MATLABFunction_f.y[1];
    X[2] = 10000.0 * controller_template_B.sf_MATLABFunction_f.y[2];
    X[3] = 10000.0 * controller_template_B.sf_MATLABFunction_f.y[3];
    controller_template_round(X);
    X_0[0] = X[0];
    X_0[1] = X[1];
    X_0[2] = X[2];
    X_0[3] = X[3];
    controller_template_mrdivide(X_0, 10000.0, X);

    /* '<S24>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S24>:1:12' */
    memset((void *)&Hi[0], 0, 400U * sizeof(real_T));

    /* '<S24>:1:13' */
    memset((void *)&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S24>:1:16' */
    abspos = 1.0;

    /* '<S24>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 368) {
        /* '<S24>:1:17' */
        /* '<S24>:1:18' */
        sumViol = 0.0;

        /* '<S24>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S24>:1:23' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value[ireg] -
             1; i++) {
          /* '<S24>:1:23' */
          /* '<S24>:1:24' */
          /* '<S24>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_o[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S24>:1:24' */
          /* '<S24>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 99] =
            controller_template_P.Constant_Value_o[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 3242];

          /* '<S24>:1:24' */
          /* '<S24>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 199] =
            controller_template_P.Constant_Value_o[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 6485];

          /* '<S24>:1:24' */
          /* '<S24>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 299] =
            controller_template_P.Constant_Value_o[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 9728];

          /* '<S24>:1:24' */
          /* '<S24>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S24>:1:30' */
        for (k = 0; k <= (int32_T)controller_template_P.Constant4_Value[ireg] -
             1; k++) {
          /* '<S24>:1:30' */
          /* '<S24>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_d[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S24>:1:30' */
        }

        /* '<S24>:1:33' */
        abspos += controller_template_P.Constant4_Value[ireg];

        /* '<S24>:1:35' */
        /* '<S24>:1:36' */
        /* '<S24>:1:38' */
        /* '<S24>:1:40' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value[ireg] -
             1; i++) {
          /* '<S24>:1:40' */
          /* '<S24>:1:41' */
          rtb_yaw_rate_cmd_g = ((Hi[(int32_T)(1.0 + (real_T)i) - 1] * X[0] + Hi
                                 [(int32_T)(1.0 + (real_T)i) + 99] * X[1]) + Hi
                                [(int32_T)(1.0 + (real_T)i) + 199] * X[2]) + Hi
            [(int32_T)(1.0 + (real_T)i) + 299] * X[3];
          if (rtb_yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)i) - 1] > 1.0E-8)
          {
            /* '<S24>:1:42' */
            /* '<S24>:1:43' */
            isinside = 0;

            /* '<S24>:1:44' */
            sumViol += rtb_yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)i) - 1];
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
          rtb_UnitDelay2 = (((controller_template_P.Constant2_Value[ireg + 368] *
                              X[1] + controller_template_P.Constant2_Value[ireg]
                              * X[0]) +
                             controller_template_P.Constant2_Value[ireg + 736] *
                             X[2]) + controller_template_P.Constant2_Value[ireg
                            + 1104] * X[3]) +
            controller_template_P.Constant3_Value[ireg];
          exitg = 1;
        } else {
          /* '<S24>:1:17' */
          ireg++;
        }
      } else {
        /* '<S24>:1:58' */
        /* '<S24>:1:59' */
        /* '<S24>:1:60' */
        rtb_UnitDelay2 = (((controller_template_P.Constant2_Value[minreg + 368] *
                            X[1] + controller_template_P.Constant2_Value[minreg]
                            * X[0]) +
                           controller_template_P.Constant2_Value[minreg + 736] *
                           X[2]) + controller_template_P.Constant2_Value[minreg
                          + 1104] * X[3]) +
          controller_template_P.Constant3_Value[minreg];

        /* '<S24>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_i = rtb_UnitDelay2;
    controller_template_B.flag_oob_b = (real_T)flag_oob;

    /* End of MATLAB Function: '<S18>/Ctrl_Xdir' */

    /* Gain: '<S20>/Gain' incorporates:
     *  Saturate: '<S14>/Saturation4'
     *  Sum: '<S20>/Sum'
     *  Sum: '<S20>/Sum1'
     *  UnitDelay: '<S20>/Unit Delay'
     *  UnitDelay: '<S20>/Unit Delay2'
     */
    rtb_Gain_p = ((controller_template_B.U_i >=
                   controller_template_P.Saturation4_UpperSat ?
                   controller_template_P.Saturation4_UpperSat :
                   controller_template_B.U_i <=
                   controller_template_P.Saturation4_LowerSat ?
                   controller_template_P.Saturation4_LowerSat :
                   controller_template_B.U_i) +
                  (controller_template_DWork.UnitDelay2_DSTATE_d +
                   controller_template_DWork.UnitDelay_DSTATE_jv)) *
      controller_template_P.Gain_Gain;

    /* Inport: '<S8>/bias_W' */
    rtb_bias_W[0] =
      controller_template_B.sf_EmbeddedMATLABFunction.pitch_bias_rot;
    rtb_bias_W[1] =
      controller_template_B.sf_EmbeddedMATLABFunction.roll_bias_rot;
    rtb_bias_W[2] = rtb_Init[2];
    rtb_bias_W[3] = rtb_Init[3];

    /* Sum: '<S8>/Sum' */
    rtb_pitch_cmd_b = rtb_Gain_p - rtb_bias_W[0];

    /* Saturate: '<S15>/Saturation2' */
    rtb_UnitDelay2 = controller_template_B.DataTypeConversion[4] >=
      controller_template_P.Saturation2_UpperSat_b ?
      controller_template_P.Saturation2_UpperSat_b :
      controller_template_B.DataTypeConversion[4] <=
      controller_template_P.Saturation2_LowerSat_h ?
      controller_template_P.Saturation2_LowerSat_h :
      controller_template_B.DataTypeConversion[4];

    /* RateTransition: '<S27>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Saturate: '<S15>/Saturation' */
      controller_template_B.RateTransition_i[0] =
        controller_template_B.sf_EmbeddedMATLABFunction.roll_rot >=
        controller_template_P.Saturation_UpperSat_h ?
        controller_template_P.Saturation_UpperSat_h :
        controller_template_B.sf_EmbeddedMATLABFunction.roll_rot <=
        controller_template_P.Saturation_LowerSat_d ?
        controller_template_P.Saturation_LowerSat_d :
        controller_template_B.sf_EmbeddedMATLABFunction.roll_rot;

      /* Saturate: '<S15>/Saturation1' */
      controller_template_B.RateTransition_i[1] =
        controller_template_B.DataTypeConversion[9] >=
        controller_template_P.Saturation1_UpperSat_o ?
        controller_template_P.Saturation1_UpperSat_o :
        controller_template_B.DataTypeConversion[9] <=
        controller_template_P.Saturation1_LowerSat_c ?
        controller_template_P.Saturation1_LowerSat_c :
        controller_template_B.DataTypeConversion[9];

      /* Sum: '<S15>/Add' */
      rtb_Add = controller_template_B.DataTypeConversion[1] -
        controller_template_B.X_ref_y[0];

      /* Saturate: '<S15>/Saturation3' */
      controller_template_B.RateTransition_i[2] = rtb_Add >=
        controller_template_P.Saturation3_UpperSat_n ?
        controller_template_P.Saturation3_UpperSat_n : rtb_Add <=
        controller_template_P.Saturation3_LowerSat_c ?
        controller_template_P.Saturation3_LowerSat_c : rtb_Add;
      controller_template_B.RateTransition_i[3] = rtb_UnitDelay2;

      /* UnitDelay: '<S27>/Unit Delay2' */
      controller_template_B.UnitDelay2_o =
        controller_template_DWork.UnitDelay2_DSTATE_l;
    }

    /* End of RateTransition: '<S27>/Rate Transition' */

    /* MATLAB Function: '<S30>/MATLAB Function' */
    controller_templ_MATLABFunction(controller_template_B.RateTransition_i,
      controller_template_P.Constant_Value_c,
      controller_template_P.Constant1_Value_g,
      controller_template_B.UnitDelay2_o,
      &controller_template_B.sf_MATLABFunction_k,
      &controller_template_DWork.sf_MATLABFunction_k);

    /* MATLAB Function: '<S27>/Ctrl_Xdir' incorporates:
     *  Constant: '<S27>/Constant'
     *  Constant: '<S27>/Constant1'
     *  Constant: '<S27>/Constant2'
     *  Constant: '<S27>/Constant3'
     *  Constant: '<S27>/Constant4'
     */
    controller_template_DWork.sfEvent_cd = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S29>:1' */
    /* '<S29>:1:3' */
    tolerance = 1.0;

    /* '<S29>:1:5' */
    /* '<S29>:1:6' */
    minreg = -1;

    /* '<S29>:1:7' */
    X[0] = 10000.0 * controller_template_B.sf_MATLABFunction_k.y[0];
    X[1] = 10000.0 * controller_template_B.sf_MATLABFunction_k.y[1];
    X[2] = 10000.0 * controller_template_B.sf_MATLABFunction_k.y[2];
    X[3] = 10000.0 * controller_template_B.sf_MATLABFunction_k.y[3];
    controller_template_round_b(X);
    X_0[0] = X[0];
    X_0[1] = X[1];
    X_0[2] = X[2];
    X_0[3] = X[3];
    controller_template_mrdivide_b(X_0, 10000.0, X);

    /* '<S29>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S29>:1:12' */
    memset((void *)&Hi[0], 0, 400U * sizeof(real_T));

    /* '<S29>:1:13' */
    memset((void *)&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S29>:1:16' */
    abspos = 1.0;

    /* '<S29>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 134) {
        /* '<S29>:1:17' */
        /* '<S29>:1:18' */
        sumViol = 0.0;

        /* '<S29>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S29>:1:23' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; i++) {
          /* '<S29>:1:23' */
          /* '<S29>:1:24' */
          /* '<S29>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S29>:1:24' */
          /* '<S29>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 99] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 1132];

          /* '<S29>:1:24' */
          /* '<S29>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 199] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 2265];

          /* '<S29>:1:24' */
          /* '<S29>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 299] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 3398];

          /* '<S29>:1:24' */
          /* '<S29>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S29>:1:30' */
        for (k = 0; k <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; k++) {
          /* '<S29>:1:30' */
          /* '<S29>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_j[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S29>:1:30' */
        }

        /* '<S29>:1:33' */
        abspos += controller_template_P.Constant4_Value_g[ireg];

        /* '<S29>:1:35' */
        /* '<S29>:1:36' */
        /* '<S29>:1:38' */
        /* '<S29>:1:40' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; i++) {
          /* '<S29>:1:40' */
          /* '<S29>:1:41' */
          rtb_yaw_rate_cmd_g = ((Hi[(int32_T)(1.0 + (real_T)i) - 1] * X[0] + Hi
                                 [(int32_T)(1.0 + (real_T)i) + 99] * X[1]) + Hi
                                [(int32_T)(1.0 + (real_T)i) + 199] * X[2]) + Hi
            [(int32_T)(1.0 + (real_T)i) + 299] * X[3];
          if (rtb_yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)i) - 1] > 1.0E-8)
          {
            /* '<S29>:1:42' */
            /* '<S29>:1:43' */
            isinside = 0;

            /* '<S29>:1:44' */
            sumViol += rtb_yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)i) - 1];
          }

          /* '<S29>:1:40' */
        }

        if (sumViol < tolerance) {
          /* '<S29>:1:48' */
          /* '<S29>:1:49' */
          tolerance = sumViol;

          /* '<S29>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S29>:1:53' */
          /* '<S29>:1:54' */
          rtb_Gain_n = (((controller_template_P.Constant2_Value_j[ireg + 134] *
                          X[1] + controller_template_P.Constant2_Value_j[ireg] *
                          X[0]) + controller_template_P.Constant2_Value_j[ireg +
                         268] * X[2]) +
                        controller_template_P.Constant2_Value_j[ireg + 402] * X
                        [3]) + controller_template_P.Constant3_Value_o[ireg];
          exitg = 1;
        } else {
          /* '<S29>:1:17' */
          ireg++;
        }
      } else {
        /* '<S29>:1:58' */
        /* '<S29>:1:59' */
        /* '<S29>:1:60' */
        rtb_Gain_n = (((controller_template_P.Constant2_Value_j[minreg + 134] *
                        X[1] + controller_template_P.Constant2_Value_j[minreg] *
                        X[0]) + controller_template_P.Constant2_Value_j[minreg +
                       268] * X[2]) +
                      controller_template_P.Constant2_Value_j[minreg + 402] * X
                      [3]) + controller_template_P.Constant3_Value_o[minreg];

        /* '<S29>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_p = rtb_Gain_n;
    controller_template_B.flag_oob_o = (real_T)flag_oob;

    /* End of MATLAB Function: '<S27>/Ctrl_Xdir' */

    /* UnitDelay: '<S28>/Unit Delay2' */
    rtb_UnitDelay2 = controller_template_DWork.UnitDelay2_DSTATE_k;

    /* Gain: '<S28>/Gain' incorporates:
     *  Saturate: '<S15>/Saturation4'
     *  Sum: '<S28>/Sum'
     *  Sum: '<S28>/Sum1'
     *  UnitDelay: '<S28>/Unit Delay'
     */
    rtb_Gain_f = ((controller_template_B.U_p >=
                   controller_template_P.Saturation4_UpperSat_i ?
                   controller_template_P.Saturation4_UpperSat_i :
                   controller_template_B.U_p <=
                   controller_template_P.Saturation4_LowerSat_h ?
                   controller_template_P.Saturation4_LowerSat_h :
                   controller_template_B.U_p) + (rtb_UnitDelay2 +
      controller_template_DWork.UnitDelay_DSTATE_f)) *
      controller_template_P.Gain_Gain_f;

    /* Sum: '<S8>/Sum1' */
    rtb_roll_cmd_c = rtb_Gain_f - rtb_bias_W[1];

    /* Sum: '<S17>/Add' */
    rtb_UnitDelay2 = controller_template_B.DataTypeConversion[2] -
      controller_template_B.X_ref_z[0];

    /* Saturate: '<S17>/Saturation1' */
    controller_template_B.Saturation1 = rtb_UnitDelay2 >=
      controller_template_P.Saturation1_UpperSat_d ?
      controller_template_P.Saturation1_UpperSat_d : rtb_UnitDelay2 <=
      controller_template_P.Saturation1_LowerSat_n ?
      controller_template_P.Saturation1_LowerSat_n : rtb_UnitDelay2;

    /* Saturate: '<S17>/Saturation' */
    controller_template_B.Saturation = controller_template_B.DataTypeConversion
      [5] >= controller_template_P.Saturation_UpperSat_d ?
      controller_template_P.Saturation_UpperSat_d :
      controller_template_B.DataTypeConversion[5] <=
      controller_template_P.Saturation_LowerSat_b ?
      controller_template_P.Saturation_LowerSat_b :
      controller_template_B.DataTypeConversion[5];

    /* RateTransition: '<S37>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      controller_template_B.RateTransition_j[0] =
        controller_template_B.Saturation1;
      controller_template_B.RateTransition_j[1] =
        controller_template_B.Saturation;
    }

    /* End of RateTransition: '<S37>/Rate Transition' */

    /* MATLAB Function: '<S37>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_k0 = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S39>:1' */
    /* '<S39>:1:3' */
    tolerance = 1.0;

    /* '<S39>:1:5' */
    /* '<S39>:1:6' */
    minreg = -1;

    /* '<S39>:1:7' */
    temp_idx = 10000.0 * controller_template_B.RateTransition_j[0];
    temp_idx_0 = 10000.0 * controller_template_B.RateTransition_j[1];
    rtb_Add = temp_idx;
    if (!(fabs(temp_idx) > 4.503599627370496E+15)) {
      if (temp_idx >= 0.5) {
        rtb_Add = floor(temp_idx + 0.5);
      } else if (temp_idx > -0.5) {
        rtb_Add = -0.0;
      } else {
        rtb_Add = ceil(temp_idx - 0.5);
      }
    }

    /* End of Outputs for SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    temp_idx = rtb_Add;

    /* Outputs for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* MATLAB Function: '<S37>/Ctrl_Xdir' incorporates:
     *  Constant: '<S37>/Constant'
     *  Constant: '<S37>/Constant1'
     *  Constant: '<S37>/Constant2'
     *  Constant: '<S37>/Constant3'
     *  Constant: '<S37>/Constant4'
     */
    rtb_Add = temp_idx_0;
    if (!(fabs(temp_idx_0) > 4.503599627370496E+15)) {
      if (temp_idx_0 >= 0.5) {
        rtb_Add = floor(temp_idx_0 + 0.5);
      } else if (temp_idx_0 > -0.5) {
        rtb_Add = -0.0;
      } else {
        rtb_Add = ceil(temp_idx_0 - 0.5);
      }
    }

    temp_idx /= 10000.0;
    rtb_Add /= 10000.0;

    /* '<S39>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S39>:1:12' */
    memset((void *)&Hi_0[0], 0, 200U * sizeof(real_T));

    /* '<S39>:1:13' */
    memset((void *)&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S39>:1:16' */
    abspos = 1.0;

    /* '<S39>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 27) {
        /* '<S39>:1:17' */
        /* '<S39>:1:18' */
        sumViol = 0.0;

        /* '<S39>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S39>:1:23' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; i++) {
          /* '<S39>:1:23' */
          /* '<S39>:1:24' */
          /* '<S39>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_b[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S39>:1:24' */
          /* '<S39>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)i) + 99] =
            controller_template_P.Constant_Value_b[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 111];

          /* '<S39>:1:24' */
          /* '<S39>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S39>:1:30' */
        for (k = 0; k <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; k++) {
          /* '<S39>:1:30' */
          /* '<S39>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_l[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S39>:1:30' */
        }

        /* '<S39>:1:33' */
        abspos += controller_template_P.Constant4_Value_a[ireg];

        /* '<S39>:1:35' */
        /* '<S39>:1:36' */
        /* '<S39>:1:38' */
        /* '<S39>:1:40' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; i++) {
          /* '<S39>:1:40' */
          /* '<S39>:1:41' */
          rtb_yaw_rate_cmd_g = Hi_0[(int32_T)(1.0 + (real_T)i) - 1] * temp_idx +
            Hi_0[(int32_T)(1.0 + (real_T)i) + 99] * rtb_Add;
          if (rtb_yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)i) - 1] > 1.0E-8)
          {
            /* '<S39>:1:42' */
            /* '<S39>:1:43' */
            isinside = 0;

            /* '<S39>:1:44' */
            sumViol += rtb_yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)i) - 1];
          }

          /* '<S39>:1:40' */
        }

        if (sumViol < tolerance) {
          /* '<S39>:1:48' */
          /* '<S39>:1:49' */
          tolerance = sumViol;

          /* '<S39>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S39>:1:53' */
          /* '<S39>:1:54' */
          rtb_Gain_i = (controller_template_P.Constant2_Value_g[ireg + 27] *
                        rtb_Add + controller_template_P.Constant2_Value_g[ireg] *
                        temp_idx) + controller_template_P.Constant3_Value_m[ireg];
          exitg = 1;
        } else {
          /* '<S39>:1:17' */
          ireg++;
        }
      } else {
        /* '<S39>:1:58' */
        /* '<S39>:1:59' */
        /* '<S39>:1:60' */
        rtb_Gain_i = (controller_template_P.Constant2_Value_g[minreg + 27] *
                      rtb_Add + controller_template_P.Constant2_Value_g[minreg] *
                      temp_idx) + controller_template_P.Constant3_Value_m[minreg];

        /* '<S39>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U = rtb_Gain_i;
    controller_template_B.flag_oob = (real_T)flag_oob;

    /* UnitDelay: '<S38>/Unit Delay2' */
    rtb_UnitDelay2 = controller_template_DWork.UnitDelay2_DSTATE_b;

    /* Gain: '<S38>/Gain' incorporates:
     *  Saturate: '<S17>/Saturation2'
     *  Sum: '<S38>/Sum'
     *  Sum: '<S38>/Sum1'
     *  UnitDelay: '<S38>/Unit Delay'
     */
    rtb_Gain_i = ((controller_template_B.U >=
                   controller_template_P.Saturation2_UpperSat_k ?
                   controller_template_P.Saturation2_UpperSat_k :
                   controller_template_B.U <=
                   controller_template_P.Saturation2_LowerSat_j ?
                   controller_template_P.Saturation2_LowerSat_j :
                   controller_template_B.U) + (rtb_UnitDelay2 +
      controller_template_DWork.UnitDelay_DSTATE_fw)) *
      controller_template_P.Gain_Gain_p;

    /* Sum: '<S16>/Add' */
    rtb_UnitDelay2 = controller_template_B.DataTypeConversion[8] -
      controller_template_B.X_ref_yaw[0];

    /* Saturate: '<S16>/Saturation' */
    rtb_UnitDelay2 = rtb_UnitDelay2 >=
      controller_template_P.Saturation_UpperSat_o ?
      controller_template_P.Saturation_UpperSat_o : rtb_UnitDelay2 <=
      controller_template_P.Saturation_LowerSat_p ?
      controller_template_P.Saturation_LowerSat_p : rtb_UnitDelay2;

    /* RateTransition: '<S32>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      controller_template_B.RateTransition_jf = rtb_UnitDelay2;

      /* UnitDelay: '<S32>/Unit Delay2' */
      controller_template_B.UnitDelay2_e =
        controller_template_DWork.UnitDelay2_DSTATE_g;
    }

    /* End of RateTransition: '<S32>/Rate Transition' */

    /* MATLAB Function: '<S35>/MATLAB Function' incorporates:
     *  Constant: '<S35>/Constant'
     *  Constant: '<S35>/Constant1'
     */
    controller_template_DWork.sfEvent_l = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate/MATLAB Function': '<S36>:1' */
    /* '<S36>:1:4' */
    controller_template_B.y = controller_template_P.Constant_Value_h *
      controller_template_B.RateTransition_jf +
      controller_template_P.Constant1_Value_m *
      controller_template_B.UnitDelay2_e;

    /* MATLAB Function: '<S32>/Ctrl_Xdir' incorporates:
     *  Constant: '<S32>/Constant'
     *  Constant: '<S32>/Constant1'
     *  Constant: '<S32>/Constant2'
     *  Constant: '<S32>/Constant3'
     *  Constant: '<S32>/Constant4'
     */
    controller_template_DWork.sfEvent_jv = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S34>:1' */
    /* '<S34>:1:3' */
    tolerance = 1.0;

    /* '<S34>:1:5' */
    /* '<S34>:1:6' */
    minreg = -1;

    /* '<S34>:1:7' */
    rtb_Add = 10000.0 * controller_template_B.y;
    if (!(fabs(rtb_Add) > 4.503599627370496E+15)) {
      if (rtb_Add >= 0.5) {
        rtb_Add = floor(rtb_Add + 0.5);
      } else if (rtb_Add > -0.5) {
        rtb_Add = -0.0;
      } else {
        rtb_Add = ceil(rtb_Add - 0.5);
      }
    }

    rtb_Add /= 10000.0;

    /* '<S34>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S34>:1:12' */
    /* '<S34>:1:13' */
    for (i = 0; i < 100; i++) {
      Hi_1[i] = 0.0;
      Ki[i] = 0.0;
    }

    /*  Find the proper region */
    /* '<S34>:1:16' */
    abspos = 1.0;

    /* '<S34>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 3) {
        /* '<S34>:1:17' */
        /* '<S34>:1:18' */
        sumViol = 0.0;

        /* '<S34>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S34>:1:23' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_gb[ireg]
             - 1; i++) {
          /* '<S34>:1:23' */
          /* '<S34>:1:25' */
          Hi_1[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_a[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S34>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S34>:1:30' */
        for (k = 0; k <= (int32_T)controller_template_P.Constant4_Value_gb[ireg]
             - 1; k++) {
          /* '<S34>:1:30' */
          /* '<S34>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_gs[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S34>:1:30' */
        }

        /* '<S34>:1:33' */
        abspos += controller_template_P.Constant4_Value_gb[ireg];

        /* '<S34>:1:35' */
        /* '<S34>:1:36' */
        /* '<S34>:1:38' */
        /* '<S34>:1:40' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_gb[ireg]
             - 1; i++) {
          /* '<S34>:1:40' */
          /* '<S34>:1:41' */
          rtb_yaw_rate_cmd_g = Hi_1[(int32_T)(1.0 + (real_T)i) - 1] * rtb_Add;
          if (rtb_yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)i) - 1] > 1.0E-8)
          {
            /* '<S34>:1:42' */
            /* '<S34>:1:43' */
            isinside = 0;

            /* '<S34>:1:44' */
            sumViol += rtb_yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)i) - 1];
          }

          /* '<S34>:1:40' */
        }

        if (sumViol < tolerance) {
          /* '<S34>:1:48' */
          /* '<S34>:1:49' */
          tolerance = sumViol;

          /* '<S34>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S34>:1:53' */
          /* '<S34>:1:54' */
          rtb_Saturation_n = controller_template_P.Constant2_Value_jq[ireg] *
            rtb_Add + controller_template_P.Constant3_Value_b[ireg];
          exitg = 1;
        } else {
          /* '<S34>:1:17' */
          ireg++;
        }
      } else {
        /* '<S34>:1:58' */
        /* '<S34>:1:59' */
        /* '<S34>:1:60' */
        rtb_Saturation_n = controller_template_P.Constant2_Value_jq[minreg] *
          rtb_Add + controller_template_P.Constant3_Value_b[minreg];

        /* '<S34>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_g = rtb_Saturation_n;
    controller_template_B.flag_oob_l = (real_T)flag_oob;

    /* End of MATLAB Function: '<S32>/Ctrl_Xdir' */

    /* UnitDelay: '<S33>/Unit Delay2' */
    rtb_UnitDelay2 = controller_template_DWork.UnitDelay2_DSTATE_ga;

    /* Gain: '<S33>/Gain' incorporates:
     *  Saturate: '<S16>/Saturation1'
     *  Sum: '<S33>/Sum'
     *  Sum: '<S33>/Sum1'
     *  UnitDelay: '<S33>/Unit Delay'
     */
    rtb_Gain_n = ((controller_template_B.U_g >=
                   controller_template_P.Saturation1_UpperSat_g ?
                   controller_template_P.Saturation1_UpperSat_g :
                   controller_template_B.U_g <=
                   controller_template_P.Saturation1_LowerSat_b ?
                   controller_template_P.Saturation1_LowerSat_b :
                   controller_template_B.U_g) + (rtb_UnitDelay2 +
      controller_template_DWork.UnitDelay_DSTATE_p)) *
      controller_template_P.Gain_Gain_p0;

    /* Sum: '<S8>/Sum3' */
    rtb_yaw_rate_cmd_g = rtb_Gain_n - rtb_bias_W[3];

    /* Sum: '<S8>/Sum5' incorporates:
     *  Sum: '<S8>/Sum2'
     */
    controller_template_B.thrust_cmd_a = (rtb_Gain_i - rtb_bias_W[2]) +
      rtb_Product_l;

    /* RateTransition: '<S18>/Rate Transition1' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      controller_template_B.RateTransition1 = rtb_Gain_p;
    }

    /* End of RateTransition: '<S18>/Rate Transition1' */

    /* UnitDelay: '<S20>/Unit Delay1' */
    rtb_Add = controller_template_DWork.UnitDelay1_DSTATE_a;

    /* RateTransition: '<S27>/Rate Transition1' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      controller_template_B.RateTransition1_l = rtb_Gain_f;
    }

    /* End of RateTransition: '<S27>/Rate Transition1' */

    /* UnitDelay: '<S28>/Unit Delay1' */
    rtb_UnitDelay2 = controller_template_DWork.UnitDelay1_DSTATE_ji;

    /* RateTransition: '<S32>/Rate Transition1' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      controller_template_B.RateTransition1_h = rtb_Gain_n;
    }

    /* End of RateTransition: '<S32>/Rate Transition1' */

    /* UnitDelay: '<S33>/Unit Delay1' */
    sumViol = controller_template_DWork.UnitDelay1_DSTATE_c3;
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for UnitDelay: '<S18>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE =
        controller_template_B.RateTransition1;
    }

    /* Update for UnitDelay: '<S20>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_d = rtb_Gain_p;

    /* Update for UnitDelay: '<S20>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_jv = rtb_Add;
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for UnitDelay: '<S27>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_l =
        controller_template_B.RateTransition1_l;
    }

    /* Update for UnitDelay: '<S28>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_k = rtb_Gain_f;

    /* Update for UnitDelay: '<S28>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_f = rtb_UnitDelay2;

    /* Update for UnitDelay: '<S38>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_b = rtb_Gain_i;

    /* Update for UnitDelay: '<S38>/Unit Delay' incorporates:
     *  UnitDelay: '<S38>/Unit Delay1'
     */
    controller_template_DWork.UnitDelay_DSTATE_fw =
      controller_template_DWork.UnitDelay1_DSTATE_m;
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for UnitDelay: '<S32>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_g =
        controller_template_B.RateTransition1_h;
    }

    /* Update for UnitDelay: '<S33>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_ga = rtb_Gain_n;

    /* Update for UnitDelay: '<S33>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_p = sumViol;

    /* Update for UnitDelay: '<S20>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_a = rtb_Gain_p;

    /* Update for UnitDelay: '<S28>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_ji = rtb_Gain_f;

    /* Update for UnitDelay: '<S33>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_c3 = rtb_Gain_n;

    /* Update for UnitDelay: '<S38>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_m = rtb_Gain_i;

    /* End of Outputs for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

    /* SignalConversion: '<S12>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFi_a[0] =
      controller_template_B.DataTypeConversion[0];
    rtb_TmpSignalConversionAtToFi_a[1] =
      controller_template_B.DataTypeConversion[3];
    rtb_TmpSignalConversionAtToFi_a[2] =
      controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot;
    rtb_TmpSignalConversionAtToFi_a[3] = controller_template_B.X_ref_x[0];
    rtb_TmpSignalConversionAtToFi_a[4] = rtb_pitch_cmd_b;
    rtb_TmpSignalConversionAtToFi_a[5] =
      controller_template_B.DataTypeConversion[1];
    rtb_TmpSignalConversionAtToFi_a[6] =
      controller_template_B.DataTypeConversion[4];
    rtb_TmpSignalConversionAtToFi_a[7] =
      controller_template_B.sf_EmbeddedMATLABFunction.roll_rot;
    rtb_TmpSignalConversionAtToFi_a[8] = controller_template_B.X_ref_y[0];
    rtb_TmpSignalConversionAtToFi_a[9] = rtb_roll_cmd_c;
    rtb_TmpSignalConversionAtToFi_a[10] =
      controller_template_B.DataTypeConversion[2];
    rtb_TmpSignalConversionAtToFi_a[11] =
      controller_template_B.DataTypeConversion[5];
    rtb_TmpSignalConversionAtToFi_a[12] = controller_template_B.X_ref_z[0];
    rtb_TmpSignalConversionAtToFi_a[13] = controller_template_B.thrust_cmd_a;
    rtb_TmpSignalConversionAtToFi_a[14] =
      controller_template_B.DataTypeConversion[8];
    rtb_TmpSignalConversionAtToFi_a[15] =
      controller_template_B.DataTypeConversion[11];
    rtb_TmpSignalConversionAtToFi_a[16] = controller_template_B.X_ref_yaw[0];
    rtb_TmpSignalConversionAtToFi_a[17] = rtb_yaw_rate_cmd_g;

    /* ToFile: '<S12>/To File' */
    if (!(++controller_template_DWork.ToFile_IWORK_g.Decimation % 1) &&
        (controller_template_DWork.ToFile_IWORK_g.Count*19)+1 < 100000000 ) {
      FILE *fp = (FILE *) controller_template_DWork.ToFile_PWORK_p.FilePtr;
      if (fp != (NULL)) {
        real_T u[19];
        controller_template_DWork.ToFile_IWORK_g.Decimation = 0;
        u[0] = controller_template_M->Timing.taskTime0;
        u[1] = rtb_TmpSignalConversionAtToFi_a[0];
        u[2] = rtb_TmpSignalConversionAtToFi_a[1];
        u[3] = rtb_TmpSignalConversionAtToFi_a[2];
        u[4] = rtb_TmpSignalConversionAtToFi_a[3];
        u[5] = rtb_TmpSignalConversionAtToFi_a[4];
        u[6] = rtb_TmpSignalConversionAtToFi_a[5];
        u[7] = rtb_TmpSignalConversionAtToFi_a[6];
        u[8] = rtb_TmpSignalConversionAtToFi_a[7];
        u[9] = rtb_TmpSignalConversionAtToFi_a[8];
        u[10] = rtb_TmpSignalConversionAtToFi_a[9];
        u[11] = rtb_TmpSignalConversionAtToFi_a[10];
        u[12] = rtb_TmpSignalConversionAtToFi_a[11];
        u[13] = rtb_TmpSignalConversionAtToFi_a[12];
        u[14] = rtb_TmpSignalConversionAtToFi_a[13];
        u[15] = rtb_TmpSignalConversionAtToFi_a[14];
        u[16] = rtb_TmpSignalConversionAtToFi_a[15];
        u[17] = rtb_TmpSignalConversionAtToFi_a[16];
        u[18] = rtb_TmpSignalConversionAtToFi_a[17];
        if (fwrite(u, sizeof(real_T), 19, fp) != 19) {
          rtmSetErrorStatus(controller_template_M,
                            "Error writing to MAT-file hquad_force.mat");
          return;
        }

        if (((++controller_template_DWork.ToFile_IWORK_g.Count)*19)+1 >=
            100000000) {
          (void)fprintf(stdout,
                        "*** The ToFile block will stop logging data before\n"
                        "    the simulation has ended, because it has reached\n"
                        "    the maximum number of elements (100000000)\n"
                        "    allowed in MAT-file hquad_force.mat.\n");
        }
      }
    }

    /* ToFile: '<S12>/To File1' */
    if (!(++controller_template_DWork.ToFile1_IWORK_p.Decimation % 1) &&
        (controller_template_DWork.ToFile1_IWORK_p.Count*5)+1 < 100000000 ) {
      FILE *fp = (FILE *) controller_template_DWork.ToFile1_PWORK_i.FilePtr;
      if (fp != (NULL)) {
        real_T u[5];
        controller_template_DWork.ToFile1_IWORK_p.Decimation = 0;
        u[0] = controller_template_M->Timing.taskTime0;
        u[1] = rtb_bias_W[0];
        u[2] = rtb_bias_W[1];
        u[3] = rtb_bias_W[2];
        u[4] = rtb_bias_W[3];
        if (fwrite(u, sizeof(real_T), 5, fp) != 5) {
          rtmSetErrorStatus(controller_template_M,
                            "Error writing to MAT-file hquad_force_bias.mat");
          return;
        }

        if (((++controller_template_DWork.ToFile1_IWORK_p.Count)*5)+1 >=
            100000000) {
          (void)fprintf(stdout,
                        "*** The ToFile block will stop logging data before\n"
                        "    the simulation has ended, because it has reached\n"
                        "    the maximum number of elements (100000000)\n"
                        "    allowed in MAT-file hquad_force_bias.mat.\n");
        }
      }
    }

    /* Gain: '<S12>/rad -> deg2' */
    controller_template_B.raddeg2_p[0] = controller_template_P.raddeg2_Gain *
      controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot;
    controller_template_B.raddeg2_p[1] = controller_template_P.raddeg2_Gain *
      controller_template_B.DataTypeConversion[10];
    controller_template_B.raddeg2_p[2] = controller_template_P.raddeg2_Gain *
      rtb_pitch_cmd_b;

    /* Gain: '<S12>/rad -> deg1' */
    controller_template_B.raddeg1_e[0] = controller_template_P.raddeg1_Gain *
      controller_template_B.sf_EmbeddedMATLABFunction.roll_rot;
    controller_template_B.raddeg1_e[1] = controller_template_P.raddeg1_Gain *
      controller_template_B.DataTypeConversion[9];
    controller_template_B.raddeg1_e[2] = controller_template_P.raddeg1_Gain *
      rtb_roll_cmd_c;

    /* Gain: '<S12>/rad -> deg3' */
    controller_template_B.raddeg3_a[0] = controller_template_P.raddeg3_Gain *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg3_a[1] = controller_template_P.raddeg3_Gain *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg3_a[2] = controller_template_P.raddeg3_Gain *
      rtb_yaw_rate_cmd_g;

    /* Gain: '<S12>/rad -> deg' */
    controller_template_B.raddeg_j[0] = controller_template_P.raddeg_Gain *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg_j[1] = controller_template_P.raddeg_Gain *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg_j[2] = controller_template_P.raddeg_Gain *
      controller_template_B.X_ref_yaw[0];
    controller_template_B.raddeg_j[3] = controller_template_P.raddeg_Gain *
      controller_template_B.X_ref_yaw[1];

    /* Outputs for Atomic SubSystem: '<S2>/decoupling and rotation' */
    /* Inport: '<S9>/bias_W' */
    controller_template_B.bias_W_b[0] = rtb_bias_W[0];
    controller_template_B.bias_W_b[1] = rtb_bias_W[1];
    controller_template_B.bias_W_b[2] = rtb_bias_W[2];
    controller_template_B.bias_W_b[3] = rtb_bias_W[3];

    /* Inport: '<S9>/cmd_W' */
    controller_template_B.cmd_W_h[0] = rtb_pitch_cmd_b;
    controller_template_B.cmd_W_h[1] = rtb_roll_cmd_c;
    controller_template_B.cmd_W_h[2] = controller_template_B.thrust_cmd_a;
    controller_template_B.cmd_W_h[3] = rtb_yaw_rate_cmd_g;

    /* MATLAB Function: '<S40>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S40>/g'
     */
    controller_template_DWork.sfEvent_c = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/decoupling /Embedded MATLAB Function': '<S42>:1' */
    /* '<S42>:1:4' */
    rtb_Add = controller_template_B.cmd_W_h[2] / (cos
      (controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot) * cos
      (controller_template_B.sf_EmbeddedMATLABFunction.roll_rot));

    /* '<S42>:1:6' */
    controller_template_B.pitch_cmd_comp_n =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value / rtb_Add * controller_template_B.cmd_W_h[0];

    /* '<S42>:1:7' */
    controller_template_B.roll_cmd_comp_j =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value / rtb_Add * controller_template_B.cmd_W_h[1];

    /*  pitch_cmd_comp=pitch_cmd; */
    /*  roll_cmd_comp=roll_cmd; */
    /*  pitch_cmd_comp = atan(Fx/(-thrust_comp)); */
    /*  roll_cmd_comp = atan(Fy/(thrust_comp)); */
    /*  pitch_cmd_comp = atan(-g*m*pitch_cmd/(-thrust)); */
    /*  roll_cmd_comp = atan(g*m*roll_cmd*cos(pitch_meas)/(thrust)); */
    controller_template_B.thrust_comp_k = rtb_Add;

    /* MATLAB Function: '<S41>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_j = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S43>:1' */
    /* '<S43>:1:3' */
    rtb_Add = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S43>:1:4' */
    rtb_UnitDelay2 = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S43>:1:6' */
    /* '<S43>:1:8' */
    /* '<S43>:1:9' */
    controller_template_B.pitch_rot_n = rtb_UnitDelay2 *
      controller_template_B.pitch_cmd_comp_n + -rtb_Add *
      controller_template_B.roll_cmd_comp_j;

    /* '<S43>:1:10' */
    controller_template_B.roll_rot_e = rtb_Add *
      controller_template_B.pitch_cmd_comp_n + rtb_UnitDelay2 *
      controller_template_B.roll_cmd_comp_j;

    /* '<S43>:1:12' */
    /* '<S43>:1:13' */
    controller_template_B.pitch_bias_rot_i = rtb_UnitDelay2 *
      controller_template_B.bias_W_b[0] + -rtb_Add *
      controller_template_B.bias_W_b[1];

    /* '<S43>:1:14' */
    controller_template_B.roll_bias_rot_d = rtb_Add *
      controller_template_B.bias_W_b[0] + rtb_UnitDelay2 *
      controller_template_B.bias_W_b[1];

    /* End of Outputs for SubSystem: '<S2>/decoupling and rotation' */
    srUpdateBC(controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC);
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
  switch ((int32_T)controller_template_B.DataTypeConversion[20]) {
   case 1:
   case 2:
   case 3:
    controller_template_B.MultiportSwitch =
      controller_template_P.Constant1_Value_mr;
    break;

   default:
    controller_template_B.MultiportSwitch =
      controller_template_P.Constant2_Value_a;
    break;
  }

  /* End of MultiPortSwitch: '<S4>/Multiport Switch' */

  /* Outputs for Enabled SubSystem: '<Root>/pos controller' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (controller_template_B.MultiportSwitch > 0.0) {
    if (!controller_template_DWork.poscontroller_MODE) {
      /* InitializeConditions for MATLAB Function: '<S50>/Embedded MATLAB Function' */
      con_EmbeddedMATLABFunction_Init
        (&controller_template_DWork.sf_EmbeddedMATLABFunction_o);

      /* InitializeConditions for Atomic SubSystem: '<S7>/MAIN CONTROL LOOP1' */
      /* InitializeConditions for Delay: '<S47>/Integer Delay' */
      controller_template_DWork.IntegerDelay_DSTATE =
        controller_template_P.IntegerDelay_InitialCondition;

      /* InitializeConditions for Delay: '<S47>/Integer Delay1' */
      controller_template_DWork.IntegerDelay1_DSTATE =
        controller_template_P.IntegerDelay1_InitialCondition;

      /* InitializeConditions for Delay: '<S47>/Integer Delay2' */
      controller_template_DWork.IntegerDelay2_DSTATE =
        controller_template_P.IntegerDelay2_InitialCondition;

      /* InitializeConditions for Delay: '<S47>/Integer Delay3' */
      controller_template_DWork.IntegerDelay3_DSTATE =
        controller_template_P.IntegerDelay3_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S54>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
             controller_template_P.UnitDelay1_X0_c, sizeof(real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S62>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
        controller_template_P.FixPtUnitDelay2_X0;

      /* InitializeConditions for UnitDelay: '<S62>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
        controller_template_P.FixPtUnitDelay1_X0;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
        controller_template_P.FixPtUnitDelay1_X0;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
        controller_template_P.FixPtUnitDelay1_X0;

      /* InitializeConditions for MATLAB Function: '<S54>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter);

      /* InitializeConditions for UnitDelay: '<S53>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE[0] =
        controller_template_P.UnitDelay_X0_fc[0];
      controller_template_DWork.UnitDelay_DSTATE[1] =
        controller_template_P.UnitDelay_X0_fc[1];
      controller_template_DWork.UnitDelay_DSTATE[2] =
        controller_template_P.UnitDelay_X0_fc[2];

      /* InitializeConditions for UnitDelay: '<S53>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
             controller_template_P.UnitDelay1_X0_k, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S53>/runFastGradient' */
      controller_runFastGradient_Init
        (&controller_template_DWork.sf_runFastGradient);

      /* InitializeConditions for UnitDelay: '<S56>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
             controller_template_P.UnitDelay1_X0_fk, sizeof(real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S65>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
        controller_template_P.FixPtUnitDelay2_X0_n;

      /* InitializeConditions for UnitDelay: '<S65>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
        controller_template_P.FixPtUnitDelay1_X0_n;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
        controller_template_P.FixPtUnitDelay1_X0_n;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
        controller_template_P.FixPtUnitDelay1_X0_n;

      /* InitializeConditions for MATLAB Function: '<S56>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter_m);

      /* InitializeConditions for UnitDelay: '<S55>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_j[0] =
        controller_template_P.UnitDelay_X0_ik[0];
      controller_template_DWork.UnitDelay_DSTATE_j[1] =
        controller_template_P.UnitDelay_X0_ik[1];
      controller_template_DWork.UnitDelay_DSTATE_j[2] =
        controller_template_P.UnitDelay_X0_ik[2];

      /* InitializeConditions for UnitDelay: '<S55>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
             controller_template_P.UnitDelay1_X0_jc, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S55>/runFastGradient' */
      controller_runFastGradient_Init
        (&controller_template_DWork.sf_runFastGradient_d);

      /* InitializeConditions for UnitDelay: '<S60>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
             controller_template_P.UnitDelay1_X0_cw, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S71>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
        controller_template_P.FixPtUnitDelay2_X0_d;

      /* InitializeConditions for UnitDelay: '<S71>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
        controller_template_P.FixPtUnitDelay1_X0_c;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
        controller_template_P.FixPtUnitDelay1_X0_c;

      /* InitializeConditions for MATLAB Function: '<S60>/discrete kalman filter' */
      con_discretekalmanfilter_i_Init
        (&controller_template_DWork.sf_discretekalmanfilter_k);

      /* InitializeConditions for UnitDelay: '<S59>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_l[0] =
        controller_template_P.UnitDelay_X0_a[0];
      controller_template_DWork.UnitDelay_DSTATE_l[1] =
        controller_template_P.UnitDelay_X0_a[1];

      /* InitializeConditions for UnitDelay: '<S59>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
             controller_template_P.UnitDelay1_X0_b, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S59>/runFastGradient' */
      controller_template_DWork.sfEvent_k = CALL_EVENT;
      controller_template_DWork.is_active_c8_Hquad_control_LIB_ = 0U;

      /* InitializeConditions for UnitDelay: '<S58>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
             controller_template_P.UnitDelay1_X0_n, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S68>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
        controller_template_P.FixPtUnitDelay2_X0_i;

      /* InitializeConditions for UnitDelay: '<S68>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
        controller_template_P.FixPtUnitDelay1_X0_e;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
        controller_template_P.FixPtUnitDelay1_X0_e;

      /* InitializeConditions for MATLAB Function: '<S58>/discrete kalman filter' */
      con_discretekalmanfilter_i_Init
        (&controller_template_DWork.sf_discretekalmanfilter_n);

      /* InitializeConditions for UnitDelay: '<S57>/Unit Delay' */
      for (i = 0; i < 6; i++) {
        controller_template_DWork.UnitDelay_DSTATE_jz[i] =
          controller_template_P.UnitDelay_X0_fj[i];
      }

      /* End of InitializeConditions for UnitDelay: '<S57>/Unit Delay' */

      /* InitializeConditions for UnitDelay: '<S57>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
             controller_template_P.UnitDelay1_X0_o, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S57>/runFastGradient' */
      controller_template_DWork.sfEvent_n = CALL_EVENT;
      controller_template_DWork.is_active_c9_Hquad_control_LIB_ = 0U;

      /* End of InitializeConditions for SubSystem: '<S7>/MAIN CONTROL LOOP1' */

      /* InitializeConditions for Atomic SubSystem: '<S7>/decoupling and rotation' */
      /* InitializeConditions for MATLAB Function: '<S73>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_f = CALL_EVENT;
      controller_template_DWork.is_active_c1_Hquad_control_LIB_ = 0U;

      /* InitializeConditions for MATLAB Function: '<S74>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent = CALL_EVENT;
      controller_template_DWork.is_active_c4_Hquad_control_LIB_ = 0U;

      /* End of InitializeConditions for SubSystem: '<S7>/decoupling and rotation' */
      controller_template_DWork.poscontroller_MODE = TRUE;
    }

    /* MATLAB Function: '<S50>/Embedded MATLAB Function' */
    controll_EmbeddedMATLABFunction(controller_template_B.DataTypeConversion[6],
      controller_template_B.DataTypeConversion[7], rtb_Init[0], rtb_Init[1],
      controller_template_B.DataTypeConversion[8],
      &controller_template_B.sf_EmbeddedMATLABFunction_o,
      &controller_template_DWork.sf_EmbeddedMATLABFunction_o);

    /* Outputs for Atomic SubSystem: '<S7>/MAIN CONTROL LOOP1' */
    /* Delay: '<S47>/Integer Delay' */
    rtb_IntegerDelay = controller_template_DWork.IntegerDelay_DSTATE;

    /* Delay: '<S47>/Integer Delay1' */
    rtb_IntegerDelay1 = controller_template_DWork.IntegerDelay1_DSTATE;

    /* Delay: '<S47>/Integer Delay2' */
    rtb_IntegerDelay2 = controller_template_DWork.IntegerDelay2_DSTATE;

    /* Delay: '<S47>/Integer Delay3' */
    rtb_IntegerDelay3 = controller_template_DWork.IntegerDelay3_DSTATE;

    /* Product: '<S47>/Product' incorporates:
     *  Constant: '<S47>/gravity'
     */
    rtb_Gain_n = controller_template_P.gravity_Value_j *
      controller_template_B.DataTypeConversion[29];

    /* UnitDelay: '<S54>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE, sizeof(real_T) << 4U);

    /* Switch: '<S62>/Init' incorporates:
     *  UnitDelay: '<S62>/FixPt Unit Delay1'
     *  UnitDelay: '<S62>/FixPt Unit Delay2'
     */
    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_l != 0) {
      rtb_Init_g[0] = controller_template_B.DataTypeConversion[0];
    } else {
      rtb_Init_g[0] = controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_l != 0) {
      rtb_Init_g[1] = controller_template_B.DataTypeConversion[3];
    } else {
      rtb_Init_g[1] = controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_l != 0) {
      rtb_Init_g[2] =
        controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_rot;
    } else {
      rtb_Init_g[2] = controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2];
    }

    /* End of Switch: '<S62>/Init' */

    /* MATLAB Function: '<S54>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.DataTypeConversion[0],
      controller_template_B.DataTypeConversion[3],
      controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_rot, rtb_Init_g,
      controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_bias_rot,
      controller_template_P.A_Value, controller_template_P.B_Value,
      controller_template_P.C_Value, controller_template_P.Q_Value,
      controller_template_P.R_Value, rtb_IntegerDelay, rtb_UnitDelay1,
      &controller_template_B.sf_discretekalmanfilter,
      &controller_template_DWork.sf_discretekalmanfilter);

    /* UnitDelay: '<S53>/Unit Delay' */
    rtb_UnitDelay[0] = controller_template_DWork.UnitDelay_DSTATE[0];
    rtb_UnitDelay[1] = controller_template_DWork.UnitDelay_DSTATE[1];
    rtb_UnitDelay[2] = controller_template_DWork.UnitDelay_DSTATE[2];

    /* UnitDelay: '<S53>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_o[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_c, 30U * sizeof(real_T));

    /* MATLAB Function: '<S53>/runFastGradient' */
    controller_temp_runFastGradient(controller_template_P.TT_PP_Value,
      controller_template_P.LL_PP_Value, controller_template_P.LL_ref_PP_Value,
      controller_template_P.LL_U_ref_PP_Value, controller_template_P.MM_Value,
      controller_template_P.PP_Value, controller_template_P.AA_delay_Value,
      controller_template_P.BB_delay_Value,
      controller_template_B.sf_discretekalmanfilter.state_est,
      controller_template_B.X_ref_x, controller_template_P.V_max_Value,
      controller_template_P.i_min_Value, controller_template_P.betas_Value,
      controller_template_P.L_Value, rtb_UnitDelay, rtb_UnitDelay1_o,
      &controller_template_B.sf_runFastGradient,
      &controller_template_DWork.sf_runFastGradient);

    /* Saturate: '<S54>/Saturation' */
    rtb_yaw_rate_cmd_g =
      controller_template_B.sf_discretekalmanfilter.state_est[3] >=
      controller_template_P.Saturation_UpperSat_i ?
      controller_template_P.Saturation_UpperSat_i :
      controller_template_B.sf_discretekalmanfilter.state_est[3] <=
      controller_template_P.Saturation_LowerSat_o ?
      controller_template_P.Saturation_LowerSat_o :
      controller_template_B.sf_discretekalmanfilter.state_est[3];

    /* Sum: '<S47>/Sum' */
    tolerance = controller_template_B.sf_runFastGradient.u_opt -
      rtb_yaw_rate_cmd_g;

    /* UnitDelay: '<S56>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_oh[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_b, sizeof(real_T) << 4U);

    /* Switch: '<S65>/Init' incorporates:
     *  UnitDelay: '<S65>/FixPt Unit Delay1'
     *  UnitDelay: '<S65>/FixPt Unit Delay2'
     */
    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_b != 0) {
      rtb_Init_j[0] = controller_template_B.DataTypeConversion[1];
    } else {
      rtb_Init_j[0] = controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_b != 0) {
      rtb_Init_j[1] = controller_template_B.DataTypeConversion[4];
    } else {
      rtb_Init_j[1] = controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_b != 0) {
      rtb_Init_j[2] = controller_template_B.sf_EmbeddedMATLABFunction_o.roll_rot;
    } else {
      rtb_Init_j[2] = controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2];
    }

    /* End of Switch: '<S65>/Init' */

    /* MATLAB Function: '<S56>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.DataTypeConversion[1],
      controller_template_B.DataTypeConversion[4],
      controller_template_B.sf_EmbeddedMATLABFunction_o.roll_rot, rtb_Init_j,
      controller_template_B.sf_EmbeddedMATLABFunction_o.roll_bias_rot,
      controller_template_P.A_Value_n, controller_template_P.B_Value_h,
      controller_template_P.C_Value_p, controller_template_P.Q_Value_h,
      controller_template_P.R_Value_l, rtb_IntegerDelay1, rtb_UnitDelay1_oh,
      &controller_template_B.sf_discretekalmanfilter_m,
      &controller_template_DWork.sf_discretekalmanfilter_m);

    /* UnitDelay: '<S55>/Unit Delay' */
    rtb_UnitDelay_e[0] = controller_template_DWork.UnitDelay_DSTATE_j[0];
    rtb_UnitDelay_e[1] = controller_template_DWork.UnitDelay_DSTATE_j[1];
    rtb_UnitDelay_e[2] = controller_template_DWork.UnitDelay_DSTATE_j[2];

    /* UnitDelay: '<S55>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_g[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_l, 30U * sizeof(real_T));

    /* MATLAB Function: '<S55>/runFastGradient' */
    controller_temp_runFastGradient(controller_template_P.TT_PP_Value_m,
      controller_template_P.LL_PP_Value_e,
      controller_template_P.LL_ref_PP_Value_l,
      controller_template_P.LL_U_ref_PP_Value_m,
      controller_template_P.MM_Value_c, controller_template_P.PP_Value_m,
      controller_template_P.AA_delay_Value_h,
      controller_template_P.BB_delay_Value_o,
      controller_template_B.sf_discretekalmanfilter_m.state_est,
      controller_template_B.X_ref_y, controller_template_P.V_max_Value_o,
      controller_template_P.i_min_Value_j, controller_template_P.betas_Value_l,
      controller_template_P.L_Value_n, rtb_UnitDelay_e, rtb_UnitDelay1_g,
      &controller_template_B.sf_runFastGradient_d,
      &controller_template_DWork.sf_runFastGradient_d);

    /* Saturate: '<S56>/Saturation' */
    abspos = controller_template_B.sf_discretekalmanfilter_m.state_est[3] >=
      controller_template_P.Saturation_UpperSat_f ?
      controller_template_P.Saturation_UpperSat_f :
      controller_template_B.sf_discretekalmanfilter_m.state_est[3] <=
      controller_template_P.Saturation_LowerSat_k ?
      controller_template_P.Saturation_LowerSat_k :
      controller_template_B.sf_discretekalmanfilter_m.state_est[3];

    /* Sum: '<S47>/Sum1' */
    rtb_Gain_i = controller_template_B.sf_runFastGradient_d.u_opt - abspos;

    /* UnitDelay: '<S60>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_j[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_j, 9U * sizeof(real_T));

    /* Switch: '<S71>/Init' incorporates:
     *  UnitDelay: '<S71>/FixPt Unit Delay1'
     *  UnitDelay: '<S71>/FixPt Unit Delay2'
     */
    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_c != 0) {
      rtb_Init_d[0] = controller_template_B.DataTypeConversion[2];
    } else {
      rtb_Init_d[0] = controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_c != 0) {
      rtb_Init_d[1] = controller_template_B.DataTypeConversion[5];
    } else {
      rtb_Init_d[1] = controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1];
    }

    /* End of Switch: '<S71>/Init' */

    /* MATLAB Function: '<S60>/discrete kalman filter' */
    controll_discretekalmanfilter_n(controller_template_B.DataTypeConversion[2],
      controller_template_B.DataTypeConversion[5], rtb_Init_d, rtb_Init[2],
      controller_template_P.A_Value_f, controller_template_P.B_Value_n,
      controller_template_P.C_Value_o, controller_template_P.Q_Value_j,
      controller_template_P.R_Value_c, rtb_IntegerDelay2, rtb_UnitDelay1_j,
      &controller_template_B.sf_discretekalmanfilter_k,
      &controller_template_DWork.sf_discretekalmanfilter_k);

    /* MATLAB Function: '<S59>/runFastGradient' incorporates:
     *  Constant: '<S59>/AA_delay'
     *  Constant: '<S59>/BB_delay'
     *  Constant: '<S59>/L'
     *  Constant: '<S59>/LL_PP'
     *  Constant: '<S59>/LL_U_ref_PP'
     *  Constant: '<S59>/LL_ref_PP'
     *  Constant: '<S59>/MM'
     *  Constant: '<S59>/PP'
     *  Constant: '<S59>/TT_PP'
     *  Constant: '<S59>/V_max'
     *  Constant: '<S59>/betas'
     *  Constant: '<S59>/i_min'
     *  UnitDelay: '<S59>/Unit Delay'
     *  UnitDelay: '<S59>/Unit Delay1'
     */
    controller_template_DWork.sfEvent_k = CALL_EVENT;

    /* MATLAB Function 'z controller MPC FG/runFastGradient': '<S70>:1' */
    /*  ugly, but simulink needs fix output sizes for vectors */
    /*  number of outputs u */
    /*  number of delay steps */
    /*  prediction horizon */
    /*  predict non-delayed state */
    /* '<S70>:1:14' */
    temp_idx = (controller_template_P.AA_delay_Value_l[0] *
                controller_template_B.sf_discretekalmanfilter_k.state_est[0] +
                controller_template_P.AA_delay_Value_l[2] *
                controller_template_B.sf_discretekalmanfilter_k.state_est[1]) +
      (controller_template_P.BB_delay_Value_b[0] *
       controller_template_DWork.UnitDelay_DSTATE_l[0] +
       controller_template_P.BB_delay_Value_b[2] *
       controller_template_DWork.UnitDelay_DSTATE_l[1]);
    temp_idx_0 = (controller_template_P.AA_delay_Value_l[1] *
                  controller_template_B.sf_discretekalmanfilter_k.state_est[0] +
                  controller_template_P.AA_delay_Value_l[3] *
                  controller_template_B.sf_discretekalmanfilter_k.state_est[1])
      + (controller_template_P.BB_delay_Value_b[1] *
         controller_template_DWork.UnitDelay_DSTATE_l[0] +
         controller_template_P.BB_delay_Value_b[3] *
         controller_template_DWork.UnitDelay_DSTATE_l[1]);

    /*  TODO get U_ref from trajectory */
    /*  set optimization variables */
    /* '<S70>:1:21' */
    for (k = 0; k < 30; k++) {
      temp[k] = 0.0;
      temp[k] += controller_template_P.LL_PP_Value_j[(k << 1)] * temp_idx;
      temp[k] += controller_template_P.LL_PP_Value_j[(k << 1) + 1] * temp_idx_0;
      tmp[k] = 0.0;
      for (minreg = 0; minreg < 62; minreg++) {
        tmp[k] += controller_template_P.LL_ref_PP_Value_h[62 * k + minreg] *
          controller_template_B.X_ref_z[minreg];
      }
    }

    for (k = 0; k < 30; k++) {
      rtb_Add = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        rtb_Add += controller_template_P.LL_U_ref_PP_Value_o[30 * k + minreg] *
          0.0;
      }

      LL_PP_ref[k] = (temp[k] - tmp[k]) - rtb_Add;
    }

    /* '<S70>:1:22' */
    /*  TODO expand to X_ref, U_ref */
    /*  run fast gradient method */
    for (i = 0; i < 30; i++) {
      temp[i] = -controller_template_P.V_max_Value_i[i];
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
    rtb_UnitDelay2 = 1.0 / controller_template_P.L_Value_m;
    for (k = 0; k < 30; k++) {
      rtb_Add = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        rtb_Add += controller_template_P.TT_PP_Value_b[30 * minreg + k] *
          controller_template_DWork.UnitDelay1_DSTATE_g[minreg];
      }

      tmp[k] = rtb_Add + LL_PP_ref[k];
    }

    for (k = 0; k < 30; k++) {
      rtb_Gain_f = controller_template_DWork.UnitDelay1_DSTATE_g[k] -
        rtb_UnitDelay2 * tmp[k];
      rtb_Add = (controller_template_P.V_max_Value_i[k] <= rtb_Gain_f) ||
        rtIsNaN(rtb_Gain_f) ? controller_template_P.V_max_Value_i[k] :
        rtb_Gain_f;
      sumViol = (temp[k] >= rtb_Add) || rtIsNaN(rtb_Add) ? temp[k] : rtb_Add;
      V_ip[k] = sumViol;
      V_i[k] = sumViol;
      U_star[k] = rtb_Gain_f;
    }

    /*  now run the fast gradient method: */
    for (i = 0; i <= (int32_T)controller_template_P.i_min_Value_o - 1; i++) {
      for (k = 0; k < 30; k++) {
        rtb_Add = 0.0;
        for (minreg = 0; minreg < 30; minreg++) {
          rtb_Add += controller_template_P.TT_PP_Value_b[30 * minreg + k] *
            V_ip[minreg];
        }

        tmp[k] = rtb_Add + LL_PP_ref[k];
      }

      /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
      /*      convergence result idea */
      for (k = 0; k < 30; k++) {
        rtb_Gain_f = V_ip[k] - rtb_UnitDelay2 * tmp[k];
        rtb_Add = (controller_template_P.V_max_Value_i[k] <= rtb_Gain_f) ||
          rtIsNaN(rtb_Gain_f) ? controller_template_P.V_max_Value_i[k] :
          rtb_Gain_f;
        rtb_Add = (temp[k] >= rtb_Add) || rtIsNaN(rtb_Add) ? temp[k] : rtb_Add;
        rtb_Gain_f = controller_template_P.betas_Value_g[(int32_T)(1.0 + (real_T)
          i) - 1] * (rtb_Add - V_i[k]);
        sumViol = rtb_Add;
        rtb_Add += rtb_Gain_f;
        U_star[k] = rtb_Gain_f;
        V_i[k] = sumViol;
        V_ip[k] = rtb_Add;
      }
    }

    /*  return values: */
    rtb_Add = 0.0;
    rtb_UnitDelay2 = 0.0;

    /*  plot(residuals) just for testing new convergence result idea */
    /* '<S70>:1:25' */
    /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
    /*  so don't forget to backtransform after termination: */
    /* '<S70>:1:32' */
    for (k = 0; k < 30; k++) {
      b_y[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        b_y[k] += controller_template_P.TT_PP_Value_b[30 * k + minreg] * (0.5 *
          V_i[minreg]);
      }

      rtb_Add += b_y[k] * V_i[k];
      rtb_UnitDelay2 += LL_PP_ref[k] * V_i[k];
      U_star[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        U_star[k] += controller_template_P.PP_Value_o[30 * minreg + k] *
          V_i[minreg];
      }
    }

    /*  save outputs for delayed system */
    /* '<S70>:1:38' */
    /*  set new initial guess */
    /* '<S70>:1:42' */
    /* '<S70>:1:44' */
    controller_template_B.u_opt = U_star[0];
    controller_template_B.J_star = ((temp_idx *
      controller_template_P.MM_Value_l[0] + temp_idx_0 *
      controller_template_P.MM_Value_l[1]) * temp_idx + (temp_idx *
      controller_template_P.MM_Value_l[2] + temp_idx_0 *
      controller_template_P.MM_Value_l[3]) * temp_idx_0) + (rtb_Add +
      rtb_UnitDelay2);
    controller_template_B.u_buff_out[0] =
      controller_template_DWork.UnitDelay_DSTATE_l[1];
    controller_template_B.u_buff_out[1] = U_star[0];
    memcpy((void *)(&controller_template_B.V_init_out[0]), (void *)&V_i[1], 29U *
           sizeof(real_T));
    controller_template_B.V_init_out[29] = 0.0;

    /* End of MATLAB Function: '<S59>/runFastGradient' */

    /* Saturate: '<S60>/Saturation' */
    rtb_Saturation_n =
      controller_template_B.sf_discretekalmanfilter_k.state_est[2] >=
      controller_template_P.Saturation_UpperSat_l ?
      controller_template_P.Saturation_UpperSat_l :
      controller_template_B.sf_discretekalmanfilter_k.state_est[2] <=
      controller_template_P.Saturation_LowerSat_c ?
      controller_template_P.Saturation_LowerSat_c :
      controller_template_B.sf_discretekalmanfilter_k.state_est[2];

    /* Sum: '<S47>/Sum2' */
    rtb_Product_l = controller_template_B.u_opt - rtb_Saturation_n;

    /* UnitDelay: '<S58>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_n[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_lx, 9U * sizeof(real_T));

    /* Switch: '<S68>/Init' incorporates:
     *  UnitDelay: '<S68>/FixPt Unit Delay1'
     *  UnitDelay: '<S68>/FixPt Unit Delay2'
     */
    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init_h[0] = controller_template_B.DataTypeConversion[8];
    } else {
      rtb_Init_h[0] = controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init_h[1] = controller_template_B.DataTypeConversion[11];
    } else {
      rtb_Init_h[1] = controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1];
    }

    /* End of Switch: '<S68>/Init' */

    /* MATLAB Function: '<S58>/discrete kalman filter' */
    controll_discretekalmanfilter_n(controller_template_B.DataTypeConversion[8],
      controller_template_B.DataTypeConversion[11], rtb_Init_h, rtb_Init[3],
      controller_template_P.A_Value_k, controller_template_P.B_Value_f,
      controller_template_P.C_Value_b, controller_template_P.Q_Value_g,
      controller_template_P.R_Value_o, rtb_IntegerDelay3, rtb_UnitDelay1_n,
      &controller_template_B.sf_discretekalmanfilter_n,
      &controller_template_DWork.sf_discretekalmanfilter_n);

    /* MATLAB Function: '<S57>/runFastGradient' incorporates:
     *  Constant: '<S57>/AA_delay'
     *  Constant: '<S57>/BB_delay'
     *  Constant: '<S57>/L'
     *  Constant: '<S57>/LL_PP'
     *  Constant: '<S57>/LL_U_ref_PP'
     *  Constant: '<S57>/LL_ref_PP'
     *  Constant: '<S57>/MM'
     *  Constant: '<S57>/PP'
     *  Constant: '<S57>/TT_PP'
     *  Constant: '<S57>/V_max'
     *  Constant: '<S57>/betas'
     *  Constant: '<S57>/i_min'
     *  UnitDelay: '<S57>/Unit Delay'
     *  UnitDelay: '<S57>/Unit Delay1'
     */
    controller_template_DWork.sfEvent_n = CALL_EVENT;

    /* MATLAB Function 'yaw controller MPC FG/runFastGradient': '<S67>:1' */
    /*  ugly, but simulink needs fix output sizes for vectors */
    /*  number of outputs u */
    /*  number of delay steps */
    /*  prediction horizon */
    /*  predict non-delayed state */
    /* '<S67>:1:14' */
    for (k = 0; k < 2; k++) {
      tmp_0[k] = 0.0;
      for (minreg = 0; minreg < 6; minreg++) {
        tmp_0[k] += controller_template_P.BB_delay_Value_d[(minreg << 1) + k] *
          controller_template_DWork.UnitDelay_DSTATE_jz[minreg];
      }
    }

    temp_idx = (controller_template_P.AA_delay_Value_o[0] *
                controller_template_B.sf_discretekalmanfilter_n.state_est[0] +
                controller_template_P.AA_delay_Value_o[2] *
                controller_template_B.sf_discretekalmanfilter_n.state_est[1]) +
      tmp_0[0];
    temp_idx_0 = (controller_template_P.AA_delay_Value_o[1] *
                  controller_template_B.sf_discretekalmanfilter_n.state_est[0] +
                  controller_template_P.AA_delay_Value_o[3] *
                  controller_template_B.sf_discretekalmanfilter_n.state_est[1])
      + tmp_0[1];

    /*  TODO get U_ref from trajectory */
    /*  set optimization variables */
    /* '<S67>:1:21' */
    for (k = 0; k < 30; k++) {
      temp[k] = 0.0;
      temp[k] += controller_template_P.LL_PP_Value_j5[(k << 1)] * temp_idx;
      temp[k] += controller_template_P.LL_PP_Value_j5[(k << 1) + 1] * temp_idx_0;
      tmp[k] = 0.0;
      for (minreg = 0; minreg < 62; minreg++) {
        tmp[k] += controller_template_P.LL_ref_PP_Value_e[62 * k + minreg] *
          controller_template_B.X_ref_yaw[minreg];
      }
    }

    for (k = 0; k < 30; k++) {
      rtb_Add = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        rtb_Add += controller_template_P.LL_U_ref_PP_Value_b[30 * k + minreg] *
          0.0;
      }

      LL_PP_ref[k] = (temp[k] - tmp[k]) - rtb_Add;
    }

    /* '<S67>:1:22' */
    /*  TODO expand to X_ref, U_ref */
    /*  run fast gradient method */
    for (i = 0; i < 30; i++) {
      temp[i] = -controller_template_P.V_max_Value_f[i];
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
    rtb_UnitDelay2 = 1.0 / controller_template_P.L_Value_g;
    for (k = 0; k < 30; k++) {
      rtb_Add = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        rtb_Add += controller_template_P.TT_PP_Value_o[30 * minreg + k] *
          controller_template_DWork.UnitDelay1_DSTATE_js[minreg];
      }

      tmp[k] = rtb_Add + LL_PP_ref[k];
    }

    for (k = 0; k < 30; k++) {
      rtb_Gain_f = controller_template_DWork.UnitDelay1_DSTATE_js[k] -
        rtb_UnitDelay2 * tmp[k];
      rtb_Add = (controller_template_P.V_max_Value_f[k] <= rtb_Gain_f) ||
        rtIsNaN(rtb_Gain_f) ? controller_template_P.V_max_Value_f[k] :
        rtb_Gain_f;
      sumViol = (temp[k] >= rtb_Add) || rtIsNaN(rtb_Add) ? temp[k] : rtb_Add;
      V_ip[k] = sumViol;
      V_i[k] = sumViol;
      U_star[k] = rtb_Gain_f;
    }

    /*  now run the fast gradient method: */
    for (i = 0; i <= (int32_T)controller_template_P.i_min_Value_n - 1; i++) {
      for (k = 0; k < 30; k++) {
        rtb_Add = 0.0;
        for (minreg = 0; minreg < 30; minreg++) {
          rtb_Add += controller_template_P.TT_PP_Value_o[30 * minreg + k] *
            V_ip[minreg];
        }

        tmp[k] = rtb_Add + LL_PP_ref[k];
      }

      /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
      /*      convergence result idea */
      for (k = 0; k < 30; k++) {
        rtb_Gain_f = V_ip[k] - rtb_UnitDelay2 * tmp[k];
        rtb_Add = (controller_template_P.V_max_Value_f[k] <= rtb_Gain_f) ||
          rtIsNaN(rtb_Gain_f) ? controller_template_P.V_max_Value_f[k] :
          rtb_Gain_f;
        rtb_Add = (temp[k] >= rtb_Add) || rtIsNaN(rtb_Add) ? temp[k] : rtb_Add;
        rtb_Gain_f = controller_template_P.betas_Value_j[(int32_T)(1.0 + (real_T)
          i) - 1] * (rtb_Add - V_i[k]);
        sumViol = rtb_Add;
        rtb_Add += rtb_Gain_f;
        U_star[k] = rtb_Gain_f;
        V_i[k] = sumViol;
        V_ip[k] = rtb_Add;
      }
    }

    /*  return values: */
    rtb_Add = 0.0;
    rtb_UnitDelay2 = 0.0;

    /*  plot(residuals) just for testing new convergence result idea */
    /* '<S67>:1:25' */
    /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
    /*  so don't forget to backtransform after termination: */
    /* '<S67>:1:32' */
    for (k = 0; k < 30; k++) {
      b_y[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        b_y[k] += controller_template_P.TT_PP_Value_o[30 * k + minreg] * (0.5 *
          V_i[minreg]);
      }

      rtb_Add += b_y[k] * V_i[k];
      rtb_UnitDelay2 += LL_PP_ref[k] * V_i[k];
      U_star[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        U_star[k] += controller_template_P.PP_Value_p[30 * minreg + k] *
          V_i[minreg];
      }
    }

    /*  save outputs for delayed system */
    /* '<S67>:1:38' */
    /*  set new initial guess */
    /* '<S67>:1:42' */
    /* '<S67>:1:44' */
    controller_template_B.u_opt_l = U_star[0];
    controller_template_B.J_star_h = ((temp_idx *
      controller_template_P.MM_Value_g[0] + temp_idx_0 *
      controller_template_P.MM_Value_g[1]) * temp_idx + (temp_idx *
      controller_template_P.MM_Value_g[2] + temp_idx_0 *
      controller_template_P.MM_Value_g[3]) * temp_idx_0) + (rtb_Add +
      rtb_UnitDelay2);
    for (i = 0; i < 5; i++) {
      controller_template_B.u_buff_out_i[i] =
        controller_template_DWork.UnitDelay_DSTATE_jz[i + 1];
    }

    controller_template_B.u_buff_out_i[5] = U_star[0];
    memcpy((void *)(&controller_template_B.V_init_out_n[0]), (void *)&V_i[1],
           29U * sizeof(real_T));
    controller_template_B.V_init_out_n[29] = 0.0;

    /* End of MATLAB Function: '<S57>/runFastGradient' */

    /* Saturate: '<S58>/Saturation' */
    rtb_UnitDelay2 = controller_template_B.sf_discretekalmanfilter_n.state_est[2]
      >= controller_template_P.Saturation_UpperSat_o3 ?
      controller_template_P.Saturation_UpperSat_o3 :
      controller_template_B.sf_discretekalmanfilter_n.state_est[2] <=
      controller_template_P.Saturation_LowerSat_kn ?
      controller_template_P.Saturation_LowerSat_kn :
      controller_template_B.sf_discretekalmanfilter_n.state_est[2];

    /* Sum: '<S47>/Sum3' */
    rtb_Add = controller_template_B.u_opt_l - rtb_UnitDelay2;

    /* Sum: '<S47>/Sum5' */
    controller_template_B.thrust_cmd_e = rtb_Product_l + rtb_Gain_n;

    /* Update for Delay: '<S47>/Integer Delay' */
    controller_template_DWork.IntegerDelay_DSTATE = tolerance;

    /* Update for Delay: '<S47>/Integer Delay1' */
    controller_template_DWork.IntegerDelay1_DSTATE = rtb_Gain_i;

    /* Update for Delay: '<S47>/Integer Delay2' */
    controller_template_DWork.IntegerDelay2_DSTATE = rtb_Product_l;

    /* Update for Delay: '<S47>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE = rtb_Add;

    /* Update for UnitDelay: '<S54>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
           (&controller_template_B.sf_discretekalmanfilter.P_est[0]), sizeof
           (real_T) << 4U);

    /* Update for UnitDelay: '<S62>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S62>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
      controller_template_P.FixPtConstant_Value;

    /* Update for UnitDelay: '<S62>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
      controller_template_B.sf_discretekalmanfilter.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
      controller_template_B.sf_discretekalmanfilter.state_est[1];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
      controller_template_B.sf_discretekalmanfilter.state_est[2];

    /* Update for UnitDelay: '<S53>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE[0] =
      controller_template_B.sf_runFastGradient.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE[1] =
      controller_template_B.sf_runFastGradient.u_buff_out[1];
    controller_template_DWork.UnitDelay_DSTATE[2] =
      controller_template_B.sf_runFastGradient.u_buff_out[2];

    /* Update for UnitDelay: '<S53>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
           (&controller_template_B.sf_runFastGradient.V_init_out[0]), 30U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S56>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
           (&controller_template_B.sf_discretekalmanfilter_m.P_est[0]), sizeof
           (real_T) << 4U);

    /* Update for UnitDelay: '<S65>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S65>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
      controller_template_P.FixPtConstant_Value_o;

    /* Update for UnitDelay: '<S65>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[1];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[2];

    /* Update for UnitDelay: '<S55>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_j[0] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE_j[1] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[1];
    controller_template_DWork.UnitDelay_DSTATE_j[2] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[2];

    /* Update for UnitDelay: '<S55>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
           (&controller_template_B.sf_runFastGradient_d.V_init_out[0]), 30U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S60>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
           (&controller_template_B.sf_discretekalmanfilter_k.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S71>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S71>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
      controller_template_P.FixPtConstant_Value_p;

    /* Update for UnitDelay: '<S71>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
      controller_template_B.sf_discretekalmanfilter_k.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
      controller_template_B.sf_discretekalmanfilter_k.state_est[1];

    /* Update for UnitDelay: '<S59>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_l[0] =
      controller_template_B.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE_l[1] =
      controller_template_B.u_buff_out[1];

    /* Update for UnitDelay: '<S59>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
           (&controller_template_B.V_init_out[0]), 30U * sizeof(real_T));

    /* Update for UnitDelay: '<S58>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
           (&controller_template_B.sf_discretekalmanfilter_n.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S68>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S68>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
      controller_template_P.FixPtConstant_Value_n;

    /* Update for UnitDelay: '<S68>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[1];

    /* Update for UnitDelay: '<S57>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      controller_template_DWork.UnitDelay_DSTATE_jz[i] =
        controller_template_B.u_buff_out_i[i];
    }

    /* End of Update for UnitDelay: '<S57>/Unit Delay' */

    /* Update for UnitDelay: '<S57>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
           (&controller_template_B.V_init_out_n[0]), 30U * sizeof(real_T));

    /* End of Outputs for SubSystem: '<S7>/MAIN CONTROL LOOP1' */

    /* SignalConversion: '<S51>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFi_f[0] =
      controller_template_B.DataTypeConversion[0];
    rtb_TmpSignalConversionAtToFi_f[1] =
      controller_template_B.DataTypeConversion[3];
    rtb_TmpSignalConversionAtToFi_f[2] =
      controller_template_B.DataTypeConversion[7];
    rtb_TmpSignalConversionAtToFi_f[3] = controller_template_B.X_ref_x[0];
    rtb_TmpSignalConversionAtToFi_f[4] = tolerance;
    rtb_TmpSignalConversionAtToFi_f[5] =
      controller_template_B.DataTypeConversion[1];
    rtb_TmpSignalConversionAtToFi_f[6] =
      controller_template_B.DataTypeConversion[4];
    rtb_TmpSignalConversionAtToFi_f[7] =
      controller_template_B.DataTypeConversion[6];
    rtb_TmpSignalConversionAtToFi_f[8] = controller_template_B.X_ref_y[0];
    rtb_TmpSignalConversionAtToFi_f[9] = rtb_Gain_i;
    rtb_TmpSignalConversionAtToFi_f[10] =
      controller_template_B.DataTypeConversion[2];
    rtb_TmpSignalConversionAtToFi_f[11] =
      controller_template_B.DataTypeConversion[5];
    rtb_TmpSignalConversionAtToFi_f[12] = controller_template_B.X_ref_z[0];
    rtb_TmpSignalConversionAtToFi_f[13] = controller_template_B.thrust_cmd_e;
    rtb_TmpSignalConversionAtToFi_f[14] =
      controller_template_B.DataTypeConversion[8];
    rtb_TmpSignalConversionAtToFi_f[15] =
      controller_template_B.DataTypeConversion[11];
    rtb_TmpSignalConversionAtToFi_f[16] = controller_template_B.X_ref_yaw[0];
    rtb_TmpSignalConversionAtToFi_f[17] = rtb_Add;

    /* ToFile: '<S51>/To File' */
    if (!(++controller_template_DWork.ToFile_IWORK.Decimation % 1) &&
        (controller_template_DWork.ToFile_IWORK.Count*19)+1 < 100000000 ) {
      FILE *fp = (FILE *) controller_template_DWork.ToFile_PWORK.FilePtr;
      if (fp != (NULL)) {
        real_T u[19];
        controller_template_DWork.ToFile_IWORK.Decimation = 0;
        u[0] = controller_template_M->Timing.taskTime0;
        u[1] = rtb_TmpSignalConversionAtToFi_f[0];
        u[2] = rtb_TmpSignalConversionAtToFi_f[1];
        u[3] = rtb_TmpSignalConversionAtToFi_f[2];
        u[4] = rtb_TmpSignalConversionAtToFi_f[3];
        u[5] = rtb_TmpSignalConversionAtToFi_f[4];
        u[6] = rtb_TmpSignalConversionAtToFi_f[5];
        u[7] = rtb_TmpSignalConversionAtToFi_f[6];
        u[8] = rtb_TmpSignalConversionAtToFi_f[7];
        u[9] = rtb_TmpSignalConversionAtToFi_f[8];
        u[10] = rtb_TmpSignalConversionAtToFi_f[9];
        u[11] = rtb_TmpSignalConversionAtToFi_f[10];
        u[12] = rtb_TmpSignalConversionAtToFi_f[11];
        u[13] = rtb_TmpSignalConversionAtToFi_f[12];
        u[14] = rtb_TmpSignalConversionAtToFi_f[13];
        u[15] = rtb_TmpSignalConversionAtToFi_f[14];
        u[16] = rtb_TmpSignalConversionAtToFi_f[15];
        u[17] = rtb_TmpSignalConversionAtToFi_f[16];
        u[18] = rtb_TmpSignalConversionAtToFi_f[17];
        if (fwrite(u, sizeof(real_T), 19, fp) != 19) {
          rtmSetErrorStatus(controller_template_M,
                            "Error writing to MAT-file hquad_pos_FG.mat");
          return;
        }

        if (((++controller_template_DWork.ToFile_IWORK.Count)*19)+1 >= 100000000)
        {
          (void)fprintf(stdout,
                        "*** The ToFile block will stop logging data before\n"
                        "    the simulation has ended, because it has reached\n"
                        "    the maximum number of elements (100000000)\n"
                        "    allowed in MAT-file hquad_pos_FG.mat.\n");
        }
      }
    }

    /* SignalConversion: '<S51>/TmpSignal ConversionAtTo File1Inport1' */
    rtb_TmpSignalConversionAtToFile[0] = rtb_yaw_rate_cmd_g;
    rtb_TmpSignalConversionAtToFile[1] = abspos;
    rtb_TmpSignalConversionAtToFile[2] = rtb_Saturation_n;
    rtb_TmpSignalConversionAtToFile[3] = rtb_UnitDelay2;

    /* ToFile: '<S51>/To File1' */
    if (!(++controller_template_DWork.ToFile1_IWORK.Decimation % 1) &&
        (controller_template_DWork.ToFile1_IWORK.Count*5)+1 < 100000000 ) {
      FILE *fp = (FILE *) controller_template_DWork.ToFile1_PWORK.FilePtr;
      if (fp != (NULL)) {
        real_T u[5];
        controller_template_DWork.ToFile1_IWORK.Decimation = 0;
        u[0] = controller_template_M->Timing.taskTime0;
        u[1] = rtb_TmpSignalConversionAtToFile[0];
        u[2] = rtb_TmpSignalConversionAtToFile[1];
        u[3] = rtb_TmpSignalConversionAtToFile[2];
        u[4] = rtb_TmpSignalConversionAtToFile[3];
        if (fwrite(u, sizeof(real_T), 5, fp) != 5) {
          rtmSetErrorStatus(controller_template_M,
                            "Error writing to MAT-file hquad_pos_FG_bias.mat");
          return;
        }

        if (((++controller_template_DWork.ToFile1_IWORK.Count)*5)+1 >= 100000000)
        {
          (void)fprintf(stdout,
                        "*** The ToFile block will stop logging data before\n"
                        "    the simulation has ended, because it has reached\n"
                        "    the maximum number of elements (100000000)\n"
                        "    allowed in MAT-file hquad_pos_FG_bias.mat.\n");
        }
      }
    }

    /* Gain: '<S51>/rad -> deg2' */
    controller_template_B.raddeg2[0] = controller_template_P.raddeg2_Gain_p *
      controller_template_B.DataTypeConversion[7];
    controller_template_B.raddeg2[1] = controller_template_P.raddeg2_Gain_p *
      controller_template_B.DataTypeConversion[10];
    controller_template_B.raddeg2[2] = controller_template_P.raddeg2_Gain_p *
      tolerance;

    /* Gain: '<S51>/rad -> deg1' */
    controller_template_B.raddeg1[0] = controller_template_P.raddeg1_Gain_a *
      controller_template_B.DataTypeConversion[6];
    controller_template_B.raddeg1[1] = controller_template_P.raddeg1_Gain_a *
      controller_template_B.DataTypeConversion[9];
    controller_template_B.raddeg1[2] = controller_template_P.raddeg1_Gain_a *
      rtb_Gain_i;

    /* Gain: '<S51>/rad -> deg3' */
    controller_template_B.raddeg3[0] = controller_template_P.raddeg3_Gain_k *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg3[1] = controller_template_P.raddeg3_Gain_k *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg3[2] = controller_template_P.raddeg3_Gain_k *
      rtb_Add;

    /* Gain: '<S51>/rad -> deg' */
    controller_template_B.raddeg[0] = controller_template_P.raddeg_Gain_k *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg[1] = controller_template_P.raddeg_Gain_k *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg[2] = controller_template_P.raddeg_Gain_k *
      controller_template_B.X_ref_yaw[0];
    controller_template_B.raddeg[3] = controller_template_P.raddeg_Gain_k *
      controller_template_B.X_ref_yaw[1];

    /* Outputs for Atomic SubSystem: '<S7>/decoupling and rotation' */
    /* Inport: '<S48>/bias_W' */
    controller_template_B.bias_W[0] = rtb_TmpSignalConversionAtToFile[0];
    controller_template_B.bias_W[1] = rtb_TmpSignalConversionAtToFile[1];
    controller_template_B.bias_W[2] = rtb_TmpSignalConversionAtToFile[2];
    controller_template_B.bias_W[3] = rtb_TmpSignalConversionAtToFile[3];

    /* Inport: '<S48>/cmd_W' */
    controller_template_B.cmd_W[0] = tolerance;
    controller_template_B.cmd_W[1] = rtb_Gain_i;
    controller_template_B.cmd_W[2] = controller_template_B.thrust_cmd_e;
    controller_template_B.cmd_W[3] = rtb_Add;

    /* MATLAB Function: '<S73>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S73>/g'
     */
    controller_template_DWork.sfEvent_f = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/decoupling /Embedded MATLAB Function': '<S75>:1' */
    /* '<S75>:1:4' */
    rtb_Add = controller_template_B.cmd_W[2] / (cos
      (controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_rot) * cos
      (controller_template_B.sf_EmbeddedMATLABFunction_o.roll_rot));

    /* '<S75>:1:6' */
    controller_template_B.pitch_cmd_comp =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value_m / rtb_Add * controller_template_B.cmd_W[0];

    /* '<S75>:1:7' */
    controller_template_B.roll_cmd_comp =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value_m / rtb_Add * controller_template_B.cmd_W[1];

    /*  pitch_cmd_comp=pitch_cmd; */
    /*  roll_cmd_comp=roll_cmd; */
    /*  pitch_cmd_comp = atan(Fx/(-thrust_comp)); */
    /*  roll_cmd_comp = atan(Fy/(thrust_comp)); */
    /*  pitch_cmd_comp = atan(-g*m*pitch_cmd/(-thrust)); */
    /*  roll_cmd_comp = atan(g*m*roll_cmd*cos(pitch_meas)/(thrust)); */
    controller_template_B.thrust_comp = rtb_Add;

    /* MATLAB Function: '<S74>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S76>:1' */
    /* '<S76>:1:3' */
    rtb_Add = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S76>:1:4' */
    rtb_UnitDelay2 = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S76>:1:6' */
    /* '<S76>:1:8' */
    /* '<S76>:1:9' */
    controller_template_B.pitch_rot = rtb_UnitDelay2 *
      controller_template_B.pitch_cmd_comp + -rtb_Add *
      controller_template_B.roll_cmd_comp;

    /* '<S76>:1:10' */
    controller_template_B.roll_rot = rtb_Add *
      controller_template_B.pitch_cmd_comp + rtb_UnitDelay2 *
      controller_template_B.roll_cmd_comp;

    /* '<S76>:1:12' */
    /* '<S76>:1:13' */
    controller_template_B.pitch_bias_rot = rtb_UnitDelay2 *
      controller_template_B.bias_W[0] + -rtb_Add * controller_template_B.bias_W
      [1];

    /* '<S76>:1:14' */
    controller_template_B.roll_bias_rot = rtb_Add *
      controller_template_B.bias_W[0] + rtb_UnitDelay2 *
      controller_template_B.bias_W[1];

    /* End of Outputs for SubSystem: '<S7>/decoupling and rotation' */
    srUpdateBC(controller_template_DWork.poscontroller_SubsysRanBC);
  } else {
    if (controller_template_DWork.poscontroller_MODE) {
      controller_template_DWork.poscontroller_MODE = FALSE;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/pos controller' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S3>/pitch'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    controller_template_B.pitch_cmd = controller_template_B.pitch_rot_n;
  } else if (controller_template_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    controller_template_B.pitch_cmd = controller_template_B.pitch_rot;
  } else {
    controller_template_B.pitch_cmd = controller_template_P.pitch_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S3>/roll'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    controller_template_B.roll_cmd = controller_template_B.roll_rot_e;
  } else if (controller_template_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    controller_template_B.roll_cmd = controller_template_B.roll_rot;
  } else {
    controller_template_B.roll_cmd = controller_template_P.roll_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/gravity'
   */
  rtb_Add = controller_template_P.gravity_Value_ch *
    controller_template_B.DataTypeConversion[29];

  /* Switch: '<Root>/Switch1' incorporates:
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    controller_template_B.thrust_cmd = controller_template_B.thrust_comp_k;
  } else if (controller_template_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    controller_template_B.thrust_cmd = controller_template_B.thrust_comp;
  } else {
    /* Switch: '<Root>/Switch3' incorporates:
     *  Constant: '<S3>/- gravity'
     *  Product: '<S3>/Product'
     */
    controller_template_B.thrust_cmd = controller_template_P.gravity_Value_c *
      controller_template_B.DataTypeConversion[29];
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S3>/yaw'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    controller_template_B.yaw_rate_cmd = controller_template_B.cmd_W_h[3];
  } else if (controller_template_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    controller_template_B.yaw_rate_cmd = controller_template_B.cmd_W[3];
  } else {
    controller_template_B.yaw_rate_cmd = controller_template_P.yaw_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<S45>/SwitchControl' incorporates:
   *  Constant: '<S45>/Constant'
   *  Constant: '<S5>/yaw_rate'
   *  Gain: '<S5>/yaw_cmd2yaw'
   */
  if (controller_template_P.Constant_Value_a3 >
      controller_template_P.SwitchControl_Threshold) {
    rtb_UnitDelay2 = controller_template_P.yaw_cmd2yaw_Gain *
      controller_template_B.yaw_rate_cmd;
  } else {
    rtb_UnitDelay2 = controller_template_P.yaw_rate_Value;
  }

  /* End of Switch: '<S45>/SwitchControl' */

  /* Gain: '<S5>/Gain4' */
  rtb_UnitDelay2 *= controller_template_P.Gain4_Gain;

  /* Outport: '<Root>/cmd_out' incorporates:
   *  Constant: '<S5>/pitch_offset'
   *  Constant: '<S5>/roll_offset'
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  Gain: '<S5>/Gain2'
   *  Gain: '<S5>/Gain3'
   *  Gain: '<S5>/pitch_cmd2pitch'
   *  Gain: '<S5>/roll_cmd2roll'
   *  Gain: '<S5>/trhust_cmd2thrust'
   *  Sum: '<S5>/Sum'
   *  Sum: '<S5>/Sum1'
   *  Sum: '<S5>/Sum2'
   *  Sum: '<S5>/Sum3'
   */
  arg_cmd_out[0] = (real32_T)((controller_template_B.pitch_cmd -
    controller_template_P.pitch_offset_Value) *
    controller_template_P.pitch_cmd2pitch_Gain *
    controller_template_P.Gain1_Gain);
  arg_cmd_out[1] = (real32_T)((controller_template_B.roll_cmd -
    controller_template_P.roll_offset_Value) *
    controller_template_P.roll_cmd2roll_Gain * controller_template_P.Gain2_Gain);
  arg_cmd_out[2] = (real32_T)(((controller_template_B.thrust_cmd - rtb_Add) *
    controller_template_P.trhust_cmd2thrust_Gain + rtb_Add) *
    controller_template_P.Gain_Gain_k * controller_template_P.Gain3_Gain);
  arg_cmd_out[3] = (real32_T)rtb_UnitDelay2;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S3>/pitch_bias'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    controller_template_B.pitch_bias = controller_template_B.pitch_bias_rot_i;
  } else if (controller_template_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    controller_template_B.pitch_bias = controller_template_B.pitch_bias_rot;
  } else {
    controller_template_B.pitch_bias = controller_template_P.pitch_bias_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S3>/roll_bias'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    controller_template_B.roll_bias = controller_template_B.roll_bias_rot_d;
  } else if (controller_template_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    controller_template_B.roll_bias = controller_template_B.roll_bias_rot;
  } else {
    controller_template_B.roll_bias = controller_template_P.roll_bias_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S3>/thrust_bias'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    controller_template_B.thrust_bias = controller_template_B.bias_W_b[2];
  } else if (controller_template_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    controller_template_B.thrust_bias = controller_template_B.bias_W[2];
  } else {
    controller_template_B.thrust_bias = controller_template_P.thrust_bias_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S3>/yaw_rate_bias'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    controller_template_B.yaw_rate_bias = controller_template_B.bias_W_b[3];
  } else if (controller_template_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    controller_template_B.yaw_rate_bias = controller_template_B.bias_W[3];
  } else {
    controller_template_B.yaw_rate_bias =
      controller_template_P.yaw_rate_bias_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Update for UnitDelay: '<S46>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S46>/FixPt Constant'
   */
  controller_template_DWork.FixPtUnitDelay2_DSTATE =
    controller_template_P.FixPtConstant_Value_i;

  /* Switch: '<S46>/Reset' */
  if (rtb_MultiportSwitch1 != 0.0) {
    /* Update for UnitDelay: '<S46>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S46>/Initial Condition'
     */
    controller_template_DWork.FixPtUnitDelay1_DSTATE[0] =
      controller_template_P.InitialCondition_Value;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[1] =
      controller_template_P.InitialCondition_Value;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[2] =
      controller_template_P.InitialCondition_Value;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[3] =
      controller_template_P.InitialCondition_Value;
  } else {
    /* Update for UnitDelay: '<S46>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE[0] =
      controller_template_B.pitch_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[1] =
      controller_template_B.roll_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[2] =
      controller_template_B.thrust_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[3] =
      controller_template_B.yaw_rate_bias;
  }

  /* End of Switch: '<S46>/Reset' */

  /* external mode */
  {
    boolean_T rtmStopReq = FALSE;
    rtExtModeOneStep(controller_template_M->extModeInfo, 2, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(controller_template_M, TRUE);
    }
  }

  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, controller_template_M->Timing.taskTime0);
  }

  if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.08s, 0.0s] */
    rtExtModeUpload(1, (((controller_template_M->Timing.clockTick1+
                          controller_template_M->Timing.clockTickH1*
                          4294967296.0)) * 0.08));
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(controller_template_M)!=-1) &&
        !((rtmGetTFinal(controller_template_M)-
           controller_template_M->Timing.taskTime0) >
          controller_template_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(controller_template_M, "Simulation finished");
    }

    if (rtmGetStopRequested(controller_template_M)) {
      rtmSetErrorStatus(controller_template_M, "Simulation finished");
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
  if (!(++controller_template_M->Timing.clockTick0)) {
    ++controller_template_M->Timing.clockTickH0;
  }

  controller_template_M->Timing.taskTime0 =
    controller_template_M->Timing.clockTick0 *
    controller_template_M->Timing.stepSize0 +
    controller_template_M->Timing.clockTickH0 *
    controller_template_M->Timing.stepSize0 * 4294967296.0;
  if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.08s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.08, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    controller_template_M->Timing.clockTick1++;
    if (!controller_template_M->Timing.clockTick1) {
      controller_template_M->Timing.clockTickH1++;
    }
  }

  rate_scheduler();
}

/* Model initialize function */
void FG_traj_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)controller_template_M, 0,
                sizeof(RT_MODEL_controller_template));
  rtmSetTFinal(controller_template_M, -1);
  controller_template_M->Timing.stepSize0 = 0.02;

  /* external mode info */
  controller_template_M->Sizes.checksums[0] = (808419355U);
  controller_template_M->Sizes.checksums[1] = (149421341U);
  controller_template_M->Sizes.checksums[2] = (4087441434U);
  controller_template_M->Sizes.checksums[3] = (3271846147U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[47];
    controller_template_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[2] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = &rtAlwaysEnabled;
    systemRan[18] = &rtAlwaysEnabled;
    systemRan[19] = &rtAlwaysEnabled;
    systemRan[20] = &rtAlwaysEnabled;
    systemRan[21] = &rtAlwaysEnabled;
    systemRan[22] = &rtAlwaysEnabled;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    systemRan[27] = &rtAlwaysEnabled;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    systemRan[32] = &rtAlwaysEnabled;
    systemRan[33] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[37] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[38] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[39] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[40] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[41] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[44] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[45] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[46] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    rteiSetModelMappingInfoPtr(controller_template_M->extModeInfo,
      &controller_template_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(controller_template_M->extModeInfo,
                        controller_template_M->Sizes.checksums);
    rteiSetTPtr(controller_template_M->extModeInfo, rtmGetTPtr
                (controller_template_M));
  }

  /* block I/O */
  (void) memset(((void *) &controller_template_B), 0,
                sizeof(BlockIO_controller_template));

  /* states (dwork) */
  (void) memset((void *)&controller_template_DWork, 0,
                sizeof(D_Work_controller_template));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    controller_template_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  {
    int32_T i;

    /* Start for Enabled SubSystem: '<Root>/FreeFlight Pos Ctrl' */
    /* Start for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* Start for UnitDelay: '<S18>/Unit Delay2' */
    controller_template_B.UnitDelay2 = controller_template_P.UnitDelay2_X0;

    /* Start for UnitDelay: '<S27>/Unit Delay2' */
    controller_template_B.UnitDelay2_o = controller_template_P.UnitDelay2_X0_d;

    /* Start for UnitDelay: '<S32>/Unit Delay2' */
    controller_template_B.UnitDelay2_e = controller_template_P.UnitDelay2_X0_ng;

    /* End of Start for SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* Start for ToFile: '<S12>/To File' */
    {
      char fileName[509] = "hquad_force.mat";
      FILE *fp = (NULL);
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(controller_template_M,
                          "Error creating .mat file hquad_force.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,19,0,"hquad_force")) {
        rtmSetErrorStatus(controller_template_M,
                          "Error writing mat file header to file hquad_force.mat");
        return;
      }

      controller_template_DWork.ToFile_IWORK_g.Count = 0;
      controller_template_DWork.ToFile_IWORK_g.Decimation = -1;
      controller_template_DWork.ToFile_PWORK_p.FilePtr = fp;
    }

    /* Start for ToFile: '<S12>/To File1' */
    {
      char fileName[509] = "hquad_force_bias.mat";
      FILE *fp = (NULL);
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(controller_template_M,
                          "Error creating .mat file hquad_force_bias.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,5,0,"hquad_force_bias")) {
        rtmSetErrorStatus(controller_template_M,
                          "Error writing mat file header to file hquad_force_bias.mat");
        return;
      }

      controller_template_DWork.ToFile1_IWORK_p.Count = 0;
      controller_template_DWork.ToFile1_IWORK_p.Decimation = -1;
      controller_template_DWork.ToFile1_PWORK_i.FilePtr = fp;
    }

    /* InitializeConditions for MATLAB Function: '<S11>/Embedded MATLAB Function' */
    con_EmbeddedMATLABFunction_Init
      (&controller_template_DWork.sf_EmbeddedMATLABFunction);

    /* InitializeConditions for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* InitializeConditions for MATLAB Function: '<S14>/MATLAB Function' */
    controller_template_DWork.sfEvent_fk = CALL_EVENT;
    controller_template_DWork.is_active_c8_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S18>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE =
      controller_template_P.UnitDelay2_X0;

    /* InitializeConditions for MATLAB Function: '<S25>/MATLAB Function' */
    controller__MATLABFunction_Init
      (&controller_template_DWork.sf_MATLABFunction_f);

    /* InitializeConditions for MATLAB Function: '<S18>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_kl = CALL_EVENT;
    controller_template_DWork.is_active_c1_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S20>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_d =
      controller_template_P.UnitDelay2_X0_m;

    /* InitializeConditions for UnitDelay: '<S20>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_jv =
      controller_template_P.UnitDelay_X0;

    /* InitializeConditions for UnitDelay: '<S27>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_l =
      controller_template_P.UnitDelay2_X0_d;

    /* InitializeConditions for MATLAB Function: '<S30>/MATLAB Function' */
    controller__MATLABFunction_Init
      (&controller_template_DWork.sf_MATLABFunction_k);

    /* InitializeConditions for MATLAB Function: '<S27>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_cd = CALL_EVENT;
    controller_template_DWork.is_active_c2_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S28>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_k =
      controller_template_P.UnitDelay2_X0_n;

    /* InitializeConditions for UnitDelay: '<S28>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_f =
      controller_template_P.UnitDelay_X0_f;

    /* InitializeConditions for MATLAB Function: '<S37>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_k0 = CALL_EVENT;
    controller_template_DWork.is_active_c3_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S38>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_b =
      controller_template_P.UnitDelay2_X0_o;

    /* InitializeConditions for UnitDelay: '<S38>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_fw =
      controller_template_P.UnitDelay_X0_i;

    /* InitializeConditions for UnitDelay: '<S32>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_g =
      controller_template_P.UnitDelay2_X0_ng;

    /* InitializeConditions for MATLAB Function: '<S35>/MATLAB Function' */
    controller_template_DWork.sfEvent_l = CALL_EVENT;
    controller_template_DWork.is_active_c6_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S32>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_jv = CALL_EVENT;
    controller_template_DWork.is_active_c4_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S33>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_ga =
      controller_template_P.UnitDelay2_X0_i;

    /* InitializeConditions for UnitDelay: '<S33>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_p =
      controller_template_P.UnitDelay_X0_c;

    /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_a =
      controller_template_P.UnitDelay1_X0;

    /* InitializeConditions for UnitDelay: '<S28>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_ji =
      controller_template_P.UnitDelay1_X0_d;

    /* InitializeConditions for UnitDelay: '<S33>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_c3 =
      controller_template_P.UnitDelay1_X0_j;

    /* InitializeConditions for UnitDelay: '<S38>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_m =
      controller_template_P.UnitDelay1_X0_f;

    /* End of InitializeConditions for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

    /* InitializeConditions for Atomic SubSystem: '<S2>/decoupling and rotation' */
    /* InitializeConditions for MATLAB Function: '<S40>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_c = CALL_EVENT;
    controller_template_DWork.is_active_c1_Hquad_control_LI_l = 0U;

    /* InitializeConditions for MATLAB Function: '<S41>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_j = CALL_EVENT;
    controller_template_DWork.is_active_c4_Hquad_control_LI_d = 0U;

    /* End of InitializeConditions for SubSystem: '<S2>/decoupling and rotation' */
    /* End of Start for SubSystem: '<Root>/FreeFlight Pos Ctrl' */

    /* Start for Enabled SubSystem: '<Root>/pos controller' */
    /* Start for ToFile: '<S51>/To File' */
    {
      char fileName[509] = "hquad_pos_FG.mat";
      FILE *fp = (NULL);
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(controller_template_M,
                          "Error creating .mat file hquad_pos_FG.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,19,0,"hquad_pos_FG")) {
        rtmSetErrorStatus(controller_template_M,
                          "Error writing mat file header to file hquad_pos_FG.mat");
        return;
      }

      controller_template_DWork.ToFile_IWORK.Count = 0;
      controller_template_DWork.ToFile_IWORK.Decimation = -1;
      controller_template_DWork.ToFile_PWORK.FilePtr = fp;
    }

    /* Start for ToFile: '<S51>/To File1' */
    {
      char fileName[509] = "hquad_pos_FG_bias.mat";
      FILE *fp = (NULL);
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(controller_template_M,
                          "Error creating .mat file hquad_pos_FG_bias.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,5,0,"hquad_pos_FG_bias")) {
        rtmSetErrorStatus(controller_template_M,
                          "Error writing mat file header to file hquad_pos_FG_bias.mat");
        return;
      }

      controller_template_DWork.ToFile1_IWORK.Count = 0;
      controller_template_DWork.ToFile1_IWORK.Decimation = -1;
      controller_template_DWork.ToFile1_PWORK.FilePtr = fp;
    }

    /* InitializeConditions for MATLAB Function: '<S50>/Embedded MATLAB Function' */
    con_EmbeddedMATLABFunction_Init
      (&controller_template_DWork.sf_EmbeddedMATLABFunction_o);

    /* InitializeConditions for Atomic SubSystem: '<S7>/MAIN CONTROL LOOP1' */
    /* InitializeConditions for Delay: '<S47>/Integer Delay' */
    controller_template_DWork.IntegerDelay_DSTATE =
      controller_template_P.IntegerDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S47>/Integer Delay1' */
    controller_template_DWork.IntegerDelay1_DSTATE =
      controller_template_P.IntegerDelay1_InitialCondition;

    /* InitializeConditions for Delay: '<S47>/Integer Delay2' */
    controller_template_DWork.IntegerDelay2_DSTATE =
      controller_template_P.IntegerDelay2_InitialCondition;

    /* InitializeConditions for Delay: '<S47>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE =
      controller_template_P.IntegerDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S54>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
           controller_template_P.UnitDelay1_X0_c, sizeof(real_T) << 4U);

    /* InitializeConditions for UnitDelay: '<S62>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
      controller_template_P.FixPtUnitDelay2_X0;

    /* InitializeConditions for UnitDelay: '<S62>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
      controller_template_P.FixPtUnitDelay1_X0;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
      controller_template_P.FixPtUnitDelay1_X0;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
      controller_template_P.FixPtUnitDelay1_X0;

    /* InitializeConditions for MATLAB Function: '<S54>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter);

    /* InitializeConditions for UnitDelay: '<S53>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE[0] =
      controller_template_P.UnitDelay_X0_fc[0];
    controller_template_DWork.UnitDelay_DSTATE[1] =
      controller_template_P.UnitDelay_X0_fc[1];
    controller_template_DWork.UnitDelay_DSTATE[2] =
      controller_template_P.UnitDelay_X0_fc[2];

    /* InitializeConditions for UnitDelay: '<S53>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
           controller_template_P.UnitDelay1_X0_k, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S53>/runFastGradient' */
    controller_runFastGradient_Init
      (&controller_template_DWork.sf_runFastGradient);

    /* InitializeConditions for UnitDelay: '<S56>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
           controller_template_P.UnitDelay1_X0_fk, sizeof(real_T) << 4U);

    /* InitializeConditions for UnitDelay: '<S65>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
      controller_template_P.FixPtUnitDelay2_X0_n;

    /* InitializeConditions for UnitDelay: '<S65>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
      controller_template_P.FixPtUnitDelay1_X0_n;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
      controller_template_P.FixPtUnitDelay1_X0_n;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
      controller_template_P.FixPtUnitDelay1_X0_n;

    /* InitializeConditions for MATLAB Function: '<S56>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter_m);

    /* InitializeConditions for UnitDelay: '<S55>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_j[0] =
      controller_template_P.UnitDelay_X0_ik[0];
    controller_template_DWork.UnitDelay_DSTATE_j[1] =
      controller_template_P.UnitDelay_X0_ik[1];
    controller_template_DWork.UnitDelay_DSTATE_j[2] =
      controller_template_P.UnitDelay_X0_ik[2];

    /* InitializeConditions for UnitDelay: '<S55>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
           controller_template_P.UnitDelay1_X0_jc, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S55>/runFastGradient' */
    controller_runFastGradient_Init
      (&controller_template_DWork.sf_runFastGradient_d);

    /* InitializeConditions for UnitDelay: '<S60>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
           controller_template_P.UnitDelay1_X0_cw, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S71>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
      controller_template_P.FixPtUnitDelay2_X0_d;

    /* InitializeConditions for UnitDelay: '<S71>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
      controller_template_P.FixPtUnitDelay1_X0_c;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
      controller_template_P.FixPtUnitDelay1_X0_c;

    /* InitializeConditions for MATLAB Function: '<S60>/discrete kalman filter' */
    con_discretekalmanfilter_i_Init
      (&controller_template_DWork.sf_discretekalmanfilter_k);

    /* InitializeConditions for UnitDelay: '<S59>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_l[0] =
      controller_template_P.UnitDelay_X0_a[0];
    controller_template_DWork.UnitDelay_DSTATE_l[1] =
      controller_template_P.UnitDelay_X0_a[1];

    /* InitializeConditions for UnitDelay: '<S59>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
           controller_template_P.UnitDelay1_X0_b, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S59>/runFastGradient' */
    controller_template_DWork.sfEvent_k = CALL_EVENT;
    controller_template_DWork.is_active_c8_Hquad_control_LIB_ = 0U;

    /* InitializeConditions for UnitDelay: '<S58>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
           controller_template_P.UnitDelay1_X0_n, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S68>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
      controller_template_P.FixPtUnitDelay2_X0_i;

    /* InitializeConditions for UnitDelay: '<S68>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
      controller_template_P.FixPtUnitDelay1_X0_e;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
      controller_template_P.FixPtUnitDelay1_X0_e;

    /* InitializeConditions for MATLAB Function: '<S58>/discrete kalman filter' */
    con_discretekalmanfilter_i_Init
      (&controller_template_DWork.sf_discretekalmanfilter_n);

    /* InitializeConditions for UnitDelay: '<S57>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      controller_template_DWork.UnitDelay_DSTATE_jz[i] =
        controller_template_P.UnitDelay_X0_fj[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S57>/Unit Delay' */

    /* InitializeConditions for UnitDelay: '<S57>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
           controller_template_P.UnitDelay1_X0_o, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S57>/runFastGradient' */
    controller_template_DWork.sfEvent_n = CALL_EVENT;
    controller_template_DWork.is_active_c9_Hquad_control_LIB_ = 0U;

    /* End of InitializeConditions for SubSystem: '<S7>/MAIN CONTROL LOOP1' */

    /* InitializeConditions for Atomic SubSystem: '<S7>/decoupling and rotation' */
    /* InitializeConditions for MATLAB Function: '<S73>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_f = CALL_EVENT;
    controller_template_DWork.is_active_c1_Hquad_control_LIB_ = 0U;

    /* InitializeConditions for MATLAB Function: '<S74>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent = CALL_EVENT;
    controller_template_DWork.is_active_c4_Hquad_control_LIB_ = 0U;

    /* End of InitializeConditions for SubSystem: '<S7>/decoupling and rotation' */
    /* End of Start for SubSystem: '<Root>/pos controller' */
  }

  /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay2' */
  controller_template_DWork.FixPtUnitDelay2_DSTATE =
    controller_template_P.FixPtUnitDelay2_X0_g;

  /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay1' */
  controller_template_DWork.FixPtUnitDelay1_DSTATE[0] =
    controller_template_P.FixPtUnitDelay1_X0_h;
  controller_template_DWork.FixPtUnitDelay1_DSTATE[1] =
    controller_template_P.FixPtUnitDelay1_X0_h;
  controller_template_DWork.FixPtUnitDelay1_DSTATE[2] =
    controller_template_P.FixPtUnitDelay1_X0_h;
  controller_template_DWork.FixPtUnitDelay1_DSTATE[3] =
    controller_template_P.FixPtUnitDelay1_X0_h;

  /* External mode */
  rtERTExtModeSetTFinal(&rtmGetTFinal(controller_template_M));
  rtExtModeCheckInit(2);

  {
    boolean_T rtmStopReq = FALSE;
    rtExtModeWaitForStartPkt(controller_template_M->extModeInfo, 2, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(controller_template_M, TRUE);
    }
  }

  rtERTExtModeStartMsg();
}

/* Model terminate function */
void controller_template_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<Root>/FreeFlight Pos Ctrl' */

  /* Terminate for ToFile: '<S12>/To File' */
  {
    FILE *fp = (FILE *) controller_template_DWork.ToFile_PWORK_p.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "hquad_force.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(controller_template_M,
                          "Error closing MAT-file hquad_force.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(controller_template_M,
                          "Error reopening MAT-file hquad_force.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 19,
           controller_template_DWork.ToFile_IWORK_g.Count, "hquad_force")) {
        rtmSetErrorStatus(controller_template_M,
                          "Error writing header for hquad_force to MAT-file hquad_force.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(controller_template_M,
                          "Error closing MAT-file hquad_force.mat");
        return;
      }

      controller_template_DWork.ToFile_PWORK_p.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S12>/To File1' */
  {
    FILE *fp = (FILE *) controller_template_DWork.ToFile1_PWORK_i.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "hquad_force_bias.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(controller_template_M,
                          "Error closing MAT-file hquad_force_bias.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(controller_template_M,
                          "Error reopening MAT-file hquad_force_bias.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 5,
           controller_template_DWork.ToFile1_IWORK_p.Count, "hquad_force_bias"))
      {
        rtmSetErrorStatus(controller_template_M,
                          "Error writing header for hquad_force_bias to MAT-file hquad_force_bias.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(controller_template_M,
                          "Error closing MAT-file hquad_force_bias.mat");
        return;
      }

      controller_template_DWork.ToFile1_PWORK_i.FilePtr = (NULL);
    }
  }

  /* End of Terminate for SubSystem: '<Root>/FreeFlight Pos Ctrl' */

  /* Terminate for Enabled SubSystem: '<Root>/pos controller' */

  /* Terminate for ToFile: '<S51>/To File' */
  {
    FILE *fp = (FILE *) controller_template_DWork.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "hquad_pos_FG.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(controller_template_M,
                          "Error closing MAT-file hquad_pos_FG.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(controller_template_M,
                          "Error reopening MAT-file hquad_pos_FG.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 19,
           controller_template_DWork.ToFile_IWORK.Count, "hquad_pos_FG")) {
        rtmSetErrorStatus(controller_template_M,
                          "Error writing header for hquad_pos_FG to MAT-file hquad_pos_FG.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(controller_template_M,
                          "Error closing MAT-file hquad_pos_FG.mat");
        return;
      }

      controller_template_DWork.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S51>/To File1' */
  {
    FILE *fp = (FILE *) controller_template_DWork.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "hquad_pos_FG_bias.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(controller_template_M,
                          "Error closing MAT-file hquad_pos_FG_bias.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(controller_template_M,
                          "Error reopening MAT-file hquad_pos_FG_bias.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 5,
           controller_template_DWork.ToFile1_IWORK.Count, "hquad_pos_FG_bias"))
      {
        rtmSetErrorStatus(controller_template_M,
                          "Error writing header for hquad_pos_FG_bias to MAT-file hquad_pos_FG_bias.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(controller_template_M,
                          "Error closing MAT-file hquad_pos_FG_bias.mat");
        return;
      }

      controller_template_DWork.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* End of Terminate for SubSystem: '<Root>/pos controller' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
