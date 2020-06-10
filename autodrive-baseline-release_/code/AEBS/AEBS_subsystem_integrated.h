/*
 * File: AEBS_subsystem_integrated.h
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

#ifndef RTW_HEADER_AEBS_subsystem_integrated_h_
#define RTW_HEADER_AEBS_subsystem_integrated_h_
#include <string.h>
#ifndef AEBS_subsystem_integrated_COMMON_INCLUDES_
# define AEBS_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* AEBS_subsystem_integrated_COMMON_INCLUDES_ */

#include "AEBS_subsystem_integrated_types.h"

/* Child system includes */
#include "AEBS.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct
{
  AEBS_Obs_VIP_info_Bus Switch;        /* '<S164>/Switch' */
  AEBS_AEB_Data BusCreator;            /* '<S39>/Bus Creator' */
  real32_T Assignment[120];            /* '<S167>/Assignment' */
  real32_T Assignment1[120];           /* '<S167>/Assignment1' */
  real32_T TimeBrake;                  /* '<S96>/BrakeTimeState' */
  real32_T SpeedReduction;             /* '<S101>/SpeedReductionStates' */
  real32_T TimeBrake_orpa;             /* '<S101>/BrakeTimeState' */
  real32_T veh_speed;                  /* '<S6>/Switch' */
  real32_T veh_speed_rel_x;            /* '<S6>/Switch4' */
  real32_T veh_acceleration;           /* '<S6>/Switch1' */
  real32_T DataTypeConversion8;        /* '<S14>/Data Type Conversion8' */
  real32_T veh_curvature;              /* '<S6>/Switch2' */
  real32_T veh_speed_rel_y;            /* '<S6>/Switch5' */
  real32_T DataTypeConversion11;       /* '<S14>/Data Type Conversion11' */
  uint8_T FCW_error;                   /* '<S193>/BusConversion_InsertedFor_FCW_data_at_inport_0' */
  uint8_T warn_level;                  /* '<S193>/DtrmnFCW_State' */
  uint8_T Switch2;                     /* '<S9>/Switch2' */
  uint8_T DataTypeConversion12;        /* '<S14>/Data Type Conversion12' */
  uint8_T DataTypeConversion2;         /* '<S14>/Data Type Conversion2' */
  uint8_T DataTypeConversion3;         /* '<S14>/Data Type Conversion3' */
  uint8_T DataTypeConversion4;         /* '<S14>/Data Type Conversion4' */
  uint8_T DataTypeConversion5;         /* '<S14>/Data Type Conversion5' */
  uint8_T Switch1;                     /* '<S9>/Switch1' */
  boolean_T vehicle_standstill;        /* '<S205>/Stop_Moving_Estimation' */
  boolean_T LogicalOperator;           /* '<S199>/Logical Operator' */
  boolean_T request;                   /* '<S193>/DtrmnFCW_State' */
  boolean_T Logic[2];                  /* '<S200>/Logic' */
  boolean_T RelationalOperator;        /* '<S8>/Relational Operator' */
  boolean_T LogicalOperator_pqhk;      /* '<S39>/Logical Operator' */
  boolean_T LogicalOperator_j5b5;      /* '<S46>/Logical Operator' */
  boolean_T Logic_lzmf[2];             /* '<S72>/Logic' */
  boolean_T Switch_eddh;               /* '<S41>/Switch' */
  EnumAEBS_EnblState enable_state;     /* '<S193>/DtrmnFCW_State' */
  EnumAEBS_EnblState enable_state_dli2;/* '<S39>/DtrmnAEB_State' */
  EnumAEBS_FCWState actived_state;     /* '<S193>/DtrmnFCW_State' */
  EnumAEBS_AEBState actived_state_bp54;/* '<S39>/DtrmnAEB_State' */
}
B_AEBS_subsystem_integrated_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
  struct
  {
    void *LoggedData;
  }
  Scope2_PWORK;                        /* '<S47>/Scope2' */

  struct
  {
    void *LoggedData;
  }
  Scope4_PWORK;                        /* '<S47>/Scope4' */

  struct
  {
    void *LoggedData;
  }
  Scope1_PWORK;                        /* '<S47>/Scope1' */

  real32_T UnitDelay_DSTATE;           /* '<S212>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S212>/Unit Delay1' */
  real32_T Delay_DSTATE[20];           /* '<S135>/Delay' */
  real32_T Delay_DSTATE_fido[20];      /* '<S128>/Delay' */
  real32_T UnitDelay_DSTATE_fbz5;      /* '<S94>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_pqdg;     /* '<S94>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S94>/Unit Delay2' */
  real32_T UnitDelay_DSTATE_lyfp;      /* '<S95>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_fg3i;     /* '<S95>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_j1zq;      /* '<S161>/UnitDelay' */
  real32_T Delay_DSTATE_igdy[20];      /* '<S144>/Delay' */
  real_T data;
  real32_T UnitDelay1_DSTATE_gojp;     /* '<S8>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_eswa;      /* '<S114>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_eowt;     /* '<S114>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_fchv;      /* '<S49>/Unit Delay' */
  real32_T UnitDelay_DSTATE_hf5d;      /* '<S51>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_feaq;     /* '<S42>/Unit Delay1' */
  real32_T UnitDelay1_DSTATE_hdmk;     /* '<S47>/Unit Delay1' */
  int32_T UnitDelay1_DSTATE_hjpc;      /* '<S211>/Unit Delay1' */
  int32_T UnitDelay1_DSTATE_krs0;      /* '<S113>/Unit Delay1' */
  int32_T UnitDelay_DSTATE_dinf;       /* '<S12>/Unit Delay' */
  int32_T UnitDelay1_DSTATE_mmx5;      /* '<S12>/Unit Delay1' */
  real32_T KfAEBS_CTRL_PeriodFunction_oryw;/* '<S3>/KfAEBS_CTRL_PeriodFunctionCall' */
  real32_T KfAEBS_a_BrakeHold_ci33;    /* '<S3>/KfAEBS_a_BrakeHold' */
  real32_T KfAEBS_t_BrkPdlDeprssd_Thr_diax;/* '<S3>/KfAEBS_t_BrkPdlDeprssd_Thrsh' */
  real32_T KfAEBS_t_TimeBrakeConfdConfirme;/* '<S3>/KfAEBS_t_TimeBrakeConfdConfirmed' */
  real32_T KfAEBS_t_TimeExitActide_ibk1;/* '<S3>/KfAEBS_t_TimeExitActide' */
  real32_T KfAEBS_t_TimeWait2StandbyT_gpm0;/* '<S3>/KfAEBS_t_TimeWait2StandbyThrsh' */
  real32_T time_threat;                /* '<S193>/DtrmnFCW_State' */
  real32_T time_confidence;            /* '<S193>/DtrmnFCW_State' */
  real32_T time_wait;                  /* '<S193>/DtrmnFCW_State' */
  real32_T KfAEBS_Veh_DisHead2OC_ddms; /* '<S9>/KfAEBS_Veh_DisHead2OC' */
  real32_T KfAEBS_Veh_DisIngnore2OC_p2fq;/* '<S9>/KfAEBS_Veh_DisIngnore2OC' */
  real32_T KfAEBS_Veh_Width_b12o;      /* '<S9>/KfAEBS_Veh_Width' */
  real32_T KfAEBS_d_Dis2HeadIgnoreSid_clhs;/* '<S9>/KfAEBS_d_Dis2HeadIgnoreSide' */
  real32_T KfAEBS_d_Dis_BufferTTSP_fvf0;/* '<S9>/KfAEBS_d_Dis_BufferTTSP' */
  real32_T KfAEBS_d_Dis_BufferTTSP_le_ahgr;/* '<S9>/KfAEBS_d_Dis_BufferTTSP_length' */
  real32_T KfAEBS_d_Dis_LateralIgnore_jbqn;/* '<S9>/KfAEBS_d_Dis_LateralIgnore' */
  real32_T KfAEBS_d_min_dis_swap_ivsz; /* '<S9>/KfAEBS_d_min_dis_swap' */
  real32_T KfAEBS_t_timeGap_ignore_tu_nfky;/* '<S9>/KfAEBS_t_timeGap_ignore_turn' */
  real32_T KfAEBS_v_Speed_DeltaWExit_gqet;/* '<S9>/KfAEBS_v_Speed_DeltaWExit' */
  real32_T KfAEBS_v_Speed_ObjStillThrshLat;/* '<S9>/KfAEBS_v_Speed_ObjStillThrshLateral' */
  real32_T KfAEBS_v_obsSpdBuffer_dhnh; /* '<S9>/KfAEBS_v_obsSpdBuffer' */
  real32_T KfAEBS_v_obsSpeedArcMin_bsty;/* '<S9>/KfAEBS_v_obsSpeedArcMin' */
  real32_T TimeNoIntervention;         /* '<S101>/SpeedReductionStates' */
  real32_T SpeedAtIntervention;        /* '<S101>/SpeedReductionStates' */
  real32_T SpeedRedPrevious;           /* '<S101>/SpeedReductionStates' */
  real32_T TimeNoIntervention_b1jh;    /* '<S101>/BrakeTimeState' */
  real32_T time_confidence_d4b4;       /* '<S39>/DtrmnAEB_State' */
  real32_T time_threat_gr5h;           /* '<S39>/DtrmnAEB_State' */
  real32_T time_wait_o23a;             /* '<S39>/DtrmnAEB_State' */
  real32_T time_brkPdl_depressed;      /* '<S39>/DtrmnAEB_State' */
  uint16_T UnitDelay1_DSTATE_airs;     /* '<S219>/Unit Delay1' */
  uint16_T UnitDelay1_DSTATE_hiir;     /* '<S142>/Unit Delay1' */
  uint16_T UnitDelay1_DSTATE_otc1;     /* '<S143>/Unit Delay1' */
  uint16_T counter;                    /* '<S118>/VIPCloseLostTime' */
  boolean_T UnitDelay_DSTATE_j1ho;     /* '<S219>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_m5j4;     /* '<S10>/Unit Delay' */
  boolean_T UnitDelay3_DSTATE;         /* '<S94>/Unit Delay3' */
  boolean_T UnitDelay_DSTATE_mgfe;     /* '<S116>/Unit Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S159>/Delay Input1' */
  boolean_T DelayInput1_DSTATE_jg0j;   /* '<S158>/Delay Input1' */
  EnumAEBS_AEBState UnitDelay_DSTATE_cm23;/* '<S8>/Unit Delay' */
  EnumAEBS_AEBState UnitDelay_DSTATE_epz0;/* '<S142>/Unit Delay' */
  EnumAEBS_AEBState UnitDelay_DSTATE_ag4i;/* '<S143>/Unit Delay' */
  uint8_T is_active_c21_AEBS_subsystem_in;/* '<S193>/DtrmnFCW_State' */
  uint8_T is_c21_AEBS_subsystem_integrate;/* '<S193>/DtrmnFCW_State' */
  uint8_T is_ON;                       /* '<S193>/DtrmnFCW_State' */
  uint8_T is_Actived;                  /* '<S193>/DtrmnFCW_State' */
  uint8_T is_active_c20_AEBS_subsystem_in;/* '<S166>/Chart' */
  uint8_T is_c20_AEBS_subsystem_integrate;/* '<S166>/Chart' */
  uint8_T is_active_c6_AEBS_subsystem_int;/* '<S123>/Chart' */
  uint8_T is_c6_AEBS_subsystem_integrated;/* '<S123>/Chart' */
  uint8_T is_active_c8_AEBS_subsystem_int;/* '<S96>/BrakeTimeState' */
  uint8_T is_c8_AEBS_subsystem_integrated;/* '<S96>/BrakeTimeState' */
  uint8_T is_active_c24_AEBS_subsystem_in;/* '<S101>/SpeedReductionStates' */
  uint8_T is_c24_AEBS_subsystem_integrate;/* '<S101>/SpeedReductionStates' */
  uint8_T is_SpeedReductionEval;       /* '<S101>/SpeedReductionStates' */
  uint8_T is_active_c23_AEBS_subsystem_in;/* '<S101>/BrakeTimeState' */
  uint8_T is_c23_AEBS_subsystem_integrate;/* '<S101>/BrakeTimeState' */
  uint8_T is_BrakeTimeEval;            /* '<S101>/BrakeTimeState' */
  uint8_T is_active_c17_AEBS_subsystem_in;/* '<S39>/DtrmnAEB_State' */
  uint8_T is_c17_AEBS_subsystem_integrate;/* '<S39>/DtrmnAEB_State' */
  uint8_T is_ON_p2gh;                  /* '<S39>/DtrmnAEB_State' */
  uint8_T is_Actived_jiof;             /* '<S39>/DtrmnAEB_State' */
  boolean_T exit_flag;                 /* '<S193>/DtrmnFCW_State' */
  boolean_T Memory_PreviousInput;      /* '<S200>/Memory' */
  boolean_T Memory_PreviousInput_l2t2; /* '<S138>/Memory' */
  boolean_T Memory_PreviousInput_bh05; /* '<S131>/Memory' */
  boolean_T Memory_PreviousInput_m5dr; /* '<S112>/Memory' */
  boolean_T Memory_PreviousInput_k5se; /* '<S137>/Memory' */
  boolean_T Memory_PreviousInput_c1qe; /* '<S130>/Memory' */
  boolean_T Memory_PreviousInput_cd3i; /* '<S115>/Memory' */
  boolean_T Memory_PreviousInput_lbx1; /* '<S117>/Memory' */
  boolean_T Memory_PreviousInput_llaj; /* '<S160>/Memory' */
  boolean_T exit_actived;              /* '<S39>/DtrmnAEB_State' */
  boolean_T Memory_PreviousInput_ehjf; /* '<S72>/Memory' */
  DW_Stop_Moving_Estimation_AEB_T sf_Stop_Moving_Estimation_licw;/* '<S205>/Stop_Moving_Estimation' */
  DW_Chart_AEBS_subsystem__jbmw_T sf_Chart_omyv;/* '<S214>/Chart' */
  DW_Chart_AEBS_subsystem__jbmw_T sf_Chart_avmp;/* '<S213>/Chart' */
  DW_Chart_AEBS_subsystem__jbmw_T sf_Chart_h0r1;/* '<S139>/Chart' */
  DW_Chart_AEBS_subsystem__jbmw_T sf_Chart_cuaz;/* '<S132>/Chart' */
  DW_Stop_Moving_Estimation_AEB_T sf_Stop_Moving_Estimation;/* '<S79>/Stop_Moving_Estimation' */
  DW_Chart_AEBS_subsystem__jbmw_T sf_Chart_hwue;/* '<S99>/Chart' */
  DW_Chart_AEBS_subsystem__jbmw_T sf_Chart_izss;/* '<S97>/Chart' */
  DW_Chart_AEBS_subsystem__jbmw_T sf_Chart_fmkq;/* '<S85>/Chart' */
  DW_Chart_AEBS_subsystem_integ_T sf_Chart_la5t;/* '<S19>/Chart' */
  DW_Chart_AEBS_subsystem_integ_T sf_Chart;/* '<S18>/Chart' */
}
DW_AEBS_subsystem_integrated_T;

