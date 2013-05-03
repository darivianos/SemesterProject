/* Include files */

#include <stddef.h>
#include "blas.h"
#include "controller_template_sfun.h"
#include "c3_controller_template.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[27] = { "tolerance", "nr",
  "MPT_ABSTOL", "minreg", "Hi", "Ki", "abspos", "ireg", "sumViol", "isinside",
  "i", "j", "F", "G", "nc", "ic", "hx", "nargin", "nargout", "X", "Hn", "Kn",
  "Fi", "Gi", "Nc", "U", "flag_oob" };

/* Function Declarations */
static void initialize_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance);
static void enable_c3_controller_template(SFc3_controller_templateInstanceStruct
  *chartInstance);
static void disable_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance, const mxArray *c3_st);
static void finalize_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance);
static void sf_c3_controller_template(SFc3_controller_templateInstanceStruct
  *chartInstance);
static void c3_chartstep_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance);
static void initSimStructsc3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance);
static void registerMessagesc3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_flag_oob, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_d_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[100]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_e_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[200]);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[26]);
static void c3_round(SFc3_controller_templateInstanceStruct *chartInstance,
                     real_T c3_x[2], real_T c3_b_x[2]);
static void c3_eml_scalar_eg(SFc3_controller_templateInstanceStruct
  *chartInstance);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_f_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_controller_template, const
  char_T *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_round(SFc3_controller_templateInstanceStruct *chartInstance,
  real_T c3_x[2]);
static void init_dsm_address_info(SFc3_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_controller_template = 0U;
}

