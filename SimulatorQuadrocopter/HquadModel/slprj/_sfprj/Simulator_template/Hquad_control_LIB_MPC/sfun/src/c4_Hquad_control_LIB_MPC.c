/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Hquad_control_LIB_MPC_sfun.h"
#include "c4_Hquad_control_LIB_MPC.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hquad_control_LIB_MPC_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c4_debug_family_names[15] = { "sin_yaw", "cos_yaw", "R",
  "temp", "nargin", "nargout", "yaw", "pitch_cmd", "roll_cmd", "pitch_bias",
  "roll_bias", "pitch_rot", "roll_rot", "pitch_bias_rot", "roll_bias_rot" };

/* Function Declarations */
static void initialize_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initialize_params_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void enable_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void disable_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void set_sim_state_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray *c4_st);
static void finalize_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void sf_c4_Hquad_control_LIB_MPC(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c4_chartstep_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initSimStructsc4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void registerMessagesc4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_roll_bias_rot, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_c_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[2]);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static void c4_d_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[4]);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[13]);
static void c4_eml_scalar_eg(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_e_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_f_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_Hquad_control_LIB_MPC, const
  char_T *c4_identifier);
static uint8_T c4_g_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c4_is_active_c4_Hquad_control_LIB_MPC = 0U;
}

static void initialize_params_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void enable_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c4_update_debugger_state_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T c4_c_hoistedGlobal;
  real_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  real_T c4_d_hoistedGlobal;
  real_T c4_d_u;
  const mxArray *c4_e_y = NULL;
  uint8_T c4_e_hoistedGlobal;
  uint8_T c4_e_u;
  const mxArray *c4_f_y = NULL;
  real_T *c4_pitch_bias_rot;
  real_T *c4_pitch_rot;
  real_T *c4_roll_bias_rot;
  real_T *c4_roll_rot;
  c4_roll_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_pitch_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_roll_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_pitch_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(5), FALSE);
  c4_hoistedGlobal = *c4_pitch_bias_rot;
  c4_u = c4_hoistedGlobal;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = *c4_pitch_rot;
  c4_b_u = c4_b_hoistedGlobal;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *c4_roll_bias_rot;
  c4_c_u = c4_c_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = *c4_roll_rot;
  c4_d_u = c4_d_hoistedGlobal;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = chartInstance->c4_is_active_c4_Hquad_control_LIB_MPC;
  c4_e_u = c4_e_hoistedGlobal;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  sf_mex_assign(&c4_st, c4_y, FALSE);
  return c4_st;
}

