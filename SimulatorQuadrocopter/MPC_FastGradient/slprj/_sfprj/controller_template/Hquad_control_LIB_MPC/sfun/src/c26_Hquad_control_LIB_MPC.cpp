/* Include files */

#include "blascompat32.h"
#include "Hquad_control_LIB_MPC_sfun.h"
#include "c26_Hquad_control_LIB_MPC.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hquad_control_LIB_MPC_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c26_debug_family_names[15] = { "sin_yaw", "cos_yaw", "R",
  "temp", "nargin", "nargout", "roll", "pitch", "pitch_bias", "roll_bias", "yaw",
  "roll_rot", "pitch_rot", "pitch_bias_rot", "roll_bias_rot" };

/* Function Declarations */
static void initialize_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initialize_params_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void enable_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void disable_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c26_update_debugger_state_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void ext_mode_exec_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void set_sim_state_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray
   *c26_st);
static void finalize_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void sf_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c26_chartstep_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initSimStructsc26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber);
static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static real_T c26_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c26_roll_bias_rot, const char_T *c26_identifier);
static real_T c26_b_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static void c26_c_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[2]);
static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static void c26_d_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[4]);
static void c26_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static void c26_eml_scalar_eg(SFc26_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static const mxArray *c26_d_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData);
static int32_T c26_e_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void c26_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData);
static uint8_T c26_f_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c26_is_active_c26_Hquad_control_LIB_MPC, const
  char_T *c26_identifier);
static uint8_T c26_g_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId);
static void init_dsm_address_info(SFc26_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T *c26_sfEvent;
  uint8_T *c26_is_active_c26_Hquad_control_LIB_MPC;
  c26_is_active_c26_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c26_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c26_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c26_is_active_c26_Hquad_control_LIB_MPC = 0U;
}

static void initialize_params_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void enable_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c26_update_debugger_state_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  c26_update_debugger_state_c26_Hquad_control_LIB_MPC(chartInstance);
}

static const mxArray *get_sim_state_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  const mxArray *c26_st;
  const mxArray *c26_y = NULL;
  real_T c26_hoistedGlobal;
  real_T c26_u;
  const mxArray *c26_b_y = NULL;
  real_T c26_b_hoistedGlobal;
  real_T c26_b_u;
  const mxArray *c26_c_y = NULL;
  real_T c26_c_hoistedGlobal;
  real_T c26_c_u;
  const mxArray *c26_d_y = NULL;
  real_T c26_d_hoistedGlobal;
  real_T c26_d_u;
  const mxArray *c26_e_y = NULL;
  uint8_T c26_e_hoistedGlobal;
  uint8_T c26_e_u;
  const mxArray *c26_f_y = NULL;
  real_T *c26_pitch_bias_rot;
  real_T *c26_pitch_rot;
  real_T *c26_roll_bias_rot;
  real_T *c26_roll_rot;
  uint8_T *c26_is_active_c26_Hquad_control_LIB_MPC;
  c26_roll_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c26_pitch_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c26_pitch_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c26_roll_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c26_is_active_c26_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c26_st = NULL;
  c26_st = NULL;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_createcellarray(5), FALSE);
  c26_hoistedGlobal = *c26_pitch_bias_rot;
  c26_u = c26_hoistedGlobal;
  c26_b_y = NULL;
  sf_mex_assign(&c26_b_y, sf_mex_create("y", &c26_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c26_y, 0, c26_b_y);
  c26_b_hoistedGlobal = *c26_pitch_rot;
  c26_b_u = c26_b_hoistedGlobal;
  c26_c_y = NULL;
  sf_mex_assign(&c26_c_y, sf_mex_create("y", &c26_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c26_y, 1, c26_c_y);
  c26_c_hoistedGlobal = *c26_roll_bias_rot;
  c26_c_u = c26_c_hoistedGlobal;
  c26_d_y = NULL;
  sf_mex_assign(&c26_d_y, sf_mex_create("y", &c26_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c26_y, 2, c26_d_y);
  c26_d_hoistedGlobal = *c26_roll_rot;
  c26_d_u = c26_d_hoistedGlobal;
  c26_e_y = NULL;
  sf_mex_assign(&c26_e_y, sf_mex_create("y", &c26_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c26_y, 3, c26_e_y);
  c26_e_hoistedGlobal = *c26_is_active_c26_Hquad_control_LIB_MPC;
  c26_e_u = c26_e_hoistedGlobal;
  c26_f_y = NULL;
  sf_mex_assign(&c26_f_y, sf_mex_create("y", &c26_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c26_y, 4, c26_f_y);
  sf_mex_assign(&c26_st, c26_y, FALSE);
  return c26_st;
}

static void set_sim_state_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray
   *c26_st)
{
  const mxArray *c26_u;
  boolean_T *c26_doneDoubleBufferReInit;
  real_T *c26_pitch_bias_rot;
  real_T *c26_pitch_rot;
  real_T *c26_roll_bias_rot;
  real_T *c26_roll_rot;
  uint8_T *c26_is_active_c26_Hquad_control_LIB_MPC;
  c26_roll_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c26_pitch_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c26_pitch_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c26_roll_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c26_is_active_c26_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c26_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c26_doneDoubleBufferReInit = TRUE;
  c26_u = sf_mex_dup(c26_st);
  *c26_pitch_bias_rot = c26_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c26_u, 0)), "pitch_bias_rot");
  *c26_pitch_rot = c26_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c26_u, 1)), "pitch_rot");
  *c26_roll_bias_rot = c26_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c26_u, 2)), "roll_bias_rot");
  *c26_roll_rot = c26_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c26_u, 3)), "roll_rot");
  *c26_is_active_c26_Hquad_control_LIB_MPC = c26_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c26_u, 4)),
     "is_active_c26_Hquad_control_LIB_MPC");
  sf_mex_destroy(&c26_u);
  c26_update_debugger_state_c26_Hquad_control_LIB_MPC(chartInstance);
  sf_mex_destroy(&c26_st);
}

