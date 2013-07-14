/* Include files */

#include "blascompat32.h"
#include "controller_template_rectangle_sfun.h"
#include "c23_controller_template_rectangle.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_rectangle_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c23_debug_family_names[5] = { "nargin", "nargout", "u",
  "thres", "y" };

/* Function Declarations */
static void initialize_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance);
static void initialize_params_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance);
static void enable_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance);
static void disable_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance);
static void c23_update_debugger_state_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance);
static void ext_mode_exec_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance);
static void set_sim_state_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c23_st);
static void finalize_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance);
static void sf_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance);
static void initSimStructsc23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c23_machineNumber, uint32_T
  c23_chartNumber);
static const mxArray *c23_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static real_T c23_emlrt_marshallIn
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c23_y, const char_T *c23_identifier);
static real_T c23_b_emlrt_marshallIn
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData);
static int32_T c23_c_emlrt_marshallIn
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData);
static uint8_T c23_d_emlrt_marshallIn
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c23_is_active_c23_controller_template_rectangle, const char_T
   *c23_identifier);
static uint8_T c23_e_emlrt_marshallIn
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId);
static void init_dsm_address_info
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance)
{
  int32_T *c23_sfEvent;
  uint8_T *c23_is_active_c23_controller_template_rectangle;
  c23_is_active_c23_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c23_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c23_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c23_is_active_c23_controller_template_rectangle = 0U;
}

static void initialize_params_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void enable_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c23_update_debugger_state_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance)
{
  c23_update_debugger_state_c23_controller_template_rectangle(chartInstance);
}

static const mxArray *get_sim_state_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance)
{
  const mxArray *c23_st;
  const mxArray *c23_y = NULL;
  real_T c23_hoistedGlobal;
  real_T c23_u;
  const mxArray *c23_b_y = NULL;
  uint8_T c23_b_hoistedGlobal;
  uint8_T c23_b_u;
  const mxArray *c23_c_y = NULL;
  real_T *c23_d_y;
  uint8_T *c23_is_active_c23_controller_template_rectangle;
  c23_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_is_active_c23_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c23_st = NULL;
  c23_st = NULL;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_createcellarray(2), FALSE);
  c23_hoistedGlobal = *c23_d_y;
  c23_u = c23_hoistedGlobal;
  c23_b_y = NULL;
  sf_mex_assign(&c23_b_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c23_y, 0, c23_b_y);
  c23_b_hoistedGlobal = *c23_is_active_c23_controller_template_rectangle;
  c23_b_u = c23_b_hoistedGlobal;
  c23_c_y = NULL;
  sf_mex_assign(&c23_c_y, sf_mex_create("y", &c23_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c23_y, 1, c23_c_y);
  sf_mex_assign(&c23_st, c23_y, FALSE);
  return c23_st;
}

static void set_sim_state_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c23_st)
{
  const mxArray *c23_u;
  boolean_T *c23_doneDoubleBufferReInit;
  real_T *c23_y;
  uint8_T *c23_is_active_c23_controller_template_rectangle;
  c23_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_is_active_c23_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c23_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c23_doneDoubleBufferReInit = TRUE;
  c23_u = sf_mex_dup(c23_st);
  *c23_y = c23_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c23_u,
    0)), "y");
  *c23_is_active_c23_controller_template_rectangle = c23_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c23_u, 1)),
     "is_active_c23_controller_template_rectangle");
  sf_mex_destroy(&c23_u);
  c23_update_debugger_state_c23_controller_template_rectangle(chartInstance);
  sf_mex_destroy(&c23_st);
}

