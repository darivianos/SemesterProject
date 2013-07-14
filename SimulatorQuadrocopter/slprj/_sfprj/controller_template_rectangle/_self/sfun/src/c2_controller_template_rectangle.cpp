/* Include files */

#include "blascompat32.h"
#include "controller_template_rectangle_sfun.h"
#include "c2_controller_template_rectangle.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_rectangle_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[23] = { "tolerance", "nr",
  "MPT_ABSTOL", "minreg", "Hi", "Ki", "abspos", "sumViol", "isinside", "F", "G",
  "nc", "hx", "nargin", "nargout", "X", "Hn", "Kn", "Fi", "Gi", "Nc", "U",
  "flag_oob" };

/* Function Declarations */
static void initialize_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance);
static void initialize_params_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance);
static void enable_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance);
static void disable_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance);
static void ext_mode_exec_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance);
static void set_sim_state_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_st);
static void finalize_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance);
static void sf_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance);
static void c2_chartstep_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance);
static void initSimStructsc2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_flag_oob, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[5]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_d_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[100]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[500]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18]);
static void c2_round(SFc2_controller_template_rectangleInstanceStruct
                     *chartInstance, real_T c2_x[5], real_T c2_b_x[5]);
static void c2_mrdivide(SFc2_controller_template_rectangleInstanceStruct
  *chartInstance, real_T c2_A[5], real_T c2_B, real_T c2_y[5]);
static void c2_eml_scalar_eg(SFc2_controller_template_rectangleInstanceStruct
  *chartInstance);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_f_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_g_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_is_active_c2_controller_template_rectangle, const char_T
   *c2_identifier);
static uint8_T c2_h_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_round(SFc2_controller_template_rectangleInstanceStruct
  *chartInstance, real_T c2_x[5]);
static void init_dsm_address_info
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance)
{
  int32_T *c2_sfEvent;
  uint8_T *c2_is_active_c2_controller_template_rectangle;
  c2_is_active_c2_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c2_is_active_c2_controller_template_rectangle = 0U;
}

static void initialize_params_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void enable_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance)
{
  c2_update_debugger_state_c2_controller_template_rectangle(chartInstance);
}

