/* Include files */

#include "blascompat32.h"
#include "controller_template_rectangle_sfun.h"
#include "c29_controller_template_rectangle.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_rectangle_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c29_debug_family_names[18] = { "n", "x_", "P_", "K",
  "nargin", "nargout", "A", "B", "C", "D", "Q", "R", "u", "y", "P", "state",
  "state_est", "P_est" };

/* Function Declarations */
static void initialize_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void initialize_params_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void enable_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void disable_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void c29_update_debugger_state_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void ext_mode_exec_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void set_sim_state_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_st);
static void finalize_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void sf_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void c29_chartstep_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void initSimStructsc29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber);
static const mxArray *c29_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static void c29_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_P_est, const char_T *c29_identifier, real_T c29_y[9]);
static void c29_b_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[9]);
static void c29_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static const mxArray *c29_b_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static void c29_c_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_state_est, const char_T *c29_identifier, real_T c29_y[3]);
static void c29_d_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[3]);
static void c29_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static const mxArray *c29_c_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static const mxArray *c29_d_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static const mxArray *c29_e_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static const mxArray *c29_f_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static real_T c29_e_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId);
static void c29_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static const mxArray *c29_g_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static void c29_f_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[6]);
static void c29_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static void c29_info_helper(c29_ResolvedFunctionInfo c29_info[29]);
static void c29_eml_scalar_eg(SFc29_controller_template_rectangleInstanceStruct *
  chartInstance);
static void c29_b_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void c29_c_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void c29_d_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void c29_e_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void c29_mpower(SFc29_controller_template_rectangleInstanceStruct
  *chartInstance, real_T c29_a[4], real_T c29_c[4]);
static void c29_matrix_to_integer_power
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, real_T
   c29_a[4], real_T c29_b, real_T c29_c[4]);
static void c29_f_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void c29_g_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static real_T c29_norm(SFc29_controller_template_rectangleInstanceStruct
  *chartInstance, real_T c29_x[4]);
static void c29_eml_warning(SFc29_controller_template_rectangleInstanceStruct
  *chartInstance);
static void c29_b_eml_warning(SFc29_controller_template_rectangleInstanceStruct *
  chartInstance, char_T c29_varargin_2[14]);
static void c29_h_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void c29_i_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void c29_j_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void c29_eye(SFc29_controller_template_rectangleInstanceStruct
                    *chartInstance, real_T c29_I[9]);
static void c29_k_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);
static void c29_g_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_sprintf, const char_T *c29_identifier, char_T c29_y[14]);
static void c29_h_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, char_T c29_y[14]);
static const mxArray *c29_h_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData);
static int32_T c29_i_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId);
static void c29_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData);
static uint8_T c29_j_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_is_active_c29_controller_template_rectangle, const char_T
   *c29_identifier);
static uint8_T c29_k_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId);
static void init_dsm_address_info
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
  int32_T *c29_sfEvent;
  uint8_T *c29_is_active_c29_controller_template_rectangle;
  c29_is_active_c29_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c29_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c29_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c29_is_active_c29_controller_template_rectangle = 0U;
}

static void initialize_params_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void enable_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c29_update_debugger_state_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
  c29_update_debugger_state_c29_controller_template_rectangle(chartInstance);
}

static const mxArray *get_sim_state_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
  const mxArray *c29_st;
  const mxArray *c29_y = NULL;
  int32_T c29_i0;
  real_T c29_u[9];
  const mxArray *c29_b_y = NULL;
  int32_T c29_i1;
  real_T c29_b_u[3];
  const mxArray *c29_c_y = NULL;
  uint8_T c29_hoistedGlobal;
  uint8_T c29_c_u;
  const mxArray *c29_d_y = NULL;
  uint8_T *c29_is_active_c29_controller_template_rectangle;
  real_T (*c29_state_est)[3];
  real_T (*c29_P_est)[9];
  c29_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c29_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c29_is_active_c29_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c29_st = NULL;
  c29_st = NULL;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_createcellarray(3), FALSE);
  for (c29_i0 = 0; c29_i0 < 9; c29_i0++) {
    c29_u[c29_i0] = (*c29_P_est)[c29_i0];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 2, 3, 3),
                FALSE);
  sf_mex_setcell(c29_y, 0, c29_b_y);
  for (c29_i1 = 0; c29_i1 < 3; c29_i1++) {
    c29_b_u[c29_i1] = (*c29_state_est)[c29_i1];
  }

  c29_c_y = NULL;
  sf_mex_assign(&c29_c_y, sf_mex_create("y", c29_b_u, 0, 0U, 1U, 0U, 1, 3),
                FALSE);
  sf_mex_setcell(c29_y, 1, c29_c_y);
  c29_hoistedGlobal = *c29_is_active_c29_controller_template_rectangle;
  c29_c_u = c29_hoistedGlobal;
  c29_d_y = NULL;
  sf_mex_assign(&c29_d_y, sf_mex_create("y", &c29_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c29_y, 2, c29_d_y);
  sf_mex_assign(&c29_st, c29_y, FALSE);
  return c29_st;
}

static void set_sim_state_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_st)
{
  const mxArray *c29_u;
  real_T c29_dv0[9];
  int32_T c29_i2;
  real_T c29_dv1[3];
  int32_T c29_i3;
  boolean_T *c29_doneDoubleBufferReInit;
  uint8_T *c29_is_active_c29_controller_template_rectangle;
  real_T (*c29_P_est)[9];
  real_T (*c29_state_est)[3];
  c29_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c29_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c29_is_active_c29_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c29_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c29_doneDoubleBufferReInit = TRUE;
  c29_u = sf_mex_dup(c29_st);
  c29_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c29_u, 0)),
                       "P_est", c29_dv0);
  for (c29_i2 = 0; c29_i2 < 9; c29_i2++) {
    (*c29_P_est)[c29_i2] = c29_dv0[c29_i2];
  }

  c29_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c29_u, 1)),
    "state_est", c29_dv1);
  for (c29_i3 = 0; c29_i3 < 3; c29_i3++) {
    (*c29_state_est)[c29_i3] = c29_dv1[c29_i3];
  }

  *c29_is_active_c29_controller_template_rectangle = c29_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c29_u, 2)),
     "is_active_c29_controller_template_rectangle");
  sf_mex_destroy(&c29_u);
  c29_update_debugger_state_c29_controller_template_rectangle(chartInstance);
  sf_mex_destroy(&c29_st);
}

