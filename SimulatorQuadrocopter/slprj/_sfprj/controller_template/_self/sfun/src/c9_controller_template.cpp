/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c9_controller_template.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[13] = { "maxangle", "nargin",
  "nargout", "pitch_meas", "roll_meas", "pitch_cmd", "roll_cmd", "thrust", "m",
  "g", "pitch_cmd_comp", "roll_cmd_comp", "thrust_comp" };

/* Function Declarations */
static void initialize_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance);
static void enable_c9_controller_template(SFc9_controller_templateInstanceStruct
  *chartInstance);
static void disable_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance, const mxArray *c9_st);
static void finalize_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance);
static void sf_c9_controller_template(SFc9_controller_templateInstanceStruct
  *chartInstance);
static void initSimStructsc9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static real_T c9_emlrt_marshallIn(SFc9_controller_templateInstanceStruct
  *chartInstance, const mxArray *c9_thrust_comp, const char_T *c9_identifier);
static real_T c9_b_emlrt_marshallIn(SFc9_controller_templateInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_c_emlrt_marshallIn(SFc9_controller_templateInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_d_emlrt_marshallIn(SFc9_controller_templateInstanceStruct
  *chartInstance, const mxArray *c9_is_active_c9_controller_template, const
  char_T *c9_identifier);
static uint8_T c9_e_emlrt_marshallIn(SFc9_controller_templateInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c9_sfEvent;
  uint8_T *c9_is_active_c9_controller_template;
  c9_is_active_c9_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c9_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c9_is_active_c9_controller_template = 0U;
}

static void initialize_params_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c9_controller_template(SFc9_controller_templateInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance)
{
  c9_update_debugger_state_c9_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  uint8_T c9_d_hoistedGlobal;
  uint8_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  real_T *c9_pitch_cmd_comp;
  real_T *c9_roll_cmd_comp;
  real_T *c9_thrust_comp;
  uint8_T *c9_is_active_c9_controller_template;
  c9_thrust_comp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_roll_cmd_comp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_pitch_cmd_comp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_is_active_c9_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(4), FALSE);
  c9_hoistedGlobal = *c9_pitch_cmd_comp;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = *c9_roll_cmd_comp;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = *c9_thrust_comp;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_hoistedGlobal = *c9_is_active_c9_controller_template;
  c9_d_u = c9_d_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  boolean_T *c9_doneDoubleBufferReInit;
  real_T *c9_pitch_cmd_comp;
  real_T *c9_roll_cmd_comp;
  real_T *c9_thrust_comp;
  uint8_T *c9_is_active_c9_controller_template;
  c9_thrust_comp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_roll_cmd_comp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_pitch_cmd_comp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_is_active_c9_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c9_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  *c9_pitch_cmd_comp = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 0)), "pitch_cmd_comp");
  *c9_roll_cmd_comp = c9_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 1)), "roll_cmd_comp");
  *c9_thrust_comp = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 2)), "thrust_comp");
  *c9_is_active_c9_controller_template = c9_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 3)), "is_active_c9_controller_template");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_controller_template(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c9_controller_template(SFc9_controller_templateInstanceStruct
  *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_c_hoistedGlobal;
  real_T c9_d_hoistedGlobal;
  real_T c9_e_hoistedGlobal;
  real_T c9_f_hoistedGlobal;
  real_T c9_g_hoistedGlobal;
  real_T c9_pitch_meas;
  real_T c9_roll_meas;
  real_T c9_pitch_cmd;
  real_T c9_roll_cmd;
  real_T c9_thrust;
  real_T c9_m;
  real_T c9_g;
  uint32_T c9_debug_family_var_map[13];
  real_T c9_maxangle;
  real_T c9_nargin = 7.0;
  real_T c9_nargout = 3.0;
  real_T c9_pitch_cmd_comp;
  real_T c9_roll_cmd_comp;
  real_T c9_thrust_comp;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_y;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_b_y;
  real_T c9_e_x;
  real_T c9_f_x;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_a;
  real_T c9_b;
  real_T c9_c_y;
  real_T c9_A;
  real_T c9_B;
  real_T c9_i_x;
  real_T c9_d_y;
  real_T c9_j_x;
  real_T c9_e_y;
  real_T c9_b_a;
  real_T c9_b_b;
  real_T c9_f_y;
  real_T c9_b_A;
  real_T c9_b_B;
  real_T c9_k_x;
  real_T c9_g_y;
  real_T c9_l_x;
  real_T c9_h_y;
  real_T c9_i_y;
  real_T c9_c_a;
  real_T c9_c_b;
  real_T c9_d_a;
  real_T c9_d_b;
  real_T c9_j_y;
  real_T c9_c_A;
  real_T c9_c_B;
  real_T c9_m_x;
  real_T c9_k_y;
  real_T c9_n_x;
  real_T c9_l_y;
  real_T c9_m_y;
  real_T c9_e_a;
  real_T c9_e_b;
  real_T *c9_b_thrust_comp;
  real_T *c9_b_roll_cmd_comp;
  real_T *c9_b_pitch_cmd_comp;
  real_T *c9_b_g;
  real_T *c9_b_m;
  real_T *c9_b_thrust;
  real_T *c9_b_roll_cmd;
  real_T *c9_b_pitch_cmd;
  real_T *c9_b_roll_meas;
  real_T *c9_b_pitch_meas;
  int32_T *c9_sfEvent;
  boolean_T guard1 = FALSE;
  c9_b_g = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c9_b_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c9_b_thrust = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c9_b_roll_cmd = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c9_b_pitch_cmd = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c9_b_roll_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_thrust_comp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c9_b_pitch_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c9_b_roll_cmd_comp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_b_pitch_cmd_comp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, *c9_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c9_b_pitch_cmd_comp, 0U);
  _SFD_DATA_RANGE_CHECK(*c9_b_roll_cmd_comp, 1U);
  _SFD_DATA_RANGE_CHECK(*c9_b_pitch_meas, 2U);
  _SFD_DATA_RANGE_CHECK(*c9_b_thrust_comp, 3U);
  _SFD_DATA_RANGE_CHECK(*c9_b_roll_meas, 4U);
  _SFD_DATA_RANGE_CHECK(*c9_b_pitch_cmd, 5U);
  _SFD_DATA_RANGE_CHECK(*c9_b_roll_cmd, 6U);
  _SFD_DATA_RANGE_CHECK(*c9_b_thrust, 7U);
  _SFD_DATA_RANGE_CHECK(*c9_b_m, 8U);
  _SFD_DATA_RANGE_CHECK(*c9_b_g, 9U);
  *c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, *c9_sfEvent);
  c9_hoistedGlobal = *c9_b_pitch_meas;
  c9_b_hoistedGlobal = *c9_b_roll_meas;
  c9_c_hoistedGlobal = *c9_b_pitch_cmd;
  c9_d_hoistedGlobal = *c9_b_roll_cmd;
  c9_e_hoistedGlobal = *c9_b_thrust;
  c9_f_hoistedGlobal = *c9_b_m;
  c9_g_hoistedGlobal = *c9_b_g;
  c9_pitch_meas = c9_hoistedGlobal;
  c9_roll_meas = c9_b_hoistedGlobal;
  c9_pitch_cmd = c9_c_hoistedGlobal;
  c9_roll_cmd = c9_d_hoistedGlobal;
  c9_thrust = c9_e_hoistedGlobal;
  c9_m = c9_f_hoistedGlobal;
  c9_g = c9_g_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 13U, 13U, c9_debug_family_names,
    c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c9_maxangle, 0U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargin, 1U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargout, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c9_pitch_meas, 3U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_roll_meas, 4U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_pitch_cmd, 5U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_roll_cmd, 6U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_thrust, 7U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_m, 8U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_g, 9U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c9_pitch_cmd_comp, 10U,
    c9_sf_marshallOut, c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_roll_cmd_comp, 11U,
    c9_sf_marshallOut, c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_thrust_comp, 12U,
    c9_sf_marshallOut, c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c9_sfEvent, 3);
  c9_maxangle = 0.069813170079773182;
  _SFD_EML_CALL(0U, *c9_sfEvent, 4);
  c9_x = c9_pitch_meas;
  c9_b_x = c9_x;
  c9_y = muDoubleScalarAbs(c9_b_x);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c9_y <= c9_maxangle)) {
    c9_c_x = c9_roll_meas;
    c9_d_x = c9_c_x;
    c9_b_y = muDoubleScalarAbs(c9_d_x);
    if (CV_EML_COND(0, 1, 1, c9_b_y <= c9_maxangle)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 0, TRUE);
      _SFD_EML_CALL(0U, *c9_sfEvent, 5);
      c9_e_x = c9_pitch_meas;
      c9_f_x = c9_e_x;
      c9_f_x = muDoubleScalarCos(c9_f_x);
      c9_g_x = c9_roll_meas;
      c9_h_x = c9_g_x;
      c9_h_x = muDoubleScalarCos(c9_h_x);
      c9_a = c9_f_x;
      c9_b = c9_h_x;
      c9_c_y = c9_a * c9_b;
      c9_A = c9_thrust;
      c9_B = c9_c_y;
      c9_i_x = c9_A;
      c9_d_y = c9_B;
      c9_j_x = c9_i_x;
      c9_e_y = c9_d_y;
      c9_thrust_comp = c9_j_x / c9_e_y;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
    _SFD_EML_CALL(0U, *c9_sfEvent, 7);
    c9_thrust_comp = c9_thrust;
  }

  _SFD_EML_CALL(0U, *c9_sfEvent, 9);
  c9_b_a = c9_m;
  c9_b_b = c9_g;
  c9_f_y = c9_b_a * c9_b_b;
  c9_b_A = c9_f_y;
  c9_b_B = c9_thrust_comp;
  c9_k_x = c9_b_A;
  c9_g_y = c9_b_B;
  c9_l_x = c9_k_x;
  c9_h_y = c9_g_y;
  c9_i_y = c9_l_x / c9_h_y;
  c9_c_a = c9_i_y;
  c9_c_b = c9_pitch_cmd;
  c9_pitch_cmd_comp = c9_c_a * c9_c_b;
  _SFD_EML_CALL(0U, *c9_sfEvent, 10);
  c9_d_a = c9_m;
  c9_d_b = c9_g;
  c9_j_y = c9_d_a * c9_d_b;
  c9_c_A = c9_j_y;
  c9_c_B = c9_thrust_comp;
  c9_m_x = c9_c_A;
  c9_k_y = c9_c_B;
  c9_n_x = c9_m_x;
  c9_l_y = c9_k_y;
  c9_m_y = c9_n_x / c9_l_y;
  c9_e_a = c9_m_y;
  c9_e_b = c9_roll_cmd;
  c9_roll_cmd_comp = c9_e_a * c9_e_b;
  _SFD_EML_CALL(0U, *c9_sfEvent, -10);
  sf_debug_symbol_scope_pop();
  *c9_b_pitch_cmd_comp = c9_pitch_cmd_comp;
  *c9_b_roll_cmd_comp = c9_roll_cmd_comp;
  *c9_b_thrust_comp = c9_thrust_comp;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, *c9_sfEvent);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc9_controller_template
  (SFc9_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc9_controller_templateInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_emlrt_marshallIn(SFc9_controller_templateInstanceStruct
  *chartInstance, const mxArray *c9_thrust_comp, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_thrust_comp),
    &c9_thisId);
  sf_mex_destroy(&c9_thrust_comp);
  return c9_y;
}

