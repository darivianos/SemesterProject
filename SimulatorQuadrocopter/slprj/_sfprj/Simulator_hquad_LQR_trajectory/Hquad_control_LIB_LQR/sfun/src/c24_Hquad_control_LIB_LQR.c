/* Include files */

#include "blascompat32.h"
#include "Hquad_control_LIB_LQR_sfun.h"
#include "c24_Hquad_control_LIB_LQR.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hquad_control_LIB_LQR_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c24_debug_family_names[6] = { "nargin", "nargout", "traj_z",
  "idx", "z_ref", "z_dot_ref" };

/* Function Declarations */
static void initialize_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void initialize_params_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void enable_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void disable_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void c24_update_debugger_state_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void set_sim_state_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance, const mxArray
   *c24_st);
static void finalize_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void sf_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void initSimStructsc24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber);
static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_emlrt_marshallIn(SFc24_Hquad_control_LIB_LQRInstanceStruct
  *chartInstance, const mxArray *c24_z_dot_ref, const char_T *c24_identifier);
static real_T c24_b_emlrt_marshallIn(SFc24_Hquad_control_LIB_LQRInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static int32_T c24_c_emlrt_marshallIn(SFc24_Hquad_control_LIB_LQRInstanceStruct *
  chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static uint8_T c24_d_emlrt_marshallIn(SFc24_Hquad_control_LIB_LQRInstanceStruct *
  chartInstance, const mxArray *c24_b_is_active_c24_Hquad_control_LIB_LQR, const
  char_T *c24_identifier);
static uint8_T c24_e_emlrt_marshallIn(SFc24_Hquad_control_LIB_LQRInstanceStruct *
  chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void init_dsm_address_info(SFc24_Hquad_control_LIB_LQRInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
  chartInstance->c24_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c24_is_active_c24_Hquad_control_LIB_LQR = 0U;
}

static void initialize_params_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
}

static void enable_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c24_update_debugger_state_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
  const mxArray *c24_st;
  const mxArray *c24_y = NULL;
  real_T c24_hoistedGlobal;
  real_T c24_u;
  const mxArray *c24_b_y = NULL;
  real_T c24_b_hoistedGlobal;
  real_T c24_b_u;
  const mxArray *c24_c_y = NULL;
  uint8_T c24_c_hoistedGlobal;
  uint8_T c24_c_u;
  const mxArray *c24_d_y = NULL;
  real_T *c24_z_dot_ref;
  real_T *c24_z_ref;
  c24_z_dot_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c24_z_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c24_st = NULL;
  c24_st = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createcellarray(3), FALSE);
  c24_hoistedGlobal = *c24_z_dot_ref;
  c24_u = c24_hoistedGlobal;
  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c24_y, 0, c24_b_y);
  c24_b_hoistedGlobal = *c24_z_ref;
  c24_b_u = c24_b_hoistedGlobal;
  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", &c24_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c24_y, 1, c24_c_y);
  c24_c_hoistedGlobal = chartInstance->c24_is_active_c24_Hquad_control_LIB_LQR;
  c24_c_u = c24_c_hoistedGlobal;
  c24_d_y = NULL;
  sf_mex_assign(&c24_d_y, sf_mex_create("y", &c24_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c24_y, 2, c24_d_y);
  sf_mex_assign(&c24_st, c24_y, FALSE);
  return c24_st;
}

static void set_sim_state_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance, const mxArray
   *c24_st)
{
  const mxArray *c24_u;
  real_T *c24_z_dot_ref;
  real_T *c24_z_ref;
  c24_z_dot_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c24_z_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c24_doneDoubleBufferReInit = TRUE;
  c24_u = sf_mex_dup(c24_st);
  *c24_z_dot_ref = c24_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c24_u, 0)), "z_dot_ref");
  *c24_z_ref = c24_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c24_u, 1)), "z_ref");
  chartInstance->c24_is_active_c24_Hquad_control_LIB_LQR =
    c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 2)),
    "is_active_c24_Hquad_control_LIB_LQR");
  sf_mex_destroy(&c24_u);
  c24_update_debugger_state_c24_Hquad_control_LIB_LQR(chartInstance);
  sf_mex_destroy(&c24_st);
}

