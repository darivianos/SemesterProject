/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c44_controller_template.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c44_debug_family_names[24] = { "U", "nargin", "nargout",
  "state_cur", "Uprev", "Mprev", "nx", "nu", "H", "K", "Hobj", "Fobj", "Gobj",
  "F", "G", "Nc", "Qopt", "Ropt", "Ml", "Mr", "U_x", "U_y", "flag_oob", "M" };

static const char * c44_b_debug_family_names[58] = { "nuRoptr", "nuRoptc",
  "nuUprevr", "nuUprevc", "nxQoptr", "nxQoptc", "nxHobjr", "nxHobjc", "unusedU0",
  "nxFobjr", "nxFobjc", "unusedU1", "nxGobjr", "nxGobjc", "unusedU2", "nmMprevr",
  "nmMprevc", "nm", "unusedU3", "unusedU4", "tolerance", "nr", "MPT_ABSTOL",
  "minreg", "Hsz", "Hi", "Ki", "UminJ", "minJ", "abspos", "sumViol", "isinside",
  "F", "G", "nc", "hx", "Jobj", "U", "nargin", "nargout", "X", "Uprev", "Mprev",
  "nx", "nu", "Hn", "Kn", "Hobj", "Fobj", "Gobj", "Fi", "Gi", "Nc", "Ropt", "Ml",
  "Mr", "flag_oob", "M" };

/* Function Declarations */
static void initialize_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance);
static void enable_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance);
static void disable_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance);
static void c44_update_debugger_state_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance, const mxArray *c44_st);
static void finalize_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance);
static void sf_c44_controller_template(SFc44_controller_templateInstanceStruct
  *chartInstance);
static void initSimStructsc44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c44_machineNumber, uint32_T
  c44_chartNumber);
static const mxArray *c44_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static real_T c44_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_M, const char_T *c44_identifier);
static real_T c44_b_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId);
static void c44_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_b_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_c_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_d_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_e_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_f_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_g_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_h_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_i_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_j_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_k_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_l_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_m_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_n_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_o_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static const mxArray *c44_p_sf_marshallOut(void *chartInstanceVoid, real_T
  c44_inData_data[2], int32_T c44_inData_sizes[1]);
static void c44_c_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y_data[2], int32_T c44_y_sizes[1]);
static void c44_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, real_T c44_outData_data[2],
  int32_T c44_outData_sizes[1]);
static void c44_d_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[10]);
static void c44_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static void c44_e_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[60]);
static void c44_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static void c44_f_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[4]);
static void c44_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_q_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static void c44_g_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[2303]);
static void c44_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static void c44_h_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[4606]);
static void c44_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static void c44_i_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[18424]);
static void c44_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static void c44_j_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[2303]);
static void c44_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static void c44_k_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[9212]);
static void c44_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static void c44_l_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[36848]);
static void c44_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_r_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static void c44_m_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[18999]);
static void c44_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static void c44_n_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[75996]);
static void c44_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static void c44_o_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[2]);
static void c44_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static void c44_p_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[4]);
static void c44_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_s_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static void c44_q_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[8]);
static void c44_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_t_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static void c44_r_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[100]);
static void c44_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static const mxArray *c44_u_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static void c44_s_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[400]);
static void c44_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static void c44_info_helper(c44_ResolvedFunctionInfo c44_info[20]);
static void c44_OptimalMPCInputExportC_vP
  (SFc44_controller_templateInstanceStruct *chartInstance, real_T c44_X[4],
   real_T c44_Uprev[2], real_T c44_Mprev, real_T c44_nx, real_T c44_nu, real_T
   c44_Hn[75996], real_T c44_Kn[18999], real_T c44_Hobj[36848], real_T c44_Fobj
   [9212], real_T c44_Gobj[2303], real_T c44_Fi[18424], real_T c44_Gi[4606],
   real_T c44_Nc[2303], real_T c44_Ropt[4], real_T c44_Ml[60], real_T c44_Mr[10],
   real_T c44_U_data[2], int32_T c44_U_sizes[1], real_T *c44_flag_oob, real_T
   *c44_M);
static void c44_error(SFc44_controller_templateInstanceStruct *chartInstance);
static void c44_b_error(SFc44_controller_templateInstanceStruct *chartInstance);
static boolean_T c44_all(SFc44_controller_templateInstanceStruct *chartInstance,
  boolean_T c44_x[5]);
static void c44_eml_xgemm(SFc44_controller_templateInstanceStruct *chartInstance,
  int32_T c44_k, real_T c44_A_data[2], int32_T c44_A_sizes[2], real_T c44_B[4],
  int32_T c44_ldb, real_T c44_C[2], real_T c44_b_C[2]);
static const mxArray *c44_v_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData);
static int32_T c44_t_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId);
static void c44_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData);
static uint8_T c44_u_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_is_active_c44_controller_template, const
  char_T *c44_identifier);
static uint8_T c44_v_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId);
static void c44_b_eml_xgemm(SFc44_controller_templateInstanceStruct
  *chartInstance, int32_T c44_k, real_T c44_A_data[2], int32_T c44_A_sizes[2],
  real_T c44_B[4], int32_T c44_ldb, real_T c44_C[2]);
static void init_dsm_address_info(SFc44_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c44_sfEvent;
  uint8_T *c44_is_active_c44_controller_template;
  c44_is_active_c44_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c44_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c44_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c44_is_active_c44_controller_template = 0U;
}

static void initialize_params_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c44_update_debugger_state_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance)
{
  c44_update_debugger_state_c44_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c44_st;
  const mxArray *c44_y = NULL;
  real_T c44_hoistedGlobal;
  real_T c44_u;
  const mxArray *c44_b_y = NULL;
  real_T c44_b_hoistedGlobal;
  real_T c44_b_u;
  const mxArray *c44_c_y = NULL;
  real_T c44_c_hoistedGlobal;
  real_T c44_c_u;
  const mxArray *c44_d_y = NULL;
  real_T c44_d_hoistedGlobal;
  real_T c44_d_u;
  const mxArray *c44_e_y = NULL;
  uint8_T c44_e_hoistedGlobal;
  uint8_T c44_e_u;
  const mxArray *c44_f_y = NULL;
  real_T *c44_M;
  real_T *c44_U_x;
  real_T *c44_U_y;
  real_T *c44_flag_oob;
  uint8_T *c44_is_active_c44_controller_template;
  c44_M = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c44_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c44_U_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c44_U_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c44_is_active_c44_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c44_st = NULL;
  c44_st = NULL;
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_createcellarray(5), FALSE);
  c44_hoistedGlobal = *c44_M;
  c44_u = c44_hoistedGlobal;
  c44_b_y = NULL;
  sf_mex_assign(&c44_b_y, sf_mex_create("y", &c44_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c44_y, 0, c44_b_y);
  c44_b_hoistedGlobal = *c44_U_x;
  c44_b_u = c44_b_hoistedGlobal;
  c44_c_y = NULL;
  sf_mex_assign(&c44_c_y, sf_mex_create("y", &c44_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c44_y, 1, c44_c_y);
  c44_c_hoistedGlobal = *c44_U_y;
  c44_c_u = c44_c_hoistedGlobal;
  c44_d_y = NULL;
  sf_mex_assign(&c44_d_y, sf_mex_create("y", &c44_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c44_y, 2, c44_d_y);
  c44_d_hoistedGlobal = *c44_flag_oob;
  c44_d_u = c44_d_hoistedGlobal;
  c44_e_y = NULL;
  sf_mex_assign(&c44_e_y, sf_mex_create("y", &c44_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c44_y, 3, c44_e_y);
  c44_e_hoistedGlobal = *c44_is_active_c44_controller_template;
  c44_e_u = c44_e_hoistedGlobal;
  c44_f_y = NULL;
  sf_mex_assign(&c44_f_y, sf_mex_create("y", &c44_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c44_y, 4, c44_f_y);
  sf_mex_assign(&c44_st, c44_y, FALSE);
  return c44_st;
}

static void set_sim_state_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance, const mxArray *c44_st)
{
  const mxArray *c44_u;
  boolean_T *c44_doneDoubleBufferReInit;
  real_T *c44_M;
  real_T *c44_U_x;
  real_T *c44_U_y;
  real_T *c44_flag_oob;
  uint8_T *c44_is_active_c44_controller_template;
  c44_M = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c44_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c44_U_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c44_U_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c44_is_active_c44_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c44_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c44_doneDoubleBufferReInit = TRUE;
  c44_u = sf_mex_dup(c44_st);
  *c44_M = c44_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c44_u,
    0)), "M");
  *c44_U_x = c44_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c44_u,
    1)), "U_x");
  *c44_U_y = c44_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c44_u,
    2)), "U_y");
  *c44_flag_oob = c44_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c44_u, 3)), "flag_oob");
  *c44_is_active_c44_controller_template = c44_u_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c44_u, 4)), "is_active_c44_controller_template");
  sf_mex_destroy(&c44_u);
  c44_update_debugger_state_c44_controller_template(chartInstance);
  sf_mex_destroy(&c44_st);
}

