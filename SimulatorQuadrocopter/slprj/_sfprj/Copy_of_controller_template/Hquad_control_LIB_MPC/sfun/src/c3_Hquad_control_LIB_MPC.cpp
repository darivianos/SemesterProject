/* Include files */

#include "blascompat32.h"
#include "Hquad_control_LIB_MPC_sfun.h"
#include "c3_Hquad_control_LIB_MPC.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hquad_control_LIB_MPC_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[18] = { "n", "x_", "P_", "K", "nargin",
  "nargout", "A", "B", "C", "D", "Q", "R", "u", "y", "P", "state", "state_est",
  "P_est" };

/* Function Declarations */
static void initialize_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initialize_params_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void enable_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void disable_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void ext_mode_exec_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void set_sim_state_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray *c3_st);
static void finalize_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void sf_c3_Hquad_control_LIB_MPC(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_chartstep_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initSimStructsc3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_P_est, const char_T *c3_identifier, real_T
  c3_y[16]);
static void c3_b_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[16]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_state_est, const char_T *c3_identifier,
  real_T c3_y[4]);
static void c3_d_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_e_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_f_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[12]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[27]);
static void c3_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_b_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_c_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_d_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_e_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_mpower(SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                      real_T c3_a[9], real_T c3_c[9]);
static void c3_matrix_to_integer_power(SFc3_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, real_T c3_a[9], real_T c3_b, real_T c3_c[9]);
static void c3_f_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_g_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_inv3x3(SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                      real_T c3_x[9], real_T c3_y[9]);
static real_T c3_norm(SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                      real_T c3_x[9]);
static void c3_eml_warning(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_b_eml_warning(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, char_T c3_varargin_2[14]);
static void c3_h_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_i_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_j_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_eye(SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                   real_T c3_I[16]);
static void c3_k_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c3_g_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y[14]);
static void c3_h_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[14]);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_i_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_j_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_is_active_c3_Hquad_control_LIB_MPC, const
  char_T *c3_identifier);
static uint8_T c3_k_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T *c3_sfEvent;
  uint8_T *c3_is_active_c3_Hquad_control_LIB_MPC;
  c3_is_active_c3_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c3_is_active_c3_Hquad_control_LIB_MPC = 0U;
}

static void initialize_params_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void enable_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  c3_update_debugger_state_c3_Hquad_control_LIB_MPC(chartInstance);
}

