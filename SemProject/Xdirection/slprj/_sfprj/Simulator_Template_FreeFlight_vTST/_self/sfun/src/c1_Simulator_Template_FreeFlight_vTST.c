/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Simulator_Template_FreeFlight_vTST_sfun.h"
#include "c1_Simulator_Template_FreeFlight_vTST.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Simulator_Template_FreeFlight_vTST_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[27] = { "tolerance", "nr",
  "MPT_ABSTOL", "minreg", "Hi", "Ki", "abspos", "ireg", "sumViol", "isinside",
  "i", "j", "F", "G", "nc", "ic", "hx", "nargin", "nargout", "X", "Hn", "Kn",
  "Fi", "Gi", "Nc", "U", "flag_oob" };

/* Function Declarations */
static void initialize_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);
static void initialize_params_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);
static void enable_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);
static void disable_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);
static void set_sim_state_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void finalize_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);
static void sf_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);
static void c1_chartstep_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);
static void initSimStructsc1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);
static void registerMessagesc1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_flag_oob, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
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
static void c1_c_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[100]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[400]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[26]);
static void c1_round(SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct
                     *chartInstance, real_T c1_x[4], real_T c1_b_x[4]);
static void c1_eml_scalar_eg
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_g_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_Simulator_Template_FreeFlight_vTST, const char_T
   *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_round(SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct
  *chartInstance, real_T c1_x[4]);
static void init_dsm_address_info
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_Simulator_Template_FreeFlight_vTST = 0U;
}

static void initialize_params_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
{
}