static void set_sim_state_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_pitch_bias_rot;
  real_T *c4_pitch_rot;
  real_T *c4_roll_bias_rot;
  real_T *c4_roll_rot;
  c4_roll_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_pitch_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_roll_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_pitch_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c4_doneDoubleBufferReInit = TRUE;
  c4_u = sf_mex_dup(c4_st);
  *c4_pitch_bias_rot = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "pitch_bias_rot");
  *c4_pitch_rot = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 1)), "pitch_rot");
  *c4_roll_bias_rot = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 2)), "roll_bias_rot");
  *c4_roll_rot = c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c4_u, 3)), "roll_rot");
  chartInstance->c4_is_active_c4_Hquad_control_LIB_MPC = c4_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 4)),
     "is_active_c4_Hquad_control_LIB_MPC");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_Hquad_control_LIB_MPC(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void sf_c4_Hquad_control_LIB_MPC(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
  real_T *c4_yaw;
  real_T *c4_pitch_rot;
  real_T *c4_pitch_cmd;
  real_T *c4_roll_cmd;
  real_T *c4_pitch_bias;
  real_T *c4_roll_bias;
  real_T *c4_roll_rot;
  real_T *c4_pitch_bias_rot;
  real_T *c4_roll_bias_rot;
  c4_roll_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_pitch_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_roll_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_roll_bias = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c4_pitch_bias = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_roll_cmd = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_pitch_cmd = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_pitch_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c4_yaw, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_pitch_rot, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_pitch_cmd, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_roll_cmd, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_pitch_bias, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_roll_bias, 5U);
  _SFD_DATA_RANGE_CHECK(*c4_roll_rot, 6U);
  _SFD_DATA_RANGE_CHECK(*c4_pitch_bias_rot, 7U);
  _SFD_DATA_RANGE_CHECK(*c4_roll_bias_rot, 8U);
  chartInstance->c4_sfEvent = CALL_EVENT;
  c4_chartstep_c4_Hquad_control_LIB_MPC(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Hquad_control_LIB_MPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c4_chartstep_c4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  real_T c4_hoistedGlobal;
  real_T c4_b_hoistedGlobal;
  real_T c4_c_hoistedGlobal;
  real_T c4_d_hoistedGlobal;
  real_T c4_e_hoistedGlobal;
  real_T c4_yaw;
  real_T c4_pitch_cmd;
  real_T c4_roll_cmd;
  real_T c4_pitch_bias;
  real_T c4_roll_bias;
  uint32_T c4_debug_family_var_map[15];
  real_T c4_sin_yaw;
  real_T c4_cos_yaw;
  real_T c4_R[4];
  real_T c4_temp[2];
  real_T c4_nargin = 5.0;
  real_T c4_nargout = 4.0;
  real_T c4_pitch_rot;
  real_T c4_roll_rot;
  real_T c4_pitch_bias_rot;
  real_T c4_roll_bias_rot;
  real_T c4_x;
  real_T c4_b_x;
  real_T c4_c_x;
  real_T c4_d_x;
  int32_T c4_i0;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  real_T c4_a[4];
  real_T c4_b[2];
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  real_T c4_C[2];
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  real_T *c4_b_yaw;
  real_T *c4_b_pitch_cmd;
  real_T *c4_b_roll_cmd;
  real_T *c4_b_pitch_bias;
  real_T *c4_b_roll_bias;
  real_T *c4_b_pitch_rot;
  real_T *c4_b_roll_rot;
  real_T *c4_b_pitch_bias_rot;
  real_T *c4_b_roll_bias_rot;
  c4_b_roll_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c4_b_pitch_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c4_b_roll_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c4_b_roll_bias = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c4_b_pitch_bias = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c4_b_roll_cmd = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c4_b_pitch_cmd = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c4_b_pitch_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c4_b_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  c4_hoistedGlobal = *c4_b_yaw;
  c4_b_hoistedGlobal = *c4_b_pitch_cmd;
  c4_c_hoistedGlobal = *c4_b_roll_cmd;
  c4_d_hoistedGlobal = *c4_b_pitch_bias;
  c4_e_hoistedGlobal = *c4_b_roll_bias;
  c4_yaw = c4_hoistedGlobal;
  c4_pitch_cmd = c4_b_hoistedGlobal;
  c4_roll_cmd = c4_c_hoistedGlobal;
  c4_pitch_bias = c4_d_hoistedGlobal;
  c4_roll_bias = c4_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_sin_yaw, 0U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_cos_yaw, 1U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_R, 2U, c4_c_sf_marshallOut,
    c4_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_temp, 3U, c4_b_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 5U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_yaw, 6U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_pitch_cmd, 7U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_roll_cmd, 8U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_pitch_bias, 9U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c4_roll_bias, 10U, c4_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_pitch_rot, 11U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_roll_rot, 12U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_pitch_bias_rot, 13U,
    c4_sf_marshallOut, c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_roll_bias_rot, 14U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  c4_x = c4_yaw;
  c4_sin_yaw = c4_x;
  c4_b_x = c4_sin_yaw;
  c4_sin_yaw = c4_b_x;
  c4_sin_yaw = muDoubleScalarSin(c4_sin_yaw);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  c4_c_x = c4_yaw;
  c4_cos_yaw = c4_c_x;
  c4_d_x = c4_cos_yaw;
  c4_cos_yaw = c4_d_x;
  c4_cos_yaw = muDoubleScalarCos(c4_cos_yaw);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 6);
  c4_R[0] = c4_cos_yaw;
  c4_R[2] = c4_sin_yaw;
  c4_R[1] = -c4_sin_yaw;
  c4_R[3] = c4_cos_yaw;
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 8);
  c4_i0 = 0;
  for (c4_i1 = 0; c4_i1 < 2; c4_i1++) {
    c4_i2 = 0;
    for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
      c4_a[c4_i3 + c4_i0] = c4_R[c4_i2 + c4_i1];
      c4_i2 += 2;
    }

    c4_i0 += 2;
  }

  c4_b[0] = c4_pitch_cmd;
  c4_b[1] = c4_roll_cmd;
  c4_eml_scalar_eg(chartInstance);
  c4_eml_scalar_eg(chartInstance);
  for (c4_i4 = 0; c4_i4 < 2; c4_i4++) {
    c4_temp[c4_i4] = 0.0;
  }

  for (c4_i5 = 0; c4_i5 < 2; c4_i5++) {
    c4_temp[c4_i5] = 0.0;
  }

  for (c4_i6 = 0; c4_i6 < 2; c4_i6++) {
    c4_C[c4_i6] = c4_temp[c4_i6];
  }

  for (c4_i7 = 0; c4_i7 < 2; c4_i7++) {
    c4_temp[c4_i7] = c4_C[c4_i7];
  }

  for (c4_i8 = 0; c4_i8 < 2; c4_i8++) {
    c4_C[c4_i8] = c4_temp[c4_i8];
  }

  for (c4_i9 = 0; c4_i9 < 2; c4_i9++) {
    c4_temp[c4_i9] = c4_C[c4_i9];
  }

  for (c4_i10 = 0; c4_i10 < 2; c4_i10++) {
    c4_temp[c4_i10] = 0.0;
    c4_i11 = 0;
    for (c4_i12 = 0; c4_i12 < 2; c4_i12++) {
      c4_temp[c4_i10] += c4_a[c4_i11 + c4_i10] * c4_b[c4_i12];
      c4_i11 += 2;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 9);
  c4_pitch_rot = c4_temp[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 10);
  c4_roll_rot = c4_temp[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 12);
  c4_i13 = 0;
  for (c4_i14 = 0; c4_i14 < 2; c4_i14++) {
    c4_i15 = 0;
    for (c4_i16 = 0; c4_i16 < 2; c4_i16++) {
      c4_a[c4_i16 + c4_i13] = c4_R[c4_i15 + c4_i14];
      c4_i15 += 2;
    }

    c4_i13 += 2;
  }

  c4_b[0] = c4_pitch_bias;
  c4_b[1] = c4_roll_bias;
  c4_eml_scalar_eg(chartInstance);
  c4_eml_scalar_eg(chartInstance);
  for (c4_i17 = 0; c4_i17 < 2; c4_i17++) {
    c4_temp[c4_i17] = 0.0;
  }

  for (c4_i18 = 0; c4_i18 < 2; c4_i18++) {
    c4_temp[c4_i18] = 0.0;
  }

  for (c4_i19 = 0; c4_i19 < 2; c4_i19++) {
    c4_C[c4_i19] = c4_temp[c4_i19];
  }

  for (c4_i20 = 0; c4_i20 < 2; c4_i20++) {
    c4_temp[c4_i20] = c4_C[c4_i20];
  }

  for (c4_i21 = 0; c4_i21 < 2; c4_i21++) {
    c4_C[c4_i21] = c4_temp[c4_i21];
  }

  for (c4_i22 = 0; c4_i22 < 2; c4_i22++) {
    c4_temp[c4_i22] = c4_C[c4_i22];
  }

  for (c4_i23 = 0; c4_i23 < 2; c4_i23++) {
    c4_temp[c4_i23] = 0.0;
    c4_i24 = 0;
    for (c4_i25 = 0; c4_i25 < 2; c4_i25++) {
      c4_temp[c4_i23] += c4_a[c4_i24 + c4_i23] * c4_b[c4_i25];
      c4_i24 += 2;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 13);
  c4_pitch_bias_rot = c4_temp[0];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 14);
  c4_roll_bias_rot = c4_temp[1];
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  *c4_b_pitch_rot = c4_pitch_rot;
  *c4_b_roll_rot = c4_roll_rot;
  *c4_b_pitch_bias_rot = c4_pitch_bias_rot;
  *c4_b_roll_bias_rot = c4_roll_bias_rot;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
}

