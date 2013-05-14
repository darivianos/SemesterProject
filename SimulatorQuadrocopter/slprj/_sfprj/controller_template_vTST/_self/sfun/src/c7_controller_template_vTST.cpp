/* Include files */

#include "blascompat32.h"
#include "controller_template_vTST_sfun.h"
#include "c7_controller_template_vTST.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "controller_template_vTST_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c7_debug_family_names[7] = { "nargin", "nargout", "x", "A",
  "B", "u", "y" };

/* Function Declarations */
static void initialize_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance);
static void initialize_params_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance);
static void enable_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance);
static void disable_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance);
static void ext_mode_exec_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance);
static void set_sim_state_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance, const mxArray
   *c7_st);
static void finalize_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance);
static void sf_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance);
static void c7_chartstep_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance);
static void initSimStructsc7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static void c7_emlrt_marshallIn(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c7_y, const char_T *c7_identifier, real_T
  c7_b_y[4]);
static void c7_b_emlrt_marshallIn(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[4]);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_c_emlrt_marshallIn(SFc7_controller_template_vTSTInstanceStruct *
  chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_eml_scalar_eg(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance);
static void c7_b_eml_scalar_eg(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_d_emlrt_marshallIn(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_e_emlrt_marshallIn(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c7_is_active_c7_controller_template_vTST, const
  char_T *c7_identifier);
static uint8_T c7_f_emlrt_marshallIn(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance)
{
  int32_T *c7_sfEvent;
  uint8_T *c7_is_active_c7_controller_template_vTST;
  c7_is_active_c7_controller_template_vTST = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c7_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c7_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c7_is_active_c7_controller_template_vTST = 0U;
}

static void initialize_params_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance)
{
}

static void enable_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c7_update_debugger_state_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance)
{
  c7_update_debugger_state_c7_controller_template_vTST(chartInstance);
}

static const mxArray *get_sim_state_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  int32_T c7_i0;
  real_T c7_u[4];
  const mxArray *c7_b_y = NULL;
  uint8_T c7_hoistedGlobal;
  uint8_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  uint8_T *c7_is_active_c7_controller_template_vTST;
  real_T (*c7_d_y)[4];
  c7_d_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_is_active_c7_controller_template_vTST = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellarray(2), FALSE);
  for (c7_i0 = 0; c7_i0 < 4; c7_i0++) {
    c7_u[c7_i0] = (*c7_d_y)[c7_i0];
  }

  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_hoistedGlobal = *c7_is_active_c7_controller_template_vTST;
  c7_b_u = c7_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  sf_mex_assign(&c7_st, c7_y, FALSE);
  return c7_st;
}

static void set_sim_state_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance, const mxArray
   *c7_st)
{
  const mxArray *c7_u;
  real_T c7_dv0[4];
  int32_T c7_i1;
  boolean_T *c7_doneDoubleBufferReInit;
  uint8_T *c7_is_active_c7_controller_template_vTST;
  real_T (*c7_y)[4];
  c7_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_is_active_c7_controller_template_vTST = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c7_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c7_doneDoubleBufferReInit = TRUE;
  c7_u = sf_mex_dup(c7_st);
  c7_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 0)), "y",
                      c7_dv0);
  for (c7_i1 = 0; c7_i1 < 4; c7_i1++) {
    (*c7_y)[c7_i1] = c7_dv0[c7_i1];
  }

  *c7_is_active_c7_controller_template_vTST = c7_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 1)),
     "is_active_c7_controller_template_vTST");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_controller_template_vTST(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance)
{
}

