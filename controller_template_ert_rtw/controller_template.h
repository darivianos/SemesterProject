/*
 * File: controller_template.h
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.684
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Aug  6 2011)
 * C/C++ source code generated on : Sun Sep  1 19:36:40 2013
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

/* Block signals for system '<S41>/MATLAB Function' */
typedef struct {
  real_T y;                            /* '<S41>/MATLAB Function' */
} rtB_MATLABFunction_controller_t;

/* Block states (auto storage) for system '<S41>/MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S41>/MATLAB Function' */
  uint8_T is_active_c40_controller_templa;/* '<S41>/MATLAB Function' */
  boolean_T isStable;                  /* '<S41>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S41>/MATLAB Function' */
} rtDW_MATLABFunction_controller_;

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

/* Block signals for system '<S123>/runFastGradient' */
typedef struct {
  real_T u_opt;                        /* '<S123>/runFastGradient' */
  real_T J_star;                       /* '<S123>/runFastGradient' */
  real_T u_buff_out[3];                /* '<S123>/runFastGradient' */
  real_T V_init_out[30];               /* '<S123>/runFastGradient' */
} rtB_runFastGradient_controller_;

/* Block states (auto storage) for system '<S123>/runFastGradient' */
typedef struct {
  int32_T sfEvent;                     /* '<S123>/runFastGradient' */
  uint8_T is_active_c6_Hquad_control_LIB_;/* '<S123>/runFastGradient' */
  boolean_T isStable;                  /* '<S123>/runFastGradient' */
  boolean_T doneDoubleBufferReInit;    /* '<S123>/runFastGradient' */
} rtDW_runFastGradient_controller;

/* Block signals for system '<S124>/discrete kalman filter' */
typedef struct {
  real_T state_est[4];                 /* '<S124>/discrete kalman filter' */
  real_T P_est[16];                    /* '<S124>/discrete kalman filter' */
} rtB_discretekalmanfilter_cont_h;

/* Block states (auto storage) for system '<S124>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S124>/discrete kalman filter' */
  uint8_T is_active_c11_Hquad_control_LIB;/* '<S124>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S124>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S124>/discrete kalman filter' */
} rtDW_discretekalmanfilter_con_c;