static void finalize_c44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c44_controller_template(SFc44_controller_templateInstanceStruct
  *chartInstance)
{
  int32_T c44_i0;
  int32_T c44_i1;
  int32_T c44_i2;
  int32_T c44_i3;
  int32_T c44_i4;
  int32_T c44_i5;
  int32_T c44_i6;
  int32_T c44_i7;
  int32_T c44_i8;
  int32_T c44_i9;
  int32_T c44_i10;
  int32_T c44_i11;
  int32_T c44_i12;
  int32_T c44_i13;
  real_T c44_hoistedGlobal;
  real_T c44_b_hoistedGlobal;
  real_T c44_c_hoistedGlobal;
  int32_T c44_i14;
  real_T c44_state_cur[4];
  int32_T c44_i15;
  real_T c44_Uprev[2];
  real_T c44_Mprev;
  real_T c44_nx;
  real_T c44_nu;
  int32_T c44_i16;
  static real_T c44_H[75996];
  int32_T c44_i17;
  static real_T c44_K[18999];
  int32_T c44_i18;
  static real_T c44_Hobj[36848];
  int32_T c44_i19;
  static real_T c44_Fobj[9212];
  int32_T c44_i20;
  real_T c44_Gobj[2303];
  int32_T c44_i21;
  static real_T c44_F[18424];
  int32_T c44_i22;
  real_T c44_G[4606];
  int32_T c44_i23;
  real_T c44_Nc[2303];
  int32_T c44_i24;
  real_T c44_Qopt[16];
  int32_T c44_i25;
  real_T c44_Ropt[4];
  int32_T c44_i26;
  real_T c44_Ml[60];
  int32_T c44_i27;
  real_T c44_Mr[10];
  uint32_T c44_debug_family_var_map[24];
  int32_T c44_U_sizes;
  real_T c44_U_data[2];
  real_T c44_nargin = 17.0;
  real_T c44_nargout = 4.0;
  real_T c44_U_x;
  real_T c44_U_y;
  real_T c44_flag_oob;
  real_T c44_M;
  int32_T c44_i28;
  real_T c44_b_state_cur[4];
  int32_T c44_i29;
  real_T c44_b_Uprev[2];
  int32_T c44_i30;
  static real_T c44_b_H[75996];
  int32_T c44_i31;
  static real_T c44_b_K[18999];
  int32_T c44_i32;
  static real_T c44_b_Hobj[36848];
  int32_T c44_i33;
  static real_T c44_b_Fobj[9212];
  int32_T c44_i34;
  real_T c44_b_Gobj[2303];
  int32_T c44_i35;
  static real_T c44_b_F[18424];
  int32_T c44_i36;
  real_T c44_b_G[4606];
  int32_T c44_i37;
  real_T c44_b_Nc[2303];
  int32_T c44_i38;
  real_T c44_b_Ropt[4];
  int32_T c44_i39;
  real_T c44_b_Ml[60];
  int32_T c44_i40;
  real_T c44_b_Mr[10];
  real_T c44_b_M;
  real_T c44_b_flag_oob;
  int32_T c44_b_U_sizes;
  real_T c44_b_U_data[2];
  int32_T c44_i41;
  int32_T *c44_sfEvent;
  real_T *c44_b_U_x;
  real_T *c44_b_Mprev;
  real_T *c44_b_nx;
  real_T *c44_b_nu;
  real_T *c44_b_U_y;
  real_T *c44_c_flag_oob;
  real_T *c44_c_M;
  real_T (*c44_c_Mr)[10];
  real_T (*c44_c_Ml)[60];
  real_T (*c44_c_Ropt)[4];
  real_T (*c44_b_Qopt)[16];
  real_T (*c44_c_Nc)[2303];
  real_T (*c44_c_G)[4606];
  real_T (*c44_c_F)[18424];
  real_T (*c44_c_Gobj)[2303];
  real_T (*c44_c_Fobj)[9212];
  real_T (*c44_c_Hobj)[36848];
  real_T (*c44_c_K)[18999];
  real_T (*c44_c_H)[75996];
  real_T (*c44_c_Uprev)[2];
  real_T (*c44_c_state_cur)[4];
  c44_c_M = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c44_c_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c44_b_U_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c44_c_Mr = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 16);
  c44_c_Ml = (real_T (*)[60])ssGetInputPortSignal(chartInstance->S, 15);
  c44_c_Ropt = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 14);
  c44_b_Qopt = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 13);
  c44_c_Nc = (real_T (*)[2303])ssGetInputPortSignal(chartInstance->S, 12);
  c44_c_G = (real_T (*)[4606])ssGetInputPortSignal(chartInstance->S, 11);
  c44_c_F = (real_T (*)[18424])ssGetInputPortSignal(chartInstance->S, 10);
  c44_c_Gobj = (real_T (*)[2303])ssGetInputPortSignal(chartInstance->S, 9);
  c44_c_Fobj = (real_T (*)[9212])ssGetInputPortSignal(chartInstance->S, 8);
  c44_c_Hobj = (real_T (*)[36848])ssGetInputPortSignal(chartInstance->S, 7);
  c44_c_K = (real_T (*)[18999])ssGetInputPortSignal(chartInstance->S, 6);
  c44_c_H = (real_T (*)[75996])ssGetInputPortSignal(chartInstance->S, 5);
  c44_b_nu = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c44_b_nx = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c44_b_Mprev = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c44_c_Uprev = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 1);
  c44_b_U_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c44_c_state_cur = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c44_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 27U, *c44_sfEvent);
  for (c44_i0 = 0; c44_i0 < 4; c44_i0++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_state_cur)[c44_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c44_b_U_x, 1U);
  for (c44_i1 = 0; c44_i1 < 2; c44_i1++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_Uprev)[c44_i1], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*c44_b_Mprev, 3U);
  _SFD_DATA_RANGE_CHECK(*c44_b_nx, 4U);
  _SFD_DATA_RANGE_CHECK(*c44_b_nu, 5U);
  for (c44_i2 = 0; c44_i2 < 75996; c44_i2++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_H)[c44_i2], 6U);
  }

  for (c44_i3 = 0; c44_i3 < 18999; c44_i3++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_K)[c44_i3], 7U);
  }

  for (c44_i4 = 0; c44_i4 < 36848; c44_i4++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_Hobj)[c44_i4], 8U);
  }

  for (c44_i5 = 0; c44_i5 < 9212; c44_i5++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_Fobj)[c44_i5], 9U);
  }

  for (c44_i6 = 0; c44_i6 < 2303; c44_i6++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_Gobj)[c44_i6], 10U);
  }

  for (c44_i7 = 0; c44_i7 < 18424; c44_i7++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_F)[c44_i7], 11U);
  }

  for (c44_i8 = 0; c44_i8 < 4606; c44_i8++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_G)[c44_i8], 12U);
  }

  for (c44_i9 = 0; c44_i9 < 2303; c44_i9++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_Nc)[c44_i9], 13U);
  }

  for (c44_i10 = 0; c44_i10 < 16; c44_i10++) {
    _SFD_DATA_RANGE_CHECK((*c44_b_Qopt)[c44_i10], 14U);
  }

  for (c44_i11 = 0; c44_i11 < 4; c44_i11++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_Ropt)[c44_i11], 15U);
  }

  for (c44_i12 = 0; c44_i12 < 60; c44_i12++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_Ml)[c44_i12], 16U);
  }

  for (c44_i13 = 0; c44_i13 < 10; c44_i13++) {
    _SFD_DATA_RANGE_CHECK((*c44_c_Mr)[c44_i13], 17U);
  }

  _SFD_DATA_RANGE_CHECK(*c44_b_U_y, 18U);
  _SFD_DATA_RANGE_CHECK(*c44_c_flag_oob, 19U);
  _SFD_DATA_RANGE_CHECK(*c44_c_M, 20U);
  *c44_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 27U, *c44_sfEvent);
  c44_hoistedGlobal = *c44_b_Mprev;
  c44_b_hoistedGlobal = *c44_b_nx;
  c44_c_hoistedGlobal = *c44_b_nu;
  for (c44_i14 = 0; c44_i14 < 4; c44_i14++) {
    c44_state_cur[c44_i14] = (*c44_c_state_cur)[c44_i14];
  }

  for (c44_i15 = 0; c44_i15 < 2; c44_i15++) {
    c44_Uprev[c44_i15] = (*c44_c_Uprev)[c44_i15];
  }

  c44_Mprev = c44_hoistedGlobal;
  c44_nx = c44_b_hoistedGlobal;
  c44_nu = c44_c_hoistedGlobal;
  for (c44_i16 = 0; c44_i16 < 75996; c44_i16++) {
    c44_H[c44_i16] = (*c44_c_H)[c44_i16];
  }

  for (c44_i17 = 0; c44_i17 < 18999; c44_i17++) {
    c44_K[c44_i17] = (*c44_c_K)[c44_i17];
  }

  for (c44_i18 = 0; c44_i18 < 36848; c44_i18++) {
    c44_Hobj[c44_i18] = (*c44_c_Hobj)[c44_i18];
  }

  for (c44_i19 = 0; c44_i19 < 9212; c44_i19++) {
    c44_Fobj[c44_i19] = (*c44_c_Fobj)[c44_i19];
  }

  for (c44_i20 = 0; c44_i20 < 2303; c44_i20++) {
    c44_Gobj[c44_i20] = (*c44_c_Gobj)[c44_i20];
  }

  for (c44_i21 = 0; c44_i21 < 18424; c44_i21++) {
    c44_F[c44_i21] = (*c44_c_F)[c44_i21];
  }

  for (c44_i22 = 0; c44_i22 < 4606; c44_i22++) {
    c44_G[c44_i22] = (*c44_c_G)[c44_i22];
  }

  for (c44_i23 = 0; c44_i23 < 2303; c44_i23++) {
    c44_Nc[c44_i23] = (*c44_c_Nc)[c44_i23];
  }

  for (c44_i24 = 0; c44_i24 < 16; c44_i24++) {
    c44_Qopt[c44_i24] = (*c44_b_Qopt)[c44_i24];
  }

  for (c44_i25 = 0; c44_i25 < 4; c44_i25++) {
    c44_Ropt[c44_i25] = (*c44_c_Ropt)[c44_i25];
  }

  for (c44_i26 = 0; c44_i26 < 60; c44_i26++) {
    c44_Ml[c44_i26] = (*c44_c_Ml)[c44_i26];
  }

  for (c44_i27 = 0; c44_i27 < 10; c44_i27++) {
    c44_Mr[c44_i27] = (*c44_c_Mr)[c44_i27];
  }

  sf_debug_symbol_scope_push_eml(0U, 24U, 24U, c44_debug_family_names,
    c44_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_dyn_importable(c44_U_data, (const int32_T *)
    &c44_U_sizes, NULL, 0, 0, (void *)c44_p_sf_marshallOut, (void *)
    c44_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_nargin, 1U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_nargout, 2U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c44_state_cur, 3U, c44_o_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_Uprev, 4U, c44_n_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c44_Mprev, 5U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c44_nx, 6U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c44_nu, 7U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_H, 8U, c44_m_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_K, 9U, c44_l_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_Hobj, 10U, c44_k_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_Fobj, 11U, c44_j_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_Gobj, 12U, c44_i_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_F, 13U, c44_h_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_G, 14U, c44_g_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_Nc, 15U, c44_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_Qopt, 16U, c44_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_Ropt, 17U, c44_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_Ml, 18U, c44_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c44_Mr, 19U, c44_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c44_U_x, 20U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_U_y, 21U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_flag_oob, 22U,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_M, 23U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c44_sfEvent, 4);
  for (c44_i28 = 0; c44_i28 < 4; c44_i28++) {
    c44_b_state_cur[c44_i28] = c44_state_cur[c44_i28];
  }

  for (c44_i29 = 0; c44_i29 < 2; c44_i29++) {
    c44_b_Uprev[c44_i29] = c44_Uprev[c44_i29];
  }

  for (c44_i30 = 0; c44_i30 < 75996; c44_i30++) {
    c44_b_H[c44_i30] = c44_H[c44_i30];
  }

  for (c44_i31 = 0; c44_i31 < 18999; c44_i31++) {
    c44_b_K[c44_i31] = c44_K[c44_i31];
  }

  for (c44_i32 = 0; c44_i32 < 36848; c44_i32++) {
    c44_b_Hobj[c44_i32] = c44_Hobj[c44_i32];
  }

  for (c44_i33 = 0; c44_i33 < 9212; c44_i33++) {
    c44_b_Fobj[c44_i33] = c44_Fobj[c44_i33];
  }

  for (c44_i34 = 0; c44_i34 < 2303; c44_i34++) {
    c44_b_Gobj[c44_i34] = c44_Gobj[c44_i34];
  }

  for (c44_i35 = 0; c44_i35 < 18424; c44_i35++) {
    c44_b_F[c44_i35] = c44_F[c44_i35];
  }

  for (c44_i36 = 0; c44_i36 < 4606; c44_i36++) {
    c44_b_G[c44_i36] = c44_G[c44_i36];
  }

  for (c44_i37 = 0; c44_i37 < 2303; c44_i37++) {
    c44_b_Nc[c44_i37] = c44_Nc[c44_i37];
  }

  for (c44_i38 = 0; c44_i38 < 4; c44_i38++) {
    c44_b_Ropt[c44_i38] = c44_Ropt[c44_i38];
  }

  for (c44_i39 = 0; c44_i39 < 60; c44_i39++) {
    c44_b_Ml[c44_i39] = c44_Ml[c44_i39];
  }

  for (c44_i40 = 0; c44_i40 < 10; c44_i40++) {
    c44_b_Mr[c44_i40] = c44_Mr[c44_i40];
  }

  c44_OptimalMPCInputExportC_vP(chartInstance, c44_b_state_cur, c44_b_Uprev,
    c44_Mprev, c44_nx, c44_nu, c44_b_H, c44_b_K, c44_b_Hobj, c44_b_Fobj,
    c44_b_Gobj, c44_b_F, c44_b_G, c44_b_Nc, c44_b_Ropt, c44_b_Ml, c44_b_Mr,
    c44_b_U_data, *(int32_T (*)[1])&c44_b_U_sizes, &c44_b_flag_oob, &c44_b_M);
  c44_U_sizes = 2;
  for (c44_i41 = 0; c44_i41 < 2; c44_i41++) {
    c44_U_data[c44_i41] = c44_b_U_data[c44_i41];
  }

  c44_flag_oob = c44_b_flag_oob;
  c44_M = c44_b_M;
  _SFD_EML_CALL(0U, *c44_sfEvent, 6);
  c44_U_x = c44_U_data[0];
  _SFD_EML_CALL(0U, *c44_sfEvent, 7);
  c44_U_y = c44_U_data[1];
  _SFD_EML_CALL(0U, *c44_sfEvent, -7);
  sf_debug_symbol_scope_pop();
  *c44_b_U_x = c44_U_x;
  *c44_b_U_y = c44_U_y;
  *c44_c_flag_oob = c44_flag_oob;
  *c44_c_M = c44_M;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, *c44_sfEvent);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc44_controller_template
  (SFc44_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c44_machineNumber, uint32_T
  c44_chartNumber)
{
  _SFD_SCRIPT_TRANSLATION(c44_chartNumber, 0U, sf_debug_get_script_id(
    "/home/burrimi/git/darivianakis/SemProject/OptimalMPCInputExportC_vP.m"));
}

static const mxArray *c44_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  real_T c44_u;
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_u = *(real_T *)c44_inData;
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", &c44_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static real_T c44_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_M, const char_T *c44_identifier)
{
  real_T c44_y;
  emlrtMsgIdentifier c44_thisId;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_M), &c44_thisId);
  sf_mex_destroy(&c44_M);
  return c44_y;
}

static real_T c44_b_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId)
{
  real_T c44_y;
  real_T c44_d0;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), &c44_d0, 1, 0, 0U, 0, 0U, 0);
  c44_y = c44_d0;
  sf_mex_destroy(&c44_u);
  return c44_y;
}

static void c44_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_M;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_M = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_M), &c44_thisId);
  sf_mex_destroy(&c44_M);
  *(real_T *)c44_outData = c44_y;
  sf_mex_destroy(&c44_mxArrayInData);
}

