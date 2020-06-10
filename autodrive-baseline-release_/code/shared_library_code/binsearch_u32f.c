/*
 * File: binsearch_u32f.c
 *
 * Code generated for Simulink model 'DCSN_subsystem_integrated'.
 *
 * Model version                  : 1.602
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:32:03 2020
 */

#include "rtwtypes.h"
#include "binsearch_u32f.h"

uint32_T binsearch_u32f(real32_T u, const real32_T bp[], uint32_T startIndex,
  uint32_T maxIndex)
{
  uint32_T bpIndex;
  uint32_T iRght;
  uint32_T bpIdx;

  /* Binary Search */
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while ((iRght - bpIndex) > 1U)
  {
    if (u < bp[bpIdx])
    {
      iRght = bpIdx;
    }
    else
    {
      bpIndex = bpIdx;
    }

    bpIdx = ((iRght + bpIndex) >> 1U);
  }

  return bpIndex;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
