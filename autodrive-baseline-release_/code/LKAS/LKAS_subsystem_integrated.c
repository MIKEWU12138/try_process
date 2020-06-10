/*
 * File: LKAS_subsystem_integrated.c
 *
 * Code generated for Simulink model 'LKAS_subsystem_integrated'.
 *
 * Model version                  : 1.102
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 11:05:35 2020
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

#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

const LKAS_DataBus LKAS_subsystem_integrated_rtZLKAS_DataBus =
{
  false,                               /* Intv_Request */
  0.0F,                                /* SteerData */
  LKAS_SftyLaneKeepAid,                /* IntvTyp_sLKA */
  LKAS_IntvSideLe,                     /* IntvSide_sLKA */
  LKAS_NoIntv                          /* IntvMgrSt_sLKA */
} ;                                    /* LKAS_DataBus ground */

const LKAS_VehStates LKAS_subsystem_integrated_rtZLKAS_VehStates =
{
  LKAS_IntvSideLe,                     /* IntvSideReq_sLKA */
  0.0F,                                /* Vlat_sLKA */
  0.0F,                                /* L_DistToCross_sLKA */
  LKAS_NoRef,                          /* CtrlRefReq_sLKA */
  0.0F,                                /* L_ExtraMargin_sLKA */
  0.0F,                                /* A_ALatRelLaneMkr_sLKA */
  0.0F,                                /* A_ALatRelLaneMkrLe */
  0.0F,                                /* A_ALatRelLaneMkrRi */
  0.0F                                 /* Vlong_sLKA */
} ;                                    /* LKAS_VehStates ground */