static const mxArray *c44_b_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i42;
  int32_T c44_i43;
  int32_T c44_i44;
  real_T c44_b_inData[10];
  int32_T c44_i45;
  int32_T c44_i46;
  int32_T c44_i47;
  real_T c44_u[10];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_i42 = 0;
  for (c44_i43 = 0; c44_i43 < 2; c44_i43++) {
    for (c44_i44 = 0; c44_i44 < 5; c44_i44++) {
      c44_b_inData[c44_i44 + c44_i42] = (*(real_T (*)[10])c44_inData)[c44_i44 +
        c44_i42];
    }

    c44_i42 += 5;
  }

  c44_i45 = 0;
  for (c44_i46 = 0; c44_i46 < 2; c44_i46++) {
    for (c44_i47 = 0; c44_i47 < 5; c44_i47++) {
      c44_u[c44_i47 + c44_i45] = c44_b_inData[c44_i47 + c44_i45];
    }

    c44_i45 += 5;
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 3, 5, 1, 2),
                FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_c_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i48;
  int32_T c44_i49;
  int32_T c44_i50;
  int32_T c44_i51;
  int32_T c44_i52;
  real_T c44_b_inData[60];
  int32_T c44_i53;
  int32_T c44_i54;
  int32_T c44_i55;
  int32_T c44_i56;
  int32_T c44_i57;
  real_T c44_u[60];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_i48 = 0;
  for (c44_i49 = 0; c44_i49 < 2; c44_i49++) {
    c44_i50 = 0;
    for (c44_i51 = 0; c44_i51 < 6; c44_i51++) {
      for (c44_i52 = 0; c44_i52 < 5; c44_i52++) {
        c44_b_inData[(c44_i52 + c44_i50) + c44_i48] = (*(real_T (*)[60])
          c44_inData)[(c44_i52 + c44_i50) + c44_i48];
      }

      c44_i50 += 5;
    }

    c44_i48 += 30;
  }

  c44_i53 = 0;
  for (c44_i54 = 0; c44_i54 < 2; c44_i54++) {
    c44_i55 = 0;
    for (c44_i56 = 0; c44_i56 < 6; c44_i56++) {
      for (c44_i57 = 0; c44_i57 < 5; c44_i57++) {
        c44_u[(c44_i57 + c44_i55) + c44_i53] = c44_b_inData[(c44_i57 + c44_i55)
          + c44_i53];
      }

      c44_i55 += 5;
    }

    c44_i53 += 30;
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 3, 5, 6, 2),
                FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_d_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i58;
  int32_T c44_i59;
  int32_T c44_i60;
  real_T c44_b_inData[4];
  int32_T c44_i61;
  int32_T c44_i62;
  int32_T c44_i63;
  real_T c44_u[4];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_i58 = 0;
  for (c44_i59 = 0; c44_i59 < 2; c44_i59++) {
    for (c44_i60 = 0; c44_i60 < 2; c44_i60++) {
      c44_b_inData[c44_i60 + c44_i58] = (*(real_T (*)[4])c44_inData)[c44_i60 +
        c44_i58];
    }

    c44_i58 += 2;
  }

  c44_i61 = 0;
  for (c44_i62 = 0; c44_i62 < 2; c44_i62++) {
    for (c44_i63 = 0; c44_i63 < 2; c44_i63++) {
      c44_u[c44_i63 + c44_i61] = c44_b_inData[c44_i63 + c44_i61];
    }

    c44_i61 += 2;
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_e_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i64;
  int32_T c44_i65;
  int32_T c44_i66;
  real_T c44_b_inData[16];
  int32_T c44_i67;
  int32_T c44_i68;
  int32_T c44_i69;
  real_T c44_u[16];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_i64 = 0;
  for (c44_i65 = 0; c44_i65 < 4; c44_i65++) {
    for (c44_i66 = 0; c44_i66 < 4; c44_i66++) {
      c44_b_inData[c44_i66 + c44_i64] = (*(real_T (*)[16])c44_inData)[c44_i66 +
        c44_i64];
    }

    c44_i64 += 4;
  }

  c44_i67 = 0;
  for (c44_i68 = 0; c44_i68 < 4; c44_i68++) {
    for (c44_i69 = 0; c44_i69 < 4; c44_i69++) {
      c44_u[c44_i69 + c44_i67] = c44_b_inData[c44_i69 + c44_i67];
    }

    c44_i67 += 4;
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_f_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i70;
  real_T c44_b_inData[2303];
  int32_T c44_i71;
  real_T c44_u[2303];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  for (c44_i70 = 0; c44_i70 < 2303; c44_i70++) {
    c44_b_inData[c44_i70] = (*(real_T (*)[2303])c44_inData)[c44_i70];
  }

  for (c44_i71 = 0; c44_i71 < 2303; c44_i71++) {
    c44_u[c44_i71] = c44_b_inData[c44_i71];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 2, 2303, 1),
                FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_g_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i72;
  int32_T c44_i73;
  int32_T c44_i74;
  real_T c44_b_inData[4606];
  int32_T c44_i75;
  int32_T c44_i76;
  int32_T c44_i77;
  real_T c44_u[4606];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_i72 = 0;
  for (c44_i73 = 0; c44_i73 < 2303; c44_i73++) {
    for (c44_i74 = 0; c44_i74 < 2; c44_i74++) {
      c44_b_inData[c44_i74 + c44_i72] = (*(real_T (*)[4606])c44_inData)[c44_i74
        + c44_i72];
    }

    c44_i72 += 2;
  }

  c44_i75 = 0;
  for (c44_i76 = 0; c44_i76 < 2303; c44_i76++) {
    for (c44_i77 = 0; c44_i77 < 2; c44_i77++) {
      c44_u[c44_i77 + c44_i75] = c44_b_inData[c44_i77 + c44_i75];
    }

    c44_i75 += 2;
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 3, 2, 1, 2303),
                FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_h_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i78;
  int32_T c44_i79;
  int32_T c44_i80;
  int32_T c44_i81;
  int32_T c44_i82;
  static real_T c44_b_inData[18424];
  int32_T c44_i83;
  int32_T c44_i84;
  int32_T c44_i85;
  int32_T c44_i86;
  int32_T c44_i87;
  real_T c44_u[18424];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_i78 = 0;
  for (c44_i79 = 0; c44_i79 < 2303; c44_i79++) {
    c44_i80 = 0;
    for (c44_i81 = 0; c44_i81 < 4; c44_i81++) {
      for (c44_i82 = 0; c44_i82 < 2; c44_i82++) {
        c44_b_inData[(c44_i82 + c44_i80) + c44_i78] = (*(real_T (*)[18424])
          c44_inData)[(c44_i82 + c44_i80) + c44_i78];
      }

      c44_i80 += 2;
    }

    c44_i78 += 8;
  }

  c44_i83 = 0;
  for (c44_i84 = 0; c44_i84 < 2303; c44_i84++) {
    c44_i85 = 0;
    for (c44_i86 = 0; c44_i86 < 4; c44_i86++) {
      for (c44_i87 = 0; c44_i87 < 2; c44_i87++) {
        c44_u[(c44_i87 + c44_i85) + c44_i83] = c44_b_inData[(c44_i87 + c44_i85)
          + c44_i83];
      }

      c44_i85 += 2;
    }

    c44_i83 += 8;
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 3, 2, 4, 2303),
                FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_i_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i88;
  real_T c44_b_inData[2303];
  int32_T c44_i89;
  real_T c44_u[2303];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  for (c44_i88 = 0; c44_i88 < 2303; c44_i88++) {
    c44_b_inData[c44_i88] = (*(real_T (*)[2303])c44_inData)[c44_i88];
  }

  for (c44_i89 = 0; c44_i89 < 2303; c44_i89++) {
    c44_u[c44_i89] = c44_b_inData[c44_i89];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 3, 1, 1, 2303),
                FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_j_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i90;
  int32_T c44_i91;
  int32_T c44_i92;
  real_T c44_b_inData[9212];
  int32_T c44_i93;
  int32_T c44_i94;
  int32_T c44_i95;
  real_T c44_u[9212];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_i90 = 0;
  for (c44_i91 = 0; c44_i91 < 2303; c44_i91++) {
    for (c44_i92 = 0; c44_i92 < 4; c44_i92++) {
      c44_b_inData[c44_i92 + c44_i90] = (*(real_T (*)[9212])c44_inData)[c44_i92
        + c44_i90];
    }

    c44_i90 += 4;
  }

  c44_i93 = 0;
  for (c44_i94 = 0; c44_i94 < 2303; c44_i94++) {
    for (c44_i95 = 0; c44_i95 < 4; c44_i95++) {
      c44_u[c44_i95 + c44_i93] = c44_b_inData[c44_i95 + c44_i93];
    }

    c44_i93 += 4;
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 3, 1, 4, 2303),
                FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_k_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i96;
  int32_T c44_i97;
  int32_T c44_i98;
  int32_T c44_i99;
  int32_T c44_i100;
  static real_T c44_b_inData[36848];
  int32_T c44_i101;
  int32_T c44_i102;
  int32_T c44_i103;
  int32_T c44_i104;
  int32_T c44_i105;
  static real_T c44_u[36848];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_i96 = 0;
  for (c44_i97 = 0; c44_i97 < 2303; c44_i97++) {
    c44_i98 = 0;
    for (c44_i99 = 0; c44_i99 < 4; c44_i99++) {
      for (c44_i100 = 0; c44_i100 < 4; c44_i100++) {
        c44_b_inData[(c44_i100 + c44_i98) + c44_i96] = (*(real_T (*)[36848])
          c44_inData)[(c44_i100 + c44_i98) + c44_i96];
      }

      c44_i98 += 4;
    }

    c44_i96 += 16;
  }

  c44_i101 = 0;
  for (c44_i102 = 0; c44_i102 < 2303; c44_i102++) {
    c44_i103 = 0;
    for (c44_i104 = 0; c44_i104 < 4; c44_i104++) {
      for (c44_i105 = 0; c44_i105 < 4; c44_i105++) {
        c44_u[(c44_i105 + c44_i103) + c44_i101] = c44_b_inData[(c44_i105 +
          c44_i103) + c44_i101];
      }

      c44_i103 += 4;
    }

    c44_i101 += 16;
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 3, 4, 4, 2303),
                FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_l_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i106;
  static real_T c44_b_inData[18999];
  int32_T c44_i107;
  real_T c44_u[18999];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  for (c44_i106 = 0; c44_i106 < 18999; c44_i106++) {
    c44_b_inData[c44_i106] = (*(real_T (*)[18999])c44_inData)[c44_i106];
  }

  for (c44_i107 = 0; c44_i107 < 18999; c44_i107++) {
    c44_u[c44_i107] = c44_b_inData[c44_i107];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 2, 18999, 1),
                FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_m_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i108;
  int32_T c44_i109;
  int32_T c44_i110;
  static real_T c44_b_inData[75996];
  int32_T c44_i111;
  int32_T c44_i112;
  int32_T c44_i113;
  static real_T c44_u[75996];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_i108 = 0;
  for (c44_i109 = 0; c44_i109 < 4; c44_i109++) {
    for (c44_i110 = 0; c44_i110 < 18999; c44_i110++) {
      c44_b_inData[c44_i110 + c44_i108] = (*(real_T (*)[75996])c44_inData)
        [c44_i110 + c44_i108];
    }

    c44_i108 += 18999;
  }

  c44_i111 = 0;
  for (c44_i112 = 0; c44_i112 < 4; c44_i112++) {
    for (c44_i113 = 0; c44_i113 < 18999; c44_i113++) {
      c44_u[c44_i113 + c44_i111] = c44_b_inData[c44_i113 + c44_i111];
    }

    c44_i111 += 18999;
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 2, 18999, 4),
                FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_n_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i114;
  real_T c44_b_inData[2];
  int32_T c44_i115;
  real_T c44_u[2];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  for (c44_i114 = 0; c44_i114 < 2; c44_i114++) {
    c44_b_inData[c44_i114] = (*(real_T (*)[2])c44_inData)[c44_i114];
  }

  for (c44_i115 = 0; c44_i115 < 2; c44_i115++) {
    c44_u[c44_i115] = c44_b_inData[c44_i115];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_o_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i116;
  real_T c44_b_inData[4];
  int32_T c44_i117;
  real_T c44_u[4];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  for (c44_i116 = 0; c44_i116 < 4; c44_i116++) {
    c44_b_inData[c44_i116] = (*(real_T (*)[4])c44_inData)[c44_i116];
  }

  for (c44_i117 = 0; c44_i117 < 4; c44_i117++) {
    c44_u[c44_i117] = c44_b_inData[c44_i117];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static const mxArray *c44_p_sf_marshallOut(void *chartInstanceVoid, real_T
  c44_inData_data[2], int32_T c44_inData_sizes[1])
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_b_inData_sizes;
  int32_T c44_i118;
  real_T c44_b_inData_data[2];
  int32_T c44_u_sizes;
  int32_T c44_i119;
  real_T c44_u_data[2];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_b_inData_sizes = 2;
  for (c44_i118 = 0; c44_i118 < 2; c44_i118++) {
    c44_b_inData_data[c44_i118] = c44_inData_data[c44_i118];
  }

  c44_u_sizes = 2;
  for (c44_i119 = 0; c44_i119 < 2; c44_i119++) {
    c44_u_data[c44_i119] = c44_b_inData_data[c44_i119];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u_data, 0, 0U, 1U, 0U, 1,
    c44_u_sizes), FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static void c44_c_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y_data[2], int32_T c44_y_sizes[1])
{
  static uint32_T c44_uv0[1] = { 2U };

  uint32_T c44_uv1[1];
  static boolean_T c44_bv0[1] = { FALSE };

  boolean_T c44_bv1[1];
  int32_T c44_tmp_sizes;
  real_T c44_tmp_data[2];
  int32_T c44_i120;
  c44_uv1[0] = c44_uv0[0];
  c44_bv1[0] = c44_bv0[0];
  sf_mex_import_vs(c44_parentId, sf_mex_dup(c44_u), c44_tmp_data, 1, 0, 0U, 1,
                   0U, 1, c44_bv1, c44_uv1, &c44_tmp_sizes);
  c44_y_sizes[0] = 2;
  for (c44_i120 = 0; c44_i120 < 2; c44_i120++) {
    c44_y_data[c44_i120] = c44_tmp_data[c44_i120];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, real_T c44_outData_data[2],
  int32_T c44_outData_sizes[1])
{
  const mxArray *c44_U;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  int32_T c44_y_sizes;
  real_T c44_y_data[2];
  int32_T c44_i121;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_U = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_U), &c44_thisId,
    c44_y_data, *(int32_T (*)[1])&c44_y_sizes);
  sf_mex_destroy(&c44_U);
  c44_outData_sizes[0] = 2;
  for (c44_i121 = 0; c44_i121 < 2; c44_i121++) {
    c44_outData_data[c44_i121] = c44_y_data[c44_i121];
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static void c44_d_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[10])
{
  real_T c44_dv0[10];
  int32_T c44_i122;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv0, 1, 0, 0U, 1, 0U, 3, 5,
                1, 2);
  for (c44_i122 = 0; c44_i122 < 10; c44_i122++) {
    c44_y[c44_i122] = c44_dv0[c44_i122];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Mr;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[10];
  int32_T c44_i123;
  int32_T c44_i124;
  int32_T c44_i125;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Mr = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Mr), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Mr);
  c44_i123 = 0;
  for (c44_i124 = 0; c44_i124 < 2; c44_i124++) {
    for (c44_i125 = 0; c44_i125 < 5; c44_i125++) {
      (*(real_T (*)[10])c44_outData)[c44_i125 + c44_i123] = c44_y[c44_i125 +
        c44_i123];
    }

    c44_i123 += 5;
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static void c44_e_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[60])
{
  real_T c44_dv1[60];
  int32_T c44_i126;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv1, 1, 0, 0U, 1, 0U, 3, 5,
                6, 2);
  for (c44_i126 = 0; c44_i126 < 60; c44_i126++) {
    c44_y[c44_i126] = c44_dv1[c44_i126];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Ml;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[60];
  int32_T c44_i127;
  int32_T c44_i128;
  int32_T c44_i129;
  int32_T c44_i130;
  int32_T c44_i131;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Ml = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Ml), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Ml);
  c44_i127 = 0;
  for (c44_i128 = 0; c44_i128 < 2; c44_i128++) {
    c44_i129 = 0;
    for (c44_i130 = 0; c44_i130 < 6; c44_i130++) {
      for (c44_i131 = 0; c44_i131 < 5; c44_i131++) {
        (*(real_T (*)[60])c44_outData)[(c44_i131 + c44_i129) + c44_i127] =
          c44_y[(c44_i131 + c44_i129) + c44_i127];
      }

      c44_i129 += 5;
    }

    c44_i127 += 30;
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static void c44_f_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[4])
{
  real_T c44_dv2[4];
  int32_T c44_i132;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv2, 1, 0, 0U, 1, 0U, 2, 2,
                2);
  for (c44_i132 = 0; c44_i132 < 4; c44_i132++) {
    c44_y[c44_i132] = c44_dv2[c44_i132];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Ropt;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[4];
  int32_T c44_i133;
  int32_T c44_i134;
  int32_T c44_i135;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Ropt = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Ropt), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Ropt);
  c44_i133 = 0;
  for (c44_i134 = 0; c44_i134 < 2; c44_i134++) {
    for (c44_i135 = 0; c44_i135 < 2; c44_i135++) {
      (*(real_T (*)[4])c44_outData)[c44_i135 + c44_i133] = c44_y[c44_i135 +
        c44_i133];
    }

    c44_i133 += 2;
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static const mxArray *c44_q_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i136;
  real_T c44_b_inData[2303];
  int32_T c44_i137;
  real_T c44_u[2303];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  for (c44_i136 = 0; c44_i136 < 2303; c44_i136++) {
    c44_b_inData[c44_i136] = (*(real_T (*)[2303])c44_inData)[c44_i136];
  }

  for (c44_i137 = 0; c44_i137 < 2303; c44_i137++) {
    c44_u[c44_i137] = c44_b_inData[c44_i137];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 1, 2303), FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static void c44_g_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[2303])
{
  real_T c44_dv3[2303];
  int32_T c44_i138;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv3, 1, 0, 0U, 1, 0U, 1,
                2303);
  for (c44_i138 = 0; c44_i138 < 2303; c44_i138++) {
    c44_y[c44_i138] = c44_dv3[c44_i138];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Nc;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[2303];
  int32_T c44_i139;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Nc = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Nc), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Nc);
  for (c44_i139 = 0; c44_i139 < 2303; c44_i139++) {
    (*(real_T (*)[2303])c44_outData)[c44_i139] = c44_y[c44_i139];
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static void c44_h_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[4606])
{
  real_T c44_dv4[4606];
  int32_T c44_i140;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv4, 1, 0, 0U, 1, 0U, 3, 2,
                1, 2303);
  for (c44_i140 = 0; c44_i140 < 4606; c44_i140++) {
    c44_y[c44_i140] = c44_dv4[c44_i140];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Gi;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[4606];
  int32_T c44_i141;
  int32_T c44_i142;
  int32_T c44_i143;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Gi = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Gi), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Gi);
  c44_i141 = 0;
  for (c44_i142 = 0; c44_i142 < 2303; c44_i142++) {
    for (c44_i143 = 0; c44_i143 < 2; c44_i143++) {
      (*(real_T (*)[4606])c44_outData)[c44_i143 + c44_i141] = c44_y[c44_i143 +
        c44_i141];
    }

    c44_i141 += 2;
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static void c44_i_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[18424])
{
  real_T c44_dv5[18424];
  int32_T c44_i144;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv5, 1, 0, 0U, 1, 0U, 3, 2,
                4, 2303);
  for (c44_i144 = 0; c44_i144 < 18424; c44_i144++) {
    c44_y[c44_i144] = c44_dv5[c44_i144];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Fi;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  static real_T c44_y[18424];
  int32_T c44_i145;
  int32_T c44_i146;
  int32_T c44_i147;
  int32_T c44_i148;
  int32_T c44_i149;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Fi = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Fi), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Fi);
  c44_i145 = 0;
  for (c44_i146 = 0; c44_i146 < 2303; c44_i146++) {
    c44_i147 = 0;
    for (c44_i148 = 0; c44_i148 < 4; c44_i148++) {
      for (c44_i149 = 0; c44_i149 < 2; c44_i149++) {
        (*(real_T (*)[18424])c44_outData)[(c44_i149 + c44_i147) + c44_i145] =
          c44_y[(c44_i149 + c44_i147) + c44_i145];
      }

      c44_i147 += 2;
    }

    c44_i145 += 8;
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static void c44_j_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[2303])
{
  real_T c44_dv6[2303];
  int32_T c44_i150;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv6, 1, 0, 0U, 1, 0U, 3, 1,
                1, 2303);
  for (c44_i150 = 0; c44_i150 < 2303; c44_i150++) {
    c44_y[c44_i150] = c44_dv6[c44_i150];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Gobj;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[2303];
  int32_T c44_i151;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Gobj = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Gobj), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Gobj);
  for (c44_i151 = 0; c44_i151 < 2303; c44_i151++) {
    (*(real_T (*)[2303])c44_outData)[c44_i151] = c44_y[c44_i151];
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static void c44_k_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[9212])
{
  real_T c44_dv7[9212];
  int32_T c44_i152;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv7, 1, 0, 0U, 1, 0U, 3, 1,
                4, 2303);
  for (c44_i152 = 0; c44_i152 < 9212; c44_i152++) {
    c44_y[c44_i152] = c44_dv7[c44_i152];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Fobj;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[9212];
  int32_T c44_i153;
  int32_T c44_i154;
  int32_T c44_i155;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Fobj = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Fobj), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Fobj);
  c44_i153 = 0;
  for (c44_i154 = 0; c44_i154 < 2303; c44_i154++) {
    for (c44_i155 = 0; c44_i155 < 4; c44_i155++) {
      (*(real_T (*)[9212])c44_outData)[c44_i155 + c44_i153] = c44_y[c44_i155 +
        c44_i153];
    }

    c44_i153 += 4;
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static void c44_l_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[36848])
{
  static real_T c44_dv8[36848];
  int32_T c44_i156;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv8, 1, 0, 0U, 1, 0U, 3, 4,
                4, 2303);
  for (c44_i156 = 0; c44_i156 < 36848; c44_i156++) {
    c44_y[c44_i156] = c44_dv8[c44_i156];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Hobj;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  static real_T c44_y[36848];
  int32_T c44_i157;
  int32_T c44_i158;
  int32_T c44_i159;
  int32_T c44_i160;
  int32_T c44_i161;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Hobj = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Hobj), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Hobj);
  c44_i157 = 0;
  for (c44_i158 = 0; c44_i158 < 2303; c44_i158++) {
    c44_i159 = 0;
    for (c44_i160 = 0; c44_i160 < 4; c44_i160++) {
      for (c44_i161 = 0; c44_i161 < 4; c44_i161++) {
        (*(real_T (*)[36848])c44_outData)[(c44_i161 + c44_i159) + c44_i157] =
          c44_y[(c44_i161 + c44_i159) + c44_i157];
      }

      c44_i159 += 4;
    }

    c44_i157 += 16;
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static const mxArray *c44_r_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i162;
  static real_T c44_b_inData[18999];
  int32_T c44_i163;
  real_T c44_u[18999];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  for (c44_i162 = 0; c44_i162 < 18999; c44_i162++) {
    c44_b_inData[c44_i162] = (*(real_T (*)[18999])c44_inData)[c44_i162];
  }

  for (c44_i163 = 0; c44_i163 < 18999; c44_i163++) {
    c44_u[c44_i163] = c44_b_inData[c44_i163];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 1, 18999),
                FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static void c44_m_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[18999])
{
  real_T c44_dv9[18999];
  int32_T c44_i164;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv9, 1, 0, 0U, 1, 0U, 1,
                18999);
  for (c44_i164 = 0; c44_i164 < 18999; c44_i164++) {
    c44_y[c44_i164] = c44_dv9[c44_i164];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Kn;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  static real_T c44_y[18999];
  int32_T c44_i165;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Kn = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Kn), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Kn);
  for (c44_i165 = 0; c44_i165 < 18999; c44_i165++) {
    (*(real_T (*)[18999])c44_outData)[c44_i165] = c44_y[c44_i165];
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static void c44_n_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[75996])
{
  static real_T c44_dv10[75996];
  int32_T c44_i166;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv10, 1, 0, 0U, 1, 0U, 2,
                18999, 4);
  for (c44_i166 = 0; c44_i166 < 75996; c44_i166++) {
    c44_y[c44_i166] = c44_dv10[c44_i166];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Hn;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  static real_T c44_y[75996];
  int32_T c44_i167;
  int32_T c44_i168;
  int32_T c44_i169;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Hn = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Hn), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Hn);
  c44_i167 = 0;
  for (c44_i168 = 0; c44_i168 < 4; c44_i168++) {
    for (c44_i169 = 0; c44_i169 < 18999; c44_i169++) {
      (*(real_T (*)[75996])c44_outData)[c44_i169 + c44_i167] = c44_y[c44_i169 +
        c44_i167];
    }

    c44_i167 += 18999;
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static void c44_o_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[2])
{
  real_T c44_dv11[2];
  int32_T c44_i170;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv11, 1, 0, 0U, 1, 0U, 1, 2);
  for (c44_i170 = 0; c44_i170 < 2; c44_i170++) {
    c44_y[c44_i170] = c44_dv11[c44_i170];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Uprev;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[2];
  int32_T c44_i171;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Uprev = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Uprev), &c44_thisId,
    c44_y);
  sf_mex_destroy(&c44_Uprev);
  for (c44_i171 = 0; c44_i171 < 2; c44_i171++) {
    (*(real_T (*)[2])c44_outData)[c44_i171] = c44_y[c44_i171];
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static void c44_p_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[4])
{
  real_T c44_dv12[4];
  int32_T c44_i172;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv12, 1, 0, 0U, 1, 0U, 1, 4);
  for (c44_i172 = 0; c44_i172 < 4; c44_i172++) {
    c44_y[c44_i172] = c44_dv12[c44_i172];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_X;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[4];
  int32_T c44_i173;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_X = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_X), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_X);
  for (c44_i173 = 0; c44_i173 < 4; c44_i173++) {
    (*(real_T (*)[4])c44_outData)[c44_i173] = c44_y[c44_i173];
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static const mxArray *c44_s_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i174;
  int32_T c44_i175;
  int32_T c44_i176;
  real_T c44_b_inData[8];
  int32_T c44_i177;
  int32_T c44_i178;
  int32_T c44_i179;
  real_T c44_u[8];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_i174 = 0;
  for (c44_i175 = 0; c44_i175 < 4; c44_i175++) {
    for (c44_i176 = 0; c44_i176 < 2; c44_i176++) {
      c44_b_inData[c44_i176 + c44_i174] = (*(real_T (*)[8])c44_inData)[c44_i176
        + c44_i174];
    }

    c44_i174 += 2;
  }

  c44_i177 = 0;
  for (c44_i178 = 0; c44_i178 < 4; c44_i178++) {
    for (c44_i179 = 0; c44_i179 < 2; c44_i179++) {
      c44_u[c44_i179 + c44_i177] = c44_b_inData[c44_i179 + c44_i177];
    }

    c44_i177 += 2;
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 2, 2, 4), FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static void c44_q_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[8])
{
  real_T c44_dv13[8];
  int32_T c44_i180;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv13, 1, 0, 0U, 1, 0U, 2, 2,
                4);
  for (c44_i180 = 0; c44_i180 < 8; c44_i180++) {
    c44_y[c44_i180] = c44_dv13[c44_i180];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_F;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[8];
  int32_T c44_i181;
  int32_T c44_i182;
  int32_T c44_i183;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_F = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_F), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_F);
  c44_i181 = 0;
  for (c44_i182 = 0; c44_i182 < 4; c44_i182++) {
    for (c44_i183 = 0; c44_i183 < 2; c44_i183++) {
      (*(real_T (*)[8])c44_outData)[c44_i183 + c44_i181] = c44_y[c44_i183 +
        c44_i181];
    }

    c44_i181 += 2;
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static const mxArray *c44_t_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i184;
  real_T c44_b_inData[100];
  int32_T c44_i185;
  real_T c44_u[100];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  for (c44_i184 = 0; c44_i184 < 100; c44_i184++) {
    c44_b_inData[c44_i184] = (*(real_T (*)[100])c44_inData)[c44_i184];
  }

  for (c44_i185 = 0; c44_i185 < 100; c44_i185++) {
    c44_u[c44_i185] = c44_b_inData[c44_i185];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 1, 100), FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static void c44_r_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[100])
{
  real_T c44_dv14[100];
  int32_T c44_i186;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv14, 1, 0, 0U, 1, 0U, 1,
                100);
  for (c44_i186 = 0; c44_i186 < 100; c44_i186++) {
    c44_y[c44_i186] = c44_dv14[c44_i186];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Ki;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[100];
  int32_T c44_i187;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Ki = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Ki), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Ki);
  for (c44_i187 = 0; c44_i187 < 100; c44_i187++) {
    (*(real_T (*)[100])c44_outData)[c44_i187] = c44_y[c44_i187];
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

static const mxArray *c44_u_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_i188;
  int32_T c44_i189;
  int32_T c44_i190;
  real_T c44_b_inData[400];
  int32_T c44_i191;
  int32_T c44_i192;
  int32_T c44_i193;
  real_T c44_u[400];
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_i188 = 0;
  for (c44_i189 = 0; c44_i189 < 4; c44_i189++) {
    for (c44_i190 = 0; c44_i190 < 100; c44_i190++) {
      c44_b_inData[c44_i190 + c44_i188] = (*(real_T (*)[400])c44_inData)
        [c44_i190 + c44_i188];
    }

    c44_i188 += 100;
  }

  c44_i191 = 0;
  for (c44_i192 = 0; c44_i192 < 4; c44_i192++) {
    for (c44_i193 = 0; c44_i193 < 100; c44_i193++) {
      c44_u[c44_i193 + c44_i191] = c44_b_inData[c44_i193 + c44_i191];
    }

    c44_i191 += 100;
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 0, 0U, 1U, 0U, 2, 100, 4),
                FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static void c44_s_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId,
  real_T c44_y[400])
{
  real_T c44_dv15[400];
  int32_T c44_i194;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), c44_dv15, 1, 0, 0U, 1, 0U, 2,
                100, 4);
  for (c44_i194 = 0; c44_i194 < 400; c44_i194++) {
    c44_y[c44_i194] = c44_dv15[c44_i194];
  }

  sf_mex_destroy(&c44_u);
}