static void enable_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
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
  c1_c_hoistedGlobal =
    chartInstance->c1_is_active_c1_Simulator_Template_FreeFlight_vTST;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_st)
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
  chartInstance->c1_is_active_c1_Simulator_Template_FreeFlight_vTST =
    c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
    "is_active_c1_Simulator_Template_FreeFlight_vTST");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_Simulator_Template_FreeFlight_vTST(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
{
}

static void sf_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
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
  c1_chartstep_c1_Simulator_Template_FreeFlight_vTST(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_Simulator_Template_FreeFlight_vTSTMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
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
  uint32_T c1_debug_family_var_map[27];
  real_T c1_tolerance;
  real_T c1_nr;
  real_T c1_MPT_ABSTOL;
  real_T c1_minreg;
  real_T c1_Hi[400];
  real_T c1_Ki[100];
  real_T c1_abspos;
  real_T c1_ireg;
  real_T c1_sumViol;
  real_T c1_isinside;
  real_T c1_i;
  real_T c1_j;
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
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_b_ireg;
  real_T c1_d0;
  int32_T c1_i17;
  int32_T c1_b_i;
  int32_T c1_b_j;
  real_T c1_d1;
  int32_T c1_i18;
  int32_T c1_c_i;
  int32_T c1_c_ireg;
  int32_T c1_i19;
  real_T c1_b_nc;
  int32_T c1_i20;
  int32_T c1_b_ic;
  int32_T c1_c_ic;
  int32_T c1_i21;
  real_T c1_a[4];
  int32_T c1_i22;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_i23;
  int32_T c1_i24;
  real_T c1_y;
  int32_T c1_c_k;
  int32_T c1_d_k;
  int32_T c1_b_minreg;
  int32_T c1_i25;
  int32_T c1_i26;
  int32_T c1_i27;
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

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 27U, 27U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_tolerance, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_nr, 1U, c1_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_MPT_ABSTOL, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_minreg, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Hi, 4U, c1_i_sf_marshallOut,
    c1_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_Ki, 5U, c1_h_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_abspos, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ireg, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_sumViol, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_isinside, 9U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c1_F, 12U, c1_g_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_G, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nc, 14U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ic, 15U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_hx, 16U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 17U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 18U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_X, 19U, c1_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Hn, 20U, c1_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Kn, 21U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Fi, 22U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Gi, 23U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_Nc, 24U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_U, 25U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_flag_oob, 26U, c1_sf_marshallOut,
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
  for (c1_i15 = 0; c1_i15 < 400; c1_i15++) {
    c1_Hi[c1_i15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 13);
  for (c1_i16 = 0; c1_i16 < 100; c1_i16++) {
    c1_Ki[c1_i16] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 16);
  c1_abspos = 1.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 17);
  c1_ireg = 1.0;
  c1_b_ireg = 0;
  do {
    exitg1 = 0;
    if (c1_b_ireg < 107) {
      c1_ireg = 1.0 + (real_T)c1_b_ireg;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 18);
      c1_sumViol = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 19);
      c1_isinside = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 23);
      c1_d0 = c1_Nc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c1_ireg), 1, 107, 1, 0) - 1];
      c1_i17 = (int32_T)c1_d0;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c1_d0, mxDOUBLE_CLASS, c1_i17);
      c1_i = 1.0;
      c1_b_i = 0;
      while (c1_b_i <= c1_i17 - 1) {
        c1_i = 1.0 + (real_T)c1_b_i;
        CV_EML_FOR(0, 1, 1, 1);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 24);
        c1_j = 1.0;
        c1_b_j = 0;
        while (c1_b_j < 4) {
          c1_j = 1.0 + (real_T)c1_b_j;
          CV_EML_FOR(0, 1, 2, 1);
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 25);
          c1_Hi[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)
                  _SFD_INTEGER_CHECK("i", c1_i), 1, 100, 1, 0) + 100 * ((int32_T)
                  (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)
                   _SFD_INTEGER_CHECK("j", c1_j), 1, 4, 2, 0) - 1)) - 1] =
            c1_Hn[((int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)
                    _SFD_INTEGER_CHECK("abspos + i - 1", (c1_abspos + c1_i) -
                     1.0), 1, 940, 1, 0) + 940 * ((int32_T)(real_T)
                    _SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)
                     _SFD_INTEGER_CHECK("j", c1_j), 1, 4, 2, 0) - 1)) - 1];
          c1_b_j++;
          _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
        }

        CV_EML_FOR(0, 1, 2, 0);
        c1_b_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 1, 0);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 30);
      c1_d1 = c1_Nc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c1_ireg), 1, 107, 1, 0) - 1];
      c1_i18 = (int32_T)c1_d1;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c1_d1, mxDOUBLE_CLASS, c1_i18);
      c1_i = 1.0;
      c1_c_i = 0;
      while (c1_c_i <= c1_i18 - 1) {
        c1_i = 1.0 + (real_T)c1_c_i;
        CV_EML_FOR(0, 1, 3, 1);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 31);
        c1_Ki[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)
          _SFD_INTEGER_CHECK("i", c1_i), 1, 100, 1, 0) - 1] = c1_Kn[(int32_T)
          (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Kn", (int32_T)_SFD_INTEGER_CHECK(
          "abspos + i - 1", (c1_abspos + c1_i) - 1.0), 1, 940, 1, 0) - 1];
        c1_c_i++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 3, 0);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 33);
      c1_abspos += c1_Nc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Nc",
        (int32_T)_SFD_INTEGER_CHECK("ireg", c1_ireg), 1, 107, 1, 0) - 1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 35);
      c1_c_ireg = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c1_ireg), 1, 107, 1, 0) - 1;
      for (c1_i19 = 0; c1_i19 < 4; c1_i19++) {
        c1_F[c1_i19] = c1_Fi[c1_c_ireg + 107 * c1_i19];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 36);
      c1_G = c1_Gi[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Gi", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c1_ireg), 1, 107, 1, 0) - 1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 38);
      c1_nc = c1_Nc[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c1_ireg), 1, 107, 1, 0) - 1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 40);
      c1_b_nc = c1_nc;
      c1_i20 = (int32_T)c1_b_nc;
      _SFD_FOR_LOOP_VECTOR_CHECK(1.0, 1.0, c1_b_nc, mxDOUBLE_CLASS, c1_i20);
      c1_ic = 1.0;
      c1_b_ic = 0;
      while (c1_b_ic <= c1_i20 - 1) {
        c1_ic = 1.0 + (real_T)c1_b_ic;
        CV_EML_FOR(0, 1, 4, 1);
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
        c1_c_ic = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)
          _SFD_INTEGER_CHECK("ic", c1_ic), 1, 100, 1, 0) - 1;
        for (c1_i21 = 0; c1_i21 < 4; c1_i21++) {
          c1_a[c1_i21] = c1_Hi[c1_c_ic + 100 * c1_i21];
        }

        for (c1_i22 = 0; c1_i22 < 4; c1_i22++) {
          c1_b[c1_i22] = c1_X[c1_i22];
        }

        c1_eml_scalar_eg(chartInstance);
        c1_eml_scalar_eg(chartInstance);
        c1_hx = 0.0;
        for (c1_k = 1; c1_k < 5; c1_k++) {
          c1_b_k = c1_k;
          c1_hx += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_b_k), 1, 4, 1, 0) - 1] *
            c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_b_k), 1, 4, 1, 0) - 1];
        }

        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 42);
        if (CV_EML_IF(0, 1, 0, c1_hx - c1_Ki[(int32_T)(real_T)
                      _SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)
              _SFD_INTEGER_CHECK("ic", c1_ic), 1, 100, 1, 0) - 1] >
                      c1_MPT_ABSTOL)) {
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 43);
          c1_isinside = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 44);
          c1_sumViol += c1_hx - c1_Ki[(int32_T)(real_T)
            _SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)_SFD_INTEGER_CHECK("ic",
            c1_ic), 1, 100, 1, 0) - 1];
        }

        c1_b_ic++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 4, 0);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
      if (CV_EML_IF(0, 1, 1, c1_sumViol < c1_tolerance)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 49);
        c1_tolerance = c1_sumViol;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 50);
        c1_minreg = c1_ireg;
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 53);
      if (CV_EML_IF(0, 1, 2, c1_isinside == 1.0)) {
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 54);
        for (c1_i23 = 0; c1_i23 < 4; c1_i23++) {
          c1_a[c1_i23] = c1_F[c1_i23];
        }

        for (c1_i24 = 0; c1_i24 < 4; c1_i24++) {
          c1_b[c1_i24] = c1_X[c1_i24];
        }

        c1_eml_scalar_eg(chartInstance);
        c1_eml_scalar_eg(chartInstance);
        c1_y = 0.0;
        for (c1_c_k = 1; c1_c_k < 5; c1_c_k++) {
          c1_d_k = c1_c_k;
          c1_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c1_d_k), 1, 4, 1, 0) - 1] *
            c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c1_d_k), 1, 4, 1, 0) - 1];
        }

        c1_U = c1_y + c1_G;
        _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
        exitg1 = 1;
      } else {
        c1_b_ireg++;
        _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
      }
    } else {
      CV_EML_FOR(0, 1, 0, 0);
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 58);
      c1_b_minreg = (int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)
        _SFD_INTEGER_CHECK("minreg", c1_minreg), 1, 107, 1, 0) - 1;
      for (c1_i25 = 0; c1_i25 < 4; c1_i25++) {
        c1_F[c1_i25] = c1_Fi[c1_b_minreg + 107 * c1_i25];
      }

      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
      c1_G = c1_Gi[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("Gi", (int32_T)
        _SFD_INTEGER_CHECK("minreg", c1_minreg), 1, 107, 1, 0) - 1];
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 60);
      for (c1_i26 = 0; c1_i26 < 4; c1_i26++) {
        c1_a[c1_i26] = c1_F[c1_i26];
      }

      for (c1_i27 = 0; c1_i27 < 4; c1_i27++) {
        c1_b[c1_i27] = c1_X[c1_i27];
      }

      c1_eml_scalar_eg(chartInstance);
      c1_eml_scalar_eg(chartInstance);
      c1_b_y = 0.0;
      for (c1_e_k = 1; c1_e_k < 5; c1_e_k++) {
        c1_f_k = c1_e_k;
        c1_b_y += c1_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c1_f_k), 1, 4, 1, 0) - 1] *
          c1_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c1_f_k), 1, 4, 1, 0) - 1];
      }

      c1_U = c1_b_y + c1_G;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 61);
      c1_flag_oob = 1.0;
      _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 63);
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -63);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_U = c1_U;
  *c1_b_flag_oob = c1_flag_oob;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_Simulator_Template_FreeFlight_vTST
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
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
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_flag_oob, const char_T *c1_identifier)
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