static void initSimStructsc4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void registerMessagesc4_Hquad_control_LIB_MPC
  (SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
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
  SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc4_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_roll_bias_rot, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_roll_bias_rot),
    &c4_thisId);
  sf_mex_destroy(&c4_roll_bias_rot);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_roll_bias_rot;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc4_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c4_roll_bias_rot = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_roll_bias_rot),
    &c4_thisId);
  sf_mex_destroy(&c4_roll_bias_rot);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i26;
  real_T c4_b_inData[2];
  int32_T c4_i27;
  real_T c4_u[2];
  const mxArray *c4_y = NULL;
  SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc4_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i26 = 0; c4_i26 < 2; c4_i26++) {
    c4_b_inData[c4_i26] = (*(real_T (*)[2])c4_inData)[c4_i26];
  }

  for (c4_i27 = 0; c4_i27 < 2; c4_i27++) {
    c4_u[c4_i27] = c4_b_inData[c4_i27];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_c_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[2])
{
  real_T c4_dv0[2];
  int32_T c4_i28;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv0, 1, 0, 0U, 1, 0U, 1, 2);
  for (c4_i28 = 0; c4_i28 < 2; c4_i28++) {
    c4_y[c4_i28] = c4_dv0[c4_i28];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_temp;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[2];
  int32_T c4_i29;
  SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc4_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c4_temp = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_temp), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_temp);
  for (c4_i29 = 0; c4_i29 < 2; c4_i29++) {
    (*(real_T (*)[2])c4_outData)[c4_i29] = c4_y[c4_i29];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  real_T c4_b_inData[4];
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  real_T c4_u[4];
  const mxArray *c4_y = NULL;
  SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc4_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_i30 = 0;
  for (c4_i31 = 0; c4_i31 < 2; c4_i31++) {
    for (c4_i32 = 0; c4_i32 < 2; c4_i32++) {
      c4_b_inData[c4_i32 + c4_i30] = (*(real_T (*)[4])c4_inData)[c4_i32 + c4_i30];
    }

    c4_i30 += 2;
  }

  c4_i33 = 0;
  for (c4_i34 = 0; c4_i34 < 2; c4_i34++) {
    for (c4_i35 = 0; c4_i35 < 2; c4_i35++) {
      c4_u[c4_i35 + c4_i33] = c4_b_inData[c4_i35 + c4_i33];
    }

    c4_i33 += 2;
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static void c4_d_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[4])
{
  real_T c4_dv1[4];
  int32_T c4_i36;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv1, 1, 0, 0U, 1, 0U, 2, 2, 2);
  for (c4_i36 = 0; c4_i36 < 4; c4_i36++) {
    c4_y[c4_i36] = c4_dv1[c4_i36];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_R;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[4];
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc4_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c4_R = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_R), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_R);
  c4_i37 = 0;
  for (c4_i38 = 0; c4_i38 < 2; c4_i38++) {
    for (c4_i39 = 0; c4_i39 < 2; c4_i39++) {
      (*(real_T (*)[4])c4_outData)[c4_i39 + c4_i37] = c4_y[c4_i39 + c4_i37];
    }

    c4_i37 += 2;
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo;
  c4_ResolvedFunctionInfo c4_info[13];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i40;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  c4_info_helper(c4_info);
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 13), FALSE);
  for (c4_i40 = 0; c4_i40 < 13; c4_i40++) {
    c4_r0 = &c4_info[c4_i40];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context", "nameCaptureInfo",
                    c4_i40);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name", "nameCaptureInfo", c4_i40);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c4_i40);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved", "nameCaptureInfo",
                    c4_i40);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c4_i40);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c4_i40);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c4_i40);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c4_i40);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c4_nameCaptureInfo);
  return c4_nameCaptureInfo;
}

