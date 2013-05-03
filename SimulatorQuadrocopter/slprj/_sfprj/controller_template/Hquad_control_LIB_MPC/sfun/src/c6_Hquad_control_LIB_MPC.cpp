/* Include files */

#include "blascompat32.h"
#include "Hquad_control_LIB_MPC_sfun.h"
#include "c6_Hquad_control_LIB_MPC.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hquad_control_LIB_MPC_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[32] = { "m", "delay_steps", "N",
  "x_predicted", "U_ref", "LL_PP_ref", "MM_ref", "V_star", "unusedU0", "U_star",
  "nargin", "nargout", "TT_PP", "LL_PP", "LL_ref_PP", "LL_U_ref_PP", "MM", "PP",
  "AA_delay", "BB_delay", "x", "X_ref", "V_max", "i_min", "betas", "L", "u_buff",
  "V_init", "u_opt", "J_star", "u_buff_out", "V_init_out" };

static const char * c6_b_debug_family_names[22] = { "MONITOR", "L_inv",
  "LL_PP_t", "V_i", "W_i", "V_ip1", "W_ip1", "sol", "nargin", "nargout", "TT_PP",
  "LL_PP", "MM", "V_min", "V_max", "V_init", "i_min", "betas", "L", "J", "V",
  "actual_num_iters" };

/* Function Declarations */
static void initialize_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initialize_params_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void enable_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void disable_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void ext_mode_exec_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void set_sim_state_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray *c6_st);
static void finalize_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void sf_c6_Hquad_control_LIB_MPC(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c6_chartstep_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initSimStructsc6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_V_init_out, const char_T *c6_identifier,
  real_T c6_y[30]);
static void c6_b_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[30]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_c_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u_buff_out, const char_T *c6_identifier,
  real_T c6_y[3]);
static void c6_d_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[3]);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_e_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_J_star, const char_T *c6_identifier);
static real_T c6_f_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_g_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_h_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_i_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_j_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_g_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[30]);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_h_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[7]);
static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static void c6_i_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[900]);
static void c6_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_k_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[24]);
static void c6_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c6_b_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c6_c_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c6_eml_xgemm(SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c6_A[93], real_T c6_B[2790], real_T c6_C[30], real_T c6_b_C[30]);
static void c6_d_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c6_b_eml_xgemm(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_A[30], real_T c6_B[900], real_T c6_C[30], real_T
  c6_b_C[30]);
static void c6_e_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c6_f_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c6_runFastGradient(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_TT_PP[900], real_T c6_LL_PP[30], real_T c6_MM,
  real_T c6_V_min[30], real_T c6_V_max[30], real_T c6_V_init[30], real_T
  c6_i_min, real_T c6_betas[7], real_T c6_L, real_T *c6_J, real_T c6_V[30],
  real_T *c6_actual_num_iters);
static real_T c6_mrdivide(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_A, real_T c6_B);
static void c6_g_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c6_c_eml_xgemm(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_A[900], real_T c6_B[30], real_T c6_C[30], real_T
  c6_b_C[30]);
static void c6_h_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c6_i_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static void c6_j_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);
static const mxArray *c6_l_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_j_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_k_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_is_active_c6_Hquad_control_LIB_MPC, const
  char_T *c6_identifier);
static uint8_T c6_l_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_eml_xgemm(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_A[93], real_T c6_B[2790], real_T c6_C[30]);
static void c6_e_eml_xgemm(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_A[30], real_T c6_B[900], real_T c6_C[30]);
static void c6_f_eml_xgemm(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_A[900], real_T c6_B[30], real_T c6_C[30]);
static void init_dsm_address_info(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T *c6_sfEvent;
  uint8_T *c6_is_active_c6_Hquad_control_LIB_MPC;
  c6_is_active_c6_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c6_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c6_is_active_c6_Hquad_control_LIB_MPC = 0U;
}

static void initialize_params_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void enable_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  c6_update_debugger_state_c6_Hquad_control_LIB_MPC(chartInstance);
}