/* Exported block signals */
LKAS_DataBus VsLKAS_DataBus;           /* '<S111>/Bus Creator' */
real32_T VfLKAS_Vlat_sLKA;             /* '<S387>/MSWCH_1' */
real32_T VfLKAS_L_DistToCross_sLKA;    /* '<S387>/MSWCH_2' */
real32_T VfLKAS_L_ExtraMargin_sLKA;    /* '<S240>/k_LKA_SatnOfAInpForPahCalcn1' */
real32_T VfLKAS_A_ALatRelLaneMkr_sLKA; /* '<S388>/Switch2' */
real32_T VfLKAS_A_ALatRelLaneMkrLe;    /* '<S389>/Switch2' */
real32_T VfLKAS_A_ALatRelLaneMkrRi;    /* '<S390>/Switch2' */
real32_T VfLKAS_Vlong_sLKA;            /* '<S376>/Product' */
real32_T VfLKAS_vlat_0;                /* '<S267>/_2' */
real32_T VfLKAS_alat_0;                /* '<S266>/_2' */
real32_T VfLKAS_delta_pos_sLKA;        /* '<S268>/G_2' */
real32_T VfLKAS_TimeNeeded_sLKA;       /* '<S262>/Switch5' */
real32_T VfLKAS_end_offst_sLKA;        /* '<S263>/Switch' */
real32_T VfLKAS_dt_sLKA;               /* '<S249>/Signal Conversion' */
real32_T VfLKAS_A0_sLKA;               /* '<S251>/Signal Conversion' */
real32_T VfLKAS_Am_sLKA;               /* '<S252>/Signal Conversion' */
real32_T VfLKAS_Ae_sLKA;               /* '<S253>/Signal Conversion' */
real32_T VfLKAS_Am1;                   /* '<S284>/Merge' */
real32_T VfLKAS_Am2;                   /* '<S284>/Merge' */
real32_T VfLKAS_dt1;                   /* '<S276>/Saturation' */
real32_T VfLKAS_dt2;                   /* '<S276>/Saturation1' */
real32_T VfLKAS_JerkNeeded_sLkA;       /* '<S277>/Merge_3' */
real32_T VfLKAS_LatAccNeeded_sLKA;     /* '<S277>/Merge_5' */
real32_T VfLKAS_FirstEndPos;           /* '<S325>/ADD_3' */
real32_T VfLKAS_FirstEndVlat;          /* '<S326>/ADD_1' */
real32_T VfLKAS_SecEndPos;             /* '<S337>/ADD_3' */
real32_T VfLKAS_SecEndVlat;            /* '<S338>/ADD_1' */
real32_T VfLKAS_V_Latleft;             /* '<S181>/PROD_5' */
real32_T VfLKAS_L_OffstLeft;           /* '<S181>/PROD_6' */
real32_T VfLKAS_Heading;               /* '<S182>/G_3' */
real32_T VfLKAS_VLatRight;             /* '<S182>/PROD_1' */
real32_T VfLKAS_OffstRi_sLKA;          /* '<S182>/PROD_2' */
real32_T VfLKAS_Cr_Road;               /* '<S221>/SWCH_1' */
real32_T VfLKAS_LaneWidth;             /* '<S220>/Subtract' */
real32_T VfLKAS_Velocity_x;            /* '<S229>/Signal Conversion' */
real32_T VfLKAS_yaw_rate_utm;          /* '<S230>/Signal Conversion' */
real32_T VfLKAS_Acceleration_x;        /* '<S231>/Signal Conversion' */
real32_T VfLKAS_Acce_y;                /* '<S235>/Signal Conversion' */
real32_T VfLKAS_T_AftIntvStart_IntOut; /* '<S175>/Unit Delay1' */
real32_T VfLKAS_RiC0;                  /* '<S182>/MATLAB Function' */
real32_T VfLKAS_RiC1;                  /* '<S182>/MATLAB Function' */
real32_T VfLKAS_RiC2;                  /* '<S182>/MATLAB Function' */
real32_T VfLKAS_Ri_Length;             /* '<S182>/MATLAB Function' */
real32_T VfLKAS_L_DistToCrossRight;    /* '<S182>/DetermineDistToCross' */
real32_T VfLAKS_LeC0;                  /* '<S181>/MATLAB Function1' */
real32_T VfLAKS_LeC1;                  /* '<S181>/MATLAB Function1' */
real32_T VfLKAS_LeC2;                  /* '<S181>/MATLAB Function1' */
real32_T VfLKAS_LeLength;              /* '<S181>/MATLAB Function1' */
real32_T VfLKAS_L_DisToCrossLeft;      /* '<S181>/DetermineDistToDistToCross' */
real32_T VfLKAS_T_AftIntvStart;        /* '<S109>/Switch' */
real32_T VfLKAS_dtFreezed_sLKA;        /* '<S53>/SWCH_1' */
real32_T VfLKAS_AmFreezed_sLKA;        /* '<S51>/SWCH_1' */
real32_T VfLKAS_V0Freezed_sLKA;        /* '<S54>/SWCH_1' */
real32_T VfLKAS_A0Freezed_sLKA;        /* '<S49>/SWCH_1' */
real32_T VfLKAS_AeFreezed_sLKA;        /* '<S52>/SWCH_1' */
real32_T VfLKAS_Jerk2;                 /* '<S24>/Divide1' */
real32_T VfLKAS_TargetDist_Freezed2;   /* '<S22>/SWCH_1' */
real32_T VfLKAS_Jerk1;                 /* '<S24>/Divide' */
real32_T VfLKAS_TargetDist_Freezed1;   /* '<S23>/SWCH_1' */
real32_T VfLKAS_TargetV;               /* '<S17>/Switch2' */
real32_T VfLKAS_Offst_Actual;          /* '<S39>/Switch' */
real32_T VfLKAS_Offst_start;           /* '<S50>/SWCH_1' */
real32_T VfLKAS_DesiredDistToEdge;     /* '<S17>/Add' */
real32_T VfLKAS_OffstError;            /* '<S17>/Add1' */
real32_T VfLKAS_Offst_ErrorDiff;       /* '<S17>/Add3' */
real32_T VfLKAS_Vlat_Desired;          /* '<S17>/Add5' */
real32_T VfLKAS_VlatError;             /* '<S17>/Sum' */
real32_T VfLKAS_Vlat_ErrorDiff;        /* '<S17>/Add4' */
real32_T VfLKAS_TargetA;               /* '<S17>/Switch3' */
real32_T VfLKAS_Alat_Desired;          /* '<S17>/Sum1' */
real32_T VfLKAS_YawRateDesired;        /* '<S17>/Divide' */
real32_T VfLKAS_SteerAngleRequest;     /* '<S19>/Gain' */
real32_T VfLKAS_StrAngFilted;          /* '<S19>/Add1' */
real32_T VfLKAS_SteerAngleRequest_Saturated;/* '<S68>/Switch2' */
real32_T VfLKAS_TargetA_2;             /* '<S27>/Add7' */
real32_T VfLKAS_TargetDist_2;          /* '<S27>/Switch1' */
real32_T VfLKAS_TargetV_2;             /* '<S27>/Switch' */
real32_T VfLKAS_TargetA_1;             /* '<S26>/Add3' */
real32_T VfLKAS_V0Increment;           /* '<S26>/Add2' */
real32_T VfLKAS_TargetDist_1;          /* '<S26>/Switch1' */
real32_T VfLKAS_TargetV_1;             /* '<S26>/Switch' */
real32_T VfLKAS_TargetDist;            /* '<S21>/TargetCalculation' */
uint8_T VfLKAS_QlyLe;                  /* '<S180>/MATLAB Function' */
uint8_T VfLKAS_QlyRi;                  /* '<S180>/MATLAB Function' */
uint8_T VfLKAS_AbortID;                /* '<S85>/Add' */
boolean_T VbLKAS_zero_trajectory_found;/* '<S268>/SWCH_4' */
boolean_T VbLKAS_LaneWidthEnbl;        /* '<S373>/LogOp3' */
boolean_T VbLKAS_RoadEnblRi;           /* '<S369>/RelationalOperator1' */
boolean_T VbLKAS_RoadEnblLe;           /* '<S368>/RelationalOperator1' */
boolean_T VbLKAS__RoadEnbl;            /* '<S364>/SWCH_1' */
boolean_T VbLKAS_InnerCurvLe_sLKA;     /* '<S243>/LogicalOperator3' */
boolean_T VbLKAS_InnerCurvRi_sLKA;     /* '<S244>/LogicalOperator3' */
boolean_T VbLKAS_SolutionFoundForAm;   /* '<S284>/Merge1' */
boolean_T VbLKAS_TrajectoryFound_sLKA; /* '<S277>/Merge_2' */
boolean_T VbLKAS_FirstEndPositionOK;   /* '<S307>/RELOP_2' */
boolean_T VbLKAS_FirstEndVLatOK;       /* '<S307>/RELOP_1' */
boolean_T VbLKAS_TrajectoryFoundAm1;   /* '<S307>/LOGOP_1' */
boolean_T VbLKAS_SecEndPositionOK;     /* '<S308>/RELOP_2' */
boolean_T VbLKAS_SecEndVLatOK;         /* '<S308>/RELOP_1' */
boolean_T VbLKAS_TrajectoryFoundAm2;   /* '<S308>/LOGOP_1' */
boolean_T VbLKAS_QlyValidLe;           /* '<S180>/RELOP_1' */
boolean_T VbLKAS_LeftVLatStep;         /* '<S200>/LOGOP_4' */
boolean_T VbLKAS_LeftCurvStep;         /* '<S198>/LOGOP_4' */
boolean_T VbLKAS_LeftOffstStep;        /* '<S199>/LOGOP_4' */
boolean_T VbLKAS_QlyValidRi;           /* '<S180>/RELOP_5' */
boolean_T VbLKAS_RightVlatStep;        /* '<S215>/LOGOP_4' */
boolean_T VbLKAS_RightCurvStep;        /* '<S216>/LOGOP_4' */
boolean_T VbLKAS_RightOffstStep;       /* '<S217>/LOGOP_4' */
boolean_T VbLKAS_IsIntvCompleted_sLKA_IntOut;/* '<S175>/Unit Delay' */
boolean_T VbLKAS_IsLDWSTriggered;      /* '<S124>/Logical Operator4' */
boolean_T VbLKAS_IsPathAccPlausible;   /* '<S117>/Relational Operator' */
boolean_T VbLKAS_IsTrajInTrigZone;     /* '<S120>/Logical Operator1' */
boolean_T VbLKAS_IsTrajectoryFound;    /* '<S13>/Signal Conversion' */
boolean_T VbLKAS_IsVlatOkForZeroPath;  /* '<S122>/Relational Operator1' */
boolean_T VbLKAS_IsTrackingIntvSide;   /* '<S118>/Logical Operator2' */
boolean_T VbLKAS_IsVlatTowardsIntvSide;/* '<S121>/Multiport Switch' */
boolean_T VbLKAS_IsActivated_sLKA;     /* '<S131>/RelationalOperator1' */
boolean_T VbLKAS_LeftChangeLane;       /* '<S115>/Signal Conversion' */
boolean_T VbLKAS_InnerCurvLe;          /* '<S115>/Signal Conversion1' */
boolean_T VbLKAS_NotQualDrpLeft;       /* '<S115>/Signal Conversion2' */
boolean_T VbLKAS_DlyAftAbort;          /* '<S115>/Signal Conversion3' */
boolean_T VbLKAS_IsSuppLe;             /* '<S115>/Logical Operator' */
boolean_T VbLKAS_RightChangeLane;      /* '<S115>/Signal Conversion4' */
boolean_T VbLKAS_InnerCurvRi;          /* '<S115>/Signal Conversion5' */
boolean_T VbLKAS_NotQualDrpRight;      /* '<S115>/Signal Conversion6' */
boolean_T VbLKAS_IsSuppRi;             /* '<S115>/Logical Operator1' */
boolean_T VbLKAS_Intv_Request;         /* '<S111>/Relational Operator' */
boolean_T VbLKAS_IsInsidePath;         /* '<S87>/Relational Operator' */
boolean_T VbLKAS_IsVlatTowardsLaneCenter;/* '<S92>/Switch' */
boolean_T VbLKAS_IsVmaxReached;        /* '<S93>/Switch' */
boolean_T VbLKAS_IsIntvCompleted;      /* '<S96>/RelationalOperator1' */
boolean_T VbLKAS_IsAbortIntv;          /* '<S77>/Logical Operator' */
boolean_T VbLKAS_IsDelayAftAbort;      /* '<S86>/Logical Operator' */
boolean_T VbLKAS_Trigger_Traj_2;       /* '<S21>/Relational Operator' */
boolean_T VbLKAS_Trigger_Traj_1;       /* '<S21>/Logical Operator' */
EnumLKAS_IntvTyp VeLKAS_IntvTyp_sLKA_IntOut;/* '<S175>/Unit Delay3' */
EnumLKAS_IntvTyp VeLKAS_IntvTyp_sLKA;  /* '<S10>/sLKA' */
EnumLKAS_IntvSide VeLKAS_IntvSideReq_sLKA;/* '<S394>/SWCH_2' */
EnumLKAS_IntvSide VeLKAS_IntvSide_sLKA_IntOut;/* '<S175>/Unit Delay4' */
EnumLKAS_IntvSide VeLKAS_IntvSide_sLKA;/* '<S10>/sLKA' */
EnumLKAS_IntvMgrSt VeLKAS_IntvMgrSt_sLKA;/* '<S10>/sLKA' */
EnumLKAS_CtrlRefTypVcc VeLKAS_CtrlRefReq_sLKA;/* '<S386>/MSWCH_1' */
EnumLKAS_CtrlRefTypVcc VeLKAS_CtrlRef_sLKA_IntOut;/* '<S175>/Unit Delay2' */
EnumLKAS_CtrlRefTypVcc VeLKAS_CtrlRef_sLKA;/* '<S10>/sLKA' */
EnumLKAS_LaneMkrQly VeLKAS_LineLeftOk; /* '<S181>/Switch2' */
EnumLKAS_LaneMkrQly VeLKAS_LineRightOK;/* '<S182>/Switch2' */
EnumLKAS_SystemSt VeLKAS_SystemSt_sLKA;/* '<S10>/sLKA' */
EnumLKAS_OnStateSt VeLKAS_OnStateSt_sLKA;/* '<S10>/sLKA' */

