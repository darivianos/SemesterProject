/* Include files */

#include "blascompat32.h"
#include "Simulator_hquad_MPC_FG_trajectory_sfun.h"
#include "c1_Simulator_hquad_MPC_FG_trajectory.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Simulator_hquad_MPC_FG_trajectory_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[6] = { "pred_horizon_z", "nargin",
  "nargout", "traj_z", "idx", "X_ref_z" };

/* Function Declarations */
static void initialize_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance);
static void initialize_params_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance);
static void enable_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance);
static void disable_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance);
static void set_sim_state_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_st);
static void finalize_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance);
static void sf_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance);
static void initSimStructsc1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_X_ref_z, const char_T *c1_identifier, real_T c1_y[62]);
static void c1_b_emlrt_marshallIn
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[62]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_d_emlrt_marshallIn
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_e_emlrt_marshallIn
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_Simulator_hquad_MPC_FG_trajectory, const char_T
   *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_Simulator_hquad_MPC_FG_trajectory = 0U;
}

static void initialize_params_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance)
{
}

static void enable_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  int32_T c1_i0;
  real_T c1_u[62];
  const mxArray *c1_b_y = NULL;
  uint8_T c1_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T (*c1_X_ref_z)[62];
  c1_X_ref_z = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2), FALSE);
  for (c1_i0 = 0; c1_i0 < 62; c1_i0++) {
    c1_u[c1_i0] = (*c1_X_ref_z)[c1_i0];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2, 31),
                FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_hoistedGlobal =
    chartInstance->c1_is_active_c1_Simulator_hquad_MPC_FG_trajectory;
  c1_b_u = c1_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[62];
  int32_T c1_i1;
  real_T (*c1_X_ref_z)[62];
  c1_X_ref_z = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 0)),
                      "X_ref_z", c1_dv0);
  for (c1_i1 = 0; c1_i1 < 62; c1_i1++) {
    (*c1_X_ref_z)[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_Simulator_hquad_MPC_FG_trajectory =
    c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "is_active_c1_Simulator_hquad_MPC_FG_trajectory");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_Simulator_hquad_MPC_FG_trajectory(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance)
{
}

static void sf_c1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance)
{
  int32_T c1_i2;
  int32_T c1_i3;
  real_T c1_hoistedGlobal;
  int32_T c1_i4;
  real_T c1_traj_z[1864];
  real_T c1_idx;
  uint32_T c1_debug_family_var_map[6];
  real_T c1_pred_horizon_z;
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  real_T c1_X_ref_z[62];
  int32_T c1_i5;
  int32_T c1_i6;
  int32_T c1_i7;
  real_T *c1_b_idx;
  real_T (*c1_b_X_ref_z)[62];
  real_T (*c1_b_traj_z)[1864];
  c1_b_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_X_ref_z = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_traj_z = (real_T (*)[1864])ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  for (c1_i2 = 0; c1_i2 < 1864; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_traj_z)[c1_i2], 0U);
  }

  for (c1_i3 = 0; c1_i3 < 62; c1_i3++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_X_ref_z)[c1_i3], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*c1_b_idx, 2U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_idx;
  for (c1_i4 = 0; c1_i4 < 1864; c1_i4++) {
    c1_traj_z[c1_i4] = (*c1_b_traj_z)[c1_i4];
  }

  c1_idx = c1_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 6U, 6U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml(&c1_pred_horizon_z, 0U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 2U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(c1_traj_z, 3U, c1_c_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_idx, 4U, c1_b_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(c1_X_ref_z, 5U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  c1_pred_horizon_z = 30.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 5);
  for (c1_i5 = 0; c1_i5 < 31; c1_i5++) {
    for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
      c1_X_ref_z[c1_i6 + (c1_i5 << 1)] = c1_traj_z[c1_i6 +
        ((_SFD_EML_ARRAY_BOUNDS_CHECK("traj_z", (int32_T)_SFD_INTEGER_CHECK(
            "idx:idx+pred_horizon_z", c1_idx + (real_T)c1_i5), 1, 932, 2, 0) - 1)
         << 1)];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -5);
  sf_debug_symbol_scope_pop();
  for (c1_i7 = 0; c1_i7 < 62; c1_i7++) {
    (*c1_b_X_ref_z)[c1_i7] = c1_X_ref_z[c1_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency
    (_Simulator_hquad_MPC_FG_trajectoryMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_Simulator_hquad_MPC_FG_trajectory
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i8;
  int32_T c1_i9;
  int32_T c1_i10;
  real_T c1_b_inData[62];
  int32_T c1_i11;
  int32_T c1_i12;
  int32_T c1_i13;
  real_T c1_u[62];
  const mxArray *c1_y = NULL;
  SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i8 = 0;
  for (c1_i9 = 0; c1_i9 < 31; c1_i9++) {
    for (c1_i10 = 0; c1_i10 < 2; c1_i10++) {
      c1_b_inData[c1_i10 + c1_i8] = (*(real_T (*)[62])c1_inData)[c1_i10 + c1_i8];
    }

    c1_i8 += 2;
  }

  c1_i11 = 0;
  for (c1_i12 = 0; c1_i12 < 31; c1_i12++) {
    for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
      c1_u[c1_i13 + c1_i11] = c1_b_inData[c1_i13 + c1_i11];
    }

    c1_i11 += 2;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2, 31), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_X_ref_z, const char_T *c1_identifier, real_T c1_y[62])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_X_ref_z), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_X_ref_z);
}

