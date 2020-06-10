/*
 * File: BSDS_subsystem_integrated.h
 *
 * Code generated for Simulink model 'BSDS_subsystem_integrated'.
 *
 * Model version                  : 1.461
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Jun  8 17:01:06 2020
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

#ifndef RTW_HEADER_BSDS_subsystem_integrated_h_
#define RTW_HEADER_BSDS_subsystem_integrated_h_
#include <math.h>
#include <string.h>
#ifndef BSDS_subsystem_integrated_COMMON_INCLUDES_
# define BSDS_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* BSDS_subsystem_integrated_COMMON_INCLUDES_ */

#include "BSDS_subsystem_integrated_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct
{
  real32_T vec_L[220];                 /* '<S20>/Data Type Conversion' */
  real32_T vec_R[220];                 /* '<S20>/Data Type Conversion1' */
  int32_T bswR_ID;                     /* '<S3>/CalcRBSWFunction' */
  int32_T bswL_ID;                     /* '<S2>/Calc_LBSWFunction' */
  uint16_T num_L;                      /* '<S20>/CvrtObtVecFunction' */
  uint16_T num_R;                      /* '<S20>/CvrtObtVecFunction' */
  boolean_T enable;                    /* '<S4>/DtmnChart' */
  EnumBSDS_Active_Status active_status;/* '<S4>/DtmnChart' */
  EnumBSDS_Warning_Status right_warning_status;/* '<S3>/DtmnWarningChart' */
  EnumBSDS_Warning_Status left_warning_status;/* '<S2>/DtmnWarningChart' */
}
B_BSDS_subsystem_integrated_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
  int32_T DataTypeConversion_DIMS1[2]; /* '<S20>/Data Type Conversion' */
  int32_T DataTypeConversion1_DIMS1[2];/* '<S20>/Data Type Conversion1' */
  int32_T SFunction_DIMS2[2];          /* '<S20>/CvrtObtVecFunction' */
  int32_T SFunction_DIMS3[2];          /* '<S20>/CvrtObtVecFunction' */
  uint32_T temporalCounter_i1;         /* '<S3>/DtmnWarningChart' */
  uint32_T previousTicks;              /* '<S3>/DtmnWarningChart' */
  uint32_T temporalCounter_i1_hmm3;    /* '<S2>/DtmnWarningChart' */
  uint32_T previousTicks_mdx3;         /* '<S2>/DtmnWarningChart' */
  uint8_T is_c3_BSDS_subsystem_integrated;/* '<S4>/DtmnChart' */
  uint8_T is_NoError;                  /* '<S4>/DtmnChart' */
  uint8_T is_On;                       /* '<S4>/DtmnChart' */
  uint8_T is_c4_BSDS_subsystem_integrated;/* '<S3>/DtmnWarningChart' */
  uint8_T is_UnSafe;                   /* '<S3>/DtmnWarningChart' */
  uint8_T is_c12_BSDS_subsystem_integrate;/* '<S2>/DtmnWarningChart' */
  uint8_T is_UnSafe_jdaq;              /* '<S2>/DtmnWarningChart' */
  boolean_T CvrtObtVecFunctionEnabled_MODE;/* '<S5>/CvrtObtVecFunctionEnabled' */
  boolean_T DtmnEnabledSubsystem_MODE; /* '<S1>/DtmnEnabledSubsystem' */
  boolean_T CalcRBSDEnabledSubsystem_MODE;/* '<S1>/CalcRBSDEnabledSubsystem' */
  boolean_T CalcLBSDEnabledSubsystem_MODE;/* '<S1>/CalcLBSDEnabledSubsystem' */
}
DW_BSDS_subsystem_integrated_T;

/* Real-time Model Data Structure */
struct tag_RTM_BSDS_subsystem_integr_T
{
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct
  {
    uint32_T clockTick0;
    uint32_T clockTickH0;
  }
  Timing;
};

/* Block signals (auto storage) */
extern B_BSDS_subsystem_integrated_T BSDS_subsystem_integrated_B;

/* Block states (auto storage) */
extern DW_BSDS_subsystem_integrated_T BSDS_subsystem_integrated_DW;

