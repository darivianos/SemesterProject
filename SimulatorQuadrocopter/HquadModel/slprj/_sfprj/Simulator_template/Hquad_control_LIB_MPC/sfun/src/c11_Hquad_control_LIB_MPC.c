/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Hquad_control_LIB_MPC_sfun.h"
#include "c11_Hquad_control_LIB_MPC.h"
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
static const char * c11_debug_family_names[18] = { "n", "x_", "P_", "K",
  "nargin", "nargout", "A", "B", "C", "D", "Q", "R", "u", "y", "P", "state",
  "state_est", "P_est" };

/* Function Declarations */
static void initialize_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initialize_params_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void enable_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void disable_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void set_sim_state_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray
   *c11_st);
static void finalize_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void sf_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c11_chartstep_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initSimStructsc11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void registerMessagesc11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_P_est, const char_T *c11_identifier, real_T
  c11_y[16]);
static void c11_b_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[16]);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_c_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_state_est, const char_T *c11_identifier,
  real_T c11_y[4]);
static void c11_d_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[4]);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_e_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_f_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[12]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[55]);
static void c11_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c11_b_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c11_c_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c11_d_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c11_e_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c11_mpower(SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c11_a[9], real_T c11_c[9]);
static void c11_matrix_to_integer_power
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance, real_T c11_a[9],
   real_T c11_b, real_T c11_c[9]);
static void c11_f_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c11_g_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c11_inv3x3(SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c11_x[9], real_T c11_y[9]);
static real_T c11_norm(SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c11_x[9]);
static void c11_eml_warning(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c11_b_eml_warning(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, char_T c11_varargin_2[14]);
static void c11_h_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c11_i_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c11_j_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c11_eye(SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                    real_T c11_I[16]);
static void c11_k_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c11_g_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_sprintf, const char_T *c11_identifier,
  char_T c11_y[14]);
static void c11_h_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[14]);
static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_i_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_j_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c11_b_is_active_c11_Hquad_control_LIB_MPC, const
  char_T *c11_identifier);
static uint8_T c11_k_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c11_is_active_c11_Hquad_control_LIB_MPC = 0U;
}

static void initialize_params_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void enable_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c11_update_debugger_state_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  int32_T c11_i0;
  real_T c11_u[16];
  const mxArray *c11_b_y = NULL;
  int32_T c11_i1;
  real_T c11_b_u[4];
  const mxArray *c11_c_y = NULL;
  uint8_T c11_hoistedGlobal;
  uint8_T c11_c_u;
  const mxArray *c11_d_y = NULL;
  real_T (*c11_state_est)[4];
  real_T (*c11_P_est)[16];
  c11_P_est = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
  c11_state_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(3), FALSE);
  for (c11_i0 = 0; c11_i0 < 16; c11_i0++) {
    c11_u[c11_i0] = (*c11_P_est)[c11_i0];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 4, 4),
                FALSE);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  for (c11_i1 = 0; c11_i1 < 4; c11_i1++) {
    c11_b_u[c11_i1] = (*c11_state_est)[c11_i1];
  }

  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_u, 0, 0U, 1U, 0U, 1, 4),
                FALSE);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  c11_hoistedGlobal = chartInstance->c11_is_active_c11_Hquad_control_LIB_MPC;
  c11_c_u = c11_hoistedGlobal;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  sf_mex_assign(&c11_st, c11_y, FALSE);
  return c11_st;
}

