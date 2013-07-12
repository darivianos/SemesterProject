/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c35_controller_template.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c35_debug_family_names[11] = { "dy", "dz", "nargin",
  "nargout", "dx", "y", "z", "yref", "zref", "thres", "en" };

/* Function Declarations */
static void initialize_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance);
static void enable_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance);
static void disable_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance);
static void c35_update_debugger_state_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance, const mxArray *c35_st);
static void finalize_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance);
static void sf_c35_controller_template(SFc35_controller_templateInstanceStruct
  *chartInstance);
static void initSimStructsc35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber);
static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static real_T c35_emlrt_marshallIn(SFc35_controller_templateInstanceStruct
  *chartInstance, const mxArray *c35_en, const char_T *c35_identifier);
static real_T c35_b_emlrt_marshallIn(SFc35_controller_templateInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData);
static int32_T c35_c_emlrt_marshallIn(SFc35_controller_templateInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData);
static uint8_T c35_d_emlrt_marshallIn(SFc35_controller_templateInstanceStruct
  *chartInstance, const mxArray *c35_is_active_c35_controller_template, const
  char_T *c35_identifier);
static uint8_T c35_e_emlrt_marshallIn(SFc35_controller_templateInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId);
static void init_dsm_address_info(SFc35_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c35_sfEvent;
  uint8_T *c35_is_active_c35_controller_template;
  c35_is_active_c35_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c35_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c35_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c35_is_active_c35_controller_template = 0U;
}

static void initialize_params_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c35_update_debugger_state_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance)
{
  c35_update_debugger_state_c35_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c35_st;
  const mxArray *c35_y = NULL;
  real_T c35_hoistedGlobal;
  real_T c35_u;
  const mxArray *c35_b_y = NULL;
  uint8_T c35_b_hoistedGlobal;
  uint8_T c35_b_u;
  const mxArray *c35_c_y = NULL;
  real_T *c35_en;
  uint8_T *c35_is_active_c35_controller_template;
  c35_en = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c35_is_active_c35_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c35_st = NULL;
  c35_st = NULL;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_createcellarray(2), FALSE);
  c35_hoistedGlobal = *c35_en;
  c35_u = c35_hoistedGlobal;
  c35_b_y = NULL;
  sf_mex_assign(&c35_b_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 0, c35_b_y);
  c35_b_hoistedGlobal = *c35_is_active_c35_controller_template;
  c35_b_u = c35_b_hoistedGlobal;
  c35_c_y = NULL;
  sf_mex_assign(&c35_c_y, sf_mex_create("y", &c35_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c35_y, 1, c35_c_y);
  sf_mex_assign(&c35_st, c35_y, FALSE);
  return c35_st;
}

static void set_sim_state_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance, const mxArray *c35_st)
{
  const mxArray *c35_u;
  boolean_T *c35_doneDoubleBufferReInit;
  real_T *c35_en;
  uint8_T *c35_is_active_c35_controller_template;
  c35_en = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c35_is_active_c35_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c35_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c35_doneDoubleBufferReInit = TRUE;
  c35_u = sf_mex_dup(c35_st);
  *c35_en = c35_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c35_u,
    0)), "en");
  *c35_is_active_c35_controller_template = c35_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c35_u, 1)), "is_active_c35_controller_template");
  sf_mex_destroy(&c35_u);
  c35_update_debugger_state_c35_controller_template(chartInstance);
  sf_mex_destroy(&c35_st);
}

