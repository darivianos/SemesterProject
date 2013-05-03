/*
 * File: FG_traj_fast.cpp
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

#include "FG_traj_fast.h"
#include "FG_traj_fast_private.h"
#include "FG_traj_fast_dt.h"

/* Block signals (auto storage) */
BlockIO_FG_traj_fast FG_traj_fast_B;

/* Block states (auto storage) */
D_Work_FG_traj_fast FG_traj_fast_DWork;

/* Real-time model */
RT_MODEL_FG_traj_fast FG_traj_fast_M_;
RT_MODEL_FG_traj_fast *const FG_traj_fast_M = &FG_traj_fast_M_;

/* Forward declaration for local functions */
static void FG_traj_fast_inv(const real_T x[9], real_T y[9]);

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
 * Output and update for atomic system:
 *    '<S15>/runFastGradient'
 *    '<S17>/runFastGradient'
 *    '<S46>/runFastGradient'
 *    '<S48>/runFastGradient'
 */
void FG_traj_fast_runFastGradient(const real_T rtu_TT_PP[900], const real_T
  rtu_LL_PP[90], const real_T rtu_LL_ref_PP[2790], const real_T rtu_LL_U_ref_PP
  [900], const real_T rtu_PP[900], const real_T rtu_AA_delay[9], const real_T
  rtu_BB_delay[9], const real_T rtu_x[3], const real_T rtu_X_ref[93], const
  real_T rtu_V_max[30], real_T rtu_i_min, const real_T rtu_betas[7], real_T
  rtu_L, const real_T rtu_u_buff[3], const real_T rtu_V_init[30],
  rtB_runFastGradient_FG_traj_fas *localB)
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

  /* MATLAB Function 'x controller MPC FG  /runFastGradient': '<S23>:1' */
  /*  ugly, but simulink needs fix output sizes for vectors */
  /*  number of outputs u */
  /*  number of delay steps */
  /*  prediction horizon */
  /*  predict non-delayed state */
  /* '<S23>:1:14' */
  /*  TODO get U_ref from trajectory */
  /*  set optimization variables */
  /* '<S23>:1:21' */
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

  /* '<S23>:1:22' */
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
  /* '<S23>:1:25' */
  /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
  /*  so don't forget to backtransform after termination: */
  /* '<S23>:1:32' */
  for (i_0 = 0; i_0 < 30; i_0++) {
    U_star[i_0] = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      U_star[i_0] += rtu_PP[30 * i_1 + i_0] * V_i[i_1];
    }
  }

  /*  save outputs for delayed system */
  /* '<S23>:1:38' */
  /*  set new initial guess */
  /* '<S23>:1:42' */
  /* '<S23>:1:44' */
  localB->u_opt = U_star[0];
  localB->u_buff_out[0] = rtu_u_buff[1];
  localB->u_buff_out[1] = rtu_u_buff[2];
  localB->u_buff_out[2] = U_star[0];
  memcpy(&localB->V_init_out[0], &V_i[1], 29U * sizeof(real_T));
  localB->V_init_out[29] = 0.0;
}

/* Function for MATLAB Function: '<S16>/discrete kalman filter' */
static void FG_traj_fast_inv(const real_T x[9], real_T y[9])
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
 *    '<S16>/discrete kalman filter'
 *    '<S18>/discrete kalman filter'
 *    '<S47>/discrete kalman filter'
 *    '<S49>/discrete kalman filter'
 */
void FG_traj_fa_discretekalmanfilter(real_T rtu_y, real_T rtu_y_e, real_T
  rtu_y_f, const real_T rtu_state[3], real_T rtu_state_h, const real_T rtu_A[16],
  const real_T rtu_B[4], const real_T rtu_C[12], const real_T rtu_Q[16], const
  real_T rtu_R[9], real_T rtu_u, const real_T rtu_P[16],
  rtB_discretekalmanfilter_FG_tra *localB)
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

  /* MATLAB Function 'x states estimator bias/discrete kalman filter': '<S25>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S25>:1:10' */
  for (i = 0; i < 4; i++) {
    /* SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = (((rtu_A[i + 4] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
             8] * rtu_state[2]) + rtu_A[i + 12] * rtu_state_h) + rtu_B[i] *
      rtu_u;
  }

  /* '<S25>:1:11' */
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
  /* '<S25>:1:14' */
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

  FG_traj_fast_inv(tmp, tmp_0);
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

  /* '<S25>:1:15' */
  /* '<S25>:1:16' */
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

  /* SignalConversion: '<S25>/TmpSignal ConversionAt SFunction Inport8' */
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
 *    '<S20>/discrete kalman filter'
 *    '<S22>/discrete kalman filter'
 *    '<S51>/discrete kalman filter'
 *    '<S53>/discrete kalman filter'
 */
void FG_traj__discretekalmanfilter_j(real_T rtu_y, real_T rtu_y_m, const real_T
  rtu_state[2], real_T rtu_state_n, const real_T rtu_A[9], const real_T rtu_B[3],
  const real_T rtu_C[6], const real_T rtu_Q[9], const real_T rtu_R[4], real_T
  rtu_u, const real_T rtu_P[9], rtB_discretekalmanfilter_FG_t_p *localB)
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

  /* MATLAB Function 'yaw states estimator bias/discrete kalman filter': '<S31>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S31>:1:10' */
  for (i = 0; i < 3; i++) {
    /* SignalConversion: '<S31>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = ((rtu_A[i + 3] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
            6] * rtu_state_n) + rtu_B[i] * rtu_u;
  }

  /* '<S31>:1:11' */
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
  /* '<S31>:1:14' */
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

  /* '<S31>:1:15' */
  /* '<S31>:1:16' */
  for (i = 0; i < 9; i++) {
    I[i] = 0;
  }

  I[0] = 1;
  I[4] = 1;
  I[8] = 1;
  for (i = 0; i < 2; i++) {
    tmp[i] = rtu_C[i + 4] * x[2] + (rtu_C[i + 2] * x[1] + rtu_C[i] * x[0]);
  }

  /* SignalConversion: '<S31>/TmpSignal ConversionAt SFunction Inport8' */
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

/*
 * Initial conditions for atomic system:
 *    '<S6>/MAIN CONTROL LOOP1'
 *    '<S7>/MAIN CONTROL LOOP1'
 */
void FG_traj_f_MAINCONTROLLOOP1_Init(rtDW_MAINCONTROLLOOP1_FG_traj_f *localDW,
  rtP_MAINCONTROLLOOP1_FG_traj_fa *localP)
{
  int32_T i;

  /* InitializeConditions for Delay: '<S9>/Integer Delay' */
  localDW->IntegerDelay_DSTATE = localP->IntegerDelay_InitialCondition;

  /* InitializeConditions for Delay: '<S9>/Integer Delay1' */
  localDW->IntegerDelay1_DSTATE = localP->IntegerDelay1_InitialCondition;

  /* InitializeConditions for Delay: '<S9>/Integer Delay2' */
  localDW->IntegerDelay2_DSTATE = localP->IntegerDelay2_InitialCondition;

  /* InitializeConditions for Delay: '<S9>/Integer Delay3' */
  localDW->IntegerDelay3_DSTATE = localP->IntegerDelay3_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE[0], &localP->UnitDelay1_InitialCondition[0],
         sizeof(real_T) << 4U);

  /* InitializeConditions for UnitDelay: '<S24>/FixPt Unit Delay2' */
  localDW->FixPtUnitDelay2_DSTATE = localP->FixPtUnitDelay2_InitialConditio;

  /* InitializeConditions for UnitDelay: '<S24>/FixPt Unit Delay1' */
  localDW->FixPtUnitDelay1_DSTATE[0] = localP->FixPtUnitDelay1_InitialConditio;
  localDW->FixPtUnitDelay1_DSTATE[1] = localP->FixPtUnitDelay1_InitialConditio;
  localDW->FixPtUnitDelay1_DSTATE[2] = localP->FixPtUnitDelay1_InitialConditio;

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay' */
  localDW->UnitDelay_DSTATE[0] = localP->UnitDelay_InitialCondition[0];
  localDW->UnitDelay_DSTATE[1] = localP->UnitDelay_InitialCondition[1];
  localDW->UnitDelay_DSTATE[2] = localP->UnitDelay_InitialCondition[2];

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE_f[0],
         &localP->UnitDelay1_InitialCondition_h[0], 30U * sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE_m[0],
         &localP->UnitDelay1_InitialCondition_b[0], sizeof(real_T) << 4U);

  /* InitializeConditions for UnitDelay: '<S27>/FixPt Unit Delay2' */
  localDW->FixPtUnitDelay2_DSTATE_f = localP->FixPtUnitDelay2_InitialCondit_d;

  /* InitializeConditions for UnitDelay: '<S27>/FixPt Unit Delay1' */
  localDW->FixPtUnitDelay1_DSTATE_g[0] = localP->FixPtUnitDelay1_InitialCondit_m;
  localDW->FixPtUnitDelay1_DSTATE_g[1] = localP->FixPtUnitDelay1_InitialCondit_m;
  localDW->FixPtUnitDelay1_DSTATE_g[2] = localP->FixPtUnitDelay1_InitialCondit_m;

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[0] = localP->UnitDelay_InitialCondition_n[0];
  localDW->UnitDelay_DSTATE_p[1] = localP->UnitDelay_InitialCondition_n[1];
  localDW->UnitDelay_DSTATE_p[2] = localP->UnitDelay_InitialCondition_n[2];

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE_mi[0],
         &localP->UnitDelay1_InitialCondition_o[0], 30U * sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE_c[0],
         &localP->UnitDelay1_InitialCondition_ou[0], 9U * sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S33>/FixPt Unit Delay2' */
  localDW->FixPtUnitDelay2_DSTATE_h = localP->FixPtUnitDelay2_InitialCondit_b;

  /* InitializeConditions for UnitDelay: '<S33>/FixPt Unit Delay1' */
  localDW->FixPtUnitDelay1_DSTATE_j[0] = localP->FixPtUnitDelay1_InitialCondit_p;
  localDW->FixPtUnitDelay1_DSTATE_j[1] = localP->FixPtUnitDelay1_InitialCondit_p;

  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay' */
  localDW->UnitDelay_DSTATE_d[0] = localP->UnitDelay_InitialCondition_f[0];
  localDW->UnitDelay_DSTATE_d[1] = localP->UnitDelay_InitialCondition_f[1];

  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE_j[0],
         &localP->UnitDelay1_InitialCondition_m[0], 30U * sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE_h[0],
         &localP->UnitDelay1_InitialCondition_oo[0], 9U * sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S30>/FixPt Unit Delay2' */
  localDW->FixPtUnitDelay2_DSTATE_g = localP->FixPtUnitDelay2_InitialCondit_i;

  /* InitializeConditions for UnitDelay: '<S30>/FixPt Unit Delay1' */
  localDW->FixPtUnitDelay1_DSTATE_p[0] = localP->FixPtUnitDelay1_InitialCondit_k;
  localDW->FixPtUnitDelay1_DSTATE_p[1] = localP->FixPtUnitDelay1_InitialCondit_k;

  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay' */
  for (i = 0; i < 6; i++) {
    localDW->UnitDelay_DSTATE_j[i] = localP->UnitDelay_InitialCondition_k[i];
  }

  /* End of InitializeConditions for UnitDelay: '<S19>/Unit Delay' */

  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE_p[0],
         &localP->UnitDelay1_InitialCondition_g[0], 30U * sizeof(real_T));
}

/*
 * Output and update for atomic system:
 *    '<S6>/MAIN CONTROL LOOP1'
 *    '<S7>/MAIN CONTROL LOOP1'
 */
