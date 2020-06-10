/*
 * File: LDWS_subsystem_integrated.h
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

#ifndef RTW_HEADER_LDWS_subsystem_integrated_h_
#define RTW_HEADER_LDWS_subsystem_integrated_h_
#include <string.h>
#ifndef LDWS_subsystem_integrated_COMMON_INCLUDES_
# define LDWS_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LDWS_subsystem_integrated_COMMON_INCLUDES_ */

#include "LDWS_subsystem_integrated_types.h"

/* Child system includes */
#include "EnablingManager_LDW.h"
#include "LnMkrFilter_LDW.h"
#include "OutputManager_LDW.h"
#include "Road_Enable_Estimator_LDW.h"
#include "SuppressionManager_LDW.h"
#include "TriggerManager_LDW.h"
#include "WarningManager_LDW.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct
{
  real32_T RiDist;                     /* '<S4>/MATLAB Function' */
  uint8_T LeQlt;                       /* '<S4>/MATLAB Function' */
  boolean_T Switch;                    /* '<S7>/Switch' */
  boolean_T Switch1;                   /* '<S7>/Switch1' */
  EnumLDWS_wrn_mgr_st Warn_Manager_Status;/* '<S9>/Warning_Machine' */
}
B_LDWS_subsystem_integrated_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
  struct
  {
    void *LoggedData;
  }
  Scope_PWORK;                         /* '<S27>/Scope' */

  real32_T Delay_DSTATE[20];           /* '<S2>/Delay' */
  real32_T UnitDelay_DSTATE;           /* '<S23>/Unit Delay' */
  real32_T UnitDelay_DSTATE_jze2;      /* '<S24>/Unit Delay' */
  uint32_T CntOnTimer;                 /* '<S9>/Warning_Machine' */
  uint16_T UnitDelay_DSTATE_n2v1;      /* '<S36>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_o5hd;      /* '<S37>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_czjk;      /* '<S38>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_l5ms;      /* '<S39>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_kcwr;      /* '<S43>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_evoy;      /* '<S41>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_p1ve;      /* '<S40>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_jqfz;      /* '<S42>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_fakt;      /* '<S32>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_fwdu;      /* '<S33>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_jukp;      /* '<S16>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_p1mq;      /* '<S18>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_g1ck;      /* '<S15>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_oro1;      /* '<S17>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_oikr;      /* '<S19>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_o1j0;      /* '<S20>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_cieb;      /* '<S21>/UnitDelay' */
  uint16_T UnitDelay_DSTATE_pduf;      /* '<S22>/UnitDelay' */
  uint16_T CntWarn;                    /* '<S9>/Warning_Machine' */
  boolean_T UnitDelay_DSTATE_nlrv;     /* '<S14>/Unit Delay' */
  uint8_T is_active_c16_LDWS_subsystem_in;/* '<S9>/Warning_Machine' */
  uint8_T is_c16_LDWS_subsystem_integrate;/* '<S9>/Warning_Machine' */
  uint8_T is_On;                       /* '<S9>/Warning_Machine' */
  uint8_T is_Enabled;                  /* '<S9>/Warning_Machine' */
}
DW_LDWS_subsystem_integrated_T;

/* Invariant block signals (auto storage) */
typedef struct
{
  const EnumLDWS_warn_side In1;        /* '<S27>/In1' */
}
ConstB_LDWS_subsystem_integra_T;

/* Block signals (auto storage) */
extern B_LDWS_subsystem_integrated_T LDWS_subsystem_integrated_B;

/* Block states (auto storage) */
extern DW_LDWS_subsystem_integrated_T LDWS_subsystem_integrated_DW;

/* External data declarations for dependent source files */
extern const LDWS_DataBus LDWS_subsystem_integrated_rtZLDWS_DataBus;/* LDWS_DataBus ground */
extern const ConstB_LDWS_subsystem_integra_T LDWS_subsystem_integrate_ConstB;/* constant block i/o */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern LDWS_DataBus VsLDWS_DataBus;    /* '<S1>/Bus Creator2' */
extern real32_T VfLDWS_SteerAngleRate; /* '<S2>/Divide' */
extern real32_T VfLDWS_BackToRiDist;   /* '<S8>/Abs'
                                        * The distacne bewteen center of rear axle and right lane marker
                                        */
extern real32_T VfLDWS_Theta;          /* '<S49>/Switch'
                                        * The angle between linear velocity and heading
                                        */
