/*
 * File: controller_template.cpp
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
static void controller_template_round_e(real_T x[4]);
static void controller_template_mrdivide_e(const real_T A[4], real_T B, real_T
  y[4]);
static void controller_template_round(real_T x[4]);
static void controller_template_mrdivide(const real_T A[4], real_T B, real_T y[4]);
static void controller_template_round_j(real_T x[5]);
static void controller_template_mrdivide_j(const real_T A[5], real_T B, real_T
  y[5]);
static void controller_template_mrdivide_d(const real_T A[16], const real_T B[16],
  real_T y[16]);
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
  if ((controller_template_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.04s, 0.0s] */
    controller_template_M->Timing.TaskCounters.TID[1] = 0;
  }

  (controller_template_M->Timing.TaskCounters.TID[2])++;
  if ((controller_template_M->Timing.TaskCounters.TID[2]) > 3) {/* Sample time: [0.08s, 0.0s] */
    controller_template_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S17>/generate_X_ref_x'
 *    '<S18>/generate_X_ref_x'
 *    '<S116>/generate_X_ref_x'
 */
void controlle_generate_X_ref_x_Init(rtDW_generate_X_ref_x_controlle *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c19_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S17>/generate_X_ref_x'
 *    '<S18>/generate_X_ref_x'
 *    '<S116>/generate_X_ref_x'
 */
void controller_tem_generate_X_ref_x(const real_T rtu_traj_x[909], real_T
  rtu_idx, rtB_generate_X_ref_x_controller *localB,
  rtDW_generate_X_ref_x_controlle *localDW)
{
  int32_T i;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_x': '<S20>:1' */
  /* '<S20>:1:5' */
  for (i = 0; i < 31; i++) {
    localB->X_ref_x[3 * i] = rtu_traj_x[((int32_T)(rtu_idx + (real_T)i) - 1) * 3];
    localB->X_ref_x[1 + 3 * i] = rtu_traj_x[((int32_T)(rtu_idx + (real_T)i) - 1)
      * 3 + 1];
    localB->X_ref_x[2 + 3 * i] = rtu_traj_x[((int32_T)(rtu_idx + (real_T)i) - 1)
      * 3 + 2];
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S17>/generate_X_ref_y'
 *    '<S18>/generate_X_ref_y'
 *    '<S116>/generate_X_ref_y'
 */
void controlle_generate_X_ref_y_Init(rtDW_generate_X_ref_y_controlle *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c20_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S17>/generate_X_ref_y'
 *    '<S18>/generate_X_ref_y'
 *    '<S116>/generate_X_ref_y'
 */
void controller_tem_generate_X_ref_y(const real_T rtu_traj_y[909], real_T
  rtu_idx, rtB_generate_X_ref_y_controller *localB,
  rtDW_generate_X_ref_y_controlle *localDW)
{
  int32_T i;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_y': '<S21>:1' */
  /* '<S21>:1:5' */
  for (i = 0; i < 31; i++) {
    localB->X_ref_y[3 * i] = rtu_traj_y[((int32_T)(rtu_idx + (real_T)i) - 1) * 3];
    localB->X_ref_y[1 + 3 * i] = rtu_traj_y[((int32_T)(rtu_idx + (real_T)i) - 1)
      * 3 + 1];
    localB->X_ref_y[2 + 3 * i] = rtu_traj_y[((int32_T)(rtu_idx + (real_T)i) - 1)
      * 3 + 2];
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S17>/generate_X_ref_yaw'
 *    '<S18>/generate_X_ref_yaw'
 *    '<S116>/generate_X_ref_yaw'
 */
void control_generate_X_ref_yaw_Init(rtDW_generate_X_ref_yaw_control *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c21_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S17>/generate_X_ref_yaw'
 *    '<S18>/generate_X_ref_yaw'
 *    '<S116>/generate_X_ref_yaw'
 */
void controller_t_generate_X_ref_yaw(const real_T rtu_X_ref_yaw_unbounded[606],
  real_T rtu_yaw_meas, real_T rtu_idx, rtB_generate_X_ref_yaw_controll *localB,
  rtDW_generate_X_ref_yaw_control *localDW)
{
  real_T yaw_offset;
  int32_T i;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_yaw': '<S22>:1' */
  /* '<S22>:1:5' */
  /* '<S22>:1:6' */
  /* '<S22>:1:9' */
  yaw_offset = (rtu_yaw_meas - rtu_X_ref_yaw_unbounded[((int32_T)rtu_idx - 1) <<
                1]) / 6.2831853071795862;
  if (!(fabs(yaw_offset) > 4.503599627370496E+15)) {
    if (yaw_offset >= 0.5) {
      yaw_offset = floor(yaw_offset + 0.5);
    } else if (yaw_offset > -0.5) {
      yaw_offset = -0.0;
    } else {
      yaw_offset = ceil(yaw_offset - 0.5);
    }
  }

  yaw_offset = yaw_offset * 2.0 * 3.1415926535897931;

  /* '<S22>:1:11' */
  for (i = 0; i < 31; i++) {
    localB->X_ref_yaw[(i << 1)] = rtu_X_ref_yaw_unbounded[((int32_T)(rtu_idx +
      (real_T)i) - 1) << 1] + yaw_offset;
  }

  for (i = 0; i < 31; i++) {
    localB->X_ref_yaw[1 + (i << 1)] = rtu_X_ref_yaw_unbounded[(((int32_T)
      (rtu_idx + (real_T)i) - 1) << 1) + 1];
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S17>/generate_X_ref_z'
 *    '<S18>/generate_X_ref_z'
 *    '<S116>/generate_X_ref_z'
 */
void controlle_generate_X_ref_z_Init(rtDW_generate_X_ref_z_controlle *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c22_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S17>/generate_X_ref_z'
 *    '<S18>/generate_X_ref_z'
 *    '<S116>/generate_X_ref_z'
 */
void controller_tem_generate_X_ref_z(const real_T rtu_traj_z[606], real_T
  rtu_idx, rtB_generate_X_ref_z_controller *localB,
  rtDW_generate_X_ref_z_controlle *localDW)
{
  int32_T i;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_z': '<S23>:1' */
  /* '<S23>:1:5' */
  for (i = 0; i < 31; i++) {
    localB->X_ref_z[(i << 1)] = rtu_traj_z[((int32_T)(rtu_idx + (real_T)i) - 1) <<
      1];
    localB->X_ref_z[1 + (i << 1)] = rtu_traj_z[(((int32_T)(rtu_idx + (real_T)i)
      - 1) << 1) + 1];
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S50>/MATLAB Function'
 *    '<S115>/MATLAB Function'
 *    '<S136>/MATLAB Function'
 */
void controller__MATLABFunction_Init(rtDW_MATLABFunction_controller_ *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c15_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S50>/MATLAB Function'
 *    '<S115>/MATLAB Function'
 *    '<S136>/MATLAB Function'
 */
void controller_templ_MATLABFunction(real_T rtu_u, real_T rtu_thres,
  rtB_MATLABFunction_controller_t *localB, rtDW_MATLABFunction_controller_
  *localDW)
{
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation/MATLAB Function': '<S65>:1' */
  if (rtu_u >= rtu_thres) {
    /* '<S65>:1:3' */
    /* '<S65>:1:4' */
    localB->y = 0.0;
  } else {
    /* '<S65>:1:6' */
    localB->y = rtu_u;
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S73>/MATLAB Function'
 *    '<S101>/MATLAB Function'
 */
void controlle_MATLABFunction_l_Init(rtDW_MATLABFunction_controlle_o *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c13_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S73>/MATLAB Function'
 *    '<S101>/MATLAB Function'
 */
void controller_tem_MATLABFunction_l(real_T rtu_u, real_T rtu_thres,
  rtB_MATLABFunction_controller_p *localB, rtDW_MATLABFunction_controlle_o
  *localDW)
{
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Wall Deviation/MATLAB Function': '<S80>:1' */
  if (rtu_u >= rtu_thres) {
    /* '<S80>:1:3' */
    /* '<S80>:1:4' */
    localB->y = 0.1;
  } else {
    /* '<S80>:1:6' */
    localB->y = rtu_u;
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S34>/discrete kalman filter'
 *    '<S160>/discrete kalman filter'
 *    '<S162>/discrete kalman filter'
 */
void contr_discretekalmanfilter_Init(rtDW_discretekalmanfilter_contr *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c27_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S34>/discrete kalman filter'
 *    '<S160>/discrete kalman filter'
 *    '<S162>/discrete kalman filter'
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

  /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter': '<S96>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S96>:1:10' */
  for (i = 0; i < 3; i++) {
    /* SignalConversion: '<S96>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = ((rtu_A[i + 3] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
            6] * rtu_state_g) + rtu_B[i] * rtu_u;
  }

  /* '<S96>:1:11' */
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
  /* '<S96>:1:14' */
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

  /* '<S96>:1:15' */
  /* '<S96>:1:16' */
  for (i = 0; i < 9; i++) {
    I[i] = 0;
  }

  I[0] = 1;
  I[4] = 1;
  I[8] = 1;
  for (i = 0; i < 2; i++) {
    tmp[i] = rtu_C[i + 4] * x[2] + (rtu_C[i + 2] * x[1] + rtu_C[i] * x[0]);
  }

  /* SignalConversion: '<S96>/TmpSignal ConversionAt SFunction Inport8' */
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
 *    '<S155>/runFastGradient'
 *    '<S157>/runFastGradient'
 */
void controller_runFastGradient_Init(rtDW_runFastGradient_controller *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c6_Hquad_control_LIB_ = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S155>/runFastGradient'
 *    '<S157>/runFastGradient'
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

  /* MATLAB Function 'x controller MPC FG  /runFastGradient': '<S163>:1' */
  /*  ugly, but simulink needs fix output sizes for vectors */
  /*  number of outputs u */
  /*  number of delay steps */
  /*  prediction horizon */
  /*  predict non-delayed state */
  /* '<S163>:1:14' */
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
  /* '<S163>:1:21' */
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

  /* '<S163>:1:22' */
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
  /* '<S163>:1:25' */
  /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
  /*  so don't forget to backtransform after termination: */
  /* '<S163>:1:32' */
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
  /* '<S163>:1:38' */
  /*  set new initial guess */
  /* '<S163>:1:42' */
  /* '<S163>:1:44' */
  localB->u_opt = U_star[0];
  localB->J_star = ((y[0] * x_predicted_idx + y[1] * x_predicted_idx_0) + y[2] *
                    x_predicted_idx_1) + (L_inv + d_y);
  localB->u_buff_out[0] = rtu_u_buff[1];
  localB->u_buff_out[1] = rtu_u_buff[2];
  localB->u_buff_out[2] = U_star[0];
  memcpy((void *)(&localB->V_init_out[0]), (void *)&V_i[1], 29U * sizeof(real_T));
  localB->V_init_out[29] = 0.0;
}

/* Function for MATLAB Function: '<S156>/discrete kalman filter' */
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
 *    '<S156>/discrete kalman filter'
 *    '<S158>/discrete kalman filter'
 */
void con_discretekalmanfilter_k_Init(rtDW_discretekalmanfilter_con_c *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c11_Hquad_control_LIB = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S156>/discrete kalman filter'
 *    '<S158>/discrete kalman filter'
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

  /* MATLAB Function 'x states estimator bias/discrete kalman filter': '<S165>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S165>:1:10' */
  for (i = 0; i < 4; i++) {
    /* SignalConversion: '<S165>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = (((rtu_A[i + 4] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
             8] * rtu_state[2]) + rtu_A[i + 12] * rtu_state_m) + rtu_B[i] *
      rtu_u;
  }

  /* '<S165>:1:11' */
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
  /* '<S165>:1:14' */
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

  /* '<S165>:1:15' */
  /* '<S165>:1:16' */
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

  /* SignalConversion: '<S165>/TmpSignal ConversionAt SFunction Inport8' */
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

/* Function for MATLAB Function: '<S44>/Ctrl_Xdir' */
static void controller_template_round_e(real_T x[4])
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

/* Function for MATLAB Function: '<S44>/Ctrl_Xdir' */
static void controller_template_mrdivide_e(const real_T A[4], real_T B, real_T
  y[4])
{
  y[0] = A[0] / B;
  y[1] = A[1] / B;
  y[2] = A[2] / B;
  y[3] = A[3] / B;
}

/* Function for MATLAB Function: '<S43>/Ctrl_Xdir' */
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

/* Function for MATLAB Function: '<S43>/Ctrl_Xdir' */
static void controller_template_mrdivide(const real_T A[4], real_T B, real_T y[4])
{
  y[0] = A[0] / B;
  y[1] = A[1] / B;
  y[2] = A[2] / B;
  y[3] = A[3] / B;
}

/* Function for MATLAB Function: '<S68>/Ctrl_Xdir' */
static void controller_template_round_j(real_T x[5])
{
  int32_T k;
  real_T b_x;
  for (k = 0; k < 5; k++) {
    if (fabs(x[k]) > 4.503599627370496E+15) {
      b_x = x[k];
    } else if (x[k] >= 0.5) {
      b_x = floor(x[k] + 0.5);
    } else if (x[k] > -0.5) {
      b_x = x[k] * 0.0;
    } else {
      b_x = ceil(x[k] - 0.5);
    }

    x[k] = b_x;
  }
}

/* Function for MATLAB Function: '<S68>/Ctrl_Xdir' */
static void controller_template_mrdivide_j(const real_T A[5], real_T B, real_T
  y[5])
{
  int32_T i;
  for (i = 0; i < 5; i++) {
    y[i] = A[i] / B;
  }
}

/* Function for MATLAB Function: '<S59>/MATLAB Function' */
static void controller_template_mrdivide_d(const real_T A[16], const real_T B[16],
  real_T y[16])
{
  real_T Y[16];
  real_T temp;
  real_T b_A[16];
  int8_T ipiv[4];
  int32_T jj;
  int32_T jp1j;
  int32_T jrow;
  int32_T b_j;
  int32_T ix;
  real_T s;
  int32_T b_ix;
  int32_T iy;
  int32_T jy;
  for (b_j = 0; b_j < 4; b_j++) {
    b_A[b_j << 2] = B[b_j];
    b_A[1 + (b_j << 2)] = B[b_j + 4];
    b_A[2 + (b_j << 2)] = B[b_j + 8];
    b_A[3 + (b_j << 2)] = B[b_j + 12];
  }

  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  for (b_j = 0; b_j < 3; b_j++) {
    jj = b_j * 5;
    jp1j = jj;
    jy = 0;
    ix = jj;
    temp = fabs(b_A[jj]);
    for (jrow = 1; jrow + 1 <= 4 - b_j; jrow++) {
      ix++;
      s = fabs(b_A[ix]);
      if (s > temp) {
        jy = jrow;
        temp = s;
      }
    }

    if (b_A[jj + jy] != 0.0) {
      if (jy != 0) {
        ipiv[b_j] = (int8_T)((b_j + jy) + 1);
        iy = b_j + jy;
        temp = b_A[b_j];
        b_A[b_j] = b_A[iy];
        b_A[iy] = temp;
        b_ix = b_j + 4;
        iy += 4;
        temp = b_A[b_ix];
        b_A[b_ix] = b_A[iy];
        b_A[iy] = temp;
        b_ix += 4;
        iy += 4;
        temp = b_A[b_ix];
        b_A[b_ix] = b_A[iy];
        b_A[iy] = temp;
        b_ix += 4;
        iy += 4;
        temp = b_A[b_ix];
        b_A[b_ix] = b_A[iy];
        b_A[iy] = temp;
      }

      ix = jj - b_j;
      for (jrow = jj + 1; jrow + 1 <= ix + 4; jrow++) {
        b_A[jrow] /= b_A[jj];
      }
    }

    jy = jj + 4;
    for (ix = 1; ix <= 3 - b_j; ix++) {
      temp = b_A[jy];
      if (b_A[jy] != 0.0) {
        jrow = jp1j + 2;
        iy = jj - b_j;
        for (b_ix = 5 + jj; b_ix + 1 <= iy + 8; b_ix++) {
          b_A[b_ix] += b_A[jrow - 1] * -temp;
          jrow++;
        }
      }

      jy += 4;
      jj += 4;
    }
  }

  for (b_j = 0; b_j < 4; b_j++) {
    Y[b_j << 2] = A[b_j];
    Y[1 + (b_j << 2)] = A[b_j + 4];
    Y[2 + (b_j << 2)] = A[b_j + 8];
    Y[3 + (b_j << 2)] = A[b_j + 12];
  }

  for (ix = 0; ix < 4; ix++) {
    if (ix + 1 != ipiv[ix]) {
      temp = Y[ix];
      Y[ix] = Y[ipiv[ix] - 1];
      Y[ipiv[ix] - 1] = temp;
      temp = Y[ix + 4];
      Y[ix + 4] = Y[ipiv[ix] + 3];
      Y[ipiv[ix] + 3] = temp;
      temp = Y[ix + 8];
      Y[ix + 8] = Y[ipiv[ix] + 7];
      Y[ipiv[ix] + 7] = temp;
      temp = Y[ix + 12];
      Y[ix + 12] = Y[ipiv[ix] + 11];
      Y[ipiv[ix] + 11] = temp;
    }
  }

  for (ix = 0; ix < 4; ix++) {
    jrow = ix << 2;
    if (Y[jrow] != 0.0) {
      for (b_ix = 2; b_ix < 5; b_ix++) {
        Y[(b_ix + jrow) - 1] -= b_A[b_ix - 1] * Y[jrow];
      }
    }

    if (Y[1 + jrow] != 0.0) {
      for (b_ix = 3; b_ix < 5; b_ix++) {
        Y[(b_ix + jrow) - 1] -= Y[1 + jrow] * b_A[b_ix + 3];
      }
    }

    if (Y[2 + jrow] != 0.0) {
      b_ix = 4;
      while (b_ix < 5) {
        Y[jrow + 3] -= Y[2 + jrow] * b_A[11];
        b_ix = 5;
      }
    }
  }

  for (ix = 0; ix < 4; ix++) {
    jrow = ix << 2;
    if (Y[3 + jrow] != 0.0) {
      Y[3 + jrow] /= b_A[15];
      for (b_ix = 0; b_ix + 1 < 4; b_ix++) {
        Y[b_ix + jrow] -= Y[3 + jrow] * b_A[b_ix + 12];
      }
    }

    if (Y[2 + jrow] != 0.0) {
      Y[2 + jrow] /= b_A[10];
      for (b_ix = 0; b_ix + 1 < 3; b_ix++) {
        Y[b_ix + jrow] -= Y[2 + jrow] * b_A[b_ix + 8];
      }
    }

    if (Y[1 + jrow] != 0.0) {
      Y[1 + jrow] /= b_A[5];
      for (b_ix = 0; b_ix + 1 < 2; b_ix++) {
        Y[b_ix + jrow] -= Y[1 + jrow] * b_A[b_ix + 4];
      }
    }

    if (Y[jrow] != 0.0) {
      Y[jrow] /= b_A[0];
    }
  }

  for (b_j = 0; b_j < 4; b_j++) {
    y[b_j << 2] = Y[b_j];
    y[1 + (b_j << 2)] = Y[b_j + 4];
    y[2 + (b_j << 2)] = Y[b_j + 8];
    y[3 + (b_j << 2)] = Y[b_j + 12];
  }
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
  real_T rtb_Add;
  real_T rtb_SliderGain_p;
  real_T rtb_Sum2_m;
  real_T rtb_Sum2_l;
  real_T rtb_TmpSignalConversionAtToFi_p[4];
  real_T rtb_Sum2_m2;
  real_T rtb_Add_k;
  real_T rtb_SliderGain_m1;
  real_T rtb_IntegerDelay3_c;
  real_T rtb_UnitDelay1_d[9];
  real_T rtb_Init_jd[2];
  real_T rtb_bias_W[4];
  real_T rtb_Add_c;
  real_T rtb_SliderGain_n4;
  real_T rtb_Add_kj;
  real_T rtb_SliderGain_j;
  real_T rtb_Add_e;
  real_T rtb_SliderGain_kp;
  real_T rtb_TmpSignalConversionAtToFi_f[18];
  real_T rtb_TmpSignalConversionAtToFi_a[18];
  real_T sin_yaw;
  real_T cos_yaw;
  int32_T dz;
  int32_T flag_oob;
  int32_T minreg;
  real_T abspos;
  real_T sumViol;
  int32_T isinside;
  int32_T ireg;
  int32_T exitg;
  real_T U;
  real_T X[5];
  real_T U_0;
  real_T Hi[500];
  real_T Ki[100];
  real_T U_1;
  real_T Hi_0[300];
  real_T U_2;
  real_T Hi_1[100];
  real_T x_pred[4];
  real_T P_pred[16];
  real_T K[16];
  int8_T I[16];
  int8_T b_I[16];
  real_T LL_PP_ref[30];
  real_T U_star[30];
  real_T V_i[30];
  real_T V_ip[30];
  real_T b_y[30];
  real_T rtb_MultiportSwitch1;
  real_T rtb_MultiportSwitch2;
  real_T rtb_SwitchControl;
  real_T rtb_Saturation3;
  real_T rtb_y_ref;
  real_T rtb_z_ref;
  real_T rtb_SliderGain_h;
  real_T rtb_SliderGain_l;
  real_T rtb_SliderGain_c;
  real_T rtb_SliderGain_m;
  real_T rtb_Sum_c;
  real_T rtb_Sum_f;
  real_T rtb_X_ref_y[93];
  real_T rtb_X_ref_z[62];
  real_T rtb_X_ref_x[93];
  real_T rtb_X_ref_x_k[93];
  real_T rtb_X_ref_y_j[93];
  real_T rtb_X_ref_z_a[62];
  real_T rtb_X_ref_yaw[62];
  real_T rtb_X_ref_yaw_a[62];
  real_T rtb_yaw_ref;
  real_T rtb_Saturation2_l;
  real_T rtb_Switch[4];
  real_T rtb_UnitDelay_g;
  real_T rtb_Saturation3_o;
  real_T rtb_pitch_cmd_b;
  real_T yaw_rate_cmd_g;
  int32_T i;
  real_T P_pred_0[16];
  real_T X_0[5];
  real_T rtb_Switch_0[4];
  real_T tmp[8];
  real_T tmp_0[4];
  real_T tmp_1[5];
  real_T I_0[16];
  real_T I_1[16];
  real_T K_0[16];
  real_T K_1[16];
  real_T temp[30];
  real_T tmp_2[30];
  real_T tmp_3[2];
  real_T temp_idx;

  {                                    /* Sample time: [0.02s, 0.0s] */
    boolean_T rtmStopReq = FALSE;
    rtExtModePauseIfNeeded(controller_template_M->extModeInfo, 3, &rtmStopReq);
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

  /* Switch: '<S148>/Init' incorporates:
   *  Constant: '<S148>/Initial Condition'
   *  Logic: '<S148>/FixPt Logical Operator'
   *  UnitDelay: '<S148>/FixPt Unit Delay1'
   *  UnitDelay: '<S148>/FixPt Unit Delay2'
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

  /* End of Switch: '<S148>/Init' */
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
      controller_template_P.SwitchControl_Threshold_e) {
    rtb_SwitchControl = controller_template_P.Constant_Value_pe;
  } else {
    rtb_SwitchControl = rtb_MultiportSwitch2;
  }

  /* End of Switch: '<S5>/SwitchControl' */

  /* Outputs for Enabled SubSystem: '<Root>/FreeFlight Pos Ctrl' incorporates:
   *  EnablePort: '<S2>/Enable'
   */
  if (rtb_SwitchControl > 0.0) {
    if (!controller_template_DWork.FreeFlightPosCtrl_MODE) {
      /* InitializeConditions for MATLAB Function: '<S15>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_bq = CALL_EVENT;
      controller_template_DWork.is_active_c26_Hquad_control_L_f = 0U;

      /* InitializeConditions for MATLAB Function: '<S115>/MATLAB Function' */
      controller__MATLABFunction_Init
        (&controller_template_DWork.sf_MATLABFunction);

      /* InitializeConditions for UnitDelay: '<S108>/Unit Delay' */
      controller_template_DWork.UnitDelay_2_DSTATE =
        controller_template_P.UnitDelay_2_X0;

      /* InitializeConditions for UnitDelay: '<S108>/Unit Delay' */
      controller_template_DWork.UnitDelay_3_DSTATE =
        controller_template_P.UnitDelay_3_X0;

      /* InitializeConditions for MATLAB Function: '<S112>/MATLAB Function' */
      controller_template_DWork.sfEvent_a = CALL_EVENT;
      controller_template_DWork.is_active_c18_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S108>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_i =
        controller_template_P.UnitDelay1_X0_ie;

      /* InitializeConditions for MATLAB Function: '<S108>/Next Ref' */
      controller_template_DWork.sfEvent_p = CALL_EVENT;
      controller_template_DWork.is_active_c35_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S116>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_g =
        controller_template_P.UnitDelay_X0_o;

      /* InitializeConditions for MATLAB Function: '<S116>/generate_X_ref_x' */
      controlle_generate_X_ref_x_Init
        (&controller_template_DWork.sf_generate_X_ref_x);

      /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_c =
        controller_template_P.UnitDelay_X0_e;

      /* InitializeConditions for MATLAB Function: '<S18>/generate_X_ref_x' */
      controlle_generate_X_ref_x_Init
        (&controller_template_DWork.sf_generate_X_ref_x_a);

      /* InitializeConditions for MATLAB Function: '<S116>/generate_X_ref_y' */
      controlle_generate_X_ref_y_Init
        (&controller_template_DWork.sf_generate_X_ref_y);

      /* InitializeConditions for MATLAB Function: '<S18>/generate_X_ref_y' */
      controlle_generate_X_ref_y_Init
        (&controller_template_DWork.sf_generate_X_ref_y_k);

      /* InitializeConditions for MATLAB Function: '<S116>/generate_X_ref_z' */
      controlle_generate_X_ref_z_Init
        (&controller_template_DWork.sf_generate_X_ref_z);

      /* InitializeConditions for MATLAB Function: '<S18>/generate_X_ref_z' */
      controlle_generate_X_ref_z_Init
        (&controller_template_DWork.sf_generate_X_ref_z_b);

      /* InitializeConditions for MATLAB Function: '<S116>/generate_X_ref_yaw' */
      control_generate_X_ref_yaw_Init
        (&controller_template_DWork.sf_generate_X_ref_yaw);

      /* InitializeConditions for MATLAB Function: '<S18>/generate_X_ref_yaw' */
      control_generate_X_ref_yaw_Init
        (&controller_template_DWork.sf_generate_X_ref_yaw_h);

      /* InitializeConditions for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
      /* InitializeConditions for Delay: '<S11>/Integer Delay3' */
      controller_template_DWork.IntegerDelay3_DSTATE_k =
        controller_template_P.IntegerDelay3_InitialCondition;

      /* InitializeConditions for MATLAB Function: '<S34>/MATLAB Function' */
      controller_template_DWork.sfEvent_ks = CALL_EVENT;
      controller_template_DWork.is_active_c28_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S34>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_bg, (void *)
             controller_template_P.UnitDelay1_X0, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S95>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
        controller_template_P.FixPtUnitDelay2_X0;

      /* InitializeConditions for UnitDelay: '<S95>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0] =
        controller_template_P.FixPtUnitDelay1_X0;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1] =
        controller_template_P.FixPtUnitDelay1_X0;

      /* InitializeConditions for MATLAB Function: '<S34>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter);

      /* InitializeConditions for UnitDelay: '<S31>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_h[0] =
        controller_template_P.UnitDelay1_X0_d[0];
      controller_template_DWork.UnitDelay1_DSTATE_h[1] =
        controller_template_P.UnitDelay1_X0_d[1];
      controller_template_DWork.UnitDelay1_DSTATE_h[2] =
        controller_template_P.UnitDelay1_X0_d[2];
      controller_template_DWork.UnitDelay1_DSTATE_h[3] =
        controller_template_P.UnitDelay1_X0_d[3];

      /* InitializeConditions for UnitDelay: '<S31>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE =
        controller_template_P.UnitDelay2_X0;

      /* InitializeConditions for MATLAB Function: '<S50>/MATLAB Function' */
      controller__MATLABFunction_Init
        (&controller_template_DWork.sf_MATLABFunction_e);

      /* InitializeConditions for UnitDelay: '<S44>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_c =
        controller_template_P.UnitDelay2_X0_g;

      /* InitializeConditions for MATLAB Function: '<S55>/MATLAB Function' */
      controller_template_DWork.sfEvent_ac = CALL_EVENT;
      controller_template_DWork.is_active_c7_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S44>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_cm = CALL_EVENT;
      controller_template_DWork.is_active_c1_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S43>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_m =
        controller_template_P.UnitDelay2_X0_b;

      /* InitializeConditions for MATLAB Function: '<S52>/MATLAB Function' */
      controller_template_DWork.sfEvent_kd = CALL_EVENT;
      controller_template_DWork.is_active_c26_controller_templa = 0U;

      /* InitializeConditions for MATLAB Function: '<S43>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_cr = CALL_EVENT;
      controller_template_DWork.is_active_c24_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S48>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_d =
        controller_template_P.UnitDelay2_X0_m;

      /* InitializeConditions for UnitDelay: '<S48>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_jv =
        controller_template_P.UnitDelay_X0;

      /* InitializeConditions for MATLAB Function: '<S29>/MATLAB Function' */
      controller_template_DWork.sfEvent_fp = CALL_EVENT;
      controller_template_DWork.is_active_c12_controller_templa = 0U;

      /* InitializeConditions for MATLAB Function: '<S73>/MATLAB Function' */
      controlle_MATLABFunction_l_Init
        (&controller_template_DWork.sf_MATLABFunction_l5);

      /* InitializeConditions for UnitDelay: '<S68>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_l =
        controller_template_P.UnitDelay2_X0_d;

      /* InitializeConditions for MATLAB Function: '<S76>/MATLAB Function' */
      controller_template_DWork.sfEvent_i = CALL_EVENT;
      controller_template_DWork.is_active_c5_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S68>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_cd = CALL_EVENT;
      controller_template_DWork.is_active_c2_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S72>/MATLAB Function' */
      controller_template_DWork.sfEvent_ab = CALL_EVENT;
      controller_template_DWork.is_active_c17_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S69>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_k =
        controller_template_P.UnitDelay2_X0_n;

      /* InitializeConditions for UnitDelay: '<S69>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_f =
        controller_template_P.UnitDelay_X0_f;

      /* InitializeConditions for MATLAB Function: '<S101>/MATLAB Function' */
      controlle_MATLABFunction_l_Init
        (&controller_template_DWork.sf_MATLABFunction_c);

      /* InitializeConditions for MATLAB Function: '<S97>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_k0 = CALL_EVENT;
      controller_template_DWork.is_active_c3_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S100>/MATLAB Function' */
      controller_template_DWork.sfEvent_jj = CALL_EVENT;
      controller_template_DWork.is_active_c16_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S98>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_b =
        controller_template_P.UnitDelay2_X0_o;

      /* InitializeConditions for UnitDelay: '<S98>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_fw =
        controller_template_P.UnitDelay_X0_i;

      /* InitializeConditions for UnitDelay: '<S33>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_lg =
        controller_template_P.UnitDelay_X0_m;

      /* InitializeConditions for MATLAB Function: '<S33>/MATLAB Function' */
      controller_template_DWork.sfEvent_g = CALL_EVENT;
      controller_template_DWork.is_active_c25_controller_templa = 0U;

      /* InitializeConditions for MATLAB Function: '<S33>/MATLAB Function1' */
      controller_template_DWork.sfEvent_d = CALL_EVENT;
      controller_template_DWork.is_active_c30_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S83>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_g =
        controller_template_P.UnitDelay2_X0_ng;

      /* InitializeConditions for MATLAB Function: '<S92>/MATLAB Function' */
      controller_template_DWork.sfEvent_l = CALL_EVENT;
      controller_template_DWork.is_active_c6_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S83>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_jv = CALL_EVENT;
      controller_template_DWork.is_active_c4_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S86>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_ga =
        controller_template_P.UnitDelay2_X0_i;

      /* InitializeConditions for UnitDelay: '<S86>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_p =
        controller_template_P.UnitDelay_X0_c;

      /* InitializeConditions for UnitDelay: '<S48>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_a =
        controller_template_P.UnitDelay1_X0_i;

      /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_a =
        controller_template_P.UnitDelay_X0_d;

      /* InitializeConditions for MATLAB Function: '<S49>/MATLAB Function1' */
      controller_template_DWork.sfEvent_h = CALL_EVENT;
      controller_template_DWork.is_active_c41_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S59>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_m[0] =
        controller_template_P.UnitDelay_X0_a[0];
      controller_template_DWork.UnitDelay_DSTATE_m[1] =
        controller_template_P.UnitDelay_X0_a[1];
      controller_template_DWork.UnitDelay_DSTATE_m[2] =
        controller_template_P.UnitDelay_X0_a[2];
      controller_template_DWork.UnitDelay_DSTATE_m[3] =
        controller_template_P.UnitDelay_X0_a[3];

      /* InitializeConditions for UnitDelay: '<S59>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j5, (void *)
             controller_template_P.UnitDelay1_X0_ic, sizeof(real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S60>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_m2 =
        controller_template_P.UnitDelay_X0_if;

      /* InitializeConditions for MATLAB Function: '<S60>/MATLAB Function' */
      controller_template_DWork.sfEvent_fc = CALL_EVENT;
      controller_template_DWork.is_active_c40_controller_templa = 0U;

      /* InitializeConditions for MATLAB Function: '<S62>/MATLAB Function' */
      controller_template_DWork.sfEvent_du = CALL_EVENT;
      controller_template_DWork.is_active_c43_controller_templa = 0U;

      /* InitializeConditions for MATLAB Function: '<S59>/MATLAB Function' */
      controller_template_DWork.sfEvent_cq = CALL_EVENT;
      controller_template_DWork.is_active_c42_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S69>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_ji =
        controller_template_P.UnitDelay1_X0_dy;

      /* InitializeConditions for UnitDelay: '<S86>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_c3 =
        controller_template_P.UnitDelay1_X0_j;

      /* InitializeConditions for UnitDelay: '<S98>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_m =
        controller_template_P.UnitDelay1_X0_f;

      /* End of InitializeConditions for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

      /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_e =
        controller_template_P.UnitDelay_X0_b;

      /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_x' */
      controlle_generate_X_ref_x_Init
        (&controller_template_DWork.sf_generate_X_ref_x_k);

      /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_y' */
      controlle_generate_X_ref_y_Init
        (&controller_template_DWork.sf_generate_X_ref_y_a);

      /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_yaw' */
      control_generate_X_ref_yaw_Init
        (&controller_template_DWork.sf_generate_X_ref_yaw_g);

      /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_z' */
      controlle_generate_X_ref_z_Init
        (&controller_template_DWork.sf_generate_X_ref_z_l);

      /* InitializeConditions for UnitDelay: '<S111>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_es =
        controller_template_P.UnitDelay_X0_l;

      /* InitializeConditions for UnitDelay: '<S111>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_o =
        controller_template_P.UnitDelay1_X0_js;

      /* InitializeConditions for MATLAB Function: '<S111>/MATLAB Function' */
      controller_template_DWork.sfEvent_jg = CALL_EVENT;
      controller_template_DWork.is_active_c11_controller_templa = 0U;

      /* InitializeConditions for Atomic SubSystem: '<S2>/decoupling and rotation' */
      /* InitializeConditions for MATLAB Function: '<S136>/MATLAB Function' */
      controller__MATLABFunction_Init
        (&controller_template_DWork.sf_MATLABFunction_p);

      /* InitializeConditions for MATLAB Function: '<S133>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_c = CALL_EVENT;
      controller_template_DWork.is_active_c9_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S134>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_j = CALL_EVENT;
      controller_template_DWork.is_active_c10_controller_templa = 0U;

      /* End of InitializeConditions for SubSystem: '<S2>/decoupling and rotation' */
      controller_template_DWork.FreeFlightPosCtrl_MODE = TRUE;
    }

    /* MATLAB Function: '<S15>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_bq = CALL_EVENT;

    /* MATLAB Function 'rotate to world frame/Embedded MATLAB Function': '<S141>:1' */
    /* '<S141>:1:5' */
    sin_yaw = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S141>:1:6' */
    cos_yaw = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S141>:1:8' */
    /* '<S141>:1:10' */
    /* '<S141>:1:11' */
    controller_template_B.pitch_rot_i = cos_yaw *
      controller_template_B.DataTypeConversion[7] + sin_yaw *
      controller_template_B.DataTypeConversion[6];

    /* '<S141>:1:12' */
    controller_template_B.roll_rot_f = -sin_yaw *
      controller_template_B.DataTypeConversion[7] + cos_yaw *
      controller_template_B.DataTypeConversion[6];

    /* '<S141>:1:14' */
    /* '<S141>:1:15' */
    controller_template_B.pitch_bias_rot_p = cos_yaw * rtb_Init[0] + sin_yaw *
      rtb_Init[1];

    /* '<S141>:1:16' */
    controller_template_B.roll_bias_rot_n = -sin_yaw * rtb_Init[0] + cos_yaw *
      rtb_Init[1];

    /* Sum: '<S115>/Add' incorporates:
     *  Constant: '<S115>/Constant'
     *  Gain: '<S127>/Slider Gain'
     */
    rtb_Add = controller_template_B.DataTypeConversion[0] -
      controller_template_P.SliderGain_Gain_e *
      controller_template_P.Constant_Value_i;

    /* Gain: '<S128>/Slider Gain' incorporates:
     *  Constant: '<S115>/Constant1'
     */
    rtb_SliderGain_p = controller_template_P.SliderGain_Gain_jr *
      controller_template_P.Constant1_Value_e;

    /* MATLAB Function: '<S115>/MATLAB Function' */
    controller_templ_MATLABFunction(rtb_Add, rtb_SliderGain_p,
      &controller_template_B.sf_MATLABFunction,
      &controller_template_DWork.sf_MATLABFunction);

    /* Saturate: '<S115>/Saturation3' */
    rtb_Saturation3 = controller_template_B.sf_MATLABFunction.y >=
      controller_template_P.Saturation3_UpperSat_f ?
      controller_template_P.Saturation3_UpperSat_f :
      controller_template_B.sf_MATLABFunction.y <=
      controller_template_P.Saturation3_LowerSat_lw ?
      controller_template_P.Saturation3_LowerSat_lw :
      controller_template_B.sf_MATLABFunction.y;

    /* UnitDelay: '<S108>/Unit Delay' */
    rtb_y_ref = controller_template_DWork.UnitDelay_2_DSTATE;

    /* UnitDelay: '<S108>/Unit Delay' */
    rtb_z_ref = controller_template_DWork.UnitDelay_3_DSTATE;

    /* Gain: '<S114>/Slider Gain' incorporates:
     *  Constant: '<S108>/Constant1'
     */
    rtb_SliderGain_h = controller_template_P.SliderGain_Gain_db *
      controller_template_P.Constant1_Value_j2;

    /* Gain: '<S113>/Slider Gain' incorporates:
     *  Constant: '<S108>/Constant'
     */
    rtb_SliderGain_l = controller_template_P.SliderGain_Gain_ne *
      controller_template_P.Constant_Value_le;

    /* Gain: '<S121>/Slider Gain' incorporates:
     *  Constant: '<S112>/Constant'
     */
    sin_yaw = controller_template_P.SliderGain_Gain_dsh *
      controller_template_P.Constant_Value_kb;

    /* Gain: '<S122>/Slider Gain' incorporates:
     *  Constant: '<S112>/Constant'
     */
    cos_yaw = controller_template_P.SliderGain_Gain_cx *
      controller_template_P.Constant_Value_kb;

    /* Gain: '<S123>/Slider Gain' incorporates:
     *  Constant: '<S112>/Constant1'
     */
    rtb_SliderGain_c = controller_template_P.SliderGain_Gain_mi *
      controller_template_P.Constant1_Value_kj;

    /* Gain: '<S124>/Slider Gain' incorporates:
     *  Constant: '<S112>/Constant2'
     */
    rtb_SliderGain_m = controller_template_P.SliderGain_Gain_nu *
      controller_template_P.Constant2_Value_c;

    /* MATLAB Function: '<S112>/MATLAB Function' */
    controller_template_DWork.sfEvent_a = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/MATLAB Function': '<S120>:1' */
    /* '<S120>:1:4' */
    controller_template_B.nominal_window_z_out = rtb_SliderGain_h;

    /* '<S120>:1:5' */
    controller_template_B.nominal_window_y_out = rtb_SliderGain_l;

    /* '<S120>:1:7' */
    sumViol = fabs(controller_template_B.DataTypeConversion[4]);

    /* '<S120>:1:8' */
    if (sumViol > cos_yaw) {
      /* '<S120>:1:10' */
      /* '<S120>:1:11' */
      temp_idx = fabs(sumViol - cos_yaw) * rtb_SliderGain_c;
      controller_template_B.nominal_window_y_out = rtb_SliderGain_l - ((temp_idx
        <= rtb_SliderGain_m) || rtIsNaN(rtb_SliderGain_m) ? temp_idx :
        rtb_SliderGain_m);
    }

    if (controller_template_B.DataTypeConversion[5] > sin_yaw) {
      /* '<S120>:1:14' */
      /* '<S120>:1:15' */
      temp_idx = fabs(controller_template_B.DataTypeConversion[5] - sin_yaw) *
        rtb_SliderGain_c;
      controller_template_B.nominal_window_z_out = rtb_SliderGain_h - ((temp_idx
        <= rtb_SliderGain_m) || rtIsNaN(rtb_SliderGain_m) ? temp_idx :
        rtb_SliderGain_m);
    }

    /* End of MATLAB Function: '<S112>/MATLAB Function' */

    /* Gain: '<S125>/Slider Gain' incorporates:
     *  Constant: '<S112>/Constant3'
     */
    sin_yaw = controller_template_P.SliderGain_Gain_ka *
      controller_template_P.Constant3_Value_f;

    /* Switch: '<S112>/Switch1' */
    if (sin_yaw >= controller_template_P.Switch1_Threshold) {
      controller_template_B.Switch1 = controller_template_B.nominal_window_y_out;
    } else {
      controller_template_B.Switch1 = rtb_SliderGain_l;
    }

    /* End of Switch: '<S112>/Switch1' */

    /* Switch: '<S112>/Switch' */
    if (sin_yaw >= controller_template_P.Switch_Threshold_f) {
      controller_template_B.Switch = controller_template_B.nominal_window_z_out;
    } else {
      controller_template_B.Switch = rtb_SliderGain_h;
    }

    /* End of Switch: '<S112>/Switch' */

    /* UnitDelay: '<S108>/Unit Delay1' */
    controller_template_B.UnitDelay1 =
      controller_template_DWork.UnitDelay1_DSTATE_i;

    /* MATLAB Function: '<S108>/Next Ref' incorporates:
     *  Constant: '<S108>/Total Samples'
     *  Gain: '<S110>/Slider Gain'
     *  UnitDelay: '<S108>/Unit Delay'
     */
    controller_template_DWork.sfEvent_p = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Next Ref': '<S109>:1' */
    if (fabs(controller_template_B.DataTypeConversion[1] -
             controller_template_DWork.UnitDelay_2_DSTATE) >
        controller_template_B.Switch1) {
      /* '<S109>:1:3' */
      /* '<S109>:1:4' */
      i = 1;
    } else {
      /* '<S109>:1:6' */
      i = 0;

      /*  in position */
    }

    /*  if abs(z-zref) > thresz */
    /*      dz = 1; */
    /*  else */
    /*      dz = 0; % in position */
    /*  end */
    if ((controller_template_B.DataTypeConversion[2] -
         controller_template_DWork.UnitDelay_3_DSTATE >
         controller_template_B.Switch) ||
        (-(controller_template_B.DataTypeConversion[2] -
           controller_template_DWork.UnitDelay_3_DSTATE) >
         controller_template_P.SliderGain_Gain_h * controller_template_B.Switch))
    {
      /* '<S109>:1:17' */
      /* '<S109>:1:18' */
      dz = 1;
    } else {
      /* '<S109>:1:20' */
      dz = 0;

      /*  in position */
    }

    if ((i != 0) || (dz != 0) || (rtb_Saturation3 != 0.0)) {
      /* '<S109>:1:24' */
      /* '<S109>:1:25' */
      controller_template_B.en = 0.0;

      /*  not yet in position, don't change reference */
    } else if (controller_template_B.UnitDelay1 <
               controller_template_P.TotalSamples_Value) {
      /* '<S109>:1:27' */
      /* '<S109>:1:28' */
      controller_template_B.en = 1.0;

      /*  in position, both deviations < thres, change ref. point. */
    } else {
      /* '<S109>:1:30' */
      controller_template_B.en = 0.0;
    }

    /* End of MATLAB Function: '<S108>/Next Ref' */

    /* Sum: '<S116>/Sum' incorporates:
     *  UnitDelay: '<S116>/Unit Delay'
     */
    rtb_Sum_c = controller_template_B.en +
      controller_template_DWork.UnitDelay_DSTATE_g;

    /* Sum: '<S116>/Sum2' incorporates:
     *  Constant: '<S116>/Constant1'
     *  Constant: '<S116>/total_samples'
     *  Math: '<S116>/Math Function'
     */
    rtb_Sum2_m = rt_modd_snf(rtb_Sum_c,
      controller_template_P.total_samples_Value) +
      controller_template_P.Constant1_Value_mu;

    /* MATLAB Function: '<S116>/generate_X_ref_x' */
    controller_tem_generate_X_ref_x(controller_template_P.X_ref_x_Value,
      rtb_Sum2_m, &controller_template_B.sf_generate_X_ref_x,
      &controller_template_DWork.sf_generate_X_ref_x);

    /* Sum: '<S116>/Add3' */
    for (i = 0; i < 93; i++) {
      rtb_X_ref_x[i] = controller_template_B.sf_generate_X_ref_x.X_ref_x[i] +
        controller_template_B.X_ref_x[i];
    }

    /* End of Sum: '<S116>/Add3' */

    /* Sum: '<S18>/Sum' incorporates:
     *  Constant: '<S10>/Constant'
     *  UnitDelay: '<S18>/Unit Delay'
     */
    rtb_Sum_f = controller_template_P.Constant_Value_lw +
      controller_template_DWork.UnitDelay_DSTATE_c;

    /* Sum: '<S18>/Sum2' incorporates:
     *  Constant: '<S18>/Constant1'
     *  Constant: '<S18>/total_samples'
     *  Math: '<S18>/Math Function'
     */
    rtb_Sum2_l = rt_modd_snf(rtb_Sum_f,
      controller_template_P.total_samples_Value_h) +
      controller_template_P.Constant1_Value_o;

    /* MATLAB Function: '<S18>/generate_X_ref_x' */
    controller_tem_generate_X_ref_x(controller_template_P.X_ref_x_Value_n,
      rtb_Sum2_l, &controller_template_B.sf_generate_X_ref_x_a,
      &controller_template_DWork.sf_generate_X_ref_x_a);

    /* Sum: '<S18>/Add3' */
    for (i = 0; i < 93; i++) {
      rtb_X_ref_x_k[i] = controller_template_B.sf_generate_X_ref_x_a.X_ref_x[i]
        + controller_template_B.X_ref_x[i];
    }

    /* End of Sum: '<S18>/Add3' */

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_1_Threshold) {
      controller_template_B.x_ref = rtb_X_ref_x[0];
    } else {
      controller_template_B.x_ref = rtb_X_ref_x_k[0];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* MATLAB Function: '<S116>/generate_X_ref_y' */
    controller_tem_generate_X_ref_y(controller_template_P.X_ref_y_Value,
      rtb_Sum2_m, &controller_template_B.sf_generate_X_ref_y,
      &controller_template_DWork.sf_generate_X_ref_y);

    /* Sum: '<S116>/Add2' */
    for (i = 0; i < 93; i++) {
      rtb_X_ref_y[i] = controller_template_B.sf_generate_X_ref_y.X_ref_y[i] +
        controller_template_B.X_ref_y[i];
    }

    /* End of Sum: '<S116>/Add2' */

    /* MATLAB Function: '<S18>/generate_X_ref_y' */
    controller_tem_generate_X_ref_y(controller_template_P.X_ref_y_Value_f,
      rtb_Sum2_l, &controller_template_B.sf_generate_X_ref_y_k,
      &controller_template_DWork.sf_generate_X_ref_y_k);

    /* Sum: '<S18>/Add2' */
    for (i = 0; i < 93; i++) {
      rtb_X_ref_y_j[i] = controller_template_B.sf_generate_X_ref_y_k.X_ref_y[i]
        + controller_template_B.X_ref_y[i];
    }

    /* End of Sum: '<S18>/Add2' */

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_2_Threshold) {
      controller_template_B.y_ref = rtb_X_ref_y[0];
    } else {
      controller_template_B.y_ref = rtb_X_ref_y_j[0];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* MATLAB Function: '<S116>/generate_X_ref_z' */
    controller_tem_generate_X_ref_z(controller_template_P.X_ref_z_Value,
      rtb_Sum2_m, &controller_template_B.sf_generate_X_ref_z,
      &controller_template_DWork.sf_generate_X_ref_z);

    /* Sum: '<S116>/Add1' */
    for (i = 0; i < 62; i++) {
      rtb_X_ref_z[i] = controller_template_B.sf_generate_X_ref_z.X_ref_z[i] +
        controller_template_B.X_ref_z[i];
    }

    /* End of Sum: '<S116>/Add1' */

    /* MATLAB Function: '<S18>/generate_X_ref_z' */
    controller_tem_generate_X_ref_z(controller_template_P.X_ref_z_Value_p,
      rtb_Sum2_l, &controller_template_B.sf_generate_X_ref_z_b,
      &controller_template_DWork.sf_generate_X_ref_z_b);

    /* Sum: '<S18>/Add1' */
    for (i = 0; i < 62; i++) {
      rtb_X_ref_z_a[i] = controller_template_B.sf_generate_X_ref_z_b.X_ref_z[i]
        + controller_template_B.X_ref_z[i];
    }

    /* End of Sum: '<S18>/Add1' */

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_3_Threshold) {
      controller_template_B.z_ref = rtb_X_ref_z[0];
    } else {
      controller_template_B.z_ref = rtb_X_ref_z_a[0];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* MATLAB Function: '<S116>/generate_X_ref_yaw' */
    controller_t_generate_X_ref_yaw(controller_template_P.X_ref_yaw_Value,
      controller_template_B.DataTypeConversion[8], rtb_Sum2_m,
      &controller_template_B.sf_generate_X_ref_yaw,
      &controller_template_DWork.sf_generate_X_ref_yaw);

    /* Sum: '<S116>/Add' */
    for (i = 0; i < 62; i++) {
      rtb_X_ref_yaw[i] = controller_template_B.sf_generate_X_ref_yaw.X_ref_yaw[i]
        + controller_template_B.X_ref_yaw[i];
    }

    /* End of Sum: '<S116>/Add' */

    /* MATLAB Function: '<S18>/generate_X_ref_yaw' */
    controller_t_generate_X_ref_yaw(controller_template_P.X_ref_yaw_Value_i,
      controller_template_B.DataTypeConversion[8], rtb_Sum2_l,
      &controller_template_B.sf_generate_X_ref_yaw_h,
      &controller_template_DWork.sf_generate_X_ref_yaw_h);

    /* Sum: '<S18>/Add' incorporates:
     *  Gain: '<S18>/Gain'
     */
    for (i = 0; i < 62; i++) {
      rtb_X_ref_yaw_a[i] = controller_template_P.Gain_Gain_m *
        controller_template_B.X_ref_yaw[i] +
        controller_template_B.sf_generate_X_ref_yaw_h.X_ref_yaw[i];
    }

    /* End of Sum: '<S18>/Add' */

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_4_Threshold) {
      rtb_yaw_ref = rtb_X_ref_yaw[0];
    } else {
      rtb_yaw_ref = rtb_X_ref_yaw_a[0];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* Outputs for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* Delay: '<S11>/Integer Delay3' */
    rtb_IntegerDelay3_c = controller_template_DWork.IntegerDelay3_DSTATE_k;

    /* MATLAB Function: '<S34>/MATLAB Function' */
    controller_template_DWork.sfEvent_ks = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/MATLAB Function': '<S94>:1' */
    /* '<S94>:1:4' */
    controller_template_B.psi_prime = controller_template_B.DataTypeConversion[8];
    if ((controller_template_B.DataTypeConversion[8] >= 0.78539816339744828) &&
        (controller_template_B.DataTypeConversion[8] <= 3.2553426535897931)) {
      /* '<S94>:1:7' */
      /* '<S94>:1:8' */
      controller_template_B.psi_prime =
        (controller_template_B.DataTypeConversion[8] - 3.1415926535897931) -
        3.1415926535897931;
    }

    /* End of MATLAB Function: '<S34>/MATLAB Function' */

    /* UnitDelay: '<S34>/Unit Delay1' */
    /*  if(psi_meas<=pi */
    memcpy((void *)&rtb_UnitDelay1_d[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_bg, 9U * sizeof(real_T));

    /* Switch: '<S95>/Init' incorporates:
     *  UnitDelay: '<S95>/FixPt Unit Delay1'
     *  UnitDelay: '<S95>/FixPt Unit Delay2'
     */
    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_g != 0) {
      rtb_Init_jd[0] = controller_template_B.psi_prime;
    } else {
      rtb_Init_jd[0] = controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0];
    }

    if (controller_template_DWork.FixPtUnitDelay2_DSTATE_g != 0) {
      rtb_Init_jd[1] = controller_template_B.DataTypeConversion[11];
    } else {
      rtb_Init_jd[1] = controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1];
    }

    /* End of Switch: '<S95>/Init' */

    /* Inport: '<S11>/bias_W' */
    rtb_bias_W[0] = controller_template_B.pitch_bias_rot_p;
    rtb_bias_W[1] = controller_template_B.roll_bias_rot_n;
    rtb_bias_W[2] = rtb_Init[2];
    rtb_bias_W[3] = rtb_Init[3];

    /* MATLAB Function: '<S34>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.psi_prime,
      controller_template_B.DataTypeConversion[11], rtb_Init_jd, rtb_bias_W[3],
      controller_template_P.A_Value, controller_template_P.B_Value,
      controller_template_P.C_Value, controller_template_P.Q_Value,
      controller_template_P.R_Value, rtb_IntegerDelay3_c, rtb_UnitDelay1_d,
      &controller_template_B.sf_discretekalmanfilter,
      &controller_template_DWork.sf_discretekalmanfilter);

    /* Gain: '<S34>/Gain2' incorporates:
     *  Saturate: '<S34>/Saturation'
     */
    controller_template_B.Gain2 =
      (controller_template_B.sf_discretekalmanfilter.state_est[2] >=
       controller_template_P.Saturation_UpperSat ?
       controller_template_P.Saturation_UpperSat :
       controller_template_B.sf_discretekalmanfilter.state_est[2] <=
       controller_template_P.Saturation_LowerSat ?
       controller_template_P.Saturation_LowerSat :
       controller_template_B.sf_discretekalmanfilter.state_est[2]) *
      controller_template_P.Gain2_Gain;

    /* Switch: '<S31>/Switch' incorporates:
     *  UnitDelay: '<S31>/Unit Delay1'
     *  UnitDelay: '<S31>/Unit Delay2'
     */
    if (controller_template_DWork.UnitDelay2_DSTATE >=
        controller_template_P.Switch_Threshold) {
      rtb_Switch[0] = controller_template_DWork.UnitDelay1_DSTATE_h[0];
    } else {
      rtb_Switch[0] = controller_template_B.pitch_rot_i;
    }

    if (controller_template_DWork.UnitDelay2_DSTATE >=
        controller_template_P.Switch_Threshold) {
      rtb_Switch[1] = controller_template_DWork.UnitDelay1_DSTATE_h[1];
    } else {
      rtb_Switch[1] = controller_template_B.DataTypeConversion[10];
    }

    if (controller_template_DWork.UnitDelay2_DSTATE >=
        controller_template_P.Switch_Threshold) {
      rtb_Switch[2] = controller_template_DWork.UnitDelay1_DSTATE_h[2];
    } else {
      rtb_Switch[2] = controller_template_B.DataTypeConversion[0];
    }

    if (controller_template_DWork.UnitDelay2_DSTATE >=
        controller_template_P.Switch_Threshold) {
      rtb_Switch[3] = controller_template_DWork.UnitDelay1_DSTATE_h[3];
    } else {
      rtb_Switch[3] = controller_template_B.DataTypeConversion[3];
    }

    /* End of Switch: '<S31>/Switch' */

    /* Saturate: '<S31>/Saturation' */
    rtb_Saturation2_l = rtb_Switch[0] >=
      controller_template_P.Saturation_UpperSat_i ?
      controller_template_P.Saturation_UpperSat_i : rtb_Switch[0] <=
      controller_template_P.Saturation_LowerSat_j ?
      controller_template_P.Saturation_LowerSat_j : rtb_Switch[0];

    /* Saturate: '<S31>/Saturation1' */
    rtb_UnitDelay_g = rtb_Switch[1] >=
      controller_template_P.Saturation1_UpperSat ?
      controller_template_P.Saturation1_UpperSat : rtb_Switch[1] <=
      controller_template_P.Saturation1_LowerSat ?
      controller_template_P.Saturation1_LowerSat : rtb_Switch[1];

    /* Sum: '<S50>/Add' incorporates:
     *  Constant: '<S50>/Constant'
     *  Gain: '<S66>/Slider Gain'
     */
    rtb_Add_c = rtb_Switch[2] - controller_template_P.SliderGain_Gain *
      controller_template_P.Constant_Value_c;

    /* Gain: '<S67>/Slider Gain' incorporates:
     *  Constant: '<S50>/Constant1'
     */
    rtb_SliderGain_n4 = controller_template_P.SliderGain_Gain_b *
      controller_template_P.Constant1_Value_f;

    /* MATLAB Function: '<S50>/MATLAB Function' */
    controller_templ_MATLABFunction(rtb_Add_c, rtb_SliderGain_n4,
      &controller_template_B.sf_MATLABFunction_e,
      &controller_template_DWork.sf_MATLABFunction_e);

    /* Saturate: '<S50>/Saturation3' */
    rtb_Saturation3_o = controller_template_B.sf_MATLABFunction_e.y >=
      controller_template_P.Saturation3_UpperSat_j ?
      controller_template_P.Saturation3_UpperSat_j :
      controller_template_B.sf_MATLABFunction_e.y <=
      controller_template_P.Saturation3_LowerSat_l ?
      controller_template_P.Saturation3_LowerSat_l :
      controller_template_B.sf_MATLABFunction_e.y;

    /* Switch: '<S46>/SwitchControl' incorporates:
     *  Constant: '<S46>/Constant'
     */
    if (controller_template_P.Constant_Value_lwi >
        controller_template_P.SwitchControl_Threshold) {
      controller_template_B.SwitchControl = rtb_Saturation3_o;
    } else {
      /* Sum: '<S45>/Add' */
      temp_idx = rtb_Switch[2] - controller_template_B.x_ref;

      /* Saturate: '<S45>/Saturation3' */
      controller_template_B.SwitchControl = temp_idx >=
        controller_template_P.Saturation3_UpperSat ?
        controller_template_P.Saturation3_UpperSat : temp_idx <=
        controller_template_P.Saturation3_LowerSat ?
        controller_template_P.Saturation3_LowerSat : temp_idx;
    }

    /* End of Switch: '<S46>/SwitchControl' */

    /* Saturate: '<S31>/Saturation2' */
    rtb_SliderGain_c = rtb_Switch[3] >=
      controller_template_P.Saturation2_UpperSat ?
      controller_template_P.Saturation2_UpperSat : rtb_Switch[3] <=
      controller_template_P.Saturation2_LowerSat ?
      controller_template_P.Saturation2_LowerSat : rtb_Switch[3];

    /* RateTransition: '<S44>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      controller_template_B.RateTransition[0] = rtb_Saturation2_l;
      controller_template_B.RateTransition[1] = rtb_UnitDelay_g;
      controller_template_B.RateTransition[2] =
        controller_template_B.SwitchControl;
      controller_template_B.RateTransition[3] = rtb_SliderGain_c;

      /* UnitDelay: '<S44>/Unit Delay2' */
      controller_template_B.UnitDelay2 =
        controller_template_DWork.UnitDelay2_DSTATE_c;
    }

    /* End of RateTransition: '<S44>/Rate Transition' */

    /* MATLAB Function: '<S55>/MATLAB Function' */
    controller_template_DWork.sfEvent_ac = CALL_EVENT;

    /* Switch: '<S55>/Switch' incorporates:
     *  Constant: '<S55>/Constant'
     *  Constant: '<S55>/Constant2'
     *  MATLAB Function: '<S55>/MATLAB Function'
     */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/PitchPropagate/MATLAB Function': '<S56>:1' */
    /* '<S56>:1:4' */
    if (controller_template_B.RateTransition[2] != 0.0) {
      for (i = 0; i < 4; i++) {
        I_1[i << 2] = controller_template_P.Constant_Value[(i << 2)];
        I_1[1 + (i << 2)] = controller_template_P.Constant_Value[(i << 2) + 1];
        I_1[2 + (i << 2)] = controller_template_P.Constant_Value[(i << 2) + 2];
        I_1[3 + (i << 2)] = controller_template_P.Constant_Value[(i << 2) + 3];
      }
    } else {
      for (i = 0; i < 4; i++) {
        I_1[i << 2] = controller_template_P.Constant2_Value[(i << 2)];
        I_1[1 + (i << 2)] = controller_template_P.Constant2_Value[(i << 2) + 1];
        I_1[2 + (i << 2)] = controller_template_P.Constant2_Value[(i << 2) + 2];
        I_1[3 + (i << 2)] = controller_template_P.Constant2_Value[(i << 2) + 3];
      }
    }

    /* End of Switch: '<S55>/Switch' */

    /* Switch: '<S55>/Switch1' incorporates:
     *  Constant: '<S55>/Constant1'
     *  Constant: '<S55>/Constant3'
     *  MATLAB Function: '<S55>/MATLAB Function'
     */
    if (controller_template_B.RateTransition[2] != 0.0) {
      for (i = 0; i < 2; i++) {
        tmp[i << 2] = controller_template_P.Constant1_Value[(i << 2)];
        tmp[1 + (i << 2)] = controller_template_P.Constant1_Value[(i << 2) + 1];
        tmp[2 + (i << 2)] = controller_template_P.Constant1_Value[(i << 2) + 2];
        tmp[3 + (i << 2)] = controller_template_P.Constant1_Value[(i << 2) + 3];
      }
    } else {
      for (i = 0; i < 2; i++) {
        tmp[i << 2] = controller_template_P.Constant3_Value[(i << 2)];
        tmp[1 + (i << 2)] = controller_template_P.Constant3_Value[(i << 2) + 1];
        tmp[2 + (i << 2)] = controller_template_P.Constant3_Value[(i << 2) + 2];
        tmp[3 + (i << 2)] = controller_template_P.Constant3_Value[(i << 2) + 3];
      }
    }

    /* End of Switch: '<S55>/Switch1' */

    /* MATLAB Function: '<S55>/MATLAB Function' */
    for (i = 0; i < 4; i++) {
      cos_yaw = I_1[i + 12] * controller_template_B.RateTransition[3] + (I_1[i +
        8] * controller_template_B.RateTransition[2] + (I_1[i + 4] *
        controller_template_B.RateTransition[1] + I_1[i] *
        controller_template_B.RateTransition[0]));
      rtb_Switch_0[i] = cos_yaw;
    }

    for (i = 0; i < 4; i++) {
      tmp_0[i] = tmp[i + 4] * 0.0 + tmp[i] * controller_template_B.UnitDelay2;
    }

    controller_template_B.y_i[0] = rtb_Switch_0[0] + tmp_0[0];
    controller_template_B.y_i[1] = rtb_Switch_0[1] + tmp_0[1];
    controller_template_B.y_i[2] = rtb_Switch_0[2] + tmp_0[2];
    controller_template_B.y_i[3] = rtb_Switch_0[3] + tmp_0[3];

    /* MATLAB Function: '<S44>/Ctrl_Xdir' incorporates:
     *  Constant: '<S44>/Constant'
     *  Constant: '<S44>/Constant1'
     *  Constant: '<S44>/Constant2'
     *  Constant: '<S44>/Constant4'
     *  Constant: '<S44>/Constat3'
     *  Saturate: '<S55>/Saturation'
     *  Saturate: '<S55>/Saturation1'
     *  Saturate: '<S55>/Saturation2'
     *  Saturate: '<S55>/Saturation3'
     */
    controller_template_DWork.sfEvent_cm = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/Ctrl_Xdir': '<S54>:1' */
    /* '<S54>:1:3' */
    rtb_SliderGain_l = 1.0;

    /* '<S54>:1:5' */
    /* '<S54>:1:6' */
    minreg = -1;

    /* '<S54>:1:7' */
    rtb_Switch[0] = (controller_template_B.y_i[0] >=
                     controller_template_P.Saturation_UpperSat_p ?
                     controller_template_P.Saturation_UpperSat_p :
                     controller_template_B.y_i[0] <=
                     controller_template_P.Saturation_LowerSat_c ?
                     controller_template_P.Saturation_LowerSat_c :
                     controller_template_B.y_i[0]) * 10000.0;
    rtb_Switch[1] = (controller_template_B.y_i[1] >=
                     controller_template_P.Saturation1_UpperSat_o ?
                     controller_template_P.Saturation1_UpperSat_o :
                     controller_template_B.y_i[1] <=
                     controller_template_P.Saturation1_LowerSat_d ?
                     controller_template_P.Saturation1_LowerSat_d :
                     controller_template_B.y_i[1]) * 10000.0;
    rtb_Switch[2] = (controller_template_B.y_i[2] >=
                     controller_template_P.Saturation3_UpperSat_c ?
                     controller_template_P.Saturation3_UpperSat_c :
                     controller_template_B.y_i[2] <=
                     controller_template_P.Saturation3_LowerSat_k ?
                     controller_template_P.Saturation3_LowerSat_k :
                     controller_template_B.y_i[2]) * 10000.0;
    rtb_Switch[3] = (controller_template_B.y_i[3] >=
                     controller_template_P.Saturation2_UpperSat_a ?
                     controller_template_P.Saturation2_UpperSat_a :
                     controller_template_B.y_i[3] <=
                     controller_template_P.Saturation2_LowerSat_h ?
                     controller_template_P.Saturation2_LowerSat_h :
                     controller_template_B.y_i[3]) * 10000.0;
    controller_template_round_e(rtb_Switch);
    rtb_Switch_0[0] = rtb_Switch[0];
    rtb_Switch_0[1] = rtb_Switch[1];
    rtb_Switch_0[2] = rtb_Switch[2];
    rtb_Switch_0[3] = rtb_Switch[3];
    controller_template_mrdivide_e(rtb_Switch_0, 10000.0, rtb_Switch);

    /* '<S54>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S54>:1:12' */
    memset((void *)(&controller_template_B.Hi[0]), 0, 4000U * sizeof(real_T));

    /* '<S54>:1:13' */
    memset((void *)(&controller_template_B.Ki[0]), 0, 1000U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S54>:1:16' */
    abspos = 1.0;

    /* '<S54>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 277) {
        /* '<S54>:1:17' */
        /* '<S54>:1:18' */
        sumViol = 0.0;

        /* '<S54>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S54>:1:23' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant4_Value[ireg]
             - 1; dz++) {
          /* '<S54>:1:23' */
          /* '<S54>:1:24' */
          /* '<S54>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) - 1] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) - 1];

          /* '<S54>:1:24' */
          /* '<S54>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) + 999] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 2368];

          /* '<S54>:1:24' */
          /* '<S54>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) + 1999] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 4737];

          /* '<S54>:1:24' */
          /* '<S54>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) + 2999] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 7106];

          /* '<S54>:1:24' */
          /* '<S54>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S54>:1:30' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value[ireg] -
             1; i++) {
          /* '<S54>:1:30' */
          /* '<S54>:1:31' */
          controller_template_B.Ki[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant1_Value_fy[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S54>:1:30' */
        }

        /* '<S54>:1:33' */
        abspos += controller_template_P.Constant4_Value[ireg];

        /* '<S54>:1:35' */
        /* '<S54>:1:36' */
        /* '<S54>:1:38' */
        /* '<S54>:1:40' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant4_Value[ireg]
             - 1; dz++) {
          /* '<S54>:1:40' */
          /* '<S54>:1:41' */
          yaw_rate_cmd_g = ((controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz)
                             - 1] * rtb_Switch[0] + controller_template_B.Hi
                             [(int32_T)(1.0 + (real_T)dz) + 999] * rtb_Switch[1])
                            + controller_template_B.Hi[(int32_T)(1.0 + (real_T)
            dz) + 1999] * rtb_Switch[2]) + controller_template_B.Hi[(int32_T)
            (1.0 + (real_T)dz) + 2999] * rtb_Switch[3];
          if (yaw_rate_cmd_g - controller_template_B.Ki[(int32_T)(1.0 + (real_T)
               dz) - 1] > 1.0E-8) {
            /* '<S54>:1:42' */
            /* '<S54>:1:43' */
            isinside = 0;

            /* '<S54>:1:44' */
            sumViol += yaw_rate_cmd_g - controller_template_B.Ki[(int32_T)(1.0 +
              (real_T)dz) - 1];
          }

          /* '<S54>:1:40' */
        }

        if (sumViol < rtb_SliderGain_l) {
          /* '<S54>:1:48' */
          /* '<S54>:1:49' */
          rtb_SliderGain_l = sumViol;

          /* '<S54>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S54>:1:53' */
          /* '<S54>:1:54' */
          rtb_pitch_cmd_b = (((controller_template_P.Constant2_Value_m[ireg +
                               277] * rtb_Switch[1] +
                               controller_template_P.Constant2_Value_m[ireg] *
                               rtb_Switch[0]) +
                              controller_template_P.Constant2_Value_m[ireg + 554]
                              * rtb_Switch[2]) +
                             controller_template_P.Constant2_Value_m[ireg + 831]
                             * rtb_Switch[3]) +
            controller_template_P.Constat3_Value[ireg];
          exitg = 1;
        } else {
          /* '<S54>:1:17' */
          ireg++;
        }
      } else {
        /* '<S54>:1:58' */
        /* '<S54>:1:59' */
        /* '<S54>:1:60' */
        rtb_pitch_cmd_b = (((controller_template_P.Constant2_Value_m[minreg +
                             277] * rtb_Switch[1] +
                             controller_template_P.Constant2_Value_m[minreg] *
                             rtb_Switch[0]) +
                            controller_template_P.Constant2_Value_m[minreg + 554]
                            * rtb_Switch[2]) +
                           controller_template_P.Constant2_Value_m[minreg + 831]
                           * rtb_Switch[3]) +
          controller_template_P.Constat3_Value[minreg];

        /* '<S54>:1:61' */
        flag_oob = 1;
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_gb = rtb_pitch_cmd_b;
    controller_template_B.flag_oob_ow = (real_T)flag_oob;

    /* End of MATLAB Function: '<S44>/Ctrl_Xdir' */

    /* RateTransition: '<S43>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      controller_template_B.RateTransition_l[0] = rtb_Saturation2_l;
      controller_template_B.RateTransition_l[1] = rtb_UnitDelay_g;
      controller_template_B.RateTransition_l[2] =
        controller_template_B.SwitchControl;
      controller_template_B.RateTransition_l[3] = rtb_SliderGain_c;

      /* UnitDelay: '<S43>/Unit Delay2' */
      controller_template_B.UnitDelay2_p =
        controller_template_DWork.UnitDelay2_DSTATE_m;
    }

    /* End of RateTransition: '<S43>/Rate Transition' */

    /* MATLAB Function: '<S52>/MATLAB Function' incorporates:
     *  Constant: '<S52>/Constant'
     *  Constant: '<S52>/Constant1'
     */
    controller_template_DWork.sfEvent_kd = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/PitchPropagateFF/MATLAB Function': '<S53>:1' */
    /* '<S53>:1:4' */
    for (i = 0; i < 4; i++) {
      cos_yaw = controller_template_P.Constant_Value_m[i + 12] *
        controller_template_B.RateTransition_l[3] +
        (controller_template_P.Constant_Value_m[i + 8] *
         controller_template_B.RateTransition_l[2] +
         (controller_template_P.Constant_Value_m[i + 4] *
          controller_template_B.RateTransition_l[1] +
          controller_template_P.Constant_Value_m[i] *
          controller_template_B.RateTransition_l[0]));
      rtb_Switch_0[i] = cos_yaw;
    }

    for (i = 0; i < 4; i++) {
      tmp_0[i] = controller_template_P.Constant1_Value_a[i + 4] * 0.0 +
        controller_template_P.Constant1_Value_a[i] *
        controller_template_B.UnitDelay2_p;
    }

    controller_template_B.y_o[0] = rtb_Switch_0[0] + tmp_0[0];
    controller_template_B.y_o[1] = rtb_Switch_0[1] + tmp_0[1];
    controller_template_B.y_o[2] = rtb_Switch_0[2] + tmp_0[2];
    controller_template_B.y_o[3] = rtb_Switch_0[3] + tmp_0[3];

    /* End of MATLAB Function: '<S52>/MATLAB Function' */

    /* MATLAB Function: '<S43>/Ctrl_Xdir' incorporates:
     *  Constant: '<S43>/Constant5'
     *  Constant: '<S43>/Constant6'
     *  Constant: '<S43>/Constant7'
     *  Constant: '<S43>/Constant8'
     *  Constant: '<S43>/Constant9'
     *  Saturate: '<S52>/Saturation'
     *  Saturate: '<S52>/Saturation1'
     *  Saturate: '<S52>/Saturation2'
     *  Saturate: '<S52>/Saturation3'
     */
    controller_template_DWork.sfEvent_cr = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/Ctrl_Xdir': '<S51>:1' */
    /* '<S51>:1:3' */
    rtb_SliderGain_l = 1.0;

    /* '<S51>:1:5' */
    /* '<S51>:1:6' */
    minreg = -1;

    /* '<S51>:1:7' */
    rtb_Switch[0] = (controller_template_B.y_o[0] >=
                     controller_template_P.Saturation_UpperSat_k ?
                     controller_template_P.Saturation_UpperSat_k :
                     controller_template_B.y_o[0] <=
                     controller_template_P.Saturation_LowerSat_e ?
                     controller_template_P.Saturation_LowerSat_e :
                     controller_template_B.y_o[0]) * 10000.0;
    rtb_Switch[1] = (controller_template_B.y_o[1] >=
                     controller_template_P.Saturation1_UpperSat_p ?
                     controller_template_P.Saturation1_UpperSat_p :
                     controller_template_B.y_o[1] <=
                     controller_template_P.Saturation1_LowerSat_l ?
                     controller_template_P.Saturation1_LowerSat_l :
                     controller_template_B.y_o[1]) * 10000.0;
    rtb_Switch[2] = (controller_template_B.y_o[2] >=
                     controller_template_P.Saturation3_UpperSat_l ?
                     controller_template_P.Saturation3_UpperSat_l :
                     controller_template_B.y_o[2] <=
                     controller_template_P.Saturation3_LowerSat_lj ?
                     controller_template_P.Saturation3_LowerSat_lj :
                     controller_template_B.y_o[2]) * 10000.0;
    rtb_Switch[3] = (controller_template_B.y_o[3] >=
                     controller_template_P.Saturation2_UpperSat_k ?
                     controller_template_P.Saturation2_UpperSat_k :
                     controller_template_B.y_o[3] <=
                     controller_template_P.Saturation2_LowerSat_c ?
                     controller_template_P.Saturation2_LowerSat_c :
                     controller_template_B.y_o[3]) * 10000.0;
    controller_template_round(rtb_Switch);
    rtb_Switch_0[0] = rtb_Switch[0];
    rtb_Switch_0[1] = rtb_Switch[1];
    rtb_Switch_0[2] = rtb_Switch[2];
    rtb_Switch_0[3] = rtb_Switch[3];
    controller_template_mrdivide(rtb_Switch_0, 10000.0, rtb_Switch);

    /* '<S51>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S51>:1:12' */
    memset((void *)(&controller_template_B.Hi[0]), 0, 4000U * sizeof(real_T));

    /* '<S51>:1:13' */
    memset((void *)(&controller_template_B.Ki[0]), 0, 1000U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S51>:1:16' */
    abspos = 1.0;

    /* '<S51>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 164) {
        /* '<S51>:1:17' */
        /* '<S51>:1:18' */
        sumViol = 0.0;

        /* '<S51>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S51>:1:23' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant9_Value[ireg]
             - 1; dz++) {
          /* '<S51>:1:23' */
          /* '<S51>:1:24' */
          /* '<S51>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) - 1] =
            controller_template_P.Constant5_Value[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) - 1];

          /* '<S51>:1:24' */
          /* '<S51>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) + 999] =
            controller_template_P.Constant5_Value[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 1414];

          /* '<S51>:1:24' */
          /* '<S51>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) + 1999] =
            controller_template_P.Constant5_Value[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 2829];

          /* '<S51>:1:24' */
          /* '<S51>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) + 2999] =
            controller_template_P.Constant5_Value[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 4244];

          /* '<S51>:1:24' */
          /* '<S51>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S51>:1:30' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant9_Value[ireg] -
             1; i++) {
          /* '<S51>:1:30' */
          /* '<S51>:1:31' */
          controller_template_B.Ki[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant6_Value[(int32_T)(((1.0 + (real_T)i) +
            abspos) - 1.0) - 1];

          /* '<S51>:1:30' */
        }

        /* '<S51>:1:33' */
        abspos += controller_template_P.Constant9_Value[ireg];

        /* '<S51>:1:35' */
        /* '<S51>:1:36' */
        /* '<S51>:1:38' */
        /* '<S51>:1:40' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant9_Value[ireg]
             - 1; dz++) {
          /* '<S51>:1:40' */
          /* '<S51>:1:41' */
          yaw_rate_cmd_g = ((controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz)
                             - 1] * rtb_Switch[0] + controller_template_B.Hi
                             [(int32_T)(1.0 + (real_T)dz) + 999] * rtb_Switch[1])
                            + controller_template_B.Hi[(int32_T)(1.0 + (real_T)
            dz) + 1999] * rtb_Switch[2]) + controller_template_B.Hi[(int32_T)
            (1.0 + (real_T)dz) + 2999] * rtb_Switch[3];
          if (yaw_rate_cmd_g - controller_template_B.Ki[(int32_T)(1.0 + (real_T)
               dz) - 1] > 1.0E-8) {
            /* '<S51>:1:42' */
            /* '<S51>:1:43' */
            isinside = 0;

            /* '<S51>:1:44' */
            sumViol += yaw_rate_cmd_g - controller_template_B.Ki[(int32_T)(1.0 +
              (real_T)dz) - 1];
          }

          /* '<S51>:1:40' */
        }

        if (sumViol < rtb_SliderGain_l) {
          /* '<S51>:1:48' */
          /* '<S51>:1:49' */
          rtb_SliderGain_l = sumViol;

          /* '<S51>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S51>:1:53' */
          /* '<S51>:1:54' */
          U = (((controller_template_P.Constant7_Value[ireg + 164] * rtb_Switch
                 [1] + controller_template_P.Constant7_Value[ireg] * rtb_Switch
                 [0]) + controller_template_P.Constant7_Value[ireg + 328] *
                rtb_Switch[2]) + controller_template_P.Constant7_Value[ireg +
               492] * rtb_Switch[3]) +
            controller_template_P.Constant8_Value[ireg];
          exitg = 1;
        } else {
          /* '<S51>:1:17' */
          ireg++;
        }
      } else {
        /* '<S51>:1:58' */
        /* '<S51>:1:59' */
        /* '<S51>:1:60' */
        U = (((controller_template_P.Constant7_Value[minreg + 164] * rtb_Switch
               [1] + controller_template_P.Constant7_Value[minreg] * rtb_Switch
               [0]) + controller_template_P.Constant7_Value[minreg + 328] *
              rtb_Switch[2]) + controller_template_P.Constant7_Value[minreg +
             492] * rtb_Switch[3]) +
          controller_template_P.Constant8_Value[minreg];

        /* '<S51>:1:61' */
        flag_oob = 1;
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_a = U;
    controller_template_B.flag_oob_l1 = (real_T)flag_oob;

    /* End of MATLAB Function: '<S43>/Ctrl_Xdir' */

    /* Switch: '<S47>/SwitchControl' incorporates:
     *  Constant: '<S47>/Constant'
     */
    if (controller_template_P.Constant_Value_j >
        controller_template_P.SwitchControl_Threshold_a) {
      temp_idx = controller_template_B.U_gb;
    } else {
      temp_idx = controller_template_B.U_a;
    }

    /* End of Switch: '<S47>/SwitchControl' */

    /* Gain: '<S48>/Gain' incorporates:
     *  Saturate: '<S31>/Saturation4'
     *  Sum: '<S48>/Sum'
     *  Sum: '<S48>/Sum1'
     *  UnitDelay: '<S48>/Unit Delay'
     *  UnitDelay: '<S48>/Unit Delay2'
     */
    controller_template_B.Gain_pk = ((temp_idx >=
      controller_template_P.Saturation4_UpperSat ?
      controller_template_P.Saturation4_UpperSat : temp_idx <=
      controller_template_P.Saturation4_LowerSat ?
      controller_template_P.Saturation4_LowerSat : temp_idx) +
      (controller_template_DWork.UnitDelay2_DSTATE_d +
       controller_template_DWork.UnitDelay_DSTATE_jv)) *
      controller_template_P.Gain_Gain;

    /* Gain: '<S29>/Gain' incorporates:
     *  Constant: '<S29>/Constant'
     *  Gain: '<S38>/Slider Gain'
     */
    sin_yaw = controller_template_P.SliderGain_Gain_ba *
      controller_template_P.Constant_Value_f * controller_template_P.Gain_Gain_j;

    /* Gain: '<S29>/Gain1' incorporates:
     *  Constant: '<S29>/Constant1'
     *  Gain: '<S39>/Slider Gain'
     */
    cos_yaw = controller_template_P.SliderGain_Gain_k *
      controller_template_P.Constant1_Value_m * controller_template_P.Gain1_Gain;

    /* MATLAB Function: '<S29>/MATLAB Function' */
    controller_template_DWork.sfEvent_fp = CALL_EVENT;

    /* Gain: '<S40>/Slider Gain' incorporates:
     *  Constant: '<S29>/Constant2'
     */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/MATLAB Function': '<S36>:1' */
    /* '<S36>:1:5' */
    temp_idx = controller_template_P.SliderGain_Gain_f *
      controller_template_P.Constant2_Value_h;

    /* MATLAB Function: '<S29>/MATLAB Function' incorporates:
     *  Constant: '<S29>/Constant'
     *  Gain: '<S37>/Slider Gain'
     */
    rtb_SliderGain_c = temp_idx <= 1.0 ? temp_idx : 1.0;

    /* '<S36>:1:7' */
    controller_template_B.pitch_cmd_out = rtb_SliderGain_c * cos_yaw +
      controller_template_B.Gain_pk;
    if ((rtb_Saturation3 == 0.0) && (controller_template_B.pitch_rot_i <
         -sin_yaw)) {
      /* '<S36>:1:9' */
      /* '<S36>:1:10' */
      controller_template_B.pitch_cmd_out =
        controller_template_P.SliderGain_Gain_g *
        controller_template_P.Constant_Value_f * fabs
        (controller_template_B.pitch_rot_i + sin_yaw) +
        controller_template_B.pitch_cmd_out;

      /* '<S36>:1:11' */
      controller_template_B.pitch_cmd_out = (1.0 - rtb_SliderGain_c) * cos_yaw +
        controller_template_B.pitch_cmd_out;
    }

    /* Switch: '<S28>/SwitchControl' incorporates:
     *  Constant: '<S28>/Constant'
     */
    if (controller_template_P.Constant_Value_ki >
        controller_template_P.SwitchControl_Threshold_g) {
      rtb_SliderGain_c = controller_template_B.Gain_pk;
    } else {
      rtb_SliderGain_c = controller_template_B.pitch_cmd_out;
    }

    /* End of Switch: '<S28>/SwitchControl' */

    /* Product: '<S11>/Product' incorporates:
     *  Constant: '<S11>/gravity'
     */
    rtb_SliderGain_h = controller_template_P.gravity_Value *
      controller_template_B.DataTypeConversion[29];

    /* Sum: '<S11>/Sum' */
    rtb_pitch_cmd_b = rtb_SliderGain_c - rtb_bias_W[0];

    /* Gain: '<S32>/Gain' incorporates:
     *  Constant: '<S32>/Constant1'
     *  Gain: '<S74>/Slider Gain'
     */
    sin_yaw = controller_template_P.SliderGain_Gain_j *
      controller_template_P.Constant1_Value_d *
      controller_template_P.Gain_Gain_f;

    /* Saturate: '<S32>/Saturation' */
    rtb_SliderGain_c = controller_template_B.roll_rot_f >=
      controller_template_P.Saturation_UpperSat_h ?
      controller_template_P.Saturation_UpperSat_h :
      controller_template_B.roll_rot_f <=
      controller_template_P.Saturation_LowerSat_d ?
      controller_template_P.Saturation_LowerSat_d :
      controller_template_B.roll_rot_f;

    /* Saturate: '<S32>/Saturation1' */
    rtb_UnitDelay_g = controller_template_B.DataTypeConversion[9] >=
      controller_template_P.Saturation1_UpperSat_ou ?
      controller_template_P.Saturation1_UpperSat_ou :
      controller_template_B.DataTypeConversion[9] <=
      controller_template_P.Saturation1_LowerSat_c ?
      controller_template_P.Saturation1_LowerSat_c :
      controller_template_B.DataTypeConversion[9];

    /* Sum: '<S32>/Add' incorporates:
     *  Constant: '<S32>/Constant'
     *  Gain: '<S70>/Slider Gain'
     *  Gain: '<S71>/Slider Gain'
     *  Sum: '<S32>/Sum'
     */
    temp_idx = controller_template_B.DataTypeConversion[1] -
      (controller_template_P.SliderGain_Gain_gm * controller_template_B.y_ref +
       controller_template_P.SliderGain_Gain_be *
       controller_template_P.Constant_Value_g);

    /* Saturate: '<S32>/Saturation3' */
    controller_template_B.Saturation3 = temp_idx >=
      controller_template_P.Saturation3_UpperSat_n ?
      controller_template_P.Saturation3_UpperSat_n : temp_idx <=
      controller_template_P.Saturation3_LowerSat_c ?
      controller_template_P.Saturation3_LowerSat_c : temp_idx;

    /* Saturate: '<S32>/Saturation2' */
    rtb_Saturation2_l = controller_template_B.DataTypeConversion[4] >=
      controller_template_P.Saturation2_UpperSat_b ?
      controller_template_P.Saturation2_UpperSat_b :
      controller_template_B.DataTypeConversion[4] <=
      controller_template_P.Saturation2_LowerSat_hu ?
      controller_template_P.Saturation2_LowerSat_hu :
      controller_template_B.DataTypeConversion[4];

    /* Sum: '<S73>/Add' incorporates:
     *  Constant: '<S73>/Constant'
     *  Gain: '<S81>/Slider Gain'
     */
    rtb_Add_kj = controller_template_B.DataTypeConversion[0] -
      controller_template_P.SliderGain_Gain_p *
      controller_template_P.Constant_Value_k;

    /* Gain: '<S82>/Slider Gain' incorporates:
     *  Constant: '<S73>/Constant1'
     */
    rtb_SliderGain_j = controller_template_P.SliderGain_Gain_g3 *
      controller_template_P.Constant1_Value_dx;

    /* MATLAB Function: '<S73>/MATLAB Function' */
    controller_tem_MATLABFunction_l(rtb_Add_kj, rtb_SliderGain_j,
      &controller_template_B.sf_MATLABFunction_l5,
      &controller_template_DWork.sf_MATLABFunction_l5);

    /* Saturate: '<S73>/Saturation3' */
    cos_yaw = controller_template_B.sf_MATLABFunction_l5.y >=
      controller_template_P.Saturation3_UpperSat_lg ?
      controller_template_P.Saturation3_UpperSat_lg :
      controller_template_B.sf_MATLABFunction_l5.y <=
      controller_template_P.Saturation3_LowerSat_b ?
      controller_template_P.Saturation3_LowerSat_b :
      controller_template_B.sf_MATLABFunction_l5.y;

    /* RateTransition: '<S68>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      controller_template_B.RateTransition_i[0] = rtb_SliderGain_c;
      controller_template_B.RateTransition_i[1] = rtb_UnitDelay_g;
      controller_template_B.RateTransition_i[2] =
        controller_template_B.Saturation3;
      controller_template_B.RateTransition_i[3] = rtb_Saturation2_l;
      controller_template_B.RateTransition_i[4] = cos_yaw;

      /* UnitDelay: '<S68>/Unit Delay2' */
      controller_template_B.UnitDelay2_o =
        controller_template_DWork.UnitDelay2_DSTATE_l;
    }

    /* End of RateTransition: '<S68>/Rate Transition' */

    /* MATLAB Function: '<S76>/MATLAB Function' */
    controller_template_DWork.sfEvent_i = CALL_EVENT;

    /* MATLAB Function: '<S68>/Ctrl_Xdir' incorporates:
     *  Constant: '<S68>/Constant'
     *  Constant: '<S68>/Constant1'
     *  Constant: '<S68>/Constant2'
     *  Constant: '<S68>/Constant3'
     *  Constant: '<S68>/Constant4'
     *  Constant: '<S76>/Constant1'
     *  MATLAB Function: '<S76>/MATLAB Function'
     */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate/MATLAB Function': '<S77>:1' */
    /* '<S77>:1:4' */
    controller_template_DWork.sfEvent_cd = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S75>:1' */
    /* '<S75>:1:3' */
    rtb_SliderGain_l = 1.0;

    /* '<S75>:1:5' */
    /* '<S75>:1:6' */
    minreg = -1;

    /* '<S75>:1:7' */
    for (i = 0; i < 5; i++) {
      /* MATLAB Function: '<S76>/MATLAB Function' incorporates:
       *  Constant: '<S76>/Constant'
       *  Constant: '<S76>/Constant1'
       */
      X_0[i] = 0.0;
      for (ireg = 0; ireg < 5; ireg++) {
        X_0[i] += controller_template_P.Constant_Value_co[5 * ireg + i] *
          controller_template_B.RateTransition_i[ireg];
      }

      tmp_1[i] = 0.0;
      tmp_1[i] += controller_template_P.Constant1_Value_g[i] *
        controller_template_B.UnitDelay2_o;
      tmp_1[i] += controller_template_P.Constant1_Value_g[i + 5] * 0.0;

      /* MATLAB Function: '<S76>/MATLAB Function' incorporates:
       *  Constant: '<S76>/Constant1'
       */
      controller_template_B.y_a[i] = X_0[i] + tmp_1[i];
      X[i] = 10000.0 * controller_template_B.y_a[i];
    }

    controller_template_round_j(X);
    for (i = 0; i < 5; i++) {
      X_0[i] = X[i];
    }

    controller_template_mrdivide_j(X_0, 10000.0, X);

    /* '<S75>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S75>:1:12' */
    memset((void *)&Hi[0], 0, 500U * sizeof(real_T));

    /* '<S75>:1:13' */
    memset((void *)&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S75>:1:16' */
    abspos = 1.0;

    /* '<S75>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 318) {
        /* '<S75>:1:17' */
        /* '<S75>:1:18' */
        sumViol = 0.0;

        /* '<S75>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S75>:1:23' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; dz++) {
          /* '<S75>:1:23' */
          /* '<S75>:1:24' */
          for (i = 0; i < 5; i++) {
            /* '<S75>:1:24' */
            /* '<S75>:1:25' */
            Hi[((int32_T)(1.0 + (real_T)dz) + 100 * i) - 1] =
              controller_template_P.Constant_Value_ln[((int32_T)(((1.0 + (real_T)
              dz) + abspos) - 1.0) + 3361 * i) - 1];

            /* '<S75>:1:24' */
          }

          /* '<S75>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S75>:1:30' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; i++) {
          /* '<S75>:1:30' */
          /* '<S75>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant1_Value_j[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S75>:1:30' */
        }

        /* '<S75>:1:33' */
        abspos += controller_template_P.Constant4_Value_g[ireg];

        /* '<S75>:1:35' */
        /* '<S75>:1:36' */
        /* '<S75>:1:38' */
        /* '<S75>:1:40' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; dz++) {
          /* '<S75>:1:40' */
          /* '<S75>:1:41' */
          yaw_rate_cmd_g = 0.0;
          for (i = 0; i < 5; i++) {
            yaw_rate_cmd_g += Hi[((int32_T)(1.0 + (real_T)dz) + 100 * i) - 1] *
              X[i];
          }

          if (yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)dz) - 1] > 1.0E-8) {
            /* '<S75>:1:42' */
            /* '<S75>:1:43' */
            isinside = 0;

            /* '<S75>:1:44' */
            sumViol += yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)dz) - 1];
          }

          /* '<S75>:1:40' */
        }

        if (sumViol < rtb_SliderGain_l) {
          /* '<S75>:1:48' */
          /* '<S75>:1:49' */
          rtb_SliderGain_l = sumViol;

          /* '<S75>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S75>:1:53' */
          /* '<S75>:1:54' */
          sumViol = 0.0;
          for (i = 0; i < 5; i++) {
            sumViol += controller_template_P.Constant2_Value_j[318 * i + ireg] *
              X[i];
          }

          U_0 = sumViol + controller_template_P.Constant3_Value_o[ireg];
          exitg = 1;
        } else {
          /* '<S75>:1:17' */
          ireg++;
        }
      } else {
        /* '<S75>:1:58' */
        /* '<S75>:1:59' */
        /* '<S75>:1:60' */
        sumViol = 0.0;
        for (i = 0; i < 5; i++) {
          sumViol += controller_template_P.Constant2_Value_j[318 * i + minreg] *
            X[i];
        }

        U_0 = sumViol + controller_template_P.Constant3_Value_o[minreg];

        /* '<S75>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_p = U_0;
    controller_template_B.flag_oob_o = (real_T)flag_oob;

    /* End of MATLAB Function: '<S68>/Ctrl_Xdir' */

    /* MATLAB Function: '<S72>/MATLAB Function' incorporates:
     *  Constant: '<S72>/Constant'
     *  Gain: '<S79>/Slider Gain'
     */
    controller_template_DWork.sfEvent_ab = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Subsystem/MATLAB Function': '<S78>:1' */
    /* '<S78>:1:4' */
    controller_template_B.input_out = controller_template_B.U_p;
    if (cos_yaw >= 0.0) {
      /* '<S78>:1:6' */
      /* '<S78>:1:7' */
      controller_template_B.input_out = controller_template_P.SliderGain_Gain_m *
        controller_template_P.Constant_Value_o * controller_template_B.U_p;
    }

    /* End of MATLAB Function: '<S72>/MATLAB Function' */

    /* Gain: '<S69>/Gain' incorporates:
     *  Saturate: '<S32>/Saturation4'
     *  Sum: '<S69>/Sum'
     *  Sum: '<S69>/Sum1'
     *  UnitDelay: '<S69>/Unit Delay'
     *  UnitDelay: '<S69>/Unit Delay2'
     */
    controller_template_B.Gain_f = ((controller_template_B.input_out >=
      controller_template_P.Saturation4_UpperSat_i ?
      controller_template_P.Saturation4_UpperSat_i :
      controller_template_B.input_out <=
      controller_template_P.Saturation4_LowerSat_h ?
      controller_template_P.Saturation4_LowerSat_h :
      controller_template_B.input_out) +
      (controller_template_DWork.UnitDelay2_DSTATE_k +
       controller_template_DWork.UnitDelay_DSTATE_f)) *
      controller_template_P.Gain_Gain_fn;

    /* Sum: '<S11>/Sum1' incorporates:
     *  Sum: '<S32>/Sum1'
     */
    rtb_SliderGain_m = (sin_yaw + controller_template_B.Gain_f) - rtb_bias_W[1];

    /* Sum: '<S35>/Add' */
    temp_idx = controller_template_B.DataTypeConversion[2] -
      controller_template_B.z_ref;

    /* Saturate: '<S35>/Saturation1' */
    controller_template_B.Saturation1 = temp_idx >=
      controller_template_P.Saturation1_UpperSat_d ?
      controller_template_P.Saturation1_UpperSat_d : temp_idx <=
      controller_template_P.Saturation1_LowerSat_n ?
      controller_template_P.Saturation1_LowerSat_n : temp_idx;

    /* Saturate: '<S35>/Saturation' */
    rtb_SliderGain_c = controller_template_B.DataTypeConversion[5] >=
      controller_template_P.Saturation_UpperSat_d ?
      controller_template_P.Saturation_UpperSat_d :
      controller_template_B.DataTypeConversion[5] <=
      controller_template_P.Saturation_LowerSat_b ?
      controller_template_P.Saturation_LowerSat_b :
      controller_template_B.DataTypeConversion[5];

    /* Sum: '<S101>/Add' incorporates:
     *  Constant: '<S101>/Constant'
     *  Gain: '<S106>/Slider Gain'
     */
    rtb_Add_e = controller_template_B.DataTypeConversion[0] -
      controller_template_P.SliderGain_Gain_d *
      controller_template_P.Constant_Value_fz;

    /* Gain: '<S107>/Slider Gain' incorporates:
     *  Constant: '<S101>/Constant1'
     */
    rtb_SliderGain_kp = controller_template_P.SliderGain_Gain_ds *
      controller_template_P.Constant1_Value_l;

    /* MATLAB Function: '<S101>/MATLAB Function' */
    controller_tem_MATLABFunction_l(rtb_Add_e, rtb_SliderGain_kp,
      &controller_template_B.sf_MATLABFunction_c,
      &controller_template_DWork.sf_MATLABFunction_c);

    /* Saturate: '<S101>/Saturation3' */
    sin_yaw = controller_template_B.sf_MATLABFunction_c.y >=
      controller_template_P.Saturation3_UpperSat_nh ?
      controller_template_P.Saturation3_UpperSat_nh :
      controller_template_B.sf_MATLABFunction_c.y <=
      controller_template_P.Saturation3_LowerSat_e ?
      controller_template_P.Saturation3_LowerSat_e :
      controller_template_B.sf_MATLABFunction_c.y;

    /* RateTransition: '<S97>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      controller_template_B.RateTransition_j[0] =
        controller_template_B.Saturation1;
      controller_template_B.RateTransition_j[1] = rtb_SliderGain_c;
      controller_template_B.RateTransition_j[2] = sin_yaw;
    }

    /* End of RateTransition: '<S97>/Rate Transition' */

    /* MATLAB Function: '<S97>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_k0 = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S102>:1' */
    /* '<S102>:1:3' */
    rtb_SliderGain_l = 1.0;

    /* '<S102>:1:5' */
    /* '<S102>:1:6' */
    minreg = -1;

    /* '<S102>:1:7' */
    rtb_SliderGain_c = 10000.0 * controller_template_B.RateTransition_j[0];
    U = 10000.0 * controller_template_B.RateTransition_j[1];
    cos_yaw = 10000.0 * controller_template_B.RateTransition_j[2];
    temp_idx = rtb_SliderGain_c;
    if (!(fabs(rtb_SliderGain_c) > 4.503599627370496E+15)) {
      if (rtb_SliderGain_c >= 0.5) {
        temp_idx = floor(rtb_SliderGain_c + 0.5);
      } else if (rtb_SliderGain_c > -0.5) {
        temp_idx = -0.0;
      } else {
        temp_idx = ceil(rtb_SliderGain_c - 0.5);
      }
    }

    /* End of Outputs for SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    rtb_SliderGain_c = temp_idx;

    /* Outputs for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* MATLAB Function: '<S97>/Ctrl_Xdir' */
    temp_idx = U;
    if (!(fabs(U) > 4.503599627370496E+15)) {
      if (U >= 0.5) {
        temp_idx = floor(U + 0.5);
      } else if (U > -0.5) {
        temp_idx = -0.0;
      } else {
        temp_idx = ceil(U - 0.5);
      }
    }

    /* End of Outputs for SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    U = temp_idx;

    /* Outputs for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* MATLAB Function: '<S97>/Ctrl_Xdir' incorporates:
     *  Constant: '<S97>/Constant'
     *  Constant: '<S97>/Constant1'
     *  Constant: '<S97>/Constant2'
     *  Constant: '<S97>/Constant3'
     *  Constant: '<S97>/Constant4'
     */
    temp_idx = cos_yaw;
    if (!(fabs(cos_yaw) > 4.503599627370496E+15)) {
      if (cos_yaw >= 0.5) {
        temp_idx = floor(cos_yaw + 0.5);
      } else if (cos_yaw > -0.5) {
        temp_idx = -0.0;
      } else {
        temp_idx = ceil(cos_yaw - 0.5);
      }
    }

    rtb_SliderGain_c /= 10000.0;
    U /= 10000.0;
    temp_idx /= 10000.0;

    /* '<S102>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S102>:1:12' */
    memset((void *)&Hi_0[0], 0, 300U * sizeof(real_T));

    /* '<S102>:1:13' */
    memset((void *)&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S102>:1:16' */
    abspos = 1.0;

    /* '<S102>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 30) {
        /* '<S102>:1:17' */
        /* '<S102>:1:18' */
        sumViol = 0.0;

        /* '<S102>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S102>:1:23' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; dz++) {
          /* '<S102>:1:23' */
          /* '<S102>:1:24' */
          /* '<S102>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)dz) - 1] =
            controller_template_P.Constant_Value_b[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) - 1];

          /* '<S102>:1:24' */
          /* '<S102>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)dz) + 99] =
            controller_template_P.Constant_Value_b[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 207];

          /* '<S102>:1:24' */
          /* '<S102>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)dz) + 199] =
            controller_template_P.Constant_Value_b[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 415];

          /* '<S102>:1:24' */
          /* '<S102>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S102>:1:30' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; i++) {
          /* '<S102>:1:30' */
          /* '<S102>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant1_Value_li[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S102>:1:30' */
        }

        /* '<S102>:1:33' */
        abspos += controller_template_P.Constant4_Value_a[ireg];

        /* '<S102>:1:35' */
        /* '<S102>:1:36' */
        /* '<S102>:1:38' */
        /* '<S102>:1:40' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; dz++) {
          /* '<S102>:1:40' */
          /* '<S102>:1:41' */
          yaw_rate_cmd_g = (Hi_0[(int32_T)(1.0 + (real_T)dz) - 1] *
                            rtb_SliderGain_c + Hi_0[(int32_T)(1.0 + (real_T)dz)
                            + 99] * U) + Hi_0[(int32_T)(1.0 + (real_T)dz) + 199]
            * temp_idx;
          if (yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)dz) - 1] > 1.0E-8) {
            /* '<S102>:1:42' */
            /* '<S102>:1:43' */
            isinside = 0;

            /* '<S102>:1:44' */
            sumViol += yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)dz) - 1];
          }

          /* '<S102>:1:40' */
        }

        if (sumViol < rtb_SliderGain_l) {
          /* '<S102>:1:48' */
          /* '<S102>:1:49' */
          rtb_SliderGain_l = sumViol;

          /* '<S102>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S102>:1:53' */
          /* '<S102>:1:54' */
          U_1 = ((controller_template_P.Constant2_Value_g[ireg + 30] * U +
                  controller_template_P.Constant2_Value_g[ireg] *
                  rtb_SliderGain_c) +
                 controller_template_P.Constant2_Value_g[ireg + 60] * temp_idx)
            + controller_template_P.Constant3_Value_m[ireg];
          exitg = 1;
        } else {
          /* '<S102>:1:17' */
          ireg++;
        }
      } else {
        /* '<S102>:1:58' */
        /* '<S102>:1:59' */
        /* '<S102>:1:60' */
        U_1 = ((controller_template_P.Constant2_Value_g[minreg + 30] * U +
                controller_template_P.Constant2_Value_g[minreg] *
                rtb_SliderGain_c) +
               controller_template_P.Constant2_Value_g[minreg + 60] * temp_idx)
          + controller_template_P.Constant3_Value_m[minreg];

        /* '<S102>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U = U_1;
    controller_template_B.flag_oob = (real_T)flag_oob;

    /* MATLAB Function: '<S100>/MATLAB Function' incorporates:
     *  Constant: '<S100>/Constant'
     *  Gain: '<S104>/Slider Gain'
     */
    controller_template_DWork.sfEvent_jj = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Subsystem/MATLAB Function': '<S103>:1' */
    /* '<S103>:1:4' */
    controller_template_B.u_thrust_out = controller_template_B.U;
    if ((sin_yaw > 0.0) && (controller_template_B.Saturation1 < 0.0)) {
      /* '<S103>:1:6' */
      /* '<S103>:1:7' */
      controller_template_B.u_thrust_out =
        controller_template_P.SliderGain_Gain_mb *
        controller_template_P.Constant_Value_n * controller_template_B.U;
    }

    /* End of MATLAB Function: '<S100>/MATLAB Function' */

    /* Gain: '<S99>/Slider Gain' */
    temp_idx = controller_template_P.SliderGain_Gain_c *
      controller_template_B.u_thrust_out;

    /* Gain: '<S98>/Gain' incorporates:
     *  Saturate: '<S35>/Saturation2'
     *  Sum: '<S98>/Sum'
     *  Sum: '<S98>/Sum1'
     *  UnitDelay: '<S98>/Unit Delay'
     *  UnitDelay: '<S98>/Unit Delay2'
     */
    controller_template_B.Gain_i = ((temp_idx >=
      controller_template_P.Saturation2_UpperSat_kw ?
      controller_template_P.Saturation2_UpperSat_kw : temp_idx <=
      controller_template_P.Saturation2_LowerSat_j ?
      controller_template_P.Saturation2_LowerSat_j : temp_idx) +
      (controller_template_DWork.UnitDelay2_DSTATE_b +
       controller_template_DWork.UnitDelay_DSTATE_fw)) *
      controller_template_P.Gain_Gain_p;

    /* MATLAB Function: '<S33>/MATLAB Function' */
    controller_template_DWork.sfEvent_g = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/MATLAB Function': '<S84>:1' */
    /* '<S84>:1:4' */
    controller_template_B.psi_prime_l =
      controller_template_B.sf_discretekalmanfilter.state_est[0];

    /* Gain: '<S89>/Slider Gain' incorporates:
     *  Constant: '<S33>/Constant1'
     */
    /*   */
    /*  if((abs(psi_meas - psi_prev)>= (pi-0.1))&&(psi_prev > 0)) */
    /*      psi_prime = pi + abs(pi - abs(psi_meas)); */
    /*  end */
    /*   */
    /*  if((abs(psi_meas - psi_prev)>= (pi-0.1))&&(psi_prev < 0)) */
    /*      psi_prime = -pi - abs(pi - abs(psi_meas)); */
    /*  end */
    /*  if((psi_meas>=((45)/180)*pi)&&(psi_meas<=(pi))) */
    /*      psi_prime = (psi_meas - pi) -(180/180)*pi; */
    /*  end */
    sin_yaw = controller_template_P.SliderGain_Gain_a *
      controller_template_P.Constant1_Value_k;

    /* MATLAB Function: '<S33>/MATLAB Function1' incorporates:
     *  Constant: '<S33>/Constant2'
     *  Gain: '<S90>/Slider Gain'
     */
    controller_template_DWork.sfEvent_d = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/MATLAB Function1': '<S85>:1' */
    /* '<S85>:1:4' */
    controller_template_B.psi_out = controller_template_B.psi_prime_l;
    if (sin_yaw - 0.0 <= controller_template_P.SliderGain_Gain_pq *
        controller_template_P.Constant2_Value_l) {
      /* '<S85>:1:6' */
      /* '<S85>:1:7' */
      controller_template_B.psi_out = rtb_yaw_ref;
    }

    /* '<S85>:1:10' */
    controller_template_B.delta_x = sin_yaw - 0.0;

    /* End of MATLAB Function: '<S33>/MATLAB Function1' */

    /* Sum: '<S33>/Sum' incorporates:
     *  Constant: '<S33>/Constant'
     *  Gain: '<S87>/Slider Gain'
     *  Gain: '<S88>/Slider Gain'
     */
    controller_template_B.Sum_b = controller_template_P.SliderGain_Gain_ai *
      rtb_yaw_ref + controller_template_P.SliderGain_Gain_jt *
      controller_template_P.Constant_Value_fv;

    /* MATLAB Function: '<S92>/MATLAB Function' */
    controller_template_DWork.sfEvent_l = CALL_EVENT;

    /* Sum: '<S33>/Add' */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate/MATLAB Function': '<S93>:1' */
    /* '<S93>:1:4' */
    temp_idx = controller_template_B.psi_out - controller_template_B.Sum_b;

    /* MATLAB Function: '<S92>/MATLAB Function' incorporates:
     *  Constant: '<S92>/Constant'
     *  Constant: '<S92>/Constant1'
     *  Saturate: '<S33>/Saturation'
     *  UnitDelay: '<S83>/Unit Delay2'
     */
    controller_template_B.y = (temp_idx >=
      controller_template_P.Saturation_UpperSat_o ?
      controller_template_P.Saturation_UpperSat_o : temp_idx <=
      controller_template_P.Saturation_LowerSat_p ?
      controller_template_P.Saturation_LowerSat_p : temp_idx) *
      controller_template_P.Constant_Value_h +
      controller_template_P.Constant1_Value_m3 *
      controller_template_DWork.UnitDelay2_DSTATE_g;

    /* MATLAB Function: '<S83>/Ctrl_Xdir' incorporates:
     *  Constant: '<S83>/Constant'
     *  Constant: '<S83>/Constant1'
     *  Constant: '<S83>/Constant2'
     *  Constant: '<S83>/Constant3'
     *  Constant: '<S83>/Constant4'
     */
    controller_template_DWork.sfEvent_jv = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S91>:1' */
    /* '<S91>:1:3' */
    rtb_SliderGain_l = 1.0;

    /* '<S91>:1:5' */
    /* '<S91>:1:6' */
    minreg = -1;

    /* '<S91>:1:7' */
    sumViol = 10000.0 * controller_template_B.y;
    if (!(fabs(sumViol) > 4.503599627370496E+15)) {
      if (sumViol >= 0.5) {
        sumViol = floor(sumViol + 0.5);
      } else if (sumViol > -0.5) {
        sumViol = -0.0;
      } else {
        sumViol = ceil(sumViol - 0.5);
      }
    }

    sin_yaw = sumViol / 10000.0;

    /* '<S91>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S91>:1:12' */
    /* '<S91>:1:13' */
    for (i = 0; i < 100; i++) {
      Hi_1[i] = 0.0;
      Ki[i] = 0.0;
    }

    /*  Find the proper region */
    /* '<S91>:1:16' */
    abspos = 1.0;

    /* '<S91>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 3) {
        /* '<S91>:1:17' */
        /* '<S91>:1:18' */
        sumViol = 0.0;

        /* '<S91>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S91>:1:23' */
        for (dz = 0; dz <= (int32_T)
             controller_template_P.Constant4_Value_gb[ireg] - 1; dz++) {
          /* '<S91>:1:23' */
          /* '<S91>:1:25' */
          Hi_1[(int32_T)(1.0 + (real_T)dz) - 1] =
            controller_template_P.Constant_Value_a[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) - 1];

          /* '<S91>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S91>:1:30' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_gb[ireg]
             - 1; i++) {
          /* '<S91>:1:30' */
          /* '<S91>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant1_Value_gs[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S91>:1:30' */
        }

        /* '<S91>:1:33' */
        abspos += controller_template_P.Constant4_Value_gb[ireg];

        /* '<S91>:1:35' */
        /* '<S91>:1:36' */
        /* '<S91>:1:38' */
        /* '<S91>:1:40' */
        for (dz = 0; dz <= (int32_T)
             controller_template_P.Constant4_Value_gb[ireg] - 1; dz++) {
          /* '<S91>:1:40' */
          /* '<S91>:1:41' */
          yaw_rate_cmd_g = Hi_1[(int32_T)(1.0 + (real_T)dz) - 1] * sin_yaw;
          if (yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)dz) - 1] > 1.0E-8) {
            /* '<S91>:1:42' */
            /* '<S91>:1:43' */
            isinside = 0;

            /* '<S91>:1:44' */
            sumViol += yaw_rate_cmd_g - Ki[(int32_T)(1.0 + (real_T)dz) - 1];
          }

          /* '<S91>:1:40' */
        }

        if (sumViol < rtb_SliderGain_l) {
          /* '<S91>:1:48' */
          /* '<S91>:1:49' */
          rtb_SliderGain_l = sumViol;

          /* '<S91>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S91>:1:53' */
          /* '<S91>:1:54' */
          U_2 = controller_template_P.Constant2_Value_jq[ireg] * sin_yaw +
            controller_template_P.Constant3_Value_b[ireg];
          exitg = 1;
        } else {
          /* '<S91>:1:17' */
          ireg++;
        }
      } else {
        /* '<S91>:1:58' */
        /* '<S91>:1:59' */
        /* '<S91>:1:60' */
        U_2 = controller_template_P.Constant2_Value_jq[minreg] * sin_yaw +
          controller_template_P.Constant3_Value_b[minreg];

        /* '<S91>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_g = U_2;
    controller_template_B.flag_oob_l = (real_T)flag_oob;

    /* End of MATLAB Function: '<S83>/Ctrl_Xdir' */

    /* Gain: '<S86>/Gain' incorporates:
     *  Saturate: '<S33>/Saturation1'
     *  Sum: '<S86>/Sum'
     *  Sum: '<S86>/Sum1'
     *  UnitDelay: '<S86>/Unit Delay'
     *  UnitDelay: '<S86>/Unit Delay2'
     */
    controller_template_B.Gain_n = ((controller_template_B.U_g >=
      controller_template_P.Saturation1_UpperSat_g ?
      controller_template_P.Saturation1_UpperSat_g : controller_template_B.U_g <=
      controller_template_P.Saturation1_LowerSat_b ?
      controller_template_P.Saturation1_LowerSat_b : controller_template_B.U_g)
      + (controller_template_DWork.UnitDelay2_DSTATE_ga +
         controller_template_DWork.UnitDelay_DSTATE_p)) *
      controller_template_P.Gain_Gain_p0;

    /* Sum: '<S11>/Sum3' */
    yaw_rate_cmd_g = controller_template_B.Gain_n - controller_template_B.Gain2;

    /* Sum: '<S11>/Sum5' incorporates:
     *  Sum: '<S11>/Sum2'
     */
    controller_template_B.thrust_cmd_a = (controller_template_B.Gain_i -
      rtb_bias_W[2]) + rtb_SliderGain_h;

    /* RateTransition: '<S43>/Rate Transition1' */
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      controller_template_B.RateTransition1 = controller_template_B.Gain_pk;

      /* RateTransition: '<S44>/Rate Transition1' */
      controller_template_B.RateTransition1_l = controller_template_B.Gain_pk;
    }

    /* End of RateTransition: '<S43>/Rate Transition1' */

    /* UnitDelay: '<S48>/Unit Delay1' */
    sin_yaw = controller_template_DWork.UnitDelay1_DSTATE_a;

    /* MATLAB Function: '<S49>/MATLAB Function1' incorporates:
     *  Constant: '<S49>/Constant'
     *  Gain: '<S58>/Slider Gain'
     *  UnitDelay: '<S31>/Unit Delay'
     */
    controller_template_DWork.sfEvent_h = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem/MATLAB Function1': '<S57>:1' */
    /* '<S57>:1:5' */
    controller_template_B.flag_failure = 0.0;

    /* '<S57>:1:7' */
    if ((-controller_template_DWork.UnitDelay_DSTATE_a <=
         controller_template_P.SliderGain_Gain_mg *
         controller_template_P.Constant_Value_d) &&
        (-controller_template_DWork.UnitDelay_DSTATE_a != 0.0)) {
      /* '<S57>:1:9' */
      /* '<S57>:1:10' */
      controller_template_B.flag_failure = 1.0;
    }

    /* End of MATLAB Function: '<S49>/MATLAB Function1' */

    /* MATLAB Function: '<S60>/MATLAB Function' incorporates:
     *  UnitDelay: '<S60>/Unit Delay'
     */
    controller_template_DWork.sfEvent_fc = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem/Subsystem1/MATLAB Function': '<S64>:1' */
    /* '<S64>:1:4' */
    controller_template_B.pulse_enable = 1.0;
    if ((rtb_SwitchControl == 1.0) &&
        (controller_template_DWork.UnitDelay_DSTATE_m2 == 1.0)) {
      /* '<S64>:1:6' */
      /* '<S64>:1:7' */
      controller_template_B.pulse_enable = 0.0;
    }

    /* End of MATLAB Function: '<S60>/MATLAB Function' */

    /* MATLAB Function: '<S62>/MATLAB Function' incorporates:
     *  SignalConversion: '<S63>/TmpSignal ConversionAt SFunction Inport1'
     */
    controller_template_DWork.sfEvent_du = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem/Subsystem/Subsystem/MATLAB Function': '<S63>:1' */
    /* '<S63>:1:4' */
    controller_template_B.x_init[0] = controller_template_B.pitch_rot_i;
    controller_template_B.x_init[1] = controller_template_B.DataTypeConversion
      [10];
    controller_template_B.x_init[2] = controller_template_B.DataTypeConversion[0];
    controller_template_B.x_init[3] = controller_template_B.DataTypeConversion[3];

    /* '<S63>:1:5' */
    controller_template_B.flag_init = 0.0;
    if (controller_template_B.pulse_enable == 1.0) {
      /* '<S63>:1:7' */
      /* '<S63>:1:8' */
      controller_template_B.flag_init = 1.0;
    }

    /* End of MATLAB Function: '<S62>/MATLAB Function' */

    /* MATLAB Function: '<S59>/MATLAB Function' incorporates:
     *  Constant: '<S59>/Constant'
     *  Constant: '<S59>/Constant1'
     *  Constant: '<S59>/Constant2'
     *  Constant: '<S59>/Constant3'
     *  Constant: '<S59>/Constant4'
     *  SignalConversion: '<S61>/TmpSignal ConversionAt SFunction Inport5'
     *  UnitDelay: '<S59>/Unit Delay'
     */
    controller_template_DWork.sfEvent_cq = CALL_EVENT;
    rtb_Switch[0] = controller_template_B.pitch_rot_i;
    rtb_Switch[1] = controller_template_B.DataTypeConversion[10];
    rtb_Switch[2] = controller_template_B.DataTypeConversion[0];
    rtb_Switch[3] = controller_template_B.DataTypeConversion[3];

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem/Subsystem/MATLAB Function': '<S61>:1' */
    /* % Prediction Step  */
    if (controller_template_B.flag_init != 0.0) {
      /* '<S61>:1:7' */
      x_pred[0] = controller_template_P.Constant1_Value_l0[0] *
        controller_template_B.Gain_pk;
      x_pred[1] = controller_template_P.Constant1_Value_l0[1] *
        controller_template_B.Gain_pk;
      x_pred[2] = controller_template_P.Constant1_Value_l0[2] *
        controller_template_B.Gain_pk;
      x_pred[3] = controller_template_P.Constant1_Value_l0[3] *
        controller_template_B.Gain_pk;

      /* '<S61>:1:8' */
      memcpy((void *)&P_pred[0], (void *)controller_template_P.Constant3_Value_h,
             sizeof(real_T) << 4U);
    } else {
      /* '<S61>:1:10' */
      for (i = 0; i < 4; i++) {
        x_pred[i] = (((controller_template_P.Constant_Value_p[i + 4] *
                       controller_template_DWork.UnitDelay_DSTATE_m[1] +
                       controller_template_P.Constant_Value_p[i] *
                       controller_template_DWork.UnitDelay_DSTATE_m[0]) +
                      controller_template_P.Constant_Value_p[i + 8] *
                      controller_template_DWork.UnitDelay_DSTATE_m[2]) +
                     controller_template_P.Constant_Value_p[i + 12] *
                     controller_template_DWork.UnitDelay_DSTATE_m[3]) +
          controller_template_P.Constant1_Value_l0[i] *
          controller_template_B.Gain_pk;
      }

      /* '<S61>:1:11' */
      for (i = 0; i < 4; i++) {
        for (ireg = 0; ireg < 4; ireg++) {
          I_1[i + (ireg << 2)] = 0.0;
          I_1[i + (ireg << 2)] = I_1[(ireg << 2) + i] +
            controller_template_DWork.UnitDelay1_DSTATE_j5[(ireg << 2)] *
            controller_template_P.Constant_Value_p[i];
          I_1[i + (ireg << 2)] = controller_template_DWork.UnitDelay1_DSTATE_j5
            [(ireg << 2) + 1] * controller_template_P.Constant_Value_p[i + 4] +
            I_1[(ireg << 2) + i];
          I_1[i + (ireg << 2)] = controller_template_DWork.UnitDelay1_DSTATE_j5
            [(ireg << 2) + 2] * controller_template_P.Constant_Value_p[i + 8] +
            I_1[(ireg << 2) + i];
          I_1[i + (ireg << 2)] = controller_template_DWork.UnitDelay1_DSTATE_j5
            [(ireg << 2) + 3] * controller_template_P.Constant_Value_p[i + 12] +
            I_1[(ireg << 2) + i];
        }
      }

      for (i = 0; i < 4; i++) {
        for (ireg = 0; ireg < 4; ireg++) {
          P_pred[i + (ireg << 2)] = (((I_1[i + 4] *
            controller_template_P.Constant_Value_p[ireg + 4] + I_1[i] *
            controller_template_P.Constant_Value_p[ireg]) + I_1[i + 8] *
            controller_template_P.Constant_Value_p[ireg + 8]) + I_1[i + 12] *
            controller_template_P.Constant_Value_p[ireg + 12]) +
            controller_template_P.Constant3_Value_h[(ireg << 2) + i];
        }
      }
    }

    /* % Measurement Update Step */
    /*  Fault Case */
    if (controller_template_B.flag_failure != 0.0) {
      /* '<S61>:1:18' */
      rtb_Switch[2] = x_pred[2];

      /* '<S61>:1:19' */
      rtb_Switch[3] = x_pred[3];
    }

    /*  Kalman Gain */
    /* '<S61>:1:23' */
    for (i = 0; i < 4; i++) {
      for (ireg = 0; ireg < 4; ireg++) {
        P_pred_0[i + (ireg << 2)] = 0.0;
        P_pred_0[i + (ireg << 2)] = P_pred_0[(ireg << 2) + i] + P_pred[i] *
          controller_template_P.Constant2_Value_gl[ireg];
        P_pred_0[i + (ireg << 2)] = P_pred_0[(ireg << 2) + i] + P_pred[i + 4] *
          controller_template_P.Constant2_Value_gl[ireg + 4];
        P_pred_0[i + (ireg << 2)] = P_pred_0[(ireg << 2) + i] + P_pred[i + 8] *
          controller_template_P.Constant2_Value_gl[ireg + 8];
        P_pred_0[i + (ireg << 2)] = P_pred_0[(ireg << 2) + i] + P_pred[i + 12] *
          controller_template_P.Constant2_Value_gl[ireg + 12];
      }
    }

    for (i = 0; i < 4; i++) {
      for (ireg = 0; ireg < 4; ireg++) {
        K_1[i + (ireg << 2)] = 0.0;
        K_1[i + (ireg << 2)] = K_1[(ireg << 2) + i] + P_pred[ireg << 2] *
          controller_template_P.Constant2_Value_gl[i];
        K_1[i + (ireg << 2)] = P_pred[(ireg << 2) + 1] *
          controller_template_P.Constant2_Value_gl[i + 4] + K_1[(ireg << 2) + i];
        K_1[i + (ireg << 2)] = P_pred[(ireg << 2) + 2] *
          controller_template_P.Constant2_Value_gl[i + 8] + K_1[(ireg << 2) + i];
        K_1[i + (ireg << 2)] = P_pred[(ireg << 2) + 3] *
          controller_template_P.Constant2_Value_gl[i + 12] + K_1[(ireg << 2) + i];
      }
    }

    for (i = 0; i < 4; i++) {
      for (ireg = 0; ireg < 4; ireg++) {
        I_1[i + (ireg << 2)] = (((K_1[i + 4] *
          controller_template_P.Constant2_Value_gl[ireg + 4] + K_1[i] *
          controller_template_P.Constant2_Value_gl[ireg]) + K_1[i + 8] *
          controller_template_P.Constant2_Value_gl[ireg + 8]) + K_1[i + 12] *
          controller_template_P.Constant2_Value_gl[ireg + 12]) +
          controller_template_P.Constant4_Value_n[(ireg << 2) + i];
      }
    }

    controller_template_mrdivide_d(P_pred_0, I_1, K);

    /* '<S61>:1:24' */
    /* '<S61>:1:25' */
    for (i = 0; i < 16; i++) {
      I[i] = 0;
      b_I[i] = 0;
    }

    I[0] = 1;
    I[5] = 1;
    I[10] = 1;
    I[15] = 1;
    b_I[0] = 1;
    b_I[5] = 1;
    b_I[10] = 1;
    b_I[15] = 1;
    for (i = 0; i < 4; i++) {
      for (ireg = 0; ireg < 4; ireg++) {
        I_0[i + (ireg << 2)] = (real_T)I[(ireg << 2) + i] -
          (((controller_template_P.Constant2_Value_gl[(ireg << 2) + 1] * K[i + 4]
             + controller_template_P.Constant2_Value_gl[(ireg << 2)] * K[i]) +
            controller_template_P.Constant2_Value_gl[(ireg << 2) + 2] * K[i + 8])
           + controller_template_P.Constant2_Value_gl[(ireg << 2) + 3] * K[i +
           12]);
      }
    }

    for (i = 0; i < 4; i++) {
      for (ireg = 0; ireg < 4; ireg++) {
        I_1[i + (ireg << 2)] = 0.0;
        I_1[i + (ireg << 2)] = I_1[(ireg << 2) + i] + P_pred[ireg << 2] * I_0[i];
        I_1[i + (ireg << 2)] = P_pred[(ireg << 2) + 1] * I_0[i + 4] + I_1[(ireg <<
          2) + i];
        I_1[i + (ireg << 2)] = P_pred[(ireg << 2) + 2] * I_0[i + 8] + I_1[(ireg <<
          2) + i];
        I_1[i + (ireg << 2)] = P_pred[(ireg << 2) + 3] * I_0[i + 12] + I_1[(ireg
          << 2) + i];
      }
    }

    for (i = 0; i < 4; i++) {
      for (ireg = 0; ireg < 4; ireg++) {
        P_pred_0[i + (ireg << 2)] = (real_T)b_I[(i << 2) + ireg] -
          (((controller_template_P.Constant2_Value_gl[(i << 2) + 1] * K[ireg + 4]
             + controller_template_P.Constant2_Value_gl[(i << 2)] * K[ireg]) +
            controller_template_P.Constant2_Value_gl[(i << 2) + 2] * K[ireg + 8])
           + controller_template_P.Constant2_Value_gl[(i << 2) + 3] * K[ireg +
           12]);
      }
    }

    for (i = 0; i < 4; i++) {
      for (ireg = 0; ireg < 4; ireg++) {
        K_0[i + (ireg << 2)] = 0.0;
        K_0[i + (ireg << 2)] = K_0[(ireg << 2) + i] +
          controller_template_P.Constant4_Value_n[(ireg << 2)] * K[i];
        K_0[i + (ireg << 2)] = controller_template_P.Constant4_Value_n[(ireg <<
          2) + 1] * K[i + 4] + K_0[(ireg << 2) + i];
        K_0[i + (ireg << 2)] = controller_template_P.Constant4_Value_n[(ireg <<
          2) + 2] * K[i + 8] + K_0[(ireg << 2) + i];
        K_0[i + (ireg << 2)] = controller_template_P.Constant4_Value_n[(ireg <<
          2) + 3] * K[i + 12] + K_0[(ireg << 2) + i];
      }
    }

    for (i = 0; i < 4; i++) {
      for (ireg = 0; ireg < 4; ireg++) {
        I_0[i + (ireg << 2)] = 0.0;
        I_0[i + (ireg << 2)] = I_0[(ireg << 2) + i] + P_pred_0[ireg << 2] *
          I_1[i];
        I_0[i + (ireg << 2)] = P_pred_0[(ireg << 2) + 1] * I_1[i + 4] + I_0
          [(ireg << 2) + i];
        I_0[i + (ireg << 2)] = P_pred_0[(ireg << 2) + 2] * I_1[i + 8] + I_0
          [(ireg << 2) + i];
        I_0[i + (ireg << 2)] = P_pred_0[(ireg << 2) + 3] * I_1[i + 12] + I_0
          [(ireg << 2) + i];
      }
    }

    for (i = 0; i < 4; i++) {
      for (ireg = 0; ireg < 4; ireg++) {
        K_1[i + (ireg << 2)] = 0.0;
        K_1[i + (ireg << 2)] = K_1[(ireg << 2) + i] + K_0[i] * K[ireg];
        K_1[i + (ireg << 2)] = K_1[(ireg << 2) + i] + K_0[i + 4] * K[ireg + 4];
        K_1[i + (ireg << 2)] = K_1[(ireg << 2) + i] + K_0[i + 8] * K[ireg + 8];
        K_1[i + (ireg << 2)] = K_1[(ireg << 2) + i] + K_0[i + 12] * K[ireg + 12];
      }
    }

    for (i = 0; i < 4; i++) {
      controller_template_B.Pmeas[(i << 2)] = I_0[i << 2] + K_1[i << 2];
      controller_template_B.Pmeas[1 + (i << 2)] = I_0[(i << 2) + 1] + K_1[(i <<
        2) + 1];
      controller_template_B.Pmeas[2 + (i << 2)] = I_0[(i << 2) + 2] + K_1[(i <<
        2) + 2];
      controller_template_B.Pmeas[3 + (i << 2)] = I_0[(i << 2) + 3] + K_1[(i <<
        2) + 3];
    }

    if (controller_template_B.flag_failure != 0.0) {
      /* '<S61>:1:29' */
      controller_template_B.Pmeas[2] = P_pred[2];

      /* '<S61>:1:30' */
      controller_template_B.Pmeas[3] = P_pred[3];
    }

    for (i = 0; i < 4; i++) {
      rtb_Switch_0[i] = rtb_Switch[i] -
        (((controller_template_P.Constant2_Value_gl[i + 4] * x_pred[1] +
           controller_template_P.Constant2_Value_gl[i] * x_pred[0]) +
          controller_template_P.Constant2_Value_gl[i + 8] * x_pred[2]) +
         controller_template_P.Constant2_Value_gl[i + 12] * x_pred[3]);
    }

    for (i = 0; i < 4; i++) {
      controller_template_B.x_meas[i] = (((K[i + 4] * rtb_Switch_0[1] + K[i] *
        rtb_Switch_0[0]) + K[i + 8] * rtb_Switch_0[2]) + K[i + 12] *
        rtb_Switch_0[3]) + x_pred[i];
    }

    /* End of MATLAB Function: '<S59>/MATLAB Function' */

    /* RateTransition: '<S68>/Rate Transition1' */
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      controller_template_B.RateTransition1_lq = controller_template_B.Gain_f;
    }

    /* End of RateTransition: '<S68>/Rate Transition1' */

    /* UnitDelay: '<S69>/Unit Delay1' */
    cos_yaw = controller_template_DWork.UnitDelay1_DSTATE_ji;

    /* Gain: '<S33>/Gain' */
    controller_template_B.Gain_g = controller_template_P.Gain_Gain_b *
      controller_template_B.psi_out;

    /* UnitDelay: '<S86>/Unit Delay1' */
    rtb_SliderGain_c = controller_template_DWork.UnitDelay1_DSTATE_c3;

    /* Gain: '<S34>/Gain1' */
    controller_template_B.Gain1 = controller_template_P.Gain1_Gain_e *
      controller_template_B.DataTypeConversion[8];

    /* Gain: '<S34>/Gain' */
    controller_template_B.Gain_d = controller_template_P.Gain_Gain_e *
      controller_template_B.psi_prime;

    /* Update for Delay: '<S11>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE_k = yaw_rate_cmd_g;

    /* Update for UnitDelay: '<S34>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_bg, (void *)
           (&controller_template_B.sf_discretekalmanfilter.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S95>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S95>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
      controller_template_P.FixPtConstant_Value;

    /* Update for UnitDelay: '<S95>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0] =
      controller_template_B.sf_discretekalmanfilter.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1] =
      controller_template_B.sf_discretekalmanfilter.state_est[1];

    /* Update for UnitDelay: '<S31>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_h[0] =
      controller_template_B.x_meas[0];
    controller_template_DWork.UnitDelay1_DSTATE_h[1] =
      controller_template_B.x_meas[1];
    controller_template_DWork.UnitDelay1_DSTATE_h[2] =
      controller_template_B.x_meas[2];
    controller_template_DWork.UnitDelay1_DSTATE_h[3] =
      controller_template_B.x_meas[3];

    /* Update for UnitDelay: '<S31>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE =
      controller_template_B.flag_failure;
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for UnitDelay: '<S44>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_c =
        controller_template_B.RateTransition1_l;

      /* Update for UnitDelay: '<S43>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_m =
        controller_template_B.RateTransition1;
    }

    /* Update for UnitDelay: '<S48>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_d =
      controller_template_B.Gain_pk;

    /* Update for UnitDelay: '<S48>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_jv = sin_yaw;
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for UnitDelay: '<S68>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_l =
        controller_template_B.RateTransition1_lq;
    }

    /* Update for UnitDelay: '<S69>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_k = controller_template_B.Gain_f;

    /* Update for UnitDelay: '<S69>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_f = cos_yaw;

    /* Update for UnitDelay: '<S98>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_b = controller_template_B.Gain_i;

    /* Update for UnitDelay: '<S98>/Unit Delay' incorporates:
     *  UnitDelay: '<S98>/Unit Delay1'
     */
    controller_template_DWork.UnitDelay_DSTATE_fw =
      controller_template_DWork.UnitDelay1_DSTATE_m;

    /* Update for UnitDelay: '<S33>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_lg =
      controller_template_B.psi_prime_l;

    /* Update for UnitDelay: '<S83>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_g = controller_template_B.Gain_n;

    /* Update for UnitDelay: '<S86>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_ga =
      controller_template_B.Gain_n;

    /* Update for UnitDelay: '<S86>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_p = rtb_SliderGain_c;

    /* Update for UnitDelay: '<S48>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_a =
      controller_template_B.Gain_pk;

    /* Update for UnitDelay: '<S31>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_a = rtb_Saturation3_o;

    /* Update for UnitDelay: '<S59>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_m[0] =
      controller_template_B.x_meas[0];
    controller_template_DWork.UnitDelay_DSTATE_m[1] =
      controller_template_B.x_meas[1];
    controller_template_DWork.UnitDelay_DSTATE_m[2] =
      controller_template_B.x_meas[2];
    controller_template_DWork.UnitDelay_DSTATE_m[3] =
      controller_template_B.x_meas[3];

    /* Update for UnitDelay: '<S59>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j5, (void *)
           (&controller_template_B.Pmeas[0]), sizeof(real_T) << 4U);

    /* Update for UnitDelay: '<S60>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_m2 = rtb_SwitchControl;

    /* Update for UnitDelay: '<S69>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_ji =
      controller_template_B.Gain_f;

    /* Update for UnitDelay: '<S86>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_c3 =
      controller_template_B.Gain_n;

    /* Update for UnitDelay: '<S98>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_m = controller_template_B.Gain_i;

    /* End of Outputs for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

    /* SignalConversion: '<S16>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFi_a[0] =
      controller_template_B.DataTypeConversion[0];
    rtb_TmpSignalConversionAtToFi_a[1] =
      controller_template_B.DataTypeConversion[3];
    rtb_TmpSignalConversionAtToFi_a[2] = controller_template_B.pitch_rot_i;
    rtb_TmpSignalConversionAtToFi_a[3] = controller_template_B.x_ref;
    rtb_TmpSignalConversionAtToFi_a[4] = rtb_pitch_cmd_b;
    rtb_TmpSignalConversionAtToFi_a[5] =
      controller_template_B.DataTypeConversion[1];
    rtb_TmpSignalConversionAtToFi_a[6] =
      controller_template_B.DataTypeConversion[4];
    rtb_TmpSignalConversionAtToFi_a[7] = controller_template_B.roll_rot_f;
    rtb_TmpSignalConversionAtToFi_a[8] = controller_template_B.y_ref;
    rtb_TmpSignalConversionAtToFi_a[9] = rtb_SliderGain_m;
    rtb_TmpSignalConversionAtToFi_a[10] =
      controller_template_B.DataTypeConversion[2];
    rtb_TmpSignalConversionAtToFi_a[11] =
      controller_template_B.DataTypeConversion[5];
    rtb_TmpSignalConversionAtToFi_a[12] = controller_template_B.z_ref;
    rtb_TmpSignalConversionAtToFi_a[13] = controller_template_B.thrust_cmd_a;
    rtb_TmpSignalConversionAtToFi_a[14] =
      controller_template_B.DataTypeConversion[8];
    rtb_TmpSignalConversionAtToFi_a[15] =
      controller_template_B.DataTypeConversion[11];
    rtb_TmpSignalConversionAtToFi_a[16] = rtb_yaw_ref;
    rtb_TmpSignalConversionAtToFi_a[17] = yaw_rate_cmd_g;

    /* ToFile: '<S16>/To File' */
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

    /* SignalConversion: '<S16>/TmpSignal ConversionAtTo File1Inport1' */
    rtb_TmpSignalConversionAtToFi_p[0] = rtb_bias_W[0];
    rtb_TmpSignalConversionAtToFi_p[1] = rtb_bias_W[1];
    rtb_TmpSignalConversionAtToFi_p[2] = rtb_bias_W[2];
    rtb_TmpSignalConversionAtToFi_p[3] = controller_template_B.Gain2;

    /* ToFile: '<S16>/To File1' */
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

    /* Gain: '<S16>/Gain' */
    for (i = 0; i < 18; i++) {
      controller_template_B.Gain_p[i] = controller_template_P.Gain_Gain_a *
        rtb_TmpSignalConversionAtToFi_a[i];
    }

    /* End of Gain: '<S16>/Gain' */

    /* Gain: '<S16>/rad -> deg2' */
    controller_template_B.raddeg2_p[0] = controller_template_P.raddeg2_Gain *
      controller_template_B.pitch_rot_i;
    controller_template_B.raddeg2_p[1] = controller_template_P.raddeg2_Gain *
      controller_template_B.DataTypeConversion[10];
    controller_template_B.raddeg2_p[2] = controller_template_P.raddeg2_Gain *
      rtb_pitch_cmd_b;

    /* Gain: '<S16>/rad -> deg1' */
    controller_template_B.raddeg1_e[0] = controller_template_P.raddeg1_Gain *
      controller_template_B.roll_rot_f;
    controller_template_B.raddeg1_e[1] = controller_template_P.raddeg1_Gain *
      rtb_SliderGain_m;

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_5_Threshold) {
      controller_template_B.x_dot_ref = rtb_X_ref_x[1];
    } else {
      controller_template_B.x_dot_ref = rtb_X_ref_x_k[1];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_6_Threshold) {
      controller_template_B.y_dot_ref = rtb_X_ref_y[1];
    } else {
      controller_template_B.y_dot_ref = rtb_X_ref_y_j[1];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* Gain: '<S16>/rad -> deg3' */
    controller_template_B.raddeg3_a[0] = controller_template_P.raddeg3_Gain *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg3_a[1] = controller_template_P.raddeg3_Gain *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg3_a[2] = controller_template_P.raddeg3_Gain *
      yaw_rate_cmd_g;

    /* Gain: '<S16>/rad -> deg' */
    controller_template_B.raddeg_j[0] = controller_template_P.raddeg_Gain *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg_j[1] = controller_template_P.raddeg_Gain *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg_j[2] = controller_template_P.raddeg_Gain *
      rtb_yaw_ref;

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_8_Threshold) {
      cos_yaw = rtb_X_ref_yaw[1];
    } else {
      cos_yaw = rtb_X_ref_yaw_a[1];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* Gain: '<S16>/rad -> deg' */
    controller_template_B.raddeg_j[3] = controller_template_P.raddeg_Gain *
      cos_yaw;

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_7_Threshold) {
      controller_template_B.z_dot_ref = rtb_X_ref_z[1];
    } else {
      controller_template_B.z_dot_ref = rtb_X_ref_z_a[1];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* Sum: '<S17>/Sum' incorporates:
     *  Constant: '<S17>/Constant'
     *  UnitDelay: '<S17>/Unit Delay'
     */
    rtb_SliderGain_c = controller_template_P.Constant_Value_kh +
      controller_template_DWork.UnitDelay_DSTATE_e;

    /* Sum: '<S17>/Sum2' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S17>/total_samples'
     *  Math: '<S17>/Math Function'
     */
    rtb_Sum2_m2 = rt_modd_snf(rtb_SliderGain_c,
      controller_template_P.total_samples_Value_k) +
      controller_template_P.Constant1_Value_h;

    /* MATLAB Function: '<S17>/generate_X_ref_x' */
    controller_tem_generate_X_ref_x(controller_template_P.X_ref_x_Value_k,
      rtb_Sum2_m2, &controller_template_B.sf_generate_X_ref_x_k,
      &controller_template_DWork.sf_generate_X_ref_x_k);

    /* MATLAB Function: '<S17>/generate_X_ref_y' */
    controller_tem_generate_X_ref_y(controller_template_P.X_ref_y_Value_e,
      rtb_Sum2_m2, &controller_template_B.sf_generate_X_ref_y_a,
      &controller_template_DWork.sf_generate_X_ref_y_a);

    /* MATLAB Function: '<S17>/generate_X_ref_yaw' */
    controller_t_generate_X_ref_yaw(controller_template_P.X_ref_yaw_Value_f,
      controller_template_B.DataTypeConversion[8], rtb_Sum2_m2,
      &controller_template_B.sf_generate_X_ref_yaw_g,
      &controller_template_DWork.sf_generate_X_ref_yaw_g);

    /* MATLAB Function: '<S17>/generate_X_ref_z' */
    controller_tem_generate_X_ref_z(controller_template_P.X_ref_z_Value_a,
      rtb_Sum2_m2, &controller_template_B.sf_generate_X_ref_z_l,
      &controller_template_DWork.sf_generate_X_ref_z_l);

    /* Sum: '<S108>/Sum' */
    controller_template_B.Sum[0] = controller_template_B.DataTypeConversion[1] -
      controller_template_B.X_ref_y[0];
    controller_template_B.Sum[1] = rtb_y_ref - controller_template_B.X_ref_y[0];

    /* Gain: '<S108>/Gain' incorporates:
     *  Sum: '<S108>/Sum1'
     */
    controller_template_B.Gain_k[0] = (controller_template_B.DataTypeConversion
      [2] - controller_template_B.X_ref_z[0]) *
      controller_template_P.Gain_Gain_d;
    controller_template_B.Gain_k[1] = (rtb_z_ref -
      controller_template_B.X_ref_z[0]) * controller_template_P.Gain_Gain_d;

    /* MATLAB Function: '<S111>/MATLAB Function' incorporates:
     *  UnitDelay: '<S111>/Unit Delay'
     *  UnitDelay: '<S111>/Unit Delay1'
     */
    controller_template_DWork.sfEvent_jg = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem/MATLAB Function': '<S119>:1' */
    /* '<S119>:1:4' */
    controller_template_B.count_out =
      controller_template_DWork.UnitDelay1_DSTATE_o;
    if (((controller_template_B.en == 1.0) &&
         (controller_template_DWork.UnitDelay_DSTATE_es == 0.0)) ||
        ((controller_template_B.en == 1.0) &&
         (controller_template_DWork.UnitDelay_DSTATE_es == 1.0))) {
      /* '<S119>:1:5' */
      /* '<S119>:1:6' */
      controller_template_B.count_out =
        controller_template_DWork.UnitDelay1_DSTATE_o + 1.0;
    }

    /* End of MATLAB Function: '<S111>/MATLAB Function' */

    /* Outputs for Atomic SubSystem: '<S2>/decoupling and rotation' */
    /* Inport: '<S14>/bias_W' */
    controller_template_B.bias_W_b[0] = rtb_TmpSignalConversionAtToFi_p[0];
    controller_template_B.bias_W_b[1] = rtb_TmpSignalConversionAtToFi_p[1];
    controller_template_B.bias_W_b[2] = rtb_TmpSignalConversionAtToFi_p[2];
    controller_template_B.bias_W_b[3] = rtb_TmpSignalConversionAtToFi_p[3];

    /* Inport: '<S14>/cmd_W' */
    controller_template_B.cmd_W_h[0] = rtb_pitch_cmd_b;
    controller_template_B.cmd_W_h[1] = rtb_SliderGain_m;
    controller_template_B.cmd_W_h[2] = controller_template_B.thrust_cmd_a;
    controller_template_B.cmd_W_h[3] = yaw_rate_cmd_g;

    /* Sum: '<S136>/Add' incorporates:
     *  Constant: '<S136>/Constant'
     *  Gain: '<S138>/Slider Gain'
     */
    rtb_Add_k = controller_template_B.DataTypeConversion[0] -
      controller_template_P.SliderGain_Gain_n *
      controller_template_P.Constant_Value_ks;

    /* Gain: '<S139>/Slider Gain' incorporates:
     *  Constant: '<S136>/Constant1'
     */
    rtb_SliderGain_m1 = controller_template_P.SliderGain_Gain_i *
      controller_template_P.Constant1_Value_i;

    /* MATLAB Function: '<S136>/MATLAB Function' */
    controller_templ_MATLABFunction(rtb_Add_k, rtb_SliderGain_m1,
      &controller_template_B.sf_MATLABFunction_p,
      &controller_template_DWork.sf_MATLABFunction_p);

    /* MATLAB Function: '<S133>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S133>/g'
     *  Saturate: '<S136>/Saturation3'
     */
    controller_template_DWork.sfEvent_c = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Embedded MATLAB Function': '<S135>:1' */
    /* '<S135>:1:3' */
    if ((controller_template_B.sf_MATLABFunction_p.y >=
         controller_template_P.Saturation3_UpperSat_p ?
         controller_template_P.Saturation3_UpperSat_p :
         controller_template_B.sf_MATLABFunction_p.y <=
         controller_template_P.Saturation3_LowerSat_es ?
         controller_template_P.Saturation3_LowerSat_es :
         controller_template_B.sf_MATLABFunction_p.y) == 0.0) {
      /* '<S135>:1:5' */
      /* '<S135>:1:6' */
      sin_yaw = controller_template_B.cmd_W_h[2] / (cos
        (controller_template_B.pitch_rot_i) * cos
        (controller_template_B.roll_rot_f));
      if ((fabs(controller_template_B.pitch_rot_i) >= 0.069813170079773182) &&
          (fabs(controller_template_B.roll_rot_f) >= 0.069813170079773182)) {
        /* '<S135>:1:8' */
        /* '<S135>:1:9' */
        sin_yaw = controller_template_B.cmd_W_h[2] / 0.99513403437078507;
      } else if (fabs(controller_template_B.pitch_rot_i) >= 0.069813170079773182)
      {
        /* '<S135>:1:10' */
        /* '<S135>:1:11' */
        sin_yaw = controller_template_B.cmd_W_h[2] / (0.9975640502598242 * cos
          (controller_template_B.roll_rot_f));
      } else {
        if (fabs(controller_template_B.roll_rot_f) >= 0.069813170079773182) {
          /* '<S135>:1:12' */
          /* '<S135>:1:13' */
          sin_yaw = controller_template_B.cmd_W_h[2] / (cos
            (controller_template_B.pitch_rot_i) * 0.9975640502598242);
        }
      }
    } else {
      /* '<S135>:1:16' */
      sin_yaw = controller_template_B.cmd_W_h[2] / (cos
        (controller_template_B.pitch_rot_i) * cos
        (controller_template_B.roll_rot_f));
    }

    /* '<S135>:1:18' */
    controller_template_B.pitch_cmd_comp_n =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value / sin_yaw * controller_template_B.cmd_W_h[0];

    /* '<S135>:1:19' */
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

    /* End of MATLAB Function: '<S133>/Embedded MATLAB Function' */

    /* MATLAB Function: '<S134>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_j = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S140>:1' */
    /* '<S140>:1:3' */
    sin_yaw = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S140>:1:4' */
    cos_yaw = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S140>:1:6' */
    /* '<S140>:1:8' */
    /* '<S140>:1:9' */
    controller_template_B.pitch_rot_n = cos_yaw *
      controller_template_B.pitch_cmd_comp_n + -sin_yaw *
      controller_template_B.roll_cmd_comp_j;

    /* '<S140>:1:10' */
    controller_template_B.roll_rot_e = sin_yaw *
      controller_template_B.pitch_cmd_comp_n + cos_yaw *
      controller_template_B.roll_cmd_comp_j;

    /* '<S140>:1:12' */
    /* '<S140>:1:13' */
    controller_template_B.pitch_bias_rot_i = cos_yaw *
      controller_template_B.bias_W_b[0] + -sin_yaw *
      controller_template_B.bias_W_b[1];

    /* '<S140>:1:14' */
    controller_template_B.roll_bias_rot_d = sin_yaw *
      controller_template_B.bias_W_b[0] + cos_yaw *
      controller_template_B.bias_W_b[1];

    /* End of Outputs for SubSystem: '<S2>/decoupling and rotation' */

    /* Update for UnitDelay: '<S108>/Unit Delay' */
    controller_template_DWork.UnitDelay_2_DSTATE = rtb_X_ref_y[0];

    /* Update for UnitDelay: '<S108>/Unit Delay' */
    controller_template_DWork.UnitDelay_3_DSTATE = rtb_X_ref_z[0];

    /* Update for UnitDelay: '<S108>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_i =
      controller_template_B.count_out;

    /* Update for UnitDelay: '<S116>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_g = rtb_Sum_c;

    /* Update for UnitDelay: '<S18>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_c = rtb_Sum_f;

    /* Update for UnitDelay: '<S17>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_e = rtb_SliderGain_c;

    /* Update for UnitDelay: '<S111>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_es = controller_template_B.en;

    /* Update for UnitDelay: '<S111>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_o =
      controller_template_B.count_out;
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
  if (controller_template_P.Constant_Value_nk >
      controller_template_P.SwitchControl_Threshold_b) {
    cos_yaw = controller_template_P.Constant_Value_pe;
  } else {
    cos_yaw = controller_template_B.MultiportSwitch;
  }

  /* End of Switch: '<S4>/SwitchControl' */

  /* Outputs for Enabled SubSystem: '<Root>/pos controller' incorporates:
   *  EnablePort: '<S9>/Enable'
   */
  if (cos_yaw > 0.0) {
    if (!controller_template_DWork.poscontroller_MODE) {
      /* InitializeConditions for MATLAB Function: '<S152>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent = CALL_EVENT;
      controller_template_DWork.is_active_c26_Hquad_control_LIB = 0U;

      /* InitializeConditions for Atomic SubSystem: '<S9>/MAIN CONTROL LOOP1' */
      /* InitializeConditions for Delay: '<S149>/Integer Delay' */
      controller_template_DWork.IntegerDelay_DSTATE =
        controller_template_P.IntegerDelay_InitialCondition;

      /* InitializeConditions for Delay: '<S149>/Integer Delay1' */
      controller_template_DWork.IntegerDelay1_DSTATE =
        controller_template_P.IntegerDelay1_InitialCondition;

      /* InitializeConditions for Delay: '<S149>/Integer Delay2' */
      controller_template_DWork.IntegerDelay2_DSTATE =
        controller_template_P.IntegerDelay2_InitialCondition;

      /* InitializeConditions for Delay: '<S149>/Integer Delay3' */
      controller_template_DWork.IntegerDelay3_DSTATE =
        controller_template_P.IntegerDelay3_InitialConditio_c;

      /* InitializeConditions for UnitDelay: '<S156>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
             controller_template_P.UnitDelay1_X0_c, sizeof(real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S164>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
        controller_template_P.FixPtUnitDelay2_X0_d;

      /* InitializeConditions for UnitDelay: '<S164>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
        controller_template_P.FixPtUnitDelay1_X0_f;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
        controller_template_P.FixPtUnitDelay1_X0_f;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
        controller_template_P.FixPtUnitDelay1_X0_f;

      /* InitializeConditions for MATLAB Function: '<S156>/discrete kalman filter' */
      con_discretekalmanfilter_k_Init
        (&controller_template_DWork.sf_discretekalmanfilter_b);

      /* InitializeConditions for UnitDelay: '<S155>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE[0] =
        controller_template_P.UnitDelay_X0_fc[0];
      controller_template_DWork.UnitDelay_DSTATE[1] =
        controller_template_P.UnitDelay_X0_fc[1];
      controller_template_DWork.UnitDelay_DSTATE[2] =
        controller_template_P.UnitDelay_X0_fc[2];

      /* InitializeConditions for UnitDelay: '<S155>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
             controller_template_P.UnitDelay1_X0_k, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S155>/runFastGradient' */
      controller_runFastGradient_Init
        (&controller_template_DWork.sf_runFastGradient);

      /* InitializeConditions for UnitDelay: '<S158>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
             controller_template_P.UnitDelay1_X0_fk, sizeof(real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S167>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
        controller_template_P.FixPtUnitDelay2_X0_n;

      /* InitializeConditions for UnitDelay: '<S167>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
        controller_template_P.FixPtUnitDelay1_X0_n;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
        controller_template_P.FixPtUnitDelay1_X0_n;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
        controller_template_P.FixPtUnitDelay1_X0_n;

      /* InitializeConditions for MATLAB Function: '<S158>/discrete kalman filter' */
      con_discretekalmanfilter_k_Init
        (&controller_template_DWork.sf_discretekalmanfilter_m);

      /* InitializeConditions for UnitDelay: '<S157>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_j[0] =
        controller_template_P.UnitDelay_X0_ik[0];
      controller_template_DWork.UnitDelay_DSTATE_j[1] =
        controller_template_P.UnitDelay_X0_ik[1];
      controller_template_DWork.UnitDelay_DSTATE_j[2] =
        controller_template_P.UnitDelay_X0_ik[2];

      /* InitializeConditions for UnitDelay: '<S157>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
             controller_template_P.UnitDelay1_X0_jc, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S157>/runFastGradient' */
      controller_runFastGradient_Init
        (&controller_template_DWork.sf_runFastGradient_d);

      /* InitializeConditions for UnitDelay: '<S162>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
             controller_template_P.UnitDelay1_X0_cw, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S173>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
        controller_template_P.FixPtUnitDelay2_X0_do;

      /* InitializeConditions for UnitDelay: '<S173>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
        controller_template_P.FixPtUnitDelay1_X0_c;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
        controller_template_P.FixPtUnitDelay1_X0_c;

      /* InitializeConditions for MATLAB Function: '<S162>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter_k);

      /* InitializeConditions for UnitDelay: '<S161>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_l[0] =
        controller_template_P.UnitDelay_X0_a2[0];
      controller_template_DWork.UnitDelay_DSTATE_l[1] =
        controller_template_P.UnitDelay_X0_a2[1];

      /* InitializeConditions for UnitDelay: '<S161>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
             controller_template_P.UnitDelay1_X0_b, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S161>/runFastGradient' */
      controller_template_DWork.sfEvent_k = CALL_EVENT;
      controller_template_DWork.is_active_c8_Hquad_control_LIB_ = 0U;

      /* InitializeConditions for UnitDelay: '<S160>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
             controller_template_P.UnitDelay1_X0_n, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S170>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
        controller_template_P.FixPtUnitDelay2_X0_i;

      /* InitializeConditions for UnitDelay: '<S170>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
        controller_template_P.FixPtUnitDelay1_X0_e;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
        controller_template_P.FixPtUnitDelay1_X0_e;

      /* InitializeConditions for MATLAB Function: '<S160>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter_n);

      /* InitializeConditions for UnitDelay: '<S159>/Unit Delay' */
      for (i = 0; i < 6; i++) {
        controller_template_DWork.UnitDelay_DSTATE_jz[i] =
          controller_template_P.UnitDelay_X0_fj[i];
      }

      /* End of InitializeConditions for UnitDelay: '<S159>/Unit Delay' */

      /* InitializeConditions for UnitDelay: '<S159>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
             controller_template_P.UnitDelay1_X0_o, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S159>/runFastGradient' */
      controller_template_DWork.sfEvent_n = CALL_EVENT;
      controller_template_DWork.is_active_c9_Hquad_control_LIB_ = 0U;

      /* End of InitializeConditions for SubSystem: '<S9>/MAIN CONTROL LOOP1' */

      /* InitializeConditions for Atomic SubSystem: '<S9>/decoupling and rotation' */
      /* InitializeConditions for MATLAB Function: '<S175>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_f = CALL_EVENT;
      controller_template_DWork.is_active_c1_Hquad_control_LIB_ = 0U;

      /* InitializeConditions for MATLAB Function: '<S176>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_b = CALL_EVENT;
      controller_template_DWork.is_active_c4_Hquad_control_LIB_ = 0U;

      /* End of InitializeConditions for SubSystem: '<S9>/decoupling and rotation' */
      controller_template_DWork.poscontroller_MODE = TRUE;
    }

    /* MATLAB Function: '<S152>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent = CALL_EVENT;

    /* MATLAB Function 'rotate to world frame/Embedded MATLAB Function': '<S179>:1' */
    /* '<S179>:1:5' */
    sin_yaw = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S179>:1:6' */
    cos_yaw = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S179>:1:8' */
    /* '<S179>:1:10' */
    /* '<S179>:1:11' */
    controller_template_B.pitch_rot = cos_yaw *
      controller_template_B.DataTypeConversion[7] + sin_yaw *
      controller_template_B.DataTypeConversion[6];

    /* '<S179>:1:12' */
    controller_template_B.roll_rot = -sin_yaw *
      controller_template_B.DataTypeConversion[7] + cos_yaw *
      controller_template_B.DataTypeConversion[6];

    /* '<S179>:1:14' */
    /* '<S179>:1:15' */
    controller_template_B.pitch_bias_rot = cos_yaw * rtb_Init[0] + sin_yaw *
      rtb_Init[1];

    /* '<S179>:1:16' */
    controller_template_B.roll_bias_rot = -sin_yaw * rtb_Init[0] + cos_yaw *
      rtb_Init[1];

    /* Outputs for Atomic SubSystem: '<S9>/MAIN CONTROL LOOP1' */
    /* Delay: '<S149>/Integer Delay' */
    rtb_IntegerDelay = controller_template_DWork.IntegerDelay_DSTATE;

    /* Delay: '<S149>/Integer Delay1' */
    rtb_IntegerDelay1 = controller_template_DWork.IntegerDelay1_DSTATE;

    /* Delay: '<S149>/Integer Delay2' */
    rtb_IntegerDelay2 = controller_template_DWork.IntegerDelay2_DSTATE;

    /* Delay: '<S149>/Integer Delay3' */
    rtb_IntegerDelay3 = controller_template_DWork.IntegerDelay3_DSTATE;

    /* Product: '<S149>/Product' incorporates:
     *  Constant: '<S149>/gravity'
     */
    yaw_rate_cmd_g = controller_template_P.gravity_Value_j *
      controller_template_B.DataTypeConversion[29];

    /* UnitDelay: '<S156>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE, sizeof(real_T) << 4U);

    /* Switch: '<S164>/Init' incorporates:
     *  UnitDelay: '<S164>/FixPt Unit Delay1'
     *  UnitDelay: '<S164>/FixPt Unit Delay2'
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

    /* End of Switch: '<S164>/Init' */

    /* MATLAB Function: '<S156>/discrete kalman filter' */
    controll_discretekalmanfilter_b(controller_template_B.DataTypeConversion[0],
      controller_template_B.DataTypeConversion[3],
      controller_template_B.pitch_rot, rtb_Init_g,
      controller_template_B.pitch_bias_rot, controller_template_P.A_Value_h,
      controller_template_P.B_Value_i, controller_template_P.C_Value_c,
      controller_template_P.Q_Value_a, controller_template_P.R_Value_c,
      rtb_IntegerDelay, rtb_UnitDelay1,
      &controller_template_B.sf_discretekalmanfilter_b,
      &controller_template_DWork.sf_discretekalmanfilter_b);

    /* UnitDelay: '<S155>/Unit Delay' */
    rtb_UnitDelay[0] = controller_template_DWork.UnitDelay_DSTATE[0];
    rtb_UnitDelay[1] = controller_template_DWork.UnitDelay_DSTATE[1];
    rtb_UnitDelay[2] = controller_template_DWork.UnitDelay_DSTATE[2];

    /* UnitDelay: '<S155>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_o[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_c, 30U * sizeof(real_T));

    /* MATLAB Function: '<S155>/runFastGradient' */
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

    /* Saturate: '<S156>/Saturation' */
    rtb_SliderGain_m =
      controller_template_B.sf_discretekalmanfilter_b.state_est[3] >=
      controller_template_P.Saturation_UpperSat_ia ?
      controller_template_P.Saturation_UpperSat_ia :
      controller_template_B.sf_discretekalmanfilter_b.state_est[3] <=
      controller_template_P.Saturation_LowerSat_o ?
      controller_template_P.Saturation_LowerSat_o :
      controller_template_B.sf_discretekalmanfilter_b.state_est[3];

    /* Sum: '<S149>/Sum' */
    sumViol = controller_template_B.sf_runFastGradient.u_opt - rtb_SliderGain_m;

    /* UnitDelay: '<S158>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_oh[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_b, sizeof(real_T) << 4U);

    /* Switch: '<S167>/Init' incorporates:
     *  UnitDelay: '<S167>/FixPt Unit Delay1'
     *  UnitDelay: '<S167>/FixPt Unit Delay2'
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

    /* End of Switch: '<S167>/Init' */

    /* MATLAB Function: '<S158>/discrete kalman filter' */
    controll_discretekalmanfilter_b(controller_template_B.DataTypeConversion[1],
      controller_template_B.DataTypeConversion[4],
      controller_template_B.roll_rot, rtb_Init_j,
      controller_template_B.roll_bias_rot, controller_template_P.A_Value_n,
      controller_template_P.B_Value_h, controller_template_P.C_Value_p,
      controller_template_P.Q_Value_h, controller_template_P.R_Value_l,
      rtb_IntegerDelay1, rtb_UnitDelay1_oh,
      &controller_template_B.sf_discretekalmanfilter_m,
      &controller_template_DWork.sf_discretekalmanfilter_m);

    /* UnitDelay: '<S157>/Unit Delay' */
    rtb_UnitDelay_e[0] = controller_template_DWork.UnitDelay_DSTATE_j[0];
    rtb_UnitDelay_e[1] = controller_template_DWork.UnitDelay_DSTATE_j[1];
    rtb_UnitDelay_e[2] = controller_template_DWork.UnitDelay_DSTATE_j[2];

    /* UnitDelay: '<S157>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_g[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_l, 30U * sizeof(real_T));

    /* MATLAB Function: '<S157>/runFastGradient' */
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

    /* Saturate: '<S158>/Saturation' */
    rtb_SliderGain_h =
      controller_template_B.sf_discretekalmanfilter_m.state_est[3] >=
      controller_template_P.Saturation_UpperSat_f ?
      controller_template_P.Saturation_UpperSat_f :
      controller_template_B.sf_discretekalmanfilter_m.state_est[3] <=
      controller_template_P.Saturation_LowerSat_k ?
      controller_template_P.Saturation_LowerSat_k :
      controller_template_B.sf_discretekalmanfilter_m.state_est[3];

    /* Sum: '<S149>/Sum1' */
    rtb_SliderGain_l = controller_template_B.sf_runFastGradient_d.u_opt -
      rtb_SliderGain_h;

    /* UnitDelay: '<S162>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_j[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_j, 9U * sizeof(real_T));

    /* Switch: '<S173>/Init' incorporates:
     *  UnitDelay: '<S173>/FixPt Unit Delay1'
     *  UnitDelay: '<S173>/FixPt Unit Delay2'
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

    /* End of Switch: '<S173>/Init' */

    /* MATLAB Function: '<S162>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.DataTypeConversion[2],
      controller_template_B.DataTypeConversion[5], rtb_Init_d, rtb_Init[2],
      controller_template_P.A_Value_f, controller_template_P.B_Value_n,
      controller_template_P.C_Value_o, controller_template_P.Q_Value_j,
      controller_template_P.R_Value_ca, rtb_IntegerDelay2, rtb_UnitDelay1_j,
      &controller_template_B.sf_discretekalmanfilter_k,
      &controller_template_DWork.sf_discretekalmanfilter_k);

    /* MATLAB Function: '<S161>/runFastGradient' incorporates:
     *  Constant: '<S161>/AA_delay'
     *  Constant: '<S161>/BB_delay'
     *  Constant: '<S161>/L'
     *  Constant: '<S161>/LL_PP'
     *  Constant: '<S161>/LL_U_ref_PP'
     *  Constant: '<S161>/LL_ref_PP'
     *  Constant: '<S161>/MM'
     *  Constant: '<S161>/PP'
     *  Constant: '<S161>/TT_PP'
     *  Constant: '<S161>/V_max'
     *  Constant: '<S161>/betas'
     *  Constant: '<S161>/i_min'
     *  UnitDelay: '<S161>/Unit Delay'
     *  UnitDelay: '<S161>/Unit Delay1'
     */
    controller_template_DWork.sfEvent_k = CALL_EVENT;

    /* MATLAB Function 'z controller MPC FG/runFastGradient': '<S172>:1' */
    /*  ugly, but simulink needs fix output sizes for vectors */
    /*  number of outputs u */
    /*  number of delay steps */
    /*  prediction horizon */
    /*  predict non-delayed state */
    /* '<S172>:1:14' */
    temp_idx = (controller_template_P.AA_delay_Value_l[0] *
                controller_template_B.sf_discretekalmanfilter_k.state_est[0] +
                controller_template_P.AA_delay_Value_l[2] *
                controller_template_B.sf_discretekalmanfilter_k.state_est[1]) +
      (controller_template_P.BB_delay_Value_b[0] *
       controller_template_DWork.UnitDelay_DSTATE_l[0] +
       controller_template_P.BB_delay_Value_b[2] *
       controller_template_DWork.UnitDelay_DSTATE_l[1]);
    rtb_Saturation3 = (controller_template_P.AA_delay_Value_l[1] *
                       controller_template_B.sf_discretekalmanfilter_k.state_est[
                       0] + controller_template_P.AA_delay_Value_l[3] *
                       controller_template_B.sf_discretekalmanfilter_k.state_est[
                       1]) + (controller_template_P.BB_delay_Value_b[1] *
      controller_template_DWork.UnitDelay_DSTATE_l[0] +
      controller_template_P.BB_delay_Value_b[3] *
      controller_template_DWork.UnitDelay_DSTATE_l[1]);

    /*  TODO get U_ref from trajectory */
    /*  set optimization variables */
    /* '<S172>:1:21' */
    for (i = 0; i < 30; i++) {
      temp[i] = 0.0;
      temp[i] += controller_template_P.LL_PP_Value_j[(i << 1)] * temp_idx;
      temp[i] += controller_template_P.LL_PP_Value_j[(i << 1) + 1] *
        rtb_Saturation3;
      tmp_2[i] = 0.0;
      for (ireg = 0; ireg < 62; ireg++) {
        tmp_2[i] += controller_template_P.LL_ref_PP_Value_h[62 * i + ireg] *
          controller_template_B.X_ref_z[ireg];
      }
    }

    for (i = 0; i < 30; i++) {
      cos_yaw = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        cos_yaw += controller_template_P.LL_U_ref_PP_Value_o[30 * i + ireg] *
          0.0;
      }

      LL_PP_ref[i] = (temp[i] - tmp_2[i]) - cos_yaw;
    }

    /* '<S172>:1:22' */
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
    for (i = 0; i < 30; i++) {
      cos_yaw = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        cos_yaw += controller_template_P.TT_PP_Value_b[30 * ireg + i] *
          controller_template_DWork.UnitDelay1_DSTATE_g[ireg];
      }

      tmp_2[i] = cos_yaw + LL_PP_ref[i];
    }

    for (i = 0; i < 30; i++) {
      U = controller_template_DWork.UnitDelay1_DSTATE_g[i] - sin_yaw * tmp_2[i];
      cos_yaw = (controller_template_P.V_max_Value_i[i] <= U) || rtIsNaN(U) ?
        controller_template_P.V_max_Value_i[i] : U;
      rtb_SliderGain_c = (temp[i] >= cos_yaw) || rtIsNaN(cos_yaw) ? temp[i] :
        cos_yaw;
      V_ip[i] = rtb_SliderGain_c;
      V_i[i] = rtb_SliderGain_c;
      U_star[i] = U;
    }

    /*  now run the fast gradient method: */
    for (dz = 0; dz <= (int32_T)controller_template_P.i_min_Value_o - 1; dz++) {
      for (i = 0; i < 30; i++) {
        cos_yaw = 0.0;
        for (ireg = 0; ireg < 30; ireg++) {
          cos_yaw += controller_template_P.TT_PP_Value_b[30 * ireg + i] *
            V_ip[ireg];
        }

        tmp_2[i] = cos_yaw + LL_PP_ref[i];
      }

      /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
      /*      convergence result idea */
      for (i = 0; i < 30; i++) {
        U = V_ip[i] - sin_yaw * tmp_2[i];
        cos_yaw = (controller_template_P.V_max_Value_i[i] <= U) || rtIsNaN(U) ?
          controller_template_P.V_max_Value_i[i] : U;
        cos_yaw = (temp[i] >= cos_yaw) || rtIsNaN(cos_yaw) ? temp[i] : cos_yaw;
        U = controller_template_P.betas_Value_g[(int32_T)(1.0 + (real_T)dz) - 1]
          * (cos_yaw - V_i[i]);
        rtb_SliderGain_c = cos_yaw;
        cos_yaw += U;
        U_star[i] = U;
        V_i[i] = rtb_SliderGain_c;
        V_ip[i] = cos_yaw;
      }
    }

    /*  return values: */
    sin_yaw = 0.0;
    cos_yaw = 0.0;

    /*  plot(residuals) just for testing new convergence result idea */
    /* '<S172>:1:25' */
    /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
    /*  so don't forget to backtransform after termination: */
    /* '<S172>:1:32' */
    for (i = 0; i < 30; i++) {
      b_y[i] = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        b_y[i] += controller_template_P.TT_PP_Value_b[30 * i + ireg] * (0.5 *
          V_i[ireg]);
      }

      sin_yaw += b_y[i] * V_i[i];
      cos_yaw += LL_PP_ref[i] * V_i[i];
      U_star[i] = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        U_star[i] += controller_template_P.PP_Value_o[30 * ireg + i] * V_i[ireg];
      }
    }

    /*  save outputs for delayed system */
    /* '<S172>:1:38' */
    /*  set new initial guess */
    /* '<S172>:1:42' */
    /* '<S172>:1:44' */
    controller_template_B.u_opt = U_star[0];
    controller_template_B.J_star = ((temp_idx *
      controller_template_P.MM_Value_l[0] + rtb_Saturation3 *
      controller_template_P.MM_Value_l[1]) * temp_idx + (temp_idx *
      controller_template_P.MM_Value_l[2] + rtb_Saturation3 *
      controller_template_P.MM_Value_l[3]) * rtb_Saturation3) + (sin_yaw +
      cos_yaw);
    controller_template_B.u_buff_out[0] =
      controller_template_DWork.UnitDelay_DSTATE_l[1];
    controller_template_B.u_buff_out[1] = U_star[0];
    memcpy((void *)(&controller_template_B.V_init_out[0]), (void *)&V_i[1], 29U *
           sizeof(real_T));
    controller_template_B.V_init_out[29] = 0.0;

    /* End of MATLAB Function: '<S161>/runFastGradient' */

    /* Saturate: '<S162>/Saturation' */
    rtb_Saturation2_l =
      controller_template_B.sf_discretekalmanfilter_k.state_est[2] >=
      controller_template_P.Saturation_UpperSat_l ?
      controller_template_P.Saturation_UpperSat_l :
      controller_template_B.sf_discretekalmanfilter_k.state_est[2] <=
      controller_template_P.Saturation_LowerSat_cp ?
      controller_template_P.Saturation_LowerSat_cp :
      controller_template_B.sf_discretekalmanfilter_k.state_est[2];

    /* Sum: '<S149>/Sum2' */
    rtb_UnitDelay_g = controller_template_B.u_opt - rtb_Saturation2_l;

    /* UnitDelay: '<S160>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_n[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_lx, 9U * sizeof(real_T));

    /* Switch: '<S170>/Init' incorporates:
     *  UnitDelay: '<S170>/FixPt Unit Delay1'
     *  UnitDelay: '<S170>/FixPt Unit Delay2'
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

    /* End of Switch: '<S170>/Init' */

    /* MATLAB Function: '<S160>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.DataTypeConversion[8],
      controller_template_B.DataTypeConversion[11], rtb_Init_h, rtb_Init[3],
      controller_template_P.A_Value_k, controller_template_P.B_Value_f,
      controller_template_P.C_Value_b, controller_template_P.Q_Value_g,
      controller_template_P.R_Value_o, rtb_IntegerDelay3, rtb_UnitDelay1_n,
      &controller_template_B.sf_discretekalmanfilter_n,
      &controller_template_DWork.sf_discretekalmanfilter_n);

    /* MATLAB Function: '<S159>/runFastGradient' incorporates:
     *  Constant: '<S159>/AA_delay'
     *  Constant: '<S159>/BB_delay'
     *  Constant: '<S159>/L'
     *  Constant: '<S159>/LL_PP'
     *  Constant: '<S159>/LL_U_ref_PP'
     *  Constant: '<S159>/LL_ref_PP'
     *  Constant: '<S159>/MM'
     *  Constant: '<S159>/PP'
     *  Constant: '<S159>/TT_PP'
     *  Constant: '<S159>/V_max'
     *  Constant: '<S159>/betas'
     *  Constant: '<S159>/i_min'
     *  UnitDelay: '<S159>/Unit Delay'
     *  UnitDelay: '<S159>/Unit Delay1'
     */
    controller_template_DWork.sfEvent_n = CALL_EVENT;

    /* MATLAB Function 'yaw controller MPC FG/runFastGradient': '<S169>:1' */
    /*  ugly, but simulink needs fix output sizes for vectors */
    /*  number of outputs u */
    /*  number of delay steps */
    /*  prediction horizon */
    /*  predict non-delayed state */
    /* '<S169>:1:14' */
    for (i = 0; i < 2; i++) {
      tmp_3[i] = 0.0;
      for (ireg = 0; ireg < 6; ireg++) {
        tmp_3[i] += controller_template_P.BB_delay_Value_d[(ireg << 1) + i] *
          controller_template_DWork.UnitDelay_DSTATE_jz[ireg];
      }
    }

    temp_idx = (controller_template_P.AA_delay_Value_o[0] *
                controller_template_B.sf_discretekalmanfilter_n.state_est[0] +
                controller_template_P.AA_delay_Value_o[2] *
                controller_template_B.sf_discretekalmanfilter_n.state_est[1]) +
      tmp_3[0];
    rtb_Saturation3 = (controller_template_P.AA_delay_Value_o[1] *
                       controller_template_B.sf_discretekalmanfilter_n.state_est[
                       0] + controller_template_P.AA_delay_Value_o[3] *
                       controller_template_B.sf_discretekalmanfilter_n.state_est[
                       1]) + tmp_3[1];

    /*  TODO get U_ref from trajectory */
    /*  set optimization variables */
    /* '<S169>:1:21' */
    for (i = 0; i < 30; i++) {
      temp[i] = 0.0;
      temp[i] += controller_template_P.LL_PP_Value_j5[(i << 1)] * temp_idx;
      temp[i] += controller_template_P.LL_PP_Value_j5[(i << 1) + 1] *
        rtb_Saturation3;
      tmp_2[i] = 0.0;
      for (ireg = 0; ireg < 62; ireg++) {
        tmp_2[i] += controller_template_P.LL_ref_PP_Value_e[62 * i + ireg] *
          controller_template_B.X_ref_yaw[ireg];
      }
    }

    for (i = 0; i < 30; i++) {
      cos_yaw = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        cos_yaw += controller_template_P.LL_U_ref_PP_Value_b[30 * i + ireg] *
          0.0;
      }

      LL_PP_ref[i] = (temp[i] - tmp_2[i]) - cos_yaw;
    }

    /* '<S169>:1:22' */
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
    for (i = 0; i < 30; i++) {
      cos_yaw = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        cos_yaw += controller_template_P.TT_PP_Value_o[30 * ireg + i] *
          controller_template_DWork.UnitDelay1_DSTATE_js[ireg];
      }

      tmp_2[i] = cos_yaw + LL_PP_ref[i];
    }

    for (i = 0; i < 30; i++) {
      U = controller_template_DWork.UnitDelay1_DSTATE_js[i] - sin_yaw * tmp_2[i];
      cos_yaw = (controller_template_P.V_max_Value_f[i] <= U) || rtIsNaN(U) ?
        controller_template_P.V_max_Value_f[i] : U;
      rtb_SliderGain_c = (temp[i] >= cos_yaw) || rtIsNaN(cos_yaw) ? temp[i] :
        cos_yaw;
      V_ip[i] = rtb_SliderGain_c;
      V_i[i] = rtb_SliderGain_c;
      U_star[i] = U;
    }

    /*  now run the fast gradient method: */
    for (dz = 0; dz <= (int32_T)controller_template_P.i_min_Value_n - 1; dz++) {
      for (i = 0; i < 30; i++) {
        cos_yaw = 0.0;
        for (ireg = 0; ireg < 30; ireg++) {
          cos_yaw += controller_template_P.TT_PP_Value_o[30 * ireg + i] *
            V_ip[ireg];
        }

        tmp_2[i] = cos_yaw + LL_PP_ref[i];
      }

      /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
      /*      convergence result idea */
      for (i = 0; i < 30; i++) {
        U = V_ip[i] - sin_yaw * tmp_2[i];
        cos_yaw = (controller_template_P.V_max_Value_f[i] <= U) || rtIsNaN(U) ?
          controller_template_P.V_max_Value_f[i] : U;
        cos_yaw = (temp[i] >= cos_yaw) || rtIsNaN(cos_yaw) ? temp[i] : cos_yaw;
        U = controller_template_P.betas_Value_j[(int32_T)(1.0 + (real_T)dz) - 1]
          * (cos_yaw - V_i[i]);
        rtb_SliderGain_c = cos_yaw;
        cos_yaw += U;
        U_star[i] = U;
        V_i[i] = rtb_SliderGain_c;
        V_ip[i] = cos_yaw;
      }
    }

    /*  return values: */
    sin_yaw = 0.0;
    cos_yaw = 0.0;

    /*  plot(residuals) just for testing new convergence result idea */
    /* '<S169>:1:25' */
    /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
    /*  so don't forget to backtransform after termination: */
    /* '<S169>:1:32' */
    for (i = 0; i < 30; i++) {
      b_y[i] = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        b_y[i] += controller_template_P.TT_PP_Value_o[30 * i + ireg] * (0.5 *
          V_i[ireg]);
      }

      sin_yaw += b_y[i] * V_i[i];
      cos_yaw += LL_PP_ref[i] * V_i[i];
      U_star[i] = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        U_star[i] += controller_template_P.PP_Value_p[30 * ireg + i] * V_i[ireg];
      }
    }

    /*  save outputs for delayed system */
    /* '<S169>:1:38' */
    /*  set new initial guess */
    /* '<S169>:1:42' */
    /* '<S169>:1:44' */
    controller_template_B.u_opt_l = U_star[0];
    controller_template_B.J_star_h = ((temp_idx *
      controller_template_P.MM_Value_g[0] + rtb_Saturation3 *
      controller_template_P.MM_Value_g[1]) * temp_idx + (temp_idx *
      controller_template_P.MM_Value_g[2] + rtb_Saturation3 *
      controller_template_P.MM_Value_g[3]) * rtb_Saturation3) + (sin_yaw +
      cos_yaw);
    for (i = 0; i < 5; i++) {
      controller_template_B.u_buff_out_i[i] =
        controller_template_DWork.UnitDelay_DSTATE_jz[i + 1];
    }

    controller_template_B.u_buff_out_i[5] = U_star[0];
    memcpy((void *)(&controller_template_B.V_init_out_n[0]), (void *)&V_i[1],
           29U * sizeof(real_T));
    controller_template_B.V_init_out_n[29] = 0.0;

    /* End of MATLAB Function: '<S159>/runFastGradient' */

    /* Saturate: '<S160>/Saturation' */
    cos_yaw = controller_template_B.sf_discretekalmanfilter_n.state_est[2] >=
      controller_template_P.Saturation_UpperSat_o3 ?
      controller_template_P.Saturation_UpperSat_o3 :
      controller_template_B.sf_discretekalmanfilter_n.state_est[2] <=
      controller_template_P.Saturation_LowerSat_kn ?
      controller_template_P.Saturation_LowerSat_kn :
      controller_template_B.sf_discretekalmanfilter_n.state_est[2];

    /* Sum: '<S149>/Sum3' */
    sin_yaw = controller_template_B.u_opt_l - cos_yaw;

    /* Sum: '<S149>/Sum5' */
    controller_template_B.thrust_cmd_e = rtb_UnitDelay_g + yaw_rate_cmd_g;

    /* Update for Delay: '<S149>/Integer Delay' */
    controller_template_DWork.IntegerDelay_DSTATE = sumViol;

    /* Update for Delay: '<S149>/Integer Delay1' */
    controller_template_DWork.IntegerDelay1_DSTATE = rtb_SliderGain_l;

    /* Update for Delay: '<S149>/Integer Delay2' */
    controller_template_DWork.IntegerDelay2_DSTATE = rtb_UnitDelay_g;

    /* Update for Delay: '<S149>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE = sin_yaw;

    /* Update for UnitDelay: '<S156>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
           (&controller_template_B.sf_discretekalmanfilter_b.P_est[0]), sizeof
           (real_T) << 4U);

    /* Update for UnitDelay: '<S164>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S164>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
      controller_template_P.FixPtConstant_Value_h;

    /* Update for UnitDelay: '<S164>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
      controller_template_B.sf_discretekalmanfilter_b.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
      controller_template_B.sf_discretekalmanfilter_b.state_est[1];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
      controller_template_B.sf_discretekalmanfilter_b.state_est[2];

    /* Update for UnitDelay: '<S155>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE[0] =
      controller_template_B.sf_runFastGradient.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE[1] =
      controller_template_B.sf_runFastGradient.u_buff_out[1];
    controller_template_DWork.UnitDelay_DSTATE[2] =
      controller_template_B.sf_runFastGradient.u_buff_out[2];

    /* Update for UnitDelay: '<S155>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
           (&controller_template_B.sf_runFastGradient.V_init_out[0]), 30U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S158>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
           (&controller_template_B.sf_discretekalmanfilter_m.P_est[0]), sizeof
           (real_T) << 4U);

    /* Update for UnitDelay: '<S167>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S167>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
      controller_template_P.FixPtConstant_Value_o;

    /* Update for UnitDelay: '<S167>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[1];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[2];

    /* Update for UnitDelay: '<S157>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_j[0] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE_j[1] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[1];
    controller_template_DWork.UnitDelay_DSTATE_j[2] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[2];

    /* Update for UnitDelay: '<S157>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
           (&controller_template_B.sf_runFastGradient_d.V_init_out[0]), 30U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S162>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
           (&controller_template_B.sf_discretekalmanfilter_k.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S173>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S173>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
      controller_template_P.FixPtConstant_Value_p;

    /* Update for UnitDelay: '<S173>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
      controller_template_B.sf_discretekalmanfilter_k.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
      controller_template_B.sf_discretekalmanfilter_k.state_est[1];

    /* Update for UnitDelay: '<S161>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_l[0] =
      controller_template_B.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE_l[1] =
      controller_template_B.u_buff_out[1];

    /* Update for UnitDelay: '<S161>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
           (&controller_template_B.V_init_out[0]), 30U * sizeof(real_T));

    /* Update for UnitDelay: '<S160>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
           (&controller_template_B.sf_discretekalmanfilter_n.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S170>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S170>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
      controller_template_P.FixPtConstant_Value_n;

    /* Update for UnitDelay: '<S170>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[1];

    /* Update for UnitDelay: '<S159>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      controller_template_DWork.UnitDelay_DSTATE_jz[i] =
        controller_template_B.u_buff_out_i[i];
    }

    /* End of Update for UnitDelay: '<S159>/Unit Delay' */

    /* Update for UnitDelay: '<S159>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
           (&controller_template_B.V_init_out_n[0]), 30U * sizeof(real_T));

    /* End of Outputs for SubSystem: '<S9>/MAIN CONTROL LOOP1' */

    /* SignalConversion: '<S153>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFi_f[0] =
      controller_template_B.DataTypeConversion[0];
    rtb_TmpSignalConversionAtToFi_f[1] =
      controller_template_B.DataTypeConversion[3];
    rtb_TmpSignalConversionAtToFi_f[2] =
      controller_template_B.DataTypeConversion[7];
    rtb_TmpSignalConversionAtToFi_f[3] = controller_template_B.X_ref_x[0];
    rtb_TmpSignalConversionAtToFi_f[4] = sumViol;
    rtb_TmpSignalConversionAtToFi_f[5] =
      controller_template_B.DataTypeConversion[1];
    rtb_TmpSignalConversionAtToFi_f[6] =
      controller_template_B.DataTypeConversion[4];
    rtb_TmpSignalConversionAtToFi_f[7] =
      controller_template_B.DataTypeConversion[6];
    rtb_TmpSignalConversionAtToFi_f[8] = controller_template_B.X_ref_y[0];
    rtb_TmpSignalConversionAtToFi_f[9] = rtb_SliderGain_l;
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
    rtb_TmpSignalConversionAtToFi_f[17] = sin_yaw;

    /* ToFile: '<S153>/To File' */
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

    /* SignalConversion: '<S153>/TmpSignal ConversionAtTo File1Inport1' */
    rtb_TmpSignalConversionAtToFile[0] = rtb_SliderGain_m;
    rtb_TmpSignalConversionAtToFile[1] = rtb_SliderGain_h;
    rtb_TmpSignalConversionAtToFile[2] = rtb_Saturation2_l;
    rtb_TmpSignalConversionAtToFile[3] = cos_yaw;

    /* ToFile: '<S153>/To File1' */
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

    /* Gain: '<S153>/Gain' */
    controller_template_B.Gain[0] = controller_template_P.Gain_Gain_o *
      rtb_SliderGain_l;
    controller_template_B.Gain[1] = controller_template_P.Gain_Gain_o * sumViol;
    controller_template_B.Gain[2] = controller_template_P.Gain_Gain_o *
      controller_template_B.DataTypeConversion[6];
    controller_template_B.Gain[3] = controller_template_P.Gain_Gain_o *
      controller_template_B.DataTypeConversion[7];

    /* Gain: '<S153>/rad -> deg2' */
    controller_template_B.raddeg2[0] = controller_template_P.raddeg2_Gain_p *
      controller_template_B.DataTypeConversion[7];
    controller_template_B.raddeg2[1] = controller_template_P.raddeg2_Gain_p *
      controller_template_B.DataTypeConversion[10];
    controller_template_B.raddeg2[2] = controller_template_P.raddeg2_Gain_p *
      sumViol;

    /* Gain: '<S153>/rad -> deg1' */
    controller_template_B.raddeg1[0] = controller_template_P.raddeg1_Gain_a *
      controller_template_B.DataTypeConversion[6];
    controller_template_B.raddeg1[1] = controller_template_P.raddeg1_Gain_a *
      controller_template_B.DataTypeConversion[9];
    controller_template_B.raddeg1[2] = controller_template_P.raddeg1_Gain_a *
      rtb_SliderGain_l;

    /* Gain: '<S153>/rad -> deg3' */
    controller_template_B.raddeg3[0] = controller_template_P.raddeg3_Gain_k *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg3[1] = controller_template_P.raddeg3_Gain_k *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg3[2] = controller_template_P.raddeg3_Gain_k *
      sin_yaw;

    /* Gain: '<S153>/rad -> deg' */
    controller_template_B.raddeg[0] = controller_template_P.raddeg_Gain_k *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg[1] = controller_template_P.raddeg_Gain_k *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg[2] = controller_template_P.raddeg_Gain_k *
      controller_template_B.X_ref_yaw[0];
    controller_template_B.raddeg[3] = controller_template_P.raddeg_Gain_k *
      controller_template_B.X_ref_yaw[1];

    /* Outputs for Atomic SubSystem: '<S9>/decoupling and rotation' */
    /* Inport: '<S150>/bias_W' */
    controller_template_B.bias_W[0] = rtb_TmpSignalConversionAtToFile[0];
    controller_template_B.bias_W[1] = rtb_TmpSignalConversionAtToFile[1];
    controller_template_B.bias_W[2] = rtb_TmpSignalConversionAtToFile[2];
    controller_template_B.bias_W[3] = rtb_TmpSignalConversionAtToFile[3];

    /* Inport: '<S150>/cmd_W' */
    controller_template_B.cmd_W[0] = sumViol;
    controller_template_B.cmd_W[1] = rtb_SliderGain_l;
    controller_template_B.cmd_W[2] = controller_template_B.thrust_cmd_e;
    controller_template_B.cmd_W[3] = sin_yaw;

    /* MATLAB Function: '<S175>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S175>/g'
     */
    controller_template_DWork.sfEvent_f = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/decoupling /Embedded MATLAB Function': '<S177>:1' */
    /* '<S177>:1:4' */
    sin_yaw = controller_template_B.cmd_W[2] / (cos
      (controller_template_B.pitch_rot) * cos(controller_template_B.roll_rot));

    /* '<S177>:1:6' */
    controller_template_B.pitch_cmd_comp =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value_m / sin_yaw * controller_template_B.cmd_W[0];

    /* '<S177>:1:7' */
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

    /* MATLAB Function: '<S176>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_b = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S178>:1' */
    /* '<S178>:1:3' */
    sin_yaw = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S178>:1:4' */
    cos_yaw = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S178>:1:6' */
    /* '<S178>:1:8' */
    /* '<S178>:1:9' */
    controller_template_B.pitch_rot_k = cos_yaw *
      controller_template_B.pitch_cmd_comp + -sin_yaw *
      controller_template_B.roll_cmd_comp;

    /* '<S178>:1:10' */
    controller_template_B.roll_rot_a = sin_yaw *
      controller_template_B.pitch_cmd_comp + cos_yaw *
      controller_template_B.roll_cmd_comp;

    /* '<S178>:1:12' */
    /* '<S178>:1:13' */
    controller_template_B.pitch_bias_rot_e = cos_yaw *
      controller_template_B.bias_W[0] + -sin_yaw * controller_template_B.bias_W
      [1];

    /* '<S178>:1:14' */
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

  /* Sum: '<S7>/Sum5' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Gain: '<S7>/Gain5'
   */
  temp_idx = controller_template_P.Gain5_Gain *
    controller_template_B.DataTypeConversion[2] -
    controller_template_P.Constant1_Value_ih;

  /* Gain: '<S143>/Slider Gain' incorporates:
   *  Saturate: '<S7>/Saturation'
   */
  controller_template_B.SliderGain = (temp_idx >=
    controller_template_P.Saturation_UpperSat_pb ?
    controller_template_P.Saturation_UpperSat_pb : temp_idx <=
    controller_template_P.Saturation_LowerSat_h ?
    controller_template_P.Saturation_LowerSat_h : temp_idx) *
    controller_template_P.SliderGain_Gain_o;

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/gravity'
   *  Gain: '<S144>/Slider Gain'
   *  Gain: '<S145>/Slider Gain'
   *  Sum: '<S7>/Sum4'
   *  Sum: '<S7>/Sum6'
   */
  sin_yaw = ((controller_template_P.SliderGain_Gain_px *
              controller_template_P.Constant_Value_lf +
              controller_template_P.SliderGain_Gain_mn *
              controller_template_B.SliderGain) +
             controller_template_B.DataTypeConversion[29]) *
    controller_template_P.gravity_Value_ch;

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

  /* Switch: '<S142>/SwitchControl' incorporates:
   *  Constant: '<S142>/Constant'
   *  Constant: '<S7>/yaw_rate'
   *  Gain: '<S7>/yaw_cmd2yaw'
   */
  if (controller_template_P.Constant_Value_a3 >
      controller_template_P.SwitchControl_Threshold_ef) {
    cos_yaw = controller_template_P.yaw_cmd2yaw_Gain *
      controller_template_B.yaw_rate_cmd;
  } else {
    cos_yaw = controller_template_P.yaw_rate_Value;
  }

  /* End of Switch: '<S142>/SwitchControl' */

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
    controller_template_P.Gain1_Gain_eg);
  arg_cmd_out[1] = (real32_T)((controller_template_B.roll_cmd -
    controller_template_P.roll_offset_Value) *
    controller_template_P.roll_cmd2roll_Gain *
    controller_template_P.Gain2_Gain_a);
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

  /* Update for UnitDelay: '<S148>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S148>/FixPt Constant'
   */
  controller_template_DWork.FixPtUnitDelay2_DSTATE =
    controller_template_P.FixPtConstant_Value_i;

  /* Switch: '<S148>/Reset' */
  if (rtb_MultiportSwitch1 != 0.0) {
    /* Update for UnitDelay: '<S148>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S148>/Initial Condition'
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
    /* Update for UnitDelay: '<S148>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE[0] =
      controller_template_B.pitch_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[1] =
      controller_template_B.roll_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[2] =
      controller_template_B.thrust_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[3] =
      controller_template_B.yaw_rate_bias;
  }

  /* End of Switch: '<S148>/Reset' */

  /* external mode */
  {
    boolean_T rtmStopReq = FALSE;
    rtExtModeOneStep(controller_template_M->extModeInfo, 3, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(controller_template_M, TRUE);
    }
  }

  rtExtModeUploadCheckTrigger(3);

  {                                    /* Sample time: [0.02s, 0.0s] */
    rtExtModeUpload(0, controller_template_M->Timing.taskTime0);
  }

  if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.04s, 0.0s] */
    rtExtModeUpload(1, (((controller_template_M->Timing.clockTick1+
                          controller_template_M->Timing.clockTickH1*
                          4294967296.0)) * 0.04));
  }

  if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {/* Sample time: [0.08s, 0.0s] */
    rtExtModeUpload(2, (((controller_template_M->Timing.clockTick2+
                          controller_template_M->Timing.clockTickH2*
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
    /* Update absolute timer for sample time: [0.04s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.04, which is the step size
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

  if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.08s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.08, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    controller_template_M->Timing.clockTick2++;
    if (!controller_template_M->Timing.clockTick2) {
      controller_template_M->Timing.clockTickH2++;
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
  controller_template_M->Sizes.checksums[0] = (1311212718U);
  controller_template_M->Sizes.checksums[1] = (2167360693U);
  controller_template_M->Sizes.checksums[2] = (1551412072U);
  controller_template_M->Sizes.checksums[3] = (3939074620U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[84];
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
    systemRan[24] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[37] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[38] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[39] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[40] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[41] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[44] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[45] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[46] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[47] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[49] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[50] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[51] = (sysRanDType *)
      &controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC;
    systemRan[52] = &rtAlwaysEnabled;
    systemRan[53] = &rtAlwaysEnabled;
    systemRan[54] = &rtAlwaysEnabled;
    systemRan[55] = &rtAlwaysEnabled;
    systemRan[56] = &rtAlwaysEnabled;
    systemRan[57] = &rtAlwaysEnabled;
    systemRan[58] = &rtAlwaysEnabled;
    systemRan[59] = &rtAlwaysEnabled;
    systemRan[60] = &rtAlwaysEnabled;
    systemRan[61] = &rtAlwaysEnabled;
    systemRan[62] = &rtAlwaysEnabled;
    systemRan[63] = &rtAlwaysEnabled;
    systemRan[64] = &rtAlwaysEnabled;
    systemRan[65] = &rtAlwaysEnabled;
    systemRan[66] = &rtAlwaysEnabled;
    systemRan[67] = &rtAlwaysEnabled;
    systemRan[68] = &rtAlwaysEnabled;
    systemRan[69] = &rtAlwaysEnabled;
    systemRan[70] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[71] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[72] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[73] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[74] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[75] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[76] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[77] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[78] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[79] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[80] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[81] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[82] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[83] = (sysRanDType *)
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
    /* Start for UnitDelay: '<S44>/Unit Delay2' */
    controller_template_B.UnitDelay2 = controller_template_P.UnitDelay2_X0_g;

    /* Start for UnitDelay: '<S43>/Unit Delay2' */
    controller_template_B.UnitDelay2_p = controller_template_P.UnitDelay2_X0_b;

    /* Start for UnitDelay: '<S68>/Unit Delay2' */
    controller_template_B.UnitDelay2_o = controller_template_P.UnitDelay2_X0_d;

    /* End of Start for SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* Start for ToFile: '<S16>/To File' */
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

    /* Start for ToFile: '<S16>/To File1' */
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

    /* InitializeConditions for MATLAB Function: '<S15>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_bq = CALL_EVENT;
    controller_template_DWork.is_active_c26_Hquad_control_L_f = 0U;

    /* InitializeConditions for MATLAB Function: '<S115>/MATLAB Function' */
    controller__MATLABFunction_Init(&controller_template_DWork.sf_MATLABFunction);

    /* InitializeConditions for UnitDelay: '<S108>/Unit Delay' */
    controller_template_DWork.UnitDelay_2_DSTATE =
      controller_template_P.UnitDelay_2_X0;

    /* InitializeConditions for UnitDelay: '<S108>/Unit Delay' */
    controller_template_DWork.UnitDelay_3_DSTATE =
      controller_template_P.UnitDelay_3_X0;

    /* InitializeConditions for MATLAB Function: '<S112>/MATLAB Function' */
    controller_template_DWork.sfEvent_a = CALL_EVENT;
    controller_template_DWork.is_active_c18_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S108>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_i =
      controller_template_P.UnitDelay1_X0_ie;

    /* InitializeConditions for MATLAB Function: '<S108>/Next Ref' */
    controller_template_DWork.sfEvent_p = CALL_EVENT;
    controller_template_DWork.is_active_c35_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S116>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_g =
      controller_template_P.UnitDelay_X0_o;

    /* InitializeConditions for MATLAB Function: '<S116>/generate_X_ref_x' */
    controlle_generate_X_ref_x_Init
      (&controller_template_DWork.sf_generate_X_ref_x);

    /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_c =
      controller_template_P.UnitDelay_X0_e;

    /* InitializeConditions for MATLAB Function: '<S18>/generate_X_ref_x' */
    controlle_generate_X_ref_x_Init
      (&controller_template_DWork.sf_generate_X_ref_x_a);

    /* InitializeConditions for MATLAB Function: '<S116>/generate_X_ref_y' */
    controlle_generate_X_ref_y_Init
      (&controller_template_DWork.sf_generate_X_ref_y);

    /* InitializeConditions for MATLAB Function: '<S18>/generate_X_ref_y' */
    controlle_generate_X_ref_y_Init
      (&controller_template_DWork.sf_generate_X_ref_y_k);

    /* InitializeConditions for MATLAB Function: '<S116>/generate_X_ref_z' */
    controlle_generate_X_ref_z_Init
      (&controller_template_DWork.sf_generate_X_ref_z);

    /* InitializeConditions for MATLAB Function: '<S18>/generate_X_ref_z' */
    controlle_generate_X_ref_z_Init
      (&controller_template_DWork.sf_generate_X_ref_z_b);

    /* InitializeConditions for MATLAB Function: '<S116>/generate_X_ref_yaw' */
    control_generate_X_ref_yaw_Init
      (&controller_template_DWork.sf_generate_X_ref_yaw);

    /* InitializeConditions for MATLAB Function: '<S18>/generate_X_ref_yaw' */
    control_generate_X_ref_yaw_Init
      (&controller_template_DWork.sf_generate_X_ref_yaw_h);

    /* InitializeConditions for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* InitializeConditions for Delay: '<S11>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE_k =
      controller_template_P.IntegerDelay3_InitialCondition;

    /* InitializeConditions for MATLAB Function: '<S34>/MATLAB Function' */
    controller_template_DWork.sfEvent_ks = CALL_EVENT;
    controller_template_DWork.is_active_c28_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S34>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_bg, (void *)
           controller_template_P.UnitDelay1_X0, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S95>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
      controller_template_P.FixPtUnitDelay2_X0;

    /* InitializeConditions for UnitDelay: '<S95>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0] =
      controller_template_P.FixPtUnitDelay1_X0;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1] =
      controller_template_P.FixPtUnitDelay1_X0;

    /* InitializeConditions for MATLAB Function: '<S34>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter);

    /* InitializeConditions for UnitDelay: '<S31>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_h[0] =
      controller_template_P.UnitDelay1_X0_d[0];
    controller_template_DWork.UnitDelay1_DSTATE_h[1] =
      controller_template_P.UnitDelay1_X0_d[1];
    controller_template_DWork.UnitDelay1_DSTATE_h[2] =
      controller_template_P.UnitDelay1_X0_d[2];
    controller_template_DWork.UnitDelay1_DSTATE_h[3] =
      controller_template_P.UnitDelay1_X0_d[3];

    /* InitializeConditions for UnitDelay: '<S31>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE =
      controller_template_P.UnitDelay2_X0;

    /* InitializeConditions for MATLAB Function: '<S50>/MATLAB Function' */
    controller__MATLABFunction_Init
      (&controller_template_DWork.sf_MATLABFunction_e);

    /* InitializeConditions for UnitDelay: '<S44>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_c =
      controller_template_P.UnitDelay2_X0_g;

    /* InitializeConditions for MATLAB Function: '<S55>/MATLAB Function' */
    controller_template_DWork.sfEvent_ac = CALL_EVENT;
    controller_template_DWork.is_active_c7_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S44>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_cm = CALL_EVENT;
    controller_template_DWork.is_active_c1_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S43>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_m =
      controller_template_P.UnitDelay2_X0_b;

    /* InitializeConditions for MATLAB Function: '<S52>/MATLAB Function' */
    controller_template_DWork.sfEvent_kd = CALL_EVENT;
    controller_template_DWork.is_active_c26_controller_templa = 0U;

    /* InitializeConditions for MATLAB Function: '<S43>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_cr = CALL_EVENT;
    controller_template_DWork.is_active_c24_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S48>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_d =
      controller_template_P.UnitDelay2_X0_m;

    /* InitializeConditions for UnitDelay: '<S48>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_jv =
      controller_template_P.UnitDelay_X0;

    /* InitializeConditions for MATLAB Function: '<S29>/MATLAB Function' */
    controller_template_DWork.sfEvent_fp = CALL_EVENT;
    controller_template_DWork.is_active_c12_controller_templa = 0U;

    /* InitializeConditions for MATLAB Function: '<S73>/MATLAB Function' */
    controlle_MATLABFunction_l_Init
      (&controller_template_DWork.sf_MATLABFunction_l5);

    /* InitializeConditions for UnitDelay: '<S68>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_l =
      controller_template_P.UnitDelay2_X0_d;

    /* InitializeConditions for MATLAB Function: '<S76>/MATLAB Function' */
    controller_template_DWork.sfEvent_i = CALL_EVENT;
    controller_template_DWork.is_active_c5_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S68>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_cd = CALL_EVENT;
    controller_template_DWork.is_active_c2_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S72>/MATLAB Function' */
    controller_template_DWork.sfEvent_ab = CALL_EVENT;
    controller_template_DWork.is_active_c17_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S69>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_k =
      controller_template_P.UnitDelay2_X0_n;

    /* InitializeConditions for UnitDelay: '<S69>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_f =
      controller_template_P.UnitDelay_X0_f;

    /* InitializeConditions for MATLAB Function: '<S101>/MATLAB Function' */
    controlle_MATLABFunction_l_Init
      (&controller_template_DWork.sf_MATLABFunction_c);

    /* InitializeConditions for MATLAB Function: '<S97>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_k0 = CALL_EVENT;
    controller_template_DWork.is_active_c3_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S100>/MATLAB Function' */
    controller_template_DWork.sfEvent_jj = CALL_EVENT;
    controller_template_DWork.is_active_c16_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S98>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_b =
      controller_template_P.UnitDelay2_X0_o;

    /* InitializeConditions for UnitDelay: '<S98>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_fw =
      controller_template_P.UnitDelay_X0_i;

    /* InitializeConditions for UnitDelay: '<S33>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_lg =
      controller_template_P.UnitDelay_X0_m;

    /* InitializeConditions for MATLAB Function: '<S33>/MATLAB Function' */
    controller_template_DWork.sfEvent_g = CALL_EVENT;
    controller_template_DWork.is_active_c25_controller_templa = 0U;

    /* InitializeConditions for MATLAB Function: '<S33>/MATLAB Function1' */
    controller_template_DWork.sfEvent_d = CALL_EVENT;
    controller_template_DWork.is_active_c30_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S83>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_g =
      controller_template_P.UnitDelay2_X0_ng;

    /* InitializeConditions for MATLAB Function: '<S92>/MATLAB Function' */
    controller_template_DWork.sfEvent_l = CALL_EVENT;
    controller_template_DWork.is_active_c6_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S83>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_jv = CALL_EVENT;
    controller_template_DWork.is_active_c4_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S86>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_ga =
      controller_template_P.UnitDelay2_X0_i;

    /* InitializeConditions for UnitDelay: '<S86>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_p =
      controller_template_P.UnitDelay_X0_c;

    /* InitializeConditions for UnitDelay: '<S48>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_a =
      controller_template_P.UnitDelay1_X0_i;

    /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_a =
      controller_template_P.UnitDelay_X0_d;

    /* InitializeConditions for MATLAB Function: '<S49>/MATLAB Function1' */
    controller_template_DWork.sfEvent_h = CALL_EVENT;
    controller_template_DWork.is_active_c41_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S59>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_m[0] =
      controller_template_P.UnitDelay_X0_a[0];
    controller_template_DWork.UnitDelay_DSTATE_m[1] =
      controller_template_P.UnitDelay_X0_a[1];
    controller_template_DWork.UnitDelay_DSTATE_m[2] =
      controller_template_P.UnitDelay_X0_a[2];
    controller_template_DWork.UnitDelay_DSTATE_m[3] =
      controller_template_P.UnitDelay_X0_a[3];

    /* InitializeConditions for UnitDelay: '<S59>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j5, (void *)
           controller_template_P.UnitDelay1_X0_ic, sizeof(real_T) << 4U);

    /* InitializeConditions for UnitDelay: '<S60>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_m2 =
      controller_template_P.UnitDelay_X0_if;

    /* InitializeConditions for MATLAB Function: '<S60>/MATLAB Function' */
    controller_template_DWork.sfEvent_fc = CALL_EVENT;
    controller_template_DWork.is_active_c40_controller_templa = 0U;

    /* InitializeConditions for MATLAB Function: '<S62>/MATLAB Function' */
    controller_template_DWork.sfEvent_du = CALL_EVENT;
    controller_template_DWork.is_active_c43_controller_templa = 0U;

    /* InitializeConditions for MATLAB Function: '<S59>/MATLAB Function' */
    controller_template_DWork.sfEvent_cq = CALL_EVENT;
    controller_template_DWork.is_active_c42_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S69>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_ji =
      controller_template_P.UnitDelay1_X0_dy;

    /* InitializeConditions for UnitDelay: '<S86>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_c3 =
      controller_template_P.UnitDelay1_X0_j;

    /* InitializeConditions for UnitDelay: '<S98>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_m =
      controller_template_P.UnitDelay1_X0_f;

    /* End of InitializeConditions for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

    /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_e =
      controller_template_P.UnitDelay_X0_b;

    /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_x' */
    controlle_generate_X_ref_x_Init
      (&controller_template_DWork.sf_generate_X_ref_x_k);

    /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_y' */
    controlle_generate_X_ref_y_Init
      (&controller_template_DWork.sf_generate_X_ref_y_a);

    /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_yaw' */
    control_generate_X_ref_yaw_Init
      (&controller_template_DWork.sf_generate_X_ref_yaw_g);

    /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_z' */
    controlle_generate_X_ref_z_Init
      (&controller_template_DWork.sf_generate_X_ref_z_l);

    /* InitializeConditions for UnitDelay: '<S111>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_es =
      controller_template_P.UnitDelay_X0_l;

    /* InitializeConditions for UnitDelay: '<S111>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_o =
      controller_template_P.UnitDelay1_X0_js;

    /* InitializeConditions for MATLAB Function: '<S111>/MATLAB Function' */
    controller_template_DWork.sfEvent_jg = CALL_EVENT;
    controller_template_DWork.is_active_c11_controller_templa = 0U;

    /* InitializeConditions for Atomic SubSystem: '<S2>/decoupling and rotation' */
    /* InitializeConditions for MATLAB Function: '<S136>/MATLAB Function' */
    controller__MATLABFunction_Init
      (&controller_template_DWork.sf_MATLABFunction_p);

    /* InitializeConditions for MATLAB Function: '<S133>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_c = CALL_EVENT;
    controller_template_DWork.is_active_c9_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S134>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_j = CALL_EVENT;
    controller_template_DWork.is_active_c10_controller_templa = 0U;

    /* End of InitializeConditions for SubSystem: '<S2>/decoupling and rotation' */
    /* End of Start for SubSystem: '<Root>/FreeFlight Pos Ctrl' */

    /* Start for Enabled SubSystem: '<Root>/pos controller' */
    /* Start for ToFile: '<S153>/To File' */
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

    /* Start for ToFile: '<S153>/To File1' */
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

    /* InitializeConditions for MATLAB Function: '<S152>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent = CALL_EVENT;
    controller_template_DWork.is_active_c26_Hquad_control_LIB = 0U;

    /* InitializeConditions for Atomic SubSystem: '<S9>/MAIN CONTROL LOOP1' */
    /* InitializeConditions for Delay: '<S149>/Integer Delay' */
    controller_template_DWork.IntegerDelay_DSTATE =
      controller_template_P.IntegerDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S149>/Integer Delay1' */
    controller_template_DWork.IntegerDelay1_DSTATE =
      controller_template_P.IntegerDelay1_InitialCondition;

    /* InitializeConditions for Delay: '<S149>/Integer Delay2' */
    controller_template_DWork.IntegerDelay2_DSTATE =
      controller_template_P.IntegerDelay2_InitialCondition;

    /* InitializeConditions for Delay: '<S149>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE =
      controller_template_P.IntegerDelay3_InitialConditio_c;

    /* InitializeConditions for UnitDelay: '<S156>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
           controller_template_P.UnitDelay1_X0_c, sizeof(real_T) << 4U);

    /* InitializeConditions for UnitDelay: '<S164>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
      controller_template_P.FixPtUnitDelay2_X0_d;

    /* InitializeConditions for UnitDelay: '<S164>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
      controller_template_P.FixPtUnitDelay1_X0_f;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
      controller_template_P.FixPtUnitDelay1_X0_f;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
      controller_template_P.FixPtUnitDelay1_X0_f;

    /* InitializeConditions for MATLAB Function: '<S156>/discrete kalman filter' */
    con_discretekalmanfilter_k_Init
      (&controller_template_DWork.sf_discretekalmanfilter_b);

    /* InitializeConditions for UnitDelay: '<S155>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE[0] =
      controller_template_P.UnitDelay_X0_fc[0];
    controller_template_DWork.UnitDelay_DSTATE[1] =
      controller_template_P.UnitDelay_X0_fc[1];
    controller_template_DWork.UnitDelay_DSTATE[2] =
      controller_template_P.UnitDelay_X0_fc[2];

    /* InitializeConditions for UnitDelay: '<S155>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
           controller_template_P.UnitDelay1_X0_k, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S155>/runFastGradient' */
    controller_runFastGradient_Init
      (&controller_template_DWork.sf_runFastGradient);

    /* InitializeConditions for UnitDelay: '<S158>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
           controller_template_P.UnitDelay1_X0_fk, sizeof(real_T) << 4U);

    /* InitializeConditions for UnitDelay: '<S167>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
      controller_template_P.FixPtUnitDelay2_X0_n;

    /* InitializeConditions for UnitDelay: '<S167>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
      controller_template_P.FixPtUnitDelay1_X0_n;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
      controller_template_P.FixPtUnitDelay1_X0_n;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
      controller_template_P.FixPtUnitDelay1_X0_n;

    /* InitializeConditions for MATLAB Function: '<S158>/discrete kalman filter' */
    con_discretekalmanfilter_k_Init
      (&controller_template_DWork.sf_discretekalmanfilter_m);

    /* InitializeConditions for UnitDelay: '<S157>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_j[0] =
      controller_template_P.UnitDelay_X0_ik[0];
    controller_template_DWork.UnitDelay_DSTATE_j[1] =
      controller_template_P.UnitDelay_X0_ik[1];
    controller_template_DWork.UnitDelay_DSTATE_j[2] =
      controller_template_P.UnitDelay_X0_ik[2];

    /* InitializeConditions for UnitDelay: '<S157>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
           controller_template_P.UnitDelay1_X0_jc, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S157>/runFastGradient' */
    controller_runFastGradient_Init
      (&controller_template_DWork.sf_runFastGradient_d);

    /* InitializeConditions for UnitDelay: '<S162>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
           controller_template_P.UnitDelay1_X0_cw, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S173>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
      controller_template_P.FixPtUnitDelay2_X0_do;

    /* InitializeConditions for UnitDelay: '<S173>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
      controller_template_P.FixPtUnitDelay1_X0_c;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
      controller_template_P.FixPtUnitDelay1_X0_c;

    /* InitializeConditions for MATLAB Function: '<S162>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter_k);

    /* InitializeConditions for UnitDelay: '<S161>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_l[0] =
      controller_template_P.UnitDelay_X0_a2[0];
    controller_template_DWork.UnitDelay_DSTATE_l[1] =
      controller_template_P.UnitDelay_X0_a2[1];

    /* InitializeConditions for UnitDelay: '<S161>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
           controller_template_P.UnitDelay1_X0_b, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S161>/runFastGradient' */
    controller_template_DWork.sfEvent_k = CALL_EVENT;
    controller_template_DWork.is_active_c8_Hquad_control_LIB_ = 0U;

    /* InitializeConditions for UnitDelay: '<S160>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
           controller_template_P.UnitDelay1_X0_n, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S170>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
      controller_template_P.FixPtUnitDelay2_X0_i;

    /* InitializeConditions for UnitDelay: '<S170>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
      controller_template_P.FixPtUnitDelay1_X0_e;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
      controller_template_P.FixPtUnitDelay1_X0_e;

    /* InitializeConditions for MATLAB Function: '<S160>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter_n);

    /* InitializeConditions for UnitDelay: '<S159>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      controller_template_DWork.UnitDelay_DSTATE_jz[i] =
        controller_template_P.UnitDelay_X0_fj[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S159>/Unit Delay' */

    /* InitializeConditions for UnitDelay: '<S159>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
           controller_template_P.UnitDelay1_X0_o, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S159>/runFastGradient' */
    controller_template_DWork.sfEvent_n = CALL_EVENT;
    controller_template_DWork.is_active_c9_Hquad_control_LIB_ = 0U;

    /* End of InitializeConditions for SubSystem: '<S9>/MAIN CONTROL LOOP1' */

    /* InitializeConditions for Atomic SubSystem: '<S9>/decoupling and rotation' */
    /* InitializeConditions for MATLAB Function: '<S175>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_f = CALL_EVENT;
    controller_template_DWork.is_active_c1_Hquad_control_LIB_ = 0U;

    /* InitializeConditions for MATLAB Function: '<S176>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_b = CALL_EVENT;
    controller_template_DWork.is_active_c4_Hquad_control_LIB_ = 0U;

    /* End of InitializeConditions for SubSystem: '<S9>/decoupling and rotation' */
    /* End of Start for SubSystem: '<Root>/pos controller' */
  }

  /* InitializeConditions for UnitDelay: '<S148>/FixPt Unit Delay2' */
  controller_template_DWork.FixPtUnitDelay2_DSTATE =
    controller_template_P.FixPtUnitDelay2_X0_g;

  /* InitializeConditions for UnitDelay: '<S148>/FixPt Unit Delay1' */
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
  rtExtModeCheckInit(3);

  {
    boolean_T rtmStopReq = FALSE;
    rtExtModeWaitForStartPkt(controller_template_M->extModeInfo, 3, &rtmStopReq);
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

  /* Terminate for ToFile: '<S16>/To File' */
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

  /* Terminate for ToFile: '<S16>/To File1' */
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

  /* Terminate for ToFile: '<S153>/To File' */
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

  /* Terminate for ToFile: '<S153>/To File1' */
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