static void initialize_params_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c3_controller_template(SFc3_controller_templateInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  uint8_T c3_c_hoistedGlobal;
  uint8_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  real_T *c3_U;
  real_T *c3_flag_oob;
  c3_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(3), FALSE);
  c3_hoistedGlobal = *c3_U;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *c3_flag_oob;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_is_active_c3_controller_template;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_U;
  real_T *c3_flag_oob;
  c3_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_U = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
    "U");
  *c3_flag_oob = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c3_u, 1)), "flag_oob");
  chartInstance->c3_is_active_c3_controller_template = c3_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
     "is_active_c3_controller_template");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_controller_template(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c3_controller_template(SFc3_controller_templateInstanceStruct
  *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
  int32_T c3_i2;
  int32_T c3_i3;
  int32_T c3_i4;
  int32_T c3_i5;
  real_T *c3_U;
  real_T *c3_flag_oob;
  real_T (*c3_Nc)[21];
  real_T (*c3_Gi)[21];
  real_T (*c3_Fi)[42];
  real_T (*c3_Kn)[88];
  real_T (*c3_Hn)[176];
  real_T (*c3_X)[2];
  c3_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_Nc = (real_T (*)[21])ssGetInputPortSignal(chartInstance->S, 5);
  c3_Gi = (real_T (*)[21])ssGetInputPortSignal(chartInstance->S, 4);
  c3_Fi = (real_T (*)[42])ssGetInputPortSignal(chartInstance->S, 3);
  c3_Kn = (real_T (*)[88])ssGetInputPortSignal(chartInstance->S, 2);
  c3_Hn = (real_T (*)[176])ssGetInputPortSignal(chartInstance->S, 1);
  c3_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_X = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i0 = 0; c3_i0 < 2; c3_i0++) {
    _SFD_DATA_RANGE_CHECK((*c3_X)[c3_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_U, 1U);
  for (c3_i1 = 0; c3_i1 < 176; c3_i1++) {
    _SFD_DATA_RANGE_CHECK((*c3_Hn)[c3_i1], 2U);
  }

  for (c3_i2 = 0; c3_i2 < 88; c3_i2++) {
    _SFD_DATA_RANGE_CHECK((*c3_Kn)[c3_i2], 3U);
  }

  for (c3_i3 = 0; c3_i3 < 42; c3_i3++) {
    _SFD_DATA_RANGE_CHECK((*c3_Fi)[c3_i3], 4U);
  }

  for (c3_i4 = 0; c3_i4 < 21; c3_i4++) {
    _SFD_DATA_RANGE_CHECK((*c3_Gi)[c3_i4], 5U);
  }

  for (c3_i5 = 0; c3_i5 < 21; c3_i5++) {
    _SFD_DATA_RANGE_CHECK((*c3_Nc)[c3_i5], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c3_flag_oob, 7U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_controller_template(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c3_chartstep_c3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance)
{
  int32_T c3_i6;
  real_T c3_X[2];
  int32_T c3_i7;
  real_T c3_Hn[176];
  int32_T c3_i8;
  real_T c3_Kn[88];
  int32_T c3_i9;
  real_T c3_Fi[42];
  int32_T c3_i10;
  real_T c3_Gi[21];
  int32_T c3_i11;
  real_T c3_Nc[21];
  uint32_T c3_debug_family_var_map[27];
  real_T c3_tolerance;
  real_T c3_nr;
  real_T c3_MPT_ABSTOL;
  real_T c3_minreg;
  real_T c3_Hi[200];
  real_T c3_Ki[100];
  real_T c3_abspos;
  real_T c3_ireg;
  real_T c3_sumViol;
  real_T c3_isinside;
  real_T c3_i;
  real_T c3_j;
  real_T c3_F[2];
  real_T c3_G;
  real_T c3_nc;
  real_T c3_ic;
  real_T c3_hx;
  real_T c3_nargin = 6.0;
  real_T c3_nargout = 2.0;
  real_T c3_U;
  real_T c3_flag_oob;
  int32_T c3_i12;
  real_T c3_b[2];
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_b_ireg;
  real_T c3_d0;
  int32_T c3_i17;
  int32_T c3_b_i;
  int32_T c3_b_j;
  real_T c3_d1;
  int32_T c3_i18;
  int32_T c3_c_i;
  int32_T c3_c_ireg;
  int32_T c3_i19;
  real_T c3_b_nc;
  int32_T c3_i20;
  int32_T c3_b_ic;
  int32_T c3_c_ic;
  int32_T c3_i21;
  real_T c3_a[2];
  int32_T c3_i22;
  int32_T c3_k;
  int32_T c3_b_k;
  int32_T c3_i23;
  int32_T c3_i24;
  real_T c3_y;
  int32_T c3_c_k;
  int32_T c3_d_k;
  int32_T c3_b_minreg;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  real_T c3_b_y;
  int32_T c3_e_k;
  int32_T c3_f_k;
  real_T *c3_b_U;
  real_T *c3_b_flag_oob;
  real_T (*c3_b_Nc)[21];
  real_T (*c3_b_Gi)[21];
  real_T (*c3_b_Fi)[42];
  real_T (*c3_b_Kn)[88];
  real_T (*c3_b_Hn)[176];
  real_T (*c3_b_X)[2];
  int32_T exitg1;
  c3_b_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c3_b_Nc = (real_T (*)[21])ssGetInputPortSignal(chartInstance->S, 5);
  c3_b_Gi = (real_T (*)[21])ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_Fi = (real_T (*)[42])ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_Kn = (real_T (*)[88])ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_Hn = (real_T (*)[176])ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_X = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  for (c3_i6 = 0; c3_i6 < 2; c3_i6++) {
    c3_X[c3_i6] = (*c3_b_X)[c3_i6];
  }

  for (c3_i7 = 0; c3_i7 < 176; c3_i7++) {
    c3_Hn[c3_i7] = (*c3_b_Hn)[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 88; c3_i8++) {
    c3_Kn[c3_i8] = (*c3_b_Kn)[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 42; c3_i9++) {
    c3_Fi[c3_i9] = (*c3_b_Fi)[c3_i9];
  }

  for (c3_i10 = 0; c3_i10 < 21; c3_i10++) {
    c3_Gi[c3_i10] = (*c3_b_Gi)[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 21; c3_i11++) {
    c3_Nc[c3_i11] = (*c3_b_Nc)[c3_i11];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 27U, 27U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_tolerance, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_nr, 1U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_MPT_ABSTOL, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_minreg, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_Hi, 4U, c3_i_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_Ki, 5U, c3_h_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_abspos, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ireg, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_sumViol, 8U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_isinside, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_i, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_j, 11U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_F, 12U, c3_g_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_G, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nc, 14U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_ic, 15U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_hx, 16U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 17U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 18U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_X, 19U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_Hn, 20U, c3_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_Kn, 21U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_Fi, 22U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_Gi, 23U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_Nc, 24U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_U, 25U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_flag_oob, 26U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_tolerance = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_nr = 21.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_MPT_ABSTOL = 1.0E-8;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_minreg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  for (c3_i12 = 0; c3_i12 < 2; c3_i12++) {
    c3_b[c3_i12] = c3_X[c3_i12];
  }

  for (c3_i13 = 0; c3_i13 < 2; c3_i13++) {
    c3_b[c3_i13] *= 10000.0;
  }

  c3_b_round(chartInstance, c3_b);
  for (c3_i14 = 0; c3_i14 < 2; c3_i14++) {
    c3_X[c3_i14] = c3_b[c3_i14] / 10000.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_flag_oob = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
  for (c3_i15 = 0; c3_i15 < 200; c3_i15++) {
    c3_Hi[c3_i15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  for (c3_i16 = 0; c3_i16 < 100; c3_i16++) {
    c3_Ki[c3_i16] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  c3_abspos = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  c3_ireg = 1.0;
  c3_b_ireg = 0;
  do {
    exitg1 = 0;
    if (c3_b_ireg < 21) {
      c3_ireg = 1.0 + (real_T)c3_b_ireg;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
      c3_sumViol = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
      c3_isinside = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
      c3_d0 = c3_Nc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c3_ireg), 1, 21, 1, 0) - 1];
      c3_i17 = (int32_T)c3_d0;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c3_d0, mxDOUBLE_CLASS, c3_i17);
      c3_i = 1.0;
      c3_b_i = 0;
      while (c3_b_i <= c3_i17 - 1) {
        c3_i = 1.0 + (real_T)c3_b_i;
        CV_EML_FOR(0, 1, 1, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
        c3_j = 1.0;
        c3_b_j = 0;
        while (c3_b_j < 2) {
          c3_j = 1.0 + (real_T)c3_b_j;
          CV_EML_FOR(0, 1, 2, 1);
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
          c3_Hi[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)
                  _SFD_INTEGER_CHECK("i", c3_i), 1, 100, 1, 0) + 100 * ((int32_T)
                  (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)
                   _SFD_INTEGER_CHECK("j", c3_j), 1, 2, 2, 0) - 1)) - 1] =
            c3_Hn[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)
                    _SFD_INTEGER_CHECK("abspos + i - 1", (c3_abspos + c3_i) -
                     1.0), 1, 88, 1, 0) + 88 * ((int32_T)(real_T)
                    _SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)
                     _SFD_INTEGER_CHECK("j", c3_j), 1, 2, 2, 0) - 1)) - 1];
          c3_b_j++;
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        CV_EML_FOR(0, 1, 2, 0);
        c3_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 1, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
      c3_d1 = c3_Nc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c3_ireg), 1, 21, 1, 0) - 1];
      c3_i18 = (int32_T)c3_d1;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c3_d1, mxDOUBLE_CLASS, c3_i18);
      c3_i = 1.0;
      c3_c_i = 0;
      while (c3_c_i <= c3_i18 - 1) {
        c3_i = 1.0 + (real_T)c3_c_i;
        CV_EML_FOR(0, 1, 3, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
        c3_Ki[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)
          _SFD_INTEGER_CHECK("i", c3_i), 1, 100, 1, 0) - 1] = c3_Kn[(int32_T)
          (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Kn", (int32_T)_SFD_INTEGER_CHECK(
          "abspos + i - 1", (c3_abspos + c3_i) - 1.0), 1, 88, 1, 0) - 1];
        c3_c_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 3, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 33);
      c3_abspos += c3_Nc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Nc",
        (int32_T)_SFD_INTEGER_CHECK("ireg", c3_ireg), 1, 21, 1, 0) - 1];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 35);
      c3_c_ireg = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c3_ireg), 1, 21, 1, 0) - 1;
      for (c3_i19 = 0; c3_i19 < 2; c3_i19++) {
        c3_F[c3_i19] = c3_Fi[c3_c_ireg + 21 * c3_i19];
      }

      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
      c3_G = c3_Gi[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Gi", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c3_ireg), 1, 21, 1, 0) - 1];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 38);
      c3_nc = c3_Nc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c3_ireg), 1, 21, 1, 0) - 1];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
      c3_b_nc = c3_nc;
      c3_i20 = (int32_T)c3_b_nc;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c3_b_nc, mxDOUBLE_CLASS, c3_i20);
      c3_ic = 1.0;
      c3_b_ic = 0;
      while (c3_b_ic <= c3_i20 - 1) {
        c3_ic = 1.0 + (real_T)c3_b_ic;
        CV_EML_FOR(0, 1, 4, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
        c3_c_ic = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)
          _SFD_INTEGER_CHECK("ic", c3_ic), 1, 100, 1, 0) - 1;
        for (c3_i21 = 0; c3_i21 < 2; c3_i21++) {
          c3_a[c3_i21] = c3_Hi[c3_c_ic + 100 * c3_i21];
        }

        for (c3_i22 = 0; c3_i22 < 2; c3_i22++) {
          c3_b[c3_i22] = c3_X[c3_i22];
        }

        c3_eml_scalar_eg(chartInstance);
        c3_eml_scalar_eg(chartInstance);
        c3_hx = 0.0;
        for (c3_k = 1; c3_k < 3; c3_k++) {
          c3_b_k = c3_k;
          c3_hx += c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c3_b_k), 1, 2, 1, 0) - 1] *
            c3_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c3_b_k), 1, 2, 1, 0) - 1];
        }

        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
        if (CV_EML_IF(0, 1, 0, c3_hx - c3_Ki[(int32_T)(real_T)
                      _SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)
              _SFD_INTEGER_CHECK("ic", c3_ic), 1, 100, 1, 0) - 1] >
                      c3_MPT_ABSTOL)) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 43);
          c3_isinside = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
          c3_sumViol += c3_hx - c3_Ki[(int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)_SFD_INTEGER_CHECK("ic",
            c3_ic), 1, 100, 1, 0) - 1];
        }

        c3_b_ic++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 4, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 48);
      if (CV_EML_IF(0, 1, 1, c3_sumViol < c3_tolerance)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 49);
        c3_tolerance = c3_sumViol;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
        c3_minreg = c3_ireg;
      }

      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 53);
      if (CV_EML_IF(0, 1, 2, c3_isinside == 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 54);
        for (c3_i23 = 0; c3_i23 < 2; c3_i23++) {
          c3_a[c3_i23] = c3_F[c3_i23];
        }

        for (c3_i24 = 0; c3_i24 < 2; c3_i24++) {
          c3_b[c3_i24] = c3_X[c3_i24];
        }

        c3_eml_scalar_eg(chartInstance);
        c3_eml_scalar_eg(chartInstance);
        c3_y = 0.0;
        for (c3_c_k = 1; c3_c_k < 3; c3_c_k++) {
          c3_d_k = c3_c_k;
          c3_y += c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c3_d_k), 1, 2, 1, 0) - 1] *
            c3_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c3_d_k), 1, 2, 1, 0) - 1];
        }

        c3_U = c3_y + c3_G;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 55);
        exitg1 = 1;
      } else {
        c3_b_ireg++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(0, 1, 0, 0);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 58);
      c3_b_minreg = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)
        _SFD_INTEGER_CHECK("minreg", c3_minreg), 1, 21, 1, 0) - 1;
      for (c3_i25 = 0; c3_i25 < 2; c3_i25++) {
        c3_F[c3_i25] = c3_Fi[c3_b_minreg + 21 * c3_i25];
      }

      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 59);
      c3_G = c3_Gi[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Gi", (int32_T)
        _SFD_INTEGER_CHECK("minreg", c3_minreg), 1, 21, 1, 0) - 1];
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 60);
      for (c3_i26 = 0; c3_i26 < 2; c3_i26++) {
        c3_a[c3_i26] = c3_F[c3_i26];
      }

      for (c3_i27 = 0; c3_i27 < 2; c3_i27++) {
        c3_b[c3_i27] = c3_X[c3_i27];
      }

      c3_eml_scalar_eg(chartInstance);
      c3_eml_scalar_eg(chartInstance);
      c3_b_y = 0.0;
      for (c3_e_k = 1; c3_e_k < 3; c3_e_k++) {
        c3_f_k = c3_e_k;
        c3_b_y += c3_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c3_f_k), 1, 2, 1, 0) - 1] *
          c3_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c3_f_k), 1, 2, 1, 0) - 1];
      }

      c3_U = c3_b_y + c3_G;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 61);
      c3_flag_oob = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 63);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -63);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_b_U = c3_U;
  *c3_b_flag_oob = c3_flag_oob;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance)
{
}

