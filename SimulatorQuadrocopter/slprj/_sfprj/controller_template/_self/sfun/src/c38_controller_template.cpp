/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c38_controller_template.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c38_debug_family_names[10] = { "pred_horizon_yaw", "yaw0",
  "yaw_diff", "yaw_offset", "nargin", "nargout", "X_ref_yaw_unbounded",
  "yaw_meas", "idx", "X_ref_yaw" };

/* Function Declarations */
static void initialize_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance);
static void enable_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance);
static void disable_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance);
static void c38_update_debugger_state_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance, const mxArray *c38_st);
static void finalize_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance);
static void sf_c38_controller_template(SFc38_controller_templateInstanceStruct
  *chartInstance);
static void initSimStructsc38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c38_machineNumber, uint32_T
  c38_chartNumber);
static const mxArray *c38_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static void c38_emlrt_marshallIn(SFc38_controller_templateInstanceStruct
  *chartInstance, const mxArray *c38_X_ref_yaw, const char_T *c38_identifier,
  real_T c38_y[62]);
static void c38_b_emlrt_marshallIn(SFc38_controller_templateInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[62]);
static void c38_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static const mxArray *c38_b_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static const mxArray *c38_c_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static real_T c38_c_emlrt_marshallIn(SFc38_controller_templateInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId);
static void c38_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static const mxArray *c38_d_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData);
static int32_T c38_d_emlrt_marshallIn(SFc38_controller_templateInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId);
static void c38_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData);
static uint8_T c38_e_emlrt_marshallIn(SFc38_controller_templateInstanceStruct
  *chartInstance, const mxArray *c38_is_active_c38_controller_template, const
  char_T *c38_identifier);
static uint8_T c38_f_emlrt_marshallIn(SFc38_controller_templateInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId);
static void init_dsm_address_info(SFc38_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c38_sfEvent;
  uint8_T *c38_is_active_c38_controller_template;
  c38_is_active_c38_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c38_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c38_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c38_is_active_c38_controller_template = 0U;
}

static void initialize_params_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c38_update_debugger_state_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance)
{
  c38_update_debugger_state_c38_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c38_st;
  const mxArray *c38_y = NULL;
  int32_T c38_i0;
  real_T c38_u[62];
  const mxArray *c38_b_y = NULL;
  uint8_T c38_hoistedGlobal;
  uint8_T c38_b_u;
  const mxArray *c38_c_y = NULL;
  uint8_T *c38_is_active_c38_controller_template;
  real_T (*c38_X_ref_yaw)[62];
  c38_X_ref_yaw = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c38_is_active_c38_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c38_st = NULL;
  c38_st = NULL;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_createcellarray(2), FALSE);
  for (c38_i0 = 0; c38_i0 < 62; c38_i0++) {
    c38_u[c38_i0] = (*c38_X_ref_yaw)[c38_i0];
  }

  c38_b_y = NULL;
  sf_mex_assign(&c38_b_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 2, 2, 31),
                FALSE);
  sf_mex_setcell(c38_y, 0, c38_b_y);
  c38_hoistedGlobal = *c38_is_active_c38_controller_template;
  c38_b_u = c38_hoistedGlobal;
  c38_c_y = NULL;
  sf_mex_assign(&c38_c_y, sf_mex_create("y", &c38_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c38_y, 1, c38_c_y);
  sf_mex_assign(&c38_st, c38_y, FALSE);
  return c38_st;
}

static void set_sim_state_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance, const mxArray *c38_st)
{
  const mxArray *c38_u;
  real_T c38_dv0[62];
  int32_T c38_i1;
  boolean_T *c38_doneDoubleBufferReInit;
  uint8_T *c38_is_active_c38_controller_template;
  real_T (*c38_X_ref_yaw)[62];
  c38_X_ref_yaw = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c38_is_active_c38_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c38_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c38_doneDoubleBufferReInit = TRUE;
  c38_u = sf_mex_dup(c38_st);
  c38_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c38_u, 0)),
                       "X_ref_yaw", c38_dv0);
  for (c38_i1 = 0; c38_i1 < 62; c38_i1++) {
    (*c38_X_ref_yaw)[c38_i1] = c38_dv0[c38_i1];
  }

  *c38_is_active_c38_controller_template = c38_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c38_u, 1)), "is_active_c38_controller_template");
  sf_mex_destroy(&c38_u);
  c38_update_debugger_state_c38_controller_template(chartInstance);
  sf_mex_destroy(&c38_st);
}

