/*
 * File: controller_template.h
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.681
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Aug  6 2011)
 * C/C++ source code generated on : Sun Sep  1 21:17:59 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_controller_template_h_
#define RTW_HEADER_controller_template_h_
#ifndef controller_template_COMMON_INCLUDES_
# define controller_template_COMMON_INCLUDES_
#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#endif                                 /* controller_template_COMMON_INCLUDES_ */

#include "controller_template_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* user code (top of header file) */
#include <math.h>

/* Block signals for system '<S17>/generate_X_ref_x' */
typedef struct {
  real_T X_ref_x[93];                  /* '<S17>/generate_X_ref_x' */
} rtB_generate_X_ref_x_controller;

/* Block states (auto storage) for system '<S17>/generate_X_ref_x' */
typedef struct {
  int32_T sfEvent;                     /* '<S17>/generate_X_ref_x' */
  uint8_T is_active_c19_controller_templa;/* '<S17>/generate_X_ref_x' */
  boolean_T isStable;                  /* '<S17>/generate_X_ref_x' */
  boolean_T doneDoubleBufferReInit;    /* '<S17>/generate_X_ref_x' */
} rtDW_generate_X_ref_x_controlle;

/* Block signals for system '<S17>/generate_X_ref_y' */
typedef struct {
  real_T X_ref_y[93];                  /* '<S17>/generate_X_ref_y' */
} rtB_generate_X_ref_y_controller;

/* Block states (auto storage) for system '<S17>/generate_X_ref_y' */
typedef struct {
  int32_T sfEvent;                     /* '<S17>/generate_X_ref_y' */
  uint8_T is_active_c20_controller_templa;/* '<S17>/generate_X_ref_y' */
  boolean_T isStable;                  /* '<S17>/generate_X_ref_y' */
  boolean_T doneDoubleBufferReInit;    /* '<S17>/generate_X_ref_y' */
} rtDW_generate_X_ref_y_controlle;

/* Block signals for system '<S17>/generate_X_ref_yaw' */
typedef struct {
  real_T X_ref_yaw[62];                /* '<S17>/generate_X_ref_yaw' */
} rtB_generate_X_ref_yaw_controll;

/* Block states (auto storage) for system '<S17>/generate_X_ref_yaw' */
typedef struct {
  int32_T sfEvent;                     /* '<S17>/generate_X_ref_yaw' */
  uint8_T is_active_c21_controller_templa;/* '<S17>/generate_X_ref_yaw' */
  boolean_T isStable;                  /* '<S17>/generate_X_ref_yaw' */
  boolean_T doneDoubleBufferReInit;    /* '<S17>/generate_X_ref_yaw' */
} rtDW_generate_X_ref_yaw_control;

/* Block signals for system '<S17>/generate_X_ref_z' */
typedef struct {
  real_T X_ref_z[62];                  /* '<S17>/generate_X_ref_z' */
} rtB_generate_X_ref_z_controller;

/* Block states (auto storage) for system '<S17>/generate_X_ref_z' */
typedef struct {
  int32_T sfEvent;                     /* '<S17>/generate_X_ref_z' */
  uint8_T is_active_c22_controller_templa;/* '<S17>/generate_X_ref_z' */
  boolean_T isStable;                  /* '<S17>/generate_X_ref_z' */
  boolean_T doneDoubleBufferReInit;    /* '<S17>/generate_X_ref_z' */
} rtDW_generate_X_ref_z_controlle;

/* Block signals for system '<S40>/MATLAB Function' */
typedef struct {
  real_T y;                            /* '<S40>/MATLAB Function' */
} rtB_MATLABFunction_controller_t;

/* Block states (auto storage) for system '<S40>/MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S40>/MATLAB Function' */
  uint8_T is_active_c15_controller_templa;/* '<S40>/MATLAB Function' */
  boolean_T isStable;                  /* '<S40>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S40>/MATLAB Function' */
} rtDW_MATLABFunction_controller_;

/* Block signals for system '<S55>/MATLAB Function' */
typedef struct {
  real_T y;                            /* '<S55>/MATLAB Function' */
} rtB_MATLABFunction_controller_p;

/* Block states (auto storage) for system '<S55>/MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S55>/MATLAB Function' */
  uint8_T is_active_c13_controller_templa;/* '<S55>/MATLAB Function' */
  boolean_T isStable;                  /* '<S55>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S55>/MATLAB Function' */
} rtDW_MATLABFunction_controlle_o;

/* Block signals for system '<S28>/discrete kalman filter' */
typedef struct {
  real_T state_est[3];                 /* '<S28>/discrete kalman filter' */
  real_T P_est[9];                     /* '<S28>/discrete kalman filter' */
} rtB_discretekalmanfilter_contro;

/* Block states (auto storage) for system '<S28>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S28>/discrete kalman filter' */
  uint8_T is_active_c27_controller_templa;/* '<S28>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S28>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S28>/discrete kalman filter' */
} rtDW_discretekalmanfilter_contr;

/* Block signals for system '<S15>/Embedded MATLAB Function' */
typedef struct {
  real_T roll_rot;                     /* '<S15>/Embedded MATLAB Function' */
  real_T pitch_rot;                    /* '<S15>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S15>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S15>/Embedded MATLAB Function' */
} rtB_EmbeddedMATLABFunction_cont;

/* Block states (auto storage) for system '<S15>/Embedded MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S15>/Embedded MATLAB Function' */
  uint8_T is_active_c26_Hquad_control_LIB;/* '<S15>/Embedded MATLAB Function' */
  boolean_T isStable;                  /* '<S15>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S15>/Embedded MATLAB Function' */
} rtDW_EmbeddedMATLABFunction_con;

/* Block signals for system '<S136>/runFastGradient' */
typedef struct {
  real_T u_opt;                        /* '<S136>/runFastGradient' */
  real_T J_star;                       /* '<S136>/runFastGradient' */
  real_T u_buff_out[3];                /* '<S136>/runFastGradient' */
  real_T V_init_out[30];               /* '<S136>/runFastGradient' */
} rtB_runFastGradient_controller_;

/* Block states (auto storage) for system '<S136>/runFastGradient' */
typedef struct {
  int32_T sfEvent;                     /* '<S136>/runFastGradient' */
  uint8_T is_active_c6_Hquad_control_LIB_;/* '<S136>/runFastGradient' */
  boolean_T isStable;                  /* '<S136>/runFastGradient' */
  boolean_T doneDoubleBufferReInit;    /* '<S136>/runFastGradient' */
} rtDW_runFastGradient_controller;

/* Block signals for system '<S137>/discrete kalman filter' */
typedef struct {
  real_T state_est[4];                 /* '<S137>/discrete kalman filter' */
  real_T P_est[16];                    /* '<S137>/discrete kalman filter' */
} rtB_discretekalmanfilter_cont_h;

/* Block states (auto storage) for system '<S137>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S137>/discrete kalman filter' */
  uint8_T is_active_c11_Hquad_control_LIB;/* '<S137>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S137>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S137>/discrete kalman filter' */
} rtDW_discretekalmanfilter_con_c;