static void finalize_c35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c35_controller_template(SFc35_controller_templateInstanceStruct
  *chartInstance)
{
  real_T c35_hoistedGlobal;
  real_T c35_b_hoistedGlobal;
  real_T c35_c_hoistedGlobal;
  real_T c35_d_hoistedGlobal;
  real_T c35_e_hoistedGlobal;
  real_T c35_f_hoistedGlobal;
  real_T c35_dx;
  real_T c35_y;
  real_T c35_z;
  real_T c35_yref;
  real_T c35_zref;
  real_T c35_thres;
  uint32_T c35_debug_family_var_map[11];
  real_T c35_dy;
  real_T c35_dz;
  real_T c35_nargin = 6.0;
  real_T c35_nargout = 1.0;
  real_T c35_en;
  real_T c35_x;
  real_T c35_b_x;
  real_T c35_b_y;
  real_T c35_c_x;
  real_T c35_d_x;
  real_T c35_c_y;
  int32_T *c35_sfEvent;
  real_T *c35_b_dx;
  real_T *c35_d_y;
  real_T *c35_b_z;
  real_T *c35_b_yref;
  real_T *c35_b_zref;
  real_T *c35_b_thres;
  real_T *c35_b_en;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  c35_b_en = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c35_b_thres = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c35_b_zref = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c35_b_yref = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c35_b_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c35_d_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c35_b_dx = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c35_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 27U, *c35_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c35_b_dx, 0U);
  _SFD_DATA_RANGE_CHECK(*c35_d_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c35_b_z, 2U);
  _SFD_DATA_RANGE_CHECK(*c35_b_yref, 3U);
  _SFD_DATA_RANGE_CHECK(*c35_b_zref, 4U);
  _SFD_DATA_RANGE_CHECK(*c35_b_thres, 5U);
  _SFD_DATA_RANGE_CHECK(*c35_b_en, 6U);
  *c35_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 27U, *c35_sfEvent);
  c35_hoistedGlobal = *c35_b_dx;
  c35_b_hoistedGlobal = *c35_d_y;
  c35_c_hoistedGlobal = *c35_b_z;
  c35_d_hoistedGlobal = *c35_b_yref;
  c35_e_hoistedGlobal = *c35_b_zref;
  c35_f_hoistedGlobal = *c35_b_thres;
  c35_dx = c35_hoistedGlobal;
  c35_y = c35_b_hoistedGlobal;
  c35_z = c35_c_hoistedGlobal;
  c35_yref = c35_d_hoistedGlobal;
  c35_zref = c35_e_hoistedGlobal;
  c35_thres = c35_f_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 11U, 11U, c35_debug_family_names,
    c35_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c35_dy, 0U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c35_dz, 1U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c35_nargin, 2U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c35_nargout, 3U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c35_dx, 4U, c35_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c35_y, 5U, c35_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c35_z, 6U, c35_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c35_yref, 7U, c35_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c35_zref, 8U, c35_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c35_thres, 9U, c35_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c35_en, 10U, c35_sf_marshallOut,
    c35_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c35_sfEvent, 3);
  c35_x = c35_y - c35_yref;
  c35_b_x = c35_x;
  c35_b_y = muDoubleScalarAbs(c35_b_x);
  if (CV_EML_IF(0, 1, 0, c35_b_y > c35_thres)) {
    _SFD_EML_CALL(0U, *c35_sfEvent, 4);
    c35_dy = 1.0;
  } else {
    _SFD_EML_CALL(0U, *c35_sfEvent, 6);
    c35_dy = 0.0;
  }

  _SFD_EML_CALL(0U, *c35_sfEvent, 9);
  c35_c_x = c35_z - c35_zref;
  c35_d_x = c35_c_x;
  c35_c_y = muDoubleScalarAbs(c35_d_x);
  if (CV_EML_IF(0, 1, 1, c35_c_y > c35_thres)) {
    _SFD_EML_CALL(0U, *c35_sfEvent, 10);
    c35_dz = 1.0;
  } else {
    _SFD_EML_CALL(0U, *c35_sfEvent, 12);
    c35_dz = 0.0;
  }

  _SFD_EML_CALL(0U, *c35_sfEvent, 16);
  guard1 = FALSE;
  guard2 = FALSE;
  if (CV_EML_COND(0, 1, 0, c35_dy != 0.0)) {
    guard2 = TRUE;
  } else if (CV_EML_COND(0, 1, 1, c35_dz != 0.0)) {
    guard2 = TRUE;
  } else if (CV_EML_COND(0, 1, 2, c35_dx != 0.0)) {
    guard1 = TRUE;
  } else {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 2, FALSE);
    _SFD_EML_CALL(0U, *c35_sfEvent, 19);
    c35_en = 1.0;
  }

  if (guard2 == TRUE) {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, TRUE);
    CV_EML_IF(0, 1, 2, TRUE);
    _SFD_EML_CALL(0U, *c35_sfEvent, 17);
    c35_en = 0.0;
  }

  _SFD_EML_CALL(0U, *c35_sfEvent, -19);
  sf_debug_symbol_scope_pop();
  *c35_b_en = c35_en;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 27U, *c35_sfEvent);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc35_controller_template
  (SFc35_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c35_machineNumber, uint32_T
  c35_chartNumber)
{
}

static const mxArray *c35_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  real_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc35_controller_templateInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(real_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, FALSE);
  return c35_mxArrayOutData;
}

static real_T c35_emlrt_marshallIn(SFc35_controller_templateInstanceStruct
  *chartInstance, const mxArray *c35_en, const char_T *c35_identifier)
{
  real_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_en), &c35_thisId);
  sf_mex_destroy(&c35_en);
  return c35_y;
}