static void finalize_c38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c38_controller_template(SFc38_controller_templateInstanceStruct
  *chartInstance)
{
  int32_T c38_i2;
  int32_T c38_i3;
  real_T c38_hoistedGlobal;
  real_T c38_b_hoistedGlobal;
  int32_T c38_i4;
  real_T c38_X_ref_yaw_unbounded[806];
  real_T c38_yaw_meas;
  real_T c38_idx;
  uint32_T c38_debug_family_var_map[10];
  real_T c38_pred_horizon_yaw;
  real_T c38_yaw0;
  real_T c38_yaw_diff;
  real_T c38_yaw_offset;
  real_T c38_nargin = 3.0;
  real_T c38_nargout = 1.0;
  real_T c38_X_ref_yaw[62];
  real_T c38_A;
  real_T c38_x;
  real_T c38_b_x;
  real_T c38_y;
  real_T c38_c_x;
  real_T c38_d_x;
  real_T c38_e_x;
  real_T c38_a;
  real_T c38_b_y;
  real_T c38_b_a;
  int32_T c38_i5;
  int32_T c38_i6;
  int32_T c38_i7;
  real_T *c38_b_idx;
  real_T *c38_b_yaw_meas;
  int32_T *c38_sfEvent;
  real_T (*c38_b_X_ref_yaw)[62];
  real_T (*c38_b_X_ref_yaw_unbounded)[806];
  c38_b_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c38_b_yaw_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c38_b_X_ref_yaw = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c38_b_X_ref_yaw_unbounded = (real_T (*)[806])ssGetInputPortSignal
    (chartInstance->S, 0);
  c38_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 37U, *c38_sfEvent);
  for (c38_i2 = 0; c38_i2 < 806; c38_i2++) {
    _SFD_DATA_RANGE_CHECK((*c38_b_X_ref_yaw_unbounded)[c38_i2], 0U);
  }

  for (c38_i3 = 0; c38_i3 < 62; c38_i3++) {
    _SFD_DATA_RANGE_CHECK((*c38_b_X_ref_yaw)[c38_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c38_b_yaw_meas, 2U);
  _SFD_DATA_RANGE_CHECK(*c38_b_idx, 3U);
  *c38_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 37U, *c38_sfEvent);
  c38_hoistedGlobal = *c38_b_yaw_meas;
  c38_b_hoistedGlobal = *c38_b_idx;
  for (c38_i4 = 0; c38_i4 < 806; c38_i4++) {
    c38_X_ref_yaw_unbounded[c38_i4] = (*c38_b_X_ref_yaw_unbounded)[c38_i4];
  }

  c38_yaw_meas = c38_hoistedGlobal;
  c38_idx = c38_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c38_debug_family_names,
    c38_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c38_pred_horizon_yaw, 0U, c38_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c38_yaw0, 1U, c38_b_sf_marshallOut,
    c38_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_yaw_diff, 2U,
    c38_b_sf_marshallOut, c38_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_yaw_offset, 3U,
    c38_b_sf_marshallOut, c38_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_nargin, 4U, c38_b_sf_marshallOut,
    c38_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c38_nargout, 5U,
    c38_b_sf_marshallOut, c38_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c38_X_ref_yaw_unbounded, 6U,
    c38_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c38_yaw_meas, 7U, c38_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c38_idx, 8U, c38_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c38_X_ref_yaw, 9U, c38_sf_marshallOut,
    c38_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c38_sfEvent, 3);
  c38_pred_horizon_yaw = 30.0;
  _SFD_EML_CALL(0U, *c38_sfEvent, 5);
  c38_yaw0 = c38_X_ref_yaw_unbounded[(_SFD_EML_ARRAY_BOUNDS_CHECK(
    "X_ref_yaw_unbounded", (int32_T)_SFD_INTEGER_CHECK("idx", c38_idx), 1, 403,
    2, 0) - 1) << 1];
  _SFD_EML_CALL(0U, *c38_sfEvent, 6);
  c38_yaw_diff = c38_yaw_meas - c38_yaw0;
  _SFD_EML_CALL(0U, *c38_sfEvent, 9);
  c38_A = c38_yaw_diff;
  c38_x = c38_A;
  c38_b_x = c38_x;
  c38_y = c38_b_x / 6.2831853071795862;
  c38_c_x = c38_y;
  c38_d_x = c38_c_x;
  c38_e_x = c38_d_x;
  if (muDoubleScalarAbs(c38_e_x) > 4.503599627370496E+15) {
  } else if (c38_e_x >= 0.5) {
    c38_d_x = muDoubleScalarFloor(c38_e_x + 0.5);
  } else if (c38_e_x > -0.5) {
    c38_d_x = c38_e_x * 0.0;
  } else {
    c38_d_x = muDoubleScalarCeil(c38_e_x - 0.5);
  }

  c38_a = c38_d_x;
  c38_b_y = c38_a * 2.0;
  c38_b_a = c38_b_y;
  c38_yaw_offset = c38_b_a * 3.1415926535897931;
  _SFD_EML_CALL(0U, *c38_sfEvent, 11);
  for (c38_i5 = 0; c38_i5 < 31; c38_i5++) {
    c38_X_ref_yaw[c38_i5 << 1] = c38_X_ref_yaw_unbounded
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("X_ref_yaw_unbounded", (int32_T)
         _SFD_INTEGER_CHECK("idx:idx+pred_horizon_yaw", c38_idx + (real_T)c38_i5),
         1, 403, 2, 0) - 1) << 1] + c38_yaw_offset;
  }

  for (c38_i6 = 0; c38_i6 < 31; c38_i6++) {
    c38_X_ref_yaw[1 + (c38_i6 << 1)] = c38_X_ref_yaw_unbounded[1 +
      ((_SFD_EML_ARRAY_BOUNDS_CHECK("X_ref_yaw_unbounded", (int32_T)
         _SFD_INTEGER_CHECK("idx:idx+pred_horizon_yaw", c38_idx + (real_T)c38_i6),
         1, 403, 2, 0) - 1) << 1)];
  }

  _SFD_EML_CALL(0U, *c38_sfEvent, -11);
  sf_debug_symbol_scope_pop();
  for (c38_i7 = 0; c38_i7 < 62; c38_i7++) {
    (*c38_b_X_ref_yaw)[c38_i7] = c38_X_ref_yaw[c38_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 37U, *c38_sfEvent);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc38_controller_template
  (SFc38_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c38_machineNumber, uint32_T
  c38_chartNumber)
{
}

static const mxArray *c38_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_i8;
  int32_T c38_i9;
  int32_T c38_i10;
  real_T c38_b_inData[62];
  int32_T c38_i11;
  int32_T c38_i12;
  int32_T c38_i13;
  real_T c38_u[62];
  const mxArray *c38_y = NULL;
  SFc38_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc38_controller_templateInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_i8 = 0;
  for (c38_i9 = 0; c38_i9 < 31; c38_i9++) {
    for (c38_i10 = 0; c38_i10 < 2; c38_i10++) {
      c38_b_inData[c38_i10 + c38_i8] = (*(real_T (*)[62])c38_inData)[c38_i10 +
        c38_i8];
    }

    c38_i8 += 2;
  }

  c38_i11 = 0;
  for (c38_i12 = 0; c38_i12 < 31; c38_i12++) {
    for (c38_i13 = 0; c38_i13 < 2; c38_i13++) {
      c38_u[c38_i13 + c38_i11] = c38_b_inData[c38_i13 + c38_i11];
    }

    c38_i11 += 2;
  }

  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 2, 2, 31),
                FALSE);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, FALSE);
  return c38_mxArrayOutData;
}