static void sf_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance)
{
  int32_T c7_i2;
  int32_T c7_i3;
  int32_T c7_i4;
  int32_T c7_i5;
  int32_T *c7_sfEvent;
  real_T *c7_u;
  real_T (*c7_B)[8];
  real_T (*c7_A)[16];
  real_T (*c7_y)[4];
  real_T (*c7_x)[4];
  c7_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c7_B = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 2);
  c7_A = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 1);
  c7_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c7_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, *c7_sfEvent);
  for (c7_i2 = 0; c7_i2 < 4; c7_i2++) {
    _SFD_DATA_RANGE_CHECK((*c7_x)[c7_i2], 0U);
  }

  for (c7_i3 = 0; c7_i3 < 4; c7_i3++) {
    _SFD_DATA_RANGE_CHECK((*c7_y)[c7_i3], 1U);
  }

  for (c7_i4 = 0; c7_i4 < 16; c7_i4++) {
    _SFD_DATA_RANGE_CHECK((*c7_A)[c7_i4], 2U);
  }

  for (c7_i5 = 0; c7_i5 < 8; c7_i5++) {
    _SFD_DATA_RANGE_CHECK((*c7_B)[c7_i5], 3U);
  }

  _SFD_DATA_RANGE_CHECK(*c7_u, 4U);
  *c7_sfEvent = CALL_EVENT;
  c7_chartstep_c7_controller_template_vTST(chartInstance);
  sf_debug_check_for_state_inconsistency(_controller_template_vTSTMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c7_chartstep_c7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance)
{
  real_T c7_hoistedGlobal;
  int32_T c7_i6;
  real_T c7_x[4];
  int32_T c7_i7;
  real_T c7_A[16];
  int32_T c7_i8;
  real_T c7_B[8];
  real_T c7_u;
  uint32_T c7_debug_family_var_map[7];
  real_T c7_nargin = 4.0;
  real_T c7_nargout = 1.0;
  real_T c7_y[4];
  int32_T c7_i9;
  real_T c7_a[16];
  int32_T c7_i10;
  real_T c7_b[4];
  int32_T c7_i11;
  real_T c7_b_y[4];
  int32_T c7_i12;
  int32_T c7_i13;
  int32_T c7_i14;
  real_T c7_b_a[8];
  real_T c7_b_b[2];
  int32_T c7_i15;
  int32_T c7_i16;
  int32_T c7_i17;
  int32_T c7_i18;
  int32_T c7_i19;
  real_T *c7_b_u;
  real_T (*c7_c_y)[4];
  real_T (*c7_b_B)[8];
  real_T (*c7_b_A)[16];
  real_T (*c7_b_x)[4];
  int32_T *c7_sfEvent;
  c7_b_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c7_b_B = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 2);
  c7_b_A = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 1);
  c7_c_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
  c7_b_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
  c7_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, *c7_sfEvent);
  c7_hoistedGlobal = *c7_b_u;
  for (c7_i6 = 0; c7_i6 < 4; c7_i6++) {
    c7_x[c7_i6] = (*c7_b_x)[c7_i6];
  }

  for (c7_i7 = 0; c7_i7 < 16; c7_i7++) {
    c7_A[c7_i7] = (*c7_b_A)[c7_i7];
  }

  for (c7_i8 = 0; c7_i8 < 8; c7_i8++) {
    c7_B[c7_i8] = (*c7_b_B)[c7_i8];
  }

  c7_u = c7_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 7U, 7U, c7_debug_family_names,
    c7_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c7_x, 2U, c7_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c7_A, 3U, c7_d_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(c7_B, 4U, c7_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c7_u, 5U, c7_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c7_y, 6U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c7_sfEvent, 4);
  for (c7_i9 = 0; c7_i9 < 16; c7_i9++) {
    c7_a[c7_i9] = c7_A[c7_i9];
  }

  for (c7_i10 = 0; c7_i10 < 4; c7_i10++) {
    c7_b[c7_i10] = c7_x[c7_i10];
  }

  c7_eml_scalar_eg(chartInstance);
  c7_eml_scalar_eg(chartInstance);
  for (c7_i11 = 0; c7_i11 < 4; c7_i11++) {
    c7_b_y[c7_i11] = 0.0;
    c7_i12 = 0;
    for (c7_i13 = 0; c7_i13 < 4; c7_i13++) {
      c7_b_y[c7_i11] += c7_a[c7_i12 + c7_i11] * c7_b[c7_i13];
      c7_i12 += 4;
    }
  }

  for (c7_i14 = 0; c7_i14 < 8; c7_i14++) {
    c7_b_a[c7_i14] = c7_B[c7_i14];
  }

  c7_b_b[0] = c7_u;
  c7_b_b[1] = 0.0;
  c7_b_eml_scalar_eg(chartInstance);
  c7_b_eml_scalar_eg(chartInstance);
  for (c7_i15 = 0; c7_i15 < 4; c7_i15++) {
    c7_b[c7_i15] = 0.0;
    c7_i16 = 0;
    for (c7_i17 = 0; c7_i17 < 2; c7_i17++) {
      c7_b[c7_i15] += c7_b_a[c7_i16 + c7_i15] * c7_b_b[c7_i17];
      c7_i16 += 4;
    }
  }

  for (c7_i18 = 0; c7_i18 < 4; c7_i18++) {
    c7_y[c7_i18] = c7_b_y[c7_i18] + c7_b[c7_i18];
  }

  _SFD_EML_CALL(0U, *c7_sfEvent, -4);
  sf_debug_symbol_scope_pop();
  for (c7_i19 = 0; c7_i19 < 4; c7_i19++) {
    (*c7_c_y)[c7_i19] = c7_y[c7_i19];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *c7_sfEvent);
}