extern real32_T VfLDWS_Vx;             /* '<S8>/Signal Conversion'
                                        * The value of Vx
                                        */
extern real32_T VfLDWS_Vy;             /* '<S8>/Signal Conversion1'
                                        * The value of Vy
                                        */
extern real32_T VfLDWS_VLatLe;         /* '<S61>/Add' */
extern real32_T VfLDWS_EdgeLaneLe;     /* '<S50>/Switch'
                                        * The vertical distacne between left front wheel and left lane marker
                                        */
extern real32_T VfLDWS_TLCLe;          /* '<S60>/Merge'
                                        * The time to collision of left side
                                        */
extern real32_T VfLDWS_EdgeLaneRi;     /* '<S50>/Switch2'
                                        * The vertical distacne between right front wheel and right lane marker
                                        */
extern real32_T VfLDWS_VLatRi;         /* '<S61>/Add1' */
extern real32_T VfLDWS_TLCRi;          /* '<S60>/Merge1'
                                        * The time to collision of right side
                                        */
extern real32_T VfLDWS_SteerAngle;     /* '<S8>/Signal Conversion2'
                                        * The vehicle's steering angle
                                        */
extern real32_T VfLDWS_SteerTorque;    /* '<S7>/Signal Conversion2' */
extern real32_T VfLDWS_Curvature;      /* '<S4>/Gain' */
extern real32_T VfLDWS_LeC0Filtd;      /* '<S23>/Switch1'
                                        * The C0 coefficient of left lane marker after filtering
                                        */
extern real32_T VfLDWS_RiC0Filtd;      /* '<S24>/Switch1'
                                        * The C0 coefficient of right lane marker after filtering
                                        */
extern real32_T VfLDWS_LeC1Filtd;      /* '<S4>/MATLAB Function'
                                        * The C1 coefficient of left lane marker after filtering
                                        */
extern real32_T VfLDWS_RiC1Filtd;      /* '<S4>/MATLAB Function'
                                        * The C1 coefficient of right lane marker after filtering
                                        */
extern real32_T VfLDWS_BackToLeDist;   /* '<S4>/MATLAB Function'
                                        * The distacne bewteen center of rear axle and left lane marker
                                        */
extern boolean_T VbLDWS_IsOnLeLine;    /* '<S51>/Switch1'
                                        * The vehicle is on left lane marker or not
                                        */
extern boolean_T VbLDWS_LeadDrctn;     /* '<S47>/Switch'
                                        * The heading of vehicle is left or right. True is on left, fale is on right.
                                        */
extern boolean_T VbLDWS_ActLeLDW;      /* '<S8>/Switch'
                                        * The left LDW is whether trggered or not
                                        */
extern boolean_T VbLDWS_IsOnRiLine;    /* '<S52>/Switch2'
                                        * The vehicle is on right lane marker or not
                                        */
extern boolean_T VbLDWS_ActRiLDW;      /* '<S8>/Switch1'
                                        * The right LDW is whether triggered or not
                                        */
extern boolean_T VbLDWS_LeIndicatorSt; /* '<S7>/Signal Conversion'
                                        * The status of right indicator
                                        */
extern boolean_T VbLDWS_SuppLe;        /* '<S34>/Logical Operator'
                                        * The left LDW is whether suppressed or not
                                        */
extern boolean_T VbLDWS_RiIndicatorSt; /* '<S7>/Signal Conversion1'
                                        * The status of right indicator
                                        */
extern boolean_T VbLDWS_SuppRi;        /* '<S35>/Logical Operator1'
                                        * The right LDW is whether suppressed or not
                                        */
extern boolean_T VbLDWS_RdEnblLe;      /* '<S30>/Switch'
                                        * The left Lane Marker is whether enabled or not
                                        */
extern boolean_T VbLDWS_RdEnblRi;      /* '<S31>/Switch1'
                                        * The right Lane Marker is whether enabled or not
                                        */
extern boolean_T VbLDWS_WrnSt;         /* '<S5>/Merge'
                                        * The warning is whether issued or not
                                        */
extern boolean_T VbLDWS_EnabledLDW;    /* '<S13>/LogOp3'
                                        * The system is whether enabled or not
                                        */
extern boolean_T VbLDWS_SpdRngValid;   /* '<S3>/MATLAB Function1'
                                        * The ODD of speed range is whether fullfiled
                                        */
