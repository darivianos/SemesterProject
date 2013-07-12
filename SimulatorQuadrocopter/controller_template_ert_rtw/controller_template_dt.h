/*
 * controller_template_dt.h
 *
 * Code generation for model "controller_template.mdl".
 *
 * Model version              : 1.613
 * Simulink Coder version : 8.1 (R2011b) 08-Jul-2011
 * C++ source code generated on : Wed Jul 10 21:38:37 2013
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
  { (char_T *)(&controller_template_B.DataTypeConversion[0]), 0, 0, 560 },

  { (char_T *)(&controller_template_B.sf_EmbeddedMATLABFunction_o.roll_rot), 0,
    0, 4 },

  { (char_T *)(&controller_template_B.sf_discretekalmanfilter_k.state_est[0]), 0,
    0, 12 },

  { (char_T *)(&controller_template_B.sf_discretekalmanfilter_n.state_est[0]), 0,
    0, 12 },

  { (char_T *)(&controller_template_B.sf_discretekalmanfilter_m.state_est[0]), 0,
    0, 20 },

  { (char_T *)(&controller_template_B.sf_runFastGradient_d.u_opt), 0, 0, 35 },

  { (char_T *)(&controller_template_B.sf_discretekalmanfilter_b.state_est[0]), 0,
    0, 20 },

  { (char_T *)(&controller_template_B.sf_runFastGradient.u_opt), 0, 0, 35 },

  { (char_T *)(&controller_template_B.sf_EmbeddedMATLABFunction.roll_rot), 0, 0,
    4 },

  { (char_T *)(&controller_template_B.sf_MATLABFunction_p.y), 0, 0, 1 },

  { (char_T *)(&controller_template_B.sf_generate_X_ref_z.X_ref_z[0]), 0, 0, 62
  },

  { (char_T *)(&controller_template_B.sf_generate_X_ref_yaw.X_ref_yaw[0]), 0, 0,
    62 },

  { (char_T *)(&controller_template_B.sf_generate_X_ref_y.X_ref_y[0]), 0, 0, 93
  },

  { (char_T *)(&controller_template_B.sf_generate_X_ref_x.X_ref_x[0]), 0, 0, 93
  },

  { (char_T *)(&controller_template_B.sf_MATLABFunction.y), 0, 0, 1 },

  { (char_T *)(&controller_template_B.sf_discretekalmanfilter.state_est[0]), 0,
    0, 12 },

  { (char_T *)(&controller_template_B.sf_MATLABFunction_k.y[0]), 0, 0, 4 },

  { (char_T *)(&controller_template_B.sf_MATLABFunction_e.y), 0, 0, 1 },

  { (char_T *)(&controller_template_B.sf_MATLABFunction_i.y[0]), 0, 0, 4 },

  { (char_T *)(&controller_template_B.sf_generate_X_ref_z_l.X_ref_z[0]), 0, 0,
    62 },

  { (char_T *)(&controller_template_B.sf_generate_X_ref_yaw_g.X_ref_yaw[0]), 0,
    0, 62 },

  { (char_T *)(&controller_template_B.sf_generate_X_ref_y_a.X_ref_y[0]), 0, 0,
    93 },

  { (char_T *)(&controller_template_B.sf_generate_X_ref_x_k.X_ref_x[0]), 0, 0,
    93 }
  ,

  { (char_T *)(&controller_template_DWork.FixPtUnitDelay1_DSTATE[0]), 0, 0, 235
  },

  { (char_T *)(&controller_template_DWork.bias_PWORK.LoggedData), 11, 0, 34 },

  { (char_T *)(&controller_template_DWork.sfEvent), 6, 0, 17 },

  { (char_T *)(&controller_template_DWork.ToFile_IWORK.Count), 10, 0, 4 },

  { (char_T *)(&controller_template_DWork.FixPtUnitDelay2_DSTATE), 3, 0, 6 },

  { (char_T *)(&controller_template_DWork.FreeFlightPosCtrl_SubsysRanBC), 2, 0,
    2 },

  { (char_T *)(&controller_template_DWork.is_active_c4_Hquad_control_LIB_), 3, 0,
    17 },

  { (char_T *)(&controller_template_DWork.isStable), 8, 0, 36 },

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
    (&controller_template_DWork.sf_discretekalmanfilter_k.is_active_c27_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter_k.isStable), 8,
    0, 2 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter_n.sfEvent), 6,
    0, 1 },

  { (char_T *)
    (&controller_template_DWork.sf_discretekalmanfilter_n.is_active_c27_controller_templa),
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

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter_b.sfEvent), 6,
    0, 1 },

  { (char_T *)
    (&controller_template_DWork.sf_discretekalmanfilter_b.is_active_c11_Hquad_control_LIB),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter_b.isStable), 8,
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

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction_p.sfEvent), 6, 0, 1
  },

  { (char_T *)
    (&controller_template_DWork.sf_MATLABFunction_p.is_active_c15_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction_p.isStable), 8, 0, 2
  },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_z.sfEvent), 6, 0, 1
  },

  { (char_T *)
    (&controller_template_DWork.sf_generate_X_ref_z.is_active_c22_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_z.isStable), 8, 0, 2
  },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_yaw.sfEvent), 6, 0,
    1 },

  { (char_T *)
    (&controller_template_DWork.sf_generate_X_ref_yaw.is_active_c21_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_yaw.isStable), 8, 0,
    2 },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_y.sfEvent), 6, 0, 1
  },

  { (char_T *)
    (&controller_template_DWork.sf_generate_X_ref_y.is_active_c20_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_y.isStable), 8, 0, 2
  },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_x.sfEvent), 6, 0, 1
  },

  { (char_T *)
    (&controller_template_DWork.sf_generate_X_ref_x.is_active_c19_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_x.isStable), 8, 0, 2
  },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction.sfEvent), 6, 0, 1 },

  { (char_T *)
    (&controller_template_DWork.sf_MATLABFunction.is_active_c15_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction.isStable), 8, 0, 2 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter.sfEvent), 6, 0,
    1 },

  { (char_T *)
    (&controller_template_DWork.sf_discretekalmanfilter.is_active_c27_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_discretekalmanfilter.isStable), 8,
    0, 2 },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction_k.sfEvent), 6, 0, 1
  },

  { (char_T *)
    (&controller_template_DWork.sf_MATLABFunction_k.is_active_c26_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction_k.isStable), 8, 0, 2
  },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction_e.sfEvent), 6, 0, 1
  },

  { (char_T *)
    (&controller_template_DWork.sf_MATLABFunction_e.is_active_c15_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction_e.isStable), 8, 0, 2
  },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction_i.sfEvent), 6, 0, 1
  },

  { (char_T *)
    (&controller_template_DWork.sf_MATLABFunction_i.is_active_c26_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_MATLABFunction_i.isStable), 8, 0, 2
  },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_z_l.sfEvent), 6, 0,
    1 },

  { (char_T *)
    (&controller_template_DWork.sf_generate_X_ref_z_l.is_active_c22_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_z_l.isStable), 8, 0,
    2 },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_yaw_g.sfEvent), 6, 0,
    1 },

  { (char_T *)
    (&controller_template_DWork.sf_generate_X_ref_yaw_g.is_active_c21_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_yaw_g.isStable), 8,
    0, 2 },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_y_a.sfEvent), 6, 0,
    1 },

  { (char_T *)
    (&controller_template_DWork.sf_generate_X_ref_y_a.is_active_c20_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_y_a.isStable), 8, 0,
    2 },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_x_k.sfEvent), 6, 0,
    1 },

  { (char_T *)
    (&controller_template_DWork.sf_generate_X_ref_x_k.is_active_c19_controller_templa),
    3, 0, 1 },

  { (char_T *)(&controller_template_DWork.sf_generate_X_ref_x_k.isStable), 8, 0,
    2 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  97U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&controller_template_P.Constant3_Value[0]), 0, 0, 50757 },

  { (char_T *)(&controller_template_P.IntegerDelay3_DelayLength), 7, 0, 5 },

  { (char_T *)(&controller_template_P.FixPtUnitDelay2_X0), 3, 0, 31 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] controller_template_dt.h */
