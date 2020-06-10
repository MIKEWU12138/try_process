/*
 * File: LDWS_subsystem_integrated.c
 *
 * Code generated for Simulink model 'LDWS_subsystem_integrated'.
 *
 * Model version                  : 1.384
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 11:19:43 2020
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

#include "LDWS_subsystem_integrated.h"
#include "LDWS_subsystem_integrated_private.h"

const LDWS_DataBus LDWS_subsystem_integrated_rtZLDWS_DataBus =
{
  LDWS_BothAvl,                        /* LDWS_la_detect_st */
  LDWS_NoWarn,                         /* LDWS_warn_side */
  false,                               /* LDWS_warn_st */
  LDWS_Off,                            /* LDWS_system_st */
  LDWS_Enabling                        /* LDWS_on_state_st */
} ;                                    /* LDWS_DataBus ground */

/* Exported block signals */
LDWS_DataBus VsLDWS_DataBus;           /* '<S1>/Bus Creator2' */
real32_T VfLDWS_SteerAngleRate;        /* '<S2>/Divide' */
real32_T VfLDWS_BackToRiDist;          /* '<S8>/Abs'
                                        * The distacne bewteen center of rear axle and right lane marker
                                        */
real32_T VfLDWS_Theta;                 /* '<S49>/Switch'
                                        * The angle between linear velocity and heading
                                        */
real32_T VfLDWS_Vx;                    /* '<S8>/Signal Conversion'
                                        * The value of Vx
                                        */
real32_T VfLDWS_Vy;                    /* '<S8>/Signal Conversion1'
                                        * The value of Vy
                                        */
real32_T VfLDWS_VLatLe;                /* '<S61>/Add' */
real32_T VfLDWS_EdgeLaneLe;            /* '<S50>/Switch'
                                        * The vertical distacne between left front wheel and left lane marker
                                        */
real32_T VfLDWS_TLCLe;                 /* '<S60>/Merge'
                                        * The time to collision of left side
                                        */
real32_T VfLDWS_EdgeLaneRi;            /* '<S50>/Switch2'
                                        * The vertical distacne between right front wheel and right lane marker
                                        */
real32_T VfLDWS_VLatRi;                /* '<S61>/Add1' */
real32_T VfLDWS_TLCRi;                 /* '<S60>/Merge1'
                                        * The time to collision of right side
                                        */
real32_T VfLDWS_SteerAngle;            /* '<S8>/Signal Conversion2'
                                        * The vehicle's steering angle
                                        */
real32_T VfLDWS_SteerTorque;           /* '<S7>/Signal Conversion2' */
real32_T VfLDWS_Curvature;             /* '<S4>/Gain' */
real32_T VfLDWS_LeC0Filtd;             /* '<S23>/Switch1'
                                        * The C0 coefficient of left lane marker after filtering
                                        */
real32_T VfLDWS_RiC0Filtd;             /* '<S24>/Switch1'
                                        * The C0 coefficient of right lane marker after filtering
                                        */
real32_T VfLDWS_LeC1Filtd;             /* '<S4>/MATLAB Function'
                                        * The C1 coefficient of left lane marker after filtering
                                        */
real32_T VfLDWS_RiC1Filtd;             /* '<S4>/MATLAB Function'
                                        * The C1 coefficient of right lane marker after filtering
                                        */
real32_T VfLDWS_BackToLeDist;          /* '<S4>/MATLAB Function'
                                        * The distacne bewteen center of rear axle and left lane marker
                                        */
boolean_T VbLDWS_IsOnLeLine;           /* '<S51>/Switch1'
                                        * The vehicle is on left lane marker or not
                                        */
boolean_T VbLDWS_LeadDrctn;            /* '<S47>/Switch'
                                        * The heading of vehicle is left or right. True is on left, fale is on right.
                                        */
boolean_T VbLDWS_ActLeLDW;             /* '<S8>/Switch'
                                        * The left LDW is whether trggered or not
                                        */
boolean_T VbLDWS_IsOnRiLine;           /* '<S52>/Switch2'
                                        * The vehicle is on right lane marker or not
                                        */
boolean_T VbLDWS_ActRiLDW;             /* '<S8>/Switch1'
                                        * The right LDW is whether triggered or not
                                        */
