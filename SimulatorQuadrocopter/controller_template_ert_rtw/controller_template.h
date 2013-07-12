/*
 * File: controller_template.h
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.613
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Aug  6 2011)
 * C/C++ source code generated on : Wed Jul 10 21:38:37 2013
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

/* Block signals for system '<S37>/MATLAB Function' */
typedef struct {
  real_T y[4];                         /* '<S37>/MATLAB Function' */
} rtB_MATLABFunction_controller_t;

/* Block states (auto storage) for system '<S37>/MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S37>/MATLAB Function' */
  uint8_T is_active_c26_controller_templa;/* '<S37>/MATLAB Function' */
  boolean_T isStable;                  /* '<S37>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S37>/MATLAB Function' */
} rtDW_MATLABFunction_controller_;

/* Block signals for system '<S35>/MATLAB Function' */
typedef struct {
  real_T y;                            /* '<S35>/MATLAB Function' */
} rtB_MATLABFunction_controller_m;

/* Block states (auto storage) for system '<S35>/MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S35>/MATLAB Function' */
  uint8_T is_active_c15_controller_templa;/* '<S35>/MATLAB Function' */
  boolean_T isStable;                  /* '<S35>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S35>/MATLAB Function' */
} rtDW_MATLABFunction_controlle_a;

/* Block signals for system '<S27>/discrete kalman filter' */
typedef struct {
  real_T state_est[3];                 /* '<S27>/discrete kalman filter' */
  real_T P_est[9];                     /* '<S27>/discrete kalman filter' */
} rtB_discretekalmanfilter_contro;

/* Block states (auto storage) for system '<S27>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S27>/discrete kalman filter' */
  uint8_T is_active_c27_controller_templa;/* '<S27>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S27>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S27>/discrete kalman filter' */
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

/* Block signals for system '<S99>/runFastGradient' */
typedef struct {
  real_T u_opt;                        /* '<S99>/runFastGradient' */
  real_T J_star;                       /* '<S99>/runFastGradient' */
  real_T u_buff_out[3];                /* '<S99>/runFastGradient' */
  real_T V_init_out[30];               /* '<S99>/runFastGradient' */
} rtB_runFastGradient_controller_;

/* Block states (auto storage) for system '<S99>/runFastGradient' */
typedef struct {
  int32_T sfEvent;                     /* '<S99>/runFastGradient' */
  uint8_T is_active_c6_Hquad_control_LIB_;/* '<S99>/runFastGradient' */
  boolean_T isStable;                  /* '<S99>/runFastGradient' */
  boolean_T doneDoubleBufferReInit;    /* '<S99>/runFastGradient' */
} rtDW_runFastGradient_controller;

/* Block signals for system '<S100>/discrete kalman filter' */
typedef struct {
  real_T state_est[4];                 /* '<S100>/discrete kalman filter' */
  real_T P_est[16];                    /* '<S100>/discrete kalman filter' */
} rtB_discretekalmanfilter_cont_h;