static real_T c1_b_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
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
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
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
  int32_T c1_i28;
  real_T c1_b_inData[107];
  int32_T c1_i29;
  real_T c1_u[107];
  const mxArray *c1_y = NULL;
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i28 = 0; c1_i28 < 107; c1_i28++) {
    c1_b_inData[c1_i28] = (*(real_T (*)[107])c1_inData)[c1_i28];
  }

  for (c1_i29 = 0; c1_i29 < 107; c1_i29++) {
    c1_u[c1_i29] = c1_b_inData[c1_i29];
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
  int32_T c1_i30;
  int32_T c1_i31;
  int32_T c1_i32;
  real_T c1_b_inData[428];
  int32_T c1_i33;
  int32_T c1_i34;
  int32_T c1_i35;
  real_T c1_u[428];
  const mxArray *c1_y = NULL;
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i30 = 0;
  for (c1_i31 = 0; c1_i31 < 4; c1_i31++) {
    for (c1_i32 = 0; c1_i32 < 107; c1_i32++) {
      c1_b_inData[c1_i32 + c1_i30] = (*(real_T (*)[428])c1_inData)[c1_i32 +
        c1_i30];
    }

    c1_i30 += 107;
  }

  c1_i33 = 0;
  for (c1_i34 = 0; c1_i34 < 4; c1_i34++) {
    for (c1_i35 = 0; c1_i35 < 107; c1_i35++) {
      c1_u[c1_i35 + c1_i33] = c1_b_inData[c1_i35 + c1_i33];
    }

    c1_i33 += 107;
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
  int32_T c1_i36;
  real_T c1_b_inData[940];
  int32_T c1_i37;
  real_T c1_u[940];
  const mxArray *c1_y = NULL;
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i36 = 0; c1_i36 < 940; c1_i36++) {
    c1_b_inData[c1_i36] = (*(real_T (*)[940])c1_inData)[c1_i36];
  }

  for (c1_i37 = 0; c1_i37 < 940; c1_i37++) {
    c1_u[c1_i37] = c1_b_inData[c1_i37];
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
  int32_T c1_i38;
  int32_T c1_i39;
  int32_T c1_i40;
  real_T c1_b_inData[3760];
  int32_T c1_i41;
  int32_T c1_i42;
  int32_T c1_i43;
  real_T c1_u[3760];
  const mxArray *c1_y = NULL;
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i38 = 0;
  for (c1_i39 = 0; c1_i39 < 4; c1_i39++) {
    for (c1_i40 = 0; c1_i40 < 940; c1_i40++) {
      c1_b_inData[c1_i40 + c1_i38] = (*(real_T (*)[3760])c1_inData)[c1_i40 +
        c1_i38];
    }

    c1_i38 += 940;
  }

  c1_i41 = 0;
  for (c1_i42 = 0; c1_i42 < 4; c1_i42++) {
    for (c1_i43 = 0; c1_i43 < 940; c1_i43++) {
      c1_u[c1_i43 + c1_i41] = c1_b_inData[c1_i43 + c1_i41];
    }

    c1_i41 += 940;
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
  int32_T c1_i44;
  real_T c1_b_inData[4];
  int32_T c1_i45;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i44 = 0; c1_i44 < 4; c1_i44++) {
    c1_b_inData[c1_i44] = (*(real_T (*)[4])c1_inData)[c1_i44];
  }

  for (c1_i45 = 0; c1_i45 < 4; c1_i45++) {
    c1_u[c1_i45] = c1_b_inData[c1_i45];
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
  int32_T c1_i46;
  real_T c1_b_inData[4];
  int32_T c1_i47;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i46 = 0; c1_i46 < 4; c1_i46++) {
    c1_b_inData[c1_i46] = (*(real_T (*)[4])c1_inData)[c1_i46];
  }

  for (c1_i47 = 0; c1_i47 < 4; c1_i47++) {
    c1_u[c1_i47] = c1_b_inData[c1_i47];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[4])
{
  real_T c1_dv0[4];
  int32_T c1_i48;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c1_i48 = 0; c1_i48 < 4; c1_i48++) {
    c1_y[c1_i48] = c1_dv0[c1_i48];
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
  int32_T c1_i49;
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_F = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_F), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_F);
  for (c1_i49 = 0; c1_i49 < 4; c1_i49++) {
    (*(real_T (*)[4])c1_outData)[c1_i49] = c1_y[c1_i49];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i50;
  real_T c1_b_inData[100];
  int32_T c1_i51;
  real_T c1_u[100];
  const mxArray *c1_y = NULL;
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i50 = 0; c1_i50 < 100; c1_i50++) {
    c1_b_inData[c1_i50] = (*(real_T (*)[100])c1_inData)[c1_i50];
  }

  for (c1_i51 = 0; c1_i51 < 100; c1_i51++) {
    c1_u[c1_i51] = c1_b_inData[c1_i51];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 100), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[100])
{
  real_T c1_dv1[100];
  int32_T c1_i52;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 1, 100);
  for (c1_i52 = 0; c1_i52 < 100; c1_i52++) {
    c1_y[c1_i52] = c1_dv1[c1_i52];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Ki;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[100];
  int32_T c1_i53;
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_Ki = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Ki), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Ki);
  for (c1_i53 = 0; c1_i53 < 100; c1_i53++) {
    (*(real_T (*)[100])c1_outData)[c1_i53] = c1_y[c1_i53];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i54;
  int32_T c1_i55;
  int32_T c1_i56;
  real_T c1_b_inData[400];
  int32_T c1_i57;
  int32_T c1_i58;
  int32_T c1_i59;
  real_T c1_u[400];
  const mxArray *c1_y = NULL;
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i54 = 0;
  for (c1_i55 = 0; c1_i55 < 4; c1_i55++) {
    for (c1_i56 = 0; c1_i56 < 100; c1_i56++) {
      c1_b_inData[c1_i56 + c1_i54] = (*(real_T (*)[400])c1_inData)[c1_i56 +
        c1_i54];
    }

    c1_i54 += 100;
  }

  c1_i57 = 0;
  for (c1_i58 = 0; c1_i58 < 4; c1_i58++) {
    for (c1_i59 = 0; c1_i59 < 100; c1_i59++) {
      c1_u[c1_i59 + c1_i57] = c1_b_inData[c1_i59 + c1_i57];
    }

    c1_i57 += 100;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 100, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[400])
{
  real_T c1_dv2[400];
  int32_T c1_i60;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 2, 100,
                4);
  for (c1_i60 = 0; c1_i60 < 400; c1_i60++) {
    c1_y[c1_i60] = c1_dv2[c1_i60];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Hi;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[400];
  int32_T c1_i61;
  int32_T c1_i62;
  int32_T c1_i63;
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_Hi = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Hi), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Hi);
  c1_i61 = 0;
  for (c1_i62 = 0; c1_i62 < 4; c1_i62++) {
    for (c1_i63 = 0; c1_i63 < 100; c1_i63++) {
      (*(real_T (*)[400])c1_outData)[c1_i63 + c1_i61] = c1_y[c1_i63 + c1_i61];
    }

    c1_i61 += 100;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray
  *sf_c1_Simulator_Template_FreeFlight_vTST_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[26];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i64;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 26), FALSE);
  for (c1_i64 = 0; c1_i64 < 26; c1_i64++) {
    c1_r0 = &c1_info[c1_i64];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i64);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i64);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i64);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i64);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i64);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i64);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i64);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i64);
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

