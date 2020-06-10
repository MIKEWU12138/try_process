/*
 * File: LCCS_subsystem_integrated.h
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.2176
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 09:42:58 2020
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

#ifndef RTW_HEADER_LCCS_subsystem_integrated_h_
#define RTW_HEADER_LCCS_subsystem_integrated_h_
#include <string.h>
#ifndef LCCS_subsystem_integrated_COMMON_INCLUDES_
# define LCCS_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LCCS_subsystem_integrated_COMMON_INCLUDES_ */

#include "LCCS_subsystem_integrated_types.h"

/* Child system includes */
#include "lccs_control.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct
{
  real32_T lane_center_points[160];    /* '<S5>/MATLAB Function' */
  real32_T Add1;                       /* '<S80>/Add1' */
  int32_T lanemark_index;              /* '<S129>/lanemark_index' */
  int32_T lanemark_index_i2on;         /* '<S127>/lanemark_index' */
  boolean_T VbLCCS_steering_control_ac_byg4;/* '<S2>/UnitDelay1' */
  boolean_T VbLCCS_steering_control_en_pmot;/* '<S2>/UnitDelay1' */
  boolean_T VbLCCS_lateral_movement_en_ka3l;/* '<S2>/UnitDelay1' */
  boolean_T right_turn_signal;         /* '<S11>/right_turn_signal' */
  boolean_T left_turn_signal;          /* '<S11>/left_turn_signal' */
  boolean_T VbLCCS_steering_control_st_jgz4;/* '<S2>/UnitDelay1' */
}
B_LCCS_subsystem_integrated_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
  real_T UnitDelay1_DSTATE;            /* '<S9>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S2>/Unit Delay' */
  real32_T UnitDelay_DSTATE_mjzr;      /* '<S148>/Unit Delay' */
  real32_T UnitDelay_DSTATE_kvve;      /* '<S144>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ik3u;      /* '<S137>/Unit Delay' */
  real32_T UnitDelay_DSTATE_cjmy;      /* '<S142>/Unit Delay' */
  real32_T UnitDelay_DSTATE_pmqa;      /* '<S121>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ft2i;      /* '<S123>/Unit Delay' */
  real32_T UnitDelay_DSTATE_aayl;      /* '<S124>/Unit Delay' */
  real32_T UnitDelay_DSTATE_bcwo;      /* '<S125>/Unit Delay' */
  real32_T UnitDelay_DSTATE_g4ms;      /* '<S126>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ppsl;      /* '<S115>/Unit Delay' */
  real32_T UnitDelay_DSTATE_cuw4;      /* '<S117>/Unit Delay' */
  real32_T UnitDelay_DSTATE_labs;      /* '<S118>/Unit Delay' */
  real32_T UnitDelay_DSTATE_a3c0;      /* '<S119>/Unit Delay' */
  real32_T UnitDelay_DSTATE_mobc;      /* '<S120>/Unit Delay' */
  real32_T UnitDelay5_DSTATE;          /* '<S9>/Unit Delay5' */
  real32_T UnitDelay_DSTATE_c5xb;      /* '<S9>/Unit Delay' */
  real32_T UnitDelay_DSTATE_k1xa;      /* '<S94>/Unit Delay' */
  real32_T UnitDelay4_DSTATE_m2on;     /* '<S8>/Unit Delay4' */
  real32_T UnitDelay5_DSTATE_fogd[101];/* '<S67>/Unit Delay5' */
  real32_T UnitDelay1_DSTATE_g04w;     /* '<S67>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE_o2ei;     /* '<S67>/Unit Delay2' */
  real32_T UnitDelay3_DSTATE_p0ty;     /* '<S67>/Unit Delay3' */
  real32_T UnitDelay4_DSTATE_b3pi;     /* '<S67>/Unit Delay4' */
  real32_T UnitDelay6_DSTATE;          /* '<S67>/Unit Delay6' */
  real32_T UnitDelay7_DSTATE;          /* '<S67>/Unit Delay7' */
  real32_T UnitDelay8_DSTATE;          /* '<S67>/Unit Delay8' */
  real32_T UnitDelay9_DSTATE;          /* '<S67>/Unit Delay9' */
  real32_T UnitDelay10_DSTATE;         /* '<S67>/Unit Delay10' */
  real32_T UnitDelay2_DSTATE_ljaq[16]; /* '<S56>/UnitDelay2' */
  real32_T UnitDelay_DSTATE_pmel;      /* '<S63>/Unit Delay' */
  real32_T UnitDelay_DSTATE_frui;      /* '<S56>/Unit Delay' */
  real32_T UnitDelay_DSTATE_k2bi;      /* '<S64>/Unit Delay' */
  real32_T UnitDelay_DSTATE_eoiv;      /* '<S44>/Unit Delay' */
  real32_T UnitDelay_DSTATE_navt;      /* '<S42>/Unit Delay' */
  real32_T UnitDelay_DSTATE_o5zn;      /* '<S43>/Unit Delay' */
  real32_T UnitDelay_DSTATE_jjbb;      /* '<S45>/Unit Delay' */
  real32_T UnitDelay_DSTATE_hi5n;      /* '<S46>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ctwe;      /* '<S47>/Unit Delay' */
  real32_T UnitDelay_DSTATE_bazq;      /* '<S38>/Unit Delay' */
  real32_T UnitDelay_DSTATE_o3lq;      /* '<S39>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ht0x;      /* '<S40>/Unit Delay' */
  real32_T UnitDelay_DSTATE_bxva;      /* '<S41>/Unit Delay' */
  real32_T UnitDelay4_DSTATE_b0jj;     /* '<S6>/Unit Delay4' */
  real32_T UnitDelay_DSTATE_kfnj;      /* '<S6>/Unit Delay' */
  real32_T UnitDelay5_DSTATE_n525;     /* '<S6>/Unit Delay5' */
  real32_T UnitDelay_DSTATE_fqzd;      /* '<S34>/Unit Delay' */
  real32_T UnitDelay_DSTATE_mur1;      /* '<S35>/Unit Delay' */
  real32_T UnitDelay_DSTATE_exgu;      /* '<S36>/Unit Delay' */
  real32_T UnitDelay_DSTATE_fuw4;      /* '<S37>/Unit Delay' */
  real32_T UnitDelay_DSTATE_phrg;      /* '<S51>/Unit Delay' */
  real32_T UnitDelay_DSTATE_of5p;      /* '<S49>/Unit Delay' */
  real32_T UnitDelay_DSTATE_cmzk;      /* '<S50>/Unit Delay' */
  real32_T UnitDelay_DSTATE_l533;      /* '<S52>/Unit Delay' */
  real32_T UnitDelay_DSTATE_h41r;      /* '<S53>/Unit Delay' */
  real32_T UnitDelay_DSTATE_khns;      /* '<S54>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_oid4;     /* '<S6>/Unit Delay1' */
  real32_T TrappedDelay_X[50];         /* '<S14>/Trapped Delay' */
  real32_T UnitDelay_DSTATE_mkfo;      /* '<S14>/Unit Delay' */
  uint32_T temporalCounter_i1;         /* '<S97>/Chart' */
  uint16_T temporalCounter_i1_l3pc;    /* '<S156>/lateral_movement_enable' */
  uint16_T temporalCounter_i1_iexi;    /* '<S11>/right_turn_signal' */
  uint16_T temporalCounter_i1_guw3;    /* '<S11>/left_turn_signal' */
  uint8_T Output_DSTATE;               /* '<S69>/Output' */
  boolean_T UnitDelay2_1_DSTATE;       /* '<S2>/UnitDelay2' */
  boolean_T UnitDelay2_2_DSTATE;       /* '<S2>/UnitDelay2' */
  boolean_T UnitDelay2_3_DSTATE;       /* '<S2>/UnitDelay2' */
  boolean_T UnitDelay2_4_DSTATE;       /* '<S2>/UnitDelay2' */
  boolean_T UnitDelay1_1_DSTATE;       /* '<S2>/UnitDelay1' */
  boolean_T UnitDelay1_2_DSTATE;       /* '<S2>/UnitDelay1' */
  boolean_T UnitDelay1_3_DSTATE;       /* '<S2>/UnitDelay1' */
  boolean_T UnitDelay1_4_DSTATE;       /* '<S2>/UnitDelay1' */
  boolean_T UnitDelay_DSTATE_l0sm;     /* '<S11>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_lgx0;    /* '<S11>/Unit Delay1' */
  boolean_T UnitDelay3_DSTATE_nn4w;    /* '<S11>/Unit Delay3' */
  boolean_T UnitDelay2_DSTATE_ojf4;    /* '<S8>/Unit Delay2' */
  boolean_T UnitDelay1_DSTATE_avtz;    /* '<S8>/Unit Delay1' */
  boolean_T DelayInput1_DSTATE;        /* '<S27>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_kn4x;   /* '<S26>/Delay Input1' */
  uint8_T is_active_c43_LCCS_subsystem_in;/* '<S156>/steering_control_states' */
  uint8_T is_c43_LCCS_subsystem_integrate;/* '<S156>/steering_control_states' */
  uint8_T is_active_c8_LCCS_subsystem_int;/* '<S156>/lateral_movement_enable' */
  uint8_T is_c8_LCCS_subsystem_integrated;/* '<S156>/lateral_movement_enable' */
  uint8_T is_active_c12_LCCS_subsystem_in;/* '<S11>/right_turn_signal' */
  uint8_T is_c12_LCCS_subsystem_integrate;/* '<S11>/right_turn_signal' */
  uint8_T is_active_c10_LCCS_subsystem_in;/* '<S11>/left_turn_signal' */
  uint8_T is_c10_LCCS_subsystem_integrate;/* '<S11>/left_turn_signal' */
  uint8_T is_active_c14_LCCS_subsystem_in;/* '<S97>/Chart' */
  uint8_T is_c14_LCCS_subsystem_integrate;/* '<S97>/Chart' */
  uint8_T is_active_c7_LCCS_subsystem_int;/* '<S8>/lateral_shift_control_states' */
  uint8_T is_c7_LCCS_subsystem_integrated;/* '<S8>/lateral_shift_control_states' */
  boolean_T EnabledSubsystem2_MODE;    /* '<S114>/Enabled Subsystem2' */
  boolean_T EnabledSubsystem2_MODE_bijq;/* '<S113>/Enabled Subsystem2' */
}
DW_LCCS_subsystem_integrated_T;