/* Block states (auto storage) for system '<S100>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S100>/discrete kalman filter' */
  uint8_T is_active_c11_Hquad_control_LIB;/* '<S100>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S100>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S100>/discrete kalman filter' */
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
  real_T Gain[4];                      /* '<S97>/Gain' */
  real_T raddeg2[3];                   /* '<S97>/rad -> deg2' */
  real_T raddeg1[3];                   /* '<S97>/rad -> deg1' */
  real_T raddeg3[3];                   /* '<S97>/rad -> deg3' */
  real_T raddeg[4];                    /* '<S97>/rad -> deg' */
  real_T bias_W[4];                    /* '<S94>/bias_W' */
  real_T cmd_W[4];                     /* '<S94>/cmd_W' */
  real_T pitch_rot;                    /* '<S120>/Embedded MATLAB Function' */
  real_T roll_rot;                     /* '<S120>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S120>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S120>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp;               /* '<S119>/Embedded MATLAB Function' */
  real_T roll_cmd_comp;                /* '<S119>/Embedded MATLAB Function' */
  real_T thrust_comp;                  /* '<S119>/Embedded MATLAB Function' */
  real_T thrust_cmd_e;                 /* '<S93>/Sum5' */
  real_T u_opt;                        /* '<S105>/runFastGradient' */
  real_T J_star;                       /* '<S105>/runFastGradient' */
  real_T u_buff_out[2];                /* '<S105>/runFastGradient' */
  real_T V_init_out[30];               /* '<S105>/runFastGradient' */
  real_T u_opt_l;                      /* '<S103>/runFastGradient' */
  real_T J_star_h;                     /* '<S103>/runFastGradient' */
  real_T u_buff_out_i[6];              /* '<S103>/runFastGradient' */
  real_T V_init_out_n[30];             /* '<S103>/runFastGradient' */
  real_T y_ref;                        /* '<S69>/Unit Delay' */
  real_T z_ref;                        /* '<S69>/Unit Delay' */
  real_T x_ref;                        /* '<S12>/SwitchControl' */
  real_T y_ref_h;                      /* '<S12>/SwitchControl' */
  real_T z_ref_n;                      /* '<S12>/SwitchControl' */
  real_T Gain_p[18];                   /* '<S16>/Gain' */
  real_T raddeg2_p[3];                 /* '<S16>/rad -> deg2' */
  real_T raddeg1_e[2];                 /* '<S16>/rad -> deg1' */
  real_T x_dot_ref;                    /* '<S12>/SwitchControl' */
  real_T y_dot_ref;                    /* '<S12>/SwitchControl' */
  real_T raddeg3_a[3];                 /* '<S16>/rad -> deg3' */
  real_T raddeg_j[4];                  /* '<S16>/rad -> deg' */
  real_T z_dot_ref;                    /* '<S12>/SwitchControl' */
  real_T bias_W_b[4];                  /* '<S14>/bias_W' */
  real_T cmd_W_h[4];                   /* '<S14>/cmd_W' */
  real_T pitch_rot_n;                  /* '<S83>/Embedded MATLAB Function' */
  real_T roll_rot_e;                   /* '<S83>/Embedded MATLAB Function' */
  real_T pitch_bias_rot_i;             /* '<S83>/Embedded MATLAB Function' */
  real_T roll_bias_rot_d;              /* '<S83>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp_n;             /* '<S82>/Embedded MATLAB Function' */
  real_T roll_cmd_comp_j;              /* '<S82>/Embedded MATLAB Function' */
  real_T thrust_comp_k;                /* '<S82>/Embedded MATLAB Function' */
  real_T en;                           /* '<S69>/Next Ref' */
  real_T Gain2;                        /* '<S27>/Gain2' */
  real_T SwitchControl;                /* '<S32>/SwitchControl' */
  real_T RateTransition[4];            /* '<S30>/Rate Transition' */
  real_T UnitDelay2;                   /* '<S30>/Unit Delay2' */
  real_T RateTransition_l[4];          /* '<S29>/Rate Transition' */
  real_T UnitDelay2_p;                 /* '<S29>/Unit Delay2' */
  real_T Gain_pk;                      /* '<S34>/Gain' */
  real_T Saturation3;                  /* '<S25>/Saturation3' */
  real_T RateTransition_i[4];          /* '<S45>/Rate Transition' */
  real_T UnitDelay2_o;                 /* '<S45>/Unit Delay2' */
  real_T Gain_f;                       /* '<S46>/Gain' */
  real_T Saturation1;                  /* '<S28>/Saturation1' */
  real_T RateTransition_j[2];          /* '<S66>/Rate Transition' */
  real_T Gain_i;                       /* '<S67>/Gain' */
  real_T Sum;                          /* '<S26>/Sum' */
  real_T Gain_n;                       /* '<S55>/Gain' */
  real_T thrust_cmd_a;                 /* '<S11>/Sum5' */
  real_T RateTransition1;              /* '<S29>/Rate Transition1' */
  real_T RateTransition1_l;            /* '<S30>/Rate Transition1' */
  real_T RateTransition1_lq;           /* '<S45>/Rate Transition1' */
  real_T Gain_g;                       /* '<S26>/Gain' */
  real_T Gain1;                        /* '<S27>/Gain1' */
  real_T Gain_d;                       /* '<S27>/Gain' */
  real_T U;                            /* '<S66>/Ctrl_Xdir' */
  real_T flag_oob;                     /* '<S66>/Ctrl_Xdir' */
  real_T psi_prime;                    /* '<S27>/MATLAB Function' */
  real_T psi_out;                      /* '<S26>/MATLAB Function1' */
  real_T delta_x;                      /* '<S26>/MATLAB Function1' */
  real_T psi_prime_l;                  /* '<S26>/MATLAB Function' */
  real_T y;                            /* '<S61>/MATLAB Function' */
  real_T U_g;                          /* '<S52>/Ctrl_Xdir' */
  real_T flag_oob_l;                   /* '<S52>/Ctrl_Xdir' */
  real_T U_p;                          /* '<S45>/Ctrl_Xdir' */
  real_T flag_oob_o;                   /* '<S45>/Ctrl_Xdir' */
  real_T y_i[4];                       /* '<S40>/MATLAB Function' */
  real_T U_gb;                         /* '<S30>/Ctrl_Xdir' */
  real_T flag_oob_ow;                  /* '<S30>/Ctrl_Xdir' */
  real_T U_a;                          /* '<S29>/Ctrl_Xdir' */
  real_T flag_oob_l1;                  /* '<S29>/Ctrl_Xdir' */
  rtB_EmbeddedMATLABFunction_cont sf_EmbeddedMATLABFunction_o;/* '<S96>/Embedded MATLAB Function' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_k;/* '<S106>/discrete kalman filter' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_n;/* '<S104>/discrete kalman filter' */
  rtB_discretekalmanfilter_cont_h sf_discretekalmanfilter_m;/* '<S102>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient_d;/* '<S101>/runFastGradient' */
  rtB_discretekalmanfilter_cont_h sf_discretekalmanfilter_b;/* '<S100>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient;/* '<S99>/runFastGradient' */
  rtB_EmbeddedMATLABFunction_cont sf_EmbeddedMATLABFunction;/* '<S15>/Embedded MATLAB Function' */
  rtB_MATLABFunction_controller_m sf_MATLABFunction_p;/* '<S85>/MATLAB Function' */
  rtB_generate_X_ref_z_controller sf_generate_X_ref_z;/* '<S73>/generate_X_ref_z' */
  rtB_generate_X_ref_yaw_controll sf_generate_X_ref_yaw;/* '<S73>/generate_X_ref_yaw' */
  rtB_generate_X_ref_y_controller sf_generate_X_ref_y;/* '<S73>/generate_X_ref_y' */
  rtB_generate_X_ref_x_controller sf_generate_X_ref_x;/* '<S73>/generate_X_ref_x' */
  rtB_MATLABFunction_controller_m sf_MATLABFunction;/* '<S72>/MATLAB Function' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter;/* '<S27>/discrete kalman filter' */
  rtB_MATLABFunction_controller_t sf_MATLABFunction_k;/* '<S50>/MATLAB Function' */
  rtB_MATLABFunction_controller_m sf_MATLABFunction_e;/* '<S35>/MATLAB Function' */
  rtB_MATLABFunction_controller_t sf_MATLABFunction_i;/* '<S37>/MATLAB Function' */
  rtB_generate_X_ref_z_controller sf_generate_X_ref_z_l;/* '<S17>/generate_X_ref_z' */
  rtB_generate_X_ref_yaw_controll sf_generate_X_ref_yaw_g;/* '<S17>/generate_X_ref_yaw' */
  rtB_generate_X_ref_y_controller sf_generate_X_ref_y_a;/* '<S17>/generate_X_ref_y' */
  rtB_generate_X_ref_x_controller sf_generate_X_ref_x_k;/* '<S17>/generate_X_ref_x' */
} BlockIO_controller_template;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T FixPtUnitDelay1_DSTATE[4];    /* '<S92>/FixPt Unit Delay1' */
  real_T IntegerDelay_DSTATE;          /* '<S93>/Integer Delay' */
  real_T IntegerDelay1_DSTATE;         /* '<S93>/Integer Delay1' */
  real_T IntegerDelay2_DSTATE;         /* '<S93>/Integer Delay2' */
  real_T IntegerDelay3_DSTATE;         /* '<S93>/Integer Delay3' */
  real_T UnitDelay1_DSTATE[16];        /* '<S100>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i[3];  /* '<S108>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE[3];          /* '<S99>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c[30];      /* '<S99>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_b[16];      /* '<S102>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_g[3];  /* '<S111>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_j[3];        /* '<S101>/Unit Delay' */
  real_T UnitDelay1_DSTATE_l[30];      /* '<S101>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_j[9];       /* '<S106>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_d[2];  /* '<S117>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_l[2];        /* '<S105>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g[30];      /* '<S105>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_lx[9];      /* '<S104>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_e[2];  /* '<S114>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_jz[6];       /* '<S103>/Unit Delay' */
  real_T UnitDelay1_DSTATE_js[30];     /* '<S103>/Unit Delay1' */
  real_T UnitDelay_2_DSTATE;           /* '<S69>/Unit Delay' */
  real_T UnitDelay_3_DSTATE;           /* '<S69>/Unit Delay' */
  real_T UnitDelay_DSTATE_g;           /* '<S73>/Unit Delay' */
  real_T UnitDelay_DSTATE_e;           /* '<S17>/Unit Delay' */
  real_T IntegerDelay3_DSTATE_k;       /* '<S11>/Integer Delay3' */
  real_T UnitDelay1_DSTATE_bg[9];      /* '<S27>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i1[2]; /* '<S64>/FixPt Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S30>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_m;          /* '<S29>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_d;          /* '<S34>/Unit Delay2' */
  real_T UnitDelay_DSTATE_jv;          /* '<S34>/Unit Delay' */
  real_T UnitDelay2_DSTATE_l;          /* '<S45>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_k;          /* '<S46>/Unit Delay2' */
  real_T UnitDelay_DSTATE_f;           /* '<S46>/Unit Delay' */
  real_T UnitDelay2_DSTATE_b;          /* '<S67>/Unit Delay2' */
  real_T UnitDelay_DSTATE_fw;          /* '<S67>/Unit Delay' */
  real_T UnitDelay_DSTATE_lg;          /* '<S26>/Unit Delay' */
  real_T UnitDelay2_DSTATE_g;          /* '<S52>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_ga;         /* '<S55>/Unit Delay2' */
  real_T UnitDelay_DSTATE_p;           /* '<S55>/Unit Delay' */
  real_T UnitDelay1_DSTATE_a;          /* '<S34>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_ji;         /* '<S46>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_c3;         /* '<S55>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_m;          /* '<S67>/Unit Delay1' */
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
  } ToFile_PWORK;                      /* '<S97>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<S97>/To File1' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S97>/To Workspace' */

  struct {
    void *LoggedData;
  } pitchcmd_PWORK;                    /* '<S97>/pitch cmd' */

  struct {
    void *LoggedData;
  } rollcmd_PWORK;                     /* '<S97>/roll cmd' */

  struct {
    void *LoggedData;
  } thrustcmd_PWORK;                   /* '<S97>/thrust cmd' */

  struct {
    void *LoggedData;
  } x_ref_PWORK;                       /* '<S97>/x_ref' */

  struct {
    void *LoggedData;
  } y_ref_PWORK;                       /* '<S97>/y_ref' */

  struct {
    void *LoggedData;
  } yawcmd_PWORK;                      /* '<S97>/yaw cmd' */

  struct {
    void *LoggedData;
  } yaw_ref_PWORK;                     /* '<S97>/yaw_ref' */

  struct {
    void *LoggedData;
  } z_ref_PWORK;                       /* '<S97>/z_ref' */

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
  } Scope_PWORK;                       /* '<S69>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     /* '<S11>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<S26>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S26>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_e;                     /* '<S27>/Scope' */

  int32_T sfEvent;                     /* '<S120>/Embedded MATLAB Function' */
  int32_T sfEvent_f;                   /* '<S119>/Embedded MATLAB Function' */
  int32_T sfEvent_k;                   /* '<S105>/runFastGradient' */
  int32_T sfEvent_n;                   /* '<S103>/runFastGradient' */
  int32_T sfEvent_j;                   /* '<S83>/Embedded MATLAB Function' */
  int32_T sfEvent_c;                   /* '<S82>/Embedded MATLAB Function' */
  int32_T sfEvent_p;                   /* '<S69>/Next Ref' */
  int32_T sfEvent_k0;                  /* '<S66>/Ctrl_Xdir' */
  int32_T sfEvent_ks;                  /* '<S27>/MATLAB Function' */
  int32_T sfEvent_d;                   /* '<S26>/MATLAB Function1' */
  int32_T sfEvent_g;                   /* '<S26>/MATLAB Function' */
  int32_T sfEvent_l;                   /* '<S61>/MATLAB Function' */
  int32_T sfEvent_jv;                  /* '<S52>/Ctrl_Xdir' */
  int32_T sfEvent_cd;                  /* '<S45>/Ctrl_Xdir' */
  int32_T sfEvent_a;                   /* '<S40>/MATLAB Function' */
  int32_T sfEvent_cm;                  /* '<S30>/Ctrl_Xdir' */
  int32_T sfEvent_cr;                  /* '<S29>/Ctrl_Xdir' */
  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<S97>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<S97>/To File1' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK_g;                    /* '<S16>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK_p;                   /* '<S16>/To File1' */

  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S92>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_l;    /* '<S108>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_b;    /* '<S111>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S117>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S114>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_g;    /* '<S64>/FixPt Unit Delay2' */
  int8_T FreeFlightPosCtrl_SubsysRanBC;/* '<Root>/FreeFlight Pos Ctrl' */
  int8_T poscontroller_SubsysRanBC;    /* '<Root>/pos controller' */
  uint8_T is_active_c4_Hquad_control_LIB_;/* '<S120>/Embedded MATLAB Function' */
  uint8_T is_active_c1_Hquad_control_LIB_;/* '<S119>/Embedded MATLAB Function' */
  uint8_T is_active_c8_Hquad_control_LIB_;/* '<S105>/runFastGradient' */
  uint8_T is_active_c9_Hquad_control_LIB_;/* '<S103>/runFastGradient' */
  uint8_T is_active_c10_controller_templa;/* '<S83>/Embedded MATLAB Function' */
  uint8_T is_active_c9_controller_templat;/* '<S82>/Embedded MATLAB Function' */
  uint8_T is_active_c35_controller_templa;/* '<S69>/Next Ref' */
  uint8_T is_active_c3_controller_templat;/* '<S66>/Ctrl_Xdir' */
  uint8_T is_active_c28_controller_templa;/* '<S27>/MATLAB Function' */
  uint8_T is_active_c30_controller_templa;/* '<S26>/MATLAB Function1' */
  uint8_T is_active_c25_controller_templa;/* '<S26>/MATLAB Function' */
  uint8_T is_active_c6_controller_templat;/* '<S61>/MATLAB Function' */
  uint8_T is_active_c4_controller_templat;/* '<S52>/Ctrl_Xdir' */
  uint8_T is_active_c2_controller_templat;/* '<S45>/Ctrl_Xdir' */
  uint8_T is_active_c7_controller_templat;/* '<S40>/MATLAB Function' */
  uint8_T is_active_c1_controller_templat;/* '<S30>/Ctrl_Xdir' */
  uint8_T is_active_c24_controller_templa;/* '<S29>/Ctrl_Xdir' */
  boolean_T isStable;                  /* '<S120>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S120>/Embedded MATLAB Function' */
  boolean_T isStable_m;                /* '<S119>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S119>/Embedded MATLAB Function' */
  boolean_T isStable_i;                /* '<S105>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_h;  /* '<S105>/runFastGradient' */
  boolean_T isStable_h;                /* '<S103>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_o;  /* '<S103>/runFastGradient' */
  boolean_T isStable_o;                /* '<S83>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S83>/Embedded MATLAB Function' */
  boolean_T isStable_mf;               /* '<S82>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_a;  /* '<S82>/Embedded MATLAB Function' */
  boolean_T isStable_od;               /* '<S69>/Next Ref' */
  boolean_T doneDoubleBufferReInit_em; /* '<S69>/Next Ref' */
  boolean_T isStable_c;                /* '<S66>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_ha; /* '<S66>/Ctrl_Xdir' */
  boolean_T isStable_hz;               /* '<S27>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_l;  /* '<S27>/MATLAB Function' */
  boolean_T isStable_f;                /* '<S26>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_g;  /* '<S26>/MATLAB Function1' */
  boolean_T isStable_a;                /* '<S26>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_ga; /* '<S26>/MATLAB Function' */
  boolean_T isStable_oc;               /* '<S61>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_m;  /* '<S61>/MATLAB Function' */
  boolean_T isStable_hg;               /* '<S52>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_p;  /* '<S52>/Ctrl_Xdir' */
  boolean_T isStable_k;                /* '<S45>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S45>/Ctrl_Xdir' */
  boolean_T isStable_b;                /* '<S40>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_n;  /* '<S40>/MATLAB Function' */
  boolean_T isStable_hy;               /* '<S30>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_f;  /* '<S30>/Ctrl_Xdir' */
  boolean_T isStable_n;                /* '<S29>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_dn; /* '<S29>/Ctrl_Xdir' */
  boolean_T FreeFlightPosCtrl_MODE;    /* '<Root>/FreeFlight Pos Ctrl' */
  boolean_T poscontroller_MODE;        /* '<Root>/pos controller' */
  rtDW_EmbeddedMATLABFunction_con sf_EmbeddedMATLABFunction_o;/* '<S96>/Embedded MATLAB Function' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_k;/* '<S106>/discrete kalman filter' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_n;/* '<S104>/discrete kalman filter' */
  rtDW_discretekalmanfilter_con_c sf_discretekalmanfilter_m;/* '<S102>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient_d;/* '<S101>/runFastGradient' */
  rtDW_discretekalmanfilter_con_c sf_discretekalmanfilter_b;/* '<S100>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient;/* '<S99>/runFastGradient' */
  rtDW_EmbeddedMATLABFunction_con sf_EmbeddedMATLABFunction;/* '<S15>/Embedded MATLAB Function' */
  rtDW_MATLABFunction_controlle_a sf_MATLABFunction_p;/* '<S85>/MATLAB Function' */
  rtDW_generate_X_ref_z_controlle sf_generate_X_ref_z;/* '<S73>/generate_X_ref_z' */
  rtDW_generate_X_ref_yaw_control sf_generate_X_ref_yaw;/* '<S73>/generate_X_ref_yaw' */
  rtDW_generate_X_ref_y_controlle sf_generate_X_ref_y;/* '<S73>/generate_X_ref_y' */
  rtDW_generate_X_ref_x_controlle sf_generate_X_ref_x;/* '<S73>/generate_X_ref_x' */
  rtDW_MATLABFunction_controlle_a sf_MATLABFunction;/* '<S72>/MATLAB Function' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter;/* '<S27>/discrete kalman filter' */
  rtDW_MATLABFunction_controller_ sf_MATLABFunction_k;/* '<S50>/MATLAB Function' */
  rtDW_MATLABFunction_controlle_a sf_MATLABFunction_e;/* '<S35>/MATLAB Function' */
  rtDW_MATLABFunction_controller_ sf_MATLABFunction_i;/* '<S37>/MATLAB Function' */
  rtDW_generate_X_ref_z_controlle sf_generate_X_ref_z_l;/* '<S17>/generate_X_ref_z' */
  rtDW_generate_X_ref_yaw_control sf_generate_X_ref_yaw_g;/* '<S17>/generate_X_ref_yaw' */
  rtDW_generate_X_ref_y_controlle sf_generate_X_ref_y_a;/* '<S17>/generate_X_ref_y' */
  rtDW_generate_X_ref_x_controlle sf_generate_X_ref_x_k;/* '<S17>/generate_X_ref_x' */
} D_Work_controller_template;

