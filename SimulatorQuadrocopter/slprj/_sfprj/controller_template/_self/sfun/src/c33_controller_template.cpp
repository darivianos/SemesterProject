/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c33_controller_template.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c33_debug_family_names[10] = { "pred_horizon_yaw", "yaw0",
  "yaw_diff", "yaw_offset", "nargin", "nargout", "X_ref_yaw_unbounded",
  "yaw_meas", "idx", "X_ref_yaw" };

/* Function Declarations */
static void initialize_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance);
static void enable_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance);
static void disable_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance);
static void c33_update_debugger_state_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance, const mxArray *c33_st);
static void finalize_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance);
static void sf_c33_controller_template(SFc33_controller_templateInstanceStruct
  *chartInstance);
static void initSimStructsc33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c33_machineNumber, uint32_T
  c33_chartNumber);
static const mxArray *c33_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static void c33_emlrt_marshallIn(SFc33_controller_templateInstanceStruct
  *chartInstance, const mxArray *c33_X_ref_yaw, const char_T *c33_identifier,
  real_T c33_y[62]);
static void c33_b_emlrt_marshallIn(SFc33_controller_templateInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[62]);
static void c33_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_b_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static const mxArray *c33_c_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static real_T c33_c_emlrt_marshallIn(SFc33_controller_templateInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static const mxArray *c33_d_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData);
static int32_T c33_d_emlrt_marshallIn(SFc33_controller_templateInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void c33_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData);
static uint8_T c33_e_emlrt_marshallIn(SFc33_controller_templateInstanceStruct
  *chartInstance, const mxArray *c33_is_active_c33_controller_template, const
  char_T *c33_identifier);
static uint8_T c33_f_emlrt_marshallIn(SFc33_controller_templateInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId);
static void init_dsm_address_info(SFc33_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c33_sfEvent;
  uint8_T *c33_is_active_c33_controller_template;
  c33_is_active_c33_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c33_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c33_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c33_is_active_c33_controller_template = 0U;
}

static void initialize_params_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c33_update_debugger_state_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance)
{
  c33_update_debugger_state_c33_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c33_st;
  const mxArray *c33_y = NULL;
  int32_T c33_i0;
  real_T c33_u[62];
  const mxArray *c33_b_y = NULL;
  uint8_T c33_hoistedGlobal;
  uint8_T c33_b_u;
  const mxArray *c33_c_y = NULL;
  uint8_T *c33_is_active_c33_controller_template;
  real_T (*c33_X_ref_yaw)[62];
  c33_X_ref_yaw = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c33_is_active_c33_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c33_st = NULL;
  c33_st = NULL;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_createcellarray(2), FALSE);
  for (c33_i0 = 0; c33_i0 < 62; c33_i0++) {
    c33_u[c33_i0] = (*c33_X_ref_yaw)[c33_i0];
  }

  c33_b_y = NULL;
  sf_mex_assign(&c33_b_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 2, 2, 31),
                FALSE);
  sf_mex_setcell(c33_y, 0, c33_b_y);
  c33_hoistedGlobal = *c33_is_active_c33_controller_template;
  c33_b_u = c33_hoistedGlobal;
  c33_c_y = NULL;
  sf_mex_assign(&c33_c_y, sf_mex_create("y", &c33_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c33_y, 1, c33_c_y);
  sf_mex_assign(&c33_st, c33_y, FALSE);
  return c33_st;
}

static void set_sim_state_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance, const mxArray *c33_st)
{
  const mxArray *c33_u;
  real_T c33_dv0[62];
  int32_T c33_i1;
  boolean_T *c33_doneDoubleBufferReInit;
  uint8_T *c33_is_active_c33_controller_template;
  real_T (*c33_X_ref_yaw)[62];
  c33_X_ref_yaw = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c33_is_active_c33_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c33_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c33_doneDoubleBufferReInit = TRUE;
  c33_u = sf_mex_dup(c33_st);
  c33_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c33_u, 0)),
                       "X_ref_yaw", c33_dv0);
  for (c33_i1 = 0; c33_i1 < 62; c33_i1++) {
    (*c33_X_ref_yaw)[c33_i1] = c33_dv0[c33_i1];
  }

  *c33_is_active_c33_controller_template = c33_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c33_u, 1)), "is_active_c33_controller_template");
  sf_mex_destroy(&c33_u);
  c33_update_debugger_state_c33_controller_template(chartInstance);
  sf_mex_destroy(&c33_st);
}