static const mxArray *get_sim_state_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[16];
  const mxArray *c3_b_y = NULL;
  int32_T c3_i1;
  real_T c3_b_u[4];
  const mxArray *c3_c_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint8_T *c3_is_active_c3_Hquad_control_LIB_MPC;
  real_T (*c3_state_est)[4];
  real_T (*c3_P_est)[16];
  c3_P_est = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_state_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(3), FALSE);
  for (c3_i0 = 0; c3_i0 < 16; c3_i0++) {
    c3_u[c3_i0] = (*c3_P_est)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  for (c3_i1 = 0; c3_i1 < 4; c3_i1++) {
    c3_b_u[c3_i1] = (*c3_state_est)[c3_i1];
  }

  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_hoistedGlobal = *c3_is_active_c3_Hquad_control_LIB_MPC;
  c3_c_u = c3_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[16];
  int32_T c3_i2;
  real_T c3_dv1[4];
  int32_T c3_i3;
  boolean_T *c3_doneDoubleBufferReInit;
  uint8_T *c3_is_active_c3_Hquad_control_LIB_MPC;
  real_T (*c3_P_est)[16];
  real_T (*c3_state_est)[4];
  c3_P_est = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_state_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_is_active_c3_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c3_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                      "P_est", c3_dv0);
  for (c3_i2 = 0; c3_i2 < 16; c3_i2++) {
    (*c3_P_est)[c3_i2] = c3_dv0[c3_i2];
  }

  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
                        "state_est", c3_dv1);
  for (c3_i3 = 0; c3_i3 < 4; c3_i3++) {
    (*c3_state_est)[c3_i3] = c3_dv1[c3_i3];
  }

  *c3_is_active_c3_Hquad_control_LIB_MPC = c3_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 2)), "is_active_c3_Hquad_control_LIB_MPC");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_Hquad_control_LIB_MPC(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void sf_c3_Hquad_control_LIB_MPC(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
  int32_T c3_i4;
  int32_T c3_i5;
  int32_T c3_i6;
  int32_T c3_i7;
  int32_T c3_i8;
  int32_T c3_i9;
  int32_T c3_i10;
  int32_T c3_i11;
  int32_T c3_i12;
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T *c3_sfEvent;
  real_T *c3_u;
  real_T (*c3_P_est)[16];
  real_T (*c3_state)[4];
  real_T (*c3_P)[16];
  real_T (*c3_y)[3];
  real_T (*c3_R)[9];
  real_T (*c3_Q)[16];
  real_T (*c3_D)[3];
  real_T (*c3_C)[12];
  real_T (*c3_state_est)[4];
  real_T (*c3_B)[4];
  real_T (*c3_A)[16];
  c3_P_est = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_state = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 9);
  c3_P = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 8);
  c3_y = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 7);
  c3_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
  c3_Q = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 4);
  c3_D = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c3_C = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 2);
  c3_state_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_B = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c3_A = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c3_sfEvent);
  for (c3_i4 = 0; c3_i4 < 16; c3_i4++) {
    _SFD_DATA_RANGE_CHECK((*c3_A)[c3_i4], 0U);
  }

  for (c3_i5 = 0; c3_i5 < 4; c3_i5++) {
    _SFD_DATA_RANGE_CHECK((*c3_B)[c3_i5], 1U);
  }

  for (c3_i6 = 0; c3_i6 < 4; c3_i6++) {
    _SFD_DATA_RANGE_CHECK((*c3_state_est)[c3_i6], 2U);
  }

  for (c3_i7 = 0; c3_i7 < 12; c3_i7++) {
    _SFD_DATA_RANGE_CHECK((*c3_C)[c3_i7], 3U);
  }

  for (c3_i8 = 0; c3_i8 < 3; c3_i8++) {
    _SFD_DATA_RANGE_CHECK((*c3_D)[c3_i8], 4U);
  }

  for (c3_i9 = 0; c3_i9 < 16; c3_i9++) {
    _SFD_DATA_RANGE_CHECK((*c3_Q)[c3_i9], 5U);
  }

  for (c3_i10 = 0; c3_i10 < 9; c3_i10++) {
    _SFD_DATA_RANGE_CHECK((*c3_R)[c3_i10], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_u, 7U);
  for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
    _SFD_DATA_RANGE_CHECK((*c3_y)[c3_i11], 8U);
  }

  for (c3_i12 = 0; c3_i12 < 16; c3_i12++) {
    _SFD_DATA_RANGE_CHECK((*c3_P)[c3_i12], 9U);
  }

  for (c3_i13 = 0; c3_i13 < 4; c3_i13++) {
    _SFD_DATA_RANGE_CHECK((*c3_state)[c3_i13], 10U);
  }

  for (c3_i14 = 0; c3_i14 < 16; c3_i14++) {
    _SFD_DATA_RANGE_CHECK((*c3_P_est)[c3_i14], 11U);
  }

  *c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_Hquad_control_LIB_MPC(chartInstance);
  sf_debug_check_for_state_inconsistency(_Hquad_control_LIB_MPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  int32_T c3_i15;
  real_T c3_A[16];
  int32_T c3_i16;
  real_T c3_B[4];
  int32_T c3_i17;
  real_T c3_C[12];
  int32_T c3_i18;
  real_T c3_D[3];
  int32_T c3_i19;
  real_T c3_Q[16];
  int32_T c3_i20;
  real_T c3_R[9];
  real_T c3_u;
  int32_T c3_i21;
  real_T c3_y[3];
  int32_T c3_i22;
  real_T c3_P[16];
  int32_T c3_i23;
  real_T c3_state[4];
  uint32_T c3_debug_family_var_map[18];
  real_T c3_n;
  real_T c3_x_[4];
  real_T c3_P_[16];
  real_T c3_K[12];
  real_T c3_nargin = 10.0;
  real_T c3_nargout = 2.0;
  real_T c3_state_est[4];
  real_T c3_P_est[16];
  int32_T c3_i24;
  real_T c3_a[16];
  int32_T c3_i25;
  real_T c3_b[4];
  int32_T c3_i26;
  real_T c3_b_y[4];
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  real_T c3_b_b;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  real_T c3_c_b[16];
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  real_T c3_c_y[16];
  int32_T c3_i37;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i40;
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  real_T c3_d_y[16];
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  real_T c3_d_b[12];
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  real_T c3_e_y[12];
  int32_T c3_i57;
  int32_T c3_i58;
  int32_T c3_i59;
  real_T c3_b_a[12];
  int32_T c3_i60;
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  int32_T c3_i64;
  real_T c3_f_y[12];
  int32_T c3_i65;
  int32_T c3_i66;
  int32_T c3_i67;
  int32_T c3_i68;
  int32_T c3_i69;
  int32_T c3_i70;
  int32_T c3_i71;
  int32_T c3_i72;
  int32_T c3_i73;
  int32_T c3_i74;
  real_T c3_g_y[9];
  int32_T c3_i75;
  int32_T c3_i76;
  int32_T c3_i77;
  real_T c3_h_y[9];
  int32_T c3_i78;
  int32_T c3_i79;
  int32_T c3_i80;
  int32_T c3_i81;
  int32_T c3_i82;
  int32_T c3_i83;
  int32_T c3_i84;
  int32_T c3_i85;
  int32_T c3_i86;
  int32_T c3_i87;
  int32_T c3_i88;
  int32_T c3_i89;
  int32_T c3_i90;
  int32_T c3_i91;
  int32_T c3_i92;
  real_T c3_i_y[3];
  int32_T c3_i93;
  int32_T c3_i94;
  int32_T c3_i95;
  int32_T c3_i96;
  int32_T c3_i97;
  int32_T c3_i98;
  int32_T c3_i99;
  int32_T c3_i100;
  int32_T c3_i101;
  int32_T c3_i102;
  int32_T c3_i103;
  int32_T c3_i104;
  int32_T c3_i105;
  int32_T c3_i106;
  int32_T c3_i107;
  int32_T c3_i108;
  int32_T c3_i109;
  int32_T c3_i110;
  int32_T c3_i111;
  int32_T c3_i112;
  int32_T c3_i113;
  int32_T c3_i114;
  int32_T c3_i115;
  int32_T c3_i116;
  int32_T c3_i117;
  int32_T c3_i118;
  int32_T c3_i119;
  int32_T c3_i120;
  int32_T c3_i121;
  int32_T c3_i122;
  int32_T c3_i123;
  real_T *c3_b_u;
  real_T (*c3_b_state_est)[4];
  real_T (*c3_b_P_est)[16];
  real_T (*c3_b_state)[4];
  real_T (*c3_b_P)[16];
  real_T (*c3_j_y)[3];
  real_T (*c3_b_R)[9];
  real_T (*c3_b_Q)[16];
  real_T (*c3_b_D)[3];
  real_T (*c3_b_C)[12];
  real_T (*c3_b_B)[4];
  real_T (*c3_b_A)[16];
  int32_T *c3_sfEvent;
  c3_b_P_est = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_state = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 9);
  c3_b_P = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 8);
  c3_j_y = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 7);
  c3_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c3_b_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_Q = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_D = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_C = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_state_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_B = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_A = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  c3_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c3_sfEvent);
  c3_hoistedGlobal = *c3_b_u;
  for (c3_i15 = 0; c3_i15 < 16; c3_i15++) {
    c3_A[c3_i15] = (*c3_b_A)[c3_i15];
  }

  for (c3_i16 = 0; c3_i16 < 4; c3_i16++) {
    c3_B[c3_i16] = (*c3_b_B)[c3_i16];
  }

  for (c3_i17 = 0; c3_i17 < 12; c3_i17++) {
    c3_C[c3_i17] = (*c3_b_C)[c3_i17];
  }

  for (c3_i18 = 0; c3_i18 < 3; c3_i18++) {
    c3_D[c3_i18] = (*c3_b_D)[c3_i18];
  }

  for (c3_i19 = 0; c3_i19 < 16; c3_i19++) {
    c3_Q[c3_i19] = (*c3_b_Q)[c3_i19];
  }

  for (c3_i20 = 0; c3_i20 < 9; c3_i20++) {
    c3_R[c3_i20] = (*c3_b_R)[c3_i20];
  }

  c3_u = c3_hoistedGlobal;
  for (c3_i21 = 0; c3_i21 < 3; c3_i21++) {
    c3_y[c3_i21] = (*c3_j_y)[c3_i21];
  }

  for (c3_i22 = 0; c3_i22 < 16; c3_i22++) {
    c3_P[c3_i22] = (*c3_b_P)[c3_i22];
  }

  for (c3_i23 = 0; c3_i23 < 4; c3_i23++) {
    c3_state[c3_i23] = (*c3_b_state)[c3_i23];
  }

  sf_debug_symbol_scope_push_eml(0U, 18U, 18U, c3_debug_family_names,
    c3_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c3_n, 0U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c3_x_, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_P_, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_K, 3U, c3_g_sf_marshallOut,
    c3_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargin, 4U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c3_nargout, 5U, c3_d_sf_marshallOut,
    c3_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c3_A, 6U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_B, 7U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_C, 8U, c3_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_D, 9U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_Q, 10U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_R, 11U, c3_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c3_u, 12U, c3_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_y, 13U, c3_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_P, 14U, c3_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c3_state, 15U, c3_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c3_state_est, 16U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c3_P_est, 17U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c3_sfEvent, 7);
  c3_n = 4.0;
  _SFD_EML_CALL(0U, *c3_sfEvent, 10);
  for (c3_i24 = 0; c3_i24 < 16; c3_i24++) {
    c3_a[c3_i24] = c3_A[c3_i24];
  }

  for (c3_i25 = 0; c3_i25 < 4; c3_i25++) {
    c3_b[c3_i25] = c3_state[c3_i25];
  }

  c3_eml_scalar_eg(chartInstance);
  c3_eml_scalar_eg(chartInstance);
  for (c3_i26 = 0; c3_i26 < 4; c3_i26++) {
    c3_b_y[c3_i26] = 0.0;
    c3_i27 = 0;
    for (c3_i28 = 0; c3_i28 < 4; c3_i28++) {
      c3_b_y[c3_i26] += c3_a[c3_i27 + c3_i26] * c3_b[c3_i28];
      c3_i27 += 4;
    }
  }

  for (c3_i29 = 0; c3_i29 < 4; c3_i29++) {
    c3_b[c3_i29] = c3_B[c3_i29];
  }

  c3_b_b = c3_u;
  for (c3_i30 = 0; c3_i30 < 4; c3_i30++) {
    c3_b[c3_i30] *= c3_b_b;
  }

  for (c3_i31 = 0; c3_i31 < 4; c3_i31++) {
    c3_x_[c3_i31] = c3_b_y[c3_i31] + c3_b[c3_i31];
  }

  _SFD_EML_CALL(0U, *c3_sfEvent, 11);
  for (c3_i32 = 0; c3_i32 < 16; c3_i32++) {
    c3_a[c3_i32] = c3_A[c3_i32];
  }

  for (c3_i33 = 0; c3_i33 < 16; c3_i33++) {
    c3_c_b[c3_i33] = c3_P[c3_i33];
  }

  c3_b_eml_scalar_eg(chartInstance);
  c3_b_eml_scalar_eg(chartInstance);
  for (c3_i34 = 0; c3_i34 < 4; c3_i34++) {
    c3_i35 = 0;
    for (c3_i36 = 0; c3_i36 < 4; c3_i36++) {
      c3_c_y[c3_i35 + c3_i34] = 0.0;
      c3_i37 = 0;
      for (c3_i38 = 0; c3_i38 < 4; c3_i38++) {
        c3_c_y[c3_i35 + c3_i34] += c3_a[c3_i37 + c3_i34] * c3_c_b[c3_i38 +
          c3_i35];
        c3_i37 += 4;
      }

      c3_i35 += 4;
    }
  }

  c3_i39 = 0;
  for (c3_i40 = 0; c3_i40 < 4; c3_i40++) {
    c3_i41 = 0;
    for (c3_i42 = 0; c3_i42 < 4; c3_i42++) {
      c3_c_b[c3_i42 + c3_i39] = c3_A[c3_i41 + c3_i40];
      c3_i41 += 4;
    }

    c3_i39 += 4;
  }

  c3_b_eml_scalar_eg(chartInstance);
  c3_b_eml_scalar_eg(chartInstance);
  for (c3_i43 = 0; c3_i43 < 4; c3_i43++) {
    c3_i44 = 0;
    for (c3_i45 = 0; c3_i45 < 4; c3_i45++) {
      c3_d_y[c3_i44 + c3_i43] = 0.0;
      c3_i46 = 0;
      for (c3_i47 = 0; c3_i47 < 4; c3_i47++) {
        c3_d_y[c3_i44 + c3_i43] += c3_c_y[c3_i46 + c3_i43] * c3_c_b[c3_i47 +
          c3_i44];
        c3_i46 += 4;
      }

      c3_i44 += 4;
    }
  }

  for (c3_i48 = 0; c3_i48 < 16; c3_i48++) {
    c3_P_[c3_i48] = c3_d_y[c3_i48] + c3_Q[c3_i48];
  }

  _SFD_EML_CALL(0U, *c3_sfEvent, 14);
  for (c3_i49 = 0; c3_i49 < 16; c3_i49++) {
    c3_a[c3_i49] = c3_P_[c3_i49];
  }

  c3_i50 = 0;
  for (c3_i51 = 0; c3_i51 < 3; c3_i51++) {
    c3_i52 = 0;
    for (c3_i53 = 0; c3_i53 < 4; c3_i53++) {
      c3_d_b[c3_i53 + c3_i50] = c3_C[c3_i52 + c3_i51];
      c3_i52 += 3;
    }

    c3_i50 += 4;
  }

  c3_c_eml_scalar_eg(chartInstance);
  c3_c_eml_scalar_eg(chartInstance);
  for (c3_i54 = 0; c3_i54 < 4; c3_i54++) {
    c3_i55 = 0;
    for (c3_i56 = 0; c3_i56 < 3; c3_i56++) {
      c3_e_y[c3_i55 + c3_i54] = 0.0;
      c3_i57 = 0;
      for (c3_i58 = 0; c3_i58 < 4; c3_i58++) {
        c3_e_y[c3_i55 + c3_i54] += c3_a[c3_i57 + c3_i54] * c3_d_b[c3_i58 +
          c3_i55];
        c3_i57 += 4;
      }

      c3_i55 += 4;
    }
  }

  for (c3_i59 = 0; c3_i59 < 12; c3_i59++) {
    c3_b_a[c3_i59] = c3_C[c3_i59];
  }

  for (c3_i60 = 0; c3_i60 < 16; c3_i60++) {
    c3_c_b[c3_i60] = c3_P_[c3_i60];
  }

  c3_d_eml_scalar_eg(chartInstance);
  c3_d_eml_scalar_eg(chartInstance);
  for (c3_i61 = 0; c3_i61 < 3; c3_i61++) {
    c3_i62 = 0;
    c3_i63 = 0;
    for (c3_i64 = 0; c3_i64 < 4; c3_i64++) {
      c3_f_y[c3_i62 + c3_i61] = 0.0;
      c3_i65 = 0;
      for (c3_i66 = 0; c3_i66 < 4; c3_i66++) {
        c3_f_y[c3_i62 + c3_i61] += c3_b_a[c3_i65 + c3_i61] * c3_c_b[c3_i66 +
          c3_i63];
        c3_i65 += 3;
      }

      c3_i62 += 3;
      c3_i63 += 4;
    }
  }

  c3_i67 = 0;
  for (c3_i68 = 0; c3_i68 < 3; c3_i68++) {
    c3_i69 = 0;
    for (c3_i70 = 0; c3_i70 < 4; c3_i70++) {
      c3_d_b[c3_i70 + c3_i67] = c3_C[c3_i69 + c3_i68];
      c3_i69 += 3;
    }

    c3_i67 += 4;
  }

  c3_e_eml_scalar_eg(chartInstance);
  c3_e_eml_scalar_eg(chartInstance);
  for (c3_i71 = 0; c3_i71 < 3; c3_i71++) {
    c3_i72 = 0;
    c3_i73 = 0;
    for (c3_i74 = 0; c3_i74 < 3; c3_i74++) {
      c3_g_y[c3_i72 + c3_i71] = 0.0;
      c3_i75 = 0;
      for (c3_i76 = 0; c3_i76 < 4; c3_i76++) {
        c3_g_y[c3_i72 + c3_i71] += c3_f_y[c3_i75 + c3_i71] * c3_d_b[c3_i76 +
          c3_i73];
        c3_i75 += 3;
      }

      c3_i72 += 3;
      c3_i73 += 4;
    }
  }

  for (c3_i77 = 0; c3_i77 < 9; c3_i77++) {
    c3_h_y[c3_i77] = c3_g_y[c3_i77] + c3_R[c3_i77];
  }

  c3_mpower(chartInstance, c3_h_y, c3_g_y);
  c3_h_eml_scalar_eg(chartInstance);
  c3_h_eml_scalar_eg(chartInstance);
  for (c3_i78 = 0; c3_i78 < 12; c3_i78++) {
    c3_K[c3_i78] = 0.0;
  }

  for (c3_i79 = 0; c3_i79 < 12; c3_i79++) {
    c3_K[c3_i79] = 0.0;
  }

  for (c3_i80 = 0; c3_i80 < 12; c3_i80++) {
    c3_d_b[c3_i80] = c3_K[c3_i80];
  }

  for (c3_i81 = 0; c3_i81 < 12; c3_i81++) {
    c3_K[c3_i81] = c3_d_b[c3_i81];
  }

  for (c3_i82 = 0; c3_i82 < 12; c3_i82++) {
    c3_d_b[c3_i82] = c3_K[c3_i82];
  }

  for (c3_i83 = 0; c3_i83 < 12; c3_i83++) {
    c3_K[c3_i83] = c3_d_b[c3_i83];
  }

  for (c3_i84 = 0; c3_i84 < 4; c3_i84++) {
    c3_i85 = 0;
    c3_i86 = 0;
    for (c3_i87 = 0; c3_i87 < 3; c3_i87++) {
      c3_K[c3_i85 + c3_i84] = 0.0;
      c3_i88 = 0;
      for (c3_i89 = 0; c3_i89 < 3; c3_i89++) {
        c3_K[c3_i85 + c3_i84] += c3_e_y[c3_i88 + c3_i84] * c3_g_y[c3_i89 +
          c3_i86];
        c3_i88 += 4;
      }

      c3_i85 += 4;
      c3_i86 += 3;
    }
  }

  _SFD_EML_CALL(0U, *c3_sfEvent, 15);
  for (c3_i90 = 0; c3_i90 < 12; c3_i90++) {
    c3_b_a[c3_i90] = c3_C[c3_i90];
  }

  for (c3_i91 = 0; c3_i91 < 4; c3_i91++) {
    c3_b[c3_i91] = c3_x_[c3_i91];
  }

  c3_i_eml_scalar_eg(chartInstance);
  c3_i_eml_scalar_eg(chartInstance);
  for (c3_i92 = 0; c3_i92 < 3; c3_i92++) {
    c3_i_y[c3_i92] = 0.0;
    c3_i93 = 0;
    for (c3_i94 = 0; c3_i94 < 4; c3_i94++) {
      c3_i_y[c3_i92] += c3_b_a[c3_i93 + c3_i92] * c3_b[c3_i94];
      c3_i93 += 3;
    }
  }

  for (c3_i95 = 0; c3_i95 < 12; c3_i95++) {
    c3_d_b[c3_i95] = c3_K[c3_i95];
  }

  for (c3_i96 = 0; c3_i96 < 3; c3_i96++) {
    c3_i_y[c3_i96] = c3_y[c3_i96] - c3_i_y[c3_i96];
  }

  c3_j_eml_scalar_eg(chartInstance);
  c3_j_eml_scalar_eg(chartInstance);
  for (c3_i97 = 0; c3_i97 < 4; c3_i97++) {
    c3_b_y[c3_i97] = 0.0;
    c3_i98 = 0;
    for (c3_i99 = 0; c3_i99 < 3; c3_i99++) {
      c3_b_y[c3_i97] += c3_d_b[c3_i98 + c3_i97] * c3_i_y[c3_i99];
      c3_i98 += 4;
    }
  }

  for (c3_i100 = 0; c3_i100 < 4; c3_i100++) {
    c3_state_est[c3_i100] = c3_x_[c3_i100] + c3_b_y[c3_i100];
  }

  _SFD_EML_CALL(0U, *c3_sfEvent, 16);
  for (c3_i101 = 0; c3_i101 < 12; c3_i101++) {
    c3_d_b[c3_i101] = c3_K[c3_i101];
  }

  for (c3_i102 = 0; c3_i102 < 12; c3_i102++) {
    c3_b_a[c3_i102] = c3_C[c3_i102];
  }

  c3_k_eml_scalar_eg(chartInstance);
  c3_k_eml_scalar_eg(chartInstance);
  for (c3_i103 = 0; c3_i103 < 4; c3_i103++) {
    c3_i104 = 0;
    c3_i105 = 0;
    for (c3_i106 = 0; c3_i106 < 4; c3_i106++) {
      c3_c_y[c3_i104 + c3_i103] = 0.0;
      c3_i107 = 0;
      for (c3_i108 = 0; c3_i108 < 3; c3_i108++) {
        c3_c_y[c3_i104 + c3_i103] += c3_d_b[c3_i107 + c3_i103] * c3_b_a[c3_i108
          + c3_i105];
        c3_i107 += 4;
      }

      c3_i104 += 4;
      c3_i105 += 3;
    }
  }

  c3_eye(chartInstance, c3_a);
  for (c3_i109 = 0; c3_i109 < 16; c3_i109++) {
    c3_a[c3_i109] -= c3_c_y[c3_i109];
  }

  for (c3_i110 = 0; c3_i110 < 16; c3_i110++) {
    c3_c_b[c3_i110] = c3_P_[c3_i110];
  }

  c3_b_eml_scalar_eg(chartInstance);
  c3_b_eml_scalar_eg(chartInstance);
  for (c3_i111 = 0; c3_i111 < 16; c3_i111++) {
    c3_P_est[c3_i111] = 0.0;
  }

  for (c3_i112 = 0; c3_i112 < 16; c3_i112++) {
    c3_P_est[c3_i112] = 0.0;
  }

  for (c3_i113 = 0; c3_i113 < 16; c3_i113++) {
    c3_d_y[c3_i113] = c3_P_est[c3_i113];
  }

  for (c3_i114 = 0; c3_i114 < 16; c3_i114++) {
    c3_P_est[c3_i114] = c3_d_y[c3_i114];
  }

  for (c3_i115 = 0; c3_i115 < 16; c3_i115++) {
    c3_d_y[c3_i115] = c3_P_est[c3_i115];
  }

  for (c3_i116 = 0; c3_i116 < 16; c3_i116++) {
    c3_P_est[c3_i116] = c3_d_y[c3_i116];
  }

  for (c3_i117 = 0; c3_i117 < 4; c3_i117++) {
    c3_i118 = 0;
    for (c3_i119 = 0; c3_i119 < 4; c3_i119++) {
      c3_P_est[c3_i118 + c3_i117] = 0.0;
      c3_i120 = 0;
      for (c3_i121 = 0; c3_i121 < 4; c3_i121++) {
        c3_P_est[c3_i118 + c3_i117] += c3_a[c3_i120 + c3_i117] * c3_c_b[c3_i121
          + c3_i118];
        c3_i120 += 4;
      }

      c3_i118 += 4;
    }
  }

  _SFD_EML_CALL(0U, *c3_sfEvent, -16);
  sf_debug_symbol_scope_pop();
  for (c3_i122 = 0; c3_i122 < 4; c3_i122++) {
    (*c3_b_state_est)[c3_i122] = c3_state_est[c3_i122];
  }

  for (c3_i123 = 0; c3_i123 < 16; c3_i123++) {
    (*c3_b_P_est)[c3_i123] = c3_P_est[c3_i123];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c3_sfEvent);
}