static void registerMessagesc3_controller_template
  (SFc3_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_flag_oob, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_flag_oob),
    &c3_thisId);
  sf_mex_destroy(&c3_flag_oob);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d2;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d2, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d2;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_flag_oob;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_flag_oob = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_flag_oob),
    &c3_thisId);
  sf_mex_destroy(&c3_flag_oob);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i28;
  real_T c3_b_inData[21];
  int32_T c3_i29;
  real_T c3_u[21];
  const mxArray *c3_y = NULL;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i28 = 0; c3_i28 < 21; c3_i28++) {
    c3_b_inData[c3_i28] = (*(real_T (*)[21])c3_inData)[c3_i28];
  }

  for (c3_i29 = 0; c3_i29 < 21; c3_i29++) {
    c3_u[c3_i29] = c3_b_inData[c3_i29];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 21), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  real_T c3_b_inData[42];
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  real_T c3_u[42];
  const mxArray *c3_y = NULL;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i30 = 0;
  for (c3_i31 = 0; c3_i31 < 2; c3_i31++) {
    for (c3_i32 = 0; c3_i32 < 21; c3_i32++) {
      c3_b_inData[c3_i32 + c3_i30] = (*(real_T (*)[42])c3_inData)[c3_i32 +
        c3_i30];
    }

    c3_i30 += 21;
  }

  c3_i33 = 0;
  for (c3_i34 = 0; c3_i34 < 2; c3_i34++) {
    for (c3_i35 = 0; c3_i35 < 21; c3_i35++) {
      c3_u[c3_i35 + c3_i33] = c3_b_inData[c3_i35 + c3_i33];
    }

    c3_i33 += 21;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 21, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i36;
  real_T c3_b_inData[88];
  int32_T c3_i37;
  real_T c3_u[88];
  const mxArray *c3_y = NULL;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i36 = 0; c3_i36 < 88; c3_i36++) {
    c3_b_inData[c3_i36] = (*(real_T (*)[88])c3_inData)[c3_i36];
  }

  for (c3_i37 = 0; c3_i37 < 88; c3_i37++) {
    c3_u[c3_i37] = c3_b_inData[c3_i37];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 88), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i40;
  real_T c3_b_inData[176];
  int32_T c3_i41;
  int32_T c3_i42;
  int32_T c3_i43;
  real_T c3_u[176];
  const mxArray *c3_y = NULL;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i38 = 0;
  for (c3_i39 = 0; c3_i39 < 2; c3_i39++) {
    for (c3_i40 = 0; c3_i40 < 88; c3_i40++) {
      c3_b_inData[c3_i40 + c3_i38] = (*(real_T (*)[176])c3_inData)[c3_i40 +
        c3_i38];
    }

    c3_i38 += 88;
  }

  c3_i41 = 0;
  for (c3_i42 = 0; c3_i42 < 2; c3_i42++) {
    for (c3_i43 = 0; c3_i43 < 88; c3_i43++) {
      c3_u[c3_i43 + c3_i41] = c3_b_inData[c3_i43 + c3_i41];
    }

    c3_i41 += 88;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 88, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i44;
  real_T c3_b_inData[2];
  int32_T c3_i45;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i44 = 0; c3_i44 < 2; c3_i44++) {
    c3_b_inData[c3_i44] = (*(real_T (*)[2])c3_inData)[c3_i44];
  }

  for (c3_i45 = 0; c3_i45 < 2; c3_i45++) {
    c3_u[c3_i45] = c3_b_inData[c3_i45];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i46;
  real_T c3_b_inData[2];
  int32_T c3_i47;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i46 = 0; c3_i46 < 2; c3_i46++) {
    c3_b_inData[c3_i46] = (*(real_T (*)[2])c3_inData)[c3_i46];
  }

  for (c3_i47 = 0; c3_i47 < 2; c3_i47++) {
    c3_u[c3_i47] = c3_b_inData[c3_i47];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 1, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2])
{
  real_T c3_dv0[2];
  int32_T c3_i48;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv0, 1, 0, 0U, 1, 0U, 2, 1, 2);
  for (c3_i48 = 0; c3_i48 < 2; c3_i48++) {
    c3_y[c3_i48] = c3_dv0[c3_i48];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_F;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i49;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_F = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_F), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_F);
  for (c3_i49 = 0; c3_i49 < 2; c3_i49++) {
    (*(real_T (*)[2])c3_outData)[c3_i49] = c3_y[c3_i49];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i50;
  real_T c3_b_inData[100];
  int32_T c3_i51;
  real_T c3_u[100];
  const mxArray *c3_y = NULL;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i50 = 0; c3_i50 < 100; c3_i50++) {
    c3_b_inData[c3_i50] = (*(real_T (*)[100])c3_inData)[c3_i50];
  }

  for (c3_i51 = 0; c3_i51 < 100; c3_i51++) {
    c3_u[c3_i51] = c3_b_inData[c3_i51];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 100), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_d_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[100])
{
  real_T c3_dv1[100];
  int32_T c3_i52;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv1, 1, 0, 0U, 1, 0U, 1, 100);
  for (c3_i52 = 0; c3_i52 < 100; c3_i52++) {
    c3_y[c3_i52] = c3_dv1[c3_i52];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_Ki;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[100];
  int32_T c3_i53;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_Ki = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Ki), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_Ki);
  for (c3_i53 = 0; c3_i53 < 100; c3_i53++) {
    (*(real_T (*)[100])c3_outData)[c3_i53] = c3_y[c3_i53];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i54;
  int32_T c3_i55;
  int32_T c3_i56;
  real_T c3_b_inData[200];
  int32_T c3_i57;
  int32_T c3_i58;
  int32_T c3_i59;
  real_T c3_u[200];
  const mxArray *c3_y = NULL;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i54 = 0;
  for (c3_i55 = 0; c3_i55 < 2; c3_i55++) {
    for (c3_i56 = 0; c3_i56 < 100; c3_i56++) {
      c3_b_inData[c3_i56 + c3_i54] = (*(real_T (*)[200])c3_inData)[c3_i56 +
        c3_i54];
    }

    c3_i54 += 100;
  }

  c3_i57 = 0;
  for (c3_i58 = 0; c3_i58 < 2; c3_i58++) {
    for (c3_i59 = 0; c3_i59 < 100; c3_i59++) {
      c3_u[c3_i59 + c3_i57] = c3_b_inData[c3_i59 + c3_i57];
    }

    c3_i57 += 100;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 100, 2), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static void c3_e_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[200])
{
  real_T c3_dv2[200];
  int32_T c3_i60;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv2, 1, 0, 0U, 1, 0U, 2, 100,
                2);
  for (c3_i60 = 0; c3_i60 < 200; c3_i60++) {
    c3_y[c3_i60] = c3_dv2[c3_i60];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_Hi;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[200];
  int32_T c3_i61;
  int32_T c3_i62;
  int32_T c3_i63;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_Hi = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_Hi), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_Hi);
  c3_i61 = 0;
  for (c3_i62 = 0; c3_i62 < 2; c3_i62++) {
    for (c3_i63 = 0; c3_i63 < 100; c3_i63++) {
      (*(real_T (*)[200])c3_outData)[c3_i63 + c3_i61] = c3_y[c3_i63 + c3_i61];
    }

    c3_i61 += 100;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[26];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i64;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_info_helper(c3_info);
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 26), FALSE);
  for (c3_i64 = 0; c3_i64 < 26; c3_i64++) {
    c3_r0 = &c3_info[c3_i64];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i64);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i64);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i64);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i64);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i64);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i64);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i64);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i64);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(c3_ResolvedFunctionInfo c3_info[26])
{
  c3_info[0].context = "";
  c3_info[0].name = "mtimes";
  c3_info[0].dominantType = "double";
  c3_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[0].fileTimeLo = 1289519692U;
  c3_info[0].fileTimeHi = 0U;
  c3_info[0].mFileTimeLo = 0U;
  c3_info[0].mFileTimeHi = 0U;
  c3_info[1].context = "";
  c3_info[1].name = "round";
  c3_info[1].dominantType = "double";
  c3_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c3_info[1].fileTimeLo = 1343830384U;
  c3_info[1].fileTimeHi = 0U;
  c3_info[1].mFileTimeLo = 0U;
  c3_info[1].mFileTimeHi = 0U;
  c3_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c3_info[2].name = "eml_scalar_round";
  c3_info[2].dominantType = "double";
  c3_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c3_info[2].fileTimeLo = 1307651238U;
  c3_info[2].fileTimeHi = 0U;
  c3_info[2].mFileTimeLo = 0U;
  c3_info[2].mFileTimeHi = 0U;
  c3_info[3].context = "";
  c3_info[3].name = "mrdivide";
  c3_info[3].dominantType = "double";
  c3_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[3].fileTimeLo = 1357951548U;
  c3_info[3].fileTimeHi = 0U;
  c3_info[3].mFileTimeLo = 1319729966U;
  c3_info[3].mFileTimeHi = 0U;
  c3_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c3_info[4].name = "rdivide";
  c3_info[4].dominantType = "double";
  c3_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[4].fileTimeLo = 1346510388U;
  c3_info[4].fileTimeHi = 0U;
  c3_info[4].mFileTimeLo = 0U;
  c3_info[4].mFileTimeHi = 0U;
  c3_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[5].name = "eml_scalexp_compatible";
  c3_info[5].dominantType = "double";
  c3_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c3_info[5].fileTimeLo = 1286818796U;
  c3_info[5].fileTimeHi = 0U;
  c3_info[5].mFileTimeLo = 0U;
  c3_info[5].mFileTimeHi = 0U;
  c3_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c3_info[6].name = "eml_div";
  c3_info[6].dominantType = "double";
  c3_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c3_info[6].fileTimeLo = 1313347810U;
  c3_info[6].fileTimeHi = 0U;
  c3_info[6].mFileTimeLo = 0U;
  c3_info[6].mFileTimeHi = 0U;
  c3_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[7].name = "eml_index_class";
  c3_info[7].dominantType = "";
  c3_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[7].fileTimeLo = 1323170578U;
  c3_info[7].fileTimeHi = 0U;
  c3_info[7].mFileTimeLo = 0U;
  c3_info[7].mFileTimeHi = 0U;
  c3_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[8].name = "eml_scalar_eg";
  c3_info[8].dominantType = "double";
  c3_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[8].fileTimeLo = 1286818796U;
  c3_info[8].fileTimeHi = 0U;
  c3_info[8].mFileTimeLo = 0U;
  c3_info[8].mFileTimeHi = 0U;
  c3_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c3_info[9].name = "eml_xdotu";
  c3_info[9].dominantType = "double";
  c3_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[9].fileTimeLo = 1299076772U;
  c3_info[9].fileTimeHi = 0U;
  c3_info[9].mFileTimeLo = 0U;
  c3_info[9].mFileTimeHi = 0U;
  c3_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[10].name = "eml_blas_inline";
  c3_info[10].dominantType = "";
  c3_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[10].fileTimeLo = 1299076768U;
  c3_info[10].fileTimeHi = 0U;
  c3_info[10].mFileTimeLo = 0U;
  c3_info[10].mFileTimeHi = 0U;
  c3_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c3_info[11].name = "eml_xdot";
  c3_info[11].dominantType = "double";
  c3_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[11].fileTimeLo = 1299076772U;
  c3_info[11].fileTimeHi = 0U;
  c3_info[11].mFileTimeLo = 0U;
  c3_info[11].mFileTimeHi = 0U;
  c3_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c3_info[12].name = "eml_blas_inline";
  c3_info[12].dominantType = "";
  c3_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c3_info[12].fileTimeLo = 1299076768U;
  c3_info[12].fileTimeHi = 0U;
  c3_info[12].mFileTimeLo = 0U;
  c3_info[12].mFileTimeHi = 0U;
  c3_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c3_info[13].name = "eml_index_class";
  c3_info[13].dominantType = "";
  c3_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[13].fileTimeLo = 1323170578U;
  c3_info[13].fileTimeHi = 0U;
  c3_info[13].mFileTimeLo = 0U;
  c3_info[13].mFileTimeHi = 0U;
  c3_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c3_info[14].name = "eml_refblas_xdot";
  c3_info[14].dominantType = "double";
  c3_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[14].fileTimeLo = 1299076772U;
  c3_info[14].fileTimeHi = 0U;
  c3_info[14].mFileTimeLo = 0U;
  c3_info[14].mFileTimeHi = 0U;
  c3_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c3_info[15].name = "eml_refblas_xdotx";
  c3_info[15].dominantType = "char";
  c3_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[15].fileTimeLo = 1299076774U;
  c3_info[15].fileTimeHi = 0U;
  c3_info[15].mFileTimeLo = 0U;
  c3_info[15].mFileTimeHi = 0U;
  c3_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[16].name = "eml_scalar_eg";
  c3_info[16].dominantType = "double";
  c3_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c3_info[16].fileTimeLo = 1286818796U;
  c3_info[16].fileTimeHi = 0U;
  c3_info[16].mFileTimeLo = 0U;
  c3_info[16].mFileTimeHi = 0U;
  c3_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[17].name = "eml_index_class";
  c3_info[17].dominantType = "";
  c3_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[17].fileTimeLo = 1323170578U;
  c3_info[17].fileTimeHi = 0U;
  c3_info[17].mFileTimeLo = 0U;
  c3_info[17].mFileTimeHi = 0U;
  c3_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[18].name = "eml_index_minus";
  c3_info[18].dominantType = "double";
  c3_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[18].fileTimeLo = 1286818778U;
  c3_info[18].fileTimeHi = 0U;
  c3_info[18].mFileTimeLo = 0U;
  c3_info[18].mFileTimeHi = 0U;
  c3_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c3_info[19].name = "eml_index_class";
  c3_info[19].dominantType = "";
  c3_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[19].fileTimeLo = 1323170578U;
  c3_info[19].fileTimeHi = 0U;
  c3_info[19].mFileTimeLo = 0U;
  c3_info[19].mFileTimeHi = 0U;
  c3_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[20].name = "eml_index_times";
  c3_info[20].dominantType = "coder.internal.indexInt";
  c3_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[20].fileTimeLo = 1286818780U;
  c3_info[20].fileTimeHi = 0U;
  c3_info[20].mFileTimeLo = 0U;
  c3_info[20].mFileTimeHi = 0U;
  c3_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c3_info[21].name = "eml_index_class";
  c3_info[21].dominantType = "";
  c3_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[21].fileTimeLo = 1323170578U;
  c3_info[21].fileTimeHi = 0U;
  c3_info[21].mFileTimeLo = 0U;
  c3_info[21].mFileTimeHi = 0U;
  c3_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[22].name = "eml_index_plus";
  c3_info[22].dominantType = "coder.internal.indexInt";
  c3_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[22].fileTimeLo = 1286818778U;
  c3_info[22].fileTimeHi = 0U;
  c3_info[22].mFileTimeLo = 0U;
  c3_info[22].mFileTimeHi = 0U;
  c3_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c3_info[23].name = "eml_index_class";
  c3_info[23].dominantType = "";
  c3_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c3_info[23].fileTimeLo = 1323170578U;
  c3_info[23].fileTimeHi = 0U;
  c3_info[23].mFileTimeLo = 0U;
  c3_info[23].mFileTimeHi = 0U;
  c3_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c3_info[24].name = "eml_int_forloop_overflow_check";
  c3_info[24].dominantType = "";
  c3_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c3_info[24].fileTimeLo = 1346510340U;
  c3_info[24].fileTimeHi = 0U;
  c3_info[24].mFileTimeLo = 0U;
  c3_info[24].mFileTimeHi = 0U;
  c3_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c3_info[25].name = "intmax";
  c3_info[25].dominantType = "char";
  c3_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c3_info[25].fileTimeLo = 1311255316U;
  c3_info[25].fileTimeHi = 0U;
  c3_info[25].mFileTimeLo = 0U;
  c3_info[25].mFileTimeHi = 0U;
}

