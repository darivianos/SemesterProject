/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c24_controller_template.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c24_debug_family_names[23] = { "tolerance", "nr",
  "MPT_ABSTOL", "minreg", "Hi", "Ki", "abspos", "sumViol", "isinside", "F", "G",
  "nc", "hx", "nargin", "nargout", "X", "Hn", "Kn", "Fi", "Gi", "Nc", "U",
  "flag_oob" };

/* Function Declarations */
static void initialize_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance);
static void enable_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance);
static void disable_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance);
static void c24_update_debugger_state_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance, const mxArray *c24_st);
static void finalize_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance);
static void sf_c24_controller_template(SFc24_controller_templateInstanceStruct
  *chartInstance);
static void c24_chartstep_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance);
static void initSimStructsc24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber);
static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_flag_oob, const char_T *c24_identifier);
static real_T c24_b_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static const mxArray *c24_e_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static const mxArray *c24_f_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static const mxArray *c24_g_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_c_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[4]);
static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_h_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_d_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[1000]);
static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_i_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_e_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[4000]);
static void c24_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static void c24_info_helper(c24_ResolvedFunctionInfo c24_info[18]);
static void c24_round(SFc24_controller_templateInstanceStruct *chartInstance,
                      real_T c24_x[4], real_T c24_b_x[4]);
static void c24_mrdivide(SFc24_controller_templateInstanceStruct *chartInstance,
  real_T c24_A[4], real_T c24_B, real_T c24_y[4]);
static void c24_eml_scalar_eg(SFc24_controller_templateInstanceStruct
  *chartInstance);
static const mxArray *c24_j_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static int32_T c24_f_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static uint8_T c24_g_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_is_active_c24_controller_template, const
  char_T *c24_identifier);
static uint8_T c24_h_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_b_round(SFc24_controller_templateInstanceStruct *chartInstance,
  real_T c24_x[4]);
static void init_dsm_address_info(SFc24_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c24_sfEvent;
  uint8_T *c24_is_active_c24_controller_template;
  c24_is_active_c24_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c24_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c24_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c24_is_active_c24_controller_template = 0U;
}

static void initialize_params_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c24_update_debugger_state_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance)
{
  c24_update_debugger_state_c24_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c24_st;
  const mxArray *c24_y = NULL;
  real_T c24_hoistedGlobal;
  real_T c24_u;
  const mxArray *c24_b_y = NULL;
  real_T c24_b_hoistedGlobal;
  real_T c24_b_u;
  const mxArray *c24_c_y = NULL;
  uint8_T c24_c_hoistedGlobal;
  uint8_T c24_c_u;
  const mxArray *c24_d_y = NULL;
  real_T *c24_U;
  real_T *c24_flag_oob;
  uint8_T *c24_is_active_c24_controller_template;
  c24_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c24_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c24_is_active_c24_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c24_st = NULL;
  c24_st = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createcellarray(3), FALSE);
  c24_hoistedGlobal = *c24_U;
  c24_u = c24_hoistedGlobal;
  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c24_y, 0, c24_b_y);
  c24_b_hoistedGlobal = *c24_flag_oob;
  c24_b_u = c24_b_hoistedGlobal;
  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", &c24_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c24_y, 1, c24_c_y);
  c24_c_hoistedGlobal = *c24_is_active_c24_controller_template;
  c24_c_u = c24_c_hoistedGlobal;
  c24_d_y = NULL;
  sf_mex_assign(&c24_d_y, sf_mex_create("y", &c24_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c24_y, 2, c24_d_y);
  sf_mex_assign(&c24_st, c24_y, FALSE);
  return c24_st;
}

static void set_sim_state_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance, const mxArray *c24_st)
{
  const mxArray *c24_u;
  boolean_T *c24_doneDoubleBufferReInit;
  real_T *c24_U;
  real_T *c24_flag_oob;
  uint8_T *c24_is_active_c24_controller_template;
  c24_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c24_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c24_is_active_c24_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c24_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c24_doneDoubleBufferReInit = TRUE;
  c24_u = sf_mex_dup(c24_st);
  *c24_U = c24_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u,
    0)), "U");
  *c24_flag_oob = c24_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c24_u, 1)), "flag_oob");
  *c24_is_active_c24_controller_template = c24_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c24_u, 2)), "is_active_c24_controller_template");
  sf_mex_destroy(&c24_u);
  c24_update_debugger_state_c24_controller_template(chartInstance);
  sf_mex_destroy(&c24_st);
}