static void c44_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_Hi;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  real_T c44_y[400];
  int32_T c44_i195;
  int32_T c44_i196;
  int32_T c44_i197;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_Hi = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_Hi), &c44_thisId, c44_y);
  sf_mex_destroy(&c44_Hi);
  c44_i195 = 0;
  for (c44_i196 = 0; c44_i196 < 4; c44_i196++) {
    for (c44_i197 = 0; c44_i197 < 100; c44_i197++) {
      (*(real_T (*)[400])c44_outData)[c44_i197 + c44_i195] = c44_y[c44_i197 +
        c44_i195];
    }

    c44_i195 += 100;
  }

  sf_mex_destroy(&c44_mxArrayInData);
}

const mxArray *sf_c44_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c44_nameCaptureInfo;
  c44_ResolvedFunctionInfo c44_info[20];
  const mxArray *c44_m0 = NULL;
  int32_T c44_i198;
  c44_ResolvedFunctionInfo *c44_r0;
  c44_nameCaptureInfo = NULL;
  c44_nameCaptureInfo = NULL;
  c44_info_helper(c44_info);
  sf_mex_assign(&c44_m0, sf_mex_createstruct("nameCaptureInfo", 1, 20), FALSE);
  for (c44_i198 = 0; c44_i198 < 20; c44_i198++) {
    c44_r0 = &c44_info[c44_i198];
    sf_mex_addfield(c44_m0, sf_mex_create("nameCaptureInfo", c44_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c44_r0->context)), "context", "nameCaptureInfo",
                    c44_i198);
    sf_mex_addfield(c44_m0, sf_mex_create("nameCaptureInfo", c44_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c44_r0->name)), "name", "nameCaptureInfo",
                    c44_i198);
    sf_mex_addfield(c44_m0, sf_mex_create("nameCaptureInfo",
      c44_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c44_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c44_i198);
    sf_mex_addfield(c44_m0, sf_mex_create("nameCaptureInfo", c44_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c44_r0->resolved)), "resolved",
                    "nameCaptureInfo", c44_i198);
    sf_mex_addfield(c44_m0, sf_mex_create("nameCaptureInfo", &c44_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c44_i198);
    sf_mex_addfield(c44_m0, sf_mex_create("nameCaptureInfo", &c44_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c44_i198);
    sf_mex_addfield(c44_m0, sf_mex_create("nameCaptureInfo",
      &c44_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c44_i198);
    sf_mex_addfield(c44_m0, sf_mex_create("nameCaptureInfo",
      &c44_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c44_i198);
  }

  sf_mex_assign(&c44_nameCaptureInfo, c44_m0, FALSE);
  return c44_nameCaptureInfo;
}

static void c44_info_helper(c44_ResolvedFunctionInfo c44_info[20])
{
  c44_info[0].context = "";
  c44_info[0].name = "OptimalMPCInputExportC_vP";
  c44_info[0].dominantType = "double";
  c44_info[0].resolved =
    "[E]/home/burrimi/git/darivianakis/SemProject/OptimalMPCInputExportC_vP.m";
  c44_info[0].fileTimeLo = 1378039760U;
  c44_info[0].fileTimeHi = 0U;
  c44_info[0].mFileTimeLo = 0U;
  c44_info[0].mFileTimeHi = 0U;
  c44_info[1].context =
    "[E]/home/burrimi/git/darivianakis/SemProject/OptimalMPCInputExportC_vP.m";
  c44_info[1].name = "error";
  c44_info[1].dominantType = "char";
  c44_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/lang/error.m";
  c44_info[1].fileTimeLo = 1301328470U;
  c44_info[1].fileTimeHi = 0U;
  c44_info[1].mFileTimeLo = 0U;
  c44_info[1].mFileTimeHi = 0U;
  c44_info[2].context =
    "[E]/home/burrimi/git/darivianakis/SemProject/OptimalMPCInputExportC_vP.m";
  c44_info[2].name = "mtimes";
  c44_info[2].dominantType = "double";
  c44_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c44_info[2].fileTimeLo = 1289519692U;
  c44_info[2].fileTimeHi = 0U;
  c44_info[2].mFileTimeLo = 0U;
  c44_info[2].mFileTimeHi = 0U;
  c44_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c44_info[3].name = "eml_index_class";
  c44_info[3].dominantType = "";
  c44_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c44_info[3].fileTimeLo = 1286818778U;
  c44_info[3].fileTimeHi = 0U;
  c44_info[3].mFileTimeLo = 0U;
  c44_info[3].mFileTimeHi = 0U;
  c44_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c44_info[4].name = "eml_scalar_eg";
  c44_info[4].dominantType = "double";
  c44_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c44_info[4].fileTimeLo = 1286818796U;
  c44_info[4].fileTimeHi = 0U;
  c44_info[4].mFileTimeLo = 0U;
  c44_info[4].mFileTimeHi = 0U;
  c44_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c44_info[5].name = "eml_xgemm";
  c44_info[5].dominantType = "int32";
  c44_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c44_info[5].fileTimeLo = 1299076772U;
  c44_info[5].fileTimeHi = 0U;
  c44_info[5].mFileTimeLo = 0U;
  c44_info[5].mFileTimeHi = 0U;
  c44_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c44_info[6].name = "eml_blas_inline";
  c44_info[6].dominantType = "";
  c44_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c44_info[6].fileTimeLo = 1299076768U;
  c44_info[6].fileTimeHi = 0U;
  c44_info[6].mFileTimeLo = 0U;
  c44_info[6].mFileTimeHi = 0U;
  c44_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c44_info[7].name = "eml_refblas_xgemm";
  c44_info[7].dominantType = "int32";
  c44_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c44_info[7].fileTimeLo = 1299076774U;
  c44_info[7].fileTimeHi = 0U;
  c44_info[7].mFileTimeLo = 0U;
  c44_info[7].mFileTimeHi = 0U;
  c44_info[8].context =
    "[E]/home/burrimi/git/darivianakis/SemProject/OptimalMPCInputExportC_vP.m";
  c44_info[8].name = "all";
  c44_info[8].dominantType = "double";
  c44_info[8].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c44_info[8].fileTimeLo = 1286818834U;
  c44_info[8].fileTimeHi = 0U;
  c44_info[8].mFileTimeLo = 0U;
  c44_info[8].mFileTimeHi = 0U;
  c44_info[9].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m";
  c44_info[9].name = "eml_all_or_any";
  c44_info[9].dominantType = "char";
  c44_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c44_info[9].fileTimeLo = 1286818694U;
  c44_info[9].fileTimeHi = 0U;
  c44_info[9].mFileTimeLo = 0U;
  c44_info[9].mFileTimeHi = 0U;
  c44_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_all_or_any.m";
  c44_info[10].name = "eml_assert_valid_dim";
  c44_info[10].dominantType = "double";
  c44_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c44_info[10].fileTimeLo = 1286818694U;
  c44_info[10].fileTimeHi = 0U;
  c44_info[10].mFileTimeLo = 0U;
  c44_info[10].mFileTimeHi = 0U;
  c44_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c44_info[11].name = "eml_scalar_floor";
  c44_info[11].dominantType = "double";
  c44_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c44_info[11].fileTimeLo = 1286818726U;
  c44_info[11].fileTimeHi = 0U;
  c44_info[11].mFileTimeLo = 0U;
  c44_info[11].mFileTimeHi = 0U;
  c44_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m";
  c44_info[12].name = "intmax";
  c44_info[12].dominantType = "char";
  c44_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c44_info[12].fileTimeLo = 1286818756U;
  c44_info[12].fileTimeHi = 0U;
  c44_info[12].mFileTimeLo = 0U;
  c44_info[12].mFileTimeHi = 0U;
  c44_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c44_info[13].name = "eml_xdotu";
  c44_info[13].dominantType = "int32";
  c44_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c44_info[13].fileTimeLo = 1299076772U;
  c44_info[13].fileTimeHi = 0U;
  c44_info[13].mFileTimeLo = 0U;
  c44_info[13].mFileTimeHi = 0U;
  c44_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m";
  c44_info[14].name = "eml_xdot";
  c44_info[14].dominantType = "int32";
  c44_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m";
  c44_info[14].fileTimeLo = 1299076772U;
  c44_info[14].fileTimeHi = 0U;
  c44_info[14].mFileTimeLo = 0U;
  c44_info[14].mFileTimeHi = 0U;
  c44_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m";
  c44_info[15].name = "eml_refblas_xdot";
  c44_info[15].dominantType = "int32";
  c44_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c44_info[15].fileTimeLo = 1299076772U;
  c44_info[15].fileTimeHi = 0U;
  c44_info[15].mFileTimeLo = 0U;
  c44_info[15].mFileTimeHi = 0U;
  c44_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m";
  c44_info[16].name = "eml_refblas_xdotx";
  c44_info[16].dominantType = "int32";
  c44_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c44_info[16].fileTimeLo = 1299076774U;
  c44_info[16].fileTimeHi = 0U;
  c44_info[16].mFileTimeLo = 0U;
  c44_info[16].mFileTimeHi = 0U;
  c44_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c44_info[17].name = "eml_index_minus";
  c44_info[17].dominantType = "int32";
  c44_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m";
  c44_info[17].fileTimeLo = 1286818778U;
  c44_info[17].fileTimeHi = 0U;
  c44_info[17].mFileTimeLo = 0U;
  c44_info[17].mFileTimeHi = 0U;
  c44_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c44_info[18].name = "eml_index_times";
  c44_info[18].dominantType = "int32";
  c44_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m";
  c44_info[18].fileTimeLo = 1286818780U;
  c44_info[18].fileTimeHi = 0U;
  c44_info[18].mFileTimeLo = 0U;
  c44_info[18].mFileTimeHi = 0U;
  c44_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m";
  c44_info[19].name = "eml_index_plus";
  c44_info[19].dominantType = "int32";
  c44_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c44_info[19].fileTimeLo = 1286818778U;
  c44_info[19].fileTimeHi = 0U;
  c44_info[19].mFileTimeLo = 0U;
  c44_info[19].mFileTimeHi = 0U;
}

static void c44_OptimalMPCInputExportC_vP
  (SFc44_controller_templateInstanceStruct *chartInstance, real_T c44_X[4],
   real_T c44_Uprev[2], real_T c44_Mprev, real_T c44_nx, real_T c44_nu, real_T
   c44_Hn[75996], real_T c44_Kn[18999], real_T c44_Hobj[36848], real_T c44_Fobj
   [9212], real_T c44_Gobj[2303], real_T c44_Fi[18424], real_T c44_Gi[4606],
   real_T c44_Nc[2303], real_T c44_Ropt[4], real_T c44_Ml[60], real_T c44_Mr[10],
   real_T c44_U_data[2], int32_T c44_U_sizes[1], real_T *c44_flag_oob, real_T
   *c44_M)
{
  uint32_T c44_debug_family_var_map[58];
  real_T c44_nuRoptr;
  real_T c44_nuRoptc;
  real_T c44_nuUprevr;
  real_T c44_nuUprevc;
  real_T c44_nxQoptr;
  real_T c44_nxQoptc;
  real_T c44_nxHobjr;
  real_T c44_nxHobjc;
  real_T c44_unusedU0;
  real_T c44_b_unusedU0;
  real_T c44_nxFobjr;
  real_T c44_nxFobjc;
  real_T c44_unusedU1;
  real_T c44_b_unusedU1;
  real_T c44_nxGobjr;
  real_T c44_nxGobjc;
  real_T c44_unusedU2;
  real_T c44_b_unusedU2;
  real_T c44_nmMprevr;
  real_T c44_nmMprevc;
  real_T c44_nm;
  real_T c44_unusedU3;
  real_T c44_unusedU4;
  real_T c44_b_unusedU3;
  real_T c44_b_unusedU4;
  real_T c44_tolerance;
  real_T c44_nr;
  real_T c44_MPT_ABSTOL;
  real_T c44_minreg;
  real_T c44_Hsz;
  real_T c44_Hi[400];
  real_T c44_Ki[100];
  int32_T c44_UminJ_sizes;
  real_T c44_UminJ_data[2];
  real_T c44_minJ;
  real_T c44_abspos;
  real_T c44_sumViol;
  real_T c44_isinside;
  real_T c44_F[8];
  real_T c44_G[2];
  real_T c44_nc;
  real_T c44_hx;
  real_T c44_Jobj;
  real_T c44_U[2];
  real_T c44_nargin = 17.0;
  real_T c44_nargout = 3.0;
  int32_T c44_i199;
  int32_T c44_b_Mprev;
  int32_T c44_i200;
  int32_T c44_i201;
  real_T c44_a[30];
  int32_T c44_i202;
  real_T c44_b[6];
  int32_T c44_i203;
  int32_T c44_i204;
  real_T c44_y[5];
  int32_T c44_i205;
  int32_T c44_i206;
  int32_T c44_c_Mprev;
  int32_T c44_i207;
  boolean_T c44_b_y[5];
  int32_T c44_im;
  real_T c44_b_im;
  int32_T c44_c_im;
  int32_T c44_i208;
  int32_T c44_i209;
  int32_T c44_i210;
  int32_T c44_i211;
  int32_T c44_i212;
  int32_T c44_i213;
  int32_T c44_i214;
  int32_T c44_d_im;
  int32_T c44_i215;
  boolean_T c44_c_y[5];
  int32_T c44_i216;
  int32_T c44_i217;
  int32_T c44_i218;
  int32_T c44_b_sizes;
  int32_T c44_i219;
  real_T c44_b_data[2];
  int32_T c44_i220;
  int32_T c44_ireg;
  real_T c44_b_ireg;
  real_T c44_d1;
  int32_T c44_i221;
  int32_T c44_loop_ub;
  int32_T c44_i;
  real_T c44_b_i;
  int32_T c44_j;
  real_T c44_b_j;
  real_T c44_d2;
  int32_T c44_i222;
  int32_T c44_b_loop_ub;
  int32_T c44_c_i;
  int32_T c44_c_ireg;
  int32_T c44_i223;
  int32_T c44_i224;
  int32_T c44_d_ireg;
  int32_T c44_i225;
  int32_T c44_i226;
  int32_T c44_c_loop_ub;
  int32_T c44_ic;
  real_T c44_b_ic;
  int32_T c44_c_ic;
  int32_T c44_i227;
  real_T c44_b_a[4];
  int32_T c44_i228;
  real_T c44_b_b[4];
  int32_T c44_k;
  int32_T c44_b_k;
  int32_T c44_i229;
  real_T c44_c_a[8];
  int32_T c44_i230;
  int32_T c44_i231;
  real_T c44_d_y[2];
  int32_T c44_i232;
  int32_T c44_i233;
  int32_T c44_i234;
  int32_T c44_i235;
  int32_T c44_e_ireg;
  int32_T c44_i236;
  int32_T c44_i237;
  real_T c44_c_b[16];
  int32_T c44_i238;
  int32_T c44_i239;
  real_T c44_e_y[4];
  int32_T c44_i240;
  int32_T c44_i241;
  real_T c44_f_y;
  int32_T c44_c_k;
  int32_T c44_d_k;
  int32_T c44_f_ireg;
  int32_T c44_i242;
  int32_T c44_i243;
  real_T c44_g_y;
  int32_T c44_e_k;
  int32_T c44_f_k;
  int32_T c44_i244;
  int32_T c44_i245;
  real_T c44_d_a[2];
  int32_T c44_i246;
  real_T c44_d_b[4];
  int32_T c44_i247;
  int32_T c44_i248;
  real_T c44_h_y[2];
  int32_T c44_i249;
  int32_T c44_i250;
  real_T c44_i_y;
  int32_T c44_g_k;
  int32_T c44_h_k;
  int32_T c44_a_sizes[2];
  int32_T c44_e_a;
  int32_T c44_f_a;
  int32_T c44_d_loop_ub;
  int32_T c44_i251;
  real_T c44_a_data[2];
  int32_T c44_i252;
  int32_T c44_i253;
  int32_T c44_b_a_sizes[2];
  int32_T c44_g_a;
  int32_T c44_h_a;
  int32_T c44_e_loop_ub;
  int32_T c44_i254;
  real_T c44_b_a_data[2];
  int32_T c44_i255;
  real_T c44_e_b[4];
  int32_T c44_i256;
  real_T c44_j_y;
  int32_T c44_i_k;
  int32_T c44_j_k;
  int32_T c44_i257;
  int32_T c44_i258;
  int32_T c44_b_minreg;
  int32_T c44_i259;
  int32_T c44_i260;
  int32_T c44_c_minreg;
  int32_T c44_i261;
  int32_T c44_i262;
  int32_T c44_i263;
  int32_T c44_i264;
  int32_T c44_i265;
  int32_T c44_i266;
  int32_T c44_i267;
  int32_T c44_i268;
  int32_T c44_i269;
  int32_T *c44_sfEvent;
  boolean_T guard1 = FALSE;
  int32_T exitg1;
  c44_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  sf_debug_symbol_scope_push_eml(0U, 58U, 64U, c44_b_debug_family_names,
    c44_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c44_nuRoptr, 0U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c44_nuRoptc, 1U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c44_nuUprevr, 2U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c44_nuUprevc, 3U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c44_nxQoptr, 4U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c44_nxQoptc, 5U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c44_nxHobjr, 6U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c44_nxHobjc, 7U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c44_unusedU0, MAX_uint32_T,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_b_unusedU0, MAX_uint32_T,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c44_nxFobjr, 9U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c44_nxFobjc, 10U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_unusedU1, MAX_uint32_T,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_b_unusedU1, MAX_uint32_T,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c44_nxGobjr, 12U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c44_nxGobjc, 13U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c44_unusedU2, MAX_uint32_T,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_b_unusedU2, MAX_uint32_T,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c44_nmMprevr, 15U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c44_nmMprevc, 16U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c44_nm, 17U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c44_unusedU3, MAX_uint32_T,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_unusedU4, MAX_uint32_T,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_b_unusedU3, MAX_uint32_T,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_b_unusedU4, MAX_uint32_T,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_tolerance, 20U,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c44_nr, 21U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c44_MPT_ABSTOL, 22U,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_minreg, 23U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c44_Hsz, 24U, c44_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c44_Hi, 25U, c44_u_sf_marshallOut,
    c44_r_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Ki, 26U, c44_t_sf_marshallOut,
    c44_q_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_dyn_importable(c44_UminJ_data, (const int32_T *)
    &c44_UminJ_sizes, NULL, 0, 27, (void *)c44_p_sf_marshallOut, (void *)
    c44_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_minJ, 28U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_abspos, 29U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_sumViol, 30U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_isinside, 31U,
    c44_sf_marshallOut, c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_F, 32U, c44_s_sf_marshallOut,
    c44_p_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_G, 33U, c44_n_sf_marshallOut,
    c44_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_nc, 34U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_hx, 35U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_Jobj, 36U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_U, MAX_uint32_T,
    c44_n_sf_marshallOut, c44_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_nargin, 38U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_nargout, 39U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_X, 40U, c44_o_sf_marshallOut,
    c44_o_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Uprev, 41U, c44_n_sf_marshallOut,
    c44_n_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_Mprev, 42U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_nx, 43U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c44_nu, 44U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Hn, 45U, c44_m_sf_marshallOut,
    c44_m_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Kn, 46U, c44_r_sf_marshallOut,
    c44_l_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Hobj, 47U, c44_k_sf_marshallOut,
    c44_k_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Fobj, 48U, c44_j_sf_marshallOut,
    c44_j_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Gobj, 49U, c44_i_sf_marshallOut,
    c44_i_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Fi, 50U, c44_h_sf_marshallOut,
    c44_h_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Gi, 51U, c44_g_sf_marshallOut,
    c44_g_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Nc, 52U, c44_q_sf_marshallOut,
    c44_f_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Ropt, 53U, c44_d_sf_marshallOut,
    c44_e_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Ml, 54U, c44_c_sf_marshallOut,
    c44_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_Mr, 55U, c44_b_sf_marshallOut,
    c44_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_dyn_importable(c44_U_data, (const int32_T *)
    c44_U_sizes, NULL, 0, -1, (void *)c44_p_sf_marshallOut, (void *)
    c44_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_flag_oob, 56U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c44_M, 57U, c44_sf_marshallOut,
    c44_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 5);
  c44_nuRoptr = 2.0;
  c44_nuRoptc = 2.0;
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 6);
  CV_SCRIPT_COND(0, 0, FALSE);
  CV_SCRIPT_COND(0, 1, FALSE);
  if (CV_SCRIPT_COND(0, 2, 2.0 != c44_nu)) {
    CV_SCRIPT_MCDC(0, 0, TRUE);
    CV_SCRIPT_IF(0, 0, TRUE);
    _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 7);
    c44_error(chartInstance);
  } else {
    CV_SCRIPT_MCDC(0, 0, FALSE);
    CV_SCRIPT_IF(0, 0, FALSE);
  }

  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 10);
  c44_nuUprevr = 2.0;
  c44_nuUprevc = 1.0;
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 11);
  CV_SCRIPT_COND(0, 3, c44_nuUprevr != c44_nu);
  CV_SCRIPT_COND(0, 4, FALSE);
  CV_SCRIPT_COND(0, 5, c44_nuUprevr != c44_nu);
  CV_SCRIPT_MCDC(0, 1, FALSE);
  CV_SCRIPT_IF(0, 1, FALSE);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 15);
  c44_nxQoptr = 4.0;
  c44_nxQoptc = 4.0;
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 16);
  CV_SCRIPT_COND(0, 6, FALSE);
  CV_SCRIPT_COND(0, 7, FALSE);
  if (CV_SCRIPT_COND(0, 8, 4.0 != c44_nx)) {
    CV_SCRIPT_MCDC(0, 2, TRUE);
    CV_SCRIPT_IF(0, 2, TRUE);
    _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 17);
    c44_b_error(chartInstance);
  } else {
    CV_SCRIPT_MCDC(0, 2, FALSE);
    CV_SCRIPT_IF(0, 2, FALSE);
  }

  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 19);
  c44_nxHobjr = 4.0;
  c44_nxHobjc = 4.0;
  c44_unusedU0 = 2303.0;
  sf_debug_symbol_switch(8U, 8U);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 19);
  c44_b_unusedU0 = 0.0;
  sf_debug_symbol_switch(8U, 9U);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 20);
  CV_SCRIPT_COND(0, 9, FALSE);
  CV_SCRIPT_COND(0, 10, FALSE);
  CV_SCRIPT_COND(0, 11, c44_nxHobjr != c44_nx);
  CV_SCRIPT_MCDC(0, 3, FALSE);
  CV_SCRIPT_IF(0, 3, FALSE);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 24);
  CV_SCRIPT_IF(0, 4, FALSE);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 27);
  c44_nxFobjr = 1.0;
  c44_nxFobjc = 4.0;
  c44_unusedU1 = 2303.0;
  sf_debug_symbol_switch(11U, 12U);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 27);
  c44_b_unusedU1 = 0.0;
  sf_debug_symbol_switch(11U, 13U);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 28);
  CV_SCRIPT_COND(0, 12, FALSE);
  CV_SCRIPT_COND(0, 13, c44_nxFobjc != c44_nx);
  CV_SCRIPT_MCDC(0, 4, FALSE);
  CV_SCRIPT_IF(0, 5, FALSE);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 31);
  c44_nxGobjr = 1.0;
  c44_nxGobjc = 1.0;
  c44_unusedU2 = 2303.0;
  sf_debug_symbol_switch(14U, 16U);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 31);
  c44_b_unusedU2 = 0.0;
  sf_debug_symbol_switch(14U, 17U);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 32);
  CV_SCRIPT_COND(0, 14, FALSE);
  CV_SCRIPT_COND(0, 15, FALSE);
  CV_SCRIPT_MCDC(0, 5, FALSE);
  CV_SCRIPT_IF(0, 6, FALSE);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 37);
  c44_nmMprevr = 1.0;
  c44_nmMprevc = 1.0;
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 38);
  CV_SCRIPT_COND(0, 16, FALSE);
  CV_SCRIPT_COND(0, 17, FALSE);
  CV_SCRIPT_MCDC(0, 6, FALSE);
  CV_SCRIPT_IF(0, 7, FALSE);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 44);
  *c44_M = 0.0;
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 45);
  c44_unusedU3 = 5.0;
  sf_debug_symbol_switch(18U, 21U);
  c44_unusedU4 = 6.0;
  sf_debug_symbol_switch(19U, 22U);
  c44_nm = 2.0;
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 45);
  c44_b_unusedU3 = 0.0;
  sf_debug_symbol_switch(18U, 23U);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 45);
  c44_b_unusedU4 = 0.0;
  sf_debug_symbol_switch(19U, 24U);
  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 46);
  guard1 = FALSE;
  if (CV_SCRIPT_COND(0, 18, c44_Mprev < 1.0)) {
    guard1 = TRUE;
  } else if (CV_SCRIPT_COND(0, 19, c44_Mprev > 2.0)) {
    guard1 = TRUE;
  } else {
    CV_SCRIPT_MCDC(0, 7, FALSE);
    CV_SCRIPT_IF(0, 8, FALSE);
    _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 52);
    c44_b_Mprev = (int32_T)_SFD_INTEGER_CHECK("Mprev", c44_Mprev) - 1;
    for (c44_i200 = 0; c44_i200 < 6; c44_i200++) {
      for (c44_i201 = 0; c44_i201 < 5; c44_i201++) {
        c44_a[c44_i201 + 5 * c44_i200] = c44_Ml[(c44_i201 + 5 * c44_i200) + 30 *
          c44_b_Mprev];
      }
    }

    for (c44_i202 = 0; c44_i202 < 4; c44_i202++) {
      c44_b[c44_i202] = c44_X[c44_i202];
    }

    for (c44_i203 = 0; c44_i203 < 2; c44_i203++) {
      c44_b[c44_i203 + 4] = c44_Uprev[c44_i203];
    }

    for (c44_i204 = 0; c44_i204 < 5; c44_i204++) {
      c44_y[c44_i204] = 0.0;
      c44_i205 = 0;
      for (c44_i206 = 0; c44_i206 < 6; c44_i206++) {
        c44_y[c44_i204] += c44_a[c44_i205 + c44_i204] * c44_b[c44_i206];
        c44_i205 += 5;
      }
    }

    c44_c_Mprev = (int32_T)_SFD_INTEGER_CHECK("Mprev", c44_Mprev) - 1;
    for (c44_i207 = 0; c44_i207 < 5; c44_i207++) {
      c44_b_y[c44_i207] = (c44_y[c44_i207] <= c44_Mr[c44_i207 + 5 * c44_c_Mprev]);
    }

    if (CV_SCRIPT_IF(0, 9, c44_all(chartInstance, c44_b_y))) {
      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 53);
      *c44_M = c44_Mprev;
    } else {
      c44_im = 0;
      do {
        exitg1 = 0U;
        if (c44_im < 2) {
          c44_b_im = 1.0 + (real_T)c44_im;
          CV_SCRIPT_FOR(0, 0, 1);
          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 56);
          c44_c_im = (int32_T)c44_b_im - 1;
          for (c44_i208 = 0; c44_i208 < 6; c44_i208++) {
            for (c44_i209 = 0; c44_i209 < 5; c44_i209++) {
              c44_a[c44_i209 + 5 * c44_i208] = c44_Ml[(c44_i209 + 5 * c44_i208)
                + 30 * c44_c_im];
            }
          }

          for (c44_i210 = 0; c44_i210 < 4; c44_i210++) {
            c44_b[c44_i210] = c44_X[c44_i210];
          }

          for (c44_i211 = 0; c44_i211 < 2; c44_i211++) {
            c44_b[c44_i211 + 4] = c44_Uprev[c44_i211];
          }

          for (c44_i212 = 0; c44_i212 < 5; c44_i212++) {
            c44_y[c44_i212] = 0.0;
            c44_i213 = 0;
            for (c44_i214 = 0; c44_i214 < 6; c44_i214++) {
              c44_y[c44_i212] += c44_a[c44_i213 + c44_i212] * c44_b[c44_i214];
              c44_i213 += 5;
            }
          }

          c44_d_im = (int32_T)c44_b_im - 1;
          for (c44_i215 = 0; c44_i215 < 5; c44_i215++) {
            c44_c_y[c44_i215] = (c44_y[c44_i215] <= c44_Mr[c44_i215 + 5 *
                                 c44_d_im]);
          }

          if (CV_SCRIPT_IF(0, 10, c44_all(chartInstance, c44_c_y))) {
            _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 57);
            *c44_M = c44_b_im;
            exitg1 = 1U;
          } else {
            c44_im++;
            sf_mex_listen_for_ctrl_c(chartInstance->S);
          }
        } else {
          CV_SCRIPT_FOR(0, 0, 0);
          exitg1 = 1U;
        }
      } while (exitg1 == 0U);
    }

    _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 62);
    if (CV_SCRIPT_IF(0, 11, *c44_M == 0.0)) {
      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 64);
      c44_U_sizes[0] = 2;
      for (c44_i216 = 0; c44_i216 < 2; c44_i216++) {
        c44_U_data[c44_i216] = c44_Uprev[c44_i216];
      }

      sf_debug_symbol_switch(37U, 61U);
      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 65);
      *c44_flag_oob = -1.0;
    } else {
      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 70);
      c44_tolerance = 1.0;
      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 71);
      c44_nr = 2303.0;
      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 72);
      c44_MPT_ABSTOL = 1.0E-8;
      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 73);
      c44_minreg = 0.0;
      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 76);
      *c44_flag_oob = 0.0;
      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 79);
      c44_Hsz = 4.0;
      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 80);
      for (c44_i217 = 0; c44_i217 < 400; c44_i217++) {
        c44_Hi[c44_i217] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 81);
      for (c44_i218 = 0; c44_i218 < 100; c44_i218++) {
        c44_Ki[c44_i218] = 0.0;
      }

      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 83);
      _SFD_INTEGER_CHECK("nu", c44_nu);
      c44_b_sizes = 2;
      for (c44_i219 = 0; c44_i219 < 2; c44_i219++) {
        c44_b_data[c44_i219] = 1.0;
      }

      c44_UminJ_sizes = 2;
      for (c44_i220 = 0; c44_i220 < 2; c44_i220++) {
        c44_UminJ_data[c44_i220] = 10000.0 * c44_b_data[c44_i220];
      }

      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 84);
      c44_minJ = 1.0E+8;
      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 87);
      c44_abspos = 1.0;
      c44_ireg = 0;
      while (c44_ireg < 2303) {
        c44_b_ireg = 1.0 + (real_T)c44_ireg;
        CV_SCRIPT_FOR(0, 1, 1);
        _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 89);
        c44_sumViol = 0.0;
        _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 90);
        c44_isinside = 1.0;
        c44_d1 = c44_Nc[(int32_T)c44_b_ireg - 1];
        c44_i221 = (int32_T)c44_d1;
        sf_debug_for_loop_vector_check(1.0, 1.0, c44_d1, mxDOUBLE_CLASS,
          c44_i221);
        c44_loop_ub = c44_i221;
        c44_i = 0;
        while (c44_i <= c44_loop_ub - 1) {
          c44_b_i = 1.0 + (real_T)c44_i;
          CV_SCRIPT_FOR(0, 2, 1);
          c44_j = 0;
          while (c44_j < 4) {
            c44_b_j = 1.0 + (real_T)c44_j;
            CV_SCRIPT_FOR(0, 3, 1);
            _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 96);
            c44_Hi[(_SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)c44_b_i, 1, 100,
                     1, 0) + 100 * ((int32_T)c44_b_j - 1)) - 1] = c44_Hn
              [(_SFD_EML_ARRAY_BOUNDS_CHECK("Hn", (int32_T)_SFD_INTEGER_CHECK(
                  "abspos + i - 1", (c44_abspos + c44_b_i) - 1.0), 1, 18999, 1,
                 0) + 18999 * ((int32_T)c44_b_j - 1)) - 1];
            c44_j++;
            sf_mex_listen_for_ctrl_c(chartInstance->S);
          }

          CV_SCRIPT_FOR(0, 3, 0);
          c44_i++;
          sf_mex_listen_for_ctrl_c(chartInstance->S);
        }

        CV_SCRIPT_FOR(0, 2, 0);
        c44_d2 = c44_Nc[(int32_T)c44_b_ireg - 1];
        c44_i222 = (int32_T)c44_d2;
        sf_debug_for_loop_vector_check(1.0, 1.0, c44_d2, mxDOUBLE_CLASS,
          c44_i222);
        c44_b_loop_ub = c44_i222;
        c44_c_i = 0;
        while (c44_c_i <= c44_b_loop_ub - 1) {
          c44_b_i = 1.0 + (real_T)c44_c_i;
          CV_SCRIPT_FOR(0, 4, 1);
          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 102);
          c44_Ki[_SFD_EML_ARRAY_BOUNDS_CHECK("Ki", (int32_T)c44_b_i, 1, 100, 1,
            0) - 1] = c44_Kn[_SFD_EML_ARRAY_BOUNDS_CHECK("Kn", (int32_T)
            _SFD_INTEGER_CHECK("abspos + i - 1", (c44_abspos + c44_b_i) - 1.0),
            1, 18999, 1, 0) - 1];
          c44_c_i++;
          sf_mex_listen_for_ctrl_c(chartInstance->S);
        }

        CV_SCRIPT_FOR(0, 4, 0);
        _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 104);
        c44_abspos += c44_Nc[(int32_T)c44_b_ireg - 1];
        _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 106);
        c44_c_ireg = (int32_T)c44_b_ireg - 1;
        for (c44_i223 = 0; c44_i223 < 4; c44_i223++) {
          for (c44_i224 = 0; c44_i224 < 2; c44_i224++) {
            c44_F[c44_i224 + (c44_i223 << 1)] = c44_Fi[(c44_i224 + (c44_i223 <<
              1)) + (c44_c_ireg << 3)];
          }
        }

        _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 107);
        c44_d_ireg = (int32_T)c44_b_ireg - 1;
        for (c44_i225 = 0; c44_i225 < 2; c44_i225++) {
          c44_G[c44_i225] = c44_Gi[c44_i225 + (c44_d_ireg << 1)];
        }

        _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 109);
        c44_nc = c44_Nc[(int32_T)c44_b_ireg - 1];
        c44_i226 = (int32_T)c44_nc;
        sf_debug_for_loop_vector_check(1.0, 1.0, c44_nc, mxDOUBLE_CLASS,
          c44_i226);
        c44_c_loop_ub = c44_i226;
        c44_ic = 0;
        while (c44_ic <= c44_c_loop_ub - 1) {
          c44_b_ic = 1.0 + (real_T)c44_ic;
          CV_SCRIPT_FOR(0, 5, 1);
          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 112);
          c44_c_ic = _SFD_EML_ARRAY_BOUNDS_CHECK("Hi", (int32_T)c44_b_ic, 1, 100,
            1, 0) - 1;
          for (c44_i227 = 0; c44_i227 < 4; c44_i227++) {
            c44_b_a[c44_i227] = c44_Hi[c44_c_ic + 100 * c44_i227];
          }

          for (c44_i228 = 0; c44_i228 < 4; c44_i228++) {
            c44_b_b[c44_i228] = c44_X[c44_i228];
          }

          c44_hx = 0.0;
          for (c44_k = 1; c44_k < 5; c44_k++) {
            c44_b_k = c44_k - 1;
            c44_hx += c44_b_a[c44_b_k] * c44_b_b[c44_b_k];
          }

          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 113);
          if (CV_SCRIPT_IF(0, 12, c44_hx - c44_Ki[(int32_T)c44_b_ic - 1] >
                           1.0E-8)) {
            _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 114);
            c44_isinside = 0.0;
            _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 115);
            c44_sumViol += c44_hx - c44_Ki[(int32_T)c44_b_ic - 1];
          }

          c44_ic++;
          sf_mex_listen_for_ctrl_c(chartInstance->S);
        }

        CV_SCRIPT_FOR(0, 5, 0);
        _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 119);
        if (CV_SCRIPT_IF(0, 13, c44_sumViol < c44_tolerance)) {
          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 120);
          c44_tolerance = c44_sumViol;
          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 121);
          c44_minreg = c44_b_ireg;
        }

        _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 124);
        if (CV_SCRIPT_IF(0, 14, c44_isinside == 1.0)) {
          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 125);
          for (c44_i229 = 0; c44_i229 < 8; c44_i229++) {
            c44_c_a[c44_i229] = c44_F[c44_i229];
          }

          for (c44_i230 = 0; c44_i230 < 4; c44_i230++) {
            c44_b_b[c44_i230] = c44_X[c44_i230];
          }

          for (c44_i231 = 0; c44_i231 < 2; c44_i231++) {
            c44_d_y[c44_i231] = 0.0;
            c44_i232 = 0;
            for (c44_i233 = 0; c44_i233 < 4; c44_i233++) {
              c44_d_y[c44_i231] += c44_c_a[c44_i232 + c44_i231] *
                c44_b_b[c44_i233];
              c44_i232 += 2;
            }
          }

          for (c44_i234 = 0; c44_i234 < 2; c44_i234++) {
            c44_U[c44_i234] = c44_d_y[c44_i234] + c44_G[c44_i234];
          }

          sf_debug_symbol_switch(37U, 42U);
          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 126);
          for (c44_i235 = 0; c44_i235 < 4; c44_i235++) {
            c44_b_a[c44_i235] = c44_X[c44_i235];
          }

          c44_e_ireg = (int32_T)c44_b_ireg - 1;
          for (c44_i236 = 0; c44_i236 < 4; c44_i236++) {
            for (c44_i237 = 0; c44_i237 < 4; c44_i237++) {
              c44_c_b[c44_i237 + (c44_i236 << 2)] = c44_Hobj[(c44_i237 +
                (c44_i236 << 2)) + (c44_e_ireg << 4)];
            }
          }

          c44_i238 = 0;
          for (c44_i239 = 0; c44_i239 < 4; c44_i239++) {
            c44_e_y[c44_i239] = 0.0;
            for (c44_i240 = 0; c44_i240 < 4; c44_i240++) {
              c44_e_y[c44_i239] += c44_b_a[c44_i240] * c44_c_b[c44_i240 +
                c44_i238];
            }

            c44_i238 += 4;
          }

          for (c44_i241 = 0; c44_i241 < 4; c44_i241++) {
            c44_b_b[c44_i241] = c44_X[c44_i241];
          }

          c44_f_y = 0.0;
          for (c44_c_k = 1; c44_c_k < 5; c44_c_k++) {
            c44_d_k = c44_c_k - 1;
            c44_f_y += c44_e_y[c44_d_k] * c44_b_b[c44_d_k];
          }

          c44_f_ireg = (int32_T)c44_b_ireg - 1;
          for (c44_i242 = 0; c44_i242 < 4; c44_i242++) {
            c44_b_a[c44_i242] = c44_Fobj[c44_i242 + (c44_f_ireg << 2)];
          }

          for (c44_i243 = 0; c44_i243 < 4; c44_i243++) {
            c44_b_b[c44_i243] = c44_X[c44_i243];
          }

          c44_g_y = 0.0;
          for (c44_e_k = 1; c44_e_k < 5; c44_e_k++) {
            c44_f_k = c44_e_k - 1;
            c44_g_y += c44_b_a[c44_f_k] * c44_b_b[c44_f_k];
          }

          c44_Jobj = (c44_f_y + c44_g_y) + c44_Gobj[(int32_T)c44_b_ireg - 1];
          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 144U);
          if (CV_SCRIPT_IF(0, 15, c44_Jobj < c44_minJ)) {
            _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 145U);
            c44_minJ = c44_Jobj;
            _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 146U);
            c44_UminJ_sizes = 2;
            for (c44_i244 = 0; c44_i244 < 2; c44_i244++) {
              c44_UminJ_data[c44_i244] = c44_U[c44_i244];
            }
          } else {
            _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 147U);
            if (CV_SCRIPT_IF(0, 16, c44_Jobj == c44_minJ)) {
              _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 148U);
              for (c44_i245 = 0; c44_i245 < 2; c44_i245++) {
                c44_d_a[c44_i245] = c44_U[c44_i245];
              }

              for (c44_i246 = 0; c44_i246 < 4; c44_i246++) {
                c44_d_b[c44_i246] = c44_Ropt[c44_i246];
              }

              c44_i247 = 0;
              for (c44_i248 = 0; c44_i248 < 2; c44_i248++) {
                c44_h_y[c44_i248] = 0.0;
                for (c44_i249 = 0; c44_i249 < 2; c44_i249++) {
                  c44_h_y[c44_i248] += c44_d_a[c44_i249] * c44_d_b[c44_i249 +
                    c44_i247];
                }

                c44_i247 += 2;
              }

              for (c44_i250 = 0; c44_i250 < 2; c44_i250++) {
                c44_d_y[c44_i250] = c44_U[c44_i250];
              }

              c44_i_y = 0.0;
              for (c44_g_k = 1; c44_g_k < 3; c44_g_k++) {
                c44_h_k = c44_g_k - 1;
                c44_i_y += c44_h_y[c44_h_k] * c44_d_y[c44_h_k];
              }

              c44_a_sizes[0] = 1;
              c44_a_sizes[1] = 2;
              c44_e_a = c44_a_sizes[0];
              c44_f_a = c44_a_sizes[1];
              c44_d_loop_ub = c44_UminJ_sizes - 1;
              for (c44_i251 = 0; c44_i251 <= c44_d_loop_ub; c44_i251++) {
                c44_a_data[c44_i251] = c44_UminJ_data[c44_i251];
              }

              for (c44_i252 = 0; c44_i252 < 4; c44_i252++) {
                c44_d_b[c44_i252] = c44_Ropt[c44_i252];
              }

              for (c44_i253 = 0; c44_i253 < 2; c44_i253++) {
                c44_h_y[c44_i253] = 0.0;
              }

              c44_b_a_sizes[0] = 1;
              c44_b_a_sizes[1] = 2;
              c44_g_a = c44_b_a_sizes[0];
              c44_h_a = c44_b_a_sizes[1];
              c44_e_loop_ub = c44_a_sizes[0] * c44_a_sizes[1] - 1;
              for (c44_i254 = 0; c44_i254 <= c44_e_loop_ub; c44_i254++) {
                c44_b_a_data[c44_i254] = c44_a_data[c44_i254];
              }

              for (c44_i255 = 0; c44_i255 < 4; c44_i255++) {
                c44_e_b[c44_i255] = c44_d_b[c44_i255];
              }

              c44_b_eml_xgemm(chartInstance, 2, c44_b_a_data, c44_b_a_sizes,
                              c44_e_b, 2, c44_h_y);
              c44_b_sizes = 2;
              for (c44_i256 = 0; c44_i256 < 2; c44_i256++) {
                c44_b_data[c44_i256] = c44_UminJ_data[c44_i256];
              }

              c44_j_y = 0.0;
              for (c44_i_k = 1; c44_i_k < 3; c44_i_k++) {
                c44_j_k = c44_i_k - 1;
                c44_j_y += c44_h_y[c44_j_k] * c44_b_data[c44_j_k];
              }

              if (CV_SCRIPT_IF(0, 17, c44_i_y < c44_j_y)) {
                _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 149U);
                c44_minJ = c44_Jobj;
                _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 150U);
                c44_UminJ_sizes = 2;
                for (c44_i257 = 0; c44_i257 < 2; c44_i257++) {
                  c44_UminJ_data[c44_i257] = c44_U[c44_i257];
                }
              }
            }
          }
        }

        c44_ireg++;
        sf_mex_listen_for_ctrl_c(chartInstance->S);
      }

      CV_SCRIPT_FOR(0, 1, 0);
      _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 156U);
      if (CV_SCRIPT_IF(0, 18, c44_minJ < 1.0E+8)) {
        _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 157U);
        c44_U_sizes[0] = 2;
        for (c44_i258 = 0; c44_i258 < 2; c44_i258++) {
          c44_U_data[c44_i258] = c44_UminJ_data[c44_i258];
        }

        sf_debug_symbol_switch(37U, 61U);
      } else {
        _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 160U);
        if (CV_SCRIPT_IF(0, 19, c44_minreg > 0.0)) {
          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 161U);
          c44_b_minreg = (int32_T)c44_minreg - 1;
          for (c44_i259 = 0; c44_i259 < 4; c44_i259++) {
            for (c44_i260 = 0; c44_i260 < 2; c44_i260++) {
              c44_F[c44_i260 + (c44_i259 << 1)] = c44_Fi[(c44_i260 + (c44_i259 <<
                1)) + (c44_b_minreg << 3)];
            }
          }

          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 162U);
          c44_c_minreg = (int32_T)c44_minreg - 1;
          for (c44_i261 = 0; c44_i261 < 2; c44_i261++) {
            c44_G[c44_i261] = c44_Gi[c44_i261 + (c44_c_minreg << 1)];
          }

          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 163U);
          for (c44_i262 = 0; c44_i262 < 8; c44_i262++) {
            c44_c_a[c44_i262] = c44_F[c44_i262];
          }

          for (c44_i263 = 0; c44_i263 < 4; c44_i263++) {
            c44_b_b[c44_i263] = c44_X[c44_i263];
          }

          for (c44_i264 = 0; c44_i264 < 2; c44_i264++) {
            c44_d_y[c44_i264] = 0.0;
            c44_i265 = 0;
            for (c44_i266 = 0; c44_i266 < 4; c44_i266++) {
              c44_d_y[c44_i264] += c44_c_a[c44_i265 + c44_i264] *
                c44_b_b[c44_i266];
              c44_i265 += 2;
            }
          }

          for (c44_i267 = 0; c44_i267 < 2; c44_i267++) {
            c44_d_y[c44_i267] += c44_G[c44_i267];
          }

          c44_U_sizes[0] = 2;
          for (c44_i268 = 0; c44_i268 < 2; c44_i268++) {
            c44_U_data[c44_i268] = c44_d_y[c44_i268];
          }

          sf_debug_symbol_switch(37U, 61U);
          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 164U);
          *c44_flag_oob = 1.0;
        } else {
          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 166U);
          c44_U_sizes[0] = 2;
          for (c44_i269 = 0; c44_i269 < 2; c44_i269++) {
            c44_U_data[c44_i269] = c44_Uprev[c44_i269];
          }

          sf_debug_symbol_switch(37U, 61U);
          _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 167U);
          *c44_flag_oob = 1.0;
        }
      }
    }
  }

  if (guard1 == TRUE) {
    CV_SCRIPT_MCDC(0, 7, TRUE);
    CV_SCRIPT_IF(0, 8, TRUE);
    _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 48);
    c44_U_sizes[0] = 2;
    for (c44_i199 = 0; c44_i199 < 2; c44_i199++) {
      c44_U_data[c44_i199] = c44_Uprev[c44_i199];
    }

    sf_debug_symbol_switch(37U, 61U);
    _SFD_SCRIPT_CALL(0U, *c44_sfEvent, 49);
    *c44_flag_oob = -1.0;
  }

  _SFD_SCRIPT_CALL(0U, *c44_sfEvent, -167);
  sf_debug_symbol_scope_pop();
}