static void initSimStructsc7_controller_template_vTST
  (SFc7_controller_template_vTSTInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber)
{
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i20;
  real_T c7_b_inData[4];
  int32_T c7_i21;
  real_T c7_u[4];
  const mxArray *c7_y = NULL;
  SFc7_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc7_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  for (c7_i20 = 0; c7_i20 < 4; c7_i20++) {
    c7_b_inData[c7_i20] = (*(real_T (*)[4])c7_inData)[c7_i20];
  }

  for (c7_i21 = 0; c7_i21 < 4; c7_i21++) {
    c7_u[c7_i21] = c7_b_inData[c7_i21];
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static void c7_emlrt_marshallIn(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c7_y, const char_T *c7_identifier, real_T
  c7_b_y[4])
{
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_y), &c7_thisId, c7_b_y);
  sf_mex_destroy(&c7_y);
}

static void c7_b_emlrt_marshallIn(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  real_T c7_y[4])
{
  real_T c7_dv1[4];
  int32_T c7_i22;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), c7_dv1, 1, 0, 0U, 1, 0U, 1, 4);
  for (c7_i22 = 0; c7_i22 < 4; c7_i22++) {
    c7_y[c7_i22] = c7_dv1[c7_i22];
  }

  sf_mex_destroy(&c7_u);
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_y;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_b_y[4];
  int32_T c7_i23;
  SFc7_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc7_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c7_y = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_y), &c7_thisId, c7_b_y);
  sf_mex_destroy(&c7_y);
  for (c7_i23 = 0; c7_i23 < 4; c7_i23++) {
    (*(real_T (*)[4])c7_outData)[c7_i23] = c7_b_y[c7_i23];
  }

  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc7_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i24;
  int32_T c7_i25;
  int32_T c7_i26;
  real_T c7_b_inData[8];
  int32_T c7_i27;
  int32_T c7_i28;
  int32_T c7_i29;
  real_T c7_u[8];
  const mxArray *c7_y = NULL;
  SFc7_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc7_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_i24 = 0;
  for (c7_i25 = 0; c7_i25 < 2; c7_i25++) {
    for (c7_i26 = 0; c7_i26 < 4; c7_i26++) {
      c7_b_inData[c7_i26 + c7_i24] = (*(real_T (*)[8])c7_inData)[c7_i26 + c7_i24];
    }

    c7_i24 += 4;
  }

  c7_i27 = 0;
  for (c7_i28 = 0; c7_i28 < 2; c7_i28++) {
    for (c7_i29 = 0; c7_i29 < 4; c7_i29++) {
      c7_u[c7_i29 + c7_i27] = c7_b_inData[c7_i29 + c7_i27];
    }

    c7_i27 += 4;
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 4, 2), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_i30;
  int32_T c7_i31;
  int32_T c7_i32;
  real_T c7_b_inData[16];
  int32_T c7_i33;
  int32_T c7_i34;
  int32_T c7_i35;
  real_T c7_u[16];
  const mxArray *c7_y = NULL;
  SFc7_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc7_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_i30 = 0;
  for (c7_i31 = 0; c7_i31 < 4; c7_i31++) {
    for (c7_i32 = 0; c7_i32 < 4; c7_i32++) {
      c7_b_inData[c7_i32 + c7_i30] = (*(real_T (*)[16])c7_inData)[c7_i32 +
        c7_i30];
    }

    c7_i30 += 4;
  }

  c7_i33 = 0;
  for (c7_i34 = 0; c7_i34 < 4; c7_i34++) {
    for (c7_i35 = 0; c7_i35 < 4; c7_i35++) {
      c7_u[c7_i35 + c7_i33] = c7_b_inData[c7_i35 + c7_i33];
    }

    c7_i33 += 4;
  }

  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_u, 0, 0U, 1U, 0U, 2, 4, 4), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static real_T c7_c_emlrt_marshallIn(SFc7_controller_template_vTSTInstanceStruct *
  chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_nargout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc7_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c7_nargout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_controller_template_vTST_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c7_nameCaptureInfo;
  c7_ResolvedFunctionInfo c7_info[6];
  c7_ResolvedFunctionInfo (*c7_b_info)[6];
  const mxArray *c7_m0 = NULL;
  int32_T c7_i36;
  c7_ResolvedFunctionInfo *c7_r0;
  c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  c7_b_info = (c7_ResolvedFunctionInfo (*)[6])c7_info;
  (*c7_b_info)[0].context = "";
  (*c7_b_info)[0].name = "mtimes";
  (*c7_b_info)[0].dominantType = "double";
  (*c7_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c7_b_info)[0].fileTimeLo = 1289519692U;
  (*c7_b_info)[0].fileTimeHi = 0U;
  (*c7_b_info)[0].mFileTimeLo = 0U;
  (*c7_b_info)[0].mFileTimeHi = 0U;
  (*c7_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c7_b_info)[1].name = "eml_index_class";
  (*c7_b_info)[1].dominantType = "";
  (*c7_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c7_b_info)[1].fileTimeLo = 1286818778U;
  (*c7_b_info)[1].fileTimeHi = 0U;
  (*c7_b_info)[1].mFileTimeLo = 0U;
  (*c7_b_info)[1].mFileTimeHi = 0U;
  (*c7_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c7_b_info)[2].name = "eml_scalar_eg";
  (*c7_b_info)[2].dominantType = "double";
  (*c7_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c7_b_info)[2].fileTimeLo = 1286818796U;
  (*c7_b_info)[2].fileTimeHi = 0U;
  (*c7_b_info)[2].mFileTimeLo = 0U;
  (*c7_b_info)[2].mFileTimeHi = 0U;
  (*c7_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c7_b_info)[3].name = "eml_xgemm";
  (*c7_b_info)[3].dominantType = "int32";
  (*c7_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c7_b_info)[3].fileTimeLo = 1299076772U;
  (*c7_b_info)[3].fileTimeHi = 0U;
  (*c7_b_info)[3].mFileTimeLo = 0U;
  (*c7_b_info)[3].mFileTimeHi = 0U;
  (*c7_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m";
  (*c7_b_info)[4].name = "eml_blas_inline";
  (*c7_b_info)[4].dominantType = "";
  (*c7_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_blas_inline.m";
  (*c7_b_info)[4].fileTimeLo = 1299076768U;
  (*c7_b_info)[4].fileTimeHi = 0U;
  (*c7_b_info)[4].mFileTimeLo = 0U;
  (*c7_b_info)[4].mFileTimeHi = 0U;
  (*c7_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xgemm.m";
  (*c7_b_info)[5].name = "eml_refblas_xgemm";
  (*c7_b_info)[5].dominantType = "int32";
  (*c7_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xgemm.m";
  (*c7_b_info)[5].fileTimeLo = 1299076774U;
  (*c7_b_info)[5].fileTimeHi = 0U;
  (*c7_b_info)[5].mFileTimeLo = 0U;
  (*c7_b_info)[5].mFileTimeHi = 0U;
  sf_mex_assign(&c7_m0, sf_mex_createstruct("nameCaptureInfo", 1, 6), FALSE);
  for (c7_i36 = 0; c7_i36 < 6; c7_i36++) {
    c7_r0 = &c7_info[c7_i36];
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->context)), "context", "nameCaptureInfo",
                    c7_i36);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c7_r0->name)), "name", "nameCaptureInfo", c7_i36);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c7_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c7_i36);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", c7_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c7_r0->resolved)), "resolved", "nameCaptureInfo",
                    c7_i36);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c7_i36);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c7_i36);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c7_i36);
    sf_mex_addfield(c7_m0, sf_mex_create("nameCaptureInfo", &c7_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c7_i36);
  }

  sf_mex_assign(&c7_nameCaptureInfo, c7_m0, FALSE);
  return c7_nameCaptureInfo;
}