static void c4_info_helper(c4_ResolvedFunctionInfo c4_info[13])
{
  c4_info[0].context = "";
  c4_info[0].name = "sin";
  c4_info[0].dominantType = "double";
  c4_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c4_info[0].fileTimeLo = 1343830386U;
  c4_info[0].fileTimeHi = 0U;
  c4_info[0].mFileTimeLo = 0U;
  c4_info[0].mFileTimeHi = 0U;
  c4_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  c4_info[1].name = "eml_scalar_sin";
  c4_info[1].dominantType = "double";
  c4_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  c4_info[1].fileTimeLo = 1286818736U;
  c4_info[1].fileTimeHi = 0U;
  c4_info[1].mFileTimeLo = 0U;
  c4_info[1].mFileTimeHi = 0U;
  c4_info[2].context = "";
  c4_info[2].name = "cos";
  c4_info[2].dominantType = "double";
  c4_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c4_info[2].fileTimeLo = 1343830372U;
  c4_info[2].fileTimeHi = 0U;
  c4_info[2].mFileTimeLo = 0U;
  c4_info[2].mFileTimeHi = 0U;
  c4_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  c4_info[3].name = "eml_scalar_cos";
  c4_info[3].dominantType = "double";
  c4_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  c4_info[3].fileTimeLo = 1286818722U;
  c4_info[3].fileTimeHi = 0U;
  c4_info[3].mFileTimeLo = 0U;
  c4_info[3].mFileTimeHi = 0U;
  c4_info[4].context = "";
  c4_info[4].name = "mtimes";
  c4_info[4].dominantType = "double";
  c4_info[4].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[4].fileTimeLo = 1289519692U;
  c4_info[4].fileTimeHi = 0U;
  c4_info[4].mFileTimeLo = 0U;
  c4_info[4].mFileTimeHi = 0U;
  c4_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[5].name = "eml_index_class";
  c4_info[5].dominantType = "";
  c4_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[5].fileTimeLo = 1323170578U;
  c4_info[5].fileTimeHi = 0U;
  c4_info[5].mFileTimeLo = 0U;
  c4_info[5].mFileTimeHi = 0U;
  c4_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[6].name = "eml_scalar_eg";
  c4_info[6].dominantType = "double";
  c4_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[6].fileTimeLo = 1286818796U;
  c4_info[6].fileTimeHi = 0U;
  c4_info[6].mFileTimeLo = 0U;
  c4_info[6].mFileTimeHi = 0U;
  c4_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[7].name = "eml_xgemm";
  c4_info[7].dominantType = "char";
  c4_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c4_info[7].fileTimeLo = 1299076772U;
  c4_info[7].fileTimeHi = 0U;
  c4_info[7].mFileTimeLo = 0U;
  c4_info[7].mFileTimeHi = 0U;
  c4_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c4_info[8].name = "eml_blas_inline";
  c4_info[8].dominantType = "";
  c4_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c4_info[8].fileTimeLo = 1299076768U;
  c4_info[8].fileTimeHi = 0U;
  c4_info[8].mFileTimeLo = 0U;
  c4_info[8].mFileTimeHi = 0U;
  c4_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m!below_threshold";
  c4_info[9].name = "mtimes";
  c4_info[9].dominantType = "double";
  c4_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c4_info[9].fileTimeLo = 1289519692U;
  c4_info[9].fileTimeHi = 0U;
  c4_info[9].mFileTimeLo = 0U;
  c4_info[9].mFileTimeHi = 0U;
  c4_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c4_info[10].name = "eml_index_class";
  c4_info[10].dominantType = "";
  c4_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c4_info[10].fileTimeLo = 1323170578U;
  c4_info[10].fileTimeHi = 0U;
  c4_info[10].mFileTimeLo = 0U;
  c4_info[10].mFileTimeHi = 0U;
  c4_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c4_info[11].name = "eml_scalar_eg";
  c4_info[11].dominantType = "double";
  c4_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c4_info[11].fileTimeLo = 1286818796U;
  c4_info[11].fileTimeHi = 0U;
  c4_info[11].mFileTimeLo = 0U;
  c4_info[11].mFileTimeHi = 0U;
  c4_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c4_info[12].name = "eml_refblas_xgemm";
  c4_info[12].dominantType = "char";
  c4_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c4_info[12].fileTimeLo = 1299076774U;
  c4_info[12].fileTimeHi = 0U;
  c4_info[12].mFileTimeLo = 0U;
  c4_info[12].mFileTimeHi = 0U;
}