static const mxArray *get_sim_state_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_u;
  const mxArray *c6_b_y = NULL;
  int32_T c6_i0;
  real_T c6_b_u[30];
  const mxArray *c6_c_y = NULL;
  int32_T c6_i1;
  real_T c6_c_u[3];
  const mxArray *c6_d_y = NULL;
  real_T c6_b_hoistedGlobal;
  real_T c6_d_u;
  const mxArray *c6_e_y = NULL;
  uint8_T c6_c_hoistedGlobal;
  uint8_T c6_e_u;
  const mxArray *c6_f_y = NULL;
  real_T *c6_J_star;
  real_T *c6_u_opt;
  uint8_T *c6_is_active_c6_Hquad_control_LIB_MPC;
  real_T (*c6_u_buff_out)[3];
  real_T (*c6_V_init_out)[30];
  c6_V_init_out = (real_T (*)[30])ssGetOutputPortSignal(chartInstance->S, 4);
  c6_u_buff_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c6_J_star = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_u_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_is_active_c6_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(5), FALSE);
  c6_hoistedGlobal = *c6_J_star;
  c6_u = c6_hoistedGlobal;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  for (c6_i0 = 0; c6_i0 < 30; c6_i0++) {
    c6_b_u[c6_i0] = (*c6_V_init_out)[c6_i0];
  }

  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_b_u, 0, 0U, 1U, 0U, 1, 30), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  for (c6_i1 = 0; c6_i1 < 3; c6_i1++) {
    c6_c_u[c6_i1] = (*c6_u_buff_out)[c6_i1];
  }

  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_c_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_b_hoistedGlobal = *c6_u_opt;
  c6_d_u = c6_b_hoistedGlobal;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  c6_c_hoistedGlobal = *c6_is_active_c6_Hquad_control_LIB_MPC;
  c6_e_u = c6_c_hoistedGlobal;
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 4, c6_f_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv0[30];
  int32_T c6_i2;
  real_T c6_dv1[3];
  int32_T c6_i3;
  boolean_T *c6_doneDoubleBufferReInit;
  real_T *c6_J_star;
  real_T *c6_u_opt;
  uint8_T *c6_is_active_c6_Hquad_control_LIB_MPC;
  real_T (*c6_V_init_out)[30];
  real_T (*c6_u_buff_out)[3];
  c6_V_init_out = (real_T (*)[30])ssGetOutputPortSignal(chartInstance->S, 4);
  c6_u_buff_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c6_J_star = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_u_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_is_active_c6_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c6_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  *c6_J_star = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 0)), "J_star");
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
                      "V_init_out", c6_dv0);
  for (c6_i2 = 0; c6_i2 < 30; c6_i2++) {
    (*c6_V_init_out)[c6_i2] = c6_dv0[c6_i2];
  }

  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 2)),
                        "u_buff_out", c6_dv1);
  for (c6_i3 = 0; c6_i3 < 3; c6_i3++) {
    (*c6_u_buff_out)[c6_i3] = c6_dv1[c6_i3];
  }

  *c6_u_opt = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 3)), "u_opt");
  *c6_is_active_c6_Hquad_control_LIB_MPC = c6_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 4)), "is_active_c6_Hquad_control_LIB_MPC");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_Hquad_control_LIB_MPC(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void sf_c6_Hquad_control_LIB_MPC(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T *c6_sfEvent;
  real_T *c6_u_opt;
  real_T *c6_J_star;
  real_T *c6_i_min;
  real_T *c6_L;
  real_T (*c6_V_init)[30];
  real_T (*c6_u_buff)[3];
  real_T (*c6_betas)[7];
  real_T (*c6_V_max)[30];
  real_T (*c6_X_ref)[93];
  real_T (*c6_x)[3];
  real_T (*c6_BB_delay)[9];
  real_T (*c6_AA_delay)[9];
  real_T (*c6_PP)[900];
  real_T (*c6_MM)[9];
  real_T (*c6_V_init_out)[30];
  real_T (*c6_u_buff_out)[3];
  real_T (*c6_LL_U_ref_PP)[900];
  real_T (*c6_LL_ref_PP)[2790];
  real_T (*c6_LL_PP)[90];
  real_T (*c6_TT_PP)[900];
  c6_V_init = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 15);
  c6_u_buff = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 14);
  c6_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c6_betas = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 12);
  c6_i_min = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c6_V_max = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 10);
  c6_X_ref = (real_T (*)[93])ssGetInputPortSignal(chartInstance->S, 9);
  c6_x = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 8);
  c6_BB_delay = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 7);
  c6_AA_delay = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 6);
  c6_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 5);
  c6_MM = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c6_V_init_out = (real_T (*)[30])ssGetOutputPortSignal(chartInstance->S, 4);
  c6_u_buff_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c6_J_star = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_LL_U_ref_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 3);
  c6_LL_ref_PP = (real_T (*)[2790])ssGetInputPortSignal(chartInstance->S, 2);
  c6_LL_PP = (real_T (*)[90])ssGetInputPortSignal(chartInstance->S, 1);
  c6_u_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_TT_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 0);
  c6_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, *c6_sfEvent);
  for (c6_i4 = 0; c6_i4 < 900; c6_i4++) {
    _SFD_DATA_RANGE_CHECK((*c6_TT_PP)[c6_i4], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c6_u_opt, 1U);
  for (c6_i5 = 0; c6_i5 < 90; c6_i5++) {
    _SFD_DATA_RANGE_CHECK((*c6_LL_PP)[c6_i5], 2U);
  }

  for (c6_i6 = 0; c6_i6 < 2790; c6_i6++) {
    _SFD_DATA_RANGE_CHECK((*c6_LL_ref_PP)[c6_i6], 3U);
  }

  for (c6_i7 = 0; c6_i7 < 900; c6_i7++) {
    _SFD_DATA_RANGE_CHECK((*c6_LL_U_ref_PP)[c6_i7], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*c6_J_star, 5U);
  for (c6_i8 = 0; c6_i8 < 3; c6_i8++) {
    _SFD_DATA_RANGE_CHECK((*c6_u_buff_out)[c6_i8], 6U);
  }

  for (c6_i9 = 0; c6_i9 < 30; c6_i9++) {
    _SFD_DATA_RANGE_CHECK((*c6_V_init_out)[c6_i9], 7U);
  }

  for (c6_i10 = 0; c6_i10 < 9; c6_i10++) {
    _SFD_DATA_RANGE_CHECK((*c6_MM)[c6_i10], 8U);
  }

  for (c6_i11 = 0; c6_i11 < 900; c6_i11++) {
    _SFD_DATA_RANGE_CHECK((*c6_PP)[c6_i11], 9U);
  }

  for (c6_i12 = 0; c6_i12 < 9; c6_i12++) {
    _SFD_DATA_RANGE_CHECK((*c6_AA_delay)[c6_i12], 10U);
  }

  for (c6_i13 = 0; c6_i13 < 9; c6_i13++) {
    _SFD_DATA_RANGE_CHECK((*c6_BB_delay)[c6_i13], 11U);
  }

  for (c6_i14 = 0; c6_i14 < 3; c6_i14++) {
    _SFD_DATA_RANGE_CHECK((*c6_x)[c6_i14], 12U);
  }

  for (c6_i15 = 0; c6_i15 < 93; c6_i15++) {
    _SFD_DATA_RANGE_CHECK((*c6_X_ref)[c6_i15], 13U);
  }

  for (c6_i16 = 0; c6_i16 < 30; c6_i16++) {
    _SFD_DATA_RANGE_CHECK((*c6_V_max)[c6_i16], 14U);
  }

  _SFD_DATA_RANGE_CHECK(*c6_i_min, 15U);
  for (c6_i17 = 0; c6_i17 < 7; c6_i17++) {
    _SFD_DATA_RANGE_CHECK((*c6_betas)[c6_i17], 16U);
  }

  _SFD_DATA_RANGE_CHECK(*c6_L, 17U);
  for (c6_i18 = 0; c6_i18 < 3; c6_i18++) {
    _SFD_DATA_RANGE_CHECK((*c6_u_buff)[c6_i18], 18U);
  }

  for (c6_i19 = 0; c6_i19 < 30; c6_i19++) {
    _SFD_DATA_RANGE_CHECK((*c6_V_init)[c6_i19], 19U);
  }

  *c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_Hquad_control_LIB_MPC(chartInstance);
  sf_debug_check_for_state_inconsistency(_Hquad_control_LIB_MPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_chartstep_c6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  int32_T c6_i20;
  real_T c6_TT_PP[900];
  int32_T c6_i21;
  real_T c6_LL_PP[90];
  int32_T c6_i22;
  real_T c6_LL_ref_PP[2790];
  int32_T c6_i23;
  real_T c6_LL_U_ref_PP[900];
  int32_T c6_i24;
  real_T c6_MM[9];
  int32_T c6_i25;
  real_T c6_PP[900];
  int32_T c6_i26;
  real_T c6_AA_delay[9];
  int32_T c6_i27;
  real_T c6_BB_delay[9];
  int32_T c6_i28;
  real_T c6_x[3];
  int32_T c6_i29;
  real_T c6_X_ref[93];
  int32_T c6_i30;
  real_T c6_V_max[30];
  real_T c6_i_min;
  int32_T c6_i31;
  real_T c6_betas[7];
  real_T c6_L;
  int32_T c6_i32;
  real_T c6_u_buff[3];
  int32_T c6_i33;
  real_T c6_V_init[30];
  uint32_T c6_debug_family_var_map[32];
  real_T c6_m;
  real_T c6_delay_steps;
  real_T c6_N;
  real_T c6_x_predicted[3];
  real_T c6_U_ref[30];
  real_T c6_LL_PP_ref[30];
  real_T c6_MM_ref;
  real_T c6_V_star[30];
  real_T c6_unusedU0;
  real_T c6_b_unusedU0;
  real_T c6_U_star[30];
  real_T c6_nargin = 16.0;
  real_T c6_nargout = 4.0;
  real_T c6_u_opt;
  real_T c6_J_star;
  real_T c6_u_buff_out[3];
  real_T c6_V_init_out[30];
  int32_T c6_i34;
  real_T c6_a[9];
  int32_T c6_i35;
  real_T c6_b[3];
  int32_T c6_i36;
  real_T c6_y[3];
  int32_T c6_i37;
  int32_T c6_i38;
  int32_T c6_i39;
  int32_T c6_i40;
  int32_T c6_i41;
  real_T c6_b_y[3];
  int32_T c6_i42;
  int32_T c6_i43;
  int32_T c6_i44;
  int32_T c6_i45;
  int32_T c6_i46;
  real_T c6_b_a[3];
  int32_T c6_i47;
  real_T c6_b_b[90];
  int32_T c6_i48;
  int32_T c6_i49;
  real_T c6_c_y[30];
  int32_T c6_i50;
  int32_T c6_i51;
  real_T c6_c_a[93];
  int32_T c6_i52;
  real_T c6_c_b[2790];
  int32_T c6_i53;
  real_T c6_d_y[30];
  int32_T c6_i54;
  real_T c6_d_a[93];
  int32_T c6_i55;
  real_T c6_d_b[2790];
  int32_T c6_i56;
  real_T c6_e_b[900];
  int32_T c6_i57;
  real_T c6_e_y[30];
  int32_T c6_i58;
  real_T c6_dv2[30];
  int32_T c6_i59;
  real_T c6_f_b[900];
  int32_T c6_i60;
  int32_T c6_i61;
  int32_T c6_i62;
  int32_T c6_i63;
  int32_T c6_i64;
  real_T c6_f_y[3];
  int32_T c6_i65;
  int32_T c6_i66;
  int32_T c6_k;
  int32_T c6_b_k;
  int32_T c6_i67;
  real_T c6_b_TT_PP[900];
  int32_T c6_i68;
  real_T c6_b_LL_PP_ref[30];
  int32_T c6_i69;
  real_T c6_b_V_max[30];
  int32_T c6_i70;
  real_T c6_c_V_max[30];
  int32_T c6_i71;
  real_T c6_b_V_init[30];
  int32_T c6_i72;
  real_T c6_b_betas[7];
  real_T c6_c_unusedU0;
  real_T c6_b_V_star[30];
  real_T c6_b_J_star;
  int32_T c6_i73;
  int32_T c6_i74;
  int32_T c6_i75;
  int32_T c6_i76;
  int32_T c6_i77;
  int32_T c6_i78;
  real_T c6_g_b[900];
  int32_T c6_i79;
  real_T c6_c_V_star[30];
  int32_T c6_i80;
  int32_T c6_i81;
  int32_T c6_i82;
  int32_T c6_i83;
  real_T *c6_b_i_min;
  real_T *c6_b_L;
  real_T *c6_b_u_opt;
  real_T *c6_c_J_star;
  real_T (*c6_b_u_buff_out)[3];
  real_T (*c6_b_V_init_out)[30];
  real_T (*c6_c_V_init)[30];
  real_T (*c6_b_u_buff)[3];
  real_T (*c6_c_betas)[7];
  real_T (*c6_d_V_max)[30];
  real_T (*c6_b_X_ref)[93];
  real_T (*c6_b_x)[3];
  real_T (*c6_b_BB_delay)[9];
  real_T (*c6_b_AA_delay)[9];
  real_T (*c6_b_PP)[900];
  real_T (*c6_b_MM)[9];
  real_T (*c6_b_LL_U_ref_PP)[900];
  real_T (*c6_b_LL_ref_PP)[2790];
  real_T (*c6_b_LL_PP)[90];
  real_T (*c6_c_TT_PP)[900];
  int32_T *c6_sfEvent;
  c6_c_V_init = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 15);
  c6_b_u_buff = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 14);
  c6_b_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
  c6_c_betas = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 12);
  c6_b_i_min = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
  c6_d_V_max = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 10);
  c6_b_X_ref = (real_T (*)[93])ssGetInputPortSignal(chartInstance->S, 9);
  c6_b_x = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 8);
  c6_b_BB_delay = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 7);
  c6_b_AA_delay = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 6);
  c6_b_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 5);
  c6_b_MM = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c6_b_V_init_out = (real_T (*)[30])ssGetOutputPortSignal(chartInstance->S, 4);
  c6_b_u_buff_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 3);
  c6_c_J_star = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_b_LL_U_ref_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 3);
  c6_b_LL_ref_PP = (real_T (*)[2790])ssGetInputPortSignal(chartInstance->S, 2);
  c6_b_LL_PP = (real_T (*)[90])ssGetInputPortSignal(chartInstance->S, 1);
  c6_b_u_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_c_TT_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 0);
  c6_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, *c6_sfEvent);
  c6_hoistedGlobal = *c6_b_i_min;
  c6_b_hoistedGlobal = *c6_b_L;
  for (c6_i20 = 0; c6_i20 < 900; c6_i20++) {
    c6_TT_PP[c6_i20] = (*c6_c_TT_PP)[c6_i20];
  }

  for (c6_i21 = 0; c6_i21 < 90; c6_i21++) {
    c6_LL_PP[c6_i21] = (*c6_b_LL_PP)[c6_i21];
  }

  for (c6_i22 = 0; c6_i22 < 2790; c6_i22++) {
    c6_LL_ref_PP[c6_i22] = (*c6_b_LL_ref_PP)[c6_i22];
  }

  for (c6_i23 = 0; c6_i23 < 900; c6_i23++) {
    c6_LL_U_ref_PP[c6_i23] = (*c6_b_LL_U_ref_PP)[c6_i23];
  }

  for (c6_i24 = 0; c6_i24 < 9; c6_i24++) {
    c6_MM[c6_i24] = (*c6_b_MM)[c6_i24];
  }

  for (c6_i25 = 0; c6_i25 < 900; c6_i25++) {
    c6_PP[c6_i25] = (*c6_b_PP)[c6_i25];
  }

  for (c6_i26 = 0; c6_i26 < 9; c6_i26++) {
    c6_AA_delay[c6_i26] = (*c6_b_AA_delay)[c6_i26];
  }

  for (c6_i27 = 0; c6_i27 < 9; c6_i27++) {
    c6_BB_delay[c6_i27] = (*c6_b_BB_delay)[c6_i27];
  }

  for (c6_i28 = 0; c6_i28 < 3; c6_i28++) {
    c6_x[c6_i28] = (*c6_b_x)[c6_i28];
  }

  for (c6_i29 = 0; c6_i29 < 93; c6_i29++) {
    c6_X_ref[c6_i29] = (*c6_b_X_ref)[c6_i29];
  }

  for (c6_i30 = 0; c6_i30 < 30; c6_i30++) {
    c6_V_max[c6_i30] = (*c6_d_V_max)[c6_i30];
  }

  c6_i_min = c6_hoistedGlobal;
  for (c6_i31 = 0; c6_i31 < 7; c6_i31++) {
    c6_betas[c6_i31] = (*c6_c_betas)[c6_i31];
  }

  c6_L = c6_b_hoistedGlobal;
  for (c6_i32 = 0; c6_i32 < 3; c6_i32++) {
    c6_u_buff[c6_i32] = (*c6_b_u_buff)[c6_i32];
  }

  for (c6_i33 = 0; c6_i33 < 30; c6_i33++) {
    c6_V_init[c6_i33] = (*c6_c_V_init)[c6_i33];
  }

  sf_debug_symbol_scope_push_eml(0U, 32U, 33U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c6_m, 0U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_delay_steps, 1U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_N, 2U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_x_predicted, 3U,
    c6_b_sf_marshallOut, c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c6_U_ref, 4U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c6_LL_PP_ref, 5U, c6_j_sf_marshallOut,
    c6_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_MM_ref, 6U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_V_star, 7U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_unusedU0, MAX_uint32_T,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_b_unusedU0, MAX_uint32_T,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_U_star, 9U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 10U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 11U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c6_TT_PP, 12U, c6_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_LL_PP, 13U, c6_i_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_LL_ref_PP, 14U, c6_h_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_LL_U_ref_PP, 15U, c6_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_MM, 16U, c6_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_PP, 17U, c6_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_AA_delay, 18U, c6_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_BB_delay, 19U, c6_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_x, 20U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_X_ref, 21U, c6_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_V_max, 22U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_i_min, 23U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_betas, 24U, c6_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_L, 25U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_u_buff, 26U, c6_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c6_V_init, 27U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_u_opt, 28U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_J_star, 29U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_u_buff_out, 30U,
    c6_b_sf_marshallOut, c6_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_V_init_out, 31U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c6_sfEvent, 6);
  c6_m = 1.0;
  _SFD_EML_CALL(0U, *c6_sfEvent, 7);
  c6_delay_steps = 3.0;
  _SFD_EML_CALL(0U, *c6_sfEvent, 8);
  c6_N = 30.0;
  _SFD_EML_CALL(0U, *c6_sfEvent, 11);
  CV_EML_IF(0, 1, 0, c6_delay_steps == 0.0);
  _SFD_EML_CALL(0U, *c6_sfEvent, 14);
  for (c6_i34 = 0; c6_i34 < 9; c6_i34++) {
    c6_a[c6_i34] = c6_AA_delay[c6_i34];
  }

  for (c6_i35 = 0; c6_i35 < 3; c6_i35++) {
    c6_b[c6_i35] = c6_x[c6_i35];
  }

  c6_eml_scalar_eg(chartInstance);
  c6_eml_scalar_eg(chartInstance);
  for (c6_i36 = 0; c6_i36 < 3; c6_i36++) {
    c6_y[c6_i36] = 0.0;
    c6_i37 = 0;
    for (c6_i38 = 0; c6_i38 < 3; c6_i38++) {
      c6_y[c6_i36] += c6_a[c6_i37 + c6_i36] * c6_b[c6_i38];
      c6_i37 += 3;
    }
  }

  for (c6_i39 = 0; c6_i39 < 9; c6_i39++) {
    c6_a[c6_i39] = c6_BB_delay[c6_i39];
  }

  for (c6_i40 = 0; c6_i40 < 3; c6_i40++) {
    c6_b[c6_i40] = c6_u_buff[c6_i40];
  }

  c6_eml_scalar_eg(chartInstance);
  c6_eml_scalar_eg(chartInstance);
  for (c6_i41 = 0; c6_i41 < 3; c6_i41++) {
    c6_b_y[c6_i41] = 0.0;
    c6_i42 = 0;
    for (c6_i43 = 0; c6_i43 < 3; c6_i43++) {
      c6_b_y[c6_i41] += c6_a[c6_i42 + c6_i41] * c6_b[c6_i43];
      c6_i42 += 3;
    }
  }

  for (c6_i44 = 0; c6_i44 < 3; c6_i44++) {
    c6_x_predicted[c6_i44] = c6_y[c6_i44] + c6_b_y[c6_i44];
  }

  _SFD_EML_CALL(0U, *c6_sfEvent, 18);
  for (c6_i45 = 0; c6_i45 < 30; c6_i45++) {
    c6_U_ref[c6_i45] = 0.0;
  }

  _SFD_EML_CALL(0U, *c6_sfEvent, 21);
  for (c6_i46 = 0; c6_i46 < 3; c6_i46++) {
    c6_b_a[c6_i46] = c6_x_predicted[c6_i46];
  }

  for (c6_i47 = 0; c6_i47 < 90; c6_i47++) {
    c6_b_b[c6_i47] = c6_LL_PP[c6_i47];
  }

  c6_b_eml_scalar_eg(chartInstance);
  c6_b_eml_scalar_eg(chartInstance);
  c6_i48 = 0;
  for (c6_i49 = 0; c6_i49 < 30; c6_i49++) {
    c6_c_y[c6_i49] = 0.0;
    for (c6_i50 = 0; c6_i50 < 3; c6_i50++) {
      c6_c_y[c6_i49] += c6_b_a[c6_i50] * c6_b_b[c6_i50 + c6_i48];
    }

    c6_i48 += 3;
  }

  for (c6_i51 = 0; c6_i51 < 93; c6_i51++) {
    c6_c_a[c6_i51] = c6_X_ref[c6_i51];
  }

  for (c6_i52 = 0; c6_i52 < 2790; c6_i52++) {
    c6_c_b[c6_i52] = c6_LL_ref_PP[c6_i52];
  }

  c6_c_eml_scalar_eg(chartInstance);
  c6_c_eml_scalar_eg(chartInstance);
  for (c6_i53 = 0; c6_i53 < 30; c6_i53++) {
    c6_d_y[c6_i53] = 0.0;
  }

  for (c6_i54 = 0; c6_i54 < 93; c6_i54++) {
    c6_d_a[c6_i54] = c6_c_a[c6_i54];
  }

  for (c6_i55 = 0; c6_i55 < 2790; c6_i55++) {
    c6_d_b[c6_i55] = c6_c_b[c6_i55];
  }

  c6_d_eml_xgemm(chartInstance, c6_d_a, c6_d_b, c6_d_y);
  for (c6_i56 = 0; c6_i56 < 900; c6_i56++) {
    c6_e_b[c6_i56] = c6_LL_U_ref_PP[c6_i56];
  }

  c6_d_eml_scalar_eg(chartInstance);
  c6_d_eml_scalar_eg(chartInstance);
  for (c6_i57 = 0; c6_i57 < 30; c6_i57++) {
    c6_e_y[c6_i57] = 0.0;
  }

  for (c6_i58 = 0; c6_i58 < 30; c6_i58++) {
    c6_dv2[c6_i58] = 0.0;
  }

  for (c6_i59 = 0; c6_i59 < 900; c6_i59++) {
    c6_f_b[c6_i59] = c6_e_b[c6_i59];
  }

  c6_e_eml_xgemm(chartInstance, c6_dv2, c6_f_b, c6_e_y);
  for (c6_i60 = 0; c6_i60 < 30; c6_i60++) {
    c6_LL_PP_ref[c6_i60] = (c6_c_y[c6_i60] - c6_d_y[c6_i60]) - c6_e_y[c6_i60];
  }

  _SFD_EML_CALL(0U, *c6_sfEvent, 22);
  for (c6_i61 = 0; c6_i61 < 3; c6_i61++) {
    c6_b_a[c6_i61] = c6_x_predicted[c6_i61];
  }

  for (c6_i62 = 0; c6_i62 < 9; c6_i62++) {
    c6_a[c6_i62] = c6_MM[c6_i62];
  }

  c6_e_eml_scalar_eg(chartInstance);
  c6_e_eml_scalar_eg(chartInstance);
  c6_i63 = 0;
  for (c6_i64 = 0; c6_i64 < 3; c6_i64++) {
    c6_f_y[c6_i64] = 0.0;
    for (c6_i65 = 0; c6_i65 < 3; c6_i65++) {
      c6_f_y[c6_i64] += c6_b_a[c6_i65] * c6_a[c6_i65 + c6_i63];
    }

    c6_i63 += 3;
  }

  for (c6_i66 = 0; c6_i66 < 3; c6_i66++) {
    c6_b[c6_i66] = c6_x_predicted[c6_i66];
  }

  c6_f_eml_scalar_eg(chartInstance);
  c6_f_eml_scalar_eg(chartInstance);
  c6_MM_ref = 0.0;
  for (c6_k = 1; c6_k < 4; c6_k++) {
    c6_b_k = c6_k;
    c6_MM_ref += c6_f_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c6_b_k), 1, 3, 1, 0) - 1] *
      c6_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_b_k), 1, 3, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, *c6_sfEvent, 25);
  for (c6_i67 = 0; c6_i67 < 900; c6_i67++) {
    c6_b_TT_PP[c6_i67] = c6_TT_PP[c6_i67];
  }

  for (c6_i68 = 0; c6_i68 < 30; c6_i68++) {
    c6_b_LL_PP_ref[c6_i68] = c6_LL_PP_ref[c6_i68];
  }

  for (c6_i69 = 0; c6_i69 < 30; c6_i69++) {
    c6_b_V_max[c6_i69] = -c6_V_max[c6_i69];
  }

  for (c6_i70 = 0; c6_i70 < 30; c6_i70++) {
    c6_c_V_max[c6_i70] = c6_V_max[c6_i70];
  }

  for (c6_i71 = 0; c6_i71 < 30; c6_i71++) {
    c6_b_V_init[c6_i71] = c6_V_init[c6_i71];
  }

  for (c6_i72 = 0; c6_i72 < 7; c6_i72++) {
    c6_b_betas[c6_i72] = c6_betas[c6_i72];
  }

  c6_runFastGradient(chartInstance, c6_b_TT_PP, c6_b_LL_PP_ref, c6_MM_ref,
                     c6_b_V_max, c6_c_V_max, c6_b_V_init, c6_i_min, c6_b_betas,
                     c6_L, &c6_b_J_star, c6_b_V_star, &c6_c_unusedU0);
  c6_J_star = c6_b_J_star;
  for (c6_i73 = 0; c6_i73 < 30; c6_i73++) {
    c6_V_star[c6_i73] = c6_b_V_star[c6_i73];
  }

  c6_unusedU0 = c6_c_unusedU0;
  sf_debug_symbol_switch(8U, 8U);
  _SFD_EML_CALL(0U, *c6_sfEvent, 25);
  c6_b_unusedU0 = 0.0;
  sf_debug_symbol_switch(8U, 9U);
  _SFD_EML_CALL(0U, *c6_sfEvent, 32);
  for (c6_i74 = 0; c6_i74 < 900; c6_i74++) {
    c6_e_b[c6_i74] = c6_PP[c6_i74];
  }

  for (c6_i75 = 0; c6_i75 < 30; c6_i75++) {
    c6_b_V_star[c6_i75] = c6_V_star[c6_i75];
  }

  c6_g_eml_scalar_eg(chartInstance);
  c6_g_eml_scalar_eg(chartInstance);
  for (c6_i76 = 0; c6_i76 < 30; c6_i76++) {
    c6_U_star[c6_i76] = 0.0;
  }

  for (c6_i77 = 0; c6_i77 < 30; c6_i77++) {
    c6_U_star[c6_i77] = 0.0;
  }

  for (c6_i78 = 0; c6_i78 < 900; c6_i78++) {
    c6_g_b[c6_i78] = c6_e_b[c6_i78];
  }

  for (c6_i79 = 0; c6_i79 < 30; c6_i79++) {
    c6_c_V_star[c6_i79] = c6_b_V_star[c6_i79];
  }

  c6_f_eml_xgemm(chartInstance, c6_g_b, c6_c_V_star, c6_U_star);
  _SFD_EML_CALL(0U, *c6_sfEvent, 35);
  CV_EML_IF(0, 1, 1, c6_delay_steps == 0.0);
  _SFD_EML_CALL(0U, *c6_sfEvent, 38);
  for (c6_i80 = 0; c6_i80 < 2; c6_i80++) {
    c6_u_buff_out[c6_i80] = c6_u_buff[c6_i80 + 1];
  }

  c6_u_buff_out[2] = c6_U_star[0];
  _SFD_EML_CALL(0U, *c6_sfEvent, 42);
  for (c6_i81 = 0; c6_i81 < 29; c6_i81++) {
    c6_V_init_out[c6_i81] = c6_V_star[c6_i81 + 1];
  }

  c6_V_init_out[29] = 0.0;
  _SFD_EML_CALL(0U, *c6_sfEvent, 44);
  c6_u_opt = c6_U_star[0];
  _SFD_EML_CALL(0U, *c6_sfEvent, -44);
  sf_debug_symbol_scope_pop();
  *c6_b_u_opt = c6_u_opt;
  *c6_c_J_star = c6_J_star;
  for (c6_i82 = 0; c6_i82 < 3; c6_i82++) {
    (*c6_b_u_buff_out)[c6_i82] = c6_u_buff_out[c6_i82];
  }

  for (c6_i83 = 0; c6_i83 < 30; c6_i83++) {
    (*c6_b_V_init_out)[c6_i83] = c6_V_init_out[c6_i83];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *c6_sfEvent);
}

