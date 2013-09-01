/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c30_controller_template.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c30_debug_family_names[9] = { "nargin", "nargout",
  "psi_meas", "x_pos", "x_w", "thres_x", "ref_yaw", "psi_out", "delta_x" };

/* Function Declarations */
static void initialize_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance);
static void enable_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance);
static void disable_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance);
static void c30_update_debugger_state_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance, const mxArray *c30_st);
static void finalize_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance);
static void sf_c30_controller_template(SFc30_controller_templateInstanceStruct
  *chartInstance);
static void initSimStructsc30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber);
static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static real_T c30_emlrt_marshallIn(SFc30_controller_templateInstanceStruct
  *chartInstance, const mxArray *c30_delta_x, const char_T *c30_identifier);
static real_T c30_b_emlrt_marshallIn(SFc30_controller_templateInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData);
static int32_T c30_c_emlrt_marshallIn(SFc30_controller_templateInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData);
static uint8_T c30_d_emlrt_marshallIn(SFc30_controller_templateInstanceStruct
  *chartInstance, const mxArray *c30_is_active_c30_controller_template, const
  char_T *c30_identifier);
static uint8_T c30_e_emlrt_marshallIn(SFc30_controller_templateInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId);
static void init_dsm_address_info(SFc30_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c30_sfEvent;
  uint8_T *c30_is_active_c30_controller_template;
  c30_is_active_c30_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c30_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c30_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c30_is_active_c30_controller_template = 0U;
}

static void initialize_params_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c30_update_debugger_state_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance)
{
  c30_update_debugger_state_c30_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c30_st;
  const mxArray *c30_y = NULL;
  real_T c30_hoistedGlobal;
  real_T c30_u;
  const mxArray *c30_b_y = NULL;
  real_T c30_b_hoistedGlobal;
  real_T c30_b_u;
  const mxArray *c30_c_y = NULL;
  uint8_T c30_c_hoistedGlobal;
  uint8_T c30_c_u;
  const mxArray *c30_d_y = NULL;
  real_T *c30_delta_x;
  real_T *c30_psi_out;
  uint8_T *c30_is_active_c30_controller_template;
  c30_delta_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c30_psi_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c30_is_active_c30_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c30_st = NULL;
  c30_st = NULL;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_createcellarray(3), FALSE);
  c30_hoistedGlobal = *c30_delta_x;
  c30_u = c30_hoistedGlobal;
  c30_b_y = NULL;
  sf_mex_assign(&c30_b_y, sf_mex_create("y", &c30_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c30_y, 0, c30_b_y);
  c30_b_hoistedGlobal = *c30_psi_out;
  c30_b_u = c30_b_hoistedGlobal;
  c30_c_y = NULL;
  sf_mex_assign(&c30_c_y, sf_mex_create("y", &c30_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c30_y, 1, c30_c_y);
  c30_c_hoistedGlobal = *c30_is_active_c30_controller_template;
  c30_c_u = c30_c_hoistedGlobal;
  c30_d_y = NULL;
  sf_mex_assign(&c30_d_y, sf_mex_create("y", &c30_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c30_y, 2, c30_d_y);
  sf_mex_assign(&c30_st, c30_y, FALSE);
  return c30_st;
}

static void set_sim_state_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance, const mxArray *c30_st)
{
  const mxArray *c30_u;
  boolean_T *c30_doneDoubleBufferReInit;
  real_T *c30_delta_x;
  real_T *c30_psi_out;
  uint8_T *c30_is_active_c30_controller_template;
  c30_delta_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c30_psi_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c30_is_active_c30_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c30_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c30_doneDoubleBufferReInit = TRUE;
  c30_u = sf_mex_dup(c30_st);
  *c30_delta_x = c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c30_u, 0)), "delta_x");
  *c30_psi_out = c30_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c30_u, 1)), "psi_out");
  *c30_is_active_c30_controller_template = c30_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c30_u, 2)), "is_active_c30_controller_template");
  sf_mex_destroy(&c30_u);
  c30_update_debugger_state_c30_controller_template(chartInstance);
  sf_mex_destroy(&c30_st);
}

