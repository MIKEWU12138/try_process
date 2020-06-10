/*
 * File: LCCS_subsystem_integrated.c
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

#include "LCCS_subsystem_integrated.h"
#include "LCCS_subsystem_integrated_private.h"

const LCCS_DataBus LCCS_subsystem_integrated_rtZLCCS_DataBus =
{
  false,                               /* LCC_ReadyToEngage */
  false,                               /* LCC_ForceToDisengage */
  false,                               /* steering_control_engaged */
  LCCS_NoLane,                         /* valid_lane_marker */
  0.0F,                                /* veh_strwhl_angle_des */
  0.0F                                 /* lateral_dist_to_go */
} ;                                    /* LCCS_DataBus ground */

/* Exported block signals */
LCCS_DataBus VsLCCS_DataBus;           /* '<S12>/Bus Creator' */
real_T VfLCCS_timestamp_EGMO;          /* '<S11>/Add1'
                                        * Timestamp of EGMO interface.
                                        */
real_T VfLCCS_timestamp_MPFU;          /* '<S10>/Add1'
                                        * Timestamp of MPFU interface.
                                        */
real32_T VfLCCS_steering_angle_diff_abs;/* '<S12>/Abs'
                                         * Steering angle delta absolute value.
                                         */
real32_T VfLCCS_lateral_v_from_ALCA;   /* '<S141>/Switch2'
                                        * ALCA requested lateral speed to shift lane center.
                                        */
real32_T VfLCCS_linear_velocity;       /* '<S136>/Switch2'
                                        * Linear velocity.
                                        */
real32_T VfLCCS_velocity_rel_y;        /* '<S11>/Switch10'
                                        * Longitudinal speed Vy.
                                        */
real32_T VfLCCS_velocity_rel_x;        /* '<S143>/Switch2'
                                        * Lateral speed Vx.
                                        */
real32_T VfLCCS_veh_heading_rel;       /* '<S11>/Switch9'
                                        * Slip angle of center of mass.
                                        */
real32_T VfLCCS_EPS_ActualSteeringAngle;/* '<S150>/Switch2'
                                         * Steering wheel angle from CAN.
                                         */
real32_T VfLCCS_yaw_rate;              /* '<S11>/Product'
                                        * Yaw rate from CAN.
                                        */
real32_T VfLCCS_lookahead_distance;    /* '<S10>/Add2'
                                        * Lookahead distance.
                                        */
real32_T VfLCCS_veh_frtwhl_angle_act;  /* '<S10>/Product'
                                        * Vehicle front wheel angle actual value.
                                        */
real32_T VaLCCS_raw_left_lanemark[6];  /* '<S10>/Merge'
                                        * Raw left lanemark.
                                        */
real32_T VaLCCS_raw_right_lanemark[6]; /* '<S10>/Merge1'
                                        * Raw right lanemark.
                                        */
real32_T VfLCCS_smoothed_lane_width;   /* '<S92>/Sum1'
                                        * Smoothed lane width.
                                        */
real32_T VfLCCS_left_lanemark_confidence;/* '<S9>/Multiport Switch' */
real32_T VfLCCS_right_lanemark_confidence;/* '<S9>/Multiport Switch1' */
real32_T VaLCCS_virtual_left_lanemark[4];/* '<S9>/Merge'
                                          * Virtual left lanemark.
                                          */
real32_T VaLCCS_virtual_right_lanemark[4];/* '<S9>/Merge1'
                                           * Virtual right lanemark.
                                           */
real32_T VfLCCS_raw_lane_width;        /* '<S9>/Merge2'
                                        * Raw lane width.
                                        */
real32_T VfLCCS_c0_scaling;            /* '<S9>/Merge4'
                                        * c0 scaling factor against lane width.
                                        */
real32_T VfLCCS_target_lateral_shift_width;/* '<S84>/Switch4'
                                            * Target shift width for lane change or inlane nudge.
                                            */
real32_T VfLCCS_lateral_shift_step;    /* '<S8>/Product'
                                        * Lane change or nudge shift lateral distance step.
                                        */
real32_T VfLCCS_lateral_dist_to_go;    /* '<S8>/Switch1'
                                        * Lateral distance from shifted lane center to target lane center.
                                        */
real32_T VfLCCS_lateral_shift_width;   /* '<S86>/Switch2'
                                        * Lane change or inlane nudge lateral shift width, which is an offset to raw lane center.
                                        */
real32_T VaLCCS_shifted_lane_center_line[4];/* '<S8>/Signal Conversion'
                                             * Shifted lane center line.
                                             */
real32_T VfLCCS_frtwhl_angle_step_limit;/* '<S81>/Switch5'
                                         * Front wheel angle step limit.
                                         */
real32_T VfLCCS_frtwhl_angle_limit_manual;/* '<S82>/Abs1'
                                           * Front wheel angle limit manual.
                                           */
real32_T VfLCCS_veh_frtwhl_angle_des_ramped;/* '<S83>/Switch2'
                                             * Vehicle front wheel angle desired value ramped.
                                             */
real32_T VfLCCS_veh_strwhl_angle_des;  /* '<S80>/Add'
                                        * Desired steering wheel angle.
                                        */
real32_T VfLCCS_steer_angle_feedback;  /* '<S56>/steer_angle_feedback'
                                        * Steer angle feedback.
                                        */
real32_T VfLCCS_steer_angle_feedforward;/* '<S56>/steer_angle_feedforward'
                                         * Steer angle feedforward.
                                         */
real32_T VfLCCS_slowpath_steer_P;      /* '<S73>/Switch2'
                                        * Slowpath steer P part.
                                        */
