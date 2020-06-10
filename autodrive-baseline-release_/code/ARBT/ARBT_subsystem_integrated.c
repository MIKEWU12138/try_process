/*
 * File: ARBT_subsystem_integrated.c
 *
 * Code generated for Simulink model 'ARBT_subsystem_integrated'.
 *
 * Model version                  : 1.644
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  2 11:29:36 2020
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

#include "ARBT_subsystem_integrated.h"
#include "ARBT_subsystem_integrated_private.h"

/* Named constants for Chart: '<S10>/VehicleStandstillStateEst' */
#define ARBT_subsyst_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define ARBT_subsystem__IN_Moving_delay ((uint8_T)2U)
#define ARBT_subsystem_integr_IN_Moving ((uint8_T)1U)
#define ARBT_subsystem_integrat_IN_Stop ((uint8_T)3U)

/* Named constants for Chart: '<S11>/Acceleration_Estimation' */
#define ARBT_subsystem_int_IN_Releasing ((uint8_T)3U)
#define ARBT_subsystem_inte_IN_Released ((uint8_T)2U)
#define ARBT_subsystem_integ_IN_Clamped ((uint8_T)1U)

/* Named constants for Chart: '<S12>/stop_and_go_control_states' */
#define ARBT_subsy_IN_AutoDriveInactive ((uint8_T)2U)
#define ARBT_subsy_IN_Release_Auto_hold ((uint8_T)4U)
#define ARBT_subsyst_IN_Act_Gear_P_or_N ((uint8_T)2U)
#define ARBT_subsyst_IN_AutoDriveActive ((uint8_T)1U)
#define ARBT_subsyste_IN_Auto_Drive_Req ((uint8_T)1U)
#define ARBT_subsystem_IN_Auto_hold_req ((uint8_T)1U)
#define ARBT_subsystem_in_IN_Act_Gear_D ((uint8_T)1U)
#define ARBT_subsystem_in_IN_Act_Gear_R ((uint8_T)3U)
#define ARBT_subsystem_int_IN_Init_m2h1 ((uint8_T)3U)
#define ARBT_subsystem_integ_IN_Go_to_D ((uint8_T)2U)
#define ARBT_subsystem_integ_IN_Go_to_P ((uint8_T)2U)
#define ARBT_subsystem_integrat_IN_Init ((uint8_T)4U)

/* Named constants for Chart: '<S7>/DtrmnDriverHardBrake' */
#define ARBT__IN_POTENTIAL_HARD_BRAKING ((uint8_T)3U)
#define ARBT_sub_IN_DRIVER_HARD_BRAKING ((uint8_T)1U)
#define ARBT_subsyste_IN_NORMAL_DRIVING ((uint8_T)2U)

/* Named constants for Chart: '<S7>/DtrmnRecTrigger' */
#define ARBT_sub_IN_NORMAL_DRIVING_e10u ((uint8_T)3U)
#define ARBT_subsys_IN_MISSED_AEB_EVENT ((uint8_T)2U)
#define ARBT_subsyst_IN_FALSE_AEB_EVENT ((uint8_T)1U)
#define ARBT_subsyst_IN_POTENTIAL_FALSE ((uint8_T)4U)
#define ARBT_subsyste_IN_POTENTIAL_MISS ((uint8_T)5U)

const ARBT_DataBus ARBT_subsystem_integrated_rtZARBT_DataBus =
{
  {
    0.0F,                              /* brake_req_lon_a */
    false,                             /* brake_ctrl_enbl_to_comm */
    false,                             /* brake_precharge_req */
    false                              /* brake_priority_setting */
  },                                   /* BrakeGroup */

  {
    0U,                                /* steer_req_mode */
    0.0F,                              /* steer_req_strwhl_angle */
    0.0F,                              /* steer_req_strwhl_torque */
    false                              /* steer_ctrl_enbl_to_comm */
  },                                   /* SteerGroup */

  {
    0U,                                /* power_req_mode */
    0.0F,                              /* power_req_lon_a */
    0.0F,                              /* power_req_torque */
    false                              /* power_ctrl_enbl_to_comm */
  },                                   /* PowerGroup */

  {
    false,                             /* warn_haptic_req */
    false,                             /* warn_acoustic_req */
    false,                             /* warn_visual_lcw_left_req */
    false,                             /* warn_visual_lcw_right_req */
    false,                             /* warn_visual_ldw_left_req */
    false,                             /* warn_visual_ldw_right_req */
    false                              /* warn_visual_fcw_req */
  },                                   /* WarningGroup */

  {
    false,                             /* epb_ctrl_enbl_to_comm */
    false,                             /* epb_switch_request */
    0U,                                /* epb_control_mode */
    false,                             /* gear_ctrl_enbl_to_comm */
    0U,                                /* gear_ctrl_req */
    false,                             /* auto_hold_req */
    false                              /* horn_ctrl_req */
  },                                   /* AccessoryGroup */

  {
    false,                             /* missed_aeb_flag */
    false,                             /* false_aeb_flag */
    false,                             /* driver_hard_braking_flag */
    false                              /* aeb_triggered_flag */
  }                                    /* RecTrigFlagGroup */
} ;                                    /* ARBT_DataBus ground */

/* Exported block signals */
ARBT_DataBus VsARBT_DataBus;           /* '<S5>/Bus Creator' */
real32_T VfARBT_steer_req_strwhl_angle;/* '<S29>/Switch2'
                                        * final steer angle req (as deg) after arbitration and saturation
                                        */
real32_T VfARBT_steer_req_strwhl_angle_raw;/* '<S8>/MATLAB Function'
                                            * raw steer angle request after arbitration before saturation
                                            */
real32_T VfARBT_steer_req_strwhl_torque;/* '<S8>/MATLAB Function' */
real32_T VfARBT_power_req_lon_a_raw;   /* '<S6>/Switch2'
                                        * raw power request after arbitration before saturation
                                        */
real32_T VfARBT_power_req_lon_a;       /* '<S22>/Switch2'
                                        * final power req (as m/s2) after arbitration and saturation
                                        */
real32_T VfARBT_power_req_torque;      /* '<S6>/Switch1' */
real32_T VfARBT_brake_req_lon_a_raw;   /* '<S4>/Switch4'
                                        * raw brake request after arbitration before saturation
                                        */
real32_T VfARBT_brake_req_lon_a;       /* '<S21>/Switch2'
                                        * final brake req (as m/s2) after arbitration and saturation
                                        */
uint8_T VfARBT_steer_req_mode;         /* '<S8>/Constant'
                                        * 0 = acceleration mode
                                          1 = torque mode
                                        */
uint8_T VfARBT_power_req_mode;         /* '<S6>/Constant2'
                                        * 0 = steering wheel angle
                                          1 = steering wheel torque
                                        */
uint8_T VfARBT_gear_pos_req;           /* '<S12>/stop_and_go_control_states'
                                        * Gear Pos Definition
                                          0->N
                                          1->D
                                          13->R
                                          14->P
                                          15->Invalid
                                        */
