/*
 * File: controller_template.cpp
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.492
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Aug  6 2011)
 * C/C++ source code generated on : Fri May 17 21:42:55 2013
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
static void controller_template_round_c(real_T x[4]);
static void controller_template_mrdivide_c(const real_T A[4], real_T B, real_T
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
 *    '<S19>/discrete kalman filter'
 *    '<S67>/discrete kalman filter'
 *    '<S69>/discrete kalman filter'
 */
void contr_discretekalmanfilter_Init(rtDW_discretekalmanfilter_contr *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c5_Hquad_control_LIB_ = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S19>/discrete kalman filter'
 *    '<S67>/discrete kalman filter'
 *    '<S69>/discrete kalman filter'
 */
void controller_discretekalmanfilter(real_T rtu_y, real_T rtu_y_e, const real_T
  rtu_state[2], real_T rtu_state_g, const real_T rtu_A[9], const real_T rtu_B[3],
  const real_T rtu_C[6], const real_T rtu_Q[9], const real_T rtu_R[4], real_T
  rtu_u, const real_T rtu_P[9], rtB_discretekalmanfilter_contro *localB,
  rtDW_discretekalmanfilter_contr *localDW)
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

  /* MATLAB Function 'yaw states estimator bias/discrete kalman filter': '<S45>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S45>:1:10' */
  for (i = 0; i < 3; i++) {
    /* SignalConversion: '<S45>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = ((rtu_A[i + 3] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
            6] * rtu_state_g) + rtu_B[i] * rtu_u;
  }

  /* '<S45>:1:11' */
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
  /* '<S45>:1:14' */
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

  /* '<S45>:1:15' */
  /* '<S45>:1:16' */
  for (i = 0; i < 9; i++) {
    I[i] = 0;
  }

  I[0] = 1;
  I[4] = 1;
  I[8] = 1;
  for (i = 0; i < 2; i++) {
    tmp[i] = rtu_C[i + 4] * x[2] + (rtu_C[i + 2] * x[1] + rtu_C[i] * x[0]);
  }

  /* SignalConversion: '<S45>/TmpSignal ConversionAt SFunction Inport8' */
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

/*
 * Initial conditions for atomic system:
 *    '<S13>/Embedded MATLAB Function'
 *    '<S59>/Embedded MATLAB Function'
 */
void con_EmbeddedMATLABFunction_Init(rtDW_EmbeddedMATLABFunction_con *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c26_Hquad_control_LIB = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S13>/Embedded MATLAB Function'
 *    '<S59>/Embedded MATLAB Function'
 */
void controll_EmbeddedMATLABFunction(real_T rtu_roll, real_T rtu_pitch, real_T
  rtu_pitch_bias, real_T rtu_roll_bias, real_T rtu_yaw,
  rtB_EmbeddedMATLABFunction_cont *localB, rtDW_EmbeddedMATLABFunction_con
  *localDW)
{
  real_T sin_yaw;
  real_T cos_yaw;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'rotate to world frame/Embedded MATLAB Function': '<S53>:1' */
  /* '<S53>:1:5' */
  sin_yaw = sin(rtu_yaw);

  /* '<S53>:1:6' */
  cos_yaw = cos(rtu_yaw);

  /* '<S53>:1:8' */
  /* '<S53>:1:10' */
  /* '<S53>:1:11' */
  localB->pitch_rot = cos_yaw * rtu_pitch + sin_yaw * rtu_roll;

  /* '<S53>:1:12' */
  localB->roll_rot = -sin_yaw * rtu_pitch + cos_yaw * rtu_roll;

  /* '<S53>:1:14' */
  /* '<S53>:1:15' */
  localB->pitch_bias_rot = cos_yaw * rtu_pitch_bias + sin_yaw * rtu_roll_bias;

  /* '<S53>:1:16' */
  localB->roll_bias_rot = -sin_yaw * rtu_pitch_bias + cos_yaw * rtu_roll_bias;
}

/*
 * Initial conditions for atomic system:
 *    '<S62>/runFastGradient'
 *    '<S64>/runFastGradient'
 */
void controller_runFastGradient_Init(rtDW_runFastGradient_controller *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c6_Hquad_control_LIB_ = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S62>/runFastGradient'
 *    '<S64>/runFastGradient'
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

  /* MATLAB Function 'x controller MPC FG  /runFastGradient': '<S70>:1' */
  /*  ugly, but simulink needs fix output sizes for vectors */
  /*  number of outputs u */
  /*  number of delay steps */
  /*  prediction horizon */
  /*  predict non-delayed state */
  /* '<S70>:1:14' */
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
  /* '<S70>:1:21' */
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

  /* '<S70>:1:22' */
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
  /* '<S70>:1:25' */
  /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
  /*  so don't forget to backtransform after termination: */
  /* '<S70>:1:32' */
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
  /* '<S70>:1:38' */
  /*  set new initial guess */
  /* '<S70>:1:42' */
  /* '<S70>:1:44' */
  localB->u_opt = U_star[0];
  localB->J_star = ((y[0] * x_predicted_idx + y[1] * x_predicted_idx_0) + y[2] *
                    x_predicted_idx_1) + (L_inv + d_y);
  localB->u_buff_out[0] = rtu_u_buff[1];
  localB->u_buff_out[1] = rtu_u_buff[2];
  localB->u_buff_out[2] = U_star[0];
  memcpy((void *)(&localB->V_init_out[0]), (void *)&V_i[1], 29U * sizeof(real_T));
  localB->V_init_out[29] = 0.0;
}

/* Function for MATLAB Function: '<S63>/discrete kalman filter' */
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
 *    '<S63>/discrete kalman filter'
 *    '<S65>/discrete kalman filter'
 */
void con_discretekalmanfilter_k_Init(rtDW_discretekalmanfilter_con_c *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c11_Hquad_control_LIB = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S63>/discrete kalman filter'
 *    '<S65>/discrete kalman filter'
 */
void controll_discretekalmanfilter_b(real_T rtu_y, real_T rtu_y_o, real_T
  rtu_y_h, const real_T rtu_state[3], real_T rtu_state_m, const real_T rtu_A[16],
  const real_T rtu_B[4], const real_T rtu_C[12], const real_T rtu_Q[16], const
  real_T rtu_R[9], real_T rtu_u, const real_T rtu_P[16],
  rtB_discretekalmanfilter_cont_h *localB, rtDW_discretekalmanfilter_con_c
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

  /* MATLAB Function 'x states estimator bias/discrete kalman filter': '<S72>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S72>:1:10' */
  for (i = 0; i < 4; i++) {
    /* SignalConversion: '<S72>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = (((rtu_A[i + 4] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
             8] * rtu_state[2]) + rtu_A[i + 12] * rtu_state_m) + rtu_B[i] *
      rtu_u;
  }

  /* '<S72>:1:11' */
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
  /* '<S72>:1:14' */
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

  /* '<S72>:1:15' */
  /* '<S72>:1:16' */
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

  /* SignalConversion: '<S72>/TmpSignal ConversionAt SFunction Inport8' */
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

/* Function for MATLAB Function: '<S21>/Ctrl_Xdir' */
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

/* Function for MATLAB Function: '<S21>/Ctrl_Xdir' */
static void controller_template_mrdivide(const real_T A[4], real_T B, real_T y[4])
{
  y[0] = A[0] / B;
  y[1] = A[1] / B;
  y[2] = A[2] / B;
  y[3] = A[3] / B;
}

/* Function for MATLAB Function: '<S30>/Ctrl_Xdir' */
static void controller_template_round_c(real_T x[4])
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

/* Function for MATLAB Function: '<S30>/Ctrl_Xdir' */
static void controller_template_mrdivide_c(const real_T A[4], real_T B, real_T
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
  real_T rtb_TmpSignalConversionAtToFi_p[4];
  real_T rtb_IntegerDelay3_c;
  real_T rtb_UnitDelay1_d[9];
  real_T rtb_Init_jd[2];
  real_T rtb_bias_W[4];
  real_T rtb_TmpSignalConversionAtToFi_f[18];
  real_T rtb_TmpSignalConversionAtToFi_a[18];
  real_T X[4];
  int32_T flag_oob;
  real_T tolerance;
  int32_T minreg;
  real_T abspos;
  int32_T isinside;
  int32_T ireg;
  int32_T k;
  int32_T exitg;
  real_T Hi[400];
  real_T Ki[100];
  real_T Hi_0[200];
  real_T Hi_1[100];
  real_T LL_PP_ref[30];
  real_T MM_ref;
  real_T U_star[30];
  real_T V_i[30];
  real_T V_ip[30];
  real_T b_y[30];
  real_T rtb_MultiportSwitch1;
  real_T rtb_MultiportSwitch2;
  real_T rtb_Product_l;
  real_T rtb_Saturation_n;
  real_T rtb_Add;
  real_T rtb_pitch_cmd_b;
  real_T rtb_roll_cmd_c;
  real_T yaw_rate_cmd_g;
  real_T roll_cmd_f;
  int32_T i;
  real_T X_0[4];
  real_T tmp[16];
  real_T tmp_0[8];
  real_T tmp_1[4];
  real_T temp[30];
  real_T tmp_2[30];
  real_T tmp_3[2];
  real_T temp_idx;
  real_T temp_idx_0;
  real_T u;

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

  /* MultiPortSwitch: '<S6>/Multiport Switch1' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   */
  if ((int32_T)controller_template_B.DataTypeConversion[20] == 10) {
    rtb_MultiportSwitch1 = controller_template_P.Constant1_Value_mr;
  } else {
    rtb_MultiportSwitch1 = controller_template_P.Constant2_Value_a;
  }

  /* End of MultiPortSwitch: '<S6>/Multiport Switch1' */

  /* Switch: '<S55>/Init' incorporates:
   *  Constant: '<S55>/Initial Condition'
   *  Logic: '<S55>/FixPt Logical Operator'
   *  UnitDelay: '<S55>/FixPt Unit Delay1'
   *  UnitDelay: '<S55>/FixPt Unit Delay2'
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

  /* End of Switch: '<S55>/Init' */
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

  /* MultiPortSwitch: '<S6>/Multiport Switch2' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   */
  if ((int32_T)controller_template_B.DataTypeConversion[20] == 4) {
    rtb_MultiportSwitch2 = controller_template_P.Constant1_Value_mr;
  } else {
    rtb_MultiportSwitch2 = controller_template_P.Constant2_Value_a;
  }

  /* End of MultiPortSwitch: '<S6>/Multiport Switch2' */

  /* Switch: '<S5>/SwitchControl' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S5>/Constant'
   */
  if (controller_template_P.Constant_Value_he >
      controller_template_P.SwitchControl_Threshold) {
    u = controller_template_P.Constant_Value_p;
  } else {
    u = rtb_MultiportSwitch2;
  }

  /* End of Switch: '<S5>/SwitchControl' */

  /* Outputs for Enabled SubSystem: '<Root>/FreeFlight Pos Ctrl' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (u > 0.0) {
    if (!controller_template_DWork.FreeFlightPosCtrl_MODE) {
      /* InitializeConditions for MATLAB Function: '<S13>/Embedded MATLAB Function' */
      con_EmbeddedMATLABFunction_Init
        (&controller_template_DWork.sf_EmbeddedMATLABFunction);

      /* InitializeConditions for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
      /* InitializeConditions for Delay: '<S10>/Integer Delay3' */
      controller_template_DWork.IntegerDelay3_DSTATE_k =
        controller_template_P.IntegerDelay3_InitialCondition;

      /* InitializeConditions for UnitDelay: '<S19>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_bg, (void *)
             controller_template_P.UnitDelay1_X0, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S44>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
        controller_template_P.FixPtUnitDelay2_X0;

      /* InitializeConditions for UnitDelay: '<S44>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0] =
        controller_template_P.FixPtUnitDelay1_X0;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1] =
        controller_template_P.FixPtUnitDelay1_X0;

      /* InitializeConditions for MATLAB Function: '<S19>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter);

      /* InitializeConditions for MATLAB Function: '<S16>/MATLAB Function' */
      controller_template_DWork.sfEvent_fk = CALL_EVENT;
      controller_template_DWork.is_active_c8_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S21>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE =
        controller_template_P.UnitDelay2_X0;

      /* InitializeConditions for MATLAB Function: '<S28>/MATLAB Function' */
      controller_template_DWork.sfEvent_cm = CALL_EVENT;
      controller_template_DWork.is_active_c7_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S21>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_kl = CALL_EVENT;
      controller_template_DWork.is_active_c1_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S23>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_d =
        controller_template_P.UnitDelay2_X0_m;

      /* InitializeConditions for UnitDelay: '<S23>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_jv =
        controller_template_P.UnitDelay_X0;

      /* InitializeConditions for UnitDelay: '<S30>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_l =
        controller_template_P.UnitDelay2_X0_d;

      /* InitializeConditions for MATLAB Function: '<S35>/MATLAB Function' */
      controller_template_DWork.sfEvent_i = CALL_EVENT;
      controller_template_DWork.is_active_c5_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S30>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_cd = CALL_EVENT;
      controller_template_DWork.is_active_c2_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S31>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_k =
        controller_template_P.UnitDelay2_X0_n;

      /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_f =
        controller_template_P.UnitDelay_X0_f;

      /* InitializeConditions for MATLAB Function: '<S46>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_k0 = CALL_EVENT;
      controller_template_DWork.is_active_c3_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S47>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_b =
        controller_template_P.UnitDelay2_X0_o;

      /* InitializeConditions for UnitDelay: '<S47>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_fw =
        controller_template_P.UnitDelay_X0_i;

      /* InitializeConditions for UnitDelay: '<S37>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_g =
        controller_template_P.UnitDelay2_X0_ng;

      /* InitializeConditions for MATLAB Function: '<S42>/MATLAB Function' */
      controller_template_DWork.sfEvent_l = CALL_EVENT;
      controller_template_DWork.is_active_c6_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S37>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_jv = CALL_EVENT;
      controller_template_DWork.is_active_c4_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S38>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_ga =
        controller_template_P.UnitDelay2_X0_i;

      /* InitializeConditions for UnitDelay: '<S38>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_p =
        controller_template_P.UnitDelay_X0_c;

      /* InitializeConditions for UnitDelay: '<S23>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_a =
        controller_template_P.UnitDelay1_X0_i;

      /* InitializeConditions for UnitDelay: '<S31>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_ji =
        controller_template_P.UnitDelay1_X0_d;

      /* InitializeConditions for UnitDelay: '<S38>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_c3 =
        controller_template_P.UnitDelay1_X0_j;

      /* InitializeConditions for UnitDelay: '<S47>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_m =
        controller_template_P.UnitDelay1_X0_f;

      /* End of InitializeConditions for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

      /* InitializeConditions for Atomic SubSystem: '<S2>/decoupling and rotation' */
      /* InitializeConditions for MATLAB Function: '<S49>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_c = CALL_EVENT;
      controller_template_DWork.is_active_c9_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S50>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_j = CALL_EVENT;
      controller_template_DWork.is_active_c10_controller_templa = 0U;

      /* End of InitializeConditions for SubSystem: '<S2>/decoupling and rotation' */
      controller_template_DWork.FreeFlightPosCtrl_MODE = TRUE;
    }

    /* MATLAB Function: '<S13>/Embedded MATLAB Function' */
    controll_EmbeddedMATLABFunction(controller_template_B.DataTypeConversion[6],
      controller_template_B.DataTypeConversion[7], rtb_Init[0], rtb_Init[1],
      controller_template_B.DataTypeConversion[8],
      &controller_template_B.sf_EmbeddedMATLABFunction,
      &controller_template_DWork.sf_EmbeddedMATLABFunction);

    /* Outputs for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* Delay: '<S10>/Integer Delay3' */
    rtb_IntegerDelay3_c = controller_template_DWork.IntegerDelay3_DSTATE_k;

    /* UnitDelay: '<S19>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_d[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_bg, 9U * sizeof(real_T));

    /* Switch: '<S44>/Init' incorporates:
     *  UnitDelay: '<S44>/FixPt Unit Delay1'
     *  UnitDelay: '<S44>/FixPt Unit Delay2'
     */
    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_g != 0) {
      rtb_Init_jd[0] = controller_template_B.DataTypeConversion[8];
    } else {
      rtb_Init_jd[0] = controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_g != 0) {
      rtb_Init_jd[1] = controller_template_B.DataTypeConversion[11];
    } else {
      rtb_Init_jd[1] = controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1];
    }

    /* End of Switch: '<S44>/Init' */

    /* Inport: '<S10>/bias_W' */
    rtb_bias_W[0] =
      controller_template_B.sf_EmbeddedMATLABFunction.pitch_bias_rot;
    rtb_bias_W[1] =
      controller_template_B.sf_EmbeddedMATLABFunction.roll_bias_rot;
    rtb_bias_W[2] = rtb_Init[2];
    rtb_bias_W[3] = rtb_Init[3];

    /* MATLAB Function: '<S19>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.DataTypeConversion[8],
      controller_template_B.DataTypeConversion[11], rtb_Init_jd, rtb_bias_W[3],
      controller_template_P.A_Value, controller_template_P.B_Value,
      controller_template_P.C_Value, controller_template_P.Q_Value,
      controller_template_P.R_Value, rtb_IntegerDelay3_c, rtb_UnitDelay1_d,
      &controller_template_B.sf_discretekalmanfilter,
      &controller_template_DWork.sf_discretekalmanfilter);

    /* Saturate: '<S19>/Saturation' */
    controller_template_B.Saturation =
      controller_template_B.sf_discretekalmanfilter.state_est[2] >=
      controller_template_P.Saturation_UpperSat ?
      controller_template_P.Saturation_UpperSat :
      controller_template_B.sf_discretekalmanfilter.state_est[2] <=
      controller_template_P.Saturation_LowerSat ?
      controller_template_P.Saturation_LowerSat :
      controller_template_B.sf_discretekalmanfilter.state_est[2];

    /* Product: '<S10>/Product' incorporates:
     *  Constant: '<S10>/gravity'
     */
    rtb_Product_l = controller_template_P.gravity_Value *
      controller_template_B.DataTypeConversion[29];

    /* Sum: '<S16>/Add' incorporates:
     *  Constant: '<S16>/Constant'
     *  Gain: '<S24>/Slider Gain'
     *  Gain: '<S25>/Slider Gain'
     *  Sum: '<S16>/Sum'
     */
    rtb_Add = controller_template_B.DataTypeConversion[0] -
      (controller_template_P.SliderGain_Gain * controller_template_B.X_ref_x[0]
       + controller_template_P.SliderGain_Gain_e *
       controller_template_P.Constant_Value_f);

    /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
     *  Constant: '<S16>/Constant1'
     *  Gain: '<S26>/Slider Gain'
     */
    controller_template_DWork.sfEvent_fk = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /MATLAB Function': '<S22>:1' */
    if (rtb_Add >= controller_template_P.SliderGain_Gain_f *
        controller_template_P.Constant1_Value_g) {
      /* '<S22>:1:3' */
      /* '<S22>:1:4' */
      controller_template_B.y_n = 0.0;
    } else {
      /* '<S22>:1:6' */
      controller_template_B.y_n = rtb_Add;
    }

    /* End of MATLAB Function: '<S16>/MATLAB Function' */

    /* Saturate: '<S16>/Saturation3' */
    controller_template_B.Saturation3 = controller_template_B.y_n >=
      controller_template_P.Saturation3_UpperSat ?
      controller_template_P.Saturation3_UpperSat : controller_template_B.y_n <=
      controller_template_P.Saturation3_LowerSat ?
      controller_template_P.Saturation3_LowerSat : controller_template_B.y_n;

    /* RateTransition: '<S21>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Saturate: '<S16>/Saturation' */
      controller_template_B.RateTransition[0] =
        controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot >=
        controller_template_P.Saturation_UpperSat_i ?
        controller_template_P.Saturation_UpperSat_i :
        controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot <=
        controller_template_P.Saturation_LowerSat_j ?
        controller_template_P.Saturation_LowerSat_j :
        controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot;

      /* Saturate: '<S16>/Saturation1' */
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

      /* Saturate: '<S16>/Saturation2' */
      controller_template_B.RateTransition[3] =
        controller_template_B.DataTypeConversion[3] >=
        controller_template_P.Saturation2_UpperSat ?
        controller_template_P.Saturation2_UpperSat :
        controller_template_B.DataTypeConversion[3] <=
        controller_template_P.Saturation2_LowerSat ?
        controller_template_P.Saturation2_LowerSat :
        controller_template_B.DataTypeConversion[3];

      /* UnitDelay: '<S21>/Unit Delay2' */
      controller_template_B.UnitDelay2 =
        controller_template_DWork.UnitDelay2_DSTATE;
    }

    /* End of RateTransition: '<S21>/Rate Transition' */

    /* MATLAB Function: '<S28>/MATLAB Function' */
    controller_template_DWork.sfEvent_cm = CALL_EVENT;

    /* Switch: '<S28>/Switch' incorporates:
     *  Constant: '<S28>/Constant'
     *  Constant: '<S28>/Constant2'
     *  MATLAB Function: '<S28>/MATLAB Function'
     */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/PitchPropagate/MATLAB Function': '<S29>:1' */
    /* '<S29>:1:4' */
    if (controller_template_B.RateTransition[2] != 0.0) {
      for (k = 0; k < 4; k++) {
        tmp[k << 2] = controller_template_P.Constant_Value[(k << 2)];
        tmp[1 + (k << 2)] = controller_template_P.Constant_Value[(k << 2) + 1];
        tmp[2 + (k << 2)] = controller_template_P.Constant_Value[(k << 2) + 2];
        tmp[3 + (k << 2)] = controller_template_P.Constant_Value[(k << 2) + 3];
      }
    } else {
      for (k = 0; k < 4; k++) {
        tmp[k << 2] = controller_template_P.Constant2_Value[(k << 2)];
        tmp[1 + (k << 2)] = controller_template_P.Constant2_Value[(k << 2) + 1];
        tmp[2 + (k << 2)] = controller_template_P.Constant2_Value[(k << 2) + 2];
        tmp[3 + (k << 2)] = controller_template_P.Constant2_Value[(k << 2) + 3];
      }
    }

    /* End of Switch: '<S28>/Switch' */

    /* Switch: '<S28>/Switch1' incorporates:
     *  Constant: '<S28>/Constant1'
     *  Constant: '<S28>/Constant3'
     *  MATLAB Function: '<S28>/MATLAB Function'
     */
    if (controller_template_B.RateTransition[2] != 0.0) {
      for (k = 0; k < 2; k++) {
        tmp_0[k << 2] = controller_template_P.Constant1_Value[(k << 2)];
        tmp_0[1 + (k << 2)] = controller_template_P.Constant1_Value[(k << 2) + 1];
        tmp_0[2 + (k << 2)] = controller_template_P.Constant1_Value[(k << 2) + 2];
        tmp_0[3 + (k << 2)] = controller_template_P.Constant1_Value[(k << 2) + 3];
      }
    } else {
      for (k = 0; k < 2; k++) {
        tmp_0[k << 2] = controller_template_P.Constant3_Value[(k << 2)];
        tmp_0[1 + (k << 2)] = controller_template_P.Constant3_Value[(k << 2) + 1];
        tmp_0[2 + (k << 2)] = controller_template_P.Constant3_Value[(k << 2) + 2];
        tmp_0[3 + (k << 2)] = controller_template_P.Constant3_Value[(k << 2) + 3];
      }
    }

    /* End of Switch: '<S28>/Switch1' */

    /* MATLAB Function: '<S28>/MATLAB Function' */
    for (k = 0; k < 4; k++) {
      u = tmp[k + 12] * controller_template_B.RateTransition[3] + (tmp[k + 8] *
        controller_template_B.RateTransition[2] + (tmp[k + 4] *
        controller_template_B.RateTransition[1] + tmp[k] *
        controller_template_B.RateTransition[0]));
      X_0[k] = u;
    }

    for (k = 0; k < 4; k++) {
      tmp_1[k] = tmp_0[k + 4] * 0.0 + tmp_0[k] *
        controller_template_B.UnitDelay2;
    }

    controller_template_B.y_d[0] = X_0[0] + tmp_1[0];
    controller_template_B.y_d[1] = X_0[1] + tmp_1[1];
    controller_template_B.y_d[2] = X_0[2] + tmp_1[2];
    controller_template_B.y_d[3] = X_0[3] + tmp_1[3];

    /* MATLAB Function: '<S21>/Ctrl_Xdir' incorporates:
     *  Constant: '<S21>/Constant'
     *  Constant: '<S21>/Constant1'
     *  Constant: '<S21>/Constant2'
     *  Constant: '<S21>/Constant3'
     *  Constant: '<S21>/Constant4'
     *  Saturate: '<S28>/Saturation'
     *  Saturate: '<S28>/Saturation1'
     *  Saturate: '<S28>/Saturation2'
     *  Saturate: '<S28>/Saturation3'
     */
    controller_template_DWork.sfEvent_kl = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/Ctrl_Xdir': '<S27>:1' */
    /* '<S27>:1:3' */
    tolerance = 1.0;

    /* '<S27>:1:5' */
    /* '<S27>:1:6' */
    minreg = -1;

    /* '<S27>:1:7' */
    X[0] = (controller_template_B.y_d[0] >=
            controller_template_P.Saturation_UpperSat_a ?
            controller_template_P.Saturation_UpperSat_a :
            controller_template_B.y_d[0] <=
            controller_template_P.Saturation_LowerSat_e ?
            controller_template_P.Saturation_LowerSat_e :
            controller_template_B.y_d[0]) * 10000.0;
    X[1] = (controller_template_B.y_d[1] >=
            controller_template_P.Saturation1_UpperSat_n ?
            controller_template_P.Saturation1_UpperSat_n :
            controller_template_B.y_d[1] <=
            controller_template_P.Saturation1_LowerSat_c ?
            controller_template_P.Saturation1_LowerSat_c :
            controller_template_B.y_d[1]) * 10000.0;
    X[2] = (controller_template_B.y_d[2] >=
            controller_template_P.Saturation3_UpperSat_i ?
            controller_template_P.Saturation3_UpperSat_i :
            controller_template_B.y_d[2] <=
            controller_template_P.Saturation3_LowerSat_k ?
            controller_template_P.Saturation3_LowerSat_k :
            controller_template_B.y_d[2]) * 10000.0;
    X[3] = (controller_template_B.y_d[3] >=
            controller_template_P.Saturation2_UpperSat_g ?
            controller_template_P.Saturation2_UpperSat_g :
            controller_template_B.y_d[3] <=
            controller_template_P.Saturation2_LowerSat_o ?
            controller_template_P.Saturation2_LowerSat_o :
            controller_template_B.y_d[3]) * 10000.0;
    controller_template_round(X);
    X_0[0] = X[0];
    X_0[1] = X[1];
    X_0[2] = X[2];
    X_0[3] = X[3];
    controller_template_mrdivide(X_0, 10000.0, X);

    /* '<S27>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S27>:1:12' */
    memset((void *)(&controller_template_B.Hi[0]), 0, 4000U * sizeof(real_T));

    /* '<S27>:1:13' */
    memset((void *)(&controller_template_B.Ki[0]), 0, 1000U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S27>:1:16' */
    abspos = 1.0;

    /* '<S27>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 358) {
        /* '<S27>:1:17' */
        /* '<S27>:1:18' */
        rtb_Add = 0.0;

        /* '<S27>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S27>:1:23' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value[ireg] -
             1; i++) {
          /* '<S27>:1:23' */
          /* '<S27>:1:24' */
          /* '<S27>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_o[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S27>:1:24' */
          /* '<S27>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)i) + 999] =
            controller_template_P.Constant_Value_o[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 3158];

          /* '<S27>:1:24' */
          /* '<S27>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)i) + 1999] =
            controller_template_P.Constant_Value_o[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 6317];

          /* '<S27>:1:24' */
          /* '<S27>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)i) + 2999] =
            controller_template_P.Constant_Value_o[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 9476];

          /* '<S27>:1:24' */
          /* '<S27>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S27>:1:30' */
        for (k = 0; k <= (int32_T)controller_template_P.Constant4_Value[ireg] -
             1; k++) {
          /* '<S27>:1:30' */
          /* '<S27>:1:31' */
          controller_template_B.Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_d[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S27>:1:30' */
        }

        /* '<S27>:1:33' */
        abspos += controller_template_P.Constant4_Value[ireg];

        /* '<S27>:1:35' */
        /* '<S27>:1:36' */
        /* '<S27>:1:38' */
        /* '<S27>:1:40' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value[ireg] -
             1; i++) {
          /* '<S27>:1:40' */
          /* '<S27>:1:41' */
          MM_ref = ((controller_template_B.Hi[(int32_T)(1.0 + (real_T)i) - 1] *
                     X[0] + controller_template_B.Hi[(int32_T)(1.0 + (real_T)i)
                     + 999] * X[1]) + controller_template_B.Hi[(int32_T)(1.0 +
                     (real_T)i) + 1999] * X[2]) + controller_template_B.Hi
            [(int32_T)(1.0 + (real_T)i) + 2999] * X[3];
          if (MM_ref - controller_template_B.Ki[(int32_T)(1.0 + (real_T)i) - 1] >
              1.0E-8) {
            /* '<S27>:1:42' */
            /* '<S27>:1:43' */
            isinside = 0;

            /* '<S27>:1:44' */
            rtb_Add += MM_ref - controller_template_B.Ki[(int32_T)(1.0 + (real_T)
              i) - 1];
          }

          /* '<S27>:1:40' */
        }

        if (rtb_Add < tolerance) {
          /* '<S27>:1:48' */
          /* '<S27>:1:49' */
          tolerance = rtb_Add;

          /* '<S27>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S27>:1:53' */
          /* '<S27>:1:54' */
          yaw_rate_cmd_g = (((controller_template_P.Constant2_Value_i[ireg + 358]
                              * X[1] +
                              controller_template_P.Constant2_Value_i[ireg] * X
                              [0]) +
                             controller_template_P.Constant2_Value_i[ireg + 716]
                             * X[2]) +
                            controller_template_P.Constant2_Value_i[ireg + 1074]
                            * X[3]) +
            controller_template_P.Constant3_Value_o[ireg];
          exitg = 1;
        } else {
          /* '<S27>:1:17' */
          ireg++;
        }
      } else {
        /* '<S27>:1:58' */
        /* '<S27>:1:59' */
        /* '<S27>:1:60' */
        yaw_rate_cmd_g = (((controller_template_P.Constant2_Value_i[minreg + 358]
                            * X[1] +
                            controller_template_P.Constant2_Value_i[minreg] * X
                            [0]) +
                           controller_template_P.Constant2_Value_i[minreg + 716]
                           * X[2]) +
                          controller_template_P.Constant2_Value_i[minreg + 1074]
                          * X[3]) +
          controller_template_P.Constant3_Value_o[minreg];

        /* '<S27>:1:61' */
        flag_oob = 1;
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_i = yaw_rate_cmd_g;
    controller_template_B.flag_oob_b = (real_T)flag_oob;

    /* End of MATLAB Function: '<S21>/Ctrl_Xdir' */

    /* Gain: '<S23>/Gain' incorporates:
     *  Saturate: '<S16>/Saturation4'
     *  Sum: '<S23>/Sum'
     *  Sum: '<S23>/Sum1'
     *  UnitDelay: '<S23>/Unit Delay'
     *  UnitDelay: '<S23>/Unit Delay2'
     */
    controller_template_B.Gain = ((controller_template_B.U_i >=
      controller_template_P.Saturation4_UpperSat ?
      controller_template_P.Saturation4_UpperSat : controller_template_B.U_i <=
      controller_template_P.Saturation4_LowerSat ?
      controller_template_P.Saturation4_LowerSat : controller_template_B.U_i) +
                                  (controller_template_DWork.UnitDelay2_DSTATE_d
      + controller_template_DWork.UnitDelay_DSTATE_jv)) *
      controller_template_P.Gain_Gain;

    /* Sum: '<S10>/Sum' */
    rtb_pitch_cmd_b = controller_template_B.Gain - rtb_bias_W[0];

    /* Sum: '<S17>/Add' incorporates:
     *  Constant: '<S17>/Constant'
     *  Gain: '<S32>/Slider Gain'
     *  Gain: '<S33>/Slider Gain'
     *  Sum: '<S17>/Sum'
     */
    u = controller_template_B.DataTypeConversion[1] -
      (controller_template_P.SliderGain_Gain_g * controller_template_B.X_ref_y[0]
       + controller_template_P.SliderGain_Gain_b *
       controller_template_P.Constant_Value_g);

    /* Saturate: '<S17>/Saturation3' */
    controller_template_B.Saturation3_e = u >=
      controller_template_P.Saturation3_UpperSat_n ?
      controller_template_P.Saturation3_UpperSat_n : u <=
      controller_template_P.Saturation3_LowerSat_c ?
      controller_template_P.Saturation3_LowerSat_c : u;

    /* RateTransition: '<S30>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Saturate: '<S17>/Saturation' */
      controller_template_B.RateTransition_i[0] =
        controller_template_B.sf_EmbeddedMATLABFunction.roll_rot >=
        controller_template_P.Saturation_UpperSat_h ?
        controller_template_P.Saturation_UpperSat_h :
        controller_template_B.sf_EmbeddedMATLABFunction.roll_rot <=
        controller_template_P.Saturation_LowerSat_d ?
        controller_template_P.Saturation_LowerSat_d :
        controller_template_B.sf_EmbeddedMATLABFunction.roll_rot;

      /* Saturate: '<S17>/Saturation1' */
      controller_template_B.RateTransition_i[1] =
        controller_template_B.DataTypeConversion[9] >=
        controller_template_P.Saturation1_UpperSat_o ?
        controller_template_P.Saturation1_UpperSat_o :
        controller_template_B.DataTypeConversion[9] <=
        controller_template_P.Saturation1_LowerSat_cl ?
        controller_template_P.Saturation1_LowerSat_cl :
        controller_template_B.DataTypeConversion[9];
      controller_template_B.RateTransition_i[2] =
        controller_template_B.Saturation3_e;

      /* Saturate: '<S17>/Saturation2' */
      controller_template_B.RateTransition_i[3] =
        controller_template_B.DataTypeConversion[4] >=
        controller_template_P.Saturation2_UpperSat_b ?
        controller_template_P.Saturation2_UpperSat_b :
        controller_template_B.DataTypeConversion[4] <=
        controller_template_P.Saturation2_LowerSat_h ?
        controller_template_P.Saturation2_LowerSat_h :
        controller_template_B.DataTypeConversion[4];

      /* UnitDelay: '<S30>/Unit Delay2' */
      controller_template_B.UnitDelay2_o =
        controller_template_DWork.UnitDelay2_DSTATE_l;
    }

    /* End of RateTransition: '<S30>/Rate Transition' */

    /* MATLAB Function: '<S35>/MATLAB Function' incorporates:
     *  Constant: '<S35>/Constant'
     *  Constant: '<S35>/Constant1'
     */
    controller_template_DWork.sfEvent_i = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate/MATLAB Function': '<S36>:1' */
    /* '<S36>:1:4' */
    for (k = 0; k < 4; k++) {
      u = controller_template_P.Constant_Value_c[k + 12] *
        controller_template_B.RateTransition_i[3] +
        (controller_template_P.Constant_Value_c[k + 8] *
         controller_template_B.RateTransition_i[2] +
         (controller_template_P.Constant_Value_c[k + 4] *
          controller_template_B.RateTransition_i[1] +
          controller_template_P.Constant_Value_c[k] *
          controller_template_B.RateTransition_i[0]));
      X_0[k] = u;
    }

    for (k = 0; k < 4; k++) {
      tmp_1[k] = controller_template_P.Constant1_Value_gy[k + 4] * 0.0 +
        controller_template_P.Constant1_Value_gy[k] *
        controller_template_B.UnitDelay2_o;
    }

    controller_template_B.y_a[0] = X_0[0] + tmp_1[0];
    controller_template_B.y_a[1] = X_0[1] + tmp_1[1];
    controller_template_B.y_a[2] = X_0[2] + tmp_1[2];
    controller_template_B.y_a[3] = X_0[3] + tmp_1[3];

    /* End of MATLAB Function: '<S35>/MATLAB Function' */

    /* MATLAB Function: '<S30>/Ctrl_Xdir' incorporates:
     *  Constant: '<S30>/Constant'
     *  Constant: '<S30>/Constant1'
     *  Constant: '<S30>/Constant2'
     *  Constant: '<S30>/Constant3'
     *  Constant: '<S30>/Constant4'
     */
    controller_template_DWork.sfEvent_cd = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S34>:1' */
    /* '<S34>:1:3' */
    tolerance = 1.0;

    /* '<S34>:1:5' */
    /* '<S34>:1:6' */
    minreg = -1;

    /* '<S34>:1:7' */
    X[0] = 10000.0 * controller_template_B.y_a[0];
    X[1] = 10000.0 * controller_template_B.y_a[1];
    X[2] = 10000.0 * controller_template_B.y_a[2];
    X[3] = 10000.0 * controller_template_B.y_a[3];
    controller_template_round_c(X);
    X_0[0] = X[0];
    X_0[1] = X[1];
    X_0[2] = X[2];
    X_0[3] = X[3];
    controller_template_mrdivide_c(X_0, 10000.0, X);

    /* '<S34>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S34>:1:12' */
    memset((void *)&Hi[0], 0, 400U * sizeof(real_T));

    /* '<S34>:1:13' */
    memset((void *)&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S34>:1:16' */
    abspos = 1.0;

    /* '<S34>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 134) {
        /* '<S34>:1:17' */
        /* '<S34>:1:18' */
        rtb_Add = 0.0;

        /* '<S34>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S34>:1:23' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; i++) {
          /* '<S34>:1:23' */
          /* '<S34>:1:24' */
          /* '<S34>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S34>:1:24' */
          /* '<S34>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 99] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 1132];

          /* '<S34>:1:24' */
          /* '<S34>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 199] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 2265];

          /* '<S34>:1:24' */
          /* '<S34>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 299] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 3398];

          /* '<S34>:1:24' */
          /* '<S34>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S34>:1:30' */
        for (k = 0; k <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; k++) {
          /* '<S34>:1:30' */
          /* '<S34>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_j[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S34>:1:30' */
        }

        /* '<S34>:1:33' */
        abspos += controller_template_P.Constant4_Value_g[ireg];

        /* '<S34>:1:35' */
        /* '<S34>:1:36' */
        /* '<S34>:1:38' */
        /* '<S34>:1:40' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; i++) {
          /* '<S34>:1:40' */
          /* '<S34>:1:41' */
          MM_ref = ((Hi[(int32_T)(1.0 + (real_T)i) - 1] * X[0] + Hi[(int32_T)
                     (1.0 + (real_T)i) + 99] * X[1]) + Hi[(int32_T)(1.0 +
                     (real_T)i) + 199] * X[2]) + Hi[(int32_T)(1.0 + (real_T)i) +
            299] * X[3];
          if (MM_ref - Ki[(int32_T)(1.0 + (real_T)i) - 1] > 1.0E-8) {
            /* '<S34>:1:42' */
            /* '<S34>:1:43' */
            isinside = 0;

            /* '<S34>:1:44' */
            rtb_Add += MM_ref - Ki[(int32_T)(1.0 + (real_T)i) - 1];
          }

          /* '<S34>:1:40' */
        }

        if (rtb_Add < tolerance) {
          /* '<S34>:1:48' */
          /* '<S34>:1:49' */
          tolerance = rtb_Add;

          /* '<S34>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S34>:1:53' */
          /* '<S34>:1:54' */
          rtb_roll_cmd_c = (((controller_template_P.Constant2_Value_j[ireg + 134]
                              * X[1] +
                              controller_template_P.Constant2_Value_j[ireg] * X
                              [0]) +
                             controller_template_P.Constant2_Value_j[ireg + 268]
                             * X[2]) +
                            controller_template_P.Constant2_Value_j[ireg + 402] *
                            X[3]) +
            controller_template_P.Constant3_Value_ok[ireg];
          exitg = 1;
        } else {
          /* '<S34>:1:17' */
          ireg++;
        }
      } else {
        /* '<S34>:1:58' */
        /* '<S34>:1:59' */
        /* '<S34>:1:60' */
        rtb_roll_cmd_c = (((controller_template_P.Constant2_Value_j[minreg + 134]
                            * X[1] +
                            controller_template_P.Constant2_Value_j[minreg] * X
                            [0]) +
                           controller_template_P.Constant2_Value_j[minreg + 268]
                           * X[2]) +
                          controller_template_P.Constant2_Value_j[minreg + 402] *
                          X[3]) +
          controller_template_P.Constant3_Value_ok[minreg];

        /* '<S34>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_p = rtb_roll_cmd_c;
    controller_template_B.flag_oob_o = (real_T)flag_oob;

    /* End of MATLAB Function: '<S30>/Ctrl_Xdir' */

    /* Gain: '<S31>/Gain' incorporates:
     *  Saturate: '<S17>/Saturation4'
     *  Sum: '<S31>/Sum'
     *  Sum: '<S31>/Sum1'
     *  UnitDelay: '<S31>/Unit Delay'
     *  UnitDelay: '<S31>/Unit Delay2'
     */
    controller_template_B.Gain_f = ((controller_template_B.U_p >=
      controller_template_P.Saturation4_UpperSat_i ?
      controller_template_P.Saturation4_UpperSat_i : controller_template_B.U_p <=
      controller_template_P.Saturation4_LowerSat_h ?
      controller_template_P.Saturation4_LowerSat_h : controller_template_B.U_p)
      + (controller_template_DWork.UnitDelay2_DSTATE_k +
         controller_template_DWork.UnitDelay_DSTATE_f)) *
      controller_template_P.Gain_Gain_f;

    /* Sum: '<S10>/Sum1' */
    rtb_roll_cmd_c = controller_template_B.Gain_f - rtb_bias_W[1];

    /* Sum: '<S20>/Add' */
    u = controller_template_B.DataTypeConversion[2] -
      controller_template_B.X_ref_z[0];

    /* Saturate: '<S20>/Saturation1' */
    controller_template_B.Saturation1 = u >=
      controller_template_P.Saturation1_UpperSat_d ?
      controller_template_P.Saturation1_UpperSat_d : u <=
      controller_template_P.Saturation1_LowerSat_n ?
      controller_template_P.Saturation1_LowerSat_n : u;

    /* RateTransition: '<S46>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      controller_template_B.RateTransition_j[0] =
        controller_template_B.Saturation1;

      /* Saturate: '<S20>/Saturation' */
      controller_template_B.RateTransition_j[1] =
        controller_template_B.DataTypeConversion[5] >=
        controller_template_P.Saturation_UpperSat_d ?
        controller_template_P.Saturation_UpperSat_d :
        controller_template_B.DataTypeConversion[5] <=
        controller_template_P.Saturation_LowerSat_b ?
        controller_template_P.Saturation_LowerSat_b :
        controller_template_B.DataTypeConversion[5];
    }

    /* End of RateTransition: '<S46>/Rate Transition' */

    /* MATLAB Function: '<S46>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_k0 = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S48>:1' */
    /* '<S48>:1:3' */
    tolerance = 1.0;

    /* '<S48>:1:5' */
    /* '<S48>:1:6' */
    minreg = -1;

    /* '<S48>:1:7' */
    temp_idx = 10000.0 * controller_template_B.RateTransition_j[0];
    temp_idx_0 = 10000.0 * controller_template_B.RateTransition_j[1];
    u = temp_idx;
    if (!(fabs(temp_idx) > 4.503599627370496E+15)) {
      if (temp_idx >= 0.5) {
        u = floor(temp_idx + 0.5);
      } else if (temp_idx > -0.5) {
        u = -0.0;
      } else {
        u = ceil(temp_idx - 0.5);
      }
    }

    /* End of Outputs for SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    temp_idx = u;

    /* Outputs for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* MATLAB Function: '<S46>/Ctrl_Xdir' incorporates:
     *  Constant: '<S46>/Constant'
     *  Constant: '<S46>/Constant1'
     *  Constant: '<S46>/Constant2'
     *  Constant: '<S46>/Constant3'
     *  Constant: '<S46>/Constant4'
     */
    u = temp_idx_0;
    if (!(fabs(temp_idx_0) > 4.503599627370496E+15)) {
      if (temp_idx_0 >= 0.5) {
        u = floor(temp_idx_0 + 0.5);
      } else if (temp_idx_0 > -0.5) {
        u = -0.0;
      } else {
        u = ceil(temp_idx_0 - 0.5);
      }
    }

    temp_idx /= 10000.0;
    u /= 10000.0;

    /* '<S48>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S48>:1:12' */
    memset((void *)&Hi_0[0], 0, 200U * sizeof(real_T));

    /* '<S48>:1:13' */
    memset((void *)&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S48>:1:16' */
    abspos = 1.0;

    /* '<S48>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 27) {
        /* '<S48>:1:17' */
        /* '<S48>:1:18' */
        rtb_Add = 0.0;

        /* '<S48>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S48>:1:23' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; i++) {
          /* '<S48>:1:23' */
          /* '<S48>:1:24' */
          /* '<S48>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_b[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S48>:1:24' */
          /* '<S48>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)i) + 99] =
            controller_template_P.Constant_Value_b[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 111];

          /* '<S48>:1:24' */
          /* '<S48>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S48>:1:30' */
        for (k = 0; k <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; k++) {
          /* '<S48>:1:30' */
          /* '<S48>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_l[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S48>:1:30' */
        }

        /* '<S48>:1:33' */
        abspos += controller_template_P.Constant4_Value_a[ireg];

        /* '<S48>:1:35' */
        /* '<S48>:1:36' */
        /* '<S48>:1:38' */
        /* '<S48>:1:40' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; i++) {
          /* '<S48>:1:40' */
          /* '<S48>:1:41' */
          MM_ref = Hi_0[(int32_T)(1.0 + (real_T)i) - 1] * temp_idx + Hi_0
            [(int32_T)(1.0 + (real_T)i) + 99] * u;
          if (MM_ref - Ki[(int32_T)(1.0 + (real_T)i) - 1] > 1.0E-8) {
            /* '<S48>:1:42' */
            /* '<S48>:1:43' */
            isinside = 0;

            /* '<S48>:1:44' */
            rtb_Add += MM_ref - Ki[(int32_T)(1.0 + (real_T)i) - 1];
          }

          /* '<S48>:1:40' */
        }

        if (rtb_Add < tolerance) {
          /* '<S48>:1:48' */
          /* '<S48>:1:49' */
          tolerance = rtb_Add;

          /* '<S48>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S48>:1:53' */
          /* '<S48>:1:54' */
          roll_cmd_f = (controller_template_P.Constant2_Value_g[ireg + 27] * u +
                        controller_template_P.Constant2_Value_g[ireg] * temp_idx)
            + controller_template_P.Constant3_Value_m[ireg];
          exitg = 1;
        } else {
          /* '<S48>:1:17' */
          ireg++;
        }
      } else {
        /* '<S48>:1:58' */
        /* '<S48>:1:59' */
        /* '<S48>:1:60' */
        roll_cmd_f = (controller_template_P.Constant2_Value_g[minreg + 27] * u +
                      controller_template_P.Constant2_Value_g[minreg] * temp_idx)
          + controller_template_P.Constant3_Value_m[minreg];

        /* '<S48>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U = roll_cmd_f;
    controller_template_B.flag_oob = (real_T)flag_oob;

    /* Gain: '<S47>/Gain' incorporates:
     *  Saturate: '<S20>/Saturation2'
     *  Sum: '<S47>/Sum'
     *  Sum: '<S47>/Sum1'
     *  UnitDelay: '<S47>/Unit Delay'
     *  UnitDelay: '<S47>/Unit Delay2'
     */
    controller_template_B.Gain_i = ((controller_template_B.U >=
      controller_template_P.Saturation2_UpperSat_k ?
      controller_template_P.Saturation2_UpperSat_k : controller_template_B.U <=
      controller_template_P.Saturation2_LowerSat_j ?
      controller_template_P.Saturation2_LowerSat_j : controller_template_B.U) +
                                    
      (controller_template_DWork.UnitDelay2_DSTATE_b +
       controller_template_DWork.UnitDelay_DSTATE_fw)) *
      controller_template_P.Gain_Gain_p;

    /* Sum: '<S18>/Sum' incorporates:
     *  Constant: '<S18>/Constant'
     *  Gain: '<S39>/Slider Gain'
     *  Gain: '<S40>/Slider Gain'
     */
    controller_template_B.Sum = controller_template_P.SliderGain_Gain_a *
      controller_template_B.X_ref_yaw[0] +
      controller_template_P.SliderGain_Gain_j *
      controller_template_P.Constant_Value_fv;

    /* MATLAB Function: '<S42>/MATLAB Function' */
    controller_template_DWork.sfEvent_l = CALL_EVENT;

    /* Sum: '<S18>/Add' */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate/MATLAB Function': '<S43>:1' */
    /* '<S43>:1:4' */
    u = controller_template_B.sf_discretekalmanfilter.state_est[0] -
      controller_template_B.Sum;

    /* MATLAB Function: '<S42>/MATLAB Function' incorporates:
     *  Constant: '<S42>/Constant'
     *  Constant: '<S42>/Constant1'
     *  Saturate: '<S18>/Saturation'
     *  UnitDelay: '<S37>/Unit Delay2'
     */
    controller_template_B.y = (u >= controller_template_P.Saturation_UpperSat_o ?
      controller_template_P.Saturation_UpperSat_o : u <=
      controller_template_P.Saturation_LowerSat_p ?
      controller_template_P.Saturation_LowerSat_p : u) *
      controller_template_P.Constant_Value_h +
      controller_template_P.Constant1_Value_m *
      controller_template_DWork.UnitDelay2_DSTATE_g;

    /* MATLAB Function: '<S37>/Ctrl_Xdir' incorporates:
     *  Constant: '<S37>/Constant'
     *  Constant: '<S37>/Constant1'
     *  Constant: '<S37>/Constant2'
     *  Constant: '<S37>/Constant3'
     *  Constant: '<S37>/Constant4'
     */
    controller_template_DWork.sfEvent_jv = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S41>:1' */
    /* '<S41>:1:3' */
    tolerance = 1.0;

    /* '<S41>:1:5' */
    /* '<S41>:1:6' */
    minreg = -1;

    /* '<S41>:1:7' */
    yaw_rate_cmd_g = 10000.0 * controller_template_B.y;
    if (!(fabs(yaw_rate_cmd_g) > 4.503599627370496E+15)) {
      if (yaw_rate_cmd_g >= 0.5) {
        yaw_rate_cmd_g = floor(yaw_rate_cmd_g + 0.5);
      } else if (yaw_rate_cmd_g > -0.5) {
        yaw_rate_cmd_g = -0.0;
      } else {
        yaw_rate_cmd_g = ceil(yaw_rate_cmd_g - 0.5);
      }
    }

    yaw_rate_cmd_g /= 10000.0;

    /* '<S41>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S41>:1:12' */
    /* '<S41>:1:13' */
    for (i = 0; i < 100; i++) {
      Hi_1[i] = 0.0;
      Ki[i] = 0.0;
    }

    /*  Find the proper region */
    /* '<S41>:1:16' */
    abspos = 1.0;

    /* '<S41>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 3) {
        /* '<S41>:1:17' */
        /* '<S41>:1:18' */
        rtb_Add = 0.0;

        /* '<S41>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S41>:1:23' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_gb[ireg]
             - 1; i++) {
          /* '<S41>:1:23' */
          /* '<S41>:1:25' */
          Hi_1[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_a[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S41>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S41>:1:30' */
        for (k = 0; k <= (int32_T)controller_template_P.Constant4_Value_gb[ireg]
             - 1; k++) {
          /* '<S41>:1:30' */
          /* '<S41>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_gs[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S41>:1:30' */
        }

        /* '<S41>:1:33' */
        abspos += controller_template_P.Constant4_Value_gb[ireg];

        /* '<S41>:1:35' */
        /* '<S41>:1:36' */
        /* '<S41>:1:38' */
        /* '<S41>:1:40' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_gb[ireg]
             - 1; i++) {
          /* '<S41>:1:40' */
          /* '<S41>:1:41' */
          MM_ref = Hi_1[(int32_T)(1.0 + (real_T)i) - 1] * yaw_rate_cmd_g;
          if (MM_ref - Ki[(int32_T)(1.0 + (real_T)i) - 1] > 1.0E-8) {
            /* '<S41>:1:42' */
            /* '<S41>:1:43' */
            isinside = 0;

            /* '<S41>:1:44' */
            rtb_Add += MM_ref - Ki[(int32_T)(1.0 + (real_T)i) - 1];
          }

          /* '<S41>:1:40' */
        }

        if (rtb_Add < tolerance) {
          /* '<S41>:1:48' */
          /* '<S41>:1:49' */
          tolerance = rtb_Add;

          /* '<S41>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S41>:1:53' */
          /* '<S41>:1:54' */
          rtb_Saturation_n = controller_template_P.Constant2_Value_jq[ireg] *
            yaw_rate_cmd_g + controller_template_P.Constant3_Value_b[ireg];
          exitg = 1;
        } else {
          /* '<S41>:1:17' */
          ireg++;
        }
      } else {
        /* '<S41>:1:58' */
        /* '<S41>:1:59' */
        /* '<S41>:1:60' */
        rtb_Saturation_n = controller_template_P.Constant2_Value_jq[minreg] *
          yaw_rate_cmd_g + controller_template_P.Constant3_Value_b[minreg];

        /* '<S41>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_g = rtb_Saturation_n;
    controller_template_B.flag_oob_l = (real_T)flag_oob;

    /* End of MATLAB Function: '<S37>/Ctrl_Xdir' */

    /* Gain: '<S38>/Gain' incorporates:
     *  Saturate: '<S18>/Saturation1'
     *  Sum: '<S38>/Sum'
     *  Sum: '<S38>/Sum1'
     *  UnitDelay: '<S38>/Unit Delay'
     *  UnitDelay: '<S38>/Unit Delay2'
     */
    controller_template_B.Gain_n = ((controller_template_B.U_g >=
      controller_template_P.Saturation1_UpperSat_g ?
      controller_template_P.Saturation1_UpperSat_g : controller_template_B.U_g <=
      controller_template_P.Saturation1_LowerSat_b ?
      controller_template_P.Saturation1_LowerSat_b : controller_template_B.U_g)
      + (controller_template_DWork.UnitDelay2_DSTATE_ga +
         controller_template_DWork.UnitDelay_DSTATE_p)) *
      controller_template_P.Gain_Gain_p0;

    /* Sum: '<S10>/Sum3' */
    yaw_rate_cmd_g = controller_template_B.Gain_n -
      controller_template_B.Saturation;

    /* Sum: '<S10>/Sum5' incorporates:
     *  Sum: '<S10>/Sum2'
     */
    controller_template_B.thrust_cmd_a = (controller_template_B.Gain_i -
      rtb_bias_W[2]) + rtb_Product_l;

    /* RateTransition: '<S21>/Rate Transition1' incorporates:
     *  RateTransition: '<S30>/Rate Transition1'
     */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      controller_template_B.RateTransition1 = controller_template_B.Gain;
      controller_template_B.RateTransition1_l = controller_template_B.Gain_f;
    }

    /* End of RateTransition: '<S21>/Rate Transition1' */

    /* Gain: '<S18>/Gain' */
    controller_template_B.Gain_g = controller_template_P.Gain_Gain_b *
      controller_template_B.sf_discretekalmanfilter.state_est[0];

    /* Update for Delay: '<S10>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE_k = yaw_rate_cmd_g;

    /* Update for UnitDelay: '<S19>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_bg, (void *)
           (&controller_template_B.sf_discretekalmanfilter.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S44>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S44>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
      controller_template_P.FixPtConstant_Value;

    /* Update for UnitDelay: '<S44>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0] =
      controller_template_B.sf_discretekalmanfilter.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1] =
      controller_template_B.sf_discretekalmanfilter.state_est[1];
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for UnitDelay: '<S21>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE =
        controller_template_B.RateTransition1;
    }

    /* Update for UnitDelay: '<S23>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_d = controller_template_B.Gain;

    /* Update for UnitDelay: '<S23>/Unit Delay' incorporates:
     *  UnitDelay: '<S23>/Unit Delay1'
     */
    controller_template_DWork.UnitDelay_DSTATE_jv =
      controller_template_DWork.UnitDelay1_DSTATE_a;
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for UnitDelay: '<S30>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_l =
        controller_template_B.RateTransition1_l;
    }

    /* Update for UnitDelay: '<S31>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_k = controller_template_B.Gain_f;

    /* Update for UnitDelay: '<S31>/Unit Delay' incorporates:
     *  UnitDelay: '<S31>/Unit Delay1'
     */
    controller_template_DWork.UnitDelay_DSTATE_f =
      controller_template_DWork.UnitDelay1_DSTATE_ji;

    /* Update for UnitDelay: '<S47>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_b = controller_template_B.Gain_i;

    /* Update for UnitDelay: '<S47>/Unit Delay' incorporates:
     *  UnitDelay: '<S47>/Unit Delay1'
     */
    controller_template_DWork.UnitDelay_DSTATE_fw =
      controller_template_DWork.UnitDelay1_DSTATE_m;

    /* Update for UnitDelay: '<S37>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_g = controller_template_B.Gain_n;

    /* Update for UnitDelay: '<S38>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_ga =
      controller_template_B.Gain_n;

    /* Update for UnitDelay: '<S38>/Unit Delay' incorporates:
     *  UnitDelay: '<S38>/Unit Delay1'
     */
    controller_template_DWork.UnitDelay_DSTATE_p =
      controller_template_DWork.UnitDelay1_DSTATE_c3;

    /* Update for UnitDelay: '<S23>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_a = controller_template_B.Gain;

    /* Update for UnitDelay: '<S31>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_ji =
      controller_template_B.Gain_f;

    /* Update for UnitDelay: '<S38>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_c3 =
      controller_template_B.Gain_n;

    /* Update for UnitDelay: '<S47>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_m = controller_template_B.Gain_i;

    /* End of Outputs for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

    /* SignalConversion: '<S14>/TmpSignal ConversionAtTo FileInport1' */
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
    rtb_TmpSignalConversionAtToFi_a[17] = yaw_rate_cmd_g;

    /* ToFile: '<S14>/To File' */
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

    /* SignalConversion: '<S14>/TmpSignal ConversionAtTo File1Inport1' */
    rtb_TmpSignalConversionAtToFi_p[0] = rtb_bias_W[0];
    rtb_TmpSignalConversionAtToFi_p[1] = rtb_bias_W[1];
    rtb_TmpSignalConversionAtToFi_p[2] = rtb_bias_W[2];
    rtb_TmpSignalConversionAtToFi_p[3] = controller_template_B.Saturation;

    /* ToFile: '<S14>/To File1' */
    if (!(++controller_template_DWork.ToFile1_IWORK_p.Decimation % 1) &&
        (controller_template_DWork.ToFile1_IWORK_p.Count*5)+1 < 100000000 ) {
      FILE *fp = (FILE *) controller_template_DWork.ToFile1_PWORK_i.FilePtr;
      if (fp != (NULL)) {
        real_T u[5];
        controller_template_DWork.ToFile1_IWORK_p.Decimation = 0;
        u[0] = controller_template_M->Timing.taskTime0;
        u[1] = rtb_TmpSignalConversionAtToFi_p[0];
        u[2] = rtb_TmpSignalConversionAtToFi_p[1];
        u[3] = rtb_TmpSignalConversionAtToFi_p[2];
        u[4] = rtb_TmpSignalConversionAtToFi_p[3];
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

    /* Gain: '<S14>/rad -> deg2' */
    controller_template_B.raddeg2_p[0] = controller_template_P.raddeg2_Gain *
      controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot;
    controller_template_B.raddeg2_p[1] = controller_template_P.raddeg2_Gain *
      controller_template_B.DataTypeConversion[10];
    controller_template_B.raddeg2_p[2] = controller_template_P.raddeg2_Gain *
      rtb_pitch_cmd_b;

    /* Gain: '<S14>/rad -> deg1' */
    controller_template_B.raddeg1_e[0] = controller_template_P.raddeg1_Gain *
      controller_template_B.sf_EmbeddedMATLABFunction.roll_rot;
    controller_template_B.raddeg1_e[1] = controller_template_P.raddeg1_Gain *
      controller_template_B.DataTypeConversion[9];
    controller_template_B.raddeg1_e[2] = controller_template_P.raddeg1_Gain *
      rtb_roll_cmd_c;

    /* Gain: '<S14>/rad -> deg3' */
    controller_template_B.raddeg3_a[0] = controller_template_P.raddeg3_Gain *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg3_a[1] = controller_template_P.raddeg3_Gain *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg3_a[2] = controller_template_P.raddeg3_Gain *
      yaw_rate_cmd_g;

    /* Gain: '<S14>/rad -> deg' */
    controller_template_B.raddeg_j[0] = controller_template_P.raddeg_Gain *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg_j[1] = controller_template_P.raddeg_Gain *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg_j[2] = controller_template_P.raddeg_Gain *
      controller_template_B.X_ref_yaw[0];
    controller_template_B.raddeg_j[3] = controller_template_P.raddeg_Gain *
      controller_template_B.X_ref_yaw[1];

    /* Outputs for Atomic SubSystem: '<S2>/decoupling and rotation' */
    /* Inport: '<S11>/bias_W' */
    controller_template_B.bias_W_b[0] = rtb_TmpSignalConversionAtToFi_p[0];
    controller_template_B.bias_W_b[1] = rtb_TmpSignalConversionAtToFi_p[1];
    controller_template_B.bias_W_b[2] = rtb_TmpSignalConversionAtToFi_p[2];
    controller_template_B.bias_W_b[3] = rtb_TmpSignalConversionAtToFi_p[3];

    /* Inport: '<S11>/cmd_W' */
    controller_template_B.cmd_W_h[0] = rtb_pitch_cmd_b;
    controller_template_B.cmd_W_h[1] = rtb_roll_cmd_c;
    controller_template_B.cmd_W_h[2] = controller_template_B.thrust_cmd_a;
    controller_template_B.cmd_W_h[3] = yaw_rate_cmd_g;

    /* MATLAB Function: '<S49>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S49>/g'
     */
    controller_template_DWork.sfEvent_c = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Embedded MATLAB Function': '<S51>:1' */
    /* '<S51>:1:3' */
    if ((fabs(controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot) <=
         0.069813170079773182) && (fabs
         (controller_template_B.sf_EmbeddedMATLABFunction.roll_rot) <=
         0.069813170079773182)) {
      /* '<S51>:1:4' */
      /* '<S51>:1:5' */
      yaw_rate_cmd_g = controller_template_B.cmd_W_h[2] / (cos
        (controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot) * cos
        (controller_template_B.sf_EmbeddedMATLABFunction.roll_rot));
    } else {
      /* '<S51>:1:7' */
      yaw_rate_cmd_g = controller_template_B.cmd_W_h[2];
    }

    /* '<S51>:1:9' */
    controller_template_B.pitch_cmd_comp_n =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value / yaw_rate_cmd_g *
      controller_template_B.cmd_W_h[0];

    /* '<S51>:1:10' */
    controller_template_B.roll_cmd_comp_j =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value / yaw_rate_cmd_g *
      controller_template_B.cmd_W_h[1];

    /*  pitch_cmd_comp=pitch_cmd; */
    /*  roll_cmd_comp=roll_cmd; */
    /*  pitch_cmd_comp = atan(Fx/(-thrust_comp)); */
    /*  roll_cmd_comp = atan(Fy/(thrust_comp)); */
    /*  pitch_cmd_comp = atan(-g*m*pitch_cmd/(-thrust)); */
    /*  roll_cmd_comp = atan(g*m*roll_cmd*cos(pitch_meas)/(thrust)); */
    controller_template_B.thrust_comp_k = yaw_rate_cmd_g;

    /* End of MATLAB Function: '<S49>/Embedded MATLAB Function' */

    /* MATLAB Function: '<S50>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_j = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S52>:1' */
    /* '<S52>:1:3' */
    yaw_rate_cmd_g = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S52>:1:4' */
    rtb_Add = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S52>:1:6' */
    /* '<S52>:1:8' */
    /* '<S52>:1:9' */
    controller_template_B.pitch_rot_n = rtb_Add *
      controller_template_B.pitch_cmd_comp_n + -yaw_rate_cmd_g *
      controller_template_B.roll_cmd_comp_j;

    /* '<S52>:1:10' */
    controller_template_B.roll_rot_e = yaw_rate_cmd_g *
      controller_template_B.pitch_cmd_comp_n + rtb_Add *
      controller_template_B.roll_cmd_comp_j;

    /* '<S52>:1:12' */
    /* '<S52>:1:13' */
    controller_template_B.pitch_bias_rot_i = rtb_Add *
      controller_template_B.bias_W_b[0] + -yaw_rate_cmd_g *
      controller_template_B.bias_W_b[1];

    /* '<S52>:1:14' */
    controller_template_B.roll_bias_rot_d = yaw_rate_cmd_g *
      controller_template_B.bias_W_b[0] + rtb_Add *
      controller_template_B.bias_W_b[1];

    /* End of Outputs for SubSystem: '<S2>/decoupling and rotation' */
    srUpdateBC(controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC);
  } else {
    if (controller_template_DWork.FreeFlightPosCtrl_MODE) {
      controller_template_DWork.FreeFlightPosCtrl_MODE = FALSE;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/FreeFlight Pos Ctrl' */

  /* MultiPortSwitch: '<S6>/Multiport Switch' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
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

  /* End of MultiPortSwitch: '<S6>/Multiport Switch' */

  /* Switch: '<S4>/SwitchControl' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<S4>/Constant'
   */
  if (controller_template_P.Constant_Value_n >
      controller_template_P.SwitchControl_Threshold_b) {
    u = controller_template_P.Constant_Value_p;
  } else {
    u = controller_template_B.MultiportSwitch;
  }

  /* End of Switch: '<S4>/SwitchControl' */

  /* Outputs for Enabled SubSystem: '<Root>/pos controller' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (u > 0.0) {
    if (!controller_template_DWork.poscontroller_MODE) {
      /* InitializeConditions for MATLAB Function: '<S59>/Embedded MATLAB Function' */
      con_EmbeddedMATLABFunction_Init
        (&controller_template_DWork.sf_EmbeddedMATLABFunction_o);

      /* InitializeConditions for Atomic SubSystem: '<S9>/MAIN CONTROL LOOP1' */
      /* InitializeConditions for Delay: '<S56>/Integer Delay' */
      controller_template_DWork.IntegerDelay_DSTATE =
        controller_template_P.IntegerDelay_InitialCondition;

      /* InitializeConditions for Delay: '<S56>/Integer Delay1' */
      controller_template_DWork.IntegerDelay1_DSTATE =
        controller_template_P.IntegerDelay1_InitialCondition;

      /* InitializeConditions for Delay: '<S56>/Integer Delay2' */
      controller_template_DWork.IntegerDelay2_DSTATE =
        controller_template_P.IntegerDelay2_InitialCondition;

      /* InitializeConditions for Delay: '<S56>/Integer Delay3' */
      controller_template_DWork.IntegerDelay3_DSTATE =
        controller_template_P.IntegerDelay3_InitialConditio_c;

      /* InitializeConditions for UnitDelay: '<S63>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
             controller_template_P.UnitDelay1_X0_c, sizeof(real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S71>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
        controller_template_P.FixPtUnitDelay2_X0_d;

      /* InitializeConditions for UnitDelay: '<S71>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
        controller_template_P.FixPtUnitDelay1_X0_f;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
        controller_template_P.FixPtUnitDelay1_X0_f;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
        controller_template_P.FixPtUnitDelay1_X0_f;

      /* InitializeConditions for MATLAB Function: '<S63>/discrete kalman filter' */
      con_discretekalmanfilter_k_Init
        (&controller_template_DWork.sf_discretekalmanfilter_b);

      /* InitializeConditions for UnitDelay: '<S62>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE[0] =
        controller_template_P.UnitDelay_X0_fc[0];
      controller_template_DWork.UnitDelay_DSTATE[1] =
        controller_template_P.UnitDelay_X0_fc[1];
      controller_template_DWork.UnitDelay_DSTATE[2] =
        controller_template_P.UnitDelay_X0_fc[2];

      /* InitializeConditions for UnitDelay: '<S62>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
             controller_template_P.UnitDelay1_X0_k, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S62>/runFastGradient' */
      controller_runFastGradient_Init
        (&controller_template_DWork.sf_runFastGradient);

      /* InitializeConditions for UnitDelay: '<S65>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
             controller_template_P.UnitDelay1_X0_fk, sizeof(real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S74>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
        controller_template_P.FixPtUnitDelay2_X0_n;

      /* InitializeConditions for UnitDelay: '<S74>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
        controller_template_P.FixPtUnitDelay1_X0_n;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
        controller_template_P.FixPtUnitDelay1_X0_n;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
        controller_template_P.FixPtUnitDelay1_X0_n;

      /* InitializeConditions for MATLAB Function: '<S65>/discrete kalman filter' */
      con_discretekalmanfilter_k_Init
        (&controller_template_DWork.sf_discretekalmanfilter_m);

      /* InitializeConditions for UnitDelay: '<S64>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_j[0] =
        controller_template_P.UnitDelay_X0_ik[0];
      controller_template_DWork.UnitDelay_DSTATE_j[1] =
        controller_template_P.UnitDelay_X0_ik[1];
      controller_template_DWork.UnitDelay_DSTATE_j[2] =
        controller_template_P.UnitDelay_X0_ik[2];

      /* InitializeConditions for UnitDelay: '<S64>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
             controller_template_P.UnitDelay1_X0_jc, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S64>/runFastGradient' */
      controller_runFastGradient_Init
        (&controller_template_DWork.sf_runFastGradient_d);

      /* InitializeConditions for UnitDelay: '<S69>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
             controller_template_P.UnitDelay1_X0_cw, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S80>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
        controller_template_P.FixPtUnitDelay2_X0_do;

      /* InitializeConditions for UnitDelay: '<S80>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
        controller_template_P.FixPtUnitDelay1_X0_c;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
        controller_template_P.FixPtUnitDelay1_X0_c;

      /* InitializeConditions for MATLAB Function: '<S69>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter_k);

      /* InitializeConditions for UnitDelay: '<S68>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_l[0] =
        controller_template_P.UnitDelay_X0_a[0];
      controller_template_DWork.UnitDelay_DSTATE_l[1] =
        controller_template_P.UnitDelay_X0_a[1];

      /* InitializeConditions for UnitDelay: '<S68>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
             controller_template_P.UnitDelay1_X0_b, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S68>/runFastGradient' */
      controller_template_DWork.sfEvent_k = CALL_EVENT;
      controller_template_DWork.is_active_c8_Hquad_control_LIB_ = 0U;

      /* InitializeConditions for UnitDelay: '<S67>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
             controller_template_P.UnitDelay1_X0_n, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S77>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
        controller_template_P.FixPtUnitDelay2_X0_i;

      /* InitializeConditions for UnitDelay: '<S77>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
        controller_template_P.FixPtUnitDelay1_X0_e;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
        controller_template_P.FixPtUnitDelay1_X0_e;

      /* InitializeConditions for MATLAB Function: '<S67>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter_n);

      /* InitializeConditions for UnitDelay: '<S66>/Unit Delay' */
      for (i = 0; i < 6; i++) {
        controller_template_DWork.UnitDelay_DSTATE_jz[i] =
          controller_template_P.UnitDelay_X0_fj[i];
      }

      /* End of InitializeConditions for UnitDelay: '<S66>/Unit Delay' */

      /* InitializeConditions for UnitDelay: '<S66>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
             controller_template_P.UnitDelay1_X0_o, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S66>/runFastGradient' */
      controller_template_DWork.sfEvent_n = CALL_EVENT;
      controller_template_DWork.is_active_c9_Hquad_control_LIB_ = 0U;

      /* End of InitializeConditions for SubSystem: '<S9>/MAIN CONTROL LOOP1' */

      /* InitializeConditions for Atomic SubSystem: '<S9>/decoupling and rotation' */
      /* InitializeConditions for MATLAB Function: '<S82>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_f = CALL_EVENT;
      controller_template_DWork.is_active_c1_Hquad_control_LIB_ = 0U;

      /* InitializeConditions for MATLAB Function: '<S83>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent = CALL_EVENT;
      controller_template_DWork.is_active_c4_Hquad_control_LIB_ = 0U;

      /* End of InitializeConditions for SubSystem: '<S9>/decoupling and rotation' */
      controller_template_DWork.poscontroller_MODE = TRUE;
    }

    /* MATLAB Function: '<S59>/Embedded MATLAB Function' */
    controll_EmbeddedMATLABFunction(controller_template_B.DataTypeConversion[6],
      controller_template_B.DataTypeConversion[7], rtb_Init[0], rtb_Init[1],
      controller_template_B.DataTypeConversion[8],
      &controller_template_B.sf_EmbeddedMATLABFunction_o,
      &controller_template_DWork.sf_EmbeddedMATLABFunction_o);

    /* Outputs for Atomic SubSystem: '<S9>/MAIN CONTROL LOOP1' */
    /* Delay: '<S56>/Integer Delay' */
    rtb_IntegerDelay = controller_template_DWork.IntegerDelay_DSTATE;

    /* Delay: '<S56>/Integer Delay1' */
    rtb_IntegerDelay1 = controller_template_DWork.IntegerDelay1_DSTATE;

    /* Delay: '<S56>/Integer Delay2' */
    rtb_IntegerDelay2 = controller_template_DWork.IntegerDelay2_DSTATE;

    /* Delay: '<S56>/Integer Delay3' */
    rtb_IntegerDelay3 = controller_template_DWork.IntegerDelay3_DSTATE;

    /* Product: '<S56>/Product' incorporates:
     *  Constant: '<S56>/gravity'
     */
    rtb_roll_cmd_c = controller_template_P.gravity_Value_j *
      controller_template_B.DataTypeConversion[29];

    /* UnitDelay: '<S63>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE, sizeof(real_T) << 4U);

    /* Switch: '<S71>/Init' incorporates:
     *  UnitDelay: '<S71>/FixPt Unit Delay1'
     *  UnitDelay: '<S71>/FixPt Unit Delay2'
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

    /* End of Switch: '<S71>/Init' */

    /* MATLAB Function: '<S63>/discrete kalman filter' */
    controll_discretekalmanfilter_b(controller_template_B.DataTypeConversion[0],
      controller_template_B.DataTypeConversion[3],
      controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_rot, rtb_Init_g,
      controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_bias_rot,
      controller_template_P.A_Value_h, controller_template_P.B_Value_i,
      controller_template_P.C_Value_c, controller_template_P.Q_Value_a,
      controller_template_P.R_Value_c, rtb_IntegerDelay, rtb_UnitDelay1,
      &controller_template_B.sf_discretekalmanfilter_b,
      &controller_template_DWork.sf_discretekalmanfilter_b);

    /* UnitDelay: '<S62>/Unit Delay' */
    rtb_UnitDelay[0] = controller_template_DWork.UnitDelay_DSTATE[0];
    rtb_UnitDelay[1] = controller_template_DWork.UnitDelay_DSTATE[1];
    rtb_UnitDelay[2] = controller_template_DWork.UnitDelay_DSTATE[2];

    /* UnitDelay: '<S62>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_o[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_c, 30U * sizeof(real_T));

    /* MATLAB Function: '<S62>/runFastGradient' */
    controller_temp_runFastGradient(controller_template_P.TT_PP_Value,
      controller_template_P.LL_PP_Value, controller_template_P.LL_ref_PP_Value,
      controller_template_P.LL_U_ref_PP_Value, controller_template_P.MM_Value,
      controller_template_P.PP_Value, controller_template_P.AA_delay_Value,
      controller_template_P.BB_delay_Value,
      controller_template_B.sf_discretekalmanfilter_b.state_est,
      controller_template_B.X_ref_x, controller_template_P.V_max_Value,
      controller_template_P.i_min_Value, controller_template_P.betas_Value,
      controller_template_P.L_Value, rtb_UnitDelay, rtb_UnitDelay1_o,
      &controller_template_B.sf_runFastGradient,
      &controller_template_DWork.sf_runFastGradient);

    /* Saturate: '<S63>/Saturation' */
    tolerance = controller_template_B.sf_discretekalmanfilter_b.state_est[3] >=
      controller_template_P.Saturation_UpperSat_ia ?
      controller_template_P.Saturation_UpperSat_ia :
      controller_template_B.sf_discretekalmanfilter_b.state_est[3] <=
      controller_template_P.Saturation_LowerSat_o ?
      controller_template_P.Saturation_LowerSat_o :
      controller_template_B.sf_discretekalmanfilter_b.state_est[3];

    /* Sum: '<S56>/Sum' */
    abspos = controller_template_B.sf_runFastGradient.u_opt - tolerance;

    /* UnitDelay: '<S65>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_oh[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_b, sizeof(real_T) << 4U);

    /* Switch: '<S74>/Init' incorporates:
     *  UnitDelay: '<S74>/FixPt Unit Delay1'
     *  UnitDelay: '<S74>/FixPt Unit Delay2'
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

    /* End of Switch: '<S74>/Init' */

    /* MATLAB Function: '<S65>/discrete kalman filter' */
    controll_discretekalmanfilter_b(controller_template_B.DataTypeConversion[1],
      controller_template_B.DataTypeConversion[4],
      controller_template_B.sf_EmbeddedMATLABFunction_o.roll_rot, rtb_Init_j,
      controller_template_B.sf_EmbeddedMATLABFunction_o.roll_bias_rot,
      controller_template_P.A_Value_n, controller_template_P.B_Value_h,
      controller_template_P.C_Value_p, controller_template_P.Q_Value_h,
      controller_template_P.R_Value_l, rtb_IntegerDelay1, rtb_UnitDelay1_oh,
      &controller_template_B.sf_discretekalmanfilter_m,
      &controller_template_DWork.sf_discretekalmanfilter_m);

    /* UnitDelay: '<S64>/Unit Delay' */
    rtb_UnitDelay_e[0] = controller_template_DWork.UnitDelay_DSTATE_j[0];
    rtb_UnitDelay_e[1] = controller_template_DWork.UnitDelay_DSTATE_j[1];
    rtb_UnitDelay_e[2] = controller_template_DWork.UnitDelay_DSTATE_j[2];

    /* UnitDelay: '<S64>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_g[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_l, 30U * sizeof(real_T));

    /* MATLAB Function: '<S64>/runFastGradient' */
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

    /* Saturate: '<S65>/Saturation' */
    rtb_pitch_cmd_b = controller_template_B.sf_discretekalmanfilter_m.state_est
      [3] >= controller_template_P.Saturation_UpperSat_f ?
      controller_template_P.Saturation_UpperSat_f :
      controller_template_B.sf_discretekalmanfilter_m.state_est[3] <=
      controller_template_P.Saturation_LowerSat_k ?
      controller_template_P.Saturation_LowerSat_k :
      controller_template_B.sf_discretekalmanfilter_m.state_est[3];

    /* Sum: '<S56>/Sum1' */
    roll_cmd_f = controller_template_B.sf_runFastGradient_d.u_opt -
      rtb_pitch_cmd_b;

    /* UnitDelay: '<S69>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_j[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_j, 9U * sizeof(real_T));

    /* Switch: '<S80>/Init' incorporates:
     *  UnitDelay: '<S80>/FixPt Unit Delay1'
     *  UnitDelay: '<S80>/FixPt Unit Delay2'
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

    /* End of Switch: '<S80>/Init' */

    /* MATLAB Function: '<S69>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.DataTypeConversion[2],
      controller_template_B.DataTypeConversion[5], rtb_Init_d, rtb_Init[2],
      controller_template_P.A_Value_f, controller_template_P.B_Value_n,
      controller_template_P.C_Value_o, controller_template_P.Q_Value_j,
      controller_template_P.R_Value_ca, rtb_IntegerDelay2, rtb_UnitDelay1_j,
      &controller_template_B.sf_discretekalmanfilter_k,
      &controller_template_DWork.sf_discretekalmanfilter_k);

    /* MATLAB Function: '<S68>/runFastGradient' incorporates:
     *  Constant: '<S68>/AA_delay'
     *  Constant: '<S68>/BB_delay'
     *  Constant: '<S68>/L'
     *  Constant: '<S68>/LL_PP'
     *  Constant: '<S68>/LL_U_ref_PP'
     *  Constant: '<S68>/LL_ref_PP'
     *  Constant: '<S68>/MM'
     *  Constant: '<S68>/PP'
     *  Constant: '<S68>/TT_PP'
     *  Constant: '<S68>/V_max'
     *  Constant: '<S68>/betas'
     *  Constant: '<S68>/i_min'
     *  UnitDelay: '<S68>/Unit Delay'
     *  UnitDelay: '<S68>/Unit Delay1'
     */
    controller_template_DWork.sfEvent_k = CALL_EVENT;

    /* MATLAB Function 'z controller MPC FG/runFastGradient': '<S79>:1' */
    /*  ugly, but simulink needs fix output sizes for vectors */
    /*  number of outputs u */
    /*  number of delay steps */
    /*  prediction horizon */
    /*  predict non-delayed state */
    /* '<S79>:1:14' */
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
    /* '<S79>:1:21' */
    for (k = 0; k < 30; k++) {
      temp[k] = 0.0;
      temp[k] += controller_template_P.LL_PP_Value_j[(k << 1)] * temp_idx;
      temp[k] += controller_template_P.LL_PP_Value_j[(k << 1) + 1] * temp_idx_0;
      tmp_2[k] = 0.0;
      for (minreg = 0; minreg < 62; minreg++) {
        tmp_2[k] += controller_template_P.LL_ref_PP_Value_h[62 * k + minreg] *
          controller_template_B.X_ref_z[minreg];
      }
    }

    for (k = 0; k < 30; k++) {
      u = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        u += controller_template_P.LL_U_ref_PP_Value_o[30 * k + minreg] * 0.0;
      }

      LL_PP_ref[k] = (temp[k] - tmp_2[k]) - u;
    }

    /* '<S79>:1:22' */
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
    yaw_rate_cmd_g = 1.0 / controller_template_P.L_Value_m;
    for (k = 0; k < 30; k++) {
      u = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        u += controller_template_P.TT_PP_Value_b[30 * minreg + k] *
          controller_template_DWork.UnitDelay1_DSTATE_g[minreg];
      }

      tmp_2[k] = u + LL_PP_ref[k];
    }

    for (k = 0; k < 30; k++) {
      rtb_Add = controller_template_DWork.UnitDelay1_DSTATE_g[k] -
        yaw_rate_cmd_g * tmp_2[k];
      u = (controller_template_P.V_max_Value_i[k] <= rtb_Add) || rtIsNaN(rtb_Add)
        ? controller_template_P.V_max_Value_i[k] : rtb_Add;
      MM_ref = (temp[k] >= u) || rtIsNaN(u) ? temp[k] : u;
      V_ip[k] = MM_ref;
      V_i[k] = MM_ref;
      U_star[k] = rtb_Add;
    }

    /*  now run the fast gradient method: */
    for (i = 0; i <= (int32_T)controller_template_P.i_min_Value_o - 1; i++) {
      for (k = 0; k < 30; k++) {
        u = 0.0;
        for (minreg = 0; minreg < 30; minreg++) {
          u += controller_template_P.TT_PP_Value_b[30 * minreg + k] *
            V_ip[minreg];
        }

        tmp_2[k] = u + LL_PP_ref[k];
      }

      /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
      /*      convergence result idea */
      for (k = 0; k < 30; k++) {
        rtb_Add = V_ip[k] - yaw_rate_cmd_g * tmp_2[k];
        u = (controller_template_P.V_max_Value_i[k] <= rtb_Add) || rtIsNaN
          (rtb_Add) ? controller_template_P.V_max_Value_i[k] : rtb_Add;
        u = (temp[k] >= u) || rtIsNaN(u) ? temp[k] : u;
        rtb_Add = controller_template_P.betas_Value_g[(int32_T)(1.0 + (real_T)i)
          - 1] * (u - V_i[k]);
        MM_ref = u;
        u += rtb_Add;
        U_star[k] = rtb_Add;
        V_i[k] = MM_ref;
        V_ip[k] = u;
      }
    }

    /*  return values: */
    yaw_rate_cmd_g = 0.0;
    rtb_Add = 0.0;

    /*  plot(residuals) just for testing new convergence result idea */
    /* '<S79>:1:25' */
    /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
    /*  so don't forget to backtransform after termination: */
    /* '<S79>:1:32' */
    for (k = 0; k < 30; k++) {
      b_y[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        b_y[k] += controller_template_P.TT_PP_Value_b[30 * k + minreg] * (0.5 *
          V_i[minreg]);
      }

      yaw_rate_cmd_g += b_y[k] * V_i[k];
      rtb_Add += LL_PP_ref[k] * V_i[k];
      U_star[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        U_star[k] += controller_template_P.PP_Value_o[30 * minreg + k] *
          V_i[minreg];
      }
    }

    /*  save outputs for delayed system */
    /* '<S79>:1:38' */
    /*  set new initial guess */
    /* '<S79>:1:42' */
    /* '<S79>:1:44' */
    controller_template_B.u_opt = U_star[0];
    controller_template_B.J_star = ((temp_idx *
      controller_template_P.MM_Value_l[0] + temp_idx_0 *
      controller_template_P.MM_Value_l[1]) * temp_idx + (temp_idx *
      controller_template_P.MM_Value_l[2] + temp_idx_0 *
      controller_template_P.MM_Value_l[3]) * temp_idx_0) + (yaw_rate_cmd_g +
      rtb_Add);
    controller_template_B.u_buff_out[0] =
      controller_template_DWork.UnitDelay_DSTATE_l[1];
    controller_template_B.u_buff_out[1] = U_star[0];
    memcpy((void *)(&controller_template_B.V_init_out[0]), (void *)&V_i[1], 29U *
           sizeof(real_T));
    controller_template_B.V_init_out[29] = 0.0;

    /* End of MATLAB Function: '<S68>/runFastGradient' */

    /* Saturate: '<S69>/Saturation' */
    rtb_Saturation_n =
      controller_template_B.sf_discretekalmanfilter_k.state_est[2] >=
      controller_template_P.Saturation_UpperSat_l ?
      controller_template_P.Saturation_UpperSat_l :
      controller_template_B.sf_discretekalmanfilter_k.state_est[2] <=
      controller_template_P.Saturation_LowerSat_c ?
      controller_template_P.Saturation_LowerSat_c :
      controller_template_B.sf_discretekalmanfilter_k.state_est[2];

    /* Sum: '<S56>/Sum2' */
    rtb_Product_l = controller_template_B.u_opt - rtb_Saturation_n;

    /* UnitDelay: '<S67>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_n[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_lx, 9U * sizeof(real_T));

    /* Switch: '<S77>/Init' incorporates:
     *  UnitDelay: '<S77>/FixPt Unit Delay1'
     *  UnitDelay: '<S77>/FixPt Unit Delay2'
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

    /* End of Switch: '<S77>/Init' */

    /* MATLAB Function: '<S67>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.DataTypeConversion[8],
      controller_template_B.DataTypeConversion[11], rtb_Init_h, rtb_Init[3],
      controller_template_P.A_Value_k, controller_template_P.B_Value_f,
      controller_template_P.C_Value_b, controller_template_P.Q_Value_g,
      controller_template_P.R_Value_o, rtb_IntegerDelay3, rtb_UnitDelay1_n,
      &controller_template_B.sf_discretekalmanfilter_n,
      &controller_template_DWork.sf_discretekalmanfilter_n);

    /* MATLAB Function: '<S66>/runFastGradient' incorporates:
     *  Constant: '<S66>/AA_delay'
     *  Constant: '<S66>/BB_delay'
     *  Constant: '<S66>/L'
     *  Constant: '<S66>/LL_PP'
     *  Constant: '<S66>/LL_U_ref_PP'
     *  Constant: '<S66>/LL_ref_PP'
     *  Constant: '<S66>/MM'
     *  Constant: '<S66>/PP'
     *  Constant: '<S66>/TT_PP'
     *  Constant: '<S66>/V_max'
     *  Constant: '<S66>/betas'
     *  Constant: '<S66>/i_min'
     *  UnitDelay: '<S66>/Unit Delay'
     *  UnitDelay: '<S66>/Unit Delay1'
     */
    controller_template_DWork.sfEvent_n = CALL_EVENT;

    /* MATLAB Function 'yaw controller MPC FG/runFastGradient': '<S76>:1' */
    /*  ugly, but simulink needs fix output sizes for vectors */
    /*  number of outputs u */
    /*  number of delay steps */
    /*  prediction horizon */
    /*  predict non-delayed state */
    /* '<S76>:1:14' */
    for (k = 0; k < 2; k++) {
      tmp_3[k] = 0.0;
      for (minreg = 0; minreg < 6; minreg++) {
        tmp_3[k] += controller_template_P.BB_delay_Value_d[(minreg << 1) + k] *
          controller_template_DWork.UnitDelay_DSTATE_jz[minreg];
      }
    }

    temp_idx = (controller_template_P.AA_delay_Value_o[0] *
                controller_template_B.sf_discretekalmanfilter_n.state_est[0] +
                controller_template_P.AA_delay_Value_o[2] *
                controller_template_B.sf_discretekalmanfilter_n.state_est[1]) +
      tmp_3[0];
    temp_idx_0 = (controller_template_P.AA_delay_Value_o[1] *
                  controller_template_B.sf_discretekalmanfilter_n.state_est[0] +
                  controller_template_P.AA_delay_Value_o[3] *
                  controller_template_B.sf_discretekalmanfilter_n.state_est[1])
      + tmp_3[1];

    /*  TODO get U_ref from trajectory */
    /*  set optimization variables */
    /* '<S76>:1:21' */
    for (k = 0; k < 30; k++) {
      temp[k] = 0.0;
      temp[k] += controller_template_P.LL_PP_Value_j5[(k << 1)] * temp_idx;
      temp[k] += controller_template_P.LL_PP_Value_j5[(k << 1) + 1] * temp_idx_0;
      tmp_2[k] = 0.0;
      for (minreg = 0; minreg < 62; minreg++) {
        tmp_2[k] += controller_template_P.LL_ref_PP_Value_e[62 * k + minreg] *
          controller_template_B.X_ref_yaw[minreg];
      }
    }

    for (k = 0; k < 30; k++) {
      u = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        u += controller_template_P.LL_U_ref_PP_Value_b[30 * k + minreg] * 0.0;
      }

      LL_PP_ref[k] = (temp[k] - tmp_2[k]) - u;
    }

    /* '<S76>:1:22' */
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
    yaw_rate_cmd_g = 1.0 / controller_template_P.L_Value_g;
    for (k = 0; k < 30; k++) {
      u = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        u += controller_template_P.TT_PP_Value_o[30 * minreg + k] *
          controller_template_DWork.UnitDelay1_DSTATE_js[minreg];
      }

      tmp_2[k] = u + LL_PP_ref[k];
    }

    for (k = 0; k < 30; k++) {
      rtb_Add = controller_template_DWork.UnitDelay1_DSTATE_js[k] -
        yaw_rate_cmd_g * tmp_2[k];
      u = (controller_template_P.V_max_Value_f[k] <= rtb_Add) || rtIsNaN(rtb_Add)
        ? controller_template_P.V_max_Value_f[k] : rtb_Add;
      MM_ref = (temp[k] >= u) || rtIsNaN(u) ? temp[k] : u;
      V_ip[k] = MM_ref;
      V_i[k] = MM_ref;
      U_star[k] = rtb_Add;
    }

    /*  now run the fast gradient method: */
    for (i = 0; i <= (int32_T)controller_template_P.i_min_Value_n - 1; i++) {
      for (k = 0; k < 30; k++) {
        u = 0.0;
        for (minreg = 0; minreg < 30; minreg++) {
          u += controller_template_P.TT_PP_Value_o[30 * minreg + k] *
            V_ip[minreg];
        }

        tmp_2[k] = u + LL_PP_ref[k];
      }

      /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
      /*      convergence result idea */
      for (k = 0; k < 30; k++) {
        rtb_Add = V_ip[k] - yaw_rate_cmd_g * tmp_2[k];
        u = (controller_template_P.V_max_Value_f[k] <= rtb_Add) || rtIsNaN
          (rtb_Add) ? controller_template_P.V_max_Value_f[k] : rtb_Add;
        u = (temp[k] >= u) || rtIsNaN(u) ? temp[k] : u;
        rtb_Add = controller_template_P.betas_Value_j[(int32_T)(1.0 + (real_T)i)
          - 1] * (u - V_i[k]);
        MM_ref = u;
        u += rtb_Add;
        U_star[k] = rtb_Add;
        V_i[k] = MM_ref;
        V_ip[k] = u;
      }
    }

    /*  return values: */
    yaw_rate_cmd_g = 0.0;
    rtb_Add = 0.0;

    /*  plot(residuals) just for testing new convergence result idea */
    /* '<S76>:1:25' */
    /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
    /*  so don't forget to backtransform after termination: */
    /* '<S76>:1:32' */
    for (k = 0; k < 30; k++) {
      b_y[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        b_y[k] += controller_template_P.TT_PP_Value_o[30 * k + minreg] * (0.5 *
          V_i[minreg]);
      }

      yaw_rate_cmd_g += b_y[k] * V_i[k];
      rtb_Add += LL_PP_ref[k] * V_i[k];
      U_star[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        U_star[k] += controller_template_P.PP_Value_p[30 * minreg + k] *
          V_i[minreg];
      }
    }

    /*  save outputs for delayed system */
    /* '<S76>:1:38' */
    /*  set new initial guess */
    /* '<S76>:1:42' */
    /* '<S76>:1:44' */
    controller_template_B.u_opt_l = U_star[0];
    controller_template_B.J_star_h = ((temp_idx *
      controller_template_P.MM_Value_g[0] + temp_idx_0 *
      controller_template_P.MM_Value_g[1]) * temp_idx + (temp_idx *
      controller_template_P.MM_Value_g[2] + temp_idx_0 *
      controller_template_P.MM_Value_g[3]) * temp_idx_0) + (yaw_rate_cmd_g +
      rtb_Add);
    for (i = 0; i < 5; i++) {
      controller_template_B.u_buff_out_i[i] =
        controller_template_DWork.UnitDelay_DSTATE_jz[i + 1];
    }

    controller_template_B.u_buff_out_i[5] = U_star[0];
    memcpy((void *)(&controller_template_B.V_init_out_n[0]), (void *)&V_i[1],
           29U * sizeof(real_T));
    controller_template_B.V_init_out_n[29] = 0.0;

    /* End of MATLAB Function: '<S66>/runFastGradient' */

    /* Saturate: '<S67>/Saturation' */
    yaw_rate_cmd_g = controller_template_B.sf_discretekalmanfilter_n.state_est[2]
      >= controller_template_P.Saturation_UpperSat_o3 ?
      controller_template_P.Saturation_UpperSat_o3 :
      controller_template_B.sf_discretekalmanfilter_n.state_est[2] <=
      controller_template_P.Saturation_LowerSat_kn ?
      controller_template_P.Saturation_LowerSat_kn :
      controller_template_B.sf_discretekalmanfilter_n.state_est[2];

    /* Sum: '<S56>/Sum3' */
    rtb_Add = controller_template_B.u_opt_l - yaw_rate_cmd_g;

    /* Sum: '<S56>/Sum5' */
    controller_template_B.thrust_cmd_e = rtb_Product_l + rtb_roll_cmd_c;

    /* Update for Delay: '<S56>/Integer Delay' */
    controller_template_DWork.IntegerDelay_DSTATE = abspos;

    /* Update for Delay: '<S56>/Integer Delay1' */
    controller_template_DWork.IntegerDelay1_DSTATE = roll_cmd_f;

    /* Update for Delay: '<S56>/Integer Delay2' */
    controller_template_DWork.IntegerDelay2_DSTATE = rtb_Product_l;

    /* Update for Delay: '<S56>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE = rtb_Add;

    /* Update for UnitDelay: '<S63>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
           (&controller_template_B.sf_discretekalmanfilter_b.P_est[0]), sizeof
           (real_T) << 4U);

    /* Update for UnitDelay: '<S71>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S71>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
      controller_template_P.FixPtConstant_Value_h;

    /* Update for UnitDelay: '<S71>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
      controller_template_B.sf_discretekalmanfilter_b.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
      controller_template_B.sf_discretekalmanfilter_b.state_est[1];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
      controller_template_B.sf_discretekalmanfilter_b.state_est[2];

    /* Update for UnitDelay: '<S62>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE[0] =
      controller_template_B.sf_runFastGradient.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE[1] =
      controller_template_B.sf_runFastGradient.u_buff_out[1];
    controller_template_DWork.UnitDelay_DSTATE[2] =
      controller_template_B.sf_runFastGradient.u_buff_out[2];

    /* Update for UnitDelay: '<S62>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
           (&controller_template_B.sf_runFastGradient.V_init_out[0]), 30U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S65>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
           (&controller_template_B.sf_discretekalmanfilter_m.P_est[0]), sizeof
           (real_T) << 4U);

    /* Update for UnitDelay: '<S74>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S74>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
      controller_template_P.FixPtConstant_Value_o;

    /* Update for UnitDelay: '<S74>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[1];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[2];

    /* Update for UnitDelay: '<S64>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_j[0] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE_j[1] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[1];
    controller_template_DWork.UnitDelay_DSTATE_j[2] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[2];

    /* Update for UnitDelay: '<S64>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
           (&controller_template_B.sf_runFastGradient_d.V_init_out[0]), 30U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S69>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
           (&controller_template_B.sf_discretekalmanfilter_k.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S80>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S80>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
      controller_template_P.FixPtConstant_Value_p;

    /* Update for UnitDelay: '<S80>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
      controller_template_B.sf_discretekalmanfilter_k.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
      controller_template_B.sf_discretekalmanfilter_k.state_est[1];

    /* Update for UnitDelay: '<S68>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_l[0] =
      controller_template_B.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE_l[1] =
      controller_template_B.u_buff_out[1];

    /* Update for UnitDelay: '<S68>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
           (&controller_template_B.V_init_out[0]), 30U * sizeof(real_T));

    /* Update for UnitDelay: '<S67>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
           (&controller_template_B.sf_discretekalmanfilter_n.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S77>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S77>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
      controller_template_P.FixPtConstant_Value_n;

    /* Update for UnitDelay: '<S77>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[1];

    /* Update for UnitDelay: '<S66>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      controller_template_DWork.UnitDelay_DSTATE_jz[i] =
        controller_template_B.u_buff_out_i[i];
    }

    /* End of Update for UnitDelay: '<S66>/Unit Delay' */

    /* Update for UnitDelay: '<S66>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
           (&controller_template_B.V_init_out_n[0]), 30U * sizeof(real_T));

    /* End of Outputs for SubSystem: '<S9>/MAIN CONTROL LOOP1' */

    /* SignalConversion: '<S60>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFi_f[0] =
      controller_template_B.DataTypeConversion[0];
    rtb_TmpSignalConversionAtToFi_f[1] =
      controller_template_B.DataTypeConversion[3];
    rtb_TmpSignalConversionAtToFi_f[2] =
      controller_template_B.DataTypeConversion[7];
    rtb_TmpSignalConversionAtToFi_f[3] = controller_template_B.X_ref_x[0];
    rtb_TmpSignalConversionAtToFi_f[4] = abspos;
    rtb_TmpSignalConversionAtToFi_f[5] =
      controller_template_B.DataTypeConversion[1];
    rtb_TmpSignalConversionAtToFi_f[6] =
      controller_template_B.DataTypeConversion[4];
    rtb_TmpSignalConversionAtToFi_f[7] =
      controller_template_B.DataTypeConversion[6];
    rtb_TmpSignalConversionAtToFi_f[8] = controller_template_B.X_ref_y[0];
    rtb_TmpSignalConversionAtToFi_f[9] = roll_cmd_f;
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

    /* ToFile: '<S60>/To File' */
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

    /* SignalConversion: '<S60>/TmpSignal ConversionAtTo File1Inport1' */
    rtb_TmpSignalConversionAtToFile[0] = tolerance;
    rtb_TmpSignalConversionAtToFile[1] = rtb_pitch_cmd_b;
    rtb_TmpSignalConversionAtToFile[2] = rtb_Saturation_n;
    rtb_TmpSignalConversionAtToFile[3] = yaw_rate_cmd_g;

    /* ToFile: '<S60>/To File1' */
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

    /* Gain: '<S60>/rad -> deg2' */
    controller_template_B.raddeg2[0] = controller_template_P.raddeg2_Gain_p *
      controller_template_B.DataTypeConversion[7];
    controller_template_B.raddeg2[1] = controller_template_P.raddeg2_Gain_p *
      controller_template_B.DataTypeConversion[10];
    controller_template_B.raddeg2[2] = controller_template_P.raddeg2_Gain_p *
      abspos;

    /* Gain: '<S60>/rad -> deg1' */
    controller_template_B.raddeg1[0] = controller_template_P.raddeg1_Gain_a *
      controller_template_B.DataTypeConversion[6];
    controller_template_B.raddeg1[1] = controller_template_P.raddeg1_Gain_a *
      controller_template_B.DataTypeConversion[9];
    controller_template_B.raddeg1[2] = controller_template_P.raddeg1_Gain_a *
      roll_cmd_f;

    /* Gain: '<S60>/rad -> deg3' */
    controller_template_B.raddeg3[0] = controller_template_P.raddeg3_Gain_k *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg3[1] = controller_template_P.raddeg3_Gain_k *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg3[2] = controller_template_P.raddeg3_Gain_k *
      rtb_Add;

    /* Gain: '<S60>/rad -> deg' */
    controller_template_B.raddeg[0] = controller_template_P.raddeg_Gain_k *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg[1] = controller_template_P.raddeg_Gain_k *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg[2] = controller_template_P.raddeg_Gain_k *
      controller_template_B.X_ref_yaw[0];
    controller_template_B.raddeg[3] = controller_template_P.raddeg_Gain_k *
      controller_template_B.X_ref_yaw[1];

    /* Outputs for Atomic SubSystem: '<S9>/decoupling and rotation' */
    /* Inport: '<S57>/bias_W' */
    controller_template_B.bias_W[0] = rtb_TmpSignalConversionAtToFile[0];
    controller_template_B.bias_W[1] = rtb_TmpSignalConversionAtToFile[1];
    controller_template_B.bias_W[2] = rtb_TmpSignalConversionAtToFile[2];
    controller_template_B.bias_W[3] = rtb_TmpSignalConversionAtToFile[3];

    /* Inport: '<S57>/cmd_W' */
    controller_template_B.cmd_W[0] = abspos;
    controller_template_B.cmd_W[1] = roll_cmd_f;
    controller_template_B.cmd_W[2] = controller_template_B.thrust_cmd_e;
    controller_template_B.cmd_W[3] = rtb_Add;

    /* MATLAB Function: '<S82>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S82>/g'
     */
    controller_template_DWork.sfEvent_f = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/decoupling /Embedded MATLAB Function': '<S84>:1' */
    /* '<S84>:1:4' */
    yaw_rate_cmd_g = controller_template_B.cmd_W[2] / (cos
      (controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_rot) * cos
      (controller_template_B.sf_EmbeddedMATLABFunction_o.roll_rot));

    /* '<S84>:1:6' */
    controller_template_B.pitch_cmd_comp =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value_m / yaw_rate_cmd_g *
      controller_template_B.cmd_W[0];

    /* '<S84>:1:7' */
    controller_template_B.roll_cmd_comp =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value_m / yaw_rate_cmd_g *
      controller_template_B.cmd_W[1];

    /*  pitch_cmd_comp=pitch_cmd; */
    /*  roll_cmd_comp=roll_cmd; */
    /*  pitch_cmd_comp = atan(Fx/(-thrust_comp)); */
    /*  roll_cmd_comp = atan(Fy/(thrust_comp)); */
    /*  pitch_cmd_comp = atan(-g*m*pitch_cmd/(-thrust)); */
    /*  roll_cmd_comp = atan(g*m*roll_cmd*cos(pitch_meas)/(thrust)); */
    controller_template_B.thrust_comp = yaw_rate_cmd_g;

    /* MATLAB Function: '<S83>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S85>:1' */
    /* '<S85>:1:3' */
    yaw_rate_cmd_g = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S85>:1:4' */
    rtb_Add = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S85>:1:6' */
    /* '<S85>:1:8' */
    /* '<S85>:1:9' */
    controller_template_B.pitch_rot = rtb_Add *
      controller_template_B.pitch_cmd_comp + -yaw_rate_cmd_g *
      controller_template_B.roll_cmd_comp;

    /* '<S85>:1:10' */
    controller_template_B.roll_rot = yaw_rate_cmd_g *
      controller_template_B.pitch_cmd_comp + rtb_Add *
      controller_template_B.roll_cmd_comp;

    /* '<S85>:1:12' */
    /* '<S85>:1:13' */
    controller_template_B.pitch_bias_rot = rtb_Add *
      controller_template_B.bias_W[0] + -yaw_rate_cmd_g *
      controller_template_B.bias_W[1];

    /* '<S85>:1:14' */
    controller_template_B.roll_bias_rot = yaw_rate_cmd_g *
      controller_template_B.bias_W[0] + rtb_Add * controller_template_B.bias_W[1];

    /* End of Outputs for SubSystem: '<S9>/decoupling and rotation' */
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

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/gravity'
   */
  yaw_rate_cmd_g = controller_template_P.gravity_Value_ch *
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

  /* Switch: '<S54>/SwitchControl' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S7>/yaw_rate'
   *  Gain: '<S7>/yaw_cmd2yaw'
   */
  if (controller_template_P.Constant_Value_a3 >
      controller_template_P.SwitchControl_Threshold_e) {
    rtb_Add = controller_template_P.yaw_cmd2yaw_Gain *
      controller_template_B.yaw_rate_cmd;
  } else {
    rtb_Add = controller_template_P.yaw_rate_Value;
  }

  /* End of Switch: '<S54>/SwitchControl' */

  /* Gain: '<S7>/Gain4' */
  rtb_Add *= controller_template_P.Gain4_Gain;

  /* Outport: '<Root>/cmd_out' incorporates:
   *  Constant: '<S7>/pitch_offset'
   *  Constant: '<S7>/roll_offset'
   *  DataTypeConversion: '<S7>/Data Type Conversion'
   *  Gain: '<S7>/Gain'
   *  Gain: '<S7>/Gain1'
   *  Gain: '<S7>/Gain2'
   *  Gain: '<S7>/Gain3'
   *  Gain: '<S7>/pitch_cmd2pitch'
   *  Gain: '<S7>/roll_cmd2roll'
   *  Gain: '<S7>/trhust_cmd2thrust'
   *  Sum: '<S7>/Sum'
   *  Sum: '<S7>/Sum1'
   *  Sum: '<S7>/Sum2'
   *  Sum: '<S7>/Sum3'
   */
  arg_cmd_out[0] = (real32_T)((controller_template_B.pitch_cmd -
    controller_template_P.pitch_offset_Value) *
    controller_template_P.pitch_cmd2pitch_Gain *
    controller_template_P.Gain1_Gain);
  arg_cmd_out[1] = (real32_T)((controller_template_B.roll_cmd -
    controller_template_P.roll_offset_Value) *
    controller_template_P.roll_cmd2roll_Gain * controller_template_P.Gain2_Gain);
  arg_cmd_out[2] = (real32_T)(((controller_template_B.thrust_cmd -
    yaw_rate_cmd_g) * controller_template_P.trhust_cmd2thrust_Gain +
    yaw_rate_cmd_g) * controller_template_P.Gain_Gain_k *
    controller_template_P.Gain3_Gain);
  arg_cmd_out[3] = (real32_T)rtb_Add;

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

  /* Update for UnitDelay: '<S55>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S55>/FixPt Constant'
   */
  controller_template_DWork.FixPtUnitDelay2_DSTATE =
    controller_template_P.FixPtConstant_Value_i;

  /* Switch: '<S55>/Reset' */
  if (rtb_MultiportSwitch1 != 0.0) {
    /* Update for UnitDelay: '<S55>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S55>/Initial Condition'
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
    /* Update for UnitDelay: '<S55>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE[0] =
      controller_template_B.pitch_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[1] =
      controller_template_B.roll_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[2] =
      controller_template_B.thrust_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[3] =
      controller_template_B.yaw_rate_bias;
  }

  /* End of Switch: '<S55>/Reset' */

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
  controller_template_M->Sizes.checksums[0] = (2810885480U);
  controller_template_M->Sizes.checksums[1] = (93825254U);
  controller_template_M->Sizes.checksums[2] = (2053453503U);
  controller_template_M->Sizes.checksums[3] = (1180289107U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[52];
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
    systemRan[15] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
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
    systemRan[33] = &rtAlwaysEnabled;
    systemRan[34] = &rtAlwaysEnabled;
    systemRan[35] = &rtAlwaysEnabled;
    systemRan[36] = &rtAlwaysEnabled;
    systemRan[37] = &rtAlwaysEnabled;
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
    systemRan[47] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[49] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[50] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[51] = (sysRanDType *)
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
    /* Start for UnitDelay: '<S21>/Unit Delay2' */
    controller_template_B.UnitDelay2 = controller_template_P.UnitDelay2_X0;

    /* Start for UnitDelay: '<S30>/Unit Delay2' */
    controller_template_B.UnitDelay2_o = controller_template_P.UnitDelay2_X0_d;

    /* End of Start for SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* Start for ToFile: '<S14>/To File' */
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

    /* Start for ToFile: '<S14>/To File1' */
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

    /* InitializeConditions for MATLAB Function: '<S13>/Embedded MATLAB Function' */
    con_EmbeddedMATLABFunction_Init
      (&controller_template_DWork.sf_EmbeddedMATLABFunction);

    /* InitializeConditions for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* InitializeConditions for Delay: '<S10>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE_k =
      controller_template_P.IntegerDelay3_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S19>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_bg, (void *)
           controller_template_P.UnitDelay1_X0, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S44>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
      controller_template_P.FixPtUnitDelay2_X0;

    /* InitializeConditions for UnitDelay: '<S44>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0] =
      controller_template_P.FixPtUnitDelay1_X0;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1] =
      controller_template_P.FixPtUnitDelay1_X0;

    /* InitializeConditions for MATLAB Function: '<S19>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter);

    /* InitializeConditions for MATLAB Function: '<S16>/MATLAB Function' */
    controller_template_DWork.sfEvent_fk = CALL_EVENT;
    controller_template_DWork.is_active_c8_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S21>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE =
      controller_template_P.UnitDelay2_X0;

    /* InitializeConditions for MATLAB Function: '<S28>/MATLAB Function' */
    controller_template_DWork.sfEvent_cm = CALL_EVENT;
    controller_template_DWork.is_active_c7_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S21>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_kl = CALL_EVENT;
    controller_template_DWork.is_active_c1_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S23>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_d =
      controller_template_P.UnitDelay2_X0_m;

    /* InitializeConditions for UnitDelay: '<S23>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_jv =
      controller_template_P.UnitDelay_X0;

    /* InitializeConditions for UnitDelay: '<S30>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_l =
      controller_template_P.UnitDelay2_X0_d;

    /* InitializeConditions for MATLAB Function: '<S35>/MATLAB Function' */
    controller_template_DWork.sfEvent_i = CALL_EVENT;
    controller_template_DWork.is_active_c5_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S30>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_cd = CALL_EVENT;
    controller_template_DWork.is_active_c2_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S31>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_k =
      controller_template_P.UnitDelay2_X0_n;

    /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_f =
      controller_template_P.UnitDelay_X0_f;

    /* InitializeConditions for MATLAB Function: '<S46>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_k0 = CALL_EVENT;
    controller_template_DWork.is_active_c3_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S47>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_b =
      controller_template_P.UnitDelay2_X0_o;

    /* InitializeConditions for UnitDelay: '<S47>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_fw =
      controller_template_P.UnitDelay_X0_i;

    /* InitializeConditions for UnitDelay: '<S37>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_g =
      controller_template_P.UnitDelay2_X0_ng;

    /* InitializeConditions for MATLAB Function: '<S42>/MATLAB Function' */
    controller_template_DWork.sfEvent_l = CALL_EVENT;
    controller_template_DWork.is_active_c6_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S37>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_jv = CALL_EVENT;
    controller_template_DWork.is_active_c4_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S38>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_ga =
      controller_template_P.UnitDelay2_X0_i;

    /* InitializeConditions for UnitDelay: '<S38>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_p =
      controller_template_P.UnitDelay_X0_c;

    /* InitializeConditions for UnitDelay: '<S23>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_a =
      controller_template_P.UnitDelay1_X0_i;

    /* InitializeConditions for UnitDelay: '<S31>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_ji =
      controller_template_P.UnitDelay1_X0_d;

    /* InitializeConditions for UnitDelay: '<S38>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_c3 =
      controller_template_P.UnitDelay1_X0_j;

    /* InitializeConditions for UnitDelay: '<S47>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_m =
      controller_template_P.UnitDelay1_X0_f;

    /* End of InitializeConditions for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

    /* InitializeConditions for Atomic SubSystem: '<S2>/decoupling and rotation' */
    /* InitializeConditions for MATLAB Function: '<S49>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_c = CALL_EVENT;
    controller_template_DWork.is_active_c9_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S50>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_j = CALL_EVENT;
    controller_template_DWork.is_active_c10_controller_templa = 0U;

    /* End of InitializeConditions for SubSystem: '<S2>/decoupling and rotation' */
    /* End of Start for SubSystem: '<Root>/FreeFlight Pos Ctrl' */

    /* Start for Enabled SubSystem: '<Root>/pos controller' */
    /* Start for ToFile: '<S60>/To File' */
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

    /* Start for ToFile: '<S60>/To File1' */
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

    /* InitializeConditions for MATLAB Function: '<S59>/Embedded MATLAB Function' */
    con_EmbeddedMATLABFunction_Init
      (&controller_template_DWork.sf_EmbeddedMATLABFunction_o);

    /* InitializeConditions for Atomic SubSystem: '<S9>/MAIN CONTROL LOOP1' */
    /* InitializeConditions for Delay: '<S56>/Integer Delay' */
    controller_template_DWork.IntegerDelay_DSTATE =
      controller_template_P.IntegerDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S56>/Integer Delay1' */
    controller_template_DWork.IntegerDelay1_DSTATE =
      controller_template_P.IntegerDelay1_InitialCondition;

    /* InitializeConditions for Delay: '<S56>/Integer Delay2' */
    controller_template_DWork.IntegerDelay2_DSTATE =
      controller_template_P.IntegerDelay2_InitialCondition;

    /* InitializeConditions for Delay: '<S56>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE =
      controller_template_P.IntegerDelay3_InitialConditio_c;

    /* InitializeConditions for UnitDelay: '<S63>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
           controller_template_P.UnitDelay1_X0_c, sizeof(real_T) << 4U);

    /* InitializeConditions for UnitDelay: '<S71>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
      controller_template_P.FixPtUnitDelay2_X0_d;

    /* InitializeConditions for UnitDelay: '<S71>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
      controller_template_P.FixPtUnitDelay1_X0_f;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
      controller_template_P.FixPtUnitDelay1_X0_f;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
      controller_template_P.FixPtUnitDelay1_X0_f;

    /* InitializeConditions for MATLAB Function: '<S63>/discrete kalman filter' */
    con_discretekalmanfilter_k_Init
      (&controller_template_DWork.sf_discretekalmanfilter_b);

    /* InitializeConditions for UnitDelay: '<S62>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE[0] =
      controller_template_P.UnitDelay_X0_fc[0];
    controller_template_DWork.UnitDelay_DSTATE[1] =
      controller_template_P.UnitDelay_X0_fc[1];
    controller_template_DWork.UnitDelay_DSTATE[2] =
      controller_template_P.UnitDelay_X0_fc[2];

    /* InitializeConditions for UnitDelay: '<S62>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
           controller_template_P.UnitDelay1_X0_k, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S62>/runFastGradient' */
    controller_runFastGradient_Init
      (&controller_template_DWork.sf_runFastGradient);

    /* InitializeConditions for UnitDelay: '<S65>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
           controller_template_P.UnitDelay1_X0_fk, sizeof(real_T) << 4U);

    /* InitializeConditions for UnitDelay: '<S74>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
      controller_template_P.FixPtUnitDelay2_X0_n;

    /* InitializeConditions for UnitDelay: '<S74>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
      controller_template_P.FixPtUnitDelay1_X0_n;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
      controller_template_P.FixPtUnitDelay1_X0_n;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
      controller_template_P.FixPtUnitDelay1_X0_n;

    /* InitializeConditions for MATLAB Function: '<S65>/discrete kalman filter' */
    con_discretekalmanfilter_k_Init
      (&controller_template_DWork.sf_discretekalmanfilter_m);

    /* InitializeConditions for UnitDelay: '<S64>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_j[0] =
      controller_template_P.UnitDelay_X0_ik[0];
    controller_template_DWork.UnitDelay_DSTATE_j[1] =
      controller_template_P.UnitDelay_X0_ik[1];
    controller_template_DWork.UnitDelay_DSTATE_j[2] =
      controller_template_P.UnitDelay_X0_ik[2];

    /* InitializeConditions for UnitDelay: '<S64>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
           controller_template_P.UnitDelay1_X0_jc, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S64>/runFastGradient' */
    controller_runFastGradient_Init
      (&controller_template_DWork.sf_runFastGradient_d);

    /* InitializeConditions for UnitDelay: '<S69>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
           controller_template_P.UnitDelay1_X0_cw, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S80>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
      controller_template_P.FixPtUnitDelay2_X0_do;

    /* InitializeConditions for UnitDelay: '<S80>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
      controller_template_P.FixPtUnitDelay1_X0_c;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
      controller_template_P.FixPtUnitDelay1_X0_c;

    /* InitializeConditions for MATLAB Function: '<S69>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter_k);

    /* InitializeConditions for UnitDelay: '<S68>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_l[0] =
      controller_template_P.UnitDelay_X0_a[0];
    controller_template_DWork.UnitDelay_DSTATE_l[1] =
      controller_template_P.UnitDelay_X0_a[1];

    /* InitializeConditions for UnitDelay: '<S68>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
           controller_template_P.UnitDelay1_X0_b, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S68>/runFastGradient' */
    controller_template_DWork.sfEvent_k = CALL_EVENT;
    controller_template_DWork.is_active_c8_Hquad_control_LIB_ = 0U;

    /* InitializeConditions for UnitDelay: '<S67>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
           controller_template_P.UnitDelay1_X0_n, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S77>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
      controller_template_P.FixPtUnitDelay2_X0_i;

    /* InitializeConditions for UnitDelay: '<S77>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
      controller_template_P.FixPtUnitDelay1_X0_e;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
      controller_template_P.FixPtUnitDelay1_X0_e;

    /* InitializeConditions for MATLAB Function: '<S67>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter_n);

    /* InitializeConditions for UnitDelay: '<S66>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      controller_template_DWork.UnitDelay_DSTATE_jz[i] =
        controller_template_P.UnitDelay_X0_fj[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S66>/Unit Delay' */

    /* InitializeConditions for UnitDelay: '<S66>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
           controller_template_P.UnitDelay1_X0_o, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S66>/runFastGradient' */
    controller_template_DWork.sfEvent_n = CALL_EVENT;
    controller_template_DWork.is_active_c9_Hquad_control_LIB_ = 0U;

    /* End of InitializeConditions for SubSystem: '<S9>/MAIN CONTROL LOOP1' */

    /* InitializeConditions for Atomic SubSystem: '<S9>/decoupling and rotation' */
    /* InitializeConditions for MATLAB Function: '<S82>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_f = CALL_EVENT;
    controller_template_DWork.is_active_c1_Hquad_control_LIB_ = 0U;

    /* InitializeConditions for MATLAB Function: '<S83>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent = CALL_EVENT;
    controller_template_DWork.is_active_c4_Hquad_control_LIB_ = 0U;

    /* End of InitializeConditions for SubSystem: '<S9>/decoupling and rotation' */
    /* End of Start for SubSystem: '<Root>/pos controller' */
  }

  /* InitializeConditions for UnitDelay: '<S55>/FixPt Unit Delay2' */
  controller_template_DWork.FixPtUnitDelay2_DSTATE =
    controller_template_P.FixPtUnitDelay2_X0_g;

  /* InitializeConditions for UnitDelay: '<S55>/FixPt Unit Delay1' */
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

  /* Terminate for ToFile: '<S14>/To File' */
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

  /* Terminate for ToFile: '<S14>/To File1' */
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

  /* Terminate for ToFile: '<S60>/To File' */
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

  /* Terminate for ToFile: '<S60>/To File1' */
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