static void finalize_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c24_controller_template(SFc24_controller_templateInstanceStruct
  *chartInstance)
{
  int32_T c24_i0;
  int32_T c24_i1;
  int32_T c24_i2;
  int32_T c24_i3;
  int32_T c24_i4;
  int32_T c24_i5;
  int32_T *c24_sfEvent;
  real_T *c24_U;
  real_T *c24_flag_oob;
  real_T (*c24_Nc)[134];
  real_T (*c24_Gi)[134];
  real_T (*c24_Fi)[536];
  real_T (*c24_Kn)[1116];
  real_T (*c24_Hn)[4464];
  real_T (*c24_X)[4];
  c24_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c24_Nc = (real_T (*)[134])ssGetInputPortSignal(chartInstance->S, 5);
  c24_Gi = (real_T (*)[134])ssGetInputPortSignal(chartInstance->S, 4);
  c24_Fi = (real_T (*)[536])ssGetInputPortSignal(chartInstance->S, 3);
  c24_Kn = (real_T (*)[1116])ssGetInputPortSignal(chartInstance->S, 2);
  c24_Hn = (real_T (*)[4464])ssGetInputPortSignal(chartInstance->S, 1);
  c24_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c24_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c24_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 22U, *c24_sfEvent);
  for (c24_i0 = 0; c24_i0 < 4; c24_i0++) {
    _SFD_DATA_RANGE_CHECK((*c24_X)[c24_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c24_U, 1U);
  for (c24_i1 = 0; c24_i1 < 4464; c24_i1++) {
    _SFD_DATA_RANGE_CHECK((*c24_Hn)[c24_i1], 2U);
  }

  for (c24_i2 = 0; c24_i2 < 1116; c24_i2++) {
    _SFD_DATA_RANGE_CHECK((*c24_Kn)[c24_i2], 3U);
  }

  for (c24_i3 = 0; c24_i3 < 536; c24_i3++) {
    _SFD_DATA_RANGE_CHECK((*c24_Fi)[c24_i3], 4U);
  }

  for (c24_i4 = 0; c24_i4 < 134; c24_i4++) {
    _SFD_DATA_RANGE_CHECK((*c24_Gi)[c24_i4], 5U);
  }

  for (c24_i5 = 0; c24_i5 < 134; c24_i5++) {
    _SFD_DATA_RANGE_CHECK((*c24_Nc)[c24_i5], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c24_flag_oob, 7U);
  *c24_sfEvent = CALL_EVENT;
  c24_chartstep_c24_controller_template(chartInstance);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c24_chartstep_c24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance)
{
  int32_T c24_i6;
  real_T c24_X[4];
  int32_T c24_i7;
  real_T c24_Hn[4464];
  int32_T c24_i8;
  real_T c24_Kn[1116];
  int32_T c24_i9;
  real_T c24_Fi[536];
  int32_T c24_i10;
  real_T c24_Gi[134];
  int32_T c24_i11;
  real_T c24_Nc[134];
  uint32_T c24_debug_family_var_map[23];
  real_T c24_tolerance;
  real_T c24_nr;
  real_T c24_MPT_ABSTOL;
  real_T c24_minreg;
  real_T c24_Hi[4000];
  real_T c24_Ki[1000];
  real_T c24_abspos;
  real_T c24_sumViol;
  real_T c24_isinside;
  real_T c24_F[4];
  real_T c24_G;
  real_T c24_nc;
  real_T c24_hx;
  real_T c24_nargin = 6.0;
  real_T c24_nargout = 2.0;
  real_T c24_U;
  real_T c24_flag_oob;
  int32_T c24_i12;
  real_T c24_b[4];
  int32_T c24_i13;
  int32_T c24_i14;
  real_T c24_b_b[4];
  real_T c24_dv0[4];
  int32_T c24_i15;
  int32_T c24_i16;
  int32_T c24_i17;
  int32_T c24_ireg;
  real_T c24_b_ireg;
  real_T c24_d0;
  int32_T c24_i18;
  int32_T c24_loop_ub;
  int32_T c24_i;
  real_T c24_b_i;
  int32_T c24_j;
  real_T c24_b_j;
  real_T c24_d1;
  int32_T c24_i19;
  int32_T c24_b_loop_ub;
  int32_T c24_c_i;
  int32_T c24_c_ireg;
  int32_T c24_i20;
  int32_T c24_i21;
  int32_T c24_c_loop_ub;
  int32_T c24_ic;
  real_T c24_b_ic;
  int32_T c24_c_ic;
  int32_T c24_i22;
  real_T c24_a[4];
  int32_T c24_i23;
  int32_T c24_k;
  int32_T c24_b_k;
  int32_T c24_i24;
  int32_T c24_i25;
  real_T c24_y;
  int32_T c24_c_k;
  int32_T c24_d_k;
  int32_T c24_b_minreg;
  int32_T c24_i26;
  int32_T c24_i27;
  int32_T c24_i28;
  real_T c24_b_y;
  int32_T c24_e_k;
  int32_T c24_f_k;
  real_T *c24_b_U;
  real_T *c24_b_flag_oob;
  real_T (*c24_b_Nc)[134];
  real_T (*c24_b_Gi)[134];
  real_T (*c24_b_Fi)[536];
  real_T (*c24_b_Kn)[1116];
  real_T (*c24_b_Hn)[4464];
  real_T (*c24_b_X)[4];
  int32_T *c24_sfEvent;
  int32_T exitg1;
  c24_b_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c24_b_Nc = (real_T (*)[134])ssGetInputPortSignal(chartInstance->S, 5);
  c24_b_Gi = (real_T (*)[134])ssGetInputPortSignal(chartInstance->S, 4);
  c24_b_Fi = (real_T (*)[536])ssGetInputPortSignal(chartInstance->S, 3);
  c24_b_Kn = (real_T (*)[1116])ssGetInputPortSignal(chartInstance->S, 2);
  c24_b_Hn = (real_T (*)[4464])ssGetInputPortSignal(chartInstance->S, 1);
  c24_b_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c24_b_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c24_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 22U, *c24_sfEvent);
  for (c24_i6 = 0; c24_i6 < 4; c24_i6++) {
    c24_X[c24_i6] = (*c24_b_X)[c24_i6];
  }

  for (c24_i7 = 0; c24_i7 < 4464; c24_i7++) {
    c24_Hn[c24_i7] = (*c24_b_Hn)[c24_i7];
  }

  for (c24_i8 = 0; c24_i8 < 1116; c24_i8++) {
    c24_Kn[c24_i8] = (*c24_b_Kn)[c24_i8];
  }

  for (c24_i9 = 0; c24_i9 < 536; c24_i9++) {
    c24_Fi[c24_i9] = (*c24_b_Fi)[c24_i9];
  }

  for (c24_i10 = 0; c24_i10 < 134; c24_i10++) {
    c24_Gi[c24_i10] = (*c24_b_Gi)[c24_i10];
  }

  for (c24_i11 = 0; c24_i11 < 134; c24_i11++) {
    c24_Nc[c24_i11] = (*c24_b_Nc)[c24_i11];
  }

  sf_debug_symbol_scope_push_eml(0U, 23U, 23U, c24_debug_family_names,
    c24_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c24_tolerance, 0U,
    c24_sf_marshallOut, c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c24_nr, 1U, c24_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c24_MPT_ABSTOL, 2U,
    c24_sf_marshallOut, c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_minreg, 3U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c24_Hi, 4U, c24_i_sf_marshallOut,
    c24_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c24_Ki, 5U, c24_h_sf_marshallOut,
    c24_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_abspos, 6U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_sumViol, 7U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_isinside, 8U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c24_F, 9U, c24_g_sf_marshallOut,
    c24_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_G, 10U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_nc, 11U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_hx, 12U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_nargin, 13U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_nargout, 14U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c24_X, 15U, c24_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c24_Hn, 16U, c24_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c24_Kn, 17U, c24_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c24_Fi, 18U, c24_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c24_Gi, 19U, c24_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c24_Nc, 20U, c24_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c24_U, 21U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_flag_oob, 22U,
    c24_sf_marshallOut, c24_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c24_sfEvent, 3);
  c24_tolerance = 1.0;
  _SFD_EML_CALL(0U, *c24_sfEvent, 4);
  c24_nr = 134.0;
  _SFD_EML_CALL(0U, *c24_sfEvent, 5);
  c24_MPT_ABSTOL = 1.0E-8;
  _SFD_EML_CALL(0U, *c24_sfEvent, 6);
  c24_minreg = 0.0;
  _SFD_EML_CALL(0U, *c24_sfEvent, 7);
  for (c24_i12 = 0; c24_i12 < 4; c24_i12++) {
    c24_b[c24_i12] = c24_X[c24_i12];
  }

  for (c24_i13 = 0; c24_i13 < 4; c24_i13++) {
    c24_b[c24_i13] *= 10000.0;
  }

  c24_b_round(chartInstance, c24_b);
  for (c24_i14 = 0; c24_i14 < 4; c24_i14++) {
    c24_b_b[c24_i14] = c24_b[c24_i14];
  }

  c24_mrdivide(chartInstance, c24_b_b, 10000.0, c24_dv0);
  for (c24_i15 = 0; c24_i15 < 4; c24_i15++) {
    c24_X[c24_i15] = c24_dv0[c24_i15];
  }

  _SFD_EML_CALL(0U, *c24_sfEvent, 9);
  c24_flag_oob = 0.0;
  _SFD_EML_CALL(0U, *c24_sfEvent, 12);
  for (c24_i16 = 0; c24_i16 < 4000; c24_i16++) {
    c24_Hi[c24_i16] = 0.0;
  }

  _SFD_EML_CALL(0U, *c24_sfEvent, 13);
  for (c24_i17 = 0; c24_i17 < 1000; c24_i17++) {
    c24_Ki[c24_i17] = 0.0;
  }

  _SFD_EML_CALL(0U, *c24_sfEvent, 16);
  c24_abspos = 1.0;
  c24_ireg = 0;
  do {
    exitg1 = 0U;
    if (c24_ireg < 134) {
      c24_b_ireg = 1.0 + (real_T)c24_ireg;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, *c24_sfEvent, 18);
      c24_sumViol = 0.0;
      _SFD_EML_CALL(0U, *c24_sfEvent, 19);
      c24_isinside = 1.0;
      c24_d0 = c24_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c24_b_ireg), 1, 134, 1, 0) - 1];
      c24_i18 = (int32_T)c24_d0;
      sf_debug_for_loop_vector_check(1.0, 1.0, c24_d0, mxDOUBLE_CLASS, c24_i18);
      c24_loop_ub = c24_i18;
      c24_i = 0;
      while (c24_i <= c24_loop_ub - 1) {
        c24_b_i = 1.0 + (real_T)c24_i;
        CV_EML_FOR(0, 1, 1, 1);
        c24_j = 0;
        while (c24_j < 4) {
          c24_b_j = 1.0 + (real_T)c24_j;
          CV_EML_FOR(0, 1, 2, 1);
          _SFD_EML_CALL(0U, *c24_sfEvent, 25);
          c24_Hi[(_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)_SFD_INTEGER_CHECK(
                    "i", c24_b_i), 1, 1000, 1, 0) + 1000 *
                  (_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)_SFD_INTEGER_CHECK
                    ("j", c24_b_j), 1, 4, 2, 0) - 1)) - 1] = c24_Hn
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)_SFD_INTEGER_CHECK(
                "abspos + i - 1", (c24_abspos + c24_b_i) - 1.0), 1, 1116, 1, 0)
              + 1116 * (_SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)
                _SFD_INTEGER_CHECK("j", c24_b_j), 1, 4, 2, 0) - 1)) - 1];
          c24_j++;
          sf_mex_listen_for_ctrl_c(chartInstance->S);
        }

        CV_EML_FOR(0, 1, 2, 0);
        c24_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 1, 0);
      c24_d1 = c24_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c24_b_ireg), 1, 134, 1, 0) - 1];
      c24_i19 = (int32_T)c24_d1;
      sf_debug_for_loop_vector_check(1.0, 1.0, c24_d1, mxDOUBLE_CLASS, c24_i19);
      c24_b_loop_ub = c24_i19;
      c24_c_i = 0;
      while (c24_c_i <= c24_b_loop_ub - 1) {
        c24_b_i = 1.0 + (real_T)c24_c_i;
        CV_EML_FOR(0, 1, 3, 1);
        _SFD_EML_CALL(0U, *c24_sfEvent, 31);
        c24_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)_SFD_INTEGER_CHECK("i",
          c24_b_i), 1, 1000, 1, 0) - 1] = c24_Kn[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "Kn", (int32_T)_SFD_INTEGER_CHECK("abspos + i - 1", (c24_abspos +
          c24_b_i) - 1.0), 1, 1116, 1, 0) - 1];
        c24_c_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 3, 0);
      _SFD_EML_CALL(0U, *c24_sfEvent, 33);
      c24_abspos += c24_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c24_b_ireg), 1, 134, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c24_sfEvent, 35);
      c24_c_ireg = _SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)_SFD_INTEGER_CHECK
        ("ireg", c24_b_ireg), 1, 134, 1, 0) - 1;
      for (c24_i20 = 0; c24_i20 < 4; c24_i20++) {
        c24_F[c24_i20] = c24_Fi[c24_c_ireg + 134 * c24_i20];
      }

      _SFD_EML_CALL(0U, *c24_sfEvent, 36);
      c24_G = c24_Gi[_SFD_EML_ARRAY_BOUNDS_CHECK("Gi", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c24_b_ireg), 1, 134, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c24_sfEvent, 38);
      c24_nc = c24_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c24_b_ireg), 1, 134, 1, 0) - 1];
      c24_i21 = (int32_T)c24_nc;
      sf_debug_for_loop_vector_check(1.0, 1.0, c24_nc, mxDOUBLE_CLASS, c24_i21);
      c24_c_loop_ub = c24_i21;
      c24_ic = 0;
      while (c24_ic <= c24_c_loop_ub - 1) {
        c24_b_ic = 1.0 + (real_T)c24_ic;
        CV_EML_FOR(0, 1, 4, 1);
        _SFD_EML_CALL(0U, *c24_sfEvent, 41);
        c24_c_ic = _SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)_SFD_INTEGER_CHECK
          ("ic", c24_b_ic), 1, 1000, 1, 0) - 1;
        for (c24_i22 = 0; c24_i22 < 4; c24_i22++) {
          c24_a[c24_i22] = c24_Hi[c24_c_ic + 1000 * c24_i22];
        }

        for (c24_i23 = 0; c24_i23 < 4; c24_i23++) {
          c24_b[c24_i23] = c24_X[c24_i23];
        }

        c24_eml_scalar_eg(chartInstance);
        c24_eml_scalar_eg(chartInstance);
        c24_hx = 0.0;
        for (c24_k = 1; c24_k < 5; c24_k++) {
          c24_b_k = c24_k;
          c24_hx += c24_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c24_b_k), 1, 4, 1, 0) - 1] *
            c24_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c24_b_k), 1, 4, 1, 0) - 1];
        }

        _SFD_EML_CALL(0U, *c24_sfEvent, 42);
        if (CV_EML_IF(0, 1, 0, c24_hx - c24_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki",
              (int32_T)_SFD_INTEGER_CHECK("ic", c24_b_ic), 1, 1000, 1, 0) - 1] >
                      c24_MPT_ABSTOL)) {
          _SFD_EML_CALL(0U, *c24_sfEvent, 43);
          c24_isinside = 0.0;
          _SFD_EML_CALL(0U, *c24_sfEvent, 44);
          c24_sumViol += c24_hx - c24_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki",
            (int32_T)_SFD_INTEGER_CHECK("ic", c24_b_ic), 1, 1000, 1, 0) - 1];
        }

        c24_ic++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 4, 0);
      _SFD_EML_CALL(0U, *c24_sfEvent, 48);
      if (CV_EML_IF(0, 1, 1, c24_sumViol < c24_tolerance)) {
        _SFD_EML_CALL(0U, *c24_sfEvent, 49);
        c24_tolerance = c24_sumViol;
        _SFD_EML_CALL(0U, *c24_sfEvent, 50);
        c24_minreg = c24_b_ireg;
      }

      _SFD_EML_CALL(0U, *c24_sfEvent, 53);
      if (CV_EML_IF(0, 1, 2, c24_isinside == 1.0)) {
        _SFD_EML_CALL(0U, *c24_sfEvent, 54);
        for (c24_i24 = 0; c24_i24 < 4; c24_i24++) {
          c24_a[c24_i24] = c24_F[c24_i24];
        }

        for (c24_i25 = 0; c24_i25 < 4; c24_i25++) {
          c24_b[c24_i25] = c24_X[c24_i25];
        }

        c24_eml_scalar_eg(chartInstance);
        c24_eml_scalar_eg(chartInstance);
        c24_y = 0.0;
        for (c24_c_k = 1; c24_c_k < 5; c24_c_k++) {
          c24_d_k = c24_c_k;
          c24_y += c24_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c24_d_k), 1, 4, 1, 0) - 1] *
            c24_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c24_d_k), 1, 4, 1, 0) - 1];
        }

        c24_U = c24_y + c24_G;
        exitg1 = 1U;
      } else {
        c24_ireg++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }
    } else {
      CV_EML_FOR(0, 1, 0, 0);
      _SFD_EML_CALL(0U, *c24_sfEvent, 58);
      c24_b_minreg = _SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)
        _SFD_INTEGER_CHECK("minreg", c24_minreg), 1, 134, 1, 0) - 1;
      for (c24_i26 = 0; c24_i26 < 4; c24_i26++) {
        c24_F[c24_i26] = c24_Fi[c24_b_minreg + 134 * c24_i26];
      }

      _SFD_EML_CALL(0U, *c24_sfEvent, 59);
      c24_G = c24_Gi[_SFD_EML_ARRAY_BOUNDS_CHECK("Gi", (int32_T)
        _SFD_INTEGER_CHECK("minreg", c24_minreg), 1, 134, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c24_sfEvent, 60);
      for (c24_i27 = 0; c24_i27 < 4; c24_i27++) {
        c24_a[c24_i27] = c24_F[c24_i27];
      }

      for (c24_i28 = 0; c24_i28 < 4; c24_i28++) {
        c24_b[c24_i28] = c24_X[c24_i28];
      }

      c24_eml_scalar_eg(chartInstance);
      c24_eml_scalar_eg(chartInstance);
      c24_b_y = 0.0;
      for (c24_e_k = 1; c24_e_k < 5; c24_e_k++) {
        c24_f_k = c24_e_k;
        c24_b_y += c24_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c24_f_k), 1, 4, 1, 0) - 1] *
          c24_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c24_f_k), 1, 4, 1, 0) - 1];
      }

      c24_U = c24_b_y + c24_G;
      _SFD_EML_CALL(0U, *c24_sfEvent, 61);
      c24_flag_oob = 1.0;
      exitg1 = 1U;
    }
  } while (exitg1 == 0U);

  _SFD_EML_CALL(0U, *c24_sfEvent, -61);
  sf_debug_symbol_scope_pop();
  *c24_b_U = c24_U;
  *c24_b_flag_oob = c24_flag_oob;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, *c24_sfEvent);
}

