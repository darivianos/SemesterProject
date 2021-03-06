/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Hquad_control_LIB_MPC_sfun.h"
#include "c16_Hquad_control_LIB_MPC.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hquad_control_LIB_MPC_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c16_debug_family_names[18] = { "n", "x_", "P_", "K",
  "nargin", "nargout", "A", "B", "C", "D", "Q", "R", "u", "y", "P", "state",
  "state_est", "P_est" };

/* Function Declarations */
static void initialize_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initialize_params_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void enable_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void disable_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c16_update_debugger_state_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void set_sim_state_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray
   *c16_st);
static void finalize_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void sf_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c16_chartstep_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initSimStructsc16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void registerMessagesc16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber);
static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_P_est, const char_T *c16_identifier, real_T
  c16_y[9]);
static void c16_b_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  real_T c16_y[9]);
static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_c_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_state_est, const char_T *c16_identifier,
  real_T c16_y[3]);
static void c16_d_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  real_T c16_y[3]);
static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static const mxArray *c16_e_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static const mxArray *c16_f_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static real_T c16_e_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static const mxArray *c16_g_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static void c16_f_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  real_T c16_y[6]);
static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static void c16_info_helper(c16_ResolvedFunctionInfo c16_info[56]);
static void c16_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c16_b_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c16_c_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c16_d_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c16_e_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c16_mpower(SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c16_a[4], real_T c16_c[4]);
static void c16_matrix_to_integer_power
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance, real_T c16_a[4],
   real_T c16_b, real_T c16_c[4]);
static void c16_f_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c16_g_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c16_inv(SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                    real_T c16_x[4], real_T c16_y[4]);
static real_T c16_norm(SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c16_x[4]);
static void c16_eml_warning(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c16_b_eml_warning(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, char_T c16_varargin_2[14]);
static void c16_h_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c16_i_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c16_j_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c16_eye(SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                    real_T c16_I[9]);
static void c16_k_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c16_g_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_sprintf, const char_T *c16_identifier,
  char_T c16_y[14]);
static void c16_h_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  char_T c16_y[14]);
static const mxArray *c16_h_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData);
static int32_T c16_i_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void c16_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData);
static uint8_T c16_j_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c16_b_is_active_c16_Hquad_control_LIB_MPC, const
  char_T *c16_identifier);
static uint8_T c16_k_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId);
static void init_dsm_address_info(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  chartInstance->c16_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c16_is_active_c16_Hquad_control_LIB_MPC = 0U;
}

static void initialize_params_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void enable_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c16_update_debugger_state_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  const mxArray *c16_st;
  const mxArray *c16_y = NULL;
  int32_T c16_i0;
  real_T c16_u[9];
  const mxArray *c16_b_y = NULL;
  int32_T c16_i1;
  real_T c16_b_u[3];
  const mxArray *c16_c_y = NULL;
  uint8_T c16_hoistedGlobal;
  uint8_T c16_c_u;
  const mxArray *c16_d_y = NULL;
  real_T (*c16_state_est)[3];
  real_T (*c16_P_est)[9];
  c16_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c16_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_st = NULL;
  c16_st = NULL;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_createcellarray(3), FALSE);
  for (c16_i0 = 0; c16_i0 < 9; c16_i0++) {
    c16_u[c16_i0] = (*c16_P_est)[c16_i0];
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c16_y, 0, c16_b_y);
  for (c16_i1 = 0; c16_i1 < 3; c16_i1++) {
    c16_b_u[c16_i1] = (*c16_state_est)[c16_i1];
  }

  c16_c_y = NULL;
  sf_mex_assign(&c16_c_y, sf_mex_create("y", c16_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c16_y, 1, c16_c_y);
  c16_hoistedGlobal = chartInstance->c16_is_active_c16_Hquad_control_LIB_MPC;
  c16_c_u = c16_hoistedGlobal;
  c16_d_y = NULL;
  sf_mex_assign(&c16_d_y, sf_mex_create("y", &c16_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c16_y, 2, c16_d_y);
  sf_mex_assign(&c16_st, c16_y, FALSE);
  return c16_st;
}

static void set_sim_state_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray
   *c16_st)
{
  const mxArray *c16_u;
  real_T c16_dv0[9];
  int32_T c16_i2;
  real_T c16_dv1[3];
  int32_T c16_i3;
  real_T (*c16_P_est)[9];
  real_T (*c16_state_est)[3];
  c16_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c16_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c16_doneDoubleBufferReInit = TRUE;
  c16_u = sf_mex_dup(c16_st);
  c16_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 0)),
                       "P_est", c16_dv0);
  for (c16_i2 = 0; c16_i2 < 9; c16_i2++) {
    (*c16_P_est)[c16_i2] = c16_dv0[c16_i2];
  }

  c16_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 1)),
    "state_est", c16_dv1);
  for (c16_i3 = 0; c16_i3 < 3; c16_i3++) {
    (*c16_state_est)[c16_i3] = c16_dv1[c16_i3];
  }

  chartInstance->c16_is_active_c16_Hquad_control_LIB_MPC =
    c16_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c16_u, 2)),
    "is_active_c16_Hquad_control_LIB_MPC");
  sf_mex_destroy(&c16_u);
  c16_update_debugger_state_c16_Hquad_control_LIB_MPC(chartInstance);
  sf_mex_destroy(&c16_st);
}