static void finalize_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void sf_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
  int32_T c29_i4;
  int32_T c29_i5;
  int32_T c29_i6;
  int32_T c29_i7;
  int32_T c29_i8;
  int32_T c29_i9;
  int32_T c29_i10;
  int32_T c29_i11;
  int32_T c29_i12;
  int32_T c29_i13;
  int32_T c29_i14;
  int32_T *c29_sfEvent;
  real_T *c29_u;
  real_T (*c29_P_est)[9];
  real_T (*c29_state)[3];
  real_T (*c29_P)[9];
  real_T (*c29_y)[2];
  real_T (*c29_R)[4];
  real_T (*c29_Q)[9];
  real_T (*c29_D)[2];
  real_T (*c29_C)[6];
  real_T (*c29_state_est)[3];
  real_T (*c29_B)[3];
  real_T (*c29_A)[9];
  c29_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c29_state = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c29_P = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 8);
  c29_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 7);
  c29_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c29_R = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
  c29_Q = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c29_D = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 3);
  c29_C = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c29_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c29_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c29_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c29_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 28U, *c29_sfEvent);
  for (c29_i4 = 0; c29_i4 < 9; c29_i4++) {
    _SFD_DATA_RANGE_CHECK((*c29_A)[c29_i4], 0U);
  }

  for (c29_i5 = 0; c29_i5 < 3; c29_i5++) {
    _SFD_DATA_RANGE_CHECK((*c29_B)[c29_i5], 1U);
  }

  for (c29_i6 = 0; c29_i6 < 3; c29_i6++) {
    _SFD_DATA_RANGE_CHECK((*c29_state_est)[c29_i6], 2U);
  }

  for (c29_i7 = 0; c29_i7 < 6; c29_i7++) {
    _SFD_DATA_RANGE_CHECK((*c29_C)[c29_i7], 3U);
  }

  for (c29_i8 = 0; c29_i8 < 2; c29_i8++) {
    _SFD_DATA_RANGE_CHECK((*c29_D)[c29_i8], 4U);
  }

  for (c29_i9 = 0; c29_i9 < 9; c29_i9++) {
    _SFD_DATA_RANGE_CHECK((*c29_Q)[c29_i9], 5U);
  }

  for (c29_i10 = 0; c29_i10 < 4; c29_i10++) {
    _SFD_DATA_RANGE_CHECK((*c29_R)[c29_i10], 6U);
  }

  _SFD_DATA_RANGE_CHECK(*c29_u, 7U);
  for (c29_i11 = 0; c29_i11 < 2; c29_i11++) {
    _SFD_DATA_RANGE_CHECK((*c29_y)[c29_i11], 8U);
  }

  for (c29_i12 = 0; c29_i12 < 9; c29_i12++) {
    _SFD_DATA_RANGE_CHECK((*c29_P)[c29_i12], 9U);
  }

  for (c29_i13 = 0; c29_i13 < 3; c29_i13++) {
    _SFD_DATA_RANGE_CHECK((*c29_state)[c29_i13], 10U);
  }

  for (c29_i14 = 0; c29_i14 < 9; c29_i14++) {
    _SFD_DATA_RANGE_CHECK((*c29_P_est)[c29_i14], 11U);
  }

  *c29_sfEvent = CALL_EVENT;
  c29_chartstep_c29_controller_template_rectangle(chartInstance);
  sf_debug_check_for_state_inconsistency
    (_controller_template_rectangleMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void c29_chartstep_c29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
  real_T c29_hoistedGlobal;
  int32_T c29_i15;
  real_T c29_A[9];
  int32_T c29_i16;
  real_T c29_B[3];
  int32_T c29_i17;
  real_T c29_C[6];
  int32_T c29_i18;
  real_T c29_D[2];
  int32_T c29_i19;
  real_T c29_Q[9];
  int32_T c29_i20;
  real_T c29_R[4];
  real_T c29_u;
  int32_T c29_i21;
  real_T c29_y[2];
  int32_T c29_i22;
  real_T c29_P[9];
  int32_T c29_i23;
  real_T c29_state[3];
  uint32_T c29_debug_family_var_map[18];
  real_T c29_n;
  real_T c29_x_[3];
  real_T c29_P_[9];
  real_T c29_K[6];
  real_T c29_nargin = 10.0;
  real_T c29_nargout = 2.0;
  real_T c29_state_est[3];
  real_T c29_P_est[9];
  int32_T c29_i24;
  real_T c29_a[9];
  int32_T c29_i25;
  real_T c29_b[3];
  int32_T c29_i26;
  real_T c29_b_y[3];
  int32_T c29_i27;
  int32_T c29_i28;
  int32_T c29_i29;
  real_T c29_b_b;
  int32_T c29_i30;
  int32_T c29_i31;
  int32_T c29_i32;
  int32_T c29_i33;
  real_T c29_c_b[9];
  int32_T c29_i34;
  int32_T c29_i35;
  int32_T c29_i36;
  real_T c29_c_y[9];
  int32_T c29_i37;
  int32_T c29_i38;
  int32_T c29_i39;
  int32_T c29_i40;
  int32_T c29_i41;
  int32_T c29_i42;
  int32_T c29_i43;
  int32_T c29_i44;
  int32_T c29_i45;
  real_T c29_d_y[9];
  int32_T c29_i46;
  int32_T c29_i47;
  int32_T c29_i48;
  int32_T c29_i49;
  int32_T c29_i50;
  int32_T c29_i51;
  int32_T c29_i52;
  int32_T c29_i53;
  real_T c29_d_b[6];
  int32_T c29_i54;
  int32_T c29_i55;
  int32_T c29_i56;
  real_T c29_e_y[6];
  int32_T c29_i57;
  int32_T c29_i58;
  int32_T c29_i59;
  real_T c29_b_a[6];
  int32_T c29_i60;
  int32_T c29_i61;
  int32_T c29_i62;
  int32_T c29_i63;
  int32_T c29_i64;
  real_T c29_f_y[6];
  int32_T c29_i65;
  int32_T c29_i66;
  int32_T c29_i67;
  int32_T c29_i68;
  int32_T c29_i69;
  int32_T c29_i70;
  int32_T c29_i71;
  int32_T c29_i72;
  int32_T c29_i73;
  int32_T c29_i74;
  real_T c29_g_y[4];
  int32_T c29_i75;
  int32_T c29_i76;
  int32_T c29_i77;
  real_T c29_h_y[4];
  int32_T c29_i78;
  int32_T c29_i79;
  int32_T c29_i80;
  int32_T c29_i81;
  int32_T c29_i82;
  int32_T c29_i83;
  int32_T c29_i84;
  int32_T c29_i85;
  int32_T c29_i86;
  int32_T c29_i87;
  int32_T c29_i88;
  int32_T c29_i89;
  int32_T c29_i90;
  int32_T c29_i91;
  int32_T c29_i92;
  real_T c29_i_y[2];
  int32_T c29_i93;
  int32_T c29_i94;
  int32_T c29_i95;
  int32_T c29_i96;
  int32_T c29_i97;
  int32_T c29_i98;
  int32_T c29_i99;
  int32_T c29_i100;
  int32_T c29_i101;
  int32_T c29_i102;
  int32_T c29_i103;
  int32_T c29_i104;
  int32_T c29_i105;
  int32_T c29_i106;
  int32_T c29_i107;
  int32_T c29_i108;
  int32_T c29_i109;
  int32_T c29_i110;
  int32_T c29_i111;
  int32_T c29_i112;
  int32_T c29_i113;
  int32_T c29_i114;
  int32_T c29_i115;
  int32_T c29_i116;
  int32_T c29_i117;
  int32_T c29_i118;
  int32_T c29_i119;
  int32_T c29_i120;
  int32_T c29_i121;
  int32_T c29_i122;
  int32_T c29_i123;
  real_T *c29_b_u;
  real_T (*c29_b_state_est)[3];
  real_T (*c29_b_P_est)[9];
  real_T (*c29_b_state)[3];
  real_T (*c29_b_P)[9];
  real_T (*c29_j_y)[2];
  real_T (*c29_b_R)[4];
  real_T (*c29_b_Q)[9];
  real_T (*c29_b_D)[2];
  real_T (*c29_b_C)[6];
  real_T (*c29_b_B)[3];
  real_T (*c29_b_A)[9];
  int32_T *c29_sfEvent;
  c29_b_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
  c29_b_state = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
  c29_b_P = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 8);
  c29_j_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 7);
  c29_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
  c29_b_R = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
  c29_b_Q = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
  c29_b_D = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 3);
  c29_b_C = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
  c29_b_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S, 1);
  c29_b_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
  c29_b_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
  c29_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 28U, *c29_sfEvent);
  c29_hoistedGlobal = *c29_b_u;
  for (c29_i15 = 0; c29_i15 < 9; c29_i15++) {
    c29_A[c29_i15] = (*c29_b_A)[c29_i15];
  }

  for (c29_i16 = 0; c29_i16 < 3; c29_i16++) {
    c29_B[c29_i16] = (*c29_b_B)[c29_i16];
  }

  for (c29_i17 = 0; c29_i17 < 6; c29_i17++) {
    c29_C[c29_i17] = (*c29_b_C)[c29_i17];
  }

  for (c29_i18 = 0; c29_i18 < 2; c29_i18++) {
    c29_D[c29_i18] = (*c29_b_D)[c29_i18];
  }

  for (c29_i19 = 0; c29_i19 < 9; c29_i19++) {
    c29_Q[c29_i19] = (*c29_b_Q)[c29_i19];
  }

  for (c29_i20 = 0; c29_i20 < 4; c29_i20++) {
    c29_R[c29_i20] = (*c29_b_R)[c29_i20];
  }

  c29_u = c29_hoistedGlobal;
  for (c29_i21 = 0; c29_i21 < 2; c29_i21++) {
    c29_y[c29_i21] = (*c29_j_y)[c29_i21];
  }

  for (c29_i22 = 0; c29_i22 < 9; c29_i22++) {
    c29_P[c29_i22] = (*c29_b_P)[c29_i22];
  }

  for (c29_i23 = 0; c29_i23 < 3; c29_i23++) {
    c29_state[c29_i23] = (*c29_b_state)[c29_i23];
  }

  sf_debug_symbol_scope_push_eml(0U, 18U, 18U, c29_debug_family_names,
    c29_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c29_n, 0U, c29_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c29_x_, 1U, c29_b_sf_marshallOut,
    c29_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c29_P_, 2U, c29_sf_marshallOut,
    c29_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c29_K, 3U, c29_g_sf_marshallOut,
    c29_d_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c29_nargin, 4U, c29_d_sf_marshallOut,
    c29_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c29_nargout, 5U,
    c29_d_sf_marshallOut, c29_c_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c29_A, 6U, c29_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c29_B, 7U, c29_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c29_C, 8U, c29_f_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c29_D, 9U, c29_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c29_Q, 10U, c29_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c29_R, 11U, c29_e_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c29_u, 12U, c29_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c29_y, 13U, c29_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c29_P, 14U, c29_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c29_state, 15U, c29_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c29_state_est, 16U,
    c29_b_sf_marshallOut, c29_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(c29_P_est, 17U, c29_sf_marshallOut,
    c29_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c29_sfEvent, 7);
  c29_n = 3.0;
  _SFD_EML_CALL(0U, *c29_sfEvent, 10);
  for (c29_i24 = 0; c29_i24 < 9; c29_i24++) {
    c29_a[c29_i24] = c29_A[c29_i24];
  }

  for (c29_i25 = 0; c29_i25 < 3; c29_i25++) {
    c29_b[c29_i25] = c29_state[c29_i25];
  }

  c29_eml_scalar_eg(chartInstance);
  c29_eml_scalar_eg(chartInstance);
  for (c29_i26 = 0; c29_i26 < 3; c29_i26++) {
    c29_b_y[c29_i26] = 0.0;
    c29_i27 = 0;
    for (c29_i28 = 0; c29_i28 < 3; c29_i28++) {
      c29_b_y[c29_i26] += c29_a[c29_i27 + c29_i26] * c29_b[c29_i28];
      c29_i27 += 3;
    }
  }

  for (c29_i29 = 0; c29_i29 < 3; c29_i29++) {
    c29_b[c29_i29] = c29_B[c29_i29];
  }

  c29_b_b = c29_u;
  for (c29_i30 = 0; c29_i30 < 3; c29_i30++) {
    c29_b[c29_i30] *= c29_b_b;
  }

  for (c29_i31 = 0; c29_i31 < 3; c29_i31++) {
    c29_x_[c29_i31] = c29_b_y[c29_i31] + c29_b[c29_i31];
  }

  _SFD_EML_CALL(0U, *c29_sfEvent, 11);
  for (c29_i32 = 0; c29_i32 < 9; c29_i32++) {
    c29_a[c29_i32] = c29_A[c29_i32];
  }

  for (c29_i33 = 0; c29_i33 < 9; c29_i33++) {
    c29_c_b[c29_i33] = c29_P[c29_i33];
  }

  c29_b_eml_scalar_eg(chartInstance);
  c29_b_eml_scalar_eg(chartInstance);
  for (c29_i34 = 0; c29_i34 < 3; c29_i34++) {
    c29_i35 = 0;
    for (c29_i36 = 0; c29_i36 < 3; c29_i36++) {
      c29_c_y[c29_i35 + c29_i34] = 0.0;
      c29_i37 = 0;
      for (c29_i38 = 0; c29_i38 < 3; c29_i38++) {
        c29_c_y[c29_i35 + c29_i34] += c29_a[c29_i37 + c29_i34] * c29_c_b[c29_i38
          + c29_i35];
        c29_i37 += 3;
      }

      c29_i35 += 3;
    }
  }

  c29_i39 = 0;
  for (c29_i40 = 0; c29_i40 < 3; c29_i40++) {
    c29_i41 = 0;
    for (c29_i42 = 0; c29_i42 < 3; c29_i42++) {
      c29_c_b[c29_i42 + c29_i39] = c29_A[c29_i41 + c29_i40];
      c29_i41 += 3;
    }

    c29_i39 += 3;
  }

  c29_b_eml_scalar_eg(chartInstance);
  c29_b_eml_scalar_eg(chartInstance);
  for (c29_i43 = 0; c29_i43 < 3; c29_i43++) {
    c29_i44 = 0;
    for (c29_i45 = 0; c29_i45 < 3; c29_i45++) {
      c29_d_y[c29_i44 + c29_i43] = 0.0;
      c29_i46 = 0;
      for (c29_i47 = 0; c29_i47 < 3; c29_i47++) {
        c29_d_y[c29_i44 + c29_i43] += c29_c_y[c29_i46 + c29_i43] *
          c29_c_b[c29_i47 + c29_i44];
        c29_i46 += 3;
      }

      c29_i44 += 3;
    }
  }

  for (c29_i48 = 0; c29_i48 < 9; c29_i48++) {
    c29_P_[c29_i48] = c29_d_y[c29_i48] + c29_Q[c29_i48];
  }

  _SFD_EML_CALL(0U, *c29_sfEvent, 14);
  for (c29_i49 = 0; c29_i49 < 9; c29_i49++) {
    c29_a[c29_i49] = c29_P_[c29_i49];
  }

  c29_i50 = 0;
  for (c29_i51 = 0; c29_i51 < 2; c29_i51++) {
    c29_i52 = 0;
    for (c29_i53 = 0; c29_i53 < 3; c29_i53++) {
      c29_d_b[c29_i53 + c29_i50] = c29_C[c29_i52 + c29_i51];
      c29_i52 += 2;
    }

    c29_i50 += 3;
  }

  c29_c_eml_scalar_eg(chartInstance);
  c29_c_eml_scalar_eg(chartInstance);
  for (c29_i54 = 0; c29_i54 < 3; c29_i54++) {
    c29_i55 = 0;
    for (c29_i56 = 0; c29_i56 < 2; c29_i56++) {
      c29_e_y[c29_i55 + c29_i54] = 0.0;
      c29_i57 = 0;
      for (c29_i58 = 0; c29_i58 < 3; c29_i58++) {
        c29_e_y[c29_i55 + c29_i54] += c29_a[c29_i57 + c29_i54] * c29_d_b[c29_i58
          + c29_i55];
        c29_i57 += 3;
      }

      c29_i55 += 3;
    }
  }

  for (c29_i59 = 0; c29_i59 < 6; c29_i59++) {
    c29_b_a[c29_i59] = c29_C[c29_i59];
  }

  for (c29_i60 = 0; c29_i60 < 9; c29_i60++) {
    c29_c_b[c29_i60] = c29_P_[c29_i60];
  }

  c29_d_eml_scalar_eg(chartInstance);
  c29_d_eml_scalar_eg(chartInstance);
  for (c29_i61 = 0; c29_i61 < 2; c29_i61++) {
    c29_i62 = 0;
    c29_i63 = 0;
    for (c29_i64 = 0; c29_i64 < 3; c29_i64++) {
      c29_f_y[c29_i62 + c29_i61] = 0.0;
      c29_i65 = 0;
      for (c29_i66 = 0; c29_i66 < 3; c29_i66++) {
        c29_f_y[c29_i62 + c29_i61] += c29_b_a[c29_i65 + c29_i61] *
          c29_c_b[c29_i66 + c29_i63];
        c29_i65 += 2;
      }

      c29_i62 += 2;
      c29_i63 += 3;
    }
  }

  c29_i67 = 0;
  for (c29_i68 = 0; c29_i68 < 2; c29_i68++) {
    c29_i69 = 0;
    for (c29_i70 = 0; c29_i70 < 3; c29_i70++) {
      c29_d_b[c29_i70 + c29_i67] = c29_C[c29_i69 + c29_i68];
      c29_i69 += 2;
    }

    c29_i67 += 3;
  }

  c29_e_eml_scalar_eg(chartInstance);
  c29_e_eml_scalar_eg(chartInstance);
  for (c29_i71 = 0; c29_i71 < 2; c29_i71++) {
    c29_i72 = 0;
    c29_i73 = 0;
    for (c29_i74 = 0; c29_i74 < 2; c29_i74++) {
      c29_g_y[c29_i72 + c29_i71] = 0.0;
      c29_i75 = 0;
      for (c29_i76 = 0; c29_i76 < 3; c29_i76++) {
        c29_g_y[c29_i72 + c29_i71] += c29_f_y[c29_i75 + c29_i71] *
          c29_d_b[c29_i76 + c29_i73];
        c29_i75 += 2;
      }

      c29_i72 += 2;
      c29_i73 += 3;
    }
  }

  for (c29_i77 = 0; c29_i77 < 4; c29_i77++) {
    c29_h_y[c29_i77] = c29_g_y[c29_i77] + c29_R[c29_i77];
  }

  c29_mpower(chartInstance, c29_h_y, c29_g_y);
  c29_h_eml_scalar_eg(chartInstance);
  c29_h_eml_scalar_eg(chartInstance);
  for (c29_i78 = 0; c29_i78 < 6; c29_i78++) {
    c29_K[c29_i78] = 0.0;
  }

  for (c29_i79 = 0; c29_i79 < 6; c29_i79++) {
    c29_K[c29_i79] = 0.0;
  }

  for (c29_i80 = 0; c29_i80 < 6; c29_i80++) {
    c29_d_b[c29_i80] = c29_K[c29_i80];
  }

  for (c29_i81 = 0; c29_i81 < 6; c29_i81++) {
    c29_K[c29_i81] = c29_d_b[c29_i81];
  }

  for (c29_i82 = 0; c29_i82 < 6; c29_i82++) {
    c29_d_b[c29_i82] = c29_K[c29_i82];
  }

  for (c29_i83 = 0; c29_i83 < 6; c29_i83++) {
    c29_K[c29_i83] = c29_d_b[c29_i83];
  }

  for (c29_i84 = 0; c29_i84 < 3; c29_i84++) {
    c29_i85 = 0;
    c29_i86 = 0;
    for (c29_i87 = 0; c29_i87 < 2; c29_i87++) {
      c29_K[c29_i85 + c29_i84] = 0.0;
      c29_i88 = 0;
      for (c29_i89 = 0; c29_i89 < 2; c29_i89++) {
        c29_K[c29_i85 + c29_i84] += c29_e_y[c29_i88 + c29_i84] * c29_g_y[c29_i89
          + c29_i86];
        c29_i88 += 3;
      }

      c29_i85 += 3;
      c29_i86 += 2;
    }
  }

  _SFD_EML_CALL(0U, *c29_sfEvent, 15);
  for (c29_i90 = 0; c29_i90 < 6; c29_i90++) {
    c29_b_a[c29_i90] = c29_C[c29_i90];
  }

  for (c29_i91 = 0; c29_i91 < 3; c29_i91++) {
    c29_b[c29_i91] = c29_x_[c29_i91];
  }

  c29_i_eml_scalar_eg(chartInstance);
  c29_i_eml_scalar_eg(chartInstance);
  for (c29_i92 = 0; c29_i92 < 2; c29_i92++) {
    c29_i_y[c29_i92] = 0.0;
    c29_i93 = 0;
    for (c29_i94 = 0; c29_i94 < 3; c29_i94++) {
      c29_i_y[c29_i92] += c29_b_a[c29_i93 + c29_i92] * c29_b[c29_i94];
      c29_i93 += 2;
    }
  }

  for (c29_i95 = 0; c29_i95 < 6; c29_i95++) {
    c29_d_b[c29_i95] = c29_K[c29_i95];
  }

  for (c29_i96 = 0; c29_i96 < 2; c29_i96++) {
    c29_i_y[c29_i96] = c29_y[c29_i96] - c29_i_y[c29_i96];
  }

  c29_j_eml_scalar_eg(chartInstance);
  c29_j_eml_scalar_eg(chartInstance);
  for (c29_i97 = 0; c29_i97 < 3; c29_i97++) {
    c29_b_y[c29_i97] = 0.0;
    c29_i98 = 0;
    for (c29_i99 = 0; c29_i99 < 2; c29_i99++) {
      c29_b_y[c29_i97] += c29_d_b[c29_i98 + c29_i97] * c29_i_y[c29_i99];
      c29_i98 += 3;
    }
  }

  for (c29_i100 = 0; c29_i100 < 3; c29_i100++) {
    c29_state_est[c29_i100] = c29_x_[c29_i100] + c29_b_y[c29_i100];
  }

  _SFD_EML_CALL(0U, *c29_sfEvent, 16);
  for (c29_i101 = 0; c29_i101 < 6; c29_i101++) {
    c29_d_b[c29_i101] = c29_K[c29_i101];
  }

  for (c29_i102 = 0; c29_i102 < 6; c29_i102++) {
    c29_b_a[c29_i102] = c29_C[c29_i102];
  }

  c29_k_eml_scalar_eg(chartInstance);
  c29_k_eml_scalar_eg(chartInstance);
  for (c29_i103 = 0; c29_i103 < 3; c29_i103++) {
    c29_i104 = 0;
    c29_i105 = 0;
    for (c29_i106 = 0; c29_i106 < 3; c29_i106++) {
      c29_c_y[c29_i104 + c29_i103] = 0.0;
      c29_i107 = 0;
      for (c29_i108 = 0; c29_i108 < 2; c29_i108++) {
        c29_c_y[c29_i104 + c29_i103] += c29_d_b[c29_i107 + c29_i103] *
          c29_b_a[c29_i108 + c29_i105];
        c29_i107 += 3;
      }

      c29_i104 += 3;
      c29_i105 += 2;
    }
  }

  c29_eye(chartInstance, c29_a);
  for (c29_i109 = 0; c29_i109 < 9; c29_i109++) {
    c29_a[c29_i109] -= c29_c_y[c29_i109];
  }

  for (c29_i110 = 0; c29_i110 < 9; c29_i110++) {
    c29_c_b[c29_i110] = c29_P_[c29_i110];
  }

  c29_b_eml_scalar_eg(chartInstance);
  c29_b_eml_scalar_eg(chartInstance);
  for (c29_i111 = 0; c29_i111 < 9; c29_i111++) {
    c29_P_est[c29_i111] = 0.0;
  }

  for (c29_i112 = 0; c29_i112 < 9; c29_i112++) {
    c29_P_est[c29_i112] = 0.0;
  }

  for (c29_i113 = 0; c29_i113 < 9; c29_i113++) {
    c29_d_y[c29_i113] = c29_P_est[c29_i113];
  }

  for (c29_i114 = 0; c29_i114 < 9; c29_i114++) {
    c29_P_est[c29_i114] = c29_d_y[c29_i114];
  }

  for (c29_i115 = 0; c29_i115 < 9; c29_i115++) {
    c29_d_y[c29_i115] = c29_P_est[c29_i115];
  }

  for (c29_i116 = 0; c29_i116 < 9; c29_i116++) {
    c29_P_est[c29_i116] = c29_d_y[c29_i116];
  }

  for (c29_i117 = 0; c29_i117 < 3; c29_i117++) {
    c29_i118 = 0;
    for (c29_i119 = 0; c29_i119 < 3; c29_i119++) {
      c29_P_est[c29_i118 + c29_i117] = 0.0;
      c29_i120 = 0;
      for (c29_i121 = 0; c29_i121 < 3; c29_i121++) {
        c29_P_est[c29_i118 + c29_i117] += c29_a[c29_i120 + c29_i117] *
          c29_c_b[c29_i121 + c29_i118];
        c29_i120 += 3;
      }

      c29_i118 += 3;
    }
  }

  _SFD_EML_CALL(0U, *c29_sfEvent, -16);
  sf_debug_symbol_scope_pop();
  for (c29_i122 = 0; c29_i122 < 3; c29_i122++) {
    (*c29_b_state_est)[c29_i122] = c29_state_est[c29_i122];
  }

  for (c29_i123 = 0; c29_i123 < 9; c29_i123++) {
    (*c29_b_P_est)[c29_i123] = c29_P_est[c29_i123];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 28U, *c29_sfEvent);
}

