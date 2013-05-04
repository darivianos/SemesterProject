/* Include files */

#include "blascompat32.h"
#include "Hquad_control_LIB_MPC_sfun.h"
#include "c9_Hquad_control_LIB_MPC.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hquad_control_LIB_MPC_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[32] = { "m", "delay_steps", "N",
  "x_predicted", "U_ref", "LL_PP_ref", "MM_ref", "V_star", "unusedU0", "U_star",
  "nargin", "nargout", "TT_PP", "LL_PP", "LL_ref_PP", "LL_U_ref_PP", "MM", "PP",
  "AA_delay", "BB_delay", "x", "X_ref", "V_max", "i_min", "betas", "L", "u_buff",
  "V_init", "u_opt", "J_star", "u_buff_out", "V_init_out" };

static const char * c9_b_debug_family_names[22] = { "MONITOR", "L_inv",
  "LL_PP_t", "V_i", "W_i", "V_ip1", "W_ip1", "sol", "nargin", "nargout", "TT_PP",
  "LL_PP", "MM", "V_min", "V_max", "V_init", "i_min", "betas", "L", "J", "V",
  "actual_num_iters" };

/* Function Declarations */
static void initialize_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initialize_params_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void enable_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void disable_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void ext_mode_exec_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void set_sim_state_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray *c9_st);
static void finalize_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void sf_c9_Hquad_control_LIB_MPC(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c9_chartstep_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initSimStructsc9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_V_init_out, const char_T *c9_identifier,
  real_T c9_y[30]);
static void c9_b_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[30]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_c_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u_buff_out, const char_T *c9_identifier,
  real_T c9_y[6]);
static void c9_d_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[6]);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_e_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_J_star, const char_T *c9_identifier);
static real_T c9_f_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_j_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_k_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_l_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_g_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[30]);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_h_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[2]);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_i_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[5]);
static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_j_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[900]);
static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_m_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[24]);
static void c9_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c9_b_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c9_c_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c9_d_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c9_eml_xgemm(SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c9_A[62], real_T c9_B[1860], real_T c9_C[30], real_T c9_b_C[30]);
static void c9_e_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c9_b_eml_xgemm(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_A[30], real_T c9_B[900], real_T c9_C[30], real_T
  c9_b_C[30]);
static void c9_f_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c9_g_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c9_runFastGradient(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_TT_PP[900], real_T c9_LL_PP[30], real_T c9_MM,
  real_T c9_V_min[30], real_T c9_V_max[30], real_T c9_V_init[30], real_T
  c9_i_min, real_T c9_betas[5], real_T c9_L, real_T *c9_J, real_T c9_V[30],
  real_T *c9_actual_num_iters);
static real_T c9_mrdivide(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_A, real_T c9_B);
static void c9_h_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c9_c_eml_xgemm(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_A[900], real_T c9_B[30], real_T c9_C[30], real_T
  c9_b_C[30]);
static void c9_i_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c9_j_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c9_k_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static const mxArray *c9_n_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_k_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_l_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_is_active_c9_Hquad_control_LIB_MPC, const
  char_T *c9_identifier);
static uint8_T c9_m_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_eml_xgemm(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_A[62], real_T c9_B[1860], real_T c9_C[30]);
static void c9_e_eml_xgemm(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_A[30], real_T c9_B[900], real_T c9_C[30]);
static void c9_f_eml_xgemm(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_A[900], real_T c9_B[30], real_T c9_C[30]);
static void init_dsm_address_info(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T *c9_sfEvent;
  uint8_T *c9_is_active_c9_Hquad_control_LIB_MPC;
  c9_is_active_c9_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c9_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c9_is_active_c9_Hquad_control_LIB_MPC = 0U;
}

static void initialize_params_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void enable_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  c9_update_debugger_state_c9_Hquad_control_LIB_MPC(chartInstance);
}