real32_T VfLCCS_slowpath_steer_I;      /* '<S74>/Switch2'
                                        * Slowpath steer I part.
                                        */
real32_T VfLCCS_slowpath_steer_PI;     /* '<S67>/Add1'
                                        * Slowpath steer PI part.
                                        */
real32_T VfLCCS_frtwhl_angle_limit_lat_acc;/* '<S56>/Atan2'
                                            * Front wheel angle limit lat acc.
                                            */
real32_T VfLCCS_veh_frtwhl_angle_des;  /* '<S60>/Switch2'
                                        * Vehicle front wheel angle desired value raw.
                                        */
real32_T VfLCCS_heading_error_contribution;/* '<S56>/heading_error_contribution'
                                            * Heading error contribution.
                                            */
real32_T VfLCCS_heading_error_rate_contribution;/* '<S56>/heading_error_rate_contribution'
                                                 * Heading error rate contribution.
                                                 */
real32_T VfLCCS_lateral_error_contribution;/* '<S56>/lateral_error_contribution'
                                            * Lateral error contribution.
                                            */
real32_T VfLCCS_lateral_error_rate_contribution;/* '<S56>/lateral_error_rate_contribution'
                                                 * Lateral error rate contribution.
                                                 */
real32_T VfLCCS_left_lanemark_switch_time;/* '<S6>/Product'
                                           * Left lanemark switch time.
                                           */
real32_T VaLCCS_final_left_lanemark[4];/* '<S6>/Switch'
                                        * Final left lanemarker.
                                        */
real32_T VfLCCS_right_lanemark_switch_time;/* '<S6>/Product1'
                                            * Right lanemark switch time.
                                            */
real32_T VaLCCS_final_right_lanemark[4];/* '<S6>/Switch3'
                                         * Final right lanemarker.
                                         */
real32_T VaLCCS_raw_lane_center_line[4];/* '<S6>/Gain'
                                         * Raw lane center line.
                                         */
real32_T VaLCCS_com_point[3];          /* '<S13>/Signal Conversion1'
                                        * Center of mass position.
                                        */
real32_T VaLCCS_preview_proj_point[3]; /* '<S15>/Signal Conversion'
                                        * Lookahead point projection position.
                                        */
real32_T VfLCCS_lookahead_angle;       /* '<S14>/Atan2'
                                        * Lookahead angle.
                                        */
real32_T VaLCCS_com_proj_point[3];     /* '<S13>/Signal Conversion'
                                        * Center of mass projection point position.
                                        */
real32_T VfLCCS_lateral_error;         /* '<S21>/Switch2'
                                        * Lateral error.
                                        */
real32_T VfLCCS_heading_error_rate;    /* '<S14>/Switch2'
                                        * Heading error rate.
                                        */
real32_T VfLCCS_lateral_error_rate;    /* '<S14>/Product11'
                                        * Lateral error rate.
                                        */
real32_T VfLCCS_preview_curvature;     /* '<S14>/limit_minus0p2_to_0p2'
                                        * The lane center curvature of preview projection point.
                                        */
real32_T VfLCCS_heading_error;         /* '<S14>/NormalizeHeadingAngle'
                                        * Heading error.
                                        */
uint8_T VcLCCS_EPS_SteeringControlResponse_LCC;/* '<S149>/Switch2'
                                                * EPS control mode feedback.
                                                */
uint8_T VfLCCS_num_lane_markers;       /* '<S108>/Switch2' */
uint8_T VcLCCS_num_iteration;          /* '<S56>/linear_quadratic_regulator' */
boolean_T VbLCCS_steering_control_active;/* '<S156>/Logical Operator19'
                                          * Steering control active.
                                          */
boolean_T VbLCCS_LCC_ReadyToEngage;    /* '<S12>/Logical Operator'
                                        * LCC ReadyToEngage.
                                        */
boolean_T VbLCCS_LCC_ForceToDisengage; /* '<S12>/Logical Operator1'
                                        * Lane centering control is forced to disengage due to one of following reasons:
                                          1. EGMO and MPFU timestamp don't match.
                                          2. No valid lane marker.
                                        */
boolean_T VbLCCS_steering_control_stable;/* '<S156>/Logical Operator18'
                                          * Steering control stable.
                                          */
boolean_T VbLCCS_steering_control_engaged;/* '<S156>/steering_control_states'
                                           * Steering control engaged.
                                           */
boolean_T VbLCCS_lateral_movement_enabled;/* '<S156>/lateral_movement_enable'
                                           * Flag to indicate lateral movement is allowed.
                                           */
boolean_T VbLCCS_lane_change_request;  /* '<S11>/Switch' */
boolean_T VbLCCS_inlane_nudge_request; /* '<S11>/Switch3'
                                        * Inlane nudge request.
                                        */
boolean_T VbLCCS_input_isNaN_DCSN;     /* '<S11>/Logical Operator1' */
boolean_T VbLCCS_lcc_feature_enable;   /* '<S139>/Switch2' */
boolean_T VbLCCS_steer_control_enable; /* '<S147>/Switch2'
                                        * LCC is allowed by decision module.
                                        */
boolean_T VbLCCS_input_isNaN_ALCA;     /* '<S11>/Logical Operator4' */
boolean_T VbLCCS_input_isNaN_COMM;     /* '<S11>/Logical Operator2' */
boolean_T VbLCCS_input_isNaN_EGMO;     /* '<S11>/Logical Operator' */
boolean_T VbLCCS_input_isNaN_MPFU;     /* '<S10>/Logical Operator3' */
boolean_T VbLCCS_left_lanemark_valid;  /* '<S9>/Logical Operator7'
                                        * Left lanemark valid.
                                        */