/* External data declarations for dependent source files */
extern const BSDS_DataBus BSDS_subsystem_integrated_rtZBSDS_DataBus;/* BSDS_DataBus ground */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern BSDS_DataBus VsBSDS_DataBus;    /* '<S6>/Bus_Creator' */
extern real32_T VfBSDS_curvature;      /* '<S19>/Gain2' */
extern real32_T VfBSDS_speed_in;       /* '<S19>/Gain1' */
extern real32_T VfBSDS_veh_vx;         /* '<S20>/Gain4' */
extern real32_T VaLCWS_Obt[33];        /* '<S20>/ObserveObtVecFunction2' */
extern real32_T VaLCWS_x_in[10];       /* '<S20>/ObserveObtVecFunction' */
extern real32_T VaLCWS_y_in[10];       /* '<S20>/ObserveObtVecFunction' */
extern real32_T VaLCWS_heading_in[10]; /* '<S20>/ObserveObtVecFunction' */
extern real32_T VaLCWS_Vx_in[10];      /* '<S20>/ObserveObtVecFunction' */
extern real32_T VaLCWS_Vy_in[10];      /* '<S20>/ObserveObtVecFunction' */
extern real32_T VaLCWS_obt_lenth_in[10];/* '<S20>/ObserveObtVecFunction' */
extern real32_T VaLCWS_obt_width_in[10];/* '<S20>/ObserveObtVecFunction' */
extern real32_T VaLCWS_nearest_point_rel_x_in[10];/* '<S20>/ObserveObtVecFunction' */
extern real32_T VaLCWS_nearest_point_rel_y_in[10];/* '<S20>/ObserveObtVecFunction' */
extern int32_T VaLCWS_id_in[10];       /* '<S20>/ObserveObtVecFunction' */
extern int32_T ViBSDS_bswR_ID;         /* '<S3>/Gain2' */
extern int32_T ViBSDS_bswL_ID;         /* '<S2>/Gain' */
extern uint16_T VnLCWS_num_R;          /* '<S20>/Gain1' */
extern uint16_T VnLCWS_num_L;          /* '<S20>/Gain2' */
extern uint16_T VnLCWS_num_in;         /* '<S20>/Gain3' */
extern int8_T VaLCWS_position_zone_in[10];/* '<S20>/ObserveObtVecFunction' */
extern int8_T VaLCWS_orientation_in[10];/* '<S20>/ObserveObtVecFunction' */
extern int8_T VaLCWS_motion_status_in[10];/* '<S20>/ObserveObtVecFunction' */
extern uint8_T VfBSDS_gear_in;         /* '<S19>/Gain3' */
extern uint8_T VaLCWS_type_in[10];     /* '<S20>/ObserveObtVecFunction' */
extern uint8_T ViBSDS_bswR;            /* '<S3>/Gain3' */
extern uint8_T ViBSDS_bswL;            /* '<S2>/Gain2' */
extern boolean_T VeBSDS_LturnON;       /* '<S19>/Rate Transition2' */
extern boolean_T VeBSDS_RturnON;       /* '<S19>/Rate Transition1' */
extern EnumBSDS_Active_Status VeBSDS_active_status;/* '<S6>/Rate Transition2' */
extern EnumBSDS_Warning_Status VeBSDS_right_warning_status_out;/* '<S6>/Rate Transition1' */
extern EnumBSDS_Warning_Status VeBSDS_left_warning_status_out;/* '<S6>/Rate Transition' */
extern EnumBSDS_Warning_Status VeBSDS_right_warning_status;/* '<S3>/Rate Transition' */
extern EnumBSDS_Warning_Status VeBSDS_left_warning_status;/* '<S2>/Rate Transition' */
extern EnumBSDS_warningArea ViBSDS_bswLL;/* '<S2>/Rate Transition1' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T KfBSDS_Ang_DisbleStrAngleThrshMax;/* Variable: KfBSDS_Ang_DisbleStrAngleThrshMax
                                                   * Referenced by: '<S18>/Constant12'
                                                   */
extern real32_T KfBSDS_Ang_EnbleStrAngleThrshMax;/* Variable: KfBSDS_Ang_EnbleStrAngleThrshMax
                                                  * Referenced by: '<S18>/Constant11'
                                                  */
extern real32_T KfBSDS_c_DisbleCurveThrshMax;/* Variable: KfBSDS_c_DisbleCurveThrshMax
                                              * Referenced by: '<S18>/Constant20'
                                              */
extern real32_T KfBSDS_c_EnbleCurveThrshMax;/* Variable: KfBSDS_c_EnbleCurveThrshMax
                                             * Referenced by: '<S18>/Constant19'
                                             */