static void c38_emlrt_marshallIn(SFc38_controller_templateInstanceStruct
  *chartInstance, const mxArray *c38_X_ref_yaw, const char_T *c38_identifier,
  real_T c38_y[62])
{
  emlrtMsgIdentifier c38_thisId;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_X_ref_yaw), &c38_thisId,
    c38_y);
  sf_mex_destroy(&c38_X_ref_yaw);
}

static void c38_b_emlrt_marshallIn(SFc38_controller_templateInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId,
  real_T c38_y[62])
{
  real_T c38_dv1[62];
  int32_T c38_i14;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), c38_dv1, 1, 0, 0U, 1, 0U, 2, 2,
                31);
  for (c38_i14 = 0; c38_i14 < 62; c38_i14++) {
    c38_y[c38_i14] = c38_dv1[c38_i14];
  }

  sf_mex_destroy(&c38_u);
}

static void c38_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_X_ref_yaw;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y[62];
  int32_T c38_i15;
  int32_T c38_i16;
  int32_T c38_i17;
  SFc38_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc38_controller_templateInstanceStruct *)chartInstanceVoid;
  c38_X_ref_yaw = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_X_ref_yaw), &c38_thisId,
    c38_y);
  sf_mex_destroy(&c38_X_ref_yaw);
  c38_i15 = 0;
  for (c38_i16 = 0; c38_i16 < 31; c38_i16++) {
    for (c38_i17 = 0; c38_i17 < 2; c38_i17++) {
      (*(real_T (*)[62])c38_outData)[c38_i17 + c38_i15] = c38_y[c38_i17 +
        c38_i15];
    }

    c38_i15 += 2;
  }

  sf_mex_destroy(&c38_mxArrayInData);
}

