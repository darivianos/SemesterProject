/* Include files */

#include "blascompat32.h"
#include "Hquad_control_LIB_MPC_sfun.h"
#include "c23_Hquad_control_LIB_MPC.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hquad_control_LIB_MPC_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c23_debug_family_names[10] = { "pred_horizon_yaw", "yaw0",
  "yaw_diff", "yaw_offset", "nargin", "nargout", "X_ref_yaw_unbounded",
  "yaw_meas", "idx", "X_ref_yaw" };

/* Function Declarations */
static void initialize_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initialize_params_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void enable_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void disable_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c23_update_debugger_state_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void ext_mode_exec_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void set_sim_state_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray
   *c23_st);
static void finalize_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void sf_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initSimStructsc23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static void c23_emlrt_marshallIn(SFc23_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c23_X_ref_yaw, const char_T *c23_identifier,
  real_T c23_y[62]);
static void c23_b_emlrt_marshallIn(SFc23_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[62]);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_c_emlrt_marshallIn(SFc23_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_d_emlrt_marshallIn(SFc23_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static uint8_T c23_e_emlrt_marshallIn(SFc23_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c23_is_active_c23_Hquad_control_LIB_MPC, const
  char_T *c23_identifier);
static uint8_T c23_f_emlrt_marshallIn(SFc23_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void init_dsm_address_info(SFc23_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T *c23_sfEvent;
  uint8_T *c23_is_active_c23_Hquad_control_LIB_MPC;
  c23_is_active_c23_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c23_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c23_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c23_is_active_c23_Hquad_control_LIB_MPC = 0U;
}

static void initialize_params_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void enable_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c23_update_debugger_state_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  c23_update_debugger_state_c23_Hquad_control_LIB_MPC(chartInstance);
}

static const mxArray *get_sim_state_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  int32_T c23_i0;
  real_T c23_u[62];
  const mxArray *c23_b_y = NULL;
  uint8_T c23_hoistedGlobal;
  uint8_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  uint8_T *c23_is_active_c23_Hquad_control_LIB_MPC;
  real_T (*c23_X_ref_yaw)[62];
  c23_X_ref_yaw = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c23_is_active_c23_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellarray(2), FALSE);
  for (c23_i0 = 0; c23_i0 < 62; c23_i0++) {
    c23_u[c23_i0] = (*c23_X_ref_yaw)[c23_i0];
  }

  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 2, 2, 31),
                FALSE);
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_hoistedGlobal = *c23_is_active_c23_Hquad_control_LIB_MPC;
  c23_b_u = c23_hoistedGlobal;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c23_y, 1, c23_c_y);
  sf_mex_assign(&c23_st, c23_y, FALSE);
  return c23_st;
}