static void initSimStructsc29_controller_template_rectangle
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c29_machineNumber, uint32_T
  c29_chartNumber)
{
}

static const mxArray *c29_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i124;
  int32_T c29_i125;
  int32_T c29_i126;
  real_T c29_b_inData[9];
  int32_T c29_i127;
  int32_T c29_i128;
  int32_T c29_i129;
  real_T c29_u[9];
  const mxArray *c29_y = NULL;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_i124 = 0;
  for (c29_i125 = 0; c29_i125 < 3; c29_i125++) {
    for (c29_i126 = 0; c29_i126 < 3; c29_i126++) {
      c29_b_inData[c29_i126 + c29_i124] = (*(real_T (*)[9])c29_inData)[c29_i126
        + c29_i124];
    }

    c29_i124 += 3;
  }

  c29_i127 = 0;
  for (c29_i128 = 0; c29_i128 < 3; c29_i128++) {
    for (c29_i129 = 0; c29_i129 < 3; c29_i129++) {
      c29_u[c29_i129 + c29_i127] = c29_b_inData[c29_i129 + c29_i127];
    }

    c29_i127 += 3;
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, FALSE);
  return c29_mxArrayOutData;
}

static void c29_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_P_est, const char_T *c29_identifier, real_T c29_y[9])
{
  emlrtMsgIdentifier c29_thisId;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_P_est), &c29_thisId,
    c29_y);
  sf_mex_destroy(&c29_P_est);
}

