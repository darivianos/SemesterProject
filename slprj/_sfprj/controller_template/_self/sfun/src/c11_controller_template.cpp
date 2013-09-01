/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c11_controller_template.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c11_debug_family_names[6] = { "nargin", "nargout", "en_flag",
  "en_flag_prev", "count_out_prev", "count_out" };

/* Function Declarations */
static void initialize_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance);
static void enable_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance);
static void disable_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance, const mxArray *c11_st);
static void finalize_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance);
static void sf_c11_controller_template(SFc11_controller_templateInstanceStruct
  *chartInstance);
static void initSimStructsc11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_emlrt_marshallIn(SFc11_controller_templateInstanceStruct
  *chartInstance, const mxArray *c11_count_out, const char_T *c11_identifier);
static real_T c11_b_emlrt_marshallIn(SFc11_controller_templateInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_c_emlrt_marshallIn(SFc11_controller_templateInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_d_emlrt_marshallIn(SFc11_controller_templateInstanceStruct
  *chartInstance, const mxArray *c11_is_active_c11_controller_template, const
  char_T *c11_identifier);
static uint8_T c11_e_emlrt_marshallIn(SFc11_controller_templateInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c11_sfEvent;
  uint8_T *c11_is_active_c11_controller_template;
  c11_is_active_c11_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c11_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c11_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c11_is_active_c11_controller_template = 0U;
}

static void initialize_params_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c11_update_debugger_state_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance)
{
  c11_update_debugger_state_c11_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_u;
  const mxArray *c11_b_y = NULL;
  uint8_T c11_b_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  real_T *c11_count_out;
  uint8_T *c11_is_active_c11_controller_template;
  c11_count_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_is_active_c11_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellarray(2), FALSE);
  c11_hoistedGlobal = *c11_count_out;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal = *c11_is_active_c11_controller_template;
  c11_b_u = c11_b_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  sf_mex_assign(&c11_st, c11_y, FALSE);
  return c11_st;
}

static void set_sim_state_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  boolean_T *c11_doneDoubleBufferReInit;
  real_T *c11_count_out;
  uint8_T *c11_is_active_c11_controller_template;
  c11_count_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_is_active_c11_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c11_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c11_doneDoubleBufferReInit = TRUE;
  c11_u = sf_mex_dup(c11_st);
  *c11_count_out = c11_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c11_u, 0)), "count_out");
  *c11_is_active_c11_controller_template = c11_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 1)), "is_active_c11_controller_template");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_controller_template(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c11_controller_template(SFc11_controller_templateInstanceStruct
  *chartInstance)
{
  real_T c11_hoistedGlobal;
  real_T c11_b_hoistedGlobal;
  real_T c11_c_hoistedGlobal;
  real_T c11_en_flag;
  real_T c11_en_flag_prev;
  real_T c11_count_out_prev;
  uint32_T c11_debug_family_var_map[6];
  real_T c11_nargin = 3.0;
  real_T c11_nargout = 1.0;
  real_T c11_count_out;
  int32_T *c11_sfEvent;
  real_T *c11_b_en_flag;
  real_T *c11_b_count_out;
  real_T *c11_b_en_flag_prev;
  real_T *c11_b_count_out_prev;
  boolean_T guard1 = FALSE;
  boolean_T guard2 = FALSE;
  boolean_T guard3 = FALSE;
  c11_b_count_out_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c11_b_en_flag_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c11_b_count_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c11_b_en_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c11_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, *c11_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c11_b_en_flag, 0U);
  _SFD_DATA_RANGE_CHECK(*c11_b_count_out, 1U);
  _SFD_DATA_RANGE_CHECK(*c11_b_en_flag_prev, 2U);
  _SFD_DATA_RANGE_CHECK(*c11_b_count_out_prev, 3U);
  *c11_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, *c11_sfEvent);
  c11_hoistedGlobal = *c11_b_en_flag;
  c11_b_hoistedGlobal = *c11_b_en_flag_prev;
  c11_c_hoistedGlobal = *c11_b_count_out_prev;
  c11_en_flag = c11_hoistedGlobal;
  c11_en_flag_prev = c11_b_hoistedGlobal;
  c11_count_out_prev = c11_c_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c11_debug_family_names,
    c11_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c11_nargin, 0U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c11_nargout, 1U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c11_en_flag, 2U, c11_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c11_en_flag_prev, 3U, c11_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c11_count_out_prev, 4U, c11_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c11_count_out, 5U,
    c11_sf_marshallOut, c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c11_sfEvent, 4);
  c11_count_out = c11_count_out_prev;
  _SFD_EML_CALL(0U, *c11_sfEvent, 5);
  guard1 = FALSE;
  guard2 = FALSE;
  guard3 = FALSE;
  if (CV_EML_COND(0, 1, 0, c11_en_flag == 1.0)) {
    if (CV_EML_COND(0, 1, 1, c11_en_flag_prev == 0.0)) {
      guard2 = TRUE;
    } else {
      guard3 = TRUE;
    }
  } else {
    guard3 = TRUE;
  }

  if (guard3 == TRUE) {
    if (CV_EML_COND(0, 1, 2, c11_en_flag == 1.0)) {
      if (CV_EML_COND(0, 1, 3, c11_en_flag_prev == 1.0)) {
        guard2 = TRUE;
      } else {
        guard1 = TRUE;
      }
    } else {
      guard1 = TRUE;
    }
  }

  if (guard2 == TRUE) {
    CV_EML_MCDC(0, 1, 0, TRUE);
    CV_EML_IF(0, 1, 0, TRUE);
    _SFD_EML_CALL(0U, *c11_sfEvent, 6);
    c11_count_out = c11_count_out_prev + 1.0;
  }

  if (guard1 == TRUE) {
    CV_EML_MCDC(0, 1, 0, FALSE);
    CV_EML_IF(0, 1, 0, FALSE);
  }

  _SFD_EML_CALL(0U, *c11_sfEvent, -6);
  sf_debug_symbol_scope_pop();
  *c11_b_count_out = c11_count_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, *c11_sfEvent);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc11_controller_template
  (SFc11_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber)
{
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc11_controller_templateInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static real_T c11_emlrt_marshallIn(SFc11_controller_templateInstanceStruct
  *chartInstance, const mxArray *c11_count_out, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_count_out),
    &c11_thisId);
  sf_mex_destroy(&c11_count_out);
  return c11_y;
}