static void c4_eml_scalar_eg(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc4_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, FALSE);
  return c4_mxArrayOutData;
}

static int32_T c4_e_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i41;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i41, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i41;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc4_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_Hquad_control_LIB_MPC, const
  char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_Hquad_control_LIB_MPC), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_Hquad_control_LIB_MPC);
  return c4_y;
}

static uint8_T c4_g_emlrt_marshallIn(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
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

void sf_c4_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3162882598U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(110980509U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3653499001U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1977587442U);
}

mxArray *sf_c4_Hquad_control_LIB_MPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("PddICc7weq3w2oiZsWbCfH");
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

mxArray *sf_c4_Hquad_control_LIB_MPC_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c4_Hquad_control_LIB_MPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[15],T\"pitch_bias_rot\",},{M[1],M[11],T\"pitch_rot\",},{M[1],M[14],T\"roll_bias_rot\",},{M[1],M[10],T\"roll_rot\",},{M[8],M[0],T\"is_active_c4_Hquad_control_LIB_MPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_Hquad_control_LIB_MPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
    chartInstance = (SFc4_Hquad_control_LIB_MPCInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Hquad_control_LIB_MPCMachineNumber_,
           4,
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
            (sfGlobalDebugInstanceStruct,_Hquad_control_LIB_MPCMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Hquad_control_LIB_MPCMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"yaw");
          _SFD_SET_DATA_PROPS(1,2,0,1,"pitch_rot");
          _SFD_SET_DATA_PROPS(2,1,1,0,"pitch_cmd");
          _SFD_SET_DATA_PROPS(3,1,1,0,"roll_cmd");
          _SFD_SET_DATA_PROPS(4,1,1,0,"pitch_bias");
          _SFD_SET_DATA_PROPS(5,1,1,0,"roll_bias");
          _SFD_SET_DATA_PROPS(6,2,0,1,"roll_rot");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,341);
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
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);

        {
          real_T *c4_yaw;
          real_T *c4_pitch_rot;
          real_T *c4_pitch_cmd;
          real_T *c4_roll_cmd;
          real_T *c4_pitch_bias;
          real_T *c4_roll_bias;
          real_T *c4_roll_rot;
          real_T *c4_pitch_bias_rot;
          real_T *c4_roll_bias_rot;
          c4_roll_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c4_pitch_bias_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            3);
          c4_roll_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c4_roll_bias = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c4_pitch_bias = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c4_roll_cmd = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c4_pitch_cmd = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c4_pitch_rot = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c4_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_yaw);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_pitch_rot);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_pitch_cmd);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_roll_cmd);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_pitch_bias);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_roll_bias);
          _SFD_SET_DATA_VALUE_PTR(6U, c4_roll_rot);
          _SFD_SET_DATA_VALUE_PTR(7U, c4_pitch_bias_rot);
          _SFD_SET_DATA_VALUE_PTR(8U, c4_roll_bias_rot);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Hquad_control_LIB_MPCMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "9ukmRYrRYXn7rvf6dwyjIG";
}