static void c44_error(SFc44_controller_templateInstanceStruct *chartInstance)
{
  int32_T c44_i270;
  static char_T c44_varargin_1[34] = { 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    ' ', 'R', 'o', 'p', 't', '[', 'n', 'u', ',', 'n', 'u', ']', ' ', 's', 'q',
    'u', 'a', 'r', 'e', ' ', 'm', 'a', 't', 'r', 'i', 'x' };

  char_T c44_u[34];
  const mxArray *c44_y = NULL;
  for (c44_i270 = 0; c44_i270 < 34; c44_i270++) {
    c44_u[c44_i270] = c44_varargin_1[c44_i270];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 10, 0U, 1U, 0U, 2, 1, 34),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, c44_y);
}

static void c44_b_error(SFc44_controller_templateInstanceStruct *chartInstance)
{
  int32_T c44_i271;
  static char_T c44_varargin_1[34] = { 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    ' ', 'Q', 'o', 'p', 't', '[', 'n', 'x', ',', 'n', 'x', ']', ' ', 's', 'q',
    'u', 'a', 'r', 'e', ' ', 'm', 'a', 't', 'r', 'i', 'x' };

  char_T c44_u[34];
  const mxArray *c44_y = NULL;
  for (c44_i271 = 0; c44_i271 < 34; c44_i271++) {
    c44_u[c44_i271] = c44_varargin_1[c44_i271];
  }

  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", c44_u, 10, 0U, 1U, 0U, 2, 1, 34),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, c44_y);
}

