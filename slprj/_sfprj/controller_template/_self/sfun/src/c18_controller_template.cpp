/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c18_controller_template.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c18_debug_family_names[12] = { "nargin", "nargout",
  "nominal_window_z", "nominal_window_y", "vel_z", "vel_y", "thres_vel_z",
  "thres_vel_y", "K_gain", "maxDeltaWindow", "nominal_window_z_out",
  "nominal_window_y_out" };

/* Function Declarations */
static void initialize_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance);
static void enable_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance);
static void disable_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance);
static void c18_update_debugger_state_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance, const mxArray *c18_st);
static void finalize_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance);
static void sf_c18_controller_template(SFc18_controller_templateInstanceStruct
  *chartInstance);
static void c18_chartstep_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance);
static void initSimStructsc18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber);
static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static real_T c18_emlrt_marshallIn(SFc18_controller_templateInstanceStruct
  *chartInstance, const mxArray *c18_nominal_window_y_out, const char_T
  *c18_identifier);
static real_T c18_b_emlrt_marshallIn(SFc18_controller_templateInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static void c18_eml_scalar_eg(SFc18_controller_templateInstanceStruct
  *chartInstance);
static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData);
static int32_T c18_c_emlrt_marshallIn(SFc18_controller_templateInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData);
static uint8_T c18_d_emlrt_marshallIn(SFc18_controller_templateInstanceStruct
  *chartInstance, const mxArray *c18_is_active_c18_controller_template, const
  char_T *c18_identifier);
static uint8_T c18_e_emlrt_marshallIn(SFc18_controller_templateInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId);
static void init_dsm_address_info(SFc18_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c18_sfEvent;
  uint8_T *c18_is_active_c18_controller_template;
  c18_is_active_c18_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c18_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c18_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c18_is_active_c18_controller_template = 0U;
}

static void initialize_params_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c18_update_debugger_state_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance)
{
  c18_update_debugger_state_c18_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c18_st;
  const mxArray *c18_y = NULL;
  real_T c18_hoistedGlobal;
  real_T c18_u;
  const mxArray *c18_b_y = NULL;
  real_T c18_b_hoistedGlobal;
  real_T c18_b_u;
  const mxArray *c18_c_y = NULL;
  uint8_T c18_c_hoistedGlobal;
  uint8_T c18_c_u;
  const mxArray *c18_d_y = NULL;
  real_T *c18_nominal_window_y_out;
  real_T *c18_nominal_window_z_out;
  uint8_T *c18_is_active_c18_controller_template;
  c18_nominal_window_y_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c18_nominal_window_z_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c18_is_active_c18_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c18_st = NULL;
  c18_st = NULL;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_createcellarray(3), FALSE);
  c18_hoistedGlobal = *c18_nominal_window_y_out;
  c18_u = c18_hoistedGlobal;
  c18_b_y = NULL;
  sf_mex_assign(&c18_b_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c18_y, 0, c18_b_y);
  c18_b_hoistedGlobal = *c18_nominal_window_z_out;
  c18_b_u = c18_b_hoistedGlobal;
  c18_c_y = NULL;
  sf_mex_assign(&c18_c_y, sf_mex_create("y", &c18_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c18_y, 1, c18_c_y);
  c18_c_hoistedGlobal = *c18_is_active_c18_controller_template;
  c18_c_u = c18_c_hoistedGlobal;
  c18_d_y = NULL;
  sf_mex_assign(&c18_d_y, sf_mex_create("y", &c18_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c18_y, 2, c18_d_y);
  sf_mex_assign(&c18_st, c18_y, FALSE);
  return c18_st;
}

static void set_sim_state_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance, const mxArray *c18_st)
{
  const mxArray *c18_u;
  boolean_T *c18_doneDoubleBufferReInit;
  real_T *c18_nominal_window_y_out;
  real_T *c18_nominal_window_z_out;
  uint8_T *c18_is_active_c18_controller_template;
  c18_nominal_window_y_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c18_nominal_window_z_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c18_is_active_c18_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c18_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c18_doneDoubleBufferReInit = TRUE;
  c18_u = sf_mex_dup(c18_st);
  *c18_nominal_window_y_out = c18_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c18_u, 0)), "nominal_window_y_out");
  *c18_nominal_window_z_out = c18_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c18_u, 1)), "nominal_window_z_out");
  *c18_is_active_c18_controller_template = c18_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c18_u, 2)), "is_active_c18_controller_template");
  sf_mex_destroy(&c18_u);
  c18_update_debugger_state_c18_controller_template(chartInstance);
  sf_mex_destroy(&c18_st);
}

