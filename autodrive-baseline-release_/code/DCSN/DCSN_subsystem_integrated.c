/*
 * File: DCSN_subsystem_integrated.c
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

#include "DCSN_subsystem_integrated.h"
#include "DCSN_subsystem_integrated_private.h"

const DCSN_DataBus DCSN_subsystem_integrated_rtZDCSN_DataBus =
{
  {
    ADM_OFF,                           /* adm_main_mode */
    NO_MSG,                            /* adm_hmi_msg_display */
    NO_ICON,                           /* adm_hmi_icon_display */
    0U,                                /* usr_cmd_autodrive_activate */
    false,                             /* adm_accs_resume */
    false                              /* acoustic_warning_req */
  },                                   /* ADM_Group */

  {
    false,                             /* power_ctrl_enable */
    false,                             /* brake_ctrl_enable */
    false,                             /* steer_ctrl_enable */
    false,                             /* gear_ctrl_enable */
    false,                             /* epb_ctrl_enable */
    false,                             /* acc_feature_enable */
    false,                             /* lcc_feature_enable */
    false,                             /* alca_feature_enable */
    false,                             /* aeb_feature_enable */
    false,                             /* fcw_feature_enable */
    false,                             /* lcw_feature_enable */
    false,                             /* ldw_feature_enable */
    false,                             /* lka_feature_enable */
    false,                             /* bsd_feature_enable */
    false,                             /* lca_feature_enable */
    false,                             /* rcta_feature_enable */
    false,                             /* fcta_feature_enable */
    false,                             /* dow_feature_enable */
    AUTODRIVE_PASIV                    /* autodrive_control_mode */
  },                                   /* EnablingFlags_Group */

  {
    false,                             /* stop_request */
    0.0F,                              /* stop_s_distance */
    NO_STOP_REQUEST,                   /* stop_reason */
    0.0F,                              /* lane_speed_limit */
    0.0F,                              /* target_speed_limit */
    0.0F,                              /* speed_limit_distance */
    NO_LIMIT,                          /* speed_limit_reason */
    false,                             /* change_lane_request */
    FORWARD,                           /* change_lane_req_side */
    LC_NO_REQUEST,                     /* change_lane_reason */
    0.0F,                              /* change_lane_target_speed */
    false,                             /* change_lane_cancel_request */
    LC_CANCEL_NO_REQUEST,              /* change_lane_cancel_reason */
    false,                             /* inlane_nudge_request */
    FORWARD,                           /* inlane_nudge_side */
    NUDGE_NO_REQUEST,                  /* inlane_nudge_reason */
    false,                             /* pull_over_request */
    PULLOVER_NO_REQUEST,               /* pull_over_reason */
    false                              /* over_speed_warning */
  }                                    /* TrafficDecider_Group */
} ;                                    /* DCSN_DataBus ground */

/* Exported block signals */
EGMO_DataBus VsEGMO_DataBus;           /* '<Root>/EGMO_DataBus' */
MPFU_DataBus VsMPFU_DataBus;           /* '<Root>/MPFU_DataBus' */
OBFU_DataBus VsOBFU_DataBus;           /* '<Root>/OBFU_DataBus' */
DCSN_DataBus VsDCSN_DataBus;           /* '<S1>/Bus Creator' */
real32_T VfDCSN_vehicle_speed_egmo;    /* '<S70>/Signal Conversion'
                                        * The linear velocity of ego vehicle from egmo
                                        */
real32_T VfDCSN_SpdLimt_look_ahead_dis;/* '<S74>/Product'
                                        * look ahead distance when judging speed limit from curvature
                                        */
real32_T VfDCSN_largest_curvature_ahead;/* '<S74>/MinMax'
                                         * the largest curvature in look-ahead distance
                                         */
real32_T VfDCSN_speed_limit_curvature; /* '<S74>/1-D Lookup Table'
                                        * speed limit from curvature
                                        */
real32_T VfDCSN_raw_stop_line_distance;/* '<S160>/Merge3'
                                        * The raw stop line distance from mpfu
                                        */
real32_T VfDCSN_stop_s_distance;       /* '<S73>/Switch1'
                                        * stop distance
                                        */
real32_T VfDCSN_lane_speed_limit;      /* '<S73>/Switch2'
                                        * speed limit from ego lane
                                        */
real32_T VfDCSN_target_speed_limit;    /* '<S73>/Switch16'
                                        * speed limit from target point
                                        */
real32_T VfDCSN_speed_limit_distance;  /* '<S73>/Switch17'
                                        * the position of speed limit point
                                        */
real32_T VfDCSN_change_lane_target_speed;/* '<S73>/Switch5'
                                          * target speed when change lane
                                          */
real32_T VfDCSN_right_marker_raw_c0;   /* '<S100>/Signal Conversion9'
                                        * The raw c0
                                        */
real32_T VfDCSN_current_right_marker_cur;/* '<S150>/Divide'
                                          * current right marker curvature
                                          */
real32_T VfDCSN_right_marker_raw_c1;   /* '<S100>/Signal Conversion10'
                                        * The raw c1
                                        */
real32_T VfDCSN_current_right_edge_cur;/* '<S148>/Divide'
                                        * current right edge curvature
                                        */
real32_T VfDCSN_right_marker_raw_c2;   /* '<S100>/Signal Conversion11'
                                        * The raw c2
                                        */
real32_T VfDCSN_right_marker_raw_c3;   /* '<S100>/Signal Conversion12'
                                        * The raw c3
                                        */
real32_T VfDCSN_right_marker_raw_start_x;/* '<S100>/Signal Conversion13'
                                          * The raw start x
                                          */
real32_T VfDCSN_right_marker_raw_end_x;/* '<S100>/Signal Conversion15'
                                        * The raw end x
                                        */
real32_T VfDCSN_right_marker_raw_start_y;/* '<S100>/Signal Conversion14'
                                          * The raw start y
                                          */
real32_T VfDCSN_right_marker_raw_end_y;/* '<S100>/Signal Conversion16'
                                        * The raw end y
                                        */
real32_T VfDCSN_right_marker_raw_quality;/* '<S100>/Signal Conversion17'
                                          * The raw quality
                                          */
real32_T VfDCSN_left_marker_raw_c0;    /* '<S100>/Signal Conversion'
                                        * The raw c0
                                        */
real32_T VfDCSN_current_left_marker_cur;/* '<S149>/Divide'
                                         * current left marker curvature
                                         */
real32_T VfDCSN_left_marker_raw_c1;    /* '<S100>/Signal Conversion1'
                                        * The raw c1
                                        */
real32_T VfDCSN_current_left_edge_cur; /* '<S147>/Divide'
                                        * current left edge curvature
                                        */
real32_T VfDCSN_left_marker_raw_c2;    /* '<S100>/Signal Conversion2'
                                        * The raw c2
                                        */
real32_T VfDCSN_left_marker_raw_c3;    /* '<S100>/Signal Conversion3'
                                        * The raw c3
                                        */
real32_T VfDCSN_left_marker_raw_start_x;/* '<S100>/Signal Conversion4'
                                         * The raw start x
                                         */
real32_T VfDCSN_left_marker_raw_end_x; /* '<S100>/Signal Conversion6'
                                        * The raw end x
                                        */
real32_T VfDCSN_left_marker_raw_start_y;/* '<S100>/Signal Conversion5'
                                         * The raw start y
                                         */
real32_T VfDCSN_left_marker_raw_end_y; /* '<S100>/Signal Conversion7'
                                        * The raw end y
                                        */
real32_T VfDCSN_left_marker_raw_quality;/* '<S100>/Signal Conversion8'
                                         * The raw quality
                                         */
real32_T VfDCSN_speed_limit_ego_lane;  /* '<S156>/In1'
                                        * speed limit from ego lane
                                        */
uint16_T VfDCSN_C_cond_act_time;       /* '<S41>/In1'
                                        * The time count from driver presses activate switch and release the brake pedal.
                                          Valid when driver want to activate autodrive when brake or gas pedal pressed.
                                        */
uint8_T VfDCSN_mpfu_num_stop_lines;    /* '<S184>/Switch'
                                        * The number of input numbers of stop lines from mpfu
                                        */
uint8_T VeDCSN_usr_cmd_autodrive_activate;/* '<S7>/Switch'
                                           * usr activate cmd
                                             0 = deactivate
                                             1 = activate
                                             2 = hold
                                           */
boolean_T VbDCSN_mpfu_num_edges_isNaN; /* '<S183>/Relational Operator'
                                        * 0 = input is valid
                                          1 = input is NaN
                                        */
boolean_T VbDCSN_mpfu_num_markers_isNaN;/* '<S181>/Relational Operator'
                                         * 0 = input is valid
                                           1 = input is NaN
                                         */
boolean_T VbDCSN_has_left_marker;      /* '<S74>/Logical Operator3'
                                        * 0 = no left_marker
                                          1 = has left_marker
                                        */
boolean_T VbDCSN_has_right_marker;     /* '<S74>/Logical Operator4'
                                        * 0 = no right_marker
                                          1 = has right_marker
                                        */
