/* Include files */

#include "blascompat32.h"
#include "Hquad_control_LIB_MPC_sfun.h"
#include "c19_Hquad_control_LIB_MPC.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hquad_control_LIB_MPC_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c19_debug_family_names[7] = { "pred_horizon", "X_ref_temp",
  "nargin", "nargout", "x_ref", "x_dot_ref", "X_ref" };

/* Function Declarations */
static void initialize_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initialize_params_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void enable_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void disable_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c19_update_debugger_state_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void ext_mode_exec_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void set_sim_state_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray
   *c19_st);
static void finalize_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void sf_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initSimStructsc19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber);
static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c19_X_ref, const char_T *c19_identifier, real_T
  c19_y[93]);
static void c19_b_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId,
  real_T c19_y[93]);
static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static real_T c19_c_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static void c19_d_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId,
  real_T c19_y[93]);
static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static const mxArray *c19_d_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData);
static int32_T c19_e_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void c19_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData);
static uint8_T c19_f_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c19_is_active_c19_Hquad_control_LIB_MPC, const
  char_T *c19_identifier);
static uint8_T c19_g_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId);
static void init_dsm_address_info(SFc19_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T *c19_sfEvent;
  uint8_T *c19_is_active_c19_Hquad_control_LIB_MPC;
  c19_is_active_c19_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c19_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c19_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c19_is_active_c19_Hquad_control_LIB_MPC = 0U;
}

static void initialize_params_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void enable_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c19_update_debugger_state_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  c19_update_debugger_state_c19_Hquad_control_LIB_MPC(chartInstance);
}

static const mxArray *get_sim_state_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  const mxArray *c19_st;
  const mxArray *c19_y = NULL;
  int32_T c19_i0;
  real_T c19_u[93];
  const mxArray *c19_b_y = NULL;
  uint8_T c19_hoistedGlobal;
  uint8_T c19_b_u;
  const mxArray *c19_c_y = NULL;
  uint8_T *c19_is_active_c19_Hquad_control_LIB_MPC;
  real_T (*c19_X_ref)[93];
  c19_X_ref = (real_T (*)[93])ssGetOutputPortSignal(chartInstance->S, 1);
  c19_is_active_c19_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c19_st = NULL;
  c19_st = NULL;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_createcellarray(2), FALSE);
  for (c19_i0 = 0; c19_i0 < 93; c19_i0++) {
    c19_u[c19_i0] = (*c19_X_ref)[c19_i0];
  }

  c19_b_y = NULL;
  sf_mex_assign(&c19_b_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 1, 93), FALSE);
  sf_mex_setcell(c19_y, 0, c19_b_y);
  c19_hoistedGlobal = *c19_is_active_c19_Hquad_control_LIB_MPC;
  c19_b_u = c19_hoistedGlobal;
  c19_c_y = NULL;
  sf_mex_assign(&c19_c_y, sf_mex_create("y", &c19_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c19_y, 1, c19_c_y);
  sf_mex_assign(&c19_st, c19_y, FALSE);
  return c19_st;
}

static void set_sim_state_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray
   *c19_st)
{
  const mxArray *c19_u;
  real_T c19_dv0[93];
  int32_T c19_i1;
  boolean_T *c19_doneDoubleBufferReInit;
  uint8_T *c19_is_active_c19_Hquad_control_LIB_MPC;
  real_T (*c19_X_ref)[93];
  c19_X_ref = (real_T (*)[93])ssGetOutputPortSignal(chartInstance->S, 1);
  c19_is_active_c19_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c19_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c19_doneDoubleBufferReInit = TRUE;
  c19_u = sf_mex_dup(c19_st);
  c19_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 0)),
                       "X_ref", c19_dv0);
  for (c19_i1 = 0; c19_i1 < 93; c19_i1++) {
    (*c19_X_ref)[c19_i1] = c19_dv0[c19_i1];
  }

  *c19_is_active_c19_Hquad_control_LIB_MPC = c19_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c19_u, 1)),
     "is_active_c19_Hquad_control_LIB_MPC");
  sf_mex_destroy(&c19_u);
  c19_update_debugger_state_c19_Hquad_control_LIB_MPC(chartInstance);
  sf_mex_destroy(&c19_st);
}