boolean_T VbLDWS_LeIndicatorSt;        /* '<S7>/Signal Conversion'
                                        * The status of right indicator
                                        */
boolean_T VbLDWS_SuppLe;               /* '<S34>/Logical Operator'
                                        * The left LDW is whether suppressed or not
                                        */
boolean_T VbLDWS_RiIndicatorSt;        /* '<S7>/Signal Conversion1'
                                        * The status of right indicator
                                        */
boolean_T VbLDWS_SuppRi;               /* '<S35>/Logical Operator1'
                                        * The right LDW is whether suppressed or not
                                        */
boolean_T VbLDWS_RdEnblLe;             /* '<S30>/Switch'
                                        * The left Lane Marker is whether enabled or not
                                        */
boolean_T VbLDWS_RdEnblRi;             /* '<S31>/Switch1'
                                        * The right Lane Marker is whether enabled or not
                                        */
boolean_T VbLDWS_WrnSt;                /* '<S5>/Merge'
                                        * The warning is whether issued or not
                                        */
boolean_T VbLDWS_EnabledLDW;           /* '<S13>/LogOp3'
                                        * The system is whether enabled or not
                                        */
boolean_T VbLDWS_SpdRngValid;          /* '<S3>/MATLAB Function1'
                                        * The ODD of speed range is whether fullfiled
                                        */
boolean_T VbLDWS_CurvValid;            /* '<S3>/MATLAB Function'
                                        * The ODD of lane curvature is whether fullfiled
                                        */
boolean_T VbLDWS_WidthValid;           /* '<S3>/MATLAB Function'
                                        * The ODD of lane width is whether fullfiled
                                        */
boolean_T VbLDWS_LnMkrValid;           /* '<S3>/MATLAB Function'
                                        * The ODD of lane marker is whether fullfiled
                                        */
EnumLDWS_la_detec_st VeLDWS_LaDetecSt; /* '<S5>/Truth Table' */
EnumLDWS_warn_side VeLDWS_WrnSd;       /* '<S5>/Merge1' */
EnumLDWS_system_st VeLDWS_SysSt;       /* '<S9>/Warning_Machine' */
EnumLDWS_on_state_st VeLDWS_OnStateSt; /* '<S9>/Warning_Machine' */

/* Exported block parameters */
#pragma section ".cal"
real32_T KfLDWS_Ang_BkToCnrAng = 0.318F;/* Variable: KfLDWS_Ang_BkToCnrAng
                                         * Referenced by:
                                         *   '<S50>/Constant3'
                                         *   '<S50>/Constant4'
                                         * The angle X axis and the line connecting center of rear axle and front tire.
                                         */
real32_T KfLDWS_Ang_SuppSteerAngThrsh = 30.0F;/* Variable: KfLDWS_Ang_SuppSteerAngThrsh
                                               * Referenced by:
                                               *   '<S34>/Constant5'
                                               *   '<S35>/Constant14'
                                               * The suppression threshold for Steer Angle
                                               */
real32_T KfLDWS_M_SuppTorque = 2.5F;   /* Variable: KfLDWS_M_SuppTorque
                                        * Referenced by:
                                        *   '<S34>/Constant1'
                                        *   '<S35>/Constant1'
                                        * The torque limit that could be treated as suppression
                                        */
real32_T KfLDWS_c_CurvLwrBnd = 0.002F; /* Variable: KfLDWS_c_CurvLwrBnd
                                        * Referenced by: '<S3>/Constant1'
                                        * The curvature upper bound for ODD
                                        */
real32_T KfLDWS_c_CurvUprBnd = 0.004F; /* Variable: KfLDWS_c_CurvUprBnd
                                        * Referenced by:
                                        *   '<S3>/Constant'
                                        *   '<S50>/Switch1'
                                        *   '<S50>/Switch3'
                                        * The curvature lower bound for ODD
                                        */
real32_T KfLDWS_d_BkToFrtCnrDist = 3.06F;/* Variable: KfLDWS_d_BkToFrtCnrDist
                                          * Referenced by:
                                          *   '<S50>/Constant1'
                                          *   '<S50>/Constant2'
                                          * The distance between one fo the front tires to the center of rear axle.
                                          */