/* Exported block parameters */
#pragma section ".cal"
real32_T KfLKAS_Ang_BkToCnrAng = 0.318F;/* Variable: KfLKAS_Ang_BkToCnrAng
                                         * Referenced by:
                                         *   '<S148>/Constant3'
                                         *   '<S148>/Constant4'
                                         * The angle X axis and the line connecting center of rear axle and front tire.
                                         */
real32_T KfLKAS_Ang_SteerOffset = -13.0F;/* Variable: KfLKAS_Ang_SteerOffset
                                          * Referenced by: '<S19>/Constant11'
                                          */
real32_T KfLKAS_C_CfForLatCtrl = 155494.0F;/* Variable: KfLKAS_C_CfForLatCtrl
                                            * Referenced by: '<S19>/Constant'
                                            * Front tire cornering stiffness.
                                            */
real32_T KfLKAS_C_CrForLatCtrl = 155494.0F;/* Variable: KfLKAS_C_CrForLatCtrl
                                            * Referenced by: '<S19>/Constant1'
                                            * Rear tire cornering stiffness.
                                            */
real32_T KfLKAS_CallFreq = 10.0F;      /* Variable: KfLKAS_CallFreq
                                        * Referenced by: '<S364>/c_LKA_CallFreq'
                                        * Frequency used for delay block, if the frequency is larger, the delay time is longer.
                                        */
real32_T KfLKAS_a_AMaxInPathToTrig_sLKA = 5.0F;/* Variable: KfLKAS_a_AMaxInPathToTrig_sLKA
                                                * Referenced by: '<S117>/Constant'
                                                * The max acceleration in generated trajectory that allows triggering LKAS.
                                                */
real32_T KfLKAS_a_CurveSuppOff = 0.1F; /* Variable: KfLKAS_a_CurveSuppOff
                                        * Referenced by: '<S237>/k_LKA_A_CurveSuppOff'
                                        * When the centripetal acceleration is smaller than a_CurveSuppOff, the road is consideredto be straight.
                                        */
real32_T KfLKAS_a_CurveSuppOn = 1.0F;  /* Variable: KfLKAS_a_CurveSuppOn
                                        * Referenced by: '<S237>/k_LKA_A_CurveSuppOn'
                                        * When the centripetal acceleration is bigger than a_CurveSuppOn, the road curvature is considered to be
                                          too large
                                        */
real32_T KfLKAS_a_SarnOfRelALatForPahCalcn = 0.1F;/* Variable: KfLKAS_a_SarnOfRelALatForPahCalcn
                                                   * Referenced by: '<S375>/k_LKA_SatnOfAInpForPahCalcn'
                                                   * The saturation used for vehicle acceleration relative to lane marker.
                                                   */
real32_T KfLKAS_c_CurvUprBnd = 0.004F; /* Variable: KfLKAS_c_CurvUprBnd
                                        * Referenced by:
                                        *   '<S148>/Switch1'
                                        *   '<S148>/Switch3'
                                        * The curavature upperbound that determines whether to use extra buffer coefficient.
                                        */
