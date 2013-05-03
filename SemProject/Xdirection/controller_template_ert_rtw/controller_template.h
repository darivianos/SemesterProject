/*
 * File: controller_template.h
 *
 * Code generated for Simulink model 'controller_template'.
 *
 * Model version                  : 1.377
 * Simulink Coder version         : 8.4 (R2013a) 13-Feb-2013
 * TLC version                    : 8.4 (Jan 18 2013)
 * C/C++ source code generated on : Thu May  2 17:35:50 2013
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
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#endif                                 /* controller_template_COMMON_INCLUDES_ */

#include "controller_template_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include <math.h>

/* Block signals for system '<S25>/Embedded MATLAB Function' */
typedef struct {
  real_T pitch_cmd_comp;               /* '<S25>/Embedded MATLAB Function' */
  real_T roll_cmd_comp;                /* '<S25>/Embedded MATLAB Function' */
  real_T thrust_comp;                  /* '<S25>/Embedded MATLAB Function' */
} rtB_EmbeddedMATLABFunction_cont;

/* Block signals for system '<S26>/Embedded MATLAB Function' */
typedef struct {
  real_T pitch_rot;                    /* '<S26>/Embedded MATLAB Function' */
  real_T roll_rot;                     /* '<S26>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S26>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S26>/Embedded MATLAB Function' */
} rtB_EmbeddedMATLABFunction_co_g;

/* Block signals for system '<S11>/Embedded MATLAB Function' */
typedef struct {
  real_T roll_rot;                     /* '<S11>/Embedded MATLAB Function' */
  real_T pitch_rot;                    /* '<S11>/Embedded MATLAB Function' */
  real_T pitch_bias_rot;               /* '<S11>/Embedded MATLAB Function' */
  real_T roll_bias_rot;                /* '<S11>/Embedded MATLAB Function' */
} rtB_EmbeddedMATLABFunction_co_c;

/* Block signals for system '<S37>/runFastGradient' */
typedef struct {
  real_T u_opt;                        /* '<S37>/runFastGradient' */
  real_T u_buff_out[3];                /* '<S37>/runFastGradient' */
  real_T V_init_out[30];               /* '<S37>/runFastGradient' */
} rtB_runFastGradient_controller_;

/* Block signals for system '<S38>/discrete kalman filter' */
typedef struct {
  real_T state_est[4];                 /* '<S38>/discrete kalman filter' */
  real_T P_est[16];                    /* '<S38>/discrete kalman filter' */
} rtB_discretekalmanfilter_contro;

/* Block signals for system '<S42>/discrete kalman filter' */
typedef struct {
  real_T state_est[3];                 /* '<S42>/discrete kalman filter' */
  real_T P_est[9];                     /* '<S42>/discrete kalman filter' */
} rtB_discretekalmanfilter_cont_p;