static const mxArray *get_sim_state_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  int32_T c9_i0;
  real_T c9_b_u[30];
  const mxArray *c9_c_y = NULL;
  int32_T c9_i1;
  real_T c9_c_u[6];
  const mxArray *c9_d_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  uint8_T c9_c_hoistedGlobal;
  uint8_T c9_e_u;
  const mxArray *c9_f_y = NULL;
  real_T *c9_J_star;
  real_T *c9_u_opt;
  uint8_T *c9_is_active_c9_Hquad_control_LIB_MPC;
  real_T (*c9_u_buff_out)[6];
  real_T (*c9_V_init_out)[30];
  c9_V_init_out = (real_T (*)[30])ssGetOutputPortSignal(chartInstance->S, 4);
  c9_u_buff_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
  c9_J_star = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_u_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_is_active_c9_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(5), FALSE);
  c9_hoistedGlobal = *c9_J_star;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  for (c9_i0 = 0; c9_i0 < 30; c9_i0++) {
    c9_b_u[c9_i0] = (*c9_V_init_out)[c9_i0];
  }

  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", c9_b_u, 0, 0U, 1U, 0U, 1, 30), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  for (c9_i1 = 0; c9_i1 < 6; c9_i1++) {
    c9_c_u[c9_i1] = (*c9_u_buff_out)[c9_i1];
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_c_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_b_hoistedGlobal = *c9_u_opt;
  c9_d_u = c9_b_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  c9_c_hoistedGlobal = *c9_is_active_c9_Hquad_control_LIB_MPC;
  c9_e_u = c9_c_hoistedGlobal;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 4, c9_f_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[30];
  int32_T c9_i2;
  real_T c9_dv1[6];
  int32_T c9_i3;
  boolean_T *c9_doneDoubleBufferReInit;
  real_T *c9_J_star;
  real_T *c9_u_opt;
  uint8_T *c9_is_active_c9_Hquad_control_LIB_MPC;
  real_T (*c9_V_init_out)[30];
  real_T (*c9_u_buff_out)[6];
  c9_V_init_out = (real_T (*)[30])ssGetOutputPortSignal(chartInstance->S, 4);
  c9_u_buff_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
  c9_J_star = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_u_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_is_active_c9_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c9_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  *c9_J_star = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 0)), "J_star");
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
                      "V_init_out", c9_dv0);
  for (c9_i2 = 0; c9_i2 < 30; c9_i2++) {
    (*c9_V_init_out)[c9_i2] = c9_dv0[c9_i2];
  }

  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 2)),
                        "u_buff_out", c9_dv1);
  for (c9_i3 = 0; c9_i3 < 6; c9_i3++) {
    (*c9_u_buff_out)[c9_i3] = c9_dv1[c9_i3];
  }

  *c9_u_opt = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 3)), "u_opt");
  *c9_is_active_c9_Hquad_control_LIB_MPC = c9_l_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 4)), "is_active_c9_Hquad_control_LIB_MPC");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_Hquad_control_LIB_MPC(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void sf_c9_Hquad_control_LIB_MPC(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
  int32_T c9_i4;
  int32_T c9_i5;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  int32_T c9_i9;
  int32_T c9_i10;
  int32_T c9_i11;
  int32_T c9_i12;
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  int32_T c9_i16;
  int32_T c9_i17;
  int32_T c9_i18;
  int32_T c9_i19;
  int32_T *c9_sfEvent;
  real_T *c9_u_opt;
  real_T *c9_J_star;
  real_T *c9_i_min;
  real_T *c9_L;
  real_T (*c9_V_init)[30];
  real_T (*c9_u_buff)[6];
  real_T (*c9_betas)[5];
  real_T (*c9_V_max)[30];
  real_T (*c9_X_ref)[62];
  real_T (*c9_x)[2];
  real_T (*c9_BB_delay)[12];
  real_T (*c9_AA_delay)[4];
  real_T (*c9_PP)[900];
  real_T (*c9_MM)[4];
  real_T (*c9_V_init_out)[30];
  real_T (*c9_u_buff_out)[6];
  real_T (*c9_LL_U_ref_PP)[900];
  real_T (*c9_LL_ref_PP)[1860];
  real_T (*c9_LL_PP)[60];
  real_T (*c9_TT_PP)[900];
  c9_V_init = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 15);
  c9_u_buff = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 14);
  c9_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c9_betas = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 12);
  c9_i_min = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c9_V_max = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 10);
  c9_X_ref = (real_T (*)[62])ssGetInputPortSignal(chartInstance->S, 9);
  c9_x = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 8);
  c9_BB_delay = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 7);
  c9_AA_delay = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 6);
  c9_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 5);
  c9_MM = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c9_V_init_out = (real_T (*)[30])ssGetOutputPortSignal(chartInstance->S, 4);
  c9_u_buff_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
  c9_J_star = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_LL_U_ref_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 3);
  c9_LL_ref_PP = (real_T (*)[1860])ssGetInputPortSignal(chartInstance->S, 2);
  c9_LL_PP = (real_T (*)[60])ssGetInputPortSignal(chartInstance->S, 1);
  c9_u_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_TT_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 0);
  c9_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, *c9_sfEvent);
  for (c9_i4 = 0; c9_i4 < 900; c9_i4++) {
    _SFD_DATA_RANGE_CHECK((*c9_TT_PP)[c9_i4], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c9_u_opt, 1U);
  for (c9_i5 = 0; c9_i5 < 60; c9_i5++) {
    _SFD_DATA_RANGE_CHECK((*c9_LL_PP)[c9_i5], 2U);
  }

  for (c9_i6 = 0; c9_i6 < 1860; c9_i6++) {
    _SFD_DATA_RANGE_CHECK((*c9_LL_ref_PP)[c9_i6], 3U);
  }

  for (c9_i7 = 0; c9_i7 < 900; c9_i7++) {
    _SFD_DATA_RANGE_CHECK((*c9_LL_U_ref_PP)[c9_i7], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c9_J_star, 5U);
  for (c9_i8 = 0; c9_i8 < 6; c9_i8++) {
    _SFD_DATA_RANGE_CHECK((*c9_u_buff_out)[c9_i8], 6U);
  }

  for (c9_i9 = 0; c9_i9 < 30; c9_i9++) {
    _SFD_DATA_RANGE_CHECK((*c9_V_init_out)[c9_i9], 7U);
  }

  for (c9_i10 = 0; c9_i10 < 4; c9_i10++) {
    _SFD_DATA_RANGE_CHECK((*c9_MM)[c9_i10], 8U);
  }

  for (c9_i11 = 0; c9_i11 < 900; c9_i11++) {
    _SFD_DATA_RANGE_CHECK((*c9_PP)[c9_i11], 9U);
  }

  for (c9_i12 = 0; c9_i12 < 4; c9_i12++) {
    _SFD_DATA_RANGE_CHECK((*c9_AA_delay)[c9_i12], 10U);
  }

  for (c9_i13 = 0; c9_i13 < 12; c9_i13++) {
    _SFD_DATA_RANGE_CHECK((*c9_BB_delay)[c9_i13], 11U);
  }

  for (c9_i14 = 0; c9_i14 < 2; c9_i14++) {
    _SFD_DATA_RANGE_CHECK((*c9_x)[c9_i14], 12U);
  }

  for (c9_i15 = 0; c9_i15 < 62; c9_i15++) {
    _SFD_DATA_RANGE_CHECK((*c9_X_ref)[c9_i15], 13U);
  }

  for (c9_i16 = 0; c9_i16 < 30; c9_i16++) {
    _SFD_DATA_RANGE_CHECK((*c9_V_max)[c9_i16], 14U);
  }

  _SFD_DATA_RANGE_CHECK(*c9_i_min, 15U);
  for (c9_i17 = 0; c9_i17 < 5; c9_i17++) {
    _SFD_DATA_RANGE_CHECK((*c9_betas)[c9_i17], 16U);
  }

  _SFD_DATA_RANGE_CHECK(*c9_L, 17U);
  for (c9_i18 = 0; c9_i18 < 6; c9_i18++) {
    _SFD_DATA_RANGE_CHECK((*c9_u_buff)[c9_i18], 18U);
  }

  for (c9_i19 = 0; c9_i19 < 30; c9_i19++) {
    _SFD_DATA_RANGE_CHECK((*c9_V_init)[c9_i19], 19U);
  }

  *c9_sfEvent = CALL_EVENT;
  c9_chartstep_c9_Hquad_control_LIB_MPC(chartInstance);
  sf_debug_check_for_state_inconsistency(_Hquad_control_LIB_MPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c9_chartstep_c9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  int32_T c9_i20;
  real_T c9_TT_PP[900];
  int32_T c9_i21;
  real_T c9_LL_PP[60];
  int32_T c9_i22;
  real_T c9_LL_ref_PP[1860];
  int32_T c9_i23;
  real_T c9_LL_U_ref_PP[900];
  int32_T c9_i24;
  real_T c9_MM[4];
  int32_T c9_i25;
  real_T c9_PP[900];
  int32_T c9_i26;
  real_T c9_AA_delay[4];
  int32_T c9_i27;
  real_T c9_BB_delay[12];
  int32_T c9_i28;
  real_T c9_x[2];
  int32_T c9_i29;
  real_T c9_X_ref[62];
  int32_T c9_i30;
  real_T c9_V_max[30];
  real_T c9_i_min;
  int32_T c9_i31;
  real_T c9_betas[5];
  real_T c9_L;
  int32_T c9_i32;
  real_T c9_u_buff[6];
  int32_T c9_i33;
  real_T c9_V_init[30];
  uint32_T c9_debug_family_var_map[32];
  real_T c9_m;
  real_T c9_delay_steps;
  real_T c9_N;
  real_T c9_x_predicted[2];
  real_T c9_U_ref[30];
  real_T c9_LL_PP_ref[30];
  real_T c9_MM_ref;
  real_T c9_V_star[30];
  real_T c9_unusedU0;
  real_T c9_b_unusedU0;
  real_T c9_U_star[30];
  real_T c9_nargin = 16.0;
  real_T c9_nargout = 4.0;
  real_T c9_u_opt;
  real_T c9_J_star;
  real_T c9_u_buff_out[6];
  real_T c9_V_init_out[30];
  int32_T c9_i34;
  real_T c9_a[4];
  int32_T c9_i35;
  real_T c9_b[2];
  int32_T c9_i36;
  real_T c9_y[2];
  int32_T c9_i37;
  int32_T c9_i38;
  int32_T c9_i39;
  real_T c9_b_a[12];
  int32_T c9_i40;
  real_T c9_b_b[6];
  int32_T c9_i41;
  int32_T c9_i42;
  int32_T c9_i43;
  int32_T c9_i44;
  int32_T c9_i45;
  int32_T c9_i46;
  real_T c9_c_a[2];
  int32_T c9_i47;
  real_T c9_c_b[60];
  int32_T c9_i48;
  int32_T c9_i49;
  real_T c9_b_y[30];
  int32_T c9_i50;
  int32_T c9_i51;
  real_T c9_d_a[62];
  int32_T c9_i52;
  real_T c9_d_b[1860];
  int32_T c9_i53;
  real_T c9_c_y[30];
  int32_T c9_i54;
  real_T c9_e_a[62];
  int32_T c9_i55;
  real_T c9_e_b[1860];
  int32_T c9_i56;
  real_T c9_f_b[900];
  int32_T c9_i57;
  real_T c9_d_y[30];
  int32_T c9_i58;
  real_T c9_dv2[30];
  int32_T c9_i59;
  real_T c9_g_b[900];
  int32_T c9_i60;
  int32_T c9_i61;
  int32_T c9_i62;
  int32_T c9_i63;
  int32_T c9_i64;
  real_T c9_e_y[2];
  int32_T c9_i65;
  int32_T c9_i66;
  int32_T c9_k;
  int32_T c9_b_k;
  int32_T c9_i67;
  real_T c9_b_TT_PP[900];
  int32_T c9_i68;
  real_T c9_b_LL_PP_ref[30];
  int32_T c9_i69;
  real_T c9_b_V_max[30];
  int32_T c9_i70;
  real_T c9_c_V_max[30];
  int32_T c9_i71;
  real_T c9_b_V_init[30];
  int32_T c9_i72;
  real_T c9_b_betas[5];
  real_T c9_c_unusedU0;
  real_T c9_b_V_star[30];
  real_T c9_b_J_star;
  int32_T c9_i73;
  int32_T c9_i74;
  int32_T c9_i75;
  int32_T c9_i76;
  int32_T c9_i77;
  int32_T c9_i78;
  real_T c9_h_b[900];
  int32_T c9_i79;
  real_T c9_c_V_star[30];
  int32_T c9_i80;
  int32_T c9_i81;
  int32_T c9_i82;
  int32_T c9_i83;
  real_T *c9_b_i_min;
  real_T *c9_b_L;
  real_T *c9_b_u_opt;
  real_T *c9_c_J_star;
  real_T (*c9_b_u_buff_out)[6];
  real_T (*c9_b_V_init_out)[30];
  real_T (*c9_c_V_init)[30];
  real_T (*c9_b_u_buff)[6];
  real_T (*c9_c_betas)[5];
  real_T (*c9_d_V_max)[30];
  real_T (*c9_b_X_ref)[62];
  real_T (*c9_b_x)[2];
  real_T (*c9_b_BB_delay)[12];
  real_T (*c9_b_AA_delay)[4];
  real_T (*c9_b_PP)[900];
  real_T (*c9_b_MM)[4];
  real_T (*c9_b_LL_U_ref_PP)[900];
  real_T (*c9_b_LL_ref_PP)[1860];
  real_T (*c9_b_LL_PP)[60];
  real_T (*c9_c_TT_PP)[900];
  int32_T *c9_sfEvent;
  c9_c_V_init = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 15);
  c9_b_u_buff = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 14);
  c9_b_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c9_c_betas = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 12);
  c9_b_i_min = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c9_d_V_max = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 10);
  c9_b_X_ref = (real_T (*)[62])ssGetInputPortSignal(chartInstance->S, 9);
  c9_b_x = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 8);
  c9_b_BB_delay = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 7);
  c9_b_AA_delay = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 6);
  c9_b_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 5);
  c9_b_MM = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
  c9_b_V_init_out = (real_T (*)[30])ssGetOutputPortSignal(chartInstance->S, 4);
  c9_b_u_buff_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S, 3);
  c9_c_J_star = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c9_b_LL_U_ref_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 3);
  c9_b_LL_ref_PP = (real_T (*)[1860])ssGetInputPortSignal(chartInstance->S, 2);
  c9_b_LL_PP = (real_T (*)[60])ssGetInputPortSignal(chartInstance->S, 1);
  c9_b_u_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c9_c_TT_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 0);
  c9_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, *c9_sfEvent);
  c9_hoistedGlobal = *c9_b_i_min;
  c9_b_hoistedGlobal = *c9_b_L;
  for (c9_i20 = 0; c9_i20 < 900; c9_i20++) {
    c9_TT_PP[c9_i20] = (*c9_c_TT_PP)[c9_i20];
  }

  for (c9_i21 = 0; c9_i21 < 60; c9_i21++) {
    c9_LL_PP[c9_i21] = (*c9_b_LL_PP)[c9_i21];
  }

  for (c9_i22 = 0; c9_i22 < 1860; c9_i22++) {
    c9_LL_ref_PP[c9_i22] = (*c9_b_LL_ref_PP)[c9_i22];
  }

  for (c9_i23 = 0; c9_i23 < 900; c9_i23++) {
    c9_LL_U_ref_PP[c9_i23] = (*c9_b_LL_U_ref_PP)[c9_i23];
  }

  for (c9_i24 = 0; c9_i24 < 4; c9_i24++) {
    c9_MM[c9_i24] = (*c9_b_MM)[c9_i24];
  }

  for (c9_i25 = 0; c9_i25 < 900; c9_i25++) {
    c9_PP[c9_i25] = (*c9_b_PP)[c9_i25];
  }

  for (c9_i26 = 0; c9_i26 < 4; c9_i26++) {
    c9_AA_delay[c9_i26] = (*c9_b_AA_delay)[c9_i26];
  }

  for (c9_i27 = 0; c9_i27 < 12; c9_i27++) {
    c9_BB_delay[c9_i27] = (*c9_b_BB_delay)[c9_i27];
  }

  for (c9_i28 = 0; c9_i28 < 2; c9_i28++) {
    c9_x[c9_i28] = (*c9_b_x)[c9_i28];
  }

  for (c9_i29 = 0; c9_i29 < 62; c9_i29++) {
    c9_X_ref[c9_i29] = (*c9_b_X_ref)[c9_i29];
  }

  for (c9_i30 = 0; c9_i30 < 30; c9_i30++) {
    c9_V_max[c9_i30] = (*c9_d_V_max)[c9_i30];
  }

  c9_i_min = c9_hoistedGlobal;
  for (c9_i31 = 0; c9_i31 < 5; c9_i31++) {
    c9_betas[c9_i31] = (*c9_c_betas)[c9_i31];
  }

  c9_L = c9_b_hoistedGlobal;
  for (c9_i32 = 0; c9_i32 < 6; c9_i32++) {
    c9_u_buff[c9_i32] = (*c9_b_u_buff)[c9_i32];
  }

  for (c9_i33 = 0; c9_i33 < 30; c9_i33++) {
    c9_V_init[c9_i33] = (*c9_c_V_init)[c9_i33];
  }

  sf_debug_symbol_scope_push_eml(0U, 32U, 33U, c9_debug_family_names,
    c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c9_m, 0U, c9_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_delay_steps, 1U, c9_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_N, 2U, c9_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c9_x_predicted, 3U,
    c9_f_sf_marshallOut, c9_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c9_U_ref, 4U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c9_LL_PP_ref, 5U, c9_l_sf_marshallOut,
    c9_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_MM_ref, 6U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_V_star, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_unusedU0, MAX_uint32_T,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_b_unusedU0, MAX_uint32_T,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_U_star, 9U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargin, 10U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargout, 11U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c9_TT_PP, 12U, c9_i_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_LL_PP, 13U, c9_k_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_LL_ref_PP, 14U, c9_j_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_LL_U_ref_PP, 15U, c9_i_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_MM, 16U, c9_h_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_PP, 17U, c9_i_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_AA_delay, 18U, c9_h_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_BB_delay, 19U, c9_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_x, 20U, c9_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_X_ref, 21U, c9_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_V_max, 22U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_i_min, 23U, c9_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_betas, 24U, c9_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c9_L, 25U, c9_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_u_buff, 26U, c9_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c9_V_init, 27U, c9_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c9_u_opt, 28U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_J_star, 29U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_u_buff_out, 30U,
    c9_b_sf_marshallOut, c9_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_V_init_out, 31U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c9_sfEvent, 6);
  c9_m = 1.0;
  _SFD_EML_CALL(0U, *c9_sfEvent, 7);
  c9_delay_steps = 6.0;
  _SFD_EML_CALL(0U, *c9_sfEvent, 8);
  c9_N = 30.0;
  _SFD_EML_CALL(0U, *c9_sfEvent, 11);
  CV_EML_IF(0, 1, 0, c9_delay_steps == 0.0);
  _SFD_EML_CALL(0U, *c9_sfEvent, 14);
  for (c9_i34 = 0; c9_i34 < 4; c9_i34++) {
    c9_a[c9_i34] = c9_AA_delay[c9_i34];
  }

  for (c9_i35 = 0; c9_i35 < 2; c9_i35++) {
    c9_b[c9_i35] = c9_x[c9_i35];
  }

  c9_eml_scalar_eg(chartInstance);
  c9_eml_scalar_eg(chartInstance);
  for (c9_i36 = 0; c9_i36 < 2; c9_i36++) {
    c9_y[c9_i36] = 0.0;
    c9_i37 = 0;
    for (c9_i38 = 0; c9_i38 < 2; c9_i38++) {
      c9_y[c9_i36] += c9_a[c9_i37 + c9_i36] * c9_b[c9_i38];
      c9_i37 += 2;
    }
  }

  for (c9_i39 = 0; c9_i39 < 12; c9_i39++) {
    c9_b_a[c9_i39] = c9_BB_delay[c9_i39];
  }

  for (c9_i40 = 0; c9_i40 < 6; c9_i40++) {
    c9_b_b[c9_i40] = c9_u_buff[c9_i40];
  }

  c9_b_eml_scalar_eg(chartInstance);
  c9_b_eml_scalar_eg(chartInstance);
  for (c9_i41 = 0; c9_i41 < 2; c9_i41++) {
    c9_b[c9_i41] = 0.0;
    c9_i42 = 0;
    for (c9_i43 = 0; c9_i43 < 6; c9_i43++) {
      c9_b[c9_i41] += c9_b_a[c9_i42 + c9_i41] * c9_b_b[c9_i43];
      c9_i42 += 2;
    }
  }

  for (c9_i44 = 0; c9_i44 < 2; c9_i44++) {
    c9_x_predicted[c9_i44] = c9_y[c9_i44] + c9_b[c9_i44];
  }

  _SFD_EML_CALL(0U, *c9_sfEvent, 18);
  for (c9_i45 = 0; c9_i45 < 30; c9_i45++) {
    c9_U_ref[c9_i45] = 0.0;
  }

  _SFD_EML_CALL(0U, *c9_sfEvent, 21);
  for (c9_i46 = 0; c9_i46 < 2; c9_i46++) {
    c9_c_a[c9_i46] = c9_x_predicted[c9_i46];
  }

  for (c9_i47 = 0; c9_i47 < 60; c9_i47++) {
    c9_c_b[c9_i47] = c9_LL_PP[c9_i47];
  }

  c9_c_eml_scalar_eg(chartInstance);
  c9_c_eml_scalar_eg(chartInstance);
  c9_i48 = 0;
  for (c9_i49 = 0; c9_i49 < 30; c9_i49++) {
    c9_b_y[c9_i49] = 0.0;
    for (c9_i50 = 0; c9_i50 < 2; c9_i50++) {
      c9_b_y[c9_i49] += c9_c_a[c9_i50] * c9_c_b[c9_i50 + c9_i48];
    }

    c9_i48 += 2;
  }

  for (c9_i51 = 0; c9_i51 < 62; c9_i51++) {
    c9_d_a[c9_i51] = c9_X_ref[c9_i51];
  }

  for (c9_i52 = 0; c9_i52 < 1860; c9_i52++) {
    c9_d_b[c9_i52] = c9_LL_ref_PP[c9_i52];
  }

  c9_d_eml_scalar_eg(chartInstance);
  c9_d_eml_scalar_eg(chartInstance);
  for (c9_i53 = 0; c9_i53 < 30; c9_i53++) {
    c9_c_y[c9_i53] = 0.0;
  }

  for (c9_i54 = 0; c9_i54 < 62; c9_i54++) {
    c9_e_a[c9_i54] = c9_d_a[c9_i54];
  }

  for (c9_i55 = 0; c9_i55 < 1860; c9_i55++) {
    c9_e_b[c9_i55] = c9_d_b[c9_i55];
  }

  c9_d_eml_xgemm(chartInstance, c9_e_a, c9_e_b, c9_c_y);
  for (c9_i56 = 0; c9_i56 < 900; c9_i56++) {
    c9_f_b[c9_i56] = c9_LL_U_ref_PP[c9_i56];
  }

  c9_e_eml_scalar_eg(chartInstance);
  c9_e_eml_scalar_eg(chartInstance);
  for (c9_i57 = 0; c9_i57 < 30; c9_i57++) {
    c9_d_y[c9_i57] = 0.0;
  }

  for (c9_i58 = 0; c9_i58 < 30; c9_i58++) {
    c9_dv2[c9_i58] = 0.0;
  }

  for (c9_i59 = 0; c9_i59 < 900; c9_i59++) {
    c9_g_b[c9_i59] = c9_f_b[c9_i59];
  }

  c9_e_eml_xgemm(chartInstance, c9_dv2, c9_g_b, c9_d_y);
  for (c9_i60 = 0; c9_i60 < 30; c9_i60++) {
    c9_LL_PP_ref[c9_i60] = (c9_b_y[c9_i60] - c9_c_y[c9_i60]) - c9_d_y[c9_i60];
  }

  _SFD_EML_CALL(0U, *c9_sfEvent, 22);
  for (c9_i61 = 0; c9_i61 < 2; c9_i61++) {
    c9_c_a[c9_i61] = c9_x_predicted[c9_i61];
  }

  for (c9_i62 = 0; c9_i62 < 4; c9_i62++) {
    c9_a[c9_i62] = c9_MM[c9_i62];
  }

  c9_f_eml_scalar_eg(chartInstance);
  c9_f_eml_scalar_eg(chartInstance);
  c9_i63 = 0;
  for (c9_i64 = 0; c9_i64 < 2; c9_i64++) {
    c9_e_y[c9_i64] = 0.0;
    for (c9_i65 = 0; c9_i65 < 2; c9_i65++) {
      c9_e_y[c9_i64] += c9_c_a[c9_i65] * c9_a[c9_i65 + c9_i63];
    }

    c9_i63 += 2;
  }

  for (c9_i66 = 0; c9_i66 < 2; c9_i66++) {
    c9_b[c9_i66] = c9_x_predicted[c9_i66];
  }

  c9_g_eml_scalar_eg(chartInstance);
  c9_g_eml_scalar_eg(chartInstance);
  c9_MM_ref = 0.0;
  for (c9_k = 1; c9_k < 3; c9_k++) {
    c9_b_k = c9_k;
    c9_MM_ref += c9_e_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c9_b_k), 1, 2, 1, 0) - 1] *
      c9_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c9_b_k), 1, 2, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, *c9_sfEvent, 25);
  for (c9_i67 = 0; c9_i67 < 900; c9_i67++) {
    c9_b_TT_PP[c9_i67] = c9_TT_PP[c9_i67];
  }

  for (c9_i68 = 0; c9_i68 < 30; c9_i68++) {
    c9_b_LL_PP_ref[c9_i68] = c9_LL_PP_ref[c9_i68];
  }

  for (c9_i69 = 0; c9_i69 < 30; c9_i69++) {
    c9_b_V_max[c9_i69] = -c9_V_max[c9_i69];
  }

  for (c9_i70 = 0; c9_i70 < 30; c9_i70++) {
    c9_c_V_max[c9_i70] = c9_V_max[c9_i70];
  }

  for (c9_i71 = 0; c9_i71 < 30; c9_i71++) {
    c9_b_V_init[c9_i71] = c9_V_init[c9_i71];
  }

  for (c9_i72 = 0; c9_i72 < 5; c9_i72++) {
    c9_b_betas[c9_i72] = c9_betas[c9_i72];
  }

  c9_runFastGradient(chartInstance, c9_b_TT_PP, c9_b_LL_PP_ref, c9_MM_ref,
                     c9_b_V_max, c9_c_V_max, c9_b_V_init, c9_i_min, c9_b_betas,
                     c9_L, &c9_b_J_star, c9_b_V_star, &c9_c_unusedU0);
  c9_J_star = c9_b_J_star;
  for (c9_i73 = 0; c9_i73 < 30; c9_i73++) {
    c9_V_star[c9_i73] = c9_b_V_star[c9_i73];
  }

  c9_unusedU0 = c9_c_unusedU0;
  sf_debug_symbol_switch(8U, 8U);
  _SFD_EML_CALL(0U, *c9_sfEvent, 25);
  c9_b_unusedU0 = 0.0;
  sf_debug_symbol_switch(8U, 9U);
  _SFD_EML_CALL(0U, *c9_sfEvent, 32);
  for (c9_i74 = 0; c9_i74 < 900; c9_i74++) {
    c9_f_b[c9_i74] = c9_PP[c9_i74];
  }

  for (c9_i75 = 0; c9_i75 < 30; c9_i75++) {
    c9_b_V_star[c9_i75] = c9_V_star[c9_i75];
  }

  c9_h_eml_scalar_eg(chartInstance);
  c9_h_eml_scalar_eg(chartInstance);
  for (c9_i76 = 0; c9_i76 < 30; c9_i76++) {
    c9_U_star[c9_i76] = 0.0;
  }

  for (c9_i77 = 0; c9_i77 < 30; c9_i77++) {
    c9_U_star[c9_i77] = 0.0;
  }

  for (c9_i78 = 0; c9_i78 < 900; c9_i78++) {
    c9_h_b[c9_i78] = c9_f_b[c9_i78];
  }

  for (c9_i79 = 0; c9_i79 < 30; c9_i79++) {
    c9_c_V_star[c9_i79] = c9_b_V_star[c9_i79];
  }

  c9_f_eml_xgemm(chartInstance, c9_h_b, c9_c_V_star, c9_U_star);
  _SFD_EML_CALL(0U, *c9_sfEvent, 35);
  CV_EML_IF(0, 1, 1, c9_delay_steps == 0.0);
  _SFD_EML_CALL(0U, *c9_sfEvent, 38);
  for (c9_i80 = 0; c9_i80 < 5; c9_i80++) {
    c9_u_buff_out[c9_i80] = c9_u_buff[c9_i80 + 1];
  }

  c9_u_buff_out[5] = c9_U_star[0];
  _SFD_EML_CALL(0U, *c9_sfEvent, 42);
  for (c9_i81 = 0; c9_i81 < 29; c9_i81++) {
    c9_V_init_out[c9_i81] = c9_V_star[c9_i81 + 1];
  }

  c9_V_init_out[29] = 0.0;
  _SFD_EML_CALL(0U, *c9_sfEvent, 44);
  c9_u_opt = c9_U_star[0];
  _SFD_EML_CALL(0U, *c9_sfEvent, -44);
  sf_debug_symbol_scope_pop();
  *c9_b_u_opt = c9_u_opt;
  *c9_c_J_star = c9_J_star;
  for (c9_i82 = 0; c9_i82 < 6; c9_i82++) {
    (*c9_b_u_buff_out)[c9_i82] = c9_u_buff_out[c9_i82];
  }

  for (c9_i83 = 0; c9_i83 < 30; c9_i83++) {
    (*c9_b_V_init_out)[c9_i83] = c9_V_init_out[c9_i83];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *c9_sfEvent);
}

