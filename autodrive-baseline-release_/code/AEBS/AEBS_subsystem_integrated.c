/*
 * File: AEBS_subsystem_integrated.c
 *
 * Code generated for Simulink model 'AEBS_subsystem_integrated'.
 *
 * Model version                  : 1.3091
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 16:35:01 2020
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

#include "AEBS_subsystem_integrated.h"
#include "AEBS_subsystem_integrated_private.h"

const AEBS_DataBus AEBS_subsystem_integrated_rtZAEBS_DataBus =
{
  {
    false,                             /* FCW_request */
    0U,                                /* FCW_warn_level */
    AEBS_EnblState_OFF,                /* FCW_enable_state */
    AEBS_FCWState_StandBy,             /* FCW_active_state */
    0U                                 /* FCW_error */
  },                                   /* FCW_Data */

  {
    false,                             /* AEB_request */
    false,                             /* AEB_prebrake_req */
    0.0F,                              /* AEB_acceleration_req */
    false,                             /* AEB_brakeLight_req */
    AEBS_EnblState_OFF,                /* AEB_enabled_state */
    AEBS_AEBState_StandBy,             /* AEB_actived_state */
    0U                                 /* AEB_error */
  },                                   /* AEB_Data */
  false,                               /* AEBS_brake_priority_setting */
  false,                               /* AEBS_horn_ctrl_req */
  0                                    /* AEBS_obj_ID */
} ;                                    /* AEBS_DataBus ground */

/* Exported block signals */
AEBS_DataBus VsAEBS_DataBus;           /* '<S1>/Merge' */
real32_T VfAEBS_m_1_a_x;               /* '<S4>/Signal Conversion10' */
real32_T VfAEBS_m_1_a_y;               /* '<S4>/Signal Conversion11' */
real32_T VfAEBS_m_1_length;            /* '<S4>/Signal Conversion12' */
real32_T VfAEBS_m_1_width;             /* '<S4>/Signal Conversion13' */
real32_T VfAEBS_m_2_NP_x;              /* '<S4>/Signal Conversion18' */
real32_T VfAEBS_m_2_NP_y;              /* '<S4>/Signal Conversion19' */
real32_T VfAEBS_m_3_NP_x;              /* '<S4>/Signal Conversion23' */
real32_T VfAEBS_m_3_NP_y;              /* '<S4>/Signal Conversion24' */
real32_T VfAEBS_m_2_heading;           /* '<S4>/Signal Conversion27' */
real32_T VfAEBS_m_3_heading;           /* '<S4>/Signal Conversion28' */
real32_T VfAEBS_m_4_NP_x;              /* '<S4>/Signal Conversion30' */
real32_T VfAEBS_m_4_NP_y;              /* '<S4>/Signal Conversion31' */
real32_T VfAEBS_m_4_heading;           /* '<S4>/Signal Conversion34' */
real32_T VfAEBS_m_2_length;            /* '<S4>/Signal Conversion35' */
real32_T VfAEBS_m_2_width;             /* '<S4>/Signal Conversion36' */
real32_T VfAEBS_m_3_length;            /* '<S4>/Signal Conversion37' */
real32_T VfAEBS_m_3_width;             /* '<S4>/Signal Conversion38' */
real32_T VfAEBS_m_4_length;            /* '<S4>/Signal Conversion39' */
real32_T VfAEBS_m_1_NP_x;              /* '<S4>/Signal Conversion4' */
real32_T VfAEBS_m_4_width;             /* '<S4>/Signal Conversion40' */
real32_T VfAEBS_m_1_NP_y;              /* '<S4>/Signal Conversion5' */
real32_T VfAEBS_m_1_heading;           /* '<S4>/Signal Conversion6' */
real32_T VfAEBS_m_1_v_x;               /* '<S4>/Signal Conversion7' */
real32_T VfAEBS_m_1_v_y;               /* '<S4>/Signal Conversion9' */
real32_T VfAEBS_m_EGMO_veh_speed;      /* '<S5>/Signal Conversion5' */
real32_T VfAEBS_m_EGMO_veh_acc;        /* '<S5>/Signal Conversion6' */
real32_T VfAEBS_m_EGMO_v_cur;          /* '<S5>/Signal Conversion7' */
real32_T VfAEBS_m_EGMO_v_x;            /* '<S5>/Signal Conversion8' */
real32_T VfAEBS_m_EGMO_v_y;            /* '<S5>/Signal Conversion9' */
real32_T VfAEBS_veh_speed_used;        /* '<S9>/Signal Conversion' */
real32_T VfAEBS_speed_x_used;          /* '<S9>/Signal Conversion11' */
real32_T VfAEBS_speed_y_used;          /* '<S9>/Signal Conversion12' */
real32_T VfAEBS_veh_acc_used;          /* '<S9>/Signal Conversion13' */
real32_T VfAEBS_veh_cur_used;          /* '<S9>/Signal Conversion10' */
real32_T VfAEBS_obs_delta_dis[32];     /* '<S9>/Signal Conversion1' */
real32_T VfAEBS_obs_delta_speed[32];   /* '<S9>/Signal Conversion2' */
real32_T VfAEBS_obs_ttc[32];           /* '<S9>/Signal Conversion3' */
real32_T VfAEBS_obs_dis2adc_long[32];  /* '<S9>/Signal Conversion4' */
real32_T VfAEBS_obs_dis2adc_lateral[32];/* '<S9>/Signal Conversion5' */
real32_T VfAEBS_obs_v_long[32];        /* '<S9>/Signal Conversion6' */
real32_T VfAEBS_obs_v_lateral[32];     /* '<S9>/Signal Conversion7' */
real32_T VfAEBS_obs_v_long_vip;        /* '<S165>/Data Type Conversion10' */
real32_T VfAEBS_obs_acc_lateral_vip;   /* '<S165>/Data Type Conversion11' */
real32_T VfAEBS_obs_acc_long_vip;      /* '<S165>/Data Type Conversion12' */
real32_T VfAEBS_obs_NP_x_vip;          /* '<S165>/Data Type Conversion13' */
real32_T VfAEBS_obs_NP_y_vip;          /* '<S165>/Data Type Conversion14' */
real32_T VfAEBS_obs_heading_VIP;       /* '<S165>/Data Type Conversion15' */
real32_T VfAEBS_obs_length_VIP;        /* '<S165>/Data Type Conversion16' */
real32_T VfAEBS_obs_width_VIP;         /* '<S165>/Data Type Conversion17' */
real32_T VfAEBS_obs_dis_long_VIP;      /* '<S165>/Data Type Conversion18' */
real32_T VfAEBS_obs_dis_lateral_VIP;   /* '<S165>/Data Type Conversion19' */
real32_T VfAEBS_obs_rp_vip;            /* '<S165>/Data Type Conversion2' */
real32_T VfAEBS_obs_ttc_vip;           /* '<S165>/Data Type Conversion4' */
real32_T VfAEBS_obs_delta_dis_vip;     /* '<S165>/Data Type Conversion5' */
real32_T VfAEBS_obs_delta_speed_vip;   /* '<S165>/Data Type Conversion6' */
real32_T VfAEBS_obs_v_lateral_vip;     /* '<S165>/Data Type Conversion9' */
real32_T VfAEBS_Pre_BrakeActiveTTCThreshold;/* '<S141>/Switch' */
real32_T VfAEBS_Partial_BrakeActiveTTCThreshold;/* '<S134>/Switch' */
real32_T VfAEBS_v_obj_absolute_speed;  /* '<S76>/Add2' */
real32_T VfAEBS_a_obj_absolute_acc;    /* '<S76>/Add1' */
real32_T VfAEBS_areq_withoutDelay_UrgentBrk;/* '<S76>/Divide2' */
real32_T VfAEBS_areq_withoutDelay;     /* '<S76>/Gain1' */
real32_T VfAEBS_dis_delay;             /* '<S76>/Add' */
real32_T VfAEBS_dis_safe_used;         /* '<S76>/Switch3' */
real32_T VfAEBS_areq;                  /* '<S76>/MinMax2' */
real32_T VfAEBS_Full_BrkActiveACCThreshold;/* '<S126>/Full_BrkActiveAccThreshold_table' */
real32_T VfAEBS_AEB_acceleration_af_filter;/* '<S51>/Product1' */
real32_T VfAEBS_AEB_acceleration_bf_limit;/* '<S47>/MinMax2' */
real32_T VfAEBS_AEB_accReq_beforeSend; /* '<S48>/Switch' */
real32_T VfAEBS_AEB_acceleration_req;  /* '<S7>/Signal Conversion3' */
real32_T VfAEBS_FedBck_Vehspd;         /* '<S14>/Signal Conversion6' */
real32_T VfAEBS_FedBck_AccLong;        /* '<S14>/Signal Conversion8' */
real32_T VfAEBS_FedBck_StrAngle;       /* '<S14>/Signal Conversion1' */
real32_T VfAEBS_FedBck_yawRate;        /* '<S14>/Signal Conversion15' */
real32_T VfAEBS_FedBck_AccLateral;     /* '<S14>/Signal Conversion7' */
int32_T VfAEBS_m_2_id;                 /* '<S4>/Signal Conversion17' */
int32_T VfAEBS_m_3_id;                 /* '<S4>/Signal Conversion22' */
int32_T VfAEBS_m_4_id;                 /* '<S4>/Signal Conversion29' */
int32_T VfAEBS_m_1_id;                 /* '<S4>/Signal Conversion3' */
int32_T VfAEBS_m_timestamp_high;       /* '<S4>/Signal Conversion8' */
int32_T VfAEBS_m_EGMO_timestamp_h;     /* '<S5>/Signal Conversion3' */
int32_T VfAEBS_obs_id_vip;             /* '<S165>/Data Type Conversion7' */
int32_T VfAEBS_AEBS_obs_id;            /* '<S28>/Switch' */
uint32_T VfAEBS_m_timestamp_low;       /* '<S4>/Signal Conversion1' */
uint32_T VfAEBS_m_EGMO_timestamp_l;    /* '<S5>/Signal Conversion1' */
uint16_T VfAEBS_m_num_obstacles;       /* '<S4>/Signal Conversion2' */
int8_T VfAEBS_m_1_type;                /* '<S4>/Signal Conversion14' */
int8_T VfAEBS_m_1_motion_status;       /* '<S4>/Signal Conversion15' */
int8_T VfAEBS_m_1_position_zone;       /* '<S4>/Signal Conversion16' */
int8_T VfAEBS_m_2_position_zone;       /* '<S4>/Signal Conversion20' */
int8_T VfAEBS_m_2_motion_status;       /* '<S4>/Signal Conversion21' */
int8_T VfAEBS_m_3_position_zone;       /* '<S4>/Signal Conversion25' */
int8_T VfAEBS_m_3_motion_status;       /* '<S4>/Signal Conversion26' */
int8_T VfAEBS_m_4_position_zone;       /* '<S4>/Signal Conversion32' */
int8_T VfAEBS_m_4_motion_status;       /* '<S4>/Signal Conversion33' */
int8_T VfAEBS_obs_position_zone_VIP;   /* '<S165>/Data Type Conversion20' */
int8_T VfAEBS_obs_motion_status_VIP;   /* '<S165>/Data Type Conversion21' */
int8_T VfAEBS_obs_type_vip;            /* '<S165>/Data Type Conversion8' */
uint8_T VfAEBS_m_1_confidence;         /* '<S4>/Signal Conversion41' */
uint8_T VfAEBS_m_2_confidence;         /* '<S4>/Signal Conversion42' */
uint8_T VfAEBS_m_3_confidence;         /* '<S4>/Signal Conversion43' */
uint8_T VfAEBS_m_4_confidence;         /* '<S4>/Signal Conversion44' */
uint8_T VfAEBS_obs_position_state[32]; /* '<S9>/Signal Conversion8' */
uint8_T VfAEBS_obs_filtered_type[32];  /* '<S9>/Signal Conversion9' */
uint8_T VfAEBS_obs_index_vip;          /* '<S165>/Data Type Conversion1' */
uint8_T VfAEBS_obs_confidence_VIP;     /* '<S165>/Data Type Conversion22' */
uint8_T VfAEBS_obs_position_state_vip; /* '<S165>/Data Type Conversion3' */
uint8_T VfAEBS_FCW_warn_level;         /* '<S27>/Switch1' */
uint8_T VfAEBS_FCW_error;              /* '<S7>/Signal Conversion11' */
uint8_T VfAEBS_AEB_error;              /* '<S7>/Signal Conversion8' */
uint8_T VfAEBS_FedBck_Drivemode;       /* '<S14>/Signal Conversion' */
uint8_T VfAEBS_FedBck_BrkLightState;   /* '<S14>/Signal Conversion12' */
uint8_T VfAEBS_FedBck_BrkPedStatus;    /* '<S14>/Signal Conversion9' */
uint8_T VfAEBS_FedBck_EPBstate;        /* '<S14>/Signal Conversion5' */
uint8_T VfAEBS_FedBck_GearValue;       /* '<S14>/Signal Conversion4' */
uint8_T VfAEBS_FedBck_BrkPedPos;       /* '<S14>/Signal Conversion3' */
uint8_T VfAEBS_FedBck_AccPedPos;       /* '<S14>/Signal Conversion2' */
uint8_T VfAEBS_FedBck_SmallLampState;  /* '<S14>/Signal Conversion11' */
boolean_T VfAEBS_FCW_enabled;          /* '<S206>/Logical Operator' */
boolean_T VbAEBS_FCW_inhbt_AccPedPos;  /* '<S210>/Relational Operator1' */
boolean_T VbAEBS_FCW_inhbt_VehAcc;     /* '<S210>/Relational Operator2' */
boolean_T VbAEBS_FCW_inhbt_DeactTime;  /* '<S219>/Relational Operator' */
boolean_T VbAEBS_FCW_inhibit;          /* '<S210>/Logical Operator1' */
boolean_T VfAEBS_FCWLev1_active;       /* '<S207>/Logical Operator' */
boolean_T VfAEBS_FCWLev1_dactive;      /* '<S207>/Logical Operator3' */
boolean_T VfAEBS_FCWLev2_active;       /* '<S208>/Logical Operator' */
boolean_T VfAEBS_FCWLev2_dactive;      /* '<S208>/Logical Operator3' */
boolean_T VfAEBS_FCWLev3_active;       /* '<S209>/Logical Operator' */
boolean_T VfAEBS_FCWLev3_dactive;      /* '<S209>/Logical Operator3' */
boolean_T VfAEBS_FCW_disabled;         /* '<S206>/Logical Operator2' */
boolean_T VfAEBS_FCW_deacitve;         /* '<S214>/Chart' */
boolean_T VbAEBS_has_obs_vip;          /* '<S165>/Data Type Conversion' */
boolean_T VfAEBS_Obj_IsVRU;            /* '<S122>/SwitchVRUObs' */
boolean_T VfAEBS_use_VRU_Calibration;  /* '<S78>/Logical Operator' */
boolean_T VfAEBS_LowSpeed_InhibitAEB;  /* '<S145>/Logical Operator' */
boolean_T VfAEBS_HighSpeed_InhibitAEB; /* '<S145>/Relational Operator2' */
boolean_T VfAEBS_VehDeltaSpeed_InhibitAEB;/* '<S145>/Logical Operator2' */
boolean_T VfAEBS_Speed_InhibitAEB;     /* '<S145>/Logical Operator1' */
boolean_T VfAEBS_Gear_InhibitAEB;      /* '<S84>/Relational Operator3' */
boolean_T VbAEBS_AEB_inhbt_DeactTime;  /* '<S142>/Relational Operator' */
boolean_T VbAEBS_AEB_inhbt_AccPdl;     /* '<S84>/Relational Operator1' */
boolean_T VbAEBS_AEB_inhbt_StrAngRte;  /* '<S144>/Relational Operator' */
boolean_T VbAEBS_AEB_inhbt_veh_acc;    /* '<S146>/Relational Operator' */
boolean_T VfAEBS_AEB_inhibit;          /* '<S84>/Logical Operator' */
boolean_T VbAEBS_PreBrk_inhbt_deactTime;/* '<S143>/Relational Operator' */
boolean_T VbAEBS_preBrake_inhibit;     /* '<S84>/Logical Operator1' */
boolean_T VfAEBS_preBrake_active;      /* '<S83>/Logical Operator' */
boolean_T VfAEBS_partialBrk_active;    /* '<S82>/Switch' */
boolean_T VfAEBS_fullBrk_active;       /* '<S81>/Switch' */
boolean_T VbAEBS_Deactive_R_NoVIP;     /* '<S77>/Logical Operator' */
boolean_T VbAEBS_vipCloseLost;         /* '<S95>/Signal Conversion' */
boolean_T VbAEBS_vipStationary;        /* '<S94>/Signal Conversion' */
boolean_T VbAEBS_Deactive_R_VIPChanged;/* '<S93>/Logical Operator2' */
boolean_T VfAEBS_DeniedDueToSpdRed;    /* '<S92>/i' */
boolean_T VfAEBS_DeniedDueToTimeBrake; /* '<S92>/i1' */
boolean_T VbAEBS_Deactive_R_Confdnc;   /* '<S77>/Relational Operator1' */
boolean_T VbAEBS_deactive_preBrk_timeOut;/* '<S96>/i1' */
boolean_T VfAEBS_AEB_enabled;          /* '<S80>/Logical Operator3' */
boolean_T VfAEBS_preBrake_dactive;     /* '<S83>/Logical Operator3' */
boolean_T VfAEBS_partialBrk_dactive;   /* '<S82>/Logical Operator3' */
boolean_T VfAEBS_fullBrk_dactive;      /* '<S81>/Logical Operator3' */
boolean_T VfAEBS_AEB_disabled;         /* '<S80>/Logical Operator7' */
boolean_T VfAEBS_veh_standstill;       /* '<S79>/Stop_Moving_Estimation' */
boolean_T VfAEBS_Vehicle_isInHighSpeed;/* '<S123>/Chart' */
boolean_T VfAEBS_AEB_deactive;         /* '<S99>/Chart' */
boolean_T VbAEBS_Deactive_R_HighTTC;   /* '<S97>/Chart' */
boolean_T VfAEBS_AEB_request_beforeSend;/* '<S39>/DtrmnAEB_State' */
boolean_T VfAEBS_FCW_request;          /* '<S7>/Signal Conversion9' */
boolean_T VfAEBS_AEB_request;          /* '<S7>/Signal Conversion2' */
boolean_T VfAEBS_AEB_prebrake_req;     /* '<S7>/Signal Conversion1' */
boolean_T VfAEBS_brakeLight_req;       /* '<S7>/Signal Conversion4' */
boolean_T VfAEBS_AEBS_brake_priority_setting;/* '<S7>/Signal Conversion5' */
boolean_T VfAEBS_AEBS_horn_ctrl_req;   /* '<S7>/Signal Conversion12' */
boolean_T VfAEBS_FedBck_LeftLampState; /* '<S14>/Signal Conversion16' */
boolean_T VfAEBS_FedBck_RightLampState;/* '<S14>/Signal Conversion17' */
EnumAEBS_EnblState VfAEBS_FCW_enable_state;/* '<S7>/Signal Conversion10' */
EnumAEBS_EnblState VeAEBS_AEB_enabled_state;/* '<S7>/Signal Conversion6' */
EnumAEBS_FCWState VfAEBS_FCW_active_state;/* '<S27>/Switch3' */
EnumAEBS_AEBState VeAEBS_AEB_actived_state;/* '<S7>/Signal Conversion7' */
EnumAEBS_TurnType VeAEBS_TurnType;     /* '<S166>/Merge1' */

