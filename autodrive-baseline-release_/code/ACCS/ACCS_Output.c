/*
 * File: ACCS_Output.c
 *
 * Code generated for Simulink model 'ACCS_subsystem_integrated'.
 *
 * Model version                  : 1.1217
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:55:27 2020
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

#include "ACCS_Output.h"

/* Include model header file for global data */
#include "ACCS_subsystem_integrated.h"
#include "ACCS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S1>/DtrmnACCS_Output' */
void DtrmnACCS_Output(void)
{
  /* SignalConversion: '<S5>/Signal Conversion' */
  VsACCS_DataBus.VbACCS_InformDriverPressResume = VbACCS_ExitStandbyToOn;

  /* SignalConversion: '<S5>/Signal Conversion1' */
  VsACCS_DataBus.VeACCS_EnterStandbyState = VeACCS_EnterStandbyType;

  /* SignalConversion: '<S5>/Signal Conversion3' */
  VsACCS_DataBus.VfACCS_Lon_Accleration = VfACCS_Lon_Accleration;

  /* SignalConversion: '<S5>/Signal Conversion2' */
  VsACCS_DataBus.VbACCS_Lon_Torq_req = VbACCS_Lon_Torq_Req;

  /* SignalConversion: '<S5>/Signal Conversion4' */
  VsACCS_DataBus.VfACCS_Lon_Torq = VfACCS_Lon_Torq_Req;

  /* SignalConversion: '<S5>/Signal Conversion5' */
  VsACCS_DataBus.VfACCS_Lon_Speed_Tar = VfACCS_VehSpeed_Tar;

  /* SignalConversion: '<S5>/Signal Conversion6' */
  VsACCS_DataBus.VfACCS_Lon_Range_Act = VfACCS_Range_Actual;

  /* SignalConversion: '<S5>/Signal Conversion7' */
  VsACCS_DataBus.VbACCS_Lon_Accleration_req = VbACCS_Lon_Accleration_Req;

  /* SignalConversion: '<S5>/Signal Conversion8' */
  VsACCS_DataBus.VeACCS_Mode = VeACCS_ModeState;

  /* SignalConversion: '<S5>/Signal Conversion9' */
  VsACCS_DataBus.VeACCS_RunStatus = VeACCS_RunStatus;

  /* BusCreator: '<S5>/Bus Creator' */
  VsACCS_DataBus.VbACCS_ExitStandbyToOn = VbACCS_InformDriverPressResume;
  VsACCS_DataBus.VbACCS_InformDriverPressGasPedal =
    VbACCS_InformDriverPressGasPedal;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