static void set_sim_state_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray
   *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[16];
  int32_T c11_i2;
  real_T c11_dv1[4];
  int32_T c11_i3;
  real_T (*c11_P_est)[16];
  real_T (*c11_state_est)[4];
  c11_P_est = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
  c11_state_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c11_doneDoubleBufferReInit = TRUE;
  c11_u = sf_mex_dup(c11_st);
  c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)),
                       "P_est", c11_dv0);
  for (c11_i2 = 0; c11_i2 < 16; c11_i2++) {
    (*c11_P_est)[c11_i2] = c11_dv0[c11_i2];
  }

  c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
    "state_est", c11_dv1);
  for (c11_i3 = 0; c11_i3 < 4; c11_i3++) {
    (*c11_state_est)[c11_i3] = c11_dv1[c11_i3];
  }

  chartInstance->c11_is_active_c11_Hquad_control_LIB_MPC =
    c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 2)),
    "is_active_c11_Hquad_control_LIB_MPC");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_Hquad_control_LIB_MPC(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void sf_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T c11_i4;
  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_i7;
  int32_T c11_i8;
  int32_T c11_i9;
  int32_T c11_i10;
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  int32_T c11_i14;
  real_T *c11_u;
  real_T (*c11_P_est)[16];
  real_T (*c11_state)[4];
  real_T (*c11_P)[16];
  real_T (*c11_y)[3];
  real_T (*c11_R)[9];
  real_T (*c11_Q)[16];
  real_T (*c11_D)[3];
  real_T (*c11_C)[12];
  real_T (*c11_state_est)[4];
  real_T (*c11_B)[4];
  real_T (*c11_A)[16];
  c11_P_est = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
  c11_state = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 9);
  c11_P = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 8);
  c11_y = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 7);
  c11_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c11_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
  c11_Q = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 4);
  c11_D = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c11_C = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 2);
  c11_state_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_B = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c11_A = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c11_sfEvent);
  for (c11_i4 = 0; c11_i4 < 16; c11_i4++) {
    _SFD_DATA_RANGE_CHECK((*c11_A)[c11_i4], 0U);
  }

  for (c11_i5 = 0; c11_i5 < 4; c11_i5++) {
    _SFD_DATA_RANGE_CHECK((*c11_B)[c11_i5], 1U);
  }

  for (c11_i6 = 0; c11_i6 < 4; c11_i6++) {
    _SFD_DATA_RANGE_CHECK((*c11_state_est)[c11_i6], 2U);
  }

  for (c11_i7 = 0; c11_i7 < 12; c11_i7++) {
    _SFD_DATA_RANGE_CHECK((*c11_C)[c11_i7], 3U);
  }

  for (c11_i8 = 0; c11_i8 < 3; c11_i8++) {
    _SFD_DATA_RANGE_CHECK((*c11_D)[c11_i8], 4U);
  }

  for (c11_i9 = 0; c11_i9 < 16; c11_i9++) {
    _SFD_DATA_RANGE_CHECK((*c11_Q)[c11_i9], 5U);
  }

  for (c11_i10 = 0; c11_i10 < 9; c11_i10++) {
    _SFD_DATA_RANGE_CHECK((*c11_R)[c11_i10], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c11_u, 7U);
  for (c11_i11 = 0; c11_i11 < 3; c11_i11++) {
    _SFD_DATA_RANGE_CHECK((*c11_y)[c11_i11], 8U);
  }

  for (c11_i12 = 0; c11_i12 < 16; c11_i12++) {
    _SFD_DATA_RANGE_CHECK((*c11_P)[c11_i12], 9U);
  }

  for (c11_i13 = 0; c11_i13 < 4; c11_i13++) {
    _SFD_DATA_RANGE_CHECK((*c11_state)[c11_i13], 10U);
  }

  for (c11_i14 = 0; c11_i14 < 16; c11_i14++) {
    _SFD_DATA_RANGE_CHECK((*c11_P_est)[c11_i14], 11U);
  }

  chartInstance->c11_sfEvent = CALL_EVENT;
  c11_chartstep_c11_Hquad_control_LIB_MPC(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Hquad_control_LIB_MPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c11_chartstep_c11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  real_T c11_hoistedGlobal;
  int32_T c11_i15;
  real_T c11_A[16];
  int32_T c11_i16;
  real_T c11_B[4];
  int32_T c11_i17;
  real_T c11_C[12];
  int32_T c11_i18;
  real_T c11_D[3];
  int32_T c11_i19;
  real_T c11_Q[16];
  int32_T c11_i20;
  real_T c11_R[9];
  real_T c11_u;
  int32_T c11_i21;
  real_T c11_y[3];
  int32_T c11_i22;
  real_T c11_P[16];
  int32_T c11_i23;
  real_T c11_state[4];
  uint32_T c11_debug_family_var_map[18];
  real_T c11_n;
  real_T c11_x_[4];
  real_T c11_P_[16];
  real_T c11_K[12];
  real_T c11_nargin = 10.0;
  real_T c11_nargout = 2.0;
  real_T c11_state_est[4];
  real_T c11_P_est[16];
  int32_T c11_i24;
  real_T c11_a[16];
  int32_T c11_i25;
  real_T c11_b[4];
  int32_T c11_i26;
  real_T c11_b_y[4];
  int32_T c11_i27;
  int32_T c11_i28;
  int32_T c11_i29;
  real_T c11_b_b;
  int32_T c11_i30;
  int32_T c11_i31;
  int32_T c11_i32;
  int32_T c11_i33;
  real_T c11_c_b[16];
  int32_T c11_i34;
  int32_T c11_i35;
  int32_T c11_i36;
  real_T c11_c_y[16];
  int32_T c11_i37;
  int32_T c11_i38;
  int32_T c11_i39;
  int32_T c11_i40;
  int32_T c11_i41;
  int32_T c11_i42;
  int32_T c11_i43;
  int32_T c11_i44;
  int32_T c11_i45;
  real_T c11_d_y[16];
  int32_T c11_i46;
  int32_T c11_i47;
  int32_T c11_i48;
  int32_T c11_i49;
  int32_T c11_i50;
  int32_T c11_i51;
  int32_T c11_i52;
  int32_T c11_i53;
  real_T c11_d_b[12];
  int32_T c11_i54;
  int32_T c11_i55;
  int32_T c11_i56;
  real_T c11_e_y[12];
  int32_T c11_i57;
  int32_T c11_i58;
  int32_T c11_i59;
  real_T c11_b_a[12];
  int32_T c11_i60;
  int32_T c11_i61;
  int32_T c11_i62;
  int32_T c11_i63;
  int32_T c11_i64;
  real_T c11_f_y[12];
  int32_T c11_i65;
  int32_T c11_i66;
  int32_T c11_i67;
  int32_T c11_i68;
  int32_T c11_i69;
  int32_T c11_i70;
  int32_T c11_i71;
  int32_T c11_i72;
  int32_T c11_i73;
  int32_T c11_i74;
  real_T c11_g_y[9];
  int32_T c11_i75;
  int32_T c11_i76;
  int32_T c11_i77;
  real_T c11_h_y[9];
  int32_T c11_i78;
  int32_T c11_i79;
  int32_T c11_i80;
  int32_T c11_i81;
  int32_T c11_i82;
  int32_T c11_i83;
  int32_T c11_i84;
  int32_T c11_i85;
  int32_T c11_i86;
  int32_T c11_i87;
  int32_T c11_i88;
  int32_T c11_i89;
  int32_T c11_i90;
  int32_T c11_i91;
  int32_T c11_i92;
  real_T c11_i_y[3];
  int32_T c11_i93;
  int32_T c11_i94;
  int32_T c11_i95;
  int32_T c11_i96;
  int32_T c11_i97;
  int32_T c11_i98;
  int32_T c11_i99;
  int32_T c11_i100;
  int32_T c11_i101;
  int32_T c11_i102;
  int32_T c11_i103;
  int32_T c11_i104;
  int32_T c11_i105;
  int32_T c11_i106;
  int32_T c11_i107;
  int32_T c11_i108;
  int32_T c11_i109;
  int32_T c11_i110;
  int32_T c11_i111;
  int32_T c11_i112;
  int32_T c11_i113;
  int32_T c11_i114;
  int32_T c11_i115;
  int32_T c11_i116;
  int32_T c11_i117;
  int32_T c11_i118;
  int32_T c11_i119;
  int32_T c11_i120;
  int32_T c11_i121;
  int32_T c11_i122;
  int32_T c11_i123;
  real_T *c11_b_u;
  real_T (*c11_b_state_est)[4];
  real_T (*c11_b_P_est)[16];
  real_T (*c11_b_state)[4];
  real_T (*c11_b_P)[16];
  real_T (*c11_j_y)[3];
  real_T (*c11_b_R)[9];
  real_T (*c11_b_Q)[16];
  real_T (*c11_b_D)[3];
  real_T (*c11_b_C)[12];
  real_T (*c11_b_B)[4];
  real_T (*c11_b_A)[16];
  c11_b_P_est = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
  c11_b_state = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 9);
  c11_b_P = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 8);
  c11_j_y = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 7);
  c11_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c11_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
  c11_b_Q = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 4);
  c11_b_D = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c11_b_C = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 2);
  c11_b_state_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c11_b_B = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c11_b_A = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c11_sfEvent);
  c11_hoistedGlobal = *c11_b_u;
  for (c11_i15 = 0; c11_i15 < 16; c11_i15++) {
    c11_A[c11_i15] = (*c11_b_A)[c11_i15];
  }

  for (c11_i16 = 0; c11_i16 < 4; c11_i16++) {
    c11_B[c11_i16] = (*c11_b_B)[c11_i16];
  }

  for (c11_i17 = 0; c11_i17 < 12; c11_i17++) {
    c11_C[c11_i17] = (*c11_b_C)[c11_i17];
  }

  for (c11_i18 = 0; c11_i18 < 3; c11_i18++) {
    c11_D[c11_i18] = (*c11_b_D)[c11_i18];
  }

  for (c11_i19 = 0; c11_i19 < 16; c11_i19++) {
    c11_Q[c11_i19] = (*c11_b_Q)[c11_i19];
  }

  for (c11_i20 = 0; c11_i20 < 9; c11_i20++) {
    c11_R[c11_i20] = (*c11_b_R)[c11_i20];
  }

  c11_u = c11_hoistedGlobal;
  for (c11_i21 = 0; c11_i21 < 3; c11_i21++) {
    c11_y[c11_i21] = (*c11_j_y)[c11_i21];
  }

  for (c11_i22 = 0; c11_i22 < 16; c11_i22++) {
    c11_P[c11_i22] = (*c11_b_P)[c11_i22];
  }

  for (c11_i23 = 0; c11_i23 < 4; c11_i23++) {
    c11_state[c11_i23] = (*c11_b_state)[c11_i23];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 18U, 18U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_n, 0U, c11_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_x_, 1U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_P_, 2U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_K, 3U, c11_g_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 4U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 5U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_A, 6U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_B, 7U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_C, 8U, c11_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_D, 9U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_Q, 10U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_R, 11U, c11_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_u, 12U, c11_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_y, 13U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_P, 14U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_state, 15U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_state_est, 16U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_P_est, 17U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_n = 4.0;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i24 = 0; c11_i24 < 16; c11_i24++) {
    c11_a[c11_i24] = c11_A[c11_i24];
  }

  for (c11_i25 = 0; c11_i25 < 4; c11_i25++) {
    c11_b[c11_i25] = c11_state[c11_i25];
  }

  c11_eml_scalar_eg(chartInstance);
  c11_eml_scalar_eg(chartInstance);
  for (c11_i26 = 0; c11_i26 < 4; c11_i26++) {
    c11_b_y[c11_i26] = 0.0;
    c11_i27 = 0;
    for (c11_i28 = 0; c11_i28 < 4; c11_i28++) {
      c11_b_y[c11_i26] += c11_a[c11_i27 + c11_i26] * c11_b[c11_i28];
      c11_i27 += 4;
    }
  }

  for (c11_i29 = 0; c11_i29 < 4; c11_i29++) {
    c11_b[c11_i29] = c11_B[c11_i29];
  }

  c11_b_b = c11_u;
  for (c11_i30 = 0; c11_i30 < 4; c11_i30++) {
    c11_b[c11_i30] *= c11_b_b;
  }

  for (c11_i31 = 0; c11_i31 < 4; c11_i31++) {
    c11_x_[c11_i31] = c11_b_y[c11_i31] + c11_b[c11_i31];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i32 = 0; c11_i32 < 16; c11_i32++) {
    c11_a[c11_i32] = c11_A[c11_i32];
  }

  for (c11_i33 = 0; c11_i33 < 16; c11_i33++) {
    c11_c_b[c11_i33] = c11_P[c11_i33];
  }

  c11_b_eml_scalar_eg(chartInstance);
  c11_b_eml_scalar_eg(chartInstance);
  for (c11_i34 = 0; c11_i34 < 4; c11_i34++) {
    c11_i35 = 0;
    for (c11_i36 = 0; c11_i36 < 4; c11_i36++) {
      c11_c_y[c11_i35 + c11_i34] = 0.0;
      c11_i37 = 0;
      for (c11_i38 = 0; c11_i38 < 4; c11_i38++) {
        c11_c_y[c11_i35 + c11_i34] += c11_a[c11_i37 + c11_i34] * c11_c_b[c11_i38
          + c11_i35];
        c11_i37 += 4;
      }

      c11_i35 += 4;
    }
  }

  c11_i39 = 0;
  for (c11_i40 = 0; c11_i40 < 4; c11_i40++) {
    c11_i41 = 0;
    for (c11_i42 = 0; c11_i42 < 4; c11_i42++) {
      c11_c_b[c11_i42 + c11_i39] = c11_A[c11_i41 + c11_i40];
      c11_i41 += 4;
    }

    c11_i39 += 4;
  }

  c11_b_eml_scalar_eg(chartInstance);
  c11_b_eml_scalar_eg(chartInstance);
  for (c11_i43 = 0; c11_i43 < 4; c11_i43++) {
    c11_i44 = 0;
    for (c11_i45 = 0; c11_i45 < 4; c11_i45++) {
      c11_d_y[c11_i44 + c11_i43] = 0.0;
      c11_i46 = 0;
      for (c11_i47 = 0; c11_i47 < 4; c11_i47++) {
        c11_d_y[c11_i44 + c11_i43] += c11_c_y[c11_i46 + c11_i43] *
          c11_c_b[c11_i47 + c11_i44];
        c11_i46 += 4;
      }

      c11_i44 += 4;
    }
  }

  for (c11_i48 = 0; c11_i48 < 16; c11_i48++) {
    c11_P_[c11_i48] = c11_d_y[c11_i48] + c11_Q[c11_i48];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 14);
  for (c11_i49 = 0; c11_i49 < 16; c11_i49++) {
    c11_a[c11_i49] = c11_P_[c11_i49];
  }

  c11_i50 = 0;
  for (c11_i51 = 0; c11_i51 < 3; c11_i51++) {
    c11_i52 = 0;
    for (c11_i53 = 0; c11_i53 < 4; c11_i53++) {
      c11_d_b[c11_i53 + c11_i50] = c11_C[c11_i52 + c11_i51];
      c11_i52 += 3;
    }

    c11_i50 += 4;
  }

  c11_c_eml_scalar_eg(chartInstance);
  c11_c_eml_scalar_eg(chartInstance);
  for (c11_i54 = 0; c11_i54 < 4; c11_i54++) {
    c11_i55 = 0;
    for (c11_i56 = 0; c11_i56 < 3; c11_i56++) {
      c11_e_y[c11_i55 + c11_i54] = 0.0;
      c11_i57 = 0;
      for (c11_i58 = 0; c11_i58 < 4; c11_i58++) {
        c11_e_y[c11_i55 + c11_i54] += c11_a[c11_i57 + c11_i54] * c11_d_b[c11_i58
          + c11_i55];
        c11_i57 += 4;
      }

      c11_i55 += 4;
    }
  }

  for (c11_i59 = 0; c11_i59 < 12; c11_i59++) {
    c11_b_a[c11_i59] = c11_C[c11_i59];
  }

  for (c11_i60 = 0; c11_i60 < 16; c11_i60++) {
    c11_c_b[c11_i60] = c11_P_[c11_i60];
  }

  c11_d_eml_scalar_eg(chartInstance);
  c11_d_eml_scalar_eg(chartInstance);
  for (c11_i61 = 0; c11_i61 < 3; c11_i61++) {
    c11_i62 = 0;
    c11_i63 = 0;
    for (c11_i64 = 0; c11_i64 < 4; c11_i64++) {
      c11_f_y[c11_i62 + c11_i61] = 0.0;
      c11_i65 = 0;
      for (c11_i66 = 0; c11_i66 < 4; c11_i66++) {
        c11_f_y[c11_i62 + c11_i61] += c11_b_a[c11_i65 + c11_i61] *
          c11_c_b[c11_i66 + c11_i63];
        c11_i65 += 3;
      }

      c11_i62 += 3;
      c11_i63 += 4;
    }
  }

  c11_i67 = 0;
  for (c11_i68 = 0; c11_i68 < 3; c11_i68++) {
    c11_i69 = 0;
    for (c11_i70 = 0; c11_i70 < 4; c11_i70++) {
      c11_d_b[c11_i70 + c11_i67] = c11_C[c11_i69 + c11_i68];
      c11_i69 += 3;
    }

    c11_i67 += 4;
  }

  c11_e_eml_scalar_eg(chartInstance);
  c11_e_eml_scalar_eg(chartInstance);
  for (c11_i71 = 0; c11_i71 < 3; c11_i71++) {
    c11_i72 = 0;
    c11_i73 = 0;
    for (c11_i74 = 0; c11_i74 < 3; c11_i74++) {
      c11_g_y[c11_i72 + c11_i71] = 0.0;
      c11_i75 = 0;
      for (c11_i76 = 0; c11_i76 < 4; c11_i76++) {
        c11_g_y[c11_i72 + c11_i71] += c11_f_y[c11_i75 + c11_i71] *
          c11_d_b[c11_i76 + c11_i73];
        c11_i75 += 3;
      }

      c11_i72 += 3;
      c11_i73 += 4;
    }
  }

  for (c11_i77 = 0; c11_i77 < 9; c11_i77++) {
    c11_h_y[c11_i77] = c11_g_y[c11_i77] + c11_R[c11_i77];
  }

  c11_mpower(chartInstance, c11_h_y, c11_g_y);
  c11_h_eml_scalar_eg(chartInstance);
  c11_h_eml_scalar_eg(chartInstance);
  for (c11_i78 = 0; c11_i78 < 12; c11_i78++) {
    c11_K[c11_i78] = 0.0;
  }

  for (c11_i79 = 0; c11_i79 < 12; c11_i79++) {
    c11_K[c11_i79] = 0.0;
  }

  for (c11_i80 = 0; c11_i80 < 12; c11_i80++) {
    c11_d_b[c11_i80] = c11_K[c11_i80];
  }

  for (c11_i81 = 0; c11_i81 < 12; c11_i81++) {
    c11_K[c11_i81] = c11_d_b[c11_i81];
  }

  for (c11_i82 = 0; c11_i82 < 12; c11_i82++) {
    c11_d_b[c11_i82] = c11_K[c11_i82];
  }

  for (c11_i83 = 0; c11_i83 < 12; c11_i83++) {
    c11_K[c11_i83] = c11_d_b[c11_i83];
  }

  for (c11_i84 = 0; c11_i84 < 4; c11_i84++) {
    c11_i85 = 0;
    c11_i86 = 0;
    for (c11_i87 = 0; c11_i87 < 3; c11_i87++) {
      c11_K[c11_i85 + c11_i84] = 0.0;
      c11_i88 = 0;
      for (c11_i89 = 0; c11_i89 < 3; c11_i89++) {
        c11_K[c11_i85 + c11_i84] += c11_e_y[c11_i88 + c11_i84] * c11_g_y[c11_i89
          + c11_i86];
        c11_i88 += 4;
      }

      c11_i85 += 4;
      c11_i86 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 15);
  for (c11_i90 = 0; c11_i90 < 12; c11_i90++) {
    c11_b_a[c11_i90] = c11_C[c11_i90];
  }

  for (c11_i91 = 0; c11_i91 < 4; c11_i91++) {
    c11_b[c11_i91] = c11_x_[c11_i91];
  }

  c11_i_eml_scalar_eg(chartInstance);
  c11_i_eml_scalar_eg(chartInstance);
  for (c11_i92 = 0; c11_i92 < 3; c11_i92++) {
    c11_i_y[c11_i92] = 0.0;
    c11_i93 = 0;
    for (c11_i94 = 0; c11_i94 < 4; c11_i94++) {
      c11_i_y[c11_i92] += c11_b_a[c11_i93 + c11_i92] * c11_b[c11_i94];
      c11_i93 += 3;
    }
  }

  for (c11_i95 = 0; c11_i95 < 12; c11_i95++) {
    c11_d_b[c11_i95] = c11_K[c11_i95];
  }

  for (c11_i96 = 0; c11_i96 < 3; c11_i96++) {
    c11_i_y[c11_i96] = c11_y[c11_i96] - c11_i_y[c11_i96];
  }

  c11_j_eml_scalar_eg(chartInstance);
  c11_j_eml_scalar_eg(chartInstance);
  for (c11_i97 = 0; c11_i97 < 4; c11_i97++) {
    c11_b_y[c11_i97] = 0.0;
    c11_i98 = 0;
    for (c11_i99 = 0; c11_i99 < 3; c11_i99++) {
      c11_b_y[c11_i97] += c11_d_b[c11_i98 + c11_i97] * c11_i_y[c11_i99];
      c11_i98 += 4;
    }
  }

  for (c11_i100 = 0; c11_i100 < 4; c11_i100++) {
    c11_state_est[c11_i100] = c11_x_[c11_i100] + c11_b_y[c11_i100];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 16);
  for (c11_i101 = 0; c11_i101 < 12; c11_i101++) {
    c11_d_b[c11_i101] = c11_K[c11_i101];
  }

  for (c11_i102 = 0; c11_i102 < 12; c11_i102++) {
    c11_b_a[c11_i102] = c11_C[c11_i102];
  }

  c11_k_eml_scalar_eg(chartInstance);
  c11_k_eml_scalar_eg(chartInstance);
  for (c11_i103 = 0; c11_i103 < 4; c11_i103++) {
    c11_i104 = 0;
    c11_i105 = 0;
    for (c11_i106 = 0; c11_i106 < 4; c11_i106++) {
      c11_c_y[c11_i104 + c11_i103] = 0.0;
      c11_i107 = 0;
      for (c11_i108 = 0; c11_i108 < 3; c11_i108++) {
        c11_c_y[c11_i104 + c11_i103] += c11_d_b[c11_i107 + c11_i103] *
          c11_b_a[c11_i108 + c11_i105];
        c11_i107 += 4;
      }

      c11_i104 += 4;
      c11_i105 += 3;
    }
  }

  c11_eye(chartInstance, c11_a);
  for (c11_i109 = 0; c11_i109 < 16; c11_i109++) {
    c11_a[c11_i109] -= c11_c_y[c11_i109];
  }

  for (c11_i110 = 0; c11_i110 < 16; c11_i110++) {
    c11_c_b[c11_i110] = c11_P_[c11_i110];
  }

  c11_b_eml_scalar_eg(chartInstance);
  c11_b_eml_scalar_eg(chartInstance);
  for (c11_i111 = 0; c11_i111 < 16; c11_i111++) {
    c11_P_est[c11_i111] = 0.0;
  }

  for (c11_i112 = 0; c11_i112 < 16; c11_i112++) {
    c11_P_est[c11_i112] = 0.0;
  }

  for (c11_i113 = 0; c11_i113 < 16; c11_i113++) {
    c11_d_y[c11_i113] = c11_P_est[c11_i113];
  }

  for (c11_i114 = 0; c11_i114 < 16; c11_i114++) {
    c11_P_est[c11_i114] = c11_d_y[c11_i114];
  }

  for (c11_i115 = 0; c11_i115 < 16; c11_i115++) {
    c11_d_y[c11_i115] = c11_P_est[c11_i115];
  }

  for (c11_i116 = 0; c11_i116 < 16; c11_i116++) {
    c11_P_est[c11_i116] = c11_d_y[c11_i116];
  }

  for (c11_i117 = 0; c11_i117 < 4; c11_i117++) {
    c11_i118 = 0;
    for (c11_i119 = 0; c11_i119 < 4; c11_i119++) {
      c11_P_est[c11_i118 + c11_i117] = 0.0;
      c11_i120 = 0;
      for (c11_i121 = 0; c11_i121 < 4; c11_i121++) {
        c11_P_est[c11_i118 + c11_i117] += c11_a[c11_i120 + c11_i117] *
          c11_c_b[c11_i121 + c11_i118];
        c11_i120 += 4;
      }

      c11_i118 += 4;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  for (c11_i122 = 0; c11_i122 < 4; c11_i122++) {
    (*c11_b_state_est)[c11_i122] = c11_state_est[c11_i122];
  }

  for (c11_i123 = 0; c11_i123 < 16; c11_i123++) {
    (*c11_b_P_est)[c11_i123] = c11_P_est[c11_i123];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c11_sfEvent);
}

static void initSimStructsc11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void registerMessagesc11_Hquad_control_LIB_MPC
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i124;
  int32_T c11_i125;
  int32_T c11_i126;
  real_T c11_b_inData[16];
  int32_T c11_i127;
  int32_T c11_i128;
  int32_T c11_i129;
  real_T c11_u[16];
  const mxArray *c11_y = NULL;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i124 = 0;
  for (c11_i125 = 0; c11_i125 < 4; c11_i125++) {
    for (c11_i126 = 0; c11_i126 < 4; c11_i126++) {
      c11_b_inData[c11_i126 + c11_i124] = (*(real_T (*)[16])c11_inData)[c11_i126
        + c11_i124];
    }

    c11_i124 += 4;
  }

  c11_i127 = 0;
  for (c11_i128 = 0; c11_i128 < 4; c11_i128++) {
    for (c11_i129 = 0; c11_i129 < 4; c11_i129++) {
      c11_u[c11_i129 + c11_i127] = c11_b_inData[c11_i129 + c11_i127];
    }

    c11_i127 += 4;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static void c11_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_P_est, const char_T *c11_identifier, real_T
  c11_y[16])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_P_est), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_P_est);
}