#pragma section ".cal"
/* Exported block parameters */
real32_T KaAEBS_AXIS_DeltaSpeed_Vip[13] =
{
  1.0F, 2.5F, 5.0F, 7.5F, 10.0F, 12.5F, 15.0F, 17.5F, 20.0F, 22.5F, 25.0F, 27.5F,
  30.0F
} ;                                    /* Variable: KaAEBS_AXIS_DeltaSpeed_Vip
                                        * Referenced by:
                                        *   '<S207>/Partial_FCWL1TTCThreshold_table'
                                        *   '<S208>/Partial_FCWL2TTCThreshold_table'
                                        *   '<S209>/Partial_FCWL3TTCThreshold_table'
                                        *   '<S126>/Full_BrkActiveAccThreshold_table'
                                        *   '<S134>/Partial_BrakeActiveTTCThreshold_VRU_table'
                                        *   '<S134>/Partial_BrakeActiveTTCThreshold_table'
                                        *   '<S141>/Pre_BrakeActiveTTCThreshold_VRU_table'
                                        *   '<S141>/Pre_BrakeActiveTTCThreshold_table'
                                        */

real32_T KaAEBS_AXIS_NearestPointX_vec[11] =
{
  2.0F, 5.0F, 10.0F, 15.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F
} ;                                    /* Variable: KaAEBS_AXIS_NearestPointX_vec
                                        * Referenced by:
                                        *   '<S171>/lateral_buffer_bicycle_table'
                                        *   '<S172>/lateral_buffer_motorcycle_table'
                                        *   '<S173>/lateral_buffer_other_table'
                                        *   '<S174>/lateral_buffer_pedestrain_table'
                                        *   '<S175>/lateral_buffer_vehicle_table'
                                        */