static void c29_b_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[9])
{
  real_T c29_dv2[9];
  int32_T c29_i130;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), c29_dv2, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c29_i130 = 0; c29_i130 < 9; c29_i130++) {
    c29_y[c29_i130] = c29_dv2[c29_i130];
  }

  sf_mex_destroy(&c29_u);
}

static void c29_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_P_est;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y[9];
  int32_T c29_i131;
  int32_T c29_i132;
  int32_T c29_i133;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_P_est = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_P_est), &c29_thisId,
    c29_y);
  sf_mex_destroy(&c29_P_est);
  c29_i131 = 0;
  for (c29_i132 = 0; c29_i132 < 3; c29_i132++) {
    for (c29_i133 = 0; c29_i133 < 3; c29_i133++) {
      (*(real_T (*)[9])c29_outData)[c29_i133 + c29_i131] = c29_y[c29_i133 +
        c29_i131];
    }

    c29_i131 += 3;
  }

  sf_mex_destroy(&c29_mxArrayInData);
}

static const mxArray *c29_b_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i134;
  real_T c29_b_inData[3];
  int32_T c29_i135;
  real_T c29_u[3];
  const mxArray *c29_y = NULL;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  for (c29_i134 = 0; c29_i134 < 3; c29_i134++) {
    c29_b_inData[c29_i134] = (*(real_T (*)[3])c29_inData)[c29_i134];
  }

  for (c29_i135 = 0; c29_i135 < 3; c29_i135++) {
    c29_u[c29_i135] = c29_b_inData[c29_i135];
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, FALSE);
  return c29_mxArrayOutData;
}

static void c29_c_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_state_est, const char_T *c29_identifier, real_T c29_y[3])
{
  emlrtMsgIdentifier c29_thisId;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_state_est), &c29_thisId,
    c29_y);
  sf_mex_destroy(&c29_state_est);
}

static void c29_d_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[3])
{
  real_T c29_dv3[3];
  int32_T c29_i136;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), c29_dv3, 1, 0, 0U, 1, 0U, 1, 3);
  for (c29_i136 = 0; c29_i136 < 3; c29_i136++) {
    c29_y[c29_i136] = c29_dv3[c29_i136];
  }

  sf_mex_destroy(&c29_u);
}

static void c29_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_state_est;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y[3];
  int32_T c29_i137;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_state_est = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_state_est), &c29_thisId,
    c29_y);
  sf_mex_destroy(&c29_state_est);
  for (c29_i137 = 0; c29_i137 < 3; c29_i137++) {
    (*(real_T (*)[3])c29_outData)[c29_i137] = c29_y[c29_i137];
  }

  sf_mex_destroy(&c29_mxArrayInData);
}

static const mxArray *c29_c_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i138;
  real_T c29_b_inData[2];
  int32_T c29_i139;
  real_T c29_u[2];
  const mxArray *c29_y = NULL;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  for (c29_i138 = 0; c29_i138 < 2; c29_i138++) {
    c29_b_inData[c29_i138] = (*(real_T (*)[2])c29_inData)[c29_i138];
  }

  for (c29_i139 = 0; c29_i139 < 2; c29_i139++) {
    c29_u[c29_i139] = c29_b_inData[c29_i139];
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 1, 2), FALSE);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, FALSE);
  return c29_mxArrayOutData;
}

static const mxArray *c29_d_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  real_T c29_u;
  const mxArray *c29_y = NULL;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_u = *(real_T *)c29_inData;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, FALSE);
  return c29_mxArrayOutData;
}

static const mxArray *c29_e_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i140;
  int32_T c29_i141;
  int32_T c29_i142;
  real_T c29_b_inData[4];
  int32_T c29_i143;
  int32_T c29_i144;
  int32_T c29_i145;
  real_T c29_u[4];
  const mxArray *c29_y = NULL;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_i140 = 0;
  for (c29_i141 = 0; c29_i141 < 2; c29_i141++) {
    for (c29_i142 = 0; c29_i142 < 2; c29_i142++) {
      c29_b_inData[c29_i142 + c29_i140] = (*(real_T (*)[4])c29_inData)[c29_i142
        + c29_i140];
    }

    c29_i140 += 2;
  }

  c29_i143 = 0;
  for (c29_i144 = 0; c29_i144 < 2; c29_i144++) {
    for (c29_i145 = 0; c29_i145 < 2; c29_i145++) {
      c29_u[c29_i145 + c29_i143] = c29_b_inData[c29_i145 + c29_i143];
    }

    c29_i143 += 2;
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 2, 2, 2), FALSE);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, FALSE);
  return c29_mxArrayOutData;
}

static const mxArray *c29_f_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i146;
  int32_T c29_i147;
  int32_T c29_i148;
  real_T c29_b_inData[6];
  int32_T c29_i149;
  int32_T c29_i150;
  int32_T c29_i151;
  real_T c29_u[6];
  const mxArray *c29_y = NULL;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_i146 = 0;
  for (c29_i147 = 0; c29_i147 < 3; c29_i147++) {
    for (c29_i148 = 0; c29_i148 < 2; c29_i148++) {
      c29_b_inData[c29_i148 + c29_i146] = (*(real_T (*)[6])c29_inData)[c29_i148
        + c29_i146];
    }

    c29_i146 += 2;
  }

  c29_i149 = 0;
  for (c29_i150 = 0; c29_i150 < 3; c29_i150++) {
    for (c29_i151 = 0; c29_i151 < 2; c29_i151++) {
      c29_u[c29_i151 + c29_i149] = c29_b_inData[c29_i151 + c29_i149];
    }

    c29_i149 += 2;
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 2, 2, 3), FALSE);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, FALSE);
  return c29_mxArrayOutData;
}

static real_T c29_e_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId)
{
  real_T c29_y;
  real_T c29_d0;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), &c29_d0, 1, 0, 0U, 0, 0U, 0);
  c29_y = c29_d0;
  sf_mex_destroy(&c29_u);
  return c29_y;
}

static void c29_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_nargout;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_nargout = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_y = c29_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_nargout),
    &c29_thisId);
  sf_mex_destroy(&c29_nargout);
  *(real_T *)c29_outData = c29_y;
  sf_mex_destroy(&c29_mxArrayInData);
}

static const mxArray *c29_g_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_i152;
  int32_T c29_i153;
  int32_T c29_i154;
  real_T c29_b_inData[6];
  int32_T c29_i155;
  int32_T c29_i156;
  int32_T c29_i157;
  real_T c29_u[6];
  const mxArray *c29_y = NULL;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_i152 = 0;
  for (c29_i153 = 0; c29_i153 < 2; c29_i153++) {
    for (c29_i154 = 0; c29_i154 < 3; c29_i154++) {
      c29_b_inData[c29_i154 + c29_i152] = (*(real_T (*)[6])c29_inData)[c29_i154
        + c29_i152];
    }

    c29_i152 += 3;
  }

  c29_i155 = 0;
  for (c29_i156 = 0; c29_i156 < 2; c29_i156++) {
    for (c29_i157 = 0; c29_i157 < 3; c29_i157++) {
      c29_u[c29_i157 + c29_i155] = c29_b_inData[c29_i157 + c29_i155];
    }

    c29_i155 += 3;
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 0, 0U, 1U, 0U, 2, 3, 2), FALSE);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, FALSE);
  return c29_mxArrayOutData;
}

static void c29_f_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, real_T c29_y[6])
{
  real_T c29_dv4[6];
  int32_T c29_i158;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), c29_dv4, 1, 0, 0U, 1, 0U, 2, 3,
                2);
  for (c29_i158 = 0; c29_i158 < 6; c29_i158++) {
    c29_y[c29_i158] = c29_dv4[c29_i158];
  }

  sf_mex_destroy(&c29_u);
}

