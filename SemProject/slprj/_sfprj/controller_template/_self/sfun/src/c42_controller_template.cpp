/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c42_controller_template.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c42_debug_family_names[18] = { "x_pred", "P_pred", "K",
  "nargin", "nargout", "Ax", "Bx", "Cx", "u", "z", "x_prev", "P_prev", "Qp",
  "Rn", "flag_init", "flag_fault", "x_meas", "Pmeas" };

/* Function Declarations */
static void initialize_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance);
static void enable_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance);
static void disable_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance);
static void c42_update_debugger_state_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance, const mxArray *c42_st);
static void finalize_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance);
static void sf_c42_controller_template(SFc42_controller_templateInstanceStruct
  *chartInstance);
static void c42_chartstep_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance);
static void initSimStructsc42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c42_machineNumber, uint32_T
  c42_chartNumber);
static const mxArray *c42_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static void c42_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_Pmeas, const char_T *c42_identifier, real_T
  c42_y[16]);
static void c42_b_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId,
  real_T c42_y[16]);
static void c42_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static const mxArray *c42_b_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static void c42_c_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_x_meas, const char_T *c42_identifier,
  real_T c42_y[4]);
static void c42_d_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId,
  real_T c42_y[4]);
static void c42_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static const mxArray *c42_c_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static real_T c42_e_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId);
static void c42_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static void c42_info_helper(c42_ResolvedFunctionInfo c42_info[48]);
static void c42_eml_scalar_eg(SFc42_controller_templateInstanceStruct
  *chartInstance);
static void c42_b_eml_scalar_eg(SFc42_controller_templateInstanceStruct
  *chartInstance);
static void c42_mrdivide(SFc42_controller_templateInstanceStruct *chartInstance,
  real_T c42_A[16], real_T c42_B[16], real_T c42_y[16]);
static void c42_eps(SFc42_controller_templateInstanceStruct *chartInstance);
static void c42_eml_matlab_zgetrf(SFc42_controller_templateInstanceStruct
  *chartInstance, real_T c42_A[16], real_T c42_b_A[16], int32_T c42_ipiv[4],
  int32_T *c42_info);
static void c42_eml_xgeru(SFc42_controller_templateInstanceStruct *chartInstance,
  int32_T c42_m, int32_T c42_n, real_T c42_alpha1, int32_T c42_ix0, int32_T
  c42_iy0, real_T c42_A[16], int32_T c42_ia0, real_T c42_b_A[16]);
static void c42_eml_warning(SFc42_controller_templateInstanceStruct
  *chartInstance);
static void c42_eml_xtrsm(SFc42_controller_templateInstanceStruct *chartInstance,
  real_T c42_A[16], real_T c42_B[16], real_T c42_b_B[16]);
static void c42_below_threshold(SFc42_controller_templateInstanceStruct
  *chartInstance);
static void c42_c_eml_scalar_eg(SFc42_controller_templateInstanceStruct
  *chartInstance);
static void c42_eye(SFc42_controller_templateInstanceStruct *chartInstance,
                    real_T c42_I[16]);
static const mxArray *c42_d_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData);
static int32_T c42_f_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId);
static void c42_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData);
static uint8_T c42_g_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_is_active_c42_controller_template, const
  char_T *c42_identifier);
static uint8_T c42_h_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId);
static void c42_b_eml_matlab_zgetrf(SFc42_controller_templateInstanceStruct
  *chartInstance, real_T c42_A[16], int32_T c42_ipiv[4], int32_T *c42_info);
static void c42_b_eml_xgeru(SFc42_controller_templateInstanceStruct
  *chartInstance, int32_T c42_m, int32_T c42_n, real_T c42_alpha1, int32_T
  c42_ix0, int32_T c42_iy0, real_T c42_A[16], int32_T c42_ia0);
static void c42_b_eml_xtrsm(SFc42_controller_templateInstanceStruct
  *chartInstance, real_T c42_A[16], real_T c42_B[16]);
static void init_dsm_address_info(SFc42_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c42_sfEvent;
  uint8_T *c42_is_active_c42_controller_template;
  c42_is_active_c42_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c42_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c42_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c42_is_active_c42_controller_template = 0U;
}

static void initialize_params_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c42_update_debugger_state_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance)
{
  c42_update_debugger_state_c42_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c42_st;
  const mxArray *c42_y = NULL;
  int32_T c42_i0;
  real_T c42_u[16];
  const mxArray *c42_b_y = NULL;
  int32_T c42_i1;
  real_T c42_b_u[4];
  const mxArray *c42_c_y = NULL;
  uint8_T c42_hoistedGlobal;
  uint8_T c42_c_u;
  const mxArray *c42_d_y = NULL;
  uint8_T *c42_is_active_c42_controller_template;
  real_T (*c42_x_meas)[4];
  real_T (*c42_Pmeas)[16];
  c42_Pmeas = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
  c42_x_meas = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c42_is_active_c42_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c42_st = NULL;
  c42_st = NULL;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_createcellarray(3), FALSE);
  for (c42_i0 = 0; c42_i0 < 16; c42_i0++) {
    c42_u[c42_i0] = (*c42_Pmeas)[c42_i0];
  }

  c42_b_y = NULL;
  sf_mex_assign(&c42_b_y, sf_mex_create("y", c42_u, 0, 0U, 1U, 0U, 2, 4, 4),
                FALSE);
  sf_mex_setcell(c42_y, 0, c42_b_y);
  for (c42_i1 = 0; c42_i1 < 4; c42_i1++) {
    c42_b_u[c42_i1] = (*c42_x_meas)[c42_i1];
  }

  c42_c_y = NULL;
  sf_mex_assign(&c42_c_y, sf_mex_create("y", c42_b_u, 0, 0U, 1U, 0U, 1, 4),
                FALSE);
  sf_mex_setcell(c42_y, 1, c42_c_y);
  c42_hoistedGlobal = *c42_is_active_c42_controller_template;
  c42_c_u = c42_hoistedGlobal;
  c42_d_y = NULL;
  sf_mex_assign(&c42_d_y, sf_mex_create("y", &c42_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c42_y, 2, c42_d_y);
  sf_mex_assign(&c42_st, c42_y, FALSE);
  return c42_st;
}

static void set_sim_state_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance, const mxArray *c42_st)
{
  const mxArray *c42_u;
  real_T c42_dv0[16];
  int32_T c42_i2;
  real_T c42_dv1[4];
  int32_T c42_i3;
  boolean_T *c42_doneDoubleBufferReInit;
  uint8_T *c42_is_active_c42_controller_template;
  real_T (*c42_Pmeas)[16];
  real_T (*c42_x_meas)[4];
  c42_Pmeas = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
  c42_x_meas = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c42_is_active_c42_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c42_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c42_doneDoubleBufferReInit = TRUE;
  c42_u = sf_mex_dup(c42_st);
  c42_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c42_u, 0)),
                       "Pmeas", c42_dv0);
  for (c42_i2 = 0; c42_i2 < 16; c42_i2++) {
    (*c42_Pmeas)[c42_i2] = c42_dv0[c42_i2];
  }

  c42_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c42_u, 1)),
    "x_meas", c42_dv1);
  for (c42_i3 = 0; c42_i3 < 4; c42_i3++) {
    (*c42_x_meas)[c42_i3] = c42_dv1[c42_i3];
  }

  *c42_is_active_c42_controller_template = c42_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c42_u, 2)), "is_active_c42_controller_template");
  sf_mex_destroy(&c42_u);
  c42_update_debugger_state_c42_controller_template(chartInstance);
  sf_mex_destroy(&c42_st);
}

