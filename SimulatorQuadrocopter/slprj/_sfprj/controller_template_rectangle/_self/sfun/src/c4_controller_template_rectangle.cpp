/* Include files */

#include "blascompat32.h"
#include "controller_template_rectangle_sfun.h"
#include "c4_controller_template_rectangle.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_rectangle_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[24] = { "tolerance", "nr",
  "MPT_ABSTOL", "minreg", "Hi", "Ki", "abspos", "sumViol", "isinside", "j", "F",
  "G", "nc", "hx", "nargin", "nargout", "X", "Hn", "Kn", "Fi", "Gi", "Nc", "U",
  "flag_oob" };

/* Function Declarations */
static void initialize_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance);
static void initialize_params_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance);
static void enable_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance);
static void disable_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance);
static void ext_mode_exec_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance);
static void set_sim_state_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_st);
static void finalize_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance);
static void sf_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance);
static void c4_chartstep_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance);
static void initSimStructsc4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_flag_oob, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[100]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_d_emlrt_marshallIn
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_e_emlrt_marshallIn
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_is_active_c4_controller_template_rectangle, const char_T
   *c4_identifier);
static uint8_T c4_f_emlrt_marshallIn
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance)
{
  int32_T *c4_sfEvent;
  uint8_T *c4_is_active_c4_controller_template_rectangle;
  c4_is_active_c4_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c4_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c4_is_active_c4_controller_template_rectangle = 0U;
}

static void initialize_params_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void enable_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance)
{
  c4_update_debugger_state_c4_controller_template_rectangle(chartInstance);
}