boolean_T VbDCSN_CL_delay_finished;    /* '<S187>/RelationalOperator1'
                                        * Change lane request confirmed.
                                          Delay finished.
                                        */
boolean_T VbDCSN_speed_limit_enabled;  /* '<S72>/Logical Operator'
                                        * Whether the speed limit output is enabled
                                        */
boolean_T VbDCSN_overspeed_warning;    /* '<S66>/Switch'
                                        * 0 = speed in range
                                          1 = overspeed warning
                                        */
boolean_T VbDCSN_num_stop_lines_isNaN; /* '<S184>/Relational Operator'
                                        * The output stop lines number from mpfu
                                        */
boolean_T VbDCSN_has_valid_stop_line;  /* '<S160>/Logical Operator2'
                                        * 0 = no valid stop line
                                          1 = has valid stop line
                                        */
boolean_T VbDCSN_stop_line_distance_isNaN;/* '<S160>/Merge5'
                                           * 0 = distance from stop line is valid
                                             1 = distance from stop line is NaN
                                           */
boolean_T VbDCSN_accs_stop_finished;   /* '<S70>/Logical Operator'
                                        * If ACCS finished the stop request from DCSN
                                        */
boolean_T VbDCSN_raw_stop_finished;    /* '<S162>/Logical Operator1'
                                        * The raw signal:
                                          Whether ACCS has finished stop request before the stop line.
                                        */
boolean_T VbDCSN_hold_stop_finished;   /* '<S172>/Switch'
                                        * The time hold signal:
                                          Whether ACCS has finished stop request before the stop line.
                                        */
boolean_T VbDCSN_raw_stop_finished_late;/* '<S162>/Logical Operator2'
                                         * The raw signal:
                                           Whether ACCS has finished stop request after the stop line.
                                         */
boolean_T VbDCSN_stop_request_enabled; /* '<S72>/Logical Operator1'
                                        * 0 = Sending stop request is disabled
                                          1 = Sending stop request is ensabled
                                        */
boolean_T VbDCSN_should_send_stop_req; /* '<S162>/Logical Operator'
                                        * 0 = should not send stop req
                                          1 = should send stop req
                                        */
boolean_T VbDCSN_stop_line_is_close;   /* '<S162>/Logical Operator3'
                                        * 0 = stop line is far
                                          1 = stop line is close and will be updated by vehicle speed
                                        */
boolean_T VbDCSN_stop_unsuccess;       /* '<S162>/Relational Operator2'
                                        * Whether the ego vehicle failed to stop for this stop request
                                        */
boolean_T VbDCSN_stop_request;         /* '<S73>/Switch'
                                        * 0 = no stop request
                                          1 = stop request
                                        */
boolean_T VbDCSN_num_lanes_isNaN;      /* '<S182>/Relational Operator'
                                        * Whether lanes number from mpfu is NaN
                                        */
boolean_T VbDCSN_has_ego_lane;         /* '<S75>/Logical Operator'
                                        * 0 = no ego lane
                                          1 = has ego lane
                                        */
boolean_T VbDCSN_spd_limt_max_isNaN;   /* '<S75>/Merge1'
                                        * 0 = input speed limit is valid
                                          1 = input speed limit is NaN
                                        */
boolean_T VbDCSN_speed_limit_input_isNaN;/* '<S75>/Logical Operator1'
                                          * 0 = input is valid
                                            1 = input is NaN
                                          */
boolean_T VbDCSN_change_lane_request;  /* '<S73>/Switch3'
                                        * 0 = no change lane request
                                          1 = change lane request
                                        */
boolean_T VbDCSN_change_lane_cancel_request;/* '<S73>/Switch14'
                                             * 0 = no change lane cancel request
                                               1 = cancel change lane
                                             */
boolean_T VbDCSN_inlane_nudge_request; /* '<S73>/Switch6'
                                        * 0 = no inlane nudge request
                                          1 = request inlane nudge
                                        */
boolean_T VbDCSN_pull_over_request;    /* '<S73>/Switch8'
                                        * 0 = no pull over request
                                          1 = pull over
                                        */
boolean_T VbDCSN_stop_line_input_isNaN;/* '<S160>/Logical Operator3'
                                        * 0 = input is valid
                                          1 = input is NaN
                                        */
boolean_T VbDCSN_egmo_is_ready;        /* '<S179>/Compare'
                                        * 0 = egmo not ready
                                          1 = egmo ready
                                        */
boolean_T VbDCSN_mpfu_is_ready;        /* '<S180>/Compare'
                                        * 0 = mpfu not ready
                                          1 = mpfu ready
                                        */
boolean_T VbDCSN_input_is_ready;       /* '<S69>/Logical Operator'
                                        * 0 = input data is not ready
                                          1 = input data is ready
                                        */
boolean_T VbDCSN_right_marker_para_isNaN;/* '<S87>/Logical Operator'
                                          * 0 = c0/c1/c2/c3 no NaN input
                                            1 = c0/c1/c2/c3 have NaN input
                                          */
boolean_T VbDCSN_left_marker_para_isNaN;/* '<S85>/Logical Operator'
                                         * 0 = c0/c1/c2/c3 no NaN input
                                           1 = c0/c1/c2/c3 have NaN input
                                         */
boolean_T VbDCSN_right_edge_para_isNaN;/* '<S86>/Logical Operator'
                                        * 0 = c0/c1/c2/c3 no NaN input
                                          1 = c0/c1/c2/c3 have NaN input
                                        */
boolean_T VbDCSN_left_edge_para_isNaN; /* '<S84>/Logical Operator'
                                        * 0 = c0/c1/c2/c3 no NaN input
                                          1 = c0/c1/c2/c3 have NaN input
                                        */
boolean_T VbDCSN_acc_feature_enable;   /* '<S61>/Switch2'
                                        * 0 = acc not enabled
                                          1 = acc enabled
                                        */
boolean_T VbDCSN_power_control_inhibit;/* '<S58>/Logical Operator1'
                                        * 0 = power control not inhibit
                                          1 = power control inhibit
                                        */
boolean_T VbDCSN_power_ctrl_enable;    /* '<S61>/Switch7'
                                        * 0 = power not enabled
                                          1 = power enabled
                                        */
boolean_T VbDCSN_brake_ctrl_enable;    /* '<S61>/Logical Operator9'
                                        * 0 = brake not enabled
                                          1 = brake enabled

                                        */
boolean_T VbDCSN_steer_ctrl_enable;    /* '<S61>/Logical Operator2'
                                        * 0 = steer not enabled
                                          1 = steer enabled
                                        */
boolean_T VbDCSN_gear_ctrl_enable;     /* '<S61>/Switch10'
                                        * 0 = gear not enabled
                                          1 = gear enabled
                                        */
boolean_T VbDCSN_epb_ctrl_enable;      /* '<S61>/Switch11'
                                        * 0 = epb not enabled
                                          1 = epb enabled
                                        */
boolean_T VbDCSN_lcc_feature_enable;   /* '<S61>/Switch'
                                        * 0 = lcc not enabled
                                          1 = lcc enabled

                                        */
boolean_T VbDCSN_alca_feature_enable;  /* '<S61>/Switch1'
                                        * 0 = alca not enabled
                                          1 = alca enabled
                                        */
boolean_T VbDCSN_aeb_feature_enable;   /* '<S61>/Switch3'
                                        * 0 = aeb not enabled
                                          1 = aeb enabled

                                        */
boolean_T VbDCSN_fcw_feature_enable;   /* '<S61>/Switch4'
                                        * 0 = fcw not enabled
                                          1 = fcw enabled
                                        */
boolean_T VbDCSN_lcw_feature_enable;   /* '<S61>/Switch5'
                                        * 0 = lcw not enabled
                                          1 = lcw enabled

                                        */
boolean_T VbDCSN_ldw_feature_enable;   /* '<S61>/Switch6'
                                        * 0 = ldw not enabled
                                          1 = ldw enabled

                                        */
boolean_T VbDCSN_lka_feature_enable;   /* '<S61>/Switch13'
                                        * 0 = lka not enabled
                                          1 = lka enabled

                                        */
boolean_T VbDCSN_bsd_feature_enable;   /* '<S61>/Switch14'
                                        * 0 = bsd not enabled
                                          1 = bsd enabled

                                        */
boolean_T VbDCSN_lca_feature_enable;   /* '<S61>/Switch17'
                                        * 0 = lca not enabled
                                          1 = lca enabled

                                        */
boolean_T VbDCSN_rcta_feature_enable;  /* '<S61>/Switch18'
                                        * 0 = rcta not enabled
                                          1 = rcta enabled

                                        */
boolean_T VbDCSN_fcta_feature_enable;  /* '<S61>/Switch19'
                                        * 0 = fcta not enabled
                                          1 = fcta enabled

                                        */
boolean_T VbDCSN_dow_feature_enable;   /* '<S61>/Switch20'
                                        * 0 = dow not enabled
                                          1 = dow enabled

                                        */
boolean_T VbDCSN_cond_activate_met;    /* '<S14>/Data Type Conversion'
                                        * 0 = no acitvate request when brake/gas pedal is pressed
                                          1 = activate request when brake/gas pedal is pressed
                                        */
