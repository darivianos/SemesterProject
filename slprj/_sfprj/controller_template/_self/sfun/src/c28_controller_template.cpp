/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c28_controller_template.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c28_debug_family_names[4] = { "nargin", "nargout",
  "psi_meas", "psi_prime" };

/* Function Declarations */
static void initialize_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance);
static void enable_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance);
static void disable_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance);
static void c28_update_debugger_state_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance, const mxArray *c28_st);
static void finalize_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance);
static void sf_c28_controller_template(SFc28_controller_templateInstanceStruct
  *chartInstance);
static void initSimStructsc28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c28_machineNumber, uint32_T
  c28_chartNumber);
static const mxArray *c28_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static real_T c28_emlrt_marshallIn(SFc28_controller_templateInstanceStruct
  *chartInstance, const mxArray *c28_psi_prime, const char_T *c28_identifier);
static real_T c28_b_emlrt_marshallIn(SFc28_controller_templateInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static const mxArray *c28_b_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData);
static int32_T c28_c_emlrt_marshallIn(SFc28_controller_templateInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void c28_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData);
static uint8_T c28_d_emlrt_marshallIn(SFc28_controller_templateInstanceStruct
  *chartInstance, const mxArray *c28_is_active_c28_controller_template, const
  char_T *c28_identifier);
static uint8_T c28_e_emlrt_marshallIn(SFc28_controller_templateInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId);
static void init_dsm_address_info(SFc28_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c28_sfEvent;
  uint8_T *c28_is_active_c28_controller_template;
  c28_is_active_c28_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c28_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c28_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c28_is_active_c28_controller_template = 0U;
}

static void initialize_params_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c28_update_debugger_state_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance)
{
  c28_update_debugger_state_c28_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c28_st;
  const mxArray *c28_y = NULL;
  real_T c28_hoistedGlobal;
  real_T c28_u;
  const mxArray *c28_b_y = NULL;
  uint8_T c28_b_hoistedGlobal;
  uint8_T c28_b_u;
  const mxArray *c28_c_y = NULL;
  real_T *c28_psi_prime;
  uint8_T *c28_is_active_c28_controller_template;
  c28_psi_prime = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c28_is_active_c28_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c28_st = NULL;
  c28_st = NULL;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_createcellarray(2), FALSE);
  c28_hoistedGlobal = *c28_psi_prime;
  c28_u = c28_hoistedGlobal;
  c28_b_y = NULL;
  sf_mex_assign(&c28_b_y, sf_mex_create("y", &c28_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c28_y, 0, c28_b_y);
  c28_b_hoistedGlobal = *c28_is_active_c28_controller_template;
  c28_b_u = c28_b_hoistedGlobal;
  c28_c_y = NULL;
  sf_mex_assign(&c28_c_y, sf_mex_create("y", &c28_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c28_y, 1, c28_c_y);
  sf_mex_assign(&c28_st, c28_y, FALSE);
  return c28_st;
}

static void set_sim_state_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance, const mxArray *c28_st)
{
  const mxArray *c28_u;
  boolean_T *c28_doneDoubleBufferReInit;
  real_T *c28_psi_prime;
  uint8_T *c28_is_active_c28_controller_template;
  c28_psi_prime = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c28_is_active_c28_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c28_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c28_doneDoubleBufferReInit = TRUE;
  c28_u = sf_mex_dup(c28_st);
  *c28_psi_prime = c28_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c28_u, 0)), "psi_prime");
  *c28_is_active_c28_controller_template = c28_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c28_u, 1)), "is_active_c28_controller_template");
  sf_mex_destroy(&c28_u);
  c28_update_debugger_state_c28_controller_template(chartInstance);
  sf_mex_destroy(&c28_st);
}

