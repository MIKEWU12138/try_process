/*
 * File: COMM_subsystem_integrated.h
 *
 * Code generated for Simulink model 'COMM_subsystem_integrated'.
 *
 * Model version                  : 1.1787
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 09:20:56 2020
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

#ifndef RTW_HEADER_COMM_subsystem_integrated_h_
#define RTW_HEADER_COMM_subsystem_integrated_h_
#include <string.h>
#ifndef COMM_subsystem_integrated_COMMON_INCLUDES_
# define COMM_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "can_message.h"
#endif                                 /* COMM_subsystem_integrated_COMMON_INCLUDES_ */

#include "COMM_subsystem_integrated_types.h"

/* Child system includes */
#include "comm_receive.h"
#include "comm_transmit.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct
{
  CAN_MESSAGE_BUS CAN_Pack;            /* '<S43>/CAN_Pack' */
  CAN_MESSAGE_BUS EBS_Control;         /* '<S37>/EBS_Control' */
  CAN_MESSAGE_BUS Low_Voltage_Distribution_Contro;/* '<S37>/Low_Voltage_Distribution_Control' */
  CAN_MESSAGE_BUS Vehicle_Control;     /* '<S37>/Vehicle_Control' */
  CAN_MESSAGE_BUS Config_3_Transmit_CAN_0_ID_581;/* '<S41>/Config_3_Transmit_CAN_0_ID_581' */
  CAN_MESSAGE_BUS Config_3_Transmit_CAN_1_ID_550;/* '<S41>/Config_3_Transmit_CAN_1_ID_550' */
  CAN_MESSAGE_BUS Config_2_Transmit_CAN_2_ID_193;/* '<S45>/Config_2_Transmit_CAN_2_ID_193' */
  CAN_MESSAGE_BUS Config_1_Transmit_CAN_2_ID_193;/* '<S44>/Config_1_Transmit_CAN_2_ID_193' */
  real_T BUS_BCUState_o1;              /* '<S15>/BUS_BCUState' */
  real_T BUS_BCUState_o2;              /* '<S15>/BUS_BCUState' */
  real_T BUS_BCUState1_o1;             /* '<S15>/BUS_BCUState1' */
  real_T BUS_BCUState3_o1;             /* '<S15>/BUS_BCUState3' */
  real_T BUS_BCUState3_o2;             /* '<S15>/BUS_BCUState3' */
  real_T BUS_BCUState3_o3;             /* '<S15>/BUS_BCUState3' */
  real_T BUS_BCUState3_o4;             /* '<S15>/BUS_BCUState3' */
  real_T BUS_BCUState4;                /* '<S15>/BUS_BCUState4' */
  real_T BUS_BCUState5;                /* '<S15>/BUS_BCUState5' */
  real_T Vehicle_Message_1_o1;         /* '<S4>/Vehicle_Message_1' */
  real_T Vehicle_Message_1_o2;         /* '<S4>/Vehicle_Message_1' */
  real_T Vehicle_Message_1_o3;         /* '<S4>/Vehicle_Message_1' */
  real_T Vehicle_Message_1_o4;         /* '<S4>/Vehicle_Message_1' */
  real_T Vehicle_Message_1_o5;         /* '<S4>/Vehicle_Message_1' */
  real_T Vehicle_Message_1_o6;         /* '<S4>/Vehicle_Message_1' */
  real_T Vehicle_Message_1_o7;         /* '<S4>/Vehicle_Message_1' */
  real_T Vehicle_Message_1_o8;         /* '<S4>/Vehicle_Message_1' */
  real_T ESC_Message_o1;               /* '<S4>/ESC_Message' */
  real_T ESC_Message_o2;               /* '<S4>/ESC_Message' */
  real_T ESC_Message_o3;               /* '<S4>/ESC_Message' */
  real_T ESC_Message_o4;               /* '<S4>/ESC_Message' */
  real_T ESC_Message_o5;               /* '<S4>/ESC_Message' */
  real_T ESC_Message_o6;               /* '<S4>/ESC_Message' */
  real_T Vehicle_Message_2_o1;         /* '<S4>/Vehicle_Message_2' */
  real_T Vehicle_Message_2_o2;         /* '<S4>/Vehicle_Message_2' */
  real_T Vehicle_Message_2_o3;         /* '<S4>/Vehicle_Message_2' */
  real_T Vehicle_Message_2_o4;         /* '<S4>/Vehicle_Message_2' */
  real_T Vehicle_Message_2_o5;         /* '<S4>/Vehicle_Message_2' */
  real_T Vehicle_Message_2_o6;         /* '<S4>/Vehicle_Message_2' */
  real_T Vehicle_Message_2_o7;         /* '<S4>/Vehicle_Message_2' */
  real_T Vehicle_Message_2_o8;         /* '<S4>/Vehicle_Message_2' */
  real_T Vehicle_Message_2_o9;         /* '<S4>/Vehicle_Message_2' */
  real_T EBS_WheelSpeed_o1;            /* '<S4>/EBS_WheelSpeed' */
  real_T EBS_WheelSpeed_o2;            /* '<S4>/EBS_WheelSpeed' */
  real_T EBS_WheelSpeed_o3;            /* '<S4>/EBS_WheelSpeed' */
  real_T EBS_WheelSpeed_o4;            /* '<S4>/EBS_WheelSpeed' */
  real_T EBS_WheelSpeed_o5;            /* '<S4>/EBS_WheelSpeed' */
  real_T EBS_WheelSpeed_o6;            /* '<S4>/EBS_WheelSpeed' */
  real_T VCU_ICPV_ATOModFb;            /* '<S5>/VCU_ICPV_CAN_00' */
  real_T VCU_ICPV_AccPelSta;           /* '<S5>/VCU_ICPV_CAN_00' */
  real_T VCU_ICPV_BrkPelSta;           /* '<S5>/VCU_ICPV_CAN_00' */
  real_T VCU_ICPV_VCUSta;              /* '<S5>/VCU_ICPV_CAN_00' */
  real_T VCU_ICPV_CruiseSwitchSts;     /* '<S5>/VCU_ICPV_CAN_01' */
  real_T VCU_IPCV_BrkLgtSts;           /* '<S5>/VCU_ICPV_CAN' */
  real_T VCU1_ICPV_BackDoorSts;        /* '<S5>/VCU1_ICPV_CAN_00' */
  real_T VCU1_ICPV_DrvDoorStatus;      /* '<S5>/VCU1_ICPV_CAN_00' */
  real_T VCU1_ICPV_HeadLampHighBeam;   /* '<S5>/VCU1_ICPV_CAN_00' */
  real_T VCU1_ICPV_HeadLampLowBeam;    /* '<S5>/VCU1_ICPV_CAN_00' */
  real_T VCU1_ICPV_PsgDoorStatus;      /* '<S5>/VCU1_ICPV_CAN_00' */
  real_T VCU1_ICPV_RLDoorStatus;       /* '<S5>/VCU1_ICPV_CAN_00' */
  real_T VCU1_ICPV_RRDoorStatus;       /* '<S5>/VCU1_ICPV_CAN_00' */
  real_T VCU1_ICPV_StrAngleSpdDir;     /* '<S5>/VCU1_ICPV_CAN_01' */
  real_T VCU1_ICPV_VehSpd;             /* '<S5>/VCU1_ICPV_CAN_04' */
  real_T VCU1_ICPV_DirIndicationLH;    /* '<S5>/VCU1_ICPV_CAN_05' */
  real_T VCU1_ICPV_DirIndicationRH;    /* '<S5>/VCU1_ICPV_CAN_05' */
  real_T VCU1_ICPV_EPSDir;             /* '<S5>/VCU1_ICPV_CAN_06' */
  real_T VCU1_ICPV_EPSMODE;            /* '<S5>/VCU1_ICPV_CAN_06' */
  real_T VCU1_ICPV_StrAngle;           /* '<S5>/VCU1_ICPV_CAN_06' */
  real_T VCU_ICPV_VCUGearLevPos;       /* '<S5>/VCU_ICPV_CAN_02' */
  real_T PCU_ICPV_TMDirSts;            /* '<S5>/PCU_ICPV_CAN' */
  real_T EPSHWVer;                     /* '<S5>/VCU1_ICPV_CAN_1' */
  real_T EPSSWVer;                     /* '<S5>/VCU1_ICPV_CAN_1' */
  real_T ABS_FrP01_RollingCounter_o3;  /* '<S18>/ABS_FrP01_RollingCounter' */
  real_T ESC_FrP01_BrkPress_AccValue_o2;/* '<S18>/ESC_FrP01_BrkPress_AccValue' */
  real_T Decs_FedBck_BrkPedSts;        /* '<S18>/Veh_MCCU_01' */
  real_T Decs_FedBck_Drivemod;         /* '<S18>/Veh_MCCU_01' */
  real_T Decs_FedBck_EPSmod;           /* '<S18>/Veh_MCCU_01' */
  real_T Decs_FedBck_ESCmod;           /* '<S18>/Veh_MCCU_01' */
  real_T Decs_FedBck_GearValue;        /* '<S18>/Veh_MCCU_01' */
  real_T Decs_FedBck_Keystate;         /* '<S18>/Veh_MCCU_01' */
  real_T Decs_FedBck_StrAngle;         /* '<S18>/Veh_MCCU_01' */
  real_T Decs_FedBck_VehSpd;           /* '<S18>/Veh_MCCU_01' */
  real_T DriverModeComd;               /* '<S18>/VCU_EVCAN_F08_DriveMode' */
  real_T ESC_FrP01_YawRate;            /* '<S18>/ESC_FrP01_YawRate' */
  real_T ABS_FrP01_RollingCounter_o_fc4u;/* '<S17>/ABS_FrP01_RollingCounter' */
  real_T ESC_FrP01_o2;                 /* '<S17>/ESC_FrP01' */
  real_T Decs_FedBck_BrkPedSts_nttx;   /* '<S17>/Veh_MCCU_01' */
  real_T Decs_FedBck_Drivemod_mpet;    /* '<S17>/Veh_MCCU_01' */
  real_T Decs_FedBck_EPSmod_ejux;      /* '<S17>/Veh_MCCU_01' */
  real_T Decs_FedBck_ESCmod_gpcj;      /* '<S17>/Veh_MCCU_01' */
  real_T Decs_FedBck_GearValue_du1v;   /* '<S17>/Veh_MCCU_01' */
  real_T Decs_FedBck_Keystate_cil1;    /* '<S17>/Veh_MCCU_01' */
  real_T Decs_FedBck_StrAngle_jsjb;    /* '<S17>/Veh_MCCU_01' */
  real_T Decs_FedBck_VehSpd_nhc2;      /* '<S17>/Veh_MCCU_01' */
  real_T ESC_FrP01_YawRate_jnwb;       /* '<S17>/ESC_FrP01_YawRate' */
  real32_T Gain;                       /* '<S43>/Gain' */
  real32_T Gain1;                      /* '<S43>/Gain1' */
  real32_T Abs;                        /* '<S41>/Abs' */
  real32_T Decs_Breake_Value;          /* '<S45>/Gain1' */
  real32_T Decs_Breake_Value_jnah;     /* '<S44>/Gain1' */
  real32_T Decs_SteeringAngle;         /* '<S44>/Gain' */
  real32_T BUS_BCUState1_o2;           /* '<S15>/BUS_BCUState1' */
  real32_T BUS_BCUState2_o1;           /* '<S15>/BUS_BCUState2' */
  real32_T BUS_BCUState2_o2;           /* '<S15>/BUS_BCUState2' */
  real32_T BUS_BCUState2_o3;           /* '<S15>/BUS_BCUState2' */
  real32_T VCU_ICPV_AccPelPosFb;       /* '<S5>/VCU_ICPV_CAN_00' */
  real32_T VCU_ICPV_BrkPelPosFb;       /* '<S5>/VCU_ICPV_CAN_00' */
  real32_T VUC_ICPV_AccPed;            /* '<S5>/VCU_ICPV_CAN_03' */
  real32_T VUC_ICPV_BrkPed;            /* '<S5>/VCU_ICPV_CAN_03' */
  real32_T VCU1_ICPV_StrAngleSpd;      /* '<S5>/VCU1_ICPV_CAN_01' */
  real32_T VCU1_ICPV_ESCWhlFLSpd;      /* '<S5>/VCU1_ICPV_CAN_02' */
  real32_T VCU1_ICPV_ESCWhlFRSpd;      /* '<S5>/VCU1_ICPV_CAN_02' */
  real32_T VCU1_ICPV_ESCWhlRLSpd;      /* '<S5>/VCU1_ICPV_CAN_02' */
  real32_T VCU1_ICPV_ESCWhlRRSpd;      /* '<S5>/VCU1_ICPV_CAN_02' */
  real32_T VCU1_ICPV_LongAcc;          /* '<S5>/VCU1_ICPV_CAN_03' */
  real32_T VCU1_ICPV_YawRate;          /* '<S5>/VCU1_ICPV_CAN_03' */
  real32_T VCU1_ICPV_StrAngleFb;       /* '<S5>/VCU1_ICPV_CAN_06' */
  real32_T ESC_FrP01_BrkPress_AccValue_o1;/* '<S18>/ESC_FrP01_BrkPress_AccValue' */
  real32_T ESC_FrP01_BrkPress_AccValue_o3;/* '<S18>/ESC_FrP01_BrkPress_AccValue' */
  real32_T AccPed;                     /* '<S18>/VCU_FrP07_AccPed' */
  real32_T EPS_SteeringTorqueAct;      /* '<S18>/EPS_02_SteeringTorque' */
  real32_T ESC_FrP01_o1;               /* '<S17>/ESC_FrP01' */
  real32_T ESC_FrP01_o3;               /* '<S17>/ESC_FrP01' */
  real32_T AccPed_dvek;                /* '<S17>/VCU_HSC_FrP07' */
  real32_T EPS_SteeringTorqueAct_bnll; /* '<S17>/EPS_02_SteeringTorque' */
  uint32_T DataTypeConversion15;       /* '<S41>/Data Type Conversion15' */
  uint32_T ABS_FrP01_RollingCounter_o1;/* '<S18>/ABS_FrP01_RollingCounter' */
  uint32_T ABS_FrP01_RollingCounter_o2;/* '<S18>/ABS_FrP01_RollingCounter' */
  uint32_T ABS_FrP01_RollingCounter_o_nlod;/* '<S17>/ABS_FrP01_RollingCounter' */
  uint32_T ABS_FrP01_RollingCounter_o_hv3k;/* '<S17>/ABS_FrP01_RollingCounter' */
  uint8_T veh_Gear_Value_des;          /* '<S41>/Merge' */
  uint8_T DataTypeConversion13;        /* '<S41>/Data Type Conversion13' */
  uint8_T Subtract1;                   /* '<S41>/Subtract1' */
  uint8_T DataTypeConversion11;        /* '<S41>/Data Type Conversion11' */
  uint8_T Subtract;                    /* '<S41>/Subtract' */
  uint8_T Switch1;                     /* '<S41>/Switch1' */
  uint8_T DataTypeConversion1;         /* '<S41>/Data Type Conversion1' */
  uint8_T Merge;                       /* '<S45>/Merge' */
  uint8_T Merge_lfml;                  /* '<S44>/Merge' */
  uint8_T VCU_ICPV_TgtSftFb;           /* '<S5>/VCU_ICPV_CAN_00' */
  uint8_T VCU_ICPV_CruiseControlSts;   /* '<S5>/VCU_ICPV_CAN_01' */
  uint8_T VCU_ICPV_EPBSysVCU;          /* '<S5>/VCU_ICPV_CAN_01' */
  uint8_T Decs_FedBck_EPBstate;        /* '<S18>/Veh_MCCU_01' */
  uint8_T Decs_FedBck_EPBstate_hzkd;   /* '<S17>/Veh_MCCU_01' */
  boolean_T DataTypeConversion9;       /* '<S37>/Data Type Conversion9' */
  boolean_T Switch;                    /* '<S41>/Switch' */
  boolean_T Decs_Acc_Req;              /* '<S45>/Data Type Conversion7' */
  boolean_T Decs_Breake_Req;           /* '<S45>/Data Type Conversion6' */
  boolean_T Decs_Gear_Req;             /* '<S45>/Data Type Conversion5' */
  boolean_T Decs_Steering_Req;         /* '<S45>/Data Type Conversion8' */
  boolean_T Decs_iBCM_Req;             /* '<S45>/Logical Operator' */
  boolean_T Decs_Acc_Req_ewfe;         /* '<S44>/Data Type Conversion7' */
  boolean_T Decs_Breake_Req_kolp;      /* '<S44>/Data Type Conversion6' */
  boolean_T Decs_Gear_Req_j1ga;        /* '<S44>/Data Type Conversion5' */
  boolean_T Decs_Steering_Req_bjr4;    /* '<S44>/Data Type Conversion8' */
  boolean_T Decs_iBCM_Req_prls;        /* '<S44>/Logical Operator' */
  B_MedianFilter1_COMM_subsyste_T MedianFilter1_pnaevvf;
  B_MedianFilter1_COMM_subsyste_T MedianFilter1_pnaevv;
  B_MedianFilter1_COMM_subsyste_T MedianFilter1_pnaev;
  B_MedianFilter1_COMM_subsyste_T MedianFilter1_pnae;
  B_MedianFilter1_COMM_subsyste_T MedianFilter1;
}
B_COMM_subsystem_integrated_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
  int_T CAN_Pack_ModeSignalID;         /* '<S43>/CAN_Pack' */
  int_T EBS_Control_ModeSignalID;      /* '<S37>/EBS_Control' */
  int_T Low_Voltage_Distribution_Contro;/* '<S37>/Low_Voltage_Distribution_Control' */
  int_T Vehicle_Control_ModeSignalID;  /* '<S37>/Vehicle_Control' */
  int_T Config_3_Transmit_CAN_0_ID_581_;/* '<S41>/Config_3_Transmit_CAN_0_ID_581' */
  int_T Config_3_Transmit_CAN_1_ID_550_;/* '<S41>/Config_3_Transmit_CAN_1_ID_550' */
  int_T Config_2_Transmit_CAN_2_ID_193_;/* '<S45>/Config_2_Transmit_CAN_2_ID_193' */
  int_T Config_1_Transmit_CAN_2_ID_193_;/* '<S44>/Config_1_Transmit_CAN_2_ID_193' */
  int_T BUS_BCUState_ModeSignalID;     /* '<S15>/BUS_BCUState' */
  int_T BUS_BCUState_StatusPortID;     /* '<S15>/BUS_BCUState' */
  int_T BUS_BCUState1_ModeSignalID;    /* '<S15>/BUS_BCUState1' */
  int_T BUS_BCUState1_StatusPortID;    /* '<S15>/BUS_BCUState1' */
  int_T BUS_BCUState2_ModeSignalID;    /* '<S15>/BUS_BCUState2' */
  int_T BUS_BCUState2_StatusPortID;    /* '<S15>/BUS_BCUState2' */
  int_T BUS_BCUState3_ModeSignalID;    /* '<S15>/BUS_BCUState3' */
  int_T BUS_BCUState3_StatusPortID;    /* '<S15>/BUS_BCUState3' */
  int_T BUS_BCUState4_ModeSignalID;    /* '<S15>/BUS_BCUState4' */
  int_T BUS_BCUState4_StatusPortID;    /* '<S15>/BUS_BCUState4' */
  int_T BUS_BCUState5_ModeSignalID;    /* '<S15>/BUS_BCUState5' */
  int_T BUS_BCUState5_StatusPortID;    /* '<S15>/BUS_BCUState5' */
  int_T Vehicle_Message_1_ModeSignalID;/* '<S4>/Vehicle_Message_1' */
  int_T Vehicle_Message_1_StatusPortID;/* '<S4>/Vehicle_Message_1' */
  int_T ESC_Message_ModeSignalID;      /* '<S4>/ESC_Message' */
  int_T ESC_Message_StatusPortID;      /* '<S4>/ESC_Message' */
  int_T Vehicle_Message_2_ModeSignalID;/* '<S4>/Vehicle_Message_2' */
  int_T Vehicle_Message_2_StatusPortID;/* '<S4>/Vehicle_Message_2' */
  int_T EBS_WheelSpeed_ModeSignalID;   /* '<S4>/EBS_WheelSpeed' */
  int_T EBS_WheelSpeed_StatusPortID;   /* '<S4>/EBS_WheelSpeed' */
  int_T VCU_ICPV_CAN_00_ModeSignalID;  /* '<S5>/VCU_ICPV_CAN_00' */
  int_T VCU_ICPV_CAN_00_StatusPortID;  /* '<S5>/VCU_ICPV_CAN_00' */
  int_T VCU_ICPV_CAN_01_ModeSignalID;  /* '<S5>/VCU_ICPV_CAN_01' */
  int_T VCU_ICPV_CAN_01_StatusPortID;  /* '<S5>/VCU_ICPV_CAN_01' */
  int_T VCU_ICPV_CAN_03_ModeSignalID;  /* '<S5>/VCU_ICPV_CAN_03' */
  int_T VCU_ICPV_CAN_03_StatusPortID;  /* '<S5>/VCU_ICPV_CAN_03' */
  int_T VCU_ICPV_CAN_ModeSignalID;     /* '<S5>/VCU_ICPV_CAN' */
  int_T VCU_ICPV_CAN_StatusPortID;     /* '<S5>/VCU_ICPV_CAN' */
  int_T VCU1_ICPV_CAN_00_ModeSignalID; /* '<S5>/VCU1_ICPV_CAN_00' */
  int_T VCU1_ICPV_CAN_00_StatusPortID; /* '<S5>/VCU1_ICPV_CAN_00' */
  int_T VCU1_ICPV_CAN_01_ModeSignalID; /* '<S5>/VCU1_ICPV_CAN_01' */
  int_T VCU1_ICPV_CAN_01_StatusPortID; /* '<S5>/VCU1_ICPV_CAN_01' */
  int_T VCU1_ICPV_CAN_02_ModeSignalID; /* '<S5>/VCU1_ICPV_CAN_02' */
  int_T VCU1_ICPV_CAN_02_StatusPortID; /* '<S5>/VCU1_ICPV_CAN_02' */
  int_T VCU1_ICPV_CAN_03_ModeSignalID; /* '<S5>/VCU1_ICPV_CAN_03' */
  int_T VCU1_ICPV_CAN_03_StatusPortID; /* '<S5>/VCU1_ICPV_CAN_03' */
  int_T VCU1_ICPV_CAN_04_ModeSignalID; /* '<S5>/VCU1_ICPV_CAN_04' */
  int_T VCU1_ICPV_CAN_04_StatusPortID; /* '<S5>/VCU1_ICPV_CAN_04' */
  int_T VCU1_ICPV_CAN_05_ModeSignalID; /* '<S5>/VCU1_ICPV_CAN_05' */
  int_T VCU1_ICPV_CAN_05_StatusPortID; /* '<S5>/VCU1_ICPV_CAN_05' */
  int_T VCU1_ICPV_CAN_06_ModeSignalID; /* '<S5>/VCU1_ICPV_CAN_06' */
  int_T VCU1_ICPV_CAN_06_StatusPortID; /* '<S5>/VCU1_ICPV_CAN_06' */
  int_T VCU_ICPV_CAN_02_ModeSignalID;  /* '<S5>/VCU_ICPV_CAN_02' */
  int_T VCU_ICPV_CAN_02_StatusPortID;  /* '<S5>/VCU_ICPV_CAN_02' */
  int_T PCU_ICPV_CAN_ModeSignalID;     /* '<S5>/PCU_ICPV_CAN' */
  int_T PCU_ICPV_CAN_StatusPortID;     /* '<S5>/PCU_ICPV_CAN' */
  int_T VCU1_ICPV_CAN_1_ModeSignalID;  /* '<S5>/VCU1_ICPV_CAN_1' */
  int_T VCU1_ICPV_CAN_1_StatusPortID;  /* '<S5>/VCU1_ICPV_CAN_1' */
  int_T ABS_FrP01_RollingCounter_ModeSi;/* '<S18>/ABS_FrP01_RollingCounter' */
  int_T ABS_FrP01_RollingCounter_Status;/* '<S18>/ABS_FrP01_RollingCounter' */
  int_T ESC_FrP01_BrkPress_AccValue_Mod;/* '<S18>/ESC_FrP01_BrkPress_AccValue' */
  int_T ESC_FrP01_BrkPress_AccValue_Sta;/* '<S18>/ESC_FrP01_BrkPress_AccValue' */
  int_T Veh_MCCU_01_ModeSignalID;      /* '<S18>/Veh_MCCU_01' */
  int_T Veh_MCCU_01_StatusPortID;      /* '<S18>/Veh_MCCU_01' */
  int_T VCU_FrP07_AccPed_ModeSignalID; /* '<S18>/VCU_FrP07_AccPed' */
  int_T VCU_FrP07_AccPed_StatusPortID; /* '<S18>/VCU_FrP07_AccPed' */
  int_T EPS_02_SteeringTorque_ModeSigna;/* '<S18>/EPS_02_SteeringTorque' */
  int_T EPS_02_SteeringTorque_StatusPor;/* '<S18>/EPS_02_SteeringTorque' */
  int_T VCU_EVCAN_F08_DriveMode_ModeSig;/* '<S18>/VCU_EVCAN_F08_DriveMode' */
  int_T VCU_EVCAN_F08_DriveMode_StatusP;/* '<S18>/VCU_EVCAN_F08_DriveMode' */
  int_T ESC_FrP01_YawRate_ModeSignalID;/* '<S18>/ESC_FrP01_YawRate' */
  int_T ESC_FrP01_YawRate_StatusPortID;/* '<S18>/ESC_FrP01_YawRate' */
  int_T ABS_FrP01_RollingCounter_M_pnxq;/* '<S17>/ABS_FrP01_RollingCounter' */
  int_T ABS_FrP01_RollingCounter_S_gloy;/* '<S17>/ABS_FrP01_RollingCounter' */
  int_T ESC_FrP01_ModeSignalID;        /* '<S17>/ESC_FrP01' */
  int_T ESC_FrP01_StatusPortID;        /* '<S17>/ESC_FrP01' */
  int_T Veh_MCCU_01_ModeSignalID_m5mm; /* '<S17>/Veh_MCCU_01' */
  int_T Veh_MCCU_01_StatusPortID_cmpt; /* '<S17>/Veh_MCCU_01' */
  int_T VCU_HSC_FrP07_ModeSignalID;    /* '<S17>/VCU_HSC_FrP07' */
  int_T VCU_HSC_FrP07_StatusPortID;    /* '<S17>/VCU_HSC_FrP07' */
  int_T EPS_02_SteeringTorque_Mode_ayxo;/* '<S17>/EPS_02_SteeringTorque' */
  int_T EPS_02_SteeringTorque_Stat_ozsk;/* '<S17>/EPS_02_SteeringTorque' */
  int_T ESC_FrP01_YawRate_ModeSign_nyqm;/* '<S17>/ESC_FrP01_YawRate' */
  int_T ESC_FrP01_YawRate_StatusPo_hpsr;/* '<S17>/ESC_FrP01_YawRate' */
  DW_MedianFilter1_COMM_subsyst_T MedianFilter1_pnaevvf;
  DW_MedianFilter1_COMM_subsyst_T MedianFilter1_pnaevv;
  DW_MedianFilter1_COMM_subsyst_T MedianFilter1_pnaev;
  DW_MedianFilter1_COMM_subsyst_T MedianFilter1_pnae;
  DW_MedianFilter1_COMM_subsyst_T MedianFilter1;
}
DW_COMM_subsystem_integrated_T;

