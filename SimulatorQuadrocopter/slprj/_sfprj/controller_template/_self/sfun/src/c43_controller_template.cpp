/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c43_controller_template.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c43_debug_family_names[6] = { "nargin", "nargout",
  "state_meas", "enable_flag", "flag_init", "x_init" };

/* Function Declarations */
static void initialize_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance);
static void enable_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance);
static void disable_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance);
static void c43_update_debugger_state_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance, const mxArray *c43_st);
static void finalize_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance);
static void sf_c43_controller_template(SFc43_controller_templateInstanceStruct
  *chartInstance);
static void initSimStructsc43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c43_machineNumber, uint32_T
  c43_chartNumber);
static const mxArray *c43_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static void c43_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_x_init, const char_T *c43_identifier,
  real_T c43_y[4]);
static void c43_b_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId,
  real_T c43_y[4]);
static void c43_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_b_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static real_T c43_c_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_flag_init, const char_T *c43_identifier);
static real_T c43_d_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_c_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static int32_T c43_e_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static uint8_T c43_f_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_is_active_c43_controller_template, const
  char_T *c43_identifier);
static uint8_T c43_g_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void init_dsm_address_info(SFc43_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c43_sfEvent;
  uint8_T *c43_is_active_c43_controller_template;
  c43_is_active_c43_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c43_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c43_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c43_is_active_c43_controller_template = 0U;
}

static void initialize_params_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c43_update_debugger_state_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance)
{
  c43_update_debugger_state_c43_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c43_st;
  const mxArray *c43_y = NULL;
  real_T c43_hoistedGlobal;
  real_T c43_u;
  const mxArray *c43_b_y = NULL;
  int32_T c43_i0;
  real_T c43_b_u[4];
  const mxArray *c43_c_y = NULL;
  uint8_T c43_b_hoistedGlobal;
  uint8_T c43_c_u;
  const mxArray *c43_d_y = NULL;
  real_T *c43_flag_init;
  uint8_T *c43_is_active_c43_controller_template;
  real_T (*c43_x_init)[4];
  c43_x_init = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c43_flag_init = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c43_is_active_c43_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c43_st = NULL;
  c43_st = NULL;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_createcellarray(3), FALSE);
  c43_hoistedGlobal = *c43_flag_init;
  c43_u = c43_hoistedGlobal;
  c43_b_y = NULL;
  sf_mex_assign(&c43_b_y, sf_mex_create("y", &c43_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c43_y, 0, c43_b_y);
  for (c43_i0 = 0; c43_i0 < 4; c43_i0++) {
    c43_b_u[c43_i0] = (*c43_x_init)[c43_i0];
  }

  c43_c_y = NULL;
  sf_mex_assign(&c43_c_y, sf_mex_create("y", c43_b_u, 0, 0U, 1U, 0U, 1, 4),
                FALSE);
  sf_mex_setcell(c43_y, 1, c43_c_y);
  c43_b_hoistedGlobal = *c43_is_active_c43_controller_template;
  c43_c_u = c43_b_hoistedGlobal;
  c43_d_y = NULL;
  sf_mex_assign(&c43_d_y, sf_mex_create("y", &c43_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c43_y, 2, c43_d_y);
  sf_mex_assign(&c43_st, c43_y, FALSE);
  return c43_st;
}

static void set_sim_state_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance, const mxArray *c43_st)
{
  const mxArray *c43_u;
  real_T c43_dv0[4];
  int32_T c43_i1;
  boolean_T *c43_doneDoubleBufferReInit;
  real_T *c43_flag_init;
  uint8_T *c43_is_active_c43_controller_template;
  real_T (*c43_x_init)[4];
  c43_x_init = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c43_flag_init = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c43_is_active_c43_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c43_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c43_doneDoubleBufferReInit = TRUE;
  c43_u = sf_mex_dup(c43_st);
  *c43_flag_init = c43_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c43_u, 0)), "flag_init");
  c43_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c43_u, 1)),
                       "x_init", c43_dv0);
  for (c43_i1 = 0; c43_i1 < 4; c43_i1++) {
    (*c43_x_init)[c43_i1] = c43_dv0[c43_i1];
  }

  *c43_is_active_c43_controller_template = c43_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c43_u, 2)), "is_active_c43_controller_template");
  sf_mex_destroy(&c43_u);
  c43_update_debugger_state_c43_controller_template(chartInstance);
  sf_mex_destroy(&c43_st);
}