static void finalize_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void sf_c19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T c19_i2;
  real_T c19_hoistedGlobal;
  real_T c19_b_hoistedGlobal;
  real_T c19_x_ref;
  real_T c19_x_dot_ref;
  uint32_T c19_debug_family_var_map[7];
  real_T c19_pred_horizon;
  real_T c19_X_ref_temp[93];
  real_T c19_nargin = 2.0;
  real_T c19_nargout = 1.0;
  real_T c19_X_ref[93];
  real_T c19_a;
  int32_T c19_i3;
  real_T c19_y[31];
  real_T c19_b_a;
  int32_T c19_i4;
  real_T c19_b_y[31];
  int32_T c19_i5;
  int32_T c19_i6;
  int32_T c19_i7;
  int32_T c19_i8;
  int32_T c19_i9;
  int32_T c19_i10;
  int32_T c19_i11;
  real_T c19_x[93];
  int32_T c19_k;
  int32_T c19_b_k;
  real_T c19_c_y[93];
  int32_T c19_i12;
  int32_T c19_i13;
  int32_T *c19_sfEvent;
  real_T *c19_b_x_ref;
  real_T *c19_b_x_dot_ref;
  real_T (*c19_b_X_ref)[93];
  c19_b_X_ref = (real_T (*)[93])ssGetOutputPortSignal(chartInstance->S, 1);
  c19_b_x_dot_ref = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c19_b_x_ref = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c19_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, *c19_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c19_b_x_ref, 0U);
  _SFD_DATA_RANGE_CHECK(*c19_b_x_dot_ref, 1U);
  for (c19_i2 = 0; c19_i2 < 93; c19_i2++) {
    _SFD_DATA_RANGE_CHECK((*c19_b_X_ref)[c19_i2], 2U);
  }

  *c19_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, *c19_sfEvent);
  c19_hoistedGlobal = *c19_b_x_ref;
  c19_b_hoistedGlobal = *c19_b_x_dot_ref;
  c19_x_ref = c19_hoistedGlobal;
  c19_x_dot_ref = c19_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c19_debug_family_names,
    c19_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c19_pred_horizon, 0U, c19_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c19_X_ref_temp, 1U,
    c19_c_sf_marshallOut, c19_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c19_nargin, 2U, c19_b_sf_marshallOut,
    c19_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c19_nargout, 3U,
    c19_b_sf_marshallOut, c19_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c19_x_ref, 4U, c19_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c19_x_dot_ref, 5U, c19_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c19_X_ref, 6U, c19_sf_marshallOut,
    c19_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c19_sfEvent, 3);
  c19_pred_horizon = 30.0;
  _SFD_EML_CALL(0U, *c19_sfEvent, 5);
  c19_a = c19_x_ref;
  for (c19_i3 = 0; c19_i3 < 31; c19_i3++) {
    c19_y[c19_i3] = c19_a;
  }

  c19_b_a = c19_x_dot_ref;
  for (c19_i4 = 0; c19_i4 < 31; c19_i4++) {
    c19_b_y[c19_i4] = c19_b_a;
  }

  c19_i5 = 0;
  for (c19_i6 = 0; c19_i6 < 31; c19_i6++) {
    c19_X_ref_temp[c19_i5] = c19_y[c19_i6];
    c19_i5 += 3;
  }

  c19_i7 = 0;
  for (c19_i8 = 0; c19_i8 < 31; c19_i8++) {
    c19_X_ref_temp[c19_i7 + 1] = c19_b_y[c19_i8];
    c19_i7 += 3;
  }

  c19_i9 = 0;
  for (c19_i10 = 0; c19_i10 < 31; c19_i10++) {
    c19_X_ref_temp[c19_i9 + 2] = 0.0;
    c19_i9 += 3;
  }

  _SFD_EML_CALL(0U, *c19_sfEvent, 7);
  for (c19_i11 = 0; c19_i11 < 93; c19_i11++) {
    c19_x[c19_i11] = c19_X_ref_temp[c19_i11];
  }

  for (c19_k = 1; c19_k < 94; c19_k++) {
    c19_b_k = c19_k;
    c19_c_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c19_b_k), 1, 93, 1, 0) - 1] = c19_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c19_b_k), 1, 93, 1, 0) - 1];
  }

  for (c19_i12 = 0; c19_i12 < 93; c19_i12++) {
    c19_X_ref[c19_i12] = c19_c_y[c19_i12];
  }

  _SFD_EML_CALL(0U, *c19_sfEvent, -7);
  sf_debug_symbol_scope_pop();
  for (c19_i13 = 0; c19_i13 < 93; c19_i13++) {
    (*c19_b_X_ref)[c19_i13] = c19_X_ref[c19_i13];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, *c19_sfEvent);
  sf_debug_check_for_state_inconsistency(_Hquad_control_LIB_MPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc19_Hquad_control_LIB_MPC
  (SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c19_machineNumber, uint32_T
  c19_chartNumber)
{
}

static const mxArray *c19_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i14;
  real_T c19_b_inData[93];
  int32_T c19_i15;
  real_T c19_u[93];
  const mxArray *c19_y = NULL;
  SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  for (c19_i14 = 0; c19_i14 < 93; c19_i14++) {
    c19_b_inData[c19_i14] = (*(real_T (*)[93])c19_inData)[c19_i14];
  }

  for (c19_i15 = 0; c19_i15 < 93; c19_i15++) {
    c19_u[c19_i15] = c19_b_inData[c19_i15];
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 1, 93), FALSE);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, FALSE);
  return c19_mxArrayOutData;
}

