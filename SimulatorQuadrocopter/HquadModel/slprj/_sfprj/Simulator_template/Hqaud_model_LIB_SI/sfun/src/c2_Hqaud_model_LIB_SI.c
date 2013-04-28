/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Hqaud_model_LIB_SI_sfun.h"
#include "c2_Hqaud_model_LIB_SI.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hqaud_model_LIB_SI_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[12] = { "acc", "nargin", "nargout",
  "pitch", "roll", "yaw", "thrust", "m", "g", "ax_I", "ay_I", "az_I" };

/* Function Declarations */
static void initialize_c2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance);
static void initialize_params_c2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance);
static void enable_c2_Hqaud_model_LIB_SI(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance);
static void disable_c2_Hqaud_model_LIB_SI(SFc2_Hqaud_model_LIB_SIInstanceStruct *
  chartInstance);
static void c2_update_debugger_state_c2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance);
static void set_sim_state_c2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_Hqaud_model_LIB_SI(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance);
static void sf_c2_Hqaud_model_LIB_SI(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance);
static void initSimStructsc2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance);
static void registerMessagesc2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance, const mxArray *c2_az_I, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_d_emlrt_marshallIn(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_e_emlrt_marshallIn(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Hqaud_model_LIB_SI, const
  char_T *c2_identifier);
static uint8_T c2_f_emlrt_marshallIn(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_Hqaud_model_LIB_SI = 0U;
}

static void initialize_params_c2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance)
{
}