static const mxArray *c38_b_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  real_T c38_u;
  const mxArray *c38_y = NULL;
  SFc38_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc38_controller_templateInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_u = *(real_T *)c38_inData;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", &c38_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, FALSE);
  return c38_mxArrayOutData;
}

static const mxArray *c38_c_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_i18;
  int32_T c38_i19;
  int32_T c38_i20;
  real_T c38_b_inData[806];
  int32_T c38_i21;
  int32_T c38_i22;
  int32_T c38_i23;
  real_T c38_u[806];
  const mxArray *c38_y = NULL;
  SFc38_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc38_controller_templateInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_i18 = 0;
  for (c38_i19 = 0; c38_i19 < 403; c38_i19++) {
    for (c38_i20 = 0; c38_i20 < 2; c38_i20++) {
      c38_b_inData[c38_i20 + c38_i18] = (*(real_T (*)[806])c38_inData)[c38_i20 +
        c38_i18];
    }

    c38_i18 += 2;
  }

  c38_i21 = 0;
  for (c38_i22 = 0; c38_i22 < 403; c38_i22++) {
    for (c38_i23 = 0; c38_i23 < 2; c38_i23++) {
      c38_u[c38_i23 + c38_i21] = c38_b_inData[c38_i23 + c38_i21];
    }

    c38_i21 += 2;
  }

  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", c38_u, 0, 0U, 1U, 0U, 2, 2, 403),
                FALSE);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, FALSE);
  return c38_mxArrayOutData;
}

static real_T c38_c_emlrt_marshallIn(SFc38_controller_templateInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId)
{
  real_T c38_y;
  real_T c38_d0;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), &c38_d0, 1, 0, 0U, 0, 0U, 0);
  c38_y = c38_d0;
  sf_mex_destroy(&c38_u);
  return c38_y;
}

static void c38_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_nargout;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  real_T c38_y;
  SFc38_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc38_controller_templateInstanceStruct *)chartInstanceVoid;
  c38_nargout = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_nargout),
    &c38_thisId);
  sf_mex_destroy(&c38_nargout);
  *(real_T *)c38_outData = c38_y;
  sf_mex_destroy(&c38_mxArrayInData);
}