/* Constant parameters (auto storage) */
typedef struct
{
  /* Computed Parameter: UnitDelay2_InitialCondition
   * Referenced by: '<S56>/UnitDelay2'
   */
  real32_T UnitDelay2_InitialCondition[16];

  /* Computed Parameter: KtLCCS_d_lookahead_distance_max
   * Referenced by: '<S10>/KtLCCS_d_lookahead_distance'
   */
  uint32_T KtLCCS_d_lookahead_distance_max[2];
}
ConstP_LCCS_subsystem_integra_T;

/* Block signals (auto storage) */
extern B_LCCS_subsystem_integrated_T LCCS_subsystem_integrated_B;

/* Block states (auto storage) */
extern DW_LCCS_subsystem_integrated_T LCCS_subsystem_integrated_DW;

/* External data declarations for dependent source files */
extern const LCCS_DataBus LCCS_subsystem_integrated_rtZLCCS_DataBus;/* LCCS_DataBus ground */

/* Constant parameters (auto storage) */
extern const ConstP_LCCS_subsystem_integra_T LCCS_subsystem_integrate_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern LCCS_DataBus VsLCCS_DataBus;    /* '<S12>/Bus Creator' */
extern real_T VfLCCS_timestamp_EGMO;   /* '<S11>/Add1'
                                        * Timestamp of EGMO interface.
                                        */
extern real_T VfLCCS_timestamp_MPFU;   /* '<S10>/Add1'
                                        * Timestamp of MPFU interface.
                                        */
extern real32_T VfLCCS_steering_angle_diff_abs;/* '<S12>/Abs'
                                                * Steering angle delta absolute value.
                                                */
extern real32_T VfLCCS_lateral_v_from_ALCA;/* '<S141>/Switch2'
                                            * ALCA requested lateral speed to shift lane center.
                                            */
extern real32_T VfLCCS_linear_velocity;/* '<S136>/Switch2'
                                        * Linear velocity.
                                        */
extern real32_T VfLCCS_velocity_rel_y; /* '<S11>/Switch10'
                                        * Longitudinal speed Vy.
                                        */
extern real32_T VfLCCS_velocity_rel_x; /* '<S143>/Switch2'
                                        * Lateral speed Vx.
                                        */
extern real32_T VfLCCS_veh_heading_rel;/* '<S11>/Switch9'
                                        * Slip angle of center of mass.
                                        */
extern real32_T VfLCCS_EPS_ActualSteeringAngle;/* '<S150>/Switch2'
                                                * Steering wheel angle from CAN.
                                                */
extern real32_T VfLCCS_yaw_rate;       /* '<S11>/Product'
                                        * Yaw rate from CAN.
                                        */
extern real32_T VfLCCS_lookahead_distance;/* '<S10>/Add2'
                                           * Lookahead distance.
                                           */
extern real32_T VfLCCS_veh_frtwhl_angle_act;/* '<S10>/Product'
                                             * Vehicle front wheel angle actual value.
                                             */
