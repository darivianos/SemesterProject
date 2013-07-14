/* Include files */

#include "blascompat32.h"
#include "controller_template_rectangle_sfun.h"
#include "c25_controller_template_rectangle.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_rectangle_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c25_debug_family_names[5] = { "nargin", "nargout",
  "psi_meas", "psi_prev", "psi_prime" };

/* Function Declarations */
static void initialize_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance);
static void initialize_params_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance);
static void enable_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance);
static void disable_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance);
static void c25_update_debugger_state_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance);
static void ext_mode_exec_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance);
static void set_sim_state_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c25_st);
static void finalize_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance);
static void sf_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance);
static void initSimStructsc25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber);
static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static real_T c25_emlrt_marshallIn
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c25_psi_prime, const char_T *c25_identifier);
static real_T c25_b_emlrt_marshallIn
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static int32_T c25_c_emlrt_marshallIn
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static uint8_T c25_d_emlrt_marshallIn
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c25_is_active_c25_controller_template_rectangle, const char_T
   *c25_identifier);
static uint8_T c25_e_emlrt_marshallIn
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId);
static void init_dsm_address_info
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance)
{
  int32_T *c25_sfEvent;
  uint8_T *c25_is_active_c25_controller_template_rectangle;
  c25_is_active_c25_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c25_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c25_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c25_is_active_c25_controller_template_rectangle = 0U;
}

static void initialize_params_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void enable_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c25_update_debugger_state_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance)
{
  c25_update_debugger_state_c25_controller_template_rectangle(chartInstance);
}

static const mxArray *get_sim_state_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance)
{
  const mxArray *c25_st;
  const mxArray *c25_y = NULL;
  real_T c25_hoistedGlobal;
  real_T c25_u;
  const mxArray *c25_b_y = NULL;
  uint8_T c25_b_hoistedGlobal;
  uint8_T c25_b_u;
  const mxArray *c25_c_y = NULL;
  real_T *c25_psi_prime;
  uint8_T *c25_is_active_c25_controller_template_rectangle;
  c25_psi_prime = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c25_is_active_c25_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c25_st = NULL;
  c25_st = NULL;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_createcellarray(2), FALSE);
  c25_hoistedGlobal = *c25_psi_prime;
  c25_u = c25_hoistedGlobal;
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c25_y, 0, c25_b_y);
  c25_b_hoistedGlobal = *c25_is_active_c25_controller_template_rectangle;
  c25_b_u = c25_b_hoistedGlobal;
  c25_c_y = NULL;
  sf_mex_assign(&c25_c_y, sf_mex_create("y", &c25_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c25_y, 1, c25_c_y);
  sf_mex_assign(&c25_st, c25_y, FALSE);
  return c25_st;
}

static void set_sim_state_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c25_st)
{
  const mxArray *c25_u;
  boolean_T *c25_doneDoubleBufferReInit;
  real_T *c25_psi_prime;
  uint8_T *c25_is_active_c25_controller_template_rectangle;
  c25_psi_prime = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c25_is_active_c25_controller_template_rectangle = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c25_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c25_doneDoubleBufferReInit = TRUE;
  c25_u = sf_mex_dup(c25_st);
  *c25_psi_prime = c25_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c25_u, 0)), "psi_prime");
  *c25_is_active_c25_controller_template_rectangle = c25_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c25_u, 1)),
     "is_active_c25_controller_template_rectangle");
  sf_mex_destroy(&c25_u);
  c25_update_debugger_state_c25_controller_template_rectangle(chartInstance);
  sf_mex_destroy(&c25_st);
}

