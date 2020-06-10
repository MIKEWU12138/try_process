/*
 * File: rt_roundf.c
 *
 * Code generated for Simulink model 'LCWS_subsystem_integrated'.
 *
 * Model version                  : 1.362
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Mar 19 16:42:29 2020
 */

#include "rtwtypes.h"
#include <math.h>
#include "rt_roundf.h"

real32_T rt_roundf(real32_T u)
{
  real32_T y;
  if (((real32_T)fabs((real_T)u)) < 8.388608E+6F)
  {
    if (u >= 0.5F)
    {
      y = (real32_T)floor((real_T)((real32_T)(u + 0.5F)));
    }
    else if (u > -0.5F)
    {
      y = 0.0F;
    }
    else
    {
      y = (real32_T)ceil((real_T)((real32_T)(u - 0.5F)));
    }
  }
  else
  {
    y = u;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