static void finalize_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c42_controller_template(SFc42_controller_templateInstanceStruct
  *chartInstance)
{
  int32_T c42_i4;
  int32_T c42_i5;
  int32_T c42_i6;
  int32_T c42_i7;
  int32_T c42_i8;
  int32_T c42_i9;
  int32_T c42_i10;
  int32_T c42_i11;
  int32_T c42_i12;
  int32_T c42_i13;
  int32_T *c42_sfEvent;
  real_T *c42_u;
  real_T *c42_flag_init;
  real_T *c42_flag_fault;
  real_T (*c42_Pmeas)[16];
  real_T (*c42_Rn)[16];
  real_T (*c42_Qp)[16];
  real_T (*c42_P_prev)[16];
  real_T (*c42_x_prev)[4];
  real_T (*c42_z)[4];
  real_T (*c42_x_meas)[4];
  real_T (*c42_Cx)[16];
  real_T (*c42_Bx)[4];
  real_T (*c42_Ax)[16];
  c42_Pmeas = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
  c42_flag_fault = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c42_flag_init = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c42_Rn = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 8);
  c42_Qp = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 7);
  c42_P_prev = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 6);
  c42_x_prev = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
  c42_z = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c42_x_meas = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c42_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c42_Cx = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 2);
  c42_Bx = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c42_Ax = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  c42_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 41U, *c42_sfEvent);
  for (c42_i4 = 0; c42_i4 < 16; c42_i4++) {
    _SFD_DATA_RANGE_CHECK((*c42_Ax)[c42_i4], 0U);
  }

  for (c42_i5 = 0; c42_i5 < 4; c42_i5++) {
    _SFD_DATA_RANGE_CHECK((*c42_Bx)[c42_i5], 1U);
  }

  for (c42_i6 = 0; c42_i6 < 16; c42_i6++) {
    _SFD_DATA_RANGE_CHECK((*c42_Cx)[c42_i6], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c42_u, 3U);
  for (c42_i7 = 0; c42_i7 < 4; c42_i7++) {
    _SFD_DATA_RANGE_CHECK((*c42_x_meas)[c42_i7], 4U);
  }

  for (c42_i8 = 0; c42_i8 < 4; c42_i8++) {
    _SFD_DATA_RANGE_CHECK((*c42_z)[c42_i8], 5U);
  }

  for (c42_i9 = 0; c42_i9 < 4; c42_i9++) {
    _SFD_DATA_RANGE_CHECK((*c42_x_prev)[c42_i9], 6U);
  }

  for (c42_i10 = 0; c42_i10 < 16; c42_i10++) {
    _SFD_DATA_RANGE_CHECK((*c42_P_prev)[c42_i10], 7U);
  }

  for (c42_i11 = 0; c42_i11 < 16; c42_i11++) {
    _SFD_DATA_RANGE_CHECK((*c42_Qp)[c42_i11], 8U);
  }

  for (c42_i12 = 0; c42_i12 < 16; c42_i12++) {
    _SFD_DATA_RANGE_CHECK((*c42_Rn)[c42_i12], 9U);
  }

  _SFD_DATA_RANGE_CHECK(*c42_flag_init, 10U);
  _SFD_DATA_RANGE_CHECK(*c42_flag_fault, 11U);
  for (c42_i13 = 0; c42_i13 < 16; c42_i13++) {
    _SFD_DATA_RANGE_CHECK((*c42_Pmeas)[c42_i13], 12U);
  }

  *c42_sfEvent = CALL_EVENT;
  c42_chartstep_c42_controller_template(chartInstance);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c42_chartstep_c42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance)
{
  real_T c42_hoistedGlobal;
  real_T c42_b_hoistedGlobal;
  real_T c42_c_hoistedGlobal;
  int32_T c42_i14;
  real_T c42_Ax[16];
  int32_T c42_i15;
  real_T c42_Bx[4];
  int32_T c42_i16;
  real_T c42_Cx[16];
  real_T c42_u;
  int32_T c42_i17;
  real_T c42_z[4];
  int32_T c42_i18;
  real_T c42_x_prev[4];
  int32_T c42_i19;
  real_T c42_P_prev[16];
  int32_T c42_i20;
  real_T c42_Qp[16];
  int32_T c42_i21;
  real_T c42_Rn[16];
  real_T c42_flag_init;
  real_T c42_flag_fault;
  uint32_T c42_debug_family_var_map[18];
  real_T c42_x_pred[4];
  real_T c42_P_pred[16];
  real_T c42_K[16];
  real_T c42_nargin = 11.0;
  real_T c42_nargout = 2.0;
  real_T c42_x_meas[4];
  real_T c42_Pmeas[16];
  int32_T c42_i22;
  real_T c42_b[4];
  real_T c42_b_b;
  int32_T c42_i23;
  int32_T c42_i24;
  int32_T c42_i25;
  real_T c42_a[16];
  int32_T c42_i26;
  int32_T c42_i27;
  real_T c42_y[4];
  int32_T c42_i28;
  int32_T c42_i29;
  int32_T c42_i30;
  real_T c42_c_b;
  int32_T c42_i31;
  int32_T c42_i32;
  int32_T c42_i33;
  int32_T c42_i34;
  real_T c42_d_b[16];
  int32_T c42_i35;
  int32_T c42_i36;
  int32_T c42_i37;
  real_T c42_b_y[16];
  int32_T c42_i38;
  int32_T c42_i39;
  int32_T c42_i40;
  int32_T c42_i41;
  int32_T c42_i42;
  int32_T c42_i43;
  int32_T c42_i44;
  int32_T c42_i45;
  int32_T c42_i46;
  real_T c42_c_y[16];
  int32_T c42_i47;
  int32_T c42_i48;
  int32_T c42_i49;
  int32_T c42_i50;
  int32_T c42_i51;
  int32_T c42_i52;
  int32_T c42_i53;
  int32_T c42_i54;
  int32_T c42_i55;
  int32_T c42_i56;
  int32_T c42_i57;
  int32_T c42_i58;
  int32_T c42_i59;
  int32_T c42_i60;
  int32_T c42_i61;
  int32_T c42_i62;
  int32_T c42_i63;
  int32_T c42_i64;
  int32_T c42_i65;
  int32_T c42_i66;
  int32_T c42_i67;
  int32_T c42_i68;
  int32_T c42_i69;
  int32_T c42_i70;
  int32_T c42_i71;
  int32_T c42_i72;
  int32_T c42_i73;
  int32_T c42_i74;
  int32_T c42_i75;
  int32_T c42_i76;
  real_T c42_d_y[16];
  int32_T c42_i77;
  real_T c42_b_a[16];
  real_T c42_dv2[16];
  int32_T c42_i78;
  int32_T c42_i79;
  int32_T c42_i80;
  int32_T c42_i81;
  int32_T c42_i82;
  int32_T c42_i83;
  int32_T c42_i84;
  int32_T c42_i85;
  int32_T c42_i86;
  int32_T c42_i87;
  int32_T c42_i88;
  int32_T c42_i89;
  int32_T c42_i90;
  int32_T c42_i91;
  int32_T c42_i92;
  int32_T c42_i93;
  int32_T c42_i94;
  int32_T c42_i95;
  int32_T c42_i96;
  int32_T c42_i97;
  int32_T c42_i98;
  int32_T c42_i99;
  int32_T c42_i100;
  int32_T c42_i101;
  int32_T c42_i102;
  int32_T c42_i103;
  int32_T c42_i104;
  int32_T c42_i105;
  int32_T c42_i106;
  int32_T c42_i107;
  int32_T c42_i108;
  int32_T c42_i109;
  int32_T c42_i110;
  int32_T c42_i111;
  int32_T c42_i112;
  int32_T c42_i113;
  int32_T c42_i114;
  int32_T c42_i115;
  int32_T c42_i116;
  int32_T c42_i117;
  int32_T c42_i118;
  int32_T c42_i119;
  int32_T c42_i120;
  int32_T c42_i121;
  int32_T c42_i122;
  int32_T c42_i123;
  int32_T c42_i124;
  int32_T c42_i125;
  int32_T c42_i126;
  int32_T c42_i127;
  int32_T c42_i128;
  int32_T c42_i129;
  int32_T c42_i130;
  int32_T c42_i131;
  int32_T c42_i132;
  int32_T c42_i133;
  int32_T c42_i134;
  int32_T c42_i135;
  int32_T c42_i136;
  int32_T c42_i137;
  int32_T c42_i138;
  real_T *c42_b_u;
  real_T *c42_b_flag_init;
  real_T *c42_b_flag_fault;
  real_T (*c42_b_x_meas)[4];
  real_T (*c42_b_Pmeas)[16];
  real_T (*c42_b_Rn)[16];
  real_T (*c42_b_Qp)[16];
  real_T (*c42_b_P_prev)[16];
  real_T (*c42_b_x_prev)[4];
  real_T (*c42_b_z)[4];
  real_T (*c42_b_Cx)[16];
  real_T (*c42_b_Bx)[4];
  real_T (*c42_b_Ax)[16];
  int32_T *c42_sfEvent;
  c42_b_Pmeas = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
  c42_b_flag_fault = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
  c42_b_flag_init = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
  c42_b_Rn = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 8);
  c42_b_Qp = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 7);
  c42_b_P_prev = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 6);
  c42_b_x_prev = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
  c42_b_z = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c42_b_x_meas = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c42_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c42_b_Cx = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 2);
  c42_b_Bx = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
  c42_b_Ax = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
  c42_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 41U, *c42_sfEvent);
  c42_hoistedGlobal = *c42_b_u;
  c42_b_hoistedGlobal = *c42_b_flag_init;
  c42_c_hoistedGlobal = *c42_b_flag_fault;
  for (c42_i14 = 0; c42_i14 < 16; c42_i14++) {
    c42_Ax[c42_i14] = (*c42_b_Ax)[c42_i14];
  }

  for (c42_i15 = 0; c42_i15 < 4; c42_i15++) {
    c42_Bx[c42_i15] = (*c42_b_Bx)[c42_i15];
  }

  for (c42_i16 = 0; c42_i16 < 16; c42_i16++) {
    c42_Cx[c42_i16] = (*c42_b_Cx)[c42_i16];
  }

  c42_u = c42_hoistedGlobal;
  for (c42_i17 = 0; c42_i17 < 4; c42_i17++) {
    c42_z[c42_i17] = (*c42_b_z)[c42_i17];
  }

  for (c42_i18 = 0; c42_i18 < 4; c42_i18++) {
    c42_x_prev[c42_i18] = (*c42_b_x_prev)[c42_i18];
  }

  for (c42_i19 = 0; c42_i19 < 16; c42_i19++) {
    c42_P_prev[c42_i19] = (*c42_b_P_prev)[c42_i19];
  }

  for (c42_i20 = 0; c42_i20 < 16; c42_i20++) {
    c42_Qp[c42_i20] = (*c42_b_Qp)[c42_i20];
  }

  for (c42_i21 = 0; c42_i21 < 16; c42_i21++) {
    c42_Rn[c42_i21] = (*c42_b_Rn)[c42_i21];
  }

  c42_flag_init = c42_b_hoistedGlobal;
  c42_flag_fault = c42_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 18U, 18U, c42_debug_family_names,
    c42_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(c42_x_pred, 0U, c42_b_sf_marshallOut,
    c42_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c42_P_pred, 1U, c42_sf_marshallOut,
    c42_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c42_K, 2U, c42_sf_marshallOut,
    c42_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c42_nargin, 3U, c42_c_sf_marshallOut,
    c42_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c42_nargout, 4U,
    c42_c_sf_marshallOut, c42_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c42_Ax, 5U, c42_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c42_Bx, 6U, c42_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c42_Cx, 7U, c42_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c42_u, 8U, c42_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c42_z, 9U, c42_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c42_x_prev, 10U, c42_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c42_P_prev, 11U, c42_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c42_Qp, 12U, c42_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c42_Rn, 13U, c42_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c42_flag_init, 14U, c42_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c42_flag_fault, 15U, c42_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c42_x_meas, 16U, c42_b_sf_marshallOut,
    c42_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c42_Pmeas, 17U, c42_sf_marshallOut,
    c42_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c42_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, c42_flag_init != 0.0) != 0.0) {
    _SFD_EML_CALL(0U, *c42_sfEvent, 7);
    for (c42_i22 = 0; c42_i22 < 4; c42_i22++) {
      c42_b[c42_i22] = c42_Bx[c42_i22];
    }

    c42_b_b = c42_u;
    for (c42_i23 = 0; c42_i23 < 4; c42_i23++) {
      c42_x_pred[c42_i23] = c42_b[c42_i23] * c42_b_b;
    }

    _SFD_EML_CALL(0U, *c42_sfEvent, 8);
    for (c42_i24 = 0; c42_i24 < 16; c42_i24++) {
      c42_P_pred[c42_i24] = c42_Qp[c42_i24];
    }
  } else {
    _SFD_EML_CALL(0U, *c42_sfEvent, 10);
    for (c42_i25 = 0; c42_i25 < 16; c42_i25++) {
      c42_a[c42_i25] = c42_Ax[c42_i25];
    }

    for (c42_i26 = 0; c42_i26 < 4; c42_i26++) {
      c42_b[c42_i26] = c42_x_prev[c42_i26];
    }

    c42_eml_scalar_eg(chartInstance);
    c42_eml_scalar_eg(chartInstance);
    for (c42_i27 = 0; c42_i27 < 4; c42_i27++) {
      c42_y[c42_i27] = 0.0;
      c42_i28 = 0;
      for (c42_i29 = 0; c42_i29 < 4; c42_i29++) {
        c42_y[c42_i27] += c42_a[c42_i28 + c42_i27] * c42_b[c42_i29];
        c42_i28 += 4;
      }
    }

    for (c42_i30 = 0; c42_i30 < 4; c42_i30++) {
      c42_b[c42_i30] = c42_Bx[c42_i30];
    }

    c42_c_b = c42_u;
    for (c42_i31 = 0; c42_i31 < 4; c42_i31++) {
      c42_b[c42_i31] *= c42_c_b;
    }

    for (c42_i32 = 0; c42_i32 < 4; c42_i32++) {
      c42_x_pred[c42_i32] = c42_y[c42_i32] + c42_b[c42_i32];
    }

    _SFD_EML_CALL(0U, *c42_sfEvent, 11);
    for (c42_i33 = 0; c42_i33 < 16; c42_i33++) {
      c42_a[c42_i33] = c42_Ax[c42_i33];
    }

    for (c42_i34 = 0; c42_i34 < 16; c42_i34++) {
      c42_d_b[c42_i34] = c42_P_prev[c42_i34];
    }

    c42_b_eml_scalar_eg(chartInstance);
    c42_b_eml_scalar_eg(chartInstance);
    for (c42_i35 = 0; c42_i35 < 4; c42_i35++) {
      c42_i36 = 0;
      for (c42_i37 = 0; c42_i37 < 4; c42_i37++) {
        c42_b_y[c42_i36 + c42_i35] = 0.0;
        c42_i38 = 0;
        for (c42_i39 = 0; c42_i39 < 4; c42_i39++) {
          c42_b_y[c42_i36 + c42_i35] += c42_a[c42_i38 + c42_i35] *
            c42_d_b[c42_i39 + c42_i36];
          c42_i38 += 4;
        }

        c42_i36 += 4;
      }
    }

    c42_i40 = 0;
    for (c42_i41 = 0; c42_i41 < 4; c42_i41++) {
      c42_i42 = 0;
      for (c42_i43 = 0; c42_i43 < 4; c42_i43++) {
        c42_d_b[c42_i43 + c42_i40] = c42_Ax[c42_i42 + c42_i41];
        c42_i42 += 4;
      }

      c42_i40 += 4;
    }

    c42_b_eml_scalar_eg(chartInstance);
    c42_b_eml_scalar_eg(chartInstance);
    for (c42_i44 = 0; c42_i44 < 4; c42_i44++) {
      c42_i45 = 0;
      for (c42_i46 = 0; c42_i46 < 4; c42_i46++) {
        c42_c_y[c42_i45 + c42_i44] = 0.0;
        c42_i47 = 0;
        for (c42_i48 = 0; c42_i48 < 4; c42_i48++) {
          c42_c_y[c42_i45 + c42_i44] += c42_b_y[c42_i47 + c42_i44] *
            c42_d_b[c42_i48 + c42_i45];
          c42_i47 += 4;
        }

        c42_i45 += 4;
      }
    }

    for (c42_i49 = 0; c42_i49 < 16; c42_i49++) {
      c42_P_pred[c42_i49] = c42_c_y[c42_i49] + c42_Qp[c42_i49];
    }
  }

  _SFD_EML_CALL(0U, *c42_sfEvent, 17);
  if (CV_EML_IF(0, 1, 1, c42_flag_fault != 0.0) != 0.0) {
    _SFD_EML_CALL(0U, *c42_sfEvent, 18);
    c42_z[2] = c42_x_pred[2];
    _SFD_EML_CALL(0U, *c42_sfEvent, 19);
    c42_z[3] = c42_x_pred[3];
  }

  _SFD_EML_CALL(0U, *c42_sfEvent, 23);
  for (c42_i50 = 0; c42_i50 < 16; c42_i50++) {
    c42_a[c42_i50] = c42_P_pred[c42_i50];
  }

  c42_i51 = 0;
  for (c42_i52 = 0; c42_i52 < 4; c42_i52++) {
    c42_i53 = 0;
    for (c42_i54 = 0; c42_i54 < 4; c42_i54++) {
      c42_d_b[c42_i54 + c42_i51] = c42_Cx[c42_i53 + c42_i52];
      c42_i53 += 4;
    }

    c42_i51 += 4;
  }

  c42_b_eml_scalar_eg(chartInstance);
  c42_b_eml_scalar_eg(chartInstance);
  for (c42_i55 = 0; c42_i55 < 4; c42_i55++) {
    c42_i56 = 0;
    for (c42_i57 = 0; c42_i57 < 4; c42_i57++) {
      c42_b_y[c42_i56 + c42_i55] = 0.0;
      c42_i58 = 0;
      for (c42_i59 = 0; c42_i59 < 4; c42_i59++) {
        c42_b_y[c42_i56 + c42_i55] += c42_a[c42_i58 + c42_i55] * c42_d_b[c42_i59
          + c42_i56];
        c42_i58 += 4;
      }

      c42_i56 += 4;
    }
  }

  for (c42_i60 = 0; c42_i60 < 16; c42_i60++) {
    c42_a[c42_i60] = c42_Cx[c42_i60];
  }

  for (c42_i61 = 0; c42_i61 < 16; c42_i61++) {
    c42_d_b[c42_i61] = c42_P_pred[c42_i61];
  }

  c42_b_eml_scalar_eg(chartInstance);
  c42_b_eml_scalar_eg(chartInstance);
  for (c42_i62 = 0; c42_i62 < 4; c42_i62++) {
    c42_i63 = 0;
    for (c42_i64 = 0; c42_i64 < 4; c42_i64++) {
      c42_c_y[c42_i63 + c42_i62] = 0.0;
      c42_i65 = 0;
      for (c42_i66 = 0; c42_i66 < 4; c42_i66++) {
        c42_c_y[c42_i63 + c42_i62] += c42_a[c42_i65 + c42_i62] * c42_d_b[c42_i66
          + c42_i63];
        c42_i65 += 4;
      }

      c42_i63 += 4;
    }
  }

  c42_i67 = 0;
  for (c42_i68 = 0; c42_i68 < 4; c42_i68++) {
    c42_i69 = 0;
    for (c42_i70 = 0; c42_i70 < 4; c42_i70++) {
      c42_d_b[c42_i70 + c42_i67] = c42_Cx[c42_i69 + c42_i68];
      c42_i69 += 4;
    }

    c42_i67 += 4;
  }

  c42_b_eml_scalar_eg(chartInstance);
  c42_b_eml_scalar_eg(chartInstance);
  for (c42_i71 = 0; c42_i71 < 4; c42_i71++) {
    c42_i72 = 0;
    for (c42_i73 = 0; c42_i73 < 4; c42_i73++) {
      c42_a[c42_i72 + c42_i71] = 0.0;
      c42_i74 = 0;
      for (c42_i75 = 0; c42_i75 < 4; c42_i75++) {
        c42_a[c42_i72 + c42_i71] += c42_c_y[c42_i74 + c42_i71] * c42_d_b[c42_i75
          + c42_i72];
        c42_i74 += 4;
      }

      c42_i72 += 4;
    }
  }

  for (c42_i76 = 0; c42_i76 < 16; c42_i76++) {
    c42_d_y[c42_i76] = c42_b_y[c42_i76];
  }

  for (c42_i77 = 0; c42_i77 < 16; c42_i77++) {
    c42_b_a[c42_i77] = c42_a[c42_i77] + c42_Rn[c42_i77];
  }

  c42_mrdivide(chartInstance, c42_d_y, c42_b_a, c42_dv2);
  for (c42_i78 = 0; c42_i78 < 16; c42_i78++) {
    c42_K[c42_i78] = c42_dv2[c42_i78];
  }

  _SFD_EML_CALL(0U, *c42_sfEvent, 24);
  for (c42_i79 = 0; c42_i79 < 16; c42_i79++) {
    c42_a[c42_i79] = c42_Cx[c42_i79];
  }

  for (c42_i80 = 0; c42_i80 < 4; c42_i80++) {
    c42_b[c42_i80] = c42_x_pred[c42_i80];
  }

  c42_eml_scalar_eg(chartInstance);
  c42_eml_scalar_eg(chartInstance);
  for (c42_i81 = 0; c42_i81 < 4; c42_i81++) {
    c42_y[c42_i81] = 0.0;
    c42_i82 = 0;
    for (c42_i83 = 0; c42_i83 < 4; c42_i83++) {
      c42_y[c42_i81] += c42_a[c42_i82 + c42_i81] * c42_b[c42_i83];
      c42_i82 += 4;
    }
  }

  for (c42_i84 = 0; c42_i84 < 16; c42_i84++) {
    c42_a[c42_i84] = c42_K[c42_i84];
  }

  for (c42_i85 = 0; c42_i85 < 4; c42_i85++) {
    c42_y[c42_i85] = c42_z[c42_i85] - c42_y[c42_i85];
  }

  c42_eml_scalar_eg(chartInstance);
  c42_eml_scalar_eg(chartInstance);
  for (c42_i86 = 0; c42_i86 < 4; c42_i86++) {
    c42_b[c42_i86] = 0.0;
    c42_i87 = 0;
    for (c42_i88 = 0; c42_i88 < 4; c42_i88++) {
      c42_b[c42_i86] += c42_a[c42_i87 + c42_i86] * c42_y[c42_i88];
      c42_i87 += 4;
    }
  }

  for (c42_i89 = 0; c42_i89 < 4; c42_i89++) {
    c42_x_meas[c42_i89] = c42_x_pred[c42_i89] + c42_b[c42_i89];
  }

  _SFD_EML_CALL(0U, *c42_sfEvent, 25);
  for (c42_i90 = 0; c42_i90 < 16; c42_i90++) {
    c42_a[c42_i90] = c42_K[c42_i90];
  }

  for (c42_i91 = 0; c42_i91 < 16; c42_i91++) {
    c42_d_b[c42_i91] = c42_Cx[c42_i91];
  }

  c42_b_eml_scalar_eg(chartInstance);
  c42_b_eml_scalar_eg(chartInstance);
  for (c42_i92 = 0; c42_i92 < 4; c42_i92++) {
    c42_i93 = 0;
    for (c42_i94 = 0; c42_i94 < 4; c42_i94++) {
      c42_b_y[c42_i93 + c42_i92] = 0.0;
      c42_i95 = 0;
      for (c42_i96 = 0; c42_i96 < 4; c42_i96++) {
        c42_b_y[c42_i93 + c42_i92] += c42_a[c42_i95 + c42_i92] * c42_d_b[c42_i96
          + c42_i93];
        c42_i95 += 4;
      }

      c42_i93 += 4;
    }
  }

  c42_eye(chartInstance, c42_a);
  for (c42_i97 = 0; c42_i97 < 16; c42_i97++) {
    c42_a[c42_i97] -= c42_b_y[c42_i97];
  }

  for (c42_i98 = 0; c42_i98 < 16; c42_i98++) {
    c42_d_b[c42_i98] = c42_P_pred[c42_i98];
  }

  c42_b_eml_scalar_eg(chartInstance);
  c42_b_eml_scalar_eg(chartInstance);
  for (c42_i99 = 0; c42_i99 < 4; c42_i99++) {
    c42_i100 = 0;
    for (c42_i101 = 0; c42_i101 < 4; c42_i101++) {
      c42_b_y[c42_i100 + c42_i99] = 0.0;
      c42_i102 = 0;
      for (c42_i103 = 0; c42_i103 < 4; c42_i103++) {
        c42_b_y[c42_i100 + c42_i99] += c42_a[c42_i102 + c42_i99] *
          c42_d_b[c42_i103 + c42_i100];
        c42_i102 += 4;
      }

      c42_i100 += 4;
    }
  }

  for (c42_i104 = 0; c42_i104 < 16; c42_i104++) {
    c42_a[c42_i104] = c42_K[c42_i104];
  }

  for (c42_i105 = 0; c42_i105 < 16; c42_i105++) {
    c42_d_b[c42_i105] = c42_Cx[c42_i105];
  }

  c42_b_eml_scalar_eg(chartInstance);
  c42_b_eml_scalar_eg(chartInstance);
  for (c42_i106 = 0; c42_i106 < 4; c42_i106++) {
    c42_i107 = 0;
    for (c42_i108 = 0; c42_i108 < 4; c42_i108++) {
      c42_c_y[c42_i107 + c42_i106] = 0.0;
      c42_i109 = 0;
      for (c42_i110 = 0; c42_i110 < 4; c42_i110++) {
        c42_c_y[c42_i107 + c42_i106] += c42_a[c42_i109 + c42_i106] *
          c42_d_b[c42_i110 + c42_i107];
        c42_i109 += 4;
      }

      c42_i107 += 4;
    }
  }

  c42_eye(chartInstance, c42_a);
  c42_i111 = 0;
  for (c42_i112 = 0; c42_i112 < 4; c42_i112++) {
    c42_i113 = 0;
    for (c42_i114 = 0; c42_i114 < 4; c42_i114++) {
      c42_d_b[c42_i114 + c42_i111] = c42_a[c42_i113 + c42_i112] -
        c42_c_y[c42_i113 + c42_i112];
      c42_i113 += 4;
    }

    c42_i111 += 4;
  }

  c42_b_eml_scalar_eg(chartInstance);
  c42_b_eml_scalar_eg(chartInstance);
  for (c42_i115 = 0; c42_i115 < 4; c42_i115++) {
    c42_i116 = 0;
    for (c42_i117 = 0; c42_i117 < 4; c42_i117++) {
      c42_c_y[c42_i116 + c42_i115] = 0.0;
      c42_i118 = 0;
      for (c42_i119 = 0; c42_i119 < 4; c42_i119++) {
        c42_c_y[c42_i116 + c42_i115] += c42_b_y[c42_i118 + c42_i115] *
          c42_d_b[c42_i119 + c42_i116];
        c42_i118 += 4;
      }

      c42_i116 += 4;
    }
  }

  for (c42_i120 = 0; c42_i120 < 16; c42_i120++) {
    c42_a[c42_i120] = c42_K[c42_i120];
  }

  for (c42_i121 = 0; c42_i121 < 16; c42_i121++) {
    c42_d_b[c42_i121] = c42_Rn[c42_i121];
  }

  c42_b_eml_scalar_eg(chartInstance);
  c42_b_eml_scalar_eg(chartInstance);
  for (c42_i122 = 0; c42_i122 < 4; c42_i122++) {
    c42_i123 = 0;
    for (c42_i124 = 0; c42_i124 < 4; c42_i124++) {
      c42_b_y[c42_i123 + c42_i122] = 0.0;
      c42_i125 = 0;
      for (c42_i126 = 0; c42_i126 < 4; c42_i126++) {
        c42_b_y[c42_i123 + c42_i122] += c42_a[c42_i125 + c42_i122] *
          c42_d_b[c42_i126 + c42_i123];
        c42_i125 += 4;
      }

      c42_i123 += 4;
    }
  }

  c42_i127 = 0;
  for (c42_i128 = 0; c42_i128 < 4; c42_i128++) {
    c42_i129 = 0;
    for (c42_i130 = 0; c42_i130 < 4; c42_i130++) {
      c42_d_b[c42_i130 + c42_i127] = c42_K[c42_i129 + c42_i128];
      c42_i129 += 4;
    }

    c42_i127 += 4;
  }

  c42_b_eml_scalar_eg(chartInstance);
  c42_b_eml_scalar_eg(chartInstance);
  for (c42_i131 = 0; c42_i131 < 4; c42_i131++) {
    c42_i132 = 0;
    for (c42_i133 = 0; c42_i133 < 4; c42_i133++) {
      c42_a[c42_i132 + c42_i131] = 0.0;
      c42_i134 = 0;
      for (c42_i135 = 0; c42_i135 < 4; c42_i135++) {
        c42_a[c42_i132 + c42_i131] += c42_b_y[c42_i134 + c42_i131] *
          c42_d_b[c42_i135 + c42_i132];
        c42_i134 += 4;
      }

      c42_i132 += 4;
    }
  }

  for (c42_i136 = 0; c42_i136 < 16; c42_i136++) {
    c42_Pmeas[c42_i136] = c42_c_y[c42_i136] + c42_a[c42_i136];
  }

  _SFD_EML_CALL(0U, *c42_sfEvent, 28);
  if (CV_EML_IF(0, 1, 2, c42_flag_fault != 0.0) != 0.0) {
    _SFD_EML_CALL(0U, *c42_sfEvent, 29);
    c42_Pmeas[2] = c42_P_pred[2];
    _SFD_EML_CALL(0U, *c42_sfEvent, 30);
    c42_Pmeas[3] = c42_P_pred[3];
  }

  _SFD_EML_CALL(0U, *c42_sfEvent, -30);
  sf_debug_symbol_scope_pop();
  for (c42_i137 = 0; c42_i137 < 4; c42_i137++) {
    (*c42_b_x_meas)[c42_i137] = c42_x_meas[c42_i137];
  }

  for (c42_i138 = 0; c42_i138 < 16; c42_i138++) {
    (*c42_b_Pmeas)[c42_i138] = c42_Pmeas[c42_i138];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, *c42_sfEvent);
}