static void finalize_c30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c30_controller_template(SFc30_controller_templateInstanceStruct
  *chartInstance)
{
  real_T c30_hoistedGlobal;
  real_T c30_b_hoistedGlobal;
  real_T c30_c_hoistedGlobal;
  real_T c30_d_hoistedGlobal;
  real_T c30_e_hoistedGlobal;
  real_T c30_psi_meas;
  real_T c30_x_pos;
  real_T c30_x_w;
  real_T c30_thres_x;
  real_T c30_ref_yaw;
  uint32_T c30_debug_family_var_map[9];
  real_T c30_nargin = 5.0;
  real_T c30_nargout = 2.0;
  real_T c30_psi_out;
  real_T c30_delta_x;
  int32_T *c30_sfEvent;
  real_T *c30_b_psi_meas;
  real_T *c30_b_psi_out;
  real_T *c30_b_x_pos;
  real_T *c30_b_x_w;
  real_T *c30_b_thres_x;
  real_T *c30_b_ref_yaw;
  real_T *c30_b_delta_x;
  c30_b_delta_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c30_b_ref_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c30_b_thres_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c30_b_x_w = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c30_b_x_pos = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c30_b_psi_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c30_b_psi_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c30_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 21U, *c30_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c30_b_psi_meas, 0U);
  _SFD_DATA_RANGE_CHECK(*c30_b_psi_out, 1U);
  _SFD_DATA_RANGE_CHECK(*c30_b_x_pos, 2U);
  _SFD_DATA_RANGE_CHECK(*c30_b_x_w, 3U);
  _SFD_DATA_RANGE_CHECK(*c30_b_thres_x, 4U);
  _SFD_DATA_RANGE_CHECK(*c30_b_ref_yaw, 5U);
  _SFD_DATA_RANGE_CHECK(*c30_b_delta_x, 6U);
  *c30_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 21U, *c30_sfEvent);
  c30_hoistedGlobal = *c30_b_psi_meas;
  c30_b_hoistedGlobal = *c30_b_x_pos;
  c30_c_hoistedGlobal = *c30_b_x_w;
  c30_d_hoistedGlobal = *c30_b_thres_x;
  c30_e_hoistedGlobal = *c30_b_ref_yaw;
  c30_psi_meas = c30_hoistedGlobal;
  c30_x_pos = c30_b_hoistedGlobal;
  c30_x_w = c30_c_hoistedGlobal;
  c30_thres_x = c30_d_hoistedGlobal;
  c30_ref_yaw = c30_e_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 9U, 9U, c30_debug_family_names,
    c30_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c30_nargin, 0U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c30_nargout, 1U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c30_psi_meas, 2U, c30_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c30_x_pos, 3U, c30_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c30_x_w, 4U, c30_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c30_thres_x, 5U, c30_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c30_ref_yaw, 6U, c30_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c30_psi_out, 7U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c30_delta_x, 8U, c30_sf_marshallOut,
    c30_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c30_sfEvent, 4);
  c30_psi_out = c30_psi_meas;
  _SFD_EML_CALL(0U, *c30_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, c30_x_w - c30_x_pos <= c30_thres_x)) {
    _SFD_EML_CALL(0U, *c30_sfEvent, 7);
    c30_psi_out = c30_ref_yaw;
  }

  _SFD_EML_CALL(0U, *c30_sfEvent, 10);
  c30_delta_x = c30_x_w - c30_x_pos;
  _SFD_EML_CALL(0U, *c30_sfEvent, -10);
  sf_debug_symbol_scope_pop();
  *c30_b_psi_out = c30_psi_out;
  *c30_b_delta_x = c30_delta_x;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, *c30_sfEvent);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc30_controller_template
  (SFc30_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c30_machineNumber, uint32_T
  c30_chartNumber)
{
}