static const mxArray *get_sim_state_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_c_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  real_T *c2_U;
  real_T *c2_flag_oob;
  uint8_T *c2_is_active_c2_controller_template_rectangle;
  c2_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(3), FALSE);
  c2_hoistedGlobal = *c2_U;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_flag_oob;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_is_active_c2_controller_template_rectangle;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_st)
{
  const mxArray *c2_u;
  boolean_T *c2_doneDoubleBufferReInit;
  real_T *c2_U;
  real_T *c2_flag_oob;
  uint8_T *c2_is_active_c2_controller_template_rectangle;
  c2_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_is_active_c2_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c2_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_U = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "U");
  *c2_flag_oob = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 1)), "flag_oob");
  *c2_is_active_c2_controller_template_rectangle = c2_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)),
     "is_active_c2_controller_template_rectangle");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_controller_template_rectangle(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void sf_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance)
{
  int32_T c2_i0;
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T *c2_sfEvent;
  real_T *c2_U;
  real_T *c2_flag_oob;
  real_T (*c2_Nc)[315];
  real_T (*c2_Gi)[315];
  real_T (*c2_Fi)[1575];
  real_T (*c2_Kn)[3329];
  real_T (*c2_Hn)[16645];
  real_T (*c2_X)[5];
  c2_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_Nc = (real_T (*)[315])ssGetInputPortSignal(chartInstance->S, 5);
  c2_Gi = (real_T (*)[315])ssGetInputPortSignal(chartInstance->S, 4);
  c2_Fi = (real_T (*)[1575])ssGetInputPortSignal(chartInstance->S, 3);
  c2_Kn = (real_T (*)[3329])ssGetInputPortSignal(chartInstance->S, 2);
  c2_Hn = (real_T (*)[16645])ssGetInputPortSignal(chartInstance->S, 1);
  c2_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_X = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, *c2_sfEvent);
  for (c2_i0 = 0; c2_i0 < 5; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((*c2_X)[c2_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_U, 1U);
  for (c2_i1 = 0; c2_i1 < 16645; c2_i1++) {
    _SFD_DATA_RANGE_CHECK((*c2_Hn)[c2_i1], 2U);
  }

  for (c2_i2 = 0; c2_i2 < 3329; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((*c2_Kn)[c2_i2], 3U);
  }

  for (c2_i3 = 0; c2_i3 < 1575; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((*c2_Fi)[c2_i3], 4U);
  }

  for (c2_i4 = 0; c2_i4 < 315; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*c2_Gi)[c2_i4], 5U);
  }

  for (c2_i5 = 0; c2_i5 < 315; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*c2_Nc)[c2_i5], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c2_flag_oob, 7U);
  *c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_controller_template_rectangle(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_controller_template_rectangleMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c2_chartstep_c2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance)
{
  int32_T c2_i6;
  real_T c2_X[5];
  int32_T c2_i7;
  real_T c2_Hn[16645];
  int32_T c2_i8;
  real_T c2_Kn[3329];
  int32_T c2_i9;
  real_T c2_Fi[1575];
  int32_T c2_i10;
  real_T c2_Gi[315];
  int32_T c2_i11;
  real_T c2_Nc[315];
  uint32_T c2_debug_family_var_map[23];
  real_T c2_tolerance;
  real_T c2_nr;
  real_T c2_MPT_ABSTOL;
  real_T c2_minreg;
  real_T c2_Hi[500];
  real_T c2_Ki[100];
  real_T c2_abspos;
  real_T c2_sumViol;
  real_T c2_isinside;
  real_T c2_F[5];
  real_T c2_G;
  real_T c2_nc;
  real_T c2_hx;
  real_T c2_nargin = 6.0;
  real_T c2_nargout = 2.0;
  real_T c2_U;
  real_T c2_flag_oob;
  int32_T c2_i12;
  real_T c2_b[5];
  int32_T c2_i13;
  int32_T c2_i14;
  real_T c2_b_b[5];
  real_T c2_dv0[5];
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_ireg;
  real_T c2_b_ireg;
  real_T c2_d0;
  int32_T c2_i18;
  int32_T c2_loop_ub;
  int32_T c2_i;
  real_T c2_b_i;
  int32_T c2_j;
  real_T c2_b_j;
  real_T c2_d1;
  int32_T c2_i19;
  int32_T c2_b_loop_ub;
  int32_T c2_c_i;
  int32_T c2_c_ireg;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_c_loop_ub;
  int32_T c2_ic;
  real_T c2_b_ic;
  int32_T c2_c_ic;
  int32_T c2_i22;
  real_T c2_a[5];
  int32_T c2_i23;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_i24;
  int32_T c2_i25;
  real_T c2_y;
  int32_T c2_c_k;
  int32_T c2_d_k;
  int32_T c2_b_minreg;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  real_T c2_b_y;
  int32_T c2_e_k;
  int32_T c2_f_k;
  real_T *c2_b_U;
  real_T *c2_b_flag_oob;
  real_T (*c2_b_Nc)[315];
  real_T (*c2_b_Gi)[315];
  real_T (*c2_b_Fi)[1575];
  real_T (*c2_b_Kn)[3329];
  real_T (*c2_b_Hn)[16645];
  real_T (*c2_b_X)[5];
  int32_T *c2_sfEvent;
  int32_T exitg1;
  c2_b_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_Nc = (real_T (*)[315])ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_Gi = (real_T (*)[315])ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_Fi = (real_T (*)[1575])ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_Kn = (real_T (*)[3329])ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_Hn = (real_T (*)[16645])ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_X = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
  c2_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, *c2_sfEvent);
  for (c2_i6 = 0; c2_i6 < 5; c2_i6++) {
    c2_X[c2_i6] = (*c2_b_X)[c2_i6];
  }

  for (c2_i7 = 0; c2_i7 < 16645; c2_i7++) {
    c2_Hn[c2_i7] = (*c2_b_Hn)[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 3329; c2_i8++) {
    c2_Kn[c2_i8] = (*c2_b_Kn)[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 1575; c2_i9++) {
    c2_Fi[c2_i9] = (*c2_b_Fi)[c2_i9];
  }

  for (c2_i10 = 0; c2_i10 < 315; c2_i10++) {
    c2_Gi[c2_i10] = (*c2_b_Gi)[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 315; c2_i11++) {
    c2_Nc[c2_i11] = (*c2_b_Nc)[c2_i11];
  }

  sf_debug_symbol_scope_push_eml(0U, 23U, 23U, c2_debug_family_names,
    c2_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c2_tolerance, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c2_nr, 1U, c2_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_MPT_ABSTOL, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_minreg, 3U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Hi, 4U, c2_i_sf_marshallOut,
    c2_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_Ki, 5U, c2_h_sf_marshallOut,
    c2_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_abspos, 6U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_sumViol, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_isinside, 8U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c2_F, 9U, c2_g_sf_marshallOut,
    c2_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_G, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nc, 11U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_hx, 12U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargin, 13U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_nargout, 14U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c2_X, 15U, c2_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_Hn, 16U, c2_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_Kn, 17U, c2_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_Fi, 18U, c2_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_Gi, 19U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c2_Nc, 20U, c2_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c2_U, 21U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c2_flag_oob, 22U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c2_sfEvent, 3);
  c2_tolerance = 1.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 4);
  c2_nr = 315.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 5);
  c2_MPT_ABSTOL = 1.0E-8;
  _SFD_EML_CALL(0U, *c2_sfEvent, 6);
  c2_minreg = 0.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 7);
  for (c2_i12 = 0; c2_i12 < 5; c2_i12++) {
    c2_b[c2_i12] = c2_X[c2_i12];
  }

  for (c2_i13 = 0; c2_i13 < 5; c2_i13++) {
    c2_b[c2_i13] *= 10000.0;
  }

  c2_b_round(chartInstance, c2_b);
  for (c2_i14 = 0; c2_i14 < 5; c2_i14++) {
    c2_b_b[c2_i14] = c2_b[c2_i14];
  }

  c2_mrdivide(chartInstance, c2_b_b, 10000.0, c2_dv0);
  for (c2_i15 = 0; c2_i15 < 5; c2_i15++) {
    c2_X[c2_i15] = c2_dv0[c2_i15];
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 9);
  c2_flag_oob = 0.0;
  _SFD_EML_CALL(0U, *c2_sfEvent, 12);
  for (c2_i16 = 0; c2_i16 < 500; c2_i16++) {
    c2_Hi[c2_i16] = 0.0;
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 13);
  for (c2_i17 = 0; c2_i17 < 100; c2_i17++) {
    c2_Ki[c2_i17] = 0.0;
  }

  _SFD_EML_CALL(0U, *c2_sfEvent, 16);
  c2_abspos = 1.0;
  c2_ireg = 0;
  do {
    exitg1 = 0U;
    if (c2_ireg < 315) {
      c2_b_ireg = 1.0 + (real_T)c2_ireg;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, *c2_sfEvent, 18);
      c2_sumViol = 0.0;
      _SFD_EML_CALL(0U, *c2_sfEvent, 19);
      c2_isinside = 1.0;
      c2_d0 = c2_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c2_b_ireg), 1, 315, 1, 0) - 1];
      c2_i18 = (int32_T)c2_d0;
      sf_debug_for_loop_vector_check(1.0, 1.0, c2_d0, mxDOUBLE_CLASS, c2_i18);
      c2_loop_ub = c2_i18;
      c2_i = 0;
      while (c2_i <= c2_loop_ub - 1) {
        c2_b_i = 1.0 + (real_T)c2_i;
        CV_EML_FOR(0, 1, 1, 1);
        c2_j = 0;
        while (c2_j < 5) {
          c2_b_j = 1.0 + (real_T)c2_j;
          CV_EML_FOR(0, 1, 2, 1);
          _SFD_EML_CALL(0U, *c2_sfEvent, 25);
          c2_Hi[(_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)_SFD_INTEGER_CHECK(
                   "i", c2_b_i), 1, 100, 1, 0) + 100 *
                 (_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)_SFD_INTEGER_CHECK(
                    "j", c2_b_j), 1, 5, 2, 0) - 1)) - 1] = c2_Hn
            [(_SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)_SFD_INTEGER_CHECK(
                "abspos + i - 1", (c2_abspos + c2_b_i) - 1.0), 1, 3329, 1, 0) +
              3329 * (_SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)
                _SFD_INTEGER_CHECK("j", c2_b_j), 1, 5, 2, 0) - 1)) - 1];
          c2_j++;
          sf_mex_listen_for_ctrl_c(chartInstance->S);
        }

        CV_EML_FOR(0, 1, 2, 0);
        c2_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 1, 0);
      c2_d1 = c2_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c2_b_ireg), 1, 315, 1, 0) - 1];
      c2_i19 = (int32_T)c2_d1;
      sf_debug_for_loop_vector_check(1.0, 1.0, c2_d1, mxDOUBLE_CLASS, c2_i19);
      c2_b_loop_ub = c2_i19;
      c2_c_i = 0;
      while (c2_c_i <= c2_b_loop_ub - 1) {
        c2_b_i = 1.0 + (real_T)c2_c_i;
        CV_EML_FOR(0, 1, 3, 1);
        _SFD_EML_CALL(0U, *c2_sfEvent, 31);
        c2_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)_SFD_INTEGER_CHECK("i",
          c2_b_i), 1, 100, 1, 0) - 1] = c2_Kn[_SFD_EML_ARRAY_BOUNDS_CHECK("Kn",
          (int32_T)_SFD_INTEGER_CHECK("abspos + i - 1", (c2_abspos + c2_b_i) -
          1.0), 1, 3329, 1, 0) - 1];
        c2_c_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 3, 0);
      _SFD_EML_CALL(0U, *c2_sfEvent, 33);
      c2_abspos += c2_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c2_b_ireg), 1, 315, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c2_sfEvent, 35);
      c2_c_ireg = _SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)_SFD_INTEGER_CHECK(
        "ireg", c2_b_ireg), 1, 315, 1, 0) - 1;
      for (c2_i20 = 0; c2_i20 < 5; c2_i20++) {
        c2_F[c2_i20] = c2_Fi[c2_c_ireg + 315 * c2_i20];
      }

      _SFD_EML_CALL(0U, *c2_sfEvent, 36);
      c2_G = c2_Gi[_SFD_EML_ARRAY_BOUNDS_CHECK("Gi", (int32_T)_SFD_INTEGER_CHECK
        ("ireg", c2_b_ireg), 1, 315, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c2_sfEvent, 38);
      c2_nc = c2_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c2_b_ireg), 1, 315, 1, 0) - 1];
      c2_i21 = (int32_T)c2_nc;
      sf_debug_for_loop_vector_check(1.0, 1.0, c2_nc, mxDOUBLE_CLASS, c2_i21);
      c2_c_loop_ub = c2_i21;
      c2_ic = 0;
      while (c2_ic <= c2_c_loop_ub - 1) {
        c2_b_ic = 1.0 + (real_T)c2_ic;
        CV_EML_FOR(0, 1, 4, 1);
        _SFD_EML_CALL(0U, *c2_sfEvent, 41);
        c2_c_ic = _SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)_SFD_INTEGER_CHECK(
          "ic", c2_b_ic), 1, 100, 1, 0) - 1;
        for (c2_i22 = 0; c2_i22 < 5; c2_i22++) {
          c2_a[c2_i22] = c2_Hi[c2_c_ic + 100 * c2_i22];
        }

        for (c2_i23 = 0; c2_i23 < 5; c2_i23++) {
          c2_b[c2_i23] = c2_X[c2_i23];
        }

        c2_eml_scalar_eg(chartInstance);
        c2_eml_scalar_eg(chartInstance);
        c2_hx = 0.0;
        for (c2_k = 1; c2_k < 6; c2_k++) {
          c2_b_k = c2_k;
          c2_hx += c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 5, 1, 0) - 1] *
            c2_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 5, 1, 0) - 1];
        }

        _SFD_EML_CALL(0U, *c2_sfEvent, 42);
        if (CV_EML_IF(0, 1, 0, c2_hx - c2_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki",
              (int32_T)_SFD_INTEGER_CHECK("ic", c2_b_ic), 1, 100, 1, 0) - 1] >
                      c2_MPT_ABSTOL)) {
          _SFD_EML_CALL(0U, *c2_sfEvent, 43);
          c2_isinside = 0.0;
          _SFD_EML_CALL(0U, *c2_sfEvent, 44);
          c2_sumViol += c2_hx - c2_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)
            _SFD_INTEGER_CHECK("ic", c2_b_ic), 1, 100, 1, 0) - 1];
        }

        c2_ic++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 4, 0);
      _SFD_EML_CALL(0U, *c2_sfEvent, 48);
      if (CV_EML_IF(0, 1, 1, c2_sumViol < c2_tolerance)) {
        _SFD_EML_CALL(0U, *c2_sfEvent, 49);
        c2_tolerance = c2_sumViol;
        _SFD_EML_CALL(0U, *c2_sfEvent, 50);
        c2_minreg = c2_b_ireg;
      }

      _SFD_EML_CALL(0U, *c2_sfEvent, 53);
      if (CV_EML_IF(0, 1, 2, c2_isinside == 1.0)) {
        _SFD_EML_CALL(0U, *c2_sfEvent, 54);
        for (c2_i24 = 0; c2_i24 < 5; c2_i24++) {
          c2_a[c2_i24] = c2_F[c2_i24];
        }

        for (c2_i25 = 0; c2_i25 < 5; c2_i25++) {
          c2_b[c2_i25] = c2_X[c2_i25];
        }

        c2_eml_scalar_eg(chartInstance);
        c2_eml_scalar_eg(chartInstance);
        c2_y = 0.0;
        for (c2_c_k = 1; c2_c_k < 6; c2_c_k++) {
          c2_d_k = c2_c_k;
          c2_y += c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_d_k), 1, 5, 1, 0) - 1] *
            c2_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_d_k), 1, 5, 1, 0) - 1];
        }

        c2_U = c2_y + c2_G;
        exitg1 = 1U;
      } else {
        c2_ireg++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }
    } else {
      CV_EML_FOR(0, 1, 0, 0);
      _SFD_EML_CALL(0U, *c2_sfEvent, 58);
      c2_b_minreg = _SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)
        _SFD_INTEGER_CHECK("minreg", c2_minreg), 1, 315, 1, 0) - 1;
      for (c2_i26 = 0; c2_i26 < 5; c2_i26++) {
        c2_F[c2_i26] = c2_Fi[c2_b_minreg + 315 * c2_i26];
      }

      _SFD_EML_CALL(0U, *c2_sfEvent, 59);
      c2_G = c2_Gi[_SFD_EML_ARRAY_BOUNDS_CHECK("Gi", (int32_T)_SFD_INTEGER_CHECK
        ("minreg", c2_minreg), 1, 315, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c2_sfEvent, 60);
      for (c2_i27 = 0; c2_i27 < 5; c2_i27++) {
        c2_a[c2_i27] = c2_F[c2_i27];
      }

      for (c2_i28 = 0; c2_i28 < 5; c2_i28++) {
        c2_b[c2_i28] = c2_X[c2_i28];
      }

      c2_eml_scalar_eg(chartInstance);
      c2_eml_scalar_eg(chartInstance);
      c2_b_y = 0.0;
      for (c2_e_k = 1; c2_e_k < 6; c2_e_k++) {
        c2_f_k = c2_e_k;
        c2_b_y += c2_a[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_f_k), 1, 5, 1, 0) - 1] *
          c2_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_f_k), 1, 5, 1, 0) - 1];
      }

      c2_U = c2_b_y + c2_G;
      _SFD_EML_CALL(0U, *c2_sfEvent, 61);
      c2_flag_oob = 1.0;
      exitg1 = 1U;
    }
  } while (exitg1 == 0U);

  _SFD_EML_CALL(0U, *c2_sfEvent, -61);
  sf_debug_symbol_scope_pop();
  *c2_b_U = c2_U;
  *c2_b_flag_oob = c2_flag_oob;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *c2_sfEvent);
}

