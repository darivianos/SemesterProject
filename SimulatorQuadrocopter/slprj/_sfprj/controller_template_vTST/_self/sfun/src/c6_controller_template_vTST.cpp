/* Include files */

#include "blascompat32.h"
#include "controller_template_vTST_sfun.h"
#include "c6_controller_template_vTST.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_vTST_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c6_debug_family_names[7] = { "nargin", "nargout", "x", "A",
  "B", "u", "y" };

/* Function Declarations */
static void initialize_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance);
static void initialize_params_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance);
static void enable_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance);
static void disable_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance);
static void ext_mode_exec_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance);
static void set_sim_state_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance, const mxArray
   *c6_st);
static void finalize_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance);
static void sf_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance);
static void initSimStructsc6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c6_y, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_controller_template_vTSTInstanceStruct *
  chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_c_emlrt_marshallIn(SFc6_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_d_emlrt_marshallIn(SFc6_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c6_is_active_c6_controller_template_vTST, const
  char_T *c6_identifier);
static uint8_T c6_e_emlrt_marshallIn(SFc6_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_controller_template_vTSTInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance)
{
  int32_T *c6_sfEvent;
  uint8_T *c6_is_active_c6_controller_template_vTST;
  c6_is_active_c6_controller_template_vTST = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c6_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c6_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c6_is_active_c6_controller_template_vTST = 0U;
}

static void initialize_params_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance)
{
}

static void enable_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c6_update_debugger_state_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance)
{
  c6_update_debugger_state_c6_controller_template_vTST(chartInstance);
}

static const mxArray *get_sim_state_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_u;
  const mxArray *c6_b_y = NULL;
  uint8_T c6_b_hoistedGlobal;
  uint8_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  real_T *c6_d_y;
  uint8_T *c6_is_active_c6_controller_template_vTST;
  c6_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_is_active_c6_controller_template_vTST = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellarray(2), FALSE);
  c6_hoistedGlobal = *c6_d_y;
  c6_u = c6_hoistedGlobal;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = *c6_is_active_c6_controller_template_vTST;
  c6_b_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  sf_mex_assign(&c6_st, c6_y, FALSE);
  return c6_st;
}

static void set_sim_state_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance, const mxArray
   *c6_st)
{
  const mxArray *c6_u;
  boolean_T *c6_doneDoubleBufferReInit;
  real_T *c6_y;
  uint8_T *c6_is_active_c6_controller_template_vTST;
  c6_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_is_active_c6_controller_template_vTST = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c6_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c6_doneDoubleBufferReInit = TRUE;
  c6_u = sf_mex_dup(c6_st);
  *c6_y = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 0)),
    "y");
  *c6_is_active_c6_controller_template_vTST = c6_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
     "is_active_c6_controller_template_vTST");
  sf_mex_destroy(&c6_u);
  c6_update_debugger_state_c6_controller_template_vTST(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance)
{
}