static void initSimStructsc24_controller_template
  (SFc24_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber)
{
}

static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static real_T c24_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_flag_oob, const char_T *c24_identifier)
{
  real_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_flag_oob),
    &c24_thisId);
  sf_mex_destroy(&c24_flag_oob);
  return c24_y;
}

static real_T c24_b_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d2;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d2, 1, 0, 0U, 0, 0U, 0);
  c24_y = c24_d2;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_flag_oob;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_flag_oob = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_flag_oob),
    &c24_thisId);
  sf_mex_destroy(&c24_flag_oob);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i29;
  real_T c24_b_inData[134];
  int32_T c24_i30;
  real_T c24_u[134];
  const mxArray *c24_y = NULL;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i29 = 0; c24_i29 < 134; c24_i29++) {
    c24_b_inData[c24_i29] = (*(real_T (*)[134])c24_inData)[c24_i29];
  }

  for (c24_i30 = 0; c24_i30 < 134; c24_i30++) {
    c24_u[c24_i30] = c24_b_inData[c24_i30];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 134), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i31;
  int32_T c24_i32;
  int32_T c24_i33;
  real_T c24_b_inData[536];
  int32_T c24_i34;
  int32_T c24_i35;
  int32_T c24_i36;
  real_T c24_u[536];
  const mxArray *c24_y = NULL;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_i31 = 0;
  for (c24_i32 = 0; c24_i32 < 4; c24_i32++) {
    for (c24_i33 = 0; c24_i33 < 134; c24_i33++) {
      c24_b_inData[c24_i33 + c24_i31] = (*(real_T (*)[536])c24_inData)[c24_i33 +
        c24_i31];
    }

    c24_i31 += 134;
  }

  c24_i34 = 0;
  for (c24_i35 = 0; c24_i35 < 4; c24_i35++) {
    for (c24_i36 = 0; c24_i36 < 134; c24_i36++) {
      c24_u[c24_i36 + c24_i34] = c24_b_inData[c24_i36 + c24_i34];
    }

    c24_i34 += 134;
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 134, 4),
                FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i37;
  real_T c24_b_inData[1116];
  int32_T c24_i38;
  real_T c24_u[1116];
  const mxArray *c24_y = NULL;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i37 = 0; c24_i37 < 1116; c24_i37++) {
    c24_b_inData[c24_i37] = (*(real_T (*)[1116])c24_inData)[c24_i37];
  }

  for (c24_i38 = 0; c24_i38 < 1116; c24_i38++) {
    c24_u[c24_i38] = c24_b_inData[c24_i38];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 1116), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static const mxArray *c24_e_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i39;
  int32_T c24_i40;
  int32_T c24_i41;
  real_T c24_b_inData[4464];
  int32_T c24_i42;
  int32_T c24_i43;
  int32_T c24_i44;
  real_T c24_u[4464];
  const mxArray *c24_y = NULL;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_i39 = 0;
  for (c24_i40 = 0; c24_i40 < 4; c24_i40++) {
    for (c24_i41 = 0; c24_i41 < 1116; c24_i41++) {
      c24_b_inData[c24_i41 + c24_i39] = (*(real_T (*)[4464])c24_inData)[c24_i41
        + c24_i39];
    }

    c24_i39 += 1116;
  }

  c24_i42 = 0;
  for (c24_i43 = 0; c24_i43 < 4; c24_i43++) {
    for (c24_i44 = 0; c24_i44 < 1116; c24_i44++) {
      c24_u[c24_i44 + c24_i42] = c24_b_inData[c24_i44 + c24_i42];
    }

    c24_i42 += 1116;
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 1116, 4),
                FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static const mxArray *c24_f_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i45;
  real_T c24_b_inData[4];
  int32_T c24_i46;
  real_T c24_u[4];
  const mxArray *c24_y = NULL;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i45 = 0; c24_i45 < 4; c24_i45++) {
    c24_b_inData[c24_i45] = (*(real_T (*)[4])c24_inData)[c24_i45];
  }

  for (c24_i46 = 0; c24_i46 < 4; c24_i46++) {
    c24_u[c24_i46] = c24_b_inData[c24_i46];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static const mxArray *c24_g_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i47;
  real_T c24_b_inData[4];
  int32_T c24_i48;
  real_T c24_u[4];
  const mxArray *c24_y = NULL;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i47 = 0; c24_i47 < 4; c24_i47++) {
    c24_b_inData[c24_i47] = (*(real_T (*)[4])c24_inData)[c24_i47];
  }

  for (c24_i48 = 0; c24_i48 < 4; c24_i48++) {
    c24_u[c24_i48] = c24_b_inData[c24_i48];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static void c24_c_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[4])
{
  real_T c24_dv1[4];
  int32_T c24_i49;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv1, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c24_i49 = 0; c24_i49 < 4; c24_i49++) {
    c24_y[c24_i49] = c24_dv1[c24_i49];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_F;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[4];
  int32_T c24_i50;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_F = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_F), &c24_thisId, c24_y);
  sf_mex_destroy(&c24_F);
  for (c24_i50 = 0; c24_i50 < 4; c24_i50++) {
    (*(real_T (*)[4])c24_outData)[c24_i50] = c24_y[c24_i50];
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_h_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i51;
  real_T c24_b_inData[1000];
  int32_T c24_i52;
  real_T c24_u[1000];
  const mxArray *c24_y = NULL;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i51 = 0; c24_i51 < 1000; c24_i51++) {
    c24_b_inData[c24_i51] = (*(real_T (*)[1000])c24_inData)[c24_i51];
  }

  for (c24_i52 = 0; c24_i52 < 1000; c24_i52++) {
    c24_u[c24_i52] = c24_b_inData[c24_i52];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 1000), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static void c24_d_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[1000])
{
  real_T c24_dv2[1000];
  int32_T c24_i53;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv2, 1, 0, 0U, 1, 0U, 1,
                1000);
  for (c24_i53 = 0; c24_i53 < 1000; c24_i53++) {
    c24_y[c24_i53] = c24_dv2[c24_i53];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_Ki;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[1000];
  int32_T c24_i54;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_Ki = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_Ki), &c24_thisId, c24_y);
  sf_mex_destroy(&c24_Ki);
  for (c24_i54 = 0; c24_i54 < 1000; c24_i54++) {
    (*(real_T (*)[1000])c24_outData)[c24_i54] = c24_y[c24_i54];
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_i_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i55;
  int32_T c24_i56;
  int32_T c24_i57;
  real_T c24_b_inData[4000];
  int32_T c24_i58;
  int32_T c24_i59;
  int32_T c24_i60;
  real_T c24_u[4000];
  const mxArray *c24_y = NULL;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_i55 = 0;
  for (c24_i56 = 0; c24_i56 < 4; c24_i56++) {
    for (c24_i57 = 0; c24_i57 < 1000; c24_i57++) {
      c24_b_inData[c24_i57 + c24_i55] = (*(real_T (*)[4000])c24_inData)[c24_i57
        + c24_i55];
    }

    c24_i55 += 1000;
  }

  c24_i58 = 0;
  for (c24_i59 = 0; c24_i59 < 4; c24_i59++) {
    for (c24_i60 = 0; c24_i60 < 1000; c24_i60++) {
      c24_u[c24_i60 + c24_i58] = c24_b_inData[c24_i60 + c24_i58];
    }

    c24_i58 += 1000;
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 1000, 4),
                FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static void c24_e_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[4000])
{
  real_T c24_dv3[4000];
  int32_T c24_i61;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv3, 1, 0, 0U, 1, 0U, 2,
                1000, 4);
  for (c24_i61 = 0; c24_i61 < 4000; c24_i61++) {
    c24_y[c24_i61] = c24_dv3[c24_i61];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_Hi;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[4000];
  int32_T c24_i62;
  int32_T c24_i63;
  int32_T c24_i64;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_Hi = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_Hi), &c24_thisId, c24_y);
  sf_mex_destroy(&c24_Hi);
  c24_i62 = 0;
  for (c24_i63 = 0; c24_i63 < 4; c24_i63++) {
    for (c24_i64 = 0; c24_i64 < 1000; c24_i64++) {
      (*(real_T (*)[4000])c24_outData)[c24_i64 + c24_i62] = c24_y[c24_i64 +
        c24_i62];
    }

    c24_i62 += 1000;
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

const mxArray *sf_c24_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c24_nameCaptureInfo;
  c24_ResolvedFunctionInfo c24_info[18];
  const mxArray *c24_m0 = NULL;
  int32_T c24_i65;
  c24_ResolvedFunctionInfo *c24_r0;
  c24_nameCaptureInfo = NULL;
  c24_nameCaptureInfo = NULL;
  c24_info_helper(c24_info);
  sf_mex_assign(&c24_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18), FALSE);
  for (c24_i65 = 0; c24_i65 < 18; c24_i65++) {
    c24_r0 = &c24_info[c24_i65];
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", c24_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c24_r0->context)), "context", "nameCaptureInfo",
                    c24_i65);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", c24_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c24_r0->name)), "name", "nameCaptureInfo",
                    c24_i65);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo",
      c24_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c24_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c24_i65);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", c24_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c24_r0->resolved)), "resolved",
                    "nameCaptureInfo", c24_i65);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", &c24_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c24_i65);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo", &c24_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c24_i65);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo",
      &c24_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c24_i65);
    sf_mex_addfield(c24_m0, sf_mex_create("nameCaptureInfo",
      &c24_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c24_i65);
  }

  sf_mex_assign(&c24_nameCaptureInfo, c24_m0, FALSE);
  return c24_nameCaptureInfo;
}