static void finalize_c28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c28_controller_template(SFc28_controller_templateInstanceStruct
  *chartInstance)
{
  real_T c28_hoistedGlobal;
  real_T c28_psi_meas;
  uint32_T c28_debug_family_var_map[4];
  real_T c28_nargin = 1.0;
  real_T c28_nargout = 1.0;
  real_T c28_psi_prime;
  int32_T *c28_sfEvent;
  real_T *c28_b_psi_meas;
  real_T *c28_b_psi_prime;
  boolean_T guard1 = FALSE;
  c28_b_psi_prime = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c28_b_psi_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c28_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, *c28_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c28_b_psi_meas, 0U);
  _SFD_DATA_RANGE_CHECK(*c28_b_psi_prime, 1U);
  *c28_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, *c28_sfEvent);
  c28_hoistedGlobal = *c28_b_psi_meas;
  c28_psi_meas = c28_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 4U, 4U, c28_debug_family_names,
    c28_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c28_nargin, 0U, c28_sf_marshallOut,
    c28_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c28_nargout, 1U, c28_sf_marshallOut,
    c28_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c28_psi_meas, 2U, c28_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c28_psi_prime, 3U,
    c28_sf_marshallOut, c28_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c28_sfEvent, 4);
  c28_psi_prime = c28_psi_meas;
  _SFD_EML_CALL(0U, *c28_sfEvent, 7);
  guard1 = FALSE;
  if (CV_EML_COND(0, 1, 0, c28_psi_meas >= 0.78539816339744828)) {
    if (CV_EML_COND(0, 1, 1, c28_psi_meas <= 3.2553426535897931)) {
      CV_EML_MCDC(0, 1, 0, TRUE);
      CV_EML_IF(0, 1, 0, TRUE);
      _SFD_EML_CALL(0U, *c28_sfEvent, 8);
      c28_psi_prime = (c28_psi_meas - 3.1415926535897931) - 3.1415926535897931;
    } else {
      guard1 = TRUE;
    }
  } else {
    guard1 = TRUE;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
  }

  _SFD_EML_CALL(0U, *c28_sfEvent, -8);
  sf_debug_symbol_scope_pop();
  *c28_b_psi_prime = c28_psi_prime;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, *c28_sfEvent);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc28_controller_template
  (SFc28_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c28_machineNumber, uint32_T
  c28_chartNumber)
{
}

static const mxArray *c28_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  real_T c28_u;
  const mxArray *c28_y = NULL;
  SFc28_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc28_controller_templateInstanceStruct *)chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_u = *(real_T *)c28_inData;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, FALSE);
  return c28_mxArrayOutData;
}

static real_T c28_emlrt_marshallIn(SFc28_controller_templateInstanceStruct
  *chartInstance, const mxArray *c28_psi_prime, const char_T *c28_identifier)
{
  real_T c28_y;
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_psi_prime),
    &c28_thisId);
  sf_mex_destroy(&c28_psi_prime);
  return c28_y;
}

static real_T c28_b_emlrt_marshallIn(SFc28_controller_templateInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  real_T c28_y;
  real_T c28_d0;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_d0, 1, 0, 0U, 0, 0U, 0);
  c28_y = c28_d0;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_psi_prime;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  real_T c28_y;
  SFc28_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc28_controller_templateInstanceStruct *)chartInstanceVoid;
  c28_psi_prime = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_psi_prime),
    &c28_thisId);
  sf_mex_destroy(&c28_psi_prime);
  *(real_T *)c28_outData = c28_y;
  sf_mex_destroy(&c28_mxArrayInData);
}