static void initSimStructsc2_controller_template_rectangle
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_flag_oob, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_flag_oob),
    &c2_thisId);
  sf_mex_destroy(&c2_flag_oob);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d2;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d2, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_flag_oob;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_flag_oob = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_flag_oob),
    &c2_thisId);
  sf_mex_destroy(&c2_flag_oob);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i29;
  real_T c2_b_inData[315];
  int32_T c2_i30;
  real_T c2_u[315];
  const mxArray *c2_y = NULL;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i29 = 0; c2_i29 < 315; c2_i29++) {
    c2_b_inData[c2_i29] = (*(real_T (*)[315])c2_inData)[c2_i29];
  }

  for (c2_i30 = 0; c2_i30 < 315; c2_i30++) {
    c2_u[c2_i30] = c2_b_inData[c2_i30];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 315), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  real_T c2_b_inData[1575];
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  real_T c2_u[1575];
  const mxArray *c2_y = NULL;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i31 = 0;
  for (c2_i32 = 0; c2_i32 < 5; c2_i32++) {
    for (c2_i33 = 0; c2_i33 < 315; c2_i33++) {
      c2_b_inData[c2_i33 + c2_i31] = (*(real_T (*)[1575])c2_inData)[c2_i33 +
        c2_i31];
    }

    c2_i31 += 315;
  }

  c2_i34 = 0;
  for (c2_i35 = 0; c2_i35 < 5; c2_i35++) {
    for (c2_i36 = 0; c2_i36 < 315; c2_i36++) {
      c2_u[c2_i36 + c2_i34] = c2_b_inData[c2_i36 + c2_i34];
    }

    c2_i34 += 315;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 315, 5), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i37;
  real_T c2_b_inData[3329];
  int32_T c2_i38;
  real_T c2_u[3329];
  const mxArray *c2_y = NULL;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i37 = 0; c2_i37 < 3329; c2_i37++) {
    c2_b_inData[c2_i37] = (*(real_T (*)[3329])c2_inData)[c2_i37];
  }

  for (c2_i38 = 0; c2_i38 < 3329; c2_i38++) {
    c2_u[c2_i38] = c2_b_inData[c2_i38];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3329), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i39;
  int32_T c2_i40;
  int32_T c2_i41;
  static real_T c2_b_inData[16645];
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  real_T c2_u[16645];
  const mxArray *c2_y = NULL;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i39 = 0;
  for (c2_i40 = 0; c2_i40 < 5; c2_i40++) {
    for (c2_i41 = 0; c2_i41 < 3329; c2_i41++) {
      c2_b_inData[c2_i41 + c2_i39] = (*(real_T (*)[16645])c2_inData)[c2_i41 +
        c2_i39];
    }

    c2_i39 += 3329;
  }

  c2_i42 = 0;
  for (c2_i43 = 0; c2_i43 < 5; c2_i43++) {
    for (c2_i44 = 0; c2_i44 < 3329; c2_i44++) {
      c2_u[c2_i44 + c2_i42] = c2_b_inData[c2_i44 + c2_i42];
    }

    c2_i42 += 3329;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 3329, 5),
                FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i45;
  real_T c2_b_inData[5];
  int32_T c2_i46;
  real_T c2_u[5];
  const mxArray *c2_y = NULL;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i45 = 0; c2_i45 < 5; c2_i45++) {
    c2_b_inData[c2_i45] = (*(real_T (*)[5])c2_inData)[c2_i45];
  }

  for (c2_i46 = 0; c2_i46 < 5; c2_i46++) {
    c2_u[c2_i46] = c2_b_inData[c2_i46];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i47;
  real_T c2_b_inData[5];
  int32_T c2_i48;
  real_T c2_u[5];
  const mxArray *c2_y = NULL;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i47 = 0; c2_i47 < 5; c2_i47++) {
    c2_b_inData[c2_i47] = (*(real_T (*)[5])c2_inData)[c2_i47];
  }

  for (c2_i48 = 0; c2_i48 < 5; c2_i48++) {
    c2_u[c2_i48] = c2_b_inData[c2_i48];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 5), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[5])
{
  real_T c2_dv1[5];
  int32_T c2_i49;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 1, 5);
  for (c2_i49 = 0; c2_i49 < 5; c2_i49++) {
    c2_y[c2_i49] = c2_dv1[c2_i49];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_F;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[5];
  int32_T c2_i50;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_F = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_F), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_F);
  for (c2_i50 = 0; c2_i50 < 5; c2_i50++) {
    (*(real_T (*)[5])c2_outData)[c2_i50] = c2_y[c2_i50];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i51;
  real_T c2_b_inData[100];
  int32_T c2_i52;
  real_T c2_u[100];
  const mxArray *c2_y = NULL;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i51 = 0; c2_i51 < 100; c2_i51++) {
    c2_b_inData[c2_i51] = (*(real_T (*)[100])c2_inData)[c2_i51];
  }

  for (c2_i52 = 0; c2_i52 < 100; c2_i52++) {
    c2_u[c2_i52] = c2_b_inData[c2_i52];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 100), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_d_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[100])
{
  real_T c2_dv2[100];
  int32_T c2_i53;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv2, 1, 0, 0U, 1, 0U, 1, 100);
  for (c2_i53 = 0; c2_i53 < 100; c2_i53++) {
    c2_y[c2_i53] = c2_dv2[c2_i53];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Ki;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[100];
  int32_T c2_i54;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_Ki = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Ki), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Ki);
  for (c2_i54 = 0; c2_i54 < 100; c2_i54++) {
    (*(real_T (*)[100])c2_outData)[c2_i54] = c2_y[c2_i54];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i55;
  int32_T c2_i56;
  int32_T c2_i57;
  real_T c2_b_inData[500];
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  real_T c2_u[500];
  const mxArray *c2_y = NULL;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i55 = 0;
  for (c2_i56 = 0; c2_i56 < 5; c2_i56++) {
    for (c2_i57 = 0; c2_i57 < 100; c2_i57++) {
      c2_b_inData[c2_i57 + c2_i55] = (*(real_T (*)[500])c2_inData)[c2_i57 +
        c2_i55];
    }

    c2_i55 += 100;
  }

  c2_i58 = 0;
  for (c2_i59 = 0; c2_i59 < 5; c2_i59++) {
    for (c2_i60 = 0; c2_i60 < 100; c2_i60++) {
      c2_u[c2_i60 + c2_i58] = c2_b_inData[c2_i60 + c2_i58];
    }

    c2_i58 += 100;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 100, 5), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[500])
{
  real_T c2_dv3[500];
  int32_T c2_i61;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv3, 1, 0, 0U, 1, 0U, 2, 100,
                5);
  for (c2_i61 = 0; c2_i61 < 500; c2_i61++) {
    c2_y[c2_i61] = c2_dv3[c2_i61];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_Hi;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[500];
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_Hi = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_Hi), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_Hi);
  c2_i62 = 0;
  for (c2_i63 = 0; c2_i63 < 5; c2_i63++) {
    for (c2_i64 = 0; c2_i64 < 100; c2_i64++) {
      (*(real_T (*)[500])c2_outData)[c2_i64 + c2_i62] = c2_y[c2_i64 + c2_i62];
    }

    c2_i62 += 100;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray
  *sf_c2_controller_template_rectangle_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[18];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i65;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18), FALSE);
  for (c2_i65 = 0; c2_i65 < 18; c2_i65++) {
    c2_r0 = &c2_info[c2_i65];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i65);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i65);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i65);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i65);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i65);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i65);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i65);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i65);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18])
{
  c2_info[0].context = "";
  c2_info[0].name = "mtimes";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[0].fileTimeLo = 1289519692U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "round";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c2_info[1].fileTimeLo = 1286818748U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  c2_info[2].name = "eml_scalar_round";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c2_info[2].fileTimeLo = 1289519628U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c2_info[3].name = "eps";
  c2_info[3].dominantType = "char";
  c2_info[3].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[3].fileTimeLo = 1286818686U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[4].name = "eml_is_float_class";
  c2_info[4].dominantType = "char";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c2_info[4].fileTimeLo = 1286818782U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  c2_info[5].name = "mrdivide";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[5].fileTimeLo = 1310137456U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 1289519692U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c2_info[6].name = "rdivide";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].fileTimeLo = 1286818844U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[7].name = "eml_div";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[7].fileTimeLo = 1305318000U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[8].name = "eml_index_class";
  c2_info[8].dominantType = "";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[8].fileTimeLo = 1286818778U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[9].name = "eml_scalar_eg";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[9].fileTimeLo = 1286818796U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[10].name = "eml_xdotu";
  c2_info[10].dominantType = "int32";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c2_info[10].fileTimeLo = 1299076772U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c2_info[11].name = "eml_blas_inline";
  c2_info[11].dominantType = "";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c2_info[11].fileTimeLo = 1299076768U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c2_info[12].name = "eml_xdot";
  c2_info[12].dominantType = "int32";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c2_info[12].fileTimeLo = 1299076772U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c2_info[13].name = "eml_refblas_xdot";
  c2_info[13].dominantType = "int32";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c2_info[13].fileTimeLo = 1299076772U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c2_info[14].name = "eml_refblas_xdotx";
  c2_info[14].dominantType = "int32";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[14].fileTimeLo = 1299076774U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[15].name = "eml_index_minus";
  c2_info[15].dominantType = "int32";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c2_info[15].fileTimeLo = 1286818778U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[16].name = "eml_index_times";
  c2_info[16].dominantType = "int32";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c2_info[16].fileTimeLo = 1286818780U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c2_info[17].name = "eml_index_plus";
  c2_info[17].dominantType = "int32";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[17].fileTimeLo = 1286818778U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
}