static void sf_c6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance)
{
  real_T c6_hoistedGlobal;
  real_T c6_b_hoistedGlobal;
  real_T c6_c_hoistedGlobal;
  real_T c6_d_hoistedGlobal;
  real_T c6_x;
  real_T c6_A;
  real_T c6_B;
  real_T c6_u;
  uint32_T c6_debug_family_var_map[7];
  real_T c6_nargin = 4.0;
  real_T c6_nargout = 1.0;
  real_T c6_y;
  real_T c6_a;
  real_T c6_b;
  real_T c6_b_y;
  real_T c6_b_a;
  real_T c6_b_b;
  real_T c6_c_y;
  int32_T *c6_sfEvent;
  real_T *c6_b_x;
  real_T *c6_d_y;
  real_T *c6_b_A;
  real_T *c6_b_B;
  real_T *c6_b_u;
  c6_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c6_b_B = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c6_b_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_d_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_b_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, *c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c6_b_x, 0U);
  _SFD_DATA_RANGE_CHECK(*c6_d_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c6_b_A, 2U);
  _SFD_DATA_RANGE_CHECK(*c6_b_B, 3U);
  _SFD_DATA_RANGE_CHECK(*c6_b_u, 4U);
  *c6_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, *c6_sfEvent);
  c6_hoistedGlobal = *c6_b_x;
  c6_b_hoistedGlobal = *c6_b_A;
  c6_c_hoistedGlobal = *c6_b_B;
  c6_d_hoistedGlobal = *c6_b_u;
  c6_x = c6_hoistedGlobal;
  c6_A = c6_b_hoistedGlobal;
  c6_B = c6_c_hoistedGlobal;
  c6_u = c6_d_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c6_debug_family_names,
    c6_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargin, 0U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c6_nargout, 1U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c6_x, 2U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_A, 3U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_B, 4U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c6_u, 5U, c6_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c6_y, 6U, c6_sf_marshallOut,
    c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c6_sfEvent, 4);
  c6_a = c6_A;
  c6_b = c6_x;
  c6_b_y = c6_a * c6_b;
  c6_b_a = c6_B;
  c6_b_b = c6_u;
  c6_c_y = c6_b_a * c6_b_b;
  c6_y = c6_b_y + c6_c_y;
  _SFD_EML_CALL(0U, *c6_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  *c6_d_y = c6_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *c6_sfEvent);
  sf_debug_check_for_state_inconsistency(_controller_template_vTSTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc6_controller_template_vTST
  (SFc6_controller_template_vTSTInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber)
{
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc6_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c6_y, const char_T *c6_identifier)
{
  real_T c6_b_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_y), &c6_thisId);
  sf_mex_destroy(&c6_y);
  return c6_b_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_controller_template_vTSTInstanceStruct *
  chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_y;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_b_y;
  SFc6_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc6_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c6_y = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_b_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_y), &c6_thisId);
  sf_mex_destroy(&c6_y);
  *(real_T *)c6_outData = c6_b_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_controller_template_vTST_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c6_nameCaptureInfo;
  c6_ResolvedFunctionInfo c6_info[1];
  c6_ResolvedFunctionInfo (*c6_b_info)[1];
  const mxArray *c6_m0 = NULL;
  int32_T c6_i0;
  c6_ResolvedFunctionInfo *c6_r0;
  c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  c6_b_info = (c6_ResolvedFunctionInfo (*)[1])c6_info;
  (*c6_b_info)[0].context = "";
  (*c6_b_info)[0].name = "mtimes";
  (*c6_b_info)[0].dominantType = "double";
  (*c6_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c6_b_info)[0].fileTimeLo = 1289519692U;
  (*c6_b_info)[0].fileTimeHi = 0U;
  (*c6_b_info)[0].mFileTimeLo = 0U;
  (*c6_b_info)[0].mFileTimeHi = 0U;
  sf_mex_assign(&c6_m0, sf_mex_createstruct("nameCaptureInfo", 1, 1), FALSE);
  for (c6_i0 = 0; c6_i0 < 1; c6_i0++) {
    c6_r0 = &c6_info[c6_i0];
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->context)), "context", "nameCaptureInfo",
                    c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c6_r0->name)), "name", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c6_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", c6_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c6_r0->resolved)), "resolved", "nameCaptureInfo",
                    c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c6_i0);
    sf_mex_addfield(c6_m0, sf_mex_create("nameCaptureInfo", &c6_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c6_i0);
  }

  sf_mex_assign(&c6_nameCaptureInfo, c6_m0, FALSE);
  return c6_nameCaptureInfo;
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc6_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, FALSE);
  return c6_mxArrayOutData;
}

static int32_T c6_c_emlrt_marshallIn(SFc6_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i1;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i1, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i1;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc6_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c6_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_sfEvent), &c6_thisId);
  sf_mex_destroy(&c6_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_d_emlrt_marshallIn(SFc6_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c6_is_active_c6_controller_template_vTST, const
  char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_is_active_c6_controller_template_vTST), &c6_thisId);
  sf_mex_destroy(&c6_is_active_c6_controller_template_vTST);
  return c6_y;
}