static const mxArray *get_sim_state_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  uint8_T c4_c_hoistedGlobal;
  uint8_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T *c4_U;
  real_T *c4_flag_oob;
  uint8_T *c4_is_active_c4_controller_template_rectangle;
  c4_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_is_active_c4_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(3), FALSE);
  c4_hoistedGlobal = *c4_U;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_flag_oob;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *c4_is_active_c4_controller_template_rectangle;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_st)
{
  const mxArray *c4_u;
  boolean_T *c4_doneDoubleBufferReInit;
  real_T *c4_U;
  real_T *c4_flag_oob;
  uint8_T *c4_is_active_c4_controller_template_rectangle;
  c4_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_is_active_c4_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c4_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  *c4_U = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)),
    "U");
  *c4_flag_oob = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 1)), "flag_oob");
  *c4_is_active_c4_controller_template_rectangle = c4_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)),
     "is_active_c4_controller_template_rectangle");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_controller_template_rectangle(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void sf_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance)
{
  int32_T c4_i0;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T *c4_sfEvent;
  real_T *c4_X;
  real_T *c4_U;
  real_T *c4_flag_oob;
  real_T (*c4_Nc)[3];
  real_T (*c4_Gi)[3];
  real_T (*c4_Fi)[3];
  real_T (*c4_Kn)[6];
  real_T (*c4_Hn)[6];
  c4_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_Nc = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c4_Gi = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c4_Fi = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c4_Kn = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c4_Hn = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c4_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_X = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, *c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_X, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_U, 1U);
  for (c4_i0 = 0; c4_i0 < 6; c4_i0++) {
    _SFD_DATA_RANGE_CHECK((*c4_Hn)[c4_i0], 2U);
  }

  for (c4_i1 = 0; c4_i1 < 6; c4_i1++) {
    _SFD_DATA_RANGE_CHECK((*c4_Kn)[c4_i1], 3U);
  }

  for (c4_i2 = 0; c4_i2 < 3; c4_i2++) {
    _SFD_DATA_RANGE_CHECK((*c4_Fi)[c4_i2], 4U);
  }

  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    _SFD_DATA_RANGE_CHECK((*c4_Gi)[c4_i3], 5U);
  }

  for (c4_i4 = 0; c4_i4 < 3; c4_i4++) {
    _SFD_DATA_RANGE_CHECK((*c4_Nc)[c4_i4], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c4_flag_oob, 7U);
  *c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_controller_template_rectangle(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_controller_template_rectangleMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c4_chartstep_c4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_X;
  int32_T c4_i5;
  real_T c4_Hn[6];
  int32_T c4_i6;
  real_T c4_Kn[6];
  int32_T c4_i7;
  real_T c4_Fi[3];
  int32_T c4_i8;
  real_T c4_Gi[3];
  int32_T c4_i9;
  real_T c4_Nc[3];
  uint32_T c4_debug_family_var_map[24];
  real_T c4_tolerance;
  real_T c4_nr;
  real_T c4_MPT_ABSTOL;
  real_T c4_minreg;
  real_T c4_Hi[100];
  real_T c4_Ki[100];
  real_T c4_abspos;
  real_T c4_sumViol;
  real_T c4_isinside;
  real_T c4_j;
  real_T c4_F;
  real_T c4_G;
  real_T c4_nc;
  real_T c4_hx;
  real_T c4_nargin = 6.0;
  real_T c4_nargout = 2.0;
  real_T c4_U;
  real_T c4_flag_oob;
  real_T c4_b;
  real_T c4_y;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_A;
  real_T c4_d_x;
  real_T c4_e_x;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_ireg;
  real_T c4_b_ireg;
  real_T c4_d0;
  int32_T c4_i12;
  int32_T c4_loop_ub;
  int32_T c4_i;
  real_T c4_b_i;
  real_T c4_d1;
  int32_T c4_i13;
  int32_T c4_b_loop_ub;
  int32_T c4_c_i;
  int32_T c4_i14;
  int32_T c4_c_loop_ub;
  int32_T c4_ic;
  real_T c4_b_ic;
  real_T c4_a;
  real_T c4_b_b;
  real_T c4_b_a;
  real_T c4_c_b;
  real_T c4_b_y;
  real_T c4_c_a;
  real_T c4_d_b;
  real_T c4_c_y;
  real_T *c4_b_flag_oob;
  real_T *c4_b_U;
  real_T *c4_b_X;
  real_T (*c4_b_Nc)[3];
  real_T (*c4_b_Gi)[3];
  real_T (*c4_b_Fi)[3];
  real_T (*c4_b_Kn)[6];
  real_T (*c4_b_Hn)[6];
  int32_T *c4_sfEvent;
  int32_T exitg1;
  c4_b_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_Nc = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
  c4_b_Gi = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c4_b_Fi = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c4_b_Kn = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_Hn = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_X = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c4_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, *c4_sfEvent);
  c4_hoistedGlobal = *c4_b_X;
  c4_X = c4_hoistedGlobal;
  for (c4_i5 = 0; c4_i5 < 6; c4_i5++) {
    c4_Hn[c4_i5] = (*c4_b_Hn)[c4_i5];
  }

  for (c4_i6 = 0; c4_i6 < 6; c4_i6++) {
    c4_Kn[c4_i6] = (*c4_b_Kn)[c4_i6];
  }

  for (c4_i7 = 0; c4_i7 < 3; c4_i7++) {
    c4_Fi[c4_i7] = (*c4_b_Fi)[c4_i7];
  }

  for (c4_i8 = 0; c4_i8 < 3; c4_i8++) {
    c4_Gi[c4_i8] = (*c4_b_Gi)[c4_i8];
  }

  for (c4_i9 = 0; c4_i9 < 3; c4_i9++) {
    c4_Nc[c4_i9] = (*c4_b_Nc)[c4_i9];
  }

  sf_debug_symbol_scope_push_eml(0U, 24U, 24U, c4_debug_family_names,
    c4_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c4_tolerance, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_nr, 1U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_MPT_ABSTOL, 2U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_minreg, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_Hi, 4U, c4_d_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c4_Ki, 5U, c4_d_sf_marshallOut,
    c4_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_abspos, 6U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_sumViol, 7U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_isinside, 8U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_j, 9U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_F, 10U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_G, 11U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nc, 12U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_hx, 13U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargin, 14U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_nargout, 15U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c4_X, 16U, c4_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c4_Hn, 17U, c4_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c4_Kn, 18U, c4_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c4_Fi, 19U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c4_Gi, 20U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c4_Nc, 21U, c4_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c4_U, 22U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c4_flag_oob, 23U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c4_sfEvent, 3);
  c4_tolerance = 1.0;
  _SFD_EML_CALL(0U, *c4_sfEvent, 4);
  c4_nr = 3.0;
  _SFD_EML_CALL(0U, *c4_sfEvent, 5);
  c4_MPT_ABSTOL = 1.0E-8;
  _SFD_EML_CALL(0U, *c4_sfEvent, 6);
  c4_minreg = 0.0;
  _SFD_EML_CALL(0U, *c4_sfEvent, 7);
  c4_b = c4_X;
  c4_y = 10000.0 * c4_b;
  c4_x = c4_y;
  c4_b_x = c4_x;
  c4_c_x = c4_b_x;
  if (muDoubleScalarAbs(c4_c_x) > 4.503599627370496E+15) {
  } else if (c4_c_x >= 0.5) {
    c4_b_x = muDoubleScalarFloor(c4_c_x + 0.5);
  } else if (c4_c_x > -0.5) {
    c4_b_x = c4_c_x * 0.0;
  } else {
    c4_b_x = muDoubleScalarCeil(c4_c_x - 0.5);
  }

  c4_A = c4_b_x;
  c4_d_x = c4_A;
  c4_e_x = c4_d_x;
  c4_X = c4_e_x / 10000.0;
  _SFD_EML_CALL(0U, *c4_sfEvent, 9);
  c4_flag_oob = 0.0;
  _SFD_EML_CALL(0U, *c4_sfEvent, 12);
  for (c4_i10 = 0; c4_i10 < 100; c4_i10++) {
    c4_Hi[c4_i10] = 0.0;
  }

  _SFD_EML_CALL(0U, *c4_sfEvent, 13);
  for (c4_i11 = 0; c4_i11 < 100; c4_i11++) {
    c4_Ki[c4_i11] = 0.0;
  }

  _SFD_EML_CALL(0U, *c4_sfEvent, 16);
  c4_abspos = 1.0;
  c4_ireg = 0;
  do {
    exitg1 = 0U;
    if (c4_ireg < 3) {
      c4_b_ireg = 1.0 + (real_T)c4_ireg;
      CV_EML_FOR(0, 1, 0, 1);
      _SFD_EML_CALL(0U, *c4_sfEvent, 18);
      c4_sumViol = 0.0;
      _SFD_EML_CALL(0U, *c4_sfEvent, 19);
      c4_isinside = 1.0;
      c4_d0 = c4_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c4_b_ireg), 1, 3, 1, 0) - 1];
      c4_i12 = (int32_T)c4_d0;
      sf_debug_for_loop_vector_check(1.0, 1.0, c4_d0, mxDOUBLE_CLASS, c4_i12);
      c4_loop_ub = c4_i12;
      c4_i = 0;
      while (c4_i <= c4_loop_ub - 1) {
        c4_b_i = 1.0 + (real_T)c4_i;
        CV_EML_FOR(0, 1, 1, 1);
        c4_j = 1.0;
        CV_EML_FOR(0, 1, 2, 1);
        _SFD_EML_CALL(0U, *c4_sfEvent, 25);
        c4_Hi[_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)_SFD_INTEGER_CHECK("i",
          c4_b_i), 1, 100, 1, 0) - 1] = c4_Hn[_SFD_EML_ARRAY_BOUNDS_CHECK("Hn",
          (int32_T)_SFD_INTEGER_CHECK("abspos + i - 1", (c4_abspos + c4_b_i) -
          1.0), 1, 6, 1, 0) - 1];
        CV_EML_FOR(0, 1, 2, 0);
        c4_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 1, 0);
      c4_d1 = c4_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c4_b_ireg), 1, 3, 1, 0) - 1];
      c4_i13 = (int32_T)c4_d1;
      sf_debug_for_loop_vector_check(1.0, 1.0, c4_d1, mxDOUBLE_CLASS, c4_i13);
      c4_b_loop_ub = c4_i13;
      c4_c_i = 0;
      while (c4_c_i <= c4_b_loop_ub - 1) {
        c4_b_i = 1.0 + (real_T)c4_c_i;
        CV_EML_FOR(0, 1, 3, 1);
        _SFD_EML_CALL(0U, *c4_sfEvent, 31);
        c4_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)_SFD_INTEGER_CHECK("i",
          c4_b_i), 1, 100, 1, 0) - 1] = c4_Kn[_SFD_EML_ARRAY_BOUNDS_CHECK("Kn",
          (int32_T)_SFD_INTEGER_CHECK("abspos + i - 1", (c4_abspos + c4_b_i) -
          1.0), 1, 6, 1, 0) - 1];
        c4_c_i++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 3, 0);
      _SFD_EML_CALL(0U, *c4_sfEvent, 33);
      c4_abspos += c4_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c4_b_ireg), 1, 3, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c4_sfEvent, 35);
      c4_F = c4_Fi[_SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)_SFD_INTEGER_CHECK
        ("ireg", c4_b_ireg), 1, 3, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c4_sfEvent, 36);
      c4_G = c4_Gi[_SFD_EML_ARRAY_BOUNDS_CHECK("Gi", (int32_T)_SFD_INTEGER_CHECK
        ("ireg", c4_b_ireg), 1, 3, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c4_sfEvent, 38);
      c4_nc = c4_Nc[_SFD_EML_ARRAY_BOUNDS_CHECK("Nc", (int32_T)
        _SFD_INTEGER_CHECK("ireg", c4_b_ireg), 1, 3, 1, 0) - 1];
      c4_i14 = (int32_T)c4_nc;
      sf_debug_for_loop_vector_check(1.0, 1.0, c4_nc, mxDOUBLE_CLASS, c4_i14);
      c4_c_loop_ub = c4_i14;
      c4_ic = 0;
      while (c4_ic <= c4_c_loop_ub - 1) {
        c4_b_ic = 1.0 + (real_T)c4_ic;
        CV_EML_FOR(0, 1, 4, 1);
        _SFD_EML_CALL(0U, *c4_sfEvent, 41);
        c4_a = c4_Hi[_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)
          _SFD_INTEGER_CHECK("ic", c4_b_ic), 1, 100, 1, 0) - 1];
        c4_b_b = c4_X;
        c4_hx = c4_a * c4_b_b;
        _SFD_EML_CALL(0U, *c4_sfEvent, 42);
        if (CV_EML_IF(0, 1, 0, c4_hx - c4_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki",
              (int32_T)_SFD_INTEGER_CHECK("ic", c4_b_ic), 1, 100, 1, 0) - 1] >
                      c4_MPT_ABSTOL)) {
          _SFD_EML_CALL(0U, *c4_sfEvent, 43);
          c4_isinside = 0.0;
          _SFD_EML_CALL(0U, *c4_sfEvent, 44);
          c4_sumViol += c4_hx - c4_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)
            _SFD_INTEGER_CHECK("ic", c4_b_ic), 1, 100, 1, 0) - 1];
        }

        c4_ic++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_EML_FOR(0, 1, 4, 0);
      _SFD_EML_CALL(0U, *c4_sfEvent, 48);
      if (CV_EML_IF(0, 1, 1, c4_sumViol < c4_tolerance)) {
        _SFD_EML_CALL(0U, *c4_sfEvent, 49);
        c4_tolerance = c4_sumViol;
        _SFD_EML_CALL(0U, *c4_sfEvent, 50);
        c4_minreg = c4_b_ireg;
      }

      _SFD_EML_CALL(0U, *c4_sfEvent, 53);
      if (CV_EML_IF(0, 1, 2, c4_isinside == 1.0)) {
        _SFD_EML_CALL(0U, *c4_sfEvent, 54);
        c4_b_a = c4_F;
        c4_c_b = c4_X;
        c4_b_y = c4_b_a * c4_c_b;
        c4_U = c4_b_y + c4_G;
        exitg1 = 1U;
      } else {
        c4_ireg++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }
    } else {
      CV_EML_FOR(0, 1, 0, 0);
      _SFD_EML_CALL(0U, *c4_sfEvent, 58);
      c4_F = c4_Fi[_SFD_EML_ARRAY_BOUNDS_CHECK("Fi", (int32_T)_SFD_INTEGER_CHECK
        ("minreg", c4_minreg), 1, 3, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c4_sfEvent, 59);
      c4_G = c4_Gi[_SFD_EML_ARRAY_BOUNDS_CHECK("Gi", (int32_T)_SFD_INTEGER_CHECK
        ("minreg", c4_minreg), 1, 3, 1, 0) - 1];
      _SFD_EML_CALL(0U, *c4_sfEvent, 60);
      c4_c_a = c4_F;
      c4_d_b = c4_X;
      c4_c_y = c4_c_a * c4_d_b;
      c4_U = c4_c_y + c4_G;
      _SFD_EML_CALL(0U, *c4_sfEvent, 61);
      c4_flag_oob = 1.0;
      exitg1 = 1U;
    }
  } while (exitg1 == 0U);

  _SFD_EML_CALL(0U, *c4_sfEvent, -61);
  sf_debug_symbol_scope_pop();
  *c4_b_U = c4_U;
  *c4_b_flag_oob = c4_flag_oob;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *c4_sfEvent);
}

