/*
 * File: LKAS_subsystem_integrated_data.c
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

#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* Invariant block signals (auto storage) */
const ConstB_LKAS_subsystem_integra_T LKAS_subsystem_integrate_ConstB =
{
  1.0F,                                /* '<S262>/Sum of Elements' */
  1,                                   /* '<S13>/Logical Operator2' */
  0,                                   /* '<S75>/Logical Operator' */
  1,                                   /* '<S7>/Constant' */
  0U                                   /* '<S85>/Gain1' */
};

/* Constant parameters (auto storage) */
const ConstP_LKAS_subsystem_integra_T LKAS_subsystem_integrate_ConstP =
{
  /* Pooled Parameter (Expression: single([0 0 0 0 0 0 0 0]))
   * Referenced by:
   *   '<S262>/Zero_2'
   *   '<S306>/Zero_2'
   *   '<S312>/Zero_2'
   */
  {
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
  },

  /* Computed Parameter: uDLookupTable_maxIndex
   * Referenced by: '<S17>/1-D Lookup Table'
   */
  {
    5U, 8U
  }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