static void finalize_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void sf_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T c16_i4;
  int32_T c16_i5;
  int32_T c16_i6;
  int32_T c16_i7;
  int32_T c16_i8;
  int32_T c16_i9;
  int32_T c16_i10;
  int32_T c16_i11;
  int32_T c16_i12;
  int32_T c16_i13;
  int32_T c16_i14;
  real_T *c16_u;
  real_T (*c16_P_est)[9];
  real_T (*c16_state)[3];
  real_T (*c16_P)[9];
  real_T (*c16_y)[2];
  real_T (*c16_R)[4];
  real_T (*c16_Q)[9];
  real_T (*c16_D)[2];
  real_T (*c16_C)[6];
  real_T (*c16_state_est)[3];
  real_T (*c16_B)[3];
  real_T (*c16_A)[9];
  c16_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c16_state = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c16_P = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 8);
  c16_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 7);
  c16_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c16_R = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
  c16_Q = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c16_D = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 3);
  c16_C = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c16_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c16_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c16_sfEvent);
  for (c16_i4 = 0; c16_i4 < 9; c16_i4++) {
    _SFD_DATA_RANGE_CHECK((*c16_A)[c16_i4], 0U);
  }

  for (c16_i5 = 0; c16_i5 < 3; c16_i5++) {
    _SFD_DATA_RANGE_CHECK((*c16_B)[c16_i5], 1U);
  }

  for (c16_i6 = 0; c16_i6 < 3; c16_i6++) {
    _SFD_DATA_RANGE_CHECK((*c16_state_est)[c16_i6], 2U);
  }

  for (c16_i7 = 0; c16_i7 < 6; c16_i7++) {
    _SFD_DATA_RANGE_CHECK((*c16_C)[c16_i7], 3U);
  }

  for (c16_i8 = 0; c16_i8 < 2; c16_i8++) {
    _SFD_DATA_RANGE_CHECK((*c16_D)[c16_i8], 4U);
  }

  for (c16_i9 = 0; c16_i9 < 9; c16_i9++) {
    _SFD_DATA_RANGE_CHECK((*c16_Q)[c16_i9], 5U);
  }

  for (c16_i10 = 0; c16_i10 < 4; c16_i10++) {
    _SFD_DATA_RANGE_CHECK((*c16_R)[c16_i10], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c16_u, 7U);
  for (c16_i11 = 0; c16_i11 < 2; c16_i11++) {
    _SFD_DATA_RANGE_CHECK((*c16_y)[c16_i11], 8U);
  }

  for (c16_i12 = 0; c16_i12 < 9; c16_i12++) {
    _SFD_DATA_RANGE_CHECK((*c16_P)[c16_i12], 9U);
  }

  for (c16_i13 = 0; c16_i13 < 3; c16_i13++) {
    _SFD_DATA_RANGE_CHECK((*c16_state)[c16_i13], 10U);
  }

  for (c16_i14 = 0; c16_i14 < 9; c16_i14++) {
    _SFD_DATA_RANGE_CHECK((*c16_P_est)[c16_i14], 11U);
  }

  chartInstance->c16_sfEvent = CALL_EVENT;
  c16_chartstep_c16_Hquad_control_LIB_MPC(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Hquad_control_LIB_MPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c16_chartstep_c16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  real_T c16_hoistedGlobal;
  int32_T c16_i15;
  real_T c16_A[9];
  int32_T c16_i16;
  real_T c16_B[3];
  int32_T c16_i17;
  real_T c16_C[6];
  int32_T c16_i18;
  real_T c16_D[2];
  int32_T c16_i19;
  real_T c16_Q[9];
  int32_T c16_i20;
  real_T c16_R[4];
  real_T c16_u;
  int32_T c16_i21;
  real_T c16_y[2];
  int32_T c16_i22;
  real_T c16_P[9];
  int32_T c16_i23;
  real_T c16_state[3];
  uint32_T c16_debug_family_var_map[18];
  real_T c16_n;
  real_T c16_x_[3];
  real_T c16_P_[9];
  real_T c16_K[6];
  real_T c16_nargin = 10.0;
  real_T c16_nargout = 2.0;
  real_T c16_state_est[3];
  real_T c16_P_est[9];
  int32_T c16_i24;
  real_T c16_a[9];
  int32_T c16_i25;
  real_T c16_b[3];
  int32_T c16_i26;
  real_T c16_b_y[3];
  int32_T c16_i27;
  int32_T c16_i28;
  int32_T c16_i29;
  real_T c16_b_b;
  int32_T c16_i30;
  int32_T c16_i31;
  int32_T c16_i32;
  int32_T c16_i33;
  real_T c16_c_b[9];
  int32_T c16_i34;
  int32_T c16_i35;
  int32_T c16_i36;
  real_T c16_c_y[9];
  int32_T c16_i37;
  int32_T c16_i38;
  int32_T c16_i39;
  int32_T c16_i40;
  int32_T c16_i41;
  int32_T c16_i42;
  int32_T c16_i43;
  int32_T c16_i44;
  int32_T c16_i45;
  real_T c16_d_y[9];
  int32_T c16_i46;
  int32_T c16_i47;
  int32_T c16_i48;
  int32_T c16_i49;
  int32_T c16_i50;
  int32_T c16_i51;
  int32_T c16_i52;
  int32_T c16_i53;
  real_T c16_d_b[6];
  int32_T c16_i54;
  int32_T c16_i55;
  int32_T c16_i56;
  real_T c16_e_y[6];
  int32_T c16_i57;
  int32_T c16_i58;
  int32_T c16_i59;
  real_T c16_b_a[6];
  int32_T c16_i60;
  int32_T c16_i61;
  int32_T c16_i62;
  int32_T c16_i63;
  int32_T c16_i64;
  real_T c16_f_y[6];
  int32_T c16_i65;
  int32_T c16_i66;
  int32_T c16_i67;
  int32_T c16_i68;
  int32_T c16_i69;
  int32_T c16_i70;
  int32_T c16_i71;
  int32_T c16_i72;
  int32_T c16_i73;
  int32_T c16_i74;
  real_T c16_g_y[4];
  int32_T c16_i75;
  int32_T c16_i76;
  int32_T c16_i77;
  real_T c16_h_y[4];
  int32_T c16_i78;
  int32_T c16_i79;
  int32_T c16_i80;
  int32_T c16_i81;
  int32_T c16_i82;
  int32_T c16_i83;
  int32_T c16_i84;
  int32_T c16_i85;
  int32_T c16_i86;
  int32_T c16_i87;
  int32_T c16_i88;
  int32_T c16_i89;
  int32_T c16_i90;
  int32_T c16_i91;
  int32_T c16_i92;
  real_T c16_i_y[2];
  int32_T c16_i93;
  int32_T c16_i94;
  int32_T c16_i95;
  int32_T c16_i96;
  int32_T c16_i97;
  int32_T c16_i98;
  int32_T c16_i99;
  int32_T c16_i100;
  int32_T c16_i101;
  int32_T c16_i102;
  int32_T c16_i103;
  int32_T c16_i104;
  int32_T c16_i105;
  int32_T c16_i106;
  int32_T c16_i107;
  int32_T c16_i108;
  int32_T c16_i109;
  int32_T c16_i110;
  int32_T c16_i111;
  int32_T c16_i112;
  int32_T c16_i113;
  int32_T c16_i114;
  int32_T c16_i115;
  int32_T c16_i116;
  int32_T c16_i117;
  int32_T c16_i118;
  int32_T c16_i119;
  int32_T c16_i120;
  int32_T c16_i121;
  int32_T c16_i122;
  int32_T c16_i123;
  real_T *c16_b_u;
  real_T (*c16_b_state_est)[3];
  real_T (*c16_b_P_est)[9];
  real_T (*c16_b_state)[3];
  real_T (*c16_b_P)[9];
  real_T (*c16_j_y)[2];
  real_T (*c16_b_R)[4];
  real_T (*c16_b_Q)[9];
  real_T (*c16_b_D)[2];
  real_T (*c16_b_C)[6];
  real_T (*c16_b_B)[3];
  real_T (*c16_b_A)[9];
  c16_b_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c16_b_state = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c16_b_P = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 8);
  c16_j_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 7);
  c16_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c16_b_R = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
  c16_b_Q = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c16_b_D = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 3);
  c16_b_C = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c16_b_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c16_b_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c16_b_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c16_sfEvent);
  c16_hoistedGlobal = *c16_b_u;
  for (c16_i15 = 0; c16_i15 < 9; c16_i15++) {
    c16_A[c16_i15] = (*c16_b_A)[c16_i15];
  }

  for (c16_i16 = 0; c16_i16 < 3; c16_i16++) {
    c16_B[c16_i16] = (*c16_b_B)[c16_i16];
  }

  for (c16_i17 = 0; c16_i17 < 6; c16_i17++) {
    c16_C[c16_i17] = (*c16_b_C)[c16_i17];
  }

  for (c16_i18 = 0; c16_i18 < 2; c16_i18++) {
    c16_D[c16_i18] = (*c16_b_D)[c16_i18];
  }

  for (c16_i19 = 0; c16_i19 < 9; c16_i19++) {
    c16_Q[c16_i19] = (*c16_b_Q)[c16_i19];
  }

  for (c16_i20 = 0; c16_i20 < 4; c16_i20++) {
    c16_R[c16_i20] = (*c16_b_R)[c16_i20];
  }

  c16_u = c16_hoistedGlobal;
  for (c16_i21 = 0; c16_i21 < 2; c16_i21++) {
    c16_y[c16_i21] = (*c16_j_y)[c16_i21];
  }

  for (c16_i22 = 0; c16_i22 < 9; c16_i22++) {
    c16_P[c16_i22] = (*c16_b_P)[c16_i22];
  }

  for (c16_i23 = 0; c16_i23 < 3; c16_i23++) {
    c16_state[c16_i23] = (*c16_b_state)[c16_i23];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c16_debug_family_names,
    c16_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_n, 0U, c16_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_x_, 1U, c16_b_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_P_, 2U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_K, 3U, c16_g_sf_marshallOut,
    c16_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargin, 4U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c16_nargout, 5U, c16_d_sf_marshallOut,
    c16_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_A, 6U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_B, 7U, c16_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_C, 8U, c16_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_D, 9U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_Q, 10U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_R, 11U, c16_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c16_u, 12U, c16_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_y, 13U, c16_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_P, 14U, c16_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c16_state, 15U, c16_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_state_est, 16U, c16_b_sf_marshallOut,
    c16_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c16_P_est, 17U, c16_sf_marshallOut,
    c16_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 7);
  c16_n = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 10);
  for (c16_i24 = 0; c16_i24 < 9; c16_i24++) {
    c16_a[c16_i24] = c16_A[c16_i24];
  }

  for (c16_i25 = 0; c16_i25 < 3; c16_i25++) {
    c16_b[c16_i25] = c16_state[c16_i25];
  }

  c16_eml_scalar_eg(chartInstance);
  c16_eml_scalar_eg(chartInstance);
  for (c16_i26 = 0; c16_i26 < 3; c16_i26++) {
    c16_b_y[c16_i26] = 0.0;
    c16_i27 = 0;
    for (c16_i28 = 0; c16_i28 < 3; c16_i28++) {
      c16_b_y[c16_i26] += c16_a[c16_i27 + c16_i26] * c16_b[c16_i28];
      c16_i27 += 3;
    }
  }

  for (c16_i29 = 0; c16_i29 < 3; c16_i29++) {
    c16_b[c16_i29] = c16_B[c16_i29];
  }

  c16_b_b = c16_u;
  for (c16_i30 = 0; c16_i30 < 3; c16_i30++) {
    c16_b[c16_i30] *= c16_b_b;
  }

  for (c16_i31 = 0; c16_i31 < 3; c16_i31++) {
    c16_x_[c16_i31] = c16_b_y[c16_i31] + c16_b[c16_i31];
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 11);
  for (c16_i32 = 0; c16_i32 < 9; c16_i32++) {
    c16_a[c16_i32] = c16_A[c16_i32];
  }

  for (c16_i33 = 0; c16_i33 < 9; c16_i33++) {
    c16_c_b[c16_i33] = c16_P[c16_i33];
  }

  c16_b_eml_scalar_eg(chartInstance);
  c16_b_eml_scalar_eg(chartInstance);
  for (c16_i34 = 0; c16_i34 < 3; c16_i34++) {
    c16_i35 = 0;
    for (c16_i36 = 0; c16_i36 < 3; c16_i36++) {
      c16_c_y[c16_i35 + c16_i34] = 0.0;
      c16_i37 = 0;
      for (c16_i38 = 0; c16_i38 < 3; c16_i38++) {
        c16_c_y[c16_i35 + c16_i34] += c16_a[c16_i37 + c16_i34] * c16_c_b[c16_i38
          + c16_i35];
        c16_i37 += 3;
      }

      c16_i35 += 3;
    }
  }

  c16_i39 = 0;
  for (c16_i40 = 0; c16_i40 < 3; c16_i40++) {
    c16_i41 = 0;
    for (c16_i42 = 0; c16_i42 < 3; c16_i42++) {
      c16_c_b[c16_i42 + c16_i39] = c16_A[c16_i41 + c16_i40];
      c16_i41 += 3;
    }

    c16_i39 += 3;
  }

  c16_b_eml_scalar_eg(chartInstance);
  c16_b_eml_scalar_eg(chartInstance);
  for (c16_i43 = 0; c16_i43 < 3; c16_i43++) {
    c16_i44 = 0;
    for (c16_i45 = 0; c16_i45 < 3; c16_i45++) {
      c16_d_y[c16_i44 + c16_i43] = 0.0;
      c16_i46 = 0;
      for (c16_i47 = 0; c16_i47 < 3; c16_i47++) {
        c16_d_y[c16_i44 + c16_i43] += c16_c_y[c16_i46 + c16_i43] *
          c16_c_b[c16_i47 + c16_i44];
        c16_i46 += 3;
      }

      c16_i44 += 3;
    }
  }

  for (c16_i48 = 0; c16_i48 < 9; c16_i48++) {
    c16_P_[c16_i48] = c16_d_y[c16_i48] + c16_Q[c16_i48];
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 14);
  for (c16_i49 = 0; c16_i49 < 9; c16_i49++) {
    c16_a[c16_i49] = c16_P_[c16_i49];
  }

  c16_i50 = 0;
  for (c16_i51 = 0; c16_i51 < 2; c16_i51++) {
    c16_i52 = 0;
    for (c16_i53 = 0; c16_i53 < 3; c16_i53++) {
      c16_d_b[c16_i53 + c16_i50] = c16_C[c16_i52 + c16_i51];
      c16_i52 += 2;
    }

    c16_i50 += 3;
  }

  c16_c_eml_scalar_eg(chartInstance);
  c16_c_eml_scalar_eg(chartInstance);
  for (c16_i54 = 0; c16_i54 < 3; c16_i54++) {
    c16_i55 = 0;
    for (c16_i56 = 0; c16_i56 < 2; c16_i56++) {
      c16_e_y[c16_i55 + c16_i54] = 0.0;
      c16_i57 = 0;
      for (c16_i58 = 0; c16_i58 < 3; c16_i58++) {
        c16_e_y[c16_i55 + c16_i54] += c16_a[c16_i57 + c16_i54] * c16_d_b[c16_i58
          + c16_i55];
        c16_i57 += 3;
      }

      c16_i55 += 3;
    }
  }

  for (c16_i59 = 0; c16_i59 < 6; c16_i59++) {
    c16_b_a[c16_i59] = c16_C[c16_i59];
  }

  for (c16_i60 = 0; c16_i60 < 9; c16_i60++) {
    c16_c_b[c16_i60] = c16_P_[c16_i60];
  }

  c16_d_eml_scalar_eg(chartInstance);
  c16_d_eml_scalar_eg(chartInstance);
  for (c16_i61 = 0; c16_i61 < 2; c16_i61++) {
    c16_i62 = 0;
    c16_i63 = 0;
    for (c16_i64 = 0; c16_i64 < 3; c16_i64++) {
      c16_f_y[c16_i62 + c16_i61] = 0.0;
      c16_i65 = 0;
      for (c16_i66 = 0; c16_i66 < 3; c16_i66++) {
        c16_f_y[c16_i62 + c16_i61] += c16_b_a[c16_i65 + c16_i61] *
          c16_c_b[c16_i66 + c16_i63];
        c16_i65 += 2;
      }

      c16_i62 += 2;
      c16_i63 += 3;
    }
  }

  c16_i67 = 0;
  for (c16_i68 = 0; c16_i68 < 2; c16_i68++) {
    c16_i69 = 0;
    for (c16_i70 = 0; c16_i70 < 3; c16_i70++) {
      c16_d_b[c16_i70 + c16_i67] = c16_C[c16_i69 + c16_i68];
      c16_i69 += 2;
    }

    c16_i67 += 3;
  }

  c16_e_eml_scalar_eg(chartInstance);
  c16_e_eml_scalar_eg(chartInstance);
  for (c16_i71 = 0; c16_i71 < 2; c16_i71++) {
    c16_i72 = 0;
    c16_i73 = 0;
    for (c16_i74 = 0; c16_i74 < 2; c16_i74++) {
      c16_g_y[c16_i72 + c16_i71] = 0.0;
      c16_i75 = 0;
      for (c16_i76 = 0; c16_i76 < 3; c16_i76++) {
        c16_g_y[c16_i72 + c16_i71] += c16_f_y[c16_i75 + c16_i71] *
          c16_d_b[c16_i76 + c16_i73];
        c16_i75 += 2;
      }

      c16_i72 += 2;
      c16_i73 += 3;
    }
  }

  for (c16_i77 = 0; c16_i77 < 4; c16_i77++) {
    c16_h_y[c16_i77] = c16_g_y[c16_i77] + c16_R[c16_i77];
  }

  c16_mpower(chartInstance, c16_h_y, c16_g_y);
  c16_h_eml_scalar_eg(chartInstance);
  c16_h_eml_scalar_eg(chartInstance);
  for (c16_i78 = 0; c16_i78 < 6; c16_i78++) {
    c16_K[c16_i78] = 0.0;
  }

  for (c16_i79 = 0; c16_i79 < 6; c16_i79++) {
    c16_K[c16_i79] = 0.0;
  }

  for (c16_i80 = 0; c16_i80 < 6; c16_i80++) {
    c16_d_b[c16_i80] = c16_K[c16_i80];
  }

  for (c16_i81 = 0; c16_i81 < 6; c16_i81++) {
    c16_K[c16_i81] = c16_d_b[c16_i81];
  }

  for (c16_i82 = 0; c16_i82 < 6; c16_i82++) {
    c16_d_b[c16_i82] = c16_K[c16_i82];
  }

  for (c16_i83 = 0; c16_i83 < 6; c16_i83++) {
    c16_K[c16_i83] = c16_d_b[c16_i83];
  }

  for (c16_i84 = 0; c16_i84 < 3; c16_i84++) {
    c16_i85 = 0;
    c16_i86 = 0;
    for (c16_i87 = 0; c16_i87 < 2; c16_i87++) {
      c16_K[c16_i85 + c16_i84] = 0.0;
      c16_i88 = 0;
      for (c16_i89 = 0; c16_i89 < 2; c16_i89++) {
        c16_K[c16_i85 + c16_i84] += c16_e_y[c16_i88 + c16_i84] * c16_g_y[c16_i89
          + c16_i86];
        c16_i88 += 3;
      }

      c16_i85 += 3;
      c16_i86 += 2;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 15);
  for (c16_i90 = 0; c16_i90 < 6; c16_i90++) {
    c16_b_a[c16_i90] = c16_C[c16_i90];
  }

  for (c16_i91 = 0; c16_i91 < 3; c16_i91++) {
    c16_b[c16_i91] = c16_x_[c16_i91];
  }

  c16_i_eml_scalar_eg(chartInstance);
  c16_i_eml_scalar_eg(chartInstance);
  for (c16_i92 = 0; c16_i92 < 2; c16_i92++) {
    c16_i_y[c16_i92] = 0.0;
    c16_i93 = 0;
    for (c16_i94 = 0; c16_i94 < 3; c16_i94++) {
      c16_i_y[c16_i92] += c16_b_a[c16_i93 + c16_i92] * c16_b[c16_i94];
      c16_i93 += 2;
    }
  }

  for (c16_i95 = 0; c16_i95 < 6; c16_i95++) {
    c16_d_b[c16_i95] = c16_K[c16_i95];
  }

  for (c16_i96 = 0; c16_i96 < 2; c16_i96++) {
    c16_i_y[c16_i96] = c16_y[c16_i96] - c16_i_y[c16_i96];
  }

  c16_j_eml_scalar_eg(chartInstance);
  c16_j_eml_scalar_eg(chartInstance);
  for (c16_i97 = 0; c16_i97 < 3; c16_i97++) {
    c16_b_y[c16_i97] = 0.0;
    c16_i98 = 0;
    for (c16_i99 = 0; c16_i99 < 2; c16_i99++) {
      c16_b_y[c16_i97] += c16_d_b[c16_i98 + c16_i97] * c16_i_y[c16_i99];
      c16_i98 += 3;
    }
  }

  for (c16_i100 = 0; c16_i100 < 3; c16_i100++) {
    c16_state_est[c16_i100] = c16_x_[c16_i100] + c16_b_y[c16_i100];
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, 16);
  for (c16_i101 = 0; c16_i101 < 6; c16_i101++) {
    c16_d_b[c16_i101] = c16_K[c16_i101];
  }

  for (c16_i102 = 0; c16_i102 < 6; c16_i102++) {
    c16_b_a[c16_i102] = c16_C[c16_i102];
  }

  c16_k_eml_scalar_eg(chartInstance);
  c16_k_eml_scalar_eg(chartInstance);
  for (c16_i103 = 0; c16_i103 < 3; c16_i103++) {
    c16_i104 = 0;
    c16_i105 = 0;
    for (c16_i106 = 0; c16_i106 < 3; c16_i106++) {
      c16_c_y[c16_i104 + c16_i103] = 0.0;
      c16_i107 = 0;
      for (c16_i108 = 0; c16_i108 < 2; c16_i108++) {
        c16_c_y[c16_i104 + c16_i103] += c16_d_b[c16_i107 + c16_i103] *
          c16_b_a[c16_i108 + c16_i105];
        c16_i107 += 3;
      }

      c16_i104 += 3;
      c16_i105 += 2;
    }
  }

  c16_eye(chartInstance, c16_a);
  for (c16_i109 = 0; c16_i109 < 9; c16_i109++) {
    c16_a[c16_i109] -= c16_c_y[c16_i109];
  }

  for (c16_i110 = 0; c16_i110 < 9; c16_i110++) {
    c16_c_b[c16_i110] = c16_P_[c16_i110];
  }

  c16_b_eml_scalar_eg(chartInstance);
  c16_b_eml_scalar_eg(chartInstance);
  for (c16_i111 = 0; c16_i111 < 9; c16_i111++) {
    c16_P_est[c16_i111] = 0.0;
  }

  for (c16_i112 = 0; c16_i112 < 9; c16_i112++) {
    c16_P_est[c16_i112] = 0.0;
  }

  for (c16_i113 = 0; c16_i113 < 9; c16_i113++) {
    c16_d_y[c16_i113] = c16_P_est[c16_i113];
  }

  for (c16_i114 = 0; c16_i114 < 9; c16_i114++) {
    c16_P_est[c16_i114] = c16_d_y[c16_i114];
  }

  for (c16_i115 = 0; c16_i115 < 9; c16_i115++) {
    c16_d_y[c16_i115] = c16_P_est[c16_i115];
  }

  for (c16_i116 = 0; c16_i116 < 9; c16_i116++) {
    c16_P_est[c16_i116] = c16_d_y[c16_i116];
  }

  for (c16_i117 = 0; c16_i117 < 3; c16_i117++) {
    c16_i118 = 0;
    for (c16_i119 = 0; c16_i119 < 3; c16_i119++) {
      c16_P_est[c16_i118 + c16_i117] = 0.0;
      c16_i120 = 0;
      for (c16_i121 = 0; c16_i121 < 3; c16_i121++) {
        c16_P_est[c16_i118 + c16_i117] += c16_a[c16_i120 + c16_i117] *
          c16_c_b[c16_i121 + c16_i118];
        c16_i120 += 3;
      }

      c16_i118 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c16_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  for (c16_i122 = 0; c16_i122 < 3; c16_i122++) {
    (*c16_b_state_est)[c16_i122] = c16_state_est[c16_i122];
  }

  for (c16_i123 = 0; c16_i123 < 9; c16_i123++) {
    (*c16_b_P_est)[c16_i123] = c16_P_est[c16_i123];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c16_sfEvent);
}

static void initSimStructsc16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void registerMessagesc16_Hquad_control_LIB_MPC
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c16_machineNumber, uint32_T
  c16_chartNumber)
{
}

static const mxArray *c16_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i124;
  int32_T c16_i125;
  int32_T c16_i126;
  real_T c16_b_inData[9];
  int32_T c16_i127;
  int32_T c16_i128;
  int32_T c16_i129;
  real_T c16_u[9];
  const mxArray *c16_y = NULL;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_i124 = 0;
  for (c16_i125 = 0; c16_i125 < 3; c16_i125++) {
    for (c16_i126 = 0; c16_i126 < 3; c16_i126++) {
      c16_b_inData[c16_i126 + c16_i124] = (*(real_T (*)[9])c16_inData)[c16_i126
        + c16_i124];
    }

    c16_i124 += 3;
  }

  c16_i127 = 0;
  for (c16_i128 = 0; c16_i128 < 3; c16_i128++) {
    for (c16_i129 = 0; c16_i129 < 3; c16_i129++) {
      c16_u[c16_i129 + c16_i127] = c16_b_inData[c16_i129 + c16_i127];
    }

    c16_i127 += 3;
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static void c16_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_P_est, const char_T *c16_identifier, real_T
  c16_y[9])
{
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_P_est), &c16_thisId,
    c16_y);
  sf_mex_destroy(&c16_P_est);
}

