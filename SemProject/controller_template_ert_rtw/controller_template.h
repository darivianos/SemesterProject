/*
 * File: controller_template.h
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.718
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Aug  6 2011)
 * C/C++ source code generated on : Sat Aug 24 17:40:43 2013
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

/* Block signals for system '<S50>/MATLAB Function' */
typedef struct {
  real_T y;                            /* '<S50>/MATLAB Function' */
} rtB_MATLABFunction_controller_t;

/* Block states (auto storage) for system '<S50>/MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S50>/MATLAB Function' */
  uint8_T is_active_c15_controller_templa;/* '<S50>/MATLAB Function' */
  boolean_T isStable;                  /* '<S50>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S50>/MATLAB Function' */
} rtDW_MATLABFunction_controller_;

/* Block signals for system '<S73>/MATLAB Function' */
typedef struct {
  real_T y;                            /* '<S73>/MATLAB Function' */
} rtB_MATLABFunction_controller_p;

/* Block states (auto storage) for system '<S73>/MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S73>/MATLAB Function' */
  uint8_T is_active_c13_controller_templa;/* '<S73>/MATLAB Function' */
  boolean_T isStable;                  /* '<S73>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S73>/MATLAB Function' */
} rtDW_MATLABFunction_controlle_o;

/* Block signals for system '<S34>/discrete kalman filter' */
typedef struct {
  real_T state_est[3];                 /* '<S34>/discrete kalman filter' */
  real_T P_est[9];                     /* '<S34>/discrete kalman filter' */
} rtB_discretekalmanfilter_contro;

/* Block states (auto storage) for system '<S34>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S34>/discrete kalman filter' */
  uint8_T is_active_c27_controller_templa;/* '<S34>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S34>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S34>/discrete kalman filter' */
} rtDW_discretekalmanfilter_contr;

/* Block signals for system '<S155>/runFastGradient' */
typedef struct {
  real_T u_opt;                        /* '<S155>/runFastGradient' */
  real_T J_star;                       /* '<S155>/runFastGradient' */
  real_T u_buff_out[3];                /* '<S155>/runFastGradient' */
  real_T V_init_out[30];               /* '<S155>/runFastGradient' */
} rtB_runFastGradient_controller_;

/* Block states (auto storage) for system '<S155>/runFastGradient' */
typedef struct {
  int32_T sfEvent;                     /* '<S155>/runFastGradient' */
  uint8_T is_active_c6_Hquad_control_LIB_;/* '<S155>/runFastGradient' */
  boolean_T isStable;                  /* '<S155>/runFastGradient' */
  boolean_T doneDoubleBufferReInit;    /* '<S155>/runFastGradient' */
} rtDW_runFastGradient_controller;

/* Block signals for system '<S156>/discrete kalman filter' */
typedef struct {
  real_T state_est[4];                 /* '<S156>/discrete kalman filter' */
  real_T P_est[16];                    /* '<S156>/discrete kalman filter' */
} rtB_discretekalmanfilter_cont_h;

