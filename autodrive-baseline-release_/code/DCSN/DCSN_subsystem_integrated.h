/*
 * File: DCSN_subsystem_integrated.h
 *
 * Code generated for Simulink model 'DCSN_subsystem_integrated'.
 *
 * Model version                  : 1.602
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:40:58 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Safety precaution
 *    3. Execution efficiency
 *    4. RAM efficiency
 *    5. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DCSN_subsystem_integrated_h_
#define RTW_HEADER_DCSN_subsystem_integrated_h_
#include <string.h>
#ifndef DCSN_subsystem_integrated_COMMON_INCLUDES_
# define DCSN_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* DCSN_subsystem_integrated_COMMON_INCLUDES_ */

#include "DCSN_subsystem_integrated_types.h"

/* Child system includes */
#include "DtrmnDCSN_Integrated.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct
{
  DCSN_EnablingFlagsGroup EnablingFlags_Group;/* '<S61>/Bus Creator' */
  DCSN_ADMGroup ADM_Group;             /* '<S3>/Bus Creator2' */
  real32_T stop_distance;              /* '<S162>/DtrmnDCSN_StopModeManager' */
  real32_T Add;                        /* '<S171>/Add' */
  int32_T stop_lines_index;            /* '<S168>/stop_lines_index' */
  int32_T lane_index;                  /* '<S157>/lane_index' */
  int32_T lane_marker_index;           /* '<S113>/lane_marker_index' */
  int32_T lane_marker_index_o23e;      /* '<S111>/lane_marker_index' */
  int32_T road_edges_index;            /* '<S109>/road_edges_index' */
  int32_T road_edges_index_iogx;       /* '<S107>/road_edges_index' */
  uint16_T CurrentTick;                /* '<S51>/Switch1' */
  uint16_T CurrentTick_cho5;           /* '<S27>/Switch1' */
  uint16_T CurrentTick_hcb0;           /* '<S28>/Switch1' */
  uint16_T CurrentTick_ilxy;           /* '<S29>/Switch1' */
  uint16_T CurrentTick_k4pd;           /* '<S30>/Switch1' */
  uint16_T CurrentTick_i1hg;           /* '<S31>/Switch1' */
  uint16_T CurrentTick_ad1o;           /* '<S24>/Switch1' */
  uint16_T CurrentTick_hziy;           /* '<S25>/Switch1' */
  uint16_T CurrentTick_k0eg;           /* '<S26>/Switch1' */
  boolean_T Switch;                    /* '<S62>/Switch' */
  boolean_T Logic[2];                  /* '<S43>/Logic' */
  boolean_T LogicalOperator3;          /* '<S14>/Logical Operator3' */
  boolean_T Logic_mmx2[2];             /* '<S42>/Logic' */
  boolean_T Compare;                   /* '<S36>/Compare' */
  boolean_T RelationalOperator8;       /* '<S14>/Relational Operator8' */
  boolean_T LogicalOperator8;          /* '<S14>/Logical Operator8' */
  boolean_T LogicalOperator9;          /* '<S14>/Logical Operator9' */
  EnumDCSN_adm_main_mode adm_main_mode;/* '<S8>/DtrmnDCSN_ADMManager' */
  B_IfActionSubsystem_DCSN_subs_T IfActionSubsystem_j2my;/* '<S79>/If Action Subsystem' */
  B_IfActionSubsystem_DCSN_subs_T IfActionSubsystem;/* '<S78>/If Action Subsystem' */
}
B_DCSN_subsystem_integrated_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
  real32_T UnitDelay_DSTATE_fq2a;      /* '<S74>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ezc1;      /* '<S171>/Unit Delay' */
  real32_T UnitDelay_DSTATE_df2f;      /* '<S170>/Unit Delay' */
  real32_T UnitDelay_DSTATE_nmi2;      /* '<S137>/Unit Delay' */
  real32_T UnitDelay_DSTATE_aygd;      /* '<S141>/Unit Delay' */
  real32_T UnitDelay_DSTATE_e1pk;      /* '<S143>/Unit Delay' */
  real32_T UnitDelay_DSTATE_hrrg;      /* '<S142>/Unit Delay' */
  real32_T UnitDelay_DSTATE_mp0s;      /* '<S146>/Unit Delay' */
  real32_T UnitDelay_DSTATE_h2o1;      /* '<S145>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ldyw;      /* '<S140>/Unit Delay' */
  real32_T UnitDelay_DSTATE_gmxm;      /* '<S139>/Unit Delay' */
  real32_T UnitDelay_DSTATE_dvap;      /* '<S138>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ojmf;      /* '<S121>/Unit Delay' */
  real32_T UnitDelay_DSTATE_jmmu;      /* '<S125>/Unit Delay' */
  real32_T UnitDelay_DSTATE_o5r3;      /* '<S127>/Unit Delay' */
  real32_T UnitDelay_DSTATE_j4qc;      /* '<S126>/Unit Delay' */
  real32_T UnitDelay_DSTATE_pxme;      /* '<S130>/Unit Delay' */
  real32_T UnitDelay_DSTATE_edmg;      /* '<S129>/Unit Delay' */
  real32_T UnitDelay_DSTATE_cs2z;      /* '<S124>/Unit Delay' */
  real32_T UnitDelay_DSTATE_jc32;      /* '<S123>/Unit Delay' */
  real32_T UnitDelay_DSTATE_dqkl;      /* '<S122>/Unit Delay' */
  real32_T UnitDelay_DSTATE_bcxc;      /* '<S131>/Unit Delay' */
  real32_T UnitDelay_DSTATE_hxfz;      /* '<S135>/Unit Delay' */
  real32_T UnitDelay_DSTATE_fsl3;      /* '<S134>/Unit Delay' */
  real32_T UnitDelay_DSTATE_fmjv;      /* '<S133>/Unit Delay' */
  real32_T UnitDelay_DSTATE_anes;      /* '<S132>/Unit Delay' */
  real32_T UnitDelay_DSTATE_o5ry;      /* '<S115>/Unit Delay' */
  real32_T UnitDelay_DSTATE_cxqx;      /* '<S119>/Unit Delay' */
  real32_T UnitDelay_DSTATE_cwys;      /* '<S118>/Unit Delay' */
  real32_T UnitDelay_DSTATE_orr5;      /* '<S117>/Unit Delay' */
  real32_T UnitDelay_DSTATE_k4as;      /* '<S116>/Unit Delay' */
  real32_T distance_to_move;           /* '<S162>/DtrmnDCSN_StopModeManager' */
  uint32_T temporalCounter_i1;         /* '<S8>/DtrmnDCSN_ADMManager' */
  uint16_T UnitDelay_DSTATE_ch4m;      /* '<S187>/UnitDelay' */
  uint16_T DiscreteTimeIntegrator_DSTATE;/* '<S172>/Discrete-Time Integrator' */
  uint16_T DiscreteTimeIntegrator_DST_ky0g;/* '<S173>/Discrete-Time Integrator' */
  uint16_T UnitDelay_DSTATE_ctin;      /* '<S188>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_b5in;      /* '<S189>/UnitDelay' */
  uint16_T DiscreteTimeIntegrator_DST_kkmj;/* '<S58>/Discrete-Time Integrator' */
  uint16_T DiscreteTimeIntegrator_DST_brg5;/* '<S14>/Discrete-Time Integrator' */
  uint16_T UnitDelay5_DSTATE;          /* '<S14>/Unit Delay5' */
  uint16_T UnitDelay_DSTATE_jn5k;      /* '<S51>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_kv3i;      /* '<S27>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_awwr;      /* '<S28>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_a5my;      /* '<S29>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_ivcp;      /* '<S30>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_pet3;      /* '<S31>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_nbxp;      /* '<S24>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_o4sd;      /* '<S25>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_pjhr;      /* '<S26>/UnitDelay' */
  uint16_T DiscreteTimeIntegrator1_DSTATE;/* '<S14>/Discrete-Time Integrator1' */
  uint16_T autodrive_wait_time;        /* '<S53>/autodrive_control_mode_manager' */
  uint16_T time_count;                 /* '<S53>/autodrive_control_mode_manager' */
  uint16_T temporalCounter_i1_lzql;    /* '<S53>/autodrive_control_mode_manager' */
  uint16_T temporalCounter_i1_gk3n;    /* '<S9>/DtrmnDCSN_DrivIntention' */
  uint16_T warning_time;               /* '<S8>/DtrmnDCSN_ADMManager' */
  uint16_T time_count_agzm;            /* '<S8>/DtrmnDCSN_ADMManager' */
  uint8_T UnitDelay_DSTATE_da3u;       /* '<S183>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_efss;       /* '<S181>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_dsaz;       /* '<S182>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_g2gu;       /* '<S14>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_cb10;     /* '<S185>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_a53f;    /* '<S185>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE;         /* '<S185>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE;         /* '<S185>/Unit Delay4' */
  boolean_T UnitDelay5_DSTATE_nwlx;    /* '<S185>/Unit Delay5' */
  boolean_T UnitDelay6_DSTATE;         /* '<S185>/Unit Delay6' */
  boolean_T UnitDelay7_DSTATE;         /* '<S185>/Unit Delay7' */
  boolean_T UnitDelay8_DSTATE;         /* '<S185>/Unit Delay8' */
  boolean_T Delay_DSTATE[5];           /* '<S185>/Delay' */
  boolean_T UnitDelay2_DSTATE_nwfs;    /* '<S185>/Unit Delay2' */
  boolean_T Delay_DSTATE_a2ia;         /* '<S60>/Delay' */
  boolean_T UnitDelay_DSTATE_bhq0;     /* '<S62>/Unit Delay' */
  boolean_T Delay1_DSTATE[100];        /* '<S7>/Delay1' */
  boolean_T UnitDelay2_DSTATE_khwm;    /* '<S14>/Unit Delay2' */
  boolean_T UnitDelay1_DSTATE_imjc;    /* '<S14>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE_m0wa;    /* '<S14>/Unit Delay3' */
  boolean_T Delay_DSTATE_mze2[3];      /* '<S12>/Delay' */
  boolean_T UnitDelay_DSTATE_cy03;     /* '<S3>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_jlps;    /* '<S3>/Unit Delay1' */
  boolean_T UnitDelay4_DSTATE_oddz;    /* '<S14>/Unit Delay4' */
  EnumDCSN_adm_main_mode UnitDelay_DSTATE_k2di;/* '<S8>/Unit Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S172>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_Pre_jtbt;/* '<S173>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_Pre_bpg0;/* '<S58>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_Pre_np0h;/* '<S14>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S14>/Discrete-Time Integrator1' */
  uint8_T is_active_c3_DCSN_subsystem_int;/* '<S162>/DtrmnDCSN_StopModeManager' */
  uint8_T is_c3_DCSN_subsystem_integrated;/* '<S162>/DtrmnDCSN_StopModeManager' */
  uint8_T is_StopRequestEnabled;       /* '<S162>/DtrmnDCSN_StopModeManager' */
  uint8_T is_active_c5_DCSN_subsystem_int;/* '<S53>/autodrive_control_mode_manager' */
  uint8_T is_c5_DCSN_subsystem_integrated;/* '<S53>/autodrive_control_mode_manager' */
  uint8_T icLoad;                      /* '<S7>/Delay1' */
  uint8_T is_active_c1_DCSN_subsystem_int;/* '<S9>/DtrmnDCSN_DrivIntention' */
  uint8_T is_c1_DCSN_subsystem_integrated;/* '<S9>/DtrmnDCSN_DrivIntention' */
  uint8_T is_active_c4_DCSN_subsystem_int;/* '<S8>/DtrmnDCSN_ADMManager' */
  uint8_T is_c4_DCSN_subsystem_integrated;/* '<S8>/DtrmnDCSN_ADMManager' */
  uint8_T is_ADM_ON;                   /* '<S8>/DtrmnDCSN_ADMManager' */
  uint8_T is_ADM_ON_INACTIVE;          /* '<S8>/DtrmnDCSN_ADMManager' */
  uint8_T is_ADM_ON_ACTIVE;            /* '<S8>/DtrmnDCSN_ADMManager' */
  uint8_T is_ADM_FAULT;                /* '<S8>/DtrmnDCSN_ADMManager' */
  boolean_T Memory_PreviousInput;      /* '<S190>/Memory' */
  boolean_T Memory_PreviousInput_nozl; /* '<S43>/Memory' */
  boolean_T Memory_PreviousInput_p5cx; /* '<S42>/Memory' */
  boolean_T autodrive_engaged;         /* '<S8>/DtrmnDCSN_ADMManager' */
  boolean_T autodrive_ready_to_engage; /* '<S8>/DtrmnDCSN_ADMManager' */
  boolean_T autodrive_resume_allowed;  /* '<S8>/DtrmnDCSN_ADMManager' */
  boolean_T StopDis_MODE;              /* '<S161>/StopDis' */
  DW_IfActionSubsystem_DCSN_sub_T IfActionSubsystem_j2my;/* '<S79>/If Action Subsystem' */
  DW_IfActionSubsystem_DCSN_sub_T IfActionSubsystem;/* '<S78>/If Action Subsystem' */
}
DW_DCSN_subsystem_integrated_T;