static void enable_c2_Hqaud_model_LIB_SI(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_Hqaud_model_LIB_SI(SFc2_Hqaud_model_LIB_SIInstanceStruct *
  chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T c2_b_hoistedGlobal;
  real_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T c2_c_hoistedGlobal;
  real_T c2_c_u;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  real_T *c2_ax_I;
  real_T *c2_ay_I;
  real_T *c2_az_I;
  c2_az_I = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_ay_I = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_ax_I = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(4), FALSE);
  c2_hoistedGlobal = *c2_ax_I;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = *c2_ay_I;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  c2_c_hoistedGlobal = *c2_az_I;
  c2_c_u = c2_c_hoistedGlobal;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_active_c2_Hqaud_model_LIB_SI;
  c2_d_u = c2_d_hoistedGlobal;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 3, c2_e_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_ax_I;
  real_T *c2_ay_I;
  real_T *c2_az_I;
  c2_az_I = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_ay_I = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_ax_I = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_ax_I = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    0)), "ax_I");
  *c2_ay_I = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    1)), "ay_I");
  *c2_az_I = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    2)), "az_I");
  chartInstance->c2_is_active_c2_Hqaud_model_LIB_SI = c2_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 3)),
     "is_active_c2_Hqaud_model_LIB_SI");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_Hqaud_model_LIB_SI(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_Hqaud_model_LIB_SI(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance)
{
}

static void sf_c2_Hqaud_model_LIB_SI(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  real_T c2_f_hoistedGlobal;
  real_T c2_pitch;
  real_T c2_roll;
  real_T c2_yaw;
  real_T c2_thrust;
  real_T c2_m;
  real_T c2_g;
  uint32_T c2_debug_family_var_map[12];
  real_T c2_acc[3];
  real_T c2_nargin = 6.0;
  real_T c2_nargout = 3.0;
  real_T c2_ax_I;
  real_T c2_ay_I;
  real_T c2_az_I;
  real_T c2_A;
  real_T c2_B;
  real_T c2_x;
  real_T c2_y;
  real_T c2_b_x;
  real_T c2_b_y;
  real_T c2_c_y;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_a;
  real_T c2_b;
  real_T c2_d_y;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_b_a;
  real_T c2_b_b;
  real_T c2_e_y;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_f_y;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_d_a;
  real_T c2_d_b;
  real_T c2_g_y;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_h_y;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_f_a;
  real_T c2_f_b;
  real_T c2_i_y;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_g_a;
  real_T c2_g_b;
  real_T c2_j_y;
  real_T c2_h_a;
  real_T c2_h_b[3];
  int32_T c2_i0;
  real_T c2_dv0[3];
  int32_T c2_i1;
  real_T *c2_b_az_I;
  real_T *c2_b_ay_I;
  real_T *c2_b_ax_I;
  real_T *c2_b_g;
  real_T *c2_b_m;
  real_T *c2_b_thrust;
  real_T *c2_b_yaw;
  real_T *c2_b_roll;
  real_T *c2_b_pitch;
  c2_b_az_I = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c2_b_ay_I = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c2_b_g = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c2_b_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_thrust = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_ax_I = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c2_b_pitch, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_ax_I, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_roll, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_yaw, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_thrust, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_m, 5U);
  _SFD_DATA_RANGE_CHECK(*c2_b_g, 6U);
  _SFD_DATA_RANGE_CHECK(*c2_b_ay_I, 7U);
  _SFD_DATA_RANGE_CHECK(*c2_b_az_I, 8U);
  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_pitch;
  c2_b_hoistedGlobal = *c2_b_roll;
  c2_c_hoistedGlobal = *c2_b_yaw;
  c2_d_hoistedGlobal = *c2_b_thrust;
  c2_e_hoistedGlobal = *c2_b_m;
  c2_f_hoistedGlobal = *c2_b_g;
  c2_pitch = c2_hoistedGlobal;
  c2_roll = c2_b_hoistedGlobal;
  c2_yaw = c2_c_hoistedGlobal;
  c2_thrust = c2_d_hoistedGlobal;
  c2_m = c2_e_hoistedGlobal;
  c2_g = c2_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_acc, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 2U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_pitch, 3U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_roll, 4U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_yaw, 5U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_thrust, 6U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_m, 7U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_g, 8U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_ax_I, 9U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_ay_I, 10U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_az_I, 11U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  c2_A = -c2_thrust;
  c2_B = c2_m;
  c2_x = c2_A;
  c2_y = c2_B;
  c2_b_x = c2_x;
  c2_b_y = c2_y;
  c2_c_y = c2_b_x / c2_b_y;
  c2_c_x = c2_yaw;
  c2_d_x = c2_c_x;
  c2_d_x = muDoubleScalarCos(c2_d_x);
  c2_e_x = c2_pitch;
  c2_f_x = c2_e_x;
  c2_f_x = muDoubleScalarSin(c2_f_x);
  c2_a = c2_d_x;
  c2_b = c2_f_x;
  c2_d_y = c2_a * c2_b;
  c2_g_x = c2_roll;
  c2_h_x = c2_g_x;
  c2_h_x = muDoubleScalarCos(c2_h_x);
  c2_b_a = c2_d_y;
  c2_b_b = c2_h_x;
  c2_e_y = c2_b_a * c2_b_b;
  c2_i_x = c2_yaw;
  c2_j_x = c2_i_x;
  c2_j_x = muDoubleScalarSin(c2_j_x);
  c2_k_x = c2_roll;
  c2_l_x = c2_k_x;
  c2_l_x = muDoubleScalarSin(c2_l_x);
  c2_c_a = c2_j_x;
  c2_c_b = c2_l_x;
  c2_f_y = c2_c_a * c2_c_b;
  c2_m_x = c2_yaw;
  c2_n_x = c2_m_x;
  c2_n_x = muDoubleScalarSin(c2_n_x);
  c2_o_x = c2_pitch;
  c2_p_x = c2_o_x;
  c2_p_x = muDoubleScalarSin(c2_p_x);
  c2_d_a = c2_n_x;
  c2_d_b = c2_p_x;
  c2_g_y = c2_d_a * c2_d_b;
  c2_q_x = c2_roll;
  c2_r_x = c2_q_x;
  c2_r_x = muDoubleScalarCos(c2_r_x);
  c2_e_a = c2_g_y;
  c2_e_b = c2_r_x;
  c2_h_y = c2_e_a * c2_e_b;
  c2_s_x = c2_yaw;
  c2_t_x = c2_s_x;
  c2_t_x = muDoubleScalarCos(c2_t_x);
  c2_u_x = c2_roll;
  c2_v_x = c2_u_x;
  c2_v_x = muDoubleScalarSin(c2_v_x);
  c2_f_a = c2_t_x;
  c2_f_b = c2_v_x;
  c2_i_y = c2_f_a * c2_f_b;
  c2_w_x = c2_pitch;
  c2_x_x = c2_w_x;
  c2_x_x = muDoubleScalarCos(c2_x_x);
  c2_y_x = c2_roll;
  c2_ab_x = c2_y_x;
  c2_ab_x = muDoubleScalarCos(c2_ab_x);
  c2_g_a = c2_x_x;
  c2_g_b = c2_ab_x;
  c2_j_y = c2_g_a * c2_g_b;
  c2_h_a = c2_c_y;
  c2_h_b[0] = c2_e_y + c2_f_y;
  c2_h_b[1] = c2_h_y - c2_i_y;
  c2_h_b[2] = c2_j_y;
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    c2_h_b[c2_i0] *= c2_h_a;
  }

  c2_dv0[0] = 0.0;
  c2_dv0[1] = 0.0;
  c2_dv0[2] = c2_g;
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    c2_acc[c2_i1] = c2_h_b[c2_i1] + c2_dv0[c2_i1];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 9);
  c2_ax_I = c2_acc[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_ay_I = c2_acc[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_az_I = c2_acc[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_b_ax_I = c2_ax_I;
  *c2_b_ay_I = c2_ay_I;
  *c2_b_az_I = c2_az_I;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Hqaud_model_LIB_SIMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance)
{
}

static void registerMessagesc2_Hqaud_model_LIB_SI
  (SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance)
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
  SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hqaud_model_LIB_SIInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance, const mxArray *c2_az_I, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_az_I), &c2_thisId);
  sf_mex_destroy(&c2_az_I);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_az_I;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hqaud_model_LIB_SIInstanceStruct *)chartInstanceVoid;
  c2_az_I = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_az_I), &c2_thisId);
  sf_mex_destroy(&c2_az_I);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i2;
  real_T c2_b_inData[3];
  int32_T c2_i3;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hqaud_model_LIB_SIInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i2 = 0; c2_i2 < 3; c2_i2++) {
    c2_b_inData[c2_i2] = (*(real_T (*)[3])c2_inData)[c2_i2];
  }

  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    c2_u[c2_i3] = c2_b_inData[c2_i3];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3])
{
  real_T c2_dv1[3];
  int32_T c2_i4;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i4 = 0; c2_i4 < 3; c2_i4++) {
    c2_y[c2_i4] = c2_dv1[c2_i4];
  }

  sf_mex_destroy(&c2_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_acc;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i5;
  SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hqaud_model_LIB_SIInstanceStruct *)chartInstanceVoid;
  c2_acc = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_acc), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_acc);
  for (c2_i5 = 0; c2_i5 < 3; c2_i5++) {
    (*(real_T (*)[3])c2_outData)[c2_i5] = c2_y[c2_i5];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_Hqaud_model_LIB_SI_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[9];
  c2_ResolvedFunctionInfo (*c2_b_info)[9];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i6;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[9])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "mrdivide";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[0].fileTimeLo = 1357951548U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 1319729966U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c2_b_info)[1].name = "rdivide";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[1].fileTimeLo = 1346510388U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[2].name = "eml_scalexp_compatible";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c2_b_info)[2].fileTimeLo = 1286818796U;
  (*c2_b_info)[2].fileTimeHi = 0U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c2_b_info)[3].name = "eml_div";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c2_b_info)[3].fileTimeLo = 1313347810U;
  (*c2_b_info)[3].fileTimeHi = 0U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context = "";
  (*c2_b_info)[4].name = "cos";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c2_b_info)[4].fileTimeLo = 1343830372U;
  (*c2_b_info)[4].fileTimeHi = 0U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  (*c2_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c2_b_info)[5].name = "eml_scalar_cos";
  (*c2_b_info)[5].dominantType = "double";
  (*c2_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c2_b_info)[5].fileTimeLo = 1286818722U;
  (*c2_b_info)[5].fileTimeHi = 0U;
  (*c2_b_info)[5].mFileTimeLo = 0U;
  (*c2_b_info)[5].mFileTimeHi = 0U;
  (*c2_b_info)[6].context = "";
  (*c2_b_info)[6].name = "sin";
  (*c2_b_info)[6].dominantType = "double";
  (*c2_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c2_b_info)[6].fileTimeLo = 1343830386U;
  (*c2_b_info)[6].fileTimeHi = 0U;
  (*c2_b_info)[6].mFileTimeLo = 0U;
  (*c2_b_info)[6].mFileTimeHi = 0U;
  (*c2_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c2_b_info)[7].name = "eml_scalar_sin";
  (*c2_b_info)[7].dominantType = "double";
  (*c2_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c2_b_info)[7].fileTimeLo = 1286818736U;
  (*c2_b_info)[7].fileTimeHi = 0U;
  (*c2_b_info)[7].mFileTimeLo = 0U;
  (*c2_b_info)[7].mFileTimeHi = 0U;
  (*c2_b_info)[8].context = "";
  (*c2_b_info)[8].name = "mtimes";
  (*c2_b_info)[8].dominantType = "double";
  (*c2_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c2_b_info)[8].fileTimeLo = 1289519692U;
  (*c2_b_info)[8].fileTimeHi = 0U;
  (*c2_b_info)[8].mFileTimeLo = 0U;
  (*c2_b_info)[8].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 9), FALSE);
  for (c2_i6 = 0; c2_i6 < 9; c2_i6++) {
    c2_r0 = &c2_info[c2_i6];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i6);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i6);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i6);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i6);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i6);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i6);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i6);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i6);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hqaud_model_LIB_SIInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_d_emlrt_marshallIn(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i7;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i7, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i7;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hqaud_model_LIB_SIInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_Hqaud_model_LIB_SI, const
  char_T *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_Hqaud_model_LIB_SI), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_Hqaud_model_LIB_SI);
  return c2_y;
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_Hqaud_model_LIB_SIInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_Hqaud_model_LIB_SIInstanceStruct
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