static void finalize_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void sf_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T *c26_sfEvent;
  real_T *c26_roll;
  real_T *c26_pitch;
  real_T *c26_pitch_bias;
  real_T *c26_roll_bias;
  real_T *c26_roll_rot;
  real_T *c26_yaw;
  real_T *c26_pitch_rot;
  real_T *c26_pitch_bias_rot;
  real_T *c26_roll_bias_rot;
  c26_roll_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c26_pitch_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c26_pitch_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c26_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c26_roll_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c26_roll_bias = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c26_pitch_bias = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c26_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c26_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c26_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, *c26_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c26_roll, 0U);
  _SFD_DATA_RANGE_CHECK(*c26_pitch, 1U);
  _SFD_DATA_RANGE_CHECK(*c26_pitch_bias, 2U);
  _SFD_DATA_RANGE_CHECK(*c26_roll_bias, 3U);
  _SFD_DATA_RANGE_CHECK(*c26_roll_rot, 4U);
  _SFD_DATA_RANGE_CHECK(*c26_yaw, 5U);
  _SFD_DATA_RANGE_CHECK(*c26_pitch_rot, 6U);
  _SFD_DATA_RANGE_CHECK(*c26_pitch_bias_rot, 7U);
  _SFD_DATA_RANGE_CHECK(*c26_roll_bias_rot, 8U);
  *c26_sfEvent = CALL_EVENT;
  c26_chartstep_c26_Hquad_control_LIB_MPC(chartInstance);
  sf_debug_check_for_state_inconsistency(_Hquad_control_LIB_MPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c26_chartstep_c26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  real_T c26_hoistedGlobal;
  real_T c26_b_hoistedGlobal;
  real_T c26_c_hoistedGlobal;
  real_T c26_d_hoistedGlobal;
  real_T c26_e_hoistedGlobal;
  real_T c26_roll;
  real_T c26_pitch;
  real_T c26_pitch_bias;
  real_T c26_roll_bias;
  real_T c26_yaw;
  uint32_T c26_debug_family_var_map[15];
  real_T c26_sin_yaw;
  real_T c26_cos_yaw;
  real_T c26_R[4];
  real_T c26_temp[2];
  real_T c26_nargin = 5.0;
  real_T c26_nargout = 4.0;
  real_T c26_roll_rot;
  real_T c26_pitch_rot;
  real_T c26_pitch_bias_rot;
  real_T c26_roll_bias_rot;
  real_T c26_x;
  real_T c26_b_x;
  real_T c26_c_x;
  real_T c26_d_x;
  int32_T c26_i0;
  real_T c26_a[4];
  real_T c26_b[2];
  int32_T c26_i1;
  int32_T c26_i2;
  int32_T c26_i3;
  real_T c26_C[2];
  int32_T c26_i4;
  int32_T c26_i5;
  int32_T c26_i6;
  int32_T c26_i7;
  int32_T c26_i8;
  int32_T c26_i9;
  int32_T c26_i10;
  int32_T c26_i11;
  int32_T c26_i12;
  int32_T c26_i13;
  int32_T c26_i14;
  int32_T c26_i15;
  int32_T c26_i16;
  int32_T c26_i17;
  int32_T c26_i18;
  int32_T c26_i19;
  real_T *c26_b_roll;
  real_T *c26_b_pitch;
  real_T *c26_b_pitch_bias;
  real_T *c26_b_roll_bias;
  real_T *c26_b_yaw;
  real_T *c26_b_roll_rot;
  real_T *c26_b_pitch_rot;
  real_T *c26_b_pitch_bias_rot;
  real_T *c26_b_roll_bias_rot;
  int32_T *c26_sfEvent;
  c26_b_roll_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c26_b_pitch_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c26_b_pitch_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c26_b_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c26_b_roll_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c26_b_roll_bias = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c26_b_pitch_bias = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c26_b_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c26_b_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c26_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, *c26_sfEvent);
  c26_hoistedGlobal = *c26_b_roll;
  c26_b_hoistedGlobal = *c26_b_pitch;
  c26_c_hoistedGlobal = *c26_b_pitch_bias;
  c26_d_hoistedGlobal = *c26_b_roll_bias;
  c26_e_hoistedGlobal = *c26_b_yaw;
  c26_roll = c26_hoistedGlobal;
  c26_pitch = c26_b_hoistedGlobal;
  c26_pitch_bias = c26_c_hoistedGlobal;
  c26_roll_bias = c26_d_hoistedGlobal;
  c26_yaw = c26_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 15U, 15U, c26_debug_family_names,
    c26_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c26_sin_yaw, 0U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c26_cos_yaw, 1U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c26_R, 2U, c26_c_sf_marshallOut,
    c26_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c26_temp, 3U, c26_b_sf_marshallOut,
    c26_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c26_nargin, 4U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c26_nargout, 5U, c26_sf_marshallOut,
    c26_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c26_roll, 6U, c26_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c26_pitch, 7U, c26_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c26_pitch_bias, 8U, c26_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c26_roll_bias, 9U, c26_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c26_yaw, 10U, c26_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c26_roll_rot, 11U,
    c26_sf_marshallOut, c26_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c26_pitch_rot, 12U,
    c26_sf_marshallOut, c26_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c26_pitch_bias_rot, 13U,
    c26_sf_marshallOut, c26_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c26_roll_bias_rot, 14U,
    c26_sf_marshallOut, c26_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c26_sfEvent, 5);
  c26_x = c26_yaw;
  c26_sin_yaw = c26_x;
  c26_b_x = c26_sin_yaw;
  c26_sin_yaw = c26_b_x;
  c26_sin_yaw = muDoubleScalarSin(c26_sin_yaw);
  _SFD_EML_CALL(0U, *c26_sfEvent, 6);
  c26_c_x = c26_yaw;
  c26_cos_yaw = c26_c_x;
  c26_d_x = c26_cos_yaw;
  c26_cos_yaw = c26_d_x;
  c26_cos_yaw = muDoubleScalarCos(c26_cos_yaw);
  _SFD_EML_CALL(0U, *c26_sfEvent, 8);
  c26_R[0] = c26_cos_yaw;
  c26_R[2] = c26_sin_yaw;
  c26_R[1] = -c26_sin_yaw;
  c26_R[3] = c26_cos_yaw;
  _SFD_EML_CALL(0U, *c26_sfEvent, 10);
  for (c26_i0 = 0; c26_i0 < 4; c26_i0++) {
    c26_a[c26_i0] = c26_R[c26_i0];
  }

  c26_b[0] = c26_pitch;
  c26_b[1] = c26_roll;
  c26_eml_scalar_eg(chartInstance);
  c26_eml_scalar_eg(chartInstance);
  for (c26_i1 = 0; c26_i1 < 2; c26_i1++) {
    c26_temp[c26_i1] = 0.0;
  }

  for (c26_i2 = 0; c26_i2 < 2; c26_i2++) {
    c26_temp[c26_i2] = 0.0;
  }

  for (c26_i3 = 0; c26_i3 < 2; c26_i3++) {
    c26_C[c26_i3] = c26_temp[c26_i3];
  }

  for (c26_i4 = 0; c26_i4 < 2; c26_i4++) {
    c26_temp[c26_i4] = c26_C[c26_i4];
  }

  for (c26_i5 = 0; c26_i5 < 2; c26_i5++) {
    c26_C[c26_i5] = c26_temp[c26_i5];
  }

  for (c26_i6 = 0; c26_i6 < 2; c26_i6++) {
    c26_temp[c26_i6] = c26_C[c26_i6];
  }

  for (c26_i7 = 0; c26_i7 < 2; c26_i7++) {
    c26_temp[c26_i7] = 0.0;
    c26_i8 = 0;
    for (c26_i9 = 0; c26_i9 < 2; c26_i9++) {
      c26_temp[c26_i7] += c26_a[c26_i8 + c26_i7] * c26_b[c26_i9];
      c26_i8 += 2;
    }
  }

  _SFD_EML_CALL(0U, *c26_sfEvent, 11);
  c26_pitch_rot = c26_temp[0];
  _SFD_EML_CALL(0U, *c26_sfEvent, 12);
  c26_roll_rot = c26_temp[1];
  _SFD_EML_CALL(0U, *c26_sfEvent, 14);
  for (c26_i10 = 0; c26_i10 < 4; c26_i10++) {
    c26_a[c26_i10] = c26_R[c26_i10];
  }

  c26_b[0] = c26_pitch_bias;
  c26_b[1] = c26_roll_bias;
  c26_eml_scalar_eg(chartInstance);
  c26_eml_scalar_eg(chartInstance);
  for (c26_i11 = 0; c26_i11 < 2; c26_i11++) {
    c26_temp[c26_i11] = 0.0;
  }

  for (c26_i12 = 0; c26_i12 < 2; c26_i12++) {
    c26_temp[c26_i12] = 0.0;
  }

  for (c26_i13 = 0; c26_i13 < 2; c26_i13++) {
    c26_C[c26_i13] = c26_temp[c26_i13];
  }

  for (c26_i14 = 0; c26_i14 < 2; c26_i14++) {
    c26_temp[c26_i14] = c26_C[c26_i14];
  }

  for (c26_i15 = 0; c26_i15 < 2; c26_i15++) {
    c26_C[c26_i15] = c26_temp[c26_i15];
  }

  for (c26_i16 = 0; c26_i16 < 2; c26_i16++) {
    c26_temp[c26_i16] = c26_C[c26_i16];
  }

  for (c26_i17 = 0; c26_i17 < 2; c26_i17++) {
    c26_temp[c26_i17] = 0.0;
    c26_i18 = 0;
    for (c26_i19 = 0; c26_i19 < 2; c26_i19++) {
      c26_temp[c26_i17] += c26_a[c26_i18 + c26_i17] * c26_b[c26_i19];
      c26_i18 += 2;
    }
  }

  _SFD_EML_CALL(0U, *c26_sfEvent, 15);
  c26_pitch_bias_rot = c26_temp[0];
  _SFD_EML_CALL(0U, *c26_sfEvent, 16);
  c26_roll_bias_rot = c26_temp[1];
  _SFD_EML_CALL(0U, *c26_sfEvent, -16);
  sf_debug_symbol_scope_pop();
  *c26_b_roll_rot = c26_roll_rot;
  *c26_b_pitch_rot = c26_pitch_rot;
  *c26_b_pitch_bias_rot = c26_pitch_bias_rot;
  *c26_b_roll_bias_rot = c26_roll_bias_rot;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, *c26_sfEvent);
}