/* Invariant block signals (auto storage) */
typedef struct
{
  const uint8_T DataTypeConversion;    /* '<S206>/Data Type Conversion' */
  const uint8_T DataTypeConversion_dfrt;/* '<S199>/Data Type Conversion' */
  const uint8_T DataTypeConversion1;   /* '<S199>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2;   /* '<S199>/Data Type Conversion2' */
  const uint8_T DataTypeConversion_fpa3;/* '<S80>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_lo5n;/* '<S80>/Data Type Conversion1' */
  const uint8_T DataTypeConversion_j4el;/* '<S46>/Data Type Conversion' */
  const uint8_T DataTypeConversion1_bqey;/* '<S46>/Data Type Conversion1' */
  const uint8_T DataTypeConversion2_lua5;/* '<S46>/Data Type Conversion2' */
  const uint8_T DataTypeConversion2_o2r5;/* '<S12>/Data Type Conversion2' */
  const uint8_T DataTypeConversion1_gzmk;/* '<S12>/Data Type Conversion1' */
  const uint8_T BitwiseOperator1;      /* '<S12>/Bitwise Operator1' */
  const uint8_T DataTypeConversion_axbm;/* '<S6>/Data Type Conversion' */
  const uint8_T FedBck_SmallLampState; /* '<S26>/Data Type Conversion11' */
}
ConstB_AEBS_subsystem_integra_T;

/* Constant parameters (auto storage) */
typedef struct
{
  /* Pooled Parameter (Expression: [0 1;1 0;0 1;0 1;1 0;1 0;0 0;0 0])
   * Referenced by:
   *   '<S160>/Logic'
   *   '<S72>/Logic'
   *   '<S200>/Logic'
   *   '<S115>/Logic'
   *   '<S117>/Logic'
   *   '<S130>/Logic'
   *   '<S131>/Logic'
   *   '<S137>/Logic'
   *   '<S138>/Logic'
   *   '<S112>/Logic'
   */
  boolean_T pooled22[16];
}
ConstP_AEBS_subsystem_integra_T;

/* Block signals (auto storage) */
extern B_AEBS_subsystem_integrated_T AEBS_subsystem_integrated_B;

/* Block states (auto storage) */
extern DW_AEBS_subsystem_integrated_T AEBS_subsystem_integrated_DW;