extern boolean_T VbLDWS_CurvValid;     /* '<S3>/MATLAB Function'
                                        * The ODD of lane curvature is whether fullfiled
                                        */
extern boolean_T VbLDWS_WidthValid;    /* '<S3>/MATLAB Function'
                                        * The ODD of lane width is whether fullfiled
                                        */
extern boolean_T VbLDWS_LnMkrValid;    /* '<S3>/MATLAB Function'
                                        * The ODD of lane marker is whether fullfiled
                                        */
extern EnumLDWS_la_detec_st VeLDWS_LaDetecSt;/* '<S5>/Truth Table' */
extern EnumLDWS_warn_side VeLDWS_WrnSd;/* '<S5>/Merge1' */
extern EnumLDWS_system_st VeLDWS_SysSt;/* '<S9>/Warning_Machine' */
extern EnumLDWS_on_state_st VeLDWS_OnStateSt;/* '<S9>/Warning_Machine' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T KfLDWS_Ang_BkToCnrAng; /* Variable: KfLDWS_Ang_BkToCnrAng
                                        * Referenced by:
                                        *   '<S50>/Constant3'
                                        *   '<S50>/Constant4'
                                        * The angle X axis and the line connecting center of rear axle and front tire.
                                        */
extern real32_T KfLDWS_Ang_SuppSteerAngThrsh;/* Variable: KfLDWS_Ang_SuppSteerAngThrsh
                                              * Referenced by:
                                              *   '<S34>/Constant5'
                                              *   '<S35>/Constant14'
                                              * The suppression threshold for Steer Angle
                                              */
extern real32_T KfLDWS_M_SuppTorque;   /* Variable: KfLDWS_M_SuppTorque
                                        * Referenced by:
                                        *   '<S34>/Constant1'
                                        *   '<S35>/Constant1'
                                        * The torque limit that could be treated as suppression
                                        */
extern real32_T KfLDWS_c_CurvLwrBnd;   /* Variable: KfLDWS_c_CurvLwrBnd
                                        * Referenced by: '<S3>/Constant1'
                                        * The curvature upper bound for ODD
                                        */
extern real32_T KfLDWS_c_CurvUprBnd;   /* Variable: KfLDWS_c_CurvUprBnd
                                        * Referenced by:
                                        *   '<S3>/Constant'
                                        *   '<S50>/Switch1'
                                        *   '<S50>/Switch3'
                                        * The curvature lower bound for ODD
                                        */
extern real32_T KfLDWS_d_BkToFrtCnrDist;/* Variable: KfLDWS_d_BkToFrtCnrDist
                                         * Referenced by:
                                         *   '<S50>/Constant1'
                                         *   '<S50>/Constant2'
                                         * The distance between one fo the front tires to the center of rear axle.
                                         */
extern real32_T KfLDWS_d_EdgBuff;      /* Variable: KfLDWS_d_EdgBuff
                                        * Referenced by:
                                        *   '<S50>/Constant'
                                        *   '<S50>/Constant5'
                                        *   '<S50>/Constant8'
                                        *   '<S50>/Constant9'
                                        * The edge buffer that added to the calcualted distance to lane markers
                                        */
extern real32_T KfLDWS_d_LnWidthLwrBnd;/* Variable: KfLDWS_d_LnWidthLwrBnd
                                        * Referenced by: '<S3>/Constant3'
                                        * The lane width lower bound for ODD
                                        */
extern real32_T KfLDWS_d_LnWidthUprBnd;/* Variable: KfLDWS_d_LnWidthUprBnd
                                        * Referenced by: '<S3>/Constant2'
                                        * The lane width upper bound for ODD
                                        */
extern real32_T KfLDWS_d_WarnLineLvlOne;/* Variable: KfLDWS_d_WarnLineLvlOne
                                         * Referenced by:
                                         *   '<S51>/Constant1'
                                         *   '<S52>/Constant1'
                                         * When vehicle speed is higher than 1.0m/s, the earliest warning line shall be placed no more than 1.5m inside the lane boundary.
                                         */
extern real32_T KfLDWS_d_WarnLineLvlThree;/* Variable: KfLDWS_d_WarnLineLvlThree
                                           * Referenced by:
                                           *   '<S51>/Constant2'
                                           *   '<S52>/Constant2'
                                           * When vehicle speed is not higher than 0.5 m/s, the earliest warning line shall be placed no more than 0.75m inside the lane boundary.
                                           */
