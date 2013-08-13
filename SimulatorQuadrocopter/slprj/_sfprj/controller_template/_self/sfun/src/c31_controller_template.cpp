/* Include files */

#include "blascompat32.h"
#include "controller_template_sfun.h"
#include "c31_controller_template.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c31_debug_family_names[6] = { "pred_horizon_x", "nargin",
  "nargout", "traj_x", "idx", "X_ref_x" };

/* Function Declarations */
static void initialize_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance);
static void initialize_params_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance);
static void enable_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance);
static void disable_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance);
static void c31_update_debugger_state_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance);
static void ext_mode_exec_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance);
static void set_sim_state_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance, const mxArray *c31_st);
static void finalize_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance);
static void sf_c31_controller_template(SFc31_controller_templateInstanceStruct
  *chartInstance);
static void initSimStructsc31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber);
static const mxArray *c31_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static void c31_emlrt_marshallIn(SFc31_controller_templateInstanceStruct
  *chartInstance, const mxArray *c31_X_ref_x, const char_T *c31_identifier,
  real_T c31_y[93]);
static void c31_b_emlrt_marshallIn(SFc31_controller_templateInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId,
  real_T c31_y[93]);
static void c31_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_b_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static const mxArray *c31_c_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static real_T c31_c_emlrt_marshallIn(SFc31_controller_templateInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static const mxArray *c31_d_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData);
static int32_T c31_d_emlrt_marshallIn(SFc31_controller_templateInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void c31_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData);
static uint8_T c31_e_emlrt_marshallIn(SFc31_controller_templateInstanceStruct
  *chartInstance, const mxArray *c31_is_active_c31_controller_template, const
  char_T *c31_identifier);
static uint8_T c31_f_emlrt_marshallIn(SFc31_controller_templateInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId);
static void init_dsm_address_info(SFc31_controller_templateInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance)
{
  int32_T *c31_sfEvent;
  uint8_T *c31_is_active_c31_controller_template;
  c31_is_active_c31_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c31_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c31_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c31_is_active_c31_controller_template = 0U;
}

static void initialize_params_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance)
{
}

static void enable_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c31_update_debugger_state_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance)
{
  c31_update_debugger_state_c31_controller_template(chartInstance);
}

static const mxArray *get_sim_state_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance)
{
  const mxArray *c31_st;
  const mxArray *c31_y = NULL;
  int32_T c31_i0;
  real_T c31_u[93];
  const mxArray *c31_b_y = NULL;
  uint8_T c31_hoistedGlobal;
  uint8_T c31_b_u;
  const mxArray *c31_c_y = NULL;
  uint8_T *c31_is_active_c31_controller_template;
  real_T (*c31_X_ref_x)[93];
  c31_X_ref_x = (real_T (*)[93])ssGetOutputPortSignal(chartInstance->S, 1);
  c31_is_active_c31_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c31_st = NULL;
  c31_st = NULL;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_createcellarray(2), FALSE);
  for (c31_i0 = 0; c31_i0 < 93; c31_i0++) {
    c31_u[c31_i0] = (*c31_X_ref_x)[c31_i0];
  }

  c31_b_y = NULL;
  sf_mex_assign(&c31_b_y, sf_mex_create("y", c31_u, 0, 0U, 1U, 0U, 2, 3, 31),
                FALSE);
  sf_mex_setcell(c31_y, 0, c31_b_y);
  c31_hoistedGlobal = *c31_is_active_c31_controller_template;
  c31_b_u = c31_hoistedGlobal;
  c31_c_y = NULL;
  sf_mex_assign(&c31_c_y, sf_mex_create("y", &c31_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c31_y, 1, c31_c_y);
  sf_mex_assign(&c31_st, c31_y, FALSE);
  return c31_st;
}