static void c1_round(SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct
                     *chartInstance, real_T c1_x[4], real_T c1_b_x[4])
{
  int32_T c1_i65;
  for (c1_i65 = 0; c1_i65 < 4; c1_i65++) {
    c1_b_x[c1_i65] = c1_x[c1_i65];
  }

  c1_b_round(chartInstance, c1_b_x);
}

static void c1_eml_scalar_eg
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
{
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i66;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i66, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i66;
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
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    chartInstanceVoid;
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

static uint8_T c1_g_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_Simulator_Template_FreeFlight_vTST, const char_T
   *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_Simulator_Template_FreeFlight_vTST), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Simulator_Template_FreeFlight_vTST);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_round(SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct
  *chartInstance, real_T c1_x[4])
{
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  for (c1_k = 0; c1_k < 4; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_b_x = c1_x[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_b_k), 1, 4, 1, 0) - 1];
    c1_c_x = c1_b_x;
    c1_c_x = muDoubleScalarRound(c1_c_x);
    c1_x[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", c1_b_k), 1, 4, 1, 0) - 1] = c1_c_x;
  }
}

static void init_dsm_address_info
  (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance)
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

void sf_c1_Simulator_Template_FreeFlight_vTST_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(999360599U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2811213423U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1136956415U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(801941992U);
}