static void finalize_c43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c43_controller_template(SFc43_controller_templateInstanceStruct
  *chartInstance)
{
  int32_T c43_i2;
  int32_T c43_i3;
  real_T c43_hoistedGlobal;
  int32_T c43_i4;
  real_T c43_state_meas[4];
  real_T c43_enable_flag;
  uint32_T c43_debug_family_var_map[6];
  real_T c43_nargin = 2.0;
  real_T c43_nargout = 2.0;
  real_T c43_flag_init;
  real_T c43_x_init[4];
  int32_T c43_i5;
  int32_T c43_i6;
  int32_T *c43_sfEvent;
  real_T *c43_b_flag_init;
  real_T *c43_b_enable_flag;
  real_T (*c43_b_x_init)[4];
  real_T (*c43_b_state_meas)[4];
  c43_b_x_init = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
  c43_b_enable_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c43_b_flag_init = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c43_b_state_meas = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c43_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 41U, *c43_sfEvent);
  for (c43_i2 = 0; c43_i2 < 4; c43_i2++) {
    _SFD_DATA_RANGE_CHECK((*c43_b_state_meas)[c43_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c43_b_flag_init, 1U);
  _SFD_DATA_RANGE_CHECK(*c43_b_enable_flag, 2U);
  for (c43_i3 = 0; c43_i3 < 4; c43_i3++) {
    _SFD_DATA_RANGE_CHECK((*c43_b_x_init)[c43_i3], 3U);
  }

  *c43_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 41U, *c43_sfEvent);
  c43_hoistedGlobal = *c43_b_enable_flag;
  for (c43_i4 = 0; c43_i4 < 4; c43_i4++) {
    c43_state_meas[c43_i4] = (*c43_b_state_meas)[c43_i4];
  }

  c43_enable_flag = c43_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c43_debug_family_names,
    c43_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c43_nargin, 0U, c43_b_sf_marshallOut,
    c43_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c43_nargout, 1U,
    c43_b_sf_marshallOut, c43_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c43_state_meas, 2U, c43_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c43_enable_flag, 3U, c43_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c43_flag_init, 4U,
    c43_b_sf_marshallOut, c43_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c43_x_init, 5U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c43_sfEvent, 4);
  for (c43_i5 = 0; c43_i5 < 4; c43_i5++) {
    c43_x_init[c43_i5] = c43_state_meas[c43_i5];
  }

  _SFD_EML_CALL(0U, *c43_sfEvent, 5);
  c43_flag_init = 0.0;
  _SFD_EML_CALL(0U, *c43_sfEvent, 7);
  if (CV_EML_IF(0, 1, 0, c43_enable_flag == 1.0)) {
    _SFD_EML_CALL(0U, *c43_sfEvent, 8);
    c43_flag_init = 1.0;
  }

  _SFD_EML_CALL(0U, *c43_sfEvent, -8);
  sf_debug_symbol_scope_pop();
  *c43_b_flag_init = c43_flag_init;
  for (c43_i6 = 0; c43_i6 < 4; c43_i6++) {
    (*c43_b_x_init)[c43_i6] = c43_x_init[c43_i6];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 41U, *c43_sfEvent);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc43_controller_template
  (SFc43_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c43_machineNumber, uint32_T
  c43_chartNumber)
{
}

static const mxArray *c43_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_i7;
  real_T c43_b_inData[4];
  int32_T c43_i8;
  real_T c43_u[4];
  const mxArray *c43_y = NULL;
  SFc43_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc43_controller_templateInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  for (c43_i7 = 0; c43_i7 < 4; c43_i7++) {
    c43_b_inData[c43_i7] = (*(real_T (*)[4])c43_inData)[c43_i7];
  }

  for (c43_i8 = 0; c43_i8 < 4; c43_i8++) {
    c43_u[c43_i8] = c43_b_inData[c43_i8];
  }

  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", c43_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, FALSE);
  return c43_mxArrayOutData;
}

static void c43_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_x_init, const char_T *c43_identifier,
  real_T c43_y[4])
{
  emlrtMsgIdentifier c43_thisId;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_x_init), &c43_thisId,
    c43_y);
  sf_mex_destroy(&c43_x_init);
}

static void c43_b_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId,
  real_T c43_y[4])
{
  real_T c43_dv1[4];
  int32_T c43_i9;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), c43_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c43_i9 = 0; c43_i9 < 4; c43_i9++) {
    c43_y[c43_i9] = c43_dv1[c43_i9];
  }

  sf_mex_destroy(&c43_u);
}

static void c43_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_x_init;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y[4];
  int32_T c43_i10;
  SFc43_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc43_controller_templateInstanceStruct *)chartInstanceVoid;
  c43_x_init = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_x_init), &c43_thisId,
    c43_y);
  sf_mex_destroy(&c43_x_init);
  for (c43_i10 = 0; c43_i10 < 4; c43_i10++) {
    (*(real_T (*)[4])c43_outData)[c43_i10] = c43_y[c43_i10];
  }

  sf_mex_destroy(&c43_mxArrayInData);
}

static const mxArray *c43_b_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  real_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc43_controller_templateInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(real_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, FALSE);
  return c43_mxArrayOutData;
}

static real_T c43_c_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_flag_init, const char_T *c43_identifier)
{
  real_T c43_y;
  emlrtMsgIdentifier c43_thisId;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_flag_init),
    &c43_thisId);
  sf_mex_destroy(&c43_flag_init);
  return c43_y;
}