static void finalize_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void sf_c25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance)
{
  real_T c25_hoistedGlobal;
  real_T c25_b_hoistedGlobal;
  real_T c25_psi_meas;
  real_T c25_psi_prev;
  uint32_T c25_debug_family_var_map[5];
  real_T c25_nargin = 2.0;
  real_T c25_nargout = 1.0;
  real_T c25_psi_prime;
  int32_T *c25_sfEvent;
  real_T *c25_b_psi_meas;
  real_T *c25_b_psi_prime;
  real_T *c25_b_psi_prev;
  c25_b_psi_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c25_b_psi_prime = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c25_b_psi_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c25_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 24U, *c25_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c25_b_psi_meas, 0U);
  _SFD_DATA_RANGE_CHECK(*c25_b_psi_prime, 1U);
  _SFD_DATA_RANGE_CHECK(*c25_b_psi_prev, 2U);
  *c25_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, *c25_sfEvent);
  c25_hoistedGlobal = *c25_b_psi_meas;
  c25_b_hoistedGlobal = *c25_b_psi_prev;
  c25_psi_meas = c25_hoistedGlobal;
  c25_psi_prev = c25_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c25_debug_family_names,
    c25_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c25_nargin, 0U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c25_nargout, 1U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c25_psi_meas, 2U, c25_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c25_psi_prev, 3U, c25_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c25_psi_prime, 4U,
    c25_sf_marshallOut, c25_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c25_sfEvent, 4);
  c25_psi_prime = c25_psi_meas;
  _SFD_EML_CALL(0U, *c25_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  *c25_b_psi_prime = c25_psi_prime;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, *c25_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_controller_template_rectangleMachineNumber_, chartInstance->chartNumber,
     chartInstance->instanceNumber);
}

static void initSimStructsc25_controller_template_rectangle
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber)
{
}

static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  real_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc25_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(real_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, FALSE);
  return c25_mxArrayOutData;
}

static real_T c25_emlrt_marshallIn
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c25_psi_prime, const char_T *c25_identifier)
{
  real_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_psi_prime),
    &c25_thisId);
  sf_mex_destroy(&c25_psi_prime);
  return c25_y;
}

static real_T c25_b_emlrt_marshallIn
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  real_T c25_y;
  real_T c25_d0;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_d0, 1, 0, 0U, 0, 0U, 0);
  c25_y = c25_d0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_psi_prime;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_y;
  SFc25_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc25_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c25_psi_prime = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_psi_prime),
    &c25_thisId);
  sf_mex_destroy(&c25_psi_prime);
  *(real_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

const mxArray
  *sf_c25_controller_template_rectangle_get_eml_resolved_functions_info(void)
{
  const mxArray *c25_nameCaptureInfo = NULL;
  c25_nameCaptureInfo = NULL;
  sf_mex_assign(&c25_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c25_nameCaptureInfo;
}

static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_u;
  const mxArray *c25_y = NULL;
  SFc25_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc25_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_u = *(int32_T *)c25_inData;
  c25_y = NULL;
  sf_mex_assign(&c25_y, sf_mex_create("y", &c25_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c25_mxArrayOutData, c25_y, FALSE);
  return c25_mxArrayOutData;
}

static int32_T c25_c_emlrt_marshallIn
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  int32_T c25_y;
  int32_T c25_i0;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_i0, 1, 6, 0U, 0, 0U, 0);
  c25_y = c25_i0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_sfEvent;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  int32_T c25_y;
  SFc25_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc25_controller_template_rectangleInstanceStruct *)
    chartInstanceVoid;
  c25_sfEvent = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_sfEvent),
    &c25_thisId);
  sf_mex_destroy(&c25_sfEvent);
  *(int32_T *)c25_outData = c25_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static uint8_T c25_d_emlrt_marshallIn
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c25_is_active_c25_controller_template_rectangle, const char_T
   *c25_identifier)
{
  uint8_T c25_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_y = c25_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c25_is_active_c25_controller_template_rectangle), &c25_thisId);
  sf_mex_destroy(&c25_is_active_c25_controller_template_rectangle);
  return c25_y;
}

static uint8_T c25_e_emlrt_marshallIn
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance, const
   mxArray *c25_u, const emlrtMsgIdentifier *c25_parentId)
{
  uint8_T c25_y;
  uint8_T c25_u0;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_u), &c25_u0, 1, 3, 0U, 0, 0U, 0);
  c25_y = c25_u0;
  sf_mex_destroy(&c25_u);
  return c25_y;
}

static void init_dsm_address_info
  (SFc25_controller_template_rectangleInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c25_controller_template_rectangle_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1371718091U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(618399521U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2692959029U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2869540579U);
}

mxArray *sf_c25_controller_template_rectangle_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("cFk05jf0QvimeNN6A052LC");
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

