/*
 * File: controller_template.h
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.465
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Aug  6 2011)
 * C/C++ source code generated on : Fri May 17 16:26:04 2013
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

/* Block signals for system '<S20>/discrete kalman filter' */
typedef struct {
  real_T state_est[3];                 /* '<S20>/discrete kalman filter' */
  real_T P_est[9];                     /* '<S20>/discrete kalman filter' */
} rtB_discretekalmanfilter_contro;

/* Block states (auto storage) for system '<S20>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S20>/discrete kalman filter' */
  uint8_T is_active_c5_Hquad_control_LIB_;/* '<S20>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S20>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S20>/discrete kalman filter' */
} rtDW_discretekalmanfilter_contr;

/* Block signals for system '<S69>/runFastGradient' */
typedef struct {
  real_T u_opt;                        /* '<S69>/runFastGradient' */
  real_T J_star;                       /* '<S69>/runFastGradient' */
  real_T u_buff_out[3];                /* '<S69>/runFastGradient' */
  real_T V_init_out[30];               /* '<S69>/runFastGradient' */
} rtB_runFastGradient_controller_;

/* Block states (auto storage) for system '<S69>/runFastGradient' */
typedef struct {
  int32_T sfEvent;                     /* '<S69>/runFastGradient' */
  uint8_T is_active_c6_Hquad_control_LIB_;/* '<S69>/runFastGradient' */
  boolean_T isStable;                  /* '<S69>/runFastGradient' */
  boolean_T doneDoubleBufferReInit;    /* '<S69>/runFastGradient' */
} rtDW_runFastGradient_controller;

/* Block signals for system '<S70>/discrete kalman filter' */
typedef struct {
  real_T state_est[4];                 /* '<S70>/discrete kalman filter' */
  real_T P_est[16];                    /* '<S70>/discrete kalman filter' */
} rtB_discretekalmanfilter_cont_h;

