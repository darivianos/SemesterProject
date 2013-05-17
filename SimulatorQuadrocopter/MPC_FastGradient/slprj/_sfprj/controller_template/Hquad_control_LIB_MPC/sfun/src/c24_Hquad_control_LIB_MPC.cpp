/* Include files */

#include "blascompat32.h"
#include "Hquad_control_LIB_MPC_sfun.h"
#include "c24_Hquad_control_LIB_MPC.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Hquad_control_LIB_MPC_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c24_debug_family_names[6] = { "pred_horizon_z", "nargin",
  "nargout", "traj_z", "idx", "X_ref_z" };

/* Function Declarations */
static void initialize_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initialize_params_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void enable_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void disable_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void c24_update_debugger_state_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void ext_mode_exec_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void set_sim_state_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray
   *c24_st);
static void finalize_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void sf_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void initSimStructsc24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber);
static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_emlrt_marshallIn(SFc24_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c24_X_ref_z, const char_T *c24_identifier,
  real_T c24_y[62]);
static void c24_b_emlrt_marshallIn(SFc24_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[62]);
static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_c_emlrt_marshallIn(SFc24_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static int32_T c24_d_emlrt_marshallIn(SFc24_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static uint8_T c24_e_emlrt_marshallIn(SFc24_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c24_is_active_c24_Hquad_control_LIB_MPC, const
  char_T *c24_identifier);
static uint8_T c24_f_emlrt_marshallIn(SFc24_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void init_dsm_address_info(SFc24_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T *c24_sfEvent;
  uint8_T *c24_is_active_c24_Hquad_control_LIB_MPC;
  c24_is_active_c24_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c24_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  *c24_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c24_is_active_c24_Hquad_control_LIB_MPC = 0U;
}

static void initialize_params_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void enable_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c24_update_debugger_state_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void ext_mode_exec_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  c24_update_debugger_state_c24_Hquad_control_LIB_MPC(chartInstance);
}

static const mxArray *get_sim_state_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  const mxArray *c24_st;
  const mxArray *c24_y = NULL;
  int32_T c24_i0;
  real_T c24_u[62];
  const mxArray *c24_b_y = NULL;
  uint8_T c24_hoistedGlobal;
  uint8_T c24_b_u;
  const mxArray *c24_c_y = NULL;
  uint8_T *c24_is_active_c24_Hquad_control_LIB_MPC;
  real_T (*c24_X_ref_z)[62];
  c24_X_ref_z = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c24_is_active_c24_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c24_st = NULL;
  c24_st = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createcellarray(2), FALSE);
  for (c24_i0 = 0; c24_i0 < 62; c24_i0++) {
    c24_u[c24_i0] = (*c24_X_ref_z)[c24_i0];
  }

  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 2, 31),
                FALSE);
  sf_mex_setcell(c24_y, 0, c24_b_y);
  c24_hoistedGlobal = *c24_is_active_c24_Hquad_control_LIB_MPC;
  c24_b_u = c24_hoistedGlobal;
  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", &c24_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c24_y, 1, c24_c_y);
  sf_mex_assign(&c24_st, c24_y, FALSE);
  return c24_st;
}

static void set_sim_state_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance, const mxArray
   *c24_st)
{
  const mxArray *c24_u;
  real_T c24_dv0[62];
  int32_T c24_i1;
  boolean_T *c24_doneDoubleBufferReInit;
  uint8_T *c24_is_active_c24_Hquad_control_LIB_MPC;
  real_T (*c24_X_ref_z)[62];
  c24_X_ref_z = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c24_is_active_c24_Hquad_control_LIB_MPC = (uint8_T *)ssGetDWork
    (chartInstance->S, 3);
  c24_doneDoubleBufferReInit = (boolean_T *)ssGetDWork(chartInstance->S, 2);
  *c24_doneDoubleBufferReInit = TRUE;
  c24_u = sf_mex_dup(c24_st);
  c24_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 0)),
                       "X_ref_z", c24_dv0);
  for (c24_i1 = 0; c24_i1 < 62; c24_i1++) {
    (*c24_X_ref_z)[c24_i1] = c24_dv0[c24_i1];
  }

  *c24_is_active_c24_Hquad_control_LIB_MPC = c24_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 1)),
     "is_active_c24_Hquad_control_LIB_MPC");
  sf_mex_destroy(&c24_u);
  c24_update_debugger_state_c24_Hquad_control_LIB_MPC(chartInstance);
  sf_mex_destroy(&c24_st);
}