static void finalize_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
}

static void sf_c24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
  int32_T c24_i0;
  real_T c24_hoistedGlobal;
  int32_T c24_i1;
  real_T c24_traj_z[1864];
  real_T c24_idx;
  uint32_T c24_debug_family_var_map[6];
  real_T c24_nargin = 2.0;
  real_T c24_nargout = 2.0;
  real_T c24_z_ref;
  real_T c24_z_dot_ref;
  real_T *c24_b_z_ref;
  real_T *c24_b_idx;
  real_T *c24_b_z_dot_ref;
  real_T (*c24_b_traj_z)[1864];
  c24_b_z_dot_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c24_b_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c24_b_z_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c24_b_traj_z = (real_T (*)[1864])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c24_sfEvent);
  for (c24_i0 = 0; c24_i0 < 1864; c24_i0++) {
    _SFD_DATA_RANGE_CHECK((*c24_b_traj_z)[c24_i0], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*c24_b_z_ref, 1U);
  _SFD_DATA_RANGE_CHECK(*c24_b_idx, 2U);
  _SFD_DATA_RANGE_CHECK(*c24_b_z_dot_ref, 3U);
  chartInstance->c24_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c24_sfEvent);
  c24_hoistedGlobal = *c24_b_idx;
  for (c24_i1 = 0; c24_i1 < 1864; c24_i1++) {
    c24_traj_z[c24_i1] = (*c24_b_traj_z)[c24_i1];
  }

  c24_idx = c24_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c24_debug_family_names,
    c24_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c24_nargin, 0U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_nargout, 1U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c24_traj_z, 2U, c24_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c24_idx, 3U, c24_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c24_z_ref, 4U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_z_dot_ref, 5U,
    c24_sf_marshallOut, c24_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 3);
  c24_z_ref = c24_traj_z[(_SFD_EML_ARRAY_BOUNDS_CHECK("traj_z", (int32_T)
    _SFD_INTEGER_CHECK("idx", c24_idx), 1, 932, 2, 0) - 1) << 1];
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 4);
  c24_z_dot_ref = c24_traj_z[1 + ((_SFD_EML_ARRAY_BOUNDS_CHECK("traj_z",
    (int32_T)_SFD_INTEGER_CHECK("idx", c24_idx), 1, 932, 2, 0) - 1) << 1)];
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  *c24_b_z_ref = c24_z_ref;
  *c24_b_z_dot_ref = c24_z_dot_ref;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c24_sfEvent);
  sf_debug_check_for_state_inconsistency(_Hquad_control_LIB_LQRMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc24_Hquad_control_LIB_LQR
  (SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber)
{
}

static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_LQRInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static real_T c24_emlrt_marshallIn(SFc24_Hquad_control_LIB_LQRInstanceStruct
  *chartInstance, const mxArray *c24_z_dot_ref, const char_T *c24_identifier)
{
  real_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_z_dot_ref),
    &c24_thisId);
  sf_mex_destroy(&c24_z_dot_ref);
  return c24_y;
}