extern real32_T KfLDWS_k_CurvBuffCoe;  /* Variable: KfLDWS_k_CurvBuffCoe
                                        * Referenced by:
                                        *   '<S50>/Constant6'
                                        *   '<S50>/Constant7'
                                        * The coefficient that multiples the distance to lanemarker when the vehicle is driving under large curavture.
                                        */
extern real32_T KfLDWS_k_WarnLineLvlTwo;/* Variable: KfLDWS_k_WarnLineLvlTwo
                                         * Referenced by:
                                         *   '<S51>/Constant3'
                                         *   '<S52>/Constant3'
                                         * When vehicle speed is higher than 0.5m/s but not  higher than 1.0m/s, the earliest warning line shall be placed no more than 1.5*Va m inside the lane boundary
                                         */
extern real32_T KfLDWS_t_TLCThrsh;     /* Variable: KfLDWS_t_TLCThrsh
                                        * Referenced by:
                                        *   '<S44>/Constant6'
                                        *   '<S45>/Constant6'
                                        * Time to lane crossing threshold
                                        */
extern real32_T KfLDWS_v_SpdLwrBnd;    /* Variable: KfLDWS_v_SpdLwrBnd
                                        * Referenced by: '<S3>/Constant5'
                                        * The speed lower bound for ODD
                                        */
extern real32_T KfLDWS_v_SpdUprBnd;    /* Variable: KfLDWS_v_SpdUprBnd
                                        * Referenced by: '<S3>/Constant4'
                                        * The speed upper bound for ODD
                                        */
extern real32_T KfLDWS_v_SuppSteerRateThrsh;/* Variable: KfLDWS_v_SuppSteerRateThrsh
                                             * Referenced by:
                                             *   '<S34>/Constant2'
                                             *   '<S35>/Constant11'
                                             * The suppression threshold for Steer Rate
                                             */
extern uint16_T KcLDWS_CntSample;      /* Variable: KcLDWS_CntSample
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
extern uint16_T KfLDWS_t_CntMaxWarnHold;/* Variable: KfLDWS_t_CntMaxWarnHold
                                         * Referenced by: '<S9>/Constant'
                                         * The maximum time that a warning satte is allowed to last
                                         */
extern uint16_T KfLDWS_t_CntMinWarnHold;/* Variable: KfLDWS_t_CntMinWarnHold
                                         * Referenced by: '<S9>/Constant1'
                                         * The minimum time that a warning state shall last.
                                         */
extern uint16_T KfLDWS_t_CntOnHold;    /* Variable: KfLDWS_t_CntOnHold
                                        * Referenced by: '<S9>/Constant2'
                                        * The bouncing time that avoids wrong trigger.
                                        */
extern uint16_T KfLDWS_t_CurvNotValidTime;/* Variable: KfLDWS_t_CurvNotValidTime
                                           * Referenced by: '<S12>/Constant15'
                                           * The time that Enabling Manager uses to reset condition for curvature
                                           */
extern uint16_T KfLDWS_t_CurvValidTime;/* Variable: KfLDWS_t_CurvValidTime
                                        * Referenced by: '<S14>/Constant7'
                                        * The time that Enabling Manager uses to set condition for curvature
                                        */
extern uint16_T KfLDWS_t_LnMkrMissThrsh;/* Variable: KfLDWS_t_LnMkrMissThrsh
                                         * Referenced by:
                                         *   '<S30>/Constant'
                                         *   '<S31>/Constant'
                                         * The maximum time that a lane marker could termporarily go missing
                                         */
extern uint16_T KfLDWS_t_LnMkrNotValidTime;/* Variable: KfLDWS_t_LnMkrNotValidTime
                                            * Referenced by: '<S12>/Constant20'
                                            * The time that Enabling Manager uses set condion for lane marker
                                            */
extern uint16_T KfLDWS_t_LnMkrValidTime;/* Variable: KfLDWS_t_LnMkrValidTime
                                         * Referenced by: '<S14>/Constant9'
                                         * The time that Enabling Manager uses reset condition for lane marker
                                         */
extern uint16_T KfLDWS_t_LnWidthNotValidTime;/* Variable: KfLDWS_t_LnWidthNotValidTime
                                              * Referenced by: '<S12>/Constant16'
                                              * The time that Enabling Manager uses to reset condition for lane width
                                              */