real32_T KaAEBS_AXIS_NearestPointY_vec[11] =
{
  0.5F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 8.0F, 10.0F, 15.0F, 20.0F
} ;                                    /* Variable: KaAEBS_AXIS_NearestPointY_vec
                                        * Referenced by:
                                        *   '<S176>/long_buffer_bicycle_table'
                                        *   '<S177>/long_buffer_motorcycle_table'
                                        *   '<S178>/long_buffer_other_table'
                                        *   '<S179>/long_buffer_pedestrain_table'
                                        *   '<S180>/long_buffer_vehicle_table'
                                        */

real32_T KaAEBS_AXIS_Veh_Curvature_vec[10] =
{
  0.004F, 0.0056F, 0.0083F, 0.01F, 0.016F, 0.025F, 0.03F, 0.05F, 0.07F, 0.1F
} ;                                    /* Variable: KaAEBS_AXIS_Veh_Curvature_vec
                                        * Referenced by: '<S48>/BrakeValueLimit_Table'
                                        */

real32_T KaAEBS_AXIS_Veh_Speed_vec[9] =
{
  0.0F, 2.5F, 5.0F, 7.5F, 10.0F, 12.5F, 15.0F, 17.5F, 20.0F
} ;                                    /* Variable: KaAEBS_AXIS_Veh_Speed_vec
                                        * Referenced by:
                                        *   '<S9>/veh_widthGain_table'
                                        *   '<S146>/veh_acc_AEB_inhibit_thrhd_table'
                                        */

real32_T KfAEBS_CTRL_PeriodFunctionCall = 0.01F;/* Variable: KfAEBS_CTRL_PeriodFunctionCall
                                                 * Referenced by:
                                                 *   '<S3>/KfAEBS_CTRL_PeriodFunctionCall'
                                                 *   '<S3>/Constant9'
                                                 *   '<S42>/Constant10'
                                                 *   '<S76>/Constant9'
                                                 *   '<S79>/Constant'
                                                 *   '<S157>/Constant9'
                                                 *   '<S204>/Constant'
                                                 *   '<S204>/Constant5'
                                                 *   '<S205>/Constant'
                                                 *   '<S47>/Constant9'
                                                 *   '<S49>/Constant'
                                                 *   '<S90>/Constant7'
                                                 *   '<S91>/Constant5'
                                                 *   '<S96>/Constant2'
                                                 *   '<S128>/Constant7'
                                                 *   '<S129>/Constant7'
                                                 *   '<S135>/Constant7'
                                                 *   '<S136>/Constant7'
                                                 *   '<S142>/Constant'
                                                 *   '<S143>/Constant'
                                                 *   '<S144>/Constant7'
                                                 *   '<S219>/Constant'
                                                 *   '<S101>/Constant'
                                                 *   '<S101>/Constant2'
                                                 *   '<S118>/Constant'
                                                 * System sample period.
                                                 */
real32_T KfAEBS_Change_LateralPosThrsh = 4.0F;/* Variable: KfAEBS_Change_LateralPosThrsh
                                               * Referenced by:
                                               *   '<S212>/Constant2'
                                               *   '<S114>/Constant2'
                                               * Object change lateral position threshold
                                               */
real32_T KfAEBS_Change_LonglPosThrsh = 4.0F;/* Variable: KfAEBS_Change_LonglPosThrsh
                                             * Referenced by:
                                             *   '<S212>/Constant1'
                                             *   '<S114>/Constant1'
                                             * Object change longitudinal position threshold
                                             */
real32_T KfAEBS_CoeffStrwhl2Radius = -0.18F;/* Variable: KfAEBS_CoeffStrwhl2Radius
                                             * Referenced by: '<S13>/Constant6'
                                             * When there's no EGMO, steer wheel angle is used to calculate Radius,
                                               Coefficent correction of radius.
                                             */
real32_T KfAEBS_Cur_LeftTurnThrshHi = 0.02F;/* Variable: KfAEBS_Cur_LeftTurnThrshHi
                                             * Referenced by:
                                             *   '<S9>/KfAEBS_Cur_LeftTurnThrshHi'
                                             *   '<S9>/Constant3'
                                             * Curvature left turn threshold High
                                             */
real32_T KfAEBS_Cur_LeftTurnThrshLo = 0.018F;/* Variable: KfAEBS_Cur_LeftTurnThrshLo
                                              * Referenced by:
                                              *   '<S9>/KfAEBS_Cur_LeftTurnThrshLo'
                                              *   '<S9>/Constant4'
                                              *   '<S94>/Constant4'
                                              * Curvature left turn threshold low
                                              */
real32_T KfAEBS_Cur_RightTurnThrshHi = -0.018F;/* Variable: KfAEBS_Cur_RightTurnThrshHi
                                                * Referenced by:
                                                *   '<S9>/KfAEBS_Cur_RightTurnThrshHi'
                                                *   '<S9>/Constant1'
                                                * Curvature right turn threshold high
                                                */
real32_T KfAEBS_Cur_RightTurnThrshLo = -0.02F;/* Variable: KfAEBS_Cur_RightTurnThrshLo
                                               * Referenced by:
                                               *   '<S9>/KfAEBS_Cur_RightTurnThrshLo'
                                               *   '<S9>/Constant2'
                                               * Curvature right turn threshold low
                                               */
real32_T KfAEBS_Default_AEB_acceleration_req = 0.0F;/* Variable: KfAEBS_Default_AEB_acceleration_req
                                                     * Referenced by: '<S2>/Constant7'
                                                     * Default AEB acceleration req
                                                     */
real32_T KfAEBS_GainTHW = 1.0F;        /* Variable: KfAEBS_GainTHW
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_GainTHW'
                                        *   '<S9>/Constant28'
                                        * GainTHW
                                        */
real32_T KfAEBS_GainTTC = 4.0F;        /* Variable: KfAEBS_GainTTC
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_GainTTC'
                                        *   '<S9>/Constant29'
                                        * GainTTC
                                        */
real32_T KfAEBS_Pedstr_length_Thrsh = 1.0F;/* Variable: KfAEBS_Pedstr_length_Thrsh
                                            * Referenced by:
                                            *   '<S9>/KfAEBS_Pedstr_length_Thrsh'
                                            *   '<S9>/Constant42'
                                            */
real32_T KfAEBS_Pedstr_width_Thrsh = 1.0F;/* Variable: KfAEBS_Pedstr_width_Thrsh
                                           * Referenced by:
                                           *   '<S9>/KfAEBS_Pedstr_width_Thrsh'
                                           *   '<S9>/Constant41'
                                           */
real32_T KfAEBS_SpdMinOvrdAccrResetInCllsnRednByBrkg = 60.0F;/* Variable: KfAEBS_SpdMinOvrdAccrResetInCllsnRednByBrkg
                                                              * Referenced by:
                                                              *   '<S43>/LoPosValInCllsnRednByBrkg  1'
                                                              *   '<S196>/LoPosValInCllsnRednByBrkg  1'
                                                              */
real32_T KfAEBS_SteerRate_Limit_hi = 50.0F;/* Variable: KfAEBS_SteerRate_Limit_hi
                                            * Referenced by:
                                            *   '<S128>/Constant4'
                                            *   '<S135>/Constant4'
                                            */
real32_T KfAEBS_SteerRate_Limit_lo = 30.0F;/* Variable: KfAEBS_SteerRate_Limit_lo
                                            * Referenced by:
                                            *   '<S128>/Constant1'
                                            *   '<S135>/Constant1'
                                            */
real32_T KfAEBS_StrAngRte_inhbt_AEB_trshd = 1.8F;/* Variable: KfAEBS_StrAngRte_inhbt_AEB_trshd
                                                  * Referenced by: '<S144>/Constant4'
                                                  */
real32_T KfAEBS_VehAcc_inhbt_FCW_thrshld = -2.5F;/* Variable: KfAEBS_VehAcc_inhbt_FCW_thrshld
                                                  * Referenced by: '<S210>/Constant3'
                                                  */
real32_T KfAEBS_Veh_Dis2OC_useCenterPoint = 10.0F;/* Variable: KfAEBS_Veh_Dis2OC_useCenterPoint
                                                   * Referenced by:
                                                   *   '<S9>/KfAEBS_Veh_Dis2OC_useCenterPoint'
                                                   *   '<S9>/Constant10'
                                                   */
real32_T KfAEBS_Veh_DisEnd2OC = 0.8F;  /* Variable: KfAEBS_Veh_DisEnd2OC
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_DisEnd2OC'
                                        *   '<S9>/Constant18'
                                        */
real32_T KfAEBS_Veh_DisHead2OC = 3.3F; /* Variable: KfAEBS_Veh_DisHead2OC
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_DisHead2OC'
                                        *   '<S9>/Constant19'
                                        *   '<S170>/Constant19'
                                        */
real32_T KfAEBS_Veh_DisIngnore2OC = 3.1F;/* Variable: KfAEBS_Veh_DisIngnore2OC
                                          * Referenced by:
                                          *   '<S9>/KfAEBS_Veh_DisIngnore2OC'
                                          *   '<S9>/Constant5'
                                          */
real32_T KfAEBS_Veh_DisRear2COM = 1.3F;/* Variable: KfAEBS_Veh_DisRear2COM
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_DisRear2COM'
                                        *   '<S9>/Constant20'
                                        */
real32_T KfAEBS_Veh_DisRear2OC = 0.0F; /* Variable: KfAEBS_Veh_DisRear2OC
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_DisRear2OC'
                                        *   '<S9>/Constant21'
                                        */
real32_T KfAEBS_Veh_Length = 4.2F;     /* Variable: KfAEBS_Veh_Length
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_Length'
                                        *   '<S9>/Constant22'
                                        */
real32_T KfAEBS_Veh_Strwhl2FrtwhlRatio = 17.0F;/* Variable: KfAEBS_Veh_Strwhl2FrtwhlRatio
                                                * Referenced by: '<S13>/Constant2'
                                                */
real32_T KfAEBS_Veh_WheelBase = 2.49F; /* Variable: KfAEBS_Veh_WheelBase
                                        * Referenced by: '<S13>/Constant1'
                                        */
real32_T KfAEBS_Veh_Width = 2.3F;      /* Variable: KfAEBS_Veh_Width
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_Width'
                                        *   '<S9>/Constant30'
                                        *   '<S9>/Constant7'
                                        *   '<S95>/Constant11'
                                        *   '<S95>/Constant14'
                                        */
real32_T KfAEBS_Veh_WidthBuffer = 0.2F;/* Variable: KfAEBS_Veh_WidthBuffer
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_WidthBuffer'
                                        *   '<S9>/Constant23'
                                        */
real32_T KfAEBS_VeloRectThrsdByBrkg = 20.0F;/* Variable: KfAEBS_VeloRectThrsdByBrkg
                                             * Referenced by: '<S92>/VRednThdASILAInCllsnRednByBrkg'
                                             */
