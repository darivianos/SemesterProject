/* Include files */

#include <stddef.h>
#include "blas.h"
#include "untitled_sfun.h"
#include "c1_untitled.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "untitled_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[25] = { "tolerance", "nr",
  "MPT_ABSTOL", "minreg", "abspos", "ireg", "sumViol", "isinside", "Hi", "Ki",
  "F", "G", "nc", "ic", "hx", "nargin", "nargout", "X", "Hn", "Kn", "Fi", "Gi",
  "Nc", "U", "flag_oob" };

/* Function Declarations */
static void initialize_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void initialize_params_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance);
static void enable_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void disable_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance);
static void set_sim_state_c1_untitled(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_st);
static void finalize_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void sf_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void c1_chartstep_c1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void initSimStructsc1_untitled(SFc1_untitledInstanceStruct *chartInstance);
static void registerMessagesc1_untitled(SFc1_untitledInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_flag_oob, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_c_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[940], int32_T c1_inData_sizes[1]);
static void c1_d_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y_data
  [940], int32_T c1_y_sizes[1]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[940],
  int32_T c1_outData_sizes[1]);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[3760], int32_T c1_inData_sizes[2]);
static void c1_e_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y_data
  [3760], int32_T c1_y_sizes[2]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[3760],
  int32_T c1_outData_sizes[2]);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[26]);
static void c1_round(SFc1_untitledInstanceStruct *chartInstance, real_T c1_x[4],
                     real_T c1_b_x[4]);
static void c1_eml_scalar_eg(SFc1_untitledInstanceStruct *chartInstance);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_g_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_untitled, const char_T *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_round(SFc1_untitledInstanceStruct *chartInstance, real_T c1_x[4]);
static void init_dsm_address_info(SFc1_untitledInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_untitled = 0U;
}

static void initialize_params_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance)
{
}

static void enable_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c1_untitled(SFc1_untitledInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  uint8_T c1_c_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T *c1_U;
  real_T *c1_flag_oob;
  c1_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3), FALSE);
  c1_hoistedGlobal = *c1_U;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = *c1_flag_oob;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_c_hoistedGlobal = chartInstance->c1_is_active_c1_untitled;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_untitled(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_U;
  real_T *c1_flag_oob;
  c1_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_U = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "U");
  *c1_flag_oob = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "flag_oob");
  chartInstance->c1_is_active_c1_untitled = c1_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 2)), "is_active_c1_untitled");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_untitled(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
}