void sf_c2_Hqaud_model_LIB_SI_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(691892277U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2100985246U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1553065107U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1195974551U);
}

mxArray *sf_c2_Hqaud_model_LIB_SI_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("tlQW3InDlHl6PTuAlGsJrH");
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

mxArray *sf_c2_Hqaud_model_LIB_SI_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_Hqaud_model_LIB_SI(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"ax_I\",},{M[1],M[11],T\"ay_I\",},{M[1],M[12],T\"az_I\",},{M[8],M[0],T\"is_active_c2_Hqaud_model_LIB_SI\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_Hqaud_model_LIB_SI_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance;
    chartInstance = (SFc2_Hqaud_model_LIB_SIInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Hqaud_model_LIB_SIMachineNumber_,
           2,
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
          init_script_number_translation(_Hqaud_model_LIB_SIMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Hqaud_model_LIB_SIMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Hqaud_model_LIB_SIMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"pitch");
          _SFD_SET_DATA_PROPS(1,2,0,1,"ax_I");
          _SFD_SET_DATA_PROPS(2,1,1,0,"roll");
          _SFD_SET_DATA_PROPS(3,1,1,0,"yaw");
          _SFD_SET_DATA_PROPS(4,1,1,0,"thrust");
          _SFD_SET_DATA_PROPS(5,1,1,0,"m");
          _SFD_SET_DATA_PROPS(6,1,1,0,"g");
          _SFD_SET_DATA_PROPS(7,2,0,1,"ay_I");
          _SFD_SET_DATA_PROPS(8,2,0,1,"az_I");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,335);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);

        {
          real_T *c2_pitch;
          real_T *c2_ax_I;
          real_T *c2_roll;
          real_T *c2_yaw;
          real_T *c2_thrust;
          real_T *c2_m;
          real_T *c2_g;
          real_T *c2_ay_I;
          real_T *c2_az_I;
          c2_az_I = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c2_ay_I = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c2_g = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c2_m = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c2_thrust = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c2_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_roll = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_ax_I = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_pitch = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_pitch);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_ax_I);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_roll);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_yaw);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_thrust);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_m);
          _SFD_SET_DATA_VALUE_PTR(6U, c2_g);
          _SFD_SET_DATA_VALUE_PTR(7U, c2_ay_I);
          _SFD_SET_DATA_VALUE_PTR(8U, c2_az_I);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Hqaud_model_LIB_SIMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "4RDv9GTCiNMDvnWpG8pBS";
}