static real_T c35_b_emlrt_marshallIn(SFc35_controller_templateInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  real_T c35_y;
  real_T c35_d0;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_d0, 1, 0, 0U, 0, 0U, 0);
  c35_y = c35_d0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_en;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  real_T c35_y;
  SFc35_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc35_controller_templateInstanceStruct *)chartInstanceVoid;
  c35_en = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_en), &c35_thisId);
  sf_mex_destroy(&c35_en);
  *(real_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

const mxArray *sf_c35_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c35_nameCaptureInfo;
  c35_ResolvedFunctionInfo c35_info[2];
  c35_ResolvedFunctionInfo (*c35_b_info)[2];
  const mxArray *c35_m0 = NULL;
  int32_T c35_i0;
  c35_ResolvedFunctionInfo *c35_r0;
  c35_nameCaptureInfo = NULL;
  c35_nameCaptureInfo = NULL;
  c35_b_info = (c35_ResolvedFunctionInfo (*)[2])c35_info;
  (*c35_b_info)[0].context = "";
  (*c35_b_info)[0].name = "abs";
  (*c35_b_info)[0].dominantType = "double";
  (*c35_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c35_b_info)[0].fileTimeLo = 1286818694U;
  (*c35_b_info)[0].fileTimeHi = 0U;
  (*c35_b_info)[0].mFileTimeLo = 0U;
  (*c35_b_info)[0].mFileTimeHi = 0U;
  (*c35_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m";
  (*c35_b_info)[1].name = "eml_scalar_abs";
  (*c35_b_info)[1].dominantType = "double";
  (*c35_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  (*c35_b_info)[1].fileTimeLo = 1286818712U;
  (*c35_b_info)[1].fileTimeHi = 0U;
  (*c35_b_info)[1].mFileTimeLo = 0U;
  (*c35_b_info)[1].mFileTimeHi = 0U;
  sf_mex_assign(&c35_m0, sf_mex_createstruct("nameCaptureInfo", 1, 2), FALSE);
  for (c35_i0 = 0; c35_i0 < 2; c35_i0++) {
    c35_r0 = &c35_info[c35_i0];
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", c35_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c35_r0->context)), "context", "nameCaptureInfo",
                    c35_i0);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", c35_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c35_r0->name)), "name", "nameCaptureInfo", c35_i0);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo",
      c35_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c35_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c35_i0);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", c35_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c35_r0->resolved)), "resolved",
                    "nameCaptureInfo", c35_i0);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", &c35_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c35_i0);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo", &c35_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c35_i0);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo",
      &c35_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c35_i0);
    sf_mex_addfield(c35_m0, sf_mex_create("nameCaptureInfo",
      &c35_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c35_i0);
  }

  sf_mex_assign(&c35_nameCaptureInfo, c35_m0, FALSE);
  return c35_nameCaptureInfo;
}

static const mxArray *c35_b_sf_marshallOut(void *chartInstanceVoid, void
  *c35_inData)
{
  const mxArray *c35_mxArrayOutData = NULL;
  int32_T c35_u;
  const mxArray *c35_y = NULL;
  SFc35_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc35_controller_templateInstanceStruct *)chartInstanceVoid;
  c35_mxArrayOutData = NULL;
  c35_u = *(int32_T *)c35_inData;
  c35_y = NULL;
  sf_mex_assign(&c35_y, sf_mex_create("y", &c35_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c35_mxArrayOutData, c35_y, FALSE);
  return c35_mxArrayOutData;
}

static int32_T c35_c_emlrt_marshallIn(SFc35_controller_templateInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  int32_T c35_y;
  int32_T c35_i1;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_i1, 1, 6, 0U, 0, 0U, 0);
  c35_y = c35_i1;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void c35_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c35_mxArrayInData, const char_T *c35_varName, void *c35_outData)
{
  const mxArray *c35_sfEvent;
  const char_T *c35_identifier;
  emlrtMsgIdentifier c35_thisId;
  int32_T c35_y;
  SFc35_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc35_controller_templateInstanceStruct *)chartInstanceVoid;
  c35_sfEvent = sf_mex_dup(c35_mxArrayInData);
  c35_identifier = c35_varName;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c35_sfEvent),
    &c35_thisId);
  sf_mex_destroy(&c35_sfEvent);
  *(int32_T *)c35_outData = c35_y;
  sf_mex_destroy(&c35_mxArrayInData);
}

static uint8_T c35_d_emlrt_marshallIn(SFc35_controller_templateInstanceStruct
  *chartInstance, const mxArray *c35_is_active_c35_controller_template, const
  char_T *c35_identifier)
{
  uint8_T c35_y;
  emlrtMsgIdentifier c35_thisId;
  c35_thisId.fIdentifier = c35_identifier;
  c35_thisId.fParent = NULL;
  c35_y = c35_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c35_is_active_c35_controller_template), &c35_thisId);
  sf_mex_destroy(&c35_is_active_c35_controller_template);
  return c35_y;
}