real32_T KfAEBS_YawRate_Limit_hi = 0.5F;/* Variable: KfAEBS_YawRate_Limit_hi
                                         * Referenced by:
                                         *   '<S128>/Constant6'
                                         *   '<S135>/Constant6'
                                         */
real32_T KfAEBS_YawRate_Limit_lo = 0.3F;/* Variable: KfAEBS_YawRate_Limit_lo
                                         * Referenced by:
                                         *   '<S128>/Constant5'
                                         *   '<S135>/Constant5'
                                         */
real32_T KfAEBS_Zone_DoRbIW_x_front = 9.0F;/* Variable: KfAEBS_Zone_DoRbIW_x_front
                                            * Referenced by:
                                            *   '<S9>/KfAEBS_Zone_DoRbIW_x_front'
                                            *   '<S9>/Constant35'
                                            */
real32_T KfAEBS_Zone_DoRbIW_x_rear = -1.0F;/* Variable: KfAEBS_Zone_DoRbIW_x_rear
                                            * Referenced by:
                                            *   '<S9>/KfAEBS_Zone_DoRbIW_x_rear'
                                            *   '<S9>/Constant36'
                                            */
real32_T KfAEBS_a_AreqRampRate = -10.0F;/* Variable: KfAEBS_a_AreqRampRate
                                         * Referenced by: '<S47>/Constant7'
                                         */
real32_T KfAEBS_a_Areq_FullBrkDeactThrsd = -0.1F;/* Variable: KfAEBS_a_Areq_FullBrkDeactThrsd
                                                  * Referenced by: '<S81>/Constant1'
                                                  * Acceleration request full brake dactive threshold(Full brake
                                                    can be deactived only in a short period)
                                                  */
real32_T KfAEBS_a_Areq_ObjChangThrsd = -0.5F;/* Variable: KfAEBS_a_Areq_ObjChangThrsd
                                              * Referenced by: '<S93>/Constant1'
                                              * When the object is changed, only when the new object's acceleration request
                                                is samller than a threshold, then, the AEB/FCW can be deactived.
                                              */
real32_T KfAEBS_a_Areq_PartialBrkActThrsd = -2.0F;/* Variable: KfAEBS_a_Areq_PartialBrkActThrsd
                                                   * Referenced by: '<S82>/Constant2'
                                                   * Acceleration request partial brake active threshold
                                                   */
real32_T KfAEBS_a_Areq_PartialBrkDeactThrsd = -0.0F;/* Variable: KfAEBS_a_Areq_PartialBrkDeactThrsd
                                                     * Referenced by: '<S82>/Constant1'
                                                     * Acceleration request partial brake deactive threshold
                                                     */
real32_T KfAEBS_a_BrakeHold = -0.2F;   /* Variable: KfAEBS_a_BrakeHold
                                        * Referenced by:
                                        *   '<S3>/KfAEBS_a_BrakeHold'
                                        *   '<S3>/Constant2'
                                        * Acceleration send when vehicle is standstill
                                        */
real32_T KfAEBS_a_BrakeInit = -1.5F;   /* Variable: KfAEBS_a_BrakeInit
                                        * Referenced by:
                                        *   '<S42>/KfAEBS_a_BrakeInit'
                                        *   '<S42>/Constant2'
                                        * In passensor protected stage,acceleration send at initial step
                                        */
real32_T KfAEBS_a_BrakeMax = -2.5F;    /* Variable: KfAEBS_a_BrakeMax
                                        * Referenced by:
                                        *   '<S42>/KfAEBS_a_BrakeMax'
                                        *   '<S42>/Constant4'
                                        * In passensor protected stage,acceleration send maximum
                                        */
real32_T KfAEBS_a_Buffer = -1.5F;      /* Variable: KfAEBS_a_Buffer
                                        * Referenced by:
                                        *   '<S89>/Constant1'
                                        *   '<S89>/Constant3'
                                        * Acceleration send buffer in distance safe
                                        */
real32_T KfAEBS_a_FullBrakeHi = -7.9F; /* Variable: KfAEBS_a_FullBrakeHi
                                        * Referenced by:
                                        *   '<S42>/KfAEBS_a_FullBrakeHi'
                                        *   '<S42>/Constant9'
                                        *   '<S76>/Constant1'
                                        *   '<S76>/Constant6'
                                        *   '<S76>/Constant8'
                                        *   '<S86>/Constant10'
                                        * Maximum decceleration send in full brake(ex. -5)
                                        */
real32_T KfAEBS_a_FullBrakeLo = -1.0F; /* Variable: KfAEBS_a_FullBrakeLo
                                        * Referenced by:
                                        *   '<S42>/KfAEBS_a_FullBrakeLo'
                                        *   '<S42>/Constant8'
                                        * Minimum decceleration send in full brake(ex. -2.5)
                                        */
real32_T KfAEBS_a_ObjUrgentBrake_Thrsh = -2.5F;/* Variable: KfAEBS_a_ObjUrgentBrake_Thrsh
                                                * Referenced by: '<S76>/Constant5'
                                                */
real32_T KfAEBS_a_PartialBrakeHi = -4.0F;/* Variable: KfAEBS_a_PartialBrakeHi
                                          * Referenced by:
                                          *   '<S42>/KfAEBS_a_PartialBrakeHi'
                                          *   '<S42>/Constant7'
                                          * Maximum decceleration send in partial brake(ex. -4)
                                          */
real32_T KfAEBS_a_PartialBrakeLo = -1.0F;/* Variable: KfAEBS_a_PartialBrakeLo
                                          * Referenced by:
                                          *   '<S42>/KfAEBS_a_PartialBrakeLo'
                                          *   '<S42>/Constant6'
                                          * Minimum decceleration send in partial brake(ex. -2)
                                          */
real32_T KfAEBS_d_Dis2HeadIgnoreSide = 0.0F;/* Variable: KfAEBS_d_Dis2HeadIgnoreSide
                                             * Referenced by:
                                             *   '<S9>/KfAEBS_d_Dis2HeadIgnoreSide'
                                             *   '<S9>/Constant44'
                                             */
real32_T KfAEBS_d_Dis_BufferTTSP = 0.1F;/* Variable: KfAEBS_d_Dis_BufferTTSP
                                         * Referenced by:
                                         *   '<S9>/KfAEBS_d_Dis_BufferTTSP'
                                         *   '<S9>/Constant8'
                                         * Distance Buffer when calculate TTSP lateral
                                         */
real32_T KfAEBS_d_Dis_BufferTTSP_length = 2.0F;/* Variable: KfAEBS_d_Dis_BufferTTSP_length
                                                * Referenced by:
                                                *   '<S9>/KfAEBS_d_Dis_BufferTTSP_length'
                                                *   '<S9>/Constant9'
                                                * Distance Buffer when calculate TTSP long
                                                */
real32_T KfAEBS_d_Dis_LateralIgnore = 10.0F;/* Variable: KfAEBS_d_Dis_LateralIgnore
                                             * Referenced by:
                                             *   '<S9>/KfAEBS_d_Dis_LateralIgnore'
                                             *   '<S9>/Constant27'
                                             * Distance Lateral Ignore
                                             */
real32_T KfAEBS_d_Dis_Safe = 0.8F;     /* Variable: KfAEBS_d_Dis_Safe
                                        * Referenced by: '<S76>/Constant15'
                                        * Distance safe, when vehicle is stopped, the distance to obj
                                        */
real32_T KfAEBS_d_Dis_Safe_VRU = 2.5F; /* Variable: KfAEBS_d_Dis_Safe_VRU
                                        * Referenced by: '<S76>/Constant12'
                                        */
real32_T KfAEBS_d_lateral_max_lostClose = 0.5F;/* Variable: KfAEBS_d_lateral_max_lostClose
                                                * Referenced by:
                                                *   '<S95>/Constant2'
                                                *   '<S95>/Constant8'
                                                */
real32_T KfAEBS_d_lateral_min_lostClose = 0.0F;/* Variable: KfAEBS_d_lateral_min_lostClose
                                                * Referenced by:
                                                *   '<S95>/Constant10'
                                                *   '<S95>/Constant3'
                                                */
real32_T KfAEBS_d_long_max_lostClose = 2.0F;/* Variable: KfAEBS_d_long_max_lostClose
                                             * Referenced by:
                                             *   '<S95>/Constant7'
                                             *   '<S95>/Constant9'
                                             */
real32_T KfAEBS_d_long_min_lostClose = 0.0F;/* Variable: KfAEBS_d_long_min_lostClose
                                             * Referenced by:
                                             *   '<S95>/Constant1'
                                             *   '<S95>/Constant6'
                                             */
real32_T KfAEBS_d_min_dis_swap = 6.0F; /* Variable: KfAEBS_d_min_dis_swap
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_d_min_dis_swap'
                                        *   '<S9>/Constant37'
                                        */
real32_T KfAEBS_t_BrkPdlDeprssd_Thrsh = 2.0F;/* Variable: KfAEBS_t_BrkPdlDeprssd_Thrsh
                                              * Referenced by:
                                              *   '<S3>/KfAEBS_t_BrkPdlDeprssd_Thrsh'
                                              *   '<S3>/Constant3'
                                              */
real32_T KfAEBS_t_Speed_DebounceTime = 0.3F;/* Variable: KfAEBS_t_Speed_DebounceTime
                                             * Referenced by:
                                             *   '<S79>/Constant8'
                                             *   '<S205>/Constant8'
                                             * Speed debounce time, used to estimate whether the vheicle is standstill
                                             */
real32_T KfAEBS_t_TTC_DeactiveThrsh = 100000.0F;/* Variable: KfAEBS_t_TTC_DeactiveThrsh
                                                 * Referenced by:
                                                 *   '<S204>/Constant2'
                                                 *   '<S90>/Constant2'
                                                 * TTC Deactive Thrsh
                                                 */
real32_T KfAEBS_t_TTC_FCWLevel1DeactThrsd = 11.0F;/* Variable: KfAEBS_t_TTC_FCWLevel1DeactThrsd
                                                   * Referenced by: '<S207>/Constant1'
                                                   * TTC_FCW Level1 Deact Thrsd
                                                   */
real32_T KfAEBS_t_TTC_FCWLevel2DeactThrsd = 8.0F;/* Variable: KfAEBS_t_TTC_FCWLevel2DeactThrsd
                                                  * Referenced by: '<S208>/Constant1'
                                                  * TTC FCW Level2 Deact Thrsd
                                                  */
real32_T KfAEBS_t_TTC_FCWLevel3DeactThrsd = 7.0F;/* Variable: KfAEBS_t_TTC_FCWLevel3DeactThrsd
                                                  * Referenced by: '<S209>/Constant1'
                                                  * TTC FCW Level3 Deact Thrsd
                                                  */
