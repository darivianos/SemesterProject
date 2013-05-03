/*
 * File: controller_template.h
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.383
 * Simulink Coder version         : 8.1 (R2011b) 08-Jul-2011
 * TLC version                    : 8.1 (Aug  6 2011)
 * C/C++ source code generated on : Thu May  2 20:10:01 2013
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

/* Block signals for system '<S11>/Embedded MATLAB Function' */
typedef struct {
  real_T roll_rot;                     /* '<S11>/Embedded MATLAB Function' */
  real_T pitch_rot;                    /* '<S11>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S11>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S11>/Embedded MATLAB Function' */
} rtB_EmbeddedMATLABFunction_cont;

/* Block states (auto storage) for system '<S11>/Embedded MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S11>/Embedded MATLAB Function' */
  uint8_T is_active_c26_Hquad_control_LIB;/* '<S11>/Embedded MATLAB Function' */
  boolean_T isStable;                  /* '<S11>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S11>/Embedded MATLAB Function' */
} rtDW_EmbeddedMATLABFunction_con;

/* Block signals for system '<S38>/runFastGradient' */
typedef struct {
  real_T u_opt;                        /* '<S38>/runFastGradient' */
  real_T J_star;                       /* '<S38>/runFastGradient' */
  real_T u_buff_out[3];                /* '<S38>/runFastGradient' */
  real_T V_init_out[30];               /* '<S38>/runFastGradient' */
} rtB_runFastGradient_controller_;

/* Block states (auto storage) for system '<S38>/runFastGradient' */
typedef struct {
  int32_T sfEvent;                     /* '<S38>/runFastGradient' */
  uint8_T is_active_c6_Hquad_control_LIB_;/* '<S38>/runFastGradient' */
  boolean_T isStable;                  /* '<S38>/runFastGradient' */
  boolean_T doneDoubleBufferReInit;    /* '<S38>/runFastGradient' */
} rtDW_runFastGradient_controller;

/* Block signals for system '<S39>/discrete kalman filter' */
typedef struct {
  real_T state_est[4];                 /* '<S39>/discrete kalman filter' */
  real_T P_est[16];                    /* '<S39>/discrete kalman filter' */
} rtB_discretekalmanfilter_contro;

/* Block states (auto storage) for system '<S39>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S39>/discrete kalman filter' */
  uint8_T is_active_c11_Hquad_control_LIB;/* '<S39>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S39>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S39>/discrete kalman filter' */
} rtDW_discretekalmanfilter_contr;

/* Block signals for system '<S43>/discrete kalman filter' */
typedef struct {
  real_T state_est[3];                 /* '<S43>/discrete kalman filter' */
  real_T P_est[9];                     /* '<S43>/discrete kalman filter' */
} rtB_discretekalmanfilter_cont_p;

/* Block states (auto storage) for system '<S43>/discrete kalman filter' */
typedef struct {
  int32_T sfEvent;                     /* '<S43>/discrete kalman filter' */
  uint8_T is_active_c5_Hquad_control_LIB_;/* '<S43>/discrete kalman filter' */
  boolean_T isStable;                  /* '<S43>/discrete kalman filter' */
  boolean_T doneDoubleBufferReInit;    /* '<S43>/discrete kalman filter' */
} rtDW_discretekalmanfilter_con_g;