static void set_sim_state_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance, const mxArray *c31_st)
{
  const mxArray *c31_u;
  real_T c31_dv0[93];
  int32_T c31_i1;
  boolean_T *c31_doneDoubleBufferReInit;
  uint8_T *c31_is_active_c31_controller_template;
  real_T (*c31_X_ref_x)[93];
  c31_X_ref_x = (real_T (*)[93])ssGetOutputPortSignal(chartInstance->S, 1);
  c31_is_active_c31_controller_template = (uint8_T *)ssGetDWork(chartInstance->S,
    3);
  c31_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c31_doneDoubleBufferReInit = TRUE;
  c31_u = sf_mex_dup(c31_st);
  c31_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c31_u, 0)),
                       "X_ref_x", c31_dv0);
  for (c31_i1 = 0; c31_i1 < 93; c31_i1++) {
    (*c31_X_ref_x)[c31_i1] = c31_dv0[c31_i1];
  }

  *c31_is_active_c31_controller_template = c31_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c31_u, 1)), "is_active_c31_controller_template");
  sf_mex_destroy(&c31_u);
  c31_update_debugger_state_c31_controller_template(chartInstance);
  sf_mex_destroy(&c31_st);
}

static void finalize_c31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance)
{
}

static void sf_c31_controller_template(SFc31_controller_templateInstanceStruct
  *chartInstance)
{
  int32_T c31_i2;
  int32_T c31_i3;
  real_T c31_hoistedGlobal;
  int32_T c31_i4;
  real_T c31_traj_x[1209];
  real_T c31_idx;
  uint32_T c31_debug_family_var_map[6];
  real_T c31_pred_horizon_x;
  real_T c31_nargin = 2.0;
  real_T c31_nargout = 1.0;
  real_T c31_X_ref_x[93];
  int32_T c31_i5;
  int32_T c31_i6;
  int32_T c31_i7;
  int32_T *c31_sfEvent;
  real_T *c31_b_idx;
  real_T (*c31_b_X_ref_x)[93];
  real_T (*c31_b_traj_x)[1209];
  c31_b_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c31_b_X_ref_x = (real_T (*)[93])ssGetOutputPortSignal(chartInstance->S, 1);
  c31_b_traj_x = (real_T (*)[1209])ssGetInputPortSignal(chartInstance->S, 0);
  c31_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 30U, *c31_sfEvent);
  for (c31_i2 = 0; c31_i2 < 1209; c31_i2++) {
    _SFD_DATA_RANGE_CHECK((*c31_b_traj_x)[c31_i2], 0U);
  }

  for (c31_i3 = 0; c31_i3 < 93; c31_i3++) {
    _SFD_DATA_RANGE_CHECK((*c31_b_X_ref_x)[c31_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c31_b_idx, 2U);
  *c31_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 30U, *c31_sfEvent);
  c31_hoistedGlobal = *c31_b_idx;
  for (c31_i4 = 0; c31_i4 < 1209; c31_i4++) {
    c31_traj_x[c31_i4] = (*c31_b_traj_x)[c31_i4];
  }

  c31_idx = c31_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c31_debug_family_names,
    c31_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c31_pred_horizon_x, 0U, c31_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c31_nargin, 1U, c31_b_sf_marshallOut,
    c31_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c31_nargout, 2U,
    c31_b_sf_marshallOut, c31_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c31_traj_x, 3U, c31_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c31_idx, 4U, c31_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c31_X_ref_x, 5U, c31_sf_marshallOut,
    c31_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c31_sfEvent, 3);
  c31_pred_horizon_x = 30.0;
  _SFD_EML_CALL(0U, *c31_sfEvent, 5);
  for (c31_i5 = 0; c31_i5 < 31; c31_i5++) {
    for (c31_i6 = 0; c31_i6 < 3; c31_i6++) {
      c31_X_ref_x[c31_i6 + 3 * c31_i5] = c31_traj_x[c31_i6 + 3 *
        (_SFD_EML_ARRAY_BOUNDS_CHECK("traj_x", (int32_T)_SFD_INTEGER_CHECK(
           "idx:idx+pred_horizon_x", c31_idx + (real_T)c31_i5), 1, 403, 2, 0) -
         1)];
    }
  }

  _SFD_EML_CALL(0U, *c31_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  for (c31_i7 = 0; c31_i7 < 93; c31_i7++) {
    (*c31_b_X_ref_x)[c31_i7] = c31_X_ref_x[c31_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 30U, *c31_sfEvent);
  sf_debug_check_for_state_inconsistency(_controller_templateMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc31_controller_template
  (SFc31_controller_templateInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c31_machineNumber, uint32_T
  c31_chartNumber)
{
}

static const mxArray *c31_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_i8;
  int32_T c31_i9;
  int32_T c31_i10;
  real_T c31_b_inData[93];
  int32_T c31_i11;
  int32_T c31_i12;
  int32_T c31_i13;
  real_T c31_u[93];
  const mxArray *c31_y = NULL;
  SFc31_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc31_controller_templateInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_i8 = 0;
  for (c31_i9 = 0; c31_i9 < 31; c31_i9++) {
    for (c31_i10 = 0; c31_i10 < 3; c31_i10++) {
      c31_b_inData[c31_i10 + c31_i8] = (*(real_T (*)[93])c31_inData)[c31_i10 +
        c31_i8];
    }

    c31_i8 += 3;
  }

  c31_i11 = 0;
  for (c31_i12 = 0; c31_i12 < 31; c31_i12++) {
    for (c31_i13 = 0; c31_i13 < 3; c31_i13++) {
      c31_u[c31_i13 + c31_i11] = c31_b_inData[c31_i13 + c31_i11];
    }

    c31_i11 += 3;
  }

  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 0, 0U, 1U, 0U, 2, 3, 31),
                FALSE);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, FALSE);
  return c31_mxArrayOutData;
}