static void finalize_c33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c33_controller_template(SFc33_controller_templateInstanceStruct
  *chartInstance)
{
  int32_T c33_i2;
  int32_T c33_i3;
  real_T c33_hoistedGlobal;
  real_T c33_b_hoistedGlobal;
  int32_T c33_i4;
  real_T c33_X_ref_yaw_unbounded[8];
  real_T c33_yaw_meas;
  real_T c33_idx;
  uint32_T c33_debug_family_var_map[10];
  real_T c33_pred_horizon_yaw;
  real_T c33_yaw0;
  real_T c33_yaw_diff;
  real_T c33_yaw_offset;
  real_T c33_nargin = 3.0;
  real_T c33_nargout = 1.0;
  real_T c33_X_ref_yaw[62];
  real_T c33_A;
  real_T c33_x;
  real_T c33_b_x;
  real_T c33_y;
  real_T c33_c_x;
  real_T c33_d_x;
  real_T c33_e_x;
  real_T c33_a;
  real_T c33_b_y;
  real_T c33_b_a;
  int32_T c33_i5;
  int32_T c33_i6;
  int32_T c33_i7;
  real_T *c33_b_idx;
  real_T *c33_b_yaw_meas;
  int32_T *c33_sfEvent;
  real_T (*c33_b_X_ref_yaw)[62];
  real_T (*c33_b_X_ref_yaw_unbounded)[8];
  c33_b_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c33_b_yaw_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c33_b_X_ref_yaw = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c33_b_X_ref_yaw_unbounded = (real_T (*)[8])ssGetInputPortSignal
    (chartInstance->S, 0);
  c33_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 25U, *c33_sfEvent);
  for (c33_i2 = 0; c33_i2 < 8; c33_i2++) {
    _SFD_DATA_RANGE_CHECK((*c33_b_X_ref_yaw_unbounded)[c33_i2], 0U);
  }

  for (c33_i3 = 0; c33_i3 < 62; c33_i3++) {
    _SFD_DATA_RANGE_CHECK((*c33_b_X_ref_yaw)[c33_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c33_b_yaw_meas, 2U);
  _SFD_DATA_RANGE_CHECK(*c33_b_idx, 3U);
  *c33_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 25U, *c33_sfEvent);
  c33_hoistedGlobal = *c33_b_yaw_meas;
  c33_b_hoistedGlobal = *c33_b_idx;
  for (c33_i4 = 0; c33_i4 < 8; c33_i4++) {
    c33_X_ref_yaw_unbounded[c33_i4] = (*c33_b_X_ref_yaw_unbounded)[c33_i4];
  }

  c33_yaw_meas = c33_hoistedGlobal;
  c33_idx = c33_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c33_debug_family_names,
    c33_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c33_pred_horizon_yaw, 0U, c33_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c33_yaw0, 1U, c33_b_sf_marshallOut,
    c33_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c33_yaw_diff, 2U,
    c33_b_sf_marshallOut, c33_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c33_yaw_offset, 3U,
    c33_b_sf_marshallOut, c33_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c33_nargin, 4U, c33_b_sf_marshallOut,
    c33_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c33_nargout, 5U,
    c33_b_sf_marshallOut, c33_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c33_X_ref_yaw_unbounded, 6U,
    c33_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c33_yaw_meas, 7U, c33_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c33_idx, 8U, c33_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c33_X_ref_yaw, 9U, c33_sf_marshallOut,
    c33_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c33_sfEvent, 3);
  c33_pred_horizon_yaw = 30.0;
  _SFD_EML_CALL(0U, *c33_sfEvent, 5);
  c33_yaw0 = c33_X_ref_yaw_unbounded[(_SFD_EML_ARRAY_BOUNDS_CHECK(
    "X_ref_yaw_unbounded", (int32_T)_SFD_INTEGER_CHECK("idx", c33_idx), 1, 4, 2,
    0) - 1) << 1];
  _SFD_EML_CALL(0U, *c33_sfEvent, 6);
  c33_yaw_diff = c33_yaw_meas - c33_yaw0;
  _SFD_EML_CALL(0U, *c33_sfEvent, 9);
  c33_A = c33_yaw_diff;
  c33_x = c33_A;
  c33_b_x = c33_x;
  c33_y = c33_b_x / 6.2831853071795862;
  c33_c_x = c33_y;
  c33_d_x = c33_c_x;
  c33_e_x = c33_d_x;
  if (muDoubleScalarAbs(c33_e_x) > 4.503599627370496E+15) {
  } else if (c33_e_x >= 0.5) {
    c33_d_x = muDoubleScalarFloor(c33_e_x + 0.5);
  } else if (c33_e_x > -0.5) {
    c33_d_x = c33_e_x * 0.0;
  } else {
    c33_d_x = muDoubleScalarCeil(c33_e_x - 0.5);
  }

  c33_a = c33_d_x;
  c33_b_y = c33_a * 2.0;
  c33_b_a = c33_b_y;
  c33_yaw_offset = c33_b_a * 3.1415926535897931;
  _SFD_EML_CALL(0U, *c33_sfEvent, 11);
  for (c33_i5 = 0; c33_i5 < 31; c33_i5++) {
    c33_X_ref_yaw[c33_i5 << 1] = c33_X_ref_yaw_unbounded
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("X_ref_yaw_unbounded", (int32_T)
         _SFD_INTEGER_CHECK("idx:idx+pred_horizon_yaw", c33_idx + (real_T)c33_i5),
         1, 4, 2, 0) - 1) << 1] + c33_yaw_offset;
  }

  for (c33_i6 = 0; c33_i6 < 31; c33_i6++) {
    c33_X_ref_yaw[1 + (c33_i6 << 1)] = c33_X_ref_yaw_unbounded[1 +
      ((_SFD_EML_ARRAY_BOUNDS_CHECK("X_ref_yaw_unbounded", (int32_T)
         _SFD_INTEGER_CHECK("idx:idx+pred_horizon_yaw", c33_idx + (real_T)c33_i6),
         1, 4, 2, 0) - 1) << 1)];
  }

  _SFD_EML_CALL(0U, *c33_sfEvent, -11);
  sf_debug_symbol_scope_pop();
  for (c33_i7 = 0; c33_i7 < 62; c33_i7++) {
    (*c33_b_X_ref_yaw)[c33_i7] = c33_X_ref_yaw[c33_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, *c33_sfEvent);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc33_controller_template
  (SFc33_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c33_machineNumber, uint32_T
  c33_chartNumber)
{
}

static const mxArray *c33_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i8;
  int32_T c33_i9;
  int32_T c33_i10;
  real_T c33_b_inData[62];
  int32_T c33_i11;
  int32_T c33_i12;
  int32_T c33_i13;
  real_T c33_u[62];
  const mxArray *c33_y = NULL;
  SFc33_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc33_controller_templateInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_i8 = 0;
  for (c33_i9 = 0; c33_i9 < 31; c33_i9++) {
    for (c33_i10 = 0; c33_i10 < 2; c33_i10++) {
      c33_b_inData[c33_i10 + c33_i8] = (*(real_T (*)[62])c33_inData)[c33_i10 +
        c33_i8];
    }

    c33_i8 += 2;
  }

  c33_i11 = 0;
  for (c33_i12 = 0; c33_i12 < 31; c33_i12++) {
    for (c33_i13 = 0; c33_i13 < 2; c33_i13++) {
      c33_u[c33_i13 + c33_i11] = c33_b_inData[c33_i13 + c33_i11];
    }

    c33_i11 += 2;
  }

  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 2, 2, 31),
                FALSE);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static void c33_emlrt_marshallIn(SFc33_controller_templateInstanceStruct
  *chartInstance, const mxArray *c33_X_ref_yaw, const char_T *c33_identifier,
  real_T c33_y[62])
{
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_X_ref_yaw), &c33_thisId,
    c33_y);
  sf_mex_destroy(&c33_X_ref_yaw);
}

