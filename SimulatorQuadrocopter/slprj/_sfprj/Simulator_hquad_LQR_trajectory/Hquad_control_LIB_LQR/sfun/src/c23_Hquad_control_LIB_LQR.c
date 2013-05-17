/* Include files */

#include "blascompat32.h"
#include "Hquad_control_LIB_LQR_sfun.h"
#include "c23_Hquad_control_LIB_LQR.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hquad_control_LIB_LQR_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c23_debug_family_names[10] = { "yaw0", "yaw_diff",
  "yaw_offset", "nargin", "nargout", "X_ref_yaw_unbounded", "yaw_meas", "idx",
  "yaw_ref", "yaw_dot_ref" };

/* Function Declarations */
static void initialize_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void initialize_params_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void enable_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void disable_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void c23_update_debugger_state_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void set_sim_state_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance, const mxArray
   *c23_st);
static void finalize_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void sf_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void initSimStructsc23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_emlrt_marshallIn(SFc23_Hquad_control_LIB_LQRInstanceStruct
  *chartInstance, const mxArray *c23_yaw_dot_ref, const char_T *c23_identifier);
static real_T c23_b_emlrt_marshallIn(SFc23_Hquad_control_LIB_LQRInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_c_emlrt_marshallIn(SFc23_Hquad_control_LIB_LQRInstanceStruct *
  chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static uint8_T c23_d_emlrt_marshallIn(SFc23_Hquad_control_LIB_LQRInstanceStruct *
  chartInstance, const mxArray *c23_b_is_active_c23_Hquad_control_LIB_LQR, const
  char_T *c23_identifier);
static uint8_T c23_e_emlrt_marshallIn(SFc23_Hquad_control_LIB_LQRInstanceStruct *
  chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void init_dsm_address_info(SFc23_Hquad_control_LIB_LQRInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
  chartInstance->c23_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c23_is_active_c23_Hquad_control_LIB_LQR = 0U;
}

static void initialize_params_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
}

static void enable_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c23_update_debugger_state_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  real_T c23_hoistedGlobal;
  real_T c23_u;
  const mxArray *c23_b_y = NULL;
  real_T c23_b_hoistedGlobal;
  real_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  uint8_T c23_c_hoistedGlobal;
  uint8_T c23_c_u;
  const mxArray *c23_d_y = NULL;
  real_T *c23_yaw_dot_ref;
  real_T *c23_yaw_ref;
  c23_yaw_dot_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c23_yaw_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellarray(3), FALSE);
  c23_hoistedGlobal = *c23_yaw_dot_ref;
  c23_u = c23_hoistedGlobal;
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_b_hoistedGlobal = *c23_yaw_ref;
  c23_b_u = c23_b_hoistedGlobal;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c23_y, 1, c23_c_y);
  c23_c_hoistedGlobal = chartInstance->c23_is_active_c23_Hquad_control_LIB_LQR;
  c23_c_u = c23_c_hoistedGlobal;
  c23_d_y = NULL;
  sf_mex_assign(&c23_d_y, sf_mex_create("y", &c23_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c23_y, 2, c23_d_y);
  sf_mex_assign(&c23_st, c23_y, FALSE);
  return c23_st;
}

static void set_sim_state_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance, const mxArray
   *c23_st)
{
  const mxArray *c23_u;
  real_T *c23_yaw_dot_ref;
  real_T *c23_yaw_ref;
  c23_yaw_dot_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c23_yaw_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c23_doneDoubleBufferReInit = TRUE;
  c23_u = sf_mex_dup(c23_st);
  *c23_yaw_dot_ref = c23_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c23_u, 0)), "yaw_dot_ref");
  *c23_yaw_ref = c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c23_u, 1)), "yaw_ref");
  chartInstance->c23_is_active_c23_Hquad_control_LIB_LQR =
    c23_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 2)),
    "is_active_c23_Hquad_control_LIB_LQR");
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_Hquad_control_LIB_LQR(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
}