static void c31_emlrt_marshallIn(SFc31_controller_templateInstanceStruct
  *chartInstance, const mxArray *c31_X_ref_x, const char_T *c31_identifier,
  real_T c31_y[93])
{
  emlrtMsgIdentifier c31_thisId;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_X_ref_x), &c31_thisId,
    c31_y);
  sf_mex_destroy(&c31_X_ref_x);
}

static void c31_b_emlrt_marshallIn(SFc31_controller_templateInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId,
  real_T c31_y[93])
{
  real_T c31_dv1[93];
  int32_T c31_i14;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), c31_dv1, 1, 0, 0U, 1, 0U, 2, 3,
                31);
  for (c31_i14 = 0; c31_i14 < 93; c31_i14++) {
    c31_y[c31_i14] = c31_dv1[c31_i14];
  }

  sf_mex_destroy(&c31_u);
}

static void c31_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_X_ref_x;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  real_T c31_y[93];
  int32_T c31_i15;
  int32_T c31_i16;
  int32_T c31_i17;
  SFc31_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc31_controller_templateInstanceStruct *)chartInstanceVoid;
  c31_X_ref_x = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_X_ref_x), &c31_thisId,
    c31_y);
  sf_mex_destroy(&c31_X_ref_x);
  c31_i15 = 0;
  for (c31_i16 = 0; c31_i16 < 31; c31_i16++) {
    for (c31_i17 = 0; c31_i17 < 3; c31_i17++) {
      (*(real_T (*)[93])c31_outData)[c31_i17 + c31_i15] = c31_y[c31_i17 +
        c31_i15];
    }

    c31_i15 += 3;
  }

  sf_mex_destroy(&c31_mxArrayInData);
}

static const mxArray *c31_b_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  real_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc31_controller_templateInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(real_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, FALSE);
  return c31_mxArrayOutData;
}

static const mxArray *c31_c_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_i18;
  int32_T c31_i19;
  int32_T c31_i20;
  real_T c31_b_inData[1209];
  int32_T c31_i21;
  int32_T c31_i22;
  int32_T c31_i23;
  real_T c31_u[1209];
  const mxArray *c31_y = NULL;
  SFc31_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc31_controller_templateInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_i18 = 0;
  for (c31_i19 = 0; c31_i19 < 403; c31_i19++) {
    for (c31_i20 = 0; c31_i20 < 3; c31_i20++) {
      c31_b_inData[c31_i20 + c31_i18] = (*(real_T (*)[1209])c31_inData)[c31_i20
        + c31_i18];
    }

    c31_i18 += 3;
  }

  c31_i21 = 0;
  for (c31_i22 = 0; c31_i22 < 403; c31_i22++) {
    for (c31_i23 = 0; c31_i23 < 3; c31_i23++) {
      c31_u[c31_i23 + c31_i21] = c31_b_inData[c31_i23 + c31_i21];
    }

    c31_i21 += 3;
  }

  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", c31_u, 0, 0U, 1U, 0U, 2, 3, 403),
                FALSE);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, FALSE);
  return c31_mxArrayOutData;
}