real32_T KfLKAS_c_MaxCurvStep = 2.0F;  /* Variable: KfLKAS_c_MaxCurvStep
                                        * Referenced by:
                                        *   '<S188>/k_LKA_Cr_MaxCurvStep1'
                                        *   '<S213>/k_LKA_Cr_MaxCurvStep2'
                                        * The maximum change allowed for curvature at one step.
                                        */
real32_T KfLKAS_d_BkToFrtCnrDist = 3.06F;/* Variable: KfLKAS_d_BkToFrtCnrDist
                                          * Referenced by:
                                          *   '<S148>/Constant1'
                                          *   '<S148>/Constant2'
                                          * The distance between one fo the front tires to the center of rear axle.
                                          */
real32_T KfLKAS_d_EdgBuff = -0.5F;     /* Variable: KfLKAS_d_EdgBuff
                                        * Referenced by:
                                        *   '<S148>/Constant'
                                        *   '<S148>/Constant5'
                                        *   '<S148>/Constant8'
                                        *   '<S148>/Constant9'
                                        * The edge buffer that added to the calcualted distance to lane markers
                                        */
real32_T KfLKAS_d_ExtraMargin = 0.5F;  /* Variable: KfLKAS_d_ExtraMargin
                                        * Referenced by: '<S240>/k_LKA_SatnOfAInpForPahCalcn1'
                                        */
real32_T KfLKAS_d_LfForLatCtrl = 1.121F;/* Variable: KfLKAS_d_LfForLatCtrl
                                         * Referenced by: '<S19>/Constant3'
                                         * The distance beetween front axle and center of mass.
                                         */
real32_T KfLKAS_d_LrForLatCtrl = 1.369F;/* Variable: KfLKAS_d_LrForLatCtrl
                                         * Referenced by: '<S19>/Constant4'
                                         * The distance beetween front axle and center of mass.
                                         */
real32_T KfLKAS_d_MaxEnblLaneWidth = 4.0F;/* Variable: KfLKAS_d_MaxEnblLaneWidth
                                           * Referenced by: '<S367>/k_LKA_L_MaxEnblLaneWidth'
                                           * If the road lane width is larger than the max enable lane width, the LKA function will not be activated.
                                           */
real32_T KfLKAS_d_MaxOffstStep = 2.0F; /* Variable: KfLKAS_d_MaxOffstStep
                                        * Referenced by:
                                        *   '<S189>/k_LKA_L_MaxOffstStep'
                                        *   '<S214>/k_LKA_L_MaxOffstStep'
                                        * The maximum change allowed for offset at one step.
                                        */
real32_T KfLKAS_d_MinDeltaPosFirst = 0.1F;/* Variable: KfLKAS_d_MinDeltaPosFirst
                                           * Referenced by: '<S268>/k_LKA_L_MinDeltaPosFirst'
                                           * If the lateral offset minus extra margin is bigger than minimum delta position first, the LKA function will not be activated.
                                           */
real32_T KfLKAS_d_MinDeltaPosSec = 0.1F;/* Variable: KfLKAS_d_MinDeltaPosSec
                                         * Referenced by: '<S268>/k_LKA_L_MinDeltaPosSec'
                                         * If the lateral offset minus extra margin is smaller than minimum delta position , the LKA function will not be activated.
                                         */
real32_T KfLKAS_d_MinDisLaneWidthMargin = 0.4F;/* Variable: KfLKAS_d_MinDisLaneWidthMargin
                                                * Referenced by: '<S367>/k_LKA_L_MinDisLaneWidthMargin'
                                                * The lane width is disabled if the current lane width is smaller than the vehicle width plus Minimum Disable Lane Width Margin
                                                */
real32_T KfLKAS_d_MinEnblLaneWidthMargin = 0.5F;/* Variable: KfLKAS_d_MinEnblLaneWidthMargin
                                                 * Referenced by: '<S367>/k_LKA_L_MinEnblLaneWidthMargin'
                                                 * The lane width is enabled, if the current lane width is largrer than the vehicle width plus minimum enable lane width margin.
                                                 */
real32_T KfLKAS_d_OffsAtMinDeltaPos = 0.1F;/* Variable: KfLKAS_d_OffsAtMinDeltaPos
                                            * Referenced by: '<S263>/k_LKA_L_OffsAtMinDeltaPos'
                                            * The offset to lane marker at the end of the caculated trajectory.
                                            */
real32_T KfLKAS_d_OffstCtrlr_DeadZone = 0.02F;/* Variable: KfLKAS_d_OffstCtrlr_DeadZone
                                               * Referenced by: '<S17>/Dead Zone1'
                                               */
real32_T KfLKAS_d_PosVal = 1.0F;       /* Variable: KfLKAS_d_PosVal
                                        * Referenced by: '<S261>/k_LKA_LoPosVal'
                                        * The threshold used for trajectory generation.
                                        */
real32_T KfLKAS_d_VehicleWheelBase = 1.8F;/* Variable: KfLKAS_d_VehicleWheelBase
                                           * Referenced by: '<S173>/VehicleWheelBase'
                                           */
real32_T KfLKAS_d_VehicleWidth = 2.0F; /* Variable: KfLKAS_d_VehicleWidth
                                        * Referenced by: '<S173>/VehicleWidth'
                                        */
real32_T KfLKAS_d_WarnLineLvlOne = 1.5F;/* Variable: KfLKAS_d_WarnLineLvlOne
                                         * Referenced by:
                                         *   '<S149>/Constant1'
                                         *   '<S150>/Constant1'
                                         * When vehicle speed is higher than 1.0m/s, the earliest warning line shall be placed no more than 1.5m inside the lane boundary.
                                         */
real32_T KfLKAS_d_WarnLineLvlThree = 0.75F;/* Variable: KfLKAS_d_WarnLineLvlThree
                                            * Referenced by:
                                            *   '<S149>/Constant2'
                                            *   '<S150>/Constant2'
                                            * When vehicle speed is not higher than 0.5 m/s, the earliest warning line shall be placed no more than 0.75m inside the lane boundary.
                                            */
real32_T KfLKAS_j_MaxTrigJerk_sLKA = 5.0F;/* Variable: KfLKAS_j_MaxTrigJerk_sLKA
                                           * Referenced by: '<S120>/Constant1'
                                           * The max jerk in generated trajectory that allows to trigger LKAS.
                                           */
real32_T KfLKAS_k_StrAngFilt = 0.9F;   /* Variable: KfLKAS_k_StrAngFilt
                                        * Referenced by:
                                        *   '<S19>/Constant10'
                                        *   '<S19>/Constant8'
                                        */
