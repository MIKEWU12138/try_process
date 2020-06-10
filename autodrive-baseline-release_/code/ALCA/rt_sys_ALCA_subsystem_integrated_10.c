/*
 * File: rt_sys_ALCA_subsystem_integrated_10.c
 *
 * Code generated for Simulink model 'ALCA_subsystem_integrated'.
 *
 * Model version                  : 1.6591
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:34:22 2020
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

#include "rt_sys_ALCA_subsystem_integrated_10.h"

/* Include model header file for global data */
#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"

/* Named constants for Chart: '<S22>/Chart' */
#define ALCA_subsyst_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define ALCA_subsystem_integr_IN_Raised ((uint8_T)3U)
#define ALCA_subsystem_integra_IN_Delay ((uint8_T)1U)
#define ALCA_subsystem_integrat_IN_INIT ((uint8_T)2U)

/*
 * System initialize for atomic system:
 *    '<S22>/Chart'
 *    '<S23>/Chart'
 *    '<S65>/Chart'
 *    '<S66>/Chart'
 *    '<S67>/Chart'
 */
void ALCA_subsystem_integ_Chart_Init(DW_Chart_ALCA_subsystem_integ_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c8_ALCA_subsystem_int = 0U;
  localDW->is_c8_ALCA_subsystem_integrated = ALCA_subsyst_IN_NO_ACTIVE_CHILD;
}

/*
 * System reset for atomic system:
 *    '<S22>/Chart'
 *    '<S23>/Chart'
 *    '<S65>/Chart'
 *    '<S66>/Chart'
 *    '<S67>/Chart'
 */
void ALCA_subsystem_inte_Chart_Reset(DW_Chart_ALCA_subsystem_integ_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c8_ALCA_subsystem_int = 0U;
  localDW->is_c8_ALCA_subsystem_integrated = ALCA_subsyst_IN_NO_ACTIVE_CHILD;
}

/*
 * Output and update for atomic system:
 *    '<S22>/Chart'
 *    '<S23>/Chart'
 *    '<S65>/Chart'
 *    '<S66>/Chart'
 *    '<S67>/Chart'
 */
void ALCA_subsystem_integrated_Chart(boolean_T rtu_in, real32_T rtu_delay_time,
  boolean_T *rty_y, uint8_T *rty_state, DW_Chart_ALCA_subsystem_integ_T *localDW)
{
  /* Chart: '<S22>/Chart' */
  if (((uint32_T)localDW->temporalCounter_i1) < 65535U)
  {
    localDW->temporalCounter_i1 = (uint16_T)((int32_T)(((int32_T)
      localDW->temporalCounter_i1) + 1));
  }

  if (((uint32_T)localDW->is_active_c8_ALCA_subsystem_int) == 0U)
  {
    localDW->is_active_c8_ALCA_subsystem_int = 1U;
    localDW->is_c8_ALCA_subsystem_integrated = ALCA_subsystem_integrat_IN_INIT;
    *rty_y = false;
    *rty_state = 1U;
  }
  else
  {
    switch (localDW->is_c8_ALCA_subsystem_integrated)
    {
     case ALCA_subsystem_integra_IN_Delay:
      if (!rtu_in)
      {
        localDW->is_c8_ALCA_subsystem_integrated =
          ALCA_subsystem_integrat_IN_INIT;
        *rty_y = false;
        *rty_state = 1U;
      }
      else if (localDW->temporalCounter_i1 >= ((uint16_T)rtu_delay_time))
      {
        localDW->is_c8_ALCA_subsystem_integrated =
          ALCA_subsystem_integr_IN_Raised;
        *rty_y = true;
        *rty_state = 2U;
      }
      else
      {
        *rty_y = false;
        *rty_state = 2U;
      }
      break;

     case ALCA_subsystem_integrat_IN_INIT:
      if (rtu_in)
      {
        localDW->is_c8_ALCA_subsystem_integrated =
          ALCA_subsystem_integra_IN_Delay;
        localDW->temporalCounter_i1 = 0U;
        *rty_y = false;
        *rty_state = 2U;
      }
      else
      {
        *rty_y = false;
        *rty_state = 1U;
      }
      break;

     default:
      if (!rtu_in)
      {
        localDW->is_c8_ALCA_subsystem_integrated =
          ALCA_subsystem_integrat_IN_INIT;
        *rty_y = false;
        *rty_state = 1U;
      }
      else
      {
        *rty_y = true;
        *rty_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S22>/Chart' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