real32_T KfAEBS_t_TTC_ObjChangThrsd = 6.0F;/* Variable: KfAEBS_t_TTC_ObjChangThrsd
                                            * Referenced by: '<S204>/Constant1'
                                            */
real32_T KfAEBS_t_TTC_PartialBrkDeactiveThrsd = 10.0F;/* Variable: KfAEBS_t_TTC_PartialBrkDeactiveThrsd
                                                       * Referenced by: '<S82>/Constant4'
                                                       * TTC Partial Brk Deactive Thrsd
                                                       */
real32_T KfAEBS_t_TTC_PreBrkDeactThrsd = 10.0F;/* Variable: KfAEBS_t_TTC_PreBrkDeactThrsd
                                                * Referenced by: '<S83>/Constant1'
                                                * KfAEBS TTC PreBrk Deact Thrsd
                                                */
real32_T KfAEBS_t_TimeBrakeConfdConfirmed = 1.0F;/* Variable: KfAEBS_t_TimeBrakeConfdConfirmed
                                                  * Referenced by:
                                                  *   '<S3>/KfAEBS_t_TimeBrakeConfdConfirmed'
                                                  *   '<S3>/Constant27'
                                                  */
real32_T KfAEBS_t_TimeBrakeThrsd = 10.0F;/* Variable: KfAEBS_t_TimeBrakeThrsd
                                          * Referenced by: '<S92>/VRednThdASILAInCllsnRednByBrkg1'
                                          */
real32_T KfAEBS_t_TimeExitActide = 0.6F;/* Variable: KfAEBS_t_TimeExitActide
                                         * Referenced by:
                                         *   '<S3>/KfAEBS_t_TimeExitActide'
                                         *   '<S3>/Constant1'
                                         */
real32_T KfAEBS_t_TimePreBrkThrsd = 5.0F;/* Variable: KfAEBS_t_TimePreBrkThrsd
                                          * Referenced by: '<S96>/VRednThdASILAInCllsnRednByBrkg1'
                                          */
real32_T KfAEBS_t_TimeWait2StandbyThrsh = 10.0F;/* Variable: KfAEBS_t_TimeWait2StandbyThrsh
                                                 * Referenced by:
                                                 *   '<S3>/KfAEBS_t_TimeWait2StandbyThrsh'
                                                 *   '<S3>/Constant28'
                                                 */
real32_T KfAEBS_t_Time_BrakeDelay = 0.0F;/* Variable: KfAEBS_t_Time_BrakeDelay
                                          * Referenced by: '<S76>/Constant2'
                                          * Time Brake Delay
                                          */
real32_T KfAEBS_t_Time_BrakeInit = 0.0F;/* Variable: KfAEBS_t_Time_BrakeInit
                                         * Referenced by:
                                         *   '<S42>/KfAEBS_t_Time_BrakeInit'
                                         *   '<S42>/Constant3'
                                         * Time Brake Init
                                         */
real32_T KfAEBS_t_Time_BrakeRamp = 0.0F;/* Variable: KfAEBS_t_Time_BrakeRamp
                                         * Referenced by:
                                         *   '<S42>/KfAEBS_t_Time_BrakeRamp'
                                         *   '<S42>/Constant5'
                                         * Time Brake Ramp
                                         */
real32_T KfAEBS_t_Time_HasNoVIPDelay = 0.3F;/* Variable: KfAEBS_t_Time_HasNoVIPDelay
                                             * Referenced by:
                                             *   '<S204>/Constant3'
                                             *   '<S91>/Constant3'
                                             * Time Has No VIP Delay
                                             */
real32_T KfAEBS_t_Time_OBFUNReceivedThrsh = 4.0F;/* Variable: KfAEBS_t_Time_OBFUNReceivedThrsh
                                                  * Referenced by:
                                                  *   '<S12>/Constant2'
                                                  *   '<S12>/Constant7'
                                                  * OBFU not receive time out
                                                  */
real32_T KfAEBS_t_Time_ObjUrgentBrk = 1.0F;/* Variable: KfAEBS_t_Time_ObjUrgentBrk
                                            * Referenced by: '<S76>/Constant7'
                                            */
real32_T KfAEBS_t_Time_ResetTimeBrkThrsd = 1.0F;/* Variable: KfAEBS_t_Time_ResetTimeBrkThrsd
                                                 * Referenced by: '<S101>/Constant3'
                                                 */
real32_T KfAEBS_t_Time_ResetVeloRdctThrsd = 1.0F;/* Variable: KfAEBS_t_Time_ResetVeloRdctThrsd
                                                  * Referenced by: '<S101>/Constant1'
                                                  */
real32_T KfAEBS_t_Time_TTCHLInhibitAEB = 5.0F;/* Variable: KfAEBS_t_Time_TTCHLInhibitAEB
                                               * Referenced by:
                                               *   '<S204>/Constant7'
                                               *   '<S90>/Constant4'
                                               *   '<S145>/Constant1'
                                               */
real32_T KfAEBS_t_Time_TwiceAEBActive = 5.0F;/* Variable: KfAEBS_t_Time_TwiceAEBActive
                                              * Referenced by: '<S142>/Constant4'
                                              */
real32_T KfAEBS_t_Time_TwiceFCWActive = 2.0F;/* Variable: KfAEBS_t_Time_TwiceFCWActive
                                              * Referenced by: '<S219>/Constant4'
                                              */
real32_T KfAEBS_t_Time_TwicePreBrkActive = 2.0F;/* Variable: KfAEBS_t_Time_TwicePreBrkActive
                                                 * Referenced by: '<S143>/Constant4'
                                                 */
real32_T KfAEBS_t_VipCloseLostTimeOut = 5.0F;/* Variable: KfAEBS_t_VipCloseLostTimeOut
                                              * Referenced by: '<S118>/Constant1'
                                              */
real32_T KfAEBS_t_fb_active_delay_turn = 0.0F;/* Variable: KfAEBS_t_fb_active_delay_turn
                                               * Referenced by: '<S129>/Constant6'
                                               */
real32_T KfAEBS_t_pb_active_delay_turn = 0.0F;/* Variable: KfAEBS_t_pb_active_delay_turn
                                               * Referenced by: '<S136>/Constant6'
                                               */
real32_T KfAEBS_t_timeGap_ignore_turn = 3.0F;/* Variable: KfAEBS_t_timeGap_ignore_turn
                                              * Referenced by:
                                              *   '<S9>/KfAEBS_t_timeGap_ignore_turn'
                                              *   '<S9>/Constant6'
                                              */
real32_T KfAEBS_v_ObjUrgentBrk_speed_Thrsh = 10.0F;/* Variable: KfAEBS_v_ObjUrgentBrk_speed_Thrsh
                                                    * Referenced by: '<S76>/Constant11'
                                                    */
real32_T KfAEBS_v_SpdCollisionInhibitAEB = 0.5F;/* Variable: KfAEBS_v_SpdCollisionInhibitAEB
                                                 * Referenced by: '<S145>/Constant2'
                                                 */
real32_T KfAEBS_v_SpeedLLThrshOvrrd = 3.0F;/* Variable: KfAEBS_v_SpeedLLThrshOvrrd
                                            * Referenced by: '<S41>/TiDlyDeactvnInCllsnRednByBrkg3'
                                            */
real32_T KfAEBS_v_SpeedRelLThrshOvrrd = 1.0F;/* Variable: KfAEBS_v_SpeedRelLThrshOvrrd
                                              * Referenced by: '<S41>/TiDlyDeactvnInCllsnRednByBrkg1'
                                              */
real32_T KfAEBS_v_Speed_DeltaStStThrsh = 0.1F;/* Variable: KfAEBS_v_Speed_DeltaStStThrsh
                                               * Referenced by:
                                               *   '<S79>/Constant7'
                                               *   '<S205>/Constant7'
                                               * delta speed, used to estimate whether the vheicle is standstill
                                               */
real32_T KfAEBS_v_Speed_DeltaWExit = 0.5F;/* Variable: KfAEBS_v_Speed_DeltaWExit
                                           * Referenced by:
                                           *   '<S9>/KfAEBS_v_Speed_DeltaWExit'
                                           *   '<S9>/Constant26'
                                           * Delta speed warning exit, if front veh's speed is larger than ego, fornt veh can be filterd
                                           */
real32_T KfAEBS_v_Speed_High_InhibitAEB = 33.0F;/* Variable: KfAEBS_v_Speed_High_InhibitAEB
                                                 * Referenced by: '<S145>/Constant3'
                                                 */
real32_T KfAEBS_v_Speed_MaxInhibitAEB = 1.5F;/* Variable: KfAEBS_v_Speed_MaxInhibitAEB
                                              * Referenced by: '<S145>/Constant7'
                                              * The speed to active AEB
                                              */
real32_T KfAEBS_v_Speed_ObjStillThrsh = 2.0F;/* Variable: KfAEBS_v_Speed_ObjStillThrsh
                                              * Referenced by:
                                              *   '<S9>/KfAEBS_v_Speed_ObjStillThrsh'
                                              *   '<S9>/Constant14'
                                              * Obj speed threshold to be estimated as standstill in long
                                              */
real32_T KfAEBS_v_Speed_ObjStillThrshLateral = 0.3F;/* Variable: KfAEBS_v_Speed_ObjStillThrshLateral
                                                     * Referenced by:
                                                     *   '<S9>/KfAEBS_v_Speed_ObjStillThrshLateral'
                                                     *   '<S9>/Constant25'
                                                     * Obj speed threshold to be estimated as standstill in lateral
                                                     */
real32_T KfAEBS_v_Speed_StandStillThrsh = 0.3F;/* Variable: KfAEBS_v_Speed_StandStillThrsh
                                                * Referenced by:
                                                *   '<S79>/Constant6'
                                                *   '<S205>/Constant6'
                                                * Speed, used to estimate whether the vheicle is standstill
                                                */
real32_T KfAEBS_v_VipStationaryThrshld = 1.0F;/* Variable: KfAEBS_v_VipStationaryThrshld
                                               * Referenced by:
                                               *   '<S94>/Constant1'
                                               *   '<S94>/Constant9'
                                               */
real32_T KfAEBS_v_deltaSpeed_InhibitAEB = 1.5F;/* Variable: KfAEBS_v_deltaSpeed_InhibitAEB
                                                * Referenced by: '<S145>/Constant5'
                                                */
real32_T KfAEBS_v_isInHighSpeed_HighThrshd = 20.0F;/* Variable: KfAEBS_v_isInHighSpeed_HighThrshd
                                                    * Referenced by: '<S123>/Constant2'
                                                    */