void FG_traj_fast_MAINCONTROLLOOP1(real_T rtu_mass, real_T rtu_x, real_T rtu_x_m,
  real_T rtu_x_p, real_T rtu_y, real_T rtu_y_k, real_T rtu_y_m, real_T rtu_z,
  real_T rtu_z_f, real_T rtu_yaw, real_T rtu_yaw_m, const real_T rtu_X_ref_yaw
  [62], const real_T rtu_X_ref_z[62], const real_T rtu_X_ref_x[93], real_T
  rtu_14, const real_T rtu_X_ref_y[93], real_T rtu_16, real_T rtu_17, real_T
  rtu_18, rtB_MAINCONTROLLOOP1_FG_traj_fa *localB,
  rtDW_MAINCONTROLLOOP1_FG_traj_f *localDW, rtP_MAINCONTROLLOOP1_FG_traj_fa
  *localP)
{
  /* local block i/o variables */
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
  real_T LL_PP_ref[30];
  real_T U_star[30];
  real_T V_min[30];
  real_T L_inv;
  real_T V_i[30];
  real_T V_ip[30];
  real_T V_i_0[30];
  real_T rtb_Product;
  real_T rtb_thrust_cmd_b;
  int32_T i;
  real_T tmp[30];
  int32_T i_0;
  real_T tmp_0[2];
  int32_T i_1;
  real_T tmp_1[6];
  real_T U_star_0;
  real_T rtb_u_buff_out_idx;
  real_T rtb_u_buff_out_idx_0;
  real_T unnamed_idx;
  real_T unnamed_idx_0;

  /* Delay: '<S9>/Integer Delay' */
  rtb_IntegerDelay = localDW->IntegerDelay_DSTATE;

  /* Delay: '<S9>/Integer Delay1' */
  rtb_IntegerDelay1 = localDW->IntegerDelay1_DSTATE;

  /* Delay: '<S9>/Integer Delay2' */
  rtb_IntegerDelay2 = localDW->IntegerDelay2_DSTATE;

  /* Delay: '<S9>/Integer Delay3' */
  rtb_IntegerDelay3 = localDW->IntegerDelay3_DSTATE;

  /* Product: '<S9>/Product' incorporates:
   *  Constant: '<S9>/gravity'
   */
  rtb_Product = localP->gravity_Value * rtu_mass;

  /* UnitDelay: '<S16>/Unit Delay1' */
  memcpy(&rtb_UnitDelay1[0], &localDW->UnitDelay1_DSTATE[0], sizeof(real_T) <<
         4U);

  /* Switch: '<S24>/Init' incorporates:
   *  UnitDelay: '<S24>/FixPt Unit Delay1'
   *  UnitDelay: '<S24>/FixPt Unit Delay2'
   */
  if (localDW->FixPtUnitDelay2_DSTATE != 0) {
    rtb_Init_k[0] = rtu_x;
  } else {
    rtb_Init_k[0] = localDW->FixPtUnitDelay1_DSTATE[0];
  }

  if (localDW->FixPtUnitDelay2_DSTATE != 0) {
    rtb_Init_k[1] = rtu_x_m;
  } else {
    rtb_Init_k[1] = localDW->FixPtUnitDelay1_DSTATE[1];
  }

  if (localDW->FixPtUnitDelay2_DSTATE != 0) {
    rtb_Init_k[2] = rtu_x_p;
  } else {
    rtb_Init_k[2] = localDW->FixPtUnitDelay1_DSTATE[2];
  }

  /* End of Switch: '<S24>/Init' */

  /* MATLAB Function: '<S16>/discrete kalman filter' incorporates:
   *  Constant: '<S16>/A'
   *  Constant: '<S16>/B'
   *  Constant: '<S16>/C'
   *  Constant: '<S16>/Q'
   *  Constant: '<S16>/R'
   */
  FG_traj_fa_discretekalmanfilter(rtu_x, rtu_x_m, rtu_x_p, rtb_Init_k, rtu_14,
                                  *(real_T (*)[16])&localP->A_Value[0], *(real_T
                                   (*)[4])&localP->B_Value[0], *(real_T (*)[12])
    &localP->C_Value[0], *(real_T (*)[16])&localP->Q_Value[0], *(real_T (*)[9])&
    localP->R_Value[0], rtb_IntegerDelay, rtb_UnitDelay1,
    &localB->sf_discretekalmanfilter);

  /* UnitDelay: '<S15>/Unit Delay' */
  rtb_UnitDelay[0] = localDW->UnitDelay_DSTATE[0];
  rtb_UnitDelay[1] = localDW->UnitDelay_DSTATE[1];
  rtb_UnitDelay[2] = localDW->UnitDelay_DSTATE[2];

  /* UnitDelay: '<S15>/Unit Delay1' */
  memcpy(&rtb_UnitDelay1_k[0], &localDW->UnitDelay1_DSTATE_f[0], 30U * sizeof
         (real_T));

  /* MATLAB Function: '<S15>/runFastGradient' incorporates:
   *  Constant: '<S15>/AA_delay'
   *  Constant: '<S15>/BB_delay'
   *  Constant: '<S15>/L'
   *  Constant: '<S15>/LL_PP'
   *  Constant: '<S15>/LL_U_ref_PP'
   *  Constant: '<S15>/LL_ref_PP'
   *  Constant: '<S15>/PP'
   *  Constant: '<S15>/TT_PP'
   *  Constant: '<S15>/V_max'
   *  Constant: '<S15>/betas'
   *  Constant: '<S15>/i_min'
   */
  FG_traj_fast_runFastGradient(*(real_T (*)[900])&localP->TT_PP_Value[0],
    *(real_T (*)[90])&localP->LL_PP_Value[0], *(real_T (*)[2790])&
    localP->LL_ref_PP_Value[0], *(real_T (*)[900])&localP->LL_U_ref_PP_Value[0],
    *(real_T (*)[900])&localP->PP_Value[0], *(real_T (*)[9])&
    localP->AA_delay_Value[0], *(real_T (*)[9])&localP->BB_delay_Value[0],
    &localB->sf_discretekalmanfilter.state_est[0], *(real_T (*)[93])&
    rtu_X_ref_x[0], *(real_T (*)[30])&localP->V_max_Value[0],
    localP->i_min_Value, *(real_T (*)[7])&localP->betas_Value[0],
    localP->L_Value, rtb_UnitDelay, rtb_UnitDelay1_k,
    &localB->sf_runFastGradient);

  /* Saturate: '<S16>/Saturation' */
  if (localB->sf_discretekalmanfilter.state_est[3] >=
      localP->Saturation_UpperSat) {
    localB->Saturation = localP->Saturation_UpperSat;
  } else if (localB->sf_discretekalmanfilter.state_est[3] <=
             localP->Saturation_LowerSat) {
    localB->Saturation = localP->Saturation_LowerSat;
  } else {
    localB->Saturation = localB->sf_discretekalmanfilter.state_est[3];
  }

  /* End of Saturate: '<S16>/Saturation' */

  /* Sum: '<S9>/Sum' */
  localB->pitch_cmd = localB->sf_runFastGradient.u_opt - localB->Saturation;

  /* UnitDelay: '<S18>/Unit Delay1' */
  memcpy(&rtb_UnitDelay1_f[0], &localDW->UnitDelay1_DSTATE_m[0], sizeof(real_T) <<
         4U);

  /* Switch: '<S27>/Init' incorporates:
   *  UnitDelay: '<S27>/FixPt Unit Delay1'
   *  UnitDelay: '<S27>/FixPt Unit Delay2'
   */
  if (localDW->FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Init_i[0] = rtu_y;
  } else {
    rtb_Init_i[0] = localDW->FixPtUnitDelay1_DSTATE_g[0];
  }

  if (localDW->FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Init_i[1] = rtu_y_k;
  } else {
    rtb_Init_i[1] = localDW->FixPtUnitDelay1_DSTATE_g[1];
  }

  if (localDW->FixPtUnitDelay2_DSTATE_f != 0) {
    rtb_Init_i[2] = rtu_y_m;
  } else {
    rtb_Init_i[2] = localDW->FixPtUnitDelay1_DSTATE_g[2];
  }

  /* End of Switch: '<S27>/Init' */

  /* MATLAB Function: '<S18>/discrete kalman filter' incorporates:
   *  Constant: '<S18>/A'
   *  Constant: '<S18>/B'
   *  Constant: '<S18>/C'
   *  Constant: '<S18>/Q'
   *  Constant: '<S18>/R'
   */
  FG_traj_fa_discretekalmanfilter(rtu_y, rtu_y_k, rtu_y_m, rtb_Init_i, rtu_16,
                                  *(real_T (*)[16])&localP->A_Value_g[0],
    *(real_T (*)[4])&localP->B_Value_f[0], *(real_T (*)[12])&localP->C_Value_m[0],
    *(real_T (*)[16])&localP->Q_Value_h[0], *(real_T (*)[9])&localP->R_Value_e[0],
    rtb_IntegerDelay1, rtb_UnitDelay1_f, &localB->sf_discretekalmanfilter_n);

  /* UnitDelay: '<S17>/Unit Delay' */
  rtb_UnitDelay_d[0] = localDW->UnitDelay_DSTATE_p[0];
  rtb_UnitDelay_d[1] = localDW->UnitDelay_DSTATE_p[1];
  rtb_UnitDelay_d[2] = localDW->UnitDelay_DSTATE_p[2];

  /* UnitDelay: '<S17>/Unit Delay1' */
  memcpy(&rtb_UnitDelay1_i[0], &localDW->UnitDelay1_DSTATE_mi[0], 30U * sizeof
         (real_T));

  /* MATLAB Function: '<S17>/runFastGradient' incorporates:
   *  Constant: '<S17>/AA_delay'
   *  Constant: '<S17>/BB_delay'
   *  Constant: '<S17>/L'
   *  Constant: '<S17>/LL_PP'
   *  Constant: '<S17>/LL_U_ref_PP'
   *  Constant: '<S17>/LL_ref_PP'
   *  Constant: '<S17>/PP'
   *  Constant: '<S17>/TT_PP'
   *  Constant: '<S17>/V_max'
   *  Constant: '<S17>/betas'
   *  Constant: '<S17>/i_min'
   */
  FG_traj_fast_runFastGradient(*(real_T (*)[900])&localP->TT_PP_Value_n[0],
    *(real_T (*)[90])&localP->LL_PP_Value_h[0], *(real_T (*)[2790])&
    localP->LL_ref_PP_Value_l[0], *(real_T (*)[900])&localP->
    LL_U_ref_PP_Value_h[0], *(real_T (*)[900])&localP->PP_Value_a[0], *(real_T (*)
    [9])&localP->AA_delay_Value_j[0], *(real_T (*)[9])&localP->BB_delay_Value_c
    [0], &localB->sf_discretekalmanfilter_n.state_est[0], *(real_T (*)[93])&
    rtu_X_ref_y[0], *(real_T (*)[30])&localP->V_max_Value_g[0],
    localP->i_min_Value_l, *(real_T (*)[7])&localP->betas_Value_m[0],
    localP->L_Value_g, rtb_UnitDelay_d, rtb_UnitDelay1_i,
    &localB->sf_runFastGradient_a);

  /* Saturate: '<S18>/Saturation' */
  if (localB->sf_discretekalmanfilter_n.state_est[3] >=
      localP->Saturation_UpperSat_f) {
    localB->Saturation_l = localP->Saturation_UpperSat_f;
  } else if (localB->sf_discretekalmanfilter_n.state_est[3] <=
             localP->Saturation_LowerSat_c) {
    localB->Saturation_l = localP->Saturation_LowerSat_c;
  } else {
    localB->Saturation_l = localB->sf_discretekalmanfilter_n.state_est[3];
  }

  /* End of Saturate: '<S18>/Saturation' */

  /* Sum: '<S9>/Sum1' */
  localB->roll_cmd = localB->sf_runFastGradient_a.u_opt - localB->Saturation_l;

  /* UnitDelay: '<S22>/Unit Delay1' */
  memcpy(&rtb_UnitDelay1_l[0], &localDW->UnitDelay1_DSTATE_c[0], 9U * sizeof
         (real_T));

  /* Switch: '<S33>/Init' incorporates:
   *  UnitDelay: '<S33>/FixPt Unit Delay1'
   *  UnitDelay: '<S33>/FixPt Unit Delay2'
   */
  if (localDW->FixPtUnitDelay2_DSTATE_h != 0) {
    rtb_Init_j[0] = rtu_z;
  } else {
    rtb_Init_j[0] = localDW->FixPtUnitDelay1_DSTATE_j[0];
  }

  if (localDW->FixPtUnitDelay2_DSTATE_h != 0) {
    rtb_Init_j[1] = rtu_z_f;
  } else {
    rtb_Init_j[1] = localDW->FixPtUnitDelay1_DSTATE_j[1];
  }

  /* End of Switch: '<S33>/Init' */

  /* MATLAB Function: '<S22>/discrete kalman filter' incorporates:
   *  Constant: '<S22>/A'
   *  Constant: '<S22>/B'
   *  Constant: '<S22>/C'
   *  Constant: '<S22>/Q'
   *  Constant: '<S22>/R'
   */
  FG_traj__discretekalmanfilter_j(rtu_z, rtu_z_f, rtb_Init_j, rtu_18, *(real_T (*)
    [9])&localP->A_Value_e[0], *(real_T (*)[3])&localP->B_Value_k[0], *(real_T (*)
    [6])&localP->C_Value_p[0], *(real_T (*)[9])&localP->Q_Value_g[0], *(real_T (*)
    [4])&localP->R_Value_c[0], rtb_IntegerDelay2, rtb_UnitDelay1_l,
    &localB->sf_discretekalmanfilter_d);

  /* MATLAB Function: '<S21>/runFastGradient' incorporates:
   *  Constant: '<S21>/AA_delay'
   *  Constant: '<S21>/BB_delay'
   *  Constant: '<S21>/L'
   *  Constant: '<S21>/LL_PP'
   *  Constant: '<S21>/LL_U_ref_PP'
   *  Constant: '<S21>/LL_ref_PP'
   *  Constant: '<S21>/PP'
   *  Constant: '<S21>/TT_PP'
   *  Constant: '<S21>/V_max'
   *  Constant: '<S21>/betas'
   *  Constant: '<S21>/i_min'
   *  UnitDelay: '<S21>/Unit Delay'
   *  UnitDelay: '<S21>/Unit Delay1'
   */
  /* MATLAB Function 'z controller MPC FG/runFastGradient': '<S32>:1' */
  /*  ugly, but simulink needs fix output sizes for vectors */
  /*  number of outputs u */
  /*  number of delay steps */
  /*  prediction horizon */
  /*  predict non-delayed state */
  /* '<S32>:1:14' */
  /*  TODO get U_ref from trajectory */
  /*  set optimization variables */
  /* '<S32>:1:21' */
  unnamed_idx = (localP->AA_delay_Value_f[0] *
                 localB->sf_discretekalmanfilter_d.state_est[0] +
                 localP->AA_delay_Value_f[2] *
                 localB->sf_discretekalmanfilter_d.state_est[1]) +
    (localP->BB_delay_Value_n[0] * localDW->UnitDelay_DSTATE_d[0] +
     localP->BB_delay_Value_n[2] * localDW->UnitDelay_DSTATE_d[1]);
  unnamed_idx_0 = (localP->AA_delay_Value_f[1] *
                   localB->sf_discretekalmanfilter_d.state_est[0] +
                   localP->AA_delay_Value_f[3] *
                   localB->sf_discretekalmanfilter_d.state_est[1]) +
    (localP->BB_delay_Value_n[1] * localDW->UnitDelay_DSTATE_d[0] +
     localP->BB_delay_Value_n[3] * localDW->UnitDelay_DSTATE_d[1]);
  for (i_0 = 0; i_0 < 30; i_0++) {
    tmp[i_0] = 0.0;
    tmp[i_0] += localP->LL_PP_Value_l[i_0 << 1] * unnamed_idx;
    tmp[i_0] += localP->LL_PP_Value_l[(i_0 << 1) + 1] * unnamed_idx_0;
    V_min[i_0] = 0.0;
    for (i_1 = 0; i_1 < 62; i_1++) {
      V_min[i_0] += localP->LL_ref_PP_Value_d[62 * i_0 + i_1] * rtu_X_ref_z[i_1];
    }
  }

  for (i_0 = 0; i_0 < 30; i_0++) {
    unnamed_idx = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      unnamed_idx += localP->LL_U_ref_PP_Value_k[30 * i_0 + i_1] * 0.0;
    }

    LL_PP_ref[i_0] = (tmp[i_0] - V_min[i_0]) - unnamed_idx;
  }

  /* '<S32>:1:22' */
  /*  TODO expand to X_ref, U_ref */
  /*  run fast gradient method */
  for (i = 0; i < 30; i++) {
    V_min[i] = -localP->V_max_Value_a[i];
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
  L_inv = 1.0 / localP->L_Value_j;
  for (i_0 = 0; i_0 < 30; i_0++) {
    unnamed_idx = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      unnamed_idx += localP->TT_PP_Value_e[30 * i_1 + i_0] *
        localDW->UnitDelay1_DSTATE_j[i_1];
    }

    tmp[i_0] = unnamed_idx + LL_PP_ref[i_0];
  }

  for (i_0 = 0; i_0 < 30; i_0++) {
    U_star_0 = localDW->UnitDelay1_DSTATE_j[i_0] - L_inv * tmp[i_0];
    if ((localP->V_max_Value_a[i_0] <= U_star_0) || rtIsNaN(U_star_0)) {
      unnamed_idx = localP->V_max_Value_a[i_0];
    } else {
      unnamed_idx = U_star_0;
    }

    if ((V_min[i_0] >= unnamed_idx) || rtIsNaN(unnamed_idx)) {
      unnamed_idx = V_min[i_0];
    }

    V_ip[i_0] = unnamed_idx;
    U_star[i_0] = U_star_0;
    V_i[i_0] = unnamed_idx;
  }

  /*  now run the fast gradient method: */
  for (i = 0; i < (int32_T)localP->i_min_Value_p; i++) {
    for (i_0 = 0; i_0 < 30; i_0++) {
      unnamed_idx = 0.0;
      for (i_1 = 0; i_1 < 30; i_1++) {
        unnamed_idx += localP->TT_PP_Value_e[30 * i_1 + i_0] * V_ip[i_1];
      }

      tmp[i_0] = unnamed_idx + LL_PP_ref[i_0];
    }

    /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
    /*      convergence result idea */
    for (i_0 = 0; i_0 < 30; i_0++) {
      U_star_0 = V_ip[i_0] - L_inv * tmp[i_0];
      if ((localP->V_max_Value_a[i_0] <= U_star_0) || rtIsNaN(U_star_0)) {
        U_star_0 = localP->V_max_Value_a[i_0];
      }

      if ((V_min[i_0] >= U_star_0) || rtIsNaN(U_star_0)) {
        unnamed_idx = V_min[i_0];
      } else {
        unnamed_idx = U_star_0;
      }

      U_star_0 = localP->betas_Value_o[(int32_T)(1.0 + (real_T)i) - 1] *
        (unnamed_idx - V_i[i_0]);
      unnamed_idx_0 = unnamed_idx;
      unnamed_idx += U_star_0;
      U_star[i_0] = U_star_0;
      V_ip[i_0] = unnamed_idx;
      V_i[i_0] = unnamed_idx_0;
    }
  }

  /*  return values: */
  /*  plot(residuals) just for testing new convergence result idea */
  /* '<S32>:1:25' */
  /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
  /*  so don't forget to backtransform after termination: */
  /* '<S32>:1:32' */
  for (i_0 = 0; i_0 < 30; i_0++) {
    U_star[i_0] = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      U_star[i_0] += localP->PP_Value_m[30 * i_1 + i_0] * V_i[i_1];
    }
  }

  /*  save outputs for delayed system */
  /* '<S32>:1:38' */
  /*  set new initial guess */
  /* '<S32>:1:42' */
  /* '<S32>:1:44' */
  rtb_u_buff_out_idx = localDW->UnitDelay_DSTATE_d[1];
  rtb_u_buff_out_idx_0 = U_star[0];

  /* Saturate: '<S22>/Saturation' */
  if (localB->sf_discretekalmanfilter_d.state_est[2] >=
      localP->Saturation_UpperSat_j) {
    localB->Saturation_p = localP->Saturation_UpperSat_j;
  } else if (localB->sf_discretekalmanfilter_d.state_est[2] <=
             localP->Saturation_LowerSat_cp) {
    localB->Saturation_p = localP->Saturation_LowerSat_cp;
  } else {
    localB->Saturation_p = localB->sf_discretekalmanfilter_d.state_est[2];
  }

  /* End of Saturate: '<S22>/Saturation' */

  /* Sum: '<S9>/Sum2' incorporates:
   *  MATLAB Function: '<S21>/runFastGradient'
   */
  rtb_thrust_cmd_b = U_star[0] - localB->Saturation_p;

  /* UnitDelay: '<S20>/Unit Delay1' */
  memcpy(&rtb_UnitDelay1_kr[0], &localDW->UnitDelay1_DSTATE_h[0], 9U * sizeof
         (real_T));

  /* Switch: '<S30>/Init' incorporates:
   *  UnitDelay: '<S30>/FixPt Unit Delay1'
   *  UnitDelay: '<S30>/FixPt Unit Delay2'
   */
  if (localDW->FixPtUnitDelay2_DSTATE_g != 0) {
    rtb_Init_n[0] = rtu_yaw;
  } else {
    rtb_Init_n[0] = localDW->FixPtUnitDelay1_DSTATE_p[0];
  }

  if (localDW->FixPtUnitDelay2_DSTATE_g != 0) {
    rtb_Init_n[1] = rtu_yaw_m;
  } else {
    rtb_Init_n[1] = localDW->FixPtUnitDelay1_DSTATE_p[1];
  }

  /* End of Switch: '<S30>/Init' */

  /* MATLAB Function: '<S20>/discrete kalman filter' incorporates:
   *  Constant: '<S20>/A'
   *  Constant: '<S20>/B'
   *  Constant: '<S20>/C'
   *  Constant: '<S20>/Q'
   *  Constant: '<S20>/R'
   */
  FG_traj__discretekalmanfilter_j(rtu_yaw, rtu_yaw_m, rtb_Init_n, rtu_17,
    *(real_T (*)[9])&localP->A_Value_gk[0], *(real_T (*)[3])&localP->B_Value_ke
    [0], *(real_T (*)[6])&localP->C_Value_c[0], *(real_T (*)[9])&
    localP->Q_Value_n[0], *(real_T (*)[4])&localP->R_Value_k[0],
    rtb_IntegerDelay3, rtb_UnitDelay1_kr, &localB->sf_discretekalmanfilter_j);

  /* MATLAB Function: '<S19>/runFastGradient' incorporates:
   *  Constant: '<S19>/AA_delay'
   *  Constant: '<S19>/BB_delay'
   *  Constant: '<S19>/L'
   *  Constant: '<S19>/LL_PP'
   *  Constant: '<S19>/LL_U_ref_PP'
   *  Constant: '<S19>/LL_ref_PP'
   *  Constant: '<S19>/PP'
   *  Constant: '<S19>/TT_PP'
   *  Constant: '<S19>/V_max'
   *  Constant: '<S19>/betas'
   *  Constant: '<S19>/i_min'
   *  UnitDelay: '<S19>/Unit Delay'
   *  UnitDelay: '<S19>/Unit Delay1'
   */
  /* MATLAB Function 'yaw controller MPC FG/runFastGradient': '<S29>:1' */
  /*  ugly, but simulink needs fix output sizes for vectors */
  /*  number of outputs u */
  /*  number of delay steps */
  /*  prediction horizon */
  /*  predict non-delayed state */
  /* '<S29>:1:14' */
  /*  TODO get U_ref from trajectory */
  /*  set optimization variables */
  /* '<S29>:1:21' */
  for (i_0 = 0; i_0 < 2; i_0++) {
    tmp_0[i_0] = 0.0;
    for (i_1 = 0; i_1 < 6; i_1++) {
      tmp_0[i_0] += localP->BB_delay_Value_j[(i_1 << 1) + i_0] *
        localDW->UnitDelay_DSTATE_j[i_1];
    }
  }

  unnamed_idx = (localP->AA_delay_Value_e[0] *
                 localB->sf_discretekalmanfilter_j.state_est[0] +
                 localP->AA_delay_Value_e[2] *
                 localB->sf_discretekalmanfilter_j.state_est[1]) + tmp_0[0];
  unnamed_idx_0 = (localP->AA_delay_Value_e[1] *
                   localB->sf_discretekalmanfilter_j.state_est[0] +
                   localP->AA_delay_Value_e[3] *
                   localB->sf_discretekalmanfilter_j.state_est[1]) + tmp_0[1];
  for (i_0 = 0; i_0 < 30; i_0++) {
    tmp[i_0] = 0.0;
    tmp[i_0] += localP->LL_PP_Value_o[i_0 << 1] * unnamed_idx;
    tmp[i_0] += localP->LL_PP_Value_o[(i_0 << 1) + 1] * unnamed_idx_0;
    V_min[i_0] = 0.0;
    for (i_1 = 0; i_1 < 62; i_1++) {
      V_min[i_0] += localP->LL_ref_PP_Value_b[62 * i_0 + i_1] *
        rtu_X_ref_yaw[i_1];
    }
  }

  for (i_0 = 0; i_0 < 30; i_0++) {
    unnamed_idx = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      unnamed_idx += localP->LL_U_ref_PP_Value_g[30 * i_0 + i_1] * 0.0;
    }

    LL_PP_ref[i_0] = (tmp[i_0] - V_min[i_0]) - unnamed_idx;
  }

  /* '<S29>:1:22' */
  /*  TODO expand to X_ref, U_ref */
  /*  run fast gradient method */
  for (i = 0; i < 30; i++) {
    V_min[i] = -localP->V_max_Value_h[i];
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
  L_inv = 1.0 / localP->L_Value_jd;
  for (i_0 = 0; i_0 < 30; i_0++) {
    unnamed_idx = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      unnamed_idx += localP->TT_PP_Value_ew[30 * i_1 + i_0] *
        localDW->UnitDelay1_DSTATE_p[i_1];
    }

    tmp[i_0] = unnamed_idx + LL_PP_ref[i_0];
  }

  for (i_0 = 0; i_0 < 30; i_0++) {
    U_star_0 = localDW->UnitDelay1_DSTATE_p[i_0] - L_inv * tmp[i_0];
    if ((localP->V_max_Value_h[i_0] <= U_star_0) || rtIsNaN(U_star_0)) {
      unnamed_idx = localP->V_max_Value_h[i_0];
    } else {
      unnamed_idx = U_star_0;
    }

    if ((V_min[i_0] >= unnamed_idx) || rtIsNaN(unnamed_idx)) {
      unnamed_idx = V_min[i_0];
    }

    V_ip[i_0] = unnamed_idx;
    U_star[i_0] = U_star_0;
    V_i_0[i_0] = unnamed_idx;
  }

  /*  now run the fast gradient method: */
  for (i = 0; i < (int32_T)localP->i_min_Value_a; i++) {
    for (i_0 = 0; i_0 < 30; i_0++) {
      unnamed_idx = 0.0;
      for (i_1 = 0; i_1 < 30; i_1++) {
        unnamed_idx += localP->TT_PP_Value_ew[30 * i_1 + i_0] * V_ip[i_1];
      }

      tmp[i_0] = unnamed_idx + LL_PP_ref[i_0];
    }

    /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
    /*      convergence result idea */
    for (i_0 = 0; i_0 < 30; i_0++) {
      U_star_0 = V_ip[i_0] - L_inv * tmp[i_0];
      if ((localP->V_max_Value_h[i_0] <= U_star_0) || rtIsNaN(U_star_0)) {
        U_star_0 = localP->V_max_Value_h[i_0];
      }

      if ((V_min[i_0] >= U_star_0) || rtIsNaN(U_star_0)) {
        unnamed_idx = V_min[i_0];
      } else {
        unnamed_idx = U_star_0;
      }

      U_star_0 = localP->betas_Value_o5[(int32_T)(1.0 + (real_T)i) - 1] *
        (unnamed_idx - V_i_0[i_0]);
      unnamed_idx_0 = unnamed_idx;
      unnamed_idx += U_star_0;
      U_star[i_0] = U_star_0;
      V_ip[i_0] = unnamed_idx;
      V_i_0[i_0] = unnamed_idx_0;
    }
  }

  /*  return values: */
  /*  plot(residuals) just for testing new convergence result idea */
  /* '<S29>:1:25' */
  /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
  /*  so don't forget to backtransform after termination: */
  /* '<S29>:1:32' */
  for (i_0 = 0; i_0 < 30; i_0++) {
    U_star[i_0] = 0.0;
    for (i_1 = 0; i_1 < 30; i_1++) {
      U_star[i_0] += localP->PP_Value_i[30 * i_1 + i_0] * V_i_0[i_1];
    }
  }

  /* Saturate: '<S20>/Saturation' */
  /*  save outputs for delayed system */
  /* '<S29>:1:38' */
  /*  set new initial guess */
  /* '<S29>:1:42' */
  /* '<S29>:1:44' */
  if (localB->sf_discretekalmanfilter_j.state_est[2] >=
      localP->Saturation_UpperSat_o) {
    localB->Saturation_c = localP->Saturation_UpperSat_o;
  } else if (localB->sf_discretekalmanfilter_j.state_est[2] <=
             localP->Saturation_LowerSat_k) {
    localB->Saturation_c = localP->Saturation_LowerSat_k;
  } else {
    localB->Saturation_c = localB->sf_discretekalmanfilter_j.state_est[2];
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* Sum: '<S9>/Sum3' incorporates:
   *  MATLAB Function: '<S19>/runFastGradient'
   */
  localB->yaw_rate_cmd = U_star[0] - localB->Saturation_c;

  /* Sum: '<S9>/Sum5' */
  localB->thrust_cmd = rtb_thrust_cmd_b + rtb_Product;

  /* Update for Delay: '<S9>/Integer Delay' */
  localDW->IntegerDelay_DSTATE = localB->pitch_cmd;

  /* Update for Delay: '<S9>/Integer Delay1' */
  localDW->IntegerDelay1_DSTATE = localB->roll_cmd;

  /* Update for Delay: '<S9>/Integer Delay2' */
  localDW->IntegerDelay2_DSTATE = rtb_thrust_cmd_b;

  /* Update for Delay: '<S9>/Integer Delay3' */
  localDW->IntegerDelay3_DSTATE = localB->yaw_rate_cmd;

  /* Update for UnitDelay: '<S16>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE[0], &localB->sf_discretekalmanfilter.P_est
         [0], sizeof(real_T) << 4U);

  /* Update for UnitDelay: '<S24>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S24>/FixPt Constant'
   */
  localDW->FixPtUnitDelay2_DSTATE = localP->FixPtConstant_Value;

  /* Update for UnitDelay: '<S24>/FixPt Unit Delay1' */
  localDW->FixPtUnitDelay1_DSTATE[0] = localB->
    sf_discretekalmanfilter.state_est[0];
  localDW->FixPtUnitDelay1_DSTATE[1] = localB->
    sf_discretekalmanfilter.state_est[1];
  localDW->FixPtUnitDelay1_DSTATE[2] = localB->
    sf_discretekalmanfilter.state_est[2];

  /* Update for UnitDelay: '<S15>/Unit Delay' */
  localDW->UnitDelay_DSTATE[0] = localB->sf_runFastGradient.u_buff_out[0];
  localDW->UnitDelay_DSTATE[1] = localB->sf_runFastGradient.u_buff_out[1];
  localDW->UnitDelay_DSTATE[2] = localB->sf_runFastGradient.u_buff_out[2];

  /* Update for UnitDelay: '<S15>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE_f[0],
         &localB->sf_runFastGradient.V_init_out[0], 30U * sizeof(real_T));

  /* Update for UnitDelay: '<S18>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE_m[0],
         &localB->sf_discretekalmanfilter_n.P_est[0], sizeof(real_T) << 4U);

  /* Update for UnitDelay: '<S27>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S27>/FixPt Constant'
   */
  localDW->FixPtUnitDelay2_DSTATE_f = localP->FixPtConstant_Value_p;

  /* Update for UnitDelay: '<S27>/FixPt Unit Delay1' */
  localDW->FixPtUnitDelay1_DSTATE_g[0] =
    localB->sf_discretekalmanfilter_n.state_est[0];
  localDW->FixPtUnitDelay1_DSTATE_g[1] =
    localB->sf_discretekalmanfilter_n.state_est[1];
  localDW->FixPtUnitDelay1_DSTATE_g[2] =
    localB->sf_discretekalmanfilter_n.state_est[2];

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  localDW->UnitDelay_DSTATE_p[0] = localB->sf_runFastGradient_a.u_buff_out[0];
  localDW->UnitDelay_DSTATE_p[1] = localB->sf_runFastGradient_a.u_buff_out[1];
  localDW->UnitDelay_DSTATE_p[2] = localB->sf_runFastGradient_a.u_buff_out[2];

  /* Update for UnitDelay: '<S17>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE_mi[0],
         &localB->sf_runFastGradient_a.V_init_out[0], 30U * sizeof(real_T));

  /* Update for UnitDelay: '<S22>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE_c[0],
         &localB->sf_discretekalmanfilter_d.P_est[0], 9U * sizeof(real_T));

  /* Update for UnitDelay: '<S33>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S33>/FixPt Constant'
   */
  localDW->FixPtUnitDelay2_DSTATE_h = localP->FixPtConstant_Value_j;

  /* Update for UnitDelay: '<S33>/FixPt Unit Delay1' */
  localDW->FixPtUnitDelay1_DSTATE_j[0] =
    localB->sf_discretekalmanfilter_d.state_est[0];
  localDW->FixPtUnitDelay1_DSTATE_j[1] =
    localB->sf_discretekalmanfilter_d.state_est[1];

  /* Update for UnitDelay: '<S21>/Unit Delay' */
  localDW->UnitDelay_DSTATE_d[0] = rtb_u_buff_out_idx;
  localDW->UnitDelay_DSTATE_d[1] = rtb_u_buff_out_idx_0;

  /* Update for UnitDelay: '<S21>/Unit Delay1' incorporates:
   *  MATLAB Function: '<S21>/runFastGradient'
   */
  memcpy(&localDW->UnitDelay1_DSTATE_j[0], &V_i[1], 29U * sizeof(real_T));
  localDW->UnitDelay1_DSTATE_j[29] = 0.0;

  /* Update for UnitDelay: '<S20>/Unit Delay1' */
  memcpy(&localDW->UnitDelay1_DSTATE_h[0],
         &localB->sf_discretekalmanfilter_j.P_est[0], 9U * sizeof(real_T));

  /* Update for UnitDelay: '<S30>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S30>/FixPt Constant'
   */
  localDW->FixPtUnitDelay2_DSTATE_g = localP->FixPtConstant_Value_p5;

  /* Update for UnitDelay: '<S30>/FixPt Unit Delay1' */
  localDW->FixPtUnitDelay1_DSTATE_p[0] =
    localB->sf_discretekalmanfilter_j.state_est[0];
  localDW->FixPtUnitDelay1_DSTATE_p[1] =
    localB->sf_discretekalmanfilter_j.state_est[1];

  /* MATLAB Function: '<S19>/runFastGradient' incorporates:
   *  UnitDelay: '<S19>/Unit Delay'
   *  Update for UnitDelay: '<S19>/Unit Delay'
   */
  for (i_0 = 0; i_0 < 5; i_0++) {
    tmp_1[i_0] = localDW->UnitDelay_DSTATE_j[1 + i_0];
  }

  tmp_1[5] = U_star[0];

  /* Update for UnitDelay: '<S19>/Unit Delay' */
  for (i_0 = 0; i_0 < 6; i_0++) {
    localDW->UnitDelay_DSTATE_j[i_0] = tmp_1[i_0];
  }

  /* Update for UnitDelay: '<S19>/Unit Delay1' incorporates:
   *  MATLAB Function: '<S19>/runFastGradient'
   */
  memcpy(&localDW->UnitDelay1_DSTATE_p[0], &V_i_0[1], 29U * sizeof(real_T));
  localDW->UnitDelay1_DSTATE_p[29] = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S12>/Embedded MATLAB Function'
 *    '<S43>/Embedded MATLAB Function'
 */
void FG_traj__EmbeddedMATLABFunction(real_T rtu_roll, real_T rtu_pitch, real_T
  rtu_pitch_bias, real_T rtu_roll_bias, real_T rtu_yaw,
  rtB_EmbeddedMATLABFunction_FG_t *localB)
{
  real_T sin_yaw;
  real_T cos_yaw;

  /* MATLAB Function 'rotate to world frame/Embedded MATLAB Function': '<S39>:1' */
  /* '<S39>:1:5' */
  sin_yaw = sin(rtu_yaw);

  /* '<S39>:1:6' */
  cos_yaw = cos(rtu_yaw);

  /* '<S39>:1:8' */
  /* '<S39>:1:10' */
  /* '<S39>:1:11' */
  localB->pitch_rot = cos_yaw * rtu_pitch + sin_yaw * rtu_roll;

  /* '<S39>:1:12' */
  localB->roll_rot = -sin_yaw * rtu_pitch + cos_yaw * rtu_roll;

  /* '<S39>:1:14' */
  /* '<S39>:1:15' */
  localB->pitch_bias_rot = cos_yaw * rtu_pitch_bias + sin_yaw * rtu_roll_bias;

  /* '<S39>:1:16' */
  localB->roll_bias_rot = -sin_yaw * rtu_pitch_bias + cos_yaw * rtu_roll_bias;
}

/* Model step function */
void FG_traj_custom(real32_T arg_data_in[30], real32_T arg_cmd_out[4], real32_T
                    arg_ref_x[93], real32_T arg_ref_y[93], real32_T arg_ref_z[62],
                    real32_T arg_ref_yaw[62])
{
  /* local block i/o variables */
  real_T rtb_Init[4];
  real_T rtb_TmpSignalConversionAtToFile[4];
  real_T rtb_TmpSignalConversionAtToFi_i[4];
  real_T rtb_TmpSignalConversionAtToFi_b[18];
  real_T rtb_TmpSignalConversionAtToFi_j[18];
  real_T sin_yaw;
  real_T cos_yaw;
  real_T rtb_MultiportSwitch1;
  real_T rtb_MultiportSwitch2;
  real_T rtb_Gain3;
  int32_T i;
  real_T unnamed_idx;

  /* RTWBLOCK_START_COMMENT */
  /* Reset subsysRan breadcrumbs */
  srClearBC(FG_traj_fast_DWork.poscontroller_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(FG_traj_fast_DWork.poscontroller1_SubsysRanBC);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/data_in'
   */
  /* RTWBLOCK_START_COMMENT */
  for (i = 0; i < 30; i++) {
    FG_traj_fast_B.DataTypeConversion[i] = arg_data_in[i];
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* MultiPortSwitch: '<S3>/Multiport Switch1' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   */
  if ((int32_T)FG_traj_fast_B.DataTypeConversion[20] == 10) {
    rtb_MultiportSwitch1 = FG_traj_fast_P.Constant1_Value;
  } else {
    rtb_MultiportSwitch1 = FG_traj_fast_P.Constant2_Value;
  }

  /* End of MultiPortSwitch: '<S3>/Multiport Switch1' */

  /* Switch: '<S8>/Init' incorporates:
   *  Constant: '<S8>/Initial Condition'
   *  Logic: '<S8>/FixPt Logical Operator'
   *  UnitDelay: '<S8>/FixPt Unit Delay1'
   *  UnitDelay: '<S8>/FixPt Unit Delay2'
   */
  if ((rtb_MultiportSwitch1 != 0.0) ||
      (FG_traj_fast_DWork.FixPtUnitDelay2_DSTATE != 0)) {
    rtb_Init[0] = FG_traj_fast_P.InitialCondition_Value;
    rtb_Init[1] = FG_traj_fast_P.InitialCondition_Value;
    rtb_Init[2] = FG_traj_fast_P.InitialCondition_Value;
    rtb_Init[3] = FG_traj_fast_P.InitialCondition_Value;
  } else {
    rtb_Init[0] = FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[0];
    rtb_Init[1] = FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[1];
    rtb_Init[2] = FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[2];
    rtb_Init[3] = FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[3];
  }

  for (i = 0; i < 93; i++) {
    /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
     *  Inport: '<Root>/ref_x'
     */
    FG_traj_fast_B.X_ref_x[i] = arg_ref_x[i];

    /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
     *  Inport: '<Root>/ref_y'
     */
    FG_traj_fast_B.X_ref_y[i] = arg_ref_y[i];
  }

  /* End of Switch: '<S8>/Init' */
  for (i = 0; i < 62; i++) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
     *  Inport: '<Root>/ref_z'
     */
    FG_traj_fast_B.X_ref_z[i] = arg_ref_z[i];

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Inport: '<Root>/ref_yaw'
     */
    FG_traj_fast_B.X_ref_yaw[i] = arg_ref_yaw[i];
  }

  /* MultiPortSwitch: '<S3>/Multiport Switch2' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   */
  if ((int32_T)FG_traj_fast_B.DataTypeConversion[20] == 4) {
    rtb_MultiportSwitch2 = FG_traj_fast_P.Constant1_Value;
  } else {
    rtb_MultiportSwitch2 = FG_traj_fast_P.Constant2_Value;
  }

  /* End of MultiPortSwitch: '<S3>/Multiport Switch2' */

  /* Outputs for Enabled SubSystem: '<Root>/pos controller1' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (rtb_MultiportSwitch2 > 0.0) {
    if (!FG_traj_fast_DWork.poscontroller1_MODE) {
      /* InitializeConditions for Atomic SubSystem: '<S7>/MAIN CONTROL LOOP1' */
      FG_traj_f_MAINCONTROLLOOP1_Init(&FG_traj_fast_DWork.MAINCONTROLLOOP1_c,
        (rtP_MAINCONTROLLOOP1_FG_traj_fa *)&FG_traj_fast_P.MAINCONTROLLOOP1_c);

      /* End of InitializeConditions for SubSystem: '<S7>/MAIN CONTROL LOOP1' */
      FG_traj_fast_DWork.poscontroller1_MODE = TRUE;
    }

    /* MATLAB Function: '<S43>/Embedded MATLAB Function' */
    FG_traj__EmbeddedMATLABFunction(FG_traj_fast_B.DataTypeConversion[6],
      FG_traj_fast_B.DataTypeConversion[7], rtb_Init[0], rtb_Init[1],
      FG_traj_fast_B.DataTypeConversion[8],
      &FG_traj_fast_B.sf_EmbeddedMATLABFunction_j);

    /* Outputs for Atomic SubSystem: '<S7>/MAIN CONTROL LOOP1' */
    FG_traj_fast_MAINCONTROLLOOP1(FG_traj_fast_B.DataTypeConversion[29],
      FG_traj_fast_B.DataTypeConversion[0], FG_traj_fast_B.DataTypeConversion[3],
      FG_traj_fast_B.sf_EmbeddedMATLABFunction_j.pitch_rot,
      FG_traj_fast_B.DataTypeConversion[1], FG_traj_fast_B.DataTypeConversion[4],
      FG_traj_fast_B.sf_EmbeddedMATLABFunction_j.roll_rot,
      FG_traj_fast_B.DataTypeConversion[2], FG_traj_fast_B.DataTypeConversion[5],
      FG_traj_fast_B.DataTypeConversion[8], FG_traj_fast_B.DataTypeConversion[11],
      FG_traj_fast_B.X_ref_yaw, FG_traj_fast_B.X_ref_z, FG_traj_fast_B.X_ref_x,
      FG_traj_fast_B.sf_EmbeddedMATLABFunction_j.pitch_bias_rot,
      FG_traj_fast_B.X_ref_y,
      FG_traj_fast_B.sf_EmbeddedMATLABFunction_j.roll_bias_rot, rtb_Init[3],
      rtb_Init[2], &FG_traj_fast_B.MAINCONTROLLOOP1_c,
      &FG_traj_fast_DWork.MAINCONTROLLOOP1_c, (rtP_MAINCONTROLLOOP1_FG_traj_fa *)
      &FG_traj_fast_P.MAINCONTROLLOOP1_c);

    /* End of Outputs for SubSystem: '<S7>/MAIN CONTROL LOOP1' */

    /* SignalConversion: '<S44>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFi_b[0] = FG_traj_fast_B.DataTypeConversion[0];
    rtb_TmpSignalConversionAtToFi_b[1] = FG_traj_fast_B.DataTypeConversion[3];
    rtb_TmpSignalConversionAtToFi_b[2] = FG_traj_fast_B.DataTypeConversion[7];
    rtb_TmpSignalConversionAtToFi_b[3] = FG_traj_fast_B.X_ref_x[0];
    rtb_TmpSignalConversionAtToFi_b[4] =
      FG_traj_fast_B.MAINCONTROLLOOP1_c.pitch_cmd;
    rtb_TmpSignalConversionAtToFi_b[5] = FG_traj_fast_B.DataTypeConversion[1];
    rtb_TmpSignalConversionAtToFi_b[6] = FG_traj_fast_B.DataTypeConversion[4];
    rtb_TmpSignalConversionAtToFi_b[7] = FG_traj_fast_B.DataTypeConversion[6];
    rtb_TmpSignalConversionAtToFi_b[8] = FG_traj_fast_B.X_ref_y[0];
    rtb_TmpSignalConversionAtToFi_b[9] =
      FG_traj_fast_B.MAINCONTROLLOOP1_c.roll_cmd;
    rtb_TmpSignalConversionAtToFi_b[10] = FG_traj_fast_B.DataTypeConversion[2];
    rtb_TmpSignalConversionAtToFi_b[11] = FG_traj_fast_B.DataTypeConversion[5];
    rtb_TmpSignalConversionAtToFi_b[12] = FG_traj_fast_B.X_ref_z[0];
    rtb_TmpSignalConversionAtToFi_b[13] =
      FG_traj_fast_B.MAINCONTROLLOOP1_c.thrust_cmd;
    rtb_TmpSignalConversionAtToFi_b[14] = FG_traj_fast_B.DataTypeConversion[8];
    rtb_TmpSignalConversionAtToFi_b[15] = FG_traj_fast_B.DataTypeConversion[11];
    rtb_TmpSignalConversionAtToFi_b[16] = FG_traj_fast_B.X_ref_yaw[0];
    rtb_TmpSignalConversionAtToFi_b[17] =
      FG_traj_fast_B.MAINCONTROLLOOP1_c.yaw_rate_cmd;

    /* ToFile: '<S44>/To File' */
    {
      if (!(++FG_traj_fast_DWork.ToFile_IWORK.Decimation % 1) &&
          (FG_traj_fast_DWork.ToFile_IWORK.Count*19)+1 < 100000000 ) {
        FILE *fp = (FILE *) FG_traj_fast_DWork.ToFile_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[19];
          FG_traj_fast_DWork.ToFile_IWORK.Decimation = 0;
          u[0] = FG_traj_fast_M->Timing.taskTime0;
          u[1] = rtb_TmpSignalConversionAtToFi_b[0];
          u[2] = rtb_TmpSignalConversionAtToFi_b[1];
          u[3] = rtb_TmpSignalConversionAtToFi_b[2];
          u[4] = rtb_TmpSignalConversionAtToFi_b[3];
          u[5] = rtb_TmpSignalConversionAtToFi_b[4];
          u[6] = rtb_TmpSignalConversionAtToFi_b[5];
          u[7] = rtb_TmpSignalConversionAtToFi_b[6];
          u[8] = rtb_TmpSignalConversionAtToFi_b[7];
          u[9] = rtb_TmpSignalConversionAtToFi_b[8];
          u[10] = rtb_TmpSignalConversionAtToFi_b[9];
          u[11] = rtb_TmpSignalConversionAtToFi_b[10];
          u[12] = rtb_TmpSignalConversionAtToFi_b[11];
          u[13] = rtb_TmpSignalConversionAtToFi_b[12];
          u[14] = rtb_TmpSignalConversionAtToFi_b[13];
          u[15] = rtb_TmpSignalConversionAtToFi_b[14];
          u[16] = rtb_TmpSignalConversionAtToFi_b[15];
          u[17] = rtb_TmpSignalConversionAtToFi_b[16];
          u[18] = rtb_TmpSignalConversionAtToFi_b[17];
          if (fwrite(u, sizeof(real_T), 19, fp) != 19) {
            rtmSetErrorStatus(FG_traj_fast_M,
                              "Error writing to MAT-file hquad_traj_FG.mat");
            return;
          }

          if (((++FG_traj_fast_DWork.ToFile_IWORK.Count)*19)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file hquad_traj_FG.mat.\n");
          }
        }
      }
    }

    /* SignalConversion: '<S44>/TmpSignal ConversionAtTo File1Inport1' */
    rtb_TmpSignalConversionAtToFile[0] =
      FG_traj_fast_B.MAINCONTROLLOOP1_c.Saturation;
    rtb_TmpSignalConversionAtToFile[1] =
      FG_traj_fast_B.MAINCONTROLLOOP1_c.Saturation_l;
    rtb_TmpSignalConversionAtToFile[2] =
      FG_traj_fast_B.MAINCONTROLLOOP1_c.Saturation_p;
    rtb_TmpSignalConversionAtToFile[3] =
      FG_traj_fast_B.MAINCONTROLLOOP1_c.Saturation_c;

    /* ToFile: '<S44>/To File1' */
    {
      if (!(++FG_traj_fast_DWork.ToFile1_IWORK.Decimation % 1) &&
          (FG_traj_fast_DWork.ToFile1_IWORK.Count*5)+1 < 100000000 ) {
        FILE *fp = (FILE *) FG_traj_fast_DWork.ToFile1_PWORK.FilePtr;
        if (fp != (NULL)) {
          real_T u[5];
          FG_traj_fast_DWork.ToFile1_IWORK.Decimation = 0;
          u[0] = FG_traj_fast_M->Timing.taskTime0;
          u[1] = rtb_TmpSignalConversionAtToFile[0];
          u[2] = rtb_TmpSignalConversionAtToFile[1];
          u[3] = rtb_TmpSignalConversionAtToFile[2];
          u[4] = rtb_TmpSignalConversionAtToFile[3];
          if (fwrite(u, sizeof(real_T), 5, fp) != 5) {
            rtmSetErrorStatus(FG_traj_fast_M,
                              "Error writing to MAT-file hquad_traj_FG_bias.mat");
            return;
          }

          if (((++FG_traj_fast_DWork.ToFile1_IWORK.Count)*5)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file hquad_traj_FG_bias.mat.\n");
          }
        }
      }
    }

    /* Gain: '<S44>/rad -> deg2' */
    FG_traj_fast_B.raddeg2[0] = FG_traj_fast_P.raddeg2_Gain_p *
      FG_traj_fast_B.DataTypeConversion[7];
    FG_traj_fast_B.raddeg2[1] = FG_traj_fast_P.raddeg2_Gain_p *
      FG_traj_fast_B.DataTypeConversion[10];
    FG_traj_fast_B.raddeg2[2] = FG_traj_fast_P.raddeg2_Gain_p *
      FG_traj_fast_B.MAINCONTROLLOOP1_c.pitch_cmd;

    /* Gain: '<S44>/rad -> deg1' */
    FG_traj_fast_B.raddeg1[0] = FG_traj_fast_P.raddeg1_Gain_a *
      FG_traj_fast_B.DataTypeConversion[6];
    FG_traj_fast_B.raddeg1[1] = FG_traj_fast_P.raddeg1_Gain_a *
      FG_traj_fast_B.DataTypeConversion[9];
    FG_traj_fast_B.raddeg1[2] = FG_traj_fast_P.raddeg1_Gain_a *
      FG_traj_fast_B.MAINCONTROLLOOP1_c.roll_cmd;

    /* Gain: '<S44>/rad -> deg3' */
    FG_traj_fast_B.raddeg3[0] = FG_traj_fast_P.raddeg3_Gain_m *
      FG_traj_fast_B.DataTypeConversion[8];
    FG_traj_fast_B.raddeg3[1] = FG_traj_fast_P.raddeg3_Gain_m *
      FG_traj_fast_B.DataTypeConversion[11];
    FG_traj_fast_B.raddeg3[2] = FG_traj_fast_P.raddeg3_Gain_m *
      FG_traj_fast_B.MAINCONTROLLOOP1_c.yaw_rate_cmd;

    /* Gain: '<S44>/rad -> deg' */
    FG_traj_fast_B.raddeg[0] = FG_traj_fast_P.raddeg_Gain_b *
      FG_traj_fast_B.DataTypeConversion[8];
    FG_traj_fast_B.raddeg[1] = FG_traj_fast_P.raddeg_Gain_b *
      FG_traj_fast_B.DataTypeConversion[11];
    FG_traj_fast_B.raddeg[2] = FG_traj_fast_P.raddeg_Gain_b *
      FG_traj_fast_B.X_ref_yaw[0];
    FG_traj_fast_B.raddeg[3] = FG_traj_fast_P.raddeg_Gain_b *
      FG_traj_fast_B.X_ref_yaw[1];

    /* Outputs for Atomic SubSystem: '<S7>/decoupling and rotation' */
    /* Inport: '<S41>/bias_W' */
    FG_traj_fast_B.bias_W[0] = rtb_TmpSignalConversionAtToFile[0];
    FG_traj_fast_B.bias_W[1] = rtb_TmpSignalConversionAtToFile[1];
    FG_traj_fast_B.bias_W[2] = rtb_TmpSignalConversionAtToFile[2];
    FG_traj_fast_B.bias_W[3] = rtb_TmpSignalConversionAtToFile[3];

    /* Inport: '<S41>/cmd_W' */
    FG_traj_fast_B.cmd_W[0] = FG_traj_fast_B.MAINCONTROLLOOP1_c.pitch_cmd;
    FG_traj_fast_B.cmd_W[1] = FG_traj_fast_B.MAINCONTROLLOOP1_c.roll_cmd;
    FG_traj_fast_B.cmd_W[2] = FG_traj_fast_B.MAINCONTROLLOOP1_c.thrust_cmd;
    FG_traj_fast_B.cmd_W[3] = FG_traj_fast_B.MAINCONTROLLOOP1_c.yaw_rate_cmd;

    /* MATLAB Function: '<S66>/Embedded MATLAB Function' */
    /* MATLAB Function 'decoupling and rotation/decoupling /Embedded MATLAB Function': '<S68>:1' */
    /* '<S68>:1:4' */
    rtb_Gain3 = FG_traj_fast_B.cmd_W[2] / (cos
      (FG_traj_fast_B.sf_EmbeddedMATLABFunction_j.pitch_rot) * cos
      (FG_traj_fast_B.sf_EmbeddedMATLABFunction_j.roll_rot));

    /* '<S68>:1:6' */
    /* '<S68>:1:7' */
    /*  pitch_cmd_comp=pitch_cmd; */
    /*  roll_cmd_comp=roll_cmd; */
    /*  pitch_cmd_comp = atan(Fx/(-thrust_comp)); */
    /*  roll_cmd_comp = atan(Fy/(thrust_comp)); */
    /*  pitch_cmd_comp = atan(-g*m*pitch_cmd/(-thrust)); */
    /*  roll_cmd_comp = atan(g*m*roll_cmd*cos(pitch_meas)/(thrust)); */
    FG_traj_fast_B.thrust_comp = rtb_Gain3;

    /* MATLAB Function: '<S67>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S66>/g'
     *  MATLAB Function: '<S66>/Embedded MATLAB Function'
     */
    /* MATLAB Function 'decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S69>:1' */
    /* '<S69>:1:3' */
    sin_yaw = sin(FG_traj_fast_B.DataTypeConversion[8]);

    /* '<S69>:1:4' */
    cos_yaw = cos(FG_traj_fast_B.DataTypeConversion[8]);

    /* '<S69>:1:6' */
    /* '<S69>:1:8' */
    unnamed_idx = FG_traj_fast_B.DataTypeConversion[29] *
      FG_traj_fast_P.g_Value_c / rtb_Gain3 * FG_traj_fast_B.cmd_W[0];
    rtb_Gain3 = FG_traj_fast_B.DataTypeConversion[29] * FG_traj_fast_P.g_Value_c
      / rtb_Gain3 * FG_traj_fast_B.cmd_W[1];

    /* '<S69>:1:9' */
    FG_traj_fast_B.pitch_rot = cos_yaw * unnamed_idx + -sin_yaw * rtb_Gain3;

    /* '<S69>:1:10' */
    FG_traj_fast_B.roll_rot = sin_yaw * unnamed_idx + cos_yaw * rtb_Gain3;

    /* '<S69>:1:12' */
    /* '<S69>:1:13' */
    FG_traj_fast_B.pitch_bias_rot = cos_yaw * FG_traj_fast_B.bias_W[0] +
      -sin_yaw * FG_traj_fast_B.bias_W[1];

    /* '<S69>:1:14' */
    FG_traj_fast_B.roll_bias_rot = sin_yaw * FG_traj_fast_B.bias_W[0] + cos_yaw *
      FG_traj_fast_B.bias_W[1];

    /* End of Outputs for SubSystem: '<S7>/decoupling and rotation' */
    srUpdateBC(FG_traj_fast_DWork.poscontroller1_SubsysRanBC);
  } else {
    if (FG_traj_fast_DWork.poscontroller1_MODE) {
      FG_traj_fast_DWork.poscontroller1_MODE = FALSE;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/pos controller1' */

  /* MultiPortSwitch: '<S3>/Multiport Switch' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant2'
   */
  switch ((int32_T)FG_traj_fast_B.DataTypeConversion[20]) {
   case 1:
   case 2:
   case 3:
    FG_traj_fast_B.MultiportSwitch = FG_traj_fast_P.Constant1_Value;
    break;

   default:
    FG_traj_fast_B.MultiportSwitch = FG_traj_fast_P.Constant2_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S3>/Multiport Switch' */

  /* Outputs for Enabled SubSystem: '<Root>/pos controller' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  if (FG_traj_fast_B.MultiportSwitch > 0.0) {
    if (!FG_traj_fast_DWork.poscontroller_MODE) {
      /* InitializeConditions for Atomic SubSystem: '<S6>/MAIN CONTROL LOOP1' */
      FG_traj_f_MAINCONTROLLOOP1_Init(&FG_traj_fast_DWork.MAINCONTROLLOOP1,
        (rtP_MAINCONTROLLOOP1_FG_traj_fa *)&FG_traj_fast_P.MAINCONTROLLOOP1);

      /* End of InitializeConditions for SubSystem: '<S6>/MAIN CONTROL LOOP1' */
      FG_traj_fast_DWork.poscontroller_MODE = TRUE;
    }

    /* MATLAB Function: '<S12>/Embedded MATLAB Function' */
    FG_traj__EmbeddedMATLABFunction(FG_traj_fast_B.DataTypeConversion[6],
      FG_traj_fast_B.DataTypeConversion[7], rtb_Init[0], rtb_Init[1],
      FG_traj_fast_B.DataTypeConversion[8],
      &FG_traj_fast_B.sf_EmbeddedMATLABFunction);

    /* Outputs for Atomic SubSystem: '<S6>/MAIN CONTROL LOOP1' */
    FG_traj_fast_MAINCONTROLLOOP1(FG_traj_fast_B.DataTypeConversion[29],
      FG_traj_fast_B.DataTypeConversion[0], FG_traj_fast_B.DataTypeConversion[3],
      FG_traj_fast_B.sf_EmbeddedMATLABFunction.pitch_rot,
      FG_traj_fast_B.DataTypeConversion[1], FG_traj_fast_B.DataTypeConversion[4],
      FG_traj_fast_B.sf_EmbeddedMATLABFunction.roll_rot,
      FG_traj_fast_B.DataTypeConversion[2], FG_traj_fast_B.DataTypeConversion[5],
      FG_traj_fast_B.DataTypeConversion[8], FG_traj_fast_B.DataTypeConversion[11],
      FG_traj_fast_B.X_ref_yaw, FG_traj_fast_B.X_ref_z, FG_traj_fast_B.X_ref_x,
      FG_traj_fast_B.sf_EmbeddedMATLABFunction.pitch_bias_rot,
      FG_traj_fast_B.X_ref_y,
      FG_traj_fast_B.sf_EmbeddedMATLABFunction.roll_bias_rot, rtb_Init[3],
      rtb_Init[2], &FG_traj_fast_B.MAINCONTROLLOOP1,
      &FG_traj_fast_DWork.MAINCONTROLLOOP1, (rtP_MAINCONTROLLOOP1_FG_traj_fa *)
      &FG_traj_fast_P.MAINCONTROLLOOP1);

    /* End of Outputs for SubSystem: '<S6>/MAIN CONTROL LOOP1' */

    /* SignalConversion: '<S13>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFi_j[0] = FG_traj_fast_B.DataTypeConversion[0];
    rtb_TmpSignalConversionAtToFi_j[1] = FG_traj_fast_B.DataTypeConversion[3];
    rtb_TmpSignalConversionAtToFi_j[2] = FG_traj_fast_B.DataTypeConversion[7];
    rtb_TmpSignalConversionAtToFi_j[3] = FG_traj_fast_B.X_ref_x[0];
    rtb_TmpSignalConversionAtToFi_j[4] =
      FG_traj_fast_B.MAINCONTROLLOOP1.pitch_cmd;
    rtb_TmpSignalConversionAtToFi_j[5] = FG_traj_fast_B.DataTypeConversion[1];
    rtb_TmpSignalConversionAtToFi_j[6] = FG_traj_fast_B.DataTypeConversion[4];
    rtb_TmpSignalConversionAtToFi_j[7] = FG_traj_fast_B.DataTypeConversion[6];
    rtb_TmpSignalConversionAtToFi_j[8] = FG_traj_fast_B.X_ref_y[0];
    rtb_TmpSignalConversionAtToFi_j[9] =
      FG_traj_fast_B.MAINCONTROLLOOP1.roll_cmd;
    rtb_TmpSignalConversionAtToFi_j[10] = FG_traj_fast_B.DataTypeConversion[2];
    rtb_TmpSignalConversionAtToFi_j[11] = FG_traj_fast_B.DataTypeConversion[5];
    rtb_TmpSignalConversionAtToFi_j[12] = FG_traj_fast_B.X_ref_z[0];
    rtb_TmpSignalConversionAtToFi_j[13] =
      FG_traj_fast_B.MAINCONTROLLOOP1.thrust_cmd;
    rtb_TmpSignalConversionAtToFi_j[14] = FG_traj_fast_B.DataTypeConversion[8];
    rtb_TmpSignalConversionAtToFi_j[15] = FG_traj_fast_B.DataTypeConversion[11];
    rtb_TmpSignalConversionAtToFi_j[16] = FG_traj_fast_B.X_ref_yaw[0];
    rtb_TmpSignalConversionAtToFi_j[17] =
      FG_traj_fast_B.MAINCONTROLLOOP1.yaw_rate_cmd;

    /* ToFile: '<S13>/To File' */
    {
      if (!(++FG_traj_fast_DWork.ToFile_IWORK_n.Decimation % 1) &&
          (FG_traj_fast_DWork.ToFile_IWORK_n.Count*19)+1 < 100000000 ) {
        FILE *fp = (FILE *) FG_traj_fast_DWork.ToFile_PWORK_d.FilePtr;
        if (fp != (NULL)) {
          real_T u[19];
          FG_traj_fast_DWork.ToFile_IWORK_n.Decimation = 0;
          u[0] = FG_traj_fast_M->Timing.taskTime0;
          u[1] = rtb_TmpSignalConversionAtToFi_j[0];
          u[2] = rtb_TmpSignalConversionAtToFi_j[1];
          u[3] = rtb_TmpSignalConversionAtToFi_j[2];
          u[4] = rtb_TmpSignalConversionAtToFi_j[3];
          u[5] = rtb_TmpSignalConversionAtToFi_j[4];
          u[6] = rtb_TmpSignalConversionAtToFi_j[5];
          u[7] = rtb_TmpSignalConversionAtToFi_j[6];
          u[8] = rtb_TmpSignalConversionAtToFi_j[7];
          u[9] = rtb_TmpSignalConversionAtToFi_j[8];
          u[10] = rtb_TmpSignalConversionAtToFi_j[9];
          u[11] = rtb_TmpSignalConversionAtToFi_j[10];
          u[12] = rtb_TmpSignalConversionAtToFi_j[11];
          u[13] = rtb_TmpSignalConversionAtToFi_j[12];
          u[14] = rtb_TmpSignalConversionAtToFi_j[13];
          u[15] = rtb_TmpSignalConversionAtToFi_j[14];
          u[16] = rtb_TmpSignalConversionAtToFi_j[15];
          u[17] = rtb_TmpSignalConversionAtToFi_j[16];
          u[18] = rtb_TmpSignalConversionAtToFi_j[17];
          if (fwrite(u, sizeof(real_T), 19, fp) != 19) {
            rtmSetErrorStatus(FG_traj_fast_M,
                              "Error writing to MAT-file hquad_pos_FG.mat");
            return;
          }

          if (((++FG_traj_fast_DWork.ToFile_IWORK_n.Count)*19)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file hquad_pos_FG.mat.\n");
          }
        }
      }
    }

    /* SignalConversion: '<S13>/TmpSignal ConversionAtTo File1Inport1' */
    rtb_TmpSignalConversionAtToFi_i[0] =
      FG_traj_fast_B.MAINCONTROLLOOP1.Saturation;
    rtb_TmpSignalConversionAtToFi_i[1] =
      FG_traj_fast_B.MAINCONTROLLOOP1.Saturation_l;
    rtb_TmpSignalConversionAtToFi_i[2] =
      FG_traj_fast_B.MAINCONTROLLOOP1.Saturation_p;
    rtb_TmpSignalConversionAtToFi_i[3] =
      FG_traj_fast_B.MAINCONTROLLOOP1.Saturation_c;

    /* ToFile: '<S13>/To File1' */
    {
      if (!(++FG_traj_fast_DWork.ToFile1_IWORK_d.Decimation % 1) &&
          (FG_traj_fast_DWork.ToFile1_IWORK_d.Count*5)+1 < 100000000 ) {
        FILE *fp = (FILE *) FG_traj_fast_DWork.ToFile1_PWORK_c.FilePtr;
        if (fp != (NULL)) {
          real_T u[5];
          FG_traj_fast_DWork.ToFile1_IWORK_d.Decimation = 0;
          u[0] = FG_traj_fast_M->Timing.taskTime0;
          u[1] = rtb_TmpSignalConversionAtToFi_i[0];
          u[2] = rtb_TmpSignalConversionAtToFi_i[1];
          u[3] = rtb_TmpSignalConversionAtToFi_i[2];
          u[4] = rtb_TmpSignalConversionAtToFi_i[3];
          if (fwrite(u, sizeof(real_T), 5, fp) != 5) {
            rtmSetErrorStatus(FG_traj_fast_M,
                              "Error writing to MAT-file hquad_pos_FG_bias.mat");
            return;
          }

          if (((++FG_traj_fast_DWork.ToFile1_IWORK_d.Count)*5)+1 >= 100000000) {
            (void)fprintf(stdout,
                          "*** The ToFile block will stop logging data before\n"
                          "    the simulation has ended, because it has reached\n"
                          "    the maximum number of elements (100000000)\n"
                          "    allowed in MAT-file hquad_pos_FG_bias.mat.\n");
          }
        }
      }
    }

    /* Gain: '<S13>/rad -> deg2' */
    FG_traj_fast_B.raddeg2_g[0] = FG_traj_fast_P.raddeg2_Gain *
      FG_traj_fast_B.DataTypeConversion[7];
    FG_traj_fast_B.raddeg2_g[1] = FG_traj_fast_P.raddeg2_Gain *
      FG_traj_fast_B.DataTypeConversion[10];
    FG_traj_fast_B.raddeg2_g[2] = FG_traj_fast_P.raddeg2_Gain *
      FG_traj_fast_B.MAINCONTROLLOOP1.pitch_cmd;

    /* Gain: '<S13>/rad -> deg1' */
    FG_traj_fast_B.raddeg1_i[0] = FG_traj_fast_P.raddeg1_Gain *
      FG_traj_fast_B.DataTypeConversion[6];
    FG_traj_fast_B.raddeg1_i[1] = FG_traj_fast_P.raddeg1_Gain *
      FG_traj_fast_B.DataTypeConversion[9];
    FG_traj_fast_B.raddeg1_i[2] = FG_traj_fast_P.raddeg1_Gain *
      FG_traj_fast_B.MAINCONTROLLOOP1.roll_cmd;

    /* Gain: '<S13>/rad -> deg3' */
    FG_traj_fast_B.raddeg3_g[0] = FG_traj_fast_P.raddeg3_Gain *
      FG_traj_fast_B.DataTypeConversion[8];
    FG_traj_fast_B.raddeg3_g[1] = FG_traj_fast_P.raddeg3_Gain *
      FG_traj_fast_B.DataTypeConversion[11];
    FG_traj_fast_B.raddeg3_g[2] = FG_traj_fast_P.raddeg3_Gain *
      FG_traj_fast_B.MAINCONTROLLOOP1.yaw_rate_cmd;

    /* Gain: '<S13>/rad -> deg' */
    FG_traj_fast_B.raddeg_e[0] = FG_traj_fast_P.raddeg_Gain *
      FG_traj_fast_B.DataTypeConversion[8];
    FG_traj_fast_B.raddeg_e[1] = FG_traj_fast_P.raddeg_Gain *
      FG_traj_fast_B.DataTypeConversion[11];
    FG_traj_fast_B.raddeg_e[2] = FG_traj_fast_P.raddeg_Gain *
      FG_traj_fast_B.X_ref_yaw[0];
    FG_traj_fast_B.raddeg_e[3] = FG_traj_fast_P.raddeg_Gain *
      FG_traj_fast_B.X_ref_yaw[1];

    /* Outputs for Atomic SubSystem: '<S6>/decoupling and rotation' */
    /* Inport: '<S10>/bias_W' */
    FG_traj_fast_B.bias_W_k[0] = rtb_TmpSignalConversionAtToFi_i[0];
    FG_traj_fast_B.bias_W_k[1] = rtb_TmpSignalConversionAtToFi_i[1];
    FG_traj_fast_B.bias_W_k[2] = rtb_TmpSignalConversionAtToFi_i[2];
    FG_traj_fast_B.bias_W_k[3] = rtb_TmpSignalConversionAtToFi_i[3];

    /* Inport: '<S10>/cmd_W' */
    FG_traj_fast_B.cmd_W_c[0] = FG_traj_fast_B.MAINCONTROLLOOP1.pitch_cmd;
    FG_traj_fast_B.cmd_W_c[1] = FG_traj_fast_B.MAINCONTROLLOOP1.roll_cmd;
    FG_traj_fast_B.cmd_W_c[2] = FG_traj_fast_B.MAINCONTROLLOOP1.thrust_cmd;
    FG_traj_fast_B.cmd_W_c[3] = FG_traj_fast_B.MAINCONTROLLOOP1.yaw_rate_cmd;

    /* MATLAB Function: '<S35>/Embedded MATLAB Function' */
    /* MATLAB Function 'decoupling and rotation/decoupling /Embedded MATLAB Function': '<S37>:1' */
    /* '<S37>:1:4' */
    rtb_Gain3 = FG_traj_fast_B.cmd_W_c[2] / (cos
      (FG_traj_fast_B.sf_EmbeddedMATLABFunction.pitch_rot) * cos
      (FG_traj_fast_B.sf_EmbeddedMATLABFunction.roll_rot));

    /* '<S37>:1:6' */
    /* '<S37>:1:7' */
    /*  pitch_cmd_comp=pitch_cmd; */
    /*  roll_cmd_comp=roll_cmd; */
    /*  pitch_cmd_comp = atan(Fx/(-thrust_comp)); */
    /*  roll_cmd_comp = atan(Fy/(thrust_comp)); */
    /*  pitch_cmd_comp = atan(-g*m*pitch_cmd/(-thrust)); */
    /*  roll_cmd_comp = atan(g*m*roll_cmd*cos(pitch_meas)/(thrust)); */
    FG_traj_fast_B.thrust_comp_c = rtb_Gain3;

    /* MATLAB Function: '<S36>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S35>/g'
     *  MATLAB Function: '<S35>/Embedded MATLAB Function'
     */
    /* MATLAB Function 'decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S38>:1' */
    /* '<S38>:1:3' */
    sin_yaw = sin(FG_traj_fast_B.DataTypeConversion[8]);

    /* '<S38>:1:4' */
    cos_yaw = cos(FG_traj_fast_B.DataTypeConversion[8]);

    /* '<S38>:1:6' */
    /* '<S38>:1:8' */
    unnamed_idx = FG_traj_fast_B.DataTypeConversion[29] * FG_traj_fast_P.g_Value
      / rtb_Gain3 * FG_traj_fast_B.cmd_W_c[0];
    rtb_Gain3 = FG_traj_fast_B.DataTypeConversion[29] * FG_traj_fast_P.g_Value /
      rtb_Gain3 * FG_traj_fast_B.cmd_W_c[1];

    /* '<S38>:1:9' */
    FG_traj_fast_B.pitch_rot_f = cos_yaw * unnamed_idx + -sin_yaw * rtb_Gain3;

    /* '<S38>:1:10' */
    FG_traj_fast_B.roll_rot_c = sin_yaw * unnamed_idx + cos_yaw * rtb_Gain3;

    /* '<S38>:1:12' */
    /* '<S38>:1:13' */
    FG_traj_fast_B.pitch_bias_rot_j = cos_yaw * FG_traj_fast_B.bias_W_k[0] +
      -sin_yaw * FG_traj_fast_B.bias_W_k[1];

    /* '<S38>:1:14' */
    FG_traj_fast_B.roll_bias_rot_g = sin_yaw * FG_traj_fast_B.bias_W_k[0] +
      cos_yaw * FG_traj_fast_B.bias_W_k[1];

    /* End of Outputs for SubSystem: '<S6>/decoupling and rotation' */
    srUpdateBC(FG_traj_fast_DWork.poscontroller_SubsysRanBC);
  } else {
    if (FG_traj_fast_DWork.poscontroller_MODE) {
      FG_traj_fast_DWork.poscontroller_MODE = FALSE;
    }
  }

  /* End of Outputs for SubSystem: '<Root>/pos controller' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S2>/pitch'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    FG_traj_fast_B.pitch_cmd = FG_traj_fast_B.pitch_rot;
  } else if (FG_traj_fast_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    FG_traj_fast_B.pitch_cmd = FG_traj_fast_B.pitch_rot_f;
  } else {
    FG_traj_fast_B.pitch_cmd = FG_traj_fast_P.pitch_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S2>/roll'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    FG_traj_fast_B.roll_cmd = FG_traj_fast_B.roll_rot;
  } else if (FG_traj_fast_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    FG_traj_fast_B.roll_cmd = FG_traj_fast_B.roll_rot_c;
  } else {
    FG_traj_fast_B.roll_cmd = FG_traj_fast_P.roll_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Product: '<S4>/Product' incorporates:
   *  Constant: '<S4>/gravity'
   */
  rtb_Gain3 = FG_traj_fast_P.gravity_Value_b *
    FG_traj_fast_B.DataTypeConversion[29];

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S2>/- gravity'
   *  Product: '<S2>/Product'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    FG_traj_fast_B.thrust_cmd = FG_traj_fast_B.thrust_comp;
  } else if (FG_traj_fast_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    FG_traj_fast_B.thrust_cmd = FG_traj_fast_B.thrust_comp_c;
  } else {
    FG_traj_fast_B.thrust_cmd = FG_traj_fast_P.gravity_Value *
      FG_traj_fast_B.DataTypeConversion[29];
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S2>/yaw'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    FG_traj_fast_B.yaw_rate_cmd = FG_traj_fast_B.cmd_W[3];
  } else if (FG_traj_fast_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    FG_traj_fast_B.yaw_rate_cmd = FG_traj_fast_B.cmd_W_c[3];
  } else {
    FG_traj_fast_B.yaw_rate_cmd = FG_traj_fast_P.yaw_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Outport: '<Root>/cmd_out' incorporates:
   *  Constant: '<S4>/pitch_offset'
   *  Constant: '<S4>/roll_offset'
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/Gain2'
   *  Gain: '<S4>/Gain3'
   *  Gain: '<S4>/pitch_cmd2pitch'
   *  Gain: '<S4>/roll_cmd2roll'
   *  Gain: '<S4>/trhust_cmd2thrust'
   *  Sum: '<S4>/Sum'
   *  Sum: '<S4>/Sum1'
   *  Sum: '<S4>/Sum2'
   *  Sum: '<S4>/Sum3'
   */
  arg_cmd_out[0] = (real32_T)((FG_traj_fast_B.pitch_cmd -
    FG_traj_fast_P.pitch_offset_Value) * FG_traj_fast_P.pitch_cmd2pitch_Gain *
    FG_traj_fast_P.Gain1_Gain);
  arg_cmd_out[1] = (real32_T)((FG_traj_fast_B.roll_cmd -
    FG_traj_fast_P.roll_offset_Value) * FG_traj_fast_P.roll_cmd2roll_Gain *
    FG_traj_fast_P.Gain2_Gain);
  arg_cmd_out[2] = (real32_T)(((FG_traj_fast_B.thrust_cmd - rtb_Gain3) *
    FG_traj_fast_P.trhust_cmd2thrust_Gain + rtb_Gain3) *
    FG_traj_fast_P.Gain_Gain * FG_traj_fast_P.Gain3_Gain);

  /* ManualSwitch: '<S4>/Manual Switch' incorporates:
   *  Constant: '<S4>/yaw_rate'
   *  Gain: '<S4>/yaw_cmd2yaw'
   */
  if (FG_traj_fast_P.ManualSwitch_CurrentSetting == 1) {
    rtb_Gain3 = FG_traj_fast_P.yaw_cmd2yaw_Gain * FG_traj_fast_B.yaw_rate_cmd;
  } else {
    rtb_Gain3 = FG_traj_fast_P.yaw_rate_Value;
  }

  /* End of ManualSwitch: '<S4>/Manual Switch' */

  /* Outport: '<Root>/cmd_out' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  Gain: '<S4>/Gain4'
   */
  arg_cmd_out[3] = (real32_T)(FG_traj_fast_P.Gain4_Gain * rtb_Gain3);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S2>/pitch_bias'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    FG_traj_fast_B.pitch_bias = FG_traj_fast_B.pitch_bias_rot;
  } else if (FG_traj_fast_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    FG_traj_fast_B.pitch_bias = FG_traj_fast_B.pitch_bias_rot_j;
  } else {
    FG_traj_fast_B.pitch_bias = FG_traj_fast_P.pitch_bias_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S2>/roll_bias'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    FG_traj_fast_B.roll_bias = FG_traj_fast_B.roll_bias_rot;
  } else if (FG_traj_fast_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    FG_traj_fast_B.roll_bias = FG_traj_fast_B.roll_bias_rot_g;
  } else {
    FG_traj_fast_B.roll_bias = FG_traj_fast_P.roll_bias_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S2>/thrust_bias'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    FG_traj_fast_B.thrust_bias = FG_traj_fast_B.bias_W[2];
  } else if (FG_traj_fast_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    FG_traj_fast_B.thrust_bias = FG_traj_fast_B.bias_W_k[2];
  } else {
    FG_traj_fast_B.thrust_bias = FG_traj_fast_P.thrust_bias_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<S2>/yaw_rate_bias'
   *  Switch: '<Root>/Switch3'
   */
  if (rtb_MultiportSwitch2 != 0.0) {
    FG_traj_fast_B.yaw_rate_bias = FG_traj_fast_B.bias_W[3];
  } else if (FG_traj_fast_B.MultiportSwitch != 0.0) {
    /* Switch: '<Root>/Switch3' */
    FG_traj_fast_B.yaw_rate_bias = FG_traj_fast_B.bias_W_k[3];
  } else {
    FG_traj_fast_B.yaw_rate_bias = FG_traj_fast_P.yaw_rate_bias_Value;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Update for UnitDelay: '<S8>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S8>/FixPt Constant'
   */
  FG_traj_fast_DWork.FixPtUnitDelay2_DSTATE = FG_traj_fast_P.FixPtConstant_Value;

  /* Switch: '<S8>/Reset' */
  if (rtb_MultiportSwitch1 != 0.0) {
    /* Update for UnitDelay: '<S8>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S8>/Initial Condition'
     */
    FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[0] =
      FG_traj_fast_P.InitialCondition_Value;
    FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[1] =
      FG_traj_fast_P.InitialCondition_Value;
    FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[2] =
      FG_traj_fast_P.InitialCondition_Value;
    FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[3] =
      FG_traj_fast_P.InitialCondition_Value;
  } else {
    /* Update for UnitDelay: '<S8>/FixPt Unit Delay1' */
    FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[0] = FG_traj_fast_B.pitch_bias;
    FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[1] = FG_traj_fast_B.roll_bias;
    FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[2] = FG_traj_fast_B.thrust_bias;
    FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[3] = FG_traj_fast_B.yaw_rate_bias;
  }

  /* End of Switch: '<S8>/Reset' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, FG_traj_fast_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(FG_traj_fast_M)!=-1) &&
        !((rtmGetTFinal(FG_traj_fast_M)-FG_traj_fast_M->Timing.taskTime0) >
          FG_traj_fast_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(FG_traj_fast_M, "Simulation finished");
    }

    if (rtmGetStopRequested(FG_traj_fast_M)) {
      rtmSetErrorStatus(FG_traj_fast_M, "Simulation finished");
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
  if (!(++FG_traj_fast_M->Timing.clockTick0)) {
    ++FG_traj_fast_M->Timing.clockTickH0;
  }

  FG_traj_fast_M->Timing.taskTime0 = FG_traj_fast_M->Timing.clockTick0 *
    FG_traj_fast_M->Timing.stepSize0 + FG_traj_fast_M->Timing.clockTickH0 *
    FG_traj_fast_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void FG_traj_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)FG_traj_fast_M, 0,
                sizeof(RT_MODEL_FG_traj_fast));
  rtmSetTFinal(FG_traj_fast_M, -1);
  FG_traj_fast_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  FG_traj_fast_M->Sizes.checksums[0] = (484232947U);
  FG_traj_fast_M->Sizes.checksums[1] = (3809245171U);
  FG_traj_fast_M->Sizes.checksums[2] = (649542148U);
  FG_traj_fast_M->Sizes.checksums[3] = (1283454371U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[45];
    FG_traj_fast_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    systemRan[15] = &rtAlwaysEnabled;
    systemRan[16] = &rtAlwaysEnabled;
    systemRan[17] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[18] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[24] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[25] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[26] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[27] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[28] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[29] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[30] = (sysRanDType *)&FG_traj_fast_DWork.poscontroller_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[37] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[38] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[39] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[40] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[41] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    systemRan[44] = (sysRanDType *)
      &FG_traj_fast_DWork.poscontroller1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(FG_traj_fast_M->extModeInfo,
      &FG_traj_fast_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(FG_traj_fast_M->extModeInfo,
                        FG_traj_fast_M->Sizes.checksums);
    rteiSetTPtr(FG_traj_fast_M->extModeInfo, rtmGetTPtr(FG_traj_fast_M));
  }

  /* block I/O */
  (void) memset(((void *) &FG_traj_fast_B), 0,
                sizeof(BlockIO_FG_traj_fast));

  /* states (dwork) */
  (void) memset((void *)&FG_traj_fast_DWork, 0,
                sizeof(D_Work_FG_traj_fast));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    FG_traj_fast_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for Enabled SubSystem: '<Root>/pos controller1' */

  /* Start for ToFile: '<S44>/To File' */
  {
    char fileName[509] = "hquad_traj_FG.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(FG_traj_fast_M,
                        "Error creating .mat file hquad_traj_FG.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,19,0,"hquad_pos_FG")) {
      rtmSetErrorStatus(FG_traj_fast_M,
                        "Error writing mat file header to file hquad_traj_FG.mat");
      return;
    }

    FG_traj_fast_DWork.ToFile_IWORK.Count = 0;
    FG_traj_fast_DWork.ToFile_IWORK.Decimation = -1;
    FG_traj_fast_DWork.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for ToFile: '<S44>/To File1' */
  {
    char fileName[509] = "hquad_traj_FG_bias.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(FG_traj_fast_M,
                        "Error creating .mat file hquad_traj_FG_bias.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,5,0,"hquad_pos_FG_bias")) {
      rtmSetErrorStatus(FG_traj_fast_M,
                        "Error writing mat file header to file hquad_traj_FG_bias.mat");
      return;
    }

    FG_traj_fast_DWork.ToFile1_IWORK.Count = 0;
    FG_traj_fast_DWork.ToFile1_IWORK.Decimation = -1;
    FG_traj_fast_DWork.ToFile1_PWORK.FilePtr = fp;
  }

  /* End of Start for SubSystem: '<Root>/pos controller1' */

  /* InitializeConditions for Enabled SubSystem: '<Root>/pos controller1' */

  /* InitializeConditions for Atomic SubSystem: '<S7>/MAIN CONTROL LOOP1' */
  FG_traj_f_MAINCONTROLLOOP1_Init(&FG_traj_fast_DWork.MAINCONTROLLOOP1_c,
    (rtP_MAINCONTROLLOOP1_FG_traj_fa *)&FG_traj_fast_P.MAINCONTROLLOOP1_c);

  /* End of InitializeConditions for SubSystem: '<S7>/MAIN CONTROL LOOP1' */

  /* End of InitializeConditions for SubSystem: '<Root>/pos controller1' */

  /* Start for Enabled SubSystem: '<Root>/pos controller' */

  /* Start for ToFile: '<S13>/To File' */
  {
    char fileName[509] = "hquad_pos_FG.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(FG_traj_fast_M,
                        "Error creating .mat file hquad_pos_FG.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,19,0,"hquad_pos_FG")) {
      rtmSetErrorStatus(FG_traj_fast_M,
                        "Error writing mat file header to file hquad_pos_FG.mat");
      return;
    }

    FG_traj_fast_DWork.ToFile_IWORK_n.Count = 0;
    FG_traj_fast_DWork.ToFile_IWORK_n.Decimation = -1;
    FG_traj_fast_DWork.ToFile_PWORK_d.FilePtr = fp;
  }

  /* Start for ToFile: '<S13>/To File1' */
  {
    char fileName[509] = "hquad_pos_FG_bias.mat";
    FILE *fp = (NULL);
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(FG_traj_fast_M,
                        "Error creating .mat file hquad_pos_FG_bias.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,5,0,"hquad_pos_FG_bias")) {
      rtmSetErrorStatus(FG_traj_fast_M,
                        "Error writing mat file header to file hquad_pos_FG_bias.mat");
      return;
    }

    FG_traj_fast_DWork.ToFile1_IWORK_d.Count = 0;
    FG_traj_fast_DWork.ToFile1_IWORK_d.Decimation = -1;
    FG_traj_fast_DWork.ToFile1_PWORK_c.FilePtr = fp;
  }

  /* End of Start for SubSystem: '<Root>/pos controller' */

  /* InitializeConditions for Enabled SubSystem: '<Root>/pos controller' */

  /* InitializeConditions for Atomic SubSystem: '<S6>/MAIN CONTROL LOOP1' */
  FG_traj_f_MAINCONTROLLOOP1_Init(&FG_traj_fast_DWork.MAINCONTROLLOOP1,
    (rtP_MAINCONTROLLOOP1_FG_traj_fa *)&FG_traj_fast_P.MAINCONTROLLOOP1);

  /* End of InitializeConditions for SubSystem: '<S6>/MAIN CONTROL LOOP1' */

  /* End of InitializeConditions for SubSystem: '<Root>/pos controller' */

  /* InitializeConditions for UnitDelay: '<S8>/FixPt Unit Delay2' */
  FG_traj_fast_DWork.FixPtUnitDelay2_DSTATE =
    FG_traj_fast_P.FixPtUnitDelay2_InitialConditio;

  /* InitializeConditions for UnitDelay: '<S8>/FixPt Unit Delay1' */
  FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[0] =
    FG_traj_fast_P.FixPtUnitDelay1_InitialConditio;
  FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[1] =
    FG_traj_fast_P.FixPtUnitDelay1_InitialConditio;
  FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[2] =
    FG_traj_fast_P.FixPtUnitDelay1_InitialConditio;
  FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[3] =
    FG_traj_fast_P.FixPtUnitDelay1_InitialConditio;
}