static void c16_b_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  real_T c16_y[9])
{
  real_T c16_dv2[9];
  int32_T c16_i130;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c16_i130 = 0; c16_i130 < 9; c16_i130++) {
    c16_y[c16_i130] = c16_dv2[c16_i130];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_P_est;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[9];
  int32_T c16_i131;
  int32_T c16_i132;
  int32_T c16_i133;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_P_est = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_P_est), &c16_thisId,
    c16_y);
  sf_mex_destroy(&c16_P_est);
  c16_i131 = 0;
  for (c16_i132 = 0; c16_i132 < 3; c16_i132++) {
    for (c16_i133 = 0; c16_i133 < 3; c16_i133++) {
      (*(real_T (*)[9])c16_outData)[c16_i133 + c16_i131] = c16_y[c16_i133 +
        c16_i131];
    }

    c16_i131 += 3;
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_b_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i134;
  real_T c16_b_inData[3];
  int32_T c16_i135;
  real_T c16_u[3];
  const mxArray *c16_y = NULL;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  for (c16_i134 = 0; c16_i134 < 3; c16_i134++) {
    c16_b_inData[c16_i134] = (*(real_T (*)[3])c16_inData)[c16_i134];
  }

  for (c16_i135 = 0; c16_i135 < 3; c16_i135++) {
    c16_u[c16_i135] = c16_b_inData[c16_i135];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static void c16_c_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_state_est, const char_T *c16_identifier,
  real_T c16_y[3])
{
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_state_est), &c16_thisId,
    c16_y);
  sf_mex_destroy(&c16_state_est);
}