static real_T c9_b_emlrt_marshallIn(SFc9_controller_templateInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_thrust_comp;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc9_controller_templateInstanceStruct *)chartInstanceVoid;
  c9_thrust_comp = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_thrust_comp),
    &c9_thisId);
  sf_mex_destroy(&c9_thrust_comp);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[8];
  c9_ResolvedFunctionInfo (*c9_b_info)[8];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i0;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_b_info = (c9_ResolvedFunctionInfo (*)[8])c9_info;
  (*c9_b_info)[0].context = "";
  (*c9_b_info)[0].name = "mtimes";
  (*c9_b_info)[0].dominantType = "double";
  (*c9_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c9_b_info)[0].fileTimeLo = 1289519692U;
  (*c9_b_info)[0].fileTimeHi = 0U;
  (*c9_b_info)[0].mFileTimeLo = 0U;
  (*c9_b_info)[0].mFileTimeHi = 0U;
  (*c9_b_info)[1].context = "";
  (*c9_b_info)[1].name = "mrdivide";
  (*c9_b_info)[1].dominantType = "double";
  (*c9_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c9_b_info)[1].fileTimeLo = 1310137456U;
  (*c9_b_info)[1].fileTimeHi = 0U;
  (*c9_b_info)[1].mFileTimeLo = 1289519692U;
  (*c9_b_info)[1].mFileTimeHi = 0U;
  (*c9_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c9_b_info)[2].name = "rdivide";
  (*c9_b_info)[2].dominantType = "double";
  (*c9_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c9_b_info)[2].fileTimeLo = 1286818844U;
  (*c9_b_info)[2].fileTimeHi = 0U;
  (*c9_b_info)[2].mFileTimeLo = 0U;
  (*c9_b_info)[2].mFileTimeHi = 0U;
  (*c9_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c9_b_info)[3].name = "eml_div";
  (*c9_b_info)[3].dominantType = "double";
  (*c9_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c9_b_info)[3].fileTimeLo = 1305318000U;
  (*c9_b_info)[3].fileTimeHi = 0U;
  (*c9_b_info)[3].mFileTimeLo = 0U;
  (*c9_b_info)[3].mFileTimeHi = 0U;
  (*c9_b_info)[4].context = "";
  (*c9_b_info)[4].name = "abs";
  (*c9_b_info)[4].dominantType = "double";
  (*c9_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c9_b_info)[4].fileTimeLo = 1286818694U;
  (*c9_b_info)[4].fileTimeHi = 0U;
  (*c9_b_info)[4].mFileTimeLo = 0U;
  (*c9_b_info)[4].mFileTimeHi = 0U;
  (*c9_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c9_b_info)[5].name = "eml_scalar_abs";
  (*c9_b_info)[5].dominantType = "double";
  (*c9_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c9_b_info)[5].fileTimeLo = 1286818712U;
  (*c9_b_info)[5].fileTimeHi = 0U;
  (*c9_b_info)[5].mFileTimeLo = 0U;
  (*c9_b_info)[5].mFileTimeHi = 0U;
  (*c9_b_info)[6].context = "";
  (*c9_b_info)[6].name = "cos";
  (*c9_b_info)[6].dominantType = "double";
  (*c9_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c9_b_info)[6].fileTimeLo = 1286818706U;
  (*c9_b_info)[6].fileTimeHi = 0U;
  (*c9_b_info)[6].mFileTimeLo = 0U;
  (*c9_b_info)[6].mFileTimeHi = 0U;
  (*c9_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c9_b_info)[7].name = "eml_scalar_cos";
  (*c9_b_info)[7].dominantType = "double";
  (*c9_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c9_b_info)[7].fileTimeLo = 1286818722U;
  (*c9_b_info)[7].fileTimeHi = 0U;
  (*c9_b_info)[7].mFileTimeLo = 0U;
  (*c9_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c9_i0 = 0; c9_i0 < 8; c9_i0++) {
    c9_r0 = &c9_info[c9_i0];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i0);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i0);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0, FALSE);
  return c9_nameCaptureInfo;
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc9_controller_templateInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_c_emlrt_marshallIn(SFc9_controller_templateInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i1;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i1, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i1;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc9_controller_templateInstanceStruct *)chartInstanceVoid;
  c9_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_sfEvent), &c9_thisId);
  sf_mex_destroy(&c9_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_d_emlrt_marshallIn(SFc9_controller_templateInstanceStruct
  *chartInstance, const mxArray *c9_is_active_c9_controller_template, const
  char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_is_active_c9_controller_template), &c9_thisId);
  sf_mex_destroy(&c9_is_active_c9_controller_template);
  return c9_y;
}