/* Model terminate function */
void FG_traj_fast_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<Root>/pos controller1' */

  /* Terminate for ToFile: '<S44>/To File' */
  {
    FILE *fp = (FILE *) FG_traj_fast_DWork.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "hquad_traj_FG.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error closing MAT-file hquad_traj_FG.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error reopening MAT-file hquad_traj_FG.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 19, FG_traj_fast_DWork.ToFile_IWORK.Count,
           "hquad_pos_FG")) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error writing header for hquad_pos_FG to MAT-file hquad_traj_FG.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error closing MAT-file hquad_traj_FG.mat");
        return;
      }

      FG_traj_fast_DWork.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S44>/To File1' */
  {
    FILE *fp = (FILE *) FG_traj_fast_DWork.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "hquad_traj_FG_bias.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error closing MAT-file hquad_traj_FG_bias.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error reopening MAT-file hquad_traj_FG_bias.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 5, FG_traj_fast_DWork.ToFile1_IWORK.Count,
           "hquad_pos_FG_bias")) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error writing header for hquad_pos_FG_bias to MAT-file hquad_traj_FG_bias.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error closing MAT-file hquad_traj_FG_bias.mat");
        return;
      }

      FG_traj_fast_DWork.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* End of Terminate for SubSystem: '<Root>/pos controller1' */

  /* Terminate for Enabled SubSystem: '<Root>/pos controller' */

  /* Terminate for ToFile: '<S13>/To File' */
  {
    FILE *fp = (FILE *) FG_traj_fast_DWork.ToFile_PWORK_d.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "hquad_pos_FG.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error closing MAT-file hquad_pos_FG.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error reopening MAT-file hquad_pos_FG.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 19, FG_traj_fast_DWork.ToFile_IWORK_n.Count,
           "hquad_pos_FG")) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error writing header for hquad_pos_FG to MAT-file hquad_pos_FG.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error closing MAT-file hquad_pos_FG.mat");
        return;
      }

      FG_traj_fast_DWork.ToFile_PWORK_d.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<S13>/To File1' */
  {
    FILE *fp = (FILE *) FG_traj_fast_DWork.ToFile1_PWORK_c.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "hquad_pos_FG_bias.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error closing MAT-file hquad_pos_FG_bias.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error reopening MAT-file hquad_pos_FG_bias.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 5, FG_traj_fast_DWork.ToFile1_IWORK_d.Count,
           "hquad_pos_FG_bias")) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error writing header for hquad_pos_FG_bias to MAT-file hquad_pos_FG_bias.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(FG_traj_fast_M,
                          "Error closing MAT-file hquad_pos_FG_bias.mat");
        return;
      }

      FG_traj_fast_DWork.ToFile1_PWORK_c.FilePtr = (NULL);
    }
  }

  /* End of Terminate for SubSystem: '<Root>/pos controller' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