static void initSimStructsc9_Hquad_control_LIB_MPC
  (SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, 0U, sf_debug_get_script_id(
    "/home/burrimi/git/darivianakis/SimulatorQuadrocopter/MPC_FastGradient/tools/runFastGradient.m"));
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i84;
  real_T c9_b_inData[30];
  int32_T c9_i85;
  real_T c9_u[30];
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i84 = 0; c9_i84 < 30; c9_i84++) {
    c9_b_inData[c9_i84] = (*(real_T (*)[30])c9_inData)[c9_i84];
  }

  for (c9_i85 = 0; c9_i85 < 30; c9_i85++) {
    c9_u[c9_i85] = c9_b_inData[c9_i85];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 30), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_V_init_out, const char_T *c9_identifier,
  real_T c9_y[30])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_V_init_out), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_V_init_out);
}

static void c9_b_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[30])
{
  real_T c9_dv3[30];
  int32_T c9_i86;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv3, 1, 0, 0U, 1, 0U, 1, 30);
  for (c9_i86 = 0; c9_i86 < 30; c9_i86++) {
    c9_y[c9_i86] = c9_dv3[c9_i86];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_V_init_out;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[30];
  int32_T c9_i87;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_V_init_out = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_V_init_out), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_V_init_out);
  for (c9_i87 = 0; c9_i87 < 30; c9_i87++) {
    (*(real_T (*)[30])c9_outData)[c9_i87] = c9_y[c9_i87];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i88;
  real_T c9_b_inData[6];
  int32_T c9_i89;
  real_T c9_u[6];
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i88 = 0; c9_i88 < 6; c9_i88++) {
    c9_b_inData[c9_i88] = (*(real_T (*)[6])c9_inData)[c9_i88];
  }

  for (c9_i89 = 0; c9_i89 < 6; c9_i89++) {
    c9_u[c9_i89] = c9_b_inData[c9_i89];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 6), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_c_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u_buff_out, const char_T *c9_identifier,
  real_T c9_y[6])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_u_buff_out), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_u_buff_out);
}