real32_T KfLKAS_m_MForLatCtrl = 1590.0F;/* Variable: KfLKAS_m_MForLatCtrl
                                         * Referenced by: '<S19>/Constant2'
                                         * The mass of vehicle being used in two-wheel model calculation.
                                         */
real32_T KfLKAS_r_CurvBuffCoe = 1.2F;  /* Variable: KfLKAS_r_CurvBuffCoe
                                        * Referenced by:
                                        *   '<S148>/Constant6'
                                        *   '<S148>/Constant7'
                                        * The coefficient that multiples the distance to lanemarker when the vehicle is driving under large curavture.
                                        */
real32_T KfLKAS_r_PGainForVlat = 0.2F; /* Variable: KfLKAS_r_PGainForVlat
                                        * Referenced by: '<S17>/Constant1'
                                        * The proportional gain for Vlat in lateral controller.
                                        */
real32_T KfLKAS_r_StrRatioForLatCtrl = 15.0F;/* Variable: KfLKAS_r_StrRatioForLatCtrl
                                              * Referenced by: '<S19>/Constant5'
                                              * Steer ratio used in two-wheel model
                                              */
real32_T KfLKAS_r_WarnLineLvlTwo = 1.5F;/* Variable: KfLKAS_r_WarnLineLvlTwo
                                         * Referenced by:
                                         *   '<S149>/Constant3'
                                         *   '<S150>/Constant3'
                                         * When vehicle speed is higher than 0.5m/s but not  higher than 1.0m/s, the earliest warning line shall be placed no more than 1.5*Va m inside the lane boundary
                                         */
real32_T KfLKAS_t_MaxIntvTime = 20.0F; /* Variable: KfLKAS_t_MaxIntvTime
                                        * Referenced by: '<S76>/Constant'
                                        * Max intervention time that allows in a single time.
                                        */
real32_T KfLKAS_t_RoadEnblOKHoldLow = 1.0F;/* Variable: KfLKAS_t_RoadEnblOKHoldLow
                                            * Referenced by: '<S364>/k_LKA_T_RoadEnblOKHoldLow'
                                            * The road is enabled if the time of road lane width enable is larger than RoadEnableOKHoldLow.
                                            */
real32_T KfLKAS_t_TLCThrsh = 0.5F;     /* Variable: KfLKAS_t_TLCThrsh
                                        * Referenced by:
                                        *   '<S142>/Constant6'
                                        *   '<S143>/Constant6'
                                        * Time to lane crossing (TTLC) threshold.
                                        */
real32_T KfLKAS_t_TMaxNeeded_sLKA = 50.0F;/* Variable: KfLKAS_t_TMaxNeeded_sLKA
                                           * Referenced by: '<S120>/Constant'
                                           * The max time allowed in generated trajectory to trigger LKAS.
                                           */
real32_T KfLKAS_v_MaxStepForVLat = 2.0F;/* Variable: KfLKAS_v_MaxStepForVLat
                                         * Referenced by:
                                         *   '<S190>/k_LKA_V_MaxStepForVLat1'
                                         *   '<S204>/k_LKA_V_MaxStepForVLat'
                                         * The max change allowed for lateral velocity at one step.
                                         */
real32_T KfLKAS_v_VMaxToTrigZeroPath_sLKA = 1.0F;/* Variable: KfLKAS_v_VMaxToTrigZeroPath_sLKA
                                                  * Referenced by: '<S122>/Constant'
                                                  * The max lateral velocity that allows to use zero trajectory.
                                                  */
real32_T KfLKAS_v_VlatCtrlr_DeadZone = 0.2F;/* Variable: KfLKAS_v_VlatCtrlr_DeadZone
                                             * Referenced by: '<S17>/Dead Zone2'
                                             */
real32_T KfLKAS_v_VlatMaxForCmpl = 1.0F;/* Variable: KfLKAS_v_VlatMaxForCmpl
                                         * Referenced by:
                                         *   '<S93>/Constant'
                                         *   '<S93>/Constant1'
                                         * The max lateral velocity used for inervention completion.
                                         */
real32_T KfLKAS_v_VlatMinForCmpl = 0.0F;/* Variable: KfLKAS_v_VlatMinForCmpl
                                         * Referenced by:
                                         *   '<S92>/Constant'
                                         *   '<S92>/Constant1'
                                         * The max lateral velocity used for inervention completion.
                                         */
real32_T KtLKAS_AXIS_OffstCtrlDiffGain_Vlong[9] =
{
  5.5F, 6.9F, 8.3F, 9.7F, 11.1F, 12.5F, 13.8F, 15.2F, 16.7F
} ;                                    /* Variable: KtLKAS_AXIS_OffstCtrlDiffGain_Vlong
                                        * Referenced by: '<S17>/1-D Lookup Table2'
                                        */

real32_T KtLKAS_AXIS_OffstCtrlPropGain_Vlat[6] =
{
  0.0F, 0.2F, 0.4F, 0.6F, 0.8F, 1.0F
} ;                                    /* Variable: KtLKAS_AXIS_OffstCtrlPropGain_Vlat
                                        * Referenced by: '<S17>/1-D Lookup Table'
                                        */

real32_T KtLKAS_AXIS_OffstCtrlPropGain_Vlong[9] =
{
  5.5F, 6.9F, 8.3F, 9.7F, 11.1F, 12.5F, 13.8F, 15.2F, 16.7F
} ;                                    /* Variable: KtLKAS_AXIS_OffstCtrlPropGain_Vlong
                                        * Referenced by: '<S17>/1-D Lookup Table'
                                        */

real32_T KtLKAS_AXIS_StrAngSaturation[9] =
{
  5.5F, 6.9F, 8.3F, 9.7F, 11.1F, 12.5F, 13.8F, 15.2F, 16.7F
} ;                                    /* Variable: KtLKAS_AXIS_StrAngSaturation
                                        * Referenced by:
                                        *   '<S19>/1-D Lookup Table'
                                        *   '<S19>/1-D Lookup Table1'
                                        */

real32_T KtLKAS_Ang_StrAngLwrSaturation[9] =
{
  -100.0F, -100.0F, -100.0F, -100.0F, -100.0F, -100.0F, -80.0F, -60.0F, -40.0F
} ;                                    /* Variable: KtLKAS_Ang_StrAngLwrSaturation
                                        * Referenced by: '<S19>/1-D Lookup Table'
                                        */