extern real32_T VaLCCS_raw_left_lanemark[6];/* '<S10>/Merge'
                                             * Raw left lanemark.
                                             */
extern real32_T VaLCCS_raw_right_lanemark[6];/* '<S10>/Merge1'
                                              * Raw right lanemark.
                                              */
extern real32_T VfLCCS_smoothed_lane_width;/* '<S92>/Sum1'
                                            * Smoothed lane width.
                                            */
extern real32_T VfLCCS_left_lanemark_confidence;/* '<S9>/Multiport Switch' */
extern real32_T VfLCCS_right_lanemark_confidence;/* '<S9>/Multiport Switch1' */
extern real32_T VaLCCS_virtual_left_lanemark[4];/* '<S9>/Merge'
                                                 * Virtual left lanemark.
                                                 */
extern real32_T VaLCCS_virtual_right_lanemark[4];/* '<S9>/Merge1'
                                                  * Virtual right lanemark.
                                                  */
extern real32_T VfLCCS_raw_lane_width; /* '<S9>/Merge2'
                                        * Raw lane width.
                                        */
extern real32_T VfLCCS_c0_scaling;     /* '<S9>/Merge4'
                                        * c0 scaling factor against lane width.
                                        */
extern real32_T VfLCCS_target_lateral_shift_width;/* '<S84>/Switch4'
                                                   * Target shift width for lane change or inlane nudge.
                                                   */
extern real32_T VfLCCS_lateral_shift_step;/* '<S8>/Product'
                                           * Lane change or nudge shift lateral distance step.
                                           */
extern real32_T VfLCCS_lateral_dist_to_go;/* '<S8>/Switch1'
                                           * Lateral distance from shifted lane center to target lane center.
                                           */
extern real32_T VfLCCS_lateral_shift_width;/* '<S86>/Switch2'
                                            * Lane change or inlane nudge lateral shift width, which is an offset to raw lane center.
                                            */
extern real32_T VaLCCS_shifted_lane_center_line[4];/* '<S8>/Signal Conversion'
                                                    * Shifted lane center line.
                                                    */
extern real32_T VfLCCS_frtwhl_angle_step_limit;/* '<S81>/Switch5'
                                                * Front wheel angle step limit.
                                                */
extern real32_T VfLCCS_frtwhl_angle_limit_manual;/* '<S82>/Abs1'
                                                  * Front wheel angle limit manual.
                                                  */
extern real32_T VfLCCS_veh_frtwhl_angle_des_ramped;/* '<S83>/Switch2'
                                                    * Vehicle front wheel angle desired value ramped.
                                                    */
extern real32_T VfLCCS_veh_strwhl_angle_des;/* '<S80>/Add'
                                             * Desired steering wheel angle.
                                             */
extern real32_T VfLCCS_steer_angle_feedback;/* '<S56>/steer_angle_feedback'
                                             * Steer angle feedback.
                                             */
extern real32_T VfLCCS_steer_angle_feedforward;/* '<S56>/steer_angle_feedforward'
                                                * Steer angle feedforward.
                                                */
extern real32_T VfLCCS_slowpath_steer_P;/* '<S73>/Switch2'
                                         * Slowpath steer P part.
                                         */
extern real32_T VfLCCS_slowpath_steer_I;/* '<S74>/Switch2'
                                         * Slowpath steer I part.
                                         */
extern real32_T VfLCCS_slowpath_steer_PI;/* '<S67>/Add1'
                                          * Slowpath steer PI part.
                                          */
extern real32_T VfLCCS_frtwhl_angle_limit_lat_acc;/* '<S56>/Atan2'
                                                   * Front wheel angle limit lat acc.
                                                   */
extern real32_T VfLCCS_veh_frtwhl_angle_des;/* '<S60>/Switch2'
                                             * Vehicle front wheel angle desired value raw.
                                             */
extern real32_T VfLCCS_heading_error_contribution;/* '<S56>/heading_error_contribution'
                                                   * Heading error contribution.
                                                   */
extern real32_T VfLCCS_heading_error_rate_contribution;/* '<S56>/heading_error_rate_contribution'
                                                        * Heading error rate contribution.
                                                        */
extern real32_T VfLCCS_lateral_error_contribution;/* '<S56>/lateral_error_contribution'
                                                   * Lateral error contribution.
                                                   */
extern real32_T VfLCCS_lateral_error_rate_contribution;/* '<S56>/lateral_error_rate_contribution'
                                                        * Lateral error rate contribution.
                                                        */
extern real32_T VfLCCS_left_lanemark_switch_time;/* '<S6>/Product'
                                                  * Left lanemark switch time.
                                                  */
extern real32_T VaLCCS_final_left_lanemark[4];/* '<S6>/Switch'
                                               * Final left lanemarker.
                                               */
extern real32_T VfLCCS_right_lanemark_switch_time;/* '<S6>/Product1'
                                                   * Right lanemark switch time.
                                                   */
extern real32_T VaLCCS_final_right_lanemark[4];/* '<S6>/Switch3'
                                                * Final right lanemarker.
                                                */
extern real32_T VaLCCS_raw_lane_center_line[4];/* '<S6>/Gain'
                                                * Raw lane center line.
                                                */
extern real32_T VaLCCS_com_point[3];   /* '<S13>/Signal Conversion1'
                                        * Center of mass position.
                                        */
extern real32_T VaLCCS_preview_proj_point[3];/* '<S15>/Signal Conversion'
                                              * Lookahead point projection position.
                                              */
extern real32_T VfLCCS_lookahead_angle;/* '<S14>/Atan2'
                                        * Lookahead angle.
                                        */
extern real32_T VaLCCS_com_proj_point[3];/* '<S13>/Signal Conversion'
                                          * Center of mass projection point position.
                                          */
extern real32_T VfLCCS_lateral_error;  /* '<S21>/Switch2'
                                        * Lateral error.
                                        */
extern real32_T VfLCCS_heading_error_rate;/* '<S14>/Switch2'
                                           * Heading error rate.
                                           */
extern real32_T VfLCCS_lateral_error_rate;/* '<S14>/Product11'
                                           * Lateral error rate.
                                           */
extern real32_T VfLCCS_preview_curvature;/* '<S14>/limit_minus0p2_to_0p2'
                                          * The lane center curvature of preview projection point.
                                          */
extern real32_T VfLCCS_heading_error;  /* '<S14>/NormalizeHeadingAngle'
                                        * Heading error.
                                        */
extern uint8_T VcLCCS_EPS_SteeringControlResponse_LCC;/* '<S149>/Switch2'
                                                       * EPS control mode feedback.
                                                       */
