/*
 * File: controller_template.cpp
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.613
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Aug  6 2011)
 * C/C++ source code generated on : Wed Jul 10 21:38:37 2013
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
static void controller_template_round_c(real_T x[4]);
static void controller_template_mrdivide_c(const real_T A[4], real_T B, real_T
  y[4]);
static void controller_template_round(real_T x[4]);
static void controller_template_mrdivide(const real_T A[4], real_T B, real_T y[4]);
static void controller_template_round_k(real_T x[4]);
static void controller_template_mrdivide_k(const real_T A[4], real_T B, real_T
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
 *    '<S73>/generate_X_ref_x'
 */
void controlle_generate_X_ref_x_Init(rtDW_generate_X_ref_x_controlle *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c19_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S17>/generate_X_ref_x'
 *    '<S73>/generate_X_ref_x'
 */
void controller_tem_generate_X_ref_x(const real_T rtu_traj_x[12], real_T rtu_idx,
  rtB_generate_X_ref_x_controller *localB, rtDW_generate_X_ref_x_controlle
  *localDW)
{
  int32_T i;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_x': '<S19>:1' */
  /* '<S19>:1:5' */
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
 *    '<S73>/generate_X_ref_y'
 */
void controlle_generate_X_ref_y_Init(rtDW_generate_X_ref_y_controlle *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c20_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S17>/generate_X_ref_y'
 *    '<S73>/generate_X_ref_y'
 */
void controller_tem_generate_X_ref_y(const real_T rtu_traj_y[12], real_T rtu_idx,
  rtB_generate_X_ref_y_controller *localB, rtDW_generate_X_ref_y_controlle
  *localDW)
{
  int32_T i;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_y': '<S20>:1' */
  /* '<S20>:1:5' */
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
 *    '<S73>/generate_X_ref_yaw'
 */
void control_generate_X_ref_yaw_Init(rtDW_generate_X_ref_yaw_control *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c21_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S17>/generate_X_ref_yaw'
 *    '<S73>/generate_X_ref_yaw'
 */
void controller_t_generate_X_ref_yaw(const real_T rtu_X_ref_yaw_unbounded[8],
  real_T rtu_yaw_meas, real_T rtu_idx, rtB_generate_X_ref_yaw_controll *localB,
  rtDW_generate_X_ref_yaw_control *localDW)
{
  real_T yaw_offset;
  int32_T i;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_yaw': '<S21>:1' */
  /* '<S21>:1:5' */
  /* '<S21>:1:6' */
  /* '<S21>:1:9' */
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

  /* '<S21>:1:11' */
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
 *    '<S73>/generate_X_ref_z'
 */
void controlle_generate_X_ref_z_Init(rtDW_generate_X_ref_z_controlle *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c22_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S17>/generate_X_ref_z'
 *    '<S73>/generate_X_ref_z'
 */
void controller_tem_generate_X_ref_z(const real_T rtu_traj_z[8], real_T rtu_idx,
  rtB_generate_X_ref_z_controller *localB, rtDW_generate_X_ref_z_controlle
  *localDW)
{
  int32_T i;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_z': '<S22>:1' */
  /* '<S22>:1:5' */
  for (i = 0; i < 31; i++) {
    localB->X_ref_z[(i << 1)] = rtu_traj_z[((int32_T)(rtu_idx + (real_T)i) - 1) <<
      1];
    localB->X_ref_z[1 + (i << 1)] = rtu_traj_z[(((int32_T)(rtu_idx + (real_T)i)
      - 1) << 1) + 1];
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S37>/MATLAB Function'
 *    '<S50>/MATLAB Function'
 */
void controller__MATLABFunction_Init(rtDW_MATLABFunction_controller_ *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c26_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S37>/MATLAB Function'
 *    '<S50>/MATLAB Function'
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

  /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/PitchPropagateFF/MATLAB Function': '<S38>:1' */
  /* '<S38>:1:4' */
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
 *    '<S35>/MATLAB Function'
 *    '<S72>/MATLAB Function'
 *    '<S85>/MATLAB Function'
 */
void controlle_MATLABFunction_c_Init(rtDW_MATLABFunction_controlle_a *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c15_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S35>/MATLAB Function'
 *    '<S72>/MATLAB Function'
 *    '<S85>/MATLAB Function'
 */
void controller_tem_MATLABFunction_e(real_T rtu_u, real_T rtu_thres,
  rtB_MATLABFunction_controller_m *localB, rtDW_MATLABFunction_controlle_a
  *localDW)
{
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation/MATLAB Function': '<S42>:1' */
  if (rtu_u >= rtu_thres) {
    /* '<S42>:1:3' */
    /* '<S42>:1:4' */
    localB->y = 0.0;
  } else {
    /* '<S42>:1:6' */
    localB->y = rtu_u;
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S27>/discrete kalman filter'
 *    '<S104>/discrete kalman filter'
 *    '<S106>/discrete kalman filter'
 */
void contr_discretekalmanfilter_Init(rtDW_discretekalmanfilter_contr *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c27_controller_templa = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S27>/discrete kalman filter'
 *    '<S104>/discrete kalman filter'
 *    '<S106>/discrete kalman filter'
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

  /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter': '<S65>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S65>:1:10' */
  for (i = 0; i < 3; i++) {
    /* SignalConversion: '<S65>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = ((rtu_A[i + 3] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
            6] * rtu_state_g) + rtu_B[i] * rtu_u;
  }

  /* '<S65>:1:11' */
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
  /* '<S65>:1:14' */
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

  /* '<S65>:1:15' */
  /* '<S65>:1:16' */
  for (i = 0; i < 9; i++) {
    I[i] = 0;
  }

  I[0] = 1;
  I[4] = 1;
  I[8] = 1;
  for (i = 0; i < 2; i++) {
    tmp[i] = rtu_C[i + 4] * x[2] + (rtu_C[i + 2] * x[1] + rtu_C[i] * x[0]);
  }

  /* SignalConversion: '<S65>/TmpSignal ConversionAt SFunction Inport8' */
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
 *    '<S15>/Embedded MATLAB Function'
 *    '<S96>/Embedded MATLAB Function'
 */
void con_EmbeddedMATLABFunction_Init(rtDW_EmbeddedMATLABFunction_con *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c26_Hquad_control_LIB = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S15>/Embedded MATLAB Function'
 *    '<S96>/Embedded MATLAB Function'
 */
void controll_EmbeddedMATLABFunction(real_T rtu_roll, real_T rtu_pitch, real_T
  rtu_pitch_bias, real_T rtu_roll_bias, real_T rtu_yaw,
  rtB_EmbeddedMATLABFunction_cont *localB, rtDW_EmbeddedMATLABFunction_con
  *localDW)
{
  real_T sin_yaw;
  real_T cos_yaw;
  localDW->sfEvent = CALL_EVENT;

  /* MATLAB Function 'rotate to world frame/Embedded MATLAB Function': '<S90>:1' */
  /* '<S90>:1:5' */
  sin_yaw = sin(rtu_yaw);

  /* '<S90>:1:6' */
  cos_yaw = cos(rtu_yaw);

  /* '<S90>:1:8' */
  /* '<S90>:1:10' */
  /* '<S90>:1:11' */
  localB->pitch_rot = cos_yaw * rtu_pitch + sin_yaw * rtu_roll;

  /* '<S90>:1:12' */
  localB->roll_rot = -sin_yaw * rtu_pitch + cos_yaw * rtu_roll;

  /* '<S90>:1:14' */
  /* '<S90>:1:15' */
  localB->pitch_bias_rot = cos_yaw * rtu_pitch_bias + sin_yaw * rtu_roll_bias;

  /* '<S90>:1:16' */
  localB->roll_bias_rot = -sin_yaw * rtu_pitch_bias + cos_yaw * rtu_roll_bias;
}

/*
 * Initial conditions for atomic system:
 *    '<S99>/runFastGradient'
 *    '<S101>/runFastGradient'
 */
void controller_runFastGradient_Init(rtDW_runFastGradient_controller *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c6_Hquad_control_LIB_ = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S99>/runFastGradient'
 *    '<S101>/runFastGradient'
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

  /* MATLAB Function 'x controller MPC FG  /runFastGradient': '<S107>:1' */
  /*  ugly, but simulink needs fix output sizes for vectors */
  /*  number of outputs u */
  /*  number of delay steps */
  /*  prediction horizon */
  /*  predict non-delayed state */
  /* '<S107>:1:14' */
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
  /* '<S107>:1:21' */
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

  /* '<S107>:1:22' */
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
  /* '<S107>:1:25' */
  /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
  /*  so don't forget to backtransform after termination: */
  /* '<S107>:1:32' */
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
  /* '<S107>:1:38' */
  /*  set new initial guess */
  /* '<S107>:1:42' */
  /* '<S107>:1:44' */
  localB->u_opt = U_star[0];
  localB->J_star = ((y[0] * x_predicted_idx + y[1] * x_predicted_idx_0) + y[2] *
                    x_predicted_idx_1) + (L_inv + d_y);
  localB->u_buff_out[0] = rtu_u_buff[1];
  localB->u_buff_out[1] = rtu_u_buff[2];
  localB->u_buff_out[2] = U_star[0];
  memcpy((void *)(&localB->V_init_out[0]), (void *)&V_i[1], 29U * sizeof(real_T));
  localB->V_init_out[29] = 0.0;
}

/* Function for MATLAB Function: '<S100>/discrete kalman filter' */
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
 *    '<S100>/discrete kalman filter'
 *    '<S102>/discrete kalman filter'
 */
void con_discretekalmanfilter_k_Init(rtDW_discretekalmanfilter_con_c *localDW)
{
  localDW->sfEvent = CALL_EVENT;
  localDW->is_active_c11_Hquad_control_LIB = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S100>/discrete kalman filter'
 *    '<S102>/discrete kalman filter'
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

  /* MATLAB Function 'x states estimator bias/discrete kalman filter': '<S109>:1' */
  /*  Kalman filter according to Welch & Bishop, An Introduction to the Kalman */
  /*  Filter */
  /*  Time update */
  /* '<S109>:1:10' */
  for (i = 0; i < 4; i++) {
    /* SignalConversion: '<S109>/TmpSignal ConversionAt SFunction Inport10' */
    x[i] = (((rtu_A[i + 4] * rtu_state[1] + rtu_A[i] * rtu_state[0]) + rtu_A[i +
             8] * rtu_state[2]) + rtu_A[i + 12] * rtu_state_m) + rtu_B[i] *
      rtu_u;
  }

  /* '<S109>:1:11' */
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
  /* '<S109>:1:14' */
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

  /* '<S109>:1:15' */
  /* '<S109>:1:16' */
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

  /* SignalConversion: '<S109>/TmpSignal ConversionAt SFunction Inport8' */
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

/* Function for MATLAB Function: '<S29>/Ctrl_Xdir' */
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

/* Function for MATLAB Function: '<S29>/Ctrl_Xdir' */
static void controller_template_mrdivide(const real_T A[4], real_T B, real_T y[4])
{
  y[0] = A[0] / B;
  y[1] = A[1] / B;
  y[2] = A[2] / B;
  y[3] = A[3] / B;
}

/* Function for MATLAB Function: '<S45>/Ctrl_Xdir' */
static void controller_template_round_k(real_T x[4])
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

/* Function for MATLAB Function: '<S45>/Ctrl_Xdir' */
static void controller_template_mrdivide_k(const real_T A[4], real_T B, real_T
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
  real_T rtb_Add;
  real_T rtb_SliderGain_p;
  real_T rtb_Sum2_m;
  real_T rtb_Sum2_m2;
  real_T rtb_TmpSignalConversionAtToFi_p[4];
  real_T rtb_Add_k;
  real_T rtb_SliderGain_m;
  real_T rtb_IntegerDelay3_c;
  real_T rtb_UnitDelay1_d[9];
  real_T rtb_Init_jd[2];
  real_T rtb_bias_W[4];
  real_T rtb_Add_c;
  real_T rtb_SliderGain_n4;
  real_T rtb_TmpSignalConversionAtToFi_f[18];
  real_T rtb_TmpSignalConversionAtToFi_a[18];
  int32_T dz;
  real_T X[4];
  int32_T flag_oob;
  real_T tolerance;
  int32_T minreg;
  real_T abspos;
  real_T sumViol;
  int32_T isinside;
  int32_T ireg;
  int32_T exitg;
  real_T Hi[400];
  real_T Ki[100];
  real_T U;
  real_T Hi_0[200];
  real_T U_0;
  real_T Hi_1[100];
  real_T LL_PP_ref[30];
  real_T U_star[30];
  real_T V_i[30];
  real_T V_ip[30];
  real_T b_y[30];
  real_T rtb_MultiportSwitch1;
  real_T rtb_MultiportSwitch2;
  real_T rtb_SliderGain_n;
  real_T rtb_Sum_c;
  real_T rtb_Sum_f;
  real_T rtb_X_ref_y[93];
  real_T rtb_X_ref_z[62];
  real_T rtb_X_ref_x[93];
  real_T rtb_X_ref_yaw[62];
  real_T rtb_yaw_ref;
  real_T rtb_Product_l;
  real_T rtb_Saturation2_l;
  real_T rtb_UnitDelay_g;
  real_T rtb_UnitDelay2_a;
  real_T rtb_SliderGain_e3;
  real_T rtb_Saturation_n;
  real_T rtb_roll_cmd_c;
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

  /* Switch: '<S92>/Init' incorporates:
   *  Constant: '<S92>/Initial Condition'
   *  Logic: '<S92>/FixPt Logical Operator'
   *  UnitDelay: '<S92>/FixPt Unit Delay1'
   *  UnitDelay: '<S92>/FixPt Unit Delay2'
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

  /* End of Switch: '<S92>/Init' */
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
      /* InitializeConditions for MATLAB Function: '<S15>/Embedded MATLAB Function' */
      con_EmbeddedMATLABFunction_Init
        (&controller_template_DWork.sf_EmbeddedMATLABFunction);

      /* InitializeConditions for MATLAB Function: '<S72>/MATLAB Function' */
      controlle_MATLABFunction_c_Init
        (&controller_template_DWork.sf_MATLABFunction);

      /* InitializeConditions for UnitDelay: '<S69>/Unit Delay' */
      controller_template_DWork.UnitDelay_2_DSTATE =
        controller_template_P.UnitDelay_2_X0;

      /* InitializeConditions for UnitDelay: '<S69>/Unit Delay' */
      controller_template_DWork.UnitDelay_3_DSTATE =
        controller_template_P.UnitDelay_3_X0;

      /* InitializeConditions for MATLAB Function: '<S69>/Next Ref' */
      controller_template_DWork.sfEvent_p = CALL_EVENT;
      controller_template_DWork.is_active_c35_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S73>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_g =
        controller_template_P.UnitDelay_X0_o;

      /* InitializeConditions for MATLAB Function: '<S73>/generate_X_ref_x' */
      controlle_generate_X_ref_x_Init
        (&controller_template_DWork.sf_generate_X_ref_x);

      /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_e =
        controller_template_P.UnitDelay_X0_b;

      /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_x' */
      controlle_generate_X_ref_x_Init
        (&controller_template_DWork.sf_generate_X_ref_x_k);

      /* InitializeConditions for MATLAB Function: '<S73>/generate_X_ref_y' */
      controlle_generate_X_ref_y_Init
        (&controller_template_DWork.sf_generate_X_ref_y);

      /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_y' */
      controlle_generate_X_ref_y_Init
        (&controller_template_DWork.sf_generate_X_ref_y_a);

      /* InitializeConditions for MATLAB Function: '<S73>/generate_X_ref_z' */
      controlle_generate_X_ref_z_Init
        (&controller_template_DWork.sf_generate_X_ref_z);

      /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_z' */
      controlle_generate_X_ref_z_Init
        (&controller_template_DWork.sf_generate_X_ref_z_l);

      /* InitializeConditions for MATLAB Function: '<S73>/generate_X_ref_yaw' */
      control_generate_X_ref_yaw_Init
        (&controller_template_DWork.sf_generate_X_ref_yaw);

      /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_yaw' */
      control_generate_X_ref_yaw_Init
        (&controller_template_DWork.sf_generate_X_ref_yaw_g);

      /* InitializeConditions for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
      /* InitializeConditions for Delay: '<S11>/Integer Delay3' */
      controller_template_DWork.IntegerDelay3_DSTATE_k =
        controller_template_P.IntegerDelay3_InitialCondition;

      /* InitializeConditions for MATLAB Function: '<S27>/MATLAB Function' */
      controller_template_DWork.sfEvent_ks = CALL_EVENT;
      controller_template_DWork.is_active_c28_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S27>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_bg, (void *)
             controller_template_P.UnitDelay1_X0, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S64>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
        controller_template_P.FixPtUnitDelay2_X0;

      /* InitializeConditions for UnitDelay: '<S64>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0] =
        controller_template_P.FixPtUnitDelay1_X0;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1] =
        controller_template_P.FixPtUnitDelay1_X0;

      /* InitializeConditions for MATLAB Function: '<S27>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter);

      /* InitializeConditions for MATLAB Function: '<S35>/MATLAB Function' */
      controlle_MATLABFunction_c_Init
        (&controller_template_DWork.sf_MATLABFunction_e);

      /* InitializeConditions for UnitDelay: '<S30>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE =
        controller_template_P.UnitDelay2_X0;

      /* InitializeConditions for MATLAB Function: '<S40>/MATLAB Function' */
      controller_template_DWork.sfEvent_a = CALL_EVENT;
      controller_template_DWork.is_active_c7_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S30>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_cm = CALL_EVENT;
      controller_template_DWork.is_active_c1_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S29>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_m =
        controller_template_P.UnitDelay2_X0_b;

      /* InitializeConditions for MATLAB Function: '<S37>/MATLAB Function' */
      controller__MATLABFunction_Init
        (&controller_template_DWork.sf_MATLABFunction_i);

      /* InitializeConditions for MATLAB Function: '<S29>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_cr = CALL_EVENT;
      controller_template_DWork.is_active_c24_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S34>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_d =
        controller_template_P.UnitDelay2_X0_m;

      /* InitializeConditions for UnitDelay: '<S34>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_jv =
        controller_template_P.UnitDelay_X0;

      /* InitializeConditions for UnitDelay: '<S45>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_l =
        controller_template_P.UnitDelay2_X0_d;

      /* InitializeConditions for MATLAB Function: '<S50>/MATLAB Function' */
      controller__MATLABFunction_Init
        (&controller_template_DWork.sf_MATLABFunction_k);

      /* InitializeConditions for MATLAB Function: '<S45>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_cd = CALL_EVENT;
      controller_template_DWork.is_active_c2_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S46>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_k =
        controller_template_P.UnitDelay2_X0_n;

      /* InitializeConditions for UnitDelay: '<S46>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_f =
        controller_template_P.UnitDelay_X0_f;

      /* InitializeConditions for MATLAB Function: '<S66>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_k0 = CALL_EVENT;
      controller_template_DWork.is_active_c3_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S67>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_b =
        controller_template_P.UnitDelay2_X0_o;

      /* InitializeConditions for UnitDelay: '<S67>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_fw =
        controller_template_P.UnitDelay_X0_i;

      /* InitializeConditions for UnitDelay: '<S26>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_lg =
        controller_template_P.UnitDelay_X0_m;

      /* InitializeConditions for MATLAB Function: '<S26>/MATLAB Function' */
      controller_template_DWork.sfEvent_g = CALL_EVENT;
      controller_template_DWork.is_active_c25_controller_templa = 0U;

      /* InitializeConditions for MATLAB Function: '<S26>/MATLAB Function1' */
      controller_template_DWork.sfEvent_d = CALL_EVENT;
      controller_template_DWork.is_active_c30_controller_templa = 0U;

      /* InitializeConditions for UnitDelay: '<S52>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_g =
        controller_template_P.UnitDelay2_X0_ng;

      /* InitializeConditions for MATLAB Function: '<S61>/MATLAB Function' */
      controller_template_DWork.sfEvent_l = CALL_EVENT;
      controller_template_DWork.is_active_c6_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S52>/Ctrl_Xdir' */
      controller_template_DWork.sfEvent_jv = CALL_EVENT;
      controller_template_DWork.is_active_c4_controller_templat = 0U;

      /* InitializeConditions for UnitDelay: '<S55>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_ga =
        controller_template_P.UnitDelay2_X0_i;

      /* InitializeConditions for UnitDelay: '<S55>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_p =
        controller_template_P.UnitDelay_X0_c;

      /* InitializeConditions for UnitDelay: '<S34>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_a =
        controller_template_P.UnitDelay1_X0_i;

      /* InitializeConditions for UnitDelay: '<S46>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_ji =
        controller_template_P.UnitDelay1_X0_d;

      /* InitializeConditions for UnitDelay: '<S55>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_c3 =
        controller_template_P.UnitDelay1_X0_j;

      /* InitializeConditions for UnitDelay: '<S67>/Unit Delay1' */
      controller_template_DWork.UnitDelay1_DSTATE_m =
        controller_template_P.UnitDelay1_X0_f;

      /* End of InitializeConditions for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

      /* InitializeConditions for Atomic SubSystem: '<S2>/decoupling and rotation' */
      /* InitializeConditions for MATLAB Function: '<S85>/MATLAB Function' */
      controlle_MATLABFunction_c_Init
        (&controller_template_DWork.sf_MATLABFunction_p);

      /* InitializeConditions for MATLAB Function: '<S82>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_c = CALL_EVENT;
      controller_template_DWork.is_active_c9_controller_templat = 0U;

      /* InitializeConditions for MATLAB Function: '<S83>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_j = CALL_EVENT;
      controller_template_DWork.is_active_c10_controller_templa = 0U;

      /* End of InitializeConditions for SubSystem: '<S2>/decoupling and rotation' */
      controller_template_DWork.FreeFlightPosCtrl_MODE = TRUE;
    }

    /* MATLAB Function: '<S15>/Embedded MATLAB Function' */
    controll_EmbeddedMATLABFunction(controller_template_B.DataTypeConversion[6],
      controller_template_B.DataTypeConversion[7], rtb_Init[0], rtb_Init[1],
      controller_template_B.DataTypeConversion[8],
      &controller_template_B.sf_EmbeddedMATLABFunction,
      &controller_template_DWork.sf_EmbeddedMATLABFunction);

    /* Sum: '<S72>/Add' incorporates:
     *  Constant: '<S72>/Constant'
     *  Gain: '<S76>/Slider Gain'
     */
    rtb_Add = controller_template_B.DataTypeConversion[0] -
      controller_template_P.SliderGain_Gain_e *
      controller_template_P.Constant_Value_i;

    /* Gain: '<S77>/Slider Gain' incorporates:
     *  Constant: '<S72>/Constant1'
     */
    rtb_SliderGain_p = controller_template_P.SliderGain_Gain_jr *
      controller_template_P.Constant1_Value_e;

    /* MATLAB Function: '<S72>/MATLAB Function' */
    controller_tem_MATLABFunction_e(rtb_Add, rtb_SliderGain_p,
      &controller_template_B.sf_MATLABFunction,
      &controller_template_DWork.sf_MATLABFunction);

    /* UnitDelay: '<S69>/Unit Delay' */
    controller_template_B.y_ref = controller_template_DWork.UnitDelay_2_DSTATE;

    /* UnitDelay: '<S69>/Unit Delay' */
    controller_template_B.z_ref = controller_template_DWork.UnitDelay_3_DSTATE;

    /* Gain: '<S71>/Slider Gain' incorporates:
     *  Constant: '<S69>/Constant'
     */
    rtb_SliderGain_n = controller_template_P.SliderGain_Gain_h *
      controller_template_P.Constant_Value_le;

    /* MATLAB Function: '<S69>/Next Ref' incorporates:
     *  Saturate: '<S72>/Saturation3'
     */
    controller_template_DWork.sfEvent_p = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Next Ref': '<S70>:1' */
    if (fabs(controller_template_B.DataTypeConversion[1] -
             controller_template_B.y_ref) > rtb_SliderGain_n) {
      /* '<S70>:1:3' */
      /* '<S70>:1:4' */
      i = 1;
    } else {
      /* '<S70>:1:6' */
      i = 0;

      /*  in position */
    }

    if (fabs(controller_template_B.DataTypeConversion[2] -
             controller_template_B.z_ref) > rtb_SliderGain_n) {
      /* '<S70>:1:9' */
      /* '<S70>:1:10' */
      dz = 1;
    } else {
      /* '<S70>:1:12' */
      dz = 0;

      /*  in position */
    }

    if ((i != 0) || (dz != 0) || ((controller_template_B.sf_MATLABFunction.y >=
          controller_template_P.Saturation3_UpperSat_f ?
          controller_template_P.Saturation3_UpperSat_f :
          controller_template_B.sf_MATLABFunction.y <=
          controller_template_P.Saturation3_LowerSat_lw ?
          controller_template_P.Saturation3_LowerSat_lw :
          controller_template_B.sf_MATLABFunction.y) != 0.0)) {
      /* '<S70>:1:16' */
      /* '<S70>:1:17' */
      controller_template_B.en = 0.0;

      /*  not yet in position, don't change reference */
    } else {
      /* '<S70>:1:19' */
      controller_template_B.en = 1.0;

      /*  in position, both deviations < thres, change ref. point. */
    }

    /* End of MATLAB Function: '<S69>/Next Ref' */

    /* Sum: '<S73>/Sum' incorporates:
     *  UnitDelay: '<S73>/Unit Delay'
     */
    rtb_Sum_c = controller_template_B.en +
      controller_template_DWork.UnitDelay_DSTATE_g;

    /* Sum: '<S73>/Sum2' incorporates:
     *  Constant: '<S73>/Constant1'
     *  Constant: '<S73>/total_samples'
     *  Math: '<S73>/Math Function'
     */
    rtb_Sum2_m = rt_modd_snf(rtb_Sum_c,
      controller_template_P.total_samples_Value) +
      controller_template_P.Constant1_Value_mu;

    /* MATLAB Function: '<S73>/generate_X_ref_x' */
    controller_tem_generate_X_ref_x(controller_template_P.X_ref_x_Value,
      rtb_Sum2_m, &controller_template_B.sf_generate_X_ref_x,
      &controller_template_DWork.sf_generate_X_ref_x);

    /* Sum: '<S73>/Add3' */
    for (i = 0; i < 93; i++) {
      rtb_X_ref_x[i] = controller_template_B.sf_generate_X_ref_x.X_ref_x[i] +
        controller_template_B.X_ref_x[i];
    }

    /* End of Sum: '<S73>/Add3' */

    /* Sum: '<S17>/Sum' incorporates:
     *  Constant: '<S17>/Constant'
     *  UnitDelay: '<S17>/Unit Delay'
     */
    rtb_Sum_f = controller_template_P.Constant_Value_kh +
      controller_template_DWork.UnitDelay_DSTATE_e;

    /* Sum: '<S17>/Sum2' incorporates:
     *  Constant: '<S17>/Constant1'
     *  Constant: '<S17>/total_samples'
     *  Math: '<S17>/Math Function'
     */
    rtb_Sum2_m2 = rt_modd_snf(rtb_Sum_f,
      controller_template_P.total_samples_Value_k) +
      controller_template_P.Constant1_Value_h;

    /* MATLAB Function: '<S17>/generate_X_ref_x' */
    controller_tem_generate_X_ref_x(controller_template_P.X_ref_x_Value_k,
      rtb_Sum2_m2, &controller_template_B.sf_generate_X_ref_x_k,
      &controller_template_DWork.sf_generate_X_ref_x_k);

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_1_Threshold) {
      controller_template_B.x_ref = rtb_X_ref_x[0];
    } else {
      controller_template_B.x_ref =
        controller_template_B.sf_generate_X_ref_x_k.X_ref_x[0];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* MATLAB Function: '<S73>/generate_X_ref_y' */
    controller_tem_generate_X_ref_y(controller_template_P.X_ref_y_Value,
      rtb_Sum2_m, &controller_template_B.sf_generate_X_ref_y,
      &controller_template_DWork.sf_generate_X_ref_y);

    /* Sum: '<S73>/Add2' */
    for (i = 0; i < 93; i++) {
      rtb_X_ref_y[i] = controller_template_B.sf_generate_X_ref_y.X_ref_y[i] +
        controller_template_B.X_ref_y[i];
    }

    /* End of Sum: '<S73>/Add2' */

    /* MATLAB Function: '<S17>/generate_X_ref_y' */
    controller_tem_generate_X_ref_y(controller_template_P.X_ref_y_Value_e,
      rtb_Sum2_m2, &controller_template_B.sf_generate_X_ref_y_a,
      &controller_template_DWork.sf_generate_X_ref_y_a);

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_2_Threshold) {
      controller_template_B.y_ref_h = rtb_X_ref_y[0];
    } else {
      controller_template_B.y_ref_h =
        controller_template_B.sf_generate_X_ref_y_a.X_ref_y[0];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* MATLAB Function: '<S73>/generate_X_ref_z' */
    controller_tem_generate_X_ref_z(controller_template_P.X_ref_z_Value,
      rtb_Sum2_m, &controller_template_B.sf_generate_X_ref_z,
      &controller_template_DWork.sf_generate_X_ref_z);

    /* Sum: '<S73>/Add1' */
    for (i = 0; i < 62; i++) {
      rtb_X_ref_z[i] = controller_template_B.sf_generate_X_ref_z.X_ref_z[i] +
        controller_template_B.X_ref_z[i];
    }

    /* End of Sum: '<S73>/Add1' */

    /* MATLAB Function: '<S17>/generate_X_ref_z' */
    controller_tem_generate_X_ref_z(controller_template_P.X_ref_z_Value_a,
      rtb_Sum2_m2, &controller_template_B.sf_generate_X_ref_z_l,
      &controller_template_DWork.sf_generate_X_ref_z_l);

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_3_Threshold) {
      controller_template_B.z_ref_n = rtb_X_ref_z[0];
    } else {
      controller_template_B.z_ref_n =
        controller_template_B.sf_generate_X_ref_z_l.X_ref_z[0];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* MATLAB Function: '<S73>/generate_X_ref_yaw' */
    controller_t_generate_X_ref_yaw(controller_template_P.X_ref_yaw_Value,
      controller_template_B.DataTypeConversion[8], rtb_Sum2_m,
      &controller_template_B.sf_generate_X_ref_yaw,
      &controller_template_DWork.sf_generate_X_ref_yaw);

    /* Sum: '<S73>/Add' */
    for (i = 0; i < 62; i++) {
      rtb_X_ref_yaw[i] = controller_template_B.sf_generate_X_ref_yaw.X_ref_yaw[i]
        + controller_template_B.X_ref_yaw[i];
    }

    /* End of Sum: '<S73>/Add' */

    /* MATLAB Function: '<S17>/generate_X_ref_yaw' */
    controller_t_generate_X_ref_yaw(controller_template_P.X_ref_yaw_Value_f,
      controller_template_B.DataTypeConversion[8], rtb_Sum2_m2,
      &controller_template_B.sf_generate_X_ref_yaw_g,
      &controller_template_DWork.sf_generate_X_ref_yaw_g);

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_4_Threshold) {
      rtb_yaw_ref = rtb_X_ref_yaw[0];
    } else {
      rtb_yaw_ref = controller_template_B.sf_generate_X_ref_yaw_g.X_ref_yaw[0];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* Outputs for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* Delay: '<S11>/Integer Delay3' */
    rtb_IntegerDelay3_c = controller_template_DWork.IntegerDelay3_DSTATE_k;

    /* MATLAB Function: '<S27>/MATLAB Function' */
    controller_template_DWork.sfEvent_ks = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/MATLAB Function': '<S63>:1' */
    /* '<S63>:1:4' */
    controller_template_B.psi_prime = controller_template_B.DataTypeConversion[8];
    if ((controller_template_B.DataTypeConversion[8] >= 0.78539816339744828) &&
        (controller_template_B.DataTypeConversion[8] <= 3.2553426535897931)) {
      /* '<S63>:1:7' */
      /* '<S63>:1:8' */
      controller_template_B.psi_prime =
        (controller_template_B.DataTypeConversion[8] - 3.1415926535897931) -
        3.1415926535897931;
    }

    /* End of MATLAB Function: '<S27>/MATLAB Function' */

    /* UnitDelay: '<S27>/Unit Delay1' */
    /*  if(psi_meas<=pi */
    memcpy((void *)&rtb_UnitDelay1_d[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_bg, 9U * sizeof(real_T));

    /* Switch: '<S64>/Init' incorporates:
     *  UnitDelay: '<S64>/FixPt Unit Delay1'
     *  UnitDelay: '<S64>/FixPt Unit Delay2'
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

    /* End of Switch: '<S64>/Init' */

    /* Inport: '<S11>/bias_W' */
    rtb_bias_W[0] =
      controller_template_B.sf_EmbeddedMATLABFunction.pitch_bias_rot;
    rtb_bias_W[1] =
      controller_template_B.sf_EmbeddedMATLABFunction.roll_bias_rot;
    rtb_bias_W[2] = rtb_Init[2];
    rtb_bias_W[3] = rtb_Init[3];

    /* MATLAB Function: '<S27>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.psi_prime,
      controller_template_B.DataTypeConversion[11], rtb_Init_jd, rtb_bias_W[3],
      controller_template_P.A_Value, controller_template_P.B_Value,
      controller_template_P.C_Value, controller_template_P.Q_Value,
      controller_template_P.R_Value, rtb_IntegerDelay3_c, rtb_UnitDelay1_d,
      &controller_template_B.sf_discretekalmanfilter,
      &controller_template_DWork.sf_discretekalmanfilter);

    /* Gain: '<S27>/Gain2' incorporates:
     *  Saturate: '<S27>/Saturation'
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

    /* Product: '<S11>/Product' incorporates:
     *  Constant: '<S11>/gravity'
     */
    rtb_Product_l = controller_template_P.gravity_Value *
      controller_template_B.DataTypeConversion[29];

    /* Saturate: '<S24>/Saturation' */
    rtb_Saturation2_l =
      controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot >=
      controller_template_P.Saturation_UpperSat_i ?
      controller_template_P.Saturation_UpperSat_i :
      controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot <=
      controller_template_P.Saturation_LowerSat_j ?
      controller_template_P.Saturation_LowerSat_j :
      controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot;

    /* Saturate: '<S24>/Saturation1' */
    rtb_UnitDelay_g = controller_template_B.DataTypeConversion[10] >=
      controller_template_P.Saturation1_UpperSat ?
      controller_template_P.Saturation1_UpperSat :
      controller_template_B.DataTypeConversion[10] <=
      controller_template_P.Saturation1_LowerSat ?
      controller_template_P.Saturation1_LowerSat :
      controller_template_B.DataTypeConversion[10];

    /* Sum: '<S35>/Add' incorporates:
     *  Constant: '<S35>/Constant'
     *  Gain: '<S43>/Slider Gain'
     */
    rtb_Add_c = controller_template_B.DataTypeConversion[0] -
      controller_template_P.SliderGain_Gain *
      controller_template_P.Constant_Value_c;

    /* Gain: '<S44>/Slider Gain' incorporates:
     *  Constant: '<S35>/Constant1'
     */
    rtb_SliderGain_n4 = controller_template_P.SliderGain_Gain_b *
      controller_template_P.Constant1_Value_f;

    /* MATLAB Function: '<S35>/MATLAB Function' */
    controller_tem_MATLABFunction_e(rtb_Add_c, rtb_SliderGain_n4,
      &controller_template_B.sf_MATLABFunction_e,
      &controller_template_DWork.sf_MATLABFunction_e);

    /* Switch: '<S32>/SwitchControl' incorporates:
     *  Constant: '<S32>/Constant'
     */
    if (controller_template_P.Constant_Value_lw >
        controller_template_P.SwitchControl_Threshold) {
      /* Saturate: '<S35>/Saturation3' */
      controller_template_B.SwitchControl =
        controller_template_B.sf_MATLABFunction_e.y >=
        controller_template_P.Saturation3_UpperSat_j ?
        controller_template_P.Saturation3_UpperSat_j :
        controller_template_B.sf_MATLABFunction_e.y <=
        controller_template_P.Saturation3_LowerSat_l ?
        controller_template_P.Saturation3_LowerSat_l :
        controller_template_B.sf_MATLABFunction_e.y;
    } else {
      /* Sum: '<S31>/Add' */
      u = controller_template_B.DataTypeConversion[0] -
        controller_template_B.x_ref;

      /* Saturate: '<S31>/Saturation3' */
      controller_template_B.SwitchControl = u >=
        controller_template_P.Saturation3_UpperSat ?
        controller_template_P.Saturation3_UpperSat : u <=
        controller_template_P.Saturation3_LowerSat ?
        controller_template_P.Saturation3_LowerSat : u;
    }

    /* End of Switch: '<S32>/SwitchControl' */

    /* Saturate: '<S24>/Saturation2' */
    rtb_UnitDelay2_a = controller_template_B.DataTypeConversion[3] >=
      controller_template_P.Saturation2_UpperSat ?
      controller_template_P.Saturation2_UpperSat :
      controller_template_B.DataTypeConversion[3] <=
      controller_template_P.Saturation2_LowerSat ?
      controller_template_P.Saturation2_LowerSat :
      controller_template_B.DataTypeConversion[3];

    /* RateTransition: '<S30>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      controller_template_B.RateTransition[0] = rtb_Saturation2_l;
      controller_template_B.RateTransition[1] = rtb_UnitDelay_g;
      controller_template_B.RateTransition[2] =
        controller_template_B.SwitchControl;
      controller_template_B.RateTransition[3] = rtb_UnitDelay2_a;

      /* UnitDelay: '<S30>/Unit Delay2' */
      controller_template_B.UnitDelay2 =
        controller_template_DWork.UnitDelay2_DSTATE;
    }

    /* End of RateTransition: '<S30>/Rate Transition' */

    /* MATLAB Function: '<S40>/MATLAB Function' */
    controller_template_DWork.sfEvent_a = CALL_EVENT;

    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/Constant'
     *  Constant: '<S40>/Constant2'
     *  MATLAB Function: '<S40>/MATLAB Function'
     */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/PitchPropagate/MATLAB Function': '<S41>:1' */
    /* '<S41>:1:4' */
    if (controller_template_B.RateTransition[2] != 0.0) {
      for (i = 0; i < 4; i++) {
        tmp[i << 2] = controller_template_P.Constant_Value[(i << 2)];
        tmp[1 + (i << 2)] = controller_template_P.Constant_Value[(i << 2) + 1];
        tmp[2 + (i << 2)] = controller_template_P.Constant_Value[(i << 2) + 2];
        tmp[3 + (i << 2)] = controller_template_P.Constant_Value[(i << 2) + 3];
      }
    } else {
      for (i = 0; i < 4; i++) {
        tmp[i << 2] = controller_template_P.Constant2_Value[(i << 2)];
        tmp[1 + (i << 2)] = controller_template_P.Constant2_Value[(i << 2) + 1];
        tmp[2 + (i << 2)] = controller_template_P.Constant2_Value[(i << 2) + 2];
        tmp[3 + (i << 2)] = controller_template_P.Constant2_Value[(i << 2) + 3];
      }
    }

    /* End of Switch: '<S40>/Switch' */

    /* Switch: '<S40>/Switch1' incorporates:
     *  Constant: '<S40>/Constant1'
     *  Constant: '<S40>/Constant3'
     *  MATLAB Function: '<S40>/MATLAB Function'
     */
    if (controller_template_B.RateTransition[2] != 0.0) {
      for (i = 0; i < 2; i++) {
        tmp_0[i << 2] = controller_template_P.Constant1_Value[(i << 2)];
        tmp_0[1 + (i << 2)] = controller_template_P.Constant1_Value[(i << 2) + 1];
        tmp_0[2 + (i << 2)] = controller_template_P.Constant1_Value[(i << 2) + 2];
        tmp_0[3 + (i << 2)] = controller_template_P.Constant1_Value[(i << 2) + 3];
      }
    } else {
      for (i = 0; i < 2; i++) {
        tmp_0[i << 2] = controller_template_P.Constant3_Value[(i << 2)];
        tmp_0[1 + (i << 2)] = controller_template_P.Constant3_Value[(i << 2) + 1];
        tmp_0[2 + (i << 2)] = controller_template_P.Constant3_Value[(i << 2) + 2];
        tmp_0[3 + (i << 2)] = controller_template_P.Constant3_Value[(i << 2) + 3];
      }
    }

    /* End of Switch: '<S40>/Switch1' */

    /* MATLAB Function: '<S40>/MATLAB Function' */
    for (i = 0; i < 4; i++) {
      u = tmp[i + 12] * controller_template_B.RateTransition[3] + (tmp[i + 8] *
        controller_template_B.RateTransition[2] + (tmp[i + 4] *
        controller_template_B.RateTransition[1] + tmp[i] *
        controller_template_B.RateTransition[0]));
      X_0[i] = u;
    }

    for (i = 0; i < 4; i++) {
      tmp_1[i] = tmp_0[i + 4] * 0.0 + tmp_0[i] *
        controller_template_B.UnitDelay2;
    }

    controller_template_B.y_i[0] = X_0[0] + tmp_1[0];
    controller_template_B.y_i[1] = X_0[1] + tmp_1[1];
    controller_template_B.y_i[2] = X_0[2] + tmp_1[2];
    controller_template_B.y_i[3] = X_0[3] + tmp_1[3];

    /* MATLAB Function: '<S30>/Ctrl_Xdir' incorporates:
     *  Constant: '<S30>/Constant'
     *  Constant: '<S30>/Constant1'
     *  Constant: '<S30>/Constant2'
     *  Constant: '<S30>/Constant4'
     *  Constant: '<S30>/Constat3'
     *  Saturate: '<S40>/Saturation'
     *  Saturate: '<S40>/Saturation1'
     *  Saturate: '<S40>/Saturation2'
     *  Saturate: '<S40>/Saturation3'
     */
    controller_template_DWork.sfEvent_cm = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/Ctrl_Xdir': '<S39>:1' */
    /* '<S39>:1:3' */
    tolerance = 1.0;

    /* '<S39>:1:5' */
    /* '<S39>:1:6' */
    minreg = -1;

    /* '<S39>:1:7' */
    X[0] = (controller_template_B.y_i[0] >=
            controller_template_P.Saturation_UpperSat_p ?
            controller_template_P.Saturation_UpperSat_p :
            controller_template_B.y_i[0] <=
            controller_template_P.Saturation_LowerSat_c ?
            controller_template_P.Saturation_LowerSat_c :
            controller_template_B.y_i[0]) * 10000.0;
    X[1] = (controller_template_B.y_i[1] >=
            controller_template_P.Saturation1_UpperSat_o ?
            controller_template_P.Saturation1_UpperSat_o :
            controller_template_B.y_i[1] <=
            controller_template_P.Saturation1_LowerSat_d ?
            controller_template_P.Saturation1_LowerSat_d :
            controller_template_B.y_i[1]) * 10000.0;
    X[2] = (controller_template_B.y_i[2] >=
            controller_template_P.Saturation3_UpperSat_c ?
            controller_template_P.Saturation3_UpperSat_c :
            controller_template_B.y_i[2] <=
            controller_template_P.Saturation3_LowerSat_k ?
            controller_template_P.Saturation3_LowerSat_k :
            controller_template_B.y_i[2]) * 10000.0;
    X[3] = (controller_template_B.y_i[3] >=
            controller_template_P.Saturation2_UpperSat_a ?
            controller_template_P.Saturation2_UpperSat_a :
            controller_template_B.y_i[3] <=
            controller_template_P.Saturation2_LowerSat_h ?
            controller_template_P.Saturation2_LowerSat_h :
            controller_template_B.y_i[3]) * 10000.0;
    controller_template_round_c(X);
    X_0[0] = X[0];
    X_0[1] = X[1];
    X_0[2] = X[2];
    X_0[3] = X[3];
    controller_template_mrdivide_c(X_0, 10000.0, X);

    /* '<S39>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S39>:1:12' */
    memset((void *)(&controller_template_B.Hi[0]), 0, 4000U * sizeof(real_T));

    /* '<S39>:1:13' */
    memset((void *)(&controller_template_B.Ki[0]), 0, 1000U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S39>:1:16' */
    abspos = 1.0;

    /* '<S39>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 277) {
        /* '<S39>:1:17' */
        /* '<S39>:1:18' */
        sumViol = 0.0;

        /* '<S39>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S39>:1:23' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant4_Value[ireg]
             - 1; dz++) {
          /* '<S39>:1:23' */
          /* '<S39>:1:24' */
          /* '<S39>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) - 1] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) - 1];

          /* '<S39>:1:24' */
          /* '<S39>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) + 999] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 2368];

          /* '<S39>:1:24' */
          /* '<S39>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) + 1999] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 4737];

          /* '<S39>:1:24' */
          /* '<S39>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) + 2999] =
            controller_template_P.Constant_Value_l[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 7106];

          /* '<S39>:1:24' */
          /* '<S39>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S39>:1:30' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value[ireg] -
             1; i++) {
          /* '<S39>:1:30' */
          /* '<S39>:1:31' */
          controller_template_B.Ki[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant1_Value_fy[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S39>:1:30' */
        }

        /* '<S39>:1:33' */
        abspos += controller_template_P.Constant4_Value[ireg];

        /* '<S39>:1:35' */
        /* '<S39>:1:36' */
        /* '<S39>:1:38' */
        /* '<S39>:1:40' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant4_Value[ireg]
             - 1; dz++) {
          /* '<S39>:1:40' */
          /* '<S39>:1:41' */
          roll_cmd_f = ((controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) -
                         1] * X[0] + controller_template_B.Hi[(int32_T)(1.0 +
            (real_T)dz) + 999] * X[1]) + controller_template_B.Hi[(int32_T)(1.0
            + (real_T)dz) + 1999] * X[2]) + controller_template_B.Hi[(int32_T)
            (1.0 + (real_T)dz) + 2999] * X[3];
          if (roll_cmd_f - controller_template_B.Ki[(int32_T)(1.0 + (real_T)dz)
              - 1] > 1.0E-8) {
            /* '<S39>:1:42' */
            /* '<S39>:1:43' */
            isinside = 0;

            /* '<S39>:1:44' */
            sumViol += roll_cmd_f - controller_template_B.Ki[(int32_T)(1.0 +
              (real_T)dz) - 1];
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
          rtb_SliderGain_e3 = (((controller_template_P.Constant2_Value_m[ireg +
            277] * X[1] + controller_template_P.Constant2_Value_m[ireg] * X[0])
                                + controller_template_P.Constant2_Value_m[ireg +
                                554] * X[2]) +
                               controller_template_P.Constant2_Value_m[ireg +
                               831] * X[3]) +
            controller_template_P.Constat3_Value[ireg];
          exitg = 1;
        } else {
          /* '<S39>:1:17' */
          ireg++;
        }
      } else {
        /* '<S39>:1:58' */
        /* '<S39>:1:59' */
        /* '<S39>:1:60' */
        rtb_SliderGain_e3 = (((controller_template_P.Constant2_Value_m[minreg +
          277] * X[1] + controller_template_P.Constant2_Value_m[minreg] * X[0])
                              + controller_template_P.Constant2_Value_m[minreg +
                              554] * X[2]) +
                             controller_template_P.Constant2_Value_m[minreg +
                             831] * X[3]) +
          controller_template_P.Constat3_Value[minreg];

        /* '<S39>:1:61' */
        flag_oob = 1;
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_gb = rtb_SliderGain_e3;
    controller_template_B.flag_oob_ow = (real_T)flag_oob;

    /* End of MATLAB Function: '<S30>/Ctrl_Xdir' */

    /* RateTransition: '<S29>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      controller_template_B.RateTransition_l[0] = rtb_Saturation2_l;
      controller_template_B.RateTransition_l[1] = rtb_UnitDelay_g;
      controller_template_B.RateTransition_l[2] =
        controller_template_B.SwitchControl;
      controller_template_B.RateTransition_l[3] = rtb_UnitDelay2_a;

      /* UnitDelay: '<S29>/Unit Delay2' */
      controller_template_B.UnitDelay2_p =
        controller_template_DWork.UnitDelay2_DSTATE_m;
    }

    /* End of RateTransition: '<S29>/Rate Transition' */

    /* MATLAB Function: '<S37>/MATLAB Function' */
    controller_templ_MATLABFunction(controller_template_B.RateTransition_l,
      controller_template_P.Constant_Value_m,
      controller_template_P.Constant1_Value_a,
      controller_template_B.UnitDelay2_p,
      &controller_template_B.sf_MATLABFunction_i,
      &controller_template_DWork.sf_MATLABFunction_i);

    /* MATLAB Function: '<S29>/Ctrl_Xdir' incorporates:
     *  Constant: '<S29>/Constant5'
     *  Constant: '<S29>/Constant6'
     *  Constant: '<S29>/Constant7'
     *  Constant: '<S29>/Constant8'
     *  Constant: '<S29>/Constant9'
     *  Saturate: '<S37>/Saturation'
     *  Saturate: '<S37>/Saturation1'
     *  Saturate: '<S37>/Saturation2'
     *  Saturate: '<S37>/Saturation3'
     */
    controller_template_DWork.sfEvent_cr = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/Ctrl_Xdir': '<S36>:1' */
    /* '<S36>:1:3' */
    tolerance = 1.0;

    /* '<S36>:1:5' */
    /* '<S36>:1:6' */
    minreg = -1;

    /* '<S36>:1:7' */
    X[0] = (controller_template_B.sf_MATLABFunction_i.y[0] >=
            controller_template_P.Saturation_UpperSat_k ?
            controller_template_P.Saturation_UpperSat_k :
            controller_template_B.sf_MATLABFunction_i.y[0] <=
            controller_template_P.Saturation_LowerSat_e ?
            controller_template_P.Saturation_LowerSat_e :
            controller_template_B.sf_MATLABFunction_i.y[0]) * 10000.0;
    X[1] = (controller_template_B.sf_MATLABFunction_i.y[1] >=
            controller_template_P.Saturation1_UpperSat_p ?
            controller_template_P.Saturation1_UpperSat_p :
            controller_template_B.sf_MATLABFunction_i.y[1] <=
            controller_template_P.Saturation1_LowerSat_l ?
            controller_template_P.Saturation1_LowerSat_l :
            controller_template_B.sf_MATLABFunction_i.y[1]) * 10000.0;
    X[2] = (controller_template_B.sf_MATLABFunction_i.y[2] >=
            controller_template_P.Saturation3_UpperSat_l ?
            controller_template_P.Saturation3_UpperSat_l :
            controller_template_B.sf_MATLABFunction_i.y[2] <=
            controller_template_P.Saturation3_LowerSat_lj ?
            controller_template_P.Saturation3_LowerSat_lj :
            controller_template_B.sf_MATLABFunction_i.y[2]) * 10000.0;
    X[3] = (controller_template_B.sf_MATLABFunction_i.y[3] >=
            controller_template_P.Saturation2_UpperSat_k ?
            controller_template_P.Saturation2_UpperSat_k :
            controller_template_B.sf_MATLABFunction_i.y[3] <=
            controller_template_P.Saturation2_LowerSat_c ?
            controller_template_P.Saturation2_LowerSat_c :
            controller_template_B.sf_MATLABFunction_i.y[3]) * 10000.0;
    controller_template_round(X);
    X_0[0] = X[0];
    X_0[1] = X[1];
    X_0[2] = X[2];
    X_0[3] = X[3];
    controller_template_mrdivide(X_0, 10000.0, X);

    /* '<S36>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S36>:1:12' */
    memset((void *)(&controller_template_B.Hi[0]), 0, 4000U * sizeof(real_T));

    /* '<S36>:1:13' */
    memset((void *)(&controller_template_B.Ki[0]), 0, 1000U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S36>:1:16' */
    abspos = 1.0;

    /* '<S36>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 134) {
        /* '<S36>:1:17' */
        /* '<S36>:1:18' */
        sumViol = 0.0;

        /* '<S36>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S36>:1:23' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant9_Value[ireg]
             - 1; dz++) {
          /* '<S36>:1:23' */
          /* '<S36>:1:24' */
          /* '<S36>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) - 1] =
            controller_template_P.Constant5_Value[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) - 1];

          /* '<S36>:1:24' */
          /* '<S36>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) + 999] =
            controller_template_P.Constant5_Value[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 1115];

          /* '<S36>:1:24' */
          /* '<S36>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) + 1999] =
            controller_template_P.Constant5_Value[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 2231];

          /* '<S36>:1:24' */
          /* '<S36>:1:25' */
          controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) + 2999] =
            controller_template_P.Constant5_Value[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 3347];

          /* '<S36>:1:24' */
          /* '<S36>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S36>:1:30' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant9_Value[ireg] -
             1; i++) {
          /* '<S36>:1:30' */
          /* '<S36>:1:31' */
          controller_template_B.Ki[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant6_Value[(int32_T)(((1.0 + (real_T)i) +
            abspos) - 1.0) - 1];

          /* '<S36>:1:30' */
        }

        /* '<S36>:1:33' */
        abspos += controller_template_P.Constant9_Value[ireg];

        /* '<S36>:1:35' */
        /* '<S36>:1:36' */
        /* '<S36>:1:38' */
        /* '<S36>:1:40' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant9_Value[ireg]
             - 1; dz++) {
          /* '<S36>:1:40' */
          /* '<S36>:1:41' */
          roll_cmd_f = ((controller_template_B.Hi[(int32_T)(1.0 + (real_T)dz) -
                         1] * X[0] + controller_template_B.Hi[(int32_T)(1.0 +
            (real_T)dz) + 999] * X[1]) + controller_template_B.Hi[(int32_T)(1.0
            + (real_T)dz) + 1999] * X[2]) + controller_template_B.Hi[(int32_T)
            (1.0 + (real_T)dz) + 2999] * X[3];
          if (roll_cmd_f - controller_template_B.Ki[(int32_T)(1.0 + (real_T)dz)
              - 1] > 1.0E-8) {
            /* '<S36>:1:42' */
            /* '<S36>:1:43' */
            isinside = 0;

            /* '<S36>:1:44' */
            sumViol += roll_cmd_f - controller_template_B.Ki[(int32_T)(1.0 +
              (real_T)dz) - 1];
          }

          /* '<S36>:1:40' */
        }

        if (sumViol < tolerance) {
          /* '<S36>:1:48' */
          /* '<S36>:1:49' */
          tolerance = sumViol;

          /* '<S36>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S36>:1:53' */
          /* '<S36>:1:54' */
          rtb_roll_cmd_c = (((controller_template_P.Constant7_Value[ireg + 134] *
                              X[1] + controller_template_P.Constant7_Value[ireg]
                              * X[0]) +
                             controller_template_P.Constant7_Value[ireg + 268] *
                             X[2]) + controller_template_P.Constant7_Value[ireg
                            + 402] * X[3]) +
            controller_template_P.Constant8_Value[ireg];
          exitg = 1;
        } else {
          /* '<S36>:1:17' */
          ireg++;
        }
      } else {
        /* '<S36>:1:58' */
        /* '<S36>:1:59' */
        /* '<S36>:1:60' */
        rtb_roll_cmd_c = (((controller_template_P.Constant7_Value[minreg + 134] *
                            X[1] + controller_template_P.Constant7_Value[minreg]
                            * X[0]) +
                           controller_template_P.Constant7_Value[minreg + 268] *
                           X[2]) + controller_template_P.Constant7_Value[minreg
                          + 402] * X[3]) +
          controller_template_P.Constant8_Value[minreg];

        /* '<S36>:1:61' */
        flag_oob = 1;
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_a = rtb_roll_cmd_c;
    controller_template_B.flag_oob_l1 = (real_T)flag_oob;

    /* End of MATLAB Function: '<S29>/Ctrl_Xdir' */

    /* Switch: '<S33>/SwitchControl' incorporates:
     *  Constant: '<S33>/Constant'
     */
    if (controller_template_P.Constant_Value_j >
        controller_template_P.SwitchControl_Threshold_a) {
      u = controller_template_B.U_gb;
    } else {
      u = controller_template_B.U_a;
    }

    /* End of Switch: '<S33>/SwitchControl' */

    /* Gain: '<S34>/Gain' incorporates:
     *  Saturate: '<S24>/Saturation4'
     *  Sum: '<S34>/Sum'
     *  Sum: '<S34>/Sum1'
     *  UnitDelay: '<S34>/Unit Delay'
     *  UnitDelay: '<S34>/Unit Delay2'
     */
    controller_template_B.Gain_pk = ((u >=
      controller_template_P.Saturation4_UpperSat ?
      controller_template_P.Saturation4_UpperSat : u <=
      controller_template_P.Saturation4_LowerSat ?
      controller_template_P.Saturation4_LowerSat : u) +
      (controller_template_DWork.UnitDelay2_DSTATE_d +
       controller_template_DWork.UnitDelay_DSTATE_jv)) *
      controller_template_P.Gain_Gain;

    /* Sum: '<S11>/Sum' */
    rtb_UnitDelay2_a = controller_template_B.Gain_pk - rtb_bias_W[0];

    /* Sum: '<S25>/Add' incorporates:
     *  Constant: '<S25>/Constant'
     *  Gain: '<S47>/Slider Gain'
     *  Gain: '<S48>/Slider Gain'
     *  Sum: '<S25>/Sum'
     */
    u = controller_template_B.DataTypeConversion[1] -
      (controller_template_P.SliderGain_Gain_g * controller_template_B.y_ref_h +
       controller_template_P.SliderGain_Gain_be *
       controller_template_P.Constant_Value_g);

    /* Saturate: '<S25>/Saturation3' */
    controller_template_B.Saturation3 = u >=
      controller_template_P.Saturation3_UpperSat_n ?
      controller_template_P.Saturation3_UpperSat_n : u <=
      controller_template_P.Saturation3_LowerSat_c ?
      controller_template_P.Saturation3_LowerSat_c : u;

    /* RateTransition: '<S45>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      /* Saturate: '<S25>/Saturation' */
      controller_template_B.RateTransition_i[0] =
        controller_template_B.sf_EmbeddedMATLABFunction.roll_rot >=
        controller_template_P.Saturation_UpperSat_h ?
        controller_template_P.Saturation_UpperSat_h :
        controller_template_B.sf_EmbeddedMATLABFunction.roll_rot <=
        controller_template_P.Saturation_LowerSat_d ?
        controller_template_P.Saturation_LowerSat_d :
        controller_template_B.sf_EmbeddedMATLABFunction.roll_rot;

      /* Saturate: '<S25>/Saturation1' */
      controller_template_B.RateTransition_i[1] =
        controller_template_B.DataTypeConversion[9] >=
        controller_template_P.Saturation1_UpperSat_ou ?
        controller_template_P.Saturation1_UpperSat_ou :
        controller_template_B.DataTypeConversion[9] <=
        controller_template_P.Saturation1_LowerSat_c ?
        controller_template_P.Saturation1_LowerSat_c :
        controller_template_B.DataTypeConversion[9];
      controller_template_B.RateTransition_i[2] =
        controller_template_B.Saturation3;

      /* Saturate: '<S25>/Saturation2' */
      controller_template_B.RateTransition_i[3] =
        controller_template_B.DataTypeConversion[4] >=
        controller_template_P.Saturation2_UpperSat_b ?
        controller_template_P.Saturation2_UpperSat_b :
        controller_template_B.DataTypeConversion[4] <=
        controller_template_P.Saturation2_LowerSat_hu ?
        controller_template_P.Saturation2_LowerSat_hu :
        controller_template_B.DataTypeConversion[4];

      /* UnitDelay: '<S45>/Unit Delay2' */
      controller_template_B.UnitDelay2_o =
        controller_template_DWork.UnitDelay2_DSTATE_l;
    }

    /* End of RateTransition: '<S45>/Rate Transition' */

    /* MATLAB Function: '<S50>/MATLAB Function' */
    controller_templ_MATLABFunction(controller_template_B.RateTransition_i,
      controller_template_P.Constant_Value_co,
      controller_template_P.Constant1_Value_g,
      controller_template_B.UnitDelay2_o,
      &controller_template_B.sf_MATLABFunction_k,
      &controller_template_DWork.sf_MATLABFunction_k);

    /* MATLAB Function: '<S45>/Ctrl_Xdir' incorporates:
     *  Constant: '<S45>/Constant'
     *  Constant: '<S45>/Constant1'
     *  Constant: '<S45>/Constant2'
     *  Constant: '<S45>/Constant3'
     *  Constant: '<S45>/Constant4'
     */
    controller_template_DWork.sfEvent_cd = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S49>:1' */
    /* '<S49>:1:3' */
    tolerance = 1.0;

    /* '<S49>:1:5' */
    /* '<S49>:1:6' */
    minreg = -1;

    /* '<S49>:1:7' */
    X[0] = 10000.0 * controller_template_B.sf_MATLABFunction_k.y[0];
    X[1] = 10000.0 * controller_template_B.sf_MATLABFunction_k.y[1];
    X[2] = 10000.0 * controller_template_B.sf_MATLABFunction_k.y[2];
    X[3] = 10000.0 * controller_template_B.sf_MATLABFunction_k.y[3];
    controller_template_round_k(X);
    X_0[0] = X[0];
    X_0[1] = X[1];
    X_0[2] = X[2];
    X_0[3] = X[3];
    controller_template_mrdivide_k(X_0, 10000.0, X);

    /* '<S49>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S49>:1:12' */
    memset((void *)&Hi[0], 0, 400U * sizeof(real_T));

    /* '<S49>:1:13' */
    memset((void *)&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S49>:1:16' */
    abspos = 1.0;

    /* '<S49>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 171) {
        /* '<S49>:1:17' */
        /* '<S49>:1:18' */
        sumViol = 0.0;

        /* '<S49>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S49>:1:23' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; dz++) {
          /* '<S49>:1:23' */
          /* '<S49>:1:24' */
          /* '<S49>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)dz) - 1] =
            controller_template_P.Constant_Value_ln[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) - 1];

          /* '<S49>:1:24' */
          /* '<S49>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)dz) + 99] =
            controller_template_P.Constant_Value_ln[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 1483];

          /* '<S49>:1:24' */
          /* '<S49>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)dz) + 199] =
            controller_template_P.Constant_Value_ln[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 2967];

          /* '<S49>:1:24' */
          /* '<S49>:1:25' */
          Hi[(int32_T)(1.0 + (real_T)dz) + 299] =
            controller_template_P.Constant_Value_ln[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 4451];

          /* '<S49>:1:24' */
          /* '<S49>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S49>:1:30' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; i++) {
          /* '<S49>:1:30' */
          /* '<S49>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant1_Value_j[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S49>:1:30' */
        }

        /* '<S49>:1:33' */
        abspos += controller_template_P.Constant4_Value_g[ireg];

        /* '<S49>:1:35' */
        /* '<S49>:1:36' */
        /* '<S49>:1:38' */
        /* '<S49>:1:40' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant4_Value_g[ireg]
             - 1; dz++) {
          /* '<S49>:1:40' */
          /* '<S49>:1:41' */
          roll_cmd_f = ((Hi[(int32_T)(1.0 + (real_T)dz) - 1] * X[0] + Hi
                         [(int32_T)(1.0 + (real_T)dz) + 99] * X[1]) + Hi
                        [(int32_T)(1.0 + (real_T)dz) + 199] * X[2]) + Hi
            [(int32_T)(1.0 + (real_T)dz) + 299] * X[3];
          if (roll_cmd_f - Ki[(int32_T)(1.0 + (real_T)dz) - 1] > 1.0E-8) {
            /* '<S49>:1:42' */
            /* '<S49>:1:43' */
            isinside = 0;

            /* '<S49>:1:44' */
            sumViol += roll_cmd_f - Ki[(int32_T)(1.0 + (real_T)dz) - 1];
          }

          /* '<S49>:1:40' */
        }

        if (sumViol < tolerance) {
          /* '<S49>:1:48' */
          /* '<S49>:1:49' */
          tolerance = sumViol;

          /* '<S49>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S49>:1:53' */
          /* '<S49>:1:54' */
          rtb_Saturation_n = (((controller_template_P.Constant2_Value_j[ireg +
                                171] * X[1] +
                                controller_template_P.Constant2_Value_j[ireg] *
                                X[0]) +
                               controller_template_P.Constant2_Value_j[ireg +
                               342] * X[2]) +
                              controller_template_P.Constant2_Value_j[ireg + 513]
                              * X[3]) +
            controller_template_P.Constant3_Value_o[ireg];
          exitg = 1;
        } else {
          /* '<S49>:1:17' */
          ireg++;
        }
      } else {
        /* '<S49>:1:58' */
        /* '<S49>:1:59' */
        /* '<S49>:1:60' */
        rtb_Saturation_n = (((controller_template_P.Constant2_Value_j[minreg +
                              171] * X[1] +
                              controller_template_P.Constant2_Value_j[minreg] *
                              X[0]) +
                             controller_template_P.Constant2_Value_j[minreg +
                             342] * X[2]) +
                            controller_template_P.Constant2_Value_j[minreg + 513]
                            * X[3]) +
          controller_template_P.Constant3_Value_o[minreg];

        /* '<S49>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_p = rtb_Saturation_n;
    controller_template_B.flag_oob_o = (real_T)flag_oob;

    /* End of MATLAB Function: '<S45>/Ctrl_Xdir' */

    /* Gain: '<S46>/Gain' incorporates:
     *  Saturate: '<S25>/Saturation4'
     *  Sum: '<S46>/Sum'
     *  Sum: '<S46>/Sum1'
     *  UnitDelay: '<S46>/Unit Delay'
     *  UnitDelay: '<S46>/Unit Delay2'
     */
    controller_template_B.Gain_f = ((controller_template_B.U_p >=
      controller_template_P.Saturation4_UpperSat_i ?
      controller_template_P.Saturation4_UpperSat_i : controller_template_B.U_p <=
      controller_template_P.Saturation4_LowerSat_h ?
      controller_template_P.Saturation4_LowerSat_h : controller_template_B.U_p)
      + (controller_template_DWork.UnitDelay2_DSTATE_k +
         controller_template_DWork.UnitDelay_DSTATE_f)) *
      controller_template_P.Gain_Gain_f;

    /* Sum: '<S11>/Sum1' */
    rtb_roll_cmd_c = controller_template_B.Gain_f - rtb_bias_W[1];

    /* Sum: '<S28>/Add' */
    u = controller_template_B.DataTypeConversion[2] -
      controller_template_B.z_ref_n;

    /* Saturate: '<S28>/Saturation1' */
    controller_template_B.Saturation1 = u >=
      controller_template_P.Saturation1_UpperSat_d ?
      controller_template_P.Saturation1_UpperSat_d : u <=
      controller_template_P.Saturation1_LowerSat_n ?
      controller_template_P.Saturation1_LowerSat_n : u;

    /* RateTransition: '<S66>/Rate Transition' */
    if (controller_template_M->Timing.TaskCounters.TID[1] == 0) {
      controller_template_B.RateTransition_j[0] =
        controller_template_B.Saturation1;

      /* Saturate: '<S28>/Saturation' */
      controller_template_B.RateTransition_j[1] =
        controller_template_B.DataTypeConversion[5] >=
        controller_template_P.Saturation_UpperSat_d ?
        controller_template_P.Saturation_UpperSat_d :
        controller_template_B.DataTypeConversion[5] <=
        controller_template_P.Saturation_LowerSat_b ?
        controller_template_P.Saturation_LowerSat_b :
        controller_template_B.DataTypeConversion[5];
    }

    /* End of RateTransition: '<S66>/Rate Transition' */

    /* MATLAB Function: '<S66>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_k0 = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S68>:1' */
    /* '<S68>:1:3' */
    tolerance = 1.0;

    /* '<S68>:1:5' */
    /* '<S68>:1:6' */
    minreg = -1;

    /* '<S68>:1:7' */
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
    /* MATLAB Function: '<S66>/Ctrl_Xdir' incorporates:
     *  Constant: '<S66>/Constant'
     *  Constant: '<S66>/Constant1'
     *  Constant: '<S66>/Constant2'
     *  Constant: '<S66>/Constant3'
     *  Constant: '<S66>/Constant4'
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

    /* '<S68>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S68>:1:12' */
    memset((void *)&Hi_0[0], 0, 200U * sizeof(real_T));

    /* '<S68>:1:13' */
    memset((void *)&Ki[0], 0, 100U * sizeof(real_T));

    /*  Find the proper region */
    /* '<S68>:1:16' */
    abspos = 1.0;

    /* '<S68>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 59) {
        /* '<S68>:1:17' */
        /* '<S68>:1:18' */
        sumViol = 0.0;

        /* '<S68>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S68>:1:23' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; dz++) {
          /* '<S68>:1:23' */
          /* '<S68>:1:24' */
          /* '<S68>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)dz) - 1] =
            controller_template_P.Constant_Value_b[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) - 1];

          /* '<S68>:1:24' */
          /* '<S68>:1:25' */
          Hi_0[(int32_T)(1.0 + (real_T)dz) + 99] =
            controller_template_P.Constant_Value_b[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) + 253];

          /* '<S68>:1:24' */
          /* '<S68>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S68>:1:30' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; i++) {
          /* '<S68>:1:30' */
          /* '<S68>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant1_Value_l[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S68>:1:30' */
        }

        /* '<S68>:1:33' */
        abspos += controller_template_P.Constant4_Value_a[ireg];

        /* '<S68>:1:35' */
        /* '<S68>:1:36' */
        /* '<S68>:1:38' */
        /* '<S68>:1:40' */
        for (dz = 0; dz <= (int32_T)controller_template_P.Constant4_Value_a[ireg]
             - 1; dz++) {
          /* '<S68>:1:40' */
          /* '<S68>:1:41' */
          roll_cmd_f = Hi_0[(int32_T)(1.0 + (real_T)dz) - 1] * temp_idx + Hi_0
            [(int32_T)(1.0 + (real_T)dz) + 99] * u;
          if (roll_cmd_f - Ki[(int32_T)(1.0 + (real_T)dz) - 1] > 1.0E-8) {
            /* '<S68>:1:42' */
            /* '<S68>:1:43' */
            isinside = 0;

            /* '<S68>:1:44' */
            sumViol += roll_cmd_f - Ki[(int32_T)(1.0 + (real_T)dz) - 1];
          }

          /* '<S68>:1:40' */
        }

        if (sumViol < tolerance) {
          /* '<S68>:1:48' */
          /* '<S68>:1:49' */
          tolerance = sumViol;

          /* '<S68>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S68>:1:53' */
          /* '<S68>:1:54' */
          U = (controller_template_P.Constant2_Value_g[ireg + 59] * u +
               controller_template_P.Constant2_Value_g[ireg] * temp_idx) +
            controller_template_P.Constant3_Value_m[ireg];
          exitg = 1;
        } else {
          /* '<S68>:1:17' */
          ireg++;
        }
      } else {
        /* '<S68>:1:58' */
        /* '<S68>:1:59' */
        /* '<S68>:1:60' */
        U = (controller_template_P.Constant2_Value_g[minreg + 59] * u +
             controller_template_P.Constant2_Value_g[minreg] * temp_idx) +
          controller_template_P.Constant3_Value_m[minreg];

        /* '<S68>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U = U;
    controller_template_B.flag_oob = (real_T)flag_oob;

    /* Gain: '<S67>/Gain' incorporates:
     *  Saturate: '<S28>/Saturation2'
     *  Sum: '<S67>/Sum'
     *  Sum: '<S67>/Sum1'
     *  UnitDelay: '<S67>/Unit Delay'
     *  UnitDelay: '<S67>/Unit Delay2'
     */
    controller_template_B.Gain_i = ((controller_template_B.U >=
      controller_template_P.Saturation2_UpperSat_kw ?
      controller_template_P.Saturation2_UpperSat_kw : controller_template_B.U <=
      controller_template_P.Saturation2_LowerSat_j ?
      controller_template_P.Saturation2_LowerSat_j : controller_template_B.U) +
                                    
      (controller_template_DWork.UnitDelay2_DSTATE_b +
       controller_template_DWork.UnitDelay_DSTATE_fw)) *
      controller_template_P.Gain_Gain_p;

    /* MATLAB Function: '<S26>/MATLAB Function' */
    controller_template_DWork.sfEvent_g = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/MATLAB Function': '<S53>:1' */
    /* '<S53>:1:4' */
    controller_template_B.psi_prime_l =
      controller_template_B.sf_discretekalmanfilter.state_est[0];

    /* Gain: '<S58>/Slider Gain' incorporates:
     *  Constant: '<S26>/Constant1'
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
    rtb_SliderGain_e3 = controller_template_P.SliderGain_Gain_a *
      controller_template_P.Constant1_Value_k;

    /* MATLAB Function: '<S26>/MATLAB Function1' incorporates:
     *  Constant: '<S26>/Constant2'
     *  Gain: '<S59>/Slider Gain'
     */
    controller_template_DWork.sfEvent_d = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/MATLAB Function1': '<S54>:1' */
    /* '<S54>:1:4' */
    controller_template_B.psi_out = controller_template_B.psi_prime_l;
    if (rtb_SliderGain_e3 - 0.0 <= controller_template_P.SliderGain_Gain_p *
        controller_template_P.Constant2_Value_l) {
      /* '<S54>:1:6' */
      /* '<S54>:1:7' */
      controller_template_B.psi_out = rtb_yaw_ref;
    }

    /* '<S54>:1:10' */
    controller_template_B.delta_x = rtb_SliderGain_e3 - 0.0;

    /* End of MATLAB Function: '<S26>/MATLAB Function1' */

    /* Sum: '<S26>/Sum' incorporates:
     *  Constant: '<S26>/Constant'
     *  Gain: '<S56>/Slider Gain'
     *  Gain: '<S57>/Slider Gain'
     */
    controller_template_B.Sum = controller_template_P.SliderGain_Gain_ai *
      rtb_yaw_ref + controller_template_P.SliderGain_Gain_j *
      controller_template_P.Constant_Value_f;

    /* MATLAB Function: '<S61>/MATLAB Function' */
    controller_template_DWork.sfEvent_l = CALL_EVENT;

    /* Sum: '<S26>/Add' */
    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate/MATLAB Function': '<S62>:1' */
    /* '<S62>:1:4' */
    u = controller_template_B.psi_out - controller_template_B.Sum;

    /* MATLAB Function: '<S61>/MATLAB Function' incorporates:
     *  Constant: '<S61>/Constant'
     *  Constant: '<S61>/Constant1'
     *  Saturate: '<S26>/Saturation'
     *  UnitDelay: '<S52>/Unit Delay2'
     */
    controller_template_B.y = (u >= controller_template_P.Saturation_UpperSat_o ?
      controller_template_P.Saturation_UpperSat_o : u <=
      controller_template_P.Saturation_LowerSat_p ?
      controller_template_P.Saturation_LowerSat_p : u) *
      controller_template_P.Constant_Value_h +
      controller_template_P.Constant1_Value_m *
      controller_template_DWork.UnitDelay2_DSTATE_g;

    /* MATLAB Function: '<S52>/Ctrl_Xdir' incorporates:
     *  Constant: '<S52>/Constant'
     *  Constant: '<S52>/Constant1'
     *  Constant: '<S52>/Constant2'
     *  Constant: '<S52>/Constant3'
     *  Constant: '<S52>/Constant4'
     */
    controller_template_DWork.sfEvent_jv = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Ctrl_Xdir': '<S60>:1' */
    /* '<S60>:1:3' */
    tolerance = 1.0;

    /* '<S60>:1:5' */
    /* '<S60>:1:6' */
    minreg = -1;

    /* '<S60>:1:7' */
    rtb_SliderGain_n = 10000.0 * controller_template_B.y;
    if (!(fabs(rtb_SliderGain_n) > 4.503599627370496E+15)) {
      if (rtb_SliderGain_n >= 0.5) {
        rtb_SliderGain_n = floor(rtb_SliderGain_n + 0.5);
      } else if (rtb_SliderGain_n > -0.5) {
        rtb_SliderGain_n = -0.0;
      } else {
        rtb_SliderGain_n = ceil(rtb_SliderGain_n - 0.5);
      }
    }

    rtb_SliderGain_n /= 10000.0;

    /* '<S60>:1:9' */
    flag_oob = 0;

    /* maxSize = max(Nc); */
    /* '<S60>:1:12' */
    /* '<S60>:1:13' */
    for (i = 0; i < 100; i++) {
      Hi_1[i] = 0.0;
      Ki[i] = 0.0;
    }

    /*  Find the proper region */
    /* '<S60>:1:16' */
    abspos = 1.0;

    /* '<S60>:1:17' */
    ireg = 0;
    do {
      exitg = 0;
      if (ireg < 3) {
        /* '<S60>:1:17' */
        /* '<S60>:1:18' */
        sumViol = 0.0;

        /* '<S60>:1:19' */
        isinside = 1;

        /*   Hi(1:Nc(ireg),1:4) = Hn(abspos:(abspos+Nc(ireg)-1),1:4); */
        /* '<S60>:1:23' */
        for (dz = 0; dz <= (int32_T)
             controller_template_P.Constant4_Value_gb[ireg] - 1; dz++) {
          /* '<S60>:1:23' */
          /* '<S60>:1:25' */
          Hi_1[(int32_T)(1.0 + (real_T)dz) - 1] =
            controller_template_P.Constant_Value_a[(int32_T)(((1.0 + (real_T)dz)
            + abspos) - 1.0) - 1];

          /* '<S60>:1:23' */
        }

        /*     Ki(1:Nc(ireg),1) = Kn(abspos:(abspos+Nc(ireg)-1),1); */
        /* '<S60>:1:30' */
        for (i = 0; i <= (int32_T)controller_template_P.Constant4_Value_gb[ireg]
             - 1; i++) {
          /* '<S60>:1:30' */
          /* '<S60>:1:31' */
          Ki[(int32_T)(1.0 + (real_T)i) - 1] =
            controller_template_P.Constant1_Value_gs[(int32_T)(((1.0 + (real_T)i)
            + abspos) - 1.0) - 1];

          /* '<S60>:1:30' */
        }

        /* '<S60>:1:33' */
        abspos += controller_template_P.Constant4_Value_gb[ireg];

        /* '<S60>:1:35' */
        /* '<S60>:1:36' */
        /* '<S60>:1:38' */
        /* '<S60>:1:40' */
        for (dz = 0; dz <= (int32_T)
             controller_template_P.Constant4_Value_gb[ireg] - 1; dz++) {
          /* '<S60>:1:40' */
          /* '<S60>:1:41' */
          roll_cmd_f = Hi_1[(int32_T)(1.0 + (real_T)dz) - 1] * rtb_SliderGain_n;
          if (roll_cmd_f - Ki[(int32_T)(1.0 + (real_T)dz) - 1] > 1.0E-8) {
            /* '<S60>:1:42' */
            /* '<S60>:1:43' */
            isinside = 0;

            /* '<S60>:1:44' */
            sumViol += roll_cmd_f - Ki[(int32_T)(1.0 + (real_T)dz) - 1];
          }

          /* '<S60>:1:40' */
        }

        if (sumViol < tolerance) {
          /* '<S60>:1:48' */
          /* '<S60>:1:49' */
          tolerance = sumViol;

          /* '<S60>:1:50' */
          minreg = ireg;
        }

        /*  extract the right control law */
        if (isinside == 1) {
          /* '<S60>:1:53' */
          /* '<S60>:1:54' */
          U_0 = controller_template_P.Constant2_Value_jq[ireg] *
            rtb_SliderGain_n + controller_template_P.Constant3_Value_b[ireg];
          exitg = 1;
        } else {
          /* '<S60>:1:17' */
          ireg++;
        }
      } else {
        /* '<S60>:1:58' */
        /* '<S60>:1:59' */
        /* '<S60>:1:60' */
        U_0 = controller_template_P.Constant2_Value_jq[minreg] *
          rtb_SliderGain_n + controller_template_P.Constant3_Value_b[minreg];

        /* '<S60>:1:61' */
        flag_oob = 1;

        /* U = U_prev; */
        exitg = 1;
      }
    } while ((uint32_T)exitg == 0U);

    controller_template_B.U_g = U_0;
    controller_template_B.flag_oob_l = (real_T)flag_oob;

    /* End of MATLAB Function: '<S52>/Ctrl_Xdir' */

    /* Gain: '<S55>/Gain' incorporates:
     *  Saturate: '<S26>/Saturation1'
     *  Sum: '<S55>/Sum'
     *  Sum: '<S55>/Sum1'
     *  UnitDelay: '<S55>/Unit Delay'
     *  UnitDelay: '<S55>/Unit Delay2'
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
    rtb_UnitDelay_g = controller_template_B.Gain_n - controller_template_B.Gain2;

    /* Sum: '<S11>/Sum5' incorporates:
     *  Sum: '<S11>/Sum2'
     */
    controller_template_B.thrust_cmd_a = (controller_template_B.Gain_i -
      rtb_bias_W[2]) + rtb_Product_l;

    /* RateTransition: '<S29>/Rate Transition1' */
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      controller_template_B.RateTransition1 = controller_template_B.Gain_pk;

      /* RateTransition: '<S30>/Rate Transition1' */
      controller_template_B.RateTransition1_l = controller_template_B.Gain_pk;
    }

    /* End of RateTransition: '<S29>/Rate Transition1' */

    /* UnitDelay: '<S34>/Unit Delay1' */
    rtb_SliderGain_n = controller_template_DWork.UnitDelay1_DSTATE_a;

    /* RateTransition: '<S45>/Rate Transition1' */
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      controller_template_B.RateTransition1_lq = controller_template_B.Gain_f;
    }

    /* End of RateTransition: '<S45>/Rate Transition1' */

    /* UnitDelay: '<S46>/Unit Delay1' */
    rtb_SliderGain_e3 = controller_template_DWork.UnitDelay1_DSTATE_ji;

    /* Gain: '<S26>/Gain' */
    controller_template_B.Gain_g = controller_template_P.Gain_Gain_b *
      controller_template_B.psi_out;

    /* UnitDelay: '<S55>/Unit Delay1' */
    rtb_Saturation2_l = controller_template_DWork.UnitDelay1_DSTATE_c3;

    /* Gain: '<S27>/Gain1' */
    controller_template_B.Gain1 = controller_template_P.Gain1_Gain *
      controller_template_B.DataTypeConversion[8];

    /* Gain: '<S27>/Gain' */
    controller_template_B.Gain_d = controller_template_P.Gain_Gain_e *
      controller_template_B.psi_prime;

    /* Update for Delay: '<S11>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE_k = rtb_UnitDelay_g;

    /* Update for UnitDelay: '<S27>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_bg, (void *)
           (&controller_template_B.sf_discretekalmanfilter.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S64>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S64>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
      controller_template_P.FixPtConstant_Value;

    /* Update for UnitDelay: '<S64>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0] =
      controller_template_B.sf_discretekalmanfilter.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1] =
      controller_template_B.sf_discretekalmanfilter.state_est[1];
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for UnitDelay: '<S30>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE =
        controller_template_B.RateTransition1_l;

      /* Update for UnitDelay: '<S29>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_m =
        controller_template_B.RateTransition1;
    }

    /* Update for UnitDelay: '<S34>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_d =
      controller_template_B.Gain_pk;

    /* Update for UnitDelay: '<S34>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_jv = rtb_SliderGain_n;
    if (controller_template_M->Timing.TaskCounters.TID[2] == 0) {
      /* Update for UnitDelay: '<S45>/Unit Delay2' */
      controller_template_DWork.UnitDelay2_DSTATE_l =
        controller_template_B.RateTransition1_lq;
    }

    /* Update for UnitDelay: '<S46>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_k = controller_template_B.Gain_f;

    /* Update for UnitDelay: '<S46>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_f = rtb_SliderGain_e3;

    /* Update for UnitDelay: '<S67>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_b = controller_template_B.Gain_i;

    /* Update for UnitDelay: '<S67>/Unit Delay' incorporates:
     *  UnitDelay: '<S67>/Unit Delay1'
     */
    controller_template_DWork.UnitDelay_DSTATE_fw =
      controller_template_DWork.UnitDelay1_DSTATE_m;

    /* Update for UnitDelay: '<S26>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_lg =
      controller_template_B.psi_prime_l;

    /* Update for UnitDelay: '<S52>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_g = controller_template_B.Gain_n;

    /* Update for UnitDelay: '<S55>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_ga =
      controller_template_B.Gain_n;

    /* Update for UnitDelay: '<S55>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_p = rtb_Saturation2_l;

    /* Update for UnitDelay: '<S34>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_a =
      controller_template_B.Gain_pk;

    /* Update for UnitDelay: '<S46>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_ji =
      controller_template_B.Gain_f;

    /* Update for UnitDelay: '<S55>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_c3 =
      controller_template_B.Gain_n;

    /* Update for UnitDelay: '<S67>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_m = controller_template_B.Gain_i;

    /* End of Outputs for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

    /* SignalConversion: '<S16>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFi_a[0] =
      controller_template_B.DataTypeConversion[0];
    rtb_TmpSignalConversionAtToFi_a[1] =
      controller_template_B.DataTypeConversion[3];
    rtb_TmpSignalConversionAtToFi_a[2] =
      controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot;
    rtb_TmpSignalConversionAtToFi_a[3] = controller_template_B.x_ref;
    rtb_TmpSignalConversionAtToFi_a[4] = rtb_UnitDelay2_a;
    rtb_TmpSignalConversionAtToFi_a[5] =
      controller_template_B.DataTypeConversion[1];
    rtb_TmpSignalConversionAtToFi_a[6] =
      controller_template_B.DataTypeConversion[4];
    rtb_TmpSignalConversionAtToFi_a[7] =
      controller_template_B.sf_EmbeddedMATLABFunction.roll_rot;
    rtb_TmpSignalConversionAtToFi_a[8] = controller_template_B.y_ref_h;
    rtb_TmpSignalConversionAtToFi_a[9] = rtb_roll_cmd_c;
    rtb_TmpSignalConversionAtToFi_a[10] =
      controller_template_B.DataTypeConversion[2];
    rtb_TmpSignalConversionAtToFi_a[11] =
      controller_template_B.DataTypeConversion[5];
    rtb_TmpSignalConversionAtToFi_a[12] = controller_template_B.z_ref_n;
    rtb_TmpSignalConversionAtToFi_a[13] = controller_template_B.thrust_cmd_a;
    rtb_TmpSignalConversionAtToFi_a[14] =
      controller_template_B.DataTypeConversion[8];
    rtb_TmpSignalConversionAtToFi_a[15] =
      controller_template_B.DataTypeConversion[11];
    rtb_TmpSignalConversionAtToFi_a[16] = rtb_yaw_ref;
    rtb_TmpSignalConversionAtToFi_a[17] = rtb_UnitDelay_g;

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
      controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot;
    controller_template_B.raddeg2_p[1] = controller_template_P.raddeg2_Gain *
      controller_template_B.DataTypeConversion[10];
    controller_template_B.raddeg2_p[2] = controller_template_P.raddeg2_Gain *
      rtb_UnitDelay2_a;

    /* Gain: '<S16>/rad -> deg1' */
    controller_template_B.raddeg1_e[0] = controller_template_P.raddeg1_Gain *
      controller_template_B.sf_EmbeddedMATLABFunction.roll_rot;
    controller_template_B.raddeg1_e[1] = controller_template_P.raddeg1_Gain *
      rtb_roll_cmd_c;

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_5_Threshold) {
      controller_template_B.x_dot_ref = rtb_X_ref_x[1];
    } else {
      controller_template_B.x_dot_ref =
        controller_template_B.sf_generate_X_ref_x_k.X_ref_x[1];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_6_Threshold) {
      controller_template_B.y_dot_ref = rtb_X_ref_y[1];
    } else {
      controller_template_B.y_dot_ref =
        controller_template_B.sf_generate_X_ref_y_a.X_ref_y[1];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* Gain: '<S16>/rad -> deg3' */
    controller_template_B.raddeg3_a[0] = controller_template_P.raddeg3_Gain *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg3_a[1] = controller_template_P.raddeg3_Gain *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg3_a[2] = controller_template_P.raddeg3_Gain *
      rtb_UnitDelay_g;

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
      u = rtb_X_ref_yaw[1];
    } else {
      u = controller_template_B.sf_generate_X_ref_yaw_g.X_ref_yaw[1];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* Gain: '<S16>/rad -> deg' */
    controller_template_B.raddeg_j[3] = controller_template_P.raddeg_Gain * u;

    /* Switch: '<S12>/SwitchControl' incorporates:
     *  Constant: '<S12>/Constant'
     */
    if (controller_template_P.Constant_Value_ph >
        controller_template_P.SwitchControl_7_Threshold) {
      controller_template_B.z_dot_ref = rtb_X_ref_z[1];
    } else {
      controller_template_B.z_dot_ref =
        controller_template_B.sf_generate_X_ref_z_l.X_ref_z[1];
    }

    /* End of Switch: '<S12>/SwitchControl' */

    /* Outputs for Atomic SubSystem: '<S2>/decoupling and rotation' */
    /* Inport: '<S14>/bias_W' */
    controller_template_B.bias_W_b[0] = rtb_TmpSignalConversionAtToFi_p[0];
    controller_template_B.bias_W_b[1] = rtb_TmpSignalConversionAtToFi_p[1];
    controller_template_B.bias_W_b[2] = rtb_TmpSignalConversionAtToFi_p[2];
    controller_template_B.bias_W_b[3] = rtb_TmpSignalConversionAtToFi_p[3];

    /* Inport: '<S14>/cmd_W' */
    controller_template_B.cmd_W_h[0] = rtb_UnitDelay2_a;
    controller_template_B.cmd_W_h[1] = rtb_roll_cmd_c;
    controller_template_B.cmd_W_h[2] = controller_template_B.thrust_cmd_a;
    controller_template_B.cmd_W_h[3] = rtb_UnitDelay_g;

    /* Sum: '<S85>/Add' incorporates:
     *  Constant: '<S85>/Constant'
     *  Gain: '<S87>/Slider Gain'
     */
    rtb_Add_k = controller_template_B.DataTypeConversion[0] -
      controller_template_P.SliderGain_Gain_n *
      controller_template_P.Constant_Value_k;

    /* Gain: '<S88>/Slider Gain' incorporates:
     *  Constant: '<S85>/Constant1'
     */
    rtb_SliderGain_m = controller_template_P.SliderGain_Gain_i *
      controller_template_P.Constant1_Value_i;

    /* MATLAB Function: '<S85>/MATLAB Function' */
    controller_tem_MATLABFunction_e(rtb_Add_k, rtb_SliderGain_m,
      &controller_template_B.sf_MATLABFunction_p,
      &controller_template_DWork.sf_MATLABFunction_p);

    /* MATLAB Function: '<S82>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S82>/g'
     *  Saturate: '<S85>/Saturation3'
     */
    controller_template_DWork.sfEvent_c = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Embedded MATLAB Function': '<S84>:1' */
    /* '<S84>:1:3' */
    if ((controller_template_B.sf_MATLABFunction_p.y >=
         controller_template_P.Saturation3_UpperSat_p ?
         controller_template_P.Saturation3_UpperSat_p :
         controller_template_B.sf_MATLABFunction_p.y <=
         controller_template_P.Saturation3_LowerSat_e ?
         controller_template_P.Saturation3_LowerSat_e :
         controller_template_B.sf_MATLABFunction_p.y) == 0.0) {
      /* '<S84>:1:5' */
      /* '<S84>:1:6' */
      rtb_SliderGain_n = controller_template_B.cmd_W_h[2] / (cos
        (controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot) * cos
        (controller_template_B.sf_EmbeddedMATLABFunction.roll_rot));
      if ((fabs(controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot) >=
           0.069813170079773182) && (fabs
           (controller_template_B.sf_EmbeddedMATLABFunction.roll_rot) >=
           0.069813170079773182)) {
        /* '<S84>:1:8' */
        /* '<S84>:1:9' */
        rtb_SliderGain_n = controller_template_B.cmd_W_h[2] /
          0.99513403437078507;
      } else if (fabs(controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot)
                 >= 0.069813170079773182) {
        /* '<S84>:1:10' */
        /* '<S84>:1:11' */
        rtb_SliderGain_n = controller_template_B.cmd_W_h[2] /
          (0.9975640502598242 * cos
           (controller_template_B.sf_EmbeddedMATLABFunction.roll_rot));
      } else {
        if (fabs(controller_template_B.sf_EmbeddedMATLABFunction.roll_rot) >=
            0.069813170079773182) {
          /* '<S84>:1:12' */
          /* '<S84>:1:13' */
          rtb_SliderGain_n = controller_template_B.cmd_W_h[2] / (cos
            (controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot) *
            0.9975640502598242);
        }
      }
    } else {
      /* '<S84>:1:16' */
      rtb_SliderGain_n = controller_template_B.cmd_W_h[2] / (cos
        (controller_template_B.sf_EmbeddedMATLABFunction.pitch_rot) * cos
        (controller_template_B.sf_EmbeddedMATLABFunction.roll_rot));
    }

    /* '<S84>:1:18' */
    controller_template_B.pitch_cmd_comp_n =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value / rtb_SliderGain_n *
      controller_template_B.cmd_W_h[0];

    /* '<S84>:1:19' */
    controller_template_B.roll_cmd_comp_j =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value / rtb_SliderGain_n *
      controller_template_B.cmd_W_h[1];

    /*  pitch_cmd_comp=pitch_cmd; */
    /*  roll_cmd_comp=roll_cmd; */
    /*  pitch_cmd_comp = atan(Fx/(-thrust_comp)); */
    /*  roll_cmd_comp = atan(Fy/(thrust_comp)); */
    /*  pitch_cmd_comp = atan(-g*m*pitch_cmd/(-thrust)); */
    /*  roll_cmd_comp = atan(g*m*roll_cmd*cos(pitch_meas)/(thrust)); */
    controller_template_B.thrust_comp_k = rtb_SliderGain_n;

    /* End of MATLAB Function: '<S82>/Embedded MATLAB Function' */

    /* MATLAB Function: '<S83>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_j = CALL_EVENT;

    /* MATLAB Function 'FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S89>:1' */
    /* '<S89>:1:3' */
    rtb_SliderGain_n = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S89>:1:4' */
    rtb_SliderGain_e3 = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S89>:1:6' */
    /* '<S89>:1:8' */
    /* '<S89>:1:9' */
    controller_template_B.pitch_rot_n = rtb_SliderGain_e3 *
      controller_template_B.pitch_cmd_comp_n + -rtb_SliderGain_n *
      controller_template_B.roll_cmd_comp_j;

    /* '<S89>:1:10' */
    controller_template_B.roll_rot_e = rtb_SliderGain_n *
      controller_template_B.pitch_cmd_comp_n + rtb_SliderGain_e3 *
      controller_template_B.roll_cmd_comp_j;

    /* '<S89>:1:12' */
    /* '<S89>:1:13' */
    controller_template_B.pitch_bias_rot_i = rtb_SliderGain_e3 *
      controller_template_B.bias_W_b[0] + -rtb_SliderGain_n *
      controller_template_B.bias_W_b[1];

    /* '<S89>:1:14' */
    controller_template_B.roll_bias_rot_d = rtb_SliderGain_n *
      controller_template_B.bias_W_b[0] + rtb_SliderGain_e3 *
      controller_template_B.bias_W_b[1];

    /* End of Outputs for SubSystem: '<S2>/decoupling and rotation' */

    /* Update for UnitDelay: '<S69>/Unit Delay' */
    controller_template_DWork.UnitDelay_2_DSTATE = rtb_X_ref_y[0];

    /* Update for UnitDelay: '<S69>/Unit Delay' */
    controller_template_DWork.UnitDelay_3_DSTATE = rtb_X_ref_z[0];

    /* Update for UnitDelay: '<S73>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_g = rtb_Sum_c;

    /* Update for UnitDelay: '<S17>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_e = rtb_Sum_f;
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
      /* InitializeConditions for MATLAB Function: '<S96>/Embedded MATLAB Function' */
      con_EmbeddedMATLABFunction_Init
        (&controller_template_DWork.sf_EmbeddedMATLABFunction_o);

      /* InitializeConditions for Atomic SubSystem: '<S9>/MAIN CONTROL LOOP1' */
      /* InitializeConditions for Delay: '<S93>/Integer Delay' */
      controller_template_DWork.IntegerDelay_DSTATE =
        controller_template_P.IntegerDelay_InitialCondition;

      /* InitializeConditions for Delay: '<S93>/Integer Delay1' */
      controller_template_DWork.IntegerDelay1_DSTATE =
        controller_template_P.IntegerDelay1_InitialCondition;

      /* InitializeConditions for Delay: '<S93>/Integer Delay2' */
      controller_template_DWork.IntegerDelay2_DSTATE =
        controller_template_P.IntegerDelay2_InitialCondition;

      /* InitializeConditions for Delay: '<S93>/Integer Delay3' */
      controller_template_DWork.IntegerDelay3_DSTATE =
        controller_template_P.IntegerDelay3_InitialConditio_c;

      /* InitializeConditions for UnitDelay: '<S100>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
             controller_template_P.UnitDelay1_X0_c, sizeof(real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S108>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
        controller_template_P.FixPtUnitDelay2_X0_d;

      /* InitializeConditions for UnitDelay: '<S108>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
        controller_template_P.FixPtUnitDelay1_X0_f;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
        controller_template_P.FixPtUnitDelay1_X0_f;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
        controller_template_P.FixPtUnitDelay1_X0_f;

      /* InitializeConditions for MATLAB Function: '<S100>/discrete kalman filter' */
      con_discretekalmanfilter_k_Init
        (&controller_template_DWork.sf_discretekalmanfilter_b);

      /* InitializeConditions for UnitDelay: '<S99>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE[0] =
        controller_template_P.UnitDelay_X0_fc[0];
      controller_template_DWork.UnitDelay_DSTATE[1] =
        controller_template_P.UnitDelay_X0_fc[1];
      controller_template_DWork.UnitDelay_DSTATE[2] =
        controller_template_P.UnitDelay_X0_fc[2];

      /* InitializeConditions for UnitDelay: '<S99>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
             controller_template_P.UnitDelay1_X0_k, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S99>/runFastGradient' */
      controller_runFastGradient_Init
        (&controller_template_DWork.sf_runFastGradient);

      /* InitializeConditions for UnitDelay: '<S102>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
             controller_template_P.UnitDelay1_X0_fk, sizeof(real_T) << 4U);

      /* InitializeConditions for UnitDelay: '<S111>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
        controller_template_P.FixPtUnitDelay2_X0_n;

      /* InitializeConditions for UnitDelay: '<S111>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
        controller_template_P.FixPtUnitDelay1_X0_n;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
        controller_template_P.FixPtUnitDelay1_X0_n;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
        controller_template_P.FixPtUnitDelay1_X0_n;

      /* InitializeConditions for MATLAB Function: '<S102>/discrete kalman filter' */
      con_discretekalmanfilter_k_Init
        (&controller_template_DWork.sf_discretekalmanfilter_m);

      /* InitializeConditions for UnitDelay: '<S101>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_j[0] =
        controller_template_P.UnitDelay_X0_ik[0];
      controller_template_DWork.UnitDelay_DSTATE_j[1] =
        controller_template_P.UnitDelay_X0_ik[1];
      controller_template_DWork.UnitDelay_DSTATE_j[2] =
        controller_template_P.UnitDelay_X0_ik[2];

      /* InitializeConditions for UnitDelay: '<S101>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
             controller_template_P.UnitDelay1_X0_jc, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S101>/runFastGradient' */
      controller_runFastGradient_Init
        (&controller_template_DWork.sf_runFastGradient_d);

      /* InitializeConditions for UnitDelay: '<S106>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
             controller_template_P.UnitDelay1_X0_cw, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S117>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
        controller_template_P.FixPtUnitDelay2_X0_do;

      /* InitializeConditions for UnitDelay: '<S117>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
        controller_template_P.FixPtUnitDelay1_X0_c;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
        controller_template_P.FixPtUnitDelay1_X0_c;

      /* InitializeConditions for MATLAB Function: '<S106>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter_k);

      /* InitializeConditions for UnitDelay: '<S105>/Unit Delay' */
      controller_template_DWork.UnitDelay_DSTATE_l[0] =
        controller_template_P.UnitDelay_X0_a[0];
      controller_template_DWork.UnitDelay_DSTATE_l[1] =
        controller_template_P.UnitDelay_X0_a[1];

      /* InitializeConditions for UnitDelay: '<S105>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
             controller_template_P.UnitDelay1_X0_b, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S105>/runFastGradient' */
      controller_template_DWork.sfEvent_k = CALL_EVENT;
      controller_template_DWork.is_active_c8_Hquad_control_LIB_ = 0U;

      /* InitializeConditions for UnitDelay: '<S104>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
             controller_template_P.UnitDelay1_X0_n, 9U * sizeof(real_T));

      /* InitializeConditions for UnitDelay: '<S114>/FixPt Unit Delay2' */
      controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
        controller_template_P.FixPtUnitDelay2_X0_i;

      /* InitializeConditions for UnitDelay: '<S114>/FixPt Unit Delay1' */
      controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
        controller_template_P.FixPtUnitDelay1_X0_e;
      controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
        controller_template_P.FixPtUnitDelay1_X0_e;

      /* InitializeConditions for MATLAB Function: '<S104>/discrete kalman filter' */
      contr_discretekalmanfilter_Init
        (&controller_template_DWork.sf_discretekalmanfilter_n);

      /* InitializeConditions for UnitDelay: '<S103>/Unit Delay' */
      for (i = 0; i < 6; i++) {
        controller_template_DWork.UnitDelay_DSTATE_jz[i] =
          controller_template_P.UnitDelay_X0_fj[i];
      }

      /* End of InitializeConditions for UnitDelay: '<S103>/Unit Delay' */

      /* InitializeConditions for UnitDelay: '<S103>/Unit Delay1' */
      memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
             controller_template_P.UnitDelay1_X0_o, 30U * sizeof(real_T));

      /* InitializeConditions for MATLAB Function: '<S103>/runFastGradient' */
      controller_template_DWork.sfEvent_n = CALL_EVENT;
      controller_template_DWork.is_active_c9_Hquad_control_LIB_ = 0U;

      /* End of InitializeConditions for SubSystem: '<S9>/MAIN CONTROL LOOP1' */

      /* InitializeConditions for Atomic SubSystem: '<S9>/decoupling and rotation' */
      /* InitializeConditions for MATLAB Function: '<S119>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent_f = CALL_EVENT;
      controller_template_DWork.is_active_c1_Hquad_control_LIB_ = 0U;

      /* InitializeConditions for MATLAB Function: '<S120>/Embedded MATLAB Function' */
      controller_template_DWork.sfEvent = CALL_EVENT;
      controller_template_DWork.is_active_c4_Hquad_control_LIB_ = 0U;

      /* End of InitializeConditions for SubSystem: '<S9>/decoupling and rotation' */
      controller_template_DWork.poscontroller_MODE = TRUE;
    }

    /* MATLAB Function: '<S96>/Embedded MATLAB Function' */
    controll_EmbeddedMATLABFunction(controller_template_B.DataTypeConversion[6],
      controller_template_B.DataTypeConversion[7], rtb_Init[0], rtb_Init[1],
      controller_template_B.DataTypeConversion[8],
      &controller_template_B.sf_EmbeddedMATLABFunction_o,
      &controller_template_DWork.sf_EmbeddedMATLABFunction_o);

    /* Outputs for Atomic SubSystem: '<S9>/MAIN CONTROL LOOP1' */
    /* Delay: '<S93>/Integer Delay' */
    rtb_IntegerDelay = controller_template_DWork.IntegerDelay_DSTATE;

    /* Delay: '<S93>/Integer Delay1' */
    rtb_IntegerDelay1 = controller_template_DWork.IntegerDelay1_DSTATE;

    /* Delay: '<S93>/Integer Delay2' */
    rtb_IntegerDelay2 = controller_template_DWork.IntegerDelay2_DSTATE;

    /* Delay: '<S93>/Integer Delay3' */
    rtb_IntegerDelay3 = controller_template_DWork.IntegerDelay3_DSTATE;

    /* Product: '<S93>/Product' incorporates:
     *  Constant: '<S93>/gravity'
     */
    rtb_UnitDelay_g = controller_template_P.gravity_Value_j *
      controller_template_B.DataTypeConversion[29];

    /* UnitDelay: '<S100>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE, sizeof(real_T) << 4U);

    /* Switch: '<S108>/Init' incorporates:
     *  UnitDelay: '<S108>/FixPt Unit Delay1'
     *  UnitDelay: '<S108>/FixPt Unit Delay2'
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

    /* End of Switch: '<S108>/Init' */

    /* MATLAB Function: '<S100>/discrete kalman filter' */
    controll_discretekalmanfilter_b(controller_template_B.DataTypeConversion[0],
      controller_template_B.DataTypeConversion[3],
      controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_rot, rtb_Init_g,
      controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_bias_rot,
      controller_template_P.A_Value_h, controller_template_P.B_Value_i,
      controller_template_P.C_Value_c, controller_template_P.Q_Value_a,
      controller_template_P.R_Value_c, rtb_IntegerDelay, rtb_UnitDelay1,
      &controller_template_B.sf_discretekalmanfilter_b,
      &controller_template_DWork.sf_discretekalmanfilter_b);

    /* UnitDelay: '<S99>/Unit Delay' */
    rtb_UnitDelay[0] = controller_template_DWork.UnitDelay_DSTATE[0];
    rtb_UnitDelay[1] = controller_template_DWork.UnitDelay_DSTATE[1];
    rtb_UnitDelay[2] = controller_template_DWork.UnitDelay_DSTATE[2];

    /* UnitDelay: '<S99>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_o[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_c, 30U * sizeof(real_T));

    /* MATLAB Function: '<S99>/runFastGradient' */
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

    /* Saturate: '<S100>/Saturation' */
    rtb_UnitDelay2_a =
      controller_template_B.sf_discretekalmanfilter_b.state_est[3] >=
      controller_template_P.Saturation_UpperSat_ia ?
      controller_template_P.Saturation_UpperSat_ia :
      controller_template_B.sf_discretekalmanfilter_b.state_est[3] <=
      controller_template_P.Saturation_LowerSat_o ?
      controller_template_P.Saturation_LowerSat_o :
      controller_template_B.sf_discretekalmanfilter_b.state_est[3];

    /* Sum: '<S93>/Sum' */
    sumViol = controller_template_B.sf_runFastGradient.u_opt - rtb_UnitDelay2_a;

    /* UnitDelay: '<S102>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_oh[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_b, sizeof(real_T) << 4U);

    /* Switch: '<S111>/Init' incorporates:
     *  UnitDelay: '<S111>/FixPt Unit Delay1'
     *  UnitDelay: '<S111>/FixPt Unit Delay2'
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

    /* End of Switch: '<S111>/Init' */

    /* MATLAB Function: '<S102>/discrete kalman filter' */
    controll_discretekalmanfilter_b(controller_template_B.DataTypeConversion[1],
      controller_template_B.DataTypeConversion[4],
      controller_template_B.sf_EmbeddedMATLABFunction_o.roll_rot, rtb_Init_j,
      controller_template_B.sf_EmbeddedMATLABFunction_o.roll_bias_rot,
      controller_template_P.A_Value_n, controller_template_P.B_Value_h,
      controller_template_P.C_Value_p, controller_template_P.Q_Value_h,
      controller_template_P.R_Value_l, rtb_IntegerDelay1, rtb_UnitDelay1_oh,
      &controller_template_B.sf_discretekalmanfilter_m,
      &controller_template_DWork.sf_discretekalmanfilter_m);

    /* UnitDelay: '<S101>/Unit Delay' */
    rtb_UnitDelay_e[0] = controller_template_DWork.UnitDelay_DSTATE_j[0];
    rtb_UnitDelay_e[1] = controller_template_DWork.UnitDelay_DSTATE_j[1];
    rtb_UnitDelay_e[2] = controller_template_DWork.UnitDelay_DSTATE_j[2];

    /* UnitDelay: '<S101>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_g[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_l, 30U * sizeof(real_T));

    /* MATLAB Function: '<S101>/runFastGradient' */
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

    /* Saturate: '<S102>/Saturation' */
    rtb_roll_cmd_c = controller_template_B.sf_discretekalmanfilter_m.state_est[3]
      >= controller_template_P.Saturation_UpperSat_f ?
      controller_template_P.Saturation_UpperSat_f :
      controller_template_B.sf_discretekalmanfilter_m.state_est[3] <=
      controller_template_P.Saturation_LowerSat_k ?
      controller_template_P.Saturation_LowerSat_k :
      controller_template_B.sf_discretekalmanfilter_m.state_est[3];

    /* Sum: '<S93>/Sum1' */
    roll_cmd_f = controller_template_B.sf_runFastGradient_d.u_opt -
      rtb_roll_cmd_c;

    /* UnitDelay: '<S106>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_j[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_j, 9U * sizeof(real_T));

    /* Switch: '<S117>/Init' incorporates:
     *  UnitDelay: '<S117>/FixPt Unit Delay1'
     *  UnitDelay: '<S117>/FixPt Unit Delay2'
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

    /* End of Switch: '<S117>/Init' */

    /* MATLAB Function: '<S106>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.DataTypeConversion[2],
      controller_template_B.DataTypeConversion[5], rtb_Init_d, rtb_Init[2],
      controller_template_P.A_Value_f, controller_template_P.B_Value_n,
      controller_template_P.C_Value_o, controller_template_P.Q_Value_j,
      controller_template_P.R_Value_ca, rtb_IntegerDelay2, rtb_UnitDelay1_j,
      &controller_template_B.sf_discretekalmanfilter_k,
      &controller_template_DWork.sf_discretekalmanfilter_k);

    /* MATLAB Function: '<S105>/runFastGradient' incorporates:
     *  Constant: '<S105>/AA_delay'
     *  Constant: '<S105>/BB_delay'
     *  Constant: '<S105>/L'
     *  Constant: '<S105>/LL_PP'
     *  Constant: '<S105>/LL_U_ref_PP'
     *  Constant: '<S105>/LL_ref_PP'
     *  Constant: '<S105>/MM'
     *  Constant: '<S105>/PP'
     *  Constant: '<S105>/TT_PP'
     *  Constant: '<S105>/V_max'
     *  Constant: '<S105>/betas'
     *  Constant: '<S105>/i_min'
     *  UnitDelay: '<S105>/Unit Delay'
     *  UnitDelay: '<S105>/Unit Delay1'
     */
    controller_template_DWork.sfEvent_k = CALL_EVENT;

    /* MATLAB Function 'z controller MPC FG/runFastGradient': '<S116>:1' */
    /*  ugly, but simulink needs fix output sizes for vectors */
    /*  number of outputs u */
    /*  number of delay steps */
    /*  prediction horizon */
    /*  predict non-delayed state */
    /* '<S116>:1:14' */
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
    /* '<S116>:1:21' */
    for (i = 0; i < 30; i++) {
      temp[i] = 0.0;
      temp[i] += controller_template_P.LL_PP_Value_j[(i << 1)] * temp_idx;
      temp[i] += controller_template_P.LL_PP_Value_j[(i << 1) + 1] * temp_idx_0;
      tmp_2[i] = 0.0;
      for (ireg = 0; ireg < 62; ireg++) {
        tmp_2[i] += controller_template_P.LL_ref_PP_Value_h[62 * i + ireg] *
          controller_template_B.X_ref_z[ireg];
      }
    }

    for (i = 0; i < 30; i++) {
      u = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        u += controller_template_P.LL_U_ref_PP_Value_o[30 * i + ireg] * 0.0;
      }

      LL_PP_ref[i] = (temp[i] - tmp_2[i]) - u;
    }

    /* '<S116>:1:22' */
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
    rtb_SliderGain_n = 1.0 / controller_template_P.L_Value_m;
    for (i = 0; i < 30; i++) {
      u = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        u += controller_template_P.TT_PP_Value_b[30 * ireg + i] *
          controller_template_DWork.UnitDelay1_DSTATE_g[ireg];
      }

      tmp_2[i] = u + LL_PP_ref[i];
    }

    for (i = 0; i < 30; i++) {
      abspos = controller_template_DWork.UnitDelay1_DSTATE_g[i] -
        rtb_SliderGain_n * tmp_2[i];
      u = (controller_template_P.V_max_Value_i[i] <= abspos) || rtIsNaN(abspos) ?
        controller_template_P.V_max_Value_i[i] : abspos;
      rtb_Saturation2_l = (temp[i] >= u) || rtIsNaN(u) ? temp[i] : u;
      V_ip[i] = rtb_Saturation2_l;
      V_i[i] = rtb_Saturation2_l;
      U_star[i] = abspos;
    }

    /*  now run the fast gradient method: */
    for (dz = 0; dz <= (int32_T)controller_template_P.i_min_Value_o - 1; dz++) {
      for (i = 0; i < 30; i++) {
        u = 0.0;
        for (ireg = 0; ireg < 30; ireg++) {
          u += controller_template_P.TT_PP_Value_b[30 * ireg + i] * V_ip[ireg];
        }

        tmp_2[i] = u + LL_PP_ref[i];
      }

      /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
      /*      convergence result idea */
      for (i = 0; i < 30; i++) {
        abspos = V_ip[i] - rtb_SliderGain_n * tmp_2[i];
        u = (controller_template_P.V_max_Value_i[i] <= abspos) || rtIsNaN(abspos)
          ? controller_template_P.V_max_Value_i[i] : abspos;
        u = (temp[i] >= u) || rtIsNaN(u) ? temp[i] : u;
        abspos = controller_template_P.betas_Value_g[(int32_T)(1.0 + (real_T)dz)
          - 1] * (u - V_i[i]);
        rtb_Saturation2_l = u;
        u += abspos;
        U_star[i] = abspos;
        V_i[i] = rtb_Saturation2_l;
        V_ip[i] = u;
      }
    }

    /*  return values: */
    rtb_SliderGain_n = 0.0;
    rtb_SliderGain_e3 = 0.0;

    /*  plot(residuals) just for testing new convergence result idea */
    /* '<S116>:1:25' */
    /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
    /*  so don't forget to backtransform after termination: */
    /* '<S116>:1:32' */
    for (i = 0; i < 30; i++) {
      b_y[i] = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        b_y[i] += controller_template_P.TT_PP_Value_b[30 * i + ireg] * (0.5 *
          V_i[ireg]);
      }

      rtb_SliderGain_n += b_y[i] * V_i[i];
      rtb_SliderGain_e3 += LL_PP_ref[i] * V_i[i];
      U_star[i] = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        U_star[i] += controller_template_P.PP_Value_o[30 * ireg + i] * V_i[ireg];
      }
    }

    /*  save outputs for delayed system */
    /* '<S116>:1:38' */
    /*  set new initial guess */
    /* '<S116>:1:42' */
    /* '<S116>:1:44' */
    controller_template_B.u_opt = U_star[0];
    controller_template_B.J_star = ((temp_idx *
      controller_template_P.MM_Value_l[0] + temp_idx_0 *
      controller_template_P.MM_Value_l[1]) * temp_idx + (temp_idx *
      controller_template_P.MM_Value_l[2] + temp_idx_0 *
      controller_template_P.MM_Value_l[3]) * temp_idx_0) + (rtb_SliderGain_n +
      rtb_SliderGain_e3);
    controller_template_B.u_buff_out[0] =
      controller_template_DWork.UnitDelay_DSTATE_l[1];
    controller_template_B.u_buff_out[1] = U_star[0];
    memcpy((void *)(&controller_template_B.V_init_out[0]), (void *)&V_i[1], 29U *
           sizeof(real_T));
    controller_template_B.V_init_out[29] = 0.0;

    /* End of MATLAB Function: '<S105>/runFastGradient' */

    /* Saturate: '<S106>/Saturation' */
    rtb_Saturation_n =
      controller_template_B.sf_discretekalmanfilter_k.state_est[2] >=
      controller_template_P.Saturation_UpperSat_l ?
      controller_template_P.Saturation_UpperSat_l :
      controller_template_B.sf_discretekalmanfilter_k.state_est[2] <=
      controller_template_P.Saturation_LowerSat_cp ?
      controller_template_P.Saturation_LowerSat_cp :
      controller_template_B.sf_discretekalmanfilter_k.state_est[2];

    /* Sum: '<S93>/Sum2' */
    tolerance = controller_template_B.u_opt - rtb_Saturation_n;

    /* UnitDelay: '<S104>/Unit Delay1' */
    memcpy((void *)&rtb_UnitDelay1_n[0], (void *)
           controller_template_DWork.UnitDelay1_DSTATE_lx, 9U * sizeof(real_T));

    /* Switch: '<S114>/Init' incorporates:
     *  UnitDelay: '<S114>/FixPt Unit Delay1'
     *  UnitDelay: '<S114>/FixPt Unit Delay2'
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

    /* End of Switch: '<S114>/Init' */

    /* MATLAB Function: '<S104>/discrete kalman filter' */
    controller_discretekalmanfilter(controller_template_B.DataTypeConversion[8],
      controller_template_B.DataTypeConversion[11], rtb_Init_h, rtb_Init[3],
      controller_template_P.A_Value_k, controller_template_P.B_Value_f,
      controller_template_P.C_Value_b, controller_template_P.Q_Value_g,
      controller_template_P.R_Value_o, rtb_IntegerDelay3, rtb_UnitDelay1_n,
      &controller_template_B.sf_discretekalmanfilter_n,
      &controller_template_DWork.sf_discretekalmanfilter_n);

    /* MATLAB Function: '<S103>/runFastGradient' incorporates:
     *  Constant: '<S103>/AA_delay'
     *  Constant: '<S103>/BB_delay'
     *  Constant: '<S103>/L'
     *  Constant: '<S103>/LL_PP'
     *  Constant: '<S103>/LL_U_ref_PP'
     *  Constant: '<S103>/LL_ref_PP'
     *  Constant: '<S103>/MM'
     *  Constant: '<S103>/PP'
     *  Constant: '<S103>/TT_PP'
     *  Constant: '<S103>/V_max'
     *  Constant: '<S103>/betas'
     *  Constant: '<S103>/i_min'
     *  UnitDelay: '<S103>/Unit Delay'
     *  UnitDelay: '<S103>/Unit Delay1'
     */
    controller_template_DWork.sfEvent_n = CALL_EVENT;

    /* MATLAB Function 'yaw controller MPC FG/runFastGradient': '<S113>:1' */
    /*  ugly, but simulink needs fix output sizes for vectors */
    /*  number of outputs u */
    /*  number of delay steps */
    /*  prediction horizon */
    /*  predict non-delayed state */
    /* '<S113>:1:14' */
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
    temp_idx_0 = (controller_template_P.AA_delay_Value_o[1] *
                  controller_template_B.sf_discretekalmanfilter_n.state_est[0] +
                  controller_template_P.AA_delay_Value_o[3] *
                  controller_template_B.sf_discretekalmanfilter_n.state_est[1])
      + tmp_3[1];

    /*  TODO get U_ref from trajectory */
    /*  set optimization variables */
    /* '<S113>:1:21' */
    for (i = 0; i < 30; i++) {
      temp[i] = 0.0;
      temp[i] += controller_template_P.LL_PP_Value_j5[(i << 1)] * temp_idx;
      temp[i] += controller_template_P.LL_PP_Value_j5[(i << 1) + 1] * temp_idx_0;
      tmp_2[i] = 0.0;
      for (ireg = 0; ireg < 62; ireg++) {
        tmp_2[i] += controller_template_P.LL_ref_PP_Value_e[62 * i + ireg] *
          controller_template_B.X_ref_yaw[ireg];
      }
    }

    for (i = 0; i < 30; i++) {
      u = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        u += controller_template_P.LL_U_ref_PP_Value_b[30 * i + ireg] * 0.0;
      }

      LL_PP_ref[i] = (temp[i] - tmp_2[i]) - u;
    }

    /* '<S113>:1:22' */
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
    rtb_SliderGain_n = 1.0 / controller_template_P.L_Value_g;
    for (i = 0; i < 30; i++) {
      u = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        u += controller_template_P.TT_PP_Value_o[30 * ireg + i] *
          controller_template_DWork.UnitDelay1_DSTATE_js[ireg];
      }

      tmp_2[i] = u + LL_PP_ref[i];
    }

    for (i = 0; i < 30; i++) {
      abspos = controller_template_DWork.UnitDelay1_DSTATE_js[i] -
        rtb_SliderGain_n * tmp_2[i];
      u = (controller_template_P.V_max_Value_f[i] <= abspos) || rtIsNaN(abspos) ?
        controller_template_P.V_max_Value_f[i] : abspos;
      rtb_Saturation2_l = (temp[i] >= u) || rtIsNaN(u) ? temp[i] : u;
      V_ip[i] = rtb_Saturation2_l;
      V_i[i] = rtb_Saturation2_l;
      U_star[i] = abspos;
    }

    /*  now run the fast gradient method: */
    for (dz = 0; dz <= (int32_T)controller_template_P.i_min_Value_n - 1; dz++) {
      for (i = 0; i < 30; i++) {
        u = 0.0;
        for (ireg = 0; ireg < 30; ireg++) {
          u += controller_template_P.TT_PP_Value_o[30 * ireg + i] * V_ip[ireg];
        }

        tmp_2[i] = u + LL_PP_ref[i];
      }

      /*      residuals = [residuals, norm(V_ip1 - V_i)]; just for testing new */
      /*      convergence result idea */
      for (i = 0; i < 30; i++) {
        abspos = V_ip[i] - rtb_SliderGain_n * tmp_2[i];
        u = (controller_template_P.V_max_Value_f[i] <= abspos) || rtIsNaN(abspos)
          ? controller_template_P.V_max_Value_f[i] : abspos;
        u = (temp[i] >= u) || rtIsNaN(u) ? temp[i] : u;
        abspos = controller_template_P.betas_Value_j[(int32_T)(1.0 + (real_T)dz)
          - 1] * (u - V_i[i]);
        rtb_Saturation2_l = u;
        u += abspos;
        U_star[i] = abspos;
        V_i[i] = rtb_Saturation2_l;
        V_ip[i] = u;
      }
    }

    /*  return values: */
    rtb_SliderGain_n = 0.0;
    rtb_SliderGain_e3 = 0.0;

    /*  plot(residuals) just for testing new convergence result idea */
    /* '<S113>:1:25' */
    /*  Note: Fast gradient method is implemented in variable V where U = PP * V, */
    /*  so don't forget to backtransform after termination: */
    /* '<S113>:1:32' */
    for (i = 0; i < 30; i++) {
      b_y[i] = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        b_y[i] += controller_template_P.TT_PP_Value_o[30 * i + ireg] * (0.5 *
          V_i[ireg]);
      }

      rtb_SliderGain_n += b_y[i] * V_i[i];
      rtb_SliderGain_e3 += LL_PP_ref[i] * V_i[i];
      U_star[i] = 0.0;
      for (ireg = 0; ireg < 30; ireg++) {
        U_star[i] += controller_template_P.PP_Value_p[30 * ireg + i] * V_i[ireg];
      }
    }

    /*  save outputs for delayed system */
    /* '<S113>:1:38' */
    /*  set new initial guess */
    /* '<S113>:1:42' */
    /* '<S113>:1:44' */
    controller_template_B.u_opt_l = U_star[0];
    controller_template_B.J_star_h = ((temp_idx *
      controller_template_P.MM_Value_g[0] + temp_idx_0 *
      controller_template_P.MM_Value_g[1]) * temp_idx + (temp_idx *
      controller_template_P.MM_Value_g[2] + temp_idx_0 *
      controller_template_P.MM_Value_g[3]) * temp_idx_0) + (rtb_SliderGain_n +
      rtb_SliderGain_e3);
    for (i = 0; i < 5; i++) {
      controller_template_B.u_buff_out_i[i] =
        controller_template_DWork.UnitDelay_DSTATE_jz[i + 1];
    }

    controller_template_B.u_buff_out_i[5] = U_star[0];
    memcpy((void *)(&controller_template_B.V_init_out_n[0]), (void *)&V_i[1],
           29U * sizeof(real_T));
    controller_template_B.V_init_out_n[29] = 0.0;

    /* End of MATLAB Function: '<S103>/runFastGradient' */

    /* Saturate: '<S104>/Saturation' */
    rtb_SliderGain_n =
      controller_template_B.sf_discretekalmanfilter_n.state_est[2] >=
      controller_template_P.Saturation_UpperSat_o3 ?
      controller_template_P.Saturation_UpperSat_o3 :
      controller_template_B.sf_discretekalmanfilter_n.state_est[2] <=
      controller_template_P.Saturation_LowerSat_kn ?
      controller_template_P.Saturation_LowerSat_kn :
      controller_template_B.sf_discretekalmanfilter_n.state_est[2];

    /* Sum: '<S93>/Sum3' */
    rtb_SliderGain_e3 = controller_template_B.u_opt_l - rtb_SliderGain_n;

    /* Sum: '<S93>/Sum5' */
    controller_template_B.thrust_cmd_e = tolerance + rtb_UnitDelay_g;

    /* Update for Delay: '<S93>/Integer Delay' */
    controller_template_DWork.IntegerDelay_DSTATE = sumViol;

    /* Update for Delay: '<S93>/Integer Delay1' */
    controller_template_DWork.IntegerDelay1_DSTATE = roll_cmd_f;

    /* Update for Delay: '<S93>/Integer Delay2' */
    controller_template_DWork.IntegerDelay2_DSTATE = tolerance;

    /* Update for Delay: '<S93>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE = rtb_SliderGain_e3;

    /* Update for UnitDelay: '<S100>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
           (&controller_template_B.sf_discretekalmanfilter_b.P_est[0]), sizeof
           (real_T) << 4U);

    /* Update for UnitDelay: '<S108>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S108>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
      controller_template_P.FixPtConstant_Value_h;

    /* Update for UnitDelay: '<S108>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
      controller_template_B.sf_discretekalmanfilter_b.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
      controller_template_B.sf_discretekalmanfilter_b.state_est[1];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
      controller_template_B.sf_discretekalmanfilter_b.state_est[2];

    /* Update for UnitDelay: '<S99>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE[0] =
      controller_template_B.sf_runFastGradient.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE[1] =
      controller_template_B.sf_runFastGradient.u_buff_out[1];
    controller_template_DWork.UnitDelay_DSTATE[2] =
      controller_template_B.sf_runFastGradient.u_buff_out[2];

    /* Update for UnitDelay: '<S99>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
           (&controller_template_B.sf_runFastGradient.V_init_out[0]), 30U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S102>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
           (&controller_template_B.sf_discretekalmanfilter_m.P_est[0]), sizeof
           (real_T) << 4U);

    /* Update for UnitDelay: '<S111>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S111>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
      controller_template_P.FixPtConstant_Value_o;

    /* Update for UnitDelay: '<S111>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[1];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
      controller_template_B.sf_discretekalmanfilter_m.state_est[2];

    /* Update for UnitDelay: '<S101>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_j[0] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE_j[1] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[1];
    controller_template_DWork.UnitDelay_DSTATE_j[2] =
      controller_template_B.sf_runFastGradient_d.u_buff_out[2];

    /* Update for UnitDelay: '<S101>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
           (&controller_template_B.sf_runFastGradient_d.V_init_out[0]), 30U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S106>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
           (&controller_template_B.sf_discretekalmanfilter_k.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S117>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S117>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
      controller_template_P.FixPtConstant_Value_p;

    /* Update for UnitDelay: '<S117>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
      controller_template_B.sf_discretekalmanfilter_k.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
      controller_template_B.sf_discretekalmanfilter_k.state_est[1];

    /* Update for UnitDelay: '<S105>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_l[0] =
      controller_template_B.u_buff_out[0];
    controller_template_DWork.UnitDelay_DSTATE_l[1] =
      controller_template_B.u_buff_out[1];

    /* Update for UnitDelay: '<S105>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
           (&controller_template_B.V_init_out[0]), 30U * sizeof(real_T));

    /* Update for UnitDelay: '<S104>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
           (&controller_template_B.sf_discretekalmanfilter_n.P_est[0]), 9U *
           sizeof(real_T));

    /* Update for UnitDelay: '<S114>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S114>/FixPt Constant'
     */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
      controller_template_P.FixPtConstant_Value_n;

    /* Update for UnitDelay: '<S114>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[0];
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
      controller_template_B.sf_discretekalmanfilter_n.state_est[1];

    /* Update for UnitDelay: '<S103>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      controller_template_DWork.UnitDelay_DSTATE_jz[i] =
        controller_template_B.u_buff_out_i[i];
    }

    /* End of Update for UnitDelay: '<S103>/Unit Delay' */

    /* Update for UnitDelay: '<S103>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
           (&controller_template_B.V_init_out_n[0]), 30U * sizeof(real_T));

    /* End of Outputs for SubSystem: '<S9>/MAIN CONTROL LOOP1' */

    /* SignalConversion: '<S97>/TmpSignal ConversionAtTo FileInport1' */
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
    rtb_TmpSignalConversionAtToFi_f[17] = rtb_SliderGain_e3;

    /* ToFile: '<S97>/To File' */
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

    /* SignalConversion: '<S97>/TmpSignal ConversionAtTo File1Inport1' */
    rtb_TmpSignalConversionAtToFile[0] = rtb_UnitDelay2_a;
    rtb_TmpSignalConversionAtToFile[1] = rtb_roll_cmd_c;
    rtb_TmpSignalConversionAtToFile[2] = rtb_Saturation_n;
    rtb_TmpSignalConversionAtToFile[3] = rtb_SliderGain_n;

    /* ToFile: '<S97>/To File1' */
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

    /* Gain: '<S97>/Gain' */
    controller_template_B.Gain[0] = controller_template_P.Gain_Gain_o *
      roll_cmd_f;
    controller_template_B.Gain[1] = controller_template_P.Gain_Gain_o * sumViol;
    controller_template_B.Gain[2] = controller_template_P.Gain_Gain_o *
      controller_template_B.DataTypeConversion[6];
    controller_template_B.Gain[3] = controller_template_P.Gain_Gain_o *
      controller_template_B.DataTypeConversion[7];

    /* Gain: '<S97>/rad -> deg2' */
    controller_template_B.raddeg2[0] = controller_template_P.raddeg2_Gain_p *
      controller_template_B.DataTypeConversion[7];
    controller_template_B.raddeg2[1] = controller_template_P.raddeg2_Gain_p *
      controller_template_B.DataTypeConversion[10];
    controller_template_B.raddeg2[2] = controller_template_P.raddeg2_Gain_p *
      sumViol;

    /* Gain: '<S97>/rad -> deg1' */
    controller_template_B.raddeg1[0] = controller_template_P.raddeg1_Gain_a *
      controller_template_B.DataTypeConversion[6];
    controller_template_B.raddeg1[1] = controller_template_P.raddeg1_Gain_a *
      controller_template_B.DataTypeConversion[9];
    controller_template_B.raddeg1[2] = controller_template_P.raddeg1_Gain_a *
      roll_cmd_f;

    /* Gain: '<S97>/rad -> deg3' */
    controller_template_B.raddeg3[0] = controller_template_P.raddeg3_Gain_k *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg3[1] = controller_template_P.raddeg3_Gain_k *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg3[2] = controller_template_P.raddeg3_Gain_k *
      rtb_SliderGain_e3;

    /* Gain: '<S97>/rad -> deg' */
    controller_template_B.raddeg[0] = controller_template_P.raddeg_Gain_k *
      controller_template_B.DataTypeConversion[8];
    controller_template_B.raddeg[1] = controller_template_P.raddeg_Gain_k *
      controller_template_B.DataTypeConversion[11];
    controller_template_B.raddeg[2] = controller_template_P.raddeg_Gain_k *
      controller_template_B.X_ref_yaw[0];
    controller_template_B.raddeg[3] = controller_template_P.raddeg_Gain_k *
      controller_template_B.X_ref_yaw[1];

    /* Outputs for Atomic SubSystem: '<S9>/decoupling and rotation' */
    /* Inport: '<S94>/bias_W' */
    controller_template_B.bias_W[0] = rtb_TmpSignalConversionAtToFile[0];
    controller_template_B.bias_W[1] = rtb_TmpSignalConversionAtToFile[1];
    controller_template_B.bias_W[2] = rtb_TmpSignalConversionAtToFile[2];
    controller_template_B.bias_W[3] = rtb_TmpSignalConversionAtToFile[3];

    /* Inport: '<S94>/cmd_W' */
    controller_template_B.cmd_W[0] = sumViol;
    controller_template_B.cmd_W[1] = roll_cmd_f;
    controller_template_B.cmd_W[2] = controller_template_B.thrust_cmd_e;
    controller_template_B.cmd_W[3] = rtb_SliderGain_e3;

    /* MATLAB Function: '<S119>/Embedded MATLAB Function' incorporates:
     *  Constant: '<S119>/g'
     */
    controller_template_DWork.sfEvent_f = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/decoupling /Embedded MATLAB Function': '<S121>:1' */
    /* '<S121>:1:4' */
    rtb_SliderGain_n = controller_template_B.cmd_W[2] / (cos
      (controller_template_B.sf_EmbeddedMATLABFunction_o.pitch_rot) * cos
      (controller_template_B.sf_EmbeddedMATLABFunction_o.roll_rot));

    /* '<S121>:1:6' */
    controller_template_B.pitch_cmd_comp =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value_m / rtb_SliderGain_n *
      controller_template_B.cmd_W[0];

    /* '<S121>:1:7' */
    controller_template_B.roll_cmd_comp =
      controller_template_B.DataTypeConversion[29] *
      controller_template_P.g_Value_m / rtb_SliderGain_n *
      controller_template_B.cmd_W[1];

    /*  pitch_cmd_comp=pitch_cmd; */
    /*  roll_cmd_comp=roll_cmd; */
    /*  pitch_cmd_comp = atan(Fx/(-thrust_comp)); */
    /*  roll_cmd_comp = atan(Fy/(thrust_comp)); */
    /*  pitch_cmd_comp = atan(-g*m*pitch_cmd/(-thrust)); */
    /*  roll_cmd_comp = atan(g*m*roll_cmd*cos(pitch_meas)/(thrust)); */
    controller_template_B.thrust_comp = rtb_SliderGain_n;

    /* MATLAB Function: '<S120>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent = CALL_EVENT;

    /* MATLAB Function 'decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function': '<S122>:1' */
    /* '<S122>:1:3' */
    rtb_SliderGain_n = sin(controller_template_B.DataTypeConversion[8]);

    /* '<S122>:1:4' */
    rtb_SliderGain_e3 = cos(controller_template_B.DataTypeConversion[8]);

    /* '<S122>:1:6' */
    /* '<S122>:1:8' */
    /* '<S122>:1:9' */
    controller_template_B.pitch_rot = rtb_SliderGain_e3 *
      controller_template_B.pitch_cmd_comp + -rtb_SliderGain_n *
      controller_template_B.roll_cmd_comp;

    /* '<S122>:1:10' */
    controller_template_B.roll_rot = rtb_SliderGain_n *
      controller_template_B.pitch_cmd_comp + rtb_SliderGain_e3 *
      controller_template_B.roll_cmd_comp;

    /* '<S122>:1:12' */
    /* '<S122>:1:13' */
    controller_template_B.pitch_bias_rot = rtb_SliderGain_e3 *
      controller_template_B.bias_W[0] + -rtb_SliderGain_n *
      controller_template_B.bias_W[1];

    /* '<S122>:1:14' */
    controller_template_B.roll_bias_rot = rtb_SliderGain_n *
      controller_template_B.bias_W[0] + rtb_SliderGain_e3 *
      controller_template_B.bias_W[1];

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
  rtb_SliderGain_n = controller_template_P.gravity_Value_ch *
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

  /* Switch: '<S91>/SwitchControl' incorporates:
   *  Constant: '<S7>/yaw_rate'
   *  Constant: '<S91>/Constant'
   *  Gain: '<S7>/yaw_cmd2yaw'
   */
  if (controller_template_P.Constant_Value_a3 >
      controller_template_P.SwitchControl_Threshold_ef) {
    rtb_SliderGain_e3 = controller_template_P.yaw_cmd2yaw_Gain *
      controller_template_B.yaw_rate_cmd;
  } else {
    rtb_SliderGain_e3 = controller_template_P.yaw_rate_Value;
  }

  /* End of Switch: '<S91>/SwitchControl' */

  /* Gain: '<S7>/Gain4' */
  rtb_SliderGain_e3 *= controller_template_P.Gain4_Gain;

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
    controller_template_P.Gain1_Gain_e);
  arg_cmd_out[1] = (real32_T)((controller_template_B.roll_cmd -
    controller_template_P.roll_offset_Value) *
    controller_template_P.roll_cmd2roll_Gain *
    controller_template_P.Gain2_Gain_a);
  arg_cmd_out[2] = (real32_T)(((controller_template_B.thrust_cmd -
    rtb_SliderGain_n) * controller_template_P.trhust_cmd2thrust_Gain +
    rtb_SliderGain_n) * controller_template_P.Gain_Gain_k *
    controller_template_P.Gain3_Gain);
  arg_cmd_out[3] = (real32_T)rtb_SliderGain_e3;

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

  /* Update for UnitDelay: '<S92>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S92>/FixPt Constant'
   */
  controller_template_DWork.FixPtUnitDelay2_DSTATE =
    controller_template_P.FixPtConstant_Value_i;

  /* Switch: '<S92>/Reset' */
  if (rtb_MultiportSwitch1 != 0.0) {
    /* Update for UnitDelay: '<S92>/FixPt Unit Delay1' incorporates:
     *  Constant: '<S92>/Initial Condition'
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
    /* Update for UnitDelay: '<S92>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE[0] =
      controller_template_B.pitch_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[1] =
      controller_template_B.roll_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[2] =
      controller_template_B.thrust_bias;
    controller_template_DWork.FixPtUnitDelay1_DSTATE[3] =
      controller_template_B.yaw_rate_bias;
  }

  /* End of Switch: '<S92>/Reset' */

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
  controller_template_M->Sizes.checksums[0] = (552358399U);
  controller_template_M->Sizes.checksums[1] = (951240059U);
  controller_template_M->Sizes.checksums[2] = (4027743832U);
  controller_template_M->Sizes.checksums[3] = (2987878277U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[70];
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
    systemRan[38] = &rtAlwaysEnabled;
    systemRan[39] = &rtAlwaysEnabled;
    systemRan[40] = &rtAlwaysEnabled;
    systemRan[41] = &rtAlwaysEnabled;
    systemRan[42] = &rtAlwaysEnabled;
    systemRan[43] = &rtAlwaysEnabled;
    systemRan[44] = &rtAlwaysEnabled;
    systemRan[45] = &rtAlwaysEnabled;
    systemRan[46] = &rtAlwaysEnabled;
    systemRan[47] = &rtAlwaysEnabled;
    systemRan[48] = &rtAlwaysEnabled;
    systemRan[49] = &rtAlwaysEnabled;
    systemRan[50] = &rtAlwaysEnabled;
    systemRan[51] = &rtAlwaysEnabled;
    systemRan[52] = &rtAlwaysEnabled;
    systemRan[53] = &rtAlwaysEnabled;
    systemRan[54] = &rtAlwaysEnabled;
    systemRan[55] = &rtAlwaysEnabled;
    systemRan[56] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[57] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[58] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[59] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[60] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[61] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[62] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[63] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[64] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[65] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[66] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[67] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[68] = (sysRanDType *)
      &controller_template_DWork.poscontroller_SubsysRanBC;
    systemRan[69] = (sysRanDType *)
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
    /* Start for UnitDelay: '<S30>/Unit Delay2' */
    controller_template_B.UnitDelay2 = controller_template_P.UnitDelay2_X0;

    /* Start for UnitDelay: '<S29>/Unit Delay2' */
    controller_template_B.UnitDelay2_p = controller_template_P.UnitDelay2_X0_b;

    /* Start for UnitDelay: '<S45>/Unit Delay2' */
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
    con_EmbeddedMATLABFunction_Init
      (&controller_template_DWork.sf_EmbeddedMATLABFunction);

    /* InitializeConditions for MATLAB Function: '<S72>/MATLAB Function' */
    controlle_MATLABFunction_c_Init(&controller_template_DWork.sf_MATLABFunction);

    /* InitializeConditions for UnitDelay: '<S69>/Unit Delay' */
    controller_template_DWork.UnitDelay_2_DSTATE =
      controller_template_P.UnitDelay_2_X0;

    /* InitializeConditions for UnitDelay: '<S69>/Unit Delay' */
    controller_template_DWork.UnitDelay_3_DSTATE =
      controller_template_P.UnitDelay_3_X0;

    /* InitializeConditions for MATLAB Function: '<S69>/Next Ref' */
    controller_template_DWork.sfEvent_p = CALL_EVENT;
    controller_template_DWork.is_active_c35_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S73>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_g =
      controller_template_P.UnitDelay_X0_o;

    /* InitializeConditions for MATLAB Function: '<S73>/generate_X_ref_x' */
    controlle_generate_X_ref_x_Init
      (&controller_template_DWork.sf_generate_X_ref_x);

    /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_e =
      controller_template_P.UnitDelay_X0_b;

    /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_x' */
    controlle_generate_X_ref_x_Init
      (&controller_template_DWork.sf_generate_X_ref_x_k);

    /* InitializeConditions for MATLAB Function: '<S73>/generate_X_ref_y' */
    controlle_generate_X_ref_y_Init
      (&controller_template_DWork.sf_generate_X_ref_y);

    /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_y' */
    controlle_generate_X_ref_y_Init
      (&controller_template_DWork.sf_generate_X_ref_y_a);

    /* InitializeConditions for MATLAB Function: '<S73>/generate_X_ref_z' */
    controlle_generate_X_ref_z_Init
      (&controller_template_DWork.sf_generate_X_ref_z);

    /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_z' */
    controlle_generate_X_ref_z_Init
      (&controller_template_DWork.sf_generate_X_ref_z_l);

    /* InitializeConditions for MATLAB Function: '<S73>/generate_X_ref_yaw' */
    control_generate_X_ref_yaw_Init
      (&controller_template_DWork.sf_generate_X_ref_yaw);

    /* InitializeConditions for MATLAB Function: '<S17>/generate_X_ref_yaw' */
    control_generate_X_ref_yaw_Init
      (&controller_template_DWork.sf_generate_X_ref_yaw_g);

    /* InitializeConditions for Atomic SubSystem: '<S2>/MAIN CONTROL LOOP1' */
    /* InitializeConditions for Delay: '<S11>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE_k =
      controller_template_P.IntegerDelay3_InitialCondition;

    /* InitializeConditions for MATLAB Function: '<S27>/MATLAB Function' */
    controller_template_DWork.sfEvent_ks = CALL_EVENT;
    controller_template_DWork.is_active_c28_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S27>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_bg, (void *)
           controller_template_P.UnitDelay1_X0, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S64>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_g =
      controller_template_P.FixPtUnitDelay2_X0;

    /* InitializeConditions for UnitDelay: '<S64>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[0] =
      controller_template_P.FixPtUnitDelay1_X0;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i1[1] =
      controller_template_P.FixPtUnitDelay1_X0;

    /* InitializeConditions for MATLAB Function: '<S27>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter);

    /* InitializeConditions for MATLAB Function: '<S35>/MATLAB Function' */
    controlle_MATLABFunction_c_Init
      (&controller_template_DWork.sf_MATLABFunction_e);

    /* InitializeConditions for UnitDelay: '<S30>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE =
      controller_template_P.UnitDelay2_X0;

    /* InitializeConditions for MATLAB Function: '<S40>/MATLAB Function' */
    controller_template_DWork.sfEvent_a = CALL_EVENT;
    controller_template_DWork.is_active_c7_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S30>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_cm = CALL_EVENT;
    controller_template_DWork.is_active_c1_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S29>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_m =
      controller_template_P.UnitDelay2_X0_b;

    /* InitializeConditions for MATLAB Function: '<S37>/MATLAB Function' */
    controller__MATLABFunction_Init
      (&controller_template_DWork.sf_MATLABFunction_i);

    /* InitializeConditions for MATLAB Function: '<S29>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_cr = CALL_EVENT;
    controller_template_DWork.is_active_c24_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S34>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_d =
      controller_template_P.UnitDelay2_X0_m;

    /* InitializeConditions for UnitDelay: '<S34>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_jv =
      controller_template_P.UnitDelay_X0;

    /* InitializeConditions for UnitDelay: '<S45>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_l =
      controller_template_P.UnitDelay2_X0_d;

    /* InitializeConditions for MATLAB Function: '<S50>/MATLAB Function' */
    controller__MATLABFunction_Init
      (&controller_template_DWork.sf_MATLABFunction_k);

    /* InitializeConditions for MATLAB Function: '<S45>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_cd = CALL_EVENT;
    controller_template_DWork.is_active_c2_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S46>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_k =
      controller_template_P.UnitDelay2_X0_n;

    /* InitializeConditions for UnitDelay: '<S46>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_f =
      controller_template_P.UnitDelay_X0_f;

    /* InitializeConditions for MATLAB Function: '<S66>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_k0 = CALL_EVENT;
    controller_template_DWork.is_active_c3_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S67>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_b =
      controller_template_P.UnitDelay2_X0_o;

    /* InitializeConditions for UnitDelay: '<S67>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_fw =
      controller_template_P.UnitDelay_X0_i;

    /* InitializeConditions for UnitDelay: '<S26>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_lg =
      controller_template_P.UnitDelay_X0_m;

    /* InitializeConditions for MATLAB Function: '<S26>/MATLAB Function' */
    controller_template_DWork.sfEvent_g = CALL_EVENT;
    controller_template_DWork.is_active_c25_controller_templa = 0U;

    /* InitializeConditions for MATLAB Function: '<S26>/MATLAB Function1' */
    controller_template_DWork.sfEvent_d = CALL_EVENT;
    controller_template_DWork.is_active_c30_controller_templa = 0U;

    /* InitializeConditions for UnitDelay: '<S52>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_g =
      controller_template_P.UnitDelay2_X0_ng;

    /* InitializeConditions for MATLAB Function: '<S61>/MATLAB Function' */
    controller_template_DWork.sfEvent_l = CALL_EVENT;
    controller_template_DWork.is_active_c6_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S52>/Ctrl_Xdir' */
    controller_template_DWork.sfEvent_jv = CALL_EVENT;
    controller_template_DWork.is_active_c4_controller_templat = 0U;

    /* InitializeConditions for UnitDelay: '<S55>/Unit Delay2' */
    controller_template_DWork.UnitDelay2_DSTATE_ga =
      controller_template_P.UnitDelay2_X0_i;

    /* InitializeConditions for UnitDelay: '<S55>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_p =
      controller_template_P.UnitDelay_X0_c;

    /* InitializeConditions for UnitDelay: '<S34>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_a =
      controller_template_P.UnitDelay1_X0_i;

    /* InitializeConditions for UnitDelay: '<S46>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_ji =
      controller_template_P.UnitDelay1_X0_d;

    /* InitializeConditions for UnitDelay: '<S55>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_c3 =
      controller_template_P.UnitDelay1_X0_j;

    /* InitializeConditions for UnitDelay: '<S67>/Unit Delay1' */
    controller_template_DWork.UnitDelay1_DSTATE_m =
      controller_template_P.UnitDelay1_X0_f;

    /* End of InitializeConditions for SubSystem: '<S2>/MAIN CONTROL LOOP1' */

    /* InitializeConditions for Atomic SubSystem: '<S2>/decoupling and rotation' */
    /* InitializeConditions for MATLAB Function: '<S85>/MATLAB Function' */
    controlle_MATLABFunction_c_Init
      (&controller_template_DWork.sf_MATLABFunction_p);

    /* InitializeConditions for MATLAB Function: '<S82>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_c = CALL_EVENT;
    controller_template_DWork.is_active_c9_controller_templat = 0U;

    /* InitializeConditions for MATLAB Function: '<S83>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_j = CALL_EVENT;
    controller_template_DWork.is_active_c10_controller_templa = 0U;

    /* End of InitializeConditions for SubSystem: '<S2>/decoupling and rotation' */
    /* End of Start for SubSystem: '<Root>/FreeFlight Pos Ctrl' */

    /* Start for Enabled SubSystem: '<Root>/pos controller' */
    /* Start for ToFile: '<S97>/To File' */
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

    /* Start for ToFile: '<S97>/To File1' */
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

    /* InitializeConditions for MATLAB Function: '<S96>/Embedded MATLAB Function' */
    con_EmbeddedMATLABFunction_Init
      (&controller_template_DWork.sf_EmbeddedMATLABFunction_o);

    /* InitializeConditions for Atomic SubSystem: '<S9>/MAIN CONTROL LOOP1' */
    /* InitializeConditions for Delay: '<S93>/Integer Delay' */
    controller_template_DWork.IntegerDelay_DSTATE =
      controller_template_P.IntegerDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S93>/Integer Delay1' */
    controller_template_DWork.IntegerDelay1_DSTATE =
      controller_template_P.IntegerDelay1_InitialCondition;

    /* InitializeConditions for Delay: '<S93>/Integer Delay2' */
    controller_template_DWork.IntegerDelay2_DSTATE =
      controller_template_P.IntegerDelay2_InitialCondition;

    /* InitializeConditions for Delay: '<S93>/Integer Delay3' */
    controller_template_DWork.IntegerDelay3_DSTATE =
      controller_template_P.IntegerDelay3_InitialConditio_c;

    /* InitializeConditions for UnitDelay: '<S100>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE, (void *)
           controller_template_P.UnitDelay1_X0_c, sizeof(real_T) << 4U);

    /* InitializeConditions for UnitDelay: '<S108>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_l =
      controller_template_P.FixPtUnitDelay2_X0_d;

    /* InitializeConditions for UnitDelay: '<S108>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[0] =
      controller_template_P.FixPtUnitDelay1_X0_f;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[1] =
      controller_template_P.FixPtUnitDelay1_X0_f;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_i[2] =
      controller_template_P.FixPtUnitDelay1_X0_f;

    /* InitializeConditions for MATLAB Function: '<S100>/discrete kalman filter' */
    con_discretekalmanfilter_k_Init
      (&controller_template_DWork.sf_discretekalmanfilter_b);

    /* InitializeConditions for UnitDelay: '<S99>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE[0] =
      controller_template_P.UnitDelay_X0_fc[0];
    controller_template_DWork.UnitDelay_DSTATE[1] =
      controller_template_P.UnitDelay_X0_fc[1];
    controller_template_DWork.UnitDelay_DSTATE[2] =
      controller_template_P.UnitDelay_X0_fc[2];

    /* InitializeConditions for UnitDelay: '<S99>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_c, (void *)
           controller_template_P.UnitDelay1_X0_k, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S99>/runFastGradient' */
    controller_runFastGradient_Init
      (&controller_template_DWork.sf_runFastGradient);

    /* InitializeConditions for UnitDelay: '<S102>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_b, (void *)
           controller_template_P.UnitDelay1_X0_fk, sizeof(real_T) << 4U);

    /* InitializeConditions for UnitDelay: '<S111>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_b =
      controller_template_P.FixPtUnitDelay2_X0_n;

    /* InitializeConditions for UnitDelay: '<S111>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[0] =
      controller_template_P.FixPtUnitDelay1_X0_n;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[1] =
      controller_template_P.FixPtUnitDelay1_X0_n;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_g[2] =
      controller_template_P.FixPtUnitDelay1_X0_n;

    /* InitializeConditions for MATLAB Function: '<S102>/discrete kalman filter' */
    con_discretekalmanfilter_k_Init
      (&controller_template_DWork.sf_discretekalmanfilter_m);

    /* InitializeConditions for UnitDelay: '<S101>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_j[0] =
      controller_template_P.UnitDelay_X0_ik[0];
    controller_template_DWork.UnitDelay_DSTATE_j[1] =
      controller_template_P.UnitDelay_X0_ik[1];
    controller_template_DWork.UnitDelay_DSTATE_j[2] =
      controller_template_P.UnitDelay_X0_ik[2];

    /* InitializeConditions for UnitDelay: '<S101>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_l, (void *)
           controller_template_P.UnitDelay1_X0_jc, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S101>/runFastGradient' */
    controller_runFastGradient_Init
      (&controller_template_DWork.sf_runFastGradient_d);

    /* InitializeConditions for UnitDelay: '<S106>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_j, (void *)
           controller_template_P.UnitDelay1_X0_cw, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S117>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_c =
      controller_template_P.FixPtUnitDelay2_X0_do;

    /* InitializeConditions for UnitDelay: '<S117>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[0] =
      controller_template_P.FixPtUnitDelay1_X0_c;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_d[1] =
      controller_template_P.FixPtUnitDelay1_X0_c;

    /* InitializeConditions for MATLAB Function: '<S106>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter_k);

    /* InitializeConditions for UnitDelay: '<S105>/Unit Delay' */
    controller_template_DWork.UnitDelay_DSTATE_l[0] =
      controller_template_P.UnitDelay_X0_a[0];
    controller_template_DWork.UnitDelay_DSTATE_l[1] =
      controller_template_P.UnitDelay_X0_a[1];

    /* InitializeConditions for UnitDelay: '<S105>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_g, (void *)
           controller_template_P.UnitDelay1_X0_b, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S105>/runFastGradient' */
    controller_template_DWork.sfEvent_k = CALL_EVENT;
    controller_template_DWork.is_active_c8_Hquad_control_LIB_ = 0U;

    /* InitializeConditions for UnitDelay: '<S104>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_lx, (void *)
           controller_template_P.UnitDelay1_X0_n, 9U * sizeof(real_T));

    /* InitializeConditions for UnitDelay: '<S114>/FixPt Unit Delay2' */
    controller_template_DWork.FixPtUnitDelay2_DSTATE_a =
      controller_template_P.FixPtUnitDelay2_X0_i;

    /* InitializeConditions for UnitDelay: '<S114>/FixPt Unit Delay1' */
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[0] =
      controller_template_P.FixPtUnitDelay1_X0_e;
    controller_template_DWork.FixPtUnitDelay1_DSTATE_e[1] =
      controller_template_P.FixPtUnitDelay1_X0_e;

    /* InitializeConditions for MATLAB Function: '<S104>/discrete kalman filter' */
    contr_discretekalmanfilter_Init
      (&controller_template_DWork.sf_discretekalmanfilter_n);

    /* InitializeConditions for UnitDelay: '<S103>/Unit Delay' */
    for (i = 0; i < 6; i++) {
      controller_template_DWork.UnitDelay_DSTATE_jz[i] =
        controller_template_P.UnitDelay_X0_fj[i];
    }

    /* End of InitializeConditions for UnitDelay: '<S103>/Unit Delay' */

    /* InitializeConditions for UnitDelay: '<S103>/Unit Delay1' */
    memcpy((void *)controller_template_DWork.UnitDelay1_DSTATE_js, (void *)
           controller_template_P.UnitDelay1_X0_o, 30U * sizeof(real_T));

    /* InitializeConditions for MATLAB Function: '<S103>/runFastGradient' */
    controller_template_DWork.sfEvent_n = CALL_EVENT;
    controller_template_DWork.is_active_c9_Hquad_control_LIB_ = 0U;

    /* End of InitializeConditions for SubSystem: '<S9>/MAIN CONTROL LOOP1' */

    /* InitializeConditions for Atomic SubSystem: '<S9>/decoupling and rotation' */
    /* InitializeConditions for MATLAB Function: '<S119>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent_f = CALL_EVENT;
    controller_template_DWork.is_active_c1_Hquad_control_LIB_ = 0U;

    /* InitializeConditions for MATLAB Function: '<S120>/Embedded MATLAB Function' */
    controller_template_DWork.sfEvent = CALL_EVENT;
    controller_template_DWork.is_active_c4_Hquad_control_LIB_ = 0U;

    /* End of InitializeConditions for SubSystem: '<S9>/decoupling and rotation' */
    /* End of Start for SubSystem: '<Root>/pos controller' */
  }

  /* InitializeConditions for UnitDelay: '<S92>/FixPt Unit Delay2' */
  controller_template_DWork.FixPtUnitDelay2_DSTATE =
    controller_template_P.FixPtUnitDelay2_X0_g;

  /* InitializeConditions for UnitDelay: '<S92>/FixPt Unit Delay1' */
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

  /* Terminate for ToFile: '<S97>/To File' */
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

  /* Terminate for ToFile: '<S97>/To File1' */
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