static void c9_d_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[6])
{
  real_T c9_dv4[6];
  int32_T c9_i90;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv4, 1, 0, 0U, 1, 0U, 1, 6);
  for (c9_i90 = 0; c9_i90 < 6; c9_i90++) {
    c9_y[c9_i90] = c9_dv4[c9_i90];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_u_buff_out;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[6];
  int32_T c9_i91;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_u_buff_out = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_u_buff_out), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_u_buff_out);
  for (c9_i91 = 0; c9_i91 < 6; c9_i91++) {
    (*(real_T (*)[6])c9_outData)[c9_i91] = c9_y[c9_i91];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_e_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_J_star, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_J_star), &c9_thisId);
  sf_mex_destroy(&c9_J_star);
  return c9_y;
}

static real_T c9_f_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_J_star;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_J_star = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_J_star), &c9_thisId);
  sf_mex_destroy(&c9_J_star);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i92;
  real_T c9_b_inData[5];
  int32_T c9_i93;
  real_T c9_u[5];
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i92 = 0; c9_i92 < 5; c9_i92++) {
    c9_b_inData[c9_i92] = (*(real_T (*)[5])c9_inData)[c9_i92];
  }

  for (c9_i93 = 0; c9_i93 < 5; c9_i93++) {
    c9_u[c9_i93] = c9_b_inData[c9_i93];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 5), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i94;
  real_T c9_b_inData[62];
  int32_T c9_i95;
  real_T c9_u[62];
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i94 = 0; c9_i94 < 62; c9_i94++) {
    c9_b_inData[c9_i94] = (*(real_T (*)[62])c9_inData)[c9_i94];
  }

  for (c9_i95 = 0; c9_i95 < 62; c9_i95++) {
    c9_u[c9_i95] = c9_b_inData[c9_i95];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 62), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i96;
  real_T c9_b_inData[2];
  int32_T c9_i97;
  real_T c9_u[2];
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i96 = 0; c9_i96 < 2; c9_i96++) {
    c9_b_inData[c9_i96] = (*(real_T (*)[2])c9_inData)[c9_i96];
  }

  for (c9_i97 = 0; c9_i97 < 2; c9_i97++) {
    c9_u[c9_i97] = c9_b_inData[c9_i97];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i98;
  int32_T c9_i99;
  int32_T c9_i100;
  real_T c9_b_inData[12];
  int32_T c9_i101;
  int32_T c9_i102;
  int32_T c9_i103;
  real_T c9_u[12];
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i98 = 0;
  for (c9_i99 = 0; c9_i99 < 6; c9_i99++) {
    for (c9_i100 = 0; c9_i100 < 2; c9_i100++) {
      c9_b_inData[c9_i100 + c9_i98] = (*(real_T (*)[12])c9_inData)[c9_i100 +
        c9_i98];
    }

    c9_i98 += 2;
  }

  c9_i101 = 0;
  for (c9_i102 = 0; c9_i102 < 6; c9_i102++) {
    for (c9_i103 = 0; c9_i103 < 2; c9_i103++) {
      c9_u[c9_i103 + c9_i101] = c9_b_inData[c9_i103 + c9_i101];
    }

    c9_i101 += 2;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 2, 6), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i104;
  int32_T c9_i105;
  int32_T c9_i106;
  real_T c9_b_inData[4];
  int32_T c9_i107;
  int32_T c9_i108;
  int32_T c9_i109;
  real_T c9_u[4];
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i104 = 0;
  for (c9_i105 = 0; c9_i105 < 2; c9_i105++) {
    for (c9_i106 = 0; c9_i106 < 2; c9_i106++) {
      c9_b_inData[c9_i106 + c9_i104] = (*(real_T (*)[4])c9_inData)[c9_i106 +
        c9_i104];
    }

    c9_i104 += 2;
  }

  c9_i107 = 0;
  for (c9_i108 = 0; c9_i108 < 2; c9_i108++) {
    for (c9_i109 = 0; c9_i109 < 2; c9_i109++) {
      c9_u[c9_i109 + c9_i107] = c9_b_inData[c9_i109 + c9_i107];
    }

    c9_i107 += 2;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i110;
  int32_T c9_i111;
  int32_T c9_i112;
  real_T c9_b_inData[900];
  int32_T c9_i113;
  int32_T c9_i114;
  int32_T c9_i115;
  real_T c9_u[900];
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i110 = 0;
  for (c9_i111 = 0; c9_i111 < 30; c9_i111++) {
    for (c9_i112 = 0; c9_i112 < 30; c9_i112++) {
      c9_b_inData[c9_i112 + c9_i110] = (*(real_T (*)[900])c9_inData)[c9_i112 +
        c9_i110];
    }

    c9_i110 += 30;
  }

  c9_i113 = 0;
  for (c9_i114 = 0; c9_i114 < 30; c9_i114++) {
    for (c9_i115 = 0; c9_i115 < 30; c9_i115++) {
      c9_u[c9_i115 + c9_i113] = c9_b_inData[c9_i115 + c9_i113];
    }

    c9_i113 += 30;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 30, 30), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_j_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i116;
  int32_T c9_i117;
  int32_T c9_i118;
  real_T c9_b_inData[1860];
  int32_T c9_i119;
  int32_T c9_i120;
  int32_T c9_i121;
  real_T c9_u[1860];
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i116 = 0;
  for (c9_i117 = 0; c9_i117 < 30; c9_i117++) {
    for (c9_i118 = 0; c9_i118 < 62; c9_i118++) {
      c9_b_inData[c9_i118 + c9_i116] = (*(real_T (*)[1860])c9_inData)[c9_i118 +
        c9_i116];
    }

    c9_i116 += 62;
  }

  c9_i119 = 0;
  for (c9_i120 = 0; c9_i120 < 30; c9_i120++) {
    for (c9_i121 = 0; c9_i121 < 62; c9_i121++) {
      c9_u[c9_i121 + c9_i119] = c9_b_inData[c9_i121 + c9_i119];
    }

    c9_i119 += 62;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 62, 30), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_k_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i122;
  int32_T c9_i123;
  int32_T c9_i124;
  real_T c9_b_inData[60];
  int32_T c9_i125;
  int32_T c9_i126;
  int32_T c9_i127;
  real_T c9_u[60];
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i122 = 0;
  for (c9_i123 = 0; c9_i123 < 30; c9_i123++) {
    for (c9_i124 = 0; c9_i124 < 2; c9_i124++) {
      c9_b_inData[c9_i124 + c9_i122] = (*(real_T (*)[60])c9_inData)[c9_i124 +
        c9_i122];
    }

    c9_i122 += 2;
  }

  c9_i125 = 0;
  for (c9_i126 = 0; c9_i126 < 30; c9_i126++) {
    for (c9_i127 = 0; c9_i127 < 2; c9_i127++) {
      c9_u[c9_i127 + c9_i125] = c9_b_inData[c9_i127 + c9_i125];
    }

    c9_i125 += 2;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 2, 30), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_l_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i128;
  real_T c9_b_inData[30];
  int32_T c9_i129;
  real_T c9_u[30];
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i128 = 0; c9_i128 < 30; c9_i128++) {
    c9_b_inData[c9_i128] = (*(real_T (*)[30])c9_inData)[c9_i128];
  }

  for (c9_i129 = 0; c9_i129 < 30; c9_i129++) {
    c9_u[c9_i129] = c9_b_inData[c9_i129];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_g_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[30])
{
  real_T c9_dv5[30];
  int32_T c9_i130;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv5, 1, 0, 0U, 1, 0U, 2, 1, 30);
  for (c9_i130 = 0; c9_i130 < 30; c9_i130++) {
    c9_y[c9_i130] = c9_dv5[c9_i130];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_LL_PP_ref;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[30];
  int32_T c9_i131;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_LL_PP_ref = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_LL_PP_ref), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_LL_PP_ref);
  for (c9_i131 = 0; c9_i131 < 30; c9_i131++) {
    (*(real_T (*)[30])c9_outData)[c9_i131] = c9_y[c9_i131];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static void c9_h_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[2])
{
  real_T c9_dv6[2];
  int32_T c9_i132;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv6, 1, 0, 0U, 1, 0U, 1, 2);
  for (c9_i132 = 0; c9_i132 < 2; c9_i132++) {
    c9_y[c9_i132] = c9_dv6[c9_i132];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_x_predicted;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[2];
  int32_T c9_i133;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_x_predicted = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_x_predicted), &c9_thisId,
                        c9_y);
  sf_mex_destroy(&c9_x_predicted);
  for (c9_i133 = 0; c9_i133 < 2; c9_i133++) {
    (*(real_T (*)[2])c9_outData)[c9_i133] = c9_y[c9_i133];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static void c9_i_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[5])
{
  real_T c9_dv7[5];
  int32_T c9_i134;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv7, 1, 0, 0U, 1, 0U, 1, 5);
  for (c9_i134 = 0; c9_i134 < 5; c9_i134++) {
    c9_y[c9_i134] = c9_dv7[c9_i134];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_betas;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[5];
  int32_T c9_i135;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_betas = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_betas), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_betas);
  for (c9_i135 = 0; c9_i135 < 5; c9_i135++) {
    (*(real_T (*)[5])c9_outData)[c9_i135] = c9_y[c9_i135];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static void c9_j_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[900])
{
  real_T c9_dv8[900];
  int32_T c9_i136;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv8, 1, 0, 0U, 1, 0U, 2, 30,
                30);
  for (c9_i136 = 0; c9_i136 < 900; c9_i136++) {
    c9_y[c9_i136] = c9_dv8[c9_i136];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_TT_PP;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[900];
  int32_T c9_i137;
  int32_T c9_i138;
  int32_T c9_i139;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_TT_PP = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_TT_PP), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_TT_PP);
  c9_i137 = 0;
  for (c9_i138 = 0; c9_i138 < 30; c9_i138++) {
    for (c9_i139 = 0; c9_i139 < 30; c9_i139++) {
      (*(real_T (*)[900])c9_outData)[c9_i139 + c9_i137] = c9_y[c9_i139 + c9_i137];
    }

    c9_i137 += 30;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_m_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

const mxArray *sf_c9_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo;
  c9_ResolvedFunctionInfo c9_info[24];
  const mxArray *c9_m0 = NULL;
  int32_T c9_i140;
  c9_ResolvedFunctionInfo *c9_r0;
  c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  c9_info_helper(c9_info);
  sf_mex_assign(&c9_m0, sf_mex_createstruct("nameCaptureInfo", 1, 24), FALSE);
  for (c9_i140 = 0; c9_i140 < 24; c9_i140++) {
    c9_r0 = &c9_info[c9_i140];
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->context)), "context", "nameCaptureInfo",
                    c9_i140);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c9_r0->name)), "name", "nameCaptureInfo", c9_i140);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c9_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c9_i140);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", c9_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c9_r0->resolved)), "resolved", "nameCaptureInfo",
                    c9_i140);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c9_i140);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c9_i140);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c9_i140);
    sf_mex_addfield(c9_m0, sf_mex_create("nameCaptureInfo", &c9_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c9_i140);
  }

  sf_mex_assign(&c9_nameCaptureInfo, c9_m0, FALSE);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(c9_ResolvedFunctionInfo c9_info[24])
{
  c9_info[0].context = "";
  c9_info[0].name = "mtimes";
  c9_info[0].dominantType = "double";
  c9_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[0].fileTimeLo = 1289519692U;
  c9_info[0].fileTimeHi = 0U;
  c9_info[0].mFileTimeLo = 0U;
  c9_info[0].mFileTimeHi = 0U;
  c9_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[1].name = "eml_index_class";
  c9_info[1].dominantType = "";
  c9_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c9_info[1].fileTimeLo = 1286818778U;
  c9_info[1].fileTimeHi = 0U;
  c9_info[1].mFileTimeLo = 0U;
  c9_info[1].mFileTimeHi = 0U;
  c9_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[2].name = "eml_scalar_eg";
  c9_info[2].dominantType = "double";
  c9_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c9_info[2].fileTimeLo = 1286818796U;
  c9_info[2].fileTimeHi = 0U;
  c9_info[2].mFileTimeLo = 0U;
  c9_info[2].mFileTimeHi = 0U;
  c9_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[3].name = "eml_xgemm";
  c9_info[3].dominantType = "int32";
  c9_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c9_info[3].fileTimeLo = 1299076772U;
  c9_info[3].fileTimeHi = 0U;
  c9_info[3].mFileTimeLo = 0U;
  c9_info[3].mFileTimeHi = 0U;
  c9_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c9_info[4].name = "eml_blas_inline";
  c9_info[4].dominantType = "";
  c9_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c9_info[4].fileTimeLo = 1299076768U;
  c9_info[4].fileTimeHi = 0U;
  c9_info[4].mFileTimeLo = 0U;
  c9_info[4].mFileTimeHi = 0U;
  c9_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c9_info[5].name = "eml_refblas_xgemm";
  c9_info[5].dominantType = "int32";
  c9_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c9_info[5].fileTimeLo = 1299076774U;
  c9_info[5].fileTimeHi = 0U;
  c9_info[5].mFileTimeLo = 0U;
  c9_info[5].mFileTimeHi = 0U;
  c9_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c9_info[6].name = "eml_xdotu";
  c9_info[6].dominantType = "int32";
  c9_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c9_info[6].fileTimeLo = 1299076772U;
  c9_info[6].fileTimeHi = 0U;
  c9_info[6].mFileTimeLo = 0U;
  c9_info[6].mFileTimeHi = 0U;
  c9_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c9_info[7].name = "eml_xdot";
  c9_info[7].dominantType = "int32";
  c9_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c9_info[7].fileTimeLo = 1299076772U;
  c9_info[7].fileTimeHi = 0U;
  c9_info[7].mFileTimeLo = 0U;
  c9_info[7].mFileTimeHi = 0U;
  c9_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c9_info[8].name = "eml_refblas_xdot";
  c9_info[8].dominantType = "int32";
  c9_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c9_info[8].fileTimeLo = 1299076772U;
  c9_info[8].fileTimeHi = 0U;
  c9_info[8].mFileTimeLo = 0U;
  c9_info[8].mFileTimeHi = 0U;
  c9_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c9_info[9].name = "eml_refblas_xdotx";
  c9_info[9].dominantType = "int32";
  c9_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c9_info[9].fileTimeLo = 1299076774U;
  c9_info[9].fileTimeHi = 0U;
  c9_info[9].mFileTimeLo = 0U;
  c9_info[9].mFileTimeHi = 0U;
  c9_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c9_info[10].name = "eml_index_minus";
  c9_info[10].dominantType = "int32";
  c9_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c9_info[10].fileTimeLo = 1286818778U;
  c9_info[10].fileTimeHi = 0U;
  c9_info[10].mFileTimeLo = 0U;
  c9_info[10].mFileTimeHi = 0U;
  c9_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c9_info[11].name = "eml_index_times";
  c9_info[11].dominantType = "int32";
  c9_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c9_info[11].fileTimeLo = 1286818780U;
  c9_info[11].fileTimeHi = 0U;
  c9_info[11].mFileTimeLo = 0U;
  c9_info[11].mFileTimeHi = 0U;
  c9_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c9_info[12].name = "eml_index_plus";
  c9_info[12].dominantType = "int32";
  c9_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c9_info[12].fileTimeLo = 1286818778U;
  c9_info[12].fileTimeHi = 0U;
  c9_info[12].mFileTimeLo = 0U;
  c9_info[12].mFileTimeHi = 0U;
  c9_info[13].context = "";
  c9_info[13].name = "runFastGradient";
  c9_info[13].dominantType = "double";
  c9_info[13].resolved =
    "[E]/home/burrimi/git/darivianakis/SimulatorQuadrocopter/MPC_FastGradient/tools/runFastGradient.m";
  c9_info[13].fileTimeLo = 1367485014U;
  c9_info[13].fileTimeHi = 0U;
  c9_info[13].mFileTimeLo = 0U;
  c9_info[13].mFileTimeHi = 0U;
  c9_info[14].context =
    "[E]/home/burrimi/git/darivianakis/SimulatorQuadrocopter/MPC_FastGradient/tools/runFastGradient.m";
  c9_info[14].name = "mrdivide";
  c9_info[14].dominantType = "double";
  c9_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c9_info[14].fileTimeLo = 1310137456U;
  c9_info[14].fileTimeHi = 0U;
  c9_info[14].mFileTimeLo = 1289519692U;
  c9_info[14].mFileTimeHi = 0U;
  c9_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c9_info[15].name = "rdivide";
  c9_info[15].dominantType = "double";
  c9_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[15].fileTimeLo = 1286818844U;
  c9_info[15].fileTimeHi = 0U;
  c9_info[15].mFileTimeLo = 0U;
  c9_info[15].mFileTimeHi = 0U;
  c9_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c9_info[16].name = "eml_div";
  c9_info[16].dominantType = "double";
  c9_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c9_info[16].fileTimeLo = 1305318000U;
  c9_info[16].fileTimeHi = 0U;
  c9_info[16].mFileTimeLo = 0U;
  c9_info[16].mFileTimeHi = 0U;
  c9_info[17].context =
    "[E]/home/burrimi/git/darivianakis/SimulatorQuadrocopter/MPC_FastGradient/tools/runFastGradient.m";
  c9_info[17].name = "min";
  c9_info[17].dominantType = "double";
  c9_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[17].fileTimeLo = 1308747330U;
  c9_info[17].fileTimeHi = 0U;
  c9_info[17].mFileTimeLo = 0U;
  c9_info[17].mFileTimeHi = 0U;
  c9_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c9_info[18].name = "eml_min_or_max";
  c9_info[18].dominantType = "char";
  c9_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c9_info[18].fileTimeLo = 1303146212U;
  c9_info[18].fileTimeHi = 0U;
  c9_info[18].mFileTimeLo = 0U;
  c9_info[18].mFileTimeHi = 0U;
  c9_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c9_info[19].name = "eml_scalexp_alloc";
  c9_info[19].dominantType = "double";
  c9_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[19].fileTimeLo = 1286818796U;
  c9_info[19].fileTimeHi = 0U;
  c9_info[19].mFileTimeLo = 0U;
  c9_info[19].mFileTimeHi = 0U;
  c9_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c9_info[20].name = "isequal";
  c9_info[20].dominantType = "double";
  c9_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c9_info[20].fileTimeLo = 1286818758U;
  c9_info[20].fileTimeHi = 0U;
  c9_info[20].mFileTimeLo = 0U;
  c9_info[20].mFileTimeHi = 0U;
  c9_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c9_info[21].name = "eml_isequal_core";
  c9_info[21].dominantType = "double";
  c9_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c9_info[21].fileTimeLo = 1286818786U;
  c9_info[21].fileTimeHi = 0U;
  c9_info[21].mFileTimeLo = 0U;
  c9_info[21].mFileTimeHi = 0U;
  c9_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  c9_info[22].name = "isnan";
  c9_info[22].dominantType = "double";
  c9_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c9_info[22].fileTimeLo = 1286818760U;
  c9_info[22].fileTimeHi = 0U;
  c9_info[22].mFileTimeLo = 0U;
  c9_info[22].mFileTimeHi = 0U;
  c9_info[23].context =
    "[E]/home/burrimi/git/darivianakis/SimulatorQuadrocopter/MPC_FastGradient/tools/runFastGradient.m";
  c9_info[23].name = "max";
  c9_info[23].dominantType = "double";
  c9_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c9_info[23].fileTimeLo = 1308747328U;
  c9_info[23].fileTimeHi = 0U;
  c9_info[23].mFileTimeLo = 0U;
  c9_info[23].mFileTimeHi = 0U;
}

