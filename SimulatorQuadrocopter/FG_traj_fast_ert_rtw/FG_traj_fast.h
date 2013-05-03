/*
 * File: FG_traj_fast.h
 *
 * Code generated for Simulink model 'FG_traj_fast'.
 *
 * Model version                  : 1.362
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Thu May  2 14:33:59 2013
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FG_traj_fast_h_
#define RTW_HEADER_FG_traj_fast_h_
#ifndef FG_traj_fast_COMMON_INCLUDES_
# define FG_traj_fast_COMMON_INCLUDES_
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <float.h>
#include <math.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* FG_traj_fast_COMMON_INCLUDES_ */

#include "FG_traj_fast_types.h"

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

/* Block signals for system '<S15>/runFastGradient' */
typedef struct {
  real_T u_opt;                        /* '<S15>/runFastGradient' */
  real_T u_buff_out[3];                /* '<S15>/runFastGradient' */
  real_T V_init_out[30];               /* '<S15>/runFastGradient' */
} rtB_runFastGradient_FG_traj_fas;

/* Block signals for system '<S16>/discrete kalman filter' */
typedef struct {
  real_T state_est[4];                 /* '<S16>/discrete kalman filter' */
  real_T P_est[16];                    /* '<S16>/discrete kalman filter' */
} rtB_discretekalmanfilter_FG_tra;

/* Block signals for system '<S20>/discrete kalman filter' */
typedef struct {
  real_T state_est[3];                 /* '<S20>/discrete kalman filter' */
  real_T P_est[9];                     /* '<S20>/discrete kalman filter' */
} rtB_discretekalmanfilter_FG_t_p;

/* Block signals for system '<S6>/MAIN CONTROL LOOP1' */
typedef struct {
  real_T Saturation;                   /* '<S16>/Saturation' */
  real_T pitch_cmd;                    /* '<S9>/Sum' */
  real_T Saturation_l;                 /* '<S18>/Saturation' */
  real_T roll_cmd;                     /* '<S9>/Sum1' */
  real_T Saturation_p;                 /* '<S22>/Saturation' */
  real_T Saturation_c;                 /* '<S20>/Saturation' */
  real_T yaw_rate_cmd;                 /* '<S9>/Sum3' */
  real_T thrust_cmd;                   /* '<S9>/Sum5' */
  rtB_discretekalmanfilter_FG_t_p sf_discretekalmanfilter_d;/* '<S22>/discrete kalman filter' */
  rtB_discretekalmanfilter_FG_t_p sf_discretekalmanfilter_j;/* '<S20>/discrete kalman filter' */
  rtB_discretekalmanfilter_FG_tra sf_discretekalmanfilter_n;/* '<S18>/discrete kalman filter' */
  rtB_runFastGradient_FG_traj_fas sf_runFastGradient_a;/* '<S17>/runFastGradient' */
  rtB_discretekalmanfilter_FG_tra sf_discretekalmanfilter;/* '<S16>/discrete kalman filter' */
  rtB_runFastGradient_FG_traj_fas sf_runFastGradient;/* '<S15>/runFastGradient' */
} rtB_MAINCONTROLLOOP1_FG_traj_fa;

/* Block states (auto storage) for system '<S6>/MAIN CONTROL LOOP1' */
typedef struct {
  real_T IntegerDelay_DSTATE;          /* '<S9>/Integer Delay' */
  real_T IntegerDelay1_DSTATE;         /* '<S9>/Integer Delay1' */
  real_T IntegerDelay2_DSTATE;         /* '<S9>/Integer Delay2' */
  real_T IntegerDelay3_DSTATE;         /* '<S9>/Integer Delay3' */
  real_T UnitDelay1_DSTATE[16];        /* '<S16>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE[3];    /* '<S24>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE[3];          /* '<S15>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f[30];      /* '<S15>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_m[16];      /* '<S18>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_g[3];  /* '<S27>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_p[3];        /* '<S17>/Unit Delay' */
  real_T UnitDelay1_DSTATE_mi[30];     /* '<S17>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_c[9];       /* '<S22>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_j[2];  /* '<S33>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_d[2];        /* '<S21>/Unit Delay' */
  real_T UnitDelay1_DSTATE_j[30];      /* '<S21>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_h[9];       /* '<S20>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_p[2];  /* '<S30>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_j[6];        /* '<S19>/Unit Delay' */
  real_T UnitDelay1_DSTATE_p[30];      /* '<S19>/Unit Delay1' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S24>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_f;    /* '<S27>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_h;    /* '<S33>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_g;    /* '<S30>/FixPt Unit Delay2' */
} rtDW_MAINCONTROLLOOP1_FG_traj_f;

