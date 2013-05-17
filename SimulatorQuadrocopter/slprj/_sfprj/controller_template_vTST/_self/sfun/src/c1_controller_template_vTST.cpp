/* Include files */

#include "blascompat32.h"
#include "controller_template_vTST_sfun.h"
#include "c1_controller_template_vTST.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_vTST_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[23] = { "tolerance", "nr",
  "MPT_ABSTOL", "minreg", "Hi", "Ki", "abspos", "sumViol", "isinside", "F", "G",
  "nc", "hx", "nargin", "nargout", "X", "Hn", "Kn", "Fi", "Gi", "Nc", "U",
  "flag_oob" };

/* Function Declarations */
static void initialize_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance);
static void initialize_params_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance);
static void enable_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance);
static void disable_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance);
static void ext_mode_exec_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance);
static void set_sim_state_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance);
static void sf_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance);
static void c1_chartstep_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance);
static void initSimStructsc1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_flag_oob, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
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
static void c1_c_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4]);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_d_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[1000]);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static void c1_e_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4000]);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[18]);
static void c1_round(SFc1_controller_template_vTSTInstanceStruct *chartInstance,
                     real_T c1_x[4], real_T c1_b_x[4]);
static void c1_mrdivide(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, real_T c1_A[4], real_T c1_B, real_T c1_y[4]);
static void c1_eml_scalar_eg(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance);
static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_f_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_g_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_controller_template_vTST, const
  char_T *c1_identifier);
static uint8_T c1_h_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_round(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, real_T c1_x[4]);
static void init_dsm_address_info(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance)
{
  int32_T *c1_sfEvent;
  uint8_T *c1_is_active_c1_controller_template_vTST;
  c1_is_active_c1_controller_template_vTST = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c1_is_active_c1_controller_template_vTST = 0U;
}

static void initialize_params_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance)
{
}

static void enable_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance)
{
  c1_update_debugger_state_c1_controller_template_vTST(chartInstance);
}

static const mxArray *get_sim_state_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance)
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
  uint8_T *c1_is_active_c1_controller_template_vTST;
  c1_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_controller_template_vTST = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
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
  c1_c_hoistedGlobal = *c1_is_active_c1_controller_template_vTST;
  c1_c_u = c1_c_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  boolean_T *c1_doneDoubleBufferReInit;
  real_T *c1_U;
  real_T *c1_flag_oob;
  uint8_T *c1_is_active_c1_controller_template_vTST;
  c1_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_is_active_c1_controller_template_vTST = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c1_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_U = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
    "U");
  *c1_flag_oob = c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 1)), "flag_oob");
  *c1_is_active_c1_controller_template_vTST = c1_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_controller_template_vTST");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_controller_template_vTST(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance)
{
}