static void sf_opaque_initialize_c2_Hqaud_model_LIB_SI(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_Hqaud_model_LIB_SIInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_Hqaud_model_LIB_SI((SFc2_Hqaud_model_LIB_SIInstanceStruct*)
    chartInstanceVar);
  initialize_c2_Hqaud_model_LIB_SI((SFc2_Hqaud_model_LIB_SIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_Hqaud_model_LIB_SI(void *chartInstanceVar)
{
  enable_c2_Hqaud_model_LIB_SI((SFc2_Hqaud_model_LIB_SIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_Hqaud_model_LIB_SI(void *chartInstanceVar)
{
  disable_c2_Hqaud_model_LIB_SI((SFc2_Hqaud_model_LIB_SIInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_Hqaud_model_LIB_SI(void *chartInstanceVar)
{
  sf_c2_Hqaud_model_LIB_SI((SFc2_Hqaud_model_LIB_SIInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_Hqaud_model_LIB_SI(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_Hqaud_model_LIB_SI
    ((SFc2_Hqaud_model_LIB_SIInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Hqaud_model_LIB_SI();/* state var info */
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

extern void sf_internal_set_sim_state_c2_Hqaud_model_LIB_SI(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_Hqaud_model_LIB_SI();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_Hqaud_model_LIB_SI((SFc2_Hqaud_model_LIB_SIInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_Hqaud_model_LIB_SI(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_Hqaud_model_LIB_SI(S);
}

static void sf_opaque_set_sim_state_c2_Hqaud_model_LIB_SI(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c2_Hqaud_model_LIB_SI(S, st);
}

static void sf_opaque_terminate_c2_Hqaud_model_LIB_SI(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_Hqaud_model_LIB_SIInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Hqaud_model_LIB_SI_optimization_info();
    }

    finalize_c2_Hqaud_model_LIB_SI((SFc2_Hqaud_model_LIB_SIInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_Hqaud_model_LIB_SI((SFc2_Hqaud_model_LIB_SIInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_Hqaud_model_LIB_SI(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_Hqaud_model_LIB_SI
      ((SFc2_Hqaud_model_LIB_SIInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_Hqaud_model_LIB_SI(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hqaud_model_LIB_SI_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(787557413U));
  ssSetChecksum1(S,(257152101U));
  ssSetChecksum2(S,(272332560U));
  ssSetChecksum3(S,(4036368052U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_Hqaud_model_LIB_SI(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_Hqaud_model_LIB_SI(SimStruct *S)
{
  SFc2_Hqaud_model_LIB_SIInstanceStruct *chartInstance;
  chartInstance = (SFc2_Hqaud_model_LIB_SIInstanceStruct *)utMalloc(sizeof
    (SFc2_Hqaud_model_LIB_SIInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_Hqaud_model_LIB_SIInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_Hqaud_model_LIB_SI;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_Hqaud_model_LIB_SI;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_Hqaud_model_LIB_SI;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_Hqaud_model_LIB_SI;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c2_Hqaud_model_LIB_SI;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_Hqaud_model_LIB_SI;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_Hqaud_model_LIB_SI;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_Hqaud_model_LIB_SI;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_Hqaud_model_LIB_SI;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_Hqaud_model_LIB_SI;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_Hqaud_model_LIB_SI;
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

void c2_Hqaud_model_LIB_SI_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_Hqaud_model_LIB_SI(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_Hqaud_model_LIB_SI(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_Hqaud_model_LIB_SI(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_Hqaud_model_LIB_SI_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
