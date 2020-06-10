/*
 * File: ttc_calculation_aebs_an7L2XSm.c
 *
 * Code generated for Simulink model 'AEBS_subsystem_integrated'.
 *
 * Model version                  : 1.3069
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed May 20 17:43:59 2020
 */

#include "rtwtypes.h"
#include <math.h>
#include "ttc_calculation_aebs_an7L2XSm.h"

/* Function for MATLAB Function: '<S9>/AEB_Target_Selection' */
real32_T ttc_calculation_aebs_an7L2XSm(real32_T delta_dis, real32_T delta_speed,
  real32_T delta_acceleration)
{
  real32_T ttc;
  real32_T delta_acceleration_0;
  if (((real32_T)fabs((real_T)delta_acceleration)) < 0.5F)
  {
    if (((real_T)delta_speed) > 0.01)
    {
      delta_acceleration_0 = delta_speed;
    }
    else
    {
      delta_acceleration_0 = 0.01F;
    }

    ttc = delta_dis / delta_acceleration_0;
  }
  else if (delta_acceleration <= -0.5F)
  {
    if (((real_T)delta_speed) > 0.01)
    {
      delta_acceleration_0 = delta_speed;
    }
    else
    {
      delta_acceleration_0 = 0.01F;
    }

    ttc = delta_dis / delta_acceleration_0;
  }
  else
  {
    if (((real_T)delta_acceleration) > 0.01)
    {
      delta_acceleration_0 = delta_acceleration;
    }
    else
    {
      delta_acceleration_0 = 0.01F;
    }

    ttc = ((-delta_speed) + ((real32_T)sqrt((real_T)((real32_T)((delta_speed *
                delta_speed) + ((2.0F * delta_dis) * delta_acceleration)))))) /
      delta_acceleration_0;
  }

  return ttc;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