static void c24_info_helper(c24_ResolvedFunctionInfo c24_info[18])
{
  c24_info[0].context = "";
  c24_info[0].name = "mtimes";
  c24_info[0].dominantType = "double";
  c24_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c24_info[0].fileTimeLo = 1289519692U;
  c24_info[0].fileTimeHi = 0U;
  c24_info[0].mFileTimeLo = 0U;
  c24_info[0].mFileTimeHi = 0U;
  c24_info[1].context = "";
  c24_info[1].name = "round";
  c24_info[1].dominantType = "double";
  c24_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c24_info[1].fileTimeLo = 1286818748U;
  c24_info[1].fileTimeHi = 0U;
  c24_info[1].mFileTimeLo = 0U;
  c24_info[1].mFileTimeHi = 0U;
  c24_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c24_info[2].name = "eml_scalar_round";
  c24_info[2].dominantType = "double";
  c24_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c24_info[2].fileTimeLo = 1289519628U;
  c24_info[2].fileTimeHi = 0U;
  c24_info[2].mFileTimeLo = 0U;
  c24_info[2].mFileTimeHi = 0U;
  c24_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c24_info[3].name = "eps";
  c24_info[3].dominantType = "char";
  c24_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c24_info[3].fileTimeLo = 1286818686U;
  c24_info[3].fileTimeHi = 0U;
  c24_info[3].mFileTimeLo = 0U;
  c24_info[3].mFileTimeHi = 0U;
  c24_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c24_info[4].name = "eml_is_float_class";
  c24_info[4].dominantType = "char";
  c24_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c24_info[4].fileTimeLo = 1286818782U;
  c24_info[4].fileTimeHi = 0U;
  c24_info[4].mFileTimeLo = 0U;
  c24_info[4].mFileTimeHi = 0U;
  c24_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c24_info[5].name = "mrdivide";
  c24_info[5].dominantType = "double";
  c24_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c24_info[5].fileTimeLo = 1310137456U;
  c24_info[5].fileTimeHi = 0U;
  c24_info[5].mFileTimeLo = 1289519692U;
  c24_info[5].mFileTimeHi = 0U;
  c24_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c24_info[6].name = "rdivide";
  c24_info[6].dominantType = "double";
  c24_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c24_info[6].fileTimeLo = 1286818844U;
  c24_info[6].fileTimeHi = 0U;
  c24_info[6].mFileTimeLo = 0U;
  c24_info[6].mFileTimeHi = 0U;
  c24_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c24_info[7].name = "eml_div";
  c24_info[7].dominantType = "double";
  c24_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c24_info[7].fileTimeLo = 1305318000U;
  c24_info[7].fileTimeHi = 0U;
  c24_info[7].mFileTimeLo = 0U;
  c24_info[7].mFileTimeHi = 0U;
  c24_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c24_info[8].name = "eml_index_class";
  c24_info[8].dominantType = "";
  c24_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c24_info[8].fileTimeLo = 1286818778U;
  c24_info[8].fileTimeHi = 0U;
  c24_info[8].mFileTimeLo = 0U;
  c24_info[8].mFileTimeHi = 0U;
  c24_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c24_info[9].name = "eml_scalar_eg";
  c24_info[9].dominantType = "double";
  c24_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c24_info[9].fileTimeLo = 1286818796U;
  c24_info[9].fileTimeHi = 0U;
  c24_info[9].mFileTimeLo = 0U;
  c24_info[9].mFileTimeHi = 0U;
  c24_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c24_info[10].name = "eml_xdotu";
  c24_info[10].dominantType = "int32";
  c24_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c24_info[10].fileTimeLo = 1299076772U;
  c24_info[10].fileTimeHi = 0U;
  c24_info[10].mFileTimeLo = 0U;
  c24_info[10].mFileTimeHi = 0U;
  c24_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c24_info[11].name = "eml_blas_inline";
  c24_info[11].dominantType = "";
  c24_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c24_info[11].fileTimeLo = 1299076768U;
  c24_info[11].fileTimeHi = 0U;
  c24_info[11].mFileTimeLo = 0U;
  c24_info[11].mFileTimeHi = 0U;
  c24_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c24_info[12].name = "eml_xdot";
  c24_info[12].dominantType = "int32";
  c24_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c24_info[12].fileTimeLo = 1299076772U;
  c24_info[12].fileTimeHi = 0U;
  c24_info[12].mFileTimeLo = 0U;
  c24_info[12].mFileTimeHi = 0U;
  c24_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c24_info[13].name = "eml_refblas_xdot";
  c24_info[13].dominantType = "int32";
  c24_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c24_info[13].fileTimeLo = 1299076772U;
  c24_info[13].fileTimeHi = 0U;
  c24_info[13].mFileTimeLo = 0U;
  c24_info[13].mFileTimeHi = 0U;
  c24_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c24_info[14].name = "eml_refblas_xdotx";
  c24_info[14].dominantType = "int32";
  c24_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c24_info[14].fileTimeLo = 1299076774U;
  c24_info[14].fileTimeHi = 0U;
  c24_info[14].mFileTimeLo = 0U;
  c24_info[14].mFileTimeHi = 0U;
  c24_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c24_info[15].name = "eml_index_minus";
  c24_info[15].dominantType = "int32";
  c24_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c24_info[15].fileTimeLo = 1286818778U;
  c24_info[15].fileTimeHi = 0U;
  c24_info[15].mFileTimeLo = 0U;
  c24_info[15].mFileTimeHi = 0U;
  c24_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c24_info[16].name = "eml_index_times";
  c24_info[16].dominantType = "int32";
  c24_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c24_info[16].fileTimeLo = 1286818780U;
  c24_info[16].fileTimeHi = 0U;
  c24_info[16].mFileTimeLo = 0U;
  c24_info[16].mFileTimeHi = 0U;
  c24_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c24_info[17].name = "eml_index_plus";
  c24_info[17].dominantType = "int32";
  c24_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c24_info[17].fileTimeLo = 1286818778U;
  c24_info[17].fileTimeHi = 0U;
  c24_info[17].mFileTimeLo = 0U;
  c24_info[17].mFileTimeHi = 0U;
}

