/*
 * File: interp2_q9UVjiL3.c
 *
 * Code generated for Simulink model 'ALCA_subsystem_integrated'.
 *
 * Model version                  : 1.6050
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon May 11 18:14:03 2020
 */

#include "rtwtypes.h"
#include "asr_s32.h"
#include "interp2_q9UVjiL3.h"

/* Function for MATLAB Function: '<S8>/CheckLCODD' */
real32_T interp2_q9UVjiL3(const real32_T varargin_1[15], const real32_T
  varargin_2[8], const real32_T varargin_3[120], real32_T varargin_4, real32_T
  varargin_5)
{
  real32_T Vq;
  int32_T low_i;
  int32_T low_ip1;
  int32_T high_i;
  int32_T b_high_i;
  int32_T b_mid_i;
  real32_T qx1;
  real32_T rx;
  if (varargin_4 >= varargin_1[0])
  {
    if (varargin_4 <= varargin_1[14])
    {
      if (varargin_5 >= varargin_2[0])
      {
        if (varargin_5 <= varargin_2[7])
        {
          low_i = 0;
          low_ip1 = 2;
          high_i = 15;
          while (high_i > low_ip1)
          {
            b_high_i = asr_s32((low_i + high_i) + 1, 1U);
            if (varargin_4 >= varargin_1[b_high_i - 1])
            {
              low_i = b_high_i - 1;
              low_ip1 = b_high_i + 1;
            }
            else
            {
              high_i = b_high_i;
            }
          }

          low_ip1 = 1;
          high_i = 2;
          b_high_i = 8;
          while (b_high_i > high_i)
          {
            b_mid_i = asr_s32(low_ip1 + b_high_i, 1U);
            if (varargin_5 >= varargin_2[b_mid_i - 1])
            {
              low_ip1 = b_mid_i;
              high_i = b_mid_i + 1;
            }
            else
            {
              b_high_i = b_mid_i;
            }
          }

          if (varargin_4 == varargin_1[low_i])
          {
            qx1 = varargin_3[(low_ip1 + (low_i * 8)) - 1];
            Vq = varargin_3[low_ip1 + (low_i * 8)];
          }
          else if (varargin_4 == varargin_1[low_i + 1])
          {
            qx1 = varargin_3[(low_ip1 + ((low_i + 1) * 8)) - 1];
            Vq = varargin_3[low_ip1 + ((low_i + 1) * 8)];
          }
          else
          {
            rx = (varargin_4 - varargin_1[low_i]) / (varargin_1[low_i + 1] -
              varargin_1[low_i]);
            if (varargin_3[(low_ip1 + (low_i * 8)) - 1] == varargin_3[(low_ip1 +
                 ((low_i + 1) * 8)) - 1])
            {
              qx1 = varargin_3[(low_ip1 + (low_i * 8)) - 1];
            }
            else
            {
              qx1 = ((1.0F - rx) * varargin_3[(low_ip1 + (low_i * 8)) - 1]) +
                (rx * varargin_3[(low_ip1 + ((low_i + 1) * 8)) - 1]);
            }

            if (varargin_3[low_ip1 + (low_i * 8)] == varargin_3[low_ip1 +
                ((low_i + 1) * 8)])
            {
              Vq = varargin_3[low_ip1 + (low_i * 8)];
            }
            else
            {
              Vq = ((1.0F - rx) * varargin_3[low_ip1 + (low_i * 8)]) + (rx *
                varargin_3[low_ip1 + ((low_i + 1) * 8)]);
            }
          }

          if (varargin_5 == varargin_2[low_ip1 - 1])
          {
            Vq = qx1;
          }
          else if (qx1 == Vq)
          {
            Vq = qx1;
          }
          else if (varargin_5 == varargin_2[low_ip1])
          {
          }
          else
          {
            rx = (varargin_5 - varargin_2[low_ip1 - 1]) / (varargin_2[low_ip1] -
              varargin_2[low_ip1 - 1]);
            Vq = ((1.0F - rx) * qx1) + (rx * Vq);
          }
        }
        else
        {
          Vq = 0.0F;
        }
      }
      else
      {
        Vq = 0.0F;
      }
    }
    else
    {
      Vq = 0.0F;
    }
  }
  else
  {
    Vq = 0.0F;
  }

  return Vq;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