static void c11_b_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[16])
{
  real_T c11_dv2[16];
  int32_T c11_i130;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv2, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c11_i130 = 0; c11_i130 < 16; c11_i130++) {
    c11_y[c11_i130] = c11_dv2[c11_i130];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_P_est;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[16];
  int32_T c11_i131;
  int32_T c11_i132;
  int32_T c11_i133;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_P_est = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_P_est), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_P_est);
  c11_i131 = 0;
  for (c11_i132 = 0; c11_i132 < 4; c11_i132++) {
    for (c11_i133 = 0; c11_i133 < 4; c11_i133++) {
      (*(real_T (*)[16])c11_outData)[c11_i133 + c11_i131] = c11_y[c11_i133 +
        c11_i131];
    }

    c11_i131 += 4;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i134;
  real_T c11_b_inData[4];
  int32_T c11_i135;
  real_T c11_u[4];
  const mxArray *c11_y = NULL;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i134 = 0; c11_i134 < 4; c11_i134++) {
    c11_b_inData[c11_i134] = (*(real_T (*)[4])c11_inData)[c11_i134];
  }

  for (c11_i135 = 0; c11_i135 < 4; c11_i135++) {
    c11_u[c11_i135] = c11_b_inData[c11_i135];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static void c11_c_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_state_est, const char_T *c11_identifier,
  real_T c11_y[4])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_state_est), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_state_est);
}