static void sf_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  real_T *c1_U;
  real_T *c1_flag_oob;
  real_T (*c1_Nc)[107];
  real_T (*c1_Gi)[107];
  real_T (*c1_Fi)[428];
  real_T (*c1_Kn)[940];
  real_T (*c1_Hn)[3760];
  real_T (*c1_X)[4];
  c1_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Nc = (real_T (*)[107])ssGetInputPortSignal(chartInstance->S, 5);
  c1_Gi = (real_T (*)[107])ssGetInputPortSignal(chartInstance->S, 4);
  c1_Fi = (real_T (*)[428])ssGetInputPortSignal(chartInstance->S, 3);
  c1_Kn = (real_T (*)[940])ssGetInputPortSignal(chartInstance->S, 2);
  c1_Hn = (real_T (*)[3760])ssGetInputPortSignal(chartInstance->S, 1);
  c1_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_X)[c1_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_U, 1U);
  for (c1_i1 = 0; c1_i1 < 3760; c1_i1++) {
    _SFD_DATA_RANGE_CHECK((*c1_Hn)[c1_i1], 2U);
  }

  for (c1_i2 = 0; c1_i2 < 940; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_Kn)[c1_i2], 3U);
  }

  for (c1_i3 = 0; c1_i3 < 428; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_Fi)[c1_i3], 4U);
  }

  for (c1_i4 = 0; c1_i4 < 107; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_Gi)[c1_i4], 5U);
  }

  for (c1_i5 = 0; c1_i5 < 107; c1_i5++) {
    _SFD_DATA_RANGE_CHECK((*c1_Nc)[c1_i5], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_flag_oob, 7U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_untitled(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_untitledMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
  int32_T c1_i6;
  real_T c1_X[4];
  int32_T c1_i7;
  real_T c1_Hn[3760];
  int32_T c1_i8;
  real_T c1_Kn[940];
  int32_T c1_i9;
  real_T c1_Fi[428];
  int32_T c1_i10;
  real_T c1_Gi[107];
  int32_T c1_i11;
  real_T c1_Nc[107];
  uint32_T c1_debug_family_var_map[25];
  real_T c1_tolerance;
  real_T c1_nr;
  real_T c1_MPT_ABSTOL;
  real_T c1_minreg;
  real_T c1_abspos;
  real_T c1_ireg;
  real_T c1_sumViol;
  real_T c1_isinside;
  int32_T c1_Hi_sizes[2];
  real_T c1_Hi_data[3760];
  int32_T c1_Ki_sizes;
  real_T c1_Ki_data[940];
  real_T c1_F[4];
  real_T c1_G;
  real_T c1_nc;
  real_T c1_ic;
  real_T c1_hx;
  real_T c1_nargin = 6.0;
  real_T c1_nargout = 2.0;
  real_T c1_U;
  real_T c1_flag_oob;
  int32_T c1_i12;
  real_T c1_b[4];
  int32_T c1_i13;
  int32_T c1_i14;
  int32_T c1_b_ireg;
  real_T c1_d0;
  boolean_T c1_b0;
  boolean_T c1_b1;
  boolean_T c1_b2;
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_loop_ub;
  int32_T c1_i18;
  real_T c1_d1;
  boolean_T c1_b3;
  boolean_T c1_b4;
  boolean_T c1_b5;
  int32_T c1_i19;
  int32_T c1_i20;
  int32_T c1_b_loop_ub;
  int32_T c1_i21;
  int32_T c1_c_ireg;
  int32_T c1_i22;
  real_T c1_b_nc;
  int32_T c1_i23;
  int32_T c1_b_ic;
  int32_T c1_c_ic;
  int32_T c1_i24;
  real_T c1_a[4];
  int32_T c1_i25;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_i26;
  int32_T c1_i27;
  real_T c1_y;
  int32_T c1_c_k;
  int32_T c1_d_k;
  int32_T c1_b_minreg;
  int32_T c1_i28;
  int32_T c1_i29;
  int32_T c1_i30;
  real_T c1_b_y;
  int32_T c1_e_k;
  int32_T c1_f_k;
  real_T *c1_b_U;
  real_T *c1_b_flag_oob;
  real_T (*c1_b_Nc)[107];
  real_T (*c1_b_Gi)[107];
  real_T (*c1_b_Fi)[428];
  real_T (*c1_b_Kn)[940];
  real_T (*c1_b_Hn)[3760];
  real_T (*c1_b_X)[4];
  int32_T exitg1;
  c1_b_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_Nc = (real_T (*)[107])ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_Gi = (real_T (*)[107])ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_Fi = (real_T (*)[428])ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_Kn = (real_T (*)[940])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_Hn = (real_T (*)[3760])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i6 = 0; c1_i6 < 4; c1_i6++) {
    c1_X[c1_i6] = (*c1_b_X)[c1_i6];
  }

  for (c1_i7 = 0; c1_i7 < 3760; c1_i7++) {
    c1_Hn[c1_i7] = (*c1_b_Hn)[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 940; c1_i8++) {
    c1_Kn[c1_i8] = (*c1_b_Kn)[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 428; c1_i9++) {
    c1_Fi[c1_i9] = (*c1_b_Fi)[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 107; c1_i10++) {
    c1_Gi[c1_i10] = (*c1_b_Gi)[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 107; c1_i11++) {
    c1_Nc[c1_i11] = (*c1_b_Nc)[c1_i11];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 25U, 25U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_tolerance, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_nr, 1U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_MPT_ABSTOL, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_minreg, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_abspos, 4U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ireg, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sumViol, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_isinside, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c1_Hi_data, (const int32_T *)
    &c1_Hi_sizes, NULL, 0, 8, (void *)c1_i_sf_marshallOut, (void *)
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_DYN_IMPORTABLE(c1_Ki_data, (const int32_T *)
    &c1_Ki_sizes, NULL, 0, 9, (void *)c1_h_sf_marshallOut, (void *)
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_F, 10U, c1_g_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_G, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nc, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ic, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_hx, 14U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 15U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 16U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_X, 17U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Hn, 18U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Kn, 19U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Fi, 20U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Gi, 21U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Nc, 22U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_U, 23U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_flag_oob, 24U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_tolerance = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
  c1_nr = 107.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  c1_MPT_ABSTOL = 1.0E-8;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
  c1_minreg = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 7);
  for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
    c1_b[c1_i12] = c1_X[c1_i12];
  }

  for (c1_i13 = 0; c1_i13 < 4; c1_i13++) {
    c1_b[c1_i13] *= 10000.0;
  }

  c1_b_round(chartInstance, c1_b);
  for (c1_i14 = 0; c1_i14 < 4; c1_i14++) {
    c1_X[c1_i14] = c1_b[c1_i14] / 10000.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 9);
  c1_flag_oob = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 12);
  c1_abspos = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  c1_ireg = 1.0;
  c1_b_ireg = 0;
  do {
    exitg1 = 0;
    if (c1_b_ireg < 107) {
      c1_ireg = 1.0 + (real_T)c1_b_ireg;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 14);
      c1_sumViol = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 15);
      c1_isinside = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
      c1_d0 = (c1_abspos + c1_Nc[(int32_T)c1_ireg - 1]) - 1.0;
      c1_b0 = (c1_abspos > c1_d0);
      c1_b1 = c1_b0;
      c1_b2 = c1_b1;
      if (c1_b2) {
        c1_i15 = 1;
        c1_i16 = 0;
      } else {
        c1_i15 = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)
          _SFD_INTEGER_CHECK("abspos", c1_abspos), 1, 940, 0, 0);
        c1_i16 = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)
          _SFD_INTEGER_CHECK("abspos:abspos+Nc(ireg)-1", c1_d0), 1, 940, 0, 0);
      }

      c1_Hi_sizes[0] = (c1_i16 - c1_i15) + 1;
      c1_Hi_sizes[1] = 4;
      for (c1_i17 = 0; c1_i17 < 4; c1_i17++) {
        c1_loop_ub = c1_i16 - c1_i15;
        for (c1_i18 = 0; c1_i18 <= c1_loop_ub; c1_i18++) {
          c1_Hi_data[c1_i18 + c1_Hi_sizes[0] * c1_i17] = c1_Hn[((c1_i15 + c1_i18)
            + 940 * c1_i17) - 1];
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
      c1_d1 = (c1_abspos + c1_Nc[(int32_T)c1_ireg - 1]) - 1.0;
      c1_b3 = (c1_abspos > c1_d1);
      c1_b4 = c1_b3;
      c1_b5 = c1_b4;
      if (c1_b5) {
        c1_i19 = 1;
        c1_i20 = 0;
      } else {
        c1_i19 = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Kn", (int32_T)
          _SFD_INTEGER_CHECK("abspos", c1_abspos), 1, 940, 0, 0);
        c1_i20 = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Kn", (int32_T)
          _SFD_INTEGER_CHECK("abspos:abspos+Nc(ireg)-1", c1_d1), 1, 940, 0, 0);
      }

      c1_Ki_sizes = (c1_i20 - c1_i19) + 1;
      c1_b_loop_ub = c1_i20 - c1_i19;
      for (c1_i21 = 0; c1_i21 <= c1_b_loop_ub; c1_i21++) {
        c1_Ki_data[c1_i21] = c1_Kn[(c1_i19 + c1_i21) - 1];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
      c1_abspos += c1_Nc[(int32_T)c1_ireg - 1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 21);
      c1_c_ireg = (int32_T)c1_ireg - 1;
      for (c1_i22 = 0; c1_i22 < 4; c1_i22++) {
        c1_F[c1_i22] = c1_Fi[c1_c_ireg + 107 * c1_i22];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 22);
      c1_G = c1_Gi[(int32_T)c1_ireg - 1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
      c1_nc = c1_Nc[(int32_T)c1_ireg - 1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 26);
      c1_b_nc = c1_nc;
      c1_i23 = (int32_T)c1_b_nc;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c1_b_nc, mxDOUBLE_CLASS, c1_i23);
      c1_ic = 1.0;
      c1_b_ic = 0;
      while (c1_b_ic <= c1_i23 - 1) {
        c1_ic = 1.0 + (real_T)c1_b_ic;
        CV_EML_FOR(0, 1, 1, 1);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 27);
        c1_c_ic = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)
          c1_ic, 1, c1_Hi_sizes[0], 1, 0) - 1;
        for (c1_i24 = 0; c1_i24 < 4; c1_i24++) {
          c1_a[c1_i24] = c1_Hi_data[c1_c_ic + c1_Hi_sizes[0] * c1_i24];
        }

        for (c1_i25 = 0; c1_i25 < 4; c1_i25++) {
          c1_b[c1_i25] = c1_X[c1_i25];
        }

        c1_eml_scalar_eg(chartInstance);
        c1_eml_scalar_eg(chartInstance);
        c1_hx = 0.0;
        for (c1_k = 1; c1_k < 5; c1_k++) {
          c1_b_k = c1_k - 1;
          c1_hx += c1_a[c1_b_k] * c1_b[c1_b_k];
        }

        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 28);
        if (CV_EML_IF(0, 1, 0, c1_hx - c1_Ki_data[(int32_T)(real_T)
                      _SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)c1_ic, 1,
              c1_Ki_sizes, 1, 0) - 1] > 1.0E-8)) {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 29);
          c1_isinside = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
          c1_sumViol += c1_hx - c1_Ki_data[(int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)c1_ic, 1, c1_Ki_sizes, 1,
            0) - 1];
        }

        c1_b_ic++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 1, 0);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 34);
      if (CV_EML_IF(0, 1, 1, c1_sumViol < c1_tolerance)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
        c1_tolerance = c1_sumViol;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 36);
        c1_minreg = c1_ireg;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
      if (CV_EML_IF(0, 1, 2, c1_isinside == 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 40);
        for (c1_i26 = 0; c1_i26 < 4; c1_i26++) {
          c1_a[c1_i26] = c1_F[c1_i26];
        }

        for (c1_i27 = 0; c1_i27 < 4; c1_i27++) {
          c1_b[c1_i27] = c1_X[c1_i27];
        }

        c1_eml_scalar_eg(chartInstance);
        c1_eml_scalar_eg(chartInstance);
        c1_y = 0.0;
        for (c1_c_k = 1; c1_c_k < 5; c1_c_k++) {
          c1_d_k = c1_c_k - 1;
          c1_y += c1_a[c1_d_k] * c1_b[c1_d_k];
        }

        c1_U = c1_y + c1_G;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
        exitg1 = 1;
      } else {
        c1_b_ireg++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(0, 1, 0, 0);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
      c1_b_minreg = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)
        c1_minreg, 1, 107, 1, 0) - 1;
      for (c1_i28 = 0; c1_i28 < 4; c1_i28++) {
        c1_F[c1_i28] = c1_Fi[c1_b_minreg + 107 * c1_i28];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 45);
      c1_G = c1_Gi[(int32_T)c1_minreg - 1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 46);
      for (c1_i29 = 0; c1_i29 < 4; c1_i29++) {
        c1_a[c1_i29] = c1_F[c1_i29];
      }

      for (c1_i30 = 0; c1_i30 < 4; c1_i30++) {
        c1_b[c1_i30] = c1_X[c1_i30];
      }

      c1_eml_scalar_eg(chartInstance);
      c1_eml_scalar_eg(chartInstance);
      c1_b_y = 0.0;
      for (c1_e_k = 1; c1_e_k < 5; c1_e_k++) {
        c1_f_k = c1_e_k - 1;
        c1_b_y += c1_a[c1_f_k] * c1_b[c1_f_k];
      }

      c1_U = c1_b_y + c1_G;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
      c1_flag_oob = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 49);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -49);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_U = c1_U;
  *c1_b_flag_oob = c1_flag_oob;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_untitled(SFc1_untitledInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_untitled(SFc1_untitledInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_flag_oob, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_flag_oob),
    &c1_thisId);
  sf_mex_destroy(&c1_flag_oob);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d2;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d2, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d2;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_flag_oob;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_flag_oob = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_flag_oob),
    &c1_thisId);
  sf_mex_destroy(&c1_flag_oob);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i31;
  real_T c1_b_inData[107];
  int32_T c1_i32;
  real_T c1_u[107];
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i31 = 0; c1_i31 < 107; c1_i31++) {
    c1_b_inData[c1_i31] = (*(real_T (*)[107])c1_inData)[c1_i31];
  }

  for (c1_i32 = 0; c1_i32 < 107; c1_i32++) {
    c1_u[c1_i32] = c1_b_inData[c1_i32];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 107), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  real_T c1_b_inData[428];
  int32_T c1_i36;
  int32_T c1_i37;
  int32_T c1_i38;
  real_T c1_u[428];
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i33 = 0;
  for (c1_i34 = 0; c1_i34 < 4; c1_i34++) {
    for (c1_i35 = 0; c1_i35 < 107; c1_i35++) {
      c1_b_inData[c1_i35 + c1_i33] = (*(real_T (*)[428])c1_inData)[c1_i35 +
        c1_i33];
    }

    c1_i33 += 107;
  }

  c1_i36 = 0;
  for (c1_i37 = 0; c1_i37 < 4; c1_i37++) {
    for (c1_i38 = 0; c1_i38 < 107; c1_i38++) {
      c1_u[c1_i38 + c1_i36] = c1_b_inData[c1_i38 + c1_i36];
    }

    c1_i36 += 107;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 107, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i39;
  real_T c1_b_inData[940];
  int32_T c1_i40;
  real_T c1_u[940];
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i39 = 0; c1_i39 < 940; c1_i39++) {
    c1_b_inData[c1_i39] = (*(real_T (*)[940])c1_inData)[c1_i39];
  }

  for (c1_i40 = 0; c1_i40 < 940; c1_i40++) {
    c1_u[c1_i40] = c1_b_inData[c1_i40];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 940), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  real_T c1_b_inData[3760];
  int32_T c1_i44;
  int32_T c1_i45;
  int32_T c1_i46;
  real_T c1_u[3760];
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i41 = 0;
  for (c1_i42 = 0; c1_i42 < 4; c1_i42++) {
    for (c1_i43 = 0; c1_i43 < 940; c1_i43++) {
      c1_b_inData[c1_i43 + c1_i41] = (*(real_T (*)[3760])c1_inData)[c1_i43 +
        c1_i41];
    }

    c1_i41 += 940;
  }

  c1_i44 = 0;
  for (c1_i45 = 0; c1_i45 < 4; c1_i45++) {
    for (c1_i46 = 0; c1_i46 < 940; c1_i46++) {
      c1_u[c1_i46 + c1_i44] = c1_b_inData[c1_i46 + c1_i44];
    }

    c1_i44 += 940;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 940, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i47;
  real_T c1_b_inData[4];
  int32_T c1_i48;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i47 = 0; c1_i47 < 4; c1_i47++) {
    c1_b_inData[c1_i47] = (*(real_T (*)[4])c1_inData)[c1_i47];
  }

  for (c1_i48 = 0; c1_i48 < 4; c1_i48++) {
    c1_u[c1_i48] = c1_b_inData[c1_i48];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i49;
  real_T c1_b_inData[4];
  int32_T c1_i50;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i49 = 0; c1_i49 < 4; c1_i49++) {
    c1_b_inData[c1_i49] = (*(real_T (*)[4])c1_inData)[c1_i49];
  }

  for (c1_i50 = 0; c1_i50 < 4; c1_i50++) {
    c1_u[c1_i50] = c1_b_inData[c1_i50];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv0[4];
  int32_T c1_i51;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c1_i51 = 0; c1_i51 < 4; c1_i51++) {
    c1_y[c1_i51] = c1_dv0[c1_i51];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_F;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4];
  int32_T c1_i52;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_F = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_F), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_F);
  for (c1_i52 = 0; c1_i52 < 4; c1_i52++) {
    (*(real_T (*)[4])c1_outData)[c1_i52] = c1_y[c1_i52];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[940], int32_T c1_inData_sizes[1])
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_b_inData_sizes;
  int32_T c1_loop_ub;
  int32_T c1_i53;
  real_T c1_b_inData_data[940];
  int32_T c1_u_sizes;
  int32_T c1_b_loop_ub;
  int32_T c1_i54;
  real_T c1_u_data[940];
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_b_inData_sizes = c1_inData_sizes[0];
  c1_loop_ub = c1_inData_sizes[0] - 1;
  for (c1_i53 = 0; c1_i53 <= c1_loop_ub; c1_i53++) {
    c1_b_inData_data[c1_i53] = c1_inData_data[c1_i53];
  }

  c1_u_sizes = c1_b_inData_sizes;
  c1_b_loop_ub = c1_b_inData_sizes - 1;
  for (c1_i54 = 0; c1_i54 <= c1_b_loop_ub; c1_i54++) {
    c1_u_data[c1_i54] = c1_b_inData_data[c1_i54];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u_data, 0, 0U, 1U, 0U, 1,
    c1_u_sizes), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y_data
  [940], int32_T c1_y_sizes[1])
{
  static uint32_T c1_uv0[1] = { 940U };

  uint32_T c1_uv1[1];
  static boolean_T c1_bv0[1] = { TRUE };

  boolean_T c1_bv1[1];
  int32_T c1_tmp_sizes;
  real_T c1_tmp_data[940];
  int32_T c1_loop_ub;
  int32_T c1_i55;
  c1_uv1[0] = c1_uv0[0];
  c1_bv1[0] = c1_bv0[0];
  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_u), c1_tmp_data, 1, 0, 0U, 1, 0U,
                   1, c1_bv1, c1_uv1, &c1_tmp_sizes);
  c1_y_sizes[0] = c1_tmp_sizes;
  c1_loop_ub = c1_tmp_sizes - 1;
  for (c1_i55 = 0; c1_i55 <= c1_loop_ub; c1_i55++) {
    c1_y_data[c1_i55] = c1_tmp_data[c1_i55];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[940],
  int32_T c1_outData_sizes[1])
{
  const mxArray *c1_Ki;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y_sizes;
  real_T c1_y_data[940];
  int32_T c1_loop_ub;
  int32_T c1_i56;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_Ki = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Ki), &c1_thisId, c1_y_data,
                        *(int32_T (*)[1])&c1_y_sizes);
  sf_mex_destroy(&c1_Ki);
  c1_outData_sizes[0] = c1_y_sizes;
  c1_loop_ub = c1_y_sizes - 1;
  for (c1_i56 = 0; c1_i56 <= c1_loop_ub; c1_i56++) {
    c1_outData_data[c1_i56] = c1_y_data[c1_i56];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, real_T
  c1_inData_data[3760], int32_T c1_inData_sizes[2])
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_b_inData_sizes[2];
  int32_T c1_i57;
  int32_T c1_loop_ub;
  int32_T c1_i58;
  real_T c1_b_inData_data[3760];
  int32_T c1_u_sizes[2];
  int32_T c1_i59;
  int32_T c1_b_loop_ub;
  int32_T c1_i60;
  real_T c1_u_data[3760];
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_b_inData_sizes[0] = c1_inData_sizes[0];
  c1_b_inData_sizes[1] = 4;
  for (c1_i57 = 0; c1_i57 < 4; c1_i57++) {
    c1_loop_ub = c1_inData_sizes[0] - 1;
    for (c1_i58 = 0; c1_i58 <= c1_loop_ub; c1_i58++) {
      c1_b_inData_data[c1_i58 + c1_b_inData_sizes[0] * c1_i57] =
        c1_inData_data[c1_i58 + c1_inData_sizes[0] * c1_i57];
    }
  }

  c1_u_sizes[0] = c1_b_inData_sizes[0];
  c1_u_sizes[1] = 4;
  for (c1_i59 = 0; c1_i59 < 4; c1_i59++) {
    c1_b_loop_ub = c1_b_inData_sizes[0] - 1;
    for (c1_i60 = 0; c1_i60 <= c1_b_loop_ub; c1_i60++) {
      c1_u_data[c1_i60 + c1_u_sizes[0] * c1_i59] = c1_b_inData_data[c1_i60 +
        c1_b_inData_sizes[0] * c1_i59];
    }
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u_data, 0, 0U, 1U, 0U, 2,
    c1_u_sizes[0], c1_u_sizes[1]), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y_data
  [3760], int32_T c1_y_sizes[2])
{
  int32_T c1_i61;
  static uint32_T c1_uv2[2] = { 940U, 4U };

  uint32_T c1_uv3[2];
  int32_T c1_i62;
  static boolean_T c1_bv2[2] = { TRUE, FALSE };

  boolean_T c1_bv3[2];
  int32_T c1_tmp_sizes[2];
  real_T c1_tmp_data[3760];
  int32_T c1_y;
  int32_T c1_b_y;
  int32_T c1_loop_ub;
  int32_T c1_i63;
  for (c1_i61 = 0; c1_i61 < 2; c1_i61++) {
    c1_uv3[c1_i61] = c1_uv2[c1_i61];
  }

  for (c1_i62 = 0; c1_i62 < 2; c1_i62++) {
    c1_bv3[c1_i62] = c1_bv2[c1_i62];
  }

  sf_mex_import_vs(c1_parentId, sf_mex_dup(c1_u), c1_tmp_data, 1, 0, 0U, 1, 0U,
                   2, c1_bv3, c1_uv3, c1_tmp_sizes);
  c1_y_sizes[0] = c1_tmp_sizes[0];
  c1_y_sizes[1] = 4;
  c1_y = c1_y_sizes[0];
  c1_b_y = c1_y_sizes[1];
  c1_loop_ub = c1_tmp_sizes[0] * c1_tmp_sizes[1] - 1;
  for (c1_i63 = 0; c1_i63 <= c1_loop_ub; c1_i63++) {
    c1_y_data[c1_i63] = c1_tmp_data[c1_i63];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, real_T c1_outData_data[3760],
  int32_T c1_outData_sizes[2])
{
  const mxArray *c1_Hi;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y_sizes[2];
  real_T c1_y_data[3760];
  int32_T c1_i64;
  int32_T c1_loop_ub;
  int32_T c1_i65;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_Hi = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Hi), &c1_thisId, c1_y_data,
                        c1_y_sizes);
  sf_mex_destroy(&c1_Hi);
  c1_outData_sizes[0] = c1_y_sizes[0];
  c1_outData_sizes[1] = 4;
  for (c1_i64 = 0; c1_i64 < 4; c1_i64++) {
    c1_loop_ub = c1_y_sizes[0] - 1;
    for (c1_i65 = 0; c1_i65 <= c1_loop_ub; c1_i65++) {
      c1_outData_data[c1_i65 + c1_outData_sizes[0] * c1_i64] = c1_y_data[c1_i65
        + c1_y_sizes[0] * c1_i64];
    }
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_untitled_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[26];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i66;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 26), FALSE);
  for (c1_i66 = 0; c1_i66 < 26; c1_i66++) {
    c1_r0 = &c1_info[c1_i66];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i66);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i66);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i66);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i66);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i66);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i66);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i66);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i66);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[26])
{
  c1_info[0].context = "";
  c1_info[0].name = "mtimes";
  c1_info[0].dominantType = "double";
  c1_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[0].fileTimeLo = 1289519692U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context = "";
  c1_info[1].name = "round";
  c1_info[1].dominantType = "double";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c1_info[1].fileTimeLo = 1343830384U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c1_info[2].name = "eml_scalar_round";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c1_info[2].fileTimeLo = 1307651238U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "";
  c1_info[3].name = "mrdivide";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[3].fileTimeLo = 1357951548U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 1319729966U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[4].name = "rdivide";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[4].fileTimeLo = 1346510388U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[5].name = "eml_scalexp_compatible";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  c1_info[5].fileTimeLo = 1286818796U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[6].name = "eml_div";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[6].fileTimeLo = 1313347810U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[7].name = "eml_index_class";
  c1_info[7].dominantType = "";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[7].fileTimeLo = 1323170578U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[8].name = "eml_scalar_eg";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[8].fileTimeLo = 1286818796U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].name = "eml_xdotu";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[9].fileTimeLo = 1299076772U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[10].name = "eml_blas_inline";
  c1_info[10].dominantType = "";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[10].fileTimeLo = 1299076768U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[11].name = "eml_xdot";
  c1_info[11].dominantType = "double";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c1_info[11].fileTimeLo = 1299076772U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c1_info[12].name = "eml_blas_inline";
  c1_info[12].dominantType = "";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[12].fileTimeLo = 1299076768U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c1_info[13].name = "eml_index_class";
  c1_info[13].dominantType = "";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[13].fileTimeLo = 1323170578U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c1_info[14].name = "eml_refblas_xdot";
  c1_info[14].dominantType = "double";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[14].fileTimeLo = 1299076772U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[15].name = "eml_refblas_xdotx";
  c1_info[15].dominantType = "char";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[15].fileTimeLo = 1299076774U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[16].name = "eml_scalar_eg";
  c1_info[16].dominantType = "double";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[16].fileTimeLo = 1286818796U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[17].name = "eml_index_class";
  c1_info[17].dominantType = "";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[17].fileTimeLo = 1323170578U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
  c1_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[18].name = "eml_index_minus";
  c1_info[18].dominantType = "double";
  c1_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[18].fileTimeLo = 1286818778U;
  c1_info[18].fileTimeHi = 0U;
  c1_info[18].mFileTimeLo = 0U;
  c1_info[18].mFileTimeHi = 0U;
  c1_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[19].name = "eml_index_class";
  c1_info[19].dominantType = "";
  c1_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[19].fileTimeLo = 1323170578U;
  c1_info[19].fileTimeHi = 0U;
  c1_info[19].mFileTimeLo = 0U;
  c1_info[19].mFileTimeHi = 0U;
  c1_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[20].name = "eml_index_times";
  c1_info[20].dominantType = "coder.internal.indexInt";
  c1_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[20].fileTimeLo = 1286818780U;
  c1_info[20].fileTimeHi = 0U;
  c1_info[20].mFileTimeLo = 0U;
  c1_info[20].mFileTimeHi = 0U;
  c1_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[21].name = "eml_index_class";
  c1_info[21].dominantType = "";
  c1_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[21].fileTimeLo = 1323170578U;
  c1_info[21].fileTimeHi = 0U;
  c1_info[21].mFileTimeLo = 0U;
  c1_info[21].mFileTimeHi = 0U;
  c1_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[22].name = "eml_index_plus";
  c1_info[22].dominantType = "coder.internal.indexInt";
  c1_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[22].fileTimeLo = 1286818778U;
  c1_info[22].fileTimeHi = 0U;
  c1_info[22].mFileTimeLo = 0U;
  c1_info[22].mFileTimeHi = 0U;
  c1_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[23].name = "eml_index_class";
  c1_info[23].dominantType = "";
  c1_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[23].fileTimeLo = 1323170578U;
  c1_info[23].fileTimeHi = 0U;
  c1_info[23].mFileTimeLo = 0U;
  c1_info[23].mFileTimeHi = 0U;
  c1_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[24].name = "eml_int_forloop_overflow_check";
  c1_info[24].dominantType = "";
  c1_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[24].fileTimeLo = 1346510340U;
  c1_info[24].fileTimeHi = 0U;
  c1_info[24].mFileTimeLo = 0U;
  c1_info[24].mFileTimeHi = 0U;
  c1_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[25].name = "intmax";
  c1_info[25].dominantType = "char";
  c1_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[25].fileTimeLo = 1311255316U;
  c1_info[25].fileTimeHi = 0U;
  c1_info[25].mFileTimeLo = 0U;
  c1_info[25].mFileTimeHi = 0U;
}