/* Block signals (auto storage) */
typedef struct {
  real_T DataTypeConversion[30];       /* '<S1>/Data Type Conversion' */
  real_T X_ref_x[93];                  /* '<Root>/Data Type Conversion2' */
  real_T X_ref_y[93];                  /* '<Root>/Data Type Conversion3' */
  real_T X_ref_z[62];                  /* '<Root>/Data Type Conversion1' */
  real_T X_ref_yaw[62];                /* '<Root>/Data Type Conversion' */
  real_T MultiportSwitch;              /* '<S4>/Multiport Switch' */
  real_T pitch_cmd;                    /* '<Root>/Switch1' */
  real_T roll_cmd;                     /* '<Root>/Switch1' */
  real_T thrust_cmd;                   /* '<Root>/Switch1' */
  real_T yaw_rate_cmd;                 /* '<Root>/Switch1' */
  real_T pitch_bias;                   /* '<Root>/Switch1' */
  real_T roll_bias;                    /* '<Root>/Switch1' */
  real_T thrust_bias;                  /* '<Root>/Switch1' */
  real_T yaw_rate_bias;                /* '<Root>/Switch1' */
  real_T raddeg2[3];                   /* '<S36>/rad -> deg2' */
  real_T raddeg1[3];                   /* '<S36>/rad -> deg1' */
  real_T raddeg3[3];                   /* '<S36>/rad -> deg3' */
  real_T raddeg[4];                    /* '<S36>/rad -> deg' */
  real_T bias_W[4];                    /* '<S33>/bias_W' */
  real_T cmd_W[4];                     /* '<S33>/cmd_W' */
  real_T pitch_rot;                    /* '<S59>/Embedded MATLAB Function' */
  real_T roll_rot;                     /* '<S59>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S59>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S59>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp;               /* '<S58>/Embedded MATLAB Function' */
  real_T roll_cmd_comp;                /* '<S58>/Embedded MATLAB Function' */
  real_T thrust_comp;                  /* '<S58>/Embedded MATLAB Function' */
  real_T thrust_cmd_e;                 /* '<S32>/Sum5' */
  real_T u_opt;                        /* '<S44>/runFastGradient' */
  real_T J_star;                       /* '<S44>/runFastGradient' */
  real_T u_buff_out[2];                /* '<S44>/runFastGradient' */
  real_T V_init_out[30];               /* '<S44>/runFastGradient' */
  real_T u_opt_l;                      /* '<S42>/runFastGradient' */
  real_T J_star_h;                     /* '<S42>/runFastGradient' */
  real_T u_buff_out_i[6];              /* '<S42>/runFastGradient' */
  real_T V_init_out_n[30];             /* '<S42>/runFastGradient' */
  real_T bias_W_b[4];                  /* '<S9>/bias_W' */
  real_T cmd_W_h[4];                   /* '<S9>/cmd_W' */
  real_T pitch_rot_n;                  /* '<S26>/Embedded MATLAB Function' */
  real_T roll_rot_e;                   /* '<S26>/Embedded MATLAB Function' */
  real_T pitch_bias_rot_i;             /* '<S26>/Embedded MATLAB Function' */
  real_T roll_bias_rot_d;              /* '<S26>/Embedded MATLAB Function' */
  real_T pitch_cmd_comp_n;             /* '<S25>/Embedded MATLAB Function' */
  real_T roll_cmd_comp_j;              /* '<S25>/Embedded MATLAB Function' */
  real_T thrust_comp_k;                /* '<S25>/Embedded MATLAB Function' */
  real_T Saturation3;                  /* '<S13>/Saturation3' */
  real_T Saturation2;                  /* '<S13>/Saturation2' */
  real_T RateTransition[4];            /* '<S17>/Rate Transition' */
  real_T Saturation;                   /* '<S14>/Saturation' */
  real_T Saturation1;                  /* '<S14>/Saturation1' */
  real_T Add;                          /* '<S14>/Add' */
  real_T Saturation3_e;                /* '<S14>/Saturation3' */
  real_T Saturation2_l;                /* '<S14>/Saturation2' */
  real_T RateTransition_i[4];          /* '<S19>/Rate Transition' */
  real_T Saturation1_o;                /* '<S16>/Saturation1' */
  real_T Saturation_j;                 /* '<S16>/Saturation' */
  real_T RateTransition_j[2];          /* '<S23>/Rate Transition' */
  real_T RateTransition_jf;            /* '<S21>/Rate Transition' */
  real_T U;                            /* '<S23>/Ctrl_Xdir' */
  real_T flag_oob;                     /* '<S23>/Ctrl_Xdir' */
  real_T U_g;                          /* '<S21>/Ctrl_Xdir' */
  real_T flag_oob_l;                   /* '<S21>/Ctrl_Xdir' */
  real_T U_p;                          /* '<S19>/Ctrl_Xdir' */
  real_T flag_oob_o;                   /* '<S19>/Ctrl_Xdir' */
  real_T U_i;                          /* '<S17>/Ctrl_Xdir' */
  real_T flag_oob_b;                   /* '<S17>/Ctrl_Xdir' */
  rtB_EmbeddedMATLABFunction_cont sf_EmbeddedMATLABFunction_o;/* '<S35>/Embedded MATLAB Function' */
  rtB_discretekalmanfilter_cont_p sf_discretekalmanfilter_k;/* '<S45>/discrete kalman filter' */
  rtB_discretekalmanfilter_cont_p sf_discretekalmanfilter_n;/* '<S43>/discrete kalman filter' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_m;/* '<S41>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient_d;/* '<S40>/runFastGradient' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter;/* '<S39>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient;/* '<S38>/runFastGradient' */
  rtB_EmbeddedMATLABFunction_cont sf_EmbeddedMATLABFunction;/* '<S11>/Embedded MATLAB Function' */
} BlockIO_controller_template;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T FixPtUnitDelay1_DSTATE[4];    /* '<S31>/FixPt Unit Delay1' */
  real_T IntegerDelay_DSTATE;          /* '<S32>/Integer Delay' */
  real_T IntegerDelay1_DSTATE;         /* '<S32>/Integer Delay1' */
  real_T IntegerDelay2_DSTATE;         /* '<S32>/Integer Delay2' */
  real_T IntegerDelay3_DSTATE;         /* '<S32>/Integer Delay3' */
  real_T UnitDelay1_DSTATE[16];        /* '<S39>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_i[3];  /* '<S47>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE[3];          /* '<S38>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c[30];      /* '<S38>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_b[16];      /* '<S41>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_g[3];  /* '<S50>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_j[3];        /* '<S40>/Unit Delay' */
  real_T UnitDelay1_DSTATE_l[30];      /* '<S40>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_j[9];       /* '<S45>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_d[2];  /* '<S56>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_l[2];        /* '<S44>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g[30];      /* '<S44>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_lx[9];      /* '<S43>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_e[2];  /* '<S53>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_jz[6];       /* '<S42>/Unit Delay' */
  real_T UnitDelay1_DSTATE_js[30];     /* '<S42>/Unit Delay1' */
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
  } mode1_PWORK_h;                     /* '<S7>/mode1' */

  struct {
    void *FilePtr;
  } ToFile_PWORK;                      /* '<S36>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<S36>/To File1' */

  struct {
    void *LoggedData;
  } pitchcmd_PWORK;                    /* '<S36>/pitch cmd' */

  struct {
    void *LoggedData;
  } rollcmd_PWORK;                     /* '<S36>/roll cmd' */

  struct {
    void *LoggedData;
  } thrustcmd_PWORK;                   /* '<S36>/thrust cmd' */

  struct {
    void *LoggedData;
  } x_ref_PWORK;                       /* '<S36>/x_ref' */

  struct {
    void *LoggedData;
  } y_ref_PWORK;                       /* '<S36>/y_ref' */

  struct {
    void *LoggedData;
  } yawcmd_PWORK;                      /* '<S36>/yaw cmd' */

  struct {
    void *LoggedData;
  } yaw_ref_PWORK;                     /* '<S36>/yaw_ref' */

  struct {
    void *LoggedData;
  } z_ref_PWORK;                       /* '<S36>/z_ref' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S13>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S13>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_o;                     /* '<S14>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_f;                    /* '<S14>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S14>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     /* '<S16>/Scope' */

  int32_T sfEvent;                     /* '<S59>/Embedded MATLAB Function' */
  int32_T sfEvent_f;                   /* '<S58>/Embedded MATLAB Function' */
  int32_T sfEvent_k;                   /* '<S44>/runFastGradient' */
  int32_T sfEvent_n;                   /* '<S42>/runFastGradient' */
  int32_T sfEvent_j;                   /* '<S26>/Embedded MATLAB Function' */
  int32_T sfEvent_c;                   /* '<S25>/Embedded MATLAB Function' */
  int32_T sfEvent_k0;                  /* '<S23>/Ctrl_Xdir' */
  int32_T sfEvent_jv;                  /* '<S21>/Ctrl_Xdir' */
  int32_T sfEvent_cd;                  /* '<S19>/Ctrl_Xdir' */
  int32_T sfEvent_kl;                  /* '<S17>/Ctrl_Xdir' */
  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<S36>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<S36>/To File1' */

  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S31>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_l;    /* '<S47>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_b;    /* '<S50>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S56>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S53>/FixPt Unit Delay2' */
  int8_T FreeFlightPosCtrl_SubsysRanBC;/* '<Root>/FreeFlight Pos Ctrl' */
  int8_T poscontroller_SubsysRanBC;    /* '<Root>/pos controller' */
  uint8_T is_active_c4_Hquad_control_LIB_;/* '<S59>/Embedded MATLAB Function' */
  uint8_T is_active_c1_Hquad_control_LIB_;/* '<S58>/Embedded MATLAB Function' */
  uint8_T is_active_c8_Hquad_control_LIB_;/* '<S44>/runFastGradient' */
  uint8_T is_active_c9_Hquad_control_LIB_;/* '<S42>/runFastGradient' */
  uint8_T is_active_c4_Hquad_control_LI_d;/* '<S26>/Embedded MATLAB Function' */
  uint8_T is_active_c1_Hquad_control_LI_l;/* '<S25>/Embedded MATLAB Function' */
  uint8_T is_active_c3_controller_templat;/* '<S23>/Ctrl_Xdir' */
  uint8_T is_active_c4_controller_templat;/* '<S21>/Ctrl_Xdir' */
  uint8_T is_active_c2_controller_templat;/* '<S19>/Ctrl_Xdir' */
  uint8_T is_active_c1_controller_templat;/* '<S17>/Ctrl_Xdir' */
  boolean_T isStable;                  /* '<S59>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S59>/Embedded MATLAB Function' */
  boolean_T isStable_m;                /* '<S58>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S58>/Embedded MATLAB Function' */
  boolean_T isStable_i;                /* '<S44>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_h;  /* '<S44>/runFastGradient' */
  boolean_T isStable_h;                /* '<S42>/runFastGradient' */
  boolean_T doneDoubleBufferReInit_o;  /* '<S42>/runFastGradient' */
  boolean_T isStable_o;                /* '<S26>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_c;  /* '<S26>/Embedded MATLAB Function' */
  boolean_T isStable_mf;               /* '<S25>/Embedded MATLAB Function' */
  boolean_T doneDoubleBufferReInit_a;  /* '<S25>/Embedded MATLAB Function' */
  boolean_T isStable_c;                /* '<S23>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_ha; /* '<S23>/Ctrl_Xdir' */
  boolean_T isStable_hg;               /* '<S21>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_p;  /* '<S21>/Ctrl_Xdir' */
  boolean_T isStable_k;                /* '<S19>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_d;  /* '<S19>/Ctrl_Xdir' */
  boolean_T isStable_f;                /* '<S17>/Ctrl_Xdir' */
  boolean_T doneDoubleBufferReInit_g;  /* '<S17>/Ctrl_Xdir' */
  boolean_T FreeFlightPosCtrl_MODE;    /* '<Root>/FreeFlight Pos Ctrl' */
  boolean_T poscontroller_MODE;        /* '<Root>/pos controller' */
  rtDW_EmbeddedMATLABFunction_con sf_EmbeddedMATLABFunction_o;/* '<S35>/Embedded MATLAB Function' */
  rtDW_discretekalmanfilter_con_g sf_discretekalmanfilter_k;/* '<S45>/discrete kalman filter' */
  rtDW_discretekalmanfilter_con_g sf_discretekalmanfilter_n;/* '<S43>/discrete kalman filter' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter_m;/* '<S41>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient_d;/* '<S40>/runFastGradient' */
  rtDW_discretekalmanfilter_contr sf_discretekalmanfilter;/* '<S39>/discrete kalman filter' */
  rtDW_runFastGradient_controller sf_runFastGradient;/* '<S38>/runFastGradient' */
  rtDW_EmbeddedMATLABFunction_con sf_EmbeddedMATLABFunction;/* '<S11>/Embedded MATLAB Function' */
} D_Work_controller_template;