real32_T KtLKAS_Ang_StrAngUpperSaturation[9] =
{
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 80.0F, 60.0F, 40.0F
} ;                                    /* Variable: KtLKAS_Ang_StrAngUpperSaturation
                                        * Referenced by: '<S19>/1-D Lookup Table1'
                                        */

real32_T KtLKAS_r_OffstCtrlDiffGain[9] =
{
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F
} ;                                    /* Variable: KtLKAS_r_OffstCtrlDiffGain
                                        * Referenced by: '<S17>/1-D Lookup Table2'
                                        */

real32_T KtLKAS_r_OffstCtrlPropGain[54] =
{
  7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F,
  7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 7.8F, 6.5F, 7.15F,
  7.41F, 7.8F, 7.8F, 7.8F, 6.5F, 7.15F, 7.41F, 7.67F, 7.8F, 7.8F, 6.5F, 7.02F,
  7.28F, 7.54F, 7.8F, 7.8F, 6.5F, 7.02F, 7.28F, 7.54F, 7.8F, 7.8F, 6.5F, 7.02F,
  7.28F, 7.54F, 7.8F, 7.8F
} ;                                    /* Variable: KtLKAS_r_OffstCtrlPropGain
                                        * Referenced by: '<S17>/1-D Lookup Table'
                                        */

uint16_T KcLKAS_CntSample = 1U;        /* Variable: KcLKAS_CntSample
                                        * Referenced by:
                                        *   '<S78>/Constant'
                                        *   '<S123>/Constant'
                                        *   '<S95>/Constant'
                                        *   '<S138>/Constant9'
                                        *   '<S139>/Constant9'
                                        * The sample time that state machine uses in a loop.
                                        */
uint16_T KfLKAS_t_LnMkrMissThrsh = 20U;/* Variable: KfLKAS_t_LnMkrMissThrsh
                                        * Referenced by:
                                        *   '<S138>/Constant'
                                        *   '<S139>/Constant'
                                        * The maximum time that a lane marker could termporarily go missing
                                        */
uint16_T KfLKAS_t_TDelayForAct_sLKA = 3U;/* Variable: KfLKAS_t_TDelayForAct_sLKA
                                          * Referenced by: '<S123>/Constant1'
                                          * Time delay for activation to increase robustness.
                                          */
uint16_T KfLKAS_t_TDelayForCmpl_sLKA = 10U;/* Variable: KfLKAS_t_TDelayForCmpl_sLKA
                                            * Referenced by: '<S95>/Constant1'
                                            */
uint16_T KfLKAS_t_TimeDlyAbort = 100U; /* Variable: KfLKAS_t_TimeDlyAbort
                                        * Referenced by: '<S78>/Constant1'
                                        * Time delay for activation abort.
                                        */
uint8_T KfLKAS_r_QlyVld = 1U;          /* Variable: KfLKAS_r_QlyVld
                                        * Referenced by:
                                        *   '<S138>/KfLKAS_QlyVld'
                                        *   '<S139>/KfLKAS_QlyVld'
                                        *   '<S180>/k_LKA_QlyVld'
                                        * Lane marker quality threshold
                                        */
boolean_T KbLKAS_A0Trigger_Temp = 0;   /* Variable: KbLKAS_A0Trigger_Temp
                                        * Referenced by: '<S375>/k_LKA_SatnOfAInpForPahCalcn1'
                                        */
boolean_T KbLKAS_AbortSwitch_Temp = 0; /* Variable: KbLKAS_AbortSwitch_Temp
                                        * Referenced by: '<S77>/Constant1'
                                        */
boolean_T KbLKAS_NotUseOffstForCmpl_Temp = 0;/* Variable: KbLKAS_NotUseOffstForCmpl_Temp
                                              * Referenced by: '<S90>/Constant1'
                                              */
boolean_T KbLKAS_SuppSwitch_Temp = 0;  /* Variable: KbLKAS_SuppSwitch_Temp
                                        * Referenced by:
                                        *   '<S115>/Constant'
                                        *   '<S115>/Constant1'
                                        */
boolean_T KbLKAS_TargetSwitch_Temp = 0;/* Variable: KbLKAS_TargetSwitch_Temp
                                        * Referenced by:
                                        *   '<S17>/Constant'
                                        *   '<S17>/Constant3'
                                        */
boolean_T KbLKAS_TriggerLDWSwitch = 1; /* Variable: KbLKAS_TriggerLDWSwitch
                                        * Referenced by: '<S13>/Constant'
                                        * The switch that uses LDWS triggering conditions.
                                        */
boolean_T KbLKAS_UseInsidePathForCmpl_Temp = 1;/* Variable: KbLKAS_UseInsidePathForCmpl_Temp
                                                * Referenced by: '<S89>/Constant3'
                                                */
boolean_T KbLKAS_UseVmaxForCmpl_Temp = 0;/* Variable: KbLKAS_UseVmaxForCmpl_Temp
                                          * Referenced by: '<S89>/Constant1'
                                          */
#pragma section

/* Block signals (auto storage) */
B_LKAS_subsystem_integrated_T LKAS_subsystem_integrated_B;

/* Block states (auto storage) */
DW_LKAS_subsystem_integrated_T LKAS_subsystem_integrated_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_LKAS_subsystem_integrate_T LKAS_subsystem_integrated_U;
const DRIV_DataBus LKAS_subsystem_integrated_rtZDR =
{
  {
    false,                             /* VbDIRV_Override_Steering */
    0U,                                /* VeDRIV_LeftChangeLane */
    0U,                                /* VeDRIV_RightChangeLane */
    false                              /* VbDRIV_LaneKeepAssist */
  },                                   /* OverrideSteer */
  {
    false,                             /* VbDRIV_EnableAutoDrive */
    false,                             /* VbLCC_ButtonActivate */
    false                              /* VbACC_ButtonActivate */
  },                                   /* OverrideButton */
  0U,                                  /* VeDRIV_DriverStatus */
  false,                               /* VbDRIV_ModeStatus */
  {
    false,                             /* VbDRIV_ACCMainSwitch */
    false,                             /* VbDRIV_ACCResumeSwitch */
    false,                             /* VbDRIV_ACCCancelSwitch */
    0.0F,                              /* VfDRIV_ACCDriveSetSpeed */
    0U                                 /* VfDRIV_ACCTimeGap */
  }                                    /* DRIV_ACCS_Switch */
};