static const mxArray *c30_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  real_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc30_controller_templateInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(real_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, FALSE);
  return c30_mxArrayOutData;
}

static real_T c30_emlrt_marshallIn(SFc30_controller_templateInstanceStruct
  *chartInstance, const mxArray *c30_delta_x, const char_T *c30_identifier)
{
  real_T c30_y;
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_delta_x),
    &c30_thisId);
  sf_mex_destroy(&c30_delta_x);
  return c30_y;
}

static real_T c30_b_emlrt_marshallIn(SFc30_controller_templateInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  real_T c30_y;
  real_T c30_d0;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_d0, 1, 0, 0U, 0, 0U, 0);
  c30_y = c30_d0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_delta_x;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  real_T c30_y;
  SFc30_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc30_controller_templateInstanceStruct *)chartInstanceVoid;
  c30_delta_x = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_delta_x),
    &c30_thisId);
  sf_mex_destroy(&c30_delta_x);
  *(real_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

const mxArray *sf_c30_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c30_nameCaptureInfo = NULL;
  c30_nameCaptureInfo = NULL;
  sf_mex_assign(&c30_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c30_nameCaptureInfo;
}

static const mxArray *c30_b_sf_marshallOut(void *chartInstanceVoid, void
  *c30_inData)
{
  const mxArray *c30_mxArrayOutData = NULL;
  int32_T c30_u;
  const mxArray *c30_y = NULL;
  SFc30_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc30_controller_templateInstanceStruct *)chartInstanceVoid;
  c30_mxArrayOutData = NULL;
  c30_u = *(int32_T *)c30_inData;
  c30_y = NULL;
  sf_mex_assign(&c30_y, sf_mex_create("y", &c30_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c30_mxArrayOutData, c30_y, FALSE);
  return c30_mxArrayOutData;
}

static int32_T c30_c_emlrt_marshallIn(SFc30_controller_templateInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  int32_T c30_y;
  int32_T c30_i0;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_i0, 1, 6, 0U, 0, 0U, 0);
  c30_y = c30_i0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void c30_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c30_mxArrayInData, const char_T *c30_varName, void *c30_outData)
{
  const mxArray *c30_sfEvent;
  const char_T *c30_identifier;
  emlrtMsgIdentifier c30_thisId;
  int32_T c30_y;
  SFc30_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc30_controller_templateInstanceStruct *)chartInstanceVoid;
  c30_sfEvent = sf_mex_dup(c30_mxArrayInData);
  c30_identifier = c30_varName;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c30_sfEvent),
    &c30_thisId);
  sf_mex_destroy(&c30_sfEvent);
  *(int32_T *)c30_outData = c30_y;
  sf_mex_destroy(&c30_mxArrayInData);
}

static uint8_T c30_d_emlrt_marshallIn(SFc30_controller_templateInstanceStruct
  *chartInstance, const mxArray *c30_is_active_c30_controller_template, const
  char_T *c30_identifier)
{
  uint8_T c30_y;
  emlrtMsgIdentifier c30_thisId;
  c30_thisId.fIdentifier = c30_identifier;
  c30_thisId.fParent = NULL;
  c30_y = c30_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c30_is_active_c30_controller_template), &c30_thisId);
  sf_mex_destroy(&c30_is_active_c30_controller_template);
  return c30_y;
}

static uint8_T c30_e_emlrt_marshallIn(SFc30_controller_templateInstanceStruct
  *chartInstance, const mxArray *c30_u, const emlrtMsgIdentifier *c30_parentId)
{
  uint8_T c30_y;
  uint8_T c30_u0;
  sf_mex_import(c30_parentId, sf_mex_dup(c30_u), &c30_u0, 1, 3, 0U, 0, 0U, 0);
  c30_y = c30_u0;
  sf_mex_destroy(&c30_u);
  return c30_y;
}