/* Block signals for system '<S12>/Embedded MATLAB Function' */
typedef struct {
  real_T roll_rot;                     /* '<S12>/Embedded MATLAB Function' */
  real_T pitch_rot;                    /* '<S12>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S12>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S12>/Embedded MATLAB Function' */
} rtB_EmbeddedMATLABFunction_FG_t;

/* Block signals (auto storage) */
typedef struct {
  real_T DataTypeConversion[30];       /* '<S1>/Data Type Conversion' */
  real_T X_ref_x[93];                  /* '<Root>/Data Type Conversion2' */
  real_T X_ref_y[93];                  /* '<Root>/Data Type Conversion3' */
  real_T X_ref_z[62];                  /* '<Root>/Data Type Conversion1' */
  real_T X_ref_yaw[62];                /* '<Root>/Data Type Conversion' */
  real_T MultiportSwitch;              /* '<S3>/Multiport Switch' */
  real_T pitch_cmd;                    /* '<Root>/Switch1' */
  real_T roll_cmd;                     /* '<Root>/Switch1' */
  real_T thrust_cmd;                   /* '<Root>/Switch1' */
  real_T yaw_rate_cmd;                 /* '<Root>/Switch1' */
  real_T pitch_bias;                   /* '<Root>/Switch1' */
  real_T roll_bias;                    /* '<Root>/Switch1' */
  real_T thrust_bias;                  /* '<Root>/Switch1' */
  real_T yaw_rate_bias;                /* '<Root>/Switch1' */
  real_T raddeg2[3];                   /* '<S44>/rad -> deg2' */
  real_T raddeg1[3];                   /* '<S44>/rad -> deg1' */
  real_T raddeg3[3];                   /* '<S44>/rad -> deg3' */
  real_T raddeg[4];                    /* '<S44>/rad -> deg' */
  real_T bias_W[4];                    /* '<S41>/bias_W' */
  real_T cmd_W[4];                     /* '<S41>/cmd_W' */
  real_T pitch_rot;                    /* '<S67>/Embedded MATLAB Function' */
  real_T roll_rot;                     /* '<S67>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S67>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S67>/Embedded MATLAB Function' */
  real_T thrust_comp;                  /* '<S66>/Embedded MATLAB Function' */
  real_T raddeg2_g[3];                 /* '<S13>/rad -> deg2' */
  real_T raddeg1_i[3];                 /* '<S13>/rad -> deg1' */
  real_T raddeg3_g[3];                 /* '<S13>/rad -> deg3' */
  real_T raddeg_e[4];                  /* '<S13>/rad -> deg' */
  real_T bias_W_k[4];                  /* '<S10>/bias_W' */
  real_T cmd_W_c[4];                   /* '<S10>/cmd_W' */
  real_T pitch_rot_f;                  /* '<S36>/Embedded MATLAB Function' */
  real_T roll_rot_c;                   /* '<S36>/Embedded MATLAB Function' */
  real_T pitch_bias_rot_j;             /* '<S36>/Embedded MATLAB Function' */
  real_T roll_bias_rot_g;              /* '<S36>/Embedded MATLAB Function' */
  real_T thrust_comp_c;                /* '<S35>/Embedded MATLAB Function' */
  rtB_EmbeddedMATLABFunction_FG_t sf_EmbeddedMATLABFunction_j;/* '<S43>/Embedded MATLAB Function' */
  rtB_MAINCONTROLLOOP1_FG_traj_fa MAINCONTROLLOOP1_c;/* '<S7>/MAIN CONTROL LOOP1' */
  rtB_EmbeddedMATLABFunction_FG_t sf_EmbeddedMATLABFunction;/* '<S12>/Embedded MATLAB Function' */
  rtB_MAINCONTROLLOOP1_FG_traj_fa MAINCONTROLLOOP1;/* '<S6>/MAIN CONTROL LOOP1' */
} BlockIO_FG_traj_fast;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T FixPtUnitDelay1_DSTATE[4];    /* '<S8>/FixPt Unit Delay1' */
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
  } mode1_PWORK_k;                     /* '<S7>/mode1' */

  struct {
    void *FilePtr;
  } ToFile_PWORK;                      /* '<S44>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<S44>/To File1' */

  struct {
    void *LoggedData;
  } pitchcmd_PWORK;                    /* '<S44>/pitch cmd' */

  struct {
    void *LoggedData;
  } rollcmd_PWORK;                     /* '<S44>/roll cmd' */

  struct {
    void *LoggedData;
  } thrustcmd_PWORK;                   /* '<S44>/thrust cmd' */

  struct {
    void *LoggedData;
  } x_ref_PWORK;                       /* '<S44>/x_ref' */

  struct {
    void *LoggedData;
  } y_ref_PWORK;                       /* '<S44>/y_ref' */

  struct {
    void *LoggedData;
  } yawcmd_PWORK;                      /* '<S44>/yaw cmd' */

  struct {
    void *LoggedData;
  } yaw_ref_PWORK;                     /* '<S44>/yaw_ref' */

  struct {
    void *LoggedData;
  } z_ref_PWORK;                       /* '<S44>/z_ref' */

  struct {
    void *LoggedData;
  } mode1_PWORK_n;                     /* '<S6>/mode1' */

  struct {
    void *FilePtr;
  } ToFile_PWORK_d;                    /* '<S13>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK_c;                   /* '<S13>/To File1' */

  struct {
    void *LoggedData;
  } pitchcmd_PWORK_f;                  /* '<S13>/pitch cmd' */

  struct {
    void *LoggedData;
  } rollcmd_PWORK_m;                   /* '<S13>/roll cmd' */

  struct {
    void *LoggedData;
  } thrustcmd_PWORK_i;                 /* '<S13>/thrust cmd' */

  struct {
    void *LoggedData;
  } x_ref_PWORK_n;                     /* '<S13>/x_ref' */

  struct {
    void *LoggedData;
  } y_ref_PWORK_f;                     /* '<S13>/y_ref' */

  struct {
    void *LoggedData;
  } yawcmd_PWORK_p;                    /* '<S13>/yaw cmd' */

  struct {
    void *LoggedData;
  } yaw_ref_PWORK_g;                   /* '<S13>/yaw_ref' */

  struct {
    void *LoggedData;
  } z_ref_PWORK_m;                     /* '<S13>/z_ref' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<S44>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<S44>/To File1' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK_n;                    /* '<S13>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK_d;                   /* '<S13>/To File1' */

  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S8>/FixPt Unit Delay2' */
  int8_T poscontroller1_SubsysRanBC;   /* '<Root>/pos controller1' */
  int8_T poscontroller_SubsysRanBC;    /* '<Root>/pos controller' */
  boolean_T poscontroller1_MODE;       /* '<Root>/pos controller1' */
  boolean_T poscontroller_MODE;        /* '<Root>/pos controller' */
  rtDW_MAINCONTROLLOOP1_FG_traj_f MAINCONTROLLOOP1_c;/* '<S7>/MAIN CONTROL LOOP1' */
  rtDW_MAINCONTROLLOOP1_FG_traj_f MAINCONTROLLOOP1;/* '<S6>/MAIN CONTROL LOOP1' */
} D_Work_FG_traj_fast;

