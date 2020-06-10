/*
 * File: rt_powf_snf.c
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
#include "rtGetInf.h"
#include <math.h>
#include "rt_powf_snf.h"

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  real32_T tmp;
  real32_T tmp_0;
  if ((rtIsNaNF(u0)) || (rtIsNaNF(u1)))
  {
    y = (rtNaNF);
  }
  else
  {
    tmp = (real32_T)fabs((real_T)u0);
    tmp_0 = (real32_T)fabs((real_T)u1);
    if (rtIsInfF(u1))
    {
      if (tmp == 1.0F)
      {
        y = 1.0F;
      }
      else if (tmp > 1.0F)
      {
        if (u1 > 0.0F)
        {
          y = (rtInfF);
        }
        else
        {
          y = 0.0F;
        }
      }
      else if (u1 > 0.0F)
      {
        y = 0.0F;
      }
      else
      {
        y = (rtInfF);
      }
    }
    else if (tmp_0 == 0.0F)
    {
      y = 1.0F;
    }
    else if (tmp_0 == 1.0F)
    {
      if (u1 > 0.0F)
      {
        y = u0;
      }
      else
      {
        y = 1.0F / u0;
      }
    }
    else if (u1 == 2.0F)
    {
      y = u0 * u0;
    }
    else if ((u1 == 0.5F) && (u0 >= 0.0F))
    {
      y = (real32_T)sqrt((real_T)u0);
    }
    else if ((u0 < 0.0F) && (u1 > ((real32_T)floor((real_T)u1))))
    {
      y = (rtNaNF);
    }
    else
    {
      y = (real32_T)pow((real_T)u0, (real_T)u1);
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