static void c19_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c19_X_ref, const char_T *c19_identifier, real_T
  c19_y[93])
{
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_X_ref), &c19_thisId,
    c19_y);
  sf_mex_destroy(&c19_X_ref);
}

static void c19_b_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId,
  real_T c19_y[93])
{
  real_T c19_dv1[93];
  int32_T c19_i16;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), c19_dv1, 1, 0, 0U, 1, 0U, 1, 93);
  for (c19_i16 = 0; c19_i16 < 93; c19_i16++) {
    c19_y[c19_i16] = c19_dv1[c19_i16];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_X_ref;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y[93];
  int32_T c19_i17;
  SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c19_X_ref = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_X_ref), &c19_thisId,
    c19_y);
  sf_mex_destroy(&c19_X_ref);
  for (c19_i17 = 0; c19_i17 < 93; c19_i17++) {
    (*(real_T (*)[93])c19_outData)[c19_i17] = c19_y[c19_i17];
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_b_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  real_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(real_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, FALSE);
  return c19_mxArrayOutData;
}

static real_T c19_c_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  real_T c19_y;
  real_T c19_d0;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_d0, 1, 0, 0U, 0, 0U, 0);
  c19_y = c19_d0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_nargout;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y;
  SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c19_nargout = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_nargout),
    &c19_thisId);
  sf_mex_destroy(&c19_nargout);
  *(real_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static const mxArray *c19_c_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_i18;
  int32_T c19_i19;
  int32_T c19_i20;
  real_T c19_b_inData[93];
  int32_T c19_i21;
  int32_T c19_i22;
  int32_T c19_i23;
  real_T c19_u[93];
  const mxArray *c19_y = NULL;
  SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_i18 = 0;
  for (c19_i19 = 0; c19_i19 < 31; c19_i19++) {
    for (c19_i20 = 0; c19_i20 < 3; c19_i20++) {
      c19_b_inData[c19_i20 + c19_i18] = (*(real_T (*)[93])c19_inData)[c19_i20 +
        c19_i18];
    }

    c19_i18 += 3;
  }

  c19_i21 = 0;
  for (c19_i22 = 0; c19_i22 < 31; c19_i22++) {
    for (c19_i23 = 0; c19_i23 < 3; c19_i23++) {
      c19_u[c19_i23 + c19_i21] = c19_b_inData[c19_i23 + c19_i21];
    }

    c19_i21 += 3;
  }

  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", c19_u, 0, 0U, 1U, 0U, 2, 3, 31),
                FALSE);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, FALSE);
  return c19_mxArrayOutData;
}

static void c19_d_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId,
  real_T c19_y[93])
{
  real_T c19_dv2[93];
  int32_T c19_i24;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), c19_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                31);
  for (c19_i24 = 0; c19_i24 < 93; c19_i24++) {
    c19_y[c19_i24] = c19_dv2[c19_i24];
  }

  sf_mex_destroy(&c19_u);
}