static void set_sim_state_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray
   *c23_st)
{
  const mxArray *c23_u;
  real_T c23_dv0[62];
  int32_T c23_i1;
  boolean_T *c23_doneDoubleBufferReInit;
  uint8_T *c23_is_active_c23_Hquad_control_LIB_MPC;
  real_T (*c23_X_ref_yaw)[62];
  c23_X_ref_yaw = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c23_is_active_c23_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c23_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c23_doneDoubleBufferReInit = TRUE;
  c23_u = sf_mex_dup(c23_st);
  c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 0)),
                       "X_ref_yaw", c23_dv0);
  for (c23_i1 = 0; c23_i1 < 62; c23_i1++) {
    (*c23_X_ref_yaw)[c23_i1] = c23_dv0[c23_i1];
  }

  *c23_is_active_c23_Hquad_control_LIB_MPC = c23_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 1)),
     "is_active_c23_Hquad_control_LIB_MPC");
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_Hquad_control_LIB_MPC(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void sf_c23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T c23_i2;
  int32_T c23_i3;
  real_T c23_hoistedGlobal;
  real_T c23_b_hoistedGlobal;
  int32_T c23_i4;
  real_T c23_X_ref_yaw_unbounded[1864];
  real_T c23_yaw_meas;
  real_T c23_idx;
  uint32_T c23_debug_family_var_map[10];
  real_T c23_pred_horizon_yaw;
  real_T c23_yaw0;
  real_T c23_yaw_diff;
  real_T c23_yaw_offset;
  real_T c23_nargin = 3.0;
  real_T c23_nargout = 1.0;
  real_T c23_X_ref_yaw[62];
  real_T c23_A;
  real_T c23_x;
  real_T c23_b_x;
  real_T c23_y;
  real_T c23_c_x;
  real_T c23_d_x;
  real_T c23_e_x;
  real_T c23_a;
  real_T c23_b_y;
  real_T c23_b_a;
  int32_T c23_i5;
  int32_T c23_i6;
  int32_T c23_i7;
  real_T *c23_b_idx;
  real_T *c23_b_yaw_meas;
  int32_T *c23_sfEvent;
  real_T (*c23_b_X_ref_yaw)[62];
  real_T (*c23_b_X_ref_yaw_unbounded)[1864];
  c23_b_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c23_b_yaw_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c23_b_X_ref_yaw = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c23_b_X_ref_yaw_unbounded = (real_T (*)[1864])ssGetInputPortSignal
    (chartInstance->S, 0);
  c23_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, *c23_sfEvent);
  for (c23_i2 = 0; c23_i2 < 1864; c23_i2++) {
    _SFD_DATA_RANGE_CHECK((*c23_b_X_ref_yaw_unbounded)[c23_i2], 0U);
  }

  for (c23_i3 = 0; c23_i3 < 62; c23_i3++) {
    _SFD_DATA_RANGE_CHECK((*c23_b_X_ref_yaw)[c23_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c23_b_yaw_meas, 2U);
  _SFD_DATA_RANGE_CHECK(*c23_b_idx, 3U);
  *c23_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, *c23_sfEvent);
  c23_hoistedGlobal = *c23_b_yaw_meas;
  c23_b_hoistedGlobal = *c23_b_idx;
  for (c23_i4 = 0; c23_i4 < 1864; c23_i4++) {
    c23_X_ref_yaw_unbounded[c23_i4] = (*c23_b_X_ref_yaw_unbounded)[c23_i4];
  }

  c23_yaw_meas = c23_hoistedGlobal;
  c23_idx = c23_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c23_debug_family_names,
    c23_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c23_pred_horizon_yaw, 0U, c23_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c23_yaw0, 1U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_yaw_diff, 2U,
    c23_b_sf_marshallOut, c23_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_yaw_offset, 3U,
    c23_b_sf_marshallOut, c23_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_nargin, 4U, c23_b_sf_marshallOut,
    c23_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_nargout, 5U,
    c23_b_sf_marshallOut, c23_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c23_X_ref_yaw_unbounded, 6U,
    c23_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c23_yaw_meas, 7U, c23_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c23_idx, 8U, c23_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c23_X_ref_yaw, 9U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c23_sfEvent, 3);
  c23_pred_horizon_yaw = 30.0;
  _SFD_EML_CALL(0U, *c23_sfEvent, 5);
  c23_yaw0 = c23_X_ref_yaw_unbounded[(_SFD_EML_ARRAY_BOUNDS_CHECK(
    "X_ref_yaw_unbounded", (int32_T)_SFD_INTEGER_CHECK("idx", c23_idx), 1, 932,
    2, 0) - 1) << 1];
  _SFD_EML_CALL(0U, *c23_sfEvent, 6);
  c23_yaw_diff = c23_yaw_meas - c23_yaw0;
  _SFD_EML_CALL(0U, *c23_sfEvent, 9);
  c23_A = c23_yaw_diff;
  c23_x = c23_A;
  c23_b_x = c23_x;
  c23_y = c23_b_x / 6.2831853071795862;
  c23_c_x = c23_y;
  c23_d_x = c23_c_x;
  c23_e_x = c23_d_x;
  if (muDoubleScalarAbs(c23_e_x) > 4.503599627370496E+15) {
  } else if (c23_e_x >= 0.5) {
    c23_d_x = muDoubleScalarFloor(c23_e_x + 0.5);
  } else if (c23_e_x > -0.5) {
    c23_d_x = c23_e_x * 0.0;
  } else {
    c23_d_x = muDoubleScalarCeil(c23_e_x - 0.5);
  }

  c23_a = c23_d_x;
  c23_b_y = c23_a * 2.0;
  c23_b_a = c23_b_y;
  c23_yaw_offset = c23_b_a * 3.1415926535897931;
  _SFD_EML_CALL(0U, *c23_sfEvent, 11);
  for (c23_i5 = 0; c23_i5 < 31; c23_i5++) {
    c23_X_ref_yaw[c23_i5 << 1] = c23_X_ref_yaw_unbounded
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("X_ref_yaw_unbounded", (int32_T)
         _SFD_INTEGER_CHECK("idx:idx+pred_horizon_yaw", c23_idx + (real_T)c23_i5),
         1, 932, 2, 0) - 1) << 1] + c23_yaw_offset;
  }

  for (c23_i6 = 0; c23_i6 < 31; c23_i6++) {
    c23_X_ref_yaw[1 + (c23_i6 << 1)] = c23_X_ref_yaw_unbounded[1 +
      ((_SFD_EML_ARRAY_BOUNDS_CHECK("X_ref_yaw_unbounded", (int32_T)
         _SFD_INTEGER_CHECK("idx:idx+pred_horizon_yaw", c23_idx + (real_T)c23_i6),
         1, 932, 2, 0) - 1) << 1)];
  }

  _SFD_EML_CALL(0U, *c23_sfEvent, -11);
  sf_debug_symbol_scope_pop();
  for (c23_i7 = 0; c23_i7 < 62; c23_i7++) {
    (*c23_b_X_ref_yaw)[c23_i7] = c23_X_ref_yaw[c23_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, *c23_sfEvent);
  sf_debug_check_for_state_inconsistency(_Hquad_control_LIB_MPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc23_Hquad_control_LIB_MPC
  (SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber)
{
}

static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i8;
  int32_T c23_i9;
  int32_T c23_i10;
  real_T c23_b_inData[62];
  int32_T c23_i11;
  int32_T c23_i12;
  int32_T c23_i13;
  real_T c23_u[62];
  const mxArray *c23_y = NULL;
  SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_i8 = 0;
  for (c23_i9 = 0; c23_i9 < 31; c23_i9++) {
    for (c23_i10 = 0; c23_i10 < 2; c23_i10++) {
      c23_b_inData[c23_i10 + c23_i8] = (*(real_T (*)[62])c23_inData)[c23_i10 +
        c23_i8];
    }

    c23_i8 += 2;
  }

  c23_i11 = 0;
  for (c23_i12 = 0; c23_i12 < 31; c23_i12++) {
    for (c23_i13 = 0; c23_i13 < 2; c23_i13++) {
      c23_u[c23_i13 + c23_i11] = c23_b_inData[c23_i13 + c23_i11];
    }

    c23_i11 += 2;
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 2, 2, 31),
                FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static void c23_emlrt_marshallIn(SFc23_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c23_X_ref_yaw, const char_T *c23_identifier,
  real_T c23_y[62])
{
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_X_ref_yaw), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_X_ref_yaw);
}