static void sf_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance)
{
  int32_T c1_i0;
  int32_T c1_i1;
  int32_T c1_i2;
  int32_T c1_i3;
  int32_T c1_i4;
  int32_T c1_i5;
  int32_T *c1_sfEvent;
  real_T *c1_U;
  real_T *c1_flag_oob;
  real_T (*c1_Nc)[334];
  real_T (*c1_Gi)[334];
  real_T (*c1_Fi)[1336];
  real_T (*c1_Kn)[2973];
  real_T (*c1_Hn)[11892];
  real_T (*c1_X)[4];
  c1_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_Nc = (real_T (*)[334])ssGetInputPortSignal(chartInstance->S, 5);
  c1_Gi = (real_T (*)[334])ssGetInputPortSignal(chartInstance->S, 4);
  c1_Fi = (real_T (*)[1336])ssGetInputPortSignal(chartInstance->S, 3);
  c1_Kn = (real_T (*)[2973])ssGetInputPortSignal(chartInstance->S, 2);
  c1_Hn = (real_T (*)[11892])ssGetInputPortSignal(chartInstance->S, 1);
  c1_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, *c1_sfEvent);
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    _SFD_DATA_RANGE_CHECK((*c1_X)[c1_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_U, 1U);
  for (c1_i1 = 0; c1_i1 < 11892; c1_i1++) {
    _SFD_DATA_RANGE_CHECK((*c1_Hn)[c1_i1], 2U);
  }

  for (c1_i2 = 0; c1_i2 < 2973; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_Kn)[c1_i2], 3U);
  }

  for (c1_i3 = 0; c1_i3 < 1336; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_Fi)[c1_i3], 4U);
  }

  for (c1_i4 = 0; c1_i4 < 334; c1_i4++) {
    _SFD_DATA_RANGE_CHECK((*c1_Gi)[c1_i4], 5U);
  }

  for (c1_i5 = 0; c1_i5 < 334; c1_i5++) {
    _SFD_DATA_RANGE_CHECK((*c1_Nc)[c1_i5], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_flag_oob, 7U);
  *c1_sfEvent = CALL_EVENT;
  c1_chartstep_c1_controller_template_vTST(chartInstance);
  sf_debug_check_for_state_inconsistency(_controller_template_vTSTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c1_chartstep_c1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance)
{
  int32_T c1_i6;
  real_T c1_X[4];
  int32_T c1_i7;
  real_T c1_Hn[11892];
  int32_T c1_i8;
  real_T c1_Kn[2973];
  int32_T c1_i9;
  real_T c1_Fi[1336];
  int32_T c1_i10;
  real_T c1_Gi[334];
  int32_T c1_i11;
  real_T c1_Nc[334];
  uint32_T c1_debug_family_var_map[23];
  real_T c1_tolerance;
  real_T c1_nr;
  real_T c1_MPT_ABSTOL;
  real_T c1_minreg;
  real_T c1_Hi[4000];
  real_T c1_Ki[1000];
  real_T c1_abspos;
  real_T c1_sumViol;
  real_T c1_isinside;
  real_T c1_F[4];
  real_T c1_G;
  real_T c1_nc;
  real_T c1_hx;
  real_T c1_nargin = 6.0;
  real_T c1_nargout = 2.0;
  real_T c1_U;
  real_T c1_flag_oob;
  int32_T c1_i12;
  real_T c1_b[4];
  int32_T c1_i13;
  int32_T c1_i14;
  real_T c1_b_b[4];
  real_T c1_dv0[4];
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  int32_T c1_ireg;
  real_T c1_b_ireg;
  real_T c1_d0;
  int32_T c1_i18;
  int32_T c1_loop_ub;
  int32_T c1_i;
  real_T c1_b_i;
  int32_T c1_j;
  real_T c1_b_j;
  real_T c1_d1;
  int32_T c1_i19;
  int32_T c1_b_loop_ub;
  int32_T c1_c_i;
  int32_T c1_c_ireg;
  int32_T c1_i20;
  int32_T c1_i21;
  int32_T c1_c_loop_ub;
  int32_T c1_ic;
  real_T c1_b_ic;
  int32_T c1_c_ic;
  int32_T c1_i22;
  real_T c1_a[4];
  int32_T c1_i23;
  int32_T c1_k;
  int32_T c1_b_k;
  int32_T c1_i24;
  int32_T c1_i25;
  real_T c1_y;
  int32_T c1_c_k;
  int32_T c1_d_k;
  int32_T c1_b_minreg;
  int32_T c1_i26;
  int32_T c1_i27;
  int32_T c1_i28;
  real_T c1_b_y;
  int32_T c1_e_k;
  int32_T c1_f_k;
  real_T *c1_b_U;
  real_T *c1_b_flag_oob;
  real_T (*c1_b_Nc)[334];
  real_T (*c1_b_Gi)[334];
  real_T (*c1_b_Fi)[1336];
  real_T (*c1_b_Kn)[2973];
  real_T (*c1_b_Hn)[11892];
  real_T (*c1_b_X)[4];
  int32_T *c1_sfEvent;
  int32_T exitg1;
  c1_b_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c1_b_Nc = (real_T (*)[334])ssGetInputPortSignal(chartInstance->S, 5);
  c1_b_Gi = (real_T (*)[334])ssGetInputPortSignal(chartInstance->S, 4);
  c1_b_Fi = (real_T (*)[1336])ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_Kn = (real_T (*)[2973])ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_Hn = (real_T (*)[11892])ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_X = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c1_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, *c1_sfEvent);
  for (c1_i6 = 0; c1_i6 < 4; c1_i6++) {
    c1_X[c1_i6] = (*c1_b_X)[c1_i6];
  }

  for (c1_i7 = 0; c1_i7 < 11892; c1_i7++) {
    c1_Hn[c1_i7] = (*c1_b_Hn)[c1_i7];
  }

  for (c1_i8 = 0; c1_i8 < 2973; c1_i8++) {
    c1_Kn[c1_i8] = (*c1_b_Kn)[c1_i8];
  }

  for (c1_i9 = 0; c1_i9 < 1336; c1_i9++) {
    c1_Fi[c1_i9] = (*c1_b_Fi)[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 334; c1_i10++) {
    c1_Gi[c1_i10] = (*c1_b_Gi)[c1_i10];
  }

  for (c1_i11 = 0; c1_i11 < 334; c1_i11++) {
    c1_Nc[c1_i11] = (*c1_b_Nc)[c1_i11];
  }

  sf_debug_symbol_scope_push_eml(0U, 23U, 23U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_tolerance, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_nr, 1U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_MPT_ABSTOL, 2U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_minreg, 3U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Hi, 4U, c1_i_sf_marshallOut,
    c1_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_Ki, 5U, c1_h_sf_marshallOut,
    c1_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_abspos, 6U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_sumViol, 7U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_isinside, 8U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c1_F, 9U, c1_g_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_G, 10U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nc, 11U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_hx, 12U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 13U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 14U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_X, 15U, c1_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_Hn, 16U, c1_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_Kn, 17U, c1_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_Fi, 18U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_Gi, 19U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c1_Nc, 20U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_U, 21U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_flag_oob, 22U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c1_sfEvent, 3);
  c1_tolerance = 1.0;
  _SFD_EML_CALL(0U, *c1_sfEvent, 4);
  c1_nr = 334.0;
  _SFD_EML_CALL(0U, *c1_sfEvent, 5);
  c1_MPT_ABSTOL = 1.0E-8;
  _SFD_EML_CALL(0U, *c1_sfEvent, 6);
  c1_minreg = 0.0;
  _SFD_EML_CALL(0U, *c1_sfEvent, 7);
  for (c1_i12 = 0; c1_i12 < 4; c1_i12++) {
    c1_b[c1_i12] = c1_X[c1_i12];
  }

  for (c1_i13 = 0; c1_i13 < 4; c1_i13++) {
    c1_b[c1_i13] *= 10000.0;
  }

  c1_b_round(chartInstance, c1_b);
  for (c1_i14 = 0; c1_i14 < 4; c1_i14++) {
    c1_b_b[c1_i14] = c1_b[c1_i14];
  }

  c1_mrdivide(chartInstance, c1_b_b, 10000.0, c1_dv0);
  for (c1_i15 = 0; c1_i15 < 4; c1_i15++) {
    c1_X[c1_i15] = c1_dv0[c1_i15];
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 9);
  c1_flag_oob = 0.0;
  _SFD_EML_CALL(0U, *c1_sfEvent, 12);
  for (c1_i16 = 0; c1_i16 < 4000; c1_i16++) {
    c1_Hi[c1_i16] = 0.0;
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 13);
  for (c1_i17 = 0; c1_i17 < 1000; c1_i17++) {
    c1_Ki[c1_i17] = 0.0;
  }

  _SFD_EML_CALL(0U, *c1_sfEvent, 16);
  c1_abspos = 1.0;
  c1_ireg = 0;
  do {
    exitg1 = 0U;
    if (c1_ireg < 334) {
      c1_b_ireg = 1.0 + (real_T)c1_ireg;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, *c1_sfEvent, 18);
      c1_sumViol = 0.0;
      _SFD_EML_CALL(0U, *c1_sfEvent, 19);
      c1_isinside = 1.0;
      c1_d0 = c1_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c1_b_ireg), 1, 334, 1, 0) - 1];
      c1_i18 = (int32_T)c1_d0;
      sf_debug_for_loop_vector_check(1.0, 1.0, c1_d0, mxDOUBLE_CLASS, c1_i18);
      c1_loop_ub = c1_i18;
      c1_i = 0;
      while (c1_i <= c1_loop_ub - 1) {
        c1_b_i = 1.0 + (real_T)c1_i;
        CV_EML_FOR(0, 1, 1, 1);
        c1_j = 0;
        while (c1_j < 4) {
          c1_b_j = 1.0 + (real_T)c1_j;
          CV_EML_FOR(0, 1, 2, 1);
          _SFD_EML_CALL(0U, *c1_sfEvent, 25);
          c1_Hi[(_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)_SFD_INTEGER_CHECK(
                   "i", c1_b_i), 1, 1000, 1, 0) + 1000 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)_SFD_INTEGER_CHECK(
                    "j", c1_b_j), 1, 4, 2, 0) - 1)) - 1] = c1_Hn
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)_SFD_INTEGER_CHECK(
                "abspos + i - 1", (c1_abspos + c1_b_i) - 1.0), 1, 2973, 1, 0) +
              2973 * (_SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)
                _SFD_INTEGER_CHECK("j", c1_b_j), 1, 4, 2, 0) - 1)) - 1];
          c1_j++;
          sf_mex_listen_for_ctrl_c(chartInstance->S);
        }

        CV_EML_FOR(0, 1, 2, 0);
        c1_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 1, 0);
      c1_d1 = c1_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c1_b_ireg), 1, 334, 1, 0) - 1];
      c1_i19 = (int32_T)c1_d1;
      sf_debug_for_loop_vector_check(1.0, 1.0, c1_d1, mxDOUBLE_CLASS, c1_i19);
      c1_b_loop_ub = c1_i19;
      c1_c_i = 0;
      while (c1_c_i <= c1_b_loop_ub - 1) {
        c1_b_i = 1.0 + (real_T)c1_c_i;
        CV_EML_FOR(0, 1, 3, 1);
        _SFD_EML_CALL(0U, *c1_sfEvent, 31);
        c1_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)_SFD_INTEGER_CHECK("i",
          c1_b_i), 1, 1000, 1, 0) - 1] = c1_Kn[_SFD_EML_ARRAY_BOUNDS_CHECK("Kn",
          (int32_T)_SFD_INTEGER_CHECK("abspos + i - 1", (c1_abspos + c1_b_i) -
          1.0), 1, 2973, 1, 0) - 1];
        c1_c_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 3, 0);
      _SFD_EML_CALL(0U, *c1_sfEvent, 33);
      c1_abspos += c1_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c1_b_ireg), 1, 334, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c1_sfEvent, 35);
      c1_c_ireg = _SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)_SFD_INTEGER_CHECK(
        "ireg", c1_b_ireg), 1, 334, 1, 0) - 1;
      for (c1_i20 = 0; c1_i20 < 4; c1_i20++) {
        c1_F[c1_i20] = c1_Fi[c1_c_ireg + 334 * c1_i20];
      }

      _SFD_EML_CALL(0U, *c1_sfEvent, 36);
      c1_G = c1_Gi[_SFD_EML_ARRAY_BOUNDS_CHECK("Gi", (int32_T)_SFD_INTEGER_CHECK
        ("ireg", c1_b_ireg), 1, 334, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c1_sfEvent, 38);
      c1_nc = c1_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c1_b_ireg), 1, 334, 1, 0) - 1];
      c1_i21 = (int32_T)c1_nc;
      sf_debug_for_loop_vector_check(1.0, 1.0, c1_nc, mxDOUBLE_CLASS, c1_i21);
      c1_c_loop_ub = c1_i21;
      c1_ic = 0;
      while (c1_ic <= c1_c_loop_ub - 1) {
        c1_b_ic = 1.0 + (real_T)c1_ic;
        CV_EML_FOR(0, 1, 4, 1);
        _SFD_EML_CALL(0U, *c1_sfEvent, 41);
        c1_c_ic = _SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)_SFD_INTEGER_CHECK(
          "ic", c1_b_ic), 1, 1000, 1, 0) - 1;
        for (c1_i22 = 0; c1_i22 < 4; c1_i22++) {
          c1_a[c1_i22] = c1_Hi[c1_c_ic + 1000 * c1_i22];
        }

        for (c1_i23 = 0; c1_i23 < 4; c1_i23++) {
          c1_b[c1_i23] = c1_X[c1_i23];
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

        _SFD_EML_CALL(0U, *c1_sfEvent, 42);
        if (CV_EML_IF(0, 1, 0, c1_hx - c1_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki",
              (int32_T)_SFD_INTEGER_CHECK("ic", c1_b_ic), 1, 1000, 1, 0) - 1] >
                      c1_MPT_ABSTOL)) {
          _SFD_EML_CALL(0U, *c1_sfEvent, 43);
          c1_isinside = 0.0;
          _SFD_EML_CALL(0U, *c1_sfEvent, 44);
          c1_sumViol += c1_hx - c1_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)
            _SFD_INTEGER_CHECK("ic", c1_b_ic), 1, 1000, 1, 0) - 1];
        }

        c1_ic++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 4, 0);
      _SFD_EML_CALL(0U, *c1_sfEvent, 48);
      if (CV_EML_IF(0, 1, 1, c1_sumViol < c1_tolerance)) {
        _SFD_EML_CALL(0U, *c1_sfEvent, 49);
        c1_tolerance = c1_sumViol;
        _SFD_EML_CALL(0U, *c1_sfEvent, 50);
        c1_minreg = c1_b_ireg;
      }

      _SFD_EML_CALL(0U, *c1_sfEvent, 53);
      if (CV_EML_IF(0, 1, 2, c1_isinside == 1.0)) {
        _SFD_EML_CALL(0U, *c1_sfEvent, 54);
        for (c1_i24 = 0; c1_i24 < 4; c1_i24++) {
          c1_a[c1_i24] = c1_F[c1_i24];
        }

        for (c1_i25 = 0; c1_i25 < 4; c1_i25++) {
          c1_b[c1_i25] = c1_X[c1_i25];
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
        exitg1 = 1U;
      } else {
        c1_ireg++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }
    } else {
      CV_EML_FOR(0, 1, 0, 0);
      _SFD_EML_CALL(0U, *c1_sfEvent, 58);
      c1_b_minreg = _SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)
        _SFD_INTEGER_CHECK("minreg", c1_minreg), 1, 334, 1, 0) - 1;
      for (c1_i26 = 0; c1_i26 < 4; c1_i26++) {
        c1_F[c1_i26] = c1_Fi[c1_b_minreg + 334 * c1_i26];
      }

      _SFD_EML_CALL(0U, *c1_sfEvent, 59);
      c1_G = c1_Gi[_SFD_EML_ARRAY_BOUNDS_CHECK("Gi", (int32_T)_SFD_INTEGER_CHECK
        ("minreg", c1_minreg), 1, 334, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c1_sfEvent, 60);
      for (c1_i27 = 0; c1_i27 < 4; c1_i27++) {
        c1_a[c1_i27] = c1_F[c1_i27];
      }

      for (c1_i28 = 0; c1_i28 < 4; c1_i28++) {
        c1_b[c1_i28] = c1_X[c1_i28];
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
      _SFD_EML_CALL(0U, *c1_sfEvent, 61);
      c1_flag_oob = 1.0;
      exitg1 = 1U;
    }
  } while (exitg1 == 0U);

  _SFD_EML_CALL(0U, *c1_sfEvent, -61);
  sf_debug_symbol_scope_pop();
  *c1_b_U = c1_U;
  *c1_b_flag_oob = c1_flag_oob;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *c1_sfEvent);
}

