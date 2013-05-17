/* Include files */

#include "blascompat32.h"
#include "Hquad_control_LIB_MPC_sfun.h"
#include "c5_Hquad_control_LIB_MPC.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hquad_control_LIB_MPC_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c5_debug_family_names[18] = { "n", "x_", "P_", "K", "nargin",
  "nargout", "A", "B", "C", "D", "Q", "R", "u", "y", "P", "state", "state_est",
  "P_est" };

/* Function Declarations */
static void initialize_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initialize_params_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void enable_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void disable_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void set_sim_state_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray *c5_st);
static void finalize_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void sf_c5_Hquad_control_LIB_MPC(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c5_chartstep_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initSimStructsc5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_P_est, const char_T *c5_identifier, real_T
  c5_y[9]);
static void c5_b_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[9]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_c_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_state_est, const char_T *c5_identifier,
  real_T c5_y[3]);
static void c5_d_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3]);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_e_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_f_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[6]);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[29]);
static void c5_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c5_b_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c5_c_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c5_d_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c5_e_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c5_mpower(SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                      real_T c5_a[4], real_T c5_c[4]);
static void c5_matrix_to_integer_power(SFc5_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, real_T c5_a[4], real_T c5_b, real_T c5_c[4]);
static void c5_f_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c5_g_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static real_T c5_norm(SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                      real_T c5_x[4]);
static void c5_eml_warning(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c5_b_eml_warning(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, char_T c5_varargin_2[14]);
static void c5_h_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c5_i_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c5_j_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c5_eye(SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                   real_T c5_I[9]);
static void c5_k_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c5_g_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_sprintf, const char_T *c5_identifier, char_T
  c5_y[14]);
static void c5_h_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  char_T c5_y[14]);
static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_i_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static uint8_T c5_j_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_Hquad_control_LIB_MPC, const
  char_T *c5_identifier);
static uint8_T c5_k_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId);
static void init_dsm_address_info(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c5_is_active_c5_Hquad_control_LIB_MPC = 0U;
}

static void initialize_params_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void enable_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c5_update_debugger_state_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_y = NULL;
  int32_T c5_i0;
  real_T c5_u[9];
  const mxArray *c5_b_y = NULL;
  int32_T c5_i1;
  real_T c5_b_u[3];
  const mxArray *c5_c_y = NULL;
  uint8_T c5_hoistedGlobal;
  uint8_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  real_T (*c5_state_est)[3];
  real_T (*c5_P_est)[9];
  c5_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_st = NULL;
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(3), FALSE);
  for (c5_i0 = 0; c5_i0 < 9; c5_i0++) {
    c5_u[c5_i0] = (*c5_P_est)[c5_i0];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c5_y, 0, c5_b_y);
  for (c5_i1 = 0; c5_i1 < 3; c5_i1++) {
    c5_b_u[c5_i1] = (*c5_state_est)[c5_i1];
  }

  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_hoistedGlobal = chartInstance->c5_is_active_c5_Hquad_control_LIB_MPC;
  c5_c_u = c5_hoistedGlobal;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c5_y, 2, c5_d_y);
  sf_mex_assign(&c5_st, c5_y, FALSE);
  return c5_st;
}