static void c9_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c9_b_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c9_c_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c9_d_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c9_eml_xgemm(SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c9_A[62], real_T c9_B[1860], real_T c9_C[30], real_T c9_b_C[30])
{
  int32_T c9_i141;
  int32_T c9_i142;
  real_T c9_b_A[62];
  int32_T c9_i143;
  real_T c9_b_B[1860];
  for (c9_i141 = 0; c9_i141 < 30; c9_i141++) {
    c9_b_C[c9_i141] = c9_C[c9_i141];
  }

  for (c9_i142 = 0; c9_i142 < 62; c9_i142++) {
    c9_b_A[c9_i142] = c9_A[c9_i142];
  }

  for (c9_i143 = 0; c9_i143 < 1860; c9_i143++) {
    c9_b_B[c9_i143] = c9_B[c9_i143];
  }

  c9_d_eml_xgemm(chartInstance, c9_b_A, c9_b_B, c9_b_C);
}

static void c9_e_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c9_b_eml_xgemm(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_A[30], real_T c9_B[900], real_T c9_C[30], real_T
  c9_b_C[30])
{
  int32_T c9_i144;
  int32_T c9_i145;
  real_T c9_b_A[30];
  int32_T c9_i146;
  real_T c9_b_B[900];
  for (c9_i144 = 0; c9_i144 < 30; c9_i144++) {
    c9_b_C[c9_i144] = c9_C[c9_i144];
  }

  for (c9_i145 = 0; c9_i145 < 30; c9_i145++) {
    c9_b_A[c9_i145] = c9_A[c9_i145];
  }

  for (c9_i146 = 0; c9_i146 < 900; c9_i146++) {
    c9_b_B[c9_i146] = c9_B[c9_i146];
  }

  c9_e_eml_xgemm(chartInstance, c9_b_A, c9_b_B, c9_b_C);
}