/* Parameters for system: '<S6>/MAIN CONTROL LOOP1' */
struct rtP_MAINCONTROLLOOP1_FG_traj_fa_ {
  real_T IntegerDelay_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<S9>/Integer Delay'
                                        */
  real_T IntegerDelay1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S9>/Integer Delay1'
                                         */
  real_T IntegerDelay2_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S9>/Integer Delay2'
                                         */
  real_T IntegerDelay3_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S9>/Integer Delay3'
                                         */
  real_T gravity_Value;                /* Expression: g
                                        * Referenced by: '<S9>/gravity'
                                        */
  real_T TT_PP_Value[900];             /* Expression: FG_ctrl_x.TT_PP
                                        * Referenced by: '<S15>/TT_PP'
                                        */
  real_T LL_PP_Value[90];              /* Expression: FG_ctrl_x.LL_PP
                                        * Referenced by: '<S15>/LL_PP'
                                        */
  real_T LL_ref_PP_Value[2790];        /* Expression: FG_ctrl_x.LL_ref_PP
                                        * Referenced by: '<S15>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value[900];       /* Expression: FG_ctrl_x.LL_U_ref_PP
                                        * Referenced by: '<S15>/LL_U_ref_PP'
                                        */
  real_T MM_Value[9];                  /* Expression: FG_ctrl_x.MM
                                        * Referenced by: '<S15>/MM'
                                        */
  real_T PP_Value[900];                /* Expression: FG_ctrl_x.PP
                                        * Referenced by: '<S15>/PP'
                                        */
  real_T AA_delay_Value[9];            /* Expression: FG_ctrl_x.AA_delay
                                        * Referenced by: '<S15>/AA_delay'
                                        */
  real_T BB_delay_Value[9];            /* Expression: FG_ctrl_x.BB_delay
                                        * Referenced by: '<S15>/BB_delay'
                                        */
  real_T A_Value[16];                  /* Expression: kalm_mpc_x.A
                                        * Referenced by: '<S16>/A'
                                        */
  real_T B_Value[4];                   /* Expression: kalm_mpc_x.B
                                        * Referenced by: '<S16>/B'
                                        */
  real_T C_Value[12];                  /* Expression: kalm_mpc_x.C
                                        * Referenced by: '<S16>/C'
                                        */
  real_T D_Value[3];                   /* Expression: kalm_mpc_x.D
                                        * Referenced by: '<S16>/D'
                                        */
  real_T Q_Value[16];                  /* Expression: kalm_mpc_x.Q
                                        * Referenced by: '<S16>/Q'
                                        */
  real_T R_Value[9];                   /* Expression: kalm_mpc_x.R
                                        * Referenced by: '<S16>/R'
                                        */
  real_T UnitDelay1_InitialCondition[16];/* Expression: kalm_mpc_x.P
                                          * Referenced by: '<S16>/Unit Delay1'
                                          */
  real_T FixPtUnitDelay1_InitialConditio;/* Expression: 0.0
                                          * Referenced by: '<S24>/FixPt Unit Delay1'
                                          */
  real_T V_max_Value[30];              /* Expression: FG_ctrl_x.V_max
                                        * Referenced by: '<S15>/V_max'
                                        */
  real_T i_min_Value;                  /* Expression: FG_ctrl_x.i_min
                                        * Referenced by: '<S15>/i_min'
                                        */
  real_T betas_Value[7];               /* Expression: FG_ctrl_x.betas
                                        * Referenced by: '<S15>/betas'
                                        */
  real_T L_Value;                      /* Expression: FG_ctrl_x.L
                                        * Referenced by: '<S15>/L'
                                        */
  real_T UnitDelay_InitialCondition[3];/* Expression: zeros(FG_ctrl_x.delay_steps,1)
                                        * Referenced by: '<S15>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition_h[30];/* Expression: zeros(size(FG_ctrl_x.V_max,1),1)
                                            * Referenced by: '<S15>/Unit Delay1'
                                            */
  real_T Saturation_UpperSat;          /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T TT_PP_Value_n[900];           /* Expression: FG_ctrl_y.TT_PP
                                        * Referenced by: '<S17>/TT_PP'
                                        */
  real_T LL_PP_Value_h[90];            /* Expression: FG_ctrl_y.LL_PP
                                        * Referenced by: '<S17>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_l[2790];      /* Expression: FG_ctrl_y.LL_ref_PP
                                        * Referenced by: '<S17>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_h[900];     /* Expression: FG_ctrl_y.LL_U_ref_PP
                                        * Referenced by: '<S17>/LL_U_ref_PP'
                                        */
  real_T MM_Value_n[9];                /* Expression: FG_ctrl_y.MM
                                        * Referenced by: '<S17>/MM'
                                        */
  real_T PP_Value_a[900];              /* Expression: FG_ctrl_y.PP
                                        * Referenced by: '<S17>/PP'
                                        */
  real_T AA_delay_Value_j[9];          /* Expression: FG_ctrl_y.AA_delay
                                        * Referenced by: '<S17>/AA_delay'
                                        */
  real_T BB_delay_Value_c[9];          /* Expression: FG_ctrl_y.BB_delay
                                        * Referenced by: '<S17>/BB_delay'
                                        */
  real_T A_Value_g[16];                /* Expression: kalm_mpc_y.A
                                        * Referenced by: '<S18>/A'
                                        */
  real_T B_Value_f[4];                 /* Expression: kalm_mpc_y.B
                                        * Referenced by: '<S18>/B'
                                        */
  real_T C_Value_m[12];                /* Expression: kalm_mpc_y.C
                                        * Referenced by: '<S18>/C'
                                        */
  real_T D_Value_f[3];                 /* Expression: kalm_mpc_y.D
                                        * Referenced by: '<S18>/D'
                                        */
  real_T Q_Value_h[16];                /* Expression: kalm_mpc_y.Q
                                        * Referenced by: '<S18>/Q'
                                        */
  real_T R_Value_e[9];                 /* Expression: kalm_mpc_y.R
                                        * Referenced by: '<S18>/R'
                                        */
  real_T UnitDelay1_InitialCondition_b[16];/* Expression: kalm_mpc_y.P
                                            * Referenced by: '<S18>/Unit Delay1'
                                            */
  real_T FixPtUnitDelay1_InitialCondit_m;/* Expression: 0.0
                                          * Referenced by: '<S27>/FixPt Unit Delay1'
                                          */
  real_T V_max_Value_g[30];            /* Expression: FG_ctrl_y.V_max
                                        * Referenced by: '<S17>/V_max'
                                        */
  real_T i_min_Value_l;                /* Expression: FG_ctrl_y.i_min
                                        * Referenced by: '<S17>/i_min'
                                        */
  real_T betas_Value_m[7];             /* Expression: FG_ctrl_y.betas
                                        * Referenced by: '<S17>/betas'
                                        */
  real_T L_Value_g;                    /* Expression: FG_ctrl_y.L
                                        * Referenced by: '<S17>/L'
                                        */
  real_T UnitDelay_InitialCondition_n[3];/* Expression: zeros(FG_ctrl_y.delay_steps,1)
                                          * Referenced by: '<S17>/Unit Delay'
                                          */
  real_T UnitDelay1_InitialCondition_o[30];/* Expression: zeros(size(FG_ctrl_y.V_max,1),1)
                                            * Referenced by: '<S17>/Unit Delay1'
                                            */
  real_T Saturation_UpperSat_f;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S18>/Saturation'
                                        */
  real_T TT_PP_Value_e[900];           /* Expression: FG_ctrl_z.TT_PP
                                        * Referenced by: '<S21>/TT_PP'
                                        */
  real_T LL_PP_Value_l[60];            /* Expression: FG_ctrl_z.LL_PP
                                        * Referenced by: '<S21>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_d[1860];      /* Expression: FG_ctrl_z.LL_ref_PP
                                        * Referenced by: '<S21>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_k[900];     /* Expression: FG_ctrl_z.LL_U_ref_PP
                                        * Referenced by: '<S21>/LL_U_ref_PP'
                                        */
  real_T MM_Value_i[4];                /* Expression: FG_ctrl_z.MM
                                        * Referenced by: '<S21>/MM'
                                        */
  real_T PP_Value_m[900];              /* Expression: FG_ctrl_z.PP
                                        * Referenced by: '<S21>/PP'
                                        */
  real_T AA_delay_Value_f[4];          /* Expression: FG_ctrl_z.AA_delay
                                        * Referenced by: '<S21>/AA_delay'
                                        */
  real_T BB_delay_Value_n[4];          /* Expression: FG_ctrl_z.BB_delay
                                        * Referenced by: '<S21>/BB_delay'
                                        */
  real_T A_Value_e[9];                 /* Expression: kalm_mpc_z.A
                                        * Referenced by: '<S22>/A'
                                        */
  real_T B_Value_k[3];                 /* Expression: kalm_mpc_z.B
                                        * Referenced by: '<S22>/B'
                                        */
  real_T C_Value_p[6];                 /* Expression: kalm_mpc_z.C
                                        * Referenced by: '<S22>/C'
                                        */
  real_T D_Value_k[2];                 /* Expression: kalm_mpc_z.D
                                        * Referenced by: '<S22>/D'
                                        */
  real_T Q_Value_g[9];                 /* Expression: kalm_mpc_z.Q
                                        * Referenced by: '<S22>/Q'
                                        */
  real_T R_Value_c[4];                 /* Expression: kalm_mpc_z.R
                                        * Referenced by: '<S22>/R'
                                        */
  real_T UnitDelay1_InitialCondition_ou[9];/* Expression: kalm_mpc_z.P
                                            * Referenced by: '<S22>/Unit Delay1'
                                            */
  real_T FixPtUnitDelay1_InitialCondit_p;/* Expression: 0.0
                                          * Referenced by: '<S33>/FixPt Unit Delay1'
                                          */
  real_T V_max_Value_a[30];            /* Expression: FG_ctrl_z.V_max
                                        * Referenced by: '<S21>/V_max'
                                        */
  real_T i_min_Value_p;                /* Expression: FG_ctrl_z.i_min
                                        * Referenced by: '<S21>/i_min'
                                        */
  real_T betas_Value_o[8];             /* Expression: FG_ctrl_z.betas
                                        * Referenced by: '<S21>/betas'
                                        */
  real_T L_Value_j;                    /* Expression: FG_ctrl_z.L
                                        * Referenced by: '<S21>/L'
                                        */
  real_T UnitDelay_InitialCondition_f[2];/* Expression: zeros(FG_ctrl_z.delay_steps,1)
                                          * Referenced by: '<S21>/Unit Delay'
                                          */
  real_T UnitDelay1_InitialCondition_m[30];/* Expression: zeros(size(FG_ctrl_z.V_max,1),1)
                                            * Referenced by: '<S21>/Unit Delay1'
                                            */
  real_T Saturation_UpperSat_j;        /* Expression: MAX_BIAS_THRUST
                                        * Referenced by: '<S22>/Saturation'
                                        */
  real_T Saturation_LowerSat_cp;       /* Expression: -MAX_BIAS_THRUST
                                        * Referenced by: '<S22>/Saturation'
                                        */
  real_T TT_PP_Value_ew[900];          /* Expression: FG_ctrl_yaw.TT_PP
                                        * Referenced by: '<S19>/TT_PP'
                                        */
  real_T LL_PP_Value_o[60];            /* Expression: FG_ctrl_yaw.LL_PP
                                        * Referenced by: '<S19>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_b[1860];      /* Expression: FG_ctrl_yaw.LL_ref_PP
                                        * Referenced by: '<S19>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_g[900];     /* Expression: FG_ctrl_yaw.LL_U_ref_PP
                                        * Referenced by: '<S19>/LL_U_ref_PP'
                                        */
  real_T MM_Value_m[4];                /* Expression: FG_ctrl_yaw.MM
                                        * Referenced by: '<S19>/MM'
                                        */
  real_T PP_Value_i[900];              /* Expression: FG_ctrl_yaw.PP
                                        * Referenced by: '<S19>/PP'
                                        */
  real_T AA_delay_Value_e[4];          /* Expression: FG_ctrl_yaw.AA_delay
                                        * Referenced by: '<S19>/AA_delay'
                                        */
  real_T BB_delay_Value_j[12];         /* Expression: FG_ctrl_yaw.BB_delay
                                        * Referenced by: '<S19>/BB_delay'
                                        */
  real_T A_Value_gk[9];                /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S20>/A'
                                        */
  real_T B_Value_ke[3];                /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S20>/B'
                                        */
  real_T C_Value_c[6];                 /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S20>/C'
                                        */
  real_T D_Value_h[2];                 /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S20>/D'
                                        */
  real_T Q_Value_n[9];                 /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S20>/Q'
                                        */
  real_T R_Value_k[4];                 /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S20>/R'
                                        */
  real_T UnitDelay1_InitialCondition_oo[9];/* Expression: kalm_mpc_yaw.P
                                            * Referenced by: '<S20>/Unit Delay1'
                                            */
  real_T FixPtUnitDelay1_InitialCondit_k;/* Expression: 0.0
                                          * Referenced by: '<S30>/FixPt Unit Delay1'
                                          */
  real_T V_max_Value_h[30];            /* Expression: FG_ctrl_yaw.V_max
                                        * Referenced by: '<S19>/V_max'
                                        */
  real_T i_min_Value_a;                /* Expression: FG_ctrl_yaw.i_min
                                        * Referenced by: '<S19>/i_min'
                                        */
  real_T betas_Value_o5[5];            /* Expression: FG_ctrl_yaw.betas
                                        * Referenced by: '<S19>/betas'
                                        */
  real_T L_Value_jd;                   /* Expression: FG_ctrl_yaw.L
                                        * Referenced by: '<S19>/L'
                                        */
  real_T UnitDelay_InitialCondition_k[6];/* Expression: zeros(FG_ctrl_yaw.delay_steps,1)
                                          * Referenced by: '<S19>/Unit Delay'
                                          */
  real_T UnitDelay1_InitialCondition_g[30];/* Expression: zeros(size(FG_ctrl_yaw.V_max,1),1)
                                            * Referenced by: '<S19>/Unit Delay1'
                                            */
  real_T Saturation_UpperSat_o;        /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S20>/Saturation'
                                        */
  uint32_T IntegerDelay_DelayLength;   /* Computed Parameter: IntegerDelay_DelayLength
                                        * Referenced by: '<S9>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength;  /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S9>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength;  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S9>/Integer Delay2'
                                        */
  uint32_T IntegerDelay3_DelayLength;  /* Computed Parameter: IntegerDelay3_DelayLength
                                        * Referenced by: '<S9>/Integer Delay3'
                                        */
  uint8_T FixPtUnitDelay2_InitialConditio;/* Computed Parameter: FixPtUnitDelay2_InitialConditio
                                           * Referenced by: '<S24>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtUnitDelay2_InitialCondit_d;/* Computed Parameter: FixPtUnitDelay2_InitialCondit_d
                                           * Referenced by: '<S27>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtUnitDelay2_InitialCondit_b;/* Computed Parameter: FixPtUnitDelay2_InitialCondit_b
                                           * Referenced by: '<S33>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtUnitDelay2_InitialCondit_i;/* Computed Parameter: FixPtUnitDelay2_InitialCondit_i
                                           * Referenced by: '<S30>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S24>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_p;       /* Computed Parameter: FixPtConstant_Value_p
                                        * Referenced by: '<S27>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_p5;      /* Computed Parameter: FixPtConstant_Value_p5
                                        * Referenced by: '<S30>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_j;       /* Computed Parameter: FixPtConstant_Value_j
                                        * Referenced by: '<S33>/FixPt Constant'
                                        */
};