uint8_T VfARBT_gear_ctrl_state;        /* '<S12>/stop_and_go_control_states' */
uint8_T VbARBT_EPB_ctrl_mode;          /* '<S11>/Acceleration_Estimation' */
boolean_T VbARBT_FCW_level_three;      /* '<S9>/Logical Operator15' */
boolean_T VbARBT_FCW_level_one;        /* '<S9>/Logical Operator' */
boolean_T VbARBT_FCW_level_two;        /* '<S9>/Logical Operator1' */
boolean_T VbARBT_LDW_left;             /* '<S9>/Logical Operator2' */
boolean_T VbARBT_BSD_left_low_raw;     /* '<S9>/Logical Operator4' */
boolean_T VbARBT_BSD_right_low_raw;    /* '<S9>/Logical Operator5' */
boolean_T VbARBT_LCA_left_low_raw;     /* '<S9>/Logical Operator6' */
boolean_T VbARBT_LCA_right_low_raw;    /* '<S9>/Logical Operator7' */
boolean_T VbARBT_warn_lcw_left_req;    /* '<S9>/Logical Operator9' */
boolean_T VbARBT_LDW_right;            /* '<S9>/Logical Operator3' */
boolean_T VbARBT_BSD_left_high_raw;    /* '<S9>/Logical Operator11' */
boolean_T VbARBT_LCA_left_high_raw;    /* '<S9>/Logical Operator13' */
boolean_T VbARBT_BSD_right_high_raw;   /* '<S9>/Logical Operator12' */
boolean_T VbARBT_LCA_right_high_raw;   /* '<S9>/Logical Operator14' */
boolean_T VbARBT_FCW_level_four;       /* '<S9>/Logical Operator16' */
boolean_T VbARBT_FCW_level_five;       /* '<S9>/Logical Operator17' */
boolean_T VbARBT_warn_lcw_right_req;   /* '<S9>/Logical Operator10' */
boolean_T VbARBT_steer_ctrl_enbl_to_comm;/* '<S8>/Logical Operator2' */
boolean_T VbARBT_aeb_triggered_flag;   /* '<S7>/Logical Operator'
                                        * Flag of whether AEB is triggered
                                        */
boolean_T VbARBT_missed_aeb_flag;      /* '<S7>/DtrmnRecTrigger'
                                        * Flag of whether a missed aeb event is detected
                                        */
boolean_T VbARBT_false_aeb_flag;       /* '<S7>/DtrmnRecTrigger'
                                        * Flag of whether a false AEB event is detected

                                        */
boolean_T VbARBT_driver_hard_brake_flag;/* '<S7>/DtrmnDriverHardBrake'
                                         * Flag of whether driver is taking a hard brake
                                         */
boolean_T VbARBT_power_ctrl_enbl_to_comm;/* '<S6>/Switch3' */
boolean_T VbARBT_brake_ctrl_enbl_to_comm;/* '<S4>/Logical Operator4' */
boolean_T VbARBT_EPB_ctrl_enbl_to_comm;/* '<S11>/Logical Operator3' */
boolean_T VbARBT_vehicle_standstill;   /* '<S10>/Data Type Conversion' */
boolean_T VbARBT_EPB_switch_request;   /* '<S11>/Switch'
                                        * 1 = clamping request
                                          0 = release request
                                        */
boolean_T VbARBT_gear_ctrl_enbl_to_comm;/* '<S12>/Logical Operator' */
boolean_T VbARBT_auto_hold_req;        /* '<S12>/stop_and_go_control_states' */
EnumARBT_arbitration_winner VeARBT_steer_arbt_winner;/* '<S8>/MATLAB Function' */
EnumARBT_arbitration_winner VeARBT_power_arbt_winner;/* '<S6>/Switch4' */
EnumARBT_arbitration_winner VeARBT_brake_arbt_winner;/* '<S4>/Switch3' */

/* Exported block parameters */
#pragma section ".cal"

real32_T KfARBT_autohold_timeout = 20.0F;/* Variable: KfARBT_autohold_timeout
                                          * Referenced by: '<S3>/Constant1'
                                          * Unit in second
                                          */
real32_T KfARBT_brake_req_lon_a_lowerlimit = -4.0F;/* Variable: KfARBT_brake_req_lon_a_lowerlimit
                                                    * Referenced by: '<S4>/Constant7'
                                                    * Lower limit for brake longitudinal acceleration request output (in m/s2)
                                                    */
real32_T KfARBT_brake_req_lon_a_upperlimit = 0.0F;/* Variable: KfARBT_brake_req_lon_a_upperlimit
                                                   * Referenced by: '<S4>/Constant6'
                                                   * Upper limit for brake longitudinal acceleration request output (in m/s2)
                                                   */
real32_T KfARBT_brk_ped_pos_thrsh_rec_trig = 50.0F;/* Variable: KfARBT_brk_ped_pos_thrsh_rec_trig
                                                    * Referenced by: '<S7>/Constant1'
                                                    * Threshold of actual brake pedal position to determine if driver is taking a hard brake
                                                    */
real32_T KfARBT_lon_a_thrsh_rec_trig = -2.0F;/* Variable: KfARBT_lon_a_thrsh_rec_trig
                                              * Referenced by: '<S7>/Constant'
                                              * Threshold of longitudinal acceleration to determine if the driver is taking a hard brake
                                              */
real32_T KfARBT_power_req_lon_a_lowerlimit = 0.0F;/* Variable: KfARBT_power_req_lon_a_lowerlimit
                                                   * Referenced by: '<S6>/Constant7'
                                                   * Lower limit for power longitudinal acceleration request output (in m/s2)
                                                   */
real32_T KfARBT_power_req_lon_a_upperlimit = 4.0F;/* Variable: KfARBT_power_req_lon_a_upperlimit
                                                   * Referenced by: '<S6>/Constant6'
                                                   * Lower limit for power longitudinal acceleration request output (in m/s2)
                                                   */
real32_T KfARBT_steer_req_strwhl_angle_lowerlimit = -550.0F;/* Variable: KfARBT_steer_req_strwhl_angle_lowerlimit
                                                             * Referenced by: '<S8>/Constant7'
                                                             * Lower limit for steer wheel angle output (in degrees)
                                                             */
real32_T KfARBT_steer_req_strwhl_angle_upperlimit = 550.0F;/* Variable: KfARBT_steer_req_strwhl_angle_upperlimit
                                                            * Referenced by: '<S8>/Constant6'
                                                            * Upper limit for steer wheel angle output (in degrees)
                                                            */
real32_T KfARBT_t_false_aeb_time_gap_thrsh = 50.0F;/* Variable: KfARBT_t_false_aeb_time_gap_thrsh
                                                    * Referenced by: '<S7>/Constant5'
                                                    * Time difference allowed for AEB to be triggered earlier than the start of driver hard braking

                                                      Unit in ms

                                                    */
real32_T KfARBT_t_hard_brake_debounce_time = 5.0F;/* Variable: KfARBT_t_hard_brake_debounce_time
                                                   * Referenced by: '<S7>/Constant2'
                                                   * Unit in ms. The debounce time to enter hard braking state
                                                   */
real32_T KfARBT_t_hard_brake_time_out = 5.0F;/* Variable: KfARBT_t_hard_brake_time_out
                                              * Referenced by: '<S7>/Constant3'
                                              * Unit in second, time out for hard braking state
                                              */