/* Block states (auto storage) for system '<S70>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S70>/discrete kalman filter' */
  uint8_T is_active_c11_Hquad_control_LIB;/* '<S70>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S70>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S70>/discrete kalman filter' */
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
  real_T thrust_cmd;                   /* '<Root>/Switch1' */
  real_T yaw_rate_cmd;                 /* '<Root>/Switch1' */
  real_T pitch_bias;                   /* '<Root>/Switch1' */
  real_T roll_bias;                    /* '<Root>/Switch1' */
  real_T thrust_bias;                  /* '<Root>/Switch1' */
  real_T yaw_rate_bias;                /* '<Root>/Switch1' */
  real_T raddeg2[3];                   /* '<S67>/rad -> deg2' */
  real_T raddeg1[3];                   /* '<S67>/rad -> deg1' */
  real_T raddeg3[3];                   /* '<S67>/rad -> deg3' */
  real_T raddeg[4];                    /* '<S67>/rad -> deg' */
  real_T roll_rot;                     /* '<S66>/Embedded MATLAB Function' */
  real_T pitch_rot;                    /* '<S66>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S66>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S66>/Embedded MATLAB Function' */
  real_T bias_W[4];                    /* '<S64>/bias_W' */
  real_T cmd_W[4];                     /* '<S64>/cmd_W' */
  real_T pitch_rot_k;                  /* '<S90>/Embedded MATLAB Function' */
  real_T roll_rot_a;                   /* '<S90>/Embedded MATLAB Function' */
  real_T pitch_bias_rot_e;             /* '<S90>/Embedded MATLAB Function' */
  real_T roll_bias_rot_b;              /* '<S90>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp;               /* '<S89>/Embedded MATLAB Function' */
  real_T roll_cmd_comp;                /* '<S89>/Embedded MATLAB Function' */
  real_T thrust_comp;                  /* '<S89>/Embedded MATLAB Function' */
  real_T thrust_cmd_e;                 /* '<S63>/Sum5' */
  real_T u_opt;                        /* '<S75>/runFastGradient' */
  real_T J_star;                       /* '<S75>/runFastGradient' */
  real_T u_buff_out[2];                /* '<S75>/runFastGradient' */
  real_T V_init_out[30];               /* '<S75>/runFastGradient' */
  real_T u_opt_l;                      /* '<S73>/runFastGradient' */
  real_T J_star_h;                     /* '<S73>/runFastGradient' */
  real_T u_buff_out_i[6];              /* '<S73>/runFastGradient' */
  real_T V_init_out_n[30];             /* '<S73>/runFastGradient' */
  real_T roll_rot_f;                   /* '<S14>/Embedded MATLAB Function' */
  real_T pitch_rot_i;                  /* '<S14>/Embedded MATLAB Function' */
  real_T pitch_bias_rot_p;             /* '<S14>/Embedded MATLAB Function' */
  real_T roll_bias_rot_n;              /* '<S14>/Embedded MATLAB Function' */
  real_T bias_W_b[4];                  /* '<S12>/bias_W' */
  real_T cmd_W_h[4];                   /* '<S12>/cmd_W' */
  real_T pitch_rot_n;                  /* '<S57>/Embedded MATLAB Function' */
  real_T roll_rot_e;                   /* '<S57>/Embedded MATLAB Function' */
  real_T pitch_bias_rot_i;             /* '<S57>/Embedded MATLAB Function' */
  real_T roll_bias_rot_d;              /* '<S57>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp_n;             /* '<S56>/Embedded MATLAB Function' */
  real_T roll_cmd_comp_j;              /* '<S56>/Embedded MATLAB Function' */
  real_T thrust_comp_k;                /* '<S56>/Embedded MATLAB Function' */
  real_T X_ref_z_b[62];                /* '<S11>/generate_X_ref_z' */
  real_T X_ref_yaw_a[62];              /* '<S11>/generate_X_ref_yaw' */
  real_T X_ref_y_j[93];                /* '<S11>/generate_X_ref_y' */
  real_T X_ref_x_l[93];                /* '<S11>/generate_X_ref_x' */
  real_T Saturation3;                  /* '<S17>/Saturation3' */
  real_T RateTransition[4];            /* '<S22>/Rate Transition' */
  real_T UnitDelay2;                   /* '<S22>/Unit Delay2' */
  real_T Gain;                         /* '<S24>/Gain' */
  real_T pitch_cmd_bq;                 /* '<S10>/Sum' */
  real_T Saturation3_e;                /* '<S18>/Saturation3' */
  real_T RateTransition_i[4];          /* '<S31>/Rate Transition' */
  real_T UnitDelay2_o;                 /* '<S31>/Unit Delay2' */
  real_T Gain_f;                       /* '<S32>/Gain' */
  real_T roll_cmd_c;                   /* '<S10>/Sum1' */
  real_T Saturation1;                  /* '<S21>/Saturation1' */
  real_T RateTransition_j[2];          /* '<S48>/Rate Transition' */
  real_T Gain_i;                       /* '<S49>/Gain' */
  real_T Sum;                          /* '<S19>/Sum' */
  real_T Gain_n;                       /* '<S39>/Gain' */
  real_T yaw_rate_cmd_g;               /* '<S10>/Sum3' */
  real_T thrust_cmd_a;                 /* '<S10>/Sum5' */
  real_T RateTransition1;              /* '<S22>/Rate Transition1' */
  real_T RateTransition1_l;            /* '<S31>/Rate Transition1' */
  real_T Gain_g;                       /* '<S19>/Gain' */
  real_T U;                            /* '<S48>/Ctrl_Xdir' */
  real_T flag_oob;                     /* '<S48>/Ctrl_Xdir' */
  real_T y;                            /* '<S44>/MATLAB Function' */
  real_T U_g;                          /* '<S38>/Ctrl_Xdir' */
  real_T flag_oob_l;                   /* '<S38>/Ctrl_Xdir' */
  real_T y_a[4];                       /* '<S36>/MATLAB Function' */
  real_T U_p;                          /* '<S31>/Ctrl_Xdir' */
  real_T flag_oob_o;                   /* '<S31>/Ctrl_Xdir' */
  real_T y_n;                          /* '<S17>/MATLAB Function' */
  real_T y_d[4];                       /* '<S29>/MATLAB Function' */
  real_T U_i;                          /* '<S22>/Ctrl_Xdir' */
  real_T flag_oob_b;                   /* '<S22>/Ctrl_Xdir' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_k;/* '<S76>/discrete kalman filter' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_n;/* '<S74>/discrete kalman filter' */
  rtB_discretekalmanfilter_cont_h sf_discretekalmanfilter_m;/* '<S72>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient_d;/* '<S71>/runFastGradient' */
  rtB_discretekalmanfilter_cont_h sf_discretekalmanfilter_b;/* '<S70>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient;/* '<S69>/runFastGradient' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter;/* '<S20>/discrete kalman filter' */
} BlockIO_controller_template;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T FixPtUnitDelay1_DSTATE[4];    /* '<S62>/FixPt Unit Delay1' */
  real_T IntegerDelay_DSTATE;          /* '<S63>/Integer Delay' */
  real_T IntegerDelay1_DSTATE;         /* '<S63>/Integer Delay1' */
  real_T IntegerDelay2_DSTATE;         /* '<S63>/Integer Delay2' */
  real_T IntegerDelay3_DSTATE;         /* '<S63>/Integer Delay3' */
  real_T UnitDelay1_DSTATE[16];        /* '<S70>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i[3];  /* '<S78>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE[3];          /* '<S69>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c[30];      /* '<S69>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_b[16];      /* '<S72>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_g[3];  /* '<S81>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_j[3];        /* '<S71>/Unit Delay' */
  real_T UnitDelay1_DSTATE_l[30];      /* '<S71>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_j[9];       /* '<S76>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_d[2];  /* '<S87>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_l[2];        /* '<S75>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g[30];      /* '<S75>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_lx[9];      /* '<S74>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_e[2];  /* '<S84>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_jz[6];       /* '<S73>/Unit Delay' */
  real_T UnitDelay1_DSTATE_js[30];     /* '<S73>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_k;     /* '<S51>/FixPt Unit Delay1' */
  real_T IntegerDelay3_DSTATE_k;       /* '<S10>/Integer Delay3' */
  real_T UnitDelay2_DSTATE;            /* '<S22>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_d;          /* '<S24>/Unit Delay2' */
  real_T UnitDelay_DSTATE_jv;          /* '<S24>/Unit Delay' */
  real_T UnitDelay2_DSTATE_l;          /* '<S31>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_k;          /* '<S32>/Unit Delay2' */
  real_T UnitDelay_DSTATE_f;           /* '<S32>/Unit Delay' */
  real_T UnitDelay2_DSTATE_b;          /* '<S49>/Unit Delay2' */
  real_T UnitDelay_DSTATE_fw;          /* '<S49>/Unit Delay' */
  real_T UnitDelay1_DSTATE_bg[9];      /* '<S20>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i1[2]; /* '<S46>/FixPt Unit Delay1' */
  real_T UnitDelay2_DSTATE_g;          /* '<S38>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_ga;         /* '<S39>/Unit Delay2' */
  real_T UnitDelay_DSTATE_p;           /* '<S39>/Unit Delay' */
  real_T UnitDelay1_DSTATE_a;          /* '<S24>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_ji;         /* '<S32>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_c3;         /* '<S39>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_m;          /* '<S49>/Unit Delay1' */
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
  } ToFile_PWORK;                      /* '<S67>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<S67>/To File1' */

  struct {
    void *LoggedData;
  } pitchcmd_PWORK;                    /* '<S67>/pitch cmd' */

  struct {
    void *LoggedData;
  } rollcmd_PWORK;                     /* '<S67>/roll cmd' */

  struct {
    void *LoggedData;
  } thrustcmd_PWORK;                   /* '<S67>/thrust cmd' */

  struct {
    void *LoggedData;
  } x_ref_PWORK;                       /* '<S67>/x_ref' */

  struct {
    void *LoggedData;
  } y_ref_PWORK;                       /* '<S67>/y_ref' */

  struct {
    void *LoggedData;
  } yawcmd_PWORK;                      /* '<S67>/yaw cmd' */

  struct {
    void *LoggedData;
  } yaw_ref_PWORK;                     /* '<S67>/yaw_ref' */

  struct {
    void *LoggedData;
  } z_ref_PWORK;                       /* '<S67>/z_ref' */

  struct {
    void *FilePtr;
  } ToFile_PWORK_p;                    /* '<S15>/To File' */

  struct {
    void *LoggedData;
  } pitch_PWORK;                       /* '<S15>/pitch' */

  struct {
    void *LoggedData;
  } roll_PWORK;                        /* '<S15>/roll' */

  struct {
    void *LoggedData;
  } thrust_PWORK;                      /* '<S15>/thrust' */

  struct {
    void *LoggedData;
  } xaxis_PWORK;                       /* '<S15>/x axis' */

  struct {
    void *LoggedData;
  } yaxis_PWORK;                       /* '<S15>/y axis' */

  struct {
    void *LoggedData;
  } yaw_PWORK;                         /* '<S15>/yaw' */

  struct {
    void *LoggedData;
  } zaxis_PWORK;                       /* '<S15>/z axis' */

  int32_T sfEvent;                     /* '<S66>/Embedded MATLAB Function' */
  int32_T sfEvent_b;                   /* '<S90>/Embedded MATLAB Function' */
  int32_T sfEvent_f;                   /* '<S89>/Embedded MATLAB Function' */
  int32_T sfEvent_k;                   /* '<S75>/runFastGradient' */
  int32_T sfEvent_n;                   /* '<S73>/runFastGradient' */
  int32_T sfEvent_bq;                  /* '<S14>/Embedded MATLAB Function' */
  int32_T sfEvent_j;                   /* '<S57>/Embedded MATLAB Function' */
  int32_T sfEvent_c;                   /* '<S56>/Embedded MATLAB Function' */
  int32_T sfEvent_d;                   /* '<S11>/generate_X_ref_z' */
  int32_T sfEvent_h;                   /* '<S11>/generate_X_ref_yaw' */
  int32_T sfEvent_dw;                  /* '<S11>/generate_X_ref_y' */
  int32_T sfEvent_m;                   /* '<S11>/generate_X_ref_x' */
  int32_T sfEvent_k0;                  /* '<S48>/Ctrl_Xdir' */
  int32_T sfEvent_l;                   /* '<S44>/MATLAB Function' */
  int32_T sfEvent_jv;                  /* '<S38>/Ctrl_Xdir' */
  int32_T sfEvent_i;                   /* '<S36>/MATLAB Function' */
  int32_T sfEvent_cd;                  /* '<S31>/Ctrl_Xdir' */
  int32_T sfEvent_fk;                  /* '<S17>/MATLAB Function' */
  int32_T sfEvent_cm;                  /* '<S29>/MATLAB Function' */
  int32_T sfEvent_kl;                  /* '<S22>/Ctrl_Xdir' */
  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<S67>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<S67>/To File1' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK_g;                    /* '<S15>/To File' */

  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S62>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_l;    /* '<S78>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_b;    /* '<S81>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S87>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S84>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_e;    /* '<S51>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_g;    /* '<S46>/FixPt Unit Delay2' */
  int8_T FreeFlightPosCtrl_SubsysRanBC;/* '<Root>/FreeFlight Pos Ctrl' */
  int8_T poscontroller_SubsysRanBC;    /* '<Root>/pos controller' */
  uint8_T is_active_c26_Hquad_control_LIB;/* '<S66>/Embedded MATLAB Function' */
  uint8_T is_active_c4_Hquad_control_LIB_;/* '<S90>/Embedded MATLAB Function' */
  uint8_T is_active_c1_Hquad_control_LIB_;/* '<S89>/Embedded MATLAB Function' */
  uint8_T is_active_c8_Hquad_control_LIB_;/* '<S75>/runFastGradient' */
  uint8_T is_active_c9_Hquad_control_LIB_;/* '<S73>/runFastGradient' */
  uint8_T is_active_c26_Hquad_control_L_f;/* '<S14>/Embedded MATLAB Function' */
  uint8_T is_active_c4_Hquad_control_LI_d;/* '<S57>/Embedded MATLAB Function' */
  uint8_T is_active_c1_Hquad_control_LI_l;/* '<S56>/Embedded MATLAB Function' */
  uint8_T is_active_c24_Hquad_control_LIB;/* '<S11>/generate_X_ref_z' */
  uint8_T is_active_c23_Hquad_control_LIB;/* '<S11>/generate_X_ref_yaw' */
  uint8_T is_active_c22_Hquad_control_LIB;/* '<S11>/generate_X_ref_y' */
  uint8_T is_active_c2_Hquad_control_LIB_;/* '<S11>/generate_X_ref_x' */
  uint8_T is_active_c3_controller_templat;/* '<S48>/Ctrl_Xdir' */
  uint8_T is_active_c6_controller_templat;/* '<S44>/MATLAB Function' */
  uint8_T is_active_c4_controller_templat;/* '<S38>/Ctrl_Xdir' */
  uint8_T is_active_c5_controller_templat;/* '<S36>/MATLAB Function' */
  uint8_T is_active_c2_controller_templat;/* '<S31>/Ctrl_Xdir' */
  uint8_T is_active_c8_controller_templat;/* '<S17>/MATLAB Function' */
  uint8_T is_active_c7_controller_templat;/* '<S29>/MATLAB Function' */
  uint8_T is_active_c1_controller_templat;/* '<S22>/Ctrl_Xdir' */
  boolean_T isStable;                  /* '<S66>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S66>/Embedded MATLAB Function' */
  boolean_T isStable_n;                /* '<S90>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_m;  /* '<S90>/Embedded MATLAB Function' */
  boolean_T isStable_m;                /* '<S89>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S89>/Embedded MATLAB Function' */
  boolean_T isStable_i;                /* '<S75>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_h;  /* '<S75>/runFastGradient' */
  boolean_T isStable_h;                /* '<S73>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_o;  /* '<S73>/runFastGradient' */
  boolean_T isStable_k;                /* '<S14>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_og; /* '<S14>/Embedded MATLAB Function' */
  boolean_T isStable_o;                /* '<S57>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S57>/Embedded MATLAB Function' */
  boolean_T isStable_mf;               /* '<S56>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_a;  /* '<S56>/Embedded MATLAB Function' */
  boolean_T isStable_f;                /* '<S11>/generate_X_ref_z' */
  boolean_T doneDoubleBufferReInit_l;  /* '<S11>/generate_X_ref_z' */
  boolean_T isStable_mv;               /* '<S11>/generate_X_ref_yaw' */
  boolean_T doneDoubleBufferReInit_ov; /* '<S11>/generate_X_ref_yaw' */
  boolean_T isStable_b;                /* '<S11>/generate_X_ref_y' */
  boolean_T doneDoubleBufferReInit_n;  /* '<S11>/generate_X_ref_y' */
  boolean_T isStable_bj;               /* '<S11>/generate_X_ref_x' */
  boolean_T doneDoubleBufferReInit_f;  /* '<S11>/generate_X_ref_x' */
  boolean_T isStable_c;                /* '<S48>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_ha; /* '<S48>/Ctrl_Xdir' */
  boolean_T isStable_oc;               /* '<S44>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_me; /* '<S44>/MATLAB Function' */
  boolean_T isStable_hg;               /* '<S38>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_p;  /* '<S38>/Ctrl_Xdir' */
  boolean_T isStable_nx;               /* '<S36>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_b;  /* '<S36>/MATLAB Function' */
  boolean_T isStable_ke;               /* '<S31>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S31>/Ctrl_Xdir' */
  boolean_T isStable_a;                /* '<S17>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_h2; /* '<S17>/MATLAB Function' */
  boolean_T isStable_fw;               /* '<S29>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_j;  /* '<S29>/MATLAB Function' */
  boolean_T isStable_fv;               /* '<S22>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_g;  /* '<S22>/Ctrl_Xdir' */
  boolean_T FreeFlightPosCtrl_MODE;    /* '<Root>/FreeFlight Pos Ctrl' */
  boolean_T poscontroller_MODE;        /* '<Root>/pos controller' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_k;/* '<S76>/discrete kalman filter' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_n;/* '<S74>/discrete kalman filter' */
  rtDW_discretekalmanfilter_con_c sf_discretekalmanfilter_m;/* '<S72>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient_d;/* '<S71>/runFastGradient' */
  rtDW_discretekalmanfilter_con_c sf_discretekalmanfilter_b;/* '<S70>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient;/* '<S69>/runFastGradient' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter;/* '<S20>/discrete kalman filter' */
} D_Work_controller_template;