static void set_sim_state_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T c5_dv0[9];
  int32_T c5_i2;
  real_T c5_dv1[3];
  int32_T c5_i3;
  real_T (*c5_P_est)[9];
  real_T (*c5_state_est)[3];
  c5_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c5_doneDoubleBufferReInit = TRUE;
  c5_u = sf_mex_dup(c5_st);
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 0)),
                      "P_est", c5_dv0);
  for (c5_i2 = 0; c5_i2 < 9; c5_i2++) {
    (*c5_P_est)[c5_i2] = c5_dv0[c5_i2];
  }

  c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 1)),
                        "state_est", c5_dv1);
  for (c5_i3 = 0; c5_i3 < 3; c5_i3++) {
    (*c5_state_est)[c5_i3] = c5_dv1[c5_i3];
  }

  chartInstance->c5_is_active_c5_Hquad_control_LIB_MPC = c5_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_u, 2)),
     "is_active_c5_Hquad_control_LIB_MPC");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_Hquad_control_LIB_MPC(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void sf_c5_Hquad_control_LIB_MPC(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
  int32_T c5_i4;
  int32_T c5_i5;
  int32_T c5_i6;
  int32_T c5_i7;
  int32_T c5_i8;
  int32_T c5_i9;
  int32_T c5_i10;
  int32_T c5_i11;
  int32_T c5_i12;
  int32_T c5_i13;
  int32_T c5_i14;
  real_T *c5_u;
  real_T (*c5_P_est)[9];
  real_T (*c5_state)[3];
  real_T (*c5_P)[9];
  real_T (*c5_y)[2];
  real_T (*c5_R)[4];
  real_T (*c5_Q)[9];
  real_T (*c5_D)[2];
  real_T (*c5_C)[6];
  real_T (*c5_state_est)[3];
  real_T (*c5_B)[3];
  real_T (*c5_A)[9];
  c5_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_state = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c5_P = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 8);
  c5_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 7);
  c5_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c5_R = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
  c5_Q = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c5_D = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 3);
  c5_C = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c5_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c5_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
  for (c5_i4 = 0; c5_i4 < 9; c5_i4++) {
    _SFD_DATA_RANGE_CHECK((*c5_A)[c5_i4], 0U);
  }

  for (c5_i5 = 0; c5_i5 < 3; c5_i5++) {
    _SFD_DATA_RANGE_CHECK((*c5_B)[c5_i5], 1U);
  }

  for (c5_i6 = 0; c5_i6 < 3; c5_i6++) {
    _SFD_DATA_RANGE_CHECK((*c5_state_est)[c5_i6], 2U);
  }

  for (c5_i7 = 0; c5_i7 < 6; c5_i7++) {
    _SFD_DATA_RANGE_CHECK((*c5_C)[c5_i7], 3U);
  }

  for (c5_i8 = 0; c5_i8 < 2; c5_i8++) {
    _SFD_DATA_RANGE_CHECK((*c5_D)[c5_i8], 4U);
  }

  for (c5_i9 = 0; c5_i9 < 9; c5_i9++) {
    _SFD_DATA_RANGE_CHECK((*c5_Q)[c5_i9], 5U);
  }

  for (c5_i10 = 0; c5_i10 < 4; c5_i10++) {
    _SFD_DATA_RANGE_CHECK((*c5_R)[c5_i10], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c5_u, 7U);
  for (c5_i11 = 0; c5_i11 < 2; c5_i11++) {
    _SFD_DATA_RANGE_CHECK((*c5_y)[c5_i11], 8U);
  }

  for (c5_i12 = 0; c5_i12 < 9; c5_i12++) {
    _SFD_DATA_RANGE_CHECK((*c5_P)[c5_i12], 9U);
  }

  for (c5_i13 = 0; c5_i13 < 3; c5_i13++) {
    _SFD_DATA_RANGE_CHECK((*c5_state)[c5_i13], 10U);
  }

  for (c5_i14 = 0; c5_i14 < 9; c5_i14++) {
    _SFD_DATA_RANGE_CHECK((*c5_P_est)[c5_i14], 11U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  c5_chartstep_c5_Hquad_control_LIB_MPC(chartInstance);
  sf_debug_check_for_state_inconsistency(_Hquad_control_LIB_MPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c5_chartstep_c5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  real_T c5_hoistedGlobal;
  int32_T c5_i15;
  real_T c5_A[9];
  int32_T c5_i16;
  real_T c5_B[3];
  int32_T c5_i17;
  real_T c5_C[6];
  int32_T c5_i18;
  real_T c5_D[2];
  int32_T c5_i19;
  real_T c5_Q[9];
  int32_T c5_i20;
  real_T c5_R[4];
  real_T c5_u;
  int32_T c5_i21;
  real_T c5_y[2];
  int32_T c5_i22;
  real_T c5_P[9];
  int32_T c5_i23;
  real_T c5_state[3];
  uint32_T c5_debug_family_var_map[18];
  real_T c5_n;
  real_T c5_x_[3];
  real_T c5_P_[9];
  real_T c5_K[6];
  real_T c5_nargin = 10.0;
  real_T c5_nargout = 2.0;
  real_T c5_state_est[3];
  real_T c5_P_est[9];
  int32_T c5_i24;
  real_T c5_a[9];
  int32_T c5_i25;
  real_T c5_b[3];
  int32_T c5_i26;
  real_T c5_b_y[3];
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  real_T c5_b_b;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  real_T c5_c_b[9];
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  real_T c5_c_y[9];
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  real_T c5_d_y[9];
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  real_T c5_d_b[6];
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  real_T c5_e_y[6];
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  real_T c5_b_a[6];
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  real_T c5_f_y[6];
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  real_T c5_g_y[4];
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  real_T c5_h_y[4];
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i80;
  int32_T c5_i81;
  int32_T c5_i82;
  int32_T c5_i83;
  int32_T c5_i84;
  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  real_T c5_i_y[2];
  int32_T c5_i93;
  int32_T c5_i94;
  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_i100;
  int32_T c5_i101;
  int32_T c5_i102;
  int32_T c5_i103;
  int32_T c5_i104;
  int32_T c5_i105;
  int32_T c5_i106;
  int32_T c5_i107;
  int32_T c5_i108;
  int32_T c5_i109;
  int32_T c5_i110;
  int32_T c5_i111;
  int32_T c5_i112;
  int32_T c5_i113;
  int32_T c5_i114;
  int32_T c5_i115;
  int32_T c5_i116;
  int32_T c5_i117;
  int32_T c5_i118;
  int32_T c5_i119;
  int32_T c5_i120;
  int32_T c5_i121;
  int32_T c5_i122;
  int32_T c5_i123;
  real_T *c5_b_u;
  real_T (*c5_b_state_est)[3];
  real_T (*c5_b_P_est)[9];
  real_T (*c5_b_state)[3];
  real_T (*c5_b_P)[9];
  real_T (*c5_j_y)[2];
  real_T (*c5_b_R)[4];
  real_T (*c5_b_Q)[9];
  real_T (*c5_b_D)[2];
  real_T (*c5_b_C)[6];
  real_T (*c5_b_B)[3];
  real_T (*c5_b_A)[9];
  c5_b_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c5_b_state = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c5_b_P = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 8);
  c5_j_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 7);
  c5_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c5_b_R = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
  c5_b_Q = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c5_b_D = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 3);
  c5_b_C = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c5_b_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c5_b_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c5_b_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *c5_b_u;
  for (c5_i15 = 0; c5_i15 < 9; c5_i15++) {
    c5_A[c5_i15] = (*c5_b_A)[c5_i15];
  }

  for (c5_i16 = 0; c5_i16 < 3; c5_i16++) {
    c5_B[c5_i16] = (*c5_b_B)[c5_i16];
  }

  for (c5_i17 = 0; c5_i17 < 6; c5_i17++) {
    c5_C[c5_i17] = (*c5_b_C)[c5_i17];
  }

  for (c5_i18 = 0; c5_i18 < 2; c5_i18++) {
    c5_D[c5_i18] = (*c5_b_D)[c5_i18];
  }

  for (c5_i19 = 0; c5_i19 < 9; c5_i19++) {
    c5_Q[c5_i19] = (*c5_b_Q)[c5_i19];
  }

  for (c5_i20 = 0; c5_i20 < 4; c5_i20++) {
    c5_R[c5_i20] = (*c5_b_R)[c5_i20];
  }

  c5_u = c5_hoistedGlobal;
  for (c5_i21 = 0; c5_i21 < 2; c5_i21++) {
    c5_y[c5_i21] = (*c5_j_y)[c5_i21];
  }

  for (c5_i22 = 0; c5_i22 < 9; c5_i22++) {
    c5_P[c5_i22] = (*c5_b_P)[c5_i22];
  }

  for (c5_i23 = 0; c5_i23 < 3; c5_i23++) {
    c5_state[c5_i23] = (*c5_b_state)[c5_i23];
  }

  sf_debug_symbol_scope_push_eml(0U, 18U, 18U, c5_debug_family_names,
    c5_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c5_n, 0U, c5_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c5_x_, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_P_, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_K, 3U, c5_g_sf_marshallOut,
    c5_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargin, 4U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c5_nargout, 5U, c5_d_sf_marshallOut,
    c5_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c5_A, 6U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_B, 7U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_C, 8U, c5_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_D, 9U, c5_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_Q, 10U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_R, 11U, c5_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c5_u, 12U, c5_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_y, 13U, c5_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_P, 14U, c5_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c5_state, 15U, c5_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c5_state_est, 16U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c5_P_est, 17U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  c5_n = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 10);
  for (c5_i24 = 0; c5_i24 < 9; c5_i24++) {
    c5_a[c5_i24] = c5_A[c5_i24];
  }

  for (c5_i25 = 0; c5_i25 < 3; c5_i25++) {
    c5_b[c5_i25] = c5_state[c5_i25];
  }

  c5_eml_scalar_eg(chartInstance);
  c5_eml_scalar_eg(chartInstance);
  for (c5_i26 = 0; c5_i26 < 3; c5_i26++) {
    c5_b_y[c5_i26] = 0.0;
    c5_i27 = 0;
    for (c5_i28 = 0; c5_i28 < 3; c5_i28++) {
      c5_b_y[c5_i26] += c5_a[c5_i27 + c5_i26] * c5_b[c5_i28];
      c5_i27 += 3;
    }
  }

  for (c5_i29 = 0; c5_i29 < 3; c5_i29++) {
    c5_b[c5_i29] = c5_B[c5_i29];
  }

  c5_b_b = c5_u;
  for (c5_i30 = 0; c5_i30 < 3; c5_i30++) {
    c5_b[c5_i30] *= c5_b_b;
  }

  for (c5_i31 = 0; c5_i31 < 3; c5_i31++) {
    c5_x_[c5_i31] = c5_b_y[c5_i31] + c5_b[c5_i31];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 11);
  for (c5_i32 = 0; c5_i32 < 9; c5_i32++) {
    c5_a[c5_i32] = c5_A[c5_i32];
  }

  for (c5_i33 = 0; c5_i33 < 9; c5_i33++) {
    c5_c_b[c5_i33] = c5_P[c5_i33];
  }

  c5_b_eml_scalar_eg(chartInstance);
  c5_b_eml_scalar_eg(chartInstance);
  for (c5_i34 = 0; c5_i34 < 3; c5_i34++) {
    c5_i35 = 0;
    for (c5_i36 = 0; c5_i36 < 3; c5_i36++) {
      c5_c_y[c5_i35 + c5_i34] = 0.0;
      c5_i37 = 0;
      for (c5_i38 = 0; c5_i38 < 3; c5_i38++) {
        c5_c_y[c5_i35 + c5_i34] += c5_a[c5_i37 + c5_i34] * c5_c_b[c5_i38 +
          c5_i35];
        c5_i37 += 3;
      }

      c5_i35 += 3;
    }
  }

  c5_i39 = 0;
  for (c5_i40 = 0; c5_i40 < 3; c5_i40++) {
    c5_i41 = 0;
    for (c5_i42 = 0; c5_i42 < 3; c5_i42++) {
      c5_c_b[c5_i42 + c5_i39] = c5_A[c5_i41 + c5_i40];
      c5_i41 += 3;
    }

    c5_i39 += 3;
  }

  c5_b_eml_scalar_eg(chartInstance);
  c5_b_eml_scalar_eg(chartInstance);
  for (c5_i43 = 0; c5_i43 < 3; c5_i43++) {
    c5_i44 = 0;
    for (c5_i45 = 0; c5_i45 < 3; c5_i45++) {
      c5_d_y[c5_i44 + c5_i43] = 0.0;
      c5_i46 = 0;
      for (c5_i47 = 0; c5_i47 < 3; c5_i47++) {
        c5_d_y[c5_i44 + c5_i43] += c5_c_y[c5_i46 + c5_i43] * c5_c_b[c5_i47 +
          c5_i44];
        c5_i46 += 3;
      }

      c5_i44 += 3;
    }
  }

  for (c5_i48 = 0; c5_i48 < 9; c5_i48++) {
    c5_P_[c5_i48] = c5_d_y[c5_i48] + c5_Q[c5_i48];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
  for (c5_i49 = 0; c5_i49 < 9; c5_i49++) {
    c5_a[c5_i49] = c5_P_[c5_i49];
  }

  c5_i50 = 0;
  for (c5_i51 = 0; c5_i51 < 2; c5_i51++) {
    c5_i52 = 0;
    for (c5_i53 = 0; c5_i53 < 3; c5_i53++) {
      c5_d_b[c5_i53 + c5_i50] = c5_C[c5_i52 + c5_i51];
      c5_i52 += 2;
    }

    c5_i50 += 3;
  }

  c5_c_eml_scalar_eg(chartInstance);
  c5_c_eml_scalar_eg(chartInstance);
  for (c5_i54 = 0; c5_i54 < 3; c5_i54++) {
    c5_i55 = 0;
    for (c5_i56 = 0; c5_i56 < 2; c5_i56++) {
      c5_e_y[c5_i55 + c5_i54] = 0.0;
      c5_i57 = 0;
      for (c5_i58 = 0; c5_i58 < 3; c5_i58++) {
        c5_e_y[c5_i55 + c5_i54] += c5_a[c5_i57 + c5_i54] * c5_d_b[c5_i58 +
          c5_i55];
        c5_i57 += 3;
      }

      c5_i55 += 3;
    }
  }

  for (c5_i59 = 0; c5_i59 < 6; c5_i59++) {
    c5_b_a[c5_i59] = c5_C[c5_i59];
  }

  for (c5_i60 = 0; c5_i60 < 9; c5_i60++) {
    c5_c_b[c5_i60] = c5_P_[c5_i60];
  }

  c5_d_eml_scalar_eg(chartInstance);
  c5_d_eml_scalar_eg(chartInstance);
  for (c5_i61 = 0; c5_i61 < 2; c5_i61++) {
    c5_i62 = 0;
    c5_i63 = 0;
    for (c5_i64 = 0; c5_i64 < 3; c5_i64++) {
      c5_f_y[c5_i62 + c5_i61] = 0.0;
      c5_i65 = 0;
      for (c5_i66 = 0; c5_i66 < 3; c5_i66++) {
        c5_f_y[c5_i62 + c5_i61] += c5_b_a[c5_i65 + c5_i61] * c5_c_b[c5_i66 +
          c5_i63];
        c5_i65 += 2;
      }

      c5_i62 += 2;
      c5_i63 += 3;
    }
  }

  c5_i67 = 0;
  for (c5_i68 = 0; c5_i68 < 2; c5_i68++) {
    c5_i69 = 0;
    for (c5_i70 = 0; c5_i70 < 3; c5_i70++) {
      c5_d_b[c5_i70 + c5_i67] = c5_C[c5_i69 + c5_i68];
      c5_i69 += 2;
    }

    c5_i67 += 3;
  }

  c5_e_eml_scalar_eg(chartInstance);
  c5_e_eml_scalar_eg(chartInstance);
  for (c5_i71 = 0; c5_i71 < 2; c5_i71++) {
    c5_i72 = 0;
    c5_i73 = 0;
    for (c5_i74 = 0; c5_i74 < 2; c5_i74++) {
      c5_g_y[c5_i72 + c5_i71] = 0.0;
      c5_i75 = 0;
      for (c5_i76 = 0; c5_i76 < 3; c5_i76++) {
        c5_g_y[c5_i72 + c5_i71] += c5_f_y[c5_i75 + c5_i71] * c5_d_b[c5_i76 +
          c5_i73];
        c5_i75 += 2;
      }

      c5_i72 += 2;
      c5_i73 += 3;
    }
  }

  for (c5_i77 = 0; c5_i77 < 4; c5_i77++) {
    c5_h_y[c5_i77] = c5_g_y[c5_i77] + c5_R[c5_i77];
  }

  c5_mpower(chartInstance, c5_h_y, c5_g_y);
  c5_h_eml_scalar_eg(chartInstance);
  c5_h_eml_scalar_eg(chartInstance);
  for (c5_i78 = 0; c5_i78 < 6; c5_i78++) {
    c5_K[c5_i78] = 0.0;
  }

  for (c5_i79 = 0; c5_i79 < 6; c5_i79++) {
    c5_K[c5_i79] = 0.0;
  }

  for (c5_i80 = 0; c5_i80 < 6; c5_i80++) {
    c5_d_b[c5_i80] = c5_K[c5_i80];
  }

  for (c5_i81 = 0; c5_i81 < 6; c5_i81++) {
    c5_K[c5_i81] = c5_d_b[c5_i81];
  }

  for (c5_i82 = 0; c5_i82 < 6; c5_i82++) {
    c5_d_b[c5_i82] = c5_K[c5_i82];
  }

  for (c5_i83 = 0; c5_i83 < 6; c5_i83++) {
    c5_K[c5_i83] = c5_d_b[c5_i83];
  }

  for (c5_i84 = 0; c5_i84 < 3; c5_i84++) {
    c5_i85 = 0;
    c5_i86 = 0;
    for (c5_i87 = 0; c5_i87 < 2; c5_i87++) {
      c5_K[c5_i85 + c5_i84] = 0.0;
      c5_i88 = 0;
      for (c5_i89 = 0; c5_i89 < 2; c5_i89++) {
        c5_K[c5_i85 + c5_i84] += c5_e_y[c5_i88 + c5_i84] * c5_g_y[c5_i89 +
          c5_i86];
        c5_i88 += 3;
      }

      c5_i85 += 3;
      c5_i86 += 2;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
  for (c5_i90 = 0; c5_i90 < 6; c5_i90++) {
    c5_b_a[c5_i90] = c5_C[c5_i90];
  }

  for (c5_i91 = 0; c5_i91 < 3; c5_i91++) {
    c5_b[c5_i91] = c5_x_[c5_i91];
  }

  c5_i_eml_scalar_eg(chartInstance);
  c5_i_eml_scalar_eg(chartInstance);
  for (c5_i92 = 0; c5_i92 < 2; c5_i92++) {
    c5_i_y[c5_i92] = 0.0;
    c5_i93 = 0;
    for (c5_i94 = 0; c5_i94 < 3; c5_i94++) {
      c5_i_y[c5_i92] += c5_b_a[c5_i93 + c5_i92] * c5_b[c5_i94];
      c5_i93 += 2;
    }
  }

  for (c5_i95 = 0; c5_i95 < 6; c5_i95++) {
    c5_d_b[c5_i95] = c5_K[c5_i95];
  }

  for (c5_i96 = 0; c5_i96 < 2; c5_i96++) {
    c5_i_y[c5_i96] = c5_y[c5_i96] - c5_i_y[c5_i96];
  }

  c5_j_eml_scalar_eg(chartInstance);
  c5_j_eml_scalar_eg(chartInstance);
  for (c5_i97 = 0; c5_i97 < 3; c5_i97++) {
    c5_b_y[c5_i97] = 0.0;
    c5_i98 = 0;
    for (c5_i99 = 0; c5_i99 < 2; c5_i99++) {
      c5_b_y[c5_i97] += c5_d_b[c5_i98 + c5_i97] * c5_i_y[c5_i99];
      c5_i98 += 3;
    }
  }

  for (c5_i100 = 0; c5_i100 < 3; c5_i100++) {
    c5_state_est[c5_i100] = c5_x_[c5_i100] + c5_b_y[c5_i100];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 16);
  for (c5_i101 = 0; c5_i101 < 6; c5_i101++) {
    c5_d_b[c5_i101] = c5_K[c5_i101];
  }

  for (c5_i102 = 0; c5_i102 < 6; c5_i102++) {
    c5_b_a[c5_i102] = c5_C[c5_i102];
  }

  c5_k_eml_scalar_eg(chartInstance);
  c5_k_eml_scalar_eg(chartInstance);
  for (c5_i103 = 0; c5_i103 < 3; c5_i103++) {
    c5_i104 = 0;
    c5_i105 = 0;
    for (c5_i106 = 0; c5_i106 < 3; c5_i106++) {
      c5_c_y[c5_i104 + c5_i103] = 0.0;
      c5_i107 = 0;
      for (c5_i108 = 0; c5_i108 < 2; c5_i108++) {
        c5_c_y[c5_i104 + c5_i103] += c5_d_b[c5_i107 + c5_i103] * c5_b_a[c5_i108
          + c5_i105];
        c5_i107 += 3;
      }

      c5_i104 += 3;
      c5_i105 += 2;
    }
  }

  c5_eye(chartInstance, c5_a);
  for (c5_i109 = 0; c5_i109 < 9; c5_i109++) {
    c5_a[c5_i109] -= c5_c_y[c5_i109];
  }

  for (c5_i110 = 0; c5_i110 < 9; c5_i110++) {
    c5_c_b[c5_i110] = c5_P_[c5_i110];
  }

  c5_b_eml_scalar_eg(chartInstance);
  c5_b_eml_scalar_eg(chartInstance);
  for (c5_i111 = 0; c5_i111 < 9; c5_i111++) {
    c5_P_est[c5_i111] = 0.0;
  }

  for (c5_i112 = 0; c5_i112 < 9; c5_i112++) {
    c5_P_est[c5_i112] = 0.0;
  }

  for (c5_i113 = 0; c5_i113 < 9; c5_i113++) {
    c5_d_y[c5_i113] = c5_P_est[c5_i113];
  }

  for (c5_i114 = 0; c5_i114 < 9; c5_i114++) {
    c5_P_est[c5_i114] = c5_d_y[c5_i114];
  }

  for (c5_i115 = 0; c5_i115 < 9; c5_i115++) {
    c5_d_y[c5_i115] = c5_P_est[c5_i115];
  }

  for (c5_i116 = 0; c5_i116 < 9; c5_i116++) {
    c5_P_est[c5_i116] = c5_d_y[c5_i116];
  }

  for (c5_i117 = 0; c5_i117 < 3; c5_i117++) {
    c5_i118 = 0;
    for (c5_i119 = 0; c5_i119 < 3; c5_i119++) {
      c5_P_est[c5_i118 + c5_i117] = 0.0;
      c5_i120 = 0;
      for (c5_i121 = 0; c5_i121 < 3; c5_i121++) {
        c5_P_est[c5_i118 + c5_i117] += c5_a[c5_i120 + c5_i117] * c5_c_b[c5_i121
          + c5_i118];
        c5_i120 += 3;
      }

      c5_i118 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -16);
  sf_debug_symbol_scope_pop();
  for (c5_i122 = 0; c5_i122 < 3; c5_i122++) {
    (*c5_b_state_est)[c5_i122] = c5_state_est[c5_i122];
  }

  for (c5_i123 = 0; c5_i123 < 9; c5_i123++) {
    (*c5_b_P_est)[c5_i123] = c5_P_est[c5_i123];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c5_sfEvent);
}

static void initSimStructsc5_Hquad_control_LIB_MPC
  (SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i124;
  int32_T c5_i125;
  int32_T c5_i126;
  real_T c5_b_inData[9];
  int32_T c5_i127;
  int32_T c5_i128;
  int32_T c5_i129;
  real_T c5_u[9];
  const mxArray *c5_y = NULL;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i124 = 0;
  for (c5_i125 = 0; c5_i125 < 3; c5_i125++) {
    for (c5_i126 = 0; c5_i126 < 3; c5_i126++) {
      c5_b_inData[c5_i126 + c5_i124] = (*(real_T (*)[9])c5_inData)[c5_i126 +
        c5_i124];
    }

    c5_i124 += 3;
  }

  c5_i127 = 0;
  for (c5_i128 = 0; c5_i128 < 3; c5_i128++) {
    for (c5_i129 = 0; c5_i129 < 3; c5_i129++) {
      c5_u[c5_i129 + c5_i127] = c5_b_inData[c5_i129 + c5_i127];
    }

    c5_i127 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_P_est, const char_T *c5_identifier, real_T
  c5_y[9])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_P_est), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_P_est);
}

static void c5_b_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[9])
{
  real_T c5_dv2[9];
  int32_T c5_i130;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv2, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c5_i130 = 0; c5_i130 < 9; c5_i130++) {
    c5_y[c5_i130] = c5_dv2[c5_i130];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_P_est;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[9];
  int32_T c5_i131;
  int32_T c5_i132;
  int32_T c5_i133;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_P_est = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_P_est), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_P_est);
  c5_i131 = 0;
  for (c5_i132 = 0; c5_i132 < 3; c5_i132++) {
    for (c5_i133 = 0; c5_i133 < 3; c5_i133++) {
      (*(real_T (*)[9])c5_outData)[c5_i133 + c5_i131] = c5_y[c5_i133 + c5_i131];
    }

    c5_i131 += 3;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i134;
  real_T c5_b_inData[3];
  int32_T c5_i135;
  real_T c5_u[3];
  const mxArray *c5_y = NULL;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i134 = 0; c5_i134 < 3; c5_i134++) {
    c5_b_inData[c5_i134] = (*(real_T (*)[3])c5_inData)[c5_i134];
  }

  for (c5_i135 = 0; c5_i135 < 3; c5_i135++) {
    c5_u[c5_i135] = c5_b_inData[c5_i135];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_c_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_state_est, const char_T *c5_identifier,
  real_T c5_y[3])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_state_est), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_state_est);
}

