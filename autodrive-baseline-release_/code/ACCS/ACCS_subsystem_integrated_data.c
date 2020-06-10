/*
 * File: ACCS_subsystem_integrated_data.c
 *
 * Code generated for Simulink model 'ACCS_subsystem_integrated'.
 *
 * Model version                  : 1.1217
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:55:27 2020
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

#include "ACCS_subsystem_integrated.h"
#include "ACCS_subsystem_integrated_private.h"

/* Invariant block signals (auto storage) */
const ConstB_ACCS_subsystem_integra_T ACCS_subsystem_integrate_ConstB =
{
  1.5707963267948966,                  /* '<S44>/Gain1' */
  1.5707963267948966,                  /* '<S45>/Gain' */
  1.5707963267948966,                  /* '<S45>/Gain2' */
  1.5707963267948966,                  /* '<S68>/Gain1' */
  1.5707963267948966,                  /* '<S75>/Gain1' */
  1.5707963267948966,                  /* '<S82>/Gain1' */
  1.5707963267948966,                  /* '<S83>/Gain' */
  1.5707963267948966,                  /* '<S83>/Gain2' */
  1.5707963267948966,                  /* '<S69>/Gain' */
  1.5707963267948966,                  /* '<S69>/Gain2' */
  1.5707963267948966,                  /* '<S76>/Gain' */
  1.5707963267948966,                  /* '<S76>/Gain2' */
  1.5707963267948966,                  /* '<S89>/Gain1' */
  1.5707963267948966,                  /* '<S90>/Gain' */
  1.5707963267948966,                  /* '<S90>/Gain2' */
  1.5707963267948966,                  /* '<S96>/Gain1' */
  1.5707963267948966,                  /* '<S97>/Gain' */
  1.5707963267948966,                  /* '<S97>/Gain2' */
  0.0F,                                /* '<S106>/Sum2' */
  0.0F,                                /* '<S131>/Constant' */
  0.0F,                                /* '<S131>/Constant1' */
  0.0F,                                /* '<S131>/Constant2' */
  0.0F,                                /* '<S131>/Constant3' */
  0.0F,                                /* '<S131>/Constant4' */
  0.0F,                                /* '<S130>/Constant' */
  0.0F,                                /* '<S130>/Constant1' */
  0.0F,                                /* '<S105>/Sum3' */
  0.0F,                                /* '<S128>/Constant' */
  0.0F,                                /* '<S128>/Constant1' */
  0.0F,                                /* '<S127>/Constant' */
  0.0F,                                /* '<S127>/Constant1' */
  0.0F,                                /* '<S122>/Constant' */
  0.0F,                                /* '<S122>/Constant1' */
  0.0F,                                /* '<S122>/Constant2' */
  0.0F,                                /* '<S122>/Constant3' */
  0.0F,                                /* '<S121>/Constant' */
  0.0F,                                /* '<S113>/Sum1' */
  0.0F,                                /* '<S113>/Sum2' */
  0.0F,                                /* '<S117>/Constant' */
  0.0F,                                /* '<S116>/Constant' */
  0.0F,                                /* '<S116>/Constant1' */
  0.0F,                                /* '<S116>/Constant2' */
  0.0F,                                /* '<S116>/Constant3' */
  0.0F,                                /* '<S115>/Constant' */
  400.0F,                              /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  400.0F,                              /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  400.0F,                              /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  400.0F,                              /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0.0F,                                /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0.0F,                                /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0.0F,                                /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1.0F,                                /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0.0F,                                /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0.0F,                                /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1.0F,                                /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1.0F,                                /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1.0F,                                /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  16.666666F,                          /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1.0F,                                /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  2.0F,                                /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0.0F,                                /* '<S7>/Constant11' */
  16.666666F,                          /* '<S7>/Constant21' */
  2.0F,                                /* '<S7>/Constant22' */
  400.0F,                              /* '<S7>/Constant30' */
  400.0F,                              /* '<S7>/Constant31' */
  400.0F,                              /* '<S7>/Constant32' */
  400.0F,                              /* '<S7>/Constant33' */
  0.0F,                                /* '<S7>/Constant34' */
  0.0F,                                /* '<S7>/Constant40' */
  1.0F,                                /* '<S7>/Constant45' */
  0.0F,                                /* '<S7>/Constant47' */
  0.0F,                                /* '<S7>/Constant48' */
  1.0F,                                /* '<S7>/Constant51' */
  1.0F,                                /* '<S7>/Constant55' */
  1.0F,                                /* '<S7>/Constant57' */
  1.0F,                                /* '<S7>/Constant61' */
  0U,                                  /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0U,                                  /* '<S7>/Constant29' */
  0,                                   /* '<S37>/Logical Operator' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  1,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0,                                   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  0,                                   /* '<S34>/Logical Operator3' */
  0,                                   /* '<S34>/Logical Operator2' */
  0,                                   /* '<S34>/Logical Operator4' */
  0,                                   /* '<S7>/Constant19' */
  0,                                   /* '<S7>/Constant20' */
  1,                                   /* '<S7>/Constant23' */
  1,                                   /* '<S7>/Constant25' */
  0,                                   /* '<S7>/Constant26' */
  1,                                   /* '<S7>/Constant27' */
  1,                                   /* '<S7>/Constant35' */
  0,                                   /* '<S7>/Constant36' */
  1,                                   /* '<S7>/Constant37' */
  0,                                   /* '<S7>/Constant38' */
  0,                                   /* '<S7>/Constant39' */
  1,                                   /* '<S7>/Constant50' */
  1,                                   /* '<S7>/Constant52' */
  1,                                   /* '<S7>/Constant53' */
  1,                                   /* '<S7>/Constant54' */
  1,                                   /* '<S7>/Constant56' */
  1,                                   /* '<S7>/Constant58' */
  1,                                   /* '<S7>/Constant59' */
  1,                                   /* '<S7>/Constant60' */
  1,                                   /* '<S7>/Constant62' */
  1                                    /* '<S7>/Constant64' */
};