static void initSimStructsc42_controller_template
  (SFc42_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c42_machineNumber, uint32_T
  c42_chartNumber)
{
}

static const mxArray *c42_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  int32_T c42_i139;
  int32_T c42_i140;
  int32_T c42_i141;
  real_T c42_b_inData[16];
  int32_T c42_i142;
  int32_T c42_i143;
  int32_T c42_i144;
  real_T c42_u[16];
  const mxArray *c42_y = NULL;
  SFc42_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc42_controller_templateInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  c42_i139 = 0;
  for (c42_i140 = 0; c42_i140 < 4; c42_i140++) {
    for (c42_i141 = 0; c42_i141 < 4; c42_i141++) {
      c42_b_inData[c42_i141 + c42_i139] = (*(real_T (*)[16])c42_inData)[c42_i141
        + c42_i139];
    }

    c42_i139 += 4;
  }

  c42_i142 = 0;
  for (c42_i143 = 0; c42_i143 < 4; c42_i143++) {
    for (c42_i144 = 0; c42_i144 < 4; c42_i144++) {
      c42_u[c42_i144 + c42_i142] = c42_b_inData[c42_i144 + c42_i142];
    }

    c42_i142 += 4;
  }

  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", c42_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, FALSE);
  return c42_mxArrayOutData;
}