static void c33_b_emlrt_marshallIn(SFc33_controller_templateInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId,
  real_T c33_y[62])
{
  real_T c33_dv1[62];
  int32_T c33_i14;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), c33_dv1, 1, 0, 0U, 1, 0U, 2, 2,
                31);
  for (c33_i14 = 0; c33_i14 < 62; c33_i14++) {
    c33_y[c33_i14] = c33_dv1[c33_i14];
  }

  sf_mex_destroy(&c33_u);
}

static void c33_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_X_ref_yaw;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y[62];
  int32_T c33_i15;
  int32_T c33_i16;
  int32_T c33_i17;
  SFc33_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc33_controller_templateInstanceStruct *)chartInstanceVoid;
  c33_X_ref_yaw = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_X_ref_yaw), &c33_thisId,
    c33_y);
  sf_mex_destroy(&c33_X_ref_yaw);
  c33_i15 = 0;
  for (c33_i16 = 0; c33_i16 < 31; c33_i16++) {
    for (c33_i17 = 0; c33_i17 < 2; c33_i17++) {
      (*(real_T (*)[62])c33_outData)[c33_i17 + c33_i15] = c33_y[c33_i17 +
        c33_i15];
    }

    c33_i15 += 2;
  }

  sf_mex_destroy(&c33_mxArrayInData);
}