extern uint8_T VfLCCS_num_lane_markers;/* '<S108>/Switch2' */
extern uint8_T VcLCCS_num_iteration;   /* '<S56>/linear_quadratic_regulator' */
extern boolean_T VbLCCS_steering_control_active;/* '<S156>/Logical Operator19'
                                                 * Steering control active.
                                                 */
extern boolean_T VbLCCS_LCC_ReadyToEngage;/* '<S12>/Logical Operator'
                                           * LCC ReadyToEngage.
                                           */
extern boolean_T VbLCCS_LCC_ForceToDisengage;/* '<S12>/Logical Operator1'
                                              * Lane centering control is forced to disengage due to one of following reasons:
                                                1. EGMO and MPFU timestamp don't match.
                                                2. No valid lane marker.
                                              */
extern boolean_T VbLCCS_steering_control_stable;/* '<S156>/Logical Operator18'
                                                 * Steering control stable.
                                                 */
extern boolean_T VbLCCS_steering_control_engaged;/* '<S156>/steering_control_states'
                                                  * Steering control engaged.
                                                  */
extern boolean_T VbLCCS_lateral_movement_enabled;/* '<S156>/lateral_movement_enable'
                                                  * Flag to indicate lateral movement is allowed.
                                                  */
extern boolean_T VbLCCS_lane_change_request;/* '<S11>/Switch' */
extern boolean_T VbLCCS_inlane_nudge_request;/* '<S11>/Switch3'
                                              * Inlane nudge request.
                                              */
extern boolean_T VbLCCS_input_isNaN_DCSN;/* '<S11>/Logical Operator1' */
extern boolean_T VbLCCS_lcc_feature_enable;/* '<S139>/Switch2' */
extern boolean_T VbLCCS_steer_control_enable;/* '<S147>/Switch2'
                                              * LCC is allowed by decision module.
                                              */
extern boolean_T VbLCCS_input_isNaN_ALCA;/* '<S11>/Logical Operator4' */
extern boolean_T VbLCCS_input_isNaN_COMM;/* '<S11>/Logical Operator2' */
extern boolean_T VbLCCS_input_isNaN_EGMO;/* '<S11>/Logical Operator' */
extern boolean_T VbLCCS_input_isNaN_MPFU;/* '<S10>/Logical Operator3' */
extern boolean_T VbLCCS_left_lanemark_valid;/* '<S9>/Logical Operator7'
                                             * Left lanemark valid.
                                             */
extern boolean_T VbLCCS_right_lanemark_valid;/* '<S9>/Switch'
                                              * Right lanemark valid.
                                              */
extern boolean_T VbLCCS_both_lanemark_available;/* '<S9>/Logical Operator8' */
extern boolean_T VbLCCS_shifting_in_progress;/* '<S8>/lateral_shift_control_states'
                                              * Flag to indicate lateral shifting is in progress.
                                              */
extern boolean_T VbLCCS_touched_new_lane;/* '<S6>/Logical Operator'
                                          * Flag to to indicate that ego car has crossed lane marker.
                                          */
extern EnumDCSN_driving_direction VeLCCS_shifting_direction_raw;/* '<S11>/Switch1'
                                                                 * Inlane nudge or lane change shifting_direction. 1 = left. 2 = right.
                                                                 */
extern EnumDCSN_driving_direction VeLCCS_shifting_direction_final;/* '<S8>/lateral_shift_control_states'
                                                                   * Inlane nudge or lane change shifting_direction.
                                                                   */
extern EnumLCCS_ValidLane VeLCCS_valid_lane_marker;/* '<S9>/Merge3'
                                                    * Valid lane marker. 0 = LCCS_NoLane; 1 = LCCS_LeftLane; 2 = LCCS_RightLane; 3 = BothLane.
                                                    */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T KfLCCS_Ang_slowpath_steer_limit;/* Variable: KfLCCS_Ang_slowpath_steer_limit
                                                 * Referenced by: '<S56>/Constant4'
                                                 * Slowpath adjuct limit for front wheel angle. Unit: rad.
                                                 */
extern real32_T KfLCCS_Ang_steering_center_position;/* Variable: KfLCCS_Ang_steering_center_position
                                                     * Referenced by:
                                                     *   '<S10>/Constant1'
                                                     *   '<S80>/Constant1'
                                                     *   '<S80>/Constant3'
                                                     * Steering wheel center position. Unit: degree.
                                                     */
extern real32_T KfLCCS_LanemarkerQualityThrsh;/* Variable: KfLCCS_LanemarkerQualityThrsh
                                               * Referenced by:
                                               *   '<S9>/Constant2'
                                               *   '<S9>/Constant6'
                                               * Lane marker quality thresh, below which that lane marker is not utilized.

                                               */
extern real32_T KfLCCS_WeightMatrixStates_R;/* Variable: KfLCCS_WeightMatrixStates_R
                                             * Referenced by: '<S56>/Constant5'
                                             * Regulator matrix for LQR solver.

                                             */
extern real32_T KfLCCS_a_max_lat_acc;  /* Variable: KfLCCS_a_max_lat_acc
                                        * Referenced by: '<S56>/gps_trace_x1'
                                        * Max acceptable lateral acceleration. Unit: m/s^2.
                                        */
extern real32_T KfLCCS_cf;             /* Variable: KfLCCS_cf
                                        * Referenced by:
                                        *   '<S56>/Constant6'
                                        *   '<S59>/Constant3'
                                        * Corning stiffness for front wheel.

                                        */
extern real32_T KfLCCS_cr;             /* Variable: KfLCCS_cr
                                        * Referenced by:
                                        *   '<S56>/Constant11'
                                        *   '<S59>/Constant15'
                                        *   '<S59>/Constant8'
                                        * Corning stiffness for rear wheel.

                                        */
extern real32_T KfLCCS_d_LateralErrorDeadBand;/* Variable: KfLCCS_d_LateralErrorDeadBand
                                               * Referenced by:
                                               *   '<S67>/Constant7'
                                               *   '<S67>/Constant8'
                                               * Lateral error deadband for slowpath I term.
                                               */
extern real32_T KfLCCS_d_NudgeSafetyZone;/* Variable: KfLCCS_d_NudgeSafetyZone
                                          * Referenced by: '<S84>/Constant1'
                                          * Inlane nudge safety margin between vehicle body and lane marker.

                                          */
extern real32_T KfLCCS_d_RearAxleToCameraOrigin;/* Variable: KfLCCS_d_RearAxleToCameraOrigin
                                                 * Referenced by: '<S5>/KfLCCS_d_RearAxleToCameraOrigin'
                                                 * The distance between rear axle and camera coordinates origin.
                                                 */
extern real32_T KfLCCS_d_ValidLaneWidthLimit;/* Variable: KfLCCS_d_ValidLaneWidthLimit
                                              * Referenced by: '<S9>/Constant3'
                                              */