real32_T KfLDWS_d_EdgBuff = 0.5F;      /* Variable: KfLDWS_d_EdgBuff
                                        * Referenced by:
                                        *   '<S50>/Constant'
                                        *   '<S50>/Constant5'
                                        *   '<S50>/Constant8'
                                        *   '<S50>/Constant9'
                                        * The edge buffer that added to the calcualted distance to lane markers
                                        */
real32_T KfLDWS_d_LnWidthLwrBnd = 2.6F;/* Variable: KfLDWS_d_LnWidthLwrBnd
                                        * Referenced by: '<S3>/Constant3'
                                        * The lane width lower bound for ODD
                                        */
real32_T KfLDWS_d_LnWidthUprBnd = 5.2F;/* Variable: KfLDWS_d_LnWidthUprBnd
                                        * Referenced by: '<S3>/Constant2'
                                        * The lane width upper bound for ODD
                                        */
real32_T KfLDWS_d_WarnLineLvlOne = 1.5F;/* Variable: KfLDWS_d_WarnLineLvlOne
                                         * Referenced by:
                                         *   '<S51>/Constant1'
                                         *   '<S52>/Constant1'
                                         * When vehicle speed is higher than 1.0m/s, the earliest warning line shall be placed no more than 1.5m inside the lane boundary.
                                         */
real32_T KfLDWS_d_WarnLineLvlThree = 0.75F;/* Variable: KfLDWS_d_WarnLineLvlThree
                                            * Referenced by:
                                            *   '<S51>/Constant2'
                                            *   '<S52>/Constant2'
                                            * When vehicle speed is not higher than 0.5 m/s, the earliest warning line shall be placed no more than 0.75m inside the lane boundary.
                                            */
real32_T KfLDWS_k_CurvBuffCoe = 1.2F;  /* Variable: KfLDWS_k_CurvBuffCoe
                                        * Referenced by:
                                        *   '<S50>/Constant6'
                                        *   '<S50>/Constant7'
                                        * The coefficient that multiples the distance to lanemarker when the vehicle is driving under large curavture.
                                        */
real32_T KfLDWS_k_WarnLineLvlTwo = 1.5F;/* Variable: KfLDWS_k_WarnLineLvlTwo
                                         * Referenced by:
                                         *   '<S51>/Constant3'
                                         *   '<S52>/Constant3'
                                         * When vehicle speed is higher than 0.5m/s but not  higher than 1.0m/s, the earliest warning line shall be placed no more than 1.5*Va m inside the lane boundary
                                         */
real32_T KfLDWS_t_TLCThrsh = 0.5F;     /* Variable: KfLDWS_t_TLCThrsh
                                        * Referenced by:
                                        *   '<S44>/Constant6'
                                        *   '<S45>/Constant6'
                                        * Time to lane crossing threshold
                                        */
real32_T KfLDWS_v_SpdLwrBnd = 16.7F;   /* Variable: KfLDWS_v_SpdLwrBnd
                                        * Referenced by: '<S3>/Constant5'
                                        * The speed lower bound for ODD
                                        */
real32_T KfLDWS_v_SpdUprBnd = 50.0F;   /* Variable: KfLDWS_v_SpdUprBnd
                                        * Referenced by: '<S3>/Constant4'
                                        * The speed upper bound for ODD
                                        */
real32_T KfLDWS_v_SuppSteerRateThrsh = 30.0F;/* Variable: KfLDWS_v_SuppSteerRateThrsh
                                              * Referenced by:
                                              *   '<S34>/Constant2'
                                              *   '<S35>/Constant11'
                                              * The suppression threshold for Steer Rate
                                              */
uint16_T KcLDWS_CntSample = 1U;        /* Variable: KcLDWS_CntSample
                                        * Referenced by:
                                        *   '<S9>/Constant3'
                                        *   '<S12>/Constant1'
                                        *   '<S12>/Constant2'
                                        *   '<S12>/Constant3'
                                        *   '<S12>/Constant4'
                                        *   '<S14>/Constant'
                                        *   '<S14>/Constant1'
                                        *   '<S14>/Constant2'
                                        *   '<S14>/Constant3'
                                        *   '<S30>/Constant9'
                                        *   '<S31>/Constant9'
                                        *   '<S34>/Constant13'
                                        *   '<S34>/Constant3'
                                        *   '<S34>/Constant7'
                                        *   '<S34>/Constant9'
                                        *   '<S35>/Constant13'
                                        *   '<S35>/Constant3'
                                        *   '<S35>/Constant7'
                                        *   '<S35>/Constant9'
                                        * The sample time that state machine uses in a loop.
                                        */
