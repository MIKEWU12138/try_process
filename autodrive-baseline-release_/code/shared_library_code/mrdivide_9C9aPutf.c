/*
 * File: mrdivide_9C9aPutf.c
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.1804
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Thu Mar 19 23:33:55 2020
 */

#include "rtwtypes.h"
#include <math.h>
#include <string.h>
#include "mrdivide_9C9aPutf.h"

/* Function for MATLAB Function: '<S53>/UpdateMatrixA' */
void mrdivide_9C9aPutf(real32_T A[16], const real32_T B[16])
{
  real32_T b_A[16];
  int8_T ipiv[4];
  int32_T j;
  int32_T ix;
  real32_T smax;
  real32_T s;
  int32_T iy;
  int32_T c_ix;
  int32_T d;
  int32_T ijA;
  int32_T jBcol;
  int32_T kBcol;
  memcpy(&b_A[0], &B[0], (sizeof(real32_T)) << 4U);
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  for (j = 0; j < 3; j++)
  {
    jBcol = j * 5;
    iy = 0;
    ix = jBcol;
    smax = (real32_T)fabs((real_T)b_A[jBcol]);
    for (kBcol = 2; kBcol <= (4 - j); kBcol++)
    {
      ix++;
      s = (real32_T)fabs((real_T)b_A[ix]);
      if (s > smax)
      {
        iy = kBcol - 1;
        smax = s;
      }
    }

    if (b_A[jBcol + iy] != 0.0F)
    {
      if (iy != 0)
      {
        iy += j;
        ipiv[j] = (int8_T)(iy + 1);
        smax = b_A[j];
        b_A[j] = b_A[iy];
        b_A[iy] = smax;
        ix = j + 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
        ix += 4;
        iy += 4;
        smax = b_A[ix];
        b_A[ix] = b_A[iy];
        b_A[iy] = smax;
      }

      iy = (jBcol - j) + 4;
      for (ix = jBcol + 1; (ix + 1) <= iy; ix++)
      {
        b_A[ix] /= b_A[jBcol];
      }
    }

    iy = jBcol;
    ix = jBcol + 4;
    for (kBcol = 1; kBcol <= (3 - j); kBcol++)
    {
      smax = b_A[ix];
      if (b_A[ix] != 0.0F)
      {
        c_ix = jBcol + 1;
        d = (iy - j) + 8;
        for (ijA = 5 + iy; (ijA + 1) <= d; ijA++)
        {
          b_A[ijA] += b_A[c_ix] * (-smax);
          c_ix++;
        }
      }

      ix += 4;
      iy += 4;
    }
  }

  for (j = 0; j < 4; j++)
  {
    jBcol = j * 4;
    iy = j * 4;
    for (ix = 1; ix <= j; ix++)
    {
      kBcol = (ix - 1) * 4;
      if (b_A[(ix + iy) - 1] != 0.0F)
      {
        A[jBcol] -= b_A[(ix + iy) - 1] * A[kBcol];
        A[1 + jBcol] -= b_A[(ix + iy) - 1] * A[1 + kBcol];
        A[2 + jBcol] -= b_A[(ix + iy) - 1] * A[2 + kBcol];
        A[3 + jBcol] -= b_A[(ix + iy) - 1] * A[3 + kBcol];
      }
    }

    smax = 1.0F / b_A[j + iy];
    A[jBcol] *= smax;
    A[1 + jBcol] *= smax;
    A[2 + jBcol] *= smax;
    A[3 + jBcol] *= smax;
  }

  for (j = 3; j >= 0; j--)
  {
    jBcol = j * 4;
    iy = (j * 4) - 1;
    for (ix = j + 2; ix < 5; ix++)
    {
      kBcol = (ix - 1) * 4;
      if (b_A[ix + iy] != 0.0F)
      {
        A[jBcol] -= b_A[ix + iy] * A[kBcol];
        A[1 + jBcol] -= b_A[ix + iy] * A[1 + kBcol];
        A[2 + jBcol] -= b_A[ix + iy] * A[2 + kBcol];
        A[3 + jBcol] -= b_A[ix + iy] * A[3 + kBcol];
      }
    }
  }

  for (j = 2; j >= 0; j--)
  {
    if (((int32_T)ipiv[j]) != (j + 1))
    {
      jBcol = ((int32_T)ipiv[j]) - 1;
      smax = A[j * 4];
      A[j * 4] = A[jBcol * 4];
      A[jBcol * 4] = smax;
      smax = A[1 + (j * 4)];
      A[1 + (j * 4)] = A[1 + (jBcol * 4)];
      A[1 + (jBcol * 4)] = smax;
      smax = A[2 + (j * 4)];
      A[2 + (j * 4)] = A[2 + (jBcol * 4)];
      A[2 + (jBcol * 4)] = smax;
      smax = A[3 + (j * 4)];
      A[3 + (j * 4)] = A[3 + (jBcol * 4)];
      A[3 + (jBcol * 4)] = smax;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