static void initSimStructsc26_Hquad_control_LIB_MPC
  (SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c26_machineNumber, uint32_T
  c26_chartNumber)
{
}

static const mxArray *c26_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  real_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc26_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(real_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static real_T c26_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c26_roll_bias_rot, const char_T *c26_identifier)
{
  real_T c26_y;
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_roll_bias_rot),
    &c26_thisId);
  sf_mex_destroy(&c26_roll_bias_rot);
  return c26_y;
}

static real_T c26_b_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  real_T c26_y;
  real_T c26_d0;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_d0, 1, 0, 0U, 0, 0U, 0);
  c26_y = c26_d0;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_roll_bias_rot;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y;
  SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc26_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c26_roll_bias_rot = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_roll_bias_rot),
    &c26_thisId);
  sf_mex_destroy(&c26_roll_bias_rot);
  *(real_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_b_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i20;
  real_T c26_b_inData[2];
  int32_T c26_i21;
  real_T c26_u[2];
  const mxArray *c26_y = NULL;
  SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc26_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  for (c26_i20 = 0; c26_i20 < 2; c26_i20++) {
    c26_b_inData[c26_i20] = (*(real_T (*)[2])c26_inData)[c26_i20];
  }

  for (c26_i21 = 0; c26_i21 < 2; c26_i21++) {
    c26_u[c26_i21] = c26_b_inData[c26_i21];
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static void c26_c_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[2])
{
  real_T c26_dv0[2];
  int32_T c26_i22;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_dv0, 1, 0, 0U, 1, 0U, 1, 2);
  for (c26_i22 = 0; c26_i22 < 2; c26_i22++) {
    c26_y[c26_i22] = c26_dv0[c26_i22];
  }

  sf_mex_destroy(&c26_u);
}