const mxArray *sf_c38_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c38_nameCaptureInfo;
  c38_ResolvedFunctionInfo c38_info[8];
  c38_ResolvedFunctionInfo (*c38_b_info)[8];
  const mxArray *c38_m0 = NULL;
  int32_T c38_i24;
  c38_ResolvedFunctionInfo *c38_r0;
  c38_nameCaptureInfo = NULL;
  c38_nameCaptureInfo = NULL;
  c38_b_info = (c38_ResolvedFunctionInfo (*)[8])c38_info;
  (*c38_b_info)[0].context = "";
  (*c38_b_info)[0].name = "mtimes";
  (*c38_b_info)[0].dominantType = "double";
  (*c38_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c38_b_info)[0].fileTimeLo = 1289519692U;
  (*c38_b_info)[0].fileTimeHi = 0U;
  (*c38_b_info)[0].mFileTimeLo = 0U;
  (*c38_b_info)[0].mFileTimeHi = 0U;
  (*c38_b_info)[1].context = "";
  (*c38_b_info)[1].name = "mrdivide";
  (*c38_b_info)[1].dominantType = "double";
  (*c38_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c38_b_info)[1].fileTimeLo = 1310137456U;
  (*c38_b_info)[1].fileTimeHi = 0U;
  (*c38_b_info)[1].mFileTimeLo = 1289519692U;
  (*c38_b_info)[1].mFileTimeHi = 0U;
  (*c38_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c38_b_info)[2].name = "rdivide";
  (*c38_b_info)[2].dominantType = "double";
  (*c38_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c38_b_info)[2].fileTimeLo = 1286818844U;
  (*c38_b_info)[2].fileTimeHi = 0U;
  (*c38_b_info)[2].mFileTimeLo = 0U;
  (*c38_b_info)[2].mFileTimeHi = 0U;
  (*c38_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c38_b_info)[3].name = "eml_div";
  (*c38_b_info)[3].dominantType = "double";
  (*c38_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c38_b_info)[3].fileTimeLo = 1305318000U;
  (*c38_b_info)[3].fileTimeHi = 0U;
  (*c38_b_info)[3].mFileTimeLo = 0U;
  (*c38_b_info)[3].mFileTimeHi = 0U;
  (*c38_b_info)[4].context = "";
  (*c38_b_info)[4].name = "round";
  (*c38_b_info)[4].dominantType = "double";
  (*c38_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c38_b_info)[4].fileTimeLo = 1286818748U;
  (*c38_b_info)[4].fileTimeHi = 0U;
  (*c38_b_info)[4].mFileTimeLo = 0U;
  (*c38_b_info)[4].mFileTimeHi = 0U;
  (*c38_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m";
  (*c38_b_info)[5].name = "eml_scalar_round";
  (*c38_b_info)[5].dominantType = "double";
  (*c38_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  (*c38_b_info)[5].fileTimeLo = 1289519628U;
  (*c38_b_info)[5].fileTimeHi = 0U;
  (*c38_b_info)[5].mFileTimeLo = 0U;
  (*c38_b_info)[5].mFileTimeHi = 0U;
  (*c38_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m!scalar_round";
  (*c38_b_info)[6].name = "eps";
  (*c38_b_info)[6].dominantType = "char";
  (*c38_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c38_b_info)[6].fileTimeLo = 1286818686U;
  (*c38_b_info)[6].fileTimeHi = 0U;
  (*c38_b_info)[6].mFileTimeLo = 0U;
  (*c38_b_info)[6].mFileTimeHi = 0U;
  (*c38_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  (*c38_b_info)[7].name = "eml_is_float_class";
  (*c38_b_info)[7].dominantType = "char";
  (*c38_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  (*c38_b_info)[7].fileTimeLo = 1286818782U;
  (*c38_b_info)[7].fileTimeHi = 0U;
  (*c38_b_info)[7].mFileTimeLo = 0U;
  (*c38_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c38_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c38_i24 = 0; c38_i24 < 8; c38_i24++) {
    c38_r0 = &c38_info[c38_i24];
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo", c38_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c38_r0->context)), "context", "nameCaptureInfo",
                    c38_i24);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo", c38_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c38_r0->name)), "name", "nameCaptureInfo",
                    c38_i24);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo",
      c38_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c38_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c38_i24);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo", c38_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c38_r0->resolved)), "resolved",
                    "nameCaptureInfo", c38_i24);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo", &c38_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c38_i24);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo", &c38_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c38_i24);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo",
      &c38_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c38_i24);
    sf_mex_addfield(c38_m0, sf_mex_create("nameCaptureInfo",
      &c38_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c38_i24);
  }

  sf_mex_assign(&c38_nameCaptureInfo, c38_m0, FALSE);
  return c38_nameCaptureInfo;
}

static const mxArray *c38_d_sf_marshallOut(void *chartInstanceVoid, void
  *c38_inData)
{
  const mxArray *c38_mxArrayOutData = NULL;
  int32_T c38_u;
  const mxArray *c38_y = NULL;
  SFc38_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc38_controller_templateInstanceStruct *)chartInstanceVoid;
  c38_mxArrayOutData = NULL;
  c38_u = *(int32_T *)c38_inData;
  c38_y = NULL;
  sf_mex_assign(&c38_y, sf_mex_create("y", &c38_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c38_mxArrayOutData, c38_y, FALSE);
  return c38_mxArrayOutData;
}

static int32_T c38_d_emlrt_marshallIn(SFc38_controller_templateInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId)
{
  int32_T c38_y;
  int32_T c38_i25;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), &c38_i25, 1, 6, 0U, 0, 0U, 0);
  c38_y = c38_i25;
  sf_mex_destroy(&c38_u);
  return c38_y;
}

