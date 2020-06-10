/*
 * File: DRIV_SignalOutput.c
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

#include "DRIV_SignalOutput.h"

/* Include model header file for global data */
#include "DRIV_subsystem_integrated.h"
#include "DRIV_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S1>/CheckDRIV_SignalOutput' */
void CheckDRIV_SignalOutput(void)
{
  /* SignalConversion: '<S4>/Signal Conversion4' incorporates:
   *  BusCreator: '<S4>/BusConversion_InsertedFor_Bus Creator_at_inport_0'
   *  SignalConversion: '<S4>/Signal Conversion1'
   *  SignalConversion: '<S4>/Signal Conversion3'
   *  SignalConversion: '<S4>/Signal Conversion5'
   */
  VsDRIV_DataBus.OverrideSteer = DRIV_subsystem_integrated_B.Merge;

  /* SignalConversion: '<S4>/Signal Conversion2' */
  VsDRIV_DataBus.OverrideButton.VbACC_ButtonActivate =
    DRIV_subsystem_integrated_B.VbACC_ButtonActivate;

  /* BusCreator: '<S4>/Bus Creator3' incorporates:
   *  SignalConversion: '<S4>/Signal Conversion6'
   *  SignalConversion: '<S4>/Signal Conversion7'
   */
  VsDRIV_DataBus.OverrideButton.VbDRIV_EnableAutoDrive =
    DRIV_subsystem_integrated_B.VbDRIV_EnableAutoDrive;
  VsDRIV_DataBus.OverrideButton.VbLCC_ButtonActivate =
    DRIV_subsystem_integrated_B.VbLCC_ButtonActivate;

  /* BusCreator: '<S4>/BusConversion_InsertedFor_Bus Creator_at_inport_4' */
  VsDRIV_DataBus.DRIV_ACCS_Switch.VbDRIV_ACCMainSwitch =
    DRIV_subsystem_integrated_B.VbDRIV_ACCMainSwitch_nbff;
  VsDRIV_DataBus.DRIV_ACCS_Switch.VbDRIV_ACCResumeSwitch =
    DRIV_subsystem_integrated_B.VbDRIV_ACCResumeSwitch_i0xk;
  VsDRIV_DataBus.DRIV_ACCS_Switch.VbDRIV_ACCCancelSwitch =
    DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt;
  VsDRIV_DataBus.DRIV_ACCS_Switch.VfDRIV_ACCDriveSetSpeed =
    DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o;
  VsDRIV_DataBus.DRIV_ACCS_Switch.VfDRIV_ACCTimeGap =
    DRIV_subsystem_integrated_B.VfDRIV_ACCTimeGap_a2ct;

  /* BusCreator: '<S4>/Bus Creator' incorporates:
   *  Constant: '<S27>/Constant'
   *  Constant: '<S4>/Constant'
   */
  VsDRIV_DataBus.VeDRIV_DriverStatus = DRIV_DriverNormal;
  VsDRIV_DataBus.VbDRIV_ModeStatus = KbDRIV_DRIVEnable;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
