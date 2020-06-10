/*
 * File: ACCS_subsystem_integrated.h
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

#ifndef RTW_HEADER_ACCS_subsystem_integrated_h_
#define RTW_HEADER_ACCS_subsystem_integrated_h_
#include <string.h>
#ifndef ACCS_subsystem_integrated_COMMON_INCLUDES_
# define ACCS_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* ACCS_subsystem_integrated_COMMON_INCLUDES_ */

#include "ACCS_subsystem_integrated_types.h"

/* Child system includes */
#include "ACCS_Task.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct
{
  OBFU_Obstacle VsACCS_Input_Obs_CIPV; /* '<S35>/DtrmnACCS_ObstacleExtraction' */
  OBFU_Obstacle VsACCS_Input_Obs_CIPVR;/* '<S35>/DtrmnACCS_ObstacleExtraction' */
  OBFU_Obstacle VsACCS_Input_Obs_CIPVL;/* '<S35>/DtrmnACCS_ObstacleExtraction' */
  OBFU_Obstacle VsACCS_Input_Obs_F;    /* '<S35>/DtrmnACCS_ObstacleExtraction' */
  OBFU_Obstacle VsACCS_Input_Obs_L;    /* '<S35>/DtrmnACCS_ObstacleExtraction' */
  OBFU_Obstacle VsACCS_Input_Obs_R;    /* '<S35>/DtrmnACCS_ObstacleExtraction' */
  real32_T Product1;                   /* '<S129>/Product1' */
  real32_T Product;                    /* '<S129>/Product' */
  real32_T Product_cgsn;               /* '<S123>/Product' */
  real32_T Delay;                      /* '<S14>/Delay' */
  real32_T VfACCS_Input_stop_s_distance_DC;/* '<S14>/BusConversion_InsertedFor_ACCS_DCSN_BUS _at_inport_0' */
  real32_T VfACCS_Input_traffic_speed_limi;/* '<S14>/BusConversion_InsertedFor_ACCS_DCSN_BUS _at_inport_0' */
  real32_T VfACCS_Input_linear_velocity_EG;/* '<S14>/BusConversion_InsertedFor_ACCS_EGMO_BUS _at_inport_0' */
  real32_T VfACCS_Input_Obs_Rangerate_h0h0;/* '<S37>/Switch' */
  real32_T VfACCS_Input_Obs_Range_n5rr;/* '<S37>/Switch' */
  real32_T VfACCS_Input_LaneMkL_c2_MPFU;/* '<S10>/LaneMark' */
  real32_T VfACCS_Input_LaneMkL_c3_MPFU;/* '<S10>/LaneMark' */
  real32_T VfACCS_Input_LaneMkR_c0_MPFU;/* '<S10>/LaneMark' */
  real32_T VfACCS_Input_LaneMkR_c1_MPFU;/* '<S10>/LaneMark' */
  real32_T VfACCS_Input_LaneMkR_c2_MPFU;/* '<S10>/LaneMark' */
  real32_T VfACCS_Input_LaneMkR_c3_MPFU;/* '<S10>/LaneMark' */
  real32_T VfACCS_Input_Lane_width_MPFU;/* '<S10>/LaneInfo' */
  real32_T VfACCS_Input_Lane_length_MPFU;/* '<S10>/LaneInfo' */
  real32_T VfACCS_Input_Yawrate_EGMO;  /* '<S9>/Signal Conversion2' */
  real32_T VfACCS_Input_linear_Acceleratio;/* '<S9>/Signal Conversion3' */
  real32_T VfACCS_Input_linear_Accele_dcwi;/* '<S9>/Signal Conversion8' */
  real32_T VfACCS_Input_linear_Accele_p235;/* '<S14>/BusConversion_InsertedFor_ACCS_EGMO_BUS _at_inport_0' */
  real32_T VfACCS_Input_EgoPitch_EGMO_av3q;/* '<S14>/BusConversion_InsertedFor_ACCS_EGMO_BUS _at_inport_0' */
  real32_T VfACCS_RangeErrLim_CIPV;    /* '<S18>/Switch' */
  real32_T CalDriverSetSpeed;          /* '<S34>/Switch3' */
  real32_T VfACCS_RangeErrlim_SIPV;    /* '<S18>/Switch1' */
  real32_T Product_cjbq;               /* '<S132>/Product' */
  real32_T Switch;                     /* '<S110>/Switch' */
  uint32_T SignalConversion2;          /* '<S35>/Signal Conversion2' */
  uint32_T VfACCS_Input_EGMOTimeStamp_low;/* '<S9>/Signal Conversion10' */
  int8_T VfACCS_Input_LaneMkL_Type_MPFU;/* '<S10>/LaneMark' */
  int8_T VeACCS_Input_LaneMkL_color_MPFU;/* '<S10>/LaneMark' */
  int8_T VeACCS_Input_LaneMkR_color_MPFU;/* '<S10>/LaneMark' */
  int8_T VeACCS_RoadType_MPFU;         /* '<S10>/LaneInfo' */
  int8_T VfACCS_Input_Lane_type_MPFU;  /* '<S10>/LaneInfo' */
  int8_T VeACCS_Input_Lane_turntype_MPFU;/* '<S10>/LaneInfo' */
  int8_T VeACCS_Input_Lane_direction_MPF;/* '<S10>/LaneInfo' */
  uint8_T VfACCS_Input_LaneMkL_quality_MP;/* '<S10>/LaneMark' */
  uint8_T VfACCS_Input_LaneMkR_quality_MP;/* '<S10>/LaneMark' */
  uint8_T VfACCS_Input_Lane_speed_limit_M;/* '<S10>/LaneInfo' */
  uint8_T VfACCS_Input_Lane_minspeed_limi;/* '<S10>/LaneInfo' */
  uint8_T VeACCS_Input_autodrive_activate;/* '<S14>/BusConversion_InsertedFor_ACCS_DCSN_BUS _at_inport_0' */
  uint8_T VeACCS_Input_Gear_TCU;       /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  boolean_T Switch6[2];                /* '<S150>/Switch6' */
  boolean_T VbACCS_InformDriverPressResumeE;/* '<S138>/DtrmnACCS_RunStatusTransfer' */
  boolean_T VbACCS_InformDriverPressGasPeda;/* '<S138>/DtrmnACCS_RunStatusTransfer' */
  boolean_T RangeFlickerObs;           /* '<S47>/Chart' */
  boolean_T VbACCS_Input_Obs_CIPVR_valid;/* '<S35>/DtrmnACCS_ObstacleExtraction' */
  boolean_T VbACCS_Input_Obs_CIPVL_valid;/* '<S35>/DtrmnACCS_ObstacleExtraction' */
  boolean_T VbACCS_Input_Obs_F_valid;  /* '<S35>/DtrmnACCS_ObstacleExtraction' */
  boolean_T VbACCS_Input_Obs_L_valid;  /* '<S35>/DtrmnACCS_ObstacleExtraction' */
  boolean_T is_valid;                  /* '<S10>/BusConversion_InsertedFor_ACCS_MPFU_BUS_at_inport_0' */
  boolean_T VbACCS_Input_LaneMkL_MPFU_valid;/* '<S10>/LaneMark' */
  boolean_T VbACCS_Input_LaneMkR_MPFU_valid;/* '<S10>/LaneMark' */
  boolean_T VbACCS_Lane_MPFU_valid;    /* '<S10>/LaneInfo' */
  boolean_T VbACCS_Input_resume_DCSN;  /* '<S8>/Signal Conversion13' */
  boolean_T VbACCS_Input_inlane_nudge_reque;/* '<S8>/Signal Conversion8' */
  boolean_T UnitDelay1;                /* '<S4>/Unit Delay1' */
  boolean_T SignalConversion;          /* '<S148>/Signal Conversion' */
  boolean_T LogicalOperator;           /* '<S14>/Logical Operator' */
  boolean_T VbACCS_Input_NoSpdLimit_mvju;/* '<S14>/BusConversion_InsertedFor_ACCS_DCSN_BUS _at_inport_0' */
  boolean_T VbACCS_Input_stop_request__d13v;/* '<S14>/BusConversion_InsertedFor_ACCS_DCSN_BUS _at_inport_0' */
  boolean_T SignalConversion1;         /* '<S18>/Signal Conversion1' */
  boolean_T VbACCS_Input_Obs_R_valid;  /* '<S35>/DtrmnACCS_ObstacleExtraction' */
  boolean_T VbACCS_Input_DriverPresent;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  boolean_T Ego_LimitCondition;        /* '<S34>/Logical Operator1' */
  boolean_T Switch4;                   /* '<S16>/Switch4' */
  boolean_T SignalConversion1_dk4z;    /* '<S148>/Signal Conversion1' */
  boolean_T SignalConversion_a213;     /* '<S18>/Signal Conversion' */
  EnumDCSN_driving_direction VfACCS_Input_inlane_nudge_side_;/* '<S8>/Signal Conversion9' */
  EnumACCS_StandbyType UnitDelay1_e3kh;/* '<S16>/Unit Delay1' */
  EnumACCS_StandbyType VeACCS_EnterStandbyType_hvif;/* '<S138>/DtrmnACCS_RunStatusTransfer' */
  EnumACCS_StandbyType UnitDelay1_iozd;/* '<S137>/Unit Delay1' */
  EnumACCS_Mode UnitDelay2;            /* '<S137>/Unit Delay2' */
  EnumACCS_RunStatus VeACCS_RunStatus_nlqu;/* '<S138>/DtrmnACCS_RunStatusTransfer' */
  EnumACCS_RunStatus UnitDelay;        /* '<S138>/Unit Delay' */
  EnumACCS_StatusTransferType VeACCS_StatusTransferType_git0;/* '<S138>/DtrmnACCS_RunStatusTransfer' */
  EnumACCS_FaultState Merge;           /* '<S136>/Merge' */
}
B_ACCS_subsystem_integrated_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
  real_T UnitDelay_DSTATE;             /* '<S151>/Unit Delay' */
  real_T UnitDelay_DSTATE_iiqj;        /* '<S152>/Unit Delay' */
  real_T UnitDelay_DSTATE_hso2;        /* '<S154>/Unit Delay' */
  real_T UnitDelay_DSTATE_hgyz;        /* '<S153>/Unit Delay' */
  real_T UnitDelay_DSTATE_gzqw;        /* '<S57>/Unit Delay' */
  real_T Delay12_DSTATE;               /* '<S56>/Delay12' */
  real_T ResumeSwitchPressTimer;       /* '<S155>/DtrmnACCS_WhetherPressResume' */
  real_T GasPedalPressTimer;           /* '<S155>/DtrmnACCS_WhetherPressGasPedal' */
  real32_T UnitDelay_DSTATE_n0sm;      /* '<S4>/Unit Delay' */
  real32_T UnitDelay2_DSTATE;          /* '<S4>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE;          /* '<S138>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_pniz;      /* '<S108>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_mixm;     /* '<S103>/Unit Delay1' */
  real32_T Delay_DSTATE;               /* '<S14>/Delay' */
  real32_T UnitDelay_DSTATE_mdjq;      /* '<S44>/Unit Delay' */
  real32_T UnitDelay_DSTATE_oamq;      /* '<S52>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_g15n;     /* '<S44>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_gzk1;      /* '<S51>/Unit Delay' */
  real32_T Delay_DSTATE_ml05;          /* '<S44>/Delay' */
  real32_T UnitDelay2_DSTATE_a0sb;     /* '<S44>/Unit Delay2' */
  real32_T UnitDelay_DSTATE_jw3u;      /* '<S50>/Unit Delay' */
  real32_T UnitDelay2_DSTATE_ihdw;     /* '<S67>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE_iqun;     /* '<S67>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_mfeb;      /* '<S67>/Unit Delay' */
  real32_T UnitDelay_DSTATE_kvt4;      /* '<S66>/Unit Delay' */
  real32_T UnitDelay_DSTATE_kvni;      /* '<S53>/Unit Delay' */
  real32_T UnitDelay2_DSTATE_akoi;     /* '<S60>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE_perp;     /* '<S60>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_k1rh;      /* '<S60>/Unit Delay' */
  real32_T Delay1_DSTATE;              /* '<S56>/Delay1' */
  real32_T UnitDelay_DSTATE_c2bu;      /* '<S54>/Unit Delay' */
  real32_T Delay2_DSTATE;              /* '<S56>/Delay2' */
  real32_T Delay3_DSTATE;              /* '<S56>/Delay3' */
  real32_T Delay10_DSTATE[10];         /* '<S56>/Delay10' */
  real32_T Delay7_DSTATE;              /* '<S56>/Delay7' */
  real32_T UnitDelay_DSTATE_obhi;      /* '<S56>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_pkqb;     /* '<S56>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE_ewh0;     /* '<S56>/Unit Delay2' */
  real32_T Delay11_DSTATE;             /* '<S46>/Delay11' */
  real32_T Delay1_DSTATE_jitl;         /* '<S47>/Delay1' */
  real32_T UnitDelay2_DSTATE_pkvt;     /* '<S64>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE_lu5x;     /* '<S64>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_mi5a;      /* '<S64>/Unit Delay' */
  real32_T UnitDelay2_DSTATE_dtcn;     /* '<S61>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE_ffnd;     /* '<S61>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_gu2l;      /* '<S61>/Unit Delay' */
  real32_T UnitDelay2_DSTATE_lrqq;     /* '<S62>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE_jbin;     /* '<S62>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_ckgq;      /* '<S62>/Unit Delay' */
  real32_T UnitDelay2_DSTATE_opog;     /* '<S63>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE_pq2g;     /* '<S63>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_pimc;      /* '<S63>/Unit Delay' */
  real32_T UnitDelay2_DSTATE_eatc;     /* '<S65>/Unit Delay2' */
  real32_T UnitDelay1_DSTATE_b45d;     /* '<S65>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_nqfg;      /* '<S65>/Unit Delay' */
  real32_T UnitDelay_DSTATE_nten;      /* '<S68>/Unit Delay' */
  real32_T UnitDelay_DSTATE_kec2;      /* '<S72>/Unit Delay' */
  real32_T UnitDelay_DSTATE_g3bx;      /* '<S71>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_gsho;     /* '<S68>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE_pzjs;     /* '<S68>/Unit Delay2' */
  real32_T UnitDelay_DSTATE_hcyq;      /* '<S70>/Unit Delay' */
  real32_T UnitDelay_DSTATE_lhxk;      /* '<S79>/Unit Delay' */
  real32_T UnitDelay_DSTATE_dwri;      /* '<S75>/Unit Delay' */
  real32_T UnitDelay_DSTATE_p00p;      /* '<S78>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_ehwx;     /* '<S75>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE_byd2;     /* '<S75>/Unit Delay2' */
  real32_T UnitDelay_DSTATE_cqqi;      /* '<S77>/Unit Delay' */
  real32_T UnitDelay_DSTATE_an2b;      /* '<S84>/Unit Delay' */
  real32_T UnitDelay_DSTATE_bmp0;      /* '<S86>/Unit Delay' */
  real32_T UnitDelay_DSTATE_a5fv;      /* '<S82>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ar1y;      /* '<S85>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_fbvr;     /* '<S82>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE_inkz;     /* '<S82>/Unit Delay2' */
  real32_T UnitDelay_DSTATE_aqya;      /* '<S87>/Unit Delay' */
  real32_T UnitDelay_DSTATE_juxr;      /* '<S73>/Unit Delay' */
  real32_T UnitDelay_DSTATE_f1jp;      /* '<S80>/Unit Delay' */
  real32_T UnitDelay_DSTATE_e0dr;      /* '<S81>/Unit Delay' */
  real32_T UnitDelay_DSTATE_ht1h;      /* '<S74>/Unit Delay' */
  real32_T UnitDelay_DSTATE_jszo;      /* '<S88>/Unit Delay' */
  real32_T UnitDelay_DSTATE_mpn1;      /* '<S89>/Unit Delay' */
  real32_T UnitDelay_DSTATE_fxt0;      /* '<S93>/Unit Delay' */
  real32_T UnitDelay_DSTATE_nmde;      /* '<S92>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_bzek;     /* '<S89>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE_noaa;     /* '<S89>/Unit Delay2' */
  real32_T UnitDelay_DSTATE_mskg;      /* '<S91>/Unit Delay' */
  real32_T UnitDelay_DSTATE_jk3b;      /* '<S94>/Unit Delay' */
  real32_T UnitDelay_DSTATE_la5j;      /* '<S95>/Unit Delay' */
  real32_T UnitDelay_DSTATE_otyz;      /* '<S96>/Unit Delay' */
  real32_T UnitDelay_DSTATE_oajl;      /* '<S100>/Unit Delay' */
  real32_T UnitDelay_DSTATE_bfjb;      /* '<S99>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_cstm;     /* '<S96>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE_ee1g;     /* '<S96>/Unit Delay2' */
  real32_T UnitDelay_DSTATE_ic5u;      /* '<S98>/Unit Delay' */
  real32_T UnitDelay_DSTATE_k5j0;      /* '<S101>/Unit Delay' */
  real32_T UnitDelay_DSTATE_bz5k;      /* '<S102>/Unit Delay' */
  real32_T UnitDelay_DSTATE_kdq3;      /* '<S34>/Unit Delay' */
  int32_T UnitDelay_DSTATE_ok4f;       /* '<S150>/Unit Delay' */
  int32_T UnitDelay_DSTATE_o4mr;       /* '<S33>/Unit Delay' */
  int32_T UnitDelay2_DSTATE_c5z1;      /* '<S33>/Unit Delay2' */
  int32_T UnitDelay1_DSTATE_fi04;      /* '<S38>/Unit Delay1' */
  int32_T UnitDelay_DSTATE_mjdv;       /* '<S38>/Unit Delay' */
  int32_T UnitDelay3_DSTATE_cdwe;      /* '<S44>/Unit Delay3' */
  int32_T Delay_DSTATE_kclz;           /* '<S56>/Delay' */
  int32_T Delay8_DSTATE;               /* '<S56>/Delay8' */
  int32_T Delay9_DSTATE;               /* '<S56>/Delay9' */
  int32_T Delay_DSTATE_jbar;           /* '<S47>/Delay' */
  real32_T VfACCS_TempStopTimer;       /* '<S138>/DtrmnACCS_RunStatusTransfer' */
  real32_T VfACCS_LaunchLowSpdTimer;   /* '<S138>/DtrmnACCS_RunStatusTransfer' */
  real32_T VfACCS_LaunchStopTimer;     /* '<S138>/DtrmnACCS_RunStatusTransfer' */
  real32_T VfACCS_LaunchTimer;         /* '<S138>/DtrmnACCS_RunStatusTransfer' */
  int32_T LastFlickerObsID;            /* '<S47>/Chart' */
  uint16_T FlickerTimeCount;           /* '<S47>/Chart' */
  uint8_T UnitDelay1_DSTATE_hhs3;      /* '<S148>/Unit Delay1' */
  uint8_T UnitDelay1_DSTATE_d3rt;      /* '<S33>/Unit Delay1' */
  uint8_T UnitDelay4_DSTATE_jzbz;      /* '<S33>/Unit Delay4' */
  boolean_T UnitDelay1_DSTATE_dciv;    /* '<S4>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_adca;     /* '<S155>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_dtsz;     /* '<S148>/Unit Delay' */
  boolean_T UnitDelay6_DSTATE;         /* '<S111>/Unit Delay6' */
  boolean_T UnitDelay7_DSTATE;         /* '<S111>/Unit Delay7' */
  boolean_T Delay1_DSTATE_g2ma;        /* '<S14>/Delay1' */
  boolean_T UnitDelay2_DSTATE_exnj;    /* '<S66>/Unit Delay2' */
  boolean_T UnitDelay1_DSTATE_ians;    /* '<S66>/Unit Delay1' */
  boolean_T Delay10_DSTATE_iwrp;       /* '<S46>/Delay10' */
  boolean_T Delay5_DSTATE;             /* '<S56>/Delay5' */
  boolean_T Delay11_DSTATE_dnza;       /* '<S56>/Delay11' */
  boolean_T Delay4_DSTATE;             /* '<S56>/Delay4' */
  boolean_T Delay6_DSTATE;             /* '<S56>/Delay6' */
  boolean_T Delay13_DSTATE;            /* '<S56>/Delay13' */
  EnumACCS_StandbyType UnitDelay1_DSTATE_gmku;/* '<S16>/Unit Delay1' */
  EnumACCS_StandbyType UnitDelay1_DSTATE_cjbc;/* '<S137>/Unit Delay1' */
  EnumACCS_Mode UnitDelay2_DSTATE_nivv;/* '<S137>/Unit Delay2' */
  EnumACCS_RunStatus UnitDelay_DSTATE_d4k1;/* '<S16>/Unit Delay' */
  EnumACCS_RunStatus UnitDelay_DSTATE_ffzr;/* '<S138>/Unit Delay' */
  ACCS_CIPVChangedType Delay12_DSTATE_jlce;/* '<S46>/Delay12' */
  uint8_T is_active_c12_ACCS_subsystem_in;/* '<S155>/DtrmnACCS_WhetherPressResume' */
  uint8_T is_c12_ACCS_subsystem_integrate;/* '<S155>/DtrmnACCS_WhetherPressResume' */
  uint8_T is_active_c11_ACCS_subsystem_in;/* '<S155>/DtrmnACCS_WhetherPressGasPedal' */
  uint8_T is_c11_ACCS_subsystem_integrate;/* '<S155>/DtrmnACCS_WhetherPressGasPedal' */
  uint8_T is_active_c4_ACCS_subsystem_int;/* '<S138>/DtrmnACCS_RunStatusTransfer' */
  uint8_T is_c4_ACCS_subsystem_integrated;/* '<S138>/DtrmnACCS_RunStatusTransfer' */
  uint8_T is_ACCS_ModeAndRunStatus_on; /* '<S138>/DtrmnACCS_RunStatusTransfer' */
  uint8_T is_active_c1_ACCS_subsystem_int;/* '<S137>/DtrmnACCS_ModeStateTransfer' */
  uint8_T is_c1_ACCS_subsystem_integrated;/* '<S137>/DtrmnACCS_ModeStateTransfer' */
}
DW_ACCS_subsystem_integrated_T;