static void initSimStructsc3_Hquad_control_LIB_MPC
  (SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i124;
  int32_T c3_i125;
  int32_T c3_i126;
  real_T c3_b_inData[16];
  int32_T c3_i127;
  int32_T c3_i128;
  int32_T c3_i129;
  real_T c3_u[16];
  const mxArray *c3_y = NULL;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i124 = 0;
  for (c3_i125 = 0; c3_i125 < 4; c3_i125++) {
    for (c3_i126 = 0; c3_i126 < 4; c3_i126++) {
      c3_b_inData[c3_i126 + c3_i124] = (*(real_T (*)[16])c3_inData)[c3_i126 +
        c3_i124];
    }

    c3_i124 += 4;
  }

  c3_i127 = 0;
  for (c3_i128 = 0; c3_i128 < 4; c3_i128++) {
    for (c3_i129 = 0; c3_i129 < 4; c3_i129++) {
      c3_u[c3_i129 + c3_i127] = c3_b_inData[c3_i129 + c3_i127];
    }

    c3_i127 += 4;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_P_est, const char_T *c3_identifier, real_T
  c3_y[16])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_P_est), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_P_est);
}

static void c3_b_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[16])
{
  real_T c3_dv2[16];
  int32_T c3_i130;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 2, 4, 4);
  for (c3_i130 = 0; c3_i130 < 16; c3_i130++) {
    c3_y[c3_i130] = c3_dv2[c3_i130];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_P_est;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[16];
  int32_T c3_i131;
  int32_T c3_i132;
  int32_T c3_i133;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_P_est = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_P_est), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_P_est);
  c3_i131 = 0;
  for (c3_i132 = 0; c3_i132 < 4; c3_i132++) {
    for (c3_i133 = 0; c3_i133 < 4; c3_i133++) {
      (*(real_T (*)[16])c3_outData)[c3_i133 + c3_i131] = c3_y[c3_i133 + c3_i131];
    }

    c3_i131 += 4;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i134;
  real_T c3_b_inData[4];
  int32_T c3_i135;
  real_T c3_u[4];
  const mxArray *c3_y = NULL;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i134 = 0; c3_i134 < 4; c3_i134++) {
    c3_b_inData[c3_i134] = (*(real_T (*)[4])c3_inData)[c3_i134];
  }

  for (c3_i135 = 0; c3_i135 < 4; c3_i135++) {
    c3_u[c3_i135] = c3_b_inData[c3_i135];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_state_est, const char_T *c3_identifier,
  real_T c3_y[4])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_state_est), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_state_est);
}

