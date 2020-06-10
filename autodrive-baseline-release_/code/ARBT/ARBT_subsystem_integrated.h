/*
 * File: ARBT_subsystem_integrated.h
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

#ifndef RTW_HEADER_ARBT_subsystem_integrated_h_
#define RTW_HEADER_ARBT_subsystem_integrated_h_
#include <string.h>
#ifndef ARBT_subsystem_integrated_COMMON_INCLUDES_
# define ARBT_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ARBT_subsystem_integrated_COMMON_INCLUDES_ */

#include "ARBT_subsystem_integrated_types.h"

/* Child system includes */
#include "BrakeArbitration.h"
#include "PowerArbitration.h"
#include "SteerArbitration.h"
#include "WarningArbitration.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct
{
  ARBT_PowerGroup PowerGroup;          /* '<S6>/Bus Creator3' */
  ARBT_BrakeGroup BrakeGroup;          /* '<S4>/Bus Creator' */
}
B_ARBT_subsystem_integrated_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
  uint32_T temporalCounter_i1;         /* '<S7>/DtrmnRecTrigger' */
  uint32_T temporalCounter_i1_ia33;    /* '<S7>/DtrmnDriverHardBrake' */
  uint32_T temporalCounter_i1_g1ht;    /* '<S12>/stop_and_go_control_states' */
  uint16_T temporalCounter_i1_lasi;    /* '<S10>/VehicleStandstillStateEst' */
  uint8_T is_active_c2_ARBT_subsystem_int;/* '<S7>/DtrmnRecTrigger' */
  uint8_T is_c2_ARBT_subsystem_integrated;/* '<S7>/DtrmnRecTrigger' */
  uint8_T is_active_c1_ARBT_subsystem_int;/* '<S7>/DtrmnDriverHardBrake' */
  uint8_T is_c1_ARBT_subsystem_integrated;/* '<S7>/DtrmnDriverHardBrake' */
  uint8_T is_active_c46_ARBT_subsystem_in;/* '<S12>/stop_and_go_control_states' */
  uint8_T is_c46_ARBT_subsystem_integrate;/* '<S12>/stop_and_go_control_states' */
  uint8_T is_AutoDriveActive;          /* '<S12>/stop_and_go_control_states' */
  uint8_T is_Act_Gear_P_or_N;          /* '<S12>/stop_and_go_control_states' */
  uint8_T is_Act_Gear_D;               /* '<S12>/stop_and_go_control_states' */
  uint8_T is_active_c6_ARBT_subsystem_int;/* '<S11>/Acceleration_Estimation' */
  uint8_T is_c6_ARBT_subsystem_integrated;/* '<S11>/Acceleration_Estimation' */
  uint8_T is_active_c48_ARBT_subsystem_in;/* '<S10>/VehicleStandstillStateEst' */
  uint8_T is_c48_ARBT_subsystem_integrate;/* '<S10>/VehicleStandstillStateEst' */
}
DW_ARBT_subsystem_integrated_T;

/* External inputs (root inport signals with auto storage) */
typedef struct
{
  boolean_T VbHWIO_DriverModeComd;     /* '<Root>/HWIO_DriverCmd' */
}
ExtU_ARBT_subsystem_integrate_T;

/* Block signals (auto storage) */
extern B_ARBT_subsystem_integrated_T ARBT_subsystem_integrated_B;

/* Block states (auto storage) */
extern DW_ARBT_subsystem_integrated_T ARBT_subsystem_integrated_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_ARBT_subsystem_integrate_T ARBT_subsystem_integrated_U;

/* External data declarations for dependent source files */
extern const ARBT_DataBus ARBT_subsystem_integrated_rtZARBT_DataBus;/* ARBT_DataBus ground */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern ARBT_DataBus VsARBT_DataBus;    /* '<S5>/Bus Creator' */
extern real32_T VfARBT_steer_req_strwhl_angle;/* '<S29>/Switch2'
                                               * final steer angle req (as deg) after arbitration and saturation
                                               */
extern real32_T VfARBT_steer_req_strwhl_angle_raw;/* '<S8>/MATLAB Function'
                                                   * raw steer angle request after arbitration before saturation
                                                   */
extern real32_T VfARBT_steer_req_strwhl_torque;/* '<S8>/MATLAB Function' */
extern real32_T VfARBT_power_req_lon_a_raw;/* '<S6>/Switch2'
                                            * raw power request after arbitration before saturation
                                            */