static void finalize_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c18_controller_template(SFc18_controller_templateInstanceStruct
  *chartInstance)
{
  int32_T *c18_sfEvent;
  real_T *c18_nominal_window_z;
  real_T *c18_nominal_window_z_out;
  real_T *c18_nominal_window_y;
  real_T *c18_vel_z;
  real_T *c18_vel_y;
  real_T *c18_thres_vel_z;
  real_T *c18_thres_vel_y;
  real_T *c18_K_gain;
  real_T *c18_maxDeltaWindow;
  real_T *c18_nominal_window_y_out;
  c18_nominal_window_y_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c18_maxDeltaWindow = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c18_K_gain = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c18_thres_vel_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c18_thres_vel_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c18_vel_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c18_vel_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c18_nominal_window_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c18_nominal_window_z_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c18_nominal_window_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c18_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, *c18_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c18_nominal_window_z, 0U);
  _SFD_DATA_RANGE_CHECK(*c18_nominal_window_z_out, 1U);
  _SFD_DATA_RANGE_CHECK(*c18_nominal_window_y, 2U);
  _SFD_DATA_RANGE_CHECK(*c18_vel_z, 3U);
  _SFD_DATA_RANGE_CHECK(*c18_vel_y, 4U);
  _SFD_DATA_RANGE_CHECK(*c18_thres_vel_z, 5U);
  _SFD_DATA_RANGE_CHECK(*c18_thres_vel_y, 6U);
  _SFD_DATA_RANGE_CHECK(*c18_K_gain, 7U);
  _SFD_DATA_RANGE_CHECK(*c18_maxDeltaWindow, 8U);
  _SFD_DATA_RANGE_CHECK(*c18_nominal_window_y_out, 9U);
  *c18_sfEvent = CALL_EVENT;
  c18_chartstep_c18_controller_template(chartInstance);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c18_chartstep_c18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance)
{
  real_T c18_hoistedGlobal;
  real_T c18_b_hoistedGlobal;
  real_T c18_c_hoistedGlobal;
  real_T c18_d_hoistedGlobal;
  real_T c18_e_hoistedGlobal;
  real_T c18_f_hoistedGlobal;
  real_T c18_g_hoistedGlobal;
  real_T c18_h_hoistedGlobal;
  real_T c18_nominal_window_z;
  real_T c18_nominal_window_y;
  real_T c18_vel_z;
  real_T c18_vel_y;
  real_T c18_thres_vel_z;
  real_T c18_thres_vel_y;
  real_T c18_K_gain;
  real_T c18_maxDeltaWindow;
  uint32_T c18_debug_family_var_map[12];
  real_T c18_nargin = 8.0;
  real_T c18_nargout = 2.0;
  real_T c18_nominal_window_z_out;
  real_T c18_nominal_window_y_out;
  real_T c18_x;
  real_T c18_b_x;
  real_T c18_c_x;
  real_T c18_d_x;
  real_T c18_y;
  real_T c18_a;
  real_T c18_b;
  real_T c18_b_y;
  real_T c18_varargin_1;
  real_T c18_varargin_2;
  real_T c18_b_varargin_2;
  real_T c18_varargin_3;
  real_T c18_e_x;
  real_T c18_c_y;
  real_T c18_f_x;
  real_T c18_d_y;
  real_T c18_xk;
  real_T c18_yk;
  real_T c18_g_x;
  real_T c18_e_y;
  real_T c18_minval;
  real_T c18_h_x;
  real_T c18_i_x;
  real_T c18_f_y;
  real_T c18_b_a;
  real_T c18_b_b;
  real_T c18_g_y;
  real_T c18_b_varargin_1;
  real_T c18_c_varargin_2;
  real_T c18_d_varargin_2;
  real_T c18_b_varargin_3;
  real_T c18_j_x;
  real_T c18_h_y;
  real_T c18_k_x;
  real_T c18_i_y;
  real_T c18_b_xk;
  real_T c18_b_yk;
  real_T c18_l_x;
  real_T c18_j_y;
  real_T c18_b_minval;
  real_T *c18_b_nominal_window_z;
  real_T *c18_b_nominal_window_y;
  real_T *c18_b_vel_z;
  real_T *c18_b_vel_y;
  real_T *c18_b_thres_vel_z;
  real_T *c18_b_thres_vel_y;
  real_T *c18_b_K_gain;
  real_T *c18_b_maxDeltaWindow;
  real_T *c18_b_nominal_window_z_out;
  real_T *c18_b_nominal_window_y_out;
  int32_T *c18_sfEvent;
  c18_b_nominal_window_y_out = (real_T *)ssGetOutputPortSignal(chartInstance->S,
    2);
  c18_b_maxDeltaWindow = (real_T *)ssGetInputPortSignal(chartInstance->S, 7);
  c18_b_K_gain = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c18_b_thres_vel_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c18_b_thres_vel_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c18_b_vel_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c18_b_vel_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c18_b_nominal_window_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c18_b_nominal_window_z_out = (real_T *)ssGetOutputPortSignal(chartInstance->S,
    1);
  c18_b_nominal_window_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c18_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, *c18_sfEvent);
  c18_hoistedGlobal = *c18_b_nominal_window_z;
  c18_b_hoistedGlobal = *c18_b_nominal_window_y;
  c18_c_hoistedGlobal = *c18_b_vel_z;
  c18_d_hoistedGlobal = *c18_b_vel_y;
  c18_e_hoistedGlobal = *c18_b_thres_vel_z;
  c18_f_hoistedGlobal = *c18_b_thres_vel_y;
  c18_g_hoistedGlobal = *c18_b_K_gain;
  c18_h_hoistedGlobal = *c18_b_maxDeltaWindow;
  c18_nominal_window_z = c18_hoistedGlobal;
  c18_nominal_window_y = c18_b_hoistedGlobal;
  c18_vel_z = c18_c_hoistedGlobal;
  c18_vel_y = c18_d_hoistedGlobal;
  c18_thres_vel_z = c18_e_hoistedGlobal;
  c18_thres_vel_y = c18_f_hoistedGlobal;
  c18_K_gain = c18_g_hoistedGlobal;
  c18_maxDeltaWindow = c18_h_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 12U, 12U, c18_debug_family_names,
    c18_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c18_nargin, 0U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c18_nargout, 1U, c18_sf_marshallOut,
    c18_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c18_nominal_window_z, 2U, c18_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c18_nominal_window_y, 3U, c18_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c18_vel_z, 4U, c18_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c18_vel_y, 5U, c18_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c18_thres_vel_z, 6U, c18_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c18_thres_vel_y, 7U, c18_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c18_K_gain, 8U, c18_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c18_maxDeltaWindow, 9U, c18_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c18_nominal_window_z_out, 10U,
    c18_sf_marshallOut, c18_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c18_nominal_window_y_out, 11U,
    c18_sf_marshallOut, c18_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c18_sfEvent, 4);
  c18_nominal_window_z_out = c18_nominal_window_z;
  _SFD_EML_CALL(0U, *c18_sfEvent, 5);
  c18_nominal_window_y_out = c18_nominal_window_y;
  _SFD_EML_CALL(0U, *c18_sfEvent, 7);
  c18_x = c18_vel_y;
  c18_b_x = c18_x;
  c18_vel_y = muDoubleScalarAbs(c18_b_x);
  _SFD_EML_CALL(0U, *c18_sfEvent, 8);
  _SFD_EML_CALL(0U, *c18_sfEvent, 10);
  if (CV_EML_IF(0, 1, 0, c18_vel_y > c18_thres_vel_y)) {
    _SFD_EML_CALL(0U, *c18_sfEvent, 11);
    c18_c_x = c18_vel_y - c18_thres_vel_y;
    c18_d_x = c18_c_x;
    c18_y = muDoubleScalarAbs(c18_d_x);
    c18_a = c18_K_gain;
    c18_b = c18_y;
    c18_b_y = c18_a * c18_b;
    c18_varargin_1 = c18_b_y;
    c18_varargin_2 = c18_maxDeltaWindow;
    c18_b_varargin_2 = c18_varargin_1;
    c18_varargin_3 = c18_varargin_2;
    c18_e_x = c18_b_varargin_2;
    c18_c_y = c18_varargin_3;
    c18_f_x = c18_e_x;
    c18_d_y = c18_c_y;
    c18_eml_scalar_eg(chartInstance);
    c18_xk = c18_f_x;
    c18_yk = c18_d_y;
    c18_g_x = c18_xk;
    c18_e_y = c18_yk;
    c18_eml_scalar_eg(chartInstance);
    c18_minval = muDoubleScalarMin(c18_g_x, c18_e_y);
    c18_nominal_window_y_out = c18_nominal_window_y - c18_minval;
  }

  _SFD_EML_CALL(0U, *c18_sfEvent, 14);
  if (CV_EML_IF(0, 1, 1, c18_vel_z > c18_thres_vel_z)) {
    _SFD_EML_CALL(0U, *c18_sfEvent, 15);
    c18_h_x = c18_vel_z - c18_thres_vel_z;
    c18_i_x = c18_h_x;
    c18_f_y = muDoubleScalarAbs(c18_i_x);
    c18_b_a = c18_K_gain;
    c18_b_b = c18_f_y;
    c18_g_y = c18_b_a * c18_b_b;
    c18_b_varargin_1 = c18_g_y;
    c18_c_varargin_2 = c18_maxDeltaWindow;
    c18_d_varargin_2 = c18_b_varargin_1;
    c18_b_varargin_3 = c18_c_varargin_2;
    c18_j_x = c18_d_varargin_2;
    c18_h_y = c18_b_varargin_3;
    c18_k_x = c18_j_x;
    c18_i_y = c18_h_y;
    c18_eml_scalar_eg(chartInstance);
    c18_b_xk = c18_k_x;
    c18_b_yk = c18_i_y;
    c18_l_x = c18_b_xk;
    c18_j_y = c18_b_yk;
    c18_eml_scalar_eg(chartInstance);
    c18_b_minval = muDoubleScalarMin(c18_l_x, c18_j_y);
    c18_nominal_window_z_out = c18_nominal_window_z - c18_b_minval;
  }

  _SFD_EML_CALL(0U, *c18_sfEvent, -15);
  sf_debug_symbol_scope_pop();
  *c18_b_nominal_window_z_out = c18_nominal_window_z_out;
  *c18_b_nominal_window_y_out = c18_nominal_window_y_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, *c18_sfEvent);
}