static void c3_d_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[4])
{
  real_T c3_dv3[4];
  int32_T c3_i136;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv3, 1, 0, 0U, 1, 0U, 1, 4);
  for (c3_i136 = 0; c3_i136 < 4; c3_i136++) {
    c3_y[c3_i136] = c3_dv3[c3_i136];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_state_est;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[4];
  int32_T c3_i137;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_state_est = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_state_est), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_state_est);
  for (c3_i137 = 0; c3_i137 < 4; c3_i137++) {
    (*(real_T (*)[4])c3_outData)[c3_i137] = c3_y[c3_i137];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i138;
  real_T c3_b_inData[3];
  int32_T c3_i139;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i138 = 0; c3_i138 < 3; c3_i138++) {
    c3_b_inData[c3_i138] = (*(real_T (*)[3])c3_inData)[c3_i138];
  }

  for (c3_i139 = 0; c3_i139 < 3; c3_i139++) {
    c3_u[c3_i139] = c3_b_inData[c3_i139];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i140;
  int32_T c3_i141;
  int32_T c3_i142;
  real_T c3_b_inData[9];
  int32_T c3_i143;
  int32_T c3_i144;
  int32_T c3_i145;
  real_T c3_u[9];
  const mxArray *c3_y = NULL;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i140 = 0;
  for (c3_i141 = 0; c3_i141 < 3; c3_i141++) {
    for (c3_i142 = 0; c3_i142 < 3; c3_i142++) {
      c3_b_inData[c3_i142 + c3_i140] = (*(real_T (*)[9])c3_inData)[c3_i142 +
        c3_i140];
    }

    c3_i140 += 3;
  }

  c3_i143 = 0;
  for (c3_i144 = 0; c3_i144 < 3; c3_i144++) {
    for (c3_i145 = 0; c3_i145 < 3; c3_i145++) {
      c3_u[c3_i145 + c3_i143] = c3_b_inData[c3_i145 + c3_i143];
    }

    c3_i143 += 3;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i146;
  int32_T c3_i147;
  int32_T c3_i148;
  real_T c3_b_inData[12];
  int32_T c3_i149;
  int32_T c3_i150;
  int32_T c3_i151;
  real_T c3_u[12];
  const mxArray *c3_y = NULL;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i146 = 0;
  for (c3_i147 = 0; c3_i147 < 4; c3_i147++) {
    for (c3_i148 = 0; c3_i148 < 3; c3_i148++) {
      c3_b_inData[c3_i148 + c3_i146] = (*(real_T (*)[12])c3_inData)[c3_i148 +
        c3_i146];
    }

    c3_i146 += 3;
  }

  c3_i149 = 0;
  for (c3_i150 = 0; c3_i150 < 4; c3_i150++) {
    for (c3_i151 = 0; c3_i151 < 3; c3_i151++) {
      c3_u[c3_i151 + c3_i149] = c3_b_inData[c3_i151 + c3_i149];
    }

    c3_i149 += 3;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 4), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_e_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i152;
  int32_T c3_i153;
  int32_T c3_i154;
  real_T c3_b_inData[12];
  int32_T c3_i155;
  int32_T c3_i156;
  int32_T c3_i157;
  real_T c3_u[12];
  const mxArray *c3_y = NULL;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i152 = 0;
  for (c3_i153 = 0; c3_i153 < 3; c3_i153++) {
    for (c3_i154 = 0; c3_i154 < 4; c3_i154++) {
      c3_b_inData[c3_i154 + c3_i152] = (*(real_T (*)[12])c3_inData)[c3_i154 +
        c3_i152];
    }

    c3_i152 += 4;
  }

  c3_i155 = 0;
  for (c3_i156 = 0; c3_i156 < 3; c3_i156++) {
    for (c3_i157 = 0; c3_i157 < 4; c3_i157++) {
      c3_u[c3_i157 + c3_i155] = c3_b_inData[c3_i157 + c3_i155];
    }

    c3_i155 += 4;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 4, 3), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_f_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[12])
{
  real_T c3_dv4[12];
  int32_T c3_i158;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv4, 1, 0, 0U, 1, 0U, 2, 4, 3);
  for (c3_i158 = 0; c3_i158 < 12; c3_i158++) {
    c3_y[c3_i158] = c3_dv4[c3_i158];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_K;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[12];
  int32_T c3_i159;
  int32_T c3_i160;
  int32_T c3_i161;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_K = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_K), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_K);
  c3_i159 = 0;
  for (c3_i160 = 0; c3_i160 < 3; c3_i160++) {
    for (c3_i161 = 0; c3_i161 < 4; c3_i161++) {
      (*(real_T (*)[12])c3_outData)[c3_i161 + c3_i159] = c3_y[c3_i161 + c3_i159];
    }

    c3_i159 += 4;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[27];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i162;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 27), FALSE);
  for (c3_i162 = 0; c3_i162 < 27; c3_i162++) {
    c3_r0 = &c3_info[c3_i162];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i162);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i162);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i162);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i162);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i162);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i162);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i162);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i162);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[27])
{
  c3_info[0].context = "";
  c3_info[0].name = "mtimes";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[0].fileTimeLo = 1289519692U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[1].name = "eml_index_class";
  c3_info[1].dominantType = "";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[1].fileTimeLo = 1286818778U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[2].name = "eml_scalar_eg";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[2].fileTimeLo = 1286818796U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[3].name = "eml_xgemm";
  c3_info[3].dominantType = "int32";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[3].fileTimeLo = 1299076772U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 0U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c3_info[4].name = "eml_blas_inline";
  c3_info[4].dominantType = "";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[4].fileTimeLo = 1299076768U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c3_info[5].name = "eml_refblas_xgemm";
  c3_info[5].dominantType = "int32";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c3_info[5].fileTimeLo = 1299076774U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context = "";
  c3_info[6].name = "mpower";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[6].fileTimeLo = 1286818842U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c3_info[7].name = "eml_scalar_floor";
  c3_info[7].dominantType = "double";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c3_info[7].fileTimeLo = 1286818726U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c3_info[8].name = "eml_scalar_abs";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c3_info[8].fileTimeLo = 1286818712U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c3_info[9].name = "inv";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c3_info[9].fileTimeLo = 1305318000U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c3_info[10].name = "abs";
  c3_info[10].dominantType = "double";
  c3_info[10].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c3_info[10].fileTimeLo = 1286818694U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c3_info[11].name = "eml_div";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[11].fileTimeLo = 1305318000U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv3x3";
  c3_info[12].name = "eml_index_plus";
  c3_info[12].dominantType = "int32";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[12].fileTimeLo = 1286818778U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c3_info[13].name = "norm";
  c3_info[13].dominantType = "double";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c3_info[13].fileTimeLo = 1286818826U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c3_info[14].name = "isnan";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c3_info[14].fileTimeLo = 1286818760U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c3_info[15].name = "eml_guarded_nan";
  c3_info[15].dominantType = "char";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c3_info[15].fileTimeLo = 1286818776U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c3_info[16].name = "eml_is_float_class";
  c3_info[16].dominantType = "char";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c3_info[16].fileTimeLo = 1286818782U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c3_info[17].name = "eml_warning";
  c3_info[17].dominantType = "char";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c3_info[17].fileTimeLo = 1286818802U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c3_info[18].name = "eps";
  c3_info[18].dominantType = "char";
  c3_info[18].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c3_info[18].fileTimeLo = 1286818686U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c3_info[19].name = "eml_flt2str";
  c3_info[19].dominantType = "double";
  c3_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c3_info[19].fileTimeLo = 1286818776U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context = "";
  c3_info[20].name = "eye";
  c3_info[20].dominantType = "double";
  c3_info[20].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c3_info[20].fileTimeLo = 1286818688U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[21].name = "eml_assert_valid_size_arg";
  c3_info[21].dominantType = "double";
  c3_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c3_info[21].fileTimeLo = 1286818694U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c3_info[22].name = "isinf";
  c3_info[22].dominantType = "double";
  c3_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c3_info[22].fileTimeLo = 1286818760U;
  c3_info[22].fileTimeHi = 0U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
  c3_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c3_info[23].name = "intmax";
  c3_info[23].dominantType = "char";
  c3_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[23].fileTimeLo = 1286818756U;
  c3_info[23].fileTimeHi = 0U;
  c3_info[23].mFileTimeLo = 0U;
  c3_info[23].mFileTimeHi = 0U;
  c3_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c3_info[24].name = "min";
  c3_info[24].dominantType = "double";
  c3_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[24].fileTimeLo = 1308747330U;
  c3_info[24].fileTimeHi = 0U;
  c3_info[24].mFileTimeLo = 0U;
  c3_info[24].mFileTimeHi = 0U;
  c3_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c3_info[25].name = "eml_min_or_max";
  c3_info[25].dominantType = "char";
  c3_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c3_info[25].fileTimeLo = 1303146212U;
  c3_info[25].fileTimeHi = 0U;
  c3_info[25].mFileTimeLo = 0U;
  c3_info[25].mFileTimeHi = 0U;
  c3_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c3_info[26].name = "eml_scalexp_alloc";
  c3_info[26].dominantType = "double";
  c3_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c3_info[26].fileTimeLo = 1286818796U;
  c3_info[26].fileTimeHi = 0U;
  c3_info[26].mFileTimeLo = 0U;
  c3_info[26].mFileTimeHi = 0U;
}