boolean_T VbLCCS_right_lanemark_valid; /* '<S9>/Switch'
                                        * Right lanemark valid.
                                        */
boolean_T VbLCCS_both_lanemark_available;/* '<S9>/Logical Operator8' */
boolean_T VbLCCS_shifting_in_progress; /* '<S8>/lateral_shift_control_states'
                                        * Flag to indicate lateral shifting is in progress.
                                        */
boolean_T VbLCCS_touched_new_lane;     /* '<S6>/Logical Operator'
                                        * Flag to to indicate that ego car has crossed lane marker.
                                        */
EnumDCSN_driving_direction VeLCCS_shifting_direction_raw;/* '<S11>/Switch1'
                                                          * Inlane nudge or lane change shifting_direction. 1 = left. 2 = right.
                                                          */
EnumDCSN_driving_direction VeLCCS_shifting_direction_final;/* '<S8>/lateral_shift_control_states'
                                                            * Inlane nudge or lane change shifting_direction.
                                                            */
EnumLCCS_ValidLane VeLCCS_valid_lane_marker;/* '<S9>/Merge3'
                                             * Valid lane marker. 0 = LCCS_NoLane; 1 = LCCS_LeftLane; 2 = LCCS_RightLane; 3 = BothLane.
                                             */

#pragma section ".cal"
/* Exported block parameters */
real32_T KfLCCS_Ang_slowpath_steer_limit = 0.006F;/* Variable: KfLCCS_Ang_slowpath_steer_limit
                                                   * Referenced by: '<S56>/Constant4'
                                                   * Slowpath adjuct limit for front wheel angle. Unit: rad.
                                                   */
real32_T KfLCCS_Ang_steering_center_position = 0.0F;/* Variable: KfLCCS_Ang_steering_center_position
                                                     * Referenced by:
                                                     *   '<S10>/Constant1'
                                                     *   '<S80>/Constant1'
                                                     *   '<S80>/Constant3'
                                                     * Steering wheel center position. Unit: degree.
                                                     */
real32_T KfLCCS_LanemarkerQualityThrsh = 60.0F;/* Variable: KfLCCS_LanemarkerQualityThrsh
                                                * Referenced by:
                                                *   '<S9>/Constant2'
                                                *   '<S9>/Constant6'
                                                * Lane marker quality thresh, below which that lane marker is not utilized.

                                                */
real32_T KfLCCS_WeightMatrixStates_R = 1.0F;/* Variable: KfLCCS_WeightMatrixStates_R
                                             * Referenced by: '<S56>/Constant5'
                                             * Regulator matrix for LQR solver.

                                             */
real32_T KfLCCS_a_max_lat_acc = 2.0F;  /* Variable: KfLCCS_a_max_lat_acc
                                        * Referenced by: '<S56>/gps_trace_x1'
                                        * Max acceptable lateral acceleration. Unit: m/s^2.
                                        */
real32_T KfLCCS_cf = 214135.766F;      /* Variable: KfLCCS_cf
                                        * Referenced by:
                                        *   '<S56>/Constant6'
                                        *   '<S59>/Constant3'
                                        * Corning stiffness for front wheel.

                                        */
real32_T KfLCCS_cr = 214135.766F;      /* Variable: KfLCCS_cr
                                        * Referenced by:
                                        *   '<S56>/Constant11'
                                        *   '<S59>/Constant15'
                                        *   '<S59>/Constant8'
                                        * Corning stiffness for rear wheel.

                                        */
real32_T KfLCCS_d_LateralErrorDeadBand = 0.05F;/* Variable: KfLCCS_d_LateralErrorDeadBand
                                                * Referenced by:
                                                *   '<S67>/Constant7'
                                                *   '<S67>/Constant8'
                                                * Lateral error deadband for slowpath I term.
                                                */
real32_T KfLCCS_d_NudgeSafetyZone = 0.2F;/* Variable: KfLCCS_d_NudgeSafetyZone
                                          * Referenced by: '<S84>/Constant1'
                                          * Inlane nudge safety margin between vehicle body and lane marker.

                                          */
real32_T KfLCCS_d_RearAxleToCameraOrigin = 0.0F;/* Variable: KfLCCS_d_RearAxleToCameraOrigin
                                                 * Referenced by: '<S5>/KfLCCS_d_RearAxleToCameraOrigin'
                                                 * The distance between rear axle and camera coordinates origin.
                                                 */
real32_T KfLCCS_d_ValidLaneWidthLimit = 4.5F;/* Variable: KfLCCS_d_ValidLaneWidthLimit
                                              * Referenced by: '<S9>/Constant3'
                                              */
real32_T KfLCCS_d_VehicleWidth = 3.0F; /* Variable: KfLCCS_d_VehicleWidth
                                        * Referenced by: '<S84>/Constant5'
                                        * Vehicle width.
                                        */
real32_T KfLCCS_d_lf = 1.93F;          /* Variable: KfLCCS_d_lf
                                        * Referenced by:
                                        *   '<S56>/Constant19'
                                        *   '<S59>/Constant12'
                                        *   '<S59>/Constant5'
                                        * Distance between center of mass and front axle.

                                        */
real32_T KfLCCS_d_lr = 2.72F;          /* Variable: KfLCCS_d_lr
                                        * Referenced by:
                                        *   '<S13>/rear_to_com_distance'
                                        *   '<S56>/Constant18'
                                        *   '<S59>/Constant'
                                        *   '<S59>/Constant11'
                                        * Distance between center of mass and rear axle.

                                        */