static void c1_round(SFc1_untitledInstanceStruct *chartInstance, real_T c1_x[4],
                     real_T c1_b_x[4])
{
  int32_T c1_i67;
  for (c1_i67 = 0; c1_i67 < 4; c1_i67++) {
    c1_b_x[c1_i67] = c1_x[c1_i67];
  }

  c1_b_round(chartInstance, c1_b_x);
}

static void c1_eml_scalar_eg(SFc1_untitledInstanceStruct *chartInstance)
{
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i68;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i68, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i68;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_b_is_active_c1_untitled, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_untitled), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_untitled);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_untitledInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_round(SFc1_untitledInstanceStruct *chartInstance, real_T c1_x[4])
{
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  for (c1_k = 0; c1_k < 4; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_b_x = c1_x[(int32_T)c1_b_k - 1];
    c1_c_x = c1_b_x;
    c1_c_x = muDoubleScalarRound(c1_c_x);
    c1_x[(int32_T)c1_b_k - 1] = c1_c_x;
  }
}

static void init_dsm_address_info(SFc1_untitledInstanceStruct *chartInstance)
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

void sf_c1_untitled_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2693654793U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(112421722U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1480845573U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3481636601U);
}

mxArray *sf_c1_untitled_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("giNeUE49lT5W5OhBIVw07E");
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
      pr[0] = (double)(940);
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
      pr[0] = (double)(940);
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
      pr[0] = (double)(107);
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
      pr[0] = (double)(107);
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
      pr[0] = (double)(107);
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