static void c3_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c3_b_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c3_c_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c3_d_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c3_e_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c3_mpower(SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                      real_T c3_a[9], real_T c3_c[9])
{
  int32_T c3_i163;
  real_T c3_b_a[9];
  for (c3_i163 = 0; c3_i163 < 9; c3_i163++) {
    c3_b_a[c3_i163] = c3_a[c3_i163];
  }

  c3_matrix_to_integer_power(chartInstance, c3_b_a, -1.0, c3_c);
}

static void c3_matrix_to_integer_power(SFc3_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, real_T c3_a[9], real_T c3_b, real_T c3_c[9])
{
  real_T c3_x;
  real_T c3_e;
  boolean_T c3_firstmult;
  real_T c3_b_x;
  real_T c3_ed2;
  real_T c3_b_b;
  real_T c3_y;
  int32_T c3_i164;
  int32_T c3_i165;
  real_T c3_A[9];
  int32_T c3_i166;
  int32_T c3_i167;
  int32_T c3_i168;
  int32_T c3_i169;
  int32_T c3_i170;
  int32_T c3_i171;
  int32_T c3_i172;
  real_T c3_b_A[9];
  int32_T c3_i173;
  real_T c3_c_A[9];
  real_T c3_n1x;
  int32_T c3_i174;
  real_T c3_b_c[9];
  real_T c3_n1xinv;
  real_T c3_b_a;
  real_T c3_c_b;
  real_T c3_b_y;
  real_T c3_rc;
  real_T c3_c_x;
  boolean_T c3_d_b;
  real_T c3_d_x;
  int32_T c3_i175;
  static char_T c3_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c3_u[8];
  const mxArray *c3_c_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_c_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_d_u;
  const mxArray *c3_f_y = NULL;
  char_T c3_str[14];
  int32_T c3_i176;
  char_T c3_b_str[14];
  int32_T c3_i177;
  int32_T c3_i178;
  int32_T c3_i179;
  int32_T c3_i180;
  int32_T c3_i181;
  int32_T c3_i182;
  int32_T c3_i183;
  int32_T c3_k;
  int32_T c3_b_k;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  int32_T exitg1;
  c3_f_eml_scalar_eg(chartInstance);
  c3_x = c3_b;
  c3_e = muDoubleScalarAbs(c3_x);
  if (c3_e > 0.0) {
    c3_firstmult = TRUE;
    do {
      exitg1 = 0U;
      c3_b_x = c3_e / 2.0;
      c3_ed2 = c3_b_x;
      c3_ed2 = muDoubleScalarFloor(c3_ed2);
      c3_b_b = c3_ed2;
      c3_y = 2.0 * c3_b_b;
      if (c3_y != c3_e) {
        if (c3_firstmult) {
          for (c3_i164 = 0; c3_i164 < 9; c3_i164++) {
            c3_c[c3_i164] = c3_a[c3_i164];
          }

          c3_firstmult = FALSE;
        } else {
          c3_g_eml_scalar_eg(chartInstance);
          c3_g_eml_scalar_eg(chartInstance);
          for (c3_i165 = 0; c3_i165 < 9; c3_i165++) {
            c3_A[c3_i165] = c3_c[c3_i165];
          }

          for (c3_i166 = 0; c3_i166 < 3; c3_i166++) {
            c3_i167 = 0;
            for (c3_i168 = 0; c3_i168 < 3; c3_i168++) {
              c3_c[c3_i167 + c3_i166] = 0.0;
              c3_i169 = 0;
              for (c3_i170 = 0; c3_i170 < 3; c3_i170++) {
                c3_c[c3_i167 + c3_i166] += c3_A[c3_i169 + c3_i166] *
                  c3_a[c3_i170 + c3_i167];
                c3_i169 += 3;
              }

              c3_i167 += 3;
            }
          }
        }
      }

      if (c3_ed2 == 0.0) {
        exitg1 = 1U;
      } else {
        c3_e = c3_ed2;
        c3_g_eml_scalar_eg(chartInstance);
        c3_g_eml_scalar_eg(chartInstance);
        for (c3_i177 = 0; c3_i177 < 9; c3_i177++) {
          c3_A[c3_i177] = c3_a[c3_i177];
        }

        for (c3_i178 = 0; c3_i178 < 3; c3_i178++) {
          c3_i179 = 0;
          for (c3_i180 = 0; c3_i180 < 3; c3_i180++) {
            c3_a[c3_i179 + c3_i178] = 0.0;
            c3_i181 = 0;
            for (c3_i182 = 0; c3_i182 < 3; c3_i182++) {
              c3_a[c3_i179 + c3_i178] += c3_A[c3_i181 + c3_i178] * c3_A[c3_i182
                + c3_i179];
              c3_i181 += 3;
            }

            c3_i179 += 3;
          }
        }
      }
    } while (exitg1 == 0U);

    if (c3_b < 0.0) {
      for (c3_i171 = 0; c3_i171 < 9; c3_i171++) {
        c3_A[c3_i171] = c3_c[c3_i171];
      }

      for (c3_i172 = 0; c3_i172 < 9; c3_i172++) {
        c3_b_A[c3_i172] = c3_A[c3_i172];
      }

      c3_inv3x3(chartInstance, c3_b_A, c3_c);
      for (c3_i173 = 0; c3_i173 < 9; c3_i173++) {
        c3_c_A[c3_i173] = c3_A[c3_i173];
      }

      c3_n1x = c3_norm(chartInstance, c3_c_A);
      for (c3_i174 = 0; c3_i174 < 9; c3_i174++) {
        c3_b_c[c3_i174] = c3_c[c3_i174];
      }

      c3_n1xinv = c3_norm(chartInstance, c3_b_c);
      c3_b_a = c3_n1x;
      c3_c_b = c3_n1xinv;
      c3_b_y = c3_b_a * c3_c_b;
      c3_rc = 1.0 / c3_b_y;
      guard1 = FALSE;
      guard2 = FALSE;
      if (c3_n1x == 0.0) {
        guard2 = TRUE;
      } else if (c3_n1xinv == 0.0) {
        guard2 = TRUE;
      } else if (c3_rc == 0.0) {
        guard1 = TRUE;
      } else {
        c3_c_x = c3_rc;
        c3_d_b = muDoubleScalarIsNaN(c3_c_x);
        guard3 = FALSE;
        if (c3_d_b) {
          guard3 = TRUE;
        } else {
          if (c3_rc < 2.2204460492503131E-16) {
            guard3 = TRUE;
          }
        }

        if (guard3 == TRUE) {
          c3_d_x = c3_rc;
          for (c3_i175 = 0; c3_i175 < 8; c3_i175++) {
            c3_u[c3_i175] = c3_cv0[c3_i175];
          }

          c3_c_y = NULL;
          sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1,
            8), FALSE);
          c3_b_u = 14.0;
          c3_d_y = NULL;
          sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c3_c_u = 6.0;
          c3_e_y = NULL;
          sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c3_d_u = c3_d_x;
          c3_f_y = NULL;
          sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c3_g_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U,
            2U, 14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c3_c_y, 14, c3_d_y,
            14, c3_e_y), 14, c3_f_y), "sprintf", c3_str);
          for (c3_i176 = 0; c3_i176 < 14; c3_i176++) {
            c3_b_str[c3_i176] = c3_str[c3_i176];
          }

          c3_b_eml_warning(chartInstance, c3_b_str);
        }
      }

      if (guard2 == TRUE) {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        c3_eml_warning(chartInstance);
      }
    }
  } else {
    for (c3_i183 = 0; c3_i183 < 9; c3_i183++) {
      c3_c[c3_i183] = 0.0;
    }

    for (c3_k = 1; c3_k < 4; c3_k++) {
      c3_b_k = c3_k;
      c3_c[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c3_b_k), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 3, 2, 0) - 1))
        - 1] = 1.0;
    }
  }
}

