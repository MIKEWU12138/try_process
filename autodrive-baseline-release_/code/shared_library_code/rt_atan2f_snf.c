/*
 * File: rt_atan2f_snf.c
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.1804
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Mar 19 23:33:55 2020
 */

#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "rt_defines.h"
#include "rt_atan2f_snf.h"

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  int32_T u0_0;
  int32_T u1_0;
  if ((rtIsNaNF(u0)) || (rtIsNaNF(u1)))
  {
    y = (rtNaNF);
  }
  else if ((rtIsInfF(u0)) && (rtIsInfF(u1)))
  {
    if (u0 > 0.0F)
    {
      u0_0 = 1;
    }
    else
    {
      u0_0 = -1;
    }

    if (u1 > 0.0F)
    {
      u1_0 = 1;
    }
    else
    {
      u1_0 = -1;
    }

    y = (real32_T)atan2((real_T)((real32_T)u0_0), (real_T)((real32_T)u1_0));
  }
  else if (u1 == 0.0F)
  {
    if (u0 > 0.0F)
    {
      y = RT_PIF / 2.0F;
    }
    else if (u0 < 0.0F)
    {
      y = -(RT_PIF / 2.0F);
    }
    else
    {
      y = 0.0F;
    }
  }
  else
  {
    y = (real32_T)atan2((real_T)u0, (real_T)u1);
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