extern uint16_T KfLDWS_t_LnWidthValidTime;/* Variable: KfLDWS_t_LnWidthValidTime
                                           * Referenced by: '<S14>/Constant8'
                                           * The time that enabling manager uses to set condition for lane width
                                           */
extern uint16_T KfLDWS_t_SpdRngNotValidTime;/* Variable: KfLDWS_t_SpdRngNotValidTime
                                             * Referenced by: '<S12>/Constant14'
                                             * The time that enabling manager uses to reset condition for speed range
                                             */
extern uint16_T KfLDWS_t_SpdRngValidTime;/* Variable: KfLDWS_t_SpdRngValidTime
                                          * Referenced by: '<S14>/Constant6'
                                          * The time that enabling manager uses to set condtion for speed range
                                          */
extern uint16_T KfLDWS_t_SuppIndiTime; /* Variable: KfLDWS_t_SuppIndiTime
                                        * Referenced by:
                                        *   '<S34>/Constant10'
                                        *   '<S35>/Constant10'
                                        * The time that indicator could be treated as suppression
                                        */
extern uint16_T KfLDWS_t_SuppSteerAngTime;/* Variable: KfLDWS_t_SuppSteerAngTime
                                           * Referenced by:
                                           *   '<S34>/Constant6'
                                           *   '<S35>/Constant6'
                                           * The time that steer angle could be treated as suppression
                                           */
extern uint16_T KfLDWS_t_SuppSteerRateTime;/* Variable: KfLDWS_t_SuppSteerRateTime
                                            * Referenced by:
                                            *   '<S34>/Constant4'
                                            *   '<S35>/Constant4'
                                            * The time that steer rate could be treated as suppression
                                            */
extern uint16_T KfLDWS_t_SuppTorqueTime;/* Variable: KfLDWS_t_SuppTorqueTime
                                         * Referenced by:
                                         *   '<S34>/Constant12'
                                         *   '<S35>/Constant12'
                                         * The time that steer toque could be treated as suppression
                                         */
extern uint8_T KfLDWS_r_LaMkrQlt;      /* Variable: KfLDWS_r_LaMkrQlt
                                        * Referenced by:
                                        *   '<S30>/Constant2'
                                        *   '<S31>/Constant2'
                                        * Lane marker quality threshold
                                        */
extern boolean_T KbLDWS_EnableSwitch;  /* Variable: KbLDWS_EnableSwitch
                                        * Referenced by: '<S9>/Constant5'
                                        */
extern boolean_T KbLDWS_SuppLeSwitch;  /* Variable: KbLDWS_SuppLeSwitch
                                        * Referenced by: '<S7>/Constant1'
                                        */
extern boolean_T KbLDWS_SuppRiSwitch;  /* Variable: KbLDWS_SuppRiSwitch
                                        * Referenced by: '<S7>/Constant3'
                                        */
extern boolean_T KbLDWS_ThetaSwitch;   /* Variable: KbLDWS_ThetaSwitch
                                        * Referenced by: '<S49>/Constant'
                                        */