/* Block states (auto storage) for system '<S156>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S156>/discrete kalman filter' */
  uint8_T is_active_c11_Hquad_control_LIB;/* '<S156>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S156>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S156>/discrete kalman filter' */
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
  real_T SliderGain;                   /* '<S143>/Slider Gain' */
  real_T thrust_cmd;                   /* '<Root>/Switch1' */
  real_T yaw_rate_cmd;                 /* '<Root>/Switch1' */
  real_T pitch_bias;                   /* '<Root>/Switch1' */
  real_T roll_bias;                    /* '<Root>/Switch1' */
  real_T thrust_bias;                  /* '<Root>/Switch1' */
  real_T yaw_rate_bias;                /* '<Root>/Switch1' */
  real_T Gain[4];                      /* '<S153>/Gain' */
  real_T raddeg2[3];                   /* '<S153>/rad -> deg2' */
  real_T raddeg1[3];                   /* '<S153>/rad -> deg1' */
  real_T raddeg3[3];                   /* '<S153>/rad -> deg3' */
  real_T raddeg[4];                    /* '<S153>/rad -> deg' */
  real_T roll_rot;                     /* '<S152>/Embedded MATLAB Function' */
  real_T pitch_rot;                    /* '<S152>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S152>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S152>/Embedded MATLAB Function' */
  real_T bias_W[4];                    /* '<S150>/bias_W' */
  real_T cmd_W[4];                     /* '<S150>/cmd_W' */
  real_T pitch_rot_k;                  /* '<S176>/Embedded MATLAB Function' */
  real_T roll_rot_a;                   /* '<S176>/Embedded MATLAB Function' */
  real_T pitch_bias_rot_e;             /* '<S176>/Embedded MATLAB Function' */
  real_T roll_bias_rot_b;              /* '<S176>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp;               /* '<S175>/Embedded MATLAB Function' */
  real_T roll_cmd_comp;                /* '<S175>/Embedded MATLAB Function' */
  real_T thrust_comp;                  /* '<S175>/Embedded MATLAB Function' */
  real_T thrust_cmd_e;                 /* '<S149>/Sum5' */
  real_T u_opt;                        /* '<S161>/runFastGradient' */
  real_T J_star;                       /* '<S161>/runFastGradient' */
  real_T u_buff_out[2];                /* '<S161>/runFastGradient' */
  real_T V_init_out[30];               /* '<S161>/runFastGradient' */
  real_T u_opt_l;                      /* '<S159>/runFastGradient' */
  real_T J_star_h;                     /* '<S159>/runFastGradient' */
  real_T u_buff_out_i[6];              /* '<S159>/runFastGradient' */
  real_T V_init_out_n[30];             /* '<S159>/runFastGradient' */
  real_T Switch1;                      /* '<S112>/Switch1' */
  real_T Switch;                       /* '<S112>/Switch' */
  real_T UnitDelay1;                   /* '<S108>/Unit Delay1' */
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
  real_T Sum[2];                       /* '<S108>/Sum' */
  real_T Gain_k[2];                    /* '<S108>/Gain' */
  real_T roll_rot_f;                   /* '<S15>/Embedded MATLAB Function' */
  real_T pitch_rot_i;                  /* '<S15>/Embedded MATLAB Function' */
  real_T pitch_bias_rot_p;             /* '<S15>/Embedded MATLAB Function' */
  real_T roll_bias_rot_n;              /* '<S15>/Embedded MATLAB Function' */
  real_T bias_W_b[4];                  /* '<S14>/bias_W' */
  real_T cmd_W_h[4];                   /* '<S14>/cmd_W' */
  real_T pitch_rot_n;                  /* '<S134>/Embedded MATLAB Function' */
  real_T roll_rot_e;                   /* '<S134>/Embedded MATLAB Function' */
  real_T pitch_bias_rot_i;             /* '<S134>/Embedded MATLAB Function' */
  real_T roll_bias_rot_d;              /* '<S134>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp_n;             /* '<S133>/Embedded MATLAB Function' */
  real_T roll_cmd_comp_j;              /* '<S133>/Embedded MATLAB Function' */
  real_T thrust_comp_k;                /* '<S133>/Embedded MATLAB Function' */
  real_T nominal_window_z_out;         /* '<S112>/MATLAB Function' */
  real_T nominal_window_y_out;         /* '<S112>/MATLAB Function' */
  real_T count_out;                    /* '<S111>/MATLAB Function' */
  real_T en;                           /* '<S108>/Next Ref' */
  real_T Gain2;                        /* '<S34>/Gain2' */
  real_T SwitchControl;                /* '<S46>/SwitchControl' */
  real_T RateTransition[4];            /* '<S44>/Rate Transition' */
  real_T UnitDelay2;                   /* '<S44>/Unit Delay2' */
  real_T RateTransition_l[4];          /* '<S43>/Rate Transition' */
  real_T UnitDelay2_p;                 /* '<S43>/Unit Delay2' */
  real_T Gain_pk;                      /* '<S48>/Gain' */
  real_T Saturation3;                  /* '<S32>/Saturation3' */
  real_T RateTransition_i[5];          /* '<S68>/Rate Transition' */
  real_T UnitDelay2_o;                 /* '<S68>/Unit Delay2' */
  real_T Gain_f;                       /* '<S69>/Gain' */
  real_T Saturation1;                  /* '<S35>/Saturation1' */
  real_T RateTransition_j[3];          /* '<S97>/Rate Transition' */
  real_T Gain_i;                       /* '<S98>/Gain' */
  real_T Sum_b;                        /* '<S33>/Sum' */
  real_T Gain_n;                       /* '<S86>/Gain' */
  real_T thrust_cmd_a;                 /* '<S11>/Sum5' */
  real_T RateTransition1;              /* '<S43>/Rate Transition1' */
  real_T RateTransition1_l;            /* '<S44>/Rate Transition1' */
  real_T RateTransition1_lq;           /* '<S68>/Rate Transition1' */
  real_T Gain_g;                       /* '<S33>/Gain' */
  real_T Gain1;                        /* '<S34>/Gain1' */
  real_T Gain_d;                       /* '<S34>/Gain' */
  real_T u_thrust_out;                 /* '<S100>/MATLAB Function' */
  real_T U;                            /* '<S97>/Ctrl_Xdir' */
  real_T flag_oob;                     /* '<S97>/Ctrl_Xdir' */
  real_T psi_prime;                    /* '<S34>/MATLAB Function' */
  real_T psi_out;                      /* '<S33>/MATLAB Function1' */
  real_T delta_x;                      /* '<S33>/MATLAB Function1' */
  real_T psi_prime_l;                  /* '<S33>/MATLAB Function' */
  real_T y;                            /* '<S92>/MATLAB Function' */
  real_T U_g;                          /* '<S83>/Ctrl_Xdir' */
  real_T flag_oob_l;                   /* '<S83>/Ctrl_Xdir' */
  real_T input_out;                    /* '<S72>/MATLAB Function' */
  real_T y_a[5];                       /* '<S76>/MATLAB Function' */
  real_T U_p;                          /* '<S68>/Ctrl_Xdir' */
  real_T flag_oob_o;                   /* '<S68>/Ctrl_Xdir' */
  real_T pulse_enable;                 /* '<S60>/MATLAB Function' */
  real_T flag_init;                    /* '<S62>/MATLAB Function' */
  real_T x_init[4];                    /* '<S62>/MATLAB Function' */
  real_T x_meas[4];                    /* '<S59>/MATLAB Function' */
  real_T Pmeas[16];                    /* '<S59>/MATLAB Function' */
  real_T flag_failure;                 /* '<S49>/MATLAB Function1' */
  real_T y_i[4];                       /* '<S55>/MATLAB Function' */
  real_T U_gb;                         /* '<S44>/Ctrl_Xdir' */
  real_T flag_oob_ow;                  /* '<S44>/Ctrl_Xdir' */
  real_T y_o[4];                       /* '<S52>/MATLAB Function' */
  real_T U_a;                          /* '<S43>/Ctrl_Xdir' */
  real_T flag_oob_l1;                  /* '<S43>/Ctrl_Xdir' */
  real_T pitch_cmd_out;                /* '<S29>/MATLAB Function' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_k;/* '<S162>/discrete kalman filter' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_n;/* '<S160>/discrete kalman filter' */
  rtB_discretekalmanfilter_cont_h sf_discretekalmanfilter_m;/* '<S158>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient_d;/* '<S157>/runFastGradient' */
  rtB_discretekalmanfilter_cont_h sf_discretekalmanfilter_b;/* '<S156>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient;/* '<S155>/runFastGradient' */
  rtB_MATLABFunction_controller_t sf_MATLABFunction_p;/* '<S136>/MATLAB Function' */
  rtB_generate_X_ref_z_controller sf_generate_X_ref_z;/* '<S116>/generate_X_ref_z' */
  rtB_generate_X_ref_yaw_controll sf_generate_X_ref_yaw;/* '<S116>/generate_X_ref_yaw' */
  rtB_generate_X_ref_y_controller sf_generate_X_ref_y;/* '<S116>/generate_X_ref_y' */
  rtB_generate_X_ref_x_controller sf_generate_X_ref_x;/* '<S116>/generate_X_ref_x' */
  rtB_MATLABFunction_controller_t sf_MATLABFunction;/* '<S115>/MATLAB Function' */
  rtB_MATLABFunction_controller_p sf_MATLABFunction_c;/* '<S101>/MATLAB Function' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter;/* '<S34>/discrete kalman filter' */
  rtB_MATLABFunction_controller_p sf_MATLABFunction_l5;/* '<S73>/MATLAB Function' */
  rtB_MATLABFunction_controller_t sf_MATLABFunction_e;/* '<S50>/MATLAB Function' */
  rtB_generate_X_ref_z_controller sf_generate_X_ref_z_b;/* '<S18>/generate_X_ref_z' */
  rtB_generate_X_ref_yaw_controll sf_generate_X_ref_yaw_h;/* '<S18>/generate_X_ref_yaw' */
  rtB_generate_X_ref_y_controller sf_generate_X_ref_y_k;/* '<S18>/generate_X_ref_y' */
  rtB_generate_X_ref_x_controller sf_generate_X_ref_x_a;/* '<S18>/generate_X_ref_x' */
  rtB_generate_X_ref_z_controller sf_generate_X_ref_z_l;/* '<S17>/generate_X_ref_z' */
  rtB_generate_X_ref_yaw_controll sf_generate_X_ref_yaw_g;/* '<S17>/generate_X_ref_yaw' */
  rtB_generate_X_ref_y_controller sf_generate_X_ref_y_a;/* '<S17>/generate_X_ref_y' */
  rtB_generate_X_ref_x_controller sf_generate_X_ref_x_k;/* '<S17>/generate_X_ref_x' */
} BlockIO_controller_template;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T FixPtUnitDelay1_DSTATE[4];    /* '<S148>/FixPt Unit Delay1' */
  real_T IntegerDelay_DSTATE;          /* '<S149>/Integer Delay' */
  real_T IntegerDelay1_DSTATE;         /* '<S149>/Integer Delay1' */
  real_T IntegerDelay2_DSTATE;         /* '<S149>/Integer Delay2' */
  real_T IntegerDelay3_DSTATE;         /* '<S149>/Integer Delay3' */
  real_T UnitDelay1_DSTATE[16];        /* '<S156>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i[3];  /* '<S164>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE[3];          /* '<S155>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c[30];      /* '<S155>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_b[16];      /* '<S158>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_g[3];  /* '<S167>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_j[3];        /* '<S157>/Unit Delay' */
  real_T UnitDelay1_DSTATE_l[30];      /* '<S157>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_j[9];       /* '<S162>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_d[2];  /* '<S173>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_l[2];        /* '<S161>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g[30];      /* '<S161>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_lx[9];      /* '<S160>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_e[2];  /* '<S170>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_jz[6];       /* '<S159>/Unit Delay' */
  real_T UnitDelay1_DSTATE_js[30];     /* '<S159>/Unit Delay1' */
  real_T UnitDelay_2_DSTATE;           /* '<S108>/Unit Delay' */
  real_T UnitDelay_3_DSTATE;           /* '<S108>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S108>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S116>/Unit Delay' */
  real_T UnitDelay_DSTATE_c;           /* '<S18>/Unit Delay' */
  real_T UnitDelay_DSTATE_e;           /* '<S17>/Unit Delay' */
  real_T UnitDelay_DSTATE_es;          /* '<S111>/Unit Delay' */
  real_T UnitDelay1_DSTATE_o;          /* '<S111>/Unit Delay1' */
  real_T IntegerDelay3_DSTATE_k;       /* '<S11>/Integer Delay3' */
  real_T UnitDelay1_DSTATE_bg[9];      /* '<S34>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i1[2]; /* '<S95>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_h[4];       /* '<S31>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S31>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_c;          /* '<S44>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_m;          /* '<S43>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_d;          /* '<S48>/Unit Delay2' */
  real_T UnitDelay_DSTATE_jv;          /* '<S48>/Unit Delay' */
  real_T UnitDelay2_DSTATE_l;          /* '<S68>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_k;          /* '<S69>/Unit Delay2' */
  real_T UnitDelay_DSTATE_f;           /* '<S69>/Unit Delay' */
  real_T UnitDelay2_DSTATE_b;          /* '<S98>/Unit Delay2' */
  real_T UnitDelay_DSTATE_fw;          /* '<S98>/Unit Delay' */
  real_T UnitDelay_DSTATE_lg;          /* '<S33>/Unit Delay' */
  real_T UnitDelay2_DSTATE_g;          /* '<S83>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_ga;         /* '<S86>/Unit Delay2' */
  real_T UnitDelay_DSTATE_p;           /* '<S86>/Unit Delay' */
  real_T UnitDelay1_DSTATE_a;          /* '<S48>/Unit Delay1' */
  real_T UnitDelay_DSTATE_a;           /* '<S31>/Unit Delay' */
  real_T UnitDelay_DSTATE_m[4];        /* '<S59>/Unit Delay' */
  real_T UnitDelay1_DSTATE_j5[16];     /* '<S59>/Unit Delay1' */
  real_T UnitDelay_DSTATE_m2;          /* '<S60>/Unit Delay' */
  real_T UnitDelay1_DSTATE_ji;         /* '<S69>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_c3;         /* '<S86>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_m;          /* '<S98>/Unit Delay1' */
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
  } ToFile_PWORK;                      /* '<S153>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<S153>/To File1' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S153>/To Workspace' */

  struct {
    void *LoggedData;
  } pitchcmd_PWORK;                    /* '<S153>/pitch cmd' */

  struct {
    void *LoggedData;
  } rollcmd_PWORK;                     /* '<S153>/roll cmd' */

  struct {
    void *LoggedData;
  } thrustcmd_PWORK;                   /* '<S153>/thrust cmd' */

  struct {
    void *LoggedData;
  } x_ref_PWORK;                       /* '<S153>/x_ref' */

  struct {
    void *LoggedData;
  } y_ref_PWORK;                       /* '<S153>/y_ref' */

  struct {
    void *LoggedData;
  } yawcmd_PWORK;                      /* '<S153>/yaw cmd' */

  struct {
    void *LoggedData;
  } yaw_ref_PWORK;                     /* '<S153>/yaw_ref' */

  struct {
    void *LoggedData;
  } z_ref_PWORK;                       /* '<S153>/z_ref' */

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
  } Scope_PWORK;                       /* '<S108>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     /* '<S112>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     /* '<S11>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     /* '<S29>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_l;                     /* '<S49>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S49>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<S33>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_c;                    /* '<S33>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_e;                     /* '<S34>/Scope' */

  int32_T sfEvent;                     /* '<S152>/Embedded MATLAB Function' */
  int32_T sfEvent_b;                   /* '<S176>/Embedded MATLAB Function' */
  int32_T sfEvent_f;                   /* '<S175>/Embedded MATLAB Function' */
  int32_T sfEvent_k;                   /* '<S161>/runFastGradient' */
  int32_T sfEvent_n;                   /* '<S159>/runFastGradient' */
  int32_T sfEvent_bq;                  /* '<S15>/Embedded MATLAB Function' */
  int32_T sfEvent_j;                   /* '<S134>/Embedded MATLAB Function' */
  int32_T sfEvent_c;                   /* '<S133>/Embedded MATLAB Function' */
  int32_T sfEvent_a;                   /* '<S112>/MATLAB Function' */
  int32_T sfEvent_jg;                  /* '<S111>/MATLAB Function' */
  int32_T sfEvent_p;                   /* '<S108>/Next Ref' */
  int32_T sfEvent_jj;                  /* '<S100>/MATLAB Function' */
  int32_T sfEvent_k0;                  /* '<S97>/Ctrl_Xdir' */
  int32_T sfEvent_ks;                  /* '<S34>/MATLAB Function' */
  int32_T sfEvent_d;                   /* '<S33>/MATLAB Function1' */
  int32_T sfEvent_g;                   /* '<S33>/MATLAB Function' */
  int32_T sfEvent_l;                   /* '<S92>/MATLAB Function' */
  int32_T sfEvent_jv;                  /* '<S83>/Ctrl_Xdir' */
  int32_T sfEvent_ab;                  /* '<S72>/MATLAB Function' */
  int32_T sfEvent_i;                   /* '<S76>/MATLAB Function' */
  int32_T sfEvent_cd;                  /* '<S68>/Ctrl_Xdir' */
  int32_T sfEvent_fc;                  /* '<S60>/MATLAB Function' */
  int32_T sfEvent_du;                  /* '<S62>/MATLAB Function' */
  int32_T sfEvent_cq;                  /* '<S59>/MATLAB Function' */
  int32_T sfEvent_h;                   /* '<S49>/MATLAB Function1' */
  int32_T sfEvent_ac;                  /* '<S55>/MATLAB Function' */
  int32_T sfEvent_cm;                  /* '<S44>/Ctrl_Xdir' */
  int32_T sfEvent_kd;                  /* '<S52>/MATLAB Function' */
  int32_T sfEvent_cr;                  /* '<S43>/Ctrl_Xdir' */
  int32_T sfEvent_fp;                  /* '<S29>/MATLAB Function' */
  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<S153>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<S153>/To File1' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK_g;                    /* '<S16>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK_p;                   /* '<S16>/To File1' */

  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S148>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_l;    /* '<S164>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_b;    /* '<S167>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S173>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S170>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_g;    /* '<S95>/FixPt Unit Delay2' */
  int8_T FreeFlightPosCtrl_SubsysRanBC;/* '<Root>/FreeFlight Pos Ctrl' */
  int8_T poscontroller_SubsysRanBC;    /* '<Root>/pos controller' */
  uint8_T is_active_c26_Hquad_control_LIB;/* '<S152>/Embedded MATLAB Function' */
  uint8_T is_active_c4_Hquad_control_LIB_;/* '<S176>/Embedded MATLAB Function' */
  uint8_T is_active_c1_Hquad_control_LIB_;/* '<S175>/Embedded MATLAB Function' */
  uint8_T is_active_c8_Hquad_control_LIB_;/* '<S161>/runFastGradient' */
  uint8_T is_active_c9_Hquad_control_LIB_;/* '<S159>/runFastGradient' */
  uint8_T is_active_c26_Hquad_control_L_f;/* '<S15>/Embedded MATLAB Function' */
  uint8_T is_active_c10_controller_templa;/* '<S134>/Embedded MATLAB Function' */
  uint8_T is_active_c9_controller_templat;/* '<S133>/Embedded MATLAB Function' */
  uint8_T is_active_c18_controller_templa;/* '<S112>/MATLAB Function' */
  uint8_T is_active_c11_controller_templa;/* '<S111>/MATLAB Function' */
  uint8_T is_active_c35_controller_templa;/* '<S108>/Next Ref' */
  uint8_T is_active_c16_controller_templa;/* '<S100>/MATLAB Function' */
  uint8_T is_active_c3_controller_templat;/* '<S97>/Ctrl_Xdir' */
  uint8_T is_active_c28_controller_templa;/* '<S34>/MATLAB Function' */
  uint8_T is_active_c30_controller_templa;/* '<S33>/MATLAB Function1' */
  uint8_T is_active_c25_controller_templa;/* '<S33>/MATLAB Function' */
  uint8_T is_active_c6_controller_templat;/* '<S92>/MATLAB Function' */
  uint8_T is_active_c4_controller_templat;/* '<S83>/Ctrl_Xdir' */
  uint8_T is_active_c17_controller_templa;/* '<S72>/MATLAB Function' */
  uint8_T is_active_c5_controller_templat;/* '<S76>/MATLAB Function' */
  uint8_T is_active_c2_controller_templat;/* '<S68>/Ctrl_Xdir' */
  uint8_T is_active_c40_controller_templa;/* '<S60>/MATLAB Function' */
  uint8_T is_active_c43_controller_templa;/* '<S62>/MATLAB Function' */
  uint8_T is_active_c42_controller_templa;/* '<S59>/MATLAB Function' */
  uint8_T is_active_c41_controller_templa;/* '<S49>/MATLAB Function1' */
  uint8_T is_active_c7_controller_templat;/* '<S55>/MATLAB Function' */
  uint8_T is_active_c1_controller_templat;/* '<S44>/Ctrl_Xdir' */
  uint8_T is_active_c26_controller_templa;/* '<S52>/MATLAB Function' */
  uint8_T is_active_c24_controller_templa;/* '<S43>/Ctrl_Xdir' */
  uint8_T is_active_c12_controller_templa;/* '<S29>/MATLAB Function' */
  boolean_T isStable;                  /* '<S152>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S152>/Embedded MATLAB Function' */
  boolean_T isStable_n;                /* '<S176>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_m;  /* '<S176>/Embedded MATLAB Function' */
  boolean_T isStable_m;                /* '<S175>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S175>/Embedded MATLAB Function' */
  boolean_T isStable_i;                /* '<S161>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_h;  /* '<S161>/runFastGradient' */
  boolean_T isStable_h;                /* '<S159>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_o;  /* '<S159>/runFastGradient' */
  boolean_T isStable_k;                /* '<S15>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_og; /* '<S15>/Embedded MATLAB Function' */
  boolean_T isStable_o;                /* '<S134>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S134>/Embedded MATLAB Function' */
  boolean_T isStable_mf;               /* '<S133>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_a;  /* '<S133>/Embedded MATLAB Function' */
  boolean_T isStable_g;                /* '<S112>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_ek; /* '<S112>/MATLAB Function' */
  boolean_T isStable_j;                /* '<S111>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_p;  /* '<S111>/MATLAB Function' */
  boolean_T isStable_od;               /* '<S108>/Next Ref' */
  boolean_T doneDoubleBufferReInit_em; /* '<S108>/Next Ref' */
  boolean_T isStable_g4;               /* '<S100>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_n;  /* '<S100>/MATLAB Function' */
  boolean_T isStable_c;                /* '<S97>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_ha; /* '<S97>/Ctrl_Xdir' */
  boolean_T isStable_hz;               /* '<S34>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_l;  /* '<S34>/MATLAB Function' */
  boolean_T isStable_f;                /* '<S33>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_g;  /* '<S33>/MATLAB Function1' */
  boolean_T isStable_a;                /* '<S33>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_ga; /* '<S33>/MATLAB Function' */
  boolean_T isStable_oc;               /* '<S92>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_me; /* '<S92>/MATLAB Function' */
  boolean_T isStable_hg;               /* '<S83>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_pw; /* '<S83>/Ctrl_Xdir' */
  boolean_T isStable_oj;               /* '<S72>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_cz; /* '<S72>/MATLAB Function' */
  boolean_T isStable_nx;               /* '<S76>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_b;  /* '<S76>/MATLAB Function' */
  boolean_T isStable_ke;               /* '<S68>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S68>/Ctrl_Xdir' */
  boolean_T isStable_j4;               /* '<S60>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_as; /* '<S60>/MATLAB Function' */
  boolean_T isStable_b;                /* '<S62>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_o4; /* '<S62>/MATLAB Function' */
  boolean_T isStable_an;               /* '<S59>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_lb; /* '<S59>/MATLAB Function' */
  boolean_T isStable_ni;               /* '<S49>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_j;  /* '<S49>/MATLAB Function1' */
  boolean_T isStable_bh;               /* '<S55>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_nz; /* '<S55>/MATLAB Function' */
  boolean_T isStable_hy;               /* '<S44>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_f;  /* '<S44>/Ctrl_Xdir' */
  boolean_T isStable_l;                /* '<S52>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_lo; /* '<S52>/MATLAB Function' */
  boolean_T isStable_ng;               /* '<S43>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_dn; /* '<S43>/Ctrl_Xdir' */
  boolean_T isStable_d;                /* '<S29>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_hm; /* '<S29>/MATLAB Function' */
  boolean_T FreeFlightPosCtrl_MODE;    /* '<Root>/FreeFlight Pos Ctrl' */
  boolean_T poscontroller_MODE;        /* '<Root>/pos controller' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_k;/* '<S162>/discrete kalman filter' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_n;/* '<S160>/discrete kalman filter' */
  rtDW_discretekalmanfilter_con_c sf_discretekalmanfilter_m;/* '<S158>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient_d;/* '<S157>/runFastGradient' */
  rtDW_discretekalmanfilter_con_c sf_discretekalmanfilter_b;/* '<S156>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient;/* '<S155>/runFastGradient' */
  rtDW_MATLABFunction_controller_ sf_MATLABFunction_p;/* '<S136>/MATLAB Function' */
  rtDW_generate_X_ref_z_controlle sf_generate_X_ref_z;/* '<S116>/generate_X_ref_z' */
  rtDW_generate_X_ref_yaw_control sf_generate_X_ref_yaw;/* '<S116>/generate_X_ref_yaw' */
  rtDW_generate_X_ref_y_controlle sf_generate_X_ref_y;/* '<S116>/generate_X_ref_y' */
  rtDW_generate_X_ref_x_controlle sf_generate_X_ref_x;/* '<S116>/generate_X_ref_x' */
  rtDW_MATLABFunction_controller_ sf_MATLABFunction;/* '<S115>/MATLAB Function' */
  rtDW_MATLABFunction_controlle_o sf_MATLABFunction_c;/* '<S101>/MATLAB Function' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter;/* '<S34>/discrete kalman filter' */
  rtDW_MATLABFunction_controlle_o sf_MATLABFunction_l5;/* '<S73>/MATLAB Function' */
  rtDW_MATLABFunction_controller_ sf_MATLABFunction_e;/* '<S50>/MATLAB Function' */
  rtDW_generate_X_ref_z_controlle sf_generate_X_ref_z_b;/* '<S18>/generate_X_ref_z' */
  rtDW_generate_X_ref_yaw_control sf_generate_X_ref_yaw_h;/* '<S18>/generate_X_ref_yaw' */
  rtDW_generate_X_ref_y_controlle sf_generate_X_ref_y_k;/* '<S18>/generate_X_ref_y' */
  rtDW_generate_X_ref_x_controlle sf_generate_X_ref_x_a;/* '<S18>/generate_X_ref_x' */
  rtDW_generate_X_ref_z_controlle sf_generate_X_ref_z_l;/* '<S17>/generate_X_ref_z' */
  rtDW_generate_X_ref_yaw_control sf_generate_X_ref_yaw_g;/* '<S17>/generate_X_ref_yaw' */
  rtDW_generate_X_ref_y_controlle sf_generate_X_ref_y_a;/* '<S17>/generate_X_ref_y' */
  rtDW_generate_X_ref_x_controlle sf_generate_X_ref_x_k;/* '<S17>/generate_X_ref_x' */
} D_Work_controller_template;