/* Invariant block signals (auto storage) */
typedef struct
{
  const uint8_T DataTypeConversion13;  /* '<S40>/Data Type Conversion13' */
  const uint8_T DataTypeConversion8;   /* '<S41>/Data Type Conversion8' */
  const uint8_T DataTypeConversion16;  /* '<S41>/Data Type Conversion16' */
  const boolean_T DataTypeConversion17;/* '<S2>/Data Type Conversion17' */
  const boolean_T DataTypeConversion6; /* '<S15>/Data Type Conversion6' */
}
ConstB_COMM_subsystem_integra_T;

/* Constant parameters (auto storage) */
typedef struct
{
  /* Pooled Parameter (Expression: 2)
   * Referenced by:
   *   '<S41>/Constant5'
   *   '<S44>/Constant12'
   *   '<S45>/Constant12'
   *   '<S65>/Constant'
   *   '<S67>/Constant'
   *   '<S71>/Constant'
   *   '<S54>/Constant'
   */
  uint8_T pooled36;
}
ConstP_COMM_subsystem_integra_T;

/* Block signals (auto storage) */
extern B_COMM_subsystem_integrated_T COMM_subsystem_integrated_B;

/* Block states (auto storage) */
extern DW_COMM_subsystem_integrated_T COMM_subsystem_integrated_DW;