extern real32_T VfARBT_power_req_lon_a;/* '<S22>/Switch2'
                                        * final power req (as m/s2) after arbitration and saturation
                                        */
extern real32_T VfARBT_power_req_torque;/* '<S6>/Switch1' */
extern real32_T VfARBT_brake_req_lon_a_raw;/* '<S4>/Switch4'
                                            * raw brake request after arbitration before saturation
                                            */
extern real32_T VfARBT_brake_req_lon_a;/* '<S21>/Switch2'
                                        * final brake req (as m/s2) after arbitration and saturation
                                        */
extern uint8_T VfARBT_steer_req_mode;  /* '<S8>/Constant'
                                        * 0 = acceleration mode
                                          1 = torque mode
                                        */
extern uint8_T VfARBT_power_req_mode;  /* '<S6>/Constant2'
                                        * 0 = steering wheel angle
                                          1 = steering wheel torque
                                        */
extern uint8_T VfARBT_gear_pos_req;    /* '<S12>/stop_and_go_control_states'
                                        * Gear Pos Definition
                                          0->N
                                          1->D
                                          13->R
                                          14->P
                                          15->Invalid
                                        */
extern uint8_T VfARBT_gear_ctrl_state; /* '<S12>/stop_and_go_control_states' */
extern uint8_T VbARBT_EPB_ctrl_mode;   /* '<S11>/Acceleration_Estimation' */
extern boolean_T VbARBT_FCW_level_three;/* '<S9>/Logical Operator15' */
extern boolean_T VbARBT_FCW_level_one; /* '<S9>/Logical Operator' */
extern boolean_T VbARBT_FCW_level_two; /* '<S9>/Logical Operator1' */
extern boolean_T VbARBT_LDW_left;      /* '<S9>/Logical Operator2' */
extern boolean_T VbARBT_BSD_left_low_raw;/* '<S9>/Logical Operator4' */
extern boolean_T VbARBT_BSD_right_low_raw;/* '<S9>/Logical Operator5' */
extern boolean_T VbARBT_LCA_left_low_raw;/* '<S9>/Logical Operator6' */
extern boolean_T VbARBT_LCA_right_low_raw;/* '<S9>/Logical Operator7' */
extern boolean_T VbARBT_warn_lcw_left_req;/* '<S9>/Logical Operator9' */
extern boolean_T VbARBT_LDW_right;     /* '<S9>/Logical Operator3' */
extern boolean_T VbARBT_BSD_left_high_raw;/* '<S9>/Logical Operator11' */
extern boolean_T VbARBT_LCA_left_high_raw;/* '<S9>/Logical Operator13' */
extern boolean_T VbARBT_BSD_right_high_raw;/* '<S9>/Logical Operator12' */
extern boolean_T VbARBT_LCA_right_high_raw;/* '<S9>/Logical Operator14' */
extern boolean_T VbARBT_FCW_level_four;/* '<S9>/Logical Operator16' */
extern boolean_T VbARBT_FCW_level_five;/* '<S9>/Logical Operator17' */
extern boolean_T VbARBT_warn_lcw_right_req;/* '<S9>/Logical Operator10' */
extern boolean_T VbARBT_steer_ctrl_enbl_to_comm;/* '<S8>/Logical Operator2' */
extern boolean_T VbARBT_aeb_triggered_flag;/* '<S7>/Logical Operator'
                                            * Flag of whether AEB is triggered
                                            */
extern boolean_T VbARBT_missed_aeb_flag;/* '<S7>/DtrmnRecTrigger'
                                         * Flag of whether a missed aeb event is detected
                                         */
extern boolean_T VbARBT_false_aeb_flag;/* '<S7>/DtrmnRecTrigger'
                                        * Flag of whether a false AEB event is detected

                                        */
extern boolean_T VbARBT_driver_hard_brake_flag;/* '<S7>/DtrmnDriverHardBrake'
                                                * Flag of whether driver is taking a hard brake
                                                */
extern boolean_T VbARBT_power_ctrl_enbl_to_comm;/* '<S6>/Switch3' */
extern boolean_T VbARBT_brake_ctrl_enbl_to_comm;/* '<S4>/Logical Operator4' */
extern boolean_T VbARBT_EPB_ctrl_enbl_to_comm;/* '<S11>/Logical Operator3' */
extern boolean_T VbARBT_vehicle_standstill;/* '<S10>/Data Type Conversion' */
extern boolean_T VbARBT_EPB_switch_request;/* '<S11>/Switch'
                                            * 1 = clamping request
                                              0 = release request
                                            */
