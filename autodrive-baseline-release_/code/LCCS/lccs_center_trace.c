/*
 * File: lccs_center_trace.c
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.2176
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 09:42:58 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Infineon->TriCore
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. Safety precaution
 *    3. Execution efficiency
 *    4. RAM efficiency
 *    5. ROM efficiency
 * Validation result: Not run
 */

#include "lccs_center_trace.h"

/* Include model header file for global data */
#include "LCCS_subsystem_integrated.h"
#include "LCCS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S2>/CalcLCCS_lane_center_discretize' */
void CalcLCCS_lane_center_discretize(void)
{
  real32_T x_interval;
  real32_T x_RearAxle;
  real32_T x_Camera_square;
  int32_T i;

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Constant: '<S5>/KfLCCS_d_RearAxleToCameraOrigin'
   */
  memset(&LCCS_subsystem_integrated_B.lane_center_points[0], 0, 160U * (sizeof
          (real32_T)));
  x_RearAxle = 0.1F * VfLCCS_linear_velocity;
  x_interval = VfLCCS_lookahead_distance / 79.0F;
  if ((x_RearAxle > x_interval) || (rtIsNaNF(x_interval)))
  {
    x_interval = x_RearAxle;
  }

  for (i = 0; i < 80; i++)
  {
    x_RearAxle = ((1.0F + ((real32_T)i)) - 1.0F) * x_interval;
    LCCS_subsystem_integrated_B.lane_center_points[i] = x_RearAxle;
    x_RearAxle -= KfLCCS_d_RearAxleToCameraOrigin;
    x_Camera_square = x_RearAxle * x_RearAxle;
    LCCS_subsystem_integrated_B.lane_center_points[80 + i] =
      ((VaLCCS_shifted_lane_center_line[0] + (VaLCCS_shifted_lane_center_line[1]
         * x_RearAxle)) + (VaLCCS_shifted_lane_center_line[2] * x_Camera_square))
      + ((VaLCCS_shifted_lane_center_line[3] * x_Camera_square) * x_RearAxle);
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