static void initSimStructsc18_controller_template
  (SFc18_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c18_machineNumber, uint32_T
  c18_chartNumber)
{
}

static const mxArray *c18_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  real_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc18_controller_templateInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(real_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, FALSE);
  return c18_mxArrayOutData;
}

static real_T c18_emlrt_marshallIn(SFc18_controller_templateInstanceStruct
  *chartInstance, const mxArray *c18_nominal_window_y_out, const char_T
  *c18_identifier)
{
  real_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_nominal_window_y_out), &c18_thisId);
  sf_mex_destroy(&c18_nominal_window_y_out);
  return c18_y;
}

static real_T c18_b_emlrt_marshallIn(SFc18_controller_templateInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  real_T c18_y;
  real_T c18_d0;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_d0, 1, 0, 0U, 0, 0U, 0);
  c18_y = c18_d0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_nominal_window_y_out;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  real_T c18_y;
  SFc18_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc18_controller_templateInstanceStruct *)chartInstanceVoid;
  c18_nominal_window_y_out = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_nominal_window_y_out), &c18_thisId);
  sf_mex_destroy(&c18_nominal_window_y_out);
  *(real_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

const mxArray *sf_c18_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c18_nameCaptureInfo;
  c18_ResolvedFunctionInfo c18_info[8];
  c18_ResolvedFunctionInfo (*c18_b_info)[8];
  const mxArray *c18_m0 = NULL;
  int32_T c18_i0;
  c18_ResolvedFunctionInfo *c18_r0;
  c18_nameCaptureInfo = NULL;
  c18_nameCaptureInfo = NULL;
  c18_b_info = (c18_ResolvedFunctionInfo (*)[8])c18_info;
  (*c18_b_info)[0].context = "";
  (*c18_b_info)[0].name = "abs";
  (*c18_b_info)[0].dominantType = "double";
  (*c18_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c18_b_info)[0].fileTimeLo = 1286818694U;
  (*c18_b_info)[0].fileTimeHi = 0U;
  (*c18_b_info)[0].mFileTimeLo = 0U;
  (*c18_b_info)[0].mFileTimeHi = 0U;
  (*c18_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c18_b_info)[1].name = "eml_scalar_abs";
  (*c18_b_info)[1].dominantType = "double";
  (*c18_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c18_b_info)[1].fileTimeLo = 1286818712U;
  (*c18_b_info)[1].fileTimeHi = 0U;
  (*c18_b_info)[1].mFileTimeLo = 0U;
  (*c18_b_info)[1].mFileTimeHi = 0U;
  (*c18_b_info)[2].context = "";
  (*c18_b_info)[2].name = "mtimes";
  (*c18_b_info)[2].dominantType = "double";
  (*c18_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c18_b_info)[2].fileTimeLo = 1289519692U;
  (*c18_b_info)[2].fileTimeHi = 0U;
  (*c18_b_info)[2].mFileTimeLo = 0U;
  (*c18_b_info)[2].mFileTimeHi = 0U;
  (*c18_b_info)[3].context = "";
  (*c18_b_info)[3].name = "min";
  (*c18_b_info)[3].dominantType = "double";
  (*c18_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  (*c18_b_info)[3].fileTimeLo = 1308747330U;
  (*c18_b_info)[3].fileTimeHi = 0U;
  (*c18_b_info)[3].mFileTimeLo = 0U;
  (*c18_b_info)[3].mFileTimeHi = 0U;
  (*c18_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  (*c18_b_info)[4].name = "eml_min_or_max";
  (*c18_b_info)[4].dominantType = "char";
  (*c18_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  (*c18_b_info)[4].fileTimeLo = 1303146212U;
  (*c18_b_info)[4].fileTimeHi = 0U;
  (*c18_b_info)[4].mFileTimeLo = 0U;
  (*c18_b_info)[4].mFileTimeHi = 0U;
  (*c18_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c18_b_info)[5].name = "eml_scalar_eg";
  (*c18_b_info)[5].dominantType = "double";
  (*c18_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c18_b_info)[5].fileTimeLo = 1286818796U;
  (*c18_b_info)[5].fileTimeHi = 0U;
  (*c18_b_info)[5].mFileTimeLo = 0U;
  (*c18_b_info)[5].mFileTimeHi = 0U;
  (*c18_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c18_b_info)[6].name = "eml_scalexp_alloc";
  (*c18_b_info)[6].dominantType = "double";
  (*c18_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  (*c18_b_info)[6].fileTimeLo = 1286818796U;
  (*c18_b_info)[6].fileTimeHi = 0U;
  (*c18_b_info)[6].mFileTimeLo = 0U;
  (*c18_b_info)[6].mFileTimeHi = 0U;
  (*c18_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  (*c18_b_info)[7].name = "eml_index_class";
  (*c18_b_info)[7].dominantType = "";
  (*c18_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c18_b_info)[7].fileTimeLo = 1286818778U;
  (*c18_b_info)[7].fileTimeHi = 0U;
  (*c18_b_info)[7].mFileTimeLo = 0U;
  (*c18_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c18_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c18_i0 = 0; c18_i0 < 8; c18_i0++) {
    c18_r0 = &c18_info[c18_i0];
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", c18_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c18_r0->context)), "context", "nameCaptureInfo",
                    c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", c18_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c18_r0->name)), "name", "nameCaptureInfo", c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo",
      c18_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c18_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", c18_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c18_r0->resolved)), "resolved",
                    "nameCaptureInfo", c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", &c18_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo", &c18_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo",
      &c18_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c18_i0);
    sf_mex_addfield(c18_m0, sf_mex_create("nameCaptureInfo",
      &c18_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c18_i0);
  }

  sf_mex_assign(&c18_nameCaptureInfo, c18_m0, FALSE);
  return c18_nameCaptureInfo;
}

static void c18_eml_scalar_eg(SFc18_controller_templateInstanceStruct
  *chartInstance)
{
}

static const mxArray *c18_b_sf_marshallOut(void *chartInstanceVoid, void
  *c18_inData)
{
  const mxArray *c18_mxArrayOutData = NULL;
  int32_T c18_u;
  const mxArray *c18_y = NULL;
  SFc18_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc18_controller_templateInstanceStruct *)chartInstanceVoid;
  c18_mxArrayOutData = NULL;
  c18_u = *(int32_T *)c18_inData;
  c18_y = NULL;
  sf_mex_assign(&c18_y, sf_mex_create("y", &c18_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c18_mxArrayOutData, c18_y, FALSE);
  return c18_mxArrayOutData;
}

static int32_T c18_c_emlrt_marshallIn(SFc18_controller_templateInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  int32_T c18_y;
  int32_T c18_i1;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_i1, 1, 6, 0U, 0, 0U, 0);
  c18_y = c18_i1;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void c18_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c18_mxArrayInData, const char_T *c18_varName, void *c18_outData)
{
  const mxArray *c18_sfEvent;
  const char_T *c18_identifier;
  emlrtMsgIdentifier c18_thisId;
  int32_T c18_y;
  SFc18_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc18_controller_templateInstanceStruct *)chartInstanceVoid;
  c18_sfEvent = sf_mex_dup(c18_mxArrayInData);
  c18_identifier = c18_varName;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c18_sfEvent),
    &c18_thisId);
  sf_mex_destroy(&c18_sfEvent);
  *(int32_T *)c18_outData = c18_y;
  sf_mex_destroy(&c18_mxArrayInData);
}

static uint8_T c18_d_emlrt_marshallIn(SFc18_controller_templateInstanceStruct
  *chartInstance, const mxArray *c18_is_active_c18_controller_template, const
  char_T *c18_identifier)
{
  uint8_T c18_y;
  emlrtMsgIdentifier c18_thisId;
  c18_thisId.fIdentifier = c18_identifier;
  c18_thisId.fParent = NULL;
  c18_y = c18_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c18_is_active_c18_controller_template), &c18_thisId);
  sf_mex_destroy(&c18_is_active_c18_controller_template);
  return c18_y;
}