boolean_T VbDCSN_fault_detected;       /* '<S12>/Logical Operator'
                                        * Whether system fault is level 3,4,5.
                                        */
boolean_T VbDCSN_initialization_finished;/* '<S10>/Logical Operator'
                                          * Initialization process is finished.
                                            Including vehicle and controller.
                                          */
boolean_T VbDCSN_ACC_ready_to_engage;  /* '<S6>/Logical Operator'
                                        * ACCS subsystem ready
                                        */
boolean_T VbDCSN_autodrive_ready_to_engage;/* '<S15>/Logical Operator'
                                            * Whether the requirements of autodrive activation is all satisfied.
                                            */
boolean_T VbDCSN_autodrive_exit;       /* '<S16>/Logical Operator'
                                        * the flag if autodrive reqest exit
                                        */
boolean_T VbDCSN_autodrive_warning;    /* '<S17>/Logical Operator'
                                        * the flag if autodrive reqest warning
                                        */
boolean_T VbDCSN_accs_resume;          /* '<S3>/Switch2'
                                        * 0 = no accs resume request
                                          1 = accs resume request
                                        */
boolean_T VbDCSN_adm_steering_override;/* '<S9>/DtrmnDCSN_DrivIntention'
                                        * 0 = not override
                                          1 = override
                                        */
boolean_T VbDCSN_adm_steering_resume;  /* '<S9>/DtrmnDCSN_DrivIntention'
                                        * 0 = not resume
                                          1 = resume
                                        */
EnumDCSN_driving_direction VeDCSN_change_lane_req_side;/* '<S73>/Switch4'
                                                        * 0 = FORWARD
                                                          1 = LEFT
                                                          2 = RIGHT
                                                        */
EnumDCSN_driving_direction VfDCSN_inlane_nudge_side;/* '<S73>/Data Type Conversion6'
                                                     * inlane nudge side
                                                       0 = NA
                                                       1 = LEFT
                                                       2 = RIGHT
                                                     */
EnumDCSN_driving_direction VeDCSN_CL_req_side_pre;/* '<S186>/In1'
                                                   * 0 = FORWARD
                                                     1 = LEFT
                                                     2 = RIGHT
                                                   */
EnumDCSN_adm_main_mode VeDCSN_adm_main_mode;/* '<S8>/Switch'
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
EnumDCSN_adm_hmi_msg_display VeDCSN_hmi_msg_display;/* '<S8>/DtrmnDCSN_ADMManager'
                                                     * 0 = NO_MSG
                                                       1 = ACTIVE
                                                       2 = OVRD
                                                       3 = TAKOVER_REQ
                                                       4 = FAULT
                                                     */
EnumDCSN_adm_hmi_icon_display VeDCSN_hmi_icon_display;/* '<S8>/DtrmnDCSN_ADMManager'
                                                       * 0 = NO_ICON
                                                         1 = GREY_SOLID
                                                         2 = GREEN_SOLID
                                                         3 = BLUE_SOLID
                                                         4 = RED_FLASH_SLOW
                                                         5 = RED_FLASH_FAST
                                                         6 = RED_SOLID
                                                       */
EnumDCSN_autodrive_control_mode VeDCSN_autodrive_control_mode;/* '<S61>/Switch16'
                                                               * 0 = AUTODRIVE_PASIV
                                                                 1 = AUTODRIVE_DELAY
                                                                 2 = AUTODRIVE_RE_ACTIV
                                                                 3 = AUTODRIVE_ACTIVATING
                                                                 4 = AUTODRIVE_ACTIVATED
                                                               */
EnumDCSN_stop_reason VeDCSN_stop_reason;/* '<S73>/Switch10'
                                         * 0 = NO_STOP_REQUEST
                                           1 = STOP_FOR_DESTINATION
                                           2 = STOP_FOR_TRAFFIC_LIGHT
                                           3 = STOP_FOR_STOP_SIGN
                                           4 = STOP_FOR_STOP_LINE
                                           5 = STOP_FOR_CROSSWALK
                                           6 = STOP_FOR_KEEP_CLEAR
                                         */
EnumDCSN_speed_limit_reason VeDCSN_speed_limit_reason;/* '<S73>/Switch9'
                                                       * 0 = NO_LIMIT
                                                         1 = LIMIT_FOR_EGO_LANE
                                                         2 = LIMIT_FOR_DRIVER_REQ
                                                         3 = LIMIT_FOR_CROSSWALK
                                                         4 = LIMIT_FOR_NUDGE
                                                       */
EnumDCSN_change_lane_reason VeDCSN_change_lane_reason;/* '<S73>/Switch11'
                                                       * 0 = LC_NO_REQUEST
                                                         1 = LC_USER_CMD
                                                         2 = LC_NAVIGATION_CMD
                                                         3 = LC_FRONT_OBSTACLE
                                                       */
EnumDCSN_change_lane_cancel_reason VeDCSN_change_lane_cancel_reason;/* '<S73>/Switch15'
                                                                     * 0 = LC_CANCEL_NO_REQUEST
                                                                      1 = LC_CANCEL_USR_CMD
                                                                     */
EnumDCSN_inlane_nudge_reason VeDCSN_inlane_nudge_reason;/* '<S73>/Switch12'
                                                         * 0 = NUDGE_NO_REQUEST
                                                           1 = NUDGE_FRONT_OBSTACLE
                                                           2 = NUDGE_SIDE_OBSTACLE
                                                         */
EnumDCSN_pull_over_reason VeDCSN_pull_over_reason;/* '<S73>/Switch13'
                                                   * 0 = PULLOVER_NO_REQUEST
                                                     1 = PULLOVER_USER_CMD
                                                     2 = PULLOVER_POLICE
                                                     3 = PULLOVER_SYSTEM_FAULT
                                                   */
EnumDCSN_stop_request_mode VeDCSN_stop_request_mode;/* '<S162>/DtrmnDCSN_StopModeManager'
                                                     * 0 = NotEnabled
                                                       1 = WaitForValidStopLine
                                                       2 = CheckStopCond
                                                       3 = SendStopReqEgmoDis
                                                       4 = UpdateStopDis
                                                       5 = HoldForStopLineUpdate
                                                     */

/* Exported block parameters */
#pragma section ".cal"
real32_T KfDCSN_M_adm_temp_steering_ovrd_torque = 3.0F;/* Variable: KfDCSN_M_adm_temp_steering_ovrd_torque
                                                        * Referenced by: '<S47>/KfDCSN_M_adm_temp_steering_ovrd_torque'
                                                        * The torque for driver to override.
                                                        */
real32_T KfDCSN_M_adm_temp_steering_resume_torque = 1.0F;/* Variable: KfDCSN_M_adm_temp_steering_resume_torque
                                                          * Referenced by: '<S48>/KfDCSN_M_adm_temp_steering_resume_torque'
                                                          * The torque for driver to override.
                                                          */
real32_T KfDCSN_a_curvature_sample_point[8] =
{
  0.0F, 1.0F, 2.0F, 4.0F, 8.0F, 16.0F, 32.0F, 64.0F
} ;                                    /* Variable: KfDCSN_a_curvature_sample_point
                                        * Referenced by:
                                        *   '<S74>/KfDCSN_a_curvature_sample_point'
                                        *   '<S74>/KfDCSN_a_curvature_sample_point1'
                                        * The sample point of curvature calculation. Unit is %.
                                          From remote point to close point
                                        */

real32_T KfDCSN_d_Thrsh_request_stop = 200.0F;/* Variable: KfDCSN_d_Thrsh_request_stop
                                               * Referenced by: '<S162>/KfDCSN_d_Thrsh_request_stop'
                                               * The maximal distance between vehicle and stop line before sending stop request.
                                               */
real32_T KfDCSN_d_arc_length_integration_step = 0.1F;/* Variable: KfDCSN_d_arc_length_integration_step
                                                      * Referenced by:
                                                      *   '<S74>/KfDCSN_d_arc_length_integration_step2'
                                                      *   '<S74>/KfDCSN_d_arc_length_integration_step3'
                                                      * The step size of arc length integration when caculating the look ahead distance for curvature.
                                                      */
real32_T KfDCSN_d_rearaxle_frontbump = 3.3F;/* Variable: KfDCSN_d_rearaxle_frontbump
                                             * Referenced by: '<S170>/KfDCSN_d_rearaxle_frontbump'
                                             * The distance between rear axle and front bumper
                                             */
real32_T KfDCSN_d_speed_limit_distance_man_value = 0.0F;/* Variable: KfDCSN_d_speed_limit_distance_man_value
                                                         * Referenced by: '<S73>/Constant21'
                                                         * targe speed limit point distance
                                                         */
real32_T KfDCSN_d_stop_cleared_Thrsh = 2.0F;/* Variable: KfDCSN_d_stop_cleared_Thrsh
                                             * Referenced by: '<S162>/KfDCSN_d_stop_cleared_Thrsh'
                                             * The extra distance vehicle has to move before receiving new stop request
                                             */
real32_T KfDCSN_d_stop_close_Thrsh = 10.0F;/* Variable: KfDCSN_d_stop_close_Thrsh
                                            * Referenced by: '<S162>/KfDCSN_d_stop_close_Thrsh'
                                            * The threshold whether stop distance is calculated by vehicle speed.
                                            */