/* Zero-crossing (trigger) state */
typedef struct
{
  ZCSigState CvrtDCSN_DataConvert_Trig_ZCE;/* '<S14>/CvrtDCSN_DataConvert' */
}
PrevZCX_DCSN_subsystem_integr_T;

/* Invariant block signals (auto storage) */
typedef struct
{
  const real32_T TmpBufferAtConstantOutport1;/* '<S86>/Constant' */
  const real32_T TmpBufferAtConstant2Outport;/* '<S86>/Constant2' */
  const real32_T TmpBufferAtConstantOut_dl2l;/* '<S84>/Constant' */
  const real32_T TmpBufferAtConstant2Ou_ijwj;/* '<S84>/Constant2' */
}
ConstB_DCSN_subsystem_integra_T;

/* Constant parameters (auto storage) */
typedef struct
{
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S42>/Logic'
   *   '<S43>/Logic'
   *   '<S190>/Logic'
   */
  boolean_T pooled30[16];
}
ConstP_DCSN_subsystem_integra_T;

/* Block signals (auto storage) */
extern B_DCSN_subsystem_integrated_T DCSN_subsystem_integrated_B;

/* Block states (auto storage) */
extern DW_DCSN_subsystem_integrated_T DCSN_subsystem_integrated_DW;

/* External data declarations for dependent source files */
extern const DCSN_DataBus DCSN_subsystem_integrated_rtZDCSN_DataBus;/* DCSN_DataBus ground */

/* Zero-crossing (trigger) state */
extern PrevZCX_DCSN_subsystem_integr_T DCSN_subsystem_integrat_PrevZCX;
extern const ConstB_DCSN_subsystem_integra_T DCSN_subsystem_integrate_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstP_DCSN_subsystem_integra_T DCSN_subsystem_integrate_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern EGMO_DataBus VsEGMO_DataBus;    /* '<Root>/EGMO_DataBus' */
extern MPFU_DataBus VsMPFU_DataBus;    /* '<Root>/MPFU_DataBus' */
extern OBFU_DataBus VsOBFU_DataBus;    /* '<Root>/OBFU_DataBus' */
extern DCSN_DataBus VsDCSN_DataBus;    /* '<S1>/Bus Creator' */
extern real32_T VfDCSN_vehicle_speed_egmo;/* '<S70>/Signal Conversion'
                                           * The linear velocity of ego vehicle from egmo
                                           */
extern real32_T VfDCSN_SpdLimt_look_ahead_dis;/* '<S74>/Product'
                                               * look ahead distance when judging speed limit from curvature
                                               */
extern real32_T VfDCSN_largest_curvature_ahead;/* '<S74>/MinMax'
                                                * the largest curvature in look-ahead distance
                                                */
extern real32_T VfDCSN_speed_limit_curvature;/* '<S74>/1-D Lookup Table'
                                              * speed limit from curvature
                                              */
extern real32_T VfDCSN_raw_stop_line_distance;/* '<S160>/Merge3'
                                               * The raw stop line distance from mpfu
                                               */
extern real32_T VfDCSN_stop_s_distance;/* '<S73>/Switch1'
                                        * stop distance
                                        */
extern real32_T VfDCSN_lane_speed_limit;/* '<S73>/Switch2'
                                         * speed limit from ego lane
                                         */
extern real32_T VfDCSN_target_speed_limit;/* '<S73>/Switch16'
                                           * speed limit from target point
                                           */
extern real32_T VfDCSN_speed_limit_distance;/* '<S73>/Switch17'
                                             * the position of speed limit point
                                             */
extern real32_T VfDCSN_change_lane_target_speed;/* '<S73>/Switch5'
                                                 * target speed when change lane
                                                 */
extern real32_T VfDCSN_right_marker_raw_c0;/* '<S100>/Signal Conversion9'
                                            * The raw c0
                                            */
extern real32_T VfDCSN_current_right_marker_cur;/* '<S150>/Divide'
                                                 * current right marker curvature
                                                 */
extern real32_T VfDCSN_right_marker_raw_c1;/* '<S100>/Signal Conversion10'
                                            * The raw c1
                                            */
extern real32_T VfDCSN_current_right_edge_cur;/* '<S148>/Divide'
                                               * current right edge curvature
                                               */
extern real32_T VfDCSN_right_marker_raw_c2;/* '<S100>/Signal Conversion11'
                                            * The raw c2
                                            */
extern real32_T VfDCSN_right_marker_raw_c3;/* '<S100>/Signal Conversion12'
                                            * The raw c3
                                            */
extern real32_T VfDCSN_right_marker_raw_start_x;/* '<S100>/Signal Conversion13'
                                                 * The raw start x
                                                 */
extern real32_T VfDCSN_right_marker_raw_end_x;/* '<S100>/Signal Conversion15'
                                               * The raw end x
                                               */
extern real32_T VfDCSN_right_marker_raw_start_y;/* '<S100>/Signal Conversion14'
                                                 * The raw start y
                                                 */
extern real32_T VfDCSN_right_marker_raw_end_y;/* '<S100>/Signal Conversion16'
                                               * The raw end y
                                               */
extern real32_T VfDCSN_right_marker_raw_quality;/* '<S100>/Signal Conversion17'
                                                 * The raw quality
                                                 */
extern real32_T VfDCSN_left_marker_raw_c0;/* '<S100>/Signal Conversion'
                                           * The raw c0
                                           */
extern real32_T VfDCSN_current_left_marker_cur;/* '<S149>/Divide'
                                                * current left marker curvature
                                                */
extern real32_T VfDCSN_left_marker_raw_c1;/* '<S100>/Signal Conversion1'
                                           * The raw c1
                                           */
extern real32_T VfDCSN_current_left_edge_cur;/* '<S147>/Divide'
                                              * current left edge curvature
                                              */
extern real32_T VfDCSN_left_marker_raw_c2;/* '<S100>/Signal Conversion2'
                                           * The raw c2
                                           */
extern real32_T VfDCSN_left_marker_raw_c3;/* '<S100>/Signal Conversion3'
                                           * The raw c3
                                           */
extern real32_T VfDCSN_left_marker_raw_start_x;/* '<S100>/Signal Conversion4'
                                                * The raw start x
                                                */
extern real32_T VfDCSN_left_marker_raw_end_x;/* '<S100>/Signal Conversion6'
                                              * The raw end x
                                              */
extern real32_T VfDCSN_left_marker_raw_start_y;/* '<S100>/Signal Conversion5'
                                                * The raw start y
                                                */
extern real32_T VfDCSN_left_marker_raw_end_y;/* '<S100>/Signal Conversion7'
                                              * The raw end y
                                              */
extern real32_T VfDCSN_left_marker_raw_quality;/* '<S100>/Signal Conversion8'
                                                * The raw quality
                                                */
extern real32_T VfDCSN_speed_limit_ego_lane;/* '<S156>/In1'
                                             * speed limit from ego lane
                                             */
extern uint16_T VfDCSN_C_cond_act_time;/* '<S41>/In1'
                                        * The time count from driver presses activate switch and release the brake pedal.
                                          Valid when driver want to activate autodrive when brake or gas pedal pressed.
                                        */
extern uint8_T VfDCSN_mpfu_num_stop_lines;/* '<S184>/Switch'
                                           * The number of input numbers of stop lines from mpfu
                                           */
extern uint8_T VeDCSN_usr_cmd_autodrive_activate;/* '<S7>/Switch'
                                                  * usr activate cmd
                                                    0 = deactivate
                                                    1 = activate
                                                    2 = hold
                                                  */
extern boolean_T VbDCSN_mpfu_num_edges_isNaN;/* '<S183>/Relational Operator'
                                              * 0 = input is valid
                                                1 = input is NaN
                                              */
extern boolean_T VbDCSN_mpfu_num_markers_isNaN;/* '<S181>/Relational Operator'
                                                * 0 = input is valid
                                                  1 = input is NaN
                                                */
extern boolean_T VbDCSN_has_left_marker;/* '<S74>/Logical Operator3'
                                         * 0 = no left_marker
                                           1 = has left_marker
                                         */
extern boolean_T VbDCSN_has_right_marker;/* '<S74>/Logical Operator4'
                                          * 0 = no right_marker
                                            1 = has right_marker
                                          */
extern boolean_T VbDCSN_CL_delay_finished;/* '<S187>/RelationalOperator1'
                                           * Change lane request confirmed.
                                             Delay finished.
                                           */
extern boolean_T VbDCSN_speed_limit_enabled;/* '<S72>/Logical Operator'
                                             * Whether the speed limit output is enabled
                                             */
extern boolean_T VbDCSN_overspeed_warning;/* '<S66>/Switch'
                                           * 0 = speed in range
                                             1 = overspeed warning
                                           */
extern boolean_T VbDCSN_num_stop_lines_isNaN;/* '<S184>/Relational Operator'
                                              * The output stop lines number from mpfu
                                              */
extern boolean_T VbDCSN_has_valid_stop_line;/* '<S160>/Logical Operator2'
                                             * 0 = no valid stop line
                                               1 = has valid stop line
                                             */
extern boolean_T VbDCSN_stop_line_distance_isNaN;/* '<S160>/Merge5'
                                                  * 0 = distance from stop line is valid
                                                    1 = distance from stop line is NaN
                                                  */
extern boolean_T VbDCSN_accs_stop_finished;/* '<S70>/Logical Operator'
                                            * If ACCS finished the stop request from DCSN
                                            */
extern boolean_T VbDCSN_raw_stop_finished;/* '<S162>/Logical Operator1'
                                           * The raw signal:
                                             Whether ACCS has finished stop request before the stop line.
                                           */
extern boolean_T VbDCSN_hold_stop_finished;/* '<S172>/Switch'
                                            * The time hold signal:
                                              Whether ACCS has finished stop request before the stop line.
                                            */
extern boolean_T VbDCSN_raw_stop_finished_late;/* '<S162>/Logical Operator2'
                                                * The raw signal:
                                                  Whether ACCS has finished stop request after the stop line.
                                                */
extern boolean_T VbDCSN_stop_request_enabled;/* '<S72>/Logical Operator1'
                                              * 0 = Sending stop request is disabled
                                                1 = Sending stop request is ensabled
                                              */