extern boolean_T VbARBT_gear_ctrl_enbl_to_comm;/* '<S12>/Logical Operator' */
extern boolean_T VbARBT_auto_hold_req; /* '<S12>/stop_and_go_control_states' */
extern EnumARBT_arbitration_winner VeARBT_steer_arbt_winner;/* '<S8>/MATLAB Function' */
extern EnumARBT_arbitration_winner VeARBT_power_arbt_winner;/* '<S6>/Switch4' */
extern EnumARBT_arbitration_winner VeARBT_brake_arbt_winner;/* '<S4>/Switch3' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T KfARBT_autohold_timeout;/* Variable: KfARBT_autohold_timeout
                                         * Referenced by: '<S3>/Constant1'
                                         * Unit in second
                                         */
extern real32_T KfARBT_brake_req_lon_a_lowerlimit;/* Variable: KfARBT_brake_req_lon_a_lowerlimit
                                                   * Referenced by: '<S4>/Constant7'
                                                   * Lower limit for brake longitudinal acceleration request output (in m/s2)
                                                   */
extern real32_T KfARBT_brake_req_lon_a_upperlimit;/* Variable: KfARBT_brake_req_lon_a_upperlimit
                                                   * Referenced by: '<S4>/Constant6'
                                                   * Upper limit for brake longitudinal acceleration request output (in m/s2)
                                                   */
extern real32_T KfARBT_brk_ped_pos_thrsh_rec_trig;/* Variable: KfARBT_brk_ped_pos_thrsh_rec_trig
                                                   * Referenced by: '<S7>/Constant1'
                                                   * Threshold of actual brake pedal position to determine if driver is taking a hard brake
                                                   */
extern real32_T KfARBT_lon_a_thrsh_rec_trig;/* Variable: KfARBT_lon_a_thrsh_rec_trig
                                             * Referenced by: '<S7>/Constant'
                                             * Threshold of longitudinal acceleration to determine if the driver is taking a hard brake
                                             */
extern real32_T KfARBT_power_req_lon_a_lowerlimit;/* Variable: KfARBT_power_req_lon_a_lowerlimit
                                                   * Referenced by: '<S6>/Constant7'
                                                   * Lower limit for power longitudinal acceleration request output (in m/s2)
                                                   */
extern real32_T KfARBT_power_req_lon_a_upperlimit;/* Variable: KfARBT_power_req_lon_a_upperlimit
                                                   * Referenced by: '<S6>/Constant6'
                                                   * Lower limit for power longitudinal acceleration request output (in m/s2)
                                                   */
extern real32_T KfARBT_steer_req_strwhl_angle_lowerlimit;/* Variable: KfARBT_steer_req_strwhl_angle_lowerlimit
                                                          * Referenced by: '<S8>/Constant7'
                                                          * Lower limit for steer wheel angle output (in degrees)
                                                          */
extern real32_T KfARBT_steer_req_strwhl_angle_upperlimit;/* Variable: KfARBT_steer_req_strwhl_angle_upperlimit
                                                          * Referenced by: '<S8>/Constant6'
                                                          * Upper limit for steer wheel angle output (in degrees)
                                                          */
extern real32_T KfARBT_t_false_aeb_time_gap_thrsh;/* Variable: KfARBT_t_false_aeb_time_gap_thrsh
                                                   * Referenced by: '<S7>/Constant5'
                                                   * Time difference allowed for AEB to be triggered earlier than the start of driver hard braking

                                                     Unit in ms

                                                   */
extern real32_T KfARBT_t_hard_brake_debounce_time;/* Variable: KfARBT_t_hard_brake_debounce_time
                                                   * Referenced by: '<S7>/Constant2'
                                                   * Unit in ms. The debounce time to enter hard braking state
                                                   */
extern real32_T KfARBT_t_hard_brake_time_out;/* Variable: KfARBT_t_hard_brake_time_out
                                              * Referenced by: '<S7>/Constant3'
                                              * Unit in second, time out for hard braking state
                                              */
extern real32_T KfARBT_t_missed_aeb_time_gap_thrsh;/* Variable: KfARBT_t_missed_aeb_time_gap_thrsh
                                                    * Referenced by: '<S7>/Constant4'
                                                    * Time difference allowed for AEB to be triggered later than the start of driver hard braking

                                                      Unit in ms


                                                    */