real32_T KfLCCS_d_min_turn_radius = 15.0F;/* Variable: KfLCCS_d_min_turn_radius
                                           * Referenced by: '<S56>/gps_trace_x3'
                                           * Minimum turn radius at lowest speed.

                                           */
real32_T KfLCCS_d_wheel_base = 2.5F;   /* Variable: KfLCCS_d_wheel_base
                                        * Referenced by:
                                        *   '<S10>/wheel_base'
                                        *   '<S59>/Constant10'
                                        *   '<S59>/Constant16'
                                        *   '<S59>/Constant4'
                                        *   '<S59>/Constant9'
                                        * Wheel base.
                                        */
real32_T KfLCCS_eps = 0.01F;           /* Variable: KfLCCS_eps
                                        * Referenced by: '<S56>/Constant3'
                                        * Tolerance for LQR solver.

                                        */
real32_T KfLCCS_heading_error_rate_limit = 0.03F;/* Variable: KfLCCS_heading_error_rate_limit
                                                  * Referenced by: '<S17>/Constant'
                                                  * High limit for calculated heading error rate.

                                                  */
real32_T KfLCCS_iz = 95363.0F;         /* Variable: KfLCCS_iz
                                        * Referenced by: '<S56>/Constant20'
                                        * Vehicle yaw inertia around -Z- axis.

                                        */
real32_T KfLCCS_k_LaneWidthFilter = 0.005F;/* Variable: KfLCCS_k_LaneWidthFilter
                                            * Referenced by: '<S9>/Constant13'
                                            * Filter to smooth lane width.
                                            */
real32_T KfLCCS_mass = 8805.0F;        /* Variable: KfLCCS_mass
                                        * Referenced by:
                                        *   '<S56>/Constant16'
                                        *   '<S59>/Constant1'
                                        *   '<S59>/Constant13'
                                        *   '<S59>/Constant6'
                                        * Vehicle mass.

                                        */
real32_T KfLCCS_r_MaxLateralSpeedPortion = 0.2F;/* Variable: KfLCCS_r_MaxLateralSpeedPortion
                                                 * Referenced by: '<S8>/Constant14'
                                                 * The maximum ratio of lateral speed over vehicle speed.
                                                 */
real32_T KfLCCS_r_YawRateCorrection = 1.0F;/* Variable: KfLCCS_r_YawRateCorrection
                                            * Referenced by: '<S11>/Constant17'
                                            * Correction factor for Yaw Rate from CAN bus.
                                            */
real32_T KfLCCS_r_shift_speed_gain = 0.4F;/* Variable: KfLCCS_r_shift_speed_gain
                                           * Referenced by: '<S8>/Constant1'
                                           * Lateral distance to go multiply by thisgain to calculate lateral shift speed.
                                           */
real32_T KfLCCS_r_steering_rate_forward_gain = 0.618F;/* Variable: KfLCCS_r_steering_rate_forward_gain
                                                       * Referenced by:
                                                       *   '<S81>/Constant2'
                                                       *   '<S81>/Constant3'
                                                       * Steering wheel turning speed gain when moving to forward direction.
                                                       */
real32_T KfLCCS_r_veh_strwhl_2_frtwhl_ratio = 19.315F;/* Variable: KfLCCS_r_veh_strwhl_2_frtwhl_ratio
                                                       * Referenced by:
                                                       *   '<S10>/Constant2'
                                                       *   '<S80>/Constant2'
                                                       *   '<S80>/Constant4'
                                                       *   '<S82>/Constant2'
                                                       *   '<S82>/Constant3'
                                                       * The gear ratio between steering wheel angle and front wheel angle.
                                                       */
real32_T KfLCCS_t_SampleTime = 0.01F;  /* Variable: KfLCCS_t_SampleTime
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
real32_T KfLCCS_t_TimestampAliveThresh = 2.0F;/* Variable: KfLCCS_t_TimestampAliveThresh
                                               * Referenced by:
                                               *   '<S12>/Constant1'
                                               *   '<S12>/Constant10'
                                               * Timestamp alive thresh to check the diff between EGMO and MPFU messages..
                                               */
real32_T KfLCCS_t_lateral_movement_delay = 0.5F;/* Variable: KfLCCS_t_lateral_movement_delay
                                                 * Referenced by: '<S156>/KfLCCS_lateral_movement_delay'
                                                 * When vehicle is moving, and steering control is active, lateral movement will be enabled after this time delay.
                                                 */
real32_T KfLCCS_v_shift_speed_high_limit = 1.0F;/* Variable: KfLCCS_v_shift_speed_high_limit
                                                 * Referenced by: '<S8>/Constant3'
                                                 * Lateral shift speed high limit.
                                                 */
real32_T KfLCCS_v_shift_speed_low_limit = 0.05F;/* Variable: KfLCCS_v_shift_speed_low_limit
                                                 * Referenced by: '<S8>/Constant2'
                                                 * Lateral shift speed low limit.
                                                 */
real32_T KtLCCS_AXIS_heading_error[21] =
{
  0.0F, 0.002F, 0.004F, 0.006F, 0.008F, 0.01F, 0.012F, 0.014F, 0.016F, 0.018F,
  0.02F, 0.022F, 0.024F, 0.026F, 0.028F, 0.03F, 0.032F, 0.034F, 0.036F, 0.038F,
  0.04F
} ;                                    /* Variable: KtLCCS_AXIS_heading_error
                                        * Referenced by: '<S56>/KtLCCS_heading_err_correction'
                                        * AXIS for heading error.
                                        */