static void c3_round(SFc3_controller_templateInstanceStruct *chartInstance,
                     real_T c3_x[2], real_T c3_b_x[2])
{
  int32_T c3_i65;
  for (c3_i65 = 0; c3_i65 < 2; c3_i65++) {
    c3_b_x[c3_i65] = c3_x[c3_i65];
  }

  c3_b_round(chartInstance, c3_b_x);
}

static void c3_eml_scalar_eg(SFc3_controller_templateInstanceStruct
  *chartInstance)
{
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_f_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i66;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i66, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i66;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_controller_template, const
  char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_controller_template), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_controller_template);
  return c3_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_controller_templateInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_round(SFc3_controller_templateInstanceStruct *chartInstance,
  real_T c3_x[2])
{
  int32_T c3_k;
  real_T c3_b_k;
  real_T c3_b_x;
  real_T c3_c_x;
  for (c3_k = 0; c3_k < 2; c3_k++) {
    c3_b_k = 1.0 + (real_T)c3_k;
    c3_b_x = c3_x[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c3_b_k), 1, 2, 1, 0) - 1];
    c3_c_x = c3_b_x;
    c3_c_x = muDoubleScalarRound(c3_c_x);
    c3_x[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c3_b_k), 1, 2, 1, 0) - 1] = c3_c_x;
  }
}