static real_T c24_b_emlrt_marshallIn(SFc24_Hquad_control_LIB_LQRInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d0;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d0, 1, 0, 0U, 0, 0U, 0);
  c24_y = c24_d0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_z_dot_ref;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_LQRInstanceStruct *)chartInstanceVoid;
  c24_z_dot_ref = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_z_dot_ref),
    &c24_thisId);
  sf_mex_destroy(&c24_z_dot_ref);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i2;
  int32_T c24_i3;
  int32_T c24_i4;
  real_T c24_b_inData[1864];
  int32_T c24_i5;
  int32_T c24_i6;
  int32_T c24_i7;
  real_T c24_u[1864];
  const mxArray *c24_y = NULL;
  SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_LQRInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_i2 = 0;
  for (c24_i3 = 0; c24_i3 < 932; c24_i3++) {
    for (c24_i4 = 0; c24_i4 < 2; c24_i4++) {
      c24_b_inData[c24_i4 + c24_i2] = (*(real_T (*)[1864])c24_inData)[c24_i4 +
        c24_i2];
    }

    c24_i2 += 2;
  }

  c24_i5 = 0;
  for (c24_i6 = 0; c24_i6 < 932; c24_i6++) {
    for (c24_i7 = 0; c24_i7 < 2; c24_i7++) {
      c24_u[c24_i7 + c24_i5] = c24_b_inData[c24_i7 + c24_i5];
    }

    c24_i5 += 2;
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 2, 932),
                FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

const mxArray *sf_c24_Hquad_control_LIB_LQR_get_eml_resolved_functions_info(void)
{
  const mxArray *c24_nameCaptureInfo = NULL;
  c24_nameCaptureInfo = NULL;
  sf_mex_assign(&c24_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c24_nameCaptureInfo;
}

static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_LQRInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(int32_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static int32_T c24_c_emlrt_marshallIn(SFc24_Hquad_control_LIB_LQRInstanceStruct *
  chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  int32_T c24_y;
  int32_T c24_i8;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_i8, 1, 6, 0U, 0, 0U, 0);
  c24_y = c24_i8;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_sfEvent;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  int32_T c24_y;
  SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_LQRInstanceStruct *)chartInstanceVoid;
  c24_b_sfEvent = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_sfEvent),
    &c24_thisId);
  sf_mex_destroy(&c24_b_sfEvent);
  *(int32_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static uint8_T c24_d_emlrt_marshallIn(SFc24_Hquad_control_LIB_LQRInstanceStruct *
  chartInstance, const mxArray *c24_b_is_active_c24_Hquad_control_LIB_LQR, const
  char_T *c24_identifier)
{
  uint8_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c24_b_is_active_c24_Hquad_control_LIB_LQR), &c24_thisId);
  sf_mex_destroy(&c24_b_is_active_c24_Hquad_control_LIB_LQR);
  return c24_y;
}

static uint8_T c24_e_emlrt_marshallIn(SFc24_Hquad_control_LIB_LQRInstanceStruct *
  chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  uint8_T c24_y;
  uint8_T c24_u0;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_u0, 1, 3, 0U, 0, 0U, 0);
  c24_y = c24_u0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void init_dsm_address_info(SFc24_Hquad_control_LIB_LQRInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c24_Hquad_control_LIB_LQR_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1266874071U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2587954640U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1292206646U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(803332062U);
}