static void initSimStructsc4_controller_template_rectangle
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc4_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_flag_oob, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_flag_oob),
    &c4_thisId);
  sf_mex_destroy(&c4_flag_oob);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d2;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d2, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d2;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_flag_oob;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc4_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c4_flag_oob = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_flag_oob),
    &c4_thisId);
  sf_mex_destroy(&c4_flag_oob);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i15;
  real_T c4_b_inData[3];
  int32_T c4_i16;
  real_T c4_u[3];
  const mxArray *c4_y = NULL;
  SFc4_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc4_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i15 = 0; c4_i15 < 3; c4_i15++) {
    c4_b_inData[c4_i15] = (*(real_T (*)[3])c4_inData)[c4_i15];
  }

  for (c4_i16 = 0; c4_i16 < 3; c4_i16++) {
    c4_u[c4_i16] = c4_b_inData[c4_i16];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i17;
  real_T c4_b_inData[6];
  int32_T c4_i18;
  real_T c4_u[6];
  const mxArray *c4_y = NULL;
  SFc4_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc4_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i17 = 0; c4_i17 < 6; c4_i17++) {
    c4_b_inData[c4_i17] = (*(real_T (*)[6])c4_inData)[c4_i17];
  }

  for (c4_i18 = 0; c4_i18 < 6; c4_i18++) {
    c4_u[c4_i18] = c4_b_inData[c4_i18];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i19;
  real_T c4_b_inData[100];
  int32_T c4_i20;
  real_T c4_u[100];
  const mxArray *c4_y = NULL;
  SFc4_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc4_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i19 = 0; c4_i19 < 100; c4_i19++) {
    c4_b_inData[c4_i19] = (*(real_T (*)[100])c4_inData)[c4_i19];
  }

  for (c4_i20 = 0; c4_i20 < 100; c4_i20++) {
    c4_u[c4_i20] = c4_b_inData[c4_i20];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 100), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, real_T c4_y[100])
{
  real_T c4_dv0[100];
  int32_T c4_i21;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv0, 1, 0, 0U, 1, 0U, 1, 100);
  for (c4_i21 = 0; c4_i21 < 100; c4_i21++) {
    c4_y[c4_i21] = c4_dv0[c4_i21];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_Ki;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[100];
  int32_T c4_i22;
  SFc4_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc4_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c4_Ki = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_Ki), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_Ki);
  for (c4_i22 = 0; c4_i22 < 100; c4_i22++) {
    (*(real_T (*)[100])c4_outData)[c4_i22] = c4_y[c4_i22];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray
  *sf_c4_controller_template_rectangle_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[8];
  c4_ResolvedFunctionInfo (*c4_b_info)[8];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i23;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[8])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "mtimes";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[0].fileTimeLo = 1289519692U;
  (*c4_b_info)[0].fileTimeHi = 0U;
  (*c4_b_info)[0].mFileTimeLo = 0U;
  (*c4_b_info)[0].mFileTimeHi = 0U;
  (*c4_b_info)[1].context = "";
  (*c4_b_info)[1].name = "round";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c4_b_info)[1].fileTimeLo = 1286818748U;
  (*c4_b_info)[1].fileTimeHi = 0U;
  (*c4_b_info)[1].mFileTimeLo = 0U;
  (*c4_b_info)[1].mFileTimeHi = 0U;
  (*c4_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c4_b_info)[2].name = "eml_scalar_round";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  (*c4_b_info)[2].fileTimeLo = 1289519628U;
  (*c4_b_info)[2].fileTimeHi = 0U;
  (*c4_b_info)[2].mFileTimeLo = 0U;
  (*c4_b_info)[2].mFileTimeHi = 0U;
  (*c4_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  (*c4_b_info)[3].name = "eps";
  (*c4_b_info)[3].dominantType = "char";
  (*c4_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c4_b_info)[3].fileTimeLo = 1286818686U;
  (*c4_b_info)[3].fileTimeHi = 0U;
  (*c4_b_info)[3].mFileTimeLo = 0U;
  (*c4_b_info)[3].mFileTimeHi = 0U;
  (*c4_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c4_b_info)[4].name = "eml_is_float_class";
  (*c4_b_info)[4].dominantType = "char";
  (*c4_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  (*c4_b_info)[4].fileTimeLo = 1286818782U;
  (*c4_b_info)[4].fileTimeHi = 0U;
  (*c4_b_info)[4].mFileTimeLo = 0U;
  (*c4_b_info)[4].mFileTimeHi = 0U;
  (*c4_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  (*c4_b_info)[5].name = "mrdivide";
  (*c4_b_info)[5].dominantType = "double";
  (*c4_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[5].fileTimeLo = 1310137456U;
  (*c4_b_info)[5].fileTimeHi = 0U;
  (*c4_b_info)[5].mFileTimeLo = 1289519692U;
  (*c4_b_info)[5].mFileTimeHi = 0U;
  (*c4_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c4_b_info)[6].name = "rdivide";
  (*c4_b_info)[6].dominantType = "double";
  (*c4_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[6].fileTimeLo = 1286818844U;
  (*c4_b_info)[6].fileTimeHi = 0U;
  (*c4_b_info)[6].mFileTimeLo = 0U;
  (*c4_b_info)[6].mFileTimeHi = 0U;
  (*c4_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c4_b_info)[7].name = "eml_div";
  (*c4_b_info)[7].dominantType = "double";
  (*c4_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c4_b_info)[7].fileTimeLo = 1305318000U;
  (*c4_b_info)[7].fileTimeHi = 0U;
  (*c4_b_info)[7].mFileTimeLo = 0U;
  (*c4_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c4_i23 = 0; c4_i23 < 8; c4_i23++) {
    c4_r0 = &c4_info[c4_i23];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i23);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i23);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc4_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_d_emlrt_marshallIn
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i24;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i24, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i24;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc4_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c4_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_sfEvent), &c4_thisId);
  sf_mex_destroy(&c4_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_e_emlrt_marshallIn
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_is_active_c4_controller_template_rectangle, const char_T
   *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_is_active_c4_controller_template_rectangle), &c4_thisId);
  sf_mex_destroy(&c4_is_active_c4_controller_template_rectangle);
  return c4_y;
}