static uint8_T c18_e_emlrt_marshallIn(SFc18_controller_templateInstanceStruct
  *chartInstance, const mxArray *c18_u, const emlrtMsgIdentifier *c18_parentId)
{
  uint8_T c18_y;
  uint8_T c18_u0;
  sf_mex_import(c18_parentId, sf_mex_dup(c18_u), &c18_u0, 1, 3, 0U, 0, 0U, 0);
  c18_y = c18_u0;
  sf_mex_destroy(&c18_u);
  return c18_y;
}

static void init_dsm_address_info(SFc18_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c18_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1729857014U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2998253613U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2921641526U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2439549249U);
}

mxArray *sf_c18_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("8Z64J0PISshKT3uTwYNdfC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
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

static const mxArray *sf_get_sim_state_info_c18_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[13],T\"nominal_window_y_out\",},{M[1],M[5],T\"nominal_window_z_out\",},{M[8],M[0],T\"is_active_c18_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c18_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc18_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc18_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           18,
           1,
           1,
           10,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"nominal_window_z");
          _SFD_SET_DATA_PROPS(1,2,0,1,"nominal_window_z_out");
          _SFD_SET_DATA_PROPS(2,1,1,0,"nominal_window_y");
          _SFD_SET_DATA_PROPS(3,1,1,0,"vel_z");
          _SFD_SET_DATA_PROPS(4,1,1,0,"vel_y");
          _SFD_SET_DATA_PROPS(5,1,1,0,"thres_vel_z");
          _SFD_SET_DATA_PROPS(6,1,1,0,"thres_vel_y");
          _SFD_SET_DATA_PROPS(7,1,1,0,"K_gain");
          _SFD_SET_DATA_PROPS(8,1,1,0,"maxDeltaWindow");
          _SFD_SET_DATA_PROPS(9,2,0,1,"nominal_window_y_out");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,547);
        _SFD_CV_INIT_EML_IF(0,1,0,284,307,-1,412);
        _SFD_CV_INIT_EML_IF(0,1,1,414,437,-1,542);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)c18_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c18_sf_marshallOut,(MexInFcnForType)c18_sf_marshallIn);

        {
          real_T *c18_nominal_window_z;
          real_T *c18_nominal_window_z_out;
          real_T *c18_nominal_window_y;
          real_T *c18_vel_z;
          real_T *c18_vel_y;
          real_T *c18_thres_vel_z;
          real_T *c18_thres_vel_y;
          real_T *c18_K_gain;
          real_T *c18_maxDeltaWindow;
          real_T *c18_nominal_window_y_out;
          c18_nominal_window_y_out = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 2);
          c18_maxDeltaWindow = (real_T *)ssGetInputPortSignal(chartInstance->S,
            7);
          c18_K_gain = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c18_thres_vel_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c18_thres_vel_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c18_vel_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c18_vel_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c18_nominal_window_y = (real_T *)ssGetInputPortSignal(chartInstance->S,
            1);
          c18_nominal_window_z_out = (real_T *)ssGetOutputPortSignal
            (chartInstance->S, 1);
          c18_nominal_window_z = (real_T *)ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, c18_nominal_window_z);
          _SFD_SET_DATA_VALUE_PTR(1U, c18_nominal_window_z_out);
          _SFD_SET_DATA_VALUE_PTR(2U, c18_nominal_window_y);
          _SFD_SET_DATA_VALUE_PTR(3U, c18_vel_z);
          _SFD_SET_DATA_VALUE_PTR(4U, c18_vel_y);
          _SFD_SET_DATA_VALUE_PTR(5U, c18_thres_vel_z);
          _SFD_SET_DATA_VALUE_PTR(6U, c18_thres_vel_y);
          _SFD_SET_DATA_VALUE_PTR(7U, c18_K_gain);
          _SFD_SET_DATA_VALUE_PTR(8U, c18_maxDeltaWindow);
          _SFD_SET_DATA_VALUE_PTR(9U, c18_nominal_window_y_out);
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
      18, "dworkChecksum");
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

