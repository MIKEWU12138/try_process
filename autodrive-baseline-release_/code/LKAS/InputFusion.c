/*
 * File: InputFusion.c
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

#include "InputFusion.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* System initialize for atomic system: '<S3>/InputFusion' */
void LKAS_subsystem_InputFusion_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S5>/LaneMarkerHandler' */
  LKAS_sub_LaneMarkerHandler_Init();

  /* End of SystemInitialize for SubSystem: '<S5>/LaneMarkerHandler' */

  /* SystemInitialize for Atomic SubSystem: '<S5>/TrajectoryCalculation' */
  LKAS_TrajectoryCalculation_Init();

  /* End of SystemInitialize for SubSystem: '<S5>/TrajectoryCalculation' */
}

/* Outputs for atomic system: '<S3>/InputFusion' */
void LKAS_subsystem_inte_InputFusion(void)
{
  /* Outputs for Atomic SubSystem: '<S5>/LaneMarkerHandler' */
  LKAS_subsyste_LaneMarkerHandler();

  /* End of Outputs for SubSystem: '<S5>/LaneMarkerHandler' */

  /* Outputs for Atomic SubSystem: '<S5>/TrajectoryCalculation' */
  LKAS_subs_TrajectoryCalculation();

  /* End of Outputs for SubSystem: '<S5>/TrajectoryCalculation' */
}

/* Update for atomic system: '<S3>/InputFusion' */
void LKAS_subsyst_InputFusion_Update(void)
{
  /* Update for Atomic SubSystem: '<S5>/LaneMarkerHandler' */
  LKAS_s_LaneMarkerHandler_Update();

  /* End of Update for SubSystem: '<S5>/LaneMarkerHandler' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