static void c3_f_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c3_g_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c3_inv3x3(SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                      real_T c3_x[9], real_T c3_y[9])
{
  int32_T c3_p1;
  int32_T c3_p2;
  int32_T c3_p3;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_absx11;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_absx21;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_absx31;
  real_T c3_t1;
  real_T c3_h_x;
  real_T c3_b_y;
  real_T c3_z;
  real_T c3_i_x;
  real_T c3_c_y;
  real_T c3_b_z;
  real_T c3_a;
  real_T c3_b;
  real_T c3_d_y;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_e_y;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_f_y;
  real_T c3_d_a;
  real_T c3_d_b;
  real_T c3_g_y;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_h_y;
  real_T c3_l_x;
  real_T c3_m_x;
  real_T c3_i_y;
  int32_T c3_itmp;
  real_T c3_n_x;
  real_T c3_j_y;
  real_T c3_c_z;
  real_T c3_e_a;
  real_T c3_e_b;
  real_T c3_k_y;
  real_T c3_f_a;
  real_T c3_f_b;
  real_T c3_l_y;
  real_T c3_o_x;
  real_T c3_m_y;
  real_T c3_t3;
  real_T c3_g_a;
  real_T c3_g_b;
  real_T c3_n_y;
  real_T c3_p_x;
  real_T c3_o_y;
  real_T c3_t2;
  int32_T c3_h_a;
  int32_T c3_c;
  real_T c3_i_a;
  real_T c3_h_b;
  real_T c3_p_y;
  real_T c3_j_a;
  real_T c3_i_b;
  real_T c3_q_y;
  real_T c3_q_x;
  real_T c3_r_y;
  real_T c3_d_z;
  int32_T c3_k_a;
  int32_T c3_b_c;
  int32_T c3_l_a;
  int32_T c3_c_c;
  real_T c3_r_x;
  real_T c3_s_y;
  real_T c3_m_a;
  real_T c3_j_b;
  real_T c3_t_y;
  real_T c3_s_x;
  real_T c3_u_y;
  int32_T c3_n_a;
  int32_T c3_d_c;
  real_T c3_o_a;
  real_T c3_k_b;
  real_T c3_v_y;
  real_T c3_p_a;
  real_T c3_l_b;
  real_T c3_w_y;
  real_T c3_t_x;
  real_T c3_x_y;
  real_T c3_e_z;
  int32_T c3_q_a;
  int32_T c3_e_c;
  int32_T c3_r_a;
  int32_T c3_f_c;
  real_T c3_y_y;
  real_T c3_s_a;
  real_T c3_m_b;
  real_T c3_ab_y;
  real_T c3_u_x;
  real_T c3_bb_y;
  int32_T c3_t_a;
  int32_T c3_g_c;
  real_T c3_u_a;
  real_T c3_n_b;
  real_T c3_cb_y;
  real_T c3_v_a;
  real_T c3_o_b;
  real_T c3_db_y;
  real_T c3_v_x;
  real_T c3_eb_y;
  real_T c3_f_z;
  int32_T c3_w_a;
  int32_T c3_h_c;
  int32_T c3_x_a;
  int32_T c3_i_c;
  boolean_T guard1 = FALSE;
  c3_p1 = 0;
  c3_p2 = 3;
  c3_p3 = 6;
  c3_b_x = c3_x[0];
  c3_c_x = c3_b_x;
  c3_absx11 = muDoubleScalarAbs(c3_c_x);
  c3_d_x = c3_x[1];
  c3_e_x = c3_d_x;
  c3_absx21 = muDoubleScalarAbs(c3_e_x);
  c3_f_x = c3_x[2];
  c3_g_x = c3_f_x;
  c3_absx31 = muDoubleScalarAbs(c3_g_x);
  guard1 = FALSE;
  if (c3_absx21 > c3_absx11) {
    if (c3_absx21 > c3_absx31) {
      c3_p1 = 3;
      c3_p2 = 0;
      c3_t1 = c3_x[0];
      c3_x[0] = c3_x[1];
      c3_x[1] = c3_t1;
      c3_t1 = c3_x[3];
      c3_x[3] = c3_x[4];
      c3_x[4] = c3_t1;
      c3_t1 = c3_x[6];
      c3_x[6] = c3_x[7];
      c3_x[7] = c3_t1;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    if (c3_absx31 > c3_absx11) {
      c3_p1 = 6;
      c3_p3 = 0;
      c3_t1 = c3_x[0];
      c3_x[0] = c3_x[2];
      c3_x[2] = c3_t1;
      c3_t1 = c3_x[3];
      c3_x[3] = c3_x[5];
      c3_x[5] = c3_t1;
      c3_t1 = c3_x[6];
      c3_x[6] = c3_x[8];
      c3_x[8] = c3_t1;
    }
  }

  c3_h_x = c3_x[1];
  c3_b_y = c3_x[0];
  c3_z = c3_h_x / c3_b_y;
  c3_x[1] = c3_z;
  c3_i_x = c3_x[2];
  c3_c_y = c3_x[0];
  c3_b_z = c3_i_x / c3_c_y;
  c3_x[2] = c3_b_z;
  c3_a = c3_x[1];
  c3_b = c3_x[3];
  c3_d_y = c3_a * c3_b;
  c3_x[4] -= c3_d_y;
  c3_b_a = c3_x[2];
  c3_b_b = c3_x[3];
  c3_e_y = c3_b_a * c3_b_b;
  c3_x[5] -= c3_e_y;
  c3_c_a = c3_x[1];
  c3_c_b = c3_x[6];
  c3_f_y = c3_c_a * c3_c_b;
  c3_x[7] -= c3_f_y;
  c3_d_a = c3_x[2];
  c3_d_b = c3_x[6];
  c3_g_y = c3_d_a * c3_d_b;
  c3_x[8] -= c3_g_y;
  c3_j_x = c3_x[5];
  c3_k_x = c3_j_x;
  c3_h_y = muDoubleScalarAbs(c3_k_x);
  c3_l_x = c3_x[4];
  c3_m_x = c3_l_x;
  c3_i_y = muDoubleScalarAbs(c3_m_x);
  if (c3_h_y > c3_i_y) {
    c3_itmp = c3_p2;
    c3_p2 = c3_p3;
    c3_p3 = c3_itmp;
    c3_t1 = c3_x[1];
    c3_x[1] = c3_x[2];
    c3_x[2] = c3_t1;
    c3_t1 = c3_x[4];
    c3_x[4] = c3_x[5];
    c3_x[5] = c3_t1;
    c3_t1 = c3_x[7];
    c3_x[7] = c3_x[8];
    c3_x[8] = c3_t1;
  }

  c3_n_x = c3_x[5];
  c3_j_y = c3_x[4];
  c3_c_z = c3_n_x / c3_j_y;
  c3_x[5] = c3_c_z;
  c3_e_a = c3_x[5];
  c3_e_b = c3_x[7];
  c3_k_y = c3_e_a * c3_e_b;
  c3_x[8] -= c3_k_y;
  c3_f_a = c3_x[5];
  c3_f_b = c3_x[1];
  c3_l_y = c3_f_a * c3_f_b;
  c3_o_x = c3_l_y - c3_x[2];
  c3_m_y = c3_x[8];
  c3_t3 = c3_o_x / c3_m_y;
  c3_g_a = c3_x[7];
  c3_g_b = c3_t3;
  c3_n_y = c3_g_a * c3_g_b;
  c3_p_x = -(c3_x[1] + c3_n_y);
  c3_o_y = c3_x[4];
  c3_t2 = c3_p_x / c3_o_y;
  c3_h_a = c3_p1 + 1;
  c3_c = c3_h_a;
  c3_i_a = c3_x[3];
  c3_h_b = c3_t2;
  c3_p_y = c3_i_a * c3_h_b;
  c3_j_a = c3_x[6];
  c3_i_b = c3_t3;
  c3_q_y = c3_j_a * c3_i_b;
  c3_q_x = (1.0 - c3_p_y) - c3_q_y;
  c3_r_y = c3_x[0];
  c3_d_z = c3_q_x / c3_r_y;
  c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_c), 1, 9, 1, 0) - 1] = c3_d_z;
  c3_k_a = c3_p1 + 2;
  c3_b_c = c3_k_a;
  c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_b_c), 1, 9, 1, 0) - 1] = c3_t2;
  c3_l_a = c3_p1 + 3;
  c3_c_c = c3_l_a;
  c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_c_c), 1, 9, 1, 0) - 1] = c3_t3;
  c3_r_x = -c3_x[5];
  c3_s_y = c3_x[8];
  c3_t3 = c3_r_x / c3_s_y;
  c3_m_a = c3_x[7];
  c3_j_b = c3_t3;
  c3_t_y = c3_m_a * c3_j_b;
  c3_s_x = 1.0 - c3_t_y;
  c3_u_y = c3_x[4];
  c3_t2 = c3_s_x / c3_u_y;
  c3_n_a = c3_p2 + 1;
  c3_d_c = c3_n_a;
  c3_o_a = c3_x[3];
  c3_k_b = c3_t2;
  c3_v_y = c3_o_a * c3_k_b;
  c3_p_a = c3_x[6];
  c3_l_b = c3_t3;
  c3_w_y = c3_p_a * c3_l_b;
  c3_t_x = -(c3_v_y + c3_w_y);
  c3_x_y = c3_x[0];
  c3_e_z = c3_t_x / c3_x_y;
  c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_d_c), 1, 9, 1, 0) - 1] = c3_e_z;
  c3_q_a = c3_p2 + 2;
  c3_e_c = c3_q_a;
  c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_e_c), 1, 9, 1, 0) - 1] = c3_t2;
  c3_r_a = c3_p2 + 3;
  c3_f_c = c3_r_a;
  c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_f_c), 1, 9, 1, 0) - 1] = c3_t3;
  c3_y_y = c3_x[8];
  c3_t3 = 1.0 / c3_y_y;
  c3_s_a = -c3_x[7];
  c3_m_b = c3_t3;
  c3_ab_y = c3_s_a * c3_m_b;
  c3_u_x = c3_ab_y;
  c3_bb_y = c3_x[4];
  c3_t2 = c3_u_x / c3_bb_y;
  c3_t_a = c3_p3 + 1;
  c3_g_c = c3_t_a;
  c3_u_a = c3_x[3];
  c3_n_b = c3_t2;
  c3_cb_y = c3_u_a * c3_n_b;
  c3_v_a = c3_x[6];
  c3_o_b = c3_t3;
  c3_db_y = c3_v_a * c3_o_b;
  c3_v_x = -(c3_cb_y + c3_db_y);
  c3_eb_y = c3_x[0];
  c3_f_z = c3_v_x / c3_eb_y;
  c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_g_c), 1, 9, 1, 0) - 1] = c3_f_z;
  c3_w_a = c3_p3 + 2;
  c3_h_c = c3_w_a;
  c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_h_c), 1, 9, 1, 0) - 1] = c3_t2;
  c3_x_a = c3_p3 + 3;
  c3_i_c = c3_x_a;
  c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c3_i_c), 1, 9, 1, 0) - 1] = c3_t3;
}