static void c11_d_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[4])
{
  real_T c11_dv3[4];
  int32_T c11_i136;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c11_i136 = 0; c11_i136 < 4; c11_i136++) {
    c11_y[c11_i136] = c11_dv3[c11_i136];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_state_est;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[4];
  int32_T c11_i137;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_state_est = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_state_est), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_state_est);
  for (c11_i137 = 0; c11_i137 < 4; c11_i137++) {
    (*(real_T (*)[4])c11_outData)[c11_i137] = c11_y[c11_i137];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i138;
  real_T c11_b_inData[3];
  int32_T c11_i139;
  real_T c11_u[3];
  const mxArray *c11_y = NULL;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i138 = 0; c11_i138 < 3; c11_i138++) {
    c11_b_inData[c11_i138] = (*(real_T (*)[3])c11_inData)[c11_i138];
  }

  for (c11_i139 = 0; c11_i139 < 3; c11_i139++) {
    c11_u[c11_i139] = c11_b_inData[c11_i139];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i140;
  int32_T c11_i141;
  int32_T c11_i142;
  real_T c11_b_inData[9];
  int32_T c11_i143;
  int32_T c11_i144;
  int32_T c11_i145;
  real_T c11_u[9];
  const mxArray *c11_y = NULL;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i140 = 0;
  for (c11_i141 = 0; c11_i141 < 3; c11_i141++) {
    for (c11_i142 = 0; c11_i142 < 3; c11_i142++) {
      c11_b_inData[c11_i142 + c11_i140] = (*(real_T (*)[9])c11_inData)[c11_i142
        + c11_i140];
    }

    c11_i140 += 3;
  }

  c11_i143 = 0;
  for (c11_i144 = 0; c11_i144 < 3; c11_i144++) {
    for (c11_i145 = 0; c11_i145 < 3; c11_i145++) {
      c11_u[c11_i145 + c11_i143] = c11_b_inData[c11_i145 + c11_i143];
    }

    c11_i143 += 3;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i146;
  int32_T c11_i147;
  int32_T c11_i148;
  real_T c11_b_inData[12];
  int32_T c11_i149;
  int32_T c11_i150;
  int32_T c11_i151;
  real_T c11_u[12];
  const mxArray *c11_y = NULL;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i146 = 0;
  for (c11_i147 = 0; c11_i147 < 4; c11_i147++) {
    for (c11_i148 = 0; c11_i148 < 3; c11_i148++) {
      c11_b_inData[c11_i148 + c11_i146] = (*(real_T (*)[12])c11_inData)[c11_i148
        + c11_i146];
    }

    c11_i146 += 3;
  }

  c11_i149 = 0;
  for (c11_i150 = 0; c11_i150 < 4; c11_i150++) {
    for (c11_i151 = 0; c11_i151 < 3; c11_i151++) {
      c11_u[c11_i151 + c11_i149] = c11_b_inData[c11_i151 + c11_i149];
    }

    c11_i149 += 3;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 3, 4), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static real_T c11_e_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_nargout;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_nargout = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_nargout),
    &c11_thisId);
  sf_mex_destroy(&c11_nargout);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i152;
  int32_T c11_i153;
  int32_T c11_i154;
  real_T c11_b_inData[12];
  int32_T c11_i155;
  int32_T c11_i156;
  int32_T c11_i157;
  real_T c11_u[12];
  const mxArray *c11_y = NULL;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i152 = 0;
  for (c11_i153 = 0; c11_i153 < 3; c11_i153++) {
    for (c11_i154 = 0; c11_i154 < 4; c11_i154++) {
      c11_b_inData[c11_i154 + c11_i152] = (*(real_T (*)[12])c11_inData)[c11_i154
        + c11_i152];
    }

    c11_i152 += 4;
  }

  c11_i155 = 0;
  for (c11_i156 = 0; c11_i156 < 3; c11_i156++) {
    for (c11_i157 = 0; c11_i157 < 4; c11_i157++) {
      c11_u[c11_i157 + c11_i155] = c11_b_inData[c11_i157 + c11_i155];
    }

    c11_i155 += 4;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 4, 3), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static void c11_f_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[12])
{
  real_T c11_dv4[12];
  int32_T c11_i158;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv4, 1, 0, 0U, 1, 0U, 2, 4,
                3);
  for (c11_i158 = 0; c11_i158 < 12; c11_i158++) {
    c11_y[c11_i158] = c11_dv4[c11_i158];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_K;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[12];
  int32_T c11_i159;
  int32_T c11_i160;
  int32_T c11_i161;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_K = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_K), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_K);
  c11_i159 = 0;
  for (c11_i160 = 0; c11_i160 < 3; c11_i160++) {
    for (c11_i161 = 0; c11_i161 < 4; c11_i161++) {
      (*(real_T (*)[12])c11_outData)[c11_i161 + c11_i159] = c11_y[c11_i161 +
        c11_i159];
    }

    c11_i159 += 4;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo;
  c11_ResolvedFunctionInfo c11_info[55];
  const mxArray *c11_m0 = NULL;
  int32_T c11_i162;
  c11_ResolvedFunctionInfo *c11_r0;
  c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  c11_info_helper(c11_info);
  sf_mex_assign(&c11_m0, sf_mex_createstruct("nameCaptureInfo", 1, 55), FALSE);
  for (c11_i162 = 0; c11_i162 < 55; c11_i162++) {
    c11_r0 = &c11_info[c11_i162];
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->context)), "context", "nameCaptureInfo",
                    c11_i162);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c11_r0->name)), "name", "nameCaptureInfo",
                    c11_i162);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      c11_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c11_i162);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", c11_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c11_r0->resolved)), "resolved",
                    "nameCaptureInfo", c11_i162);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c11_i162);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo", &c11_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c11_i162);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c11_i162);
    sf_mex_addfield(c11_m0, sf_mex_create("nameCaptureInfo",
      &c11_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c11_i162);
  }

  sf_mex_assign(&c11_nameCaptureInfo, c11_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c11_nameCaptureInfo);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(c11_ResolvedFunctionInfo c11_info[55])
{
  c11_info[0].context = "";
  c11_info[0].name = "mtimes";
  c11_info[0].dominantType = "double";
  c11_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[0].fileTimeLo = 1289519692U;
  c11_info[0].fileTimeHi = 0U;
  c11_info[0].mFileTimeLo = 0U;
  c11_info[0].mFileTimeHi = 0U;
  c11_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[1].name = "eml_index_class";
  c11_info[1].dominantType = "";
  c11_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[1].fileTimeLo = 1323170578U;
  c11_info[1].fileTimeHi = 0U;
  c11_info[1].mFileTimeLo = 0U;
  c11_info[1].mFileTimeHi = 0U;
  c11_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[2].name = "eml_scalar_eg";
  c11_info[2].dominantType = "double";
  c11_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[2].fileTimeLo = 1286818796U;
  c11_info[2].fileTimeHi = 0U;
  c11_info[2].mFileTimeLo = 0U;
  c11_info[2].mFileTimeHi = 0U;
  c11_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[3].name = "eml_xgemm";
  c11_info[3].dominantType = "char";
  c11_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c11_info[3].fileTimeLo = 1299076772U;
  c11_info[3].fileTimeHi = 0U;
  c11_info[3].mFileTimeLo = 0U;
  c11_info[3].mFileTimeHi = 0U;
  c11_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c11_info[4].name = "eml_blas_inline";
  c11_info[4].dominantType = "";
  c11_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c11_info[4].fileTimeLo = 1299076768U;
  c11_info[4].fileTimeHi = 0U;
  c11_info[4].mFileTimeLo = 0U;
  c11_info[4].mFileTimeHi = 0U;
  c11_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c11_info[5].name = "mtimes";
  c11_info[5].dominantType = "double";
  c11_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[5].fileTimeLo = 1289519692U;
  c11_info[5].fileTimeHi = 0U;
  c11_info[5].mFileTimeLo = 0U;
  c11_info[5].mFileTimeHi = 0U;
  c11_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c11_info[6].name = "eml_index_class";
  c11_info[6].dominantType = "";
  c11_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[6].fileTimeLo = 1323170578U;
  c11_info[6].fileTimeHi = 0U;
  c11_info[6].mFileTimeLo = 0U;
  c11_info[6].mFileTimeHi = 0U;
  c11_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c11_info[7].name = "eml_scalar_eg";
  c11_info[7].dominantType = "double";
  c11_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[7].fileTimeLo = 1286818796U;
  c11_info[7].fileTimeHi = 0U;
  c11_info[7].mFileTimeLo = 0U;
  c11_info[7].mFileTimeHi = 0U;
  c11_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c11_info[8].name = "eml_refblas_xgemm";
  c11_info[8].dominantType = "char";
  c11_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c11_info[8].fileTimeLo = 1299076774U;
  c11_info[8].fileTimeHi = 0U;
  c11_info[8].mFileTimeLo = 0U;
  c11_info[8].mFileTimeHi = 0U;
  c11_info[9].context = "";
  c11_info[9].name = "mpower";
  c11_info[9].dominantType = "double";
  c11_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c11_info[9].fileTimeLo = 1286818842U;
  c11_info[9].fileTimeHi = 0U;
  c11_info[9].mFileTimeLo = 0U;
  c11_info[9].mFileTimeHi = 0U;
  c11_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c11_info[10].name = "eml_scalar_floor";
  c11_info[10].dominantType = "double";
  c11_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c11_info[10].fileTimeLo = 1286818726U;
  c11_info[10].fileTimeHi = 0U;
  c11_info[10].mFileTimeLo = 0U;
  c11_info[10].mFileTimeHi = 0U;
  c11_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c11_info[11].name = "eml_index_class";
  c11_info[11].dominantType = "";
  c11_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[11].fileTimeLo = 1323170578U;
  c11_info[11].fileTimeHi = 0U;
  c11_info[11].mFileTimeLo = 0U;
  c11_info[11].mFileTimeHi = 0U;
  c11_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c11_info[12].name = "eml_scalar_eg";
  c11_info[12].dominantType = "double";
  c11_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[12].fileTimeLo = 1286818796U;
  c11_info[12].fileTimeHi = 0U;
  c11_info[12].mFileTimeLo = 0U;
  c11_info[12].mFileTimeHi = 0U;
  c11_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c11_info[13].name = "eml_scalar_abs";
  c11_info[13].dominantType = "double";
  c11_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c11_info[13].fileTimeLo = 1286818712U;
  c11_info[13].fileTimeHi = 0U;
  c11_info[13].mFileTimeLo = 0U;
  c11_info[13].mFileTimeHi = 0U;
  c11_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c11_info[14].name = "eml_scalar_floor";
  c11_info[14].dominantType = "double";
  c11_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c11_info[14].fileTimeLo = 1286818726U;
  c11_info[14].fileTimeHi = 0U;
  c11_info[14].mFileTimeLo = 0U;
  c11_info[14].mFileTimeHi = 0U;
  c11_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c11_info[15].name = "mtimes";
  c11_info[15].dominantType = "double";
  c11_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[15].fileTimeLo = 1289519692U;
  c11_info[15].fileTimeHi = 0U;
  c11_info[15].mFileTimeLo = 0U;
  c11_info[15].mFileTimeHi = 0U;
  c11_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c11_info[16].name = "inv";
  c11_info[16].dominantType = "double";
  c11_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c11_info[16].fileTimeLo = 1305318000U;
  c11_info[16].fileTimeHi = 0U;
  c11_info[16].mFileTimeLo = 0U;
  c11_info[16].mFileTimeHi = 0U;
  c11_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c11_info[17].name = "eml_index_class";
  c11_info[17].dominantType = "";
  c11_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[17].fileTimeLo = 1323170578U;
  c11_info[17].fileTimeHi = 0U;
  c11_info[17].mFileTimeLo = 0U;
  c11_info[17].mFileTimeHi = 0U;
  c11_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c11_info[18].name = "abs";
  c11_info[18].dominantType = "double";
  c11_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c11_info[18].fileTimeLo = 1343830366U;
  c11_info[18].fileTimeHi = 0U;
  c11_info[18].mFileTimeLo = 0U;
  c11_info[18].mFileTimeHi = 0U;
  c11_info[19].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c11_info[19].name = "eml_scalar_abs";
  c11_info[19].dominantType = "double";
  c11_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c11_info[19].fileTimeLo = 1286818712U;
  c11_info[19].fileTimeHi = 0U;
  c11_info[19].mFileTimeLo = 0U;
  c11_info[19].mFileTimeHi = 0U;
  c11_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c11_info[20].name = "eml_div";
  c11_info[20].dominantType = "double";
  c11_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c11_info[20].fileTimeLo = 1313347810U;
  c11_info[20].fileTimeHi = 0U;
  c11_info[20].mFileTimeLo = 0U;
  c11_info[20].mFileTimeHi = 0U;
  c11_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c11_info[21].name = "mtimes";
  c11_info[21].dominantType = "double";
  c11_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[21].fileTimeLo = 1289519692U;
  c11_info[21].fileTimeHi = 0U;
  c11_info[21].mFileTimeLo = 0U;
  c11_info[21].mFileTimeHi = 0U;
  c11_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c11_info[22].name = "eml_index_plus";
  c11_info[22].dominantType = "double";
  c11_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c11_info[22].fileTimeLo = 1286818778U;
  c11_info[22].fileTimeHi = 0U;
  c11_info[22].mFileTimeLo = 0U;
  c11_info[22].mFileTimeHi = 0U;
  c11_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c11_info[23].name = "eml_index_class";
  c11_info[23].dominantType = "";
  c11_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[23].fileTimeLo = 1323170578U;
  c11_info[23].fileTimeHi = 0U;
  c11_info[23].mFileTimeLo = 0U;
  c11_info[23].mFileTimeHi = 0U;
  c11_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c11_info[24].name = "norm";
  c11_info[24].dominantType = "double";
  c11_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c11_info[24].fileTimeLo = 1336522094U;
  c11_info[24].fileTimeHi = 0U;
  c11_info[24].mFileTimeLo = 0U;
  c11_info[24].mFileTimeHi = 0U;
  c11_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c11_info[25].name = "abs";
  c11_info[25].dominantType = "double";
  c11_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c11_info[25].fileTimeLo = 1343830366U;
  c11_info[25].fileTimeHi = 0U;
  c11_info[25].mFileTimeLo = 0U;
  c11_info[25].mFileTimeHi = 0U;
  c11_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c11_info[26].name = "isnan";
  c11_info[26].dominantType = "double";
  c11_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c11_info[26].fileTimeLo = 1286818760U;
  c11_info[26].fileTimeHi = 0U;
  c11_info[26].mFileTimeLo = 0U;
  c11_info[26].mFileTimeHi = 0U;
  c11_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c11_info[27].name = "eml_guarded_nan";
  c11_info[27].dominantType = "char";
  c11_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c11_info[27].fileTimeLo = 1286818776U;
  c11_info[27].fileTimeHi = 0U;
  c11_info[27].mFileTimeLo = 0U;
  c11_info[27].mFileTimeHi = 0U;
  c11_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c11_info[28].name = "eml_is_float_class";
  c11_info[28].dominantType = "char";
  c11_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c11_info[28].fileTimeLo = 1286818782U;
  c11_info[28].fileTimeHi = 0U;
  c11_info[28].mFileTimeLo = 0U;
  c11_info[28].mFileTimeHi = 0U;
  c11_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c11_info[29].name = "mtimes";
  c11_info[29].dominantType = "double";
  c11_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[29].fileTimeLo = 1289519692U;
  c11_info[29].fileTimeHi = 0U;
  c11_info[29].mFileTimeLo = 0U;
  c11_info[29].mFileTimeHi = 0U;
  c11_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c11_info[30].name = "eml_warning";
  c11_info[30].dominantType = "char";
  c11_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c11_info[30].fileTimeLo = 1286818802U;
  c11_info[30].fileTimeHi = 0U;
  c11_info[30].mFileTimeLo = 0U;
  c11_info[30].mFileTimeHi = 0U;
  c11_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c11_info[31].name = "isnan";
  c11_info[31].dominantType = "double";
  c11_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c11_info[31].fileTimeLo = 1286818760U;
  c11_info[31].fileTimeHi = 0U;
  c11_info[31].mFileTimeLo = 0U;
  c11_info[31].mFileTimeHi = 0U;
  c11_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c11_info[32].name = "eps";
  c11_info[32].dominantType = "char";
  c11_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c11_info[32].fileTimeLo = 1326727996U;
  c11_info[32].fileTimeHi = 0U;
  c11_info[32].mFileTimeLo = 0U;
  c11_info[32].mFileTimeHi = 0U;
  c11_info[33].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c11_info[33].name = "eml_is_float_class";
  c11_info[33].dominantType = "char";
  c11_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c11_info[33].fileTimeLo = 1286818782U;
  c11_info[33].fileTimeHi = 0U;
  c11_info[33].mFileTimeLo = 0U;
  c11_info[33].mFileTimeHi = 0U;
  c11_info[34].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c11_info[34].name = "eml_eps";
  c11_info[34].dominantType = "char";
  c11_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c11_info[34].fileTimeLo = 1326727996U;
  c11_info[34].fileTimeHi = 0U;
  c11_info[34].mFileTimeLo = 0U;
  c11_info[34].mFileTimeHi = 0U;
  c11_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c11_info[35].name = "eml_float_model";
  c11_info[35].dominantType = "char";
  c11_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c11_info[35].fileTimeLo = 1326727996U;
  c11_info[35].fileTimeHi = 0U;
  c11_info[35].mFileTimeLo = 0U;
  c11_info[35].mFileTimeHi = 0U;
  c11_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c11_info[36].name = "eml_flt2str";
  c11_info[36].dominantType = "double";
  c11_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c11_info[36].fileTimeLo = 1309451196U;
  c11_info[36].fileTimeHi = 0U;
  c11_info[36].mFileTimeLo = 0U;
  c11_info[36].mFileTimeHi = 0U;
  c11_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c11_info[37].name = "char";
  c11_info[37].dominantType = "double";
  c11_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m";
  c11_info[37].fileTimeLo = 1319729968U;
  c11_info[37].fileTimeHi = 0U;
  c11_info[37].mFileTimeLo = 0U;
  c11_info[37].mFileTimeHi = 0U;
  c11_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c11_info[38].name = "eml_int_forloop_overflow_check";
  c11_info[38].dominantType = "";
  c11_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c11_info[38].fileTimeLo = 1346510340U;
  c11_info[38].fileTimeHi = 0U;
  c11_info[38].mFileTimeLo = 0U;
  c11_info[38].mFileTimeHi = 0U;
  c11_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c11_info[39].name = "intmax";
  c11_info[39].dominantType = "char";
  c11_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c11_info[39].fileTimeLo = 1311255316U;
  c11_info[39].fileTimeHi = 0U;
  c11_info[39].mFileTimeLo = 0U;
  c11_info[39].mFileTimeHi = 0U;
  c11_info[40].context = "";
  c11_info[40].name = "eye";
  c11_info[40].dominantType = "double";
  c11_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c11_info[40].fileTimeLo = 1286818688U;
  c11_info[40].fileTimeHi = 0U;
  c11_info[40].mFileTimeLo = 0U;
  c11_info[40].mFileTimeHi = 0U;
  c11_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c11_info[41].name = "eml_assert_valid_size_arg";
  c11_info[41].dominantType = "double";
  c11_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c11_info[41].fileTimeLo = 1286818694U;
  c11_info[41].fileTimeHi = 0U;
  c11_info[41].mFileTimeLo = 0U;
  c11_info[41].mFileTimeHi = 0U;
  c11_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c11_info[42].name = "isinf";
  c11_info[42].dominantType = "double";
  c11_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c11_info[42].fileTimeLo = 1286818760U;
  c11_info[42].fileTimeHi = 0U;
  c11_info[42].mFileTimeLo = 0U;
  c11_info[42].mFileTimeHi = 0U;
  c11_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!numel_for_size";
  c11_info[43].name = "mtimes";
  c11_info[43].dominantType = "double";
  c11_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c11_info[43].fileTimeLo = 1289519692U;
  c11_info[43].fileTimeHi = 0U;
  c11_info[43].mFileTimeLo = 0U;
  c11_info[43].mFileTimeHi = 0U;
  c11_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c11_info[44].name = "eml_index_class";
  c11_info[44].dominantType = "";
  c11_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[44].fileTimeLo = 1323170578U;
  c11_info[44].fileTimeHi = 0U;
  c11_info[44].mFileTimeLo = 0U;
  c11_info[44].mFileTimeHi = 0U;
  c11_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c11_info[45].name = "intmax";
  c11_info[45].dominantType = "char";
  c11_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c11_info[45].fileTimeLo = 1311255316U;
  c11_info[45].fileTimeHi = 0U;
  c11_info[45].mFileTimeLo = 0U;
  c11_info[45].mFileTimeHi = 0U;
  c11_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c11_info[46].name = "eml_is_float_class";
  c11_info[46].dominantType = "char";
  c11_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c11_info[46].fileTimeLo = 1286818782U;
  c11_info[46].fileTimeHi = 0U;
  c11_info[46].mFileTimeLo = 0U;
  c11_info[46].mFileTimeHi = 0U;
  c11_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c11_info[47].name = "min";
  c11_info[47].dominantType = "double";
  c11_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c11_info[47].fileTimeLo = 1311255318U;
  c11_info[47].fileTimeHi = 0U;
  c11_info[47].mFileTimeLo = 0U;
  c11_info[47].mFileTimeHi = 0U;
  c11_info[48].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c11_info[48].name = "eml_min_or_max";
  c11_info[48].dominantType = "char";
  c11_info[48].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c11_info[48].fileTimeLo = 1334071490U;
  c11_info[48].fileTimeHi = 0U;
  c11_info[48].mFileTimeLo = 0U;
  c11_info[48].mFileTimeHi = 0U;
  c11_info[49].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c11_info[49].name = "eml_scalar_eg";
  c11_info[49].dominantType = "double";
  c11_info[49].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[49].fileTimeLo = 1286818796U;
  c11_info[49].fileTimeHi = 0U;
  c11_info[49].mFileTimeLo = 0U;
  c11_info[49].mFileTimeHi = 0U;
  c11_info[50].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c11_info[50].name = "eml_scalexp_alloc";
  c11_info[50].dominantType = "double";
  c11_info[50].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c11_info[50].fileTimeLo = 1352424860U;
  c11_info[50].fileTimeHi = 0U;
  c11_info[50].mFileTimeLo = 0U;
  c11_info[50].mFileTimeHi = 0U;
  c11_info[51].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c11_info[51].name = "eml_index_class";
  c11_info[51].dominantType = "";
  c11_info[51].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[51].fileTimeLo = 1323170578U;
  c11_info[51].fileTimeHi = 0U;
  c11_info[51].mFileTimeLo = 0U;
  c11_info[51].mFileTimeHi = 0U;
  c11_info[52].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum";
  c11_info[52].name = "eml_scalar_eg";
  c11_info[52].dominantType = "double";
  c11_info[52].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c11_info[52].fileTimeLo = 1286818796U;
  c11_info[52].fileTimeHi = 0U;
  c11_info[52].mFileTimeLo = 0U;
  c11_info[52].mFileTimeHi = 0U;
  c11_info[53].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c11_info[53].name = "eml_index_class";
  c11_info[53].dominantType = "";
  c11_info[53].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c11_info[53].fileTimeLo = 1323170578U;
  c11_info[53].fileTimeHi = 0U;
  c11_info[53].mFileTimeLo = 0U;
  c11_info[53].mFileTimeHi = 0U;
  c11_info[54].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c11_info[54].name = "eml_int_forloop_overflow_check";
  c11_info[54].dominantType = "";
  c11_info[54].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c11_info[54].fileTimeLo = 1346510340U;
  c11_info[54].fileTimeHi = 0U;
  c11_info[54].mFileTimeLo = 0U;
  c11_info[54].mFileTimeHi = 0U;
}