static real_T c31_c_emlrt_marshallIn(SFc31_controller_templateInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  real_T c31_y;
  real_T c31_d0;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_d0, 1, 0, 0U, 0, 0U, 0);
  c31_y = c31_d0;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_nargout;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  real_T c31_y;
  SFc31_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc31_controller_templateInstanceStruct *)chartInstanceVoid;
  c31_nargout = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_nargout),
    &c31_thisId);
  sf_mex_destroy(&c31_nargout);
  *(real_T *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

const mxArray *sf_c31_controller_template_get_eml_resolved_functions_info(void)
{
  const mxArray *c31_nameCaptureInfo = NULL;
  c31_nameCaptureInfo = NULL;
  sf_mex_assign(&c31_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c31_nameCaptureInfo;
}

static const mxArray *c31_d_sf_marshallOut(void *chartInstanceVoid, void
  *c31_inData)
{
  const mxArray *c31_mxArrayOutData = NULL;
  int32_T c31_u;
  const mxArray *c31_y = NULL;
  SFc31_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc31_controller_templateInstanceStruct *)chartInstanceVoid;
  c31_mxArrayOutData = NULL;
  c31_u = *(int32_T *)c31_inData;
  c31_y = NULL;
  sf_mex_assign(&c31_y, sf_mex_create("y", &c31_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c31_mxArrayOutData, c31_y, FALSE);
  return c31_mxArrayOutData;
}

static int32_T c31_d_emlrt_marshallIn(SFc31_controller_templateInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  int32_T c31_y;
  int32_T c31_i24;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_i24, 1, 6, 0U, 0, 0U, 0);
  c31_y = c31_i24;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void c31_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c31_mxArrayInData, const char_T *c31_varName, void *c31_outData)
{
  const mxArray *c31_sfEvent;
  const char_T *c31_identifier;
  emlrtMsgIdentifier c31_thisId;
  int32_T c31_y;
  SFc31_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc31_controller_templateInstanceStruct *)chartInstanceVoid;
  c31_sfEvent = sf_mex_dup(c31_mxArrayInData);
  c31_identifier = c31_varName;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c31_sfEvent),
    &c31_thisId);
  sf_mex_destroy(&c31_sfEvent);
  *(int32_T *)c31_outData = c31_y;
  sf_mex_destroy(&c31_mxArrayInData);
}

static uint8_T c31_e_emlrt_marshallIn(SFc31_controller_templateInstanceStruct
  *chartInstance, const mxArray *c31_is_active_c31_controller_template, const
  char_T *c31_identifier)
{
  uint8_T c31_y;
  emlrtMsgIdentifier c31_thisId;
  c31_thisId.fIdentifier = c31_identifier;
  c31_thisId.fParent = NULL;
  c31_y = c31_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c31_is_active_c31_controller_template), &c31_thisId);
  sf_mex_destroy(&c31_is_active_c31_controller_template);
  return c31_y;
}

static uint8_T c31_f_emlrt_marshallIn(SFc31_controller_templateInstanceStruct
  *chartInstance, const mxArray *c31_u, const emlrtMsgIdentifier *c31_parentId)
{
  uint8_T c31_y;
  uint8_T c31_u0;
  sf_mex_import(c31_parentId, sf_mex_dup(c31_u), &c31_u0, 1, 3, 0U, 0, 0U, 0);
  c31_y = c31_u0;
  sf_mex_destroy(&c31_u);
  return c31_y;
}

static void init_dsm_address_info(SFc31_controller_templateInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c31_controller_template_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3348111212U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2078451608U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1568847890U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3542751543U);
}