static real_T c11_b_emlrt_marshallIn(SFc11_controller_templateInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_count_out;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc11_controller_templateInstanceStruct *)chartInstanceVoid;
  c11_count_out = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_count_out),
    &c11_thisId);
  sf_mex_destroy(&c11_count_out);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c11_nameCaptureInfo;
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc11_controller_templateInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, FALSE);
  return c11_mxArrayOutData;
}

static int32_T c11_c_emlrt_marshallIn(SFc11_controller_templateInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i0, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc11_controller_templateInstanceStruct *)chartInstanceVoid;
  c11_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_d_emlrt_marshallIn(SFc11_controller_templateInstanceStruct
  *chartInstance, const mxArray *c11_is_active_c11_controller_template, const
  char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_is_active_c11_controller_template), &c11_thisId);
  sf_mex_destroy(&c11_is_active_c11_controller_template);
  return c11_y;
}

static uint8_T c11_e_emlrt_marshallIn(SFc11_controller_templateInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info(SFc11_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c11_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4182253637U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2970452699U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2900054294U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4290010883U);
}

mxArray *sf_c11_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("GMEx7tippoHjEDseqga4WF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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

static const mxArray *sf_get_sim_state_info_c11_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"count_out\",},{M[8],M[0],T\"is_active_c11_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc11_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           11,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"en_flag");
          _SFD_SET_DATA_PROPS(1,2,0,1,"count_out");
          _SFD_SET_DATA_PROPS(2,1,1,0,"en_flag_prev");
          _SFD_SET_DATA_PROPS(3,1,1,0,"count_out_prev");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,235);
        _SFD_CV_INIT_EML_IF(0,1,0,102,188,-1,230);

        {
          static int condStart[] = { 108, 126, 151, 169 };

          static int condEnd[] = { 120, 143, 163, 186 };

          static int pfixExpr[] = { 0, 1, -3, 2, 3, -3, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,106,188,4,0,&(condStart[0]),&(condEnd[0]),
                                7,&(pfixExpr[0]));
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
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c11_en_flag;
          real_T *c11_count_out;
          real_T *c11_en_flag_prev;
          real_T *c11_count_out_prev;
          c11_count_out_prev = (real_T *)ssGetInputPortSignal(chartInstance->S,
            2);
          c11_en_flag_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c11_count_out = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c11_en_flag = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c11_en_flag);
          _SFD_SET_DATA_VALUE_PTR(1U, c11_count_out);
          _SFD_SET_DATA_VALUE_PTR(2U, c11_en_flag_prev);
          _SFD_SET_DATA_VALUE_PTR(3U, c11_count_out_prev);
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
      11, "dworkChecksum");
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

static void sf_opaque_initialize_c11_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc11_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc11_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_controller_template
    ((SFc11_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c11_controller_template((SFc11_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_controller_template(void *chartInstanceVar)
{
  enable_c11_controller_template((SFc11_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_controller_template(void *chartInstanceVar)
{
  disable_c11_controller_template((SFc11_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_controller_template(void *chartInstanceVar)
{
  sf_c11_controller_template((SFc11_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c11_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c11_controller_template((SFc11_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c11_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c11_controller_template
    ((SFc11_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c11_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c11_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c11_controller_template((SFc11_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c11_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c11_controller_template(S);
}

static void sf_opaque_set_sim_state_c11_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c11_controller_template(S, st);
}

static void sf_opaque_terminate_c11_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c11_controller_template((SFc11_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_controller_template((SFc11_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_controller_template
      ((SFc11_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c11_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c11_controller_template\",T\"is_active_c11_controller_template\"}}"
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

static void mdlSetWorkWidths_c11_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,11,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,11,3);
      sf_mark_chart_reusable_outputs(S,infoStruct,11,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3910350673U));
  ssSetChecksum1(S,(1855889461U));
  ssSetChecksum2(S,(1107972188U));
  ssSetChecksum3(S,(4130263666U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c11_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_controller_template(SimStruct *S)
{
  SFc11_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc11_controller_templateInstanceStruct *)malloc(sizeof
    (SFc11_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c11_controller_template;
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

void c11_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