static void c42_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_Pmeas, const char_T *c42_identifier, real_T
  c42_y[16])
{
  emlrtMsgIdentifier c42_thisId;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_Pmeas), &c42_thisId,
    c42_y);
  sf_mex_destroy(&c42_Pmeas);
}

static void c42_b_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId,
  real_T c42_y[16])
{
  real_T c42_dv3[16];
  int32_T c42_i145;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), c42_dv3, 1, 0, 0U, 1, 0U, 2, 4,
                4);
  for (c42_i145 = 0; c42_i145 < 16; c42_i145++) {
    c42_y[c42_i145] = c42_dv3[c42_i145];
  }

  sf_mex_destroy(&c42_u);
}

static void c42_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_Pmeas;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  real_T c42_y[16];
  int32_T c42_i146;
  int32_T c42_i147;
  int32_T c42_i148;
  SFc42_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc42_controller_templateInstanceStruct *)chartInstanceVoid;
  c42_Pmeas = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_Pmeas), &c42_thisId,
    c42_y);
  sf_mex_destroy(&c42_Pmeas);
  c42_i146 = 0;
  for (c42_i147 = 0; c42_i147 < 4; c42_i147++) {
    for (c42_i148 = 0; c42_i148 < 4; c42_i148++) {
      (*(real_T (*)[16])c42_outData)[c42_i148 + c42_i146] = c42_y[c42_i148 +
        c42_i146];
    }

    c42_i146 += 4;
  }

  sf_mex_destroy(&c42_mxArrayInData);
}

static const mxArray *c42_b_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  int32_T c42_i149;
  real_T c42_b_inData[4];
  int32_T c42_i150;
  real_T c42_u[4];
  const mxArray *c42_y = NULL;
  SFc42_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc42_controller_templateInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  for (c42_i149 = 0; c42_i149 < 4; c42_i149++) {
    c42_b_inData[c42_i149] = (*(real_T (*)[4])c42_inData)[c42_i149];
  }

  for (c42_i150 = 0; c42_i150 < 4; c42_i150++) {
    c42_u[c42_i150] = c42_b_inData[c42_i150];
  }

  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", c42_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, FALSE);
  return c42_mxArrayOutData;
}

static void c42_c_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_x_meas, const char_T *c42_identifier,
  real_T c42_y[4])
{
  emlrtMsgIdentifier c42_thisId;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_x_meas), &c42_thisId,
    c42_y);
  sf_mex_destroy(&c42_x_meas);
}

static void c42_d_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId,
  real_T c42_y[4])
{
  real_T c42_dv4[4];
  int32_T c42_i151;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), c42_dv4, 1, 0, 0U, 1, 0U, 1, 4);
  for (c42_i151 = 0; c42_i151 < 4; c42_i151++) {
    c42_y[c42_i151] = c42_dv4[c42_i151];
  }

  sf_mex_destroy(&c42_u);
}

static void c42_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_x_meas;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  real_T c42_y[4];
  int32_T c42_i152;
  SFc42_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc42_controller_templateInstanceStruct *)chartInstanceVoid;
  c42_x_meas = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_x_meas), &c42_thisId,
    c42_y);
  sf_mex_destroy(&c42_x_meas);
  for (c42_i152 = 0; c42_i152 < 4; c42_i152++) {
    (*(real_T (*)[4])c42_outData)[c42_i152] = c42_y[c42_i152];
  }

  sf_mex_destroy(&c42_mxArrayInData);
}

static const mxArray *c42_c_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  real_T c42_u;
  const mxArray *c42_y = NULL;
  SFc42_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc42_controller_templateInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  c42_u = *(real_T *)c42_inData;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", &c42_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, FALSE);
  return c42_mxArrayOutData;
}

static real_T c42_e_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId)
{
  real_T c42_y;
  real_T c42_d0;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), &c42_d0, 1, 0, 0U, 0, 0U, 0);
  c42_y = c42_d0;
  sf_mex_destroy(&c42_u);
  return c42_y;
}

static void c42_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_nargout;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  real_T c42_y;
  SFc42_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc42_controller_templateInstanceStruct *)chartInstanceVoid;
  c42_nargout = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_y = c42_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_nargout),
    &c42_thisId);
  sf_mex_destroy(&c42_nargout);
  *(real_T *)c42_outData = c42_y;
  sf_mex_destroy(&c42_mxArrayInData);
}