static void c24_round(SFc24_controller_templateInstanceStruct *chartInstance,
                      real_T c24_x[4], real_T c24_b_x[4])
{
  int32_T c24_i66;
  for (c24_i66 = 0; c24_i66 < 4; c24_i66++) {
    c24_b_x[c24_i66] = c24_x[c24_i66];
  }

  c24_b_round(chartInstance, c24_b_x);
}

static void c24_mrdivide(SFc24_controller_templateInstanceStruct *chartInstance,
  real_T c24_A[4], real_T c24_B, real_T c24_y[4])
{
  real_T c24_b_y;
  real_T c24_c_y;
  int32_T c24_i67;
  c24_b_y = c24_B;
  c24_c_y = c24_b_y;
  for (c24_i67 = 0; c24_i67 < 4; c24_i67++) {
    c24_y[c24_i67] = c24_A[c24_i67] / c24_c_y;
  }
}

static void c24_eml_scalar_eg(SFc24_controller_templateInstanceStruct
  *chartInstance)
{
}

static const mxArray *c24_j_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(int32_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static int32_T c24_f_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  int32_T c24_y;
  int32_T c24_i68;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_i68, 1, 6, 0U, 0, 0U, 0);
  c24_y = c24_i68;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_sfEvent;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  int32_T c24_y;
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)chartInstanceVoid;
  c24_sfEvent = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_sfEvent),
    &c24_thisId);
  sf_mex_destroy(&c24_sfEvent);
  *(int32_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static uint8_T c24_g_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_is_active_c24_controller_template, const
  char_T *c24_identifier)
{
  uint8_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c24_is_active_c24_controller_template), &c24_thisId);
  sf_mex_destroy(&c24_is_active_c24_controller_template);
  return c24_y;
}