mxArray *sf_c1_untitled_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_untitled(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"U\",},{M[1],M[16],T\"flag_oob\",},{M[8],M[0],T\"is_active_c1_untitled\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_untitled_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_untitledInstanceStruct *chartInstance;
    chartInstance = (SFc1_untitledInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _untitledMachineNumber_,
           1,
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
          init_script_number_translation(_untitledMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_untitledMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _untitledMachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,2,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,916);
        _SFD_CV_INIT_EML_IF(0,1,0,497,528,-1,613);
        _SFD_CV_INIT_EML_IF(0,1,1,631,655,-1,715);
        _SFD_CV_INIT_EML_IF(0,1,2,756,774,-1,-2);
        _SFD_CV_INIT_EML_FOR(0,1,0,202,218,822);
        _SFD_CV_INIT_EML_FOR(0,1,1,450,464,621);
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
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 940;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 940;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 107;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 107;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 107;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_U;
          real_T *c1_flag_oob;
          real_T (*c1_X)[4];
          real_T (*c1_Hn)[3760];
          real_T (*c1_Kn)[940];
          real_T (*c1_Fi)[428];
          real_T (*c1_Gi)[107];
          real_T (*c1_Nc)[107];
          c1_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_Nc = (real_T (*)[107])ssGetInputPortSignal(chartInstance->S, 5);
          c1_Gi = (real_T (*)[107])ssGetInputPortSignal(chartInstance->S, 4);
          c1_Fi = (real_T (*)[428])ssGetInputPortSignal(chartInstance->S, 3);
          c1_Kn = (real_T (*)[940])ssGetInputPortSignal(chartInstance->S, 2);
          c1_Hn = (real_T (*)[3760])ssGetInputPortSignal(chartInstance->S, 1);
          c1_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_X);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_U);
          _SFD_SET_DATA_VALUE_PTR(2U, *c1_Hn);
          _SFD_SET_DATA_VALUE_PTR(3U, *c1_Kn);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_Fi);
          _SFD_SET_DATA_VALUE_PTR(5U, *c1_Gi);
          _SFD_SET_DATA_VALUE_PTR(6U, *c1_Nc);
          _SFD_SET_DATA_VALUE_PTR(7U, c1_flag_oob);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _untitledMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "7NeSBkcpxHUhpQQvJtfyRH";
}