uint16_T KfLDWS_t_CntMaxWarnHold = 500U;/* Variable: KfLDWS_t_CntMaxWarnHold
                                         * Referenced by: '<S9>/Constant'
                                         * The maximum time that a warning satte is allowed to last
                                         */
uint16_T KfLDWS_t_CntMinWarnHold = 100U;/* Variable: KfLDWS_t_CntMinWarnHold
                                         * Referenced by: '<S9>/Constant1'
                                         * The minimum time that a warning state shall last.
                                         */
uint16_T KfLDWS_t_CntOnHold = 10U;     /* Variable: KfLDWS_t_CntOnHold
                                        * Referenced by: '<S9>/Constant2'
                                        * The bouncing time that avoids wrong trigger.
                                        */
uint16_T KfLDWS_t_CurvNotValidTime = 200U;/* Variable: KfLDWS_t_CurvNotValidTime
                                           * Referenced by: '<S12>/Constant15'
                                           * The time that Enabling Manager uses to reset condition for curvature
                                           */
uint16_T KfLDWS_t_CurvValidTime = 100U;/* Variable: KfLDWS_t_CurvValidTime
                                        * Referenced by: '<S14>/Constant7'
                                        * The time that Enabling Manager uses to set condition for curvature
                                        */
uint16_T KfLDWS_t_LnMkrMissThrsh = 20U;/* Variable: KfLDWS_t_LnMkrMissThrsh
                                        * Referenced by:
                                        *   '<S30>/Constant'
                                        *   '<S31>/Constant'
                                        * The maximum time that a lane marker could termporarily go missing
                                        */
uint16_T KfLDWS_t_LnMkrNotValidTime = 0U;/* Variable: KfLDWS_t_LnMkrNotValidTime
                                          * Referenced by: '<S12>/Constant20'
                                          * The time that Enabling Manager uses set condion for lane marker
                                          */
uint16_T KfLDWS_t_LnMkrValidTime = 500U;/* Variable: KfLDWS_t_LnMkrValidTime
                                         * Referenced by: '<S14>/Constant9'
                                         * The time that Enabling Manager uses reset condition for lane marker
                                         */
uint16_T KfLDWS_t_LnWidthNotValidTime = 300U;/* Variable: KfLDWS_t_LnWidthNotValidTime
                                              * Referenced by: '<S12>/Constant16'
                                              * The time that Enabling Manager uses to reset condition for lane width
                                              */
uint16_T KfLDWS_t_LnWidthValidTime = 100U;/* Variable: KfLDWS_t_LnWidthValidTime
                                           * Referenced by: '<S14>/Constant8'
                                           * The time that enabling manager uses to set condition for lane width
                                           */
uint16_T KfLDWS_t_SpdRngNotValidTime = 500U;/* Variable: KfLDWS_t_SpdRngNotValidTime
                                             * Referenced by: '<S12>/Constant14'
                                             * The time that enabling manager uses to reset condition for speed range
                                             */
uint16_T KfLDWS_t_SpdRngValidTime = 200U;/* Variable: KfLDWS_t_SpdRngValidTime
                                          * Referenced by: '<S14>/Constant6'
                                          * The time that enabling manager uses to set condtion for speed range
                                          */
uint16_T KfLDWS_t_SuppIndiTime = 10U;  /* Variable: KfLDWS_t_SuppIndiTime
                                        * Referenced by:
                                        *   '<S34>/Constant10'
                                        *   '<S35>/Constant10'
                                        * The time that indicator could be treated as suppression
                                        */
uint16_T KfLDWS_t_SuppSteerAngTime = 0U;/* Variable: KfLDWS_t_SuppSteerAngTime
                                         * Referenced by:
                                         *   '<S34>/Constant6'
                                         *   '<S35>/Constant6'
                                         * The time that steer angle could be treated as suppression
                                         */