static void c23_b_emlrt_marshallIn(SFc23_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId,
  real_T c23_y[62])
{
  real_T c23_dv1[62];
  int32_T c23_i14;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), c23_dv1, 1, 0, 0U, 1, 0U, 2, 2,
                31);
  for (c23_i14 = 0; c23_i14 < 62; c23_i14++) {
    c23_y[c23_i14] = c23_dv1[c23_i14];
  }

  sf_mex_destroy(&c23_u);
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_X_ref_yaw;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y[62];
  int32_T c23_i15;
  int32_T c23_i16;
  int32_T c23_i17;
  SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c23_X_ref_yaw = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_X_ref_yaw), &c23_thisId,
    c23_y);
  sf_mex_destroy(&c23_X_ref_yaw);
  c23_i15 = 0;
  for (c23_i16 = 0; c23_i16 < 31; c23_i16++) {
    for (c23_i17 = 0; c23_i17 < 2; c23_i17++) {
      (*(real_T (*)[62])c23_outData)[c23_i17 + c23_i15] = c23_y[c23_i17 +
        c23_i15];
    }

    c23_i15 += 2;
  }

  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i18;
  int32_T c23_i19;
  int32_T c23_i20;
  real_T c23_b_inData[1864];
  int32_T c23_i21;
  int32_T c23_i22;
  int32_T c23_i23;
  real_T c23_u[1864];
  const mxArray *c23_y = NULL;
  SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_i18 = 0;
  for (c23_i19 = 0; c23_i19 < 932; c23_i19++) {
    for (c23_i20 = 0; c23_i20 < 2; c23_i20++) {
      c23_b_inData[c23_i20 + c23_i18] = (*(real_T (*)[1864])c23_inData)[c23_i20
        + c23_i18];
    }

    c23_i18 += 2;
  }

  c23_i21 = 0;
  for (c23_i22 = 0; c23_i22 < 932; c23_i22++) {
    for (c23_i23 = 0; c23_i23 < 2; c23_i23++) {
      c23_u[c23_i23 + c23_i21] = c23_b_inData[c23_i23 + c23_i21];
    }

    c23_i21 += 2;
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 2, 2, 932),
                FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static real_T c23_c_emlrt_marshallIn(SFc23_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d0;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d0, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_nargout;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c23_nargout = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_nargout),
    &c23_thisId);
  sf_mex_destroy(&c23_nargout);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