static const mxArray *c33_b_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  real_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc33_controller_templateInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(real_T *)c33_inData;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static const mxArray *c33_c_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_i18;
  int32_T c33_i19;
  int32_T c33_i20;
  real_T c33_b_inData[8];
  int32_T c33_i21;
  int32_T c33_i22;
  int32_T c33_i23;
  real_T c33_u[8];
  const mxArray *c33_y = NULL;
  SFc33_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc33_controller_templateInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_i18 = 0;
  for (c33_i19 = 0; c33_i19 < 4; c33_i19++) {
    for (c33_i20 = 0; c33_i20 < 2; c33_i20++) {
      c33_b_inData[c33_i20 + c33_i18] = (*(real_T (*)[8])c33_inData)[c33_i20 +
        c33_i18];
    }

    c33_i18 += 2;
  }

  c33_i21 = 0;
  for (c33_i22 = 0; c33_i22 < 4; c33_i22++) {
    for (c33_i23 = 0; c33_i23 < 2; c33_i23++) {
      c33_u[c33_i23 + c33_i21] = c33_b_inData[c33_i23 + c33_i21];
    }

    c33_i21 += 2;
  }

  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", c33_u, 0, 0U, 1U, 0U, 2, 2, 4), FALSE);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static real_T c33_c_emlrt_marshallIn(SFc33_controller_templateInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  real_T c33_y;
  real_T c33_d0;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_d0, 1, 0, 0U, 0, 0U, 0);
  c33_y = c33_d0;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_nargout;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  real_T c33_y;
  SFc33_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc33_controller_templateInstanceStruct *)chartInstanceVoid;
  c33_nargout = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_nargout),
    &c33_thisId);
  sf_mex_destroy(&c33_nargout);
  *(real_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

const mxArray *sf_c33_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c33_nameCaptureInfo;
  c33_ResolvedFunctionInfo c33_info[8];
  c33_ResolvedFunctionInfo (*c33_b_info)[8];
  const mxArray *c33_m0 = NULL;
  int32_T c33_i24;
  c33_ResolvedFunctionInfo *c33_r0;
  c33_nameCaptureInfo = NULL;
  c33_nameCaptureInfo = NULL;
  c33_b_info = (c33_ResolvedFunctionInfo (*)[8])c33_info;
  (*c33_b_info)[0].context = "";
  (*c33_b_info)[0].name = "mtimes";
  (*c33_b_info)[0].dominantType = "double";
  (*c33_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c33_b_info)[0].fileTimeLo = 1289519692U;
  (*c33_b_info)[0].fileTimeHi = 0U;
  (*c33_b_info)[0].mFileTimeLo = 0U;
  (*c33_b_info)[0].mFileTimeHi = 0U;
  (*c33_b_info)[1].context = "";
  (*c33_b_info)[1].name = "mrdivide";
  (*c33_b_info)[1].dominantType = "double";
  (*c33_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c33_b_info)[1].fileTimeLo = 1310137456U;
  (*c33_b_info)[1].fileTimeHi = 0U;
  (*c33_b_info)[1].mFileTimeLo = 1289519692U;
  (*c33_b_info)[1].mFileTimeHi = 0U;
  (*c33_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c33_b_info)[2].name = "rdivide";
  (*c33_b_info)[2].dominantType = "double";
  (*c33_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c33_b_info)[2].fileTimeLo = 1286818844U;
  (*c33_b_info)[2].fileTimeHi = 0U;
  (*c33_b_info)[2].mFileTimeLo = 0U;
  (*c33_b_info)[2].mFileTimeHi = 0U;
  (*c33_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c33_b_info)[3].name = "eml_div";
  (*c33_b_info)[3].dominantType = "double";
  (*c33_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c33_b_info)[3].fileTimeLo = 1305318000U;
  (*c33_b_info)[3].fileTimeHi = 0U;
  (*c33_b_info)[3].mFileTimeLo = 0U;
  (*c33_b_info)[3].mFileTimeHi = 0U;
  (*c33_b_info)[4].context = "";
  (*c33_b_info)[4].name = "round";
  (*c33_b_info)[4].dominantType = "double";
  (*c33_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c33_b_info)[4].fileTimeLo = 1286818748U;
  (*c33_b_info)[4].fileTimeHi = 0U;
  (*c33_b_info)[4].mFileTimeLo = 0U;
  (*c33_b_info)[4].mFileTimeHi = 0U;
  (*c33_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c33_b_info)[5].name = "eml_scalar_round";
  (*c33_b_info)[5].dominantType = "double";
  (*c33_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  (*c33_b_info)[5].fileTimeLo = 1289519628U;
  (*c33_b_info)[5].fileTimeHi = 0U;
  (*c33_b_info)[5].mFileTimeLo = 0U;
  (*c33_b_info)[5].mFileTimeHi = 0U;
  (*c33_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  (*c33_b_info)[6].name = "eps";
  (*c33_b_info)[6].dominantType = "char";
  (*c33_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c33_b_info)[6].fileTimeLo = 1286818686U;
  (*c33_b_info)[6].fileTimeHi = 0U;
  (*c33_b_info)[6].mFileTimeLo = 0U;
  (*c33_b_info)[6].mFileTimeHi = 0U;
  (*c33_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c33_b_info)[7].name = "eml_is_float_class";
  (*c33_b_info)[7].dominantType = "char";
  (*c33_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  (*c33_b_info)[7].fileTimeLo = 1286818782U;
  (*c33_b_info)[7].fileTimeHi = 0U;
  (*c33_b_info)[7].mFileTimeLo = 0U;
  (*c33_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c33_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c33_i24 = 0; c33_i24 < 8; c33_i24++) {
    c33_r0 = &c33_info[c33_i24];
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", c33_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c33_r0->context)), "context", "nameCaptureInfo",
                    c33_i24);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", c33_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c33_r0->name)), "name", "nameCaptureInfo",
                    c33_i24);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo",
      c33_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c33_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c33_i24);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", c33_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c33_r0->resolved)), "resolved",
                    "nameCaptureInfo", c33_i24);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", &c33_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c33_i24);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo", &c33_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c33_i24);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo",
      &c33_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c33_i24);
    sf_mex_addfield(c33_m0, sf_mex_create("nameCaptureInfo",
      &c33_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c33_i24);
  }

  sf_mex_assign(&c33_nameCaptureInfo, c33_m0, FALSE);
  return c33_nameCaptureInfo;
}