static void c26_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_temp;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y[2];
  int32_T c26_i23;
  SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc26_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c26_temp = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_temp), &c26_thisId, c26_y);
  sf_mex_destroy(&c26_temp);
  for (c26_i23 = 0; c26_i23 < 2; c26_i23++) {
    (*(real_T (*)[2])c26_outData)[c26_i23] = c26_y[c26_i23];
  }

  sf_mex_destroy(&c26_mxArrayInData);
}

static const mxArray *c26_c_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_i24;
  int32_T c26_i25;
  int32_T c26_i26;
  real_T c26_b_inData[4];
  int32_T c26_i27;
  int32_T c26_i28;
  int32_T c26_i29;
  real_T c26_u[4];
  const mxArray *c26_y = NULL;
  SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc26_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_i24 = 0;
  for (c26_i25 = 0; c26_i25 < 2; c26_i25++) {
    for (c26_i26 = 0; c26_i26 < 2; c26_i26++) {
      c26_b_inData[c26_i26 + c26_i24] = (*(real_T (*)[4])c26_inData)[c26_i26 +
        c26_i24];
    }

    c26_i24 += 2;
  }

  c26_i27 = 0;
  for (c26_i28 = 0; c26_i28 < 2; c26_i28++) {
    for (c26_i29 = 0; c26_i29 < 2; c26_i29++) {
      c26_u[c26_i29 + c26_i27] = c26_b_inData[c26_i29 + c26_i27];
    }

    c26_i27 += 2;
  }

  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", c26_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static void c26_d_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId,
  real_T c26_y[4])
{
  real_T c26_dv1[4];
  int32_T c26_i30;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), c26_dv1, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c26_i30 = 0; c26_i30 < 4; c26_i30++) {
    c26_y[c26_i30] = c26_dv1[c26_i30];
  }

  sf_mex_destroy(&c26_u);
}