const mxArray *sf_c28_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c28_nameCaptureInfo;
  c28_ResolvedFunctionInfo c28_info[4];
  c28_ResolvedFunctionInfo (*c28_b_info)[4];
  const mxArray *c28_m0 = NULL;
  int32_T c28_i0;
  c28_ResolvedFunctionInfo *c28_r0;
  c28_nameCaptureInfo = NULL;
  c28_nameCaptureInfo = NULL;
  c28_b_info = (c28_ResolvedFunctionInfo (*)[4])c28_info;
  (*c28_b_info)[0].context = "";
  (*c28_b_info)[0].name = "mrdivide";
  (*c28_b_info)[0].dominantType = "double";
  (*c28_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c28_b_info)[0].fileTimeLo = 1310137456U;
  (*c28_b_info)[0].fileTimeHi = 0U;
  (*c28_b_info)[0].mFileTimeLo = 1289519692U;
  (*c28_b_info)[0].mFileTimeHi = 0U;
  (*c28_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c28_b_info)[1].name = "rdivide";
  (*c28_b_info)[1].dominantType = "double";
  (*c28_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c28_b_info)[1].fileTimeLo = 1286818844U;
  (*c28_b_info)[1].fileTimeHi = 0U;
  (*c28_b_info)[1].mFileTimeLo = 0U;
  (*c28_b_info)[1].mFileTimeHi = 0U;
  (*c28_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c28_b_info)[2].name = "eml_div";
  (*c28_b_info)[2].dominantType = "double";
  (*c28_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c28_b_info)[2].fileTimeLo = 1305318000U;
  (*c28_b_info)[2].fileTimeHi = 0U;
  (*c28_b_info)[2].mFileTimeLo = 0U;
  (*c28_b_info)[2].mFileTimeHi = 0U;
  (*c28_b_info)[3].context = "";
  (*c28_b_info)[3].name = "mtimes";
  (*c28_b_info)[3].dominantType = "double";
  (*c28_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c28_b_info)[3].fileTimeLo = 1289519692U;
  (*c28_b_info)[3].fileTimeHi = 0U;
  (*c28_b_info)[3].mFileTimeLo = 0U;
  (*c28_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c28_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4), FALSE);
  for (c28_i0 = 0; c28_i0 < 4; c28_i0++) {
    c28_r0 = &c28_info[c28_i0];
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", c28_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c28_r0->context)), "context", "nameCaptureInfo",
                    c28_i0);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", c28_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c28_r0->name)), "name", "nameCaptureInfo", c28_i0);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo",
      c28_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c28_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c28_i0);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", c28_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c28_r0->resolved)), "resolved",
                    "nameCaptureInfo", c28_i0);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", &c28_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c28_i0);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo", &c28_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c28_i0);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo",
      &c28_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c28_i0);
    sf_mex_addfield(c28_m0, sf_mex_create("nameCaptureInfo",
      &c28_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c28_i0);
  }

  sf_mex_assign(&c28_nameCaptureInfo, c28_m0, FALSE);
  return c28_nameCaptureInfo;
}

static const mxArray *c28_b_sf_marshallOut(void *chartInstanceVoid, void
  *c28_inData)
{
  const mxArray *c28_mxArrayOutData = NULL;
  int32_T c28_u;
  const mxArray *c28_y = NULL;
  SFc28_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc28_controller_templateInstanceStruct *)chartInstanceVoid;
  c28_mxArrayOutData = NULL;
  c28_u = *(int32_T *)c28_inData;
  c28_y = NULL;
  sf_mex_assign(&c28_y, sf_mex_create("y", &c28_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c28_mxArrayOutData, c28_y, FALSE);
  return c28_mxArrayOutData;
}

static int32_T c28_c_emlrt_marshallIn(SFc28_controller_templateInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  int32_T c28_y;
  int32_T c28_i1;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_i1, 1, 6, 0U, 0, 0U, 0);
  c28_y = c28_i1;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void c28_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c28_mxArrayInData, const char_T *c28_varName, void *c28_outData)
{
  const mxArray *c28_sfEvent;
  const char_T *c28_identifier;
  emlrtMsgIdentifier c28_thisId;
  int32_T c28_y;
  SFc28_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc28_controller_templateInstanceStruct *)chartInstanceVoid;
  c28_sfEvent = sf_mex_dup(c28_mxArrayInData);
  c28_identifier = c28_varName;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c28_sfEvent),
    &c28_thisId);
  sf_mex_destroy(&c28_sfEvent);
  *(int32_T *)c28_outData = c28_y;
  sf_mex_destroy(&c28_mxArrayInData);
}