static void c29_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_K;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  real_T c29_y[6];
  int32_T c29_i159;
  int32_T c29_i160;
  int32_T c29_i161;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_K = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_K), &c29_thisId, c29_y);
  sf_mex_destroy(&c29_K);
  c29_i159 = 0;
  for (c29_i160 = 0; c29_i160 < 2; c29_i160++) {
    for (c29_i161 = 0; c29_i161 < 3; c29_i161++) {
      (*(real_T (*)[6])c29_outData)[c29_i161 + c29_i159] = c29_y[c29_i161 +
        c29_i159];
    }

    c29_i159 += 3;
  }

  sf_mex_destroy(&c29_mxArrayInData);
}

const mxArray
  *sf_c29_controller_template_rectangle_get_eml_resolved_functions_info(void)
{
  const mxArray *c29_nameCaptureInfo;
  c29_ResolvedFunctionInfo c29_info[29];
  const mxArray *c29_m0 = NULL;
  int32_T c29_i162;
  c29_ResolvedFunctionInfo *c29_r0;
  c29_nameCaptureInfo = NULL;
  c29_nameCaptureInfo = NULL;
  c29_info_helper(c29_info);
  sf_mex_assign(&c29_m0, sf_mex_createstruct("nameCaptureInfo", 1, 29), FALSE);
  for (c29_i162 = 0; c29_i162 < 29; c29_i162++) {
    c29_r0 = &c29_info[c29_i162];
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", c29_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c29_r0->context)), "context", "nameCaptureInfo",
                    c29_i162);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", c29_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c29_r0->name)), "name", "nameCaptureInfo",
                    c29_i162);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo",
      c29_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c29_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c29_i162);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", c29_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c29_r0->resolved)), "resolved",
                    "nameCaptureInfo", c29_i162);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", &c29_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c29_i162);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo", &c29_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c29_i162);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo",
      &c29_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c29_i162);
    sf_mex_addfield(c29_m0, sf_mex_create("nameCaptureInfo",
      &c29_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c29_i162);
  }

  sf_mex_assign(&c29_nameCaptureInfo, c29_m0, FALSE);
  return c29_nameCaptureInfo;
}

