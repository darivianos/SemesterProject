/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c27_controller_template.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c27_debug_family_names[18] = { "n", "x_", "P_", "K",
  "nargin", "nargout", "A", "B", "C", "D", "Q", "R", "u", "y", "P", "state",
  "state_est", "P_est" };

/* Function Declarations */
static void initialize_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance);
static void enable_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance);
static void disable_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance);
static void c27_update_debugger_state_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance, const mxArray *c27_st);
static void finalize_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance);
static void sf_c27_controller_template(SFc27_controller_templateInstanceStruct
  *chartInstance);
static void c27_chartstep_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance);
static void initSimStructsc27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber);
static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_P_est, const char_T *c27_identifier, real_T
  c27_y[9]);
static void c27_b_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[9]);
static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_c_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_state_est, const char_T *c27_identifier,
  real_T c27_y[3]);
static void c27_d_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[3]);
static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static const mxArray *c27_e_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static const mxArray *c27_f_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static real_T c27_e_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static const mxArray *c27_g_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static void c27_f_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[6]);
static void c27_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static void c27_info_helper(c27_ResolvedFunctionInfo c27_info[29]);
static void c27_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance);
static void c27_b_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance);
static void c27_c_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance);
static void c27_d_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance);
static void c27_e_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance);
static void c27_mpower(SFc27_controller_templateInstanceStruct *chartInstance,
  real_T c27_a[4], real_T c27_c[4]);
static void c27_matrix_to_integer_power(SFc27_controller_templateInstanceStruct *
  chartInstance, real_T c27_a[4], real_T c27_b, real_T c27_c[4]);
static void c27_f_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance);
static void c27_g_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance);
static real_T c27_norm(SFc27_controller_templateInstanceStruct *chartInstance,
  real_T c27_x[4]);
static void c27_eml_warning(SFc27_controller_templateInstanceStruct
  *chartInstance);
static void c27_b_eml_warning(SFc27_controller_templateInstanceStruct
  *chartInstance, char_T c27_varargin_2[14]);
static void c27_h_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance);
static void c27_i_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance);
static void c27_j_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance);
static void c27_eye(SFc27_controller_templateInstanceStruct *chartInstance,
                    real_T c27_I[9]);
static void c27_k_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance);
static void c27_g_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_sprintf, const char_T *c27_identifier,
  char_T c27_y[14]);
static void c27_h_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  char_T c27_y[14]);
static const mxArray *c27_h_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData);
static int32_T c27_i_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void c27_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData);
static uint8_T c27_j_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_is_active_c27_controller_template, const
  char_T *c27_identifier);
static uint8_T c27_k_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId);
static void init_dsm_address_info(SFc27_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c27_sfEvent;
  uint8_T *c27_is_active_c27_controller_template;
  c27_is_active_c27_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c27_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c27_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c27_is_active_c27_controller_template = 0U;
}

static void initialize_params_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c27_update_debugger_state_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance)
{
  c27_update_debugger_state_c27_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c27_st;
  const mxArray *c27_y = NULL;
  int32_T c27_i0;
  real_T c27_u[9];
  const mxArray *c27_b_y = NULL;
  int32_T c27_i1;
  real_T c27_b_u[3];
  const mxArray *c27_c_y = NULL;
  uint8_T c27_hoistedGlobal;
  uint8_T c27_c_u;
  const mxArray *c27_d_y = NULL;
  uint8_T *c27_is_active_c27_controller_template;
  real_T (*c27_state_est)[3];
  real_T (*c27_P_est)[9];
  c27_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c27_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c27_is_active_c27_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c27_st = NULL;
  c27_st = NULL;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_createcellarray(3), FALSE);
  for (c27_i0 = 0; c27_i0 < 9; c27_i0++) {
    c27_u[c27_i0] = (*c27_P_est)[c27_i0];
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c27_y, 0, c27_b_y);
  for (c27_i1 = 0; c27_i1 < 3; c27_i1++) {
    c27_b_u[c27_i1] = (*c27_state_est)[c27_i1];
  }

  c27_c_y = NULL;
  sf_mex_assign(&c27_c_y, sf_mex_create("y", c27_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c27_y, 1, c27_c_y);
  c27_hoistedGlobal = *c27_is_active_c27_controller_template;
  c27_c_u = c27_hoistedGlobal;
  c27_d_y = NULL;
  sf_mex_assign(&c27_d_y, sf_mex_create("y", &c27_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c27_y, 2, c27_d_y);
  sf_mex_assign(&c27_st, c27_y, FALSE);
  return c27_st;
}

static void set_sim_state_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance, const mxArray *c27_st)
{
  const mxArray *c27_u;
  real_T c27_dv0[9];
  int32_T c27_i2;
  real_T c27_dv1[3];
  int32_T c27_i3;
  boolean_T *c27_doneDoubleBufferReInit;
  uint8_T *c27_is_active_c27_controller_template;
  real_T (*c27_P_est)[9];
  real_T (*c27_state_est)[3];
  c27_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c27_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c27_is_active_c27_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c27_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c27_doneDoubleBufferReInit = TRUE;
  c27_u = sf_mex_dup(c27_st);
  c27_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 0)),
                       "P_est", c27_dv0);
  for (c27_i2 = 0; c27_i2 < 9; c27_i2++) {
    (*c27_P_est)[c27_i2] = c27_dv0[c27_i2];
  }

  c27_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c27_u, 1)),
    "state_est", c27_dv1);
  for (c27_i3 = 0; c27_i3 < 3; c27_i3++) {
    (*c27_state_est)[c27_i3] = c27_dv1[c27_i3];
  }

  *c27_is_active_c27_controller_template = c27_j_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c27_u, 2)), "is_active_c27_controller_template");
  sf_mex_destroy(&c27_u);
  c27_update_debugger_state_c27_controller_template(chartInstance);
  sf_mex_destroy(&c27_st);
}