static boolean_T c44_all(SFc44_controller_templateInstanceStruct *chartInstance,
  boolean_T c44_x[5])
{
  boolean_T c44_y;
  int32_T c44_k;
  real_T c44_b_k;
  boolean_T exitg1;
  c44_y = TRUE;
  c44_k = 0;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (c44_k < 5)) {
    c44_b_k = 1.0 + (real_T)c44_k;
    if ((real_T)c44_x[(int32_T)c44_b_k - 1] == 0.0) {
      c44_y = FALSE;
      exitg1 = 1U;
    } else {
      c44_k++;
    }
  }

  return c44_y;
}

static void c44_eml_xgemm(SFc44_controller_templateInstanceStruct *chartInstance,
  int32_T c44_k, real_T c44_A_data[2], int32_T c44_A_sizes[2], real_T c44_B[4],
  int32_T c44_ldb, real_T c44_C[2], real_T c44_b_C[2])
{
  int32_T c44_i272;
  int32_T c44_b_A_sizes[2];
  int32_T c44_A;
  int32_T c44_b_A;
  int32_T c44_loop_ub;
  int32_T c44_i273;
  real_T c44_b_A_data[2];
  int32_T c44_i274;
  real_T c44_b_B[4];
  for (c44_i272 = 0; c44_i272 < 2; c44_i272++) {
    c44_b_C[c44_i272] = c44_C[c44_i272];
  }

  c44_b_A_sizes[0] = 1;
  c44_b_A_sizes[1] = 2;
  c44_A = c44_b_A_sizes[0];
  c44_b_A = c44_b_A_sizes[1];
  c44_loop_ub = c44_A_sizes[0] * c44_A_sizes[1] - 1;
  for (c44_i273 = 0; c44_i273 <= c44_loop_ub; c44_i273++) {
    c44_b_A_data[c44_i273] = c44_A_data[c44_i273];
  }

  for (c44_i274 = 0; c44_i274 < 4; c44_i274++) {
    c44_b_B[c44_i274] = c44_B[c44_i274];
  }

  c44_b_eml_xgemm(chartInstance, c44_k, c44_b_A_data, c44_b_A_sizes, c44_b_B,
                  c44_ldb, c44_b_C);
}