/* Parameters (auto storage) */
struct Parameters_controller_template_ {
  real_T gravity_Value;                /* Expression: g
                                        * Referenced by: '<S8>/gravity'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.2094
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.2094
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 2
                                        * Referenced by: '<S13>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -2
                                        * Referenced by: '<S13>/Saturation1'
                                        */
  real_T Saturation3_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S13>/Saturation3'
                                        */
  real_T Saturation3_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S13>/Saturation3'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S13>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: -1
                                        * Referenced by: '<S13>/Saturation2'
                                        */
  real_T Constant_Value[3760];         /* Expression: Hn_XdirFF
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T Constant1_Value[940];         /* Expression: Kn_XdirFF
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T Constant2_Value[428];         /* Expression: Fi_XdirFF
                                        * Referenced by: '<S17>/Constant2'
                                        */
  real_T Constant3_Value[107];         /* Expression: Gi_XdirFF
                                        * Referenced by: '<S17>/Constant3'
                                        */
  real_T Constant4_Value[107];         /* Expression: Nc_XdirFF
                                        * Referenced by: '<S17>/Constant4'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: 0.2094
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -0.2094
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Saturation1_UpperSat_o;       /* Expression: 2
                                        * Referenced by: '<S14>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_c;       /* Expression: -2
                                        * Referenced by: '<S14>/Saturation1'
                                        */
  real_T Saturation3_UpperSat_n;       /* Expression: 1
                                        * Referenced by: '<S14>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_c;       /* Expression: -1
                                        * Referenced by: '<S14>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_b;       /* Expression: 1
                                        * Referenced by: '<S14>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_h;       /* Expression: -1
                                        * Referenced by: '<S14>/Saturation2'
                                        */
  real_T Constant_Value_l[3684];       /* Expression: Hn_Ydir
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Constant1_Value_j[921];       /* Expression: Kn_Ydir
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Constant2_Value_j[416];       /* Expression: Fi_Ydir
                                        * Referenced by: '<S19>/Constant2'
                                        */
  real_T Constant3_Value_o[104];       /* Expression: Gi_Ydir
                                        * Referenced by: '<S19>/Constant3'
                                        */
  real_T Constant4_Value_g[104];       /* Expression: Nc_Ydir
                                        * Referenced by: '<S19>/Constant4'
                                        */
  real_T Saturation1_UpperSat_d;       /* Expression: 1
                                        * Referenced by: '<S16>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -1
                                        * Referenced by: '<S16>/Saturation1'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -1
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Constant_Value_b[176];        /* Expression: Hn_Zdir
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Constant1_Value_l[88];        /* Expression: Kn_Zdir
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T Constant2_Value_g[42];        /* Expression: Fi_Zdir
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T Constant3_Value_m[21];        /* Expression: Gi_Zdir
                                        * Referenced by: '<S23>/Constant3'
                                        */
  real_T Constant4_Value_a[21];        /* Expression: Nc_Zdir
                                        * Referenced by: '<S23>/Constant4'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 0.0873
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -0.0873
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Constant_Value_a[2];          /* Expression: Hn_Yaw
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant1_Value_g[2];         /* Expression: Kn_Yaw
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real_T Constant2_Value_jq;           /* Expression: Fi_Yaw
                                        * Referenced by: '<S21>/Constant2'
                                        */
  real_T Constant3_Value_b;            /* Expression: Gi_Yaw
                                        * Referenced by: '<S21>/Constant3'
                                        */
  real_T Constant4_Value_gb;           /* Expression: Nc_Yaw
                                        * Referenced by: '<S21>/Constant4'
                                        */
  real_T g_Value;                      /* Expression: g
                                        * Referenced by: '<S25>/g'
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
                                        * Referenced by: '<S5>/yaw_rate'
                                        */
  real_T yaw_cmd2yaw_Gain;             /* Expression: yaw_cmd2yaw_1stOrd
                                        * Referenced by: '<S5>/yaw_cmd2yaw'
                                        */
  real_T IntegerDelay_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<S32>/Integer Delay'
                                        */
  real_T IntegerDelay1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S32>/Integer Delay1'
                                         */
  real_T IntegerDelay2_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S32>/Integer Delay2'
                                         */
  real_T IntegerDelay3_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S32>/Integer Delay3'
                                         */
  real_T gravity_Value_j;              /* Expression: g
                                        * Referenced by: '<S32>/gravity'
                                        */
  real_T TT_PP_Value[900];             /* Expression: FG_ctrl_x.TT_PP
                                        * Referenced by: '<S38>/TT_PP'
                                        */
  real_T LL_PP_Value[90];              /* Expression: FG_ctrl_x.LL_PP
                                        * Referenced by: '<S38>/LL_PP'
                                        */
  real_T LL_ref_PP_Value[2790];        /* Expression: FG_ctrl_x.LL_ref_PP
                                        * Referenced by: '<S38>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value[900];       /* Expression: FG_ctrl_x.LL_U_ref_PP
                                        * Referenced by: '<S38>/LL_U_ref_PP'
                                        */
  real_T MM_Value[9];                  /* Expression: FG_ctrl_x.MM
                                        * Referenced by: '<S38>/MM'
                                        */
  real_T PP_Value[900];                /* Expression: FG_ctrl_x.PP
                                        * Referenced by: '<S38>/PP'
                                        */
  real_T AA_delay_Value[9];            /* Expression: FG_ctrl_x.AA_delay
                                        * Referenced by: '<S38>/AA_delay'
                                        */
  real_T BB_delay_Value[9];            /* Expression: FG_ctrl_x.BB_delay
                                        * Referenced by: '<S38>/BB_delay'
                                        */
  real_T A_Value[16];                  /* Expression: kalm_mpc_x.A
                                        * Referenced by: '<S39>/A'
                                        */
  real_T B_Value[4];                   /* Expression: kalm_mpc_x.B
                                        * Referenced by: '<S39>/B'
                                        */
  real_T C_Value[12];                  /* Expression: kalm_mpc_x.C
                                        * Referenced by: '<S39>/C'
                                        */
  real_T D_Value[3];                   /* Expression: kalm_mpc_x.D
                                        * Referenced by: '<S39>/D'
                                        */
  real_T Q_Value[16];                  /* Expression: kalm_mpc_x.Q
                                        * Referenced by: '<S39>/Q'
                                        */
  real_T R_Value[9];                   /* Expression: kalm_mpc_x.R
                                        * Referenced by: '<S39>/R'
                                        */
  real_T UnitDelay1_X0[16];            /* Expression: kalm_mpc_x.P
                                        * Referenced by: '<S39>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0;           /* Expression: 0.0
                                        * Referenced by: '<S47>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value[30];              /* Expression: FG_ctrl_x.V_max
                                        * Referenced by: '<S38>/V_max'
                                        */
  real_T i_min_Value;                  /* Expression: FG_ctrl_x.i_min
                                        * Referenced by: '<S38>/i_min'
                                        */
  real_T betas_Value[7];               /* Expression: FG_ctrl_x.betas
                                        * Referenced by: '<S38>/betas'
                                        */
  real_T L_Value;                      /* Expression: FG_ctrl_x.L
                                        * Referenced by: '<S38>/L'
                                        */
  real_T UnitDelay_X0[3];              /* Expression: zeros(FG_ctrl_x.delay_steps,1)
                                        * Referenced by: '<S38>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_k[30];          /* Expression: zeros(size(FG_ctrl_x.V_max,1),1)
                                        * Referenced by: '<S38>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S39>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S39>/Saturation'
                                        */
  real_T TT_PP_Value_m[900];           /* Expression: FG_ctrl_y.TT_PP
                                        * Referenced by: '<S40>/TT_PP'
                                        */
  real_T LL_PP_Value_e[90];            /* Expression: FG_ctrl_y.LL_PP
                                        * Referenced by: '<S40>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_l[2790];      /* Expression: FG_ctrl_y.LL_ref_PP
                                        * Referenced by: '<S40>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_m[900];     /* Expression: FG_ctrl_y.LL_U_ref_PP
                                        * Referenced by: '<S40>/LL_U_ref_PP'
                                        */
  real_T MM_Value_c[9];                /* Expression: FG_ctrl_y.MM
                                        * Referenced by: '<S40>/MM'
                                        */
  real_T PP_Value_m[900];              /* Expression: FG_ctrl_y.PP
                                        * Referenced by: '<S40>/PP'
                                        */
  real_T AA_delay_Value_h[9];          /* Expression: FG_ctrl_y.AA_delay
                                        * Referenced by: '<S40>/AA_delay'
                                        */
  real_T BB_delay_Value_o[9];          /* Expression: FG_ctrl_y.BB_delay
                                        * Referenced by: '<S40>/BB_delay'
                                        */
  real_T A_Value_n[16];                /* Expression: kalm_mpc_y.A
                                        * Referenced by: '<S41>/A'
                                        */
  real_T B_Value_h[4];                 /* Expression: kalm_mpc_y.B
                                        * Referenced by: '<S41>/B'
                                        */
  real_T C_Value_p[12];                /* Expression: kalm_mpc_y.C
                                        * Referenced by: '<S41>/C'
                                        */
  real_T D_Value_m[3];                 /* Expression: kalm_mpc_y.D
                                        * Referenced by: '<S41>/D'
                                        */
  real_T Q_Value_h[16];                /* Expression: kalm_mpc_y.Q
                                        * Referenced by: '<S41>/Q'
                                        */
  real_T R_Value_l[9];                 /* Expression: kalm_mpc_y.R
                                        * Referenced by: '<S41>/R'
                                        */
  real_T UnitDelay1_X0_f[16];          /* Expression: kalm_mpc_y.P
                                        * Referenced by: '<S41>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_n;         /* Expression: 0.0
                                        * Referenced by: '<S50>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_o[30];            /* Expression: FG_ctrl_y.V_max
                                        * Referenced by: '<S40>/V_max'
                                        */
  real_T i_min_Value_j;                /* Expression: FG_ctrl_y.i_min
                                        * Referenced by: '<S40>/i_min'
                                        */
  real_T betas_Value_l[7];             /* Expression: FG_ctrl_y.betas
                                        * Referenced by: '<S40>/betas'
                                        */
  real_T L_Value_n;                    /* Expression: FG_ctrl_y.L
                                        * Referenced by: '<S40>/L'
                                        */
  real_T UnitDelay_X0_i[3];            /* Expression: zeros(FG_ctrl_y.delay_steps,1)
                                        * Referenced by: '<S40>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_j[30];          /* Expression: zeros(size(FG_ctrl_y.V_max,1),1)
                                        * Referenced by: '<S40>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T TT_PP_Value_b[900];           /* Expression: FG_ctrl_z.TT_PP
                                        * Referenced by: '<S44>/TT_PP'
                                        */
  real_T LL_PP_Value_j[60];            /* Expression: FG_ctrl_z.LL_PP
                                        * Referenced by: '<S44>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_h[1860];      /* Expression: FG_ctrl_z.LL_ref_PP
                                        * Referenced by: '<S44>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_o[900];     /* Expression: FG_ctrl_z.LL_U_ref_PP
                                        * Referenced by: '<S44>/LL_U_ref_PP'
                                        */
  real_T MM_Value_l[4];                /* Expression: FG_ctrl_z.MM
                                        * Referenced by: '<S44>/MM'
                                        */
  real_T PP_Value_o[900];              /* Expression: FG_ctrl_z.PP
                                        * Referenced by: '<S44>/PP'
                                        */
  real_T AA_delay_Value_l[4];          /* Expression: FG_ctrl_z.AA_delay
                                        * Referenced by: '<S44>/AA_delay'
                                        */
  real_T BB_delay_Value_b[4];          /* Expression: FG_ctrl_z.BB_delay
                                        * Referenced by: '<S44>/BB_delay'
                                        */
  real_T A_Value_f[9];                 /* Expression: kalm_mpc_z.A
                                        * Referenced by: '<S45>/A'
                                        */
  real_T B_Value_n[3];                 /* Expression: kalm_mpc_z.B
                                        * Referenced by: '<S45>/B'
                                        */
  real_T C_Value_o[6];                 /* Expression: kalm_mpc_z.C
                                        * Referenced by: '<S45>/C'
                                        */
  real_T D_Value_j[2];                 /* Expression: kalm_mpc_z.D
                                        * Referenced by: '<S45>/D'
                                        */
  real_T Q_Value_j[9];                 /* Expression: kalm_mpc_z.Q
                                        * Referenced by: '<S45>/Q'
                                        */
  real_T R_Value_c[4];                 /* Expression: kalm_mpc_z.R
                                        * Referenced by: '<S45>/R'
                                        */
  real_T UnitDelay1_X0_c[9];           /* Expression: kalm_mpc_z.P
                                        * Referenced by: '<S45>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_c;         /* Expression: 0.0
                                        * Referenced by: '<S56>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_i[30];            /* Expression: FG_ctrl_z.V_max
                                        * Referenced by: '<S44>/V_max'
                                        */
  real_T i_min_Value_o;                /* Expression: FG_ctrl_z.i_min
                                        * Referenced by: '<S44>/i_min'
                                        */
  real_T betas_Value_g[8];             /* Expression: FG_ctrl_z.betas
                                        * Referenced by: '<S44>/betas'
                                        */
  real_T L_Value_m;                    /* Expression: FG_ctrl_z.L
                                        * Referenced by: '<S44>/L'
                                        */
  real_T UnitDelay_X0_a[2];            /* Expression: zeros(FG_ctrl_z.delay_steps,1)
                                        * Referenced by: '<S44>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_b[30];          /* Expression: zeros(size(FG_ctrl_z.V_max,1),1)
                                        * Referenced by: '<S44>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: MAX_BIAS_THRUST
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -MAX_BIAS_THRUST
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real_T TT_PP_Value_o[900];           /* Expression: FG_ctrl_yaw.TT_PP
                                        * Referenced by: '<S42>/TT_PP'
                                        */
  real_T LL_PP_Value_j5[60];           /* Expression: FG_ctrl_yaw.LL_PP
                                        * Referenced by: '<S42>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_e[1860];      /* Expression: FG_ctrl_yaw.LL_ref_PP
                                        * Referenced by: '<S42>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_b[900];     /* Expression: FG_ctrl_yaw.LL_U_ref_PP
                                        * Referenced by: '<S42>/LL_U_ref_PP'
                                        */
  real_T MM_Value_g[4];                /* Expression: FG_ctrl_yaw.MM
                                        * Referenced by: '<S42>/MM'
                                        */
  real_T PP_Value_p[900];              /* Expression: FG_ctrl_yaw.PP
                                        * Referenced by: '<S42>/PP'
                                        */
  real_T AA_delay_Value_o[4];          /* Expression: FG_ctrl_yaw.AA_delay
                                        * Referenced by: '<S42>/AA_delay'
                                        */
  real_T BB_delay_Value_d[12];         /* Expression: FG_ctrl_yaw.BB_delay
                                        * Referenced by: '<S42>/BB_delay'
                                        */
  real_T A_Value_k[9];                 /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S43>/A'
                                        */
  real_T B_Value_f[3];                 /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S43>/B'
                                        */
  real_T C_Value_b[6];                 /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S43>/C'
                                        */
  real_T D_Value_c[2];                 /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S43>/D'
                                        */
  real_T Q_Value_g[9];                 /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S43>/Q'
                                        */
  real_T R_Value_o[4];                 /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S43>/R'
                                        */
  real_T UnitDelay1_X0_n[9];           /* Expression: kalm_mpc_yaw.P
                                        * Referenced by: '<S43>/Unit Delay1'
                                        */
  real_T FixPtUnitDelay1_X0_e;         /* Expression: 0.0
                                        * Referenced by: '<S53>/FixPt Unit Delay1'
                                        */
  real_T V_max_Value_f[30];            /* Expression: FG_ctrl_yaw.V_max
                                        * Referenced by: '<S42>/V_max'
                                        */
  real_T i_min_Value_n;                /* Expression: FG_ctrl_yaw.i_min
                                        * Referenced by: '<S42>/i_min'
                                        */
  real_T betas_Value_j[5];             /* Expression: FG_ctrl_yaw.betas
                                        * Referenced by: '<S42>/betas'
                                        */
  real_T L_Value_g;                    /* Expression: FG_ctrl_yaw.L
                                        * Referenced by: '<S42>/L'
                                        */
  real_T UnitDelay_X0_f[6];            /* Expression: zeros(FG_ctrl_yaw.delay_steps,1)
                                        * Referenced by: '<S42>/Unit Delay'
                                        */
  real_T UnitDelay1_X0_o[30];          /* Expression: zeros(size(FG_ctrl_yaw.V_max,1),1)
                                        * Referenced by: '<S42>/Unit Delay1'
                                        */
  real_T Saturation_UpperSat_o3;       /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S43>/Saturation'
                                        */
  real_T Saturation_LowerSat_kn;       /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S43>/Saturation'
                                        */
  real_T g_Value_m;                    /* Expression: g
                                        * Referenced by: '<S58>/g'
                                        */
  real_T raddeg2_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S36>/rad -> deg2'
                                        */
  real_T raddeg1_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S36>/rad -> deg1'
                                        */
  real_T raddeg3_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S36>/rad -> deg3'
                                        */
  real_T raddeg_Gain;                  /* Expression: 180/pi
                                        * Referenced by: '<S36>/rad -> deg'
                                        */
  real_T pitch_offset_Value;           /* Expression: 0.00
                                        * Referenced by: '<S5>/pitch_offset'
                                        */
  real_T InitialCondition_Value;       /* Expression: vinit
                                        * Referenced by: '<S31>/Initial Condition'
                                        */
  real_T Constant1_Value_m;            /* Expression: 1
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant2_Value_a;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T FixPtUnitDelay1_X0_h;         /* Expression: vinit
                                        * Referenced by: '<S31>/FixPt Unit Delay1'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T pitch_cmd2pitch_Gain;         /* Expression: pitch_cmd2pitch_1stOrd
                                        * Referenced by: '<S5>/pitch_cmd2pitch'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1.0
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T roll_offset_Value;            /* Expression: 0.00
                                        * Referenced by: '<S5>/roll_offset'
                                        */
  real_T roll_cmd2roll_Gain;           /* Expression: roll_cmd2roll_1stOrd
                                        * Referenced by: '<S5>/roll_cmd2roll'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T gravity_Value_ch;             /* Expression: g
                                        * Referenced by: '<S5>/gravity'
                                        */
  real_T trhust_cmd2thrust_Gain;       /* Expression: thrust_cmd2thrust_0thOrd
                                        * Referenced by: '<S5>/trhust_cmd2thrust'
                                        */
  real_T Gain_Gain;                    /* Expression: THRUST_CMD_GAIN
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1.0
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1.0
                                        * Referenced by: '<S5>/Gain4'
                                        */
  uint32_T IntegerDelay_DelayLength;   /* Computed Parameter: IntegerDelay_DelayLength
                                        * Referenced by: '<S32>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength;  /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S32>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength;  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S32>/Integer Delay2'
                                        */
  uint32_T IntegerDelay3_DelayLength;  /* Computed Parameter: IntegerDelay3_DelayLength
                                        * Referenced by: '<S32>/Integer Delay3'
                                        */
  uint8_T FixPtUnitDelay2_X0;          /* Computed Parameter: FixPtUnitDelay2_X0
                                        * Referenced by: '<S47>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_n;        /* Computed Parameter: FixPtUnitDelay2_X0_n
                                        * Referenced by: '<S50>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_d;        /* Computed Parameter: FixPtUnitDelay2_X0_d
                                        * Referenced by: '<S56>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtUnitDelay2_X0_i;        /* Computed Parameter: FixPtUnitDelay2_X0_i
                                        * Referenced by: '<S53>/FixPt Unit Delay2'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S47>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_o;       /* Computed Parameter: FixPtConstant_Value_o
                                        * Referenced by: '<S50>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_n;       /* Computed Parameter: FixPtConstant_Value_n
                                        * Referenced by: '<S53>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_p;       /* Computed Parameter: FixPtConstant_Value_p
                                        * Referenced by: '<S56>/FixPt Constant'
                                        */
  uint8_T FixPtUnitDelay2_X0_g;        /* Computed Parameter: FixPtUnitDelay2_X0_g
                                        * Referenced by: '<S31>/FixPt Unit Delay2'
                                        */
  uint8_T Constant_Value_a3;           /* Expression: uint8(1)
                                        * Referenced by: '<S30>/Constant'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(0)
                                        * Referenced by: '<S30>/SwitchControl'
                                        */
  uint8_T FixPtConstant_Value_i;       /* Computed Parameter: FixPtConstant_Value_i
                                        * Referenced by: '<S31>/FixPt Constant'
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
 * '<S4>'   : 'controller_template/Mode Handling'
 * '<S5>'   : 'controller_template/convert2cmd'
 * '<S6>'   : 'controller_template/delay'
 * '<S7>'   : 'controller_template/pos controller'
 * '<S8>'   : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1'
 * '<S9>'   : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation'
 * '<S10>'  : 'controller_template/FreeFlight Pos Ctrl/get ref from vector'
 * '<S11>'  : 'controller_template/FreeFlight Pos Ctrl/rotate to world frame'
 * '<S12>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/demux'
 * '<S13>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S14>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S15>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S16>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S17>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1'
 * '<S18>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/x controller MPC FG  /Explicit Ctrl1/Ctrl_Xdir'
 * '<S19>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1'
 * '<S20>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/y controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S21>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1'
 * '<S22>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/yaw controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S23>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1'
 * '<S24>'  : 'controller_template/FreeFlight Pos Ctrl/MAIN CONTROL LOOP1/z controller MPC FG/Explicit Ctrl1/Ctrl_Xdir'
 * '<S25>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling '
 * '<S26>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame'
 * '<S27>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S28>'  : 'controller_template/FreeFlight Pos Ctrl/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S29>'  : 'controller_template/FreeFlight Pos Ctrl/rotate to world frame/Embedded MATLAB Function'
 * '<S30>'  : 'controller_template/convert2cmd/Manual Switch'
 * '<S31>'  : 'controller_template/delay/delay bias'
 * '<S32>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1'
 * '<S33>'  : 'controller_template/pos controller/decoupling and rotation'
 * '<S34>'  : 'controller_template/pos controller/get ref from vector'
 * '<S35>'  : 'controller_template/pos controller/rotate to world frame'
 * '<S36>'  : 'controller_template/pos controller/view & log signals'
 * '<S37>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/demux'
 * '<S38>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S39>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias'
 * '<S40>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S41>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias'
 * '<S42>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S43>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S44>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S45>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias'
 * '<S46>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  /runFastGradient'
 * '<S47>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/Unit Delay External IC1'
 * '<S48>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/discrete kalman filter'
 * '<S49>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG/runFastGradient'
 * '<S50>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/Unit Delay External IC1'
 * '<S51>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/discrete kalman filter'
 * '<S52>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG/runFastGradient'
 * '<S53>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S54>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S55>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG/runFastGradient'
 * '<S56>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/Unit Delay External IC1'
 * '<S57>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/discrete kalman filter'
 * '<S58>'  : 'controller_template/pos controller/decoupling and rotation/decoupling '
 * '<S59>'  : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame'
 * '<S60>'  : 'controller_template/pos controller/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S61>'  : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S62>'  : 'controller_template/pos controller/rotate to world frame/Embedded MATLAB Function'
 */
#endif                                 /* RTW_HEADER_controller_template_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