static void c11_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c11_b_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c11_c_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c11_d_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c11_e_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c11_mpower(SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c11_a[9], real_T c11_c[9])
{
  int32_T c11_i163;
  real_T c11_b_a[9];
  for (c11_i163 = 0; c11_i163 < 9; c11_i163++) {
    c11_b_a[c11_i163] = c11_a[c11_i163];
  }

  c11_matrix_to_integer_power(chartInstance, c11_b_a, -1.0, c11_c);
}

static void c11_matrix_to_integer_power
  (SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance, real_T c11_a[9],
   real_T c11_b, real_T c11_c[9])
{
  real_T c11_x;
  real_T c11_e;
  boolean_T c11_firstmult;
  real_T c11_b_x;
  real_T c11_ed2;
  real_T c11_b_b;
  real_T c11_y;
  int32_T c11_i164;
  int32_T c11_i165;
  real_T c11_A[9];
  int32_T c11_i166;
  int32_T c11_i167;
  int32_T c11_i168;
  int32_T c11_i169;
  int32_T c11_i170;
  int32_T c11_i171;
  int32_T c11_i172;
  real_T c11_b_A[9];
  int32_T c11_i173;
  real_T c11_c_A[9];
  real_T c11_n1x;
  int32_T c11_i174;
  real_T c11_b_c[9];
  real_T c11_n1xinv;
  real_T c11_b_a;
  real_T c11_c_b;
  real_T c11_b_y;
  real_T c11_rc;
  real_T c11_c_x;
  boolean_T c11_d_b;
  real_T c11_d_x;
  int32_T c11_i175;
  static char_T c11_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c11_u[8];
  const mxArray *c11_c_y = NULL;
  real_T c11_b_u;
  const mxArray *c11_d_y = NULL;
  real_T c11_c_u;
  const mxArray *c11_e_y = NULL;
  real_T c11_d_u;
  const mxArray *c11_f_y = NULL;
  char_T c11_str[14];
  int32_T c11_i176;
  char_T c11_b_str[14];
  int32_T c11_i177;
  int32_T c11_i178;
  int32_T c11_i179;
  int32_T c11_i180;
  int32_T c11_i181;
  int32_T c11_i182;
  int32_T c11_i183;
  int32_T c11_k;
  int32_T c11_b_k;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  int32_T exitg1;
  c11_f_eml_scalar_eg(chartInstance);
  c11_x = c11_b;
  c11_e = muDoubleScalarAbs(c11_x);
  if (c11_e > 0.0) {
    c11_firstmult = TRUE;
    do {
      exitg1 = 0;
      c11_b_x = c11_e / 2.0;
      c11_ed2 = c11_b_x;
      c11_ed2 = muDoubleScalarFloor(c11_ed2);
      c11_b_b = c11_ed2;
      c11_y = 2.0 * c11_b_b;
      if (c11_y != c11_e) {
        if (c11_firstmult) {
          for (c11_i164 = 0; c11_i164 < 9; c11_i164++) {
            c11_c[c11_i164] = c11_a[c11_i164];
          }

          c11_firstmult = FALSE;
        } else {
          c11_g_eml_scalar_eg(chartInstance);
          c11_g_eml_scalar_eg(chartInstance);
          for (c11_i165 = 0; c11_i165 < 9; c11_i165++) {
            c11_A[c11_i165] = c11_c[c11_i165];
          }

          for (c11_i166 = 0; c11_i166 < 3; c11_i166++) {
            c11_i167 = 0;
            for (c11_i168 = 0; c11_i168 < 3; c11_i168++) {
              c11_c[c11_i167 + c11_i166] = 0.0;
              c11_i169 = 0;
              for (c11_i170 = 0; c11_i170 < 3; c11_i170++) {
                c11_c[c11_i167 + c11_i166] += c11_A[c11_i169 + c11_i166] *
                  c11_a[c11_i170 + c11_i167];
                c11_i169 += 3;
              }

              c11_i167 += 3;
            }
          }
        }
      }

      if (c11_ed2 == 0.0) {
        exitg1 = 1;
      } else {
        c11_e = c11_ed2;
        c11_g_eml_scalar_eg(chartInstance);
        c11_g_eml_scalar_eg(chartInstance);
        for (c11_i177 = 0; c11_i177 < 9; c11_i177++) {
          c11_A[c11_i177] = c11_a[c11_i177];
        }

        for (c11_i178 = 0; c11_i178 < 3; c11_i178++) {
          c11_i179 = 0;
          for (c11_i180 = 0; c11_i180 < 3; c11_i180++) {
            c11_a[c11_i179 + c11_i178] = 0.0;
            c11_i181 = 0;
            for (c11_i182 = 0; c11_i182 < 3; c11_i182++) {
              c11_a[c11_i179 + c11_i178] += c11_A[c11_i181 + c11_i178] *
                c11_A[c11_i182 + c11_i179];
              c11_i181 += 3;
            }

            c11_i179 += 3;
          }
        }
      }
    } while (exitg1 == 0);

    if (c11_b < 0.0) {
      for (c11_i171 = 0; c11_i171 < 9; c11_i171++) {
        c11_A[c11_i171] = c11_c[c11_i171];
      }

      for (c11_i172 = 0; c11_i172 < 9; c11_i172++) {
        c11_b_A[c11_i172] = c11_A[c11_i172];
      }

      c11_inv3x3(chartInstance, c11_b_A, c11_c);
      for (c11_i173 = 0; c11_i173 < 9; c11_i173++) {
        c11_c_A[c11_i173] = c11_A[c11_i173];
      }

      c11_n1x = c11_norm(chartInstance, c11_c_A);
      for (c11_i174 = 0; c11_i174 < 9; c11_i174++) {
        c11_b_c[c11_i174] = c11_c[c11_i174];
      }

      c11_n1xinv = c11_norm(chartInstance, c11_b_c);
      c11_b_a = c11_n1x;
      c11_c_b = c11_n1xinv;
      c11_b_y = c11_b_a * c11_c_b;
      c11_rc = 1.0 / c11_b_y;
      guard1 = FALSE;
      guard2 = FALSE;
      if (c11_n1x == 0.0) {
        guard2 = TRUE;
      } else if (c11_n1xinv == 0.0) {
        guard2 = TRUE;
      } else if (c11_rc == 0.0) {
        guard1 = TRUE;
      } else {
        c11_c_x = c11_rc;
        c11_d_b = muDoubleScalarIsNaN(c11_c_x);
        guard3 = FALSE;
        if (c11_d_b) {
          guard3 = TRUE;
        } else {
          if (c11_rc < 2.2204460492503131E-16) {
            guard3 = TRUE;
          }
        }

        if (guard3 == TRUE) {
          c11_d_x = c11_rc;
          for (c11_i175 = 0; c11_i175 < 8; c11_i175++) {
            c11_u[c11_i175] = c11_cv0[c11_i175];
          }

          c11_c_y = NULL;
          sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1,
            8), FALSE);
          c11_b_u = 14.0;
          c11_d_y = NULL;
          sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_b_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c11_c_u = 6.0;
          c11_e_y = NULL;
          sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c11_d_u = c11_d_x;
          c11_f_y = NULL;
          sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_d_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c11_g_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U,
            2U, 14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c11_c_y, 14,
            c11_d_y, 14, c11_e_y), 14, c11_f_y), "sprintf", c11_str);
          for (c11_i176 = 0; c11_i176 < 14; c11_i176++) {
            c11_b_str[c11_i176] = c11_str[c11_i176];
          }

          c11_b_eml_warning(chartInstance, c11_b_str);
        }
      }

      if (guard2 == TRUE) {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        c11_eml_warning(chartInstance);
      }
    }
  } else {
    for (c11_i183 = 0; c11_i183 < 9; c11_i183++) {
      c11_c[c11_i183] = 0.0;
    }

    for (c11_k = 1; c11_k < 4; c11_k++) {
      c11_b_k = c11_k;
      c11_c[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c11_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK(
               "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c11_b_k), 1, 3, 2, 0)
              - 1)) - 1] = 1.0;
    }
  }
}