static void c5_d_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[3])
{
  real_T c5_dv3[3];
  int32_T c5_i136;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c5_i136 = 0; c5_i136 < 3; c5_i136++) {
    c5_y[c5_i136] = c5_dv3[c5_i136];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_state_est;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[3];
  int32_T c5_i137;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_state_est = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_state_est), &c5_thisId,
                        c5_y);
  sf_mex_destroy(&c5_state_est);
  for (c5_i137 = 0; c5_i137 < 3; c5_i137++) {
    (*(real_T (*)[3])c5_outData)[c5_i137] = c5_y[c5_i137];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i138;
  real_T c5_b_inData[2];
  int32_T c5_i139;
  real_T c5_u[2];
  const mxArray *c5_y = NULL;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i138 = 0; c5_i138 < 2; c5_i138++) {
    c5_b_inData[c5_i138] = (*(real_T (*)[2])c5_inData)[c5_i138];
  }

  for (c5_i139 = 0; c5_i139 < 2; c5_i139++) {
    c5_u[c5_i139] = c5_b_inData[c5_i139];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(real_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i140;
  int32_T c5_i141;
  int32_T c5_i142;
  real_T c5_b_inData[4];
  int32_T c5_i143;
  int32_T c5_i144;
  int32_T c5_i145;
  real_T c5_u[4];
  const mxArray *c5_y = NULL;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i140 = 0;
  for (c5_i141 = 0; c5_i141 < 2; c5_i141++) {
    for (c5_i142 = 0; c5_i142 < 2; c5_i142++) {
      c5_b_inData[c5_i142 + c5_i140] = (*(real_T (*)[4])c5_inData)[c5_i142 +
        c5_i140];
    }

    c5_i140 += 2;
  }

  c5_i143 = 0;
  for (c5_i144 = 0; c5_i144 < 2; c5_i144++) {
    for (c5_i145 = 0; c5_i145 < 2; c5_i145++) {
      c5_u[c5_i145 + c5_i143] = c5_b_inData[c5_i145 + c5_i143];
    }

    c5_i143 += 2;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i146;
  int32_T c5_i147;
  int32_T c5_i148;
  real_T c5_b_inData[6];
  int32_T c5_i149;
  int32_T c5_i150;
  int32_T c5_i151;
  real_T c5_u[6];
  const mxArray *c5_y = NULL;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i146 = 0;
  for (c5_i147 = 0; c5_i147 < 3; c5_i147++) {
    for (c5_i148 = 0; c5_i148 < 2; c5_i148++) {
      c5_b_inData[c5_i148 + c5_i146] = (*(real_T (*)[6])c5_inData)[c5_i148 +
        c5_i146];
    }

    c5_i146 += 2;
  }

  c5_i149 = 0;
  for (c5_i150 = 0; c5_i150 < 3; c5_i150++) {
    for (c5_i151 = 0; c5_i151 < 2; c5_i151++) {
      c5_u[c5_i151 + c5_i149] = c5_b_inData[c5_i151 + c5_i149];
    }

    c5_i149 += 2;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 2, 3), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static real_T c5_e_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_nargout;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_nargout = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_nargout), &c5_thisId);
  sf_mex_destroy(&c5_nargout);
  *(real_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i152;
  int32_T c5_i153;
  int32_T c5_i154;
  real_T c5_b_inData[6];
  int32_T c5_i155;
  int32_T c5_i156;
  int32_T c5_i157;
  real_T c5_u[6];
  const mxArray *c5_y = NULL;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i152 = 0;
  for (c5_i153 = 0; c5_i153 < 2; c5_i153++) {
    for (c5_i154 = 0; c5_i154 < 3; c5_i154++) {
      c5_b_inData[c5_i154 + c5_i152] = (*(real_T (*)[6])c5_inData)[c5_i154 +
        c5_i152];
    }

    c5_i152 += 3;
  }

  c5_i155 = 0;
  for (c5_i156 = 0; c5_i156 < 2; c5_i156++) {
    for (c5_i157 = 0; c5_i157 < 3; c5_i157++) {
      c5_u[c5_i157 + c5_i155] = c5_b_inData[c5_i157 + c5_i155];
    }

    c5_i155 += 3;
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 0, 0U, 1U, 0U, 2, 3, 2), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static void c5_f_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  real_T c5_y[6])
{
  real_T c5_dv4[6];
  int32_T c5_i158;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_dv4, 1, 0, 0U, 1, 0U, 2, 3, 2);
  for (c5_i158 = 0; c5_i158 < 6; c5_i158++) {
    c5_y[c5_i158] = c5_dv4[c5_i158];
  }

  sf_mex_destroy(&c5_u);
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_K;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_y[6];
  int32_T c5_i159;
  int32_T c5_i160;
  int32_T c5_i161;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_K = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_K), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_K);
  c5_i159 = 0;
  for (c5_i160 = 0; c5_i160 < 2; c5_i160++) {
    for (c5_i161 = 0; c5_i161 < 3; c5_i161++) {
      (*(real_T (*)[6])c5_outData)[c5_i161 + c5_i159] = c5_y[c5_i161 + c5_i159];
    }

    c5_i159 += 3;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo;
  c5_ResolvedFunctionInfo c5_info[29];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i162;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  c5_info_helper(c5_info);
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 29), FALSE);
  for (c5_i162 = 0; c5_i162 < 29; c5_i162++) {
    c5_r0 = &c5_info[c5_i162];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context", "nameCaptureInfo",
                    c5_i162);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name", "nameCaptureInfo", c5_i162);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c5_i162);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved", "nameCaptureInfo",
                    c5_i162);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c5_i162);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c5_i162);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c5_i162);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c5_i162);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0, FALSE);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(c5_ResolvedFunctionInfo c5_info[29])
{
  c5_info[0].context = "";
  c5_info[0].name = "mtimes";
  c5_info[0].dominantType = "double";
  c5_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[0].fileTimeLo = 1289519692U;
  c5_info[0].fileTimeHi = 0U;
  c5_info[0].mFileTimeLo = 0U;
  c5_info[0].mFileTimeHi = 0U;
  c5_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[1].name = "eml_index_class";
  c5_info[1].dominantType = "";
  c5_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c5_info[1].fileTimeLo = 1286818778U;
  c5_info[1].fileTimeHi = 0U;
  c5_info[1].mFileTimeLo = 0U;
  c5_info[1].mFileTimeHi = 0U;
  c5_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[2].name = "eml_scalar_eg";
  c5_info[2].dominantType = "double";
  c5_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c5_info[2].fileTimeLo = 1286818796U;
  c5_info[2].fileTimeHi = 0U;
  c5_info[2].mFileTimeLo = 0U;
  c5_info[2].mFileTimeHi = 0U;
  c5_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c5_info[3].name = "eml_xgemm";
  c5_info[3].dominantType = "int32";
  c5_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c5_info[3].fileTimeLo = 1299076772U;
  c5_info[3].fileTimeHi = 0U;
  c5_info[3].mFileTimeLo = 0U;
  c5_info[3].mFileTimeHi = 0U;
  c5_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c5_info[4].name = "eml_blas_inline";
  c5_info[4].dominantType = "";
  c5_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c5_info[4].fileTimeLo = 1299076768U;
  c5_info[4].fileTimeHi = 0U;
  c5_info[4].mFileTimeLo = 0U;
  c5_info[4].mFileTimeHi = 0U;
  c5_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c5_info[5].name = "eml_refblas_xgemm";
  c5_info[5].dominantType = "int32";
  c5_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c5_info[5].fileTimeLo = 1299076774U;
  c5_info[5].fileTimeHi = 0U;
  c5_info[5].mFileTimeLo = 0U;
  c5_info[5].mFileTimeHi = 0U;
  c5_info[6].context = "";
  c5_info[6].name = "mpower";
  c5_info[6].dominantType = "double";
  c5_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[6].fileTimeLo = 1286818842U;
  c5_info[6].fileTimeHi = 0U;
  c5_info[6].mFileTimeLo = 0U;
  c5_info[6].mFileTimeHi = 0U;
  c5_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c5_info[7].name = "eml_scalar_floor";
  c5_info[7].dominantType = "double";
  c5_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c5_info[7].fileTimeLo = 1286818726U;
  c5_info[7].fileTimeHi = 0U;
  c5_info[7].mFileTimeLo = 0U;
  c5_info[7].mFileTimeHi = 0U;
  c5_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c5_info[8].name = "eml_scalar_abs";
  c5_info[8].dominantType = "double";
  c5_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c5_info[8].fileTimeLo = 1286818712U;
  c5_info[8].fileTimeHi = 0U;
  c5_info[8].mFileTimeLo = 0U;
  c5_info[8].mFileTimeHi = 0U;
  c5_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c5_info[9].name = "inv";
  c5_info[9].dominantType = "double";
  c5_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c5_info[9].fileTimeLo = 1305318000U;
  c5_info[9].fileTimeHi = 0U;
  c5_info[9].mFileTimeLo = 0U;
  c5_info[9].mFileTimeHi = 0U;
  c5_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c5_info[10].name = "eml_xcabs1";
  c5_info[10].dominantType = "double";
  c5_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c5_info[10].fileTimeLo = 1286818706U;
  c5_info[10].fileTimeHi = 0U;
  c5_info[10].mFileTimeLo = 0U;
  c5_info[10].mFileTimeHi = 0U;
  c5_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c5_info[11].name = "abs";
  c5_info[11].dominantType = "double";
  c5_info[11].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c5_info[11].fileTimeLo = 1286818694U;
  c5_info[11].fileTimeHi = 0U;
  c5_info[11].mFileTimeLo = 0U;
  c5_info[11].mFileTimeHi = 0U;
  c5_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c5_info[12].name = "mrdivide";
  c5_info[12].dominantType = "double";
  c5_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[12].fileTimeLo = 1310137456U;
  c5_info[12].fileTimeHi = 0U;
  c5_info[12].mFileTimeLo = 1289519692U;
  c5_info[12].mFileTimeHi = 0U;
  c5_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c5_info[13].name = "rdivide";
  c5_info[13].dominantType = "double";
  c5_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[13].fileTimeLo = 1286818844U;
  c5_info[13].fileTimeHi = 0U;
  c5_info[13].mFileTimeLo = 0U;
  c5_info[13].mFileTimeHi = 0U;
  c5_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c5_info[14].name = "eml_div";
  c5_info[14].dominantType = "double";
  c5_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c5_info[14].fileTimeLo = 1305318000U;
  c5_info[14].fileTimeHi = 0U;
  c5_info[14].mFileTimeLo = 0U;
  c5_info[14].mFileTimeHi = 0U;
  c5_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c5_info[15].name = "norm";
  c5_info[15].dominantType = "double";
  c5_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c5_info[15].fileTimeLo = 1286818826U;
  c5_info[15].fileTimeHi = 0U;
  c5_info[15].mFileTimeLo = 0U;
  c5_info[15].mFileTimeHi = 0U;
  c5_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c5_info[16].name = "isnan";
  c5_info[16].dominantType = "double";
  c5_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c5_info[16].fileTimeLo = 1286818760U;
  c5_info[16].fileTimeHi = 0U;
  c5_info[16].mFileTimeLo = 0U;
  c5_info[16].mFileTimeHi = 0U;
  c5_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c5_info[17].name = "eml_guarded_nan";
  c5_info[17].dominantType = "char";
  c5_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c5_info[17].fileTimeLo = 1286818776U;
  c5_info[17].fileTimeHi = 0U;
  c5_info[17].mFileTimeLo = 0U;
  c5_info[17].mFileTimeHi = 0U;
  c5_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c5_info[18].name = "eml_is_float_class";
  c5_info[18].dominantType = "char";
  c5_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c5_info[18].fileTimeLo = 1286818782U;
  c5_info[18].fileTimeHi = 0U;
  c5_info[18].mFileTimeLo = 0U;
  c5_info[18].mFileTimeHi = 0U;
  c5_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c5_info[19].name = "eml_warning";
  c5_info[19].dominantType = "char";
  c5_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c5_info[19].fileTimeLo = 1286818802U;
  c5_info[19].fileTimeHi = 0U;
  c5_info[19].mFileTimeLo = 0U;
  c5_info[19].mFileTimeHi = 0U;
  c5_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c5_info[20].name = "eps";
  c5_info[20].dominantType = "char";
  c5_info[20].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c5_info[20].fileTimeLo = 1286818686U;
  c5_info[20].fileTimeHi = 0U;
  c5_info[20].mFileTimeLo = 0U;
  c5_info[20].mFileTimeHi = 0U;
  c5_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c5_info[21].name = "eml_flt2str";
  c5_info[21].dominantType = "double";
  c5_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c5_info[21].fileTimeLo = 1286818776U;
  c5_info[21].fileTimeHi = 0U;
  c5_info[21].mFileTimeLo = 0U;
  c5_info[21].mFileTimeHi = 0U;
  c5_info[22].context = "";
  c5_info[22].name = "eye";
  c5_info[22].dominantType = "double";
  c5_info[22].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c5_info[22].fileTimeLo = 1286818688U;
  c5_info[22].fileTimeHi = 0U;
  c5_info[22].mFileTimeLo = 0U;
  c5_info[22].mFileTimeHi = 0U;
  c5_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c5_info[23].name = "eml_assert_valid_size_arg";
  c5_info[23].dominantType = "double";
  c5_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[23].fileTimeLo = 1286818694U;
  c5_info[23].fileTimeHi = 0U;
  c5_info[23].mFileTimeLo = 0U;
  c5_info[23].mFileTimeHi = 0U;
  c5_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c5_info[24].name = "isinf";
  c5_info[24].dominantType = "double";
  c5_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c5_info[24].fileTimeLo = 1286818760U;
  c5_info[24].fileTimeHi = 0U;
  c5_info[24].mFileTimeLo = 0U;
  c5_info[24].mFileTimeHi = 0U;
  c5_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c5_info[25].name = "intmax";
  c5_info[25].dominantType = "char";
  c5_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c5_info[25].fileTimeLo = 1286818756U;
  c5_info[25].fileTimeHi = 0U;
  c5_info[25].mFileTimeLo = 0U;
  c5_info[25].mFileTimeHi = 0U;
  c5_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c5_info[26].name = "min";
  c5_info[26].dominantType = "double";
  c5_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[26].fileTimeLo = 1308747330U;
  c5_info[26].fileTimeHi = 0U;
  c5_info[26].mFileTimeLo = 0U;
  c5_info[26].mFileTimeHi = 0U;
  c5_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c5_info[27].name = "eml_min_or_max";
  c5_info[27].dominantType = "char";
  c5_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c5_info[27].fileTimeLo = 1303146212U;
  c5_info[27].fileTimeHi = 0U;
  c5_info[27].mFileTimeLo = 0U;
  c5_info[27].mFileTimeHi = 0U;
  c5_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c5_info[28].name = "eml_scalexp_alloc";
  c5_info[28].dominantType = "double";
  c5_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c5_info[28].fileTimeLo = 1286818796U;
  c5_info[28].fileTimeHi = 0U;
  c5_info[28].mFileTimeLo = 0U;
  c5_info[28].mFileTimeHi = 0U;
}