static void finalize_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c27_controller_template(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
  int32_T c27_i4;
  int32_T c27_i5;
  int32_T c27_i6;
  int32_T c27_i7;
  int32_T c27_i8;
  int32_T c27_i9;
  int32_T c27_i10;
  int32_T c27_i11;
  int32_T c27_i12;
  int32_T c27_i13;
  int32_T c27_i14;
  int32_T *c27_sfEvent;
  real_T *c27_u;
  real_T (*c27_P_est)[9];
  real_T (*c27_state)[3];
  real_T (*c27_P)[9];
  real_T (*c27_y)[2];
  real_T (*c27_R)[4];
  real_T (*c27_Q)[9];
  real_T (*c27_D)[2];
  real_T (*c27_C)[6];
  real_T (*c27_state_est)[3];
  real_T (*c27_B)[3];
  real_T (*c27_A)[9];
  c27_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c27_state = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c27_P = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 8);
  c27_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 7);
  c27_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c27_R = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
  c27_Q = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c27_D = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 3);
  c27_C = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c27_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c27_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c27_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c27_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 18U, *c27_sfEvent);
  for (c27_i4 = 0; c27_i4 < 9; c27_i4++) {
    _SFD_DATA_RANGE_CHECK((*c27_A)[c27_i4], 0U);
  }

  for (c27_i5 = 0; c27_i5 < 3; c27_i5++) {
    _SFD_DATA_RANGE_CHECK((*c27_B)[c27_i5], 1U);
  }

  for (c27_i6 = 0; c27_i6 < 3; c27_i6++) {
    _SFD_DATA_RANGE_CHECK((*c27_state_est)[c27_i6], 2U);
  }

  for (c27_i7 = 0; c27_i7 < 6; c27_i7++) {
    _SFD_DATA_RANGE_CHECK((*c27_C)[c27_i7], 3U);
  }

  for (c27_i8 = 0; c27_i8 < 2; c27_i8++) {
    _SFD_DATA_RANGE_CHECK((*c27_D)[c27_i8], 4U);
  }

  for (c27_i9 = 0; c27_i9 < 9; c27_i9++) {
    _SFD_DATA_RANGE_CHECK((*c27_Q)[c27_i9], 5U);
  }

  for (c27_i10 = 0; c27_i10 < 4; c27_i10++) {
    _SFD_DATA_RANGE_CHECK((*c27_R)[c27_i10], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c27_u, 7U);
  for (c27_i11 = 0; c27_i11 < 2; c27_i11++) {
    _SFD_DATA_RANGE_CHECK((*c27_y)[c27_i11], 8U);
  }

  for (c27_i12 = 0; c27_i12 < 9; c27_i12++) {
    _SFD_DATA_RANGE_CHECK((*c27_P)[c27_i12], 9U);
  }

  for (c27_i13 = 0; c27_i13 < 3; c27_i13++) {
    _SFD_DATA_RANGE_CHECK((*c27_state)[c27_i13], 10U);
  }

  for (c27_i14 = 0; c27_i14 < 9; c27_i14++) {
    _SFD_DATA_RANGE_CHECK((*c27_P_est)[c27_i14], 11U);
  }

  *c27_sfEvent = CALL_EVENT;
  c27_chartstep_c27_controller_template(chartInstance);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c27_chartstep_c27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance)
{
  real_T c27_hoistedGlobal;
  int32_T c27_i15;
  real_T c27_A[9];
  int32_T c27_i16;
  real_T c27_B[3];
  int32_T c27_i17;
  real_T c27_C[6];
  int32_T c27_i18;
  real_T c27_D[2];
  int32_T c27_i19;
  real_T c27_Q[9];
  int32_T c27_i20;
  real_T c27_R[4];
  real_T c27_u;
  int32_T c27_i21;
  real_T c27_y[2];
  int32_T c27_i22;
  real_T c27_P[9];
  int32_T c27_i23;
  real_T c27_state[3];
  uint32_T c27_debug_family_var_map[18];
  real_T c27_n;
  real_T c27_x_[3];
  real_T c27_P_[9];
  real_T c27_K[6];
  real_T c27_nargin = 10.0;
  real_T c27_nargout = 2.0;
  real_T c27_state_est[3];
  real_T c27_P_est[9];
  int32_T c27_i24;
  real_T c27_a[9];
  int32_T c27_i25;
  real_T c27_b[3];
  int32_T c27_i26;
  real_T c27_b_y[3];
  int32_T c27_i27;
  int32_T c27_i28;
  int32_T c27_i29;
  real_T c27_b_b;
  int32_T c27_i30;
  int32_T c27_i31;
  int32_T c27_i32;
  int32_T c27_i33;
  real_T c27_c_b[9];
  int32_T c27_i34;
  int32_T c27_i35;
  int32_T c27_i36;
  real_T c27_c_y[9];
  int32_T c27_i37;
  int32_T c27_i38;
  int32_T c27_i39;
  int32_T c27_i40;
  int32_T c27_i41;
  int32_T c27_i42;
  int32_T c27_i43;
  int32_T c27_i44;
  int32_T c27_i45;
  real_T c27_d_y[9];
  int32_T c27_i46;
  int32_T c27_i47;
  int32_T c27_i48;
  int32_T c27_i49;
  int32_T c27_i50;
  int32_T c27_i51;
  int32_T c27_i52;
  int32_T c27_i53;
  real_T c27_d_b[6];
  int32_T c27_i54;
  int32_T c27_i55;
  int32_T c27_i56;
  real_T c27_e_y[6];
  int32_T c27_i57;
  int32_T c27_i58;
  int32_T c27_i59;
  real_T c27_b_a[6];
  int32_T c27_i60;
  int32_T c27_i61;
  int32_T c27_i62;
  int32_T c27_i63;
  int32_T c27_i64;
  real_T c27_f_y[6];
  int32_T c27_i65;
  int32_T c27_i66;
  int32_T c27_i67;
  int32_T c27_i68;
  int32_T c27_i69;
  int32_T c27_i70;
  int32_T c27_i71;
  int32_T c27_i72;
  int32_T c27_i73;
  int32_T c27_i74;
  real_T c27_g_y[4];
  int32_T c27_i75;
  int32_T c27_i76;
  int32_T c27_i77;
  real_T c27_h_y[4];
  int32_T c27_i78;
  int32_T c27_i79;
  int32_T c27_i80;
  int32_T c27_i81;
  int32_T c27_i82;
  int32_T c27_i83;
  int32_T c27_i84;
  int32_T c27_i85;
  int32_T c27_i86;
  int32_T c27_i87;
  int32_T c27_i88;
  int32_T c27_i89;
  int32_T c27_i90;
  int32_T c27_i91;
  int32_T c27_i92;
  real_T c27_i_y[2];
  int32_T c27_i93;
  int32_T c27_i94;
  int32_T c27_i95;
  int32_T c27_i96;
  int32_T c27_i97;
  int32_T c27_i98;
  int32_T c27_i99;
  int32_T c27_i100;
  int32_T c27_i101;
  int32_T c27_i102;
  int32_T c27_i103;
  int32_T c27_i104;
  int32_T c27_i105;
  int32_T c27_i106;
  int32_T c27_i107;
  int32_T c27_i108;
  int32_T c27_i109;
  int32_T c27_i110;
  int32_T c27_i111;
  int32_T c27_i112;
  int32_T c27_i113;
  int32_T c27_i114;
  int32_T c27_i115;
  int32_T c27_i116;
  int32_T c27_i117;
  int32_T c27_i118;
  int32_T c27_i119;
  int32_T c27_i120;
  int32_T c27_i121;
  int32_T c27_i122;
  int32_T c27_i123;
  real_T *c27_b_u;
  real_T (*c27_b_state_est)[3];
  real_T (*c27_b_P_est)[9];
  real_T (*c27_b_state)[3];
  real_T (*c27_b_P)[9];
  real_T (*c27_j_y)[2];
  real_T (*c27_b_R)[4];
  real_T (*c27_b_Q)[9];
  real_T (*c27_b_D)[2];
  real_T (*c27_b_C)[6];
  real_T (*c27_b_B)[3];
  real_T (*c27_b_A)[9];
  int32_T *c27_sfEvent;
  c27_b_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c27_b_state = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c27_b_P = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 8);
  c27_j_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 7);
  c27_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c27_b_R = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
  c27_b_Q = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c27_b_D = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 3);
  c27_b_C = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c27_b_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c27_b_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c27_b_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c27_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 18U, *c27_sfEvent);
  c27_hoistedGlobal = *c27_b_u;
  for (c27_i15 = 0; c27_i15 < 9; c27_i15++) {
    c27_A[c27_i15] = (*c27_b_A)[c27_i15];
  }

  for (c27_i16 = 0; c27_i16 < 3; c27_i16++) {
    c27_B[c27_i16] = (*c27_b_B)[c27_i16];
  }

  for (c27_i17 = 0; c27_i17 < 6; c27_i17++) {
    c27_C[c27_i17] = (*c27_b_C)[c27_i17];
  }

  for (c27_i18 = 0; c27_i18 < 2; c27_i18++) {
    c27_D[c27_i18] = (*c27_b_D)[c27_i18];
  }

  for (c27_i19 = 0; c27_i19 < 9; c27_i19++) {
    c27_Q[c27_i19] = (*c27_b_Q)[c27_i19];
  }

  for (c27_i20 = 0; c27_i20 < 4; c27_i20++) {
    c27_R[c27_i20] = (*c27_b_R)[c27_i20];
  }

  c27_u = c27_hoistedGlobal;
  for (c27_i21 = 0; c27_i21 < 2; c27_i21++) {
    c27_y[c27_i21] = (*c27_j_y)[c27_i21];
  }

  for (c27_i22 = 0; c27_i22 < 9; c27_i22++) {
    c27_P[c27_i22] = (*c27_b_P)[c27_i22];
  }

  for (c27_i23 = 0; c27_i23 < 3; c27_i23++) {
    c27_state[c27_i23] = (*c27_b_state)[c27_i23];
  }

  sf_debug_symbol_scope_push_eml(0U, 18U, 18U, c27_debug_family_names,
    c27_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c27_n, 0U, c27_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c27_x_, 1U, c27_b_sf_marshallOut,
    c27_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c27_P_, 2U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c27_K, 3U, c27_g_sf_marshallOut,
    c27_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c27_nargin, 4U, c27_d_sf_marshallOut,
    c27_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c27_nargout, 5U,
    c27_d_sf_marshallOut, c27_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c27_A, 6U, c27_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c27_B, 7U, c27_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c27_C, 8U, c27_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c27_D, 9U, c27_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c27_Q, 10U, c27_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c27_R, 11U, c27_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c27_u, 12U, c27_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c27_y, 13U, c27_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c27_P, 14U, c27_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c27_state, 15U, c27_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c27_state_est, 16U,
    c27_b_sf_marshallOut, c27_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c27_P_est, 17U, c27_sf_marshallOut,
    c27_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c27_sfEvent, 7);
  c27_n = 3.0;
  _SFD_EML_CALL(0U, *c27_sfEvent, 10);
  for (c27_i24 = 0; c27_i24 < 9; c27_i24++) {
    c27_a[c27_i24] = c27_A[c27_i24];
  }

  for (c27_i25 = 0; c27_i25 < 3; c27_i25++) {
    c27_b[c27_i25] = c27_state[c27_i25];
  }

  c27_eml_scalar_eg(chartInstance);
  c27_eml_scalar_eg(chartInstance);
  for (c27_i26 = 0; c27_i26 < 3; c27_i26++) {
    c27_b_y[c27_i26] = 0.0;
    c27_i27 = 0;
    for (c27_i28 = 0; c27_i28 < 3; c27_i28++) {
      c27_b_y[c27_i26] += c27_a[c27_i27 + c27_i26] * c27_b[c27_i28];
      c27_i27 += 3;
    }
  }

  for (c27_i29 = 0; c27_i29 < 3; c27_i29++) {
    c27_b[c27_i29] = c27_B[c27_i29];
  }

  c27_b_b = c27_u;
  for (c27_i30 = 0; c27_i30 < 3; c27_i30++) {
    c27_b[c27_i30] *= c27_b_b;
  }

  for (c27_i31 = 0; c27_i31 < 3; c27_i31++) {
    c27_x_[c27_i31] = c27_b_y[c27_i31] + c27_b[c27_i31];
  }

  _SFD_EML_CALL(0U, *c27_sfEvent, 11);
  for (c27_i32 = 0; c27_i32 < 9; c27_i32++) {
    c27_a[c27_i32] = c27_A[c27_i32];
  }

  for (c27_i33 = 0; c27_i33 < 9; c27_i33++) {
    c27_c_b[c27_i33] = c27_P[c27_i33];
  }

  c27_b_eml_scalar_eg(chartInstance);
  c27_b_eml_scalar_eg(chartInstance);
  for (c27_i34 = 0; c27_i34 < 3; c27_i34++) {
    c27_i35 = 0;
    for (c27_i36 = 0; c27_i36 < 3; c27_i36++) {
      c27_c_y[c27_i35 + c27_i34] = 0.0;
      c27_i37 = 0;
      for (c27_i38 = 0; c27_i38 < 3; c27_i38++) {
        c27_c_y[c27_i35 + c27_i34] += c27_a[c27_i37 + c27_i34] * c27_c_b[c27_i38
          + c27_i35];
        c27_i37 += 3;
      }

      c27_i35 += 3;
    }
  }

  c27_i39 = 0;
  for (c27_i40 = 0; c27_i40 < 3; c27_i40++) {
    c27_i41 = 0;
    for (c27_i42 = 0; c27_i42 < 3; c27_i42++) {
      c27_c_b[c27_i42 + c27_i39] = c27_A[c27_i41 + c27_i40];
      c27_i41 += 3;
    }

    c27_i39 += 3;
  }

  c27_b_eml_scalar_eg(chartInstance);
  c27_b_eml_scalar_eg(chartInstance);
  for (c27_i43 = 0; c27_i43 < 3; c27_i43++) {
    c27_i44 = 0;
    for (c27_i45 = 0; c27_i45 < 3; c27_i45++) {
      c27_d_y[c27_i44 + c27_i43] = 0.0;
      c27_i46 = 0;
      for (c27_i47 = 0; c27_i47 < 3; c27_i47++) {
        c27_d_y[c27_i44 + c27_i43] += c27_c_y[c27_i46 + c27_i43] *
          c27_c_b[c27_i47 + c27_i44];
        c27_i46 += 3;
      }

      c27_i44 += 3;
    }
  }

  for (c27_i48 = 0; c27_i48 < 9; c27_i48++) {
    c27_P_[c27_i48] = c27_d_y[c27_i48] + c27_Q[c27_i48];
  }

  _SFD_EML_CALL(0U, *c27_sfEvent, 14);
  for (c27_i49 = 0; c27_i49 < 9; c27_i49++) {
    c27_a[c27_i49] = c27_P_[c27_i49];
  }

  c27_i50 = 0;
  for (c27_i51 = 0; c27_i51 < 2; c27_i51++) {
    c27_i52 = 0;
    for (c27_i53 = 0; c27_i53 < 3; c27_i53++) {
      c27_d_b[c27_i53 + c27_i50] = c27_C[c27_i52 + c27_i51];
      c27_i52 += 2;
    }

    c27_i50 += 3;
  }

  c27_c_eml_scalar_eg(chartInstance);
  c27_c_eml_scalar_eg(chartInstance);
  for (c27_i54 = 0; c27_i54 < 3; c27_i54++) {
    c27_i55 = 0;
    for (c27_i56 = 0; c27_i56 < 2; c27_i56++) {
      c27_e_y[c27_i55 + c27_i54] = 0.0;
      c27_i57 = 0;
      for (c27_i58 = 0; c27_i58 < 3; c27_i58++) {
        c27_e_y[c27_i55 + c27_i54] += c27_a[c27_i57 + c27_i54] * c27_d_b[c27_i58
          + c27_i55];
        c27_i57 += 3;
      }

      c27_i55 += 3;
    }
  }

  for (c27_i59 = 0; c27_i59 < 6; c27_i59++) {
    c27_b_a[c27_i59] = c27_C[c27_i59];
  }

  for (c27_i60 = 0; c27_i60 < 9; c27_i60++) {
    c27_c_b[c27_i60] = c27_P_[c27_i60];
  }

  c27_d_eml_scalar_eg(chartInstance);
  c27_d_eml_scalar_eg(chartInstance);
  for (c27_i61 = 0; c27_i61 < 2; c27_i61++) {
    c27_i62 = 0;
    c27_i63 = 0;
    for (c27_i64 = 0; c27_i64 < 3; c27_i64++) {
      c27_f_y[c27_i62 + c27_i61] = 0.0;
      c27_i65 = 0;
      for (c27_i66 = 0; c27_i66 < 3; c27_i66++) {
        c27_f_y[c27_i62 + c27_i61] += c27_b_a[c27_i65 + c27_i61] *
          c27_c_b[c27_i66 + c27_i63];
        c27_i65 += 2;
      }

      c27_i62 += 2;
      c27_i63 += 3;
    }
  }

  c27_i67 = 0;
  for (c27_i68 = 0; c27_i68 < 2; c27_i68++) {
    c27_i69 = 0;
    for (c27_i70 = 0; c27_i70 < 3; c27_i70++) {
      c27_d_b[c27_i70 + c27_i67] = c27_C[c27_i69 + c27_i68];
      c27_i69 += 2;
    }

    c27_i67 += 3;
  }

  c27_e_eml_scalar_eg(chartInstance);
  c27_e_eml_scalar_eg(chartInstance);
  for (c27_i71 = 0; c27_i71 < 2; c27_i71++) {
    c27_i72 = 0;
    c27_i73 = 0;
    for (c27_i74 = 0; c27_i74 < 2; c27_i74++) {
      c27_g_y[c27_i72 + c27_i71] = 0.0;
      c27_i75 = 0;
      for (c27_i76 = 0; c27_i76 < 3; c27_i76++) {
        c27_g_y[c27_i72 + c27_i71] += c27_f_y[c27_i75 + c27_i71] *
          c27_d_b[c27_i76 + c27_i73];
        c27_i75 += 2;
      }

      c27_i72 += 2;
      c27_i73 += 3;
    }
  }

  for (c27_i77 = 0; c27_i77 < 4; c27_i77++) {
    c27_h_y[c27_i77] = c27_g_y[c27_i77] + c27_R[c27_i77];
  }

  c27_mpower(chartInstance, c27_h_y, c27_g_y);
  c27_h_eml_scalar_eg(chartInstance);
  c27_h_eml_scalar_eg(chartInstance);
  for (c27_i78 = 0; c27_i78 < 6; c27_i78++) {
    c27_K[c27_i78] = 0.0;
  }

  for (c27_i79 = 0; c27_i79 < 6; c27_i79++) {
    c27_K[c27_i79] = 0.0;
  }

  for (c27_i80 = 0; c27_i80 < 6; c27_i80++) {
    c27_d_b[c27_i80] = c27_K[c27_i80];
  }

  for (c27_i81 = 0; c27_i81 < 6; c27_i81++) {
    c27_K[c27_i81] = c27_d_b[c27_i81];
  }

  for (c27_i82 = 0; c27_i82 < 6; c27_i82++) {
    c27_d_b[c27_i82] = c27_K[c27_i82];
  }

  for (c27_i83 = 0; c27_i83 < 6; c27_i83++) {
    c27_K[c27_i83] = c27_d_b[c27_i83];
  }

  for (c27_i84 = 0; c27_i84 < 3; c27_i84++) {
    c27_i85 = 0;
    c27_i86 = 0;
    for (c27_i87 = 0; c27_i87 < 2; c27_i87++) {
      c27_K[c27_i85 + c27_i84] = 0.0;
      c27_i88 = 0;
      for (c27_i89 = 0; c27_i89 < 2; c27_i89++) {
        c27_K[c27_i85 + c27_i84] += c27_e_y[c27_i88 + c27_i84] * c27_g_y[c27_i89
          + c27_i86];
        c27_i88 += 3;
      }

      c27_i85 += 3;
      c27_i86 += 2;
    }
  }

  _SFD_EML_CALL(0U, *c27_sfEvent, 15);
  for (c27_i90 = 0; c27_i90 < 6; c27_i90++) {
    c27_b_a[c27_i90] = c27_C[c27_i90];
  }

  for (c27_i91 = 0; c27_i91 < 3; c27_i91++) {
    c27_b[c27_i91] = c27_x_[c27_i91];
  }

  c27_i_eml_scalar_eg(chartInstance);
  c27_i_eml_scalar_eg(chartInstance);
  for (c27_i92 = 0; c27_i92 < 2; c27_i92++) {
    c27_i_y[c27_i92] = 0.0;
    c27_i93 = 0;
    for (c27_i94 = 0; c27_i94 < 3; c27_i94++) {
      c27_i_y[c27_i92] += c27_b_a[c27_i93 + c27_i92] * c27_b[c27_i94];
      c27_i93 += 2;
    }
  }

  for (c27_i95 = 0; c27_i95 < 6; c27_i95++) {
    c27_d_b[c27_i95] = c27_K[c27_i95];
  }

  for (c27_i96 = 0; c27_i96 < 2; c27_i96++) {
    c27_i_y[c27_i96] = c27_y[c27_i96] - c27_i_y[c27_i96];
  }

  c27_j_eml_scalar_eg(chartInstance);
  c27_j_eml_scalar_eg(chartInstance);
  for (c27_i97 = 0; c27_i97 < 3; c27_i97++) {
    c27_b_y[c27_i97] = 0.0;
    c27_i98 = 0;
    for (c27_i99 = 0; c27_i99 < 2; c27_i99++) {
      c27_b_y[c27_i97] += c27_d_b[c27_i98 + c27_i97] * c27_i_y[c27_i99];
      c27_i98 += 3;
    }
  }

  for (c27_i100 = 0; c27_i100 < 3; c27_i100++) {
    c27_state_est[c27_i100] = c27_x_[c27_i100] + c27_b_y[c27_i100];
  }

  _SFD_EML_CALL(0U, *c27_sfEvent, 16);
  for (c27_i101 = 0; c27_i101 < 6; c27_i101++) {
    c27_d_b[c27_i101] = c27_K[c27_i101];
  }

  for (c27_i102 = 0; c27_i102 < 6; c27_i102++) {
    c27_b_a[c27_i102] = c27_C[c27_i102];
  }

  c27_k_eml_scalar_eg(chartInstance);
  c27_k_eml_scalar_eg(chartInstance);
  for (c27_i103 = 0; c27_i103 < 3; c27_i103++) {
    c27_i104 = 0;
    c27_i105 = 0;
    for (c27_i106 = 0; c27_i106 < 3; c27_i106++) {
      c27_c_y[c27_i104 + c27_i103] = 0.0;
      c27_i107 = 0;
      for (c27_i108 = 0; c27_i108 < 2; c27_i108++) {
        c27_c_y[c27_i104 + c27_i103] += c27_d_b[c27_i107 + c27_i103] *
          c27_b_a[c27_i108 + c27_i105];
        c27_i107 += 3;
      }

      c27_i104 += 3;
      c27_i105 += 2;
    }
  }

  c27_eye(chartInstance, c27_a);
  for (c27_i109 = 0; c27_i109 < 9; c27_i109++) {
    c27_a[c27_i109] -= c27_c_y[c27_i109];
  }

  for (c27_i110 = 0; c27_i110 < 9; c27_i110++) {
    c27_c_b[c27_i110] = c27_P_[c27_i110];
  }

  c27_b_eml_scalar_eg(chartInstance);
  c27_b_eml_scalar_eg(chartInstance);
  for (c27_i111 = 0; c27_i111 < 9; c27_i111++) {
    c27_P_est[c27_i111] = 0.0;
  }

  for (c27_i112 = 0; c27_i112 < 9; c27_i112++) {
    c27_P_est[c27_i112] = 0.0;
  }

  for (c27_i113 = 0; c27_i113 < 9; c27_i113++) {
    c27_d_y[c27_i113] = c27_P_est[c27_i113];
  }

  for (c27_i114 = 0; c27_i114 < 9; c27_i114++) {
    c27_P_est[c27_i114] = c27_d_y[c27_i114];
  }

  for (c27_i115 = 0; c27_i115 < 9; c27_i115++) {
    c27_d_y[c27_i115] = c27_P_est[c27_i115];
  }

  for (c27_i116 = 0; c27_i116 < 9; c27_i116++) {
    c27_P_est[c27_i116] = c27_d_y[c27_i116];
  }

  for (c27_i117 = 0; c27_i117 < 3; c27_i117++) {
    c27_i118 = 0;
    for (c27_i119 = 0; c27_i119 < 3; c27_i119++) {
      c27_P_est[c27_i118 + c27_i117] = 0.0;
      c27_i120 = 0;
      for (c27_i121 = 0; c27_i121 < 3; c27_i121++) {
        c27_P_est[c27_i118 + c27_i117] += c27_a[c27_i120 + c27_i117] *
          c27_c_b[c27_i121 + c27_i118];
        c27_i120 += 3;
      }

      c27_i118 += 3;
    }
  }

  _SFD_EML_CALL(0U, *c27_sfEvent, -16);
  sf_debug_symbol_scope_pop();
  for (c27_i122 = 0; c27_i122 < 3; c27_i122++) {
    (*c27_b_state_est)[c27_i122] = c27_state_est[c27_i122];
  }

  for (c27_i123 = 0; c27_i123 < 9; c27_i123++) {
    (*c27_b_P_est)[c27_i123] = c27_P_est[c27_i123];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, *c27_sfEvent);
}