extern real32_T KfBSDS_d_BSDLargerZone_BackDis;/* Variable: KfBSDS_d_BSDLargerZone_BackDis
                                                * Referenced by: '<S18>/Constant9'
                                                */
extern real32_T KfBSDS_d_BSDLargerZone_FarDis;/* Variable: KfBSDS_d_BSDLargerZone_FarDis
                                               * Referenced by: '<S18>/Constant5'
                                               */
extern real32_T KfBSDS_d_BSDLargerZone_FrontDis;/* Variable: KfBSDS_d_BSDLargerZone_FrontDis
                                                 * Referenced by: '<S18>/Constant7'
                                                 */
extern real32_T KfBSDS_d_BSDLargerZone_NearDis;/* Variable: KfBSDS_d_BSDLargerZone_NearDis
                                                * Referenced by: '<S18>/Constant3'
                                                */
extern real32_T KfBSDS_d_BSDZone_BackDis;/* Variable: KfBSDS_d_BSDZone_BackDis
                                          * Referenced by: '<S18>/Constant8'
                                          */
extern real32_T KfBSDS_d_BSDZone_Eye95Dis;/* Variable: KfBSDS_d_BSDZone_Eye95Dis
                                           * Referenced by: '<S18>/Constant10'
                                           */
extern real32_T KfBSDS_d_BSDZone_FarDis;/* Variable: KfBSDS_d_BSDZone_FarDis
                                         * Referenced by: '<S18>/Constant4'
                                         */
extern real32_T KfBSDS_d_BSDZone_FrontDis;/* Variable: KfBSDS_d_BSDZone_FrontDis
                                           * Referenced by: '<S18>/Constant6'
                                           */
extern real32_T KfBSDS_d_BSDZone_NearDis;/* Variable: KfBSDS_d_BSDZone_NearDis
                                          * Referenced by: '<S18>/Constant2'
                                          */
extern real32_T KfBSDS_d_VehCenterFront;/* Variable: KfBSDS_d_VehCenterFront
                                         * Referenced by: '<S18>/Constant29'
                                         */
extern real32_T KfBSDS_d_VehCenterRear;/* Variable: KfBSDS_d_VehCenterRear
                                        * Referenced by: '<S18>/Constant28'
                                        */
extern real32_T KfBSDS_d_VehLenth;     /* Variable: KfBSDS_d_VehLenth
                                        * Referenced by: '<S18>/Constant'
                                        */
extern real32_T KfBSDS_d_VehWidth;     /* Variable: KfBSDS_d_VehWidth
                                        * Referenced by: '<S18>/Constant1'
                                        */
extern real32_T KfBSDS_r_ObtWidthProportion;/* Variable: KfBSDS_r_ObtWidthProportion
                                             * Referenced by: '<S18>/Constant25'
                                             */
extern real32_T KfBSDS_t_WarnSustainedTime;/* Variable: KfBSDS_t_WarnSustainedTime
                                            * Referenced by: '<S18>/Constant13'
                                            */
extern real32_T KfBSDS_v_DisbleVehSpdThrshHi;/* Variable: KfBSDS_v_DisbleVehSpdThrshHi
                                              * Referenced by: '<S18>/Constant27'
                                              */
extern real32_T KfBSDS_v_DisbleVehSpdThrshLo;/* Variable: KfBSDS_v_DisbleVehSpdThrshLo
                                              * Referenced by: '<S18>/Constant18'
                                              */
extern real32_T KfBSDS_v_EnbleVehSpdThrshHi;/* Variable: KfBSDS_v_EnbleVehSpdThrshHi
                                             * Referenced by: '<S18>/Constant26'
                                             */
extern real32_T KfBSDS_v_EnbleVehSpdThrshLo;/* Variable: KfBSDS_v_EnbleVehSpdThrshLo
                                             * Referenced by: '<S18>/Constant17'
                                             */
extern real32_T KfBSDS_v_LatSpdThr;    /* Variable: KfBSDS_v_LatSpdThr
                                        * Referenced by: '<S18>/Constant24'
                                        */
extern real32_T KfBSDS_v_OncomRelSpdThrshHi_in;/* Variable: KfBSDS_v_OncomRelSpdThrshHi_in
                                                * Referenced by: '<S18>/Constant22'
                                                */
extern real32_T KfBSDS_v_OncomRelSpdThrshHi_out;/* Variable: KfBSDS_v_OncomRelSpdThrshHi_out
                                                 * Referenced by: '<S18>/Constant23'
                                                 */