static void initSimStructsc1_controller_template_vTST
  (SFc1_controller_template_vTSTInstanceStruct *chartInstance)
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
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_flag_oob, const char_T *c1_identifier)
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

static real_T c1_b_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
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
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
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
  int32_T c1_i29;
  real_T c1_b_inData[334];
  int32_T c1_i30;
  real_T c1_u[334];
  const mxArray *c1_y = NULL;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i29 = 0; c1_i29 < 334; c1_i29++) {
    c1_b_inData[c1_i29] = (*(real_T (*)[334])c1_inData)[c1_i29];
  }

  for (c1_i30 = 0; c1_i30 < 334; c1_i30++) {
    c1_u[c1_i30] = c1_b_inData[c1_i30];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 334), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i31;
  int32_T c1_i32;
  int32_T c1_i33;
  real_T c1_b_inData[1336];
  int32_T c1_i34;
  int32_T c1_i35;
  int32_T c1_i36;
  real_T c1_u[1336];
  const mxArray *c1_y = NULL;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i31 = 0;
  for (c1_i32 = 0; c1_i32 < 4; c1_i32++) {
    for (c1_i33 = 0; c1_i33 < 334; c1_i33++) {
      c1_b_inData[c1_i33 + c1_i31] = (*(real_T (*)[1336])c1_inData)[c1_i33 +
        c1_i31];
    }

    c1_i31 += 334;
  }

  c1_i34 = 0;
  for (c1_i35 = 0; c1_i35 < 4; c1_i35++) {
    for (c1_i36 = 0; c1_i36 < 334; c1_i36++) {
      c1_u[c1_i36 + c1_i34] = c1_b_inData[c1_i36 + c1_i34];
    }

    c1_i34 += 334;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 334, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i37;
  real_T c1_b_inData[2973];
  int32_T c1_i38;
  real_T c1_u[2973];
  const mxArray *c1_y = NULL;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i37 = 0; c1_i37 < 2973; c1_i37++) {
    c1_b_inData[c1_i37] = (*(real_T (*)[2973])c1_inData)[c1_i37];
  }

  for (c1_i38 = 0; c1_i38 < 2973; c1_i38++) {
    c1_u[c1_i38] = c1_b_inData[c1_i38];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2973), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i39;
  int32_T c1_i40;
  int32_T c1_i41;
  real_T c1_b_inData[11892];
  int32_T c1_i42;
  int32_T c1_i43;
  int32_T c1_i44;
  real_T c1_u[11892];
  const mxArray *c1_y = NULL;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i39 = 0;
  for (c1_i40 = 0; c1_i40 < 4; c1_i40++) {
    for (c1_i41 = 0; c1_i41 < 2973; c1_i41++) {
      c1_b_inData[c1_i41 + c1_i39] = (*(real_T (*)[11892])c1_inData)[c1_i41 +
        c1_i39];
    }

    c1_i39 += 2973;
  }

  c1_i42 = 0;
  for (c1_i43 = 0; c1_i43 < 4; c1_i43++) {
    for (c1_i44 = 0; c1_i44 < 2973; c1_i44++) {
      c1_u[c1_i44 + c1_i42] = c1_b_inData[c1_i44 + c1_i42];
    }

    c1_i42 += 2973;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2973, 4),
                FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i45;
  real_T c1_b_inData[4];
  int32_T c1_i46;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i45 = 0; c1_i45 < 4; c1_i45++) {
    c1_b_inData[c1_i45] = (*(real_T (*)[4])c1_inData)[c1_i45];
  }

  for (c1_i46 = 0; c1_i46 < 4; c1_i46++) {
    c1_u[c1_i46] = c1_b_inData[c1_i46];
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
  int32_T c1_i47;
  real_T c1_b_inData[4];
  int32_T c1_i48;
  real_T c1_u[4];
  const mxArray *c1_y = NULL;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i47 = 0; c1_i47 < 4; c1_i47++) {
    c1_b_inData[c1_i47] = (*(real_T (*)[4])c1_inData)[c1_i47];
  }

  for (c1_i48 = 0; c1_i48 < 4; c1_i48++) {
    c1_u[c1_i48] = c1_b_inData[c1_i48];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 4), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_c_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4])
{
  real_T c1_dv1[4];
  int32_T c1_i49;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 2, 1, 4);
  for (c1_i49 = 0; c1_i49 < 4; c1_i49++) {
    c1_y[c1_i49] = c1_dv1[c1_i49];
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
  int32_T c1_i50;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_F = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_F), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_F);
  for (c1_i50 = 0; c1_i50 < 4; c1_i50++) {
    (*(real_T (*)[4])c1_outData)[c1_i50] = c1_y[c1_i50];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_h_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i51;
  real_T c1_b_inData[1000];
  int32_T c1_i52;
  real_T c1_u[1000];
  const mxArray *c1_y = NULL;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i51 = 0; c1_i51 < 1000; c1_i51++) {
    c1_b_inData[c1_i51] = (*(real_T (*)[1000])c1_inData)[c1_i51];
  }

  for (c1_i52 = 0; c1_i52 < 1000; c1_i52++) {
    c1_u[c1_i52] = c1_b_inData[c1_i52];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 1000), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_d_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[1000])
{
  real_T c1_dv2[1000];
  int32_T c1_i53;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv2, 1, 0, 0U, 1, 0U, 1, 1000);
  for (c1_i53 = 0; c1_i53 < 1000; c1_i53++) {
    c1_y[c1_i53] = c1_dv2[c1_i53];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Ki;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[1000];
  int32_T c1_i54;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_Ki = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Ki), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Ki);
  for (c1_i54 = 0; c1_i54 < 1000; c1_i54++) {
    (*(real_T (*)[1000])c1_outData)[c1_i54] = c1_y[c1_i54];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_i_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i55;
  int32_T c1_i56;
  int32_T c1_i57;
  real_T c1_b_inData[4000];
  int32_T c1_i58;
  int32_T c1_i59;
  int32_T c1_i60;
  real_T c1_u[4000];
  const mxArray *c1_y = NULL;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i55 = 0;
  for (c1_i56 = 0; c1_i56 < 4; c1_i56++) {
    for (c1_i57 = 0; c1_i57 < 1000; c1_i57++) {
      c1_b_inData[c1_i57 + c1_i55] = (*(real_T (*)[4000])c1_inData)[c1_i57 +
        c1_i55];
    }

    c1_i55 += 1000;
  }

  c1_i58 = 0;
  for (c1_i59 = 0; c1_i59 < 4; c1_i59++) {
    for (c1_i60 = 0; c1_i60 < 1000; c1_i60++) {
      c1_u[c1_i60 + c1_i58] = c1_b_inData[c1_i60 + c1_i58];
    }

    c1_i58 += 1000;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1000, 4),
                FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_e_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[4000])
{
  real_T c1_dv3[4000];
  int32_T c1_i61;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv3, 1, 0, 0U, 1, 0U, 2, 1000,
                4);
  for (c1_i61 = 0; c1_i61 < 4000; c1_i61++) {
    c1_y[c1_i61] = c1_dv3[c1_i61];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_Hi;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[4000];
  int32_T c1_i62;
  int32_T c1_i63;
  int32_T c1_i64;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_Hi = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_Hi), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_Hi);
  c1_i62 = 0;
  for (c1_i63 = 0; c1_i63 < 4; c1_i63++) {
    for (c1_i64 = 0; c1_i64 < 1000; c1_i64++) {
      (*(real_T (*)[4000])c1_outData)[c1_i64 + c1_i62] = c1_y[c1_i64 + c1_i62];
    }

    c1_i62 += 1000;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_controller_template_vTST_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[18];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i65;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18), FALSE);
  for (c1_i65 = 0; c1_i65 < 18; c1_i65++) {
    c1_r0 = &c1_info[c1_i65];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i65);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i65);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i65);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i65);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i65);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i65);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i65);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i65);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[18])
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
  c1_info[1].fileTimeLo = 1286818748U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c1_info[2].name = "eml_scalar_round";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c1_info[2].fileTimeLo = 1289519628U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c1_info[3].name = "eps";
  c1_info[3].dominantType = "char";
  c1_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[3].fileTimeLo = 1286818686U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[4].name = "eml_is_float_class";
  c1_info[4].dominantType = "char";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[4].fileTimeLo = 1286818782U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c1_info[5].name = "mrdivide";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[5].fileTimeLo = 1310137456U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 1289519692U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c1_info[6].name = "rdivide";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[6].fileTimeLo = 1286818844U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c1_info[7].name = "eml_div";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c1_info[7].fileTimeLo = 1305318000U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[8].name = "eml_index_class";
  c1_info[8].dominantType = "";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c1_info[8].fileTimeLo = 1286818778U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[9].name = "eml_scalar_eg";
  c1_info[9].dominantType = "double";
  c1_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[9].fileTimeLo = 1286818796U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[10].name = "eml_xdotu";
  c1_info[10].dominantType = "int32";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[10].fileTimeLo = 1299076772U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[11].name = "eml_blas_inline";
  c1_info[11].dominantType = "";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c1_info[11].fileTimeLo = 1299076768U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c1_info[12].name = "eml_xdot";
  c1_info[12].dominantType = "int32";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c1_info[12].fileTimeLo = 1299076772U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c1_info[13].name = "eml_refblas_xdot";
  c1_info[13].dominantType = "int32";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[13].fileTimeLo = 1299076772U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
  c1_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c1_info[14].name = "eml_refblas_xdotx";
  c1_info[14].dominantType = "int32";
  c1_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[14].fileTimeLo = 1299076774U;
  c1_info[14].fileTimeHi = 0U;
  c1_info[14].mFileTimeLo = 0U;
  c1_info[14].mFileTimeHi = 0U;
  c1_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[15].name = "eml_index_minus";
  c1_info[15].dominantType = "int32";
  c1_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c1_info[15].fileTimeLo = 1286818778U;
  c1_info[15].fileTimeHi = 0U;
  c1_info[15].mFileTimeLo = 0U;
  c1_info[15].mFileTimeHi = 0U;
  c1_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[16].name = "eml_index_times";
  c1_info[16].dominantType = "int32";
  c1_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c1_info[16].fileTimeLo = 1286818780U;
  c1_info[16].fileTimeHi = 0U;
  c1_info[16].mFileTimeLo = 0U;
  c1_info[16].mFileTimeHi = 0U;
  c1_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c1_info[17].name = "eml_index_plus";
  c1_info[17].dominantType = "int32";
  c1_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c1_info[17].fileTimeLo = 1286818778U;
  c1_info[17].fileTimeHi = 0U;
  c1_info[17].mFileTimeLo = 0U;
  c1_info[17].mFileTimeHi = 0U;
}