mxArray *sf_c31_controller_template_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("oXK1HGmNkuSlUnw1jeaNsG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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

static const mxArray *sf_get_sim_state_info_c31_controller_template(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[18],T\"X_ref_x\",},{M[8],M[0],T\"is_active_c31_controller_template\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c31_controller_template_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc31_controller_templateInstanceStruct *chartInstance;
    chartInstance = (SFc31_controller_templateInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_templateMachineNumber_,
           31,
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
          init_script_number_translation(_controller_templateMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_controller_templateMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_controller_templateMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"traj_x");
          _SFD_SET_DATA_PROPS(1,2,0,1,"X_ref_x");
          _SFD_SET_DATA_PROPS(2,1,1,0,"idx");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,98);
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
          dimVector[0]= 3;
          dimVector[1]= 403;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c31_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 31;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c31_sf_marshallOut,(MexInFcnForType)
            c31_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c31_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c31_idx;
          real_T (*c31_traj_x)[1209];
          real_T (*c31_X_ref_x)[93];
          c31_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c31_X_ref_x = (real_T (*)[93])ssGetOutputPortSignal(chartInstance->S,
            1);
          c31_traj_x = (real_T (*)[1209])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c31_traj_x);
          _SFD_SET_DATA_VALUE_PTR(1U, *c31_X_ref_x);
          _SFD_SET_DATA_VALUE_PTR(2U, c31_idx);
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
      31, "dworkChecksum");
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

static void sf_opaque_initialize_c31_controller_template(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc31_controller_templateInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc31_controller_templateInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c31_controller_template
    ((SFc31_controller_templateInstanceStruct*) chartInstanceVar);
  initialize_c31_controller_template((SFc31_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c31_controller_template(void *chartInstanceVar)
{
  enable_c31_controller_template((SFc31_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c31_controller_template(void *chartInstanceVar)
{
  disable_c31_controller_template((SFc31_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c31_controller_template(void *chartInstanceVar)
{
  sf_c31_controller_template((SFc31_controller_templateInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c31_controller_template(void
  *chartInstanceVar)
{
  ext_mode_exec_c31_controller_template((SFc31_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c31_controller_template
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c31_controller_template
    ((SFc31_controller_templateInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c31_controller_template();/* state var info */
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

extern void sf_internal_set_sim_state_c31_controller_template(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c31_controller_template();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c31_controller_template((SFc31_controller_templateInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c31_controller_template(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c31_controller_template(S);
}

static void sf_opaque_set_sim_state_c31_controller_template(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c31_controller_template(S, st);
}

static void sf_opaque_terminate_c31_controller_template(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc31_controller_templateInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c31_controller_template((SFc31_controller_templateInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc31_controller_template((SFc31_controller_templateInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c31_controller_template(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c31_controller_template
      ((SFc31_controller_templateInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c31_controller_template_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c31_controller_template\",T\"is_active_c31_controller_template\"}}"
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

static void mdlSetWorkWidths_c31_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,31);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,31,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,31,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,31,2);
      sf_mark_chart_reusable_outputs(S,infoStruct,31,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,31);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3917434842U));
  ssSetChecksum1(S,(1750472342U));
  ssSetChecksum2(S,(1700506410U));
  ssSetChecksum3(S,(3247890866U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c31_controller_template(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c31_controller_template(SimStruct *S)
{
  SFc31_controller_templateInstanceStruct *chartInstance;
  chartInstance = (SFc31_controller_templateInstanceStruct *)malloc(sizeof
    (SFc31_controller_templateInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc31_controller_templateInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c31_controller_template;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c31_controller_template;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c31_controller_template;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c31_controller_template;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c31_controller_template;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c31_controller_template;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c31_controller_template;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c31_controller_template;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c31_controller_template;
  chartInstance->chartInfo.mdlStart = mdlStart_c31_controller_template;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c31_controller_template;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c31_controller_template;
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

void c31_controller_template_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c31_controller_template(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c31_controller_template(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c31_controller_template(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c31_controller_template_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