/* External data declarations for dependent source files */
extern const COMM_CAN_Data_Receive
  COMM_subsystem_integrated_rtZCOMM_CAN_Data_Receive;/* COMM_CAN_Data_Receive ground */
extern const COMM_VEH_RX_Data COMM_subsystem_integrated_rtZCOMM_VEH_RX_Data;/* COMM_VEH_RX_Data ground */
extern const COMM_Bus_VEH_Config
  COMM_subsystem_integrated_rtZCOMM_Bus_VEH_Config;/* COMM_Bus_VEH_Config ground */
extern const COMM_CANR_Databus COMM_subsystem_integrated_rtZCOMM_CANR_Databus;/* COMM_CANR_Databus ground */
extern const COMM_CANT_Databus COMM_subsystem_integrated_rtZCOMM_CANT_Databus;/* COMM_CANT_Databus ground */
extern const COMM_CAN_Data_Transmit
  COMM_subsystem_integrated_rtZCOMM_CAN_Data_Transmit;/* COMM_CAN_Data_Transmit ground */
extern const COMM_ADCU_TX_Data COMM_subsystem_integrated_rtZCOMM_ADCU_TX_Data;/* COMM_ADCU_TX_Data ground */
extern const ConstB_COMM_subsystem_integra_T COMM_subsystem_integrate_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstP_COMM_subsystem_integra_T COMM_subsystem_integrate_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern COMM_CAN_Data_Receive VsCOMM_CAN_Data_Receive;/* '<Root>/VsCOMM_CAN_Data_Receive' */
extern COMM_VEH_RX_Data VsCOMM_FAW_VEH_RX_Data;/* '<Root>/VsCOMM_FAW_VEH_RX_Data' */
extern boolean_T VbHWIO_DriverModeComd;/* '<Root>/VbHWIO_DriverModeComd'
                                        * Drive Mode Command from HWIO.
                                        */