static void sf_c23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
  int32_T c23_i0;
  real_T c23_hoistedGlobal;
  real_T c23_b_hoistedGlobal;
  int32_T c23_i1;
  real_T c23_X_ref_yaw_unbounded[1864];
  real_T c23_yaw_meas;
  real_T c23_idx;
  uint32_T c23_debug_family_var_map[10];
  real_T c23_yaw0;
  real_T c23_yaw_diff;
  real_T c23_yaw_offset;
  real_T c23_nargin = 3.0;
  real_T c23_nargout = 2.0;
  real_T c23_yaw_ref;
  real_T c23_yaw_dot_ref;
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
  real_T *c23_b_yaw_dot_ref;
  real_T *c23_b_yaw_ref;
  real_T *c23_b_idx;
  real_T *c23_b_yaw_meas;
  real_T (*c23_b_X_ref_yaw_unbounded)[1864];
  c23_b_yaw_dot_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c23_b_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c23_b_yaw_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c23_b_yaw_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_b_X_ref_yaw_unbounded = (real_T (*)[1864])ssGetInputPortSignal
    (chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c23_sfEvent);
  for (c23_i0 = 0; c23_i0 < 1864; c23_i0++) {
    _SFD_DATA_RANGE_CHECK((*c23_b_X_ref_yaw_unbounded)[c23_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c23_b_yaw_ref, 1U);
  _SFD_DATA_RANGE_CHECK(*c23_b_yaw_meas, 2U);
  _SFD_DATA_RANGE_CHECK(*c23_b_idx, 3U);
  _SFD_DATA_RANGE_CHECK(*c23_b_yaw_dot_ref, 4U);
  chartInstance->c23_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c23_sfEvent);
  c23_hoistedGlobal = *c23_b_yaw_meas;
  c23_b_hoistedGlobal = *c23_b_idx;
  for (c23_i1 = 0; c23_i1 < 1864; c23_i1++) {
    c23_X_ref_yaw_unbounded[c23_i1] = (*c23_b_X_ref_yaw_unbounded)[c23_i1];
  }

  c23_yaw_meas = c23_hoistedGlobal;
  c23_idx = c23_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 10U, 10U, c23_debug_family_names,
    c23_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c23_yaw0, 0U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_yaw_diff, 1U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_yaw_offset, 2U,
    c23_sf_marshallOut, c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_nargin, 3U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_nargout, 4U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c23_X_ref_yaw_unbounded, 5U,
    c23_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c23_yaw_meas, 6U, c23_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c23_idx, 7U, c23_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c23_yaw_ref, 8U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_yaw_dot_ref, 9U,
    c23_sf_marshallOut, c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 4);
  c23_yaw0 = c23_X_ref_yaw_unbounded[(_SFD_EML_ARRAY_BOUNDS_CHECK(
    "X_ref_yaw_unbounded", (int32_T)_SFD_INTEGER_CHECK("idx", c23_idx), 1, 932,
    2, 0) - 1) << 1];
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 5);
  c23_yaw_diff = c23_yaw_meas - c23_yaw0;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 8);
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
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 11);
  c23_yaw_ref = c23_X_ref_yaw_unbounded[(_SFD_EML_ARRAY_BOUNDS_CHECK(
    "X_ref_yaw_unbounded", (int32_T)_SFD_INTEGER_CHECK("idx", c23_idx), 1, 932,
    2, 0) - 1) << 1] + c23_yaw_offset;
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, 12);
  c23_yaw_dot_ref = c23_X_ref_yaw_unbounded[1 + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
    "X_ref_yaw_unbounded", (int32_T)_SFD_INTEGER_CHECK("idx", c23_idx), 1, 932,
    2, 0) - 1) << 1)];
  _SFD_EML_CALL(0U, chartInstance->c23_sfEvent, -12);
  sf_debug_symbol_scope_pop();
  *c23_b_yaw_ref = c23_yaw_ref;
  *c23_b_yaw_dot_ref = c23_yaw_dot_ref;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c23_sfEvent);
  sf_debug_check_for_state_inconsistency(_Hquad_control_LIB_LQRMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc23_Hquad_control_LIB_LQR
  (SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
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
  real_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_LQRInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static real_T c23_emlrt_marshallIn(SFc23_Hquad_control_LIB_LQRInstanceStruct
  *chartInstance, const mxArray *c23_yaw_dot_ref, const char_T *c23_identifier)
{
  real_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_yaw_dot_ref),
    &c23_thisId);
  sf_mex_destroy(&c23_yaw_dot_ref);
  return c23_y;
}