real32_T KfAEBS_v_isInHighSpeed_LowThrshd = 18.0F;/* Variable: KfAEBS_v_isInHighSpeed_LowThrshd
                                                   * Referenced by: '<S123>/Constant1'
                                                   */
real32_T KfAEBS_v_obsSpdBuffer = 1.0F; /* Variable: KfAEBS_v_obsSpdBuffer
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_v_obsSpdBuffer'
                                        *   '<S9>/Constant13'
                                        */
real32_T KfAEBS_v_obsSpeedArcMin = -0.3F;/* Variable: KfAEBS_v_obsSpeedArcMin
                                          * Referenced by:
                                          *   '<S9>/KfAEBS_v_obsSpeedArcMin'
                                          *   '<S9>/Constant11'
                                          */
real32_T KfAEBS_v_speed_max_lostClose = 5.0F;/* Variable: KfAEBS_v_speed_max_lostClose
                                              * Referenced by: '<S95>/Constant4'
                                              */
real32_T KfAEBS_v_speed_min_lostClose = 0.0F;/* Variable: KfAEBS_v_speed_min_lostClose
                                              * Referenced by: '<S95>/Constant5'
                                              */
real32_T KtAEBS_FCWL1ActiveTTCThrshld[13] =
{
  2.0F, 2.2F, 2.4F, 2.6F, 2.8F, 3.0F, 3.2F, 3.4F, 3.6F, 3.8F, 4.0F, 4.2F, 4.5F
} ;                                    /* Variable: KtAEBS_FCWL1ActiveTTCThrshld
                                        * Referenced by: '<S207>/Partial_FCWL1TTCThreshold_table'
                                        */

real32_T KtAEBS_FCWL2ActiveTTCThrshld[13] =
{
  2.0F, 2.2F, 2.4F, 2.6F, 2.8F, 3.0F, 3.2F, 3.4F, 3.6F, 3.8F, 4.0F, 4.2F, 4.5F
} ;                                    /* Variable: KtAEBS_FCWL2ActiveTTCThrshld
                                        * Referenced by: '<S208>/Partial_FCWL2TTCThreshold_table'
                                        */

real32_T KtAEBS_FCWL3ActiveTTCThrshld[13] =
{
  2.0F, 2.2F, 2.4F, 2.6F, 2.8F, 3.0F, 3.2F, 3.4F, 3.6F, 3.8F, 4.0F, 4.2F, 4.5F
} ;                                    /* Variable: KtAEBS_FCWL3ActiveTTCThrshld
                                        * Referenced by: '<S209>/Partial_FCWL3TTCThreshold_table'
                                        */

real32_T KtAEBS_FullBrkActiveAccThrshld[13] =
{
  -3.0F, -3.0F, -3.0F, -3.0F, -3.0F, -3.25F, -3.5F, -3.5F, -3.5F, -3.75F, -3.75F,
  -3.75F, -3.75F
} ;                                    /* Variable: KtAEBS_FullBrkActiveAccThrshld
                                        * Referenced by: '<S126>/Full_BrkActiveAccThreshold_table'
                                        */

real32_T KtAEBS_LateralBuffer_Bicycle[11] =
{
  0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 0.9F, 0.9F, 0.9F
} ;                                    /* Variable: KtAEBS_LateralBuffer_Bicycle
                                        * Referenced by: '<S171>/lateral_buffer_bicycle_table'
                                        */

real32_T KtAEBS_LateralBuffer_Motor[11] =
{
  0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 0.9F, 0.9F, 0.9F
} ;                                    /* Variable: KtAEBS_LateralBuffer_Motor
                                        * Referenced by: '<S172>/lateral_buffer_motorcycle_table'
                                        */

real32_T KtAEBS_LateralBuffer_Other[11] =
{
  0.0F, 0.0F, 0.1F, 0.1F, 0.2F, 0.2F, 0.3F, 0.3F, 0.4F, 0.4F, 0.4F
} ;                                    /* Variable: KtAEBS_LateralBuffer_Other
                                        * Referenced by: '<S173>/lateral_buffer_other_table'
                                        */

real32_T KtAEBS_LateralBuffer_Pedstrn[11] =
{
  0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 0.9F, 0.9F, 0.9F
} ;                                    /* Variable: KtAEBS_LateralBuffer_Pedstrn
                                        * Referenced by: '<S174>/lateral_buffer_pedestrain_table'
                                        */

real32_T KtAEBS_LateralBuffer_Vehicle[11] =
{
  0.0F, 0.0F, 0.1F, 0.1F, 0.2F, 0.2F, 0.3F, 0.3F, 0.4F, 0.4F, 0.4F
} ;                                    /* Variable: KtAEBS_LateralBuffer_Vehicle
                                        * Referenced by: '<S175>/lateral_buffer_vehicle_table'
                                        */

real32_T KtAEBS_LongBuffer_Bicycle[11] =
{
  0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 0.9F, 0.9F, 0.9F
} ;                                    /* Variable: KtAEBS_LongBuffer_Bicycle
                                        * Referenced by: '<S176>/long_buffer_bicycle_table'
                                        */

real32_T KtAEBS_LongBuffer_Motor[11] =
{
  0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 0.9F, 0.9F, 0.9F
} ;                                    /* Variable: KtAEBS_LongBuffer_Motor
                                        * Referenced by: '<S177>/long_buffer_motorcycle_table'
                                        */

real32_T KtAEBS_LongBuffer_Other[11] =
{
  0.0F, 0.0F, 0.1F, 0.1F, 0.2F, 0.2F, 0.3F, 0.3F, 0.4F, 0.4F, 0.4F
} ;                                    /* Variable: KtAEBS_LongBuffer_Other
                                        * Referenced by: '<S178>/long_buffer_other_table'
                                        */

real32_T KtAEBS_LongBuffer_Pedstrn[11] =
{
  0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 0.9F, 0.9F, 0.9F
} ;                                    /* Variable: KtAEBS_LongBuffer_Pedstrn
                                        * Referenced by: '<S179>/long_buffer_pedestrain_table'
                                        */

real32_T KtAEBS_LongBuffer_Vehicle[11] =
{
  0.0F, 0.0F, 0.1F, 0.1F, 0.2F, 0.2F, 0.3F, 0.3F, 0.4F, 0.4F, 0.4F
} ;                                    /* Variable: KtAEBS_LongBuffer_Vehicle
                                        * Referenced by: '<S180>/long_buffer_vehicle_table'
                                        */

real32_T KtAEBS_PreBrkActiveTTCThrshld[13] =
{
  3.0F, 3.2F, 3.4F, 3.6F, 3.8F, 4.0F, 4.2F, 4.4F, 4.6F, 4.8F, 5.0F, 5.2F, 5.5F
} ;                                    /* Variable: KtAEBS_PreBrkActiveTTCThrshld
                                        * Referenced by: '<S141>/Pre_BrakeActiveTTCThreshold_table'
                                        */

real32_T KtAEBS_PreBrkActiveTTCThrshld_VRU[13] =
{
  3.5F, 3.7F, 3.9F, 4.1F, 4.3F, 4.5F, 4.7F, 4.9F, 5.1F, 5.3F, 5.5F, 5.7F, 6.0F
} ;                                    /* Variable: KtAEBS_PreBrkActiveTTCThrshld_VRU
                                        * Referenced by: '<S141>/Pre_BrakeActiveTTCThreshold_VRU_table'
                                        */

real32_T KtAEBS_PrtlBrkActiveTTCThrshld[13] =
{
  1.2F, 1.4F, 1.6F, 1.8F, 2.0F, 2.2F, 2.4F, 2.6F, 2.8F, 3.0F, 3.2F, 3.2F, 3.5F
} ;                                    /* Variable: KtAEBS_PrtlBrkActiveTTCThrshld
                                        * Referenced by: '<S134>/Partial_BrakeActiveTTCThreshold_table'
                                        */

real32_T KtAEBS_PrtlBrkActiveTTCThrshld_VRU[13] =
{
  2.0F, 2.2F, 2.4F, 2.6F, 2.8F, 3.0F, 3.2F, 3.4F, 3.6F, 3.8F, 4.0F, 4.2F, 4.5F
} ;                                    /* Variable: KtAEBS_PrtlBrkActiveTTCThrshld_VRU
                                        * Referenced by: '<S134>/Partial_BrakeActiveTTCThreshold_VRU_table'
                                        */

real32_T KtAEBS_a_BrakeValueLimit[10] =
{
  -7.9F, -7.9F, -7.9F, -7.9F, -7.9F, -7.9F, -7.9F, -7.9F, -7.9F, -7.9F
} ;                                    /* Variable: KtAEBS_a_BrakeValueLimit
                                        * Referenced by: '<S48>/BrakeValueLimit_Table'
                                        */

real32_T KtAEBS_veh_acc_inhibit_AEB_thrhd[9] =
{
  6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F
} ;                                    /* Variable: KtAEBS_veh_acc_inhibit_AEB_thrhd
                                        * Referenced by: '<S146>/veh_acc_AEB_inhibit_thrhd_table'
                                        */

real32_T KtAEBS_veh_widthGain[9] =
{
  0.8F, 0.82F, 0.83F, 0.84F, 0.86F, 0.89F, 0.9F, 0.95F, 0.98F
} ;                                    /* Variable: KtAEBS_veh_widthGain
                                        * Referenced by: '<S9>/veh_widthGain_table'
                                        */

int32_T KfAEBS_Default_AEBS_obj_ID = 0;/* Variable: KfAEBS_Default_AEBS_obj_ID
                                        * Referenced by: '<S2>/Constant13'
                                        * Default AEBS obj ID
                                        */
int8_T KfAEBS_VIPObsType = 4;          /* Variable: KfAEBS_VIPObsType
                                        * Referenced by: '<S164>/Constant1'
                                        */
uint8_T KfAEBS_AccPdl_InhbtDeact_thrshld = 85U;/* Variable: KfAEBS_AccPdl_InhbtDeact_thrshld
                                                * Referenced by:
                                                *   '<S77>/Constant9'
                                                *   '<S84>/Constant2'
                                                *   '<S210>/Constant2'
                                                */
uint8_T KfAEBS_AccPedelThrshOvrrd = 5U;/* Variable: KfAEBS_AccPedelThrshOvrrd
                                        * Referenced by: '<S41>/TiDlyDeactvnInCllsnRednByBrkg4'
                                        * Acc Pedel threshold when override
                                        */
uint8_T KfAEBS_Confdnc_FullBrkActThrsd = 0U;/* Variable: KfAEBS_Confdnc_FullBrkActThrsd
                                             * Referenced by: '<S81>/Constant3'
                                             */
uint8_T KfAEBS_Confdnc_PartialBrkActThrsd = 0U;/* Variable: KfAEBS_Confdnc_PartialBrkActThrsd
                                                * Referenced by: '<S82>/Constant3'
                                                */