static void c16_d_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  real_T c16_y[3])
{
  real_T c16_dv3[3];
  int32_T c16_i136;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c16_i136 = 0; c16_i136 < 3; c16_i136++) {
    c16_y[c16_i136] = c16_dv3[c16_i136];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_state_est;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[3];
  int32_T c16_i137;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_state_est = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_state_est), &c16_thisId,
    c16_y);
  sf_mex_destroy(&c16_state_est);
  for (c16_i137 = 0; c16_i137 < 3; c16_i137++) {
    (*(real_T (*)[3])c16_outData)[c16_i137] = c16_y[c16_i137];
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_c_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i138;
  real_T c16_b_inData[2];
  int32_T c16_i139;
  real_T c16_u[2];
  const mxArray *c16_y = NULL;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  for (c16_i138 = 0; c16_i138 < 2; c16_i138++) {
    c16_b_inData[c16_i138] = (*(real_T (*)[2])c16_inData)[c16_i138];
  }

  for (c16_i139 = 0; c16_i139 < 2; c16_i139++) {
    c16_u[c16_i139] = c16_b_inData[c16_i139];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static const mxArray *c16_d_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  real_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(real_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static const mxArray *c16_e_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i140;
  int32_T c16_i141;
  int32_T c16_i142;
  real_T c16_b_inData[4];
  int32_T c16_i143;
  int32_T c16_i144;
  int32_T c16_i145;
  real_T c16_u[4];
  const mxArray *c16_y = NULL;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_i140 = 0;
  for (c16_i141 = 0; c16_i141 < 2; c16_i141++) {
    for (c16_i142 = 0; c16_i142 < 2; c16_i142++) {
      c16_b_inData[c16_i142 + c16_i140] = (*(real_T (*)[4])c16_inData)[c16_i142
        + c16_i140];
    }

    c16_i140 += 2;
  }

  c16_i143 = 0;
  for (c16_i144 = 0; c16_i144 < 2; c16_i144++) {
    for (c16_i145 = 0; c16_i145 < 2; c16_i145++) {
      c16_u[c16_i145 + c16_i143] = c16_b_inData[c16_i145 + c16_i143];
    }

    c16_i143 += 2;
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static const mxArray *c16_f_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i146;
  int32_T c16_i147;
  int32_T c16_i148;
  real_T c16_b_inData[6];
  int32_T c16_i149;
  int32_T c16_i150;
  int32_T c16_i151;
  real_T c16_u[6];
  const mxArray *c16_y = NULL;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_i146 = 0;
  for (c16_i147 = 0; c16_i147 < 3; c16_i147++) {
    for (c16_i148 = 0; c16_i148 < 2; c16_i148++) {
      c16_b_inData[c16_i148 + c16_i146] = (*(real_T (*)[6])c16_inData)[c16_i148
        + c16_i146];
    }

    c16_i146 += 2;
  }

  c16_i149 = 0;
  for (c16_i150 = 0; c16_i150 < 3; c16_i150++) {
    for (c16_i151 = 0; c16_i151 < 2; c16_i151++) {
      c16_u[c16_i151 + c16_i149] = c16_b_inData[c16_i151 + c16_i149];
    }

    c16_i149 += 2;
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 2, 3), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static real_T c16_e_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  real_T c16_y;
  real_T c16_d0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_d0, 1, 0, 0U, 0, 0U, 0);
  c16_y = c16_d0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_nargout;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_nargout = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_nargout),
    &c16_thisId);
  sf_mex_destroy(&c16_nargout);
  *(real_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static const mxArray *c16_g_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_i152;
  int32_T c16_i153;
  int32_T c16_i154;
  real_T c16_b_inData[6];
  int32_T c16_i155;
  int32_T c16_i156;
  int32_T c16_i157;
  real_T c16_u[6];
  const mxArray *c16_y = NULL;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_i152 = 0;
  for (c16_i153 = 0; c16_i153 < 2; c16_i153++) {
    for (c16_i154 = 0; c16_i154 < 3; c16_i154++) {
      c16_b_inData[c16_i154 + c16_i152] = (*(real_T (*)[6])c16_inData)[c16_i154
        + c16_i152];
    }

    c16_i152 += 3;
  }

  c16_i155 = 0;
  for (c16_i156 = 0; c16_i156 < 2; c16_i156++) {
    for (c16_i157 = 0; c16_i157 < 3; c16_i157++) {
      c16_u[c16_i157 + c16_i155] = c16_b_inData[c16_i157 + c16_i155];
    }

    c16_i155 += 3;
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 0, 0U, 1U, 0U, 2, 3, 2), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static void c16_f_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  real_T c16_y[6])
{
  real_T c16_dv4[6];
  int32_T c16_i158;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                2);
  for (c16_i158 = 0; c16_i158 < 6; c16_i158++) {
    c16_y[c16_i158] = c16_dv4[c16_i158];
  }

  sf_mex_destroy(&c16_u);
}

static void c16_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_K;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  real_T c16_y[6];
  int32_T c16_i159;
  int32_T c16_i160;
  int32_T c16_i161;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_K = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_K), &c16_thisId, c16_y);
  sf_mex_destroy(&c16_K);
  c16_i159 = 0;
  for (c16_i160 = 0; c16_i160 < 2; c16_i160++) {
    for (c16_i161 = 0; c16_i161 < 3; c16_i161++) {
      (*(real_T (*)[6])c16_outData)[c16_i161 + c16_i159] = c16_y[c16_i161 +
        c16_i159];
    }

    c16_i159 += 3;
  }

  sf_mex_destroy(&c16_mxArrayInData);
}

const mxArray *sf_c16_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c16_nameCaptureInfo;
  c16_ResolvedFunctionInfo c16_info[56];
  const mxArray *c16_m0 = NULL;
  int32_T c16_i162;
  c16_ResolvedFunctionInfo *c16_r0;
  c16_nameCaptureInfo = NULL;
  c16_nameCaptureInfo = NULL;
  c16_info_helper(c16_info);
  sf_mex_assign(&c16_m0, sf_mex_createstruct("nameCaptureInfo", 1, 56), FALSE);
  for (c16_i162 = 0; c16_i162 < 56; c16_i162++) {
    c16_r0 = &c16_info[c16_i162];
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c16_r0->context)), "context", "nameCaptureInfo",
                    c16_i162);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c16_r0->name)), "name", "nameCaptureInfo",
                    c16_i162);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      c16_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c16_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c16_i162);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", c16_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c16_r0->resolved)), "resolved",
                    "nameCaptureInfo", c16_i162);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c16_i162);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo", &c16_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c16_i162);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      &c16_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c16_i162);
    sf_mex_addfield(c16_m0, sf_mex_create("nameCaptureInfo",
      &c16_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c16_i162);
  }

  sf_mex_assign(&c16_nameCaptureInfo, c16_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c16_nameCaptureInfo);
  return c16_nameCaptureInfo;
}

