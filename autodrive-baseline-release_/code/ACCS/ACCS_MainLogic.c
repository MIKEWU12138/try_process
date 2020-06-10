/*
 * File: ACCS_MainLogic.c
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

#include "ACCS_MainLogic.h"

/* Include model header file for global data */
#include "ACCS_subsystem_integrated.h"
#include "ACCS_subsystem_integrated_private.h"
#include "LookUp_real32_T_real32_T.h"
#include "look1_iflf_binlc.h"
#include "look1_iflf_binlx.h"
#include "look2_iflf_binlc.h"
#include "look2_iflf_binlx.h"

/* Named constants for Chart: '<S137>/DtrmnACCS_ModeStateTransfer' */
#define ACCS_su_IN_NO_ACTIVE_CHILD_b1sk ((uint8_T)0U)
#define ACCS_subsy_IN_ACCS_Mode_standby ((uint8_T)4U)
#define ACCS_subsyst_IN_ACCS_Mode_fault ((uint8_T)1U)
#define ACCS_subsystem_IN_ACCS_Mode_off ((uint8_T)2U)
#define ACCS_subsystem__IN_ACCS_Mode_on ((uint8_T)3U)

/* Named constants for Chart: '<S138>/DtrmnACCS_RunStatusTransfer' */
#define ACCS_IN_ACCS_Runstatus_LowSpeed ((uint8_T)3U)
#define ACCS_IN_ACCS_Runstatus_TempStop ((uint8_T)6U)
#define ACCS__IN_ACCS_Runstatus_Standby ((uint8_T)2U)
#define ACCS_s_IN_ACCS_Runstatus_Launch ((uint8_T)2U)
#define ACCS_su_IN_NO_ACTIVE_CHILD_kuby ((uint8_T)0U)
#define ACCS_sub_IN_ACCS_Runstatus_Stop ((uint8_T)5U)
#define ACCS_subsy_IN_ACCS_Runstatus_on ((uint8_T)7U)
#define ACC_IN_ACCS_ModeAndRunStatus_on ((uint8_T)1U)
#define ACC_IN_ACCS_Runstatus_SpeedCtrl ((uint8_T)4U)
#define IN_ACCS_Runstatus_FollowingCtrl ((uint8_T)1U)

/* Named constants for Chart: '<S155>/DtrmnACCS_WhetherPressGasPedal' */
#define ACCS_s_IN_Driver_Press_GasPedal ((uint8_T)1U)
#define ACCS_su_IN_NO_ACTIVE_CHILD_dinm ((uint8_T)0U)
#define ACCS_subsystem_inte_IN_GasPedal ((uint8_T)2U)

/* Named constants for Chart: '<S155>/DtrmnACCS_WhetherPressResume' */
#define ACCS_su_IN_Driver_NoPressResume ((uint8_T)1U)
#define ACCS_subsy_IN_Driver_PressResum ((uint8_T)2U)

/* Forward declaration for local functions */
static void ACCS_su_ACCS_Runstatus_TempStop(void);
static void ACCS_s_ACCS_ModeAndRunStatus_on(void);

/* Output and update for atomic system: '<S13>/CalcACCS_EgoVehicleTargetSpeed' */
void CalcACCS_EgoVehicleTargetSpeed(void)
{
  real32_T u0;

  /* If: '<S17>/If1' incorporates:
   *  Constant: '<S17>/Constant38'
   *  Constant: '<S17>/Constant41'
   *  Constant: '<S17>/Constant8'
   *  RelationalOperator: '<S17>/Relational Operator'
   *  RelationalOperator: '<S17>/Relational Operator1'
   *  RelationalOperator: '<S17>/Relational Operator10'
   *  SignalConversion: '<S20>/Signal Conversion'
   *  SignalConversion: '<S22>/Signal Conversion'
   */
  if (VeACCS_RunStatus == ACCS_status_FollowingCtrl)
  {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
     *  ActionPort: '<S20>/Action Port'
     */
    u0 = VfACCS_Input_Obs_LinearVelocity;

    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */
  }
  else if (VeACCS_RunStatus == ACCS_status_LowSpeed)
  {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S23>/Action Port'
     */
    /* Switch: '<S23>/Switch' */
    if (VbACCS_Input_Obs_valid)
    {
      u0 = VfACCS_Input_Obs_LinearVelocity;
    }
    else
    {
      u0 = ACCS_subsystem_integrated_B.CalDriverSetSpeed;
    }

    /* End of Switch: '<S23>/Switch' */
    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem4' */
  }
  else if (VeACCS_RunStatus == ACCS_status_Launch)
  {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S21>/Action Port'
     */
    /* Switch: '<S21>/Switch' */
    if (VbACCS_Input_Obs_valid)
    {
      u0 = VfACCS_Input_Obs_LinearVelocity;
    }
    else
    {
      u0 = ACCS_subsystem_integrated_B.CalDriverSetSpeed;
    }

    /* End of Switch: '<S21>/Switch' */
    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem1' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S22>/Action Port'
     */
    u0 = ACCS_subsystem_integrated_B.CalDriverSetSpeed;

    /* End of Outputs for SubSystem: '<S17>/If Action Subsystem3' */
  }

  /* End of If: '<S17>/If1' */

  /* MinMax: '<S17>/Min' */
  if (u0 < VfACCS_FinalSpeedLimit)
  {
  }
  else
  {
    u0 = VfACCS_FinalSpeedLimit;
  }

  /* End of MinMax: '<S17>/Min' */

  /* Saturate: '<S17>/Saturation' */
  if (u0 > kfACCS_v_TargetVehicleSpeedHi)
  {
    VfACCS_VehSpeed_Tar = kfACCS_v_TargetVehicleSpeedHi;
  }
  else if (u0 < kfACCS_v_TargetVehicleSpeedLo)
  {
    VfACCS_VehSpeed_Tar = kfACCS_v_TargetVehicleSpeedLo;
  }
  else
  {
    VfACCS_VehSpeed_Tar = u0;
  }

  /* End of Saturate: '<S17>/Saturation' */
}

/* Output and update for atomic system: '<S13>/CalcACCS_OpenAccel' */
void CalcACCS_OpenAccel(void)
{
  /* local block i/o variables */
  real32_T rtb_Product3;
  real32_T rtb_VfACCS_CalOpenAccel_CIPV;
  real32_T rtb_Add;
  real32_T rtb_Subtract1_fycv;
  real32_T rtb_Subtract1;
  real_T u0;

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Constant6'
   */
  if (VbACCS_Input_Obs_valid)
  {
    /* Sum: '<S18>/Subtract2' */
    rtb_Add = VfACCS_Input_Obs_Range - VfACCS_DriverTargetRange;

    /* MinMax: '<S18>/Min' incorporates:
     *  Constant: '<S18>/Constant1'
     */
    if (rtb_Add < KfACCS_d_RangePIDCtrl_RangeErrlimit)
    {
    }
    else
    {
      rtb_Add = KfACCS_d_RangePIDCtrl_RangeErrlimit;
    }

    /* End of MinMax: '<S18>/Min' */

    /* Product: '<S18>/Product' incorporates:
     *  Constant: '<S18>/Constant1'
     *  Constant: '<S18>/Constant2'
     */
    rtb_VfACCS_CalOpenAccel_CIPV = KfACCS_d_RangePIDCtrl_RangeErrlimit * (-1.0F);

    /* MinMax: '<S18>/max' incorporates:
     *  Product: '<S18>/Product'
     */
    if (rtb_Add > rtb_VfACCS_CalOpenAccel_CIPV)
    {
      ACCS_subsystem_integrated_B.VfACCS_RangeErrLim_CIPV = rtb_Add;
    }
    else
    {
      ACCS_subsystem_integrated_B.VfACCS_RangeErrLim_CIPV =
        rtb_VfACCS_CalOpenAccel_CIPV;
    }

    /* End of MinMax: '<S18>/max' */
  }
  else
  {
    ACCS_subsystem_integrated_B.VfACCS_RangeErrLim_CIPV = 0.0F;
  }

  /* End of Switch: '<S18>/Switch' */

  /* Switch: '<S18>/Switch1' incorporates:
   *  Constant: '<S18>/Constant7'
   */
  if (ACCS_subsystem_integrated_B.SignalConversion1)
  {
    /* Sum: '<S18>/Subtract1' */
    rtb_Add = ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Range_n5rr -
      VfACCS_DriverTargetRange;

    /* MinMax: '<S18>/Min1' incorporates:
     *  Constant: '<S18>/Constant3'
     */
    if (rtb_Add < KfACCS_d_RangePIDCtrl_RangeErrlimit)
    {
    }
    else
    {
      rtb_Add = KfACCS_d_RangePIDCtrl_RangeErrlimit;
    }

    /* End of MinMax: '<S18>/Min1' */

    /* Product: '<S18>/Product1' incorporates:
     *  Constant: '<S18>/Constant3'
     *  Constant: '<S18>/Constant4'
     */
    rtb_VfACCS_CalOpenAccel_CIPV = KfACCS_d_RangePIDCtrl_RangeErrlimit * (-1.0F);

    /* MinMax: '<S18>/max1' incorporates:
     *  Product: '<S18>/Product1'
     */
    if (rtb_Add > rtb_VfACCS_CalOpenAccel_CIPV)
    {
      ACCS_subsystem_integrated_B.VfACCS_RangeErrlim_SIPV = rtb_Add;
    }
    else
    {
      ACCS_subsystem_integrated_B.VfACCS_RangeErrlim_SIPV =
        rtb_VfACCS_CalOpenAccel_CIPV;
    }

    /* End of MinMax: '<S18>/max1' */
  }
  else
  {
    ACCS_subsystem_integrated_B.VfACCS_RangeErrlim_SIPV = 0.0F;
  }

  /* End of Switch: '<S18>/Switch1' */

  /* If: '<S18>/If1' incorporates:
   *  Constant: '<S18>/Constant38'
   *  Constant: '<S18>/Constant41'
   *  Constant: '<S18>/Constant5'
   *  Constant: '<S18>/Constant8'
   *  RelationalOperator: '<S18>/Relational Operator'
   *  RelationalOperator: '<S18>/Relational Operator1'
   *  RelationalOperator: '<S18>/Relational Operator10'
   *  RelationalOperator: '<S18>/Relational Operator3'
   */
  if (VeACCS_RunStatus == ACCS_status_FollowingCtrl)
  {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* Lookup_n-D: '<S24>/KtACCS_a_OpenAccel_FollowCtrl' */
    rtb_VfACCS_CalOpenAccel_CIPV = look2_iflf_binlc
      (ACCS_subsystem_integrated_B.VfACCS_RangeErrLim_CIPV,
       VfACCS_Input_Obs_Rangerate, KtACCS_AXIS_OpenAccelFwCtrl_RangeErr,
       KtACCS_AXIS_OpenAccelFwCtrl_RR, KtACCS_a_OpenAccel_FollowCtrl,
       ACCS_subsystem_integrate_ConstP.pooled17, 9U);

    /* Switch: '<S24>/Switch' incorporates:
     *  Constant: '<S24>/Constant'
     *  Constant: '<S24>/Constant1'
     *  Logic: '<S24>/Logical Operator'
     *  MinMax: '<S24>/Max1'
     *  Sum: '<S24>/Subtract1'
     *  Sum: '<S24>/Sum'
     *  Switch: '<S24>/Switch1'
     */
    if (!KbACCS_UseCIPVAccelToCalOpenAccel)
    {
      VfACCS_FeedForwardAccel = rtb_VfACCS_CalOpenAccel_CIPV +
        (VfACCS_Input_Obs_LinearAcc -
         ACCS_subsystem_integrated_B.VfACCS_Input_linear_Accele_p235);
    }
    else
    {
      if (VfACCS_Input_Obs_LinearAcc >= 0.0F)
      {
        /* MinMax: '<S24>/Max' incorporates:
         *  Constant: '<S24>/Constant2'
         *  Switch: '<S24>/Switch1'
         */
        if (1.0F > VfACCS_Input_Obs_LinearVelocity)
        {
          rtb_Add = 1.0F;
        }
        else
        {
          rtb_Add = VfACCS_Input_Obs_LinearVelocity;
        }

        /* End of MinMax: '<S24>/Max' */

        /* Product: '<S24>/Divide' incorporates:
         *  Switch: '<S24>/Switch1'
         */
        rtb_Add = (1.0F / rtb_Add) * VfACCS_Input_Obs_Range;

        /* Saturate: '<S24>/Saturation1' incorporates:
         *  Switch: '<S24>/Switch1'
         */
        if (rtb_Add > 150.0F)
        {
          rtb_Add = 150.0F;
        }
        else
        {
          if (rtb_Add < 0.0F)
          {
            rtb_Add = 0.0F;
          }
        }

        /* End of Saturate: '<S24>/Saturation1' */

        /* Switch: '<S24>/Switch1' incorporates:
         *  Lookup_n-D: '<S24>/1-D Lookup Table'
         */
        rtb_Add = look1_iflf_binlc(rtb_Add,
          KtACCS_AXIS_OpenAccelFwCtrl_TimeGapAcc,
          KtACCS_r_OpenAccelFwCtrl_TimeGapAcc, 6U);
      }
      else
      {
        if (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG > 1.0F)
        {
          /* MinMax: '<S24>/Max1' incorporates:
           *  Switch: '<S24>/Switch1'
           */
          rtb_Add = ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG;
        }
        else
        {
          /* MinMax: '<S24>/Max1' incorporates:
           *  Constant: '<S24>/Constant1'
           *  Switch: '<S24>/Switch1'
           */
          rtb_Add = 1.0F;
        }

        /* Product: '<S24>/Divide1' incorporates:
         *  Switch: '<S24>/Switch1'
         */
        rtb_Add = VfACCS_Input_Obs_Range / rtb_Add;

        /* Saturate: '<S24>/Saturation2' incorporates:
         *  Switch: '<S24>/Switch1'
         */
        if (rtb_Add > 150.0F)
        {
          rtb_Add = 150.0F;
        }
        else
        {
          if (rtb_Add < 0.0F)
          {
            rtb_Add = 0.0F;
          }
        }

        /* End of Saturate: '<S24>/Saturation2' */

        /* Switch: '<S24>/Switch1' incorporates:
         *  Lookup_n-D: '<S24>/1-D Lookup Table1'
         */
        rtb_Add = look1_iflf_binlc(rtb_Add,
          KtACCS_AXIS_OpenAccelFwCtrl_TimeGapDec,
          KtACCS_r_OpenAccelFwCtrl_TimeGapDec, 5U);
      }

      /* Sum: '<S24>/Add' incorporates:
       *  Constant: '<S24>/Constant1'
       *  MinMax: '<S24>/Max1'
       *  Product: '<S24>/Product'
       *  Switch: '<S24>/Switch1'
       */
      rtb_Add = (VfACCS_Input_Obs_LinearAcc * rtb_Add) +
        rtb_VfACCS_CalOpenAccel_CIPV;

      /* Saturate: '<S24>/Saturation' */
      if (rtb_Add > 5.0F)
      {
        VfACCS_FeedForwardAccel = 5.0F;
      }
      else if (rtb_Add < (-5.0F))
      {
        VfACCS_FeedForwardAccel = (-5.0F);
      }
      else
      {
        VfACCS_FeedForwardAccel = rtb_Add;
      }

      /* End of Saturate: '<S24>/Saturation' */
    }

    /* End of Switch: '<S24>/Switch' */
    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem' */
  }
  else if (VeACCS_RunStatus == ACCS_status_SpeedCtrl)
  {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* Sum: '<S25>/Subtract1' */
    rtb_Subtract1_fycv = VfACCS_VehSpeed_Tar -
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG;

    /* Lookup: '<S25>/KtACCS_a_OpenAccel_SpeedCtrl' */
    /*
     * About '<S25>/KtACCS_a_OpenAccel_SpeedCtrl':
     * Input0  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(VfACCS_FeedForwardAccel),
      KtACCS_a_OpenAccel_SpeedCtrl, rtb_Subtract1_fycv,
      KtACCS_AXIS_OpenAccelSpedCtrl_SpedErr, 6U);

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem1' */
  }
  else if (VeACCS_RunStatus == ACCS_status_LowSpeed)
  {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* Sum: '<S27>/Subtract1' */
    rtb_Subtract1 = VfACCS_VehSpeed_Tar -
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG;

    /* Lookup: '<S27>/KtACCS_a_OpenAccel_LowSpeedCtrl' */
    /*
     * About '<S27>/KtACCS_a_OpenAccel_LowSpeedCtrl':
     * Input0  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(VfACCS_FeedForwardAccel),
      KtACCS_a_OpenAccel_LowSpeedCtrl, rtb_Subtract1,
      KtACCS_AXIS_OpenAccelLowSpedCtrl_SpedErr, 6U);

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem3' */
  }
  else if (VeACCS_RunStatus == ACCS_status_Launch)
  {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */

    /* Lookup: '<S26>/KtACCS_a_OpenAccel_Launch' */
    /*
     * About '<S26>/KtACCS_a_OpenAccel_Launch':
     * Input0  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(VfACCS_FeedForwardAccel),
      KtACCS_a_OpenAccel_Launch,
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG,
      KtACCS_AXIS_OpenAccelLaunch_CurSpd, 5U);

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem2' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* SignalConversion: '<S28>/OutportBufferForVfACCS_FeedForwardAccel' incorporates:
     *  Constant: '<S28>/Constant'
     */
    VfACCS_FeedForwardAccel = 0.0F;

    /* End of Outputs for SubSystem: '<S18>/If Action Subsystem4' */
  }

  /* End of If: '<S18>/If1' */

  /* Logic: '<S18>/Logical Operator' incorporates:
   *  Lookup_n-D: '<S18>/KtACCS_d_RespDCSNStopThrshHi'
   *  RelationalOperator: '<S18>/Relational Operator2'
   */
  VbACCS_NeedRespStopFrmDCSN =
    ((ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v) &&
     (ACCS_subsystem_integrated_B.VfACCS_Input_stop_s_distance_DC <=
      look1_iflf_binlc
      (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG,
       KtACCS_AXIS_DCSNStopThrshHi_Spd, KtACCS_d_RespDCSNStopThrshHi, 5U)));

  /* Switch: '<S18>/Switch2' incorporates:
   *  Constant: '<S18>/Constant10'
   *  Product: '<S18>/Divide'
   */
  if (VbACCS_NeedRespStopFrmDCSN)
  {
    /* Lookup: '<S18>/KtACCS_t_CalOpenAccelForStopFrmDCSN' */
    /*
     * About '<S18>/KtACCS_t_CalOpenAccelForStopFrmDCSN':
     * Input0  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(rtb_Product3),
      KtACCS_t_CalOpenAccelForStopFrmDCSN,
      ACCS_subsystem_integrated_B.VfACCS_Input_stop_s_distance_DC,
      KtACCS_AXIS_OpenAccelStop_StopDis, 5U);

    /* MinMax: '<S18>/MinMax' incorporates:
     *  Math: '<S18>/Square'
     */
    u0 = (real_T)((real32_T)(rtb_Product3 * rtb_Product3));

    /* Product: '<S18>/Product3' incorporates:
     *  Constant: '<S18>/Constant9'
     *  Product: '<S18>/Product2'
     *  Sum: '<S18>/Subtract'
     */
    rtb_Product3 = (real32_T)((real_T)(((real_T)((real32_T)
      (ACCS_subsystem_integrated_B.VfACCS_Input_stop_s_distance_DC -
       (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG *
        rtb_Product3)))) * 2.0));

    /* MinMax: '<S18>/MinMax' incorporates:
     *  Constant: '<S18>/Constant27'
     */
    if (u0 > 1.0E-6)
    {
    }
    else
    {
      u0 = 1.0E-6;
    }

    VfACCS_OpenAccel_ForDCSNStop = (real32_T)((real_T)(((real_T)rtb_Product3) /
      u0));
  }
  else
  {
    VfACCS_OpenAccel_ForDCSNStop = 0.0F;
  }

  /* End of Switch: '<S18>/Switch2' */

  /* SignalConversion: '<S18>/Signal Conversion' */
  ACCS_subsystem_integrated_B.SignalConversion_a213 = VbACCS_Input_Obs_valid;
}

/* Output and update for atomic system: '<S13>/DtrmnACCS_AccelAndSpdLimit' */
void DtrmnACCS_AccelAndSpdLimit(void)
{
  /* Inport: '<S19>/CombinedSpeedLimit' */
  VfACCS_FinalSpeedLimit = VfACCS_CombinedSpeedLimit;
}

/* Output and update for atomic system: '<S4>/DtrmnACCS_DsrdLonControlParm' */
void DtrmnACCS_DsrdLonControlParm(void)
{
  /* Outputs for Atomic SubSystem: '<S13>/DtrmnACCS_AccelAndSpdLimit' */
  DtrmnACCS_AccelAndSpdLimit();

  /* End of Outputs for SubSystem: '<S13>/DtrmnACCS_AccelAndSpdLimit' */

  /* Outputs for Atomic SubSystem: '<S13>/CalcACCS_EgoVehicleTargetSpeed' */
  CalcACCS_EgoVehicleTargetSpeed();

  /* End of Outputs for SubSystem: '<S13>/CalcACCS_EgoVehicleTargetSpeed' */

  /* Outputs for Atomic SubSystem: '<S13>/CalcACCS_OpenAccel' */
  CalcACCS_OpenAccel();

  /* End of Outputs for SubSystem: '<S13>/CalcACCS_OpenAccel' */
}

/* Output and update for atomic system: '<S14>/DtrmnACCS_EgoStatusFrmCan' */
void DtrmnACCS_EgoStatusFrmCan(void)
{
  real32_T rtb_Min_mthm;
  real32_T rtb_Switch1;

  /* SignalConversion: '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  VbACCS_BrakePedalPress =
    ACCS_subsystem_integrated_B.VbACCS_Input_DriverPresent;

  /* SignalConversion: '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  VbACCS_EPB_Engaged = ACCS_subsystem_integrated_B.SignalConversion_a213;

  /* SignalConversion: '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  ACCS_subsystem_integrated_B.VbACCS_Input_DriverPresent =
    ACCS_subsystem_integrated_B.Ego_LimitCondition;

  /* SignalConversion: '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  ACCS_subsystem_integrated_B.VfACCS_RangeErrLim_CIPV =
    VfACCS_Input_PhyGasPedal_POWER;

  /* Switch: '<S34>/Switch2' incorporates:
   *  Constant: '<S34>/Constant'
   *  Constant: '<S34>/Constant2'
   */
  if (KbACCS_MainSwitch)
  {
    ACCS_subsystem_integrated_B.SignalConversion = true;
  }
  else
  {
    ACCS_subsystem_integrated_B.SignalConversion =
      ACCS_subsystem_integrate_ConstB.Constant19;
  }

  /* End of Switch: '<S34>/Switch2' */

  /* Switch: '<S34>/Switch5' incorporates:
   *  Constant: '<S34>/Constant1'
   *  Constant: '<S34>/Constant4'
   */
  if (KbACCS_CancelSwitch)
  {
    ACCS_subsystem_integrated_B.Switch4 = true;
  }
  else
  {
    ACCS_subsystem_integrated_B.Switch4 =
      ACCS_subsystem_integrate_ConstB.Constant20;
  }

  /* End of Switch: '<S34>/Switch5' */

  /* Switch: '<S34>/Switch4' incorporates:
   *  Constant: '<S34>/Constant7'
   *  Constant: '<S34>/Constant8'
   *  Sum: '<S34>/Sum'
   *  UnitDelay: '<S34>/Unit Delay'
   */
  if (ACCS_subsystem_integrate_ConstB.Constant47 > 0.0F)
  {
    rtb_Switch1 = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_kdq3 + 1.0F;
  }
  else
  {
    rtb_Switch1 = 0.0F;
  }

  /* End of Switch: '<S34>/Switch4' */

  /* MinMax: '<S34>/Min' incorporates:
   *  Constant: '<S34>/Constant9'
   */
  if (rtb_Switch1 < 6000.0F)
  {
    rtb_Min_mthm = rtb_Switch1;
  }
  else
  {
    rtb_Min_mthm = 6000.0F;
  }

  /* End of MinMax: '<S34>/Min' */

  /* Logic: '<S34>/Logical Operator1' incorporates:
   *  Constant: '<S34>/Constant10'
   *  Logic: '<S34>/Logical Operator5'
   *  Logic: '<S34>/Logical Operator6'
   *  RelationalOperator: '<S34>/Relational Operator2'
   */
  ACCS_subsystem_integrated_B.Ego_LimitCondition = ((((((rtb_Min_mthm >=
    KcACCS_ABSActvieCntDisableACCThrsh) ||
    (ACCS_subsystem_integrate_ConstB.LogicalOperator3)) ||
    (ACCS_subsystem_integrate_ConstB.LogicalOperator2)) ||
    (ACCS_subsystem_integrate_ConstB.LogicalOperator4)) ||
    (!VbACCS_Input_power_ctrl_enable_DCSN)) ||
    (!VbACCS_Input_brake_ctrl_enable_DCSN));

  /* Switch: '<S34>/Switch1' incorporates:
   *  Constant: '<S34>/KbACCS_CalTimeGap'
   *  Constant: '<S34>/kfACCS_TimeGapToCalcRange'
   *  Lookup_n-D: '<S34>/KaACCS_t_TimeGapFrmDriver'
   */
  if (KbACCS_CalTimeGap)
  {
    rtb_Switch1 = KfACCS_t_TimeGapToCalcRange;
  }
  else
  {
    rtb_Switch1 = look1_iflf_binlx(ACCS_subsystem_integrate_ConstB.Constant22,
      ACCS_subsystem_integrate_ConstP.KaACCS_t_TimeGapFrmDriver_bp01D,
      KaACCS_t_TimeGapFrmDriver, 3U);
  }

  /* End of Switch: '<S34>/Switch1' */

  /* Switch: '<S34>/Switch9' incorporates:
   *  Product: '<S34>/Product'
   */
  if (ACCS_subsystem_integrated_B.SignalConversion1_dk4z)
  {
    /* Switch: '<S34>/Switch8' incorporates:
     *  Constant: '<S34>/Constant17'
     *  Constant: '<S34>/KeACCS_TargetRangeCalType'
     *  Lookup_n-D: '<S34>/KtACCS_d_CIPVTargtRange'
     *  Product: '<S34>/Product1'
     *  RelationalOperator: '<S34>/Relational Operator3'
     */
    if (((real_T)KeACCS_TargetRangeCalType) == 1.0)
    {
      rtb_Switch1 *= ACCS_subsystem_integrated_B.Delay;
    }
    else
    {
      rtb_Switch1 = look2_iflf_binlx(ACCS_subsystem_integrated_B.Delay,
        rtb_Switch1, KtACCS_AXIS_TargetRange_Speed,
        KtACCS_AXIS_TargtRange_Timegap, KtACCS_d_CIPVTargtRange,
        ACCS_subsystem_integrate_ConstP.KtACCS_d_CIPVTargtRange_maxInde, 10U);
    }

    /* End of Switch: '<S34>/Switch8' */
  }
  else
  {
    rtb_Switch1 *= VfACCS_Input_linear_velocity_EGMO;
  }

  /* End of Switch: '<S34>/Switch9' */

  /* MinMax: '<S34>/MinMax' incorporates:
   *  Constant: '<S34>/KfACCS_d_MinimumRange'
   */
  if (rtb_Switch1 > KfACCS_d_MinimumRange)
  {
  }
  else
  {
    rtb_Switch1 = KfACCS_d_MinimumRange;
  }

  /* End of MinMax: '<S34>/MinMax' */

  /* MinMax: '<S34>/MinMax1' incorporates:
   *  Constant: '<S34>/KfACCS_d_MaxRange'
   */
  if (KfACCS_d_MaxRange < rtb_Switch1)
  {
    VfACCS_DriverTargetRange = KfACCS_d_MaxRange;
  }
  else
  {
    VfACCS_DriverTargetRange = rtb_Switch1;
  }

  /* End of MinMax: '<S34>/MinMax1' */

  /* Switch: '<S34>/Switch6' incorporates:
   *  Constant: '<S34>/Constant3'
   *  Constant: '<S34>/Constant5'
   */
  if (KbACCS_ResumeSwitch)
  {
    ACCS_subsystem_integrated_B.SignalConversion_a213 = true;
  }
  else
  {
    ACCS_subsystem_integrated_B.SignalConversion_a213 =
      ACCS_subsystem_integrated_B.VbACCS_Input_Obs_R_valid;
  }

  /* End of Switch: '<S34>/Switch6' */

  /* Switch: '<S34>/Switch3' incorporates:
   *  Constant: '<S34>/KbACCS_CalDriverSetSpeed'
   *  Constant: '<S34>/KfACCS_v_CalDriverSetSpeed'
   */
  if (KbACCS_CalDriverSetSpeed)
  {
    ACCS_subsystem_integrated_B.CalDriverSetSpeed = KfACCS_v_CalDriverSetSpeed;
  }
  else
  {
    ACCS_subsystem_integrated_B.CalDriverSetSpeed =
      ACCS_subsystem_integrate_ConstB.Constant21;
  }

  /* End of Switch: '<S34>/Switch3' */

  /* RelationalOperator: '<S34>/Relational Operator1' incorporates:
   *  Constant: '<S34>/KfACCS_v_DriverSetSpeedMinThrsh'
   */
  VbACCS_DriverHasSetSpeed = (ACCS_subsystem_integrated_B.CalDriverSetSpeed >=
    KfACCS_v_DriverSetSpeedMinThrsh);

  /* Update for UnitDelay: '<S34>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_kdq3 = rtb_Min_mthm;
}

/* Output and update for atomic system: '<S35>/DtrmnACCS_ObstacleExtraction' */
void DtrmnACCS_ObstacleExtraction(void)
{
  real32_T LeftDistance;
  real32_T FrDistance;
  real32_T RightDistance;
  uint16_T i;
  OBFU_Obstacle tmp;

  /* Inport: '<Root>/OBFU_DataBus' */
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV = VsOBFU_DataBus.obstacles[0];
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.nearest_point_rel.x = 150.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.nearest_point_rel.y = 20.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.nearest_point_rel.z = 0.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.center_point_rel.x = 150.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.center_point_rel.y = 20.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.center_point_rel.z = 0.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.heading_rel = 0.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.velocity_rel.x = 0.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.velocity_rel.y = 0.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.acceleration_rel.x = 0.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.acceleration_rel.y = 0.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.is_velocity_valid = true;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.is_acceleration_valid = true;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.padding_1[0] = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.padding_1[1] = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.length = 0.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.width = 0.0F;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.height = 0.0F;
  memset(&ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.polygon_points[0], 0,
         (sizeof(Vector3f)) << 3U);
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.num_polygon_points = 0U;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.padding_2[0] = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.padding_2[1] = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.padding_2[2] = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.tracking_time = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.type = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.motion_status = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.motion_orientation = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.confidence = 0U;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.position_zone = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.turn_indicator = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.brake_indicator = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.tracking_status = 0;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.source = 0U;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.is_cipv_front = false;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.is_cipv_rear = false;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.is_cipv_left = false;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.is_cipv_right = false;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.is_cutin = false;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.is_cutout = false;
  ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v = false;
  ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVR_valid = false;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV;
  ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVL_valid = false;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV;
  ACCS_subsystem_integrated_B.VbACCS_Input_Obs_F_valid = false;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV;
  ACCS_subsystem_integrated_B.VbACCS_Input_Obs_L_valid = false;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV;
  ACCS_subsystem_integrated_B.VbACCS_Input_Obs_R_valid = false;
  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV;
  LeftDistance = 200.0F;
  FrDistance = 200.0F;
  RightDistance = 200.0F;
  for (i = 1U; i <= VfACCS_Input_Obs_Num; i = (uint16_T)(((uint32_T)i) + 1U))
  {
    /* Inport: '<Root>/OBFU_DataBus' */
    tmp = VsOBFU_DataBus.obstacles[((int32_T)i) - 1];
    if ((tmp.is_cipv_front) && (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].id >
         0))
    {
      ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v = true;
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV = tmp;
    }
    else if ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].is_cipv_left) &&
             (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].id > 0))
    {
      ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVL_valid = true;
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL = tmp;
    }
    else if ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].is_cipv_right) &&
             (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].id > 0))
    {
      ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVR_valid = true;
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR = tmp;
    }
    else
    {
      switch (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].position_zone)
      {
       case 1:
        if (((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].nearest_point_rel.x >
              0.0F) && (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                        nearest_point_rel.x < LeftDistance)) &&
            (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].motion_orientation == 4))
        {
          ACCS_subsystem_integrated_B.VbACCS_Input_Obs_L_valid = true;
          ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L = tmp;
          LeftDistance = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
            nearest_point_rel.x;
        }
        break;

       case 2:
        if ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].nearest_point_rel.x >
             0.0F) && (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                       nearest_point_rel.x < FrDistance))
        {
          ACCS_subsystem_integrated_B.VbACCS_Input_Obs_F_valid = true;
          ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F = tmp;
          FrDistance = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
            nearest_point_rel.x;
        }
        break;

       case 3:
        if (((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].nearest_point_rel.x >
              0.0F) && (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                        nearest_point_rel.x < RightDistance)) &&
            (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].motion_orientation == 4))
        {
          ACCS_subsystem_integrated_B.VbACCS_Input_Obs_R_valid = true;
          ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R = tmp;
          RightDistance = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
            nearest_point_rel.x;
        }
        break;

       default:
        /* no actions */
        break;
      }
    }
  }
}

/* Output and update for atomic system: '<S35>/DtrmnACCS_TargetObject' */
void DtrmnACCS_TargetObject(void)
{
  int_T idxDelay;
  real32_T rtb_Abs3;
  boolean_T rtb_LogicalOperator1;
  boolean_T rtb_LogicalOperator3_g0tf;
  boolean_T rtb_RelationalOperator14;
  real32_T rtb_Sum_nujo;
  boolean_T rtb_RelationalOperator2_f3ty;
  real32_T rtb_Switch11;
  real32_T rtb_Product_kelx;
  real32_T rtb_Limit10to10;
  real32_T rtb_Add11;
  real32_T rtb_MathReciprocal;
  real_T rtb_Switch;
  boolean_T rtb_LogicalOperator4_fmdb;
  real32_T rtb_Abs3_f3i5;
  real32_T rtb_Sum_e3dl;
  real32_T rtb_Switch11_lqzi;
  real32_T rtb_Abs3_daky;
  real32_T rtb_Sum_kt3p;
  real32_T rtb_Switch11_pxmy;
  real32_T rtb_Abs3_ptqq;
  real32_T rtb_Sum_g5ql;
  real32_T rtb_Switch11_fwu3;
  real32_T rtb_MathReciprocal_ashu;
  real32_T rtb_MathReciprocal_k124;
  real32_T rtb_Sum_khuf;
  real32_T rtb_Switch11_mayx;
  real32_T rtb_Switch1;
  boolean_T rtb_Switch1_h4qq;
  real32_T rtb_Switch_n0oh;
  real32_T rtb_Switch2_lvye;
  real32_T rtb_Switch1_gcg5;
  real_T rtb_Switch5_nscd;
  real32_T rtb_Switch1_pa3i;
  real32_T rtb_Switch1_k02x;
  real32_T rtb_Switch1_oyua;
  real32_T rtb_Switch1_l00p;
  real32_T rtb_Switch1_ic0c;
  real32_T rtb_Switch2_b0i5;
  real32_T rtb_VfACCS_Input_Obs_Range;
  real32_T rtb_Switch2_cdx1;
  real_T rtb_Switch5_blbp;
  real32_T rtb_Switch2_mhzu;
  real32_T rtb_Switch2_aer3;
  real32_T rtb_Sum_psl2;
  real32_T rtb_Sum_jtad;
  real32_T rtb_Sum_oc5m;
  real32_T rtb_Sum_hycr;
  real32_T rtb_Switch2_bksf;
  real32_T rtb_Switch2_otez;
  real32_T rtb_Switch2_ciy1;
  real32_T rtb_Switch2_nhsq;
  real32_T rtb_Switch2_kl5r;
  real32_T rtb_Switch2_kzlb;
  real32_T rtb_Switch2_du1h;
  real32_T rtb_Switch2_krvg;
  real32_T rtb_Switch12_cgog;
  real32_T rtb_VfACCS_Input_Obs_Linea_flzo;
  real32_T rtb_Add11_hcma;
  ACCS_CIPVChangedType rtb_CIPVChangedType;
  uint32_T tmp;
  real32_T rtb_MathReciprocal_klus;
  real32_T rtb_Switch_iliv_tmp;

  /* Sum: '<S38>/Add17' */
  VfACCS_Obs_Lat_V_OBFU =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.velocity_rel.y +
    VfACCS_Input_latvelocity_EGMO;

  /* Abs: '<S44>/Abs3' */
  rtb_Abs3 = (real32_T)fabs((real_T)VfACCS_Obs_Lat_V_OBFU);

  /* Switch: '<S44>/Switch6' incorporates:
   *  Constant: '<S44>/Constant15'
   *  Constant: '<S44>/Constant23'
   *  RelationalOperator: '<S44>/Relational Operator5'
   *  RelationalOperator: '<S44>/Relational Operator6'
   *  Switch: '<S44>/Switch8'
   */
  if (rtb_Abs3 >= KfACCS_v_LatSpdDeadband_Max)
  {
    rtb_Abs3 = VfACCS_Obs_Lat_V_OBFU;
  }
  else if (rtb_Abs3 >= KfACCS_v_LatSpdDeadband_Min)
  {
    /* MinMax: '<S44>/Max3' incorporates:
     *  Constant: '<S44>/Constant17'
     *  Constant: '<S44>/Constant18'
     *  Sum: '<S44>/Add8'
     *  Switch: '<S44>/Switch8'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(KfACCS_v_LatSpdDeadband_Max -
      KfACCS_v_LatSpdDeadband_Min));

    /* Switch: '<S44>/Switch7' incorporates:
     *  Constant: '<S44>/Constant20'
     *  Constant: '<S44>/Constant21'
     *  Switch: '<S44>/Switch8'
     */
    if (VfACCS_Obs_Lat_V_OBFU > 0.0F)
    {
      rtb_Sum_nujo = (real32_T)1.0;
    }
    else
    {
      rtb_Sum_nujo = (real32_T)(-1.0);
    }

    /* End of Switch: '<S44>/Switch7' */

    /* MinMax: '<S44>/Max3' incorporates:
     *  Constant: '<S44>/Constant19'
     *  Switch: '<S44>/Switch8'
     */
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S44>/Switch8' incorporates:
     *  Constant: '<S44>/Constant16'
     *  Constant: '<S44>/Constant22'
     *  Product: '<S44>/Divide3'
     *  Product: '<S44>/Product9'
     *  Sum: '<S44>/Add7'
     */
    rtb_Abs3 = (rtb_Sum_nujo * KfACCS_v_LatSpdDeadband_Max) * ((real32_T)
      ((real_T)(((real_T)((real32_T)(rtb_Abs3 - KfACCS_v_LatSpdDeadband_Min))) /
                rtb_Switch5_blbp)));
  }
  else
  {
    /* Switch: '<S44>/Switch8' incorporates:
     *  Constant: '<S44>/Constant24'
     */
    rtb_Abs3 = (real32_T)0.0;
  }

  /* End of Switch: '<S44>/Switch6' */

  /* Switch: '<S44>/Switch9' incorporates:
   *  Abs: '<S44>/Abs4'
   *  Constant: '<S44>/Constant26'
   *  RelationalOperator: '<S44>/Relational Operator7'
   *  Sum: '<S44>/Add9'
   *  UnitDelay: '<S44>/Unit Delay'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Abs3 -
          ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mdjq)))) >=
      KfACCS_v_LatSpdUpdateThrsh)
  {
  }
  else
  {
    rtb_Abs3 = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mdjq;
  }

  /* End of Switch: '<S44>/Switch9' */

  /* Logic: '<S38>/Logical Operator1' incorporates:
   *  Constant: '<S38>/Constant1'
   *  Constant: '<S38>/Constant3'
   *  RelationalOperator: '<S38>/Relational Operator2'
   *  RelationalOperator: '<S38>/Relational Operator3'
   *  UnitDelay: '<S38>/Unit Delay1'
   */
  rtb_LogicalOperator1 = ((ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_fi04
    != 0) && (ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id == 0));

  /* Logic: '<S38>/Logical Operator3' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S38>/Constant2'
   *  RelationalOperator: '<S38>/Relational Operator'
   *  RelationalOperator: '<S38>/Relational Operator1'
   *  UnitDelay: '<S38>/Unit Delay'
   */
  rtb_LogicalOperator3_g0tf =
    ((ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mjdv == 0) &&
     (ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id != 0));

  /* Logic: '<S38>/Logical Operator' */
  rtb_RelationalOperator14 = (rtb_LogicalOperator1 || rtb_LogicalOperator3_g0tf);

  /* Switch: '<S52>/Switch' incorporates:
   *  UnitDelay: '<S52>/Unit Delay'
   */
  if (rtb_RelationalOperator14)
  {
    rtb_Sum_nujo = rtb_Abs3;
  }
  else
  {
    rtb_Sum_nujo = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_oamq;
  }

  /* End of Switch: '<S52>/Switch' */

  /* Sum: '<S52>/Subtract' incorporates:
   *  Constant: '<S44>/Constant50'
   *  Constant: '<S52>/Constant'
   *  Sum: '<S100>/Subtract'
   *  Sum: '<S51>/Subtract'
   *  Sum: '<S71>/Subtract'
   *  Sum: '<S72>/Subtract'
   *  Sum: '<S78>/Subtract'
   *  Sum: '<S79>/Subtract'
   *  Sum: '<S85>/Subtract'
   *  Sum: '<S86>/Subtract'
   *  Sum: '<S92>/Subtract'
   *  Sum: '<S93>/Subtract'
   *  Sum: '<S99>/Subtract'
   */
  rtb_Sum_khuf = 1.0F - KfACCS_k_ObjectSpdFilter;

  /* Sum: '<S52>/Sum' incorporates:
   *  Constant: '<S44>/Constant50'
   *  Product: '<S52>/Product'
   *  Product: '<S52>/Product1'
   *  Sum: '<S52>/Subtract'
   */
  rtb_Abs3 = (rtb_Sum_nujo * rtb_Sum_khuf) + (KfACCS_k_ObjectSpdFilter *
    rtb_Abs3);

  /* Sum: '<S38>/Add18' */
  VfACCS_Obs_Long_V_OBFU =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.velocity_rel.x +
    VfACCS_Input_longvelocity_EGMO;

  /* Switch: '<S44>/Switch10' incorporates:
   *  Abs: '<S44>/Abs5'
   *  Constant: '<S44>/Constant25'
   *  RelationalOperator: '<S44>/Relational Operator8'
   *  Sum: '<S44>/Add10'
   *  UnitDelay: '<S44>/Unit Delay1'
   */
  if (((real32_T)fabs((real_T)((real32_T)(VfACCS_Obs_Long_V_OBFU -
          ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_g15n)))) >=
      KfACCS_v_ObjectSpdUpdateThrsh)
  {
    rtb_Add11_hcma = VfACCS_Obs_Long_V_OBFU;
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_g15n;
  }

  /* End of Switch: '<S44>/Switch10' */

  /* Switch: '<S51>/Switch' incorporates:
   *  UnitDelay: '<S51>/Unit Delay'
   */
  if (rtb_RelationalOperator14)
  {
    rtb_Sum_nujo = rtb_Add11_hcma;
  }
  else
  {
    rtb_Sum_nujo = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_gzk1;
  }

  /* End of Switch: '<S51>/Switch' */

  /* Sum: '<S51>/Sum' incorporates:
   *  Constant: '<S44>/Constant48'
   *  Product: '<S51>/Product'
   *  Product: '<S51>/Product1'
   */
  rtb_Sum_nujo = (rtb_Sum_nujo * rtb_Sum_khuf) + (KfACCS_k_ObjectSpdFilter *
    rtb_Add11_hcma);

  /* Switch: '<S44>/Switch11' incorporates:
   *  Abs: '<S44>/Abs6'
   *  Constant: '<S44>/Constant28'
   *  MinMax: '<S44>/Max4'
   *  Product: '<S44>/Divide4'
   *  RelationalOperator: '<S44>/Relational Operator9'
   *  Trigonometry: '<S44>/Atan2'
   */
  if (((real_T)((real32_T)fabs((real_T)rtb_Sum_nujo))) > 0.0)
  {
    /* MinMax: '<S44>/Max4' incorporates:
     *  Constant: '<S44>/Constant27'
     */
    if (((real_T)rtb_Sum_nujo) > 1.0E-6)
    {
      rtb_Switch5_nscd = (real_T)rtb_Sum_nujo;
    }
    else
    {
      rtb_Switch5_nscd = 1.0E-6;
    }

    rtb_Switch11 = (real32_T)atan((real_T)((real32_T)(rtb_Abs3 / ((real32_T)
      rtb_Switch5_nscd))));
  }
  else
  {
    rtb_Switch11 = (real32_T)ACCS_subsystem_integrate_ConstB.Gain1;
  }

  /* End of Switch: '<S44>/Switch11' */

  /* Sum: '<S38>/Add19' */
  VfACCS_Obs_Long_A_OBFU =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.acceleration_rel.x +
    ACCS_subsystem_integrated_B.VfACCS_Input_linear_Accele_dcwi;

  /* Sum: '<S38>/Add20' */
  VfACCS_Obs_Lat_A_OBFU =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.acceleration_rel.y +
    ACCS_subsystem_integrated_B.VfACCS_Input_linear_Acceleratio;

  /* Trigonometry: '<S44>/Cos4' incorporates:
   *  Switch: '<S44>/Switch12'
   *  Trigonometry: '<S44>/Cos2'
   *  Trigonometry: '<S44>/Cos3'
   */
  rtb_MathReciprocal_ashu = (real32_T)cos((real_T)rtb_Switch11);

  /* Trigonometry: '<S44>/Sin5' incorporates:
   *  Switch: '<S44>/Switch12'
   *  Trigonometry: '<S44>/Sin3'
   *  Trigonometry: '<S44>/Sin4'
   */
  rtb_Switch11_lqzi = (real32_T)sin((real_T)rtb_Switch11);

  /* Sum: '<S44>/Add16' incorporates:
   *  Product: '<S44>/Product14'
   *  Product: '<S44>/Product15'
   *  Trigonometry: '<S44>/Cos4'
   *  Trigonometry: '<S44>/Sin5'
   */
  rtb_Add11_hcma = (VfACCS_Obs_Long_A_OBFU * rtb_MathReciprocal_ashu) +
    (VfACCS_Obs_Lat_A_OBFU * rtb_Switch11_lqzi);

  /* Sum: '<S44>/Add11' incorporates:
   *  Product: '<S44>/Product10'
   *  Product: '<S44>/Product11'
   */
  rtb_Add11 = (rtb_Sum_nujo * rtb_MathReciprocal_ashu) + (rtb_Abs3 *
    rtb_Switch11_lqzi);

  /* Switch: '<S44>/Switch1' incorporates:
   *  Constant: '<S44>/Constant'
   *  Constant: '<S44>/Constant1'
   *  Delay: '<S44>/Delay'
   *  Product: '<S44>/Divide'
   *  RelationalOperator: '<S44>/Relational Operator'
   *  Sum: '<S44>/Subtract'
   *  Switch: '<S44>/Switch'
   *  UnitDelay: '<S44>/Unit Delay3'
   */
  if ((((real32_T)(KbACCS_UseACCFromRadar ? 1.0F : 0.0F)) > 0.0F) ||
      (ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id !=
       ACCS_subsystem_integrated_DW.UnitDelay3_DSTATE_cdwe))
  {
  }
  else
  {
    rtb_Add11_hcma = (rtb_Add11 - ACCS_subsystem_integrated_DW.Delay_DSTATE_ml05)
      / 0.01F;
  }

  /* End of Switch: '<S44>/Switch1' */

  /* Switch: '<S44>/Switch24' incorporates:
   *  Abs: '<S44>/Abs7'
   *  Constant: '<S44>/Constant47'
   *  RelationalOperator: '<S44>/Relational Operator10'
   *  Sum: '<S44>/Add21'
   *  UnitDelay: '<S44>/Unit Delay2'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_a0sb)))) >=
      KfACCS_a_ObjectAccelUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_a0sb;
  }

  /* End of Switch: '<S44>/Switch24' */

  /* Product: '<S50>/Product' incorporates:
   *  Constant: '<S44>/Constant46'
   */
  rtb_Product_kelx = KfACCS_k_ObjectAccelFilter * rtb_Add11_hcma;

  /* Switch: '<S50>/Switch' incorporates:
   *  UnitDelay: '<S50>/Unit Delay'
   */
  if (rtb_RelationalOperator14)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_jw3u;
  }

  /* End of Switch: '<S50>/Switch' */

  /* Sum: '<S50>/Subtract' incorporates:
   *  Constant: '<S44>/Constant46'
   *  Constant: '<S50>/Constant'
   *  Sum: '<S70>/Subtract'
   *  Sum: '<S77>/Subtract'
   *  Sum: '<S84>/Subtract'
   *  Sum: '<S91>/Subtract'
   *  Sum: '<S98>/Subtract'
   */
  rtb_Sum_hycr = 1.0F - KfACCS_k_ObjectAccelFilter;

  /* Sum: '<S50>/Sum' incorporates:
   *  Product: '<S50>/Product1'
   *  Sum: '<S50>/Subtract'
   */
  rtb_Product_kelx += rtb_Add11_hcma * rtb_Sum_hycr;

  /* Saturate: '<S44>/Limit -10 to 10' */
  if (rtb_Product_kelx > 10.0F)
  {
    rtb_Limit10to10 = 10.0F;
  }
  else if (rtb_Product_kelx < (-10.0F))
  {
    rtb_Limit10to10 = (-10.0F);
  }
  else
  {
    rtb_Limit10to10 = rtb_Product_kelx;
  }

  /* End of Saturate: '<S44>/Limit -10 to 10' */

  /* Switch: '<S67>/Switch1' incorporates:
   *  UnitDelay: '<S67>/Unit Delay1'
   *  UnitDelay: '<S67>/Unit Delay2'
   */
  if (rtb_LogicalOperator1)
  {
    rtb_Switch1 = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_ihdw;
  }
  else
  {
    rtb_Switch1 = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_iqun;
  }

  /* End of Switch: '<S67>/Switch1' */

  /* Switch: '<S67>/Switch4' incorporates:
   *  Constant: '<S67>/Constant3'
   *  Constant: '<S67>/Constant5'
   *  Saturate: '<S67>/Saturation'
   *  Sum: '<S67>/Add3'
   *  Switch: '<S67>/Switch2'
   *  UnitDelay: '<S67>/Unit Delay'
   */
  if (rtb_LogicalOperator3_g0tf)
  {
    rtb_Switch2_bksf = 0.0F;
  }
  else
  {
    if (rtb_LogicalOperator1)
    {
      /* Switch: '<S67>/Switch2' incorporates:
       *  Constant: '<S67>/Constant4'
       */
      rtb_Switch2_bksf = KfACCS_t_CIPVDisappearDelay;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mfeb > 10.0F)
    {
      /* Saturate: '<S67>/Saturation' incorporates:
       *  Switch: '<S67>/Switch2'
       */
      rtb_Switch2_bksf = 10.0F;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mfeb < 0.0F)
    {
      /* Saturate: '<S67>/Saturation' incorporates:
       *  Switch: '<S67>/Switch2'
       */
      rtb_Switch2_bksf = 0.0F;
    }
    else
    {
      /* Switch: '<S67>/Switch2' incorporates:
       *  Saturate: '<S67>/Saturation'
       *  UnitDelay: '<S67>/Unit Delay'
       */
      rtb_Switch2_bksf = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mfeb;
    }

    rtb_Switch2_bksf -= 0.01F;
  }

  /* End of Switch: '<S67>/Switch4' */

  /* SignalConversion: '<S38>/Signal Conversion' */
  VfACCS_Obs_Long_OBFU =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.nearest_point_rel.x;

  /* SignalConversion: '<S38>/Signal Conversion1' */
  VfACCS_Obs_Lat_OBFU =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.nearest_point_rel.y;

  /* Abs: '<S49>/Abs' incorporates:
   *  Abs: '<S45>/Abs1'
   *  Switch: '<S45>/Switch1'
   */
  rtb_Switch2_lvye = (real32_T)fabs((real_T)VfACCS_Obs_Lat_OBFU);

  /* Logic: '<S48>/Logical Operator' incorporates:
   *  Abs: '<S49>/Abs'
   *  Constant: '<S49>/Constant'
   *  Constant: '<S49>/Constant2'
   *  Constant: '<S49>/Constant3'
   *  Constant: '<S49>/Constant4'
   *  Constant: '<S49>/Constant5'
   *  Constant: '<S49>/Constant6'
   *  Logic: '<S48>/Logical Operator1'
   *  Logic: '<S49>/Logical Operator'
   *  Logic: '<S49>/Logical Operator1'
   *  Logic: '<S49>/Outside control zone'
   *  Logic: '<S49>/Stationary Obs or Omcoming Obs'
   *  Lookup_n-D: '<S49>/1-D Lookup Table'
   *  RelationalOperator: '<S49>/Relational Operator'
   *  RelationalOperator: '<S49>/Relational Operator1'
   *  RelationalOperator: '<S49>/Relational Operator2'
   *  RelationalOperator: '<S49>/Relational Operator3'
   *  RelationalOperator: '<S49>/Relational Operator4'
   *  RelationalOperator: '<S49>/Relational Operator5'
   */
  VbACCS_Obs_validBeforeDelay =
    ((ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v) &&
     (!((((VfACCS_Input_linear_velocity_EGMO >=
           KfACCS_v_ChooseStationaryObsMaxSpd) || ((VfACCS_Obs_Long_OBFU >=
           look1_iflf_binlx(VfACCS_Input_linear_velocity_EGMO,
            KtACCS_AXIS_TargetZoneSpd, KtACCS_d_TargetZoneLongDis, 14U)) ||
          (rtb_Switch2_lvye >= KfACCS_d_ConsiderObsMaxLat))) && (((((int32_T)
            ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.motion_status) ==
           ((int32_T)((uint8_T)2U))) || (((int32_T)
            ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.motion_orientation)
           == ((int32_T)((uint8_T)1U)))) || (rtb_Add11 <=
          KfACCS_v_IgnoreObsSpdLimit))) && KbACCS_UseIgnoreObsFcn)));

  /* Switch: '<S66>/Switch1' incorporates:
   *  UnitDelay: '<S66>/Unit Delay1'
   *  UnitDelay: '<S66>/Unit Delay2'
   */
  if (rtb_LogicalOperator1)
  {
    rtb_Switch1_h4qq = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_exnj;
  }
  else
  {
    rtb_Switch1_h4qq = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_ians;
  }

  /* End of Switch: '<S66>/Switch1' */

  /* Switch: '<S66>/Switch4' incorporates:
   *  Constant: '<S66>/Constant3'
   *  Constant: '<S66>/Constant5'
   *  Saturate: '<S66>/Saturation'
   *  Sum: '<S66>/Add3'
   *  Switch: '<S66>/Switch2'
   *  UnitDelay: '<S66>/Unit Delay'
   */
  if (rtb_LogicalOperator3_g0tf)
  {
    rtb_Switch2_otez = 0.0F;
  }
  else
  {
    if (rtb_LogicalOperator1)
    {
      /* Switch: '<S66>/Switch2' incorporates:
       *  Constant: '<S66>/Constant4'
       */
      rtb_Switch2_otez = KfACCS_t_CIPVDisappearDelay;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_kvt4 > 10.0F)
    {
      /* Saturate: '<S66>/Saturation' incorporates:
       *  Switch: '<S66>/Switch2'
       */
      rtb_Switch2_otez = 10.0F;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_kvt4 < 0.0F)
    {
      /* Saturate: '<S66>/Saturation' incorporates:
       *  Switch: '<S66>/Switch2'
       */
      rtb_Switch2_otez = 0.0F;
    }
    else
    {
      /* Switch: '<S66>/Switch2' incorporates:
       *  Saturate: '<S66>/Saturation'
       *  UnitDelay: '<S66>/Unit Delay'
       */
      rtb_Switch2_otez = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_kvt4;
    }

    rtb_Switch2_otez -= 0.01F;
  }

  /* End of Switch: '<S66>/Switch4' */

  /* Switch: '<S66>/Switch' */
  if (rtb_Switch2_otez > 0.0F)
  {
    VbACCS_Input_Obs_valid = rtb_Switch1_h4qq;
  }
  else
  {
    VbACCS_Input_Obs_valid = VbACCS_Obs_validBeforeDelay;
  }

  /* End of Switch: '<S66>/Switch' */

  /* Switch: '<S48>/Switch6' incorporates:
   *  Constant: '<S48>/Constant6'
   */
  if (VbACCS_Input_Obs_valid)
  {
    /* Switch: '<S67>/Switch' */
    if (rtb_Switch2_bksf > 0.0F)
    {
      VfACCS_Input_Obs_LinearAcc = rtb_Switch1;
    }
    else
    {
      VfACCS_Input_Obs_LinearAcc = rtb_Limit10to10;
    }

    /* End of Switch: '<S67>/Switch' */
  }
  else
  {
    VfACCS_Input_Obs_LinearAcc = 0.0F;
  }

  /* End of Switch: '<S48>/Switch6' */

  /* MinMax: '<S45>/Max1' incorporates:
   *  Constant: '<S45>/Constant1'
   */
  if (((real_T)ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q) >
      1.0E-6)
  {
    rtb_Switch5_blbp = (real_T)
      ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q;
  }
  else
  {
    rtb_Switch5_blbp = 1.0E-6;
  }

  /* End of MinMax: '<S45>/Max1' */

  /* Math: '<S45>/Math Reciprocal'
   *
   * About '<S45>/Math Reciprocal':
   *  Operator: reciprocal
   */
  rtb_MathReciprocal = (real32_T)((real_T)(1.0 / rtb_Switch5_blbp));

  /* Switch: '<S45>/Switch' incorporates:
   *  Constant: '<S45>/Constant2'
   *  Constant: '<S45>/Constant3'
   */
  if (rtb_MathReciprocal > 0.0F)
  {
    rtb_Switch_n0oh = (real32_T)1.0;
  }
  else
  {
    rtb_Switch_n0oh = (real32_T)(-1.0);
  }

  /* End of Switch: '<S45>/Switch' */

  /* Switch: '<S45>/Switch1' incorporates:
   *  Abs: '<S45>/Abs'
   *  Product: '<S45>/Product4'
   *  RelationalOperator: '<S45>/Relational Operator'
   *  RelationalOperator: '<S45>/Relational Operator1'
   *  Switch: '<S45>/Switch2'
   */
  if (rtb_MathReciprocal == VfACCS_Obs_Lat_OBFU)
  {
    rtb_Switch2_lvye = (real32_T)((real_T)(ACCS_subsystem_integrate_ConstB.Gain *
      ((real_T)rtb_Switch_n0oh)));
  }
  else if (((real32_T)fabs((real_T)rtb_MathReciprocal)) > rtb_Switch2_lvye)
  {
    /* MinMax: '<S45>/Max2' incorporates:
     *  Constant: '<S45>/Constant31'
     *  Sum: '<S45>/Add2'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(rtb_MathReciprocal -
      VfACCS_Obs_Lat_OBFU));
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S45>/Switch2' incorporates:
     *  Product: '<S45>/Divide1'
     *  Trigonometry: '<S45>/Atan1'
     */
    rtb_Switch2_lvye = (real32_T)atan((real_T)((real32_T)((real_T)(((real_T)
      VfACCS_Obs_Long_OBFU) / rtb_Switch5_blbp))));
  }
  else
  {
    /* MinMax: '<S45>/Max2' incorporates:
     *  Constant: '<S45>/Constant31'
     *  Sum: '<S45>/Add2'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(rtb_MathReciprocal -
      VfACCS_Obs_Lat_OBFU));
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S45>/Switch2' incorporates:
     *  Product: '<S45>/Divide1'
     *  Product: '<S45>/Product5'
     *  Sum: '<S45>/Add3'
     *  Trigonometry: '<S45>/Atan1'
     */
    rtb_Switch2_lvye = ((real32_T)((real_T)(((real_T)rtb_Switch_n0oh) *
      ACCS_subsystem_integrate_ConstB.Gain2))) + ((real32_T)atan((real_T)
      ((real32_T)((real_T)(((real_T)VfACCS_Obs_Long_OBFU) / rtb_Switch5_blbp)))));
  }

  /* Switch: '<S45>/Switch3' incorporates:
   *  Constant: '<S45>/Constant7'
   *  Product: '<S45>/Product6'
   *  RelationalOperator: '<S45>/Relational Operator2'
   */
  if (rtb_MathReciprocal > KfACCS_d_CurvatureRadius_Max)
  {
    rtb_Switch_n0oh = VfACCS_Obs_Long_OBFU;
  }
  else
  {
    rtb_Switch_n0oh = rtb_Switch2_lvye * rtb_MathReciprocal;
  }

  /* End of Switch: '<S45>/Switch3' */

  /* Sum: '<S45>/Add4' incorporates:
   *  Constant: '<S45>/Constant13'
   *  Constant: '<S45>/Constant8'
   *  Product: '<S45>/Product7'
   */
  rtb_Add11_hcma = (rtb_Switch_n0oh - KfACCS_d_DisToLeadSur) +
    (KfACCS_t_TimeOffset * rtb_Sum_nujo);

  /* Product: '<S53>/Product' incorporates:
   *  Constant: '<S45>/Constant46'
   */
  rtb_Switch_n0oh = KfACCS_k_ObjectRangeFilter * rtb_Add11_hcma;

  /* Switch: '<S53>/Switch' incorporates:
   *  UnitDelay: '<S53>/Unit Delay'
   */
  if (rtb_RelationalOperator14)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_kvni;
  }

  /* End of Switch: '<S53>/Switch' */

  /* Sum: '<S53>/Subtract' incorporates:
   *  Constant: '<S45>/Constant46'
   *  Constant: '<S53>/Constant'
   *  Sum: '<S101>/Subtract'
   *  Sum: '<S102>/Subtract'
   *  Sum: '<S54>/Subtract'
   *  Sum: '<S73>/Subtract'
   *  Sum: '<S74>/Subtract'
   *  Sum: '<S80>/Subtract'
   *  Sum: '<S81>/Subtract'
   *  Sum: '<S87>/Subtract'
   *  Sum: '<S88>/Subtract'
   *  Sum: '<S94>/Subtract'
   *  Sum: '<S95>/Subtract'
   */
  rtb_Switch_iliv_tmp = 1.0F - KfACCS_k_ObjectRangeFilter;

  /* Sum: '<S53>/Sum' incorporates:
   *  Product: '<S53>/Product1'
   *  Sum: '<S53>/Subtract'
   */
  rtb_Switch_n0oh += rtb_Add11_hcma * rtb_Switch_iliv_tmp;

  /* Switch: '<S60>/Switch1' incorporates:
   *  UnitDelay: '<S60>/Unit Delay1'
   *  UnitDelay: '<S60>/Unit Delay2'
   */
  if (rtb_LogicalOperator1)
  {
    rtb_Switch1_gcg5 = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_akoi;
  }
  else
  {
    rtb_Switch1_gcg5 = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_perp;
  }

  /* End of Switch: '<S60>/Switch1' */

  /* Switch: '<S60>/Switch4' incorporates:
   *  Constant: '<S60>/Constant3'
   *  Constant: '<S60>/Constant5'
   *  Saturate: '<S60>/Saturation'
   *  Sum: '<S60>/Add3'
   *  Switch: '<S60>/Switch2'
   *  UnitDelay: '<S60>/Unit Delay'
   */
  if (rtb_LogicalOperator3_g0tf)
  {
    rtb_Switch2_ciy1 = 0.0F;
  }
  else
  {
    if (rtb_LogicalOperator1)
    {
      /* Switch: '<S60>/Switch2' incorporates:
       *  Constant: '<S60>/Constant4'
       */
      rtb_Switch2_ciy1 = KfACCS_t_CIPVDisappearDelay;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_k1rh > 10.0F)
    {
      /* Saturate: '<S60>/Saturation' incorporates:
       *  Switch: '<S60>/Switch2'
       */
      rtb_Switch2_ciy1 = 10.0F;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_k1rh < 0.0F)
    {
      /* Saturate: '<S60>/Saturation' incorporates:
       *  Switch: '<S60>/Switch2'
       */
      rtb_Switch2_ciy1 = 0.0F;
    }
    else
    {
      /* Switch: '<S60>/Switch2' incorporates:
       *  Saturate: '<S60>/Saturation'
       *  UnitDelay: '<S60>/Unit Delay'
       */
      rtb_Switch2_ciy1 = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_k1rh;
    }

    rtb_Switch2_ciy1 -= 0.01F;
  }

  /* End of Switch: '<S60>/Switch4' */

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S48>/Constant'
   */
  if (VbACCS_Input_Obs_valid)
  {
    /* Switch: '<S60>/Switch' */
    if (rtb_Switch2_ciy1 > 0.0F)
    {
      VfACCS_Input_Obs_Range = rtb_Switch1_gcg5;
    }
    else
    {
      VfACCS_Input_Obs_Range = rtb_Switch_n0oh;
    }

    /* End of Switch: '<S60>/Switch' */
  }
  else
  {
    VfACCS_Input_Obs_Range = 150.0F;
  }

  /* End of Switch: '<S48>/Switch' */

  /* Switch: '<S45>/Switch4' incorporates:
   *  Constant: '<S45>/Constant9'
   *  RelationalOperator: '<S45>/Relational Operator3'
   */
  if (rtb_MathReciprocal > KfACCS_d_CurvatureRadius_Max)
  {
    rtb_Add11_hcma = VfACCS_Obs_Lat_OBFU;
  }
  else
  {
    /* Trigonometry: '<S45>/Sin2' */
    rtb_Switch2_lvye = (real32_T)sin((real_T)rtb_Switch2_lvye);

    /* Switch: '<S45>/Switch5' incorporates:
     *  Abs: '<S45>/Abs2'
     *  Constant: '<S45>/Constant11'
     *  Constant: '<S45>/Constant12'
     *  Product: '<S45>/Divide2'
     *  RelationalOperator: '<S45>/Relational Operator4'
     *  Sum: '<S45>/Add6'
     */
    if (((real_T)((real32_T)fabs((real_T)rtb_Switch2_lvye))) > 0.01)
    {
      /* MinMax: '<S45>/Max' incorporates:
       *  Constant: '<S45>/Constant5'
       */
      if (((real_T)rtb_Switch2_lvye) > 1.0E-6)
      {
        rtb_Switch5_nscd = (real_T)rtb_Switch2_lvye;
      }
      else
      {
        rtb_Switch5_nscd = 1.0E-6;
      }

      /* End of MinMax: '<S45>/Max' */
      rtb_Switch5_nscd = (real_T)((real32_T)(rtb_MathReciprocal - ((real32_T)
        ((real_T)(((real_T)VfACCS_Obs_Long_OBFU) / rtb_Switch5_nscd)))));
    }
    else
    {
      rtb_Switch5_nscd = 0.0;
    }

    /* End of Switch: '<S45>/Switch5' */
    rtb_Add11_hcma = (real32_T)rtb_Switch5_nscd;
  }

  /* End of Switch: '<S45>/Switch4' */

  /* Sum: '<S45>/Add5' incorporates:
   *  Constant: '<S45>/Constant10'
   *  Constant: '<S45>/Constant14'
   *  Product: '<S45>/Product8'
   */
  rtb_Add11_hcma = (rtb_Add11_hcma - KfACCS_d_DisToSideSur) +
    (KfACCS_t_TimeOffset * rtb_Abs3);

  /* Product: '<S54>/Product' incorporates:
   *  Constant: '<S45>/Constant15'
   */
  rtb_MathReciprocal = KfACCS_k_ObjectRangeFilter * rtb_Add11_hcma;

  /* Switch: '<S54>/Switch' incorporates:
   *  UnitDelay: '<S54>/Unit Delay'
   */
  if (rtb_RelationalOperator14)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_c2bu;
  }

  /* End of Switch: '<S54>/Switch' */

  /* Sum: '<S54>/Sum' incorporates:
   *  Product: '<S54>/Product1'
   */
  rtb_MathReciprocal += rtb_Add11_hcma * rtb_Switch_iliv_tmp;

  /* Switch: '<S56>/Switch' incorporates:
   *  Abs: '<S56>/Abs3'
   *  Constant: '<S56>/Constant15'
   *  Constant: '<S56>/Constant5'
   *  Delay: '<S56>/Delay12'
   *  RelationalOperator: '<S56>/Relational Operator8'
   */
  if (((real32_T)fabs((real_T)
                      ACCS_subsystem_integrated_B.VfACCS_Input_Yawrate_EGMO)) >=
      KfACCS_Ang_DtrmSelfChangeLane)
  {
    rtb_Switch5_blbp = ACCS_subsystem_integrated_DW.Delay12_DSTATE;
  }
  else
  {
    rtb_Switch5_blbp = 0.0;
  }

  /* End of Switch: '<S56>/Switch' */

  /* Sum: '<S56>/Add3' incorporates:
   *  Constant: '<S56>/Constant6'
   */
  rtb_Switch5_nscd = rtb_Switch5_blbp + 0.01;

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S56>/Constant18'
   *  Constant: '<S57>/Constant'
   *  Constant: '<S57>/Constant1'
   *  RelationalOperator: '<S56>/Relational Operator17'
   *  Sum: '<S57>/Sum'
   *  UnitDelay: '<S57>/Unit Delay'
   */
  if (rtb_Switch5_nscd >= ((real_T)KfACCS_t_DtrmSelfChangeLane))
  {
    rtb_Switch = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_gzqw + 1.0;
  }
  else
  {
    rtb_Switch = 0.0;
  }

  /* End of Switch: '<S57>/Switch' */

  /* Switch: '<S44>/Switch12' incorporates:
   *  Constant: '<S44>/Constant30'
   *  Product: '<S44>/Product12'
   *  Product: '<S44>/Product13'
   *  Sum: '<S44>/Add12'
   *  Sum: '<S44>/Add13'
   *  Sum: '<S44>/Add14'
   *  Sum: '<S44>/Add15'
   */
  if (KeACCS_RRCalMetdType > ((uint8_T)0U))
  {
    rtb_Switch11 = rtb_Add11 - VfACCS_Input_linear_velocity_EGMO;
  }
  else
  {
    rtb_Switch11 = ((rtb_Sum_nujo - VfACCS_Input_longvelocity_EGMO) *
                    rtb_MathReciprocal_ashu) + ((rtb_Abs3 -
      VfACCS_Input_latvelocity_EGMO) * rtb_Switch11_lqzi);
  }

  /* UnitDelay: '<S56>/Unit Delay2' */
  rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_ewh0;

  /* Chart: '<S46>/Dtrmn_CIPVChangedType' incorporates:
   *  Abs: '<S56>/Abs'
   *  Abs: '<S56>/Abs1'
   *  Abs: '<S56>/Abs2'
   *  Constant: '<S56>/Constant'
   *  Constant: '<S56>/Constant1'
   *  Constant: '<S56>/Constant10'
   *  Constant: '<S56>/Constant11'
   *  Constant: '<S56>/Constant12'
   *  Constant: '<S56>/Constant13'
   *  Constant: '<S56>/Constant14'
   *  Constant: '<S56>/Constant16'
   *  Constant: '<S56>/Constant17'
   *  Constant: '<S56>/Constant19'
   *  Constant: '<S56>/Constant2'
   *  Constant: '<S56>/Constant20'
   *  Constant: '<S56>/Constant21'
   *  Constant: '<S56>/Constant22'
   *  Constant: '<S56>/Constant23'
   *  Constant: '<S56>/Constant24'
   *  Constant: '<S56>/Constant25'
   *  Constant: '<S56>/Constant26'
   *  Constant: '<S56>/Constant3'
   *  Constant: '<S56>/Constant4'
   *  Constant: '<S56>/Constant7'
   *  Constant: '<S56>/Constant8'
   *  Constant: '<S56>/Constant9'
   *  Delay: '<S46>/Delay10'
   *  Delay: '<S56>/Delay'
   *  Delay: '<S56>/Delay1'
   *  Delay: '<S56>/Delay10'
   *  Delay: '<S56>/Delay11'
   *  Delay: '<S56>/Delay13'
   *  Delay: '<S56>/Delay2'
   *  Delay: '<S56>/Delay3'
   *  Delay: '<S56>/Delay4'
   *  Delay: '<S56>/Delay5'
   *  Delay: '<S56>/Delay6'
   *  Delay: '<S56>/Delay7'
   *  Delay: '<S56>/Delay8'
   *  Delay: '<S56>/Delay9'
   *  Gain: '<S56>/Gain'
   *  Logic: '<S56>/Logical Operator'
   *  Logic: '<S56>/Logical Operator10'
   *  Logic: '<S56>/Logical Operator11'
   *  Logic: '<S56>/Logical Operator12'
   *  Logic: '<S56>/Logical Operator13'
   *  Logic: '<S56>/Logical Operator14'
   *  Logic: '<S56>/Logical Operator15'
   *  Logic: '<S56>/Logical Operator16'
   *  Logic: '<S56>/Logical Operator17'
   *  Logic: '<S56>/Logical Operator18'
   *  Logic: '<S56>/Logical Operator19'
   *  Logic: '<S56>/Logical Operator2'
   *  Logic: '<S56>/Logical Operator20'
   *  Logic: '<S56>/Logical Operator3'
   *  Logic: '<S56>/Logical Operator4'
   *  Logic: '<S56>/Logical Operator5'
   *  Logic: '<S56>/Logical Operator8'
   *  Logic: '<S56>/Logical Operator9'
   *  Product: '<S57>/Divide'
   *  RelationalOperator: '<S56>/Relational Operator'
   *  RelationalOperator: '<S56>/Relational Operator1'
   *  RelationalOperator: '<S56>/Relational Operator10'
   *  RelationalOperator: '<S56>/Relational Operator11'
   *  RelationalOperator: '<S56>/Relational Operator12'
   *  RelationalOperator: '<S56>/Relational Operator13'
   *  RelationalOperator: '<S56>/Relational Operator14'
   *  RelationalOperator: '<S56>/Relational Operator15'
   *  RelationalOperator: '<S56>/Relational Operator16'
   *  RelationalOperator: '<S56>/Relational Operator18'
   *  RelationalOperator: '<S56>/Relational Operator19'
   *  RelationalOperator: '<S56>/Relational Operator2'
   *  RelationalOperator: '<S56>/Relational Operator20'
   *  RelationalOperator: '<S56>/Relational Operator21'
   *  RelationalOperator: '<S56>/Relational Operator22'
   *  RelationalOperator: '<S56>/Relational Operator23'
   *  RelationalOperator: '<S56>/Relational Operator24'
   *  RelationalOperator: '<S56>/Relational Operator25'
   *  RelationalOperator: '<S56>/Relational Operator3'
   *  RelationalOperator: '<S56>/Relational Operator4'
   *  RelationalOperator: '<S56>/Relational Operator5'
   *  RelationalOperator: '<S56>/Relational Operator6'
   *  RelationalOperator: '<S56>/Relational Operator7'
   *  RelationalOperator: '<S56>/Relational Operator9'
   *  RelationalOperator: '<S57>/Relational Operator'
   *  Sum: '<S56>/Add'
   *  Sum: '<S56>/Add1'
   *  Sum: '<S56>/Add2'
   *  UnitDelay: '<S56>/Unit Delay'
   *  UnitDelay: '<S56>/Unit Delay1'
   */
  if ((((ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id !=
         ACCS_subsystem_integrated_DW.Delay_DSTATE_kclz) && (((real32_T)fabs
          ((real_T)((real32_T)(rtb_Switch_n0oh -
             ACCS_subsystem_integrated_DW.Delay1_DSTATE)))) >=
         KfACCS_d_ChangedObsRangeLongDiff)) && (((real32_T)fabs((real_T)
          ((real32_T)(rtb_MathReciprocal -
                      ACCS_subsystem_integrated_DW.Delay2_DSTATE)))) >=
        KfACCS_d_ChangedObsRangeLatDiff)) && (((real32_T)fabs((real_T)((real32_T)
          (rtb_Add11 - ACCS_subsystem_integrated_DW.Delay3_DSTATE)))) >=
       KfACCS_v_ChangedObsVelDiff))
  {
    if (ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.is_cutin)
    {
      rtb_CIPVChangedType = CutIn;
    }
    else if (ACCS_subsystem_integrated_DW.Delay10_DSTATE_iwrp)
    {
      rtb_CIPVChangedType = CutOut;
    }
    else if (((((ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v ?
                 1.0 : 0.0) == 1.0) &&
               ((ACCS_subsystem_integrated_DW.Delay4_DSTATE ? 1.0 : 0.0) == 0.0))
              && (rtb_Switch_n0oh >= (0.0666666701F *
                KfACCS_d_RangeForApproaching))) && (rtb_Switch11 <
              KfACCS_v_RangeRateForApproaching))
    {
      rtb_CIPVChangedType = Approaching;
    }
    else if ((((ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v ==
                false) && (ACCS_subsystem_integrated_DW.Delay6_DSTATE == true)) &&
              (ACCS_subsystem_integrated_DW.Delay10_DSTATE[0] >=
               KfACCS_d_RangeForAway)) &&
             (ACCS_subsystem_integrated_DW.Delay7_DSTATE >
              KfACCS_v_RangeRateForAway))
    {
      rtb_CIPVChangedType = Away;
    }
    else if ((rtb_Switch >= (((real_T)KfACCS_t_DtrmSelfChangeLaneDelay) / 0.01))
             && ((((((ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVR_valid) &&
                     (ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id ==
                      ACCS_subsystem_integrated_DW.Delay8_DSTATE)) &&
                    (!ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.is_cutin))
                   ||
                   (((ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVL_valid) &&
                     (ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id ==
                      ACCS_subsystem_integrated_DW.Delay9_DSTATE)) &&
                    (!ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.is_cutin)))
                  || ((ACCS_subsystem_integrated_DW.Delay5_DSTATE) && (((real_T)
                  ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id) == 0.0)))
                 || ((ACCS_subsystem_integrated_DW.Delay11_DSTATE_dnza) &&
                     (((real_T)
                       ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id) ==
                      0.0))))
    {
      rtb_CIPVChangedType = SelfChangeLane;
    }
    else if (((((ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v ==
                 false) && (ACCS_subsystem_integrated_DW.Delay13_DSTATE == true))
               && ((ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_obhi <=
                    KfACCS_d_LonRangeMaxForCloseDisappear) &&
                   (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_obhi >=
                    KfACCS_d_LonRangeMinForCloseDisappear))) &&
              ((ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_pkqb <=
                KfACCS_d_LatRangeMaxForCloseDisappear) &&
               (ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_pkqb >=
                KfACCS_d_LatRangeMinForCloseDisappear))) && ((rtb_Add11_hcma <=
               KfACCS_v_SpdMaxForCloseDisappear) && (((real_T)rtb_Add11_hcma) >=
               KfACCS_v_SpdMinForCloseDisappear)))
    {
      rtb_CIPVChangedType = CloseDisappearing;
    }
    else
    {
      rtb_CIPVChangedType = Unknown;
    }
  }
  else
  {
    rtb_CIPVChangedType = Normal;
  }

  /* End of Chart: '<S46>/Dtrmn_CIPVChangedType' */

  /* Switch: '<S46>/Switch' incorporates:
   *  Constant: '<S46>/Constant3'
   *  Constant: '<S46>/Constant4'
   *  Delay: '<S46>/Delay11'
   *  RelationalOperator: '<S46>/Relational Operator11'
   *  Saturate: '<S46>/Saturation'
   */
  if (rtb_CIPVChangedType != Normal)
  {
    rtb_Add11_hcma = KfACCS_t_CIPVChangedTypeDelay;
  }
  else if (ACCS_subsystem_integrated_DW.Delay11_DSTATE > 10.0F)
  {
    /* Saturate: '<S46>/Saturation' */
    rtb_Add11_hcma = 10.0F;
  }
  else if (ACCS_subsystem_integrated_DW.Delay11_DSTATE < 0.0F)
  {
    /* Saturate: '<S46>/Saturation' */
    rtb_Add11_hcma = 0.0F;
  }
  else
  {
    /* Saturate: '<S46>/Saturation' incorporates:
     *  Delay: '<S46>/Delay11'
     */
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.Delay11_DSTATE;
  }

  /* End of Switch: '<S46>/Switch' */

  /* Sum: '<S46>/Add3' incorporates:
   *  Constant: '<S46>/Constant5'
   */
  rtb_Switch2_lvye = (real32_T)((real_T)(((real_T)rtb_Add11_hcma) - 0.01));

  /* Switch: '<S46>/Switch2' incorporates:
   *  Constant: '<S46>/Constant18'
   *  Delay: '<S46>/Delay12'
   *  RelationalOperator: '<S46>/Relational Operator12'
   */
  if (rtb_CIPVChangedType == Normal)
  {
    rtb_CIPVChangedType = ACCS_subsystem_integrated_DW.Delay12_DSTATE_jlce;
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Switch: '<S46>/Switch1' */
  if (rtb_Switch2_lvye > 0.0F)
  {
    /* SignalConversion: '<S48>/Signal Conversion3' */
    VeACCS_CIPVChangedType = rtb_CIPVChangedType;
  }
  else
  {
    /* SignalConversion: '<S48>/Signal Conversion3' incorporates:
     *  Constant: '<S46>/Constant6'
     */
    VeACCS_CIPVChangedType = Normal;
  }

  /* End of Switch: '<S46>/Switch1' */

  /* RelationalOperator: '<S47>/Relational Operator1' incorporates:
   *  Constant: '<S47>/Constant7'
   */
  rtb_RelationalOperator14 = (rtb_Switch_n0oh <= KfACCS_d_FlickerRangeLongLimit);

  /* RelationalOperator: '<S47>/Relational Operator2' incorporates:
   *  Abs: '<S47>/Abs1'
   *  Constant: '<S47>/Constant1'
   */
  rtb_RelationalOperator2_f3ty = (((real32_T)fabs((real_T)rtb_Switch11)) <=
    KfACCS_d_FlickerRangeLatLimit);

  /* Logic: '<S47>/Logical Operator4' incorporates:
   *  Constant: '<S47>/Constant4'
   *  Logic: '<S47>/Logical Operator1'
   *  Logic: '<S47>/Logical Operator2'
   *  Logic: '<S47>/Logical Operator3'
   *  RelationalOperator: '<S47>/Relational Operator6'
   */
  rtb_LogicalOperator4_fmdb =
    ((((!ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v) ||
       (!rtb_RelationalOperator14)) || (!rtb_RelationalOperator2_f3ty)) ||
     (rtb_MathReciprocal >= KfACCS_v_FlickerRangeRRForReset));

  /* Chart: '<S47>/Chart' incorporates:
   *  Abs: '<S47>/Abs'
   *  Constant: '<S47>/Constant2'
   *  Constant: '<S47>/Constant3'
   *  Constant: '<S47>/Constant6'
   *  Constant: '<S47>/Constant8'
   *  Delay: '<S47>/Delay'
   *  Delay: '<S47>/Delay1'
   *  Delay: '<S47>/Delay2'
   *  Logic: '<S47>/Logical Operator'
   *  RelationalOperator: '<S47>/Relational Operator'
   *  RelationalOperator: '<S47>/Relational Operator3'
   *  RelationalOperator: '<S47>/Relational Operator4'
   *  RelationalOperator: '<S47>/Relational Operator5'
   *  Sum: '<S47>/Add'
   */
  if (rtb_LogicalOperator4_fmdb)
  {
    ACCS_subsystem_integrated_DW.LastFlickerObsID = 0;
    ACCS_subsystem_integrated_DW.FlickerTimeCount = 0U;
  }

  if (((((((ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v) &&
           (ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id ==
            ACCS_subsystem_integrated_DW.Delay_DSTATE_jbar)) &&
          rtb_RelationalOperator14) && (((real32_T)fabs((real_T)((real32_T)
             (rtb_Switch_n0oh - ACCS_subsystem_integrated_DW.Delay1_DSTATE_jitl))))
          >= KfACCS_d_FlickerRangeDiffLimit)) && rtb_RelationalOperator2_f3ty) &&
       (rtb_MathReciprocal <= KfACCS_v_FlickerRangeRateLimit)) &&
      (VfACCS_Input_linear_velocity_EGMO <= KfACCS_v_FlickerRangeEgoSpd))
  {
    if (ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id !=
        ACCS_subsystem_integrated_DW.LastFlickerObsID)
    {
      ACCS_subsystem_integrated_DW.FlickerTimeCount = 0U;
    }

    tmp = ((uint32_T)ACCS_subsystem_integrated_DW.FlickerTimeCount) + 1U;
    if (tmp > 65535U)
    {
      tmp = 65535U;
    }

    ACCS_subsystem_integrated_DW.FlickerTimeCount = (uint16_T)tmp;
    if (((int32_T)ACCS_subsystem_integrated_DW.FlickerTimeCount) >= 100)
    {
      ACCS_subsystem_integrated_DW.FlickerTimeCount = 100U;
    }

    if (((real32_T)ACCS_subsystem_integrated_DW.FlickerTimeCount) >=
        KcACCS_DtrmFlickerThresh)
    {
      ACCS_subsystem_integrated_B.RangeFlickerObs = true;
    }
    else
    {
      ACCS_subsystem_integrated_DW.LastFlickerObsID =
        ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id;
    }
  }
  else
  {
    ACCS_subsystem_integrated_B.RangeFlickerObs =
      ((ACCS_subsystem_integrated_B.RangeFlickerObs) &&
       (!rtb_LogicalOperator4_fmdb));
  }

  /* End of Chart: '<S47>/Chart' */

  /* SignalConversion: '<S48>/Signal Conversion1' */
  VbACCS_CIPVObsRangeFlicker = ACCS_subsystem_integrated_B.RangeFlickerObs;

  /* Switch: '<S64>/Switch1' incorporates:
   *  UnitDelay: '<S64>/Unit Delay1'
   *  UnitDelay: '<S64>/Unit Delay2'
   */
  if (rtb_LogicalOperator1)
  {
    rtb_Switch1_pa3i = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_pkvt;
  }
  else
  {
    rtb_Switch1_pa3i = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_lu5x;
  }

  /* End of Switch: '<S64>/Switch1' */

  /* Switch: '<S64>/Switch4' incorporates:
   *  Constant: '<S64>/Constant3'
   *  Constant: '<S64>/Constant5'
   *  Saturate: '<S64>/Saturation'
   *  Sum: '<S64>/Add3'
   *  Switch: '<S64>/Switch2'
   *  UnitDelay: '<S64>/Unit Delay'
   */
  if (rtb_LogicalOperator3_g0tf)
  {
    rtb_Switch2_nhsq = 0.0F;
  }
  else
  {
    if (rtb_LogicalOperator1)
    {
      /* Switch: '<S64>/Switch2' incorporates:
       *  Constant: '<S64>/Constant4'
       */
      rtb_Switch2_nhsq = KfACCS_t_CIPVDisappearDelay;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mi5a > 10.0F)
    {
      /* Saturate: '<S64>/Saturation' incorporates:
       *  Switch: '<S64>/Switch2'
       */
      rtb_Switch2_nhsq = 10.0F;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mi5a < 0.0F)
    {
      /* Saturate: '<S64>/Saturation' incorporates:
       *  Switch: '<S64>/Switch2'
       */
      rtb_Switch2_nhsq = 0.0F;
    }
    else
    {
      /* Switch: '<S64>/Switch2' incorporates:
       *  Saturate: '<S64>/Saturation'
       *  UnitDelay: '<S64>/Unit Delay'
       */
      rtb_Switch2_nhsq = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mi5a;
    }

    rtb_Switch2_nhsq -= 0.01F;
  }

  /* End of Switch: '<S64>/Switch4' */

  /* Switch: '<S48>/Switch4' incorporates:
   *  Constant: '<S48>/Constant4'
   */
  if (VbACCS_Input_Obs_valid)
  {
    /* Switch: '<S64>/Switch' */
    if (rtb_Switch2_nhsq > 0.0F)
    {
      VfACCS_Input_Obs_Rangerate = rtb_Switch1_pa3i;
    }
    else
    {
      VfACCS_Input_Obs_Rangerate = rtb_Switch11;
    }

    /* End of Switch: '<S64>/Switch' */
  }
  else
  {
    VfACCS_Input_Obs_Rangerate = 0.0F;
  }

  /* End of Switch: '<S48>/Switch4' */

  /* Switch: '<S61>/Switch1' incorporates:
   *  UnitDelay: '<S61>/Unit Delay1'
   *  UnitDelay: '<S61>/Unit Delay2'
   */
  if (rtb_LogicalOperator1)
  {
    rtb_Switch1_k02x = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_dtcn;
  }
  else
  {
    rtb_Switch1_k02x = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_ffnd;
  }

  /* End of Switch: '<S61>/Switch1' */

  /* Switch: '<S61>/Switch4' incorporates:
   *  Constant: '<S61>/Constant3'
   *  Constant: '<S61>/Constant5'
   *  Saturate: '<S61>/Saturation'
   *  Sum: '<S61>/Add3'
   *  Switch: '<S61>/Switch2'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  if (rtb_LogicalOperator3_g0tf)
  {
    rtb_Switch2_kl5r = 0.0F;
  }
  else
  {
    if (rtb_LogicalOperator1)
    {
      /* Switch: '<S61>/Switch2' incorporates:
       *  Constant: '<S61>/Constant4'
       */
      rtb_Switch2_kl5r = KfACCS_t_CIPVDisappearDelay;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_gu2l > 10.0F)
    {
      /* Saturate: '<S61>/Saturation' incorporates:
       *  Switch: '<S61>/Switch2'
       */
      rtb_Switch2_kl5r = 10.0F;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_gu2l < 0.0F)
    {
      /* Saturate: '<S61>/Saturation' incorporates:
       *  Switch: '<S61>/Switch2'
       */
      rtb_Switch2_kl5r = 0.0F;
    }
    else
    {
      /* Switch: '<S61>/Switch2' incorporates:
       *  Saturate: '<S61>/Saturation'
       *  UnitDelay: '<S61>/Unit Delay'
       */
      rtb_Switch2_kl5r = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_gu2l;
    }

    rtb_Switch2_kl5r -= 0.01F;
  }

  /* End of Switch: '<S61>/Switch4' */

  /* Switch: '<S48>/Switch1' incorporates:
   *  Constant: '<S48>/Constant1'
   */
  if (VbACCS_Input_Obs_valid)
  {
    /* Switch: '<S61>/Switch' */
    if (rtb_Switch2_kl5r > 0.0F)
    {
      VfACCS_Input_Obs_LatDis = rtb_Switch1_k02x;
    }
    else
    {
      VfACCS_Input_Obs_LatDis = rtb_MathReciprocal;
    }

    /* End of Switch: '<S61>/Switch' */
  }
  else
  {
    VfACCS_Input_Obs_LatDis = 10.0F;
  }

  /* End of Switch: '<S48>/Switch1' */

  /* Switch: '<S62>/Switch1' incorporates:
   *  UnitDelay: '<S62>/Unit Delay1'
   *  UnitDelay: '<S62>/Unit Delay2'
   */
  if (rtb_LogicalOperator1)
  {
    rtb_Switch1_oyua = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_lrqq;
  }
  else
  {
    rtb_Switch1_oyua = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_jbin;
  }

  /* End of Switch: '<S62>/Switch1' */

  /* Switch: '<S62>/Switch4' incorporates:
   *  Constant: '<S62>/Constant3'
   *  Constant: '<S62>/Constant5'
   *  Saturate: '<S62>/Saturation'
   *  Sum: '<S62>/Add3'
   *  Switch: '<S62>/Switch2'
   *  UnitDelay: '<S62>/Unit Delay'
   */
  if (rtb_LogicalOperator3_g0tf)
  {
    rtb_Switch2_kzlb = 0.0F;
  }
  else
  {
    if (rtb_LogicalOperator1)
    {
      /* Switch: '<S62>/Switch2' incorporates:
       *  Constant: '<S62>/Constant4'
       */
      rtb_Switch2_kzlb = KfACCS_t_CIPVDisappearDelay;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ckgq > 10.0F)
    {
      /* Saturate: '<S62>/Saturation' incorporates:
       *  Switch: '<S62>/Switch2'
       */
      rtb_Switch2_kzlb = 10.0F;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ckgq < 0.0F)
    {
      /* Saturate: '<S62>/Saturation' incorporates:
       *  Switch: '<S62>/Switch2'
       */
      rtb_Switch2_kzlb = 0.0F;
    }
    else
    {
      /* Switch: '<S62>/Switch2' incorporates:
       *  Saturate: '<S62>/Saturation'
       *  UnitDelay: '<S62>/Unit Delay'
       */
      rtb_Switch2_kzlb = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ckgq;
    }

    rtb_Switch2_kzlb -= 0.01F;
  }

  /* End of Switch: '<S62>/Switch4' */

  /* Switch: '<S48>/Switch2' incorporates:
   *  Constant: '<S48>/Constant2'
   */
  if (VbACCS_Input_Obs_valid)
  {
    /* Switch: '<S62>/Switch' */
    if (rtb_Switch2_kzlb > 0.0F)
    {
      VfACCS_Input_Obs_Long_VFiltered = rtb_Switch1_oyua;
    }
    else
    {
      VfACCS_Input_Obs_Long_VFiltered = rtb_Sum_nujo;
    }

    /* End of Switch: '<S62>/Switch' */
  }
  else
  {
    VfACCS_Input_Obs_Long_VFiltered = 0.0F;
  }

  /* End of Switch: '<S48>/Switch2' */

  /* Switch: '<S63>/Switch1' incorporates:
   *  UnitDelay: '<S63>/Unit Delay1'
   *  UnitDelay: '<S63>/Unit Delay2'
   */
  if (rtb_LogicalOperator1)
  {
    rtb_Switch1_l00p = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_opog;
  }
  else
  {
    rtb_Switch1_l00p = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_pq2g;
  }

  /* End of Switch: '<S63>/Switch1' */

  /* Switch: '<S63>/Switch4' incorporates:
   *  Constant: '<S63>/Constant3'
   *  Constant: '<S63>/Constant5'
   *  Saturate: '<S63>/Saturation'
   *  Sum: '<S63>/Add3'
   *  Switch: '<S63>/Switch2'
   *  UnitDelay: '<S63>/Unit Delay'
   */
  if (rtb_LogicalOperator3_g0tf)
  {
    rtb_Switch2_du1h = 0.0F;
  }
  else
  {
    if (rtb_LogicalOperator1)
    {
      /* Switch: '<S63>/Switch2' incorporates:
       *  Constant: '<S63>/Constant4'
       */
      rtb_Switch2_du1h = KfACCS_t_CIPVDisappearDelay;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_pimc > 10.0F)
    {
      /* Saturate: '<S63>/Saturation' incorporates:
       *  Switch: '<S63>/Switch2'
       */
      rtb_Switch2_du1h = 10.0F;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_pimc < 0.0F)
    {
      /* Saturate: '<S63>/Saturation' incorporates:
       *  Switch: '<S63>/Switch2'
       */
      rtb_Switch2_du1h = 0.0F;
    }
    else
    {
      /* Switch: '<S63>/Switch2' incorporates:
       *  Saturate: '<S63>/Saturation'
       *  UnitDelay: '<S63>/Unit Delay'
       */
      rtb_Switch2_du1h = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_pimc;
    }

    rtb_Switch2_du1h -= 0.01F;
  }

  /* End of Switch: '<S63>/Switch4' */

  /* Switch: '<S48>/Switch3' incorporates:
   *  Constant: '<S48>/Constant3'
   */
  if (VbACCS_Input_Obs_valid)
  {
    /* Switch: '<S63>/Switch' */
    if (rtb_Switch2_du1h > 0.0F)
    {
      VfACCS_Input_Obs_Lat_VFiltered = rtb_Switch1_l00p;
    }
    else
    {
      VfACCS_Input_Obs_Lat_VFiltered = rtb_Abs3;
    }

    /* End of Switch: '<S63>/Switch' */
  }
  else
  {
    VfACCS_Input_Obs_Lat_VFiltered = 0.0F;
  }

  /* End of Switch: '<S48>/Switch3' */

  /* Switch: '<S65>/Switch1' incorporates:
   *  UnitDelay: '<S65>/Unit Delay1'
   *  UnitDelay: '<S65>/Unit Delay2'
   */
  if (rtb_LogicalOperator1)
  {
    rtb_Switch1_ic0c = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_eatc;
  }
  else
  {
    rtb_Switch1_ic0c = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_b45d;
  }

  /* End of Switch: '<S65>/Switch1' */

  /* Switch: '<S65>/Switch4' incorporates:
   *  Constant: '<S65>/Constant3'
   *  Constant: '<S65>/Constant5'
   *  Saturate: '<S65>/Saturation'
   *  Sum: '<S65>/Add3'
   *  Switch: '<S65>/Switch2'
   *  UnitDelay: '<S65>/Unit Delay'
   */
  if (rtb_LogicalOperator3_g0tf)
  {
    rtb_Switch2_krvg = 0.0F;
  }
  else
  {
    if (rtb_LogicalOperator1)
    {
      /* Switch: '<S65>/Switch2' incorporates:
       *  Constant: '<S65>/Constant4'
       */
      rtb_Switch2_krvg = KfACCS_t_CIPVDisappearDelay;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_nqfg > 10.0F)
    {
      /* Saturate: '<S65>/Saturation' incorporates:
       *  Switch: '<S65>/Switch2'
       */
      rtb_Switch2_krvg = 10.0F;
    }
    else if (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_nqfg < 0.0F)
    {
      /* Saturate: '<S65>/Saturation' incorporates:
       *  Switch: '<S65>/Switch2'
       */
      rtb_Switch2_krvg = 0.0F;
    }
    else
    {
      /* Switch: '<S65>/Switch2' incorporates:
       *  Saturate: '<S65>/Saturation'
       *  UnitDelay: '<S65>/Unit Delay'
       */
      rtb_Switch2_krvg = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_nqfg;
    }

    rtb_Switch2_krvg -= 0.01F;
  }

  /* End of Switch: '<S65>/Switch4' */

  /* Switch: '<S48>/Switch5' incorporates:
   *  Constant: '<S48>/Constant5'
   */
  if (VbACCS_Input_Obs_valid)
  {
    /* Switch: '<S65>/Switch' */
    if (rtb_Switch2_krvg > 0.0F)
    {
      VfACCS_Input_Obs_LinearVelocity = rtb_Switch1_ic0c;
    }
    else
    {
      VfACCS_Input_Obs_LinearVelocity = rtb_Add11;
    }

    /* End of Switch: '<S65>/Switch' */
  }
  else
  {
    VfACCS_Input_Obs_LinearVelocity = 0.0F;
  }

  /* End of Switch: '<S48>/Switch5' */

  /* SignalConversion: '<S48>/Signal Conversion2' */
  VfACCS_Input_Obs_ID = ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id;

  /* SignalConversion: '<S48>/Signal Conversion4' */
  VeACCS_CIPVobsType = ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.type;

  /* Sum: '<S39>/Add1' */
  rtb_Add11_hcma =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.velocity_rel.y +
    VfACCS_Input_latvelocity_EGMO;

  /* Abs: '<S68>/Abs3' */
  rtb_Abs3_f3i5 = (real32_T)fabs((real_T)rtb_Add11_hcma);

  /* Switch: '<S68>/Switch6' incorporates:
   *  Constant: '<S68>/Constant15'
   *  Constant: '<S68>/Constant23'
   *  RelationalOperator: '<S68>/Relational Operator5'
   *  RelationalOperator: '<S68>/Relational Operator6'
   *  Switch: '<S68>/Switch8'
   */
  if (rtb_Abs3_f3i5 >= KfACCS_v_LatSpdDeadband_Max)
  {
  }
  else if (rtb_Abs3_f3i5 >= KfACCS_v_LatSpdDeadband_Min)
  {
    /* MinMax: '<S68>/Max3' incorporates:
     *  Constant: '<S68>/Constant17'
     *  Constant: '<S68>/Constant18'
     *  Sum: '<S68>/Add8'
     *  Switch: '<S68>/Switch8'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(KfACCS_v_LatSpdDeadband_Max -
      KfACCS_v_LatSpdDeadband_Min));

    /* Switch: '<S68>/Switch7' incorporates:
     *  Constant: '<S68>/Constant20'
     *  Constant: '<S68>/Constant21'
     *  Switch: '<S68>/Switch8'
     */
    if (rtb_Add11_hcma > 0.0F)
    {
      rtb_Add11_hcma = (real32_T)1.0;
    }
    else
    {
      rtb_Add11_hcma = (real32_T)(-1.0);
    }

    /* End of Switch: '<S68>/Switch7' */

    /* MinMax: '<S68>/Max3' incorporates:
     *  Constant: '<S68>/Constant19'
     *  Switch: '<S68>/Switch8'
     */
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S68>/Switch8' incorporates:
     *  Constant: '<S68>/Constant16'
     *  Constant: '<S68>/Constant22'
     *  Product: '<S68>/Divide3'
     *  Product: '<S68>/Product9'
     *  Sum: '<S68>/Add7'
     */
    rtb_Add11_hcma = (rtb_Add11_hcma * KfACCS_v_LatSpdDeadband_Max) * ((real32_T)
      ((real_T)(((real_T)((real32_T)(rtb_Abs3_f3i5 - KfACCS_v_LatSpdDeadband_Min)))
                / rtb_Switch5_blbp)));
  }
  else
  {
    /* Switch: '<S68>/Switch8' incorporates:
     *  Constant: '<S68>/Constant24'
     */
    rtb_Add11_hcma = (real32_T)0.0;
  }

  /* End of Switch: '<S68>/Switch6' */

  /* Switch: '<S68>/Switch9' incorporates:
   *  Abs: '<S68>/Abs4'
   *  Constant: '<S68>/Constant26'
   *  RelationalOperator: '<S68>/Relational Operator7'
   *  Sum: '<S68>/Add9'
   *  UnitDelay: '<S68>/Unit Delay'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_nten)))) >=
      KfACCS_v_LatSpdUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_nten;
  }

  /* End of Switch: '<S68>/Switch9' */

  /* Sum: '<S72>/Sum' incorporates:
   *  Constant: '<S68>/Constant50'
   *  Product: '<S72>/Product'
   *  Product: '<S72>/Product1'
   *  UnitDelay: '<S72>/Unit Delay'
   */
  rtb_Abs3_f3i5 = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_kec2 *
                   rtb_Sum_khuf) + (rtb_Add11_hcma * KfACCS_k_ObjectSpdFilter);

  /* Sum: '<S39>/Add22' */
  rtb_Add11_hcma =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.velocity_rel.x +
    VfACCS_Input_longvelocity_EGMO;

  /* Switch: '<S68>/Switch10' incorporates:
   *  Abs: '<S68>/Abs5'
   *  Constant: '<S68>/Constant25'
   *  RelationalOperator: '<S68>/Relational Operator8'
   *  Sum: '<S68>/Add10'
   *  UnitDelay: '<S68>/Unit Delay1'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_gsho)))) >=
      KfACCS_v_ObjectSpdUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_gsho;
  }

  /* End of Switch: '<S68>/Switch10' */

  /* Sum: '<S71>/Sum' incorporates:
   *  Constant: '<S68>/Constant48'
   *  Product: '<S71>/Product'
   *  Product: '<S71>/Product1'
   *  UnitDelay: '<S71>/Unit Delay'
   */
  rtb_Sum_e3dl = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_g3bx *
                  rtb_Sum_khuf) + (rtb_Add11_hcma * KfACCS_k_ObjectSpdFilter);

  /* Switch: '<S68>/Switch11' incorporates:
   *  Abs: '<S68>/Abs6'
   *  Constant: '<S68>/Constant28'
   *  MinMax: '<S68>/Max4'
   *  Product: '<S68>/Divide4'
   *  RelationalOperator: '<S68>/Relational Operator9'
   *  Trigonometry: '<S68>/Atan2'
   */
  if (((real_T)((real32_T)fabs((real_T)rtb_Sum_e3dl))) > 0.0)
  {
    /* MinMax: '<S68>/Max4' incorporates:
     *  Constant: '<S68>/Constant27'
     */
    if (((real_T)rtb_Sum_e3dl) > 1.0E-6)
    {
      rtb_Switch5_blbp = (real_T)rtb_Sum_e3dl;
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    rtb_Switch11_lqzi = (real32_T)atan((real_T)((real32_T)(rtb_Abs3_f3i5 /
      ((real32_T)rtb_Switch5_blbp))));
  }
  else
  {
    rtb_Switch11_lqzi = (real32_T)ACCS_subsystem_integrate_ConstB.Gain1_jjpg;
  }

  /* End of Switch: '<S68>/Switch11' */

  /* Trigonometry: '<S68>/Cos4' incorporates:
   *  Switch: '<S37>/Switch'
   *  Switch: '<S37>/Switch1'
   *  Switch: '<S37>/Switch2'
   *  Switch: '<S39>/Switch15'
   *  Switch: '<S39>/Switch18'
   *  Switch: '<S68>/Switch12'
   *  Trigonometry: '<S68>/Cos2'
   *  Trigonometry: '<S68>/Cos3'
   */
  rtb_MathReciprocal_ashu = (real32_T)cos((real_T)rtb_Switch11_lqzi);

  /* Trigonometry: '<S68>/Sin5' incorporates:
   *  Switch: '<S37>/Switch'
   *  Switch: '<S37>/Switch1'
   *  Switch: '<S37>/Switch2'
   *  Switch: '<S39>/Switch15'
   *  Switch: '<S39>/Switch18'
   *  Switch: '<S68>/Switch12'
   *  Trigonometry: '<S68>/Sin3'
   *  Trigonometry: '<S68>/Sin4'
   */
  rtb_Switch11_lqzi = (real32_T)sin((real_T)rtb_Switch11_lqzi);

  /* Sum: '<S68>/Add16' incorporates:
   *  Product: '<S68>/Product14'
   *  Product: '<S68>/Product15'
   *  Sum: '<S39>/Add23'
   *  Sum: '<S39>/Add24'
   *  Trigonometry: '<S68>/Cos4'
   *  Trigonometry: '<S68>/Sin5'
   */
  rtb_Add11_hcma =
    ((ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.acceleration_rel.x +
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_Accele_dcwi) *
     rtb_MathReciprocal_ashu) +
    ((ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.acceleration_rel.y +
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_Acceleratio) *
     rtb_Switch11_lqzi);

  /* Switch: '<S68>/Switch24' incorporates:
   *  Abs: '<S68>/Abs7'
   *  Constant: '<S68>/Constant47'
   *  RelationalOperator: '<S68>/Relational Operator10'
   *  Sum: '<S68>/Add21'
   *  UnitDelay: '<S68>/Unit Delay2'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_pzjs)))) >=
      KfACCS_a_ObjectAccelUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_pzjs;
  }

  /* End of Switch: '<S68>/Switch24' */

  /* Sum: '<S70>/Sum' incorporates:
   *  Constant: '<S68>/Constant46'
   *  Product: '<S70>/Product'
   *  Product: '<S70>/Product1'
   *  UnitDelay: '<S70>/Unit Delay'
   */
  rtb_Sum_psl2 = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_hcyq *
                  rtb_Sum_hycr) + (rtb_Add11_hcma * KfACCS_k_ObjectAccelFilter);

  /* Sum: '<S40>/Add1' */
  rtb_Add11_hcma =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.velocity_rel.y +
    VfACCS_Input_latvelocity_EGMO;

  /* Abs: '<S75>/Abs3' */
  rtb_Abs3_daky = (real32_T)fabs((real_T)rtb_Add11_hcma);

  /* Switch: '<S75>/Switch6' incorporates:
   *  Constant: '<S75>/Constant15'
   *  Constant: '<S75>/Constant23'
   *  RelationalOperator: '<S75>/Relational Operator5'
   *  RelationalOperator: '<S75>/Relational Operator6'
   *  Switch: '<S75>/Switch8'
   */
  if (rtb_Abs3_daky >= KfACCS_v_LatSpdDeadband_Max)
  {
  }
  else if (rtb_Abs3_daky >= KfACCS_v_LatSpdDeadband_Min)
  {
    /* MinMax: '<S75>/Max3' incorporates:
     *  Constant: '<S75>/Constant17'
     *  Constant: '<S75>/Constant18'
     *  Sum: '<S75>/Add8'
     *  Switch: '<S75>/Switch8'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(KfACCS_v_LatSpdDeadband_Max -
      KfACCS_v_LatSpdDeadband_Min));

    /* Switch: '<S75>/Switch7' incorporates:
     *  Constant: '<S75>/Constant20'
     *  Constant: '<S75>/Constant21'
     *  Switch: '<S75>/Switch8'
     */
    if (rtb_Add11_hcma > 0.0F)
    {
      rtb_Add11_hcma = (real32_T)1.0;
    }
    else
    {
      rtb_Add11_hcma = (real32_T)(-1.0);
    }

    /* End of Switch: '<S75>/Switch7' */

    /* MinMax: '<S75>/Max3' incorporates:
     *  Constant: '<S75>/Constant19'
     *  Switch: '<S75>/Switch8'
     */
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S75>/Switch8' incorporates:
     *  Constant: '<S75>/Constant16'
     *  Constant: '<S75>/Constant22'
     *  Product: '<S75>/Divide3'
     *  Product: '<S75>/Product9'
     *  Sum: '<S75>/Add7'
     */
    rtb_Add11_hcma = (rtb_Add11_hcma * KfACCS_v_LatSpdDeadband_Max) * ((real32_T)
      ((real_T)(((real_T)((real32_T)(rtb_Abs3_daky - KfACCS_v_LatSpdDeadband_Min)))
                / rtb_Switch5_blbp)));
  }
  else
  {
    /* Switch: '<S75>/Switch8' incorporates:
     *  Constant: '<S75>/Constant24'
     */
    rtb_Add11_hcma = (real32_T)0.0;
  }

  /* End of Switch: '<S75>/Switch6' */

  /* Switch: '<S75>/Switch9' incorporates:
   *  Abs: '<S75>/Abs4'
   *  Constant: '<S75>/Constant26'
   *  RelationalOperator: '<S75>/Relational Operator7'
   *  Sum: '<S75>/Add9'
   *  UnitDelay: '<S75>/Unit Delay'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_dwri)))) >=
      KfACCS_v_LatSpdUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_dwri;
  }

  /* End of Switch: '<S75>/Switch9' */

  /* Sum: '<S79>/Sum' incorporates:
   *  Constant: '<S75>/Constant50'
   *  Product: '<S79>/Product'
   *  Product: '<S79>/Product1'
   *  UnitDelay: '<S79>/Unit Delay'
   */
  rtb_Abs3_daky = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_lhxk *
                   rtb_Sum_khuf) + (rtb_Add11_hcma * KfACCS_k_ObjectSpdFilter);

  /* Sum: '<S40>/Add22' */
  rtb_Add11_hcma =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.velocity_rel.x +
    VfACCS_Input_longvelocity_EGMO;

  /* Switch: '<S75>/Switch10' incorporates:
   *  Abs: '<S75>/Abs5'
   *  Constant: '<S75>/Constant25'
   *  RelationalOperator: '<S75>/Relational Operator8'
   *  Sum: '<S75>/Add10'
   *  UnitDelay: '<S75>/Unit Delay1'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_ehwx)))) >=
      KfACCS_v_ObjectSpdUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_ehwx;
  }

  /* End of Switch: '<S75>/Switch10' */

  /* Sum: '<S78>/Sum' incorporates:
   *  Constant: '<S75>/Constant48'
   *  Product: '<S78>/Product'
   *  Product: '<S78>/Product1'
   *  UnitDelay: '<S78>/Unit Delay'
   */
  rtb_Sum_kt3p = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_p00p *
                  rtb_Sum_khuf) + (rtb_Add11_hcma * KfACCS_k_ObjectSpdFilter);

  /* Switch: '<S75>/Switch11' incorporates:
   *  Abs: '<S75>/Abs6'
   *  Constant: '<S75>/Constant28'
   *  MinMax: '<S75>/Max4'
   *  Product: '<S75>/Divide4'
   *  RelationalOperator: '<S75>/Relational Operator9'
   *  Trigonometry: '<S75>/Atan2'
   */
  if (((real_T)((real32_T)fabs((real_T)rtb_Sum_kt3p))) > 0.0)
  {
    /* MinMax: '<S75>/Max4' incorporates:
     *  Constant: '<S75>/Constant27'
     */
    if (((real_T)rtb_Sum_kt3p) > 1.0E-6)
    {
      rtb_Switch5_blbp = (real_T)rtb_Sum_kt3p;
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    rtb_Switch11_pxmy = (real32_T)atan((real_T)((real32_T)(rtb_Abs3_daky /
      ((real32_T)rtb_Switch5_blbp))));
  }
  else
  {
    rtb_Switch11_pxmy = (real32_T)ACCS_subsystem_integrate_ConstB.Gain1_k0gs;
  }

  /* End of Switch: '<S75>/Switch11' */

  /* Trigonometry: '<S75>/Cos4' incorporates:
   *  Switch: '<S37>/Switch'
   *  Switch: '<S37>/Switch1'
   *  Switch: '<S37>/Switch2'
   *  Switch: '<S40>/Switch15'
   *  Switch: '<S40>/Switch18'
   *  Switch: '<S75>/Switch12'
   *  Trigonometry: '<S75>/Cos2'
   *  Trigonometry: '<S75>/Cos3'
   */
  rtb_Switch2_b0i5 = (real32_T)cos((real_T)rtb_Switch11_pxmy);

  /* Trigonometry: '<S75>/Sin5' incorporates:
   *  Switch: '<S37>/Switch'
   *  Switch: '<S37>/Switch1'
   *  Switch: '<S37>/Switch2'
   *  Switch: '<S40>/Switch15'
   *  Switch: '<S40>/Switch18'
   *  Switch: '<S75>/Switch12'
   *  Trigonometry: '<S75>/Sin3'
   *  Trigonometry: '<S75>/Sin4'
   */
  rtb_Switch11_pxmy = (real32_T)sin((real_T)rtb_Switch11_pxmy);

  /* Sum: '<S75>/Add16' incorporates:
   *  Product: '<S75>/Product14'
   *  Product: '<S75>/Product15'
   *  Sum: '<S40>/Add23'
   *  Sum: '<S40>/Add24'
   *  Trigonometry: '<S75>/Cos4'
   *  Trigonometry: '<S75>/Sin5'
   */
  rtb_Add11_hcma =
    ((ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.acceleration_rel.x +
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_Accele_dcwi) *
     rtb_Switch2_b0i5) +
    ((ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.acceleration_rel.y +
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_Acceleratio) *
     rtb_Switch11_pxmy);

  /* Switch: '<S75>/Switch24' incorporates:
   *  Abs: '<S75>/Abs7'
   *  Constant: '<S75>/Constant47'
   *  RelationalOperator: '<S75>/Relational Operator10'
   *  Sum: '<S75>/Add21'
   *  UnitDelay: '<S75>/Unit Delay2'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_byd2)))) >=
      KfACCS_a_ObjectAccelUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_byd2;
  }

  /* End of Switch: '<S75>/Switch24' */

  /* Sum: '<S77>/Sum' incorporates:
   *  Constant: '<S75>/Constant46'
   *  Product: '<S77>/Product'
   *  Product: '<S77>/Product1'
   *  UnitDelay: '<S77>/Unit Delay'
   */
  rtb_Sum_jtad = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_cqqi *
                  rtb_Sum_hycr) + (rtb_Add11_hcma * KfACCS_k_ObjectAccelFilter);

  /* Sum: '<S41>/Add1' */
  rtb_Add11_hcma = ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.velocity_rel.y
    + VfACCS_Input_latvelocity_EGMO;

  /* Abs: '<S82>/Abs3' */
  rtb_Abs3_ptqq = (real32_T)fabs((real_T)rtb_Add11_hcma);

  /* Switch: '<S82>/Switch6' incorporates:
   *  Constant: '<S82>/Constant15'
   *  Constant: '<S82>/Constant23'
   *  RelationalOperator: '<S82>/Relational Operator5'
   *  RelationalOperator: '<S82>/Relational Operator6'
   *  Switch: '<S82>/Switch8'
   */
  if (rtb_Abs3_ptqq >= KfACCS_v_LatSpdDeadband_Max)
  {
  }
  else if (rtb_Abs3_ptqq >= KfACCS_v_LatSpdDeadband_Min)
  {
    /* MinMax: '<S82>/Max3' incorporates:
     *  Constant: '<S82>/Constant17'
     *  Constant: '<S82>/Constant18'
     *  Sum: '<S82>/Add8'
     *  Switch: '<S82>/Switch8'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(KfACCS_v_LatSpdDeadband_Max -
      KfACCS_v_LatSpdDeadband_Min));

    /* Switch: '<S82>/Switch7' incorporates:
     *  Constant: '<S82>/Constant20'
     *  Constant: '<S82>/Constant21'
     *  Switch: '<S82>/Switch8'
     */
    if (rtb_Add11_hcma > 0.0F)
    {
      rtb_Add11_hcma = (real32_T)1.0;
    }
    else
    {
      rtb_Add11_hcma = (real32_T)(-1.0);
    }

    /* End of Switch: '<S82>/Switch7' */

    /* MinMax: '<S82>/Max3' incorporates:
     *  Constant: '<S82>/Constant19'
     *  Switch: '<S82>/Switch8'
     */
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S82>/Switch8' incorporates:
     *  Constant: '<S82>/Constant16'
     *  Constant: '<S82>/Constant22'
     *  Product: '<S82>/Divide3'
     *  Product: '<S82>/Product9'
     *  Sum: '<S82>/Add7'
     */
    rtb_Add11_hcma = (rtb_Add11_hcma * KfACCS_v_LatSpdDeadband_Max) * ((real32_T)
      ((real_T)(((real_T)((real32_T)(rtb_Abs3_ptqq - KfACCS_v_LatSpdDeadband_Min)))
                / rtb_Switch5_blbp)));
  }
  else
  {
    /* Switch: '<S82>/Switch8' incorporates:
     *  Constant: '<S82>/Constant24'
     */
    rtb_Add11_hcma = (real32_T)0.0;
  }

  /* End of Switch: '<S82>/Switch6' */

  /* Switch: '<S82>/Switch9' incorporates:
   *  Abs: '<S82>/Abs4'
   *  Constant: '<S82>/Constant26'
   *  RelationalOperator: '<S82>/Relational Operator7'
   *  Sum: '<S82>/Add9'
   *  UnitDelay: '<S82>/Unit Delay'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_a5fv)))) >=
      KfACCS_v_LatSpdUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_a5fv;
  }

  /* End of Switch: '<S82>/Switch9' */

  /* Sum: '<S86>/Sum' incorporates:
   *  Constant: '<S82>/Constant50'
   *  Product: '<S86>/Product'
   *  Product: '<S86>/Product1'
   *  UnitDelay: '<S86>/Unit Delay'
   */
  rtb_Abs3_ptqq = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_bmp0 *
                   rtb_Sum_khuf) + (rtb_Add11_hcma * KfACCS_k_ObjectSpdFilter);

  /* Sum: '<S41>/Add22' */
  rtb_Add11_hcma = ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.velocity_rel.x
    + VfACCS_Input_longvelocity_EGMO;

  /* Switch: '<S82>/Switch10' incorporates:
   *  Abs: '<S82>/Abs5'
   *  Constant: '<S82>/Constant25'
   *  RelationalOperator: '<S82>/Relational Operator8'
   *  Sum: '<S82>/Add10'
   *  UnitDelay: '<S82>/Unit Delay1'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_fbvr)))) >=
      KfACCS_v_ObjectSpdUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_fbvr;
  }

  /* End of Switch: '<S82>/Switch10' */

  /* Sum: '<S85>/Sum' incorporates:
   *  Constant: '<S82>/Constant48'
   *  Product: '<S85>/Product'
   *  Product: '<S85>/Product1'
   *  UnitDelay: '<S85>/Unit Delay'
   */
  rtb_Sum_g5ql = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ar1y *
                  rtb_Sum_khuf) + (rtb_Add11_hcma * KfACCS_k_ObjectSpdFilter);

  /* Switch: '<S82>/Switch11' incorporates:
   *  Abs: '<S82>/Abs6'
   *  Constant: '<S82>/Constant28'
   *  MinMax: '<S82>/Max4'
   *  Product: '<S82>/Divide4'
   *  RelationalOperator: '<S82>/Relational Operator9'
   *  Trigonometry: '<S82>/Atan2'
   */
  if (((real_T)((real32_T)fabs((real_T)rtb_Sum_g5ql))) > 0.0)
  {
    /* MinMax: '<S82>/Max4' incorporates:
     *  Constant: '<S82>/Constant27'
     */
    if (((real_T)rtb_Sum_g5ql) > 1.0E-6)
    {
      rtb_Switch5_blbp = (real_T)rtb_Sum_g5ql;
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    rtb_Switch11_fwu3 = (real32_T)atan((real_T)((real32_T)(rtb_Abs3_ptqq /
      ((real32_T)rtb_Switch5_blbp))));
  }
  else
  {
    rtb_Switch11_fwu3 = (real32_T)ACCS_subsystem_integrate_ConstB.Gain1_clwv;
  }

  /* End of Switch: '<S82>/Switch11' */

  /* Trigonometry: '<S82>/Cos4' incorporates:
   *  Switch: '<S41>/Switch15'
   *  Switch: '<S41>/Switch18'
   *  Switch: '<S82>/Switch12'
   *  Trigonometry: '<S82>/Cos2'
   *  Trigonometry: '<S82>/Cos3'
   */
  rtb_Switch12_cgog = (real32_T)cos((real_T)rtb_Switch11_fwu3);

  /* Trigonometry: '<S82>/Sin5' incorporates:
   *  Switch: '<S41>/Switch15'
   *  Switch: '<S41>/Switch18'
   *  Switch: '<S82>/Switch12'
   *  Trigonometry: '<S82>/Sin3'
   *  Trigonometry: '<S82>/Sin4'
   */
  rtb_Switch11_fwu3 = (real32_T)sin((real_T)rtb_Switch11_fwu3);

  /* Sum: '<S82>/Add16' incorporates:
   *  Product: '<S82>/Product14'
   *  Product: '<S82>/Product15'
   *  Sum: '<S41>/Add23'
   *  Sum: '<S41>/Add24'
   *  Trigonometry: '<S82>/Cos4'
   *  Trigonometry: '<S82>/Sin5'
   */
  rtb_Add11_hcma =
    ((ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.acceleration_rel.x +
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_Accele_dcwi) *
     rtb_Switch12_cgog) +
    ((ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.acceleration_rel.y +
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_Acceleratio) *
     rtb_Switch11_fwu3);

  /* Switch: '<S82>/Switch24' incorporates:
   *  Abs: '<S82>/Abs7'
   *  Constant: '<S82>/Constant47'
   *  RelationalOperator: '<S82>/Relational Operator10'
   *  Sum: '<S82>/Add21'
   *  UnitDelay: '<S82>/Unit Delay2'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_inkz)))) >=
      KfACCS_a_ObjectAccelUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_inkz;
  }

  /* End of Switch: '<S82>/Switch24' */

  /* Sum: '<S84>/Sum' incorporates:
   *  Constant: '<S82>/Constant46'
   *  Product: '<S84>/Product'
   *  Product: '<S84>/Product1'
   *  UnitDelay: '<S84>/Unit Delay'
   */
  rtb_Sum_oc5m = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_an2b *
                  rtb_Sum_hycr) + (rtb_Add11_hcma * KfACCS_k_ObjectAccelFilter);

  /* Switch: '<S41>/Switch18' incorporates:
   *  Constant: '<S41>/Constant36'
   *  Constant: '<S41>/Constant37'
   *  Logic: '<S41>/Logical Operator1'
   */
  if (!KbACCS_UseVirtualObject)
  {
    /* Switch: '<S41>/Switch15' incorporates:
     *  Constant: '<S41>/Constant33'
     */
    if (ACCS_subsystem_integrated_B.VbACCS_Input_Obs_F_valid)
    {
      /* Switch: '<S82>/Switch12' incorporates:
       *  Constant: '<S82>/Constant30'
       *  Product: '<S82>/Product10'
       *  Product: '<S82>/Product11'
       *  Product: '<S82>/Product12'
       *  Product: '<S82>/Product13'
       *  Sum: '<S82>/Add11'
       *  Sum: '<S82>/Add12'
       *  Sum: '<S82>/Add13'
       *  Sum: '<S82>/Add14'
       *  Sum: '<S82>/Add15'
       */
      if (KeACCS_RRCalMetdType > ((uint8_T)0U))
      {
        rtb_Switch12_cgog = ((rtb_Sum_g5ql * rtb_Switch12_cgog) + (rtb_Abs3_ptqq
          * rtb_Switch11_fwu3)) - VfACCS_Input_linear_velocity_EGMO;
      }
      else
      {
        rtb_Switch12_cgog = ((rtb_Sum_g5ql - VfACCS_Input_longvelocity_EGMO) *
                             rtb_Switch12_cgog) + ((rtb_Abs3_ptqq -
          VfACCS_Input_latvelocity_EGMO) * rtb_Switch11_fwu3);
      }
    }
    else
    {
      rtb_Switch12_cgog = 0.0F;
    }
  }
  else
  {
    rtb_Switch12_cgog = KfACCS_v_RangeRate_PreSet;
  }

  /* Switch: '<S37>/Switch' */
  if (ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v)
  {
    /* Switch: '<S37>/Switch1' */
    if (ACCS_subsystem_integrate_ConstB.LogicalOperator)
    {
      /* Switch: '<S37>/Switch2' incorporates:
       *  Constant: '<S39>/Constant36'
       *  Logic: '<S39>/Logical Operator1'
       *  Switch: '<S39>/Switch18'
       */
      if (ACCS_subsystem_integrate_ConstB.VeACCS_Input_TurnLightState)
      {
        /* Switch: '<S40>/Switch18' incorporates:
         *  Constant: '<S40>/Constant36'
         *  Constant: '<S40>/Constant37'
         *  Logic: '<S40>/Logical Operator1'
         */
        if (!KbACCS_UseVirtualObject)
        {
          /* Switch: '<S40>/Switch15' incorporates:
           *  Constant: '<S40>/Constant33'
           */
          if (ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVR_valid)
          {
            /* Switch: '<S75>/Switch12' incorporates:
             *  Constant: '<S75>/Constant30'
             *  Product: '<S75>/Product10'
             *  Product: '<S75>/Product11'
             *  Product: '<S75>/Product12'
             *  Product: '<S75>/Product13'
             *  Sum: '<S75>/Add11'
             *  Sum: '<S75>/Add12'
             *  Sum: '<S75>/Add13'
             *  Sum: '<S75>/Add14'
             *  Sum: '<S75>/Add15'
             */
            if (KeACCS_RRCalMetdType > ((uint8_T)0U))
            {
              ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Rangerate_h0h0 =
                ((rtb_Sum_kt3p * rtb_Switch2_b0i5) + (rtb_Abs3_daky *
                  rtb_Switch11_pxmy)) - VfACCS_Input_linear_velocity_EGMO;
            }
            else
            {
              ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Rangerate_h0h0 =
                ((rtb_Sum_kt3p - VfACCS_Input_longvelocity_EGMO) *
                 rtb_Switch2_b0i5) + ((rtb_Abs3_daky -
                VfACCS_Input_latvelocity_EGMO) * rtb_Switch11_pxmy);
            }
          }
          else
          {
            ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Rangerate_h0h0 = 0.0F;
          }
        }
        else
        {
          ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Rangerate_h0h0 =
            KfACCS_v_RangeRate_PreSet;
        }
      }
      else if (!KbACCS_UseVirtualObject)
      {
        /* Switch: '<S39>/Switch15' incorporates:
         *  Constant: '<S39>/Constant33'
         *  Switch: '<S39>/Switch18'
         */
        if (ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVL_valid)
        {
          /* Switch: '<S68>/Switch12' incorporates:
           *  Constant: '<S68>/Constant30'
           *  Product: '<S68>/Product10'
           *  Product: '<S68>/Product11'
           *  Product: '<S68>/Product12'
           *  Product: '<S68>/Product13'
           *  Sum: '<S68>/Add11'
           *  Sum: '<S68>/Add12'
           *  Sum: '<S68>/Add13'
           *  Sum: '<S68>/Add14'
           *  Sum: '<S68>/Add15'
           */
          if (KeACCS_RRCalMetdType > ((uint8_T)0U))
          {
            ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Rangerate_h0h0 =
              ((rtb_Sum_e3dl * rtb_MathReciprocal_ashu) + (rtb_Abs3_f3i5 *
                rtb_Switch11_lqzi)) - VfACCS_Input_linear_velocity_EGMO;
          }
          else
          {
            ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Rangerate_h0h0 =
              ((rtb_Sum_e3dl - VfACCS_Input_longvelocity_EGMO) *
               rtb_MathReciprocal_ashu) + ((rtb_Abs3_f3i5 -
              VfACCS_Input_latvelocity_EGMO) * rtb_Switch11_lqzi);
          }
        }
        else
        {
          ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Rangerate_h0h0 = 0.0F;
        }
      }
      else
      {
        /* Switch: '<S39>/Switch18' incorporates:
         *  Constant: '<S39>/Constant37'
         */
        ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Rangerate_h0h0 =
          KfACCS_v_RangeRate_PreSet;
      }
    }
    else
    {
      ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Rangerate_h0h0 =
        rtb_Switch12_cgog;
    }
  }
  else
  {
    ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Rangerate_h0h0 =
      rtb_Switch12_cgog;
  }

  /* MinMax: '<S83>/Max1' incorporates:
   *  Constant: '<S83>/Constant1'
   */
  if (((real_T)ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q) >
      1.0E-6)
  {
    rtb_Switch5_blbp = (real_T)
      ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q;
  }
  else
  {
    rtb_Switch5_blbp = 1.0E-6;
  }

  /* End of MinMax: '<S83>/Max1' */

  /* Math: '<S83>/Math Reciprocal'
   *
   * About '<S83>/Math Reciprocal':
   *  Operator: reciprocal
   */
  rtb_MathReciprocal_ashu = (real32_T)((real_T)(1.0 / rtb_Switch5_blbp));

  /* Switch: '<S83>/Switch' incorporates:
   *  Constant: '<S83>/Constant2'
   *  Constant: '<S83>/Constant3'
   */
  if (rtb_MathReciprocal_ashu > 0.0F)
  {
    rtb_Switch11_lqzi = (real32_T)1.0;
  }
  else
  {
    rtb_Switch11_lqzi = (real32_T)(-1.0);
  }

  /* End of Switch: '<S83>/Switch' */

  /* Switch: '<S83>/Switch1' incorporates:
   *  Abs: '<S83>/Abs'
   *  Abs: '<S83>/Abs1'
   *  Product: '<S83>/Product4'
   *  RelationalOperator: '<S83>/Relational Operator'
   *  RelationalOperator: '<S83>/Relational Operator1'
   *  Switch: '<S83>/Switch2'
   */
  if (rtb_MathReciprocal_ashu ==
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.nearest_point_rel.y)
  {
    rtb_Switch2_b0i5 = (real32_T)((real_T)
      (ACCS_subsystem_integrate_ConstB.Gain_mimv * ((real_T)rtb_Switch11_lqzi)));
  }
  else if (((real32_T)fabs((real_T)rtb_MathReciprocal_ashu)) > ((real32_T)fabs
            ((real_T)
             ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.nearest_point_rel.y)))
  {
    /* MinMax: '<S83>/Max2' incorporates:
     *  Constant: '<S83>/Constant31'
     *  Sum: '<S83>/Add2'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(rtb_MathReciprocal_ashu -
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.nearest_point_rel.y));
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S83>/Switch2' incorporates:
     *  Product: '<S83>/Divide1'
     *  Trigonometry: '<S83>/Atan1'
     */
    rtb_Switch2_b0i5 = (real32_T)atan((real_T)((real32_T)((real_T)(((real_T)
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.nearest_point_rel.x) /
      rtb_Switch5_blbp))));
  }
  else
  {
    /* MinMax: '<S83>/Max2' incorporates:
     *  Constant: '<S83>/Constant31'
     *  Sum: '<S83>/Add2'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(rtb_MathReciprocal_ashu -
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.nearest_point_rel.y));
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S83>/Switch2' incorporates:
     *  Product: '<S83>/Divide1'
     *  Product: '<S83>/Product5'
     *  Sum: '<S83>/Add3'
     *  Trigonometry: '<S83>/Atan1'
     */
    rtb_Switch2_b0i5 = ((real32_T)((real_T)(((real_T)rtb_Switch11_lqzi) *
      ACCS_subsystem_integrate_ConstB.Gain2_dadm))) + ((real32_T)atan((real_T)
      ((real32_T)((real_T)(((real_T)
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.nearest_point_rel.x) /
      rtb_Switch5_blbp)))));
  }

  /* End of Switch: '<S83>/Switch1' */

  /* Switch: '<S83>/Switch3' incorporates:
   *  Constant: '<S83>/Constant7'
   *  Product: '<S83>/Product6'
   *  RelationalOperator: '<S83>/Relational Operator2'
   */
  if (rtb_MathReciprocal_ashu > KfACCS_d_CurvatureRadius_Max)
  {
    rtb_Add11_hcma =
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.nearest_point_rel.x;
  }
  else
  {
    rtb_Add11_hcma = rtb_Switch2_b0i5 * rtb_MathReciprocal_ashu;
  }

  /* End of Switch: '<S83>/Switch3' */

  /* Sum: '<S87>/Sum' incorporates:
   *  Constant: '<S83>/Constant13'
   *  Constant: '<S83>/Constant46'
   *  Constant: '<S83>/Constant8'
   *  Product: '<S83>/Product7'
   *  Product: '<S87>/Product'
   *  Product: '<S87>/Product1'
   *  Sum: '<S83>/Add4'
   *  UnitDelay: '<S87>/Unit Delay'
   */
  rtb_Switch11_lqzi = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_aqya *
                       rtb_Switch_iliv_tmp) + (((rtb_Add11_hcma -
    KfACCS_d_DisToLeadSur) + (KfACCS_t_TimeOffset * rtb_Sum_g5ql)) *
    KfACCS_k_ObjectRangeFilter);

  /* Switch: '<S41>/Switch19' incorporates:
   *  Constant: '<S41>/Constant38'
   *  Constant: '<S41>/Constant39'
   *  Logic: '<S41>/Logical Operator'
   */
  if (!KbACCS_UseVirtualObject)
  {
    /* Switch: '<S41>/Switch13' incorporates:
     *  Constant: '<S41>/Constant32'
     */
    if (ACCS_subsystem_integrated_B.VbACCS_Input_Obs_F_valid)
    {
      rtb_VfACCS_Input_Obs_Range = rtb_Switch11_lqzi;
    }
    else
    {
      rtb_VfACCS_Input_Obs_Range = 0.0F;
    }

    /* End of Switch: '<S41>/Switch13' */
  }
  else
  {
    rtb_VfACCS_Input_Obs_Range = KfACCS_d_Range_PreSet;
  }

  /* End of Switch: '<S41>/Switch19' */

  /* MinMax: '<S69>/Max1' incorporates:
   *  Constant: '<S69>/Constant1'
   */
  if (((real_T)ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q) >
      1.0E-6)
  {
    rtb_Switch5_blbp = (real_T)
      ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q;
  }
  else
  {
    rtb_Switch5_blbp = 1.0E-6;
  }

  /* End of MinMax: '<S69>/Max1' */

  /* Math: '<S69>/Math Reciprocal'
   *
   * About '<S69>/Math Reciprocal':
   *  Operator: reciprocal
   */
  rtb_Switch12_cgog = (real32_T)((real_T)(1.0 / rtb_Switch5_blbp));

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S69>/Constant2'
   *  Constant: '<S69>/Constant3'
   */
  if (rtb_Switch12_cgog > 0.0F)
  {
    rtb_Switch11_pxmy = (real32_T)1.0;
  }
  else
  {
    rtb_Switch11_pxmy = (real32_T)(-1.0);
  }

  /* End of Switch: '<S69>/Switch' */

  /* Switch: '<S69>/Switch1' incorporates:
   *  Abs: '<S69>/Abs'
   *  Abs: '<S69>/Abs1'
   *  Product: '<S69>/Product4'
   *  RelationalOperator: '<S69>/Relational Operator'
   *  RelationalOperator: '<S69>/Relational Operator1'
   *  Switch: '<S69>/Switch2'
   */
  if (rtb_Switch12_cgog ==
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.nearest_point_rel.y)
  {
    rtb_Switch2_cdx1 = (real32_T)((real_T)
      (ACCS_subsystem_integrate_ConstB.Gain_pbdr * ((real_T)rtb_Switch11_pxmy)));
  }
  else if (((real32_T)fabs((real_T)rtb_Switch12_cgog)) > ((real32_T)fabs((real_T)
             ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.nearest_point_rel.y)))
  {
    /* MinMax: '<S69>/Max2' incorporates:
     *  Constant: '<S69>/Constant31'
     *  Sum: '<S69>/Add2'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(rtb_Switch12_cgog -
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.nearest_point_rel.y));
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S69>/Switch2' incorporates:
     *  Product: '<S69>/Divide1'
     *  Trigonometry: '<S69>/Atan1'
     */
    rtb_Switch2_cdx1 = (real32_T)atan((real_T)((real32_T)((real_T)(((real_T)
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.nearest_point_rel.x) /
      rtb_Switch5_blbp))));
  }
  else
  {
    /* MinMax: '<S69>/Max2' incorporates:
     *  Constant: '<S69>/Constant31'
     *  Sum: '<S69>/Add2'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(rtb_Switch12_cgog -
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.nearest_point_rel.y));
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S69>/Switch2' incorporates:
     *  Product: '<S69>/Divide1'
     *  Product: '<S69>/Product5'
     *  Sum: '<S69>/Add3'
     *  Trigonometry: '<S69>/Atan1'
     */
    rtb_Switch2_cdx1 = ((real32_T)((real_T)(((real_T)rtb_Switch11_pxmy) *
      ACCS_subsystem_integrate_ConstB.Gain2_eem0))) + ((real32_T)atan((real_T)
      ((real32_T)((real_T)(((real_T)
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.nearest_point_rel.x) /
      rtb_Switch5_blbp)))));
  }

  /* End of Switch: '<S69>/Switch1' */

  /* Switch: '<S69>/Switch3' incorporates:
   *  Constant: '<S69>/Constant7'
   *  Product: '<S69>/Product6'
   *  RelationalOperator: '<S69>/Relational Operator2'
   */
  if (rtb_Switch12_cgog > KfACCS_d_CurvatureRadius_Max)
  {
    rtb_Add11_hcma =
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.nearest_point_rel.x;
  }
  else
  {
    rtb_Add11_hcma = rtb_Switch2_cdx1 * rtb_Switch12_cgog;
  }

  /* End of Switch: '<S69>/Switch3' */

  /* Sum: '<S73>/Sum' incorporates:
   *  Constant: '<S69>/Constant13'
   *  Constant: '<S69>/Constant46'
   *  Constant: '<S69>/Constant8'
   *  Product: '<S69>/Product7'
   *  Product: '<S73>/Product'
   *  Product: '<S73>/Product1'
   *  Sum: '<S69>/Add4'
   *  UnitDelay: '<S73>/Unit Delay'
   */
  rtb_Switch11_pxmy = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_juxr *
                       rtb_Switch_iliv_tmp) + (((rtb_Add11_hcma -
    KfACCS_d_DisToLeadSur) + (KfACCS_t_TimeOffset * rtb_Sum_e3dl)) *
    KfACCS_k_ObjectRangeFilter);

  /* MinMax: '<S76>/Max1' incorporates:
   *  Constant: '<S76>/Constant1'
   */
  if (((real_T)ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q) >
      1.0E-6)
  {
    rtb_Switch5_blbp = (real_T)
      ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q;
  }
  else
  {
    rtb_Switch5_blbp = 1.0E-6;
  }

  /* End of MinMax: '<S76>/Max1' */

  /* Math: '<S76>/Math Reciprocal'
   *
   * About '<S76>/Math Reciprocal':
   *  Operator: reciprocal
   */
  rtb_Switch11_fwu3 = (real32_T)((real_T)(1.0 / rtb_Switch5_blbp));

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S76>/Constant2'
   *  Constant: '<S76>/Constant3'
   */
  if (rtb_Switch11_fwu3 > 0.0F)
  {
    rtb_VfACCS_Input_Obs_Linea_flzo = (real32_T)1.0;
  }
  else
  {
    rtb_VfACCS_Input_Obs_Linea_flzo = (real32_T)(-1.0);
  }

  /* End of Switch: '<S76>/Switch' */

  /* Switch: '<S76>/Switch1' incorporates:
   *  Abs: '<S76>/Abs'
   *  Abs: '<S76>/Abs1'
   *  Product: '<S76>/Product4'
   *  RelationalOperator: '<S76>/Relational Operator'
   *  RelationalOperator: '<S76>/Relational Operator1'
   *  Switch: '<S76>/Switch2'
   */
  if (rtb_Switch11_fwu3 ==
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.nearest_point_rel.y)
  {
    rtb_Add11_hcma = (real32_T)((real_T)
      (ACCS_subsystem_integrate_ConstB.Gain_nrzt * ((real_T)
      rtb_VfACCS_Input_Obs_Linea_flzo)));
  }
  else if (((real32_T)fabs((real_T)rtb_Switch11_fwu3)) > ((real32_T)fabs((real_T)
             ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.nearest_point_rel.y)))
  {
    /* MinMax: '<S76>/Max2' incorporates:
     *  Constant: '<S76>/Constant31'
     *  Sum: '<S76>/Add2'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(rtb_Switch11_fwu3 -
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.nearest_point_rel.y));
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S76>/Switch2' incorporates:
     *  Product: '<S76>/Divide1'
     *  Trigonometry: '<S76>/Atan1'
     */
    rtb_Add11_hcma = (real32_T)atan((real_T)((real32_T)((real_T)(((real_T)
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.nearest_point_rel.x) /
      rtb_Switch5_blbp))));
  }
  else
  {
    /* MinMax: '<S76>/Max2' incorporates:
     *  Constant: '<S76>/Constant31'
     *  Sum: '<S76>/Add2'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(rtb_Switch11_fwu3 -
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.nearest_point_rel.y));
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S76>/Switch2' incorporates:
     *  Product: '<S76>/Divide1'
     *  Product: '<S76>/Product5'
     *  Sum: '<S76>/Add3'
     *  Trigonometry: '<S76>/Atan1'
     */
    rtb_Add11_hcma = ((real32_T)((real_T)(((real_T)
      rtb_VfACCS_Input_Obs_Linea_flzo) *
      ACCS_subsystem_integrate_ConstB.Gain2_l1lb))) + ((real32_T)atan((real_T)
      ((real32_T)((real_T)(((real_T)
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.nearest_point_rel.x) /
      rtb_Switch5_blbp)))));
  }

  /* End of Switch: '<S76>/Switch1' */

  /* Switch: '<S76>/Switch3' incorporates:
   *  Constant: '<S76>/Constant7'
   *  Product: '<S76>/Product6'
   *  RelationalOperator: '<S76>/Relational Operator2'
   */
  if (rtb_Switch11_fwu3 > KfACCS_d_CurvatureRadius_Max)
  {
    rtb_VfACCS_Input_Obs_Linea_flzo =
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.nearest_point_rel.x;
  }
  else
  {
    rtb_VfACCS_Input_Obs_Linea_flzo = rtb_Add11_hcma * rtb_Switch11_fwu3;
  }

  /* End of Switch: '<S76>/Switch3' */

  /* Sum: '<S80>/Sum' incorporates:
   *  Constant: '<S76>/Constant13'
   *  Constant: '<S76>/Constant46'
   *  Constant: '<S76>/Constant8'
   *  Product: '<S76>/Product7'
   *  Product: '<S80>/Product'
   *  Product: '<S80>/Product1'
   *  Sum: '<S76>/Add4'
   *  UnitDelay: '<S80>/Unit Delay'
   */
  rtb_VfACCS_Input_Obs_Linea_flzo =
    (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_f1jp * rtb_Switch_iliv_tmp) +
    (((rtb_VfACCS_Input_Obs_Linea_flzo - KfACCS_d_DisToLeadSur) +
      (KfACCS_t_TimeOffset * rtb_Sum_kt3p)) * KfACCS_k_ObjectRangeFilter);

  /* Switch: '<S37>/Switch' */
  if (ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v)
  {
    /* Switch: '<S37>/Switch1' */
    if (ACCS_subsystem_integrate_ConstB.LogicalOperator)
    {
      /* Switch: '<S37>/Switch2' incorporates:
       *  Constant: '<S39>/Constant38'
       *  Constant: '<S39>/Constant39'
       *  Logic: '<S39>/Logical Operator'
       *  Switch: '<S39>/Switch19'
       */
      if (ACCS_subsystem_integrate_ConstB.VeACCS_Input_TurnLightState)
      {
        /* Switch: '<S40>/Switch19' incorporates:
         *  Constant: '<S40>/Constant38'
         *  Constant: '<S40>/Constant39'
         *  Logic: '<S40>/Logical Operator'
         */
        if (!KbACCS_UseVirtualObject)
        {
          /* Switch: '<S40>/Switch13' incorporates:
           *  Constant: '<S40>/Constant32'
           */
          if (ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVR_valid)
          {
            ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Range_n5rr =
              rtb_VfACCS_Input_Obs_Linea_flzo;
          }
          else
          {
            ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Range_n5rr = 0.0F;
          }

          /* End of Switch: '<S40>/Switch13' */
        }
        else
        {
          ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Range_n5rr =
            KfACCS_d_Range_PreSet;
        }

        /* End of Switch: '<S40>/Switch19' */
      }
      else if (!KbACCS_UseVirtualObject)
      {
        /* Switch: '<S39>/Switch13' incorporates:
         *  Constant: '<S39>/Constant32'
         *  Switch: '<S39>/Switch19'
         */
        if (ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVL_valid)
        {
          ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Range_n5rr =
            rtb_Switch11_pxmy;
        }
        else
        {
          ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Range_n5rr = 0.0F;
        }

        /* End of Switch: '<S39>/Switch13' */
      }
      else
      {
        ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Range_n5rr =
          KfACCS_d_Range_PreSet;
      }
    }
    else
    {
      ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Range_n5rr =
        rtb_VfACCS_Input_Obs_Range;
    }
  }
  else
  {
    ACCS_subsystem_integrated_B.VfACCS_Input_Obs_Range_n5rr =
      rtb_VfACCS_Input_Obs_Range;
  }

  /* Switch: '<S76>/Switch4' incorporates:
   *  Constant: '<S76>/Constant9'
   *  RelationalOperator: '<S76>/Relational Operator3'
   */
  if (rtb_Switch11_fwu3 > KfACCS_d_CurvatureRadius_Max)
  {
    rtb_Add11_hcma =
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.nearest_point_rel.y;
  }
  else
  {
    /* Trigonometry: '<S76>/Sin2' */
    rtb_Add11_hcma = (real32_T)sin((real_T)rtb_Add11_hcma);

    /* Switch: '<S76>/Switch5' incorporates:
     *  Abs: '<S76>/Abs2'
     *  Constant: '<S76>/Constant11'
     *  Constant: '<S76>/Constant12'
     *  Product: '<S76>/Divide2'
     *  RelationalOperator: '<S76>/Relational Operator4'
     *  Sum: '<S76>/Add6'
     */
    if (((real_T)((real32_T)fabs((real_T)rtb_Add11_hcma))) > 0.01)
    {
      /* MinMax: '<S76>/Max' incorporates:
       *  Constant: '<S76>/Constant5'
       */
      if (((real_T)rtb_Add11_hcma) > 1.0E-6)
      {
        rtb_Switch5_blbp = (real_T)rtb_Add11_hcma;
      }
      else
      {
        rtb_Switch5_blbp = 1.0E-6;
      }

      /* End of MinMax: '<S76>/Max' */
      rtb_Switch5_blbp = (real_T)((real32_T)(rtb_Switch11_fwu3 - ((real32_T)
        ((real_T)(((real_T)
                   ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.nearest_point_rel.x)
                  / rtb_Switch5_blbp)))));
    }
    else
    {
      rtb_Switch5_blbp = 0.0;
    }

    /* End of Switch: '<S76>/Switch5' */
    rtb_Add11_hcma = (real32_T)rtb_Switch5_blbp;
  }

  /* End of Switch: '<S76>/Switch4' */

  /* Sum: '<S81>/Sum' incorporates:
   *  Constant: '<S76>/Constant10'
   *  Constant: '<S76>/Constant14'
   *  Constant: '<S76>/Constant15'
   *  Product: '<S76>/Product8'
   *  Product: '<S81>/Product'
   *  Product: '<S81>/Product1'
   *  Sum: '<S76>/Add5'
   *  UnitDelay: '<S81>/Unit Delay'
   */
  rtb_Switch11_fwu3 = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_e0dr *
                       rtb_Switch_iliv_tmp) + (((rtb_Add11_hcma -
    KfACCS_d_DisToSideSur) + (KfACCS_t_TimeOffset * rtb_Abs3_daky)) *
    KfACCS_k_ObjectRangeFilter);

  /* Switch: '<S69>/Switch4' incorporates:
   *  Constant: '<S69>/Constant9'
   *  RelationalOperator: '<S69>/Relational Operator3'
   */
  if (rtb_Switch12_cgog > KfACCS_d_CurvatureRadius_Max)
  {
    rtb_Add11_hcma =
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.nearest_point_rel.y;
  }
  else
  {
    /* Trigonometry: '<S69>/Sin2' */
    rtb_Add11_hcma = (real32_T)sin((real_T)rtb_Switch2_cdx1);

    /* Switch: '<S69>/Switch5' incorporates:
     *  Abs: '<S69>/Abs2'
     *  Constant: '<S69>/Constant11'
     *  Constant: '<S69>/Constant12'
     *  Product: '<S69>/Divide2'
     *  RelationalOperator: '<S69>/Relational Operator4'
     *  Sum: '<S69>/Add6'
     */
    if (((real_T)((real32_T)fabs((real_T)rtb_Add11_hcma))) > 0.01)
    {
      /* MinMax: '<S69>/Max' incorporates:
       *  Constant: '<S69>/Constant5'
       */
      if (((real_T)rtb_Add11_hcma) > 1.0E-6)
      {
        rtb_Switch5_blbp = (real_T)rtb_Add11_hcma;
      }
      else
      {
        rtb_Switch5_blbp = 1.0E-6;
      }

      /* End of MinMax: '<S69>/Max' */
      rtb_Switch5_blbp = (real_T)((real32_T)(rtb_Switch12_cgog - ((real32_T)
        ((real_T)(((real_T)
                   ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.nearest_point_rel.x)
                  / rtb_Switch5_blbp)))));
    }
    else
    {
      rtb_Switch5_blbp = 0.0;
    }

    /* End of Switch: '<S69>/Switch5' */
    rtb_Add11_hcma = (real32_T)rtb_Switch5_blbp;
  }

  /* End of Switch: '<S69>/Switch4' */

  /* Sum: '<S74>/Sum' incorporates:
   *  Constant: '<S69>/Constant10'
   *  Constant: '<S69>/Constant14'
   *  Constant: '<S69>/Constant15'
   *  Product: '<S69>/Product8'
   *  Product: '<S74>/Product'
   *  Product: '<S74>/Product1'
   *  Sum: '<S69>/Add5'
   *  UnitDelay: '<S74>/Unit Delay'
   */
  rtb_Switch12_cgog = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ht1h *
                       rtb_Switch_iliv_tmp) + (((rtb_Add11_hcma -
    KfACCS_d_DisToSideSur) + (KfACCS_t_TimeOffset * rtb_Abs3_f3i5)) *
    KfACCS_k_ObjectRangeFilter);

  /* Switch: '<S83>/Switch4' incorporates:
   *  Constant: '<S83>/Constant9'
   *  RelationalOperator: '<S83>/Relational Operator3'
   */
  if (rtb_MathReciprocal_ashu > KfACCS_d_CurvatureRadius_Max)
  {
    rtb_Add11_hcma =
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.nearest_point_rel.y;
  }
  else
  {
    /* Trigonometry: '<S83>/Sin2' */
    rtb_Add11_hcma = (real32_T)sin((real_T)rtb_Switch2_b0i5);

    /* Switch: '<S83>/Switch5' incorporates:
     *  Abs: '<S83>/Abs2'
     *  Constant: '<S83>/Constant11'
     *  Constant: '<S83>/Constant12'
     *  Product: '<S83>/Divide2'
     *  RelationalOperator: '<S83>/Relational Operator4'
     *  Sum: '<S83>/Add6'
     */
    if (((real_T)((real32_T)fabs((real_T)rtb_Add11_hcma))) > 0.01)
    {
      /* MinMax: '<S83>/Max' incorporates:
       *  Constant: '<S83>/Constant5'
       */
      if (((real_T)rtb_Add11_hcma) > 1.0E-6)
      {
        rtb_Switch5_blbp = (real_T)rtb_Add11_hcma;
      }
      else
      {
        rtb_Switch5_blbp = 1.0E-6;
      }

      /* End of MinMax: '<S83>/Max' */
      rtb_Switch5_blbp = (real_T)((real32_T)(rtb_MathReciprocal_ashu -
        ((real32_T)((real_T)(((real_T)
        ACCS_subsystem_integrated_B.VsACCS_Input_Obs_F.nearest_point_rel.x) /
        rtb_Switch5_blbp)))));
    }
    else
    {
      rtb_Switch5_blbp = 0.0;
    }

    /* End of Switch: '<S83>/Switch5' */
    rtb_Add11_hcma = (real32_T)rtb_Switch5_blbp;
  }

  /* End of Switch: '<S83>/Switch4' */

  /* Sum: '<S88>/Sum' incorporates:
   *  Constant: '<S83>/Constant10'
   *  Constant: '<S83>/Constant14'
   *  Constant: '<S83>/Constant15'
   *  Product: '<S83>/Product8'
   *  Product: '<S88>/Product'
   *  Product: '<S88>/Product1'
   *  Sum: '<S83>/Add5'
   *  UnitDelay: '<S88>/Unit Delay'
   */
  rtb_MathReciprocal_ashu = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_jszo *
    rtb_Switch_iliv_tmp) + (((rtb_Add11_hcma - KfACCS_d_DisToSideSur) +
    (KfACCS_t_TimeOffset * rtb_Abs3_ptqq)) * KfACCS_k_ObjectRangeFilter);

  /* Switch: '<S37>/Switch' incorporates:
   *  SignalConversion: '<S41>/Signal Conversion'
   */
  if (ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v)
  {
    /* Switch: '<S37>/Switch1' incorporates:
     *  SignalConversion: '<S41>/Signal Conversion'
     */
    if (ACCS_subsystem_integrate_ConstB.LogicalOperator)
    {
      /* Switch: '<S37>/Switch2' incorporates:
       *  SignalConversion: '<S39>/Signal Conversion'
       *  SignalConversion: '<S40>/Signal Conversion'
       */
      if (ACCS_subsystem_integrate_ConstB.VeACCS_Input_TurnLightState)
      {
        ACCS_subsystem_integrated_B.SignalConversion1 =
          ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVR_valid;
      }
      else
      {
        ACCS_subsystem_integrated_B.SignalConversion1 =
          ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVL_valid;
      }
    }
    else
    {
      ACCS_subsystem_integrated_B.SignalConversion1 =
        ACCS_subsystem_integrated_B.VbACCS_Input_Obs_F_valid;
    }
  }
  else
  {
    ACCS_subsystem_integrated_B.SignalConversion1 =
      ACCS_subsystem_integrated_B.VbACCS_Input_Obs_F_valid;
  }

  /* Sum: '<S42>/Add1' */
  rtb_Add11_hcma = ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.velocity_rel.y
    + VfACCS_Input_latvelocity_EGMO;

  /* Abs: '<S89>/Abs3' */
  rtb_Switch2_b0i5 = (real32_T)fabs((real_T)rtb_Add11_hcma);

  /* Switch: '<S89>/Switch6' incorporates:
   *  Constant: '<S89>/Constant15'
   *  Constant: '<S89>/Constant23'
   *  RelationalOperator: '<S89>/Relational Operator5'
   *  RelationalOperator: '<S89>/Relational Operator6'
   *  Switch: '<S89>/Switch8'
   */
  if (rtb_Switch2_b0i5 >= KfACCS_v_LatSpdDeadband_Max)
  {
  }
  else if (rtb_Switch2_b0i5 >= KfACCS_v_LatSpdDeadband_Min)
  {
    /* MinMax: '<S89>/Max3' incorporates:
     *  Constant: '<S89>/Constant17'
     *  Constant: '<S89>/Constant18'
     *  Sum: '<S89>/Add8'
     *  Switch: '<S89>/Switch8'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(KfACCS_v_LatSpdDeadband_Max -
      KfACCS_v_LatSpdDeadband_Min));

    /* Switch: '<S89>/Switch7' incorporates:
     *  Constant: '<S89>/Constant20'
     *  Constant: '<S89>/Constant21'
     *  Switch: '<S89>/Switch8'
     */
    if (rtb_Add11_hcma > 0.0F)
    {
      rtb_Add11_hcma = (real32_T)1.0;
    }
    else
    {
      rtb_Add11_hcma = (real32_T)(-1.0);
    }

    /* End of Switch: '<S89>/Switch7' */

    /* MinMax: '<S89>/Max3' incorporates:
     *  Constant: '<S89>/Constant19'
     *  Switch: '<S89>/Switch8'
     */
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S89>/Switch8' incorporates:
     *  Constant: '<S89>/Constant16'
     *  Constant: '<S89>/Constant22'
     *  Product: '<S89>/Divide3'
     *  Product: '<S89>/Product9'
     *  Sum: '<S89>/Add7'
     */
    rtb_Add11_hcma = (rtb_Add11_hcma * KfACCS_v_LatSpdDeadband_Max) * ((real32_T)
      ((real_T)(((real_T)((real32_T)(rtb_Switch2_b0i5 -
      KfACCS_v_LatSpdDeadband_Min))) / rtb_Switch5_blbp)));
  }
  else
  {
    /* Switch: '<S89>/Switch8' incorporates:
     *  Constant: '<S89>/Constant24'
     */
    rtb_Add11_hcma = (real32_T)0.0;
  }

  /* End of Switch: '<S89>/Switch6' */

  /* Switch: '<S89>/Switch9' incorporates:
   *  Abs: '<S89>/Abs4'
   *  Constant: '<S89>/Constant26'
   *  RelationalOperator: '<S89>/Relational Operator7'
   *  Sum: '<S89>/Add9'
   *  UnitDelay: '<S89>/Unit Delay'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mpn1)))) >=
      KfACCS_v_LatSpdUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mpn1;
  }

  /* End of Switch: '<S89>/Switch9' */

  /* Sum: '<S93>/Sum' incorporates:
   *  Constant: '<S89>/Constant50'
   *  Product: '<S93>/Product'
   *  Product: '<S93>/Product1'
   *  UnitDelay: '<S93>/Unit Delay'
   */
  rtb_Switch2_b0i5 = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_fxt0 *
                      rtb_Sum_khuf) + (rtb_Add11_hcma * KfACCS_k_ObjectSpdFilter);

  /* Sum: '<S42>/Add22' */
  rtb_Add11_hcma = ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.velocity_rel.x
    + VfACCS_Input_longvelocity_EGMO;

  /* Switch: '<S89>/Switch10' incorporates:
   *  Abs: '<S89>/Abs5'
   *  Constant: '<S89>/Constant25'
   *  RelationalOperator: '<S89>/Relational Operator8'
   *  Sum: '<S89>/Add10'
   *  UnitDelay: '<S89>/Unit Delay1'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_bzek)))) >=
      KfACCS_v_ObjectSpdUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_bzek;
  }

  /* End of Switch: '<S89>/Switch10' */

  /* Sum: '<S92>/Sum' incorporates:
   *  Constant: '<S89>/Constant48'
   *  Product: '<S92>/Product'
   *  Product: '<S92>/Product1'
   *  UnitDelay: '<S92>/Unit Delay'
   */
  rtb_Switch2_cdx1 = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_nmde *
                      rtb_Sum_khuf) + (rtb_Add11_hcma * KfACCS_k_ObjectSpdFilter);

  /* Switch: '<S89>/Switch11' incorporates:
   *  Abs: '<S89>/Abs6'
   *  Constant: '<S89>/Constant28'
   *  MinMax: '<S89>/Max4'
   *  Product: '<S89>/Divide4'
   *  RelationalOperator: '<S89>/Relational Operator9'
   *  Trigonometry: '<S89>/Atan2'
   */
  if (((real_T)((real32_T)fabs((real_T)rtb_Switch2_cdx1))) > 0.0)
  {
    /* MinMax: '<S89>/Max4' incorporates:
     *  Constant: '<S89>/Constant27'
     */
    if (((real_T)rtb_Switch2_cdx1) > 1.0E-6)
    {
      rtb_Switch5_blbp = (real_T)rtb_Switch2_cdx1;
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    rtb_Add11_hcma = (real32_T)atan((real_T)((real32_T)(rtb_Switch2_b0i5 /
      ((real32_T)rtb_Switch5_blbp))));
  }
  else
  {
    rtb_Add11_hcma = (real32_T)ACCS_subsystem_integrate_ConstB.Gain1_i31r;
  }

  /* End of Switch: '<S89>/Switch11' */

  /* Sum: '<S89>/Add16' incorporates:
   *  Product: '<S89>/Product14'
   *  Product: '<S89>/Product15'
   *  Sum: '<S42>/Add23'
   *  Sum: '<S42>/Add24'
   *  Trigonometry: '<S89>/Cos4'
   *  Trigonometry: '<S89>/Sin5'
   */
  rtb_Add11_hcma =
    ((ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.acceleration_rel.x +
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_Accele_dcwi) * ((real32_T)
      cos((real_T)rtb_Add11_hcma))) +
    ((ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.acceleration_rel.y +
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_Acceleratio) * ((real32_T)
      sin((real_T)rtb_Add11_hcma)));

  /* Switch: '<S89>/Switch24' incorporates:
   *  Abs: '<S89>/Abs7'
   *  Constant: '<S89>/Constant47'
   *  RelationalOperator: '<S89>/Relational Operator10'
   *  Sum: '<S89>/Add21'
   *  UnitDelay: '<S89>/Unit Delay2'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_noaa)))) >=
      KfACCS_a_ObjectAccelUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_noaa;
  }

  /* End of Switch: '<S89>/Switch24' */

  /* Sum: '<S91>/Sum' incorporates:
   *  Constant: '<S89>/Constant46'
   *  Product: '<S91>/Product'
   *  Product: '<S91>/Product1'
   *  UnitDelay: '<S91>/Unit Delay'
   */
  rtb_VfACCS_Input_Obs_Range =
    (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mskg * rtb_Sum_hycr) +
    (rtb_Add11_hcma * KfACCS_k_ObjectAccelFilter);

  /* MinMax: '<S90>/Max1' incorporates:
   *  Constant: '<S90>/Constant1'
   */
  if (((real_T)ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q) >
      1.0E-6)
  {
    rtb_Switch5_blbp = (real_T)
      ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q;
  }
  else
  {
    rtb_Switch5_blbp = 1.0E-6;
  }

  /* End of MinMax: '<S90>/Max1' */

  /* Math: '<S90>/Math Reciprocal'
   *
   * About '<S90>/Math Reciprocal':
   *  Operator: reciprocal
   */
  rtb_MathReciprocal_k124 = (real32_T)((real_T)(1.0 / rtb_Switch5_blbp));

  /* Switch: '<S90>/Switch' incorporates:
   *  Constant: '<S90>/Constant2'
   *  Constant: '<S90>/Constant3'
   */
  if (rtb_MathReciprocal_k124 > 0.0F)
  {
    rtb_Add11_hcma = (real32_T)1.0;
  }
  else
  {
    rtb_Add11_hcma = (real32_T)(-1.0);
  }

  /* End of Switch: '<S90>/Switch' */

  /* Switch: '<S90>/Switch1' incorporates:
   *  Abs: '<S90>/Abs'
   *  Abs: '<S90>/Abs1'
   *  Product: '<S90>/Product4'
   *  RelationalOperator: '<S90>/Relational Operator'
   *  RelationalOperator: '<S90>/Relational Operator1'
   *  Switch: '<S90>/Switch2'
   */
  if (rtb_MathReciprocal_k124 ==
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.nearest_point_rel.y)
  {
    rtb_Switch2_mhzu = (real32_T)((real_T)
      (ACCS_subsystem_integrate_ConstB.Gain_k0b0 * ((real_T)rtb_Add11_hcma)));
  }
  else if (((real32_T)fabs((real_T)rtb_MathReciprocal_k124)) > ((real32_T)fabs
            ((real_T)
             ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.nearest_point_rel.y)))
  {
    /* MinMax: '<S90>/Max2' incorporates:
     *  Constant: '<S90>/Constant31'
     *  Sum: '<S90>/Add2'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(rtb_MathReciprocal_k124 -
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.nearest_point_rel.y));
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S90>/Switch2' incorporates:
     *  Product: '<S90>/Divide1'
     *  Trigonometry: '<S90>/Atan1'
     */
    rtb_Switch2_mhzu = (real32_T)atan((real_T)((real32_T)((real_T)(((real_T)
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.nearest_point_rel.x) /
      rtb_Switch5_blbp))));
  }
  else
  {
    /* MinMax: '<S90>/Max2' incorporates:
     *  Constant: '<S90>/Constant31'
     *  Sum: '<S90>/Add2'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(rtb_MathReciprocal_k124 -
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.nearest_point_rel.y));
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S90>/Switch2' incorporates:
     *  Product: '<S90>/Divide1'
     *  Product: '<S90>/Product5'
     *  Sum: '<S90>/Add3'
     *  Trigonometry: '<S90>/Atan1'
     */
    rtb_Switch2_mhzu = ((real32_T)((real_T)(((real_T)rtb_Add11_hcma) *
      ACCS_subsystem_integrate_ConstB.Gain2_mzr0))) + ((real32_T)atan((real_T)
      ((real32_T)((real_T)(((real_T)
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.nearest_point_rel.x) /
      rtb_Switch5_blbp)))));
  }

  /* End of Switch: '<S90>/Switch1' */

  /* Switch: '<S90>/Switch3' incorporates:
   *  Constant: '<S90>/Constant7'
   *  Product: '<S90>/Product6'
   *  RelationalOperator: '<S90>/Relational Operator2'
   */
  if (rtb_MathReciprocal_k124 > KfACCS_d_CurvatureRadius_Max)
  {
    rtb_MathReciprocal_klus =
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.nearest_point_rel.x;
  }
  else
  {
    rtb_MathReciprocal_klus = rtb_Switch2_mhzu * rtb_MathReciprocal_k124;
  }

  /* End of Switch: '<S90>/Switch3' */

  /* Switch: '<S90>/Switch4' incorporates:
   *  Constant: '<S90>/Constant9'
   *  RelationalOperator: '<S90>/Relational Operator3'
   */
  if (rtb_MathReciprocal_k124 > KfACCS_d_CurvatureRadius_Max)
  {
    rtb_Add11_hcma =
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.nearest_point_rel.y;
  }
  else
  {
    /* Trigonometry: '<S90>/Sin2' */
    rtb_Add11_hcma = (real32_T)sin((real_T)rtb_Switch2_mhzu);

    /* Switch: '<S90>/Switch5' incorporates:
     *  Abs: '<S90>/Abs2'
     *  Constant: '<S90>/Constant11'
     *  Constant: '<S90>/Constant12'
     *  Product: '<S90>/Divide2'
     *  RelationalOperator: '<S90>/Relational Operator4'
     *  Sum: '<S90>/Add6'
     */
    if (((real_T)((real32_T)fabs((real_T)rtb_Add11_hcma))) > 0.01)
    {
      /* MinMax: '<S90>/Max' incorporates:
       *  Constant: '<S90>/Constant5'
       */
      if (((real_T)rtb_Add11_hcma) > 1.0E-6)
      {
        rtb_Switch5_blbp = (real_T)rtb_Add11_hcma;
      }
      else
      {
        rtb_Switch5_blbp = 1.0E-6;
      }

      /* End of MinMax: '<S90>/Max' */
      rtb_Switch5_blbp = (real_T)((real32_T)(rtb_MathReciprocal_k124 -
        ((real32_T)((real_T)(((real_T)
        ACCS_subsystem_integrated_B.VsACCS_Input_Obs_L.nearest_point_rel.x) /
        rtb_Switch5_blbp)))));
    }
    else
    {
      rtb_Switch5_blbp = 0.0;
    }

    /* End of Switch: '<S90>/Switch5' */
    rtb_Add11_hcma = (real32_T)rtb_Switch5_blbp;
  }

  /* End of Switch: '<S90>/Switch4' */

  /* Sum: '<S95>/Sum' incorporates:
   *  Constant: '<S90>/Constant10'
   *  Constant: '<S90>/Constant14'
   *  Constant: '<S90>/Constant15'
   *  Product: '<S90>/Product8'
   *  Product: '<S95>/Product'
   *  Product: '<S95>/Product1'
   *  Sum: '<S90>/Add5'
   *  UnitDelay: '<S95>/Unit Delay'
   */
  rtb_MathReciprocal_k124 = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_la5j *
    rtb_Switch_iliv_tmp) + (((rtb_Add11_hcma - KfACCS_d_DisToSideSur) +
    (KfACCS_t_TimeOffset * rtb_Switch2_b0i5)) * KfACCS_k_ObjectRangeFilter);

  /* Sum: '<S43>/Add1' */
  rtb_Add11_hcma = ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.velocity_rel.y
    + VfACCS_Input_latvelocity_EGMO;

  /* Abs: '<S96>/Abs3' */
  rtb_Switch2_mhzu = (real32_T)fabs((real_T)rtb_Add11_hcma);

  /* Switch: '<S96>/Switch6' incorporates:
   *  Constant: '<S96>/Constant15'
   *  Constant: '<S96>/Constant23'
   *  RelationalOperator: '<S96>/Relational Operator5'
   *  RelationalOperator: '<S96>/Relational Operator6'
   *  Switch: '<S96>/Switch8'
   */
  if (rtb_Switch2_mhzu >= KfACCS_v_LatSpdDeadband_Max)
  {
  }
  else if (rtb_Switch2_mhzu >= KfACCS_v_LatSpdDeadband_Min)
  {
    /* MinMax: '<S96>/Max3' incorporates:
     *  Constant: '<S96>/Constant17'
     *  Constant: '<S96>/Constant18'
     *  Sum: '<S96>/Add8'
     *  Switch: '<S96>/Switch8'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(KfACCS_v_LatSpdDeadband_Max -
      KfACCS_v_LatSpdDeadband_Min));

    /* Switch: '<S96>/Switch7' incorporates:
     *  Constant: '<S96>/Constant20'
     *  Constant: '<S96>/Constant21'
     *  Switch: '<S96>/Switch8'
     */
    if (rtb_Add11_hcma > 0.0F)
    {
      rtb_Add11_hcma = (real32_T)1.0;
    }
    else
    {
      rtb_Add11_hcma = (real32_T)(-1.0);
    }

    /* End of Switch: '<S96>/Switch7' */

    /* MinMax: '<S96>/Max3' incorporates:
     *  Constant: '<S96>/Constant19'
     *  Switch: '<S96>/Switch8'
     */
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S96>/Switch8' incorporates:
     *  Constant: '<S96>/Constant16'
     *  Constant: '<S96>/Constant22'
     *  Product: '<S96>/Divide3'
     *  Product: '<S96>/Product9'
     *  Sum: '<S96>/Add7'
     */
    rtb_Add11_hcma = (rtb_Add11_hcma * KfACCS_v_LatSpdDeadband_Max) * ((real32_T)
      ((real_T)(((real_T)((real32_T)(rtb_Switch2_mhzu -
      KfACCS_v_LatSpdDeadband_Min))) / rtb_Switch5_blbp)));
  }
  else
  {
    /* Switch: '<S96>/Switch8' incorporates:
     *  Constant: '<S96>/Constant24'
     */
    rtb_Add11_hcma = (real32_T)0.0;
  }

  /* End of Switch: '<S96>/Switch6' */

  /* Switch: '<S96>/Switch9' incorporates:
   *  Abs: '<S96>/Abs4'
   *  Constant: '<S96>/Constant26'
   *  RelationalOperator: '<S96>/Relational Operator7'
   *  Sum: '<S96>/Add9'
   *  UnitDelay: '<S96>/Unit Delay'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_otyz)))) >=
      KfACCS_v_LatSpdUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_otyz;
  }

  /* End of Switch: '<S96>/Switch9' */

  /* Sum: '<S100>/Sum' incorporates:
   *  Constant: '<S96>/Constant50'
   *  Product: '<S100>/Product'
   *  Product: '<S100>/Product1'
   *  UnitDelay: '<S100>/Unit Delay'
   */
  rtb_Switch2_mhzu = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_oajl *
                      rtb_Sum_khuf) + (rtb_Add11_hcma * KfACCS_k_ObjectSpdFilter);

  /* Sum: '<S43>/Add22' */
  rtb_Add11_hcma = ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.velocity_rel.x
    + VfACCS_Input_longvelocity_EGMO;

  /* Switch: '<S96>/Switch10' incorporates:
   *  Abs: '<S96>/Abs5'
   *  Constant: '<S96>/Constant25'
   *  RelationalOperator: '<S96>/Relational Operator8'
   *  Sum: '<S96>/Add10'
   *  UnitDelay: '<S96>/Unit Delay1'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_cstm)))) >=
      KfACCS_v_ObjectSpdUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_cstm;
  }

  /* End of Switch: '<S96>/Switch10' */

  /* Sum: '<S99>/Sum' incorporates:
   *  Constant: '<S96>/Constant48'
   *  Product: '<S99>/Product'
   *  Product: '<S99>/Product1'
   *  UnitDelay: '<S99>/Unit Delay'
   */
  rtb_Sum_khuf = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_bfjb *
                  rtb_Sum_khuf) + (rtb_Add11_hcma * KfACCS_k_ObjectSpdFilter);

  /* Switch: '<S96>/Switch11' incorporates:
   *  Abs: '<S96>/Abs6'
   *  Constant: '<S96>/Constant28'
   *  MinMax: '<S96>/Max4'
   *  Product: '<S96>/Divide4'
   *  RelationalOperator: '<S96>/Relational Operator9'
   *  Trigonometry: '<S96>/Atan2'
   */
  if (((real_T)((real32_T)fabs((real_T)rtb_Sum_khuf))) > 0.0)
  {
    /* MinMax: '<S96>/Max4' incorporates:
     *  Constant: '<S96>/Constant27'
     */
    if (((real_T)rtb_Sum_khuf) > 1.0E-6)
    {
      rtb_Switch5_blbp = (real_T)rtb_Sum_khuf;
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    rtb_Switch11_mayx = (real32_T)atan((real_T)((real32_T)(rtb_Switch2_mhzu /
      ((real32_T)rtb_Switch5_blbp))));
  }
  else
  {
    rtb_Switch11_mayx = (real32_T)ACCS_subsystem_integrate_ConstB.Gain1_jwej;
  }

  /* End of Switch: '<S96>/Switch11' */

  /* Sum: '<S96>/Add16' incorporates:
   *  Product: '<S96>/Product14'
   *  Product: '<S96>/Product15'
   *  Sum: '<S43>/Add23'
   *  Sum: '<S43>/Add24'
   *  Trigonometry: '<S96>/Cos4'
   *  Trigonometry: '<S96>/Sin5'
   */
  rtb_Add11_hcma =
    ((ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.acceleration_rel.x +
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_Accele_dcwi) * ((real32_T)
      cos((real_T)rtb_Switch11_mayx))) +
    ((ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.acceleration_rel.y +
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_Acceleratio) * ((real32_T)
      sin((real_T)rtb_Switch11_mayx)));

  /* Switch: '<S96>/Switch24' incorporates:
   *  Abs: '<S96>/Abs7'
   *  Constant: '<S96>/Constant47'
   *  RelationalOperator: '<S96>/Relational Operator10'
   *  Sum: '<S96>/Add21'
   *  UnitDelay: '<S96>/Unit Delay2'
   */
  if (((real32_T)fabs((real_T)((real32_T)(rtb_Add11_hcma -
          ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_ee1g)))) >=
      KfACCS_a_ObjectAccelUpdateThrsh)
  {
  }
  else
  {
    rtb_Add11_hcma = ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_ee1g;
  }

  /* End of Switch: '<S96>/Switch24' */

  /* Sum: '<S98>/Sum' incorporates:
   *  Constant: '<S96>/Constant46'
   *  Product: '<S98>/Product'
   *  Product: '<S98>/Product1'
   *  UnitDelay: '<S98>/Unit Delay'
   */
  rtb_Sum_hycr = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ic5u *
                  rtb_Sum_hycr) + (rtb_Add11_hcma * KfACCS_k_ObjectAccelFilter);

  /* MinMax: '<S97>/Max1' incorporates:
   *  Constant: '<S97>/Constant1'
   */
  if (((real_T)ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q) >
      1.0E-6)
  {
    rtb_Switch5_blbp = (real_T)
      ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q;
  }
  else
  {
    rtb_Switch5_blbp = 1.0E-6;
  }

  /* End of MinMax: '<S97>/Max1' */

  /* Math: '<S97>/Math Reciprocal'
   *
   * About '<S97>/Math Reciprocal':
   *  Operator: reciprocal
   */
  rtb_Switch11_mayx = (real32_T)((real_T)(1.0 / rtb_Switch5_blbp));

  /* Switch: '<S97>/Switch' incorporates:
   *  Constant: '<S97>/Constant2'
   *  Constant: '<S97>/Constant3'
   */
  if (rtb_Switch11_mayx > 0.0F)
  {
    rtb_Add11_hcma = (real32_T)1.0;
  }
  else
  {
    rtb_Add11_hcma = (real32_T)(-1.0);
  }

  /* End of Switch: '<S97>/Switch' */

  /* Switch: '<S97>/Switch1' incorporates:
   *  Abs: '<S97>/Abs'
   *  Abs: '<S97>/Abs1'
   *  Product: '<S97>/Product4'
   *  RelationalOperator: '<S97>/Relational Operator'
   *  RelationalOperator: '<S97>/Relational Operator1'
   *  Switch: '<S97>/Switch2'
   */
  if (rtb_Switch11_mayx ==
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.nearest_point_rel.y)
  {
    rtb_Switch2_aer3 = (real32_T)((real_T)
      (ACCS_subsystem_integrate_ConstB.Gain_onru * ((real_T)rtb_Add11_hcma)));
  }
  else if (((real32_T)fabs((real_T)rtb_Switch11_mayx)) > ((real32_T)fabs((real_T)
             ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.nearest_point_rel.y)))
  {
    /* MinMax: '<S97>/Max2' incorporates:
     *  Constant: '<S97>/Constant31'
     *  Sum: '<S97>/Add2'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(rtb_Switch11_mayx -
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.nearest_point_rel.y));
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S97>/Switch2' incorporates:
     *  Product: '<S97>/Divide1'
     *  Trigonometry: '<S97>/Atan1'
     */
    rtb_Switch2_aer3 = (real32_T)atan((real_T)((real32_T)((real_T)(((real_T)
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.nearest_point_rel.x) /
      rtb_Switch5_blbp))));
  }
  else
  {
    /* MinMax: '<S97>/Max2' incorporates:
     *  Constant: '<S97>/Constant31'
     *  Sum: '<S97>/Add2'
     */
    rtb_Switch5_blbp = (real_T)((real32_T)(rtb_Switch11_mayx -
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.nearest_point_rel.y));
    if (rtb_Switch5_blbp > 1.0E-6)
    {
    }
    else
    {
      rtb_Switch5_blbp = 1.0E-6;
    }

    /* Switch: '<S97>/Switch2' incorporates:
     *  Product: '<S97>/Divide1'
     *  Product: '<S97>/Product5'
     *  Sum: '<S97>/Add3'
     *  Trigonometry: '<S97>/Atan1'
     */
    rtb_Switch2_aer3 = ((real32_T)((real_T)(((real_T)rtb_Add11_hcma) *
      ACCS_subsystem_integrate_ConstB.Gain2_mok3))) + ((real32_T)atan((real_T)
      ((real32_T)((real_T)(((real_T)
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.nearest_point_rel.x) /
      rtb_Switch5_blbp)))));
  }

  /* End of Switch: '<S97>/Switch1' */

  /* Switch: '<S97>/Switch4' incorporates:
   *  Constant: '<S97>/Constant9'
   *  RelationalOperator: '<S97>/Relational Operator3'
   */
  if (rtb_Switch11_mayx > KfACCS_d_CurvatureRadius_Max)
  {
    rtb_Add11_hcma =
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.nearest_point_rel.y;
  }
  else
  {
    /* Trigonometry: '<S97>/Sin2' */
    rtb_Add11_hcma = (real32_T)sin((real_T)rtb_Switch2_aer3);

    /* Switch: '<S97>/Switch5' incorporates:
     *  Abs: '<S97>/Abs2'
     *  Constant: '<S97>/Constant11'
     *  Constant: '<S97>/Constant12'
     *  Product: '<S97>/Divide2'
     *  RelationalOperator: '<S97>/Relational Operator4'
     *  Sum: '<S97>/Add6'
     */
    if (((real_T)((real32_T)fabs((real_T)rtb_Add11_hcma))) > 0.01)
    {
      /* MinMax: '<S97>/Max' incorporates:
       *  Constant: '<S97>/Constant5'
       */
      if (((real_T)rtb_Add11_hcma) > 1.0E-6)
      {
        rtb_Switch5_blbp = (real_T)rtb_Add11_hcma;
      }
      else
      {
        rtb_Switch5_blbp = 1.0E-6;
      }

      /* End of MinMax: '<S97>/Max' */
      rtb_Switch5_blbp = (real_T)((real32_T)(rtb_Switch11_mayx - ((real32_T)
        ((real_T)(((real_T)
                   ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.nearest_point_rel.x)
                  / rtb_Switch5_blbp)))));
    }
    else
    {
      rtb_Switch5_blbp = 0.0;
    }

    /* End of Switch: '<S97>/Switch5' */
    rtb_Add11_hcma = (real32_T)rtb_Switch5_blbp;
  }

  /* End of Switch: '<S97>/Switch4' */

  /* Sum: '<S102>/Sum' incorporates:
   *  Constant: '<S97>/Constant10'
   *  Constant: '<S97>/Constant14'
   *  Constant: '<S97>/Constant15'
   *  Product: '<S102>/Product'
   *  Product: '<S102>/Product1'
   *  Product: '<S97>/Product8'
   *  Sum: '<S97>/Add5'
   *  UnitDelay: '<S102>/Unit Delay'
   */
  rtb_Add11_hcma = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_bz5k *
                    rtb_Switch_iliv_tmp) + (((rtb_Add11_hcma -
    KfACCS_d_DisToSideSur) + (KfACCS_t_TimeOffset * rtb_Switch2_mhzu)) *
    KfACCS_k_ObjectRangeFilter);

  /* Update for UnitDelay: '<S44>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mdjq = rtb_Abs3;

  /* Update for UnitDelay: '<S38>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_fi04 =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id;

  /* Update for UnitDelay: '<S38>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mjdv =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id;

  /* Update for UnitDelay: '<S52>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_oamq = rtb_Abs3;

  /* Update for UnitDelay: '<S44>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_g15n = rtb_Sum_nujo;

  /* Update for UnitDelay: '<S51>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_gzk1 = rtb_Sum_nujo;

  /* Update for UnitDelay: '<S44>/Unit Delay3' */
  ACCS_subsystem_integrated_DW.UnitDelay3_DSTATE_cdwe =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id;

  /* Update for Delay: '<S44>/Delay' */
  ACCS_subsystem_integrated_DW.Delay_DSTATE_ml05 = rtb_Add11;

  /* Update for UnitDelay: '<S44>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_a0sb = rtb_Product_kelx;

  /* Update for UnitDelay: '<S50>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_jw3u = rtb_Product_kelx;

  /* Update for UnitDelay: '<S67>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_ihdw = rtb_Limit10to10;

  /* Update for UnitDelay: '<S67>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_iqun = rtb_Switch1;

  /* Update for UnitDelay: '<S67>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mfeb = rtb_Switch2_bksf;

  /* Update for UnitDelay: '<S66>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_exnj =
    VbACCS_Obs_validBeforeDelay;

  /* Update for UnitDelay: '<S66>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_ians = rtb_Switch1_h4qq;

  /* Update for UnitDelay: '<S66>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_kvt4 = rtb_Switch2_otez;

  /* Update for UnitDelay: '<S53>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_kvni = rtb_Switch_n0oh;

  /* Update for UnitDelay: '<S60>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_akoi = rtb_Switch_n0oh;

  /* Update for UnitDelay: '<S60>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_perp = rtb_Switch1_gcg5;

  /* Update for UnitDelay: '<S60>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_k1rh = rtb_Switch2_ciy1;

  /* Update for Delay: '<S56>/Delay1' */
  ACCS_subsystem_integrated_DW.Delay1_DSTATE = rtb_Switch_n0oh;

  /* Update for Delay: '<S56>/Delay' */
  ACCS_subsystem_integrated_DW.Delay_DSTATE_kclz =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id;

  /* Update for UnitDelay: '<S54>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_c2bu = rtb_MathReciprocal;

  /* Update for Delay: '<S56>/Delay2' */
  ACCS_subsystem_integrated_DW.Delay2_DSTATE = rtb_MathReciprocal;

  /* Update for Delay: '<S56>/Delay3' */
  ACCS_subsystem_integrated_DW.Delay3_DSTATE = rtb_Add11;

  /* Update for Delay: '<S46>/Delay10' */
  ACCS_subsystem_integrated_DW.Delay10_DSTATE_iwrp =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.is_cutout;

  /* Update for UnitDelay: '<S57>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_gzqw = rtb_Switch;

  /* Update for Delay: '<S56>/Delay12' */
  ACCS_subsystem_integrated_DW.Delay12_DSTATE = rtb_Switch5_nscd;

  /* Update for Delay: '<S56>/Delay8' */
  ACCS_subsystem_integrated_DW.Delay8_DSTATE =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVR.id;

  /* Update for Delay: '<S56>/Delay9' */
  ACCS_subsystem_integrated_DW.Delay9_DSTATE =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPVL.id;

  /* Update for Delay: '<S56>/Delay5' incorporates:
   *  Logic: '<S56>/Logical Operator6'
   */
  ACCS_subsystem_integrated_DW.Delay5_DSTATE =
    !ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVL_valid;

  /* Update for Delay: '<S56>/Delay11' incorporates:
   *  Logic: '<S56>/Logical Operator7'
   */
  ACCS_subsystem_integrated_DW.Delay11_DSTATE_dnza =
    !ACCS_subsystem_integrated_B.VbACCS_Input_Obs_CIPVR_valid;

  /* Update for Delay: '<S56>/Delay4' */
  ACCS_subsystem_integrated_DW.Delay4_DSTATE =
    ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v;

  /* Update for Delay: '<S56>/Delay6' */
  ACCS_subsystem_integrated_DW.Delay6_DSTATE =
    ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v;

  /* Update for Delay: '<S56>/Delay10' */
  for (idxDelay = 0; idxDelay < 9; idxDelay++)
  {
    ACCS_subsystem_integrated_DW.Delay10_DSTATE[idxDelay] =
      ACCS_subsystem_integrated_DW.Delay10_DSTATE[idxDelay + 1];
  }

  ACCS_subsystem_integrated_DW.Delay10_DSTATE[9] = rtb_Switch_n0oh;

  /* End of Update for Delay: '<S56>/Delay10' */

  /* Update for Delay: '<S56>/Delay7' */
  ACCS_subsystem_integrated_DW.Delay7_DSTATE = rtb_Switch11;

  /* Update for Delay: '<S56>/Delay13' */
  ACCS_subsystem_integrated_DW.Delay13_DSTATE =
    ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v;

  /* Update for UnitDelay: '<S56>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_obhi = rtb_Switch_n0oh;

  /* Update for UnitDelay: '<S56>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_pkqb = rtb_MathReciprocal;

  /* Update for UnitDelay: '<S56>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_ewh0 =
    VfACCS_Input_linear_velocity_EGMO;

  /* Update for Delay: '<S46>/Delay11' */
  ACCS_subsystem_integrated_DW.Delay11_DSTATE = rtb_Switch2_lvye;

  /* Update for Delay: '<S46>/Delay12' */
  ACCS_subsystem_integrated_DW.Delay12_DSTATE_jlce = rtb_CIPVChangedType;

  /* Update for Delay: '<S47>/Delay' */
  ACCS_subsystem_integrated_DW.Delay_DSTATE_jbar =
    ACCS_subsystem_integrated_B.VsACCS_Input_Obs_CIPV.id;

  /* Update for Delay: '<S47>/Delay1' */
  ACCS_subsystem_integrated_DW.Delay1_DSTATE_jitl = rtb_Switch_n0oh;

  /* Update for UnitDelay: '<S64>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_pkvt = rtb_Switch11;

  /* Update for UnitDelay: '<S64>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_lu5x = rtb_Switch1_pa3i;

  /* Update for UnitDelay: '<S64>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mi5a = rtb_Switch2_nhsq;

  /* Update for UnitDelay: '<S61>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_dtcn = rtb_MathReciprocal;

  /* Update for UnitDelay: '<S61>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_ffnd = rtb_Switch1_k02x;

  /* Update for UnitDelay: '<S61>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_gu2l = rtb_Switch2_kl5r;

  /* Update for UnitDelay: '<S62>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_lrqq = rtb_Sum_nujo;

  /* Update for UnitDelay: '<S62>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_jbin = rtb_Switch1_oyua;

  /* Update for UnitDelay: '<S62>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ckgq = rtb_Switch2_kzlb;

  /* Update for UnitDelay: '<S63>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_opog = rtb_Abs3;

  /* Update for UnitDelay: '<S63>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_pq2g = rtb_Switch1_l00p;

  /* Update for UnitDelay: '<S63>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_pimc = rtb_Switch2_du1h;

  /* Update for UnitDelay: '<S65>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_eatc = rtb_Add11;

  /* Update for UnitDelay: '<S65>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_b45d = rtb_Switch1_ic0c;

  /* Update for UnitDelay: '<S65>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_nqfg = rtb_Switch2_krvg;

  /* Update for UnitDelay: '<S68>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_nten = rtb_Abs3_f3i5;

  /* Update for UnitDelay: '<S72>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_kec2 = rtb_Abs3_f3i5;

  /* Update for UnitDelay: '<S71>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_g3bx = rtb_Sum_e3dl;

  /* Update for UnitDelay: '<S68>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_gsho = rtb_Sum_e3dl;

  /* Update for UnitDelay: '<S68>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_pzjs = rtb_Sum_psl2;

  /* Update for UnitDelay: '<S70>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_hcyq = rtb_Sum_psl2;

  /* Update for UnitDelay: '<S79>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_lhxk = rtb_Abs3_daky;

  /* Update for UnitDelay: '<S75>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_dwri = rtb_Abs3_daky;

  /* Update for UnitDelay: '<S78>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_p00p = rtb_Sum_kt3p;

  /* Update for UnitDelay: '<S75>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_ehwx = rtb_Sum_kt3p;

  /* Update for UnitDelay: '<S75>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_byd2 = rtb_Sum_jtad;

  /* Update for UnitDelay: '<S77>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_cqqi = rtb_Sum_jtad;

  /* Update for UnitDelay: '<S84>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_an2b = rtb_Sum_oc5m;

  /* Update for UnitDelay: '<S86>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_bmp0 = rtb_Abs3_ptqq;

  /* Update for UnitDelay: '<S82>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_a5fv = rtb_Abs3_ptqq;

  /* Update for UnitDelay: '<S85>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ar1y = rtb_Sum_g5ql;

  /* Update for UnitDelay: '<S82>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_fbvr = rtb_Sum_g5ql;

  /* Update for UnitDelay: '<S82>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_inkz = rtb_Sum_oc5m;

  /* Update for UnitDelay: '<S87>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_aqya = rtb_Switch11_lqzi;

  /* Update for UnitDelay: '<S73>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_juxr = rtb_Switch11_pxmy;

  /* Update for UnitDelay: '<S80>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_f1jp =
    rtb_VfACCS_Input_Obs_Linea_flzo;

  /* Update for UnitDelay: '<S81>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_e0dr = rtb_Switch11_fwu3;

  /* Update for UnitDelay: '<S74>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ht1h = rtb_Switch12_cgog;

  /* Update for UnitDelay: '<S88>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_jszo = rtb_MathReciprocal_ashu;

  /* Update for UnitDelay: '<S89>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mpn1 = rtb_Switch2_b0i5;

  /* Update for UnitDelay: '<S93>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_fxt0 = rtb_Switch2_b0i5;

  /* Update for UnitDelay: '<S92>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_nmde = rtb_Switch2_cdx1;

  /* Update for UnitDelay: '<S89>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_bzek = rtb_Switch2_cdx1;

  /* Update for UnitDelay: '<S89>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_noaa =
    rtb_VfACCS_Input_Obs_Range;

  /* Update for UnitDelay: '<S91>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_mskg =
    rtb_VfACCS_Input_Obs_Range;

  /* Update for UnitDelay: '<S94>/Unit Delay' incorporates:
   *  Constant: '<S90>/Constant13'
   *  Constant: '<S90>/Constant46'
   *  Constant: '<S90>/Constant8'
   *  Product: '<S90>/Product7'
   *  Product: '<S94>/Product'
   *  Product: '<S94>/Product1'
   *  Sum: '<S90>/Add4'
   *  Sum: '<S94>/Sum'
   */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_jk3b =
    (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_jk3b * rtb_Switch_iliv_tmp) +
    (((rtb_MathReciprocal_klus - KfACCS_d_DisToLeadSur) + (KfACCS_t_TimeOffset *
       rtb_Switch2_cdx1)) * KfACCS_k_ObjectRangeFilter);

  /* Update for UnitDelay: '<S95>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_la5j = rtb_MathReciprocal_k124;

  /* Update for UnitDelay: '<S96>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_otyz = rtb_Switch2_mhzu;

  /* Update for UnitDelay: '<S100>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_oajl = rtb_Switch2_mhzu;

  /* Update for UnitDelay: '<S99>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_bfjb = rtb_Sum_khuf;

  /* Update for UnitDelay: '<S96>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_cstm = rtb_Sum_khuf;

  /* Update for UnitDelay: '<S96>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_ee1g = rtb_Sum_hycr;

  /* Update for UnitDelay: '<S98>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ic5u = rtb_Sum_hycr;

  /* Switch: '<S97>/Switch3' incorporates:
   *  Constant: '<S97>/Constant7'
   *  Product: '<S97>/Product6'
   *  RelationalOperator: '<S97>/Relational Operator2'
   */
  if (rtb_Switch11_mayx > KfACCS_d_CurvatureRadius_Max)
  {
    rtb_Switch11_mayx =
      ACCS_subsystem_integrated_B.VsACCS_Input_Obs_R.nearest_point_rel.x;
  }
  else
  {
    rtb_Switch11_mayx *= rtb_Switch2_aer3;
  }

  /* End of Switch: '<S97>/Switch3' */

  /* Update for UnitDelay: '<S101>/Unit Delay' incorporates:
   *  Constant: '<S97>/Constant13'
   *  Constant: '<S97>/Constant46'
   *  Constant: '<S97>/Constant8'
   *  Product: '<S101>/Product'
   *  Product: '<S101>/Product1'
   *  Product: '<S97>/Product7'
   *  Sum: '<S101>/Sum'
   *  Sum: '<S97>/Add4'
   */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_k5j0 =
    (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_k5j0 * rtb_Switch_iliv_tmp) +
    (((rtb_Switch11_mayx - KfACCS_d_DisToLeadSur) + (KfACCS_t_TimeOffset *
       rtb_Sum_khuf)) * KfACCS_k_ObjectRangeFilter);

  /* Update for UnitDelay: '<S102>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_bz5k = rtb_Add11_hcma;
}

/* Output and update for atomic system: '<S14>/DtrmnACCS_TargetsSecletion' */
void DtrmnACCS_TargetsSecletion(void)
{
  /* SignalConversion: '<S35>/Signal Conversion' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfACCS_Input_Obs_Num = VsOBFU_DataBus.num_obstacles;

  /* MATLAB Function: '<S35>/DtrmnACCS_ObstacleExtraction' */
  DtrmnACCS_ObstacleExtraction();

  /* Outputs for Atomic SubSystem: '<S35>/DtrmnACCS_TargetObject' */
  DtrmnACCS_TargetObject();

  /* End of Outputs for SubSystem: '<S35>/DtrmnACCS_TargetObject' */

  /* SignalConversion: '<S35>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  VfACCS_Input_OBFUTimeStamp_high = VsOBFU_DataBus.timestamp_high;

  /* SignalConversion: '<S35>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/OBFU_DataBus'
   */
  ACCS_subsystem_integrated_B.SignalConversion2 = VsOBFU_DataBus.timestamp_low;
}

/* Output and update for atomic system: '<S4>/DtrmnACCS_InputSignalConvert' */
void DtrmnACCS_InputSignalConvert(void)
{
  boolean_T rtb_RelationalOperator2_fxxl;
  boolean_T rtb_RelationalOperator1_k12t;
  uint8_T rtb_Add2;
  uint8_T rtb_Add3_e2em;
  int32_T u;
  boolean_T VbACCS_InputInfError_tmp;

  /* Delay: '<S14>/Delay1' */
  ACCS_subsystem_integrated_B.SignalConversion1_dk4z =
    ACCS_subsystem_integrated_DW.Delay1_DSTATE_g2ma;

  /* Delay: '<S14>/Delay' */
  ACCS_subsystem_integrated_B.Delay = ACCS_subsystem_integrated_DW.Delay_DSTATE;

  /* Outputs for Atomic SubSystem: '<S14>/DtrmnACCS_EgoStatusFrmCan' */
  DtrmnACCS_EgoStatusFrmCan();

  /* End of Outputs for SubSystem: '<S14>/DtrmnACCS_EgoStatusFrmCan' */

  /* Outputs for Atomic SubSystem: '<S14>/DtrmnACCS_TargetsSecletion' */
  DtrmnACCS_TargetsSecletion();

  /* End of Outputs for SubSystem: '<S14>/DtrmnACCS_TargetsSecletion' */

  /* RelationalOperator: '<S33>/Relational Operator2' incorporates:
   *  Constant: '<S33>/Constant6'
   *  Sum: '<S33>/Add1'
   */
  rtb_RelationalOperator2_fxxl = ((ACCS_subsystem_integrated_B.SignalConversion2
    - ACCS_subsystem_integrated_B.VfACCS_Input_EGMOTimeStamp_low) >=
    KfACCS_t_MaxTimeStampDiff);

  /* Sum: '<S33>/Add4' */
  u = VfACCS_Input_OBFUTimeStamp_high - VfACCS_Input_EGMOTimeStamp_high;

  /* Abs: '<S33>/Abs1' */
  if (u < 0)
  {
    /* RelationalOperator: '<S33>/Relational Operator1' */
    u = -u;
  }

  /* End of Abs: '<S33>/Abs1' */

  /* RelationalOperator: '<S33>/Relational Operator1' incorporates:
   *  Constant: '<S33>/Constant1'
   */
  if (u < 0)
  {
    u = 0;
  }

  rtb_RelationalOperator1_k12t = (((uint32_T)u) >= KfACCS_t_MaxTimeStampDiff);

  /* Switch: '<S33>/Switch4' incorporates:
   *  Constant: '<S33>/Constant10'
   *  RelationalOperator: '<S33>/Relational Operator4'
   *  UnitDelay: '<S33>/Unit Delay'
   *  UnitDelay: '<S33>/Unit Delay1'
   */
  if (VfACCS_Input_OBFUTimeStamp_high ==
      ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_o4mr)
  {
    rtb_Add3_e2em = ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_d3rt;
  }
  else
  {
    rtb_Add3_e2em = ((uint8_T)0U);
  }

  /* End of Switch: '<S33>/Switch4' */

  /* Sum: '<S33>/Add2' incorporates:
   *  Constant: '<S33>/Constant11'
   */
  rtb_Add2 = (uint8_T)(((uint32_T)rtb_Add3_e2em) + ((uint32_T)((uint8_T)1U)));

  /* Switch: '<S33>/Switch5' incorporates:
   *  Constant: '<S33>/Constant13'
   *  RelationalOperator: '<S33>/Relational Operator6'
   *  UnitDelay: '<S33>/Unit Delay2'
   *  UnitDelay: '<S33>/Unit Delay4'
   */
  if (VfACCS_Input_EGMOTimeStamp_high ==
      ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_c5z1)
  {
    rtb_Add3_e2em = ACCS_subsystem_integrated_DW.UnitDelay4_DSTATE_jzbz;
  }
  else
  {
    rtb_Add3_e2em = ((uint8_T)0U);
  }

  /* End of Switch: '<S33>/Switch5' */

  /* Sum: '<S33>/Add3' incorporates:
   *  Constant: '<S33>/Constant14'
   */
  rtb_Add3_e2em = (uint8_T)(((uint32_T)rtb_Add3_e2em) + ((uint32_T)((uint8_T)1U)));

  /* Logic: '<S33>/Logical Operator5' incorporates:
   *  Constant: '<S33>/Constant16'
   *  Logic: '<S33>/Logical Operator8'
   */
  VbACCS_InputInfError_tmp = !KbACCS_IgnoreOBFUTimeStampBug;

  /* Logic: '<S33>/Logical Operator13' incorporates:
   *  Constant: '<S33>/Constant12'
   *  Constant: '<S33>/Constant15'
   *  Constant: '<S33>/Constant2'
   *  Logic: '<S33>/Logical Operator'
   *  Logic: '<S33>/Logical Operator1'
   *  Logic: '<S33>/Logical Operator10'
   *  Logic: '<S33>/Logical Operator11'
   *  Logic: '<S33>/Logical Operator12'
   *  Logic: '<S33>/Logical Operator14'
   *  Logic: '<S33>/Logical Operator2'
   *  Logic: '<S33>/Logical Operator3'
   *  Logic: '<S33>/Logical Operator4'
   *  Logic: '<S33>/Logical Operator5'
   *  Logic: '<S33>/Logical Operator6'
   *  Logic: '<S33>/Logical Operator7'
   *  Logic: '<S33>/Logical Operator9'
   *  RelationalOperator: '<S33>/Relational Operator10'
   *  RelationalOperator: '<S33>/Relational Operator3'
   *  RelationalOperator: '<S33>/Relational Operator5'
   *  RelationalOperator: '<S33>/Relational Operator7'
   *  RelationalOperator: '<S33>/Relational Operator8'
   *  RelationalOperator: '<S33>/Relational Operator9'
   */
  VbACCS_InputInfError = ((((rtb_Add2 >= KcACCS_TimeStampErrLimit) ||
    ((((ACCS_subsystem_integrated_B.SignalConversion2 <
        ACCS_subsystem_integrated_B.VfACCS_Input_EGMOTimeStamp_low) &&
       rtb_RelationalOperator2_fxxl) || ((VfACCS_Input_OBFUTimeStamp_high <
    VfACCS_Input_EGMOTimeStamp_high) && rtb_RelationalOperator1_k12t)) &&
     VbACCS_InputInfError_tmp)) || ((rtb_Add3_e2em >= KcACCS_TimeStampErrLimit) ||
    (((rtb_RelationalOperator2_fxxl &&
       (ACCS_subsystem_integrated_B.SignalConversion2 >
        ACCS_subsystem_integrated_B.VfACCS_Input_EGMOTimeStamp_low)) ||
      (rtb_RelationalOperator1_k12t && (VfACCS_Input_OBFUTimeStamp_high >
    VfACCS_Input_EGMOTimeStamp_high))) && VbACCS_InputInfError_tmp))) &&
    (!KbACCS_IgnoreTimeStampError));

  /* Logic: '<S14>/Logical Operator' */
  ACCS_subsystem_integrated_B.LogicalOperator =
    ((ACCS_subsystem_integrated_B.LogicalOperator) || VbACCS_InputInfError);

  /* SignalConversion: '<S14>/BusConversion_InsertedFor_ACCS_DCSN_BUS _at_inport_0' */
  ACCS_subsystem_integrated_B.VbACCS_Input_NoSpdLimit_mvju =
    VbACCS_Input_NoSpdLimit;

  /* SignalConversion: '<S14>/BusConversion_InsertedFor_ACCS_DCSN_BUS _at_inport_0' */
  ACCS_subsystem_integrated_B.SignalConversion1_dk4z =
    VbACCS_Input_acc_feature_enable_DCSN;

  /* SignalConversion: '<S14>/BusConversion_InsertedFor_ACCS_DCSN_BUS _at_inport_0' */
  ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v =
    VbACCS_Input_stop_request_DCSN;

  /* SignalConversion: '<S14>/BusConversion_InsertedFor_ACCS_DCSN_BUS _at_inport_0' */
  ACCS_subsystem_integrated_B.VfACCS_Input_stop_s_distance_DC =
    VfACCS_Input_stop_s_distance_DCSN;

  /* SignalConversion: '<S14>/BusConversion_InsertedFor_ACCS_DCSN_BUS _at_inport_0' */
  ACCS_subsystem_integrated_B.VfACCS_Input_traffic_speed_limi =
    VfACCS_Input_traffic_speed_limit_DCSN;

  /* SignalConversion: '<S14>/BusConversion_InsertedFor_ACCS_EGMO_BUS _at_inport_0' */
  ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG =
    VfACCS_Input_linear_velocity_EGMO;

  /* SignalConversion: '<S14>/BusConversion_InsertedFor_ACCS_EGMO_BUS _at_inport_0' */
  ACCS_subsystem_integrated_B.VfACCS_Input_linear_Accele_p235 =
    VfACCS_Input_linear_Acceleration_EGMO;

  /* SignalConversion: '<S14>/BusConversion_InsertedFor_ACCS_EGMO_BUS _at_inport_0' */
  ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q =
    VfACCS_Input_EgoPitch_EGMO;

  /* Update for Delay: '<S14>/Delay1' */
  ACCS_subsystem_integrated_DW.Delay1_DSTATE_g2ma = VbACCS_Input_Obs_valid;

  /* Update for Delay: '<S14>/Delay' */
  ACCS_subsystem_integrated_DW.Delay_DSTATE = VfACCS_Input_Obs_LinearVelocity;

  /* Saturate: '<S33>/Saturation' */
  if (rtb_Add2 < ((uint8_T)100U))
  {
    /* Update for UnitDelay: '<S33>/Unit Delay1' */
    ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_d3rt = rtb_Add2;
  }
  else
  {
    /* Update for UnitDelay: '<S33>/Unit Delay1' */
    ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_d3rt = ((uint8_T)100U);
  }

  /* End of Saturate: '<S33>/Saturation' */

  /* Update for UnitDelay: '<S33>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_o4mr =
    VfACCS_Input_OBFUTimeStamp_high;

  /* Saturate: '<S33>/Saturation1' */
  if (rtb_Add3_e2em < ((uint8_T)100U))
  {
    /* Update for UnitDelay: '<S33>/Unit Delay4' */
    ACCS_subsystem_integrated_DW.UnitDelay4_DSTATE_jzbz = rtb_Add3_e2em;
  }
  else
  {
    /* Update for UnitDelay: '<S33>/Unit Delay4' */
    ACCS_subsystem_integrated_DW.UnitDelay4_DSTATE_jzbz = ((uint8_T)100U);
  }

  /* End of Saturate: '<S33>/Saturation1' */

  /* Update for UnitDelay: '<S33>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_c5z1 =
    VfACCS_Input_EGMOTimeStamp_high;
}

/* Output and update for atomic system: '<S107>/CalcACCS_RampAcceleration' */
void CalcACCS_RampAcceleration(void)
{
  real32_T rtb_Switch2_itwq;

  /* Switch: '<S110>/Switch' incorporates:
   *  Constant: '<S110>/Constant1'
   *  RelationalOperator: '<S110>/Relational Operator'
   *  RelationalOperator: '<S110>/Relational Operator2'
   *  Switch: '<S110>/Switch2'
   */
  if (VfACCS_FinalDrsdAcceleration_old <= VfACCS_TargetDrsdLonAccel)
  {
    /* Switch: '<S110>/Switch1' incorporates:
     *  Constant: '<S110>/Constant'
     *  RelationalOperator: '<S110>/Relational Operator1'
     *  Sum: '<S110>/Add'
     */
    if (VfACCS_Acceleartion_RampUpStep == 0.0F)
    {
      rtb_Switch2_itwq = VfACCS_TargetDrsdLonAccel;
    }
    else
    {
      rtb_Switch2_itwq = VfACCS_Acceleartion_RampUpStep +
        VfACCS_FinalDrsdAcceleration_old;
    }

    /* End of Switch: '<S110>/Switch1' */

    /* MinMax: '<S110>/MinMax' */
    if (VfACCS_TargetDrsdLonAccel < rtb_Switch2_itwq)
    {
      ACCS_subsystem_integrated_B.Switch = VfACCS_TargetDrsdLonAccel;
    }
    else
    {
      ACCS_subsystem_integrated_B.Switch = rtb_Switch2_itwq;
    }

    /* End of MinMax: '<S110>/MinMax' */
  }
  else
  {
    if (VfACCS_Acceleartion_RampDownStep == 0.0F)
    {
      /* Switch: '<S110>/Switch2' */
      rtb_Switch2_itwq = VfACCS_TargetDrsdLonAccel;
    }
    else
    {
      /* Switch: '<S110>/Switch2' incorporates:
       *  Sum: '<S110>/Subtract'
       */
      rtb_Switch2_itwq = VfACCS_FinalDrsdAcceleration_old -
        VfACCS_Acceleartion_RampDownStep;
    }

    /* MinMax: '<S110>/MinMax1' */
    if (VfACCS_TargetDrsdLonAccel > rtb_Switch2_itwq)
    {
      ACCS_subsystem_integrated_B.Switch = VfACCS_TargetDrsdLonAccel;
    }
    else
    {
      ACCS_subsystem_integrated_B.Switch = rtb_Switch2_itwq;
    }

    /* End of MinMax: '<S110>/MinMax1' */
  }

  /* End of Switch: '<S110>/Switch' */
}

/* Output and update for atomic system: '<S107>/CalcACCS_RampStep' */
void CalcACCS_RampStep(void)
{
  boolean_T VbACCS_EnableLaunchToSpdRamp_0;
  boolean_T VbACCS_EnableLaunchToFollowRa_0;
  boolean_T VbACCS_EnableSpeedToFollowRam_0;
  boolean_T VbACCS_EnableFollowToSpeedRam_0;
  real32_T Acceleartion_RampUpStep;
  real32_T Acceleartion_RampDownStep;
  real32_T rtb_UnitDelay1;
  real32_T rtb_UnitDelay2_lxoi;
  real32_T rtb_UnitDelay3_hjdj;
  real32_T rtb_UnitDelay4;

  /* UnitDelay: '<S111>/Unit Delay1' */
  rtb_UnitDelay1 = VfACCS_LaunchToSpdRampTimer;

  /* UnitDelay: '<S111>/Unit Delay2' */
  rtb_UnitDelay2_lxoi = VfACCS_LaunchToFollowRampTimer;

  /* UnitDelay: '<S111>/Unit Delay3' */
  rtb_UnitDelay3_hjdj = VfACCS_SpeedToFollowRampTimer;

  /* UnitDelay: '<S111>/Unit Delay4' */
  rtb_UnitDelay4 = VfACCS_FollowToSpdRampTimer;

  /* MATLAB Function: '<S111>/MATLAB Function' incorporates:
   *  UnitDelay: '<S111>/Unit Delay1'
   *  UnitDelay: '<S111>/Unit Delay2'
   *  UnitDelay: '<S111>/Unit Delay3'
   *  UnitDelay: '<S111>/Unit Delay4'
   *  UnitDelay: '<S111>/Unit Delay5'
   *  UnitDelay: '<S111>/Unit Delay6'
   *  UnitDelay: '<S111>/Unit Delay7'
   *  UnitDelay: '<S111>/Unit Delay8'
   */
  Acceleartion_RampUpStep = 0.0F;
  Acceleartion_RampDownStep = 0.0F;
  VbACCS_EnableLaunchToSpdRamp_0 = VbACCS_EnableLaunchToSpdRamp;
  VbACCS_EnableFollowToSpeedRam_0 = VbACCS_EnableFollowToSpeedRamp;
  VbACCS_EnableLaunchToFollowRa_0 =
    ACCS_subsystem_integrated_DW.UnitDelay6_DSTATE;
  VbACCS_EnableSpeedToFollowRam_0 =
    ACCS_subsystem_integrated_DW.UnitDelay7_DSTATE;
  if ((((((((((uint32_T)VeACCS_StatusTransferType) == NoTransfer) || (((uint32_T)
              VeACCS_StatusTransferType) == FromOnToStop)) || (((uint32_T)
             VeACCS_StatusTransferType) == FromTempStopToStop)) || (((uint32_T)
            VeACCS_StatusTransferType) == FromLowSpeedToTempStop)) ||
         (((uint32_T)VeACCS_StatusTransferType) == FromLaunchToTempStop)) ||
        (((uint32_T)VeACCS_StatusTransferType) == FromStopToLaunch)) ||
       (((uint32_T)VeACCS_StatusTransferType) == FromTempStopToLaunch)) ||
      (((uint32_T)VeACCS_StatusTransferType) == FromLaunchToLowSpeed))
  {
  }
  else
  {
    switch (VeACCS_StatusTransferType)
    {
     case FromLaunchToSpeedCtrl:
      VbACCS_EnableLaunchToSpdRamp_0 = true;
      VbACCS_EnableFollowToSpeedRam_0 = false;
      VbACCS_EnableLaunchToFollowRa_0 = false;
      VbACCS_EnableSpeedToFollowRam_0 = false;
      break;

     case FromFollowingToSpeedCtrl:
      VbACCS_EnableLaunchToSpdRamp_0 = false;
      VbACCS_EnableFollowToSpeedRam_0 = true;
      VbACCS_EnableLaunchToFollowRa_0 = false;
      VbACCS_EnableSpeedToFollowRam_0 = false;
      break;

     case FromLaunchToFollowingCtrl:
      VbACCS_EnableLaunchToSpdRamp_0 = false;
      VbACCS_EnableFollowToSpeedRam_0 = false;
      VbACCS_EnableLaunchToFollowRa_0 = true;
      VbACCS_EnableSpeedToFollowRam_0 = false;
      break;

     case FromSpeedToFollowing:
      VbACCS_EnableLaunchToSpdRamp_0 = false;
      VbACCS_EnableFollowToSpeedRam_0 = false;
      VbACCS_EnableLaunchToFollowRa_0 = false;
      VbACCS_EnableSpeedToFollowRam_0 = true;
      break;

     default:
      /* no actions */
      break;
    }
  }

  if (VbACCS_EnableLaunchToSpdRamp_0)
  {
    rtb_UnitDelay1 = VfACCS_LaunchToSpdRampTimer + 0.01F;
    Acceleartion_RampUpStep = KfACCS_a_LaunchToSpdRampUpStep;
    Acceleartion_RampDownStep = KfACCS_a_LaunchToSpdRampDownStep;
  }
  else if (VbACCS_EnableFollowToSpeedRam_0)
  {
    rtb_UnitDelay4 = VfACCS_FollowToSpdRampTimer + 0.01F;
    Acceleartion_RampUpStep = KfACCS_a_FollowToSpdRampUpStep;
    Acceleartion_RampDownStep = KfACCS_a_FollowToSpdRampDownStep;
  }
  else if (VbACCS_EnableLaunchToFollowRa_0)
  {
    rtb_UnitDelay2_lxoi = VfACCS_LaunchToFollowRampTimer + 0.01F;
    Acceleartion_RampUpStep = KfACCS_a_LaunchToFollowRampUpStep;
    Acceleartion_RampDownStep = KfACCS_a_LaunchToFollowRampDownStep;
  }
  else
  {
    if (VbACCS_EnableSpeedToFollowRam_0)
    {
      rtb_UnitDelay3_hjdj = VfACCS_SpeedToFollowRampTimer + 0.01F;
      Acceleartion_RampUpStep = KfACCS_a_SpeedToFollowRampUpStep;
      Acceleartion_RampDownStep = KfACCS_a_SpeedToFollowRampDownStep;
    }
  }

  if ((rtb_UnitDelay1 >= KfACCS_t_LaunchToSpdRampTimerThrsh) || (((uint32_T)
        VeACCS_RunStatus) != ACCS_status_SpeedCtrl))
  {
    VbACCS_EnableLaunchToSpdRamp_0 = false;
    rtb_UnitDelay1 = 0.0F;
  }
  else
  {
    if ((rtb_UnitDelay4 >= KfACCS_t_FollowToSpdRampTimerThrsh) || (((uint32_T)
          VeACCS_RunStatus) != ACCS_status_SpeedCtrl))
    {
      VbACCS_EnableFollowToSpeedRam_0 = false;
      rtb_UnitDelay4 = 0.0F;
    }
  }

  if (((!VbACCS_EnableLaunchToSpdRamp_0) || (!VbACCS_EnableFollowToSpeedRam_0)) &&
      (((uint32_T)VeACCS_RunStatus) == ACCS_status_SpeedCtrl))
  {
    Acceleartion_RampUpStep = KfACCS_a_StatusSpeedAcceleRampUpStep;
    Acceleartion_RampDownStep = KfACCS_a_StatusSpeedAcceleRampDownStep;
  }

  if ((rtb_UnitDelay2_lxoi >= KfACCS_t_LaunchToFollowRampTimerThrsh) ||
      (((uint32_T)VeACCS_RunStatus) != ACCS_status_FollowingCtrl))
  {
    VbACCS_EnableLaunchToFollowRa_0 = false;
    rtb_UnitDelay2_lxoi = 0.0F;
  }
  else
  {
    if ((rtb_UnitDelay3_hjdj >= KfACCS_t_SpeedToFollowRampTimerThrsh) ||
        (((uint32_T)VeACCS_RunStatus) != ACCS_status_FollowingCtrl))
    {
      VbACCS_EnableSpeedToFollowRam_0 = false;
      rtb_UnitDelay3_hjdj = 0.0F;
    }
  }

  if (((!VbACCS_EnableSpeedToFollowRam_0) || (!VbACCS_EnableLaunchToFollowRa_0))
      && (((uint32_T)VeACCS_RunStatus) == ACCS_status_FollowingCtrl))
  {
    Acceleartion_RampUpStep = KfACCS_a_StatusFollowAcceleRampUpStep;
    Acceleartion_RampDownStep = KfACCS_a_StatusFollowAcceleRampDownStep;
  }

  VfACCS_Acceleartion_RampUpStep = Acceleartion_RampUpStep;
  VfACCS_Acceleartion_RampDownStep = Acceleartion_RampDownStep;
  VfACCS_LaunchToSpdRampTimer = rtb_UnitDelay1;
  VfACCS_LaunchToFollowRampTimer = rtb_UnitDelay2_lxoi;
  VfACCS_SpeedToFollowRampTimer = rtb_UnitDelay3_hjdj;
  VfACCS_FollowToSpdRampTimer = rtb_UnitDelay4;
  VbACCS_EnableLaunchToSpdRamp = VbACCS_EnableLaunchToSpdRamp_0;
  VbACCS_EnableLaunchToFollowRamp = VbACCS_EnableLaunchToFollowRa_0;
  VbACCS_EnableSpeedToFollowRamp = VbACCS_EnableSpeedToFollowRam_0;
  VbACCS_EnableFollowToSpeedRamp = VbACCS_EnableFollowToSpeedRam_0;

  /* End of MATLAB Function: '<S111>/MATLAB Function' */

  /* Update for UnitDelay: '<S111>/Unit Delay6' */
  ACCS_subsystem_integrated_DW.UnitDelay6_DSTATE =
    VbACCS_EnableLaunchToFollowRamp;

  /* Update for UnitDelay: '<S111>/Unit Delay7' */
  ACCS_subsystem_integrated_DW.UnitDelay7_DSTATE =
    VbACCS_EnableSpeedToFollowRamp;
}

/* Output and update for atomic system: '<S103>/DtrmnACCS_Acceleration_Ramp' */
void DtrmnACCS_Acceleration_Ramp(void)
{
  /* Outputs for Atomic SubSystem: '<S107>/CalcACCS_RampStep' */
  CalcACCS_RampStep();

  /* End of Outputs for SubSystem: '<S107>/CalcACCS_RampStep' */

  /* Outputs for Atomic SubSystem: '<S107>/CalcACCS_RampAcceleration' */
  CalcACCS_RampAcceleration();

  /* End of Outputs for SubSystem: '<S107>/CalcACCS_RampAcceleration' */
}

/* Output and update for atomic system: '<S15>/ClacACCS_DsrdLonAccel' */
void ClacACCS_DsrdLonAccel(void)
{
  /* local block i/o variables */
  real32_T rtb_Abs_hdjs;
  real32_T rtb_KtACCS_a_StopStatus_Accel;
  real32_T rtb_UnitDelay_alis;
  real32_T rtb_Sum_hia3;

  /* Switch: '<S103>/Switch2' incorporates:
   *  Constant: '<S103>/Constant2'
   *  Lookup_n-D: '<S103>/KtACCS_r_DCSNStopSpdGain'
   *  Product: '<S103>/Product2'
   */
  if (VbACCS_NeedRespStopFrmDCSN)
  {
    /* Sum: '<S103>/Sum2' incorporates:
     *  Constant: '<S103>/Constant8'
     *  Lookup_n-D: '<S103>/KtACCS_r_DCSNStopDistanceGain '
     *  Product: '<S103>/Product1'
     *  Sum: '<S103>/Subtract'
     */
    rtb_UnitDelay_alis =
      (ACCS_subsystem_integrated_B.VfACCS_Input_stop_s_distance_DC *
       look2_iflf_binlc
       (ACCS_subsystem_integrated_B.VfACCS_Input_stop_s_distance_DC,
        ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG,
        KtACCS_AXIS_DCSNStopDisGain_d, KtACCS_AXIS_DCSNStopGain_VehSpd,
        KtACCS_r_DCSNStopDistanceGain,
        ACCS_subsystem_integrate_ConstP.KtACCS_r_DCSNStopDistanceGain_m, 13U)) +
      (0.0F - ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG);
    rtb_UnitDelay_alis *= look2_iflf_binlc(rtb_UnitDelay_alis,
      ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG,
      KtACCS_AXIS_DCSNStopGainSpd_SpdErr, KtACCS_AXIS_DCSNStopGain_VehSpd,
      KtACCS_r_DCSNStopSpdGain,
      ACCS_subsystem_integrate_ConstP.KtACCS_r_DCSNStopSpdGain_maxInd, 11U);
  }
  else
  {
    rtb_UnitDelay_alis = 0.0F;
  }

  /* End of Switch: '<S103>/Switch2' */

  /* Sum: '<S103>/Sum1' */
  VfACCS_DCSNStopAccel = VfACCS_OpenAccel_ForDCSNStop + rtb_UnitDelay_alis;

  /* Switch: '<S103>/Switch3' incorporates:
   *  Sum: '<S103>/Sum'
   */
  if (VbACCS_NeedRespStopFrmDCSN)
  {
    /* Sum: '<S103>/Sum' */
    rtb_Sum_hia3 = VfACCS_DrsdAccelFrmRngSped + VfACCS_FeedForwardAccel;

    /* MinMax: '<S103>/MinMax' incorporates:
     *  Sum: '<S103>/Sum'
     */
    if (VfACCS_DCSNStopAccel < rtb_Sum_hia3)
    {
      VfACCS_DrsdAccelWithDCSN = VfACCS_DCSNStopAccel;
    }
    else
    {
      VfACCS_DrsdAccelWithDCSN = rtb_Sum_hia3;
    }

    /* End of MinMax: '<S103>/MinMax' */
  }
  else
  {
    VfACCS_DrsdAccelWithDCSN = VfACCS_DrsdAccelFrmRngSped +
      VfACCS_FeedForwardAccel;
  }

  /* End of Switch: '<S103>/Switch3' */

  /* Sum: '<S108>/Sum' incorporates:
   *  Constant: '<S103>/Constant6'
   *  Constant: '<S108>/Constant'
   *  Product: '<S108>/Product'
   *  Product: '<S108>/Product1'
   *  Sum: '<S108>/Subtract'
   *  UnitDelay: '<S108>/Unit Delay'
   */
  rtb_Sum_hia3 = (ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_pniz * (1.0F -
    KfACCS_k_EgoPitchFilter)) +
    (ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q *
     KfACCS_k_EgoPitchFilter);

  /* Switch: '<S103>/Switch' incorporates:
   *  Constant: '<S103>/Constant3'
   *  Constant: '<S103>/Gravity_Acc'
   *  Constant: '<S103>/const'
   *  Product: '<S103>/Product3'
   *  Trigonometry: '<S103>/Trigonometric Function'
   */
  if (KbACCS_EnblSlopeOfst)
  {
    rtb_UnitDelay_alis = ((real32_T)sin((real_T)rtb_Sum_hia3)) * 9.8F;
  }
  else
  {
    rtb_UnitDelay_alis = 0.0F;
  }

  /* End of Switch: '<S103>/Switch' */

  /* Sum: '<S103>/Add' */
  VfACCS_DrsdAccelWithPitch = VfACCS_DrsdAccelWithDCSN + rtb_UnitDelay_alis;

  /* Switch: '<S103>/Switch1' incorporates:
   *  Constant: '<S103>/Constant36'
   *  Constant: '<S103>/Constant4'
   *  Constant: '<S103>/Constant9'
   *  Logic: '<S103>/Logical Operator'
   *  Logic: '<S103>/Logical Operator1'
   *  Lookup: '<S103>/KtACCS_a_StopStatus_Accel'
   *  RelationalOperator: '<S103>/Relational Operator1'
   *  RelationalOperator: '<S103>/Relational Operator2'
   */
  if (((VeACCS_RunStatus == ACCS_status_Stop) || (VeACCS_RunStatus ==
        ACCS_status_TempStop)) && KbACCS_UseStopStatus_Accel)
  {
    /* Abs: '<S103>/Abs' incorporates:
     *  Constant: '<S103>/Constant'
     *  Product: '<S103>/Product'
     */
    rtb_Abs_hdjs = (real32_T)fabs((real_T)((real32_T)
      (ACCS_subsystem_integrated_B.VfACCS_Input_EgoPitch_EGMO_av3q * 57.3248405F)));

    /* Lookup: '<S103>/KtACCS_a_StopStatus_Accel' */
    /*
     * About '<S103>/KtACCS_a_StopStatus_Accel':
     * Input0  Data Type:  Floating Point real32_T
     * Output0 Data Type:  Floating Point real32_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real32_T_real32_T( &(rtb_KtACCS_a_StopStatus_Accel),
      KtACCS_a_StopStatus_Accel, rtb_Abs_hdjs,
      KtACCS_AXIS_StopStatus_Accel_Pitch, 9U);
    rtb_UnitDelay_alis = rtb_KtACCS_a_StopStatus_Accel;
  }
  else
  {
    rtb_UnitDelay_alis = VfACCS_DrsdAccelWithPitch;
  }

  /* End of Switch: '<S103>/Switch1' */

  /* MinMax: '<S103>/Min' incorporates:
   *  Constant: '<S103>/Constant5'
   */
  if (KfACCS_a_OutAccelHiThrsh < rtb_UnitDelay_alis)
  {
    rtb_UnitDelay_alis = KfACCS_a_OutAccelHiThrsh;
  }

  /* End of MinMax: '<S103>/Min' */

  /* MinMax: '<S103>/max' incorporates:
   *  Constant: '<S103>/Constant7'
   */
  if (rtb_UnitDelay_alis > KfACCS_a_OutAccelLoThrsh)
  {
  }
  else
  {
    rtb_UnitDelay_alis = KfACCS_a_OutAccelLoThrsh;
  }

  /* End of MinMax: '<S103>/max' */

  /* Sum: '<S109>/Sum' incorporates:
   *  Constant: '<S103>/Constant1'
   *  Constant: '<S109>/Constant'
   *  Product: '<S109>/Product'
   *  Product: '<S109>/Product1'
   *  Sum: '<S109>/Subtract'
   *  UnitDelay: '<S109>/Unit Delay'
   */
  VfACCS_TargetDrsdLonAccel = (VfACCS_TargetDrsdLonAccel * (1.0F -
    KfACCS_k_DrsdAccelFilter)) + (rtb_UnitDelay_alis * KfACCS_k_DrsdAccelFilter);

  /* UnitDelay: '<S103>/Unit Delay1' */
  VfACCS_FinalDrsdAcceleration_old =
    ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_mixm;

  /* Outputs for Atomic SubSystem: '<S103>/DtrmnACCS_Acceleration_Ramp' */
  DtrmnACCS_Acceleration_Ramp();

  /* End of Outputs for SubSystem: '<S103>/DtrmnACCS_Acceleration_Ramp' */

  /* Switch: '<S103>/Switch4' incorporates:
   *  Constant: '<S103>/Constant10'
   *  Logic: '<S103>/Logical Operator2'
   */
  if (!KbACCS_EnblAccelerationRamp)
  {
    VfACCS_FinalDrsdAcceleration = VfACCS_TargetDrsdLonAccel;
  }
  else
  {
    VfACCS_FinalDrsdAcceleration = ACCS_subsystem_integrated_B.Switch;
  }

  /* End of Switch: '<S103>/Switch4' */

  /* Update for UnitDelay: '<S108>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_pniz = rtb_Sum_hia3;

  /* Update for UnitDelay: '<S103>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_mixm =
    ACCS_subsystem_integrated_B.Switch;
}

/* Output and update for atomic system: '<S104>/CalcACCS_FinalAccelReq' */
void CalcACCS_FinalAccelReq(void)
{
  boolean_T rtb_LogicalOperator2_cqax;
  real32_T tmp;

  /* Switch: '<S113>/Switch' incorporates:
   *  Constant: '<S113>/Constant'
   *  Constant: '<S113>/Constant3'
   *  Constant: '<S113>/Constant4'
   *  RelationalOperator: '<S113>/Relational Operator3'
   */
  if (KeACCS_OutPutControlSignal == ((uint8_T)0U))
  {
    tmp = ACCS_subsystem_integrate_ConstB.Sum2_mads;
  }
  else
  {
    tmp = 0.0F;
  }

  /* End of Switch: '<S113>/Switch' */

  /* Sum: '<S113>/Sum3' */
  VfACCS_Lon_Accleration = tmp + VfACCS_FinalDrsdAcceleration;

  /* RelationalOperator: '<S113>/Relational Operator1' incorporates:
   *  Constant: '<S113>/Constant8'
   */
  rtb_LogicalOperator2_cqax = (VeACCS_ModeState == ACCS_mode_on);

  /* Logic: '<S113>/Logical Operator1' incorporates:
   *  Constant: '<S113>/Constant7'
   *  RelationalOperator: '<S113>/Relational Operator'
   */
  VbACCS_Lon_Torq_Req = (rtb_LogicalOperator2_cqax && (VfACCS_Lon_Accleration >=
    KfACCS_a_AccelCmdDeadZone));

  /* Logic: '<S113>/Logical Operator2' incorporates:
   *  Constant: '<S113>/Constant5'
   *  RelationalOperator: '<S113>/Relational Operator2'
   */
  rtb_LogicalOperator2_cqax = (rtb_LogicalOperator2_cqax &&
    (VfACCS_Lon_Accleration <= KfACCS_a_BrakeCmdDeadZone));

  /* Logic: '<S113>/Logical Operator3' */
  VbACCS_Lon_Accleration_Req = (VbACCS_Lon_Torq_Req || rtb_LogicalOperator2_cqax);
}

/* Output and update for atomic system: '<S114>/DtrmnACCS_TorqCtrlProp' */
void DtrmnACCS_TorqCtrlProp(void)
{
  real32_T rtb_Subtract_klem;

  /* Sum: '<S123>/Subtract' */
  rtb_Subtract_klem = VfACCS_FinalDrsdAcceleration -
    ACCS_subsystem_integrated_B.VfACCS_Input_linear_Accele_p235;

  /* Product: '<S123>/Product' incorporates:
   *  Lookup_n-D: '<S123>/KtACCS_r_TorqCtrlProp '
   */
  ACCS_subsystem_integrated_B.Product_cgsn = rtb_Subtract_klem *
    look2_iflf_binlc(rtb_Subtract_klem,
                     ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG,
                     KtACCS_AXIS_TorqCtrlProp_DeltaAccel,
                     KtACCS_AXIS_TorqCtrlProp_EgoSpeed, KtACCS_r_TorqCtrlProp,
                     ACCS_subsystem_integrate_ConstP.KtACCS_r_TorqCtrlProp_maxIndex,
                     9U);
}

/* Output and update for atomic system: '<S104>/CalcACCS_FinalTorqReq' */
void CalcACCS_FinalTorqReq(void)
{
  real32_T rtb_Switch1;
  real32_T rtb_Product_fjhf;

  /* Switch: '<S114>/Switch1' incorporates:
   *  Constant: '<S114>/Constant'
   *  Constant: '<S114>/Constant3'
   *  Constant: '<S114>/Constant4'
   *  RelationalOperator: '<S114>/Relational Operator3'
   *  Sum: '<S114>/Sum1'
   *  Sum: '<S114>/Sum2'
   */
  if (KeACCS_OutPutControlSignal == ((uint8_T)1U))
  {
    /* Outputs for Atomic SubSystem: '<S114>/DtrmnACCS_TorqCtrlProp' */
    DtrmnACCS_TorqCtrlProp();

    /* End of Outputs for SubSystem: '<S114>/DtrmnACCS_TorqCtrlProp' */
    rtb_Switch1 = (ACCS_subsystem_integrated_B.Product_cgsn +
                   ACCS_subsystem_integrate_ConstB.Constant_gbpu) +
      ACCS_subsystem_integrate_ConstB.Constant_jgqb;
  }
  else
  {
    rtb_Switch1 = 0.0F;
  }

  /* End of Switch: '<S114>/Switch1' */

  /* Sum: '<S114>/Sum3' incorporates:
   *  Lookup_n-D: '<S114>/KtACCS_Pct_AccelToGasPedal '
   */
  VfACCS_Lon_Torq_Req = look2_iflf_binlc
    (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG,
     VfACCS_FinalDrsdAcceleration, KtACCS_AXIS_AccelToGasPedal_VehSpd,
     KtACCS_AXIS_AccelToGasPedal_Accel, KtACCS_Pct_AccelToGasPedal,
     ACCS_subsystem_integrate_ConstP.KtACCS_Pct_AccelToGasPedal_maxI, 10U) +
    rtb_Switch1;

  /* Product: '<S114>/Product' incorporates:
   *  Constant: '<S114>/Constant2'
   */
  rtb_Product_fjhf = VfACCS_Lon_Torq_Req * KfACCS_M_StandardTorqForPercent;
}

/* Output and update for atomic system: '<S15>/DtrmnACCS_ActuaorControl' */
void DtrmnACCS_ActuaorControl(void)
{
  /* Outputs for Atomic SubSystem: '<S104>/CalcACCS_FinalAccelReq' */
  CalcACCS_FinalAccelReq();

  /* End of Outputs for SubSystem: '<S104>/CalcACCS_FinalAccelReq' */

  /* Outputs for Atomic SubSystem: '<S104>/CalcACCS_FinalTorqReq' */
  CalcACCS_FinalTorqReq();

  /* End of Outputs for SubSystem: '<S104>/CalcACCS_FinalTorqReq' */
}

/* Output and update for atomic system: '<S105>/DtrmnACCS_RangeCtrlProp' */
void DtrmnACCS_RangeCtrlProp(void)
{
  /* Product: '<S129>/Product1' incorporates:
   *  Lookup_n-D: '<S129>/KtACCS_r_RangeCtrlPGain '
   */
  ACCS_subsystem_integrated_B.Product1 = look2_iflf_binlc
    (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG,
     ACCS_subsystem_integrated_B.VfACCS_RangeErrlim_SIPV,
     KtACCS_AXIS_RangeCtrlPGain_VehSpd, KtACCS_AXIS_RangeCtrlPGain_Err,
     KtACCS_r_RangeCtrlPGain, ACCS_subsystem_integrate_ConstP.pooled19, 10U) *
    ACCS_subsystem_integrated_B.VfACCS_RangeErrlim_SIPV;

  /* Product: '<S129>/Product' incorporates:
   *  Lookup_n-D: '<S129>/KtACCS_r_RangeCtrlPGain 1'
   */
  ACCS_subsystem_integrated_B.Product = look2_iflf_binlc
    (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG,
     ACCS_subsystem_integrated_B.VfACCS_RangeErrLim_CIPV,
     KtACCS_AXIS_RangeCtrlPGain_VehSpd, KtACCS_AXIS_RangeCtrlPGain_Err,
     KtACCS_r_RangeCtrlPGain, ACCS_subsystem_integrate_ConstP.pooled19, 10U) *
    ACCS_subsystem_integrated_B.VfACCS_RangeErrLim_CIPV;
}

/* Output and update for atomic system: '<S15>/DtrmnACCS_RangeCtrlPID' */
void DtrmnACCS_RangeCtrlPID(void)
{
  real32_T rtb_Subtract_hm0r;
  real32_T rtb_Subtract1;
  real32_T rtb_Switch_mdyi_idx_1;
  real32_T u0;

  /* Switch: '<S105>/Switch' incorporates:
   *  Constant: '<S105>/Constant'
   *  Constant: '<S105>/Constant6'
   *  RelationalOperator: '<S105>/Relational Operator'
   *  Sum: '<S105>/Sum2'
   */
  if (VeACCS_RunStatus == ACCS_status_SpeedCtrl)
  {
    /* SignalConversion: '<S105>/Signal Conversion' incorporates:
     *  Constant: '<S105>/Constant5'
     */
    VfACCS_RangCtrCL_CIPV = 0.0F;
    rtb_Switch_mdyi_idx_1 = 0.0F;
  }
  else
  {
    /* Outputs for Atomic SubSystem: '<S105>/DtrmnACCS_RangeCtrlProp' */
    DtrmnACCS_RangeCtrlProp();

    /* End of Outputs for SubSystem: '<S105>/DtrmnACCS_RangeCtrlProp' */

    /* SignalConversion: '<S105>/Signal Conversion' incorporates:
     *  Sum: '<S105>/Sum'
     *  Sum: '<S105>/Sum1'
     */
    VfACCS_RangCtrCL_CIPV = (ACCS_subsystem_integrated_B.Product +
      ACCS_subsystem_integrate_ConstB.Constant_g2bl) +
      ACCS_subsystem_integrate_ConstB.Constant_jk02;
    rtb_Switch_mdyi_idx_1 = ACCS_subsystem_integrate_ConstB.Sum3 +
      ACCS_subsystem_integrated_B.Product1;
  }

  /* End of Switch: '<S105>/Switch' */

  /* Sum: '<S105>/Subtract' */
  rtb_Subtract_hm0r = VfACCS_VehSpeed_Tar -
    ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG;

  /* Sum: '<S105>/Subtract1' */
  rtb_Subtract1 = VfACCS_FinalSpeedLimit -
    ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG;

  /* Switch: '<S105>/Switch1' incorporates:
   *  Constant: '<S105>/Constant1'
   *  RelationalOperator: '<S105>/Relational Operator1'
   *  Sum: '<S105>/Sum4'
   */
  if (((real_T)rtb_Subtract1) > 0.0)
  {
    /* Sum: '<S105>/Sum4' */
    u0 = VfACCS_RangCtrCL_CIPV + rtb_Subtract_hm0r;

    /* MinMax: '<S105>/MinMax' incorporates:
     *  Sum: '<S105>/Sum4'
     */
    if (u0 < rtb_Subtract1)
    {
      ACCS_subsystem_integrated_B.Switch = u0;
    }
    else
    {
      ACCS_subsystem_integrated_B.Switch = rtb_Subtract1;
    }

    /* End of MinMax: '<S105>/MinMax' */
  }
  else
  {
    ACCS_subsystem_integrated_B.Switch = VfACCS_RangCtrCL_CIPV +
      rtb_Subtract_hm0r;
  }

  /* End of Switch: '<S105>/Switch1' */

  /* Sum: '<S105>/Sum5' */
  ACCS_subsystem_integrated_B.Product_cjbq = rtb_Subtract_hm0r +
    rtb_Switch_mdyi_idx_1;
}

/* Output and update for atomic system: '<S106>/DtrmnACCS_SpeedCtrlProp' */
void DtrmnACCS_SpeedCtrlProp(void)
{
  /* Product: '<S132>/Product1' incorporates:
   *  Lookup_n-D: '<S132>/KtACCS_r_SpeedCtrlPGain'
   */
  ACCS_subsystem_integrated_B.Switch *= look2_iflf_binlc
    (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG,
     ACCS_subsystem_integrated_B.Switch, KtACCS_AXIS_RangeCtrlPGain_VehSpd,
     KtACCS_AXIS_SpeedCtrlPGain_Err, KtACCS_r_SpeedCtrlPGain,
     ACCS_subsystem_integrate_ConstP.pooled19, 10U);

  /* Product: '<S132>/Product' incorporates:
   *  Lookup_n-D: '<S132>/KtACCS_r_SpeedCtrlPGain1'
   */
  ACCS_subsystem_integrated_B.Product_cjbq = look2_iflf_binlc
    (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG,
     VfACCS_SpdErrLim_CIPV, KtACCS_AXIS_RangeCtrlPGain_VehSpd,
     KtACCS_AXIS_SpeedCtrlPGain_Err, KtACCS_r_SpeedCtrlPGain,
     ACCS_subsystem_integrate_ConstP.pooled19, 10U) * VfACCS_SpdErrLim_CIPV;
}

/* Output and update for atomic system: '<S15>/DtrmnACCS_SpeedCtrlPID' */
void DtrmnACCS_SpeedCtrlPID(void)
{
  real32_T rtb_VfACCS_DrsdAccelFrmRngSped_;
  real32_T rtb_fACCS_DrsdAccelFrmRngSped_C;

  /* MinMax: '<S106>/Min' incorporates:
   *  Constant: '<S106>/Constant1'
   */
  if (ACCS_subsystem_integrated_B.Switch < KfACCS_v_SpdPIDCtrl_SpdErrlimit)
  {
    rtb_fACCS_DrsdAccelFrmRngSped_C = ACCS_subsystem_integrated_B.Switch;
  }
  else
  {
    rtb_fACCS_DrsdAccelFrmRngSped_C = KfACCS_v_SpdPIDCtrl_SpdErrlimit;
  }

  /* End of MinMax: '<S106>/Min' */

  /* Product: '<S106>/Product' incorporates:
   *  Constant: '<S106>/Constant1'
   *  Constant: '<S106>/Constant2'
   *  Product: '<S106>/Product1'
   */
  rtb_VfACCS_DrsdAccelFrmRngSped_ = KfACCS_v_SpdPIDCtrl_SpdErrlimit * (-1.0F);

  /* MinMax: '<S106>/max' incorporates:
   *  Product: '<S106>/Product'
   */
  if (rtb_fACCS_DrsdAccelFrmRngSped_C > rtb_VfACCS_DrsdAccelFrmRngSped_)
  {
    VfACCS_SpdErrLim_CIPV = rtb_fACCS_DrsdAccelFrmRngSped_C;
  }
  else
  {
    VfACCS_SpdErrLim_CIPV = rtb_VfACCS_DrsdAccelFrmRngSped_;
  }

  /* End of MinMax: '<S106>/max' */

  /* MinMax: '<S106>/Min1' incorporates:
   *  Constant: '<S106>/Constant3'
   */
  if (ACCS_subsystem_integrated_B.Product_cjbq < KfACCS_v_SpdPIDCtrl_SpdErrlimit)
  {
    rtb_fACCS_DrsdAccelFrmRngSped_C = ACCS_subsystem_integrated_B.Product_cjbq;
  }
  else
  {
    rtb_fACCS_DrsdAccelFrmRngSped_C = KfACCS_v_SpdPIDCtrl_SpdErrlimit;
  }

  /* End of MinMax: '<S106>/Min1' */

  /* MinMax: '<S106>/max1' */
  if (rtb_fACCS_DrsdAccelFrmRngSped_C > rtb_VfACCS_DrsdAccelFrmRngSped_)
  {
    ACCS_subsystem_integrated_B.Switch = rtb_fACCS_DrsdAccelFrmRngSped_C;
  }
  else
  {
    ACCS_subsystem_integrated_B.Switch = rtb_VfACCS_DrsdAccelFrmRngSped_;
  }

  /* End of MinMax: '<S106>/max1' */

  /* Outputs for Atomic SubSystem: '<S106>/DtrmnACCS_SpeedCtrlProp' */
  DtrmnACCS_SpeedCtrlProp();

  /* End of Outputs for SubSystem: '<S106>/DtrmnACCS_SpeedCtrlProp' */

  /* Sum: '<S106>/Sum1' incorporates:
   *  Sum: '<S106>/Sum'
   */
  rtb_fACCS_DrsdAccelFrmRngSped_C = (ACCS_subsystem_integrated_B.Product_cjbq +
    ACCS_subsystem_integrate_ConstB.Constant) +
    ACCS_subsystem_integrate_ConstB.Constant_fh1v;

  /* Sum: '<S106>/Sum3' */
  rtb_VfACCS_DrsdAccelFrmRngSped_ = ACCS_subsystem_integrate_ConstB.Sum2 +
    ACCS_subsystem_integrated_B.Switch;

  /* Switch: '<S106>/Switch' incorporates:
   *  Constant: '<S106>/Constant'
   *  Logic: '<S106>/Logical Operator'
   */
  if (KbACCS_ConsiderSIPVforACC &&
      (ACCS_subsystem_integrated_B.SignalConversion1))
  {
    /* MinMax: '<S106>/Min2' */
    if (rtb_VfACCS_DrsdAccelFrmRngSped_ < rtb_fACCS_DrsdAccelFrmRngSped_C)
    {
      VfACCS_DrsdAccelFrmRngSped = rtb_VfACCS_DrsdAccelFrmRngSped_;
    }
    else
    {
      VfACCS_DrsdAccelFrmRngSped = rtb_fACCS_DrsdAccelFrmRngSped_C;
    }

    /* End of MinMax: '<S106>/Min2' */
  }
  else
  {
    VfACCS_DrsdAccelFrmRngSped = rtb_fACCS_DrsdAccelFrmRngSped_C;
  }

  /* End of Switch: '<S106>/Switch' */
}

/* Output and update for atomic system: '<S4>/DtrmnACCS_Lon_AccelOrTorq' */
void DtrmnACCS_Lon_AccelOrTorq(void)
{
  /* Outputs for Atomic SubSystem: '<S15>/DtrmnACCS_RangeCtrlPID' */
  DtrmnACCS_RangeCtrlPID();

  /* End of Outputs for SubSystem: '<S15>/DtrmnACCS_RangeCtrlPID' */

  /* Outputs for Atomic SubSystem: '<S15>/DtrmnACCS_SpeedCtrlPID' */
  DtrmnACCS_SpeedCtrlPID();

  /* End of Outputs for SubSystem: '<S15>/DtrmnACCS_SpeedCtrlPID' */

  /* Outputs for Atomic SubSystem: '<S15>/ClacACCS_DsrdLonAccel' */
  ClacACCS_DsrdLonAccel();

  /* End of Outputs for SubSystem: '<S15>/ClacACCS_DsrdLonAccel' */

  /* Outputs for Atomic SubSystem: '<S15>/DtrmnACCS_ActuaorControl' */
  DtrmnACCS_ActuaorControl();

  /* End of Outputs for SubSystem: '<S15>/DtrmnACCS_ActuaorControl' */
}

/* System initialize for atomic system: '<S16>/DtrmnACCS_FaultState' */
void DtrmnACCS_FaultState_Init(void)
{
  /* SystemInitialize for Merge: '<S136>/Merge' */
  ACCS_subsystem_integrated_B.Merge = NoEnterFault;
}

/* Output and update for atomic system: '<S16>/DtrmnACCS_FaultState' */
void DtrmnACCS_FaultState(void)
{
  /* If: '<S136>/If' incorporates:
   *  Constant: '<S136>/Constant2'
   *  Constant: '<S136>/Constant3'
   *  Constant: '<S136>/Constant4'
   *  Constant: '<S136>/Constant5'
   *  Constant: '<S136>/Constant6'
   *  Constant: '<S136>/Constant7'
   *  Constant: '<S136>/Constant8'
   *  Constant: '<S136>/Constant9'
   *  RelationalOperator: '<S136>/Relational Operator2'
   *  RelationalOperator: '<S136>/Relational Operator3'
   *  RelationalOperator: '<S136>/Relational Operator4'
   *  RelationalOperator: '<S136>/Relational Operator5'
   *  RelationalOperator: '<S136>/Relational Operator6'
   *  RelationalOperator: '<S136>/Relational Operator7'
   *  RelationalOperator: '<S136>/Relational Operator8'
   *  RelationalOperator: '<S136>/Relational Operator9'
   */
  if (VeACCS_RunStatusBeforeFault == ACCS_status_on)
  {
    /* Outputs for IfAction SubSystem: '<S136>/If Action Subsystem' incorporates:
     *  ActionPort: '<S139>/Action Port'
     */
    /* SignalConversion: '<S139>/OutportBufferForVeACCS_FaultState' incorporates:
     *  Constant: '<S139>/Constant1'
     */
    ACCS_subsystem_integrated_B.Merge = FromStatusOnToFault;

    /* End of Outputs for SubSystem: '<S136>/If Action Subsystem' */
  }
  else if (VeACCS_RunStatusBeforeFault == ACCS_status_SpeedCtrl)
  {
    /* Outputs for IfAction SubSystem: '<S136>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S140>/Action Port'
     */
    /* SignalConversion: '<S140>/OutportBufferForVeACCS_FaultState' incorporates:
     *  Constant: '<S140>/Constant1'
     */
    ACCS_subsystem_integrated_B.Merge = FromSpeedCtrlToFault;

    /* End of Outputs for SubSystem: '<S136>/If Action Subsystem1' */
  }
  else if (VeACCS_RunStatusBeforeFault == ACCS_status_FollowingCtrl)
  {
    /* Outputs for IfAction SubSystem: '<S136>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    /* SignalConversion: '<S141>/OutportBufferForVeACCS_FaultState' incorporates:
     *  Constant: '<S141>/Constant1'
     */
    ACCS_subsystem_integrated_B.Merge = FromFollowingCtrlToFault;

    /* End of Outputs for SubSystem: '<S136>/If Action Subsystem2' */
  }
  else if (VeACCS_RunStatusBeforeFault == ACCS_status_LowSpeed)
  {
    /* Outputs for IfAction SubSystem: '<S136>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S142>/Action Port'
     */
    /* SignalConversion: '<S142>/OutportBufferForVeACCS_FaultState' incorporates:
     *  Constant: '<S142>/Constant1'
     */
    ACCS_subsystem_integrated_B.Merge = FromLowSpeedToFault;

    /* End of Outputs for SubSystem: '<S136>/If Action Subsystem3' */
  }
  else if (VeACCS_RunStatusBeforeFault == ACCS_status_TempStop)
  {
    /* Outputs for IfAction SubSystem: '<S136>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    /* SignalConversion: '<S143>/OutportBufferForVeACCS_FaultState' incorporates:
     *  Constant: '<S143>/Constant1'
     */
    ACCS_subsystem_integrated_B.Merge = FromTempStopToFault;

    /* End of Outputs for SubSystem: '<S136>/If Action Subsystem4' */
  }
  else if (VeACCS_RunStatusBeforeFault == ACCS_status_Stop)
  {
    /* Outputs for IfAction SubSystem: '<S136>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S144>/Action Port'
     */
    /* SignalConversion: '<S144>/OutportBufferForVeACCS_FaultState' incorporates:
     *  Constant: '<S144>/Constant1'
     */
    ACCS_subsystem_integrated_B.Merge = FromStopToFault;

    /* End of Outputs for SubSystem: '<S136>/If Action Subsystem5' */
  }
  else if (VeACCS_RunStatusBeforeFault == ACCS_status_Launch)
  {
    /* Outputs for IfAction SubSystem: '<S136>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S145>/Action Port'
     */
    /* SignalConversion: '<S145>/OutportBufferForVeACCS_FaultState' incorporates:
     *  Constant: '<S145>/Constant1'
     */
    ACCS_subsystem_integrated_B.Merge = FromLaunchToFault;

    /* End of Outputs for SubSystem: '<S136>/If Action Subsystem6' */
  }
  else
  {
    if (VeACCS_RunStatusBeforeFault == ACCS_status_Standby)
    {
      /* Outputs for IfAction SubSystem: '<S136>/If Action Subsystem8' incorporates:
       *  ActionPort: '<S146>/Action Port'
       */
      /* SignalConversion: '<S146>/OutportBufferForVeACCS_FaultState' incorporates:
       *  Constant: '<S146>/Constant1'
       */
      ACCS_subsystem_integrated_B.Merge = FromStandbyToFault;

      /* End of Outputs for SubSystem: '<S136>/If Action Subsystem8' */
    }
  }

  /* End of If: '<S136>/If' */

  /* Switch: '<S136>/Switch' incorporates:
   *  Constant: '<S136>/Constant1'
   *  Constant: '<S136>/Constant10'
   *  RelationalOperator: '<S136>/Relational Operator1'
   */
  if (VeACCS_ModeState == ACCS_mode_fault)
  {
    VeACCS_FaultState = ACCS_subsystem_integrated_B.Merge;
  }
  else
  {
    VeACCS_FaultState = NoEnterFault;
  }

  /* End of Switch: '<S136>/Switch' */
}

/* System initialize for atomic system: '<S137>/DtrmnACCS_ModeStateTransfer' */
void DtrmnACCS_ModeStateTransfer_Init(void)
{
  ACCS_subsystem_integrated_DW.is_active_c1_ACCS_subsystem_int = 0U;
  ACCS_subsystem_integrated_DW.is_c1_ACCS_subsystem_integrated =
    ACCS_su_IN_NO_ACTIVE_CHILD_b1sk;
}

/* Output and update for atomic system: '<S137>/DtrmnACCS_ModeStateTransfer' */
void DtrmnACCS_ModeStateTransfer(void)
{
  boolean_T guard1 = false;

  /* Chart: '<S137>/DtrmnACCS_ModeStateTransfer' */
  if (((uint32_T)ACCS_subsystem_integrated_DW.is_active_c1_ACCS_subsystem_int) ==
      0U)
  {
    ACCS_subsystem_integrated_DW.is_active_c1_ACCS_subsystem_int = 1U;
    ACCS_subsystem_integrated_DW.is_c1_ACCS_subsystem_integrated =
      ACCS_subsystem_IN_ACCS_Mode_off;
    VeACCS_ModeState = ACCS_mode_off;
    VeACCS_RunStatusFrmMode = ACCS_status_off;
    VeACCS_RunStatusBeforeFault = ACCS_status_off;
    VeACCS_EnterStandbyState = NoEnterStandby;
  }
  else
  {
    guard1 = false;
    switch (ACCS_subsystem_integrated_DW.is_c1_ACCS_subsystem_integrated)
    {
     case ACCS_subsyst_IN_ACCS_Mode_fault:
      VeACCS_ModeState = ACCS_mode_fault;
      if (!VbACCS_MainSwitch)
      {
        ACCS_subsystem_integrated_DW.is_c1_ACCS_subsystem_integrated =
          ACCS_subsystem_IN_ACCS_Mode_off;
        VeACCS_ModeState = ACCS_mode_off;
        VeACCS_RunStatusFrmMode = ACCS_status_off;
        VeACCS_RunStatusBeforeFault = ACCS_status_off;
        VeACCS_EnterStandbyState = NoEnterStandby;
      }
      else
      {
        if (!ACCS_subsystem_integrated_B.LogicalOperator)
        {
          VeACCS_EnterStandbyState = FromFaultToStandby;
          ACCS_subsystem_integrated_DW.is_c1_ACCS_subsystem_integrated =
            ACCS_subsy_IN_ACCS_Mode_standby;
          VeACCS_ModeState = ACCS_mode_standby;
          VeACCS_RunStatusFrmMode = ACCS_status_Standby;
        }
      }
      break;

     case ACCS_subsystem_IN_ACCS_Mode_off:
      VeACCS_ModeState = ACCS_mode_off;
      if (VbACCS_MainSwitch)
      {
        VeACCS_EnterStandbyState = FromModeOffToStandby;
        ACCS_subsystem_integrated_DW.is_c1_ACCS_subsystem_integrated =
          ACCS_subsy_IN_ACCS_Mode_standby;
        VeACCS_ModeState = ACCS_mode_standby;
        VeACCS_RunStatusFrmMode = ACCS_status_Standby;
      }
      break;

     case ACCS_subsystem__IN_ACCS_Mode_on:
      VeACCS_ModeState = ACCS_mode_on;
      if (!VbACCS_MainSwitch)
      {
        ACCS_subsystem_integrated_DW.is_c1_ACCS_subsystem_integrated =
          ACCS_subsystem_IN_ACCS_Mode_off;
        VeACCS_ModeState = ACCS_mode_off;
        VeACCS_RunStatusFrmMode = ACCS_status_off;
        VeACCS_RunStatusBeforeFault = ACCS_status_off;
        VeACCS_EnterStandbyState = NoEnterStandby;
      }
      else if (ACCS_subsystem_integrated_B.LogicalOperator)
      {
        ACCS_subsystem_integrated_DW.is_c1_ACCS_subsystem_integrated =
          ACCS_subsyst_IN_ACCS_Mode_fault;
        VeACCS_EnterStandbyState = NoEnterStandby;
        VeACCS_ModeState = ACCS_mode_fault;
        VeACCS_RunStatusFrmMode = ACCS_status_Fault;
        VeACCS_RunStatusBeforeFault = ACCS_subsystem_integrated_B.UnitDelay;
      }
      else if (ACCS_subsystem_integrated_B.Switch4)
      {
        VeACCS_EnterStandbyState = PressCancelSwitch;
        guard1 = true;
      }
      else if (((uint32_T)ACCS_subsystem_integrated_B.UnitDelay1_e3kh) !=
               NoEnterStandby)
      {
        VeACCS_EnterStandbyState = ACCS_subsystem_integrated_B.UnitDelay1_e3kh;
        guard1 = true;
      }
      else
      {
        VeACCS_RunStatusFrmMode = ACCS_subsystem_integrated_B.UnitDelay;
      }
      break;

     default:
      VeACCS_ModeState = ACCS_mode_standby;
      if (!VbACCS_MainSwitch)
      {
        ACCS_subsystem_integrated_DW.is_c1_ACCS_subsystem_integrated =
          ACCS_subsystem_IN_ACCS_Mode_off;
        VeACCS_ModeState = ACCS_mode_off;
        VeACCS_RunStatusFrmMode = ACCS_status_off;
        VeACCS_RunStatusBeforeFault = ACCS_status_off;
        VeACCS_EnterStandbyState = NoEnterStandby;
      }
      else if (VbACCS_ExitStandbyToOn)
      {
        ACCS_subsystem_integrated_DW.is_c1_ACCS_subsystem_integrated =
          ACCS_subsystem__IN_ACCS_Mode_on;
        VeACCS_EnterStandbyState = NoEnterStandby;
        VeACCS_ModeState = ACCS_mode_on;
        VeACCS_RunStatusFrmMode = ACCS_status_on;
      }
      else
      {
        if (ACCS_subsystem_integrated_B.LogicalOperator)
        {
          ACCS_subsystem_integrated_DW.is_c1_ACCS_subsystem_integrated =
            ACCS_subsyst_IN_ACCS_Mode_fault;
          VeACCS_EnterStandbyState = NoEnterStandby;
          VeACCS_ModeState = ACCS_mode_fault;
          VeACCS_RunStatusFrmMode = ACCS_status_Fault;
          VeACCS_RunStatusBeforeFault = ACCS_subsystem_integrated_B.UnitDelay;
        }
      }
      break;
    }

    if (guard1)
    {
      ACCS_subsystem_integrated_DW.is_c1_ACCS_subsystem_integrated =
        ACCS_subsy_IN_ACCS_Mode_standby;
      VeACCS_ModeState = ACCS_mode_standby;
      VeACCS_RunStatusFrmMode = ACCS_status_Standby;
    }
  }

  /* End of Chart: '<S137>/DtrmnACCS_ModeStateTransfer' */
}

/* Output and update for atomic system: '<S137>/DtrmnACCS_ModeTransferConds' */
void DtrmnACCS_ModeTransferConds(void)
{
  boolean_T rtb_Switch_pd52_idx_0;
  boolean_T rtb_Switch_pd52_idx_1;
  boolean_T rtb_Switch_pd52_idx_2;
  real32_T tmp;

  /* SignalConversion: '<S148>/Signal Conversion4' */
  VbACCS_ResumeSwitch = ACCS_subsystem_integrated_B.SignalConversion_a213;

  /* UnitDelay: '<S148>/Unit Delay' */
  VbACCS_ResumeSwitchOld = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_dtsz;

  /* Logic: '<S148>/Logical Operator7' incorporates:
   *  Constant: '<S148>/Constant23'
   *  Constant: '<S148>/Constant45'
   *  RelationalOperator: '<S148>/Relational Operator30'
   */
  VbACCS_GearPositionIsD = ((ACCS_subsystem_integrated_B.VeACCS_Input_Gear_TCU ==
    KeACCS_GearDriveNum) || KbACCS_ConsiderWithoutGear);

  /* Logic: '<S148>/Logical Operator1' incorporates:
   *  Constant: '<S148>/Constant46'
   *  Constant: '<S148>/Constant48'
   *  RelationalOperator: '<S148>/Relational Operator31'
   *  RelationalOperator: '<S148>/Relational Operator38'
   */
  VbACCS_SpeedOutRange = ((KfACCS_v_EnableACCLoSpdThrsh >=
    ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG) &&
    (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG >=
     KfACCS_v_EnableACCHiSpdThrsh));

  /* RelationalOperator: '<S148>/Relational Operator32' incorporates:
   *  Constant: '<S148>/Constant47'
   */
  VbACCS_DriverModeAllowACCS =
    (ACCS_subsystem_integrate_ConstB.VeACCS_Input_DrivermodeDisa ==
     KeACCS_DriverMode_AllowACCSNum);

  /* Switch: '<S148>/Switch4' incorporates:
   *  Constant: '<S148>/Constant24'
   *  Constant: '<S148>/Constant25'
   */
  if (KbACCS_DirectlyUsePedalToJudgeOverride)
  {
    tmp = KfACCS_Pct_GasPedalOverrideThrsh;
  }
  else
  {
    tmp = ACCS_subsystem_integrated_B.Switch;
  }

  /* End of Switch: '<S148>/Switch4' */

  /* Logic: '<S148>/Logical Operator8' incorporates:
   *  Constant: '<S148>/Constant4'
   *  RelationalOperator: '<S148>/Relational Operator2'
   *  RelationalOperator: '<S148>/Relational Operator33'
   */
  VbACCS_DriverGasPedalOverride =
    ((ACCS_subsystem_integrated_B.VfACCS_RangeErrLim_CIPV > tmp) &&
     (ACCS_subsystem_integrated_B.VeACCS_Input_autodrive_activate != ((uint8_T)
       0U)));

  /* SignalConversion: '<S148>/Signal Conversion3' */
  VbACCS_EgoLimit = ACCS_subsystem_integrated_B.Ego_LimitCondition;

  /* Logic: '<S148>/Logical Operator4' incorporates:
   *  Constant: '<S148>/Constant19'
   *  Constant: '<S148>/Constant22'
   *  Logic: '<S148>/Logical Operator23'
   *  Logic: '<S148>/Logical Operator25'
   *  Logic: '<S148>/Logical Operator27'
   *  Logic: '<S148>/Logical Operator28'
   *  Logic: '<S148>/Logical Operator3'
   *  Logic: '<S148>/Logical Operator32'
   *  Logic: '<S148>/Logical Operator35'
   *  RelationalOperator: '<S148>/Relational Operator6'
   */
  VbACCS_ExitStandbyCommonConds = ((((((((((VbACCS_GearPositionIsD &&
    (!VbACCS_SpeedOutRange)) &&
    (ACCS_subsystem_integrated_B.VbACCS_Input_DriverPresent)) &&
    VbACCS_DriverModeAllowACCS) && (!VbACCS_DriverGasPedalOverride)) &&
    (!VbACCS_BrakePedalPress)) && (!VbACCS_EPB_Engaged)) && (!VbACCS_AEB_Active))
    && (!VbACCS_EgoLimit)) &&
    (ACCS_subsystem_integrated_B.VeACCS_Input_autodrive_activate != ((uint8_T)0U)))
    || KbACCS_ForceExitStandby);

  /* Switch: '<S148>/Switch3' incorporates:
   *  Constant: '<S148>/Constant16'
   *  Constant: '<S148>/Constant17'
   *  Constant: '<S148>/Constant8'
   *  Constant: '<S148>/Constant9'
   *  RelationalOperator: '<S148>/Relational Operator3'
   */
  if (ACCS_subsystem_integrated_B.UnitDelay2 == ACCS_mode_standby)
  {
    /* Switch: '<S148>/Switch1' incorporates:
     *  Constant: '<S148>/Constant1'
     *  Constant: '<S148>/Constant2'
     *  Constant: '<S148>/Constant3'
     */
    if (VbACCS_ExitStandbyCommonConds)
    {
      /* Switch: '<S148>/Switch' incorporates:
       *  Constant: '<S148>/Constant'
       *  Constant: '<S148>/Constant5'
       *  Constant: '<S148>/Constant6'
       *  Constant: '<S148>/Constant7'
       *  RelationalOperator: '<S148>/Relational Operator'
       */
      if (ACCS_subsystem_integrated_B.UnitDelay1_iozd == DriverGasPedalOverride)
      {
        rtb_Switch_pd52_idx_0 = true;
        rtb_Switch_pd52_idx_1 = false;
        rtb_Switch_pd52_idx_2 = false;
      }
      else
      {
        /* Logic: '<S148>/Logical Operator2' incorporates:
         *  Constant: '<S148>/Constant18'
         *  RelationalOperator: '<S148>/Relational Operator1'
         */
        rtb_Switch_pd52_idx_2 = ((VbACCS_ResumeSwitch != VbACCS_ResumeSwitchOld)
          || KbACCS_ForceExitStandby);

        /* Switch: '<S148>/Switch2' incorporates:
         *  Constant: '<S148>/Constant10'
         *  Constant: '<S148>/Constant11'
         *  Constant: '<S148>/Constant12'
         *  Constant: '<S148>/Constant13'
         *  Constant: '<S148>/Constant14'
         *  Constant: '<S148>/Constant15'
         */
        if (rtb_Switch_pd52_idx_2)
        {
          rtb_Switch_pd52_idx_0 = true;
        }
        else
        {
          rtb_Switch_pd52_idx_0 = false;
        }

        if (rtb_Switch_pd52_idx_2)
        {
          rtb_Switch_pd52_idx_1 = false;
        }
        else
        {
          rtb_Switch_pd52_idx_1 = true;
        }

        if (rtb_Switch_pd52_idx_2)
        {
          rtb_Switch_pd52_idx_2 = false;
        }
        else
        {
          rtb_Switch_pd52_idx_2 = true;
        }

        /* End of Switch: '<S148>/Switch2' */
      }

      /* End of Switch: '<S148>/Switch' */
    }
    else
    {
      rtb_Switch_pd52_idx_0 = false;
      rtb_Switch_pd52_idx_1 = false;
      rtb_Switch_pd52_idx_2 = false;
    }

    /* End of Switch: '<S148>/Switch1' */
  }
  else
  {
    rtb_Switch_pd52_idx_0 = true;
    rtb_Switch_pd52_idx_1 = false;
    rtb_Switch_pd52_idx_2 = false;
  }

  /* End of Switch: '<S148>/Switch3' */

  /* Logic: '<S148>/Logical Operator6' incorporates:
   *  Constant: '<S148>/Constant20'
   *  Constant: '<S148>/Constant21'
   *  Constant: '<S148>/Constant40'
   *  Logic: '<S148>/Logical Operator'
   *  Logic: '<S148>/Logical Operator5'
   *  RelationalOperator: '<S148>/Relational Operator4'
   *  RelationalOperator: '<S148>/Relational Operator5'
   *  SignalConversion: '<S148>/Signal Conversion2'
   *  UnitDelay: '<S148>/Unit Delay1'
   */
  VbACCS_ExitStandbyToOn = (((VbACCS_ExitStandbyCommonConds && ((((uint8_T)1U) ==
    ACCS_subsystem_integrated_B.VeACCS_Input_autodrive_activate) &&
    (ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_hhs3 == ((uint8_T)0U)))) ||
    KbACCS_NotAllowEnterStandbyForUSDemo) || rtb_Switch_pd52_idx_0);

  /* SignalConversion: '<S148>/Signal Conversion' */
  ACCS_subsystem_integrated_B.SignalConversion = rtb_Switch_pd52_idx_1;

  /* SignalConversion: '<S148>/Signal Conversion1' */
  ACCS_subsystem_integrated_B.SignalConversion1_dk4z = rtb_Switch_pd52_idx_2;

  /* Update for UnitDelay: '<S148>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_dtsz = VbACCS_ResumeSwitch;

  /* Update for UnitDelay: '<S148>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_hhs3 =
    ACCS_subsystem_integrated_B.VeACCS_Input_autodrive_activate;
}

/* System initialize for atomic system: '<S16>/DtrmnACCS_ModeState' */
void DtrmnACCS_ModeState_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S137>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_nivv = ACCS_mode_standby;

  /* SystemInitialize for Chart: '<S137>/DtrmnACCS_ModeStateTransfer' */
  DtrmnACCS_ModeStateTransfer_Init();
}

/* Output and update for atomic system: '<S16>/DtrmnACCS_ModeState' */
void DtrmnACCS_ModeState(void)
{
  /* UnitDelay: '<S137>/Unit Delay1' */
  ACCS_subsystem_integrated_B.UnitDelay1_iozd =
    ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_cjbc;

  /* UnitDelay: '<S137>/Unit Delay2' */
  ACCS_subsystem_integrated_B.UnitDelay2 =
    ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_nivv;

  /* Outputs for Atomic SubSystem: '<S137>/DtrmnACCS_ModeTransferConds' */
  DtrmnACCS_ModeTransferConds();

  /* End of Outputs for SubSystem: '<S137>/DtrmnACCS_ModeTransferConds' */

  /* Chart: '<S137>/DtrmnACCS_ModeStateTransfer' */
  DtrmnACCS_ModeStateTransfer();

  /* Update for UnitDelay: '<S137>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_cjbc = VeACCS_EnterStandbyState;

  /* Update for UnitDelay: '<S137>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE_nivv = VeACCS_ModeState;
}

/* Function for Chart: '<S138>/DtrmnACCS_RunStatusTransfer' */
static void ACCS_su_ACCS_Runstatus_TempStop(void)
{
  ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_TempStop;
  if (((ACCS_subsystem_integrated_DW.VfACCS_TempStopTimer >
        KfACCS_t_TempStpToStpDelay) || VbACCS_BrakePedalPress) ||
      VbACCS_EnterStopDueToCIP)
  {
    VbACCS_TempStpToStop = true;
    ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
      FromTempStopToStop;
    ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
      ACCS_sub_IN_ACCS_Runstatus_Stop;
    ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_Stop;
    VfACCS_StopTimer = ACCS_subsystem_integrated_DW.VfACCS_TempStopTimer;
    ACCS_subsystem_integrated_DW.VfACCS_TempStopTimer = 0.0F;
    ACCS_subsystem_integrated_B.VbACCS_InformDriverPressGasPeda = false;
    ACCS_subsystem_integrated_B.VbACCS_InformDriverPressResumeE = false;
    ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif = NoEnterStandby;
  }
  else if (VbACCS_TempStopToLaunch)
  {
    ACCS_subsystem_integrated_DW.VfACCS_TempStopTimer = 0.0F;
    ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
      FromTempStopToLaunch;
    ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
      ACCS_s_IN_ACCS_Runstatus_Launch;
    ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_Launch;
    ACCS_subsystem_integrated_DW.VfACCS_LaunchTimer = 0.0F;
    ACCS_subsystem_integrated_DW.VfACCS_LaunchLowSpdTimer = 0.0F;
    ACCS_subsystem_integrated_DW.VfACCS_LaunchStopTimer = 0.0F;
    ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif = NoEnterStandby;
  }
  else
  {
    ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 = NoTransfer;
    if (VbACCS_DriverGasPedalOverride)
    {
      ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
        DriverGasPedalOverride;
    }
    else
    {
      if (VbACCS_EnterStandbyCommonCod)
      {
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          FromTempStopToStandby;
      }
    }

    ACCS_subsystem_integrated_DW.VfACCS_TempStopTimer += 0.01F;
  }
}

/* Function for Chart: '<S138>/DtrmnACCS_RunStatusTransfer' */
static void ACCS_s_ACCS_ModeAndRunStatus_on(void)
{
  boolean_T tmp;
  if (((uint32_T)ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif) !=
      NoEnterStandby)
  {
    switch (ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on)
    {
     case ACCS_s_IN_ACCS_Runstatus_Launch:
      ACCS_subsystem_integrated_DW.VfACCS_LaunchTimer = 0.0F;
      ACCS_subsystem_integrated_DW.VfACCS_LaunchLowSpdTimer = 0.0F;
      ACCS_subsystem_integrated_DW.VfACCS_LaunchStopTimer = 0.0F;
      ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
        ACCS_su_IN_NO_ACTIVE_CHILD_kuby;
      break;

     case ACCS_IN_ACCS_Runstatus_TempStop:
      ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
        ACCS_su_IN_NO_ACTIVE_CHILD_kuby;
      break;

     default:
      ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
        ACCS_su_IN_NO_ACTIVE_CHILD_kuby;
      break;
    }

    ACCS_subsystem_integrated_DW.is_c4_ACCS_subsystem_integrated =
      ACCS__IN_ACCS_Runstatus_Standby;
    ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_Standby;
  }
  else
  {
    switch (ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on)
    {
     case IN_ACCS_Runstatus_FollowingCtrl:
      ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu =
        ACCS_status_FollowingCtrl;
      if (VbACCS_FollowingToSpeedCtrl)
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromFollowingToSpeedCtrl;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          ACC_IN_ACCS_Runstatus_SpeedCtrl;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu =
          ACCS_status_SpeedCtrl;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else if (VbACCS_FollowingToLowSpdCtrl)
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromFollowingToLowSpeed;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          ACCS_IN_ACCS_Runstatus_LowSpeed;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_LowSpeed;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 = NoTransfer;
        if (VbACCS_DriverGasPedalOverride)
        {
          ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
            DriverGasPedalOverride;
        }
        else
        {
          if (VbACCS_FromFollowingCtrlToStandby)
          {
            ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
              FromFollowingCtrlToStandby;
          }
        }
      }
      break;

     case ACCS_s_IN_ACCS_Runstatus_Launch:
      ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_Launch;
      if (VbACCS_HasCIPV_Object &&
          ((ACCS_subsystem_integrated_DW.VfACCS_LaunchTimer >=
            KfACCS_t_ExitLaunchTimer) ||
           (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG >=
            KfACCS_v_ExitLaunchSpeedThrsh)))
      {
        VbACCS_LaunchToFollowingCtrl = true;
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromLaunchToFollowingCtrl;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchTimer = 0.0F;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchLowSpdTimer = 0.0F;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchStopTimer = 0.0F;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          IN_ACCS_Runstatus_FollowingCtrl;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu =
          ACCS_status_FollowingCtrl;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else if (ACCS_subsystem_integrated_DW.VfACCS_LaunchLowSpdTimer >=
               KfACCS_t_LaunchToLowSpdTm)
      {
        VbACCS_LaunchToLowSpd = true;
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromLaunchToLowSpeed;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchTimer = 0.0F;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchLowSpdTimer = 0.0F;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchStopTimer = 0.0F;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          ACCS_IN_ACCS_Runstatus_LowSpeed;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_LowSpeed;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else if ((!VbACCS_HasCIPV_Object) &&
               ((ACCS_subsystem_integrated_DW.VfACCS_LaunchTimer >=
                 KfACCS_t_ExitLaunchTimer) ||
                (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG >=
                 KfACCS_v_ExitLaunchSpeedThrsh)))
      {
        VbACCS_LaunchToSpeedCtrl = true;
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromLaunchToSpeedCtrl;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchTimer = 0.0F;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchLowSpdTimer = 0.0F;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchStopTimer = 0.0F;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          ACC_IN_ACCS_Runstatus_SpeedCtrl;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu =
          ACCS_status_SpeedCtrl;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else if ((ACCS_subsystem_integrated_DW.VfACCS_LaunchStopTimer >=
                KfACCS_t_LaunchToTempStpTm) || VbACCS_LowSpdToTempStop)
      {
        VbACCS_LaunchToTempStop = true;
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromLaunchToTempStop;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchTimer = 0.0F;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchLowSpdTimer = 0.0F;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchStopTimer = 0.0F;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          ACCS_IN_ACCS_Runstatus_TempStop;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_TempStop;
        ACCS_subsystem_integrated_DW.VfACCS_TempStopTimer = 0.0F;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 = NoTransfer;
        if (VbACCS_DriverGasPedalOverride)
        {
          ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
            DriverGasPedalOverride;
        }
        else
        {
          if (VbACCS_FromLaunchToStandby)
          {
            ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
              FromLaunchToStandby;
          }
        }

        if (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG <=
            KfACCS_v_MovingMinSpeedThrsh)
        {
          ACCS_subsystem_integrated_DW.VfACCS_LaunchStopTimer += 0.01F;
        }
        else
        {
          if (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG >
              (KfACCS_v_MovingMinSpeedThrsh + 0.3F))
          {
            ACCS_subsystem_integrated_DW.VfACCS_LaunchStopTimer = 0.0F;
          }
        }

        if ((ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG <=
             KfACCS_v_LaunchToLowSpdSpeedThrsh) &&
            (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG >
             KfACCS_v_MovingMinSpeedThrsh))
        {
          ACCS_subsystem_integrated_DW.VfACCS_LaunchLowSpdTimer += 0.01F;
        }
        else
        {
          if (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG >
              (KfACCS_v_LaunchToLowSpdSpeedThrsh + 0.5F))
          {
            ACCS_subsystem_integrated_DW.VfACCS_LaunchLowSpdTimer = 0.0F;
            ACCS_subsystem_integrated_DW.VfACCS_LaunchTimer += 0.01F;
            if (ACCS_subsystem_integrated_DW.VfACCS_LaunchTimer < 600.0F)
            {
            }
            else
            {
              ACCS_subsystem_integrated_DW.VfACCS_LaunchTimer = 600.0F;
            }
          }
        }
      }
      break;

     case ACCS_IN_ACCS_Runstatus_LowSpeed:
      ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_LowSpeed;
      if (VbACCS_LowSpdToFollowingCtrl)
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromLowSpeedToFollowing;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          IN_ACCS_Runstatus_FollowingCtrl;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu =
          ACCS_status_FollowingCtrl;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else if (VbACCS_LowSpdToTempStop)
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromLowSpeedToTempStop;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          ACCS_IN_ACCS_Runstatus_TempStop;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_TempStop;
        ACCS_subsystem_integrated_DW.VfACCS_TempStopTimer = 0.0F;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else if (VbACCS_LowSpdToSpeedCtr)
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromLowSpeedToSpeed;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          ACC_IN_ACCS_Runstatus_SpeedCtrl;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu =
          ACCS_status_SpeedCtrl;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 = NoTransfer;
        if (VbACCS_DriverGasPedalOverride)
        {
          ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
            DriverGasPedalOverride;
        }
        else
        {
          if (VbACCS_FromLowSpeedToStandby)
          {
            ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
              FromLowSpeedToStandby;
          }
        }
      }
      break;

     case ACC_IN_ACCS_Runstatus_SpeedCtrl:
      ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_SpeedCtrl;
      if (VbACCS_SpdToLowSpeedCtr)
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromSpeedToLowSpeed;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          ACCS_IN_ACCS_Runstatus_LowSpeed;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_LowSpeed;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else if (VbACCS_SpeedToFollowingCtr)
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromSpeedToFollowing;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          IN_ACCS_Runstatus_FollowingCtrl;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu =
          ACCS_status_FollowingCtrl;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 = NoTransfer;
        if (VbACCS_DriverGasPedalOverride)
        {
          ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
            DriverGasPedalOverride;
        }
        else
        {
          if (VbACCS_FromSpeedCtrlToStandby)
          {
            ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
              FromSpeedCtrlToStandby;
          }
        }
      }
      break;

     case ACCS_sub_IN_ACCS_Runstatus_Stop:
      ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_Stop;
      tmp = !ACCS_subsystem_integrated_B.VbACCS_InformDriverPressResumeE;
      if ((((((ACCS_subsystem_integrated_B.VbACCS_InformDriverPressGasPeda) &&
              (ACCS_subsystem_integrated_B.Switch6[1])) && tmp) ||
            ((ACCS_subsystem_integrated_B.VbACCS_InformDriverPressResumeE) &&
             (ACCS_subsystem_integrated_B.Switch6[0]))) &&
           (!VbACCS_BrakePedalPress)) && VbACCS_GearPositionIsD)
      {
        VbACCS_StopToLaunch = true;
        VfACCS_StopTimer = 0.0F;
        ACCS_subsystem_integrated_B.VbACCS_InformDriverPressGasPeda = false;
        ACCS_subsystem_integrated_B.VbACCS_InformDriverPressResumeE = false;
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromStopToLaunch;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          ACCS_s_IN_ACCS_Runstatus_Launch;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_Launch;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchTimer = 0.0F;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchLowSpdTimer = 0.0F;
        ACCS_subsystem_integrated_DW.VfACCS_LaunchStopTimer = 0.0F;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 = NoTransfer;
        if (VbACCS_DriverGasPedalOverride)
        {
          ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
            DriverGasPedalOverride;
        }
        else
        {
          if (VbACCS_FromStopToStandby)
          {
            ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
              FromStopToStandby;
          }
        }

        ACCS_subsystem_integrated_B.VbACCS_InformDriverPressGasPeda =
          VbACCS_TempStopToLaunch;
        VfACCS_StopTimer += (real32_T)((real_T)(0.01 * ((real_T)(tmp ? 1.0 : 0.0))));
        if (VfACCS_StopTimer < 600.0F)
        {
        }
        else
        {
          VfACCS_StopTimer = 600.0F;
        }

        ACCS_subsystem_integrated_B.VbACCS_InformDriverPressResumeE =
          ((VfACCS_StopTimer >= KfACCS_t_MaxTimerAllowAutoResume) &&
           VbACCS_TempStopToLaunch);
      }
      break;

     case ACCS_IN_ACCS_Runstatus_TempStop:
      ACCS_su_ACCS_Runstatus_TempStop();
      break;

     default:
      ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_on;
      if (VbACCS_StatusOnToSpeedCtrl)
      {
        ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
          FromOnToSpeedCtrl;
        ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
          ACC_IN_ACCS_Runstatus_SpeedCtrl;
        ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu =
          ACCS_status_SpeedCtrl;
        ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
          NoEnterStandby;
      }
      else
      {
        if (VbACCS_StatusOnToStop)
        {
          ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 =
            FromOnToStop;
          ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
            ACCS_sub_IN_ACCS_Runstatus_Stop;
          ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_Stop;
          VfACCS_StopTimer = ACCS_subsystem_integrated_DW.VfACCS_TempStopTimer;
          ACCS_subsystem_integrated_DW.VfACCS_TempStopTimer = 0.0F;
          ACCS_subsystem_integrated_B.VbACCS_InformDriverPressGasPeda = false;
          ACCS_subsystem_integrated_B.VbACCS_InformDriverPressResumeE = false;
          ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif =
            NoEnterStandby;
        }
      }
      break;
    }
  }
}

/* System initialize for atomic system: '<S138>/DtrmnACCS_RunStatusTransfer' */
void DtrmnACCS_RunStatusTransfer_Init(void)
{
  ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
    ACCS_su_IN_NO_ACTIVE_CHILD_kuby;
  ACCS_subsystem_integrated_DW.is_active_c4_ACCS_subsystem_int = 0U;
  ACCS_subsystem_integrated_DW.is_c4_ACCS_subsystem_integrated =
    ACCS_su_IN_NO_ACTIVE_CHILD_kuby;
}

/* Output and update for atomic system: '<S138>/DtrmnACCS_RunStatusTransfer' */
void DtrmnACCS_RunStatusTransfer(void)
{
  /* Chart: '<S138>/DtrmnACCS_RunStatusTransfer' */
  if (((uint32_T)ACCS_subsystem_integrated_DW.is_active_c4_ACCS_subsystem_int) ==
      0U)
  {
    ACCS_subsystem_integrated_DW.is_active_c4_ACCS_subsystem_int = 1U;
    ACCS_subsystem_integrated_DW.is_c4_ACCS_subsystem_integrated =
      ACCS__IN_ACCS_Runstatus_Standby;
    ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_Standby;
  }
  else if (((uint32_T)
            ACCS_subsystem_integrated_DW.is_c4_ACCS_subsystem_integrated) ==
           ACC_IN_ACCS_ModeAndRunStatus_on)
  {
    ACCS_s_ACCS_ModeAndRunStatus_on();
  }
  else
  {
    ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_Standby;
    if (((uint32_T)VeACCS_ModeState) == ACCS_mode_on)
    {
      ACCS_subsystem_integrated_DW.is_c4_ACCS_subsystem_integrated =
        ACC_IN_ACCS_ModeAndRunStatus_on;
      ACCS_subsystem_integrated_DW.is_ACCS_ModeAndRunStatus_on =
        ACCS_subsy_IN_ACCS_Runstatus_on;
      ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu = ACCS_status_on;
      ACCS_subsystem_integrated_DW.VfACCS_TempStopTimer = 0.0F;
      VfACCS_StopTimer = 0.0F;
      ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif = NoEnterStandby;
      ACCS_subsystem_integrated_B.VbACCS_InformDriverPressGasPeda = false;
      ACCS_subsystem_integrated_B.VbACCS_InformDriverPressResumeE = false;
      ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0 = NoTransfer;
    }
  }

  /* End of Chart: '<S138>/DtrmnACCS_RunStatusTransfer' */
}

/* System initialize for atomic system: '<S138>/DtrmnACCS_StatusTransferConds' */
void DtrmnACCS_StatusTransferConds_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S150>/DtrmnACCS_WhetherDriverInputDuringStop' */
  /* SystemInitialize for Chart: '<S155>/DtrmnACCS_WhetherPressResume' */
  ACCS_subsystem_integrated_DW.is_active_c12_ACCS_subsystem_in = 0U;
  ACCS_subsystem_integrated_DW.is_c12_ACCS_subsystem_integrate =
    ACCS_su_IN_NO_ACTIVE_CHILD_dinm;

  /* SystemInitialize for Chart: '<S155>/DtrmnACCS_WhetherPressGasPedal' */
  ACCS_subsystem_integrated_DW.is_active_c11_ACCS_subsystem_in = 0U;
  ACCS_subsystem_integrated_DW.is_c11_ACCS_subsystem_integrate =
    ACCS_su_IN_NO_ACTIVE_CHILD_dinm;

  /* End of SystemInitialize for SubSystem: '<S150>/DtrmnACCS_WhetherDriverInputDuringStop' */
}

/* Output and update for atomic system: '<S138>/DtrmnACCS_StatusTransferConds' */
void DtrmnACCS_StatusTransferConds(void)
{
  real_T rtb_Switch;
  real_T rtb_Switch_gdi1;
  real_T rtb_Switch_ejic;
  real_T rtb_Switch_nz0q;
  boolean_T rtb_Switch1;
  boolean_T rtb_UnitDelay_eao1;
  boolean_T rtb_DriverPressResume;
  real32_T rtb_Switch3_hlia;
  real_T tmp;
  real_T VbACCS_SpdToLowSpeedCtr_tmp;

  /* Outputs for Atomic SubSystem: '<S150>/DtrmnACCS_WhetherDriverInputDuringStop' */
  /* UnitDelay: '<S155>/Unit Delay' */
  rtb_UnitDelay_eao1 = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_adca;

  /* Chart: '<S155>/DtrmnACCS_WhetherPressResume' */
  if (((uint32_T)ACCS_subsystem_integrated_DW.is_active_c12_ACCS_subsystem_in) ==
      0U)
  {
    ACCS_subsystem_integrated_DW.is_active_c12_ACCS_subsystem_in = 1U;
    ACCS_subsystem_integrated_DW.is_c12_ACCS_subsystem_integrate =
      ACCS_su_IN_Driver_NoPressResume;
    ACCS_subsystem_integrated_DW.ResumeSwitchPressTimer = 0.0;
    rtb_DriverPressResume = false;
  }
  else if (((uint32_T)
            ACCS_subsystem_integrated_DW.is_c12_ACCS_subsystem_integrate) ==
           ACCS_su_IN_Driver_NoPressResume)
  {
    rtb_DriverPressResume = false;
    if (((ACCS_subsystem_integrated_B.SignalConversion_a213) &&
         (!rtb_UnitDelay_eao1)) ||
        ((!ACCS_subsystem_integrated_B.SignalConversion_a213) &&
         rtb_UnitDelay_eao1))
    {
      ACCS_subsystem_integrated_DW.is_c12_ACCS_subsystem_integrate =
        ACCS_subsy_IN_Driver_PressResum;
      ACCS_subsystem_integrated_DW.ResumeSwitchPressTimer = 0.0;
      rtb_DriverPressResume = true;
    }
  }
  else
  {
    rtb_DriverPressResume = true;
    if (ACCS_subsystem_integrated_DW.ResumeSwitchPressTimer > ((real_T)
         KfACCS_t_PressResumeHoldTm))
    {
      ACCS_subsystem_integrated_DW.is_c12_ACCS_subsystem_integrate =
        ACCS_su_IN_Driver_NoPressResume;
      ACCS_subsystem_integrated_DW.ResumeSwitchPressTimer = 0.0;
      rtb_DriverPressResume = false;
    }
    else
    {
      ACCS_subsystem_integrated_DW.ResumeSwitchPressTimer += 0.01;
    }
  }

  /* End of Chart: '<S155>/DtrmnACCS_WhetherPressResume' */

  /* Chart: '<S155>/DtrmnACCS_WhetherPressGasPedal' */
  if (((uint32_T)ACCS_subsystem_integrated_DW.is_active_c11_ACCS_subsystem_in) ==
      0U)
  {
    ACCS_subsystem_integrated_DW.is_active_c11_ACCS_subsystem_in = 1U;
    ACCS_subsystem_integrated_DW.is_c11_ACCS_subsystem_integrate =
      ACCS_s_IN_Driver_Press_GasPedal;
    ACCS_subsystem_integrated_DW.GasPedalPressTimer = 0.0;
    rtb_UnitDelay_eao1 = false;
  }
  else if (((uint32_T)
            ACCS_subsystem_integrated_DW.is_c11_ACCS_subsystem_integrate) ==
           ACCS_s_IN_Driver_Press_GasPedal)
  {
    rtb_UnitDelay_eao1 = false;
    if (ACCS_subsystem_integrated_B.VfACCS_RangeErrLim_CIPV >=
        KfACCS_Pct_DriverPressGasPedalThrsh)
    {
      ACCS_subsystem_integrated_DW.is_c11_ACCS_subsystem_integrate =
        ACCS_subsystem_inte_IN_GasPedal;
      ACCS_subsystem_integrated_DW.GasPedalPressTimer = 0.0;
      rtb_UnitDelay_eao1 = true;
    }
  }
  else
  {
    rtb_UnitDelay_eao1 = true;
    if ((ACCS_subsystem_integrated_DW.GasPedalPressTimer > ((real_T)
          KfACCS_t_PressGasPedalHoldTm)) &&
        (ACCS_subsystem_integrated_B.VfACCS_RangeErrLim_CIPV <
         (KfACCS_Pct_DriverPressGasPedalThrsh - 0.05F)))
    {
      ACCS_subsystem_integrated_DW.is_c11_ACCS_subsystem_integrate =
        ACCS_s_IN_Driver_Press_GasPedal;
      ACCS_subsystem_integrated_DW.GasPedalPressTimer = 0.0;
      rtb_UnitDelay_eao1 = false;
    }
    else
    {
      ACCS_subsystem_integrated_DW.GasPedalPressTimer += 0.01;
    }
  }

  /* End of Chart: '<S155>/DtrmnACCS_WhetherPressGasPedal' */

  /* Update for UnitDelay: '<S155>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_adca =
    ACCS_subsystem_integrated_B.SignalConversion_a213;

  /* End of Outputs for SubSystem: '<S150>/DtrmnACCS_WhetherDriverInputDuringStop' */

  /* RelationalOperator: '<S150>/Relational Operator25' incorporates:
   *  Constant: '<S150>/Constant36'
   */
  rtb_Switch1 = (ACCS_subsystem_integrated_B.UnitDelay == ACCS_status_Stop);

  /* Switch: '<S150>/Switch6' incorporates:
   *  Constant: '<S150>/Constant'
   *  Constant: '<S150>/Constant37'
   */
  if (rtb_Switch1)
  {
    ACCS_subsystem_integrated_B.Switch6[0] = rtb_DriverPressResume;
  }
  else
  {
    ACCS_subsystem_integrated_B.Switch6[0] = false;
  }

  if (rtb_Switch1)
  {
    ACCS_subsystem_integrated_B.Switch6[1] = rtb_UnitDelay_eao1;
  }
  else
  {
    ACCS_subsystem_integrated_B.Switch6[1] = false;
  }

  /* End of Switch: '<S150>/Switch6' */

  /* Switch: '<S151>/Switch' incorporates:
   *  Constant: '<S150>/Constant6'
   *  Constant: '<S151>/Constant'
   *  Constant: '<S151>/Constant1'
   *  RelationalOperator: '<S150>/Relational Operator4'
   *  Sum: '<S151>/Sum'
   *  UnitDelay: '<S151>/Unit Delay'
   */
  if (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG <=
      KfACCS_v_SpdToLowSpdCtrlSpdThrsh)
  {
    rtb_Switch = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE + 1.0;
  }
  else
  {
    rtb_Switch = 0.0;
  }

  /* End of Switch: '<S151>/Switch' */

  /* Product: '<S151>/Divide' incorporates:
   *  Constant: '<S150>/Constant4'
   *  Constant: '<S150>/Constant5'
   *  Product: '<S153>/Divide'
   */
  VbACCS_SpdToLowSpeedCtr_tmp = ((real_T)KfACCS_t_EnterLowSpeedDelay) / 0.01;

  /* Logic: '<S150>/Logical Operator1' incorporates:
   *  Constant: '<S150>/Constant3'
   *  Product: '<S151>/Divide'
   *  RelationalOperator: '<S151>/Relational Operator'
   */
  VbACCS_SpdToLowSpeedCtr = (KbACCS_EnableLowSpeedCtrl && (rtb_Switch >=
    VbACCS_SpdToLowSpeedCtr_tmp));

  /* Switch: '<S152>/Switch' incorporates:
   *  Constant: '<S150>/Constant9'
   *  Constant: '<S152>/Constant'
   *  Constant: '<S152>/Constant1'
   *  RelationalOperator: '<S150>/Relational Operator5'
   *  Sum: '<S152>/Sum'
   *  UnitDelay: '<S152>/Unit Delay'
   */
  if (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG >=
      KfACCS_v_LowSpdToSpdCtrlSpdThrsh)
  {
    rtb_Switch_gdi1 = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_iiqj + 1.0;
  }
  else
  {
    rtb_Switch_gdi1 = 0.0;
  }

  /* End of Switch: '<S152>/Switch' */

  /* Inport: '<S150>/CIPV_object_valid' */
  VbACCS_HasCIPV_Object = VbACCS_Input_Obs_valid;

  /* Logic: '<S150>/Logical Operator3' incorporates:
   *  Logic: '<S150>/Logical Operator4'
   */
  rtb_UnitDelay_eao1 = !VbACCS_HasCIPV_Object;

  /* Product: '<S152>/Divide' incorporates:
   *  Constant: '<S150>/Constant7'
   *  Constant: '<S150>/Constant8'
   *  Product: '<S154>/Divide'
   */
  rtb_Switch_nz0q = ((real_T)KfACCS_t_ExitLowSpeedDelay) / 0.01;

  /* Logic: '<S150>/Logical Operator2' incorporates:
   *  Logic: '<S150>/Logical Operator3'
   *  Product: '<S152>/Divide'
   *  RelationalOperator: '<S152>/Relational Operator'
   */
  VbACCS_LowSpdToSpeedCtr = (rtb_UnitDelay_eao1 && (rtb_Switch_gdi1 >=
    rtb_Switch_nz0q));

  /* Logic: '<S150>/Logical Operator5' incorporates:
   *  RelationalOperator: '<S150>/Relational Operator6'
   */
  VbACCS_FollowingToSpeedCtrl = (rtb_UnitDelay_eao1 ||
    (VfACCS_CombinedSpeedLimit < VfACCS_Input_Obs_LinearVelocity));

  /* Logic: '<S150>/Logical Operator' incorporates:
   *  Constant: '<S150>/Constant1'
   *  Constant: '<S150>/Constant2'
   *  RelationalOperator: '<S150>/Relational Operator1'
   *  RelationalOperator: '<S150>/Relational Operator2'
   *  RelationalOperator: '<S150>/Relational Operator3'
   */
  VbACCS_SpeedToFollowingCtr = (((VbACCS_HasCIPV_Object &&
    (VfACCS_CombinedSpeedLimit >= VfACCS_Input_Obs_LinearVelocity)) &&
    (VfACCS_Range_Actual <= 150.0F)) && (VfACCS_Input_Obs_Rangerate <= 20.0F));

  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S150>/Constant23'
   *  RelationalOperator: '<S150>/Relational Operator15'
   *  Switch: '<S150>/Switch5'
   */
  if (VbACCS_HasCIPV_Object)
  {
    /* Switch: '<S150>/Switch1' incorporates:
     *  Constant: '<S150>/Constant20'
     *  Constant: '<S150>/Constant21'
     *  Constant: '<S150>/Constant38'
     *  Logic: '<S150>/Logical Operator24'
     *  RelationalOperator: '<S150>/Relational Operator12'
     *  RelationalOperator: '<S150>/Relational Operator26'
     *  RelationalOperator: '<S150>/Relational Operator27'
     *  Sum: '<S150>/Subtract'
     */
    if (ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v)
    {
      /* Sum: '<S150>/Subtract' */
      rtb_Switch3_hlia = VfACCS_Range_Actual - VfACCS_DriverTargetRange;

      /* MinMax: '<S150>/MinMax' incorporates:
       *  Sum: '<S150>/Subtract'
       */
      if (ACCS_subsystem_integrated_B.VfACCS_Input_stop_s_distance_DC <
          rtb_Switch3_hlia)
      {
        rtb_Switch3_hlia =
          ACCS_subsystem_integrated_B.VfACCS_Input_stop_s_distance_DC;
      }

      /* End of MinMax: '<S150>/MinMax' */
      rtb_Switch1 = (rtb_Switch3_hlia <= KfACCS_d_LowSpdToTempStpDisThrsh);
    }
    else
    {
      rtb_Switch1 = (((VfACCS_Range_Actual - VfACCS_DriverTargetRange) <=
                      KfACCS_d_LowSpdToTempStpDisThrsh) &&
                     (VfACCS_Input_Obs_LinearVelocity <=
                      KfACCS_v_LowSpdToTempStpSpdThrsh));
    }

    /* End of Switch: '<S150>/Switch1' */
  }
  else
  {
    if (ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v)
    {
      /* Switch: '<S150>/Switch5' */
      tmp = (real_T)ACCS_subsystem_integrated_B.VfACCS_Input_stop_s_distance_DC;
    }
    else
    {
      /* Switch: '<S150>/Switch5' incorporates:
       *  Constant: '<S150>/Constant35'
       */
      tmp = 255.0;
    }

    rtb_Switch1 = (tmp <= ((real_T)KfACCS_d_LowSpdToTempStpDisThrsh));
  }

  /* End of Switch: '<S150>/Switch' */

  /* Logic: '<S150>/Logical Operator10' incorporates:
   *  Constant: '<S150>/Constant22'
   *  Constant: '<S150>/Constant31'
   *  Logic: '<S150>/Logical Operator16'
   *  RelationalOperator: '<S150>/Relational Operator14'
   *  RelationalOperator: '<S150>/Relational Operator22'
   */
  VbACCS_LowSpdToTempStop = (rtb_Switch1 &&
    ((ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG <=
      KfACCS_v_LowSpdToTempStpSpdThrsh) &&
     (ACCS_subsystem_integrated_B.Product_cjbq <
      KfACCS_a_LowSpdToTempStpAccelThrsh)));

  /* Switch: '<S154>/Switch' incorporates:
   *  Constant: '<S150>/Constant18'
   *  Constant: '<S154>/Constant'
   *  Constant: '<S154>/Constant1'
   *  RelationalOperator: '<S150>/Relational Operator10'
   *  Sum: '<S154>/Sum'
   *  UnitDelay: '<S154>/Unit Delay'
   */
  if (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG >=
      KfACCS_v_LowSpdToFollowingSpdThrsh)
  {
    rtb_Switch_ejic = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_hso2 + 1.0;
  }
  else
  {
    rtb_Switch_ejic = 0.0;
  }

  /* End of Switch: '<S154>/Switch' */

  /* Logic: '<S150>/Logical Operator8' incorporates:
   *  Constant: '<S150>/Constant19'
   *  RelationalOperator: '<S150>/Relational Operator11'
   *  RelationalOperator: '<S154>/Relational Operator'
   */
  VbACCS_LowSpdToFollowingCtrl = ((VbACCS_HasCIPV_Object && (rtb_Switch_ejic >=
    rtb_Switch_nz0q)) && (VfACCS_Input_Obs_LinearVelocity >=
    KfACCS_v_LowSpdToFollowingSpdThrsh));

  /* Switch: '<S150>/Switch2' incorporates:
   *  Constant: '<S150>/Constant27'
   *  Constant: '<S150>/Constant28'
   *  Constant: '<S150>/Constant30'
   *  Constant: '<S150>/Constant33'
   *  Constant: '<S150>/Constant34'
   *  Logic: '<S150>/Logical Operator14'
   *  Logic: '<S150>/Logical Operator15'
   *  Logic: '<S150>/Logical Operator17'
   *  RelationalOperator: '<S150>/Relational Operator18'
   *  RelationalOperator: '<S150>/Relational Operator19'
   *  RelationalOperator: '<S150>/Relational Operator21'
   *  RelationalOperator: '<S150>/Relational Operator23'
   *  RelationalOperator: '<S150>/Relational Operator24'
   *  Switch: '<S150>/Switch4'
   */
  if (VbACCS_HasCIPV_Object)
  {
    /* Switch: '<S150>/Switch3' incorporates:
     *  Sum: '<S150>/Subtract2'
     */
    if (ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v)
    {
      /* Sum: '<S150>/Subtract2' */
      rtb_Switch3_hlia = VfACCS_Range_Actual - VfACCS_DriverTargetRange;

      /* MinMax: '<S150>/MinMax1' incorporates:
       *  Sum: '<S150>/Subtract2'
       */
      if (ACCS_subsystem_integrated_B.VfACCS_Input_stop_s_distance_DC <
          rtb_Switch3_hlia)
      {
        rtb_Switch3_hlia =
          ACCS_subsystem_integrated_B.VfACCS_Input_stop_s_distance_DC;
      }

      /* End of MinMax: '<S150>/MinMax1' */
    }
    else
    {
      rtb_Switch3_hlia = VfACCS_Range_Actual - VfACCS_DriverTargetRange;
    }

    /* End of Switch: '<S150>/Switch3' */
    rtb_Switch1 = (((VfACCS_Input_Obs_LinearVelocity >=
                     KfACCS_v_TempStpToLaunchSpdThrsh) &&
                    (VfACCS_Input_Obs_Rangerate >=
                     KfACCS_d_TempStopToLaunchRRThrsh)) && (rtb_Switch3_hlia >=
      KfACCS_d_TempStpToLaunchDisThrsh));
  }
  else
  {
    if (ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v)
    {
      /* Switch: '<S150>/Switch4' */
      tmp = (real_T)ACCS_subsystem_integrated_B.VfACCS_Input_stop_s_distance_DC;
    }
    else
    {
      /* Switch: '<S150>/Switch4' incorporates:
       *  Constant: '<S150>/Constant32'
       */
      tmp = 255.0;
    }

    rtb_Switch1 = ((ACCS_subsystem_integrated_B.CalDriverSetSpeed >=
                    KfACCS_v_TempStpToLaunchSpdThrsh) && (tmp >= ((real_T)
      KfACCS_d_TempStpToLaunchDisThrsh)));
  }

  /* End of Switch: '<S150>/Switch2' */

  /* Logic: '<S150>/Logical Operator13' incorporates:
   *  Constant: '<S150>/Constant29'
   *  Logic: '<S150>/Logical Operator20'
   *  RelationalOperator: '<S150>/Relational Operator20'
   */
  VbACCS_TempStopToLaunch = (((rtb_Switch1 &&
    (ACCS_subsystem_integrated_B.Product_cjbq >
     KfACCS_a_TempStpToLaunchAccelThrsh)) &&
    (ACCS_subsystem_integrated_B.VbACCS_Input_DriverPresent)) &&
    (!VbACCS_BrakePedalPress));

  /* Switch: '<S153>/Switch' incorporates:
   *  Constant: '<S150>/Constant13'
   *  Constant: '<S153>/Constant'
   *  Constant: '<S153>/Constant1'
   *  RelationalOperator: '<S150>/Relational Operator7'
   *  Sum: '<S153>/Sum'
   *  UnitDelay: '<S153>/Unit Delay'
   */
  if (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG <=
      KfACCS_v_FollowingToLowSpdThrsh)
  {
    rtb_Switch_nz0q = ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_hgyz + 1.0;
  }
  else
  {
    rtb_Switch_nz0q = 0.0;
  }

  /* End of Switch: '<S153>/Switch' */

  /* Logic: '<S150>/Logical Operator6' incorporates:
   *  Abs: '<S150>/Abs'
   *  Constant: '<S150>/Constant10'
   *  Constant: '<S150>/Constant14'
   *  Constant: '<S150>/Constant15'
   *  Logic: '<S150>/Logical Operator23'
   *  Logic: '<S150>/Logical Operator7'
   *  RelationalOperator: '<S150>/Relational Operator8'
   *  RelationalOperator: '<S150>/Relational Operator9'
   *  RelationalOperator: '<S153>/Relational Operator'
   */
  VbACCS_FollowingToLowSpdCtrl = ((KbACCS_EnableLowSpeedCtrl && (rtb_Switch_nz0q
    >= VbACCS_SpdToLowSpeedCtr_tmp)) && (((VfACCS_Input_Obs_LinearVelocity <=
    KfACCS_v_FollowingToLowSpdThrsh) && (((real32_T)fabs((real_T)
    VfACCS_Input_Obs_Rangerate)) <= KfACCS_d_FollowingToLowSpdRRThrsh)) ||
    (ACCS_subsystem_integrated_B.VbACCS_Input_stop_request__d13v)));

  /* Logic: '<S150>/Logical Operator11' incorporates:
   *  Constant: '<S150>/Constant24'
   *  RelationalOperator: '<S150>/Relational Operator16'
   */
  VbACCS_StatusOnToSpeedCtrl = (VbACCS_DriverHasSetSpeed &&
    (ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG >=
     KfACCS_v_OnToSpdCtrlSpdThrsh));

  /* Logic: '<S150>/Logical Operator12' incorporates:
   *  Constant: '<S150>/Constant25'
   *  Constant: '<S150>/Constant26'
   *  RelationalOperator: '<S150>/Relational Operator17'
   */
  VbACCS_StatusOnToStop =
    ((ACCS_subsystem_integrated_B.VfACCS_Input_linear_velocity_EG == 0.0F) &&
     KbACCS_AllowOnToStop);

  /* Logic: '<S150>/Logical Operator25' incorporates:
   *  Constant: '<S150>/Constant40'
   *  Constant: '<S150>/Constant41'
   *  Logic: '<S150>/Logical Operator18'
   *  Logic: '<S150>/Logical Operator19'
   *  Logic: '<S150>/Logical Operator30'
   *  Logic: '<S150>/Logical Operator31'
   *  Logic: '<S150>/Logical Operator9'
   *  RelationalOperator: '<S150>/Relational Operator13'
   */
  VbACCS_EnterStandbyCommonCod = (((!KbACCS_NotAllowEnterStandbyForUSDemo) &&
    (((((!VbACCS_GearPositionIsD) || VbACCS_SpeedOutRange) ||
       (!ACCS_subsystem_integrated_B.VbACCS_Input_DriverPresent)) ||
      (!VbACCS_DriverModeAllowACCS)) ||
     (ACCS_subsystem_integrated_B.Ego_LimitCondition))) &&
    (ACCS_subsystem_integrated_B.VeACCS_Input_autodrive_activate != ((uint8_T)0U)));

  /* Logic: '<S150>/Logical Operator26' incorporates:
   *  Constant: '<S150>/Constant39'
   *  RelationalOperator: '<S150>/Relational Operator29'
   */
  VbACCS_FromStopToStandby = (VbACCS_EnterStandbyCommonCod ||
    (ACCS_subsystem_integrated_B.Switch >= KfACCS_t_StopTooLongThrsh));

  /* Logic: '<S150>/Logical Operator22' incorporates:
   *  Logic: '<S150>/Logical Operator29'
   *  Logic: '<S150>/Logical Operator34'
   */
  rtb_UnitDelay_eao1 = (VbACCS_BrakePedalPress || VbACCS_EPB_Engaged);

  /* Logic: '<S150>/Logical Operator21' incorporates:
   *  Logic: '<S150>/Logical Operator33'
   */
  rtb_DriverPressResume = ((ACCS_subsystem_integrated_B.UnitDelay1) &&
    VbACCS_AEB_Active);

  /* Logic: '<S150>/Logical Operator22' incorporates:
   *  Logic: '<S150>/Logical Operator21'
   *  Logic: '<S150>/Logical Operator37'
   */
  rtb_Switch1 = (rtb_UnitDelay_eao1 || rtb_DriverPressResume);
  VbACCS_FromLowSpeedToStandby = (rtb_Switch1 || VbACCS_EnterStandbyCommonCod);

  /* Logic: '<S150>/Logical Operator29' */
  VbACCS_FromLaunchToStandby = ((rtb_UnitDelay_eao1 || VbACCS_AEB_Active) ||
    VbACCS_EnterStandbyCommonCod);

  /* Logic: '<S150>/Logical Operator34' */
  VbACCS_FromFollowingCtrlToStandby = (((rtb_UnitDelay_eao1 ||
    (ACCS_subsystem_integrated_B.Switch4)) || rtb_DriverPressResume) ||
    VbACCS_EnterStandbyCommonCod);

  /* Logic: '<S150>/Logical Operator37' */
  VbACCS_FromSpeedCtrlToStandby = (rtb_Switch1 || VbACCS_EnterStandbyCommonCod);

  /* Logic: '<S150>/Logical Operator32' incorporates:
   *  Constant: '<S150>/Constant42'
   *  Constant: '<S150>/Constant43'
   *  Constant: '<S150>/Constant44'
   *  Constant: '<S150>/Constant45'
   *  Logic: '<S150>/Logical Operator27'
   *  Logic: '<S150>/Logical Operator28'
   *  RelationalOperator: '<S150>/Relational Operator28'
   *  RelationalOperator: '<S150>/Relational Operator30'
   *  RelationalOperator: '<S150>/Relational Operator31'
   *  RelationalOperator: '<S150>/Relational Operator32'
   *  UnitDelay: '<S150>/Unit Delay'
   */
  VbACCS_EnterStopDueToCIP = (KbACCS_AllowEnterStopDueToCIP &&
    ((VfACCS_Input_Obs_ID != ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ok4f)
     || (((VeACCS_CIPVobsType == 0) || (VeACCS_CIPVobsType == 1)) ||
         (VeACCS_CIPVobsType == 2))));

  /* Update for UnitDelay: '<S151>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE = rtb_Switch;

  /* Update for UnitDelay: '<S152>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_iiqj = rtb_Switch_gdi1;

  /* Update for UnitDelay: '<S154>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_hso2 = rtb_Switch_ejic;

  /* Update for UnitDelay: '<S153>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_hgyz = rtb_Switch_nz0q;

  /* Update for UnitDelay: '<S150>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ok4f = VfACCS_Input_Obs_ID;
}

/* System initialize for atomic system: '<S16>/DtrmnACCS_RunStatus' */
void DtrmnACCS_RunStatus_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S138>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ffzr = ACCS_status_on;

  /* SystemInitialize for Atomic SubSystem: '<S138>/DtrmnACCS_StatusTransferConds' */
  DtrmnACCS_StatusTransferConds_Init();

  /* End of SystemInitialize for SubSystem: '<S138>/DtrmnACCS_StatusTransferConds' */

  /* SystemInitialize for Chart: '<S138>/DtrmnACCS_RunStatusTransfer' */
  DtrmnACCS_RunStatusTransfer_Init();
}

/* Output and update for atomic system: '<S16>/DtrmnACCS_RunStatus' */
void DtrmnACCS_RunStatus(void)
{
  /* UnitDelay: '<S138>/Unit Delay' */
  ACCS_subsystem_integrated_B.UnitDelay =
    ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ffzr;

  /* UnitDelay: '<S138>/Unit Delay1' */
  ACCS_subsystem_integrated_B.Switch =
    ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE;

  /* Outputs for Atomic SubSystem: '<S138>/DtrmnACCS_StatusTransferConds' */
  DtrmnACCS_StatusTransferConds();

  /* End of Outputs for SubSystem: '<S138>/DtrmnACCS_StatusTransferConds' */

  /* Chart: '<S138>/DtrmnACCS_RunStatusTransfer' */
  DtrmnACCS_RunStatusTransfer();

  /* Update for UnitDelay: '<S138>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_ffzr =
    ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu;

  /* Update for UnitDelay: '<S138>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE = VfACCS_StopTimer;
}

/* System initialize for atomic system: '<S4>/DtrmnACCS_ModeManger' */
void DtrmnACCS_ModeManger_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S16>/DtrmnACCS_ModeState' */
  DtrmnACCS_ModeState_Init();

  /* End of SystemInitialize for SubSystem: '<S16>/DtrmnACCS_ModeState' */

  /* SystemInitialize for Atomic SubSystem: '<S16>/DtrmnACCS_RunStatus' */
  DtrmnACCS_RunStatus_Init();

  /* End of SystemInitialize for SubSystem: '<S16>/DtrmnACCS_RunStatus' */

  /* SystemInitialize for Atomic SubSystem: '<S16>/DtrmnACCS_FaultState' */
  DtrmnACCS_FaultState_Init();

  /* End of SystemInitialize for SubSystem: '<S16>/DtrmnACCS_FaultState' */
}

/* Output and update for atomic system: '<S4>/DtrmnACCS_ModeManger' */
void DtrmnACCS_ModeManger(void)
{
  /* Constant: '<S16>/Constant11' */
  VbACCS_AEB_Active = KbACCS_AEBStateFrmCal;

  /* Logic: '<S16>/Logical Operator2' */
  VbACCS_MainSwitch = ((ACCS_subsystem_integrated_B.SignalConversion1_dk4z) &&
                       (ACCS_subsystem_integrated_B.SignalConversion));

  /* Logic: '<S16>/Logical Operator5' incorporates:
   *  Constant: '<S16>/Constant22'
   *  Constant: '<S16>/Constant40'
   *  Logic: '<S16>/Logical Operator4'
   *  Logic: '<S16>/Logical Operator9'
   *  RelationalOperator: '<S16>/Relational Operator6'
   */
  ACCS_subsystem_integrated_B.Switch4 = ((!KbACCS_NotAllowEnterStandbyForUSDemo)
    && ((ACCS_subsystem_integrated_B.VeACCS_Input_autodrive_activate ==
         ((uint8_T)0U)) || (ACCS_subsystem_integrated_B.Switch4)));

  /* UnitDelay: '<S16>/Unit Delay' */
  ACCS_subsystem_integrated_B.UnitDelay =
    ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_d4k1;

  /* UnitDelay: '<S16>/Unit Delay1' */
  ACCS_subsystem_integrated_B.UnitDelay1_e3kh =
    ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_gmku;

  /* Outputs for Atomic SubSystem: '<S16>/DtrmnACCS_ModeState' */
  DtrmnACCS_ModeState();

  /* End of Outputs for SubSystem: '<S16>/DtrmnACCS_ModeState' */

  /* SignalConversion: '<S16>/Signal Conversion2' */
  VfACCS_Range_Actual = VfACCS_Input_Obs_Range;

  /* Switch: '<S16>/Switch3' incorporates:
   *  Logic: '<S16>/Logical Operator6'
   */
  if (!ACCS_subsystem_integrated_B.VbACCS_Input_NoSpdLimit_mvju)
  {
    /* MinMax: '<S16>/Min' */
    if (ACCS_subsystem_integrated_B.VfACCS_Input_traffic_speed_limi <
        ACCS_subsystem_integrated_B.CalDriverSetSpeed)
    {
      VfACCS_CombinedSpeedLimit =
        ACCS_subsystem_integrated_B.VfACCS_Input_traffic_speed_limi;
    }
    else
    {
      VfACCS_CombinedSpeedLimit = ACCS_subsystem_integrated_B.CalDriverSetSpeed;
    }

    /* End of MinMax: '<S16>/Min' */
  }
  else
  {
    VfACCS_CombinedSpeedLimit = ACCS_subsystem_integrated_B.CalDriverSetSpeed;
  }

  /* End of Switch: '<S16>/Switch3' */

  /* Switch: '<S16>/Switch4' incorporates:
   *  Constant: '<S16>/Constant1'
   *  Constant: '<S16>/Constant8'
   */
  if (KbACCS_CalCIPV_FlickState)
  {
    ACCS_subsystem_integrated_B.Switch4 = VbACCS_CIPVObsRangeFlicker;
  }
  else
  {
    ACCS_subsystem_integrated_B.Switch4 = false;
  }

  /* End of Switch: '<S16>/Switch4' */

  /* Outputs for Atomic SubSystem: '<S16>/DtrmnACCS_RunStatus' */
  DtrmnACCS_RunStatus();

  /* End of Outputs for SubSystem: '<S16>/DtrmnACCS_RunStatus' */

  /* Switch: '<S16>/Switch2' incorporates:
   *  Constant: '<S16>/Constant4'
   *  Constant: '<S16>/Constant6'
   *  Logic: '<S16>/Logical Operator3'
   *  RelationalOperator: '<S16>/Relational Operator2'
   *  RelationalOperator: '<S16>/Relational Operator3'
   */
  if ((VeACCS_ModeState == ACCS_mode_off) || (VeACCS_ModeState ==
       ACCS_mode_fault))
  {
    /* SignalConversion: '<S16>/Signal Conversion' incorporates:
     *  Constant: '<S16>/Constant3'
     */
    VbACCS_InformDriverPressResume = false;

    /* SignalConversion: '<S16>/Signal Conversion1' incorporates:
     *  Constant: '<S16>/Constant5'
     */
    VbACCS_InformDriverPressGasPedal = false;
  }
  else
  {
    /* SignalConversion: '<S16>/Signal Conversion' incorporates:
     *  Logic: '<S16>/Logical Operator1'
     */
    VbACCS_InformDriverPressResume =
      ((ACCS_subsystem_integrated_B.SignalConversion) ||
       (ACCS_subsystem_integrated_B.VbACCS_InformDriverPressResumeE));

    /* SignalConversion: '<S16>/Signal Conversion1' incorporates:
     *  Logic: '<S16>/Logical Operator'
     */
    VbACCS_InformDriverPressGasPedal =
      ((ACCS_subsystem_integrated_B.SignalConversion1_dk4z) ||
       (ACCS_subsystem_integrated_B.VbACCS_InformDriverPressGasPeda));
  }

  /* End of Switch: '<S16>/Switch2' */

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Constant'
   *  RelationalOperator: '<S16>/Relational Operator'
   */
  if (VeACCS_ModeState == ACCS_mode_on)
  {
    VeACCS_RunStatus = ACCS_subsystem_integrated_B.VeACCS_RunStatus_nlqu;
  }
  else
  {
    VeACCS_RunStatus = VeACCS_RunStatusFrmMode;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Switch: '<S16>/Switch1' incorporates:
   *  Constant: '<S16>/Constant2'
   *  Constant: '<S16>/Constant7'
   *  RelationalOperator: '<S16>/Relational Operator1'
   */
  if (VeACCS_ModeState == ACCS_mode_off)
  {
    VeACCS_EnterStandbyType = NoEnterStandby;
  }
  else
  {
    VeACCS_EnterStandbyType =
      ACCS_subsystem_integrated_B.VeACCS_EnterStandbyType_hvif;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* Switch: '<S16>/Switch5' incorporates:
   *  Constant: '<S16>/Constant10'
   *  Constant: '<S16>/Constant9'
   *  RelationalOperator: '<S16>/Relational Operator4'
   */
  if (VeACCS_ModeState == ACCS_mode_on)
  {
    VeACCS_StatusTransferType =
      ACCS_subsystem_integrated_B.VeACCS_StatusTransferType_git0;
  }
  else
  {
    VeACCS_StatusTransferType = NoTransfer;
  }

  /* End of Switch: '<S16>/Switch5' */

  /* Outputs for Atomic SubSystem: '<S16>/DtrmnACCS_FaultState' */
  DtrmnACCS_FaultState();

  /* End of Outputs for SubSystem: '<S16>/DtrmnACCS_FaultState' */

  /* Update for UnitDelay: '<S16>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_d4k1 = VeACCS_RunStatus;

  /* Update for UnitDelay: '<S16>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_gmku = VeACCS_EnterStandbyType;
}

/* System initialize for atomic system: '<S1>/DtrmnACCS_MainLogic' */
void DtrmnACCS_MainLogic_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S4>/DtrmnACCS_ModeManger' */
  DtrmnACCS_ModeManger_Init();

  /* End of SystemInitialize for SubSystem: '<S4>/DtrmnACCS_ModeManger' */
}

/* Output and update for atomic system: '<S1>/DtrmnACCS_MainLogic' */
void DtrmnACCS_MainLogic(void)
{
  /* Outputs for Atomic SubSystem: '<S4>/DtrmnACCS_InputSignalConvert' */
  DtrmnACCS_InputSignalConvert();

  /* End of Outputs for SubSystem: '<S4>/DtrmnACCS_InputSignalConvert' */

  /* UnitDelay: '<S4>/Unit Delay' */
  ACCS_subsystem_integrated_B.Product_cjbq =
    ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_n0sm;

  /* UnitDelay: '<S4>/Unit Delay2' */
  ACCS_subsystem_integrated_B.Switch =
    ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE;

  /* UnitDelay: '<S4>/Unit Delay1' */
  ACCS_subsystem_integrated_B.UnitDelay1 =
    ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_dciv;

  /* Outputs for Atomic SubSystem: '<S4>/DtrmnACCS_ModeManger' */
  DtrmnACCS_ModeManger();

  /* End of Outputs for SubSystem: '<S4>/DtrmnACCS_ModeManger' */

  /* Outputs for Atomic SubSystem: '<S4>/DtrmnACCS_DsrdLonControlParm' */
  DtrmnACCS_DsrdLonControlParm();

  /* End of Outputs for SubSystem: '<S4>/DtrmnACCS_DsrdLonControlParm' */

  /* Outputs for Atomic SubSystem: '<S4>/DtrmnACCS_Lon_AccelOrTorq' */
  DtrmnACCS_Lon_AccelOrTorq();

  /* End of Outputs for SubSystem: '<S4>/DtrmnACCS_Lon_AccelOrTorq' */

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  ACCS_subsystem_integrated_DW.UnitDelay_DSTATE_n0sm = VfACCS_DrsdAccelWithPitch;

  /* Update for UnitDelay: '<S4>/Unit Delay2' */
  ACCS_subsystem_integrated_DW.UnitDelay2_DSTATE = VfACCS_Lon_Torq_Req;

  /* Update for UnitDelay: '<S4>/Unit Delay1' */
  ACCS_subsystem_integrated_DW.UnitDelay1_DSTATE_dciv = VbACCS_Lon_Torq_Req;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
