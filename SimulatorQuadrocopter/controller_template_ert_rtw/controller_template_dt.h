/*
 * controller_template_dt.h
 *
 * Code generation for model "controller_template.mdl".
 *
 * Model version              : 1.404
 * Simulink Coder version : 8.1 (R2011b) 08-Jul-2011
 * C++ source code generated on : Tue May 14 19:09:51 2013
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
  { (char_T *)(&controller_template_B.DataTypeConversion[0]), 0, 0, 509 },

  { (char_T *)(&controller_template_B.sf_EmbeddedMATLABFunction_o.roll_rot), 0,
    0, 4 },

  { (char_T *)(&controller_template_B.sf_discretekalmanfilter_k.state_est[0]), 0,
    0, 12 },

  { (char_T *)(&controller_template_B.sf_discretekalmanfilter_n.state_est[0]), 0,
    0, 12 },

  { (char_T *)(&controller_template_B.sf_discretekalmanfilter_m.state_est[0]), 0,
    0, 20 },

  { (char_T *)(&controller_template_B.sf_runFastGradient_d.u_opt), 0, 0, 35 },

  { (char_T *)(&controller_template_B.sf_discretekalmanfilter.state_est[0]), 0,
    0, 20 },

  { (char_T *)(&controller_template_B.sf_runFastGradient.u_opt), 0, 0, 35 },

  { (char_T *)(&controller_template_B.sf_EmbeddedMATLABFunction.roll_rot), 0, 0,
    4 },

  { (char_T *)(&controller_template_B.sf_MATLABFunction_k.y[0]), 0, 0, 4 },

  { (char_T *)(&controller_template_B.sf_MATLABFunction_f.y[0]), 0, 0, 4 }
  ,

  { (char_T *)(&controller_template_DWork.FixPtUnitDelay1_DSTATE[0]), 0, 0, 217
  },

  { (char_T *)(&controller_template_DWork.bias_PWORK.LoggedData), 11, 0, 29 },

  { (char_T *)(&controller_template_DWork.sfEvent), 6, 0, 12 },

  { (char_T *)(&controller_template_DWork.ToFile_IWORK.Count), 10, 0, 4 },

  { (char_T *)(&controller_template_DWork.FixPtUnitDelay2_DSTATE), 3, 0, 5 },

  { (char_T *)(&controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC), 2, 0,
    2 },

  { (char_T *)(&controller_template_DWork.is_active_c4_Hquad_control_LIB_), 3, 0,
    12 },

  { (char_T *)(&controller_template_DWork.isStable), 8, 0, 26 },

  { (char_T *)(&controller_template_DWork.sf_EmbeddedMATLABFunction_o.sfEvent),
    6, 0, 1 },

  { (char_T *)
    (&controller_template_DWork.sf_EmbeddedMATLABFunction_o.is_active_c26_Hquad_control_LIB),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_EmbeddedMATLABFunction_o.isStable),
    8, 0, 2 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter_k.sfEvent), 6,
    0, 1 },

  { (char_T *)
    (&controller_template_DWork.sf_discretekalmanfilter_k.is_active_c5_Hquad_control_LIB_),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter_k.isStable), 8,
    0, 2 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter_n.sfEvent), 6,
    0, 1 },

  { (char_T *)
    (&controller_template_DWork.sf_discretekalmanfilter_n.is_active_c5_Hquad_control_LIB_),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter_n.isStable), 8,
    0, 2 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter_m.sfEvent), 6,
    0, 1 },

  { (char_T *)
    (&controller_template_DWork.sf_discretekalmanfilter_m.is_active_c11_Hquad_control_LIB),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter_m.isStable), 8,
    0, 2 },

  { (char_T *)(&controller_template_DWork.sf_runFastGradient_d.sfEvent), 6, 0, 1
  },

  { (char_T *)
    (&controller_template_DWork.sf_runFastGradient_d.is_active_c6_Hquad_control_LIB_),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_runFastGradient_d.isStable), 8, 0,
    2 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter.sfEvent), 6, 0,
    1 },

  { (char_T *)
    (&controller_template_DWork.sf_discretekalmanfilter.is_active_c11_Hquad_control_LIB),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter.isStable), 8,
    0, 2 },

  { (char_T *)(&controller_template_DWork.sf_runFastGradient.sfEvent), 6, 0, 1 },

  { (char_T *)
    (&controller_template_DWork.sf_runFastGradient.is_active_c6_Hquad_control_LIB_),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_runFastGradient.isStable), 8, 0, 2
  },

  { (char_T *)(&controller_template_DWork.sf_EmbeddedMATLABFunction.sfEvent), 6,
    0, 1 },

  { (char_T *)
    (&controller_template_DWork.sf_EmbeddedMATLABFunction.is_active_c26_Hquad_control_LIB),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_EmbeddedMATLABFunction.isStable), 8,
    0, 2 },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction_k.sfEvent), 6, 0, 1
  },

  { (char_T *)
    (&controller_template_DWork.sf_MATLABFunction_k.is_active_c7_controller_templat),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction_k.isStable), 8, 0, 2
  },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction_f.sfEvent), 6, 0, 1
  },

  { (char_T *)
    (&controller_template_DWork.sf_MATLABFunction_f.is_active_c7_controller_templat),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction_f.isStable), 8, 0, 2
  }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  49U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&controller_template_P.gravity_Value), 0, 0, 46525 },

  { (char_T *)(&controller_template_P.IntegerDelay_DelayLength), 7, 0, 4 },

  { (char_T *)(&controller_template_P.FixPtUnitDelay2_X0), 3, 0, 12 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] controller_template_dt.h */