static real_T c3_norm(SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                      real_T c3_x[9])
{
  real_T c3_y;
  int32_T c3_j;
  real_T c3_b_j;
  real_T c3_s;
  int32_T c3_i;
  real_T c3_b_i;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_b_y;
  real_T c3_d_x;
  boolean_T c3_b;
  boolean_T exitg1;
  c3_y = 0.0;
  c3_j = 0;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (c3_j < 3)) {
    c3_b_j = 1.0 + (real_T)c3_j;
    c3_s = 0.0;
    for (c3_i = 0; c3_i < 3; c3_i++) {
      c3_b_i = 1.0 + (real_T)c3_i;
      c3_b_x = c3_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", c3_b_i), 1, 3, 1, 0) + 3 *
                     (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c3_b_j), 1, 3, 2, 0) - 1)) - 1];
      c3_c_x = c3_b_x;
      c3_b_y = muDoubleScalarAbs(c3_c_x);
      c3_s += c3_b_y;
    }

    c3_d_x = c3_s;
    c3_b = muDoubleScalarIsNaN(c3_d_x);
    if (c3_b) {
      c3_y = rtNaN;
      exitg1 = 1U;
    } else {
      if (c3_s > c3_y) {
        c3_y = c3_s;
      }

      c3_j++;
    }
  }

  return c3_y;
}