static void c11_f_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c11_g_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c11_inv3x3(SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c11_x[9], real_T c11_y[9])
{
  int32_T c11_p1;
  int32_T c11_p2;
  int32_T c11_p3;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_absx11;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_absx21;
  real_T c11_f_x;
  real_T c11_g_x;
  real_T c11_absx31;
  real_T c11_t1;
  real_T c11_h_x;
  real_T c11_b_y;
  real_T c11_z;
  real_T c11_i_x;
  real_T c11_c_y;
  real_T c11_b_z;
  real_T c11_a;
  real_T c11_b;
  real_T c11_d_y;
  real_T c11_b_a;
  real_T c11_b_b;
  real_T c11_e_y;
  real_T c11_c_a;
  real_T c11_c_b;
  real_T c11_f_y;
  real_T c11_d_a;
  real_T c11_d_b;
  real_T c11_g_y;
  real_T c11_j_x;
  real_T c11_k_x;
  real_T c11_h_y;
  real_T c11_l_x;
  real_T c11_m_x;
  real_T c11_i_y;
  int32_T c11_itmp;
  real_T c11_n_x;
  real_T c11_j_y;
  real_T c11_c_z;
  real_T c11_e_a;
  real_T c11_e_b;
  real_T c11_k_y;
  real_T c11_f_a;
  real_T c11_f_b;
  real_T c11_l_y;
  real_T c11_o_x;
  real_T c11_m_y;
  real_T c11_t3;
  real_T c11_g_a;
  real_T c11_g_b;
  real_T c11_n_y;
  real_T c11_p_x;
  real_T c11_o_y;
  real_T c11_t2;
  int32_T c11_h_a;
  int32_T c11_c;
  real_T c11_i_a;
  real_T c11_h_b;
  real_T c11_p_y;
  real_T c11_j_a;
  real_T c11_i_b;
  real_T c11_q_y;
  real_T c11_q_x;
  real_T c11_r_y;
  real_T c11_d_z;
  int32_T c11_k_a;
  int32_T c11_b_c;
  int32_T c11_l_a;
  int32_T c11_c_c;
  real_T c11_r_x;
  real_T c11_s_y;
  real_T c11_m_a;
  real_T c11_j_b;
  real_T c11_t_y;
  real_T c11_s_x;
  real_T c11_u_y;
  int32_T c11_n_a;
  int32_T c11_d_c;
  real_T c11_o_a;
  real_T c11_k_b;
  real_T c11_v_y;
  real_T c11_p_a;
  real_T c11_l_b;
  real_T c11_w_y;
  real_T c11_t_x;
  real_T c11_x_y;
  real_T c11_e_z;
  int32_T c11_q_a;
  int32_T c11_e_c;
  int32_T c11_r_a;
  int32_T c11_f_c;
  real_T c11_y_y;
  real_T c11_s_a;
  real_T c11_m_b;
  real_T c11_ab_y;
  real_T c11_u_x;
  real_T c11_bb_y;
  int32_T c11_t_a;
  int32_T c11_g_c;
  real_T c11_u_a;
  real_T c11_n_b;
  real_T c11_cb_y;
  real_T c11_v_a;
  real_T c11_o_b;
  real_T c11_db_y;
  real_T c11_v_x;
  real_T c11_eb_y;
  real_T c11_f_z;
  int32_T c11_w_a;
  int32_T c11_h_c;
  int32_T c11_x_a;
  int32_T c11_i_c;
  boolean_T guard1 = FALSE;
  c11_p1 = 0;
  c11_p2 = 3;
  c11_p3 = 6;
  c11_b_x = c11_x[0];
  c11_c_x = c11_b_x;
  c11_absx11 = muDoubleScalarAbs(c11_c_x);
  c11_d_x = c11_x[1];
  c11_e_x = c11_d_x;
  c11_absx21 = muDoubleScalarAbs(c11_e_x);
  c11_f_x = c11_x[2];
  c11_g_x = c11_f_x;
  c11_absx31 = muDoubleScalarAbs(c11_g_x);
  guard1 = FALSE;
  if (c11_absx21 > c11_absx11) {
    if (c11_absx21 > c11_absx31) {
      c11_p1 = 3;
      c11_p2 = 0;
      c11_t1 = c11_x[0];
      c11_x[0] = c11_x[1];
      c11_x[1] = c11_t1;
      c11_t1 = c11_x[3];
      c11_x[3] = c11_x[4];
      c11_x[4] = c11_t1;
      c11_t1 = c11_x[6];
      c11_x[6] = c11_x[7];
      c11_x[7] = c11_t1;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    if (c11_absx31 > c11_absx11) {
      c11_p1 = 6;
      c11_p3 = 0;
      c11_t1 = c11_x[0];
      c11_x[0] = c11_x[2];
      c11_x[2] = c11_t1;
      c11_t1 = c11_x[3];
      c11_x[3] = c11_x[5];
      c11_x[5] = c11_t1;
      c11_t1 = c11_x[6];
      c11_x[6] = c11_x[8];
      c11_x[8] = c11_t1;
    }
  }

  c11_h_x = c11_x[1];
  c11_b_y = c11_x[0];
  c11_z = c11_h_x / c11_b_y;
  c11_x[1] = c11_z;
  c11_i_x = c11_x[2];
  c11_c_y = c11_x[0];
  c11_b_z = c11_i_x / c11_c_y;
  c11_x[2] = c11_b_z;
  c11_a = c11_x[1];
  c11_b = c11_x[3];
  c11_d_y = c11_a * c11_b;
  c11_x[4] -= c11_d_y;
  c11_b_a = c11_x[2];
  c11_b_b = c11_x[3];
  c11_e_y = c11_b_a * c11_b_b;
  c11_x[5] -= c11_e_y;
  c11_c_a = c11_x[1];
  c11_c_b = c11_x[6];
  c11_f_y = c11_c_a * c11_c_b;
  c11_x[7] -= c11_f_y;
  c11_d_a = c11_x[2];
  c11_d_b = c11_x[6];
  c11_g_y = c11_d_a * c11_d_b;
  c11_x[8] -= c11_g_y;
  c11_j_x = c11_x[5];
  c11_k_x = c11_j_x;
  c11_h_y = muDoubleScalarAbs(c11_k_x);
  c11_l_x = c11_x[4];
  c11_m_x = c11_l_x;
  c11_i_y = muDoubleScalarAbs(c11_m_x);
  if (c11_h_y > c11_i_y) {
    c11_itmp = c11_p2;
    c11_p2 = c11_p3;
    c11_p3 = c11_itmp;
    c11_t1 = c11_x[1];
    c11_x[1] = c11_x[2];
    c11_x[2] = c11_t1;
    c11_t1 = c11_x[4];
    c11_x[4] = c11_x[5];
    c11_x[5] = c11_t1;
    c11_t1 = c11_x[7];
    c11_x[7] = c11_x[8];
    c11_x[8] = c11_t1;
  }

  c11_n_x = c11_x[5];
  c11_j_y = c11_x[4];
  c11_c_z = c11_n_x / c11_j_y;
  c11_x[5] = c11_c_z;
  c11_e_a = c11_x[5];
  c11_e_b = c11_x[7];
  c11_k_y = c11_e_a * c11_e_b;
  c11_x[8] -= c11_k_y;
  c11_f_a = c11_x[5];
  c11_f_b = c11_x[1];
  c11_l_y = c11_f_a * c11_f_b;
  c11_o_x = c11_l_y - c11_x[2];
  c11_m_y = c11_x[8];
  c11_t3 = c11_o_x / c11_m_y;
  c11_g_a = c11_x[7];
  c11_g_b = c11_t3;
  c11_n_y = c11_g_a * c11_g_b;
  c11_p_x = -(c11_x[1] + c11_n_y);
  c11_o_y = c11_x[4];
  c11_t2 = c11_p_x / c11_o_y;
  c11_h_a = c11_p1 + 1;
  c11_c = c11_h_a;
  c11_i_a = c11_x[3];
  c11_h_b = c11_t2;
  c11_p_y = c11_i_a * c11_h_b;
  c11_j_a = c11_x[6];
  c11_i_b = c11_t3;
  c11_q_y = c11_j_a * c11_i_b;
  c11_q_x = (1.0 - c11_p_y) - c11_q_y;
  c11_r_y = c11_x[0];
  c11_d_z = c11_q_x / c11_r_y;
  c11_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c11_c), 1, 9, 1, 0) - 1] = c11_d_z;
  c11_k_a = c11_p1 + 2;
  c11_b_c = c11_k_a;
  c11_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c11_b_c), 1, 9, 1, 0) - 1] = c11_t2;
  c11_l_a = c11_p1 + 3;
  c11_c_c = c11_l_a;
  c11_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c11_c_c), 1, 9, 1, 0) - 1] = c11_t3;
  c11_r_x = -c11_x[5];
  c11_s_y = c11_x[8];
  c11_t3 = c11_r_x / c11_s_y;
  c11_m_a = c11_x[7];
  c11_j_b = c11_t3;
  c11_t_y = c11_m_a * c11_j_b;
  c11_s_x = 1.0 - c11_t_y;
  c11_u_y = c11_x[4];
  c11_t2 = c11_s_x / c11_u_y;
  c11_n_a = c11_p2 + 1;
  c11_d_c = c11_n_a;
  c11_o_a = c11_x[3];
  c11_k_b = c11_t2;
  c11_v_y = c11_o_a * c11_k_b;
  c11_p_a = c11_x[6];
  c11_l_b = c11_t3;
  c11_w_y = c11_p_a * c11_l_b;
  c11_t_x = -(c11_v_y + c11_w_y);
  c11_x_y = c11_x[0];
  c11_e_z = c11_t_x / c11_x_y;
  c11_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c11_d_c), 1, 9, 1, 0) - 1] = c11_e_z;
  c11_q_a = c11_p2 + 2;
  c11_e_c = c11_q_a;
  c11_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c11_e_c), 1, 9, 1, 0) - 1] = c11_t2;
  c11_r_a = c11_p2 + 3;
  c11_f_c = c11_r_a;
  c11_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c11_f_c), 1, 9, 1, 0) - 1] = c11_t3;
  c11_y_y = c11_x[8];
  c11_t3 = 1.0 / c11_y_y;
  c11_s_a = -c11_x[7];
  c11_m_b = c11_t3;
  c11_ab_y = c11_s_a * c11_m_b;
  c11_u_x = c11_ab_y;
  c11_bb_y = c11_x[4];
  c11_t2 = c11_u_x / c11_bb_y;
  c11_t_a = c11_p3 + 1;
  c11_g_c = c11_t_a;
  c11_u_a = c11_x[3];
  c11_n_b = c11_t2;
  c11_cb_y = c11_u_a * c11_n_b;
  c11_v_a = c11_x[6];
  c11_o_b = c11_t3;
  c11_db_y = c11_v_a * c11_o_b;
  c11_v_x = -(c11_cb_y + c11_db_y);
  c11_eb_y = c11_x[0];
  c11_f_z = c11_v_x / c11_eb_y;
  c11_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c11_g_c), 1, 9, 1, 0) - 1] = c11_f_z;
  c11_w_a = c11_p3 + 2;
  c11_h_c = c11_w_a;
  c11_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c11_h_c), 1, 9, 1, 0) - 1] = c11_t2;
  c11_x_a = c11_p3 + 3;
  c11_i_c = c11_x_a;
  c11_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c11_i_c), 1, 9, 1, 0) - 1] = c11_t3;
}