static void c1_b_emlrt_marshallIn
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[62])
{
  real_T c1_dv1[62];
  int32_T c1_i14;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 2, 2, 31);
  for (c1_i14 = 0; c1_i14 < 62; c1_i14++) {
    c1_y[c1_i14] = c1_dv1[c1_i14];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_X_ref_z;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[62];
  int32_T c1_i15;
  int32_T c1_i16;
  int32_T c1_i17;
  SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *)
    chartInstanceVoid;
  c1_X_ref_z = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_X_ref_z), &c1_thisId, c1_y);
  sf_mex_destroy(&c1_X_ref_z);
  c1_i15 = 0;
  for (c1_i16 = 0; c1_i16 < 31; c1_i16++) {
    for (c1_i17 = 0; c1_i17 < 2; c1_i17++) {
      (*(real_T (*)[62])c1_outData)[c1_i17 + c1_i15] = c1_y[c1_i17 + c1_i15];
    }

    c1_i15 += 2;
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i18;
  int32_T c1_i19;
  int32_T c1_i20;
  real_T c1_b_inData[1864];
  int32_T c1_i21;
  int32_T c1_i22;
  int32_T c1_i23;
  real_T c1_u[1864];
  const mxArray *c1_y = NULL;
  SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_i18 = 0;
  for (c1_i19 = 0; c1_i19 < 932; c1_i19++) {
    for (c1_i20 = 0; c1_i20 < 2; c1_i20++) {
      c1_b_inData[c1_i20 + c1_i18] = (*(real_T (*)[1864])c1_inData)[c1_i20 +
        c1_i18];
    }

    c1_i18 += 2;
  }

  c1_i21 = 0;
  for (c1_i22 = 0; c1_i22 < 932; c1_i22++) {
    for (c1_i23 = 0; c1_i23 < 2; c1_i23++) {
      c1_u[c1_i23 + c1_i21] = c1_b_inData[c1_i23 + c1_i21];
    }

    c1_i21 += 2;
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 2, 932), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *)
    chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray
  *sf_c1_Simulator_hquad_MPC_FG_trajectory_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_d_emlrt_marshallIn
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i24;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i24, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i24;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_e_emlrt_marshallIn
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_b_is_active_c1_Simulator_hquad_MPC_FG_trajectory, const char_T
   *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_Simulator_hquad_MPC_FG_trajectory), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_Simulator_hquad_MPC_FG_trajectory);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance, const
   mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info
  (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_Simulator_hquad_MPC_FG_trajectory_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2330323927U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(752698208U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(21303563U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1883482296U);
}

mxArray *sf_c1_Simulator_hquad_MPC_FG_trajectory_get_autoinheritance_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_Simulator_hquad_MPC_FG_trajectory
  (void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[18],T\"X_ref_z\",},{M[8],M[0],T\"is_active_c1_Simulator_hquad_MPC_FG_trajectory\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_Simulator_hquad_MPC_FG_trajectory_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance;
    chartInstance = (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_Simulator_hquad_MPC_FG_trajectoryMachineNumber_,
           1,
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
            (_Simulator_hquad_MPC_FG_trajectoryMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_Simulator_hquad_MPC_FG_trajectoryMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds
            (_Simulator_hquad_MPC_FG_trajectoryMachineNumber_,
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
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 2;
          dimVector[1]= 31;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)
            c1_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_idx;
          real_T (*c1_traj_z)[1864];
          real_T (*c1_X_ref_z)[62];
          c1_idx = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_X_ref_z = (real_T (*)[62])ssGetOutputPortSignal(chartInstance->S, 1);
          c1_traj_z = (real_T (*)[1864])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c1_traj_z);
          _SFD_SET_DATA_VALUE_PTR(1U, *c1_X_ref_z);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_idx);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration
        (_Simulator_hquad_MPC_FG_trajectoryMachineNumber_,
         chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_Simulator_hquad_MPC_FG_trajectory(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct*) chartInstanceVar
     )->S,0);
  initialize_params_c1_Simulator_hquad_MPC_FG_trajectory
    ((SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct*) chartInstanceVar);
  initialize_c1_Simulator_hquad_MPC_FG_trajectory
    ((SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_Simulator_hquad_MPC_FG_trajectory(void
  *chartInstanceVar)
{
  enable_c1_Simulator_hquad_MPC_FG_trajectory
    ((SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_Simulator_hquad_MPC_FG_trajectory(void
  *chartInstanceVar)
{
  disable_c1_Simulator_hquad_MPC_FG_trajectory
    ((SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_Simulator_hquad_MPC_FG_trajectory(void
  *chartInstanceVar)
{
  sf_c1_Simulator_hquad_MPC_FG_trajectory
    ((SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct*) chartInstanceVar);
}

extern const mxArray*
  sf_internal_get_sim_state_c1_Simulator_hquad_MPC_FG_trajectory(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_Simulator_hquad_MPC_FG_trajectory
    ((SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c1_Simulator_hquad_MPC_FG_trajectory();/* state var info */
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

extern void sf_internal_set_sim_state_c1_Simulator_hquad_MPC_FG_trajectory
  (SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*)
    sf_get_sim_state_info_c1_Simulator_hquad_MPC_FG_trajectory();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_Simulator_hquad_MPC_FG_trajectory
    ((SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct*)
     chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray*
  sf_opaque_get_sim_state_c1_Simulator_hquad_MPC_FG_trajectory(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_Simulator_hquad_MPC_FG_trajectory(S);
}

static void sf_opaque_set_sim_state_c1_Simulator_hquad_MPC_FG_trajectory
  (SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c1_Simulator_hquad_MPC_FG_trajectory(S, st);
}

static void sf_opaque_terminate_c1_Simulator_hquad_MPC_FG_trajectory(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_Simulator_hquad_MPC_FG_trajectory
      ((SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_Simulator_hquad_MPC_FG_trajectory_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_Simulator_hquad_MPC_FG_trajectory
    ((SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_Simulator_hquad_MPC_FG_trajectory(SimStruct *
  S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_Simulator_hquad_MPC_FG_trajectory
      ((SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct*)(((ChartInfoStruct
          *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_Simulator_hquad_MPC_FG_trajectory(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_Simulator_hquad_MPC_FG_trajectory_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,infoStruct,1,2);
      sf_mark_chart_reusable_outputs(S,infoStruct,1,1);
    }

    sf_set_rtw_dwork_info(S,infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1277706424U));
  ssSetChecksum1(S,(821805684U));
  ssSetChecksum2(S,(4132823012U));
  ssSetChecksum3(S,(2826003381U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_Simulator_hquad_MPC_FG_trajectory(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_Simulator_hquad_MPC_FG_trajectory(SimStruct *S)
{
  SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *chartInstance;
  chartInstance = (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct *)malloc
    (sizeof(SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc1_Simulator_hquad_MPC_FG_trajectoryInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_Simulator_hquad_MPC_FG_trajectory;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_Simulator_hquad_MPC_FG_trajectory;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_Simulator_hquad_MPC_FG_trajectory;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_Simulator_hquad_MPC_FG_trajectory;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_Simulator_hquad_MPC_FG_trajectory;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_Simulator_hquad_MPC_FG_trajectory;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_Simulator_hquad_MPC_FG_trajectory;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_Simulator_hquad_MPC_FG_trajectory;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_Simulator_hquad_MPC_FG_trajectory;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c1_Simulator_hquad_MPC_FG_trajectory;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_Simulator_hquad_MPC_FG_trajectory;
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

void c1_Simulator_hquad_MPC_FG_trajectory_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_Simulator_hquad_MPC_FG_trajectory(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_Simulator_hquad_MPC_FG_trajectory(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_Simulator_hquad_MPC_FG_trajectory(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_Simulator_hquad_MPC_FG_trajectory_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