real32_T KfARBT_t_missed_aeb_time_gap_thrsh = 50.0F;/* Variable: KfARBT_t_missed_aeb_time_gap_thrsh
                                                     * Referenced by: '<S7>/Constant4'
                                                     * Time difference allowed for AEB to be triggered later than the start of driver hard braking

                                                       Unit in ms


                                                     */
real32_T KfARBT_t_speed_debounce_time = 10.0F;/* Variable: KfARBT_t_speed_debounce_time
                                               * Referenced by: '<S10>/Constant2'
                                               */
real32_T KfARBT_v_moving_speed_thrsh = 0.1F;/* Variable: KfARBT_v_moving_speed_thrsh
                                             * Referenced by: '<S10>/Constant'
                                             */
real32_T KfARBT_v_standstill_speed_thrsh = 0.1F;/* Variable: KfARBT_v_standstill_speed_thrsh
                                                 * Referenced by: '<S10>/Constant1'
                                                 */
uint8_T KbARBT_power_req_mode_man_ctrl_temp = 0U;/* Variable: KbARBT_power_req_mode_man_ctrl_temp
                                                  * Referenced by: '<S6>/Constant2'
                                                  */
boolean_T KbARBT_SLEW_autohold_active = 0;/* Variable: KbARBT_SLEW_autohold_active
                                           * Referenced by: '<S3>/Constant'
                                           */
boolean_T KbARBT_SLEW_gear_ctrl_accel_req = 0;/* Variable: KbARBT_SLEW_gear_ctrl_accel_req
                                               * Referenced by: '<S3>/Constant2'
                                               */
boolean_T KbARBT_gear_pos_fedbck_valid = 1;/* Variable: KbARBT_gear_pos_fedbck_valid
                                            * Referenced by: '<S11>/Constant2'
                                            * Validity flag of gear position feedback signal.

                                              For project vehicle without gear position feedback, this calibration shall be set to 0
                                            */
#pragma section

/* Block signals (auto storage) */
B_ARBT_subsystem_integrated_T ARBT_subsystem_integrated_B;

/* Block states (auto storage) */
DW_ARBT_subsystem_integrated_T ARBT_subsystem_integrated_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_ARBT_subsystem_integrate_T ARBT_subsystem_integrated_U;

/* Forward declaration for local functions */
static void ARBT_subsystem__AutoDriveActive(const boolean_T *LogicalOperator1,
  const boolean_T *LogicalOperator);