/* Parameters (auto storage) */
struct Parameters_controller_template_ {
  real_T Constant3_Value[8];           /* Expression: Bdd_pitch
                                        * Referenced by: '<S40>/Constant3'
                                        */
  real_T Constant1_Value[8];           /* Expression: Bff_pitch
                                        * Referenced by: '<S40>/Constant1'
                                        */
  real_T Constant2_Value[16];          /* Expression: Add_pitch
                                        * Referenced by: '<S40>/Constant2'
                                        */
  real_T Constant_Value[16];           /* Expression: Aff_pitch
                                        * Referenced by: '<S40>/Constant'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S31>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S31>/Saturation3'
                                        */
  real_T Saturation3_UpperSat_j;       /* Expression: 0
                                        * Referenced by: '<S35>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_l;       /* Expression: -1
                                        * Referenced by: '<S35>/Saturation3'
                                        */
  real_T A_Value[9];                   /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S27>/A'
                                        */
  real_T B_Value[3];                   /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S27>/B'
                                        */
  real_T C_Value[6];                   /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S27>/C'
                                        */
  real_T D_Value[2];                   /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S27>/D'
                                        */
  real_T Q_Value[9];                   /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S27>/Q'
                                        */
  real_T R_Value[4];                   /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S27>/R'
                                        */
  real_T IntegerDelay3_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S11>/Integer Delay3'
                                         */
  real_T UnitDelay1_X0[9];             /* Expression: kalm_mpc_yaw.P
                                        * Referenced by: '<S27>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0;           /* Expression: 0.0
                                        * Referenced by: '<S64>/FixPt Unit Delay1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S27>/Gain2'
                                        */
  real_T gravity_Value;                /* Expression: g
                                        * Referenced by: '<S11>/gravity'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: 0.2094
                                        * Referenced by: '<S24>/Saturation'
                                        */
  real_T Saturation_LowerSat_j;        /* Expression: -0.2094
                                        * Referenced by: '<S24>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 2
                                        * Referenced by: '<S24>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -2
                                        * Referenced by: '<S24>/Saturation1'
                                        */
  real_T Constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * Referenced by: '<S43>/Slider Gain'
                                        */
  real_T Constant1_Value_f;            /* Expression: 1
                                        * Referenced by: '<S35>/Constant1'
                                        */
  real_T SliderGain_Gain_b;            /* Expression: gain
                                        * Referenced by: '<S44>/Slider Gain'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S24>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S24>/Saturation2'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S30>/Unit Delay2'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 0.2094
                                        * Referenced by: '<S40>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -0.2094
                                        * Referenced by: '<S40>/Saturation'
                                        */
  real_T Saturation1_UpperSat_o;       /* Expression: 2
                                        * Referenced by: '<S40>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_d;       /* Expression: -2
                                        * Referenced by: '<S40>/Saturation1'
                                        */
  real_T Saturation3_UpperSat_c;       /* Expression: 0
                                        * Referenced by: '<S40>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_k;       /* Expression: -1
                                        * Referenced by: '<S40>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_a;       /* Expression: 1
                                        * Referenced by: '<S40>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_h;       /* Expression: -1
                                        * Referenced by: '<S40>/Saturation2'
                                        */
  real_T Constant_Value_l[9476];       /* Expression: Hn_Xdir
                                        * Referenced by: '<S30>/Constant'
                                        */
  real_T Constant1_Value_fy[2369];     /* Expression: Kn_Xdir
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T Constant2_Value_m[1108];      /* Expression: Fi_Xdir
                                        * Referenced by: '<S30>/Constant2'
                                        */
  real_T Constat3_Value[277];          /* Expression: Gi_Xdir
                                        * Referenced by: '<S30>/Constat3'
                                        */
  real_T Constant4_Value[277];         /* Expression: Nc_Xdir
                                        * Referenced by: '<S30>/Constant4'
                                        */
  real_T Constant_Value_m[16];         /* Expression: Aff_pitch
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Constant1_Value_a[8];         /* Expression: Bff_pitch
                                        * Referenced by: '<S37>/Constant1'
                                        */
  real_T UnitDelay2_X0_b;              /* Expression: 0
                                        * Referenced by: '<S29>/Unit Delay2'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: 0.2094
                                        * Referenced by: '<S37>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -0.2094
                                        * Referenced by: '<S37>/Saturation'
                                        */
  real_T Saturation1_UpperSat_p;       /* Expression: 2
                                        * Referenced by: '<S37>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_l;       /* Expression: -2
                                        * Referenced by: '<S37>/Saturation1'
                                        */
  real_T Saturation3_UpperSat_l;       /* Expression: 1
                                        * Referenced by: '<S37>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_lj;      /* Expression: -1
                                        * Referenced by: '<S37>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_k;       /* Expression: 1
                                        * Referenced by: '<S37>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_c;       /* Expression: -1
                                        * Referenced by: '<S37>/Saturation2'
                                        */
  real_T Constant5_Value[4464];        /* Expression: Hn_XdirFF
                                        * Referenced by: '<S29>/Constant5'
                                        */
  real_T Constant6_Value[1116];        /* Expression: Kn_XdirFF
                                        * Referenced by: '<S29>/Constant6'
                                        */
  real_T Constant7_Value[536];         /* Expression: Fi_XdirFF
                                        * Referenced by: '<S29>/Constant7'
                                        */
  real_T Constant8_Value[134];         /* Expression: Gi_XdirFF
                                        * Referenced by: '<S29>/Constant8'
                                        */
  real_T Constant9_Value[134];         /* Expression: Nc_XdirFF
                                        * Referenced by: '<S29>/Constant9'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 0.2094
                                        * Referenced by: '<S24>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -0.2094
                                        * Referenced by: '<S24>/Saturation4'
                                        */
  real_T UnitDelay2_X0_m;              /* Expression: 0
                                        * Referenced by: '<S34>/Unit Delay2'
                                        */
  real_T UnitDelay_X0;                 /* Expression: 0
                                        * Referenced by: '<S34>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: .33333
                                        * Referenced by: '<S34>/Gain'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 0.2094
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -0.2094
                                        * Referenced by: '<S25>/Saturation'
                                        */
  real_T Saturation1_UpperSat_ou;      /* Expression: 2
                                        * Referenced by: '<S25>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_c;       /* Expression: -2
                                        * Referenced by: '<S25>/Saturation1'
                                        */
  real_T SliderGain_Gain_g;            /* Expression: gain
                                        * Referenced by: '<S48>/Slider Gain'
                                        */
  real_T Constant_Value_g;             /* Expression: 1
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T SliderGain_Gain_be;           /* Expression: gain
                                        * Referenced by: '<S47>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_n;       /* Expression: 1
                                        * Referenced by: '<S25>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_c;       /* Expression: -1
                                        * Referenced by: '<S25>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_b;       /* Expression: 1
                                        * Referenced by: '<S25>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_hu;      /* Expression: -1
                                        * Referenced by: '<S25>/Saturation2'
                                        */
  real_T Constant_Value_co[16];        /* Expression: Aff_roll
                                        * Referenced by: '<S50>/Constant'
                                        */
  real_T Constant1_Value_g[8];         /* Expression: Bff_roll
                                        * Referenced by: '<S50>/Constant1'
                                        */
  real_T UnitDelay2_X0_d;              /* Expression: 0
                                        * Referenced by: '<S45>/Unit Delay2'
                                        */
  real_T Constant_Value_ln[5936];      /* Expression: Hn_Ydir
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Constant1_Value_j[1484];      /* Expression: Kn_Ydir
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real_T Constant2_Value_j[684];       /* Expression: Fi_Ydir
                                        * Referenced by: '<S45>/Constant2'
                                        */
  real_T Constant3_Value_o[171];       /* Expression: Gi_Ydir
                                        * Referenced by: '<S45>/Constant3'
                                        */
  real_T Constant4_Value_g[171];       /* Expression: Nc_Ydir
                                        * Referenced by: '<S45>/Constant4'
                                        */
  real_T Saturation4_UpperSat_i;       /* Expression: 0.2094
                                        * Referenced by: '<S25>/Saturation4'
                                        */
  real_T Saturation4_LowerSat_h;       /* Expression: -0.2094
                                        * Referenced by: '<S25>/Saturation4'
                                        */
  real_T UnitDelay2_X0_n;              /* Expression: 0
                                        * Referenced by: '<S46>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_f;               /* Expression: 0
                                        * Referenced by: '<S46>/Unit Delay'
                                        */
  real_T Gain_Gain_f;                  /* Expression: .33333
                                        * Referenced by: '<S46>/Gain'
                                        */
  real_T Saturation1_UpperSat_d;       /* Expression: 1
                                        * Referenced by: '<S28>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -1
                                        * Referenced by: '<S28>/Saturation1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1
                                        * Referenced by: '<S28>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -1
                                        * Referenced by: '<S28>/Saturation'
                                        */
  real_T Constant_Value_b[508];        /* Expression: Hn_Zdir
                                        * Referenced by: '<S66>/Constant'
                                        */
  real_T Constant1_Value_l[254];       /* Expression: Kn_Zdir
                                        * Referenced by: '<S66>/Constant1'
                                        */
  real_T Constant2_Value_g[118];       /* Expression: Fi_Zdir
                                        * Referenced by: '<S66>/Constant2'
                                        */
  real_T Constant3_Value_m[59];        /* Expression: Gi_Zdir
                                        * Referenced by: '<S66>/Constant3'
                                        */
  real_T Constant4_Value_a[59];        /* Expression: Nc_Zdir
                                        * Referenced by: '<S66>/Constant4'
                                        */
  real_T Saturation2_UpperSat_kw;      /* Expression: 1
                                        * Referenced by: '<S28>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_j;       /* Expression: -1
                                        * Referenced by: '<S28>/Saturation2'
                                        */
  real_T UnitDelay2_X0_o;              /* Expression: 0
                                        * Referenced by: '<S67>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_i;               /* Expression: 0
                                        * Referenced by: '<S67>/Unit Delay'
                                        */
  real_T Gain_Gain_p;                  /* Expression: .33333
                                        * Referenced by: '<S67>/Gain'
                                        */
  real_T UnitDelay_X0_m;               /* Expression: 0
                                        * Referenced by: '<S26>/Unit Delay'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T SliderGain_Gain_a;            /* Expression: gain
                                        * Referenced by: '<S58>/Slider Gain'
                                        */
  real_T Constant2_Value_l;            /* Expression: 1
                                        * Referenced by: '<S26>/Constant2'
                                        */
  real_T SliderGain_Gain_p;            /* Expression: gain
                                        * Referenced by: '<S59>/Slider Gain'
                                        */
  real_T SliderGain_Gain_ai;           /* Expression: gain
                                        * Referenced by: '<S57>/Slider Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S26>/Constant'
                                        */
  real_T SliderGain_Gain_j;            /* Expression: gain
                                        * Referenced by: '<S56>/Slider Gain'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: pi
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -pi
                                        * Referenced by: '<S26>/Saturation'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S61>/Constant1'
                                        */
  real_T UnitDelay2_X0_ng;             /* Expression: 0
                                        * Referenced by: '<S52>/Unit Delay2'
                                        */
  real_T Constant_Value_a[6];          /* Expression: Hn_Yaw
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T Constant1_Value_gs[6];        /* Expression: Kn_Yaw
                                        * Referenced by: '<S52>/Constant1'
                                        */
  real_T Constant2_Value_jq[3];        /* Expression: Fi_Yaw
                                        * Referenced by: '<S52>/Constant2'
                                        */
  real_T Constant3_Value_b[3];         /* Expression: Gi_Yaw
                                        * Referenced by: '<S52>/Constant3'
                                        */
  real_T Constant4_Value_gb[3];        /* Expression: Nc_Yaw
                                        * Referenced by: '<S52>/Constant4'
                                        */
  real_T Saturation1_UpperSat_g;       /* Expression: pi
                                        * Referenced by: '<S26>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_b;       /* Expression: -pi
                                        * Referenced by: '<S26>/Saturation1'
                                        */
  real_T UnitDelay2_X0_i;              /* Expression: 0
                                        * Referenced by: '<S55>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_c;               /* Expression: 0
                                        * Referenced by: '<S55>/Unit Delay'
                                        */
  real_T Gain_Gain_p0;                 /* Expression: .33333
                                        * Referenced by: '<S55>/Gain'
                                        */
  real_T UnitDelay1_X0_i;              /* Expression: 0
                                        * Referenced by: '<S34>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_d;              /* Expression: 0
                                        * Referenced by: '<S46>/Unit Delay1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 57
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T UnitDelay1_X0_j;              /* Expression: 0
                                        * Referenced by: '<S55>/Unit Delay1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 57
                                        * Referenced by: '<S27>/Gain1'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 57
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T UnitDelay1_X0_f;              /* Expression: 0
                                        * Referenced by: '<S67>/Unit Delay1'
                                        */
  real_T g_Value;                      /* Expression: g
                                        * Referenced by: '<S82>/g'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S85>/Constant'
                                        */
  real_T SliderGain_Gain_n;            /* Expression: gain
                                        * Referenced by: '<S87>/Slider Gain'
                                        */
  real_T Constant1_Value_i;            /* Expression: 1
                                        * Referenced by: '<S85>/Constant1'
                                        */
  real_T SliderGain_Gain_i;            /* Expression: gain
                                        * Referenced by: '<S88>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_p;       /* Expression: 0
                                        * Referenced by: '<S85>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_e;       /* Expression: -1
                                        * Referenced by: '<S85>/Saturation3'
                                        */
  real_T X_ref_x_Value[12];            /* Expression: traj_FG.X_ref_x
                                        * Referenced by: '<S73>/X_ref_x'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S72>/Constant'
                                        */
  real_T SliderGain_Gain_e;            /* Expression: gain
                                        * Referenced by: '<S76>/Slider Gain'
                                        */
  real_T Constant1_Value_e;            /* Expression: 1
                                        * Referenced by: '<S72>/Constant1'
                                        */
  real_T SliderGain_Gain_jr;           /* Expression: gain
                                        * Referenced by: '<S77>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_f;       /* Expression: 0
                                        * Referenced by: '<S72>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_lw;      /* Expression: -1
                                        * Referenced by: '<S72>/Saturation3'
                                        */
  real_T UnitDelay_2_X0;               /* Expression: 0
                                        * Referenced by: '<S69>/Unit Delay'
                                        */
  real_T UnitDelay_3_X0;               /* Expression: 0
                                        * Referenced by: '<S69>/Unit Delay'
                                        */
  real_T Constant_Value_le;            /* Expression: 1
                                        * Referenced by: '<S69>/Constant'
                                        */
  real_T SliderGain_Gain_h;            /* Expression: gain
                                        * Referenced by: '<S71>/Slider Gain'
                                        */
  real_T UnitDelay_X0_o;               /* Expression: 0
                                        * Referenced by: '<S73>/Unit Delay'
                                        */
  real_T total_samples_Value;          /* Expression: traj_FG.total_samples
                                        * Referenced by: '<S73>/total_samples'
                                        */
  real_T Constant1_Value_mu;           /* Expression: 1
                                        * Referenced by: '<S73>/Constant1'
                                        */
  real_T X_ref_x_Value_k[12];          /* Expression: traj_FG.X_ref_x
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
  real_T X_ref_y_Value[12];            /* Expression: traj_FG.X_ref_y
                                        * Referenced by: '<S73>/X_ref_y'
                                        */
  real_T X_ref_y_Value_e[12];          /* Expression: traj_FG.X_ref_y
                                        * Referenced by: '<S17>/X_ref_y'
                                        */
  real_T X_ref_z_Value[8];             /* Expression: traj_FG.X_ref_z
                                        * Referenced by: '<S73>/X_ref_z'
                                        */
  real_T X_ref_z_Value_a[8];           /* Expression: traj_FG.X_ref_z
                                        * Referenced by: '<S17>/X_ref_z'
                                        */
  real_T X_ref_yaw_Value[8];           /* Expression: traj_FG.X_ref_yaw
                                        * Referenced by: '<S73>/X_ref_yaw'
                                        */
  real_T X_ref_yaw_Value_f[8];         /* Expression: traj_FG.X_ref_yaw
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
                                        * Referenced by: '<S93>/Integer Delay'
                                        */
  real_T IntegerDelay1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S93>/Integer Delay1'
                                         */
  real_T IntegerDelay2_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S93>/Integer Delay2'
                                         */
  real_T IntegerDelay3_InitialConditio_c;/* Expression: 0.0
                                          * Referenced by: '<S93>/Integer Delay3'
                                          */
  real_T gravity_Value_j;              /* Expression: g
                                        * Referenced by: '<S93>/gravity'
                                        */
  real_T TT_PP_Value[900];             /* Expression: FG_ctrl_x.TT_PP
                                        * Referenced by: '<S99>/TT_PP'
                                        */
  real_T LL_PP_Value[90];              /* Expression: FG_ctrl_x.LL_PP
                                        * Referenced by: '<S99>/LL_PP'
                                        */
  real_T LL_ref_PP_Value[2790];        /* Expression: FG_ctrl_x.LL_ref_PP
                                        * Referenced by: '<S99>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value[900];       /* Expression: FG_ctrl_x.LL_U_ref_PP
                                        * Referenced by: '<S99>/LL_U_ref_PP'
                                        */
  real_T MM_Value[9];                  /* Expression: FG_ctrl_x.MM
                                        * Referenced by: '<S99>/MM'
                                        */
  real_T PP_Value[900];                /* Expression: FG_ctrl_x.PP
                                        * Referenced by: '<S99>/PP'
                                        */
  real_T AA_delay_Value[9];            /* Expression: FG_ctrl_x.AA_delay
                                        * Referenced by: '<S99>/AA_delay'
                                        */
  real_T BB_delay_Value[9];            /* Expression: FG_ctrl_x.BB_delay
                                        * Referenced by: '<S99>/BB_delay'
                                        */
  real_T A_Value_h[16];                /* Expression: kalm_mpc_x.A
                                        * Referenced by: '<S100>/A'
                                        */
  real_T B_Value_i[4];                 /* Expression: kalm_mpc_x.B
                                        * Referenced by: '<S100>/B'
                                        */
  real_T C_Value_c[12];                /* Expression: kalm_mpc_x.C
                                        * Referenced by: '<S100>/C'
                                        */
  real_T D_Value_l[3];                 /* Expression: kalm_mpc_x.D
                                        * Referenced by: '<S100>/D'
                                        */
  real_T Q_Value_a[16];                /* Expression: kalm_mpc_x.Q
                                        * Referenced by: '<S100>/Q'
                                        */
  real_T R_Value_c[9];                 /* Expression: kalm_mpc_x.R
                                        * Referenced by: '<S100>/R'
                                        */
  real_T UnitDelay1_X0_c[16];          /* Expression: kalm_mpc_x.P
                                        * Referenced by: '<S100>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_f;         /* Expression: 0.0
                                        * Referenced by: '<S108>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value[30];              /* Expression: FG_ctrl_x.V_max
                                        * Referenced by: '<S99>/V_max'
                                        */
  real_T i_min_Value;                  /* Expression: FG_ctrl_x.i_min
                                        * Referenced by: '<S99>/i_min'
                                        */
  real_T betas_Value[7];               /* Expression: FG_ctrl_x.betas
                                        * Referenced by: '<S99>/betas'
                                        */
  real_T L_Value;                      /* Expression: FG_ctrl_x.L
                                        * Referenced by: '<S99>/L'
                                        */
  real_T UnitDelay_X0_fc[3];           /* Expression: zeros(FG_ctrl_x.delay_steps,1)
                                        * Referenced by: '<S99>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_k[30];          /* Expression: zeros(size(FG_ctrl_x.V_max,1),1)
                                        * Referenced by: '<S99>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_ia;       /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S100>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S100>/Saturation'
                                        */
  real_T TT_PP_Value_m[900];           /* Expression: FG_ctrl_y.TT_PP
                                        * Referenced by: '<S101>/TT_PP'
                                        */
  real_T LL_PP_Value_e[90];            /* Expression: FG_ctrl_y.LL_PP
                                        * Referenced by: '<S101>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_l[2790];      /* Expression: FG_ctrl_y.LL_ref_PP
                                        * Referenced by: '<S101>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_m[900];     /* Expression: FG_ctrl_y.LL_U_ref_PP
                                        * Referenced by: '<S101>/LL_U_ref_PP'
                                        */
  real_T MM_Value_c[9];                /* Expression: FG_ctrl_y.MM
                                        * Referenced by: '<S101>/MM'
                                        */
  real_T PP_Value_m[900];              /* Expression: FG_ctrl_y.PP
                                        * Referenced by: '<S101>/PP'
                                        */
  real_T AA_delay_Value_h[9];          /* Expression: FG_ctrl_y.AA_delay
                                        * Referenced by: '<S101>/AA_delay'
                                        */
  real_T BB_delay_Value_o[9];          /* Expression: FG_ctrl_y.BB_delay
                                        * Referenced by: '<S101>/BB_delay'
                                        */
  real_T A_Value_n[16];                /* Expression: kalm_mpc_y.A
                                        * Referenced by: '<S102>/A'
                                        */
  real_T B_Value_h[4];                 /* Expression: kalm_mpc_y.B
                                        * Referenced by: '<S102>/B'
                                        */
  real_T C_Value_p[12];                /* Expression: kalm_mpc_y.C
                                        * Referenced by: '<S102>/C'
                                        */
  real_T D_Value_m[3];                 /* Expression: kalm_mpc_y.D
                                        * Referenced by: '<S102>/D'
                                        */
  real_T Q_Value_h[16];                /* Expression: kalm_mpc_y.Q
                                        * Referenced by: '<S102>/Q'
                                        */
  real_T R_Value_l[9];                 /* Expression: kalm_mpc_y.R
                                        * Referenced by: '<S102>/R'
                                        */
  real_T UnitDelay1_X0_fk[16];         /* Expression: kalm_mpc_y.P
                                        * Referenced by: '<S102>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_n;         /* Expression: 0.0
                                        * Referenced by: '<S111>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_o[30];            /* Expression: FG_ctrl_y.V_max
                                        * Referenced by: '<S101>/V_max'
                                        */
  real_T i_min_Value_j;                /* Expression: FG_ctrl_y.i_min
                                        * Referenced by: '<S101>/i_min'
                                        */
  real_T betas_Value_l[7];             /* Expression: FG_ctrl_y.betas
                                        * Referenced by: '<S101>/betas'
                                        */
  real_T L_Value_n;                    /* Expression: FG_ctrl_y.L
                                        * Referenced by: '<S101>/L'
                                        */
  real_T UnitDelay_X0_ik[3];           /* Expression: zeros(FG_ctrl_y.delay_steps,1)
                                        * Referenced by: '<S101>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_jc[30];         /* Expression: zeros(size(FG_ctrl_y.V_max,1),1)
                                        * Referenced by: '<S101>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S102>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S102>/Saturation'
                                        */
  real_T TT_PP_Value_b[900];           /* Expression: FG_ctrl_z.TT_PP
                                        * Referenced by: '<S105>/TT_PP'
                                        */
  real_T LL_PP_Value_j[60];            /* Expression: FG_ctrl_z.LL_PP
                                        * Referenced by: '<S105>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_h[1860];      /* Expression: FG_ctrl_z.LL_ref_PP
                                        * Referenced by: '<S105>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_o[900];     /* Expression: FG_ctrl_z.LL_U_ref_PP
                                        * Referenced by: '<S105>/LL_U_ref_PP'
                                        */
  real_T MM_Value_l[4];                /* Expression: FG_ctrl_z.MM
                                        * Referenced by: '<S105>/MM'
                                        */
  real_T PP_Value_o[900];              /* Expression: FG_ctrl_z.PP
                                        * Referenced by: '<S105>/PP'
                                        */
  real_T AA_delay_Value_l[4];          /* Expression: FG_ctrl_z.AA_delay
                                        * Referenced by: '<S105>/AA_delay'
                                        */
  real_T BB_delay_Value_b[4];          /* Expression: FG_ctrl_z.BB_delay
                                        * Referenced by: '<S105>/BB_delay'
                                        */
  real_T A_Value_f[9];                 /* Expression: kalm_mpc_z.A
                                        * Referenced by: '<S106>/A'
                                        */
  real_T B_Value_n[3];                 /* Expression: kalm_mpc_z.B
                                        * Referenced by: '<S106>/B'
                                        */
  real_T C_Value_o[6];                 /* Expression: kalm_mpc_z.C
                                        * Referenced by: '<S106>/C'
                                        */
  real_T D_Value_j[2];                 /* Expression: kalm_mpc_z.D
                                        * Referenced by: '<S106>/D'
                                        */
  real_T Q_Value_j[9];                 /* Expression: kalm_mpc_z.Q
                                        * Referenced by: '<S106>/Q'
                                        */
  real_T R_Value_ca[4];                /* Expression: kalm_mpc_z.R
                                        * Referenced by: '<S106>/R'
                                        */
  real_T UnitDelay1_X0_cw[9];          /* Expression: kalm_mpc_z.P
                                        * Referenced by: '<S106>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_c;         /* Expression: 0.0
                                        * Referenced by: '<S117>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_i[30];            /* Expression: FG_ctrl_z.V_max
                                        * Referenced by: '<S105>/V_max'
                                        */
  real_T i_min_Value_o;                /* Expression: FG_ctrl_z.i_min
                                        * Referenced by: '<S105>/i_min'
                                        */
  real_T betas_Value_g[8];             /* Expression: FG_ctrl_z.betas
                                        * Referenced by: '<S105>/betas'
                                        */
  real_T L_Value_m;                    /* Expression: FG_ctrl_z.L
                                        * Referenced by: '<S105>/L'
                                        */
  real_T UnitDelay_X0_a[2];            /* Expression: zeros(FG_ctrl_z.delay_steps,1)
                                        * Referenced by: '<S105>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_b[30];          /* Expression: zeros(size(FG_ctrl_z.V_max,1),1)
                                        * Referenced by: '<S105>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: MAX_BIAS_THRUST
                                        * Referenced by: '<S106>/Saturation'
                                        */
  real_T Saturation_LowerSat_cp;       /* Expression: -MAX_BIAS_THRUST
                                        * Referenced by: '<S106>/Saturation'
                                        */
  real_T TT_PP_Value_o[900];           /* Expression: FG_ctrl_yaw.TT_PP
                                        * Referenced by: '<S103>/TT_PP'
                                        */
  real_T LL_PP_Value_j5[60];           /* Expression: FG_ctrl_yaw.LL_PP
                                        * Referenced by: '<S103>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_e[1860];      /* Expression: FG_ctrl_yaw.LL_ref_PP
                                        * Referenced by: '<S103>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_b[900];     /* Expression: FG_ctrl_yaw.LL_U_ref_PP
                                        * Referenced by: '<S103>/LL_U_ref_PP'
                                        */
  real_T MM_Value_g[4];                /* Expression: FG_ctrl_yaw.MM
                                        * Referenced by: '<S103>/MM'
                                        */
  real_T PP_Value_p[900];              /* Expression: FG_ctrl_yaw.PP
                                        * Referenced by: '<S103>/PP'
                                        */
  real_T AA_delay_Value_o[4];          /* Expression: FG_ctrl_yaw.AA_delay
                                        * Referenced by: '<S103>/AA_delay'
                                        */
  real_T BB_delay_Value_d[12];         /* Expression: FG_ctrl_yaw.BB_delay
                                        * Referenced by: '<S103>/BB_delay'
                                        */
  real_T A_Value_k[9];                 /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S104>/A'
                                        */
  real_T B_Value_f[3];                 /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S104>/B'
                                        */
  real_T C_Value_b[6];                 /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S104>/C'
                                        */
  real_T D_Value_c[2];                 /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S104>/D'
                                        */
  real_T Q_Value_g[9];                 /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S104>/Q'
                                        */
  real_T R_Value_o[4];                 /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S104>/R'
                                        */
  real_T UnitDelay1_X0_n[9];           /* Expression: kalm_mpc_yaw.P
                                        * Referenced by: '<S104>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_e;         /* Expression: 0.0
                                        * Referenced by: '<S114>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_f[30];            /* Expression: FG_ctrl_yaw.V_max
                                        * Referenced by: '<S103>/V_max'
                                        */
  real_T i_min_Value_n;                /* Expression: FG_ctrl_yaw.i_min
                                        * Referenced by: '<S103>/i_min'
                                        */
  real_T betas_Value_j[5];             /* Expression: FG_ctrl_yaw.betas
                                        * Referenced by: '<S103>/betas'
                                        */
  real_T L_Value_g;                    /* Expression: FG_ctrl_yaw.L
                                        * Referenced by: '<S103>/L'
                                        */
  real_T UnitDelay_X0_fj[6];           /* Expression: zeros(FG_ctrl_yaw.delay_steps,1)
                                        * Referenced by: '<S103>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_o[30];          /* Expression: zeros(size(FG_ctrl_yaw.V_max,1),1)
                                        * Referenced by: '<S103>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_o3;       /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S104>/Saturation'
                                        */
  real_T Saturation_LowerSat_kn;       /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S104>/Saturation'
                                        */
  real_T g_Value_m;                    /* Expression: g
                                        * Referenced by: '<S119>/g'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 1
                                        * Referenced by: '<S97>/Gain'
                                        */
  real_T raddeg2_Gain_p;               /* Expression: 180/pi
                                        * Referenced by: '<S97>/rad -> deg2'
                                        */
  real_T raddeg1_Gain_a;               /* Expression: 180/pi
                                        * Referenced by: '<S97>/rad -> deg1'
                                        */
  real_T raddeg3_Gain_k;               /* Expression: 180/pi
                                        * Referenced by: '<S97>/rad -> deg3'
                                        */
  real_T raddeg_Gain_k;                /* Expression: 180/pi
                                        * Referenced by: '<S97>/rad -> deg'
                                        */
  real_T pitch_offset_Value;           /* Expression: 0.00
                                        * Referenced by: '<S7>/pitch_offset'
                                        */
  real_T InitialCondition_Value;       /* Expression: vinit
                                        * Referenced by: '<S92>/Initial Condition'
                                        */
  real_T Constant1_Value_mr;           /* Expression: 1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T FixPtUnitDelay1_X0_h;         /* Expression: vinit
                                        * Referenced by: '<S92>/FixPt Unit Delay1'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T pitch_cmd2pitch_Gain;         /* Expression: pitch_cmd2pitch_1stOrd
                                        * Referenced by: '<S7>/pitch_cmd2pitch'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: -1.0
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
                                        * Referenced by: '<S93>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength;  /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S93>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength;  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S93>/Integer Delay2'
                                        */
  uint32_T IntegerDelay3_DelayLength_o;/* Computed Parameter: IntegerDelay3_DelayLength_o
                                        * Referenced by: '<S93>/Integer Delay3'
                                        */
  uint8_T FixPtUnitDelay2_X0;          /* Computed Parameter: FixPtUnitDelay2_X0
                                        * Referenced by: '<S64>/FixPt Unit Delay2'
                                        */
  uint8_T Constant_Value_lw;           /* Expression: uint8(1)
                                        * Referenced by: '<S32>/Constant'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(0)
                                        * Referenced by: '<S32>/SwitchControl'
                                        */
  uint8_T Constant_Value_j;            /* Expression: uint8(1)
                                        * Referenced by: '<S33>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_a;   /* Expression: uint8(0)
                                        * Referenced by: '<S33>/SwitchControl'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S64>/FixPt Constant'
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
                                        * Referenced by: '<S108>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_n;        /* Computed Parameter: FixPtUnitDelay2_X0_n
                                        * Referenced by: '<S111>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_do;       /* Computed Parameter: FixPtUnitDelay2_X0_do
                                        * Referenced by: '<S117>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_i;        /* Computed Parameter: FixPtUnitDelay2_X0_i
                                        * Referenced by: '<S114>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtConstant_Value_h;       /* Computed Parameter: FixPtConstant_Value_h
                                        * Referenced by: '<S108>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_o;       /* Computed Parameter: FixPtConstant_Value_o
                                        * Referenced by: '<S111>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_n;       /* Computed Parameter: FixPtConstant_Value_n
                                        * Referenced by: '<S114>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_p;       /* Computed Parameter: FixPtConstant_Value_p
                                        * Referenced by: '<S117>/FixPt Constant'
                                        */
  uint8_T FixPtUnitDelay2_X0_g;        /* Computed Parameter: FixPtUnitDelay2_X0_g
                                        * Referenced by: '<S92>/FixPt Unit Delay2'
                                        */
  uint8_T Constant_Value_he;           /* Expression: uint8(1)
                                        * Referenced by: '<S5>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_e;   /* Expression: uint8(1)
                                        * Referenced by: '<S5>/SwitchControl'
                                        */
  uint8_T Constant_Value_n;            /* Expression: uint8(1)
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_b;   /* Expression: uint8(1)
                                        * Referenced by: '<S4>/SwitchControl'
                                        */
  uint8_T Constant_Value_a3;           /* Expression: uint8(1)
                                        * Referenced by: '<S91>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_ef;  /* Expression: uint8(0)
                                        * Referenced by: '<S91>/SwitchControl'
                                        */
  uint8_T FixPtConstant_Value_i;       /* Computed Parameter: FixPtConstant_Value_i
                                        * Referenced by: '<S92>/FixPt Constant'
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
 * '<S23>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/demux'
 * '<S24>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S25>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S26>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S27>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S28>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S29>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight'
 * '<S30>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid'
 * '<S31>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Free Flight'
 * '<S32>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Manual Switch'
 * '<S33>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Manual Switch1'
 * '<S34>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Mean'
 * '<S35>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation'
 * '<S36>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/Ctrl_Xdir'
 * '<S37>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/PitchPropagateFF'
 * '<S38>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Free Flight/PitchPropagateFF/MATLAB Function'
 * '<S39>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/Ctrl_Xdir'
 * '<S40>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/PitchPropagate'
 * '<S41>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl Hybrid/PitchPropagate/MATLAB Function'
 * '<S42>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation/MATLAB Function'
 * '<S43>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation/Slider Gain'
 * '<S44>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Wall Deviation/Slider Gain2'
 * '<S45>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1'
 * '<S46>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Mean'
 * '<S47>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Slider Gain'
 * '<S48>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Slider Gain1'
 * '<S49>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S50>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate'
 * '<S51>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/RollPropagate/MATLAB Function'
 * '<S52>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1'
 * '<S53>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/MATLAB Function'
 * '<S54>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/MATLAB Function1'
 * '<S55>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Mean'
 * '<S56>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain'
 * '<S57>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain1'
 * '<S58>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain2'
 * '<S59>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Slider Gain3'
 * '<S60>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S61>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate'
 * '<S62>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/YawPropagate/MATLAB Function'
 * '<S63>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/MATLAB Function'
 * '<S64>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S65>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S66>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1'
 * '<S67>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Mean'
 * '<S68>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S69>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference'
 * '<S70>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Next Ref'
 * '<S71>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Slider Gain'
 * '<S72>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation'
 * '<S73>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1'
 * '<S74>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/get ref from vector1'
 * '<S75>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation/MATLAB Function'
 * '<S76>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation/Slider Gain'
 * '<S77>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation/Slider Gain2'
 * '<S78>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_x'
 * '<S79>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_y'
 * '<S80>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_yaw'
 * '<S81>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_z'
 * '<S82>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling '
 * '<S83>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame'
 * '<S84>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S85>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation'
 * '<S86>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation/MATLAB Function'
 * '<S87>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation/Slider Gain'
 * '<S88>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation/Slider Gain2'
 * '<S89>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S90>'  : 'controller_template/FreeFlight Pos Ctrl/rotate to world frame/Embedded MATLAB Function'
 * '<S91>'  : 'controller_template/convert2cmd/Manual Switch'
 * '<S92>'  : 'controller_template/delay/delay bias'
 * '<S93>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1'
 * '<S94>'  : 'controller_template/pos controller/decoupling and rotation'
 * '<S95>'  : 'controller_template/pos controller/get ref from vector'
 * '<S96>'  : 'controller_template/pos controller/rotate to world frame'
 * '<S97>'  : 'controller_template/pos controller/view & log signals'
 * '<S98>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/demux'
 * '<S99>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S100>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias'
 * '<S101>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S102>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias'
 * '<S103>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S104>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S105>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S106>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias'
 * '<S107>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  /runFastGradient'
 * '<S108>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/Unit Delay External IC1'
 * '<S109>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/discrete kalman filter'
 * '<S110>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG/runFastGradient'
 * '<S111>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/Unit Delay External IC1'
 * '<S112>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/discrete kalman filter'
 * '<S113>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG/runFastGradient'
 * '<S114>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S115>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S116>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG/runFastGradient'
 * '<S117>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/Unit Delay External IC1'
 * '<S118>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/discrete kalman filter'
 * '<S119>' : 'controller_template/pos controller/decoupling and rotation/decoupling '
 * '<S120>' : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame'
 * '<S121>' : 'controller_template/pos controller/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S122>' : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S123>' : 'controller_template/pos controller/rotate to world frame/Embedded MATLAB Function'
 */
#endif                                 /* RTW_HEADER_controller_template_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