static uint8_T c9_e_emlrt_marshallIn(SFc9_controller_templateInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c9_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4204181179U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4164892740U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1950135001U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4060225975U);
}

mxArray *sf_c9_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("YRkARMLyYekixjHI65WvdH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c9_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[12],T\"pitch_cmd_comp\",},{M[1],M[13],T\"roll_cmd_comp\",},{M[1],M[5],T\"thrust_comp\",},{M[8],M[0],T\"is_active_c9_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc9_controller_templateInstanceStruct *) ((ChartInfoStruct
      *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           9,
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
          _SFD_SET_DATA_PROPS(0,2,0,1,"pitch_cmd_comp");
          _SFD_SET_DATA_PROPS(1,2,0,1,"roll_cmd_comp");
          _SFD_SET_DATA_PROPS(2,1,1,0,"pitch_meas");
          _SFD_SET_DATA_PROPS(3,2,0,1,"thrust_comp");
          _SFD_SET_DATA_PROPS(4,1,1,0,"roll_meas");
          _SFD_SET_DATA_PROPS(5,1,1,0,"pitch_cmd");
          _SFD_SET_DATA_PROPS(6,1,1,0,"roll_cmd");
          _SFD_SET_DATA_PROPS(7,1,1,0,"thrust");
          _SFD_SET_DATA_PROPS(8,1,1,0,"m");
          _SFD_SET_DATA_PROPS(9,1,1,0,"g");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,639);
        _SFD_CV_INIT_EML_IF(0,1,0,144,204,262,294);

        {
          static int condStart[] = { 147, 178 };

          static int condEnd[] = { 174, 204 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,147,204,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c9_pitch_cmd_comp;
          real_T *c9_roll_cmd_comp;
          real_T *c9_pitch_meas;
          real_T *c9_thrust_comp;
          real_T *c9_roll_meas;
          real_T *c9_pitch_cmd;
          real_T *c9_roll_cmd;
          real_T *c9_thrust;
          real_T *c9_m;
          real_T *c9_g;
          c9_g = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c9_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c9_thrust = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c9_roll_cmd = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c9_pitch_cmd = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c9_roll_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c9_thrust_comp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c9_pitch_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          c9_roll_cmd_comp = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c9_pitch_cmd_comp = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          _SFD_SET_DATA_VALUE_PTR(0U, c9_pitch_cmd_comp);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_roll_cmd_comp);
          _SFD_SET_DATA_VALUE_PTR(2U, c9_pitch_meas);
          _SFD_SET_DATA_VALUE_PTR(3U, c9_thrust_comp);
          _SFD_SET_DATA_VALUE_PTR(4U, c9_roll_meas);
          _SFD_SET_DATA_VALUE_PTR(5U, c9_pitch_cmd);
          _SFD_SET_DATA_VALUE_PTR(6U, c9_roll_cmd);
          _SFD_SET_DATA_VALUE_PTR(7U, c9_thrust);
          _SFD_SET_DATA_VALUE_PTR(8U, c9_m);
          _SFD_SET_DATA_VALUE_PTR(9U, c9_g);
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
      9, "dworkChecksum");
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