static void c26_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_R;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  real_T c26_y[4];
  int32_T c26_i31;
  int32_T c26_i32;
  int32_T c26_i33;
  SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc26_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c26_R = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_R), &c26_thisId, c26_y);
  sf_mex_destroy(&c26_R);
  c26_i31 = 0;
  for (c26_i32 = 0; c26_i32 < 2; c26_i32++) {
    for (c26_i33 = 0; c26_i33 < 2; c26_i33++) {
      (*(real_T (*)[4])c26_outData)[c26_i33 + c26_i31] = c26_y[c26_i33 + c26_i31];
    }

    c26_i31 += 2;
  }

  sf_mex_destroy(&c26_mxArrayInData);
}

const mxArray *sf_c26_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c26_nameCaptureInfo;
  c26_ResolvedFunctionInfo c26_info[10];
  c26_ResolvedFunctionInfo (*c26_b_info)[10];
  const mxArray *c26_m0 = NULL;
  int32_T c26_i34;
  c26_ResolvedFunctionInfo *c26_r0;
  c26_nameCaptureInfo = NULL;
  c26_nameCaptureInfo = NULL;
  c26_b_info = (c26_ResolvedFunctionInfo (*)[10])c26_info;
  (*c26_b_info)[0].context = "";
  (*c26_b_info)[0].name = "sin";
  (*c26_b_info)[0].dominantType = "double";
  (*c26_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c26_b_info)[0].fileTimeLo = 1286818750U;
  (*c26_b_info)[0].fileTimeHi = 0U;
  (*c26_b_info)[0].mFileTimeLo = 0U;
  (*c26_b_info)[0].mFileTimeHi = 0U;
  (*c26_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c26_b_info)[1].name = "eml_scalar_sin";
  (*c26_b_info)[1].dominantType = "double";
  (*c26_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c26_b_info)[1].fileTimeLo = 1286818736U;
  (*c26_b_info)[1].fileTimeHi = 0U;
  (*c26_b_info)[1].mFileTimeLo = 0U;
  (*c26_b_info)[1].mFileTimeHi = 0U;
  (*c26_b_info)[2].context = "";
  (*c26_b_info)[2].name = "cos";
  (*c26_b_info)[2].dominantType = "double";
  (*c26_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c26_b_info)[2].fileTimeLo = 1286818706U;
  (*c26_b_info)[2].fileTimeHi = 0U;
  (*c26_b_info)[2].mFileTimeLo = 0U;
  (*c26_b_info)[2].mFileTimeHi = 0U;
  (*c26_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c26_b_info)[3].name = "eml_scalar_cos";
  (*c26_b_info)[3].dominantType = "double";
  (*c26_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c26_b_info)[3].fileTimeLo = 1286818722U;
  (*c26_b_info)[3].fileTimeHi = 0U;
  (*c26_b_info)[3].mFileTimeLo = 0U;
  (*c26_b_info)[3].mFileTimeHi = 0U;
  (*c26_b_info)[4].context = "";
  (*c26_b_info)[4].name = "mtimes";
  (*c26_b_info)[4].dominantType = "double";
  (*c26_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c26_b_info)[4].fileTimeLo = 1289519692U;
  (*c26_b_info)[4].fileTimeHi = 0U;
  (*c26_b_info)[4].mFileTimeLo = 0U;
  (*c26_b_info)[4].mFileTimeHi = 0U;
  (*c26_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c26_b_info)[5].name = "eml_index_class";
  (*c26_b_info)[5].dominantType = "";
  (*c26_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c26_b_info)[5].fileTimeLo = 1286818778U;
  (*c26_b_info)[5].fileTimeHi = 0U;
  (*c26_b_info)[5].mFileTimeLo = 0U;
  (*c26_b_info)[5].mFileTimeHi = 0U;
  (*c26_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c26_b_info)[6].name = "eml_scalar_eg";
  (*c26_b_info)[6].dominantType = "double";
  (*c26_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c26_b_info)[6].fileTimeLo = 1286818796U;
  (*c26_b_info)[6].fileTimeHi = 0U;
  (*c26_b_info)[6].mFileTimeLo = 0U;
  (*c26_b_info)[6].mFileTimeHi = 0U;
  (*c26_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c26_b_info)[7].name = "eml_xgemm";
  (*c26_b_info)[7].dominantType = "int32";
  (*c26_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c26_b_info)[7].fileTimeLo = 1299076772U;
  (*c26_b_info)[7].fileTimeHi = 0U;
  (*c26_b_info)[7].mFileTimeLo = 0U;
  (*c26_b_info)[7].mFileTimeHi = 0U;
  (*c26_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c26_b_info)[8].name = "eml_blas_inline";
  (*c26_b_info)[8].dominantType = "";
  (*c26_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c26_b_info)[8].fileTimeLo = 1299076768U;
  (*c26_b_info)[8].fileTimeHi = 0U;
  (*c26_b_info)[8].mFileTimeLo = 0U;
  (*c26_b_info)[8].mFileTimeHi = 0U;
  (*c26_b_info)[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c26_b_info)[9].name = "eml_refblas_xgemm";
  (*c26_b_info)[9].dominantType = "int32";
  (*c26_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c26_b_info)[9].fileTimeLo = 1299076774U;
  (*c26_b_info)[9].fileTimeHi = 0U;
  (*c26_b_info)[9].mFileTimeLo = 0U;
  (*c26_b_info)[9].mFileTimeHi = 0U;
  sf_mex_assign(&c26_m0, sf_mex_createstruct("nameCaptureInfo", 1, 10), FALSE);
  for (c26_i34 = 0; c26_i34 < 10; c26_i34++) {
    c26_r0 = &c26_info[c26_i34];
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", c26_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c26_r0->context)), "context", "nameCaptureInfo",
                    c26_i34);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", c26_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c26_r0->name)), "name", "nameCaptureInfo",
                    c26_i34);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo",
      c26_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c26_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c26_i34);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", c26_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c26_r0->resolved)), "resolved",
                    "nameCaptureInfo", c26_i34);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", &c26_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c26_i34);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo", &c26_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c26_i34);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo",
      &c26_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c26_i34);
    sf_mex_addfield(c26_m0, sf_mex_create("nameCaptureInfo",
      &c26_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c26_i34);
  }

  sf_mex_assign(&c26_nameCaptureInfo, c26_m0, FALSE);
  return c26_nameCaptureInfo;
}