/* External data declarations for dependent source files */
extern const AEBS_DataBus AEBS_subsystem_integrated_rtZAEBS_DataBus;/* AEBS_DataBus ground */
extern const ConstB_AEBS_subsystem_integra_T AEBS_subsystem_integrate_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstP_AEBS_subsystem_integra_T AEBS_subsystem_integrate_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern AEBS_DataBus VsAEBS_DataBus;    /* '<S1>/Merge' */
extern real32_T VfAEBS_m_1_a_x;        /* '<S4>/Signal Conversion10' */
extern real32_T VfAEBS_m_1_a_y;        /* '<S4>/Signal Conversion11' */
extern real32_T VfAEBS_m_1_length;     /* '<S4>/Signal Conversion12' */
extern real32_T VfAEBS_m_1_width;      /* '<S4>/Signal Conversion13' */
extern real32_T VfAEBS_m_2_NP_x;       /* '<S4>/Signal Conversion18' */
extern real32_T VfAEBS_m_2_NP_y;       /* '<S4>/Signal Conversion19' */
extern real32_T VfAEBS_m_3_NP_x;       /* '<S4>/Signal Conversion23' */
extern real32_T VfAEBS_m_3_NP_y;       /* '<S4>/Signal Conversion24' */
extern real32_T VfAEBS_m_2_heading;    /* '<S4>/Signal Conversion27' */
extern real32_T VfAEBS_m_3_heading;    /* '<S4>/Signal Conversion28' */
extern real32_T VfAEBS_m_4_NP_x;       /* '<S4>/Signal Conversion30' */
extern real32_T VfAEBS_m_4_NP_y;       /* '<S4>/Signal Conversion31' */
extern real32_T VfAEBS_m_4_heading;    /* '<S4>/Signal Conversion34' */
extern real32_T VfAEBS_m_2_length;     /* '<S4>/Signal Conversion35' */
extern real32_T VfAEBS_m_2_width;      /* '<S4>/Signal Conversion36' */
extern real32_T VfAEBS_m_3_length;     /* '<S4>/Signal Conversion37' */
extern real32_T VfAEBS_m_3_width;      /* '<S4>/Signal Conversion38' */
extern real32_T VfAEBS_m_4_length;     /* '<S4>/Signal Conversion39' */
extern real32_T VfAEBS_m_1_NP_x;       /* '<S4>/Signal Conversion4' */
extern real32_T VfAEBS_m_4_width;      /* '<S4>/Signal Conversion40' */
extern real32_T VfAEBS_m_1_NP_y;       /* '<S4>/Signal Conversion5' */
extern real32_T VfAEBS_m_1_heading;    /* '<S4>/Signal Conversion6' */
extern real32_T VfAEBS_m_1_v_x;        /* '<S4>/Signal Conversion7' */
extern real32_T VfAEBS_m_1_v_y;        /* '<S4>/Signal Conversion9' */
extern real32_T VfAEBS_m_EGMO_veh_speed;/* '<S5>/Signal Conversion5' */
extern real32_T VfAEBS_m_EGMO_veh_acc; /* '<S5>/Signal Conversion6' */
extern real32_T VfAEBS_m_EGMO_v_cur;   /* '<S5>/Signal Conversion7' */
extern real32_T VfAEBS_m_EGMO_v_x;     /* '<S5>/Signal Conversion8' */
extern real32_T VfAEBS_m_EGMO_v_y;     /* '<S5>/Signal Conversion9' */
extern real32_T VfAEBS_veh_speed_used; /* '<S9>/Signal Conversion' */
extern real32_T VfAEBS_speed_x_used;   /* '<S9>/Signal Conversion11' */
extern real32_T VfAEBS_speed_y_used;   /* '<S9>/Signal Conversion12' */
extern real32_T VfAEBS_veh_acc_used;   /* '<S9>/Signal Conversion13' */
extern real32_T VfAEBS_veh_cur_used;   /* '<S9>/Signal Conversion10' */
extern real32_T VfAEBS_obs_delta_dis[32];/* '<S9>/Signal Conversion1' */
extern real32_T VfAEBS_obs_delta_speed[32];/* '<S9>/Signal Conversion2' */
extern real32_T VfAEBS_obs_ttc[32];    /* '<S9>/Signal Conversion3' */
extern real32_T VfAEBS_obs_dis2adc_long[32];/* '<S9>/Signal Conversion4' */
extern real32_T VfAEBS_obs_dis2adc_lateral[32];/* '<S9>/Signal Conversion5' */
extern real32_T VfAEBS_obs_v_long[32]; /* '<S9>/Signal Conversion6' */
extern real32_T VfAEBS_obs_v_lateral[32];/* '<S9>/Signal Conversion7' */
extern real32_T VfAEBS_obs_v_long_vip; /* '<S165>/Data Type Conversion10' */
extern real32_T VfAEBS_obs_acc_lateral_vip;/* '<S165>/Data Type Conversion11' */
extern real32_T VfAEBS_obs_acc_long_vip;/* '<S165>/Data Type Conversion12' */
extern real32_T VfAEBS_obs_NP_x_vip;   /* '<S165>/Data Type Conversion13' */
extern real32_T VfAEBS_obs_NP_y_vip;   /* '<S165>/Data Type Conversion14' */
extern real32_T VfAEBS_obs_heading_VIP;/* '<S165>/Data Type Conversion15' */
extern real32_T VfAEBS_obs_length_VIP; /* '<S165>/Data Type Conversion16' */
extern real32_T VfAEBS_obs_width_VIP;  /* '<S165>/Data Type Conversion17' */
extern real32_T VfAEBS_obs_dis_long_VIP;/* '<S165>/Data Type Conversion18' */
extern real32_T VfAEBS_obs_dis_lateral_VIP;/* '<S165>/Data Type Conversion19' */
extern real32_T VfAEBS_obs_rp_vip;     /* '<S165>/Data Type Conversion2' */
extern real32_T VfAEBS_obs_ttc_vip;    /* '<S165>/Data Type Conversion4' */
extern real32_T VfAEBS_obs_delta_dis_vip;/* '<S165>/Data Type Conversion5' */
extern real32_T VfAEBS_obs_delta_speed_vip;/* '<S165>/Data Type Conversion6' */
extern real32_T VfAEBS_obs_v_lateral_vip;/* '<S165>/Data Type Conversion9' */
extern real32_T VfAEBS_Pre_BrakeActiveTTCThreshold;/* '<S141>/Switch' */
extern real32_T VfAEBS_Partial_BrakeActiveTTCThreshold;/* '<S134>/Switch' */
extern real32_T VfAEBS_v_obj_absolute_speed;/* '<S76>/Add2' */
extern real32_T VfAEBS_a_obj_absolute_acc;/* '<S76>/Add1' */
extern real32_T VfAEBS_areq_withoutDelay_UrgentBrk;/* '<S76>/Divide2' */
extern real32_T VfAEBS_areq_withoutDelay;/* '<S76>/Gain1' */
extern real32_T VfAEBS_dis_delay;      /* '<S76>/Add' */
extern real32_T VfAEBS_dis_safe_used;  /* '<S76>/Switch3' */
extern real32_T VfAEBS_areq;           /* '<S76>/MinMax2' */
extern real32_T VfAEBS_Full_BrkActiveACCThreshold;/* '<S126>/Full_BrkActiveAccThreshold_table' */
extern real32_T VfAEBS_AEB_acceleration_af_filter;/* '<S51>/Product1' */
extern real32_T VfAEBS_AEB_acceleration_bf_limit;/* '<S47>/MinMax2' */
extern real32_T VfAEBS_AEB_accReq_beforeSend;/* '<S48>/Switch' */
extern real32_T VfAEBS_AEB_acceleration_req;/* '<S7>/Signal Conversion3' */
extern real32_T VfAEBS_FedBck_Vehspd;  /* '<S14>/Signal Conversion6' */
extern real32_T VfAEBS_FedBck_AccLong; /* '<S14>/Signal Conversion8' */
extern real32_T VfAEBS_FedBck_StrAngle;/* '<S14>/Signal Conversion1' */
extern real32_T VfAEBS_FedBck_yawRate; /* '<S14>/Signal Conversion15' */
extern real32_T VfAEBS_FedBck_AccLateral;/* '<S14>/Signal Conversion7' */
extern int32_T VfAEBS_m_2_id;          /* '<S4>/Signal Conversion17' */
extern int32_T VfAEBS_m_3_id;          /* '<S4>/Signal Conversion22' */
extern int32_T VfAEBS_m_4_id;          /* '<S4>/Signal Conversion29' */
extern int32_T VfAEBS_m_1_id;          /* '<S4>/Signal Conversion3' */
extern int32_T VfAEBS_m_timestamp_high;/* '<S4>/Signal Conversion8' */
extern int32_T VfAEBS_m_EGMO_timestamp_h;/* '<S5>/Signal Conversion3' */
extern int32_T VfAEBS_obs_id_vip;      /* '<S165>/Data Type Conversion7' */
extern int32_T VfAEBS_AEBS_obs_id;     /* '<S28>/Switch' */
extern uint32_T VfAEBS_m_timestamp_low;/* '<S4>/Signal Conversion1' */
extern uint32_T VfAEBS_m_EGMO_timestamp_l;/* '<S5>/Signal Conversion1' */
extern uint16_T VfAEBS_m_num_obstacles;/* '<S4>/Signal Conversion2' */
extern int8_T VfAEBS_m_1_type;         /* '<S4>/Signal Conversion14' */
extern int8_T VfAEBS_m_1_motion_status;/* '<S4>/Signal Conversion15' */
extern int8_T VfAEBS_m_1_position_zone;/* '<S4>/Signal Conversion16' */
extern int8_T VfAEBS_m_2_position_zone;/* '<S4>/Signal Conversion20' */
extern int8_T VfAEBS_m_2_motion_status;/* '<S4>/Signal Conversion21' */
extern int8_T VfAEBS_m_3_position_zone;/* '<S4>/Signal Conversion25' */
extern int8_T VfAEBS_m_3_motion_status;/* '<S4>/Signal Conversion26' */
extern int8_T VfAEBS_m_4_position_zone;/* '<S4>/Signal Conversion32' */
extern int8_T VfAEBS_m_4_motion_status;/* '<S4>/Signal Conversion33' */
extern int8_T VfAEBS_obs_position_zone_VIP;/* '<S165>/Data Type Conversion20' */
extern int8_T VfAEBS_obs_motion_status_VIP;/* '<S165>/Data Type Conversion21' */
extern int8_T VfAEBS_obs_type_vip;     /* '<S165>/Data Type Conversion8' */
extern uint8_T VfAEBS_m_1_confidence;  /* '<S4>/Signal Conversion41' */
extern uint8_T VfAEBS_m_2_confidence;  /* '<S4>/Signal Conversion42' */
extern uint8_T VfAEBS_m_3_confidence;  /* '<S4>/Signal Conversion43' */
extern uint8_T VfAEBS_m_4_confidence;  /* '<S4>/Signal Conversion44' */
extern uint8_T VfAEBS_obs_position_state[32];/* '<S9>/Signal Conversion8' */
extern uint8_T VfAEBS_obs_filtered_type[32];/* '<S9>/Signal Conversion9' */
extern uint8_T VfAEBS_obs_index_vip;   /* '<S165>/Data Type Conversion1' */
extern uint8_T VfAEBS_obs_confidence_VIP;/* '<S165>/Data Type Conversion22' */
extern uint8_T VfAEBS_obs_position_state_vip;/* '<S165>/Data Type Conversion3' */
extern uint8_T VfAEBS_FCW_warn_level;  /* '<S27>/Switch1' */
extern uint8_T VfAEBS_FCW_error;       /* '<S7>/Signal Conversion11' */
extern uint8_T VfAEBS_AEB_error;       /* '<S7>/Signal Conversion8' */
extern uint8_T VfAEBS_FedBck_Drivemode;/* '<S14>/Signal Conversion' */
extern uint8_T VfAEBS_FedBck_BrkLightState;/* '<S14>/Signal Conversion12' */
extern uint8_T VfAEBS_FedBck_BrkPedStatus;/* '<S14>/Signal Conversion9' */
extern uint8_T VfAEBS_FedBck_EPBstate; /* '<S14>/Signal Conversion5' */
extern uint8_T VfAEBS_FedBck_GearValue;/* '<S14>/Signal Conversion4' */
extern uint8_T VfAEBS_FedBck_BrkPedPos;/* '<S14>/Signal Conversion3' */
extern uint8_T VfAEBS_FedBck_AccPedPos;/* '<S14>/Signal Conversion2' */
extern uint8_T VfAEBS_FedBck_SmallLampState;/* '<S14>/Signal Conversion11' */
extern boolean_T VfAEBS_FCW_enabled;   /* '<S206>/Logical Operator' */
extern boolean_T VbAEBS_FCW_inhbt_AccPedPos;/* '<S210>/Relational Operator1' */
extern boolean_T VbAEBS_FCW_inhbt_VehAcc;/* '<S210>/Relational Operator2' */
extern boolean_T VbAEBS_FCW_inhbt_DeactTime;/* '<S219>/Relational Operator' */
extern boolean_T VbAEBS_FCW_inhibit;   /* '<S210>/Logical Operator1' */
extern boolean_T VfAEBS_FCWLev1_active;/* '<S207>/Logical Operator' */
extern boolean_T VfAEBS_FCWLev1_dactive;/* '<S207>/Logical Operator3' */
extern boolean_T VfAEBS_FCWLev2_active;/* '<S208>/Logical Operator' */
extern boolean_T VfAEBS_FCWLev2_dactive;/* '<S208>/Logical Operator3' */
extern boolean_T VfAEBS_FCWLev3_active;/* '<S209>/Logical Operator' */
extern boolean_T VfAEBS_FCWLev3_dactive;/* '<S209>/Logical Operator3' */
extern boolean_T VfAEBS_FCW_disabled;  /* '<S206>/Logical Operator2' */
extern boolean_T VfAEBS_FCW_deacitve;  /* '<S214>/Chart' */
extern boolean_T VbAEBS_has_obs_vip;   /* '<S165>/Data Type Conversion' */
extern boolean_T VfAEBS_Obj_IsVRU;     /* '<S122>/SwitchVRUObs' */
extern boolean_T VfAEBS_use_VRU_Calibration;/* '<S78>/Logical Operator' */
extern boolean_T VfAEBS_LowSpeed_InhibitAEB;/* '<S145>/Logical Operator' */
extern boolean_T VfAEBS_HighSpeed_InhibitAEB;/* '<S145>/Relational Operator2' */
extern boolean_T VfAEBS_VehDeltaSpeed_InhibitAEB;/* '<S145>/Logical Operator2' */
extern boolean_T VfAEBS_Speed_InhibitAEB;/* '<S145>/Logical Operator1' */
extern boolean_T VfAEBS_Gear_InhibitAEB;/* '<S84>/Relational Operator3' */
extern boolean_T VbAEBS_AEB_inhbt_DeactTime;/* '<S142>/Relational Operator' */
extern boolean_T VbAEBS_AEB_inhbt_AccPdl;/* '<S84>/Relational Operator1' */
extern boolean_T VbAEBS_AEB_inhbt_StrAngRte;/* '<S144>/Relational Operator' */
extern boolean_T VbAEBS_AEB_inhbt_veh_acc;/* '<S146>/Relational Operator' */
extern boolean_T VfAEBS_AEB_inhibit;   /* '<S84>/Logical Operator' */
extern boolean_T VbAEBS_PreBrk_inhbt_deactTime;/* '<S143>/Relational Operator' */
extern boolean_T VbAEBS_preBrake_inhibit;/* '<S84>/Logical Operator1' */
extern boolean_T VfAEBS_preBrake_active;/* '<S83>/Logical Operator' */
extern boolean_T VfAEBS_partialBrk_active;/* '<S82>/Switch' */
extern boolean_T VfAEBS_fullBrk_active;/* '<S81>/Switch' */
extern boolean_T VbAEBS_Deactive_R_NoVIP;/* '<S77>/Logical Operator' */
extern boolean_T VbAEBS_vipCloseLost;  /* '<S95>/Signal Conversion' */
extern boolean_T VbAEBS_vipStationary; /* '<S94>/Signal Conversion' */
extern boolean_T VbAEBS_Deactive_R_VIPChanged;/* '<S93>/Logical Operator2' */
extern boolean_T VfAEBS_DeniedDueToSpdRed;/* '<S92>/i' */
extern boolean_T VfAEBS_DeniedDueToTimeBrake;/* '<S92>/i1' */
extern boolean_T VbAEBS_Deactive_R_Confdnc;/* '<S77>/Relational Operator1' */
extern boolean_T VbAEBS_deactive_preBrk_timeOut;/* '<S96>/i1' */
extern boolean_T VfAEBS_AEB_enabled;   /* '<S80>/Logical Operator3' */
extern boolean_T VfAEBS_preBrake_dactive;/* '<S83>/Logical Operator3' */
extern boolean_T VfAEBS_partialBrk_dactive;/* '<S82>/Logical Operator3' */
extern boolean_T VfAEBS_fullBrk_dactive;/* '<S81>/Logical Operator3' */
extern boolean_T VfAEBS_AEB_disabled;  /* '<S80>/Logical Operator7' */
extern boolean_T VfAEBS_veh_standstill;/* '<S79>/Stop_Moving_Estimation' */
extern boolean_T VfAEBS_Vehicle_isInHighSpeed;/* '<S123>/Chart' */
extern boolean_T VfAEBS_AEB_deactive;  /* '<S99>/Chart' */
extern boolean_T VbAEBS_Deactive_R_HighTTC;/* '<S97>/Chart' */
extern boolean_T VfAEBS_AEB_request_beforeSend;/* '<S39>/DtrmnAEB_State' */
extern boolean_T VfAEBS_FCW_request;   /* '<S7>/Signal Conversion9' */
extern boolean_T VfAEBS_AEB_request;   /* '<S7>/Signal Conversion2' */
extern boolean_T VfAEBS_AEB_prebrake_req;/* '<S7>/Signal Conversion1' */
extern boolean_T VfAEBS_brakeLight_req;/* '<S7>/Signal Conversion4' */
extern boolean_T VfAEBS_AEBS_brake_priority_setting;/* '<S7>/Signal Conversion5' */
extern boolean_T VfAEBS_AEBS_horn_ctrl_req;/* '<S7>/Signal Conversion12' */
extern boolean_T VfAEBS_FedBck_LeftLampState;/* '<S14>/Signal Conversion16' */
extern boolean_T VfAEBS_FedBck_RightLampState;/* '<S14>/Signal Conversion17' */
extern EnumAEBS_EnblState VfAEBS_FCW_enable_state;/* '<S7>/Signal Conversion10' */
extern EnumAEBS_EnblState VeAEBS_AEB_enabled_state;/* '<S7>/Signal Conversion6' */
extern EnumAEBS_FCWState VfAEBS_FCW_active_state;/* '<S27>/Switch3' */
extern EnumAEBS_AEBState VeAEBS_AEB_actived_state;/* '<S7>/Signal Conversion7' */
extern EnumAEBS_TurnType VeAEBS_TurnType;/* '<S166>/Merge1' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T KaAEBS_AXIS_DeltaSpeed_Vip[13];/* Variable: KaAEBS_AXIS_DeltaSpeed_Vip
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
extern real32_T KaAEBS_AXIS_NearestPointX_vec[11];/* Variable: KaAEBS_AXIS_NearestPointX_vec
                                                   * Referenced by:
                                                   *   '<S171>/lateral_buffer_bicycle_table'
                                                   *   '<S172>/lateral_buffer_motorcycle_table'
                                                   *   '<S173>/lateral_buffer_other_table'
                                                   *   '<S174>/lateral_buffer_pedestrain_table'
                                                   *   '<S175>/lateral_buffer_vehicle_table'
                                                   */