static uint8_T c24_h_emlrt_marshallIn(SFc24_controller_templateInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  uint8_T c24_y;
  uint8_T c24_u0;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_u0, 1, 3, 0U, 0, 0U, 0);
  c24_y = c24_u0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_b_round(SFc24_controller_templateInstanceStruct *chartInstance,
  real_T c24_x[4])
{
  int32_T c24_k;
  real_T c24_b_k;
  real_T c24_b_x;
  real_T c24_c_x;
  real_T c24_d_x;
  for (c24_k = 0; c24_k < 4; c24_k++) {
    c24_b_k = 1.0 + (real_T)c24_k;
    c24_b_x = c24_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c24_b_k), 1, 4, 1, 0) - 1];
    c24_c_x = c24_b_x;
    c24_d_x = c24_c_x;
    if (muDoubleScalarAbs(c24_d_x) > 4.503599627370496E+15) {
    } else if (c24_d_x >= 0.5) {
      c24_c_x = muDoubleScalarFloor(c24_d_x + 0.5);
    } else if (c24_d_x > -0.5) {
      c24_c_x = c24_d_x * 0.0;
    } else {
      c24_c_x = muDoubleScalarCeil(c24_d_x - 0.5);
    }

    c24_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c24_b_k), 1, 4, 1, 0) - 1] = c24_c_x;
  }
}