static void c16_info_helper(c16_ResolvedFunctionInfo c16_info[56])
{
  c16_info[0].context = "";
  c16_info[0].name = "mtimes";
  c16_info[0].dominantType = "double";
  c16_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[0].fileTimeLo = 1289519692U;
  c16_info[0].fileTimeHi = 0U;
  c16_info[0].mFileTimeLo = 0U;
  c16_info[0].mFileTimeHi = 0U;
  c16_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[1].name = "eml_index_class";
  c16_info[1].dominantType = "";
  c16_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c16_info[1].fileTimeLo = 1323170578U;
  c16_info[1].fileTimeHi = 0U;
  c16_info[1].mFileTimeLo = 0U;
  c16_info[1].mFileTimeHi = 0U;
  c16_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[2].name = "eml_scalar_eg";
  c16_info[2].dominantType = "double";
  c16_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c16_info[2].fileTimeLo = 1286818796U;
  c16_info[2].fileTimeHi = 0U;
  c16_info[2].mFileTimeLo = 0U;
  c16_info[2].mFileTimeHi = 0U;
  c16_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[3].name = "eml_xgemm";
  c16_info[3].dominantType = "char";
  c16_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c16_info[3].fileTimeLo = 1299076772U;
  c16_info[3].fileTimeHi = 0U;
  c16_info[3].mFileTimeLo = 0U;
  c16_info[3].mFileTimeHi = 0U;
  c16_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c16_info[4].name = "eml_blas_inline";
  c16_info[4].dominantType = "";
  c16_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c16_info[4].fileTimeLo = 1299076768U;
  c16_info[4].fileTimeHi = 0U;
  c16_info[4].mFileTimeLo = 0U;
  c16_info[4].mFileTimeHi = 0U;
  c16_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c16_info[5].name = "mtimes";
  c16_info[5].dominantType = "double";
  c16_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[5].fileTimeLo = 1289519692U;
  c16_info[5].fileTimeHi = 0U;
  c16_info[5].mFileTimeLo = 0U;
  c16_info[5].mFileTimeHi = 0U;
  c16_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c16_info[6].name = "eml_index_class";
  c16_info[6].dominantType = "";
  c16_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c16_info[6].fileTimeLo = 1323170578U;
  c16_info[6].fileTimeHi = 0U;
  c16_info[6].mFileTimeLo = 0U;
  c16_info[6].mFileTimeHi = 0U;
  c16_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c16_info[7].name = "eml_scalar_eg";
  c16_info[7].dominantType = "double";
  c16_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c16_info[7].fileTimeLo = 1286818796U;
  c16_info[7].fileTimeHi = 0U;
  c16_info[7].mFileTimeLo = 0U;
  c16_info[7].mFileTimeHi = 0U;
  c16_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c16_info[8].name = "eml_refblas_xgemm";
  c16_info[8].dominantType = "char";
  c16_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c16_info[8].fileTimeLo = 1299076774U;
  c16_info[8].fileTimeHi = 0U;
  c16_info[8].mFileTimeLo = 0U;
  c16_info[8].mFileTimeHi = 0U;
  c16_info[9].context = "";
  c16_info[9].name = "mpower";
  c16_info[9].dominantType = "double";
  c16_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c16_info[9].fileTimeLo = 1286818842U;
  c16_info[9].fileTimeHi = 0U;
  c16_info[9].mFileTimeLo = 0U;
  c16_info[9].mFileTimeHi = 0U;
  c16_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c16_info[10].name = "eml_scalar_floor";
  c16_info[10].dominantType = "double";
  c16_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c16_info[10].fileTimeLo = 1286818726U;
  c16_info[10].fileTimeHi = 0U;
  c16_info[10].mFileTimeLo = 0U;
  c16_info[10].mFileTimeHi = 0U;
  c16_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c16_info[11].name = "eml_index_class";
  c16_info[11].dominantType = "";
  c16_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c16_info[11].fileTimeLo = 1323170578U;
  c16_info[11].fileTimeHi = 0U;
  c16_info[11].mFileTimeLo = 0U;
  c16_info[11].mFileTimeHi = 0U;
  c16_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c16_info[12].name = "eml_scalar_eg";
  c16_info[12].dominantType = "double";
  c16_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c16_info[12].fileTimeLo = 1286818796U;
  c16_info[12].fileTimeHi = 0U;
  c16_info[12].mFileTimeLo = 0U;
  c16_info[12].mFileTimeHi = 0U;
  c16_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c16_info[13].name = "eml_scalar_abs";
  c16_info[13].dominantType = "double";
  c16_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c16_info[13].fileTimeLo = 1286818712U;
  c16_info[13].fileTimeHi = 0U;
  c16_info[13].mFileTimeLo = 0U;
  c16_info[13].mFileTimeHi = 0U;
  c16_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c16_info[14].name = "eml_scalar_floor";
  c16_info[14].dominantType = "double";
  c16_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c16_info[14].fileTimeLo = 1286818726U;
  c16_info[14].fileTimeHi = 0U;
  c16_info[14].mFileTimeLo = 0U;
  c16_info[14].mFileTimeHi = 0U;
  c16_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c16_info[15].name = "mtimes";
  c16_info[15].dominantType = "double";
  c16_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[15].fileTimeLo = 1289519692U;
  c16_info[15].fileTimeHi = 0U;
  c16_info[15].mFileTimeLo = 0U;
  c16_info[15].mFileTimeHi = 0U;
  c16_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c16_info[16].name = "inv";
  c16_info[16].dominantType = "double";
  c16_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c16_info[16].fileTimeLo = 1305318000U;
  c16_info[16].fileTimeHi = 0U;
  c16_info[16].mFileTimeLo = 0U;
  c16_info[16].mFileTimeHi = 0U;
  c16_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c16_info[17].name = "eml_xcabs1";
  c16_info[17].dominantType = "double";
  c16_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c16_info[17].fileTimeLo = 1286818706U;
  c16_info[17].fileTimeHi = 0U;
  c16_info[17].mFileTimeLo = 0U;
  c16_info[17].mFileTimeHi = 0U;
  c16_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c16_info[18].name = "abs";
  c16_info[18].dominantType = "double";
  c16_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c16_info[18].fileTimeLo = 1343830366U;
  c16_info[18].fileTimeHi = 0U;
  c16_info[18].mFileTimeLo = 0U;
  c16_info[18].mFileTimeHi = 0U;
  c16_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c16_info[19].name = "eml_scalar_abs";
  c16_info[19].dominantType = "double";
  c16_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c16_info[19].fileTimeLo = 1286818712U;
  c16_info[19].fileTimeHi = 0U;
  c16_info[19].mFileTimeLo = 0U;
  c16_info[19].mFileTimeHi = 0U;
  c16_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c16_info[20].name = "mrdivide";
  c16_info[20].dominantType = "double";
  c16_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c16_info[20].fileTimeLo = 1357951548U;
  c16_info[20].fileTimeHi = 0U;
  c16_info[20].mFileTimeLo = 1319729966U;
  c16_info[20].mFileTimeHi = 0U;
  c16_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c16_info[21].name = "rdivide";
  c16_info[21].dominantType = "double";
  c16_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c16_info[21].fileTimeLo = 1346510388U;
  c16_info[21].fileTimeHi = 0U;
  c16_info[21].mFileTimeLo = 0U;
  c16_info[21].mFileTimeHi = 0U;
  c16_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c16_info[22].name = "eml_scalexp_compatible";
  c16_info[22].dominantType = "double";
  c16_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c16_info[22].fileTimeLo = 1286818796U;
  c16_info[22].fileTimeHi = 0U;
  c16_info[22].mFileTimeLo = 0U;
  c16_info[22].mFileTimeHi = 0U;
  c16_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c16_info[23].name = "eml_div";
  c16_info[23].dominantType = "double";
  c16_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c16_info[23].fileTimeLo = 1313347810U;
  c16_info[23].fileTimeHi = 0U;
  c16_info[23].mFileTimeLo = 0U;
  c16_info[23].mFileTimeHi = 0U;
  c16_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c16_info[24].name = "mtimes";
  c16_info[24].dominantType = "double";
  c16_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[24].fileTimeLo = 1289519692U;
  c16_info[24].fileTimeHi = 0U;
  c16_info[24].mFileTimeLo = 0U;
  c16_info[24].mFileTimeHi = 0U;
  c16_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c16_info[25].name = "norm";
  c16_info[25].dominantType = "double";
  c16_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c16_info[25].fileTimeLo = 1336522094U;
  c16_info[25].fileTimeHi = 0U;
  c16_info[25].mFileTimeLo = 0U;
  c16_info[25].mFileTimeHi = 0U;
  c16_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c16_info[26].name = "abs";
  c16_info[26].dominantType = "double";
  c16_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c16_info[26].fileTimeLo = 1343830366U;
  c16_info[26].fileTimeHi = 0U;
  c16_info[26].mFileTimeLo = 0U;
  c16_info[26].mFileTimeHi = 0U;
  c16_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c16_info[27].name = "isnan";
  c16_info[27].dominantType = "double";
  c16_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c16_info[27].fileTimeLo = 1286818760U;
  c16_info[27].fileTimeHi = 0U;
  c16_info[27].mFileTimeLo = 0U;
  c16_info[27].mFileTimeHi = 0U;
  c16_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c16_info[28].name = "eml_guarded_nan";
  c16_info[28].dominantType = "char";
  c16_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c16_info[28].fileTimeLo = 1286818776U;
  c16_info[28].fileTimeHi = 0U;
  c16_info[28].mFileTimeLo = 0U;
  c16_info[28].mFileTimeHi = 0U;
  c16_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c16_info[29].name = "eml_is_float_class";
  c16_info[29].dominantType = "char";
  c16_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c16_info[29].fileTimeLo = 1286818782U;
  c16_info[29].fileTimeHi = 0U;
  c16_info[29].mFileTimeLo = 0U;
  c16_info[29].mFileTimeHi = 0U;
  c16_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c16_info[30].name = "mtimes";
  c16_info[30].dominantType = "double";
  c16_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[30].fileTimeLo = 1289519692U;
  c16_info[30].fileTimeHi = 0U;
  c16_info[30].mFileTimeLo = 0U;
  c16_info[30].mFileTimeHi = 0U;
  c16_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c16_info[31].name = "eml_warning";
  c16_info[31].dominantType = "char";
  c16_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c16_info[31].fileTimeLo = 1286818802U;
  c16_info[31].fileTimeHi = 0U;
  c16_info[31].mFileTimeLo = 0U;
  c16_info[31].mFileTimeHi = 0U;
  c16_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c16_info[32].name = "isnan";
  c16_info[32].dominantType = "double";
  c16_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c16_info[32].fileTimeLo = 1286818760U;
  c16_info[32].fileTimeHi = 0U;
  c16_info[32].mFileTimeLo = 0U;
  c16_info[32].mFileTimeHi = 0U;
  c16_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c16_info[33].name = "eps";
  c16_info[33].dominantType = "char";
  c16_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c16_info[33].fileTimeLo = 1326727996U;
  c16_info[33].fileTimeHi = 0U;
  c16_info[33].mFileTimeLo = 0U;
  c16_info[33].mFileTimeHi = 0U;
  c16_info[34].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c16_info[34].name = "eml_is_float_class";
  c16_info[34].dominantType = "char";
  c16_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c16_info[34].fileTimeLo = 1286818782U;
  c16_info[34].fileTimeHi = 0U;
  c16_info[34].mFileTimeLo = 0U;
  c16_info[34].mFileTimeHi = 0U;
  c16_info[35].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c16_info[35].name = "eml_eps";
  c16_info[35].dominantType = "char";
  c16_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c16_info[35].fileTimeLo = 1326727996U;
  c16_info[35].fileTimeHi = 0U;
  c16_info[35].mFileTimeLo = 0U;
  c16_info[35].mFileTimeHi = 0U;
  c16_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c16_info[36].name = "eml_float_model";
  c16_info[36].dominantType = "char";
  c16_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c16_info[36].fileTimeLo = 1326727996U;
  c16_info[36].fileTimeHi = 0U;
  c16_info[36].mFileTimeLo = 0U;
  c16_info[36].mFileTimeHi = 0U;
  c16_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c16_info[37].name = "eml_flt2str";
  c16_info[37].dominantType = "double";
  c16_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c16_info[37].fileTimeLo = 1309451196U;
  c16_info[37].fileTimeHi = 0U;
  c16_info[37].mFileTimeLo = 0U;
  c16_info[37].mFileTimeHi = 0U;
  c16_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c16_info[38].name = "char";
  c16_info[38].dominantType = "double";
  c16_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c16_info[38].fileTimeLo = 1319729968U;
  c16_info[38].fileTimeHi = 0U;
  c16_info[38].mFileTimeLo = 0U;
  c16_info[38].mFileTimeHi = 0U;
  c16_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c16_info[39].name = "eml_int_forloop_overflow_check";
  c16_info[39].dominantType = "";
  c16_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c16_info[39].fileTimeLo = 1346510340U;
  c16_info[39].fileTimeHi = 0U;
  c16_info[39].mFileTimeLo = 0U;
  c16_info[39].mFileTimeHi = 0U;
  c16_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c16_info[40].name = "intmax";
  c16_info[40].dominantType = "char";
  c16_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c16_info[40].fileTimeLo = 1311255316U;
  c16_info[40].fileTimeHi = 0U;
  c16_info[40].mFileTimeLo = 0U;
  c16_info[40].mFileTimeHi = 0U;
  c16_info[41].context = "";
  c16_info[41].name = "eye";
  c16_info[41].dominantType = "double";
  c16_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c16_info[41].fileTimeLo = 1286818688U;
  c16_info[41].fileTimeHi = 0U;
  c16_info[41].mFileTimeLo = 0U;
  c16_info[41].mFileTimeHi = 0U;
  c16_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c16_info[42].name = "eml_assert_valid_size_arg";
  c16_info[42].dominantType = "double";
  c16_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c16_info[42].fileTimeLo = 1286818694U;
  c16_info[42].fileTimeHi = 0U;
  c16_info[42].mFileTimeLo = 0U;
  c16_info[42].mFileTimeHi = 0U;
  c16_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c16_info[43].name = "isinf";
  c16_info[43].dominantType = "double";
  c16_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c16_info[43].fileTimeLo = 1286818760U;
  c16_info[43].fileTimeHi = 0U;
  c16_info[43].mFileTimeLo = 0U;
  c16_info[43].mFileTimeHi = 0U;
  c16_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c16_info[44].name = "mtimes";
  c16_info[44].dominantType = "double";
  c16_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c16_info[44].fileTimeLo = 1289519692U;
  c16_info[44].fileTimeHi = 0U;
  c16_info[44].mFileTimeLo = 0U;
  c16_info[44].mFileTimeHi = 0U;
  c16_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c16_info[45].name = "eml_index_class";
  c16_info[45].dominantType = "";
  c16_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c16_info[45].fileTimeLo = 1323170578U;
  c16_info[45].fileTimeHi = 0U;
  c16_info[45].mFileTimeLo = 0U;
  c16_info[45].mFileTimeHi = 0U;
  c16_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c16_info[46].name = "intmax";
  c16_info[46].dominantType = "char";
  c16_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c16_info[46].fileTimeLo = 1311255316U;
  c16_info[46].fileTimeHi = 0U;
  c16_info[46].mFileTimeLo = 0U;
  c16_info[46].mFileTimeHi = 0U;
  c16_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c16_info[47].name = "eml_is_float_class";
  c16_info[47].dominantType = "char";
  c16_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c16_info[47].fileTimeLo = 1286818782U;
  c16_info[47].fileTimeHi = 0U;
  c16_info[47].mFileTimeLo = 0U;
  c16_info[47].mFileTimeHi = 0U;
  c16_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c16_info[48].name = "min";
  c16_info[48].dominantType = "double";
  c16_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c16_info[48].fileTimeLo = 1311255318U;
  c16_info[48].fileTimeHi = 0U;
  c16_info[48].mFileTimeLo = 0U;
  c16_info[48].mFileTimeHi = 0U;
  c16_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c16_info[49].name = "eml_min_or_max";
  c16_info[49].dominantType = "char";
  c16_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c16_info[49].fileTimeLo = 1334071490U;
  c16_info[49].fileTimeHi = 0U;
  c16_info[49].mFileTimeLo = 0U;
  c16_info[49].mFileTimeHi = 0U;
  c16_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c16_info[50].name = "eml_scalar_eg";
  c16_info[50].dominantType = "double";
  c16_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c16_info[50].fileTimeLo = 1286818796U;
  c16_info[50].fileTimeHi = 0U;
  c16_info[50].mFileTimeLo = 0U;
  c16_info[50].mFileTimeHi = 0U;
  c16_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c16_info[51].name = "eml_scalexp_alloc";
  c16_info[51].dominantType = "double";
  c16_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c16_info[51].fileTimeLo = 1352424860U;
  c16_info[51].fileTimeHi = 0U;
  c16_info[51].mFileTimeLo = 0U;
  c16_info[51].mFileTimeHi = 0U;
  c16_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c16_info[52].name = "eml_index_class";
  c16_info[52].dominantType = "";
  c16_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c16_info[52].fileTimeLo = 1323170578U;
  c16_info[52].fileTimeHi = 0U;
  c16_info[52].mFileTimeLo = 0U;
  c16_info[52].mFileTimeHi = 0U;
  c16_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c16_info[53].name = "eml_scalar_eg";
  c16_info[53].dominantType = "double";
  c16_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c16_info[53].fileTimeLo = 1286818796U;
  c16_info[53].fileTimeHi = 0U;
  c16_info[53].mFileTimeLo = 0U;
  c16_info[53].mFileTimeHi = 0U;
  c16_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c16_info[54].name = "eml_index_class";
  c16_info[54].dominantType = "";
  c16_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c16_info[54].fileTimeLo = 1323170578U;
  c16_info[54].fileTimeHi = 0U;
  c16_info[54].mFileTimeLo = 0U;
  c16_info[54].mFileTimeHi = 0U;
  c16_info[55].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c16_info[55].name = "eml_int_forloop_overflow_check";
  c16_info[55].dominantType = "";
  c16_info[55].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c16_info[55].fileTimeLo = 1346510340U;
  c16_info[55].fileTimeHi = 0U;
  c16_info[55].mFileTimeLo = 0U;
  c16_info[55].mFileTimeHi = 0U;
}