extern real32_T KfLCCS_d_VehicleWidth; /* Variable: KfLCCS_d_VehicleWidth
                                        * Referenced by: '<S84>/Constant5'
                                        * Vehicle width.
                                        */
extern real32_T KfLCCS_d_lf;           /* Variable: KfLCCS_d_lf
                                        * Referenced by:
                                        *   '<S56>/Constant19'
                                        *   '<S59>/Constant12'
                                        *   '<S59>/Constant5'
                                        * Distance between center of mass and front axle.

                                        */
extern real32_T KfLCCS_d_lr;           /* Variable: KfLCCS_d_lr
                                        * Referenced by:
                                        *   '<S13>/rear_to_com_distance'
                                        *   '<S56>/Constant18'
                                        *   '<S59>/Constant'
                                        *   '<S59>/Constant11'
                                        * Distance between center of mass and rear axle.

                                        */
extern real32_T KfLCCS_d_min_turn_radius;/* Variable: KfLCCS_d_min_turn_radius
                                          * Referenced by: '<S56>/gps_trace_x3'
                                          * Minimum turn radius at lowest speed.

                                          */
extern real32_T KfLCCS_d_wheel_base;   /* Variable: KfLCCS_d_wheel_base
                                        * Referenced by:
                                        *   '<S10>/wheel_base'
                                        *   '<S59>/Constant10'
                                        *   '<S59>/Constant16'
                                        *   '<S59>/Constant4'
                                        *   '<S59>/Constant9'
                                        * Wheel base.
                                        */
extern real32_T KfLCCS_eps;            /* Variable: KfLCCS_eps
                                        * Referenced by: '<S56>/Constant3'
                                        * Tolerance for LQR solver.

                                        */
extern real32_T KfLCCS_heading_error_rate_limit;/* Variable: KfLCCS_heading_error_rate_limit
                                                 * Referenced by: '<S17>/Constant'
                                                 * High limit for calculated heading error rate.

                                                 */
extern real32_T KfLCCS_iz;             /* Variable: KfLCCS_iz
                                        * Referenced by: '<S56>/Constant20'
                                        * Vehicle yaw inertia around -Z- axis.

                                        */
extern real32_T KfLCCS_k_LaneWidthFilter;/* Variable: KfLCCS_k_LaneWidthFilter
                                          * Referenced by: '<S9>/Constant13'
                                          * Filter to smooth lane width.
                                          */
extern real32_T KfLCCS_mass;           /* Variable: KfLCCS_mass
                                        * Referenced by:
                                        *   '<S56>/Constant16'
                                        *   '<S59>/Constant1'
                                        *   '<S59>/Constant13'
                                        *   '<S59>/Constant6'
                                        * Vehicle mass.

                                        */
extern real32_T KfLCCS_r_MaxLateralSpeedPortion;/* Variable: KfLCCS_r_MaxLateralSpeedPortion
                                                 * Referenced by: '<S8>/Constant14'
                                                 * The maximum ratio of lateral speed over vehicle speed.
                                                 */
extern real32_T KfLCCS_r_YawRateCorrection;/* Variable: KfLCCS_r_YawRateCorrection
                                            * Referenced by: '<S11>/Constant17'
                                            * Correction factor for Yaw Rate from CAN bus.
                                            */
extern real32_T KfLCCS_r_shift_speed_gain;/* Variable: KfLCCS_r_shift_speed_gain
                                           * Referenced by: '<S8>/Constant1'
                                           * Lateral distance to go multiply by thisgain to calculate lateral shift speed.
                                           */
extern real32_T KfLCCS_r_steering_rate_forward_gain;/* Variable: KfLCCS_r_steering_rate_forward_gain
                                                     * Referenced by:
                                                     *   '<S81>/Constant2'
                                                     *   '<S81>/Constant3'
                                                     * Steering wheel turning speed gain when moving to forward direction.
                                                     */
extern real32_T KfLCCS_r_veh_strwhl_2_frtwhl_ratio;/* Variable: KfLCCS_r_veh_strwhl_2_frtwhl_ratio
                                                    * Referenced by:
                                                    *   '<S10>/Constant2'
                                                    *   '<S80>/Constant2'
                                                    *   '<S80>/Constant4'
                                                    *   '<S82>/Constant2'
                                                    *   '<S82>/Constant3'
                                                    * The gear ratio between steering wheel angle and front wheel angle.
                                                    */
extern real32_T KfLCCS_t_SampleTime;   /* Variable: KfLCCS_t_SampleTime
                                        * Referenced by:
                                        *   '<S6>/Constant10'
                                        *   '<S6>/Constant2'
                                        *   '<S6>/Constant4'
                                        *   '<S6>/Constant5'
                                        *   '<S6>/Constant6'
                                        *   '<S8>/Constant6'
                                        *   '<S9>/Constant10'
                                        *   '<S14>/Constant5'
                                        *   '<S156>/Constant10'
                                        *   '<S67>/Constant1'
                                        *   '<S67>/Constant10'
                                        *   '<S82>/Constant'
                                        * Base control loop time.

                                        */
extern real32_T KfLCCS_t_TimestampAliveThresh;/* Variable: KfLCCS_t_TimestampAliveThresh
                                               * Referenced by:
                                               *   '<S12>/Constant1'
                                               *   '<S12>/Constant10'
                                               * Timestamp alive thresh to check the diff between EGMO and MPFU messages..
                                               */
extern real32_T KfLCCS_t_lateral_movement_delay;/* Variable: KfLCCS_t_lateral_movement_delay
                                                 * Referenced by: '<S156>/KfLCCS_lateral_movement_delay'
                                                 * When vehicle is moving, and steering control is active, lateral movement will be enabled after this time delay.
                                                 */
extern real32_T KfLCCS_v_shift_speed_high_limit;/* Variable: KfLCCS_v_shift_speed_high_limit
                                                 * Referenced by: '<S8>/Constant3'
                                                 * Lateral shift speed high limit.
                                                 */
extern real32_T KfLCCS_v_shift_speed_low_limit;/* Variable: KfLCCS_v_shift_speed_low_limit
                                                * Referenced by: '<S8>/Constant2'
                                                * Lateral shift speed low limit.
                                                */
extern real32_T KtLCCS_AXIS_heading_error[21];/* Variable: KtLCCS_AXIS_heading_error
                                               * Referenced by: '<S56>/KtLCCS_heading_err_correction'
                                               * AXIS for heading error.
                                               */
extern real32_T KtLCCS_AXIS_lanemark_switch_time[21];/* Variable: KtLCCS_AXIS_lanemark_switch_time
                                                      * Referenced by:
                                                      *   '<S6>/KtLCCS_k_LanemarkMergeCoef'
                                                      *   '<S6>/KtLCCS_k_LanemarkMergeCoef1'
                                                      * Lane marker switch time.
                                                      */