static void finalize_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void sf_c23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance)
{
  real_T c23_hoistedGlobal;
  real_T c23_b_hoistedGlobal;
  real_T c23_u;
  real_T c23_thres;
  uint32_T c23_debug_family_var_map[5];
  real_T c23_nargin = 2.0;
  real_T c23_nargout = 1.0;
  real_T c23_y;
  int32_T *c23_sfEvent;
  real_T *c23_b_u;
  real_T *c23_b_y;
  real_T *c23_b_thres;
  c23_b_thres = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c23_b_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c23_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c23_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 22U, *c23_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c23_b_u, 0U);
  _SFD_DATA_RANGE_CHECK(*c23_b_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c23_b_thres, 2U);
  *c23_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 22U, *c23_sfEvent);
  c23_hoistedGlobal = *c23_b_u;
  c23_b_hoistedGlobal = *c23_b_thres;
  c23_u = c23_hoistedGlobal;
  c23_thres = c23_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c23_debug_family_names,
    c23_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c23_nargin, 0U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c23_nargout, 1U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c23_u, 2U, c23_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c23_thres, 3U, c23_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c23_y, 4U, c23_sf_marshallOut,
    c23_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c23_sfEvent, 3);
  if (CV_EML_IF(0, 1, 0, c23_u >= c23_thres)) {
    _SFD_EML_CALL(0U, *c23_sfEvent, 4);
    c23_y = 0.0;
  } else {
    _SFD_EML_CALL(0U, *c23_sfEvent, 6);
    c23_y = c23_u;
  }

  _SFD_EML_CALL(0U, *c23_sfEvent, -6);
  sf_debug_symbol_scope_pop();
  *c23_b_y = c23_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, *c23_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_controller_template_rectangleMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc23_controller_template_rectangle
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance)
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
  SFc23_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc23_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(real_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static real_T c23_emlrt_marshallIn
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c23_y, const char_T *c23_identifier)
{
  real_T c23_b_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_y), &c23_thisId);
  sf_mex_destroy(&c23_y);
  return c23_b_y;
}

static real_T c23_b_emlrt_marshallIn
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
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
  const mxArray *c23_y;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  real_T c23_b_y;
  SFc23_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc23_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c23_y = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_b_y = c23_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_y), &c23_thisId);
  sf_mex_destroy(&c23_y);
  *(real_T *)c23_outData = c23_b_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

const mxArray
  *sf_c23_controller_template_rectangle_get_eml_resolved_functions_info(void)
{
  const mxArray *c23_nameCaptureInfo = NULL;
  c23_nameCaptureInfo = NULL;
  sf_mex_assign(&c23_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c23_nameCaptureInfo;
}

static const mxArray *c23_b_sf_marshallOut(void *chartInstanceVoid, void
  *c23_inData)
{
  const mxArray *c23_mxArrayOutData = NULL;
  int32_T c23_u;
  const mxArray *c23_y = NULL;
  SFc23_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc23_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c23_mxArrayOutData = NULL;
  c23_u = *(int32_T *)c23_inData;
  c23_y = NULL;
  sf_mex_assign(&c23_y, sf_mex_create("y", &c23_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c23_mxArrayOutData, c23_y, FALSE);
  return c23_mxArrayOutData;
}

static int32_T c23_c_emlrt_marshallIn
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  int32_T c23_y;
  int32_T c23_i0;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_i0, 1, 6, 0U, 0, 0U, 0);
  c23_y = c23_i0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void c23_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c23_mxArrayInData, const char_T *c23_varName, void *c23_outData)
{
  const mxArray *c23_sfEvent;
  const char_T *c23_identifier;
  emlrtMsgIdentifier c23_thisId;
  int32_T c23_y;
  SFc23_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc23_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c23_sfEvent = sf_mex_dup(c23_mxArrayInData);
  c23_identifier = c23_varName;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c23_sfEvent),
    &c23_thisId);
  sf_mex_destroy(&c23_sfEvent);
  *(int32_T *)c23_outData = c23_y;
  sf_mex_destroy(&c23_mxArrayInData);
}

static uint8_T c23_d_emlrt_marshallIn
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c23_is_active_c23_controller_template_rectangle, const char_T
   *c23_identifier)
{
  uint8_T c23_y;
  emlrtMsgIdentifier c23_thisId;
  c23_thisId.fIdentifier = c23_identifier;
  c23_thisId.fParent = NULL;
  c23_y = c23_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c23_is_active_c23_controller_template_rectangle), &c23_thisId);
  sf_mex_destroy(&c23_is_active_c23_controller_template_rectangle);
  return c23_y;
}

static uint8_T c23_e_emlrt_marshallIn
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c23_u, const emlrtMsgIdentifier *c23_parentId)
{
  uint8_T c23_y;
  uint8_T c23_u0;
  sf_mex_import(c23_parentId, sf_mex_dup(c23_u), &c23_u0, 1, 3, 0U, 0, 0U, 0);
  c23_y = c23_u0;
  sf_mex_destroy(&c23_u);
  return c23_y;
}