uint16_T KfLDWS_t_SuppSteerRateTime = 0U;/* Variable: KfLDWS_t_SuppSteerRateTime
                                          * Referenced by:
                                          *   '<S34>/Constant4'
                                          *   '<S35>/Constant4'
                                          * The time that steer rate could be treated as suppression
                                          */
uint16_T KfLDWS_t_SuppTorqueTime = 250U;/* Variable: KfLDWS_t_SuppTorqueTime
                                         * Referenced by:
                                         *   '<S34>/Constant12'
                                         *   '<S35>/Constant12'
                                         * The time that steer toque could be treated as suppression
                                         */
uint8_T KfLDWS_r_LaMkrQlt = 1U;        /* Variable: KfLDWS_r_LaMkrQlt
                                        * Referenced by:
                                        *   '<S30>/Constant2'
                                        *   '<S31>/Constant2'
                                        * Lane marker quality threshold
                                        */
boolean_T KbLDWS_EnableSwitch = 0;     /* Variable: KbLDWS_EnableSwitch
                                        * Referenced by: '<S9>/Constant5'
                                        */
boolean_T KbLDWS_SuppLeSwitch = 0;     /* Variable: KbLDWS_SuppLeSwitch
                                        * Referenced by: '<S7>/Constant1'
                                        */
boolean_T KbLDWS_SuppRiSwitch = 0;     /* Variable: KbLDWS_SuppRiSwitch
                                        * Referenced by: '<S7>/Constant3'
                                        */
boolean_T KbLDWS_ThetaSwitch = 1;      /* Variable: KbLDWS_ThetaSwitch
                                        * Referenced by: '<S49>/Constant'
                                        */
#pragma section

/* Block signals (auto storage) */
B_LDWS_subsystem_integrated_T LDWS_subsystem_integrated_B;

/* Block states (auto storage) */
DW_LDWS_subsystem_integrated_T LDWS_subsystem_integrated_DW;

/* System initialize for atomic system: '<Root>/LDWS_subsystem_integrated' */
void LDWS_subsystem_integrated_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S1>/WarningManager_LDW' */
  LDWS_su_WarningManager_LDW_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/WarningManager_LDW' */

  /* SystemInitialize for Atomic SubSystem: '<S1>/OutputManager_LDW' */
  LDWS_sub_OutputManager_LDW_Init();

  /* End of SystemInitialize for SubSystem: '<S1>/OutputManager_LDW' */
}

/* Output and update for atomic system: '<Root>/LDWS_subsystem_integrated' */
void LDWS__LDWS_subsystem_integrated(void)
{
  int_T idxDelay;

  /* Outputs for Atomic SubSystem: '<S1>/LnMkrFilter_LDW' */
  LDWS_subsystem__LnMkrFilter_LDW();

  /* End of Outputs for SubSystem: '<S1>/LnMkrFilter_LDW' */

  /* Outputs for Atomic SubSystem: '<S1>/Road_Enable_Estimator_LDW' */
  LDWS__Road_Enable_Estimator_LDW();

  /* End of Outputs for SubSystem: '<S1>/Road_Enable_Estimator_LDW' */

  /* Outputs for Atomic SubSystem: '<S1>/TriggerManager_LDW' */
  LDWS_subsyst_TriggerManager_LDW();

  /* End of Outputs for SubSystem: '<S1>/TriggerManager_LDW' */

  /* Product: '<S2>/Divide' incorporates:
   *  Constant: '<S2>/Constant'
   *  Delay: '<S2>/Delay'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  Sum: '<S2>/Add'
   */
  VfLDWS_SteerAngleRate =
    (VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle -
     LDWS_subsystem_integrated_DW.Delay_DSTATE[0]) / 0.2F;

  /* Outputs for Atomic SubSystem: '<S1>/SuppressionManager_LDW' */
  LDWS_sub_SuppressionManager_LDW();

  /* End of Outputs for SubSystem: '<S1>/SuppressionManager_LDW' */

  /* Outputs for Atomic SubSystem: '<S1>/EnablingManager_LDW' */
  LDWS_subsys_EnablingManager_LDW();

  /* End of Outputs for SubSystem: '<S1>/EnablingManager_LDW' */

  /* Outputs for Atomic SubSystem: '<S1>/WarningManager_LDW' */
  LDWS_subsyst_WarningManager_LDW();

  /* End of Outputs for SubSystem: '<S1>/WarningManager_LDW' */

  /* Outputs for Atomic SubSystem: '<S1>/OutputManager_LDW' */
  LDWS_subsyste_OutputManager_LDW();

  /* End of Outputs for SubSystem: '<S1>/OutputManager_LDW' */

  /* BusCreator: '<S1>/Bus Creator2' */
  VsLDWS_DataBus.LDWS_la_detect_st = VeLDWS_LaDetecSt;
  VsLDWS_DataBus.LDWS_warn_side = VeLDWS_WrnSd;
  VsLDWS_DataBus.LDWS_warn_st = VbLDWS_WrnSt;

  /* Update for Delay: '<S2>/Delay' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  for (idxDelay = 0; idxDelay < 19; idxDelay++)
  {
    LDWS_subsystem_integrated_DW.Delay_DSTATE[idxDelay] =
      LDWS_subsystem_integrated_DW.Delay_DSTATE[idxDelay + 1];
  }

  LDWS_subsystem_integrated_DW.Delay_DSTATE[19] =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle;

  /* End of Update for Delay: '<S2>/Delay' */
}