static void c16_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c16_b_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c16_c_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c16_d_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c16_e_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c16_mpower(SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c16_a[4], real_T c16_c[4])
{
  int32_T c16_i163;
  real_T c16_b_a[4];
  for (c16_i163 = 0; c16_i163 < 4; c16_i163++) {
    c16_b_a[c16_i163] = c16_a[c16_i163];
  }

  c16_matrix_to_integer_power(chartInstance, c16_b_a, -1.0, c16_c);
}

static void c16_matrix_to_integer_power
  (SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance, real_T c16_a[4],
   real_T c16_b, real_T c16_c[4])
{
  real_T c16_x;
  real_T c16_e;
  boolean_T c16_firstmult;
  real_T c16_b_x;
  real_T c16_ed2;
  real_T c16_b_b;
  real_T c16_y;
  int32_T c16_i164;
  int32_T c16_i165;
  real_T c16_A[4];
  int32_T c16_i166;
  int32_T c16_i167;
  int32_T c16_i168;
  int32_T c16_i169;
  int32_T c16_i170;
  int32_T c16_i171;
  real_T c16_b_c[4];
  int32_T c16_i172;
  int32_T c16_i173;
  int32_T c16_i174;
  int32_T c16_i175;
  int32_T c16_i176;
  int32_T c16_i177;
  int32_T c16_i178;
  int32_T c16_k;
  int32_T c16_b_k;
  int32_T exitg1;
  c16_f_eml_scalar_eg(chartInstance);
  c16_x = c16_b;
  c16_e = muDoubleScalarAbs(c16_x);
  if (c16_e > 0.0) {
    c16_firstmult = TRUE;
    do {
      exitg1 = 0;
      c16_b_x = c16_e / 2.0;
      c16_ed2 = c16_b_x;
      c16_ed2 = muDoubleScalarFloor(c16_ed2);
      c16_b_b = c16_ed2;
      c16_y = 2.0 * c16_b_b;
      if (c16_y != c16_e) {
        if (c16_firstmult) {
          for (c16_i164 = 0; c16_i164 < 4; c16_i164++) {
            c16_c[c16_i164] = c16_a[c16_i164];
          }

          c16_firstmult = FALSE;
        } else {
          c16_g_eml_scalar_eg(chartInstance);
          c16_g_eml_scalar_eg(chartInstance);
          for (c16_i165 = 0; c16_i165 < 4; c16_i165++) {
            c16_A[c16_i165] = c16_c[c16_i165];
          }

          for (c16_i166 = 0; c16_i166 < 2; c16_i166++) {
            c16_i167 = 0;
            for (c16_i168 = 0; c16_i168 < 2; c16_i168++) {
              c16_c[c16_i167 + c16_i166] = 0.0;
              c16_i169 = 0;
              for (c16_i170 = 0; c16_i170 < 2; c16_i170++) {
                c16_c[c16_i167 + c16_i166] += c16_A[c16_i169 + c16_i166] *
                  c16_a[c16_i170 + c16_i167];
                c16_i169 += 2;
              }

              c16_i167 += 2;
            }
          }
        }
      }

      if (c16_ed2 == 0.0) {
        exitg1 = 1;
      } else {
        c16_e = c16_ed2;
        c16_g_eml_scalar_eg(chartInstance);
        c16_g_eml_scalar_eg(chartInstance);
        for (c16_i172 = 0; c16_i172 < 4; c16_i172++) {
          c16_A[c16_i172] = c16_a[c16_i172];
        }

        for (c16_i173 = 0; c16_i173 < 2; c16_i173++) {
          c16_i174 = 0;
          for (c16_i175 = 0; c16_i175 < 2; c16_i175++) {
            c16_a[c16_i174 + c16_i173] = 0.0;
            c16_i176 = 0;
            for (c16_i177 = 0; c16_i177 < 2; c16_i177++) {
              c16_a[c16_i174 + c16_i173] += c16_A[c16_i176 + c16_i173] *
                c16_A[c16_i177 + c16_i174];
              c16_i176 += 2;
            }

            c16_i174 += 2;
          }
        }
      }
    } while (exitg1 == 0);

    if (c16_b < 0.0) {
      for (c16_i171 = 0; c16_i171 < 4; c16_i171++) {
        c16_b_c[c16_i171] = c16_c[c16_i171];
      }

      c16_inv(chartInstance, c16_b_c, c16_c);
    }
  } else {
    for (c16_i178 = 0; c16_i178 < 4; c16_i178++) {
      c16_c[c16_i178] = 0.0;
    }

    for (c16_k = 1; c16_k < 3; c16_k++) {
      c16_b_k = c16_k;
      c16_c[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c16_b_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c16_b_k), 1, 2, 2, 0) -
               1) << 1)) - 1] = 1.0;
    }
  }
}