static void initSimStructsc6_Hquad_control_LIB_MPC
  (SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c6_chartNumber, 0U, sf_debug_get_script_id(
    "/home/burrimi/svn/airobots/trunk/AIR_traj_control/Matlab/MPC_FastGradient/tools/runFastGradient.m"));
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i84;
  real_T c6_b_inData[30];
  int32_T c6_i85;
  real_T c6_u[30];
  const mxArray *c6_y = NULL;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i84 = 0; c6_i84 < 30; c6_i84++) {
    c6_b_inData[c6_i84] = (*(real_T (*)[30])c6_inData)[c6_i84];
  }

  for (c6_i85 = 0; c6_i85 < 30; c6_i85++) {
    c6_u[c6_i85] = c6_b_inData[c6_i85];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 30), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_V_init_out, const char_T *c6_identifier,
  real_T c6_y[30])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_V_init_out), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_V_init_out);
}

static void c6_b_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[30])
{
  real_T c6_dv3[30];
  int32_T c6_i86;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv3, 1, 0, 0U, 1, 0U, 1, 30);
  for (c6_i86 = 0; c6_i86 < 30; c6_i86++) {
    c6_y[c6_i86] = c6_dv3[c6_i86];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_V_init_out;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[30];
  int32_T c6_i87;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_V_init_out = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_V_init_out), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_V_init_out);
  for (c6_i87 = 0; c6_i87 < 30; c6_i87++) {
    (*(real_T (*)[30])c6_outData)[c6_i87] = c6_y[c6_i87];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i88;
  real_T c6_b_inData[3];
  int32_T c6_i89;
  real_T c6_u[3];
  const mxArray *c6_y = NULL;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i88 = 0; c6_i88 < 3; c6_i88++) {
    c6_b_inData[c6_i88] = (*(real_T (*)[3])c6_inData)[c6_i88];
  }

  for (c6_i89 = 0; c6_i89 < 3; c6_i89++) {
    c6_u[c6_i89] = c6_b_inData[c6_i89];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_c_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u_buff_out, const char_T *c6_identifier,
  real_T c6_y[3])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_u_buff_out), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_u_buff_out);
}