/* Model step function */
void LDWS_subsystem_integrated_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/LDWS_subsystem_integrated' */
  LDWS__LDWS_subsystem_integrated();

  /* End of Outputs for SubSystem: '<Root>/LDWS_subsystem_integrated' */
}

/* Model initialize function */
void LDWS_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &LDWS_subsystem_integrated_B), 0,
                sizeof(B_LDWS_subsystem_integrated_T));

  {
    LDWS_subsystem_integrated_B.Warn_Manager_Status = Avl;
  }

  /* exported global signals */
  VsLDWS_DataBus = LDWS_subsystem_integrated_rtZLDWS_DataBus;
  VfLDWS_SteerAngleRate = 0.0F;
  VfLDWS_BackToRiDist = 0.0F;
  VfLDWS_Theta = 0.0F;
  VfLDWS_Vx = 0.0F;
  VfLDWS_Vy = 0.0F;
  VfLDWS_VLatLe = 0.0F;
  VfLDWS_EdgeLaneLe = 0.0F;
  VfLDWS_TLCLe = 0.0F;
  VfLDWS_EdgeLaneRi = 0.0F;
  VfLDWS_VLatRi = 0.0F;
  VfLDWS_TLCRi = 0.0F;
  VfLDWS_SteerAngle = 0.0F;
  VfLDWS_SteerTorque = 0.0F;
  VfLDWS_Curvature = 0.0F;
  VfLDWS_LeC0Filtd = 0.0F;
  VfLDWS_RiC0Filtd = 0.0F;
  VfLDWS_LeC1Filtd = 0.0F;
  VfLDWS_RiC1Filtd = 0.0F;
  VfLDWS_BackToLeDist = 0.0F;
  VbLDWS_IsOnLeLine = false;
  VbLDWS_LeadDrctn = false;
  VbLDWS_ActLeLDW = false;
  VbLDWS_IsOnRiLine = false;
  VbLDWS_ActRiLDW = false;
  VbLDWS_LeIndicatorSt = false;
  VbLDWS_SuppLe = false;
  VbLDWS_RiIndicatorSt = false;
  VbLDWS_SuppRi = false;
  VbLDWS_RdEnblLe = false;
  VbLDWS_RdEnblRi = false;
  VbLDWS_WrnSt = false;
  VbLDWS_EnabledLDW = false;
  VbLDWS_SpdRngValid = false;
  VbLDWS_CurvValid = false;
  VbLDWS_WidthValid = false;
  VbLDWS_LnMkrValid = false;
  VeLDWS_LaDetecSt = LDWS_BothAvl;
  VeLDWS_WrnSd = LDWS_NoWarn;
  VeLDWS_SysSt = LDWS_Off;
  VeLDWS_OnStateSt = LDWS_Enabling;

  /* states (dwork) */
  (void) memset((void *)&LDWS_subsystem_integrated_DW, 0,
                sizeof(DW_LDWS_subsystem_integrated_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/LDWS_subsystem_integrated' */
  LDWS_subsystem_integrated_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/LDWS_subsystem_integrated' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