static void c7_eml_scalar_eg(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance)
{
}

static void c7_b_eml_scalar_eg(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance)
{
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc7_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, FALSE);
  return c7_mxArrayOutData;
}

static int32_T c7_d_emlrt_marshallIn(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i37;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i37, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i37;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc7_controller_template_vTSTInstanceStruct *)
    chartInstanceVoid;
  c7_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_sfEvent), &c7_thisId);
  sf_mex_destroy(&c7_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_e_emlrt_marshallIn(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c7_is_active_c7_controller_template_vTST, const
  char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_is_active_c7_controller_template_vTST), &c7_thisId);
  sf_mex_destroy(&c7_is_active_c7_controller_template_vTST);
  return c7_y;
}

static uint8_T c7_f_emlrt_marshallIn(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_controller_template_vTSTInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c7_controller_template_vTST_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4279029070U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4266240784U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1740308394U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1052919814U);
}

mxArray *sf_c7_controller_template_vTST_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("eMVt90xgq6gkBUb0K3cYZ");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
      pr[0] = (double)(4);
      pr[1] = (double)(4);
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
      pr[0] = (double)(4);
      pr[1] = (double)(2);
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
      pr[0] = (double)(4);
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

static const mxArray *sf_get_sim_state_info_c7_controller_template_vTST(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c7_controller_template_vTST\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_controller_template_vTST_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_controller_template_vTSTInstanceStruct *chartInstance;
    chartInstance = (SFc7_controller_template_vTSTInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_controller_template_vTSTMachineNumber_,
           7,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,55);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)
            c7_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 4;
          dimVector[1]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c7_u;
          real_T (*c7_x)[4];
          real_T (*c7_y)[4];
          real_T (*c7_A)[16];
          real_T (*c7_B)[8];
          c7_u = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c7_B = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 2);
          c7_A = (real_T (*)[16])ssGetInputPortSignal(chartInstance->S, 1);
          c7_y = (real_T (*)[4])ssGetOutputPortSignal(chartInstance->S, 1);
          c7_x = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c7_x);
          _SFD_SET_DATA_VALUE_PTR(1U, *c7_y);
          _SFD_SET_DATA_VALUE_PTR(2U, *c7_A);
          _SFD_SET_DATA_VALUE_PTR(3U, *c7_B);
          _SFD_SET_DATA_VALUE_PTR(4U, c7_u);
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
      7, "dworkChecksum");
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

