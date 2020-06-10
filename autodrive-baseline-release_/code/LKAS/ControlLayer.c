/*
 * File: ControlLayer.c
 *
 * Code generated for Simulink model 'LKAS_subsystem_integrated'.
 *
 * Model version                  : 1.102
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 11:05:35 2020
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

#include "ControlLayer.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* System initialize for atomic system: '<S3>/ControlLayer' */
void LKAS_subsyste_ControlLayer_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S4>/InterventionManager' */
  LKAS_s_InterventionManager_Init();

  /* End of SystemInitialize for SubSystem: '<S4>/InterventionManager' */

  /* SystemInitialize for Atomic SubSystem: '<S4>/CreateCtrlValue' */
  LKAS_subsy_CreateCtrlValue_Init();

  /* End of SystemInitialize for SubSystem: '<S4>/CreateCtrlValue' */
}

/* Output and update for atomic system: '<S3>/ControlLayer' */
void LKAS_subsystem_int_ControlLayer(void)
{
  /* Outputs for Atomic SubSystem: '<S4>/InterventionAbort' */
  LKAS_subsyste_InterventionAbort();

  /* End of Outputs for SubSystem: '<S4>/InterventionAbort' */

  /* Outputs for Atomic SubSystem: '<S4>/SuppressionManager_LKA' */
  LKAS_sub_SuppressionManager_LKA();

  /* End of Outputs for SubSystem: '<S4>/SuppressionManager_LKA' */

  /* Outputs for Atomic SubSystem: '<S4>/TriggeringSLKA' */
  LKAS_subsystem_i_TriggeringSLKA();

  /* End of Outputs for SubSystem: '<S4>/TriggeringSLKA' */

  /* Outputs for Atomic SubSystem: '<S4>/InterventionManager' */
  LKAS_subsys_InterventionManager();

  /* End of Outputs for SubSystem: '<S4>/InterventionManager' */

  /* Outputs for Atomic SubSystem: '<S4>/CreateCtrlValue' */
  LKAS_subsystem__CreateCtrlValue();

  /* End of Outputs for SubSystem: '<S4>/CreateCtrlValue' */

  /* Outputs for Atomic SubSystem: '<S4>/InterventionCompletion' */
  LKAS_sub_InterventionCompletion();

  /* End of Outputs for SubSystem: '<S4>/InterventionCompletion' */

  /* Outputs for Atomic SubSystem: '<S4>/OutputManager_LKA' */
  LKAS_subsyste_OutputManager_LKA();

  /* End of Outputs for SubSystem: '<S4>/OutputManager_LKA' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