extern boolean_T VbHWIO_LeftTurningLightState;/* '<Root>/VbHWIO_LeftTurningLightState'
                                               * Left Turning Light State from HWIO.
                                               */
extern boolean_T VbHWIO_RightTurningLightState;/* '<Root>/VbHWIO_RightTurningLightState'
                                                * Right Turning Light State from HWIO.
                                                */
extern boolean_T VbHWIO_ACC_MainSwitch;/* '<Root>/VbHWIO_ACC_MainSwitch'
                                        * ACC Main Switch from HWIO.
                                        */
extern boolean_T VbHWIO_ACC_ResumeSwitch;/* '<Root>/VbHWIO_ACC_ResumeSwitch'
                                          * ACC Resume Switch from HWIO.
                                          */
extern boolean_T VbHWIO_ACC_SetSwitch; /* '<Root>/VbHWIO_ACC_SetSwitch'
                                        * ACC Set Switch from HWIO.
                                        */
extern boolean_T VbHWIO_ACC_TimeGapPlus;/* '<Root>/VbHWIO_ACC_TimeGapPlus'
                                         * ACC Time Gap Plus from HWIO.
                                         */
extern boolean_T VbHWIO_ACC_TimeGapMinus;/* '<Root>/VbHWIO_ACC_TimeGapMinus'
                                          * ACC Time Gap Minus from HWIO.
                                          */
extern boolean_T VbHWIO_ACC_CancelSwitch;/* '<Root>/VbHWIO_ACC_CancelSwitch'
                                          * ACC Cancel Switch from HWIO.
                                          */
extern COMM_CANR_Databus VsCOMM_CANR_Databus;/* '<S1>/Merge2' */
extern COMM_CAN_Data_Transmit VsCOMM_CAN_Data_Transmit;/* '<S2>/Bus Creator1' */
extern COMM_CANT_Databus VsCOMM_CANT_Databus;/* '<S2>/Switch13' */
extern COMM_ADCU_TX_Data VsCOMM_FAW_ADCU_TX_Data;/* '<S46>/buscreator' */
extern COMM_Bus_VEH_Config VsCOMM_VEH_Config;/* '<S1>/Switch' */
extern real32_T VfCOMM_ADCU_BrakeDecelValue;/* '<S2>/Signal Conversion18' */
extern real32_T VfCOMM_ADCU_PowerAccelValue;/* '<S2>/Signal Conversion19' */
extern real32_T VfCOMM_ADCU_SteeringAngleValue;/* '<S2>/Signal Conversion20' */
extern real32_T VfCOMM_ADCU_TargetVehicleSpeed;/* '<S2>/Signal Conversion29' */
extern real32_T VfCOMM_ADCU_PowerTorqueValue;/* '<S2>/Signal Conversion4' */
extern real32_T VfCOMM_ADCU_BrakePressureValue;/* '<S2>/Signal Conversion34' */
extern real32_T VfCOMM_max_gas_pedal_EPB;/* '<S41>/Merge1' */
extern real32_T VfCOMM_TCU_ActualGearRatio;/* '<S1>/Signal Conversion136' */
extern real32_T VfCOMM_VDC_YawRate;    /* '<S1>/Signal Conversion141' */
extern real32_T VfCOMM_VDC_VehicleSpeed;/* '<S1>/Signal Conversion142' */
extern real32_T VfCOMM_VDC_WheelSpeed_RR1;/* '<S1>/Signal Conversion143' */
extern real32_T VfCOMM_VDC_LongAcceleration;/* '<S1>/Signal Conversion144' */
extern real32_T VfCOMM_VDC_LateralAcceleration;/* '<S1>/Signal Conversion145' */
extern real32_T VfCOMM_VDC_WheelSpeed_RR2;/* '<S1>/Signal Conversion146' */
extern real32_T VfCOMM_VDC_WheelSpeed_RL1;/* '<S1>/Signal Conversion147' */
extern real32_T VfCOMM_VDC_WheelSpeed_RL2;/* '<S1>/Signal Conversion148' */
extern real32_T VfCOMM_EPS_TargetSteeringAngleEcho;/* '<S1>/Signal Conversion153' */
extern real32_T VfCOMM_EPS_ActualSteeringAngle;/* '<S1>/Signal Conversion154' */
extern real32_T VfCOMM_EPS_SteeringAngleRate;/* '<S1>/Signal Conversion155' */
extern real32_T VfCOMM_VDC_WheelSpeed_FR;/* '<S1>/Signal Conversion156' */
extern real32_T VfCOMM_VDC_WheelSpeed_FL;/* '<S1>/Signal Conversion157' */
extern real32_T VfCOMM_VCU_VirtualAccelPedalPosition;/* '<S1>/Signal Conversion205' */
extern real32_T VfCOMM_EMS_EngineSpeed;/* '<S1>/Signal Conversion210' */
extern real32_T VfCOMM_PCU_DriverDemandTorque;/* '<S1>/Signal Conversion211' */
extern real32_T VfCOMM_PCU_ActualEngineTorque;/* '<S1>/Signal Conversion214' */
extern real32_T VfCOMM_EMS_CatalystTankLevel;/* '<S1>/Signal Conversion224' */
extern real32_T VfCOMM_VCU_ActualAccelPedalPosition;/* '<S1>/Signal Conversion225' */
extern real32_T VfCOMM_VCU_TargetAccelPedalPostionEcho;/* '<S1>/Signal Conversion227' */
extern real32_T VfCOMM_PCU_BatterySOC; /* '<S1>/Signal Conversion229' */
extern real32_T VfCOMM_PCU_MotorSpeed; /* '<S1>/Signal Conversion230' */
extern real32_T VfCOMM_PCU_MotorActualTorque;/* '<S1>/Signal Conversion231' */
extern real32_T VfCOMM_PCU_EngineTorqueLoss;/* '<S1>/Signal Conversion232' */
extern real32_T VfCOMM_EPS_SteeringWheelTorque;/* '<S1>/Signal Conversion234' */
extern real32_T VfCOMM_VCU_TargetBrakePedalEcho;/* '<S1>/Signal Conversion82' */
extern real32_T VfCOMM_VCU_ActualBrakePedalPosition;/* '<S1>/Signal Conversion83' */
extern real32_T VfCOMM_ESP_MasterCylinderPress;/* '<S1>/Signal Conversion85' */
extern uint32_T VfCOMM_VDC_WheelEncoderCounter_RL;/* '<S1>/Signal Conversion164' */
extern uint32_T VfCOMM_VDC_WheelEncoderCounter_RR;/* '<S1>/Signal Conversion165' */
extern int16_T VfCOMM_EMS_EngineCoolantTemperature;/* '<S1>/Signal Conversion216' */
extern uint16_T VfCOMM_EMS_EngineOilPressure;/* '<S1>/Signal Conversion215' */
extern uint16_T VeCOMM_VCU_AutoToManualTips;/* '<S1>/Signal Conversion30'
                                             * "Reason for not being able to enter automatic driving status (16 bits represent different conditions (starting from 1):

                                               Bit 1: comfort can bus off;

                                               Bit 2: power can bus off:

                                               Bit 3: adv control mode message timeout

                                               Bit 4: adv torque request message CS / LS fault;

                                               Bit 5: pull down the handbrake switch;

                                               Bit 6: The Trailer hand brake switch is pulled down;

                                               Bit 7: Cruise activation;

                                               Bit 8: when the accelerator is depressed, it is greater than a certain threshold;

                                               Bit 9: when the accelerator pedal fails;

                                               Bit 10: the brake pedal is depressed;

                                               Bit 11: brake pedal failure;

                                               Bit 12: intelligent driving function shielding. "
                                             */