static void sf_opaque_initialize_c9_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc9_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc9_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_controller_template
    ((SFc9_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c9_controller_template((SFc9_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_controller_template(void *chartInstanceVar)
{
  enable_c9_controller_template((SFc9_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_controller_template(void *chartInstanceVar)
{
  disable_c9_controller_template((SFc9_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_controller_template(void *chartInstanceVar)
{
  sf_c9_controller_template((SFc9_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c9_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c9_controller_template((SFc9_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_controller_template(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_controller_template
    ((SFc9_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c9_controller_template(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_controller_template((SFc9_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c9_controller_template(S);
}

static void sf_opaque_set_sim_state_c9_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c9_controller_template(S, st);
}

static void sf_opaque_terminate_c9_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c9_controller_template((SFc9_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_controller_template((SFc9_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_controller_template
      ((SFc9_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c9_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c9_controller_template\",T\"is_active_c9_controller_template\"}}"
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

static void mdlSetWorkWidths_c9_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,9,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,9,7);
      sf_mark_chart_reusable_outputs(S,infoStruct,9,3);
    }

    sf_set_rtw_dwork_info(S,infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2600061697U));
  ssSetChecksum1(S,(770450991U));
  ssSetChecksum2(S,(2479495796U));
  ssSetChecksum3(S,(3040573729U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_controller_template(SimStruct *S)
{
  SFc9_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc9_controller_templateInstanceStruct *)malloc(sizeof
    (SFc9_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_controller_template;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c9_controller_template;
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

void c9_controller_template_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