static uint8_T c28_d_emlrt_marshallIn(SFc28_controller_templateInstanceStruct
  *chartInstance, const mxArray *c28_is_active_c28_controller_template, const
  char_T *c28_identifier)
{
  uint8_T c28_y;
  emlrtMsgIdentifier c28_thisId;
  c28_thisId.fIdentifier = c28_identifier;
  c28_thisId.fParent = NULL;
  c28_y = c28_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c28_is_active_c28_controller_template), &c28_thisId);
  sf_mex_destroy(&c28_is_active_c28_controller_template);
  return c28_y;
}

static uint8_T c28_e_emlrt_marshallIn(SFc28_controller_templateInstanceStruct
  *chartInstance, const mxArray *c28_u, const emlrtMsgIdentifier *c28_parentId)
{
  uint8_T c28_y;
  uint8_T c28_u0;
  sf_mex_import(c28_parentId, sf_mex_dup(c28_u), &c28_u0, 1, 3, 0U, 0, 0U, 0);
  c28_y = c28_u0;
  sf_mex_destroy(&c28_u);
  return c28_y;
}

static void init_dsm_address_info(SFc28_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c28_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(496106811U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1467107529U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3292473996U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4178200754U);
}

mxArray *sf_c28_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("hy2wvFcxmbNcxCLBO2AZnE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static const mxArray *sf_get_sim_state_info_c28_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"psi_prime\",},{M[8],M[0],T\"is_active_c28_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c28_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc28_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc28_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           28,
           1,
           1,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"psi_meas");
          _SFD_SET_DATA_PROPS(1,2,0,1,"psi_prime");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,204);
        _SFD_CV_INIT_EML_IF(0,1,0,70,128,-1,179);

        {
          static int condStart[] = { 74, 101 };

          static int condEnd[] = { 97, 126 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,73,127,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
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
          (MexFcnForType)c28_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c28_sf_marshallOut,(MexInFcnForType)c28_sf_marshallIn);

        {
          real_T *c28_psi_meas;
          real_T *c28_psi_prime;
          c28_psi_prime = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c28_psi_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c28_psi_meas);
          _SFD_SET_DATA_VALUE_PTR(1U, c28_psi_prime);
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
      28, "dworkChecksum");
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

static void sf_opaque_initialize_c28_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc28_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc28_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c28_controller_template
    ((SFc28_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c28_controller_template((SFc28_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c28_controller_template(void *chartInstanceVar)
{
  enable_c28_controller_template((SFc28_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c28_controller_template(void *chartInstanceVar)
{
  disable_c28_controller_template((SFc28_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c28_controller_template(void *chartInstanceVar)
{
  sf_c28_controller_template((SFc28_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c28_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c28_controller_template((SFc28_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c28_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c28_controller_template
    ((SFc28_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c28_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c28_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c28_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c28_controller_template((SFc28_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c28_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c28_controller_template(S);
}

static void sf_opaque_set_sim_state_c28_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c28_controller_template(S, st);
}

static void sf_opaque_terminate_c28_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc28_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c28_controller_template((SFc28_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc28_controller_template((SFc28_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c28_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c28_controller_template
      ((SFc28_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c28_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c28_controller_template\",T\"is_active_c28_controller_template\"}}"
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

static void mdlSetWorkWidths_c28_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,28);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,28,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,28,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,28,1);
      sf_mark_chart_reusable_outputs(S,infoStruct,28,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,28);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2846981343U));
  ssSetChecksum1(S,(3313336288U));
  ssSetChecksum2(S,(874741029U));
  ssSetChecksum3(S,(738213970U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c28_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c28_controller_template(SimStruct *S)
{
  SFc28_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc28_controller_templateInstanceStruct *)malloc(sizeof
    (SFc28_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc28_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c28_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c28_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c28_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c28_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c28_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c28_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c28_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c28_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c28_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c28_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c28_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c28_controller_template;
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

void c28_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c28_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c28_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c28_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c28_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
