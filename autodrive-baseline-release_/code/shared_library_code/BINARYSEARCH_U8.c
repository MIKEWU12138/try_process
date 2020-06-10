/*
 * File: BINARYSEARCH_U8.c
 *
 * Code generated for Simulink model 'ACCS_subsystem_integrated'.
 *
 * Model version                  : 1.881
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Jan 19 14:45:10 2020
 */

#include "rtwtypes.h"
#include "BINARYSEARCH_U8.h"

/* Lookup Binary Search Utility BINARYSEARCH_U8 */
void BINARYSEARCH_U8(uint32_T *piLeft, uint32_T *piRght, uint8_T u, const
                     uint8_T *pData, uint32_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] )
  {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  }
  else if (u >= pData[iHi] )
  {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  }
  else
  {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1U )
    {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] )
      {
        *piRght = i;
      }
      else
      {
        *piLeft = i;
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