static void init_dsm_address_info
  (SFc23_controller_template_rectangleInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c23_controller_template_rectangle_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3567241213U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4093172190U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(70428522U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(907592534U);
}

mxArray *sf_c23_controller_template_rectangle_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("9DYUK24kJhabEDbdJagsJB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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

static const mxArray *sf_get_sim_state_info_c23_controller_template_rectangle
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c23_controller_template_rectangle\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c23_controller_template_rectangle_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc23_controller_template_rectangleInstanceStruct *chartInstance;
    chartInstance = (SFc23_controller_template_rectangleInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_template_rectangleMachineNumber_,
           23,
           1,
           1,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"thres");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,80);
        _SFD_CV_INIT_EML_IF(0,1,0,36,48,60,79);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)c23_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c23_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c23_u;
          real_T *c23_y;
          real_T *c23_thres;
          c23_thres = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c23_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c23_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c23_u);
          _SFD_SET_DATA_VALUE_PTR(1U, c23_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c23_thres);
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

static void sf_opaque_initialize_c23_controller_template_rectangle(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc23_controller_template_rectangleInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc23_controller_template_rectangleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c23_controller_template_rectangle
    ((SFc23_controller_template_rectangleInstanceStruct*) chartInstanceVar);
  initialize_c23_controller_template_rectangle
    ((SFc23_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c23_controller_template_rectangle(void
  *chartInstanceVar)
{
  enable_c23_controller_template_rectangle
    ((SFc23_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c23_controller_template_rectangle(void
  *chartInstanceVar)
{
  disable_c23_controller_template_rectangle
    ((SFc23_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c23_controller_template_rectangle(void
  *chartInstanceVar)
{
  sf_c23_controller_template_rectangle
    ((SFc23_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c23_controller_template_rectangle(void
  *chartInstanceVar)
{
  ext_mode_exec_c23_controller_template_rectangle
    ((SFc23_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c23_controller_template_rectangle(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c23_controller_template_rectangle
    ((SFc23_controller_template_rectangleInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_controller_template_rectangle();/* state var info */
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

extern void sf_internal_set_sim_state_c23_controller_template_rectangle
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c23_controller_template_rectangle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c23_controller_template_rectangle
    ((SFc23_controller_template_rectangleInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c23_controller_template_rectangle
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c23_controller_template_rectangle(S);
}

static void sf_opaque_set_sim_state_c23_controller_template_rectangle(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c23_controller_template_rectangle(S, st);
}

static void sf_opaque_terminate_c23_controller_template_rectangle(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc23_controller_template_rectangleInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c23_controller_template_rectangle
      ((SFc23_controller_template_rectangleInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_rectangle_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc23_controller_template_rectangle
    ((SFc23_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c23_controller_template_rectangle(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c23_controller_template_rectangle
      ((SFc23_controller_template_rectangleInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c23_controller_template_rectangle_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c23_controller_template_rectangle\",T\"is_active_c23_controller_template_rectangle\"}}"
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

static void mdlSetWorkWidths_c23_controller_template_rectangle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_rectangle_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,infoStruct,23,2);
      sf_mark_chart_reusable_outputs(S,infoStruct,23,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,23);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2381541654U));
  ssSetChecksum1(S,(1337048744U));
  ssSetChecksum2(S,(3896874838U));
  ssSetChecksum3(S,(1800367401U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c23_controller_template_rectangle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c23_controller_template_rectangle(SimStruct *S)
{
  SFc23_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc23_controller_template_rectangleInstanceStruct *)malloc
    (sizeof(SFc23_controller_template_rectangleInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc23_controller_template_rectangleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c23_controller_template_rectangle;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c23_controller_template_rectangle;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c23_controller_template_rectangle;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c23_controller_template_rectangle;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c23_controller_template_rectangle;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c23_controller_template_rectangle;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c23_controller_template_rectangle;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c23_controller_template_rectangle;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c23_controller_template_rectangle;
  chartInstance->chartInfo.mdlStart = mdlStart_c23_controller_template_rectangle;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c23_controller_template_rectangle;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c23_controller_template_rectangle;
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

void c23_controller_template_rectangle_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c23_controller_template_rectangle(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c23_controller_template_rectangle(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c23_controller_template_rectangle(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c23_controller_template_rectangle_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