extern real32_T KfARBT_t_speed_debounce_time;/* Variable: KfARBT_t_speed_debounce_time
                                              * Referenced by: '<S10>/Constant2'
                                              */
extern real32_T KfARBT_v_moving_speed_thrsh;/* Variable: KfARBT_v_moving_speed_thrsh
                                             * Referenced by: '<S10>/Constant'
                                             */
extern real32_T KfARBT_v_standstill_speed_thrsh;/* Variable: KfARBT_v_standstill_speed_thrsh
                                                 * Referenced by: '<S10>/Constant1'
                                                 */
extern uint8_T KbARBT_power_req_mode_man_ctrl_temp;/* Variable: KbARBT_power_req_mode_man_ctrl_temp
                                                    * Referenced by: '<S6>/Constant2'
                                                    */
extern boolean_T KbARBT_SLEW_autohold_active;/* Variable: KbARBT_SLEW_autohold_active
                                              * Referenced by: '<S3>/Constant'
                                              */
extern boolean_T KbARBT_SLEW_gear_ctrl_accel_req;/* Variable: KbARBT_SLEW_gear_ctrl_accel_req
                                                  * Referenced by: '<S3>/Constant2'
                                                  */
extern boolean_T KbARBT_gear_pos_fedbck_valid;/* Variable: KbARBT_gear_pos_fedbck_valid
                                               * Referenced by: '<S11>/Constant2'
                                               * Validity flag of gear position feedback signal.

                                                 For project vehicle without gear position feedback, this calibration shall be set to 0
                                               */

/* Model entry point functions */
extern void ARBT_subsystem_integrated_initialize(void);
extern void ARBT_subsystem_integrated_step(void);

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
 * '<Root>' : 'ARBT_subsystem_integrated'
 * '<S1>'   : 'ARBT_subsystem_integrated/ARBTIntegrated'
 * '<S2>'   : 'ARBT_subsystem_integrated/Release Note'
 * '<S3>'   : 'ARBT_subsystem_integrated/ARBTIntegrated/AccessoryArbitration'
 * '<S4>'   : 'ARBT_subsystem_integrated/ARBTIntegrated/BrakeArbitration'
 * '<S5>'   : 'ARBT_subsystem_integrated/ARBTIntegrated/OutputSignalProcess'
 * '<S6>'   : 'ARBT_subsystem_integrated/ARBTIntegrated/PowerArbitration'
 * '<S7>'   : 'ARBT_subsystem_integrated/ARBTIntegrated/RecordTriggerArbitration'
 * '<S8>'   : 'ARBT_subsystem_integrated/ARBTIntegrated/SteerArbitration'
 * '<S9>'   : 'ARBT_subsystem_integrated/ARBTIntegrated/WarningArbitration'
 * '<S10>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/AccessoryArbitration/DtrmnVehStandStill'
 * '<S11>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/AccessoryArbitration/ElectricParkingBrakeControl'
 * '<S12>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/AccessoryArbitration/GearPosControl'
 * '<S13>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/AccessoryArbitration/HornControl'
 * '<S14>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/AccessoryArbitration/DtrmnVehStandStill/VehicleStandstillStateEst'
 * '<S15>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/AccessoryArbitration/ElectricParkingBrakeControl/Acceleration_Estimation'
 * '<S16>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/AccessoryArbitration/ElectricParkingBrakeControl/Compare To Constant1'
 * '<S17>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/AccessoryArbitration/ElectricParkingBrakeControl/Gear N'
 * '<S18>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/AccessoryArbitration/ElectricParkingBrakeControl/Gear P'
 * '<S19>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/AccessoryArbitration/GearPosControl/stop_and_go_control_states'
 * '<S20>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/BrakeArbitration/Compare To Constant'
 * '<S21>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/BrakeArbitration/Saturation Dynamic'
 * '<S22>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/PowerArbitration/Saturation Dynamic'
 * '<S23>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/PowerArbitration/m//s2'
 * '<S24>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/RecordTriggerArbitration/Compare To Zero'
 * '<S25>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/RecordTriggerArbitration/CreateRecTrigBus'
 * '<S26>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/RecordTriggerArbitration/DtrmnDriverHardBrake'
 * '<S27>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/RecordTriggerArbitration/DtrmnRecTrigger'
 * '<S28>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/SteerArbitration/MATLAB Function'
 * '<S29>'  : 'ARBT_subsystem_integrated/ARBTIntegrated/SteerArbitration/Saturation Dynamic'
 */
#endif                                 /* RTW_HEADER_ARBT_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