static void c5_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c5_b_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c5_c_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c5_d_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c5_e_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c5_mpower(SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                      real_T c5_a[4], real_T c5_c[4])
{
  int32_T c5_i163;
  real_T c5_b_a[4];
  for (c5_i163 = 0; c5_i163 < 4; c5_i163++) {
    c5_b_a[c5_i163] = c5_a[c5_i163];
  }

  c5_matrix_to_integer_power(chartInstance, c5_b_a, -1.0, c5_c);
}

static void c5_matrix_to_integer_power(SFc5_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, real_T c5_a[4], real_T c5_b, real_T c5_c[4])
{
  real_T c5_x;
  real_T c5_e;
  boolean_T c5_firstmult;
  real_T c5_b_x;
  real_T c5_ed2;
  real_T c5_b_b;
  real_T c5_y;
  int32_T c5_i164;
  int32_T c5_i165;
  real_T c5_A[4];
  int32_T c5_i166;
  int32_T c5_i167;
  int32_T c5_i168;
  int32_T c5_i169;
  int32_T c5_i170;
  int32_T c5_i171;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_e_x;
  real_T c5_b_y;
  real_T c5_f_x;
  real_T c5_g_x;
  real_T c5_c_y;
  real_T c5_d;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_j_x;
  real_T c5_d_y;
  real_T c5_k_x;
  real_T c5_l_x;
  real_T c5_e_y;
  real_T c5_b_d;
  real_T c5_b_A;
  real_T c5_B;
  real_T c5_m_x;
  real_T c5_f_y;
  real_T c5_n_x;
  real_T c5_g_y;
  real_T c5_r;
  real_T c5_b_a;
  real_T c5_c_b;
  real_T c5_h_y;
  real_T c5_b_B;
  real_T c5_i_y;
  real_T c5_j_y;
  real_T c5_t;
  real_T c5_c_A;
  real_T c5_c_B;
  real_T c5_o_x;
  real_T c5_k_y;
  real_T c5_p_x;
  real_T c5_l_y;
  real_T c5_m_y;
  real_T c5_c_a;
  real_T c5_d_b;
  real_T c5_n_y;
  real_T c5_d_A;
  real_T c5_d_B;
  real_T c5_q_x;
  real_T c5_o_y;
  real_T c5_r_x;
  real_T c5_p_y;
  real_T c5_q_y;
  real_T c5_d_a;
  real_T c5_e_b;
  real_T c5_r_y;
  real_T c5_e_a;
  real_T c5_f_b;
  real_T c5_s_y;
  real_T c5_e_A;
  real_T c5_e_B;
  real_T c5_s_x;
  real_T c5_t_y;
  real_T c5_t_x;
  real_T c5_u_y;
  real_T c5_f_a;
  real_T c5_g_b;
  real_T c5_v_y;
  real_T c5_f_B;
  real_T c5_w_y;
  real_T c5_x_y;
  real_T c5_f_A;
  real_T c5_g_B;
  real_T c5_u_x;
  real_T c5_y_y;
  real_T c5_v_x;
  real_T c5_ab_y;
  real_T c5_bb_y;
  real_T c5_g_a;
  real_T c5_h_b;
  real_T c5_cb_y;
  real_T c5_h_a;
  real_T c5_i_b;
  real_T c5_db_y;
  real_T c5_g_A;
  real_T c5_h_B;
  real_T c5_w_x;
  real_T c5_eb_y;
  real_T c5_x_x;
  real_T c5_fb_y;
  real_T c5_gb_y;
  real_T c5_i_a;
  real_T c5_j_b;
  real_T c5_hb_y;
  int32_T c5_i172;
  real_T c5_h_A[4];
  real_T c5_n1x;
  int32_T c5_i173;
  real_T c5_b_c[4];
  real_T c5_n1xinv;
  real_T c5_j_a;
  real_T c5_k_b;
  real_T c5_ib_y;
  real_T c5_rc;
  real_T c5_y_x;
  boolean_T c5_l_b;
  real_T c5_ab_x;
  int32_T c5_i174;
  static char_T c5_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c5_u[8];
  const mxArray *c5_jb_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_kb_y = NULL;
  real_T c5_c_u;
  const mxArray *c5_lb_y = NULL;
  real_T c5_d_u;
  const mxArray *c5_mb_y = NULL;
  char_T c5_str[14];
  int32_T c5_i175;
  char_T c5_b_str[14];
  int32_T c5_i176;
  int32_T c5_i177;
  int32_T c5_i178;
  int32_T c5_i179;
  int32_T c5_i180;
  int32_T c5_i181;
  int32_T c5_i182;
  int32_T c5_k;
  int32_T c5_b_k;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  int32_T exitg1;
  c5_f_eml_scalar_eg(chartInstance);
  c5_x = c5_b;
  c5_e = muDoubleScalarAbs(c5_x);
  if (c5_e > 0.0) {
    c5_firstmult = TRUE;
    do {
      exitg1 = 0U;
      c5_b_x = c5_e / 2.0;
      c5_ed2 = c5_b_x;
      c5_ed2 = muDoubleScalarFloor(c5_ed2);
      c5_b_b = c5_ed2;
      c5_y = 2.0 * c5_b_b;
      if (c5_y != c5_e) {
        if (c5_firstmult) {
          for (c5_i164 = 0; c5_i164 < 4; c5_i164++) {
            c5_c[c5_i164] = c5_a[c5_i164];
          }

          c5_firstmult = FALSE;
        } else {
          c5_g_eml_scalar_eg(chartInstance);
          c5_g_eml_scalar_eg(chartInstance);
          for (c5_i165 = 0; c5_i165 < 4; c5_i165++) {
            c5_A[c5_i165] = c5_c[c5_i165];
          }

          for (c5_i166 = 0; c5_i166 < 2; c5_i166++) {
            c5_i167 = 0;
            for (c5_i168 = 0; c5_i168 < 2; c5_i168++) {
              c5_c[c5_i167 + c5_i166] = 0.0;
              c5_i169 = 0;
              for (c5_i170 = 0; c5_i170 < 2; c5_i170++) {
                c5_c[c5_i167 + c5_i166] += c5_A[c5_i169 + c5_i166] *
                  c5_a[c5_i170 + c5_i167];
                c5_i169 += 2;
              }

              c5_i167 += 2;
            }
          }
        }
      }

      if (c5_ed2 == 0.0) {
        exitg1 = 1U;
      } else {
        c5_e = c5_ed2;
        c5_g_eml_scalar_eg(chartInstance);
        c5_g_eml_scalar_eg(chartInstance);
        for (c5_i176 = 0; c5_i176 < 4; c5_i176++) {
          c5_A[c5_i176] = c5_a[c5_i176];
        }

        for (c5_i177 = 0; c5_i177 < 2; c5_i177++) {
          c5_i178 = 0;
          for (c5_i179 = 0; c5_i179 < 2; c5_i179++) {
            c5_a[c5_i178 + c5_i177] = 0.0;
            c5_i180 = 0;
            for (c5_i181 = 0; c5_i181 < 2; c5_i181++) {
              c5_a[c5_i178 + c5_i177] += c5_A[c5_i180 + c5_i177] * c5_A[c5_i181
                + c5_i178];
              c5_i180 += 2;
            }

            c5_i178 += 2;
          }
        }
      }
    } while (exitg1 == 0U);

    if (c5_b < 0.0) {
      for (c5_i171 = 0; c5_i171 < 4; c5_i171++) {
        c5_A[c5_i171] = c5_c[c5_i171];
      }

      c5_c_x = c5_A[1];
      c5_d_x = c5_c_x;
      c5_e_x = c5_d_x;
      c5_b_y = muDoubleScalarAbs(c5_e_x);
      c5_f_x = 0.0;
      c5_g_x = c5_f_x;
      c5_c_y = muDoubleScalarAbs(c5_g_x);
      c5_d = c5_b_y + c5_c_y;
      c5_h_x = c5_A[0];
      c5_i_x = c5_h_x;
      c5_j_x = c5_i_x;
      c5_d_y = muDoubleScalarAbs(c5_j_x);
      c5_k_x = 0.0;
      c5_l_x = c5_k_x;
      c5_e_y = muDoubleScalarAbs(c5_l_x);
      c5_b_d = c5_d_y + c5_e_y;
      if (c5_d > c5_b_d) {
        c5_b_A = c5_A[0];
        c5_B = c5_A[1];
        c5_m_x = c5_b_A;
        c5_f_y = c5_B;
        c5_n_x = c5_m_x;
        c5_g_y = c5_f_y;
        c5_r = c5_n_x / c5_g_y;
        c5_b_a = c5_r;
        c5_c_b = c5_A[3];
        c5_h_y = c5_b_a * c5_c_b;
        c5_b_B = c5_h_y - c5_A[2];
        c5_i_y = c5_b_B;
        c5_j_y = c5_i_y;
        c5_t = 1.0 / c5_j_y;
        c5_c_A = c5_A[3];
        c5_c_B = c5_A[1];
        c5_o_x = c5_c_A;
        c5_k_y = c5_c_B;
        c5_p_x = c5_o_x;
        c5_l_y = c5_k_y;
        c5_m_y = c5_p_x / c5_l_y;
        c5_c_a = c5_m_y;
        c5_d_b = c5_t;
        c5_n_y = c5_c_a * c5_d_b;
        c5_c[0] = c5_n_y;
        c5_c[1] = -c5_t;
        c5_d_A = -c5_A[2];
        c5_d_B = c5_A[1];
        c5_q_x = c5_d_A;
        c5_o_y = c5_d_B;
        c5_r_x = c5_q_x;
        c5_p_y = c5_o_y;
        c5_q_y = c5_r_x / c5_p_y;
        c5_d_a = c5_q_y;
        c5_e_b = c5_t;
        c5_r_y = c5_d_a * c5_e_b;
        c5_c[2] = c5_r_y;
        c5_e_a = c5_r;
        c5_f_b = c5_t;
        c5_s_y = c5_e_a * c5_f_b;
        c5_c[3] = c5_s_y;
      } else {
        c5_e_A = c5_A[1];
        c5_e_B = c5_A[0];
        c5_s_x = c5_e_A;
        c5_t_y = c5_e_B;
        c5_t_x = c5_s_x;
        c5_u_y = c5_t_y;
        c5_r = c5_t_x / c5_u_y;
        c5_f_a = c5_r;
        c5_g_b = c5_A[2];
        c5_v_y = c5_f_a * c5_g_b;
        c5_f_B = c5_A[3] - c5_v_y;
        c5_w_y = c5_f_B;
        c5_x_y = c5_w_y;
        c5_t = 1.0 / c5_x_y;
        c5_f_A = c5_A[3];
        c5_g_B = c5_A[0];
        c5_u_x = c5_f_A;
        c5_y_y = c5_g_B;
        c5_v_x = c5_u_x;
        c5_ab_y = c5_y_y;
        c5_bb_y = c5_v_x / c5_ab_y;
        c5_g_a = c5_bb_y;
        c5_h_b = c5_t;
        c5_cb_y = c5_g_a * c5_h_b;
        c5_c[0] = c5_cb_y;
        c5_h_a = -c5_r;
        c5_i_b = c5_t;
        c5_db_y = c5_h_a * c5_i_b;
        c5_c[1] = c5_db_y;
        c5_g_A = -c5_A[2];
        c5_h_B = c5_A[0];
        c5_w_x = c5_g_A;
        c5_eb_y = c5_h_B;
        c5_x_x = c5_w_x;
        c5_fb_y = c5_eb_y;
        c5_gb_y = c5_x_x / c5_fb_y;
        c5_i_a = c5_gb_y;
        c5_j_b = c5_t;
        c5_hb_y = c5_i_a * c5_j_b;
        c5_c[2] = c5_hb_y;
        c5_c[3] = c5_t;
      }

      for (c5_i172 = 0; c5_i172 < 4; c5_i172++) {
        c5_h_A[c5_i172] = c5_A[c5_i172];
      }

      c5_n1x = c5_norm(chartInstance, c5_h_A);
      for (c5_i173 = 0; c5_i173 < 4; c5_i173++) {
        c5_b_c[c5_i173] = c5_c[c5_i173];
      }

      c5_n1xinv = c5_norm(chartInstance, c5_b_c);
      c5_j_a = c5_n1x;
      c5_k_b = c5_n1xinv;
      c5_ib_y = c5_j_a * c5_k_b;
      c5_rc = 1.0 / c5_ib_y;
      guard1 = FALSE;
      guard2 = FALSE;
      if (c5_n1x == 0.0) {
        guard2 = TRUE;
      } else if (c5_n1xinv == 0.0) {
        guard2 = TRUE;
      } else if (c5_rc == 0.0) {
        guard1 = TRUE;
      } else {
        c5_y_x = c5_rc;
        c5_l_b = muDoubleScalarIsNaN(c5_y_x);
        guard3 = FALSE;
        if (c5_l_b) {
          guard3 = TRUE;
        } else {
          if (c5_rc < 2.2204460492503131E-16) {
            guard3 = TRUE;
          }
        }

        if (guard3 == TRUE) {
          c5_ab_x = c5_rc;
          for (c5_i174 = 0; c5_i174 < 8; c5_i174++) {
            c5_u[c5_i174] = c5_cv0[c5_i174];
          }

          c5_jb_y = NULL;
          sf_mex_assign(&c5_jb_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1,
            8), FALSE);
          c5_b_u = 14.0;
          c5_kb_y = NULL;
          sf_mex_assign(&c5_kb_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c5_c_u = 6.0;
          c5_lb_y = NULL;
          sf_mex_assign(&c5_lb_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c5_d_u = c5_ab_x;
          c5_mb_y = NULL;
          sf_mex_assign(&c5_mb_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c5_g_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U,
            2U, 14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c5_jb_y, 14,
            c5_kb_y, 14, c5_lb_y), 14, c5_mb_y), "sprintf", c5_str);
          for (c5_i175 = 0; c5_i175 < 14; c5_i175++) {
            c5_b_str[c5_i175] = c5_str[c5_i175];
          }

          c5_b_eml_warning(chartInstance, c5_b_str);
        }
      }

      if (guard2 == TRUE) {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        c5_eml_warning(chartInstance);
      }
    }
  } else {
    for (c5_i182 = 0; c5_i182 < 4; c5_i182++) {
      c5_c[c5_i182] = 0.0;
    }

    for (c5_k = 1; c5_k < 3; c5_k++) {
      c5_b_k = c5_k;
      c5_c[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c5_b_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c5_b_k), 1, 2, 2, 0) - 1)
             << 1)) - 1] = 1.0;
    }
  }
}