static void c26_eml_scalar_eg(SFc26_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static const mxArray *c26_d_sf_marshallOut(void *chartInstanceVoid, void
  *c26_inData)
{
  const mxArray *c26_mxArrayOutData = NULL;
  int32_T c26_u;
  const mxArray *c26_y = NULL;
  SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc26_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c26_mxArrayOutData = NULL;
  c26_u = *(int32_T *)c26_inData;
  c26_y = NULL;
  sf_mex_assign(&c26_y, sf_mex_create("y", &c26_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c26_mxArrayOutData, c26_y, FALSE);
  return c26_mxArrayOutData;
}

static int32_T c26_e_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  int32_T c26_y;
  int32_T c26_i35;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_i35, 1, 6, 0U, 0, 0U, 0);
  c26_y = c26_i35;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void c26_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c26_mxArrayInData, const char_T *c26_varName, void *c26_outData)
{
  const mxArray *c26_sfEvent;
  const char_T *c26_identifier;
  emlrtMsgIdentifier c26_thisId;
  int32_T c26_y;
  SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc26_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c26_sfEvent = sf_mex_dup(c26_mxArrayInData);
  c26_identifier = c26_varName;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c26_sfEvent),
    &c26_thisId);
  sf_mex_destroy(&c26_sfEvent);
  *(int32_T *)c26_outData = c26_y;
  sf_mex_destroy(&c26_mxArrayInData);
}