real32_T KtLCCS_AXIS_lanemark_switch_time[21] =
{
  0.0F, 0.5F, 1.0F, 1.5F, 2.0F, 2.5F, 3.0F, 3.5F, 4.0F, 4.5F, 5.0F, 5.5F, 6.0F,
  6.5F, 7.0F, 7.5F, 8.0F, 8.5F, 9.0F, 9.5F, 10.0F
} ;                                    /* Variable: KtLCCS_AXIS_lanemark_switch_time
                                        * Referenced by:
                                        *   '<S6>/KtLCCS_k_LanemarkMergeCoef'
                                        *   '<S6>/KtLCCS_k_LanemarkMergeCoef1'
                                        * Lane marker switch time.
                                        */

real32_T KtLCCS_AXIS_route_curvature[5] =
{
  0.0F, 0.05F, 0.1F, 0.15F, 0.2F
} ;                                    /* Variable: KtLCCS_AXIS_route_curvature
                                        * Referenced by: '<S10>/KtLCCS_d_lookahead_distance'
                                        * Curvature axis.
                                        */

real32_T KtLCCS_AXIS_vehicle_speed[21] =
{
  0.0F, 2.0F, 4.0F, 6.0F, 8.0F, 10.0F, 12.0F, 14.0F, 16.0F, 18.0F, 20.0F, 22.0F,
  24.0F, 26.0F, 28.0F, 30.0F, 32.0F, 34.0F, 36.0F, 38.0F, 40.0F
} ;                                    /* Variable: KtLCCS_AXIS_vehicle_speed
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

real32_T KtLCCS_Ang_steering_angle_max[21] =
{
  624.0F, 560.202759F, 440.150635F, 306.479279F, 182.770386F, 123.938103F,
  94.9881363F, 76.9330902F, 58.2260895F, 39.5461311F, 22.5439491F, 18.0134506F,
  17.9457207F, 17.9968109F, 16.8257694F, 14.8115501F, 12.9539804F, 11.41712F,
  9.79043F, 8.93282F, 8.79801F
} ;                                    /* Variable: KtLCCS_Ang_steering_angle_max
                                        * Referenced by: '<S82>/KtLCCS_Ang_steering_angle_max'
                                        * Absolute maximum steering wheel angle. Unit: degree.
                                        */

real32_T KtLCCS_Ang_steering_angle_reentry_zone[21] =
{
  130.0F, 124.818588F, 106.262779F, 76.8281784F, 54.7944794F, 39.8260193F,
  30.1284103F, 25.8111095F, 22.0360394F, 18.3046494F, 14.5837898F, 10.73839F,
  8.7594F, 6.88753F, 5.12252F, 5.22353F, 5.20052F, 5.19857F, 5.19987F, 5.2013F,
  5.20104F
} ;                                    /* Variable: KtLCCS_Ang_steering_angle_reentry_zone
                                        * Referenced by: '<S12>/KtLCCS_Ang_steering_angle_reentry_zone'
                                        * Steering angle delta limit for re-engage control. Unit: degree.
                                        */

real32_T KtLCCS_Ang_steering_angle_step[21] =
{
  336.544F, 323.130402F, 275.09317F, 198.892883F, 141.851822F, 103.10173F,
  77.9966F, 61.8199692F, 50.1750183F, 43.9514351F, 38.6145668F, 35.5304718F,
  33.8415108F, 32.4306068F, 31.2967281F, 30.6F, 30.0F, 30.0F, 30.0F, 30.0F,
  30.0F
} ;                                    /* Variable: KtLCCS_Ang_steering_angle_step
                                        * Referenced by: '<S82>/KtLCCS_Ang_steering_angle_step'
                                        * Desired steering wheel angle moving step per second. Unit: degree/s.
                                        */

real32_T KtLCCS_Ang_steering_angle_step_engaging[21] =
{
  168.272F, 168.272F, 168.272F, 168.272F, 141.851822F, 103.10173F, 77.9966F,
  61.8199692F, 50.1750183F, 43.9514351F, 38.6145668F, 35.5304718F, 33.8415108F,
  32.4306068F, 31.2967281F, 30.6F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F
} ;                                    /* Variable: KtLCCS_Ang_steering_angle_step_engaging
                                        * Referenced by: '<S82>/KtLCCS_Ang_steering_angle_step_engaging'
                                        * Desired steering wheel angle moving step per second, when engaging steering control. Unit: degree/s.
                                        */

real32_T KtLCCS_d_lookahead_distance[105] =
{
  3.0F, 2.75F, 2.5F, 2.25F, 2.0F, 4.7621F, 4.3652F, 3.9684F, 3.5715F, 3.1747F,
  6.7222F, 6.162F, 5.6018F, 5.0416F, 4.4815F, 9.0402F, 8.2868F, 7.5335F, 6.7801F,
  6.0268F, 11.5338F, 10.5726F, 9.6115F, 8.6503F, 7.6892F, 14.6437F, 13.4234F,
  12.2031F, 10.9828F, 9.7625F, 18.3854F, 16.8533F, 15.3212F, 13.7891F, 12.257F,
  22.5976F, 20.7145F, 18.8314F, 16.9482F, 15.0651F, 27.5F, 25.2083F, 22.9166F,
  20.625F, 18.3333F, 32.8389F, 30.1023F, 27.3657F, 24.6292F, 21.8926F, 38.5305F,
  35.3196F, 32.1088F, 28.8979F, 25.687F, 45.1823F, 41.4171F, 37.6519F, 33.8867F,
  30.1216F, 52.4973F, 48.1225F, 43.7477F, 39.373F, 34.9982F, 60.4479F, 55.4105F,
  50.3732F, 45.3359F, 40.2986F, 69.0654F, 63.31F, 57.5545F, 51.7991F, 46.0436F,
  79.2486F, 72.6445F, 66.0405F, 59.4364F, 52.8324F, 88.6875F, 81.2969F, 73.9063F,
  66.5156F, 59.125F, 99.5465F, 91.251F, 82.9554F, 74.6599F, 66.3643F,
  109.454697F, 100.333504F, 91.2122F, 82.091F, 72.9698F, 119.555702F,
  109.592796F, 99.6298F, 89.6668F, 79.7038F, 130.357605F, 119.4944F, 108.631302F,
  97.7682F, 86.905F
} ;                                    /* Variable: KtLCCS_d_lookahead_distance
                                        * Referenced by: '<S10>/KtLCCS_d_lookahead_distance'
                                        * Vehicle lookahead distance.
                                        */