extern uint16_T VfCOMM_ESP_BrakeAirTankPressure;/* '<S1>/Signal Conversion70' */
extern uint8_T VeCOMM_ADCU_TargetGearValue;/* '<S2>/Signal Conversion6'
                                            * Target Gear (0:Neutral;1-12:ForwardGears;13:Reverse;14Park;15:Invalid)
                                            */
extern uint8_T VeCOMM_ADCU_ParkingControlValue;/* '<S2>/Signal Conversion26'
                                                * Park control status (0: release; 1: clamp)
                                                */
extern uint8_T VeCOMM_TCU_TargetGearPositionEcho;/* '<S1>/Signal Conversion133'
                                                  * Target gear received by TCU from ADCU (0: neutral; 1-12: forwardgears; 13: reverse; 14park; 15: invalid)
                                                  */
extern uint8_T VeCOMM_TCU_ShiftLevelPosition;/* '<S1>/Signal Conversion134'
                                              * ShiftLevelPosition£¨PRNDL£©£¨0£ºPark;1:Reverse;2:Neutral;3:Drive£©
                                              */
extern uint8_T VeCOMM_TCU_ActualGearPosition;/* '<S1>/Signal Conversion135'
                                              * Actual gear(0:Neutral;1-12:ForwardGears;13:Reverse;14Park;15:Invalid)

                                              */
extern uint8_T VeCOMM_EPS_SteeringModeEcho;/* '<S1>/Signal Conversion151'
                                            * Target corner status received by EPS from ADCU (0: driver; 1: steeringangle; 2: steeringwheeltorque)
                                            */
extern uint8_T VeCOMM_EMS_StartStopStatus;/* '<S1>/Signal Conversion203'
                                           *
                                             0-Reset Start/Stop not active(any engine condition possible)

                                           */
extern uint8_T VeCOMM_EMS_EngineState; /* '<S1>/Signal Conversion209'
                                        * Engine status (0: keyoff; 1: ACC; 2: Keyon; 3: crank; 4: run)
                                        */
extern uint8_T VeCOMM_PCU_PowertrainFaultLevel;/* '<S1>/Signal Conversion228'
                                                * Power system fault level (0: nofault)
                                                */
extern uint8_T VeCOMM_EPS_FaultLevel;  /* '<S1>/Signal Conversion233'
                                        * Steering performance fault level (0: nofault)
                                        */
extern uint8_T VeCOMM_BCM_CruiseControlStatus;/* '<S1>/Signal Conversion33'
                                               * Cruise control status
                                               */
extern uint8_T VeCOMM_BCM_DriveMode;   /* '<S1>/Signal Conversion57'
                                        *
                                          BCM_DM_TargetModeReq£¨0£ºNormal£»1£ºSport£»2£ºEco£»other£ºReserve£©

                                        */
extern uint8_T VeCOMM_ESP_SystemFaultStatus;/* '<S1>/Signal Conversion60'
                                             * ESP system fault status (0: normal)
                                             */
extern uint8_T VeCOMM_EPB_SystemFaultStatus;/* '<S1>/Signal Conversion62'
                                             * ESP system fault status (0: normal)
                                             */
extern uint8_T VeCOMM_EPB_ActualControlStatus;/* '<S1>/Signal Conversion63'
                                               * EPB actual control status (0: release)
                                               */
extern boolean_T VbCOMM_ADCU_EmergencyLightRequest;/* '<S2>/Signal Conversion9' */
extern boolean_T VbCOMM_ADCU_RightTurningLightRequest;/* '<S2>/Signal Conversion10' */
extern boolean_T VbCOMM_ADCU_PositionLightRequest;/* '<S2>/Signal Conversion11' */
extern boolean_T VbCOMM_ADCU_LeftTurningLightRequest;/* '<S2>/Signal Conversion12' */
extern boolean_T VbCOMM_ADCU_HornRequest;/* '<S2>/Signal Conversion7' */
extern boolean_T VbCOMM_ADCU_HighBeamRequest;/* '<S2>/Signal Conversion13' */
extern boolean_T VbCOMM_ADCU_FrontFogLightRequest;/* '<S2>/Signal Conversion8' */
extern boolean_T VbCOMM_ADCU_LowBeamRequest;/* '<S2>/Signal Conversion14' */
extern boolean_T VbCOMM_ADCU_BrakeLightRequest;/* '<S2>/Signal Conversion5' */
extern boolean_T VbCOMM_ADCU_BackFogLghtRequest;/* '<S2>/Signal Conversion15' */
extern boolean_T VbCOMM_ADCU_AutodriveEnable;/* '<S2>/Signal Conversion16' */
extern boolean_T VbCOMM_ADCU_BCMControlEnable;/* '<S2>/Signal Conversion17' */
extern boolean_T VbCOMM_ADCU_TargetGearEnable;/* '<S2>/Signal Conversion21' */
extern boolean_T VbCOMM_ADCU_SteeringAngleEnable;/* '<S2>/Signal Conversion22' */
extern boolean_T VbCOMM_ADCU_ParkingPressureRequest;/* '<S2>/Signal Conversion23' */
extern boolean_T VbCOMM_ADCU_LaunchRequest;/* '<S2>/Signal Conversion24' */
extern boolean_T VbCOMM_ADCU_ParkingControlEnable;/* '<S2>/Signal Conversion25' */
extern boolean_T VbCOMM_ADCU_PowerEnable;/* '<S2>/Signal Conversion27' */
extern boolean_T VbCOMM_ADCU_BrakeEnable;/* '<S2>/Signal Conversion28' */
extern boolean_T VbCOMM_ADCU_SpeedDownIndicator;/* '<S2>/Signal Conversion30' */
extern boolean_T VbCOMM_ADCU_SpeedUpIndicator;/* '<S2>/Signal Conversion31' */
extern boolean_T VbCOMM_ADCU_OverSpeedWarning;/* '<S2>/Signal Conversion33' */
extern boolean_T VbCOMM_VDC_YawRateValid;/* '<S1>/Signal Conversion137' */
extern boolean_T VbCOMM_VDC_LongAccelerationValid;/* '<S1>/Signal Conversion138' */
extern boolean_T VbCOMM_EPS_SteeringWheelTorqueValid;/* '<S1>/Signal Conversion139' */
extern boolean_T VbCOMM_VDC_LateralAccelerationValid;/* '<S1>/Signal Conversion140' */
extern boolean_T VbCOMM_EPS_SteeringControlResponse_LDW;/* '<S1>/Signal Conversion149' */
extern boolean_T VbCOMM_EPS_SteeringControlResponse_LCC;/* '<S1>/Signal Conversion150' */
extern boolean_T VbCOMM_VDC_WheelSpeed_RR1Valid;/* '<S1>/Signal Conversion158' */
extern boolean_T VbCOMM_VDC_WheelSpeed_RR2Valid;/* '<S1>/Signal Conversion159' */
extern boolean_T VbCOMM_VDC_WheelSpeed_RL1Valid;/* '<S1>/Signal Conversion160' */
extern boolean_T VbCOMM_VDC_WheelSpeed_FLValid;/* '<S1>/Signal Conversion161' */
extern boolean_T VbCOMM_VDC_WheelSpeed_RL2Valid;/* '<S1>/Signal Conversion162' */
extern boolean_T VbCOMM_VDC_WheelSpeed_FRValid;/* '<S1>/Signal Conversion163' */
extern boolean_T VbCOMM_EMS_EngineSpeedValid;/* '<S1>/Signal Conversion204' */
extern boolean_T VbCOMM_VCU_VirtualAccelPedalValid;/* '<S1>/Signal Conversion206' */
extern boolean_T VbCOMM_VCU_AccelPedalOverride;/* '<S1>/Signal Conversion208' */
extern boolean_T VbCOMM_EMS_CoolantLevelLow;/* '<S1>/Signal Conversion212' */
extern boolean_T VbCOMM_PCU_PowerControlResponse;/* '<S1>/Signal Conversion213' */
extern boolean_T VbCOMM_VCU_AccelPedalValid;/* '<S1>/Signal Conversion226' */
extern boolean_T VbCOMM_EPS_HandsOnWheelDetected;/* '<S1>/Signal Conversion235' */
extern boolean_T VbCOMM_EPS_HandsOffWheelDetected;/* '<S1>/Signal Conversion236' */
extern boolean_T VbCOMM_VCU_AutodriveMainSwitch;/* '<S1>/Signal Conversion29' */
extern boolean_T VbCOMM_BCM_CruiseSwLimitMain;/* '<S1>/Signal Conversion31' */
extern boolean_T VbCOMM_BCM_DriverSeatBelt;/* '<S1>/Signal Conversion32' */
extern boolean_T VbCOMM_BCM_DriverSeatBeltValid;/* '<S1>/Signal Conversion34' */
extern boolean_T VbCOMM_BCM_TurningLightEcho;/* '<S1>/Signal Conversion35' */
extern boolean_T VbCOMM_BCM_LowBeamSwitch;/* '<S1>/Signal Conversion36' */
extern boolean_T VbCOMM_BCM_HighBeamSwitch;/* '<S1>/Signal Conversion37' */
extern boolean_T VbCOMM_BCM_BrakeLightStatus;/* '<S1>/Signal Conversion38' */
extern boolean_T VbCOMM_BCM_LeftTurningLightState;/* '<S1>/Signal Conversion39' */
extern boolean_T VbCOMM_BCM_RightTurningLightState;/* '<S1>/Signal Conversion40' */
extern boolean_T VbCOMM_VCU_AutodriveActiveStatus;/* '<S1>/Signal Conversion41' */
extern boolean_T VbCOMM_BCM_IgnitionKeyState;/* '<S1>/Signal Conversion42' */
extern boolean_T VbCOMM_BCM_DriverDoorStatus;/* '<S1>/Signal Conversion43' */
extern boolean_T VbCOMM_BCM_PassengerDoorStatus;/* '<S1>/Signal Conversion44' */
extern boolean_T VbCOMM_BCM_FrontHoodStatus;/* '<S1>/Signal Conversion45' */
extern boolean_T VbCOMM_BCM_RearRightDoorStatus;/* '<S1>/Signal Conversion46' */
extern boolean_T VbCOMM_BCM_RearLeftDoorStatus;/* '<S1>/Signal Conversion47' */
extern boolean_T VbCOMM_BCM_BackTrunkStatus;/* '<S1>/Signal Conversion48' */
extern boolean_T VbCOMM_BCM_WiperSwitch;/* '<S1>/Signal Conversion49' */
extern boolean_T VbCOMM_BCM_ControlResponse;/* '<S1>/Signal Conversion50' */
extern boolean_T VbCOMM_BCM_CruiseSwValid;/* '<S1>/Signal Conversion51' */
extern boolean_T VbCOMM_BCM_CruiseSwResume;/* '<S1>/Signal Conversion52' */
extern boolean_T VbCOMM_BCM_CruiseSwSet;/* '<S1>/Signal Conversion53' */
extern boolean_T VbCOMM_BCM_CruiseSwTimeGapPlus;/* '<S1>/Signal Conversion54' */
extern boolean_T VbCOMM_BCM_CruiseSwTimeGapMinus;/* '<S1>/Signal Conversion55' */
extern boolean_T VbCOMM_BCM_CruiseSwMain;/* '<S1>/Signal Conversion56' */
extern boolean_T VbCOMM_ESP_TCSActive; /* '<S1>/Signal Conversion58' */
extern boolean_T VbCOMM_ESP_ABSActive; /* '<S1>/Signal Conversion59' */
extern boolean_T VbCOMM_EPB_AutoholdStatus;/* '<S1>/Signal Conversion61' */
extern boolean_T VbCOMM_EPB_ParkingControlResponse;/* '<S1>/Signal Conversion64' */
extern boolean_T VbCOMM_EPB_SwitchStatus;/* '<S1>/Signal Conversion65' */
extern boolean_T VbCOMM_VCU_BrakePedalValid;/* '<S1>/Signal Conversion80' */
extern boolean_T VbCOMM_ESP_BrakeControlResponse;/* '<S1>/Signal Conversion81' */
extern boolean_T VbCOMM_VCU_ActualBrakePedalSwitch;/* '<S1>/Signal Conversion84' */
extern boolean_T VbCOMM_ESP_MasterCylinderPressValid;/* '<S1>/Signal Conversion86' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T KcCOMM_BrakePedalMax;  /* Variable: KcCOMM_BrakePedalMax
                                        * Referenced by: '<S41>/Constant9'
                                        */