static void init_dsm_address_info(SFc24_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c24_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3748228976U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(849742829U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2832221233U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2029047614U);
}

mxArray *sf_c24_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("rajXO26HuymXe7HHy23FZB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      pr[0] = (double)(1116);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1116);
      pr[1] = (double)(1);
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
      pr[0] = (double)(134);
      pr[1] = (double)(4);
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
      pr[0] = (double)(134);
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
      pr[0] = (double)(134);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c24_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"U\",},{M[1],M[16],T\"flag_oob\",},{M[8],M[0],T\"is_active_c24_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c24_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc24_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc24_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           24,
           1,
           1,
           8,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"X");
          _SFD_SET_DATA_PROPS(1,2,0,1,"U");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Hn");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Kn");
          _SFD_SET_DATA_PROPS(4,1,1,0,"Fi");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Gi");
          _SFD_SET_DATA_PROPS(6,1,1,0,"Nc");
          _SFD_SET_DATA_PROPS(7,2,0,1,"flag_oob");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,5,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1186);
        _SFD_CV_INIT_EML_IF(0,1,0,780,811,-1,896);
        _SFD_CV_INIT_EML_IF(0,1,1,914,938,-1,998);
        _SFD_CV_INIT_EML_IF(0,1,2,1039,1057,-1,-2);
        _SFD_CV_INIT_EML_FOR(0,1,0,263,279,1105);
        _SFD_CV_INIT_EML_FOR(0,1,1,386,405,488);
        _SFD_CV_INIT_EML_FOR(0,1,2,413,425,480);
        _SFD_CV_INIT_EML_FOR(0,1,3,556,575,622);
        _SFD_CV_INIT_EML_FOR(0,1,4,733,747,904);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)c24_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1116;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 1116;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 134;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 134;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 134;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)c24_sf_marshallIn);

        {
          real_T *c24_U;
          real_T *c24_flag_oob;
          real_T (*c24_X)[4];
          real_T (*c24_Hn)[4464];
          real_T (*c24_Kn)[1116];
          real_T (*c24_Fi)[536];
          real_T (*c24_Gi)[134];
          real_T (*c24_Nc)[134];
          c24_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c24_Nc = (real_T (*)[134])ssGetInputPortSignal(chartInstance->S, 5);
          c24_Gi = (real_T (*)[134])ssGetInputPortSignal(chartInstance->S, 4);
          c24_Fi = (real_T (*)[536])ssGetInputPortSignal(chartInstance->S, 3);
          c24_Kn = (real_T (*)[1116])ssGetInputPortSignal(chartInstance->S, 2);
          c24_Hn = (real_T (*)[4464])ssGetInputPortSignal(chartInstance->S, 1);
          c24_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c24_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c24_X);
          _SFD_SET_DATA_VALUE_PTR(1U, c24_U);
          _SFD_SET_DATA_VALUE_PTR(2U, *c24_Hn);
          _SFD_SET_DATA_VALUE_PTR(3U, *c24_Kn);
          _SFD_SET_DATA_VALUE_PTR(4U, *c24_Fi);
          _SFD_SET_DATA_VALUE_PTR(5U, *c24_Gi);
          _SFD_SET_DATA_VALUE_PTR(6U, *c24_Nc);
          _SFD_SET_DATA_VALUE_PTR(7U, c24_flag_oob);
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
      24, "dworkChecksum");
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