static void finalize_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
}

static void sf_c24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
{
  int32_T c24_i2;
  int32_T c24_i3;
  real_T c24_hoistedGlobal;
  int32_T c24_i4;
  real_T c24_traj_z[1864];
  real_T c24_idx;
  uint32_T c24_debug_family_var_map[6];
  real_T c24_pred_horizon_z;
  real_T c24_nargin = 2.0;
  real_T c24_nargout = 1.0;
  real_T c24_X_ref_z[62];
  int32_T c24_i5;
  int32_T c24_i6;
  int32_T c24_i7;
  int32_T *c24_sfEvent;
  real_T *c24_b_idx;
  real_T (*c24_b_X_ref_z)[62];
  real_T (*c24_b_traj_z)[1864];
  c24_b_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c24_b_X_ref_z = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c24_b_traj_z = (real_T (*)[1864])ssGetInputPortSignal(chartInstance->S, 0);
  c24_sfEvent = (int32_T *)ssGetDWork(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 13U, *c24_sfEvent);
  for (c24_i2 = 0; c24_i2 < 1864; c24_i2++) {
    _SFD_DATA_RANGE_CHECK((*c24_b_traj_z)[c24_i2], 0U);
  }

  for (c24_i3 = 0; c24_i3 < 62; c24_i3++) {
    _SFD_DATA_RANGE_CHECK((*c24_b_X_ref_z)[c24_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c24_b_idx, 2U);
  *c24_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 13U, *c24_sfEvent);
  c24_hoistedGlobal = *c24_b_idx;
  for (c24_i4 = 0; c24_i4 < 1864; c24_i4++) {
    c24_traj_z[c24_i4] = (*c24_b_traj_z)[c24_i4];
  }

  c24_idx = c24_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c24_debug_family_names,
    c24_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c24_pred_horizon_z, 0U, c24_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c24_nargin, 1U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c24_nargout, 2U,
    c24_b_sf_marshallOut, c24_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c24_traj_z, 3U, c24_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c24_idx, 4U, c24_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c24_X_ref_z, 5U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, *c24_sfEvent, 3);
  c24_pred_horizon_z = 30.0;
  _SFD_EML_CALL(0U, *c24_sfEvent, 5);
  for (c24_i5 = 0; c24_i5 < 31; c24_i5++) {
    for (c24_i6 = 0; c24_i6 < 2; c24_i6++) {
      c24_X_ref_z[c24_i6 + (c24_i5 << 1)] = c24_traj_z[c24_i6 +
        ((_SFD_EML_ARRAY_BOUNDS_CHECK("traj_z", (int32_T)_SFD_INTEGER_CHECK(
            "idx:idx+pred_horizon_z", c24_idx + (real_T)c24_i5), 1, 932, 2, 0) -
          1) << 1)];
    }
  }

  _SFD_EML_CALL(0U, *c24_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  for (c24_i7 = 0; c24_i7 < 62; c24_i7++) {
    (*c24_b_X_ref_z)[c24_i7] = c24_X_ref_z[c24_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, *c24_sfEvent);
  sf_debug_check_for_state_inconsistency(_Hquad_control_LIB_MPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc24_Hquad_control_LIB_MPC
  (SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance)
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
  int32_T c24_i8;
  int32_T c24_i9;
  int32_T c24_i10;
  real_T c24_b_inData[62];
  int32_T c24_i11;
  int32_T c24_i12;
  int32_T c24_i13;
  real_T c24_u[62];
  const mxArray *c24_y = NULL;
  SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_i8 = 0;
  for (c24_i9 = 0; c24_i9 < 31; c24_i9++) {
    for (c24_i10 = 0; c24_i10 < 2; c24_i10++) {
      c24_b_inData[c24_i10 + c24_i8] = (*(real_T (*)[62])c24_inData)[c24_i10 +
        c24_i8];
    }

    c24_i8 += 2;
  }

  c24_i11 = 0;
  for (c24_i12 = 0; c24_i12 < 31; c24_i12++) {
    for (c24_i13 = 0; c24_i13 < 2; c24_i13++) {
      c24_u[c24_i13 + c24_i11] = c24_b_inData[c24_i13 + c24_i11];
    }

    c24_i11 += 2;
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 2, 31),
                FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static void c24_emlrt_marshallIn(SFc24_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c24_X_ref_z, const char_T *c24_identifier,
  real_T c24_y[62])
{
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_X_ref_z), &c24_thisId,
    c24_y);
  sf_mex_destroy(&c24_X_ref_z);
}

static void c24_b_emlrt_marshallIn(SFc24_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[62])
{
  real_T c24_dv1[62];
  int32_T c24_i14;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv1, 1, 0, 0U, 1, 0U, 2, 2,
                31);
  for (c24_i14 = 0; c24_i14 < 62; c24_i14++) {
    c24_y[c24_i14] = c24_dv1[c24_i14];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_X_ref_z;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[62];
  int32_T c24_i15;
  int32_T c24_i16;
  int32_T c24_i17;
  SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c24_X_ref_z = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_X_ref_z), &c24_thisId,
    c24_y);
  sf_mex_destroy(&c24_X_ref_z);
  c24_i15 = 0;
  for (c24_i16 = 0; c24_i16 < 31; c24_i16++) {
    for (c24_i17 = 0; c24_i17 < 2; c24_i17++) {
      (*(real_T (*)[62])c24_outData)[c24_i17 + c24_i15] = c24_y[c24_i17 +
        c24_i15];
    }

    c24_i15 += 2;
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i18;
  int32_T c24_i19;
  int32_T c24_i20;
  real_T c24_b_inData[1864];
  int32_T c24_i21;
  int32_T c24_i22;
  int32_T c24_i23;
  real_T c24_u[1864];
  const mxArray *c24_y = NULL;
  SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_i18 = 0;
  for (c24_i19 = 0; c24_i19 < 932; c24_i19++) {
    for (c24_i20 = 0; c24_i20 < 2; c24_i20++) {
      c24_b_inData[c24_i20 + c24_i18] = (*(real_T (*)[1864])c24_inData)[c24_i20
        + c24_i18];
    }

    c24_i18 += 2;
  }

  c24_i21 = 0;
  for (c24_i22 = 0; c24_i22 < 932; c24_i22++) {
    for (c24_i23 = 0; c24_i23 < 2; c24_i23++) {
      c24_u[c24_i23 + c24_i21] = c24_b_inData[c24_i23 + c24_i21];
    }

    c24_i21 += 2;
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 2, 2, 932),
                FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static real_T c24_c_emlrt_marshallIn(SFc24_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d0;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d0, 1, 0, 0U, 0, 0U, 0);
  c24_y = c24_d0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_nargout;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c24_nargout = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_nargout),
    &c24_thisId);
  sf_mex_destroy(&c24_nargout);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