extern boolean_T VbDCSN_should_send_stop_req;/* '<S162>/Logical Operator'
                                              * 0 = should not send stop req
                                                1 = should send stop req
                                              */
extern boolean_T VbDCSN_stop_line_is_close;/* '<S162>/Logical Operator3'
                                            * 0 = stop line is far
                                              1 = stop line is close and will be updated by vehicle speed
                                            */
extern boolean_T VbDCSN_stop_unsuccess;/* '<S162>/Relational Operator2'
                                        * Whether the ego vehicle failed to stop for this stop request
                                        */
extern boolean_T VbDCSN_stop_request;  /* '<S73>/Switch'
                                        * 0 = no stop request
                                          1 = stop request
                                        */
extern boolean_T VbDCSN_num_lanes_isNaN;/* '<S182>/Relational Operator'
                                         * Whether lanes number from mpfu is NaN
                                         */
extern boolean_T VbDCSN_has_ego_lane;  /* '<S75>/Logical Operator'
                                        * 0 = no ego lane
                                          1 = has ego lane
                                        */
extern boolean_T VbDCSN_spd_limt_max_isNaN;/* '<S75>/Merge1'
                                            * 0 = input speed limit is valid
                                              1 = input speed limit is NaN
                                            */
extern boolean_T VbDCSN_speed_limit_input_isNaN;/* '<S75>/Logical Operator1'
                                                 * 0 = input is valid
                                                   1 = input is NaN
                                                 */
extern boolean_T VbDCSN_change_lane_request;/* '<S73>/Switch3'
                                             * 0 = no change lane request
                                               1 = change lane request
                                             */
extern boolean_T VbDCSN_change_lane_cancel_request;/* '<S73>/Switch14'
                                                    * 0 = no change lane cancel request
                                                      1 = cancel change lane
                                                    */
extern boolean_T VbDCSN_inlane_nudge_request;/* '<S73>/Switch6'
                                              * 0 = no inlane nudge request
                                                1 = request inlane nudge
                                              */
extern boolean_T VbDCSN_pull_over_request;/* '<S73>/Switch8'
                                           * 0 = no pull over request
                                             1 = pull over
                                           */
extern boolean_T VbDCSN_stop_line_input_isNaN;/* '<S160>/Logical Operator3'
                                               * 0 = input is valid
                                                 1 = input is NaN
                                               */
extern boolean_T VbDCSN_egmo_is_ready; /* '<S179>/Compare'
                                        * 0 = egmo not ready
                                          1 = egmo ready
                                        */
extern boolean_T VbDCSN_mpfu_is_ready; /* '<S180>/Compare'
                                        * 0 = mpfu not ready
                                          1 = mpfu ready
                                        */
extern boolean_T VbDCSN_input_is_ready;/* '<S69>/Logical Operator'
                                        * 0 = input data is not ready
                                          1 = input data is ready
                                        */
extern boolean_T VbDCSN_right_marker_para_isNaN;/* '<S87>/Logical Operator'
                                                 * 0 = c0/c1/c2/c3 no NaN input
                                                   1 = c0/c1/c2/c3 have NaN input
                                                 */
extern boolean_T VbDCSN_left_marker_para_isNaN;/* '<S85>/Logical Operator'
                                                * 0 = c0/c1/c2/c3 no NaN input
                                                  1 = c0/c1/c2/c3 have NaN input
                                                */
extern boolean_T VbDCSN_right_edge_para_isNaN;/* '<S86>/Logical Operator'
                                               * 0 = c0/c1/c2/c3 no NaN input
                                                 1 = c0/c1/c2/c3 have NaN input
                                               */
extern boolean_T VbDCSN_left_edge_para_isNaN;/* '<S84>/Logical Operator'
                                              * 0 = c0/c1/c2/c3 no NaN input
                                                1 = c0/c1/c2/c3 have NaN input
                                              */
extern boolean_T VbDCSN_acc_feature_enable;/* '<S61>/Switch2'
                                            * 0 = acc not enabled
                                              1 = acc enabled
                                            */
extern boolean_T VbDCSN_power_control_inhibit;/* '<S58>/Logical Operator1'
                                               * 0 = power control not inhibit
                                                 1 = power control inhibit
                                               */
extern boolean_T VbDCSN_power_ctrl_enable;/* '<S61>/Switch7'
                                           * 0 = power not enabled
                                             1 = power enabled
                                           */
extern boolean_T VbDCSN_brake_ctrl_enable;/* '<S61>/Logical Operator9'
                                           * 0 = brake not enabled
                                             1 = brake enabled

                                           */
extern boolean_T VbDCSN_steer_ctrl_enable;/* '<S61>/Logical Operator2'
                                           * 0 = steer not enabled
                                             1 = steer enabled
                                           */
extern boolean_T VbDCSN_gear_ctrl_enable;/* '<S61>/Switch10'
                                          * 0 = gear not enabled
                                            1 = gear enabled
                                          */
extern boolean_T VbDCSN_epb_ctrl_enable;/* '<S61>/Switch11'
                                         * 0 = epb not enabled
                                           1 = epb enabled
                                         */
extern boolean_T VbDCSN_lcc_feature_enable;/* '<S61>/Switch'
                                            * 0 = lcc not enabled
                                              1 = lcc enabled

                                            */
extern boolean_T VbDCSN_alca_feature_enable;/* '<S61>/Switch1'
                                             * 0 = alca not enabled
                                               1 = alca enabled
                                             */
extern boolean_T VbDCSN_aeb_feature_enable;/* '<S61>/Switch3'
                                            * 0 = aeb not enabled
                                              1 = aeb enabled

                                            */
extern boolean_T VbDCSN_fcw_feature_enable;/* '<S61>/Switch4'
                                            * 0 = fcw not enabled
                                              1 = fcw enabled
                                            */
extern boolean_T VbDCSN_lcw_feature_enable;/* '<S61>/Switch5'
                                            * 0 = lcw not enabled
                                              1 = lcw enabled

                                            */
extern boolean_T VbDCSN_ldw_feature_enable;/* '<S61>/Switch6'
                                            * 0 = ldw not enabled
                                              1 = ldw enabled

                                            */
extern boolean_T VbDCSN_lka_feature_enable;/* '<S61>/Switch13'
                                            * 0 = lka not enabled
                                              1 = lka enabled

                                            */
extern boolean_T VbDCSN_bsd_feature_enable;/* '<S61>/Switch14'
                                            * 0 = bsd not enabled
                                              1 = bsd enabled

                                            */
extern boolean_T VbDCSN_lca_feature_enable;/* '<S61>/Switch17'
                                            * 0 = lca not enabled
                                              1 = lca enabled

                                            */
extern boolean_T VbDCSN_rcta_feature_enable;/* '<S61>/Switch18'
                                             * 0 = rcta not enabled
                                               1 = rcta enabled

                                             */
extern boolean_T VbDCSN_fcta_feature_enable;/* '<S61>/Switch19'
                                             * 0 = fcta not enabled
                                               1 = fcta enabled

                                             */
extern boolean_T VbDCSN_dow_feature_enable;/* '<S61>/Switch20'
                                            * 0 = dow not enabled
                                              1 = dow enabled

                                            */
extern boolean_T VbDCSN_cond_activate_met;/* '<S14>/Data Type Conversion'
                                           * 0 = no acitvate request when brake/gas pedal is pressed
                                             1 = activate request when brake/gas pedal is pressed
                                           */
extern boolean_T VbDCSN_fault_detected;/* '<S12>/Logical Operator'
                                        * Whether system fault is level 3,4,5.
                                        */
extern boolean_T VbDCSN_initialization_finished;/* '<S10>/Logical Operator'
                                                 * Initialization process is finished.
                                                   Including vehicle and controller.
                                                 */
extern boolean_T VbDCSN_ACC_ready_to_engage;/* '<S6>/Logical Operator'
                                             * ACCS subsystem ready
                                             */
extern boolean_T VbDCSN_autodrive_ready_to_engage;/* '<S15>/Logical Operator'
                                                   * Whether the requirements of autodrive activation is all satisfied.
                                                   */
extern boolean_T VbDCSN_autodrive_exit;/* '<S16>/Logical Operator'
                                        * the flag if autodrive reqest exit
                                        */
extern boolean_T VbDCSN_autodrive_warning;/* '<S17>/Logical Operator'
                                           * the flag if autodrive reqest warning
                                           */
extern boolean_T VbDCSN_accs_resume;   /* '<S3>/Switch2'
                                        * 0 = no accs resume request
                                          1 = accs resume request
                                        */
extern boolean_T VbDCSN_adm_steering_override;/* '<S9>/DtrmnDCSN_DrivIntention'
                                               * 0 = not override
                                                 1 = override
                                               */
extern boolean_T VbDCSN_adm_steering_resume;/* '<S9>/DtrmnDCSN_DrivIntention'
                                             * 0 = not resume
                                               1 = resume
                                             */
extern EnumDCSN_driving_direction VeDCSN_change_lane_req_side;/* '<S73>/Switch4'
                                                               * 0 = FORWARD
                                                                 1 = LEFT
                                                                 2 = RIGHT
                                                               */
extern EnumDCSN_driving_direction VfDCSN_inlane_nudge_side;/* '<S73>/Data Type Conversion6'
                                                            * inlane nudge side
                                                              0 = NA
                                                              1 = LEFT
                                                              2 = RIGHT
                                                            */
extern EnumDCSN_driving_direction VeDCSN_CL_req_side_pre;/* '<S186>/In1'
                                                          * 0 = FORWARD
                                                            1 = LEFT
                                                            2 = RIGHT
                                                          */
extern EnumDCSN_adm_main_mode VeDCSN_adm_main_mode;/* '<S8>/Switch'
                                                    * 0 = ADM_OFF
                                                      1 = ADM_STANDBY
                                                      2 = ADM_READY
                                                      3 = ADM_ACTIVE
                                                      4 = ADM_STEER_OVRD
                                                      5 = ADM_TAKEOVER_WARNING
                                                      6 = ADM_FAULT_WARNING
                                                      7 = ADM_FAULT_REACTION
                                                      8 = ADM_FAULT_DETECTED
                                                    */
extern EnumDCSN_adm_hmi_msg_display VeDCSN_hmi_msg_display;/* '<S8>/DtrmnDCSN_ADMManager'
                                                            * 0 = NO_MSG
                                                              1 = ACTIVE
                                                              2 = OVRD
                                                              3 = TAKOVER_REQ
                                                              4 = FAULT
                                                            */
extern EnumDCSN_adm_hmi_icon_display VeDCSN_hmi_icon_display;/* '<S8>/DtrmnDCSN_ADMManager'
                                                              * 0 = NO_ICON
                                                                1 = GREY_SOLID
                                                                2 = GREEN_SOLID
                                                                3 = BLUE_SOLID
                                                                4 = RED_FLASH_SLOW
                                                                5 = RED_FLASH_FAST
                                                                6 = RED_SOLID
                                                              */
extern EnumDCSN_autodrive_control_mode VeDCSN_autodrive_control_mode;/* '<S61>/Switch16'
                                                                      * 0 = AUTODRIVE_PASIV
                                                                      1 = AUTODRIVE_DELAY
                                                                      2 = AUTODRIVE_RE_ACTIV
                                                                      3 = AUTODRIVE_ACTIVATING
                                                                      4 = AUTODRIVE_ACTIVATED
                                                                      */
extern EnumDCSN_stop_reason VeDCSN_stop_reason;/* '<S73>/Switch10'
                                                * 0 = NO_STOP_REQUEST
                                                  1 = STOP_FOR_DESTINATION
                                                  2 = STOP_FOR_TRAFFIC_LIGHT
                                                  3 = STOP_FOR_STOP_SIGN
                                                  4 = STOP_FOR_STOP_LINE
                                                  5 = STOP_FOR_CROSSWALK
                                                  6 = STOP_FOR_KEEP_CLEAR
                                                */