/* Model entry point functions */
extern void LDWS_subsystem_integrated_initialize(void);
extern void LDWS_subsystem_integrated_step(void);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'LDWS_subsystem_integrated'
 * '<S1>'   : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated'
 * '<S2>'   : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/Derivation'
 * '<S3>'   : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW'
 * '<S4>'   : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/LnMkrFilter_LDW'
 * '<S5>'   : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/OutputManager_LDW'
 * '<S6>'   : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/Road_Enable_Estimator_LDW'
 * '<S7>'   : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/SuppressionManager_LDW'
 * '<S8>'   : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW'
 * '<S9>'   : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/WarningManager_LDW'
 * '<S10>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/MATLAB Function'
 * '<S11>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/MATLAB Function1'
 * '<S12>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/ResetCondition'
 * '<S13>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/SR_FF'
 * '<S14>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/SetCondition'
 * '<S15>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/ResetCondition/OnDelayBlock1'
 * '<S16>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/ResetCondition/OnDelayBlock2'
 * '<S17>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/ResetCondition/OnDelayBlock3'
 * '<S18>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/ResetCondition/OnDelayBlock5'
 * '<S19>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/SetCondition/OnDelayBlock1'
 * '<S20>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/SetCondition/OnDelayBlock2'
 * '<S21>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/SetCondition/OnDelayBlock3'
 * '<S22>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/EnablingManager_LDW/SetCondition/OnDelayBlock4'
 * '<S23>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/LnMkrFilter_LDW/Filter_Left'
 * '<S24>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/LnMkrFilter_LDW/Filter_Right'
 * '<S25>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/LnMkrFilter_LDW/MATLAB Function'
 * '<S26>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/OutputManager_LDW/Switch Case Action Subsystem'
 * '<S27>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/OutputManager_LDW/Switch Case Action Subsystem1'
 * '<S28>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/OutputManager_LDW/Switch Case Action Subsystem2'
 * '<S29>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/OutputManager_LDW/Truth Table'
 * '<S30>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/Road_Enable_Estimator_LDW/Subsystem'
 * '<S31>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/Road_Enable_Estimator_LDW/Subsystem1'
 * '<S32>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/Road_Enable_Estimator_LDW/Subsystem/OnDelayBlock1'
 * '<S33>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/Road_Enable_Estimator_LDW/Subsystem1/OnDelayBlock1'
 * '<S34>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/SuppressionManager_LDW/DtrmnSuppLe'
 * '<S35>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/SuppressionManager_LDW/DtrmnSuppRi'
 * '<S36>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/SuppressionManager_LDW/DtrmnSuppLe/OnDelayBlock1'
 * '<S37>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/SuppressionManager_LDW/DtrmnSuppLe/OnDelayBlock2'
 * '<S38>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/SuppressionManager_LDW/DtrmnSuppLe/OnDelayBlock3'
 * '<S39>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/SuppressionManager_LDW/DtrmnSuppLe/OnDelayBlock4'
 * '<S40>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/SuppressionManager_LDW/DtrmnSuppRi/OnDelayBlock1'
 * '<S41>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/SuppressionManager_LDW/DtrmnSuppRi/OnDelayBlock2'
 * '<S42>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/SuppressionManager_LDW/DtrmnSuppRi/OnDelayBlock3'
 * '<S43>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/SuppressionManager_LDW/DtrmnSuppRi/OnDelayBlock4'
 * '<S44>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/DtrmnActLe'
 * '<S45>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/DtrmnActRi'
 * '<S46>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/LanePositionConstraint'
 * '<S47>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/LeadDirectionCondition'
 * '<S48>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/TTLCondition'
 * '<S49>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/ThetaCalc'
 * '<S50>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/VehicleToBdlnCalc'
 * '<S51>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/LanePositionConstraint/DtrmnIsOnLeLine'
 * '<S52>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/LanePositionConstraint/DtrmnIsOnRiLine'
 * '<S53>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/LanePositionConstraint/DtrmnIsOnLeLine/If Action Subsystem4'
 * '<S54>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/LanePositionConstraint/DtrmnIsOnLeLine/If Action Subsystem5'
 * '<S55>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/LanePositionConstraint/DtrmnIsOnLeLine/If Action Subsystem6'
 * '<S56>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/LanePositionConstraint/DtrmnIsOnRiLine/If Action Subsystem4'
 * '<S57>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/LanePositionConstraint/DtrmnIsOnRiLine/If Action Subsystem5'
 * '<S58>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/LanePositionConstraint/DtrmnIsOnRiLine/If Action Subsystem6'
 * '<S59>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/LeadDirectionCondition/v_lat_calculation'
 * '<S60>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/TTLCondition/TLC_calculation'
 * '<S61>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/TTLCondition/v_lat_calculation'
 * '<S62>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/TTLCondition/TLC_calculation/If Action Subsystem'
 * '<S63>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/TTLCondition/TLC_calculation/If Action Subsystem1'
 * '<S64>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/TTLCondition/TLC_calculation/If Action Subsystem2'
 * '<S65>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/TTLCondition/TLC_calculation/If Action Subsystem3'
 * '<S66>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/ThetaCalc/theta_calculation'
 * '<S67>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/VehicleToBdlnCalc/Edge _Calculation_Left'
 * '<S68>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/VehicleToBdlnCalc/Edge _Calculation_Right'
 * '<S69>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/VehicleToBdlnCalc/Edge _Calculation_Left/Left_Edge_Calculation'
 * '<S70>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/TriggerManager_LDW/VehicleToBdlnCalc/Edge _Calculation_Right/Right_Edge_Calculation'
 * '<S71>'  : 'LDWS_subsystem_integrated/LDWS_subsystem_integrated/WarningManager_LDW/Warning_Machine'
 */
#endif                                 /* RTW_HEADER_LDWS_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