static void c6_d_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[3])
{
  real_T c6_dv4[3];
  int32_T c6_i90;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv4, 1, 0, 0U, 1, 0U, 1, 3);
  for (c6_i90 = 0; c6_i90 < 3; c6_i90++) {
    c6_y[c6_i90] = c6_dv4[c6_i90];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_u_buff_out;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[3];
  int32_T c6_i91;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_u_buff_out = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_u_buff_out), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_u_buff_out);
  for (c6_i91 = 0; c6_i91 < 3; c6_i91++) {
    (*(real_T (*)[3])c6_outData)[c6_i91] = c6_y[c6_i91];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_e_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_J_star, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_J_star), &c6_thisId);
  sf_mex_destroy(&c6_J_star);
  return c6_y;
}

static real_T c6_f_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_J_star;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_J_star = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_J_star), &c6_thisId);
  sf_mex_destroy(&c6_J_star);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i92;
  real_T c6_b_inData[7];
  int32_T c6_i93;
  real_T c6_u[7];
  const mxArray *c6_y = NULL;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i92 = 0; c6_i92 < 7; c6_i92++) {
    c6_b_inData[c6_i92] = (*(real_T (*)[7])c6_inData)[c6_i92];
  }

  for (c6_i93 = 0; c6_i93 < 7; c6_i93++) {
    c6_u[c6_i93] = c6_b_inData[c6_i93];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 7), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i94;
  real_T c6_b_inData[93];
  int32_T c6_i95;
  real_T c6_u[93];
  const mxArray *c6_y = NULL;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i94 = 0; c6_i94 < 93; c6_i94++) {
    c6_b_inData[c6_i94] = (*(real_T (*)[93])c6_inData)[c6_i94];
  }

  for (c6_i95 = 0; c6_i95 < 93; c6_i95++) {
    c6_u[c6_i95] = c6_b_inData[c6_i95];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 1, 93), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i96;
  int32_T c6_i97;
  int32_T c6_i98;
  real_T c6_b_inData[9];
  int32_T c6_i99;
  int32_T c6_i100;
  int32_T c6_i101;
  real_T c6_u[9];
  const mxArray *c6_y = NULL;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i96 = 0;
  for (c6_i97 = 0; c6_i97 < 3; c6_i97++) {
    for (c6_i98 = 0; c6_i98 < 3; c6_i98++) {
      c6_b_inData[c6_i98 + c6_i96] = (*(real_T (*)[9])c6_inData)[c6_i98 + c6_i96];
    }

    c6_i96 += 3;
  }

  c6_i99 = 0;
  for (c6_i100 = 0; c6_i100 < 3; c6_i100++) {
    for (c6_i101 = 0; c6_i101 < 3; c6_i101++) {
      c6_u[c6_i101 + c6_i99] = c6_b_inData[c6_i101 + c6_i99];
    }

    c6_i99 += 3;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_g_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i102;
  int32_T c6_i103;
  int32_T c6_i104;
  real_T c6_b_inData[900];
  int32_T c6_i105;
  int32_T c6_i106;
  int32_T c6_i107;
  real_T c6_u[900];
  const mxArray *c6_y = NULL;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i102 = 0;
  for (c6_i103 = 0; c6_i103 < 30; c6_i103++) {
    for (c6_i104 = 0; c6_i104 < 30; c6_i104++) {
      c6_b_inData[c6_i104 + c6_i102] = (*(real_T (*)[900])c6_inData)[c6_i104 +
        c6_i102];
    }

    c6_i102 += 30;
  }

  c6_i105 = 0;
  for (c6_i106 = 0; c6_i106 < 30; c6_i106++) {
    for (c6_i107 = 0; c6_i107 < 30; c6_i107++) {
      c6_u[c6_i107 + c6_i105] = c6_b_inData[c6_i107 + c6_i105];
    }

    c6_i105 += 30;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 30, 30), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_h_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i108;
  int32_T c6_i109;
  int32_T c6_i110;
  real_T c6_b_inData[2790];
  int32_T c6_i111;
  int32_T c6_i112;
  int32_T c6_i113;
  real_T c6_u[2790];
  const mxArray *c6_y = NULL;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i108 = 0;
  for (c6_i109 = 0; c6_i109 < 30; c6_i109++) {
    for (c6_i110 = 0; c6_i110 < 93; c6_i110++) {
      c6_b_inData[c6_i110 + c6_i108] = (*(real_T (*)[2790])c6_inData)[c6_i110 +
        c6_i108];
    }

    c6_i108 += 93;
  }

  c6_i111 = 0;
  for (c6_i112 = 0; c6_i112 < 30; c6_i112++) {
    for (c6_i113 = 0; c6_i113 < 93; c6_i113++) {
      c6_u[c6_i113 + c6_i111] = c6_b_inData[c6_i113 + c6_i111];
    }

    c6_i111 += 93;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 93, 30), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_i_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i114;
  int32_T c6_i115;
  int32_T c6_i116;
  real_T c6_b_inData[90];
  int32_T c6_i117;
  int32_T c6_i118;
  int32_T c6_i119;
  real_T c6_u[90];
  const mxArray *c6_y = NULL;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_i114 = 0;
  for (c6_i115 = 0; c6_i115 < 30; c6_i115++) {
    for (c6_i116 = 0; c6_i116 < 3; c6_i116++) {
      c6_b_inData[c6_i116 + c6_i114] = (*(real_T (*)[90])c6_inData)[c6_i116 +
        c6_i114];
    }

    c6_i114 += 3;
  }

  c6_i117 = 0;
  for (c6_i118 = 0; c6_i118 < 30; c6_i118++) {
    for (c6_i119 = 0; c6_i119 < 3; c6_i119++) {
      c6_u[c6_i119 + c6_i117] = c6_b_inData[c6_i119 + c6_i117];
    }

    c6_i117 += 3;
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 3, 30), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static const mxArray *c6_j_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_i120;
  real_T c6_b_inData[30];
  int32_T c6_i121;
  real_T c6_u[30];
  const mxArray *c6_y = NULL;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  for (c6_i120 = 0; c6_i120 < 30; c6_i120++) {
    c6_b_inData[c6_i120] = (*(real_T (*)[30])c6_inData)[c6_i120];
  }

  for (c6_i121 = 0; c6_i121 < 30; c6_i121++) {
    c6_u[c6_i121] = c6_b_inData[c6_i121];
  }

  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_u, 0, 0U, 1U, 0U, 2, 1, 30), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static void c6_g_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[30])
{
  real_T c6_dv5[30];
  int32_T c6_i122;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv5, 1, 0, 0U, 1, 0U, 2, 1, 30);
  for (c6_i122 = 0; c6_i122 < 30; c6_i122++) {
    c6_y[c6_i122] = c6_dv5[c6_i122];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_LL_PP_ref;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[30];
  int32_T c6_i123;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_LL_PP_ref = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_LL_PP_ref), &c6_thisId,
                        c6_y);
  sf_mex_destroy(&c6_LL_PP_ref);
  for (c6_i123 = 0; c6_i123 < 30; c6_i123++) {
    (*(real_T (*)[30])c6_outData)[c6_i123] = c6_y[c6_i123];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static void c6_h_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[7])
{
  real_T c6_dv6[7];
  int32_T c6_i124;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv6, 1, 0, 0U, 1, 0U, 1, 7);
  for (c6_i124 = 0; c6_i124 < 7; c6_i124++) {
    c6_y[c6_i124] = c6_dv6[c6_i124];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_betas;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[7];
  int32_T c6_i125;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_betas = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_betas), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_betas);
  for (c6_i125 = 0; c6_i125 < 7; c6_i125++) {
    (*(real_T (*)[7])c6_outData)[c6_i125] = c6_y[c6_i125];
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static void c6_i_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_y[900])
{
  real_T c6_dv7[900];
  int32_T c6_i126;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv7, 1, 0, 0U, 1, 0U, 2, 30,
                30);
  for (c6_i126 = 0; c6_i126 < 900; c6_i126++) {
    c6_y[c6_i126] = c6_dv7[c6_i126];
  }

  sf_mex_destroy(&c6_u);
}