static const mxArray *sf_get_sim_state_info_c25_controller_template_rectangle
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"psi_prime\",},{M[8],M[0],T\"is_active_c25_controller_template_rectangle\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c25_controller_template_rectangle_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc25_controller_template_rectangleInstanceStruct *chartInstance;
    chartInstance = (SFc25_controller_template_rectangleInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_template_rectangleMachineNumber_,
           25,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"psi_meas");
          _SFD_SET_DATA_PROPS(1,2,0,1,"psi_prime");
          _SFD_SET_DATA_PROPS(2,1,1,0,"psi_prev");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,424);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)c25_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c25_psi_meas;
          real_T *c25_psi_prime;
          real_T *c25_psi_prev;
          c25_psi_prev = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c25_psi_prime = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c25_psi_meas = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c25_psi_meas);
          _SFD_SET_DATA_VALUE_PTR(1U, c25_psi_prime);
          _SFD_SET_DATA_VALUE_PTR(2U, c25_psi_prev);
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
      25, "dworkChecksum");
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

static void sf_opaque_initialize_c25_controller_template_rectangle(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc25_controller_template_rectangleInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc25_controller_template_rectangleInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c25_controller_template_rectangle
    ((SFc25_controller_template_rectangleInstanceStruct*) chartInstanceVar);
  initialize_c25_controller_template_rectangle
    ((SFc25_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c25_controller_template_rectangle(void
  *chartInstanceVar)
{
  enable_c25_controller_template_rectangle
    ((SFc25_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c25_controller_template_rectangle(void
  *chartInstanceVar)
{
  disable_c25_controller_template_rectangle
    ((SFc25_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c25_controller_template_rectangle(void
  *chartInstanceVar)
{
  sf_c25_controller_template_rectangle
    ((SFc25_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c25_controller_template_rectangle(void
  *chartInstanceVar)
{
  ext_mode_exec_c25_controller_template_rectangle
    ((SFc25_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c25_controller_template_rectangle(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c25_controller_template_rectangle
    ((SFc25_controller_template_rectangleInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c25_controller_template_rectangle();/* state var info */
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

extern void sf_internal_set_sim_state_c25_controller_template_rectangle
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c25_controller_template_rectangle();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c25_controller_template_rectangle
    ((SFc25_controller_template_rectangleInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c25_controller_template_rectangle
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c25_controller_template_rectangle(S);
}

static void sf_opaque_set_sim_state_c25_controller_template_rectangle(SimStruct*
  S, const mxArray *st)
{
  sf_internal_set_sim_state_c25_controller_template_rectangle(S, st);
}

static void sf_opaque_terminate_c25_controller_template_rectangle(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc25_controller_template_rectangleInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c25_controller_template_rectangle
      ((SFc25_controller_template_rectangleInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_rectangle_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc25_controller_template_rectangle
    ((SFc25_controller_template_rectangleInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c25_controller_template_rectangle(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c25_controller_template_rectangle
      ((SFc25_controller_template_rectangleInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c25_controller_template_rectangle_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c25_controller_template_rectangle\",T\"is_active_c25_controller_template_rectangle\"}}"
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

static void mdlSetWorkWidths_c25_controller_template_rectangle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_rectangle_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,25);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,25,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,25,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,25,2);
      sf_mark_chart_reusable_outputs(S,infoStruct,25,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,25);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(394762575U));
  ssSetChecksum1(S,(75564013U));
  ssSetChecksum2(S,(1417648961U));
  ssSetChecksum3(S,(2814736499U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c25_controller_template_rectangle(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c25_controller_template_rectangle(SimStruct *S)
{
  SFc25_controller_template_rectangleInstanceStruct *chartInstance;
  chartInstance = (SFc25_controller_template_rectangleInstanceStruct *)malloc
    (sizeof(SFc25_controller_template_rectangleInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc25_controller_template_rectangleInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c25_controller_template_rectangle;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c25_controller_template_rectangle;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c25_controller_template_rectangle;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c25_controller_template_rectangle;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c25_controller_template_rectangle;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c25_controller_template_rectangle;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c25_controller_template_rectangle;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c25_controller_template_rectangle;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c25_controller_template_rectangle;
  chartInstance->chartInfo.mdlStart = mdlStart_c25_controller_template_rectangle;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c25_controller_template_rectangle;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c25_controller_template_rectangle;
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

void c25_controller_template_rectangle_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c25_controller_template_rectangle(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c25_controller_template_rectangle(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c25_controller_template_rectangle(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c25_controller_template_rectangle_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