static void c1_round(SFc1_controller_template_vTSTInstanceStruct *chartInstance,
                     real_T c1_x[4], real_T c1_b_x[4])
{
  int32_T c1_i66;
  for (c1_i66 = 0; c1_i66 < 4; c1_i66++) {
    c1_b_x[c1_i66] = c1_x[c1_i66];
  }

  c1_b_round(chartInstance, c1_b_x);
}

static void c1_mrdivide(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, real_T c1_A[4], real_T c1_B, real_T c1_y[4])
{
  real_T c1_b_y;
  real_T c1_c_y;
  int32_T c1_i67;
  c1_b_y = c1_B;
  c1_c_y = c1_b_y;
  for (c1_i67 = 0; c1_i67 < 4; c1_i67++) {
    c1_y[c1_i67] = c1_A[c1_i67] / c1_c_y;
  }
}

static void c1_eml_scalar_eg(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance)
{
}

static const mxArray *c1_j_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_f_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
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
  const mxArray *c1_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c1_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_sfEvent), &c1_thisId);
  sf_mex_destroy(&c1_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_g_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_is_active_c1_controller_template_vTST, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_is_active_c1_controller_template_vTST), &c1_thisId);
  sf_mex_destroy(&c1_is_active_c1_controller_template_vTST);
  return c1_y;
}