/* Invariant block signals (auto storage) */
typedef struct
{
  const real_T Gain1;                  /* '<S44>/Gain1' */
  const real_T Gain;                   /* '<S45>/Gain' */
  const real_T Gain2;                  /* '<S45>/Gain2' */
  const real_T Gain1_jjpg;             /* '<S68>/Gain1' */
  const real_T Gain1_k0gs;             /* '<S75>/Gain1' */
  const real_T Gain1_clwv;             /* '<S82>/Gain1' */
  const real_T Gain_mimv;              /* '<S83>/Gain' */
  const real_T Gain2_dadm;             /* '<S83>/Gain2' */
  const real_T Gain_pbdr;              /* '<S69>/Gain' */
  const real_T Gain2_eem0;             /* '<S69>/Gain2' */
  const real_T Gain_nrzt;              /* '<S76>/Gain' */
  const real_T Gain2_l1lb;             /* '<S76>/Gain2' */
  const real_T Gain1_i31r;             /* '<S89>/Gain1' */
  const real_T Gain_k0b0;              /* '<S90>/Gain' */
  const real_T Gain2_mzr0;             /* '<S90>/Gain2' */
  const real_T Gain1_jwej;             /* '<S96>/Gain1' */
  const real_T Gain_onru;              /* '<S97>/Gain' */
  const real_T Gain2_mok3;             /* '<S97>/Gain2' */
  const real32_T Sum2;                 /* '<S106>/Sum2' */
  const real32_T Constant;             /* '<S131>/Constant' */
  const real32_T Constant1;            /* '<S131>/Constant1' */
  const real32_T Constant2;            /* '<S131>/Constant2' */
  const real32_T Constant3;            /* '<S131>/Constant3' */
  const real32_T Constant4;            /* '<S131>/Constant4' */
  const real32_T Constant_fh1v;        /* '<S130>/Constant' */
  const real32_T Constant1_dxf1;       /* '<S130>/Constant1' */
  const real32_T Sum3;                 /* '<S105>/Sum3' */
  const real32_T Constant_g2bl;        /* '<S128>/Constant' */
  const real32_T Constant1_czcq;       /* '<S128>/Constant1' */
  const real32_T Constant_jk02;        /* '<S127>/Constant' */
  const real32_T Constant1_c0c2;       /* '<S127>/Constant1' */
  const real32_T Constant_gbpu;        /* '<S122>/Constant' */
  const real32_T Constant1_psdt;       /* '<S122>/Constant1' */
  const real32_T Constant2_eroc;       /* '<S122>/Constant2' */
  const real32_T Constant3_cllx;       /* '<S122>/Constant3' */
  const real32_T Constant_jgqb;        /* '<S121>/Constant' */
  const real32_T Sum1;                 /* '<S113>/Sum1' */
  const real32_T Sum2_mads;            /* '<S113>/Sum2' */
  const real32_T Constant_cylc;        /* '<S117>/Constant' */
  const real32_T Constant_nmrj;        /* '<S116>/Constant' */
  const real32_T Constant1_ew5j;       /* '<S116>/Constant1' */
  const real32_T Constant2_dgcl;       /* '<S116>/Constant2' */
  const real32_T Constant3_e0ps;       /* '<S116>/Constant3' */
  const real32_T Constant_pe1x;        /* '<S115>/Constant' */
  const real32_T VfACCS_Input_MaxTorq_POWER;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VfACCS_Input_NetTorq_POWER;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VfACCS_Input_TorqMinActSpd_;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VfCCS_Input_TorqMaxActSpd_P;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VfACCS_Input_DriverDesiredT;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VeACCS_Input_WiperStatus_BC;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VfACCS_Input_SteringWhel_Ag;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VfACCS_Input_SteringWhel_To;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VeACCS_Input_ABSStatus_ESP;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VeACCS_Input_AutoHoldSt_ESP;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VfACCS_Input_FL_WheelSped_E;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VfACCS_Input_RL_WheelSped_E;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VfACCS_Input_RR_WheelSped_E;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VfACCS_Input_Speed_Set_HMI;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VfACCS_Input_YawRate_ESP;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T VeACCS_Input_Range_Set_HMI;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const real32_T Constant11;           /* '<S7>/Constant11' */
  const real32_T Constant21;           /* '<S7>/Constant21' */
  const real32_T Constant22;           /* '<S7>/Constant22' */
  const real32_T Constant30;           /* '<S7>/Constant30' */
  const real32_T Constant31;           /* '<S7>/Constant31' */
  const real32_T Constant32;           /* '<S7>/Constant32' */
  const real32_T Constant33;           /* '<S7>/Constant33' */
  const real32_T Constant34;           /* '<S7>/Constant34' */
  const real32_T Constant40;           /* '<S7>/Constant40' */
  const real32_T Constant45;           /* '<S7>/Constant45' */
  const real32_T Constant47;           /* '<S7>/Constant47' */
  const real32_T Constant48;           /* '<S7>/Constant48' */
  const real32_T Constant51;           /* '<S7>/Constant51' */
  const real32_T Constant55;           /* '<S7>/Constant55' */
  const real32_T Constant57;           /* '<S7>/Constant57' */
  const real32_T Constant61;           /* '<S7>/Constant61' */
  const uint8_T VeACCS_Input_DrivermodeDisa;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const uint8_T Constant29;            /* '<S7>/Constant29' */
  const boolean_T LogicalOperator;     /* '<S37>/Logical Operator' */
  const boolean_T VbACCS_Input_BrakePedal_POW;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_Torq_POWER_Val;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_PedalOverride_;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_Ctrl_Enable_HM;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_Response_Statu;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VeACCS_Input_TurnLightState;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_TurnLightState;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_Ctrl_Cancle_HM;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_VehiceSped_ESP;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_FL_WheelSped_E;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_FR_WheelSped_E;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_FR_WheelS_eczd;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_RL_WheelSped_E;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_RR_WheelSped_E;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VfACCS_Input_Grade_ESP;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_Grade_ESP_Vali;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_YawRate_ESP_Va;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_Gear_TCU_Valid;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_PhyGasPedal_PO;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_ActGasPedal_PO;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T VbACCS_Input_ActGasPed_ajr0;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0' */
  const boolean_T LogicalOperator3;    /* '<S34>/Logical Operator3' */
  const boolean_T LogicalOperator2;    /* '<S34>/Logical Operator2' */
  const boolean_T LogicalOperator4;    /* '<S34>/Logical Operator4' */
  const boolean_T Constant19;          /* '<S7>/Constant19' */
  const boolean_T Constant20;          /* '<S7>/Constant20' */
  const boolean_T Constant23;          /* '<S7>/Constant23' */
  const boolean_T Constant25;          /* '<S7>/Constant25' */
  const boolean_T Constant26;          /* '<S7>/Constant26' */
  const boolean_T Constant27;          /* '<S7>/Constant27' */
  const boolean_T Constant35;          /* '<S7>/Constant35' */
  const boolean_T Constant36;          /* '<S7>/Constant36' */
  const boolean_T Constant37;          /* '<S7>/Constant37' */
  const boolean_T Constant38;          /* '<S7>/Constant38' */
  const boolean_T Constant39;          /* '<S7>/Constant39' */
  const boolean_T Constant50;          /* '<S7>/Constant50' */
  const boolean_T Constant52;          /* '<S7>/Constant52' */
  const boolean_T Constant53;          /* '<S7>/Constant53' */
  const boolean_T Constant54;          /* '<S7>/Constant54' */
  const boolean_T Constant56;          /* '<S7>/Constant56' */
  const boolean_T Constant58;          /* '<S7>/Constant58' */
  const boolean_T Constant59;          /* '<S7>/Constant59' */
  const boolean_T Constant60;          /* '<S7>/Constant60' */
  const boolean_T Constant62;          /* '<S7>/Constant62' */
  const boolean_T Constant64;          /* '<S7>/Constant64' */
}
ConstB_ACCS_subsystem_integra_T;