static void sf_opaque_initialize_c18_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc18_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc18_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c18_controller_template
    ((SFc18_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c18_controller_template((SFc18_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c18_controller_template(void *chartInstanceVar)
{
  enable_c18_controller_template((SFc18_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c18_controller_template(void *chartInstanceVar)
{
  disable_c18_controller_template((SFc18_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c18_controller_template(void *chartInstanceVar)
{
  sf_c18_controller_template((SFc18_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c18_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c18_controller_template((SFc18_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c18_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c18_controller_template
    ((SFc18_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c18_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c18_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c18_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c18_controller_template((SFc18_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c18_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c18_controller_template(S);
}

static void sf_opaque_set_sim_state_c18_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c18_controller_template(S, st);
}

static void sf_opaque_terminate_c18_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc18_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c18_controller_template((SFc18_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc18_controller_template((SFc18_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c18_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c18_controller_template
      ((SFc18_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c18_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c18_controller_template\",T\"is_active_c18_controller_template\"}}"
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

static void mdlSetWorkWidths_c18_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,18);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,18,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,18,
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
      sf_mark_chart_expressionable_inputs(S,infoStruct,18,8);
      sf_mark_chart_reusable_outputs(S,infoStruct,18,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,18);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4152463482U));
  ssSetChecksum1(S,(2255333286U));
  ssSetChecksum2(S,(3539682983U));
  ssSetChecksum3(S,(1092918098U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c18_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c18_controller_template(SimStruct *S)
{
  SFc18_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc18_controller_templateInstanceStruct *)malloc(sizeof
    (SFc18_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc18_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c18_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c18_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c18_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c18_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c18_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c18_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c18_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c18_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c18_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c18_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c18_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c18_controller_template;
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

void c18_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c18_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c18_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c18_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c18_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