static void c2_round(SFc2_controller_template_rectangleInstanceStruct
                     *chartInstance, real_T c2_x[5], real_T c2_b_x[5])
{
  int32_T c2_i66;
  for (c2_i66 = 0; c2_i66 < 5; c2_i66++) {
    c2_b_x[c2_i66] = c2_x[c2_i66];
  }

  c2_b_round(chartInstance, c2_b_x);
}

static void c2_mrdivide(SFc2_controller_template_rectangleInstanceStruct
  *chartInstance, real_T c2_A[5], real_T c2_B, real_T c2_y[5])
{
  real_T c2_b_y;
  real_T c2_c_y;
  int32_T c2_i67;
  c2_b_y = c2_B;
  c2_c_y = c2_b_y;
  for (c2_i67 = 0; c2_i67 < 5; c2_i67++) {
    c2_y[c2_i67] = c2_A[c2_i67] / c2_c_y;
  }
}

static void c2_eml_scalar_eg(SFc2_controller_template_rectangleInstanceStruct
  *chartInstance)
{
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_f_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i68;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i68, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i68;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c2_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_sfEvent), &c2_thisId);
  sf_mex_destroy(&c2_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_g_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_is_active_c2_controller_template_rectangle, const char_T
   *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_is_active_c2_controller_template_rectangle), &c2_thisId);
  sf_mex_destroy(&c2_is_active_c2_controller_template_rectangle);
  return c2_y;
}