static void c5_f_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c5_g_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static real_T c5_norm(SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                      real_T c5_x[4])
{
  real_T c5_y;
  int32_T c5_j;
  real_T c5_b_j;
  real_T c5_s;
  int32_T c5_i;
  real_T c5_b_i;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_b_y;
  real_T c5_d_x;
  boolean_T c5_b;
  boolean_T exitg1;
  c5_y = 0.0;
  c5_j = 0;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (c5_j < 2)) {
    c5_b_j = 1.0 + (real_T)c5_j;
    c5_s = 0.0;
    for (c5_i = 0; c5_i < 2; c5_i++) {
      c5_b_i = 1.0 + (real_T)c5_i;
      c5_b_x = c5_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c5_b_i), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", c5_b_j), 1, 2, 2, 0) - 1) << 1)) - 1];
      c5_c_x = c5_b_x;
      c5_b_y = muDoubleScalarAbs(c5_c_x);
      c5_s += c5_b_y;
    }

    c5_d_x = c5_s;
    c5_b = muDoubleScalarIsNaN(c5_d_x);
    if (c5_b) {
      c5_y = rtNaN;
      exitg1 = 1U;
    } else {
      if (c5_s > c5_y) {
        c5_y = c5_s;
      }

      c5_j++;
    }
  }

  return c5_y;
}

