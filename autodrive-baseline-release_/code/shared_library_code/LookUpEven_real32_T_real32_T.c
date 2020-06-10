/*
 * File: LookUpEven_real32_T_real32_T.c
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.1918
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Apr  9 15:15:37 2020
 */

#include "rtwtypes.h"
#include "LookUpEven_real32_T_real32_T.h"

/* Lookup 1D UtilityLookUpEven_real32_T_real32_T */
void LookUpEven_real32_T_real32_T(real32_T *pY, const real32_T *pYData, real32_T
  u, real32_T valueLo, uint32_T iHi, real32_T uSpacing)
{
  if (u <= valueLo )
  {
    (*pY) = (*pYData);
  }
  else
  {
    real32_T uAdjusted = u - valueLo;
    real32_T tmpIdxLeft = uAdjusted / uSpacing;
    uint32_T iLeft = (uint32_T)tmpIdxLeft;
    if ((tmpIdxLeft >= 4294967296.0f) || (iLeft >= iHi) )
    {
      (*pY) = pYData[iHi];
    }
    else
    {
      {
        real32_T lambda;

        {
          real32_T num = (real32_T)uAdjusted - ( iLeft * uSpacing );
          lambda = num / uSpacing;
        }

        {
          real32_T yLeftCast;
          real32_T yRghtCast;
          yLeftCast = pYData[iLeft];
          yRghtCast = pYData[((iLeft)+1)];
          yLeftCast += lambda * ( yRghtCast - yLeftCast );
          (*pY) = yLeftCast;
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