static void sf_opaque_initialize_c4_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_Hquad_control_LIB_MPC
    ((SFc4_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
  initialize_c4_Hquad_control_LIB_MPC((SFc4_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  enable_c4_Hquad_control_LIB_MPC((SFc4_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  disable_c4_Hquad_control_LIB_MPC((SFc4_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_c4_Hquad_control_LIB_MPC((SFc4_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c4_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c4_Hquad_control_LIB_MPC
    ((SFc4_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Hquad_control_LIB_MPC();/* state var info */
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

extern void sf_internal_set_sim_state_c4_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c4_Hquad_control_LIB_MPC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c4_Hquad_control_LIB_MPC
    ((SFc4_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c4_Hquad_control_LIB_MPC(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c4_Hquad_control_LIB_MPC(S);
}

static void sf_opaque_set_sim_state_c4_Hquad_control_LIB_MPC(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c4_Hquad_control_LIB_MPC(S, st);
}

static void sf_opaque_terminate_c4_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Hquad_control_LIB_MPC_optimization_info();
    }

    finalize_c4_Hquad_control_LIB_MPC((SFc4_Hquad_control_LIB_MPCInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_Hquad_control_LIB_MPC
    ((SFc4_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_Hquad_control_LIB_MPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_Hquad_control_LIB_MPC
      ((SFc4_Hquad_control_LIB_MPCInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,4,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(819900167U));
  ssSetChecksum1(S,(2275868869U));
  ssSetChecksum2(S,(3269167553U));
  ssSetChecksum3(S,(1346828663U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_Hquad_control_LIB_MPC(SimStruct *S)
{
  SFc4_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc4_Hquad_control_LIB_MPCInstanceStruct *)utMalloc(sizeof
    (SFc4_Hquad_control_LIB_MPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_Hquad_control_LIB_MPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c4_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c4_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_Hquad_control_LIB_MPC;
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

void c4_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_Hquad_control_LIB_MPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_Hquad_control_LIB_MPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
