/*
 * File: rtGetNaN.c
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.1804
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Mar 19 23:33:55 2020
 */

/*
 * Abstract:
 *      Function to initialize non-finite, NaN
 */
#include "rtGetNaN.h"
#define NumBitsPerChar                 8U

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U)
  {
    nan = rtGetNaNF();
  }
  else
  {
    union
    {
      LittleEndianIEEEDouble bitVal;
      real_T fltVal;
    }
    tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF80000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
real32_T rtGetNaNF(void)
{
  IEEESingle nanF =
  {
    {
      0
    }
  };

  nanF.wordL.wordLuint = 0xFFC00000U;
  return nanF.wordL.wordLreal;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