extern EnumDCSN_speed_limit_reason VeDCSN_speed_limit_reason;/* '<S73>/Switch9'
                                                              * 0 = NO_LIMIT
                                                                1 = LIMIT_FOR_EGO_LANE
                                                                2 = LIMIT_FOR_DRIVER_REQ
                                                                3 = LIMIT_FOR_CROSSWALK
                                                                4 = LIMIT_FOR_NUDGE
                                                              */
extern EnumDCSN_change_lane_reason VeDCSN_change_lane_reason;/* '<S73>/Switch11'
                                                              * 0 = LC_NO_REQUEST
                                                                1 = LC_USER_CMD
                                                                2 = LC_NAVIGATION_CMD
                                                                3 = LC_FRONT_OBSTACLE
                                                              */
extern EnumDCSN_change_lane_cancel_reason VeDCSN_change_lane_cancel_reason;/* '<S73>/Switch15'
                                                                      * 0 = LC_CANCEL_NO_REQUEST
                                                                      1 = LC_CANCEL_USR_CMD
                                                                      */
extern EnumDCSN_inlane_nudge_reason VeDCSN_inlane_nudge_reason;/* '<S73>/Switch12'
                                                                * 0 = NUDGE_NO_REQUEST
                                                                  1 = NUDGE_FRONT_OBSTACLE
                                                                  2 = NUDGE_SIDE_OBSTACLE
                                                                */
extern EnumDCSN_pull_over_reason VeDCSN_pull_over_reason;/* '<S73>/Switch13'
                                                          * 0 = PULLOVER_NO_REQUEST
                                                            1 = PULLOVER_USER_CMD
                                                            2 = PULLOVER_POLICE
                                                            3 = PULLOVER_SYSTEM_FAULT
                                                          */
extern EnumDCSN_stop_request_mode VeDCSN_stop_request_mode;/* '<S162>/DtrmnDCSN_StopModeManager'
                                                            * 0 = NotEnabled
                                                              1 = WaitForValidStopLine
                                                              2 = CheckStopCond
                                                              3 = SendStopReqEgmoDis
                                                              4 = UpdateStopDis
                                                              5 = HoldForStopLineUpdate
                                                            */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T KfDCSN_M_adm_temp_steering_ovrd_torque;/* Variable: KfDCSN_M_adm_temp_steering_ovrd_torque
                                                        * Referenced by: '<S47>/KfDCSN_M_adm_temp_steering_ovrd_torque'
                                                        * The torque for driver to override.
                                                        */
extern real32_T KfDCSN_M_adm_temp_steering_resume_torque;/* Variable: KfDCSN_M_adm_temp_steering_resume_torque
                                                          * Referenced by: '<S48>/KfDCSN_M_adm_temp_steering_resume_torque'
                                                          * The torque for driver to override.
                                                          */
extern real32_T KfDCSN_a_curvature_sample_point[8];/* Variable: KfDCSN_a_curvature_sample_point
                                                    * Referenced by:
                                                    *   '<S74>/KfDCSN_a_curvature_sample_point'
                                                    *   '<S74>/KfDCSN_a_curvature_sample_point1'
                                                    * The sample point of curvature calculation. Unit is %.
                                                      From remote point to close point
                                                    */
extern real32_T KfDCSN_d_Thrsh_request_stop;/* Variable: KfDCSN_d_Thrsh_request_stop
                                             * Referenced by: '<S162>/KfDCSN_d_Thrsh_request_stop'
                                             * The maximal distance between vehicle and stop line before sending stop request.
                                             */
extern real32_T KfDCSN_d_arc_length_integration_step;/* Variable: KfDCSN_d_arc_length_integration_step
                                                      * Referenced by:
                                                      *   '<S74>/KfDCSN_d_arc_length_integration_step2'
                                                      *   '<S74>/KfDCSN_d_arc_length_integration_step3'
                                                      * The step size of arc length integration when caculating the look ahead distance for curvature.
                                                      */
extern real32_T KfDCSN_d_rearaxle_frontbump;/* Variable: KfDCSN_d_rearaxle_frontbump
                                             * Referenced by: '<S170>/KfDCSN_d_rearaxle_frontbump'
                                             * The distance between rear axle and front bumper
                                             */
extern real32_T KfDCSN_d_speed_limit_distance_man_value;/* Variable: KfDCSN_d_speed_limit_distance_man_value
                                                         * Referenced by: '<S73>/Constant21'
                                                         * targe speed limit point distance
                                                         */
extern real32_T KfDCSN_d_stop_cleared_Thrsh;/* Variable: KfDCSN_d_stop_cleared_Thrsh
                                             * Referenced by: '<S162>/KfDCSN_d_stop_cleared_Thrsh'
                                             * The extra distance vehicle has to move before receiving new stop request
                                             */
extern real32_T KfDCSN_d_stop_close_Thrsh;/* Variable: KfDCSN_d_stop_close_Thrsh
                                           * Referenced by: '<S162>/KfDCSN_d_stop_close_Thrsh'
                                           * The threshold whether stop distance is calculated by vehicle speed.
                                           */
extern real32_T KfDCSN_d_stop_distance_buffer;/* Variable: KfDCSN_d_stop_distance_buffer
                                               * Referenced by: '<S170>/KfDCSN_d_stop_distance_buffer'
                                               * The buffer between vehicle and stop destination
                                               */
extern real32_T KfDCSN_d_stop_finished_dis;/* Variable: KfDCSN_d_stop_finished_dis
                                            * Referenced by: '<S162>/KfDCSN_d_stop_finished_dis'
                                            * When ACC finished stop request, the maximal distance between stop point and ego vehicle.
                                              If the stop distance is larger than the value, the stop request will not be cleared.
                                            */
extern real32_T KfDCSN_d_stop_s_distance_man_value;/* Variable: KfDCSN_d_stop_s_distance_man_value
                                                    * Referenced by: '<S171>/Constant2'
                                                    * manual stop control distance, valid only when KbDCSN_stop_man_enbl = true
                                                    */
extern real32_T KfDCSN_d_stop_unsuccess_Thrsh;/* Variable: KfDCSN_d_stop_unsuccess_Thrsh
                                               * Referenced by:
                                               *   '<S162>/KfDCSN_d_stop_unsuccess_Thrsh'
                                               *   '<S162>/KfDCSN_d_stop_unsuccess_Thrsh1'
                                               * The maximal distance from vehicle to stop line if vehicle had passed the stop line. This will regard current stop action as an unsuccessful stop.
                                               */
extern real32_T KfDCSN_k_largest_curvature_filter;/* Variable: KfDCSN_k_largest_curvature_filter
                                                   * Referenced by:
                                                   *   '<S74>/KfDCSN_k_largest_curvature_filter'
                                                   *   '<S74>/KfDCSN_k_largest_curvature_filter1'
                                                   * manual stop control distance, valid only when KbDCSN_stop_man_enbl = true
                                                   */
extern real32_T KfDCSN_t_adm_temp_steering_ovrd_delay;/* Variable: KfDCSN_t_adm_temp_steering_ovrd_delay
                                                       * Referenced by: '<S9>/KfDCSN_t_adm_temp_steering_ovrd_delay'
                                                       * when override conditions are met, the time to delay before exit.
                                                       */
extern real32_T KfDCSN_t_adm_temp_steering_resume_delay;/* Variable: KfDCSN_t_adm_temp_steering_resume_delay
                                                         * Referenced by: '<S9>/KfDCSN_t_adm_temp_steering_resume_delay'
                                                         * When resume conditions are met, the time before re-engaged.
                                                         */
extern real32_T KfDCSN_t_allowed_time_cond_activate;/* Variable: KfDCSN_t_allowed_time_cond_activate
                                                     * Referenced by: '<S14>/KfDCSN_t_allowed_time_cond_activate1'
                                                     * When driver want to activate autodirve with brake or gas pedal, the max time allowed between pushing activate switch and releasing brake or gas pedal
                                                     */
extern real32_T KfDCSN_t_autodrive_control_mode_delay;/* Variable: KfDCSN_t_autodrive_control_mode_delay
                                                       * Referenced by: '<S63>/KfDCSN_t_autodrive_control_mode_delay'
                                                       * the time that the system keeps sending activating request
                                                       */
extern real32_T KfDCSN_t_autodrive_max_wait_time;/* Variable: KfDCSN_t_autodrive_max_wait_time
                                                  * Referenced by: '<S53>/KfDCSN_t_autodrive_max_wait_time'
                                                  * the maximal wait time before the vehicle response to our activating request
                                                  */
extern real32_T KfDCSN_t_max_eps_inhibit_power;/* Variable: KfDCSN_t_max_eps_inhibit_power
                                                * Referenced by: '<S58>/KfDCSN_t_max_eps_inhibit_power'
                                                * The maximal allowed delay time to inhibit power control if EPS cannot response to CMD
                                                */
extern real32_T KfDCSN_t_max_time_fault_warning;/* Variable: KfDCSN_t_max_time_fault_warning
                                                 * Referenced by: '<S8>/KfDCSN_t_max_time_fault_warning'
                                                 * allowed reaction time after fault warning and before triggering emergency stop
                                                 */
extern real32_T KfDCSN_t_max_time_to_takeover;/* Variable: KfDCSN_t_max_time_to_takeover
                                               * Referenced by: '<S8>/KfDCSN_t_time_allowed_to_takeover'
                                               * allowed reaction time after both lane markers are missed but before autodrive exit
                                               */
extern real32_T KfDCSN_t_max_wait_cond_activate;/* Variable: KfDCSN_t_max_wait_cond_activate
                                                 * Referenced by: '<S14>/KfDCSN_t_max_wait_cond_activate'
                                                 * When driver want to activate autodirve with brake or gas pedal, the max wait time for adm active
                                                 */
extern real32_T KfDCSN_t_sample_time;  /* Variable: KfDCSN_t_sample_time
                                        * Referenced by:
                                        *   '<S162>/KfDCSN_t_sample_time'
                                        *   '<S171>/KfDCSN_t_sample_time'
                                        * DCSN calculation sample time
                                        */
extern real32_T KfDCSN_t_stop_req_hold;/* Variable: KfDCSN_t_stop_req_hold
                                        * Referenced by:
                                        *   '<S172>/KfDCSN_t_stop_req_hold'
                                        *   '<S173>/KfDCSN_t_stop_req_hold'
                                        * When stop is finished, the stop request will be held for seconds.
                                        */
extern real32_T KfDCSN_t_usr_change_lane_delay;/* Variable: KfDCSN_t_usr_change_lane_delay
                                                * Referenced by: '<S185>/KfDCSN_t_usr_change_lane_delay'
                                                * The time delay between usr command and actual change lane action
                                                */
extern real32_T KfDCSN_v_adm_active_extraspeed;/* Variable: KfDCSN_v_adm_active_extraspeed
                                                * Referenced by:
                                                *   '<S20>/KfDCSN_v_adm_active_extraspeed'
                                                *   '<S34>/KfDCSN_v_adm_active_extraspeed'
                                                * When activating ACC control, max allowed delta speed between actual and ACC speed upper limit
                                                */
extern real32_T KfDCSN_v_adm_temp_veh_setspeed;/* Variable: KfDCSN_v_adm_temp_veh_setspeed
                                                * Referenced by: '<S8>/KfDCSN_v_adm_temp_veh_setspeed'
                                                * Current vehicle acc set speed.
                                                  Not connect with ACCS yet
                                                */