static void c5_eml_warning(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
  int32_T c5_i183;
  static char_T c5_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c5_u[27];
  const mxArray *c5_y = NULL;
  for (c5_i183 = 0; c5_i183 < 27; c5_i183++) {
    c5_u[c5_i183] = c5_varargin_1[c5_i183];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c5_y));
}

static void c5_b_eml_warning(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, char_T c5_varargin_2[14])
{
  int32_T c5_i184;
  static char_T c5_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c5_u[33];
  const mxArray *c5_y = NULL;
  int32_T c5_i185;
  char_T c5_b_u[14];
  const mxArray *c5_b_y = NULL;
  for (c5_i184 = 0; c5_i184 < 33; c5_i184++) {
    c5_u[c5_i184] = c5_varargin_1[c5_i184];
  }

  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", c5_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c5_i185 = 0; c5_i185 < 14; c5_i185++) {
    c5_b_u[c5_i185] = c5_varargin_2[c5_i185];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c5_y, 14, c5_b_y));
}

static void c5_h_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c5_i_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c5_j_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c5_eye(SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                   real_T c5_I[9])
{
  int32_T c5_i186;
  int32_T c5_i;
  int32_T c5_b_i;
  for (c5_i186 = 0; c5_i186 < 9; c5_i186++) {
    c5_I[c5_i186] = 0.0;
  }

  for (c5_i = 1; c5_i < 4; c5_i++) {
    c5_b_i = c5_i;
    c5_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c5_b_i), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
            (int32_T)_SFD_INTEGER_CHECK("", (real_T)c5_b_i), 1, 3, 2, 0) - 1)) -
      1] = 1.0;
  }
}