static uint8_T c6_e_emlrt_marshallIn(SFc6_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void init_dsm_address_info(SFc6_controller_template_vTSTInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c6_controller_template_vTST_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2953609234U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3584989020U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2135320975U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(23478909U);
}

mxArray *sf_c6_controller_template_vTST_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("jquNw6w9thZE5VLrT2J0PD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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

static const mxArray *sf_get_sim_state_info_c6_controller_template_vTST(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c6_controller_template_vTST\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_controller_template_vTST_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_controller_template_vTSTInstanceStruct *chartInstance;
    chartInstance = (SFc6_controller_template_vTSTInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_template_vTSTMachineNumber_,
           6,
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
          init_script_number_translation(_controller_template_vTSTMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_controller_template_vTSTMachineNumber_,chartInstance->chartNumber,
             1);
          sf_debug_set_chart_event_thresholds
            (_controller_template_vTSTMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"A");
          _SFD_SET_DATA_PROPS(3,1,1,0,"B");
          _SFD_SET_DATA_PROPS(4,1,1,0,"u");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,51);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c6_x;
          real_T *c6_y;
          real_T *c6_A;
          real_T *c6_B;
          real_T *c6_u;
          c6_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c6_B = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c6_A = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c6_y = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c6_x = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_x);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_A);
          _SFD_SET_DATA_VALUE_PTR(3U, c6_B);
          _SFD_SET_DATA_VALUE_PTR(4U, c6_u);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_controller_template_vTSTMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_controller_template_vTST_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S, infoStruct,
      6, "dworkChecksum");
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

static void sf_opaque_initialize_c6_controller_template_vTST(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc6_controller_template_vTSTInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc6_controller_template_vTSTInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_controller_template_vTST
    ((SFc6_controller_template_vTSTInstanceStruct*) chartInstanceVar);
  initialize_c6_controller_template_vTST
    ((SFc6_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_controller_template_vTST(void *chartInstanceVar)
{
  enable_c6_controller_template_vTST
    ((SFc6_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_controller_template_vTST(void *chartInstanceVar)
{
  disable_c6_controller_template_vTST
    ((SFc6_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_controller_template_vTST(void *chartInstanceVar)
{
  sf_c6_controller_template_vTST((SFc6_controller_template_vTSTInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c6_controller_template_vTST(void
  *chartInstanceVar)
{
  ext_mode_exec_c6_controller_template_vTST
    ((SFc6_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_controller_template_vTST
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_controller_template_vTST
    ((SFc6_controller_template_vTSTInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_controller_template_vTST();/* state var info */
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

extern void sf_internal_set_sim_state_c6_controller_template_vTST(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_controller_template_vTST();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_controller_template_vTST
    ((SFc6_controller_template_vTSTInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_controller_template_vTST
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c6_controller_template_vTST(S);
}

static void sf_opaque_set_sim_state_c6_controller_template_vTST(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c6_controller_template_vTST(S, st);
}

static void sf_opaque_terminate_c6_controller_template_vTST(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_controller_template_vTSTInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c6_controller_template_vTST
      ((SFc6_controller_template_vTSTInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_vTST_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_controller_template_vTST
    ((SFc6_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_controller_template_vTST(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_controller_template_vTST
      ((SFc6_controller_template_vTSTInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c6_controller_template_vTST_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c6_controller_template_vTST\",T\"is_active_c6_controller_template_vTST\"}}"
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

static void mdlSetWorkWidths_c6_controller_template_vTST(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_vTST_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,6,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,6,4);
      sf_mark_chart_reusable_outputs(S,infoStruct,6,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3353730042U));
  ssSetChecksum1(S,(3968082469U));
  ssSetChecksum2(S,(223667710U));
  ssSetChecksum3(S,(2789019709U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c6_controller_template_vTST(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_controller_template_vTST(SimStruct *S)
{
  SFc6_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc6_controller_template_vTSTInstanceStruct *)malloc(sizeof
    (SFc6_controller_template_vTSTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_controller_template_vTSTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_controller_template_vTST;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_controller_template_vTST;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_controller_template_vTST;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c6_controller_template_vTST;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c6_controller_template_vTST;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_controller_template_vTST;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_controller_template_vTST;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_controller_template_vTST;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_controller_template_vTST;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_controller_template_vTST;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_controller_template_vTST;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c6_controller_template_vTST;
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

void c6_controller_template_vTST_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_controller_template_vTST(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_controller_template_vTST(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_controller_template_vTST(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_controller_template_vTST_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
