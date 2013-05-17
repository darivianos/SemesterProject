/*
 * File: controller_template.cpp
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.465
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Aug  6 2011)
 * C/C++ source code generated on : Fri May 17 16:26:04 2013
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
static void controller_template_round_p(real_T x[4]);
static void controller_template_mrdivide_p(const real_T A[4], real_T B, real_T
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
 *    '<S20>/discrete kalman filter'
 *    '<S74>/discrete kalman filter'
 *    '<S76>/discrete kalman filter'
 */
void contr_discretekalmanfilter_Init(rtDW_discretekalmanfilter_contr *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c5_Hquad_control_LIB_ = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S20>/discrete kalman filter'
 *    '<S74>/discrete kalman filter'
 *    '<S76>/discrete kalman filter'
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

  /* MATLAB Function 'yaw states estimator bias/discrete kalman filter': '<S47>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S47>:1:10' */
  for (i = 0; i < 3; i++) {
    /* SignalConversion: '<S47>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = ((rtu_A[i + 3] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
            6] * rtu_state_g) + rtu_B[i] * rtu_u;
  }

  /* '<S47>:1:11' */
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
  /* '<S47>:1:14' */
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

  /* '<S47>:1:15' */
  /* '<S47>:1:16' */
  for (i = 0; i < 9; i++) {
    I[i] = 0;
  }

  I[0] = 1;
  I[4] = 1;
  I[8] = 1;
  for (i = 0; i < 2; i++) {
    tmp[i] = rtu_C[i + 4] * x[2] + (rtu_C[i + 2] * x[1] + rtu_C[i] * x[0]);
  }

  /* SignalConversion: '<S47>/TmpSignal ConversionAt SFunction Inport8' */
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
 *    '<S69>/runFastGradient'
 *    '<S71>/runFastGradient'
 */
void controller_runFastGradient_Init(rtDW_runFastGradient_controller *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c6_Hquad_control_LIB_ = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S69>/runFastGradient'
 *    '<S71>/runFastGradient'
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

  /* MATLAB Function 'x controller MPC FG  /runFastGradient': '<S77>:1' */
  /*  ugly, but simulink needs fix output sizes for vectors */
  /*  number of outputs u */
  /*  number of delay steps */
  /*  prediction horizon */
  /*  predict non-delayed state */
  /* '<S77>:1:14' */
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
  /* '<S77>:1:21' */
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

  /* '<S77>:1:22' */
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
  /* '<S77>:1:25' */
  /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
  /*  so don't forget to backtransform after termination: */
  /* '<S77>:1:32' */
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
  /* '<S77>:1:38' */
  /*  set new initial guess */
  /* '<S77>:1:42' */
  /* '<S77>:1:44' */
  localB->u_opt = U_star[0];
  localB->J_star = ((y[0] * x_predicted_idx + y[1] * x_predicted_idx_0) + y[2] *
                    x_predicted_idx_1) + (L_inv + d_y);
  localB->u_buff_out[0] = rtu_u_buff[1];
  localB->u_buff_out[1] = rtu_u_buff[2];
  localB->u_buff_out[2] = U_star[0];
  memcpy((void *)(&localB->V_init_out[0]), (void *)&V_i[1], 29U * sizeof(real_T));
  localB->V_init_out[29] = 0.0;
}

/* Function for MATLAB Function: '<S70>/discrete kalman filter' */
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
 *    '<S70>/discrete kalman filter'
 *    '<S72>/discrete kalman filter'
 */
void con_discretekalmanfilter_k_Init(rtDW_discretekalmanfilter_con_c *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c11_Hquad_control_LIB = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S70>/discrete kalman filter'
 *    '<S72>/discrete kalman filter'
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

  /* MATLAB Function 'x states estimator bias/discrete kalman filter': '<S79>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S79>:1:10' */
  for (i = 0; i < 4; i++) {
    /* SignalConversion: '<S79>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = (((rtu_A[i + 4] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
             8] * rtu_state[2]) + rtu_A[i + 12] * rtu_state_m) + rtu_B[i] *
      rtu_u;
  }

  /* '<S79>:1:11' */
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
  /* '<S79>:1:14' */
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

  /* '<S79>:1:15' */
  /* '<S79>:1:16' */
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

  /* SignalConversion: '<S79>/TmpSignal ConversionAt SFunction Inport8' */
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

/* Function for MATLAB Function: '<S22>/Ctrl_Xdir' */
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

/* Function for MATLAB Function: '<S22>/Ctrl_Xdir' */
static void controller_template_mrdivide(const real_T A[4], real_T B, real_T y[4])
{
  y[0] = A[0] / B;
  y[1] = A[1] / B;
  y[2] = A[2] / B;
  y[3] = A[3] / B;
}

/* Function for MATLAB Function: '<S31>/Ctrl_Xdir' */
static void controller_template_round_p(real_T x[4])
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

/* Function for MATLAB Function: '<S31>/Ctrl_Xdir' */
static void controller_template_mrdivide_p(const real_T A[4], real_T B, real_T
  y[4])
{
  y[0] = A[0] / B;
  y[1] = A[1] / B;
  y[2] = A[2] / B;
  y[3] = A[3] / B;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    y = u >= 0.5 ? floor(u + 0.5) : u > -0.5 ? u * 0.0 : ceil(u - 0.5);
  } else {
    y = u;
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  if (u1 == 0.0) {
    y = u0;
  } else if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf
                (u1))))) {
    y = (rtNaN);
  } else {
    tmp = u0 / u1;
    if (u1 <= floor(u1)) {
      y = u0 - floor(tmp) * u1;
    } else if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
      y = 0.0;
    } else {
      y = (tmp - floor(tmp)) * u1;
    }
  }

  return y;
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
  real_T rtb_IntegerDelay3_c;
  real_T rtb_bias_W[4];
  real_T rtb_UnitDelay1_d[9];
  real_T rtb_Init_jd[2];
  real_T rtb_TmpSignalConversionAtToFi_f[18];
  real_T rtb_TmpSignalConversionAtToFi_a[28];
  real_T sin_yaw;
  real_T cos_yaw;
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
  real_T U_star[30];
  real_T V_i[30];
  real_T V_ip[30];
  real_T b_y[30];
  real_T rtb_MultiportSwitch1;
  real_T rtb_MultiportSwitch2;
  real_T rtb_Product_l;
  real_T rtb_Saturation;
  real_T rtb_Saturation_p;
  real_T rtb_Saturation_n;
  real_T thrust_cmd_k;
  real_T pitch_cmd_b;
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

  /* Switch: '<S62>/Init' incorporates:
   *  Constant: '<S62>/Initial Condition'
   *  Logic: '<S62>/FixPt Logical Operator'
   *  UnitDelay: '<S62>/FixPt Unit Delay1'
   *  UnitDelay: '<S62>/FixPt Unit Delay2'
   */
  if ((rtb_MultiportSwitch1 != 0.0) ||
      (controller_template_DWork.FixPtUnitDelay2_DSTATE != 0)) {
    rtb_Init[0] = controller_template_P.InitialCondition_Value_b;
    rtb_Init[1] = controller_template_P.InitialCondition_Value_b;
    rtb_Init[2] = controller_template_P.InitialCondition_Value_b;
    rtb_Init[3] = controller_template_P.InitialCondition_Value_b;
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

  /* End of Switch: '<S62>/Init' */
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
      /* InitializeConditions for MATLAB Function: '<S14>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_bq = CALL_EVENT;
      controller_template_DWork.is_active_c26_Hquad_control_L_f = 0U;

      /* InitializeConditions for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
      /* InitializeConditions for Delay: '<S10>/Integer Delay3' */
      controller_template_DWork.IntegerDelay3_DSTATE_k =
        controller_template_P.IntegerDelay3_InitialCondition;

      /* InitializeConditions for MATLAB Function: '<S17>/MATLAB Function' */
      controller_template_DWork.sfEvent_fk = CALL_EVENT;
      controller_template_DWork.is_active_c8_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S22>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE =
        controller_template_P.UnitDelay2_X0;

      /* InitializeConditions for MATLAB Function: '<S29>/MATLAB Function' */
      controller_template_DWork.sfEvent_cm = CALL_EVENT;
      controller_template_DWork.is_active_c7_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S22>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_kl = CALL_EVENT;
      controller_template_DWork.is_active_c1_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_d =
        controller_template_P.UnitDelay2_X0_m;

      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_jv =
        controller_template_P.UnitDelay_X0;

      /* InitializeConditions for UnitDelay: '<S31>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_l =
        controller_template_P.UnitDelay2_X0_d;

      /* InitializeConditions for MATLAB Function: '<S36>/MATLAB Function' */
      controller_template_DWork.sfEvent_i = CALL_EVENT;
      controller_template_DWork.is_active_c5_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S31>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_cd = CALL_EVENT;
      controller_template_DWork.is_active_c2_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S32>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_k =
        controller_template_P.UnitDelay2_X0_n;

      /* InitializeConditions for UnitDelay: '<S32>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_f =
        controller_template_P.UnitDelay_X0_f;

      /* InitializeConditions for MATLAB Function: '<S48>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_k0 = CALL_EVENT;
      controller_template_DWork.is_active_c3_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S49>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_b =
        controller_template_P.UnitDelay2_X0_o;

      /* InitializeConditions for UnitDelay: '<S49>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_fw =
        controller_template_P.UnitDelay_X0_i;

      /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_bg, (void *)
             controller_template_P.UnitDelay1_X0, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
        controller_template_P.FixPtUnitDelay2_X0;

      /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0] =
        controller_template_P.FixPtUnitDelay1_X0;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1] =
        controller_template_P.FixPtUnitDelay1_X0;

      /* InitializeConditions for MATLAB Function: '<S20>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter);

      /* InitializeConditions for UnitDelay: '<S38>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_g =
        controller_template_P.UnitDelay2_X0_ng;

      /* InitializeConditions for MATLAB Function: '<S44>/MATLAB Function' */
      controller_template_DWork.sfEvent_l = CALL_EVENT;
      controller_template_DWork.is_active_c6_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S38>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_jv = CALL_EVENT;
      controller_template_DWork.is_active_c4_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S39>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_ga =
        controller_template_P.UnitDelay2_X0_i;

      /* InitializeConditions for UnitDelay: '<S39>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_p =
        controller_template_P.UnitDelay_X0_c;

      /* InitializeConditions for UnitDelay: '<S24>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_a =
        controller_template_P.UnitDelay1_X0_i;

      /* InitializeConditions for UnitDelay: '<S32>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_ji =
        controller_template_P.UnitDelay1_X0_d;

      /* InitializeConditions for UnitDelay: '<S39>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_c3 =
        controller_template_P.UnitDelay1_X0_j;

      /* InitializeConditions for UnitDelay: '<S49>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_m =
        controller_template_P.UnitDelay1_X0_f;

      /* End of InitializeConditions for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

      /* InitializeConditions for UnitDelay: '<S51>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_e =
        controller_template_P.FixPtUnitDelay2_X0_j;

      /* InitializeConditions for UnitDelay: '<S51>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_k =
        controller_template_P.FixPtUnitDelay1_X0_c;

      /* InitializeConditions for MATLAB Function: '<S11>/generate_X_ref_x' */
      controller_template_DWork.sfEvent_m = CALL_EVENT;
      controller_template_DWork.is_active_c2_Hquad_control_LIB_ = 0U;

      /* InitializeConditions for MATLAB Function: '<S11>/generate_X_ref_y' */
      controller_template_DWork.sfEvent_dw = CALL_EVENT;
      controller_template_DWork.is_active_c22_Hquad_control_LIB = 0U;

      /* InitializeConditions for MATLAB Function: '<S11>/generate_X_ref_yaw' */
      controller_template_DWork.sfEvent_h = CALL_EVENT;
      controller_template_DWork.is_active_c23_Hquad_control_LIB = 0U;

      /* InitializeConditions for MATLAB Function: '<S11>/generate_X_ref_z' */
      controller_template_DWork.sfEvent_d = CALL_EVENT;
      controller_template_DWork.is_active_c24_Hquad_control_LIB = 0U;

      /* InitializeConditions for Atomic SubSystem: '<S2>/decoupling and rotation' */
      /* InitializeConditions for MATLAB Function: '<S56>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_c = CALL_EVENT;
      controller_template_DWork.is_active_c1_Hquad_control_LI_l = 0U;

      /* InitializeConditions for MATLAB Function: '<S57>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_j = CALL_EVENT;
      controller_template_DWork.is_active_c4_Hquad_control_LI_d = 0U;

      /* End of InitializeConditions for SubSystem: '<S2>/decoupling and rotation' */
      controller_template_DWork.FreeFlightPosCtrl_MODE = TRUE;
    }

    /* MATLAB Function: '<S14>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_bq = CALL_EVENT;

    /* MATLAB Function 'rotate to world frame/Embedded MATLAB Function': '<S60>:1' */
    /* '<S60>:1:5' */
    sin_yaw = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S60>:1:6' */
    cos_yaw = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S60>:1:8' */
    /* '<S60>:1:10' */
    /* '<S60>:1:11' */
    controller_template_B.pitch_rot_i = cos_yaw *
      controller_template_B.DataTypeConversion[7] + sin_yaw *
      controller_template_B.DataTypeConversion[6];

    /* '<S60>:1:12' */
    controller_template_B.roll_rot_f = -sin_yaw *
      controller_template_B.DataTypeConversion[7] + cos_yaw *
      controller_template_B.DataTypeConversion[6];

    /* '<S60>:1:14' */
    /* '<S60>:1:15' */
    controller_template_B.pitch_bias_rot_p = cos_yaw * rtb_Init[0] + sin_yaw *
      rtb_Init[1];

    /* '<S60>:1:16' */
    controller_template_B.roll_bias_rot_n = -sin_yaw * rtb_Init[0] + cos_yaw *
      rtb_Init[1];

    /* Outputs for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* Delay: '<S10>/Integer Delay3' */
    rtb_IntegerDelay3_c = controller_template_DWork.IntegerDelay3_DSTATE_k;

    /* Product: '<S10>/Product' incorporates:
     *  Constant: '<S10>/gravity'
     */
    rtb_Product_l = controller_template_P.gravity_Value *
      controller_template_B.DataTypeConversion[29];

    /* Sum: '<S17>/Add' incorporates:
     *  Constant: '<S17>/Constant'
     *  Gain: '<S25>/Slider Gain'
     *  Gain: '<S26>/Slider Gain'
     *  Sum: '<S17>/Sum'
     */
    cos_yaw = controller_template_B.DataTypeConversion[0] -
      (controller_template_P.SliderGain_Gain * controller_template_B.X_ref_x[0]
       + controller_template_P.SliderGain_Gain_e *
       controller_template_P.Constant_Value_f);

    /* MATLAB Function: '<S17>/MATLAB Function' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Gain: '<S27>/Slider Gain'
     */
    controller_template_DWork.sfEvent_fk = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /MATLAB Function': '<S23>:1' */
    if (cos_yaw >= controller_template_P.SliderGain_Gain_f *
        controller_template_P.Constant1_Value_g) {
      /* '<S23>:1:3' */
      /* '<S23>:1:4' */
      controller_template_B.y_n = 0.0;
    } else {
      /* '<S23>:1:6' */
      controller_template_B.y_n = cos_yaw;
    }

    /* End of MATLAB Function: '<S17>/MATLAB Function' */

    /* Saturate: '<S17>/Saturation3' */
    controller_template_B.Saturation3 = controller_template_B.y_n >=
      controller_template_P.Saturation3_UpperSat ?
      controller_template_P.Saturation3_UpperSat : controller_template_B.y_n <=
      controller_template_P.Saturation3_LowerSat ?
      controller_template_P.Saturation3_LowerSat : controller_template_B.y_n;

    /* RateTransition: '<S22>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Saturate: '<S17>/Saturation' */
      controller_template_B.RateTransition[0] =
        controller_template_B.pitch_rot_i >=
        controller_template_P.Saturation_UpperSat ?
        controller_template_P.Saturation_UpperSat :
        controller_template_B.pitch_rot_i <=
        controller_template_P.Saturation_LowerSat ?
        controller_template_P.Saturation_LowerSat :
        controller_template_B.pitch_rot_i;

      /* Saturate: '<S17>/Saturation1' */
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

      /* Saturate: '<S17>/Saturation2' */
      controller_template_B.RateTransition[3] =
        controller_template_B.DataTypeConversion[3] >=
        controller_template_P.Saturation2_UpperSat ?
        controller_template_P.Saturation2_UpperSat :
        controller_template_B.DataTypeConversion[3] <=
        controller_template_P.Saturation2_LowerSat ?
        controller_template_P.Saturation2_LowerSat :
        controller_template_B.DataTypeConversion[3];

      /* UnitDelay: '<S22>/Unit Delay2' */
      controller_template_B.UnitDelay2 =
        controller_template_DWork.UnitDelay2_DSTATE;
    }

    /* End of RateTransition: '<S22>/Rate Transition' */

    /* MATLAB Function: '<S29>/MATLAB Function' */
    controller_template_DWork.sfEvent_cm = CALL_EVENT;

    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S29>/Constant'
     *  Constant: '<S29>/Constant2'
     *  MATLAB Function: '<S29>/MATLAB Function'
     */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/PitchPropagate/MATLAB Function': '<S30>:1' */
    /* '<S30>:1:4' */
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

    /* End of Switch: '<S29>/Switch' */

    /* Switch: '<S29>/Switch1' incorporates:
     *  Constant: '<S29>/Constant1'
     *  Constant: '<S29>/Constant3'
     *  MATLAB Function: '<S29>/MATLAB Function'
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

    /* End of Switch: '<S29>/Switch1' */

    /* MATLAB Function: '<S29>/MATLAB Function' */
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

    /* MATLAB Function: '<S22>/Ctrl_Xdir' incorporates:
     *  Constant: '<S22>/Constant'
     *  Constant: '<S22>/Constant1'
     *  Constant: '<S22>/Constant2'
     *  Constant: '<S22>/Constant3'
     *  Constant: '<S22>/Constant4'
     *  Saturate: '<S29>/Saturation'
     *  Saturate: '<S29>/Saturation1'
     *  Saturate: '<S29>/Saturation2'
     *  Saturate: '<S29>/Saturation3'
     */
    controller_template_DWork.sfEvent_kl = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/Ctrl_Xdir': '<S28>:1' */
    /* '<S28>:1:3' */
    tolerance = 1.0;

    /* '<S28>:1:5' */
    /* '<S28>:1:6' */
    minreg = -1;

    /* '<S28>:1:7' */
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

    /* '<S28>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S28>:1:12' */
    memset((void *)(&controller_template_B.Hi[0]), 0, 4000U * sizeof(real_T));

    /* '<S28>:1:13' */
    memset((void *)(&controller_template_B.Ki[0]), 0, 1000U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S28>:1:16' */
    abspos = 1.0;

    /* '<S28>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 346) {
        /* '<S28>:1:17' */
        /* '<S28>:1:18' */
        sin_yaw = 0.0;

        /* '<S28>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S28>:1:23' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value[ireg] -
             1; i++) {
          /* '<S28>:1:23' */
          /* '<S28>:1:24' */
          /* '<S28>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_o[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S28>:1:24' */
          /* '<S28>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)i) + 999] =
            controller_template_P.Constant_Value_o[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 3067];

          /* '<S28>:1:24' */
          /* '<S28>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)i) + 1999] =
            controller_template_P.Constant_Value_o[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 6135];

          /* '<S28>:1:24' */
          /* '<S28>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)i) + 2999] =
            controller_template_P.Constant_Value_o[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 9203];

          /* '<S28>:1:24' */
          /* '<S28>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S28>:1:30' */
        for (k = 0; k <= (int32_T)controller_template_P.Constant4_Value[ireg] -
             1; k++) {
          /* '<S28>:1:30' */
          /* '<S28>:1:31' */
          controller_template_B.Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_d[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S28>:1:30' */
        }

        /* '<S28>:1:33' */
        abspos += controller_template_P.Constant4_Value[ireg];

        /* '<S28>:1:35' */
        /* '<S28>:1:36' */
        /* '<S28>:1:38' */
        /* '<S28>:1:40' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value[ireg] -
             1; i++) {
          /* '<S28>:1:40' */
          /* '<S28>:1:41' */
          cos_yaw = ((controller_template_B.Hi[(int32_T)(1.0 + (real_T)i) - 1] *
                      X[0] + controller_template_B.Hi[(int32_T)(1.0 + (real_T)i)
                      + 999] * X[1]) + controller_template_B.Hi[(int32_T)(1.0 +
                      (real_T)i) + 1999] * X[2]) + controller_template_B.Hi
            [(int32_T)(1.0 + (real_T)i) + 2999] * X[3];
          if (cos_yaw - controller_template_B.Ki[(int32_T)(1.0 + (real_T)i) - 1]
              > 1.0E-8) {
            /* '<S28>:1:42' */
            /* '<S28>:1:43' */
            isinside = 0;

            /* '<S28>:1:44' */
            sin_yaw += cos_yaw - controller_template_B.Ki[(int32_T)(1.0 +
              (real_T)i) - 1];
          }

          /* '<S28>:1:40' */
        }

        if (sin_yaw < tolerance) {
          /* '<S28>:1:48' */
          /* '<S28>:1:49' */
          tolerance = sin_yaw;

          /* '<S28>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S28>:1:53' */
          /* '<S28>:1:54' */
          rtb_Saturation = (((controller_template_P.Constant2_Value_i[ireg + 346]
                              * X[1] +
                              controller_template_P.Constant2_Value_i[ireg] * X
                              [0]) +
                             controller_template_P.Constant2_Value_i[ireg + 692]
                             * X[2]) +
                            controller_template_P.Constant2_Value_i[ireg + 1038]
                            * X[3]) +
            controller_template_P.Constant3_Value_o[ireg];
          exitg = 1;
        } else {
          /* '<S28>:1:17' */
          ireg++;
        }
      } else {
        /* '<S28>:1:58' */
        /* '<S28>:1:59' */
        /* '<S28>:1:60' */
        rtb_Saturation = (((controller_template_P.Constant2_Value_i[minreg + 346]
                            * X[1] +
                            controller_template_P.Constant2_Value_i[minreg] * X
                            [0]) +
                           controller_template_P.Constant2_Value_i[minreg + 692]
                           * X[2]) +
                          controller_template_P.Constant2_Value_i[minreg + 1038]
                          * X[3]) +
          controller_template_P.Constant3_Value_o[minreg];

        /* '<S28>:1:61' */
        flag_oob = 1;
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_i = rtb_Saturation;
    controller_template_B.flag_oob_b = (real_T)flag_oob;

    /* End of MATLAB Function: '<S22>/Ctrl_Xdir' */

    /* Gain: '<S24>/Gain' incorporates:
     *  Saturate: '<S17>/Saturation4'
     *  Sum: '<S24>/Sum'
     *  Sum: '<S24>/Sum1'
     *  UnitDelay: '<S24>/Unit Delay'
     *  UnitDelay: '<S24>/Unit Delay2'
     */
    controller_template_B.Gain = ((controller_template_B.U_i >=
      controller_template_P.Saturation4_UpperSat ?
      controller_template_P.Saturation4_UpperSat : controller_template_B.U_i <=
      controller_template_P.Saturation4_LowerSat ?
      controller_template_P.Saturation4_LowerSat : controller_template_B.U_i) +
                                  (controller_template_DWork.UnitDelay2_DSTATE_d
      + controller_template_DWork.UnitDelay_DSTATE_jv)) *
      controller_template_P.Gain_Gain;

    /* Inport: '<S10>/bias_W' */
    rtb_bias_W[0] = controller_template_B.pitch_bias_rot_p;
    rtb_bias_W[1] = controller_template_B.roll_bias_rot_n;
    rtb_bias_W[2] = rtb_Init[2];
    rtb_bias_W[3] = rtb_Init[3];

    /* Sum: '<S10>/Sum' */
    controller_template_B.pitch_cmd_bq = controller_template_B.Gain -
      rtb_bias_W[0];

    /* Sum: '<S18>/Add' incorporates:
     *  Constant: '<S18>/Constant'
     *  Gain: '<S33>/Slider Gain'
     *  Gain: '<S34>/Slider Gain'
     *  Sum: '<S18>/Sum'
     */
    u = controller_template_B.DataTypeConversion[1] -
      (controller_template_P.SliderGain_Gain_g * controller_template_B.X_ref_y[0]
       + controller_template_P.SliderGain_Gain_b *
       controller_template_P.Constant_Value_g);

    /* Saturate: '<S18>/Saturation3' */
    controller_template_B.Saturation3_e = u >=
      controller_template_P.Saturation3_UpperSat_n ?
      controller_template_P.Saturation3_UpperSat_n : u <=
      controller_template_P.Saturation3_LowerSat_c ?
      controller_template_P.Saturation3_LowerSat_c : u;

    /* RateTransition: '<S31>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Saturate: '<S18>/Saturation' */
      controller_template_B.RateTransition_i[0] =
        controller_template_B.roll_rot_f >=
        controller_template_P.Saturation_UpperSat_h ?
        controller_template_P.Saturation_UpperSat_h :
        controller_template_B.roll_rot_f <=
        controller_template_P.Saturation_LowerSat_d ?
        controller_template_P.Saturation_LowerSat_d :
        controller_template_B.roll_rot_f;

      /* Saturate: '<S18>/Saturation1' */
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

      /* Saturate: '<S18>/Saturation2' */
      controller_template_B.RateTransition_i[3] =
        controller_template_B.DataTypeConversion[4] >=
        controller_template_P.Saturation2_UpperSat_b ?
        controller_template_P.Saturation2_UpperSat_b :
        controller_template_B.DataTypeConversion[4] <=
        controller_template_P.Saturation2_LowerSat_h ?
        controller_template_P.Saturation2_LowerSat_h :
        controller_template_B.DataTypeConversion[4];

      /* UnitDelay: '<S31>/Unit Delay2' */
      controller_template_B.UnitDelay2_o =
        controller_template_DWork.UnitDelay2_DSTATE_l;
    }

    /* End of RateTransition: '<S31>/Rate Transition' */

    /* MATLAB Function: '<S36>/MATLAB Function' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S36>/Constant1'
     */
    controller_template_DWork.sfEvent_i = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate/MATLAB Function': '<S37>:1' */
    /* '<S37>:1:4' */
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

    /* End of MATLAB Function: '<S36>/MATLAB Function' */

    /* MATLAB Function: '<S31>/Ctrl_Xdir' incorporates:
     *  Constant: '<S31>/Constant'
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S31>/Constant2'
     *  Constant: '<S31>/Constant3'
     *  Constant: '<S31>/Constant4'
     */
    controller_template_DWork.sfEvent_cd = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S35>:1' */
    /* '<S35>:1:3' */
    tolerance = 1.0;

    /* '<S35>:1:5' */
    /* '<S35>:1:6' */
    minreg = -1;

    /* '<S35>:1:7' */
    X[0] = 10000.0 * controller_template_B.y_a[0];
    X[1] = 10000.0 * controller_template_B.y_a[1];
    X[2] = 10000.0 * controller_template_B.y_a[2];
    X[3] = 10000.0 * controller_template_B.y_a[3];
    controller_template_round_p(X);
    X_0[0] = X[0];
    X_0[1] = X[1];
    X_0[2] = X[2];
    X_0[3] = X[3];
    controller_template_mrdivide_p(X_0, 10000.0, X);

    /* '<S35>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S35>:1:12' */
    memset((void *)&Hi[0], 0, 400U * sizeof(real_T));

    /* '<S35>:1:13' */
    memset((void *)&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S35>:1:16' */
    abspos = 1.0;

    /* '<S35>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 134) {
        /* '<S35>:1:17' */
        /* '<S35>:1:18' */
        sin_yaw = 0.0;

        /* '<S35>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S35>:1:23' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; i++) {
          /* '<S35>:1:23' */
          /* '<S35>:1:24' */
          /* '<S35>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S35>:1:24' */
          /* '<S35>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 99] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 1132];

          /* '<S35>:1:24' */
          /* '<S35>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 199] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 2265];

          /* '<S35>:1:24' */
          /* '<S35>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)i) + 299] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 3398];

          /* '<S35>:1:24' */
          /* '<S35>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S35>:1:30' */
        for (k = 0; k <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; k++) {
          /* '<S35>:1:30' */
          /* '<S35>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_j[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S35>:1:30' */
        }

        /* '<S35>:1:33' */
        abspos += controller_template_P.Constant4_Value_g[ireg];

        /* '<S35>:1:35' */
        /* '<S35>:1:36' */
        /* '<S35>:1:38' */
        /* '<S35>:1:40' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; i++) {
          /* '<S35>:1:40' */
          /* '<S35>:1:41' */
          cos_yaw = ((Hi[(int32_T)(1.0 + (real_T)i) - 1] * X[0] + Hi[(int32_T)
                      (1.0 + (real_T)i) + 99] * X[1]) + Hi[(int32_T)(1.0 +
                      (real_T)i) + 199] * X[2]) + Hi[(int32_T)(1.0 + (real_T)i)
            + 299] * X[3];
          if (cos_yaw - Ki[(int32_T)(1.0 + (real_T)i) - 1] > 1.0E-8) {
            /* '<S35>:1:42' */
            /* '<S35>:1:43' */
            isinside = 0;

            /* '<S35>:1:44' */
            sin_yaw += cos_yaw - Ki[(int32_T)(1.0 + (real_T)i) - 1];
          }

          /* '<S35>:1:40' */
        }

        if (sin_yaw < tolerance) {
          /* '<S35>:1:48' */
          /* '<S35>:1:49' */
          tolerance = sin_yaw;

          /* '<S35>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S35>:1:53' */
          /* '<S35>:1:54' */
          pitch_cmd_b = (((controller_template_P.Constant2_Value_j[ireg + 134] *
                           X[1] + controller_template_P.Constant2_Value_j[ireg] *
                           X[0]) + controller_template_P.Constant2_Value_j[ireg
                          + 268] * X[2]) +
                         controller_template_P.Constant2_Value_j[ireg + 402] *
                         X[3]) + controller_template_P.Constant3_Value_ok[ireg];
          exitg = 1;
        } else {
          /* '<S35>:1:17' */
          ireg++;
        }
      } else {
        /* '<S35>:1:58' */
        /* '<S35>:1:59' */
        /* '<S35>:1:60' */
        pitch_cmd_b = (((controller_template_P.Constant2_Value_j[minreg + 134] *
                         X[1] + controller_template_P.Constant2_Value_j[minreg] *
                         X[0]) + controller_template_P.Constant2_Value_j[minreg
                        + 268] * X[2]) +
                       controller_template_P.Constant2_Value_j[minreg + 402] *
                       X[3]) + controller_template_P.Constant3_Value_ok[minreg];

        /* '<S35>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_p = pitch_cmd_b;
    controller_template_B.flag_oob_o = (real_T)flag_oob;

    /* End of MATLAB Function: '<S31>/Ctrl_Xdir' */

    /* Gain: '<S32>/Gain' incorporates:
     *  Saturate: '<S18>/Saturation4'
     *  Sum: '<S32>/Sum'
     *  Sum: '<S32>/Sum1'
     *  UnitDelay: '<S32>/Unit Delay'
     *  UnitDelay: '<S32>/Unit Delay2'
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
    controller_template_B.roll_cmd_c = controller_template_B.Gain_f -
      rtb_bias_W[1];

    /* Sum: '<S21>/Add' */
    u = controller_template_B.DataTypeConversion[2] -
      controller_template_B.X_ref_z[0];

    /* Saturate: '<S21>/Saturation1' */
    controller_template_B.Saturation1 = u >=
      controller_template_P.Saturation1_UpperSat_d ?
      controller_template_P.Saturation1_UpperSat_d : u <=
      controller_template_P.Saturation1_LowerSat_n ?
      controller_template_P.Saturation1_LowerSat_n : u;

    /* RateTransition: '<S48>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      controller_template_B.RateTransition_j[0] =
        controller_template_B.Saturation1;

      /* Saturate: '<S21>/Saturation' */
      controller_template_B.RateTransition_j[1] =
        controller_template_B.DataTypeConversion[5] >=
        controller_template_P.Saturation_UpperSat_d ?
        controller_template_P.Saturation_UpperSat_d :
        controller_template_B.DataTypeConversion[5] <=
        controller_template_P.Saturation_LowerSat_b ?
        controller_template_P.Saturation_LowerSat_b :
        controller_template_B.DataTypeConversion[5];
    }

    /* End of RateTransition: '<S48>/Rate Transition' */

    /* MATLAB Function: '<S48>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_k0 = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S50>:1' */
    /* '<S50>:1:3' */
    tolerance = 1.0;

    /* '<S50>:1:5' */
    /* '<S50>:1:6' */
    minreg = -1;

    /* '<S50>:1:7' */
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
    /* MATLAB Function: '<S48>/Ctrl_Xdir' incorporates:
     *  Constant: '<S48>/Constant'
     *  Constant: '<S48>/Constant1'
     *  Constant: '<S48>/Constant2'
     *  Constant: '<S48>/Constant3'
     *  Constant: '<S48>/Constant4'
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

    /* '<S50>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S50>:1:12' */
    memset((void *)&Hi_0[0], 0, 200U * sizeof(real_T));

    /* '<S50>:1:13' */
    memset((void *)&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S50>:1:16' */
    abspos = 1.0;

    /* '<S50>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 27) {
        /* '<S50>:1:17' */
        /* '<S50>:1:18' */
        sin_yaw = 0.0;

        /* '<S50>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S50>:1:23' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; i++) {
          /* '<S50>:1:23' */
          /* '<S50>:1:24' */
          /* '<S50>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant_Value_b[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S50>:1:24' */
          /* '<S50>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)i) + 99] =
            controller_template_P.Constant_Value_b[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) + 111];

          /* '<S50>:1:24' */
          /* '<S50>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S50>:1:30' */
        for (k = 0; k <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; k++) {
          /* '<S50>:1:30' */
          /* '<S50>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)k) - 1] =
            controller_template_P.Constant1_Value_l[(int32_T)(((1.0 + (real_T)k)
            + abspos) - 1.0) - 1];

          /* '<S50>:1:30' */
        }

        /* '<S50>:1:33' */
        abspos += controller_template_P.Constant4_Value_a[ireg];

        /* '<S50>:1:35' */
        /* '<S50>:1:36' */
        /* '<S50>:1:38' */
        /* '<S50>:1:40' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; i++) {
          /* '<S50>:1:40' */
          /* '<S50>:1:41' */
          cos_yaw = Hi_0[(int32_T)(1.0 + (real_T)i) - 1] * temp_idx + Hi_0
            [(int32_T)(1.0 + (real_T)i) + 99] * u;
          if (cos_yaw - Ki[(int32_T)(1.0 + (real_T)i) - 1] > 1.0E-8) {
            /* '<S50>:1:42' */
            /* '<S50>:1:43' */
            isinside = 0;

            /* '<S50>:1:44' */
            sin_yaw += cos_yaw - Ki[(int32_T)(1.0 + (real_T)i) - 1];
          }

          /* '<S50>:1:40' */
        }

        if (sin_yaw < tolerance) {
          /* '<S50>:1:48' */
          /* '<S50>:1:49' */
          tolerance = sin_yaw;

          /* '<S50>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S50>:1:53' */
          /* '<S50>:1:54' */
          rtb_Saturation_p = (controller_template_P.Constant2_Value_g[ireg + 27]
                              * u + controller_template_P.Constant2_Value_g[ireg]
                              * temp_idx) +
            controller_template_P.Constant3_Value_m[ireg];
          exitg = 1;
        } else {
          /* '<S50>:1:17' */
          ireg++;
        }
      } else {
        /* '<S50>:1:58' */
        /* '<S50>:1:59' */
        /* '<S50>:1:60' */
        rtb_Saturation_p = (controller_template_P.Constant2_Value_g[minreg + 27]
                            * u + controller_template_P.Constant2_Value_g[minreg]
                            * temp_idx) +
          controller_template_P.Constant3_Value_m[minreg];

        /* '<S50>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U = rtb_Saturation_p;
    controller_template_B.flag_oob = (real_T)flag_oob;

    /* Gain: '<S49>/Gain' incorporates:
     *  Saturate: '<S21>/Saturation2'
     *  Sum: '<S49>/Sum'
     *  Sum: '<S49>/Sum1'
     *  UnitDelay: '<S49>/Unit Delay'
     *  UnitDelay: '<S49>/Unit Delay2'
     */
    controller_template_B.Gain_i = ((controller_template_B.U >=
      controller_template_P.Saturation2_UpperSat_k ?
      controller_template_P.Saturation2_UpperSat_k : controller_template_B.U <=
      controller_template_P.Saturation2_LowerSat_j ?
      controller_template_P.Saturation2_LowerSat_j : controller_template_B.U) +
                                    
      (controller_template_DWork.UnitDelay2_DSTATE_b +
       controller_template_DWork.UnitDelay_DSTATE_fw)) *
      controller_template_P.Gain_Gain_p;

    /* Sum: '<S10>/Sum2' */
    cos_yaw = controller_template_B.Gain_i - rtb_bias_W[2];

    /* UnitDelay: '<S20>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_d[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_bg, 9U * sizeof(real_T));

    /* Switch: '<S46>/Init' incorporates:
     *  UnitDelay: '<S46>/FixPt Unit Delay1'
     *  UnitDelay: '<S46>/FixPt Unit Delay2'
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

    /* End of Switch: '<S46>/Init' */

    /* MATLAB Function: '<S20>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.DataTypeConversion[8],
      controller_template_B.DataTypeConversion[11], rtb_Init_jd, rtb_bias_W[3],
      controller_template_P.A_Value, controller_template_P.B_Value,
      controller_template_P.C_Value, controller_template_P.Q_Value,
      controller_template_P.R_Value, rtb_IntegerDelay3_c, rtb_UnitDelay1_d,
      &controller_template_B.sf_discretekalmanfilter,
      &controller_template_DWork.sf_discretekalmanfilter);

    /* Sum: '<S19>/Sum' incorporates:
     *  Constant: '<S19>/Constant'
     *  Gain: '<S40>/Slider Gain'
     *  Gain: '<S41>/Slider Gain'
     */
    controller_template_B.Sum = controller_template_P.SliderGain_Gain_a *
      controller_template_B.X_ref_yaw[0] +
      controller_template_P.SliderGain_Gain_j *
      controller_template_P.Constant_Value_fv;

    /* MATLAB Function: '<S44>/MATLAB Function' */
    controller_template_DWork.sfEvent_l = CALL_EVENT;

    /* Sum: '<S19>/Add' */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate/MATLAB Function': '<S45>:1' */
    /* '<S45>:1:4' */
    u = controller_template_B.sf_discretekalmanfilter.state_est[0] -
      controller_template_B.Sum;

    /* MATLAB Function: '<S44>/MATLAB Function' incorporates:
     *  Constant: '<S44>/Constant'
     *  Constant: '<S44>/Constant1'
     *  Saturate: '<S19>/Saturation'
     *  UnitDelay: '<S38>/Unit Delay2'
     */
    controller_template_B.y = (u >= controller_template_P.Saturation_UpperSat_o ?
      controller_template_P.Saturation_UpperSat_o : u <=
      controller_template_P.Saturation_LowerSat_p ?
      controller_template_P.Saturation_LowerSat_p : u) *
      controller_template_P.Constant_Value_h +
      controller_template_P.Constant1_Value_m *
      controller_template_DWork.UnitDelay2_DSTATE_g;

    /* MATLAB Function: '<S38>/Ctrl_Xdir' incorporates:
     *  Constant: '<S38>/Constant'
     *  Constant: '<S38>/Constant1'
     *  Constant: '<S38>/Constant2'
     *  Constant: '<S38>/Constant3'
     *  Constant: '<S38>/Constant4'
     */
    controller_template_DWork.sfEvent_jv = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S42>:1' */
    /* '<S42>:1:3' */
    /* '<S42>:1:5' */
    /* '<S42>:1:6' */
    /* '<S42>:1:7' */
    sin_yaw = 10000.0 * controller_template_B.y;
    if (!(fabs(sin_yaw) > 4.503599627370496E+15)) {
      if (sin_yaw >= 0.5) {
        sin_yaw = floor(sin_yaw + 0.5);
      } else if (sin_yaw > -0.5) {
        sin_yaw = -0.0;
      } else {
        sin_yaw = ceil(sin_yaw - 0.5);
      }
    }

    sin_yaw /= 10000.0;

    /* '<S42>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S42>:1:12' */
    /* '<S42>:1:13' */
    for (i = 0; i < 100; i++) {
      Hi_1[i] = 0.0;
      Ki[i] = 0.0;
    }

    /*  Find the proper region */
    /* '<S42>:1:16' */
    /* '<S42>:1:17' */
    /* '<S42>:1:18' */
    /* '<S42>:1:19' */
    isinside = 1;

    /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
    /* '<S42>:1:23' */
    for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_gb - 1; i++)
    {
      /* '<S42>:1:23' */
      /* '<S42>:1:25' */
      Hi_1[(int32_T)(1.0 + (real_T)i) - 1] =
        controller_template_P.Constant_Value_a[(int32_T)(((1.0 + (real_T)i) +
        1.0) - 1.0) - 1];

      /* '<S42>:1:23' */
    }

    /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
    /* '<S42>:1:30' */
    for (k = 0; k <= (int32_T)controller_template_P.Constant4_Value_gb - 1; k++)
    {
      /* '<S42>:1:30' */
      /* '<S42>:1:31' */
      Ki[(int32_T)(1.0 + (real_T)k) - 1] =
        controller_template_P.Constant1_Value_gs[(int32_T)(((1.0 + (real_T)k) +
        1.0) - 1.0) - 1];

      /* '<S42>:1:30' */
    }

    /* '<S42>:1:40' */
    for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_gb - 1; i++)
    {
      /* '<S42>:1:40' */
      /* '<S42>:1:41' */
      if (Hi_1[(int32_T)(1.0 + (real_T)i) - 1] * sin_yaw - Ki[(int32_T)(1.0 +
           (real_T)i) - 1] > 1.0E-8) {
        /* '<S42>:1:42' */
        /* '<S42>:1:43' */
        isinside = 0;

        /* '<S42>:1:44' */
      }

      /* '<S42>:1:40' */
    }

    /*  extract the right control law */
    if (isinside == 1) {
      /* '<S42>:1:53' */
      /* '<S42>:1:54' */
      controller_template_B.U_g = controller_template_P.Constant2_Value_jq *
        sin_yaw + controller_template_P.Constant3_Value_b;
    } else {
      /* '<S42>:1:60' */
      controller_template_B.U_g = controller_template_P.Constant2_Value_jq *
        sin_yaw + controller_template_P.Constant3_Value_b;

      /* '<S42>:1:61' */
      flag_oob = 1;

      /* U = U_prev; */
    }

    controller_template_B.flag_oob_l = (real_T)flag_oob;

    /* End of MATLAB Function: '<S38>/Ctrl_Xdir' */

    /* Gain: '<S43>/Slider Gain' */
    u = controller_template_P.SliderGain_Gain_a3 * controller_template_B.U_g;

    /* Gain: '<S39>/Gain' incorporates:
     *  Saturate: '<S19>/Saturation1'
     *  Sum: '<S39>/Sum'
     *  Sum: '<S39>/Sum1'
     *  UnitDelay: '<S39>/Unit Delay'
     *  UnitDelay: '<S39>/Unit Delay2'
     */
    controller_template_B.Gain_n = ((u >=
      controller_template_P.Saturation1_UpperSat_g ?
      controller_template_P.Saturation1_UpperSat_g : u <=
      controller_template_P.Saturation1_LowerSat_b ?
      controller_template_P.Saturation1_LowerSat_b : u) +
      (controller_template_DWork.UnitDelay2_DSTATE_ga +
       controller_template_DWork.UnitDelay_DSTATE_p)) *
      controller_template_P.Gain_Gain_p0;

    /* Saturate: '<S20>/Saturation' */
    tolerance = controller_template_B.sf_discretekalmanfilter.state_est[2] >=
      controller_template_P.Saturation_UpperSat_c ?
      controller_template_P.Saturation_UpperSat_c :
      controller_template_B.sf_discretekalmanfilter.state_est[2] <=
      controller_template_P.Saturation_LowerSat_j ?
      controller_template_P.Saturation_LowerSat_j :
      controller_template_B.sf_discretekalmanfilter.state_est[2];

    /* Sum: '<S10>/Sum3' */
    controller_template_B.yaw_rate_cmd_g = controller_template_B.Gain_n -
      tolerance;

    /* Sum: '<S10>/Sum5' */
    controller_template_B.thrust_cmd_a = cos_yaw + rtb_Product_l;

    /* RateTransition: '<S22>/Rate Transition1' incorporates:
     *  RateTransition: '<S31>/Rate Transition1'
     */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      controller_template_B.RateTransition1 = controller_template_B.Gain;
      controller_template_B.RateTransition1_l = controller_template_B.Gain_f;
    }

    /* End of RateTransition: '<S22>/Rate Transition1' */

    /* Gain: '<S19>/Gain' */
    controller_template_B.Gain_g = controller_template_P.Gain_Gain_b *
      controller_template_B.sf_discretekalmanfilter.state_est[0];

    /* Update for Delay: '<S10>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE_k =
      controller_template_B.yaw_rate_cmd_g;
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for UnitDelay: '<S22>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE =
        controller_template_B.RateTransition1;
    }

    /* Update for UnitDelay: '<S24>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_d = controller_template_B.Gain;

    /* Update for UnitDelay: '<S24>/Unit Delay' incorporates:
     *  UnitDelay: '<S24>/Unit Delay1'
     */
    controller_template_DWork.UnitDelay_DSTATE_jv =
      controller_template_DWork.UnitDelay1_DSTATE_a;
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      /* Update for UnitDelay: '<S31>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_l =
        controller_template_B.RateTransition1_l;
    }

    /* Update for UnitDelay: '<S32>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_k = controller_template_B.Gain_f;

    /* Update for UnitDelay: '<S32>/Unit Delay' incorporates:
     *  UnitDelay: '<S32>/Unit Delay1'
     */
    controller_template_DWork.UnitDelay_DSTATE_f =
      controller_template_DWork.UnitDelay1_DSTATE_ji;

    /* Update for UnitDelay: '<S49>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_b = controller_template_B.Gain_i;

    /* Update for UnitDelay: '<S49>/Unit Delay' incorporates:
     *  UnitDelay: '<S49>/Unit Delay1'
     */
    controller_template_DWork.UnitDelay_DSTATE_fw =
      controller_template_DWork.UnitDelay1_DSTATE_m;

    /* Update for UnitDelay: '<S20>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_bg, (void *)
           (&controller_template_B.sf_discretekalmanfilter.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S46>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S46>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
      controller_template_P.FixPtConstant_Value;

    /* Update for UnitDelay: '<S46>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0] =
      controller_template_B.sf_discretekalmanfilter.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1] =
      controller_template_B.sf_discretekalmanfilter.state_est[1];

    /* Update for UnitDelay: '<S38>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_g = controller_template_B.Gain_n;

    /* Update for UnitDelay: '<S39>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_ga =
      controller_template_B.Gain_n;

    /* Update for UnitDelay: '<S39>/Unit Delay' incorporates:
     *  UnitDelay: '<S39>/Unit Delay1'
     */
    controller_template_DWork.UnitDelay_DSTATE_p =
      controller_template_DWork.UnitDelay1_DSTATE_c3;

    /* Update for UnitDelay: '<S24>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_a = controller_template_B.Gain;

    /* Update for UnitDelay: '<S32>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_ji =
      controller_template_B.Gain_f;

    /* Update for UnitDelay: '<S39>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_c3 =
      controller_template_B.Gain_n;

    /* Update for UnitDelay: '<S49>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_m = controller_template_B.Gain_i;

    /* End of Outputs for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

    /* SignalConversion: '<S15>/TmpSignal ConversionAtTo FileInport1' */
    for (i = 0; i < 6; i++) {
      rtb_TmpSignalConversionAtToFi_a[i] =
        controller_template_B.DataTypeConversion[i];
    }

    rtb_TmpSignalConversionAtToFi_a[6] = controller_template_B.roll_rot_f;
    rtb_TmpSignalConversionAtToFi_a[7] = controller_template_B.pitch_rot_i;
    rtb_TmpSignalConversionAtToFi_a[8] =
      controller_template_B.DataTypeConversion[8];
    rtb_TmpSignalConversionAtToFi_a[9] =
      controller_template_B.DataTypeConversion[9];
    rtb_TmpSignalConversionAtToFi_a[10] =
      controller_template_B.DataTypeConversion[10];
    rtb_TmpSignalConversionAtToFi_a[11] =
      controller_template_B.DataTypeConversion[11];
    rtb_TmpSignalConversionAtToFi_a[12] = controller_template_B.X_ref_x[0];
    rtb_TmpSignalConversionAtToFi_a[13] = controller_template_B.X_ref_y[0];
    rtb_TmpSignalConversionAtToFi_a[14] = controller_template_B.X_ref_z[0];
    rtb_TmpSignalConversionAtToFi_a[15] = controller_template_B.X_ref_yaw[0];
    rtb_TmpSignalConversionAtToFi_a[16] = controller_template_B.X_ref_x[1];
    rtb_TmpSignalConversionAtToFi_a[17] = controller_template_B.X_ref_y[1];
    rtb_TmpSignalConversionAtToFi_a[18] = controller_template_B.X_ref_z[1];
    rtb_TmpSignalConversionAtToFi_a[19] = controller_template_B.X_ref_yaw[1];
    rtb_TmpSignalConversionAtToFi_a[20] = controller_template_B.pitch_cmd_bq;
    rtb_TmpSignalConversionAtToFi_a[21] = controller_template_B.roll_cmd_c;
    rtb_TmpSignalConversionAtToFi_a[22] = controller_template_B.thrust_cmd_a;
    rtb_TmpSignalConversionAtToFi_a[23] = controller_template_B.yaw_rate_cmd_g;
    rtb_TmpSignalConversionAtToFi_a[24] = rtb_bias_W[0];
    rtb_TmpSignalConversionAtToFi_a[25] = rtb_bias_W[1];
    rtb_TmpSignalConversionAtToFi_a[26] = rtb_bias_W[2];
    rtb_TmpSignalConversionAtToFi_a[27] = tolerance;

    /* End of SignalConversion: '<S15>/TmpSignal ConversionAtTo FileInport1' */

    /* ToFile: '<S15>/To File' */
    if (!(++controller_template_DWork.ToFile_IWORK_g.Decimation % 1) &&
        (controller_template_DWork.ToFile_IWORK_g.Count*29)+1 < 100000000 ) {
      FILE *fp = (FILE *) controller_template_DWork.ToFile_PWORK_p.FilePtr;
      if (fp != (NULL)) {
        real_T u[29];
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
        u[19] = rtb_TmpSignalConversionAtToFi_a[18];
        u[20] = rtb_TmpSignalConversionAtToFi_a[19];
        u[21] = rtb_TmpSignalConversionAtToFi_a[20];
        u[22] = rtb_TmpSignalConversionAtToFi_a[21];
        u[23] = rtb_TmpSignalConversionAtToFi_a[22];
        u[24] = rtb_TmpSignalConversionAtToFi_a[23];
        u[25] = rtb_TmpSignalConversionAtToFi_a[24];
        u[26] = rtb_TmpSignalConversionAtToFi_a[25];
        u[27] = rtb_TmpSignalConversionAtToFi_a[26];
        u[28] = rtb_TmpSignalConversionAtToFi_a[27];
        if (fwrite(u, sizeof(real_T), 29, fp) != 29) {
          rtmSetErrorStatus(controller_template_M,
                            "Error writing to MAT-file ForceLogData.m");
          return;
        }

        if (((++controller_template_DWork.ToFile_IWORK_g.Count)*29)+1 >=
            100000000) {
          (void)fprintf(stdout,
                        "*** The ToFile block will stop logging data before\n"
                        "    the simulation has ended, because it has reached\n"
                        "    the maximum number of elements (100000000)\n"
                        "    allowed in MAT-file ForceLogData.m.\n");
        }
      }
    }

    /* Switch: '<S51>/Init' incorporates:
     *  Constant: '<S51>/Initial Condition'
     *  Logic: '<S51>/FixPt Logical Operator'
     *  UnitDelay: '<S51>/FixPt Unit Delay1'
     *  UnitDelay: '<S51>/FixPt Unit Delay2'
     */
    if ((rtb_MultiportSwitch1 != 0.0) ||
        (controller_template_DWork.FixPtUnitDelay2_DSTATE_e != 0)) {
      u = controller_template_P.InitialCondition_Value;
    } else {
      u = controller_template_DWork.FixPtUnitDelay1_DSTATE_k;
    }

    /* End of Switch: '<S51>/Init' */

    /* Sum: '<S11>/Sum' incorporates:
     *  Constant: '<S11>/Constant'
     */
    abspos = controller_template_P.Constant_Value_br + u;

    /* Sum: '<S11>/Sum2' incorporates:
     *  Constant: '<S11>/Constant1'
     *  Constant: '<S11>/total_samples'
     *  Math: '<S11>/Math Function'
     */
    cos_yaw = rt_modd_snf(abspos, controller_template_P.total_samples_Value) +
      controller_template_P.Constant1_Value_e;

    /* MATLAB Function: '<S11>/generate_X_ref_x' incorporates:
     *  Constant: '<S11>/X_ref_x'
     */
    controller_template_DWork.sfEvent_m = CALL_EVENT;

    /* MATLAB Function 'create ref traj/generate_X_ref_x': '<S52>:1' */
    /* '<S52>:1:5' */
    for (k = 0; k < 31; k++) {
      controller_template_B.X_ref_x_l[3 * k] =
        controller_template_P.X_ref_x_Value[((int32_T)(cos_yaw + (real_T)k) - 1)
        * 3];
      controller_template_B.X_ref_x_l[1 + 3 * k] =
        controller_template_P.X_ref_x_Value[((int32_T)(cos_yaw + (real_T)k) - 1)
        * 3 + 1];
      controller_template_B.X_ref_x_l[2 + 3 * k] =
        controller_template_P.X_ref_x_Value[((int32_T)(cos_yaw + (real_T)k) - 1)
        * 3 + 2];
    }

    /* End of MATLAB Function: '<S11>/generate_X_ref_x' */

    /* MATLAB Function: '<S11>/generate_X_ref_y' incorporates:
     *  Constant: '<S11>/X_ref_y'
     */
    controller_template_DWork.sfEvent_dw = CALL_EVENT;

    /* MATLAB Function 'create ref traj/generate_X_ref_y': '<S53>:1' */
    /* '<S53>:1:5' */
    for (k = 0; k < 31; k++) {
      controller_template_B.X_ref_y_j[3 * k] =
        controller_template_P.X_ref_y_Value[((int32_T)(cos_yaw + (real_T)k) - 1)
        * 3];
      controller_template_B.X_ref_y_j[1 + 3 * k] =
        controller_template_P.X_ref_y_Value[((int32_T)(cos_yaw + (real_T)k) - 1)
        * 3 + 1];
      controller_template_B.X_ref_y_j[2 + 3 * k] =
        controller_template_P.X_ref_y_Value[((int32_T)(cos_yaw + (real_T)k) - 1)
        * 3 + 2];
    }

    /* End of MATLAB Function: '<S11>/generate_X_ref_y' */

    /* MATLAB Function: '<S11>/generate_X_ref_yaw' incorporates:
     *  Constant: '<S11>/X_ref_yaw'
     */
    controller_template_DWork.sfEvent_h = CALL_EVENT;

    /* MATLAB Function 'create ref traj/generate_X_ref_yaw': '<S54>:1' */
    /* '<S54>:1:5' */
    /* '<S54>:1:6' */
    /* '<S54>:1:9' */
    sin_yaw = (controller_template_B.DataTypeConversion[8] -
               controller_template_P.X_ref_yaw_Value[(((int32_T)cos_yaw - 1) <<
                1)]) / 6.2831853071795862;
    if (!(fabs(sin_yaw) > 4.503599627370496E+15)) {
      if (sin_yaw >= 0.5) {
        sin_yaw = floor(sin_yaw + 0.5);
      } else if (sin_yaw > -0.5) {
        sin_yaw = -0.0;
      } else {
        sin_yaw = ceil(sin_yaw - 0.5);
      }
    }

    sin_yaw = sin_yaw * 2.0 * 3.1415926535897931;

    /* '<S54>:1:11' */
    for (k = 0; k < 31; k++) {
      controller_template_B.X_ref_yaw_a[(k << 1)] =
        controller_template_P.X_ref_yaw_Value[(((int32_T)(cos_yaw + (real_T)k) -
        1) << 1)] + sin_yaw;
    }

    for (k = 0; k < 31; k++) {
      controller_template_B.X_ref_yaw_a[1 + (k << 1)] =
        controller_template_P.X_ref_yaw_Value[(((int32_T)(cos_yaw + (real_T)k) -
        1) << 1) + 1];
    }

    /* End of MATLAB Function: '<S11>/generate_X_ref_yaw' */

    /* MATLAB Function: '<S11>/generate_X_ref_z' incorporates:
     *  Constant: '<S11>/X_ref_z'
     */
    controller_template_DWork.sfEvent_d = CALL_EVENT;

    /* MATLAB Function 'create ref traj/generate_X_ref_z': '<S55>:1' */
    /* '<S55>:1:5' */
    for (k = 0; k < 31; k++) {
      controller_template_B.X_ref_z_b[(k << 1)] =
        controller_template_P.X_ref_z_Value[(((int32_T)(cos_yaw + (real_T)k) - 1)
        << 1)];
      controller_template_B.X_ref_z_b[1 + (k << 1)] =
        controller_template_P.X_ref_z_Value[(((int32_T)(cos_yaw + (real_T)k) - 1)
        << 1) + 1];
    }

    /* End of MATLAB Function: '<S11>/generate_X_ref_z' */

    /* Outputs for Atomic SubSystem: '<S2>/decoupling and rotation' */
    /* Inport: '<S12>/bias_W' */
    controller_template_B.bias_W_b[0] = rtb_bias_W[0];
    controller_template_B.bias_W_b[1] = rtb_bias_W[1];
    controller_template_B.bias_W_b[2] = rtb_bias_W[2];
    controller_template_B.bias_W_b[3] = tolerance;

    /* Inport: '<S12>/cmd_W' */
    controller_template_B.cmd_W_h[0] = controller_template_B.pitch_cmd_bq;
    controller_template_B.cmd_W_h[1] = controller_template_B.roll_cmd_c;
    controller_template_B.cmd_W_h[2] = controller_template_B.thrust_cmd_a;
    controller_template_B.cmd_W_h[3] = controller_template_B.yaw_rate_cmd_g;

    /* MATLAB Function: '<S56>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S56>/g'
     */
    controller_template_DWork.sfEvent_c = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/decoupling /Embedded MATLAB Function': '<S58>:1' */
    /* '<S58>:1:4' */
    sin_yaw = controller_template_B.cmd_W_h[2] / (cos
      (controller_template_B.pitch_rot_i) * cos(controller_template_B.roll_rot_f));

    /* '<S58>:1:6' */
    controller_template_B.pitch_cmd_comp_n =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value / sin_yaw * controller_template_B.cmd_W_h[0];

    /* '<S58>:1:7' */
    controller_template_B.roll_cmd_comp_j =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value / sin_yaw * controller_template_B.cmd_W_h[1];

    /*  pitch_cmd_comp=pitch_cmd; */
    /*  roll_cmd_comp=roll_cmd; */
    /*  pitch_cmd_comp = atan(Fx/(-thrust_comp)); */
    /*  roll_cmd_comp = atan(Fy/(thrust_comp)); */
    /*  pitch_cmd_comp = atan(-g*m*pitch_cmd/(-thrust)); */
    /*  roll_cmd_comp = atan(g*m*roll_cmd*cos(pitch_meas)/(thrust)); */
    controller_template_B.thrust_comp_k = sin_yaw;

    /* MATLAB Function: '<S57>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_j = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S59>:1' */
    /* '<S59>:1:3' */
    sin_yaw = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S59>:1:4' */
    cos_yaw = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S59>:1:6' */
    /* '<S59>:1:8' */
    /* '<S59>:1:9' */
    controller_template_B.pitch_rot_n = cos_yaw *
      controller_template_B.pitch_cmd_comp_n + -sin_yaw *
      controller_template_B.roll_cmd_comp_j;

    /* '<S59>:1:10' */
    controller_template_B.roll_rot_e = sin_yaw *
      controller_template_B.pitch_cmd_comp_n + cos_yaw *
      controller_template_B.roll_cmd_comp_j;

    /* '<S59>:1:12' */
    /* '<S59>:1:13' */
    controller_template_B.pitch_bias_rot_i = cos_yaw *
      controller_template_B.bias_W_b[0] + -sin_yaw *
      controller_template_B.bias_W_b[1];

    /* '<S59>:1:14' */
    controller_template_B.roll_bias_rot_d = sin_yaw *
      controller_template_B.bias_W_b[0] + cos_yaw *
      controller_template_B.bias_W_b[1];

    /* End of Outputs for SubSystem: '<S2>/decoupling and rotation' */

    /* Update for UnitDelay: '<S51>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S51>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_e =
      controller_template_P.FixPtConstant_Value_g;

    /* Switch: '<S51>/Reset' */
    if (rtb_MultiportSwitch1 != 0.0) {
      /* Update for UnitDelay: '<S51>/FixPt Unit Delay1' incorporates:
       *  Constant: '<S51>/Initial Condition'
       */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_k =
        controller_template_P.InitialCondition_Value;
    } else {
      /* Update for UnitDelay: '<S51>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_k = abspos;
    }

    /* End of Switch: '<S51>/Reset' */
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
      /* InitializeConditions for MATLAB Function: '<S66>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent = CALL_EVENT;
      controller_template_DWork.is_active_c26_Hquad_control_LIB = 0U;

      /* InitializeConditions for Atomic SubSystem: '<S9>/MAIN CONTROL LOOP1' */
      /* InitializeConditions for Delay: '<S63>/Integer Delay' */
      controller_template_DWork.IntegerDelay_DSTATE =
        controller_template_P.IntegerDelay_InitialCondition;

      /* InitializeConditions for Delay: '<S63>/Integer Delay1' */
      controller_template_DWork.IntegerDelay1_DSTATE =
        controller_template_P.IntegerDelay1_InitialCondition;

      /* InitializeConditions for Delay: '<S63>/Integer Delay2' */
      controller_template_DWork.IntegerDelay2_DSTATE =
        controller_template_P.IntegerDelay2_InitialCondition;

      /* InitializeConditions for Delay: '<S63>/Integer Delay3' */
      controller_template_DWork.IntegerDelay3_DSTATE =
        controller_template_P.IntegerDelay3_InitialConditio_c;

      /* InitializeConditions for UnitDelay: '<S70>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
             controller_template_P.UnitDelay1_X0_c, sizeof(real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S78>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
        controller_template_P.FixPtUnitDelay2_X0_d;

      /* InitializeConditions for UnitDelay: '<S78>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
        controller_template_P.FixPtUnitDelay1_X0_f;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
        controller_template_P.FixPtUnitDelay1_X0_f;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
        controller_template_P.FixPtUnitDelay1_X0_f;

      /* InitializeConditions for MATLAB Function: '<S70>/discrete kalman filter' */
      con_discretekalmanfilter_k_Init
        (&controller_template_DWork.sf_discretekalmanfilter_b);

      /* InitializeConditions for UnitDelay: '<S69>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE[0] =
        controller_template_P.UnitDelay_X0_fc[0];
      controller_template_DWork.UnitDelay_DSTATE[1] =
        controller_template_P.UnitDelay_X0_fc[1];
      controller_template_DWork.UnitDelay_DSTATE[2] =
        controller_template_P.UnitDelay_X0_fc[2];

      /* InitializeConditions for UnitDelay: '<S69>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
             controller_template_P.UnitDelay1_X0_k, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S69>/runFastGradient' */
      controller_runFastGradient_Init
        (&controller_template_DWork.sf_runFastGradient);

      /* InitializeConditions for UnitDelay: '<S72>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
             controller_template_P.UnitDelay1_X0_fk, sizeof(real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S81>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
        controller_template_P.FixPtUnitDelay2_X0_n;

      /* InitializeConditions for UnitDelay: '<S81>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
        controller_template_P.FixPtUnitDelay1_X0_n;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
        controller_template_P.FixPtUnitDelay1_X0_n;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
        controller_template_P.FixPtUnitDelay1_X0_n;

      /* InitializeConditions for MATLAB Function: '<S72>/discrete kalman filter' */
      con_discretekalmanfilter_k_Init
        (&controller_template_DWork.sf_discretekalmanfilter_m);

      /* InitializeConditions for UnitDelay: '<S71>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_j[0] =
        controller_template_P.UnitDelay_X0_ik[0];
      controller_template_DWork.UnitDelay_DSTATE_j[1] =
        controller_template_P.UnitDelay_X0_ik[1];
      controller_template_DWork.UnitDelay_DSTATE_j[2] =
        controller_template_P.UnitDelay_X0_ik[2];

      /* InitializeConditions for UnitDelay: '<S71>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
             controller_template_P.UnitDelay1_X0_jc, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S71>/runFastGradient' */
      controller_runFastGradient_Init
        (&controller_template_DWork.sf_runFastGradient_d);

      /* InitializeConditions for UnitDelay: '<S76>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
             controller_template_P.UnitDelay1_X0_cw, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S87>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
        controller_template_P.FixPtUnitDelay2_X0_do;

      /* InitializeConditions for UnitDelay: '<S87>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
        controller_template_P.FixPtUnitDelay1_X0_cl;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
        controller_template_P.FixPtUnitDelay1_X0_cl;

      /* InitializeConditions for MATLAB Function: '<S76>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter_k);

      /* InitializeConditions for UnitDelay: '<S75>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_l[0] =
        controller_template_P.UnitDelay_X0_a[0];
      controller_template_DWork.UnitDelay_DSTATE_l[1] =
        controller_template_P.UnitDelay_X0_a[1];

      /* InitializeConditions for UnitDelay: '<S75>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
             controller_template_P.UnitDelay1_X0_b, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S75>/runFastGradient' */
      controller_template_DWork.sfEvent_k = CALL_EVENT;
      controller_template_DWork.is_active_c8_Hquad_control_LIB_ = 0U;

      /* InitializeConditions for UnitDelay: '<S74>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
             controller_template_P.UnitDelay1_X0_n, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S84>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
        controller_template_P.FixPtUnitDelay2_X0_i;

      /* InitializeConditions for UnitDelay: '<S84>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
        controller_template_P.FixPtUnitDelay1_X0_e;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
        controller_template_P.FixPtUnitDelay1_X0_e;

      /* InitializeConditions for MATLAB Function: '<S74>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter_n);

      /* InitializeConditions for UnitDelay: '<S73>/Unit Delay' */
      for (i = 0; i < 6; i++) {
        controller_template_DWork.UnitDelay_DSTATE_jz[i] =
          controller_template_P.UnitDelay_X0_fj[i];
      }

      /* End of InitializeConditions for UnitDelay: '<S73>/Unit Delay' */

      /* InitializeConditions for UnitDelay: '<S73>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
             controller_template_P.UnitDelay1_X0_o, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S73>/runFastGradient' */
      controller_template_DWork.sfEvent_n = CALL_EVENT;
      controller_template_DWork.is_active_c9_Hquad_control_LIB_ = 0U;

      /* End of InitializeConditions for SubSystem: '<S9>/MAIN CONTROL LOOP1' */

      /* InitializeConditions for Atomic SubSystem: '<S9>/decoupling and rotation' */
      /* InitializeConditions for MATLAB Function: '<S89>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_f = CALL_EVENT;
      controller_template_DWork.is_active_c1_Hquad_control_LIB_ = 0U;

      /* InitializeConditions for MATLAB Function: '<S90>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_b = CALL_EVENT;
      controller_template_DWork.is_active_c4_Hquad_control_LIB_ = 0U;

      /* End of InitializeConditions for SubSystem: '<S9>/decoupling and rotation' */
      controller_template_DWork.poscontroller_MODE = TRUE;
    }

    /* MATLAB Function: '<S66>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent = CALL_EVENT;

    /* MATLAB Function 'rotate to world frame/Embedded MATLAB Function': '<S93>:1' */
    /* '<S93>:1:5' */
    sin_yaw = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S93>:1:6' */
    cos_yaw = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S93>:1:8' */
    /* '<S93>:1:10' */
    /* '<S93>:1:11' */
    controller_template_B.pitch_rot = cos_yaw *
      controller_template_B.DataTypeConversion[7] + sin_yaw *
      controller_template_B.DataTypeConversion[6];

    /* '<S93>:1:12' */
    controller_template_B.roll_rot = -sin_yaw *
      controller_template_B.DataTypeConversion[7] + cos_yaw *
      controller_template_B.DataTypeConversion[6];

    /* '<S93>:1:14' */
    /* '<S93>:1:15' */
    controller_template_B.pitch_bias_rot = cos_yaw * rtb_Init[0] + sin_yaw *
      rtb_Init[1];

    /* '<S93>:1:16' */
    controller_template_B.roll_bias_rot = -sin_yaw * rtb_Init[0] + cos_yaw *
      rtb_Init[1];

    /* Outputs for Atomic SubSystem: '<S9>/MAIN CONTROL LOOP1' */
    /* Delay: '<S63>/Integer Delay' */
    rtb_IntegerDelay = controller_template_DWork.IntegerDelay_DSTATE;

    /* Delay: '<S63>/Integer Delay1' */
    rtb_IntegerDelay1 = controller_template_DWork.IntegerDelay1_DSTATE;

    /* Delay: '<S63>/Integer Delay2' */
    rtb_IntegerDelay2 = controller_template_DWork.IntegerDelay2_DSTATE;

    /* Delay: '<S63>/Integer Delay3' */
    rtb_IntegerDelay3 = controller_template_DWork.IntegerDelay3_DSTATE;

    /* Product: '<S63>/Product' incorporates:
     *  Constant: '<S63>/gravity'
     */
    abspos = controller_template_P.gravity_Value_j *
      controller_template_B.DataTypeConversion[29];

    /* UnitDelay: '<S70>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE, sizeof(real_T) << 4U);

    /* Switch: '<S78>/Init' incorporates:
     *  UnitDelay: '<S78>/FixPt Unit Delay1'
     *  UnitDelay: '<S78>/FixPt Unit Delay2'
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
      rtb_Init_g[2] = controller_template_B.pitch_rot;
    } else {
      rtb_Init_g[2] = controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2];
    }

    /* End of Switch: '<S78>/Init' */

    /* MATLAB Function: '<S70>/discrete kalman filter' */
    controll_discretekalmanfilter_b(controller_template_B.DataTypeConversion[0],
      controller_template_B.DataTypeConversion[3],
      controller_template_B.pitch_rot, rtb_Init_g,
      controller_template_B.pitch_bias_rot, controller_template_P.A_Value_h,
      controller_template_P.B_Value_i, controller_template_P.C_Value_c,
      controller_template_P.Q_Value_a, controller_template_P.R_Value_c,
      rtb_IntegerDelay, rtb_UnitDelay1,
      &controller_template_B.sf_discretekalmanfilter_b,
      &controller_template_DWork.sf_discretekalmanfilter_b);

    /* UnitDelay: '<S69>/Unit Delay' */
    rtb_UnitDelay[0] = controller_template_DWork.UnitDelay_DSTATE[0];
    rtb_UnitDelay[1] = controller_template_DWork.UnitDelay_DSTATE[1];
    rtb_UnitDelay[2] = controller_template_DWork.UnitDelay_DSTATE[2];

    /* UnitDelay: '<S69>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_o[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_c, 30U * sizeof(real_T));

    /* MATLAB Function: '<S69>/runFastGradient' */
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

    /* Saturate: '<S70>/Saturation' */
    rtb_Saturation = controller_template_B.sf_discretekalmanfilter_b.state_est[3]
      >= controller_template_P.Saturation_UpperSat_i ?
      controller_template_P.Saturation_UpperSat_i :
      controller_template_B.sf_discretekalmanfilter_b.state_est[3] <=
      controller_template_P.Saturation_LowerSat_o ?
      controller_template_P.Saturation_LowerSat_o :
      controller_template_B.sf_discretekalmanfilter_b.state_est[3];

    /* Sum: '<S63>/Sum' */
    pitch_cmd_b = controller_template_B.sf_runFastGradient.u_opt -
      rtb_Saturation;

    /* UnitDelay: '<S72>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_oh[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_b, sizeof(real_T) << 4U);

    /* Switch: '<S81>/Init' incorporates:
     *  UnitDelay: '<S81>/FixPt Unit Delay1'
     *  UnitDelay: '<S81>/FixPt Unit Delay2'
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
      rtb_Init_j[2] = controller_template_B.roll_rot;
    } else {
      rtb_Init_j[2] = controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2];
    }

    /* End of Switch: '<S81>/Init' */

    /* MATLAB Function: '<S72>/discrete kalman filter' */
    controll_discretekalmanfilter_b(controller_template_B.DataTypeConversion[1],
      controller_template_B.DataTypeConversion[4],
      controller_template_B.roll_rot, rtb_Init_j,
      controller_template_B.roll_bias_rot, controller_template_P.A_Value_n,
      controller_template_P.B_Value_h, controller_template_P.C_Value_p,
      controller_template_P.Q_Value_h, controller_template_P.R_Value_l,
      rtb_IntegerDelay1, rtb_UnitDelay1_oh,
      &controller_template_B.sf_discretekalmanfilter_m,
      &controller_template_DWork.sf_discretekalmanfilter_m);

    /* UnitDelay: '<S71>/Unit Delay' */
    rtb_UnitDelay_e[0] = controller_template_DWork.UnitDelay_DSTATE_j[0];
    rtb_UnitDelay_e[1] = controller_template_DWork.UnitDelay_DSTATE_j[1];
    rtb_UnitDelay_e[2] = controller_template_DWork.UnitDelay_DSTATE_j[2];

    /* UnitDelay: '<S71>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_g[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_l, 30U * sizeof(real_T));

    /* MATLAB Function: '<S71>/runFastGradient' */
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

    /* Saturate: '<S72>/Saturation' */
    rtb_Saturation_p =
      controller_template_B.sf_discretekalmanfilter_m.state_est[3] >=
      controller_template_P.Saturation_UpperSat_f ?
      controller_template_P.Saturation_UpperSat_f :
      controller_template_B.sf_discretekalmanfilter_m.state_est[3] <=
      controller_template_P.Saturation_LowerSat_k ?
      controller_template_P.Saturation_LowerSat_k :
      controller_template_B.sf_discretekalmanfilter_m.state_est[3];

    /* Sum: '<S63>/Sum1' */
    rtb_Product_l = controller_template_B.sf_runFastGradient_d.u_opt -
      rtb_Saturation_p;

    /* UnitDelay: '<S76>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_j[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_j, 9U * sizeof(real_T));

    /* Switch: '<S87>/Init' incorporates:
     *  UnitDelay: '<S87>/FixPt Unit Delay1'
     *  UnitDelay: '<S87>/FixPt Unit Delay2'
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

    /* End of Switch: '<S87>/Init' */

    /* MATLAB Function: '<S76>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.DataTypeConversion[2],
      controller_template_B.DataTypeConversion[5], rtb_Init_d, rtb_Init[2],
      controller_template_P.A_Value_f, controller_template_P.B_Value_n,
      controller_template_P.C_Value_o, controller_template_P.Q_Value_j,
      controller_template_P.R_Value_ca, rtb_IntegerDelay2, rtb_UnitDelay1_j,
      &controller_template_B.sf_discretekalmanfilter_k,
      &controller_template_DWork.sf_discretekalmanfilter_k);

    /* MATLAB Function: '<S75>/runFastGradient' incorporates:
     *  Constant: '<S75>/AA_delay'
     *  Constant: '<S75>/BB_delay'
     *  Constant: '<S75>/L'
     *  Constant: '<S75>/LL_PP'
     *  Constant: '<S75>/LL_U_ref_PP'
     *  Constant: '<S75>/LL_ref_PP'
     *  Constant: '<S75>/MM'
     *  Constant: '<S75>/PP'
     *  Constant: '<S75>/TT_PP'
     *  Constant: '<S75>/V_max'
     *  Constant: '<S75>/betas'
     *  Constant: '<S75>/i_min'
     *  UnitDelay: '<S75>/Unit Delay'
     *  UnitDelay: '<S75>/Unit Delay1'
     */
    controller_template_DWork.sfEvent_k = CALL_EVENT;

    /* MATLAB Function 'z controller MPC FG/runFastGradient': '<S86>:1' */
    /*  ugly, but simulink needs fix output sizes for vectors */
    /*  number of outputs u */
    /*  number of delay steps */
    /*  prediction horizon */
    /*  predict non-delayed state */
    /* '<S86>:1:14' */
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
    /* '<S86>:1:21' */
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

    /* '<S86>:1:22' */
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
    sin_yaw = 1.0 / controller_template_P.L_Value_m;
    for (k = 0; k < 30; k++) {
      u = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        u += controller_template_P.TT_PP_Value_b[30 * minreg + k] *
          controller_template_DWork.UnitDelay1_DSTATE_g[minreg];
      }

      tmp_2[k] = u + LL_PP_ref[k];
    }

    for (k = 0; k < 30; k++) {
      cos_yaw = controller_template_DWork.UnitDelay1_DSTATE_g[k] - sin_yaw *
        tmp_2[k];
      u = (controller_template_P.V_max_Value_i[k] <= cos_yaw) || rtIsNaN(cos_yaw)
        ? controller_template_P.V_max_Value_i[k] : cos_yaw;
      tolerance = (temp[k] >= u) || rtIsNaN(u) ? temp[k] : u;
      V_ip[k] = tolerance;
      V_i[k] = tolerance;
      U_star[k] = cos_yaw;
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
        cos_yaw = V_ip[k] - sin_yaw * tmp_2[k];
        u = (controller_template_P.V_max_Value_i[k] <= cos_yaw) || rtIsNaN
          (cos_yaw) ? controller_template_P.V_max_Value_i[k] : cos_yaw;
        u = (temp[k] >= u) || rtIsNaN(u) ? temp[k] : u;
        cos_yaw = controller_template_P.betas_Value_g[(int32_T)(1.0 + (real_T)i)
          - 1] * (u - V_i[k]);
        tolerance = u;
        u += cos_yaw;
        U_star[k] = cos_yaw;
        V_i[k] = tolerance;
        V_ip[k] = u;
      }
    }

    /*  return values: */
    sin_yaw = 0.0;
    cos_yaw = 0.0;

    /*  plot(residuals) just for testing new convergence result idea */
    /* '<S86>:1:25' */
    /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
    /*  so don't forget to backtransform after termination: */
    /* '<S86>:1:32' */
    for (k = 0; k < 30; k++) {
      b_y[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        b_y[k] += controller_template_P.TT_PP_Value_b[30 * k + minreg] * (0.5 *
          V_i[minreg]);
      }

      sin_yaw += b_y[k] * V_i[k];
      cos_yaw += LL_PP_ref[k] * V_i[k];
      U_star[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        U_star[k] += controller_template_P.PP_Value_o[30 * minreg + k] *
          V_i[minreg];
      }
    }

    /*  save outputs for delayed system */
    /* '<S86>:1:38' */
    /*  set new initial guess */
    /* '<S86>:1:42' */
    /* '<S86>:1:44' */
    controller_template_B.u_opt = U_star[0];
    controller_template_B.J_star = ((temp_idx *
      controller_template_P.MM_Value_l[0] + temp_idx_0 *
      controller_template_P.MM_Value_l[1]) * temp_idx + (temp_idx *
      controller_template_P.MM_Value_l[2] + temp_idx_0 *
      controller_template_P.MM_Value_l[3]) * temp_idx_0) + (sin_yaw + cos_yaw);
    controller_template_B.u_buff_out[0] =
      controller_template_DWork.UnitDelay_DSTATE_l[1];
    controller_template_B.u_buff_out[1] = U_star[0];
    memcpy((void *)(&controller_template_B.V_init_out[0]), (void *)&V_i[1], 29U *
           sizeof(real_T));
    controller_template_B.V_init_out[29] = 0.0;

    /* End of MATLAB Function: '<S75>/runFastGradient' */

    /* Saturate: '<S76>/Saturation' */
    rtb_Saturation_n =
      controller_template_B.sf_discretekalmanfilter_k.state_est[2] >=
      controller_template_P.Saturation_UpperSat_l ?
      controller_template_P.Saturation_UpperSat_l :
      controller_template_B.sf_discretekalmanfilter_k.state_est[2] <=
      controller_template_P.Saturation_LowerSat_c ?
      controller_template_P.Saturation_LowerSat_c :
      controller_template_B.sf_discretekalmanfilter_k.state_est[2];

    /* Sum: '<S63>/Sum2' */
    thrust_cmd_k = controller_template_B.u_opt - rtb_Saturation_n;

    /* UnitDelay: '<S74>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_n[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_lx, 9U * sizeof(real_T));

    /* Switch: '<S84>/Init' incorporates:
     *  UnitDelay: '<S84>/FixPt Unit Delay1'
     *  UnitDelay: '<S84>/FixPt Unit Delay2'
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

    /* End of Switch: '<S84>/Init' */

    /* MATLAB Function: '<S74>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.DataTypeConversion[8],
      controller_template_B.DataTypeConversion[11], rtb_Init_h, rtb_Init[3],
      controller_template_P.A_Value_k, controller_template_P.B_Value_f,
      controller_template_P.C_Value_b, controller_template_P.Q_Value_g,
      controller_template_P.R_Value_o, rtb_IntegerDelay3, rtb_UnitDelay1_n,
      &controller_template_B.sf_discretekalmanfilter_n,
      &controller_template_DWork.sf_discretekalmanfilter_n);

    /* MATLAB Function: '<S73>/runFastGradient' incorporates:
     *  Constant: '<S73>/AA_delay'
     *  Constant: '<S73>/BB_delay'
     *  Constant: '<S73>/L'
     *  Constant: '<S73>/LL_PP'
     *  Constant: '<S73>/LL_U_ref_PP'
     *  Constant: '<S73>/LL_ref_PP'
     *  Constant: '<S73>/MM'
     *  Constant: '<S73>/PP'
     *  Constant: '<S73>/TT_PP'
     *  Constant: '<S73>/V_max'
     *  Constant: '<S73>/betas'
     *  Constant: '<S73>/i_min'
     *  UnitDelay: '<S73>/Unit Delay'
     *  UnitDelay: '<S73>/Unit Delay1'
     */
    controller_template_DWork.sfEvent_n = CALL_EVENT;

    /* MATLAB Function 'yaw controller MPC FG/runFastGradient': '<S83>:1' */
    /*  ugly, but simulink needs fix output sizes for vectors */
    /*  number of outputs u */
    /*  number of delay steps */
    /*  prediction horizon */
    /*  predict non-delayed state */
    /* '<S83>:1:14' */
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
    /* '<S83>:1:21' */
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

    /* '<S83>:1:22' */
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
    sin_yaw = 1.0 / controller_template_P.L_Value_g;
    for (k = 0; k < 30; k++) {
      u = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        u += controller_template_P.TT_PP_Value_o[30 * minreg + k] *
          controller_template_DWork.UnitDelay1_DSTATE_js[minreg];
      }

      tmp_2[k] = u + LL_PP_ref[k];
    }

    for (k = 0; k < 30; k++) {
      cos_yaw = controller_template_DWork.UnitDelay1_DSTATE_js[k] - sin_yaw *
        tmp_2[k];
      u = (controller_template_P.V_max_Value_f[k] <= cos_yaw) || rtIsNaN(cos_yaw)
        ? controller_template_P.V_max_Value_f[k] : cos_yaw;
      tolerance = (temp[k] >= u) || rtIsNaN(u) ? temp[k] : u;
      V_ip[k] = tolerance;
      V_i[k] = tolerance;
      U_star[k] = cos_yaw;
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
        cos_yaw = V_ip[k] - sin_yaw * tmp_2[k];
        u = (controller_template_P.V_max_Value_f[k] <= cos_yaw) || rtIsNaN
          (cos_yaw) ? controller_template_P.V_max_Value_f[k] : cos_yaw;
        u = (temp[k] >= u) || rtIsNaN(u) ? temp[k] : u;
        cos_yaw = controller_template_P.betas_Value_j[(int32_T)(1.0 + (real_T)i)
          - 1] * (u - V_i[k]);
        tolerance = u;
        u += cos_yaw;
        U_star[k] = cos_yaw;
        V_i[k] = tolerance;
        V_ip[k] = u;
      }
    }

    /*  return values: */
    sin_yaw = 0.0;
    cos_yaw = 0.0;

    /*  plot(residuals) just for testing new convergence result idea */
    /* '<S83>:1:25' */
    /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
    /*  so don't forget to backtransform after termination: */
    /* '<S83>:1:32' */
    for (k = 0; k < 30; k++) {
      b_y[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        b_y[k] += controller_template_P.TT_PP_Value_o[30 * k + minreg] * (0.5 *
          V_i[minreg]);
      }

      sin_yaw += b_y[k] * V_i[k];
      cos_yaw += LL_PP_ref[k] * V_i[k];
      U_star[k] = 0.0;
      for (minreg = 0; minreg < 30; minreg++) {
        U_star[k] += controller_template_P.PP_Value_p[30 * minreg + k] *
          V_i[minreg];
      }
    }

    /*  save outputs for delayed system */
    /* '<S83>:1:38' */
    /*  set new initial guess */
    /* '<S83>:1:42' */
    /* '<S83>:1:44' */
    controller_template_B.u_opt_l = U_star[0];
    controller_template_B.J_star_h = ((temp_idx *
      controller_template_P.MM_Value_g[0] + temp_idx_0 *
      controller_template_P.MM_Value_g[1]) * temp_idx + (temp_idx *
      controller_template_P.MM_Value_g[2] + temp_idx_0 *
      controller_template_P.MM_Value_g[3]) * temp_idx_0) + (sin_yaw + cos_yaw);
    for (i = 0; i < 5; i++) {
      controller_template_B.u_buff_out_i[i] =
        controller_template_DWork.UnitDelay_DSTATE_jz[i + 1];
    }

    controller_template_B.u_buff_out_i[5] = U_star[0];
    memcpy((void *)(&controller_template_B.V_init_out_n[0]), (void *)&V_i[1],
           29U * sizeof(real_T));
    controller_template_B.V_init_out_n[29] = 0.0;

    /* End of MATLAB Function: '<S73>/runFastGradient' */

    /* Saturate: '<S74>/Saturation' */
    sin_yaw = controller_template_B.sf_discretekalmanfilter_n.state_est[2] >=
      controller_template_P.Saturation_UpperSat_o3 ?
      controller_template_P.Saturation_UpperSat_o3 :
      controller_template_B.sf_discretekalmanfilter_n.state_est[2] <=
      controller_template_P.Saturation_LowerSat_kn ?
      controller_template_P.Saturation_LowerSat_kn :
      controller_template_B.sf_discretekalmanfilter_n.state_est[2];

    /* Sum: '<S63>/Sum3' */
    cos_yaw = controller_template_B.u_opt_l - sin_yaw;

    /* Sum: '<S63>/Sum5' */
    controller_template_B.thrust_cmd_e = thrust_cmd_k + abspos;

    /* Update for Delay: '<S63>/Integer Delay' */
    controller_template_DWork.IntegerDelay_DSTATE = pitch_cmd_b;

    /* Update for Delay: '<S63>/Integer Delay1' */
    controller_template_DWork.IntegerDelay1_DSTATE = rtb_Product_l;

    /* Update for Delay: '<S63>/Integer Delay2' */
    controller_template_DWork.IntegerDelay2_DSTATE = thrust_cmd_k;

    /* Update for Delay: '<S63>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE = cos_yaw;

    /* Update for UnitDelay: '<S70>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
           (&controller_template_B.sf_discretekalmanfilter_b.P_est[0]), sizeof
           (real_T) << 4U);

    /* Update for UnitDelay: '<S78>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S78>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
      controller_template_P.FixPtConstant_Value_h;

    /* Update for UnitDelay: '<S78>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
      controller_template_B.sf_discretekalmanfilter_b.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
      controller_template_B.sf_discretekalmanfilter_b.state_est[1];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
      controller_template_B.sf_discretekalmanfilter_b.state_est[2];

    /* Update for UnitDelay: '<S69>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE[0] =
      controller_template_B.sf_runFastGradient.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE[1] =
      controller_template_B.sf_runFastGradient.u_buff_out[1];
    controller_template_DWork.UnitDelay_DSTATE[2] =
      controller_template_B.sf_runFastGradient.u_buff_out[2];

    /* Update for UnitDelay: '<S69>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
           (&controller_template_B.sf_runFastGradient.V_init_out[0]), 30U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S72>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
           (&controller_template_B.sf_discretekalmanfilter_m.P_est[0]), sizeof
           (real_T) << 4U);

    /* Update for UnitDelay: '<S81>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S81>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
      controller_template_P.FixPtConstant_Value_o;

    /* Update for UnitDelay: '<S81>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[1];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[2];

    /* Update for UnitDelay: '<S71>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_j[0] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE_j[1] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[1];
    controller_template_DWork.UnitDelay_DSTATE_j[2] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[2];

    /* Update for UnitDelay: '<S71>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
           (&controller_template_B.sf_runFastGradient_d.V_init_out[0]), 30U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S76>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
           (&controller_template_B.sf_discretekalmanfilter_k.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S87>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S87>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
      controller_template_P.FixPtConstant_Value_p;

    /* Update for UnitDelay: '<S87>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
      controller_template_B.sf_discretekalmanfilter_k.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
      controller_template_B.sf_discretekalmanfilter_k.state_est[1];

    /* Update for UnitDelay: '<S75>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_l[0] =
      controller_template_B.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE_l[1] =
      controller_template_B.u_buff_out[1];

    /* Update for UnitDelay: '<S75>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
           (&controller_template_B.V_init_out[0]), 30U * sizeof(real_T));

    /* Update for UnitDelay: '<S74>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
           (&controller_template_B.sf_discretekalmanfilter_n.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S84>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S84>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
      controller_template_P.FixPtConstant_Value_n;

    /* Update for UnitDelay: '<S84>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[1];

    /* Update for UnitDelay: '<S73>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      controller_template_DWork.UnitDelay_DSTATE_jz[i] =
        controller_template_B.u_buff_out_i[i];
    }

    /* End of Update for UnitDelay: '<S73>/Unit Delay' */

    /* Update for UnitDelay: '<S73>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
           (&controller_template_B.V_init_out_n[0]), 30U * sizeof(real_T));

    /* End of Outputs for SubSystem: '<S9>/MAIN CONTROL LOOP1' */

    /* SignalConversion: '<S67>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFi_f[0] =
      controller_template_B.DataTypeConversion[0];
    rtb_TmpSignalConversionAtToFi_f[1] =
      controller_template_B.DataTypeConversion[3];
    rtb_TmpSignalConversionAtToFi_f[2] =
      controller_template_B.DataTypeConversion[7];
    rtb_TmpSignalConversionAtToFi_f[3] = controller_template_B.X_ref_x[0];
    rtb_TmpSignalConversionAtToFi_f[4] = pitch_cmd_b;
    rtb_TmpSignalConversionAtToFi_f[5] =
      controller_template_B.DataTypeConversion[1];
    rtb_TmpSignalConversionAtToFi_f[6] =
      controller_template_B.DataTypeConversion[4];
    rtb_TmpSignalConversionAtToFi_f[7] =
      controller_template_B.DataTypeConversion[6];
    rtb_TmpSignalConversionAtToFi_f[8] = controller_template_B.X_ref_y[0];
    rtb_TmpSignalConversionAtToFi_f[9] = rtb_Product_l;
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
    rtb_TmpSignalConversionAtToFi_f[17] = cos_yaw;

    /* ToFile: '<S67>/To File' */
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

    /* SignalConversion: '<S67>/TmpSignal ConversionAtTo File1Inport1' */
    rtb_TmpSignalConversionAtToFile[0] = rtb_Saturation;
    rtb_TmpSignalConversionAtToFile[1] = rtb_Saturation_p;
    rtb_TmpSignalConversionAtToFile[2] = rtb_Saturation_n;
    rtb_TmpSignalConversionAtToFile[3] = sin_yaw;

    /* ToFile: '<S67>/To File1' */
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

    /* Gain: '<S67>/rad -> deg2' */
    controller_template_B.raddeg2[0] = controller_template_P.raddeg2_Gain *
      controller_template_B.DataTypeConversion[7];
    controller_template_B.raddeg2[1] = controller_template_P.raddeg2_Gain *
      controller_template_B.DataTypeConversion[10];
    controller_template_B.raddeg2[2] = controller_template_P.raddeg2_Gain *
      pitch_cmd_b;

    /* Gain: '<S67>/rad -> deg1' */
    controller_template_B.raddeg1[0] = controller_template_P.raddeg1_Gain *
      controller_template_B.DataTypeConversion[6];
    controller_template_B.raddeg1[1] = controller_template_P.raddeg1_Gain *
      controller_template_B.DataTypeConversion[9];
    controller_template_B.raddeg1[2] = controller_template_P.raddeg1_Gain *
      rtb_Product_l;

    /* Gain: '<S67>/rad -> deg3' */
    controller_template_B.raddeg3[0] = controller_template_P.raddeg3_Gain *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg3[1] = controller_template_P.raddeg3_Gain *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg3[2] = controller_template_P.raddeg3_Gain *
      cos_yaw;

    /* Gain: '<S67>/rad -> deg' */
    controller_template_B.raddeg[0] = controller_template_P.raddeg_Gain *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg[1] = controller_template_P.raddeg_Gain *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg[2] = controller_template_P.raddeg_Gain *
      controller_template_B.X_ref_yaw[0];
    controller_template_B.raddeg[3] = controller_template_P.raddeg_Gain *
      controller_template_B.X_ref_yaw[1];

    /* Outputs for Atomic SubSystem: '<S9>/decoupling and rotation' */
    /* Inport: '<S64>/bias_W' */
    controller_template_B.bias_W[0] = rtb_TmpSignalConversionAtToFile[0];
    controller_template_B.bias_W[1] = rtb_TmpSignalConversionAtToFile[1];
    controller_template_B.bias_W[2] = rtb_TmpSignalConversionAtToFile[2];
    controller_template_B.bias_W[3] = rtb_TmpSignalConversionAtToFile[3];

    /* Inport: '<S64>/cmd_W' */
    controller_template_B.cmd_W[0] = pitch_cmd_b;
    controller_template_B.cmd_W[1] = rtb_Product_l;
    controller_template_B.cmd_W[2] = controller_template_B.thrust_cmd_e;
    controller_template_B.cmd_W[3] = cos_yaw;

    /* MATLAB Function: '<S89>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S89>/g'
     */
    controller_template_DWork.sfEvent_f = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/decoupling /Embedded MATLAB Function': '<S91>:1' */
    /* '<S91>:1:4' */
    sin_yaw = controller_template_B.cmd_W[2] / (cos
      (controller_template_B.pitch_rot) * cos(controller_template_B.roll_rot));

    /* '<S91>:1:6' */
    controller_template_B.pitch_cmd_comp =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value_m / sin_yaw * controller_template_B.cmd_W[0];

    /* '<S91>:1:7' */
    controller_template_B.roll_cmd_comp =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value_m / sin_yaw * controller_template_B.cmd_W[1];

    /*  pitch_cmd_comp=pitch_cmd; */
    /*  roll_cmd_comp=roll_cmd; */
    /*  pitch_cmd_comp = atan(Fx/(-thrust_comp)); */
    /*  roll_cmd_comp = atan(Fy/(thrust_comp)); */
    /*  pitch_cmd_comp = atan(-g*m*pitch_cmd/(-thrust)); */
    /*  roll_cmd_comp = atan(g*m*roll_cmd*cos(pitch_meas)/(thrust)); */
    controller_template_B.thrust_comp = sin_yaw;

    /* MATLAB Function: '<S90>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_b = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S92>:1' */
    /* '<S92>:1:3' */
    sin_yaw = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S92>:1:4' */
    cos_yaw = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S92>:1:6' */
    /* '<S92>:1:8' */
    /* '<S92>:1:9' */
    controller_template_B.pitch_rot_k = cos_yaw *
      controller_template_B.pitch_cmd_comp + -sin_yaw *
      controller_template_B.roll_cmd_comp;

    /* '<S92>:1:10' */
    controller_template_B.roll_rot_a = sin_yaw *
      controller_template_B.pitch_cmd_comp + cos_yaw *
      controller_template_B.roll_cmd_comp;

    /* '<S92>:1:12' */
    /* '<S92>:1:13' */
    controller_template_B.pitch_bias_rot_e = cos_yaw *
      controller_template_B.bias_W[0] + -sin_yaw * controller_template_B.bias_W
      [1];

    /* '<S92>:1:14' */
    controller_template_B.roll_bias_rot_b = sin_yaw *
      controller_template_B.bias_W[0] + cos_yaw * controller_template_B.bias_W[1];

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
    controller_template_B.pitch_cmd = controller_template_B.pitch_rot_k;
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
    controller_template_B.roll_cmd = controller_template_B.roll_rot_a;
  } else {
    controller_template_B.roll_cmd = controller_template_P.roll_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/gravity'
   */
  sin_yaw = controller_template_P.gravity_Value_ch *
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

  /* Switch: '<S61>/SwitchControl' incorporates:
   *  Constant: '<S61>/Constant'
   *  Constant: '<S7>/yaw_rate'
   *  Gain: '<S7>/yaw_cmd2yaw'
   */
  if (controller_template_P.Constant_Value_a3 >
      controller_template_P.SwitchControl_Threshold_e) {
    cos_yaw = controller_template_P.yaw_cmd2yaw_Gain *
      controller_template_B.yaw_rate_cmd;
  } else {
    cos_yaw = controller_template_P.yaw_rate_Value;
  }

  /* End of Switch: '<S61>/SwitchControl' */

  /* Gain: '<S7>/Gain4' */
  cos_yaw *= controller_template_P.Gain4_Gain;

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
  arg_cmd_out[2] = (real32_T)(((controller_template_B.thrust_cmd - sin_yaw) *
    controller_template_P.trhust_cmd2thrust_Gain + sin_yaw) *
    controller_template_P.Gain_Gain_k * controller_template_P.Gain3_Gain);
  arg_cmd_out[3] = (real32_T)cos_yaw;

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S3>/pitch_bias'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    controller_template_B.pitch_bias = controller_template_B.pitch_bias_rot_i;
  } else if (controller_template_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    controller_template_B.pitch_bias = controller_template_B.pitch_bias_rot_e;
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
    controller_template_B.roll_bias = controller_template_B.roll_bias_rot_b;
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

  /* Update for UnitDelay: '<S62>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S62>/FixPt Constant'
   */
  controller_template_DWork.FixPtUnitDelay2_DSTATE =
    controller_template_P.FixPtConstant_Value_i;

  /* Switch: '<S62>/Reset' */
  if (rtb_MultiportSwitch1 != 0.0) {
    /* Update for UnitDelay: '<S62>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S62>/Initial Condition'
     */
    controller_template_DWork.FixPtUnitDelay1_DSTATE[0] =
      controller_template_P.InitialCondition_Value_b;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[1] =
      controller_template_P.InitialCondition_Value_b;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[2] =
      controller_template_P.InitialCondition_Value_b;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[3] =
      controller_template_P.InitialCondition_Value_b;
  } else {
    /* Update for UnitDelay: '<S62>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE[0] =
      controller_template_B.pitch_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[1] =
      controller_template_B.roll_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[2] =
      controller_template_B.thrust_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[3] =
      controller_template_B.yaw_rate_bias;
  }

  /* End of Switch: '<S62>/Reset' */

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
  controller_template_M->Sizes.checksums[0] = (2294414305U);
  controller_template_M->Sizes.checksums[1] = (797197336U);
  controller_template_M->Sizes.checksums[2] = (1111424642U);
  controller_template_M->Sizes.checksums[3] = (2160926172U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[56];
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
    systemRan[20] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
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
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
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
    systemRan[52] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[53] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[54] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[55] = (sysRanDType *)
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
    /* Start for UnitDelay: '<S22>/Unit Delay2' */
    controller_template_B.UnitDelay2 = controller_template_P.UnitDelay2_X0;

    /* Start for UnitDelay: '<S31>/Unit Delay2' */
    controller_template_B.UnitDelay2_o = controller_template_P.UnitDelay2_X0_d;

    /* End of Start for SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* Start for ToFile: '<S15>/To File' */
    {
      char fileName[509] = "ForceLogData.m";
      FILE *fp = (NULL);
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(controller_template_M,
                          "Error creating .mat file ForceLogData.m");
        return;
      }

      if (rt_WriteMat4FileHeader(fp,29,0,"ans")) {
        rtmSetErrorStatus(controller_template_M,
                          "Error writing mat file header to file ForceLogData.m");
        return;
      }

      controller_template_DWork.ToFile_IWORK_g.Count = 0;
      controller_template_DWork.ToFile_IWORK_g.Decimation = -1;
      controller_template_DWork.ToFile_PWORK_p.FilePtr = fp;
    }

    /* InitializeConditions for MATLAB Function: '<S14>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_bq = CALL_EVENT;
    controller_template_DWork.is_active_c26_Hquad_control_L_f = 0U;

    /* InitializeConditions for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* InitializeConditions for Delay: '<S10>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE_k =
      controller_template_P.IntegerDelay3_InitialCondition;

    /* InitializeConditions for MATLAB Function: '<S17>/MATLAB Function' */
    controller_template_DWork.sfEvent_fk = CALL_EVENT;
    controller_template_DWork.is_active_c8_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S22>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE =
      controller_template_P.UnitDelay2_X0;

    /* InitializeConditions for MATLAB Function: '<S29>/MATLAB Function' */
    controller_template_DWork.sfEvent_cm = CALL_EVENT;
    controller_template_DWork.is_active_c7_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S22>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_kl = CALL_EVENT;
    controller_template_DWork.is_active_c1_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S24>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_d =
      controller_template_P.UnitDelay2_X0_m;

    /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_jv =
      controller_template_P.UnitDelay_X0;

    /* InitializeConditions for UnitDelay: '<S31>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_l =
      controller_template_P.UnitDelay2_X0_d;

    /* InitializeConditions for MATLAB Function: '<S36>/MATLAB Function' */
    controller_template_DWork.sfEvent_i = CALL_EVENT;
    controller_template_DWork.is_active_c5_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S31>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_cd = CALL_EVENT;
    controller_template_DWork.is_active_c2_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S32>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_k =
      controller_template_P.UnitDelay2_X0_n;

    /* InitializeConditions for UnitDelay: '<S32>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_f =
      controller_template_P.UnitDelay_X0_f;

    /* InitializeConditions for MATLAB Function: '<S48>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_k0 = CALL_EVENT;
    controller_template_DWork.is_active_c3_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S49>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_b =
      controller_template_P.UnitDelay2_X0_o;

    /* InitializeConditions for UnitDelay: '<S49>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_fw =
      controller_template_P.UnitDelay_X0_i;

    /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_bg, (void *)
           controller_template_P.UnitDelay1_X0, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
      controller_template_P.FixPtUnitDelay2_X0;

    /* InitializeConditions for UnitDelay: '<S46>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0] =
      controller_template_P.FixPtUnitDelay1_X0;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1] =
      controller_template_P.FixPtUnitDelay1_X0;

    /* InitializeConditions for MATLAB Function: '<S20>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter);

    /* InitializeConditions for UnitDelay: '<S38>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_g =
      controller_template_P.UnitDelay2_X0_ng;

    /* InitializeConditions for MATLAB Function: '<S44>/MATLAB Function' */
    controller_template_DWork.sfEvent_l = CALL_EVENT;
    controller_template_DWork.is_active_c6_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S38>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_jv = CALL_EVENT;
    controller_template_DWork.is_active_c4_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S39>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_ga =
      controller_template_P.UnitDelay2_X0_i;

    /* InitializeConditions for UnitDelay: '<S39>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_p =
      controller_template_P.UnitDelay_X0_c;

    /* InitializeConditions for UnitDelay: '<S24>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_a =
      controller_template_P.UnitDelay1_X0_i;

    /* InitializeConditions for UnitDelay: '<S32>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_ji =
      controller_template_P.UnitDelay1_X0_d;

    /* InitializeConditions for UnitDelay: '<S39>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_c3 =
      controller_template_P.UnitDelay1_X0_j;

    /* InitializeConditions for UnitDelay: '<S49>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_m =
      controller_template_P.UnitDelay1_X0_f;

    /* End of InitializeConditions for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

    /* InitializeConditions for UnitDelay: '<S51>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_e =
      controller_template_P.FixPtUnitDelay2_X0_j;

    /* InitializeConditions for UnitDelay: '<S51>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_k =
      controller_template_P.FixPtUnitDelay1_X0_c;

    /* InitializeConditions for MATLAB Function: '<S11>/generate_X_ref_x' */
    controller_template_DWork.sfEvent_m = CALL_EVENT;
    controller_template_DWork.is_active_c2_Hquad_control_LIB_ = 0U;

    /* InitializeConditions for MATLAB Function: '<S11>/generate_X_ref_y' */
    controller_template_DWork.sfEvent_dw = CALL_EVENT;
    controller_template_DWork.is_active_c22_Hquad_control_LIB = 0U;

    /* InitializeConditions for MATLAB Function: '<S11>/generate_X_ref_yaw' */
    controller_template_DWork.sfEvent_h = CALL_EVENT;
    controller_template_DWork.is_active_c23_Hquad_control_LIB = 0U;

    /* InitializeConditions for MATLAB Function: '<S11>/generate_X_ref_z' */
    controller_template_DWork.sfEvent_d = CALL_EVENT;
    controller_template_DWork.is_active_c24_Hquad_control_LIB = 0U;

    /* InitializeConditions for Atomic SubSystem: '<S2>/decoupling and rotation' */
    /* InitializeConditions for MATLAB Function: '<S56>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_c = CALL_EVENT;
    controller_template_DWork.is_active_c1_Hquad_control_LI_l = 0U;

    /* InitializeConditions for MATLAB Function: '<S57>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_j = CALL_EVENT;
    controller_template_DWork.is_active_c4_Hquad_control_LI_d = 0U;

    /* End of InitializeConditions for SubSystem: '<S2>/decoupling and rotation' */
    /* End of Start for SubSystem: '<Root>/FreeFlight Pos Ctrl' */

    /* Start for Enabled SubSystem: '<Root>/pos controller' */
    /* Start for ToFile: '<S67>/To File' */
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

    /* Start for ToFile: '<S67>/To File1' */
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

    /* InitializeConditions for MATLAB Function: '<S66>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent = CALL_EVENT;
    controller_template_DWork.is_active_c26_Hquad_control_LIB = 0U;

    /* InitializeConditions for Atomic SubSystem: '<S9>/MAIN CONTROL LOOP1' */
    /* InitializeConditions for Delay: '<S63>/Integer Delay' */
    controller_template_DWork.IntegerDelay_DSTATE =
      controller_template_P.IntegerDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S63>/Integer Delay1' */
    controller_template_DWork.IntegerDelay1_DSTATE =
      controller_template_P.IntegerDelay1_InitialCondition;

    /* InitializeConditions for Delay: '<S63>/Integer Delay2' */
    controller_template_DWork.IntegerDelay2_DSTATE =
      controller_template_P.IntegerDelay2_InitialCondition;

    /* InitializeConditions for Delay: '<S63>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE =
      controller_template_P.IntegerDelay3_InitialConditio_c;

    /* InitializeConditions for UnitDelay: '<S70>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
           controller_template_P.UnitDelay1_X0_c, sizeof(real_T) << 4U);

    /* InitializeConditions for UnitDelay: '<S78>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
      controller_template_P.FixPtUnitDelay2_X0_d;

    /* InitializeConditions for UnitDelay: '<S78>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
      controller_template_P.FixPtUnitDelay1_X0_f;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
      controller_template_P.FixPtUnitDelay1_X0_f;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
      controller_template_P.FixPtUnitDelay1_X0_f;

    /* InitializeConditions for MATLAB Function: '<S70>/discrete kalman filter' */
    con_discretekalmanfilter_k_Init
      (&controller_template_DWork.sf_discretekalmanfilter_b);

    /* InitializeConditions for UnitDelay: '<S69>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE[0] =
      controller_template_P.UnitDelay_X0_fc[0];
    controller_template_DWork.UnitDelay_DSTATE[1] =
      controller_template_P.UnitDelay_X0_fc[1];
    controller_template_DWork.UnitDelay_DSTATE[2] =
      controller_template_P.UnitDelay_X0_fc[2];

    /* InitializeConditions for UnitDelay: '<S69>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
           controller_template_P.UnitDelay1_X0_k, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S69>/runFastGradient' */
    controller_runFastGradient_Init
      (&controller_template_DWork.sf_runFastGradient);

    /* InitializeConditions for UnitDelay: '<S72>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
           controller_template_P.UnitDelay1_X0_fk, sizeof(real_T) << 4U);

    /* InitializeConditions for UnitDelay: '<S81>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
      controller_template_P.FixPtUnitDelay2_X0_n;

    /* InitializeConditions for UnitDelay: '<S81>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
      controller_template_P.FixPtUnitDelay1_X0_n;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
      controller_template_P.FixPtUnitDelay1_X0_n;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
      controller_template_P.FixPtUnitDelay1_X0_n;

    /* InitializeConditions for MATLAB Function: '<S72>/discrete kalman filter' */
    con_discretekalmanfilter_k_Init
      (&controller_template_DWork.sf_discretekalmanfilter_m);

    /* InitializeConditions for UnitDelay: '<S71>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_j[0] =
      controller_template_P.UnitDelay_X0_ik[0];
    controller_template_DWork.UnitDelay_DSTATE_j[1] =
      controller_template_P.UnitDelay_X0_ik[1];
    controller_template_DWork.UnitDelay_DSTATE_j[2] =
      controller_template_P.UnitDelay_X0_ik[2];

    /* InitializeConditions for UnitDelay: '<S71>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
           controller_template_P.UnitDelay1_X0_jc, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S71>/runFastGradient' */
    controller_runFastGradient_Init
      (&controller_template_DWork.sf_runFastGradient_d);

    /* InitializeConditions for UnitDelay: '<S76>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
           controller_template_P.UnitDelay1_X0_cw, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S87>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
      controller_template_P.FixPtUnitDelay2_X0_do;

    /* InitializeConditions for UnitDelay: '<S87>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
      controller_template_P.FixPtUnitDelay1_X0_cl;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
      controller_template_P.FixPtUnitDelay1_X0_cl;

    /* InitializeConditions for MATLAB Function: '<S76>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter_k);

    /* InitializeConditions for UnitDelay: '<S75>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_l[0] =
      controller_template_P.UnitDelay_X0_a[0];
    controller_template_DWork.UnitDelay_DSTATE_l[1] =
      controller_template_P.UnitDelay_X0_a[1];

    /* InitializeConditions for UnitDelay: '<S75>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
           controller_template_P.UnitDelay1_X0_b, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S75>/runFastGradient' */
    controller_template_DWork.sfEvent_k = CALL_EVENT;
    controller_template_DWork.is_active_c8_Hquad_control_LIB_ = 0U;

    /* InitializeConditions for UnitDelay: '<S74>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
           controller_template_P.UnitDelay1_X0_n, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S84>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
      controller_template_P.FixPtUnitDelay2_X0_i;

    /* InitializeConditions for UnitDelay: '<S84>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
      controller_template_P.FixPtUnitDelay1_X0_e;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
      controller_template_P.FixPtUnitDelay1_X0_e;

    /* InitializeConditions for MATLAB Function: '<S74>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter_n);

    /* InitializeConditions for UnitDelay: '<S73>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      controller_template_DWork.UnitDelay_DSTATE_jz[i] =
        controller_template_P.UnitDelay_X0_fj[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S73>/Unit Delay' */

    /* InitializeConditions for UnitDelay: '<S73>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
           controller_template_P.UnitDelay1_X0_o, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S73>/runFastGradient' */
    controller_template_DWork.sfEvent_n = CALL_EVENT;
    controller_template_DWork.is_active_c9_Hquad_control_LIB_ = 0U;

    /* End of InitializeConditions for SubSystem: '<S9>/MAIN CONTROL LOOP1' */

    /* InitializeConditions for Atomic SubSystem: '<S9>/decoupling and rotation' */
    /* InitializeConditions for MATLAB Function: '<S89>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_f = CALL_EVENT;
    controller_template_DWork.is_active_c1_Hquad_control_LIB_ = 0U;

    /* InitializeConditions for MATLAB Function: '<S90>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_b = CALL_EVENT;
    controller_template_DWork.is_active_c4_Hquad_control_LIB_ = 0U;

    /* End of InitializeConditions for SubSystem: '<S9>/decoupling and rotation' */
    /* End of Start for SubSystem: '<Root>/pos controller' */
  }

  /* InitializeConditions for UnitDelay: '<S62>/FixPt Unit Delay2' */
  controller_template_DWork.FixPtUnitDelay2_DSTATE =
    controller_template_P.FixPtUnitDelay2_X0_g;

  /* InitializeConditions for UnitDelay: '<S62>/FixPt Unit Delay1' */
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

  /* Terminate for ToFile: '<S15>/To File' */
  {
    FILE *fp = (FILE *) controller_template_DWork.ToFile_PWORK_p.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "ForceLogData.m";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(controller_template_M,
                          "Error closing MAT-file ForceLogData.m");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(controller_template_M,
                          "Error reopening MAT-file ForceLogData.m");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 29,
           controller_template_DWork.ToFile_IWORK_g.Count, "ans")) {
        rtmSetErrorStatus(controller_template_M,
                          "Error writing header for ans to MAT-file ForceLogData.m");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(controller_template_M,
                          "Error closing MAT-file ForceLogData.m");
        return;
      }

      controller_template_DWork.ToFile_PWORK_p.FilePtr = (NULL);
    }
  }

  /* End of Terminate for SubSystem: '<Root>/FreeFlight Pos Ctrl' */

  /* Terminate for Enabled SubSystem: '<Root>/pos controller' */

  /* Terminate for ToFile: '<S67>/To File' */
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

  /* Terminate for ToFile: '<S67>/To File1' */
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