real32_T KfDCSN_d_stop_distance_buffer = 1.0F;/* Variable: KfDCSN_d_stop_distance_buffer
                                               * Referenced by: '<S170>/KfDCSN_d_stop_distance_buffer'
                                               * The buffer between vehicle and stop destination
                                               */
real32_T KfDCSN_d_stop_finished_dis = 3.0F;/* Variable: KfDCSN_d_stop_finished_dis
                                            * Referenced by: '<S162>/KfDCSN_d_stop_finished_dis'
                                            * When ACC finished stop request, the maximal distance between stop point and ego vehicle.
                                              If the stop distance is larger than the value, the stop request will not be cleared.
                                            */
real32_T KfDCSN_d_stop_s_distance_man_value = 0.0F;/* Variable: KfDCSN_d_stop_s_distance_man_value
                                                    * Referenced by: '<S171>/Constant2'
                                                    * manual stop control distance, valid only when KbDCSN_stop_man_enbl = true
                                                    */
real32_T KfDCSN_d_stop_unsuccess_Thrsh = 2.0F;/* Variable: KfDCSN_d_stop_unsuccess_Thrsh
                                               * Referenced by:
                                               *   '<S162>/KfDCSN_d_stop_unsuccess_Thrsh'
                                               *   '<S162>/KfDCSN_d_stop_unsuccess_Thrsh1'
                                               * The maximal distance from vehicle to stop line if vehicle had passed the stop line. This will regard current stop action as an unsuccessful stop.
                                               */
real32_T KfDCSN_k_largest_curvature_filter = 0.9F;/* Variable: KfDCSN_k_largest_curvature_filter
                                                   * Referenced by:
                                                   *   '<S74>/KfDCSN_k_largest_curvature_filter'
                                                   *   '<S74>/KfDCSN_k_largest_curvature_filter1'
                                                   * manual stop control distance, valid only when KbDCSN_stop_man_enbl = true
                                                   */
real32_T KfDCSN_t_adm_temp_steering_ovrd_delay = 0.2F;/* Variable: KfDCSN_t_adm_temp_steering_ovrd_delay
                                                       * Referenced by: '<S9>/KfDCSN_t_adm_temp_steering_ovrd_delay'
                                                       * when override conditions are met, the time to delay before exit.
                                                       */
real32_T KfDCSN_t_adm_temp_steering_resume_delay = 3.0F;/* Variable: KfDCSN_t_adm_temp_steering_resume_delay
                                                         * Referenced by: '<S9>/KfDCSN_t_adm_temp_steering_resume_delay'
                                                         * When resume conditions are met, the time before re-engaged.
                                                         */
real32_T KfDCSN_t_allowed_time_cond_activate = 5.0F;/* Variable: KfDCSN_t_allowed_time_cond_activate
                                                     * Referenced by: '<S14>/KfDCSN_t_allowed_time_cond_activate1'
                                                     * When driver want to activate autodirve with brake or gas pedal, the max time allowed between pushing activate switch and releasing brake or gas pedal
                                                     */
real32_T KfDCSN_t_autodrive_control_mode_delay = 0.5F;/* Variable: KfDCSN_t_autodrive_control_mode_delay
                                                       * Referenced by: '<S63>/KfDCSN_t_autodrive_control_mode_delay'
                                                       * the time that the system keeps sending activating request
                                                       */
real32_T KfDCSN_t_autodrive_max_wait_time = 2.0F;/* Variable: KfDCSN_t_autodrive_max_wait_time
                                                  * Referenced by: '<S53>/KfDCSN_t_autodrive_max_wait_time'
                                                  * the maximal wait time before the vehicle response to our activating request
                                                  */
real32_T KfDCSN_t_max_eps_inhibit_power = 1.0F;/* Variable: KfDCSN_t_max_eps_inhibit_power
                                                * Referenced by: '<S58>/KfDCSN_t_max_eps_inhibit_power'
                                                * The maximal allowed delay time to inhibit power control if EPS cannot response to CMD
                                                */
real32_T KfDCSN_t_max_time_fault_warning = 5.0F;/* Variable: KfDCSN_t_max_time_fault_warning
                                                 * Referenced by: '<S8>/KfDCSN_t_max_time_fault_warning'
                                                 * allowed reaction time after fault warning and before triggering emergency stop
                                                 */
real32_T KfDCSN_t_max_time_to_takeover = 5.0F;/* Variable: KfDCSN_t_max_time_to_takeover
                                               * Referenced by: '<S8>/KfDCSN_t_time_allowed_to_takeover'
                                               * allowed reaction time after both lane markers are missed but before autodrive exit
                                               */
real32_T KfDCSN_t_max_wait_cond_activate = 0.5F;/* Variable: KfDCSN_t_max_wait_cond_activate
                                                 * Referenced by: '<S14>/KfDCSN_t_max_wait_cond_activate'
                                                 * When driver want to activate autodirve with brake or gas pedal, the max wait time for adm active
                                                 */
real32_T KfDCSN_t_sample_time = 0.01F; /* Variable: KfDCSN_t_sample_time
                                        * Referenced by:
                                        *   '<S162>/KfDCSN_t_sample_time'
                                        *   '<S171>/KfDCSN_t_sample_time'
                                        * DCSN calculation sample time
                                        */
real32_T KfDCSN_t_stop_req_hold = 2.0F;/* Variable: KfDCSN_t_stop_req_hold
                                        * Referenced by:
                                        *   '<S172>/KfDCSN_t_stop_req_hold'
                                        *   '<S173>/KfDCSN_t_stop_req_hold'
                                        * When stop is finished, the stop request will be held for seconds.
                                        */
real32_T KfDCSN_t_usr_change_lane_delay = 0.5F;/* Variable: KfDCSN_t_usr_change_lane_delay
                                                * Referenced by: '<S185>/KfDCSN_t_usr_change_lane_delay'
                                                * The time delay between usr command and actual change lane action
                                                */
real32_T KfDCSN_v_adm_active_extraspeed = 10.0F;/* Variable: KfDCSN_v_adm_active_extraspeed
                                                 * Referenced by:
                                                 *   '<S20>/KfDCSN_v_adm_active_extraspeed'
                                                 *   '<S34>/KfDCSN_v_adm_active_extraspeed'
                                                 * When activating ACC control, max allowed delta speed between actual and ACC speed upper limit
                                                 */
real32_T KfDCSN_v_adm_temp_veh_setspeed = 33.34F;/* Variable: KfDCSN_v_adm_temp_veh_setspeed
                                                  * Referenced by: '<S8>/KfDCSN_v_adm_temp_veh_setspeed'
                                                  * Current vehicle acc set speed.
                                                    Not connect with ACCS yet
                                                  */
real32_T KfDCSN_v_autodrive_max_speed = 50.0F;/* Variable: KfDCSN_v_autodrive_max_speed
                                               * Referenced by: '<S23>/KfDCSN_v_autodrive_max_speed'
                                               * Max speed allowed by Autodrive system
                                                 If vehicle speed is larger than this value, autodrive will be deactivated immediately.
                                               */
real32_T KfDCSN_v_change_lane_target_speed_man_value = 0.0F;/* Variable: KfDCSN_v_change_lane_target_speed_man_value
                                                             * Referenced by: '<S73>/Constant8'
                                                             * manual change lane target speed, valid only when KbDCSN_change_lane_man_enbl = true
                                                             */
real32_T KfDCSN_v_default_warning_speed = 33.34F;/* Variable: KfDCSN_v_default_warning_speed
                                                  * Referenced by: '<S66>/KfDCSN_v_default_warning_speed'
                                                  * The maximal speed allowed when input speed limit is missed before warning request.
                                                  */
real32_T KfDCSN_v_lane_speed_limit_man_value = 0.0F;/* Variable: KfDCSN_v_lane_speed_limit_man_value
                                                     * Referenced by: '<S73>/Constant4'
                                                     * manual speed limit, valid only when KbDCSN_traffic_speed_limit_enble = true
                                                     */
real32_T KfDCSN_v_overspeed_warning_extra = 0.0F;/* Variable: KfDCSN_v_overspeed_warning_extra
                                                  * Referenced by:
                                                  *   '<S66>/KfDCSN_v_overspeed_warning_extra'
                                                  *   '<S66>/KfDCSN_v_overspeed_warning_extra1'
                                                  * The extra speed difference allowed when vehicle speed is higher than speed limit before warning request.
                                                  */
real32_T KfDCSN_v_setspeed_thrsh_hi = 38.89F;/* Variable: KfDCSN_v_setspeed_thrsh_hi
                                              * Referenced by:
                                              *   '<S20>/KfDCSN_v_setspeed_thrsh_hi'
                                              *   '<S34>/KfDCSN_v_setspeed_thrsh_hi'
                                              * Max allowed set speed for ACCS
                                              */
real32_T KfDCSN_v_target_speed_limit_man_value = 0.0F;/* Variable: KfDCSN_v_target_speed_limit_man_value
                                                       * Referenced by: '<S73>/Constant20'
                                                       * target speed in manual mode
                                                       */