extern real32_T KcCOMM_BrakePedalMin;  /* Variable: KcCOMM_BrakePedalMin
                                        * Referenced by: '<S41>/Constant6'
                                        */
extern real32_T KcCOMM_FirstGearRatio; /* Variable: KcCOMM_FirstGearRatio
                                        * Referenced by: '<S40>/Constant6'
                                        * Gear ratio in 1st gear.
                                        */
extern real32_T KcCOMM_GasPedalMax;    /* Variable: KcCOMM_GasPedalMax
                                        * Referenced by:
                                        *   '<S41>/Constant4'
                                        *   '<S60>/Constant4'
                                        */
extern real32_T KcCOMM_GasPedalMaxEPB; /* Variable: KcCOMM_GasPedalMaxEPB
                                        * Referenced by: '<S61>/Constant4'
                                        */
extern real32_T KcCOMM_GasPedalMin;    /* Variable: KcCOMM_GasPedalMin
                                        * Referenced by: '<S41>/Constant2'
                                        */
extern real32_T KcCOMM_GasPedalMinEPB; /* Variable: KcCOMM_GasPedalMinEPB
                                        * Referenced by: '<S59>/Constant4'
                                        */
extern real32_T KcCOMM_GasPedalRampEPB;/* Variable: KcCOMM_GasPedalRampEPB
                                        * Referenced by:
                                        *   '<S60>/Constant1'
                                        *   '<S61>/Constant1'
                                        */
extern real32_T KcCOMM_Test_Cmd_AccPelPosAct;/* Variable: KcCOMM_Test_Cmd_AccPelPosAct
                                              * Referenced by: '<S42>/Constant98'
                                              */
extern real32_T KcCOMM_Test_Cmd_BrkPelPosAct;/* Variable: KcCOMM_Test_Cmd_BrkPelPosAct
                                              * Referenced by: '<S42>/Constant95'
                                              */
extern real32_T KcCOMM_Test_Cmd_StrAngle;/* Variable: KcCOMM_Test_Cmd_StrAngle
                                          * Referenced by:
                                          *   '<S2>/Constant32'
                                          *   '<S42>/Constant104'
                                          */
extern real32_T KcCOMM_Test_Cmd_StrAngleSpd;/* Variable: KcCOMM_Test_Cmd_StrAngleSpd
                                             * Referenced by: '<S42>/Constant101'
                                             */
extern real32_T KcCOMM_Test_Decs_Acc_Value;/* Variable: KcCOMM_Test_Decs_Acc_Value
                                            * Referenced by:
                                            *   '<S2>/Constant24'
                                            *   '<S42>/Constant96'
                                            */
extern real32_T KcCOMM_Test_Decs_Breake_Value;/* Variable: KcCOMM_Test_Decs_Breake_Value
                                               * Referenced by:
                                               *   '<S2>/Constant28'
                                               *   '<S42>/Constant93'
                                               */
extern real32_T KcCOMM_Test_Tar_vehiclespd;/* Variable: KcCOMM_Test_Tar_vehiclespd
                                            * Referenced by: '<S42>/Constant34'
                                            */
extern real32_T KfACCS_d_VEH_WheelDiameter;/* Variable: KfACCS_d_VEH_WheelDiameter
                                            * Referenced by: '<S7>/Constant8'
                                            * This is whell diameter
                                            */
extern real32_T KfCOMM_Ang_VEH_AngOrigin2FrontWheel;/* Variable: KfCOMM_Ang_VEH_AngOrigin2FrontWheel
                                                     * Referenced by: '<S7>/Constant1'
                                                     * This is the angle between origin to front axle and origin to front wheel
                                                     */
extern real32_T KfCOMM_VEH_Mass;       /* Variable: KfCOMM_VEH_Mass
                                        * Referenced by: '<S7>/Constant14'
                                        * Vehicle mass
                                        */
extern real32_T KfCOMM_VEH_StiffnessFront;/* Variable: KfCOMM_VEH_StiffnessFront
                                           * Referenced by: '<S7>/Constant11'
                                           * This is cornering stiffness of front wheel
                                           */
extern real32_T KfCOMM_VEH_StiffnessRear;/* Variable: KfCOMM_VEH_StiffnessRear
                                          * Referenced by: '<S7>/Constant10'
                                          * This is cornering stiffness of rear wheel
                                          */
extern real32_T KfCOMM_VEH_YawInertia_Z;/* Variable: KfCOMM_VEH_YawInertia_Z
                                         * Referenced by: '<S7>/Constant2'
                                         * Moment of inertia of the whole vehicle around z axis
                                         */
extern real32_T KfCOMM_a_VCULongAccOffset;/* Variable: KfCOMM_a_VCULongAccOffset
                                           * Referenced by:
                                           *   '<S17>/CTRL_VehicleCANbusConfig3'
                                           *   '<S18>/CTRL_VehicleCANbusConfig3'
                                           * Offset to override Longitudinal Acceleration.
                                           */
extern real32_T KfCOMM_d_VEH_DisCentorid2Front;/* Variable: KfCOMM_d_VEH_DisCentorid2Front
                                                * Referenced by: '<S7>/Constant13'
                                                * This is the distance between Cetroid and Front surface
                                                */
extern real32_T KfCOMM_d_VEH_DisFront2Rear;/* Variable: KfCOMM_d_VEH_DisFront2Rear
                                            * Referenced by: '<S7>/Constant15'
                                            * This is distance between two axes
                                            */
extern real32_T KfCOMM_d_VEH_DisLeft2Right;/* Variable: KfCOMM_d_VEH_DisLeft2Right
                                            * Referenced by: '<S7>/Constant12'
                                            * This is the distance between left wheel and right wheel
                                            */
extern real32_T KfCOMM_d_VEH_DisOrigin2End;/* Variable: KfCOMM_d_VEH_DisOrigin2End
                                            * Referenced by: '<S7>/Constant4'
                                            * This is the distance between the cordinate origin and the rear surface
                                            */