static uint8_T c2_h_emlrt_marshallIn
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_round(SFc2_controller_template_rectangleInstanceStruct
  *chartInstance, real_T c2_x[5])
{
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  for (c2_k = 0; c2_k < 5; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_b_x = c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c2_b_k), 1, 5, 1, 0) - 1];
    c2_c_x = c2_b_x;
    c2_d_x = c2_c_x;
    if (muDoubleScalarAbs(c2_d_x) > 4.503599627370496E+15) {
    } else if (c2_d_x >= 0.5) {
      c2_c_x = muDoubleScalarFloor(c2_d_x + 0.5);
    } else if (c2_d_x > -0.5) {
      c2_c_x = c2_d_x * 0.0;
    } else {
      c2_c_x = muDoubleScalarCeil(c2_d_x - 0.5);
    }

    c2_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c2_b_k),
      1, 5, 1, 0) - 1] = c2_c_x;
  }
}

static void init_dsm_address_info
  (SFc2_controller_template_rectangleInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c2_controller_template_rectangle_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(660700983U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3459814977U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(299792141U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2283835443U);
}

mxArray *sf_c2_controller_template_rectangle_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("OfQPLFr0kbwC0mwT0OLDeF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
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
      pr[0] = (double)(3329);
      pr[1] = (double)(5);
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
      pr[0] = (double)(3329);
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
      pr[0] = (double)(315);
      pr[1] = (double)(5);
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
      pr[0] = (double)(315);
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
      pr[0] = (double)(315);
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

static const mxArray *sf_get_sim_state_info_c2_controller_template_rectangle
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"U\",},{M[1],M[16],T\"flag_oob\",},{M[8],M[0],T\"is_active_c2_controller_template_rectangle\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_controller_template_rectangle_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_controller_template_rectangleInstanceStruct *chartInstance;
    chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_template_rectangleMachineNumber_,
           2,
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
            (_controller_template_rectangleMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_controller_template_rectangleMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_controller_template_rectangleMachineNumber_,
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
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3329;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3329;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 315;
          dimVector[1]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 315;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 315;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_U;
          real_T *c2_flag_oob;
          real_T (*c2_X)[5];
          real_T (*c2_Hn)[16645];
          real_T (*c2_Kn)[3329];
          real_T (*c2_Fi)[1575];
          real_T (*c2_Gi)[315];
          real_T (*c2_Nc)[315];
          c2_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_Nc = (real_T (*)[315])ssGetInputPortSignal(chartInstance->S, 5);
          c2_Gi = (real_T (*)[315])ssGetInputPortSignal(chartInstance->S, 4);
          c2_Fi = (real_T (*)[1575])ssGetInputPortSignal(chartInstance->S, 3);
          c2_Kn = (real_T (*)[3329])ssGetInputPortSignal(chartInstance->S, 2);
          c2_Hn = (real_T (*)[16645])ssGetInputPortSignal(chartInstance->S, 1);
          c2_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_X = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c2_X);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_U);
          _SFD_SET_DATA_VALUE_PTR(2U, *c2_Hn);
          _SFD_SET_DATA_VALUE_PTR(3U, *c2_Kn);
          _SFD_SET_DATA_VALUE_PTR(4U, *c2_Fi);
          _SFD_SET_DATA_VALUE_PTR(5U, *c2_Gi);
          _SFD_SET_DATA_VALUE_PTR(6U, *c2_Nc);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_flag_oob);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_controller_template_rectangleMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_controller_template_rectangle_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S, infoStruct,
      2, "dworkChecksum");
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