uint8_T KfAEBS_Confidnc_Deact_thrshld = 0U;/* Variable: KfAEBS_Confidnc_Deact_thrshld
                                            * Referenced by: '<S77>/Constant1'
                                            */
uint8_T KfAEBS_Default_AEB_error = 0U; /* Variable: KfAEBS_Default_AEB_error
                                        * Referenced by: '<S2>/Constant12'
                                        * Default AEB error
                                        */
uint8_T KfAEBS_Default_FCW_error = 0U; /* Variable: KfAEBS_Default_FCW_error
                                        * Referenced by: '<S2>/Constant4'
                                        * Default FCW error
                                        */
uint8_T KfAEBS_Default_FCW_warn_level = 0U;/* Variable: KfAEBS_Default_FCW_warn_level
                                            * Referenced by: '<S2>/Constant1'
                                            * Default FCW warn level
                                            */
uint8_T KfAEBS_EPB_Engaged_Value = 1U; /* Variable: KfAEBS_EPB_Engaged_Value
                                        * Referenced by: '<S8>/Constant4'
                                        */
uint8_T KfAEBS_Gear_Value_R = 13U;     /* Variable: KfAEBS_Gear_Value_R
                                        * Referenced by:
                                        *   '<S84>/Constant1'
                                        *   '<S210>/Constant1'
                                        * Gear_Value_R
                                        */
uint8_T KfAEBS_LoPosValInCllsnRednByBrkg = 5U;/* Variable: KfAEBS_LoPosValInCllsnRednByBrkg
                                               * Referenced by:
                                               *   '<S43>/LoPosValInCllsnRednByBrkg  '
                                               *   '<S196>/LoPosValInCllsnRednByBrkg  '
                                               */
boolean_T KbAEBS_Active_LeftTurn = 1;  /* Variable: KbAEBS_Active_LeftTurn
                                        * Referenced by: '<S166>/Constant4'
                                        * Left turn collision mitigation active
                                        */
boolean_T KbAEBS_Active_RightTurn = 1; /* Variable: KbAEBS_Active_RightTurn
                                        * Referenced by: '<S166>/Constant3'
                                        * Right turn collision mitigation active
                                        */
boolean_T KbAEBS_Active_Straight = 1;  /* Variable: KbAEBS_Active_Straight
                                        * Referenced by: '<S166>/Constant2'
                                        * Ego go straight collision mitigation active
                                        */
boolean_T KbAEBS_AllowOverride = 0;    /* Variable: KbAEBS_AllowOverride
                                        * Referenced by: '<S41>/TiDlyDeactvnInCllsnRednByBrkg2'
                                        * Allow driver override
                                        */
boolean_T KbAEBS_Default_AEB_brakeLight_req = 0;/* Variable: KbAEBS_Default_AEB_brakeLight_req
                                                 * Referenced by: '<S2>/Constant8'
                                                 * Default AEB brakeLight req
                                                 */
boolean_T KbAEBS_Default_AEB_prebrake_req = 0;/* Variable: KbAEBS_Default_AEB_prebrake_req
                                               * Referenced by: '<S2>/Constant6'
                                               * Default AEB prebrake req
                                               */
boolean_T KbAEBS_Default_AEB_request = 0;/* Variable: KbAEBS_Default_AEB_request
                                          * Referenced by: '<S2>/Constant5'
                                          * Default AEB request
                                          */
boolean_T KbAEBS_Default_FCW_requset = 0;/* Variable: KbAEBS_Default_FCW_requset
                                          * Referenced by: '<S2>/Constant'
                                          * Default FCW requset
                                          */
boolean_T KbAEBS_Enable_AEB_feature = 0;/* Variable: KbAEBS_Enable_AEB_feature
                                         * Referenced by: '<S1>/Constant27'
                                         */
boolean_T KbAEBS_Enable_DoRbIW = 0;    /* Variable: KbAEBS_Enable_DoRbIW
                                        * Referenced by:
                                        *   '<S9>/KbAEBS_Enable_DoRbIW'
                                        *   '<S9>/Constant34'
                                        */
boolean_T KbAEBS_Enable_DoRbIW_LeftTurn = 0;/* Variable: KbAEBS_Enable_DoRbIW_LeftTurn
                                             * Referenced by:
                                             *   '<S9>/KbAEBS_Enable_DoRbIW_LeftTurn'
                                             *   '<S9>/Constant38'
                                             */
boolean_T KbAEBS_Enable_Error = 0;     /* Variable: KbAEBS_Enable_Error
                                        * Referenced by: '<S6>/Constant31'
                                        */
boolean_T KbAEBS_Enable_OutputAEB = 1; /* Variable: KbAEBS_Enable_OutputAEB
                                        * Referenced by:
                                        *   '<S39>/Constant3'
                                        *   '<S39>/Constant4'
                                        * Enable output decceleration/ AEB request
                                        */
boolean_T KbAEBS_Enable_VRU_Calibration = 1;/* Variable: KbAEBS_Enable_VRU_Calibration
                                             * Referenced by: '<S78>/Constant2'
                                             */
boolean_T KbAEBS_FilterVehicleinSide = 1;/* Variable: KbAEBS_FilterVehicleinSide
                                          * Referenced by:
                                          *   '<S9>/KbAEBS_FilterVehicleinSide'
                                          *   '<S9>/Constant45'
                                          */
boolean_T KbAEBS_RedifineVIPObsType = 1;/* Variable: KbAEBS_RedifineVIPObsType
                                         * Referenced by: '<S164>/Constant5'
                                         */
boolean_T KbAEBS_Test_Mode = 0;        /* Variable: KbAEBS_Test_Mode
                                        * Referenced by:
                                        *   '<S9>/Constant31'
                                        *   '<S9>/Constant33'
                                        */
boolean_T KbAEBS_Use_CAN_VehSpeed = 1; /* Variable: KbAEBS_Use_CAN_VehSpeed
                                        * Referenced by: '<S6>/Constant3'
                                        */
boolean_T KbAEBS_Use_OBFU_Acceleration = 0;/* Variable: KbAEBS_Use_OBFU_Acceleration
                                            * Referenced by:
                                            *   '<S9>/KbAEBS_Use_OBFU_Acceleration'
                                            *   '<S9>/Constant39'
                                            */
boolean_T KbAEBS_Use_OBFU_Type = 0;    /* Variable: KbAEBS_Use_OBFU_Type
                                        * Referenced by:
                                        *   '<S9>/KbAEBS_Use_OBFU_Type'
                                        *   '<S9>/Constant40'
                                        */
boolean_T KbAEBS_enable_PreBrake = 0;  /* Variable: KbAEBS_enable_PreBrake
                                        * Referenced by: '<S84>/Constant4'
                                        */
boolean_T KbAEBS_use_OBFU_speed = 1;   /* Variable: KbAEBS_use_OBFU_speed
                                        * Referenced by:
                                        *   '<S9>/KbAEBS_use_OBFU_speed'
                                        *   '<S9>/Constant12'
                                        */
boolean_T KbAEBS_use_steerAngle = 1;   /* Variable: KbAEBS_use_steerAngle
                                        * Referenced by:
                                        *   '<S128>/Constant2'
                                        *   '<S135>/Constant2'
                                        */
boolean_T KfAEBS_Default_BrkPrioriy = 0;/* Variable: KfAEBS_Default_BrkPrioriy
                                         * Referenced by: '<S2>/Constant14'
                                         */
boolean_T KfAEBS_Default_Horn_Req = 0; /* Variable: KfAEBS_Default_Horn_Req
                                        * Referenced by: '<S2>/Constant9'
                                        */
EnumAEBS_EnblState KfAEBS_Default_AEB_enabled_state = AEBS_EnblState_OFF;/* Variable: KfAEBS_Default_AEB_enabled_state
                                                                      * Referenced by: '<S2>/Constant10'
                                                                      * Default AEB enabled state
                                                                      */
EnumAEBS_EnblState KfAEBS_Default_FCW_enable_state = AEBS_EnblState_OFF;/* Variable: KfAEBS_Default_FCW_enable_state
                                                                      * Referenced by: '<S2>/Constant2'
                                                                      * Default FCW enable state
                                                                      */
EnumAEBS_FCWState KfAEBS_Default_FCW_active_state = AEBS_FCWState_StandBy;/* Variable: KfAEBS_Default_FCW_active_state
                                                                      * Referenced by: '<S2>/Constant3'
                                                                      * Default FCW active state
                                                                      */
EnumAEBS_AEBState KfAEBS_Default_AEB_actived_state = AEBS_AEBState_StandBy;/* Variable: KfAEBS_Default_AEB_actived_state
                                                                      * Referenced by: '<S2>/Constant11'
                                                                      * Default AEB actived state
                                                                      */
#pragma section

/* Block signals (auto storage) */
B_AEBS_subsystem_integrated_T AEBS_subsystem_integrated_B;

/* Block states (auto storage) */
DW_AEBS_subsystem_integrated_T AEBS_subsystem_integrated_DW;

/* Model step function */
void AEBS_subsystem_integrated_step(void)
{
  /* Outputs for Atomic SubSystem: '<Root>/AEBS' */
  AEBS_subsystem_integrated_AEBS();

  /* End of Outputs for SubSystem: '<Root>/AEBS' */
}