extern real32_T KtLCCS_AXIS_route_curvature[5];/* Variable: KtLCCS_AXIS_route_curvature
                                                * Referenced by: '<S10>/KtLCCS_d_lookahead_distance'
                                                * Curvature axis.
                                                */
extern real32_T KtLCCS_AXIS_vehicle_speed[21];/* Variable: KtLCCS_AXIS_vehicle_speed
                                               * Referenced by:
                                               *   '<S10>/KtLCCS_d_lookahead_distance'
                                               *   '<S12>/KtLCCS_Ang_steering_angle_reentry_zone'
                                               *   '<S56>/KtLCCS_heading_err_gain_scheduler'
                                               *   '<S56>/KtLCCS_heading_err_rate_correction'
                                               *   '<S56>/KtLCCS_heading_err_rate_gain_scheduler'
                                               *   '<S56>/KtLCCS_lateral_err_correction'
                                               *   '<S56>/KtLCCS_lateral_err_gain_scheduler'
                                               *   '<S56>/KtLCCS_lateral_err_rate_correction'
                                               *   '<S56>/KtLCCS_lateral_err_rate_gain_scheduler'
                                               *   '<S56>/KtLCCS_slowpath_steer_I_gain'
                                               *   '<S56>/KtLCCS_slowpath_steer_P_gain'
                                               *   '<S56>/KtLCCS_t_lateral_oscillation_period'
                                               *   '<S82>/KtLCCS_Ang_steering_angle_max'
                                               *   '<S82>/KtLCCS_Ang_steering_angle_step'
                                               *   '<S82>/KtLCCS_Ang_steering_angle_step_engaging'
                                               * Vehicle speed axis.
                                               */
extern real32_T KtLCCS_Ang_steering_angle_max[21];/* Variable: KtLCCS_Ang_steering_angle_max
                                                   * Referenced by: '<S82>/KtLCCS_Ang_steering_angle_max'
                                                   * Absolute maximum steering wheel angle. Unit: degree.
                                                   */
extern real32_T KtLCCS_Ang_steering_angle_reentry_zone[21];/* Variable: KtLCCS_Ang_steering_angle_reentry_zone
                                                            * Referenced by: '<S12>/KtLCCS_Ang_steering_angle_reentry_zone'
                                                            * Steering angle delta limit for re-engage control. Unit: degree.
                                                            */
extern real32_T KtLCCS_Ang_steering_angle_step[21];/* Variable: KtLCCS_Ang_steering_angle_step
                                                    * Referenced by: '<S82>/KtLCCS_Ang_steering_angle_step'
                                                    * Desired steering wheel angle moving step per second. Unit: degree/s.
                                                    */
extern real32_T KtLCCS_Ang_steering_angle_step_engaging[21];/* Variable: KtLCCS_Ang_steering_angle_step_engaging
                                                             * Referenced by: '<S82>/KtLCCS_Ang_steering_angle_step_engaging'
                                                             * Desired steering wheel angle moving step per second, when engaging steering control. Unit: degree/s.
                                                             */
extern real32_T KtLCCS_d_lookahead_distance[105];/* Variable: KtLCCS_d_lookahead_distance
                                                  * Referenced by: '<S10>/KtLCCS_d_lookahead_distance'
                                                  * Vehicle lookahead distance.
                                                  */
extern real32_T KtLCCS_heading_err_correction[21];/* Variable: KtLCCS_heading_err_correction
                                                   * Referenced by: '<S56>/KtLCCS_heading_err_correction'
                                                   * Correction for heading error.
                                                   */
extern real32_T KtLCCS_heading_err_gain_scheduler[21];/* Variable: KtLCCS_heading_err_gain_scheduler
                                                       * Referenced by: '<S56>/KtLCCS_heading_err_gain_scheduler'
                                                       * Gain for heading error scheduler.
                                                       */
extern real32_T KtLCCS_heading_err_rate_correction[21];/* Variable: KtLCCS_heading_err_rate_correction
                                                        * Referenced by: '<S56>/KtLCCS_heading_err_rate_correction'
                                                        * Correction for heading error rate.
                                                        */
extern real32_T KtLCCS_heading_err_rate_gain_scheduler[21];/* Variable: KtLCCS_heading_err_rate_gain_scheduler
                                                            * Referenced by: '<S56>/KtLCCS_heading_err_rate_gain_scheduler'
                                                            * Gain for heading error scheduler.
                                                            */
extern real32_T KtLCCS_k_LanemarkMergeCoef[21];/* Variable: KtLCCS_k_LanemarkMergeCoef
                                                * Referenced by:
                                                *   '<S6>/KtLCCS_k_LanemarkMergeCoef'
                                                *   '<S6>/KtLCCS_k_LanemarkMergeCoef1'
                                                * Lane marker merging filter coef.
                                                */
extern real32_T KtLCCS_lateral_err_correction[21];/* Variable: KtLCCS_lateral_err_correction
                                                   * Referenced by: '<S56>/KtLCCS_lateral_err_correction'
                                                   * Correction for lateral error.
                                                   */
extern real32_T KtLCCS_lateral_err_gain_scheduler[21];/* Variable: KtLCCS_lateral_err_gain_scheduler
                                                       * Referenced by: '<S56>/KtLCCS_lateral_err_gain_scheduler'
                                                       * Gain for lateral error scheduler.
                                                       */
extern real32_T KtLCCS_lateral_err_rate_correction[21];/* Variable: KtLCCS_lateral_err_rate_correction
                                                        * Referenced by: '<S56>/KtLCCS_lateral_err_rate_correction'
                                                        * Correction for lateral error rate.
                                                        */
extern real32_T KtLCCS_lateral_err_rate_gain_scheduler[21];/* Variable: KtLCCS_lateral_err_rate_gain_scheduler
                                                            * Referenced by: '<S56>/KtLCCS_lateral_err_rate_gain_scheduler'
                                                            * Gain for lateral error rate scheduler.
                                                            */
extern real32_T KtLCCS_slowpath_steer_I_gain[21];/* Variable: KtLCCS_slowpath_steer_I_gain
                                                  * Referenced by: '<S56>/KtLCCS_slowpath_steer_I_gain'
                                                  * Gain for slowpath steer I part.
                                                  */
extern real32_T KtLCCS_slowpath_steer_P_gain[21];/* Variable: KtLCCS_slowpath_steer_P_gain
                                                  * Referenced by: '<S56>/KtLCCS_slowpath_steer_P_gain'
                                                  * Gain for slowpath steer P part.
                                                  */