extern real32_T KaAEBS_AXIS_NearestPointY_vec[11];/* Variable: KaAEBS_AXIS_NearestPointY_vec
                                                   * Referenced by:
                                                   *   '<S176>/long_buffer_bicycle_table'
                                                   *   '<S177>/long_buffer_motorcycle_table'
                                                   *   '<S178>/long_buffer_other_table'
                                                   *   '<S179>/long_buffer_pedestrain_table'
                                                   *   '<S180>/long_buffer_vehicle_table'
                                                   */
extern real32_T KaAEBS_AXIS_Veh_Curvature_vec[10];/* Variable: KaAEBS_AXIS_Veh_Curvature_vec
                                                   * Referenced by: '<S48>/BrakeValueLimit_Table'
                                                   */
extern real32_T KaAEBS_AXIS_Veh_Speed_vec[9];/* Variable: KaAEBS_AXIS_Veh_Speed_vec
                                              * Referenced by:
                                              *   '<S9>/veh_widthGain_table'
                                              *   '<S146>/veh_acc_AEB_inhibit_thrhd_table'
                                              */
extern real32_T KfAEBS_CTRL_PeriodFunctionCall;/* Variable: KfAEBS_CTRL_PeriodFunctionCall
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
extern real32_T KfAEBS_Change_LateralPosThrsh;/* Variable: KfAEBS_Change_LateralPosThrsh
                                               * Referenced by:
                                               *   '<S212>/Constant2'
                                               *   '<S114>/Constant2'
                                               * Object change lateral position threshold
                                               */
extern real32_T KfAEBS_Change_LonglPosThrsh;/* Variable: KfAEBS_Change_LonglPosThrsh
                                             * Referenced by:
                                             *   '<S212>/Constant1'
                                             *   '<S114>/Constant1'
                                             * Object change longitudinal position threshold
                                             */
extern real32_T KfAEBS_CoeffStrwhl2Radius;/* Variable: KfAEBS_CoeffStrwhl2Radius
                                           * Referenced by: '<S13>/Constant6'
                                           * When there's no EGMO, steer wheel angle is used to calculate Radius,
                                             Coefficent correction of radius.
                                           */
extern real32_T KfAEBS_Cur_LeftTurnThrshHi;/* Variable: KfAEBS_Cur_LeftTurnThrshHi
                                            * Referenced by:
                                            *   '<S9>/KfAEBS_Cur_LeftTurnThrshHi'
                                            *   '<S9>/Constant3'
                                            * Curvature left turn threshold High
                                            */
extern real32_T KfAEBS_Cur_LeftTurnThrshLo;/* Variable: KfAEBS_Cur_LeftTurnThrshLo
                                            * Referenced by:
                                            *   '<S9>/KfAEBS_Cur_LeftTurnThrshLo'
                                            *   '<S9>/Constant4'
                                            *   '<S94>/Constant4'
                                            * Curvature left turn threshold low
                                            */
extern real32_T KfAEBS_Cur_RightTurnThrshHi;/* Variable: KfAEBS_Cur_RightTurnThrshHi
                                             * Referenced by:
                                             *   '<S9>/KfAEBS_Cur_RightTurnThrshHi'
                                             *   '<S9>/Constant1'
                                             * Curvature right turn threshold high
                                             */
extern real32_T KfAEBS_Cur_RightTurnThrshLo;/* Variable: KfAEBS_Cur_RightTurnThrshLo
                                             * Referenced by:
                                             *   '<S9>/KfAEBS_Cur_RightTurnThrshLo'
                                             *   '<S9>/Constant2'
                                             * Curvature right turn threshold low
                                             */
extern real32_T KfAEBS_Default_AEB_acceleration_req;/* Variable: KfAEBS_Default_AEB_acceleration_req
                                                     * Referenced by: '<S2>/Constant7'
                                                     * Default AEB acceleration req
                                                     */
extern real32_T KfAEBS_GainTHW;        /* Variable: KfAEBS_GainTHW
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_GainTHW'
                                        *   '<S9>/Constant28'
                                        * GainTHW
                                        */
extern real32_T KfAEBS_GainTTC;        /* Variable: KfAEBS_GainTTC
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_GainTTC'
                                        *   '<S9>/Constant29'
                                        * GainTTC
                                        */
extern real32_T KfAEBS_Pedstr_length_Thrsh;/* Variable: KfAEBS_Pedstr_length_Thrsh
                                            * Referenced by:
                                            *   '<S9>/KfAEBS_Pedstr_length_Thrsh'
                                            *   '<S9>/Constant42'
                                            */
extern real32_T KfAEBS_Pedstr_width_Thrsh;/* Variable: KfAEBS_Pedstr_width_Thrsh
                                           * Referenced by:
                                           *   '<S9>/KfAEBS_Pedstr_width_Thrsh'
                                           *   '<S9>/Constant41'
                                           */
extern real32_T KfAEBS_SpdMinOvrdAccrResetInCllsnRednByBrkg;/* Variable: KfAEBS_SpdMinOvrdAccrResetInCllsnRednByBrkg
                                                             * Referenced by:
                                                             *   '<S43>/LoPosValInCllsnRednByBrkg  1'
                                                             *   '<S196>/LoPosValInCllsnRednByBrkg  1'
                                                             */
extern real32_T KfAEBS_SteerRate_Limit_hi;/* Variable: KfAEBS_SteerRate_Limit_hi
                                           * Referenced by:
                                           *   '<S128>/Constant4'
                                           *   '<S135>/Constant4'
                                           */
extern real32_T KfAEBS_SteerRate_Limit_lo;/* Variable: KfAEBS_SteerRate_Limit_lo
                                           * Referenced by:
                                           *   '<S128>/Constant1'
                                           *   '<S135>/Constant1'
                                           */
extern real32_T KfAEBS_StrAngRte_inhbt_AEB_trshd;/* Variable: KfAEBS_StrAngRte_inhbt_AEB_trshd
                                                  * Referenced by: '<S144>/Constant4'
                                                  */
extern real32_T KfAEBS_VehAcc_inhbt_FCW_thrshld;/* Variable: KfAEBS_VehAcc_inhbt_FCW_thrshld
                                                 * Referenced by: '<S210>/Constant3'
                                                 */
extern real32_T KfAEBS_Veh_Dis2OC_useCenterPoint;/* Variable: KfAEBS_Veh_Dis2OC_useCenterPoint
                                                  * Referenced by:
                                                  *   '<S9>/KfAEBS_Veh_Dis2OC_useCenterPoint'
                                                  *   '<S9>/Constant10'
                                                  */
extern real32_T KfAEBS_Veh_DisEnd2OC;  /* Variable: KfAEBS_Veh_DisEnd2OC
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_DisEnd2OC'
                                        *   '<S9>/Constant18'
                                        */
extern real32_T KfAEBS_Veh_DisHead2OC; /* Variable: KfAEBS_Veh_DisHead2OC
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_DisHead2OC'
                                        *   '<S9>/Constant19'
                                        *   '<S170>/Constant19'
                                        */
extern real32_T KfAEBS_Veh_DisIngnore2OC;/* Variable: KfAEBS_Veh_DisIngnore2OC
                                          * Referenced by:
                                          *   '<S9>/KfAEBS_Veh_DisIngnore2OC'
                                          *   '<S9>/Constant5'
                                          */
extern real32_T KfAEBS_Veh_DisRear2COM;/* Variable: KfAEBS_Veh_DisRear2COM
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_DisRear2COM'
                                        *   '<S9>/Constant20'
                                        */
extern real32_T KfAEBS_Veh_DisRear2OC; /* Variable: KfAEBS_Veh_DisRear2OC
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_DisRear2OC'
                                        *   '<S9>/Constant21'
                                        */
extern real32_T KfAEBS_Veh_Length;     /* Variable: KfAEBS_Veh_Length
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_Length'
                                        *   '<S9>/Constant22'
                                        */
extern real32_T KfAEBS_Veh_Strwhl2FrtwhlRatio;/* Variable: KfAEBS_Veh_Strwhl2FrtwhlRatio
                                               * Referenced by: '<S13>/Constant2'
                                               */
extern real32_T KfAEBS_Veh_WheelBase;  /* Variable: KfAEBS_Veh_WheelBase
                                        * Referenced by: '<S13>/Constant1'
                                        */
extern real32_T KfAEBS_Veh_Width;      /* Variable: KfAEBS_Veh_Width
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_Width'
                                        *   '<S9>/Constant30'
                                        *   '<S9>/Constant7'
                                        *   '<S95>/Constant11'
                                        *   '<S95>/Constant14'
                                        */
extern real32_T KfAEBS_Veh_WidthBuffer;/* Variable: KfAEBS_Veh_WidthBuffer
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_Veh_WidthBuffer'
                                        *   '<S9>/Constant23'
                                        */
extern real32_T KfAEBS_VeloRectThrsdByBrkg;/* Variable: KfAEBS_VeloRectThrsdByBrkg
                                            * Referenced by: '<S92>/VRednThdASILAInCllsnRednByBrkg'
                                            */
extern real32_T KfAEBS_YawRate_Limit_hi;/* Variable: KfAEBS_YawRate_Limit_hi
                                         * Referenced by:
                                         *   '<S128>/Constant6'
                                         *   '<S135>/Constant6'
                                         */
extern real32_T KfAEBS_YawRate_Limit_lo;/* Variable: KfAEBS_YawRate_Limit_lo
                                         * Referenced by:
                                         *   '<S128>/Constant5'
                                         *   '<S135>/Constant5'
                                         */
extern real32_T KfAEBS_Zone_DoRbIW_x_front;/* Variable: KfAEBS_Zone_DoRbIW_x_front
                                            * Referenced by:
                                            *   '<S9>/KfAEBS_Zone_DoRbIW_x_front'
                                            *   '<S9>/Constant35'
                                            */
extern real32_T KfAEBS_Zone_DoRbIW_x_rear;/* Variable: KfAEBS_Zone_DoRbIW_x_rear
                                           * Referenced by:
                                           *   '<S9>/KfAEBS_Zone_DoRbIW_x_rear'
                                           *   '<S9>/Constant36'
                                           */
extern real32_T KfAEBS_a_AreqRampRate; /* Variable: KfAEBS_a_AreqRampRate
                                        * Referenced by: '<S47>/Constant7'
                                        */
extern real32_T KfAEBS_a_Areq_FullBrkDeactThrsd;/* Variable: KfAEBS_a_Areq_FullBrkDeactThrsd
                                                 * Referenced by: '<S81>/Constant1'
                                                 * Acceleration request full brake dactive threshold(Full brake
                                                   can be deactived only in a short period)
                                                 */
extern real32_T KfAEBS_a_Areq_ObjChangThrsd;/* Variable: KfAEBS_a_Areq_ObjChangThrsd
                                             * Referenced by: '<S93>/Constant1'
                                             * When the object is changed, only when the new object's acceleration request
                                               is samller than a threshold, then, the AEB/FCW can be deactived.
                                             */
extern real32_T KfAEBS_a_Areq_PartialBrkActThrsd;/* Variable: KfAEBS_a_Areq_PartialBrkActThrsd
                                                  * Referenced by: '<S82>/Constant2'
                                                  * Acceleration request partial brake active threshold
                                                  */
extern real32_T KfAEBS_a_Areq_PartialBrkDeactThrsd;/* Variable: KfAEBS_a_Areq_PartialBrkDeactThrsd
                                                    * Referenced by: '<S82>/Constant1'
                                                    * Acceleration request partial brake deactive threshold
                                                    */
extern real32_T KfAEBS_a_BrakeHold;    /* Variable: KfAEBS_a_BrakeHold
                                        * Referenced by:
                                        *   '<S3>/KfAEBS_a_BrakeHold'
                                        *   '<S3>/Constant2'
                                        * Acceleration send when vehicle is standstill
                                        */
extern real32_T KfAEBS_a_BrakeInit;    /* Variable: KfAEBS_a_BrakeInit
                                        * Referenced by:
                                        *   '<S42>/KfAEBS_a_BrakeInit'
                                        *   '<S42>/Constant2'
                                        * In passensor protected stage,acceleration send at initial step
                                        */
