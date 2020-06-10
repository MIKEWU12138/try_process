/*
 * File: DRIV_subsystem_integrated_data.c
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

#include "DRIV_subsystem_integrated.h"
#include "DRIV_subsystem_integrated_private.h"

/* Invariant block signals (auto storage) */
const ConstB_DRIV_subsystem_integra_T DRIV_subsystem_integrate_ConstB =
{
  300.0,                               /* '<S67>/Gain' */
  2U,                                  /* '<S7>/Data Type Conversion2' */
  1U,                                  /* '<S7>/Bitwise Operator1' */
  3U,                                  /* '<S7>/Bitwise Operator4' */
  4U,                                  /* '<S7>/Data Type Conversion1' */
  2U,                                  /* '<S3>/Data Type Conversion' */
  0                                    /* '<S80>/Logical Operator7' */
};

/* Constant parameters (auto storage) */
const ConstP_DRIV_subsystem_integra_T DRIV_subsystem_integrate_ConstP =
{
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S68>/Logic'
   *   '<S73>/Logic'
   *   '<S74>/Logic'
   */
  {
    0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0
  }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