static uint8_T c1_h_emlrt_marshallIn(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_round(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance, real_T c1_x[4])
{
  int32_T c1_k;
  real_T c1_b_k;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  for (c1_k = 0; c1_k < 4; c1_k++) {
    c1_b_k = 1.0 + (real_T)c1_k;
    c1_b_x = c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c1_b_k), 1, 4, 1, 0) - 1];
    c1_c_x = c1_b_x;
    c1_d_x = c1_c_x;
    if (muDoubleScalarAbs(c1_d_x) > 4.503599627370496E+15) {
    } else if (c1_d_x >= 0.5) {
      c1_c_x = muDoubleScalarFloor(c1_d_x + 0.5);
    } else if (c1_d_x > -0.5) {
      c1_c_x = c1_d_x * 0.0;
    } else {
      c1_c_x = muDoubleScalarCeil(c1_d_x - 0.5);
    }

    c1_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c1_b_k),
      1, 4, 1, 0) - 1] = c1_c_x;
  }
}

static void init_dsm_address_info(SFc1_controller_template_vTSTInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c1_controller_template_vTST_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(874999350U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3589267989U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3505347858U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4045174083U);
}

mxArray *sf_c1_controller_template_vTST_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("PVoFrEYjPlqc7CHIxUIiYE");
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
      pr[0] = (double)(2973);
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
      pr[0] = (double)(2973);
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
      pr[0] = (double)(334);
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
      pr[0] = (double)(334);
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
      pr[0] = (double)(334);
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

