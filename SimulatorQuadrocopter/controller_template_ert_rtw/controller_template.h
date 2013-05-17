/*
 * File: controller_template.h
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.492
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Aug  6 2011)
 * C/C++ source code generated on : Fri May 17 21:42:55 2013
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
#include <stddef.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
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

/* Block signals for system '<S19>/discrete kalman filter' */
typedef struct {
  real_T state_est[3];                 /* '<S19>/discrete kalman filter' */
  real_T P_est[9];                     /* '<S19>/discrete kalman filter' */
} rtB_discretekalmanfilter_contro;

/* Block states (auto storage) for system '<S19>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S19>/discrete kalman filter' */
  uint8_T is_active_c5_Hquad_control_LIB_;/* '<S19>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S19>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S19>/discrete kalman filter' */
} rtDW_discretekalmanfilter_contr;

/* Block signals for system '<S13>/Embedded MATLAB Function' */
typedef struct {
  real_T roll_rot;                     /* '<S13>/Embedded MATLAB Function' */
  real_T pitch_rot;                    /* '<S13>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S13>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S13>/Embedded MATLAB Function' */
} rtB_EmbeddedMATLABFunction_cont;

/* Block states (auto storage) for system '<S13>/Embedded MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S13>/Embedded MATLAB Function' */
  uint8_T is_active_c26_Hquad_control_LIB;/* '<S13>/Embedded MATLAB Function' */
  boolean_T isStable;                  /* '<S13>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S13>/Embedded MATLAB Function' */
} rtDW_EmbeddedMATLABFunction_con;

/* Block signals for system '<S62>/runFastGradient' */
typedef struct {
  real_T u_opt;                        /* '<S62>/runFastGradient' */
  real_T J_star;                       /* '<S62>/runFastGradient' */
  real_T u_buff_out[3];                /* '<S62>/runFastGradient' */
  real_T V_init_out[30];               /* '<S62>/runFastGradient' */
} rtB_runFastGradient_controller_;

/* Block states (auto storage) for system '<S62>/runFastGradient' */
typedef struct {
  int32_T sfEvent;                     /* '<S62>/runFastGradient' */
  uint8_T is_active_c6_Hquad_control_LIB_;/* '<S62>/runFastGradient' */
  boolean_T isStable;                  /* '<S62>/runFastGradient' */
  boolean_T doneDoubleBufferReInit;    /* '<S62>/runFastGradient' */
} rtDW_runFastGradient_controller;

/* Block signals for system '<S63>/discrete kalman filter' */
typedef struct {
  real_T state_est[4];                 /* '<S63>/discrete kalman filter' */
  real_T P_est[16];                    /* '<S63>/discrete kalman filter' */
} rtB_discretekalmanfilter_cont_h;