static void initSimStructsc27_controller_template
  (SFc27_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c27_machineNumber, uint32_T
  c27_chartNumber)
{
}

static const mxArray *c27_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i124;
  int32_T c27_i125;
  int32_T c27_i126;
  real_T c27_b_inData[9];
  int32_T c27_i127;
  int32_T c27_i128;
  int32_T c27_i129;
  real_T c27_u[9];
  const mxArray *c27_y = NULL;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_i124 = 0;
  for (c27_i125 = 0; c27_i125 < 3; c27_i125++) {
    for (c27_i126 = 0; c27_i126 < 3; c27_i126++) {
      c27_b_inData[c27_i126 + c27_i124] = (*(real_T (*)[9])c27_inData)[c27_i126
        + c27_i124];
    }

    c27_i124 += 3;
  }

  c27_i127 = 0;
  for (c27_i128 = 0; c27_i128 < 3; c27_i128++) {
    for (c27_i129 = 0; c27_i129 < 3; c27_i129++) {
      c27_u[c27_i129 + c27_i127] = c27_b_inData[c27_i129 + c27_i127];
    }

    c27_i127 += 3;
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static void c27_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_P_est, const char_T *c27_identifier, real_T
  c27_y[9])
{
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_P_est), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_P_est);
}

static void c27_b_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[9])
{
  real_T c27_dv2[9];
  int32_T c27_i130;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c27_i130 = 0; c27_i130 < 9; c27_i130++) {
    c27_y[c27_i130] = c27_dv2[c27_i130];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_P_est;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y[9];
  int32_T c27_i131;
  int32_T c27_i132;
  int32_T c27_i133;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_P_est = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_P_est), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_P_est);
  c27_i131 = 0;
  for (c27_i132 = 0; c27_i132 < 3; c27_i132++) {
    for (c27_i133 = 0; c27_i133 < 3; c27_i133++) {
      (*(real_T (*)[9])c27_outData)[c27_i133 + c27_i131] = c27_y[c27_i133 +
        c27_i131];
    }

    c27_i131 += 3;
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_b_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i134;
  real_T c27_b_inData[3];
  int32_T c27_i135;
  real_T c27_u[3];
  const mxArray *c27_y = NULL;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  for (c27_i134 = 0; c27_i134 < 3; c27_i134++) {
    c27_b_inData[c27_i134] = (*(real_T (*)[3])c27_inData)[c27_i134];
  }

  for (c27_i135 = 0; c27_i135 < 3; c27_i135++) {
    c27_u[c27_i135] = c27_b_inData[c27_i135];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static void c27_c_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_state_est, const char_T *c27_identifier,
  real_T c27_y[3])
{
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_state_est), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_state_est);
}

