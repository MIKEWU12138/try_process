/*
 * File: rt_sys_AEBS_subsystem_integrated_30.c
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

#include "rt_sys_AEBS_subsystem_integrated_30.h"

/* Include model header file for global data */
#include "AEBS_subsystem_integrated.h"
#include "AEBS_subsystem_integrated_private.h"

/* Named constants for Chart: '<S79>/Stop_Moving_Estimation' */
#define AEBS_su_IN_NO_ACTIVE_CHILD_o3ud ((uint8_T)0U)
#define AEBS_subsystem_IN_Stopped_delay ((uint8_T)4U)
#define AEBS_subsystem__IN_Moving_delay ((uint8_T)2U)
#define AEBS_subsystem_integr_IN_Moving ((uint8_T)1U)
#define AEBS_subsystem_integrat_IN_Stop ((uint8_T)3U)

/*
 * System initialize for atomic system:
 *    '<S79>/Stop_Moving_Estimation'
 *    '<S205>/Stop_Moving_Estimation'
 */
void AEB_Stop_Moving_Estimation_Init(boolean_T *rty_vehicle_standstill,
  DW_Stop_Moving_Estimation_AEB_T *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c5_AEBS_subsystem_int = 0U;
  localDW->is_c5_AEBS_subsystem_integrated = AEBS_su_IN_NO_ACTIVE_CHILD_o3ud;
  *rty_vehicle_standstill = false;
}

/*
 * Output and update for atomic system:
 *    '<S79>/Stop_Moving_Estimation'
 *    '<S205>/Stop_Moving_Estimation'
 */
void AEBS_sub_Stop_Moving_Estimation(real32_T rtu_speed_act, real32_T
  rtu_standstill_threshold_speed, real32_T rtu_delta_standstill_threshold_,
  uint32_T rtu_speed_debounce_time, boolean_T *rty_vehicle_standstill,
  DW_Stop_Moving_Estimation_AEB_T *localDW)
{
  real_T u0_tmp;

  /* Chart: '<S79>/Stop_Moving_Estimation' */
  if (localDW->temporalCounter_i1 < MAX_uint32_T)
  {
    localDW->temporalCounter_i1++;
  }

  if (((uint32_T)localDW->is_active_c5_AEBS_subsystem_int) == 0U)
  {
    localDW->is_active_c5_AEBS_subsystem_int = 1U;
    if (rtu_speed_act > rtu_standstill_threshold_speed)
    {
      localDW->is_c5_AEBS_subsystem_integrated = AEBS_subsystem_integr_IN_Moving;
      *rty_vehicle_standstill = false;
    }
    else
    {
      localDW->is_c5_AEBS_subsystem_integrated = AEBS_subsystem_integrat_IN_Stop;
      *rty_vehicle_standstill = true;
    }
  }
  else
  {
    switch (localDW->is_c5_AEBS_subsystem_integrated)
    {
     case AEBS_subsystem_integr_IN_Moving:
      *rty_vehicle_standstill = false;
      u0_tmp = (real_T)((real32_T)(rtu_standstill_threshold_speed -
        rtu_delta_standstill_threshold_));
      if (u0_tmp > 0.1)
      {
      }
      else
      {
        u0_tmp = 0.1;
      }

      if (((real_T)rtu_speed_act) < u0_tmp)
      {
        localDW->is_c5_AEBS_subsystem_integrated =
          AEBS_subsystem_IN_Stopped_delay;
        localDW->temporalCounter_i1 = 0U;
        *rty_vehicle_standstill = false;
      }
      break;

     case AEBS_subsystem__IN_Moving_delay:
      *rty_vehicle_standstill = true;
      if (localDW->temporalCounter_i1 >= rtu_speed_debounce_time)
      {
        localDW->is_c5_AEBS_subsystem_integrated =
          AEBS_subsystem_integr_IN_Moving;
        *rty_vehicle_standstill = false;
      }
      else
      {
        u0_tmp = (real_T)((real32_T)(rtu_standstill_threshold_speed -
          rtu_delta_standstill_threshold_));
        if (u0_tmp > 0.1)
        {
        }
        else
        {
          u0_tmp = 0.1;
        }

        if (((real_T)rtu_speed_act) < u0_tmp)
        {
          localDW->is_c5_AEBS_subsystem_integrated =
            AEBS_subsystem_integrat_IN_Stop;
          *rty_vehicle_standstill = true;
        }
      }
      break;

     case AEBS_subsystem_integrat_IN_Stop:
      *rty_vehicle_standstill = true;
      if (rtu_speed_act > rtu_standstill_threshold_speed)
      {
        localDW->is_c5_AEBS_subsystem_integrated =
          AEBS_subsystem__IN_Moving_delay;
        localDW->temporalCounter_i1 = 0U;
        *rty_vehicle_standstill = true;
      }
      break;

     default:
      *rty_vehicle_standstill = false;
      if (localDW->temporalCounter_i1 >= rtu_speed_debounce_time)
      {
        localDW->is_c5_AEBS_subsystem_integrated =
          AEBS_subsystem_integrat_IN_Stop;
        *rty_vehicle_standstill = true;
      }
      else
      {
        if (rtu_speed_act > rtu_standstill_threshold_speed)
        {
          localDW->is_c5_AEBS_subsystem_integrated =
            AEBS_subsystem_integr_IN_Moving;
          *rty_vehicle_standstill = false;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S79>/Stop_Moving_Estimation' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