/* Model initialize function */
void AEBS_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* block I/O */
  (void) memset(((void *) &AEBS_subsystem_integrated_B), 0,
                sizeof(B_AEBS_subsystem_integrated_T));

  {
    AEBS_subsystem_integrated_B.enable_state = AEBS_EnblState_OFF;
    AEBS_subsystem_integrated_B.enable_state_dli2 = AEBS_EnblState_OFF;
    AEBS_subsystem_integrated_B.actived_state = AEBS_FCWState_StandBy;
    AEBS_subsystem_integrated_B.actived_state_bp54 = AEBS_AEBState_StandBy;
  }

  /* exported global signals */
  VsAEBS_DataBus = AEBS_subsystem_integrated_rtZAEBS_DataBus;
  VfAEBS_m_1_a_x = 0.0F;
  VfAEBS_m_1_a_y = 0.0F;
  VfAEBS_m_1_length = 0.0F;
  VfAEBS_m_1_width = 0.0F;
  VfAEBS_m_2_NP_x = 0.0F;
  VfAEBS_m_2_NP_y = 0.0F;
  VfAEBS_m_3_NP_x = 0.0F;
  VfAEBS_m_3_NP_y = 0.0F;
  VfAEBS_m_2_heading = 0.0F;
  VfAEBS_m_3_heading = 0.0F;
  VfAEBS_m_4_NP_x = 0.0F;
  VfAEBS_m_4_NP_y = 0.0F;
  VfAEBS_m_4_heading = 0.0F;
  VfAEBS_m_2_length = 0.0F;
  VfAEBS_m_2_width = 0.0F;
  VfAEBS_m_3_length = 0.0F;
  VfAEBS_m_3_width = 0.0F;
  VfAEBS_m_4_length = 0.0F;
  VfAEBS_m_1_NP_x = 0.0F;
  VfAEBS_m_4_width = 0.0F;
  VfAEBS_m_1_NP_y = 0.0F;
  VfAEBS_m_1_heading = 0.0F;
  VfAEBS_m_1_v_x = 0.0F;
  VfAEBS_m_1_v_y = 0.0F;
  VfAEBS_m_EGMO_veh_speed = 0.0F;
  VfAEBS_m_EGMO_veh_acc = 0.0F;
  VfAEBS_m_EGMO_v_cur = 0.0F;
  VfAEBS_m_EGMO_v_x = 0.0F;
  VfAEBS_m_EGMO_v_y = 0.0F;
  VfAEBS_veh_speed_used = 0.0F;
  VfAEBS_speed_x_used = 0.0F;
  VfAEBS_speed_y_used = 0.0F;
  VfAEBS_veh_acc_used = 0.0F;
  VfAEBS_veh_cur_used = 0.0F;

  {
    int32_T i;
    for (i = 0; i < 32; i++)
    {
      VfAEBS_obs_delta_dis[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 32; i++)
    {
      VfAEBS_obs_delta_speed[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 32; i++)
    {
      VfAEBS_obs_ttc[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 32; i++)
    {
      VfAEBS_obs_dis2adc_long[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 32; i++)
    {
      VfAEBS_obs_dis2adc_lateral[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 32; i++)
    {
      VfAEBS_obs_v_long[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 32; i++)
    {
      VfAEBS_obs_v_lateral[i] = 0.0F;
    }
  }

  VfAEBS_obs_v_long_vip = 0.0F;
  VfAEBS_obs_acc_lateral_vip = 0.0F;
  VfAEBS_obs_acc_long_vip = 0.0F;
  VfAEBS_obs_NP_x_vip = 0.0F;
  VfAEBS_obs_NP_y_vip = 0.0F;
  VfAEBS_obs_heading_VIP = 0.0F;
  VfAEBS_obs_length_VIP = 0.0F;
  VfAEBS_obs_width_VIP = 0.0F;
  VfAEBS_obs_dis_long_VIP = 0.0F;
  VfAEBS_obs_dis_lateral_VIP = 0.0F;
  VfAEBS_obs_rp_vip = 0.0F;
  VfAEBS_obs_ttc_vip = 0.0F;
  VfAEBS_obs_delta_dis_vip = 0.0F;
  VfAEBS_obs_delta_speed_vip = 0.0F;
  VfAEBS_obs_v_lateral_vip = 0.0F;
  VfAEBS_Pre_BrakeActiveTTCThreshold = 0.0F;
  VfAEBS_Partial_BrakeActiveTTCThreshold = 0.0F;
  VfAEBS_v_obj_absolute_speed = 0.0F;
  VfAEBS_a_obj_absolute_acc = 0.0F;
  VfAEBS_areq_withoutDelay_UrgentBrk = 0.0F;
  VfAEBS_areq_withoutDelay = 0.0F;
  VfAEBS_dis_delay = 0.0F;
  VfAEBS_dis_safe_used = 0.0F;
  VfAEBS_areq = 0.0F;
  VfAEBS_Full_BrkActiveACCThreshold = 0.0F;
  VfAEBS_AEB_acceleration_af_filter = 0.0F;
  VfAEBS_AEB_acceleration_bf_limit = 0.0F;
  VfAEBS_AEB_accReq_beforeSend = 0.0F;
  VfAEBS_AEB_acceleration_req = 0.0F;
  VfAEBS_FedBck_Vehspd = 0.0F;
  VfAEBS_FedBck_AccLong = 0.0F;
  VfAEBS_FedBck_StrAngle = 0.0F;
  VfAEBS_FedBck_yawRate = 0.0F;
  VfAEBS_FedBck_AccLateral = 0.0F;
  VfAEBS_m_2_id = 0;
  VfAEBS_m_3_id = 0;
  VfAEBS_m_4_id = 0;
  VfAEBS_m_1_id = 0;
  VfAEBS_m_timestamp_high = 0;
  VfAEBS_m_EGMO_timestamp_h = 0;
  VfAEBS_obs_id_vip = 0;
  VfAEBS_AEBS_obs_id = 0;
  VfAEBS_m_timestamp_low = 0U;
  VfAEBS_m_EGMO_timestamp_l = 0U;
  VfAEBS_m_num_obstacles = 0U;
  VfAEBS_m_1_type = 0;
  VfAEBS_m_1_motion_status = 0;
  VfAEBS_m_1_position_zone = 0;
  VfAEBS_m_2_position_zone = 0;
  VfAEBS_m_2_motion_status = 0;
  VfAEBS_m_3_position_zone = 0;
  VfAEBS_m_3_motion_status = 0;
  VfAEBS_m_4_position_zone = 0;
  VfAEBS_m_4_motion_status = 0;
  VfAEBS_obs_position_zone_VIP = 0;
  VfAEBS_obs_motion_status_VIP = 0;
  VfAEBS_obs_type_vip = 0;
  VfAEBS_m_1_confidence = 0U;
  VfAEBS_m_2_confidence = 0U;
  VfAEBS_m_3_confidence = 0U;
  VfAEBS_m_4_confidence = 0U;

  {
    int32_T i;
    for (i = 0; i < 32; i++)
    {
      VfAEBS_obs_position_state[i] = 0U;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 32; i++)
    {
      VfAEBS_obs_filtered_type[i] = 0U;
    }
  }

  VfAEBS_obs_index_vip = 0U;
  VfAEBS_obs_confidence_VIP = 0U;
  VfAEBS_obs_position_state_vip = 0U;
  VfAEBS_FCW_warn_level = 0U;
  VfAEBS_FCW_error = 0U;
  VfAEBS_AEB_error = 0U;
  VfAEBS_FedBck_Drivemode = 0U;
  VfAEBS_FedBck_BrkLightState = 0U;
  VfAEBS_FedBck_BrkPedStatus = 0U;
  VfAEBS_FedBck_EPBstate = 0U;
  VfAEBS_FedBck_GearValue = 0U;
  VfAEBS_FedBck_BrkPedPos = 0U;
  VfAEBS_FedBck_AccPedPos = 0U;
  VfAEBS_FedBck_SmallLampState = ((uint8_T)0U);
  VfAEBS_FCW_enabled = false;
  VbAEBS_FCW_inhbt_AccPedPos = false;
  VbAEBS_FCW_inhbt_VehAcc = false;
  VbAEBS_FCW_inhbt_DeactTime = false;
  VbAEBS_FCW_inhibit = false;
  VfAEBS_FCWLev1_active = false;
  VfAEBS_FCWLev1_dactive = false;
  VfAEBS_FCWLev2_active = false;
  VfAEBS_FCWLev2_dactive = false;
  VfAEBS_FCWLev3_active = false;
  VfAEBS_FCWLev3_dactive = false;
  VfAEBS_FCW_disabled = false;
  VfAEBS_FCW_deacitve = false;
  VbAEBS_has_obs_vip = false;
  VfAEBS_Obj_IsVRU = false;
  VfAEBS_use_VRU_Calibration = false;
  VfAEBS_LowSpeed_InhibitAEB = false;
  VfAEBS_HighSpeed_InhibitAEB = false;
  VfAEBS_VehDeltaSpeed_InhibitAEB = false;
  VfAEBS_Speed_InhibitAEB = false;
  VfAEBS_Gear_InhibitAEB = false;
  VbAEBS_AEB_inhbt_DeactTime = false;
  VbAEBS_AEB_inhbt_AccPdl = false;
  VbAEBS_AEB_inhbt_StrAngRte = false;
  VbAEBS_AEB_inhbt_veh_acc = false;
  VfAEBS_AEB_inhibit = false;
  VbAEBS_PreBrk_inhbt_deactTime = false;
  VbAEBS_preBrake_inhibit = false;
  VfAEBS_preBrake_active = false;
  VfAEBS_partialBrk_active = false;
  VfAEBS_fullBrk_active = false;
  VbAEBS_Deactive_R_NoVIP = false;
  VbAEBS_vipCloseLost = false;
  VbAEBS_vipStationary = false;
  VbAEBS_Deactive_R_VIPChanged = false;
  VfAEBS_DeniedDueToSpdRed = false;
  VfAEBS_DeniedDueToTimeBrake = false;
  VbAEBS_Deactive_R_Confdnc = false;
  VbAEBS_deactive_preBrk_timeOut = false;
  VfAEBS_AEB_enabled = false;
  VfAEBS_preBrake_dactive = false;
  VfAEBS_partialBrk_dactive = false;
  VfAEBS_fullBrk_dactive = false;
  VfAEBS_AEB_disabled = false;
  VfAEBS_veh_standstill = false;
  VfAEBS_Vehicle_isInHighSpeed = false;
  VfAEBS_AEB_deactive = false;
  VbAEBS_Deactive_R_HighTTC = false;
  VfAEBS_AEB_request_beforeSend = false;
  VfAEBS_FCW_request = false;
  VfAEBS_AEB_request = false;
  VfAEBS_AEB_prebrake_req = false;
  VfAEBS_brakeLight_req = false;
  VfAEBS_AEBS_brake_priority_setting = false;
  VfAEBS_AEBS_horn_ctrl_req = false;
  VfAEBS_FedBck_LeftLampState = false;
  VfAEBS_FedBck_RightLampState = false;
  VfAEBS_FCW_enable_state = AEBS_EnblState_OFF;
  VeAEBS_AEB_enabled_state = AEBS_EnblState_OFF;
  VfAEBS_FCW_active_state = AEBS_FCWState_StandBy;
  VeAEBS_AEB_actived_state = AEBS_AEBState_StandBy;
  VeAEBS_TurnType = AEBS_Straight;

  /* states (dwork) */
  (void) memset((void *)&AEBS_subsystem_integrated_DW, 0,
                sizeof(DW_AEBS_subsystem_integrated_T));

  /* Machine initializer */
  AEBS_subsystem_integrated_DW.data = 0.0;

  /* Start for Atomic SubSystem: '<Root>/AEBS' */
  AEBS_subsystem_integ_AEBS_Start();

  /* End of Start for SubSystem: '<Root>/AEBS' */

  /* ConstCode for Atomic SubSystem: '<Root>/AEBS' */
  AEBS_subsystem_integ_AEBS_Const();

  /* End of ConstCode for SubSystem: '<Root>/AEBS' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/AEBS' */
  AEBS_subsystem_integr_AEBS_Init();

  /* End of SystemInitialize for SubSystem: '<Root>/AEBS' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