extern real32_T KtLCCS_t_lateral_oscillation_period[21];/* Variable: KtLCCS_t_lateral_oscillation_period
                                                         * Referenced by: '<S56>/KtLCCS_t_lateral_oscillation_period'
                                                         * THe control period of lateral oscillation.
                                                         */
extern int32_T KcLCCS_HeadingErrorRateSmooth;/* Variable: KcLCCS_HeadingErrorRateSmooth
                                              * Referenced by:
                                              *   '<S14>/Constant1'
                                              *   '<S14>/Constant4'
                                              * This number of heading error samples are used to calculate heading error rate.

                                              */
extern boolean_T KbLCCS_UsePurePursuit;/* Variable: KbLCCS_UsePurePursuit
                                        * Referenced by:
                                        *   '<S14>/gps_trace_x1'
                                        *   '<S14>/gps_trace_x5'
                                        *   '<S56>/gps_trace_x2'
                                        * True: Use lookahead point to calculate target driving direction.
                                        */
extern boolean_T KbLCCS_WheelEncoderReady;/* Variable: KbLCCS_WheelEncoderReady
                                           * Referenced by:
                                           *   '<S11>/Constant16'
                                           *   '<S11>/Constant3'
                                           * Indicator for wheel encoder system ready.
                                           */
extern boolean_T KbLCCS_inlane_nudge_request_SLEW;/* Variable: KbLCCS_inlane_nudge_request_SLEW
                                                   * Referenced by: '<S11>/Constant13'
                                                   * Calibration switch to SLEW inlane nudge request.
                                                   */
extern boolean_T KbLCCS_inlane_nudge_request_value;/* Variable: KbLCCS_inlane_nudge_request_value
                                                    * Referenced by: '<S11>/Constant14'
                                                    * Inlane nudge request value in SLEW mode.
                                                    */
extern boolean_T KbLCCS_lane_change_request_SLEW;/* Variable: KbLCCS_lane_change_request_SLEW
                                                  * Referenced by:
                                                  *   '<S11>/Constant4'
                                                  *   '<S11>/Constant6'
                                                  * Calibration switch to SLEW lane change request.
                                                  */
extern boolean_T KbLCCS_lane_change_request_value;/* Variable: KbLCCS_lane_change_request_value
                                                   * Referenced by: '<S11>/Constant5'
                                                   * Lane change request value in SLEW mode.
                                                   */
extern boolean_T KbLCCS_lane_change_source_ALCA;/* Variable: KbLCCS_lane_change_source_ALCA
                                                 * Referenced by:
                                                 *   '<S8>/Constant15'
                                                 *   '<S11>/Constant1'
                                                 *   '<S11>/Constant2'
                                                 * Lane change request source is ALCA.
                                                 */
extern EnumDCSN_driving_direction KeLCCS_shifting_direction_value;/* Variable: KeLCCS_shifting_direction_value
                                                                   * Referenced by: '<S11>/Constant12'
                                                                   * Shifting direction value in SLEW mode.
                                                                   */