const mxArray *sf_c42_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c42_nameCaptureInfo;
  c42_ResolvedFunctionInfo c42_info[48];
  const mxArray *c42_m0 = NULL;
  int32_T c42_i153;
  c42_ResolvedFunctionInfo *c42_r0;
  c42_nameCaptureInfo = NULL;
  c42_nameCaptureInfo = NULL;
  c42_info_helper(c42_info);
  sf_mex_assign(&c42_m0, sf_mex_createstruct("nameCaptureInfo", 1, 48), FALSE);
  for (c42_i153 = 0; c42_i153 < 48; c42_i153++) {
    c42_r0 = &c42_info[c42_i153];
    sf_mex_addfield(c42_m0, sf_mex_create("nameCaptureInfo", c42_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c42_r0->context)), "context", "nameCaptureInfo",
                    c42_i153);
    sf_mex_addfield(c42_m0, sf_mex_create("nameCaptureInfo", c42_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c42_r0->name)), "name", "nameCaptureInfo",
                    c42_i153);
    sf_mex_addfield(c42_m0, sf_mex_create("nameCaptureInfo",
      c42_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c42_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c42_i153);
    sf_mex_addfield(c42_m0, sf_mex_create("nameCaptureInfo", c42_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c42_r0->resolved)), "resolved",
                    "nameCaptureInfo", c42_i153);
    sf_mex_addfield(c42_m0, sf_mex_create("nameCaptureInfo", &c42_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c42_i153);
    sf_mex_addfield(c42_m0, sf_mex_create("nameCaptureInfo", &c42_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c42_i153);
    sf_mex_addfield(c42_m0, sf_mex_create("nameCaptureInfo",
      &c42_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c42_i153);
    sf_mex_addfield(c42_m0, sf_mex_create("nameCaptureInfo",
      &c42_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c42_i153);
  }

  sf_mex_assign(&c42_nameCaptureInfo, c42_m0, FALSE);
  return c42_nameCaptureInfo;
}

static void c42_info_helper(c42_ResolvedFunctionInfo c42_info[48])
{
  c42_info[0].context = "";
  c42_info[0].name = "mtimes";
  c42_info[0].dominantType = "double";
  c42_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c42_info[0].fileTimeLo = 1289519692U;
  c42_info[0].fileTimeHi = 0U;
  c42_info[0].mFileTimeLo = 0U;
  c42_info[0].mFileTimeHi = 0U;
  c42_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c42_info[1].name = "eml_index_class";
  c42_info[1].dominantType = "";
  c42_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c42_info[1].fileTimeLo = 1286818778U;
  c42_info[1].fileTimeHi = 0U;
  c42_info[1].mFileTimeLo = 0U;
  c42_info[1].mFileTimeHi = 0U;
  c42_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c42_info[2].name = "eml_scalar_eg";
  c42_info[2].dominantType = "double";
  c42_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c42_info[2].fileTimeLo = 1286818796U;
  c42_info[2].fileTimeHi = 0U;
  c42_info[2].mFileTimeLo = 0U;
  c42_info[2].mFileTimeHi = 0U;
  c42_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c42_info[3].name = "eml_xgemm";
  c42_info[3].dominantType = "int32";
  c42_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c42_info[3].fileTimeLo = 1299076772U;
  c42_info[3].fileTimeHi = 0U;
  c42_info[3].mFileTimeLo = 0U;
  c42_info[3].mFileTimeHi = 0U;
  c42_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c42_info[4].name = "eml_blas_inline";
  c42_info[4].dominantType = "";
  c42_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c42_info[4].fileTimeLo = 1299076768U;
  c42_info[4].fileTimeHi = 0U;
  c42_info[4].mFileTimeLo = 0U;
  c42_info[4].mFileTimeHi = 0U;
  c42_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c42_info[5].name = "eml_refblas_xgemm";
  c42_info[5].dominantType = "int32";
  c42_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c42_info[5].fileTimeLo = 1299076774U;
  c42_info[5].fileTimeHi = 0U;
  c42_info[5].mFileTimeLo = 0U;
  c42_info[5].mFileTimeHi = 0U;
  c42_info[6].context = "";
  c42_info[6].name = "mrdivide";
  c42_info[6].dominantType = "double";
  c42_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c42_info[6].fileTimeLo = 1310137456U;
  c42_info[6].fileTimeHi = 0U;
  c42_info[6].mFileTimeLo = 1289519692U;
  c42_info[6].mFileTimeHi = 0U;
  c42_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c42_info[7].name = "mldivide";
  c42_info[7].dominantType = "double";
  c42_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c42_info[7].fileTimeLo = 1310137456U;
  c42_info[7].fileTimeHi = 0U;
  c42_info[7].mFileTimeLo = 1289519690U;
  c42_info[7].mFileTimeHi = 0U;
  c42_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p";
  c42_info[8].name = "eml_lusolve";
  c42_info[8].dominantType = "double";
  c42_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m";
  c42_info[8].fileTimeLo = 1305318000U;
  c42_info[8].fileTimeHi = 0U;
  c42_info[8].mFileTimeLo = 0U;
  c42_info[8].mFileTimeHi = 0U;
  c42_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c42_info[9].name = "eml_xgetrf";
  c42_info[9].dominantType = "int32";
  c42_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c42_info[9].fileTimeLo = 1286818806U;
  c42_info[9].fileTimeHi = 0U;
  c42_info[9].mFileTimeLo = 0U;
  c42_info[9].mFileTimeHi = 0U;
  c42_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m";
  c42_info[10].name = "eml_lapack_xgetrf";
  c42_info[10].dominantType = "int32";
  c42_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c42_info[10].fileTimeLo = 1286818810U;
  c42_info[10].fileTimeHi = 0U;
  c42_info[10].mFileTimeLo = 0U;
  c42_info[10].mFileTimeHi = 0U;
  c42_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m";
  c42_info[11].name = "eml_matlab_zgetrf";
  c42_info[11].dominantType = "int32";
  c42_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c42_info[11].fileTimeLo = 1302688994U;
  c42_info[11].fileTimeHi = 0U;
  c42_info[11].mFileTimeLo = 0U;
  c42_info[11].mFileTimeHi = 0U;
  c42_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c42_info[12].name = "realmin";
  c42_info[12].dominantType = "char";
  c42_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c42_info[12].fileTimeLo = 1286818768U;
  c42_info[12].fileTimeHi = 0U;
  c42_info[12].mFileTimeLo = 0U;
  c42_info[12].mFileTimeHi = 0U;
  c42_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m";
  c42_info[13].name = "mpower";
  c42_info[13].dominantType = "double";
  c42_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c42_info[13].fileTimeLo = 1286818842U;
  c42_info[13].fileTimeHi = 0U;
  c42_info[13].mFileTimeLo = 0U;
  c42_info[13].mFileTimeHi = 0U;
  c42_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c42_info[14].name = "power";
  c42_info[14].dominantType = "double";
  c42_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c42_info[14].fileTimeLo = 1294067944U;
  c42_info[14].fileTimeHi = 0U;
  c42_info[14].mFileTimeLo = 0U;
  c42_info[14].mFileTimeHi = 0U;
  c42_info[15].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c42_info[15].name = "eml_scalexp_alloc";
  c42_info[15].dominantType = "double";
  c42_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c42_info[15].fileTimeLo = 1286818796U;
  c42_info[15].fileTimeHi = 0U;
  c42_info[15].mFileTimeLo = 0U;
  c42_info[15].mFileTimeHi = 0U;
  c42_info[16].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c42_info[16].name = "eml_scalar_floor";
  c42_info[16].dominantType = "double";
  c42_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c42_info[16].fileTimeLo = 1286818726U;
  c42_info[16].fileTimeHi = 0U;
  c42_info[16].mFileTimeLo = 0U;
  c42_info[16].mFileTimeHi = 0U;
  c42_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c42_info[17].name = "eps";
  c42_info[17].dominantType = "char";
  c42_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c42_info[17].fileTimeLo = 1286818686U;
  c42_info[17].fileTimeHi = 0U;
  c42_info[17].mFileTimeLo = 0U;
  c42_info[17].mFileTimeHi = 0U;
  c42_info[18].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c42_info[18].name = "eml_is_float_class";
  c42_info[18].dominantType = "char";
  c42_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c42_info[18].fileTimeLo = 1286818782U;
  c42_info[18].fileTimeHi = 0U;
  c42_info[18].mFileTimeLo = 0U;
  c42_info[18].mFileTimeHi = 0U;
  c42_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c42_info[19].name = "min";
  c42_info[19].dominantType = "int32";
  c42_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c42_info[19].fileTimeLo = 1308747330U;
  c42_info[19].fileTimeHi = 0U;
  c42_info[19].mFileTimeLo = 0U;
  c42_info[19].mFileTimeHi = 0U;
  c42_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c42_info[20].name = "eml_min_or_max";
  c42_info[20].dominantType = "int32";
  c42_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c42_info[20].fileTimeLo = 1303146212U;
  c42_info[20].fileTimeHi = 0U;
  c42_info[20].mFileTimeLo = 0U;
  c42_info[20].mFileTimeHi = 0U;
  c42_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c42_info[21].name = "colon";
  c42_info[21].dominantType = "int32";
  c42_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c42_info[21].fileTimeLo = 1286818838U;
  c42_info[21].fileTimeHi = 0U;
  c42_info[21].mFileTimeLo = 0U;
  c42_info[21].mFileTimeHi = 0U;
  c42_info[22].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m";
  c42_info[22].name = "floor";
  c42_info[22].dominantType = "double";
  c42_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c42_info[22].fileTimeLo = 1286818742U;
  c42_info[22].fileTimeHi = 0U;
  c42_info[22].mFileTimeLo = 0U;
  c42_info[22].mFileTimeHi = 0U;
  c42_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c42_info[23].name = "intmin";
  c42_info[23].dominantType = "char";
  c42_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m";
  c42_info[23].fileTimeLo = 1286818756U;
  c42_info[23].fileTimeHi = 0U;
  c42_info[23].mFileTimeLo = 0U;
  c42_info[23].mFileTimeHi = 0U;
  c42_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange";
  c42_info[24].name = "intmax";
  c42_info[24].dominantType = "char";
  c42_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c42_info[24].fileTimeLo = 1286818756U;
  c42_info[24].fileTimeHi = 0U;
  c42_info[24].mFileTimeLo = 0U;
  c42_info[24].mFileTimeHi = 0U;
  c42_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c42_info[25].name = "rdivide";
  c42_info[25].dominantType = "double";
  c42_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c42_info[25].fileTimeLo = 1286818844U;
  c42_info[25].fileTimeHi = 0U;
  c42_info[25].mFileTimeLo = 0U;
  c42_info[25].mFileTimeHi = 0U;
  c42_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c42_info[26].name = "eml_div";
  c42_info[26].dominantType = "double";
  c42_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c42_info[26].fileTimeLo = 1305318000U;
  c42_info[26].fileTimeHi = 0U;
  c42_info[26].mFileTimeLo = 0U;
  c42_info[26].mFileTimeHi = 0U;
  c42_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c42_info[27].name = "eml_index_plus";
  c42_info[27].dominantType = "int32";
  c42_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c42_info[27].fileTimeLo = 1286818778U;
  c42_info[27].fileTimeHi = 0U;
  c42_info[27].mFileTimeLo = 0U;
  c42_info[27].mFileTimeHi = 0U;
  c42_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c42_info[28].name = "eml_index_minus";
  c42_info[28].dominantType = "int32";
  c42_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c42_info[28].fileTimeLo = 1286818778U;
  c42_info[28].fileTimeHi = 0U;
  c42_info[28].mFileTimeLo = 0U;
  c42_info[28].mFileTimeHi = 0U;
  c42_info[29].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c42_info[29].name = "eml_index_times";
  c42_info[29].dominantType = "int32";
  c42_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c42_info[29].fileTimeLo = 1286818780U;
  c42_info[29].fileTimeHi = 0U;
  c42_info[29].mFileTimeLo = 0U;
  c42_info[29].mFileTimeHi = 0U;
  c42_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c42_info[30].name = "eml_ixamax";
  c42_info[30].dominantType = "int32";
  c42_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m";
  c42_info[30].fileTimeLo = 1299076770U;
  c42_info[30].fileTimeHi = 0U;
  c42_info[30].mFileTimeLo = 0U;
  c42_info[30].mFileTimeHi = 0U;
  c42_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m!below_threshold";
  c42_info[31].name = "length";
  c42_info[31].dominantType = "double";
  c42_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  c42_info[31].fileTimeLo = 1303146206U;
  c42_info[31].fileTimeHi = 0U;
  c42_info[31].mFileTimeLo = 0U;
  c42_info[31].mFileTimeHi = 0U;
  c42_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_ixamax.m";
  c42_info[32].name = "eml_refblas_ixamax";
  c42_info[32].dominantType = "int32";
  c42_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c42_info[32].fileTimeLo = 1299076770U;
  c42_info[32].fileTimeHi = 0U;
  c42_info[32].mFileTimeLo = 0U;
  c42_info[32].mFileTimeHi = 0U;
  c42_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_ixamax.m";
  c42_info[33].name = "eml_xcabs1";
  c42_info[33].dominantType = "double";
  c42_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c42_info[33].fileTimeLo = 1286818706U;
  c42_info[33].fileTimeHi = 0U;
  c42_info[33].mFileTimeLo = 0U;
  c42_info[33].mFileTimeHi = 0U;
  c42_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c42_info[34].name = "abs";
  c42_info[34].dominantType = "double";
  c42_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c42_info[34].fileTimeLo = 1286818694U;
  c42_info[34].fileTimeHi = 0U;
  c42_info[34].mFileTimeLo = 0U;
  c42_info[34].mFileTimeHi = 0U;
  c42_info[35].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c42_info[35].name = "eml_scalar_abs";
  c42_info[35].dominantType = "double";
  c42_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c42_info[35].fileTimeLo = 1286818712U;
  c42_info[35].fileTimeHi = 0U;
  c42_info[35].mFileTimeLo = 0U;
  c42_info[35].mFileTimeHi = 0U;
  c42_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c42_info[36].name = "eml_xswap";
  c42_info[36].dominantType = "int32";
  c42_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m";
  c42_info[36].fileTimeLo = 1299076778U;
  c42_info[36].fileTimeHi = 0U;
  c42_info[36].mFileTimeLo = 0U;
  c42_info[36].mFileTimeHi = 0U;
  c42_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xswap.m";
  c42_info[37].name = "eml_refblas_xswap";
  c42_info[37].dominantType = "int32";
  c42_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xswap.m";
  c42_info[37].fileTimeLo = 1299076786U;
  c42_info[37].fileTimeHi = 0U;
  c42_info[37].mFileTimeLo = 0U;
  c42_info[37].mFileTimeHi = 0U;
  c42_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m";
  c42_info[38].name = "eml_xgeru";
  c42_info[38].dominantType = "int32";
  c42_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c42_info[38].fileTimeLo = 1299076774U;
  c42_info[38].fileTimeHi = 0U;
  c42_info[38].mFileTimeLo = 0U;
  c42_info[38].mFileTimeHi = 0U;
  c42_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m";
  c42_info[39].name = "eml_xger";
  c42_info[39].dominantType = "int32";
  c42_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xger.m";
  c42_info[39].fileTimeLo = 1299076774U;
  c42_info[39].fileTimeHi = 0U;
  c42_info[39].mFileTimeLo = 0U;
  c42_info[39].mFileTimeHi = 0U;
  c42_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xger.m";
  c42_info[40].name = "eml_refblas_xger";
  c42_info[40].dominantType = "int32";
  c42_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c42_info[40].fileTimeLo = 1299076776U;
  c42_info[40].fileTimeHi = 0U;
  c42_info[40].mFileTimeLo = 0U;
  c42_info[40].mFileTimeHi = 0U;
  c42_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xger.m";
  c42_info[41].name = "eml_refblas_xgerx";
  c42_info[41].dominantType = "int32";
  c42_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgerx.m";
  c42_info[41].fileTimeLo = 1299076778U;
  c42_info[41].fileTimeHi = 0U;
  c42_info[41].mFileTimeLo = 0U;
  c42_info[41].mFileTimeHi = 0U;
  c42_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular";
  c42_info[42].name = "eml_warning";
  c42_info[42].dominantType = "char";
  c42_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c42_info[42].fileTimeLo = 1286818802U;
  c42_info[42].fileTimeHi = 0U;
  c42_info[42].mFileTimeLo = 0U;
  c42_info[42].mFileTimeHi = 0U;
  c42_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN";
  c42_info[43].name = "eml_xtrsm";
  c42_info[43].dominantType = "int32";
  c42_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m";
  c42_info[43].fileTimeLo = 1299076778U;
  c42_info[43].fileTimeHi = 0U;
  c42_info[43].mFileTimeLo = 0U;
  c42_info[43].mFileTimeHi = 0U;
  c42_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xtrsm.m";
  c42_info[44].name = "eml_refblas_xtrsm";
  c42_info[44].dominantType = "int32";
  c42_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xtrsm.m";
  c42_info[44].fileTimeLo = 1299076786U;
  c42_info[44].fileTimeHi = 0U;
  c42_info[44].mFileTimeLo = 0U;
  c42_info[44].mFileTimeHi = 0U;
  c42_info[45].context = "";
  c42_info[45].name = "eye";
  c42_info[45].dominantType = "double";
  c42_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c42_info[45].fileTimeLo = 1286818688U;
  c42_info[45].fileTimeHi = 0U;
  c42_info[45].mFileTimeLo = 0U;
  c42_info[45].mFileTimeHi = 0U;
  c42_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c42_info[46].name = "eml_assert_valid_size_arg";
  c42_info[46].dominantType = "double";
  c42_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c42_info[46].fileTimeLo = 1286818694U;
  c42_info[46].fileTimeHi = 0U;
  c42_info[46].mFileTimeLo = 0U;
  c42_info[46].mFileTimeHi = 0U;
  c42_info[47].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c42_info[47].name = "isinf";
  c42_info[47].dominantType = "double";
  c42_info[47].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c42_info[47].fileTimeLo = 1286818760U;
  c42_info[47].fileTimeHi = 0U;
  c42_info[47].mFileTimeLo = 0U;
  c42_info[47].mFileTimeHi = 0U;
}

static void c42_eml_scalar_eg(SFc42_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c42_b_eml_scalar_eg(SFc42_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c42_mrdivide(SFc42_controller_templateInstanceStruct *chartInstance,
  real_T c42_A[16], real_T c42_B[16], real_T c42_y[16])
{
  int32_T c42_i154;
  int32_T c42_i155;
  int32_T c42_i156;
  int32_T c42_i157;
  real_T c42_b_A[16];
  int32_T c42_i158;
  int32_T c42_i159;
  int32_T c42_i160;
  int32_T c42_i161;
  real_T c42_b_B[16];
  int32_T c42_info;
  int32_T c42_ipiv[4];
  int32_T c42_b_info;
  int32_T c42_c_info;
  int32_T c42_d_info;
  int32_T c42_i;
  int32_T c42_b_i;
  int32_T c42_ip;
  int32_T c42_j;
  int32_T c42_b_j;
  real_T c42_temp;
  int32_T c42_i162;
  real_T c42_c_A[16];
  int32_T c42_c_j;
  int32_T c42_d_j;
  int32_T c42_a;
  int32_T c42_c;
  int32_T c42_b;
  int32_T c42_b_c;
  int32_T c42_b_b;
  int32_T c42_jBcol;
  int32_T c42_k;
  int32_T c42_b_k;
  int32_T c42_b_a;
  int32_T c42_c_c;
  int32_T c42_c_b;
  int32_T c42_d_c;
  int32_T c42_d_b;
  int32_T c42_kAcol;
  int32_T c42_c_a;
  int32_T c42_e_b;
  int32_T c42_e_c;
  int32_T c42_d_a;
  int32_T c42_f_b;
  int32_T c42_f_c;
  int32_T c42_e_a;
  int32_T c42_g_b;
  int32_T c42_g_c;
  int32_T c42_f_a;
  int32_T c42_h_b;
  int32_T c42_h_c;
  real_T c42_x;
  real_T c42_b_y;
  real_T c42_z;
  int32_T c42_g_a;
  int32_T c42_i163;
  int32_T c42_c_i;
  int32_T c42_d_i;
  int32_T c42_h_a;
  int32_T c42_i_b;
  int32_T c42_i_c;
  int32_T c42_i_a;
  int32_T c42_j_b;
  int32_T c42_j_c;
  int32_T c42_j_a;
  int32_T c42_k_b;
  int32_T c42_k_c;
  int32_T c42_k_a;
  int32_T c42_l_b;
  int32_T c42_l_c;
  int32_T c42_i164;
  int32_T c42_i165;
  int32_T c42_i166;
  int32_T c42_i167;
  c42_i154 = 0;
  for (c42_i155 = 0; c42_i155 < 4; c42_i155++) {
    c42_i156 = 0;
    for (c42_i157 = 0; c42_i157 < 4; c42_i157++) {
      c42_b_A[c42_i157 + c42_i154] = c42_B[c42_i156 + c42_i155];
      c42_i156 += 4;
    }

    c42_i154 += 4;
  }

  c42_i158 = 0;
  for (c42_i159 = 0; c42_i159 < 4; c42_i159++) {
    c42_i160 = 0;
    for (c42_i161 = 0; c42_i161 < 4; c42_i161++) {
      c42_b_B[c42_i161 + c42_i158] = c42_A[c42_i160 + c42_i159];
      c42_i160 += 4;
    }

    c42_i158 += 4;
  }

  c42_b_eml_matlab_zgetrf(chartInstance, c42_b_A, c42_ipiv, &c42_info);
  c42_b_info = c42_info;
  c42_c_info = c42_b_info;
  c42_d_info = c42_c_info;
  if ((real_T)c42_d_info > 0.0) {
    c42_eml_warning(chartInstance);
  }

  c42_b_eml_scalar_eg(chartInstance);
  for (c42_i = 1; c42_i < 5; c42_i++) {
    c42_b_i = c42_i;
    if (c42_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c42_b_i), 1, 4, 1, 0) - 1] != c42_b_i) {
      c42_ip = c42_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c42_b_i), 1, 4, 1, 0) - 1];
      for (c42_j = 1; c42_j < 5; c42_j++) {
        c42_b_j = c42_j;
        c42_temp = c42_b_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c42_b_i), 1, 4, 1, 0) +
                            ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c42_b_j), 1, 4, 2, 0) - 1) << 2)) - 1];
        c42_b_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c42_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK
                   ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c42_b_j), 1, 4,
                    2, 0) - 1) << 2)) - 1] = c42_b_B
          [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
              (real_T)c42_ip), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
               (int32_T)_SFD_INTEGER_CHECK("", (real_T)c42_b_j), 1, 4, 2, 0) - 1)
             << 2)) - 1];
        c42_b_B[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                   (real_T)c42_ip), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
                    "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c42_b_j), 1, 4,
                    2, 0) - 1) << 2)) - 1] = c42_temp;
      }
    }
  }

  for (c42_i162 = 0; c42_i162 < 16; c42_i162++) {
    c42_c_A[c42_i162] = c42_b_A[c42_i162];
  }

  c42_b_eml_xtrsm(chartInstance, c42_c_A, c42_b_B);
  c42_below_threshold(chartInstance);
  c42_c_eml_scalar_eg(chartInstance);
  for (c42_c_j = 1; c42_c_j < 5; c42_c_j++) {
    c42_d_j = c42_c_j;
    c42_a = c42_d_j;
    c42_c = c42_a;
    c42_b = c42_c - 1;
    c42_b_c = c42_b << 2;
    c42_b_b = c42_b_c;
    c42_jBcol = c42_b_b;
    for (c42_k = 4; c42_k > 0; c42_k--) {
      c42_b_k = c42_k;
      c42_b_a = c42_b_k;
      c42_c_c = c42_b_a;
      c42_c_b = c42_c_c - 1;
      c42_d_c = c42_c_b << 2;
      c42_d_b = c42_d_c;
      c42_kAcol = c42_d_b;
      c42_c_a = c42_b_k;
      c42_e_b = c42_jBcol;
      c42_e_c = c42_c_a + c42_e_b;
      if (c42_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_e_c), 1, 16, 1, 0) - 1] != 0.0) {
        c42_d_a = c42_b_k;
        c42_f_b = c42_jBcol;
        c42_f_c = c42_d_a + c42_f_b;
        c42_e_a = c42_b_k;
        c42_g_b = c42_jBcol;
        c42_g_c = c42_e_a + c42_g_b;
        c42_f_a = c42_b_k;
        c42_h_b = c42_kAcol;
        c42_h_c = c42_f_a + c42_h_b;
        c42_x = c42_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c42_g_c), 1, 16, 1, 0) - 1];
        c42_b_y = c42_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c42_h_c), 1, 16, 1, 0) - 1];
        c42_z = c42_x / c42_b_y;
        c42_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c42_f_c), 1, 16, 1, 0) - 1] = c42_z;
        c42_g_a = c42_b_k;
        c42_i163 = c42_g_a;
        for (c42_c_i = 1; c42_c_i <= c42_i163 - 1; c42_c_i++) {
          c42_d_i = c42_c_i;
          c42_h_a = c42_d_i;
          c42_i_b = c42_jBcol;
          c42_i_c = c42_h_a + c42_i_b;
          c42_i_a = c42_d_i;
          c42_j_b = c42_jBcol;
          c42_j_c = c42_i_a + c42_j_b;
          c42_j_a = c42_b_k;
          c42_k_b = c42_jBcol;
          c42_k_c = c42_j_a + c42_k_b;
          c42_k_a = c42_d_i;
          c42_l_b = c42_kAcol;
          c42_l_c = c42_k_a + c42_l_b;
          c42_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_i_c), 1, 16, 1, 0) - 1] =
            c42_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c42_j_c), 1, 16, 1, 0) - 1] -
            c42_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c42_k_c), 1, 16, 1, 0) - 1] *
            c42_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c42_l_c), 1, 16, 1, 0) - 1];
        }
      }
    }
  }

  c42_i164 = 0;
  for (c42_i165 = 0; c42_i165 < 4; c42_i165++) {
    c42_i166 = 0;
    for (c42_i167 = 0; c42_i167 < 4; c42_i167++) {
      c42_y[c42_i167 + c42_i164] = c42_b_B[c42_i166 + c42_i165];
      c42_i166 += 4;
    }

    c42_i164 += 4;
  }
}