static const mxArray *c44_v_sf_marshallOut(void *chartInstanceVoid, void
  *c44_inData)
{
  const mxArray *c44_mxArrayOutData = NULL;
  int32_T c44_u;
  const mxArray *c44_y = NULL;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_mxArrayOutData = NULL;
  c44_u = *(int32_T *)c44_inData;
  c44_y = NULL;
  sf_mex_assign(&c44_y, sf_mex_create("y", &c44_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c44_mxArrayOutData, c44_y, FALSE);
  return c44_mxArrayOutData;
}

static int32_T c44_t_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId)
{
  int32_T c44_y;
  int32_T c44_i275;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), &c44_i275, 1, 6, 0U, 0, 0U, 0);
  c44_y = c44_i275;
  sf_mex_destroy(&c44_u);
  return c44_y;
}

static void c44_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c44_mxArrayInData, const char_T *c44_varName, void *c44_outData)
{
  const mxArray *c44_sfEvent;
  const char_T *c44_identifier;
  emlrtMsgIdentifier c44_thisId;
  int32_T c44_y;
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)chartInstanceVoid;
  c44_sfEvent = sf_mex_dup(c44_mxArrayInData);
  c44_identifier = c44_varName;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c44_sfEvent),
    &c44_thisId);
  sf_mex_destroy(&c44_sfEvent);
  *(int32_T *)c44_outData = c44_y;
  sf_mex_destroy(&c44_mxArrayInData);
}