/* Function for Chart: '<S12>/stop_and_go_control_states' */
static void ARBT_subsystem__AutoDriveActive(const boolean_T *LogicalOperator1,
  const boolean_T *LogicalOperator)
{
  /* Inport: '<Root>/COMM_DataBus' */
  if (((int32_T)VsCOMM_JAC_Bus_FedBck_Data.FedBck_Drivemod.VCU_ICPV_ATOModFb) ==
      0)
  {
    ARBT_subsystem_integrated_DW.is_Act_Gear_D = ARBT_subsyst_IN_NO_ACTIVE_CHILD;
    ARBT_subsystem_integrated_DW.is_AutoDriveActive =
      ARBT_subsyst_IN_NO_ACTIVE_CHILD;
    ARBT_subsystem_integrated_DW.is_Act_Gear_P_or_N =
      ARBT_subsyst_IN_NO_ACTIVE_CHILD;
    ARBT_subsystem_integrated_DW.is_c46_ARBT_subsystem_integrate =
      ARBT_subsy_IN_AutoDriveInactive;
    VbARBT_auto_hold_req = false;
    VfARBT_gear_pos_req =
      VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos;
    VfARBT_gear_ctrl_state = 0U;
  }
  else
  {
    switch (ARBT_subsystem_integrated_DW.is_AutoDriveActive)
    {
     case ARBT_subsystem_in_IN_Act_Gear_D:
      /* Constant: '<S3>/Constant1' */
      if ((((int32_T)
            VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos) == 14)
          || (((int32_T)
               VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos) ==
              0))
      {
        ARBT_subsystem_integrated_DW.is_Act_Gear_D =
          ARBT_subsyst_IN_NO_ACTIVE_CHILD;
        ARBT_subsystem_integrated_DW.is_AutoDriveActive =
          ARBT_subsyst_IN_Act_Gear_P_or_N;
        ARBT_subsystem_integrated_DW.is_Act_Gear_P_or_N =
          ARBT_subsystem_int_IN_Init_m2h1;
        VbARBT_auto_hold_req = false;
        VfARBT_gear_pos_req =
          VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos;
        VfARBT_gear_ctrl_state = 2U;
      }
      else
      {
        switch (ARBT_subsystem_integrated_DW.is_Act_Gear_D)
        {
         case ARBT_subsystem_IN_Auto_hold_req:
          if ((*LogicalOperator) && (*LogicalOperator1))
          {
            ARBT_subsystem_integrated_DW.is_Act_Gear_D =
              ARBT_subsy_IN_Release_Auto_hold;
            VbARBT_auto_hold_req = false;
            VfARBT_gear_pos_req = 1U;
            VfARBT_gear_ctrl_state = 7U;
          }
          else
          {
            if (((real32_T)ARBT_subsystem_integrated_DW.temporalCounter_i1_g1ht)
                >= (KfARBT_autohold_timeout * 100.0F))
            {
              ARBT_subsystem_integrated_DW.is_Act_Gear_D =
                ARBT_subsystem_integ_IN_Go_to_P;
              VbARBT_auto_hold_req = true;
              VfARBT_gear_pos_req = 14U;
              VfARBT_gear_ctrl_state = 8U;
            }
          }
          break;

         case ARBT_subsystem_integ_IN_Go_to_P:
          if ((*LogicalOperator) && (*LogicalOperator1))
          {
            ARBT_subsystem_integrated_DW.is_Act_Gear_D =
              ARBT_subsy_IN_Release_Auto_hold;
            VbARBT_auto_hold_req = false;
            VfARBT_gear_pos_req = 1U;
            VfARBT_gear_ctrl_state = 7U;
          }
          break;

         case ARBT_subsystem_int_IN_Init_m2h1:
          if (VbARBT_vehicle_standstill)
          {
            ARBT_subsystem_integrated_DW.is_Act_Gear_D =
              ARBT_subsystem_IN_Auto_hold_req;
            ARBT_subsystem_integrated_DW.temporalCounter_i1_g1ht = 0U;
            VbARBT_auto_hold_req = true;
            VfARBT_gear_pos_req = 1U;
            VfARBT_gear_ctrl_state = 6U;
          }
          else
          {
            if (!VbARBT_vehicle_standstill)
            {
              ARBT_subsystem_integrated_DW.is_Act_Gear_D =
                ARBT_subsy_IN_Release_Auto_hold;
              VbARBT_auto_hold_req = false;
              VfARBT_gear_pos_req = 1U;
              VfARBT_gear_ctrl_state = 7U;
            }
          }
          break;

         default:
          if ((!(*LogicalOperator)) && VbARBT_vehicle_standstill)
          {
            ARBT_subsystem_integrated_DW.is_Act_Gear_D =
              ARBT_subsystem_IN_Auto_hold_req;
            ARBT_subsystem_integrated_DW.temporalCounter_i1_g1ht = 0U;
            VbARBT_auto_hold_req = true;
            VfARBT_gear_pos_req = 1U;
            VfARBT_gear_ctrl_state = 6U;
          }
          break;
        }
      }

      /* End of Constant: '<S3>/Constant1' */
      break;

     case ARBT_subsyst_IN_Act_Gear_P_or_N:
      switch (VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos)
      {
       case 1:
        ARBT_subsystem_integrated_DW.is_Act_Gear_P_or_N =
          ARBT_subsyst_IN_NO_ACTIVE_CHILD;
        ARBT_subsystem_integrated_DW.is_AutoDriveActive =
          ARBT_subsystem_in_IN_Act_Gear_D;
        ARBT_subsystem_integrated_DW.is_Act_Gear_D =
          ARBT_subsystem_int_IN_Init_m2h1;
        VfARBT_gear_pos_req = 1U;
        VfARBT_gear_ctrl_state = 5U;
        break;

       case 13:
        ARBT_subsystem_integrated_DW.is_Act_Gear_P_or_N =
          ARBT_subsyst_IN_NO_ACTIVE_CHILD;
        ARBT_subsystem_integrated_DW.is_AutoDriveActive =
          ARBT_subsystem_in_IN_Act_Gear_R;
        VbARBT_auto_hold_req = false;
        VfARBT_gear_pos_req = 14U;
        VfARBT_gear_ctrl_state = 9U;
        break;

       default:
        switch (ARBT_subsystem_integrated_DW.is_Act_Gear_P_or_N)
        {
         case ARBT_subsyste_IN_Auto_Drive_Req:
          if (*LogicalOperator1)
          {
            ARBT_subsystem_integrated_DW.is_Act_Gear_P_or_N =
              ARBT_subsystem_integ_IN_Go_to_D;
            VbARBT_auto_hold_req = true;
            VfARBT_gear_pos_req = 1U;
            VfARBT_gear_ctrl_state = 4U;
          }
          else
          {
            VbARBT_auto_hold_req = true;
            VfARBT_gear_pos_req =
              VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos;
            VfARBT_gear_ctrl_state = 3U;
          }
          break;

         case ARBT_subsystem_integ_IN_Go_to_D:
          break;

         default:
          if (*LogicalOperator)
          {
            ARBT_subsystem_integrated_DW.is_Act_Gear_P_or_N =
              ARBT_subsyste_IN_Auto_Drive_Req;
            VbARBT_auto_hold_req = true;
            VfARBT_gear_pos_req =
              VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos;
            VfARBT_gear_ctrl_state = 3U;
          }
          else
          {
            VbARBT_auto_hold_req = false;
            VfARBT_gear_pos_req =
              VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos;
            VfARBT_gear_ctrl_state = 2U;
          }
          break;
        }
        break;
      }
      break;

     case ARBT_subsystem_in_IN_Act_Gear_R:
      if ((((int32_T)
            VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos) == 14)
          || (((int32_T)
               VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos) ==
              0))
      {
        ARBT_subsystem_integrated_DW.is_AutoDriveActive =
          ARBT_subsyst_IN_Act_Gear_P_or_N;
        ARBT_subsystem_integrated_DW.is_Act_Gear_P_or_N =
          ARBT_subsystem_int_IN_Init_m2h1;
        VbARBT_auto_hold_req = false;
        VfARBT_gear_pos_req =
          VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos;
        VfARBT_gear_ctrl_state = 2U;
      }
      else
      {
        if (((int32_T)
             VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos) == 1)
        {
          ARBT_subsystem_integrated_DW.is_AutoDriveActive =
            ARBT_subsystem_in_IN_Act_Gear_D;
          ARBT_subsystem_integrated_DW.is_Act_Gear_D =
            ARBT_subsystem_int_IN_Init_m2h1;
          VfARBT_gear_pos_req = 1U;
          VfARBT_gear_ctrl_state = 5U;
        }
      }
      break;

     default:
      if (((int32_T)
           VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos) == 1)
      {
        ARBT_subsystem_integrated_DW.is_AutoDriveActive =
          ARBT_subsystem_in_IN_Act_Gear_D;
        ARBT_subsystem_integrated_DW.is_Act_Gear_D =
          ARBT_subsystem_int_IN_Init_m2h1;
        VfARBT_gear_pos_req = 1U;
        VfARBT_gear_ctrl_state = 5U;
      }
      else if ((((int32_T)
                 VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos) ==
                14) || (((int32_T)
                         VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos)
                        == 0))
      {
        ARBT_subsystem_integrated_DW.is_AutoDriveActive =
          ARBT_subsyst_IN_Act_Gear_P_or_N;
        ARBT_subsystem_integrated_DW.is_Act_Gear_P_or_N =
          ARBT_subsystem_int_IN_Init_m2h1;
        VbARBT_auto_hold_req = false;
        VfARBT_gear_pos_req =
          VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos;
        VfARBT_gear_ctrl_state = 2U;
      }
      else if (((int32_T)
                VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos) ==
               13)
      {
        ARBT_subsystem_integrated_DW.is_AutoDriveActive =
          ARBT_subsystem_in_IN_Act_Gear_R;
        VbARBT_auto_hold_req = false;
        VfARBT_gear_pos_req = 14U;
        VfARBT_gear_ctrl_state = 9U;
      }
      else
      {
        VbARBT_auto_hold_req = false;
        VfARBT_gear_pos_req =
          VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos;
        VfARBT_gear_ctrl_state = 1U;
      }
      break;
    }
  }

  /* End of Inport: '<Root>/COMM_DataBus' */
}