const mxArray *sf_c23_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo;
  c23_ResolvedFunctionInfo c23_info[8];
  c23_ResolvedFunctionInfo (*c23_b_info)[8];
  const mxArray *c23_m0 = NULL;
  int32_T c23_i24;
  c23_ResolvedFunctionInfo *c23_r0;
  c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  c23_b_info = (c23_ResolvedFunctionInfo (*)[8])c23_info;
  (*c23_b_info)[0].context = "";
  (*c23_b_info)[0].name = "mtimes";
  (*c23_b_info)[0].dominantType = "double";
  (*c23_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c23_b_info)[0].fileTimeLo = 1289519692U;
  (*c23_b_info)[0].fileTimeHi = 0U;
  (*c23_b_info)[0].mFileTimeLo = 0U;
  (*c23_b_info)[0].mFileTimeHi = 0U;
  (*c23_b_info)[1].context = "";
  (*c23_b_info)[1].name = "mrdivide";
  (*c23_b_info)[1].dominantType = "double";
  (*c23_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c23_b_info)[1].fileTimeLo = 1310137456U;
  (*c23_b_info)[1].fileTimeHi = 0U;
  (*c23_b_info)[1].mFileTimeLo = 1289519692U;
  (*c23_b_info)[1].mFileTimeHi = 0U;
  (*c23_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c23_b_info)[2].name = "rdivide";
  (*c23_b_info)[2].dominantType = "double";
  (*c23_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c23_b_info)[2].fileTimeLo = 1286818844U;
  (*c23_b_info)[2].fileTimeHi = 0U;
  (*c23_b_info)[2].mFileTimeLo = 0U;
  (*c23_b_info)[2].mFileTimeHi = 0U;
  (*c23_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c23_b_info)[3].name = "eml_div";
  (*c23_b_info)[3].dominantType = "double";
  (*c23_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c23_b_info)[3].fileTimeLo = 1305318000U;
  (*c23_b_info)[3].fileTimeHi = 0U;
  (*c23_b_info)[3].mFileTimeLo = 0U;
  (*c23_b_info)[3].mFileTimeHi = 0U;
  (*c23_b_info)[4].context = "";
  (*c23_b_info)[4].name = "round";
  (*c23_b_info)[4].dominantType = "double";
  (*c23_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c23_b_info)[4].fileTimeLo = 1286818748U;
  (*c23_b_info)[4].fileTimeHi = 0U;
  (*c23_b_info)[4].mFileTimeLo = 0U;
  (*c23_b_info)[4].mFileTimeHi = 0U;
  (*c23_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c23_b_info)[5].name = "eml_scalar_round";
  (*c23_b_info)[5].dominantType = "double";
  (*c23_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  (*c23_b_info)[5].fileTimeLo = 1289519628U;
  (*c23_b_info)[5].fileTimeHi = 0U;
  (*c23_b_info)[5].mFileTimeLo = 0U;
  (*c23_b_info)[5].mFileTimeHi = 0U;
  (*c23_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  (*c23_b_info)[6].name = "eps";
  (*c23_b_info)[6].dominantType = "char";
  (*c23_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c23_b_info)[6].fileTimeLo = 1286818686U;
  (*c23_b_info)[6].fileTimeHi = 0U;
  (*c23_b_info)[6].mFileTimeLo = 0U;
  (*c23_b_info)[6].mFileTimeHi = 0U;
  (*c23_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c23_b_info)[7].name = "eml_is_float_class";
  (*c23_b_info)[7].dominantType = "char";
  (*c23_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  (*c23_b_info)[7].fileTimeLo = 1286818782U;
  (*c23_b_info)[7].fileTimeHi = 0U;
  (*c23_b_info)[7].mFileTimeLo = 0U;
  (*c23_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c23_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c23_i24 = 0; c23_i24 < 8; c23_i24++) {
    c23_r0 = &c23_info[c23_i24];
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->context)), "context", "nameCaptureInfo",
                    c23_i24);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->name)), "name", "nameCaptureInfo",
                    c23_i24);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      c23_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c23_i24);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->resolved)), "resolved",
                    "nameCaptureInfo", c23_i24);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c23_i24);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c23_i24);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      &c23_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c23_i24);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      &c23_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c23_i24);
  }

  sf_mex_assign(&c23_nameCaptureInfo, c23_m0, FALSE);
  return c23_nameCaptureInfo;
}