static uint8_T c44_u_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_is_active_c44_controller_template, const
  char_T *c44_identifier)
{
  uint8_T c44_y;
  emlrtMsgIdentifier c44_thisId;
  c44_thisId.fIdentifier = c44_identifier;
  c44_thisId.fParent = NULL;
  c44_y = c44_v_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c44_is_active_c44_controller_template), &c44_thisId);
  sf_mex_destroy(&c44_is_active_c44_controller_template);
  return c44_y;
}

static uint8_T c44_v_emlrt_marshallIn(SFc44_controller_templateInstanceStruct
  *chartInstance, const mxArray *c44_u, const emlrtMsgIdentifier *c44_parentId)
{
  uint8_T c44_y;
  uint8_T c44_u0;
  sf_mex_import(c44_parentId, sf_mex_dup(c44_u), &c44_u0, 1, 3, 0U, 0, 0U, 0);
  c44_y = c44_u0;
  sf_mex_destroy(&c44_u);
  return c44_y;
}

static void c44_b_eml_xgemm(SFc44_controller_templateInstanceStruct
  *chartInstance, int32_T c44_k, real_T c44_A_data[2], int32_T c44_A_sizes[2],
  real_T c44_B[4], int32_T c44_ldb, real_T c44_C[2])
{
  int32_T c44_m;
  int32_T c44_n;
  int32_T c44_b_k;
  real_T c44_alpha1;
  int32_T c44_lda;
  int32_T c44_b_ldb;
  real_T c44_beta1;
  int32_T c44_ldc;
  char_T c44_TRANSA;
  char_T c44_TRANSB;
  c44_m = 1;
  c44_n = 2;
  c44_b_k = 2;
  c44_alpha1 = 1.0;
  c44_lda = 1;
  c44_b_ldb = 2;
  c44_beta1 = 0.0;
  c44_ldc = 1;
  c44_TRANSA = 'N';
  c44_TRANSB = 'N';
  dgemm32(&c44_TRANSA, &c44_TRANSB, &c44_m, &c44_n, &c44_b_k, &c44_alpha1,
          &c44_A_data[0], &c44_lda, &c44_B[0], &c44_b_ldb, &c44_beta1, &c44_C[0],
          &c44_ldc);
}

static void init_dsm_address_info(SFc44_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c44_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3701867233U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3360931324U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(180392877U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1470154548U);
}

mxArray *sf_c44_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("eJXzSAKxh41fNjilIByyUE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,17,3,dataFields);

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
      pr[0] = (double)(2);
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
      pr[0] = (double)(18999);
      pr[1] = (double)(4);
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
      pr[0] = (double)(18999);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      pr[1] = (double)(4);
      pr[2] = (double)(2303);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(4);
      pr[2] = (double)(2303);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      pr[2] = (double)(2303);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(4);
      pr[2] = (double)(2303);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      pr[2] = (double)(2303);
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
      pr[0] = (double)(2303);
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
      pr[0] = (double)(4);
      pr[1] = (double)(4);
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
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(6);
      pr[2] = (double)(2);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(5);
      pr[1] = (double)(1);
      pr[2] = (double)(2);
      mxSetField(mxData,16,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,16,"type",mxType);
    }

    mxSetField(mxData,16,"complexity",mxCreateDoubleScalar(0));
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

static const mxArray *sf_get_sim_state_info_c44_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[25],T\"M\",},{M[1],M[5],T\"U_x\",},{M[1],M[23],T\"U_y\",},{M[1],M[24],T\"flag_oob\",},{M[8],M[0],T\"is_active_c44_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c44_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc44_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc44_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           44,
           1,
           1,
           21,
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
          init_script_number_translation(_controller_templateMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_controller_templateMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_controller_templateMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"state_cur");
          _SFD_SET_DATA_PROPS(1,2,0,1,"U_x");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Uprev");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Mprev");
          _SFD_SET_DATA_PROPS(4,1,1,0,"nx");
          _SFD_SET_DATA_PROPS(5,1,1,0,"nu");
          _SFD_SET_DATA_PROPS(6,1,1,0,"H");
          _SFD_SET_DATA_PROPS(7,1,1,0,"K");
          _SFD_SET_DATA_PROPS(8,1,1,0,"Hobj");
          _SFD_SET_DATA_PROPS(9,1,1,0,"Fobj");
          _SFD_SET_DATA_PROPS(10,1,1,0,"Gobj");
          _SFD_SET_DATA_PROPS(11,1,1,0,"F");
          _SFD_SET_DATA_PROPS(12,1,1,0,"G");
          _SFD_SET_DATA_PROPS(13,1,1,0,"Nc");
          _SFD_SET_DATA_PROPS(14,1,1,0,"Qopt");
          _SFD_SET_DATA_PROPS(15,1,1,0,"Ropt");
          _SFD_SET_DATA_PROPS(16,1,1,0,"Ml");
          _SFD_SET_DATA_PROPS(17,1,1,0,"Mr");
          _SFD_SET_DATA_PROPS(18,2,0,1,"U_y");
          _SFD_SET_DATA_PROPS(19,2,0,1,"flag_oob");
          _SFD_SET_DATA_PROPS(20,2,0,1,"M");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,262);
        _SFD_CV_INIT_SCRIPT(0,1,20,0,0,6,0,20,8);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"OptimalMPCInputExportC_vP",0,-1,4504);
        _SFD_CV_INIT_SCRIPT_IF(0,0,202,262,-1,315);
        _SFD_CV_INIT_SCRIPT_IF(0,1,367,425,-1,464);
        _SFD_CV_INIT_SCRIPT_IF(0,2,498,558,-1,611);
        _SFD_CV_INIT_SCRIPT_IF(0,3,646,706,-1,759);
        _SFD_CV_INIT_SCRIPT_IF(0,4,848,869,-1,947);
        _SFD_CV_INIT_SCRIPT_IF(0,5,982,1016,-1,1064);
        _SFD_CV_INIT_SCRIPT_IF(0,6,1099,1134,-1,1181);
        _SFD_CV_INIT_SCRIPT_IF(0,7,1234,1271,-1,1321);
        _SFD_CV_INIT_SCRIPT_IF(0,8,1399,1431,1526,1732);
        _SFD_CV_INIT_SCRIPT_IF(0,9,1526,1578,1594,1732);
        _SFD_CV_INIT_SCRIPT_IF(0,10,1623,1669,-1,-2);
        _SFD_CV_INIT_SCRIPT_IF(0,11,1733,1740,-1,-2);
        _SFD_CV_INIT_SCRIPT_IF(0,12,2652,2683,-1,2768);
        _SFD_CV_INIT_SCRIPT_IF(0,13,2786,2810,-1,2870);
        _SFD_CV_INIT_SCRIPT_IF(0,14,2911,2929,-1,4114);
        _SFD_CV_INIT_SCRIPT_IF(0,15,3874,3888,3946,3965);
        _SFD_CV_INIT_SCRIPT_IF(0,16,3946,3965,-1,3965);
        _SFD_CV_INIT_SCRIPT_IF(0,17,3978,4010,-1,4080);
        _SFD_CV_INIT_SCRIPT_IF(0,18,4119,4134,4168,4306);
        _SFD_CV_INIT_SCRIPT_IF(0,19,4168,4181,4265,4306);
        _SFD_CV_INIT_SCRIPT_FOR(0,0,1603,1615,1728);
        _SFD_CV_INIT_SCRIPT_FOR(0,1,2120,2136,4118);
        _SFD_CV_INIT_SCRIPT_FOR(0,2,2248,2267,2356);
        _SFD_CV_INIT_SCRIPT_FOR(0,3,2276,2290,2347);
        _SFD_CV_INIT_SCRIPT_FOR(0,4,2424,2443,2490);
        _SFD_CV_INIT_SCRIPT_FOR(0,5,2605,2619,2776);

        {
          static int condStart[] = { 206, 230, 248 };

          static int condEnd[] = { 224, 242, 261 };

          static int pfixExpr[] = { 0, 1, -2, 2, -2 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,0,205,262,3,0,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 371, 391, 410 };

          static int condEnd[] = { 385, 404, 424 };

          static int pfixExpr[] = { 0, 1, -2, 2, -2 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,1,370,425,3,3,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 502, 526, 544 };

          static int condEnd[] = { 520, 538, 557 };

          static int pfixExpr[] = { 0, 1, -2, 2, -2 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,2,501,558,3,6,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 650, 674, 692 };

          static int condEnd[] = { 668, 686, 705 };

          static int pfixExpr[] = { 0, 1, -2, 2, -2 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,3,649,706,3,9,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 986, 1002 };

          static int condEnd[] = { 996, 1015 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,4,985,1016,2,12,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1103, 1121 };

          static int condEnd[] = { 1115, 1133 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,5,1102,1134,2,14,&(condStart[0]),&(condEnd
            [0]),3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1238, 1257 };

          static int condEnd[] = { 1251, 1270 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,6,1237,1271,2,16,&(condStart[0]),&(condEnd
            [0]),3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1403, 1420 };

          static int condEnd[] = { 1412, 1430 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,7,1402,1431,2,18,&(condStart[0]),&(condEnd
            [0]),3,&(pfixExpr[0]));
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
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_o_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_n_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 18999;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_m_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 18999;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_l_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 4;
          dimVector[1]= 4;
          dimVector[2]= 2303;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_k_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 1;
          dimVector[1]= 4;
          dimVector[2]= 2303;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_j_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 1;
          dimVector[1]= 1;
          dimVector[2]= 2303;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_i_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 2;
          dimVector[1]= 4;
          dimVector[2]= 2303;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_h_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 2;
          dimVector[1]= 1;
          dimVector[2]= 2303;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2303;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 5;
          dimVector[1]= 6;
          dimVector[2]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[3];
          dimVector[0]= 5;
          dimVector[1]= 1;
          dimVector[2]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c44_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c44_sf_marshallOut,(MexInFcnForType)c44_sf_marshallIn);

        {
          real_T *c44_U_x;
          real_T *c44_Mprev;
          real_T *c44_nx;
          real_T *c44_nu;
          real_T *c44_U_y;
          real_T *c44_flag_oob;
          real_T *c44_M;
          real_T (*c44_state_cur)[4];
          real_T (*c44_Uprev)[2];
          real_T (*c44_H)[75996];
          real_T (*c44_K)[18999];
          real_T (*c44_Hobj)[36848];
          real_T (*c44_Fobj)[9212];
          real_T (*c44_Gobj)[2303];
          real_T (*c44_F)[18424];
          real_T (*c44_G)[4606];
          real_T (*c44_Nc)[2303];
          real_T (*c44_Qopt)[16];
          real_T (*c44_Ropt)[4];
          real_T (*c44_Ml)[60];
          real_T (*c44_Mr)[10];
          c44_M = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c44_flag_oob = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c44_U_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c44_Mr = (real_T (*)[10])ssGetInputPortSignal(chartInstance->S, 16);
          c44_Ml = (real_T (*)[60])ssGetInputPortSignal(chartInstance->S, 15);
          c44_Ropt = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 14);
          c44_Qopt = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 13);
          c44_Nc = (real_T (*)[2303])ssGetInputPortSignal(chartInstance->S, 12);
          c44_G = (real_T (*)[4606])ssGetInputPortSignal(chartInstance->S, 11);
          c44_F = (real_T (*)[18424])ssGetInputPortSignal(chartInstance->S, 10);
          c44_Gobj = (real_T (*)[2303])ssGetInputPortSignal(chartInstance->S, 9);
          c44_Fobj = (real_T (*)[9212])ssGetInputPortSignal(chartInstance->S, 8);
          c44_Hobj = (real_T (*)[36848])ssGetInputPortSignal(chartInstance->S, 7);
          c44_K = (real_T (*)[18999])ssGetInputPortSignal(chartInstance->S, 6);
          c44_H = (real_T (*)[75996])ssGetInputPortSignal(chartInstance->S, 5);
          c44_nu = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c44_nx = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c44_Mprev = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c44_Uprev = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 1);
          c44_U_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c44_state_cur = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c44_state_cur);
          _SFD_SET_DATA_VALUE_PTR(1U, c44_U_x);
          _SFD_SET_DATA_VALUE_PTR(2U, *c44_Uprev);
          _SFD_SET_DATA_VALUE_PTR(3U, c44_Mprev);
          _SFD_SET_DATA_VALUE_PTR(4U, c44_nx);
          _SFD_SET_DATA_VALUE_PTR(5U, c44_nu);
          _SFD_SET_DATA_VALUE_PTR(6U, *c44_H);
          _SFD_SET_DATA_VALUE_PTR(7U, *c44_K);
          _SFD_SET_DATA_VALUE_PTR(8U, *c44_Hobj);
          _SFD_SET_DATA_VALUE_PTR(9U, *c44_Fobj);
          _SFD_SET_DATA_VALUE_PTR(10U, *c44_Gobj);
          _SFD_SET_DATA_VALUE_PTR(11U, *c44_F);
          _SFD_SET_DATA_VALUE_PTR(12U, *c44_G);
          _SFD_SET_DATA_VALUE_PTR(13U, *c44_Nc);
          _SFD_SET_DATA_VALUE_PTR(14U, *c44_Qopt);
          _SFD_SET_DATA_VALUE_PTR(15U, *c44_Ropt);
          _SFD_SET_DATA_VALUE_PTR(16U, *c44_Ml);
          _SFD_SET_DATA_VALUE_PTR(17U, *c44_Mr);
          _SFD_SET_DATA_VALUE_PTR(18U, c44_U_y);
          _SFD_SET_DATA_VALUE_PTR(19U, c44_flag_oob);
          _SFD_SET_DATA_VALUE_PTR(20U, c44_M);
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
      44, "dworkChecksum");
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

static void sf_opaque_initialize_c44_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc44_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc44_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c44_controller_template
    ((SFc44_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c44_controller_template((SFc44_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c44_controller_template(void *chartInstanceVar)
{
  enable_c44_controller_template((SFc44_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c44_controller_template(void *chartInstanceVar)
{
  disable_c44_controller_template((SFc44_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c44_controller_template(void *chartInstanceVar)
{
  sf_c44_controller_template((SFc44_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c44_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c44_controller_template((SFc44_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c44_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c44_controller_template
    ((SFc44_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c44_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c44_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c44_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c44_controller_template((SFc44_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c44_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c44_controller_template(S);
}

static void sf_opaque_set_sim_state_c44_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c44_controller_template(S, st);
}

static void sf_opaque_terminate_c44_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc44_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c44_controller_template((SFc44_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc44_controller_template((SFc44_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c44_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c44_controller_template
      ((SFc44_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c44_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c44_controller_template\",T\"is_active_c44_controller_template\"}}"
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

static void mdlSetWorkWidths_c44_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,44);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,44,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,44,
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
      ssSetInputPortOptimOpts(S, 16, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,44,17);
      sf_mark_chart_reusable_outputs(S,infoStruct,44,4);
    }

    sf_set_rtw_dwork_info(S,infoStruct,44);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1239210325U));
  ssSetChecksum1(S,(390548317U));
  ssSetChecksum2(S,(1320896500U));
  ssSetChecksum3(S,(4189075309U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c44_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c44_controller_template(SimStruct *S)
{
  SFc44_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc44_controller_templateInstanceStruct *)malloc(sizeof
    (SFc44_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc44_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c44_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c44_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c44_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c44_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c44_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c44_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c44_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c44_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c44_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c44_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c44_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c44_controller_template;
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

void c44_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c44_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c44_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c44_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c44_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