static void c27_d_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[3])
{
  real_T c27_dv3[3];
  int32_T c27_i136;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c27_i136 = 0; c27_i136 < 3; c27_i136++) {
    c27_y[c27_i136] = c27_dv3[c27_i136];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_state_est;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y[3];
  int32_T c27_i137;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_state_est = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_state_est), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_state_est);
  for (c27_i137 = 0; c27_i137 < 3; c27_i137++) {
    (*(real_T (*)[3])c27_outData)[c27_i137] = c27_y[c27_i137];
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_c_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i138;
  real_T c27_b_inData[2];
  int32_T c27_i139;
  real_T c27_u[2];
  const mxArray *c27_y = NULL;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  for (c27_i138 = 0; c27_i138 < 2; c27_i138++) {
    c27_b_inData[c27_i138] = (*(real_T (*)[2])c27_inData)[c27_i138];
  }

  for (c27_i139 = 0; c27_i139 < 2; c27_i139++) {
    c27_u[c27_i139] = c27_b_inData[c27_i139];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static const mxArray *c27_d_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  real_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(real_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static const mxArray *c27_e_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i140;
  int32_T c27_i141;
  int32_T c27_i142;
  real_T c27_b_inData[4];
  int32_T c27_i143;
  int32_T c27_i144;
  int32_T c27_i145;
  real_T c27_u[4];
  const mxArray *c27_y = NULL;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_i140 = 0;
  for (c27_i141 = 0; c27_i141 < 2; c27_i141++) {
    for (c27_i142 = 0; c27_i142 < 2; c27_i142++) {
      c27_b_inData[c27_i142 + c27_i140] = (*(real_T (*)[4])c27_inData)[c27_i142
        + c27_i140];
    }

    c27_i140 += 2;
  }

  c27_i143 = 0;
  for (c27_i144 = 0; c27_i144 < 2; c27_i144++) {
    for (c27_i145 = 0; c27_i145 < 2; c27_i145++) {
      c27_u[c27_i145 + c27_i143] = c27_b_inData[c27_i145 + c27_i143];
    }

    c27_i143 += 2;
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static const mxArray *c27_f_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i146;
  int32_T c27_i147;
  int32_T c27_i148;
  real_T c27_b_inData[6];
  int32_T c27_i149;
  int32_T c27_i150;
  int32_T c27_i151;
  real_T c27_u[6];
  const mxArray *c27_y = NULL;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_i146 = 0;
  for (c27_i147 = 0; c27_i147 < 3; c27_i147++) {
    for (c27_i148 = 0; c27_i148 < 2; c27_i148++) {
      c27_b_inData[c27_i148 + c27_i146] = (*(real_T (*)[6])c27_inData)[c27_i148
        + c27_i146];
    }

    c27_i146 += 2;
  }

  c27_i149 = 0;
  for (c27_i150 = 0; c27_i150 < 3; c27_i150++) {
    for (c27_i151 = 0; c27_i151 < 2; c27_i151++) {
      c27_u[c27_i151 + c27_i149] = c27_b_inData[c27_i151 + c27_i149];
    }

    c27_i149 += 2;
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 2, 3), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static real_T c27_e_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  real_T c27_y;
  real_T c27_d0;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_d0, 1, 0, 0U, 0, 0U, 0);
  c27_y = c27_d0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_nargout;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_nargout = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_nargout),
    &c27_thisId);
  sf_mex_destroy(&c27_nargout);
  *(real_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static const mxArray *c27_g_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_i152;
  int32_T c27_i153;
  int32_T c27_i154;
  real_T c27_b_inData[6];
  int32_T c27_i155;
  int32_T c27_i156;
  int32_T c27_i157;
  real_T c27_u[6];
  const mxArray *c27_y = NULL;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_i152 = 0;
  for (c27_i153 = 0; c27_i153 < 2; c27_i153++) {
    for (c27_i154 = 0; c27_i154 < 3; c27_i154++) {
      c27_b_inData[c27_i154 + c27_i152] = (*(real_T (*)[6])c27_inData)[c27_i154
        + c27_i152];
    }

    c27_i152 += 3;
  }

  c27_i155 = 0;
  for (c27_i156 = 0; c27_i156 < 2; c27_i156++) {
    for (c27_i157 = 0; c27_i157 < 3; c27_i157++) {
      c27_u[c27_i157 + c27_i155] = c27_b_inData[c27_i157 + c27_i155];
    }

    c27_i155 += 3;
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 0, 0U, 1U, 0U, 2, 3, 2), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static void c27_f_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  real_T c27_y[6])
{
  real_T c27_dv4[6];
  int32_T c27_i158;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                2);
  for (c27_i158 = 0; c27_i158 < 6; c27_i158++) {
    c27_y[c27_i158] = c27_dv4[c27_i158];
  }

  sf_mex_destroy(&c27_u);
}