/* System initialize for atomic system: '<Root>/LKAS_subsystem_integrated' */
void LKAS_subsystem_integrated_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S3>/InputFusion' */
  LKAS_subsystem_InputFusion_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/InputFusion' */

  /* SystemInitialize for Atomic SubSystem: '<S3>/ControlLayer' */
  LKAS_subsyste_ControlLayer_Init();

  /* End of SystemInitialize for SubSystem: '<S3>/ControlLayer' */
}

/* Output and update for atomic system: '<Root>/LKAS_subsystem_integrated' */
void LKAS__LKAS_subsystem_integrated(void)
{
  /* Outputs for Atomic SubSystem: '<S3>/InputFusion' */
  LKAS_subsystem_inte_InputFusion();

  /* End of Outputs for SubSystem: '<S3>/InputFusion' */

  /* Outputs for Atomic SubSystem: '<S3>/ControlLayer' */
  LKAS_subsystem_int_ControlLayer();

  /* End of Outputs for SubSystem: '<S3>/ControlLayer' */

  /* Update for Atomic SubSystem: '<S3>/InputFusion' */
  LKAS_subsyst_InputFusion_Update();

  /* End of Update for SubSystem: '<S3>/InputFusion' */
}

/* Model step function */
void LKAS_subsystem_integrated_step(void)
{
  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  Inport: '<Root>/DRIV_DataBus'
   */
  LKAS_subsystem_integrated_B.VsDRIV_DataBus =
    LKAS_subsystem_integrated_U.VsDRIV_DataBus;
  LKAS_subsystem_integrated_B.VsDRIV_DataBus.OverrideSteer.VeDRIV_LeftChangeLane
    = LeftLC_NOT;
  LKAS_subsystem_integrated_B.VsDRIV_DataBus.OverrideSteer.VeDRIV_RightChangeLane
    = RightLC_NOT;

  /* Outputs for Atomic SubSystem: '<Root>/LKAS_subsystem_integrated' */
  LKAS__LKAS_subsystem_integrated();

  /* End of Outputs for SubSystem: '<Root>/LKAS_subsystem_integrated' */
}