static void c29_info_helper(c29_ResolvedFunctionInfo c29_info[29])
{
  c29_info[0].context = "";
  c29_info[0].name = "mtimes";
  c29_info[0].dominantType = "double";
  c29_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[0].fileTimeLo = 1289519692U;
  c29_info[0].fileTimeHi = 0U;
  c29_info[0].mFileTimeLo = 0U;
  c29_info[0].mFileTimeHi = 0U;
  c29_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[1].name = "eml_index_class";
  c29_info[1].dominantType = "";
  c29_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c29_info[1].fileTimeLo = 1286818778U;
  c29_info[1].fileTimeHi = 0U;
  c29_info[1].mFileTimeLo = 0U;
  c29_info[1].mFileTimeHi = 0U;
  c29_info[2].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[2].name = "eml_scalar_eg";
  c29_info[2].dominantType = "double";
  c29_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c29_info[2].fileTimeLo = 1286818796U;
  c29_info[2].fileTimeHi = 0U;
  c29_info[2].mFileTimeLo = 0U;
  c29_info[2].mFileTimeHi = 0U;
  c29_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c29_info[3].name = "eml_xgemm";
  c29_info[3].dominantType = "int32";
  c29_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c29_info[3].fileTimeLo = 1299076772U;
  c29_info[3].fileTimeHi = 0U;
  c29_info[3].mFileTimeLo = 0U;
  c29_info[3].mFileTimeHi = 0U;
  c29_info[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  c29_info[4].name = "eml_blas_inline";
  c29_info[4].dominantType = "";
  c29_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  c29_info[4].fileTimeLo = 1299076768U;
  c29_info[4].fileTimeHi = 0U;
  c29_info[4].mFileTimeLo = 0U;
  c29_info[4].mFileTimeHi = 0U;
  c29_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  c29_info[5].name = "eml_refblas_xgemm";
  c29_info[5].dominantType = "int32";
  c29_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  c29_info[5].fileTimeLo = 1299076774U;
  c29_info[5].fileTimeHi = 0U;
  c29_info[5].mFileTimeLo = 0U;
  c29_info[5].mFileTimeHi = 0U;
  c29_info[6].context = "";
  c29_info[6].name = "mpower";
  c29_info[6].dominantType = "double";
  c29_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c29_info[6].fileTimeLo = 1286818842U;
  c29_info[6].fileTimeHi = 0U;
  c29_info[6].mFileTimeLo = 0U;
  c29_info[6].mFileTimeHi = 0U;
  c29_info[7].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c29_info[7].name = "eml_scalar_floor";
  c29_info[7].dominantType = "double";
  c29_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c29_info[7].fileTimeLo = 1286818726U;
  c29_info[7].fileTimeHi = 0U;
  c29_info[7].mFileTimeLo = 0U;
  c29_info[7].mFileTimeHi = 0U;
  c29_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c29_info[8].name = "eml_scalar_abs";
  c29_info[8].dominantType = "double";
  c29_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c29_info[8].fileTimeLo = 1286818712U;
  c29_info[8].fileTimeHi = 0U;
  c29_info[8].mFileTimeLo = 0U;
  c29_info[8].mFileTimeHi = 0U;
  c29_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m!matrix_to_integer_power";
  c29_info[9].name = "inv";
  c29_info[9].dominantType = "double";
  c29_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m";
  c29_info[9].fileTimeLo = 1305318000U;
  c29_info[9].fileTimeHi = 0U;
  c29_info[9].mFileTimeLo = 0U;
  c29_info[9].mFileTimeHi = 0U;
  c29_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c29_info[10].name = "eml_xcabs1";
  c29_info[10].dominantType = "double";
  c29_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c29_info[10].fileTimeLo = 1286818706U;
  c29_info[10].fileTimeHi = 0U;
  c29_info[10].mFileTimeLo = 0U;
  c29_info[10].mFileTimeHi = 0U;
  c29_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m";
  c29_info[11].name = "abs";
  c29_info[11].dominantType = "double";
  c29_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  c29_info[11].fileTimeLo = 1286818694U;
  c29_info[11].fileTimeHi = 0U;
  c29_info[11].mFileTimeLo = 0U;
  c29_info[11].mFileTimeHi = 0U;
  c29_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!inv2x2";
  c29_info[12].name = "mrdivide";
  c29_info[12].dominantType = "double";
  c29_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c29_info[12].fileTimeLo = 1310137456U;
  c29_info[12].fileTimeHi = 0U;
  c29_info[12].mFileTimeLo = 1289519692U;
  c29_info[12].mFileTimeHi = 0U;
  c29_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  c29_info[13].name = "rdivide";
  c29_info[13].dominantType = "double";
  c29_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c29_info[13].fileTimeLo = 1286818844U;
  c29_info[13].fileTimeHi = 0U;
  c29_info[13].mFileTimeLo = 0U;
  c29_info[13].mFileTimeHi = 0U;
  c29_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c29_info[14].name = "eml_div";
  c29_info[14].dominantType = "double";
  c29_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c29_info[14].fileTimeLo = 1305318000U;
  c29_info[14].fileTimeHi = 0U;
  c29_info[14].mFileTimeLo = 0U;
  c29_info[14].mFileTimeHi = 0U;
  c29_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c29_info[15].name = "norm";
  c29_info[15].dominantType = "double";
  c29_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m";
  c29_info[15].fileTimeLo = 1286818826U;
  c29_info[15].fileTimeHi = 0U;
  c29_info[15].mFileTimeLo = 0U;
  c29_info[15].mFileTimeHi = 0U;
  c29_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c29_info[16].name = "isnan";
  c29_info[16].dominantType = "double";
  c29_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c29_info[16].fileTimeLo = 1286818760U;
  c29_info[16].fileTimeHi = 0U;
  c29_info[16].mFileTimeLo = 0U;
  c29_info[16].mFileTimeHi = 0U;
  c29_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!mat1norm";
  c29_info[17].name = "eml_guarded_nan";
  c29_info[17].dominantType = "char";
  c29_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c29_info[17].fileTimeLo = 1286818776U;
  c29_info[17].fileTimeHi = 0U;
  c29_info[17].mFileTimeLo = 0U;
  c29_info[17].mFileTimeHi = 0U;
  c29_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m";
  c29_info[18].name = "eml_is_float_class";
  c29_info[18].dominantType = "char";
  c29_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c29_info[18].fileTimeLo = 1286818782U;
  c29_info[18].fileTimeHi = 0U;
  c29_info[18].mFileTimeLo = 0U;
  c29_info[18].mFileTimeHi = 0U;
  c29_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c29_info[19].name = "eml_warning";
  c29_info[19].dominantType = "char";
  c29_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c29_info[19].fileTimeLo = 1286818802U;
  c29_info[19].fileTimeHi = 0U;
  c29_info[19].mFileTimeLo = 0U;
  c29_info[19].mFileTimeHi = 0U;
  c29_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c29_info[20].name = "eps";
  c29_info[20].dominantType = "char";
  c29_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c29_info[20].fileTimeLo = 1286818686U;
  c29_info[20].fileTimeHi = 0U;
  c29_info[20].mFileTimeLo = 0U;
  c29_info[20].mFileTimeHi = 0U;
  c29_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/inv.m!checkcond";
  c29_info[21].name = "eml_flt2str";
  c29_info[21].dominantType = "double";
  c29_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_flt2str.m";
  c29_info[21].fileTimeLo = 1286818776U;
  c29_info[21].fileTimeHi = 0U;
  c29_info[21].mFileTimeLo = 0U;
  c29_info[21].mFileTimeHi = 0U;
  c29_info[22].context = "";
  c29_info[22].name = "eye";
  c29_info[22].dominantType = "double";
  c29_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m";
  c29_info[22].fileTimeLo = 1286818688U;
  c29_info[22].fileTimeHi = 0U;
  c29_info[22].mFileTimeLo = 0U;
  c29_info[22].mFileTimeHi = 0U;
  c29_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c29_info[23].name = "eml_assert_valid_size_arg";
  c29_info[23].dominantType = "double";
  c29_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c29_info[23].fileTimeLo = 1286818694U;
  c29_info[23].fileTimeHi = 0U;
  c29_info[23].mFileTimeLo = 0U;
  c29_info[23].mFileTimeHi = 0U;
  c29_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral";
  c29_info[24].name = "isinf";
  c29_info[24].dominantType = "double";
  c29_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m";
  c29_info[24].fileTimeLo = 1286818760U;
  c29_info[24].fileTimeHi = 0U;
  c29_info[24].mFileTimeLo = 0U;
  c29_info[24].mFileTimeHi = 0U;
  c29_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m";
  c29_info[25].name = "intmax";
  c29_info[25].dominantType = "char";
  c29_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c29_info[25].fileTimeLo = 1286818756U;
  c29_info[25].fileTimeHi = 0U;
  c29_info[25].mFileTimeLo = 0U;
  c29_info[25].mFileTimeHi = 0U;
  c29_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m!eye_internal";
  c29_info[26].name = "min";
  c29_info[26].dominantType = "double";
  c29_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c29_info[26].fileTimeLo = 1308747330U;
  c29_info[26].fileTimeHi = 0U;
  c29_info[26].mFileTimeLo = 0U;
  c29_info[26].mFileTimeHi = 0U;
  c29_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m";
  c29_info[27].name = "eml_min_or_max";
  c29_info[27].dominantType = "char";
  c29_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m";
  c29_info[27].fileTimeLo = 1303146212U;
  c29_info[27].fileTimeHi = 0U;
  c29_info[27].mFileTimeLo = 0U;
  c29_info[27].mFileTimeHi = 0U;
  c29_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum";
  c29_info[28].name = "eml_scalexp_alloc";
  c29_info[28].dominantType = "double";
  c29_info[28].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c29_info[28].fileTimeLo = 1286818796U;
  c29_info[28].fileTimeHi = 0U;
  c29_info[28].mFileTimeLo = 0U;
  c29_info[28].mFileTimeHi = 0U;
}

static void c29_eml_scalar_eg(SFc29_controller_template_rectangleInstanceStruct *
  chartInstance)
{
}

static void c29_b_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void c29_c_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void c29_d_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void c29_e_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void c29_mpower(SFc29_controller_template_rectangleInstanceStruct
  *chartInstance, real_T c29_a[4], real_T c29_c[4])
{
  int32_T c29_i163;
  real_T c29_b_a[4];
  for (c29_i163 = 0; c29_i163 < 4; c29_i163++) {
    c29_b_a[c29_i163] = c29_a[c29_i163];
  }

  c29_matrix_to_integer_power(chartInstance, c29_b_a, -1.0, c29_c);
}

static void c29_matrix_to_integer_power
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, real_T
   c29_a[4], real_T c29_b, real_T c29_c[4])
{
  real_T c29_x;
  real_T c29_e;
  boolean_T c29_firstmult;
  real_T c29_b_x;
  real_T c29_ed2;
  real_T c29_b_b;
  real_T c29_y;
  int32_T c29_i164;
  int32_T c29_i165;
  real_T c29_A[4];
  int32_T c29_i166;
  int32_T c29_i167;
  int32_T c29_i168;
  int32_T c29_i169;
  int32_T c29_i170;
  int32_T c29_i171;
  real_T c29_c_x;
  real_T c29_d_x;
  real_T c29_e_x;
  real_T c29_b_y;
  real_T c29_f_x;
  real_T c29_g_x;
  real_T c29_c_y;
  real_T c29_d;
  real_T c29_h_x;
  real_T c29_i_x;
  real_T c29_j_x;
  real_T c29_d_y;
  real_T c29_k_x;
  real_T c29_l_x;
  real_T c29_e_y;
  real_T c29_b_d;
  real_T c29_b_A;
  real_T c29_B;
  real_T c29_m_x;
  real_T c29_f_y;
  real_T c29_n_x;
  real_T c29_g_y;
  real_T c29_r;
  real_T c29_b_a;
  real_T c29_c_b;
  real_T c29_h_y;
  real_T c29_b_B;
  real_T c29_i_y;
  real_T c29_j_y;
  real_T c29_t;
  real_T c29_c_A;
  real_T c29_c_B;
  real_T c29_o_x;
  real_T c29_k_y;
  real_T c29_p_x;
  real_T c29_l_y;
  real_T c29_m_y;
  real_T c29_c_a;
  real_T c29_d_b;
  real_T c29_n_y;
  real_T c29_d_A;
  real_T c29_d_B;
  real_T c29_q_x;
  real_T c29_o_y;
  real_T c29_r_x;
  real_T c29_p_y;
  real_T c29_q_y;
  real_T c29_d_a;
  real_T c29_e_b;
  real_T c29_r_y;
  real_T c29_e_a;
  real_T c29_f_b;
  real_T c29_s_y;
  real_T c29_e_A;
  real_T c29_e_B;
  real_T c29_s_x;
  real_T c29_t_y;
  real_T c29_t_x;
  real_T c29_u_y;
  real_T c29_f_a;
  real_T c29_g_b;
  real_T c29_v_y;
  real_T c29_f_B;
  real_T c29_w_y;
  real_T c29_x_y;
  real_T c29_f_A;
  real_T c29_g_B;
  real_T c29_u_x;
  real_T c29_y_y;
  real_T c29_v_x;
  real_T c29_ab_y;
  real_T c29_bb_y;
  real_T c29_g_a;
  real_T c29_h_b;
  real_T c29_cb_y;
  real_T c29_h_a;
  real_T c29_i_b;
  real_T c29_db_y;
  real_T c29_g_A;
  real_T c29_h_B;
  real_T c29_w_x;
  real_T c29_eb_y;
  real_T c29_x_x;
  real_T c29_fb_y;
  real_T c29_gb_y;
  real_T c29_i_a;
  real_T c29_j_b;
  real_T c29_hb_y;
  int32_T c29_i172;
  real_T c29_h_A[4];
  real_T c29_n1x;
  int32_T c29_i173;
  real_T c29_b_c[4];
  real_T c29_n1xinv;
  real_T c29_j_a;
  real_T c29_k_b;
  real_T c29_ib_y;
  real_T c29_rc;
  real_T c29_y_x;
  boolean_T c29_l_b;
  real_T c29_ab_x;
  int32_T c29_i174;
  static char_T c29_cv0[8] = { '%', '%', '%', 'd', '.', '%', 'd', 'e' };

  char_T c29_u[8];
  const mxArray *c29_jb_y = NULL;
  real_T c29_b_u;
  const mxArray *c29_kb_y = NULL;
  real_T c29_c_u;
  const mxArray *c29_lb_y = NULL;
  real_T c29_d_u;
  const mxArray *c29_mb_y = NULL;
  char_T c29_str[14];
  int32_T c29_i175;
  char_T c29_b_str[14];
  int32_T c29_i176;
  int32_T c29_i177;
  int32_T c29_i178;
  int32_T c29_i179;
  int32_T c29_i180;
  int32_T c29_i181;
  int32_T c29_i182;
  int32_T c29_k;
  int32_T c29_b_k;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  int32_T exitg1;
  c29_f_eml_scalar_eg(chartInstance);
  c29_x = c29_b;
  c29_e = muDoubleScalarAbs(c29_x);
  if (c29_e > 0.0) {
    c29_firstmult = TRUE;
    do {
      exitg1 = 0U;
      c29_b_x = c29_e / 2.0;
      c29_ed2 = c29_b_x;
      c29_ed2 = muDoubleScalarFloor(c29_ed2);
      c29_b_b = c29_ed2;
      c29_y = 2.0 * c29_b_b;
      if (c29_y != c29_e) {
        if (c29_firstmult) {
          for (c29_i164 = 0; c29_i164 < 4; c29_i164++) {
            c29_c[c29_i164] = c29_a[c29_i164];
          }

          c29_firstmult = FALSE;
        } else {
          c29_g_eml_scalar_eg(chartInstance);
          c29_g_eml_scalar_eg(chartInstance);
          for (c29_i165 = 0; c29_i165 < 4; c29_i165++) {
            c29_A[c29_i165] = c29_c[c29_i165];
          }

          for (c29_i166 = 0; c29_i166 < 2; c29_i166++) {
            c29_i167 = 0;
            for (c29_i168 = 0; c29_i168 < 2; c29_i168++) {
              c29_c[c29_i167 + c29_i166] = 0.0;
              c29_i169 = 0;
              for (c29_i170 = 0; c29_i170 < 2; c29_i170++) {
                c29_c[c29_i167 + c29_i166] += c29_A[c29_i169 + c29_i166] *
                  c29_a[c29_i170 + c29_i167];
                c29_i169 += 2;
              }

              c29_i167 += 2;
            }
          }
        }
      }

      if (c29_ed2 == 0.0) {
        exitg1 = 1U;
      } else {
        c29_e = c29_ed2;
        c29_g_eml_scalar_eg(chartInstance);
        c29_g_eml_scalar_eg(chartInstance);
        for (c29_i176 = 0; c29_i176 < 4; c29_i176++) {
          c29_A[c29_i176] = c29_a[c29_i176];
        }

        for (c29_i177 = 0; c29_i177 < 2; c29_i177++) {
          c29_i178 = 0;
          for (c29_i179 = 0; c29_i179 < 2; c29_i179++) {
            c29_a[c29_i178 + c29_i177] = 0.0;
            c29_i180 = 0;
            for (c29_i181 = 0; c29_i181 < 2; c29_i181++) {
              c29_a[c29_i178 + c29_i177] += c29_A[c29_i180 + c29_i177] *
                c29_A[c29_i181 + c29_i178];
              c29_i180 += 2;
            }

            c29_i178 += 2;
          }
        }
      }
    } while (exitg1 == 0U);

    if (c29_b < 0.0) {
      for (c29_i171 = 0; c29_i171 < 4; c29_i171++) {
        c29_A[c29_i171] = c29_c[c29_i171];
      }

      c29_c_x = c29_A[1];
      c29_d_x = c29_c_x;
      c29_e_x = c29_d_x;
      c29_b_y = muDoubleScalarAbs(c29_e_x);
      c29_f_x = 0.0;
      c29_g_x = c29_f_x;
      c29_c_y = muDoubleScalarAbs(c29_g_x);
      c29_d = c29_b_y + c29_c_y;
      c29_h_x = c29_A[0];
      c29_i_x = c29_h_x;
      c29_j_x = c29_i_x;
      c29_d_y = muDoubleScalarAbs(c29_j_x);
      c29_k_x = 0.0;
      c29_l_x = c29_k_x;
      c29_e_y = muDoubleScalarAbs(c29_l_x);
      c29_b_d = c29_d_y + c29_e_y;
      if (c29_d > c29_b_d) {
        c29_b_A = c29_A[0];
        c29_B = c29_A[1];
        c29_m_x = c29_b_A;
        c29_f_y = c29_B;
        c29_n_x = c29_m_x;
        c29_g_y = c29_f_y;
        c29_r = c29_n_x / c29_g_y;
        c29_b_a = c29_r;
        c29_c_b = c29_A[3];
        c29_h_y = c29_b_a * c29_c_b;
        c29_b_B = c29_h_y - c29_A[2];
        c29_i_y = c29_b_B;
        c29_j_y = c29_i_y;
        c29_t = 1.0 / c29_j_y;
        c29_c_A = c29_A[3];
        c29_c_B = c29_A[1];
        c29_o_x = c29_c_A;
        c29_k_y = c29_c_B;
        c29_p_x = c29_o_x;
        c29_l_y = c29_k_y;
        c29_m_y = c29_p_x / c29_l_y;
        c29_c_a = c29_m_y;
        c29_d_b = c29_t;
        c29_n_y = c29_c_a * c29_d_b;
        c29_c[0] = c29_n_y;
        c29_c[1] = -c29_t;
        c29_d_A = -c29_A[2];
        c29_d_B = c29_A[1];
        c29_q_x = c29_d_A;
        c29_o_y = c29_d_B;
        c29_r_x = c29_q_x;
        c29_p_y = c29_o_y;
        c29_q_y = c29_r_x / c29_p_y;
        c29_d_a = c29_q_y;
        c29_e_b = c29_t;
        c29_r_y = c29_d_a * c29_e_b;
        c29_c[2] = c29_r_y;
        c29_e_a = c29_r;
        c29_f_b = c29_t;
        c29_s_y = c29_e_a * c29_f_b;
        c29_c[3] = c29_s_y;
      } else {
        c29_e_A = c29_A[1];
        c29_e_B = c29_A[0];
        c29_s_x = c29_e_A;
        c29_t_y = c29_e_B;
        c29_t_x = c29_s_x;
        c29_u_y = c29_t_y;
        c29_r = c29_t_x / c29_u_y;
        c29_f_a = c29_r;
        c29_g_b = c29_A[2];
        c29_v_y = c29_f_a * c29_g_b;
        c29_f_B = c29_A[3] - c29_v_y;
        c29_w_y = c29_f_B;
        c29_x_y = c29_w_y;
        c29_t = 1.0 / c29_x_y;
        c29_f_A = c29_A[3];
        c29_g_B = c29_A[0];
        c29_u_x = c29_f_A;
        c29_y_y = c29_g_B;
        c29_v_x = c29_u_x;
        c29_ab_y = c29_y_y;
        c29_bb_y = c29_v_x / c29_ab_y;
        c29_g_a = c29_bb_y;
        c29_h_b = c29_t;
        c29_cb_y = c29_g_a * c29_h_b;
        c29_c[0] = c29_cb_y;
        c29_h_a = -c29_r;
        c29_i_b = c29_t;
        c29_db_y = c29_h_a * c29_i_b;
        c29_c[1] = c29_db_y;
        c29_g_A = -c29_A[2];
        c29_h_B = c29_A[0];
        c29_w_x = c29_g_A;
        c29_eb_y = c29_h_B;
        c29_x_x = c29_w_x;
        c29_fb_y = c29_eb_y;
        c29_gb_y = c29_x_x / c29_fb_y;
        c29_i_a = c29_gb_y;
        c29_j_b = c29_t;
        c29_hb_y = c29_i_a * c29_j_b;
        c29_c[2] = c29_hb_y;
        c29_c[3] = c29_t;
      }

      for (c29_i172 = 0; c29_i172 < 4; c29_i172++) {
        c29_h_A[c29_i172] = c29_A[c29_i172];
      }

      c29_n1x = c29_norm(chartInstance, c29_h_A);
      for (c29_i173 = 0; c29_i173 < 4; c29_i173++) {
        c29_b_c[c29_i173] = c29_c[c29_i173];
      }

      c29_n1xinv = c29_norm(chartInstance, c29_b_c);
      c29_j_a = c29_n1x;
      c29_k_b = c29_n1xinv;
      c29_ib_y = c29_j_a * c29_k_b;
      c29_rc = 1.0 / c29_ib_y;
      guard1 = FALSE;
      guard2 = FALSE;
      if (c29_n1x == 0.0) {
        guard2 = TRUE;
      } else if (c29_n1xinv == 0.0) {
        guard2 = TRUE;
      } else if (c29_rc == 0.0) {
        guard1 = TRUE;
      } else {
        c29_y_x = c29_rc;
        c29_l_b = muDoubleScalarIsNaN(c29_y_x);
        guard3 = FALSE;
        if (c29_l_b) {
          guard3 = TRUE;
        } else {
          if (c29_rc < 2.2204460492503131E-16) {
            guard3 = TRUE;
          }
        }

        if (guard3 == TRUE) {
          c29_ab_x = c29_rc;
          for (c29_i174 = 0; c29_i174 < 8; c29_i174++) {
            c29_u[c29_i174] = c29_cv0[c29_i174];
          }

          c29_jb_y = NULL;
          sf_mex_assign(&c29_jb_y, sf_mex_create("y", c29_u, 10, 0U, 1U, 0U, 2,
            1, 8), FALSE);
          c29_b_u = 14.0;
          c29_kb_y = NULL;
          sf_mex_assign(&c29_kb_y, sf_mex_create("y", &c29_b_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c29_c_u = 6.0;
          c29_lb_y = NULL;
          sf_mex_assign(&c29_lb_y, sf_mex_create("y", &c29_c_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c29_d_u = c29_ab_x;
          c29_mb_y = NULL;
          sf_mex_assign(&c29_mb_y, sf_mex_create("y", &c29_d_u, 0, 0U, 0U, 0U, 0),
                        FALSE);
          c29_g_emlrt_marshallIn(chartInstance, sf_mex_call_debug("sprintf", 1U,
            2U, 14, sf_mex_call_debug("sprintf", 1U, 3U, 14, c29_jb_y, 14,
            c29_kb_y, 14, c29_lb_y), 14, c29_mb_y), "sprintf", c29_str);
          for (c29_i175 = 0; c29_i175 < 14; c29_i175++) {
            c29_b_str[c29_i175] = c29_str[c29_i175];
          }

          c29_b_eml_warning(chartInstance, c29_b_str);
        }
      }

      if (guard2 == TRUE) {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        c29_eml_warning(chartInstance);
      }
    }
  } else {
    for (c29_i182 = 0; c29_i182 < 4; c29_i182++) {
      c29_c[c29_i182] = 0.0;
    }

    for (c29_k = 1; c29_k < 3; c29_k++) {
      c29_b_k = c29_k;
      c29_c[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
               (real_T)c29_b_k), 1, 2, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
                (int32_T)_SFD_INTEGER_CHECK("", (real_T)c29_b_k), 1, 2, 2, 0) -
               1) << 1)) - 1] = 1.0;
    }
  }
}

