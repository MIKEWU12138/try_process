/*
 * File: sMultiWord2Single.c
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.1871
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Apr  7 19:42:52 2020
 */

#include "rtwtypes.h"
#include <math.h>
#include "sMultiWord2Single.h"

real32_T sMultiWord2Single(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real32_T y;
  int32_T i;
  int32_T exp_0;
  uint32_T u1i;
  uint32_T cb;
  y = 0.0F;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U)
  {
    cb = 1U;
    for (i = 0; i < n1; i++)
    {
      u1i = ~u1[i];
      cb += u1i;
      y -= (real32_T)ldexp((real_T)((real32_T)cb), exp_0);
      cb = (uint32_T)((cb < u1i) ? 1 : 0);
      exp_0 += 32;
    }
  }
  else
  {
    for (i = 0; i < n1; i++)
    {
      y += (real32_T)ldexp((real_T)((real32_T)u1[i]), exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
