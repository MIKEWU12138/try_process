/*
 * File: obt_3pO7kBnK.c
 *
 * Code generated for Simulink model 'LCWS_subsystem_integrated'.
 *
 * Model version                  : 1.362
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Mar 19 16:42:29 2020
 */

#include "rtwtypes.h"
#include <math.h>
#include "obt_3pO7kBnK.h"

/* Function for MATLAB Function: '<S2>/Calc_LBSWFunction' */
void obt_3pO7kBnK(real32_T x, real32_T y, real32_T yaw, real32_T L, real32_T W,
                  real32_T A[2], real32_T B[2], real32_T C[2], real32_T D[2])
{
  real32_T A_tmp;
  real32_T A_tmp_0;
  real32_T A_tmp_1;
  real32_T A_tmp_2;
  real32_T A_tmp_tmp;
  real32_T A_tmp_tmp_0;
  A_tmp = (real32_T)sin((real_T)yaw);
  A_tmp_0 = (real32_T)cos((real_T)yaw);
  A_tmp_tmp = (L * 0.5F) * A_tmp_0;
  A_tmp_1 = x + A_tmp_tmp;
  A_tmp_2 = (W * 0.5F) * A_tmp;
  A[0] = A_tmp_1 - A_tmp_2;
  A_tmp_tmp_0 = (L * 0.5F) * A_tmp;
  A_tmp = y + A_tmp_tmp_0;
  A_tmp_0 *= W * 0.5F;
  A[1] = A_tmp + A_tmp_0;
  B[0] = A_tmp_1 + A_tmp_2;
  B[1] = A_tmp - A_tmp_0;
  A_tmp = x - A_tmp_tmp;
  C[0] = A_tmp + A_tmp_2;
  A_tmp_tmp_0 = y - A_tmp_tmp_0;
  C[1] = A_tmp_tmp_0 - A_tmp_0;
  D[0] = A_tmp - A_tmp_2;
  D[1] = A_tmp_tmp_0 + A_tmp_0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