real32_T KtDCSN_c_speed_limit_curve_axis[21] =
{
  0.0F, 0.001F, 0.003F, 0.005F, 0.007F, 0.01F, 0.015F, 0.02F, 0.03F, 0.04F,
  0.05F, 0.06F, 0.07F, 0.08F, 0.09F, 0.1F, 0.3F, 0.4F, 0.5F, 1.0F, 10.0F
} ;                                    /* Variable: KtDCSN_c_speed_limit_curve_axis
                                        * Referenced by: '<S74>/1-D Lookup Table'
                                        * Speed limit from curvature look up table axis
                                        */

real32_T KtDCSN_t_curvature_ahead_timegap[10] =
{
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F
} ;                                    /* Variable: KtDCSN_t_curvature_ahead_timegap
                                        * Referenced by: '<S74>/1-D Lookup Table1'
                                        * The look-ahead time gap for speed limit from curvature
                                        */

real32_T KtDCSN_v_ahead_timegap_speed_axis[10] =
{
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F
} ;                                    /* Variable: KtDCSN_v_ahead_timegap_speed_axis
                                        * Referenced by: '<S74>/1-D Lookup Table1'
                                        * The look-ahead time gap for speed limit from curvature
                                          speed axis
                                        */

real32_T KtDCSN_v_speed_limit_curve[21] =
{
  33.33F, 27.78F, 26.39F, 25.0F, 23.61F, 22.22F, 20.83F, 19.44F, 18.05F, 16.67F,
  15.28F, 13.89F, 12.25F, 11.11F, 9.27F, 8.33F, 6.94F, 5.55F, 4.17F, 2.78F, 0.0F
} ;                                    /* Variable: KtDCSN_v_speed_limit_curve
                                        * Referenced by: '<S74>/1-D Lookup Table'
                                        * Speed limit from curvature value
                                        */

uint8_T KbDCSN_SLEW_DriveModeComd_value = 0U;/* Variable: KbDCSN_SLEW_DriveModeComd_value
                                              * Referenced by: '<S61>/KbDCSN_SLEW_DriveModeComd_value'
                                              * SLEW mode
                                                the DriveModeComd value
                                              */
uint8_T KcDCSN_t_usr_activate_cmd_send_count = 10U;/* Variable: KcDCSN_t_usr_activate_cmd_send_count
                                                    * Referenced by: '<S7>/KcDCSN_t_usr_activate_cmd_send_count1'
                                                    * send count of usr_activate_action, valid when KbDCSN_use_vehicle_activate_switch = true
                                                      unit: seconds
                                                    */
uint8_T KeDCSN_adm_main_mode_man_value = 0U;/* Variable: KeDCSN_adm_main_mode_man_value
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
uint8_T KeDCSN_adm_temp_diag_system_fault = 0U;/* Variable: KeDCSN_adm_temp_diag_system_fault
                                                * Referenced by: '<S8>/KeDCSN_adm_temp_diag_system_fault'
                                                * System faults
                                                  0 = no fault
                                                  1,2 = warning faults
                                                  3,4,5 = exit faults
                                                */
uint8_T KeDCSN_change_lane_cancel_reason_man_value = 0U;/* Variable: KeDCSN_change_lane_cancel_reason_man_value
                                                         * Referenced by: '<S73>/Constant19'
                                                         * 0 = LC_CANCEL_NO_REQUEST
                                                           1 = LC_CANCEL_USR_CMD
                                                         */
uint8_T KeDCSN_change_lane_reason_man_value = 0U;/* Variable: KeDCSN_change_lane_reason_man_value
                                                  * Referenced by: '<S73>/Constant16'
                                                  * 0 = LC_NO_REQUEST
                                                    1 = LC_USER_CMD
                                                    2 = LC_NAVIGATION_CMD
                                                    3 = LC_FRONT_OBSTACLE
                                                  */
uint8_T KeDCSN_change_lane_req_side_man_value = 0U;/* Variable: KeDCSN_change_lane_req_side_man_value
                                                    * Referenced by: '<S73>/Constant7'
                                                    * manual change lane side, valid only when KbDCSN_change_lane_man_enbl = true
                                                      0 = NA
                                                      1 = LEFT
                                                      2 = RIGHT
                                                    */
uint8_T KeDCSN_control_mode_man_value = 4U;/* Variable: KeDCSN_control_mode_man_value
                                            * Referenced by: '<S61>/ldw_switch2'
                                            * 0 = AUTODRIVE_PASIV
                                              1 = AUTODRIVE_DELAY
                                              2 = AUTODRIVE_RE_ACTIV
                                              3 = AUTODRIVE_ACTIVATING
                                              4 = AUTODRIVE_ACTIVATED
                                            */
uint8_T KeDCSN_inlane_nudge_reason_man_value = 0U;/* Variable: KeDCSN_inlane_nudge_reason_man_value
                                                   * Referenced by: '<S73>/Constant17'
                                                   * 0 = NUDGE_NO_REQUEST
                                                     1 = NUDGE_FRONT_OBSTACLE
                                                     2 = NUDGE_SIDE_OBSTACLE
                                                   */
uint8_T KeDCSN_pull_over_reason_man_value = 0U;/* Variable: KeDCSN_pull_over_reason_man_value
                                                * Referenced by: '<S73>/Constant18'
                                                * 0 = PULLOVER_NO_REQUEST
                                                  1 = PULLOVER_USER_CMD
                                                  2 = PULLOVER_POLICE
                                                  3 = PULLOVER_SYSTEM_FAULT
                                                */
uint8_T KeDCSN_speed_limit_reason_man_value = 0U;/* Variable: KeDCSN_speed_limit_reason_man_value
                                                  * Referenced by: '<S73>/Constant14'
                                                  * 0 = NO_LIMIT
                                                    1 = LIMIT_FOR_EGO_LANE
                                                    2 = LIMIT_FOR_DRIVER_REQ
                                                    3 = LIMIT_FOR_CROSSWALK
                                                    4 = LIMIT_FOR_NUDGE
                                                  */
uint8_T KeDCSN_stop_reason_man_value = 0U;/* Variable: KeDCSN_stop_reason_man_value
                                           * Referenced by: '<S73>/Constant15'
                                           * 0 = NO_STOP_REQUEST
                                             1 = STOP_FOR_DESTINATION
                                             2 = STOP_FOR_TRAFFIC_LIGHT
                                             3 = STOP_FOR_STOP_SIGN
                                             4 = STOP_FOR_STOP_LINE
                                             5 = STOP_FOR_CROSSWALK
                                             6 = STOP_FOR_KEEP_CLEAR
                                           */
uint8_T KeDCSN_usr_cmd_autodrive_activate_man = 0U;/* Variable: KeDCSN_usr_cmd_autodrive_activate_man
                                                    * Referenced by: '<S7>/KfDCSN_adm_temp_usr_cmd_autodrive_activated'
                                                    * 0 = Deactivate
                                                      1 = Activate
                                                      2 = Hold
                                                    */
uint8_T KfDCSN_Pct_lane_marker_valid_quality = 20U;/* Variable: KfDCSN_Pct_lane_marker_valid_quality
                                                    * Referenced by:
                                                    *   '<S78>/KfDCSN_Pct_lane_marker_valid_quality'
                                                    *   '<S79>/KfDCSN_Pct_lane_marker_valid_quality'
                                                    * The quality threshold for valid lane marker or edge
                                                    */
uint8_T KfDCSN_d_inlane_nudge_side_man_value = 0U;/* Variable: KfDCSN_d_inlane_nudge_side_man_value
                                                   * Referenced by: '<S73>/Constant12'
                                                   * manual inlane nudge side, valid only when KbDCSN_inlane_nudge_man_enbl = true
                                                     0 = NA
                                                     1 = LEFT
                                                     2 = RIGHT
                                                   */
boolean_T KbDCSN_SLEW_DriveModeComd_enbl = 0;/* Variable: KbDCSN_SLEW_DriveModeComd_enbl
                                              * Referenced by: '<S61>/KbDCSN_SLEW_DriveModeComd_enbl'
                                              * 0 = use COMM DriverModeComd
                                                1 = use SLEW DriverModeComd
                                              */
boolean_T KbDCSN_SLEW_initialization_finished = 0;/* Variable: KbDCSN_SLEW_initialization_finished
                                                   * Referenced by: '<S10>/KbDCSN_SLEW_initialization_finished'
                                                   * 0 = use initialization finished judgement logic
                                                     1 = initialization finished
                                                   */
boolean_T KbDCSN_acc_man_enbl = 0;     /* Variable: KbDCSN_acc_man_enbl
                                        * Referenced by: '<S61>/aeb_switch2'
                                        * 0 = manual override disabled
                                          1 = manual override enabled
                                        */
boolean_T KbDCSN_accs_resume_man_enbl = 0;/* Variable: KbDCSN_accs_resume_man_enbl
                                           * Referenced by: '<S3>/aeb_switch12'
                                           * 0 = manual accs resume override disabled
                                             1 = manual accs resume override enabled
                                           */