/* Model initialize function */
void LKAS_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &LKAS_subsystem_integrated_B), 0,
                sizeof(B_LKAS_subsystem_integrated_T));

  {
    LKAS_subsystem_integrated_B.LKAS_VehStates_kqx3 =
      LKAS_subsystem_integrated_rtZLKAS_VehStates;
    LKAS_subsystem_integrated_B.IntvTyp_sLKA = LKAS_SftyLaneKeepAid;
    LKAS_subsystem_integrated_B.IntvTyp_sLKA_pzex = LKAS_SftyLaneKeepAid;
    LKAS_subsystem_integrated_B.IntvSide_sLKA = LKAS_IntvSideLe;
    LKAS_subsystem_integrated_B.IntvSide_sLKA_k4lx = LKAS_IntvSideLe;
    LKAS_subsystem_integrated_B.IntvMgrSt_sLKA = LKAS_NoIntv;
    LKAS_subsystem_integrated_B.CtrlRef_sLKA = LKAS_NoRef;
    LKAS_subsystem_integrated_B.CtrlRef_sLKA_ly5n = LKAS_NoRef;
    LKAS_subsystem_integrated_B.CtrlRef_sLKA_jpit = LKAS_NoRef;
    LKAS_subsystem_integrated_B.Out_cbrj = VldForEnag;
    LKAS_subsystem_integrated_B.Out_lr5f = VldForEnag;
  }

  /* exported global signals */
  VsLKAS_DataBus = LKAS_subsystem_integrated_rtZLKAS_DataBus;
  VfLKAS_Vlat_sLKA = 0.0F;
  VfLKAS_L_DistToCross_sLKA = 0.0F;
  VfLKAS_L_ExtraMargin_sLKA = 0.0F;
  VfLKAS_A_ALatRelLaneMkr_sLKA = 0.0F;
  VfLKAS_A_ALatRelLaneMkrLe = 0.0F;
  VfLKAS_A_ALatRelLaneMkrRi = 0.0F;
  VfLKAS_Vlong_sLKA = 0.0F;
  VfLKAS_vlat_0 = 0.0F;
  VfLKAS_alat_0 = 0.0F;
  VfLKAS_delta_pos_sLKA = 0.0F;
  VfLKAS_TimeNeeded_sLKA = 0.0F;
  VfLKAS_end_offst_sLKA = 0.0F;
  VfLKAS_dt_sLKA = 0.0F;
  VfLKAS_A0_sLKA = 0.0F;
  VfLKAS_Am_sLKA = 0.0F;
  VfLKAS_Ae_sLKA = 0.0F;
  VfLKAS_Am1 = 0.0F;
  VfLKAS_Am2 = 0.0F;
  VfLKAS_dt1 = 0.0F;
  VfLKAS_dt2 = 0.0F;
  VfLKAS_JerkNeeded_sLkA = 0.0F;
  VfLKAS_LatAccNeeded_sLKA = 0.0F;
  VfLKAS_FirstEndPos = 0.0F;
  VfLKAS_FirstEndVlat = 0.0F;
  VfLKAS_SecEndPos = 0.0F;
  VfLKAS_SecEndVlat = 0.0F;
  VfLKAS_V_Latleft = 0.0F;
  VfLKAS_L_OffstLeft = 0.0F;
  VfLKAS_Heading = 0.0F;
  VfLKAS_VLatRight = 0.0F;
  VfLKAS_OffstRi_sLKA = 0.0F;
  VfLKAS_Cr_Road = 0.0F;
  VfLKAS_LaneWidth = 0.0F;
  VfLKAS_Velocity_x = 0.0F;
  VfLKAS_yaw_rate_utm = 0.0F;
  VfLKAS_Acceleration_x = 0.0F;
  VfLKAS_Acce_y = 0.0F;
  VfLKAS_T_AftIntvStart_IntOut = 0.0F;
  VfLKAS_RiC0 = 0.0F;
  VfLKAS_RiC1 = 0.0F;
  VfLKAS_RiC2 = 0.0F;
  VfLKAS_Ri_Length = 0.0F;
  VfLKAS_L_DistToCrossRight = 0.0F;
  VfLAKS_LeC0 = 0.0F;
  VfLAKS_LeC1 = 0.0F;
  VfLKAS_LeC2 = 0.0F;
  VfLKAS_LeLength = 0.0F;
  VfLKAS_L_DisToCrossLeft = 0.0F;
  VfLKAS_T_AftIntvStart = 0.0F;
  VfLKAS_dtFreezed_sLKA = 0.0F;
  VfLKAS_AmFreezed_sLKA = 0.0F;
  VfLKAS_V0Freezed_sLKA = 0.0F;
  VfLKAS_A0Freezed_sLKA = 0.0F;
  VfLKAS_AeFreezed_sLKA = 0.0F;
  VfLKAS_Jerk2 = 0.0F;
  VfLKAS_TargetDist_Freezed2 = 0.0F;
  VfLKAS_Jerk1 = 0.0F;
  VfLKAS_TargetDist_Freezed1 = 0.0F;
  VfLKAS_TargetV = 0.0F;
  VfLKAS_Offst_Actual = 0.0F;
  VfLKAS_Offst_start = 0.0F;
  VfLKAS_DesiredDistToEdge = 0.0F;
  VfLKAS_OffstError = 0.0F;
  VfLKAS_Offst_ErrorDiff = 0.0F;
  VfLKAS_Vlat_Desired = 0.0F;
  VfLKAS_VlatError = 0.0F;
  VfLKAS_Vlat_ErrorDiff = 0.0F;
  VfLKAS_TargetA = 0.0F;
  VfLKAS_Alat_Desired = 0.0F;
  VfLKAS_YawRateDesired = 0.0F;
  VfLKAS_SteerAngleRequest = 0.0F;
  VfLKAS_StrAngFilted = 0.0F;
  VfLKAS_SteerAngleRequest_Saturated = 0.0F;
  VfLKAS_TargetA_2 = 0.0F;
  VfLKAS_TargetDist_2 = 0.0F;
  VfLKAS_TargetV_2 = 0.0F;
  VfLKAS_TargetA_1 = 0.0F;
  VfLKAS_V0Increment = 0.0F;
  VfLKAS_TargetDist_1 = 0.0F;
  VfLKAS_TargetV_1 = 0.0F;
  VfLKAS_TargetDist = 0.0F;
  VfLKAS_QlyLe = 0U;
  VfLKAS_QlyRi = 0U;
  VfLKAS_AbortID = 0U;
  VbLKAS_zero_trajectory_found = false;
  VbLKAS_LaneWidthEnbl = false;
  VbLKAS_RoadEnblRi = false;
  VbLKAS_RoadEnblLe = false;
  VbLKAS__RoadEnbl = false;
  VbLKAS_InnerCurvLe_sLKA = false;
  VbLKAS_InnerCurvRi_sLKA = false;
  VbLKAS_SolutionFoundForAm = false;
  VbLKAS_TrajectoryFound_sLKA = false;
  VbLKAS_FirstEndPositionOK = false;
  VbLKAS_FirstEndVLatOK = false;
  VbLKAS_TrajectoryFoundAm1 = false;
  VbLKAS_SecEndPositionOK = false;
  VbLKAS_SecEndVLatOK = false;
  VbLKAS_TrajectoryFoundAm2 = false;
  VbLKAS_QlyValidLe = false;
  VbLKAS_LeftVLatStep = false;
  VbLKAS_LeftCurvStep = false;
  VbLKAS_LeftOffstStep = false;
  VbLKAS_QlyValidRi = false;
  VbLKAS_RightVlatStep = false;
  VbLKAS_RightCurvStep = false;
  VbLKAS_RightOffstStep = false;
  VbLKAS_IsIntvCompleted_sLKA_IntOut = false;
  VbLKAS_IsLDWSTriggered = false;
  VbLKAS_IsPathAccPlausible = false;
  VbLKAS_IsTrajInTrigZone = false;
  VbLKAS_IsTrajectoryFound = false;
  VbLKAS_IsVlatOkForZeroPath = false;
  VbLKAS_IsTrackingIntvSide = false;
  VbLKAS_IsVlatTowardsIntvSide = false;
  VbLKAS_IsActivated_sLKA = false;
  VbLKAS_LeftChangeLane = false;
  VbLKAS_InnerCurvLe = false;
  VbLKAS_NotQualDrpLeft = false;
  VbLKAS_DlyAftAbort = false;
  VbLKAS_IsSuppLe = false;
  VbLKAS_RightChangeLane = false;
  VbLKAS_InnerCurvRi = false;
  VbLKAS_NotQualDrpRight = false;
  VbLKAS_IsSuppRi = false;
  VbLKAS_Intv_Request = false;
  VbLKAS_IsInsidePath = false;
  VbLKAS_IsVlatTowardsLaneCenter = false;
  VbLKAS_IsVmaxReached = false;
  VbLKAS_IsIntvCompleted = false;
  VbLKAS_IsAbortIntv = false;
  VbLKAS_IsDelayAftAbort = false;
  VbLKAS_Trigger_Traj_2 = false;
  VbLKAS_Trigger_Traj_1 = false;
  VeLKAS_IntvTyp_sLKA_IntOut = LKAS_SftyLaneKeepAid;
  VeLKAS_IntvTyp_sLKA = LKAS_SftyLaneKeepAid;
  VeLKAS_IntvSideReq_sLKA = LKAS_IntvSideLe;
  VeLKAS_IntvSide_sLKA_IntOut = LKAS_IntvSideLe;
  VeLKAS_IntvSide_sLKA = LKAS_IntvSideLe;
  VeLKAS_IntvMgrSt_sLKA = LKAS_NoIntv;
  VeLKAS_CtrlRefReq_sLKA = LKAS_NoRef;
  VeLKAS_CtrlRef_sLKA_IntOut = LKAS_NoRef;
  VeLKAS_CtrlRef_sLKA = LKAS_NoRef;
  VeLKAS_LineLeftOk = VldForEnag;
  VeLKAS_LineRightOK = VldForEnag;
  VeLKAS_SystemSt_sLKA = LKAS_Off;
  VeLKAS_OnStateSt_sLKA = LKAS_Enabling;

  /* states (dwork) */
  (void) memset((void *)&LKAS_subsystem_integrated_DW, 0,
                sizeof(DW_LKAS_subsystem_integrated_T));

  /* external inputs */
  LKAS_subsystem_integrated_U.VsDRIV_DataBus = LKAS_subsystem_integrated_rtZDR;

  /* SystemInitialize for Atomic SubSystem: '<Root>/LKAS_subsystem_integrated' */
  LKAS_subsystem_integrated_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/LKAS_subsystem_integrated' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