static const mxArray *c33_d_sf_marshallOut(void *chartInstanceVoid, void
  *c33_inData)
{
  const mxArray *c33_mxArrayOutData = NULL;
  int32_T c33_u;
  const mxArray *c33_y = NULL;
  SFc33_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc33_controller_templateInstanceStruct *)chartInstanceVoid;
  c33_mxArrayOutData = NULL;
  c33_u = *(int32_T *)c33_inData;
  c33_y = NULL;
  sf_mex_assign(&c33_y, sf_mex_create("y", &c33_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c33_mxArrayOutData, c33_y, FALSE);
  return c33_mxArrayOutData;
}

static int32_T c33_d_emlrt_marshallIn(SFc33_controller_templateInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  int32_T c33_y;
  int32_T c33_i25;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_i25, 1, 6, 0U, 0, 0U, 0);
  c33_y = c33_i25;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void c33_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c33_mxArrayInData, const char_T *c33_varName, void *c33_outData)
{
  const mxArray *c33_sfEvent;
  const char_T *c33_identifier;
  emlrtMsgIdentifier c33_thisId;
  int32_T c33_y;
  SFc33_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc33_controller_templateInstanceStruct *)chartInstanceVoid;
  c33_sfEvent = sf_mex_dup(c33_mxArrayInData);
  c33_identifier = c33_varName;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c33_sfEvent),
    &c33_thisId);
  sf_mex_destroy(&c33_sfEvent);
  *(int32_T *)c33_outData = c33_y;
  sf_mex_destroy(&c33_mxArrayInData);
}