static void c27_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_K;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  real_T c27_y[6];
  int32_T c27_i159;
  int32_T c27_i160;
  int32_T c27_i161;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_K = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_K), &c27_thisId, c27_y);
  sf_mex_destroy(&c27_K);
  c27_i159 = 0;
  for (c27_i160 = 0; c27_i160 < 2; c27_i160++) {
    for (c27_i161 = 0; c27_i161 < 3; c27_i161++) {
      (*(real_T (*)[6])c27_outData)[c27_i161 + c27_i159] = c27_y[c27_i161 +
        c27_i159];
    }

    c27_i159 += 3;
  }

  sf_mex_destroy(&c27_mxArrayInData);
}

const mxArray *sf_c27_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c27_nameCaptureInfo;
  c27_ResolvedFunctionInfo c27_info[29];
  const mxArray *c27_m0 = NULL;
  int32_T c27_i162;
  c27_ResolvedFunctionInfo *c27_r0;
  c27_nameCaptureInfo = NULL;
  c27_nameCaptureInfo = NULL;
  c27_info_helper(c27_info);
  sf_mex_assign(&c27_m0, sf_mex_createstruct("nameCaptureInfo", 1, 29), FALSE);
  for (c27_i162 = 0; c27_i162 < 29; c27_i162++) {
    c27_r0 = &c27_info[c27_i162];
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", c27_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c27_r0->context)), "context", "nameCaptureInfo",
                    c27_i162);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", c27_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c27_r0->name)), "name", "nameCaptureInfo",
                    c27_i162);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo",
      c27_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c27_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c27_i162);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", c27_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c27_r0->resolved)), "resolved",
                    "nameCaptureInfo", c27_i162);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", &c27_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c27_i162);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo", &c27_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c27_i162);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo",
      &c27_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c27_i162);
    sf_mex_addfield(c27_m0, sf_mex_create("nameCaptureInfo",
      &c27_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c27_i162);
  }

  sf_mex_assign(&c27_nameCaptureInfo, c27_m0, FALSE);
  return c27_nameCaptureInfo;
}

static void c27_info_helper(c27_ResolvedFunctionInfo c27_info[29])
{
  c27_info[0].context = "";
  c27_info[0].name = "mtimes";
  c27_info[0].dominantType = "double";
  c27_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c27_info[0].fileTimeLo = 1289519692U;
  c27_info[0].fileTimeHi = 0U;
  c27_info[0].mFileTimeLo = 0U;
  c27_info[0].mFileTimeHi = 0U;
  c27_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c27_info[1].name = "eml_index_class";
  c27_info[1].dominantType = "";
  c27_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c27_info[1].fileTimeLo = 1286818778U;
  c27_info[1].fileTimeHi = 0U;
  c27_info[1].mFileTimeLo = 0U;
  c27_info[1].mFileTimeHi = 0U;
  c27_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c27_info[2].name = "eml_scalar_eg";
  c27_info[2].dominantType = "double";
  c27_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c27_info[2].fileTimeLo = 1286818796U;
  c27_info[2].fileTimeHi = 0U;
  c27_info[2].mFileTimeLo = 0U;
  c27_info[2].mFileTimeHi = 0U;
  c27_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c27_info[3].name = "eml_xgemm";
  c27_info[3].dominantType = "int32";
  c27_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c27_info[3].fileTimeLo = 1299076772U;
  c27_info[3].fileTimeHi = 0U;
  c27_info[3].mFileTimeLo = 0U;
  c27_info[3].mFileTimeHi = 0U;
  c27_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c27_info[4].name = "eml_blas_inline";
  c27_info[4].dominantType = "";
  c27_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c27_info[4].fileTimeLo = 1299076768U;
  c27_info[4].fileTimeHi = 0U;
  c27_info[4].mFileTimeLo = 0U;
  c27_info[4].mFileTimeHi = 0U;
  c27_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c27_info[5].name = "eml_refblas_xgemm";
  c27_info[5].dominantType = "int32";
  c27_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c27_info[5].fileTimeLo = 1299076774U;
  c27_info[5].fileTimeHi = 0U;
  c27_info[5].mFileTimeLo = 0U;
  c27_info[5].mFileTimeHi = 0U;
  c27_info[6].context = "";
  c27_info[6].name = "mpower";
  c27_info[6].dominantType = "double";
  c27_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c27_info[6].fileTimeLo = 1286818842U;
  c27_info[6].fileTimeHi = 0U;
  c27_info[6].mFileTimeLo = 0U;
  c27_info[6].mFileTimeHi = 0U;
  c27_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c27_info[7].name = "eml_scalar_floor";
  c27_info[7].dominantType = "double";
  c27_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c27_info[7].fileTimeLo = 1286818726U;
  c27_info[7].fileTimeHi = 0U;
  c27_info[7].mFileTimeLo = 0U;
  c27_info[7].mFileTimeHi = 0U;
  c27_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c27_info[8].name = "eml_scalar_abs";
  c27_info[8].dominantType = "double";
  c27_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c27_info[8].fileTimeLo = 1286818712U;
  c27_info[8].fileTimeHi = 0U;
  c27_info[8].mFileTimeLo = 0U;
  c27_info[8].mFileTimeHi = 0U;
  c27_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c27_info[9].name = "inv";
  c27_info[9].dominantType = "double";
  c27_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c27_info[9].fileTimeLo = 1305318000U;
  c27_info[9].fileTimeHi = 0U;
  c27_info[9].mFileTimeLo = 0U;
  c27_info[9].mFileTimeHi = 0U;
  c27_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c27_info[10].name = "eml_xcabs1";
  c27_info[10].dominantType = "double";
  c27_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c27_info[10].fileTimeLo = 1286818706U;
  c27_info[10].fileTimeHi = 0U;
  c27_info[10].mFileTimeLo = 0U;
  c27_info[10].mFileTimeHi = 0U;
  c27_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c27_info[11].name = "abs";
  c27_info[11].dominantType = "double";
  c27_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c27_info[11].fileTimeLo = 1286818694U;
  c27_info[11].fileTimeHi = 0U;
  c27_info[11].mFileTimeLo = 0U;
  c27_info[11].mFileTimeHi = 0U;
  c27_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c27_info[12].name = "mrdivide";
  c27_info[12].dominantType = "double";
  c27_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c27_info[12].fileTimeLo = 1310137456U;
  c27_info[12].fileTimeHi = 0U;
  c27_info[12].mFileTimeLo = 1289519692U;
  c27_info[12].mFileTimeHi = 0U;
  c27_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c27_info[13].name = "rdivide";
  c27_info[13].dominantType = "double";
  c27_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c27_info[13].fileTimeLo = 1286818844U;
  c27_info[13].fileTimeHi = 0U;
  c27_info[13].mFileTimeLo = 0U;
  c27_info[13].mFileTimeHi = 0U;
  c27_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c27_info[14].name = "eml_div";
  c27_info[14].dominantType = "double";
  c27_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c27_info[14].fileTimeLo = 1305318000U;
  c27_info[14].fileTimeHi = 0U;
  c27_info[14].mFileTimeLo = 0U;
  c27_info[14].mFileTimeHi = 0U;
  c27_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c27_info[15].name = "norm";
  c27_info[15].dominantType = "double";
  c27_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c27_info[15].fileTimeLo = 1286818826U;
  c27_info[15].fileTimeHi = 0U;
  c27_info[15].mFileTimeLo = 0U;
  c27_info[15].mFileTimeHi = 0U;
  c27_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c27_info[16].name = "isnan";
  c27_info[16].dominantType = "double";
  c27_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c27_info[16].fileTimeLo = 1286818760U;
  c27_info[16].fileTimeHi = 0U;
  c27_info[16].mFileTimeLo = 0U;
  c27_info[16].mFileTimeHi = 0U;
  c27_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c27_info[17].name = "eml_guarded_nan";
  c27_info[17].dominantType = "char";
  c27_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c27_info[17].fileTimeLo = 1286818776U;
  c27_info[17].fileTimeHi = 0U;
  c27_info[17].mFileTimeLo = 0U;
  c27_info[17].mFileTimeHi = 0U;
  c27_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c27_info[18].name = "eml_is_float_class";
  c27_info[18].dominantType = "char";
  c27_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c27_info[18].fileTimeLo = 1286818782U;
  c27_info[18].fileTimeHi = 0U;
  c27_info[18].mFileTimeLo = 0U;
  c27_info[18].mFileTimeHi = 0U;
  c27_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c27_info[19].name = "eml_warning";
  c27_info[19].dominantType = "char";
  c27_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c27_info[19].fileTimeLo = 1286818802U;
  c27_info[19].fileTimeHi = 0U;
  c27_info[19].mFileTimeLo = 0U;
  c27_info[19].mFileTimeHi = 0U;
  c27_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c27_info[20].name = "eps";
  c27_info[20].dominantType = "char";
  c27_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c27_info[20].fileTimeLo = 1286818686U;
  c27_info[20].fileTimeHi = 0U;
  c27_info[20].mFileTimeLo = 0U;
  c27_info[20].mFileTimeHi = 0U;
  c27_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c27_info[21].name = "eml_flt2str";
  c27_info[21].dominantType = "double";
  c27_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c27_info[21].fileTimeLo = 1286818776U;
  c27_info[21].fileTimeHi = 0U;
  c27_info[21].mFileTimeLo = 0U;
  c27_info[21].mFileTimeHi = 0U;
  c27_info[22].context = "";
  c27_info[22].name = "eye";
  c27_info[22].dominantType = "double";
  c27_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c27_info[22].fileTimeLo = 1286818688U;
  c27_info[22].fileTimeHi = 0U;
  c27_info[22].mFileTimeLo = 0U;
  c27_info[22].mFileTimeHi = 0U;
  c27_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c27_info[23].name = "eml_assert_valid_size_arg";
  c27_info[23].dominantType = "double";
  c27_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c27_info[23].fileTimeLo = 1286818694U;
  c27_info[23].fileTimeHi = 0U;
  c27_info[23].mFileTimeLo = 0U;
  c27_info[23].mFileTimeHi = 0U;
  c27_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c27_info[24].name = "isinf";
  c27_info[24].dominantType = "double";
  c27_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c27_info[24].fileTimeLo = 1286818760U;
  c27_info[24].fileTimeHi = 0U;
  c27_info[24].mFileTimeLo = 0U;
  c27_info[24].mFileTimeHi = 0U;
  c27_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c27_info[25].name = "intmax";
  c27_info[25].dominantType = "char";
  c27_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c27_info[25].fileTimeLo = 1286818756U;
  c27_info[25].fileTimeHi = 0U;
  c27_info[25].mFileTimeLo = 0U;
  c27_info[25].mFileTimeHi = 0U;
  c27_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c27_info[26].name = "min";
  c27_info[26].dominantType = "double";
  c27_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c27_info[26].fileTimeLo = 1308747330U;
  c27_info[26].fileTimeHi = 0U;
  c27_info[26].mFileTimeLo = 0U;
  c27_info[26].mFileTimeHi = 0U;
  c27_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c27_info[27].name = "eml_min_or_max";
  c27_info[27].dominantType = "char";
  c27_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c27_info[27].fileTimeLo = 1303146212U;
  c27_info[27].fileTimeHi = 0U;
  c27_info[27].mFileTimeLo = 0U;
  c27_info[27].mFileTimeHi = 0U;
  c27_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c27_info[28].name = "eml_scalexp_alloc";
  c27_info[28].dominantType = "double";
  c27_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c27_info[28].fileTimeLo = 1286818796U;
  c27_info[28].fileTimeHi = 0U;
  c27_info[28].mFileTimeLo = 0U;
  c27_info[28].mFileTimeHi = 0U;
}