static void sf_opaque_initialize_c24_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc24_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc24_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c24_controller_template
    ((SFc24_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c24_controller_template((SFc24_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c24_controller_template(void *chartInstanceVar)
{
  enable_c24_controller_template((SFc24_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c24_controller_template(void *chartInstanceVar)
{
  disable_c24_controller_template((SFc24_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c24_controller_template(void *chartInstanceVar)
{
  sf_c24_controller_template((SFc24_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c24_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c24_controller_template((SFc24_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c24_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c24_controller_template
    ((SFc24_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c24_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c24_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c24_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c24_controller_template((SFc24_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c24_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c24_controller_template(S);
}

static void sf_opaque_set_sim_state_c24_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c24_controller_template(S, st);
}

static void sf_opaque_terminate_c24_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc24_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c24_controller_template((SFc24_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc24_controller_template((SFc24_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c24_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c24_controller_template
      ((SFc24_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c24_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c24_controller_template\",T\"is_active_c24_controller_template\"}}"
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

static void mdlSetWorkWidths_c24_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,24);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,24,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,24,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,24,6);
      sf_mark_chart_reusable_outputs(S,infoStruct,24,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,24);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2328200518U));
  ssSetChecksum1(S,(3342545676U));
  ssSetChecksum2(S,(1321175557U));
  ssSetChecksum3(S,(204766141U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c24_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c24_controller_template(SimStruct *S)
{
  SFc24_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc24_controller_templateInstanceStruct *)malloc(sizeof
    (SFc24_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc24_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c24_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c24_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c24_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c24_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c24_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c24_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c24_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c24_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c24_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c24_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c24_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c24_controller_template;
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

void c24_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c24_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c24_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c24_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c24_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