static void c16_f_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c16_g_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c16_inv(SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                    real_T c16_x[4], real_T c16_y[4])
{
  real_T c16_b_x;
  real_T c16_c_x;
  real_T c16_d_x;
  real_T c16_b_y;
  real_T c16_e_x;
  real_T c16_f_x;
  real_T c16_c_y;
  real_T c16_d;
  real_T c16_g_x;
  real_T c16_h_x;
  real_T c16_i_x;
  real_T c16_d_y;
  real_T c16_j_x;
  real_T c16_k_x;
  real_T c16_e_y;
  real_T c16_b_d;
  real_T c16_A;
  real_T c16_B;
  real_T c16_l_x;
  real_T c16_f_y;
  real_T c16_m_x;
  real_T c16_g_y;
  real_T c16_r;
  real_T c16_a;
  real_T c16_b;
  real_T c16_h_y;
  real_T c16_b_B;
  real_T c16_i_y;
  real_T c16_j_y;
  real_T c16_t;
  real_T c16_b_A;
  real_T c16_c_B;
  real_T c16_n_x;
  real_T c16_k_y;
  real_T c16_o_x;
  real_T c16_l_y;
  real_T c16_m_y;
  real_T c16_b_a;
  real_T c16_b_b;
  real_T c16_n_y;
  real_T c16_c_A;
  real_T c16_d_B;
  real_T c16_p_x;
  real_T c16_o_y;
  real_T c16_q_x;
  real_T c16_p_y;
  real_T c16_q_y;
  real_T c16_c_a;
  real_T c16_c_b;
  real_T c16_r_y;
  real_T c16_d_a;
  real_T c16_d_b;
  real_T c16_s_y;
  real_T c16_d_A;
  real_T c16_e_B;
  real_T c16_r_x;
  real_T c16_t_y;
  real_T c16_s_x;
  real_T c16_u_y;
  real_T c16_e_a;
  real_T c16_e_b;
  real_T c16_v_y;
  real_T c16_f_B;
  real_T c16_w_y;
  real_T c16_x_y;
  real_T c16_e_A;
  real_T c16_g_B;
  real_T c16_t_x;
  real_T c16_y_y;
  real_T c16_u_x;
  real_T c16_ab_y;
  real_T c16_bb_y;
  real_T c16_f_a;
  real_T c16_f_b;
  real_T c16_cb_y;
  real_T c16_g_a;
  real_T c16_g_b;
  real_T c16_db_y;
  real_T c16_f_A;
  real_T c16_h_B;
  real_T c16_v_x;
  real_T c16_eb_y;
  real_T c16_w_x;
  real_T c16_fb_y;
  real_T c16_gb_y;
  real_T c16_h_a;
  real_T c16_h_b;
  real_T c16_hb_y;
  int32_T c16_i179;
  real_T c16_x_x[4];
  real_T c16_n1x;
  int32_T c16_i180;
  real_T c16_ib_y[4];
  real_T c16_n1xinv;
  real_T c16_i_a;
  real_T c16_i_b;
  real_T c16_jb_y;
  real_T c16_rc;
  real_T c16_y_x;
  boolean_T c16_j_b;
  real_T c16_ab_x;
  int32_T c16_i181;
  static char_T c16_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c16_u[8];
  const mxArray *c16_kb_y = NULL;
  real_T c16_b_u;
  const mxArray *c16_lb_y = NULL;
  real_T c16_c_u;
  const mxArray *c16_mb_y = NULL;
  real_T c16_d_u;
  const mxArray *c16_nb_y = NULL;
  char_T c16_str[14];
  int32_T c16_i182;
  char_T c16_b_str[14];
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c16_b_x = c16_x[1];
  c16_c_x = c16_b_x;
  c16_d_x = c16_c_x;
  c16_b_y = muDoubleScalarAbs(c16_d_x);
  c16_e_x = 0.0;
  c16_f_x = c16_e_x;
  c16_c_y = muDoubleScalarAbs(c16_f_x);
  c16_d = c16_b_y + c16_c_y;
  c16_g_x = c16_x[0];
  c16_h_x = c16_g_x;
  c16_i_x = c16_h_x;
  c16_d_y = muDoubleScalarAbs(c16_i_x);
  c16_j_x = 0.0;
  c16_k_x = c16_j_x;
  c16_e_y = muDoubleScalarAbs(c16_k_x);
  c16_b_d = c16_d_y + c16_e_y;
  if (c16_d > c16_b_d) {
    c16_A = c16_x[0];
    c16_B = c16_x[1];
    c16_l_x = c16_A;
    c16_f_y = c16_B;
    c16_m_x = c16_l_x;
    c16_g_y = c16_f_y;
    c16_r = c16_m_x / c16_g_y;
    c16_a = c16_r;
    c16_b = c16_x[3];
    c16_h_y = c16_a * c16_b;
    c16_b_B = c16_h_y - c16_x[2];
    c16_i_y = c16_b_B;
    c16_j_y = c16_i_y;
    c16_t = 1.0 / c16_j_y;
    c16_b_A = c16_x[3];
    c16_c_B = c16_x[1];
    c16_n_x = c16_b_A;
    c16_k_y = c16_c_B;
    c16_o_x = c16_n_x;
    c16_l_y = c16_k_y;
    c16_m_y = c16_o_x / c16_l_y;
    c16_b_a = c16_m_y;
    c16_b_b = c16_t;
    c16_n_y = c16_b_a * c16_b_b;
    c16_y[0] = c16_n_y;
    c16_y[1] = -c16_t;
    c16_c_A = -c16_x[2];
    c16_d_B = c16_x[1];
    c16_p_x = c16_c_A;
    c16_o_y = c16_d_B;
    c16_q_x = c16_p_x;
    c16_p_y = c16_o_y;
    c16_q_y = c16_q_x / c16_p_y;
    c16_c_a = c16_q_y;
    c16_c_b = c16_t;
    c16_r_y = c16_c_a * c16_c_b;
    c16_y[2] = c16_r_y;
    c16_d_a = c16_r;
    c16_d_b = c16_t;
    c16_s_y = c16_d_a * c16_d_b;
    c16_y[3] = c16_s_y;
  } else {
    c16_d_A = c16_x[1];
    c16_e_B = c16_x[0];
    c16_r_x = c16_d_A;
    c16_t_y = c16_e_B;
    c16_s_x = c16_r_x;
    c16_u_y = c16_t_y;
    c16_r = c16_s_x / c16_u_y;
    c16_e_a = c16_r;
    c16_e_b = c16_x[2];
    c16_v_y = c16_e_a * c16_e_b;
    c16_f_B = c16_x[3] - c16_v_y;
    c16_w_y = c16_f_B;
    c16_x_y = c16_w_y;
    c16_t = 1.0 / c16_x_y;
    c16_e_A = c16_x[3];
    c16_g_B = c16_x[0];
    c16_t_x = c16_e_A;
    c16_y_y = c16_g_B;
    c16_u_x = c16_t_x;
    c16_ab_y = c16_y_y;
    c16_bb_y = c16_u_x / c16_ab_y;
    c16_f_a = c16_bb_y;
    c16_f_b = c16_t;
    c16_cb_y = c16_f_a * c16_f_b;
    c16_y[0] = c16_cb_y;
    c16_g_a = -c16_r;
    c16_g_b = c16_t;
    c16_db_y = c16_g_a * c16_g_b;
    c16_y[1] = c16_db_y;
    c16_f_A = -c16_x[2];
    c16_h_B = c16_x[0];
    c16_v_x = c16_f_A;
    c16_eb_y = c16_h_B;
    c16_w_x = c16_v_x;
    c16_fb_y = c16_eb_y;
    c16_gb_y = c16_w_x / c16_fb_y;
    c16_h_a = c16_gb_y;
    c16_h_b = c16_t;
    c16_hb_y = c16_h_a * c16_h_b;
    c16_y[2] = c16_hb_y;
    c16_y[3] = c16_t;
  }

  for (c16_i179 = 0; c16_i179 < 4; c16_i179++) {
    c16_x_x[c16_i179] = c16_x[c16_i179];
  }

  c16_n1x = c16_norm(chartInstance, c16_x_x);
  for (c16_i180 = 0; c16_i180 < 4; c16_i180++) {
    c16_ib_y[c16_i180] = c16_y[c16_i180];
  }

  c16_n1xinv = c16_norm(chartInstance, c16_ib_y);
  c16_i_a = c16_n1x;
  c16_i_b = c16_n1xinv;
  c16_jb_y = c16_i_a * c16_i_b;
  c16_rc = 1.0 / c16_jb_y;
  guard1 = FALSE;
  guard2 = FALSE;
  if (c16_n1x == 0.0) {
    guard2 = TRUE;
  } else if (c16_n1xinv == 0.0) {
    guard2 = TRUE;
  } else if (c16_rc == 0.0) {
    guard1 = TRUE;
  } else {
    c16_y_x = c16_rc;
    c16_j_b = muDoubleScalarIsNaN(c16_y_x);
    guard3 = FALSE;
    if (c16_j_b) {
      guard3 = TRUE;
    } else {
      if (c16_rc < 2.2204460492503131E-16) {
        guard3 = TRUE;
      }
    }

    if (guard3 == TRUE) {
      c16_ab_x = c16_rc;
      for (c16_i181 = 0; c16_i181 < 8; c16_i181++) {
        c16_u[c16_i181] = c16_cv0[c16_i181];
      }

      c16_kb_y = NULL;
      sf_mex_assign(&c16_kb_y, sf_mex_create("y", c16_u, 10, 0U, 1U, 0U, 2, 1, 8),
                    FALSE);
      c16_b_u = 14.0;
      c16_lb_y = NULL;
      sf_mex_assign(&c16_lb_y, sf_mex_create("y", &c16_b_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c16_c_u = 6.0;
      c16_mb_y = NULL;
      sf_mex_assign(&c16_mb_y, sf_mex_create("y", &c16_c_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c16_d_u = c16_ab_x;
      c16_nb_y = NULL;
      sf_mex_assign(&c16_nb_y, sf_mex_create("y", &c16_d_u, 0, 0U, 0U, 0U, 0),
                    FALSE);
      c16_g_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U, 2U,
        14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c16_kb_y, 14, c16_lb_y, 14,
        c16_mb_y), 14, c16_nb_y), "sprintf", c16_str);
      for (c16_i182 = 0; c16_i182 < 14; c16_i182++) {
        c16_b_str[c16_i182] = c16_str[c16_i182];
      }

      c16_b_eml_warning(chartInstance, c16_b_str);
    }
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    c16_eml_warning(chartInstance);
  }
}

static real_T c16_norm(SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c16_x[4])
{
  real_T c16_y;
  int32_T c16_j;
  real_T c16_b_j;
  real_T c16_s;
  int32_T c16_i;
  real_T c16_b_i;
  real_T c16_b_x;
  real_T c16_c_x;
  real_T c16_b_y;
  real_T c16_d_x;
  boolean_T c16_b;
  boolean_T exitg1;
  c16_y = 0.0;
  c16_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c16_j < 2)) {
    c16_b_j = 1.0 + (real_T)c16_j;
    c16_s = 0.0;
    for (c16_i = 0; c16_i < 2; c16_i++) {
      c16_b_i = 1.0 + (real_T)c16_i;
      c16_b_x = c16_x[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c16_b_i), 1, 2, 1, 0) + (((int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c16_b_j),
        1, 2, 2, 0) - 1) << 1)) - 1];
      c16_c_x = c16_b_x;
      c16_b_y = muDoubleScalarAbs(c16_c_x);
      c16_s += c16_b_y;
    }

    c16_d_x = c16_s;
    c16_b = muDoubleScalarIsNaN(c16_d_x);
    if (c16_b) {
      c16_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c16_s > c16_y) {
        c16_y = c16_s;
      }

      c16_j++;
    }
  }

  return c16_y;
}