/* Block signals (auto storage) */
typedef struct {
  real_T bias_W[4];                    /* '<S32>/bias_W' */
  real_T cmd_W[4];                     /* '<S32>/cmd_W' */
  real_T bias_W_b[4];                  /* '<S9>/bias_W' */
  real_T cmd_W_h[4];                   /* '<S9>/cmd_W' */
  rtB_EmbeddedMATLABFunction_co_c sf_EmbeddedMATLABFunction_h;/* '<S34>/Embedded MATLAB Function' */
  rtB_EmbeddedMATLABFunction_co_g sf_EmbeddedMATLABFunction_f;/* '<S58>/Embedded MATLAB Function' */
  rtB_EmbeddedMATLABFunction_cont sf_EmbeddedMATLABFunction_i;/* '<S57>/Embedded MATLAB Function' */
  rtB_discretekalmanfilter_cont_p sf_discretekalmanfilter_d;/* '<S44>/discrete kalman filter' */
  rtB_discretekalmanfilter_cont_p sf_discretekalmanfilter_j;/* '<S42>/discrete kalman filter' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter_n;/* '<S40>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient_a;/* '<S39>/runFastGradient' */
  rtB_discretekalmanfilter_contro sf_discretekalmanfilter;/* '<S38>/discrete kalman filter' */
  rtB_runFastGradient_controller_ sf_runFastGradient;/* '<S37>/runFastGradient' */
  rtB_EmbeddedMATLABFunction_co_c sf_EmbeddedMATLABFunction;/* '<S11>/Embedded MATLAB Function' */
  rtB_EmbeddedMATLABFunction_co_g sf_EmbeddedMATLABFunction_l;/* '<S26>/Embedded MATLAB Function' */
  rtB_EmbeddedMATLABFunction_cont sf_EmbeddedMATLABFunction_m;/* '<S25>/Embedded MATLAB Function' */
} BlockIO_controller_template;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T FixPtUnitDelay1_DSTATE[4];    /* '<S30>/FixPt Unit Delay1' */
  real_T IntegerDelay_DSTATE;          /* '<S31>/Integer Delay' */
  real_T IntegerDelay1_DSTATE;         /* '<S31>/Integer Delay1' */
  real_T IntegerDelay2_DSTATE;         /* '<S31>/Integer Delay2' */
  real_T IntegerDelay3_DSTATE;         /* '<S31>/Integer Delay3' */
  real_T UnitDelay1_DSTATE[16];        /* '<S38>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_m[3];  /* '<S46>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE[3];          /* '<S37>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f[30];      /* '<S37>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_m[16];      /* '<S40>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_g[3];  /* '<S49>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_p[3];        /* '<S39>/Unit Delay' */
  real_T UnitDelay1_DSTATE_mi[30];     /* '<S39>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_c[9];       /* '<S44>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_j[2];  /* '<S55>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_d[2];        /* '<S43>/Unit Delay' */
  real_T UnitDelay1_DSTATE_j[30];      /* '<S43>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_h[9];       /* '<S42>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_p[2];  /* '<S52>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_j[6];        /* '<S41>/Unit Delay' */
  real_T UnitDelay1_DSTATE_p[30];      /* '<S41>/Unit Delay1' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S30>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_l;    /* '<S46>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_f;    /* '<S49>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_h;    /* '<S55>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_g;    /* '<S52>/FixPt Unit Delay2' */
  boolean_T FreeFlightPosCtrl_MODE;    /* '<Root>/FreeFlight Pos Ctrl' */
  boolean_T poscontroller_MODE;        /* '<Root>/pos controller' */
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
  real_T Saturation_UpperSat_j;        /* Expression: 0.2094
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: -0.2094
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Saturation1_UpperSat_b;       /* Expression: 2
                                        * Referenced by: '<S14>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_l;       /* Expression: -2
                                        * Referenced by: '<S14>/Saturation1'
                                        */
  real_T Saturation3_UpperSat_o;       /* Expression: 1
                                        * Referenced by: '<S14>/Saturation3'
                                        */
  real_T Saturation3_LowerSat_i;       /* Expression: -1
                                        * Referenced by: '<S14>/Saturation3'
                                        */
  real_T Saturation2_UpperSat_m;       /* Expression: 1
                                        * Referenced by: '<S14>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_e;       /* Expression: -1
                                        * Referenced by: '<S14>/Saturation2'
                                        */
  real_T Constant_Value_n[3684];       /* Expression: Hn_Ydir
                                        * Referenced by: '<S19>/Constant'
                                        */
  real_T Constant1_Value_o[921];       /* Expression: Kn_Ydir
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T Constant2_Value_n[416];       /* Expression: Fi_Ydir
                                        * Referenced by: '<S19>/Constant2'
                                        */
  real_T Constant3_Value_a[104];       /* Expression: Gi_Ydir
                                        * Referenced by: '<S19>/Constant3'
                                        */
  real_T Constant4_Value_p[104];       /* Expression: Nc_Ydir
                                        * Referenced by: '<S19>/Constant4'
                                        */
  real_T Saturation1_UpperSat_m;       /* Expression: 1
                                        * Referenced by: '<S16>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -1
                                        * Referenced by: '<S16>/Saturation1'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 1
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Saturation_LowerSat_o;        /* Expression: -1
                                        * Referenced by: '<S16>/Saturation'
                                        */
  real_T Constant_Value_f[176];        /* Expression: Hn_Zdir
                                        * Referenced by: '<S23>/Constant'
                                        */
  real_T Constant1_Value_g[88];        /* Expression: Kn_Zdir
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T Constant2_Value_k[42];        /* Expression: Fi_Zdir
                                        * Referenced by: '<S23>/Constant2'
                                        */
  real_T Constant3_Value_as[21];       /* Expression: Gi_Zdir
                                        * Referenced by: '<S23>/Constant3'
                                        */
  real_T Constant4_Value_n[21];        /* Expression: Nc_Zdir
                                        * Referenced by: '<S23>/Constant4'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: 0.0873
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation_LowerSat_b;        /* Expression: -0.0873
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Constant_Value_d[2];          /* Expression: Hn_Yaw
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant1_Value_gz[2];        /* Expression: Kn_Yaw
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real_T Constant2_Value_e;            /* Expression: Fi_Yaw
                                        * Referenced by: '<S21>/Constant2'
                                        */
  real_T Constant3_Value_e;            /* Expression: Gi_Yaw
                                        * Referenced by: '<S21>/Constant3'
                                        */
  real_T Constant4_Value_m;            /* Expression: Nc_Yaw
                                        * Referenced by: '<S21>/Constant4'
                                        */
  real_T g_Value;                      /* Expression: g
                                        * Referenced by: '<S25>/g'
                                        */
  real_T yaw_Value;                    /* Expression: 0
                                        * Referenced by: '<S3>/yaw'
                                        */
  real_T gravity_Value_k;              /* Expression: -g
                                        * Referenced by: '<S3>/- gravity'
                                        */
  real_T roll_Value;                   /* Expression: 0
                                        * Referenced by: '<S3>/roll'
                                        */
  real_T pitch_Value;                  /* Expression: 0
                                        * Referenced by: '<S3>/pitch'
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
  real_T IntegerDelay_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<S31>/Integer Delay'
                                        */
  real_T IntegerDelay1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S31>/Integer Delay1'
                                         */
  real_T IntegerDelay2_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S31>/Integer Delay2'
                                         */
  real_T IntegerDelay3_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S31>/Integer Delay3'
                                         */
  real_T gravity_Value_a;              /* Expression: g
                                        * Referenced by: '<S31>/gravity'
                                        */
  real_T TT_PP_Value[900];             /* Expression: FG_ctrl_x.TT_PP
                                        * Referenced by: '<S37>/TT_PP'
                                        */
  real_T LL_PP_Value[90];              /* Expression: FG_ctrl_x.LL_PP
                                        * Referenced by: '<S37>/LL_PP'
                                        */
  real_T LL_ref_PP_Value[2790];        /* Expression: FG_ctrl_x.LL_ref_PP
                                        * Referenced by: '<S37>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value[900];       /* Expression: FG_ctrl_x.LL_U_ref_PP
                                        * Referenced by: '<S37>/LL_U_ref_PP'
                                        */
  real_T MM_Value[9];                  /* Expression: FG_ctrl_x.MM
                                        * Referenced by: '<S37>/MM'
                                        */
  real_T PP_Value[900];                /* Expression: FG_ctrl_x.PP
                                        * Referenced by: '<S37>/PP'
                                        */
  real_T AA_delay_Value[9];            /* Expression: FG_ctrl_x.AA_delay
                                        * Referenced by: '<S37>/AA_delay'
                                        */
  real_T BB_delay_Value[9];            /* Expression: FG_ctrl_x.BB_delay
                                        * Referenced by: '<S37>/BB_delay'
                                        */
  real_T A_Value[16];                  /* Expression: kalm_mpc_x.A
                                        * Referenced by: '<S38>/A'
                                        */
  real_T B_Value[4];                   /* Expression: kalm_mpc_x.B
                                        * Referenced by: '<S38>/B'
                                        */
  real_T C_Value[12];                  /* Expression: kalm_mpc_x.C
                                        * Referenced by: '<S38>/C'
                                        */
  real_T D_Value[3];                   /* Expression: kalm_mpc_x.D
                                        * Referenced by: '<S38>/D'
                                        */
  real_T Q_Value[16];                  /* Expression: kalm_mpc_x.Q
                                        * Referenced by: '<S38>/Q'
                                        */
  real_T R_Value[9];                   /* Expression: kalm_mpc_x.R
                                        * Referenced by: '<S38>/R'
                                        */
  real_T UnitDelay1_InitialCondition[16];/* Expression: kalm_mpc_x.P
                                          * Referenced by: '<S38>/Unit Delay1'
                                          */
  real_T FixPtUnitDelay1_InitialConditio;/* Expression: 0.0
                                          * Referenced by: '<S46>/FixPt Unit Delay1'
                                          */
  real_T V_max_Value[30];              /* Expression: FG_ctrl_x.V_max
                                        * Referenced by: '<S37>/V_max'
                                        */
  real_T i_min_Value;                  /* Expression: FG_ctrl_x.i_min
                                        * Referenced by: '<S37>/i_min'
                                        */
  real_T betas_Value[7];               /* Expression: FG_ctrl_x.betas
                                        * Referenced by: '<S37>/betas'
                                        */
  real_T L_Value;                      /* Expression: FG_ctrl_x.L
                                        * Referenced by: '<S37>/L'
                                        */
  real_T UnitDelay_InitialCondition[3];/* Expression: zeros(FG_ctrl_x.delay_steps,1)
                                        * Referenced by: '<S37>/Unit Delay'
                                        */
  real_T UnitDelay1_InitialCondition_h[30];/* Expression: zeros(size(FG_ctrl_x.V_max,1),1)
                                            * Referenced by: '<S37>/Unit Delay1'
                                            */
  real_T Saturation_UpperSat_e;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S38>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S38>/Saturation'
                                        */
  real_T TT_PP_Value_n[900];           /* Expression: FG_ctrl_y.TT_PP
                                        * Referenced by: '<S39>/TT_PP'
                                        */
  real_T LL_PP_Value_h[90];            /* Expression: FG_ctrl_y.LL_PP
                                        * Referenced by: '<S39>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_l[2790];      /* Expression: FG_ctrl_y.LL_ref_PP
                                        * Referenced by: '<S39>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_h[900];     /* Expression: FG_ctrl_y.LL_U_ref_PP
                                        * Referenced by: '<S39>/LL_U_ref_PP'
                                        */
  real_T MM_Value_n[9];                /* Expression: FG_ctrl_y.MM
                                        * Referenced by: '<S39>/MM'
                                        */
  real_T PP_Value_a[900];              /* Expression: FG_ctrl_y.PP
                                        * Referenced by: '<S39>/PP'
                                        */
  real_T AA_delay_Value_j[9];          /* Expression: FG_ctrl_y.AA_delay
                                        * Referenced by: '<S39>/AA_delay'
                                        */
  real_T BB_delay_Value_c[9];          /* Expression: FG_ctrl_y.BB_delay
                                        * Referenced by: '<S39>/BB_delay'
                                        */
  real_T A_Value_g[16];                /* Expression: kalm_mpc_y.A
                                        * Referenced by: '<S40>/A'
                                        */
  real_T B_Value_f[4];                 /* Expression: kalm_mpc_y.B
                                        * Referenced by: '<S40>/B'
                                        */
  real_T C_Value_m[12];                /* Expression: kalm_mpc_y.C
                                        * Referenced by: '<S40>/C'
                                        */
  real_T D_Value_f[3];                 /* Expression: kalm_mpc_y.D
                                        * Referenced by: '<S40>/D'
                                        */
  real_T Q_Value_h[16];                /* Expression: kalm_mpc_y.Q
                                        * Referenced by: '<S40>/Q'
                                        */
  real_T R_Value_e[9];                 /* Expression: kalm_mpc_y.R
                                        * Referenced by: '<S40>/R'
                                        */
  real_T UnitDelay1_InitialCondition_b[16];/* Expression: kalm_mpc_y.P
                                            * Referenced by: '<S40>/Unit Delay1'
                                            */
  real_T FixPtUnitDelay1_InitialCondit_m;/* Expression: 0.0
                                          * Referenced by: '<S49>/FixPt Unit Delay1'
                                          */
  real_T V_max_Value_g[30];            /* Expression: FG_ctrl_y.V_max
                                        * Referenced by: '<S39>/V_max'
                                        */
  real_T i_min_Value_l;                /* Expression: FG_ctrl_y.i_min
                                        * Referenced by: '<S39>/i_min'
                                        */
  real_T betas_Value_m[7];             /* Expression: FG_ctrl_y.betas
                                        * Referenced by: '<S39>/betas'
                                        */
  real_T L_Value_g;                    /* Expression: FG_ctrl_y.L
                                        * Referenced by: '<S39>/L'
                                        */
  real_T UnitDelay_InitialCondition_n[3];/* Expression: zeros(FG_ctrl_y.delay_steps,1)
                                          * Referenced by: '<S39>/Unit Delay'
                                          */
  real_T UnitDelay1_InitialCondition_o[30];/* Expression: zeros(size(FG_ctrl_y.V_max,1),1)
                                            * Referenced by: '<S39>/Unit Delay1'
                                            */
  real_T Saturation_UpperSat_f;        /* Expression: MAX_BIAS_ANGLE
                                        * Referenced by: '<S40>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -MAX_BIAS_ANGLE
                                        * Referenced by: '<S40>/Saturation'
                                        */
  real_T TT_PP_Value_e[900];           /* Expression: FG_ctrl_z.TT_PP
                                        * Referenced by: '<S43>/TT_PP'
                                        */
  real_T LL_PP_Value_l[60];            /* Expression: FG_ctrl_z.LL_PP
                                        * Referenced by: '<S43>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_d[1860];      /* Expression: FG_ctrl_z.LL_ref_PP
                                        * Referenced by: '<S43>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_k[900];     /* Expression: FG_ctrl_z.LL_U_ref_PP
                                        * Referenced by: '<S43>/LL_U_ref_PP'
                                        */
  real_T MM_Value_i[4];                /* Expression: FG_ctrl_z.MM
                                        * Referenced by: '<S43>/MM'
                                        */
  real_T PP_Value_m[900];              /* Expression: FG_ctrl_z.PP
                                        * Referenced by: '<S43>/PP'
                                        */
  real_T AA_delay_Value_f[4];          /* Expression: FG_ctrl_z.AA_delay
                                        * Referenced by: '<S43>/AA_delay'
                                        */
  real_T BB_delay_Value_n[4];          /* Expression: FG_ctrl_z.BB_delay
                                        * Referenced by: '<S43>/BB_delay'
                                        */
  real_T A_Value_e[9];                 /* Expression: kalm_mpc_z.A
                                        * Referenced by: '<S44>/A'
                                        */
  real_T B_Value_k[3];                 /* Expression: kalm_mpc_z.B
                                        * Referenced by: '<S44>/B'
                                        */
  real_T C_Value_p[6];                 /* Expression: kalm_mpc_z.C
                                        * Referenced by: '<S44>/C'
                                        */
  real_T D_Value_k[2];                 /* Expression: kalm_mpc_z.D
                                        * Referenced by: '<S44>/D'
                                        */
  real_T Q_Value_g[9];                 /* Expression: kalm_mpc_z.Q
                                        * Referenced by: '<S44>/Q'
                                        */
  real_T R_Value_c[4];                 /* Expression: kalm_mpc_z.R
                                        * Referenced by: '<S44>/R'
                                        */
  real_T UnitDelay1_InitialCondition_ou[9];/* Expression: kalm_mpc_z.P
                                            * Referenced by: '<S44>/Unit Delay1'
                                            */
  real_T FixPtUnitDelay1_InitialCondit_p;/* Expression: 0.0
                                          * Referenced by: '<S55>/FixPt Unit Delay1'
                                          */
  real_T V_max_Value_a[30];            /* Expression: FG_ctrl_z.V_max
                                        * Referenced by: '<S43>/V_max'
                                        */
  real_T i_min_Value_p;                /* Expression: FG_ctrl_z.i_min
                                        * Referenced by: '<S43>/i_min'
                                        */
  real_T betas_Value_o[8];             /* Expression: FG_ctrl_z.betas
                                        * Referenced by: '<S43>/betas'
                                        */
  real_T L_Value_j;                    /* Expression: FG_ctrl_z.L
                                        * Referenced by: '<S43>/L'
                                        */
  real_T UnitDelay_InitialCondition_f[2];/* Expression: zeros(FG_ctrl_z.delay_steps,1)
                                          * Referenced by: '<S43>/Unit Delay'
                                          */
  real_T UnitDelay1_InitialCondition_m[30];/* Expression: zeros(size(FG_ctrl_z.V_max,1),1)
                                            * Referenced by: '<S43>/Unit Delay1'
                                            */
  real_T Saturation_UpperSat_jz;       /* Expression: MAX_BIAS_THRUST
                                        * Referenced by: '<S44>/Saturation'
                                        */
  real_T Saturation_LowerSat_cp;       /* Expression: -MAX_BIAS_THRUST
                                        * Referenced by: '<S44>/Saturation'
                                        */
  real_T TT_PP_Value_ew[900];          /* Expression: FG_ctrl_yaw.TT_PP
                                        * Referenced by: '<S41>/TT_PP'
                                        */
  real_T LL_PP_Value_o[60];            /* Expression: FG_ctrl_yaw.LL_PP
                                        * Referenced by: '<S41>/LL_PP'
                                        */
  real_T LL_ref_PP_Value_b[1860];      /* Expression: FG_ctrl_yaw.LL_ref_PP
                                        * Referenced by: '<S41>/LL_ref_PP'
                                        */
  real_T LL_U_ref_PP_Value_g[900];     /* Expression: FG_ctrl_yaw.LL_U_ref_PP
                                        * Referenced by: '<S41>/LL_U_ref_PP'
                                        */
  real_T MM_Value_m[4];                /* Expression: FG_ctrl_yaw.MM
                                        * Referenced by: '<S41>/MM'
                                        */
  real_T PP_Value_i[900];              /* Expression: FG_ctrl_yaw.PP
                                        * Referenced by: '<S41>/PP'
                                        */
  real_T AA_delay_Value_e[4];          /* Expression: FG_ctrl_yaw.AA_delay
                                        * Referenced by: '<S41>/AA_delay'
                                        */
  real_T BB_delay_Value_j[12];         /* Expression: FG_ctrl_yaw.BB_delay
                                        * Referenced by: '<S41>/BB_delay'
                                        */
  real_T A_Value_gk[9];                /* Expression: kalm_mpc_yaw.A
                                        * Referenced by: '<S42>/A'
                                        */
  real_T B_Value_ke[3];                /* Expression: kalm_mpc_yaw.B
                                        * Referenced by: '<S42>/B'
                                        */
  real_T C_Value_c[6];                 /* Expression: kalm_mpc_yaw.C
                                        * Referenced by: '<S42>/C'
                                        */
  real_T D_Value_h[2];                 /* Expression: kalm_mpc_yaw.D
                                        * Referenced by: '<S42>/D'
                                        */
  real_T Q_Value_n[9];                 /* Expression: kalm_mpc_yaw.Q
                                        * Referenced by: '<S42>/Q'
                                        */
  real_T R_Value_k[4];                 /* Expression: kalm_mpc_yaw.R
                                        * Referenced by: '<S42>/R'
                                        */
  real_T UnitDelay1_InitialCondition_oo[9];/* Expression: kalm_mpc_yaw.P
                                            * Referenced by: '<S42>/Unit Delay1'
                                            */
  real_T FixPtUnitDelay1_InitialCondit_k;/* Expression: 0.0
                                          * Referenced by: '<S52>/FixPt Unit Delay1'
                                          */
  real_T V_max_Value_h[30];            /* Expression: FG_ctrl_yaw.V_max
                                        * Referenced by: '<S41>/V_max'
                                        */
  real_T i_min_Value_a;                /* Expression: FG_ctrl_yaw.i_min
                                        * Referenced by: '<S41>/i_min'
                                        */
  real_T betas_Value_o5[5];            /* Expression: FG_ctrl_yaw.betas
                                        * Referenced by: '<S41>/betas'
                                        */
  real_T L_Value_jd;                   /* Expression: FG_ctrl_yaw.L
                                        * Referenced by: '<S41>/L'
                                        */
  real_T UnitDelay_InitialCondition_k[6];/* Expression: zeros(FG_ctrl_yaw.delay_steps,1)
                                          * Referenced by: '<S41>/Unit Delay'
                                          */
  real_T UnitDelay1_InitialCondition_g[30];/* Expression: zeros(size(FG_ctrl_yaw.V_max,1),1)
                                            * Referenced by: '<S41>/Unit Delay1'
                                            */
  real_T Saturation_UpperSat_o;        /* Expression: MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S42>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: -MAX_BIAS_YAW_RATE
                                        * Referenced by: '<S42>/Saturation'
                                        */
  real_T g_Value_j;                    /* Expression: g
                                        * Referenced by: '<S57>/g'
                                        */
  real_T pitch_offset_Value;           /* Expression: 0.00
                                        * Referenced by: '<S5>/pitch_offset'
                                        */
  real_T InitialCondition_Value;       /* Expression: vinit
                                        * Referenced by: '<S30>/Initial Condition'
                                        */
  real_T Constant1_Value_of;           /* Expression: 1
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant2_Value_l;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T FixPtUnitDelay1_InitialCondit_b;/* Expression: vinit
                                          * Referenced by: '<S30>/FixPt Unit Delay1'
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
  real_T gravity_Value_b;              /* Expression: g
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
  real_T yaw_cmd2yaw_Gain;             /* Expression: yaw_cmd2yaw_1stOrd
                                        * Referenced by: '<S5>/yaw_cmd2yaw'
                                        */
  real_T yaw_rate_Value;               /* Expression: 0
                                        * Referenced by: '<S5>/yaw_rate'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1.0
                                        * Referenced by: '<S5>/Gain4'
                                        */
  uint32_T IntegerDelay_DelayLength;   /* Computed Parameter: IntegerDelay_DelayLength
                                        * Referenced by: '<S31>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength;  /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S31>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength;  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S31>/Integer Delay2'
                                        */
  uint32_T IntegerDelay3_DelayLength;  /* Computed Parameter: IntegerDelay3_DelayLength
                                        * Referenced by: '<S31>/Integer Delay3'
                                        */
  uint8_T FixPtUnitDelay2_InitialConditio;/* Computed Parameter: FixPtUnitDelay2_InitialConditio
                                           * Referenced by: '<S46>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtUnitDelay2_InitialCondit_d;/* Computed Parameter: FixPtUnitDelay2_InitialCondit_d
                                           * Referenced by: '<S49>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtUnitDelay2_InitialCondit_b;/* Computed Parameter: FixPtUnitDelay2_InitialCondit_b
                                           * Referenced by: '<S55>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtUnitDelay2_InitialCondit_i;/* Computed Parameter: FixPtUnitDelay2_InitialCondit_i
                                           * Referenced by: '<S52>/FixPt Unit Delay2'
                                           */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S46>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_p;       /* Computed Parameter: FixPtConstant_Value_p
                                        * Referenced by: '<S49>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_p5;      /* Computed Parameter: FixPtConstant_Value_p5
                                        * Referenced by: '<S52>/FixPt Constant'
                                        */
  uint8_T FixPtConstant_Value_j;       /* Computed Parameter: FixPtConstant_Value_j
                                        * Referenced by: '<S55>/FixPt Constant'
                                        */
  uint8_T FixPtUnitDelay2_InitialCondit_k;/* Computed Parameter: FixPtUnitDelay2_InitialCondit_k
                                           * Referenced by: '<S30>/FixPt Unit Delay2'
                                           */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<S5>/Manual Switch'
                                        */
  uint8_T FixPtConstant_Value_l;       /* Computed Parameter: FixPtConstant_Value_l
                                        * Referenced by: '<S30>/FixPt Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_controller_template {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern Parameters_controller_template controller_template_P;

#ifdef __cplusplus

}
#endif

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

  extern RT_MODEL_controller_template *const controller_template_M;

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
 * '<S30>'  : 'controller_template/delay/delay bias'
 * '<S31>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1'
 * '<S32>'  : 'controller_template/pos controller/decoupling and rotation'
 * '<S33>'  : 'controller_template/pos controller/get ref from vector'
 * '<S34>'  : 'controller_template/pos controller/rotate to world frame'
 * '<S35>'  : 'controller_template/pos controller/view & log signals'
 * '<S36>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/demux'
 * '<S37>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  '
 * '<S38>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias'
 * '<S39>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG'
 * '<S40>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias'
 * '<S41>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG'
 * '<S42>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias'
 * '<S43>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG'
 * '<S44>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias'
 * '<S45>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x controller MPC FG  /runFastGradient'
 * '<S46>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/Unit Delay External IC1'
 * '<S47>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/x states estimator bias/discrete kalman filter'
 * '<S48>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y controller MPC FG/runFastGradient'
 * '<S49>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/Unit Delay External IC1'
 * '<S50>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/y states estimator bias/discrete kalman filter'
 * '<S51>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw controller MPC FG/runFastGradient'
 * '<S52>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/Unit Delay External IC1'
 * '<S53>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/yaw states estimator bias/discrete kalman filter'
 * '<S54>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z controller MPC FG/runFastGradient'
 * '<S55>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/Unit Delay External IC1'
 * '<S56>'  : 'controller_template/pos controller/MAIN CONTROL LOOP1/z states estimator bias/discrete kalman filter'
 * '<S57>'  : 'controller_template/pos controller/decoupling and rotation/decoupling '
 * '<S58>'  : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame'
 * '<S59>'  : 'controller_template/pos controller/decoupling and rotation/decoupling /Embedded MATLAB Function'
 * '<S60>'  : 'controller_template/pos controller/decoupling and rotation/rotate_to_quat_frame/Embedded MATLAB Function'
 * '<S61>'  : 'controller_template/pos controller/rotate to world frame/Embedded MATLAB Function'
 */
#endif                                 /* RTW_HEADER_controller_template_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