static void c6_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_TT_PP;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y[900];
  int32_T c6_i127;
  int32_T c6_i128;
  int32_T c6_i129;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_TT_PP = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_TT_PP), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_TT_PP);
  c6_i127 = 0;
  for (c6_i128 = 0; c6_i128 < 30; c6_i128++) {
    for (c6_i129 = 0; c6_i129 < 30; c6_i129++) {
      (*(real_T (*)[900])c6_outData)[c6_i129 + c6_i127] = c6_y[c6_i129 + c6_i127];
    }

    c6_i127 += 30;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_k_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  const mxArray *c6_y = NULL;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

const mxArray *sf_c6_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[24];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i130;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_info_helper(c6_info);
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 24), FALSE);
  for (c6_i130 = 0; c6_i130 < 24; c6_i130++) {
    c6_r0 = &c6_info[c6_i130];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i130);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i130);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i130);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i130);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i130);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i130);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i130);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i130);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  return c6_nameCaptureInfo;
}

static void c6_info_helper(c6_ResolvedFunctionInfo c6_info[24])
{
  c6_info[0].context = "";
  c6_info[0].name = "mtimes";
  c6_info[0].dominantType = "double";
  c6_info[0].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[0].fileTimeLo = 1289519692U;
  c6_info[0].fileTimeHi = 0U;
  c6_info[0].mFileTimeLo = 0U;
  c6_info[0].mFileTimeHi = 0U;
  c6_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[1].name = "eml_index_class";
  c6_info[1].dominantType = "";
  c6_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c6_info[1].fileTimeLo = 1286818778U;
  c6_info[1].fileTimeHi = 0U;
  c6_info[1].mFileTimeLo = 0U;
  c6_info[1].mFileTimeHi = 0U;
  c6_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[2].name = "eml_scalar_eg";
  c6_info[2].dominantType = "double";
  c6_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c6_info[2].fileTimeLo = 1286818796U;
  c6_info[2].fileTimeHi = 0U;
  c6_info[2].mFileTimeLo = 0U;
  c6_info[2].mFileTimeHi = 0U;
  c6_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[3].name = "eml_xgemm";
  c6_info[3].dominantType = "int32";
  c6_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[3].fileTimeLo = 1299076772U;
  c6_info[3].fileTimeHi = 0U;
  c6_info[3].mFileTimeLo = 0U;
  c6_info[3].mFileTimeHi = 0U;
  c6_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c6_info[4].name = "eml_blas_inline";
  c6_info[4].dominantType = "";
  c6_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c6_info[4].fileTimeLo = 1299076768U;
  c6_info[4].fileTimeHi = 0U;
  c6_info[4].mFileTimeLo = 0U;
  c6_info[4].mFileTimeHi = 0U;
  c6_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c6_info[5].name = "eml_refblas_xgemm";
  c6_info[5].dominantType = "int32";
  c6_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c6_info[5].fileTimeLo = 1299076774U;
  c6_info[5].fileTimeHi = 0U;
  c6_info[5].mFileTimeLo = 0U;
  c6_info[5].mFileTimeHi = 0U;
  c6_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c6_info[6].name = "eml_xdotu";
  c6_info[6].dominantType = "int32";
  c6_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c6_info[6].fileTimeLo = 1299076772U;
  c6_info[6].fileTimeHi = 0U;
  c6_info[6].mFileTimeLo = 0U;
  c6_info[6].mFileTimeHi = 0U;
  c6_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c6_info[7].name = "eml_xdot";
  c6_info[7].dominantType = "int32";
  c6_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c6_info[7].fileTimeLo = 1299076772U;
  c6_info[7].fileTimeHi = 0U;
  c6_info[7].mFileTimeLo = 0U;
  c6_info[7].mFileTimeHi = 0U;
  c6_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c6_info[8].name = "eml_refblas_xdot";
  c6_info[8].dominantType = "int32";
  c6_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c6_info[8].fileTimeLo = 1299076772U;
  c6_info[8].fileTimeHi = 0U;
  c6_info[8].mFileTimeLo = 0U;
  c6_info[8].mFileTimeHi = 0U;
  c6_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c6_info[9].name = "eml_refblas_xdotx";
  c6_info[9].dominantType = "int32";
  c6_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[9].fileTimeLo = 1299076774U;
  c6_info[9].fileTimeHi = 0U;
  c6_info[9].mFileTimeLo = 0U;
  c6_info[9].mFileTimeHi = 0U;
  c6_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[10].name = "eml_index_minus";
  c6_info[10].dominantType = "int32";
  c6_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c6_info[10].fileTimeLo = 1286818778U;
  c6_info[10].fileTimeHi = 0U;
  c6_info[10].mFileTimeLo = 0U;
  c6_info[10].mFileTimeHi = 0U;
  c6_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[11].name = "eml_index_times";
  c6_info[11].dominantType = "int32";
  c6_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c6_info[11].fileTimeLo = 1286818780U;
  c6_info[11].fileTimeHi = 0U;
  c6_info[11].mFileTimeLo = 0U;
  c6_info[11].mFileTimeHi = 0U;
  c6_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c6_info[12].name = "eml_index_plus";
  c6_info[12].dominantType = "int32";
  c6_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c6_info[12].fileTimeLo = 1286818778U;
  c6_info[12].fileTimeHi = 0U;
  c6_info[12].mFileTimeLo = 0U;
  c6_info[12].mFileTimeHi = 0U;
  c6_info[13].context = "";
  c6_info[13].name = "runFastGradient";
  c6_info[13].dominantType = "double";
  c6_info[13].resolved =
    "[E]/home/burrimi/svn/airobots/trunk/AIR_traj_control/Matlab/MPC_FastGradient/tools/runFastGradient.m";
  c6_info[13].fileTimeLo = 1331828792U;
  c6_info[13].fileTimeHi = 0U;
  c6_info[13].mFileTimeLo = 0U;
  c6_info[13].mFileTimeHi = 0U;
  c6_info[14].context =
    "[E]/home/burrimi/svn/airobots/trunk/AIR_traj_control/Matlab/MPC_FastGradient/tools/runFastGradient.m";
  c6_info[14].name = "mrdivide";
  c6_info[14].dominantType = "double";
  c6_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[14].fileTimeLo = 1310137456U;
  c6_info[14].fileTimeHi = 0U;
  c6_info[14].mFileTimeLo = 1289519692U;
  c6_info[14].mFileTimeHi = 0U;
  c6_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c6_info[15].name = "rdivide";
  c6_info[15].dominantType = "double";
  c6_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[15].fileTimeLo = 1286818844U;
  c6_info[15].fileTimeHi = 0U;
  c6_info[15].mFileTimeLo = 0U;
  c6_info[15].mFileTimeHi = 0U;
  c6_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c6_info[16].name = "eml_div";
  c6_info[16].dominantType = "double";
  c6_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c6_info[16].fileTimeLo = 1305318000U;
  c6_info[16].fileTimeHi = 0U;
  c6_info[16].mFileTimeLo = 0U;
  c6_info[16].mFileTimeHi = 0U;
  c6_info[17].context =
    "[E]/home/burrimi/svn/airobots/trunk/AIR_traj_control/Matlab/MPC_FastGradient/tools/runFastGradient.m";
  c6_info[17].name = "min";
  c6_info[17].dominantType = "double";
  c6_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[17].fileTimeLo = 1308747330U;
  c6_info[17].fileTimeHi = 0U;
  c6_info[17].mFileTimeLo = 0U;
  c6_info[17].mFileTimeHi = 0U;
  c6_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c6_info[18].name = "eml_min_or_max";
  c6_info[18].dominantType = "char";
  c6_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c6_info[18].fileTimeLo = 1303146212U;
  c6_info[18].fileTimeHi = 0U;
  c6_info[18].mFileTimeLo = 0U;
  c6_info[18].mFileTimeHi = 0U;
  c6_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c6_info[19].name = "eml_scalexp_alloc";
  c6_info[19].dominantType = "double";
  c6_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[19].fileTimeLo = 1286818796U;
  c6_info[19].fileTimeHi = 0U;
  c6_info[19].mFileTimeLo = 0U;
  c6_info[19].mFileTimeHi = 0U;
  c6_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c6_info[20].name = "isequal";
  c6_info[20].dominantType = "double";
  c6_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c6_info[20].fileTimeLo = 1286818758U;
  c6_info[20].fileTimeHi = 0U;
  c6_info[20].mFileTimeLo = 0U;
  c6_info[20].mFileTimeHi = 0U;
  c6_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c6_info[21].name = "eml_isequal_core";
  c6_info[21].dominantType = "double";
  c6_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c6_info[21].fileTimeLo = 1286818786U;
  c6_info[21].fileTimeHi = 0U;
  c6_info[21].mFileTimeLo = 0U;
  c6_info[21].mFileTimeHi = 0U;
  c6_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  c6_info[22].name = "isnan";
  c6_info[22].dominantType = "double";
  c6_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c6_info[22].fileTimeLo = 1286818760U;
  c6_info[22].fileTimeHi = 0U;
  c6_info[22].mFileTimeLo = 0U;
  c6_info[22].mFileTimeHi = 0U;
  c6_info[23].context =
    "[E]/home/burrimi/svn/airobots/trunk/AIR_traj_control/Matlab/MPC_FastGradient/tools/runFastGradient.m";
  c6_info[23].name = "max";
  c6_info[23].dominantType = "double";
  c6_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m";
  c6_info[23].fileTimeLo = 1308747328U;
  c6_info[23].fileTimeHi = 0U;
  c6_info[23].mFileTimeLo = 0U;
  c6_info[23].mFileTimeHi = 0U;
}