/* Parameters (auto storage) */
struct Parameters_FG_traj_fast_ {
  real_T yaw_rate_bias_Value;          /* Expression: 0
                                        * Referenced by: '<S2>/yaw_rate_bias'
                                        */
  real_T thrust_bias_Value;            /* Expression: 0
                                        * Referenced by: '<S2>/thrust_bias'
                                        */
  real_T roll_bias_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/roll_bias'
                                        */
  real_T pitch_bias_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/pitch_bias'
                                        */
  real_T yaw_Value;                    /* Expression: 0
                                        * Referenced by: '<S2>/yaw'
                                        */
  real_T gravity_Value;                /* Expression: -g
                                        * Referenced by: '<S2>/- gravity'
                                        */
  real_T roll_Value;                   /* Expression: 0
                                        * Referenced by: '<S2>/roll'
                                        */
  real_T pitch_Value;                  /* Expression: 0
                                        * Referenced by: '<S2>/pitch'
                                        */
  real_T g_Value;                      /* Expression: g
                                        * Referenced by: '<S35>/g'
                                        */
  real_T raddeg2_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S13>/rad -> deg2'
                                        */
  real_T raddeg1_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S13>/rad -> deg1'
                                        */
  real_T raddeg3_Gain;                 /* Expression: 180/pi
                                        * Referenced by: '<S13>/rad -> deg3'
                                        */
  real_T raddeg_Gain;                  /* Expression: 180/pi
                                        * Referenced by: '<S13>/rad -> deg'
                                        */
  real_T g_Value_c;                    /* Expression: g
                                        * Referenced by: '<S66>/g'
                                        */
  real_T raddeg2_Gain_p;               /* Expression: 180/pi
                                        * Referenced by: '<S44>/rad -> deg2'
                                        */
  real_T raddeg1_Gain_a;               /* Expression: 180/pi
                                        * Referenced by: '<S44>/rad -> deg1'
                                        */
  real_T raddeg3_Gain_m;               /* Expression: 180/pi
                                        * Referenced by: '<S44>/rad -> deg3'
                                        */
  real_T raddeg_Gain_b;                /* Expression: 180/pi
                                        * Referenced by: '<S44>/rad -> deg'
                                        */
  real_T pitch_offset_Value;           /* Expression: 0.00
                                        * Referenced by: '<S4>/pitch_offset'
                                        */
  real_T InitialCondition_Value;       /* Expression: vinit
                                        * Referenced by: '<S8>/Initial Condition'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T FixPtUnitDelay1_InitialConditio;/* Expression: vinit
                                          * Referenced by: '<S8>/FixPt Unit Delay1'
                                          */
  real_T pitch_cmd2pitch_Gain;         /* Expression: pitch_cmd2pitch_1stOrd
                                        * Referenced by: '<S4>/pitch_cmd2pitch'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1.0
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T roll_offset_Value;            /* Expression: 0.00
                                        * Referenced by: '<S4>/roll_offset'
                                        */
  real_T roll_cmd2roll_Gain;           /* Expression: roll_cmd2roll_1stOrd
                                        * Referenced by: '<S4>/roll_cmd2roll'
                                        */
  real_T Gain2_Gain;                   /* Expression: -1
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real_T gravity_Value_b;              /* Expression: g
                                        * Referenced by: '<S4>/gravity'
                                        */
  real_T trhust_cmd2thrust_Gain;       /* Expression: thrust_cmd2thrust_0thOrd
                                        * Referenced by: '<S4>/trhust_cmd2thrust'
                                        */
  real_T Gain_Gain;                    /* Expression: THRUST_CMD_GAIN
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1.0
                                        * Referenced by: '<S4>/Gain3'
                                        */
  real_T yaw_cmd2yaw_Gain;             /* Expression: yaw_cmd2yaw_1stOrd
                                        * Referenced by: '<S4>/yaw_cmd2yaw'
                                        */
  real_T yaw_rate_Value;               /* Expression: 0
                                        * Referenced by: '<S4>/yaw_rate'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1.0
                                        * Referenced by: '<S4>/Gain4'
                                        */
  uint8_T FixPtUnitDelay2_InitialConditio;/* Computed Parameter: FixPtUnitDelay2_InitialConditio
                                           * Referenced by: '<S8>/FixPt Unit Delay2'
                                           */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S4>/Manual Switch'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S8>/FixPt Constant'
                                        */
  rtP_MAINCONTROLLOOP1_FG_traj_fa MAINCONTROLLOOP1_c;/* '<S7>/MAIN CONTROL LOOP1' */
  rtP_MAINCONTROLLOOP1_FG_traj_fa MAINCONTROLLOOP1;/* '<S6>/MAIN CONTROL LOOP1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_FG_traj_fast {
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
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern Parameters_FG_traj_fast FG_traj_fast_P;

#ifdef __cplusplus

}
#endif

/* Block signals (auto storage) */
extern BlockIO_FG_traj_fast FG_traj_fast_B;

/* Block states (auto storage) */
extern D_Work_FG_traj_fast FG_traj_fast_DWork;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void FG_traj_initialize(void);
  extern void FG_traj_fast_terminate(void);

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

