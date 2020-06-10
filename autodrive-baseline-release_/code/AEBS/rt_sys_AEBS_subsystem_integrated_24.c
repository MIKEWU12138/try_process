/*
 * File: rt_sys_AEBS_subsystem_integrated_24.c
 *
 * Code generated for Simulink model 'AEBS_subsystem_integrated'.
 *
 * Model version                  : 1.3091
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 16:35:01 2020
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

#include "rt_sys_AEBS_subsystem_integrated_24.h"

/* Include model header file for global data */
#include "AEBS_subsystem_integrated.h"
#include "AEBS_subsystem_integrated_private.h"

/* Named constants for Chart: '<S85>/Chart' */
#define AEBS_su_IN_NO_ACTIVE_CHILD_gj0g ((uint8_T)0U)
#define AEBS_subsystem_i_IN_Raised_gzxd ((uint8_T)3U)
#define AEBS_subsystem_in_IN_Delay_owqz ((uint8_T)1U)
#define AEBS_subsystem_int_IN_INIT_f1yl ((uint8_T)2U)

/*
 * System initialize for atomic system:
 *    '<S85>/Chart'
 *    '<S97>/Chart'
 *    '<S99>/Chart'
 *    '<S132>/Chart'
 *    '<S139>/Chart'
 *    '<S213>/Chart'
 *    '<S214>/Chart'
 */
void AEBS_subsystem__Chart_k51z_Init(DW_Chart_AEBS_subsystem__jbmw_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c4_AEBS_subsystem_int = 0U;
  localDW->is_c4_AEBS_subsystem_integrated = AEBS_su_IN_NO_ACTIVE_CHILD_gj0g;
}

/*
 * Output and update for atomic system:
 *    '<S85>/Chart'
 *    '<S97>/Chart'
 *    '<S99>/Chart'
 *    '<S132>/Chart'
 *    '<S139>/Chart'
 *    '<S213>/Chart'
 *    '<S214>/Chart'
 */
void AEBS_subsystem_integ_Chart_fmkq(boolean_T rtu_in, uint32_T rtu_delay_time,
  boolean_T *rty_y, uint8_T *rty_state, DW_Chart_AEBS_subsystem__jbmw_T *localDW)
{
  /* Chart: '<S85>/Chart' */
  if (localDW->temporalCounter_i1 < MAX_uint32_T)
  {
    localDW->temporalCounter_i1++;
  }

  if (((uint32_T)localDW->is_active_c4_AEBS_subsystem_int) == 0U)
  {
    localDW->is_active_c4_AEBS_subsystem_int = 1U;
    localDW->is_c4_AEBS_subsystem_integrated = AEBS_subsystem_int_IN_INIT_f1yl;
    *rty_y = false;
    *rty_state = 1U;
  }
  else
  {
    switch (localDW->is_c4_AEBS_subsystem_integrated)
    {
     case AEBS_subsystem_in_IN_Delay_owqz:
      if (!rtu_in)
      {
        localDW->is_c4_AEBS_subsystem_integrated =
          AEBS_subsystem_int_IN_INIT_f1yl;
        *rty_y = false;
        *rty_state = 1U;
      }
      else if (localDW->temporalCounter_i1 >= rtu_delay_time)
      {
        localDW->is_c4_AEBS_subsystem_integrated =
          AEBS_subsystem_i_IN_Raised_gzxd;
        *rty_y = true;
        *rty_state = 2U;
      }
      else
      {
        *rty_y = false;
        *rty_state = 2U;
      }
      break;

     case AEBS_subsystem_int_IN_INIT_f1yl:
      if (rtu_in)
      {
        localDW->is_c4_AEBS_subsystem_integrated =
          AEBS_subsystem_in_IN_Delay_owqz;
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
        localDW->is_c4_AEBS_subsystem_integrated =
          AEBS_subsystem_int_IN_INIT_f1yl;
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

  /* End of Chart: '<S85>/Chart' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