static void c19_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_X_ref_temp;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  real_T c19_y[93];
  int32_T c19_i25;
  int32_T c19_i26;
  int32_T c19_i27;
  SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c19_X_ref_temp = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_X_ref_temp), &c19_thisId,
    c19_y);
  sf_mex_destroy(&c19_X_ref_temp);
  c19_i25 = 0;
  for (c19_i26 = 0; c19_i26 < 31; c19_i26++) {
    for (c19_i27 = 0; c19_i27 < 3; c19_i27++) {
      (*(real_T (*)[93])c19_outData)[c19_i27 + c19_i25] = c19_y[c19_i27 +
        c19_i25];
    }

    c19_i25 += 3;
  }

  sf_mex_destroy(&c19_mxArrayInData);
}

const mxArray *sf_c19_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c19_nameCaptureInfo;
  c19_ResolvedFunctionInfo c19_info[11];
  c19_ResolvedFunctionInfo (*c19_b_info)[11];
  const mxArray *c19_m0 = NULL;
  int32_T c19_i28;
  c19_ResolvedFunctionInfo *c19_r0;
  c19_nameCaptureInfo = NULL;
  c19_nameCaptureInfo = NULL;
  c19_b_info = (c19_ResolvedFunctionInfo (*)[11])c19_info;
  (*c19_b_info)[0].context = "";
  (*c19_b_info)[0].name = "mtimes";
  (*c19_b_info)[0].dominantType = "double";
  (*c19_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c19_b_info)[0].fileTimeLo = 1289519692U;
  (*c19_b_info)[0].fileTimeHi = 0U;
  (*c19_b_info)[0].mFileTimeLo = 0U;
  (*c19_b_info)[0].mFileTimeHi = 0U;
  (*c19_b_info)[1].context = "";
  (*c19_b_info)[1].name = "reshape";
  (*c19_b_info)[1].dominantType = "double";
  (*c19_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  (*c19_b_info)[1].fileTimeLo = 1286818768U;
  (*c19_b_info)[1].fileTimeHi = 0U;
  (*c19_b_info)[1].mFileTimeLo = 0U;
  (*c19_b_info)[1].mFileTimeHi = 0U;
  (*c19_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  (*c19_b_info)[2].name = "eml_index_class";
  (*c19_b_info)[2].dominantType = "";
  (*c19_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c19_b_info)[2].fileTimeLo = 1286818778U;
  (*c19_b_info)[2].fileTimeHi = 0U;
  (*c19_b_info)[2].mFileTimeLo = 0U;
  (*c19_b_info)[2].mFileTimeHi = 0U;
  (*c19_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!varargin_nempty";
  (*c19_b_info)[3].name = "eml_index_plus";
  (*c19_b_info)[3].dominantType = "int32";
  (*c19_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  (*c19_b_info)[3].fileTimeLo = 1286818778U;
  (*c19_b_info)[3].fileTimeHi = 0U;
  (*c19_b_info)[3].mFileTimeLo = 0U;
  (*c19_b_info)[3].mFileTimeHi = 0U;
  (*c19_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  (*c19_b_info)[4].name = "eml_assert_valid_size_arg";
  (*c19_b_info)[4].dominantType = "double";
  (*c19_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  (*c19_b_info)[4].fileTimeLo = 1286818694U;
  (*c19_b_info)[4].fileTimeHi = 0U;
  (*c19_b_info)[4].mFileTimeLo = 0U;
  (*c19_b_info)[4].mFileTimeHi = 0U;
  (*c19_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  (*c19_b_info)[5].name = "isinf";
  (*c19_b_info)[5].dominantType = "double";
  (*c19_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  (*c19_b_info)[5].fileTimeLo = 1286818760U;
  (*c19_b_info)[5].fileTimeHi = 0U;
  (*c19_b_info)[5].mFileTimeLo = 0U;
  (*c19_b_info)[5].mFileTimeHi = 0U;
  (*c19_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  (*c19_b_info)[6].name = "intmax";
  (*c19_b_info)[6].dominantType = "char";
  (*c19_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  (*c19_b_info)[6].fileTimeLo = 1286818756U;
  (*c19_b_info)[6].fileTimeHi = 0U;
  (*c19_b_info)[6].mFileTimeLo = 0U;
  (*c19_b_info)[6].mFileTimeHi = 0U;
  (*c19_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  (*c19_b_info)[7].name = "eml_index_prod";
  (*c19_b_info)[7].dominantType = "int32";
  (*c19_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  (*c19_b_info)[7].fileTimeLo = 1286818780U;
  (*c19_b_info)[7].fileTimeHi = 0U;
  (*c19_b_info)[7].mFileTimeLo = 0U;
  (*c19_b_info)[7].mFileTimeHi = 0U;
  (*c19_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_prod.m";
  (*c19_b_info)[8].name = "eml_index_times";
  (*c19_b_info)[8].dominantType = "int32";
  (*c19_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  (*c19_b_info)[8].fileTimeLo = 1286818780U;
  (*c19_b_info)[8].fileTimeHi = 0U;
  (*c19_b_info)[8].mFileTimeLo = 0U;
  (*c19_b_info)[8].mFileTimeHi = 0U;
  (*c19_b_info)[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size";
  (*c19_b_info)[9].name = "eml_index_rdivide";
  (*c19_b_info)[9].dominantType = "int32";
  (*c19_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m";
  (*c19_b_info)[9].fileTimeLo = 1286818780U;
  (*c19_b_info)[9].fileTimeHi = 0U;
  (*c19_b_info)[9].mFileTimeLo = 0U;
  (*c19_b_info)[9].mFileTimeHi = 0U;
  (*c19_b_info)[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m";
  (*c19_b_info)[10].name = "eml_scalar_eg";
  (*c19_b_info)[10].dominantType = "double";
  (*c19_b_info)[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c19_b_info)[10].fileTimeLo = 1286818796U;
  (*c19_b_info)[10].fileTimeHi = 0U;
  (*c19_b_info)[10].mFileTimeLo = 0U;
  (*c19_b_info)[10].mFileTimeHi = 0U;
  sf_mex_assign(&c19_m0, sf_mex_createstruct("nameCaptureInfo", 1, 11), FALSE);
  for (c19_i28 = 0; c19_i28 < 11; c19_i28++) {
    c19_r0 = &c19_info[c19_i28];
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c19_r0->context)), "context", "nameCaptureInfo",
                    c19_i28);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c19_r0->name)), "name", "nameCaptureInfo",
                    c19_i28);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo",
      c19_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c19_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c19_i28);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", c19_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c19_r0->resolved)), "resolved",
                    "nameCaptureInfo", c19_i28);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c19_i28);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo", &c19_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c19_i28);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo",
      &c19_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c19_i28);
    sf_mex_addfield(c19_m0, sf_mex_create("nameCaptureInfo",
      &c19_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c19_i28);
  }

  sf_mex_assign(&c19_nameCaptureInfo, c19_m0, FALSE);
  return c19_nameCaptureInfo;
}

static const mxArray *c19_d_sf_marshallOut(void *chartInstanceVoid, void
  *c19_inData)
{
  const mxArray *c19_mxArrayOutData = NULL;
  int32_T c19_u;
  const mxArray *c19_y = NULL;
  SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c19_mxArrayOutData = NULL;
  c19_u = *(int32_T *)c19_inData;
  c19_y = NULL;
  sf_mex_assign(&c19_y, sf_mex_create("y", &c19_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c19_mxArrayOutData, c19_y, FALSE);
  return c19_mxArrayOutData;
}

static int32_T c19_e_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  int32_T c19_y;
  int32_T c19_i29;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_i29, 1, 6, 0U, 0, 0U, 0);
  c19_y = c19_i29;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void c19_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c19_mxArrayInData, const char_T *c19_varName, void *c19_outData)
{
  const mxArray *c19_sfEvent;
  const char_T *c19_identifier;
  emlrtMsgIdentifier c19_thisId;
  int32_T c19_y;
  SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c19_sfEvent = sf_mex_dup(c19_mxArrayInData);
  c19_identifier = c19_varName;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c19_sfEvent),
    &c19_thisId);
  sf_mex_destroy(&c19_sfEvent);
  *(int32_T *)c19_outData = c19_y;
  sf_mex_destroy(&c19_mxArrayInData);
}

static uint8_T c19_f_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c19_is_active_c19_Hquad_control_LIB_MPC, const
  char_T *c19_identifier)
{
  uint8_T c19_y;
  emlrtMsgIdentifier c19_thisId;
  c19_thisId.fIdentifier = c19_identifier;
  c19_thisId.fParent = NULL;
  c19_y = c19_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c19_is_active_c19_Hquad_control_LIB_MPC), &c19_thisId);
  sf_mex_destroy(&c19_is_active_c19_Hquad_control_LIB_MPC);
  return c19_y;
}

static uint8_T c19_g_emlrt_marshallIn(SFc19_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c19_u, const emlrtMsgIdentifier *c19_parentId)
{
  uint8_T c19_y;
  uint8_T c19_u0;
  sf_mex_import(c19_parentId, sf_mex_dup(c19_u), &c19_u0, 1, 3, 0U, 0, 0U, 0);
  c19_y = c19_u0;
  sf_mex_destroy(&c19_u);
  return c19_y;
}

static void init_dsm_address_info(SFc19_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c19_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2521006801U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(754290048U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(564783754U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(680354683U);
}

mxArray *sf_c19_Hquad_control_LIB_MPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("l4sQCkTe9nJnzCwPkz6xlD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(93);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c19_Hquad_control_LIB_MPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[18],T\"X_ref\",},{M[8],M[0],T\"is_active_c19_Hquad_control_LIB_MPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c19_Hquad_control_LIB_MPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
    chartInstance = (SFc19_Hquad_control_LIB_MPCInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Hquad_control_LIB_MPCMachineNumber_,
           19,
           1,
           1,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"x_ref");
          _SFD_SET_DATA_PROPS(1,1,1,0,"x_dot_ref");
          _SFD_SET_DATA_PROPS(2,2,0,1,"X_ref");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,197);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c19_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 93;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c19_sf_marshallOut,(MexInFcnForType)
            c19_sf_marshallIn);
        }

        {
          real_T *c19_x_ref;
          real_T *c19_x_dot_ref;
          real_T (*c19_X_ref)[93];
          c19_X_ref = (real_T (*)[93])ssGetOutputPortSignal(chartInstance->S, 1);
          c19_x_dot_ref = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c19_x_ref = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c19_x_ref);
          _SFD_SET_DATA_VALUE_PTR(1U, c19_x_dot_ref);
          _SFD_SET_DATA_VALUE_PTR(2U, *c19_X_ref);
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
      19, "dworkChecksum");
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

