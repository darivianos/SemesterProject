/*
 * FG_traj_fast_dt.h
 *
 * Code generation for model "FG_traj_fast".
 *
 * Model version              : 1.362
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C++ source code generated on : Thu May  2 14:33:59 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&FG_traj_fast_B.DataTypeConversion[0]), 0, 0, 401 },

  { (char_T *)(&FG_traj_fast_B.sf_EmbeddedMATLABFunction_j.roll_rot), 0, 0, 4 },

  { (char_T *)(&FG_traj_fast_B.MAINCONTROLLOOP1_c.Saturation), 0, 0, 8 },

  { (char_T *)
    (&FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_discretekalmanfilter_d.state_est[0]),
    0, 0, 12 },

  { (char_T *)
    (&FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_discretekalmanfilter_j.state_est[0]),
    0, 0, 12 },

  { (char_T *)
    (&FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_discretekalmanfilter_n.state_est[0]),
    0, 0, 20 },

  { (char_T *)(&FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_runFastGradient_a.u_opt), 0,
    0, 34 },

  { (char_T *)
    (&FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_discretekalmanfilter.state_est[0]), 0,
    0, 20 },

  { (char_T *)(&FG_traj_fast_B.MAINCONTROLLOOP1_c.sf_runFastGradient.u_opt), 0,
    0, 34 },

  { (char_T *)(&FG_traj_fast_B.sf_EmbeddedMATLABFunction.roll_rot), 0, 0, 4 },

  { (char_T *)(&FG_traj_fast_B.MAINCONTROLLOOP1.Saturation), 0, 0, 8 },

  { (char_T *)
    (&FG_traj_fast_B.MAINCONTROLLOOP1.sf_discretekalmanfilter_d.state_est[0]), 0,
    0, 12 },

  { (char_T *)
    (&FG_traj_fast_B.MAINCONTROLLOOP1.sf_discretekalmanfilter_j.state_est[0]), 0,
    0, 12 },

  { (char_T *)
    (&FG_traj_fast_B.MAINCONTROLLOOP1.sf_discretekalmanfilter_n.state_est[0]), 0,
    0, 20 },

  { (char_T *)(&FG_traj_fast_B.MAINCONTROLLOOP1.sf_runFastGradient_a.u_opt), 0,
    0, 34 },

  { (char_T *)
    (&FG_traj_fast_B.MAINCONTROLLOOP1.sf_discretekalmanfilter.state_est[0]), 0,
    0, 20 },

  { (char_T *)(&FG_traj_fast_B.MAINCONTROLLOOP1.sf_runFastGradient.u_opt), 0, 0,
    34 }
  ,

  { (char_T *)(&FG_traj_fast_DWork.FixPtUnitDelay1_DSTATE[0]), 0, 0, 4 },

  { (char_T *)(&FG_traj_fast_DWork.bias_PWORK.LoggedData), 11, 0, 28 },

  { (char_T *)(&FG_traj_fast_DWork.ToFile_IWORK.Count), 10, 0, 4 },

  { (char_T *)(&FG_traj_fast_DWork.FixPtUnitDelay2_DSTATE), 3, 0, 1 },

  { (char_T *)(&FG_traj_fast_DWork.poscontroller1_SubsysRanBC), 2, 0, 2 },

  { (char_T *)(&FG_traj_fast_DWork.poscontroller1_MODE), 8, 0, 2 },

  { (char_T *)(&FG_traj_fast_DWork.MAINCONTROLLOOP1_c.IntegerDelay_DSTATE), 0, 0,
    198 },

  { (char_T *)(&FG_traj_fast_DWork.MAINCONTROLLOOP1_c.FixPtUnitDelay2_DSTATE), 3,
    0, 4 },

  { (char_T *)(&FG_traj_fast_DWork.MAINCONTROLLOOP1.IntegerDelay_DSTATE), 0, 0,
    198 },

  { (char_T *)(&FG_traj_fast_DWork.MAINCONTROLLOOP1.FixPtUnitDelay2_DSTATE), 3,
    0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  27U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&FG_traj_fast_P.yaw_rate_bias_Value), 0, 0, 35 },

  { (char_T *)(&FG_traj_fast_P.FixPtUnitDelay2_InitialConditio), 3, 0, 3 },

  { (char_T *)(&FG_traj_fast_P.MAINCONTROLLOOP1_c.IntegerDelay_InitialCondition),
    0, 0, 21028 },

  { (char_T *)(&FG_traj_fast_P.MAINCONTROLLOOP1_c.IntegerDelay_DelayLength), 7,
    0, 4 },

  { (char_T *)
    (&FG_traj_fast_P.MAINCONTROLLOOP1_c.FixPtUnitDelay2_InitialConditio), 3, 0,
    8 },

  { (char_T *)(&FG_traj_fast_P.MAINCONTROLLOOP1.IntegerDelay_InitialCondition),
    0, 0, 21028 },

  { (char_T *)(&FG_traj_fast_P.MAINCONTROLLOOP1.IntegerDelay_DelayLength), 7, 0,
    4 },

  { (char_T *)(&FG_traj_fast_P.MAINCONTROLLOOP1.FixPtUnitDelay2_InitialConditio),
    3, 0, 8 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  8U,
  rtPTransitions
};

/* [EOF] FG_traj_fast_dt.h */