/* Block signals (auto storage) */
typedef struct {
  real_T DataTypeConversion[30];       /* '<S1>/Data Type Conversion' */
  real_T X_ref_x[93];                  /* '<Root>/Data Type Conversion2' */
  real_T X_ref_y[93];                  /* '<Root>/Data Type Conversion3' */
  real_T X_ref_z[62];                  /* '<Root>/Data Type Conversion1' */
  real_T X_ref_yaw[62];                /* '<Root>/Data Type Conversion' */
  real_T MultiportSwitch;              /* '<S6>/Multiport Switch' */
  real_T pitch_cmd;                    /* '<Root>/Switch1' */
  real_T roll_cmd;                     /* '<Root>/Switch1' */
  real_T SliderGain;                   /* '<S112>/Slider Gain' */
  real_T thrust_cmd;                   /* '<Root>/Switch1' */
  real_T yaw_rate_cmd;                 /* '<Root>/Switch1' */
  real_T pitch_bias;                   /* '<Root>/Switch1' */
  real_T roll_bias;                    /* '<Root>/Switch1' */
  real_T thrust_bias;                  /* '<Root>/Switch1' */
  real_T yaw_rate_bias;                /* '<Root>/Switch1' */
  real_T Gain[4];                      /* '<S121>/Gain' */
  real_T raddeg2[3];                   /* '<S121>/rad -> deg2' */
  real_T raddeg1[3];                   /* '<S121>/rad -> deg1' */
  real_T raddeg3[3];                   /* '<S121>/rad -> deg3' */
  real_T raddeg[4];                    /* '<S121>/rad -> deg' */
  real_T bias_W[4];                    /* '<S118>/bias_W' */
  real_T cmd_W[4];                     /* '<S118>/cmd_W' */
  real_T pitch_rot;                    /* '<S144>/Embedded MATLAB Function' */
  real_T roll_rot;                     /* '<S144>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S144>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S144>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp;               /* '<S143>/Embedded MATLAB Function' */
  real_T roll_cmd_comp;                /* '<S143>/Embedded MATLAB Function' */
  real_T thrust_comp;                  /* '<S143>/Embedded MATLAB Function' */
  real_T thrust_cmd_e;                 /* '<S117>/Sum5' */
  real_T u_opt;                        /* '<S129>/runFastGradient' */
  real_T J_star;                       /* '<S129>/runFastGradient' */
  real_T u_buff_out[2];                /* '<S129>/runFastGradient' */
  real_T V_init_out[30];               /* '<S129>/runFastGradient' */
  real_T u_opt_l;                      /* '<S127>/runFastGradient' */
  real_T J_star_h;                     /* '<S127>/runFastGradient' */
  real_T u_buff_out_i[6];              /* '<S127>/runFastGradient' */
  real_T V_init_out_n[30];             /* '<S127>/runFastGradient' */
  real_T Switch1;                      /* '<S81>/Switch1' */
  real_T Switch;                       /* '<S81>/Switch' */
  real_T UnitDelay1;                   /* '<S77>/Unit Delay1' */
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
  real_T Sum[2];                       /* '<S77>/Sum' */
  real_T Gain_k[2];                    /* '<S77>/Gain' */
  real_T bias_W_b[4];                  /* '<S14>/bias_W' */
  real_T cmd_W_h[4];                   /* '<S14>/cmd_W' */
  real_T pitch_rot_n;                  /* '<S103>/Embedded MATLAB Function' */
  real_T roll_rot_e;                   /* '<S103>/Embedded MATLAB Function' */
  real_T pitch_bias_rot_i;             /* '<S103>/Embedded MATLAB Function' */
  real_T roll_bias_rot_d;              /* '<S103>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp_n;             /* '<S102>/Embedded MATLAB Function' */
  real_T roll_cmd_comp_j;              /* '<S102>/Embedded MATLAB Function' */
  real_T thrust_comp_k;                /* '<S102>/Embedded MATLAB Function' */
  real_T nominal_window_z_out;         /* '<S81>/MATLAB Function' */
  real_T nominal_window_y_out;         /* '<S81>/MATLAB Function' */
  real_T count_out;                    /* '<S80>/MATLAB Function' */
  real_T en;                           /* '<S77>/Next Ref' */
  real_T Gain2;                        /* '<S27>/Gain2' */
  real_T SwitchControl;                /* '<S35>/SwitchControl' */
  real_T y_f;                          /* '<S25>/Saturation5' */
  real_T RateTransition[4];            /* '<S33>/Rate Transition' */
  real_T Gain_c;                       /* '<S36>/Gain' */
  real_T Sum_e;                        /* '<S23>/Sum' */
  real_T Gain_n;                       /* '<S37>/Gain' */
  real_T Saturation1;                  /* '<S28>/Saturation1' */
  real_T RateTransition_j[3];          /* '<S66>/Rate Transition' */
  real_T Gain_i;                       /* '<S67>/Gain' */
  real_T Sum_b;                        /* '<S26>/Sum' */
  real_T Gain_nc;                      /* '<S55>/Gain' */
  real_T thrust_cmd_a;                 /* '<S11>/Sum5' */
  real_T Gain_g;                       /* '<S26>/Gain' */
  real_T Gain1;                        /* '<S27>/Gain1' */
  real_T Gain_d;                       /* '<S27>/Gain' */
  real_T y;                            /* '<S70>/MATLAB Function' */
  real_T u_thrust_out;                 /* '<S69>/MATLAB Function' */
  real_T U;                            /* '<S66>/Ctrl_Xdir' */
  real_T flag_oob;                     /* '<S66>/Ctrl_Xdir' */
  real_T psi_prime;                    /* '<S27>/MATLAB Function' */
  real_T psi_out;                      /* '<S26>/MATLAB Function1' */
  real_T delta_x;                      /* '<S26>/MATLAB Function1' */
  real_T psi_prime_l;                  /* '<S26>/MATLAB Function' */
  real_T y_e;                          /* '<S61>/MATLAB Function' */
  real_T U_g;                          /* '<S52>/Ctrl_Xdir' */
  real_T flag_oob_l;                   /* '<S52>/Ctrl_Xdir' */
  real_T U_x_out;                      /* '<S45>/MATLAB Function1' */
  real_T U_x;                          /* '<S42>/MATLAB Function' */
  real_T U_y;                          /* '<S42>/MATLAB Function' */
  real_T flag_oob_j;                   /* '<S42>/MATLAB Function' */
  real_T M;                            /* '<S42>/MATLAB Function' */
  real_T pitch_cmd_out;                /* '<S23>/MATLAB Function' */
  rtB_EmbeddedMATLABFunction_cont sf_EmbeddedMATLABFunction_o;/* '<S120>/Embedded MATLAB Function' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_k;/* '<S130>/discrete kalman filter' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_n;/* '<S128>/discrete kalman filter' */
  rtB_discretekalmanfilter_cont_h sf_discretekalmanfilter_m;/* '<S126>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient_d;/* '<S125>/runFastGradient' */
  rtB_discretekalmanfilter_cont_h sf_discretekalmanfilter_b;/* '<S124>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient;/* '<S123>/runFastGradient' */
  rtB_EmbeddedMATLABFunction_cont sf_EmbeddedMATLABFunction;/* '<S15>/Embedded MATLAB Function' */
  rtB_MATLABFunction_controller_t sf_MATLABFunction_p;/* '<S105>/MATLAB Function' */
  rtB_generate_X_ref_z_controller sf_generate_X_ref_z;/* '<S85>/generate_X_ref_z' */
  rtB_generate_X_ref_yaw_controll sf_generate_X_ref_yaw;/* '<S85>/generate_X_ref_yaw' */
  rtB_generate_X_ref_y_controller sf_generate_X_ref_y;/* '<S85>/generate_X_ref_y' */
  rtB_generate_X_ref_x_controller sf_generate_X_ref_x;/* '<S85>/generate_X_ref_x' */
  rtB_MATLABFunction_controller_t sf_MATLABFunction;/* '<S84>/MATLAB Function' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter;/* '<S27>/discrete kalman filter' */
  rtB_MATLABFunction_controller_t sf_MATLABFunction_e;/* '<S41>/MATLAB Function' */
  rtB_generate_X_ref_z_controller sf_generate_X_ref_z_l;/* '<S17>/generate_X_ref_z' */
  rtB_generate_X_ref_yaw_controll sf_generate_X_ref_yaw_g;/* '<S17>/generate_X_ref_yaw' */
  rtB_generate_X_ref_y_controller sf_generate_X_ref_y_a;/* '<S17>/generate_X_ref_y' */
  rtB_generate_X_ref_x_controller sf_generate_X_ref_x_k;/* '<S17>/generate_X_ref_x' */
} BlockIO_controller_template;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T FixPtUnitDelay1_DSTATE[4];    /* '<S116>/FixPt Unit Delay1' */
  real_T IntegerDelay_DSTATE;          /* '<S117>/Integer Delay' */
  real_T IntegerDelay1_DSTATE;         /* '<S117>/Integer Delay1' */
  real_T IntegerDelay2_DSTATE;         /* '<S117>/Integer Delay2' */
  real_T IntegerDelay3_DSTATE;         /* '<S117>/Integer Delay3' */
  real_T UnitDelay1_DSTATE[16];        /* '<S124>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i[3];  /* '<S132>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE[3];          /* '<S123>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c[30];      /* '<S123>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_b[16];      /* '<S126>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_g[3];  /* '<S135>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_j[3];        /* '<S125>/Unit Delay' */
  real_T UnitDelay1_DSTATE_l[30];      /* '<S125>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_j[9];       /* '<S130>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_d[2];  /* '<S141>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_l[2];        /* '<S129>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g[30];      /* '<S129>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_lx[9];      /* '<S128>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_e[2];  /* '<S138>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_jz[6];       /* '<S127>/Unit Delay' */
  real_T UnitDelay1_DSTATE_js[30];     /* '<S127>/Unit Delay1' */
  real_T UnitDelay_2_DSTATE;           /* '<S77>/Unit Delay' */
  real_T UnitDelay_3_DSTATE;           /* '<S77>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S77>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g;           /* '<S85>/Unit Delay' */
  real_T UnitDelay_DSTATE_e;           /* '<S17>/Unit Delay' */
  real_T UnitDelay_DSTATE_es;          /* '<S80>/Unit Delay' */
  real_T UnitDelay1_DSTATE_o;          /* '<S80>/Unit Delay1' */
  real_T IntegerDelay3_DSTATE_k;       /* '<S11>/Integer Delay3' */
  real_T UnitDelay1_DSTATE_bg[9];      /* '<S27>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i1[2]; /* '<S64>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_a[2];        /* '<S42>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b1;         /* '<S42>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S36>/Unit Delay2' */
  real_T UnitDelay_DSTATE_d;           /* '<S36>/Unit Delay' */
  real_T UnitDelay2_DSTATE_n;          /* '<S37>/Unit Delay2' */
  real_T UnitDelay_DSTATE_n;           /* '<S37>/Unit Delay' */
  real_T UnitDelay2_DSTATE_b;          /* '<S67>/Unit Delay2' */
  real_T UnitDelay_DSTATE_f;           /* '<S67>/Unit Delay' */
  real_T UnitDelay_DSTATE_lg;          /* '<S26>/Unit Delay' */
  real_T UnitDelay2_DSTATE_g;          /* '<S52>/Unit Delay2' */
  real_T UnitDelay2_DSTATE_ga;         /* '<S55>/Unit Delay2' */
  real_T UnitDelay_DSTATE_p;           /* '<S55>/Unit Delay' */
  real_T UnitDelay1_DSTATE_h;          /* '<S36>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_a;          /* '<S37>/Unit Delay1' */
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
  } ToFile_PWORK;                      /* '<S121>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<S121>/To File1' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<S121>/To Workspace' */

  struct {
    void *LoggedData;
  } pitchcmd_PWORK;                    /* '<S121>/pitch cmd' */

  struct {
    void *LoggedData;
  } rollcmd_PWORK;                     /* '<S121>/roll cmd' */

  struct {
    void *LoggedData;
  } thrustcmd_PWORK;                   /* '<S121>/thrust cmd' */

  struct {
    void *LoggedData;
  } x_ref_PWORK;                       /* '<S121>/x_ref' */

  struct {
    void *LoggedData;
  } y_ref_PWORK;                       /* '<S121>/y_ref' */

  struct {
    void *LoggedData;
  } yawcmd_PWORK;                      /* '<S121>/yaw cmd' */

  struct {
    void *LoggedData;
  } yaw_ref_PWORK;                     /* '<S121>/yaw_ref' */

  struct {
    void *LoggedData;
  } z_ref_PWORK;                       /* '<S121>/z_ref' */

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
  } Scope_PWORK;                       /* '<S77>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_p;                     /* '<S81>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_i;                     /* '<S11>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S11>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     /* '<S23>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_e;                    /* '<S25>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S25>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_c;                     /* '<S42>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_k;                    /* '<S42>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_n;                    /* '<S42>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<S26>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_c;                    /* '<S26>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_e;                     /* '<S27>/Scope' */

  int32_T sfEvent;                     /* '<S144>/Embedded MATLAB Function' */
  int32_T sfEvent_f;                   /* '<S143>/Embedded MATLAB Function' */
  int32_T sfEvent_k;                   /* '<S129>/runFastGradient' */
  int32_T sfEvent_n;                   /* '<S127>/runFastGradient' */
  int32_T sfEvent_j;                   /* '<S103>/Embedded MATLAB Function' */
  int32_T sfEvent_c;                   /* '<S102>/Embedded MATLAB Function' */
  int32_T sfEvent_a;                   /* '<S81>/MATLAB Function' */
  int32_T sfEvent_jg;                  /* '<S80>/MATLAB Function' */
  int32_T sfEvent_p;                   /* '<S77>/Next Ref' */
  int32_T sfEvent_i;                   /* '<S70>/MATLAB Function' */
  int32_T sfEvent_jj;                  /* '<S69>/MATLAB Function' */
  int32_T sfEvent_k0;                  /* '<S66>/Ctrl_Xdir' */
  int32_T sfEvent_ks;                  /* '<S27>/MATLAB Function' */
  int32_T sfEvent_d;                   /* '<S26>/MATLAB Function1' */
  int32_T sfEvent_g;                   /* '<S26>/MATLAB Function' */
  int32_T sfEvent_l;                   /* '<S61>/MATLAB Function' */
  int32_T sfEvent_jv;                  /* '<S52>/Ctrl_Xdir' */
  int32_T sfEvent_fj;                  /* '<S45>/MATLAB Function1' */
  int32_T sfEvent_cv;                  /* '<S42>/MATLAB Function' */
  int32_T sfEvent_fp;                  /* '<S23>/MATLAB Function' */
  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<S121>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<S121>/To File1' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK_g;                    /* '<S16>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK_p;                   /* '<S16>/To File1' */

  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S116>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_l;    /* '<S132>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_b;    /* '<S135>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S141>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S138>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_g;    /* '<S64>/FixPt Unit Delay2' */
  int8_T FreeFlightPosCtrl_SubsysRanBC;/* '<Root>/FreeFlight Pos Ctrl' */
  int8_T poscontroller_SubsysRanBC;    /* '<Root>/pos controller' */
  uint8_T is_active_c4_Hquad_control_LIB_;/* '<S144>/Embedded MATLAB Function' */
  uint8_T is_active_c1_Hquad_control_LIB_;/* '<S143>/Embedded MATLAB Function' */
  uint8_T is_active_c8_Hquad_control_LIB_;/* '<S129>/runFastGradient' */
  uint8_T is_active_c9_Hquad_control_LIB_;/* '<S127>/runFastGradient' */
  uint8_T is_active_c10_controller_templa;/* '<S103>/Embedded MATLAB Function' */
  uint8_T is_active_c9_controller_templat;/* '<S102>/Embedded MATLAB Function' */
  uint8_T is_active_c18_controller_templa;/* '<S81>/MATLAB Function' */
  uint8_T is_active_c11_controller_templa;/* '<S80>/MATLAB Function' */
  uint8_T is_active_c35_controller_templa;/* '<S77>/Next Ref' */
  uint8_T is_active_c14_controller_templa;/* '<S70>/MATLAB Function' */
  uint8_T is_active_c16_controller_templa;/* '<S69>/MATLAB Function' */
  uint8_T is_active_c3_controller_templat;/* '<S66>/Ctrl_Xdir' */
  uint8_T is_active_c28_controller_templa;/* '<S27>/MATLAB Function' */
  uint8_T is_active_c30_controller_templa;/* '<S26>/MATLAB Function1' */
  uint8_T is_active_c25_controller_templa;/* '<S26>/MATLAB Function' */
  uint8_T is_active_c6_controller_templat;/* '<S61>/MATLAB Function' */
  uint8_T is_active_c4_controller_templat;/* '<S52>/Ctrl_Xdir' */
  uint8_T is_active_c2_controller_templat;/* '<S45>/MATLAB Function1' */
  uint8_T is_active_c44_controller_templa;/* '<S42>/MATLAB Function' */
  uint8_T is_active_c12_controller_templa;/* '<S23>/MATLAB Function' */
  boolean_T isStable;                  /* '<S144>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S144>/Embedded MATLAB Function' */
  boolean_T isStable_m;                /* '<S143>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S143>/Embedded MATLAB Function' */
  boolean_T isStable_i;                /* '<S129>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_h;  /* '<S129>/runFastGradient' */
  boolean_T isStable_h;                /* '<S127>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_o;  /* '<S127>/runFastGradient' */
  boolean_T isStable_o;                /* '<S103>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S103>/Embedded MATLAB Function' */
  boolean_T isStable_mf;               /* '<S102>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_a;  /* '<S102>/Embedded MATLAB Function' */
  boolean_T isStable_g;                /* '<S81>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_ek; /* '<S81>/MATLAB Function' */
  boolean_T isStable_j;                /* '<S80>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_p;  /* '<S80>/MATLAB Function' */
  boolean_T isStable_od;               /* '<S77>/Next Ref' */
  boolean_T doneDoubleBufferReInit_em; /* '<S77>/Next Ref' */
  boolean_T isStable_ib;               /* '<S70>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_ou; /* '<S70>/MATLAB Function' */
  boolean_T isStable_g4;               /* '<S69>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_n;  /* '<S69>/MATLAB Function' */
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
  boolean_T doneDoubleBufferReInit_pw; /* '<S52>/Ctrl_Xdir' */
  boolean_T isStable_ht;               /* '<S45>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_i;  /* '<S45>/MATLAB Function1' */
  boolean_T isStable_b;                /* '<S42>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_ma; /* '<S42>/MATLAB Function' */
  boolean_T isStable_d;                /* '<S23>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_hm; /* '<S23>/MATLAB Function' */
  boolean_T FreeFlightPosCtrl_MODE;    /* '<Root>/FreeFlight Pos Ctrl' */
  boolean_T poscontroller_MODE;        /* '<Root>/pos controller' */
  rtDW_EmbeddedMATLABFunction_con sf_EmbeddedMATLABFunction_o;/* '<S120>/Embedded MATLAB Function' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_k;/* '<S130>/discrete kalman filter' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_n;/* '<S128>/discrete kalman filter' */
  rtDW_discretekalmanfilter_con_c sf_discretekalmanfilter_m;/* '<S126>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient_d;/* '<S125>/runFastGradient' */
  rtDW_discretekalmanfilter_con_c sf_discretekalmanfilter_b;/* '<S124>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient;/* '<S123>/runFastGradient' */
  rtDW_EmbeddedMATLABFunction_con sf_EmbeddedMATLABFunction;/* '<S15>/Embedded MATLAB Function' */
  rtDW_MATLABFunction_controller_ sf_MATLABFunction_p;/* '<S105>/MATLAB Function' */
  rtDW_generate_X_ref_z_controlle sf_generate_X_ref_z;/* '<S85>/generate_X_ref_z' */
  rtDW_generate_X_ref_yaw_control sf_generate_X_ref_yaw;/* '<S85>/generate_X_ref_yaw' */
  rtDW_generate_X_ref_y_controlle sf_generate_X_ref_y;/* '<S85>/generate_X_ref_y' */
  rtDW_generate_X_ref_x_controlle sf_generate_X_ref_x;/* '<S85>/generate_X_ref_x' */
  rtDW_MATLABFunction_controller_ sf_MATLABFunction;/* '<S84>/MATLAB Function' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter;/* '<S27>/discrete kalman filter' */
  rtDW_MATLABFunction_controller_ sf_MATLABFunction_e;/* '<S41>/MATLAB Function' */
  rtDW_generate_X_ref_z_controlle sf_generate_X_ref_z_l;/* '<S17>/generate_X_ref_z' */
  rtDW_generate_X_ref_yaw_control sf_generate_X_ref_yaw_g;/* '<S17>/generate_X_ref_yaw' */
  rtDW_generate_X_ref_y_controlle sf_generate_X_ref_y_a;/* '<S17>/generate_X_ref_y' */
  rtDW_generate_X_ref_x_controlle sf_generate_X_ref_x_k;/* '<S17>/generate_X_ref_x' */
} D_Work_controller_template;