extern real32_T KfAEBS_a_BrakeMax;     /* Variable: KfAEBS_a_BrakeMax
                                        * Referenced by:
                                        *   '<S42>/KfAEBS_a_BrakeMax'
                                        *   '<S42>/Constant4'
                                        * In passensor protected stage,acceleration send maximum
                                        */
extern real32_T KfAEBS_a_Buffer;       /* Variable: KfAEBS_a_Buffer
                                        * Referenced by:
                                        *   '<S89>/Constant1'
                                        *   '<S89>/Constant3'
                                        * Acceleration send buffer in distance safe
                                        */
extern real32_T KfAEBS_a_FullBrakeHi;  /* Variable: KfAEBS_a_FullBrakeHi
                                        * Referenced by:
                                        *   '<S42>/KfAEBS_a_FullBrakeHi'
                                        *   '<S42>/Constant9'
                                        *   '<S76>/Constant1'
                                        *   '<S76>/Constant6'
                                        *   '<S76>/Constant8'
                                        *   '<S86>/Constant10'
                                        * Maximum decceleration send in full brake(ex. -5)
                                        */
extern real32_T KfAEBS_a_FullBrakeLo;  /* Variable: KfAEBS_a_FullBrakeLo
                                        * Referenced by:
                                        *   '<S42>/KfAEBS_a_FullBrakeLo'
                                        *   '<S42>/Constant8'
                                        * Minimum decceleration send in full brake(ex. -2.5)
                                        */
extern real32_T KfAEBS_a_ObjUrgentBrake_Thrsh;/* Variable: KfAEBS_a_ObjUrgentBrake_Thrsh
                                               * Referenced by: '<S76>/Constant5'
                                               */
extern real32_T KfAEBS_a_PartialBrakeHi;/* Variable: KfAEBS_a_PartialBrakeHi
                                         * Referenced by:
                                         *   '<S42>/KfAEBS_a_PartialBrakeHi'
                                         *   '<S42>/Constant7'
                                         * Maximum decceleration send in partial brake(ex. -4)
                                         */
extern real32_T KfAEBS_a_PartialBrakeLo;/* Variable: KfAEBS_a_PartialBrakeLo
                                         * Referenced by:
                                         *   '<S42>/KfAEBS_a_PartialBrakeLo'
                                         *   '<S42>/Constant6'
                                         * Minimum decceleration send in partial brake(ex. -2)
                                         */
extern real32_T KfAEBS_d_Dis2HeadIgnoreSide;/* Variable: KfAEBS_d_Dis2HeadIgnoreSide
                                             * Referenced by:
                                             *   '<S9>/KfAEBS_d_Dis2HeadIgnoreSide'
                                             *   '<S9>/Constant44'
                                             */
extern real32_T KfAEBS_d_Dis_BufferTTSP;/* Variable: KfAEBS_d_Dis_BufferTTSP
                                         * Referenced by:
                                         *   '<S9>/KfAEBS_d_Dis_BufferTTSP'
                                         *   '<S9>/Constant8'
                                         * Distance Buffer when calculate TTSP lateral
                                         */
extern real32_T KfAEBS_d_Dis_BufferTTSP_length;/* Variable: KfAEBS_d_Dis_BufferTTSP_length
                                                * Referenced by:
                                                *   '<S9>/KfAEBS_d_Dis_BufferTTSP_length'
                                                *   '<S9>/Constant9'
                                                * Distance Buffer when calculate TTSP long
                                                */
extern real32_T KfAEBS_d_Dis_LateralIgnore;/* Variable: KfAEBS_d_Dis_LateralIgnore
                                            * Referenced by:
                                            *   '<S9>/KfAEBS_d_Dis_LateralIgnore'
                                            *   '<S9>/Constant27'
                                            * Distance Lateral Ignore
                                            */
extern real32_T KfAEBS_d_Dis_Safe;     /* Variable: KfAEBS_d_Dis_Safe
                                        * Referenced by: '<S76>/Constant15'
                                        * Distance safe, when vehicle is stopped, the distance to obj
                                        */
extern real32_T KfAEBS_d_Dis_Safe_VRU; /* Variable: KfAEBS_d_Dis_Safe_VRU
                                        * Referenced by: '<S76>/Constant12'
                                        */
extern real32_T KfAEBS_d_lateral_max_lostClose;/* Variable: KfAEBS_d_lateral_max_lostClose
                                                * Referenced by:
                                                *   '<S95>/Constant2'
                                                *   '<S95>/Constant8'
                                                */
extern real32_T KfAEBS_d_lateral_min_lostClose;/* Variable: KfAEBS_d_lateral_min_lostClose
                                                * Referenced by:
                                                *   '<S95>/Constant10'
                                                *   '<S95>/Constant3'
                                                */
extern real32_T KfAEBS_d_long_max_lostClose;/* Variable: KfAEBS_d_long_max_lostClose
                                             * Referenced by:
                                             *   '<S95>/Constant7'
                                             *   '<S95>/Constant9'
                                             */
extern real32_T KfAEBS_d_long_min_lostClose;/* Variable: KfAEBS_d_long_min_lostClose
                                             * Referenced by:
                                             *   '<S95>/Constant1'
                                             *   '<S95>/Constant6'
                                             */
extern real32_T KfAEBS_d_min_dis_swap; /* Variable: KfAEBS_d_min_dis_swap
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_d_min_dis_swap'
                                        *   '<S9>/Constant37'
                                        */
extern real32_T KfAEBS_t_BrkPdlDeprssd_Thrsh;/* Variable: KfAEBS_t_BrkPdlDeprssd_Thrsh
                                              * Referenced by:
                                              *   '<S3>/KfAEBS_t_BrkPdlDeprssd_Thrsh'
                                              *   '<S3>/Constant3'
                                              */
extern real32_T KfAEBS_t_Speed_DebounceTime;/* Variable: KfAEBS_t_Speed_DebounceTime
                                             * Referenced by:
                                             *   '<S79>/Constant8'
                                             *   '<S205>/Constant8'
                                             * Speed debounce time, used to estimate whether the vheicle is standstill
                                             */
extern real32_T KfAEBS_t_TTC_DeactiveThrsh;/* Variable: KfAEBS_t_TTC_DeactiveThrsh
                                            * Referenced by:
                                            *   '<S204>/Constant2'
                                            *   '<S90>/Constant2'
                                            * TTC Deactive Thrsh
                                            */
extern real32_T KfAEBS_t_TTC_FCWLevel1DeactThrsd;/* Variable: KfAEBS_t_TTC_FCWLevel1DeactThrsd
                                                  * Referenced by: '<S207>/Constant1'
                                                  * TTC_FCW Level1 Deact Thrsd
                                                  */
extern real32_T KfAEBS_t_TTC_FCWLevel2DeactThrsd;/* Variable: KfAEBS_t_TTC_FCWLevel2DeactThrsd
                                                  * Referenced by: '<S208>/Constant1'
                                                  * TTC FCW Level2 Deact Thrsd
                                                  */
extern real32_T KfAEBS_t_TTC_FCWLevel3DeactThrsd;/* Variable: KfAEBS_t_TTC_FCWLevel3DeactThrsd
                                                  * Referenced by: '<S209>/Constant1'
                                                  * TTC FCW Level3 Deact Thrsd
                                                  */
extern real32_T KfAEBS_t_TTC_ObjChangThrsd;/* Variable: KfAEBS_t_TTC_ObjChangThrsd
                                            * Referenced by: '<S204>/Constant1'
                                            */
extern real32_T KfAEBS_t_TTC_PartialBrkDeactiveThrsd;/* Variable: KfAEBS_t_TTC_PartialBrkDeactiveThrsd
                                                      * Referenced by: '<S82>/Constant4'
                                                      * TTC Partial Brk Deactive Thrsd
                                                      */
extern real32_T KfAEBS_t_TTC_PreBrkDeactThrsd;/* Variable: KfAEBS_t_TTC_PreBrkDeactThrsd
                                               * Referenced by: '<S83>/Constant1'
                                               * KfAEBS TTC PreBrk Deact Thrsd
                                               */
extern real32_T KfAEBS_t_TimeBrakeConfdConfirmed;/* Variable: KfAEBS_t_TimeBrakeConfdConfirmed
                                                  * Referenced by:
                                                  *   '<S3>/KfAEBS_t_TimeBrakeConfdConfirmed'
                                                  *   '<S3>/Constant27'
                                                  */
extern real32_T KfAEBS_t_TimeBrakeThrsd;/* Variable: KfAEBS_t_TimeBrakeThrsd
                                         * Referenced by: '<S92>/VRednThdASILAInCllsnRednByBrkg1'
                                         */
extern real32_T KfAEBS_t_TimeExitActide;/* Variable: KfAEBS_t_TimeExitActide
                                         * Referenced by:
                                         *   '<S3>/KfAEBS_t_TimeExitActide'
                                         *   '<S3>/Constant1'
                                         */
extern real32_T KfAEBS_t_TimePreBrkThrsd;/* Variable: KfAEBS_t_TimePreBrkThrsd
                                          * Referenced by: '<S96>/VRednThdASILAInCllsnRednByBrkg1'
                                          */
extern real32_T KfAEBS_t_TimeWait2StandbyThrsh;/* Variable: KfAEBS_t_TimeWait2StandbyThrsh
                                                * Referenced by:
                                                *   '<S3>/KfAEBS_t_TimeWait2StandbyThrsh'
                                                *   '<S3>/Constant28'
                                                */
extern real32_T KfAEBS_t_Time_BrakeDelay;/* Variable: KfAEBS_t_Time_BrakeDelay
                                          * Referenced by: '<S76>/Constant2'
                                          * Time Brake Delay
                                          */
extern real32_T KfAEBS_t_Time_BrakeInit;/* Variable: KfAEBS_t_Time_BrakeInit
                                         * Referenced by:
                                         *   '<S42>/KfAEBS_t_Time_BrakeInit'
                                         *   '<S42>/Constant3'
                                         * Time Brake Init
                                         */
extern real32_T KfAEBS_t_Time_BrakeRamp;/* Variable: KfAEBS_t_Time_BrakeRamp
                                         * Referenced by:
                                         *   '<S42>/KfAEBS_t_Time_BrakeRamp'
                                         *   '<S42>/Constant5'
                                         * Time Brake Ramp
                                         */
extern real32_T KfAEBS_t_Time_HasNoVIPDelay;/* Variable: KfAEBS_t_Time_HasNoVIPDelay
                                             * Referenced by:
                                             *   '<S204>/Constant3'
                                             *   '<S91>/Constant3'
                                             * Time Has No VIP Delay
                                             */
extern real32_T KfAEBS_t_Time_OBFUNReceivedThrsh;/* Variable: KfAEBS_t_Time_OBFUNReceivedThrsh
                                                  * Referenced by:
                                                  *   '<S12>/Constant2'
                                                  *   '<S12>/Constant7'
                                                  * OBFU not receive time out
                                                  */
extern real32_T KfAEBS_t_Time_ObjUrgentBrk;/* Variable: KfAEBS_t_Time_ObjUrgentBrk
                                            * Referenced by: '<S76>/Constant7'
                                            */
extern real32_T KfAEBS_t_Time_ResetTimeBrkThrsd;/* Variable: KfAEBS_t_Time_ResetTimeBrkThrsd
                                                 * Referenced by: '<S101>/Constant3'
                                                 */
extern real32_T KfAEBS_t_Time_ResetVeloRdctThrsd;/* Variable: KfAEBS_t_Time_ResetVeloRdctThrsd
                                                  * Referenced by: '<S101>/Constant1'
                                                  */
extern real32_T KfAEBS_t_Time_TTCHLInhibitAEB;/* Variable: KfAEBS_t_Time_TTCHLInhibitAEB
                                               * Referenced by:
                                               *   '<S204>/Constant7'
                                               *   '<S90>/Constant4'
                                               *   '<S145>/Constant1'
                                               */
extern real32_T KfAEBS_t_Time_TwiceAEBActive;/* Variable: KfAEBS_t_Time_TwiceAEBActive
                                              * Referenced by: '<S142>/Constant4'
                                              */
extern real32_T KfAEBS_t_Time_TwiceFCWActive;/* Variable: KfAEBS_t_Time_TwiceFCWActive
                                              * Referenced by: '<S219>/Constant4'
                                              */