boolean_T KbDCSN_accs_resume_man_value = 0;/* Variable: KbDCSN_accs_resume_man_value
                                            * Referenced by: '<S3>/aeb_switch8'
                                            * manual change lane switch, valid only when KbDCSN_accs_resume_man_enbl = true
                                              Pulse signal when reverse.
                                            */
boolean_T KbDCSN_active_feature_man_ctrl = 0;/* Variable: KbDCSN_active_feature_man_ctrl
                                              * Referenced by: '<S61>/aeb_switch4'
                                              * For all active features (ACC, LCC, ALCA):
                                                0 = manual override disabled
                                                1 = manual override enabled
                                              */
boolean_T KbDCSN_adm_BrkPressDeactivateEnabled = 0;/* Variable: KbDCSN_adm_BrkPressDeactivateEnabled
                                                    * Referenced by: '<S23>/Constant7'
                                                    * 0 = cannot activate when BrkPed is pressed
                                                      1 = can activate when BrkPed is pressed
                                                    */
boolean_T KbDCSN_adm_main_mode_man_ctrl = 0;/* Variable: KbDCSN_adm_main_mode_man_ctrl
                                             * Referenced by:
                                             *   '<S8>/Constant2'
                                             *   '<S60>/Constant5'
                                             * 0 = manual override disabled
                                               1 = manual override enabled
                                             */
boolean_T KbDCSN_adm_temp_stop_finished = 1;/* Variable: KbDCSN_adm_temp_stop_finished
                                             * Referenced by: '<S8>/KfDCSN_adm_temp_stop_finished'
                                             * 0 = not finished
                                               1 = finished
                                             */
boolean_T KbDCSN_adm_temp_usr_cmd_autodrive_enabled = 1;/* Variable: KbDCSN_adm_temp_usr_cmd_autodrive_enabled
                                                         * Referenced by: '<S8>/KfDCSN_adm_temp_usr_cmd_autodrive_enabled'
                                                         * 0 = not enabled
                                                           1 = enabled
                                                         */
boolean_T KbDCSN_aeb_man_enbl = 0;     /* Variable: KbDCSN_aeb_man_enbl
                                        * Referenced by: '<S61>/aeb_switch'
                                        * 0 = Close AEB
                                          1 = Open AEB
                                        */
boolean_T KbDCSN_aeb_usr_switch = 0;   /* Variable: KbDCSN_aeb_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_aeb_usr_switch'
                                        * AEB feature user switch
                                        */
boolean_T KbDCSN_alca_man_enbl = 0;    /* Variable: KbDCSN_alca_man_enbl
                                        * Referenced by: '<S61>/aeb_switch3'
                                        * 0 = manual override disabled
                                          1 = manual override enabled
                                        */
boolean_T KbDCSN_alca_usr_switch = 1;  /* Variable: KbDCSN_alca_usr_switch
                                        * Referenced by: '<S52>/KbDCSN_acla_usr_switch'
                                        * ALCA feature user switch
                                        */
boolean_T KbDCSN_brake_ctrl_man_enbl = 0;/* Variable: KbDCSN_brake_ctrl_man_enbl
                                          * Referenced by: '<S61>/aeb_switch12'
                                          * 0 = manual override disabled
                                            1 = manual override enabled
                                          */
boolean_T KbDCSN_brake_ctrl_man_value = 0;/* Variable: KbDCSN_brake_ctrl_man_value
                                           * Referenced by: '<S61>/aeb_switch8'
                                           * manual brake control switch, valid only when KbDCSN_brake_ctrl_man_enbl = true
                                             0 = brake control off
                                             1 = brake control on
                                           */
boolean_T KbDCSN_bsd_man_enbl = 0;     /* Variable: KbDCSN_bsd_man_enbl
                                        * Referenced by: '<S61>/ldw_switch4'
                                        * 0 = Close BSD
                                          1 = Open BSD
                                        */
boolean_T KbDCSN_bsd_usr_switch = 1;   /* Variable: KbDCSN_bsd_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_bsd_usr_switch'
                                        * BSD feature user switch
                                        */
boolean_T KbDCSN_change_lane_cancel_request_man_value = 0;/* Variable: KbDCSN_change_lane_cancel_request_man_value
                                                           * Referenced by: '<S73>/Constant2'
                                                           * manual change lane switch, valid only when KbDCSN_change_lane_man_enbl = true
                                                             0 = no change lane cancel request
                                                             1 = change lane cancel request
                                                           */
boolean_T KbDCSN_change_lane_enable = 1;/* Variable: KbDCSN_change_lane_enable
                                         * Referenced by: '<S72>/KbDCSN_change_lane_enable'
                                         * 0 = disable change lane request
                                           1 = enable change lane request
                                         */
boolean_T KbDCSN_change_lane_man_enbl = 0;/* Variable: KbDCSN_change_lane_man_enbl
                                           * Referenced by: '<S73>/Constant5'
                                           * traffic decider
                                             0 = manual change lane off
                                             1 = manual change lane on
                                           */
boolean_T KbDCSN_change_lane_request_man_value = 0;/* Variable: KbDCSN_change_lane_request_man_value
                                                    * Referenced by: '<S73>/Constant6'
                                                    * manual change lane switch, valid only when KbDCSN_change_lane_man_enbl = true
                                                      0 = no change lane request
                                                      1 = change lane request
                                                    */
boolean_T KbDCSN_control_mode_man_enbl = 0;/* Variable: KbDCSN_control_mode_man_enbl
                                            * Referenced by: '<S61>/ldw_switch1'
                                            * Override the output auotdirve control main mode.
                                              0 = not override
                                              1 = override
                                            */
boolean_T KbDCSN_dow_man_enbl = 0;     /* Variable: KbDCSN_dow_man_enbl
                                        * Referenced by: '<S61>/ldw_switch8'
                                        * 0 = Close DOW
                                          1 = Open DOW
                                        */
boolean_T KbDCSN_dow_usr_switch = 1;   /* Variable: KbDCSN_dow_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_dow_usr_switch'
                                        * DOW feature user switch
                                        */
boolean_T KbDCSN_enable_warning_no_input = 0;/* Variable: KbDCSN_enable_warning_no_input
                                              * Referenced by: '<S66>/KbDCSN_enable_warning_no_input'
                                              * 0 = disable warning if no speed limit input
                                                1 = use default speed limit to warn if no speed limit input
                                              */
boolean_T KbDCSN_epb_ctrl_man_enbl = 0;/* Variable: KbDCSN_epb_ctrl_man_enbl
                                        * Referenced by: '<S61>/aeb_switch15'
                                        * 0 = manual override disabled
                                          1 = manual override enabled
                                        */
boolean_T KbDCSN_epb_ctrl_man_value = 0;/* Variable: KbDCSN_epb_ctrl_man_value
                                         * Referenced by: '<S61>/aeb_switch11'
                                         * manual epb control switch, valid only when KbDCSN_epb_ctrl_man_enbl = true
                                           0 = epb release
                                           1 = epb engage
                                         */
boolean_T KbDCSN_fcta_man_enbl = 0;    /* Variable: KbDCSN_fcta_man_enbl
                                        * Referenced by: '<S61>/ldw_switch7'
                                        * 0 = Close FCTA
                                          1 = Open FCTA
                                        */
boolean_T KbDCSN_fcta_usr_switch = 1;  /* Variable: KbDCSN_fcta_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_fcta_usr_switch'
                                        * FCTA feature user switch
                                        */
boolean_T KbDCSN_fcw_man_enbl = 0;     /* Variable: KbDCSN_fcw_man_enbl
                                        * Referenced by: '<S61>/fcw_switch'
                                        * 0 = manual FCW off
                                          1 = manual FCW on
                                        */
boolean_T KbDCSN_fcw_usr_switch = 1;   /* Variable: KbDCSN_fcw_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_fcw_usr_switch'
                                        * FCW feature user switch
                                        */
boolean_T KbDCSN_gear_ctrl_man_enbl = 0;/* Variable: KbDCSN_gear_ctrl_man_enbl
                                         * Referenced by: '<S61>/aeb_switch14'
                                         * 0 = manual override disabled
                                           1 = manual override enabled
                                         */
boolean_T KbDCSN_gear_ctrl_man_value = 0;/* Variable: KbDCSN_gear_ctrl_man_value
                                          * Referenced by: '<S61>/aeb_switch10'
                                          * manual gear control switch, valid only when KbDCSN_gear_ctrl_man_enbl = true
                                            0 = gear control off
                                            1 = gear control on
                                          */
boolean_T KbDCSN_inhibit_power_for_eps_enable = 1;/* Variable: KbDCSN_inhibit_power_for_eps_enable
                                                   * Referenced by: '<S58>/KbDCSN_inhibit_power_for_eps_enable'
                                                   * 0 = disable power inhibit when EPS is out of control
                                                     1 = enable power inhibit when EPS is out of control
                                                   */
boolean_T KbDCSN_inlane_nudge_man_enbl = 0;/* Variable: KbDCSN_inlane_nudge_man_enbl
                                            * Referenced by: '<S73>/Constant9'
                                            * traffic decider
                                              0 = manual inlane nudge off
                                              1 = manual inlane nudge on
                                            */
