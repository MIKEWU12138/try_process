/*
 * File: ALCA_CalcLateralV.c
 *
 * Code generated for Simulink model 'ALCA_subsystem_integrated'.
 *
 * Model version                  : 1.6591
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:34:22 2020
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

#include "ALCA_CalcLateralV.h"

/* Include model header file for global data */
#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"
#include "look1_iflf_binlx.h"
#include "rt_roundf.h"

/* System initialize for atomic system: '<S3>/ALCA_CalcLateralV ' */
void ALCA_sub_ALCA_CalcLateralV_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay3' */
  ALCA_subsystem_integrated_DW.pre_lateral_v = 0.0F;
}

/* System reset for atomic system: '<S3>/ALCA_CalcLateralV ' */
void ALCA_su_ALCA_CalcLateralV_Reset(void)
{
  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay3' */
  ALCA_subsystem_integrated_DW.pre_lateral_v = 0.0F;
}

/* Output and update for atomic system: '<S3>/ALCA_CalcLateralV ' */
real32_T ALCA_subsyste_ALCA_CalcLateralV(boolean_T rtu_request, real32_T
  rtu_v_lon2lane_marker)
{
  static const real_T look_table_k[40] =
  {
    0.049375, 0.0975, 0.144375, 0.19, 0.234375, 0.2775, 0.319375, 0.36, 0.399375,
    0.4375, 0.474375, 0.51, 0.544375, 0.5775, 0.609375, 0.64, 0.669375, 0.6975,
    0.724375, 0.75, 0.774375, 0.7975, 0.819375, 0.84, 0.859375, 0.8775, 0.894375,
    0.91, 0.924375, 0.9375, 0.949375, 0.96, 0.969375, 0.9775, 0.984375, 0.99,
    0.994375, 0.9975, 0.999375, 1.0
  };

  real32_T rtb_Abs;
  real32_T u0;
  real32_T tmp;
  real32_T tmp_0;
  uint16_T y;
  real32_T rty_lateral_v_0;

  /* Abs: '<S7>/Abs' incorporates:
   *  Gain: '<S7>/Gain'
   *  Gain: '<S7>/Gain1'
   *  Sum: '<S7>/Add'
   */
  rtb_Abs = (real32_T)fabs((real_T)((real32_T)((0.9F *
    VfALCA_d_Host2TargetLaneCenter) + (0.1F * VfALCA_d_LateralDist2GoFromLCCS))));

  /* MATLAB Function: '<S7>/CalcLateralV_1' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant3'
   */
  rty_lateral_v_0 = 0.0F;
  if (rtu_request)
  {
    u0 = rt_roundf(rtb_Abs * 10.0F);
    if (u0 < 40.0F)
    {
    }
    else
    {
      u0 = 40.0F;
    }

    if (ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am < rtb_Abs)
    {
      tmp = ALCA_subsystem_integrated_DW.KfALCA_d_LaneWidthMax_a3am;
    }
    else
    {
      tmp = rtb_Abs;
    }

    if (((real_T)VfALCA_t_LCTime) > 0.0001)
    {
      tmp_0 = VfALCA_t_LCTime;
    }
    else
    {
      tmp_0 = 0.0001F;
    }

    if (((int32_T)((uint16_T)((int32_T)u0))) > 1)
    {
      y = (uint16_T)((int32_T)u0);
    }
    else
    {
      y = 1U;
    }

    rty_lateral_v_0 = (tmp / (tmp_0 * 0.679062486F)) * ((real32_T)look_table_k
      [((int32_T)y) - 1]);
    if ((rtb_Abs < KfALCA_d_EnterSecondStageThrsh) && (!(rty_lateral_v_0 <
          KfALCA_v_LateralSpeedOfSecondStage)))
    {
      rty_lateral_v_0 = KfALCA_v_LateralSpeedOfSecondStage;
    }
  }

  /* End of MATLAB Function: '<S7>/CalcLateralV_1' */

  /* Switch: '<S14>/Switch1' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Constant: '<S14>/Constant7'
   *  Product: '<S14>/Product1'
   *  RelationalOperator: '<S14>/Relational Operator1'
   *  Switch: '<S14>/Switch3'
   *  UnitDelay: '<S14>/Unit Delay3'
   */
  if (VfALCA_InterruptAction == ((uint8_T)3U))
  {
    rty_lateral_v_0 = KfALCA_r_OutputLarteralVRatioInterrupt *
      ALCA_subsystem_integrated_DW.pre_lateral_v;
  }
  else if (rtu_request)
  {
    /* Switch: '<S14>/Switch2' incorporates:
     *  Abs: '<S14>/Abs1'
     *  Constant: '<S14>/Constant8'
     *  Lookup_n-D: '<S14>/1-D Lookup Table'
     *  Lookup_n-D: '<S14>/1-D Lookup Table1'
     *  Product: '<S14>/Product'
     *  Switch: '<S14>/Switch3'
     */
    if (KbALCA_EnblCalibrateLateralSpeed)
    {
      rty_lateral_v_0 = look1_iflf_binlx(rtu_v_lon2lane_marker,
        KaALCA_AXIS_VehLonSpeed, KtALCA_v_VComfortable2VLon, 17U) *
        look1_iflf_binlx((real32_T)fabs((real_T)VfALCA_d_Host2TargetLaneCenter),
                         KaALCA_AXIS_LateralDist2Go,
                         KtALCA_r_LateralDist2LateralV, 20U);
    }

    /* End of Switch: '<S14>/Switch2' */
  }
  else
  {
    /* Switch: '<S14>/Switch3' incorporates:
     *  Constant: '<S14>/Constant4'
     */
    rty_lateral_v_0 = 0.0F;
  }

  /* End of Switch: '<S14>/Switch1' */

  /* Update for UnitDelay: '<S14>/Unit Delay3' */
  ALCA_subsystem_integrated_DW.pre_lateral_v = rty_lateral_v_0;
  return rty_lateral_v_0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
