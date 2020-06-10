/*
 * File: ACCS_Task.c
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

#include "ACCS_Task.h"

/* Include model header file for global data */
#include "ACCS_subsystem_integrated.h"
#include "ACCS_subsystem_integrated_private.h"

/* System initialize for atomic system: '<Root>/ACCS' */
void DtrmnACCS_Task_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/DtrmnACCS_MainLogic' */
  DtrmnACCS_MainLogic_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/DtrmnACCS_MainLogic' */
}

/* Output and update for atomic system: '<Root>/ACCS' */
void DtrmnACCS_Task(void)
{
  /* Outputs for Atomic SubSystem: '<S1>/DtrmnACCS_Input' */
  DtrmnACCS_Input();

  /* End of Outputs for SubSystem: '<S1>/DtrmnACCS_Input' */

  /* Outputs for Atomic SubSystem: '<S1>/DtrmnACCS_MainLogic' */
  DtrmnACCS_MainLogic();

  /* End of Outputs for SubSystem: '<S1>/DtrmnACCS_MainLogic' */

  /* Outputs for Atomic SubSystem: '<S1>/DtrmnACCS_Output' */
  DtrmnACCS_Output();

  /* End of Outputs for SubSystem: '<S1>/DtrmnACCS_Output' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