/* Constant parameters (auto storage) */
typedef struct
{
  /* Computed Parameter: KaACCS_t_TimeGapFrmDriver_bp01D
   * Referenced by: '<S34>/KaACCS_t_TimeGapFrmDriver'
   */
  real32_T KaACCS_t_TimeGapFrmDriver_bp01D[4];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl'
   *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl1'
   */
  uint32_T pooled17[2];

  /* Computed Parameter: KtACCS_d_CIPVTargtRange_maxInde
   * Referenced by: '<S34>/KtACCS_d_CIPVTargtRange'
   */
  uint32_T KtACCS_d_CIPVTargtRange_maxInde[2];

  /* Computed Parameter: KtACCS_r_DCSNStopDistanceGain_m
   * Referenced by: '<S103>/KtACCS_r_DCSNStopDistanceGain '
   */
  uint32_T KtACCS_r_DCSNStopDistanceGain_m[2];

  /* Computed Parameter: KtACCS_r_DCSNStopSpdGain_maxInd
   * Referenced by: '<S103>/KtACCS_r_DCSNStopSpdGain'
   */
  uint32_T KtACCS_r_DCSNStopSpdGain_maxInd[2];

  /* Computed Parameter: KtACCS_r_TorqCtrlProp_maxIndex
   * Referenced by: '<S123>/KtACCS_r_TorqCtrlProp '
   */
  uint32_T KtACCS_r_TorqCtrlProp_maxIndex[2];

  /* Computed Parameter: KtACCS_Pct_AccelToGasPedal_maxI
   * Referenced by: '<S114>/KtACCS_Pct_AccelToGasPedal '
   */
  uint32_T KtACCS_Pct_AccelToGasPedal_maxI[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S129>/KtACCS_r_RangeCtrlPGain '
   *   '<S129>/KtACCS_r_RangeCtrlPGain 1'
   *   '<S132>/KtACCS_r_SpeedCtrlPGain'
   *   '<S132>/KtACCS_r_SpeedCtrlPGain1'
   */
  uint32_T pooled19[2];
}
ConstP_ACCS_subsystem_integra_T;

/* Block signals (auto storage) */
extern B_ACCS_subsystem_integrated_T ACCS_subsystem_integrated_B;

/* Block states (auto storage) */
extern DW_ACCS_subsystem_integrated_T ACCS_subsystem_integrated_DW;

/* External data declarations for dependent source files */
extern const ACCS_DataBus ACCS_subsystem_integrated_rtZACCS_DataBus;/* ACCS_DataBus ground */
extern const ConstB_ACCS_subsystem_integra_T ACCS_subsystem_integrate_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstP_ACCS_subsystem_integra_T ACCS_subsystem_integrate_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern ACCS_DataBus VsACCS_DataBus;    /* '<S5>/Bus Creator' */
extern real32_T VfACCS_Range_Actual;   /* '<S16>/Signal Conversion2'
                                        * The actual range
                                        */
extern real32_T VfACCS_CombinedSpeedLimit;/* '<S16>/Switch3'
                                           * Speed limit,consider with road and driver set
                                           */
extern real32_T VfACCS_StopTimer;      /* '<S138>/DtrmnACCS_RunStatusTransfer'
                                        * If enter stop model, this timer will increase
                                        */
extern real32_T VfACCS_SpdErrLim_CIPV; /* '<S106>/max'
                                        * The speed error for speed PID control
                                        */
extern real32_T VfACCS_DrsdAccelFrmRngSped;/* '<S106>/Switch'
                                            * The acceleration considers with range and speed error
                                            */
extern real32_T VfACCS_RangCtrCL_CIPV; /* '<S105>/Signal Conversion'
                                        * CIPV object range closed loop out
                                        */
extern real32_T VfACCS_Lon_Torq_Req;   /* '<S114>/Sum3'
                                        * The ACCS final output torq(%)
                                        */
extern real32_T VfACCS_Lon_Accleration;/* '<S113>/Sum3'
                                        * The ACCS final output acceleration
                                        */
extern real32_T VfACCS_DCSNStopAccel;  /* '<S103>/Sum1'
                                        * The acceleration is from DCSN stop requirement
                                        */
extern real32_T VfACCS_DrsdAccelWithDCSN;/* '<S103>/Switch3'
                                          * The acceleration consider with DCSN stop requirement
                                          */
extern real32_T VfACCS_DrsdAccelWithPitch;/* '<S103>/Add'
                                           * Before override desired acceleraton
                                           */
extern real32_T VfACCS_TargetDrsdLonAccel;/* '<S109>/Sum'
                                           * Target desired acceleration
                                           */
extern real32_T VfACCS_FinalDrsdAcceleration_old;/* '<S103>/Unit Delay1'
                                                  * Final desired acceleration pre loop value
                                                  */
extern real32_T VfACCS_FinalDrsdAcceleration;/* '<S103>/Switch4'
                                              * Finale desired acceleration
                                              */
extern real32_T VfACCS_Acceleartion_RampUpStep;/* '<S111>/MATLAB Function'
                                                * Desired acceleration ramp up step
                                                */
extern real32_T VfACCS_Acceleartion_RampDownStep;/* '<S111>/MATLAB Function'
                                                  * Desired acceleration ramp down step
                                                  */
extern real32_T VfACCS_LaunchToSpdRampTimer;/* '<S111>/MATLAB Function'
                                             * As from Launch to Speed control, this timer will increase.As this timer smaller than KfACCS_t_LaunchToSpdRampTimerThrsh,use KfACCS_a_LaunchToSpdRampUpStep or KfACCS_a_LaunchToSpdRampDownStep
                                             */
extern real32_T VfACCS_LaunchToFollowRampTimer;/* '<S111>/MATLAB Function'
                                                * As from launch to following control, this timer will increase.As this timer smaller than KfACCS_t_LaunchToFollowRampTimerThrsh,use KfACCS_a_LaunchToFollowRampUpStep or KfACCS_a_LaunchToFollowRampDownStep
                                                */
extern real32_T VfACCS_SpeedToFollowRampTimer;/* '<S111>/MATLAB Function'
                                               * As from Speed to following control, this timer will increase.As this timer smaller than KfACCS_t_SpeedToFollowRampTimerThrsh,use KfACCS_a_SpeedToFollowRampUpStep or KfACCS_a_SpeedToFollowRampDownStep
                                               */
extern real32_T VfACCS_FollowToSpdRampTimer;/* '<S111>/MATLAB Function'
                                             * As from following to speed control, this timer will increase.As this timer smaller than KfACCS_t_FollowToSpdRampTimerThrsh,use KfACCS_a_FollowToSpdRampUpStep or KfACCS_a_FollowToSpdRampDownStep
                                             */
extern real32_T VfACCS_Obs_Lat_V_OBFU; /* '<S38>/Add17'
                                        * obstacle's lateral speed before process
                                        */
extern real32_T VfACCS_Obs_Long_V_OBFU;/* '<S38>/Add18'
                                        * obstacle's longitudinal speed before process
                                        */
extern real32_T VfACCS_Obs_Long_A_OBFU;/* '<S38>/Add19'
                                        * obstacle's longitudinal acceleration before process
                                        */
extern real32_T VfACCS_Obs_Lat_A_OBFU; /* '<S38>/Add20'
                                        * obstacle's lateral acceleration before process
                                        */
extern real32_T VfACCS_Obs_Long_OBFU;  /* '<S38>/Signal Conversion'
                                        * obstacle's longitudinal distacne before process
                                        */
extern real32_T VfACCS_Obs_Lat_OBFU;   /* '<S38>/Signal Conversion1'
                                        * obstacle's lateral distance before process
                                        */
extern real32_T VfACCS_Input_Obs_LinearAcc;/* '<S48>/Switch6'
                                            * CIPV object linear speed
                                            */
extern real32_T VfACCS_Input_Obs_Range;/* '<S48>/Switch'
                                        * CIPV object range
                                        */
extern real32_T VfACCS_Input_Obs_Rangerate;/* '<S48>/Switch4'
                                            * CIPV object range rate
                                            */
extern real32_T VfACCS_Input_Obs_LatDis;/* '<S48>/Switch1'
                                         * CIPV object lat distance
                                         */
extern real32_T VfACCS_Input_Obs_Long_VFiltered;/* '<S48>/Switch2'
                                                 * CIPV object long velocity
                                                 */
extern real32_T VfACCS_Input_Obs_Lat_VFiltered;/* '<S48>/Switch3'
                                                * CIPV object lat speed
                                                */
extern real32_T VfACCS_Input_Obs_LinearVelocity;/* '<S48>/Switch5'
                                                 * CIPV object linear speed
                                                 */
extern real32_T VfACCS_DriverTargetRange;/* '<S34>/MinMax1'
                                          * Driver target following range
                                          */
extern real32_T VfACCS_FinalSpeedLimit;/* '<S19>/CombinedSpeedLimit'
                                        * Final speed limit, consider with road limit
                                        */
extern real32_T VfACCS_FeedForwardAccel;/* '<S18>/Merge1'
                                         * Acceleration open iterm
                                         */
extern real32_T VfACCS_OpenAccel_ForDCSNStop;/* '<S18>/Switch2'
                                              * This is open acceleration for DCSN stop
                                              */
extern real32_T VfACCS_VehSpeed_Tar;   /* '<S17>/Saturation'
                                        * The target vehicle speed
                                        */
extern real32_T VfACCS_DeltaSped_EGMOAndCan;/* '<S9>/Subtract'
                                             * Speed error between Can and EGMO model
                                             */
extern real32_T VfACCS_Input_linear_velocity_EGMO;/* '<S9>/Switch'
                                                   * Ego linear velocith from EGMO mode
                                                   */
extern real32_T VfACCS_Input_EgoPitch_EGMO;/* '<S9>/Switch3'
                                            * Ego pitch from EGMO model
                                            */
extern real32_T VfACCS_Input_longvelocity_EGMO;/* '<S9>/Signal Conversion5'
                                                * Ego vehilce V_x
                                                */
extern real32_T VfACCS_Input_latvelocity_EGMO;/* '<S9>/Signal Conversion6'
                                               * Ego vehicle V_y
                                               */
extern real32_T VfACCS_Input_linear_Acceleration_EGMO;/* '<S9>/Signal Conversion7'
                                                       * Ego linear acceleration from EGMO model
                                                       */
extern real32_T VfACCS_Input_stop_s_distance_DCSN;/* '<S8>/Switch2'
                                                   * Stop distance from DCSN model
                                                   */
extern real32_T VfACCS_Input_traffic_speed_limit_DCSN;/* '<S8>/Switch1'
                                                       * Speed limit from DCSM model
                                                       */
extern real32_T VfACCS_Input_PhyGasPedal_POWER;/* '<S7>/Switch6'
                                                * Observe the opening of the accelerator pedal
                                                */
extern int32_T VfACCS_Input_OBFUTimeStamp_high;/* '<S35>/Signal Conversion1'
                                                * OBFU timestamp high


                                                */
extern int32_T VfACCS_Input_Obs_ID;    /* '<S48>/Signal Conversion2'
                                        * CIPV object id
                                        */
extern int32_T VfACCS_Input_EGMOTimeStamp_high;/* '<S9>/Signal Conversion9'
                                                * EGMO timestamp high

                                                */
extern uint16_T VfACCS_Input_Obs_Num;  /* '<S35>/Signal Conversion'
                                        * Object num from OBFU
                                        */
extern int8_T VeACCS_CIPVobsType;      /* '<S48>/Signal Conversion4'
                                        * UNKNOWN=0;
                                          PEDESTRIAN=1;
                                          BICYCLE=2;
                                          MOTORCYCLE = 3;
                                          VEHICLE=4;
                                          BUS=5;
                                          TRUCK=6;
                                          ANIMAL =7;
                                          TRAFFIC_CONE = 8;
                                          FENCES = 9;
                                        */
extern boolean_T VbACCS_AEB_Active;    /* '<S16>/Constant11'
                                        * AEB active
                                        */
extern boolean_T VbACCS_MainSwitch;    /* '<S16>/Logical Operator2'
                                        * ACC main switch is ture
                                        */
extern boolean_T VbACCS_InformDriverPressResume;/* '<S16>/Signal Conversion'
                                                 * Ture:Driver need press resume switch to active ACCS
                                                 */
extern boolean_T VbACCS_InformDriverPressGasPedal;/* '<S16>/Signal Conversion1'
                                                   * Ture:Driver need press gas pedal to active ACCS
                                                   */
extern boolean_T VbACCS_SpdToLowSpeedCtr;/* '<S150>/Logical Operator1'
                                          * The condtion:From speed to low speed control
                                          */
extern boolean_T VbACCS_HasCIPV_Object;/* '<S150>/CIPV_object_valid'
                                        * Ture: There is following target object
                                        */
extern boolean_T VbACCS_LowSpdToSpeedCtr;/* '<S150>/Logical Operator2'
                                          * The condition:From low speed to speed control
                                          */
extern boolean_T VbACCS_FollowingToSpeedCtrl;/* '<S150>/Logical Operator5'
                                              * The condition: from following control to speed control
                                              */
extern boolean_T VbACCS_SpeedToFollowingCtr;/* '<S150>/Logical Operator'
                                             * The condition:From speed to following control
                                             */
extern boolean_T VbACCS_LowSpdToTempStop;/* '<S150>/Logical Operator10'
                                          * The condition:From low speed to temp stop
                                          */
extern boolean_T VbACCS_LowSpdToFollowingCtrl;/* '<S150>/Logical Operator8'
                                               * The condition:From low speed to following control
                                               */
extern boolean_T VbACCS_TempStopToLaunch;/* '<S150>/Logical Operator13'
                                          * The condition:From temp stop to launch
                                          */
extern boolean_T VbACCS_FollowingToLowSpdCtrl;/* '<S150>/Logical Operator6'
                                               * The condition: from following control to low speed control
                                               */
extern boolean_T VbACCS_StatusOnToSpeedCtrl;/* '<S150>/Logical Operator11'
                                             * The condition:From  status on to speed control
                                             */
extern boolean_T VbACCS_StatusOnToStop;/* '<S150>/Logical Operator12'
                                        * The condirion:From status on to Stop
                                        */
extern boolean_T VbACCS_EnterStandbyCommonCod;/* '<S150>/Logical Operator25'
                                               * Ture:enter standby common conditions meet
                                               */
extern boolean_T VbACCS_FromStopToStandby;/* '<S150>/Logical Operator26'
                                           * The condition: from Stop to Standby
                                           */
extern boolean_T VbACCS_FromLowSpeedToStandby;/* '<S150>/Logical Operator22'
                                               * The condition: from Low Speed control to Standby
                                               */
extern boolean_T VbACCS_FromLaunchToStandby;/* '<S150>/Logical Operator29'
                                             * The condition: from following control to Standby
                                             */
extern boolean_T VbACCS_FromFollowingCtrlToStandby;/* '<S150>/Logical Operator34'
                                                    * The condition: from following control to Standby
                                                    */
extern boolean_T VbACCS_FromSpeedCtrlToStandby;/* '<S150>/Logical Operator37'
                                                * The condition: from Speed control to Standby
                                                */
extern boolean_T VbACCS_EnterStopDueToCIP;/* '<S150>/Logical Operator32'
                                           * Enter stop mode due to obstacle
                                           */
extern boolean_T VbACCS_TempStpToStop; /* '<S138>/DtrmnACCS_RunStatusTransfer'
                                        * The condition: From temp stop to stop
                                        */
extern boolean_T VbACCS_StopToLaunch;  /* '<S138>/DtrmnACCS_RunStatusTransfer'
                                        * The condition:From stop to launch
                                        */
extern boolean_T VbACCS_LaunchToTempStop;/* '<S138>/DtrmnACCS_RunStatusTransfer'
                                          * The condition:From launch to temp stop
                                          */
extern boolean_T VbACCS_LaunchToSpeedCtrl;/* '<S138>/DtrmnACCS_RunStatusTransfer'
                                           * The condition:From launch to speed control
                                           */
extern boolean_T VbACCS_LaunchToLowSpd;/* '<S138>/DtrmnACCS_RunStatusTransfer'
                                        * The condition:From launch to low speed control
                                        */
extern boolean_T VbACCS_LaunchToFollowingCtrl;/* '<S138>/DtrmnACCS_RunStatusTransfer'
                                               * The condition:From launch to following control
                                               */
extern boolean_T VbACCS_ResumeSwitch;  /* '<S148>/Signal Conversion4'
                                        * Driver press resume switch
                                        */
extern boolean_T VbACCS_ResumeSwitchOld;/* '<S148>/Unit Delay'
                                         * The previous loop resume switch state
                                         */
extern boolean_T VbACCS_GearPositionIsD;/* '<S148>/Logical Operator7'
                                         * Gear position is D gear
                                         */
extern boolean_T VbACCS_SpeedOutRange; /* '<S148>/Logical Operator1'
                                        * Ego speed is out of ACCS enable range
                                        */
extern boolean_T VbACCS_DriverModeAllowACCS;/* '<S148>/Relational Operator32'
                                             * Under the current drive mode, can enable ACCS
                                             */
extern boolean_T VbACCS_DriverGasPedalOverride;/* '<S148>/Logical Operator8'
                                                * Driver gas pedal is bigger than ACC requirement
                                                */
extern boolean_T VbACCS_EgoLimit;      /* '<S148>/Signal Conversion3'
                                        * Ego vehicle has some features will limit ACCS
                                        */
extern boolean_T VbACCS_ExitStandbyCommonConds;/* '<S148>/Logical Operator4'
                                                * Exit stanby mode common conditions meet
                                                */
extern boolean_T VbACCS_ExitStandbyToOn;/* '<S148>/Logical Operator6'
                                         * Ture: Will exit standby to RunstatusOn
                                         */
extern boolean_T VbACCS_Lon_Torq_Req;  /* '<S113>/Logical Operator1'
                                        * Ture means set positve torqerequirement
                                        */
extern boolean_T VbACCS_Lon_Accleration_Req;/* '<S113>/Logical Operator3'
                                             * Only this flag is ture, the output acceleration is valid
                                             */
extern boolean_T VbACCS_EnableLaunchToSpdRamp;/* '<S111>/MATLAB Function'
                                               * Launch to Speed ramp enable
                                               */
extern boolean_T VbACCS_EnableLaunchToFollowRamp;/* '<S111>/MATLAB Function'
                                                  * Launch to follow ramp enable
                                                  */
extern boolean_T VbACCS_EnableSpeedToFollowRamp;/* '<S111>/MATLAB Function'
                                                 * Speed to follow ramp enable
                                                 */
extern boolean_T VbACCS_EnableFollowToSpeedRamp;/* '<S111>/MATLAB Function'
                                                 * Follow to speed ramp enable
                                                 */
extern boolean_T VbACCS_InputInfError; /* '<S33>/Logical Operator13'
                                        * This will be true if input information has error
                                        */
extern boolean_T VbACCS_Obs_validBeforeDelay;/* '<S48>/Logical Operator'
                                              * Obs valid before delay
                                              */
extern boolean_T VbACCS_Input_Obs_valid;/* '<S66>/Switch'
                                         * Has CIPV
                                         */
extern boolean_T VbACCS_CIPVObsRangeFlicker;/* '<S48>/Signal Conversion1'
                                             * This is the flag to show whether the obstacle's range is changing abnormaly
                                             */
extern boolean_T VbACCS_BrakePedalPress;/* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0'
                                         * Driver press brake pedal
                                         */
extern boolean_T VbACCS_EPB_Engaged;   /* '<S34>/BusConversion_InsertedFor_ACCS_EgoStatus_CAN_BUS_at_inport_0'
                                        * EPB engaged
                                        */
extern boolean_T VbACCS_DriverHasSetSpeed;/* '<S34>/Relational Operator1'
                                           * Driver has set speed for ACCS
                                           */
extern boolean_T VbACCS_NeedRespStopFrmDCSN;/* '<S18>/Logical Operator'
                                             * Ture: ACCS need response DCSN stop requirement
                                             */
extern boolean_T VbACCS_Input_stop_request_DCSN;/* '<S8>/Switch'
                                                 * Has Stop request from DCSN model
                                                 */
extern boolean_T VbACCS_Input_NoSpdLimit;/* '<S8>/Relational Operator'
                                          * If DCSN module speed limit reason is Nolimit, this flag will set true
                                          */
extern boolean_T VbACCS_Input_brake_ctrl_enable_DCSN;/* '<S8>/Signal Conversion1'
                                                      * Brake control enable from DCSN
                                                      */
extern boolean_T VbACCS_Input_acc_feature_enable_DCSN;/* '<S8>/Signal Conversion2'
                                                       * ACC ffeature control enable from DCSN
                                                       */
extern boolean_T VbACCS_Input_power_ctrl_enable_DCSN;/* '<S8>/Signal Conversion4'
                                                      * Power control enable from DCSN module
                                                      */
extern EnumACCS_StandbyType VeACCS_EnterStandbyType;/* '<S16>/Switch1'
                                                     * 0:NoEnterStandby
                                                       1:FromModeOffToStandby
                                                       2:FromSpeedCtrlToStandby
                                                       3:FromFollowingCtrlToStandby
                                                       4:FromLowSpeedToStandby
                                                       5:FromTempStopToStandby
                                                       6:FromStopToStandby
                                                       7:FromLaunchToStandby
                                                       8:FromFaultToStandby
                                                       9:DriverGasPedalOverride
                                                       10:PressCancelSwitch
                                                     */
extern EnumACCS_StandbyType VeACCS_EnterStandbyState;/* '<S137>/DtrmnACCS_ModeStateTransfer'
                                                      * 0:NoEnterStandby
                                                        1:FromModeOffToStandby
                                                        2:FromSpeedCtrlToStandby
                                                        3:FromFollowingCtrlToStandby
                                                        4:FromLowSpeedToStandby
                                                        5:FromTempStopToStandby
                                                        6:FromStopToStandby
                                                        7:FromLaunchToStandby
                                                        8:FromFaultToStandby
                                                        9:DriverGasPedalOverride
                                                        10:PressCancelSwitch
                                                      */
extern EnumACCS_Mode VeACCS_ModeState; /* '<S137>/DtrmnACCS_ModeStateTransfer'
                                        * 0:ACCS_mode_off
                                          1:ACCS_mode_on
                                          2:ACCS_mode_standby
                                          3:ACCS_mode_fault

                                        */
extern EnumACCS_RunStatus VeACCS_RunStatus;/* '<S16>/Switch'
                                            * 0:ACCS_status_off
                                              1:ACCS_status_on
                                              2:ACCS_status_Standby
                                              3:ACCS_status_SpeedCtrl
                                              4:ACCS_status_FollowingCtrl
                                              5:ACCS_status_TempStop
                                              6:ACCS_status_Stop
                                              7:ACCS_status_Launch
                                              8:ACCS_status_LowSpeed
                                              9:ACCS_status_Fault
                                            */
extern EnumACCS_RunStatus VeACCS_RunStatusFrmMode;/* '<S137>/DtrmnACCS_ModeStateTransfer'
                                                   * 0:ACCS_status_off
                                                     1:ACCS_status_on
                                                     2:ACCS_status_Standby
                                                     3:ACCS_status_SpeedCtrl
                                                     4:ACCS_status_FollowingCtrl
                                                     5:ACCS_status_TempStop
                                                     6:ACCS_status_Stop
                                                     7:ACCS_status_Launch
                                                     8:ACCS_status_LowSpeed
                                                     9:ACCS_status_Fault
                                                   */
extern EnumACCS_RunStatus VeACCS_RunStatusBeforeFault;/* '<S137>/DtrmnACCS_ModeStateTransfer'
                                                       * 0:ACCS_status_off
                                                         1:ACCS_status_on
                                                         2:ACCS_status_Standby
                                                         3:ACCS_status_SpeedCtrl
                                                         4:ACCS_status_FollowingCtrl
                                                         5:ACCS_status_TempStop
                                                         6:ACCS_status_Stop
                                                         7:ACCS_status_Launch
                                                         8:ACCS_status_LowSpeed
                                                         9:ACCS_status_Fault
                                                       */
extern ACCS_CIPVChangedType VeACCS_CIPVChangedType;/* '<S48>/Signal Conversion3'
                                                    * This is the signal to show the CIPV changed type
                                                    */
extern EnumACCS_StatusTransferType VeACCS_StatusTransferType;/* '<S16>/Switch5'
                                                              * 0:NoTransfer
                                                                1:FromOnToStop
                                                                2:FromOnToSpeedCtrl
                                                                3:FromSpeedToLowSpeed
                                                                4:FromSpeedToFollowing
                                                                5:FromLowSpeedToFollowing
                                                                6:FromLowSpeedToTempStop
                                                                7:FromLowSpeedToSpeed
                                                                8:FromTempStopToStop
                                                                9:FromTempStopToLaunch
                                                                10:FromStopToLaunch
                                                                11:FromLaunchToFollowingCtrl
                                                                12:FromLaunchToLowSpeed
                                                                13:FromLaunchToSpeedCtrl
                                                                14:FromLaunchToTempStop
                                                                15:FromFollowingToSpeedCtrl
                                                                16:FromFollowingToLowSpeed
                                                              */
extern EnumACCS_FaultState VeACCS_FaultState;/* '<S136>/Switch'
                                              * 0:NoEnterFault
                                                1:FromStatusOnToFault
                                                2:FromSpeedCtrlToFault
                                                3:FromFollowingCtrlToFault
                                                4:FromLowSpeedToFault
                                                5:FromTempStopToFault
                                                6:FromStopToFault
                                                7:FromLaunchToFault
                                                8:FromStandbyToFault
                                              */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T KfACCS_v_SpdMinForCloseDisappear;/* Variable: KfACCS_v_SpdMinForCloseDisappear
                                                * Referenced by: '<S56>/Constant24'
                                                * This minimum speed for selecting this type target
                                                */
extern real32_T KaACCS_t_TimeGapFrmDriver[4];/* Variable: KaACCS_t_TimeGapFrmDriver
                                              * Referenced by: '<S34>/KaACCS_t_TimeGapFrmDriver'
                                              * Time gap from driver
                                              */
extern real32_T KcACCS_ABSActvieCntDisableACCThrsh;/* Variable: KcACCS_ABSActvieCntDisableACCThrsh
                                                    * Referenced by: '<S34>/Constant10'
                                                    * ABS active timer is bigger than this calibration, ACCS will enter standby
                                                    */
extern real32_T KcACCS_DtrmFlickerThresh;/* Variable: KcACCS_DtrmFlickerThresh
                                          * Referenced by: '<S47>/Constant6'
                                          * Rnage flicker count thresh
                                          */
extern real32_T KfACCS_Ang_DtrmSelfChangeLane;/* Variable: KfACCS_Ang_DtrmSelfChangeLane
                                               * Referenced by: '<S56>/Constant15'
                                               * Thie is the steering angle to determine whether vehicle is changing lane
                                               */
extern real32_T KfACCS_M_StandardTorqForPercent;/* Variable: KfACCS_M_StandardTorqForPercent
                                                 * Referenced by: '<S114>/Constant2'
                                                 * This is standard torr for calculate percent
                                                 */
extern real32_T KfACCS_Pct_DriverPressGasPedalThrsh;/* Variable: KfACCS_Pct_DriverPressGasPedalThrsh
                                                     * Referenced by: '<S155>/DtrmnACCS_WhetherPressGasPedal'
                                                     * If the gas pedal is bigger than this calibration,determine driver preee the pedal
                                                     */
extern real32_T KfACCS_Pct_GasPedalOverrideThrsh;/* Variable: KfACCS_Pct_GasPedalOverrideThrsh
                                                  * Referenced by: '<S148>/Constant25'
                                                  * As KbACCS_DirectlyUsePedalToJudgeOverride=True,if gas pedal is bigger than this calibration, ACCS will enter pedal override standby status
                                                  */
extern real32_T KfACCS_Pct_VirtualGasPedal;/* Variable: KfACCS_Pct_VirtualGasPedal
                                            * Referenced by: '<S7>/Constant13'
                                            * This is only for test.As KbACCS_UseVirtualPedal=True, use this calibration as the Gas pedal
                                            */
extern real32_T KfACCS_a_AccelCmdDeadZone;/* Variable: KfACCS_a_AccelCmdDeadZone
                                           * Referenced by: '<S113>/Constant7'
                                           * When want to accelerate, the acceleration must bigger than this cal.
                                           */
extern real32_T KfACCS_a_BrakeCmdDeadZone;/* Variable: KfACCS_a_BrakeCmdDeadZone
                                           * Referenced by: '<S113>/Constant5'
                                           * When want to decelerate, the acceleration must bigger than this cal.
                                           */
extern real32_T KfACCS_a_FollowToSpdRampDownStep;/* Variable: KfACCS_a_FollowToSpdRampDownStep
                                                  * Referenced by: '<S111>/MATLAB Function'
                                                  * Ramp down step under VbACCS_EnableFollowToSpdRamp=True
                                                  */
extern real32_T KfACCS_a_FollowToSpdRampUpStep;/* Variable: KfACCS_a_FollowToSpdRampUpStep
                                                * Referenced by: '<S111>/MATLAB Function'
                                                * Ramp up step under VbACCS_EnableFollowToSpdRamp=True
                                                */
extern real32_T KfACCS_a_LaunchToFollowRampDownStep;/* Variable: KfACCS_a_LaunchToFollowRampDownStep
                                                     * Referenced by: '<S111>/MATLAB Function'
                                                     * Ramp down under VbACCS_EnableLaunchToFollowRamp=True
                                                     */
extern real32_T KfACCS_a_LaunchToFollowRampUpStep;/* Variable: KfACCS_a_LaunchToFollowRampUpStep
                                                   * Referenced by: '<S111>/MATLAB Function'
                                                   * Ramp up under VbACCS_EnableLaunchToFollowRamp=True
                                                   */
extern real32_T KfACCS_a_LaunchToSpdRampDownStep;/* Variable: KfACCS_a_LaunchToSpdRampDownStep
                                                  * Referenced by: '<S111>/MATLAB Function'
                                                  * Ramp down step under VbACCS_EnableLaunchToSpdRamp=True
                                                  */
extern real32_T KfACCS_a_LaunchToSpdRampUpStep;/* Variable: KfACCS_a_LaunchToSpdRampUpStep
                                                * Referenced by: '<S111>/MATLAB Function'
                                                * Ramp up step under VbACCS_EnableLaunchToSpdRamp=True
                                                */
extern real32_T KfACCS_a_LinearAcc_PreSet;/* Variable: KfACCS_a_LinearAcc_PreSet
                                           * Referenced by:
                                           *   '<S39>/Constant45'
                                           *   '<S40>/Constant45'
                                           *   '<S41>/Constant45'
                                           *   '<S42>/Constant45'
                                           *   '<S43>/Constant45'
                                           * when KbACCS_UseVirtualObject=true, object linearAcc is from this calibration
                                           */
extern real32_T KfACCS_a_LowSpdToTempStpAccelThrsh;/* Variable: KfACCS_a_LowSpdToTempStpAccelThrsh
                                                    * Referenced by: '<S150>/Constant31'
                                                    * If want from low speed to Temp stop, desired acceleration need bigger than thhi calibration
                                                    */
extern real32_T KfACCS_a_ObjectAccelUpdateThrsh;/* Variable: KfACCS_a_ObjectAccelUpdateThrsh
                                                 * Referenced by:
                                                 *   '<S44>/Constant47'
                                                 *   '<S68>/Constant47'
                                                 *   '<S75>/Constant47'
                                                 *   '<S82>/Constant47'
                                                 *   '<S89>/Constant47'
                                                 *   '<S96>/Constant47'
                                                 * Only object acceleration change is bigger than this calibration, set the new acceleration
                                                 */
extern real32_T KfACCS_a_OutAccelHiThrsh;/* Variable: KfACCS_a_OutAccelHiThrsh
                                          * Referenced by: '<S103>/Constant5'
                                          * The Max threshold for output acceleration
                                          */
extern real32_T KfACCS_a_OutAccelLoThrsh;/* Variable: KfACCS_a_OutAccelLoThrsh
                                          * Referenced by: '<S103>/Constant7'
                                          * The Min threshold for output acceleration
                                          */
extern real32_T KfACCS_a_SpeedToFollowRampDownStep;/* Variable: KfACCS_a_SpeedToFollowRampDownStep
                                                    * Referenced by: '<S111>/MATLAB Function'
                                                    * Ramp down under VbACCS_EnableSpeedToFollowRamp=True
                                                    */
extern real32_T KfACCS_a_SpeedToFollowRampUpStep;/* Variable: KfACCS_a_SpeedToFollowRampUpStep
                                                  * Referenced by: '<S111>/MATLAB Function'
                                                  * Ramp up under VbACCS_EnableSpeedToFollowRamp=True
                                                  */
extern real32_T KfACCS_a_StatusFollowAcceleRampDownStep;/* Variable: KfACCS_a_StatusFollowAcceleRampDownStep
                                                         * Referenced by: '<S111>/MATLAB Function'
                                                         * Acceleration Ramp down under Following control status
                                                         */
extern real32_T KfACCS_a_StatusFollowAcceleRampUpStep;/* Variable: KfACCS_a_StatusFollowAcceleRampUpStep
                                                       * Referenced by: '<S111>/MATLAB Function'
                                                       * Acceleration Ramp up under Following control status
                                                       */
extern real32_T KfACCS_a_StatusSpeedAcceleRampDownStep;/* Variable: KfACCS_a_StatusSpeedAcceleRampDownStep
                                                        * Referenced by: '<S111>/MATLAB Function'
                                                        * Ramp down step under Speed control status
                                                        */
extern real32_T KfACCS_a_StatusSpeedAcceleRampUpStep;/* Variable: KfACCS_a_StatusSpeedAcceleRampUpStep
                                                      * Referenced by: '<S111>/MATLAB Function'
                                                      * Ramp up step under Speed control status
                                                      */
extern real32_T KfACCS_a_TempStpToLaunchAccelThrsh;/* Variable: KfACCS_a_TempStpToLaunchAccelThrsh
                                                    * Referenced by: '<S150>/Constant29'
                                                    * If want to from temp stop to launch, the acceleration need bigger than this calibration
                                                    */
extern real32_T KfACCS_d_ChangedObsRangeLatDiff;/* Variable: KfACCS_d_ChangedObsRangeLatDiff
                                                 * Referenced by: '<S56>/Constant1'
                                                 * This is the lateral range difference to determine whether the target is a changed target
                                                 */
extern real32_T KfACCS_d_ChangedObsRangeLongDiff;/* Variable: KfACCS_d_ChangedObsRangeLongDiff
                                                  * Referenced by: '<S56>/Constant'
                                                  * This is the longitudinal range difference to determine whether the target is a changed target
                                                  */
extern real32_T KfACCS_d_ConsiderObsMaxLat;/* Variable: KfACCS_d_ConsiderObsMaxLat
                                            * Referenced by: '<S49>/Constant2'
                                            * If the vehicle's lateral distance is greater than this calibration, ACCS will not choose is as target
                                            */
extern real32_T KfACCS_d_CurvatureRadius_Max;/* Variable: KfACCS_d_CurvatureRadius_Max
                                              * Referenced by:
                                              *   '<S45>/Constant7'
                                              *   '<S45>/Constant9'
                                              *   '<S69>/Constant7'
                                              *   '<S69>/Constant9'
                                              *   '<S76>/Constant7'
                                              *   '<S76>/Constant9'
                                              *   '<S83>/Constant7'
                                              *   '<S83>/Constant9'
                                              *   '<S90>/Constant7'
                                              *   '<S90>/Constant9'
                                              *   '<S97>/Constant7'
                                              *   '<S97>/Constant9'
                                              * If curvature radius is bigger than this calibration, the road is set straight roade
                                              */
extern real32_T KfACCS_d_DisToLeadSur; /* Variable: KfACCS_d_DisToLeadSur
                                        * Referenced by:
                                        *   '<S45>/Constant8'
                                        *   '<S69>/Constant8'
                                        *   '<S76>/Constant8'
                                        *   '<S83>/Constant8'
                                        *   '<S90>/Constant8'
                                        *   '<S97>/Constant8'
                                        * The distance between the vehicle head and Rear axle center
                                        */
extern real32_T KfACCS_d_DisToSideSur; /* Variable: KfACCS_d_DisToSideSur
                                        * Referenced by:
                                        *   '<S45>/Constant10'
                                        *   '<S69>/Constant10'
                                        *   '<S76>/Constant10'
                                        *   '<S83>/Constant10'
                                        *   '<S90>/Constant10'
                                        *   '<S97>/Constant10'
                                        * The distance between the vehicle side and Rear axle center
                                        */
extern real32_T KfACCS_d_FlickerRangeDiffLimit;/* Variable: KfACCS_d_FlickerRangeDiffLimit
                                                * Referenced by: '<S47>/Constant8'
                                                * This is the range rate difference limit of last loop for detecting range flicker function
                                                */
extern real32_T KfACCS_d_FlickerRangeLatLimit;/* Variable: KfACCS_d_FlickerRangeLatLimit
                                               * Referenced by: '<S47>/Constant1'
                                               * This is the lateral range limit for detecting range flicker function
                                               */
extern real32_T KfACCS_d_FlickerRangeLongLimit;/* Variable: KfACCS_d_FlickerRangeLongLimit
                                                * Referenced by: '<S47>/Constant7'
                                                * This is the longitude range limit for detecting range flicker function
                                                */
extern real32_T KfACCS_d_FollowingToLowSpdRRThrsh;/* Variable: KfACCS_d_FollowingToLowSpdRRThrsh
                                                   * Referenced by: '<S150>/Constant15'
                                                   * If want from following control to low speed mode ,the CIPV range rate need smaller than this calibration
                                                   */
extern real32_T KfACCS_d_LatRangeMaxForCloseDisappear;/* Variable: KfACCS_d_LatRangeMaxForCloseDisappear
                                                       * Referenced by: '<S56>/Constant25'
                                                       *
                                                         The maximum lateral range for selecting this type target

                                                       */
extern real32_T KfACCS_d_LatRangeMinForCloseDisappear;/* Variable: KfACCS_d_LatRangeMinForCloseDisappear
                                                       * Referenced by: '<S56>/Constant26'
                                                       * The minimum lateral range for selecting this type target
                                                       */
extern real32_T KfACCS_d_LonRangeMaxForCloseDisappear;/* Variable: KfACCS_d_LonRangeMaxForCloseDisappear
                                                       * Referenced by: '<S56>/Constant21'
                                                       * The maximum longitude range for selecting this type target
                                                       */
extern real32_T KfACCS_d_LonRangeMinForCloseDisappear;/* Variable: KfACCS_d_LonRangeMinForCloseDisappear
                                                       * Referenced by: '<S56>/Constant22'
                                                       * The minimum longitude range for selecting this type target
                                                       */
extern real32_T KfACCS_d_LowSpdToTempStpDisThrsh;/* Variable: KfACCS_d_LowSpdToTempStpDisThrsh
                                                  * Referenced by:
                                                  *   '<S150>/Constant21'
                                                  *   '<S150>/Constant23'
                                                  *   '<S150>/Constant38'
                                                  * If want from low speed to Temp stop, the stop distance need smaller than this calibration
                                                  */
extern real32_T KfACCS_d_MaxRange;     /* Variable: KfACCS_d_MaxRange
                                        * Referenced by: '<S34>/KfACCS_d_MaxRange'
                                        * CIPV target range will be limit by this cal
                                        */
extern real32_T KfACCS_d_MinimumRange; /* Variable: KfACCS_d_MinimumRange
                                        * Referenced by: '<S34>/KfACCS_d_MinimumRange'
                                        * The drive set target range and this cal to chose max as target range
                                        */
extern real32_T KfACCS_d_RangeForApproaching;/* Variable: KfACCS_d_RangeForApproaching
                                              * Referenced by: '<S56>/Constant9'
                                              * This is the range to determine the status of approaching
                                              */
extern real32_T KfACCS_d_RangeForAway; /* Variable: KfACCS_d_RangeForAway
                                        * Referenced by: '<S56>/Constant14'
                                        * This is the range to determine the status of away.
                                        */
extern real32_T KfACCS_d_RangePIDCtrl_RangeErrlimit;/* Variable: KfACCS_d_RangePIDCtrl_RangeErrlimit
                                                     * Referenced by:
                                                     *   '<S18>/Constant1'
                                                     *   '<S18>/Constant3'
                                                     * Range error limit for Range Pid control
                                                     */
extern real32_T KfACCS_d_Range_PreSet; /* Variable: KfACCS_d_Range_PreSet
                                        * Referenced by:
                                        *   '<S39>/Constant39'
                                        *   '<S40>/Constant39'
                                        *   '<S41>/Constant39'
                                        *   '<S42>/Constant39'
                                        *   '<S43>/Constant39'
                                        * when KbACCS_UseVirtualObject=true, object range is from this calibration
                                        */
extern real32_T KfACCS_d_TempStopToLaunchRRThrsh;/* Variable: KfACCS_d_TempStopToLaunchRRThrsh
                                                  * Referenced by: '<S150>/Constant34'
                                                  * Under Temp stop and there is CIPV, if want from Temp stop to launch ,the CIPV range rate
                                                    need bigger than this calibration
                                                  */
extern real32_T KfACCS_d_TempStpToLaunchDisThrsh;/* Variable: KfACCS_d_TempStpToLaunchDisThrsh
                                                  * Referenced by:
                                                  *   '<S150>/Constant28'
                                                  *   '<S150>/Constant33'
                                                  * If want from Temp stop to launch, the stop distance need bigger than this calibration
                                                  */
extern real32_T KfACCS_d_VitualStopDisFrmDCSN;/* Variable: KfACCS_d_VitualStopDisFrmDCSN
                                               * Referenced by: '<S8>/Constant1'
                                               * This is only for test
                                                 Vitual Stop distance as KbACCS_UseVitualDCSNInfo=True
                                               */
extern real32_T KfACCS_k_DrsdAccelFilter;/* Variable: KfACCS_k_DrsdAccelFilter
                                          * Referenced by: '<S103>/Constant1'
                                          * Filter for acceleration
                                          */
extern real32_T KfACCS_k_EgoPitchFilter;/* Variable: KfACCS_k_EgoPitchFilter
                                         * Referenced by: '<S103>/Constant6'
                                         * Filter for Pitch
                                         */
extern real32_T KfACCS_k_ObjectAccelFilter;/* Variable: KfACCS_k_ObjectAccelFilter
                                            * Referenced by:
                                            *   '<S44>/Constant46'
                                            *   '<S68>/Constant46'
                                            *   '<S75>/Constant46'
                                            *   '<S82>/Constant46'
                                            *   '<S89>/Constant46'
                                            *   '<S96>/Constant46'
                                            * Filter for object acceleration
                                            */
extern real32_T KfACCS_k_ObjectRangeFilter;/* Variable: KfACCS_k_ObjectRangeFilter
                                            * Referenced by:
                                            *   '<S45>/Constant15'
                                            *   '<S45>/Constant46'
                                            *   '<S69>/Constant15'
                                            *   '<S69>/Constant46'
                                            *   '<S76>/Constant15'
                                            *   '<S76>/Constant46'
                                            *   '<S83>/Constant15'
                                            *   '<S83>/Constant46'
                                            *   '<S90>/Constant15'
                                            *   '<S90>/Constant46'
                                            *   '<S97>/Constant15'
                                            *   '<S97>/Constant46'
                                            * Filter for object range
                                            */
extern real32_T KfACCS_k_ObjectSpdFilter;/* Variable: KfACCS_k_ObjectSpdFilter
                                          * Referenced by:
                                          *   '<S44>/Constant48'
                                          *   '<S44>/Constant50'
                                          *   '<S68>/Constant48'
                                          *   '<S68>/Constant50'
                                          *   '<S75>/Constant48'
                                          *   '<S75>/Constant50'
                                          *   '<S82>/Constant48'
                                          *   '<S82>/Constant50'
                                          *   '<S89>/Constant48'
                                          *   '<S89>/Constant50'
                                          *   '<S96>/Constant48'
                                          *   '<S96>/Constant50'
                                          * Filter for object speed
                                          */
extern real32_T KfACCS_t_CIPVChangedTypeDelay;/* Variable: KfACCS_t_CIPVChangedTypeDelay
                                               * Referenced by: '<S46>/Constant4'
                                               * This is the time to determin how long the state of the obstacle change will last
                                               */
extern real32_T KfACCS_t_CIPVDisappearDelay;/* Variable: KfACCS_t_CIPVDisappearDelay
                                             * Referenced by:
                                             *   '<S60>/Constant4'
                                             *   '<S61>/Constant4'
                                             *   '<S62>/Constant4'
                                             *   '<S63>/Constant4'
                                             *   '<S64>/Constant4'
                                             *   '<S65>/Constant4'
                                             *   '<S66>/Constant4'
                                             *   '<S67>/Constant4'
                                             * This is the time to determin how long the obstacle's information will last when it is disappeared
                                             */
extern real32_T KfACCS_t_DtrmSelfChangeLane;/* Variable: KfACCS_t_DtrmSelfChangeLane
                                             * Referenced by: '<S56>/Constant18'
                                             * If wheel steering bigger than KfACCS_Ang_DtrmSelfChangeLane,timer++, as timer>this calibration, sriver seft change lane
                                             */
extern real32_T KfACCS_t_DtrmSelfChangeLaneDelay;/* Variable: KfACCS_t_DtrmSelfChangeLaneDelay
                                                  * Referenced by: '<S56>/Constant17'
                                                  * This is delay time to determine whether vehicle is changing lane
                                                  */
extern real32_T KfACCS_t_EnterLowSpeedDelay;/* Variable: KfACCS_t_EnterLowSpeedDelay
                                             * Referenced by:
                                             *   '<S150>/Constant12'
                                             *   '<S150>/Constant5'
                                             * If the Ego speed is smaller than KfACCS_SpdToLowSpdCtrlSpdThrsh under Speed control or KfACCS_FollowingToLowSpdThrsh under following control, the timer will increase,
                                               as the timer is bingger than this calibration, will enter low speed mode.
                                             */
extern real32_T KfACCS_t_ExitLaunchTimer;/* Variable: KfACCS_t_ExitLaunchTimer
                                          * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                          * If at the launch mode timer than this calibration, will exit launch mode
                                          */
extern real32_T KfACCS_t_ExitLowSpeedDelay;/* Variable: KfACCS_t_ExitLowSpeedDelay
                                            * Referenced by:
                                            *   '<S150>/Constant17'
                                            *   '<S150>/Constant8'
                                            * If Ego speed is bigger than KfACCS_LowSpdToSpdCtrlSpdThrsh under speed control or KfACCS_LowSpdToFollowingSpdThrsh under following control,
                                              the timer will increase, and timer is bigger than this calibration,will exit low speed mode
                                            */
extern real32_T KfACCS_t_FollowToSpdRampTimerThrsh;/* Variable: KfACCS_t_FollowToSpdRampTimerThrsh
                                                    * Referenced by: '<S111>/MATLAB Function'
                                                    * Hold timer for VbACCS_EnableFollowToSpdRamp as from Follow to speed
                                                    */
extern real32_T KfACCS_t_LaunchToFollowRampTimerThrsh;/* Variable: KfACCS_t_LaunchToFollowRampTimerThrsh
                                                       * Referenced by: '<S111>/MATLAB Function'
                                                       * Hold timer for VbACCS_EnableLaunchToFollowRamp as from Launch to follow
                                                       */
extern real32_T KfACCS_t_LaunchToLowSpdTm;/* Variable: KfACCS_t_LaunchToLowSpdTm
                                           * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                           * Under launch mode,Ego_CurrentSpeed<=KfACCS_LaunchToLowSpdSpeedThrsh)and (Ego_CurrentSpeed>KfACCS_MovingMinSpeedThrsh,
                                             the timer will increase, when the timer is bigger than this calibration, will from launch change to Low speed
                                           */
extern real32_T KfACCS_t_LaunchToSpdRampTimerThrsh;/* Variable: KfACCS_t_LaunchToSpdRampTimerThrsh
                                                    * Referenced by: '<S111>/MATLAB Function'
                                                    * Hold timer for VbACCS_EnableLaunchToSpdRamp as from launch to speed
                                                    */
extern real32_T KfACCS_t_LaunchToTempStpTm;/* Variable: KfACCS_t_LaunchToTempStpTm
                                            * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                            * Under launch , if Ego_CurrentSpeed<=KfACCS_MovingMinSpeedThrsh, the timer will increase, if
                                              the timer is bigger than this calibration, will from launch to Temp stop
                                            */
extern real32_T KfACCS_t_MaxTimerAllowAutoResume;/* Variable: KfACCS_t_MaxTimerAllowAutoResume
                                                  * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                                  * When stop timer bigger than this timer, if the driver want to launch the vehicle, he need
                                                    Press resume switch
                                                  */
extern real32_T KfACCS_t_PressGasPedalHoldTm;/* Variable: KfACCS_t_PressGasPedalHoldTm
                                              * Referenced by: '<S155>/DtrmnACCS_WhetherPressGasPedal'
                                              * If driver has press the gas pedal, we think driver presss the gas pedal during this calibratin timer.
                                              */
extern real32_T KfACCS_t_PressResumeHoldTm;/* Variable: KfACCS_t_PressResumeHoldTm
                                            * Referenced by: '<S155>/DtrmnACCS_WhetherPressResume'
                                            * If driver has press the resume switch, we think driver presss the resume switch during this calibratin timer.
                                            */
extern real32_T KfACCS_t_SpeedToFollowRampTimerThrsh;/* Variable: KfACCS_t_SpeedToFollowRampTimerThrsh
                                                      * Referenced by: '<S111>/MATLAB Function'
                                                      * Hold timer for VbACCS_EnableSpeedToFollowRamp as from Speed to follow
                                                      */
extern real32_T KfACCS_t_StopTooLongThrsh;/* Variable: KfACCS_t_StopTooLongThrsh
                                           * Referenced by: '<S150>/Constant39'
                                           * If the stop timer is bigger than this calibration, will from stop to enter standby
                                           */
extern real32_T KfACCS_t_TempStpToStpDelay;/* Variable: KfACCS_t_TempStpToStpDelay
                                            * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                            * If the stop timer is bigger than this calibration, will from Temp stop to stop
                                            */
extern real32_T KfACCS_t_TimeGapToCalcRange;/* Variable: KfACCS_t_TimeGapToCalcRange
                                             * Referenced by: '<S34>/kfACCS_TimeGapToCalcRange'
                                             * This is only for logic test.When KbACCS_CalTimeGap=true,useing this calibration to calculate the range
                                             */
extern real32_T KfACCS_t_TimeOffset;   /* Variable: KfACCS_t_TimeOffset
                                        * Referenced by:
                                        *   '<S45>/Constant13'
                                        *   '<S45>/Constant14'
                                        *   '<S69>/Constant13'
                                        *   '<S69>/Constant14'
                                        *   '<S76>/Constant13'
                                        *   '<S76>/Constant14'
                                        *   '<S83>/Constant13'
                                        *   '<S83>/Constant14'
                                        *   '<S90>/Constant13'
                                        *   '<S90>/Constant14'
                                        *   '<S97>/Constant13'
                                        *   '<S97>/Constant14'
                                        * This is only for logic test.Please hold the default value
                                        */
extern real32_T KfACCS_v_CalDriverSetSpeed;/* Variable: KfACCS_v_CalDriverSetSpeed
                                            * Referenced by: '<S34>/KfACCS_v_CalDriverSetSpeed'
                                            * When KbACCS_CalDriverSetSpeed=True, the drive speed is from this calibration
                                            */
extern real32_T KfACCS_v_ChangedObsVelDiff;/* Variable: KfACCS_v_ChangedObsVelDiff
                                            * Referenced by: '<S56>/Constant2'
                                            * This is the velocity difference to determine whether the target is a changed target
                                            */
extern real32_T KfACCS_v_ChooseStationaryObsMaxSpd;/* Variable: KfACCS_v_ChooseStationaryObsMaxSpd
                                                    * Referenced by: '<S49>/Constant'
                                                    * This is the speed limit for considering stationary target. If the car speed is lower than the limit, ACCS will choose stationary vehicle as target.
                                                    */
extern real32_T KfACCS_v_DeltaSped_EGMOAndCanThrsh;/* Variable: KfACCS_v_DeltaSped_EGMOAndCanThrsh
                                                    * Referenced by: '<S9>/Constant3'
                                                    * If speed error beween EGMO and Can bigger than this calibration,ACCS will use Can vehilce speed
                                                    */
extern real32_T KfACCS_v_DriverSetSpeedMinThrsh;/* Variable: KfACCS_v_DriverSetSpeedMinThrsh
                                                 * Referenced by: '<S34>/KfACCS_v_DriverSetSpeedMinThrsh'
                                                 * Driver set speed need bigger than this calibration to enable ACCS control
                                                 */
extern real32_T KfACCS_v_EnableACCHiSpdThrsh;/* Variable: KfACCS_v_EnableACCHiSpdThrsh
                                              * Referenced by: '<S148>/Constant48'
                                              * The max speed for enable ACCS
                                              */
extern real32_T KfACCS_v_EnableACCLoSpdThrsh;/* Variable: KfACCS_v_EnableACCLoSpdThrsh
                                              * Referenced by: '<S148>/Constant46'
                                              * The min speed for ACCS
                                              */
extern real32_T KfACCS_v_ExitLaunchSpeedThrsh;/* Variable: KfACCS_v_ExitLaunchSpeedThrsh
                                               * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                               * If the Ego speed is bigger than this cal, will exit launch mode.
                                               */
extern real32_T KfACCS_v_FlickerRangeEgoSpd;/* Variable: KfACCS_v_FlickerRangeEgoSpd
                                             * Referenced by: '<S47>/Constant3'
                                             * This is the maximum speed of ego car for range flicker function
                                             */
extern real32_T KfACCS_v_FlickerRangeRRForReset;/* Variable: KfACCS_v_FlickerRangeRRForReset
                                                 * Referenced by: '<S47>/Constant4'
                                                 * This is the maximum range rate for reset range flicker function
                                                 */
extern real32_T KfACCS_v_FlickerRangeRateLimit;/* Variable: KfACCS_v_FlickerRangeRateLimit
                                                * Referenced by: '<S47>/Constant2'
                                                * This is the range rate limit for detecting range flicker function
                                                */
extern real32_T KfACCS_v_FollowingToLowSpdThrsh;/* Variable: KfACCS_v_FollowingToLowSpdThrsh
                                                 * Referenced by:
                                                 *   '<S150>/Constant13'
                                                 *   '<S150>/Constant14'
                                                 * If want from following control to low speed mode ,the Ego speed need smaller than this calibration
                                                 */
extern real32_T KfACCS_v_IgnoreObsSpdLimit;/* Variable: KfACCS_v_IgnoreObsSpdLimit
                                            * Referenced by: '<S49>/Constant4'
                                            * If the obstacle's speed is lower than the calibration, ACCS will take it as stationary target.
                                            */
extern real32_T KfACCS_v_LatSpdDeadband_Max;/* Variable: KfACCS_v_LatSpdDeadband_Max
                                             * Referenced by:
                                             *   '<S44>/Constant15'
                                             *   '<S44>/Constant17'
                                             *   '<S44>/Constant22'
                                             *   '<S68>/Constant15'
                                             *   '<S68>/Constant17'
                                             *   '<S68>/Constant22'
                                             *   '<S75>/Constant15'
                                             *   '<S75>/Constant17'
                                             *   '<S75>/Constant22'
                                             *   '<S82>/Constant15'
                                             *   '<S82>/Constant17'
                                             *   '<S82>/Constant22'
                                             *   '<S89>/Constant15'
                                             *   '<S89>/Constant17'
                                             *   '<S89>/Constant22'
                                             *   '<S96>/Constant15'
                                             *   '<S96>/Constant17'
                                             *   '<S96>/Constant22'
                                             * If the object latteral speed bigger than this calibration, use latteral speed
                                             */
extern real32_T KfACCS_v_LatSpdDeadband_Min;/* Variable: KfACCS_v_LatSpdDeadband_Min
                                             * Referenced by:
                                             *   '<S44>/Constant16'
                                             *   '<S44>/Constant18'
                                             *   '<S44>/Constant23'
                                             *   '<S68>/Constant16'
                                             *   '<S68>/Constant18'
                                             *   '<S68>/Constant23'
                                             *   '<S75>/Constant16'
                                             *   '<S75>/Constant18'
                                             *   '<S75>/Constant23'
                                             *   '<S82>/Constant16'
                                             *   '<S82>/Constant18'
                                             *   '<S82>/Constant23'
                                             *   '<S89>/Constant16'
                                             *   '<S89>/Constant18'
                                             *   '<S89>/Constant23'
                                             *   '<S96>/Constant16'
                                             *   '<S96>/Constant18'
                                             *   '<S96>/Constant23'
                                             * If the object latteral speed smaller than this calibration, set latteral speed to 0
                                             */
extern real32_T KfACCS_v_LatSpdUpdateThrsh;/* Variable: KfACCS_v_LatSpdUpdateThrsh
                                            * Referenced by:
                                            *   '<S44>/Constant26'
                                            *   '<S68>/Constant26'
                                            *   '<S75>/Constant26'
                                            *   '<S82>/Constant26'
                                            *   '<S89>/Constant26'
                                            *   '<S96>/Constant26'
                                            * Only object latteral speed change is bigger than this calibration, set the new latteral speed
                                            */
extern real32_T KfACCS_v_LaunchToLowSpdSpeedThrsh;/* Variable: KfACCS_v_LaunchToLowSpdSpeedThrsh
                                                   * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                                   * If want from launch to low speed, the ego speed need smaller tham this calibration
                                                   */
extern real32_T KfACCS_v_LinearVelocity_PreSet;/* Variable: KfACCS_v_LinearVelocity_PreSet
                                                * Referenced by:
                                                *   '<S39>/Constant42'
                                                *   '<S40>/Constant42'
                                                *   '<S41>/Constant42'
                                                *   '<S42>/Constant42'
                                                *   '<S43>/Constant42'
                                                * when KbACCS_UseVirtualObject=true, object LinearVelocity is from this calibration
                                                */
extern real32_T KfACCS_v_LowSpdToFollowingSpdThrsh;/* Variable: KfACCS_v_LowSpdToFollowingSpdThrsh
                                                    * Referenced by:
                                                    *   '<S150>/Constant18'
                                                    *   '<S150>/Constant19'
                                                    * If want from low speed to following control, the ego and CIPV speed need bigger than this calibration
                                                    */
extern real32_T KfACCS_v_LowSpdToSpdCtrlSpdThrsh;/* Variable: KfACCS_v_LowSpdToSpdCtrlSpdThrsh
                                                  * Referenced by: '<S150>/Constant9'
                                                  * If want from low speed to speed control, the ego current need bigger than this calibration
                                                  */
extern real32_T KfACCS_v_LowSpdToTempStpSpdThrsh;/* Variable: KfACCS_v_LowSpdToTempStpSpdThrsh
                                                  * Referenced by:
                                                  *   '<S150>/Constant20'
                                                  *   '<S150>/Constant22'
                                                  * If want from low speed to Temp stop, the ego speed need smaller than this calibration
                                                  */
extern real32_T KfACCS_v_MovingMinSpeedThrsh;/* Variable: KfACCS_v_MovingMinSpeedThrsh
                                              * Referenced by: '<S138>/DtrmnACCS_RunStatusTransfer'
                                              * If the Ego speed is bigger than this calibration, we think the vehicle is moving
                                              */
extern real32_T KfACCS_v_ObjectSpdUpdateThrsh;/* Variable: KfACCS_v_ObjectSpdUpdateThrsh
                                               * Referenced by:
                                               *   '<S44>/Constant25'
                                               *   '<S68>/Constant25'
                                               *   '<S75>/Constant25'
                                               *   '<S82>/Constant25'
                                               *   '<S89>/Constant25'
                                               *   '<S96>/Constant25'
                                               * Only object Long speed change is bigger than this calibration, set the new long speed
                                               */
extern real32_T KfACCS_v_OnToSpdCtrlSpdThrsh;/* Variable: KfACCS_v_OnToSpdCtrlSpdThrsh
                                              * Referenced by: '<S150>/Constant24'
                                              * If want from status_on to speed control,the ego current speed need bigger than this calibration
                                              */
extern real32_T KfACCS_v_RangeRateForApproaching;/* Variable: KfACCS_v_RangeRateForApproaching
                                                  * Referenced by: '<S56>/Constant10'
                                                  * This is the range rate to determine the status of approaching
                                                  */
extern real32_T KfACCS_v_RangeRateForAway;/* Variable: KfACCS_v_RangeRateForAway
                                           * Referenced by: '<S56>/Constant11'
                                           * This is the range rate to determine the status of away
                                           */
extern real32_T KfACCS_v_RangeRate_PreSet;/* Variable: KfACCS_v_RangeRate_PreSet
                                           * Referenced by:
                                           *   '<S39>/Constant37'
                                           *   '<S40>/Constant37'
                                           *   '<S41>/Constant37'
                                           *   '<S42>/Constant37'
                                           *   '<S43>/Constant37'
                                           * when KbACCS_UseVirtualObject=true, object range rate is from this calibration
                                           */
extern real32_T KfACCS_v_SpdMaxForCloseDisappear;/* Variable: KfACCS_v_SpdMaxForCloseDisappear
                                                  * Referenced by: '<S56>/Constant23'
                                                  * The maximum speed for selecting this type target
                                                  */
extern real32_T KfACCS_v_SpdPIDCtrl_SpdErrlimit;/* Variable: KfACCS_v_SpdPIDCtrl_SpdErrlimit
                                                 * Referenced by:
                                                 *   '<S106>/Constant1'
                                                 *   '<S106>/Constant3'
                                                 * Speed error limit for Speed Pid control
                                                 */
extern real32_T KfACCS_v_SpdToLowSpdCtrlSpdThrsh;/* Variable: KfACCS_v_SpdToLowSpdCtrlSpdThrsh
                                                  * Referenced by: '<S150>/Constant6'
                                                  * If want from speed control to low speed control, the ego speed need smaller than this calibration
                                                  */
extern real32_T KfACCS_v_TempStpToLaunchSpdThrsh;/* Variable: KfACCS_v_TempStpToLaunchSpdThrsh
                                                  * Referenced by:
                                                  *   '<S150>/Constant27'
                                                  *   '<S150>/Constant30'
                                                  * If want from Temp stop to launch, the driver speed need bigger than this calibration
                                                  */
extern real32_T KfACCS_v_VitualSpeedLimitFrmDCSN;/* Variable: KfACCS_v_VitualSpeedLimitFrmDCSN
                                                  * Referenced by: '<S8>/Constant3'
                                                  * This is only for test
                                                    Vitual Speed limit as KbACCS_UseVitualDCSNInfo=True
                                                  */
extern real32_T KtACCS_AXIS_AccelToGasPedal_Accel[17];/* Variable: KtACCS_AXIS_AccelToGasPedal_Accel
                                                       * Referenced by: '<S114>/KtACCS_Pct_AccelToGasPedal '
                                                       * This is acceleration axis for KtACCS_AccelToGasPedal
                                                       */
extern real32_T KtACCS_AXIS_AccelToGasPedal_VehSpd[10];/* Variable: KtACCS_AXIS_AccelToGasPedal_VehSpd
                                                        * Referenced by: '<S114>/KtACCS_Pct_AccelToGasPedal '
                                                        * This is vehicle speed for KtACCS_AccelToGasPedal
                                                        */
extern real32_T KtACCS_AXIS_DCSNStopDisGain_d[13];/* Variable: KtACCS_AXIS_DCSNStopDisGain_d
                                                   * Referenced by: '<S103>/KtACCS_r_DCSNStopDistanceGain '
                                                   * This is distance axis for calibration KtACCS_r_DCSNStopDistanceGain
                                                   */
extern real32_T KtACCS_AXIS_DCSNStopGainSpd_SpdErr[11];/* Variable: KtACCS_AXIS_DCSNStopGainSpd_SpdErr
                                                        * Referenced by: '<S103>/KtACCS_r_DCSNStopSpdGain'
                                                        * This is speed error for KtACCS_r_DCSNStopSpdGain
                                                        */
extern real32_T KtACCS_AXIS_DCSNStopGain_VehSpd[11];/* Variable: KtACCS_AXIS_DCSNStopGain_VehSpd
                                                     * Referenced by:
                                                     *   '<S103>/KtACCS_r_DCSNStopDistanceGain '
                                                     *   '<S103>/KtACCS_r_DCSNStopSpdGain'
                                                     * This is speed axis for KtACCS_r_DCSNStopDistanceGain and KtACCS_r_DCSNStopSpdGain
                                                     */
extern real32_T KtACCS_AXIS_DCSNStopThrshHi_Spd[6];/* Variable: KtACCS_AXIS_DCSNStopThrshHi_Spd
                                                    * Referenced by: '<S18>/KtACCS_d_RespDCSNStopThrshHi'
                                                    * This is axis for KtACCS_d_RespDCSNStopThrshHi
                                                    */
extern real32_T KtACCS_AXIS_OpenAccelFwCtrl_RR[7];/* Variable: KtACCS_AXIS_OpenAccelFwCtrl_RR
                                                   * Referenced by:
                                                   *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl'
                                                   *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl1'
                                                   * This is speed error(Range rate) axis for KtACCS_OpenAccel_FollowCtrl
                                                   */
extern real32_T KtACCS_AXIS_OpenAccelFwCtrl_RangeErr[9];/* Variable: KtACCS_AXIS_OpenAccelFwCtrl_RangeErr
                                                         * Referenced by:
                                                         *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl'
                                                         *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl1'
                                                         * This is range error axis for KtACCS_OpenAccel_FollowCtrl
                                                         */
extern real32_T KtACCS_AXIS_OpenAccelFwCtrl_TimeGapAcc[7];/* Variable: KtACCS_AXIS_OpenAccelFwCtrl_TimeGapAcc
                                                           * Referenced by: '<S24>/1-D Lookup Table'
                                                           * This is the axis of Open acceleration axis for feedforward control
                                                           */
extern real32_T KtACCS_AXIS_OpenAccelFwCtrl_TimeGapDec[6];/* Variable: KtACCS_AXIS_OpenAccelFwCtrl_TimeGapDec
                                                           * Referenced by: '<S24>/1-D Lookup Table1'
                                                           * This is the axis of Open acceleration axis for feedforward control
                                                           */
extern real32_T KtACCS_AXIS_OpenAccelLaunch_CurSpd[6];/* Variable: KtACCS_AXIS_OpenAccelLaunch_CurSpd
                                                       * Referenced by: '<S26>/KtACCS_a_OpenAccel_Launch'
                                                       * This is vehcile speed axis for KtACCS_OpenAccel_Launch
                                                       */
extern real32_T KtACCS_AXIS_OpenAccelLowSpedCtrl_SpedErr[7];/* Variable: KtACCS_AXIS_OpenAccelLowSpedCtrl_SpedErr
                                                             * Referenced by: '<S27>/KtACCS_a_OpenAccel_LowSpeedCtrl'
                                                             * This is speed error axis for KtACCS_a_OpenAccel_LowSpeedCtrl
                                                             */
extern real32_T KtACCS_AXIS_OpenAccelSpedCtrl_SpedErr[7];/* Variable: KtACCS_AXIS_OpenAccelSpedCtrl_SpedErr
                                                          * Referenced by: '<S25>/KtACCS_a_OpenAccel_SpeedCtrl'
                                                          * This is speed error axis for KtACCS_OpenAccel_SpeedCtrl
                                                          */
extern real32_T KtACCS_AXIS_OpenAccelStop_StopDis[6];/* Variable: KtACCS_AXIS_OpenAccelStop_StopDis
                                                      * Referenced by: '<S18>/KtACCS_t_CalOpenAccelForStopFrmDCSN'
                                                      * The axis for the calibration KtACCS_t_CalOpenAccelForStopFrmDCSN
                                                      */
extern real32_T KtACCS_AXIS_RangeCtrlPGain_Err[9];/* Variable: KtACCS_AXIS_RangeCtrlPGain_Err
                                                   * Referenced by:
                                                   *   '<S129>/KtACCS_r_RangeCtrlPGain '
                                                   *   '<S129>/KtACCS_r_RangeCtrlPGain 1'
                                                   * This is range error axis for KtACCS_r_RangeCtrlPGain
                                                   */
extern real32_T KtACCS_AXIS_RangeCtrlPGain_VehSpd[10];/* Variable: KtACCS_AXIS_RangeCtrlPGain_VehSpd
                                                       * Referenced by:
                                                       *   '<S129>/KtACCS_r_RangeCtrlPGain '
                                                       *   '<S129>/KtACCS_r_RangeCtrlPGain 1'
                                                       *   '<S132>/KtACCS_r_SpeedCtrlPGain'
                                                       *   '<S132>/KtACCS_r_SpeedCtrlPGain1'
                                                       * This is vehicle speed axis for KtACCS_r_RangeCtrlPGain and KtACCS_r_SpeedCtrlPGain
                                                       */
extern real32_T KtACCS_AXIS_SpeedCtrlPGain_Err[9];/* Variable: KtACCS_AXIS_SpeedCtrlPGain_Err
                                                   * Referenced by:
                                                   *   '<S132>/KtACCS_r_SpeedCtrlPGain'
                                                   *   '<S132>/KtACCS_r_SpeedCtrlPGain1'
                                                   * This is vehicle speed error axis for KtACCS_r_SpeedCtrlPGain
                                                   */
extern real32_T KtACCS_AXIS_StopStatus_Accel_Pitch[10];/* Variable: KtACCS_AXIS_StopStatus_Accel_Pitch
                                                        * Referenced by: '<S103>/KtACCS_a_StopStatus_Accel'
                                                        * This is Pitch axis for KtACCS_StopStatus_Accel
                                                        */
extern real32_T KtACCS_AXIS_TargetRange_Speed[10];/* Variable: KtACCS_AXIS_TargetRange_Speed
                                                   * Referenced by: '<S34>/KtACCS_d_CIPVTargtRange'
                                                   * The CIPV speed axis for KtACCS_d_CIPVTargtRange
                                                   */
extern real32_T KtACCS_AXIS_TargetZoneSpd[15];/* Variable: KtACCS_AXIS_TargetZoneSpd
                                               * Referenced by: '<S49>/1-D Lookup Table'
                                               * This this the axis value for target zone
                                               */
extern real32_T KtACCS_AXIS_TargtRange_Timegap[4];/* Variable: KtACCS_AXIS_TargtRange_Timegap
                                                   * Referenced by: '<S34>/KtACCS_d_CIPVTargtRange'
                                                   * The time gap axis for KtACCS_d_CIPVTargtRange
                                                   */
extern real32_T KtACCS_AXIS_TorqCtrlProp_DeltaAccel[9];/* Variable: KtACCS_AXIS_TorqCtrlProp_DeltaAccel
                                                        * Referenced by: '<S123>/KtACCS_r_TorqCtrlProp '
                                                        * This is delta acceleration axis for KtACCS_r_TorqCtrlProp
                                                        */
extern real32_T KtACCS_AXIS_TorqCtrlProp_EgoSpeed[10];/* Variable: KtACCS_AXIS_TorqCtrlProp_EgoSpeed
                                                       * Referenced by: '<S123>/KtACCS_r_TorqCtrlProp '
                                                       * This is ego cunrrent speed axis for KtACCS_r_TorqCtrlProp

                                                       */
extern real32_T KtACCS_Pct_AccelToGasPedal[170];/* Variable: KtACCS_Pct_AccelToGasPedal
                                                 * Referenced by: '<S114>/KtACCS_Pct_AccelToGasPedal '
                                                 * This cal is used to transfer acceleration to gas pedal or torq(percent)
                                                 */
extern real32_T KtACCS_a_OpenAccel_FollowCtrl[63];/* Variable: KtACCS_a_OpenAccel_FollowCtrl
                                                   * Referenced by:
                                                   *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl'
                                                   *   '<S24>/KtACCS_a_OpenAccel_FollowCtrl1'
                                                   * This is open acceleration table under following control mode,it is the function of range error and speed error
                                                   */
extern real32_T KtACCS_a_OpenAccel_Launch[6];/* Variable: KtACCS_a_OpenAccel_Launch
                                              * Referenced by: '<S26>/KtACCS_a_OpenAccel_Launch'
                                              * This is open acceleration table under launch control mode,it is the function of Ego current speed
                                              */
extern real32_T KtACCS_a_OpenAccel_LowSpeedCtrl[7];/* Variable: KtACCS_a_OpenAccel_LowSpeedCtrl
                                                    * Referenced by: '<S27>/KtACCS_a_OpenAccel_LowSpeedCtrl'
                                                    * his is open acceleration table under low speed control mode,it is the function of speed error
                                                    */
extern real32_T KtACCS_a_OpenAccel_SpeedCtrl[7];/* Variable: KtACCS_a_OpenAccel_SpeedCtrl
                                                 * Referenced by: '<S25>/KtACCS_a_OpenAccel_SpeedCtrl'
                                                 * This is open acceleration table under speed control mode,it is the function of speed error
                                                 */
extern real32_T KtACCS_a_StopStatus_Accel[10];/* Variable: KtACCS_a_StopStatus_Accel
                                               * Referenced by: '<S103>/KtACCS_a_StopStatus_Accel'
                                               * When KbACCS_UseStopStatus_Accel=true, accel will be form this cal during status is Stop.This cal is the function of pitch
                                               */
extern real32_T KtACCS_d_CIPVTargtRange[40];/* Variable: KtACCS_d_CIPVTargtRange
                                             * Referenced by: '<S34>/KtACCS_d_CIPVTargtRange'
                                             * As keACCS_TargetRangeCalType =0, use this cal to define the target range
                                             */
extern real32_T KtACCS_d_RespDCSNStopThrshHi[6];/* Variable: KtACCS_d_RespDCSNStopThrshHi
                                                 * Referenced by: '<S18>/KtACCS_d_RespDCSNStopThrshHi'
                                                 * Only when stop distance from DCSN smaller than this calibration, ACCS response this stop requirement
                                                 */
extern real32_T KtACCS_d_TargetZoneLongDis[15];/* Variable: KtACCS_d_TargetZoneLongDis
                                                * Referenced by: '<S49>/1-D Lookup Table'
                                                * This is the target zone longitude distance for different speed of ego car
                                                */
extern real32_T KtACCS_r_DCSNStopDistanceGain[143];/* Variable: KtACCS_r_DCSNStopDistanceGain
                                                    * Referenced by: '<S103>/KtACCS_r_DCSNStopDistanceGain '
                                                    * This gain is for stop distance from DCSN
                                                    */
extern real32_T KtACCS_r_DCSNStopSpdGain[121];/* Variable: KtACCS_r_DCSNStopSpdGain
                                               * Referenced by: '<S103>/KtACCS_r_DCSNStopSpdGain'
                                               * This gain is for stop speed error from DCSN
                                               */
extern real32_T KtACCS_r_OpenAccelFwCtrl_TimeGapAcc[7];/* Variable: KtACCS_r_OpenAccelFwCtrl_TimeGapAcc
                                                        * Referenced by: '<S24>/1-D Lookup Table'
                                                        * This the the table value of Open acceleration axis for feedforward control
                                                        */
extern real32_T KtACCS_r_OpenAccelFwCtrl_TimeGapDec[6];/* Variable: KtACCS_r_OpenAccelFwCtrl_TimeGapDec
                                                        * Referenced by: '<S24>/1-D Lookup Table1'
                                                        * This the the table value of Open acceleration axis for feedforward control
                                                        */
extern real32_T KtACCS_r_RangeCtrlPGain[90];/* Variable: KtACCS_r_RangeCtrlPGain
                                             * Referenced by:
                                             *   '<S129>/KtACCS_r_RangeCtrlPGain '
                                             *   '<S129>/KtACCS_r_RangeCtrlPGain 1'
                                             * This is Prop gain for Range PID contrl
                                             */
extern real32_T KtACCS_r_SpeedCtrlPGain[90];/* Variable: KtACCS_r_SpeedCtrlPGain
                                             * Referenced by:
                                             *   '<S132>/KtACCS_r_SpeedCtrlPGain'
                                             *   '<S132>/KtACCS_r_SpeedCtrlPGain1'
                                             * This is Prop gain for speed PID contrl
                                             */
extern real32_T KtACCS_r_TorqCtrlProp[90];/* Variable: KtACCS_r_TorqCtrlProp
                                           * Referenced by: '<S123>/KtACCS_r_TorqCtrlProp '
                                           * Torq control PID p gain
                                           */
extern real32_T KtACCS_t_CalOpenAccelForStopFrmDCSN[6];/* Variable: KtACCS_t_CalOpenAccelForStopFrmDCSN
                                                        * Referenced by: '<S18>/KtACCS_t_CalOpenAccelForStopFrmDCSN'
                                                        * Want how long to stop the vehicle
                                                        */
extern real32_T kfACCS_v_TargetVehicleSpeedHi;/* Variable: kfACCS_v_TargetVehicleSpeedHi
                                               * Referenced by: '<S17>/Saturation'
                                               * The max target speed will limit by this calibration
                                               */
extern real32_T kfACCS_v_TargetVehicleSpeedLo;/* Variable: kfACCS_v_TargetVehicleSpeedLo
                                               * Referenced by: '<S17>/Saturation'
                                               * The min target speed limit by this calibration
                                               */
extern uint32_T KfACCS_t_MaxTimeStampDiff;/* Variable: KfACCS_t_MaxTimeStampDiff
                                           * Referenced by:
                                           *   '<S33>/Constant1'
                                           *   '<S33>/Constant6'
                                           * This is the max acceptatble time difference between OBFU and EGMO
                                           */
extern uint8_T KcACCS_TimeStampErrLimit;/* Variable: KcACCS_TimeStampErrLimit
                                         * Referenced by:
                                         *   '<S33>/Constant12'
                                         *   '<S33>/Constant15'
                                         * This is the counter value for detect OBFU and EGMO error. If the EGMO's time
                                           stamp or OBFU's time stamp does not change for this loops, ACCS will enter
                                           standby.
                                         */
extern uint8_T KeACCS_CalFaultTypeOnlyForTest;/* Variable: KeACCS_CalFaultTypeOnlyForTest
                                               * Referenced by: '<S6>/Constant4'
                                               * This is only for logic test
                                               */
extern uint8_T KeACCS_DriverMode_AllowACCSNum;/* Variable: KeACCS_DriverMode_AllowACCSNum
                                               * Referenced by: '<S148>/Constant47'
                                               * This is only for logic test.Please hold the default value
                                               */
extern uint8_T KeACCS_GearDriveNum;    /* Variable: KeACCS_GearDriveNum
                                        * Referenced by: '<S148>/Constant45'
                                        * The cal need equal to the D gear value from Can bus
                                          At current period, it is only for logic test
                                        */
extern uint8_T KeACCS_OutPutControlSignal;/* Variable: KeACCS_OutPutControlSignal
                                           * Referenced by:
                                           *   '<S113>/Constant'
                                           *   '<S114>/Constant'
                                           * 0:Acceleration
                                             1:Torq
                                           */
extern uint8_T KeACCS_RRCalMetdType;   /* Variable: KeACCS_RRCalMetdType
                                        * Referenced by:
                                        *   '<S44>/Constant30'
                                        *   '<S68>/Constant30'
                                        *   '<S75>/Constant30'
                                        *   '<S82>/Constant30'
                                        *   '<S89>/Constant30'
                                        *   '<S96>/Constant30'
                                        * 0:Frist cal delta V_x and delta V_y, then cal range rate
                                          1:Directly use CIPV speed sub Ego speed
                                        */
extern uint8_T KeACCS_TargetRangeCalType;/* Variable: KeACCS_TargetRangeCalType
                                          * Referenced by: '<S34>/KeACCS_TargetRangeCalType'
                                          * 0:Use lookup table KtACCS_d_CIPVTargtRange
                                            1: Use CIPV velocity * Timegap
                                          */
extern uint8_T KeACCS_VehicleSpeedSource;/* Variable: KeACCS_VehicleSpeedSource
                                          * Referenced by:
                                          *   '<S9>/Constant'
                                          *   '<S9>/Constant1'
                                          * 0:Vehicle speed from EGMO
                                            1:Vehicle speed from Can bus
                                          */
extern boolean_T KbACCS_AEBStateFrmCal;/* Variable: KbACCS_AEBStateFrmCal
                                        * Referenced by: '<S16>/Constant11'
                                        * This cal is only for logic Test.Ture: AEB active for ACC,False: AEB inactive for ACC.
                                        */
extern boolean_T KbACCS_AllowEnterStopDueToCIP;/* Variable: KbACCS_AllowEnterStopDueToCIP
                                                * Referenced by: '<S150>/Constant45'
                                                * Ture£º Allow enter stop from temp stop due to obstacle
                                                */
extern boolean_T KbACCS_AllowOnToStop; /* Variable: KbACCS_AllowOnToStop
                                        * Referenced by: '<S150>/Constant25'
                                        * True: Allow enable ACC during vehicle speed=0
                                        */
extern boolean_T KbACCS_CalCIPV_FlickState;/* Variable: KbACCS_CalCIPV_FlickState
                                            * Referenced by: '<S16>/Constant1'
                                            * This cal is only for logic Test.True: Object fick, Run status woudle from following ctrl to Speeed ctrl
                                            */
extern boolean_T KbACCS_CalDriverSetSpeed;/* Variable: KbACCS_CalDriverSetSpeed
                                           * Referenced by: '<S34>/KbACCS_CalDriverSetSpeed'
                                           * True: Driver set speed is from calibration KfACCS_CalDriverSetSpeed.
                                             False: Driver set speed is from can.
                                           */
extern boolean_T KbACCS_CalFaultTypeOnlyForTest;/* Variable: KbACCS_CalFaultTypeOnlyForTest
                                                 * Referenced by: '<S6>/Constant2'
                                                 * This cal is only for logic Test.True: Has fault to ACCS.
                                                 */
extern boolean_T KbACCS_CalTimeGap;    /* Variable: KbACCS_CalTimeGap
                                        * Referenced by: '<S34>/KbACCS_CalTimeGap'
                                        * True: Time gap is from calibration kfACCS_TimeGapToCalcRange.
                                          False: Time gap is from can.
                                        */
extern boolean_T KbACCS_CancelSwitch;  /* Variable: KbACCS_CancelSwitch
                                        * Referenced by: '<S34>/Constant1'
                                        * True: Cancel switch is set.

                                        */
extern boolean_T KbACCS_ConsiderSIPVforACC;/* Variable: KbACCS_ConsiderSIPVforACC
                                            * Referenced by: '<S106>/Constant'
                                            * True:Will consider CIPV and SIPV as calculating acceleration.
                                              At current period, please hold False
                                            */
extern boolean_T KbACCS_ConsiderWithEPB;/* Variable: KbACCS_ConsiderWithEPB
                                         * Referenced by: '<S7>/Constant1'
                                         * 0: EPB allways Release status;
                                           1: Will use real EPB signal
                                         */
extern boolean_T KbACCS_ConsiderWithoutGear;/* Variable: KbACCS_ConsiderWithoutGear
                                             * Referenced by: '<S148>/Constant23'
                                             * 0: Will consider Gear, only D can enable ACCS control;
                                               1: Will bypass Gear conditions.
                                             */
extern boolean_T KbACCS_DirectlyUsePedalToJudgeOverride;/* Variable: KbACCS_DirectlyUsePedalToJudgeOverride
                                                         * Referenced by: '<S148>/Constant24'
                                                         * Ture:Use KfACCS_Pct_GasPedalOverrideThrsh to judge gas pedal override;
                                                           Flase:Use desird torq pct to judge gas pedal override
                                                         */
extern boolean_T KbACCS_DriverDoorBeltState;/* Variable: KbACCS_DriverDoorBeltState
                                             * Referenced by: '<S7>/Constant5'
                                             * Ture:Door and belt is engaged
                                               False:Door open
                                               This is only for logic test
                                             */
extern boolean_T KbACCS_EgoPitchTransfer;/* Variable: KbACCS_EgoPitchTransfer
                                          * Referenced by: '<S9>/Constant4'
                                          * If this calibration value is true, the ego pitch from EGMO will be producted -1.
                                          */
extern boolean_T KbACCS_EnableLowSpeedCtrl;/* Variable: KbACCS_EnableLowSpeedCtrl
                                            * Referenced by:
                                            *   '<S150>/Constant10'
                                            *   '<S150>/Constant3'
                                            * True:Allow Low speed ctrl
                                            */
extern boolean_T KbACCS_EnblAccelerationRamp;/* Variable: KbACCS_EnblAccelerationRamp
                                              * Referenced by: '<S103>/Constant10'
                                              * Ture: Enable desired acceleration ramp
                                              */
extern boolean_T KbACCS_EnblSlopeOfst; /* Variable: KbACCS_EnblSlopeOfst
                                        * Referenced by: '<S103>/Constant3'
                                        * True:Will consider with pitch as calculation acceleration.
                                        */
extern boolean_T KbACCS_ForceExitStandby;/* Variable: KbACCS_ForceExitStandby
                                          * Referenced by:
                                          *   '<S148>/Constant18'
                                          *   '<S148>/Constant19'
                                          * This is only for test
                                            If Ture, force exit standby mode
                                          */
extern boolean_T KbACCS_IgnoreOBFUTimeStampBug;/* Variable: KbACCS_IgnoreOBFUTimeStampBug
                                                * Referenced by:
                                                *   '<S33>/Constant16'
                                                *   '<S33>/Constant17'
                                                * This is the calibration to avoid OBFU bug's infuluence
                                                */
extern boolean_T KbACCS_IgnoreTimeStampError;/* Variable: KbACCS_IgnoreTimeStampError
                                              * Referenced by: '<S33>/Constant2'
                                              * This calibration can close time stamp diagnose function
                                              */
extern boolean_T KbACCS_MainSwitch;    /* Variable: KbACCS_MainSwitch
                                        * Referenced by: '<S34>/Constant'
                                        * Ture:Main switch is on
                                        */
extern boolean_T KbACCS_NotAllowEnterStandbyForUSDemo;/* Variable: KbACCS_NotAllowEnterStandbyForUSDemo
                                                       * Referenced by:
                                                       *   '<S16>/Constant40'
                                                       *   '<S148>/Constant40'
                                                       *   '<S150>/Constant40'
                                                       * This calibration is only for US demo.US demo should set 1;Other normal project should hold the default value 0.
                                                       */
extern boolean_T KbACCS_ResumeSwitch;  /* Variable: KbACCS_ResumeSwitch
                                        * Referenced by: '<S34>/Constant3'
                                        * True:Resume switch is set
                                        */
extern boolean_T KbACCS_UseACCFromRadar;/* Variable: KbACCS_UseACCFromRadar
                                         * Referenced by: '<S44>/Constant1'
                                         * 0£º The accelatration value is from radar
                                           1: The accelaration value is from the differentiation of obstacle's velocity
                                         */
extern boolean_T KbACCS_UseCIPVAccelToCalOpenAccel;/* Variable: KbACCS_UseCIPVAccelToCalOpenAccel
                                                    * Referenced by: '<S24>/Constant'
                                                    * True: Directly use CIPV acceleration as open acceleration
                                                    */
extern boolean_T KbACCS_UseIgnoreObsFcn;/* Variable: KbACCS_UseIgnoreObsFcn
                                         * Referenced by: '<S49>/Constant6'
                                         * This calibration will decide whether to use this function that ignore stationary vehicle.
                                         */
extern boolean_T KbACCS_UseStopStatus_Accel;/* Variable: KbACCS_UseStopStatus_Accel
                                             * Referenced by: '<S103>/Constant4'
                                             * True:Set accel to the calibration during stop mode
                                             */
extern boolean_T KbACCS_UseVirtualObject;/* Variable: KbACCS_UseVirtualObject
                                          * Referenced by:
                                          *   '<S39>/Constant36'
                                          *   '<S39>/Constant38'
                                          *   '<S39>/Constant41'
                                          *   '<S39>/Constant44'
                                          *   '<S40>/Constant36'
                                          *   '<S40>/Constant38'
                                          *   '<S40>/Constant41'
                                          *   '<S40>/Constant44'
                                          *   '<S41>/Constant36'
                                          *   '<S41>/Constant38'
                                          *   '<S41>/Constant41'
                                          *   '<S41>/Constant44'
                                          *   '<S42>/Constant36'
                                          *   '<S42>/Constant38'
                                          *   '<S42>/Constant41'
                                          *   '<S42>/Constant44'
                                          *   '<S43>/Constant36'
                                          *   '<S43>/Constant38'
                                          *   '<S43>/Constant41'
                                          *   '<S43>/Constant44'
                                          * This is noly for logic test.
                                            True: Use virtual object.
                                            False: Use the actual object.

                                          */
extern boolean_T KbACCS_UseVirtualPedal;/* Variable: KbACCS_UseVirtualPedal
                                         * Referenced by: '<S7>/Constant12'
                                         * This is only for test
                                           If Ture,the gas pedal is from the calibration KfACCS_Pct_VirtualGasPedal
                                         */
extern boolean_T KbACCS_UseVitualDCSNInfo;/* Variable: KbACCS_UseVitualDCSNInfo
                                           * Referenced by:
                                           *   '<S8>/Constant'
                                           *   '<S8>/Constant4'
                                           *   '<S8>/Constant5'
                                           * This is only for test
                                             True: Use virtula information, not from DCSN
                                           */
extern boolean_T KbACCS_VitualStopReqFrmDCSN;/* Variable: KbACCS_VitualStopReqFrmDCSN
                                              * Referenced by: '<S8>/Constant2'
                                              * This is only for test.
                                                True: Stop request is true
                                              */

/* Model entry point functions */
extern void ACCS_subsystem_integrated_initialize(void);
extern void ACCS_subsystem_integrated_step(void);

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
 * '<Root>' : 'ACCS_subsystem_integrated'
 * '<S1>'   : 'ACCS_subsystem_integrated/ACCS'
 * '<S2>'   : 'ACCS_subsystem_integrated/Model Info'
 * '<S3>'   : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_Input'
 * '<S4>'   : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic'
 * '<S5>'   : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_Output'
 * '<S6>'   : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_Input/CheckACCS_FaultState'
 * '<S7>'   : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_Input/DtrmnACCS_CAN_Information'
 * '<S8>'   : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_Input/DtrmnACCS_DCSNInformation'
 * '<S9>'   : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_Input/DtrmnACCS_EGMOInformation'
 * '<S10>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_Input/DtrmnACCS_MPFUInformation'
 * '<S11>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_Input/DtrmnACCS_MPFUInformation/LaneInfo'
 * '<S12>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_Input/DtrmnACCS_MPFUInformation/LaneMark'
 * '<S13>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm'
 * '<S14>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert'
 * '<S15>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq'
 * '<S16>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger'
 * '<S17>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/CalcACCS_EgoVehicleTargetSpeed'
 * '<S18>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/CalcACCS_OpenAccel'
 * '<S19>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/DtrmnACCS_AccelAndSpdLimit'
 * '<S20>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/CalcACCS_EgoVehicleTargetSpeed/If Action Subsystem'
 * '<S21>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/CalcACCS_EgoVehicleTargetSpeed/If Action Subsystem1'
 * '<S22>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/CalcACCS_EgoVehicleTargetSpeed/If Action Subsystem3'
 * '<S23>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/CalcACCS_EgoVehicleTargetSpeed/If Action Subsystem4'
 * '<S24>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/CalcACCS_OpenAccel/If Action Subsystem'
 * '<S25>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/CalcACCS_OpenAccel/If Action Subsystem1'
 * '<S26>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/CalcACCS_OpenAccel/If Action Subsystem2'
 * '<S27>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/CalcACCS_OpenAccel/If Action Subsystem3'
 * '<S28>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/CalcACCS_OpenAccel/If Action Subsystem4'
 * '<S29>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/DtrmnACCS_AccelAndSpdLimit/DtrmnACCS_AccelLimFromComfort'
 * '<S30>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/DtrmnACCS_AccelAndSpdLimit/DtrmnACCS_AccelLimFromEconomy'
 * '<S31>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/DtrmnACCS_AccelAndSpdLimit/DtrmnACCS_AccelLimFromSafty'
 * '<S32>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_DsrdLonControlParm/DtrmnACCS_AccelAndSpdLimit/DtrmnACCS_SpeedLim'
 * '<S33>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/Data diagnosis'
 * '<S34>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_EgoStatusFrmCan'
 * '<S35>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion'
 * '<S36>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_ObstacleExtraction'
 * '<S37>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject'
 * '<S38>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV'
 * '<S39>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVL'
 * '<S40>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVR'
 * '<S41>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_F'
 * '<S42>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_L'
 * '<S43>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_R'
 * '<S44>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Calculate Obs Motion State '
 * '<S45>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Calculate Obs Range'
 * '<S46>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Detect Obs Change Status'
 * '<S47>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Detect Obs Flicker Status'
 * '<S48>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/DtrmCIPVOutput'
 * '<S49>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Stationary target processing'
 * '<S50>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Calculate Obs Motion State /FirstFilter1'
 * '<S51>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Calculate Obs Motion State /FirstFilter2'
 * '<S52>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Calculate Obs Motion State /FirstFilter4'
 * '<S53>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Calculate Obs Range/FirstFilter'
 * '<S54>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Calculate Obs Range/FirstFilter1'
 * '<S55>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Detect Obs Change Status/Dtrmn_CIPVChangedType'
 * '<S56>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Detect Obs Change Status/Dtrmn_CIPVChangedTypeCond'
 * '<S57>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Detect Obs Change Status/Dtrmn_CIPVChangedTypeCond/ACCS_Ondelay2'
 * '<S58>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Detect Obs Change Status/Dtrmn_CIPVChangedTypeCond/IgnoreChagnedStatus'
 * '<S59>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/Detect Obs Flicker Status/Chart'
 * '<S60>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/DtrmCIPVOutput/Subsystem1'
 * '<S61>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/DtrmCIPVOutput/Subsystem2'
 * '<S62>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/DtrmCIPVOutput/Subsystem3'
 * '<S63>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/DtrmCIPVOutput/Subsystem4'
 * '<S64>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/DtrmCIPVOutput/Subsystem5'
 * '<S65>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/DtrmCIPVOutput/Subsystem6'
 * '<S66>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/DtrmCIPVOutput/Subsystem7'
 * '<S67>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPV/DtrmCIPVOutput/Subsystem8'
 * '<S68>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVL/Calculate Obs Motion State '
 * '<S69>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVL/Calculate Obs Range'
 * '<S70>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVL/Calculate Obs Motion State /FirstFilter'
 * '<S71>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVL/Calculate Obs Motion State /FirstFilter1'
 * '<S72>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVL/Calculate Obs Motion State /FirstFilter2'
 * '<S73>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVL/Calculate Obs Range/FirstFilter'
 * '<S74>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVL/Calculate Obs Range/FirstFilter1'
 * '<S75>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVR/Calculate Obs Motion State '
 * '<S76>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVR/Calculate Obs Range'
 * '<S77>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVR/Calculate Obs Motion State /FirstFilter'
 * '<S78>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVR/Calculate Obs Motion State /FirstFilter1'
 * '<S79>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVR/Calculate Obs Motion State /FirstFilter2'
 * '<S80>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVR/Calculate Obs Range/FirstFilter'
 * '<S81>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/CIPVR/Calculate Obs Range/FirstFilter1'
 * '<S82>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_F/Calculate Obs Motion State '
 * '<S83>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_F/Calculate Obs Range'
 * '<S84>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_F/Calculate Obs Motion State /FirstFilter'
 * '<S85>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_F/Calculate Obs Motion State /FirstFilter1'
 * '<S86>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_F/Calculate Obs Motion State /FirstFilter2'
 * '<S87>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_F/Calculate Obs Range/FirstFilter'
 * '<S88>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_F/Calculate Obs Range/FirstFilter1'
 * '<S89>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_L/Calculate Obs Motion State '
 * '<S90>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_L/Calculate Obs Range'
 * '<S91>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_L/Calculate Obs Motion State /FirstFilter'
 * '<S92>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_L/Calculate Obs Motion State /FirstFilter1'
 * '<S93>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_L/Calculate Obs Motion State /FirstFilter2'
 * '<S94>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_L/Calculate Obs Range/FirstFilter'
 * '<S95>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_L/Calculate Obs Range/FirstFilter1'
 * '<S96>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_R/Calculate Obs Motion State '
 * '<S97>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_R/Calculate Obs Range'
 * '<S98>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_R/Calculate Obs Motion State /FirstFilter'
 * '<S99>'  : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_R/Calculate Obs Motion State /FirstFilter1'
 * '<S100>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_R/Calculate Obs Motion State /FirstFilter2'
 * '<S101>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_R/Calculate Obs Range/FirstFilter'
 * '<S102>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_InputSignalConvert/DtrmnACCS_TargetsSecletion/DtrmnACCS_TargetObject/obs_R/Calculate Obs Range/FirstFilter1'
 * '<S103>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/ClacACCS_DsrdLonAccel'
 * '<S104>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl'
 * '<S105>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_RangeCtrlPID'
 * '<S106>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_SpeedCtrlPID'
 * '<S107>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/ClacACCS_DsrdLonAccel/DtrmnACCS_Acceleration_Ramp'
 * '<S108>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/ClacACCS_DsrdLonAccel/FirstFilter'
 * '<S109>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/ClacACCS_DsrdLonAccel/FirstFilter1'
 * '<S110>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/ClacACCS_DsrdLonAccel/DtrmnACCS_Acceleration_Ramp/CalcACCS_RampAcceleration'
 * '<S111>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/ClacACCS_DsrdLonAccel/DtrmnACCS_Acceleration_Ramp/CalcACCS_RampStep'
 * '<S112>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/ClacACCS_DsrdLonAccel/DtrmnACCS_Acceleration_Ramp/CalcACCS_RampStep/MATLAB Function'
 * '<S113>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalAccelReq'
 * '<S114>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalTorqReq'
 * '<S115>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalAccelReq/DtrmnACCS_AccelCtrlDer'
 * '<S116>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalAccelReq/DtrmnACCS_AccelCtrlInt'
 * '<S117>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalAccelReq/DtrmnACCS_AccelCtrlProp'
 * '<S118>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalAccelReq/DtrmnACCS_AccelCtrlInt/DtrmnACCS_AccelCtrlPIDInt_Freeze'
 * '<S119>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalAccelReq/DtrmnACCS_AccelCtrlInt/DtrmnACCS_AccelCtrlPIDInt_Reset'
 * '<S120>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalAccelReq/DtrmnACCS_AccelCtrlInt/UpdateACCS_AccelCtrlPIDInt'
 * '<S121>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalTorqReq/DtrmnACCS_TorqCtrlDer'
 * '<S122>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalTorqReq/DtrmnACCS_TorqCtrlInt'
 * '<S123>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalTorqReq/DtrmnACCS_TorqCtrlProp'
 * '<S124>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalTorqReq/DtrmnACCS_TorqCtrlInt/DtrmnACCS_TorqCtrlPIDInt_Freeze'
 * '<S125>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalTorqReq/DtrmnACCS_TorqCtrlInt/DtrmnACCS_TorqCtrlPIDInt_Reset'
 * '<S126>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_ActuaorControl/CalcACCS_FinalTorqReq/DtrmnACCS_TorqCtrlInt/UpdateACCS_TorqCtrlPIDInt'
 * '<S127>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_RangeCtrlPID/DtrmnACCS_RangCtrlDer'
 * '<S128>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_RangeCtrlPID/DtrmnACCS_RangCtrlInt'
 * '<S129>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_RangeCtrlPID/DtrmnACCS_RangeCtrlProp'
 * '<S130>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_SpeedCtrlPID/DtrmnACCS_SpeedCtrlDer'
 * '<S131>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_SpeedCtrlPID/DtrmnACCS_SpeedCtrlInt'
 * '<S132>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_SpeedCtrlPID/DtrmnACCS_SpeedCtrlProp'
 * '<S133>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_SpeedCtrlPID/DtrmnACCS_SpeedCtrlInt/DtrmnACCS_SpeedCtrlPIDInt_Freeze'
 * '<S134>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_SpeedCtrlPID/DtrmnACCS_SpeedCtrlInt/DtrmnACCS_SpeedCtrlPIDInt_Reset'
 * '<S135>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_Lon_AccelOrTorq/DtrmnACCS_SpeedCtrlPID/DtrmnACCS_SpeedCtrlInt/UpdateACCS_SpeedCtrlPIDInt'
 * '<S136>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_FaultState'
 * '<S137>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_ModeState'
 * '<S138>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_RunStatus'
 * '<S139>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_FaultState/If Action Subsystem'
 * '<S140>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_FaultState/If Action Subsystem1'
 * '<S141>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_FaultState/If Action Subsystem2'
 * '<S142>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_FaultState/If Action Subsystem3'
 * '<S143>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_FaultState/If Action Subsystem4'
 * '<S144>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_FaultState/If Action Subsystem5'
 * '<S145>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_FaultState/If Action Subsystem6'
 * '<S146>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_FaultState/If Action Subsystem8'
 * '<S147>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_ModeState/DtrmnACCS_ModeStateTransfer'
 * '<S148>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_ModeState/DtrmnACCS_ModeTransferConds'
 * '<S149>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_RunStatus/DtrmnACCS_RunStatusTransfer'
 * '<S150>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_RunStatus/DtrmnACCS_StatusTransferConds'
 * '<S151>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_RunStatus/DtrmnACCS_StatusTransferConds/ACCS_Ondelay'
 * '<S152>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_RunStatus/DtrmnACCS_StatusTransferConds/ACCS_Ondelay1'
 * '<S153>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_RunStatus/DtrmnACCS_StatusTransferConds/ACCS_Ondelay2'
 * '<S154>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_RunStatus/DtrmnACCS_StatusTransferConds/ACCS_Ondelay3'
 * '<S155>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_RunStatus/DtrmnACCS_StatusTransferConds/DtrmnACCS_WhetherDriverInputDuringStop'
 * '<S156>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_RunStatus/DtrmnACCS_StatusTransferConds/DtrmnACCS_WhetherDriverInputDuringStop/DtrmnACCS_WhetherPressGasPedal'
 * '<S157>' : 'ACCS_subsystem_integrated/ACCS/DtrmnACCS_MainLogic/DtrmnACCS_ModeManger/DtrmnACCS_RunStatus/DtrmnACCS_StatusTransferConds/DtrmnACCS_WhetherDriverInputDuringStop/DtrmnACCS_WhetherPressResume'
 */
#endif                                 /* RTW_HEADER_ACCS_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