static void c27_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c27_b_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c27_c_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c27_d_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c27_e_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c27_mpower(SFc27_controller_templateInstanceStruct *chartInstance,
  real_T c27_a[4], real_T c27_c[4])
{
  int32_T c27_i163;
  real_T c27_b_a[4];
  for (c27_i163 = 0; c27_i163 < 4; c27_i163++) {
    c27_b_a[c27_i163] = c27_a[c27_i163];
  }

  c27_matrix_to_integer_power(chartInstance, c27_b_a, -1.0, c27_c);
}

static void c27_matrix_to_integer_power(SFc27_controller_templateInstanceStruct *
  chartInstance, real_T c27_a[4], real_T c27_b, real_T c27_c[4])
{
  real_T c27_x;
  real_T c27_e;
  boolean_T c27_firstmult;
  real_T c27_b_x;
  real_T c27_ed2;
  real_T c27_b_b;
  real_T c27_y;
  int32_T c27_i164;
  int32_T c27_i165;
  real_T c27_A[4];
  int32_T c27_i166;
  int32_T c27_i167;
  int32_T c27_i168;
  int32_T c27_i169;
  int32_T c27_i170;
  int32_T c27_i171;
  real_T c27_c_x;
  real_T c27_d_x;
  real_T c27_e_x;
  real_T c27_b_y;
  real_T c27_f_x;
  real_T c27_g_x;
  real_T c27_c_y;
  real_T c27_d;
  real_T c27_h_x;
  real_T c27_i_x;
  real_T c27_j_x;
  real_T c27_d_y;
  real_T c27_k_x;
  real_T c27_l_x;
  real_T c27_e_y;
  real_T c27_b_d;
  real_T c27_b_A;
  real_T c27_B;
  real_T c27_m_x;
  real_T c27_f_y;
  real_T c27_n_x;
  real_T c27_g_y;
  real_T c27_r;
  real_T c27_b_a;
  real_T c27_c_b;
  real_T c27_h_y;
  real_T c27_b_B;
  real_T c27_i_y;
  real_T c27_j_y;
  real_T c27_t;
  real_T c27_c_A;
  real_T c27_c_B;
  real_T c27_o_x;
  real_T c27_k_y;
  real_T c27_p_x;
  real_T c27_l_y;
  real_T c27_m_y;
  real_T c27_c_a;
  real_T c27_d_b;
  real_T c27_n_y;
  real_T c27_d_A;
  real_T c27_d_B;
  real_T c27_q_x;
  real_T c27_o_y;
  real_T c27_r_x;
  real_T c27_p_y;
  real_T c27_q_y;
  real_T c27_d_a;
  real_T c27_e_b;
  real_T c27_r_y;
  real_T c27_e_a;
  real_T c27_f_b;
  real_T c27_s_y;
  real_T c27_e_A;
  real_T c27_e_B;
  real_T c27_s_x;
  real_T c27_t_y;
  real_T c27_t_x;
  real_T c27_u_y;
  real_T c27_f_a;
  real_T c27_g_b;
  real_T c27_v_y;
  real_T c27_f_B;
  real_T c27_w_y;
  real_T c27_x_y;
  real_T c27_f_A;
  real_T c27_g_B;
  real_T c27_u_x;
  real_T c27_y_y;
  real_T c27_v_x;
  real_T c27_ab_y;
  real_T c27_bb_y;
  real_T c27_g_a;
  real_T c27_h_b;
  real_T c27_cb_y;
  real_T c27_h_a;
  real_T c27_i_b;
  real_T c27_db_y;
  real_T c27_g_A;
  real_T c27_h_B;
  real_T c27_w_x;
  real_T c27_eb_y;
  real_T c27_x_x;
  real_T c27_fb_y;
  real_T c27_gb_y;
  real_T c27_i_a;
  real_T c27_j_b;
  real_T c27_hb_y;
  int32_T c27_i172;
  real_T c27_h_A[4];
  real_T c27_n1x;
  int32_T c27_i173;
  real_T c27_b_c[4];
  real_T c27_n1xinv;
  real_T c27_j_a;
  real_T c27_k_b;
  real_T c27_ib_y;
  real_T c27_rc;
  real_T c27_y_x;
  boolean_T c27_l_b;
  real_T c27_ab_x;
  int32_T c27_i174;
  static char_T c27_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c27_u[8];
  const mxArray *c27_jb_y = NULL;
  real_T c27_b_u;
  const mxArray *c27_kb_y = NULL;
  real_T c27_c_u;
  const mxArray *c27_lb_y = NULL;
  real_T c27_d_u;
  const mxArray *c27_mb_y = NULL;
  char_T c27_str[14];
  int32_T c27_i175;
  char_T c27_b_str[14];
  int32_T c27_i176;
  int32_T c27_i177;
  int32_T c27_i178;
  int32_T c27_i179;
  int32_T c27_i180;
  int32_T c27_i181;
  int32_T c27_i182;
  int32_T c27_k;
  int32_T c27_b_k;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  int32_T exitg1;
  c27_f_eml_scalar_eg(chartInstance);
  c27_x = c27_b;
  c27_e = muDoubleScalarAbs(c27_x);
  if (c27_e > 0.0) {
    c27_firstmult = TRUE;
    do {
      exitg1 = 0U;
      c27_b_x = c27_e / 2.0;
      c27_ed2 = c27_b_x;
      c27_ed2 = muDoubleScalarFloor(c27_ed2);
      c27_b_b = c27_ed2;
      c27_y = 2.0 * c27_b_b;
      if (c27_y != c27_e) {
        if (c27_firstmult) {
          for (c27_i164 = 0; c27_i164 < 4; c27_i164++) {
            c27_c[c27_i164] = c27_a[c27_i164];
          }

          c27_firstmult = FALSE;
        } else {
          c27_g_eml_scalar_eg(chartInstance);
          c27_g_eml_scalar_eg(chartInstance);
          for (c27_i165 = 0; c27_i165 < 4; c27_i165++) {
            c27_A[c27_i165] = c27_c[c27_i165];
          }

          for (c27_i166 = 0; c27_i166 < 2; c27_i166++) {
            c27_i167 = 0;
            for (c27_i168 = 0; c27_i168 < 2; c27_i168++) {
              c27_c[c27_i167 + c27_i166] = 0.0;
              c27_i169 = 0;
              for (c27_i170 = 0; c27_i170 < 2; c27_i170++) {
                c27_c[c27_i167 + c27_i166] += c27_A[c27_i169 + c27_i166] *
                  c27_a[c27_i170 + c27_i167];
                c27_i169 += 2;
              }

              c27_i167 += 2;
            }
          }
        }
      }

      if (c27_ed2 == 0.0) {
        exitg1 = 1U;
      } else {
        c27_e = c27_ed2;
        c27_g_eml_scalar_eg(chartInstance);
        c27_g_eml_scalar_eg(chartInstance);
        for (c27_i176 = 0; c27_i176 < 4; c27_i176++) {
          c27_A[c27_i176] = c27_a[c27_i176];
        }

        for (c27_i177 = 0; c27_i177 < 2; c27_i177++) {
          c27_i178 = 0;
          for (c27_i179 = 0; c27_i179 < 2; c27_i179++) {
            c27_a[c27_i178 + c27_i177] = 0.0;
            c27_i180 = 0;
            for (c27_i181 = 0; c27_i181 < 2; c27_i181++) {
              c27_a[c27_i178 + c27_i177] += c27_A[c27_i180 + c27_i177] *
                c27_A[c27_i181 + c27_i178];
              c27_i180 += 2;
            }

            c27_i178 += 2;
          }
        }
      }
    } while (exitg1 == 0U);

    if (c27_b < 0.0) {
      for (c27_i171 = 0; c27_i171 < 4; c27_i171++) {
        c27_A[c27_i171] = c27_c[c27_i171];
      }

      c27_c_x = c27_A[1];
      c27_d_x = c27_c_x;
      c27_e_x = c27_d_x;
      c27_b_y = muDoubleScalarAbs(c27_e_x);
      c27_f_x = 0.0;
      c27_g_x = c27_f_x;
      c27_c_y = muDoubleScalarAbs(c27_g_x);
      c27_d = c27_b_y + c27_c_y;
      c27_h_x = c27_A[0];
      c27_i_x = c27_h_x;
      c27_j_x = c27_i_x;
      c27_d_y = muDoubleScalarAbs(c27_j_x);
      c27_k_x = 0.0;
      c27_l_x = c27_k_x;
      c27_e_y = muDoubleScalarAbs(c27_l_x);
      c27_b_d = c27_d_y + c27_e_y;
      if (c27_d > c27_b_d) {
        c27_b_A = c27_A[0];
        c27_B = c27_A[1];
        c27_m_x = c27_b_A;
        c27_f_y = c27_B;
        c27_n_x = c27_m_x;
        c27_g_y = c27_f_y;
        c27_r = c27_n_x / c27_g_y;
        c27_b_a = c27_r;
        c27_c_b = c27_A[3];
        c27_h_y = c27_b_a * c27_c_b;
        c27_b_B = c27_h_y - c27_A[2];
        c27_i_y = c27_b_B;
        c27_j_y = c27_i_y;
        c27_t = 1.0 / c27_j_y;
        c27_c_A = c27_A[3];
        c27_c_B = c27_A[1];
        c27_o_x = c27_c_A;
        c27_k_y = c27_c_B;
        c27_p_x = c27_o_x;
        c27_l_y = c27_k_y;
        c27_m_y = c27_p_x / c27_l_y;
        c27_c_a = c27_m_y;
        c27_d_b = c27_t;
        c27_n_y = c27_c_a * c27_d_b;
        c27_c[0] = c27_n_y;
        c27_c[1] = -c27_t;
        c27_d_A = -c27_A[2];
        c27_d_B = c27_A[1];
        c27_q_x = c27_d_A;
        c27_o_y = c27_d_B;
        c27_r_x = c27_q_x;
        c27_p_y = c27_o_y;
        c27_q_y = c27_r_x / c27_p_y;
        c27_d_a = c27_q_y;
        c27_e_b = c27_t;
        c27_r_y = c27_d_a * c27_e_b;
        c27_c[2] = c27_r_y;
        c27_e_a = c27_r;
        c27_f_b = c27_t;
        c27_s_y = c27_e_a * c27_f_b;
        c27_c[3] = c27_s_y;
      } else {
        c27_e_A = c27_A[1];
        c27_e_B = c27_A[0];
        c27_s_x = c27_e_A;
        c27_t_y = c27_e_B;
        c27_t_x = c27_s_x;
        c27_u_y = c27_t_y;
        c27_r = c27_t_x / c27_u_y;
        c27_f_a = c27_r;
        c27_g_b = c27_A[2];
        c27_v_y = c27_f_a * c27_g_b;
        c27_f_B = c27_A[3] - c27_v_y;
        c27_w_y = c27_f_B;
        c27_x_y = c27_w_y;
        c27_t = 1.0 / c27_x_y;
        c27_f_A = c27_A[3];
        c27_g_B = c27_A[0];
        c27_u_x = c27_f_A;
        c27_y_y = c27_g_B;
        c27_v_x = c27_u_x;
        c27_ab_y = c27_y_y;
        c27_bb_y = c27_v_x / c27_ab_y;
        c27_g_a = c27_bb_y;
        c27_h_b = c27_t;
        c27_cb_y = c27_g_a * c27_h_b;
        c27_c[0] = c27_cb_y;
        c27_h_a = -c27_r;
        c27_i_b = c27_t;
        c27_db_y = c27_h_a * c27_i_b;
        c27_c[1] = c27_db_y;
        c27_g_A = -c27_A[2];
        c27_h_B = c27_A[0];
        c27_w_x = c27_g_A;
        c27_eb_y = c27_h_B;
        c27_x_x = c27_w_x;
        c27_fb_y = c27_eb_y;
        c27_gb_y = c27_x_x / c27_fb_y;
        c27_i_a = c27_gb_y;
        c27_j_b = c27_t;
        c27_hb_y = c27_i_a * c27_j_b;
        c27_c[2] = c27_hb_y;
        c27_c[3] = c27_t;
      }

      for (c27_i172 = 0; c27_i172 < 4; c27_i172++) {
        c27_h_A[c27_i172] = c27_A[c27_i172];
      }

      c27_n1x = c27_norm(chartInstance, c27_h_A);
      for (c27_i173 = 0; c27_i173 < 4; c27_i173++) {
        c27_b_c[c27_i173] = c27_c[c27_i173];
      }

      c27_n1xinv = c27_norm(chartInstance, c27_b_c);
      c27_j_a = c27_n1x;
      c27_k_b = c27_n1xinv;
      c27_ib_y = c27_j_a * c27_k_b;
      c27_rc = 1.0 / c27_ib_y;
      guard1 = FALSE;
      guard2 = FALSE;
      if (c27_n1x == 0.0) {
        guard2 = TRUE;
      } else if (c27_n1xinv == 0.0) {
        guard2 = TRUE;
      } else if (c27_rc == 0.0) {
        guard1 = TRUE;
      } else {
        c27_y_x = c27_rc;
        c27_l_b = muDoubleScalarIsNaN(c27_y_x);
        guard3 = FALSE;
        if (c27_l_b) {
          guard3 = TRUE;
        } else {
          if (c27_rc < 2.2204460492503131E-16) {
            guard3 = TRUE;
          }
        }

        if (guard3 == TRUE) {
          c27_ab_x = c27_rc;
          for (c27_i174 = 0; c27_i174 < 8; c27_i174++) {
            c27_u[c27_i174] = c27_cv0[c27_i174];
          }

          c27_jb_y = NULL;
          sf_mex_assign(&c27_jb_y, sf_mex_create("y", c27_u, 10, 0U, 1U, 0U, 2,
            1, 8), FALSE);
          c27_b_u = 14.0;
          c27_kb_y = NULL;
          sf_mex_assign(&c27_kb_y, sf_mex_create("y", &c27_b_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c27_c_u = 6.0;
          c27_lb_y = NULL;
          sf_mex_assign(&c27_lb_y, sf_mex_create("y", &c27_c_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c27_d_u = c27_ab_x;
          c27_mb_y = NULL;
          sf_mex_assign(&c27_mb_y, sf_mex_create("y", &c27_d_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c27_g_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U,
            2U, 14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c27_jb_y, 14,
            c27_kb_y, 14, c27_lb_y), 14, c27_mb_y), "sprintf", c27_str);
          for (c27_i175 = 0; c27_i175 < 14; c27_i175++) {
            c27_b_str[c27_i175] = c27_str[c27_i175];
          }

          c27_b_eml_warning(chartInstance, c27_b_str);
        }
      }

      if (guard2 == TRUE) {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        c27_eml_warning(chartInstance);
      }
    }
  } else {
    for (c27_i182 = 0; c27_i182 < 4; c27_i182++) {
      c27_c[c27_i182] = 0.0;
    }

    for (c27_k = 1; c27_k < 3; c27_k++) {
      c27_b_k = c27_k;
      c27_c[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c27_b_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_b_k), 1, 2, 2, 0) -
               1) << 1)) - 1] = 1.0;
    }
  }
}

