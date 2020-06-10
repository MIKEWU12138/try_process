/*
 * File: lccs_control.c
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

#include "lccs_control.h"

/* Include model header file for global data */
#include "LCCS_subsystem_integrated.h"
#include "LCCS_subsystem_integrated_private.h"

/* System initialize for atomic system: '<S1>/LCCS' */
void LCCS_subsystem_integr_LCCS_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S2>/DtrmnLCCS_sensor_signal_rationality' */
  DtrmnLCCS_sensor_signal_ra_Init();

  /* End of SystemInitialize for SubSystem: '<S2>/DtrmnLCCS_sensor_signal_rationality' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/DtrmnLCCS_sensor_signal_processing' */
  DtrmnLCCS_sensor_signal_pr_Init();

  /* End of SystemInitialize for SubSystem: '<S2>/DtrmnLCCS_sensor_signal_processing' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/CalcLCCS_virtual_lane_marker' */
  CalcLCCS_virtual_lane_mark_Init();

  /* End of SystemInitialize for SubSystem: '<S2>/CalcLCCS_virtual_lane_marker' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/CalcLCCS_lateral_shift_width' */
  CalcLCCS_lateral_shift_wid_Init();

  /* End of SystemInitialize for SubSystem: '<S2>/CalcLCCS_lateral_shift_width' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/CalcLCCS_compute_lateral_errors' */
  CalcLCCS_compute_lateral_e_Init();

  /* End of SystemInitialize for SubSystem: '<S2>/CalcLCCS_compute_lateral_errors' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/CalcLCCS_lateral_control_main' */
  CalcLCCS_lateral_control_m_Init();

  /* End of SystemInitialize for SubSystem: '<S2>/CalcLCCS_lateral_control_main' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/DtrmnLCCS_steering_control_output' */
  DtrmnLCCS_steering_control_Init();

  /* End of SystemInitialize for SubSystem: '<S2>/DtrmnLCCS_steering_control_output' */
}