/* Block signals (auto storage) */
typedef struct {
  real_T Hi[4000];
  real_T Ki[1000];
  real_T DataTypeConversion[30];       /* '<S1>/Data Type Conversion' */
  real_T X_ref_x[93];                  /* '<Root>/Data Type Conversion2' */
  real_T X_ref_y[93];                  /* '<Root>/Data Type Conversion3' */
  real_T X_ref_z[62];                  /* '<Root>/Data Type Conversion1' */
  real_T X_ref_yaw[62];                /* '<Root>/Data Type Conversion' */
  real_T MultiportSwitch;              /* '<S6>/Multiport Switch' */
  real_T pitch_cmd;                    /* '<Root>/Switch1' */
  real_T roll_cmd;                     /* '<Root>/Switch1' */
  real_T SliderGain;                   /* '<S125>/Slider Gain' */
  real_T thrust_cmd;                   /* '<Root>/Switch1' */
  real_T yaw_rate_cmd;                 /* '<Root>/Switch1' */
  real_T pitch_bias;                   /* '<Root>/Switch1' */
  real_T roll_bias;                    /* '<Root>/Switch1' */
  real_T thrust_bias;                  /* '<Root>/Switch1' */
  real_T yaw_rate_bias;                /* '<Root>/Switch1' */
  real_T Gain[4];                      /* '<S134>/Gain' */
  real_T raddeg2[3];                   /* '<S134>/rad -> deg2' */
  real_T raddeg1[3];                   /* '<S134>/rad -> deg1' */
  real_T raddeg3[3];                   /* '<S134>/rad -> deg3' */
  real_T raddeg[4];                    /* '<S134>/rad -> deg' */
  real_T bias_W[4];                    /* '<S131>/bias_W' */
  real_T cmd_W[4];                     /* '<S131>/cmd_W' */
  real_T pitch_rot;                    /* '<S157>/Embedded MATLAB Function' */
  real_T roll_rot;                     /* '<S157>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S157>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S157>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp;               /* '<S156>/Embedded MATLAB Function' */
  real_T roll_cmd_comp;                /* '<S156>/Embedded MATLAB Function' */
  real_T thrust_comp;                  /* '<S156>/Embedded MATLAB Function' */
  real_T thrust_cmd_e;                 /* '<S130>/Sum5' */
  real_T u_opt;                        /* '<S142>/runFastGradient' */
  real_T J_star;                       /* '<S142>/runFastGradient' */
  real_T u_buff_out[2];                /* '<S142>/runFastGradient' */
  real_T V_init_out[30];               /* '<S142>/runFastGradient' */
  real_T u_opt_l;                      /* '<S140>/runFastGradient' */
  real_T J_star_h;                     /* '<S140>/runFastGradient' */
  real_T u_buff_out_i[6];              /* '<S140>/runFastGradient' */
  real_T V_init_out_n[30];             /* '<S140>/runFastGradient' */
  real_T Switch1;                      /* '<S94>/Switch1' */
  real_T Switch;                       /* '<S94>/Switch' */
  real_T UnitDelay1;                   /* '<S90>/Unit Delay1' */
  real_T x_ref;                        /* '<S12>/SwitchControl' */
  real_T y_ref;                        /* '<S12>/SwitchControl' */
  real_T z_ref;                        /* '<S12>/SwitchControl' */
  real_T Gain_p[18];                   /* '<S16>/Gain' */
  real_T raddeg2_p[3];                 /* '<S16>/rad -> deg2' */
  real_T raddeg1_e[2];                 /* '<S16>/rad -> deg1' */
  real_T x_dot_ref;                    /* '<S12>/SwitchControl' */
  real_T y_dot_ref;                    /* '<S12>/SwitchControl' */
  real_T raddeg3_a[3];                 /* '<S16>/rad -> deg3' */
  real_T raddeg_j[4];                  /* '<S16>/rad -> deg' */
  real_T z_dot_ref;                    /* '<S12>/SwitchControl' */
  real_T Sum[2];                       /* '<S90>/Sum' */
  real_T Gain_k[2];                    /* '<S90>/Gain' */
  real_T bias_W_b[4];                  /* '<S14>/bias_W' */
  real_T cmd_W_h[4];                   /* '<S14>/cmd_W' */
  real_T pitch_rot_n;                  /* '<S116>/Embedded MATLAB Function' */
  real_T roll_rot_e;                   /* '<S116>/Embedded MATLAB Function' */
  real_T pitch_bias_rot_i;             /* '<S116>/Embedded MATLAB Function' */
  real_T roll_bias_rot_d;              /* '<S116>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp_n;             /* '<S115>/Embedded MATLAB Function' */
  real_T roll_cmd_comp_j;              /* '<S115>/Embedded MATLAB Function' */
  real_T thrust_comp_k;                /* '<S115>/Embedded MATLAB Function' */
  real_T nominal_window_z_out;         /* '<S94>/MATLAB Function' */
  real_T nominal_window_y_out;         /* '<S94>/MATLAB Function' */
  real_T count_out;                    /* '<S93>/MATLAB Function' */
  real_T en;                           /* '<S90>/Next Ref' */
  real_T Gain2;                        /* '<S28>/Gain2' */
  real_T SwitchControl;                /* '<S37>/SwitchControl' */
  real_T RateTransition[4];            /* '<S35>/Rate Transition' */
  real_T UnitDelay2;                   /* '<S35>/Unit Delay2' */
  real_T RateTransition_l[4];          /* '<S34>/Rate Transition' */
  real_T UnitDelay2_p;                 /* '<S34>/Unit Delay2' */
  real_T Gain_pk;                      /* '<S39>/Gain' */
  real_T Sum_e;                        /* '<S23>/Sum' */
  real_T Saturation3;                  /* '<S26>/Saturation3' */
  real_T RateTransition_i[5];          /* '<S50>/Rate Transition' */
  real_T UnitDelay2_o;                 /* '<S50>/Unit Delay2' */
  real_T Gain_f;                       /* '<S51>/Gain' */
  real_T Saturation1;                  /* '<S29>/Saturation1' */
  real_T RateTransition_j[3];          /* '<S79>/Rate Transition' */
  real_T Gain_i;                       /* '<S80>/Gain' */
  real_T Sum_b;                        /* '<S27>/Sum' */
  real_T Gain_n;                       /* '<S68>/Gain' */
  real_T thrust_cmd_a;                 /* '<S11>/Sum5' */
  real_T RateTransition1;              /* '<S34>/Rate Transition1' */
  real_T RateTransition1_l;            /* '<S35>/Rate Transition1' */
  real_T RateTransition1_lq;           /* '<S50>/Rate Transition1' */
  real_T Gain_g;                       /* '<S27>/Gain' */
  real_T Gain1;                        /* '<S28>/Gain1' */
  real_T Gain_d;                       /* '<S28>/Gain' */
  real_T u_thrust_out;                 /* '<S82>/MATLAB Function' */
  real_T U;                            /* '<S79>/Ctrl_Xdir' */
  real_T flag_oob;                     /* '<S79>/Ctrl_Xdir' */
  real_T psi_prime;                    /* '<S28>/MATLAB Function' */
  real_T psi_out;                      /* '<S27>/MATLAB Function1' */
  real_T delta_x;                      /* '<S27>/MATLAB Function1' */
  real_T psi_prime_l;                  /* '<S27>/MATLAB Function' */
  real_T y;                            /* '<S74>/MATLAB Function' */
  real_T U_g;                          /* '<S65>/Ctrl_Xdir' */
  real_T flag_oob_l;                   /* '<S65>/Ctrl_Xdir' */
  real_T input_out;                    /* '<S54>/MATLAB Function' */
  real_T y_a[5];                       /* '<S58>/MATLAB Function' */
  real_T U_p;                          /* '<S50>/Ctrl_Xdir' */
  real_T flag_oob_o;                   /* '<S50>/Ctrl_Xdir' */
  real_T y_i[4];                       /* '<S45>/MATLAB Function' */
  real_T U_gb;                         /* '<S35>/Ctrl_Xdir' */
  real_T flag_oob_ow;                  /* '<S35>/Ctrl_Xdir' */
  real_T y_o[4];                       /* '<S42>/MATLAB Function' */
  real_T U_a;                          /* '<S34>/Ctrl_Xdir' */
  real_T flag_oob_l1;                  /* '<S34>/Ctrl_Xdir' */
  real_T pitch_cmd_out;                /* '<S23>/MATLAB Function' */
  rtB_EmbeddedMATLABFunction_cont sf_EmbeddedMATLABFunction_o;/* '<S133>/Embedded MATLAB Function' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_k;/* '<S143>/discrete kalman filter' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_n;/* '<S141>/discrete kalman filter' */
  rtB_discretekalmanfilter_cont_h sf_discretekalmanfilter_m;/* '<S139>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient_d;/* '<S138>/runFastGradient' */
  rtB_discretekalmanfilter_cont_h sf_discretekalmanfilter_b;/* '<S137>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient;/* '<S136>/runFastGradient' */
  rtB_EmbeddedMATLABFunction_cont sf_EmbeddedMATLABFunction;/* '<S15>/Embedded MATLAB Function' */
  rtB_MATLABFunction_controller_t sf_MATLABFunction_p;/* '<S118>/MATLAB Function' */
  rtB_generate_X_ref_z_controller sf_generate_X_ref_z;/* '<S98>/generate_X_ref_z' */
  rtB_generate_X_ref_yaw_controll sf_generate_X_ref_yaw;/* '<S98>/generate_X_ref_yaw' */
  rtB_generate_X_ref_y_controller sf_generate_X_ref_y;/* '<S98>/generate_X_ref_y' */
  rtB_generate_X_ref_x_controller sf_generate_X_ref_x;/* '<S98>/generate_X_ref_x' */
  rtB_MATLABFunction_controller_t sf_MATLABFunction;/* '<S97>/MATLAB Function' */
  rtB_MATLABFunction_controller_p sf_MATLABFunction_c;/* '<S83>/MATLAB Function' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter;/* '<S28>/discrete kalman filter' */
  rtB_MATLABFunction_controller_p sf_MATLABFunction_l5;/* '<S55>/MATLAB Function' */
  rtB_MATLABFunction_controller_t sf_MATLABFunction_e;/* '<S40>/MATLAB Function' */
  rtB_generate_X_ref_z_controller sf_generate_X_ref_z_l;/* '<S17>/generate_X_ref_z' */
  rtB_generate_X_ref_yaw_controll sf_generate_X_ref_yaw_g;/* '<S17>/generate_X_ref_yaw' */
  rtB_generate_X_ref_y_controller sf_generate_X_ref_y_a;/* '<S17>/generate_X_ref_y' */
  rtB_generate_X_ref_x_controller sf_generate_X_ref_x_k;/* '<S17>/generate_X_ref_x' */
} BlockIO_controller_template;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T FixPtUnitDelay1_DSTATE[4];    /* '<S129>/FixPt Unit Delay1' */
  real_T IntegerDelay_DSTATE;          /* '<S130>/Integer Delay' */
  real_T IntegerDelay1_DSTATE;         /* '<S130>/Integer Delay1' */
  real_T IntegerDelay2_DSTATE;         /* '<S130>/Integer Delay2' */
  real_T IntegerDelay3_DSTATE;         /* '<S130>/Integer Delay3' */
  real_T UnitDelay1_DSTATE[16];        /* '<S137>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i[3];  /* '<S145>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE[3];          /* '<S136>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c[30];      /* '<S136>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_b[16];      /* '<S139>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_g[3];  /* '<S148>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_j[3];        /* '<S138>/Unit Delay' */
  real_T UnitDelay1_DSTATE_l[30];      /* '<S138>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_j[9];       /* '<S143>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_d[2];  /* '<S154>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_l[2];        /* '<S142>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g[30];      /* '<S142>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_lx[9];      /* '<S141>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_e[2];  /* '<S151>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_jz[6];       /* '<S140>/Unit Delay' */
  real_T UnitDelay1_DSTATE_js[30];     /* '<S140>/Unit Delay1' */
  real_T UnitDelay_2_DSTATE;           /* '<S90>/Unit Delay' */
  real_T UnitDelay_3_DSTATE;           /* '<S90>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S90>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S98>/Unit Delay' */
  real_T UnitDelay_DSTATE_e;           /* '<S17>/Unit Delay' */
  real_T UnitDelay_DSTATE_es;          /* '<S93>/Unit Delay' */
  real_T UnitDelay1_DSTATE_o;          /* '<S93>/Unit Delay1' */
  real_T IntegerDelay3_DSTATE_k;       /* '<S11>/Integer Delay3' */
  real_T UnitDelay1_DSTATE_bg[9];      /* '<S28>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i1[2]; /* '<S77>/FixPt Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S35>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_m;          /* '<S34>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_d;          /* '<S39>/Unit Delay2' */
  real_T UnitDelay_DSTATE_jv;          /* '<S39>/Unit Delay' */
  real_T UnitDelay2_DSTATE_l;          /* '<S50>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_k;          /* '<S51>/Unit Delay2' */
  real_T UnitDelay_DSTATE_f;           /* '<S51>/Unit Delay' */
  real_T UnitDelay2_DSTATE_b;          /* '<S80>/Unit Delay2' */
  real_T UnitDelay_DSTATE_fw;          /* '<S80>/Unit Delay' */
  real_T UnitDelay_DSTATE_lg;          /* '<S27>/Unit Delay' */
  real_T UnitDelay2_DSTATE_g;          /* '<S65>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_ga;         /* '<S68>/Unit Delay2' */
  real_T UnitDelay_DSTATE_p;           /* '<S68>/Unit Delay' */
  real_T UnitDelay1_DSTATE_a;          /* '<S39>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_ji;         /* '<S51>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_c3;         /* '<S68>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_m;          /* '<S80>/Unit Delay1' */
  struct {
    void *LoggedData;
  } bias_PWORK;                        /* '<Root>/bias' */

  struct {
    void *LoggedData;
  } cmd_PWORK;                         /* '<Root>/cmd' */

  struct {
    void *LoggedData;
  } cmd1_PWORK;                        /* '<Root>/cmd1' */

  struct {
    void *LoggedData;
  } mode_PWORK;                        /* '<Root>/mode' */

  struct {
    void *LoggedData;
  } mode2_PWORK;                       /* '<Root>/mode2' */

  struct {
    void *LoggedData;
  } mode1_PWORK;                       /* '<S1>/mode1' */

  struct {
    void *LoggedData;
  } mode1_PWORK_h;                     /* '<S9>/mode1' */

  struct {
    void *FilePtr;
  } ToFile_PWORK;                      /* '<S134>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<S134>/To File1' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S134>/To Workspace' */

  struct {
    void *LoggedData;
  } pitchcmd_PWORK;                    /* '<S134>/pitch cmd' */

  struct {
    void *LoggedData;
  } rollcmd_PWORK;                     /* '<S134>/roll cmd' */

  struct {
    void *LoggedData;
  } thrustcmd_PWORK;                   /* '<S134>/thrust cmd' */

  struct {
    void *LoggedData;
  } x_ref_PWORK;                       /* '<S134>/x_ref' */

  struct {
    void *LoggedData;
  } y_ref_PWORK;                       /* '<S134>/y_ref' */

  struct {
    void *LoggedData;
  } yawcmd_PWORK;                      /* '<S134>/yaw cmd' */

  struct {
    void *LoggedData;
  } yaw_ref_PWORK;                     /* '<S134>/yaw_ref' */

  struct {
    void *LoggedData;
  } z_ref_PWORK;                       /* '<S134>/z_ref' */

  struct {
    void *FilePtr;
  } ToFile_PWORK_p;                    /* '<S16>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK_i;                   /* '<S16>/To File1' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_h;               /* '<S16>/To Workspace' */

  struct {
    void *LoggedData;
  } pitchcmd_PWORK_p;                  /* '<S16>/pitch cmd' */

  struct {
    void *LoggedData;
  } rollcmd_PWORK_i;                   /* '<S16>/roll cmd' */

  struct {
    void *LoggedData;
  } thrustcmd_PWORK_g;                 /* '<S16>/thrust cmd' */

  struct {
    void *LoggedData;
  } x_ref_PWORK_a;                     /* '<S16>/x_ref' */

  struct {
    void *LoggedData;
  } y_ref_PWORK_j;                     /* '<S16>/y_ref' */

  struct {
    void *LoggedData;
  } yawcmd_PWORK_p;                    /* '<S16>/yaw cmd' */

  struct {
    void *LoggedData;
  } yaw_ref_PWORK_n;                   /* '<S16>/yaw_ref' */

  struct {
    void *LoggedData;
  } z_ref_PWORK_e;                     /* '<S16>/z_ref' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S90>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     /* '<S94>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     /* '<S11>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     /* '<S23>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<S27>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S27>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_e;                     /* '<S28>/Scope' */

  int32_T sfEvent;                     /* '<S157>/Embedded MATLAB Function' */
  int32_T sfEvent_f;                   /* '<S156>/Embedded MATLAB Function' */
  int32_T sfEvent_k;                   /* '<S142>/runFastGradient' */
  int32_T sfEvent_n;                   /* '<S140>/runFastGradient' */
  int32_T sfEvent_j;                   /* '<S116>/Embedded MATLAB Function' */
  int32_T sfEvent_c;                   /* '<S115>/Embedded MATLAB Function' */
  int32_T sfEvent_a;                   /* '<S94>/MATLAB Function' */
  int32_T sfEvent_jg;                  /* '<S93>/MATLAB Function' */
  int32_T sfEvent_p;                   /* '<S90>/Next Ref' */
  int32_T sfEvent_jj;                  /* '<S82>/MATLAB Function' */
  int32_T sfEvent_k0;                  /* '<S79>/Ctrl_Xdir' */
  int32_T sfEvent_ks;                  /* '<S28>/MATLAB Function' */
  int32_T sfEvent_d;                   /* '<S27>/MATLAB Function1' */
  int32_T sfEvent_g;                   /* '<S27>/MATLAB Function' */
  int32_T sfEvent_l;                   /* '<S74>/MATLAB Function' */
  int32_T sfEvent_jv;                  /* '<S65>/Ctrl_Xdir' */
  int32_T sfEvent_ab;                  /* '<S54>/MATLAB Function' */
  int32_T sfEvent_i;                   /* '<S58>/MATLAB Function' */
  int32_T sfEvent_cd;                  /* '<S50>/Ctrl_Xdir' */
  int32_T sfEvent_ac;                  /* '<S45>/MATLAB Function' */
  int32_T sfEvent_cm;                  /* '<S35>/Ctrl_Xdir' */
  int32_T sfEvent_kd;                  /* '<S42>/MATLAB Function' */
  int32_T sfEvent_cr;                  /* '<S34>/Ctrl_Xdir' */
  int32_T sfEvent_fp;                  /* '<S23>/MATLAB Function' */
  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<S134>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<S134>/To File1' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK_g;                    /* '<S16>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK_p;                   /* '<S16>/To File1' */

  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S129>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_l;    /* '<S145>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_b;    /* '<S148>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S154>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S151>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_g;    /* '<S77>/FixPt Unit Delay2' */
  int8_T FreeFlightPosCtrl_SubsysRanBC;/* '<Root>/FreeFlight Pos Ctrl' */
  int8_T poscontroller_SubsysRanBC;    /* '<Root>/pos controller' */
  uint8_T is_active_c4_Hquad_control_LIB_;/* '<S157>/Embedded MATLAB Function' */
  uint8_T is_active_c1_Hquad_control_LIB_;/* '<S156>/Embedded MATLAB Function' */
  uint8_T is_active_c8_Hquad_control_LIB_;/* '<S142>/runFastGradient' */
  uint8_T is_active_c9_Hquad_control_LIB_;/* '<S140>/runFastGradient' */
  uint8_T is_active_c10_controller_templa;/* '<S116>/Embedded MATLAB Function' */
  uint8_T is_active_c9_controller_templat;/* '<S115>/Embedded MATLAB Function' */
  uint8_T is_active_c18_controller_templa;/* '<S94>/MATLAB Function' */
  uint8_T is_active_c11_controller_templa;/* '<S93>/MATLAB Function' */
  uint8_T is_active_c35_controller_templa;/* '<S90>/Next Ref' */
  uint8_T is_active_c16_controller_templa;/* '<S82>/MATLAB Function' */
  uint8_T is_active_c3_controller_templat;/* '<S79>/Ctrl_Xdir' */
  uint8_T is_active_c28_controller_templa;/* '<S28>/MATLAB Function' */
  uint8_T is_active_c30_controller_templa;/* '<S27>/MATLAB Function1' */
  uint8_T is_active_c25_controller_templa;/* '<S27>/MATLAB Function' */
  uint8_T is_active_c6_controller_templat;/* '<S74>/MATLAB Function' */
  uint8_T is_active_c4_controller_templat;/* '<S65>/Ctrl_Xdir' */
  uint8_T is_active_c17_controller_templa;/* '<S54>/MATLAB Function' */
  uint8_T is_active_c5_controller_templat;/* '<S58>/MATLAB Function' */
  uint8_T is_active_c2_controller_templat;/* '<S50>/Ctrl_Xdir' */
  uint8_T is_active_c7_controller_templat;/* '<S45>/MATLAB Function' */
  uint8_T is_active_c1_controller_templat;/* '<S35>/Ctrl_Xdir' */
  uint8_T is_active_c26_controller_templa;/* '<S42>/MATLAB Function' */
  uint8_T is_active_c24_controller_templa;/* '<S34>/Ctrl_Xdir' */
  uint8_T is_active_c12_controller_templa;/* '<S23>/MATLAB Function' */
  boolean_T isStable;                  /* '<S157>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S157>/Embedded MATLAB Function' */
  boolean_T isStable_m;                /* '<S156>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S156>/Embedded MATLAB Function' */
  boolean_T isStable_i;                /* '<S142>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_h;  /* '<S142>/runFastGradient' */
  boolean_T isStable_h;                /* '<S140>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_o;  /* '<S140>/runFastGradient' */
  boolean_T isStable_o;                /* '<S116>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S116>/Embedded MATLAB Function' */
  boolean_T isStable_mf;               /* '<S115>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_a;  /* '<S115>/Embedded MATLAB Function' */
  boolean_T isStable_g;                /* '<S94>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_ek; /* '<S94>/MATLAB Function' */
  boolean_T isStable_j;                /* '<S93>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_p;  /* '<S93>/MATLAB Function' */
  boolean_T isStable_od;               /* '<S90>/Next Ref' */
  boolean_T doneDoubleBufferReInit_em; /* '<S90>/Next Ref' */
  boolean_T isStable_g4;               /* '<S82>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_n;  /* '<S82>/MATLAB Function' */
  boolean_T isStable_c;                /* '<S79>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_ha; /* '<S79>/Ctrl_Xdir' */
  boolean_T isStable_hz;               /* '<S28>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_l;  /* '<S28>/MATLAB Function' */
  boolean_T isStable_f;                /* '<S27>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_g;  /* '<S27>/MATLAB Function1' */
  boolean_T isStable_a;                /* '<S27>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_ga; /* '<S27>/MATLAB Function' */
  boolean_T isStable_oc;               /* '<S74>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_m;  /* '<S74>/MATLAB Function' */
  boolean_T isStable_hg;               /* '<S65>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_pw; /* '<S65>/Ctrl_Xdir' */
  boolean_T isStable_oj;               /* '<S54>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_cz; /* '<S54>/MATLAB Function' */
  boolean_T isStable_n;                /* '<S58>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_b;  /* '<S58>/MATLAB Function' */
  boolean_T isStable_k;                /* '<S50>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S50>/Ctrl_Xdir' */
  boolean_T isStable_b;                /* '<S45>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_nz; /* '<S45>/MATLAB Function' */
  boolean_T isStable_hy;               /* '<S35>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_f;  /* '<S35>/Ctrl_Xdir' */
  boolean_T isStable_l;                /* '<S42>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_lo; /* '<S42>/MATLAB Function' */
  boolean_T isStable_ng;               /* '<S34>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_dn; /* '<S34>/Ctrl_Xdir' */
  boolean_T isStable_d;                /* '<S23>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_hm; /* '<S23>/MATLAB Function' */
  boolean_T FreeFlightPosCtrl_MODE;    /* '<Root>/FreeFlight Pos Ctrl' */
  boolean_T poscontroller_MODE;        /* '<Root>/pos controller' */
  rtDW_EmbeddedMATLABFunction_con sf_EmbeddedMATLABFunction_o;/* '<S133>/Embedded MATLAB Function' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_k;/* '<S143>/discrete kalman filter' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_n;/* '<S141>/discrete kalman filter' */
  rtDW_discretekalmanfilter_con_c sf_discretekalmanfilter_m;/* '<S139>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient_d;/* '<S138>/runFastGradient' */
  rtDW_discretekalmanfilter_con_c sf_discretekalmanfilter_b;/* '<S137>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient;/* '<S136>/runFastGradient' */
  rtDW_EmbeddedMATLABFunction_con sf_EmbeddedMATLABFunction;/* '<S15>/Embedded MATLAB Function' */
  rtDW_MATLABFunction_controller_ sf_MATLABFunction_p;/* '<S118>/MATLAB Function' */
  rtDW_generate_X_ref_z_controlle sf_generate_X_ref_z;/* '<S98>/generate_X_ref_z' */
  rtDW_generate_X_ref_yaw_control sf_generate_X_ref_yaw;/* '<S98>/generate_X_ref_yaw' */
  rtDW_generate_X_ref_y_controlle sf_generate_X_ref_y;/* '<S98>/generate_X_ref_y' */
  rtDW_generate_X_ref_x_controlle sf_generate_X_ref_x;/* '<S98>/generate_X_ref_x' */
  rtDW_MATLABFunction_controller_ sf_MATLABFunction;/* '<S97>/MATLAB Function' */
  rtDW_MATLABFunction_controlle_o sf_MATLABFunction_c;/* '<S83>/MATLAB Function' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter;/* '<S28>/discrete kalman filter' */
  rtDW_MATLABFunction_controlle_o sf_MATLABFunction_l5;/* '<S55>/MATLAB Function' */
  rtDW_MATLABFunction_controller_ sf_MATLABFunction_e;/* '<S40>/MATLAB Function' */
  rtDW_generate_X_ref_z_controlle sf_generate_X_ref_z_l;/* '<S17>/generate_X_ref_z' */
  rtDW_generate_X_ref_yaw_control sf_generate_X_ref_yaw_g;/* '<S17>/generate_X_ref_yaw' */
  rtDW_generate_X_ref_y_controlle sf_generate_X_ref_y_a;/* '<S17>/generate_X_ref_y' */
  rtDW_generate_X_ref_x_controlle sf_generate_X_ref_x_k;/* '<S17>/generate_X_ref_x' */
} D_Work_controller_template;

