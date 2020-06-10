/*
 * File: DRIV.c
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

#include "DRIV.h"

/* Include model header file for global data */
#include "DRIV_subsystem_integrated.h"
#include "DRIV_subsystem_integrated_private.h"

/* System initialize for atomic system: '<Root>/DRIV ' */
void DRIV_subsystem_integr_DRIV_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/CheckDRIV_SignalInput' */
  CheckDRIV_SignalInput_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/CheckDRIV_SignalInput' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/DtrmnDRIV_RunStatus' */
  DtrmnDRIV_RunStatus_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/DtrmnDRIV_RunStatus' */
}

/* Start for atomic system: '<Root>/DRIV ' */
void DRIV_subsystem_integ_DRIV_Start(void)
{
  /* Start for Atomic SubSystem: '<S1>/DtrmnDRIV_RunStatus' */
  DtrmnDRIV_RunStatus_Start();

  /* End of Start for SubSystem: '<S1>/DtrmnDRIV_RunStatus' */
}

/* Output and update for atomic system: '<Root>/DRIV ' */
void DRIV_subsystem_integrated_DRIV(void)
{
  /* Outputs for Atomic SubSystem: '<S1>/CheckDRIV_SignalInput' */
  CheckDRIV_SignalInput();

  /* End of Outputs for SubSystem: '<S1>/CheckDRIV_SignalInput' */

  /* Outputs for Atomic SubSystem: '<S1>/DtrmnDRIV_RunStatus' */
  DtrmnDRIV_RunStatus();

  /* End of Outputs for SubSystem: '<S1>/DtrmnDRIV_RunStatus' */

  /* Outputs for Atomic SubSystem: '<S1>/CheckDRIV_SignalOutput' */
  CheckDRIV_SignalOutput();

  /* End of Outputs for SubSystem: '<S1>/CheckDRIV_SignalOutput' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