static void c6_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c6_b_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c6_c_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c6_eml_xgemm(SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance,
  real_T c6_A[93], real_T c6_B[2790], real_T c6_C[30], real_T c6_b_C[30])
{
  int32_T c6_i131;
  int32_T c6_i132;
  real_T c6_b_A[93];
  int32_T c6_i133;
  real_T c6_b_B[2790];
  for (c6_i131 = 0; c6_i131 < 30; c6_i131++) {
    c6_b_C[c6_i131] = c6_C[c6_i131];
  }

  for (c6_i132 = 0; c6_i132 < 93; c6_i132++) {
    c6_b_A[c6_i132] = c6_A[c6_i132];
  }

  for (c6_i133 = 0; c6_i133 < 2790; c6_i133++) {
    c6_b_B[c6_i133] = c6_B[c6_i133];
  }

  c6_d_eml_xgemm(chartInstance, c6_b_A, c6_b_B, c6_b_C);
}

static void c6_d_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c6_b_eml_xgemm(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_A[30], real_T c6_B[900], real_T c6_C[30], real_T
  c6_b_C[30])
{
  int32_T c6_i134;
  int32_T c6_i135;
  real_T c6_b_A[30];
  int32_T c6_i136;
  real_T c6_b_B[900];
  for (c6_i134 = 0; c6_i134 < 30; c6_i134++) {
    c6_b_C[c6_i134] = c6_C[c6_i134];
  }

  for (c6_i135 = 0; c6_i135 < 30; c6_i135++) {
    c6_b_A[c6_i135] = c6_A[c6_i135];
  }

  for (c6_i136 = 0; c6_i136 < 900; c6_i136++) {
    c6_b_B[c6_i136] = c6_B[c6_i136];
  }

  c6_e_eml_xgemm(chartInstance, c6_b_A, c6_b_B, c6_b_C);
}