extern real32_T KfAEBS_t_Time_TwicePreBrkActive;/* Variable: KfAEBS_t_Time_TwicePreBrkActive
                                                 * Referenced by: '<S143>/Constant4'
                                                 */
extern real32_T KfAEBS_t_VipCloseLostTimeOut;/* Variable: KfAEBS_t_VipCloseLostTimeOut
                                              * Referenced by: '<S118>/Constant1'
                                              */
extern real32_T KfAEBS_t_fb_active_delay_turn;/* Variable: KfAEBS_t_fb_active_delay_turn
                                               * Referenced by: '<S129>/Constant6'
                                               */
extern real32_T KfAEBS_t_pb_active_delay_turn;/* Variable: KfAEBS_t_pb_active_delay_turn
                                               * Referenced by: '<S136>/Constant6'
                                               */
extern real32_T KfAEBS_t_timeGap_ignore_turn;/* Variable: KfAEBS_t_timeGap_ignore_turn
                                              * Referenced by:
                                              *   '<S9>/KfAEBS_t_timeGap_ignore_turn'
                                              *   '<S9>/Constant6'
                                              */
extern real32_T KfAEBS_v_ObjUrgentBrk_speed_Thrsh;/* Variable: KfAEBS_v_ObjUrgentBrk_speed_Thrsh
                                                   * Referenced by: '<S76>/Constant11'
                                                   */
extern real32_T KfAEBS_v_SpdCollisionInhibitAEB;/* Variable: KfAEBS_v_SpdCollisionInhibitAEB
                                                 * Referenced by: '<S145>/Constant2'
                                                 */
extern real32_T KfAEBS_v_SpeedLLThrshOvrrd;/* Variable: KfAEBS_v_SpeedLLThrshOvrrd
                                            * Referenced by: '<S41>/TiDlyDeactvnInCllsnRednByBrkg3'
                                            */
extern real32_T KfAEBS_v_SpeedRelLThrshOvrrd;/* Variable: KfAEBS_v_SpeedRelLThrshOvrrd
                                              * Referenced by: '<S41>/TiDlyDeactvnInCllsnRednByBrkg1'
                                              */
extern real32_T KfAEBS_v_Speed_DeltaStStThrsh;/* Variable: KfAEBS_v_Speed_DeltaStStThrsh
                                               * Referenced by:
                                               *   '<S79>/Constant7'
                                               *   '<S205>/Constant7'
                                               * delta speed, used to estimate whether the vheicle is standstill
                                               */
extern real32_T KfAEBS_v_Speed_DeltaWExit;/* Variable: KfAEBS_v_Speed_DeltaWExit
                                           * Referenced by:
                                           *   '<S9>/KfAEBS_v_Speed_DeltaWExit'
                                           *   '<S9>/Constant26'
                                           * Delta speed warning exit, if front veh's speed is larger than ego, fornt veh can be filterd
                                           */
extern real32_T KfAEBS_v_Speed_High_InhibitAEB;/* Variable: KfAEBS_v_Speed_High_InhibitAEB
                                                * Referenced by: '<S145>/Constant3'
                                                */
extern real32_T KfAEBS_v_Speed_MaxInhibitAEB;/* Variable: KfAEBS_v_Speed_MaxInhibitAEB
                                              * Referenced by: '<S145>/Constant7'
                                              * The speed to active AEB
                                              */
extern real32_T KfAEBS_v_Speed_ObjStillThrsh;/* Variable: KfAEBS_v_Speed_ObjStillThrsh
                                              * Referenced by:
                                              *   '<S9>/KfAEBS_v_Speed_ObjStillThrsh'
                                              *   '<S9>/Constant14'
                                              * Obj speed threshold to be estimated as standstill in long
                                              */
extern real32_T KfAEBS_v_Speed_ObjStillThrshLateral;/* Variable: KfAEBS_v_Speed_ObjStillThrshLateral
                                                     * Referenced by:
                                                     *   '<S9>/KfAEBS_v_Speed_ObjStillThrshLateral'
                                                     *   '<S9>/Constant25'
                                                     * Obj speed threshold to be estimated as standstill in lateral
                                                     */
extern real32_T KfAEBS_v_Speed_StandStillThrsh;/* Variable: KfAEBS_v_Speed_StandStillThrsh
                                                * Referenced by:
                                                *   '<S79>/Constant6'
                                                *   '<S205>/Constant6'
                                                * Speed, used to estimate whether the vheicle is standstill
                                                */
extern real32_T KfAEBS_v_VipStationaryThrshld;/* Variable: KfAEBS_v_VipStationaryThrshld
                                               * Referenced by:
                                               *   '<S94>/Constant1'
                                               *   '<S94>/Constant9'
                                               */
extern real32_T KfAEBS_v_deltaSpeed_InhibitAEB;/* Variable: KfAEBS_v_deltaSpeed_InhibitAEB
                                                * Referenced by: '<S145>/Constant5'
                                                */
extern real32_T KfAEBS_v_isInHighSpeed_HighThrshd;/* Variable: KfAEBS_v_isInHighSpeed_HighThrshd
                                                   * Referenced by: '<S123>/Constant2'
                                                   */
extern real32_T KfAEBS_v_isInHighSpeed_LowThrshd;/* Variable: KfAEBS_v_isInHighSpeed_LowThrshd
                                                  * Referenced by: '<S123>/Constant1'
                                                  */
extern real32_T KfAEBS_v_obsSpdBuffer; /* Variable: KfAEBS_v_obsSpdBuffer
                                        * Referenced by:
                                        *   '<S9>/KfAEBS_v_obsSpdBuffer'
                                        *   '<S9>/Constant13'
                                        */
extern real32_T KfAEBS_v_obsSpeedArcMin;/* Variable: KfAEBS_v_obsSpeedArcMin
                                         * Referenced by:
                                         *   '<S9>/KfAEBS_v_obsSpeedArcMin'
                                         *   '<S9>/Constant11'
                                         */
extern real32_T KfAEBS_v_speed_max_lostClose;/* Variable: KfAEBS_v_speed_max_lostClose
                                              * Referenced by: '<S95>/Constant4'
                                              */
extern real32_T KfAEBS_v_speed_min_lostClose;/* Variable: KfAEBS_v_speed_min_lostClose
                                              * Referenced by: '<S95>/Constant5'
                                              */
extern real32_T KtAEBS_FCWL1ActiveTTCThrshld[13];/* Variable: KtAEBS_FCWL1ActiveTTCThrshld
                                                  * Referenced by: '<S207>/Partial_FCWL1TTCThreshold_table'
                                                  */
extern real32_T KtAEBS_FCWL2ActiveTTCThrshld[13];/* Variable: KtAEBS_FCWL2ActiveTTCThrshld
                                                  * Referenced by: '<S208>/Partial_FCWL2TTCThreshold_table'
                                                  */
extern real32_T KtAEBS_FCWL3ActiveTTCThrshld[13];/* Variable: KtAEBS_FCWL3ActiveTTCThrshld
                                                  * Referenced by: '<S209>/Partial_FCWL3TTCThreshold_table'
                                                  */
extern real32_T KtAEBS_FullBrkActiveAccThrshld[13];/* Variable: KtAEBS_FullBrkActiveAccThrshld
                                                    * Referenced by: '<S126>/Full_BrkActiveAccThreshold_table'
                                                    */
extern real32_T KtAEBS_LateralBuffer_Bicycle[11];/* Variable: KtAEBS_LateralBuffer_Bicycle
                                                  * Referenced by: '<S171>/lateral_buffer_bicycle_table'
                                                  */
extern real32_T KtAEBS_LateralBuffer_Motor[11];/* Variable: KtAEBS_LateralBuffer_Motor
                                                * Referenced by: '<S172>/lateral_buffer_motorcycle_table'
                                                */
extern real32_T KtAEBS_LateralBuffer_Other[11];/* Variable: KtAEBS_LateralBuffer_Other
                                                * Referenced by: '<S173>/lateral_buffer_other_table'
                                                */
extern real32_T KtAEBS_LateralBuffer_Pedstrn[11];/* Variable: KtAEBS_LateralBuffer_Pedstrn
                                                  * Referenced by: '<S174>/lateral_buffer_pedestrain_table'
                                                  */
extern real32_T KtAEBS_LateralBuffer_Vehicle[11];/* Variable: KtAEBS_LateralBuffer_Vehicle
                                                  * Referenced by: '<S175>/lateral_buffer_vehicle_table'
                                                  */
extern real32_T KtAEBS_LongBuffer_Bicycle[11];/* Variable: KtAEBS_LongBuffer_Bicycle
                                               * Referenced by: '<S176>/long_buffer_bicycle_table'
                                               */
extern real32_T KtAEBS_LongBuffer_Motor[11];/* Variable: KtAEBS_LongBuffer_Motor
                                             * Referenced by: '<S177>/long_buffer_motorcycle_table'
                                             */
extern real32_T KtAEBS_LongBuffer_Other[11];/* Variable: KtAEBS_LongBuffer_Other
                                             * Referenced by: '<S178>/long_buffer_other_table'
                                             */
extern real32_T KtAEBS_LongBuffer_Pedstrn[11];/* Variable: KtAEBS_LongBuffer_Pedstrn
                                               * Referenced by: '<S179>/long_buffer_pedestrain_table'
                                               */
extern real32_T KtAEBS_LongBuffer_Vehicle[11];/* Variable: KtAEBS_LongBuffer_Vehicle
                                               * Referenced by: '<S180>/long_buffer_vehicle_table'
                                               */
extern real32_T KtAEBS_PreBrkActiveTTCThrshld[13];/* Variable: KtAEBS_PreBrkActiveTTCThrshld
                                                   * Referenced by: '<S141>/Pre_BrakeActiveTTCThreshold_table'
                                                   */
extern real32_T KtAEBS_PreBrkActiveTTCThrshld_VRU[13];/* Variable: KtAEBS_PreBrkActiveTTCThrshld_VRU
                                                       * Referenced by: '<S141>/Pre_BrakeActiveTTCThreshold_VRU_table'
                                                       */
extern real32_T KtAEBS_PrtlBrkActiveTTCThrshld[13];/* Variable: KtAEBS_PrtlBrkActiveTTCThrshld
                                                    * Referenced by: '<S134>/Partial_BrakeActiveTTCThreshold_table'
                                                    */
extern real32_T KtAEBS_PrtlBrkActiveTTCThrshld_VRU[13];/* Variable: KtAEBS_PrtlBrkActiveTTCThrshld_VRU
                                                        * Referenced by: '<S134>/Partial_BrakeActiveTTCThreshold_VRU_table'
                                                        */
extern real32_T KtAEBS_a_BrakeValueLimit[10];/* Variable: KtAEBS_a_BrakeValueLimit
                                              * Referenced by: '<S48>/BrakeValueLimit_Table'
                                              */
extern real32_T KtAEBS_veh_acc_inhibit_AEB_thrhd[9];/* Variable: KtAEBS_veh_acc_inhibit_AEB_thrhd
                                                     * Referenced by: '<S146>/veh_acc_AEB_inhibit_thrhd_table'
                                                     */
extern real32_T KtAEBS_veh_widthGain[9];/* Variable: KtAEBS_veh_widthGain
                                         * Referenced by: '<S9>/veh_widthGain_table'
                                         */
extern int32_T KfAEBS_Default_AEBS_obj_ID;/* Variable: KfAEBS_Default_AEBS_obj_ID
                                           * Referenced by: '<S2>/Constant13'
                                           * Default AEBS obj ID
                                           */
extern int8_T KfAEBS_VIPObsType;       /* Variable: KfAEBS_VIPObsType
                                        * Referenced by: '<S164>/Constant1'
                                        */
extern uint8_T KfAEBS_AccPdl_InhbtDeact_thrshld;/* Variable: KfAEBS_AccPdl_InhbtDeact_thrshld
                                                 * Referenced by:
                                                 *   '<S77>/Constant9'
                                                 *   '<S84>/Constant2'
                                                 *   '<S210>/Constant2'
                                                 */
extern uint8_T KfAEBS_AccPedelThrshOvrrd;/* Variable: KfAEBS_AccPedelThrshOvrrd
                                          * Referenced by: '<S41>/TiDlyDeactvnInCllsnRednByBrkg4'
                                          * Acc Pedel threshold when override
                                          */
extern uint8_T KfAEBS_Confdnc_FullBrkActThrsd;/* Variable: KfAEBS_Confdnc_FullBrkActThrsd
                                               * Referenced by: '<S81>/Constant3'
                                               */