static const mxArray *c23_d_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static int32_T c23_d_emlrt_marshallIn(SFc23_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i25;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i25, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i25;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c23_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static uint8_T c23_e_emlrt_marshallIn(SFc23_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c23_is_active_c23_Hquad_control_LIB_MPC, const
  char_T *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_is_active_c23_Hquad_control_LIB_MPC), &c23_thisId);
  sf_mex_destroy(&c23_is_active_c23_Hquad_control_LIB_MPC);
  return c23_y;
}

static uint8_T c23_f_emlrt_marshallIn(SFc23_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void init_dsm_address_info(SFc23_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c23_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3337894948U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2084331787U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3960361318U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(784680715U);
}

mxArray *sf_c23_Hquad_control_LIB_MPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("QWvqjCTmE70DHayvSjWvyB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(932);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(31);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c23_Hquad_control_LIB_MPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[18],T\"X_ref_yaw\",},{M[8],M[0],T\"is_active_c23_Hquad_control_LIB_MPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_Hquad_control_LIB_MPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
    chartInstance = (SFc23_Hquad_control_LIB_MPCInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Hquad_control_LIB_MPCMachineNumber_,
           23,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"X_ref_yaw_unbounded");
          _SFD_SET_DATA_PROPS(1,2,0,1,"X_ref_yaw");
          _SFD_SET_DATA_PROPS(2,1,1,0,"yaw_meas");
          _SFD_SET_DATA_PROPS(3,1,1,0,"idx");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,310);
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
          dimVector[0]= 2;
          dimVector[1]= 932;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 31;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)
            c23_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c23_yaw_meas;
          real_T *c23_idx;
          real_T (*c23_X_ref_yaw_unbounded)[1864];
          real_T (*c23_X_ref_yaw)[62];
          c23_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c23_yaw_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c23_X_ref_yaw = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S,
            1);
          c23_X_ref_yaw_unbounded = (real_T (*)[1864])ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c23_X_ref_yaw_unbounded);
          _SFD_SET_DATA_VALUE_PTR(1U, *c23_X_ref_yaw);
          _SFD_SET_DATA_VALUE_PTR(2U, c23_yaw_meas);
          _SFD_SET_DATA_VALUE_PTR(3U, c23_idx);
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
      23, "dworkChecksum");
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

static void sf_opaque_initialize_c23_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc23_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc23_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c23_Hquad_control_LIB_MPC
    ((SFc23_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
  initialize_c23_Hquad_control_LIB_MPC
    ((SFc23_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c23_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  enable_c23_Hquad_control_LIB_MPC((SFc23_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c23_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  disable_c23_Hquad_control_LIB_MPC((SFc23_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c23_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_c23_Hquad_control_LIB_MPC((SFc23_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c23_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  ext_mode_exec_c23_Hquad_control_LIB_MPC
    ((SFc23_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c23_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c23_Hquad_control_LIB_MPC
    ((SFc23_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_Hquad_control_LIB_MPC();/* state var info */
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

extern void sf_internal_set_sim_state_c23_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_Hquad_control_LIB_MPC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c23_Hquad_control_LIB_MPC
    ((SFc23_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c23_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c23_Hquad_control_LIB_MPC(S);
}

static void sf_opaque_set_sim_state_c23_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c23_Hquad_control_LIB_MPC(S, st);
}

static void sf_opaque_terminate_c23_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_Hquad_control_LIB_MPCInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c23_Hquad_control_LIB_MPC
      ((SFc23_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Hquad_control_LIB_MPC_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc23_Hquad_control_LIB_MPC
    ((SFc23_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_Hquad_control_LIB_MPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c23_Hquad_control_LIB_MPC
      ((SFc23_Hquad_control_LIB_MPCInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c23_Hquad_control_LIB_MPC_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c23_Hquad_control_LIB_MPC\",T\"is_active_c23_Hquad_control_LIB_MPC\"}}"
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

static void mdlSetWorkWidths_c23_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,23);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,23,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,23,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,23,3);
      sf_mark_chart_reusable_outputs(S,infoStruct,23,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1062451521U));
  ssSetChecksum1(S,(2756171425U));
  ssSetChecksum2(S,(571489832U));
  ssSetChecksum3(S,(1905191631U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c23_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_Hquad_control_LIB_MPC(SimStruct *S)
{
  SFc23_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_MPCInstanceStruct *)malloc(sizeof
    (SFc23_Hquad_control_LIB_MPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_Hquad_control_LIB_MPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c23_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c23_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c23_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c23_Hquad_control_LIB_MPC;
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

void c23_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_Hquad_control_LIB_MPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_Hquad_control_LIB_MPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