static void c3_eml_warning(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
  int32_T c3_i184;
  static char_T c3_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c3_u[27];
  const mxArray *c3_y = NULL;
  for (c3_i184 = 0; c3_i184 < 27; c3_i184++) {
    c3_u[c3_i184] = c3_varargin_1[c3_i184];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 27), FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c3_y));
}

static void c3_b_eml_warning(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, char_T c3_varargin_2[14])
{
  int32_T c3_i185;
  static char_T c3_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c3_u[33];
  const mxArray *c3_y = NULL;
  int32_T c3_i186;
  char_T c3_b_u[14];
  const mxArray *c3_b_y = NULL;
  for (c3_i185 = 0; c3_i185 < 33; c3_i185++) {
    c3_u[c3_i185] = c3_varargin_1[c3_i185];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 33), FALSE);
  for (c3_i186 = 0; c3_i186 < 14; c3_i186++) {
    c3_b_u[c3_i186] = c3_varargin_2[c3_i186];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c3_y, 14, c3_b_y));
}

static void c3_h_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c3_i_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c3_j_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c3_eye(SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
                   real_T c3_I[16])
{
  int32_T c3_i187;
  int32_T c3_i;
  int32_T c3_b_i;
  for (c3_i187 = 0; c3_i187 < 16; c3_i187++) {
    c3_I[c3_i187] = 0.0;
  }

  for (c3_i = 1; c3_i < 5; c3_i++) {
    c3_b_i = c3_i;
    c3_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c3_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c3_b_i), 1, 4, 2, 0) - 1) <<
           2)) - 1] = 1.0;
  }
}

static void c3_k_eml_scalar_eg(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c3_g_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_sprintf, const char_T *c3_identifier, char_T
  c3_y[14])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sprintf), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_sprintf);
}

static void c3_h_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[14])
{
  char_T c3_cv1[14];
  int32_T c3_i188;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c3_i188 = 0; c3_i188 < 14; c3_i188++) {
    c3_y[c3_i188] = c3_cv1[c3_i188];
  }

  sf_mex_destroy(&c3_u);
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_i_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i189;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i189, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i189;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c3_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_sfEvent), &c3_thisId);
  sf_mex_destroy(&c3_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_j_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_is_active_c3_Hquad_control_LIB_MPC, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_is_active_c3_Hquad_control_LIB_MPC), &c3_thisId);
  sf_mex_destroy(&c3_is_active_c3_Hquad_control_LIB_MPC);
  return c3_y;
}

static uint8_T c3_k_emlrt_marshallIn(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info(SFc3_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c3_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2479991458U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4233838231U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3046809639U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3799101334U);
}

mxArray *sf_c3_Hquad_control_LIB_MPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("J0mqXxFMfFQkNyxVlpJ5eH");
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

static const mxArray *sf_get_sim_state_info_c3_Hquad_control_LIB_MPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[29],T\"P_est\",},{M[1],M[5],T\"state_est\",},{M[8],M[0],T\"is_active_c3_Hquad_control_LIB_MPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_Hquad_control_LIB_MPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
    chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Hquad_control_LIB_MPCMachineNumber_,
           3,
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
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          real_T *c3_u;
          real_T (*c3_A)[16];
          real_T (*c3_B)[4];
          real_T (*c3_state_est)[4];
          real_T (*c3_C)[12];
          real_T (*c3_D)[3];
          real_T (*c3_Q)[16];
          real_T (*c3_R)[9];
          real_T (*c3_y)[3];
          real_T (*c3_P)[16];
          real_T (*c3_state)[4];
          real_T (*c3_P_est)[16];
          c3_P_est = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
          c3_state = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 9);
          c3_P = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 8);
          c3_y = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 7);
          c3_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c3_R = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 5);
          c3_Q = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 4);
          c3_D = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c3_C = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 2);
          c3_state_est = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S,
            1);
          c3_B = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c3_A = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_A);
          _SFD_SET_DATA_VALUE_PTR(1U, *c3_B);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_state_est);
          _SFD_SET_DATA_VALUE_PTR(3U, *c3_C);
          _SFD_SET_DATA_VALUE_PTR(4U, *c3_D);
          _SFD_SET_DATA_VALUE_PTR(5U, *c3_Q);
          _SFD_SET_DATA_VALUE_PTR(6U, *c3_R);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_u);
          _SFD_SET_DATA_VALUE_PTR(8U, *c3_y);
          _SFD_SET_DATA_VALUE_PTR(9U, *c3_P);
          _SFD_SET_DATA_VALUE_PTR(10U, *c3_state);
          _SFD_SET_DATA_VALUE_PTR(11U, *c3_P_est);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Hquad_control_LIB_MPCMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S, infoStruct,
      3, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c3_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc3_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc3_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_Hquad_control_LIB_MPC
    ((SFc3_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
  initialize_c3_Hquad_control_LIB_MPC((SFc3_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  enable_c3_Hquad_control_LIB_MPC((SFc3_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  disable_c3_Hquad_control_LIB_MPC((SFc3_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_c3_Hquad_control_LIB_MPC((SFc3_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c3_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  ext_mode_exec_c3_Hquad_control_LIB_MPC
    ((SFc3_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_Hquad_control_LIB_MPC
    ((SFc3_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_Hquad_control_LIB_MPC();/* state var info */
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

extern void sf_internal_set_sim_state_c3_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_Hquad_control_LIB_MPC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_Hquad_control_LIB_MPC
    ((SFc3_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_Hquad_control_LIB_MPC(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c3_Hquad_control_LIB_MPC(S);
}

static void sf_opaque_set_sim_state_c3_Hquad_control_LIB_MPC(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_Hquad_control_LIB_MPC(S, st);
}

static void sf_opaque_terminate_c3_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c3_Hquad_control_LIB_MPC((SFc3_Hquad_control_LIB_MPCInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Hquad_control_LIB_MPC_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_Hquad_control_LIB_MPC
    ((SFc3_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_Hquad_control_LIB_MPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_Hquad_control_LIB_MPC
      ((SFc3_Hquad_control_LIB_MPCInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c3_Hquad_control_LIB_MPC_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c3_Hquad_control_LIB_MPC\",T\"is_active_c3_Hquad_control_LIB_MPC\"}}"
  };

  mxArray *mxTpInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 1, 10);
  return mxTpInfo;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x4'type','isSigned','wordLength','bias','slope','exponent','isComplex','size'{{T\"int32\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"boolean\",,,,,,M[0],M[]},{T\"uint8\",,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 4, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 3851270630U, 3363230343U, 1651207761U,
    946165807U };

  return checksum;
}

static void mdlSetWorkWidths_c3_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,3,
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
      sf_mark_chart_expressionable_inputs(S,infoStruct,3,10);
      sf_mark_chart_reusable_outputs(S,infoStruct,3,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2086503220U));
  ssSetChecksum1(S,(4288819028U));
  ssSetChecksum2(S,(2624312210U));
  ssSetChecksum3(S,(1981670210U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c3_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_Hquad_control_LIB_MPC(SimStruct *S)
{
  SFc3_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc3_Hquad_control_LIB_MPCInstanceStruct *)malloc(sizeof
    (SFc3_Hquad_control_LIB_MPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_Hquad_control_LIB_MPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c3_Hquad_control_LIB_MPC;
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

void c3_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_Hquad_control_LIB_MPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_Hquad_control_LIB_MPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