static void sf_opaque_initialize_c7_controller_template_vTST(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc7_controller_template_vTSTInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc7_controller_template_vTSTInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_controller_template_vTST
    ((SFc7_controller_template_vTSTInstanceStruct*) chartInstanceVar);
  initialize_c7_controller_template_vTST
    ((SFc7_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_controller_template_vTST(void *chartInstanceVar)
{
  enable_c7_controller_template_vTST
    ((SFc7_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_controller_template_vTST(void *chartInstanceVar)
{
  disable_c7_controller_template_vTST
    ((SFc7_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c7_controller_template_vTST(void *chartInstanceVar)
{
  sf_c7_controller_template_vTST((SFc7_controller_template_vTSTInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c7_controller_template_vTST(void
  *chartInstanceVar)
{
  ext_mode_exec_c7_controller_template_vTST
    ((SFc7_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_controller_template_vTST
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_controller_template_vTST
    ((SFc7_controller_template_vTSTInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_controller_template_vTST();/* state var info */
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

extern void sf_internal_set_sim_state_c7_controller_template_vTST(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_controller_template_vTST();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_controller_template_vTST
    ((SFc7_controller_template_vTSTInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_controller_template_vTST
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c7_controller_template_vTST(S);
}

static void sf_opaque_set_sim_state_c7_controller_template_vTST(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c7_controller_template_vTST(S, st);
}

static void sf_opaque_terminate_c7_controller_template_vTST(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_controller_template_vTSTInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c7_controller_template_vTST
      ((SFc7_controller_template_vTSTInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_controller_template_vTST_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_controller_template_vTST
    ((SFc7_controller_template_vTSTInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_controller_template_vTST(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_controller_template_vTST
      ((SFc7_controller_template_vTSTInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c7_controller_template_vTST_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c7_controller_template_vTST\",T\"is_active_c7_controller_template_vTST\"}}"
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

static void mdlSetWorkWidths_c7_controller_template_vTST(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_controller_template_vTST_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,7,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,7,4);
      sf_mark_chart_reusable_outputs(S,infoStruct,7,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(95781195U));
  ssSetChecksum1(S,(4273225441U));
  ssSetChecksum2(S,(167425266U));
  ssSetChecksum3(S,(2390888004U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c7_controller_template_vTST(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_controller_template_vTST(SimStruct *S)
{
  SFc7_controller_template_vTSTInstanceStruct *chartInstance;
  chartInstance = (SFc7_controller_template_vTSTInstanceStruct *)malloc(sizeof
    (SFc7_controller_template_vTSTInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_controller_template_vTSTInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_controller_template_vTST;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_controller_template_vTST;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_controller_template_vTST;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c7_controller_template_vTST;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_controller_template_vTST;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_controller_template_vTST;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_controller_template_vTST;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_controller_template_vTST;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_controller_template_vTST;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_controller_template_vTST;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_controller_template_vTST;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c7_controller_template_vTST;
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

void c7_controller_template_vTST_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_controller_template_vTST(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_controller_template_vTST(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_controller_template_vTST(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_controller_template_vTST_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