static real_T c23_b_emlrt_marshallIn(SFc23_Hquad_control_LIB_LQRInstanceStruct
  *chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  real_T c23_y;
  real_T c23_d0;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_d0, 1, 0, 0U, 0, 0U, 0);
  c23_y = c23_d0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_yaw_dot_ref;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_y;
  SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_LQRInstanceStruct *)chartInstanceVoid;
  c23_yaw_dot_ref = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_yaw_dot_ref),
    &c23_thisId);
  sf_mex_destroy(&c23_yaw_dot_ref);
  *(real_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_i2;
  int32_T c23_i3;
  int32_T c23_i4;
  real_T c23_b_inData[1864];
  int32_T c23_i5;
  int32_T c23_i6;
  int32_T c23_i7;
  real_T c23_u[1864];
  const mxArray *c23_y = NULL;
  SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_LQRInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_i2 = 0;
  for (c23_i3 = 0; c23_i3 < 932; c23_i3++) {
    for (c23_i4 = 0; c23_i4 < 2; c23_i4++) {
      c23_b_inData[c23_i4 + c23_i2] = (*(real_T (*)[1864])c23_inData)[c23_i4 +
        c23_i2];
    }

    c23_i2 += 2;
  }

  c23_i5 = 0;
  for (c23_i6 = 0; c23_i6 < 932; c23_i6++) {
    for (c23_i7 = 0; c23_i7 < 2; c23_i7++) {
      c23_u[c23_i7 + c23_i5] = c23_b_inData[c23_i7 + c23_i5];
    }

    c23_i5 += 2;
  }

  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", c23_u, 0, 0U, 1U, 0U, 2, 2, 932),
                FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

const mxArray *sf_c23_Hquad_control_LIB_LQR_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo;
  c23_ResolvedFunctionInfo c23_info[8];
  c23_ResolvedFunctionInfo (*c23_b_info)[8];
  const mxArray *c23_m0 = NULL;
  int32_T c23_i8;
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
  for (c23_i8 = 0; c23_i8 < 8; c23_i8++) {
    c23_r0 = &c23_info[c23_i8];
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->context)), "context", "nameCaptureInfo",
                    c23_i8);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c23_r0->name)), "name", "nameCaptureInfo", c23_i8);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      c23_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c23_i8);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", c23_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c23_r0->resolved)), "resolved",
                    "nameCaptureInfo", c23_i8);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c23_i8);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo", &c23_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c23_i8);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      &c23_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c23_i8);
    sf_mex_addfield(c23_m0, sf_mex_create("nameCaptureInfo",
      &c23_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c23_i8);
  }

  sf_mex_assign(&c23_nameCaptureInfo, c23_m0, FALSE);
  return c23_nameCaptureInfo;
}

static const mxArray *c23_c_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_LQRInstanceStruct *)chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static int32_T c23_c_emlrt_marshallIn(SFc23_Hquad_control_LIB_LQRInstanceStruct *
  chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i9;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i9, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i9;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_b_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_LQRInstanceStruct *)chartInstanceVoid;
  c23_b_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_b_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_b_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static uint8_T c23_d_emlrt_marshallIn(SFc23_Hquad_control_LIB_LQRInstanceStruct *
  chartInstance, const mxArray *c23_b_is_active_c23_Hquad_control_LIB_LQR, const
  char_T *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_b_is_active_c23_Hquad_control_LIB_LQR), &c23_thisId);
  sf_mex_destroy(&c23_b_is_active_c23_Hquad_control_LIB_LQR);
  return c23_y;
}