static void c9_f_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c9_g_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c9_runFastGradient(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_TT_PP[900], real_T c9_LL_PP[30], real_T c9_MM,
  real_T c9_V_min[30], real_T c9_V_max[30], real_T c9_V_init[30], real_T
  c9_i_min, real_T c9_betas[5], real_T c9_L, real_T *c9_J, real_T c9_V[30],
  real_T *c9_actual_num_iters)
{
  uint32_T c9_debug_family_var_map[22];
  real_T c9_MONITOR;
  real_T c9_L_inv;
  real_T c9_LL_PP_t[30];
  real_T c9_V_i[30];
  real_T c9_W_i[30];
  real_T c9_V_ip1[30];
  real_T c9_W_ip1[30];
  real_T c9_nargin = 10.0;
  real_T c9_nargout = 3.0;
  int32_T c9_i147;
  int32_T c9_i148;
  real_T c9_a[900];
  int32_T c9_i149;
  real_T c9_b[30];
  int32_T c9_i150;
  real_T c9_y[30];
  int32_T c9_i151;
  real_T c9_b_a[900];
  int32_T c9_i152;
  real_T c9_b_b[30];
  real_T c9_c_a;
  int32_T c9_i153;
  int32_T c9_i154;
  int32_T c9_i155;
  int32_T c9_i156;
  int32_T c9_k;
  int32_T c9_b_k;
  real_T c9_xk;
  real_T c9_yk;
  real_T c9_x;
  real_T c9_b_y;
  real_T c9_extremum;
  real_T c9_minval[30];
  int32_T c9_i157;
  int32_T c9_c_k;
  int32_T c9_d_k;
  real_T c9_b_xk;
  real_T c9_b_yk;
  real_T c9_b_x;
  real_T c9_c_y;
  real_T c9_b_extremum;
  int32_T c9_i158;
  int32_T c9_i159;
  int32_T c9_loop_ub;
  int32_T c9_i;
  real_T c9_b_i;
  int32_T c9_i160;
  int32_T c9_i161;
  int32_T c9_i162;
  int32_T c9_i163;
  real_T c9_d_a[900];
  int32_T c9_i164;
  real_T c9_c_b[30];
  real_T c9_e_a;
  int32_T c9_i165;
  int32_T c9_i166;
  int32_T c9_i167;
  int32_T c9_i168;
  int32_T c9_e_k;
  int32_T c9_f_k;
  real_T c9_c_xk;
  real_T c9_c_yk;
  real_T c9_c_x;
  real_T c9_d_y;
  real_T c9_c_extremum;
  int32_T c9_i169;
  int32_T c9_g_k;
  int32_T c9_h_k;
  real_T c9_d_xk;
  real_T c9_d_yk;
  real_T c9_d_x;
  real_T c9_e_y;
  real_T c9_d_extremum;
  real_T c9_f_a;
  int32_T c9_i170;
  int32_T c9_i171;
  int32_T c9_i172;
  int32_T c9_i173;
  int32_T c9_i174;
  int32_T c9_i175;
  int32_T c9_i176;
  real_T c9_d_b[30];
  int32_T c9_i177;
  int32_T c9_i178;
  int32_T c9_i179;
  real_T c9_f_y[30];
  int32_T c9_i180;
  real_T c9_e_b[30];
  int32_T c9_i181;
  real_T c9_g_a[900];
  int32_T c9_i182;
  real_T c9_g_y;
  int32_T c9_i_k;
  int32_T c9_j_k;
  int32_T c9_i183;
  int32_T c9_i184;
  real_T c9_h_y;
  int32_T c9_k_k;
  int32_T c9_l_k;
  int32_T *c9_sfEvent;
  c9_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 22U, 22U, c9_b_debug_family_names,
    c9_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c9_MONITOR, 0U, c9_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c9_L_inv, 1U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_LL_PP_t, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_V_i, 3U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_W_i, 4U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_V_ip1, 5U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_W_ip1, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(NULL, 7U, c9_m_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargin, 8U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_nargout, 9U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_TT_PP, 10U, c9_i_sf_marshallOut,
    c9_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_LL_PP, 11U, c9_l_sf_marshallOut,
    c9_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_MM, 12U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_V_min, 13U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_V_max, 14U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_V_init, 15U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_i_min, 16U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_betas, 17U, c9_d_sf_marshallOut,
    c9_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c9_L, 18U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_J, 19U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_V, 20U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c9_actual_num_iters, 21U,
    c9_c_sf_marshallOut, c9_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 33);
  c9_MONITOR = 0.0;
  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 34);
  *c9_actual_num_iters = rtInf;
  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 35);
  CV_SCRIPT_COND(0, 0, TRUE);
  CV_SCRIPT_MCDC(0, 0, FALSE);
  CV_SCRIPT_IF(0, 0, FALSE);
  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 41);
  c9_L_inv = c9_mrdivide(chartInstance, 1.0, c9_L);
  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 42);
  for (c9_i147 = 0; c9_i147 < 30; c9_i147++) {
    c9_LL_PP_t[c9_i147] = c9_LL_PP[c9_i147];
  }

  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 44);
  for (c9_i148 = 0; c9_i148 < 900; c9_i148++) {
    c9_a[c9_i148] = c9_TT_PP[c9_i148];
  }

  for (c9_i149 = 0; c9_i149 < 30; c9_i149++) {
    c9_b[c9_i149] = c9_V_init[c9_i149];
  }

  c9_h_eml_scalar_eg(chartInstance);
  c9_h_eml_scalar_eg(chartInstance);
  for (c9_i150 = 0; c9_i150 < 30; c9_i150++) {
    c9_y[c9_i150] = 0.0;
  }

  for (c9_i151 = 0; c9_i151 < 900; c9_i151++) {
    c9_b_a[c9_i151] = c9_a[c9_i151];
  }

  for (c9_i152 = 0; c9_i152 < 30; c9_i152++) {
    c9_b_b[c9_i152] = c9_b[c9_i152];
  }

  c9_f_eml_xgemm(chartInstance, c9_b_a, c9_b_b, c9_y);
  c9_c_a = c9_L_inv;
  for (c9_i153 = 0; c9_i153 < 30; c9_i153++) {
    c9_y[c9_i153] += c9_LL_PP_t[c9_i153];
  }

  for (c9_i154 = 0; c9_i154 < 30; c9_i154++) {
    c9_y[c9_i154] *= c9_c_a;
  }

  for (c9_i155 = 0; c9_i155 < 30; c9_i155++) {
    c9_b[c9_i155] = c9_V_max[c9_i155];
  }

  for (c9_i156 = 0; c9_i156 < 30; c9_i156++) {
    c9_y[c9_i156] = c9_V_init[c9_i156] - c9_y[c9_i156];
  }

  c9_i_eml_scalar_eg(chartInstance);
  for (c9_k = 1; c9_k < 31; c9_k++) {
    c9_b_k = c9_k;
    c9_xk = c9_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c9_b_k), 1, 30, 1, 0) - 1];
    c9_yk = c9_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c9_b_k), 1, 30, 1, 0) - 1];
    c9_x = c9_xk;
    c9_b_y = c9_yk;
    c9_j_eml_scalar_eg(chartInstance);
    c9_extremum = muDoubleScalarMin(c9_x, c9_b_y);
    c9_minval[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c9_b_k), 1, 30, 1, 0) - 1] = c9_extremum;
  }

  for (c9_i157 = 0; c9_i157 < 30; c9_i157++) {
    c9_b[c9_i157] = c9_V_min[c9_i157];
  }

  c9_i_eml_scalar_eg(chartInstance);
  for (c9_c_k = 1; c9_c_k < 31; c9_c_k++) {
    c9_d_k = c9_c_k;
    c9_b_xk = c9_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c9_d_k), 1, 30, 1, 0) - 1];
    c9_b_yk = c9_minval[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c9_d_k), 1, 30, 1, 0) - 1];
    c9_b_x = c9_b_xk;
    c9_c_y = c9_b_yk;
    c9_j_eml_scalar_eg(chartInstance);
    c9_b_extremum = muDoubleScalarMax(c9_b_x, c9_c_y);
    c9_V_i[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c9_d_k), 1, 30, 1, 0) - 1] = c9_b_extremum;
  }

  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 45);
  for (c9_i158 = 0; c9_i158 < 30; c9_i158++) {
    c9_W_i[c9_i158] = c9_V_i[c9_i158];
  }

  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 47);
  CV_SCRIPT_IF(0, 1, c9_MONITOR != 0.0);
  c9_i159 = (int32_T)c9_i_min;
  sf_debug_for_loop_vector_check(1.0, 1.0, c9_i_min, mxDOUBLE_CLASS, c9_i159);
  c9_loop_ub = c9_i159;
  c9_i = 0;
  while (c9_i <= c9_loop_ub - 1) {
    c9_b_i = 1.0 + (real_T)c9_i;
    CV_SCRIPT_FOR(0, 0, 1);
    _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 59);
    for (c9_i160 = 0; c9_i160 < 900; c9_i160++) {
      c9_a[c9_i160] = c9_TT_PP[c9_i160];
    }

    for (c9_i161 = 0; c9_i161 < 30; c9_i161++) {
      c9_b[c9_i161] = c9_W_i[c9_i161];
    }

    c9_h_eml_scalar_eg(chartInstance);
    c9_h_eml_scalar_eg(chartInstance);
    for (c9_i162 = 0; c9_i162 < 30; c9_i162++) {
      c9_y[c9_i162] = 0.0;
    }

    for (c9_i163 = 0; c9_i163 < 900; c9_i163++) {
      c9_d_a[c9_i163] = c9_a[c9_i163];
    }

    for (c9_i164 = 0; c9_i164 < 30; c9_i164++) {
      c9_c_b[c9_i164] = c9_b[c9_i164];
    }

    c9_f_eml_xgemm(chartInstance, c9_d_a, c9_c_b, c9_y);
    c9_e_a = c9_L_inv;
    for (c9_i165 = 0; c9_i165 < 30; c9_i165++) {
      c9_y[c9_i165] += c9_LL_PP_t[c9_i165];
    }

    for (c9_i166 = 0; c9_i166 < 30; c9_i166++) {
      c9_y[c9_i166] *= c9_e_a;
    }

    for (c9_i167 = 0; c9_i167 < 30; c9_i167++) {
      c9_b[c9_i167] = c9_V_max[c9_i167];
    }

    for (c9_i168 = 0; c9_i168 < 30; c9_i168++) {
      c9_y[c9_i168] = c9_W_i[c9_i168] - c9_y[c9_i168];
    }

    c9_i_eml_scalar_eg(chartInstance);
    for (c9_e_k = 1; c9_e_k < 31; c9_e_k++) {
      c9_f_k = c9_e_k;
      c9_c_xk = c9_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c9_f_k), 1, 30, 1, 0) - 1];
      c9_c_yk = c9_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c9_f_k), 1, 30, 1, 0) - 1];
      c9_c_x = c9_c_xk;
      c9_d_y = c9_c_yk;
      c9_j_eml_scalar_eg(chartInstance);
      c9_c_extremum = muDoubleScalarMin(c9_c_x, c9_d_y);
      c9_minval[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c9_f_k), 1, 30, 1, 0) - 1] = c9_c_extremum;
    }

    for (c9_i169 = 0; c9_i169 < 30; c9_i169++) {
      c9_b[c9_i169] = c9_V_min[c9_i169];
    }

    c9_i_eml_scalar_eg(chartInstance);
    for (c9_g_k = 1; c9_g_k < 31; c9_g_k++) {
      c9_h_k = c9_g_k;
      c9_d_xk = c9_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c9_h_k), 1, 30, 1, 0) - 1];
      c9_d_yk = c9_minval[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c9_h_k), 1, 30, 1, 0) - 1];
      c9_d_x = c9_d_xk;
      c9_e_y = c9_d_yk;
      c9_j_eml_scalar_eg(chartInstance);
      c9_d_extremum = muDoubleScalarMax(c9_d_x, c9_e_y);
      c9_V_ip1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c9_h_k), 1, 30, 1, 0) - 1] = c9_d_extremum;
    }

    _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 62);
    c9_f_a = c9_betas[_SFD_EML_ARRAY_BOUNDS_CHECK("betas", (int32_T)
      _SFD_INTEGER_CHECK("i", c9_b_i), 1, 5, 1, 0) - 1];
    for (c9_i170 = 0; c9_i170 < 30; c9_i170++) {
      c9_b[c9_i170] = c9_V_ip1[c9_i170] - c9_V_i[c9_i170];
    }

    for (c9_i171 = 0; c9_i171 < 30; c9_i171++) {
      c9_b[c9_i171] *= c9_f_a;
    }

    for (c9_i172 = 0; c9_i172 < 30; c9_i172++) {
      c9_W_ip1[c9_i172] = c9_V_ip1[c9_i172] + c9_b[c9_i172];
    }

    _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 64);
    for (c9_i173 = 0; c9_i173 < 30; c9_i173++) {
      c9_V_i[c9_i173] = c9_V_ip1[c9_i173];
    }

    _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 65);
    for (c9_i174 = 0; c9_i174 < 30; c9_i174++) {
      c9_W_i[c9_i174] = c9_W_ip1[c9_i174];
    }

    _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 67);
    CV_SCRIPT_IF(0, 3, c9_MONITOR != 0.0);
    c9_i++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_SCRIPT_FOR(0, 0, 0);
  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 80);
  for (c9_i175 = 0; c9_i175 < 30; c9_i175++) {
    c9_V[c9_i175] = c9_V_i[c9_i175];
  }

  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 81);
  for (c9_i176 = 0; c9_i176 < 30; c9_i176++) {
    c9_d_b[c9_i176] = c9_V_i[c9_i176];
  }

  for (c9_i177 = 0; c9_i177 < 30; c9_i177++) {
    c9_d_b[c9_i177] *= 0.5;
  }

  for (c9_i178 = 0; c9_i178 < 900; c9_i178++) {
    c9_a[c9_i178] = c9_TT_PP[c9_i178];
  }

  c9_e_eml_scalar_eg(chartInstance);
  c9_e_eml_scalar_eg(chartInstance);
  for (c9_i179 = 0; c9_i179 < 30; c9_i179++) {
    c9_f_y[c9_i179] = 0.0;
  }

  for (c9_i180 = 0; c9_i180 < 30; c9_i180++) {
    c9_e_b[c9_i180] = c9_d_b[c9_i180];
  }

  for (c9_i181 = 0; c9_i181 < 900; c9_i181++) {
    c9_g_a[c9_i181] = c9_a[c9_i181];
  }

  c9_e_eml_xgemm(chartInstance, c9_e_b, c9_g_a, c9_f_y);
  for (c9_i182 = 0; c9_i182 < 30; c9_i182++) {
    c9_b[c9_i182] = c9_V_i[c9_i182];
  }

  c9_k_eml_scalar_eg(chartInstance);
  c9_k_eml_scalar_eg(chartInstance);
  c9_g_y = 0.0;
  for (c9_i_k = 1; c9_i_k < 31; c9_i_k++) {
    c9_j_k = c9_i_k;
    c9_g_y += c9_f_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c9_j_k), 1, 30, 1, 0) - 1] * c9_b[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c9_j_k), 1, 30, 1, 0) - 1];
  }

  for (c9_i183 = 0; c9_i183 < 30; c9_i183++) {
    c9_d_b[c9_i183] = c9_LL_PP[c9_i183];
  }

  for (c9_i184 = 0; c9_i184 < 30; c9_i184++) {
    c9_b[c9_i184] = c9_V_i[c9_i184];
  }

  c9_k_eml_scalar_eg(chartInstance);
  c9_k_eml_scalar_eg(chartInstance);
  c9_h_y = 0.0;
  for (c9_k_k = 1; c9_k_k < 31; c9_k_k++) {
    c9_l_k = c9_k_k;
    c9_h_y += c9_d_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c9_l_k), 1, 30, 1, 0) - 1] * c9_b[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c9_l_k), 1, 30, 1, 0) - 1];
  }

  *c9_J = (c9_g_y + c9_h_y) + c9_MM;
  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 82);
  CV_SCRIPT_IF(0, 5, CV_SCRIPT_MCDC(0, 1, !(CV_SCRIPT_COND(0, 1, c9_MONITOR !=
    0.0) != 0.0)));
  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, 83);
  *c9_actual_num_iters = c9_i_min;
  _SFD_SCRIPT_CALL(0U, *c9_sfEvent, -83);
  sf_debug_symbol_scope_pop();
}