  extern RT_MODEL_FG_traj_fast *const FG_traj_fast_M;

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
 * '<Root>' : 'FG_traj_fast'
 * '<S1>'   : 'FG_traj_fast/AIR Parser'
 * '<S2>'   : 'FG_traj_fast/Idle cmd'
 * '<S3>'   : 'FG_traj_fast/Mode Handling'
 * '<S4>'   : 'FG_traj_fast/convert2cmd'
 * '<S5>'   : 'FG_traj_fast/delay'
 * '<S6>'   : 'FG_traj_fast/pos controller'
 * '<S7>'   : 'FG_traj_fast/pos controller1'
 * '<S8>'   : 'FG_traj_fast/delay/delay bias'
 * '<S9>'   : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1'
 * '<S10>'  : 'FG_traj_fast/pos controller/decoupling and rotation'
 * '<S11>'  : 'FG_traj_fast/pos controller/get ref from vector'
 * '<S12>'  : 'FG_traj_fast/pos controller/rotate to world frame'
 * '<S13>'  : 'FG_traj_fast/pos controller/view & log signals'
 * '<S14>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/demux'
 * '<S15>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S16>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/x states estimator bias'
 * '<S17>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S18>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/y states estimator bias'
 * '<S19>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S20>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S21>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S22>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/z states estimator bias'
 * '<S23>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  /runFastGradient'
 * '<S24>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/x states estimator bias/Unit Delay External IC1'
 * '<S25>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/x states estimator bias/discrete kalman filter'
 * '<S26>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/y controller MPC FG/runFastGradient'
 * '<S27>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/y states estimator bias/Unit Delay External IC1'
 * '<S28>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/y states estimator bias/discrete kalman filter'
 * '<S29>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG/runFastGradient'
 * '<S30>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S31>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S32>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/z controller MPC FG/runFastGradient'
 * '<S33>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/z states estimator bias/Unit Delay External IC1'
 * '<S34>'  : 'FG_traj_fast/pos controller/MAIN CONTROL LOOP1/z states estimator bias/discrete kalman filter'
 * '<S35>'  : 'FG_traj_fast/pos controller/decoupling and rotation/decoupling '
 * '<S36>'  : 'FG_traj_fast/pos controller/decoupling and rotation/rotate_to_quat_frame'
 * '<S37>'  : 'FG_traj_fast/pos controller/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S38>'  : 'FG_traj_fast/pos controller/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S39>'  : 'FG_traj_fast/pos controller/rotate to world frame/Embedded MATLAB Function'
 * '<S40>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1'
 * '<S41>'  : 'FG_traj_fast/pos controller1/decoupling and rotation'
 * '<S42>'  : 'FG_traj_fast/pos controller1/get ref from vector'
 * '<S43>'  : 'FG_traj_fast/pos controller1/rotate to world frame'
 * '<S44>'  : 'FG_traj_fast/pos controller1/view & log signals'
 * '<S45>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/demux'
 * '<S46>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S47>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/x states estimator bias'
 * '<S48>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S49>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/y states estimator bias'
 * '<S50>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S51>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S52>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S53>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/z states estimator bias'
 * '<S54>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/x controller MPC FG  /runFastGradient'
 * '<S55>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/x states estimator bias/Unit Delay External IC1'
 * '<S56>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/x states estimator bias/discrete kalman filter'
 * '<S57>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/y controller MPC FG/runFastGradient'
 * '<S58>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/y states estimator bias/Unit Delay External IC1'
 * '<S59>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/y states estimator bias/discrete kalman filter'
 * '<S60>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/yaw controller MPC FG/runFastGradient'
 * '<S61>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S62>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S63>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/z controller MPC FG/runFastGradient'
 * '<S64>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/z states estimator bias/Unit Delay External IC1'
 * '<S65>'  : 'FG_traj_fast/pos controller1/MAIN CONTROL LOOP1/z states estimator bias/discrete kalman filter'
 * '<S66>'  : 'FG_traj_fast/pos controller1/decoupling and rotation/decoupling '
 * '<S67>'  : 'FG_traj_fast/pos controller1/decoupling and rotation/rotate_to_quat_frame'
 * '<S68>'  : 'FG_traj_fast/pos controller1/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S69>'  : 'FG_traj_fast/pos controller1/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S70>'  : 'FG_traj_fast/pos controller1/rotate to world frame/Embedded MATLAB Function'
 */
#endif                                 /* RTW_HEADER_FG_traj_fast_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