/* Block states (auto storage) for system '<S63>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S63>/discrete kalman filter' */
  uint8_T is_active_c11_Hquad_control_LIB;/* '<S63>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S63>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S63>/discrete kalman filter' */
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
  real_T raddeg2[3];                   /* '<S60>/rad -> deg2' */
  real_T raddeg1[3];                   /* '<S60>/rad -> deg1' */
  real_T raddeg3[3];                   /* '<S60>/rad -> deg3' */
  real_T raddeg[4];                    /* '<S60>/rad -> deg' */
  real_T bias_W[4];                    /* '<S57>/bias_W' */
  real_T cmd_W[4];                     /* '<S57>/cmd_W' */
  real_T pitch_rot;                    /* '<S83>/Embedded MATLAB Function' */
  real_T roll_rot;                     /* '<S83>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S83>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S83>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp;               /* '<S82>/Embedded MATLAB Function' */
  real_T roll_cmd_comp;                /* '<S82>/Embedded MATLAB Function' */
  real_T thrust_comp;                  /* '<S82>/Embedded MATLAB Function' */
  real_T thrust_cmd_e;                 /* '<S56>/Sum5' */
  real_T u_opt;                        /* '<S68>/runFastGradient' */
  real_T J_star;                       /* '<S68>/runFastGradient' */
  real_T u_buff_out[2];                /* '<S68>/runFastGradient' */
  real_T V_init_out[30];               /* '<S68>/runFastGradient' */
  real_T u_opt_l;                      /* '<S66>/runFastGradient' */
  real_T J_star_h;                     /* '<S66>/runFastGradient' */
  real_T u_buff_out_i[6];              /* '<S66>/runFastGradient' */
  real_T V_init_out_n[30];             /* '<S66>/runFastGradient' */
  real_T raddeg2_p[3];                 /* '<S14>/rad -> deg2' */
  real_T raddeg1_e[3];                 /* '<S14>/rad -> deg1' */
  real_T raddeg3_a[3];                 /* '<S14>/rad -> deg3' */
  real_T raddeg_j[4];                  /* '<S14>/rad -> deg' */
  real_T bias_W_b[4];                  /* '<S11>/bias_W' */
  real_T cmd_W_h[4];                   /* '<S11>/cmd_W' */
  real_T pitch_rot_n;                  /* '<S50>/Embedded MATLAB Function' */
  real_T roll_rot_e;                   /* '<S50>/Embedded MATLAB Function' */
  real_T pitch_bias_rot_i;             /* '<S50>/Embedded MATLAB Function' */
  real_T roll_bias_rot_d;              /* '<S50>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp_n;             /* '<S49>/Embedded MATLAB Function' */
  real_T roll_cmd_comp_j;              /* '<S49>/Embedded MATLAB Function' */
  real_T thrust_comp_k;                /* '<S49>/Embedded MATLAB Function' */
  real_T Saturation;                   /* '<S19>/Saturation' */
  real_T Saturation3;                  /* '<S16>/Saturation3' */
  real_T RateTransition[4];            /* '<S21>/Rate Transition' */
  real_T UnitDelay2;                   /* '<S21>/Unit Delay2' */
  real_T Gain;                         /* '<S23>/Gain' */
  real_T Saturation3_e;                /* '<S17>/Saturation3' */
  real_T RateTransition_i[4];          /* '<S30>/Rate Transition' */
  real_T UnitDelay2_o;                 /* '<S30>/Unit Delay2' */
  real_T Gain_f;                       /* '<S31>/Gain' */
  real_T Saturation1;                  /* '<S20>/Saturation1' */
  real_T RateTransition_j[2];          /* '<S46>/Rate Transition' */
  real_T Gain_i;                       /* '<S47>/Gain' */
  real_T Sum;                          /* '<S18>/Sum' */
  real_T Gain_n;                       /* '<S38>/Gain' */
  real_T thrust_cmd_a;                 /* '<S10>/Sum5' */
  real_T RateTransition1;              /* '<S21>/Rate Transition1' */
  real_T RateTransition1_l;            /* '<S30>/Rate Transition1' */
  real_T Gain_g;                       /* '<S18>/Gain' */
  real_T U;                            /* '<S46>/Ctrl_Xdir' */
  real_T flag_oob;                     /* '<S46>/Ctrl_Xdir' */
  real_T y;                            /* '<S42>/MATLAB Function' */
  real_T U_g;                          /* '<S37>/Ctrl_Xdir' */
  real_T flag_oob_l;                   /* '<S37>/Ctrl_Xdir' */
  real_T y_a[4];                       /* '<S35>/MATLAB Function' */
  real_T U_p;                          /* '<S30>/Ctrl_Xdir' */
  real_T flag_oob_o;                   /* '<S30>/Ctrl_Xdir' */
  real_T y_n;                          /* '<S16>/MATLAB Function' */
  real_T y_d[4];                       /* '<S28>/MATLAB Function' */
  real_T U_i;                          /* '<S21>/Ctrl_Xdir' */
  real_T flag_oob_b;                   /* '<S21>/Ctrl_Xdir' */
  rtB_EmbeddedMATLABFunction_cont sf_EmbeddedMATLABFunction_o;/* '<S59>/Embedded MATLAB Function' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_k;/* '<S69>/discrete kalman filter' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_n;/* '<S67>/discrete kalman filter' */
  rtB_discretekalmanfilter_cont_h sf_discretekalmanfilter_m;/* '<S65>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient_d;/* '<S64>/runFastGradient' */
  rtB_discretekalmanfilter_cont_h sf_discretekalmanfilter_b;/* '<S63>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient;/* '<S62>/runFastGradient' */
  rtB_EmbeddedMATLABFunction_cont sf_EmbeddedMATLABFunction;/* '<S13>/Embedded MATLAB Function' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter;/* '<S19>/discrete kalman filter' */
} BlockIO_controller_template;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T FixPtUnitDelay1_DSTATE[4];    /* '<S55>/FixPt Unit Delay1' */
  real_T IntegerDelay_DSTATE;          /* '<S56>/Integer Delay' */
  real_T IntegerDelay1_DSTATE;         /* '<S56>/Integer Delay1' */
  real_T IntegerDelay2_DSTATE;         /* '<S56>/Integer Delay2' */
  real_T IntegerDelay3_DSTATE;         /* '<S56>/Integer Delay3' */
  real_T UnitDelay1_DSTATE[16];        /* '<S63>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i[3];  /* '<S71>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE[3];          /* '<S62>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c[30];      /* '<S62>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_b[16];      /* '<S65>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_g[3];  /* '<S74>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_j[3];        /* '<S64>/Unit Delay' */
  real_T UnitDelay1_DSTATE_l[30];      /* '<S64>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_j[9];       /* '<S69>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_d[2];  /* '<S80>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_l[2];        /* '<S68>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g[30];      /* '<S68>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_lx[9];      /* '<S67>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_e[2];  /* '<S77>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_jz[6];       /* '<S66>/Unit Delay' */
  real_T UnitDelay1_DSTATE_js[30];     /* '<S66>/Unit Delay1' */
  real_T IntegerDelay3_DSTATE_k;       /* '<S10>/Integer Delay3' */
  real_T UnitDelay1_DSTATE_bg[9];      /* '<S19>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i1[2]; /* '<S44>/FixPt Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S21>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_d;          /* '<S23>/Unit Delay2' */
  real_T UnitDelay_DSTATE_jv;          /* '<S23>/Unit Delay' */
  real_T UnitDelay2_DSTATE_l;          /* '<S30>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_k;          /* '<S31>/Unit Delay2' */
  real_T UnitDelay_DSTATE_f;           /* '<S31>/Unit Delay' */
  real_T UnitDelay2_DSTATE_b;          /* '<S47>/Unit Delay2' */
  real_T UnitDelay_DSTATE_fw;          /* '<S47>/Unit Delay' */
  real_T UnitDelay2_DSTATE_g;          /* '<S37>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_ga;         /* '<S38>/Unit Delay2' */
  real_T UnitDelay_DSTATE_p;           /* '<S38>/Unit Delay' */
  real_T UnitDelay1_DSTATE_a;          /* '<S23>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_ji;         /* '<S31>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_c3;         /* '<S38>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_m;          /* '<S47>/Unit Delay1' */
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
  } ToFile_PWORK;                      /* '<S60>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<S60>/To File1' */

  struct {
    void *LoggedData;
  } pitchcmd_PWORK;                    /* '<S60>/pitch cmd' */

  struct {
    void *LoggedData;
  } rollcmd_PWORK;                     /* '<S60>/roll cmd' */

  struct {
    void *LoggedData;
  } thrustcmd_PWORK;                   /* '<S60>/thrust cmd' */

  struct {
    void *LoggedData;
  } x_ref_PWORK;                       /* '<S60>/x_ref' */

  struct {
    void *LoggedData;
  } y_ref_PWORK;                       /* '<S60>/y_ref' */

  struct {
    void *LoggedData;
  } yawcmd_PWORK;                      /* '<S60>/yaw cmd' */

  struct {
    void *LoggedData;
  } yaw_ref_PWORK;                     /* '<S60>/yaw_ref' */

  struct {
    void *LoggedData;
  } z_ref_PWORK;                       /* '<S60>/z_ref' */

  struct {
    void *FilePtr;
  } ToFile_PWORK_p;                    /* '<S14>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK_i;                   /* '<S14>/To File1' */

  struct {
    void *LoggedData;
  } pitchcmd_PWORK_p;                  /* '<S14>/pitch cmd' */

  struct {
    void *LoggedData;
  } rollcmd_PWORK_i;                   /* '<S14>/roll cmd' */

  struct {
    void *LoggedData;
  } thrustcmd_PWORK_g;                 /* '<S14>/thrust cmd' */

  struct {
    void *LoggedData;
  } x_ref_PWORK_a;                     /* '<S14>/x_ref' */

  struct {
    void *LoggedData;
  } y_ref_PWORK_j;                     /* '<S14>/y_ref' */

  struct {
    void *LoggedData;
  } yawcmd_PWORK_p;                    /* '<S14>/yaw cmd' */

  struct {
    void *LoggedData;
  } yaw_ref_PWORK_n;                   /* '<S14>/yaw_ref' */

  struct {
    void *LoggedData;
  } z_ref_PWORK_e;                     /* '<S14>/z_ref' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S10>/Scope' */

  int32_T sfEvent;                     /* '<S83>/Embedded MATLAB Function' */
  int32_T sfEvent_f;                   /* '<S82>/Embedded MATLAB Function' */
  int32_T sfEvent_k;                   /* '<S68>/runFastGradient' */
  int32_T sfEvent_n;                   /* '<S66>/runFastGradient' */
  int32_T sfEvent_j;                   /* '<S50>/Embedded MATLAB Function' */
  int32_T sfEvent_c;                   /* '<S49>/Embedded MATLAB Function' */
  int32_T sfEvent_k0;                  /* '<S46>/Ctrl_Xdir' */
  int32_T sfEvent_l;                   /* '<S42>/MATLAB Function' */
  int32_T sfEvent_jv;                  /* '<S37>/Ctrl_Xdir' */
  int32_T sfEvent_i;                   /* '<S35>/MATLAB Function' */
  int32_T sfEvent_cd;                  /* '<S30>/Ctrl_Xdir' */
  int32_T sfEvent_fk;                  /* '<S16>/MATLAB Function' */
  int32_T sfEvent_cm;                  /* '<S28>/MATLAB Function' */
  int32_T sfEvent_kl;                  /* '<S21>/Ctrl_Xdir' */
  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<S60>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<S60>/To File1' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK_g;                    /* '<S14>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK_p;                   /* '<S14>/To File1' */

  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S55>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_l;    /* '<S71>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_b;    /* '<S74>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S80>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S77>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_g;    /* '<S44>/FixPt Unit Delay2' */
  int8_T FreeFlightPosCtrl_SubsysRanBC;/* '<Root>/FreeFlight Pos Ctrl' */
  int8_T poscontroller_SubsysRanBC;    /* '<Root>/pos controller' */
  uint8_T is_active_c4_Hquad_control_LIB_;/* '<S83>/Embedded MATLAB Function' */
  uint8_T is_active_c1_Hquad_control_LIB_;/* '<S82>/Embedded MATLAB Function' */
  uint8_T is_active_c8_Hquad_control_LIB_;/* '<S68>/runFastGradient' */
  uint8_T is_active_c9_Hquad_control_LIB_;/* '<S66>/runFastGradient' */
  uint8_T is_active_c10_controller_templa;/* '<S50>/Embedded MATLAB Function' */
  uint8_T is_active_c9_controller_templat;/* '<S49>/Embedded MATLAB Function' */
  uint8_T is_active_c3_controller_templat;/* '<S46>/Ctrl_Xdir' */
  uint8_T is_active_c6_controller_templat;/* '<S42>/MATLAB Function' */
  uint8_T is_active_c4_controller_templat;/* '<S37>/Ctrl_Xdir' */
  uint8_T is_active_c5_controller_templat;/* '<S35>/MATLAB Function' */
  uint8_T is_active_c2_controller_templat;/* '<S30>/Ctrl_Xdir' */
  uint8_T is_active_c8_controller_templat;/* '<S16>/MATLAB Function' */
  uint8_T is_active_c7_controller_templat;/* '<S28>/MATLAB Function' */
  uint8_T is_active_c1_controller_templat;/* '<S21>/Ctrl_Xdir' */
  boolean_T isStable;                  /* '<S83>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S83>/Embedded MATLAB Function' */
  boolean_T isStable_m;                /* '<S82>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S82>/Embedded MATLAB Function' */
  boolean_T isStable_i;                /* '<S68>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_h;  /* '<S68>/runFastGradient' */
  boolean_T isStable_h;                /* '<S66>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_o;  /* '<S66>/runFastGradient' */
  boolean_T isStable_o;                /* '<S50>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S50>/Embedded MATLAB Function' */
  boolean_T isStable_mf;               /* '<S49>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_a;  /* '<S49>/Embedded MATLAB Function' */
  boolean_T isStable_c;                /* '<S46>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_ha; /* '<S46>/Ctrl_Xdir' */
  boolean_T isStable_oc;               /* '<S42>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_m;  /* '<S42>/MATLAB Function' */
  boolean_T isStable_hg;               /* '<S37>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_p;  /* '<S37>/Ctrl_Xdir' */
  boolean_T isStable_n;                /* '<S35>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_b;  /* '<S35>/MATLAB Function' */
  boolean_T isStable_k;                /* '<S30>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S30>/Ctrl_Xdir' */
  boolean_T isStable_a;                /* '<S16>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_h2; /* '<S16>/MATLAB Function' */
  boolean_T isStable_f;                /* '<S28>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_j;  /* '<S28>/MATLAB Function' */
  boolean_T isStable_fv;               /* '<S21>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_g;  /* '<S21>/Ctrl_Xdir' */
  boolean_T FreeFlightPosCtrl_MODE;    /* '<Root>/FreeFlight Pos Ctrl' */
  boolean_T poscontroller_MODE;        /* '<Root>/pos controller' */
  rtDW_EmbeddedMATLABFunction_con sf_EmbeddedMATLABFunction_o;/* '<S59>/Embedded MATLAB Function' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_k;/* '<S69>/discrete kalman filter' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_n;/* '<S67>/discrete kalman filter' */
  rtDW_discretekalmanfilter_con_c sf_discretekalmanfilter_m;/* '<S65>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient_d;/* '<S64>/runFastGradient' */
  rtDW_discretekalmanfilter_con_c sf_discretekalmanfilter_b;/* '<S63>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient;/* '<S62>/runFastGradient' */
  rtDW_EmbeddedMATLABFunction_con sf_EmbeddedMATLABFunction;/* '<S13>/Embedded MATLAB Function' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter;/* '<S19>/discrete kalman filter' */
} D_Work_controller_template;