static real_T c9_mrdivide(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_A, real_T c9_B)
{
  real_T c9_x;
  real_T c9_b_y;
  real_T c9_b_x;
  real_T c9_c_y;
  c9_x = c9_A;
  c9_b_y = c9_B;
  c9_b_x = c9_x;
  c9_c_y = c9_b_y;
  return c9_b_x / c9_c_y;
}

static void c9_h_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c9_c_eml_xgemm(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_A[900], real_T c9_B[30], real_T c9_C[30], real_T
  c9_b_C[30])
{
  int32_T c9_i185;
  int32_T c9_i186;
  real_T c9_b_A[900];
  int32_T c9_i187;
  real_T c9_b_B[30];
  for (c9_i185 = 0; c9_i185 < 30; c9_i185++) {
    c9_b_C[c9_i185] = c9_C[c9_i185];
  }

  for (c9_i186 = 0; c9_i186 < 900; c9_i186++) {
    c9_b_A[c9_i186] = c9_A[c9_i186];
  }

  for (c9_i187 = 0; c9_i187 < 30; c9_i187++) {
    c9_b_B[c9_i187] = c9_B[c9_i187];
  }

  c9_f_eml_xgemm(chartInstance, c9_b_A, c9_b_B, c9_b_C);
}

static void c9_i_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c9_j_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c9_k_eml_scalar_eg(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static const mxArray *c9_n_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_k_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i188;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i188, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i188;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c9_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_sfEvent), &c9_thisId);
  sf_mex_destroy(&c9_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_l_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_is_active_c9_Hquad_control_LIB_MPC, const
  char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_m_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_is_active_c9_Hquad_control_LIB_MPC), &c9_thisId);
  sf_mex_destroy(&c9_is_active_c9_Hquad_control_LIB_MPC);
  return c9_y;
}

static uint8_T c9_m_emlrt_marshallIn(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_eml_xgemm(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_A[62], real_T c9_B[1860], real_T c9_C[30])
{
  int32_T c9_m;
  int32_T c9_n;
  int32_T c9_k;
  real_T c9_alpha1;
  int32_T c9_lda;
  int32_T c9_ldb;
  real_T c9_beta1;
  int32_T c9_ldc;
  char_T c9_TRANSA;
  char_T c9_TRANSB;
  c9_m = 1;
  c9_n = 30;
  c9_k = 62;
  c9_alpha1 = 1.0;
  c9_lda = 1;
  c9_ldb = 62;
  c9_beta1 = 0.0;
  c9_ldc = 1;
  c9_TRANSA = 'N';
  c9_TRANSB = 'N';
  dgemm32(&c9_TRANSA, &c9_TRANSB, &c9_m, &c9_n, &c9_k, &c9_alpha1, &c9_A[0],
          &c9_lda, &c9_B[0], &c9_ldb, &c9_beta1, &c9_C[0], &c9_ldc);
}

static void c9_e_eml_xgemm(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_A[30], real_T c9_B[900], real_T c9_C[30])
{
  int32_T c9_m;
  int32_T c9_n;
  int32_T c9_k;
  real_T c9_alpha1;
  int32_T c9_lda;
  int32_T c9_ldb;
  real_T c9_beta1;
  int32_T c9_ldc;
  char_T c9_TRANSA;
  char_T c9_TRANSB;
  c9_m = 1;
  c9_n = 30;
  c9_k = 30;
  c9_alpha1 = 1.0;
  c9_lda = 1;
  c9_ldb = 30;
  c9_beta1 = 0.0;
  c9_ldc = 1;
  c9_TRANSA = 'N';
  c9_TRANSB = 'N';
  dgemm32(&c9_TRANSA, &c9_TRANSB, &c9_m, &c9_n, &c9_k, &c9_alpha1, &c9_A[0],
          &c9_lda, &c9_B[0], &c9_ldb, &c9_beta1, &c9_C[0], &c9_ldc);
}

static void c9_f_eml_xgemm(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c9_A[900], real_T c9_B[30], real_T c9_C[30])
{
  int32_T c9_m;
  int32_T c9_n;
  int32_T c9_k;
  real_T c9_alpha1;
  int32_T c9_lda;
  int32_T c9_ldb;
  real_T c9_beta1;
  int32_T c9_ldc;
  char_T c9_TRANSA;
  char_T c9_TRANSB;
  c9_m = 30;
  c9_n = 1;
  c9_k = 30;
  c9_alpha1 = 1.0;
  c9_lda = 30;
  c9_ldb = 30;
  c9_beta1 = 0.0;
  c9_ldc = 30;
  c9_TRANSA = 'N';
  c9_TRANSB = 'N';
  dgemm32(&c9_TRANSA, &c9_TRANSB, &c9_m, &c9_n, &c9_k, &c9_alpha1, &c9_A[0],
          &c9_lda, &c9_B[0], &c9_ldb, &c9_beta1, &c9_C[0], &c9_ldc);
}

static void init_dsm_address_info(SFc9_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c9_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2741087590U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3118490928U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3822130065U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3519398997U);
}