static void c27_f_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c27_g_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
}

static real_T c27_norm(SFc27_controller_templateInstanceStruct *chartInstance,
  real_T c27_x[4])
{
  real_T c27_y;
  int32_T c27_j;
  real_T c27_b_j;
  real_T c27_s;
  int32_T c27_i;
  real_T c27_b_i;
  real_T c27_b_x;
  real_T c27_c_x;
  real_T c27_b_y;
  real_T c27_d_x;
  boolean_T c27_b;
  boolean_T exitg1;
  c27_y = 0.0;
  c27_j = 0;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (c27_j < 2)) {
    c27_b_j = 1.0 + (real_T)c27_j;
    c27_s = 0.0;
    for (c27_i = 0; c27_i < 2; c27_i++) {
      c27_b_i = 1.0 + (real_T)c27_i;
      c27_b_x = c27_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c27_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c27_b_j), 1, 2, 2, 0) - 1) << 1)) - 1];
      c27_c_x = c27_b_x;
      c27_b_y = muDoubleScalarAbs(c27_c_x);
      c27_s += c27_b_y;
    }

    c27_d_x = c27_s;
    c27_b = muDoubleScalarIsNaN(c27_d_x);
    if (c27_b) {
      c27_y = rtNaN;
      exitg1 = 1U;
    } else {
      if (c27_s > c27_y) {
        c27_y = c27_s;
      }

      c27_j++;
    }
  }

  return c27_y;
}