static void c42_eps(SFc42_controller_templateInstanceStruct *chartInstance)
{
}

static void c42_eml_matlab_zgetrf(SFc42_controller_templateInstanceStruct
  *chartInstance, real_T c42_A[16], real_T c42_b_A[16], int32_T c42_ipiv[4],
  int32_T *c42_info)
{
  int32_T c42_i168;
  for (c42_i168 = 0; c42_i168 < 16; c42_i168++) {
    c42_b_A[c42_i168] = c42_A[c42_i168];
  }

  c42_b_eml_matlab_zgetrf(chartInstance, c42_b_A, c42_ipiv, c42_info);
}

static void c42_eml_xgeru(SFc42_controller_templateInstanceStruct *chartInstance,
  int32_T c42_m, int32_T c42_n, real_T c42_alpha1, int32_T c42_ix0, int32_T
  c42_iy0, real_T c42_A[16], int32_T c42_ia0, real_T c42_b_A[16])
{
  int32_T c42_i169;
  for (c42_i169 = 0; c42_i169 < 16; c42_i169++) {
    c42_b_A[c42_i169] = c42_A[c42_i169];
  }

  c42_b_eml_xgeru(chartInstance, c42_m, c42_n, c42_alpha1, c42_ix0, c42_iy0,
                  c42_b_A, c42_ia0);
}

static void c42_eml_warning(SFc42_controller_templateInstanceStruct
  *chartInstance)
{
  int32_T c42_i170;
  static char_T c42_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c42_u[27];
  const mxArray *c42_y = NULL;
  for (c42_i170 = 0; c42_i170 < 27; c42_i170++) {
    c42_u[c42_i170] = c42_varargin_1[c42_i170];
  }

  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", c42_u, 10, 0U, 1U, 0U, 2, 1, 27),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c42_y));
}

static void c42_eml_xtrsm(SFc42_controller_templateInstanceStruct *chartInstance,
  real_T c42_A[16], real_T c42_B[16], real_T c42_b_B[16])
{
  int32_T c42_i171;
  int32_T c42_i172;
  real_T c42_b_A[16];
  for (c42_i171 = 0; c42_i171 < 16; c42_i171++) {
    c42_b_B[c42_i171] = c42_B[c42_i171];
  }

  for (c42_i172 = 0; c42_i172 < 16; c42_i172++) {
    c42_b_A[c42_i172] = c42_A[c42_i172];
  }

  c42_b_eml_xtrsm(chartInstance, c42_b_A, c42_b_B);
}

static void c42_below_threshold(SFc42_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c42_c_eml_scalar_eg(SFc42_controller_templateInstanceStruct
  *chartInstance)
{
}

static void c42_eye(SFc42_controller_templateInstanceStruct *chartInstance,
                    real_T c42_I[16])
{
  int32_T c42_i173;
  int32_T c42_i;
  int32_T c42_b_i;
  for (c42_i173 = 0; c42_i173 < 16; c42_i173++) {
    c42_I[c42_i173] = 0.0;
  }

  for (c42_i = 1; c42_i < 5; c42_i++) {
    c42_b_i = c42_i;
    c42_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c42_b_i), 1, 4, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
              (int32_T)_SFD_INTEGER_CHECK("", (real_T)c42_b_i), 1, 4, 2, 0) - 1)
            << 2)) - 1] = 1.0;
  }
}