/* Parameters (auto storage) */
struct Parameters_controller_template_ {
  real_T Constant3_Value[8];           /* Expression: Bdd_pitch
                                        * Referenced by: '<S28>/Constant3'
                                        */
  real_T Constant1_Value[8];           /* Expression: Bff_pitch
                                        * Referenced by: '<S28>/Constant1'
                                        */
  real_T Constant2_Value[16];          /* Expression: Add_pitch
                                        * Referenced by: '<S28>/Constant2'
                                        */
  real_T Constant_Value[16];           /* Expression: Aff_pitch
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T A_Value[9];                   /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S19>/A'
                                        */
  real_T B_Value[3];                   /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S19>/B'
                                        */
  real_T C_Value[6];                   /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S19>/C'
                                        */
  real_T D_Value[2];                   /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S19>/D'
                                        */
  real_T Q_Value[9];                   /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S19>/Q'
                                        */
  real_T R_Value[4];                   /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S19>/R'
                                        */
  real_T IntegerDelay3_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S10>/Integer Delay3'
                                         */
  real_T UnitDelay1_X0[9];             /* Expression: kalm_mpc_yaw.P
                                        * Referenced by: '<S19>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0;           /* Expression: 0.0
                                        * Referenced by: '<S44>/FixPt Unit Delay1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S19>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S19>/Saturation'
                                        */
  real_T gravity_Value;                /* Expression: g
                                        * Referenced by: '<S10>/gravity'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 0.2094
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: -0.2094
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 2
                                        * Referenced by: '<S16>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -2
                                        * Referenced by: '<S16>/Saturation1'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * Referenced by: '<S25>/Slider Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T SliderGain_Gain_e;            /* Expression: gain
                                        * Referenced by: '<S24>/Slider Gain'
                                        */
  real_T Constant1_Value_g;            /* Expression: 1
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T SliderGain_Gain_f;            /* Expression: gain
                                        * Referenced by: '<S26>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 0
                                        * Referenced by: '<S16>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S16>/Saturation3'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S16>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S16>/Saturation2'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S21>/Unit Delay2'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 0.2094
                                        * Referenced by: '<S28>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -0.2094
                                        * Referenced by: '<S28>/Saturation'
                                        */
  real_T Saturation1_UpperSat_n;       /* Expression: 2
                                        * Referenced by: '<S28>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_c;       /* Expression: -2
                                        * Referenced by: '<S28>/Saturation1'
                                        */
  real_T Saturation3_UpperSat_i;       /* Expression: 0
                                        * Referenced by: '<S28>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_k;       /* Expression: -1
                                        * Referenced by: '<S28>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_g;       /* Expression: 1
                                        * Referenced by: '<S28>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_o;       /* Expression: -1
                                        * Referenced by: '<S28>/Saturation2'
                                        */
  real_T Constant_Value_o[12636];      /* Expression: Hn_Xdir
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant1_Value_d[3159];      /* Expression: Kn_Xdir
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real_T Constant2_Value_i[1432];      /* Expression: Fi_Xdir
                                        * Referenced by: '<S21>/Constant2'
                                        */
  real_T Constant3_Value_o[358];       /* Expression: Gi_Xdir
                                        * Referenced by: '<S21>/Constant3'
                                        */
  real_T Constant4_Value[358];         /* Expression: Nc_Xdir
                                        * Referenced by: '<S21>/Constant4'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 0.2094
                                        * Referenced by: '<S16>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -0.2094
                                        * Referenced by: '<S16>/Saturation4'
                                        */
  real_T UnitDelay2_X0_m;              /* Expression: 0
                                        * Referenced by: '<S23>/Unit Delay2'
                                        */
  real_T UnitDelay_X0;                 /* Expression: 0
                                        * Referenced by: '<S23>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: .33333
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 0.2094
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -0.2094
                                        * Referenced by: '<S17>/Saturation'
                                        */
  real_T Saturation1_UpperSat_o;       /* Expression: 2
                                        * Referenced by: '<S17>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_cl;      /* Expression: -2
                                        * Referenced by: '<S17>/Saturation1'
                                        */
  real_T SliderGain_Gain_g;            /* Expression: gain
                                        * Referenced by: '<S33>/Slider Gain'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T SliderGain_Gain_b;            /* Expression: gain
                                        * Referenced by: '<S32>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_n;       /* Expression: 1
                                        * Referenced by: '<S17>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_c;       /* Expression: -1
                                        * Referenced by: '<S17>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_b;       /* Expression: 1
                                        * Referenced by: '<S17>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_h;       /* Expression: -1
                                        * Referenced by: '<S17>/Saturation2'
                                        */
  real_T Constant_Value_c[16];         /* Expression: Aff_roll
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Constant1_Value_gy[8];        /* Expression: Bff_roll
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real_T UnitDelay2_X0_d;              /* Expression: 0
                                        * Referenced by: '<S30>/Unit Delay2'
                                        */
  real_T Constant_Value_l[4532];       /* Expression: Hn_Ydir
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Constant1_Value_j[1133];      /* Expression: Kn_Ydir
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T Constant2_Value_j[536];       /* Expression: Fi_Ydir
                                        * Referenced by: '<S30>/Constant2'
                                        */
  real_T Constant3_Value_ok[134];      /* Expression: Gi_Ydir
                                        * Referenced by: '<S30>/Constant3'
                                        */
  real_T Constant4_Value_g[134];       /* Expression: Nc_Ydir
                                        * Referenced by: '<S30>/Constant4'
                                        */
  real_T Saturation4_UpperSat_i;       /* Expression: 0.2094
                                        * Referenced by: '<S17>/Saturation4'
                                        */
  real_T Saturation4_LowerSat_h;       /* Expression: -0.2094
                                        * Referenced by: '<S17>/Saturation4'
                                        */
  real_T UnitDelay2_X0_n;              /* Expression: 0
                                        * Referenced by: '<S31>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_f;               /* Expression: 0
                                        * Referenced by: '<S31>/Unit Delay'
                                        */
  real_T Gain_Gain_f;                  /* Expression: .33333
                                        * Referenced by: '<S31>/Gain'
                                        */
  real_T Saturation1_UpperSat_d;       /* Expression: 1
                                        * Referenced by: '<S20>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -1
                                        * Referenced by: '<S20>/Saturation1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -1
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T Constant_Value_b[224];        /* Expression: Hn_Zdir
                                        * Referenced by: '<S46>/Constant'
                                        */
  real_T Constant1_Value_l[112];       /* Expression: Kn_Zdir
                                        * Referenced by: '<S46>/Constant1'
                                        */
  real_T Constant2_Value_g[54];        /* Expression: Fi_Zdir
                                        * Referenced by: '<S46>/Constant2'
                                        */
  real_T Constant3_Value_m[27];        /* Expression: Gi_Zdir
                                        * Referenced by: '<S46>/Constant3'
                                        */
  real_T Constant4_Value_a[27];        /* Expression: Nc_Zdir
                                        * Referenced by: '<S46>/Constant4'
                                        */
  real_T Saturation2_UpperSat_k;       /* Expression: 1
                                        * Referenced by: '<S20>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_j;       /* Expression: -1
                                        * Referenced by: '<S20>/Saturation2'
                                        */
  real_T UnitDelay2_X0_o;              /* Expression: 0
                                        * Referenced by: '<S47>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_i;               /* Expression: 0
                                        * Referenced by: '<S47>/Unit Delay'
                                        */
  real_T Gain_Gain_p;                  /* Expression: .33333
                                        * Referenced by: '<S47>/Gain'
                                        */
  real_T SliderGain_Gain_a;            /* Expression: gain
                                        * Referenced by: '<S40>/Slider Gain'
                                        */
  real_T Constant_Value_fv;            /* Expression: 1
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T SliderGain_Gain_j;            /* Expression: gain
                                        * Referenced by: '<S39>/Slider Gain'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: pi
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S42>/Constant1'
                                        */
  real_T UnitDelay2_X0_ng;             /* Expression: 0
                                        * Referenced by: '<S37>/Unit Delay2'
                                        */
  real_T Constant_Value_a[6];          /* Expression: Hn_Yaw
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Constant1_Value_gs[6];        /* Expression: Kn_Yaw
                                        * Referenced by: '<S37>/Constant1'
                                        */
  real_T Constant2_Value_jq[3];        /* Expression: Fi_Yaw
                                        * Referenced by: '<S37>/Constant2'
                                        */
  real_T Constant3_Value_b[3];         /* Expression: Gi_Yaw
                                        * Referenced by: '<S37>/Constant3'
                                        */
  real_T Constant4_Value_gb[3];        /* Expression: Nc_Yaw
                                        * Referenced by: '<S37>/Constant4'
                                        */
  real_T Saturation1_UpperSat_g;       /* Expression: pi
                                        * Referenced by: '<S18>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_b;       /* Expression: -pi
                                        * Referenced by: '<S18>/Saturation1'
                                        */
  real_T UnitDelay2_X0_i;              /* Expression: 0
                                        * Referenced by: '<S38>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_c;               /* Expression: 0
                                        * Referenced by: '<S38>/Unit Delay'
                                        */
  real_T Gain_Gain_p0;                 /* Expression: .33333
                                        * Referenced by: '<S38>/Gain'
                                        */
  real_T UnitDelay1_X0_i;              /* Expression: 0
                                        * Referenced by: '<S23>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_d;              /* Expression: 0
                                        * Referenced by: '<S31>/Unit Delay1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 57
                                        * Referenced by: '<S18>/Gain'
                                        */
  real_T UnitDelay1_X0_j;              /* Expression: 0
                                        * Referenced by: '<S38>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_f;              /* Expression: 0
                                        * Referenced by: '<S47>/Unit Delay1'
                                        */
  real_T g_Value;                      /* Expression: g
                                        * Referenced by: '<S49>/g'
                                        */
  real_T raddeg2_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S14>/rad -> deg2'
                                        */
  real_T raddeg1_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S14>/rad -> deg1'
                                        */
  real_T raddeg3_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S14>/rad -> deg3'
                                        */
  real_T raddeg_Gain;                  /* Expression: 180/pi
                                        * Referenced by: '<S14>/rad -> deg'
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
                                        * Referenced by: '<S56>/Integer Delay'
                                        */
  real_T IntegerDelay1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S56>/Integer Delay1'
                                         */
  real_T IntegerDelay2_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S56>/Integer Delay2'
                                         */
  real_T IntegerDelay3_InitialConditio_c;/* Expression: 0.0
                                          * Referenced by: '<S56>/Integer Delay3'
                                          */
  real_T gravity_Value_j;              /* Expression: g
                                        * Referenced by: '<S56>/gravity'
                                        */
  real_T TT_PP_Value[900];             /* Expression: FG_ctrl_x.TT_PP
                                        * Referenced by: '<S62>/TT_PP'
                                        */
  real_T LL_PP_Value[90];              /* Expression: FG_ctrl_x.LL_PP
                                        * Referenced by: '<S62>/LL_PP'
                                        */
  real_T LL_ref_PP_Value[2790];        /* Expression: FG_ctrl_x.LL_ref_PP
                                        * Referenced by: '<S62>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value[900];       /* Expression: FG_ctrl_x.LL_U_ref_PP
                                        * Referenced by: '<S62>/LL_U_ref_PP'
                                        */
  real_T MM_Value[9];                  /* Expression: FG_ctrl_x.MM
                                        * Referenced by: '<S62>/MM'
                                        */
  real_T PP_Value[900];                /* Expression: FG_ctrl_x.PP
                                        * Referenced by: '<S62>/PP'
                                        */
  real_T AA_delay_Value[9];            /* Expression: FG_ctrl_x.AA_delay
                                        * Referenced by: '<S62>/AA_delay'
                                        */
  real_T BB_delay_Value[9];            /* Expression: FG_ctrl_x.BB_delay
                                        * Referenced by: '<S62>/BB_delay'
                                        */
  real_T A_Value_h[16];                /* Expression: kalm_mpc_x.A
                                        * Referenced by: '<S63>/A'
                                        */
  real_T B_Value_i[4];                 /* Expression: kalm_mpc_x.B
                                        * Referenced by: '<S63>/B'
                                        */
  real_T C_Value_c[12];                /* Expression: kalm_mpc_x.C
                                        * Referenced by: '<S63>/C'
                                        */
  real_T D_Value_l[3];                 /* Expression: kalm_mpc_x.D
                                        * Referenced by: '<S63>/D'
                                        */
  real_T Q_Value_a[16];                /* Expression: kalm_mpc_x.Q
                                        * Referenced by: '<S63>/Q'
                                        */
  real_T R_Value_c[9];                 /* Expression: kalm_mpc_x.R
                                        * Referenced by: '<S63>/R'
                                        */
  real_T UnitDelay1_X0_c[16];          /* Expression: kalm_mpc_x.P
                                        * Referenced by: '<S63>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_f;         /* Expression: 0.0
                                        * Referenced by: '<S71>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value[30];              /* Expression: FG_ctrl_x.V_max
                                        * Referenced by: '<S62>/V_max'
                                        */
  real_T i_min_Value;                  /* Expression: FG_ctrl_x.i_min
                                        * Referenced by: '<S62>/i_min'
                                        */
  real_T betas_Value[7];               /* Expression: FG_ctrl_x.betas
                                        * Referenced by: '<S62>/betas'
                                        */
  real_T L_Value;                      /* Expression: FG_ctrl_x.L
                                        * Referenced by: '<S62>/L'
                                        */
  real_T UnitDelay_X0_fc[3];           /* Expression: zeros(FG_ctrl_x.delay_steps,1)
                                        * Referenced by: '<S62>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_k[30];          /* Expression: zeros(size(FG_ctrl_x.V_max,1),1)
                                        * Referenced by: '<S62>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_ia;       /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S63>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S63>/Saturation'
                                        */
  real_T TT_PP_Value_m[900];           /* Expression: FG_ctrl_y.TT_PP
                                        * Referenced by: '<S64>/TT_PP'
                                        */
  real_T LL_PP_Value_e[90];            /* Expression: FG_ctrl_y.LL_PP
                                        * Referenced by: '<S64>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_l[2790];      /* Expression: FG_ctrl_y.LL_ref_PP
                                        * Referenced by: '<S64>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_m[900];     /* Expression: FG_ctrl_y.LL_U_ref_PP
                                        * Referenced by: '<S64>/LL_U_ref_PP'
                                        */
  real_T MM_Value_c[9];                /* Expression: FG_ctrl_y.MM
                                        * Referenced by: '<S64>/MM'
                                        */
  real_T PP_Value_m[900];              /* Expression: FG_ctrl_y.PP
                                        * Referenced by: '<S64>/PP'
                                        */
  real_T AA_delay_Value_h[9];          /* Expression: FG_ctrl_y.AA_delay
                                        * Referenced by: '<S64>/AA_delay'
                                        */
  real_T BB_delay_Value_o[9];          /* Expression: FG_ctrl_y.BB_delay
                                        * Referenced by: '<S64>/BB_delay'
                                        */
  real_T A_Value_n[16];                /* Expression: kalm_mpc_y.A
                                        * Referenced by: '<S65>/A'
                                        */
  real_T B_Value_h[4];                 /* Expression: kalm_mpc_y.B
                                        * Referenced by: '<S65>/B'
                                        */
  real_T C_Value_p[12];                /* Expression: kalm_mpc_y.C
                                        * Referenced by: '<S65>/C'
                                        */
  real_T D_Value_m[3];                 /* Expression: kalm_mpc_y.D
                                        * Referenced by: '<S65>/D'
                                        */
  real_T Q_Value_h[16];                /* Expression: kalm_mpc_y.Q
                                        * Referenced by: '<S65>/Q'
                                        */
  real_T R_Value_l[9];                 /* Expression: kalm_mpc_y.R
                                        * Referenced by: '<S65>/R'
                                        */
  real_T UnitDelay1_X0_fk[16];         /* Expression: kalm_mpc_y.P
                                        * Referenced by: '<S65>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_n;         /* Expression: 0.0
                                        * Referenced by: '<S74>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_o[30];            /* Expression: FG_ctrl_y.V_max
                                        * Referenced by: '<S64>/V_max'
                                        */
  real_T i_min_Value_j;                /* Expression: FG_ctrl_y.i_min
                                        * Referenced by: '<S64>/i_min'
                                        */
  real_T betas_Value_l[7];             /* Expression: FG_ctrl_y.betas
                                        * Referenced by: '<S64>/betas'
                                        */
  real_T L_Value_n;                    /* Expression: FG_ctrl_y.L
                                        * Referenced by: '<S64>/L'
                                        */
  real_T UnitDelay_X0_ik[3];           /* Expression: zeros(FG_ctrl_y.delay_steps,1)
                                        * Referenced by: '<S64>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_jc[30];         /* Expression: zeros(size(FG_ctrl_y.V_max,1),1)
                                        * Referenced by: '<S64>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S65>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S65>/Saturation'
                                        */
  real_T TT_PP_Value_b[900];           /* Expression: FG_ctrl_z.TT_PP
                                        * Referenced by: '<S68>/TT_PP'
                                        */
  real_T LL_PP_Value_j[60];            /* Expression: FG_ctrl_z.LL_PP
                                        * Referenced by: '<S68>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_h[1860];      /* Expression: FG_ctrl_z.LL_ref_PP
                                        * Referenced by: '<S68>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_o[900];     /* Expression: FG_ctrl_z.LL_U_ref_PP
                                        * Referenced by: '<S68>/LL_U_ref_PP'
                                        */
  real_T MM_Value_l[4];                /* Expression: FG_ctrl_z.MM
                                        * Referenced by: '<S68>/MM'
                                        */
  real_T PP_Value_o[900];              /* Expression: FG_ctrl_z.PP
                                        * Referenced by: '<S68>/PP'
                                        */
  real_T AA_delay_Value_l[4];          /* Expression: FG_ctrl_z.AA_delay
                                        * Referenced by: '<S68>/AA_delay'
                                        */
  real_T BB_delay_Value_b[4];          /* Expression: FG_ctrl_z.BB_delay
                                        * Referenced by: '<S68>/BB_delay'
                                        */
  real_T A_Value_f[9];                 /* Expression: kalm_mpc_z.A
                                        * Referenced by: '<S69>/A'
                                        */
  real_T B_Value_n[3];                 /* Expression: kalm_mpc_z.B
                                        * Referenced by: '<S69>/B'
                                        */
  real_T C_Value_o[6];                 /* Expression: kalm_mpc_z.C
                                        * Referenced by: '<S69>/C'
                                        */
  real_T D_Value_j[2];                 /* Expression: kalm_mpc_z.D
                                        * Referenced by: '<S69>/D'
                                        */
  real_T Q_Value_j[9];                 /* Expression: kalm_mpc_z.Q
                                        * Referenced by: '<S69>/Q'
                                        */
  real_T R_Value_ca[4];                /* Expression: kalm_mpc_z.R
                                        * Referenced by: '<S69>/R'
                                        */
  real_T UnitDelay1_X0_cw[9];          /* Expression: kalm_mpc_z.P
                                        * Referenced by: '<S69>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_c;         /* Expression: 0.0
                                        * Referenced by: '<S80>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_i[30];            /* Expression: FG_ctrl_z.V_max
                                        * Referenced by: '<S68>/V_max'
                                        */
  real_T i_min_Value_o;                /* Expression: FG_ctrl_z.i_min
                                        * Referenced by: '<S68>/i_min'
                                        */
  real_T betas_Value_g[8];             /* Expression: FG_ctrl_z.betas
                                        * Referenced by: '<S68>/betas'
                                        */
  real_T L_Value_m;                    /* Expression: FG_ctrl_z.L
                                        * Referenced by: '<S68>/L'
                                        */
  real_T UnitDelay_X0_a[2];            /* Expression: zeros(FG_ctrl_z.delay_steps,1)
                                        * Referenced by: '<S68>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_b[30];          /* Expression: zeros(size(FG_ctrl_z.V_max,1),1)
                                        * Referenced by: '<S68>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: MAX_BIAS_THRUST
                                        * Referenced by: '<S69>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -MAX_BIAS_THRUST
                                        * Referenced by: '<S69>/Saturation'
                                        */
  real_T TT_PP_Value_o[900];           /* Expression: FG_ctrl_yaw.TT_PP
                                        * Referenced by: '<S66>/TT_PP'
                                        */
  real_T LL_PP_Value_j5[60];           /* Expression: FG_ctrl_yaw.LL_PP
                                        * Referenced by: '<S66>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_e[1860];      /* Expression: FG_ctrl_yaw.LL_ref_PP
                                        * Referenced by: '<S66>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_b[900];     /* Expression: FG_ctrl_yaw.LL_U_ref_PP
                                        * Referenced by: '<S66>/LL_U_ref_PP'
                                        */
  real_T MM_Value_g[4];                /* Expression: FG_ctrl_yaw.MM
                                        * Referenced by: '<S66>/MM'
                                        */
  real_T PP_Value_p[900];              /* Expression: FG_ctrl_yaw.PP
                                        * Referenced by: '<S66>/PP'
                                        */
  real_T AA_delay_Value_o[4];          /* Expression: FG_ctrl_yaw.AA_delay
                                        * Referenced by: '<S66>/AA_delay'
                                        */
  real_T BB_delay_Value_d[12];         /* Expression: FG_ctrl_yaw.BB_delay
                                        * Referenced by: '<S66>/BB_delay'
                                        */
  real_T A_Value_k[9];                 /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S67>/A'
                                        */
  real_T B_Value_f[3];                 /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S67>/B'
                                        */
  real_T C_Value_b[6];                 /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S67>/C'
                                        */
  real_T D_Value_c[2];                 /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S67>/D'
                                        */
  real_T Q_Value_g[9];                 /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S67>/Q'
                                        */
  real_T R_Value_o[4];                 /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S67>/R'
                                        */
  real_T UnitDelay1_X0_n[9];           /* Expression: kalm_mpc_yaw.P
                                        * Referenced by: '<S67>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_e;         /* Expression: 0.0
                                        * Referenced by: '<S77>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_f[30];            /* Expression: FG_ctrl_yaw.V_max
                                        * Referenced by: '<S66>/V_max'
                                        */
  real_T i_min_Value_n;                /* Expression: FG_ctrl_yaw.i_min
                                        * Referenced by: '<S66>/i_min'
                                        */
  real_T betas_Value_j[5];             /* Expression: FG_ctrl_yaw.betas
                                        * Referenced by: '<S66>/betas'
                                        */
  real_T L_Value_g;                    /* Expression: FG_ctrl_yaw.L
                                        * Referenced by: '<S66>/L'
                                        */
  real_T UnitDelay_X0_fj[6];           /* Expression: zeros(FG_ctrl_yaw.delay_steps,1)
                                        * Referenced by: '<S66>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_o[30];          /* Expression: zeros(size(FG_ctrl_yaw.V_max,1),1)
                                        * Referenced by: '<S66>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_o3;       /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S67>/Saturation'
                                        */
  real_T Saturation_LowerSat_kn;       /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S67>/Saturation'
                                        */
  real_T g_Value_m;                    /* Expression: g
                                        * Referenced by: '<S82>/g'
                                        */
  real_T raddeg2_Gain_p;               /* Expression: 180/pi
                                        * Referenced by: '<S60>/rad -> deg2'
                                        */
  real_T raddeg1_Gain_a;               /* Expression: 180/pi
                                        * Referenced by: '<S60>/rad -> deg1'
                                        */
  real_T raddeg3_Gain_k;               /* Expression: 180/pi
                                        * Referenced by: '<S60>/rad -> deg3'
                                        */
  real_T raddeg_Gain_k;                /* Expression: 180/pi
                                        * Referenced by: '<S60>/rad -> deg'
                                        */
  real_T pitch_offset_Value;           /* Expression: 0.00
                                        * Referenced by: '<S7>/pitch_offset'
                                        */
  real_T InitialCondition_Value;       /* Expression: vinit
                                        * Referenced by: '<S55>/Initial Condition'
                                        */
  real_T Constant1_Value_mr;           /* Expression: 1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T FixPtUnitDelay1_X0_h;         /* Expression: vinit
                                        * Referenced by: '<S55>/FixPt Unit Delay1'
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
                                        * Referenced by: '<S56>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength;  /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S56>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength;  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S56>/Integer Delay2'
                                        */
  uint32_T IntegerDelay3_DelayLength_o;/* Computed Parameter: IntegerDelay3_DelayLength_o
                                        * Referenced by: '<S56>/Integer Delay3'
                                        */
  uint8_T FixPtUnitDelay2_X0;          /* Computed Parameter: FixPtUnitDelay2_X0
                                        * Referenced by: '<S44>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S44>/FixPt Constant'
                                        */
  uint8_T FixPtUnitDelay2_X0_d;        /* Computed Parameter: FixPtUnitDelay2_X0_d
                                        * Referenced by: '<S71>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_n;        /* Computed Parameter: FixPtUnitDelay2_X0_n
                                        * Referenced by: '<S74>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_do;       /* Computed Parameter: FixPtUnitDelay2_X0_do
                                        * Referenced by: '<S80>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_i;        /* Computed Parameter: FixPtUnitDelay2_X0_i
                                        * Referenced by: '<S77>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtConstant_Value_h;       /* Computed Parameter: FixPtConstant_Value_h
                                        * Referenced by: '<S71>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_o;       /* Computed Parameter: FixPtConstant_Value_o
                                        * Referenced by: '<S74>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_n;       /* Computed Parameter: FixPtConstant_Value_n
                                        * Referenced by: '<S77>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_p;       /* Computed Parameter: FixPtConstant_Value_p
                                        * Referenced by: '<S80>/FixPt Constant'
                                        */
  uint8_T FixPtUnitDelay2_X0_g;        /* Computed Parameter: FixPtUnitDelay2_X0_g
                                        * Referenced by: '<S55>/FixPt Unit Delay2'
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
                                        * Referenced by: '<S54>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_e;   /* Expression: uint8(0)
                                        * Referenced by: '<S54>/SwitchControl'
                                        */
  uint8_T FixPtConstant_Value_i;       /* Computed Parameter: FixPtConstant_Value_i
                                        * Referenced by: '<S55>/FixPt Constant'
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
 * '<S11>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation'
 * '<S12>'  : 'controller_template/FreeFlight Pos Ctrl/get ref from vector'
 * '<S13>'  : 'controller_template/FreeFlight Pos Ctrl/rotate to world frame'
 * '<S14>'  : 'controller_template/FreeFlight Pos Ctrl/view & log signals'
 * '<S15>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/demux'
 * '<S16>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S17>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S18>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S19>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S20>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S21>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1'
 * '<S22>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /MATLAB Function'
 * '<S23>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Mean'
 * '<S24>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Slider Gain'
 * '<S25>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Slider Gain1'
 * '<S26>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Slider Gain2'
 * '<S27>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/Ctrl_Xdir'
 * '<S28>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/PitchPropagate'
 * '<S29>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/PitchPropagate/MATLAB Function'
 * '<S30>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1'
 * '<S31>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Mean'
 * '<S32>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Slider Gain'
 * '<S33>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Slider Gain1'
 * '<S34>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S35>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate'
 * '<S36>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate/MATLAB Function'
 * '<S37>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1'
 * '<S38>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Mean'
 * '<S39>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain'
 * '<S40>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain1'
 * '<S41>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S42>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate'
 * '<S43>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate/MATLAB Function'
 * '<S44>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S45>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S46>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1'
 * '<S47>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Mean'
 * '<S48>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S49>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling '
 * '<S50>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame'
 * '<S51>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S52>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S53>'  : 'controller_template/FreeFlight Pos Ctrl/rotate to world frame/Embedded MATLAB Function'
 * '<S54>'  : 'controller_template/convert2cmd/Manual Switch'
 * '<S55>'  : 'controller_template/delay/delay bias'
 * '<S56>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1'
 * '<S57>'  : 'controller_template/pos controller/decoupling and rotation'
 * '<S58>'  : 'controller_template/pos controller/get ref from vector'
 * '<S59>'  : 'controller_template/pos controller/rotate to world frame'
 * '<S60>'  : 'controller_template/pos controller/view & log signals'
 * '<S61>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/demux'
 * '<S62>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S63>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias'
 * '<S64>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S65>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias'
 * '<S66>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S67>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S68>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S69>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias'
 * '<S70>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  /runFastGradient'
 * '<S71>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/Unit Delay External IC1'
 * '<S72>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/discrete kalman filter'
 * '<S73>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG/runFastGradient'
 * '<S74>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/Unit Delay External IC1'
 * '<S75>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/discrete kalman filter'
 * '<S76>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG/runFastGradient'
 * '<S77>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S78>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S79>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG/runFastGradient'
 * '<S80>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/Unit Delay External IC1'
 * '<S81>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/discrete kalman filter'
 * '<S82>'  : 'controller_template/pos controller/decoupling and rotation/decoupling '
 * '<S83>'  : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame'
 * '<S84>'  : 'controller_template/pos controller/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S85>'  : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S86>'  : 'controller_template/pos controller/rotate to world frame/Embedded MATLAB Function'
 */
#endif                                 /* RTW_HEADER_controller_template_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