extern real32_T KfBSDS_v_staticSpdThr; /* Variable: KfBSDS_v_staticSpdThr
                                        * Referenced by: '<S18>/Constant14'
                                        */
extern boolean_T KbBSDS_Sensor_Error;  /* Variable: KbBSDS_Sensor_Error
                                        * Referenced by: '<S4>/Constant28'
                                        */
extern boolean_T KbBSDS_Sensor_Work;   /* Variable: KbBSDS_Sensor_Work
                                        * Referenced by: '<S4>/Constant3'
                                        */
extern boolean_T KbBSDS_Switch;        /* Variable: KbBSDS_Switch
                                        * Referenced by: '<S18>/Constant21'
                                        */
extern boolean_T KbBSDS_configBSD;     /* Variable: KbBSDS_configBSD
                                        * Referenced by: '<S18>/Constant30'
                                        */
extern boolean_T KbBSDS_curve;         /* Variable: KbBSDS_curve
                                        * Referenced by: '<S19>/Constant28'
                                        */

/* Model entry point functions */
extern void BSDS_subsystem_integrated_initialize(void);
extern void BSDS_subsystem_integrated_step(void);

/* Real-time Model object */
extern RT_MODEL_BSDS_subsystem_integ_T *const BSDS_subsystem_integrated_M;

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
 * '<Root>' : 'BSDS_subsystem_integrated'
 * '<S1>'   : 'BSDS_subsystem_integrated/BSDS_Subsystem'
 * '<S2>'   : 'BSDS_subsystem_integrated/BSDS_Subsystem/CalcLBSDEnabledSubsystem'
 * '<S3>'   : 'BSDS_subsystem_integrated/BSDS_Subsystem/CalcRBSDEnabledSubsystem'
 * '<S4>'   : 'BSDS_subsystem_integrated/BSDS_Subsystem/DtmnEnabledSubsystem'
 * '<S5>'   : 'BSDS_subsystem_integrated/BSDS_Subsystem/input_Subsystem'
 * '<S6>'   : 'BSDS_subsystem_integrated/BSDS_Subsystem/output_Subsystem'
 * '<S7>'   : 'BSDS_subsystem_integrated/BSDS_Subsystem/CalcLBSDEnabledSubsystem/Calc_LBSWFunction'
 * '<S8>'   : 'BSDS_subsystem_integrated/BSDS_Subsystem/CalcLBSDEnabledSubsystem/DtmnWarningChart'
 * '<S9>'   : 'BSDS_subsystem_integrated/BSDS_Subsystem/CalcRBSDEnabledSubsystem/CalcRBSWFunction'
 * '<S10>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/CalcRBSDEnabledSubsystem/DtmnWarningChart'
 * '<S11>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/DtmnEnabledSubsystem/Compare To Constant'
 * '<S12>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/DtmnEnabledSubsystem/Compare To Constant1'
 * '<S13>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/DtmnEnabledSubsystem/Compare To Zero'
 * '<S14>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/DtmnEnabledSubsystem/Compare To Zero1'
 * '<S15>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/DtmnEnabledSubsystem/Compare To Zero2'
 * '<S16>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/DtmnEnabledSubsystem/Compare To Zero3'
 * '<S17>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/DtmnEnabledSubsystem/DtmnChart'
 * '<S18>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/input_Subsystem/Calibration_Subsystem'
 * '<S19>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/input_Subsystem/CvrtInput_Subsystem'
 * '<S20>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/input_Subsystem/CvrtObtVecFunctionEnabled'
 * '<S21>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/input_Subsystem/CvrtInput_Subsystem/Compare To Constant'
 * '<S22>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/input_Subsystem/CvrtInput_Subsystem/Compare To Constant1'
 * '<S23>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/input_Subsystem/CvrtInput_Subsystem/Compare To Constant2'
 * '<S24>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/input_Subsystem/CvrtObtVecFunctionEnabled/CvrtObtVecFunction'
 * '<S25>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/input_Subsystem/CvrtObtVecFunctionEnabled/ObserveObtVecFunction'
 * '<S26>'  : 'BSDS_subsystem_integrated/BSDS_Subsystem/input_Subsystem/CvrtObtVecFunctionEnabled/ObserveObtVecFunction2'
 */

/*-
 * Requirements for '<Root>': BSDS_subsystem_integrated
 */
#endif                                 /* RTW_HEADER_BSDS_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
