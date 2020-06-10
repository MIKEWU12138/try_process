/*
 * File: repos_fcn_xpArvFer.c
 *
 * Code generated for Simulink model 'LCWS_subsystem_integrated'.
 *
 * Model version                  : 1.362
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Mar 19 16:42:29 2020
 */

#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "norm_TbqwX7rn.h"
#include "repos_fcn_xpArvFer.h"

/* Function for MATLAB Function: '<S22>/CvrtObtVecFunction' */
void repos_fcn_xpArvFer(uint16_T num_L, uint16_T num_R, real32_T curve, const
  real32_T vec_L[220], const real32_T vec_R[220], real32_T vec_L_out_data[],
  int32_T vec_L_out_size[2], real32_T vec_R_out_data[], int32_T vec_R_out_size[2])
{
  real32_T len1;
  real32_T O[2];
  real32_T len2;
  real32_T angle;
  uint16_T i;
  int32_T loop_ub;
  int32_T i_0;
  int32_T loop_ub_0;
  real32_T O_0;
  int32_T i_1;
  real32_T tmp;
  vec_L_out_size[0] = (int32_T)num_L;
  vec_L_out_size[1] = 11;
  loop_ub = ((int32_T)num_L) * 11;
  if (0 <= (loop_ub - 1))
  {
    memset(&vec_L_out_data[0], 0, ((uint32_T)loop_ub) * (sizeof(real32_T)));
  }

  vec_R_out_size[0] = (int32_T)num_R;
  vec_R_out_size[1] = 11;
  loop_ub = ((int32_T)num_R) * 11;
  if (0 <= (loop_ub - 1))
  {
    memset(&vec_R_out_data[0], 0, ((uint32_T)loop_ub) * (sizeof(real32_T)));
  }

  if (1 > ((int32_T)num_L))
  {
    i_1 = 0;
  }
  else
  {
    i_1 = (int32_T)num_L;
  }

  loop_ub = i_1 - 1;
  if (1 > ((int32_T)num_R))
  {
    i_1 = 0;
  }
  else
  {
    i_1 = (int32_T)num_R;
  }

  loop_ub_0 = i_1 - 1;
  for (i_1 = 0; i_1 < 11; i_1++)
  {
    for (i_0 = 0; i_0 <= loop_ub; i_0++)
    {
      vec_L_out_data[i_0 + (((int32_T)num_L) * i_1)] = vec_L[i_0 + (20 * i_1)];
    }

    for (i_0 = 0; i_0 <= loop_ub_0; i_0++)
    {
      vec_R_out_data[i_0 + (((int32_T)num_R) * i_1)] = vec_R[i_0 + (20 * i_1)];
    }
  }

  if (((real_T)((real32_T)fabs((real_T)curve))) > 0.001)
  {
    for (i = 1U; i <= num_L; i = (uint16_T)(((uint32_T)i) + 1U))
    {
      len1 = 1.0F / curve;
      O[0] = vec_L[((int32_T)i) + 19];
      O_0 = vec_L[((int32_T)i) + 39] - len1;
      O[1] = O_0;
      len2 = norm_TbqwX7rn(O);
      angle = 0.0F;
      if (((real_T)((real32_T)(((real32_T)fabs((real_T)len1)) * len2))) > 0.0001)
      {
        angle = (real32_T)acos((real_T)((real32_T)((((-len1) * O_0) / ((real32_T)
          fabs((real_T)len1))) / len2)));
      }

      if ((((real_T)angle) > 0.001) && (vec_L[((int32_T)i) + 19] < 0.0F))
      {
        vec_L_out_data[(((int32_T)i) + ((int32_T)num_L)) - 1] = (-angle) *
          ((real32_T)fabs((real_T)len2));
        vec_L_out_data[(((int32_T)i) + ((int32_T)((uint32_T)(((uint32_T)num_L) <<
          1)))) - 1] = ((real32_T)fabs((real_T)len1)) - len2;
        loop_ub = (((int32_T)i) + (((int32_T)num_L) * 3)) - 1;
        vec_L_out_data[loop_ub] = vec_L[((int32_T)i) + 59] + angle;
        if (curve < 0.0F)
        {
          vec_L_out_data[(((int32_T)i) + ((int32_T)((uint32_T)(((uint32_T)num_L)
            << 1)))) - 1] = len2 - ((real32_T)fabs((real_T)len1));
          vec_L_out_data[loop_ub] = vec_L[((int32_T)i) + 59] - angle;
        }
      }
    }

    for (i = 1U; i <= num_R; i = (uint16_T)(((uint32_T)i) + 1U))
    {
      len1 = 1.0F / curve;
      O[0] = vec_R[((int32_T)i) + 19];
      O_0 = vec_R[((int32_T)i) + 39] - len1;
      O[1] = O_0;
      len2 = norm_TbqwX7rn(O);
      angle = 0.0F;
      tmp = (real32_T)fabs((real_T)len1);
      if (((real_T)((real32_T)(tmp * len2))) > 0.0001)
      {
        angle = (real32_T)acos((real_T)((real32_T)((((-len1) * O_0) / tmp) /
          len2)));
      }

      if ((((real_T)angle) > 0.001) && (vec_R[((int32_T)i) + 19] < 0.0F))
      {
        vec_R_out_data[(((int32_T)i) + ((int32_T)num_R)) - 1] = (-angle) *
          ((real32_T)fabs((real_T)len2));
        vec_R_out_data[(((int32_T)i) + ((int32_T)((uint32_T)(((uint32_T)num_R) <<
          1)))) - 1] = tmp - len2;
        loop_ub = ((int32_T)i) + 59;
        vec_R_out_data[(((int32_T)i) + (((int32_T)num_R) * 3)) - 1] =
          vec_R[loop_ub] + angle;
        if (curve < 0.0F)
        {
          vec_R_out_data[(((int32_T)i) + ((int32_T)((uint32_T)(((uint32_T)num_R)
            << 1)))) - 1] = len2 - tmp;
          vec_L_out_data[(((int32_T)i) + (((int32_T)num_L) * 3)) - 1] =
            vec_L[loop_ub] - angle;
        }
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