static uint8_T c23_e_emlrt_marshallIn(SFc23_Hquad_control_LIB_LQRInstanceStruct *
  chartInstance, const mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void init_dsm_address_info(SFc23_Hquad_control_LIB_LQRInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c23_Hquad_control_LIB_LQR_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1684429445U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(846701398U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1640909305U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3178626259U);
}

mxArray *sf_c23_Hquad_control_LIB_LQR_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("DbIzIE8fJOe5fgoGGbEQjC");
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

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c23_Hquad_control_LIB_LQR(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[27],T\"yaw_dot_ref\",},{M[1],M[18],T\"yaw_ref\",},{M[8],M[0],T\"is_active_c23_Hquad_control_LIB_LQR\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_Hquad_control_LIB_LQR_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
    chartInstance = (SFc23_Hquad_control_LIB_LQRInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Hquad_control_LIB_LQRMachineNumber_,
           23,
           1,
           1,
           5,
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
          init_script_number_translation(_Hquad_control_LIB_LQRMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Hquad_control_LIB_LQRMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_Hquad_control_LIB_LQRMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"X_ref_yaw_unbounded");
          _SFD_SET_DATA_PROPS(1,2,0,1,"yaw_ref");
          _SFD_SET_DATA_PROPS(2,1,1,0,"yaw_meas");
          _SFD_SET_DATA_PROPS(3,1,1,0,"idx");
          _SFD_SET_DATA_PROPS(4,2,0,1,"yaw_dot_ref");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,261);
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
            1.0,0,0,(MexFcnForType)c23_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)c23_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)c23_sf_marshallIn);

        {
          real_T *c23_yaw_ref;
          real_T *c23_yaw_meas;
          real_T *c23_idx;
          real_T *c23_yaw_dot_ref;
          real_T (*c23_X_ref_yaw_unbounded)[1864];
          c23_yaw_dot_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c23_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c23_yaw_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c23_yaw_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c23_X_ref_yaw_unbounded = (real_T (*)[1864])ssGetInputPortSignal
            (chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c23_X_ref_yaw_unbounded);
          _SFD_SET_DATA_VALUE_PTR(1U, c23_yaw_ref);
          _SFD_SET_DATA_VALUE_PTR(2U, c23_yaw_meas);
          _SFD_SET_DATA_VALUE_PTR(3U, c23_idx);
          _SFD_SET_DATA_VALUE_PTR(4U, c23_yaw_dot_ref);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Hquad_control_LIB_LQRMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c23_Hquad_control_LIB_LQR(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc23_Hquad_control_LIB_LQRInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c23_Hquad_control_LIB_LQR
    ((SFc23_Hquad_control_LIB_LQRInstanceStruct*) chartInstanceVar);
  initialize_c23_Hquad_control_LIB_LQR
    ((SFc23_Hquad_control_LIB_LQRInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c23_Hquad_control_LIB_LQR(void *chartInstanceVar)
{
  enable_c23_Hquad_control_LIB_LQR((SFc23_Hquad_control_LIB_LQRInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c23_Hquad_control_LIB_LQR(void *chartInstanceVar)
{
  disable_c23_Hquad_control_LIB_LQR((SFc23_Hquad_control_LIB_LQRInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c23_Hquad_control_LIB_LQR(void *chartInstanceVar)
{
  sf_c23_Hquad_control_LIB_LQR((SFc23_Hquad_control_LIB_LQRInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c23_Hquad_control_LIB_LQR
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c23_Hquad_control_LIB_LQR
    ((SFc23_Hquad_control_LIB_LQRInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_Hquad_control_LIB_LQR();/* state var info */
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

extern void sf_internal_set_sim_state_c23_Hquad_control_LIB_LQR(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_Hquad_control_LIB_LQR();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c23_Hquad_control_LIB_LQR
    ((SFc23_Hquad_control_LIB_LQRInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c23_Hquad_control_LIB_LQR
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c23_Hquad_control_LIB_LQR(S);
}

static void sf_opaque_set_sim_state_c23_Hquad_control_LIB_LQR(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c23_Hquad_control_LIB_LQR(S, st);
}

static void sf_opaque_terminate_c23_Hquad_control_LIB_LQR(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_Hquad_control_LIB_LQRInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c23_Hquad_control_LIB_LQR
      ((SFc23_Hquad_control_LIB_LQRInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Hquad_control_LIB_LQR_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc23_Hquad_control_LIB_LQR
    ((SFc23_Hquad_control_LIB_LQRInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_Hquad_control_LIB_LQR(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c23_Hquad_control_LIB_LQR
      ((SFc23_Hquad_control_LIB_LQRInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c23_Hquad_control_LIB_LQR(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_LQR_optimization_info();
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
      sf_mark_chart_reusable_outputs(S,infoStruct,23,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(89056972U));
  ssSetChecksum1(S,(3438997568U));
  ssSetChecksum2(S,(4276534020U));
  ssSetChecksum3(S,(3890569469U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c23_Hquad_control_LIB_LQR(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_Hquad_control_LIB_LQR(SimStruct *S)
{
  SFc23_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
  chartInstance = (SFc23_Hquad_control_LIB_LQRInstanceStruct *)malloc(sizeof
    (SFc23_Hquad_control_LIB_LQRInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc23_Hquad_control_LIB_LQRInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c23_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c23_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c23_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_Hquad_control_LIB_LQR;
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

void c23_Hquad_control_LIB_LQR_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_Hquad_control_LIB_LQR(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_Hquad_control_LIB_LQR(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_Hquad_control_LIB_LQR(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_Hquad_control_LIB_LQR_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
