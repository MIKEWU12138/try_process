/*
 * File: DRIV_OverrideSteerDefaultData.c
 *
 * Code generated for Simulink model 'DRIV_subsystem_integrated'.
 *
 * Model version                  : 1.1200
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 08:50:22 2020
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

#include "DRIV_OverrideSteerDefaultData.h"

/* Include model header file for global data */
#include "DRIV_subsystem_integrated.h"
#include "DRIV_subsystem_integrated_private.h"

/* Output and update for action system: '<S48>/DRIV_OverrideSteer_DefaultData' */
void DRIV_OverrideSteerDefaultData(void)
{
  /* BusCreator: '<S51>/Bus Creator2' incorporates:
   *  Constant: '<S51>/Constant1'
   *  Constant: '<S51>/Constant2'
   *  Constant: '<S77>/Constant'
   *  Constant: '<S78>/Constant'
   */
  DRIV_subsystem_integrated_B.Merge.VbDIRV_Override_Steering =
    KbDRIV_Default_Override_Steering;
  DRIV_subsystem_integrated_B.Merge.VeDRIV_LeftChangeLane = LeftLC_NOT;
  DRIV_subsystem_integrated_B.Merge.VeDRIV_RightChangeLane = RightLC_NOT;
  DRIV_subsystem_integrated_B.Merge.VbDRIV_LaneKeepAssist =
    KbDRIV_Default_LaneKeepAssist;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