/* Model entry point functions */
extern void LCCS_subsystem_integrated_initialize(void);
extern void LCCS_subsystem_integrated_step(void);

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
 * '<Root>' : 'LCCS_subsystem_integrated'
 * '<S1>'   : 'LCCS_subsystem_integrated/LCCS'
 * '<S2>'   : 'LCCS_subsystem_integrated/LCCS/LCCS'
 * '<S3>'   : 'LCCS_subsystem_integrated/LCCS/LCCS_Dummy'
 * '<S4>'   : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_compute_lateral_errors'
 * '<S5>'   : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_discretize'
 * '<S6>'   : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line'
 * '<S7>'   : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main'
 * '<S8>'   : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_shift_width'
 * '<S9>'   : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker'
 * '<S10>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing'
 * '<S11>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality'
 * '<S12>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_steering_control_output'
 * '<S13>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_compute_lateral_errors/center_of_mass_projection'
 * '<S14>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_compute_lateral_errors/compute_lateral_errors'
 * '<S15>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_compute_lateral_errors/preview_point_projection'
 * '<S16>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_compute_lateral_errors/center_of_mass_projection/QueryNearestPointByVehPosition'
 * '<S17>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_compute_lateral_errors/compute_lateral_errors/Compare To Constant'
 * '<S18>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_compute_lateral_errors/compute_lateral_errors/MATLAB Function'
 * '<S19>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_compute_lateral_errors/compute_lateral_errors/MATLAB Function1'
 * '<S20>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_compute_lateral_errors/compute_lateral_errors/NormalizeHeadingAngle'
 * '<S21>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_compute_lateral_errors/compute_lateral_errors/Saturation Dynamic'
 * '<S22>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_compute_lateral_errors/preview_point_projection/QueryNearestPointByVehPosition'
 * '<S23>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_discretize/MATLAB Function'
 * '<S24>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/1st order filter'
 * '<S25>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/1st order filter1'
 * '<S26>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/Detect Change1'
 * '<S27>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/Detect Change2'
 * '<S28>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/Increment Real World1'
 * '<S29>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/Increment Real World2'
 * '<S30>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/check_signal_isNan'
 * '<S31>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/check_signal_isNan1'
 * '<S32>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation'
 * '<S33>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation1'
 * '<S34>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/check_signal_isNan/check_signal_isNan2'
 * '<S35>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/check_signal_isNan/check_signal_isNan4'
 * '<S36>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/check_signal_isNan/check_signal_isNan5'
 * '<S37>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/check_signal_isNan/check_signal_isNan6'
 * '<S38>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/check_signal_isNan1/check_signal_isNan2'
 * '<S39>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/check_signal_isNan1/check_signal_isNan4'
 * '<S40>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/check_signal_isNan1/check_signal_isNan5'
 * '<S41>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/check_signal_isNan1/check_signal_isNan6'
 * '<S42>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation/check_signal_isNan1'
 * '<S43>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation/check_signal_isNan2'
 * '<S44>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation/check_signal_isNan3'
 * '<S45>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation/check_signal_isNan4'
 * '<S46>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation/check_signal_isNan5'
 * '<S47>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation/check_signal_isNan6'
 * '<S48>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation/kinematic_compensation'
 * '<S49>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation1/check_signal_isNan1'
 * '<S50>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation1/check_signal_isNan2'
 * '<S51>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation1/check_signal_isNan3'
 * '<S52>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation1/check_signal_isNan4'
 * '<S53>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation1/check_signal_isNan5'
 * '<S54>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation1/check_signal_isNan6'
 * '<S55>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lane_center_line/kinematic_compensation1/kinematic_compensation'
 * '<S56>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control'
 * '<S57>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/steering_wheel_angle'
 * '<S58>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/1st order filter'
 * '<S59>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/Compute_Feed_Forward'
 * '<S60>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/Saturation Dynamic1'
 * '<S61>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/UpdateMatrixA'
 * '<S62>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/UpdateMatrixQ'
 * '<S63>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/check_signal_isNan1'
 * '<S64>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/check_signal_isNan3'
 * '<S65>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/linear_quadratic_regulator'
 * '<S66>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/matrixAB'
 * '<S67>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/slowpath_steer_PI'
 * '<S68>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/slowpath_steer_PI/Compare To Constant'
 * '<S69>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/slowpath_steer_PI/Counter Limited'
 * '<S70>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/slowpath_steer_PI/Dead Zone Dynamic'
 * '<S71>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/slowpath_steer_PI/MATLAB Function'
 * '<S72>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/slowpath_steer_PI/MATLAB Function1'
 * '<S73>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/slowpath_steer_PI/Saturation Dynamic'
 * '<S74>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/slowpath_steer_PI/Saturation Dynamic1'
 * '<S75>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/slowpath_steer_PI/Saturation Dynamic2'
 * '<S76>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/slowpath_steer_PI/Saturation Dynamic3'
 * '<S77>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/slowpath_steer_PI/Counter Limited/Increment Real World'
 * '<S78>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/lateral_control/slowpath_steer_PI/Counter Limited/Wrap To Zero'
 * '<S79>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/steering_wheel_angle/angular_vel_limit'
 * '<S80>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/steering_wheel_angle/angular_vel_limit/frontwheel_2_steeringwheel'
 * '<S81>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/steering_wheel_angle/angular_vel_limit/rate_limit'
 * '<S82>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/steering_wheel_angle/angular_vel_limit/steering_angle_limit'
 * '<S83>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_control_main/steering_wheel_angle/angular_vel_limit/rate_limit/Saturation Dynamic'
 * '<S84>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_shift_width/CalcLCCS_target_shift_width'
 * '<S85>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_shift_width/Saturation Dynamic'
 * '<S86>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_shift_width/Saturation Dynamic1'
 * '<S87>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_shift_width/lateral_shift_control_states'
 * '<S88>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_shift_width/CalcLCCS_target_shift_width/Enumerated Constant1'
 * '<S89>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_shift_width/CalcLCCS_target_shift_width/Enumerated Constant2'
 * '<S90>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_shift_width/CalcLCCS_target_shift_width/Enumerated Constant5'
 * '<S91>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_lateral_shift_width/CalcLCCS_target_shift_width/Enumerated Constant6'
 * '<S92>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker/1st order filter'
 * '<S93>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker/If Action Subsystem'
 * '<S94>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker/If Action Subsystem1'
 * '<S95>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker/If Action Subsystem2'
 * '<S96>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker/If Action Subsystem3'
 * '<S97>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker/RisingEdgeDelay'
 * '<S98>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker/If Action Subsystem/Enumerated Constant'
 * '<S99>'  : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker/If Action Subsystem1/Compare To Constant'
 * '<S100>' : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker/If Action Subsystem1/Enumerated Constant'
 * '<S101>' : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker/If Action Subsystem2/Enumerated Constant'
 * '<S102>' : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker/If Action Subsystem3/Enumerated Constant'
 * '<S103>' : 'LCCS_subsystem_integrated/LCCS/LCCS/CalcLCCS_virtual_lane_marker/RisingEdgeDelay/Chart'
 * '<S104>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/Compare To Zero1'
 * '<S105>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/Compare To Zero2'
 * '<S106>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/Compare To Zero3'
 * '<S107>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/Compare To Zero4'
 * '<S108>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/check_signal_isNan10'
 * '<S109>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/default_left_lanemark'
 * '<S110>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/default_right_lanemark'
 * '<S111>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_left_lanemark'
 * '<S112>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_right_lanemark'
 * '<S113>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/search_left_lanemark'
 * '<S114>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/search_right_lanemark'
 * '<S115>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_left_lanemark/check_signal_isNan1'
 * '<S116>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_left_lanemark/check_signal_isNan10'
 * '<S117>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_left_lanemark/check_signal_isNan2'
 * '<S118>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_left_lanemark/check_signal_isNan3'
 * '<S119>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_left_lanemark/check_signal_isNan4'
 * '<S120>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_left_lanemark/check_signal_isNan5'
 * '<S121>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_right_lanemark/check_signal_isNan1'
 * '<S122>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_right_lanemark/check_signal_isNan10'
 * '<S123>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_right_lanemark/check_signal_isNan2'
 * '<S124>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_right_lanemark/check_signal_isNan3'
 * '<S125>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_right_lanemark/check_signal_isNan4'
 * '<S126>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/received_right_lanemark/check_signal_isNan5'
 * '<S127>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/search_left_lanemark/Enabled Subsystem2'
 * '<S128>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/search_left_lanemark/LEFT_FIRST_LANEMARK__1'
 * '<S129>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/search_right_lanemark/Enabled Subsystem2'
 * '<S130>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_processing/search_right_lanemark/RIGHT_FIRST_LANEMARK__2'
 * '<S131>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/Compare To Zero'
 * '<S132>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/Enumerated Constant'
 * '<S133>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/Enumerated Constant1'
 * '<S134>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/Enumerated Constant2'
 * '<S135>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/Enumerated Constant3'
 * '<S136>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan'
 * '<S137>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan1'
 * '<S138>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan11'
 * '<S139>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan12'
 * '<S140>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan13'
 * '<S141>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan14'
 * '<S142>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan16'
 * '<S143>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan2'
 * '<S144>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan3'
 * '<S145>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan4'
 * '<S146>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan5'
 * '<S147>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan6'
 * '<S148>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan7'
 * '<S149>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan8'
 * '<S150>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan9'
 * '<S151>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/left_turn_signal'
 * '<S152>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/right_turn_signal'
 * '<S153>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan11/Enumerated Constant'
 * '<S154>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_sensor_signal_rationality/check_signal_isNan5/Enumerated Constant'
 * '<S155>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_steering_control_output/Enumerated Constant'
 * '<S156>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_steering_control_output/steering_control_machine'
 * '<S157>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_steering_control_output/steering_control_machine/Compare To Constant'
 * '<S158>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_steering_control_output/steering_control_machine/Compare To Constant1'
 * '<S159>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_steering_control_output/steering_control_machine/lateral_movement_enable'
 * '<S160>' : 'LCCS_subsystem_integrated/LCCS/LCCS/DtrmnLCCS_steering_control_output/steering_control_machine/steering_control_states'
 * '<S161>' : 'LCCS_subsystem_integrated/LCCS/LCCS_Dummy/Enumerated Constant'
 */
#endif                                 /* RTW_HEADER_LCCS_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