/* Parameters (auto storage) */
struct Parameters_controller_template_ {
  real_T Constant3_Value[8];           /* Expression: Bdd_pitch
                                        * Referenced by: '<S45>/Constant3'
                                        */
  real_T Constant1_Value[8];           /* Expression: Bff_pitch
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real_T Constant2_Value[16];          /* Expression: Add_pitch
                                        * Referenced by: '<S45>/Constant2'
                                        */
  real_T Constant_Value[16];           /* Expression: Aff_pitch
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S36>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S36>/Saturation3'
                                        */
  real_T Saturation3_UpperSat_j;       /* Expression: 0
                                        * Referenced by: '<S40>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_l;       /* Expression: -1
                                        * Referenced by: '<S40>/Saturation3'
                                        */
  real_T A_Value[9];                   /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S28>/A'
                                        */
  real_T B_Value[3];                   /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S28>/B'
                                        */
  real_T C_Value[6];                   /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S28>/C'
                                        */
  real_T D_Value[2];                   /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S28>/D'
                                        */
  real_T Q_Value[9];                   /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S28>/Q'
                                        */
  real_T R_Value[4];                   /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S28>/R'
                                        */
  real_T IntegerDelay3_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S11>/Integer Delay3'
                                         */
  real_T UnitDelay1_X0[9];             /* Expression: kalm_mpc_yaw.P
                                        * Referenced by: '<S28>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0;           /* Expression: 0.0
                                        * Referenced by: '<S77>/FixPt Unit Delay1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S28>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S28>/Saturation'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S28>/Gain2'
                                        */
  real_T gravity_Value;                /* Expression: g
                                        * Referenced by: '<S11>/gravity'
                                        */
  real_T Constant1_Value_m;            /* Expression: 1
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * Referenced by: '<S33>/Slider Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.017453292519943
                                        * Referenced by: '<S23>/Gain1'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 0.2094
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: -0.2094
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 2
                                        * Referenced by: '<S25>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -2
                                        * Referenced by: '<S25>/Saturation1'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T SliderGain_Gain_o;            /* Expression: gain
                                        * Referenced by: '<S48>/Slider Gain'
                                        */
  real_T Constant1_Value_f;            /* Expression: 1
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T SliderGain_Gain_b;            /* Expression: gain
                                        * Referenced by: '<S49>/Slider Gain'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S25>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S25>/Saturation2'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S35>/Unit Delay2'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 0.2094
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -0.2094
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real_T Saturation1_UpperSat_o;       /* Expression: 2
                                        * Referenced by: '<S45>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_d;       /* Expression: -2
                                        * Referenced by: '<S45>/Saturation1'
                                        */
  real_T Saturation3_UpperSat_c;       /* Expression: 0
                                        * Referenced by: '<S45>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_k;       /* Expression: -1
                                        * Referenced by: '<S45>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_a;       /* Expression: 1
                                        * Referenced by: '<S45>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_h;       /* Expression: -1
                                        * Referenced by: '<S45>/Saturation2'
                                        */
  real_T Constant_Value_l[9476];       /* Expression: Hn_Xdir
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Constant1_Value_fy[2369];     /* Expression: Kn_Xdir
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real_T Constant2_Value_m[1108];      /* Expression: Fi_Xdir
                                        * Referenced by: '<S35>/Constant2'
                                        */
  real_T Constat3_Value[277];          /* Expression: Gi_Xdir
                                        * Referenced by: '<S35>/Constat3'
                                        */
  real_T Constant4_Value[277];         /* Expression: Nc_Xdir
                                        * Referenced by: '<S35>/Constant4'
                                        */
  real_T Constant_Value_m[16];         /* Expression: Aff_pitch
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T Constant1_Value_a[8];         /* Expression: Bff_pitch
                                        * Referenced by: '<S42>/Constant1'
                                        */
  real_T UnitDelay2_X0_b;              /* Expression: 0
                                        * Referenced by: '<S34>/Unit Delay2'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: 0.2094
                                        * Referenced by: '<S42>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -0.2094
                                        * Referenced by: '<S42>/Saturation'
                                        */
  real_T Saturation1_UpperSat_p;       /* Expression: 2
                                        * Referenced by: '<S42>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_l;       /* Expression: -2
                                        * Referenced by: '<S42>/Saturation1'
                                        */
  real_T Saturation3_UpperSat_l;       /* Expression: 1
                                        * Referenced by: '<S42>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_lj;      /* Expression: -1
                                        * Referenced by: '<S42>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_k;       /* Expression: 1
                                        * Referenced by: '<S42>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_c;       /* Expression: -1
                                        * Referenced by: '<S42>/Saturation2'
                                        */
  real_T Constant5_Value[5660];        /* Expression: Hn_XdirFF
                                        * Referenced by: '<S34>/Constant5'
                                        */
  real_T Constant6_Value[1415];        /* Expression: Kn_XdirFF
                                        * Referenced by: '<S34>/Constant6'
                                        */
  real_T Constant7_Value[656];         /* Expression: Fi_XdirFF
                                        * Referenced by: '<S34>/Constant7'
                                        */
  real_T Constant8_Value[164];         /* Expression: Gi_XdirFF
                                        * Referenced by: '<S34>/Constant8'
                                        */
  real_T Constant9_Value[164];         /* Expression: Nc_XdirFF
                                        * Referenced by: '<S34>/Constant9'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 0.2094
                                        * Referenced by: '<S25>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -0.2094
                                        * Referenced by: '<S25>/Saturation4'
                                        */
  real_T UnitDelay2_X0_m;              /* Expression: 0
                                        * Referenced by: '<S39>/Unit Delay2'
                                        */
  real_T UnitDelay_X0;                 /* Expression: 0
                                        * Referenced by: '<S39>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: .33333
                                        * Referenced by: '<S39>/Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T SliderGain_Gain_g;            /* Expression: gain
                                        * Referenced by: '<S31>/Slider Gain'
                                        */
  real_T SliderGain_Gain_ba;           /* Expression: gain
                                        * Referenced by: '<S32>/Slider Gain'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 0.017453292519943
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Constant1_Value_d;            /* Expression: 1
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T SliderGain_Gain_j;            /* Expression: gain
                                        * Referenced by: '<S56>/Slider Gain'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 0.017453292519943
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 0.2094
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -0.2094
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real_T Saturation1_UpperSat_ou;      /* Expression: 2
                                        * Referenced by: '<S26>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_c;       /* Expression: -2
                                        * Referenced by: '<S26>/Saturation1'
                                        */
  real_T SliderGain_Gain_gm;           /* Expression: gain
                                        * Referenced by: '<S53>/Slider Gain'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T SliderGain_Gain_be;           /* Expression: gain
                                        * Referenced by: '<S52>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_n;       /* Expression: 1
                                        * Referenced by: '<S26>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_c;       /* Expression: -1
                                        * Referenced by: '<S26>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_b;       /* Expression: 1
                                        * Referenced by: '<S26>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_hu;      /* Expression: -1
                                        * Referenced by: '<S26>/Saturation2'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T SliderGain_Gain_p;            /* Expression: gain
                                        * Referenced by: '<S63>/Slider Gain'
                                        */
  real_T Constant1_Value_dx;           /* Expression: 1
                                        * Referenced by: '<S55>/Constant1'
                                        */
  real_T SliderGain_Gain_g3;           /* Expression: gain
                                        * Referenced by: '<S64>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_lg;      /* Expression: 0.1
                                        * Referenced by: '<S55>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_b;       /* Expression: -1
                                        * Referenced by: '<S55>/Saturation3'
                                        */
  real_T Constant_Value_co[25];        /* Expression: Aff_roll
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T Constant1_Value_g[10];        /* Expression: Bff_roll
                                        * Referenced by: '<S58>/Constant1'
                                        */
  real_T UnitDelay2_X0_d;              /* Expression: 0
                                        * Referenced by: '<S50>/Unit Delay2'
                                        */
  real_T Constant_Value_ln[16805];     /* Expression: Hn_Ydir
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T Constant1_Value_j[3361];      /* Expression: Kn_Ydir
                                        * Referenced by: '<S50>/Constant1'
                                        */
  real_T Constant2_Value_j[1590];      /* Expression: Fi_Ydir
                                        * Referenced by: '<S50>/Constant2'
                                        */
  real_T Constant3_Value_o[318];       /* Expression: Gi_Ydir
                                        * Referenced by: '<S50>/Constant3'
                                        */
  real_T Constant4_Value_g[318];       /* Expression: Nc_Ydir
                                        * Referenced by: '<S50>/Constant4'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T SliderGain_Gain_m;            /* Expression: gain
                                        * Referenced by: '<S61>/Slider Gain'
                                        */
  real_T Saturation4_UpperSat_i;       /* Expression: 0.2094
                                        * Referenced by: '<S26>/Saturation4'
                                        */
  real_T Saturation4_LowerSat_h;       /* Expression: -0.2094
                                        * Referenced by: '<S26>/Saturation4'
                                        */
  real_T UnitDelay2_X0_n;              /* Expression: 0
                                        * Referenced by: '<S51>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_f;               /* Expression: 0
                                        * Referenced by: '<S51>/Unit Delay'
                                        */
  real_T Gain_Gain_fn;                 /* Expression: .33333
                                        * Referenced by: '<S51>/Gain'
                                        */
  real_T Saturation1_UpperSat_d;       /* Expression: 1
                                        * Referenced by: '<S29>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -1
                                        * Referenced by: '<S29>/Saturation1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1
                                        * Referenced by: '<S29>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -1
                                        * Referenced by: '<S29>/Saturation'
                                        */
  real_T Constant_Value_fz;            /* Expression: 1
                                        * Referenced by: '<S83>/Constant'
                                        */
  real_T SliderGain_Gain_d;            /* Expression: gain
                                        * Referenced by: '<S88>/Slider Gain'
                                        */
  real_T Constant1_Value_l;            /* Expression: 1
                                        * Referenced by: '<S83>/Constant1'
                                        */
  real_T SliderGain_Gain_ds;           /* Expression: gain
                                        * Referenced by: '<S89>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_nh;      /* Expression: .1
                                        * Referenced by: '<S83>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_e;       /* Expression: -1
                                        * Referenced by: '<S83>/Saturation3'
                                        */
  real_T Constant_Value_b[624];        /* Expression: Hn_Zdir
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T Constant1_Value_li[208];      /* Expression: Kn_Zdir
                                        * Referenced by: '<S79>/Constant1'
                                        */
  real_T Constant2_Value_g[90];        /* Expression: Fi_Zdir
                                        * Referenced by: '<S79>/Constant2'
                                        */
  real_T Constant3_Value_m[30];        /* Expression: Gi_Zdir
                                        * Referenced by: '<S79>/Constant3'
                                        */
  real_T Constant4_Value_a[30];        /* Expression: Nc_Zdir
                                        * Referenced by: '<S79>/Constant4'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S82>/Constant'
                                        */
  real_T SliderGain_Gain_mb;           /* Expression: gain
                                        * Referenced by: '<S86>/Slider Gain'
                                        */
  real_T SliderGain_Gain_c;            /* Expression: gain
                                        * Referenced by: '<S81>/Slider Gain'
                                        */
  real_T Saturation2_UpperSat_kw;      /* Expression: 1
                                        * Referenced by: '<S29>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_j;       /* Expression: -1
                                        * Referenced by: '<S29>/Saturation2'
                                        */
  real_T UnitDelay2_X0_o;              /* Expression: 0
                                        * Referenced by: '<S80>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_i;               /* Expression: 0
                                        * Referenced by: '<S80>/Unit Delay'
                                        */
  real_T Gain_Gain_p;                  /* Expression: .33333
                                        * Referenced by: '<S80>/Gain'
                                        */
  real_T UnitDelay_X0_m;               /* Expression: 0
                                        * Referenced by: '<S27>/Unit Delay'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real_T SliderGain_Gain_a;            /* Expression: gain
                                        * Referenced by: '<S71>/Slider Gain'
                                        */
  real_T Constant2_Value_l;            /* Expression: 1
                                        * Referenced by: '<S27>/Constant2'
                                        */
  real_T SliderGain_Gain_pq;           /* Expression: gain
                                        * Referenced by: '<S72>/Slider Gain'
                                        */
  real_T SliderGain_Gain_ai;           /* Expression: gain
                                        * Referenced by: '<S70>/Slider Gain'
                                        */
  real_T Constant_Value_fv;            /* Expression: 1
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T SliderGain_Gain_jt;           /* Expression: gain
                                        * Referenced by: '<S69>/Slider Gain'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: pi
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -pi
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S74>/Constant'
                                        */
  real_T Constant1_Value_m3;           /* Expression: 0
                                        * Referenced by: '<S74>/Constant1'
                                        */
  real_T UnitDelay2_X0_ng;             /* Expression: 0
                                        * Referenced by: '<S65>/Unit Delay2'
                                        */
  real_T Constant_Value_a[6];          /* Expression: Hn_Yaw
                                        * Referenced by: '<S65>/Constant'
                                        */
  real_T Constant1_Value_gs[6];        /* Expression: Kn_Yaw
                                        * Referenced by: '<S65>/Constant1'
                                        */
  real_T Constant2_Value_jq[3];        /* Expression: Fi_Yaw
                                        * Referenced by: '<S65>/Constant2'
                                        */
  real_T Constant3_Value_b[3];         /* Expression: Gi_Yaw
                                        * Referenced by: '<S65>/Constant3'
                                        */
  real_T Constant4_Value_gb[3];        /* Expression: Nc_Yaw
                                        * Referenced by: '<S65>/Constant4'
                                        */
  real_T Saturation1_UpperSat_g;       /* Expression: pi
                                        * Referenced by: '<S27>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_b;       /* Expression: -pi
                                        * Referenced by: '<S27>/Saturation1'
                                        */
  real_T UnitDelay2_X0_i;              /* Expression: 0
                                        * Referenced by: '<S68>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_c;               /* Expression: 0
                                        * Referenced by: '<S68>/Unit Delay'
                                        */
  real_T Gain_Gain_p0;                 /* Expression: .33333
                                        * Referenced by: '<S68>/Gain'
                                        */
  real_T UnitDelay1_X0_i;              /* Expression: 0
                                        * Referenced by: '<S39>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_d;              /* Expression: 0
                                        * Referenced by: '<S51>/Unit Delay1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 57
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T UnitDelay1_X0_j;              /* Expression: 0
                                        * Referenced by: '<S68>/Unit Delay1'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 57
                                        * Referenced by: '<S28>/Gain1'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 57
                                        * Referenced by: '<S28>/Gain'
                                        */
  real_T UnitDelay1_X0_f;              /* Expression: 0
                                        * Referenced by: '<S80>/Unit Delay1'
                                        */
  real_T g_Value;                      /* Expression: g
                                        * Referenced by: '<S115>/g'
                                        */
  real_T Constant_Value_ks;            /* Expression: 1
                                        * Referenced by: '<S118>/Constant'
                                        */
  real_T SliderGain_Gain_n;            /* Expression: gain
                                        * Referenced by: '<S120>/Slider Gain'
                                        */
  real_T Constant1_Value_i;            /* Expression: 1
                                        * Referenced by: '<S118>/Constant1'
                                        */
  real_T SliderGain_Gain_i;            /* Expression: gain
                                        * Referenced by: '<S121>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_p;       /* Expression: 0
                                        * Referenced by: '<S118>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_es;      /* Expression: -1
                                        * Referenced by: '<S118>/Saturation3'
                                        */
  real_T X_ref_x_Value[909];           /* Expression: traj_FG.X_ref_x
                                        * Referenced by: '<S98>/X_ref_x'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S97>/Constant'
                                        */
  real_T SliderGain_Gain_e;            /* Expression: gain
                                        * Referenced by: '<S109>/Slider Gain'
                                        */
  real_T Constant1_Value_e;            /* Expression: 1
                                        * Referenced by: '<S97>/Constant1'
                                        */
  real_T SliderGain_Gain_jr;           /* Expression: gain
                                        * Referenced by: '<S110>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_f;       /* Expression: 0
                                        * Referenced by: '<S97>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_lw;      /* Expression: -1
                                        * Referenced by: '<S97>/Saturation3'
                                        */
  real_T UnitDelay_2_X0;               /* Expression: 0
                                        * Referenced by: '<S90>/Unit Delay'
                                        */
  real_T UnitDelay_3_X0;               /* Expression: 0
                                        * Referenced by: '<S90>/Unit Delay'
                                        */
  real_T Constant1_Value_j2;           /* Expression: 1
                                        * Referenced by: '<S90>/Constant1'
                                        */
  real_T SliderGain_Gain_db;           /* Expression: gain
                                        * Referenced by: '<S96>/Slider Gain'
                                        */
  real_T Constant_Value_le;            /* Expression: 1
                                        * Referenced by: '<S90>/Constant'
                                        */
  real_T SliderGain_Gain_ne;           /* Expression: gain
                                        * Referenced by: '<S95>/Slider Gain'
                                        */
  real_T Constant_Value_kb;            /* Expression: 1
                                        * Referenced by: '<S94>/Constant'
                                        */
  real_T SliderGain_Gain_dsh;          /* Expression: gain
                                        * Referenced by: '<S103>/Slider Gain'
                                        */
  real_T SliderGain_Gain_cx;           /* Expression: gain
                                        * Referenced by: '<S104>/Slider Gain'
                                        */
  real_T Constant1_Value_kj;           /* Expression: 1
                                        * Referenced by: '<S94>/Constant1'
                                        */
  real_T SliderGain_Gain_mi;           /* Expression: gain
                                        * Referenced by: '<S105>/Slider Gain'
                                        */
  real_T Constant2_Value_c;            /* Expression: 1
                                        * Referenced by: '<S94>/Constant2'
                                        */
  real_T SliderGain_Gain_nu;           /* Expression: gain
                                        * Referenced by: '<S106>/Slider Gain'
                                        */
  real_T Constant3_Value_f;            /* Expression: 1
                                        * Referenced by: '<S94>/Constant3'
                                        */
  real_T SliderGain_Gain_k;            /* Expression: gain
                                        * Referenced by: '<S107>/Slider Gain'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S94>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S94>/Switch'
                                        */
  real_T SliderGain_Gain_h;            /* Expression: gain
                                        * Referenced by: '<S92>/Slider Gain'
                                        */
  real_T TotalSamples_Value;           /* Expression: traj_FG.total_samples -1
                                        * Referenced by: '<S90>/Total Samples'
                                        */
  real_T UnitDelay1_X0_ie;             /* Expression: 0
                                        * Referenced by: '<S90>/Unit Delay1'
                                        */
  real_T UnitDelay_X0_o;               /* Expression: 0
                                        * Referenced by: '<S98>/Unit Delay'
                                        */
  real_T total_samples_Value;          /* Expression: traj_FG.total_samples
                                        * Referenced by: '<S98>/total_samples'
                                        */
  real_T Constant1_Value_mu;           /* Expression: 1
                                        * Referenced by: '<S98>/Constant1'
                                        */
  real_T X_ref_x_Value_k[909];         /* Expression: traj_FG.X_ref_x
                                        * Referenced by: '<S17>/X_ref_x'
                                        */
  real_T Constant_Value_kh;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T UnitDelay_X0_b;               /* Expression: 0
                                        * Referenced by: '<S17>/Unit Delay'
                                        */
  real_T total_samples_Value_k;        /* Expression: traj_FG.total_samples
                                        * Referenced by: '<S17>/total_samples'
                                        */
  real_T Constant1_Value_h;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T X_ref_y_Value[909];           /* Expression: traj_FG.X_ref_y
                                        * Referenced by: '<S98>/X_ref_y'
                                        */
  real_T X_ref_y_Value_e[909];         /* Expression: traj_FG.X_ref_y
                                        * Referenced by: '<S17>/X_ref_y'
                                        */
  real_T X_ref_z_Value[606];           /* Expression: traj_FG.X_ref_z
                                        * Referenced by: '<S98>/X_ref_z'
                                        */
  real_T X_ref_z_Value_a[606];         /* Expression: traj_FG.X_ref_z
                                        * Referenced by: '<S17>/X_ref_z'
                                        */
  real_T X_ref_yaw_Value[606];         /* Expression: traj_FG.X_ref_yaw
                                        * Referenced by: '<S98>/X_ref_yaw'
                                        */
  real_T X_ref_yaw_Value_f[606];       /* Expression: traj_FG.X_ref_yaw
                                        * Referenced by: '<S17>/X_ref_yaw'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 1
                                        * Referenced by: '<S16>/Gain'
                                        */
  real_T raddeg2_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S16>/rad -> deg2'
                                        */
  real_T raddeg1_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S16>/rad -> deg1'
                                        */
  real_T raddeg3_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S16>/rad -> deg3'
                                        */
  real_T raddeg_Gain;                  /* Expression: 180/pi
                                        * Referenced by: '<S16>/rad -> deg'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -1
                                        * Referenced by: '<S90>/Gain'
                                        */
  real_T UnitDelay_X0_l;               /* Expression: 0
                                        * Referenced by: '<S93>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_js;             /* Expression: 0
                                        * Referenced by: '<S93>/Unit Delay1'
                                        */
  real_T yaw_rate_bias_Value;          /* Expression: 0
                                        * Referenced by: '<S3>/yaw_rate_bias'
                                        */
  real_T thrust_bias_Value;            /* Expression: 0
                                        * Referenced by: '<S3>/thrust_bias'
                                        */
  real_T roll_bias_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/roll_bias'
                                        */
  real_T pitch_bias_Value;             /* Expression: 0
                                        * Referenced by: '<S3>/pitch_bias'
                                        */
  real_T yaw_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/yaw'
                                        */
  real_T gravity_Value_c;              /* Expression: -g
                                        * Referenced by: '<S3>/- gravity'
                                        */
  real_T roll_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/roll'
                                        */
  real_T pitch_Value;                  /* Expression: 0
                                        * Referenced by: '<S3>/pitch'
                                        */
  real_T yaw_rate_Value;               /* Expression: 0
                                        * Referenced by: '<S7>/yaw_rate'
                                        */
  real_T yaw_cmd2yaw_Gain;             /* Expression: yaw_cmd2yaw_1stOrd
                                        * Referenced by: '<S7>/yaw_cmd2yaw'
                                        */
  real_T IntegerDelay_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<S130>/Integer Delay'
                                        */
  real_T IntegerDelay1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S130>/Integer Delay1'
                                         */
  real_T IntegerDelay2_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S130>/Integer Delay2'
                                         */
  real_T IntegerDelay3_InitialConditio_c;/* Expression: 0.0
                                          * Referenced by: '<S130>/Integer Delay3'
                                          */
  real_T gravity_Value_j;              /* Expression: g
                                        * Referenced by: '<S130>/gravity'
                                        */
  real_T TT_PP_Value[900];             /* Expression: FG_ctrl_x.TT_PP
                                        * Referenced by: '<S136>/TT_PP'
                                        */
  real_T LL_PP_Value[90];              /* Expression: FG_ctrl_x.LL_PP
                                        * Referenced by: '<S136>/LL_PP'
                                        */
  real_T LL_ref_PP_Value[2790];        /* Expression: FG_ctrl_x.LL_ref_PP
                                        * Referenced by: '<S136>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value[900];       /* Expression: FG_ctrl_x.LL_U_ref_PP
                                        * Referenced by: '<S136>/LL_U_ref_PP'
                                        */
  real_T MM_Value[9];                  /* Expression: FG_ctrl_x.MM
                                        * Referenced by: '<S136>/MM'
                                        */
  real_T PP_Value[900];                /* Expression: FG_ctrl_x.PP
                                        * Referenced by: '<S136>/PP'
                                        */
  real_T AA_delay_Value[9];            /* Expression: FG_ctrl_x.AA_delay
                                        * Referenced by: '<S136>/AA_delay'
                                        */
  real_T BB_delay_Value[9];            /* Expression: FG_ctrl_x.BB_delay
                                        * Referenced by: '<S136>/BB_delay'
                                        */
  real_T A_Value_h[16];                /* Expression: kalm_mpc_x.A
                                        * Referenced by: '<S137>/A'
                                        */
  real_T B_Value_i[4];                 /* Expression: kalm_mpc_x.B
                                        * Referenced by: '<S137>/B'
                                        */
  real_T C_Value_c[12];                /* Expression: kalm_mpc_x.C
                                        * Referenced by: '<S137>/C'
                                        */
  real_T D_Value_l[3];                 /* Expression: kalm_mpc_x.D
                                        * Referenced by: '<S137>/D'
                                        */
  real_T Q_Value_a[16];                /* Expression: kalm_mpc_x.Q
                                        * Referenced by: '<S137>/Q'
                                        */
  real_T R_Value_c[9];                 /* Expression: kalm_mpc_x.R
                                        * Referenced by: '<S137>/R'
                                        */
  real_T UnitDelay1_X0_c[16];          /* Expression: kalm_mpc_x.P
                                        * Referenced by: '<S137>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_f;         /* Expression: 0.0
                                        * Referenced by: '<S145>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value[30];              /* Expression: FG_ctrl_x.V_max
                                        * Referenced by: '<S136>/V_max'
                                        */
  real_T i_min_Value;                  /* Expression: FG_ctrl_x.i_min
                                        * Referenced by: '<S136>/i_min'
                                        */
  real_T betas_Value[7];               /* Expression: FG_ctrl_x.betas
                                        * Referenced by: '<S136>/betas'
                                        */
  real_T L_Value;                      /* Expression: FG_ctrl_x.L
                                        * Referenced by: '<S136>/L'
                                        */
  real_T UnitDelay_X0_fc[3];           /* Expression: zeros(FG_ctrl_x.delay_steps,1)
                                        * Referenced by: '<S136>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_k[30];          /* Expression: zeros(size(FG_ctrl_x.V_max,1),1)
                                        * Referenced by: '<S136>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_ia;       /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S137>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S137>/Saturation'
                                        */
  real_T TT_PP_Value_m[900];           /* Expression: FG_ctrl_y.TT_PP
                                        * Referenced by: '<S138>/TT_PP'
                                        */
  real_T LL_PP_Value_e[90];            /* Expression: FG_ctrl_y.LL_PP
                                        * Referenced by: '<S138>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_l[2790];      /* Expression: FG_ctrl_y.LL_ref_PP
                                        * Referenced by: '<S138>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_m[900];     /* Expression: FG_ctrl_y.LL_U_ref_PP
                                        * Referenced by: '<S138>/LL_U_ref_PP'
                                        */
  real_T MM_Value_c[9];                /* Expression: FG_ctrl_y.MM
                                        * Referenced by: '<S138>/MM'
                                        */
  real_T PP_Value_m[900];              /* Expression: FG_ctrl_y.PP
                                        * Referenced by: '<S138>/PP'
                                        */
  real_T AA_delay_Value_h[9];          /* Expression: FG_ctrl_y.AA_delay
                                        * Referenced by: '<S138>/AA_delay'
                                        */
  real_T BB_delay_Value_o[9];          /* Expression: FG_ctrl_y.BB_delay
                                        * Referenced by: '<S138>/BB_delay'
                                        */
  real_T A_Value_n[16];                /* Expression: kalm_mpc_y.A
                                        * Referenced by: '<S139>/A'
                                        */
  real_T B_Value_h[4];                 /* Expression: kalm_mpc_y.B
                                        * Referenced by: '<S139>/B'
                                        */
  real_T C_Value_p[12];                /* Expression: kalm_mpc_y.C
                                        * Referenced by: '<S139>/C'
                                        */
  real_T D_Value_m[3];                 /* Expression: kalm_mpc_y.D
                                        * Referenced by: '<S139>/D'
                                        */
  real_T Q_Value_h[16];                /* Expression: kalm_mpc_y.Q
                                        * Referenced by: '<S139>/Q'
                                        */
  real_T R_Value_l[9];                 /* Expression: kalm_mpc_y.R
                                        * Referenced by: '<S139>/R'
                                        */
  real_T UnitDelay1_X0_fk[16];         /* Expression: kalm_mpc_y.P
                                        * Referenced by: '<S139>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_n;         /* Expression: 0.0
                                        * Referenced by: '<S148>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_o[30];            /* Expression: FG_ctrl_y.V_max
                                        * Referenced by: '<S138>/V_max'
                                        */
  real_T i_min_Value_j;                /* Expression: FG_ctrl_y.i_min
                                        * Referenced by: '<S138>/i_min'
                                        */
  real_T betas_Value_l[7];             /* Expression: FG_ctrl_y.betas
                                        * Referenced by: '<S138>/betas'
                                        */
  real_T L_Value_n;                    /* Expression: FG_ctrl_y.L
                                        * Referenced by: '<S138>/L'
                                        */
  real_T UnitDelay_X0_ik[3];           /* Expression: zeros(FG_ctrl_y.delay_steps,1)
                                        * Referenced by: '<S138>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_jc[30];         /* Expression: zeros(size(FG_ctrl_y.V_max,1),1)
                                        * Referenced by: '<S138>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S139>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S139>/Saturation'
                                        */
  real_T TT_PP_Value_b[900];           /* Expression: FG_ctrl_z.TT_PP
                                        * Referenced by: '<S142>/TT_PP'
                                        */
  real_T LL_PP_Value_j[60];            /* Expression: FG_ctrl_z.LL_PP
                                        * Referenced by: '<S142>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_h[1860];      /* Expression: FG_ctrl_z.LL_ref_PP
                                        * Referenced by: '<S142>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_o[900];     /* Expression: FG_ctrl_z.LL_U_ref_PP
                                        * Referenced by: '<S142>/LL_U_ref_PP'
                                        */
  real_T MM_Value_l[4];                /* Expression: FG_ctrl_z.MM
                                        * Referenced by: '<S142>/MM'
                                        */
  real_T PP_Value_o[900];              /* Expression: FG_ctrl_z.PP
                                        * Referenced by: '<S142>/PP'
                                        */
  real_T AA_delay_Value_l[4];          /* Expression: FG_ctrl_z.AA_delay
                                        * Referenced by: '<S142>/AA_delay'
                                        */
  real_T BB_delay_Value_b[4];          /* Expression: FG_ctrl_z.BB_delay
                                        * Referenced by: '<S142>/BB_delay'
                                        */
  real_T A_Value_f[9];                 /* Expression: kalm_mpc_z.A
                                        * Referenced by: '<S143>/A'
                                        */
  real_T B_Value_n[3];                 /* Expression: kalm_mpc_z.B
                                        * Referenced by: '<S143>/B'
                                        */
  real_T C_Value_o[6];                 /* Expression: kalm_mpc_z.C
                                        * Referenced by: '<S143>/C'
                                        */
  real_T D_Value_j[2];                 /* Expression: kalm_mpc_z.D
                                        * Referenced by: '<S143>/D'
                                        */
  real_T Q_Value_j[9];                 /* Expression: kalm_mpc_z.Q
                                        * Referenced by: '<S143>/Q'
                                        */
  real_T R_Value_ca[4];                /* Expression: kalm_mpc_z.R
                                        * Referenced by: '<S143>/R'
                                        */
  real_T UnitDelay1_X0_cw[9];          /* Expression: kalm_mpc_z.P
                                        * Referenced by: '<S143>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_c;         /* Expression: 0.0
                                        * Referenced by: '<S154>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_i[30];            /* Expression: FG_ctrl_z.V_max
                                        * Referenced by: '<S142>/V_max'
                                        */
  real_T i_min_Value_o;                /* Expression: FG_ctrl_z.i_min
                                        * Referenced by: '<S142>/i_min'
                                        */
  real_T betas_Value_g[8];             /* Expression: FG_ctrl_z.betas
                                        * Referenced by: '<S142>/betas'
                                        */
  real_T L_Value_m;                    /* Expression: FG_ctrl_z.L
                                        * Referenced by: '<S142>/L'
                                        */
  real_T UnitDelay_X0_a[2];            /* Expression: zeros(FG_ctrl_z.delay_steps,1)
                                        * Referenced by: '<S142>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_b[30];          /* Expression: zeros(size(FG_ctrl_z.V_max,1),1)
                                        * Referenced by: '<S142>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: MAX_BIAS_THRUST
                                        * Referenced by: '<S143>/Saturation'
                                        */
  real_T Saturation_LowerSat_cp;       /* Expression: -MAX_BIAS_THRUST
                                        * Referenced by: '<S143>/Saturation'
                                        */
  real_T TT_PP_Value_o[900];           /* Expression: FG_ctrl_yaw.TT_PP
                                        * Referenced by: '<S140>/TT_PP'
                                        */
  real_T LL_PP_Value_j5[60];           /* Expression: FG_ctrl_yaw.LL_PP
                                        * Referenced by: '<S140>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_e[1860];      /* Expression: FG_ctrl_yaw.LL_ref_PP
                                        * Referenced by: '<S140>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_b[900];     /* Expression: FG_ctrl_yaw.LL_U_ref_PP
                                        * Referenced by: '<S140>/LL_U_ref_PP'
                                        */
  real_T MM_Value_g[4];                /* Expression: FG_ctrl_yaw.MM
                                        * Referenced by: '<S140>/MM'
                                        */
  real_T PP_Value_p[900];              /* Expression: FG_ctrl_yaw.PP
                                        * Referenced by: '<S140>/PP'
                                        */
  real_T AA_delay_Value_o[4];          /* Expression: FG_ctrl_yaw.AA_delay
                                        * Referenced by: '<S140>/AA_delay'
                                        */
  real_T BB_delay_Value_d[12];         /* Expression: FG_ctrl_yaw.BB_delay
                                        * Referenced by: '<S140>/BB_delay'
                                        */
  real_T A_Value_k[9];                 /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S141>/A'
                                        */
  real_T B_Value_f[3];                 /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S141>/B'
                                        */
  real_T C_Value_b[6];                 /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S141>/C'
                                        */
  real_T D_Value_c[2];                 /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S141>/D'
                                        */
  real_T Q_Value_g[9];                 /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S141>/Q'
                                        */
  real_T R_Value_o[4];                 /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S141>/R'
                                        */
  real_T UnitDelay1_X0_n[9];           /* Expression: kalm_mpc_yaw.P
                                        * Referenced by: '<S141>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_e;         /* Expression: 0.0
                                        * Referenced by: '<S151>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_f[30];            /* Expression: FG_ctrl_yaw.V_max
                                        * Referenced by: '<S140>/V_max'
                                        */
  real_T i_min_Value_n;                /* Expression: FG_ctrl_yaw.i_min
                                        * Referenced by: '<S140>/i_min'
                                        */
  real_T betas_Value_j[5];             /* Expression: FG_ctrl_yaw.betas
                                        * Referenced by: '<S140>/betas'
                                        */
  real_T L_Value_g;                    /* Expression: FG_ctrl_yaw.L
                                        * Referenced by: '<S140>/L'
                                        */
  real_T UnitDelay_X0_fj[6];           /* Expression: zeros(FG_ctrl_yaw.delay_steps,1)
                                        * Referenced by: '<S140>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_o[30];          /* Expression: zeros(size(FG_ctrl_yaw.V_max,1),1)
                                        * Referenced by: '<S140>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_o3;       /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S141>/Saturation'
                                        */
  real_T Saturation_LowerSat_kn;       /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S141>/Saturation'
                                        */
  real_T g_Value_m;                    /* Expression: g
                                        * Referenced by: '<S156>/g'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 1
                                        * Referenced by: '<S134>/Gain'
                                        */
  real_T raddeg2_Gain_p;               /* Expression: 180/pi
                                        * Referenced by: '<S134>/rad -> deg2'
                                        */
  real_T raddeg1_Gain_a;               /* Expression: 180/pi
                                        * Referenced by: '<S134>/rad -> deg1'
                                        */
  real_T raddeg3_Gain_k;               /* Expression: 180/pi
                                        * Referenced by: '<S134>/rad -> deg3'
                                        */
  real_T raddeg_Gain_k;                /* Expression: 180/pi
                                        * Referenced by: '<S134>/rad -> deg'
                                        */
  real_T pitch_offset_Value;           /* Expression: 0.00
                                        * Referenced by: '<S7>/pitch_offset'
                                        */
  real_T InitialCondition_Value;       /* Expression: vinit
                                        * Referenced by: '<S129>/Initial Condition'
                                        */
  real_T Constant1_Value_mr;           /* Expression: 1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T FixPtUnitDelay1_X0_h;         /* Expression: vinit
                                        * Referenced by: '<S129>/FixPt Unit Delay1'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T pitch_cmd2pitch_Gain;         /* Expression: pitch_cmd2pitch_1stOrd
                                        * Referenced by: '<S7>/pitch_cmd2pitch'
                                        */
  real_T Gain1_Gain_eg;                /* Expression: -1.0
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T roll_offset_Value;            /* Expression: 0.00
                                        * Referenced by: '<S7>/roll_offset'
                                        */
  real_T roll_cmd2roll_Gain;           /* Expression: roll_cmd2roll_1stOrd
                                        * Referenced by: '<S7>/roll_cmd2roll'
                                        */
  real_T Gain2_Gain_a;                 /* Expression: -1
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T gravity_Value_ch;             /* Expression: g
                                        * Referenced by: '<S7>/gravity'
                                        */
  real_T Constant_Value_lf;            /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T SliderGain_Gain_px;           /* Expression: gain
                                        * Referenced by: '<S126>/Slider Gain'
                                        */
  real_T Gain5_Gain;                   /* Expression: -1
                                        * Referenced by: '<S7>/Gain5'
                                        */
  real_T Constant1_Value_ih;           /* Expression: 1.1
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Saturation_UpperSat_pb;       /* Expression: 0.7
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: 0
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T SliderGain_Gain_o4;           /* Expression: gain
                                        * Referenced by: '<S125>/Slider Gain'
                                        */
  real_T trhust_cmd2thrust_Gain;       /* Expression: thrust_cmd2thrust_0thOrd
                                        * Referenced by: '<S7>/trhust_cmd2thrust'
                                        */
  real_T Gain_Gain_k;                  /* Expression: THRUST_CMD_GAIN
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1.0
                                        * Referenced by: '<S7>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1.0
                                        * Referenced by: '<S7>/Gain4'
                                        */
  uint32_T IntegerDelay3_DelayLength;  /* Computed Parameter: IntegerDelay3_DelayLength
                                        * Referenced by: '<S11>/Integer Delay3'
                                        */
  uint32_T IntegerDelay_DelayLength;   /* Computed Parameter: IntegerDelay_DelayLength
                                        * Referenced by: '<S130>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength;  /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S130>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength;  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S130>/Integer Delay2'
                                        */
  uint32_T IntegerDelay3_DelayLength_o;/* Computed Parameter: IntegerDelay3_DelayLength_o
                                        * Referenced by: '<S130>/Integer Delay3'
                                        */
  uint8_T FixPtUnitDelay2_X0;          /* Computed Parameter: FixPtUnitDelay2_X0
                                        * Referenced by: '<S77>/FixPt Unit Delay2'
                                        */
  uint8_T Constant_Value_lw;           /* Expression: uint8(1)
                                        * Referenced by: '<S37>/Constant'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(0)
                                        * Referenced by: '<S37>/SwitchControl'
                                        */
  uint8_T Constant_Value_j;            /* Expression: uint8(1)
                                        * Referenced by: '<S38>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_a;   /* Expression: uint8(0)
                                        * Referenced by: '<S38>/SwitchControl'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S77>/FixPt Constant'
                                        */
  uint8_T Constant_Value_ph;           /* Expression: uint8(1)
                                        * Referenced by: '<S12>/Constant'
                                        */
  uint8_T SwitchControl_1_Threshold;   /* Expression: uint8(0)
                                        * Referenced by: '<S12>/SwitchControl'
                                        */
  uint8_T SwitchControl_2_Threshold;   /* Expression: uint8(0)
                                        * Referenced by: '<S12>/SwitchControl'
                                        */
  uint8_T SwitchControl_3_Threshold;   /* Expression: uint8(0)
                                        * Referenced by: '<S12>/SwitchControl'
                                        */
  uint8_T SwitchControl_4_Threshold;   /* Expression: uint8(0)
                                        * Referenced by: '<S12>/SwitchControl'
                                        */
  uint8_T SwitchControl_5_Threshold;   /* Expression: uint8(0)
                                        * Referenced by: '<S12>/SwitchControl'
                                        */
  uint8_T SwitchControl_6_Threshold;   /* Expression: uint8(0)
                                        * Referenced by: '<S12>/SwitchControl'
                                        */
  uint8_T SwitchControl_8_Threshold;   /* Expression: uint8(0)
                                        * Referenced by: '<S12>/SwitchControl'
                                        */
  uint8_T SwitchControl_7_Threshold;   /* Expression: uint8(0)
                                        * Referenced by: '<S12>/SwitchControl'
                                        */
  uint8_T FixPtUnitDelay2_X0_d;        /* Computed Parameter: FixPtUnitDelay2_X0_d
                                        * Referenced by: '<S145>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_n;        /* Computed Parameter: FixPtUnitDelay2_X0_n
                                        * Referenced by: '<S148>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_do;       /* Computed Parameter: FixPtUnitDelay2_X0_do
                                        * Referenced by: '<S154>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_i;        /* Computed Parameter: FixPtUnitDelay2_X0_i
                                        * Referenced by: '<S151>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtConstant_Value_h;       /* Computed Parameter: FixPtConstant_Value_h
                                        * Referenced by: '<S145>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_o;       /* Computed Parameter: FixPtConstant_Value_o
                                        * Referenced by: '<S148>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_n;       /* Computed Parameter: FixPtConstant_Value_n
                                        * Referenced by: '<S151>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_p;       /* Computed Parameter: FixPtConstant_Value_p
                                        * Referenced by: '<S154>/FixPt Constant'
                                        */
  uint8_T FixPtUnitDelay2_X0_g;        /* Computed Parameter: FixPtUnitDelay2_X0_g
                                        * Referenced by: '<S129>/FixPt Unit Delay2'
                                        */
  uint8_T Constant_Value_he;           /* Expression: uint8(1)
                                        * Referenced by: '<S5>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_e;   /* Expression: uint8(1)
                                        * Referenced by: '<S5>/SwitchControl'
                                        */
  uint8_T Constant_Value_nk;           /* Expression: uint8(1)
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_b;   /* Expression: uint8(1)
                                        * Referenced by: '<S4>/SwitchControl'
                                        */
  uint8_T Constant_Value_a3;           /* Expression: uint8(1)
                                        * Referenced by: '<S124>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_ef;  /* Expression: uint8(0)
                                        * Referenced by: '<S124>/SwitchControl'
                                        */
  uint8_T FixPtConstant_Value_i;       /* Computed Parameter: FixPtConstant_Value_i
                                        * Referenced by: '<S129>/FixPt Constant'
                                        */
};