static void c29_f_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void c29_g_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static real_T c29_norm(SFc29_controller_template_rectangleInstanceStruct
  *chartInstance, real_T c29_x[4])
{
  real_T c29_y;
  int32_T c29_j;
  real_T c29_b_j;
  real_T c29_s;
  int32_T c29_i;
  real_T c29_b_i;
  real_T c29_b_x;
  real_T c29_c_x;
  real_T c29_b_y;
  real_T c29_d_x;
  boolean_T c29_b;
  boolean_T exitg1;
  c29_y = 0.0;
  c29_j = 0;
  exitg1 = 0U;
  while ((exitg1 == 0U) && (c29_j < 2)) {
    c29_b_j = 1.0 + (real_T)c29_j;
    c29_s = 0.0;
    for (c29_i = 0; c29_i < 2; c29_i++) {
      c29_b_i = 1.0 + (real_T)c29_i;
      c29_b_x = c29_x[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c29_b_i), 1, 2, 1, 0) +
                       ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", c29_b_j), 1, 2, 2, 0) - 1) << 1)) - 1];
      c29_c_x = c29_b_x;
      c29_b_y = muDoubleScalarAbs(c29_c_x);
      c29_s += c29_b_y;
    }

    c29_d_x = c29_s;
    c29_b = muDoubleScalarIsNaN(c29_d_x);
    if (c29_b) {
      c29_y = rtNaN;
      exitg1 = 1U;
    } else {
      if (c29_s > c29_y) {
        c29_y = c29_s;
      }

      c29_j++;
    }
  }

  return c29_y;
}

static void c29_eml_warning(SFc29_controller_template_rectangleInstanceStruct
  *chartInstance)
{
  int32_T c29_i183;
  static char_T c29_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c29_u[27];
  const mxArray *c29_y = NULL;
  for (c29_i183 = 0; c29_i183 < 27; c29_i183++) {
    c29_u[c29_i183] = c29_varargin_1[c29_i183];
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 10, 0U, 1U, 0U, 2, 1, 27),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
    14, c29_y));
}

static void c29_b_eml_warning(SFc29_controller_template_rectangleInstanceStruct *
  chartInstance, char_T c29_varargin_2[14])
{
  int32_T c29_i184;
  static char_T c29_varargin_1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 'i', 'l', 'l', 'C', 'o', 'n', 'd', 'i', 't', 'i',
    'o', 'n', 'e', 'd', 'M', 'a', 't', 'r', 'i', 'x' };

  char_T c29_u[33];
  const mxArray *c29_y = NULL;
  int32_T c29_i185;
  char_T c29_b_u[14];
  const mxArray *c29_b_y = NULL;
  for (c29_i184 = 0; c29_i184 < 33; c29_i184++) {
    c29_u[c29_i184] = c29_varargin_1[c29_i184];
  }

  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", c29_u, 10, 0U, 1U, 0U, 2, 1, 33),
                FALSE);
  for (c29_i185 = 0; c29_i185 < 14; c29_i185++) {
    c29_b_u[c29_i185] = c29_varargin_2[c29_i185];
  }

  c29_b_y = NULL;
  sf_mex_assign(&c29_b_y, sf_mex_create("y", c29_b_u, 10, 0U, 1U, 0U, 2, 1, 14),
                FALSE);
  sf_mex_call_debug("warning", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
    14, c29_y, 14, c29_b_y));
}

static void c29_h_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void c29_i_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void c29_j_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void c29_eye(SFc29_controller_template_rectangleInstanceStruct
                    *chartInstance, real_T c29_I[9])
{
  int32_T c29_i186;
  int32_T c29_i;
  int32_T c29_b_i;
  for (c29_i186 = 0; c29_i186 < 9; c29_i186++) {
    c29_I[c29_i186] = 0.0;
  }

  for (c29_i = 1; c29_i < 4; c29_i++) {
    c29_b_i = c29_i;
    c29_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
             (real_T)c29_b_i), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c29_b_i), 1, 3, 2, 0) - 1))
      - 1] = 1.0;
  }
}