extern real32_T KfDCSN_v_autodrive_max_speed;/* Variable: KfDCSN_v_autodrive_max_speed
                                              * Referenced by: '<S23>/KfDCSN_v_autodrive_max_speed'
                                              * Max speed allowed by Autodrive system
                                                If vehicle speed is larger than this value, autodrive will be deactivated immediately.
                                              */
extern real32_T KfDCSN_v_change_lane_target_speed_man_value;/* Variable: KfDCSN_v_change_lane_target_speed_man_value
                                                             * Referenced by: '<S73>/Constant8'
                                                             * manual change lane target speed, valid only when KbDCSN_change_lane_man_enbl = true
                                                             */
extern real32_T KfDCSN_v_default_warning_speed;/* Variable: KfDCSN_v_default_warning_speed
                                                * Referenced by: '<S66>/KfDCSN_v_default_warning_speed'
                                                * The maximal speed allowed when input speed limit is missed before warning request.
                                                */
extern real32_T KfDCSN_v_lane_speed_limit_man_value;/* Variable: KfDCSN_v_lane_speed_limit_man_value
                                                     * Referenced by: '<S73>/Constant4'
                                                     * manual speed limit, valid only when KbDCSN_traffic_speed_limit_enble = true
                                                     */
extern real32_T KfDCSN_v_overspeed_warning_extra;/* Variable: KfDCSN_v_overspeed_warning_extra
                                                  * Referenced by:
                                                  *   '<S66>/KfDCSN_v_overspeed_warning_extra'
                                                  *   '<S66>/KfDCSN_v_overspeed_warning_extra1'
                                                  * The extra speed difference allowed when vehicle speed is higher than speed limit before warning request.
                                                  */
extern real32_T KfDCSN_v_setspeed_thrsh_hi;/* Variable: KfDCSN_v_setspeed_thrsh_hi
                                            * Referenced by:
                                            *   '<S20>/KfDCSN_v_setspeed_thrsh_hi'
                                            *   '<S34>/KfDCSN_v_setspeed_thrsh_hi'
                                            * Max allowed set speed for ACCS
                                            */
extern real32_T KfDCSN_v_target_speed_limit_man_value;/* Variable: KfDCSN_v_target_speed_limit_man_value
                                                       * Referenced by: '<S73>/Constant20'
                                                       * target speed in manual mode
                                                       */
extern real32_T KtDCSN_c_speed_limit_curve_axis[21];/* Variable: KtDCSN_c_speed_limit_curve_axis
                                                     * Referenced by: '<S74>/1-D Lookup Table'
                                                     * Speed limit from curvature look up table axis
                                                     */
extern real32_T KtDCSN_t_curvature_ahead_timegap[10];/* Variable: KtDCSN_t_curvature_ahead_timegap
                                                      * Referenced by: '<S74>/1-D Lookup Table1'
                                                      * The look-ahead time gap for speed limit from curvature
                                                      */
extern real32_T KtDCSN_v_ahead_timegap_speed_axis[10];/* Variable: KtDCSN_v_ahead_timegap_speed_axis
                                                       * Referenced by: '<S74>/1-D Lookup Table1'
                                                       * The look-ahead time gap for speed limit from curvature
                                                         speed axis
                                                       */
extern real32_T KtDCSN_v_speed_limit_curve[21];/* Variable: KtDCSN_v_speed_limit_curve
                                                * Referenced by: '<S74>/1-D Lookup Table'
                                                * Speed limit from curvature value
                                                */
extern uint8_T KbDCSN_SLEW_DriveModeComd_value;/* Variable: KbDCSN_SLEW_DriveModeComd_value
                                                * Referenced by: '<S61>/KbDCSN_SLEW_DriveModeComd_value'
                                                * SLEW mode
                                                  the DriveModeComd value
                                                */
extern uint8_T KcDCSN_t_usr_activate_cmd_send_count;/* Variable: KcDCSN_t_usr_activate_cmd_send_count
                                                     * Referenced by: '<S7>/KcDCSN_t_usr_activate_cmd_send_count1'
                                                     * send count of usr_activate_action, valid when KbDCSN_use_vehicle_activate_switch = true
                                                       unit: seconds
                                                     */
extern uint8_T KeDCSN_adm_main_mode_man_value;/* Variable: KeDCSN_adm_main_mode_man_value
                                               * Referenced by: '<S8>/Constant3'
                                               * manual override of adm_main_mode output as uint8:

                                                 0 = ADM_OFF
                                                 1 = ADM_STANDBY
                                                 2 = ADM_READY
                                                 3 = ADM_ACTIVE
                                                 4 = ADM_STEER_OVRD
                                                 5 = ADM_TAKEOVER_WARNING
                                                 6 = ADM_FAULT_WARNING76 = ADM_FAULT_REACTION
                                                 8 = ADM_FAULT_DETECTED
                                               */
extern uint8_T KeDCSN_adm_temp_diag_system_fault;/* Variable: KeDCSN_adm_temp_diag_system_fault
                                                  * Referenced by: '<S8>/KeDCSN_adm_temp_diag_system_fault'
                                                  * System faults
                                                    0 = no fault
                                                    1,2 = warning faults
                                                    3,4,5 = exit faults
                                                  */
extern uint8_T KeDCSN_change_lane_cancel_reason_man_value;/* Variable: KeDCSN_change_lane_cancel_reason_man_value
                                                           * Referenced by: '<S73>/Constant19'
                                                           * 0 = LC_CANCEL_NO_REQUEST
                                                             1 = LC_CANCEL_USR_CMD
                                                           */
extern uint8_T KeDCSN_change_lane_reason_man_value;/* Variable: KeDCSN_change_lane_reason_man_value
                                                    * Referenced by: '<S73>/Constant16'
                                                    * 0 = LC_NO_REQUEST
                                                      1 = LC_USER_CMD
                                                      2 = LC_NAVIGATION_CMD
                                                      3 = LC_FRONT_OBSTACLE
                                                    */
extern uint8_T KeDCSN_change_lane_req_side_man_value;/* Variable: KeDCSN_change_lane_req_side_man_value
                                                      * Referenced by: '<S73>/Constant7'
                                                      * manual change lane side, valid only when KbDCSN_change_lane_man_enbl = true
                                                        0 = NA
                                                        1 = LEFT
                                                        2 = RIGHT
                                                      */
extern uint8_T KeDCSN_control_mode_man_value;/* Variable: KeDCSN_control_mode_man_value
                                              * Referenced by: '<S61>/ldw_switch2'
                                              * 0 = AUTODRIVE_PASIV
                                                1 = AUTODRIVE_DELAY
                                                2 = AUTODRIVE_RE_ACTIV
                                                3 = AUTODRIVE_ACTIVATING
                                                4 = AUTODRIVE_ACTIVATED
                                              */
extern uint8_T KeDCSN_inlane_nudge_reason_man_value;/* Variable: KeDCSN_inlane_nudge_reason_man_value
                                                     * Referenced by: '<S73>/Constant17'
                                                     * 0 = NUDGE_NO_REQUEST
                                                       1 = NUDGE_FRONT_OBSTACLE
                                                       2 = NUDGE_SIDE_OBSTACLE
                                                     */
extern uint8_T KeDCSN_pull_over_reason_man_value;/* Variable: KeDCSN_pull_over_reason_man_value
                                                  * Referenced by: '<S73>/Constant18'
                                                  * 0 = PULLOVER_NO_REQUEST
                                                    1 = PULLOVER_USER_CMD
                                                    2 = PULLOVER_POLICE
                                                    3 = PULLOVER_SYSTEM_FAULT
                                                  */
extern uint8_T KeDCSN_speed_limit_reason_man_value;/* Variable: KeDCSN_speed_limit_reason_man_value
                                                    * Referenced by: '<S73>/Constant14'
                                                    * 0 = NO_LIMIT
                                                      1 = LIMIT_FOR_EGO_LANE
                                                      2 = LIMIT_FOR_DRIVER_REQ
                                                      3 = LIMIT_FOR_CROSSWALK
                                                      4 = LIMIT_FOR_NUDGE
                                                    */
extern uint8_T KeDCSN_stop_reason_man_value;/* Variable: KeDCSN_stop_reason_man_value
                                             * Referenced by: '<S73>/Constant15'
                                             * 0 = NO_STOP_REQUEST
                                               1 = STOP_FOR_DESTINATION
                                               2 = STOP_FOR_TRAFFIC_LIGHT
                                               3 = STOP_FOR_STOP_SIGN
                                               4 = STOP_FOR_STOP_LINE
                                               5 = STOP_FOR_CROSSWALK
                                               6 = STOP_FOR_KEEP_CLEAR
                                             */
extern uint8_T KeDCSN_usr_cmd_autodrive_activate_man;/* Variable: KeDCSN_usr_cmd_autodrive_activate_man
                                                      * Referenced by: '<S7>/KfDCSN_adm_temp_usr_cmd_autodrive_activated'
                                                      * 0 = Deactivate
                                                        1 = Activate
                                                        2 = Hold
                                                      */
extern uint8_T KfDCSN_Pct_lane_marker_valid_quality;/* Variable: KfDCSN_Pct_lane_marker_valid_quality
                                                     * Referenced by:
                                                     *   '<S78>/KfDCSN_Pct_lane_marker_valid_quality'
                                                     *   '<S79>/KfDCSN_Pct_lane_marker_valid_quality'
                                                     * The quality threshold for valid lane marker or edge
                                                     */
extern uint8_T KfDCSN_d_inlane_nudge_side_man_value;/* Variable: KfDCSN_d_inlane_nudge_side_man_value
                                                     * Referenced by: '<S73>/Constant12'
                                                     * manual inlane nudge side, valid only when KbDCSN_inlane_nudge_man_enbl = true
                                                       0 = NA
                                                       1 = LEFT
                                                       2 = RIGHT
                                                     */
extern boolean_T KbDCSN_SLEW_DriveModeComd_enbl;/* Variable: KbDCSN_SLEW_DriveModeComd_enbl
                                                 * Referenced by: '<S61>/KbDCSN_SLEW_DriveModeComd_enbl'
                                                 * 0 = use COMM DriverModeComd
                                                   1 = use SLEW DriverModeComd
                                                 */
extern boolean_T KbDCSN_SLEW_initialization_finished;/* Variable: KbDCSN_SLEW_initialization_finished
                                                      * Referenced by: '<S10>/KbDCSN_SLEW_initialization_finished'
                                                      * 0 = use initialization finished judgement logic
                                                        1 = initialization finished
                                                      */
extern boolean_T KbDCSN_acc_man_enbl;  /* Variable: KbDCSN_acc_man_enbl
                                        * Referenced by: '<S61>/aeb_switch2'
                                        * 0 = manual override disabled
                                          1 = manual override enabled
                                        */
extern boolean_T KbDCSN_accs_resume_man_enbl;/* Variable: KbDCSN_accs_resume_man_enbl
                                              * Referenced by: '<S3>/aeb_switch12'
                                              * 0 = manual accs resume override disabled
                                                1 = manual accs resume override enabled
                                              */
extern boolean_T KbDCSN_accs_resume_man_value;/* Variable: KbDCSN_accs_resume_man_value
                                               * Referenced by: '<S3>/aeb_switch8'
                                               * manual change lane switch, valid only when KbDCSN_accs_resume_man_enbl = true
                                                 Pulse signal when reverse.
                                               */
extern boolean_T KbDCSN_active_feature_man_ctrl;/* Variable: KbDCSN_active_feature_man_ctrl
                                                 * Referenced by: '<S61>/aeb_switch4'
                                                 * For all active features (ACC, LCC, ALCA):
                                                   0 = manual override disabled
                                                   1 = manual override enabled
                                                 */