mxArray *sf_c24_Hquad_control_LIB_LQR_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("0EnR6ROROtAZ3s4d6x8WbF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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

static const mxArray *sf_get_sim_state_info_c24_Hquad_control_LIB_LQR(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[27],T\"z_dot_ref\",},{M[1],M[18],T\"z_ref\",},{M[8],M[0],T\"is_active_c24_Hquad_control_LIB_LQR\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c24_Hquad_control_LIB_LQR_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
    chartInstance = (SFc24_Hquad_control_LIB_LQRInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Hquad_control_LIB_LQRMachineNumber_,
           24,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"traj_z");
          _SFD_SET_DATA_PROPS(1,2,0,1,"z_ref");
          _SFD_SET_DATA_PROPS(2,1,1,0,"idx");
          _SFD_SET_DATA_PROPS(3,2,0,1,"z_dot_ref");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,92);
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
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)c24_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)c24_sf_marshallIn);

        {
          real_T *c24_z_ref;
          real_T *c24_idx;
          real_T *c24_z_dot_ref;
          real_T (*c24_traj_z)[1864];
          c24_z_dot_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c24_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c24_z_ref = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c24_traj_z = (real_T (*)[1864])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c24_traj_z);
          _SFD_SET_DATA_VALUE_PTR(1U, c24_z_ref);
          _SFD_SET_DATA_VALUE_PTR(2U, c24_idx);
          _SFD_SET_DATA_VALUE_PTR(3U, c24_z_dot_ref);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Hquad_control_LIB_LQRMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c24_Hquad_control_LIB_LQR(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc24_Hquad_control_LIB_LQRInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c24_Hquad_control_LIB_LQR
    ((SFc24_Hquad_control_LIB_LQRInstanceStruct*) chartInstanceVar);
  initialize_c24_Hquad_control_LIB_LQR
    ((SFc24_Hquad_control_LIB_LQRInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c24_Hquad_control_LIB_LQR(void *chartInstanceVar)
{
  enable_c24_Hquad_control_LIB_LQR((SFc24_Hquad_control_LIB_LQRInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c24_Hquad_control_LIB_LQR(void *chartInstanceVar)
{
  disable_c24_Hquad_control_LIB_LQR((SFc24_Hquad_control_LIB_LQRInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c24_Hquad_control_LIB_LQR(void *chartInstanceVar)
{
  sf_c24_Hquad_control_LIB_LQR((SFc24_Hquad_control_LIB_LQRInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c24_Hquad_control_LIB_LQR
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c24_Hquad_control_LIB_LQR
    ((SFc24_Hquad_control_LIB_LQRInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c24_Hquad_control_LIB_LQR();/* state var info */
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

extern void sf_internal_set_sim_state_c24_Hquad_control_LIB_LQR(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c24_Hquad_control_LIB_LQR();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c24_Hquad_control_LIB_LQR
    ((SFc24_Hquad_control_LIB_LQRInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c24_Hquad_control_LIB_LQR
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c24_Hquad_control_LIB_LQR(S);
}

static void sf_opaque_set_sim_state_c24_Hquad_control_LIB_LQR(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c24_Hquad_control_LIB_LQR(S, st);
}

static void sf_opaque_terminate_c24_Hquad_control_LIB_LQR(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc24_Hquad_control_LIB_LQRInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c24_Hquad_control_LIB_LQR
      ((SFc24_Hquad_control_LIB_LQRInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Hquad_control_LIB_LQR_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc24_Hquad_control_LIB_LQR
    ((SFc24_Hquad_control_LIB_LQRInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c24_Hquad_control_LIB_LQR(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c24_Hquad_control_LIB_LQR
      ((SFc24_Hquad_control_LIB_LQRInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c24_Hquad_control_LIB_LQR(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_LQR_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,24);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,24,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,24,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,24,2);
      sf_mark_chart_reusable_outputs(S,infoStruct,24,2);
    }

    sf_set_rtw_dwork_info(S,infoStruct,24);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2497806593U));
  ssSetChecksum1(S,(3129619088U));
  ssSetChecksum2(S,(382981144U));
  ssSetChecksum3(S,(1141912149U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c24_Hquad_control_LIB_LQR(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c24_Hquad_control_LIB_LQR(SimStruct *S)
{
  SFc24_Hquad_control_LIB_LQRInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_LQRInstanceStruct *)malloc(sizeof
    (SFc24_Hquad_control_LIB_LQRInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc24_Hquad_control_LIB_LQRInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c24_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c24_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c24_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c24_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c24_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c24_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c24_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c24_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c24_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.mdlStart = mdlStart_c24_Hquad_control_LIB_LQR;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c24_Hquad_control_LIB_LQR;
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

void c24_Hquad_control_LIB_LQR_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c24_Hquad_control_LIB_LQR(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c24_Hquad_control_LIB_LQR(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c24_Hquad_control_LIB_LQR(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c24_Hquad_control_LIB_LQR_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