static const mxArray *c42_d_sf_marshallOut(void *chartInstanceVoid, void
  *c42_inData)
{
  const mxArray *c42_mxArrayOutData = NULL;
  int32_T c42_u;
  const mxArray *c42_y = NULL;
  SFc42_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc42_controller_templateInstanceStruct *)chartInstanceVoid;
  c42_mxArrayOutData = NULL;
  c42_u = *(int32_T *)c42_inData;
  c42_y = NULL;
  sf_mex_assign(&c42_y, sf_mex_create("y", &c42_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c42_mxArrayOutData, c42_y, FALSE);
  return c42_mxArrayOutData;
}

static int32_T c42_f_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId)
{
  int32_T c42_y;
  int32_T c42_i174;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), &c42_i174, 1, 6, 0U, 0, 0U, 0);
  c42_y = c42_i174;
  sf_mex_destroy(&c42_u);
  return c42_y;
}

static void c42_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c42_mxArrayInData, const char_T *c42_varName, void *c42_outData)
{
  const mxArray *c42_sfEvent;
  const char_T *c42_identifier;
  emlrtMsgIdentifier c42_thisId;
  int32_T c42_y;
  SFc42_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc42_controller_templateInstanceStruct *)chartInstanceVoid;
  c42_sfEvent = sf_mex_dup(c42_mxArrayInData);
  c42_identifier = c42_varName;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_y = c42_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c42_sfEvent),
    &c42_thisId);
  sf_mex_destroy(&c42_sfEvent);
  *(int32_T *)c42_outData = c42_y;
  sf_mex_destroy(&c42_mxArrayInData);
}

static uint8_T c42_g_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_is_active_c42_controller_template, const
  char_T *c42_identifier)
{
  uint8_T c42_y;
  emlrtMsgIdentifier c42_thisId;
  c42_thisId.fIdentifier = c42_identifier;
  c42_thisId.fParent = NULL;
  c42_y = c42_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c42_is_active_c42_controller_template), &c42_thisId);
  sf_mex_destroy(&c42_is_active_c42_controller_template);
  return c42_y;
}

static uint8_T c42_h_emlrt_marshallIn(SFc42_controller_templateInstanceStruct
  *chartInstance, const mxArray *c42_u, const emlrtMsgIdentifier *c42_parentId)
{
  uint8_T c42_y;
  uint8_T c42_u0;
  sf_mex_import(c42_parentId, sf_mex_dup(c42_u), &c42_u0, 1, 3, 0U, 0, 0U, 0);
  c42_y = c42_u0;
  sf_mex_destroy(&c42_u);
  return c42_y;
}

static void c42_b_eml_matlab_zgetrf(SFc42_controller_templateInstanceStruct
  *chartInstance, real_T c42_A[16], int32_T c42_ipiv[4], int32_T *c42_info)
{
  int32_T c42_i175;
  int32_T c42_j;
  int32_T c42_b_j;
  int32_T c42_a;
  int32_T c42_jm1;
  int32_T c42_b;
  int32_T c42_mmj;
  int32_T c42_b_a;
  int32_T c42_c;
  int32_T c42_b_b;
  int32_T c42_jj;
  int32_T c42_c_a;
  int32_T c42_jp1j;
  int32_T c42_d_a;
  int32_T c42_b_c;
  int32_T c42_n;
  int32_T c42_ix0;
  int32_T c42_b_n;
  int32_T c42_b_ix0;
  int32_T c42_c_n;
  int32_T c42_c_ix0;
  int32_T c42_idxmax;
  int32_T c42_ix;
  real_T c42_x;
  real_T c42_b_x;
  real_T c42_c_x;
  real_T c42_y;
  real_T c42_d_x;
  real_T c42_e_x;
  real_T c42_b_y;
  real_T c42_smax;
  int32_T c42_loop_ub;
  int32_T c42_k;
  int32_T c42_b_k;
  int32_T c42_e_a;
  real_T c42_f_x;
  real_T c42_g_x;
  real_T c42_h_x;
  real_T c42_c_y;
  real_T c42_i_x;
  real_T c42_j_x;
  real_T c42_d_y;
  real_T c42_s;
  int32_T c42_f_a;
  int32_T c42_jpiv_offset;
  int32_T c42_g_a;
  int32_T c42_c_b;
  int32_T c42_jpiv;
  int32_T c42_h_a;
  int32_T c42_d_b;
  int32_T c42_c_c;
  int32_T c42_e_b;
  int32_T c42_jrow;
  int32_T c42_i_a;
  int32_T c42_f_b;
  int32_T c42_jprow;
  int32_T c42_d_ix0;
  int32_T c42_iy0;
  int32_T c42_e_ix0;
  int32_T c42_b_iy0;
  int32_T c42_f_ix0;
  int32_T c42_c_iy0;
  int32_T c42_b_ix;
  int32_T c42_iy;
  int32_T c42_c_k;
  real_T c42_temp;
  int32_T c42_j_a;
  int32_T c42_k_a;
  int32_T c42_b_jp1j;
  int32_T c42_l_a;
  int32_T c42_d_c;
  int32_T c42_m_a;
  int32_T c42_g_b;
  int32_T c42_i176;
  int32_T c42_i;
  int32_T c42_b_i;
  real_T c42_k_x;
  real_T c42_e_y;
  real_T c42_z;
  int32_T c42_h_b;
  int32_T c42_e_c;
  int32_T c42_n_a;
  int32_T c42_f_c;
  int32_T c42_o_a;
  int32_T c42_g_c;
  c42_eps(chartInstance);
  for (c42_i175 = 0; c42_i175 < 4; c42_i175++) {
    c42_ipiv[c42_i175] = 1 + c42_i175;
  }

  *c42_info = 0;
  for (c42_j = 1; c42_j < 4; c42_j++) {
    c42_b_j = c42_j;
    c42_a = c42_b_j - 1;
    c42_jm1 = c42_a;
    c42_b = c42_b_j;
    c42_mmj = 4 - c42_b;
    c42_b_a = c42_jm1;
    c42_c = c42_b_a * 5;
    c42_b_b = c42_c + 1;
    c42_jj = c42_b_b;
    c42_c_a = c42_jj + 1;
    c42_jp1j = c42_c_a;
    c42_d_a = c42_mmj;
    c42_b_c = c42_d_a;
    c42_n = c42_b_c + 1;
    c42_ix0 = c42_jj;
    c42_b_n = c42_n;
    c42_b_ix0 = c42_ix0;
    c42_c_n = c42_b_n;
    c42_c_ix0 = c42_b_ix0;
    if ((real_T)c42_c_n < 1.0) {
      c42_idxmax = 0;
    } else {
      c42_idxmax = 1;
      if ((real_T)c42_c_n > 1.0) {
        c42_ix = c42_c_ix0;
        c42_x = c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c42_ix), 1, 16, 1, 0) - 1];
        c42_b_x = c42_x;
        c42_c_x = c42_b_x;
        c42_y = muDoubleScalarAbs(c42_c_x);
        c42_d_x = 0.0;
        c42_e_x = c42_d_x;
        c42_b_y = muDoubleScalarAbs(c42_e_x);
        c42_smax = c42_y + c42_b_y;
        c42_loop_ub = c42_c_n;
        for (c42_k = 2; c42_k <= c42_loop_ub; c42_k++) {
          c42_b_k = c42_k;
          c42_e_a = c42_ix + 1;
          c42_ix = c42_e_a;
          c42_f_x = c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c42_ix), 1, 16, 1, 0) - 1];
          c42_g_x = c42_f_x;
          c42_h_x = c42_g_x;
          c42_c_y = muDoubleScalarAbs(c42_h_x);
          c42_i_x = 0.0;
          c42_j_x = c42_i_x;
          c42_d_y = muDoubleScalarAbs(c42_j_x);
          c42_s = c42_c_y + c42_d_y;
          if (c42_s > c42_smax) {
            c42_idxmax = c42_b_k;
            c42_smax = c42_s;
          }
        }
      }
    }

    c42_f_a = c42_idxmax - 1;
    c42_jpiv_offset = c42_f_a;
    c42_g_a = c42_jj;
    c42_c_b = c42_jpiv_offset;
    c42_jpiv = c42_g_a + c42_c_b;
    if (c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c42_jpiv), 1, 16, 1, 0) - 1] != 0.0) {
      if ((real_T)c42_jpiv_offset != 0.0) {
        c42_h_a = c42_b_j;
        c42_d_b = c42_jpiv_offset;
        c42_c_c = c42_h_a + c42_d_b;
        c42_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c42_b_j), 1, 4, 1, 0) - 1] = c42_c_c;
        c42_e_b = c42_jm1 + 1;
        c42_jrow = c42_e_b;
        c42_i_a = c42_jrow;
        c42_f_b = c42_jpiv_offset;
        c42_jprow = c42_i_a + c42_f_b;
        c42_d_ix0 = c42_jrow;
        c42_iy0 = c42_jprow;
        c42_e_ix0 = c42_d_ix0;
        c42_b_iy0 = c42_iy0;
        c42_f_ix0 = c42_e_ix0;
        c42_c_iy0 = c42_b_iy0;
        c42_b_ix = c42_f_ix0;
        c42_iy = c42_c_iy0;
        for (c42_c_k = 1; c42_c_k < 5; c42_c_k++) {
          c42_temp = c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c42_b_ix), 1, 16, 1, 0) - 1];
          c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_b_ix), 1, 16, 1, 0) - 1] =
            c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_iy), 1, 16, 1, 0) - 1];
          c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_iy), 1, 16, 1, 0) - 1] = c42_temp;
          c42_j_a = c42_b_ix + 4;
          c42_b_ix = c42_j_a;
          c42_k_a = c42_iy + 4;
          c42_iy = c42_k_a;
        }
      }

      c42_b_jp1j = c42_jp1j;
      c42_l_a = c42_mmj;
      c42_d_c = c42_l_a;
      c42_m_a = c42_jp1j;
      c42_g_b = c42_d_c - 1;
      c42_i176 = c42_m_a + c42_g_b;
      for (c42_i = c42_b_jp1j; c42_i <= c42_i176; c42_i++) {
        c42_b_i = c42_i;
        c42_k_x = c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c42_b_i), 1, 16, 1, 0) - 1];
        c42_e_y = c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c42_jj), 1, 16, 1, 0) - 1];
        c42_z = c42_k_x / c42_e_y;
        c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c42_b_i), 1, 16, 1, 0) - 1] = c42_z;
      }
    } else {
      *c42_info = c42_b_j;
    }

    c42_h_b = c42_b_j;
    c42_e_c = 4 - c42_h_b;
    c42_n_a = c42_jj;
    c42_f_c = c42_n_a;
    c42_o_a = c42_jj;
    c42_g_c = c42_o_a;
    c42_b_eml_xgeru(chartInstance, c42_mmj, c42_e_c, -1.0, c42_jp1j, c42_f_c + 4,
                    c42_A, c42_g_c + 5);
  }

  if ((real_T)*c42_info == 0.0) {
    if (!(c42_A[15] != 0.0)) {
      *c42_info = 4;
    }
  }
}