const mxArray *sf_c24_Hquad_control_LIB_MPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c24_nameCaptureInfo = NULL;
  c24_nameCaptureInfo = NULL;
  sf_mex_assign(&c24_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c24_nameCaptureInfo;
}

static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(int32_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, FALSE);
  return c24_mxArrayOutData;
}

static int32_T c24_d_emlrt_marshallIn(SFc24_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  int32_T c24_y;
  int32_T c24_i24;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_i24, 1, 6, 0U, 0, 0U, 0);
  c24_y = c24_i24;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_sfEvent;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  int32_T c24_y;
  SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_MPCInstanceStruct *)chartInstanceVoid;
  c24_sfEvent = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_sfEvent),
    &c24_thisId);
  sf_mex_destroy(&c24_sfEvent);
  *(int32_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static uint8_T c24_e_emlrt_marshallIn(SFc24_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c24_is_active_c24_Hquad_control_LIB_MPC, const
  char_T *c24_identifier)
{
  uint8_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c24_is_active_c24_Hquad_control_LIB_MPC), &c24_thisId);
  sf_mex_destroy(&c24_is_active_c24_Hquad_control_LIB_MPC);
  return c24_y;
}

static uint8_T c24_f_emlrt_marshallIn(SFc24_Hquad_control_LIB_MPCInstanceStruct *
  chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  uint8_T c24_y;
  uint8_T c24_u0;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_u0, 1, 3, 0U, 0, 0U, 0);
  c24_y = c24_u0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void init_dsm_address_info(SFc24_Hquad_control_LIB_MPCInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
static uint32_T* sf_get_sfun_dwork_checksum();
void sf_c24_Hquad_control_LIB_MPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2330323927U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(752698208U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(21303563U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1883482296U);
}

mxArray *sf_c24_Hquad_control_LIB_MPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1NZmy9QUKO8Wfv2iXGmfmE");
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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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

static const mxArray *sf_get_sim_state_info_c24_Hquad_control_LIB_MPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[18],T\"X_ref_z\",},{M[8],M[0],T\"is_active_c24_Hquad_control_LIB_MPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c24_Hquad_control_LIB_MPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
    chartInstance = (SFc24_Hquad_control_LIB_MPCInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Hquad_control_LIB_MPCMachineNumber_,
           24,
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
          init_script_number_translation(_Hquad_control_LIB_MPCMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Hquad_control_LIB_MPCMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_Hquad_control_LIB_MPCMachineNumber_,
             chartInstance->chartNumber,
             0,
             0,
             0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"traj_z");
          _SFD_SET_DATA_PROPS(1,2,0,1,"X_ref_z");
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
          dimVector[0]= 2;
          dimVector[1]= 932;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 31;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)
            c24_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c24_idx;
          real_T (*c24_traj_z)[1864];
          real_T (*c24_X_ref_z)[62];
          c24_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c24_X_ref_z = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S,
            1);
          c24_traj_z = (real_T (*)[1864])ssGetInputPortSignal(chartInstance->S,
            0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c24_traj_z);
          _SFD_SET_DATA_VALUE_PTR(1U, *c24_X_ref_z);
          _SFD_SET_DATA_VALUE_PTR(2U, c24_idx);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Hquad_control_LIB_MPCMachineNumber_,chartInstance->chartNumber,
         chartInstance->instanceNumber);
    }
  }
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S, infoStruct,
      24, "dworkChecksum");
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