/* Real-time Model Data Structure */
struct RT_MODEL_controller_template {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_controller_template controller_template_P;

/* Block signals (auto storage) */
extern BlockIO_controller_template controller_template_B;

/* Block states (auto storage) */
extern D_Work_controller_template controller_template_DWork;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void FG_traj_initialize(void);
  extern void controller_template_terminate(void);

#ifdef __cplusplus

}
#endif

/* Customized model step function */
#ifdef __cplusplus

extern "C" {

#endif

  extern void FG_traj_custom(real32_T arg_data_in[30], real32_T arg_cmd_out[4],
    real32_T arg_ref_x[93], real32_T arg_ref_y[93], real32_T arg_ref_z[62],
    real32_T arg_ref_yaw[62]);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern struct RT_MODEL_controller_template *const controller_template_M;

#ifdef __cplusplus

}
#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'controller_template'
 * '<S1>'   : 'controller_template/AIR Parser'
 * '<S2>'   : 'controller_template/FreeFlight Pos Ctrl'
 * '<S3>'   : 'controller_template/Idle cmd'
 * '<S4>'   : 'controller_template/Manual Switch'
 * '<S5>'   : 'controller_template/Manual Switch1'
 * '<S6>'   : 'controller_template/Mode Handling'
 * '<S7>'   : 'controller_template/convert2cmd'
 * '<S8>'   : 'controller_template/delay'
 * '<S9>'   : 'controller_template/pos controller'
 * '<S10>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference'
 * '<S11>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1'
 * '<S12>'  : 'controller_template/FreeFlight Pos Ctrl/Manual Switch'
 * '<S13>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem'
 * '<S14>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation'
 * '<S15>'  : 'controller_template/FreeFlight Pos Ctrl/rotate to world frame'
 * '<S16>'  : 'controller_template/FreeFlight Pos Ctrl/view & log signals'
 * '<S17>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj'
 * '<S18>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/get ref from vector'
 * '<S19>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_x'
 * '<S20>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_y'
 * '<S21>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_yaw'
 * '<S22>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_z'
 * '<S23>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem'
 * '<S24>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/demux'
 * '<S25>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S26>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S27>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S28>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S29>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S30>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/MATLAB Function'
 * '<S31>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/Slider Gain'
 * '<S32>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/Slider Gain1'
 * '<S33>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/Slider Gain2'
 * '<S34>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight'
 * '<S35>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid'
 * '<S36>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Free Flight'
 * '<S37>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Manual Switch'
 * '<S38>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Manual Switch1'
 * '<S39>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Mean'
 * '<S40>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation'
 * '<S41>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/Ctrl_Xdir'
 * '<S42>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/PitchPropagateFF'
 * '<S43>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/PitchPropagateFF/MATLAB Function'
 * '<S44>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/Ctrl_Xdir'
 * '<S45>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/PitchPropagate'
 * '<S46>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/PitchPropagate/MATLAB Function'
 * '<S47>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation/MATLAB Function'
 * '<S48>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation/Slider Gain'
 * '<S49>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation/Slider Gain2'
 * '<S50>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1'
 * '<S51>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Mean'
 * '<S52>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Slider Gain'
 * '<S53>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Slider Gain1'
 * '<S54>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Subsystem'
 * '<S55>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Wall Deviation'
 * '<S56>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/comp_cable'
 * '<S57>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S58>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate'
 * '<S59>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate/MATLAB Function'
 * '<S60>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Subsystem/MATLAB Function'
 * '<S61>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Subsystem/Slider Gain2'
 * '<S62>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Wall Deviation/MATLAB Function'
 * '<S63>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Wall Deviation/Slider Gain'
 * '<S64>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Wall Deviation/Slider Gain2'
 * '<S65>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1'
 * '<S66>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/MATLAB Function'
 * '<S67>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/MATLAB Function1'
 * '<S68>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Mean'
 * '<S69>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain'
 * '<S70>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain1'
 * '<S71>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain2'
 * '<S72>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain3'
 * '<S73>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S74>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate'
 * '<S75>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate/MATLAB Function'
 * '<S76>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/MATLAB Function'
 * '<S77>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S78>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S79>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1'
 * '<S80>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Mean'
 * '<S81>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Slider Gain'
 * '<S82>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Subsystem'
 * '<S83>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Wall Deviation'
 * '<S84>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S85>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Subsystem/MATLAB Function'
 * '<S86>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Subsystem/Slider Gain'
 * '<S87>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Wall Deviation/MATLAB Function'
 * '<S88>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Wall Deviation/Slider Gain'
 * '<S89>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Wall Deviation/Slider Gain2'
 * '<S90>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference'
 * '<S91>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Next Ref'
 * '<S92>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Slider Gain'
 * '<S93>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem'
 * '<S94>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1'
 * '<S95>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Thresy'
 * '<S96>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Thresz'
 * '<S97>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation'
 * '<S98>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1'
 * '<S99>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/get ref from vector1'
 * '<S100>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/get ref from vector2'
 * '<S101>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem/MATLAB Function'
 * '<S102>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/MATLAB Function'
 * '<S103>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain'
 * '<S104>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain1'
 * '<S105>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain2'
 * '<S106>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain3'
 * '<S107>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain4'
 * '<S108>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation/MATLAB Function'
 * '<S109>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation/Slider Gain'
 * '<S110>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation/Slider Gain2'
 * '<S111>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_x'
 * '<S112>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_y'
 * '<S113>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_yaw'
 * '<S114>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_z'
 * '<S115>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling '
 * '<S116>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame'
 * '<S117>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S118>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation'
 * '<S119>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation/MATLAB Function'
 * '<S120>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation/Slider Gain'
 * '<S121>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation/Slider Gain2'
 * '<S122>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S123>' : 'controller_template/FreeFlight Pos Ctrl/rotate to world frame/Embedded MATLAB Function'
 * '<S124>' : 'controller_template/convert2cmd/Manual Switch'
 * '<S125>' : 'controller_template/convert2cmd/Slider Gain'
 * '<S126>' : 'controller_template/convert2cmd/added_mass'
 * '<S127>' : 'controller_template/convert2cmd/added_mass1'
 * '<S128>' : 'controller_template/convert2cmd/added_mass2'
 * '<S129>' : 'controller_template/delay/delay bias'
 * '<S130>' : 'controller_template/pos controller/MAIN CONTROL LOOP1'
 * '<S131>' : 'controller_template/pos controller/decoupling and rotation'
 * '<S132>' : 'controller_template/pos controller/get ref from vector'
 * '<S133>' : 'controller_template/pos controller/rotate to world frame'
 * '<S134>' : 'controller_template/pos controller/view & log signals'
 * '<S135>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/demux'
 * '<S136>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S137>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias'
 * '<S138>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S139>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias'
 * '<S140>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S141>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S142>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S143>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias'
 * '<S144>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  /runFastGradient'
 * '<S145>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/Unit Delay External IC1'
 * '<S146>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/discrete kalman filter'
 * '<S147>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG/runFastGradient'
 * '<S148>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/Unit Delay External IC1'
 * '<S149>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/discrete kalman filter'
 * '<S150>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG/runFastGradient'
 * '<S151>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S152>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S153>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG/runFastGradient'
 * '<S154>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/Unit Delay External IC1'
 * '<S155>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/discrete kalman filter'
 * '<S156>' : 'controller_template/pos controller/decoupling and rotation/decoupling '
 * '<S157>' : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame'
 * '<S158>' : 'controller_template/pos controller/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S159>' : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S160>' : 'controller_template/pos controller/rotate to world frame/Embedded MATLAB Function'
 */
#endif                                 /* RTW_HEADER_controller_template_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