/* Parameters (auto storage) */
struct Parameters_controller_template_ {
  real_T Constant3_Value[8];           /* Expression: Bdd_pitch
                                        * Referenced by: '<S29>/Constant3'
                                        */
  real_T Constant1_Value[8];           /* Expression: Bff_pitch
                                        * Referenced by: '<S29>/Constant1'
                                        */
  real_T Constant2_Value[16];          /* Expression: Add_pitch
                                        * Referenced by: '<S29>/Constant2'
                                        */
  real_T Constant_Value[16];           /* Expression: Aff_pitch
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T IntegerDelay3_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S10>/Integer Delay3'
                                         */
  real_T gravity_Value;                /* Expression: g
                                        * Referenced by: '<S10>/gravity'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.2094
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.2094
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 2
                                        * Referenced by: '<S17>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -2
                                        * Referenced by: '<S17>/Saturation1'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * Referenced by: '<S26>/Slider Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T SliderGain_Gain_e;            /* Expression: gain
                                        * Referenced by: '<S25>/Slider Gain'
                                        */
  real_T Constant1_Value_g;            /* Expression: 1
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T SliderGain_Gain_f;            /* Expression: gain
                                        * Referenced by: '<S27>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S17>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S17>/Saturation3'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S17>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S17>/Saturation2'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S22>/Unit Delay2'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 0.2094
                                        * Referenced by: '<S29>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -0.2094
                                        * Referenced by: '<S29>/Saturation'
                                        */
  real_T Saturation1_UpperSat_n;       /* Expression: 2
                                        * Referenced by: '<S29>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_c;       /* Expression: -2
                                        * Referenced by: '<S29>/Saturation1'
                                        */
  real_T Saturation3_UpperSat_i;       /* Expression: 0
                                        * Referenced by: '<S29>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_k;       /* Expression: -1
                                        * Referenced by: '<S29>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_g;       /* Expression: 1
                                        * Referenced by: '<S29>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_o;       /* Expression: -1
                                        * Referenced by: '<S29>/Saturation2'
                                        */
  real_T Constant_Value_o[12272];      /* Expression: Hn_Xdir
                                        * Referenced by: '<S22>/Constant'
                                        */
  real_T Constant1_Value_d[3068];      /* Expression: Kn_Xdir
                                        * Referenced by: '<S22>/Constant1'
                                        */
  real_T Constant2_Value_i[1384];      /* Expression: Fi_Xdir
                                        * Referenced by: '<S22>/Constant2'
                                        */
  real_T Constant3_Value_o[346];       /* Expression: Gi_Xdir
                                        * Referenced by: '<S22>/Constant3'
                                        */
  real_T Constant4_Value[346];         /* Expression: Nc_Xdir
                                        * Referenced by: '<S22>/Constant4'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 0.2094
                                        * Referenced by: '<S17>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -0.2094
                                        * Referenced by: '<S17>/Saturation4'
                                        */
  real_T UnitDelay2_X0_m;              /* Expression: 0
                                        * Referenced by: '<S24>/Unit Delay2'
                                        */
  real_T UnitDelay_X0;                 /* Expression: 0
                                        * Referenced by: '<S24>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: .33333
                                        * Referenced by: '<S24>/Gain'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 0.2094
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -0.2094
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Saturation1_UpperSat_o;       /* Expression: 2
                                        * Referenced by: '<S18>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_cl;      /* Expression: -2
                                        * Referenced by: '<S18>/Saturation1'
                                        */
  real_T SliderGain_Gain_g;            /* Expression: gain
                                        * Referenced by: '<S34>/Slider Gain'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T SliderGain_Gain_b;            /* Expression: gain
                                        * Referenced by: '<S33>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_n;       /* Expression: 1
                                        * Referenced by: '<S18>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_c;       /* Expression: -1
                                        * Referenced by: '<S18>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_b;       /* Expression: 1
                                        * Referenced by: '<S18>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_h;       /* Expression: -1
                                        * Referenced by: '<S18>/Saturation2'
                                        */
  real_T Constant_Value_c[16];         /* Expression: Aff_roll
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Constant1_Value_gy[8];        /* Expression: Bff_roll
                                        * Referenced by: '<S36>/Constant1'
                                        */
  real_T UnitDelay2_X0_d;              /* Expression: 0
                                        * Referenced by: '<S31>/Unit Delay2'
                                        */
  real_T Constant_Value_l[4532];       /* Expression: Hn_Ydir
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Constant1_Value_j[1133];      /* Expression: Kn_Ydir
                                        * Referenced by: '<S31>/Constant1'
                                        */
  real_T Constant2_Value_j[536];       /* Expression: Fi_Ydir
                                        * Referenced by: '<S31>/Constant2'
                                        */
  real_T Constant3_Value_ok[134];      /* Expression: Gi_Ydir
                                        * Referenced by: '<S31>/Constant3'
                                        */
  real_T Constant4_Value_g[134];       /* Expression: Nc_Ydir
                                        * Referenced by: '<S31>/Constant4'
                                        */
  real_T Saturation4_UpperSat_i;       /* Expression: 0.2094
                                        * Referenced by: '<S18>/Saturation4'
                                        */
  real_T Saturation4_LowerSat_h;       /* Expression: -0.2094
                                        * Referenced by: '<S18>/Saturation4'
                                        */
  real_T UnitDelay2_X0_n;              /* Expression: 0
                                        * Referenced by: '<S32>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_f;               /* Expression: 0
                                        * Referenced by: '<S32>/Unit Delay'
                                        */
  real_T Gain_Gain_f;                  /* Expression: .33333
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Saturation1_UpperSat_d;       /* Expression: 1
                                        * Referenced by: '<S21>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -1
                                        * Referenced by: '<S21>/Saturation1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1
                                        * Referenced by: '<S21>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -1
                                        * Referenced by: '<S21>/Saturation'
                                        */
  real_T Constant_Value_b[224];        /* Expression: Hn_Zdir
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T Constant1_Value_l[112];       /* Expression: Kn_Zdir
                                        * Referenced by: '<S48>/Constant1'
                                        */
  real_T Constant2_Value_g[54];        /* Expression: Fi_Zdir
                                        * Referenced by: '<S48>/Constant2'
                                        */
  real_T Constant3_Value_m[27];        /* Expression: Gi_Zdir
                                        * Referenced by: '<S48>/Constant3'
                                        */
  real_T Constant4_Value_a[27];        /* Expression: Nc_Zdir
                                        * Referenced by: '<S48>/Constant4'
                                        */
  real_T Saturation2_UpperSat_k;       /* Expression: 1
                                        * Referenced by: '<S21>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_j;       /* Expression: -1
                                        * Referenced by: '<S21>/Saturation2'
                                        */
  real_T UnitDelay2_X0_o;              /* Expression: 0
                                        * Referenced by: '<S49>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_i;               /* Expression: 0
                                        * Referenced by: '<S49>/Unit Delay'
                                        */
  real_T Gain_Gain_p;                  /* Expression: .33333
                                        * Referenced by: '<S49>/Gain'
                                        */
  real_T A_Value[9];                   /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S20>/A'
                                        */
  real_T B_Value[3];                   /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S20>/B'
                                        */
  real_T C_Value[6];                   /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S20>/C'
                                        */
  real_T D_Value[2];                   /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S20>/D'
                                        */
  real_T Q_Value[9];                   /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S20>/Q'
                                        */
  real_T R_Value[4];                   /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S20>/R'
                                        */
  real_T UnitDelay1_X0[9];             /* Expression: kalm_mpc_yaw.P
                                        * Referenced by: '<S20>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0;           /* Expression: 0.0
                                        * Referenced by: '<S46>/FixPt Unit Delay1'
                                        */
  real_T SliderGain_Gain_a;            /* Expression: gain
                                        * Referenced by: '<S41>/Slider Gain'
                                        */
  real_T Constant_Value_fv;            /* Expression: 1
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T SliderGain_Gain_j;            /* Expression: gain
                                        * Referenced by: '<S40>/Slider Gain'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: pi
                                        * Referenced by: '<S19>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -pi
                                        * Referenced by: '<S19>/Saturation'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S44>/Constant1'
                                        */
  real_T UnitDelay2_X0_ng;             /* Expression: 0
                                        * Referenced by: '<S38>/Unit Delay2'
                                        */
  real_T Constant_Value_a[2];          /* Expression: Hn_Yaw
                                        * Referenced by: '<S38>/Constant'
                                        */
  real_T Constant1_Value_gs[2];        /* Expression: Kn_Yaw
                                        * Referenced by: '<S38>/Constant1'
                                        */
  real_T Constant2_Value_jq;           /* Expression: Fi_Yaw
                                        * Referenced by: '<S38>/Constant2'
                                        */
  real_T Constant3_Value_b;            /* Expression: Gi_Yaw
                                        * Referenced by: '<S38>/Constant3'
                                        */
  real_T Constant4_Value_gb;           /* Expression: Nc_Yaw
                                        * Referenced by: '<S38>/Constant4'
                                        */
  real_T SliderGain_Gain_a3;           /* Expression: gain
                                        * Referenced by: '<S43>/Slider Gain'
                                        */
  real_T Saturation1_UpperSat_g;       /* Expression: pi
                                        * Referenced by: '<S19>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_b;       /* Expression: -pi
                                        * Referenced by: '<S19>/Saturation1'
                                        */
  real_T UnitDelay2_X0_i;              /* Expression: 0
                                        * Referenced by: '<S39>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_c;               /* Expression: 0
                                        * Referenced by: '<S39>/Unit Delay'
                                        */
  real_T Gain_Gain_p0;                 /* Expression: .33333
                                        * Referenced by: '<S39>/Gain'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T UnitDelay1_X0_i;              /* Expression: 0
                                        * Referenced by: '<S24>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_d;              /* Expression: 0
                                        * Referenced by: '<S32>/Unit Delay1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 57
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T UnitDelay1_X0_j;              /* Expression: 0
                                        * Referenced by: '<S39>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_f;              /* Expression: 0
                                        * Referenced by: '<S49>/Unit Delay1'
                                        */
  real_T g_Value;                      /* Expression: g
                                        * Referenced by: '<S56>/g'
                                        */
  real_T Constant_Value_br;            /* Expression: 1
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: 1
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T InitialCondition_Value;       /* Expression: vinit
                                        * Referenced by: '<S51>/Initial Condition'
                                        */
  real_T FixPtUnitDelay1_X0_c;         /* Expression: vinit
                                        * Referenced by: '<S51>/FixPt Unit Delay1'
                                        */
  real_T total_samples_Value;          /* Expression: traj_FG.total_samples
                                        * Referenced by: '<S11>/total_samples'
                                        */
  real_T X_ref_x_Value[2796];          /* Expression: traj_FG.X_ref_x
                                        * Referenced by: '<S11>/X_ref_x'
                                        */
  real_T X_ref_y_Value[2796];          /* Expression: traj_FG.X_ref_y
                                        * Referenced by: '<S11>/X_ref_y'
                                        */
  real_T X_ref_yaw_Value[1864];        /* Expression: traj_FG.X_ref_yaw
                                        * Referenced by: '<S11>/X_ref_yaw'
                                        */
  real_T X_ref_z_Value[1864];          /* Expression: traj_FG.X_ref_z
                                        * Referenced by: '<S11>/X_ref_z'
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
                                        * Referenced by: '<S63>/Integer Delay'
                                        */
  real_T IntegerDelay1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S63>/Integer Delay1'
                                         */
  real_T IntegerDelay2_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S63>/Integer Delay2'
                                         */
  real_T IntegerDelay3_InitialConditio_c;/* Expression: 0.0
                                          * Referenced by: '<S63>/Integer Delay3'
                                          */
  real_T gravity_Value_j;              /* Expression: g
                                        * Referenced by: '<S63>/gravity'
                                        */
  real_T TT_PP_Value[900];             /* Expression: FG_ctrl_x.TT_PP
                                        * Referenced by: '<S69>/TT_PP'
                                        */
  real_T LL_PP_Value[90];              /* Expression: FG_ctrl_x.LL_PP
                                        * Referenced by: '<S69>/LL_PP'
                                        */
  real_T LL_ref_PP_Value[2790];        /* Expression: FG_ctrl_x.LL_ref_PP
                                        * Referenced by: '<S69>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value[900];       /* Expression: FG_ctrl_x.LL_U_ref_PP
                                        * Referenced by: '<S69>/LL_U_ref_PP'
                                        */
  real_T MM_Value[9];                  /* Expression: FG_ctrl_x.MM
                                        * Referenced by: '<S69>/MM'
                                        */
  real_T PP_Value[900];                /* Expression: FG_ctrl_x.PP
                                        * Referenced by: '<S69>/PP'
                                        */
  real_T AA_delay_Value[9];            /* Expression: FG_ctrl_x.AA_delay
                                        * Referenced by: '<S69>/AA_delay'
                                        */
  real_T BB_delay_Value[9];            /* Expression: FG_ctrl_x.BB_delay
                                        * Referenced by: '<S69>/BB_delay'
                                        */
  real_T A_Value_h[16];                /* Expression: kalm_mpc_x.A
                                        * Referenced by: '<S70>/A'
                                        */
  real_T B_Value_i[4];                 /* Expression: kalm_mpc_x.B
                                        * Referenced by: '<S70>/B'
                                        */
  real_T C_Value_c[12];                /* Expression: kalm_mpc_x.C
                                        * Referenced by: '<S70>/C'
                                        */
  real_T D_Value_l[3];                 /* Expression: kalm_mpc_x.D
                                        * Referenced by: '<S70>/D'
                                        */
  real_T Q_Value_a[16];                /* Expression: kalm_mpc_x.Q
                                        * Referenced by: '<S70>/Q'
                                        */
  real_T R_Value_c[9];                 /* Expression: kalm_mpc_x.R
                                        * Referenced by: '<S70>/R'
                                        */
  real_T UnitDelay1_X0_c[16];          /* Expression: kalm_mpc_x.P
                                        * Referenced by: '<S70>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_f;         /* Expression: 0.0
                                        * Referenced by: '<S78>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value[30];              /* Expression: FG_ctrl_x.V_max
                                        * Referenced by: '<S69>/V_max'
                                        */
  real_T i_min_Value;                  /* Expression: FG_ctrl_x.i_min
                                        * Referenced by: '<S69>/i_min'
                                        */
  real_T betas_Value[7];               /* Expression: FG_ctrl_x.betas
                                        * Referenced by: '<S69>/betas'
                                        */
  real_T L_Value;                      /* Expression: FG_ctrl_x.L
                                        * Referenced by: '<S69>/L'
                                        */
  real_T UnitDelay_X0_fc[3];           /* Expression: zeros(FG_ctrl_x.delay_steps,1)
                                        * Referenced by: '<S69>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_k[30];          /* Expression: zeros(size(FG_ctrl_x.V_max,1),1)
                                        * Referenced by: '<S69>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S70>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S70>/Saturation'
                                        */
  real_T TT_PP_Value_m[900];           /* Expression: FG_ctrl_y.TT_PP
                                        * Referenced by: '<S71>/TT_PP'
                                        */
  real_T LL_PP_Value_e[90];            /* Expression: FG_ctrl_y.LL_PP
                                        * Referenced by: '<S71>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_l[2790];      /* Expression: FG_ctrl_y.LL_ref_PP
                                        * Referenced by: '<S71>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_m[900];     /* Expression: FG_ctrl_y.LL_U_ref_PP
                                        * Referenced by: '<S71>/LL_U_ref_PP'
                                        */
  real_T MM_Value_c[9];                /* Expression: FG_ctrl_y.MM
                                        * Referenced by: '<S71>/MM'
                                        */
  real_T PP_Value_m[900];              /* Expression: FG_ctrl_y.PP
                                        * Referenced by: '<S71>/PP'
                                        */
  real_T AA_delay_Value_h[9];          /* Expression: FG_ctrl_y.AA_delay
                                        * Referenced by: '<S71>/AA_delay'
                                        */
  real_T BB_delay_Value_o[9];          /* Expression: FG_ctrl_y.BB_delay
                                        * Referenced by: '<S71>/BB_delay'
                                        */
  real_T A_Value_n[16];                /* Expression: kalm_mpc_y.A
                                        * Referenced by: '<S72>/A'
                                        */
  real_T B_Value_h[4];                 /* Expression: kalm_mpc_y.B
                                        * Referenced by: '<S72>/B'
                                        */
  real_T C_Value_p[12];                /* Expression: kalm_mpc_y.C
                                        * Referenced by: '<S72>/C'
                                        */
  real_T D_Value_m[3];                 /* Expression: kalm_mpc_y.D
                                        * Referenced by: '<S72>/D'
                                        */
  real_T Q_Value_h[16];                /* Expression: kalm_mpc_y.Q
                                        * Referenced by: '<S72>/Q'
                                        */
  real_T R_Value_l[9];                 /* Expression: kalm_mpc_y.R
                                        * Referenced by: '<S72>/R'
                                        */
  real_T UnitDelay1_X0_fk[16];         /* Expression: kalm_mpc_y.P
                                        * Referenced by: '<S72>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_n;         /* Expression: 0.0
                                        * Referenced by: '<S81>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_o[30];            /* Expression: FG_ctrl_y.V_max
                                        * Referenced by: '<S71>/V_max'
                                        */
  real_T i_min_Value_j;                /* Expression: FG_ctrl_y.i_min
                                        * Referenced by: '<S71>/i_min'
                                        */
  real_T betas_Value_l[7];             /* Expression: FG_ctrl_y.betas
                                        * Referenced by: '<S71>/betas'
                                        */
  real_T L_Value_n;                    /* Expression: FG_ctrl_y.L
                                        * Referenced by: '<S71>/L'
                                        */
  real_T UnitDelay_X0_ik[3];           /* Expression: zeros(FG_ctrl_y.delay_steps,1)
                                        * Referenced by: '<S71>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_jc[30];         /* Expression: zeros(size(FG_ctrl_y.V_max,1),1)
                                        * Referenced by: '<S71>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S72>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S72>/Saturation'
                                        */
  real_T TT_PP_Value_b[900];           /* Expression: FG_ctrl_z.TT_PP
                                        * Referenced by: '<S75>/TT_PP'
                                        */
  real_T LL_PP_Value_j[60];            /* Expression: FG_ctrl_z.LL_PP
                                        * Referenced by: '<S75>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_h[1860];      /* Expression: FG_ctrl_z.LL_ref_PP
                                        * Referenced by: '<S75>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_o[900];     /* Expression: FG_ctrl_z.LL_U_ref_PP
                                        * Referenced by: '<S75>/LL_U_ref_PP'
                                        */
  real_T MM_Value_l[4];                /* Expression: FG_ctrl_z.MM
                                        * Referenced by: '<S75>/MM'
                                        */
  real_T PP_Value_o[900];              /* Expression: FG_ctrl_z.PP
                                        * Referenced by: '<S75>/PP'
                                        */
  real_T AA_delay_Value_l[4];          /* Expression: FG_ctrl_z.AA_delay
                                        * Referenced by: '<S75>/AA_delay'
                                        */
  real_T BB_delay_Value_b[4];          /* Expression: FG_ctrl_z.BB_delay
                                        * Referenced by: '<S75>/BB_delay'
                                        */
  real_T A_Value_f[9];                 /* Expression: kalm_mpc_z.A
                                        * Referenced by: '<S76>/A'
                                        */
  real_T B_Value_n[3];                 /* Expression: kalm_mpc_z.B
                                        * Referenced by: '<S76>/B'
                                        */
  real_T C_Value_o[6];                 /* Expression: kalm_mpc_z.C
                                        * Referenced by: '<S76>/C'
                                        */
  real_T D_Value_j[2];                 /* Expression: kalm_mpc_z.D
                                        * Referenced by: '<S76>/D'
                                        */
  real_T Q_Value_j[9];                 /* Expression: kalm_mpc_z.Q
                                        * Referenced by: '<S76>/Q'
                                        */
  real_T R_Value_ca[4];                /* Expression: kalm_mpc_z.R
                                        * Referenced by: '<S76>/R'
                                        */
  real_T UnitDelay1_X0_cw[9];          /* Expression: kalm_mpc_z.P
                                        * Referenced by: '<S76>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_cl;        /* Expression: 0.0
                                        * Referenced by: '<S87>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_i[30];            /* Expression: FG_ctrl_z.V_max
                                        * Referenced by: '<S75>/V_max'
                                        */
  real_T i_min_Value_o;                /* Expression: FG_ctrl_z.i_min
                                        * Referenced by: '<S75>/i_min'
                                        */
  real_T betas_Value_g[8];             /* Expression: FG_ctrl_z.betas
                                        * Referenced by: '<S75>/betas'
                                        */
  real_T L_Value_m;                    /* Expression: FG_ctrl_z.L
                                        * Referenced by: '<S75>/L'
                                        */
  real_T UnitDelay_X0_a[2];            /* Expression: zeros(FG_ctrl_z.delay_steps,1)
                                        * Referenced by: '<S75>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_b[30];          /* Expression: zeros(size(FG_ctrl_z.V_max,1),1)
                                        * Referenced by: '<S75>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: MAX_BIAS_THRUST
                                        * Referenced by: '<S76>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -MAX_BIAS_THRUST
                                        * Referenced by: '<S76>/Saturation'
                                        */
  real_T TT_PP_Value_o[900];           /* Expression: FG_ctrl_yaw.TT_PP
                                        * Referenced by: '<S73>/TT_PP'
                                        */
  real_T LL_PP_Value_j5[60];           /* Expression: FG_ctrl_yaw.LL_PP
                                        * Referenced by: '<S73>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_e[1860];      /* Expression: FG_ctrl_yaw.LL_ref_PP
                                        * Referenced by: '<S73>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_b[900];     /* Expression: FG_ctrl_yaw.LL_U_ref_PP
                                        * Referenced by: '<S73>/LL_U_ref_PP'
                                        */
  real_T MM_Value_g[4];                /* Expression: FG_ctrl_yaw.MM
                                        * Referenced by: '<S73>/MM'
                                        */
  real_T PP_Value_p[900];              /* Expression: FG_ctrl_yaw.PP
                                        * Referenced by: '<S73>/PP'
                                        */
  real_T AA_delay_Value_o[4];          /* Expression: FG_ctrl_yaw.AA_delay
                                        * Referenced by: '<S73>/AA_delay'
                                        */
  real_T BB_delay_Value_d[12];         /* Expression: FG_ctrl_yaw.BB_delay
                                        * Referenced by: '<S73>/BB_delay'
                                        */
  real_T A_Value_k[9];                 /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S74>/A'
                                        */
  real_T B_Value_f[3];                 /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S74>/B'
                                        */
  real_T C_Value_b[6];                 /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S74>/C'
                                        */
  real_T D_Value_c[2];                 /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S74>/D'
                                        */
  real_T Q_Value_g[9];                 /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S74>/Q'
                                        */
  real_T R_Value_o[4];                 /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S74>/R'
                                        */
  real_T UnitDelay1_X0_n[9];           /* Expression: kalm_mpc_yaw.P
                                        * Referenced by: '<S74>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_e;         /* Expression: 0.0
                                        * Referenced by: '<S84>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_f[30];            /* Expression: FG_ctrl_yaw.V_max
                                        * Referenced by: '<S73>/V_max'
                                        */
  real_T i_min_Value_n;                /* Expression: FG_ctrl_yaw.i_min
                                        * Referenced by: '<S73>/i_min'
                                        */
  real_T betas_Value_j[5];             /* Expression: FG_ctrl_yaw.betas
                                        * Referenced by: '<S73>/betas'
                                        */
  real_T L_Value_g;                    /* Expression: FG_ctrl_yaw.L
                                        * Referenced by: '<S73>/L'
                                        */
  real_T UnitDelay_X0_fj[6];           /* Expression: zeros(FG_ctrl_yaw.delay_steps,1)
                                        * Referenced by: '<S73>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_o[30];          /* Expression: zeros(size(FG_ctrl_yaw.V_max,1),1)
                                        * Referenced by: '<S73>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_o3;       /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S74>/Saturation'
                                        */
  real_T Saturation_LowerSat_kn;       /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S74>/Saturation'
                                        */
  real_T g_Value_m;                    /* Expression: g
                                        * Referenced by: '<S89>/g'
                                        */
  real_T raddeg2_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S67>/rad -> deg2'
                                        */
  real_T raddeg1_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S67>/rad -> deg1'
                                        */
  real_T raddeg3_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S67>/rad -> deg3'
                                        */
  real_T raddeg_Gain;                  /* Expression: 180/pi
                                        * Referenced by: '<S67>/rad -> deg'
                                        */
  real_T pitch_offset_Value;           /* Expression: 0.00
                                        * Referenced by: '<S7>/pitch_offset'
                                        */
  real_T InitialCondition_Value_b;     /* Expression: vinit
                                        * Referenced by: '<S62>/Initial Condition'
                                        */
  real_T Constant1_Value_mr;           /* Expression: 1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T FixPtUnitDelay1_X0_h;         /* Expression: vinit
                                        * Referenced by: '<S62>/FixPt Unit Delay1'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T pitch_cmd2pitch_Gain;         /* Expression: pitch_cmd2pitch_1stOrd
                                        * Referenced by: '<S7>/pitch_cmd2pitch'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1.0
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T roll_offset_Value;            /* Expression: 0.00
                                        * Referenced by: '<S7>/roll_offset'
                                        */
  real_T roll_cmd2roll_Gain;           /* Expression: roll_cmd2roll_1stOrd
                                        * Referenced by: '<S7>/roll_cmd2roll'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S7>/Gain2'
                                        */
  real_T gravity_Value_ch;             /* Expression: g
                                        * Referenced by: '<S7>/gravity'
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
                                        * Referenced by: '<S10>/Integer Delay3'
                                        */
  uint32_T IntegerDelay_DelayLength;   /* Computed Parameter: IntegerDelay_DelayLength
                                        * Referenced by: '<S63>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength;  /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S63>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength;  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S63>/Integer Delay2'
                                        */
  uint32_T IntegerDelay3_DelayLength_o;/* Computed Parameter: IntegerDelay3_DelayLength_o
                                        * Referenced by: '<S63>/Integer Delay3'
                                        */
  uint8_T FixPtUnitDelay2_X0;          /* Computed Parameter: FixPtUnitDelay2_X0
                                        * Referenced by: '<S46>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S46>/FixPt Constant'
                                        */
  uint8_T FixPtUnitDelay2_X0_j;        /* Computed Parameter: FixPtUnitDelay2_X0_j
                                        * Referenced by: '<S51>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtConstant_Value_g;       /* Computed Parameter: FixPtConstant_Value_g
                                        * Referenced by: '<S51>/FixPt Constant'
                                        */
  uint8_T FixPtUnitDelay2_X0_d;        /* Computed Parameter: FixPtUnitDelay2_X0_d
                                        * Referenced by: '<S78>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_n;        /* Computed Parameter: FixPtUnitDelay2_X0_n
                                        * Referenced by: '<S81>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_do;       /* Computed Parameter: FixPtUnitDelay2_X0_do
                                        * Referenced by: '<S87>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_i;        /* Computed Parameter: FixPtUnitDelay2_X0_i
                                        * Referenced by: '<S84>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtConstant_Value_h;       /* Computed Parameter: FixPtConstant_Value_h
                                        * Referenced by: '<S78>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_o;       /* Computed Parameter: FixPtConstant_Value_o
                                        * Referenced by: '<S81>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_n;       /* Computed Parameter: FixPtConstant_Value_n
                                        * Referenced by: '<S84>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_p;       /* Computed Parameter: FixPtConstant_Value_p
                                        * Referenced by: '<S87>/FixPt Constant'
                                        */
  uint8_T FixPtUnitDelay2_X0_g;        /* Computed Parameter: FixPtUnitDelay2_X0_g
                                        * Referenced by: '<S62>/FixPt Unit Delay2'
                                        */
  uint8_T Constant_Value_he;           /* Expression: uint8(1)
                                        * Referenced by: '<S5>/Constant'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(1)
                                        * Referenced by: '<S5>/SwitchControl'
                                        */
  uint8_T Constant_Value_n;            /* Expression: uint8(1)
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_b;   /* Expression: uint8(1)
                                        * Referenced by: '<S4>/SwitchControl'
                                        */
  uint8_T Constant_Value_a3;           /* Expression: uint8(1)
                                        * Referenced by: '<S61>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_e;   /* Expression: uint8(0)
                                        * Referenced by: '<S61>/SwitchControl'
                                        */
  uint8_T FixPtConstant_Value_i;       /* Computed Parameter: FixPtConstant_Value_i
                                        * Referenced by: '<S62>/FixPt Constant'
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
    struct {
      uint8_T TID[2];
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
 * '<S10>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1'
 * '<S11>'  : 'controller_template/FreeFlight Pos Ctrl/create ref traj'
 * '<S12>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation'
 * '<S13>'  : 'controller_template/FreeFlight Pos Ctrl/get ref from vector'
 * '<S14>'  : 'controller_template/FreeFlight Pos Ctrl/rotate to world frame'
 * '<S15>'  : 'controller_template/FreeFlight Pos Ctrl/view & log signals'
 * '<S16>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/demux'
 * '<S17>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S18>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S19>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S20>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S21>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S22>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1'
 * '<S23>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /MATLAB Function'
 * '<S24>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Mean'
 * '<S25>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Slider Gain'
 * '<S26>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Slider Gain1'
 * '<S27>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Slider Gain2'
 * '<S28>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/Ctrl_Xdir'
 * '<S29>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/PitchPropagate'
 * '<S30>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/PitchPropagate/MATLAB Function'
 * '<S31>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1'
 * '<S32>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Mean'
 * '<S33>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Slider Gain'
 * '<S34>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Slider Gain1'
 * '<S35>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S36>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate'
 * '<S37>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate/MATLAB Function'
 * '<S38>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1'
 * '<S39>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Mean'
 * '<S40>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain'
 * '<S41>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain1'
 * '<S42>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S43>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Slider Gain'
 * '<S44>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate'
 * '<S45>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate/MATLAB Function'
 * '<S46>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S47>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S48>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1'
 * '<S49>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Mean'
 * '<S50>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S51>'  : 'controller_template/FreeFlight Pos Ctrl/create ref traj/Unit Delay Resettable'
 * '<S52>'  : 'controller_template/FreeFlight Pos Ctrl/create ref traj/generate_X_ref_x'
 * '<S53>'  : 'controller_template/FreeFlight Pos Ctrl/create ref traj/generate_X_ref_y'
 * '<S54>'  : 'controller_template/FreeFlight Pos Ctrl/create ref traj/generate_X_ref_yaw'
 * '<S55>'  : 'controller_template/FreeFlight Pos Ctrl/create ref traj/generate_X_ref_z'
 * '<S56>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling '
 * '<S57>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame'
 * '<S58>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S59>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S60>'  : 'controller_template/FreeFlight Pos Ctrl/rotate to world frame/Embedded MATLAB Function'
 * '<S61>'  : 'controller_template/convert2cmd/Manual Switch'
 * '<S62>'  : 'controller_template/delay/delay bias'
 * '<S63>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1'
 * '<S64>'  : 'controller_template/pos controller/decoupling and rotation'
 * '<S65>'  : 'controller_template/pos controller/get ref from vector'
 * '<S66>'  : 'controller_template/pos controller/rotate to world frame'
 * '<S67>'  : 'controller_template/pos controller/view & log signals'
 * '<S68>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/demux'
 * '<S69>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S70>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias'
 * '<S71>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S72>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias'
 * '<S73>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S74>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S75>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S76>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias'
 * '<S77>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  /runFastGradient'
 * '<S78>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/Unit Delay External IC1'
 * '<S79>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/discrete kalman filter'
 * '<S80>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG/runFastGradient'
 * '<S81>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/Unit Delay External IC1'
 * '<S82>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/discrete kalman filter'
 * '<S83>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG/runFastGradient'
 * '<S84>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S85>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S86>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG/runFastGradient'
 * '<S87>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/Unit Delay External IC1'
 * '<S88>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/discrete kalman filter'
 * '<S89>'  : 'controller_template/pos controller/decoupling and rotation/decoupling '
 * '<S90>'  : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame'
 * '<S91>'  : 'controller_template/pos controller/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S92>'  : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S93>'  : 'controller_template/pos controller/rotate to world frame/Embedded MATLAB Function'
 */
#endif                                 /* RTW_HEADER_controller_template_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