/* Constant parameters (auto storage) */
const ConstP_ACCS_subsystem_integra_T ACCS_subsystem_integrate_ConstP =
{
  /* Computed Parameter: KaACCS_t_TimeGapFrmDriver_bp01D
   * Referenced by: '<S34>/KaACCS_t_TimeGapFrmDriver'
   */
  {
    1.0F, 2.0F, 3.0F, 4.0F
  },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl'
   *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl1'
   */
  {
    8U, 6U
  },

  /* Computed Parameter: KtACCS_d_CIPVTargtRange_maxInde
   * Referenced by: '<S34>/KtACCS_d_CIPVTargtRange'
   */
  {
    9U, 3U
  },

  /* Computed Parameter: KtACCS_r_DCSNStopDistanceGain_m
   * Referenced by: '<S103>/KtACCS_r_DCSNStopDistanceGain '
   */
  {
    12U, 10U
  },

  /* Computed Parameter: KtACCS_r_DCSNStopSpdGain_maxInd
   * Referenced by: '<S103>/KtACCS_r_DCSNStopSpdGain'
   */
  {
    10U, 10U
  },

  /* Computed Parameter: KtACCS_r_TorqCtrlProp_maxIndex
   * Referenced by: '<S123>/KtACCS_r_TorqCtrlProp '
   */
  {
    8U, 9U
  },

  /* Computed Parameter: KtACCS_Pct_AccelToGasPedal_maxI
   * Referenced by: '<S114>/KtACCS_Pct_AccelToGasPedal '
   */
  {
    9U, 16U
  },

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S129>/KtACCS_r_RangeCtrlPGain '
   *   '<S129>/KtACCS_r_RangeCtrlPGain 1'
   *   '<S132>/KtACCS_r_SpeedCtrlPGain'
   *   '<S132>/KtACCS_r_SpeedCtrlPGain1'
   */
  {
    9U, 8U
  }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