real32_T KtLCCS_heading_err_correction[21] =
{
  0.1F, 0.1F, 0.1F, 0.15F, 0.2F, 0.3F, 0.4F, 0.5F, 0.7F, 0.9F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F
} ;                                    /* Variable: KtLCCS_heading_err_correction
                                        * Referenced by: '<S56>/KtLCCS_heading_err_correction'
                                        * Correction for heading error.
                                        */

real32_T KtLCCS_heading_err_gain_scheduler[21] =
{
  1.0F, 0.8F, 0.7F, 0.6F, 0.55F, 0.5F, 0.45F, 0.4F, 0.38F, 0.36F, 0.36F, 0.36F,
  0.36F, 0.36F, 0.36F, 0.36F, 0.36F, 0.36F, 0.36F, 0.36F, 0.36F
} ;                                    /* Variable: KtLCCS_heading_err_gain_scheduler
                                        * Referenced by: '<S56>/KtLCCS_heading_err_gain_scheduler'
                                        * Gain for heading error scheduler.
                                        */

real32_T KtLCCS_heading_err_rate_correction[21] =
{
  1.0F, 0.8F, 0.7F, 0.6F, 0.55F, 0.5F, 0.45F, 0.4F, 0.38F, 0.36F, 0.36F, 0.36F,
  0.36F, 0.36F, 0.36F, 0.36F, 0.36F, 0.36F, 0.36F, 0.36F, 0.36F
} ;                                    /* Variable: KtLCCS_heading_err_rate_correction
                                        * Referenced by: '<S56>/KtLCCS_heading_err_rate_correction'
                                        * Correction for heading error rate.
                                        */

real32_T KtLCCS_heading_err_rate_gain_scheduler[21] =
{
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F, 0.2F
} ;                                    /* Variable: KtLCCS_heading_err_rate_gain_scheduler
                                        * Referenced by: '<S56>/KtLCCS_heading_err_rate_gain_scheduler'
                                        * Gain for heading error scheduler.
                                        */

real32_T KtLCCS_k_LanemarkMergeCoef[21] =
{
  0.001F, 0.002F, 0.004F, 0.008F, 0.016F, 0.032F, 0.064F, 0.128F, 0.256F, 0.512F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F
} ;                                    /* Variable: KtLCCS_k_LanemarkMergeCoef
                                        * Referenced by:
                                        *   '<S6>/KtLCCS_k_LanemarkMergeCoef'
                                        *   '<S6>/KtLCCS_k_LanemarkMergeCoef1'
                                        * Lane marker merging filter coef.
                                        */

