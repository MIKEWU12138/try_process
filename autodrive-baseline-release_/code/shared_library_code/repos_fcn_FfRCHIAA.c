/*
 * File: repos_fcn_FfRCHIAA.c
 *
 * Code generated for Simulink model 'LCAS_subsystem_integrated'.
 *
 * Model version                  : 1.428
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sat May  9 18:26:15 2020
 */

#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "norm_TbqwX7rn.h"
#include "repos_fcn_FfRCHIAA.h"

/* Function for MATLAB Function: '<S20>/CvrtObtVecFunction' */
void repos_fcn_FfRCHIAA(uint16_T num_L, uint16_T num_R, real32_T curve, const
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
  real32_T tmp;
  int32_T vec_R_out_data_tmp;
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
    vec_R_out_data_tmp = 0;
  }
  else
  {
    vec_R_out_data_tmp = (int32_T)num_L;
  }

  loop_ub = vec_R_out_data_tmp - 1;
  if (1 > ((int32_T)num_R))
  {
    vec_R_out_data_tmp = 0;
  }
  else
  {
    vec_R_out_data_tmp = (int32_T)num_R;
  }

  loop_ub_0 = vec_R_out_data_tmp - 1;
  for (vec_R_out_data_tmp = 0; vec_R_out_data_tmp < 11; vec_R_out_data_tmp++)
  {
    for (i_0 = 0; i_0 <= loop_ub; i_0++)
    {
      vec_L_out_data[i_0 + (((int32_T)num_L) * vec_R_out_data_tmp)] = vec_L[i_0
        + (20 * vec_R_out_data_tmp)];
    }

    for (i_0 = 0; i_0 <= loop_ub_0; i_0++)
    {
      vec_R_out_data[i_0 + (((int32_T)num_R) * vec_R_out_data_tmp)] = vec_R[i_0
        + (20 * vec_R_out_data_tmp)];
    }
  }

  if (((real_T)((real32_T)fabs((real_T)curve))) > 0.001)
  {
    for (i = 1U; i <= num_L; i = (uint16_T)(((uint32_T)i) + 1U))
    {
      len1 = 1.0F / curve;
      O[0] = vec_L[((int32_T)i) + 159];
      O_0 = vec_L[((int32_T)i) + 179] - len1;
      O[1] = O_0;
      len2 = norm_TbqwX7rn(O);
      angle = 0.0F;
      if (((real_T)((real32_T)(((real32_T)fabs((real_T)len1)) * len2))) > 0.0001)
      {
        angle = (real32_T)acos((real_T)((real32_T)((((-len1) * O_0) / ((real32_T)
          fabs((real_T)len1))) / len2)));
      }

      if ((((real_T)angle) > 0.001) && (vec_L[((int32_T)i) + 159] < 0.0F))
      {
        vec_L_out_data[(((int32_T)i) + ((int32_T)((uint32_T)(((uint32_T)num_L) <<
          3)))) - 1] = (-angle) * ((real32_T)fabs((real_T)len2));
        loop_ub = (((int32_T)i) + (((int32_T)num_L) * 9)) - 1;
        vec_L_out_data[loop_ub] = ((real32_T)fabs((real_T)len1)) - len2;
        vec_R_out_data_tmp = (((int32_T)i) + (((int32_T)num_L) * 3)) - 1;
        vec_L_out_data[vec_R_out_data_tmp] = vec_L[((int32_T)i) + 59] + angle;
        if (curve < 0.0F)
        {
          vec_L_out_data[loop_ub] = len2 - ((real32_T)fabs((real_T)len1));
          vec_L_out_data[vec_R_out_data_tmp] = vec_L[((int32_T)i) + 59] - angle;
        }
      }
    }

    for (i = 1U; i <= num_R; i = (uint16_T)(((uint32_T)i) + 1U))
    {
      len1 = 1.0F / curve;
      O[0] = vec_R[((int32_T)i) + 159];
      O_0 = vec_R[((int32_T)i) + 179] - len1;
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
        vec_R_out_data[(((int32_T)i) + ((int32_T)((uint32_T)(((uint32_T)num_R) <<
          3)))) - 1] = (-angle) * ((real32_T)fabs((real_T)len2));
        loop_ub = (((int32_T)i) + (((int32_T)num_R) * 9)) - 1;
        vec_R_out_data[loop_ub] = tmp - len2;
        vec_R_out_data_tmp = ((int32_T)i) + 59;
        vec_R_out_data[(((int32_T)i) + (((int32_T)num_R) * 3)) - 1] =
          vec_R[vec_R_out_data_tmp] + angle;
        if (curve < 0.0F)
        {
          vec_R_out_data[loop_ub] = len2 - tmp;
          vec_L_out_data[(((int32_T)i) + (((int32_T)num_L) * 3)) - 1] =
            vec_L[vec_R_out_data_tmp] - angle;
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