/* Model step function */
void ARBT_subsystem_integrated_step(void)
{
  int32_T rtb_vehicle_standstill;
  uint8_T rtb_Switch1;
  boolean_T LogicalOperator1;
  boolean_T LogicalOperator;

  /* Outputs for Atomic SubSystem: '<Root>/ARBTIntegrated' */

  /* Outputs for Atomic SubSystem: '<S1>/BrakeArbitration' */
  ARBT_subsystem_BrakeArbitration();

  /* End of Outputs for SubSystem: '<S1>/BrakeArbitration' */

  /* Outputs for Atomic SubSystem: '<S1>/PowerArbitration' */
  ARBT_subsystem_PowerArbitration();

  /* End of Outputs for SubSystem: '<S1>/PowerArbitration' */

  /* Outputs for Atomic SubSystem: '<S1>/AccessoryArbitration' */
  /* Logic: '<S11>/Logical Operator3' incorporates:
   *  DataTypeConversion: '<S11>/Data Type Conversion'
   *  Inport: '<Root>/COMM_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   */
  VbARBT_EPB_ctrl_enbl_to_comm = ((((int32_T)
    VsCOMM_JAC_Bus_FedBck_Data.FedBck_Drivemod.VCU_ICPV_ATOModFb) != 0) &&
    (VsDCSN_DataBus.EnablingFlags_Group.epb_ctrl_enable));

  /* Logic: '<S3>/Logical Operator1' incorporates:
   *  Constant: '<S3>/Constant'
   *  Inport: '<Root>/COMM_DataBus'
   */
  LogicalOperator1 = ((((int32_T)
                        VsCOMM_JAC_Bus_FedBck_Data.FedBck_Brake.PresHoldFish) !=
                       0) || KbARBT_SLEW_autohold_active);

  /* Chart: '<S10>/VehicleStandstillStateEst' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/Constant2'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (((uint32_T)ARBT_subsystem_integrated_DW.temporalCounter_i1_lasi) < 65535U)
  {
    ARBT_subsystem_integrated_DW.temporalCounter_i1_lasi = (uint16_T)((int32_T)
      (((int32_T)ARBT_subsystem_integrated_DW.temporalCounter_i1_lasi) + 1));
  }

  if (((uint32_T)ARBT_subsystem_integrated_DW.is_active_c48_ARBT_subsystem_in) ==
      0U)
  {
    ARBT_subsystem_integrated_DW.is_active_c48_ARBT_subsystem_in = 1U;
    ARBT_subsystem_integrated_DW.is_c48_ARBT_subsystem_integrate =
      ARBT_subsystem_integrat_IN_Stop;
    rtb_vehicle_standstill = 1;
  }
  else
  {
    switch (ARBT_subsystem_integrated_DW.is_c48_ARBT_subsystem_integrate)
    {
     case ARBT_subsystem_integr_IN_Moving:
      rtb_vehicle_standstill = 0;
      if (VsEGMO_DataBus.motion.linear_velocity <
          KfARBT_v_standstill_speed_thrsh)
      {
        ARBT_subsystem_integrated_DW.is_c48_ARBT_subsystem_integrate =
          ARBT_subsystem_integrat_IN_Stop;
        rtb_vehicle_standstill = 1;
      }
      break;

     case ARBT_subsystem__IN_Moving_delay:
      rtb_vehicle_standstill = 1;
      if (ARBT_subsystem_integrated_DW.temporalCounter_i1_lasi >= ((uint16_T)
           KfARBT_t_speed_debounce_time))
      {
        ARBT_subsystem_integrated_DW.is_c48_ARBT_subsystem_integrate =
          ARBT_subsystem_integr_IN_Moving;
        rtb_vehicle_standstill = 0;
      }
      else
      {
        if (VsEGMO_DataBus.motion.linear_velocity <
            KfARBT_v_standstill_speed_thrsh)
        {
          ARBT_subsystem_integrated_DW.is_c48_ARBT_subsystem_integrate =
            ARBT_subsystem_integrat_IN_Stop;
        }
      }
      break;

     default:
      rtb_vehicle_standstill = 1;
      if (VsEGMO_DataBus.motion.linear_velocity > KfARBT_v_moving_speed_thrsh)
      {
        ARBT_subsystem_integrated_DW.is_c48_ARBT_subsystem_integrate =
          ARBT_subsystem__IN_Moving_delay;
        ARBT_subsystem_integrated_DW.temporalCounter_i1_lasi = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S10>/VehicleStandstillStateEst' */

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  VbARBT_vehicle_standstill = (rtb_vehicle_standstill != 0);

  /* Logic: '<S3>/Logical Operator' incorporates:
   *  Constant: '<S3>/Constant2'
   */
  LogicalOperator =
    ((ARBT_subsystem_integrated_B.PowerGroup.power_ctrl_enbl_to_comm) ||
     KbARBT_SLEW_gear_ctrl_accel_req);

  /* Chart: '<S12>/stop_and_go_control_states' incorporates:
   *  Inport: '<Root>/COMM_DataBus'
   */
  if (ARBT_subsystem_integrated_DW.temporalCounter_i1_g1ht < MAX_uint32_T)
  {
    ARBT_subsystem_integrated_DW.temporalCounter_i1_g1ht++;
  }

  if (((uint32_T)ARBT_subsystem_integrated_DW.is_active_c46_ARBT_subsystem_in) ==
      0U)
  {
    ARBT_subsystem_integrated_DW.is_active_c46_ARBT_subsystem_in = 1U;
    ARBT_subsystem_integrated_DW.is_c46_ARBT_subsystem_integrate =
      ARBT_subsy_IN_AutoDriveInactive;
    VbARBT_auto_hold_req = false;
    VfARBT_gear_pos_req =
      VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos;
    VfARBT_gear_ctrl_state = 0U;
  }
  else if (((uint32_T)
            ARBT_subsystem_integrated_DW.is_c46_ARBT_subsystem_integrate) ==
           ARBT_subsyst_IN_AutoDriveActive)
  {
    ARBT_subsystem__AutoDriveActive(&LogicalOperator1, &LogicalOperator);
  }
  else if (((int32_T)
            VsCOMM_JAC_Bus_FedBck_Data.FedBck_Drivemod.VCU_ICPV_ATOModFb) == 1)
  {
    ARBT_subsystem_integrated_DW.is_c46_ARBT_subsystem_integrate =
      ARBT_subsyst_IN_AutoDriveActive;
    ARBT_subsystem_integrated_DW.is_AutoDriveActive =
      ARBT_subsystem_integrat_IN_Init;
    VbARBT_auto_hold_req = false;
    VfARBT_gear_pos_req =
      VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos;
    VfARBT_gear_ctrl_state = 1U;
  }
  else
  {
    VbARBT_auto_hold_req = false;
    VfARBT_gear_pos_req =
      VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos;
    VfARBT_gear_ctrl_state = 0U;
  }

  /* End of Chart: '<S12>/stop_and_go_control_states' */

  /* Switch: '<S11>/Switch1' incorporates:
   *  Constant: '<S11>/Constant2'
   *  Inport: '<Root>/COMM_DataBus'
   */
  if (KbARBT_gear_pos_fedbck_valid)
  {
    rtb_Switch1 = VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos;
  }
  else
  {
    rtb_Switch1 = VfARBT_gear_pos_req;
  }

  /* End of Switch: '<S11>/Switch1' */

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  Logic: '<S11>/Logical Operator1'
   *  Logic: '<S11>/Logical Operator2'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S18>/Compare'
   */
  if (((rtb_Switch1 == ((uint8_T)14U)) || (rtb_Switch1 == ((uint8_T)0U))) &&
      VbARBT_vehicle_standstill)
  {
    VbARBT_EPB_switch_request = true;
  }
  else
  {
    VbARBT_EPB_switch_request = false;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Chart: '<S11>/Acceleration_Estimation' incorporates:
   *  Constant: '<S16>/Constant'
   *  Inport: '<Root>/COMM_DataBus'
   *  Logic: '<S11>/Logical Operator'
   *  RelationalOperator: '<S16>/Compare'
   */
  if (((uint32_T)ARBT_subsystem_integrated_DW.is_active_c6_ARBT_subsystem_int) ==
      0U)
  {
    ARBT_subsystem_integrated_DW.is_active_c6_ARBT_subsystem_int = 1U;
    ARBT_subsystem_integrated_DW.is_c6_ARBT_subsystem_integrated =
      ARBT_subsystem_inte_IN_Released;
    VbARBT_EPB_ctrl_mode = 0U;
  }
  else
  {
    switch (ARBT_subsystem_integrated_DW.is_c6_ARBT_subsystem_integrated)
    {
     case ARBT_subsystem_integ_IN_Clamped:
      VbARBT_EPB_ctrl_mode = 1U;
      if (((ARBT_subsystem_integrated_B.PowerGroup.power_ctrl_enbl_to_comm) &&
           (((int32_T)
             VsCOMM_JAC_Bus_FedBck_Data.FedBck_Drivemod.VCU_ICPV_ATOModFb) != 0))
          && (VsCOMM_JAC_Bus_FedBck_Data.FedBck_Gear.VCU_ICPV_VCUGearLevPos ==
              ((uint8_T)1U)))
      {
        ARBT_subsystem_integrated_DW.is_c6_ARBT_subsystem_integrated =
          ARBT_subsystem_int_IN_Releasing;
        VbARBT_EPB_ctrl_mode = 2U;
      }
      break;

     case ARBT_subsystem_inte_IN_Released:
      VbARBT_EPB_ctrl_mode = 0U;
      if (((int32_T)VsCOMM_JAC_Bus_FedBck_Data.FedBck_EPB.VCU_ICPV_EPBSysVCU) >
          0)
      {
        ARBT_subsystem_integrated_DW.is_c6_ARBT_subsystem_integrated =
          ARBT_subsystem_integ_IN_Clamped;
        VbARBT_EPB_ctrl_mode = 1U;
      }
      break;

     default:
      VbARBT_EPB_ctrl_mode = 2U;
      if (((int32_T)VsCOMM_JAC_Bus_FedBck_Data.FedBck_EPB.VCU_ICPV_EPBSysVCU) ==
          0)
      {
        ARBT_subsystem_integrated_DW.is_c6_ARBT_subsystem_integrated =
          ARBT_subsystem_inte_IN_Released;
        VbARBT_EPB_ctrl_mode = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S11>/Acceleration_Estimation' */

  /* Logic: '<S12>/Logical Operator' incorporates:
   *  Inport: '<Root>/COMM_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   */
  VbARBT_gear_ctrl_enbl_to_comm =
    ((VsDCSN_DataBus.EnablingFlags_Group.gear_ctrl_enable) && (((int32_T)
       VsCOMM_JAC_Bus_FedBck_Data.FedBck_Drivemod.VCU_ICPV_ATOModFb) != 0));

  /* BusCreator: '<S3>/Bus Creator' incorporates:
   *  Constant: '<S3>/Constant3'
   */
  VsARBT_DataBus.AccessoryGroup.epb_ctrl_enbl_to_comm =
    VbARBT_EPB_ctrl_enbl_to_comm;
  VsARBT_DataBus.AccessoryGroup.epb_switch_request = VbARBT_EPB_switch_request;
  VsARBT_DataBus.AccessoryGroup.epb_control_mode = VbARBT_EPB_ctrl_mode;
  VsARBT_DataBus.AccessoryGroup.gear_ctrl_enbl_to_comm =
    VbARBT_gear_ctrl_enbl_to_comm;
  VsARBT_DataBus.AccessoryGroup.gear_ctrl_req = VfARBT_gear_pos_req;
  VsARBT_DataBus.AccessoryGroup.auto_hold_req = VbARBT_auto_hold_req;
  VsARBT_DataBus.AccessoryGroup.horn_ctrl_req = false;

  /* End of Outputs for SubSystem: '<S1>/AccessoryArbitration' */

  /* Outputs for Atomic SubSystem: '<S1>/SteerArbitration' */
  ARBT_subsystem_SteerArbitration();

  /* End of Outputs for SubSystem: '<S1>/SteerArbitration' */

  /* Outputs for Atomic SubSystem: '<S1>/RecordTriggerArbitration' */
  /* Logic: '<S7>/Logical Operator1' incorporates:
   *  Constant: '<S24>/Constant'
   *  Inport: '<Root>/COMM_DataBus'
   *  RelationalOperator: '<S24>/Compare'
   */
  LogicalOperator1 = (((((int32_T)
    VsCOMM_JAC_Bus_FedBck_Data.FedBck_Brake.VCU_ICPV_BrkPelSta) != 0) ||
                       (((int32_T)
    VsCOMM_JAC_Bus_FedBck_Data.FedBck_Light.VCU_IPCV_BrkLgtSts) != 0)) ||
                      (VsCOMM_JAC_Bus_FedBck_Data.FedBck_Brake.VUC_ICPV_BrkPed >
                       0.0F));

  /* Chart: '<S7>/DtrmnDriverHardBrake' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Inport: '<Root>/COMM_DataBus'
   *  Inport: '<Root>/EGMO_DataBus'
   */
  if (ARBT_subsystem_integrated_DW.temporalCounter_i1_ia33 < MAX_uint32_T)
  {
    ARBT_subsystem_integrated_DW.temporalCounter_i1_ia33++;
  }

  if (((uint32_T)ARBT_subsystem_integrated_DW.is_active_c1_ARBT_subsystem_int) ==
      0U)
  {
    ARBT_subsystem_integrated_DW.is_active_c1_ARBT_subsystem_int = 1U;
    ARBT_subsystem_integrated_DW.is_c1_ARBT_subsystem_integrated =
      ARBT_subsyste_IN_NORMAL_DRIVING;
  }
  else
  {
    switch (ARBT_subsystem_integrated_DW.is_c1_ARBT_subsystem_integrated)
    {
     case ARBT_sub_IN_DRIVER_HARD_BRAKING:
      if (((real32_T)ARBT_subsystem_integrated_DW.temporalCounter_i1_ia33) >=
          (KfARBT_t_hard_brake_time_out * 100.0F))
      {
        ARBT_subsystem_integrated_DW.is_c1_ARBT_subsystem_integrated =
          ARBT_subsyste_IN_NORMAL_DRIVING;
      }
      else if (((!LogicalOperator1) ||
                (VsCOMM_JAC_Bus_FedBck_Data.FedBck_Brake.VUC_ICPV_BrkPed <
                 KfARBT_brk_ped_pos_thrsh_rec_trig)) ||
               (VsEGMO_DataBus.motion.acceleration_rel.x >
                KfARBT_lon_a_thrsh_rec_trig))
      {
        ARBT_subsystem_integrated_DW.is_c1_ARBT_subsystem_integrated =
          ARBT_subsyste_IN_NORMAL_DRIVING;
      }
      else
      {
        VbARBT_driver_hard_brake_flag = true;
      }
      break;

     case ARBT_subsyste_IN_NORMAL_DRIVING:
      if ((LogicalOperator1 &&
           (VsCOMM_JAC_Bus_FedBck_Data.FedBck_Brake.VUC_ICPV_BrkPed >=
            KfARBT_brk_ped_pos_thrsh_rec_trig)) &&
          (VsEGMO_DataBus.motion.acceleration_rel.x <=
           KfARBT_lon_a_thrsh_rec_trig))
      {
        ARBT_subsystem_integrated_DW.is_c1_ARBT_subsystem_integrated =
          ARBT__IN_POTENTIAL_HARD_BRAKING;
        ARBT_subsystem_integrated_DW.temporalCounter_i1_ia33 = 0U;
      }
      else
      {
        VbARBT_driver_hard_brake_flag = false;
      }
      break;

     default:
      if (((real32_T)((uint32_T)
                      (ARBT_subsystem_integrated_DW.temporalCounter_i1_ia33 *
                       10U))) >= KfARBT_t_hard_brake_debounce_time)
      {
        ARBT_subsystem_integrated_DW.is_c1_ARBT_subsystem_integrated =
          ARBT_sub_IN_DRIVER_HARD_BRAKING;
        ARBT_subsystem_integrated_DW.temporalCounter_i1_ia33 = 0U;
      }
      else if (((!LogicalOperator1) ||
                (VsCOMM_JAC_Bus_FedBck_Data.FedBck_Brake.VUC_ICPV_BrkPed <
                 KfARBT_brk_ped_pos_thrsh_rec_trig)) ||
               (VsEGMO_DataBus.motion.acceleration_rel.x >
                KfARBT_lon_a_thrsh_rec_trig))
      {
        ARBT_subsystem_integrated_DW.is_c1_ARBT_subsystem_integrated =
          ARBT_subsyste_IN_NORMAL_DRIVING;
      }
      else
      {
        VbARBT_driver_hard_brake_flag = false;
      }
      break;
    }
  }

  /* End of Chart: '<S7>/DtrmnDriverHardBrake' */

  /* Logic: '<S7>/Logical Operator' incorporates:
   *  Inport: '<Root>/AEBS_DataBus'
   *  Inport: '<Root>/DCSN_DataBus'
   */
  VbARBT_aeb_triggered_flag =
    ((VsDCSN_DataBus.EnablingFlags_Group.aeb_feature_enable) &&
     (VsAEBS_DataBus.AEB_Data.AEB_acceleration_req != 0.0F));

  /* Chart: '<S7>/DtrmnRecTrigger' incorporates:
   *  Constant: '<S7>/Constant4'
   *  Constant: '<S7>/Constant5'
   */
  if (ARBT_subsystem_integrated_DW.temporalCounter_i1 < MAX_uint32_T)
  {
    ARBT_subsystem_integrated_DW.temporalCounter_i1++;
  }

  if (((uint32_T)ARBT_subsystem_integrated_DW.is_active_c2_ARBT_subsystem_int) ==
      0U)
  {
    ARBT_subsystem_integrated_DW.is_active_c2_ARBT_subsystem_int = 1U;
    ARBT_subsystem_integrated_DW.is_c2_ARBT_subsystem_integrated =
      ARBT_sub_IN_NORMAL_DRIVING_e10u;
  }
  else
  {
    switch (ARBT_subsystem_integrated_DW.is_c2_ARBT_subsystem_integrated)
    {
     case ARBT_subsyst_IN_FALSE_AEB_EVENT:
      if (VbARBT_driver_hard_brake_flag == VbARBT_aeb_triggered_flag)
      {
        ARBT_subsystem_integrated_DW.is_c2_ARBT_subsystem_integrated =
          ARBT_sub_IN_NORMAL_DRIVING_e10u;
      }
      else
      {
        VbARBT_missed_aeb_flag = false;
        VbARBT_false_aeb_flag = true;
      }
      break;

     case ARBT_subsys_IN_MISSED_AEB_EVENT:
      if (VbARBT_driver_hard_brake_flag == VbARBT_aeb_triggered_flag)
      {
        ARBT_subsystem_integrated_DW.is_c2_ARBT_subsystem_integrated =
          ARBT_sub_IN_NORMAL_DRIVING_e10u;
      }
      else
      {
        VbARBT_missed_aeb_flag = true;
        VbARBT_false_aeb_flag = false;
      }
      break;

     case ARBT_sub_IN_NORMAL_DRIVING_e10u:
      if ((!VbARBT_driver_hard_brake_flag) && VbARBT_aeb_triggered_flag)
      {
        ARBT_subsystem_integrated_DW.is_c2_ARBT_subsystem_integrated =
          ARBT_subsyst_IN_POTENTIAL_FALSE;
        ARBT_subsystem_integrated_DW.temporalCounter_i1 = 0U;
      }
      else if (VbARBT_driver_hard_brake_flag && (!VbARBT_aeb_triggered_flag))
      {
        ARBT_subsystem_integrated_DW.is_c2_ARBT_subsystem_integrated =
          ARBT_subsyste_IN_POTENTIAL_MISS;
        ARBT_subsystem_integrated_DW.temporalCounter_i1 = 0U;
      }
      else
      {
        VbARBT_missed_aeb_flag = false;
        VbARBT_false_aeb_flag = false;
      }
      break;

     case ARBT_subsyst_IN_POTENTIAL_FALSE:
      if (((real32_T)((uint32_T)(ARBT_subsystem_integrated_DW.temporalCounter_i1
             * 10U))) >= KfARBT_t_missed_aeb_time_gap_thrsh)
      {
        ARBT_subsystem_integrated_DW.is_c2_ARBT_subsystem_integrated =
          ARBT_subsyst_IN_FALSE_AEB_EVENT;
      }
      else if (VbARBT_driver_hard_brake_flag == VbARBT_aeb_triggered_flag)
      {
        ARBT_subsystem_integrated_DW.is_c2_ARBT_subsystem_integrated =
          ARBT_sub_IN_NORMAL_DRIVING_e10u;
      }
      else
      {
        VbARBT_missed_aeb_flag = false;
        VbARBT_false_aeb_flag = false;
      }
      break;

     default:
      if (((real32_T)((uint32_T)(ARBT_subsystem_integrated_DW.temporalCounter_i1
             * 10U))) >= KfARBT_t_false_aeb_time_gap_thrsh)
      {
        ARBT_subsystem_integrated_DW.is_c2_ARBT_subsystem_integrated =
          ARBT_subsys_IN_MISSED_AEB_EVENT;
      }
      else if (VbARBT_driver_hard_brake_flag == VbARBT_aeb_triggered_flag)
      {
        ARBT_subsystem_integrated_DW.is_c2_ARBT_subsystem_integrated =
          ARBT_sub_IN_NORMAL_DRIVING_e10u;
      }
      else
      {
        VbARBT_missed_aeb_flag = false;
        VbARBT_false_aeb_flag = false;
      }
      break;
    }
  }

  /* End of Chart: '<S7>/DtrmnRecTrigger' */

  /* BusCreator: '<S25>/Bus Creator' */
  VsARBT_DataBus.RecTrigFlagGroup.missed_aeb_flag = VbARBT_missed_aeb_flag;
  VsARBT_DataBus.RecTrigFlagGroup.false_aeb_flag = VbARBT_false_aeb_flag;
  VsARBT_DataBus.RecTrigFlagGroup.driver_hard_braking_flag =
    VbARBT_driver_hard_brake_flag;
  VsARBT_DataBus.RecTrigFlagGroup.aeb_triggered_flag = VbARBT_aeb_triggered_flag;

  /* End of Outputs for SubSystem: '<S1>/RecordTriggerArbitration' */

  /* Outputs for Atomic SubSystem: '<S1>/WarningArbitration' */
  ARBT_subsyst_WarningArbitration();

  /* End of Outputs for SubSystem: '<S1>/WarningArbitration' */

  /* BusCreator: '<S5>/Bus Creator' */
  VsARBT_DataBus.BrakeGroup = ARBT_subsystem_integrated_B.BrakeGroup;
  VsARBT_DataBus.PowerGroup = ARBT_subsystem_integrated_B.PowerGroup;

  /* End of Outputs for SubSystem: '<Root>/ARBTIntegrated' */
}

/* Model initialize function */
void ARBT_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &ARBT_subsystem_integrated_B), 0,
                sizeof(B_ARBT_subsystem_integrated_T));

  /* exported global signals */
  VsARBT_DataBus = ARBT_subsystem_integrated_rtZARBT_DataBus;
  VfARBT_steer_req_strwhl_angle = 0.0F;
  VfARBT_steer_req_strwhl_angle_raw = 0.0F;
  VfARBT_steer_req_strwhl_torque = 0.0F;
  VfARBT_power_req_lon_a_raw = 0.0F;
  VfARBT_power_req_lon_a = 0.0F;
  VfARBT_power_req_torque = 0.0F;
  VfARBT_brake_req_lon_a_raw = 0.0F;
  VfARBT_brake_req_lon_a = 0.0F;
  VfARBT_steer_req_mode = ((uint8_T)0U);
  VfARBT_power_req_mode = 0U;
  VfARBT_gear_pos_req = 0U;
  VfARBT_gear_ctrl_state = 0U;
  VbARBT_EPB_ctrl_mode = 0U;
  VbARBT_FCW_level_three = false;
  VbARBT_FCW_level_one = false;
  VbARBT_FCW_level_two = false;
  VbARBT_LDW_left = false;
  VbARBT_BSD_left_low_raw = false;
  VbARBT_BSD_right_low_raw = false;
  VbARBT_LCA_left_low_raw = false;
  VbARBT_LCA_right_low_raw = false;
  VbARBT_warn_lcw_left_req = false;
  VbARBT_LDW_right = false;
  VbARBT_BSD_left_high_raw = false;
  VbARBT_LCA_left_high_raw = false;
  VbARBT_BSD_right_high_raw = false;
  VbARBT_LCA_right_high_raw = false;
  VbARBT_FCW_level_four = false;
  VbARBT_FCW_level_five = false;
  VbARBT_warn_lcw_right_req = false;
  VbARBT_steer_ctrl_enbl_to_comm = false;
  VbARBT_aeb_triggered_flag = false;
  VbARBT_missed_aeb_flag = false;
  VbARBT_false_aeb_flag = false;
  VbARBT_driver_hard_brake_flag = false;
  VbARBT_power_ctrl_enbl_to_comm = false;
  VbARBT_brake_ctrl_enbl_to_comm = false;
  VbARBT_EPB_ctrl_enbl_to_comm = false;
  VbARBT_vehicle_standstill = false;
  VbARBT_EPB_switch_request = false;
  VbARBT_gear_ctrl_enbl_to_comm = false;
  VbARBT_auto_hold_req = false;
  VeARBT_steer_arbt_winner = ARBT_NO_REQ;
  VeARBT_power_arbt_winner = ARBT_NO_REQ;
  VeARBT_brake_arbt_winner = ARBT_NO_REQ;

  /* states (dwork) */
  (void) memset((void *)&ARBT_subsystem_integrated_DW, 0,
                sizeof(DW_ARBT_subsystem_integrated_T));

  /* external inputs */
  ARBT_subsystem_integrated_U.VbHWIO_DriverModeComd = false;

  /* ConstCode for Atomic SubSystem: '<Root>/ARBTIntegrated' */

  /* ConstCode for Atomic SubSystem: '<S1>/SteerArbitration' */
  ARBT_sub_SteerArbitration_Const();

  /* End of ConstCode for SubSystem: '<S1>/SteerArbitration' */

  /* End of ConstCode for SubSystem: '<Root>/ARBTIntegrated' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/ARBTIntegrated' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/AccessoryArbitration' */
  /* SystemInitialize for Chart: '<S10>/VehicleStandstillStateEst' */
  ARBT_subsystem_integrated_DW.temporalCounter_i1_lasi = 0U;
  ARBT_subsystem_integrated_DW.is_active_c48_ARBT_subsystem_in = 0U;
  ARBT_subsystem_integrated_DW.is_c48_ARBT_subsystem_integrate =
    ARBT_subsyst_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S12>/stop_and_go_control_states' */
  ARBT_subsystem_integrated_DW.is_AutoDriveActive =
    ARBT_subsyst_IN_NO_ACTIVE_CHILD;
  ARBT_subsystem_integrated_DW.is_Act_Gear_D = ARBT_subsyst_IN_NO_ACTIVE_CHILD;
  ARBT_subsystem_integrated_DW.temporalCounter_i1_g1ht = 0U;
  ARBT_subsystem_integrated_DW.is_Act_Gear_P_or_N =
    ARBT_subsyst_IN_NO_ACTIVE_CHILD;
  ARBT_subsystem_integrated_DW.is_active_c46_ARBT_subsystem_in = 0U;
  ARBT_subsystem_integrated_DW.is_c46_ARBT_subsystem_integrate =
    ARBT_subsyst_IN_NO_ACTIVE_CHILD;
  VbARBT_auto_hold_req = false;
  VfARBT_gear_pos_req = 0U;
  VfARBT_gear_ctrl_state = 0U;

  /* SystemInitialize for Chart: '<S11>/Acceleration_Estimation' */
  ARBT_subsystem_integrated_DW.is_active_c6_ARBT_subsystem_int = 0U;
  ARBT_subsystem_integrated_DW.is_c6_ARBT_subsystem_integrated =
    ARBT_subsyst_IN_NO_ACTIVE_CHILD;

  /* End of SystemInitialize for SubSystem: '<S1>/AccessoryArbitration' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/RecordTriggerArbitration' */
  /* SystemInitialize for Chart: '<S7>/DtrmnDriverHardBrake' */
  ARBT_subsystem_integrated_DW.temporalCounter_i1_ia33 = 0U;
  ARBT_subsystem_integrated_DW.is_active_c1_ARBT_subsystem_int = 0U;
  ARBT_subsystem_integrated_DW.is_c1_ARBT_subsystem_integrated =
    ARBT_subsyst_IN_NO_ACTIVE_CHILD;

  /* SystemInitialize for Chart: '<S7>/DtrmnRecTrigger' */
  ARBT_subsystem_integrated_DW.temporalCounter_i1 = 0U;
  ARBT_subsystem_integrated_DW.is_active_c2_ARBT_subsystem_int = 0U;
  ARBT_subsystem_integrated_DW.is_c2_ARBT_subsystem_integrated =
    ARBT_subsyst_IN_NO_ACTIVE_CHILD;

  /* End of SystemInitialize for SubSystem: '<S1>/RecordTriggerArbitration' */
  /* End of SystemInitialize for SubSystem: '<Root>/ARBTIntegrated' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