real32_T KtLCCS_lateral_err_correction[21] =
{
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* Variable: KtLCCS_lateral_err_correction
                                        * Referenced by: '<S56>/KtLCCS_lateral_err_correction'
                                        * Correction for lateral error.
                                        */

real32_T KtLCCS_lateral_err_gain_scheduler[21] =
{
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* Variable: KtLCCS_lateral_err_gain_scheduler
                                        * Referenced by: '<S56>/KtLCCS_lateral_err_gain_scheduler'
                                        * Gain for lateral error scheduler.
                                        */

real32_T KtLCCS_lateral_err_rate_correction[21] =
{
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* Variable: KtLCCS_lateral_err_rate_correction
                                        * Referenced by: '<S56>/KtLCCS_lateral_err_rate_correction'
                                        * Correction for lateral error rate.
                                        */

real32_T KtLCCS_lateral_err_rate_gain_scheduler[21] =
{
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* Variable: KtLCCS_lateral_err_rate_gain_scheduler
                                        * Referenced by: '<S56>/KtLCCS_lateral_err_rate_gain_scheduler'
                                        * Gain for lateral error rate scheduler.
                                        */

real32_T KtLCCS_slowpath_steer_I_gain[21] =
{
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.01F, 0.0171F, 0.0235F, 0.032F, 0.04F,
  0.045F, 0.048F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F
} ;                                    /* Variable: KtLCCS_slowpath_steer_I_gain
                                        * Referenced by: '<S56>/KtLCCS_slowpath_steer_I_gain'
                                        * Gain for slowpath steer I part.
                                        */

real32_T KtLCCS_slowpath_steer_P_gain[21] =
{
  0.02F, 0.02F, 0.02F, 0.02F, 0.019F, 0.0175F, 0.016F, 0.0143F, 0.0125F, 0.0112F,
  0.01F, 0.009F, 0.008F, 0.007F, 0.006F, 0.005F, 0.005F, 0.005F, 0.005F, 0.005F,
  0.005F
} ;                                    /* Variable: KtLCCS_slowpath_steer_P_gain
                                        * Referenced by: '<S56>/KtLCCS_slowpath_steer_P_gain'
                                        * Gain for slowpath steer P part.
                                        */

real32_T KtLCCS_t_lateral_oscillation_period[21] =
{
  2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F,
  2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F
} ;                                    /* Variable: KtLCCS_t_lateral_oscillation_period
                                        * Referenced by: '<S56>/KtLCCS_t_lateral_oscillation_period'
                                        * THe control period of lateral oscillation.
                                        */

int32_T KcLCCS_HeadingErrorRateSmooth = 30;/* Variable: KcLCCS_HeadingErrorRateSmooth
                                            * Referenced by:
                                            *   '<S14>/Constant1'
                                            *   '<S14>/Constant4'
                                            * This number of heading error samples are used to calculate heading error rate.

                                            */
boolean_T KbLCCS_UsePurePursuit = 1;   /* Variable: KbLCCS_UsePurePursuit
                                        * Referenced by:
                                        *   '<S14>/gps_trace_x1'
                                        *   '<S14>/gps_trace_x5'
                                        *   '<S56>/gps_trace_x2'
                                        * True: Use lookahead point to calculate target driving direction.
                                        */
boolean_T KbLCCS_WheelEncoderReady = 0;/* Variable: KbLCCS_WheelEncoderReady
                                        * Referenced by:
                                        *   '<S11>/Constant16'
                                        *   '<S11>/Constant3'
                                        * Indicator for wheel encoder system ready.
                                        */
boolean_T KbLCCS_inlane_nudge_request_SLEW = 0;/* Variable: KbLCCS_inlane_nudge_request_SLEW
                                                * Referenced by: '<S11>/Constant13'
                                                * Calibration switch to SLEW inlane nudge request.
                                                */
boolean_T KbLCCS_inlane_nudge_request_value = 0;/* Variable: KbLCCS_inlane_nudge_request_value
                                                 * Referenced by: '<S11>/Constant14'
                                                 * Inlane nudge request value in SLEW mode.
                                                 */
boolean_T KbLCCS_lane_change_request_SLEW = 1;/* Variable: KbLCCS_lane_change_request_SLEW
                                               * Referenced by:
                                               *   '<S11>/Constant4'
                                               *   '<S11>/Constant6'
                                               * Calibration switch to SLEW lane change request.
                                               */
boolean_T KbLCCS_lane_change_request_value = 0;/* Variable: KbLCCS_lane_change_request_value
                                                * Referenced by: '<S11>/Constant5'
                                                * Lane change request value in SLEW mode.
                                                */
boolean_T KbLCCS_lane_change_source_ALCA = 0;/* Variable: KbLCCS_lane_change_source_ALCA
                                              * Referenced by:
                                              *   '<S8>/Constant15'
                                              *   '<S11>/Constant1'
                                              *   '<S11>/Constant2'
                                              * Lane change request source is ALCA.
                                              */
EnumDCSN_driving_direction KeLCCS_shifting_direction_value = FORWARD;/* Variable: KeLCCS_shifting_direction_value
                                                                      * Referenced by: '<S11>/Constant12'
                                                                      * Shifting direction value in SLEW mode.
                                                                      */
#pragma section

/* Block signals (auto storage) */
B_LCCS_subsystem_integrated_T LCCS_subsystem_integrated_B;

/* Block states (auto storage) */
DW_LCCS_subsystem_integrated_T LCCS_subsystem_integrated_DW;

/* Model step function */
void LCCS_subsystem_integrated_step(void)
{
  /* Outputs for Atomic SubSystem: '<S1>/LCCS' */
  LCCS_subsystem_integrated_LCCS();

  /* End of Outputs for SubSystem: '<S1>/LCCS' */
}

/* Model initialize function */
void LCCS_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset(((void *) &LCCS_subsystem_integrated_B), 0,
                sizeof(B_LCCS_subsystem_integrated_T));

  /* exported global signals */
  VsLCCS_DataBus = LCCS_subsystem_integrated_rtZLCCS_DataBus;
  VfLCCS_timestamp_EGMO = 0.0;
  VfLCCS_timestamp_MPFU = 0.0;
  VfLCCS_steering_angle_diff_abs = 0.0F;
  VfLCCS_lateral_v_from_ALCA = 0.0F;
  VfLCCS_linear_velocity = 0.0F;
  VfLCCS_velocity_rel_y = 0.0F;
  VfLCCS_velocity_rel_x = 0.0F;
  VfLCCS_veh_heading_rel = 0.0F;
  VfLCCS_EPS_ActualSteeringAngle = 0.0F;
  VfLCCS_yaw_rate = 0.0F;
  VfLCCS_lookahead_distance = 0.0F;
  VfLCCS_veh_frtwhl_angle_act = 0.0F;

  {
    int32_T i;
    for (i = 0; i < 6; i++)
    {
      VaLCCS_raw_left_lanemark[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 6; i++)
    {
      VaLCCS_raw_right_lanemark[i] = 0.0F;
    }
  }

  VfLCCS_smoothed_lane_width = 0.0F;
  VfLCCS_left_lanemark_confidence = 0.0F;
  VfLCCS_right_lanemark_confidence = 0.0F;
  VaLCCS_virtual_left_lanemark[0] = 0.0F;
  VaLCCS_virtual_left_lanemark[1] = 0.0F;
  VaLCCS_virtual_left_lanemark[2] = 0.0F;
  VaLCCS_virtual_left_lanemark[3] = 0.0F;
  VaLCCS_virtual_right_lanemark[0] = 0.0F;
  VaLCCS_virtual_right_lanemark[1] = 0.0F;
  VaLCCS_virtual_right_lanemark[2] = 0.0F;
  VaLCCS_virtual_right_lanemark[3] = 0.0F;
  VfLCCS_raw_lane_width = 0.0F;
  VfLCCS_c0_scaling = 0.0F;
  VfLCCS_target_lateral_shift_width = 0.0F;
  VfLCCS_lateral_shift_step = 0.0F;
  VfLCCS_lateral_dist_to_go = 0.0F;
  VfLCCS_lateral_shift_width = 0.0F;
  VaLCCS_shifted_lane_center_line[0] = 0.0F;
  VaLCCS_shifted_lane_center_line[1] = 0.0F;
  VaLCCS_shifted_lane_center_line[2] = 0.0F;
  VaLCCS_shifted_lane_center_line[3] = 0.0F;
  VfLCCS_frtwhl_angle_step_limit = 0.0F;
  VfLCCS_frtwhl_angle_limit_manual = 0.0F;
  VfLCCS_veh_frtwhl_angle_des_ramped = 0.0F;
  VfLCCS_veh_strwhl_angle_des = 0.0F;
  VfLCCS_steer_angle_feedback = 0.0F;
  VfLCCS_steer_angle_feedforward = 0.0F;
  VfLCCS_slowpath_steer_P = 0.0F;
  VfLCCS_slowpath_steer_I = 0.0F;
  VfLCCS_slowpath_steer_PI = 0.0F;
  VfLCCS_frtwhl_angle_limit_lat_acc = 0.0F;
  VfLCCS_veh_frtwhl_angle_des = 0.0F;
  VfLCCS_heading_error_contribution = 0.0F;
  VfLCCS_heading_error_rate_contribution = 0.0F;
  VfLCCS_lateral_error_contribution = 0.0F;
  VfLCCS_lateral_error_rate_contribution = 0.0F;
  VfLCCS_left_lanemark_switch_time = 0.0F;
  VaLCCS_final_left_lanemark[0] = 0.0F;
  VaLCCS_final_left_lanemark[1] = 0.0F;
  VaLCCS_final_left_lanemark[2] = 0.0F;
  VaLCCS_final_left_lanemark[3] = 0.0F;
  VfLCCS_right_lanemark_switch_time = 0.0F;
  VaLCCS_final_right_lanemark[0] = 0.0F;
  VaLCCS_final_right_lanemark[1] = 0.0F;
  VaLCCS_final_right_lanemark[2] = 0.0F;
  VaLCCS_final_right_lanemark[3] = 0.0F;
  VaLCCS_raw_lane_center_line[0] = 0.0F;
  VaLCCS_raw_lane_center_line[1] = 0.0F;
  VaLCCS_raw_lane_center_line[2] = 0.0F;
  VaLCCS_raw_lane_center_line[3] = 0.0F;
  VaLCCS_com_point[0] = 0.0F;
  VaLCCS_com_point[1] = 0.0F;
  VaLCCS_com_point[2] = 0.0F;
  VaLCCS_preview_proj_point[0] = 0.0F;
  VaLCCS_preview_proj_point[1] = 0.0F;
  VaLCCS_preview_proj_point[2] = 0.0F;
  VfLCCS_lookahead_angle = 0.0F;
  VaLCCS_com_proj_point[0] = 0.0F;
  VaLCCS_com_proj_point[1] = 0.0F;
  VaLCCS_com_proj_point[2] = 0.0F;
  VfLCCS_lateral_error = 0.0F;
  VfLCCS_heading_error_rate = 0.0F;
  VfLCCS_lateral_error_rate = 0.0F;
  VfLCCS_preview_curvature = 0.0F;
  VfLCCS_heading_error = 0.0F;
  VcLCCS_EPS_SteeringControlResponse_LCC = 0U;
  VfLCCS_num_lane_markers = 0U;
  VcLCCS_num_iteration = 0U;
  VbLCCS_steering_control_active = false;
  VbLCCS_LCC_ReadyToEngage = false;
  VbLCCS_LCC_ForceToDisengage = false;
  VbLCCS_steering_control_stable = false;
  VbLCCS_steering_control_engaged = false;
  VbLCCS_lateral_movement_enabled = false;
  VbLCCS_lane_change_request = false;
  VbLCCS_inlane_nudge_request = false;
  VbLCCS_input_isNaN_DCSN = false;
  VbLCCS_lcc_feature_enable = false;
  VbLCCS_steer_control_enable = false;
  VbLCCS_input_isNaN_ALCA = false;
  VbLCCS_input_isNaN_COMM = false;
  VbLCCS_input_isNaN_EGMO = false;
  VbLCCS_input_isNaN_MPFU = false;
  VbLCCS_left_lanemark_valid = false;
  VbLCCS_right_lanemark_valid = false;
  VbLCCS_both_lanemark_available = false;
  VbLCCS_shifting_in_progress = false;
  VbLCCS_touched_new_lane = false;
  VeLCCS_shifting_direction_raw = FORWARD;
  VeLCCS_shifting_direction_final = FORWARD;
  VeLCCS_valid_lane_marker = LCCS_NoLane;

  /* states (dwork) */
  (void) memset((void *)&LCCS_subsystem_integrated_DW, 0,
                sizeof(DW_LCCS_subsystem_integrated_T));

  /* SystemInitialize for Atomic SubSystem: '<S1>/LCCS' */
  LCCS_subsystem_integr_LCCS_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/LCCS' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