static void c5_k_eml_scalar_eg(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c5_g_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_sprintf, const char_T *c5_identifier, char_T
  c5_y[14])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_sprintf), &c5_thisId, c5_y);
  sf_mex_destroy(&c5_sprintf);
}

static void c5_h_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId,
  char_T c5_y[14])
{
  char_T c5_cv1[14];
  int32_T c5_i187;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), c5_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c5_i187 = 0; c5_i187 < 14; c5_i187++) {
    c5_y[c5_i187] = c5_cv1[c5_i187];
  }

  sf_mex_destroy(&c5_u);
}

static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_u;
  const mxArray *c5_y = NULL;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_u = *(int32_T *)c5_inData;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c5_mxArrayOutData, c5_y, FALSE);
  return c5_mxArrayOutData;
}

static int32_T c5_i_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_y;
  int32_T c5_i188;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_i188, 1, 6, 0U, 0, 0U, 0);
  c5_y = c5_i188;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_y;
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static uint8_T c5_j_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_Hquad_control_LIB_MPC, const
  char_T *c5_identifier)
{
  uint8_T c5_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y = c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_Hquad_control_LIB_MPC), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_Hquad_control_LIB_MPC);
  return c5_y;
}

static uint8_T c5_k_emlrt_marshallIn(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c5_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_u);
  return c5_y;
}