extern uint8_T KfAEBS_Confdnc_PartialBrkActThrsd;/* Variable: KfAEBS_Confdnc_PartialBrkActThrsd
                                                  * Referenced by: '<S82>/Constant3'
                                                  */
extern uint8_T KfAEBS_Confidnc_Deact_thrshld;/* Variable: KfAEBS_Confidnc_Deact_thrshld
                                              * Referenced by: '<S77>/Constant1'
                                              */
extern uint8_T KfAEBS_Default_AEB_error;/* Variable: KfAEBS_Default_AEB_error
                                         * Referenced by: '<S2>/Constant12'
                                         * Default AEB error
                                         */
extern uint8_T KfAEBS_Default_FCW_error;/* Variable: KfAEBS_Default_FCW_error
                                         * Referenced by: '<S2>/Constant4'
                                         * Default FCW error
                                         */
extern uint8_T KfAEBS_Default_FCW_warn_level;/* Variable: KfAEBS_Default_FCW_warn_level
                                              * Referenced by: '<S2>/Constant1'
                                              * Default FCW warn level
                                              */
extern uint8_T KfAEBS_EPB_Engaged_Value;/* Variable: KfAEBS_EPB_Engaged_Value
                                         * Referenced by: '<S8>/Constant4'
                                         */
extern uint8_T KfAEBS_Gear_Value_R;    /* Variable: KfAEBS_Gear_Value_R
                                        * Referenced by:
                                        *   '<S84>/Constant1'
                                        *   '<S210>/Constant1'
                                        * Gear_Value_R
                                        */
extern uint8_T KfAEBS_LoPosValInCllsnRednByBrkg;/* Variable: KfAEBS_LoPosValInCllsnRednByBrkg
                                                 * Referenced by:
                                                 *   '<S43>/LoPosValInCllsnRednByBrkg  '
                                                 *   '<S196>/LoPosValInCllsnRednByBrkg  '
                                                 */
extern boolean_T KbAEBS_Active_LeftTurn;/* Variable: KbAEBS_Active_LeftTurn
                                         * Referenced by: '<S166>/Constant4'
                                         * Left turn collision mitigation active
                                         */
extern boolean_T KbAEBS_Active_RightTurn;/* Variable: KbAEBS_Active_RightTurn
                                          * Referenced by: '<S166>/Constant3'
                                          * Right turn collision mitigation active
                                          */
extern boolean_T KbAEBS_Active_Straight;/* Variable: KbAEBS_Active_Straight
                                         * Referenced by: '<S166>/Constant2'
                                         * Ego go straight collision mitigation active
                                         */
extern boolean_T KbAEBS_AllowOverride; /* Variable: KbAEBS_AllowOverride
                                        * Referenced by: '<S41>/TiDlyDeactvnInCllsnRednByBrkg2'
                                        * Allow driver override
                                        */
extern boolean_T KbAEBS_Default_AEB_brakeLight_req;/* Variable: KbAEBS_Default_AEB_brakeLight_req
                                                    * Referenced by: '<S2>/Constant8'
                                                    * Default AEB brakeLight req
                                                    */
extern boolean_T KbAEBS_Default_AEB_prebrake_req;/* Variable: KbAEBS_Default_AEB_prebrake_req
                                                  * Referenced by: '<S2>/Constant6'
                                                  * Default AEB prebrake req
                                                  */
extern boolean_T KbAEBS_Default_AEB_request;/* Variable: KbAEBS_Default_AEB_request
                                             * Referenced by: '<S2>/Constant5'
                                             * Default AEB request
                                             */
extern boolean_T KbAEBS_Default_FCW_requset;/* Variable: KbAEBS_Default_FCW_requset
                                             * Referenced by: '<S2>/Constant'
                                             * Default FCW requset
                                             */
extern boolean_T KbAEBS_Enable_AEB_feature;/* Variable: KbAEBS_Enable_AEB_feature
                                            * Referenced by: '<S1>/Constant27'
                                            */
extern boolean_T KbAEBS_Enable_DoRbIW; /* Variable: KbAEBS_Enable_DoRbIW
                                        * Referenced by:
                                        *   '<S9>/KbAEBS_Enable_DoRbIW'
                                        *   '<S9>/Constant34'
                                        */
extern boolean_T KbAEBS_Enable_DoRbIW_LeftTurn;/* Variable: KbAEBS_Enable_DoRbIW_LeftTurn
                                                * Referenced by:
                                                *   '<S9>/KbAEBS_Enable_DoRbIW_LeftTurn'
                                                *   '<S9>/Constant38'
                                                */
extern boolean_T KbAEBS_Enable_Error;  /* Variable: KbAEBS_Enable_Error
                                        * Referenced by: '<S6>/Constant31'
                                        */
extern boolean_T KbAEBS_Enable_OutputAEB;/* Variable: KbAEBS_Enable_OutputAEB
                                          * Referenced by:
                                          *   '<S39>/Constant3'
                                          *   '<S39>/Constant4'
                                          * Enable output decceleration/ AEB request
                                          */
extern boolean_T KbAEBS_Enable_VRU_Calibration;/* Variable: KbAEBS_Enable_VRU_Calibration
                                                * Referenced by: '<S78>/Constant2'
                                                */
extern boolean_T KbAEBS_FilterVehicleinSide;/* Variable: KbAEBS_FilterVehicleinSide
                                             * Referenced by:
                                             *   '<S9>/KbAEBS_FilterVehicleinSide'
                                             *   '<S9>/Constant45'
                                             */
extern boolean_T KbAEBS_RedifineVIPObsType;/* Variable: KbAEBS_RedifineVIPObsType
                                            * Referenced by: '<S164>/Constant5'
                                            */
extern boolean_T KbAEBS_Test_Mode;     /* Variable: KbAEBS_Test_Mode
                                        * Referenced by:
                                        *   '<S9>/Constant31'
                                        *   '<S9>/Constant33'
                                        */
extern boolean_T KbAEBS_Use_CAN_VehSpeed;/* Variable: KbAEBS_Use_CAN_VehSpeed
                                          * Referenced by: '<S6>/Constant3'
                                          */
extern boolean_T KbAEBS_Use_OBFU_Acceleration;/* Variable: KbAEBS_Use_OBFU_Acceleration
                                               * Referenced by:
                                               *   '<S9>/KbAEBS_Use_OBFU_Acceleration'
                                               *   '<S9>/Constant39'
                                               */
extern boolean_T KbAEBS_Use_OBFU_Type; /* Variable: KbAEBS_Use_OBFU_Type
                                        * Referenced by:
                                        *   '<S9>/KbAEBS_Use_OBFU_Type'
                                        *   '<S9>/Constant40'
                                        */
extern boolean_T KbAEBS_enable_PreBrake;/* Variable: KbAEBS_enable_PreBrake
                                         * Referenced by: '<S84>/Constant4'
                                         */
extern boolean_T KbAEBS_use_OBFU_speed;/* Variable: KbAEBS_use_OBFU_speed
                                        * Referenced by:
                                        *   '<S9>/KbAEBS_use_OBFU_speed'
                                        *   '<S9>/Constant12'
                                        */
extern boolean_T KbAEBS_use_steerAngle;/* Variable: KbAEBS_use_steerAngle
                                        * Referenced by:
                                        *   '<S128>/Constant2'
                                        *   '<S135>/Constant2'
                                        */
extern boolean_T KfAEBS_Default_BrkPrioriy;/* Variable: KfAEBS_Default_BrkPrioriy
                                            * Referenced by: '<S2>/Constant14'
                                            */
extern boolean_T KfAEBS_Default_Horn_Req;/* Variable: KfAEBS_Default_Horn_Req
                                          * Referenced by: '<S2>/Constant9'
                                          */
extern EnumAEBS_EnblState KfAEBS_Default_AEB_enabled_state;/* Variable: KfAEBS_Default_AEB_enabled_state
                                                            * Referenced by: '<S2>/Constant10'
                                                            * Default AEB enabled state
                                                            */
extern EnumAEBS_EnblState KfAEBS_Default_FCW_enable_state;/* Variable: KfAEBS_Default_FCW_enable_state
                                                           * Referenced by: '<S2>/Constant2'
                                                           * Default FCW enable state
                                                           */
extern EnumAEBS_FCWState KfAEBS_Default_FCW_active_state;/* Variable: KfAEBS_Default_FCW_active_state
                                                          * Referenced by: '<S2>/Constant3'
                                                          * Default FCW active state
                                                          */
extern EnumAEBS_AEBState KfAEBS_Default_AEB_actived_state;/* Variable: KfAEBS_Default_AEB_actived_state
                                                           * Referenced by: '<S2>/Constant11'
                                                           * Default AEB actived state
                                                           */

