/*
 * File: norm_TbqwX7rn.c
 *
 * Code generated for Simulink model 'LCAS_subsystem_integrated'.
 *
 * Model version                  : 1.428
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sat May  9 18:26:15 2020
 */

#include "rtwtypes.h"
#include <math.h>
#include "norm_TbqwX7rn.h"

/* Function for MATLAB Function: '<S20>/CvrtObtVecFunction' */
real32_T norm_TbqwX7rn(const real32_T x[2])
{
  real32_T y;
  real32_T scale;
  real32_T absxk;
  real32_T t;
  scale = 1.29246971E-26F;
  absxk = (real32_T)fabs((real_T)x[0]);
  if (absxk > 1.29246971E-26F)
  {
    y = 1.0F;
    scale = absxk;
  }
  else
  {
    t = absxk / 1.29246971E-26F;
    y = t * t;
  }

  absxk = (real32_T)fabs((real_T)x[1]);
  if (absxk > scale)
  {
    t = scale / absxk;
    y = 1.0F + ((y * t) * t);
    scale = absxk;
  }
  else
  {
    t = absxk / scale;
    y += t * t;
  }

  return scale * ((real32_T)sqrt((real_T)y));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