static void sf_opaque_initialize_c1_untitled(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_untitledInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
  initialize_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_untitled(void *chartInstanceVar)
{
  enable_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_untitled(void *chartInstanceVar)
{
  disable_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_untitled(void *chartInstanceVar)
{
  sf_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_untitled(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_untitled((SFc1_untitledInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_untitled();/* state var info */
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

extern void sf_internal_set_sim_state_c1_untitled(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_untitled();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_untitled((SFc1_untitledInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_untitled(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_untitled(S);
}

static void sf_opaque_set_sim_state_c1_untitled(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_untitled(S, st);
}

static void sf_opaque_terminate_c1_untitled(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_untitledInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_untitled_optimization_info();
    }

    finalize_c1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_untitled((SFc1_untitledInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_untitled(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_untitled((SFc1_untitledInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_untitled_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3661303168U));
  ssSetChecksum1(S,(233651536U));
  ssSetChecksum2(S,(806900492U));
  ssSetChecksum3(S,(4102744067U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_untitled(SimStruct *S)
{
  SFc1_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc1_untitledInstanceStruct *)utMalloc(sizeof
    (SFc1_untitledInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_untitledInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_untitled;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_untitled;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_untitled;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_untitled;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_untitled;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_untitled;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_untitled;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_untitled;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_untitled;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_untitled;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_untitled;
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

void c1_untitled_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_untitled(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_untitled(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_untitled(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_untitled_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