/* Model entry point functions */
extern void AEBS_subsystem_integrated_initialize(void);
extern void AEBS_subsystem_integrated_step(void);

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
 * '<Root>' : 'AEBS_subsystem_integrated'
 * '<S1>'   : 'AEBS_subsystem_integrated/AEBS'
 * '<S2>'   : 'AEBS_subsystem_integrated/AEBS/AEBS_Default'
 * '<S3>'   : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled'
 * '<S4>'   : 'AEBS_subsystem_integrated/AEBS/Monitor'
 * '<S5>'   : 'AEBS_subsystem_integrated/AEBS/Monitor1'
 * '<S6>'   : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input'
 * '<S7>'   : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output'
 * '<S8>'   : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination'
 * '<S9>'   : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection'
 * '<S10>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination'
 * '<S11>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/Enumerated Constant2'
 * '<S12>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/Error Detection'
 * '<S13>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/adc_path_prediction'
 * '<S14>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/veh_FedBck_update'
 * '<S15>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/Error Detection/Enumerated Constant'
 * '<S16>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/Error Detection/Enumerated Constant1'
 * '<S17>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/Error Detection/Enumerated Constant2'
 * '<S18>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/Error Detection/RaisingEdgeDelay'
 * '<S19>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/Error Detection/RaisingEdgeDelay1'
 * '<S20>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/Error Detection/RaisingEdgeDelay/Chart'
 * '<S21>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/Error Detection/RaisingEdgeDelay1/Chart'
 * '<S22>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/adc_path_prediction/evidezero'
 * '<S23>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/adc_path_prediction/evidezero1'
 * '<S24>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/adc_path_prediction/evidezero/DividByZero'
 * '<S25>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/adc_path_prediction/evidezero1/DividByZero'
 * '<S26>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Input/veh_FedBck_update/Init_veh_FedBck'
 * '<S27>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output/updataFcwWarning'
 * '<S28>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output/updateobsID'
 * '<S29>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output/updataFcwWarning/Enumerated Constant'
 * '<S30>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output/updataFcwWarning/Enumerated Constant1'
 * '<S31>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output/updataFcwWarning/Enumerated Constant2'
 * '<S32>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output/updataFcwWarning/Enumerated Constant3'
 * '<S33>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output/updataFcwWarning/Enumerated Constant4'
 * '<S34>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output/updateobsID/Enumerated Constant1'
 * '<S35>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output/updateobsID/Enumerated Constant2'
 * '<S36>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output/updateobsID/Enumerated Constant3'
 * '<S37>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output/updateobsID/Enumerated Constant4'
 * '<S38>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEBS_Output/updateobsID/Enumerated Constant5'
 * '<S39>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus'
 * '<S40>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation'
 * '<S41>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/QueueOverride'
 * '<S42>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration'
 * '<S43>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CheckAEBS_SystemOverride'
 * '<S44>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/DtrmnAEB_State'
 * '<S45>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/Subsystem2'
 * '<S46>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/hasFault'
 * '<S47>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/AccelReqFilter'
 * '<S48>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/AccelerationLimit'
 * '<S49>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/ClacCurrTime'
 * '<S50>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest'
 * '<S51>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/First Order Low Pass Filter'
 * '<S52>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/MATLAB Function'
 * '<S53>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/AccelerationLimit/Saturation Dynamic'
 * '<S54>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest'
 * '<S55>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/Compare To Zero'
 * '<S56>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DetermineFullBrakeRequest'
 * '<S57>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DeterminePreBrakeRequest'
 * '<S58>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DetermineFullBrakeRequest/AccelReqFilter'
 * '<S59>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DetermineFullBrakeRequest/Saturation Dynamic'
 * '<S60>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DetermineFullBrakeRequest/Saturation Dynamic1'
 * '<S61>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DeterminePreBrakeRequest/SimplePreChargeRequest'
 * '<S62>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DeterminePreBrakeRequest/SimplePreChargeRequest/PreBrakingAccelerationRequest'
 * '<S63>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DeterminePreBrakeRequest/SimplePreChargeRequest/PreBrkRateLimiter '
 * '<S64>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DeterminePreBrakeRequest/SimplePreChargeRequest/PreBrakingAccelerationRequest/Saturation Dynamic'
 * '<S65>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DeterminePreBrakeRequest/SimplePreChargeRequest/PreBrkRateLimiter /BrkgRelbl'
 * '<S66>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DeterminePreBrakeRequest/SimplePreChargeRequest/PreBrkRateLimiter /Enumerated Constant'
 * '<S67>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DeterminePreBrakeRequest/SimplePreChargeRequest/PreBrkRateLimiter /PreBrakeActive'
 * '<S68>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DeterminePreBrakeRequest/SimplePreChargeRequest/PreBrkRateLimiter /RateLimiter'
 * '<S69>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DeterminePreBrakeRequest/SimplePreChargeRequest/PreBrkRateLimiter /PreBrakeActive/Enumerated Constant'
 * '<S70>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/DetermineCMbBRequest/DetermineAccelerationRequest/DeterminePreBrakeRequest/SimplePreChargeRequest/PreBrkRateLimiter /PreBrakeActive/Enumerated Constant1'
 * '<S71>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CalcAEBSAcceleration/First Order Low Pass Filter/Subsystem'
 * '<S72>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/CheckAEBS_SystemOverride/SetResetFlipFlop'
 * '<S73>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/hasFault/Enumerated Constant'
 * '<S74>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/hasFault/Enumerated Constant1'
 * '<S75>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DetermineAEBStatus/hasFault/Enumerated Constant2'
 * '<S76>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/CalcObsAreq'
 * '<S77>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive'
 * '<S78>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Dtrn_VUR_and_VRU_Protection'
 * '<S79>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Dtrn_vehicleStandStill'
 * '<S80>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Enable Evaluation'
 * '<S81>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/FullBrakeThreat'
 * '<S82>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/PartialBrakeThreat'
 * '<S83>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Prebrake Threat'
 * '<S84>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit'
 * '<S85>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/CalcObsAreq/RaisingEdgeDelay2'
 * '<S86>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/CalcObsAreq/Subsystem2'
 * '<S87>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/CalcObsAreq/RaisingEdgeDelay2/Chart'
 * '<S88>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/CalcObsAreq/Subsystem2/Subsystem'
 * '<S89>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/CalcObsAreq/Subsystem2/Subsystem1'
 * '<S90>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/HighTTCDeactive'
 * '<S91>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/RisingEdgeDelay'
 * '<S92>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring'
 * '<S93>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/VIPChange_Deactive'
 * '<S94>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/VIPStationary'
 * '<S95>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/VIP_lost_close'
 * '<S96>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/preBrakeTimeOutDetection'
 * '<S97>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/HighTTCDeactive/RaisingEdgeDelay2'
 * '<S98>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/HighTTCDeactive/RaisingEdgeDelay2/Chart'
 * '<S99>'  : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/RisingEdgeDelay/RaisingEdgeDelay'
 * '<S100>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/RisingEdgeDelay/RaisingEdgeDelay/Chart'
 * '<S101>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring/SpeedReductionASILACheck'
 * '<S102>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring/SpeedReductionASILACheck/BrakeTimeState'
 * '<S103>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring/SpeedReductionASILACheck/IntvBasedOnQmInfo'
 * '<S104>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring/SpeedReductionASILACheck/SpeedReductionStates'
 * '<S105>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring/SpeedReductionASILACheck/IntvBasedOnQmInfo/Enumerated Constant'
 * '<S106>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring/SpeedReductionASILACheck/IntvBasedOnQmInfo/Enumerated Constant1'
 * '<S107>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring/SpeedReductionASILACheck/IntvBasedOnQmInfo/Enumerated Constant2'
 * '<S108>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring/SpeedReductionASILACheck/IntvBasedOnQmInfo/Enumerated Constant3'
 * '<S109>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring/SpeedReductionASILACheck/IntvBasedOnQmInfo/Enumerated Constant4'
 * '<S110>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring/SpeedReductionASILACheck/IntvBasedOnQmInfo/Enumerated Constant5'
 * '<S111>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring/SpeedReductionASILACheck/IntvBasedOnQmInfo/Enumerated Constant6'
 * '<S112>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/SpeedReductionMonitoring/SpeedReductionASILACheck/IntvBasedOnQmInfo/SRFlipFlop'
 * '<S113>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/VIPChange_Deactive/ObjChangeDetection'
 * '<S114>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/VIPChange_Deactive/ObjDataChangeDetection'
 * '<S115>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/VIPStationary/SetResetFlipFlop'
 * '<S116>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/VIP_lost_close/FallingEdgeDetection'
 * '<S117>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/VIP_lost_close/SetResetFlipFlop'
 * '<S118>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/VIP_lost_close/vipCloseLostTimeOut'
 * '<S119>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/VIP_lost_close/vipCloseLostTimeOut/VIPCloseLostTime'
 * '<S120>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/preBrakeTimeOutDetection/BrakeTimeState'
 * '<S121>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Deactive/preBrakeTimeOutDetection/Enumerated Constant4'
 * '<S122>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Dtrn_VUR_and_VRU_Protection/Dtrn_VRU_obstacle'
 * '<S123>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Dtrn_VUR_and_VRU_Protection/Dtrn_VehicleSpeedState'
 * '<S124>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Dtrn_VUR_and_VRU_Protection/Dtrn_VehicleSpeedState/Chart'
 * '<S125>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Dtrn_vehicleStandStill/Stop_Moving_Estimation'
 * '<S126>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/FullBrakeThreat/Dtrn_Acc_Threshold'
 * '<S127>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/FullBrakeThreat/Enumerated Constant'
 * '<S128>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/FullBrakeThreat/Subsystem'
 * '<S129>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/FullBrakeThreat/Subsystem1'
 * '<S130>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/FullBrakeThreat/Subsystem/SetResetFlipFlop'
 * '<S131>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/FullBrakeThreat/Subsystem/SetResetFlipFlop1'
 * '<S132>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/FullBrakeThreat/Subsystem1/RaisingEdgeDelay'
 * '<S133>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/FullBrakeThreat/Subsystem1/RaisingEdgeDelay/Chart'
 * '<S134>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/PartialBrakeThreat/Dtrn_TTC_Threshold'
 * '<S135>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/PartialBrakeThreat/Subsystem'
 * '<S136>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/PartialBrakeThreat/Subsystem1'
 * '<S137>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/PartialBrakeThreat/Subsystem/SetResetFlipFlop'
 * '<S138>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/PartialBrakeThreat/Subsystem/SetResetFlipFlop1'
 * '<S139>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/PartialBrakeThreat/Subsystem1/RaisingEdgeDelay'
 * '<S140>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/PartialBrakeThreat/Subsystem1/RaisingEdgeDelay/Chart'
 * '<S141>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/Prebrake Threat/Dtrn_TTC_Threshold'
 * '<S142>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/Deactive_time_inhibit'
 * '<S143>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/Deactive_time_inhibit1'
 * '<S144>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/Steer_angle_rate_inhibit'
 * '<S145>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/speed_inhibit'
 * '<S146>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/veh_acceleration_inhibit'
 * '<S147>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/Deactive_time_inhibit/Enumerated Constant'
 * '<S148>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/Deactive_time_inhibit/Enumerated Constant1'
 * '<S149>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/Deactive_time_inhibit/Enumerated Constant3'
 * '<S150>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/Deactive_time_inhibit/Enumerated Constant4'
 * '<S151>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/Deactive_time_inhibit/Enumerated Constant5'
 * '<S152>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/Deactive_time_inhibit/Enumerated Constant6'
 * '<S153>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/Deactive_time_inhibit1/Enumerated Constant3'
 * '<S154>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/Deactive_time_inhibit1/Enumerated Constant4'
 * '<S155>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/speed_inhibit/Dtrn_Vehicle_obstacle'
 * '<S156>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/DtrmnThreatEvaluation/inhibit/speed_inhibit/Saturation Dynamic'
 * '<S157>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/QueueOverride/ConfirmBrakePedlPsd'
 * '<S158>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/QueueOverride/Detect Decrease'
 * '<S159>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/QueueOverride/Detect Increase'
 * '<S160>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/QueueOverride/S-R Flip-Flop'
 * '<S161>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_Determination/QueueOverride/ConfirmBrakePedlPsd/OnDelayBlock'
 * '<S162>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/AEB_Target_Selection'
 * '<S163>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer'
 * '<S164>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/RedifineVIPObsType'
 * '<S165>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/SubsystemMonitor'
 * '<S166>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState'
 * '<S167>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer'
 * '<S168>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/Calc_lateral_buffer'
 * '<S169>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/Calc_long_buffer'
 * '<S170>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/ObsIgnore'
 * '<S171>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/Calc_lateral_buffer/Bicycle'
 * '<S172>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/Calc_lateral_buffer/Motorcycle'
 * '<S173>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/Calc_lateral_buffer/Other'
 * '<S174>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/Calc_lateral_buffer/Pedestrain'
 * '<S175>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/Calc_lateral_buffer/VehicleBusTruck'
 * '<S176>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/Calc_long_buffer/Bicycle'
 * '<S177>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/Calc_long_buffer/Motorcycle'
 * '<S178>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/Calc_long_buffer/Other'
 * '<S179>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/Calc_long_buffer/Pedestrain'
 * '<S180>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/Calc_obs_lateral_long_buffer/Calc_Lateral_long_buffer/Calc_long_buffer/VehicleBusTruck'
 * '<S181>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState/Chart'
 * '<S182>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState/Default'
 * '<S183>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState/Enumerated Constant'
 * '<S184>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState/Enumerated Constant1'
 * '<S185>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState/Enumerated Constant2'
 * '<S186>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState/LeftTurn'
 * '<S187>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState/RightTurn'
 * '<S188>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState/Straight'
 * '<S189>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState/Default/Enumerated Constant2'
 * '<S190>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState/LeftTurn/Enumerated Constant2'
 * '<S191>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState/RightTurn/Enumerated Constant1'
 * '<S192>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/AEB_FCWVIPTargetSelection/TurnState/Straight/Enumerated Constant'
 * '<S193>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/DetermineFCWStatus'
 * '<S194>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/Override'
 * '<S195>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation'
 * '<S196>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/DetermineFCWStatus/CheckAEBS_SystemOverride'
 * '<S197>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/DetermineFCWStatus/DtrmnFCW_State'
 * '<S198>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/DetermineFCWStatus/FCW_active'
 * '<S199>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/DetermineFCWStatus/hasFault'
 * '<S200>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/DetermineFCWStatus/CheckAEBS_SystemOverride/SetResetFlipFlop'
 * '<S201>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/DetermineFCWStatus/hasFault/Enumerated Constant'
 * '<S202>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/DetermineFCWStatus/hasFault/Enumerated Constant1'
 * '<S203>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/DetermineFCWStatus/hasFault/Enumerated Constant2'
 * '<S204>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/Deactive'
 * '<S205>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/Dtrn_vehicleStandStill'
 * '<S206>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/Enable Evaluation'
 * '<S207>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/FCW_level1 Threat'
 * '<S208>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/FCW_level2 Threat'
 * '<S209>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/FCW_level3 Threat'
 * '<S210>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/inhibit'
 * '<S211>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/Deactive/ObjChangeDetection'
 * '<S212>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/Deactive/ObjDataChangeDetection'
 * '<S213>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/Deactive/RaisingEdgeDelay'
 * '<S214>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/Deactive/RaisingEdgeDelay1'
 * '<S215>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/Deactive/RaisingEdgeDelay/Chart'
 * '<S216>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/Deactive/RaisingEdgeDelay1/Chart'
 * '<S217>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/Dtrn_vehicleStandStill/Stop_Moving_Estimation'
 * '<S218>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/Enable Evaluation/Enumerated Constant'
 * '<S219>' : 'AEBS_subsystem_integrated/AEBS/AEBS_Enabled/FCW_Determination/ThreatEvaluation/inhibit/Deactive_time_inhibit'
 */
#endif                                 /* RTW_HEADER_AEBS_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