/* Output and update for atomic system: '<S1>/LCCS' */
void LCCS_subsystem_integrated_LCCS(void)
{
  boolean_T rtb_VbLCCS_steering_control_sta;
  boolean_T rtb_VbLCCS_steering_control_act;
  boolean_T rtb_VbLCCS_steering_control_eng;

  /* UnitDelay: '<S2>/UnitDelay2' */
  rtb_VbLCCS_steering_control_sta =
    LCCS_subsystem_integrated_DW.UnitDelay2_1_DSTATE;
  rtb_VbLCCS_steering_control_act =
    LCCS_subsystem_integrated_DW.UnitDelay2_2_DSTATE;
  rtb_VbLCCS_steering_control_eng =
    LCCS_subsystem_integrated_DW.UnitDelay2_3_DSTATE;

  /* Outputs for Atomic SubSystem: '<S2>/DtrmnLCCS_sensor_signal_rationality' */
  DtrmnLCCS_sensor_signal_rationa();

  /* End of Outputs for SubSystem: '<S2>/DtrmnLCCS_sensor_signal_rationality' */

  /* UnitDelay: '<S2>/Unit Delay' */
  LCCS_subsystem_integrated_B.Add1 =
    LCCS_subsystem_integrated_DW.UnitDelay_DSTATE;

  /* Outputs for Atomic SubSystem: '<S2>/DtrmnLCCS_sensor_signal_processing' */
  DtrmnLCCS_sensor_signal_process();

  /* End of Outputs for SubSystem: '<S2>/DtrmnLCCS_sensor_signal_processing' */

  /* UnitDelay: '<S2>/UnitDelay2' */
  LCCS_subsystem_integrated_B.VbLCCS_steering_control_st_jgz4 =
    LCCS_subsystem_integrated_DW.UnitDelay2_4_DSTATE;

  /* Outputs for Atomic SubSystem: '<S2>/CalcLCCS_virtual_lane_marker' */
  LC_CalcLCCS_virtual_lane_marker();

  /* End of Outputs for SubSystem: '<S2>/CalcLCCS_virtual_lane_marker' */

  /* Outputs for Atomic SubSystem: '<S2>/CalcLCCS_lane_center_line' */
  LCCS__CalcLCCS_lane_center_line();

  /* End of Outputs for SubSystem: '<S2>/CalcLCCS_lane_center_line' */

  /* Outputs for Atomic SubSystem: '<S2>/CalcLCCS_lateral_shift_width' */
  LC_CalcLCCS_lateral_shift_width();

  /* End of Outputs for SubSystem: '<S2>/CalcLCCS_lateral_shift_width' */

  /* Outputs for Atomic SubSystem: '<S2>/CalcLCCS_lane_center_discretize' */
  CalcLCCS_lane_center_discretize();

  /* End of Outputs for SubSystem: '<S2>/CalcLCCS_lane_center_discretize' */

  /* Outputs for Atomic SubSystem: '<S2>/CalcLCCS_compute_lateral_errors' */
  CalcLCCS_compute_lateral_errors();

  /* End of Outputs for SubSystem: '<S2>/CalcLCCS_compute_lateral_errors' */

  /* UnitDelay: '<S2>/UnitDelay1' */
  LCCS_subsystem_integrated_B.VbLCCS_steering_control_st_jgz4 =
    LCCS_subsystem_integrated_DW.UnitDelay1_1_DSTATE;
  LCCS_subsystem_integrated_B.VbLCCS_steering_control_ac_byg4 =
    LCCS_subsystem_integrated_DW.UnitDelay1_2_DSTATE;
  LCCS_subsystem_integrated_B.VbLCCS_steering_control_en_pmot =
    LCCS_subsystem_integrated_DW.UnitDelay1_3_DSTATE;
  LCCS_subsystem_integrated_B.VbLCCS_lateral_movement_en_ka3l =
    LCCS_subsystem_integrated_DW.UnitDelay1_4_DSTATE;

  /* Outputs for Atomic SubSystem: '<S2>/CalcLCCS_lateral_control_main' */
  L_CalcLCCS_lateral_control_main();

  /* End of Outputs for SubSystem: '<S2>/CalcLCCS_lateral_control_main' */

  /* Outputs for Atomic SubSystem: '<S2>/DtrmnLCCS_steering_control_output' */
  DtrmnLCCS_steering_control_outp();

  /* End of Outputs for SubSystem: '<S2>/DtrmnLCCS_steering_control_output' */

  /* Update for UnitDelay: '<S2>/UnitDelay2' */
  LCCS_subsystem_integrated_DW.UnitDelay2_1_DSTATE =
    VbLCCS_steering_control_stable;
  LCCS_subsystem_integrated_DW.UnitDelay2_2_DSTATE =
    VbLCCS_steering_control_active;
  LCCS_subsystem_integrated_DW.UnitDelay2_3_DSTATE =
    VbLCCS_steering_control_engaged;

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  LCCS_subsystem_integrated_DW.UnitDelay_DSTATE = VfLCCS_preview_curvature;

  /* Update for UnitDelay: '<S2>/UnitDelay2' */
  LCCS_subsystem_integrated_DW.UnitDelay2_4_DSTATE =
    VbLCCS_lateral_movement_enabled;

  /* Update for UnitDelay: '<S2>/UnitDelay1' */
  LCCS_subsystem_integrated_DW.UnitDelay1_1_DSTATE =
    VbLCCS_steering_control_stable;
  LCCS_subsystem_integrated_DW.UnitDelay1_2_DSTATE =
    VbLCCS_steering_control_active;
  LCCS_subsystem_integrated_DW.UnitDelay1_3_DSTATE =
    VbLCCS_steering_control_engaged;
  LCCS_subsystem_integrated_DW.UnitDelay1_4_DSTATE =
    VbLCCS_lateral_movement_enabled;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