static real_T c43_d_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  real_T c43_y;
  real_T c43_d0;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_d0, 1, 0, 0U, 0, 0U, 0);
  c43_y = c43_d0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_flag_init;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y;
  SFc43_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc43_controller_templateInstanceStruct *)chartInstanceVoid;
  c43_flag_init = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_flag_init),
    &c43_thisId);
  sf_mex_destroy(&c43_flag_init);
  *(real_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

const mxArray *sf_c43_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c43_nameCaptureInfo = NULL;
  c43_nameCaptureInfo = NULL;
  sf_mex_assign(&c43_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c43_nameCaptureInfo;
}

static const mxArray *c43_c_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc43_controller_templateInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(int32_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, FALSE);
  return c43_mxArrayOutData;
}

static int32_T c43_e_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  int32_T c43_y;
  int32_T c43_i11;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_i11, 1, 6, 0U, 0, 0U, 0);
  c43_y = c43_i11;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_sfEvent;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  int32_T c43_y;
  SFc43_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc43_controller_templateInstanceStruct *)chartInstanceVoid;
  c43_sfEvent = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_sfEvent),
    &c43_thisId);
  sf_mex_destroy(&c43_sfEvent);
  *(int32_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static uint8_T c43_f_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_is_active_c43_controller_template, const
  char_T *c43_identifier)
{
  uint8_T c43_y;
  emlrtMsgIdentifier c43_thisId;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c43_is_active_c43_controller_template), &c43_thisId);
  sf_mex_destroy(&c43_is_active_c43_controller_template);
  return c43_y;
}

static uint8_T c43_g_emlrt_marshallIn(SFc43_controller_templateInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  uint8_T c43_y;
  uint8_T c43_u0;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_u0, 1, 3, 0U, 0, 0U, 0);
  c43_y = c43_u0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void init_dsm_address_info(SFc43_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c43_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3996817027U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3616271034U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1290298100U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2080027144U);
}

mxArray *sf_c43_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("dMViGNgybbIVAimtGweSOC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c43_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"flag_init\",},{M[1],M[7],T\"x_init\",},{M[8],M[0],T\"is_active_c43_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c43_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc43_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc43_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           43,
           1,
           1,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"state_meas");
          _SFD_SET_DATA_PROPS(1,2,0,1,"flag_init");
          _SFD_SET_DATA_PROPS(2,1,1,0,"enable_flag");
          _SFD_SET_DATA_PROPS(3,2,0,1,"x_init");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,166);
        _SFD_CV_INIT_EML_IF(0,1,0,119,138,-1,161);
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
            1.0,0,0,(MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)
          c43_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)
            c43_sf_marshallIn);
        }

        {
          real_T *c43_flag_init;
          real_T *c43_enable_flag;
          real_T (*c43_state_meas)[4];
          real_T (*c43_x_init)[4];
          c43_x_init = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 2);
          c43_enable_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c43_flag_init = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c43_state_meas = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c43_state_meas);
          _SFD_SET_DATA_VALUE_PTR(1U, c43_flag_init);
          _SFD_SET_DATA_VALUE_PTR(2U, c43_enable_flag);
          _SFD_SET_DATA_VALUE_PTR(3U, *c43_x_init);
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
      43, "dworkChecksum");
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

static void sf_opaque_initialize_c43_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc43_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc43_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c43_controller_template
    ((SFc43_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c43_controller_template((SFc43_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c43_controller_template(void *chartInstanceVar)
{
  enable_c43_controller_template((SFc43_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c43_controller_template(void *chartInstanceVar)
{
  disable_c43_controller_template((SFc43_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c43_controller_template(void *chartInstanceVar)
{
  sf_c43_controller_template((SFc43_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c43_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c43_controller_template((SFc43_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c43_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c43_controller_template
    ((SFc43_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c43_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c43_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c43_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c43_controller_template((SFc43_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c43_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c43_controller_template(S);
}

static void sf_opaque_set_sim_state_c43_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c43_controller_template(S, st);
}

static void sf_opaque_terminate_c43_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc43_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c43_controller_template((SFc43_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc43_controller_template((SFc43_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c43_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c43_controller_template
      ((SFc43_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c43_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c43_controller_template\",T\"is_active_c43_controller_template\"}}"
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

static void mdlSetWorkWidths_c43_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,43);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,43,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,43,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,43,2);
      sf_mark_chart_reusable_outputs(S,infoStruct,43,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,43);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1547062107U));
  ssSetChecksum1(S,(1257660455U));
  ssSetChecksum2(S,(2268328429U));
  ssSetChecksum3(S,(583093780U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c43_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c43_controller_template(SimStruct *S)
{
  SFc43_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc43_controller_templateInstanceStruct *)malloc(sizeof
    (SFc43_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc43_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c43_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c43_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c43_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c43_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c43_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c43_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c43_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c43_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c43_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c43_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c43_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c43_controller_template;
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

void c43_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c43_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c43_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c43_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c43_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