mxArray *sf_c1_Simulator_Template_FreeFlight_vTST_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("aFFIXtccfeWJJRVht6VAG");
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

mxArray *sf_c1_Simulator_Template_FreeFlight_vTST_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray
  *sf_get_sim_state_info_c1_Simulator_Template_FreeFlight_vTST(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"U\",},{M[1],M[16],T\"flag_oob\",},{M[8],M[0],T\"is_active_c1_Simulator_Template_FreeFlight_vTST\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Simulator_Template_FreeFlight_vTST_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
    chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Simulator_Template_FreeFlight_vTSTMachineNumber_,
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
          init_script_number_translation
            (_Simulator_Template_FreeFlight_vTSTMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _Simulator_Template_FreeFlight_vTSTMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Simulator_Template_FreeFlight_vTSTMachineNumber_,
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
        _Simulator_Template_FreeFlight_vTSTMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "GRygl40jww5gijbmVnJ5iC";
}

static void sf_opaque_initialize_c1_Simulator_Template_FreeFlight_vTST(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c1_Simulator_Template_FreeFlight_vTST
    ((SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct*) chartInstanceVar);
  initialize_c1_Simulator_Template_FreeFlight_vTST
    ((SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_Simulator_Template_FreeFlight_vTST(void
  *chartInstanceVar)
{
  enable_c1_Simulator_Template_FreeFlight_vTST
    ((SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Simulator_Template_FreeFlight_vTST(void
  *chartInstanceVar)
{
  disable_c1_Simulator_Template_FreeFlight_vTST
    ((SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_Simulator_Template_FreeFlight_vTST(void
  *chartInstanceVar)
{
  sf_c1_Simulator_Template_FreeFlight_vTST
    ((SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c1_Simulator_Template_FreeFlight_vTST(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_Simulator_Template_FreeFlight_vTST
    ((SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c1_Simulator_Template_FreeFlight_vTST();/* state var info */
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

extern void sf_internal_set_sim_state_c1_Simulator_Template_FreeFlight_vTST
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c1_Simulator_Template_FreeFlight_vTST();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_Simulator_Template_FreeFlight_vTST
    ((SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c1_Simulator_Template_FreeFlight_vTST(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_Simulator_Template_FreeFlight_vTST(S);
}

static void sf_opaque_set_sim_state_c1_Simulator_Template_FreeFlight_vTST
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_Simulator_Template_FreeFlight_vTST(S, st);
}

static void sf_opaque_terminate_c1_Simulator_Template_FreeFlight_vTST(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Simulator_Template_FreeFlight_vTST_optimization_info();
    }

    finalize_c1_Simulator_Template_FreeFlight_vTST
      ((SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Simulator_Template_FreeFlight_vTST
    ((SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Simulator_Template_FreeFlight_vTST(SimStruct
  *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Simulator_Template_FreeFlight_vTST
      ((SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct*)
       (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_Simulator_Template_FreeFlight_vTST(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_Simulator_Template_FreeFlight_vTST_optimization_info();
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
  ssSetChecksum0(S,(2036156407U));
  ssSetChecksum1(S,(2366251842U));
  ssSetChecksum2(S,(3925141478U));
  ssSetChecksum3(S,(603148995U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_Simulator_Template_FreeFlight_vTST(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Simulator_Template_FreeFlight_vTST(SimStruct *S)
{
  SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct *)
    utMalloc(sizeof(SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_Simulator_Template_FreeFlight_vTSTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Simulator_Template_FreeFlight_vTST;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Simulator_Template_FreeFlight_vTST;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_Simulator_Template_FreeFlight_vTST;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_Simulator_Template_FreeFlight_vTST;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_Simulator_Template_FreeFlight_vTST;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Simulator_Template_FreeFlight_vTST;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Simulator_Template_FreeFlight_vTST;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Simulator_Template_FreeFlight_vTST;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Simulator_Template_FreeFlight_vTST;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c1_Simulator_Template_FreeFlight_vTST;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_Simulator_Template_FreeFlight_vTST;
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

void c1_Simulator_Template_FreeFlight_vTST_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Simulator_Template_FreeFlight_vTST(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Simulator_Template_FreeFlight_vTST(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Simulator_Template_FreeFlight_vTST(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Simulator_Template_FreeFlight_vTST_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