static void init_dsm_address_info(SFc30_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c30_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2130560197U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3940329785U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1801755350U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(132841891U);
}

mxArray *sf_c30_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("QtsBxuvUaonpGaaKXRNU7G");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

static const mxArray *sf_get_sim_state_info_c30_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[10],T\"delta_x\",},{M[1],M[5],T\"psi_out\",},{M[8],M[0],T\"is_active_c30_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c30_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc30_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc30_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           30,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"psi_meas");
          _SFD_SET_DATA_PROPS(1,2,0,1,"psi_out");
          _SFD_SET_DATA_PROPS(2,1,1,0,"x_pos");
          _SFD_SET_DATA_PROPS(3,1,1,0,"x_w");
          _SFD_SET_DATA_PROPS(4,1,1,0,"thres_x");
          _SFD_SET_DATA_PROPS(5,1,1,0,"ref_yaw");
          _SFD_SET_DATA_PROPS(6,2,0,1,"delta_x");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,181);
        _SFD_CV_INIT_EML_IF(0,1,0,101,125,-1,152);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)c30_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c30_sf_marshallOut,(MexInFcnForType)c30_sf_marshallIn);

        {
          real_T *c30_psi_meas;
          real_T *c30_psi_out;
          real_T *c30_x_pos;
          real_T *c30_x_w;
          real_T *c30_thres_x;
          real_T *c30_ref_yaw;
          real_T *c30_delta_x;
          c30_delta_x = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c30_ref_yaw = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c30_thres_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c30_x_w = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c30_x_pos = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c30_psi_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c30_psi_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c30_psi_meas);
          _SFD_SET_DATA_VALUE_PTR(1U, c30_psi_out);
          _SFD_SET_DATA_VALUE_PTR(2U, c30_x_pos);
          _SFD_SET_DATA_VALUE_PTR(3U, c30_x_w);
          _SFD_SET_DATA_VALUE_PTR(4U, c30_thres_x);
          _SFD_SET_DATA_VALUE_PTR(5U, c30_ref_yaw);
          _SFD_SET_DATA_VALUE_PTR(6U, c30_delta_x);
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
      30, "dworkChecksum");
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

static void sf_opaque_initialize_c30_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc30_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc30_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c30_controller_template
    ((SFc30_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c30_controller_template((SFc30_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c30_controller_template(void *chartInstanceVar)
{
  enable_c30_controller_template((SFc30_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c30_controller_template(void *chartInstanceVar)
{
  disable_c30_controller_template((SFc30_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c30_controller_template(void *chartInstanceVar)
{
  sf_c30_controller_template((SFc30_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c30_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c30_controller_template((SFc30_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c30_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c30_controller_template
    ((SFc30_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c30_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c30_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c30_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c30_controller_template((SFc30_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c30_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c30_controller_template(S);
}

static void sf_opaque_set_sim_state_c30_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c30_controller_template(S, st);
}

static void sf_opaque_terminate_c30_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc30_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c30_controller_template((SFc30_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc30_controller_template((SFc30_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c30_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c30_controller_template
      ((SFc30_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c30_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c30_controller_template\",T\"is_active_c30_controller_template\"}}"
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

static void mdlSetWorkWidths_c30_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,30);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,30,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,30,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,30,5);
      sf_mark_chart_reusable_outputs(S,infoStruct,30,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,30);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2751627439U));
  ssSetChecksum1(S,(1322868073U));
  ssSetChecksum2(S,(2858537488U));
  ssSetChecksum3(S,(3955643563U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c30_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c30_controller_template(SimStruct *S)
{
  SFc30_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc30_controller_templateInstanceStruct *)malloc(sizeof
    (SFc30_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc30_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c30_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c30_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c30_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c30_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c30_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c30_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c30_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c30_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c30_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c30_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c30_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c30_controller_template;
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

void c30_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c30_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c30_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c30_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c30_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