static void c27_eml_warning(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
  int32_T c27_i183;
  static char_T c27_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c27_u[27];
  const mxArray *c27_y = NULL;
  for (c27_i183 = 0; c27_i183 < 27; c27_i183++) {
    c27_u[c27_i183] = c27_varargin_1[c27_i183];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 10, 0U, 1U, 0U, 2, 1, 27),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c27_y));
}

static void c27_b_eml_warning(SFc27_controller_templateInstanceStruct
  *chartInstance, char_T c27_varargin_2[14])
{
  int32_T c27_i184;
  static char_T c27_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c27_u[33];
  const mxArray *c27_y = NULL;
  int32_T c27_i185;
  char_T c27_b_u[14];
  const mxArray *c27_b_y = NULL;
  for (c27_i184 = 0; c27_i184 < 33; c27_i184++) {
    c27_u[c27_i184] = c27_varargin_1[c27_i184];
  }

  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", c27_u, 10, 0U, 1U, 0U, 2, 1, 33),
                FALSE);
  for (c27_i185 = 0; c27_i185 < 14; c27_i185++) {
    c27_b_u[c27_i185] = c27_varargin_2[c27_i185];
  }

  c27_b_y = NULL;
  sf_mex_assign(&c27_b_y, sf_mex_create("y", c27_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c27_y, 14, c27_b_y));
}

static void c27_h_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c27_i_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c27_j_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c27_eye(SFc27_controller_templateInstanceStruct *chartInstance,
                    real_T c27_I[9])
{
  int32_T c27_i186;
  int32_T c27_i;
  int32_T c27_b_i;
  for (c27_i186 = 0; c27_i186 < 9; c27_i186++) {
    c27_I[c27_i186] = 0.0;
  }

  for (c27_i = 1; c27_i < 4; c27_i++) {
    c27_b_i = c27_i;
    c27_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c27_b_i), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c27_b_i), 1, 3, 2, 0) - 1))
      - 1] = 1.0;
  }
}

static void c27_k_eml_scalar_eg(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c27_g_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_sprintf, const char_T *c27_identifier,
  char_T c27_y[14])
{
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_sprintf), &c27_thisId,
    c27_y);
  sf_mex_destroy(&c27_sprintf);
}

static void c27_h_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId,
  char_T c27_y[14])
{
  char_T c27_cv1[14];
  int32_T c27_i187;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), c27_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c27_i187 = 0; c27_i187 < 14; c27_i187++) {
    c27_y[c27_i187] = c27_cv1[c27_i187];
  }

  sf_mex_destroy(&c27_u);
}

static const mxArray *c27_h_sf_marshallOut(void *chartInstanceVoid, void
  *c27_inData)
{
  const mxArray *c27_mxArrayOutData = NULL;
  int32_T c27_u;
  const mxArray *c27_y = NULL;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_mxArrayOutData = NULL;
  c27_u = *(int32_T *)c27_inData;
  c27_y = NULL;
  sf_mex_assign(&c27_y, sf_mex_create("y", &c27_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c27_mxArrayOutData, c27_y, FALSE);
  return c27_mxArrayOutData;
}

static int32_T c27_i_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  int32_T c27_y;
  int32_T c27_i188;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_i188, 1, 6, 0U, 0, 0U, 0);
  c27_y = c27_i188;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void c27_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c27_mxArrayInData, const char_T *c27_varName, void *c27_outData)
{
  const mxArray *c27_sfEvent;
  const char_T *c27_identifier;
  emlrtMsgIdentifier c27_thisId;
  int32_T c27_y;
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)chartInstanceVoid;
  c27_sfEvent = sf_mex_dup(c27_mxArrayInData);
  c27_identifier = c27_varName;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c27_sfEvent),
    &c27_thisId);
  sf_mex_destroy(&c27_sfEvent);
  *(int32_T *)c27_outData = c27_y;
  sf_mex_destroy(&c27_mxArrayInData);
}

static uint8_T c27_j_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_is_active_c27_controller_template, const
  char_T *c27_identifier)
{
  uint8_T c27_y;
  emlrtMsgIdentifier c27_thisId;
  c27_thisId.fIdentifier = c27_identifier;
  c27_thisId.fParent = NULL;
  c27_y = c27_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c27_is_active_c27_controller_template), &c27_thisId);
  sf_mex_destroy(&c27_is_active_c27_controller_template);
  return c27_y;
}

static uint8_T c27_k_emlrt_marshallIn(SFc27_controller_templateInstanceStruct
  *chartInstance, const mxArray *c27_u, const emlrtMsgIdentifier *c27_parentId)
{
  uint8_T c27_y;
  uint8_T c27_u0;
  sf_mex_import(c27_parentId, sf_mex_dup(c27_u), &c27_u0, 1, 3, 0U, 0, 0U, 0);
  c27_y = c27_u0;
  sf_mex_destroy(&c27_u);
  return c27_y;
}

static void init_dsm_address_info(SFc27_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c27_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2189853427U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2730128856U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1447956719U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1158677693U);
}

mxArray *sf_c27_controller_template_get_autoinheritance_info(void)
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

static const mxArray *sf_get_sim_state_info_c27_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[29],T\"P_est\",},{M[1],M[5],T\"state_est\",},{M[8],M[0],T\"is_active_c27_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c27_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc27_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc27_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           27,
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
          init_script_number_translation(_controller_templateMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_controller_templateMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_controller_templateMachineNumber_,
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
            1.0,0,0,(MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)
            c27_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c27_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c27_sf_marshallOut,(MexInFcnForType)
            c27_sf_marshallIn);
        }

        {
          real_T *c27_u;
          real_T (*c27_A)[9];
          real_T (*c27_B)[3];
          real_T (*c27_state_est)[3];
          real_T (*c27_C)[6];
          real_T (*c27_D)[2];
          real_T (*c27_Q)[9];
          real_T (*c27_R)[4];
          real_T (*c27_y)[2];
          real_T (*c27_P)[9];
          real_T (*c27_state)[3];
          real_T (*c27_P_est)[9];
          c27_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c27_state = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
          c27_P = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 8);
          c27_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 7);
          c27_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c27_R = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
          c27_Q = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
          c27_D = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 3);
          c27_C = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
          c27_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            1);
          c27_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c27_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c27_A);
          _SFD_SET_DATA_VALUE_PTR(1U, *c27_B);
          _SFD_SET_DATA_VALUE_PTR(2U, *c27_state_est);
          _SFD_SET_DATA_VALUE_PTR(3U, *c27_C);
          _SFD_SET_DATA_VALUE_PTR(4U, *c27_D);
          _SFD_SET_DATA_VALUE_PTR(5U, *c27_Q);
          _SFD_SET_DATA_VALUE_PTR(6U, *c27_R);
          _SFD_SET_DATA_VALUE_PTR(7U, c27_u);
          _SFD_SET_DATA_VALUE_PTR(8U, *c27_y);
          _SFD_SET_DATA_VALUE_PTR(9U, *c27_P);
          _SFD_SET_DATA_VALUE_PTR(10U, *c27_state);
          _SFD_SET_DATA_VALUE_PTR(11U, *c27_P_est);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_controller_templateMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_controller_template_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S, infoStruct,
      27, "dworkChecksum");
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

static void sf_opaque_initialize_c27_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc27_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc27_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c27_controller_template
    ((SFc27_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c27_controller_template((SFc27_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c27_controller_template(void *chartInstanceVar)
{
  enable_c27_controller_template((SFc27_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c27_controller_template(void *chartInstanceVar)
{
  disable_c27_controller_template((SFc27_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c27_controller_template(void *chartInstanceVar)
{
  sf_c27_controller_template((SFc27_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c27_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c27_controller_template((SFc27_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c27_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c27_controller_template
    ((SFc27_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c27_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c27_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c27_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c27_controller_template((SFc27_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c27_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c27_controller_template(S);
}

static void sf_opaque_set_sim_state_c27_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c27_controller_template(S, st);
}

static void sf_opaque_terminate_c27_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc27_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c27_controller_template((SFc27_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc27_controller_template((SFc27_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c27_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c27_controller_template
      ((SFc27_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c27_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c27_controller_template\",T\"is_active_c27_controller_template\"}}"
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

static void mdlSetWorkWidths_c27_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,27);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,27,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,27,
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
      sf_mark_chart_expressionable_inputs(S,infoStruct,27,10);
      sf_mark_chart_reusable_outputs(S,infoStruct,27,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,27);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(237375345U));
  ssSetChecksum1(S,(3739561383U));
  ssSetChecksum2(S,(1666305668U));
  ssSetChecksum3(S,(385915697U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c27_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c27_controller_template(SimStruct *S)
{
  SFc27_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc27_controller_templateInstanceStruct *)malloc(sizeof
    (SFc27_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc27_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c27_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c27_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c27_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c27_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c27_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c27_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c27_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c27_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c27_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c27_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c27_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c27_controller_template;
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

void c27_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c27_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c27_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c27_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c27_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