static uint8_T c33_e_emlrt_marshallIn(SFc33_controller_templateInstanceStruct
  *chartInstance, const mxArray *c33_is_active_c33_controller_template, const
  char_T *c33_identifier)
{
  uint8_T c33_y;
  emlrtMsgIdentifier c33_thisId;
  c33_thisId.fIdentifier = c33_identifier;
  c33_thisId.fParent = NULL;
  c33_y = c33_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c33_is_active_c33_controller_template), &c33_thisId);
  sf_mex_destroy(&c33_is_active_c33_controller_template);
  return c33_y;
}

static uint8_T c33_f_emlrt_marshallIn(SFc33_controller_templateInstanceStruct
  *chartInstance, const mxArray *c33_u, const emlrtMsgIdentifier *c33_parentId)
{
  uint8_T c33_y;
  uint8_T c33_u0;
  sf_mex_import(c33_parentId, sf_mex_dup(c33_u), &c33_u0, 1, 3, 0U, 0, 0U, 0);
  c33_y = c33_u0;
  sf_mex_destroy(&c33_u);
  return c33_y;
}

static void init_dsm_address_info(SFc33_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c33_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2072195043U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(530060499U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1049810210U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1171575728U);
}

mxArray *sf_c33_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Sqx5MkK3Lpr1O41Yc85yZB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(4);
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

static const mxArray *sf_get_sim_state_info_c33_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[18],T\"X_ref_yaw\",},{M[8],M[0],T\"is_active_c33_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c33_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc33_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc33_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           33,
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
          init_script_number_translation(_controller_templateMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_controller_templateMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_controller_templateMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,311);
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
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c33_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 31;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c33_sf_marshallOut,(MexInFcnForType)
            c33_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c33_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c33_yaw_meas;
          real_T *c33_idx;
          real_T (*c33_X_ref_yaw_unbounded)[8];
          real_T (*c33_X_ref_yaw)[62];
          c33_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c33_yaw_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c33_X_ref_yaw = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S,
            1);
          c33_X_ref_yaw_unbounded = (real_T (*)[8])ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c33_X_ref_yaw_unbounded);
          _SFD_SET_DATA_VALUE_PTR(1U, *c33_X_ref_yaw);
          _SFD_SET_DATA_VALUE_PTR(2U, c33_yaw_meas);
          _SFD_SET_DATA_VALUE_PTR(3U, c33_idx);
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
      33, "dworkChecksum");
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

static void sf_opaque_initialize_c33_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc33_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc33_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c33_controller_template
    ((SFc33_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c33_controller_template((SFc33_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c33_controller_template(void *chartInstanceVar)
{
  enable_c33_controller_template((SFc33_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c33_controller_template(void *chartInstanceVar)
{
  disable_c33_controller_template((SFc33_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c33_controller_template(void *chartInstanceVar)
{
  sf_c33_controller_template((SFc33_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c33_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c33_controller_template((SFc33_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c33_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c33_controller_template
    ((SFc33_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c33_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c33_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c33_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c33_controller_template((SFc33_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c33_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c33_controller_template(S);
}

static void sf_opaque_set_sim_state_c33_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c33_controller_template(S, st);
}

static void sf_opaque_terminate_c33_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc33_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c33_controller_template((SFc33_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc33_controller_template((SFc33_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c33_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c33_controller_template
      ((SFc33_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c33_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c33_controller_template\",T\"is_active_c33_controller_template\"}}"
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

static void mdlSetWorkWidths_c33_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,33);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,33,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,33,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,33,3);
      sf_mark_chart_reusable_outputs(S,infoStruct,33,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,33);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3687919790U));
  ssSetChecksum1(S,(886288160U));
  ssSetChecksum2(S,(3588937393U));
  ssSetChecksum3(S,(1022689136U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c33_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c33_controller_template(SimStruct *S)
{
  SFc33_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc33_controller_templateInstanceStruct *)malloc(sizeof
    (SFc33_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc33_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c33_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c33_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c33_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c33_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c33_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c33_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c33_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c33_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c33_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c33_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c33_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c33_controller_template;
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

void c33_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c33_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c33_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c33_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c33_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