extern boolean_T KbDCSN_adm_BrkPressDeactivateEnabled;/* Variable: KbDCSN_adm_BrkPressDeactivateEnabled
                                                       * Referenced by: '<S23>/Constant7'
                                                       * 0 = cannot activate when BrkPed is pressed
                                                         1 = can activate when BrkPed is pressed
                                                       */
extern boolean_T KbDCSN_adm_main_mode_man_ctrl;/* Variable: KbDCSN_adm_main_mode_man_ctrl
                                                * Referenced by:
                                                *   '<S8>/Constant2'
                                                *   '<S60>/Constant5'
                                                * 0 = manual override disabled
                                                  1 = manual override enabled
                                                */
extern boolean_T KbDCSN_adm_temp_stop_finished;/* Variable: KbDCSN_adm_temp_stop_finished
                                                * Referenced by: '<S8>/KfDCSN_adm_temp_stop_finished'
                                                * 0 = not finished
                                                  1 = finished
                                                */
extern boolean_T KbDCSN_adm_temp_usr_cmd_autodrive_enabled;/* Variable: KbDCSN_adm_temp_usr_cmd_autodrive_enabled
                                                            * Referenced by: '<S8>/KfDCSN_adm_temp_usr_cmd_autodrive_enabled'
                                                            * 0 = not enabled
                                                              1 = enabled
                                                            */
extern boolean_T KbDCSN_aeb_man_enbl;  /* Variable: KbDCSN_aeb_man_enbl
                                        * Referenced by: '<S61>/aeb_switch'
                                        * 0 = Close AEB
                                          1 = Open AEB
                                        */
extern boolean_T KbDCSN_aeb_usr_switch;/* Variable: KbDCSN_aeb_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_aeb_usr_switch'
                                        * AEB feature user switch
                                        */
extern boolean_T KbDCSN_alca_man_enbl; /* Variable: KbDCSN_alca_man_enbl
                                        * Referenced by: '<S61>/aeb_switch3'
                                        * 0 = manual override disabled
                                          1 = manual override enabled
                                        */
extern boolean_T KbDCSN_alca_usr_switch;/* Variable: KbDCSN_alca_usr_switch
                                         * Referenced by: '<S52>/KbDCSN_acla_usr_switch'
                                         * ALCA feature user switch
                                         */
extern boolean_T KbDCSN_brake_ctrl_man_enbl;/* Variable: KbDCSN_brake_ctrl_man_enbl
                                             * Referenced by: '<S61>/aeb_switch12'
                                             * 0 = manual override disabled
                                               1 = manual override enabled
                                             */
extern boolean_T KbDCSN_brake_ctrl_man_value;/* Variable: KbDCSN_brake_ctrl_man_value
                                              * Referenced by: '<S61>/aeb_switch8'
                                              * manual brake control switch, valid only when KbDCSN_brake_ctrl_man_enbl = true
                                                0 = brake control off
                                                1 = brake control on
                                              */
extern boolean_T KbDCSN_bsd_man_enbl;  /* Variable: KbDCSN_bsd_man_enbl
                                        * Referenced by: '<S61>/ldw_switch4'
                                        * 0 = Close BSD
                                          1 = Open BSD
                                        */
extern boolean_T KbDCSN_bsd_usr_switch;/* Variable: KbDCSN_bsd_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_bsd_usr_switch'
                                        * BSD feature user switch
                                        */
extern boolean_T KbDCSN_change_lane_cancel_request_man_value;/* Variable: KbDCSN_change_lane_cancel_request_man_value
                                                              * Referenced by: '<S73>/Constant2'
                                                              * manual change lane switch, valid only when KbDCSN_change_lane_man_enbl = true
                                                                0 = no change lane cancel request
                                                                1 = change lane cancel request
                                                              */
extern boolean_T KbDCSN_change_lane_enable;/* Variable: KbDCSN_change_lane_enable
                                            * Referenced by: '<S72>/KbDCSN_change_lane_enable'
                                            * 0 = disable change lane request
                                              1 = enable change lane request
                                            */
extern boolean_T KbDCSN_change_lane_man_enbl;/* Variable: KbDCSN_change_lane_man_enbl
                                              * Referenced by: '<S73>/Constant5'
                                              * traffic decider
                                                0 = manual change lane off
                                                1 = manual change lane on
                                              */
extern boolean_T KbDCSN_change_lane_request_man_value;/* Variable: KbDCSN_change_lane_request_man_value
                                                       * Referenced by: '<S73>/Constant6'
                                                       * manual change lane switch, valid only when KbDCSN_change_lane_man_enbl = true
                                                         0 = no change lane request
                                                         1 = change lane request
                                                       */
extern boolean_T KbDCSN_control_mode_man_enbl;/* Variable: KbDCSN_control_mode_man_enbl
                                               * Referenced by: '<S61>/ldw_switch1'
                                               * Override the output auotdirve control main mode.
                                                 0 = not override
                                                 1 = override
                                               */
extern boolean_T KbDCSN_dow_man_enbl;  /* Variable: KbDCSN_dow_man_enbl
                                        * Referenced by: '<S61>/ldw_switch8'
                                        * 0 = Close DOW
                                          1 = Open DOW
                                        */
extern boolean_T KbDCSN_dow_usr_switch;/* Variable: KbDCSN_dow_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_dow_usr_switch'
                                        * DOW feature user switch
                                        */
extern boolean_T KbDCSN_enable_warning_no_input;/* Variable: KbDCSN_enable_warning_no_input
                                                 * Referenced by: '<S66>/KbDCSN_enable_warning_no_input'
                                                 * 0 = disable warning if no speed limit input
                                                   1 = use default speed limit to warn if no speed limit input
                                                 */
extern boolean_T KbDCSN_epb_ctrl_man_enbl;/* Variable: KbDCSN_epb_ctrl_man_enbl
                                           * Referenced by: '<S61>/aeb_switch15'
                                           * 0 = manual override disabled
                                             1 = manual override enabled
                                           */
extern boolean_T KbDCSN_epb_ctrl_man_value;/* Variable: KbDCSN_epb_ctrl_man_value
                                            * Referenced by: '<S61>/aeb_switch11'
                                            * manual epb control switch, valid only when KbDCSN_epb_ctrl_man_enbl = true
                                              0 = epb release
                                              1 = epb engage
                                            */
extern boolean_T KbDCSN_fcta_man_enbl; /* Variable: KbDCSN_fcta_man_enbl
                                        * Referenced by: '<S61>/ldw_switch7'
                                        * 0 = Close FCTA
                                          1 = Open FCTA
                                        */
extern boolean_T KbDCSN_fcta_usr_switch;/* Variable: KbDCSN_fcta_usr_switch
                                         * Referenced by: '<S4>/KbDCSN_fcta_usr_switch'
                                         * FCTA feature user switch
                                         */
extern boolean_T KbDCSN_fcw_man_enbl;  /* Variable: KbDCSN_fcw_man_enbl
                                        * Referenced by: '<S61>/fcw_switch'
                                        * 0 = manual FCW off
                                          1 = manual FCW on
                                        */
extern boolean_T KbDCSN_fcw_usr_switch;/* Variable: KbDCSN_fcw_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_fcw_usr_switch'
                                        * FCW feature user switch
                                        */
extern boolean_T KbDCSN_gear_ctrl_man_enbl;/* Variable: KbDCSN_gear_ctrl_man_enbl
                                            * Referenced by: '<S61>/aeb_switch14'
                                            * 0 = manual override disabled
                                              1 = manual override enabled
                                            */
extern boolean_T KbDCSN_gear_ctrl_man_value;/* Variable: KbDCSN_gear_ctrl_man_value
                                             * Referenced by: '<S61>/aeb_switch10'
                                             * manual gear control switch, valid only when KbDCSN_gear_ctrl_man_enbl = true
                                               0 = gear control off
                                               1 = gear control on
                                             */
extern boolean_T KbDCSN_inhibit_power_for_eps_enable;/* Variable: KbDCSN_inhibit_power_for_eps_enable
                                                      * Referenced by: '<S58>/KbDCSN_inhibit_power_for_eps_enable'
                                                      * 0 = disable power inhibit when EPS is out of control
                                                        1 = enable power inhibit when EPS is out of control
                                                      */
extern boolean_T KbDCSN_inlane_nudge_man_enbl;/* Variable: KbDCSN_inlane_nudge_man_enbl
                                               * Referenced by: '<S73>/Constant9'
                                               * traffic decider
                                                 0 = manual inlane nudge off
                                                 1 = manual inlane nudge on
                                               */
extern boolean_T KbDCSN_inlane_nudge_request_man_value;/* Variable: KbDCSN_inlane_nudge_request_man_value
                                                        * Referenced by: '<S73>/Constant11'
                                                        * manual inlane nudge switch, valid only when KbDCSN_inlane_nudge_request_man_enbl = true
                                                          0 = no inlane nudge request
                                                          1 = inlane nudge request
                                                        */
extern boolean_T KbDCSN_lca_man_enbl;  /* Variable: KbDCSN_lca_man_enbl
                                        * Referenced by: '<S61>/ldw_switch5'
                                        * 0 = Close LCA
                                          1 = Open LCA
                                        */
extern boolean_T KbDCSN_lca_usr_switch;/* Variable: KbDCSN_lca_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_lca_usr_switch'
                                        * LCA feature user switch
                                        */
extern boolean_T KbDCSN_lcc_man_enbl;  /* Variable: KbDCSN_lcc_man_enbl
                                        * Referenced by: '<S61>/aeb_switch1'
                                        * 0 = manual LCC off
                                          1 = manual LCC on
                                        */
extern boolean_T KbDCSN_lcc_usr_switch;/* Variable: KbDCSN_lcc_usr_switch
                                        * Referenced by: '<S8>/KbDCSN_lcc_usr_switch'
                                        * LCC feature user switch
                                        */
extern boolean_T KbDCSN_lcw_man_enbl;  /* Variable: KbDCSN_lcw_man_enbl
                                        * Referenced by: '<S61>/lcw_switch'
                                        * 0 = manual LCW off
                                          1 = manual LCW on
                                        */
extern boolean_T KbDCSN_lcw_usr_switch;/* Variable: KbDCSN_lcw_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_lcw_usr_switch'
                                        * LCW feature user switch
                                        */
extern boolean_T KbDCSN_ldw_man_enbl;  /* Variable: KbDCSN_ldw_man_enbl
                                        * Referenced by: '<S61>/ldw_switch'
                                        * 0 = manual LDW off
                                          1 = manual LDW on
                                        */
extern boolean_T KbDCSN_ldw_usr_switch;/* Variable: KbDCSN_ldw_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_ldw_usr_switch'
                                        * LDW feature user switch
                                        */
extern boolean_T KbDCSN_lka_man_enbl;  /* Variable: KbDCSN_lka_man_enbl
                                        * Referenced by: '<S61>/ldw_switch3'
                                        * 0 = Close LKA
                                          1 = Open LKA
                                        */
extern boolean_T KbDCSN_lka_usr_switch;/* Variable: KbDCSN_lka_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_lka_usr_switch'
                                        * LKA feature user switch
                                        */
extern boolean_T KbDCSN_overspeed_warning_enable;/* Variable: KbDCSN_overspeed_warning_enable
                                                  * Referenced by: '<S72>/KbDCSN_overspeed_warning_enable'
                                                  * 0 = disable overspeed warning
                                                    1 = enable overspeed warning
                                                  */
extern boolean_T KbDCSN_passive_feature_man_ctrl;/* Variable: KbDCSN_passive_feature_man_ctrl
                                                  * Referenced by: '<S61>/aeb_switch5'
                                                  * For all passive features (AEB, FCW, LDW, LCW):
                                                    0 = manual override disabled
                                                    1 = manual override enabled
                                                  */