static real_T c11_norm(SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c11_x[9])
{
  real_T c11_y;
  int32_T c11_j;
  real_T c11_b_j;
  real_T c11_s;
  int32_T c11_i;
  real_T c11_b_i;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_b_y;
  real_T c11_d_x;
  boolean_T c11_b;
  boolean_T exitg1;
  c11_y = 0.0;
  c11_j = 0;
  exitg1 = FALSE;
  while ((exitg1 == FALSE) && (c11_j < 3)) {
    c11_b_j = 1.0 + (real_T)c11_j;
    c11_s = 0.0;
    for (c11_i = 0; c11_i < 3; c11_i++) {
      c11_b_i = 1.0 + (real_T)c11_i;
      c11_b_x = c11_x[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c11_b_i), 1, 3, 1, 0) + 3 * ((int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c11_b_j),
        1, 3, 2, 0) - 1)) - 1];
      c11_c_x = c11_b_x;
      c11_b_y = muDoubleScalarAbs(c11_c_x);
      c11_s += c11_b_y;
    }

    c11_d_x = c11_s;
    c11_b = muDoubleScalarIsNaN(c11_d_x);
    if (c11_b) {
      c11_y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (c11_s > c11_y) {
        c11_y = c11_s;
      }

      c11_j++;
    }
  }

  return c11_y;
}