static void init_dsm_address_info(SFc5_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c5_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2189853427U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2730128856U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1447956719U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1158677693U);
}

mxArray *sf_c5_Hquad_control_LIB_MPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("moLetQsTYcT2odqt4LCxPB");
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

static const mxArray *sf_get_sim_state_info_c5_Hquad_control_LIB_MPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[29],T\"P_est\",},{M[1],M[5],T\"state_est\",},{M[8],M[0],T\"is_active_c5_Hquad_control_LIB_MPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_Hquad_control_LIB_MPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
    chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Hquad_control_LIB_MPCMachineNumber_,
           5,
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
            (_Hquad_control_LIB_MPCMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_Hquad_control_LIB_MPCMachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0);
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
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)
            c5_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          real_T *c5_u;
          real_T (*c5_A)[9];
          real_T (*c5_B)[3];
          real_T (*c5_state_est)[3];
          real_T (*c5_C)[6];
          real_T (*c5_D)[2];
          real_T (*c5_Q)[9];
          real_T (*c5_R)[4];
          real_T (*c5_y)[2];
          real_T (*c5_P)[9];
          real_T (*c5_state)[3];
          real_T (*c5_P_est)[9];
          c5_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c5_state = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
          c5_P = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 8);
          c5_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 7);
          c5_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c5_R = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
          c5_Q = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
          c5_D = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 3);
          c5_C = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
          c5_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            1);
          c5_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c5_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c5_A);
          _SFD_SET_DATA_VALUE_PTR(1U, *c5_B);
          _SFD_SET_DATA_VALUE_PTR(2U, *c5_state_est);
          _SFD_SET_DATA_VALUE_PTR(3U, *c5_C);
          _SFD_SET_DATA_VALUE_PTR(4U, *c5_D);
          _SFD_SET_DATA_VALUE_PTR(5U, *c5_Q);
          _SFD_SET_DATA_VALUE_PTR(6U, *c5_R);
          _SFD_SET_DATA_VALUE_PTR(7U, c5_u);
          _SFD_SET_DATA_VALUE_PTR(8U, *c5_y);
          _SFD_SET_DATA_VALUE_PTR(9U, *c5_P);
          _SFD_SET_DATA_VALUE_PTR(10U, *c5_state);
          _SFD_SET_DATA_VALUE_PTR(11U, *c5_P_est);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Hquad_control_LIB_MPCMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c5_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c5_Hquad_control_LIB_MPC
    ((SFc5_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
  initialize_c5_Hquad_control_LIB_MPC((SFc5_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c5_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  enable_c5_Hquad_control_LIB_MPC((SFc5_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c5_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  disable_c5_Hquad_control_LIB_MPC((SFc5_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c5_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_c5_Hquad_control_LIB_MPC((SFc5_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c5_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c5_Hquad_control_LIB_MPC
    ((SFc5_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_Hquad_control_LIB_MPC();/* state var info */
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

extern void sf_internal_set_sim_state_c5_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c5_Hquad_control_LIB_MPC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c5_Hquad_control_LIB_MPC
    ((SFc5_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c5_Hquad_control_LIB_MPC(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c5_Hquad_control_LIB_MPC(S);
}

static void sf_opaque_set_sim_state_c5_Hquad_control_LIB_MPC(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c5_Hquad_control_LIB_MPC(S, st);
}

static void sf_opaque_terminate_c5_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c5_Hquad_control_LIB_MPC((SFc5_Hquad_control_LIB_MPCInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Hquad_control_LIB_MPC_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_Hquad_control_LIB_MPC
    ((SFc5_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_Hquad_control_LIB_MPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_Hquad_control_LIB_MPC
      ((SFc5_Hquad_control_LIB_MPCInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,5,
      "gatewayCannotBeInlinedMultipleTimes"));
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
      sf_mark_chart_expressionable_inputs(S,infoStruct,5,10);
      sf_mark_chart_reusable_outputs(S,infoStruct,5,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(237375345U));
  ssSetChecksum1(S,(3739561383U));
  ssSetChecksum2(S,(1666305668U));
  ssSetChecksum3(S,(385915697U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_Hquad_control_LIB_MPC(SimStruct *S)
{
  SFc5_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc5_Hquad_control_LIB_MPCInstanceStruct *)malloc(sizeof
    (SFc5_Hquad_control_LIB_MPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_Hquad_control_LIB_MPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c5_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c5_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c5_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c5_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_Hquad_control_LIB_MPC;
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

void c5_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_Hquad_control_LIB_MPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_Hquad_control_LIB_MPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