/* Parameters (auto storage) */
struct Parameters_controller_template_ {
  real_T Constant3_Value[8];           /* Expression: Bdd_pitch
                                        * Referenced by: '<S55>/Constant3'
                                        */
  real_T Constant1_Value[8];           /* Expression: Bff_pitch
                                        * Referenced by: '<S55>/Constant1'
                                        */
  real_T Constant2_Value[16];          /* Expression: Add_pitch
                                        * Referenced by: '<S55>/Constant2'
                                        */
  real_T Constant_Value[16];           /* Expression: Aff_pitch
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S45>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S45>/Saturation3'
                                        */
  real_T A_Value[9];                   /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S34>/A'
                                        */
  real_T B_Value[3];                   /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S34>/B'
                                        */
  real_T C_Value[6];                   /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S34>/C'
                                        */
  real_T D_Value[2];                   /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S34>/D'
                                        */
  real_T Q_Value[9];                   /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S34>/Q'
                                        */
  real_T R_Value[4];                   /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S34>/R'
                                        */
  real_T IntegerDelay3_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S11>/Integer Delay3'
                                         */
  real_T UnitDelay1_X0[9];             /* Expression: kalm_mpc_yaw.P
                                        * Referenced by: '<S34>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0;           /* Expression: 0.0
                                        * Referenced by: '<S95>/FixPt Unit Delay1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S34>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S34>/Saturation'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S34>/Gain2'
                                        */
  real_T UnitDelay1_X0_d[4];           /* Expression: zeros(4,1)
                                        * Referenced by: '<S31>/Unit Delay1'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S31>/Unit Delay2'
                                        */
  real_T Switch_Threshold;             /* Expression: .5
                                        * Referenced by: '<S31>/Switch'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 0.2094
                                        * Referenced by: '<S31>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: -0.2094
                                        * Referenced by: '<S31>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 2
                                        * Referenced by: '<S31>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -2
                                        * Referenced by: '<S31>/Saturation1'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * Referenced by: '<S66>/Slider Gain'
                                        */
  real_T Constant1_Value_f;            /* Expression: 1
                                        * Referenced by: '<S50>/Constant1'
                                        */
  real_T SliderGain_Gain_b;            /* Expression: gain
                                        * Referenced by: '<S67>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_j;       /* Expression: 0
                                        * Referenced by: '<S50>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_l;       /* Expression: -1
                                        * Referenced by: '<S50>/Saturation3'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S31>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S31>/Saturation2'
                                        */
  real_T UnitDelay2_X0_g;              /* Expression: 0
                                        * Referenced by: '<S44>/Unit Delay2'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 0.2094
                                        * Referenced by: '<S55>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -0.2094
                                        * Referenced by: '<S55>/Saturation'
                                        */
  real_T Saturation1_UpperSat_o;       /* Expression: 2
                                        * Referenced by: '<S55>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_d;       /* Expression: -2
                                        * Referenced by: '<S55>/Saturation1'
                                        */
  real_T Saturation3_UpperSat_c;       /* Expression: 0
                                        * Referenced by: '<S55>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_k;       /* Expression: -1
                                        * Referenced by: '<S55>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_a;       /* Expression: 1
                                        * Referenced by: '<S55>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_h;       /* Expression: -1
                                        * Referenced by: '<S55>/Saturation2'
                                        */
  real_T Constant_Value_l[9476];       /* Expression: Hn_Xdir
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T Constant1_Value_fy[2369];     /* Expression: Kn_Xdir
                                        * Referenced by: '<S44>/Constant1'
                                        */
  real_T Constant2_Value_m[1108];      /* Expression: Fi_Xdir
                                        * Referenced by: '<S44>/Constant2'
                                        */
  real_T Constat3_Value[277];          /* Expression: Gi_Xdir
                                        * Referenced by: '<S44>/Constat3'
                                        */
  real_T Constant4_Value[277];         /* Expression: Nc_Xdir
                                        * Referenced by: '<S44>/Constant4'
                                        */
  real_T Constant_Value_m[16];         /* Expression: Aff_pitch
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T Constant1_Value_a[8];         /* Expression: Bff_pitch
                                        * Referenced by: '<S52>/Constant1'
                                        */
  real_T UnitDelay2_X0_b;              /* Expression: 0
                                        * Referenced by: '<S43>/Unit Delay2'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: 0.2094
                                        * Referenced by: '<S52>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -0.2094
                                        * Referenced by: '<S52>/Saturation'
                                        */
  real_T Saturation1_UpperSat_p;       /* Expression: 2
                                        * Referenced by: '<S52>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_l;       /* Expression: -2
                                        * Referenced by: '<S52>/Saturation1'
                                        */
  real_T Saturation3_UpperSat_l;       /* Expression: 1
                                        * Referenced by: '<S52>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_lj;      /* Expression: -1
                                        * Referenced by: '<S52>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_k;       /* Expression: 1
                                        * Referenced by: '<S52>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_c;       /* Expression: -1
                                        * Referenced by: '<S52>/Saturation2'
                                        */
  real_T Constant5_Value[5660];        /* Expression: Hn_XdirFF
                                        * Referenced by: '<S43>/Constant5'
                                        */
  real_T Constant6_Value[1415];        /* Expression: Kn_XdirFF
                                        * Referenced by: '<S43>/Constant6'
                                        */
  real_T Constant7_Value[656];         /* Expression: Fi_XdirFF
                                        * Referenced by: '<S43>/Constant7'
                                        */
  real_T Constant8_Value[164];         /* Expression: Gi_XdirFF
                                        * Referenced by: '<S43>/Constant8'
                                        */
  real_T Constant9_Value[164];         /* Expression: Nc_XdirFF
                                        * Referenced by: '<S43>/Constant9'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 0.2094
                                        * Referenced by: '<S31>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -0.2094
                                        * Referenced by: '<S31>/Saturation4'
                                        */
  real_T UnitDelay2_X0_m;              /* Expression: 0
                                        * Referenced by: '<S48>/Unit Delay2'
                                        */
  real_T UnitDelay_X0;                 /* Expression: 0
                                        * Referenced by: '<S48>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: .33333
                                        * Referenced by: '<S48>/Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T SliderGain_Gain_g;            /* Expression: gain
                                        * Referenced by: '<S37>/Slider Gain'
                                        */
  real_T SliderGain_Gain_ba;           /* Expression: gain
                                        * Referenced by: '<S38>/Slider Gain'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 0.017453292519943
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T Constant1_Value_m;            /* Expression: 1
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T SliderGain_Gain_k;            /* Expression: gain
                                        * Referenced by: '<S39>/Slider Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.017453292519943
                                        * Referenced by: '<S29>/Gain1'
                                        */
  real_T Constant2_Value_h;            /* Expression: 1
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T SliderGain_Gain_f;            /* Expression: gain
                                        * Referenced by: '<S40>/Slider Gain'
                                        */
  real_T gravity_Value;                /* Expression: g
                                        * Referenced by: '<S11>/gravity'
                                        */
  real_T Constant1_Value_d;            /* Expression: 1
                                        * Referenced by: '<S32>/Constant1'
                                        */
  real_T SliderGain_Gain_j;            /* Expression: gain
                                        * Referenced by: '<S74>/Slider Gain'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 0.017453292519943
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 0.2094
                                        * Referenced by: '<S32>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -0.2094
                                        * Referenced by: '<S32>/Saturation'
                                        */
  real_T Saturation1_UpperSat_ou;      /* Expression: 2
                                        * Referenced by: '<S32>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_c;       /* Expression: -2
                                        * Referenced by: '<S32>/Saturation1'
                                        */
  real_T SliderGain_Gain_gm;           /* Expression: gain
                                        * Referenced by: '<S71>/Slider Gain'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T SliderGain_Gain_be;           /* Expression: gain
                                        * Referenced by: '<S70>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_n;       /* Expression: 1
                                        * Referenced by: '<S32>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_c;       /* Expression: -1
                                        * Referenced by: '<S32>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_b;       /* Expression: 1
                                        * Referenced by: '<S32>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_hu;      /* Expression: -1
                                        * Referenced by: '<S32>/Saturation2'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S73>/Constant'
                                        */
  real_T SliderGain_Gain_p;            /* Expression: gain
                                        * Referenced by: '<S81>/Slider Gain'
                                        */
  real_T Constant1_Value_dx;           /* Expression: 1
                                        * Referenced by: '<S73>/Constant1'
                                        */
  real_T SliderGain_Gain_g3;           /* Expression: gain
                                        * Referenced by: '<S82>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_lg;      /* Expression: 0.1
                                        * Referenced by: '<S73>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_b;       /* Expression: -1
                                        * Referenced by: '<S73>/Saturation3'
                                        */
  real_T Constant_Value_co[25];        /* Expression: Aff_roll
                                        * Referenced by: '<S76>/Constant'
                                        */
  real_T Constant1_Value_g[10];        /* Expression: Bff_roll
                                        * Referenced by: '<S76>/Constant1'
                                        */
  real_T UnitDelay2_X0_d;              /* Expression: 0
                                        * Referenced by: '<S68>/Unit Delay2'
                                        */
  real_T Constant_Value_ln[16805];     /* Expression: Hn_Ydir
                                        * Referenced by: '<S68>/Constant'
                                        */
  real_T Constant1_Value_j[3361];      /* Expression: Kn_Ydir
                                        * Referenced by: '<S68>/Constant1'
                                        */
  real_T Constant2_Value_j[1590];      /* Expression: Fi_Ydir
                                        * Referenced by: '<S68>/Constant2'
                                        */
  real_T Constant3_Value_o[318];       /* Expression: Gi_Ydir
                                        * Referenced by: '<S68>/Constant3'
                                        */
  real_T Constant4_Value_g[318];       /* Expression: Nc_Ydir
                                        * Referenced by: '<S68>/Constant4'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S72>/Constant'
                                        */
  real_T SliderGain_Gain_m;            /* Expression: gain
                                        * Referenced by: '<S79>/Slider Gain'
                                        */
  real_T Saturation4_UpperSat_i;       /* Expression: 0.2094
                                        * Referenced by: '<S32>/Saturation4'
                                        */
  real_T Saturation4_LowerSat_h;       /* Expression: -0.2094
                                        * Referenced by: '<S32>/Saturation4'
                                        */
  real_T UnitDelay2_X0_n;              /* Expression: 0
                                        * Referenced by: '<S69>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_f;               /* Expression: 0
                                        * Referenced by: '<S69>/Unit Delay'
                                        */
  real_T Gain_Gain_fn;                 /* Expression: .33333
                                        * Referenced by: '<S69>/Gain'
                                        */
  real_T Saturation1_UpperSat_d;       /* Expression: 1
                                        * Referenced by: '<S35>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -1
                                        * Referenced by: '<S35>/Saturation1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1
                                        * Referenced by: '<S35>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -1
                                        * Referenced by: '<S35>/Saturation'
                                        */
  real_T Constant_Value_fz;            /* Expression: 1
                                        * Referenced by: '<S101>/Constant'
                                        */
  real_T SliderGain_Gain_d;            /* Expression: gain
                                        * Referenced by: '<S106>/Slider Gain'
                                        */
  real_T Constant1_Value_l;            /* Expression: 1
                                        * Referenced by: '<S101>/Constant1'
                                        */
  real_T SliderGain_Gain_ds;           /* Expression: gain
                                        * Referenced by: '<S107>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_nh;      /* Expression: .1
                                        * Referenced by: '<S101>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_e;       /* Expression: -1
                                        * Referenced by: '<S101>/Saturation3'
                                        */
  real_T Constant_Value_b[624];        /* Expression: Hn_Zdir
                                        * Referenced by: '<S97>/Constant'
                                        */
  real_T Constant1_Value_li[208];      /* Expression: Kn_Zdir
                                        * Referenced by: '<S97>/Constant1'
                                        */
  real_T Constant2_Value_g[90];        /* Expression: Fi_Zdir
                                        * Referenced by: '<S97>/Constant2'
                                        */
  real_T Constant3_Value_m[30];        /* Expression: Gi_Zdir
                                        * Referenced by: '<S97>/Constant3'
                                        */
  real_T Constant4_Value_a[30];        /* Expression: Nc_Zdir
                                        * Referenced by: '<S97>/Constant4'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S100>/Constant'
                                        */
  real_T SliderGain_Gain_mb;           /* Expression: gain
                                        * Referenced by: '<S104>/Slider Gain'
                                        */
  real_T SliderGain_Gain_c;            /* Expression: gain
                                        * Referenced by: '<S99>/Slider Gain'
                                        */
  real_T Saturation2_UpperSat_kw;      /* Expression: 1
                                        * Referenced by: '<S35>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_j;       /* Expression: -1
                                        * Referenced by: '<S35>/Saturation2'
                                        */
  real_T UnitDelay2_X0_o;              /* Expression: 0
                                        * Referenced by: '<S98>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_i;               /* Expression: 0
                                        * Referenced by: '<S98>/Unit Delay'
                                        */
  real_T Gain_Gain_p;                  /* Expression: .33333
                                        * Referenced by: '<S98>/Gain'
                                        */
  real_T UnitDelay_X0_m;               /* Expression: 0
                                        * Referenced by: '<S33>/Unit Delay'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real_T SliderGain_Gain_a;            /* Expression: gain
                                        * Referenced by: '<S89>/Slider Gain'
                                        */
  real_T Constant2_Value_l;            /* Expression: 1
                                        * Referenced by: '<S33>/Constant2'
                                        */
  real_T SliderGain_Gain_pq;           /* Expression: gain
                                        * Referenced by: '<S90>/Slider Gain'
                                        */
  real_T SliderGain_Gain_ai;           /* Expression: gain
                                        * Referenced by: '<S88>/Slider Gain'
                                        */
  real_T Constant_Value_fv;            /* Expression: 1
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T SliderGain_Gain_jt;           /* Expression: gain
                                        * Referenced by: '<S87>/Slider Gain'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: pi
                                        * Referenced by: '<S33>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -pi
                                        * Referenced by: '<S33>/Saturation'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S92>/Constant'
                                        */
  real_T Constant1_Value_m3;           /* Expression: 0
                                        * Referenced by: '<S92>/Constant1'
                                        */
  real_T UnitDelay2_X0_ng;             /* Expression: 0
                                        * Referenced by: '<S83>/Unit Delay2'
                                        */
  real_T Constant_Value_a[6];          /* Expression: Hn_Yaw
                                        * Referenced by: '<S83>/Constant'
                                        */
  real_T Constant1_Value_gs[6];        /* Expression: Kn_Yaw
                                        * Referenced by: '<S83>/Constant1'
                                        */
  real_T Constant2_Value_jq[3];        /* Expression: Fi_Yaw
                                        * Referenced by: '<S83>/Constant2'
                                        */
  real_T Constant3_Value_b[3];         /* Expression: Gi_Yaw
                                        * Referenced by: '<S83>/Constant3'
                                        */
  real_T Constant4_Value_gb[3];        /* Expression: Nc_Yaw
                                        * Referenced by: '<S83>/Constant4'
                                        */
  real_T Saturation1_UpperSat_g;       /* Expression: pi
                                        * Referenced by: '<S33>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_b;       /* Expression: -pi
                                        * Referenced by: '<S33>/Saturation1'
                                        */
  real_T UnitDelay2_X0_i;              /* Expression: 0
                                        * Referenced by: '<S86>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_c;               /* Expression: 0
                                        * Referenced by: '<S86>/Unit Delay'
                                        */
  real_T Gain_Gain_p0;                 /* Expression: .33333
                                        * Referenced by: '<S86>/Gain'
                                        */
  real_T UnitDelay1_X0_i;              /* Expression: 0
                                        * Referenced by: '<S48>/Unit Delay1'
                                        */
  real_T UnitDelay_X0_d;               /* Expression: 0
                                        * Referenced by: '<S31>/Unit Delay'
                                        */
  real_T Constant_Value_d;             /* Expression: 1
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T SliderGain_Gain_mg;           /* Expression: gain
                                        * Referenced by: '<S58>/Slider Gain'
                                        */
  real_T Constant_Value_p[16];         /* Expression: Ax
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T Constant1_Value_l0[4];        /* Expression: Bx
                                        * Referenced by: '<S59>/Constant1'
                                        */
  real_T Constant2_Value_gl[16];       /* Expression: Cx
                                        * Referenced by: '<S59>/Constant2'
                                        */
  real_T UnitDelay_X0_a[4];            /* Expression: zeros(4,1)
                                        * Referenced by: '<S59>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_ic[16];         /* Expression: zeros(4,4)
                                        * Referenced by: '<S59>/Unit Delay1'
                                        */
  real_T Constant3_Value_h[16];        /* Expression:  kalm_mpc_x.Q
                                        * Referenced by: '<S59>/Constant3'
                                        */
  real_T Constant4_Value_n[16];        /* Expression: .1*kalm_mpc_x.Q
                                        * Referenced by: '<S59>/Constant4'
                                        */
  real_T UnitDelay_X0_if;              /* Expression: 0
                                        * Referenced by: '<S60>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_dy;             /* Expression: 0
                                        * Referenced by: '<S69>/Unit Delay1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 57
                                        * Referenced by: '<S33>/Gain'
                                        */
  real_T UnitDelay1_X0_j;              /* Expression: 0
                                        * Referenced by: '<S86>/Unit Delay1'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 57
                                        * Referenced by: '<S34>/Gain1'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 57
                                        * Referenced by: '<S34>/Gain'
                                        */
  real_T UnitDelay1_X0_f;              /* Expression: 0
                                        * Referenced by: '<S98>/Unit Delay1'
                                        */
  real_T g_Value;                      /* Expression: g
                                        * Referenced by: '<S133>/g'
                                        */
  real_T Constant_Value_ks;            /* Expression: 1
                                        * Referenced by: '<S136>/Constant'
                                        */
  real_T SliderGain_Gain_n;            /* Expression: gain
                                        * Referenced by: '<S138>/Slider Gain'
                                        */
  real_T Constant1_Value_i;            /* Expression: 1
                                        * Referenced by: '<S136>/Constant1'
                                        */
  real_T SliderGain_Gain_i;            /* Expression: gain
                                        * Referenced by: '<S139>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_p;       /* Expression: 0
                                        * Referenced by: '<S136>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_es;      /* Expression: -1
                                        * Referenced by: '<S136>/Saturation3'
                                        */
  real_T X_ref_x_Value[909];           /* Expression: traj_FG.X_ref_x
                                        * Referenced by: '<S116>/X_ref_x'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S115>/Constant'
                                        */
  real_T SliderGain_Gain_e;            /* Expression: gain
                                        * Referenced by: '<S127>/Slider Gain'
                                        */
  real_T Constant1_Value_e;            /* Expression: 1
                                        * Referenced by: '<S115>/Constant1'
                                        */
  real_T SliderGain_Gain_jr;           /* Expression: gain
                                        * Referenced by: '<S128>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_f;       /* Expression: 0
                                        * Referenced by: '<S115>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_lw;      /* Expression: -1
                                        * Referenced by: '<S115>/Saturation3'
                                        */
  real_T UnitDelay_2_X0;               /* Expression: 0
                                        * Referenced by: '<S108>/Unit Delay'
                                        */
  real_T UnitDelay_3_X0;               /* Expression: 0
                                        * Referenced by: '<S108>/Unit Delay'
                                        */
  real_T Constant1_Value_j2;           /* Expression: 1
                                        * Referenced by: '<S108>/Constant1'
                                        */
  real_T SliderGain_Gain_db;           /* Expression: gain
                                        * Referenced by: '<S114>/Slider Gain'
                                        */
  real_T Constant_Value_le;            /* Expression: 1
                                        * Referenced by: '<S108>/Constant'
                                        */
  real_T SliderGain_Gain_ne;           /* Expression: gain
                                        * Referenced by: '<S113>/Slider Gain'
                                        */
  real_T Constant_Value_kb;            /* Expression: 1
                                        * Referenced by: '<S112>/Constant'
                                        */
  real_T SliderGain_Gain_dsh;          /* Expression: gain
                                        * Referenced by: '<S121>/Slider Gain'
                                        */
  real_T SliderGain_Gain_cx;           /* Expression: gain
                                        * Referenced by: '<S122>/Slider Gain'
                                        */
  real_T Constant1_Value_kj;           /* Expression: 1
                                        * Referenced by: '<S112>/Constant1'
                                        */
  real_T SliderGain_Gain_mi;           /* Expression: gain
                                        * Referenced by: '<S123>/Slider Gain'
                                        */
  real_T Constant2_Value_c;            /* Expression: 1
                                        * Referenced by: '<S112>/Constant2'
                                        */
  real_T SliderGain_Gain_nu;           /* Expression: gain
                                        * Referenced by: '<S124>/Slider Gain'
                                        */
  real_T Constant3_Value_f;            /* Expression: 1
                                        * Referenced by: '<S112>/Constant3'
                                        */
  real_T SliderGain_Gain_ka;           /* Expression: gain
                                        * Referenced by: '<S125>/Slider Gain'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S112>/Switch1'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0.5
                                        * Referenced by: '<S112>/Switch'
                                        */
  real_T SliderGain_Gain_h;            /* Expression: gain
                                        * Referenced by: '<S110>/Slider Gain'
                                        */
  real_T TotalSamples_Value;           /* Expression: traj_FG.total_samples -1
                                        * Referenced by: '<S108>/Total Samples'
                                        */
  real_T UnitDelay1_X0_ie;             /* Expression: 0
                                        * Referenced by: '<S108>/Unit Delay1'
                                        */
  real_T UnitDelay_X0_o;               /* Expression: 0
                                        * Referenced by: '<S116>/Unit Delay'
                                        */
  real_T total_samples_Value;          /* Expression: traj_FG.total_samples
                                        * Referenced by: '<S116>/total_samples'
                                        */
  real_T Constant1_Value_mu;           /* Expression: 1
                                        * Referenced by: '<S116>/Constant1'
                                        */
  real_T X_ref_x_Value_n[909];         /* Expression: traj_FG.X_ref_x
                                        * Referenced by: '<S18>/X_ref_x'
                                        */
  real_T Constant_Value_lw;            /* Expression: 1
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T UnitDelay_X0_e;               /* Expression: 0
                                        * Referenced by: '<S18>/Unit Delay'
                                        */
  real_T total_samples_Value_h;        /* Expression: traj_FG.total_samples
                                        * Referenced by: '<S18>/total_samples'
                                        */
  real_T Constant1_Value_o;            /* Expression: 1
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T X_ref_y_Value[909];           /* Expression: traj_FG.X_ref_y
                                        * Referenced by: '<S116>/X_ref_y'
                                        */
  real_T X_ref_y_Value_f[909];         /* Expression: traj_FG.X_ref_y
                                        * Referenced by: '<S18>/X_ref_y'
                                        */
  real_T X_ref_z_Value[606];           /* Expression: traj_FG.X_ref_z
                                        * Referenced by: '<S116>/X_ref_z'
                                        */
  real_T X_ref_z_Value_p[606];         /* Expression: traj_FG.X_ref_z
                                        * Referenced by: '<S18>/X_ref_z'
                                        */
  real_T X_ref_yaw_Value[606];         /* Expression: traj_FG.X_ref_yaw
                                        * Referenced by: '<S116>/X_ref_yaw'
                                        */
  real_T X_ref_yaw_Value_i[606];       /* Expression: traj_FG.X_ref_yaw
                                        * Referenced by: '<S18>/X_ref_yaw'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 0
                                        * Referenced by: '<S18>/Gain'
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
  real_T Constant_Value_kh;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Constant1_Value_h;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T UnitDelay_X0_b;               /* Expression: 0
                                        * Referenced by: '<S17>/Unit Delay'
                                        */
  real_T total_samples_Value_k;        /* Expression: traj_FG.total_samples
                                        * Referenced by: '<S17>/total_samples'
                                        */
  real_T X_ref_x_Value_k[909];         /* Expression: traj_FG.X_ref_x
                                        * Referenced by: '<S17>/X_ref_x'
                                        */
  real_T X_ref_y_Value_e[909];         /* Expression: traj_FG.X_ref_y
                                        * Referenced by: '<S17>/X_ref_y'
                                        */
  real_T X_ref_yaw_Value_f[606];       /* Expression: traj_FG.X_ref_yaw
                                        * Referenced by: '<S17>/X_ref_yaw'
                                        */
  real_T X_ref_z_Value_a[606];         /* Expression: traj_FG.X_ref_z
                                        * Referenced by: '<S17>/X_ref_z'
                                        */
  real_T Gain_Gain_d;                  /* Expression: -1
                                        * Referenced by: '<S108>/Gain'
                                        */
  real_T UnitDelay_X0_l;               /* Expression: 0
                                        * Referenced by: '<S111>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_js;             /* Expression: 0
                                        * Referenced by: '<S111>/Unit Delay1'
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
                                        * Referenced by: '<S149>/Integer Delay'
                                        */
  real_T IntegerDelay1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S149>/Integer Delay1'
                                         */
  real_T IntegerDelay2_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S149>/Integer Delay2'
                                         */
  real_T IntegerDelay3_InitialConditio_c;/* Expression: 0.0
                                          * Referenced by: '<S149>/Integer Delay3'
                                          */
  real_T gravity_Value_j;              /* Expression: g
                                        * Referenced by: '<S149>/gravity'
                                        */
  real_T TT_PP_Value[900];             /* Expression: FG_ctrl_x.TT_PP
                                        * Referenced by: '<S155>/TT_PP'
                                        */
  real_T LL_PP_Value[90];              /* Expression: FG_ctrl_x.LL_PP
                                        * Referenced by: '<S155>/LL_PP'
                                        */
  real_T LL_ref_PP_Value[2790];        /* Expression: FG_ctrl_x.LL_ref_PP
                                        * Referenced by: '<S155>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value[900];       /* Expression: FG_ctrl_x.LL_U_ref_PP
                                        * Referenced by: '<S155>/LL_U_ref_PP'
                                        */
  real_T MM_Value[9];                  /* Expression: FG_ctrl_x.MM
                                        * Referenced by: '<S155>/MM'
                                        */
  real_T PP_Value[900];                /* Expression: FG_ctrl_x.PP
                                        * Referenced by: '<S155>/PP'
                                        */
  real_T AA_delay_Value[9];            /* Expression: FG_ctrl_x.AA_delay
                                        * Referenced by: '<S155>/AA_delay'
                                        */
  real_T BB_delay_Value[9];            /* Expression: FG_ctrl_x.BB_delay
                                        * Referenced by: '<S155>/BB_delay'
                                        */
  real_T A_Value_h[16];                /* Expression: kalm_mpc_x.A
                                        * Referenced by: '<S156>/A'
                                        */
  real_T B_Value_i[4];                 /* Expression: kalm_mpc_x.B
                                        * Referenced by: '<S156>/B'
                                        */
  real_T C_Value_c[12];                /* Expression: kalm_mpc_x.C
                                        * Referenced by: '<S156>/C'
                                        */
  real_T D_Value_l[3];                 /* Expression: kalm_mpc_x.D
                                        * Referenced by: '<S156>/D'
                                        */
  real_T Q_Value_a[16];                /* Expression: kalm_mpc_x.Q
                                        * Referenced by: '<S156>/Q'
                                        */
  real_T R_Value_c[9];                 /* Expression: kalm_mpc_x.R
                                        * Referenced by: '<S156>/R'
                                        */
  real_T UnitDelay1_X0_c[16];          /* Expression: kalm_mpc_x.P
                                        * Referenced by: '<S156>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_f;         /* Expression: 0.0
                                        * Referenced by: '<S164>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value[30];              /* Expression: FG_ctrl_x.V_max
                                        * Referenced by: '<S155>/V_max'
                                        */
  real_T i_min_Value;                  /* Expression: FG_ctrl_x.i_min
                                        * Referenced by: '<S155>/i_min'
                                        */
  real_T betas_Value[7];               /* Expression: FG_ctrl_x.betas
                                        * Referenced by: '<S155>/betas'
                                        */
  real_T L_Value;                      /* Expression: FG_ctrl_x.L
                                        * Referenced by: '<S155>/L'
                                        */
  real_T UnitDelay_X0_fc[3];           /* Expression: zeros(FG_ctrl_x.delay_steps,1)
                                        * Referenced by: '<S155>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_k[30];          /* Expression: zeros(size(FG_ctrl_x.V_max,1),1)
                                        * Referenced by: '<S155>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_ia;       /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S156>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S156>/Saturation'
                                        */
  real_T TT_PP_Value_m[900];           /* Expression: FG_ctrl_y.TT_PP
                                        * Referenced by: '<S157>/TT_PP'
                                        */
  real_T LL_PP_Value_e[90];            /* Expression: FG_ctrl_y.LL_PP
                                        * Referenced by: '<S157>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_l[2790];      /* Expression: FG_ctrl_y.LL_ref_PP
                                        * Referenced by: '<S157>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_m[900];     /* Expression: FG_ctrl_y.LL_U_ref_PP
                                        * Referenced by: '<S157>/LL_U_ref_PP'
                                        */
  real_T MM_Value_c[9];                /* Expression: FG_ctrl_y.MM
                                        * Referenced by: '<S157>/MM'
                                        */
  real_T PP_Value_m[900];              /* Expression: FG_ctrl_y.PP
                                        * Referenced by: '<S157>/PP'
                                        */
  real_T AA_delay_Value_h[9];          /* Expression: FG_ctrl_y.AA_delay
                                        * Referenced by: '<S157>/AA_delay'
                                        */
  real_T BB_delay_Value_o[9];          /* Expression: FG_ctrl_y.BB_delay
                                        * Referenced by: '<S157>/BB_delay'
                                        */
  real_T A_Value_n[16];                /* Expression: kalm_mpc_y.A
                                        * Referenced by: '<S158>/A'
                                        */
  real_T B_Value_h[4];                 /* Expression: kalm_mpc_y.B
                                        * Referenced by: '<S158>/B'
                                        */
  real_T C_Value_p[12];                /* Expression: kalm_mpc_y.C
                                        * Referenced by: '<S158>/C'
                                        */
  real_T D_Value_m[3];                 /* Expression: kalm_mpc_y.D
                                        * Referenced by: '<S158>/D'
                                        */
  real_T Q_Value_h[16];                /* Expression: kalm_mpc_y.Q
                                        * Referenced by: '<S158>/Q'
                                        */
  real_T R_Value_l[9];                 /* Expression: kalm_mpc_y.R
                                        * Referenced by: '<S158>/R'
                                        */
  real_T UnitDelay1_X0_fk[16];         /* Expression: kalm_mpc_y.P
                                        * Referenced by: '<S158>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_n;         /* Expression: 0.0
                                        * Referenced by: '<S167>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_o[30];            /* Expression: FG_ctrl_y.V_max
                                        * Referenced by: '<S157>/V_max'
                                        */
  real_T i_min_Value_j;                /* Expression: FG_ctrl_y.i_min
                                        * Referenced by: '<S157>/i_min'
                                        */
  real_T betas_Value_l[7];             /* Expression: FG_ctrl_y.betas
                                        * Referenced by: '<S157>/betas'
                                        */
  real_T L_Value_n;                    /* Expression: FG_ctrl_y.L
                                        * Referenced by: '<S157>/L'
                                        */
  real_T UnitDelay_X0_ik[3];           /* Expression: zeros(FG_ctrl_y.delay_steps,1)
                                        * Referenced by: '<S157>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_jc[30];         /* Expression: zeros(size(FG_ctrl_y.V_max,1),1)
                                        * Referenced by: '<S157>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S158>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S158>/Saturation'
                                        */
  real_T TT_PP_Value_b[900];           /* Expression: FG_ctrl_z.TT_PP
                                        * Referenced by: '<S161>/TT_PP'
                                        */
  real_T LL_PP_Value_j[60];            /* Expression: FG_ctrl_z.LL_PP
                                        * Referenced by: '<S161>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_h[1860];      /* Expression: FG_ctrl_z.LL_ref_PP
                                        * Referenced by: '<S161>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_o[900];     /* Expression: FG_ctrl_z.LL_U_ref_PP
                                        * Referenced by: '<S161>/LL_U_ref_PP'
                                        */
  real_T MM_Value_l[4];                /* Expression: FG_ctrl_z.MM
                                        * Referenced by: '<S161>/MM'
                                        */
  real_T PP_Value_o[900];              /* Expression: FG_ctrl_z.PP
                                        * Referenced by: '<S161>/PP'
                                        */
  real_T AA_delay_Value_l[4];          /* Expression: FG_ctrl_z.AA_delay
                                        * Referenced by: '<S161>/AA_delay'
                                        */
  real_T BB_delay_Value_b[4];          /* Expression: FG_ctrl_z.BB_delay
                                        * Referenced by: '<S161>/BB_delay'
                                        */
  real_T A_Value_f[9];                 /* Expression: kalm_mpc_z.A
                                        * Referenced by: '<S162>/A'
                                        */
  real_T B_Value_n[3];                 /* Expression: kalm_mpc_z.B
                                        * Referenced by: '<S162>/B'
                                        */
  real_T C_Value_o[6];                 /* Expression: kalm_mpc_z.C
                                        * Referenced by: '<S162>/C'
                                        */
  real_T D_Value_j[2];                 /* Expression: kalm_mpc_z.D
                                        * Referenced by: '<S162>/D'
                                        */
  real_T Q_Value_j[9];                 /* Expression: kalm_mpc_z.Q
                                        * Referenced by: '<S162>/Q'
                                        */
  real_T R_Value_ca[4];                /* Expression: kalm_mpc_z.R
                                        * Referenced by: '<S162>/R'
                                        */
  real_T UnitDelay1_X0_cw[9];          /* Expression: kalm_mpc_z.P
                                        * Referenced by: '<S162>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_c;         /* Expression: 0.0
                                        * Referenced by: '<S173>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_i[30];            /* Expression: FG_ctrl_z.V_max
                                        * Referenced by: '<S161>/V_max'
                                        */
  real_T i_min_Value_o;                /* Expression: FG_ctrl_z.i_min
                                        * Referenced by: '<S161>/i_min'
                                        */
  real_T betas_Value_g[8];             /* Expression: FG_ctrl_z.betas
                                        * Referenced by: '<S161>/betas'
                                        */
  real_T L_Value_m;                    /* Expression: FG_ctrl_z.L
                                        * Referenced by: '<S161>/L'
                                        */
  real_T UnitDelay_X0_a2[2];           /* Expression: zeros(FG_ctrl_z.delay_steps,1)
                                        * Referenced by: '<S161>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_b[30];          /* Expression: zeros(size(FG_ctrl_z.V_max,1),1)
                                        * Referenced by: '<S161>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: MAX_BIAS_THRUST
                                        * Referenced by: '<S162>/Saturation'
                                        */
  real_T Saturation_LowerSat_cp;       /* Expression: -MAX_BIAS_THRUST
                                        * Referenced by: '<S162>/Saturation'
                                        */
  real_T TT_PP_Value_o[900];           /* Expression: FG_ctrl_yaw.TT_PP
                                        * Referenced by: '<S159>/TT_PP'
                                        */
  real_T LL_PP_Value_j5[60];           /* Expression: FG_ctrl_yaw.LL_PP
                                        * Referenced by: '<S159>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_e[1860];      /* Expression: FG_ctrl_yaw.LL_ref_PP
                                        * Referenced by: '<S159>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_b[900];     /* Expression: FG_ctrl_yaw.LL_U_ref_PP
                                        * Referenced by: '<S159>/LL_U_ref_PP'
                                        */
  real_T MM_Value_g[4];                /* Expression: FG_ctrl_yaw.MM
                                        * Referenced by: '<S159>/MM'
                                        */
  real_T PP_Value_p[900];              /* Expression: FG_ctrl_yaw.PP
                                        * Referenced by: '<S159>/PP'
                                        */
  real_T AA_delay_Value_o[4];          /* Expression: FG_ctrl_yaw.AA_delay
                                        * Referenced by: '<S159>/AA_delay'
                                        */
  real_T BB_delay_Value_d[12];         /* Expression: FG_ctrl_yaw.BB_delay
                                        * Referenced by: '<S159>/BB_delay'
                                        */
  real_T A_Value_k[9];                 /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S160>/A'
                                        */
  real_T B_Value_f[3];                 /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S160>/B'
                                        */
  real_T C_Value_b[6];                 /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S160>/C'
                                        */
  real_T D_Value_c[2];                 /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S160>/D'
                                        */
  real_T Q_Value_g[9];                 /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S160>/Q'
                                        */
  real_T R_Value_o[4];                 /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S160>/R'
                                        */
  real_T UnitDelay1_X0_n[9];           /* Expression: kalm_mpc_yaw.P
                                        * Referenced by: '<S160>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_e;         /* Expression: 0.0
                                        * Referenced by: '<S170>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_f[30];            /* Expression: FG_ctrl_yaw.V_max
                                        * Referenced by: '<S159>/V_max'
                                        */
  real_T i_min_Value_n;                /* Expression: FG_ctrl_yaw.i_min
                                        * Referenced by: '<S159>/i_min'
                                        */
  real_T betas_Value_j[5];             /* Expression: FG_ctrl_yaw.betas
                                        * Referenced by: '<S159>/betas'
                                        */
  real_T L_Value_g;                    /* Expression: FG_ctrl_yaw.L
                                        * Referenced by: '<S159>/L'
                                        */
  real_T UnitDelay_X0_fj[6];           /* Expression: zeros(FG_ctrl_yaw.delay_steps,1)
                                        * Referenced by: '<S159>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_o[30];          /* Expression: zeros(size(FG_ctrl_yaw.V_max,1),1)
                                        * Referenced by: '<S159>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_o3;       /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S160>/Saturation'
                                        */
  real_T Saturation_LowerSat_kn;       /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S160>/Saturation'
                                        */
  real_T g_Value_m;                    /* Expression: g
                                        * Referenced by: '<S175>/g'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 1
                                        * Referenced by: '<S153>/Gain'
                                        */
  real_T raddeg2_Gain_p;               /* Expression: 180/pi
                                        * Referenced by: '<S153>/rad -> deg2'
                                        */
  real_T raddeg1_Gain_a;               /* Expression: 180/pi
                                        * Referenced by: '<S153>/rad -> deg1'
                                        */
  real_T raddeg3_Gain_k;               /* Expression: 180/pi
                                        * Referenced by: '<S153>/rad -> deg3'
                                        */
  real_T raddeg_Gain_k;                /* Expression: 180/pi
                                        * Referenced by: '<S153>/rad -> deg'
                                        */
  real_T pitch_offset_Value;           /* Expression: 0.00
                                        * Referenced by: '<S7>/pitch_offset'
                                        */
  real_T InitialCondition_Value;       /* Expression: vinit
                                        * Referenced by: '<S148>/Initial Condition'
                                        */
  real_T Constant1_Value_mr;           /* Expression: 1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T FixPtUnitDelay1_X0_h;         /* Expression: vinit
                                        * Referenced by: '<S148>/FixPt Unit Delay1'
                                        */
  real_T Constant_Value_pe;            /* Expression: 1
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
                                        * Referenced by: '<S145>/Slider Gain'
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
  real_T SliderGain_Gain_o;            /* Expression: gain
                                        * Referenced by: '<S143>/Slider Gain'
                                        */
  real_T SliderGain_Gain_mn;           /* Expression: gain
                                        * Referenced by: '<S144>/Slider Gain'
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
                                        * Referenced by: '<S149>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength;  /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S149>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength;  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S149>/Integer Delay2'
                                        */
  uint32_T IntegerDelay3_DelayLength_o;/* Computed Parameter: IntegerDelay3_DelayLength_o
                                        * Referenced by: '<S149>/Integer Delay3'
                                        */
  uint8_T FixPtUnitDelay2_X0;          /* Computed Parameter: FixPtUnitDelay2_X0
                                        * Referenced by: '<S95>/FixPt Unit Delay2'
                                        */
  uint8_T Constant_Value_ki;           /* Expression: uint8(1)
                                        * Referenced by: '<S28>/Constant'
                                        */
  uint8_T Constant_Value_lwi;          /* Expression: uint8(1)
                                        * Referenced by: '<S46>/Constant'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(0)
                                        * Referenced by: '<S46>/SwitchControl'
                                        */
  uint8_T Constant_Value_j;            /* Expression: uint8(1)
                                        * Referenced by: '<S47>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_a;   /* Expression: uint8(0)
                                        * Referenced by: '<S47>/SwitchControl'
                                        */
  uint8_T SwitchControl_Threshold_g;   /* Expression: uint8(1)
                                        * Referenced by: '<S28>/SwitchControl'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S95>/FixPt Constant'
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
                                        * Referenced by: '<S164>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_n;        /* Computed Parameter: FixPtUnitDelay2_X0_n
                                        * Referenced by: '<S167>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_do;       /* Computed Parameter: FixPtUnitDelay2_X0_do
                                        * Referenced by: '<S173>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_i;        /* Computed Parameter: FixPtUnitDelay2_X0_i
                                        * Referenced by: '<S170>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtConstant_Value_h;       /* Computed Parameter: FixPtConstant_Value_h
                                        * Referenced by: '<S164>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_o;       /* Computed Parameter: FixPtConstant_Value_o
                                        * Referenced by: '<S167>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_n;       /* Computed Parameter: FixPtConstant_Value_n
                                        * Referenced by: '<S170>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_p;       /* Computed Parameter: FixPtConstant_Value_p
                                        * Referenced by: '<S173>/FixPt Constant'
                                        */
  uint8_T FixPtUnitDelay2_X0_g;        /* Computed Parameter: FixPtUnitDelay2_X0_g
                                        * Referenced by: '<S148>/FixPt Unit Delay2'
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
                                        * Referenced by: '<S142>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_ef;  /* Expression: uint8(0)
                                        * Referenced by: '<S142>/SwitchControl'
                                        */
  uint8_T FixPtConstant_Value_i;       /* Computed Parameter: FixPtConstant_Value_i
                                        * Referenced by: '<S148>/FixPt Constant'
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
 * '<S18>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj1'
 * '<S19>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/get ref from vector'
 * '<S20>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_x'
 * '<S21>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_y'
 * '<S22>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_yaw'
 * '<S23>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj/generate_X_ref_z'
 * '<S24>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj1/generate_X_ref_x'
 * '<S25>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj1/generate_X_ref_y'
 * '<S26>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj1/generate_X_ref_yaw'
 * '<S27>'  : 'controller_template/FreeFlight Pos Ctrl/Free Flight Reference/create traj1/generate_X_ref_z'
 * '<S28>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/FreeFlight'
 * '<S29>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem'
 * '<S30>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/demux'
 * '<S31>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S32>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S33>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S34>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S35>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S36>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/MATLAB Function'
 * '<S37>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/Slider Gain'
 * '<S38>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/Slider Gain1'
 * '<S39>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/Slider Gain2'
 * '<S40>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/Slider Gain3'
 * '<S41>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/Slider Gain4'
 * '<S42>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/Slider Gain5'
 * '<S43>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight'
 * '<S44>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid'
 * '<S45>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Free Flight'
 * '<S46>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Manual Switch'
 * '<S47>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Manual Switch1'
 * '<S48>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Mean'
 * '<S49>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem'
 * '<S50>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation'
 * '<S51>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/Ctrl_Xdir'
 * '<S52>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/PitchPropagateFF'
 * '<S53>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/PitchPropagateFF/MATLAB Function'
 * '<S54>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/Ctrl_Xdir'
 * '<S55>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/PitchPropagate'
 * '<S56>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/PitchPropagate/MATLAB Function'
 * '<S57>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem/MATLAB Function1'
 * '<S58>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem/Slider Gain'
 * '<S59>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem/Subsystem'
 * '<S60>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem/Subsystem1'
 * '<S61>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem/Subsystem/MATLAB Function'
 * '<S62>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem/Subsystem/Subsystem'
 * '<S63>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem/Subsystem/Subsystem/MATLAB Function'
 * '<S64>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Subsystem/Subsystem1/MATLAB Function'
 * '<S65>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation/MATLAB Function'
 * '<S66>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation/Slider Gain1'
 * '<S67>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation/Slider Gain2'
 * '<S68>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1'
 * '<S69>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Mean'
 * '<S70>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Slider Gain'
 * '<S71>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Slider Gain1'
 * '<S72>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Subsystem'
 * '<S73>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Wall Deviation'
 * '<S74>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/comp_cable'
 * '<S75>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S76>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate'
 * '<S77>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate/MATLAB Function'
 * '<S78>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Subsystem/MATLAB Function'
 * '<S79>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Subsystem/Slider Gain2'
 * '<S80>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Wall Deviation/MATLAB Function'
 * '<S81>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Wall Deviation/Slider Gain'
 * '<S82>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Wall Deviation/Slider Gain2'
 * '<S83>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1'
 * '<S84>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/MATLAB Function'
 * '<S85>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/MATLAB Function1'
 * '<S86>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Mean'
 * '<S87>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain'
 * '<S88>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain1'
 * '<S89>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain2'
 * '<S90>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain3'
 * '<S91>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S92>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate'
 * '<S93>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate/MATLAB Function'
 * '<S94>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/MATLAB Function'
 * '<S95>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S96>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S97>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1'
 * '<S98>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Mean'
 * '<S99>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Slider Gain'
 * '<S100>' : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Subsystem'
 * '<S101>' : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Wall Deviation'
 * '<S102>' : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S103>' : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Subsystem/MATLAB Function'
 * '<S104>' : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Subsystem/Slider Gain'
 * '<S105>' : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Wall Deviation/MATLAB Function'
 * '<S106>' : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Wall Deviation/Slider Gain'
 * '<S107>' : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Wall Deviation/Slider Gain2'
 * '<S108>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference'
 * '<S109>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Next Ref'
 * '<S110>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Slider Gain'
 * '<S111>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem'
 * '<S112>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1'
 * '<S113>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Thresy'
 * '<S114>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Thresz'
 * '<S115>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation'
 * '<S116>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1'
 * '<S117>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/get ref from vector1'
 * '<S118>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/get ref from vector2'
 * '<S119>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem/MATLAB Function'
 * '<S120>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/MATLAB Function'
 * '<S121>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain'
 * '<S122>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain1'
 * '<S123>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain2'
 * '<S124>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain3'
 * '<S125>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain4'
 * '<S126>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation/MATLAB Function'
 * '<S127>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation/Slider Gain'
 * '<S128>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation/Slider Gain2'
 * '<S129>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_x'
 * '<S130>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_y'
 * '<S131>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_yaw'
 * '<S132>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_z'
 * '<S133>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling '
 * '<S134>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame'
 * '<S135>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S136>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation'
 * '<S137>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation/MATLAB Function'
 * '<S138>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation/Slider Gain'
 * '<S139>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation/Slider Gain2'
 * '<S140>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S141>' : 'controller_template/FreeFlight Pos Ctrl/rotate to world frame/Embedded MATLAB Function'
 * '<S142>' : 'controller_template/convert2cmd/Manual Switch'
 * '<S143>' : 'controller_template/convert2cmd/Slider Gain'
 * '<S144>' : 'controller_template/convert2cmd/Slider Gain1'
 * '<S145>' : 'controller_template/convert2cmd/added_mass'
 * '<S146>' : 'controller_template/convert2cmd/added_mass1'
 * '<S147>' : 'controller_template/convert2cmd/added_mass2'
 * '<S148>' : 'controller_template/delay/delay bias'
 * '<S149>' : 'controller_template/pos controller/MAIN CONTROL LOOP1'
 * '<S150>' : 'controller_template/pos controller/decoupling and rotation'
 * '<S151>' : 'controller_template/pos controller/get ref from vector'
 * '<S152>' : 'controller_template/pos controller/rotate to world frame'
 * '<S153>' : 'controller_template/pos controller/view & log signals'
 * '<S154>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/demux'
 * '<S155>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S156>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias'
 * '<S157>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S158>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias'
 * '<S159>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S160>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S161>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S162>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias'
 * '<S163>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  /runFastGradient'
 * '<S164>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/Unit Delay External IC1'
 * '<S165>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/discrete kalman filter'
 * '<S166>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG/runFastGradient'
 * '<S167>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/Unit Delay External IC1'
 * '<S168>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/discrete kalman filter'
 * '<S169>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG/runFastGradient'
 * '<S170>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S171>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S172>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG/runFastGradient'
 * '<S173>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/Unit Delay External IC1'
 * '<S174>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/discrete kalman filter'
 * '<S175>' : 'controller_template/pos controller/decoupling and rotation/decoupling '
 * '<S176>' : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame'
 * '<S177>' : 'controller_template/pos controller/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S178>' : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S179>' : 'controller_template/pos controller/rotate to world frame/Embedded MATLAB Function'
 */
#endif                                 /* RTW_HEADER_controller_template_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