static void sf_opaque_initialize_c19_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc19_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc19_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c19_Hquad_control_LIB_MPC
    ((SFc19_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
  initialize_c19_Hquad_control_LIB_MPC
    ((SFc19_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c19_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  enable_c19_Hquad_control_LIB_MPC((SFc19_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c19_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  disable_c19_Hquad_control_LIB_MPC((SFc19_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c19_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_c19_Hquad_control_LIB_MPC((SFc19_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c19_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  ext_mode_exec_c19_Hquad_control_LIB_MPC
    ((SFc19_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c19_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c19_Hquad_control_LIB_MPC
    ((SFc19_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_Hquad_control_LIB_MPC();/* state var info */
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

extern void sf_internal_set_sim_state_c19_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c19_Hquad_control_LIB_MPC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c19_Hquad_control_LIB_MPC
    ((SFc19_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c19_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c19_Hquad_control_LIB_MPC(S);
}

static void sf_opaque_set_sim_state_c19_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c19_Hquad_control_LIB_MPC(S, st);
}

static void sf_opaque_terminate_c19_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc19_Hquad_control_LIB_MPCInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c19_Hquad_control_LIB_MPC
      ((SFc19_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Hquad_control_LIB_MPC_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc19_Hquad_control_LIB_MPC
    ((SFc19_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c19_Hquad_control_LIB_MPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c19_Hquad_control_LIB_MPC
      ((SFc19_Hquad_control_LIB_MPCInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c19_Hquad_control_LIB_MPC_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c19_Hquad_control_LIB_MPC\",T\"is_active_c19_Hquad_control_LIB_MPC\"}}"
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

static void mdlSetWorkWidths_c19_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,19);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,19,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,19,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,19,2);
      sf_mark_chart_reusable_outputs(S,infoStruct,19,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,19);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(425713604U));
  ssSetChecksum1(S,(2229498320U));
  ssSetChecksum2(S,(793927280U));
  ssSetChecksum3(S,(3130563283U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c19_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c19_Hquad_control_LIB_MPC(SimStruct *S)
{
  SFc19_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc19_Hquad_control_LIB_MPCInstanceStruct *)malloc(sizeof
    (SFc19_Hquad_control_LIB_MPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc19_Hquad_control_LIB_MPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c19_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c19_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c19_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c19_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c19_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c19_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c19_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c19_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c19_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c19_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c19_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c19_Hquad_control_LIB_MPC;
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

void c19_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c19_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c19_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c19_Hquad_control_LIB_MPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c19_Hquad_control_LIB_MPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