extern boolean_T KbDCSN_power_ctrl_man_enbl;/* Variable: KbDCSN_power_ctrl_man_enbl
                                             * Referenced by: '<S61>/aeb_switch6'
                                             * 0 = manual override disabled
                                               1 = manual override enabled
                                             */
extern boolean_T KbDCSN_power_ctrl_man_value;/* Variable: KbDCSN_power_ctrl_man_value
                                              * Referenced by: '<S61>/aeb_switch7'
                                              * manual power control switch, valid only when KbDCSN_power_ctrl_man_enbl = true
                                                0 = power control off
                                                1 = power control on
                                              */
extern boolean_T KbDCSN_pull_over_man_enbl;/* Variable: KbDCSN_pull_over_man_enbl
                                            * Referenced by: '<S73>/Constant10'
                                            * traffic decider
                                              0 = manual pull over off
                                              1 = manual pull over on
                                            */
extern boolean_T KbDCSN_pull_over_request_man_value;/* Variable: KbDCSN_pull_over_request_man_value
                                                     * Referenced by: '<S73>/Constant13'
                                                     * manual pull over switch, valid only when KbDCSN_pull_over_request_man_enbl = true
                                                       0 = no pull over request
                                                       1 = pull over request
                                                     */
extern boolean_T KbDCSN_rcta_man_enbl; /* Variable: KbDCSN_rcta_man_enbl
                                        * Referenced by: '<S61>/ldw_switch6'
                                        * 0 = Close RCTA
                                          1 = Open RCTA
                                        */
extern boolean_T KbDCSN_rcta_usr_switch;/* Variable: KbDCSN_rcta_usr_switch
                                         * Referenced by: '<S4>/KbDCSN_rcta_usr_switch'
                                         * RCTA feature user switch
                                         */
extern boolean_T KbDCSN_speed_limit_enable;/* Variable: KbDCSN_speed_limit_enable
                                            * Referenced by: '<S72>/KbDCSN_speed_limit_enable'
                                            * 0 = disable speed limit output
                                              1 = enable speed limit output
                                            */
extern boolean_T KbDCSN_speed_limit_man_enbl;/* Variable: KbDCSN_speed_limit_man_enbl
                                              * Referenced by: '<S73>/Constant3'
                                              * traffic decider
                                                0 = manual speed limit off
                                                1 = manual speed limit on
                                              */
extern boolean_T KbDCSN_steer_ctrl_man_enbl;/* Variable: KbDCSN_steer_ctrl_man_enbl
                                             * Referenced by: '<S61>/aeb_switch13'
                                             * 0 = manual override disabled
                                               1 = manual override enabled
                                             */
extern boolean_T KbDCSN_steer_ctrl_man_value;/* Variable: KbDCSN_steer_ctrl_man_value
                                              * Referenced by: '<S61>/aeb_switch9'
                                              * manual steer control switch, valid only when KbDCSN_steer_ctrl_man_enbl = true
                                                0 = steer control off
                                                1 = steer control on
                                              */
extern boolean_T KbDCSN_stop_man_enbl; /* Variable: KbDCSN_stop_man_enbl
                                        * Referenced by: '<S73>/Constant'
                                        * traffic decider
                                          0 = manual stop off
                                          1 = manual stop on
                                        */
extern boolean_T KbDCSN_stop_request_enable;/* Variable: KbDCSN_stop_request_enable
                                             * Referenced by: '<S72>/KbDCSN_stop_request_enable'
                                             * 0 = disable stop request output
                                               1 = enable stop request output
                                             */
extern boolean_T KbDCSN_stop_request_man_value;/* Variable: KbDCSN_stop_request_man_value
                                                * Referenced by:
                                                *   '<S73>/Constant1'
                                                *   '<S161>/Constant1'
                                                * manual stop control switch, valid only when KbDCSN_stop_man_enbl = true
                                                  0 = no stop request
                                                  1 = stop request
                                                */
extern boolean_T KbDCSN_use_EgmoLinearSpeed;/* Variable: KbDCSN_use_EgmoLinearSpeed
                                             * Referenced by: '<S3>/aeb_switch1'
                                             * 0 = Use vehicle CAN velocity
                                               1 = Use egmo linear velocity
                                             */
extern boolean_T KbDCSN_use_EgmoReadyFlag;/* Variable: KbDCSN_use_EgmoReadyFlag
                                           * Referenced by:
                                           *   '<S3>/aeb_switch16'
                                           *   '<S4>/aeb_switch16'
                                           * 0 = use calibration to output EGMO ready flag
                                             1 = use EGMO ready flag
                                           */
extern boolean_T KbDCSN_use_MpfuReadyFlag;/* Variable: KbDCSN_use_MpfuReadyFlag
                                           * Referenced by: '<S3>/aeb_switch2'
                                           * 0 = use calibration to output MPFU ready flag
                                             1 = use MPFU ready flag
                                           */
extern boolean_T KbDCSN_use_SLEW_override_logic;/* Variable: KbDCSN_use_SLEW_override_logic
                                                 * Referenced by: '<S60>/aeb_switch17'
                                                 * 0 = disable override logic in SLEW
                                                   1 = enable override logic in SLEW

                                                 */
extern boolean_T KbDCSN_use_SLEW_switch_control_mode;/* Variable: KbDCSN_use_SLEW_switch_control_mode
                                                      * Referenced by: '<S53>/KbDCSN_use_SLEW_switch_control_mode'
                                                      * 0 = Use normal control mode logic
                                                        1 = Use driver switch as control mode activated
                                                      */
extern boolean_T KbDCSN_use_faw_handoff_as_ovrd;/* Variable: KbDCSN_use_faw_handoff_as_ovrd
                                                 * Referenced by: '<S46>/KbDCSN_use_faw_handoff_as_ovrd'
                                                 * 0 = use HandOn flag as override flag
                                                   1 = use HandOff flag as override flag
                                                 */
extern boolean_T KbDCSN_use_faw_handoff_as_resume;/* Variable: KbDCSN_use_faw_handoff_as_resume
                                                   * Referenced by: '<S46>/KbDCSN_use_faw_handoff_as_resume'
                                                   * 0 = use HandOn flag as resume flag
                                                     1 = use HandOff flag as resume flag
                                                   */
extern boolean_T KbDCSN_use_faw_l4_logic;/* Variable: KbDCSN_use_faw_l4_logic
                                          * Referenced by:
                                          *   '<S10>/KbDCSN_use_faw_l4_logic1'
                                          *   '<S55>/KbDCSN_use_faw_l4_logic'
                                          *   '<S56>/KbDCSN_use_faw_l4_logic'
                                          *   '<S45>/KbDCSN_use_faw_l4_logic2'
                                          *   '<S46>/KbDCSN_use_faw_l4_logic1'
                                          *   '<S46>/KbDCSN_use_faw_l4_logic2'
                                          *   '<S47>/KbDCSN_use_faw_l4_logic2'
                                          *   '<S48>/KbDCSN_use_faw_l4_logic2'
                                          *   '<S62>/KbDCSN_use_faw_l4_logic1'
                                          *   '<S63>/KbDCSN_use_faw_l4_logic1'
                                          *   '<S64>/KbDCSN_use_faw_l4_logic1'
                                          *   '<S20>/KbDCSN_use_faw_l4_logic'
                                          *   '<S20>/KbDCSN_use_faw_l4_logic1'
                                          *   '<S20>/KbDCSN_use_faw_l4_logic2'
                                          *   '<S23>/KbDCSN_use_faw_l4_logic'
                                          *   '<S23>/KbDCSN_use_faw_l4_logic1'
                                          *   '<S23>/KbDCSN_use_faw_l4_logic2'
                                          * 0 = use jac l3 logic
                                            1 = use faw l4 logic
                                          */
extern boolean_T KbDCSN_use_vehicle_activate_switch;/* Variable: KbDCSN_use_vehicle_activate_switch
                                                     * Referenced by: '<S7>/KbDCSN_use_vehicle_activate_switch'
                                                     * 0 = use calibration activate switch
                                                       1 = use vehicle activate switch
                                                     */