static void c42_b_eml_xgeru(SFc42_controller_templateInstanceStruct
  *chartInstance, int32_T c42_m, int32_T c42_n, real_T c42_alpha1, int32_T
  c42_ix0, int32_T c42_iy0, real_T c42_A[16], int32_T c42_ia0)
{
  int32_T c42_b_m;
  int32_T c42_b_n;
  real_T c42_b_alpha1;
  int32_T c42_b_ix0;
  int32_T c42_b_iy0;
  int32_T c42_b_ia0;
  int32_T c42_c_m;
  int32_T c42_c_n;
  real_T c42_c_alpha1;
  int32_T c42_c_ix0;
  int32_T c42_c_iy0;
  int32_T c42_c_ia0;
  int32_T c42_d_m;
  int32_T c42_d_n;
  real_T c42_d_alpha1;
  int32_T c42_d_ix0;
  int32_T c42_d_iy0;
  int32_T c42_d_ia0;
  int32_T c42_e_m;
  int32_T c42_e_n;
  real_T c42_e_alpha1;
  int32_T c42_e_ix0;
  int32_T c42_e_iy0;
  int32_T c42_e_ia0;
  int32_T c42_ixstart;
  int32_T c42_a;
  int32_T c42_jA;
  int32_T c42_jy;
  int32_T c42_loop_ub;
  int32_T c42_j;
  real_T c42_yjy;
  real_T c42_temp;
  int32_T c42_ix;
  int32_T c42_b;
  int32_T c42_i177;
  int32_T c42_b_a;
  int32_T c42_b_b;
  int32_T c42_i178;
  int32_T c42_ijA;
  int32_T c42_b_ijA;
  int32_T c42_c_a;
  int32_T c42_d_a;
  int32_T c42_e_a;
  c42_b_m = c42_m;
  c42_b_n = c42_n;
  c42_b_alpha1 = c42_alpha1;
  c42_b_ix0 = c42_ix0;
  c42_b_iy0 = c42_iy0;
  c42_b_ia0 = c42_ia0;
  c42_c_m = c42_b_m;
  c42_c_n = c42_b_n;
  c42_c_alpha1 = c42_b_alpha1;
  c42_c_ix0 = c42_b_ix0;
  c42_c_iy0 = c42_b_iy0;
  c42_c_ia0 = c42_b_ia0;
  c42_d_m = c42_c_m;
  c42_d_n = c42_c_n;
  c42_d_alpha1 = c42_c_alpha1;
  c42_d_ix0 = c42_c_ix0;
  c42_d_iy0 = c42_c_iy0;
  c42_d_ia0 = c42_c_ia0;
  c42_e_m = c42_d_m;
  c42_e_n = c42_d_n;
  c42_e_alpha1 = c42_d_alpha1;
  c42_e_ix0 = c42_d_ix0;
  c42_e_iy0 = c42_d_iy0;
  c42_e_ia0 = c42_d_ia0;
  if (c42_e_alpha1 == 0.0) {
  } else {
    c42_ixstart = c42_e_ix0;
    c42_a = c42_e_ia0 - 1;
    c42_jA = c42_a;
    c42_jy = c42_e_iy0;
    c42_loop_ub = c42_e_n;
    for (c42_j = 1; c42_j <= c42_loop_ub; c42_j++) {
      c42_yjy = c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c42_jy), 1, 16, 1, 0) - 1];
      if (c42_yjy != 0.0) {
        c42_temp = c42_yjy * c42_e_alpha1;
        c42_ix = c42_ixstart;
        c42_b = c42_jA;
        c42_i177 = c42_b;
        c42_b_a = c42_e_m;
        c42_b_b = c42_jA;
        c42_i178 = c42_b_a + c42_b_b;
        for (c42_ijA = c42_i177 + 1; c42_ijA <= c42_i178; c42_ijA++) {
          c42_b_ijA = c42_ijA;
          c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_b_ijA), 1, 16, 1, 0) - 1] =
            c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_b_ijA), 1, 16, 1, 0) - 1] +
            c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_ix), 1, 16, 1, 0) - 1] * c42_temp;
          c42_c_a = c42_ix + 1;
          c42_ix = c42_c_a;
        }
      }

      c42_d_a = c42_jy + 4;
      c42_jy = c42_d_a;
      c42_e_a = c42_jA + 4;
      c42_jA = c42_e_a;
    }
  }
}

static void c42_b_eml_xtrsm(SFc42_controller_templateInstanceStruct
  *chartInstance, real_T c42_A[16], real_T c42_B[16])
{
  int32_T c42_j;
  int32_T c42_b_j;
  int32_T c42_a;
  int32_T c42_c;
  int32_T c42_b;
  int32_T c42_b_c;
  int32_T c42_b_b;
  int32_T c42_jBcol;
  int32_T c42_k;
  int32_T c42_b_k;
  int32_T c42_b_a;
  int32_T c42_c_c;
  int32_T c42_c_b;
  int32_T c42_d_c;
  int32_T c42_d_b;
  int32_T c42_kAcol;
  int32_T c42_c_a;
  int32_T c42_e_b;
  int32_T c42_e_c;
  int32_T c42_d_a;
  int32_T c42_i179;
  int32_T c42_i;
  int32_T c42_b_i;
  int32_T c42_e_a;
  int32_T c42_f_b;
  int32_T c42_f_c;
  int32_T c42_f_a;
  int32_T c42_g_b;
  int32_T c42_g_c;
  int32_T c42_g_a;
  int32_T c42_h_b;
  int32_T c42_h_c;
  int32_T c42_h_a;
  int32_T c42_i_b;
  int32_T c42_i_c;
  c42_below_threshold(chartInstance);
  c42_c_eml_scalar_eg(chartInstance);
  for (c42_j = 1; c42_j < 5; c42_j++) {
    c42_b_j = c42_j;
    c42_a = c42_b_j;
    c42_c = c42_a;
    c42_b = c42_c - 1;
    c42_b_c = c42_b << 2;
    c42_b_b = c42_b_c;
    c42_jBcol = c42_b_b;
    for (c42_k = 1; c42_k < 5; c42_k++) {
      c42_b_k = c42_k;
      c42_b_a = c42_b_k;
      c42_c_c = c42_b_a;
      c42_c_b = c42_c_c - 1;
      c42_d_c = c42_c_b << 2;
      c42_d_b = c42_d_c;
      c42_kAcol = c42_d_b;
      c42_c_a = c42_b_k;
      c42_e_b = c42_jBcol;
      c42_e_c = c42_c_a + c42_e_b;
      if (c42_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_e_c), 1, 16, 1, 0) - 1] != 0.0) {
        c42_d_a = c42_b_k;
        c42_i179 = c42_d_a;
        for (c42_i = c42_i179 + 1; c42_i < 5; c42_i++) {
          c42_b_i = c42_i;
          c42_e_a = c42_b_i;
          c42_f_b = c42_jBcol;
          c42_f_c = c42_e_a + c42_f_b;
          c42_f_a = c42_b_i;
          c42_g_b = c42_jBcol;
          c42_g_c = c42_f_a + c42_g_b;
          c42_g_a = c42_b_k;
          c42_h_b = c42_jBcol;
          c42_h_c = c42_g_a + c42_h_b;
          c42_h_a = c42_b_i;
          c42_i_b = c42_kAcol;
          c42_i_c = c42_h_a + c42_i_b;
          c42_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_f_c), 1, 16, 1, 0) - 1] =
            c42_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_g_c), 1, 16, 1, 0) - 1] -
            c42_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_h_c), 1, 16, 1, 0) - 1] *
            c42_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c42_i_c), 1, 16, 1, 0) - 1];
        }
      }
    }
  }
}

static void init_dsm_address_info(SFc42_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c42_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3506836527U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1763714348U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(361166757U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(464788670U);
}

mxArray *sf_c42_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("J0hki1maG3UDcJmcU52UZG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,11,3,dataFields);

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
      pr[0] = (double)(4);
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
      pr[0] = (double)(1);
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
      pr[1] = (double)(1);
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
      pr[0] = (double)(4);
      pr[1] = (double)(1);
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
      pr[0] = (double)(4);
      pr[1] = (double)(4);
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
      pr[0] = (double)(4);
      pr[1] = (double)(4);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c42_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[16],T\"Pmeas\",},{M[1],M[5],T\"x_meas\",},{M[8],M[0],T\"is_active_c42_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c42_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc42_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc42_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           42,
           1,
           1,
           13,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Ax");
          _SFD_SET_DATA_PROPS(1,1,1,0,"Bx");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Cx");
          _SFD_SET_DATA_PROPS(3,1,1,0,"u");
          _SFD_SET_DATA_PROPS(4,2,0,1,"x_meas");
          _SFD_SET_DATA_PROPS(5,1,1,0,"z");
          _SFD_SET_DATA_PROPS(6,1,1,0,"x_prev");
          _SFD_SET_DATA_PROPS(7,1,1,0,"P_prev");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Qp");
          _SFD_SET_DATA_PROPS(9,1,1,0,"Rn");
          _SFD_SET_DATA_PROPS(10,1,1,0,"flag_init");
          _SFD_SET_DATA_PROPS(11,1,1,0,"flag_fault");
          _SFD_SET_DATA_PROPS(12,2,0,1,"Pmeas");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,567);
        _SFD_CV_INIT_EML_IF(0,1,0,118,130,168,239);
        _SFD_CV_INIT_EML_IF(0,1,1,282,295,-1,343);
        _SFD_CV_INIT_EML_IF(0,1,2,492,505,-1,562);
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
            1.0,0,0,(MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_b_sf_marshallOut,(MexInFcnForType)
            c42_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c42_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c42_sf_marshallOut,(MexInFcnForType)
            c42_sf_marshallIn);
        }

        {
          real_T *c42_u;
          real_T *c42_flag_init;
          real_T *c42_flag_fault;
          real_T (*c42_Ax)[16];
          real_T (*c42_Bx)[4];
          real_T (*c42_Cx)[16];
          real_T (*c42_x_meas)[4];
          real_T (*c42_z)[4];
          real_T (*c42_x_prev)[4];
          real_T (*c42_P_prev)[16];
          real_T (*c42_Qp)[16];
          real_T (*c42_Rn)[16];
          real_T (*c42_Pmeas)[16];
          c42_Pmeas = (real_T (*)[16])ssGetOutputPortSignal(chartInstance->S, 2);
          c42_flag_fault = (real_T *)ssGetInputPortSignal(chartInstance->S, 10);
          c42_flag_init = (real_T *)ssGetInputPortSignal(chartInstance->S, 9);
          c42_Rn = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 8);
          c42_Qp = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 7);
          c42_P_prev = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 6);
          c42_x_prev = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
          c42_z = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
          c42_x_meas = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c42_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c42_Cx = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 2);
          c42_Bx = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 1);
          c42_Ax = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c42_Ax);
          _SFD_SET_DATA_VALUE_PTR(1U, *c42_Bx);
          _SFD_SET_DATA_VALUE_PTR(2U, *c42_Cx);
          _SFD_SET_DATA_VALUE_PTR(3U, c42_u);
          _SFD_SET_DATA_VALUE_PTR(4U, *c42_x_meas);
          _SFD_SET_DATA_VALUE_PTR(5U, *c42_z);
          _SFD_SET_DATA_VALUE_PTR(6U, *c42_x_prev);
          _SFD_SET_DATA_VALUE_PTR(7U, *c42_P_prev);
          _SFD_SET_DATA_VALUE_PTR(8U, *c42_Qp);
          _SFD_SET_DATA_VALUE_PTR(9U, *c42_Rn);
          _SFD_SET_DATA_VALUE_PTR(10U, c42_flag_init);
          _SFD_SET_DATA_VALUE_PTR(11U, c42_flag_fault);
          _SFD_SET_DATA_VALUE_PTR(12U, *c42_Pmeas);
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
      42, "dworkChecksum");
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

static void sf_opaque_initialize_c42_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc42_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc42_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c42_controller_template
    ((SFc42_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c42_controller_template((SFc42_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c42_controller_template(void *chartInstanceVar)
{
  enable_c42_controller_template((SFc42_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c42_controller_template(void *chartInstanceVar)
{
  disable_c42_controller_template((SFc42_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c42_controller_template(void *chartInstanceVar)
{
  sf_c42_controller_template((SFc42_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c42_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c42_controller_template((SFc42_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c42_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c42_controller_template
    ((SFc42_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c42_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c42_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c42_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c42_controller_template((SFc42_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c42_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c42_controller_template(S);
}

static void sf_opaque_set_sim_state_c42_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c42_controller_template(S, st);
}

static void sf_opaque_terminate_c42_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc42_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c42_controller_template((SFc42_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc42_controller_template((SFc42_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c42_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c42_controller_template
      ((SFc42_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c42_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c42_controller_template\",T\"is_active_c42_controller_template\"}}"
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

static void mdlSetWorkWidths_c42_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,42);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,42,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,42,
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
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,42,11);
      sf_mark_chart_reusable_outputs(S,infoStruct,42,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,42);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1617656043U));
  ssSetChecksum1(S,(1338769285U));
  ssSetChecksum2(S,(3097575699U));
  ssSetChecksum3(S,(2104897776U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c42_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c42_controller_template(SimStruct *S)
{
  SFc42_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc42_controller_templateInstanceStruct *)malloc(sizeof
    (SFc42_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc42_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c42_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c42_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c42_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c42_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c42_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c42_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c42_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c42_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c42_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c42_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c42_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c42_controller_template;
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

void c42_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c42_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c42_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c42_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c42_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