static void sf_opaque_initialize_c24_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc24_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc24_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c24_Hquad_control_LIB_MPC
    ((SFc24_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
  initialize_c24_Hquad_control_LIB_MPC
    ((SFc24_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c24_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  enable_c24_Hquad_control_LIB_MPC((SFc24_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c24_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  disable_c24_Hquad_control_LIB_MPC((SFc24_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c24_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  sf_c24_Hquad_control_LIB_MPC((SFc24_Hquad_control_LIB_MPCInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c24_Hquad_control_LIB_MPC(void
  *chartInstanceVar)
{
  ext_mode_exec_c24_Hquad_control_LIB_MPC
    ((SFc24_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c24_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c24_Hquad_control_LIB_MPC
    ((SFc24_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c24_Hquad_control_LIB_MPC();/* state var info */
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

extern void sf_internal_set_sim_state_c24_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c24_Hquad_control_LIB_MPC();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c24_Hquad_control_LIB_MPC
    ((SFc24_Hquad_control_LIB_MPCInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c24_Hquad_control_LIB_MPC
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c24_Hquad_control_LIB_MPC(S);
}

static void sf_opaque_set_sim_state_c24_Hquad_control_LIB_MPC(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c24_Hquad_control_LIB_MPC(S, st);
}

static void sf_opaque_terminate_c24_Hquad_control_LIB_MPC(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc24_Hquad_control_LIB_MPCInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c24_Hquad_control_LIB_MPC
      ((SFc24_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Hquad_control_LIB_MPC_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc24_Hquad_control_LIB_MPC
    ((SFc24_Hquad_control_LIB_MPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c24_Hquad_control_LIB_MPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c24_Hquad_control_LIB_MPC
      ((SFc24_Hquad_control_LIB_MPCInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

mxArray *sf_c24_Hquad_control_LIB_MPC_get_testpoint_info(void)
{
  const char *infoEncStr[] = {
    "100 S'varName','path'{{T\"is_active_c24_Hquad_control_LIB_MPC\",T\"is_active_c24_Hquad_control_LIB_MPC\"}}"
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

static void mdlSetWorkWidths_c24_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Hquad_control_LIB_MPC_optimization_info();
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
      sf_mark_chart_reusable_outputs(S,infoStruct,24,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,24);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1277706424U));
  ssSetChecksum1(S,(821805684U));
  ssSetChecksum2(S,(4132823012U));
  ssSetChecksum3(S,(2826003381U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c24_Hquad_control_LIB_MPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c24_Hquad_control_LIB_MPC(SimStruct *S)
{
  SFc24_Hquad_control_LIB_MPCInstanceStruct *chartInstance;
  chartInstance = (SFc24_Hquad_control_LIB_MPCInstanceStruct *)malloc(sizeof
    (SFc24_Hquad_control_LIB_MPCInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc24_Hquad_control_LIB_MPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c24_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c24_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c24_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c24_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c24_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c24_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c24_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c24_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c24_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c24_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c24_Hquad_control_LIB_MPC;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c24_Hquad_control_LIB_MPC;
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

void c24_Hquad_control_LIB_MPC_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c24_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c24_Hquad_control_LIB_MPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c24_Hquad_control_LIB_MPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c24_Hquad_control_LIB_MPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