static void sf_opaque_initialize_c2_controller_template_rectangle(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc2_controller_template_rectangleInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc2_controller_template_rectangleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_controller_template_rectangle
    ((SFc2_controller_template_rectangleInstanceStruct*) chartInstanceVar);
  initialize_c2_controller_template_rectangle
    ((SFc2_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_controller_template_rectangle(void
  *chartInstanceVar)
{
  enable_c2_controller_template_rectangle
    ((SFc2_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_controller_template_rectangle(void
  *chartInstanceVar)
{
  disable_c2_controller_template_rectangle
    ((SFc2_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_controller_template_rectangle(void
  *chartInstanceVar)
{
  sf_c2_controller_template_rectangle
    ((SFc2_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c2_controller_template_rectangle(void
  *chartInstanceVar)
{
  ext_mode_exec_c2_controller_template_rectangle
    ((SFc2_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_controller_template_rectangle
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_controller_template_rectangle
    ((SFc2_controller_template_rectangleInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_controller_template_rectangle();/* state var info */
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

extern void sf_internal_set_sim_state_c2_controller_template_rectangle(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_controller_template_rectangle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_controller_template_rectangle
    ((SFc2_controller_template_rectangleInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_controller_template_rectangle
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c2_controller_template_rectangle(S);
}

static void sf_opaque_set_sim_state_c2_controller_template_rectangle(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c2_controller_template_rectangle(S, st);
}

static void sf_opaque_terminate_c2_controller_template_rectangle(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_controller_template_rectangleInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_controller_template_rectangle
      ((SFc2_controller_template_rectangleInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_rectangle_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_controller_template_rectangle
    ((SFc2_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_controller_template_rectangle(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_controller_template_rectangle
      ((SFc2_controller_template_rectangleInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c2_controller_template_rectangle_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c2_controller_template_rectangle\",T\"is_active_c2_controller_template_rectangle\"}}"
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

static void mdlSetWorkWidths_c2_controller_template_rectangle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_rectangle_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,2,6);
      sf_mark_chart_reusable_outputs(S,infoStruct,2,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2555518325U));
  ssSetChecksum1(S,(281213126U));
  ssSetChecksum2(S,(2718056598U));
  ssSetChecksum3(S,(3606045713U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_controller_template_rectangle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_controller_template_rectangle(SimStruct *S)
{
  SFc2_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc2_controller_template_rectangleInstanceStruct *)malloc
    (sizeof(SFc2_controller_template_rectangleInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc2_controller_template_rectangleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_controller_template_rectangle;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_controller_template_rectangle;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_controller_template_rectangle;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c2_controller_template_rectangle;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_controller_template_rectangle;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_controller_template_rectangle;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_controller_template_rectangle;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_controller_template_rectangle;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_controller_template_rectangle;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_controller_template_rectangle;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_controller_template_rectangle;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c2_controller_template_rectangle;
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

void c2_controller_template_rectangle_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_controller_template_rectangle(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_controller_template_rectangle(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_controller_template_rectangle(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_controller_template_rectangle_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