static const mxArray *sf_get_sim_state_info_c1_controller_template_vTST(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"U\",},{M[1],M[16],T\"flag_oob\",},{M[8],M[0],T\"is_active_c1_controller_template_vTST\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_controller_template_vTST_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_controller_template_vTSTInstanceStruct *chartInstance;
    chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_template_vTSTMachineNumber_,
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
          init_script_number_translation(_controller_template_vTSTMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_controller_template_vTSTMachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds
            (_controller_template_vTSTMachineNumber_,
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
            1.0,0,0,(MexFcnForType)c1_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2973;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2973;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 334;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 334;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 334;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);

        {
          real_T *c1_U;
          real_T *c1_flag_oob;
          real_T (*c1_X)[4];
          real_T (*c1_Hn)[11892];
          real_T (*c1_Kn)[2973];
          real_T (*c1_Fi)[1336];
          real_T (*c1_Gi)[334];
          real_T (*c1_Nc)[334];
          c1_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c1_Nc = (real_T (*)[334])ssGetInputPortSignal(chartInstance->S, 5);
          c1_Gi = (real_T (*)[334])ssGetInputPortSignal(chartInstance->S, 4);
          c1_Fi = (real_T (*)[1336])ssGetInputPortSignal(chartInstance->S, 3);
          c1_Kn = (real_T (*)[2973])ssGetInputPortSignal(chartInstance->S, 2);
          c1_Hn = (real_T (*)[11892])ssGetInputPortSignal(chartInstance->S, 1);
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
      sf_debug_reset_current_state_configuration
        (_controller_template_vTSTMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_controller_template_vTST_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S, infoStruct,
      1, "dworkChecksum");
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

static void sf_opaque_initialize_c1_controller_template_vTST(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc1_controller_template_vTSTInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc1_controller_template_vTSTInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_controller_template_vTST
    ((SFc1_controller_template_vTSTInstanceStruct*) chartInstanceVar);
  initialize_c1_controller_template_vTST
    ((SFc1_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_controller_template_vTST(void *chartInstanceVar)
{
  enable_c1_controller_template_vTST
    ((SFc1_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_controller_template_vTST(void *chartInstanceVar)
{
  disable_c1_controller_template_vTST
    ((SFc1_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_controller_template_vTST(void *chartInstanceVar)
{
  sf_c1_controller_template_vTST((SFc1_controller_template_vTSTInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c1_controller_template_vTST(void
  *chartInstanceVar)
{
  ext_mode_exec_c1_controller_template_vTST
    ((SFc1_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_controller_template_vTST
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_controller_template_vTST
    ((SFc1_controller_template_vTSTInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_controller_template_vTST();/* state var info */
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

extern void sf_internal_set_sim_state_c1_controller_template_vTST(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_controller_template_vTST();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_controller_template_vTST
    ((SFc1_controller_template_vTSTInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_controller_template_vTST
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_controller_template_vTST(S);
}

static void sf_opaque_set_sim_state_c1_controller_template_vTST(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_controller_template_vTST(S, st);
}

static void sf_opaque_terminate_c1_controller_template_vTST(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_controller_template_vTSTInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_controller_template_vTST
      ((SFc1_controller_template_vTSTInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_vTST_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_controller_template_vTST
    ((SFc1_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_controller_template_vTST(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_controller_template_vTST
      ((SFc1_controller_template_vTSTInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c1_controller_template_vTST_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c1_controller_template_vTST\",T\"is_active_c1_controller_template_vTST\"}}"
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

static void mdlSetWorkWidths_c1_controller_template_vTST(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_vTST_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,1,6);
      sf_mark_chart_reusable_outputs(S,infoStruct,1,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1946416840U));
  ssSetChecksum1(S,(1723484650U));
  ssSetChecksum2(S,(115163930U));
  ssSetChecksum3(S,(4259842921U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_controller_template_vTST(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_controller_template_vTST(SimStruct *S)
{
  SFc1_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc1_controller_template_vTSTInstanceStruct *)malloc(sizeof
    (SFc1_controller_template_vTSTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_controller_template_vTSTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_controller_template_vTST;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_controller_template_vTST;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_controller_template_vTST;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_controller_template_vTST;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_controller_template_vTST;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_controller_template_vTST;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_controller_template_vTST;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_controller_template_vTST;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_controller_template_vTST;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_controller_template_vTST;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_controller_template_vTST;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c1_controller_template_vTST;
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

void c1_controller_template_vTST_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_controller_template_vTST(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_controller_template_vTST(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_controller_template_vTST(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_controller_template_vTST_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