static uint8_T c26_f_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c26_is_active_c26_Hquad_control_LIB_MPC, const
  char_T *c26_identifier)
{
  uint8_T c26_y;
  emlrtMsgIdentifier c26_thisId;
  c26_thisId.fIdentifier = c26_identifier;
  c26_thisId.fParent = NULL;
  c26_y = c26_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c26_is_active_c26_Hquad_control_LIB_MPC), &c26_thisId);
  sf_mex_destroy(&c26_is_active_c26_Hquad_control_LIB_MPC);
  return c26_y;
}

static uint8_T c26_g_emlrt_marshallIn(SFc26_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c26_u, const emlrtMsgIdentifier *c26_parentId)
{
  uint8_T c26_y;
  uint8_T c26_u0;
  sf_mex_import(c26_parentId, sf_mex_dup(c26_u), &c26_u0, 1, 3, 0U, 0, 0U, 0);
  c26_y = c26_u0;
  sf_mex_destroy(&c26_u);
  return c26_y;
}

static void init_dsm_address_info(SFc26_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c26_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(468685498U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2714723740U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1246709291U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4173077130U);
}

mxArray *sf_c26_Hquad_control_LIB_MPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("7RzKZXjuoXTy7F5GxUZfPG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c26_Hquad_control_LIB_MPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[20],T\"pitch_bias_rot\",},{M[1],M[8],T\"pitch_rot\",},{M[1],M[21],T\"roll_bias_rot\",},{M[1],M[5],T\"roll_rot\",},{M[8],M[0],T\"is_active_c26_Hquad_control_LIB_MPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c26_Hquad_control_LIB_MPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
    chartInstance = (SFc26_Hquad_control_LIB_MPCInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Hquad_control_LIB_MPCMachineNumber_,
           26,
           1,
           1,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"roll");
          _SFD_SET_DATA_PROPS(1,1,1,0,"pitch");
          _SFD_SET_DATA_PROPS(2,1,1,0,"pitch_bias");
          _SFD_SET_DATA_PROPS(3,1,1,0,"roll_bias");
          _SFD_SET_DATA_PROPS(4,2,0,1,"roll_rot");
          _SFD_SET_DATA_PROPS(5,1,1,0,"yaw");
          _SFD_SET_DATA_PROPS(6,2,0,1,"pitch_rot");
          _SFD_SET_DATA_PROPS(7,2,0,1,"pitch_bias_rot");
          _SFD_SET_DATA_PROPS(8,2,0,1,"roll_bias_rot");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,325);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)c26_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)c26_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)c26_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c26_sf_marshallOut,(MexInFcnForType)c26_sf_marshallIn);

        {
          real_T *c26_roll;
          real_T *c26_pitch;
          real_T *c26_pitch_bias;
          real_T *c26_roll_bias;
          real_T *c26_roll_rot;
          real_T *c26_yaw;
          real_T *c26_pitch_rot;
          real_T *c26_pitch_bias_rot;
          real_T *c26_roll_bias_rot;
          c26_roll_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            4);
          c26_pitch_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            3);
          c26_pitch_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c26_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c26_roll_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c26_roll_bias = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c26_pitch_bias = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c26_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c26_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c26_roll);
          _SFD_SET_DATA_VALUE_PTR(1U, c26_pitch);
          _SFD_SET_DATA_VALUE_PTR(2U, c26_pitch_bias);
          _SFD_SET_DATA_VALUE_PTR(3U, c26_roll_bias);
          _SFD_SET_DATA_VALUE_PTR(4U, c26_roll_rot);
          _SFD_SET_DATA_VALUE_PTR(5U, c26_yaw);
          _SFD_SET_DATA_VALUE_PTR(6U, c26_pitch_rot);
          _SFD_SET_DATA_VALUE_PTR(7U, c26_pitch_bias_rot);
          _SFD_SET_DATA_VALUE_PTR(8U, c26_roll_bias_rot);
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
      26, "dworkChecksum");
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