extern real32_T KfCOMM_d_VEH_DisOrigin2FrontWheel;/* Variable: KfCOMM_d_VEH_DisOrigin2FrontWheel
                                                   * Referenced by: '<S7>/Constant3'
                                                   */
extern real32_T KfCOMM_d_VEH_DisOrigin2Head;/* Variable: KfCOMM_d_VEH_DisOrigin2Head
                                             * Referenced by: '<S7>/Constant6'
                                             * This is the distance between the coordinate origin and the front surface
                                             */
extern real32_T KfCOMM_d_VEH_DisOrigin2RearAxle;/* Variable: KfCOMM_d_VEH_DisOrigin2RearAxle
                                                 * Referenced by: '<S7>/Constant5'
                                                 * This is the distance between the cordinate origin and the rear axle
                                                 */
extern real32_T KfCOMM_d_VEH_Length;   /* Variable: KfCOMM_d_VEH_Length
                                        * Referenced by: '<S7>/Constant9'
                                        * This is vehicle length
                                        */
extern real32_T KfCOMM_d_VEH_MinTurnRadius;/* Variable: KfCOMM_d_VEH_MinTurnRadius
                                            * Referenced by: '<S7>/Constant'
                                            * Minimum turning radius
                                            */
extern real32_T KfCOMM_d_VEH_Width;    /* Variable: KfCOMM_d_VEH_Width
                                        * Referenced by: '<S7>/Constant7'
                                        * Vehicle's width
                                        */
extern real32_T KfCOMM_r_VCULongAccSlope;/* Variable: KfCOMM_r_VCULongAccSlope
                                          * Referenced by:
                                          *   '<S17>/CTRL_VehicleCANbusConfig2'
                                          *   '<S18>/CTRL_VehicleCANbusConfig2'
                                          * Slope to override Longitudinal Acceleration.
                                          */
extern uint8_T KcCOMM_Test_Cmd_ATOModEnable;/* Variable: KcCOMM_Test_Cmd_ATOModEnable
                                             * Referenced by: '<S42>/Constant99'
                                             */
extern uint8_T KcCOMM_Test_Cmd_TgtSft; /* Variable: KcCOMM_Test_Cmd_TgtSft
                                        * Referenced by: '<S42>/Constant90'
                                        */
extern uint8_T KcCOMM_Test_Decs_Acc_Req;/* Variable: KcCOMM_Test_Decs_Acc_Req
                                         * Referenced by: '<S2>/Constant18'
                                         */
extern uint8_T KcCOMM_Test_mode;       /* Variable: KcCOMM_Test_mode
                                        * Referenced by: '<S2>/Constant34'
                                        */
extern uint8_T KcCOMM_TorqCtrlPriority_Active;/* Variable: KcCOMM_TorqCtrlPriority_Active
                                               * Referenced by: '<S53>/Constant'
                                               * The priority of the Torque Override Control Mode send to VCU in ADV active state.
                                                 0 - Highest priority.
                                                 1 - High priority.
                                                 2 - Medium priority.
                                                 3 - Low priority.
                                               */
extern uint8_T KcCOMM_TorqCtrlPriority_Default;/* Variable: KcCOMM_TorqCtrlPriority_Default
                                                * Referenced by: '<S53>/Constant_0'
                                                * The priority of the Torque Override Control Mode send to VCU in default state.
                                                  0 - Highest priority.
                                                  1 - High priority.
                                                  2 - Medium priority.
                                                  3 - Low priority.
                                                */
extern uint8_T KeCOMM_Test_Cmd_ParkingCtrlValue;/* Variable: KeCOMM_Test_Cmd_ParkingCtrlValue
                                                 * Referenced by: '<S42>/Constant25'
                                                 */
extern uint8_T KeCOMM_VehicleCANbusConfig;/* Variable: KeCOMM_VehicleCANbusConfig
                                           * Referenced by:
                                           *   '<S1>/CTRL_VehicleCANbusConfig1'
                                           *   '<S1>/Constant'
                                           *   '<S2>/CTRL_VehicleCANbusConfig1'
                                           * Vehicle Platform and CAN Bus Configuration.
                                             1 - JAC#1;
                                             2 - JAC#2 or iVISTA;
                                             3 - ICPV;
                                             4 - GLB;
                                             5 - FAW;
                                             6 - HZBus;
                                             7 - USdemo.
                                           */
extern boolean_T KbCOMM_Test_BckFogLamp_Req;/* Variable: KbCOMM_Test_BckFogLamp_Req
                                             * Referenced by: '<S42>/Constant86'
                                             */
extern boolean_T KbCOMM_Test_BrakePrechargeRequest;/* Variable: KbCOMM_Test_BrakePrechargeRequest
                                                    * Referenced by: '<S42>/Constant39'
                                                    * Test mode value for brake boost precharge request.
                                                    */
extern boolean_T KbCOMM_Test_Cmd_AccPelEnable;/* Variable: KbCOMM_Test_Cmd_AccPelEnable
                                               * Referenced by: '<S42>/Constant28'
                                               */
extern boolean_T KbCOMM_Test_Cmd_BrakeLightReq;/* Variable: KbCOMM_Test_Cmd_BrakeLightReq
                                                * Referenced by: '<S42>/Constant78'
                                                */
extern boolean_T KbCOMM_Test_Cmd_BrkPelEnable;/* Variable: KbCOMM_Test_Cmd_BrkPelEnable
                                               * Referenced by: '<S42>/Constant91'
                                               */
extern boolean_T KbCOMM_Test_Cmd_ParkingCtrlEnable;/* Variable: KbCOMM_Test_Cmd_ParkingCtrlEnable
                                                    * Referenced by: '<S42>/Constant36'
                                                    */
extern boolean_T KbCOMM_Test_Cmd_TgtSftEnable;/* Variable: KbCOMM_Test_Cmd_TgtSftEnable
                                               * Referenced by: '<S42>/Constant89'
                                               */
extern boolean_T KbCOMM_Test_Decs_DippedBeam_Req;/* Variable: KbCOMM_Test_Decs_DippedBeam_Req
                                                  * Referenced by: '<S42>/Constant79'
                                                  */
extern boolean_T KbCOMM_Test_Decs_HighBeam_Req;/* Variable: KbCOMM_Test_Decs_HighBeam_Req
                                                * Referenced by: '<S42>/Constant80'
                                                */
extern boolean_T KbCOMM_Test_Decs_LftLmp_Req;/* Variable: KbCOMM_Test_Decs_LftLmp_Req
                                              * Referenced by: '<S42>/Constant83'
                                              */
extern boolean_T KbCOMM_Test_Decs_Light_Req;/* Variable: KbCOMM_Test_Decs_Light_Req
                                             * Referenced by: '<S42>/Constant87'
                                             */
extern boolean_T KbCOMM_Test_Decs_RihtLmp_Req;/* Variable: KbCOMM_Test_Decs_RihtLmp_Req
                                               * Referenced by: '<S42>/Constant84'
                                               */
extern boolean_T KbCOMM_Test_Decs_iBCM_Req;/* Variable: KbCOMM_Test_Decs_iBCM_Req
                                            * Referenced by:
                                            *   '<S42>/Constant74'
                                            *   '<S46>/Constant2'
                                            *   '<S46>/Constant41'
                                            */
extern boolean_T KbCOMM_Test_FrontFogLamp_Req;/* Variable: KbCOMM_Test_FrontFogLamp_Req
                                               * Referenced by: '<S42>/Constant85'
                                               */
extern boolean_T KbCOMM_Test_Horn_Req; /* Variable: KbCOMM_Test_Horn_Req
                                        * Referenced by: '<S42>/Constant71'
                                        */
extern boolean_T KbCOMM_Test_Over_Speed;/* Variable: KbCOMM_Test_Over_Speed
                                         * Referenced by: '<S42>/Constant26'
                                         * SLEW value for Over Speed.
                                         */
extern boolean_T KbCOMM_Test_SlowDown_Indication;/* Variable: KbCOMM_Test_SlowDown_Indication
                                                  * Referenced by: '<S42>/Constant27'
                                                  * SLEW value for SpeedUp_Indication.
                                                  */
extern boolean_T KbCOMM_Test_SpeedUp_Indication;/* Variable: KbCOMM_Test_SpeedUp_Indication
                                                 * Referenced by: '<S42>/Constant38'
                                                 * SLEW value for SpeedUp_Indication.
                                                 */
extern boolean_T KbCOMM_Test_Stop_Request;/* Variable: KbCOMM_Test_Stop_Request
                                           * Referenced by: '<S42>/Constant35'
                                           */
extern boolean_T KbCOMM_Test_WarnLight_Req;/* Variable: KbCOMM_Test_WarnLight_Req
                                            * Referenced by: '<S42>/Constant88'
                                            */
extern boolean_T KbCOMM_Test_driveoff_Req;/* Variable: KbCOMM_Test_driveoff_Req
                                           * Referenced by: '<S42>/Constant32'
                                           */
extern boolean_T KbCOMM_VEH_UseNewConfig;/* Variable: KbCOMM_VEH_UseNewConfig
                                          * Referenced by: '<S1>/Constant1'
                                          * This calibartion can change to a new vehicle configure which can be calibrated
                                          */
extern boolean_T KcCOMM_Test_Cmd_EPSXBW_En;/* Variable: KcCOMM_Test_Cmd_EPSXBW_En
                                            * Referenced by:
                                            *   '<S2>/Constant30'
                                            *   '<S42>/Constant100'
                                            */