static uint8_T c4_f_emlrt_marshallIn
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info
  (SFc4_controller_template_rectangleInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c4_controller_template_rectangle_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2177246627U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2660597307U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(791179663U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2544525083U);
}

mxArray *sf_c4_controller_template_rectangle_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("gAP4uN982wErpTxp6hgytC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      pr[0] = (double)(6);
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
      pr[0] = (double)(6);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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

static const mxArray *sf_get_sim_state_info_c4_controller_template_rectangle
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"U\",},{M[1],M[16],T\"flag_oob\",},{M[8],M[0],T\"is_active_c4_controller_template_rectangle\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_controller_template_rectangle_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_controller_template_rectangleInstanceStruct *chartInstance;
    chartInstance = (SFc4_controller_template_rectangleInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_template_rectangleMachineNumber_,
           4,
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

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          real_T *c4_X;
          real_T *c4_U;
          real_T *c4_flag_oob;
          real_T (*c4_Hn)[6];
          real_T (*c4_Kn)[6];
          real_T (*c4_Fi)[3];
          real_T (*c4_Gi)[3];
          real_T (*c4_Nc)[3];
          c4_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c4_Nc = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 5);
          c4_Gi = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c4_Fi = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c4_Kn = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
          c4_Hn = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 1);
          c4_U = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_X = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_X);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_U);
          _SFD_SET_DATA_VALUE_PTR(2U, *c4_Hn);
          _SFD_SET_DATA_VALUE_PTR(3U, *c4_Kn);
          _SFD_SET_DATA_VALUE_PTR(4U, *c4_Fi);
          _SFD_SET_DATA_VALUE_PTR(5U, *c4_Gi);
          _SFD_SET_DATA_VALUE_PTR(6U, *c4_Nc);
          _SFD_SET_DATA_VALUE_PTR(7U, c4_flag_oob);
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
      4, "dworkChecksum");
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