static void c6_e_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c6_f_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c6_runFastGradient(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_TT_PP[900], real_T c6_LL_PP[30], real_T c6_MM,
  real_T c6_V_min[30], real_T c6_V_max[30], real_T c6_V_init[30], real_T
  c6_i_min, real_T c6_betas[7], real_T c6_L, real_T *c6_J, real_T c6_V[30],
  real_T *c6_actual_num_iters)
{
  uint32_T c6_debug_family_var_map[22];
  real_T c6_MONITOR;
  real_T c6_L_inv;
  real_T c6_LL_PP_t[30];
  real_T c6_V_i[30];
  real_T c6_W_i[30];
  real_T c6_V_ip1[30];
  real_T c6_W_ip1[30];
  real_T c6_nargin = 10.0;
  real_T c6_nargout = 3.0;
  int32_T c6_i137;
  int32_T c6_i138;
  real_T c6_a[900];
  int32_T c6_i139;
  real_T c6_b[30];
  int32_T c6_i140;
  real_T c6_y[30];
  int32_T c6_i141;
  real_T c6_b_a[900];
  int32_T c6_i142;
  real_T c6_b_b[30];
  real_T c6_c_a;
  int32_T c6_i143;
  int32_T c6_i144;
  int32_T c6_i145;
  int32_T c6_i146;
  int32_T c6_k;
  int32_T c6_b_k;
  real_T c6_xk;
  real_T c6_yk;
  real_T c6_x;
  real_T c6_b_y;
  real_T c6_extremum;
  real_T c6_minval[30];
  int32_T c6_i147;
  int32_T c6_c_k;
  int32_T c6_d_k;
  real_T c6_b_xk;
  real_T c6_b_yk;
  real_T c6_b_x;
  real_T c6_c_y;
  real_T c6_b_extremum;
  int32_T c6_i148;
  int32_T c6_i149;
  int32_T c6_loop_ub;
  int32_T c6_i;
  real_T c6_b_i;
  int32_T c6_i150;
  int32_T c6_i151;
  int32_T c6_i152;
  int32_T c6_i153;
  real_T c6_d_a[900];
  int32_T c6_i154;
  real_T c6_c_b[30];
  real_T c6_e_a;
  int32_T c6_i155;
  int32_T c6_i156;
  int32_T c6_i157;
  int32_T c6_i158;
  int32_T c6_e_k;
  int32_T c6_f_k;
  real_T c6_c_xk;
  real_T c6_c_yk;
  real_T c6_c_x;
  real_T c6_d_y;
  real_T c6_c_extremum;
  int32_T c6_i159;
  int32_T c6_g_k;
  int32_T c6_h_k;
  real_T c6_d_xk;
  real_T c6_d_yk;
  real_T c6_d_x;
  real_T c6_e_y;
  real_T c6_d_extremum;
  real_T c6_f_a;
  int32_T c6_i160;
  int32_T c6_i161;
  int32_T c6_i162;
  int32_T c6_i163;
  int32_T c6_i164;
  int32_T c6_i165;
  int32_T c6_i166;
  real_T c6_d_b[30];
  int32_T c6_i167;
  int32_T c6_i168;
  int32_T c6_i169;
  real_T c6_f_y[30];
  int32_T c6_i170;
  real_T c6_e_b[30];
  int32_T c6_i171;
  real_T c6_g_a[900];
  int32_T c6_i172;
  real_T c6_g_y;
  int32_T c6_i_k;
  int32_T c6_j_k;
  int32_T c6_i173;
  int32_T c6_i174;
  real_T c6_h_y;
  int32_T c6_k_k;
  int32_T c6_l_k;
  int32_T *c6_sfEvent;
  c6_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 22U, 22U, c6_b_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c6_MONITOR, 0U, c6_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_L_inv, 1U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_LL_PP_t, 2U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_V_i, 3U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_W_i, 4U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_V_ip1, 5U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_W_ip1, 6U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(NULL, 7U, c6_k_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 8U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 9U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_TT_PP, 10U, c6_g_sf_marshallOut,
    c6_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_LL_PP, 11U, c6_j_sf_marshallOut,
    c6_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_MM, 12U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_V_min, 13U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_V_max, 14U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_V_init, 15U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_i_min, 16U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_betas, 17U, c6_d_sf_marshallOut,
    c6_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_L, 18U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_J, 19U, c6_c_sf_marshallOut,
    c6_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_V, 20U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c6_actual_num_iters, 21U,
    c6_c_sf_marshallOut, c6_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 33);
  c6_MONITOR = 0.0;
  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 34);
  *c6_actual_num_iters = rtInf;
  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 35);
  CV_SCRIPT_COND(0, 0, TRUE);
  CV_SCRIPT_MCDC(0, 0, FALSE);
  CV_SCRIPT_IF(0, 0, FALSE);
  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 41);
  c6_L_inv = c6_mrdivide(chartInstance, 1.0, c6_L);
  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 42);
  for (c6_i137 = 0; c6_i137 < 30; c6_i137++) {
    c6_LL_PP_t[c6_i137] = c6_LL_PP[c6_i137];
  }

  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 44);
  for (c6_i138 = 0; c6_i138 < 900; c6_i138++) {
    c6_a[c6_i138] = c6_TT_PP[c6_i138];
  }

  for (c6_i139 = 0; c6_i139 < 30; c6_i139++) {
    c6_b[c6_i139] = c6_V_init[c6_i139];
  }

  c6_g_eml_scalar_eg(chartInstance);
  c6_g_eml_scalar_eg(chartInstance);
  for (c6_i140 = 0; c6_i140 < 30; c6_i140++) {
    c6_y[c6_i140] = 0.0;
  }

  for (c6_i141 = 0; c6_i141 < 900; c6_i141++) {
    c6_b_a[c6_i141] = c6_a[c6_i141];
  }

  for (c6_i142 = 0; c6_i142 < 30; c6_i142++) {
    c6_b_b[c6_i142] = c6_b[c6_i142];
  }

  c6_f_eml_xgemm(chartInstance, c6_b_a, c6_b_b, c6_y);
  c6_c_a = c6_L_inv;
  for (c6_i143 = 0; c6_i143 < 30; c6_i143++) {
    c6_y[c6_i143] += c6_LL_PP_t[c6_i143];
  }

  for (c6_i144 = 0; c6_i144 < 30; c6_i144++) {
    c6_y[c6_i144] *= c6_c_a;
  }

  for (c6_i145 = 0; c6_i145 < 30; c6_i145++) {
    c6_b[c6_i145] = c6_V_max[c6_i145];
  }

  for (c6_i146 = 0; c6_i146 < 30; c6_i146++) {
    c6_y[c6_i146] = c6_V_init[c6_i146] - c6_y[c6_i146];
  }

  c6_h_eml_scalar_eg(chartInstance);
  for (c6_k = 1; c6_k < 31; c6_k++) {
    c6_b_k = c6_k;
    c6_xk = c6_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_b_k), 1, 30, 1, 0) - 1];
    c6_yk = c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_b_k), 1, 30, 1, 0) - 1];
    c6_x = c6_xk;
    c6_b_y = c6_yk;
    c6_i_eml_scalar_eg(chartInstance);
    c6_extremum = muDoubleScalarMin(c6_x, c6_b_y);
    c6_minval[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_b_k), 1, 30, 1, 0) - 1] = c6_extremum;
  }

  for (c6_i147 = 0; c6_i147 < 30; c6_i147++) {
    c6_b[c6_i147] = c6_V_min[c6_i147];
  }

  c6_h_eml_scalar_eg(chartInstance);
  for (c6_c_k = 1; c6_c_k < 31; c6_c_k++) {
    c6_d_k = c6_c_k;
    c6_b_xk = c6_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c6_d_k), 1, 30, 1, 0) - 1];
    c6_b_yk = c6_minval[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c6_d_k), 1, 30, 1, 0) - 1];
    c6_b_x = c6_b_xk;
    c6_c_y = c6_b_yk;
    c6_i_eml_scalar_eg(chartInstance);
    c6_b_extremum = muDoubleScalarMax(c6_b_x, c6_c_y);
    c6_V_i[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c6_d_k), 1, 30, 1, 0) - 1] = c6_b_extremum;
  }

  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 45);
  for (c6_i148 = 0; c6_i148 < 30; c6_i148++) {
    c6_W_i[c6_i148] = c6_V_i[c6_i148];
  }

  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 47);
  CV_SCRIPT_IF(0, 1, c6_MONITOR != 0.0);
  c6_i149 = (int32_T)c6_i_min;
  sf_debug_for_loop_vector_check(1.0, 1.0, c6_i_min, mxDOUBLE_CLASS, c6_i149);
  c6_loop_ub = c6_i149;
  c6_i = 0;
  while (c6_i <= c6_loop_ub - 1) {
    c6_b_i = 1.0 + (real_T)c6_i;
    CV_SCRIPT_FOR(0, 0, 1);
    _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 59);
    for (c6_i150 = 0; c6_i150 < 900; c6_i150++) {
      c6_a[c6_i150] = c6_TT_PP[c6_i150];
    }

    for (c6_i151 = 0; c6_i151 < 30; c6_i151++) {
      c6_b[c6_i151] = c6_W_i[c6_i151];
    }

    c6_g_eml_scalar_eg(chartInstance);
    c6_g_eml_scalar_eg(chartInstance);
    for (c6_i152 = 0; c6_i152 < 30; c6_i152++) {
      c6_y[c6_i152] = 0.0;
    }

    for (c6_i153 = 0; c6_i153 < 900; c6_i153++) {
      c6_d_a[c6_i153] = c6_a[c6_i153];
    }

    for (c6_i154 = 0; c6_i154 < 30; c6_i154++) {
      c6_c_b[c6_i154] = c6_b[c6_i154];
    }

    c6_f_eml_xgemm(chartInstance, c6_d_a, c6_c_b, c6_y);
    c6_e_a = c6_L_inv;
    for (c6_i155 = 0; c6_i155 < 30; c6_i155++) {
      c6_y[c6_i155] += c6_LL_PP_t[c6_i155];
    }

    for (c6_i156 = 0; c6_i156 < 30; c6_i156++) {
      c6_y[c6_i156] *= c6_e_a;
    }

    for (c6_i157 = 0; c6_i157 < 30; c6_i157++) {
      c6_b[c6_i157] = c6_V_max[c6_i157];
    }

    for (c6_i158 = 0; c6_i158 < 30; c6_i158++) {
      c6_y[c6_i158] = c6_W_i[c6_i158] - c6_y[c6_i158];
    }

    c6_h_eml_scalar_eg(chartInstance);
    for (c6_e_k = 1; c6_e_k < 31; c6_e_k++) {
      c6_f_k = c6_e_k;
      c6_c_xk = c6_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c6_f_k), 1, 30, 1, 0) - 1];
      c6_c_yk = c6_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c6_f_k), 1, 30, 1, 0) - 1];
      c6_c_x = c6_c_xk;
      c6_d_y = c6_c_yk;
      c6_i_eml_scalar_eg(chartInstance);
      c6_c_extremum = muDoubleScalarMin(c6_c_x, c6_d_y);
      c6_minval[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_f_k), 1, 30, 1, 0) - 1] = c6_c_extremum;
    }

    for (c6_i159 = 0; c6_i159 < 30; c6_i159++) {
      c6_b[c6_i159] = c6_V_min[c6_i159];
    }

    c6_h_eml_scalar_eg(chartInstance);
    for (c6_g_k = 1; c6_g_k < 31; c6_g_k++) {
      c6_h_k = c6_g_k;
      c6_d_xk = c6_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c6_h_k), 1, 30, 1, 0) - 1];
      c6_d_yk = c6_minval[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c6_h_k), 1, 30, 1, 0) - 1];
      c6_d_x = c6_d_xk;
      c6_e_y = c6_d_yk;
      c6_i_eml_scalar_eg(chartInstance);
      c6_d_extremum = muDoubleScalarMax(c6_d_x, c6_e_y);
      c6_V_ip1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c6_h_k), 1, 30, 1, 0) - 1] = c6_d_extremum;
    }

    _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 62);
    c6_f_a = c6_betas[_SFD_EML_ARRAY_BOUNDS_CHECK("betas", (int32_T)
      _SFD_INTEGER_CHECK("i", c6_b_i), 1, 7, 1, 0) - 1];
    for (c6_i160 = 0; c6_i160 < 30; c6_i160++) {
      c6_b[c6_i160] = c6_V_ip1[c6_i160] - c6_V_i[c6_i160];
    }

    for (c6_i161 = 0; c6_i161 < 30; c6_i161++) {
      c6_b[c6_i161] *= c6_f_a;
    }

    for (c6_i162 = 0; c6_i162 < 30; c6_i162++) {
      c6_W_ip1[c6_i162] = c6_V_ip1[c6_i162] + c6_b[c6_i162];
    }

    _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 64);
    for (c6_i163 = 0; c6_i163 < 30; c6_i163++) {
      c6_V_i[c6_i163] = c6_V_ip1[c6_i163];
    }

    _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 65);
    for (c6_i164 = 0; c6_i164 < 30; c6_i164++) {
      c6_W_i[c6_i164] = c6_W_ip1[c6_i164];
    }

    _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 67);
    CV_SCRIPT_IF(0, 3, c6_MONITOR != 0.0);
    c6_i++;
    sf_mex_listen_for_ctrl_c(chartInstance->S);
  }

  CV_SCRIPT_FOR(0, 0, 0);
  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 80);
  for (c6_i165 = 0; c6_i165 < 30; c6_i165++) {
    c6_V[c6_i165] = c6_V_i[c6_i165];
  }

  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 81);
  for (c6_i166 = 0; c6_i166 < 30; c6_i166++) {
    c6_d_b[c6_i166] = c6_V_i[c6_i166];
  }

  for (c6_i167 = 0; c6_i167 < 30; c6_i167++) {
    c6_d_b[c6_i167] *= 0.5;
  }

  for (c6_i168 = 0; c6_i168 < 900; c6_i168++) {
    c6_a[c6_i168] = c6_TT_PP[c6_i168];
  }

  c6_d_eml_scalar_eg(chartInstance);
  c6_d_eml_scalar_eg(chartInstance);
  for (c6_i169 = 0; c6_i169 < 30; c6_i169++) {
    c6_f_y[c6_i169] = 0.0;
  }

  for (c6_i170 = 0; c6_i170 < 30; c6_i170++) {
    c6_e_b[c6_i170] = c6_d_b[c6_i170];
  }

  for (c6_i171 = 0; c6_i171 < 900; c6_i171++) {
    c6_g_a[c6_i171] = c6_a[c6_i171];
  }

  c6_e_eml_xgemm(chartInstance, c6_e_b, c6_g_a, c6_f_y);
  for (c6_i172 = 0; c6_i172 < 30; c6_i172++) {
    c6_b[c6_i172] = c6_V_i[c6_i172];
  }

  c6_j_eml_scalar_eg(chartInstance);
  c6_j_eml_scalar_eg(chartInstance);
  c6_g_y = 0.0;
  for (c6_i_k = 1; c6_i_k < 31; c6_i_k++) {
    c6_j_k = c6_i_k;
    c6_g_y += c6_f_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c6_j_k), 1, 30, 1, 0) - 1] * c6_b[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_j_k), 1, 30, 1, 0) - 1];
  }

  for (c6_i173 = 0; c6_i173 < 30; c6_i173++) {
    c6_d_b[c6_i173] = c6_LL_PP[c6_i173];
  }

  for (c6_i174 = 0; c6_i174 < 30; c6_i174++) {
    c6_b[c6_i174] = c6_V_i[c6_i174];
  }

  c6_j_eml_scalar_eg(chartInstance);
  c6_j_eml_scalar_eg(chartInstance);
  c6_h_y = 0.0;
  for (c6_k_k = 1; c6_k_k < 31; c6_k_k++) {
    c6_l_k = c6_k_k;
    c6_h_y += c6_d_b[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c6_l_k), 1, 30, 1, 0) - 1] * c6_b[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c6_l_k), 1, 30, 1, 0) - 1];
  }

  *c6_J = (c6_g_y + c6_h_y) + c6_MM;
  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 82);
  CV_SCRIPT_IF(0, 5, CV_SCRIPT_MCDC(0, 1, !(CV_SCRIPT_COND(0, 1, c6_MONITOR !=
    0.0) != 0.0)));
  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, 83);
  *c6_actual_num_iters = c6_i_min;
  _SFD_SCRIPT_CALL(0U, *c6_sfEvent, -83);
  sf_debug_symbol_scope_pop();
}

static real_T c6_mrdivide(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_A, real_T c6_B)
{
  real_T c6_x;
  real_T c6_b_y;
  real_T c6_b_x;
  real_T c6_c_y;
  c6_x = c6_A;
  c6_b_y = c6_B;
  c6_b_x = c6_x;
  c6_c_y = c6_b_y;
  return c6_b_x / c6_c_y;
}

static void c6_g_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c6_c_eml_xgemm(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_A[900], real_T c6_B[30], real_T c6_C[30], real_T
  c6_b_C[30])
{
  int32_T c6_i175;
  int32_T c6_i176;
  real_T c6_b_A[900];
  int32_T c6_i177;
  real_T c6_b_B[30];
  for (c6_i175 = 0; c6_i175 < 30; c6_i175++) {
    c6_b_C[c6_i175] = c6_C[c6_i175];
  }

  for (c6_i176 = 0; c6_i176 < 900; c6_i176++) {
    c6_b_A[c6_i176] = c6_A[c6_i176];
  }

  for (c6_i177 = 0; c6_i177 < 30; c6_i177++) {
    c6_b_B[c6_i177] = c6_B[c6_i177];
  }

  c6_f_eml_xgemm(chartInstance, c6_b_A, c6_b_B, c6_b_C);
}

static void c6_h_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c6_i_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static void c6_j_eml_scalar_eg(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

static const mxArray *c6_l_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_j_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i178;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i178, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i178;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c6_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_sfEvent), &c6_thisId);
  sf_mex_destroy(&c6_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_k_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_is_active_c6_Hquad_control_LIB_MPC, const
  char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_is_active_c6_Hquad_control_LIB_MPC), &c6_thisId);
  sf_mex_destroy(&c6_is_active_c6_Hquad_control_LIB_MPC);
  return c6_y;
}