boolean_T KbDCSN_inlane_nudge_request_man_value = 0;/* Variable: KbDCSN_inlane_nudge_request_man_value
                                                     * Referenced by: '<S73>/Constant11'
                                                     * manual inlane nudge switch, valid only when KbDCSN_inlane_nudge_request_man_enbl = true
                                                       0 = no inlane nudge request
                                                       1 = inlane nudge request
                                                     */
boolean_T KbDCSN_lca_man_enbl = 0;     /* Variable: KbDCSN_lca_man_enbl
                                        * Referenced by: '<S61>/ldw_switch5'
                                        * 0 = Close LCA
                                          1 = Open LCA
                                        */
boolean_T KbDCSN_lca_usr_switch = 1;   /* Variable: KbDCSN_lca_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_lca_usr_switch'
                                        * LCA feature user switch
                                        */
boolean_T KbDCSN_lcc_man_enbl = 0;     /* Variable: KbDCSN_lcc_man_enbl
                                        * Referenced by: '<S61>/aeb_switch1'
                                        * 0 = manual LCC off
                                          1 = manual LCC on
                                        */
boolean_T KbDCSN_lcc_usr_switch = 1;   /* Variable: KbDCSN_lcc_usr_switch
                                        * Referenced by: '<S8>/KbDCSN_lcc_usr_switch'
                                        * LCC feature user switch
                                        */
boolean_T KbDCSN_lcw_man_enbl = 0;     /* Variable: KbDCSN_lcw_man_enbl
                                        * Referenced by: '<S61>/lcw_switch'
                                        * 0 = manual LCW off
                                          1 = manual LCW on
                                        */
boolean_T KbDCSN_lcw_usr_switch = 1;   /* Variable: KbDCSN_lcw_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_lcw_usr_switch'
                                        * LCW feature user switch
                                        */
boolean_T KbDCSN_ldw_man_enbl = 0;     /* Variable: KbDCSN_ldw_man_enbl
                                        * Referenced by: '<S61>/ldw_switch'
                                        * 0 = manual LDW off
                                          1 = manual LDW on
                                        */
boolean_T KbDCSN_ldw_usr_switch = 0;   /* Variable: KbDCSN_ldw_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_ldw_usr_switch'
                                        * LDW feature user switch
                                        */
boolean_T KbDCSN_lka_man_enbl = 0;     /* Variable: KbDCSN_lka_man_enbl
                                        * Referenced by: '<S61>/ldw_switch3'
                                        * 0 = Close LKA
                                          1 = Open LKA
                                        */
boolean_T KbDCSN_lka_usr_switch = 0;   /* Variable: KbDCSN_lka_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_lka_usr_switch'
                                        * LKA feature user switch
                                        */
boolean_T KbDCSN_overspeed_warning_enable = 1;/* Variable: KbDCSN_overspeed_warning_enable
                                               * Referenced by: '<S72>/KbDCSN_overspeed_warning_enable'
                                               * 0 = disable overspeed warning
                                                 1 = enable overspeed warning
                                               */
boolean_T KbDCSN_passive_feature_man_ctrl = 0;/* Variable: KbDCSN_passive_feature_man_ctrl
                                               * Referenced by: '<S61>/aeb_switch5'
                                               * For all passive features (AEB, FCW, LDW, LCW):
                                                 0 = manual override disabled
                                                 1 = manual override enabled
                                               */
boolean_T KbDCSN_power_ctrl_man_enbl = 0;/* Variable: KbDCSN_power_ctrl_man_enbl
                                          * Referenced by: '<S61>/aeb_switch6'
                                          * 0 = manual override disabled
                                            1 = manual override enabled
                                          */
boolean_T KbDCSN_power_ctrl_man_value = 0;/* Variable: KbDCSN_power_ctrl_man_value
                                           * Referenced by: '<S61>/aeb_switch7'
                                           * manual power control switch, valid only when KbDCSN_power_ctrl_man_enbl = true
                                             0 = power control off
                                             1 = power control on
                                           */
boolean_T KbDCSN_pull_over_man_enbl = 0;/* Variable: KbDCSN_pull_over_man_enbl
                                         * Referenced by: '<S73>/Constant10'
                                         * traffic decider
                                           0 = manual pull over off
                                           1 = manual pull over on
                                         */
boolean_T KbDCSN_pull_over_request_man_value = 0;/* Variable: KbDCSN_pull_over_request_man_value
                                                  * Referenced by: '<S73>/Constant13'
                                                  * manual pull over switch, valid only when KbDCSN_pull_over_request_man_enbl = true
                                                    0 = no pull over request
                                                    1 = pull over request
                                                  */
boolean_T KbDCSN_rcta_man_enbl = 0;    /* Variable: KbDCSN_rcta_man_enbl
                                        * Referenced by: '<S61>/ldw_switch6'
                                        * 0 = Close RCTA
                                          1 = Open RCTA
                                        */
boolean_T KbDCSN_rcta_usr_switch = 1;  /* Variable: KbDCSN_rcta_usr_switch
                                        * Referenced by: '<S4>/KbDCSN_rcta_usr_switch'
                                        * RCTA feature user switch
                                        */
boolean_T KbDCSN_speed_limit_enable = 1;/* Variable: KbDCSN_speed_limit_enable
                                         * Referenced by: '<S72>/KbDCSN_speed_limit_enable'
                                         * 0 = disable speed limit output
                                           1 = enable speed limit output
                                         */
boolean_T KbDCSN_speed_limit_man_enbl = 0;/* Variable: KbDCSN_speed_limit_man_enbl
                                           * Referenced by: '<S73>/Constant3'
                                           * traffic decider
                                             0 = manual speed limit off
                                             1 = manual speed limit on
                                           */
boolean_T KbDCSN_steer_ctrl_man_enbl = 0;/* Variable: KbDCSN_steer_ctrl_man_enbl
                                          * Referenced by: '<S61>/aeb_switch13'
                                          * 0 = manual override disabled
                                            1 = manual override enabled
                                          */
boolean_T KbDCSN_steer_ctrl_man_value = 0;/* Variable: KbDCSN_steer_ctrl_man_value
                                           * Referenced by: '<S61>/aeb_switch9'
                                           * manual steer control switch, valid only when KbDCSN_steer_ctrl_man_enbl = true
                                             0 = steer control off
                                             1 = steer control on
                                           */
boolean_T KbDCSN_stop_man_enbl = 0;    /* Variable: KbDCSN_stop_man_enbl
                                        * Referenced by: '<S73>/Constant'
                                        * traffic decider
                                          0 = manual stop off
                                          1 = manual stop on
                                        */
boolean_T KbDCSN_stop_request_enable = 1;/* Variable: KbDCSN_stop_request_enable
                                          * Referenced by: '<S72>/KbDCSN_stop_request_enable'
                                          * 0 = disable stop request output
                                            1 = enable stop request output
                                          */
boolean_T KbDCSN_stop_request_man_value = 0;/* Variable: KbDCSN_stop_request_man_value
                                             * Referenced by:
                                             *   '<S73>/Constant1'
                                             *   '<S161>/Constant1'
                                             * manual stop control switch, valid only when KbDCSN_stop_man_enbl = true
                                               0 = no stop request
                                               1 = stop request
                                             */
boolean_T KbDCSN_use_EgmoLinearSpeed = 1;/* Variable: KbDCSN_use_EgmoLinearSpeed
                                          * Referenced by: '<S3>/aeb_switch1'
                                          * 0 = Use vehicle CAN velocity
                                            1 = Use egmo linear velocity
                                          */
boolean_T KbDCSN_use_EgmoReadyFlag = 0;/* Variable: KbDCSN_use_EgmoReadyFlag
                                        * Referenced by:
                                        *   '<S3>/aeb_switch16'
                                        *   '<S4>/aeb_switch16'
                                        * 0 = use calibration to output EGMO ready flag
                                          1 = use EGMO ready flag
                                        */
boolean_T KbDCSN_use_MpfuReadyFlag = 0;/* Variable: KbDCSN_use_MpfuReadyFlag
                                        * Referenced by: '<S3>/aeb_switch2'
                                        * 0 = use calibration to output MPFU ready flag
                                          1 = use MPFU ready flag
                                        */
boolean_T KbDCSN_use_SLEW_override_logic = 1;/* Variable: KbDCSN_use_SLEW_override_logic
                                              * Referenced by: '<S60>/aeb_switch17'
                                              * 0 = disable override logic in SLEW
                                                1 = enable override logic in SLEW

                                              */
boolean_T KbDCSN_use_SLEW_switch_control_mode = 0;/* Variable: KbDCSN_use_SLEW_switch_control_mode
                                                   * Referenced by: '<S53>/KbDCSN_use_SLEW_switch_control_mode'
                                                   * 0 = Use normal control mode logic
                                                     1 = Use driver switch as control mode activated
                                                   */
boolean_T KbDCSN_use_faw_handoff_as_ovrd = 0;/* Variable: KbDCSN_use_faw_handoff_as_ovrd
                                              * Referenced by: '<S46>/KbDCSN_use_faw_handoff_as_ovrd'
                                              * 0 = use HandOn flag as override flag
                                                1 = use HandOff flag as override flag
                                              */