static uint8_T c35_e_emlrt_marshallIn(SFc35_controller_templateInstanceStruct
  *chartInstance, const mxArray *c35_u, const emlrtMsgIdentifier *c35_parentId)
{
  uint8_T c35_y;
  uint8_T c35_u0;
  sf_mex_import(c35_parentId, sf_mex_dup(c35_u), &c35_u0, 1, 3, 0U, 0, 0U, 0);
  c35_y = c35_u0;
  sf_mex_destroy(&c35_u);
  return c35_y;
}

static void init_dsm_address_info(SFc35_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c35_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(264445478U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3543996251U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(272677494U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2307719619U);
}

mxArray *sf_c35_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("svA0AiEuchYRCkWbXsGeKC");
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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c35_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[10],T\"en\",},{M[8],M[0],T\"is_active_c35_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c35_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc35_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc35_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           35,
           1,
           1,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"dx");
          _SFD_SET_DATA_PROPS(1,1,1,0,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"z");
          _SFD_SET_DATA_PROPS(3,1,1,0,"yref");
          _SFD_SET_DATA_PROPS(4,1,1,0,"zref");
          _SFD_SET_DATA_PROPS(5,1,1,0,"thres");
          _SFD_SET_DATA_PROPS(6,2,0,1,"en");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,356);
        _SFD_CV_INIT_EML_IF(0,1,0,43,65,78,112);
        _SFD_CV_INIT_EML_IF(0,1,1,114,136,149,183);
        _SFD_CV_INIT_EML_IF(0,1,2,186,217,276,355);

        {
          static int condStart[] = { 189, 200, 211 };

          static int condEnd[] = { 196, 207, 217 };

          static int pfixExpr[] = { 0, 1, -2, 2, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,189,217,3,0,&(condStart[0]),&(condEnd[0]),
                                5,&(pfixExpr[0]));
        }

        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c35_sf_marshallOut,(MexInFcnForType)c35_sf_marshallIn);

        {
          real_T *c35_dx;
          real_T *c35_y;
          real_T *c35_z;
          real_T *c35_yref;
          real_T *c35_zref;
          real_T *c35_thres;
          real_T *c35_en;
          c35_en = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c35_thres = (real_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c35_zref = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c35_yref = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c35_z = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c35_y = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c35_dx = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c35_dx);
          _SFD_SET_DATA_VALUE_PTR(1U, c35_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c35_z);
          _SFD_SET_DATA_VALUE_PTR(3U, c35_yref);
          _SFD_SET_DATA_VALUE_PTR(4U, c35_zref);
          _SFD_SET_DATA_VALUE_PTR(5U, c35_thres);
          _SFD_SET_DATA_VALUE_PTR(6U, c35_en);
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
      35, "dworkChecksum");
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

static void sf_opaque_initialize_c35_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc35_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc35_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c35_controller_template
    ((SFc35_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c35_controller_template((SFc35_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c35_controller_template(void *chartInstanceVar)
{
  enable_c35_controller_template((SFc35_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c35_controller_template(void *chartInstanceVar)
{
  disable_c35_controller_template((SFc35_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c35_controller_template(void *chartInstanceVar)
{
  sf_c35_controller_template((SFc35_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c35_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c35_controller_template((SFc35_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c35_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c35_controller_template
    ((SFc35_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c35_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c35_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c35_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c35_controller_template((SFc35_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c35_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c35_controller_template(S);
}

static void sf_opaque_set_sim_state_c35_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c35_controller_template(S, st);
}

static void sf_opaque_terminate_c35_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc35_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c35_controller_template((SFc35_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc35_controller_template((SFc35_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c35_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c35_controller_template
      ((SFc35_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c35_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c35_controller_template\",T\"is_active_c35_controller_template\"}}"
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

static void mdlSetWorkWidths_c35_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,35);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,35,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,35,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,35,6);
      sf_mark_chart_reusable_outputs(S,infoStruct,35,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,35);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1619057529U));
  ssSetChecksum1(S,(2797485704U));
  ssSetChecksum2(S,(3628317550U));
  ssSetChecksum3(S,(3916556576U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c35_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c35_controller_template(SimStruct *S)
{
  SFc35_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc35_controller_templateInstanceStruct *)malloc(sizeof
    (SFc35_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc35_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c35_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c35_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c35_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c35_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c35_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c35_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c35_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c35_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c35_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c35_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c35_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c35_controller_template;
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

void c35_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c35_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c35_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c35_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c35_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