static void c11_eml_warning(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
  int32_T c11_i184;
  static char_T c11_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c11_u[27];
  const mxArray *c11_y = NULL;
  for (c11_i184 = 0; c11_i184 < 27; c11_i184++) {
    c11_u[c11_i184] = c11_varargin_1[c11_i184];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 27),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c11_y));
}

static void c11_b_eml_warning(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, char_T c11_varargin_2[14])
{
  int32_T c11_i185;
  static char_T c11_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c11_u[33];
  const mxArray *c11_y = NULL;
  int32_T c11_i186;
  char_T c11_b_u[14];
  const mxArray *c11_b_y = NULL;
  for (c11_i185 = 0; c11_i185 < 33; c11_i185++) {
    c11_u[c11_i185] = c11_varargin_1[c11_i185];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 33),
                FALSE);
  for (c11_i186 = 0; c11_i186 < 14; c11_i186++) {
    c11_b_u[c11_i186] = c11_varargin_2[c11_i186];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c11_y, 14, c11_b_y));
}

static void c11_h_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c11_i_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c11_j_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c11_eye(SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                    real_T c11_I[16])
{
  int32_T c11_i187;
  int32_T c11_i;
  int32_T c11_b_i;
  for (c11_i187 = 0; c11_i187 < 16; c11_i187++) {
    c11_I[c11_i187] = 0.0;
  }

  for (c11_i = 1; c11_i < 5; c11_i++) {
    c11_b_i = c11_i;
    c11_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c11_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c11_b_i), 1, 4, 2, 0) - 1)
            << 2)) - 1] = 1.0;
  }
}

static void c11_k_eml_scalar_eg(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c11_g_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_sprintf, const char_T *c11_identifier,
  char_T c11_y[14])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_sprintf), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_sprintf);
}

static void c11_h_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  char_T c11_y[14])
{
  char_T c11_cv1[14];
  int32_T c11_i188;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c11_i188 = 0; c11_i188 < 14; c11_i188++) {
    c11_y[c11_i188] = c11_cv1[c11_i188];
  }

  sf_mex_destroy(&c11_u);
}

static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static int32_T c11_i_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i189;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i189, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i189;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_j_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c11_b_is_active_c11_Hquad_control_LIB_MPC, const
  char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_Hquad_control_LIB_MPC), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_Hquad_control_LIB_MPC);
  return c11_y;
}

static uint8_T c11_k_emlrt_marshallIn(SFc11_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info(SFc11_Hquad_control_LIB_MPCInstanceStruct
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

void sf_c11_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2459983092U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2877341927U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(333480238U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2568357890U);
}

mxArray *sf_c11_Hquad_control_LIB_MPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("oMZbdsvy8OZAzoPlGchP1C");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(3);
      pr[1] = (double)(4);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(4);
      pr[1] = (double)(4);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(4);
      pr[1] = (double)(4);
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(4);
      pr[1] = (double)(4);
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

mxArray *sf_c11_Hquad_control_LIB_MPC_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c11_Hquad_control_LIB_MPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[29],T\"P_est\",},{M[1],M[5],T\"state_est\",},{M[8],M[0],T\"is_active_c11_Hquad_control_LIB_MPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_Hquad_control_LIB_MPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
    chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Hquad_control_LIB_MPCMachineNumber_,
           11,
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
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
            c11_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)
            c11_sf_marshallIn);
        }

        {
          real_T *c11_u;
          real_T (*c11_A)[16];
          real_T (*c11_B)[4];
          real_T (*c11_state_est)[4];
          real_T (*c11_C)[12];
          real_T (*c11_D)[3];
          real_T (*c11_Q)[16];
          real_T (*c11_R)[9];
          real_T (*c11_y)[3];
          real_T (*c11_P)[16];
          real_T (*c11_state)[4];
          real_T (*c11_P_est)[16];
          c11_P_est = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
          c11_state = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 9);
          c11_P = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 8);
          c11_y = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 7);
          c11_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c11_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
          c11_Q = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 4);
          c11_D = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c11_C = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 2);
          c11_state_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S,
            1);
          c11_B = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c11_A = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c11_A);
          _SFD_SET_DATA_VALUE_PTR(1U, *c11_B);
          _SFD_SET_DATA_VALUE_PTR(2U, *c11_state_est);
          _SFD_SET_DATA_VALUE_PTR(3U, *c11_C);
          _SFD_SET_DATA_VALUE_PTR(4U, *c11_D);
          _SFD_SET_DATA_VALUE_PTR(5U, *c11_Q);
          _SFD_SET_DATA_VALUE_PTR(6U, *c11_R);
          _SFD_SET_DATA_VALUE_PTR(7U, c11_u);
          _SFD_SET_DATA_VALUE_PTR(8U, *c11_y);
          _SFD_SET_DATA_VALUE_PTR(9U, *c11_P);
          _SFD_SET_DATA_VALUE_PTR(10U, *c11_state);
          _SFD_SET_DATA_VALUE_PTR(11U, *c11_P_est);
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
  return "tQvBlIbv8Q76uvlyfAPTMB";
}

static void sf_opaque_initialize_c11_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_Hquad_control_LIB_MPC
    ((SFc11_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
  initialize_c11_Hquad_control_LIB_MPC
    ((SFc11_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c11_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  enable_c11_Hquad_control_LIB_MPC((SFc11_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  disable_c11_Hquad_control_LIB_MPC((SFc11_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_c11_Hquad_control_LIB_MPC((SFc11_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_Hquad_control_LIB_MPC
    ((SFc11_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_Hquad_control_LIB_MPC();/* state var info */
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

extern void sf_internal_set_sim_state_c11_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_Hquad_control_LIB_MPC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_Hquad_control_LIB_MPC
    ((SFc11_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c11_Hquad_control_LIB_MPC(S);
}

static void sf_opaque_set_sim_state_c11_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c11_Hquad_control_LIB_MPC(S, st);
}

static void sf_opaque_terminate_c11_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_Hquad_control_LIB_MPCInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Hquad_control_LIB_MPC_optimization_info();
    }

    finalize_c11_Hquad_control_LIB_MPC
      ((SFc11_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_Hquad_control_LIB_MPC
    ((SFc11_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_Hquad_control_LIB_MPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_Hquad_control_LIB_MPC
      ((SFc11_Hquad_control_LIB_MPCInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,11,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,11);
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
        infoStruct,11,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2975444651U));
  ssSetChecksum1(S,(197335433U));
  ssSetChecksum2(S,(3234268684U));
  ssSetChecksum3(S,(2095806301U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_Hquad_control_LIB_MPC(SimStruct *S)
{
  SFc11_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Hquad_control_LIB_MPCInstanceStruct *)utMalloc(sizeof
    (SFc11_Hquad_control_LIB_MPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_Hquad_control_LIB_MPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_Hquad_control_LIB_MPC;
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

void c11_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_Hquad_control_LIB_MPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_Hquad_control_LIB_MPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