static void sf_opaque_initialize_c4_controller_template_rectangle(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc4_controller_template_rectangleInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc4_controller_template_rectangleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_controller_template_rectangle
    ((SFc4_controller_template_rectangleInstanceStruct*) chartInstanceVar);
  initialize_c4_controller_template_rectangle
    ((SFc4_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_controller_template_rectangle(void
  *chartInstanceVar)
{
  enable_c4_controller_template_rectangle
    ((SFc4_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_controller_template_rectangle(void
  *chartInstanceVar)
{
  disable_c4_controller_template_rectangle
    ((SFc4_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_controller_template_rectangle(void
  *chartInstanceVar)
{
  sf_c4_controller_template_rectangle
    ((SFc4_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c4_controller_template_rectangle(void
  *chartInstanceVar)
{
  ext_mode_exec_c4_controller_template_rectangle
    ((SFc4_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_controller_template_rectangle
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_controller_template_rectangle
    ((SFc4_controller_template_rectangleInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_controller_template_rectangle();/* state var info */
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

extern void sf_internal_set_sim_state_c4_controller_template_rectangle(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_controller_template_rectangle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_controller_template_rectangle
    ((SFc4_controller_template_rectangleInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_controller_template_rectangle
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c4_controller_template_rectangle(S);
}

static void sf_opaque_set_sim_state_c4_controller_template_rectangle(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c4_controller_template_rectangle(S, st);
}

static void sf_opaque_terminate_c4_controller_template_rectangle(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_controller_template_rectangleInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c4_controller_template_rectangle
      ((SFc4_controller_template_rectangleInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_rectangle_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_controller_template_rectangle
    ((SFc4_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_controller_template_rectangle(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_controller_template_rectangle
      ((SFc4_controller_template_rectangleInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c4_controller_template_rectangle_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c4_controller_template_rectangle\",T\"is_active_c4_controller_template_rectangle\"}}"
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

static void mdlSetWorkWidths_c4_controller_template_rectangle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_rectangle_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,4,6);
      sf_mark_chart_reusable_outputs(S,infoStruct,4,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3674907601U));
  ssSetChecksum1(S,(545694514U));
  ssSetChecksum2(S,(260744476U));
  ssSetChecksum3(S,(808048242U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_controller_template_rectangle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_controller_template_rectangle(SimStruct *S)
{
  SFc4_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc4_controller_template_rectangleInstanceStruct *)malloc
    (sizeof(SFc4_controller_template_rectangleInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc4_controller_template_rectangleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_controller_template_rectangle;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_controller_template_rectangle;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_controller_template_rectangle;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_controller_template_rectangle;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_controller_template_rectangle;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_controller_template_rectangle;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_controller_template_rectangle;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_controller_template_rectangle;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_controller_template_rectangle;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_controller_template_rectangle;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_controller_template_rectangle;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c4_controller_template_rectangle;
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

void c4_controller_template_rectangle_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_controller_template_rectangle(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_controller_template_rectangle(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_controller_template_rectangle(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_controller_template_rectangle_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