static void c38_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c38_mxArrayInData, const char_T *c38_varName, void *c38_outData)
{
  const mxArray *c38_sfEvent;
  const char_T *c38_identifier;
  emlrtMsgIdentifier c38_thisId;
  int32_T c38_y;
  SFc38_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc38_controller_templateInstanceStruct *)chartInstanceVoid;
  c38_sfEvent = sf_mex_dup(c38_mxArrayInData);
  c38_identifier = c38_varName;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c38_sfEvent),
    &c38_thisId);
  sf_mex_destroy(&c38_sfEvent);
  *(int32_T *)c38_outData = c38_y;
  sf_mex_destroy(&c38_mxArrayInData);
}

static uint8_T c38_e_emlrt_marshallIn(SFc38_controller_templateInstanceStruct
  *chartInstance, const mxArray *c38_is_active_c38_controller_template, const
  char_T *c38_identifier)
{
  uint8_T c38_y;
  emlrtMsgIdentifier c38_thisId;
  c38_thisId.fIdentifier = c38_identifier;
  c38_thisId.fParent = NULL;
  c38_y = c38_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c38_is_active_c38_controller_template), &c38_thisId);
  sf_mex_destroy(&c38_is_active_c38_controller_template);
  return c38_y;
}

static uint8_T c38_f_emlrt_marshallIn(SFc38_controller_templateInstanceStruct
  *chartInstance, const mxArray *c38_u, const emlrtMsgIdentifier *c38_parentId)
{
  uint8_T c38_y;
  uint8_T c38_u0;
  sf_mex_import(c38_parentId, sf_mex_dup(c38_u), &c38_u0, 1, 3, 0U, 0, 0U, 0);
  c38_y = c38_u0;
  sf_mex_destroy(&c38_u);
  return c38_y;
}

static void init_dsm_address_info(SFc38_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c38_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(846684404U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2900445370U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3897224422U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(189109119U);
}

mxArray *sf_c38_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("f4K9DnLprq53FB4aKD3IME");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(403);
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

static const mxArray *sf_get_sim_state_info_c38_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[18],T\"X_ref_yaw\",},{M[8],M[0],T\"is_active_c38_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c38_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc38_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc38_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           38,
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
          dimVector[1]= 403;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c38_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 31;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c38_sf_marshallOut,(MexInFcnForType)
            c38_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c38_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c38_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c38_yaw_meas;
          real_T *c38_idx;
          real_T (*c38_X_ref_yaw_unbounded)[806];
          real_T (*c38_X_ref_yaw)[62];
          c38_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c38_yaw_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c38_X_ref_yaw = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S,
            1);
          c38_X_ref_yaw_unbounded = (real_T (*)[806])ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c38_X_ref_yaw_unbounded);
          _SFD_SET_DATA_VALUE_PTR(1U, *c38_X_ref_yaw);
          _SFD_SET_DATA_VALUE_PTR(2U, c38_yaw_meas);
          _SFD_SET_DATA_VALUE_PTR(3U, c38_idx);
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
      38, "dworkChecksum");
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

static void sf_opaque_initialize_c38_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc38_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc38_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c38_controller_template
    ((SFc38_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c38_controller_template((SFc38_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c38_controller_template(void *chartInstanceVar)
{
  enable_c38_controller_template((SFc38_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c38_controller_template(void *chartInstanceVar)
{
  disable_c38_controller_template((SFc38_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c38_controller_template(void *chartInstanceVar)
{
  sf_c38_controller_template((SFc38_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c38_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c38_controller_template((SFc38_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c38_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c38_controller_template
    ((SFc38_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c38_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c38_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c38_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c38_controller_template((SFc38_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c38_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c38_controller_template(S);
}

static void sf_opaque_set_sim_state_c38_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c38_controller_template(S, st);
}

static void sf_opaque_terminate_c38_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc38_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c38_controller_template((SFc38_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc38_controller_template((SFc38_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c38_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c38_controller_template
      ((SFc38_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c38_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c38_controller_template\",T\"is_active_c38_controller_template\"}}"
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

static void mdlSetWorkWidths_c38_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,38);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,38,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,38,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,38,3);
      sf_mark_chart_reusable_outputs(S,infoStruct,38,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,38);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(978784636U));
  ssSetChecksum1(S,(2050170765U));
  ssSetChecksum2(S,(1474354112U));
  ssSetChecksum3(S,(3149686632U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c38_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c38_controller_template(SimStruct *S)
{
  SFc38_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc38_controller_templateInstanceStruct *)malloc(sizeof
    (SFc38_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc38_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c38_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c38_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c38_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c38_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c38_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c38_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c38_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c38_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c38_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c38_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c38_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c38_controller_template;
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

void c38_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c38_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c38_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c38_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c38_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