static void sf_opaque_initialize_c26_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc26_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc26_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c26_Hquad_control_LIB_MPC
    ((SFc26_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
  initialize_c26_Hquad_control_LIB_MPC
    ((SFc26_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c26_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  enable_c26_Hquad_control_LIB_MPC((SFc26_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c26_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  disable_c26_Hquad_control_LIB_MPC((SFc26_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c26_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_c26_Hquad_control_LIB_MPC((SFc26_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c26_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  ext_mode_exec_c26_Hquad_control_LIB_MPC
    ((SFc26_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c26_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c26_Hquad_control_LIB_MPC
    ((SFc26_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c26_Hquad_control_LIB_MPC();/* state var info */
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

extern void sf_internal_set_sim_state_c26_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c26_Hquad_control_LIB_MPC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c26_Hquad_control_LIB_MPC
    ((SFc26_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c26_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c26_Hquad_control_LIB_MPC(S);
}

static void sf_opaque_set_sim_state_c26_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c26_Hquad_control_LIB_MPC(S, st);
}

static void sf_opaque_terminate_c26_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc26_Hquad_control_LIB_MPCInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c26_Hquad_control_LIB_MPC
      ((SFc26_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Hquad_control_LIB_MPC_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc26_Hquad_control_LIB_MPC
    ((SFc26_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c26_Hquad_control_LIB_MPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c26_Hquad_control_LIB_MPC
      ((SFc26_Hquad_control_LIB_MPCInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c26_Hquad_control_LIB_MPC_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c26_Hquad_control_LIB_MPC\",T\"is_active_c26_Hquad_control_LIB_MPC\"}}"
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

static void mdlSetWorkWidths_c26_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,26);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,26,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,26,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,26,5);
      sf_mark_chart_reusable_outputs(S,infoStruct,26,4);
    }

    sf_set_rtw_dwork_info(S,infoStruct,26);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(845117381U));
  ssSetChecksum1(S,(4280209114U));
  ssSetChecksum2(S,(127098531U));
  ssSetChecksum3(S,(932477860U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c26_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c26_Hquad_control_LIB_MPC(SimStruct *S)
{
  SFc26_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc26_Hquad_control_LIB_MPCInstanceStruct *)malloc(sizeof
    (SFc26_Hquad_control_LIB_MPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc26_Hquad_control_LIB_MPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c26_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c26_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c26_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c26_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c26_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c26_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c26_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c26_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c26_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c26_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c26_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c26_Hquad_control_LIB_MPC;
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

void c26_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c26_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c26_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c26_Hquad_control_LIB_MPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c26_Hquad_control_LIB_MPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