/* Model entry point functions */
extern void DCSN_subsystem_integrated_initialize(void);
extern void DCSN_subsystem_integrated_step(void);

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
 * '<Root>' : 'DCSN_subsystem_integrated'
 * '<S1>'   : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated'
 * '<S2>'   : 'DCSN_subsystem_integrated/Release Note'
 * '<S3>'   : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM'
 * '<S4>'   : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager'
 * '<S5>'   : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider'
 * '<S6>'   : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/CheckDCSN_ACCS_mode'
 * '<S7>'   : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/CheckDCSN_UsrSwitchStatus'
 * '<S8>'   : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager'
 * '<S9>'   : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_DRIVIintentionSimu'
 * '<S10>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_InitializationManager'
 * '<S11>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck'
 * '<S12>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_SystemFaultCheck'
 * '<S13>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/DtrmnDCSN_ADMManager'
 * '<S14>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/DtrmnDCSN_CondActivation'
 * '<S15>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ActivationStateCheck'
 * '<S16>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ExitStateCheck'
 * '<S17>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_WarningStateCheck'
 * '<S18>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ActivationStateCheck/CheckDCSN_HWActivation'
 * '<S19>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ActivationStateCheck/CheckDCSN_SWActivation'
 * '<S20>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ActivationStateCheck/CheckDCSN_VehicleActivation'
 * '<S21>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ExitStateCheck/CheckDCSN_HWExit'
 * '<S22>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ExitStateCheck/CheckDCSN_SWExit'
 * '<S23>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ExitStateCheck/CheckDCSN_VehicleExit'
 * '<S24>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ExitStateCheck/CheckDCSN_SWExit/OnDelay'
 * '<S25>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ExitStateCheck/CheckDCSN_SWExit/OnDelay1'
 * '<S26>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ExitStateCheck/CheckDCSN_SWExit/OnDelay2'
 * '<S27>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ExitStateCheck/CheckDCSN_VehicleExit/OnDelay1'
 * '<S28>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ExitStateCheck/CheckDCSN_VehicleExit/OnDelay2'
 * '<S29>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ExitStateCheck/CheckDCSN_VehicleExit/OnDelay3'
 * '<S30>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ExitStateCheck/CheckDCSN_VehicleExit/OnDelay4'
 * '<S31>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_ExitStateCheck/CheckDCSN_VehicleExit/OnDelay5'
 * '<S32>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_WarningStateCheck/CheckDCSN_HWWarning'
 * '<S33>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_WarningStateCheck/CheckDCSN_SWWarning'
 * '<S34>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_StateCheck/CheckDCSN_WarningStateCheck/CheckDCSN_VehicleWarning'
 * '<S35>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_SystemFaultCheck/Compare To Zero'
 * '<S36>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/CheckDCSN_SystemFaultCheck/Fault_level_division'
 * '<S37>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/DtrmnDCSN_CondActivation/Compare To Constant'
 * '<S38>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/DtrmnDCSN_CondActivation/Compare To Constant1'
 * '<S39>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/DtrmnDCSN_CondActivation/Compare To Constant2'
 * '<S40>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/DtrmnDCSN_CondActivation/Compare To Constant3'
 * '<S41>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/DtrmnDCSN_CondActivation/CvrtDCSN_DataConvert'
 * '<S42>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/DtrmnDCSN_CondActivation/S-R Flip-Flop'
 * '<S43>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_ADMMainManager/DtrmnDCSN_CondActivation/S-R Flip-Flop1'
 * '<S44>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_DRIVIintentionSimu/DtrmnDCSN_DrivIntention'
 * '<S45>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_DRIVIintentionSimu/DtrmnDCSN_FAWTorqueOverride'
 * '<S46>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_DRIVIintentionSimu/DtrmnDCSN_TakeOverLogicFAW'
 * '<S47>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_DRIVIintentionSimu/SteerOvrrideTorque'
 * '<S48>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_DRIVIintentionSimu/SteerResumeTorque'
 * '<S49>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_InitializationManager/Compare To Constant'
 * '<S50>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_InitializationManager/Compare To Constant1'
 * '<S51>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_ADM/DtrmnDCSN_InitializationManager/OnDelay'
 * '<S52>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_ActiveFeatureSwitch'
 * '<S53>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_AutoDriveModeManager'
 * '<S54>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_BrakeCtrlSwitch'
 * '<S55>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_EpbCtrlSwitch'
 * '<S56>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_GearCtrlSwitch'
 * '<S57>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_PassiveFeatureSwitch'
 * '<S58>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_PowerControlInhibit'
 * '<S59>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_PowerCtrlSwitch'
 * '<S60>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_SteerCtrlSwitch'
 * '<S61>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/Dtrmn_EnablingFlagsOSP'
 * '<S62>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_AutoDriveModeManager/DtrmnDCSN_ACCSResumeReq'
 * '<S63>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_AutoDriveModeManager/DtrmnDCSN_AutodriveActDelay'
 * '<S64>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_AutoDriveModeManager/DtrmnDCSN_ReActivateLogicFAW'
 * '<S65>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_EnablingManager/DtrmnDCSN_AutoDriveModeManager/autodrive_control_mode_manager'
 * '<S66>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_OverSpeedWarning'
 * '<S67>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit'
 * '<S68>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest'
 * '<S69>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CheckDCSN_InputDataValidity'
 * '<S70>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CvrtDCSN_DataSelector'
 * '<S71>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/DtrmnDCSN_ChangeLaneReq'
 * '<S72>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/MngDCSN_TrafficDeciderManager'
 * '<S73>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/MngDCSN_TrafficDeciderOutputM'
 * '<S74>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit'
 * '<S75>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_ego_lane_speed_limit'
 * '<S76>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/Compare To Constant1'
 * '<S77>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/Compare To Zero2'
 * '<S78>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_max_curvature'
 * '<S79>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_max_curvature1'
 * '<S80>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_ego_road_edges_L'
 * '<S81>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_ego_road_edges_R'
 * '<S82>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_ego_road_marker_L'
 * '<S83>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_ego_road_marker_R'
 * '<S84>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_edge_para'
 * '<S85>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_marker_para'
 * '<S86>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_edge_para'
 * '<S87>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_marker_para'
 * '<S88>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_simu_left_edge_para'
 * '<S89>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_simu_left_marker_para'
 * '<S90>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_simu_right_edge_para'
 * '<S91>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_simu_right_marker_para'
 * '<S92>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Compare To Zero1'
 * '<S93>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Compare To Zero2'
 * '<S94>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Compare To Zero3'
 * '<S95>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Compare To Zero4'
 * '<S96>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Compare To Zero5'
 * '<S97>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Compare To Zero6'
 * '<S98>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Compare To Zero7'
 * '<S99>'  : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Compare To Zero8'
 * '<S100>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Input_variables_observation'
 * '<S101>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_max_curvature/If Action Subsystem'
 * '<S102>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_max_curvature/If Action Subsystem1'
 * '<S103>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_max_curvature/If Action Subsystem/While Iterator Subsystem'
 * '<S104>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_max_curvature1/If Action Subsystem'
 * '<S105>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_max_curvature1/If Action Subsystem1'
 * '<S106>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_max_curvature1/If Action Subsystem/While Iterator Subsystem'
 * '<S107>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_ego_road_edges_L/SelectIndex'
 * '<S108>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_ego_road_edges_L/ego_road_edges_L_id'
 * '<S109>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_ego_road_edges_R/SelectIndex'
 * '<S110>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_ego_road_edges_R/ego_road_edges_R_id'
 * '<S111>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_ego_road_marker_L/SelectIndex'
 * '<S112>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_ego_road_marker_L/ego_lane_marker_L_id'
 * '<S113>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_ego_road_marker_R/SelectIndex'
 * '<S114>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_ego_road_marker_R/ego_lane_marker_R_id'
 * '<S115>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_edge_para/CheckDCSN_left_edge_c0_isNAN'
 * '<S116>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_edge_para/CheckDCSN_left_edge_c1_isNAN'
 * '<S117>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_edge_para/CheckDCSN_left_edge_c2_isNAN'
 * '<S118>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_edge_para/CheckDCSN_left_edge_c3_isNAN'
 * '<S119>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_edge_para/CheckDCSN_left_edge_distance_to_host_isNAN'
 * '<S120>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_edge_para/CheckDCSN_left_edge_quality_isNAN'
 * '<S121>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_marker_para/CheckDCSN_left_marker_c0_isNAN'
 * '<S122>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_marker_para/CheckDCSN_left_marker_c1_isNAN'
 * '<S123>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_marker_para/CheckDCSN_left_marker_c2_isNAN'
 * '<S124>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_marker_para/CheckDCSN_left_marker_c3_isNAN'
 * '<S125>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_marker_para/CheckDCSN_left_marker_distance_to_host_isNAN'
 * '<S126>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_marker_para/CheckDCSN_left_marker_end_x_isNAN'
 * '<S127>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_marker_para/CheckDCSN_left_marker_end_y_isNAN'
 * '<S128>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_marker_para/CheckDCSN_left_marker_quality_isNAN'
 * '<S129>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_marker_para/CheckDCSN_left_marker_start_x_isNAN'
 * '<S130>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_left_marker_para/CheckDCSN_left_marker_start_y_isNAN'
 * '<S131>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_edge_para/CheckDCSN_right_edge_c0_isNAN'
 * '<S132>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_edge_para/CheckDCSN_right_edge_c1_isNAN'
 * '<S133>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_edge_para/CheckDCSN_right_edge_c2_isNAN'
 * '<S134>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_edge_para/CheckDCSN_right_edge_c3_isNAN'
 * '<S135>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_edge_para/CheckDCSN_right_edge_distance_to_host_isNAN'
 * '<S136>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_edge_para/CheckDCSN_right_edge_quality_isNAN'
 * '<S137>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_marker_para/CheckDCSN_right_marker_c0_isNAN'
 * '<S138>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_marker_para/CheckDCSN_right_marker_c1_isNAN'
 * '<S139>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_marker_para/CheckDCSN_right_marker_c2_isNAN'
 * '<S140>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_marker_para/CheckDCSN_right_marker_c3_isNAN'
 * '<S141>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_marker_para/CheckDCSN_right_marker_distance_to_host_isNAN'
 * '<S142>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_marker_para/CheckDCSN_right_marker_end_x_isNAN'
 * '<S143>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_marker_para/CheckDCSN_right_marker_end_y_isNAN'
 * '<S144>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_marker_para/CheckDCSN_right_marker_quality_isNAN'
 * '<S145>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_marker_para/CheckDCSN_right_marker_start_x_isNAN'
 * '<S146>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/CalcDCSN_select_right_marker_para/CheckDCSN_right_marker_start_y_isNAN'
 * '<S147>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Input_variables_observation/CalcDCSN_current_curvature'
 * '<S148>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Input_variables_observation/CalcDCSN_current_curvature1'
 * '<S149>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Input_variables_observation/CalcDCSN_current_curvature2'
 * '<S150>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_curvature_speed_limit/Input_variables_observation/CalcDCSN_current_curvature3'
 * '<S151>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_ego_lane_speed_limit/CalcDCSN_select_ego_lane'
 * '<S152>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_ego_lane_speed_limit/CalcDCSN_select_lane_speed_limit_max'
 * '<S153>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_ego_lane_speed_limit/CalcDCSN_simu_speed_limit_max'
 * '<S154>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_ego_lane_speed_limit/Compare To Zero'
 * '<S155>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_ego_lane_speed_limit/Compare To Zero1'
 * '<S156>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_ego_lane_speed_limit/Pass'
 * '<S157>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_ego_lane_speed_limit/CalcDCSN_select_ego_lane/SelectIndex'
 * '<S158>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_ego_lane_speed_limit/CalcDCSN_select_ego_lane/ego_vehicle_lane_id'
 * '<S159>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_SpeedLimit/CalcDCSN_ego_lane_speed_limit/CalcDCSN_select_lane_speed_limit_max/CheckDCSN_ego_speed_limit_max_isNAN'
 * '<S160>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_RawStopDistance'
 * '<S161>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_SLEWStopDistance'
 * '<S162>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_StopReasonDistance'
 * '<S163>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_RawStopDistance/CalcDCSN_select_ego_lane_stop_line'
 * '<S164>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_RawStopDistance/Compare To Zero2'
 * '<S165>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_RawStopDistance/Compare To Zero3'
 * '<S166>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_RawStopDistance/select_stop_line_distance'
 * '<S167>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_RawStopDistance/simu_stop_line_distance'
 * '<S168>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_RawStopDistance/CalcDCSN_select_ego_lane_stop_line/SelectIndex'
 * '<S169>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_RawStopDistance/CalcDCSN_select_ego_lane_stop_line/ego_lane_index'
 * '<S170>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_RawStopDistance/select_stop_line_distance/CheckDCSN_stop_line_distance_isNAN'
 * '<S171>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_SLEWStopDistance/StopDis'
 * '<S172>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_StopReasonDistance/CheckDCSN_VariableTimeHold'
 * '<S173>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_StopReasonDistance/CheckDCSN_VariableTimeHold1'
 * '<S174>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_StopReasonDistance/Compare To Zero'
 * '<S175>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_StopReasonDistance/Compare To Zero1'
 * '<S176>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_StopReasonDistance/Compare To Zero2'
 * '<S177>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_StopReasonDistance/Compare To Zero3'
 * '<S178>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CalcDCSN_StopRequest/CalcDCSN_StopReasonDistance/DtrmnDCSN_StopModeManager'
 * '<S179>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CheckDCSN_InputDataValidity/Compare To Constant'
 * '<S180>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CheckDCSN_InputDataValidity/Compare To Constant1'
 * '<S181>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CvrtDCSN_DataSelector/CheckDCSN_num_lane_markers_isNaN'
 * '<S182>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CvrtDCSN_DataSelector/CheckDCSN_num_lanes_isNaN'
 * '<S183>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CvrtDCSN_DataSelector/CheckDCSN_num_road_edges_isNaN'
 * '<S184>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/CvrtDCSN_DataSelector/CheckDCSN_num_stop_lines_isNaN'
 * '<S185>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/DtrmnDCSN_ChangeLaneReq/DtrmnDCSN_UsrChangeLaneReq'
 * '<S186>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/DtrmnDCSN_ChangeLaneReq/DtrmnDCSN_UsrChangeLaneReq/CvrtDCSN_DataConvert'
 * '<S187>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/DtrmnDCSN_ChangeLaneReq/DtrmnDCSN_UsrChangeLaneReq/OnDelay'
 * '<S188>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/DtrmnDCSN_ChangeLaneReq/DtrmnDCSN_UsrChangeLaneReq/OnDelay1'
 * '<S189>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/DtrmnDCSN_ChangeLaneReq/DtrmnDCSN_UsrChangeLaneReq/OnDelay2'
 * '<S190>' : 'DCSN_subsystem_integrated/DtrmnDCSN_Integrated/DtrmnDCSN_TrafficDecider/DtrmnDCSN_ChangeLaneReq/DtrmnDCSN_UsrChangeLaneReq/S-R Flip-Flop'
 */
#endif                                 /* RTW_HEADER_DCSN_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
