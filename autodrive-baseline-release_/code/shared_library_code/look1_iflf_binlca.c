/*
 * File: look1_iflf_binlca.c
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.1920
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Apr  9 17:53:30 2020
 */

#include "rtwtypes.h"
#include "look1_iflf_binlca.h"

real32_T look1_iflf_binlca(real32_T u0, const real32_T bp0[], const real32_T
  table[], uint32_T maxIndex)
{
  real32_T y;
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U])
  {
    iLeft = 0U;
    frac = 0.0F;
  }
  else if (u0 < bp0[maxIndex])
  {
    /* Binary Search */
    bpIdx = (maxIndex >> 1U);
    iLeft = 0U;
    iRght = maxIndex;
    while ((iRght - iLeft) > 1U)
    {
      if (u0 < bp0[bpIdx])
      {
        iRght = bpIdx;
      }
      else
      {
        iLeft = bpIdx;
      }

      bpIdx = ((iRght + iLeft) >> 1U);
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  }
  else
  {
    iLeft = maxIndex;
    frac = 0.0F;
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'wrapping'
   */
  if (iLeft == maxIndex)
  {
    y = table[iLeft];
  }
  else
  {
    y = ((table[iLeft + 1U] - table[iLeft]) * frac) + table[iLeft];
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