extern boolean_T KcCOMM_Test_Cmd_EPSXBW_En_ovr;/* Variable: KcCOMM_Test_Cmd_EPSXBW_En_ovr
                                                * Referenced by: '<S2>/Constant33'
                                                */
extern boolean_T KcCOMM_Test_Cmd_StrAngle_ovr;/* Variable: KcCOMM_Test_Cmd_StrAngle_ovr
                                               * Referenced by: '<S2>/Constant12'
                                               */
extern boolean_T KcCOMM_Test_Decs_Acc_Req_ovr;/* Variable: KcCOMM_Test_Decs_Acc_Req_ovr
                                               * Referenced by: '<S2>/Constant11'
                                               */
extern boolean_T KcCOMM_Test_Decs_Acc_Value_ovr;/* Variable: KcCOMM_Test_Decs_Acc_Value_ovr
                                                 * Referenced by: '<S2>/Constant23'
                                                 */
extern boolean_T KcCOMM_Test_Decs_Breake_Req;/* Variable: KcCOMM_Test_Decs_Breake_Req
                                              * Referenced by: '<S2>/Constant31'
                                              */
extern boolean_T KcCOMM_Test_Decs_Breake_Req_ovr;/* Variable: KcCOMM_Test_Decs_Breake_Req_ovr
                                                  * Referenced by: '<S2>/Constant29'
                                                  */
extern boolean_T KcCOMM_Test_Decs_Breake_Value_ovr;/* Variable: KcCOMM_Test_Decs_Breake_Value_ovr
                                                    * Referenced by: '<S2>/Constant26'
                                                    */

/* Model entry point functions */
extern void COMM_subsystem_integrated_initialize(void);
extern void COMM_subsystem_integrated_step(void);

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
 * '<Root>' : 'COMM_subsystem_integrated'
 * '<S1>'   : 'COMM_subsystem_integrated/Receive'
 * '<S2>'   : 'COMM_subsystem_integrated/Transmit'
 * '<S3>'   : 'COMM_subsystem_integrated/Receive/FAW New'
 * '<S4>'   : 'COMM_subsystem_integrated/Receive/HZBus_NewMatrix New'
 * '<S5>'   : 'COMM_subsystem_integrated/Receive/ICPV New'
 * '<S6>'   : 'COMM_subsystem_integrated/Receive/InitialCanRData'
 * '<S7>'   : 'COMM_subsystem_integrated/Receive/Subsystem'
 * '<S8>'   : 'COMM_subsystem_integrated/Receive/Switch Case Action Subsystem'
 * '<S9>'   : 'COMM_subsystem_integrated/Receive/Switch Case Action Subsystem1'
 * '<S10>'  : 'COMM_subsystem_integrated/Receive/Switch Case Action Subsystem2'
 * '<S11>'  : 'COMM_subsystem_integrated/Receive/Switch Case Action Subsystem3'
 * '<S12>'  : 'COMM_subsystem_integrated/Receive/Switch Case Action Subsystem4'
 * '<S13>'  : 'COMM_subsystem_integrated/Receive/Switch Case Action Subsystem5'
 * '<S14>'  : 'COMM_subsystem_integrated/Receive/Switch Case Action Subsystem6'
 * '<S15>'  : 'COMM_subsystem_integrated/Receive/USdemo New'
 * '<S16>'  : 'COMM_subsystem_integrated/Receive/demo New'
 * '<S17>'  : 'COMM_subsystem_integrated/Receive/iEV7S_New'
 * '<S18>'  : 'COMM_subsystem_integrated/Receive/iVISTA_New'
 * '<S19>'  : 'COMM_subsystem_integrated/Receive/FAW New/Drive'
 * '<S20>'  : 'COMM_subsystem_integrated/Receive/FAW New/Neutral'
 * '<S21>'  : 'COMM_subsystem_integrated/Receive/FAW New/Park'
 * '<S22>'  : 'COMM_subsystem_integrated/Receive/FAW New/Reverse'
 * '<S23>'  : 'COMM_subsystem_integrated/Receive/HZBus_NewMatrix New/DoorStatusRemapping'
 * '<S24>'  : 'COMM_subsystem_integrated/Receive/HZBus_NewMatrix New/GearD'
 * '<S25>'  : 'COMM_subsystem_integrated/Receive/HZBus_NewMatrix New/GearN'
 * '<S26>'  : 'COMM_subsystem_integrated/Receive/HZBus_NewMatrix New/GearR'
 * '<S27>'  : 'COMM_subsystem_integrated/Receive/HZBus_NewMatrix New/default'
 * '<S28>'  : 'COMM_subsystem_integrated/Receive/ICPV New/GearN'
 * '<S29>'  : 'COMM_subsystem_integrated/Receive/ICPV New/GearP'
 * '<S30>'  : 'COMM_subsystem_integrated/Receive/ICPV New/GearR'
 * '<S31>'  : 'COMM_subsystem_integrated/Receive/ICPV New/Invalid'
 * '<S32>'  : 'COMM_subsystem_integrated/Receive/ICPV New/default'
 * '<S33>'  : 'COMM_subsystem_integrated/Receive/iEV7S_New/GearNorD'
 * '<S34>'  : 'COMM_subsystem_integrated/Receive/iEV7S_New/GearR'
 * '<S35>'  : 'COMM_subsystem_integrated/Receive/iVISTA_New/GearNorD'
 * '<S36>'  : 'COMM_subsystem_integrated/Receive/iVISTA_New/GearR'
 * '<S37>'  : 'COMM_subsystem_integrated/Transmit/BUS New'
 * '<S38>'  : 'COMM_subsystem_integrated/Transmit/Enumerated Constant'
 * '<S39>'  : 'COMM_subsystem_integrated/Transmit/Enumerated Constant1'
 * '<S40>'  : 'COMM_subsystem_integrated/Transmit/FAW New'
 * '<S41>'  : 'COMM_subsystem_integrated/Transmit/ICPV New'
 * '<S42>'  : 'COMM_subsystem_integrated/Transmit/Test_Mode_New'
 * '<S43>'  : 'COMM_subsystem_integrated/Transmit/USdemo New'
 * '<S44>'  : 'COMM_subsystem_integrated/Transmit/iEV7S_New'
 * '<S45>'  : 'COMM_subsystem_integrated/Transmit/iVISTA New'
 * '<S46>'  : 'COMM_subsystem_integrated/Transmit/FAW New/Command_Mapping'
 * '<S47>'  : 'COMM_subsystem_integrated/Transmit/FAW New/GearD'
 * '<S48>'  : 'COMM_subsystem_integrated/Transmit/FAW New/GearN'
 * '<S49>'  : 'COMM_subsystem_integrated/Transmit/FAW New/GearR'
 * '<S50>'  : 'COMM_subsystem_integrated/Transmit/FAW New/default'
 * '<S51>'  : 'COMM_subsystem_integrated/Transmit/FAW New/Command_Mapping/T01'
 * '<S52>'  : 'COMM_subsystem_integrated/Transmit/FAW New/Command_Mapping/T02'
 * '<S53>'  : 'COMM_subsystem_integrated/Transmit/FAW New/Command_Mapping/T03'
 * '<S54>'  : 'COMM_subsystem_integrated/Transmit/FAW New/Command_Mapping/T05'
 * '<S55>'  : 'COMM_subsystem_integrated/Transmit/FAW New/Command_Mapping/T08'
 * '<S56>'  : 'COMM_subsystem_integrated/Transmit/FAW New/Command_Mapping/T13'
 * '<S57>'  : 'COMM_subsystem_integrated/Transmit/FAW New/Command_Mapping/T15'
 * '<S58>'  : 'COMM_subsystem_integrated/Transmit/FAW New/Command_Mapping/T16'
 * '<S59>'  : 'COMM_subsystem_integrated/Transmit/ICPV New/EPB_clamped'
 * '<S60>'  : 'COMM_subsystem_integrated/Transmit/ICPV New/EPB_released'
 * '<S61>'  : 'COMM_subsystem_integrated/Transmit/ICPV New/EPB_releasing'
 * '<S62>'  : 'COMM_subsystem_integrated/Transmit/ICPV New/GearD'
 * '<S63>'  : 'COMM_subsystem_integrated/Transmit/ICPV New/GearN'
 * '<S64>'  : 'COMM_subsystem_integrated/Transmit/ICPV New/GearP'
 * '<S65>'  : 'COMM_subsystem_integrated/Transmit/ICPV New/GearR'
 * '<S66>'  : 'COMM_subsystem_integrated/Transmit/ICPV New/default'
 * '<S67>'  : 'COMM_subsystem_integrated/Transmit/iEV7S_New/GearD'
 * '<S68>'  : 'COMM_subsystem_integrated/Transmit/iEV7S_New/GearN'
 * '<S69>'  : 'COMM_subsystem_integrated/Transmit/iEV7S_New/GearR'
 * '<S70>'  : 'COMM_subsystem_integrated/Transmit/iEV7S_New/default'
 * '<S71>'  : 'COMM_subsystem_integrated/Transmit/iVISTA New/GearD'
 * '<S72>'  : 'COMM_subsystem_integrated/Transmit/iVISTA New/GearN'
 * '<S73>'  : 'COMM_subsystem_integrated/Transmit/iVISTA New/GearR'
 * '<S74>'  : 'COMM_subsystem_integrated/Transmit/iVISTA New/default'
 */
#endif                                 /* RTW_HEADER_COMM_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