static void init_dsm_address_info(SFc3_controller_templateInstanceStruct
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

void sf_c3_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2004453289U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3619599573U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3231849737U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4068672140U);
}

mxArray *sf_c3_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("22mODf3Ury59sWjdqfxtkG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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
      pr[0] = (double)(88);
      pr[1] = (double)(2);
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
      pr[0] = (double)(88);
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
      pr[0] = (double)(21);
      pr[1] = (double)(2);
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
      pr[0] = (double)(21);
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
      pr[0] = (double)(21);
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

mxArray *sf_c3_controller_template_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c3_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"U\",},{M[1],M[16],T\"flag_oob\",},{M[8],M[0],T\"is_active_c3_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc3_controller_templateInstanceStruct *) ((ChartInfoStruct
      *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _controller_templateMachineNumber_,
           3,
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
            (sfGlobalDebugInstanceStruct,_controller_templateMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _controller_templateMachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,5,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1197);
        _SFD_CV_INIT_EML_IF(0,1,0,778,809,-1,894);
        _SFD_CV_INIT_EML_IF(0,1,1,912,936,-1,996);
        _SFD_CV_INIT_EML_IF(0,1,2,1037,1055,-1,-2);
        _SFD_CV_INIT_EML_FOR(0,1,0,261,277,1103);
        _SFD_CV_INIT_EML_FOR(0,1,1,384,403,486);
        _SFD_CV_INIT_EML_FOR(0,1,2,411,423,478);
        _SFD_CV_INIT_EML_FOR(0,1,3,554,573,620);
        _SFD_CV_INIT_EML_FOR(0,1,4,731,745,902);
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
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 88;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 88;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 21;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 21;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 21;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);

        {
          real_T *c3_U;
          real_T *c3_flag_oob;
          real_T (*c3_X)[2];
          real_T (*c3_Hn)[176];
          real_T (*c3_Kn)[88];
          real_T (*c3_Fi)[42];
          real_T (*c3_Gi)[21];
          real_T (*c3_Nc)[21];
          c3_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c3_Nc = (real_T (*)[21])ssGetInputPortSignal(chartInstance->S, 5);
          c3_Gi = (real_T (*)[21])ssGetInputPortSignal(chartInstance->S, 4);
          c3_Fi = (real_T (*)[42])ssGetInputPortSignal(chartInstance->S, 3);
          c3_Kn = (real_T (*)[88])ssGetInputPortSignal(chartInstance->S, 2);
          c3_Hn = (real_T (*)[176])ssGetInputPortSignal(chartInstance->S, 1);
          c3_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_X = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c3_X);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_U);
          _SFD_SET_DATA_VALUE_PTR(2U, *c3_Hn);
          _SFD_SET_DATA_VALUE_PTR(3U, *c3_Kn);
          _SFD_SET_DATA_VALUE_PTR(4U, *c3_Fi);
          _SFD_SET_DATA_VALUE_PTR(5U, *c3_Gi);
          _SFD_SET_DATA_VALUE_PTR(6U, *c3_Nc);
          _SFD_SET_DATA_VALUE_PTR(7U, c3_flag_oob);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _controller_templateMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "Lgkvb8MvfQZQSa7AyqgRwB";
}

static void sf_opaque_initialize_c3_controller_template(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_controller_template
    ((SFc3_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c3_controller_template((SFc3_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_controller_template(void *chartInstanceVar)
{
  enable_c3_controller_template((SFc3_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_controller_template(void *chartInstanceVar)
{
  disable_c3_controller_template((SFc3_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_controller_template(void *chartInstanceVar)
{
  sf_c3_controller_template((SFc3_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_controller_template(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_controller_template
    ((SFc3_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c3_controller_template(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_controller_template((SFc3_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c3_controller_template(S);
}

static void sf_opaque_set_sim_state_c3_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c3_controller_template(S, st);
}

static void sf_opaque_terminate_c3_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_controller_template_optimization_info();
    }

    finalize_c3_controller_template((SFc3_controller_templateInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_controller_template((SFc3_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_controller_template
      ((SFc3_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2718739814U));
  ssSetChecksum1(S,(898387830U));
  ssSetChecksum2(S,(1816442545U));
  ssSetChecksum3(S,(2646026925U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_controller_template(SimStruct *S)
{
  SFc3_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc3_controller_templateInstanceStruct *)utMalloc(sizeof
    (SFc3_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_controller_template;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_controller_template;
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

void c3_controller_template_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
