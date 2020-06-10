/*
 * File: DtrmnDCSN_Integrated.c
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

#include "DtrmnDCSN_Integrated.h"

/* Include model header file for global data */
#include "DCSN_subsystem_integrated.h"
#include "DCSN_subsystem_integrated_private.h"

/* System initialize for atomic system: '<Root>/DtrmnDCSN_Integrated' */
void DCSN__DtrmnDCSN_Integrated_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/DtrmnDCSN_ADM' */
  DCSN_subsyst_DtrmnDCSN_ADM_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/DtrmnDCSN_ADM' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/DtrmnDCSN_EnablingManager' */
  DtrmnDCSN_EnablingManager_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/DtrmnDCSN_EnablingManager' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/DtrmnDCSN_TrafficDecider' */
  D_DtrmnDCSN_TrafficDecider_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/DtrmnDCSN_TrafficDecider' */
}

/* Output and update for atomic system: '<Root>/DtrmnDCSN_Integrated' */
void DCSN_subsy_DtrmnDCSN_Integrated(void)
{
  /* Outputs for Atomic SubSystem: '<S1>/DtrmnDCSN_ADM' */
  DCSN_subsystem_in_DtrmnDCSN_ADM();

  /* End of Outputs for SubSystem: '<S1>/DtrmnDCSN_ADM' */

  /* Outputs for Atomic SubSystem: '<S1>/DtrmnDCSN_EnablingManager' */
  DCSN__DtrmnDCSN_EnablingManager();

  /* End of Outputs for SubSystem: '<S1>/DtrmnDCSN_EnablingManager' */

  /* Outputs for Atomic SubSystem: '<S1>/DtrmnDCSN_TrafficDecider' */
  DCSN_s_DtrmnDCSN_TrafficDecider();

  /* End of Outputs for SubSystem: '<S1>/DtrmnDCSN_TrafficDecider' */

  /* BusCreator: '<S1>/Bus Creator' */
  VsDCSN_DataBus.ADM_Group = DCSN_subsystem_integrated_B.ADM_Group;
  VsDCSN_DataBus.EnablingFlags_Group =
    DCSN_subsystem_integrated_B.EnablingFlags_Group;

  /* Update for Atomic SubSystem: '<S1>/DtrmnDCSN_ADM' */
  DCSN_subsy_DtrmnDCSN_ADM_Update();

  /* End of Update for SubSystem: '<S1>/DtrmnDCSN_ADM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