mxArray *sf_c9_Hquad_control_LIB_MPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("uG3Qs1yMoLSpjHbxmo34OE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,16,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(30);
      pr[1] = (double)(30);
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
      pr[0] = (double)(2);
      pr[1] = (double)(30);
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
      pr[0] = (double)(62);
      pr[1] = (double)(30);
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
      pr[0] = (double)(30);
      pr[1] = (double)(30);
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
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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
      pr[0] = (double)(30);
      pr[1] = (double)(30);
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
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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
      pr[0] = (double)(2);
      pr[1] = (double)(6);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(62);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(30);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,13,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,13,"type",mxType);
    }

    mxSetField(mxData,13,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,14,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,14,"type",mxType);
    }

    mxSetField(mxData,14,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(30);
      pr[1] = (double)(1);
      mxSetField(mxData,15,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,15,"type",mxType);
    }

    mxSetField(mxData,15,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(30);
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

static const mxArray *sf_get_sim_state_info_c9_Hquad_control_LIB_MPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[16],T\"J_star\",},{M[1],M[21],T\"V_init_out\",},{M[1],M[20],T\"u_buff_out\",},{M[1],M[5],T\"u_opt\",},{M[8],M[0],T\"is_active_c9_Hquad_control_LIB_MPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_Hquad_control_LIB_MPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
    chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Hquad_control_LIB_MPCMachineNumber_,
           9,
           1,
           1,
           20,
           0,
           0,
           0,
           0,
           1,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"TT_PP");
          _SFD_SET_DATA_PROPS(1,2,0,1,"u_opt");
          _SFD_SET_DATA_PROPS(2,1,1,0,"LL_PP");
          _SFD_SET_DATA_PROPS(3,1,1,0,"LL_ref_PP");
          _SFD_SET_DATA_PROPS(4,1,1,0,"LL_U_ref_PP");
          _SFD_SET_DATA_PROPS(5,2,0,1,"J_star");
          _SFD_SET_DATA_PROPS(6,2,0,1,"u_buff_out");
          _SFD_SET_DATA_PROPS(7,2,0,1,"V_init_out");
          _SFD_SET_DATA_PROPS(8,1,1,0,"MM");
          _SFD_SET_DATA_PROPS(9,1,1,0,"PP");
          _SFD_SET_DATA_PROPS(10,1,1,0,"AA_delay");
          _SFD_SET_DATA_PROPS(11,1,1,0,"BB_delay");
          _SFD_SET_DATA_PROPS(12,1,1,0,"x");
          _SFD_SET_DATA_PROPS(13,1,1,0,"X_ref");
          _SFD_SET_DATA_PROPS(14,1,1,0,"V_max");
          _SFD_SET_DATA_PROPS(15,1,1,0,"i_min");
          _SFD_SET_DATA_PROPS(16,1,1,0,"betas");
          _SFD_SET_DATA_PROPS(17,1,1,0,"L");
          _SFD_SET_DATA_PROPS(18,1,1,0,"u_buff");
          _SFD_SET_DATA_PROPS(19,1,1,0,"V_init");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1440);
        _SFD_CV_INIT_EML_IF(0,1,0,478,496,524,584);
        _SFD_CV_INIT_EML_IF(0,1,1,1230,1248,1275,1348);
        _SFD_CV_INIT_SCRIPT(0,1,6,0,0,1,0,2,2);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"runFastGradient",0,-1,2478);
        _SFD_CV_INIT_SCRIPT_IF(0,0,1281,1297,-1,1318);
        _SFD_CV_INIT_SCRIPT_IF(0,1,1487,1497,-1,1725);
        _SFD_CV_INIT_SCRIPT_IF(0,2,1560,1594,-1,1721);
        _SFD_CV_INIT_SCRIPT_IF(0,3,2052,2062,-1,2285);
        _SFD_CV_INIT_SCRIPT_IF(0,4,2133,2167,-1,2277);
        _SFD_CV_INIT_SCRIPT_IF(0,5,2368,2379,-1,2413);
        _SFD_CV_INIT_SCRIPT_FOR(0,0,1763,1777,2289);

        {
          static int condStart[] = { 1285 };

          static int condEnd[] = { 1297 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,0,1284,1297,1,0,&(condStart[0]),&(condEnd[0]),
            2,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2372 };

          static int condEnd[] = { 2379 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,1,2371,2379,1,1,&(condStart[0]),&(condEnd[0]),
            2,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 30;
          dimVector[1]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_k_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 62;
          dimVector[1]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_j_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 30;
          dimVector[1]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)c9_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_h_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 30;
          dimVector[1]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_h_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 62;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 5;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c9_u_opt;
          real_T *c9_J_star;
          real_T *c9_i_min;
          real_T *c9_L;
          real_T (*c9_TT_PP)[900];
          real_T (*c9_LL_PP)[60];
          real_T (*c9_LL_ref_PP)[1860];
          real_T (*c9_LL_U_ref_PP)[900];
          real_T (*c9_u_buff_out)[6];
          real_T (*c9_V_init_out)[30];
          real_T (*c9_MM)[4];
          real_T (*c9_PP)[900];
          real_T (*c9_AA_delay)[4];
          real_T (*c9_BB_delay)[12];
          real_T (*c9_x)[2];
          real_T (*c9_X_ref)[62];
          real_T (*c9_V_max)[30];
          real_T (*c9_betas)[5];
          real_T (*c9_u_buff)[6];
          real_T (*c9_V_init)[30];
          c9_V_init = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 15);
          c9_u_buff = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 14);
          c9_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c9_betas = (real_T (*)[5])ssGetInputPortSignal(chartInstance->S, 12);
          c9_i_min = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c9_V_max = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 10);
          c9_X_ref = (real_T (*)[62])ssGetInputPortSignal(chartInstance->S, 9);
          c9_x = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 8);
          c9_BB_delay = (real_T (*)[12])ssGetInputPortSignal(chartInstance->S, 7);
          c9_AA_delay = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 6);
          c9_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 5);
          c9_MM = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 4);
          c9_V_init_out = (real_T (*)[30])ssGetOutputPortSignal(chartInstance->S,
            4);
          c9_u_buff_out = (real_T (*)[6])ssGetOutputPortSignal(chartInstance->S,
            3);
          c9_J_star = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c9_LL_U_ref_PP = (real_T (*)[900])ssGetInputPortSignal
            (chartInstance->S, 3);
          c9_LL_ref_PP = (real_T (*)[1860])ssGetInputPortSignal(chartInstance->S,
            2);
          c9_LL_PP = (real_T (*)[60])ssGetInputPortSignal(chartInstance->S, 1);
          c9_u_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c9_TT_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c9_TT_PP);
          _SFD_SET_DATA_VALUE_PTR(1U, c9_u_opt);
          _SFD_SET_DATA_VALUE_PTR(2U, *c9_LL_PP);
          _SFD_SET_DATA_VALUE_PTR(3U, *c9_LL_ref_PP);
          _SFD_SET_DATA_VALUE_PTR(4U, *c9_LL_U_ref_PP);
          _SFD_SET_DATA_VALUE_PTR(5U, c9_J_star);
          _SFD_SET_DATA_VALUE_PTR(6U, *c9_u_buff_out);
          _SFD_SET_DATA_VALUE_PTR(7U, *c9_V_init_out);
          _SFD_SET_DATA_VALUE_PTR(8U, *c9_MM);
          _SFD_SET_DATA_VALUE_PTR(9U, *c9_PP);
          _SFD_SET_DATA_VALUE_PTR(10U, *c9_AA_delay);
          _SFD_SET_DATA_VALUE_PTR(11U, *c9_BB_delay);
          _SFD_SET_DATA_VALUE_PTR(12U, *c9_x);
          _SFD_SET_DATA_VALUE_PTR(13U, *c9_X_ref);
          _SFD_SET_DATA_VALUE_PTR(14U, *c9_V_max);
          _SFD_SET_DATA_VALUE_PTR(15U, c9_i_min);
          _SFD_SET_DATA_VALUE_PTR(16U, *c9_betas);
          _SFD_SET_DATA_VALUE_PTR(17U, c9_L);
          _SFD_SET_DATA_VALUE_PTR(18U, *c9_u_buff);
          _SFD_SET_DATA_VALUE_PTR(19U, *c9_V_init);
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

static void sf_opaque_initialize_c9_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc9_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc9_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_Hquad_control_LIB_MPC
    ((SFc9_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
  initialize_c9_Hquad_control_LIB_MPC((SFc9_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  enable_c9_Hquad_control_LIB_MPC((SFc9_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  disable_c9_Hquad_control_LIB_MPC((SFc9_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_c9_Hquad_control_LIB_MPC((SFc9_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c9_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  ext_mode_exec_c9_Hquad_control_LIB_MPC
    ((SFc9_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_Hquad_control_LIB_MPC
    ((SFc9_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_Hquad_control_LIB_MPC();/* state var info */
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

extern void sf_internal_set_sim_state_c9_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_Hquad_control_LIB_MPC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_Hquad_control_LIB_MPC
    ((SFc9_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_Hquad_control_LIB_MPC(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c9_Hquad_control_LIB_MPC(S);
}

static void sf_opaque_set_sim_state_c9_Hquad_control_LIB_MPC(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c9_Hquad_control_LIB_MPC(S, st);
}

static void sf_opaque_terminate_c9_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c9_Hquad_control_LIB_MPC((SFc9_Hquad_control_LIB_MPCInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Hquad_control_LIB_MPC_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_Hquad_control_LIB_MPC
    ((SFc9_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_Hquad_control_LIB_MPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_Hquad_control_LIB_MPC
      ((SFc9_Hquad_control_LIB_MPCInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c9_Hquad_control_LIB_MPC_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c9_Hquad_control_LIB_MPC\",T\"is_active_c9_Hquad_control_LIB_MPC\"}}"
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

static void mdlSetWorkWidths_c9_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
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
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 10, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 11, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 12, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 13, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 14, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 15, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,9,16);
      sf_mark_chart_reusable_outputs(S,infoStruct,9,4);
    }

    sf_set_rtw_dwork_info(S,infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3282574311U));
  ssSetChecksum1(S,(1569173005U));
  ssSetChecksum2(S,(3454080243U));
  ssSetChecksum3(S,(427566313U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c9_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_Hquad_control_LIB_MPC(SimStruct *S)
{
  SFc9_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc9_Hquad_control_LIB_MPCInstanceStruct *)malloc(sizeof
    (SFc9_Hquad_control_LIB_MPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_Hquad_control_LIB_MPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c9_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c9_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c9_Hquad_control_LIB_MPC;
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

void c9_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_Hquad_control_LIB_MPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_Hquad_control_LIB_MPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