static void c16_eml_warning(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
  int32_T c16_i183;
  static char_T c16_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c16_u[27];
  const mxArray *c16_y = NULL;
  for (c16_i183 = 0; c16_i183 < 27; c16_i183++) {
    c16_u[c16_i183] = c16_varargin_1[c16_i183];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 10, 0U, 1U, 0U, 2, 1, 27),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c16_y));
}

static void c16_b_eml_warning(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, char_T c16_varargin_2[14])
{
  int32_T c16_i184;
  static char_T c16_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c16_u[33];
  const mxArray *c16_y = NULL;
  int32_T c16_i185;
  char_T c16_b_u[14];
  const mxArray *c16_b_y = NULL;
  for (c16_i184 = 0; c16_i184 < 33; c16_i184++) {
    c16_u[c16_i184] = c16_varargin_1[c16_i184];
  }

  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", c16_u, 10, 0U, 1U, 0U, 2, 1, 33),
                FALSE);
  for (c16_i185 = 0; c16_i185 < 14; c16_i185++) {
    c16_b_u[c16_i185] = c16_varargin_2[c16_i185];
  }

  c16_b_y = NULL;
  sf_mex_assign(&c16_b_y, sf_mex_create("y", c16_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c16_y, 14, c16_b_y));
}

static void c16_h_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c16_i_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c16_j_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c16_eye(SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                    real_T c16_I[9])
{
  int32_T c16_i186;
  int32_T c16_i;
  int32_T c16_b_i;
  for (c16_i186 = 0; c16_i186 < 9; c16_i186++) {
    c16_I[c16_i186] = 0.0;
  }

  for (c16_i = 1; c16_i < 4; c16_i++) {
    c16_b_i = c16_i;
    c16_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c16_b_i), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c16_b_i), 1, 3, 2, 0) - 1))
      - 1] = 1.0;
  }
}

static void c16_k_eml_scalar_eg(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c16_g_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_sprintf, const char_T *c16_identifier,
  char_T c16_y[14])
{
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_sprintf), &c16_thisId,
    c16_y);
  sf_mex_destroy(&c16_sprintf);
}

static void c16_h_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId,
  char_T c16_y[14])
{
  char_T c16_cv1[14];
  int32_T c16_i187;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), c16_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c16_i187 = 0; c16_i187 < 14; c16_i187++) {
    c16_y[c16_i187] = c16_cv1[c16_i187];
  }

  sf_mex_destroy(&c16_u);
}

static const mxArray *c16_h_sf_marshallOut(void *chartInstanceVoid, void
  *c16_inData)
{
  const mxArray *c16_mxArrayOutData = NULL;
  int32_T c16_u;
  const mxArray *c16_y = NULL;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_mxArrayOutData = NULL;
  c16_u = *(int32_T *)c16_inData;
  c16_y = NULL;
  sf_mex_assign(&c16_y, sf_mex_create("y", &c16_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c16_mxArrayOutData, c16_y, FALSE);
  return c16_mxArrayOutData;
}

static int32_T c16_i_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  int32_T c16_y;
  int32_T c16_i188;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_i188, 1, 6, 0U, 0, 0U, 0);
  c16_y = c16_i188;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void c16_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c16_mxArrayInData, const char_T *c16_varName, void *c16_outData)
{
  const mxArray *c16_b_sfEvent;
  const char_T *c16_identifier;
  emlrtMsgIdentifier c16_thisId;
  int32_T c16_y;
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c16_b_sfEvent = sf_mex_dup(c16_mxArrayInData);
  c16_identifier = c16_varName;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c16_b_sfEvent),
    &c16_thisId);
  sf_mex_destroy(&c16_b_sfEvent);
  *(int32_T *)c16_outData = c16_y;
  sf_mex_destroy(&c16_mxArrayInData);
}

static uint8_T c16_j_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c16_b_is_active_c16_Hquad_control_LIB_MPC, const
  char_T *c16_identifier)
{
  uint8_T c16_y;
  emlrtMsgIdentifier c16_thisId;
  c16_thisId.fIdentifier = c16_identifier;
  c16_thisId.fParent = NULL;
  c16_y = c16_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c16_b_is_active_c16_Hquad_control_LIB_MPC), &c16_thisId);
  sf_mex_destroy(&c16_b_is_active_c16_Hquad_control_LIB_MPC);
  return c16_y;
}

static uint8_T c16_k_emlrt_marshallIn(SFc16_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c16_u, const emlrtMsgIdentifier *c16_parentId)
{
  uint8_T c16_y;
  uint8_T c16_u0;
  sf_mex_import(c16_parentId, sf_mex_dup(c16_u), &c16_u0, 1, 3, 0U, 0, 0U, 0);
  c16_y = c16_u0;
  sf_mex_destroy(&c16_u);
  return c16_y;
}

static void init_dsm_address_info(SFc16_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c16_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2446754713U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(15162562U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1302741121U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4190503008U);
}

mxArray *sf_c16_Hquad_control_LIB_MPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Js21s845HMRYEwG9sWQp3F");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(3);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(2);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c16_Hquad_control_LIB_MPC_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c16_Hquad_control_LIB_MPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[29],T\"P_est\",},{M[1],M[5],T\"state_est\",},{M[8],M[0],T\"is_active_c16_Hquad_control_LIB_MPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c16_Hquad_control_LIB_MPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
    chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Hquad_control_LIB_MPCMachineNumber_,
           16,
           1,
           1,
           12,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_Hquad_control_LIB_MPCMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Hquad_control_LIB_MPCMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Hquad_control_LIB_MPCMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"A");
          _SFD_SET_DATA_PROPS(1,1,1,0,"B");
          _SFD_SET_DATA_PROPS(2,2,0,1,"state_est");
          _SFD_SET_DATA_PROPS(3,1,1,0,"C");
          _SFD_SET_DATA_PROPS(4,1,1,0,"D");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Q");
          _SFD_SET_DATA_PROPS(6,1,1,0,"R");
          _SFD_SET_DATA_PROPS(7,1,1,0,"u");
          _SFD_SET_DATA_PROPS(8,1,1,0,"y");
          _SFD_SET_DATA_PROPS(9,1,1,0,"P");
          _SFD_SET_DATA_PROPS(10,1,1,0,"state");
          _SFD_SET_DATA_PROPS(11,2,0,1,"P_est");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,308);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)
            c16_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c16_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c16_sf_marshallOut,(MexInFcnForType)
            c16_sf_marshallIn);
        }

        {
          real_T *c16_u;
          real_T (*c16_A)[9];
          real_T (*c16_B)[3];
          real_T (*c16_state_est)[3];
          real_T (*c16_C)[6];
          real_T (*c16_D)[2];
          real_T (*c16_Q)[9];
          real_T (*c16_R)[4];
          real_T (*c16_y)[2];
          real_T (*c16_P)[9];
          real_T (*c16_state)[3];
          real_T (*c16_P_est)[9];
          c16_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c16_state = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
          c16_P = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 8);
          c16_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 7);
          c16_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c16_R = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
          c16_Q = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
          c16_D = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 3);
          c16_C = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
          c16_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            1);
          c16_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c16_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c16_A);
          _SFD_SET_DATA_VALUE_PTR(1U, *c16_B);
          _SFD_SET_DATA_VALUE_PTR(2U, *c16_state_est);
          _SFD_SET_DATA_VALUE_PTR(3U, *c16_C);
          _SFD_SET_DATA_VALUE_PTR(4U, *c16_D);
          _SFD_SET_DATA_VALUE_PTR(5U, *c16_Q);
          _SFD_SET_DATA_VALUE_PTR(6U, *c16_R);
          _SFD_SET_DATA_VALUE_PTR(7U, c16_u);
          _SFD_SET_DATA_VALUE_PTR(8U, *c16_y);
          _SFD_SET_DATA_VALUE_PTR(9U, *c16_P);
          _SFD_SET_DATA_VALUE_PTR(10U, *c16_state);
          _SFD_SET_DATA_VALUE_PTR(11U, *c16_P_est);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Hquad_control_LIB_MPCMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "po9Jq8Fj6QNIBJjFRUW5KC";
}

static void sf_opaque_initialize_c16_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc16_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c16_Hquad_control_LIB_MPC
    ((SFc16_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
  initialize_c16_Hquad_control_LIB_MPC
    ((SFc16_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c16_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  enable_c16_Hquad_control_LIB_MPC((SFc16_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c16_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  disable_c16_Hquad_control_LIB_MPC((SFc16_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c16_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_c16_Hquad_control_LIB_MPC((SFc16_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c16_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c16_Hquad_control_LIB_MPC
    ((SFc16_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_Hquad_control_LIB_MPC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c16_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c16_Hquad_control_LIB_MPC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c16_Hquad_control_LIB_MPC
    ((SFc16_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c16_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c16_Hquad_control_LIB_MPC(S);
}

static void sf_opaque_set_sim_state_c16_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c16_Hquad_control_LIB_MPC(S, st);
}

static void sf_opaque_terminate_c16_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc16_Hquad_control_LIB_MPCInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Hquad_control_LIB_MPC_optimization_info();
    }

    finalize_c16_Hquad_control_LIB_MPC
      ((SFc16_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc16_Hquad_control_LIB_MPC
    ((SFc16_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c16_Hquad_control_LIB_MPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c16_Hquad_control_LIB_MPC
      ((SFc16_Hquad_control_LIB_MPCInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c16_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      16);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,16,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,16,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,16);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,16,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,16,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 10; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,16);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3170048964U));
  ssSetChecksum1(S,(1384042747U));
  ssSetChecksum2(S,(4125893211U));
  ssSetChecksum3(S,(3049793092U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c16_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c16_Hquad_control_LIB_MPC(SimStruct *S)
{
  SFc16_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc16_Hquad_control_LIB_MPCInstanceStruct *)utMalloc(sizeof
    (SFc16_Hquad_control_LIB_MPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc16_Hquad_control_LIB_MPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c16_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c16_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c16_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c16_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c16_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c16_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c16_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c16_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c16_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c16_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c16_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c16_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c16_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c16_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c16_Hquad_control_LIB_MPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c16_Hquad_control_LIB_MPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