static uint8_T c6_l_emlrt_marshallIn(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_eml_xgemm(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_A[93], real_T c6_B[2790], real_T c6_C[30])
{
  int32_T c6_m;
  int32_T c6_n;
  int32_T c6_k;
  real_T c6_alpha1;
  int32_T c6_lda;
  int32_T c6_ldb;
  real_T c6_beta1;
  int32_T c6_ldc;
  char_T c6_TRANSA;
  char_T c6_TRANSB;
  c6_m = 1;
  c6_n = 30;
  c6_k = 93;
  c6_alpha1 = 1.0;
  c6_lda = 1;
  c6_ldb = 93;
  c6_beta1 = 0.0;
  c6_ldc = 1;
  c6_TRANSA = 'N';
  c6_TRANSB = 'N';
  dgemm32(&c6_TRANSA, &c6_TRANSB, &c6_m, &c6_n, &c6_k, &c6_alpha1, &c6_A[0],
          &c6_lda, &c6_B[0], &c6_ldb, &c6_beta1, &c6_C[0], &c6_ldc);
}

static void c6_e_eml_xgemm(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_A[30], real_T c6_B[900], real_T c6_C[30])
{
  int32_T c6_m;
  int32_T c6_n;
  int32_T c6_k;
  real_T c6_alpha1;
  int32_T c6_lda;
  int32_T c6_ldb;
  real_T c6_beta1;
  int32_T c6_ldc;
  char_T c6_TRANSA;
  char_T c6_TRANSB;
  c6_m = 1;
  c6_n = 30;
  c6_k = 30;
  c6_alpha1 = 1.0;
  c6_lda = 1;
  c6_ldb = 30;
  c6_beta1 = 0.0;
  c6_ldc = 1;
  c6_TRANSA = 'N';
  c6_TRANSB = 'N';
  dgemm32(&c6_TRANSA, &c6_TRANSB, &c6_m, &c6_n, &c6_k, &c6_alpha1, &c6_A[0],
          &c6_lda, &c6_B[0], &c6_ldb, &c6_beta1, &c6_C[0], &c6_ldc);
}

static void c6_f_eml_xgemm(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, real_T c6_A[900], real_T c6_B[30], real_T c6_C[30])
{
  int32_T c6_m;
  int32_T c6_n;
  int32_T c6_k;
  real_T c6_alpha1;
  int32_T c6_lda;
  int32_T c6_ldb;
  real_T c6_beta1;
  int32_T c6_ldc;
  char_T c6_TRANSA;
  char_T c6_TRANSB;
  c6_m = 30;
  c6_n = 1;
  c6_k = 30;
  c6_alpha1 = 1.0;
  c6_lda = 30;
  c6_ldb = 30;
  c6_beta1 = 0.0;
  c6_ldc = 30;
  c6_TRANSA = 'N';
  c6_TRANSB = 'N';
  dgemm32(&c6_TRANSA, &c6_TRANSB, &c6_m, &c6_n, &c6_k, &c6_alpha1, &c6_A[0],
          &c6_lda, &c6_B[0], &c6_ldb, &c6_beta1, &c6_C[0], &c6_ldc);
}

static void init_dsm_address_info(SFc6_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c6_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1801959365U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2352723507U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1822988212U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3426888372U);
}

mxArray *sf_c6_Hquad_control_LIB_MPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BOe6ixZwmLmYyMXy7s6TRG");
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(93);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(93);
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
      pr[0] = (double)(7);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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

static const mxArray *sf_get_sim_state_info_c6_Hquad_control_LIB_MPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[16],T\"J_star\",},{M[1],M[21],T\"V_init_out\",},{M[1],M[20],T\"u_buff_out\",},{M[1],M[5],T\"u_opt\",},{M[8],M[0],T\"is_active_c6_Hquad_control_LIB_MPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_Hquad_control_LIB_MPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
    chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Hquad_control_LIB_MPCMachineNumber_,
           6,
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
            1.0,0,0,(MexFcnForType)c6_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)c6_c_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 93;
          dimVector[1]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_h_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 30;
          dimVector[1]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)c6_c_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)
            c6_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 30;
          dimVector[1]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 93;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 7;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 30;
          _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          real_T *c6_u_opt;
          real_T *c6_J_star;
          real_T *c6_i_min;
          real_T *c6_L;
          real_T (*c6_TT_PP)[900];
          real_T (*c6_LL_PP)[90];
          real_T (*c6_LL_ref_PP)[2790];
          real_T (*c6_LL_U_ref_PP)[900];
          real_T (*c6_u_buff_out)[3];
          real_T (*c6_V_init_out)[30];
          real_T (*c6_MM)[9];
          real_T (*c6_PP)[900];
          real_T (*c6_AA_delay)[9];
          real_T (*c6_BB_delay)[9];
          real_T (*c6_x)[3];
          real_T (*c6_X_ref)[93];
          real_T (*c6_V_max)[30];
          real_T (*c6_betas)[7];
          real_T (*c6_u_buff)[3];
          real_T (*c6_V_init)[30];
          c6_V_init = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 15);
          c6_u_buff = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 14);
          c6_L = (real_T *)ssGetInputPortSignal(chartInstance->S, 13);
          c6_betas = (real_T (*)[7])ssGetInputPortSignal(chartInstance->S, 12);
          c6_i_min = (real_T *)ssGetInputPortSignal(chartInstance->S, 11);
          c6_V_max = (real_T (*)[30])ssGetInputPortSignal(chartInstance->S, 10);
          c6_X_ref = (real_T (*)[93])ssGetInputPortSignal(chartInstance->S, 9);
          c6_x = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 8);
          c6_BB_delay = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 7);
          c6_AA_delay = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 6);
          c6_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 5);
          c6_MM = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
          c6_V_init_out = (real_T (*)[30])ssGetOutputPortSignal(chartInstance->S,
            4);
          c6_u_buff_out = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            3);
          c6_J_star = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c6_LL_U_ref_PP = (real_T (*)[900])ssGetInputPortSignal
            (chartInstance->S, 3);
          c6_LL_ref_PP = (real_T (*)[2790])ssGetInputPortSignal(chartInstance->S,
            2);
          c6_LL_PP = (real_T (*)[90])ssGetInputPortSignal(chartInstance->S, 1);
          c6_u_opt = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c6_TT_PP = (real_T (*)[900])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c6_TT_PP);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_u_opt);
          _SFD_SET_DATA_VALUE_PTR(2U, *c6_LL_PP);
          _SFD_SET_DATA_VALUE_PTR(3U, *c6_LL_ref_PP);
          _SFD_SET_DATA_VALUE_PTR(4U, *c6_LL_U_ref_PP);
          _SFD_SET_DATA_VALUE_PTR(5U, c6_J_star);
          _SFD_SET_DATA_VALUE_PTR(6U, *c6_u_buff_out);
          _SFD_SET_DATA_VALUE_PTR(7U, *c6_V_init_out);
          _SFD_SET_DATA_VALUE_PTR(8U, *c6_MM);
          _SFD_SET_DATA_VALUE_PTR(9U, *c6_PP);
          _SFD_SET_DATA_VALUE_PTR(10U, *c6_AA_delay);
          _SFD_SET_DATA_VALUE_PTR(11U, *c6_BB_delay);
          _SFD_SET_DATA_VALUE_PTR(12U, *c6_x);
          _SFD_SET_DATA_VALUE_PTR(13U, *c6_X_ref);
          _SFD_SET_DATA_VALUE_PTR(14U, *c6_V_max);
          _SFD_SET_DATA_VALUE_PTR(15U, c6_i_min);
          _SFD_SET_DATA_VALUE_PTR(16U, *c6_betas);
          _SFD_SET_DATA_VALUE_PTR(17U, c6_L);
          _SFD_SET_DATA_VALUE_PTR(18U, *c6_u_buff);
          _SFD_SET_DATA_VALUE_PTR(19U, *c6_V_init);
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
      6, "dworkChecksum");
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

static void sf_opaque_initialize_c6_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc6_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc6_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_Hquad_control_LIB_MPC
    ((SFc6_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
  initialize_c6_Hquad_control_LIB_MPC((SFc6_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  enable_c6_Hquad_control_LIB_MPC((SFc6_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c6_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  disable_c6_Hquad_control_LIB_MPC((SFc6_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_c6_Hquad_control_LIB_MPC((SFc6_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c6_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  ext_mode_exec_c6_Hquad_control_LIB_MPC
    ((SFc6_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_Hquad_control_LIB_MPC
    ((SFc6_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_Hquad_control_LIB_MPC();/* state var info */
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

extern void sf_internal_set_sim_state_c6_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_Hquad_control_LIB_MPC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_Hquad_control_LIB_MPC
    ((SFc6_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_Hquad_control_LIB_MPC(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c6_Hquad_control_LIB_MPC(S);
}

static void sf_opaque_set_sim_state_c6_Hquad_control_LIB_MPC(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c6_Hquad_control_LIB_MPC(S, st);
}

static void sf_opaque_terminate_c6_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar)
      ->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_Hquad_control_LIB_MPC((SFc6_Hquad_control_LIB_MPCInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Hquad_control_LIB_MPC_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_Hquad_control_LIB_MPC
    ((SFc6_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_Hquad_control_LIB_MPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_Hquad_control_LIB_MPC
      ((SFc6_Hquad_control_LIB_MPCInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c6_Hquad_control_LIB_MPC_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c6_Hquad_control_LIB_MPC\",T\"is_active_c6_Hquad_control_LIB_MPC\"}}"
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

static void mdlSetWorkWidths_c6_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,6,
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
      sf_mark_chart_expressionable_inputs(S,infoStruct,6,16);
      sf_mark_chart_reusable_outputs(S,infoStruct,6,4);
    }

    sf_set_rtw_dwork_info(S,infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1632260904U));
  ssSetChecksum1(S,(3407228779U));
  ssSetChecksum2(S,(1697490121U));
  ssSetChecksum3(S,(2428932719U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_Hquad_control_LIB_MPC(SimStruct *S)
{
  SFc6_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc6_Hquad_control_LIB_MPCInstanceStruct *)malloc(sizeof
    (SFc6_Hquad_control_LIB_MPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_Hquad_control_LIB_MPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c6_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c6_Hquad_control_LIB_MPC;
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

void c6_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_Hquad_control_LIB_MPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_Hquad_control_LIB_MPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