boolean_T KbDCSN_use_faw_handoff_as_resume = 1;/* Variable: KbDCSN_use_faw_handoff_as_resume
                                                * Referenced by: '<S46>/KbDCSN_use_faw_handoff_as_resume'
                                                * 0 = use HandOn flag as resume flag
                                                  1 = use HandOff flag as resume flag
                                                */
boolean_T KbDCSN_use_faw_l4_logic = 0; /* Variable: KbDCSN_use_faw_l4_logic
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
boolean_T KbDCSN_use_vehicle_activate_switch = 1;/* Variable: KbDCSN_use_vehicle_activate_switch
                                                  * Referenced by: '<S7>/KbDCSN_use_vehicle_activate_switch'
                                                  * 0 = use calibration activate switch
                                                    1 = use vehicle activate switch
                                                  */
#pragma section
/* Block signals (auto storage) */
B_DCSN_subsystem_integrated_T DCSN_subsystem_integrated_B;

/* Block states (auto storage) */
DW_DCSN_subsystem_integrated_T DCSN_subsystem_integrated_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_DCSN_subsystem_integr_T DCSN_subsystem_integrat_PrevZCX;

/* Model step function */
void DCSN_subsystem_integrated_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/DtrmnDCSN_Integrated' */
  DCSN_subsy_DtrmnDCSN_Integrated();

  /* End of Outputs for SubSystem: '<Root>/DtrmnDCSN_Integrated' */
}

/* Model initialize function */
void DCSN_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  (void) memset(((void *) &DCSN_subsystem_integrated_B), 0,
                sizeof(B_DCSN_subsystem_integrated_T));

  {
    DCSN_subsystem_integrated_B.adm_main_mode = ADM_OFF;
  }

  /* exported global signals */
  VsDCSN_DataBus = DCSN_subsystem_integrated_rtZDCSN_DataBus;
  VfDCSN_vehicle_speed_egmo = 0.0F;
  VfDCSN_SpdLimt_look_ahead_dis = 0.0F;
  VfDCSN_largest_curvature_ahead = 0.0F;
  VfDCSN_speed_limit_curvature = 0.0F;
  VfDCSN_raw_stop_line_distance = 0.0F;
  VfDCSN_stop_s_distance = 0.0F;
  VfDCSN_lane_speed_limit = 0.0F;
  VfDCSN_target_speed_limit = 0.0F;
  VfDCSN_speed_limit_distance = 0.0F;
  VfDCSN_change_lane_target_speed = 0.0F;
  VfDCSN_right_marker_raw_c0 = 0.0F;
  VfDCSN_current_right_marker_cur = 0.0F;
  VfDCSN_right_marker_raw_c1 = 0.0F;
  VfDCSN_current_right_edge_cur = 0.0F;
  VfDCSN_right_marker_raw_c2 = 0.0F;
  VfDCSN_right_marker_raw_c3 = 0.0F;
  VfDCSN_right_marker_raw_start_x = 0.0F;
  VfDCSN_right_marker_raw_end_x = 0.0F;
  VfDCSN_right_marker_raw_start_y = 0.0F;
  VfDCSN_right_marker_raw_end_y = 0.0F;
  VfDCSN_right_marker_raw_quality = 0.0F;
  VfDCSN_left_marker_raw_c0 = 0.0F;
  VfDCSN_current_left_marker_cur = 0.0F;
  VfDCSN_left_marker_raw_c1 = 0.0F;
  VfDCSN_current_left_edge_cur = 0.0F;
  VfDCSN_left_marker_raw_c2 = 0.0F;
  VfDCSN_left_marker_raw_c3 = 0.0F;
  VfDCSN_left_marker_raw_start_x = 0.0F;
  VfDCSN_left_marker_raw_end_x = 0.0F;
  VfDCSN_left_marker_raw_start_y = 0.0F;
  VfDCSN_left_marker_raw_end_y = 0.0F;
  VfDCSN_left_marker_raw_quality = 0.0F;
  VfDCSN_speed_limit_ego_lane = 0.0F;
  VfDCSN_C_cond_act_time = 0U;
  VfDCSN_mpfu_num_stop_lines = 0U;
  VeDCSN_usr_cmd_autodrive_activate = 0U;
  VbDCSN_mpfu_num_edges_isNaN = false;
  VbDCSN_mpfu_num_markers_isNaN = false;
  VbDCSN_has_left_marker = false;
  VbDCSN_has_right_marker = false;
  VbDCSN_CL_delay_finished = false;
  VbDCSN_speed_limit_enabled = false;
  VbDCSN_overspeed_warning = false;
  VbDCSN_num_stop_lines_isNaN = false;
  VbDCSN_has_valid_stop_line = false;
  VbDCSN_stop_line_distance_isNaN = false;
  VbDCSN_accs_stop_finished = false;
  VbDCSN_raw_stop_finished = false;
  VbDCSN_hold_stop_finished = false;
  VbDCSN_raw_stop_finished_late = false;
  VbDCSN_stop_request_enabled = false;
  VbDCSN_should_send_stop_req = false;
  VbDCSN_stop_line_is_close = false;
  VbDCSN_stop_unsuccess = false;
  VbDCSN_stop_request = false;
  VbDCSN_num_lanes_isNaN = false;
  VbDCSN_has_ego_lane = false;
  VbDCSN_spd_limt_max_isNaN = false;
  VbDCSN_speed_limit_input_isNaN = false;
  VbDCSN_change_lane_request = false;
  VbDCSN_change_lane_cancel_request = false;
  VbDCSN_inlane_nudge_request = false;
  VbDCSN_pull_over_request = false;
  VbDCSN_stop_line_input_isNaN = false;
  VbDCSN_egmo_is_ready = false;
  VbDCSN_mpfu_is_ready = false;
  VbDCSN_input_is_ready = false;
  VbDCSN_right_marker_para_isNaN = false;
  VbDCSN_left_marker_para_isNaN = false;
  VbDCSN_right_edge_para_isNaN = false;
  VbDCSN_left_edge_para_isNaN = false;
  VbDCSN_acc_feature_enable = false;
  VbDCSN_power_control_inhibit = false;
  VbDCSN_power_ctrl_enable = false;
  VbDCSN_brake_ctrl_enable = false;
  VbDCSN_steer_ctrl_enable = false;
  VbDCSN_gear_ctrl_enable = false;
  VbDCSN_epb_ctrl_enable = false;
  VbDCSN_lcc_feature_enable = false;
  VbDCSN_alca_feature_enable = false;
  VbDCSN_aeb_feature_enable = false;
  VbDCSN_fcw_feature_enable = false;
  VbDCSN_lcw_feature_enable = false;
  VbDCSN_ldw_feature_enable = false;
  VbDCSN_lka_feature_enable = false;
  VbDCSN_bsd_feature_enable = false;
  VbDCSN_lca_feature_enable = false;
  VbDCSN_rcta_feature_enable = false;
  VbDCSN_fcta_feature_enable = false;
  VbDCSN_dow_feature_enable = false;
  VbDCSN_cond_activate_met = false;
  VbDCSN_fault_detected = false;
  VbDCSN_initialization_finished = false;
  VbDCSN_ACC_ready_to_engage = false;
  VbDCSN_autodrive_ready_to_engage = false;
  VbDCSN_autodrive_exit = false;
  VbDCSN_autodrive_warning = false;
  VbDCSN_accs_resume = false;
  VbDCSN_adm_steering_override = false;
  VbDCSN_adm_steering_resume = false;
  VeDCSN_change_lane_req_side = FORWARD;
  VfDCSN_inlane_nudge_side = FORWARD;
  VeDCSN_CL_req_side_pre = FORWARD;
  VeDCSN_adm_main_mode = ADM_OFF;
  VeDCSN_hmi_msg_display = NO_MSG;
  VeDCSN_hmi_icon_display = NO_ICON;
  VeDCSN_autodrive_control_mode = AUTODRIVE_PASIV;
  VeDCSN_stop_reason = NO_STOP_REQUEST;
  VeDCSN_speed_limit_reason = NO_LIMIT;
  VeDCSN_change_lane_reason = LC_NO_REQUEST;
  VeDCSN_change_lane_cancel_reason = LC_CANCEL_NO_REQUEST;
  VeDCSN_inlane_nudge_reason = NUDGE_NO_REQUEST;
  VeDCSN_pull_over_reason = PULLOVER_NO_REQUEST;
  VeDCSN_stop_request_mode = NotEnabled;

  /* states (dwork) */
  (void) memset((void *)&DCSN_subsystem_integrated_DW, 0,
                sizeof(DW_DCSN_subsystem_integrated_T));

  /* external inputs */
  (void)memset(&VsOBFU_DataBus, 0, sizeof(OBFU_DataBus));
  (void)memset(&VsMPFU_DataBus, 0, sizeof(MPFU_DataBus));
  (void)memset(&VsEGMO_DataBus, 0, sizeof(EGMO_DataBus));
  DCSN_subsystem_integrat_PrevZCX.CvrtDCSN_DataConvert_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<Root>/DtrmnDCSN_Integrated' */
  DCSN__DtrmnDCSN_Integrated_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/DtrmnDCSN_Integrated' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