/* Parameters (auto storage) */
struct Parameters_controller_template_ {
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S34>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S34>/Saturation3'
                                        */
  real_T Saturation3_UpperSat_k;       /* Expression: 0
                                        * Referenced by: '<S41>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_h;       /* Expression: -3
                                        * Referenced by: '<S41>/Saturation3'
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
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * Referenced by: '<S32>/Slider Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.017453292519943
                                        * Referenced by: '<S23>/Gain1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S41>/Constant'
                                        */
  real_T SliderGain_Gain_k;            /* Expression: gain
                                        * Referenced by: '<S50>/Slider Gain'
                                        */
  real_T Constant1_Value_c;            /* Expression: 1
                                        * Referenced by: '<S41>/Constant1'
                                        */
  real_T SliderGain_Gain_ko;           /* Expression: gain
                                        * Referenced by: '<S51>/Slider Gain'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S25>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S25>/Saturation2'
                                        */
  real_T SliderGain_Gain_e;            /* Expression: gain
                                        * Referenced by: '<S39>/Slider Gain'
                                        */
  real_T Constant_Value_e;             /* Expression: 1
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T SliderGain_Gain_a;            /* Expression: gain
                                        * Referenced by: '<S38>/Slider Gain'
                                        */
  real_T SliderGain_Gain_p;            /* Expression: gain
                                        * Referenced by: '<S40>/Slider Gain'
                                        */
  real_T Saturation5_UpperSat;         /* Expression: 3
                                        * Referenced by: '<S25>/Saturation5'
                                        */
  real_T Saturation5_LowerSat;         /* Expression: -3
                                        * Referenced by: '<S25>/Saturation5'
                                        */
  real_T Saturation3_UpperSat_b;       /* Expression: 1
                                        * Referenced by: '<S25>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_g;       /* Expression: -1
                                        * Referenced by: '<S25>/Saturation3'
                                        */
  real_T UnitDelay_X0;                 /* Expression: 0
                                        * Referenced by: '<S42>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_l;              /* Expression: 2
                                        * Referenced by: '<S42>/Unit Delay1'
                                        */
  real_T Constant3_Value;              /* Expression: XYctrl.nx
                                        * Referenced by: '<S42>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: XYctrl.nu
                                        * Referenced by: '<S42>/Constant4'
                                        */
  real_T Constant5_Value[75996];       /* Expression: XYctrl.H
                                        * Referenced by: '<S42>/Constant5'
                                        */
  real_T Constant6_Value[18999];       /* Expression: XYctrl.K
                                        * Referenced by: '<S42>/Constant6'
                                        */
  real_T Constant7_Value[36848];       /* Expression: XYctrl.Hobj
                                        * Referenced by: '<S42>/Constant7'
                                        */
  real_T Constant8_Value[9212];        /* Expression: XYctrl.Fobj
                                        * Referenced by: '<S42>/Constant8'
                                        */
  real_T Constant9_Value[2303];        /* Expression: XYctrl.Gobj
                                        * Referenced by: '<S42>/Constant9'
                                        */
  real_T Constant10_Value[18424];      /* Expression: XYctrl.F
                                        * Referenced by: '<S42>/Constant10'
                                        */
  real_T Constant11_Value[4606];       /* Expression: XYctrl.G
                                        * Referenced by: '<S42>/Constant11'
                                        */
  real_T Constant12_Value[2303];       /* Expression: XYctrl.Nc
                                        * Referenced by: '<S42>/Constant12'
                                        */
  real_T Constant14_Value[16];         /* Expression: XYctrl.Qopt
                                        * Referenced by: '<S42>/Constant14'
                                        */
  real_T Constant15_Value[4];          /* Expression: XYctrl.Ropt
                                        * Referenced by: '<S42>/Constant15'
                                        */
  real_T Constant16_Value[60];         /* Expression: XYctrl.Ml
                                        * Referenced by: '<S42>/Constant16'
                                        */
  real_T Constant17_Value[10];         /* Expression: XYctrl.Mr
                                        * Referenced by: '<S42>/Constant17'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<S42>/Constant'
                                        */
  real_T SliderGain_Gain_eo;           /* Expression: gain
                                        * Referenced by: '<S44>/Slider Gain'
                                        */
  real_T Saturation4_UpperSat;         /* Expression: 0.2094
                                        * Referenced by: '<S25>/Saturation4'
                                        */
  real_T Saturation4_LowerSat;         /* Expression: -0.2094
                                        * Referenced by: '<S25>/Saturation4'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S36>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_h;               /* Expression: 0
                                        * Referenced by: '<S36>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: .33333
                                        * Referenced by: '<S36>/Gain'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T SliderGain_Gain_g;            /* Expression: gain
                                        * Referenced by: '<S30>/Slider Gain'
                                        */
  real_T SliderGain_Gain_b;            /* Expression: gain
                                        * Referenced by: '<S31>/Slider Gain'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 0.017453292519943
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Saturation6_UpperSat;         /* Expression: 0.2094
                                        * Referenced by: '<S25>/Saturation6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: -0.2094
                                        * Referenced by: '<S25>/Saturation6'
                                        */
  real_T UnitDelay2_X0_b;              /* Expression: 0
                                        * Referenced by: '<S37>/Unit Delay2'
                                        */
  real_T UnitDelay_X0_m;               /* Expression: 0
                                        * Referenced by: '<S37>/Unit Delay'
                                        */
  real_T Gain_Gain_e;                  /* Expression: .33333
                                        * Referenced by: '<S37>/Gain'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S28>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S28>/Saturation1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1
                                        * Referenced by: '<S28>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -1
                                        * Referenced by: '<S28>/Saturation'
                                        */
  real_T Constant_Value_fz;            /* Expression: 1
                                        * Referenced by: '<S70>/Constant'
                                        */
  real_T SliderGain_Gain_d;            /* Expression: gain
                                        * Referenced by: '<S75>/Slider Gain'
                                        */
  real_T Constant1_Value_l;            /* Expression: 1
                                        * Referenced by: '<S70>/Constant1'
                                        */
  real_T SliderGain_Gain_ds;           /* Expression: gain
                                        * Referenced by: '<S76>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_n;       /* Expression: .1
                                        * Referenced by: '<S70>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_e;       /* Expression: -1
                                        * Referenced by: '<S70>/Saturation3'
                                        */
  real_T Constant_Value_b[624];        /* Expression: Hn_Zdir
                                        * Referenced by: '<S66>/Constant'
                                        */
  real_T Constant1_Value_li[208];      /* Expression: Kn_Zdir
                                        * Referenced by: '<S66>/Constant1'
                                        */
  real_T Constant2_Value[90];          /* Expression: Fi_Zdir
                                        * Referenced by: '<S66>/Constant2'
                                        */
  real_T Constant3_Value_m[30];        /* Expression: Gi_Zdir
                                        * Referenced by: '<S66>/Constant3'
                                        */
  real_T Constant4_Value_a[30];        /* Expression: Nc_Zdir
                                        * Referenced by: '<S66>/Constant4'
                                        */
  real_T Constant_Value_n;             /* Expression: 1
                                        * Referenced by: '<S69>/Constant'
                                        */
  real_T SliderGain_Gain_m;            /* Expression: gain
                                        * Referenced by: '<S73>/Slider Gain'
                                        */
  real_T SliderGain_Gain_c;            /* Expression: gain
                                        * Referenced by: '<S68>/Slider Gain'
                                        */
  real_T Saturation2_UpperSat_k;       /* Expression: 1
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
  real_T UnitDelay_X0_m5;              /* Expression: 0
                                        * Referenced by: '<S26>/Unit Delay'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T SliderGain_Gain_ai;           /* Expression: gain
                                        * Referenced by: '<S58>/Slider Gain'
                                        */
  real_T Constant2_Value_l;            /* Expression: 1
                                        * Referenced by: '<S26>/Constant2'
                                        */
  real_T SliderGain_Gain_pq;           /* Expression: gain
                                        * Referenced by: '<S59>/Slider Gain'
                                        */
  real_T SliderGain_Gain_aiz;          /* Expression: gain
                                        * Referenced by: '<S57>/Slider Gain'
                                        */
  real_T Constant_Value_fv;            /* Expression: 1
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
  real_T UnitDelay2_X0_n;              /* Expression: 0
                                        * Referenced by: '<S52>/Unit Delay2'
                                        */
  real_T Constant_Value_a[6];          /* Expression: Hn_Yaw
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T Constant1_Value_g[6];         /* Expression: Kn_Yaw
                                        * Referenced by: '<S52>/Constant1'
                                        */
  real_T Constant2_Value_j[3];         /* Expression: Fi_Yaw
                                        * Referenced by: '<S52>/Constant2'
                                        */
  real_T Constant3_Value_b[3];         /* Expression: Gi_Yaw
                                        * Referenced by: '<S52>/Constant3'
                                        */
  real_T Constant4_Value_g[3];         /* Expression: Nc_Yaw
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
  real_T UnitDelay1_X0_le;             /* Expression: 0
                                        * Referenced by: '<S36>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_j;              /* Expression: 0
                                        * Referenced by: '<S37>/Unit Delay1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 57
                                        * Referenced by: '<S26>/Gain'
                                        */
  real_T UnitDelay1_X0_jm;             /* Expression: 0
                                        * Referenced by: '<S55>/Unit Delay1'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 57
                                        * Referenced by: '<S27>/Gain1'
                                        */
  real_T Gain_Gain_ep;                 /* Expression: 57
                                        * Referenced by: '<S27>/Gain'
                                        */
  real_T UnitDelay1_X0_f;              /* Expression: 0
                                        * Referenced by: '<S67>/Unit Delay1'
                                        */
  real_T g_Value;                      /* Expression: g
                                        * Referenced by: '<S102>/g'
                                        */
  real_T Constant_Value_k;             /* Expression: 1
                                        * Referenced by: '<S105>/Constant'
                                        */
  real_T SliderGain_Gain_n;            /* Expression: gain
                                        * Referenced by: '<S107>/Slider Gain'
                                        */
  real_T Constant1_Value_i;            /* Expression: 1
                                        * Referenced by: '<S105>/Constant1'
                                        */
  real_T SliderGain_Gain_i;            /* Expression: gain
                                        * Referenced by: '<S108>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_p;       /* Expression: 0
                                        * Referenced by: '<S105>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_es;      /* Expression: -1
                                        * Referenced by: '<S105>/Saturation3'
                                        */
  real_T X_ref_x_Value[909];           /* Expression: traj_FG.X_ref_x
                                        * Referenced by: '<S85>/X_ref_x'
                                        */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S84>/Constant'
                                        */
  real_T SliderGain_Gain_en;           /* Expression: gain
                                        * Referenced by: '<S96>/Slider Gain'
                                        */
  real_T Constant1_Value_e;            /* Expression: 1
                                        * Referenced by: '<S84>/Constant1'
                                        */
  real_T SliderGain_Gain_jr;           /* Expression: gain
                                        * Referenced by: '<S97>/Slider Gain'
                                        */
  real_T Saturation3_UpperSat_f;       /* Expression: 0
                                        * Referenced by: '<S84>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_l;       /* Expression: -1
                                        * Referenced by: '<S84>/Saturation3'
                                        */
  real_T UnitDelay_2_X0;               /* Expression: 0
                                        * Referenced by: '<S77>/Unit Delay'
                                        */
  real_T UnitDelay_3_X0;               /* Expression: 0
                                        * Referenced by: '<S77>/Unit Delay'
                                        */
  real_T Constant1_Value_j;            /* Expression: 1
                                        * Referenced by: '<S77>/Constant1'
                                        */
  real_T SliderGain_Gain_db;           /* Expression: gain
                                        * Referenced by: '<S83>/Slider Gain'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S77>/Constant'
                                        */
  real_T SliderGain_Gain_ne;           /* Expression: gain
                                        * Referenced by: '<S82>/Slider Gain'
                                        */
  real_T Constant_Value_kb;            /* Expression: 1
                                        * Referenced by: '<S81>/Constant'
                                        */
  real_T SliderGain_Gain_dsh;          /* Expression: gain
                                        * Referenced by: '<S90>/Slider Gain'
                                        */
  real_T SliderGain_Gain_cx;           /* Expression: gain
                                        * Referenced by: '<S91>/Slider Gain'
                                        */
  real_T Constant1_Value_kj;           /* Expression: 1
                                        * Referenced by: '<S81>/Constant1'
                                        */
  real_T SliderGain_Gain_mi;           /* Expression: gain
                                        * Referenced by: '<S92>/Slider Gain'
                                        */
  real_T Constant2_Value_c;            /* Expression: 1
                                        * Referenced by: '<S81>/Constant2'
                                        */
  real_T SliderGain_Gain_nu;           /* Expression: gain
                                        * Referenced by: '<S93>/Slider Gain'
                                        */
  real_T Constant3_Value_f;            /* Expression: 1
                                        * Referenced by: '<S81>/Constant3'
                                        */
  real_T SliderGain_Gain_ka;           /* Expression: gain
                                        * Referenced by: '<S94>/Slider Gain'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S81>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S81>/Switch'
                                        */
  real_T SliderGain_Gain_h;            /* Expression: gain
                                        * Referenced by: '<S79>/Slider Gain'
                                        */
  real_T TotalSamples_Value;           /* Expression: traj_FG.total_samples -1
                                        * Referenced by: '<S77>/Total Samples'
                                        */
  real_T UnitDelay1_X0_i;              /* Expression: 0
                                        * Referenced by: '<S77>/Unit Delay1'
                                        */
  real_T UnitDelay_X0_o;               /* Expression: 0
                                        * Referenced by: '<S85>/Unit Delay'
                                        */
  real_T total_samples_Value;          /* Expression: traj_FG.total_samples
                                        * Referenced by: '<S85>/total_samples'
                                        */
  real_T Constant1_Value_mu;           /* Expression: 1
                                        * Referenced by: '<S85>/Constant1'
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
                                        * Referenced by: '<S85>/X_ref_y'
                                        */
  real_T X_ref_y_Value_e[909];         /* Expression: traj_FG.X_ref_y
                                        * Referenced by: '<S17>/X_ref_y'
                                        */
  real_T X_ref_z_Value[606];           /* Expression: traj_FG.X_ref_z
                                        * Referenced by: '<S85>/X_ref_z'
                                        */
  real_T X_ref_z_Value_a[606];         /* Expression: traj_FG.X_ref_z
                                        * Referenced by: '<S17>/X_ref_z'
                                        */
  real_T X_ref_yaw_Value[606];         /* Expression: traj_FG.X_ref_yaw
                                        * Referenced by: '<S85>/X_ref_yaw'
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
                                        * Referenced by: '<S77>/Gain'
                                        */
  real_T UnitDelay_X0_l;               /* Expression: 0
                                        * Referenced by: '<S80>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_js;             /* Expression: 0
                                        * Referenced by: '<S80>/Unit Delay1'
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
                                        * Referenced by: '<S117>/Integer Delay'
                                        */
  real_T IntegerDelay1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S117>/Integer Delay1'
                                         */
  real_T IntegerDelay2_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S117>/Integer Delay2'
                                         */
  real_T IntegerDelay3_InitialConditio_c;/* Expression: 0.0
                                          * Referenced by: '<S117>/Integer Delay3'
                                          */
  real_T gravity_Value_j;              /* Expression: g
                                        * Referenced by: '<S117>/gravity'
                                        */
  real_T TT_PP_Value[900];             /* Expression: FG_ctrl_x.TT_PP
                                        * Referenced by: '<S123>/TT_PP'
                                        */
  real_T LL_PP_Value[90];              /* Expression: FG_ctrl_x.LL_PP
                                        * Referenced by: '<S123>/LL_PP'
                                        */
  real_T LL_ref_PP_Value[2790];        /* Expression: FG_ctrl_x.LL_ref_PP
                                        * Referenced by: '<S123>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value[900];       /* Expression: FG_ctrl_x.LL_U_ref_PP
                                        * Referenced by: '<S123>/LL_U_ref_PP'
                                        */
  real_T MM_Value[9];                  /* Expression: FG_ctrl_x.MM
                                        * Referenced by: '<S123>/MM'
                                        */
  real_T PP_Value[900];                /* Expression: FG_ctrl_x.PP
                                        * Referenced by: '<S123>/PP'
                                        */
  real_T AA_delay_Value[9];            /* Expression: FG_ctrl_x.AA_delay
                                        * Referenced by: '<S123>/AA_delay'
                                        */
  real_T BB_delay_Value[9];            /* Expression: FG_ctrl_x.BB_delay
                                        * Referenced by: '<S123>/BB_delay'
                                        */
  real_T A_Value_h[16];                /* Expression: kalm_mpc_x.A
                                        * Referenced by: '<S124>/A'
                                        */
  real_T B_Value_i[4];                 /* Expression: kalm_mpc_x.B
                                        * Referenced by: '<S124>/B'
                                        */
  real_T C_Value_c[12];                /* Expression: kalm_mpc_x.C
                                        * Referenced by: '<S124>/C'
                                        */
  real_T D_Value_l[3];                 /* Expression: kalm_mpc_x.D
                                        * Referenced by: '<S124>/D'
                                        */
  real_T Q_Value_a[16];                /* Expression: kalm_mpc_x.Q
                                        * Referenced by: '<S124>/Q'
                                        */
  real_T R_Value_c[9];                 /* Expression: kalm_mpc_x.R
                                        * Referenced by: '<S124>/R'
                                        */
  real_T UnitDelay1_X0_c[16];          /* Expression: kalm_mpc_x.P
                                        * Referenced by: '<S124>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_f;         /* Expression: 0.0
                                        * Referenced by: '<S132>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value[30];              /* Expression: FG_ctrl_x.V_max
                                        * Referenced by: '<S123>/V_max'
                                        */
  real_T i_min_Value;                  /* Expression: FG_ctrl_x.i_min
                                        * Referenced by: '<S123>/i_min'
                                        */
  real_T betas_Value[7];               /* Expression: FG_ctrl_x.betas
                                        * Referenced by: '<S123>/betas'
                                        */
  real_T L_Value;                      /* Expression: FG_ctrl_x.L
                                        * Referenced by: '<S123>/L'
                                        */
  real_T UnitDelay_X0_f[3];            /* Expression: zeros(FG_ctrl_x.delay_steps,1)
                                        * Referenced by: '<S123>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_k[30];          /* Expression: zeros(size(FG_ctrl_x.V_max,1),1)
                                        * Referenced by: '<S123>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S124>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S124>/Saturation'
                                        */
  real_T TT_PP_Value_m[900];           /* Expression: FG_ctrl_y.TT_PP
                                        * Referenced by: '<S125>/TT_PP'
                                        */
  real_T LL_PP_Value_e[90];            /* Expression: FG_ctrl_y.LL_PP
                                        * Referenced by: '<S125>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_l[2790];      /* Expression: FG_ctrl_y.LL_ref_PP
                                        * Referenced by: '<S125>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_m[900];     /* Expression: FG_ctrl_y.LL_U_ref_PP
                                        * Referenced by: '<S125>/LL_U_ref_PP'
                                        */
  real_T MM_Value_c[9];                /* Expression: FG_ctrl_y.MM
                                        * Referenced by: '<S125>/MM'
                                        */
  real_T PP_Value_m[900];              /* Expression: FG_ctrl_y.PP
                                        * Referenced by: '<S125>/PP'
                                        */
  real_T AA_delay_Value_h[9];          /* Expression: FG_ctrl_y.AA_delay
                                        * Referenced by: '<S125>/AA_delay'
                                        */
  real_T BB_delay_Value_o[9];          /* Expression: FG_ctrl_y.BB_delay
                                        * Referenced by: '<S125>/BB_delay'
                                        */
  real_T A_Value_n[16];                /* Expression: kalm_mpc_y.A
                                        * Referenced by: '<S126>/A'
                                        */
  real_T B_Value_h[4];                 /* Expression: kalm_mpc_y.B
                                        * Referenced by: '<S126>/B'
                                        */
  real_T C_Value_p[12];                /* Expression: kalm_mpc_y.C
                                        * Referenced by: '<S126>/C'
                                        */
  real_T D_Value_m[3];                 /* Expression: kalm_mpc_y.D
                                        * Referenced by: '<S126>/D'
                                        */
  real_T Q_Value_h[16];                /* Expression: kalm_mpc_y.Q
                                        * Referenced by: '<S126>/Q'
                                        */
  real_T R_Value_l[9];                 /* Expression: kalm_mpc_y.R
                                        * Referenced by: '<S126>/R'
                                        */
  real_T UnitDelay1_X0_fk[16];         /* Expression: kalm_mpc_y.P
                                        * Referenced by: '<S126>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_n;         /* Expression: 0.0
                                        * Referenced by: '<S135>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_o[30];            /* Expression: FG_ctrl_y.V_max
                                        * Referenced by: '<S125>/V_max'
                                        */
  real_T i_min_Value_j;                /* Expression: FG_ctrl_y.i_min
                                        * Referenced by: '<S125>/i_min'
                                        */
  real_T betas_Value_l[7];             /* Expression: FG_ctrl_y.betas
                                        * Referenced by: '<S125>/betas'
                                        */
  real_T L_Value_n;                    /* Expression: FG_ctrl_y.L
                                        * Referenced by: '<S125>/L'
                                        */
  real_T UnitDelay_X0_ik[3];           /* Expression: zeros(FG_ctrl_y.delay_steps,1)
                                        * Referenced by: '<S125>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_jc[30];         /* Expression: zeros(size(FG_ctrl_y.V_max,1),1)
                                        * Referenced by: '<S125>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S126>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S126>/Saturation'
                                        */
  real_T TT_PP_Value_b[900];           /* Expression: FG_ctrl_z.TT_PP
                                        * Referenced by: '<S129>/TT_PP'
                                        */
  real_T LL_PP_Value_j[60];            /* Expression: FG_ctrl_z.LL_PP
                                        * Referenced by: '<S129>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_h[1860];      /* Expression: FG_ctrl_z.LL_ref_PP
                                        * Referenced by: '<S129>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_o[900];     /* Expression: FG_ctrl_z.LL_U_ref_PP
                                        * Referenced by: '<S129>/LL_U_ref_PP'
                                        */
  real_T MM_Value_l[4];                /* Expression: FG_ctrl_z.MM
                                        * Referenced by: '<S129>/MM'
                                        */
  real_T PP_Value_o[900];              /* Expression: FG_ctrl_z.PP
                                        * Referenced by: '<S129>/PP'
                                        */
  real_T AA_delay_Value_l[4];          /* Expression: FG_ctrl_z.AA_delay
                                        * Referenced by: '<S129>/AA_delay'
                                        */
  real_T BB_delay_Value_b[4];          /* Expression: FG_ctrl_z.BB_delay
                                        * Referenced by: '<S129>/BB_delay'
                                        */
  real_T A_Value_f[9];                 /* Expression: kalm_mpc_z.A
                                        * Referenced by: '<S130>/A'
                                        */
  real_T B_Value_n[3];                 /* Expression: kalm_mpc_z.B
                                        * Referenced by: '<S130>/B'
                                        */
  real_T C_Value_o[6];                 /* Expression: kalm_mpc_z.C
                                        * Referenced by: '<S130>/C'
                                        */
  real_T D_Value_j[2];                 /* Expression: kalm_mpc_z.D
                                        * Referenced by: '<S130>/D'
                                        */
  real_T Q_Value_j[9];                 /* Expression: kalm_mpc_z.Q
                                        * Referenced by: '<S130>/Q'
                                        */
  real_T R_Value_ca[4];                /* Expression: kalm_mpc_z.R
                                        * Referenced by: '<S130>/R'
                                        */
  real_T UnitDelay1_X0_cw[9];          /* Expression: kalm_mpc_z.P
                                        * Referenced by: '<S130>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_c;         /* Expression: 0.0
                                        * Referenced by: '<S141>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_i[30];            /* Expression: FG_ctrl_z.V_max
                                        * Referenced by: '<S129>/V_max'
                                        */
  real_T i_min_Value_o;                /* Expression: FG_ctrl_z.i_min
                                        * Referenced by: '<S129>/i_min'
                                        */
  real_T betas_Value_g[8];             /* Expression: FG_ctrl_z.betas
                                        * Referenced by: '<S129>/betas'
                                        */
  real_T L_Value_m;                    /* Expression: FG_ctrl_z.L
                                        * Referenced by: '<S129>/L'
                                        */
  real_T UnitDelay_X0_a[2];            /* Expression: zeros(FG_ctrl_z.delay_steps,1)
                                        * Referenced by: '<S129>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_b[30];          /* Expression: zeros(size(FG_ctrl_z.V_max,1),1)
                                        * Referenced by: '<S129>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: MAX_BIAS_THRUST
                                        * Referenced by: '<S130>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -MAX_BIAS_THRUST
                                        * Referenced by: '<S130>/Saturation'
                                        */
  real_T TT_PP_Value_o[900];           /* Expression: FG_ctrl_yaw.TT_PP
                                        * Referenced by: '<S127>/TT_PP'
                                        */
  real_T LL_PP_Value_j5[60];           /* Expression: FG_ctrl_yaw.LL_PP
                                        * Referenced by: '<S127>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_e[1860];      /* Expression: FG_ctrl_yaw.LL_ref_PP
                                        * Referenced by: '<S127>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_b[900];     /* Expression: FG_ctrl_yaw.LL_U_ref_PP
                                        * Referenced by: '<S127>/LL_U_ref_PP'
                                        */
  real_T MM_Value_g[4];                /* Expression: FG_ctrl_yaw.MM
                                        * Referenced by: '<S127>/MM'
                                        */
  real_T PP_Value_p[900];              /* Expression: FG_ctrl_yaw.PP
                                        * Referenced by: '<S127>/PP'
                                        */
  real_T AA_delay_Value_o[4];          /* Expression: FG_ctrl_yaw.AA_delay
                                        * Referenced by: '<S127>/AA_delay'
                                        */
  real_T BB_delay_Value_d[12];         /* Expression: FG_ctrl_yaw.BB_delay
                                        * Referenced by: '<S127>/BB_delay'
                                        */
  real_T A_Value_k[9];                 /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S128>/A'
                                        */
  real_T B_Value_f[3];                 /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S128>/B'
                                        */
  real_T C_Value_b[6];                 /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S128>/C'
                                        */
  real_T D_Value_c[2];                 /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S128>/D'
                                        */
  real_T Q_Value_g[9];                 /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S128>/Q'
                                        */
  real_T R_Value_o[4];                 /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S128>/R'
                                        */
  real_T UnitDelay1_X0_n[9];           /* Expression: kalm_mpc_yaw.P
                                        * Referenced by: '<S128>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_e;         /* Expression: 0.0
                                        * Referenced by: '<S138>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_f[30];            /* Expression: FG_ctrl_yaw.V_max
                                        * Referenced by: '<S127>/V_max'
                                        */
  real_T i_min_Value_n;                /* Expression: FG_ctrl_yaw.i_min
                                        * Referenced by: '<S127>/i_min'
                                        */
  real_T betas_Value_j[5];             /* Expression: FG_ctrl_yaw.betas
                                        * Referenced by: '<S127>/betas'
                                        */
  real_T L_Value_g;                    /* Expression: FG_ctrl_yaw.L
                                        * Referenced by: '<S127>/L'
                                        */
  real_T UnitDelay_X0_fj[6];           /* Expression: zeros(FG_ctrl_yaw.delay_steps,1)
                                        * Referenced by: '<S127>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_o[30];          /* Expression: zeros(size(FG_ctrl_yaw.V_max,1),1)
                                        * Referenced by: '<S127>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_o3;       /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S128>/Saturation'
                                        */
  real_T Saturation_LowerSat_kn;       /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S128>/Saturation'
                                        */
  real_T g_Value_m;                    /* Expression: g
                                        * Referenced by: '<S143>/g'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 1
                                        * Referenced by: '<S121>/Gain'
                                        */
  real_T raddeg2_Gain_p;               /* Expression: 180/pi
                                        * Referenced by: '<S121>/rad -> deg2'
                                        */
  real_T raddeg1_Gain_a;               /* Expression: 180/pi
                                        * Referenced by: '<S121>/rad -> deg1'
                                        */
  real_T raddeg3_Gain_k;               /* Expression: 180/pi
                                        * Referenced by: '<S121>/rad -> deg3'
                                        */
  real_T raddeg_Gain_k;                /* Expression: 180/pi
                                        * Referenced by: '<S121>/rad -> deg'
                                        */
  real_T pitch_offset_Value;           /* Expression: 0.00
                                        * Referenced by: '<S7>/pitch_offset'
                                        */
  real_T InitialCondition_Value;       /* Expression: vinit
                                        * Referenced by: '<S116>/Initial Condition'
                                        */
  real_T Constant1_Value_mr;           /* Expression: 1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant2'
                                        */
  real_T FixPtUnitDelay1_X0_h;         /* Expression: vinit
                                        * Referenced by: '<S116>/FixPt Unit Delay1'
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
                                        * Referenced by: '<S113>/Slider Gain'
                                        */
  real_T Gain5_Gain;                   /* Expression: -1
                                        * Referenced by: '<S7>/Gain5'
                                        */
  real_T Constant1_Value_ih;           /* Expression: 1.1
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 0.7
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: 0
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T SliderGain_Gain_o;            /* Expression: gain
                                        * Referenced by: '<S112>/Slider Gain'
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
                                        * Referenced by: '<S117>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength;  /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S117>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength;  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S117>/Integer Delay2'
                                        */
  uint32_T IntegerDelay3_DelayLength_o;/* Computed Parameter: IntegerDelay3_DelayLength_o
                                        * Referenced by: '<S117>/Integer Delay3'
                                        */
  uint8_T FixPtUnitDelay2_X0;          /* Computed Parameter: FixPtUnitDelay2_X0
                                        * Referenced by: '<S64>/FixPt Unit Delay2'
                                        */
  uint8_T Constant_Value_m;            /* Expression: uint8(1)
                                        * Referenced by: '<S35>/Constant'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(0)
                                        * Referenced by: '<S35>/SwitchControl'
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
                                        * Referenced by: '<S132>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_n;        /* Computed Parameter: FixPtUnitDelay2_X0_n
                                        * Referenced by: '<S135>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_do;       /* Computed Parameter: FixPtUnitDelay2_X0_do
                                        * Referenced by: '<S141>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_i;        /* Computed Parameter: FixPtUnitDelay2_X0_i
                                        * Referenced by: '<S138>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtConstant_Value_h;       /* Computed Parameter: FixPtConstant_Value_h
                                        * Referenced by: '<S132>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_o;       /* Computed Parameter: FixPtConstant_Value_o
                                        * Referenced by: '<S135>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_n;       /* Computed Parameter: FixPtConstant_Value_n
                                        * Referenced by: '<S138>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_p;       /* Computed Parameter: FixPtConstant_Value_p
                                        * Referenced by: '<S141>/FixPt Constant'
                                        */
  uint8_T FixPtUnitDelay2_X0_g;        /* Computed Parameter: FixPtUnitDelay2_X0_g
                                        * Referenced by: '<S116>/FixPt Unit Delay2'
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
                                        * Referenced by: '<S111>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_ef;  /* Expression: uint8(0)
                                        * Referenced by: '<S111>/SwitchControl'
                                        */
  uint8_T FixPtConstant_Value_i;       /* Computed Parameter: FixPtConstant_Value_i
                                        * Referenced by: '<S116>/FixPt Constant'
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
 * '<S25>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1'
 * '<S26>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S27>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S28>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S29>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/MATLAB Function'
 * '<S30>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/Slider Gain'
 * '<S31>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/Slider Gain1'
 * '<S32>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/Subsystem/Slider Gain2'
 * '<S33>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Explicit Ctrl Free Flight1'
 * '<S34>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Free Flight'
 * '<S35>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Manual Switch'
 * '<S36>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Mean'
 * '<S37>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Mean1'
 * '<S38>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Slider Gain'
 * '<S39>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Slider Gain1'
 * '<S40>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Slider Gain2'
 * '<S41>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Wall Deviation'
 * '<S42>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Explicit Ctrl Free Flight1/Subsystem'
 * '<S43>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Explicit Ctrl Free Flight1/Subsystem/MATLAB Function'
 * '<S44>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Explicit Ctrl Free Flight1/Subsystem/Slider Gain'
 * '<S45>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Explicit Ctrl Free Flight1/Subsystem/Subsystem'
 * '<S46>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Explicit Ctrl Free Flight1/Subsystem/Subsystem/MATLAB Function1'
 * '<S47>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Explicit Ctrl Free Flight1/Subsystem/Subsystem/Subsystem'
 * '<S48>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Explicit Ctrl Free Flight1/Subsystem/Subsystem/Subsystem1'
 * '<S49>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Wall Deviation/MATLAB Function'
 * '<S50>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Wall Deviation/Slider Gain'
 * '<S51>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  1/Wall Deviation/Slider Gain2'
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
 * '<S68>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Slider Gain'
 * '<S69>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Subsystem'
 * '<S70>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Wall Deviation'
 * '<S71>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S72>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Subsystem/MATLAB Function'
 * '<S73>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Subsystem/Slider Gain'
 * '<S74>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Wall Deviation/MATLAB Function'
 * '<S75>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Wall Deviation/Slider Gain'
 * '<S76>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Wall Deviation/Slider Gain2'
 * '<S77>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference'
 * '<S78>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Next Ref'
 * '<S79>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Slider Gain'
 * '<S80>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem'
 * '<S81>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1'
 * '<S82>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Thresy'
 * '<S83>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Thresz'
 * '<S84>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation'
 * '<S85>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1'
 * '<S86>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/get ref from vector1'
 * '<S87>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/get ref from vector2'
 * '<S88>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem/MATLAB Function'
 * '<S89>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/MATLAB Function'
 * '<S90>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain'
 * '<S91>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain1'
 * '<S92>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain2'
 * '<S93>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain3'
 * '<S94>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Subsystem1/Slider Gain4'
 * '<S95>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation/MATLAB Function'
 * '<S96>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation/Slider Gain'
 * '<S97>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/Wall Deviation/Slider Gain2'
 * '<S98>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_x'
 * '<S99>'  : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_y'
 * '<S100>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_yaw'
 * '<S101>' : 'controller_template/FreeFlight Pos Ctrl/Subsystem/Wall Point Reference/create traj1/generate_X_ref_z'
 * '<S102>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling '
 * '<S103>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame'
 * '<S104>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S105>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation'
 * '<S106>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation/MATLAB Function'
 * '<S107>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation/Slider Gain'
 * '<S108>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Wall Deviation/Slider Gain2'
 * '<S109>' : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S110>' : 'controller_template/FreeFlight Pos Ctrl/rotate to world frame/Embedded MATLAB Function'
 * '<S111>' : 'controller_template/convert2cmd/Manual Switch'
 * '<S112>' : 'controller_template/convert2cmd/Slider Gain'
 * '<S113>' : 'controller_template/convert2cmd/added_mass'
 * '<S114>' : 'controller_template/convert2cmd/added_mass1'
 * '<S115>' : 'controller_template/convert2cmd/added_mass2'
 * '<S116>' : 'controller_template/delay/delay bias'
 * '<S117>' : 'controller_template/pos controller/MAIN CONTROL LOOP1'
 * '<S118>' : 'controller_template/pos controller/decoupling and rotation'
 * '<S119>' : 'controller_template/pos controller/get ref from vector'
 * '<S120>' : 'controller_template/pos controller/rotate to world frame'
 * '<S121>' : 'controller_template/pos controller/view & log signals'
 * '<S122>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/demux'
 * '<S123>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S124>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias'
 * '<S125>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S126>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias'
 * '<S127>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S128>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S129>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S130>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias'
 * '<S131>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  /runFastGradient'
 * '<S132>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/Unit Delay External IC1'
 * '<S133>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/discrete kalman filter'
 * '<S134>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG/runFastGradient'
 * '<S135>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/Unit Delay External IC1'
 * '<S136>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/discrete kalman filter'
 * '<S137>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG/runFastGradient'
 * '<S138>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S139>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S140>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG/runFastGradient'
 * '<S141>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/Unit Delay External IC1'
 * '<S142>' : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/discrete kalman filter'
 * '<S143>' : 'controller_template/pos controller/decoupling and rotation/decoupling '
 * '<S144>' : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame'
 * '<S145>' : 'controller_template/pos controller/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S146>' : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S147>' : 'controller_template/pos controller/rotate to world frame/Embedded MATLAB Function'
 */
#endif                                 /* RTW_HEADER_controller_template_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