static void c29_k_eml_scalar_eg
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void c29_g_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_sprintf, const char_T *c29_identifier, char_T c29_y[14])
{
  emlrtMsgIdentifier c29_thisId;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_sprintf), &c29_thisId,
    c29_y);
  sf_mex_destroy(&c29_sprintf);
}

static void c29_h_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId, char_T c29_y[14])
{
  char_T c29_cv1[14];
  int32_T c29_i187;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), c29_cv1, 1, 10, 0U, 1, 0U, 2, 1,
                14);
  for (c29_i187 = 0; c29_i187 < 14; c29_i187++) {
    c29_y[c29_i187] = c29_cv1[c29_i187];
  }

  sf_mex_destroy(&c29_u);
}

static const mxArray *c29_h_sf_marshallOut(void *chartInstanceVoid, void
  *c29_inData)
{
  const mxArray *c29_mxArrayOutData = NULL;
  int32_T c29_u;
  const mxArray *c29_y = NULL;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_mxArrayOutData = NULL;
  c29_u = *(int32_T *)c29_inData;
  c29_y = NULL;
  sf_mex_assign(&c29_y, sf_mex_create("y", &c29_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c29_mxArrayOutData, c29_y, FALSE);
  return c29_mxArrayOutData;
}

static int32_T c29_i_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId)
{
  int32_T c29_y;
  int32_T c29_i188;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), &c29_i188, 1, 6, 0U, 0, 0U, 0);
  c29_y = c29_i188;
  sf_mex_destroy(&c29_u);
  return c29_y;
}

static void c29_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c29_mxArrayInData, const char_T *c29_varName, void *c29_outData)
{
  const mxArray *c29_sfEvent;
  const char_T *c29_identifier;
  emlrtMsgIdentifier c29_thisId;
  int32_T c29_y;
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c29_sfEvent = sf_mex_dup(c29_mxArrayInData);
  c29_identifier = c29_varName;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_y = c29_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c29_sfEvent),
    &c29_thisId);
  sf_mex_destroy(&c29_sfEvent);
  *(int32_T *)c29_outData = c29_y;
  sf_mex_destroy(&c29_mxArrayInData);
}

static uint8_T c29_j_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_is_active_c29_controller_template_rectangle, const char_T
   *c29_identifier)
{
  uint8_T c29_y;
  emlrtMsgIdentifier c29_thisId;
  c29_thisId.fIdentifier = c29_identifier;
  c29_thisId.fParent = NULL;
  c29_y = c29_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c29_is_active_c29_controller_template_rectangle), &c29_thisId);
  sf_mex_destroy(&c29_is_active_c29_controller_template_rectangle);
  return c29_y;
}

static uint8_T c29_k_emlrt_marshallIn
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c29_u, const emlrtMsgIdentifier *c29_parentId)
{
  uint8_T c29_y;
  uint8_T c29_u0;
  sf_mex_import(c29_parentId, sf_mex_dup(c29_u), &c29_u0, 1, 3, 0U, 0, 0U, 0);
  c29_y = c29_u0;
  sf_mex_destroy(&c29_u);
  return c29_y;
}

static void init_dsm_address_info
  (SFc29_controller_template_rectangleInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c29_controller_template_rectangle_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2189853427U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2730128856U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1447956719U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1158677693U);
}

mxArray *sf_c29_controller_template_rectangle_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("moLetQsTYcT2odqt4LCxPB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(2);
      pr[1] = (double)(3);
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
      pr[0] = (double)(2);
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
      pr[0] = (double)(2);
      pr[1] = (double)(2);
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
      pr[0] = (double)(2);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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

static const mxArray *sf_get_sim_state_info_c29_controller_template_rectangle
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[29],T\"P_est\",},{M[1],M[5],T\"state_est\",},{M[8],M[0],T\"is_active_c29_controller_template_rectangle\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c29_controller_template_rectangle_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc29_controller_template_rectangleInstanceStruct *chartInstance;
    chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_template_rectangleMachineNumber_,
           29,
           1,
           1,
           12,
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
          init_script_number_translation
            (_controller_template_rectangleMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_controller_template_rectangleMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_controller_template_rectangleMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"A");
          _SFD_SET_DATA_PROPS(1,1,1,0,"B");
          _SFD_SET_DATA_PROPS(2,2,0,1,"state_est");
          _SFD_SET_DATA_PROPS(3,1,1,0,"C");
          _SFD_SET_DATA_PROPS(4,1,1,0,"D");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Q");
          _SFD_SET_DATA_PROPS(6,1,1,0,"R");
          _SFD_SET_DATA_PROPS(7,1,1,0,"u");
          _SFD_SET_DATA_PROPS(8,1,1,0,"y");
          _SFD_SET_DATA_PROPS(9,1,1,0,"P");
          _SFD_SET_DATA_PROPS(10,1,1,0,"state");
          _SFD_SET_DATA_PROPS(11,2,0,1,"P_est");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,308);
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
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_b_sf_marshallOut,(MexInFcnForType)
            c29_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c29_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c29_sf_marshallOut,(MexInFcnForType)
            c29_sf_marshallIn);
        }

        {
          real_T *c29_u;
          real_T (*c29_A)[9];
          real_T (*c29_B)[3];
          real_T (*c29_state_est)[3];
          real_T (*c29_C)[6];
          real_T (*c29_D)[2];
          real_T (*c29_Q)[9];
          real_T (*c29_R)[4];
          real_T (*c29_y)[2];
          real_T (*c29_P)[9];
          real_T (*c29_state)[3];
          real_T (*c29_P_est)[9];
          c29_P_est = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 2);
          c29_state = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 9);
          c29_P = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 8);
          c29_y = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 7);
          c29_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 6);
          c29_R = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 5);
          c29_Q = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 4);
          c29_D = (real_T (*)[2])ssGetInputPortSignal(chartInstance->S, 3);
          c29_C = (real_T (*)[6])ssGetInputPortSignal(chartInstance->S, 2);
          c29_state_est = (real_T (*)[3])ssGetOutputPortSignal(chartInstance->S,
            1);
          c29_B = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 1);
          c29_A = (real_T (*)[9])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c29_A);
          _SFD_SET_DATA_VALUE_PTR(1U, *c29_B);
          _SFD_SET_DATA_VALUE_PTR(2U, *c29_state_est);
          _SFD_SET_DATA_VALUE_PTR(3U, *c29_C);
          _SFD_SET_DATA_VALUE_PTR(4U, *c29_D);
          _SFD_SET_DATA_VALUE_PTR(5U, *c29_Q);
          _SFD_SET_DATA_VALUE_PTR(6U, *c29_R);
          _SFD_SET_DATA_VALUE_PTR(7U, c29_u);
          _SFD_SET_DATA_VALUE_PTR(8U, *c29_y);
          _SFD_SET_DATA_VALUE_PTR(9U, *c29_P);
          _SFD_SET_DATA_VALUE_PTR(10U, *c29_state);
          _SFD_SET_DATA_VALUE_PTR(11U, *c29_P_est);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_controller_template_rectangleMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_controller_template_rectangle_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S, infoStruct,
      29, "dworkChecksum");
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

static void sf_opaque_initialize_c29_controller_template_rectangle(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc29_controller_template_rectangleInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc29_controller_template_rectangleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c29_controller_template_rectangle
    ((SFc29_controller_template_rectangleInstanceStruct*) chartInstanceVar);
  initialize_c29_controller_template_rectangle
    ((SFc29_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c29_controller_template_rectangle(void
  *chartInstanceVar)
{
  enable_c29_controller_template_rectangle
    ((SFc29_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c29_controller_template_rectangle(void
  *chartInstanceVar)
{
  disable_c29_controller_template_rectangle
    ((SFc29_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c29_controller_template_rectangle(void
  *chartInstanceVar)
{
  sf_c29_controller_template_rectangle
    ((SFc29_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c29_controller_template_rectangle(void
  *chartInstanceVar)
{
  ext_mode_exec_c29_controller_template_rectangle
    ((SFc29_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c29_controller_template_rectangle(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c29_controller_template_rectangle
    ((SFc29_controller_template_rectangleInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c29_controller_template_rectangle();/* state var info */
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

extern void sf_internal_set_sim_state_c29_controller_template_rectangle
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c29_controller_template_rectangle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c29_controller_template_rectangle
    ((SFc29_controller_template_rectangleInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c29_controller_template_rectangle
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c29_controller_template_rectangle(S);
}

static void sf_opaque_set_sim_state_c29_controller_template_rectangle(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c29_controller_template_rectangle(S, st);
}

static void sf_opaque_terminate_c29_controller_template_rectangle(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc29_controller_template_rectangleInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c29_controller_template_rectangle
      ((SFc29_controller_template_rectangleInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_rectangle_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc29_controller_template_rectangle
    ((SFc29_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c29_controller_template_rectangle(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c29_controller_template_rectangle
      ((SFc29_controller_template_rectangleInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c29_controller_template_rectangle_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c29_controller_template_rectangle\",T\"is_active_c29_controller_template_rectangle\"}}"
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

static void mdlSetWorkWidths_c29_controller_template_rectangle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_rectangle_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,29);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,29,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,29,
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
      sf_mark_chart_expressionable_inputs(S,infoStruct,29,10);
      sf_mark_chart_reusable_outputs(S,infoStruct,29,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,29);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(237375345U));
  ssSetChecksum1(S,(3739561383U));
  ssSetChecksum2(S,(1666305668U));
  ssSetChecksum3(S,(385915697U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c29_controller_template_rectangle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c29_controller_template_rectangle(SimStruct *S)
{
  SFc29_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc29_controller_template_rectangleInstanceStruct *)malloc
    (sizeof(SFc29_controller_template_rectangleInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc29_controller_template_rectangleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c29_controller_template_rectangle;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c29_controller_template_rectangle;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c29_controller_template_rectangle;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c29_controller_template_rectangle;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c29_controller_template_rectangle;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c29_controller_template_rectangle;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c29_controller_template_rectangle;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c29_controller_template_rectangle;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c29_controller_template_rectangle;
  chartInstance->chartInfo.mdlStart = mdlStart_c29_controller_template_rectangle;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c29_controller_template_rectangle;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c29_controller_template_rectangle;
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

void c29_controller_template_rectangle_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c29_controller_template_rectangle(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c29_controller_template_rectangle(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c29_controller_template_rectangle(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c29_controller_template_rectangle_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
