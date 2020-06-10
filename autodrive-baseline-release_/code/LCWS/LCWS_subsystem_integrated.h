/*
 * File: LCWS_subsystem_integrated.h
 *
 * Code generated for Simulink model 'LCWS_subsystem_integrated'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Apr 26 21:11:09 2020
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

#ifndef RTW_HEADER_LCWS_subsystem_integrated_h_
#define RTW_HEADER_LCWS_subsystem_integrated_h_
#include <math.h>
#include <string.h>
#ifndef LCWS_subsystem_integrated_COMMON_INCLUDES_
# define LCWS_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LCWS_subsystem_integrated_COMMON_INCLUDES_ */

#include "LCWS_subsystem_integrated_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct
{
  real32_T vec_L[220];                 /* '<S22>/Data Type Conversion' */
  real32_T vec_R[220];                 /* '<S22>/Data Type Conversion1' */
  int32_T cvwR_ID;                     /* '<S3>/CalcRCVWFunction' */
  int32_T bswR_ID;                     /* '<S3>/CalcRBSWFunction' */
  int32_T cvwL_ID;                     /* '<S2>/Calc_LCVWFunction' */
  int32_T bswL_ID;                     /* '<S2>/Calc_LBSWFunction' */
  uint16_T num_L;                      /* '<S22>/Switch2' */
  uint16_T num_R;                      /* '<S22>/Switch3' */
  boolean_T warning_right1;            /* '<S3>/DtmnWarningChart' */
  boolean_T warning_right2;            /* '<S3>/DtmnWarningChart' */
  boolean_T warning_left1;             /* '<S2>/DtmnWarningChart' */
  boolean_T warning_left2;             /* '<S2>/DtmnWarningChart' */
  EnumLCWS_Warning_Status right_warning_status;/* '<S3>/DtmnWarningChart' */
  EnumLCWS_Warning_Status left_warning_status;/* '<S2>/DtmnWarningChart' */
}
B_LCWS_subsystem_integrated_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
  int32_T Switch_DIMS1[2];             /* '<S22>/Switch' */
  int32_T DataTypeConversion_DIMS1[2]; /* '<S22>/Data Type Conversion' */
  int32_T Switch1_DIMS1[2];            /* '<S22>/Switch1' */
  int32_T DataTypeConversion1_DIMS1[2];/* '<S22>/Data Type Conversion1' */
  int32_T SFunction_DIMS2[2];          /* '<S22>/CvrtObtVecFunction1' */
  int32_T SFunction_DIMS3[2];          /* '<S22>/CvrtObtVecFunction1' */
  int32_T SFunction_DIMS2_iirt[2];     /* '<S22>/CvrtObtVecFunction' */
  int32_T SFunction_DIMS3_domv[2];     /* '<S22>/CvrtObtVecFunction' */
  uint8_T is_c3_LCWS_subsystem_integrated;/* '<S4>/DtmnChart' */
  uint8_T is_On;                       /* '<S4>/DtmnChart' */
  uint8_T is_Positive;                 /* '<S4>/DtmnChart' */
  uint8_T is_c5_LCWS_subsystem_integrated;/* '<S3>/DtmnWarningChart' */
  uint8_T is_UnSafe;                   /* '<S3>/DtmnWarningChart' */
  uint8_T is_c4_LCWS_subsystem_integrated;/* '<S2>/DtmnWarningChart' */
  uint8_T is_UnSafe_pitt;              /* '<S2>/DtmnWarningChart' */
  boolean_T CvrtObtVecFunctionEnabled_MODE;/* '<S5>/CvrtObtVecFunctionEnabled' */
  boolean_T CalcRLCWEnabledSubsystem_MODE;/* '<S1>/CalcRLCWEnabledSubsystem' */
  boolean_T CalcLLCWEnabledSubsystem_MODE;/* '<S1>/CalcLLCWEnabledSubsystem' */
}
DW_LCWS_subsystem_integrated_T;

/* Block signals (auto storage) */
extern B_LCWS_subsystem_integrated_T LCWS_subsystem_integrated_B;

/* Block states (auto storage) */
extern DW_LCWS_subsystem_integrated_T LCWS_subsystem_integrated_DW;

/* External data declarations for dependent source files */
extern const LCWS_DataBus LCWS_subsystem_integrated_rtZLCWS_DataBus;/* LCWS_DataBus ground */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern LCWS_DataBus VsLCWS_DataBus;    /* '<S6>/Bus_Creator' */
extern real32_T VfLCWS_curvature;      /* '<S21>/Gain2' */
extern real32_T VfLCWS_speed_in;       /* '<S21>/Gain1' */
extern real32_T VaLCWS_Obt[33];        /* '<S22>/ObserveObtVecFunction2' */
extern real32_T VaLCWS_x_in[10];       /* '<S22>/ObserveObtVecFunction1' */
extern real32_T VaLCWS_y_in[10];       /* '<S22>/ObserveObtVecFunction1' */
extern real32_T VaLCWS_heading_in[10]; /* '<S22>/ObserveObtVecFunction1' */
extern real32_T VaLCWS_Vx_in[10];      /* '<S22>/ObserveObtVecFunction1' */
extern real32_T VaLCWS_Vy_in[10];      /* '<S22>/ObserveObtVecFunction1' */
extern real32_T VaLCWS_obt_lenth_in[10];/* '<S22>/ObserveObtVecFunction1' */
extern real32_T VaLCWS_obt_width_in[10];/* '<S22>/ObserveObtVecFunction1' */
extern real32_T VaLCWS_nearest_point_rel_x_in[10];/* '<S22>/ObserveObtVecFunction1' */
extern real32_T VaLCWS_nearest_point_rel_y_in[10];/* '<S22>/ObserveObtVecFunction1' */
extern int32_T VaLCWS_id_in[10];       /* '<S22>/ObserveObtVecFunction1' */
extern int32_T ViLCWS_bswR_ID;         /* '<S3>/Gain2' */
extern int32_T ViLCWS_cvwR_ID;         /* '<S3>/Gain1' */
extern int32_T ViLCWS_bswL_ID;         /* '<S2>/Gain' */
extern int32_T ViLCWS_cvwL_ID;         /* '<S2>/Gain1' */
extern uint16_T VnLCWS_num_L;          /* '<S22>/Gain2' */
extern uint16_T VnLCWS_num_R;          /* '<S22>/Gain1' */
extern uint16_T VnLCWS_num_in;         /* '<S22>/Gain3' */
extern int8_T VaLCWS_position_zone_in[10];/* '<S22>/ObserveObtVecFunction1' */
extern int8_T VaLCWS_orientation_in[10];/* '<S22>/ObserveObtVecFunction1' */
extern int8_T VaLCWS_motion_status_in[10];/* '<S22>/ObserveObtVecFunction1' */
extern uint8_T VfLCWS_gear_in;         /* '<S21>/Gain3' */
extern uint8_T VaLCWS_type[10];        /* '<S22>/ObserveObtVecFunction1' */
extern uint8_T ViLCWS_bswR;            /* '<S3>/Gain3' */
extern uint8_T ViLCWS_cvwR;            /* '<S3>/Gain4' */
extern uint8_T ViLCWS_bswL;            /* '<S2>/Gain2' */
extern uint8_T ViLCWS_cvwL;            /* '<S2>/Gain3' */
extern EnumLCWS_Active_Status VeLCWS_active_status;/* '<S4>/Rate Transition' */
extern EnumLCWS_Warning_Status VeLCWS_right_warning_status_out;/* '<S6>/Rate Transition1' */
extern EnumLCWS_Warning_Status VeLCWS_left_warning_status_out;/* '<S6>/Rate Transition' */
extern EnumLCWS_Warning_Status VeLCWS_right_warning_status;/* '<S3>/Rate Transition' */
extern EnumLCWS_Warning_Status VeLCWS_left_warning_status;/* '<S2>/Rate Transition' */
extern EnumLCWS_warningArea ViLCWS_bswLL;/* '<S2>/Rate Transition1' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T KfLCWS_c_DisbleCurveThrshMax;/* Variable: KfLCWS_c_DisbleCurveThrshMax
                                              * Referenced by: '<S20>/Constant20'
                                              */
extern real32_T KfLCWS_c_EnbleCurveThrshMax;/* Variable: KfLCWS_c_EnbleCurveThrshMax
                                             * Referenced by: '<S20>/Constant19'
                                             */
extern real32_T KfLCWS_d_BSDLargerZone_BackDis;/* Variable: KfLCWS_d_BSDLargerZone_BackDis
                                                * Referenced by: '<S20>/Constant9'
                                                */
extern real32_T KfLCWS_d_BSDLargerZone_FrontDis;/* Variable: KfLCWS_d_BSDLargerZone_FrontDis
                                                 * Referenced by: '<S20>/Constant7'
                                                 */
extern real32_T KfLCWS_d_BSDLargerZone_NearDis;/* Variable: KfLCWS_d_BSDLargerZone_NearDis
                                                * Referenced by: '<S20>/Constant3'
                                                */
extern real32_T KfLCWS_d_BSDZone_BackDis;/* Variable: KfLCWS_d_BSDZone_BackDis
                                          * Referenced by: '<S20>/Constant8'
                                          */
extern real32_T KfLCWS_d_BSDZone_Eye95Dis;/* Variable: KfLCWS_d_BSDZone_Eye95Dis
                                           * Referenced by: '<S20>/Constant10'
                                           */
extern real32_T KfLCWS_d_BSDZone_FarDis;/* Variable: KfLCWS_d_BSDZone_FarDis
                                         * Referenced by: '<S20>/Constant4'
                                         */
extern real32_T KfLCWS_d_BSDZone_FrontDis;/* Variable: KfLCWS_d_BSDZone_FrontDis
                                           * Referenced by: '<S20>/Constant6'
                                           */
extern real32_T KfLCWS_d_BSDZone_NearDis;/* Variable: KfLCWS_d_BSDZone_NearDis
                                          * Referenced by: '<S20>/Constant2'
                                          */
extern real32_T KfLCWS_d_CVLargerZone_FrontDis;/* Variable: KfLCWS_d_CVLargerZone_FrontDis
                                                * Referenced by: '<S20>/Constant12'
                                                */
extern real32_T KfLCWS_d_CVZone_FrontDis;/* Variable: KfLCWS_d_CVZone_FrontDis
                                          * Referenced by: '<S20>/Constant11'
                                          */
extern real32_T KfLCWS_d_NearDisHiLevel;/* Variable: KfLCWS_d_NearDisHiLevel
                                         * Referenced by: '<S20>/Constant16'
                                         */
extern real32_T KfLCWS_d_VehLenth;     /* Variable: KfLCWS_d_VehLenth
                                        * Referenced by: '<S20>/Constant'
                                        */
extern real32_T KfLCWS_d_VehWidth;     /* Variable: KfLCWS_d_VehWidth
                                        * Referenced by: '<S20>/Constant1'
                                        */
extern real32_T KfLCWS_r_ObtWidthProportion;/* Variable: KfLCWS_r_ObtWidthProportion
                                             * Referenced by: '<S20>/Constant25'
                                             */
extern real32_T KfLCWS_t_TTCLargerThrsh_LowLevel;/* Variable: KfLCWS_t_TTCLargerThrsh_LowLevel
                                                  * Referenced by: '<S20>/Constant14'
                                                  */
extern real32_T KfLCWS_t_TTCThrshHiLevel;/* Variable: KfLCWS_t_TTCThrshHiLevel
                                          * Referenced by: '<S20>/Constant15'
                                          */
extern real32_T KfLCWS_t_TTCThrshLowLevel;/* Variable: KfLCWS_t_TTCThrshLowLevel
                                           * Referenced by: '<S20>/Constant13'
                                           */
extern real32_T KfLCWS_v_DisbleVehSpdThrshHi;/* Variable: KfLCWS_v_DisbleVehSpdThrshHi
                                              * Referenced by: '<S20>/Constant27'
                                              */
extern real32_T KfLCWS_v_DisbleVehSpdThrshLo;/* Variable: KfLCWS_v_DisbleVehSpdThrshLo
                                              * Referenced by: '<S20>/Constant18'
                                              */
extern real32_T KfLCWS_v_EnbleVehSpdThrshHi;/* Variable: KfLCWS_v_EnbleVehSpdThrshHi
                                             * Referenced by: '<S20>/Constant26'
                                             */
extern real32_T KfLCWS_v_EnbleVehSpdThrshLo;/* Variable: KfLCWS_v_EnbleVehSpdThrshLo
                                             * Referenced by: '<S20>/Constant17'
                                             */
extern real32_T KfLCWS_v_LatSpdThr;    /* Variable: KfLCWS_v_LatSpdThr
                                        * Referenced by: '<S20>/Constant24'
                                        */
extern real32_T KfLCWS_v_OncomRelSpdThrshHi_in;/* Variable: KfLCWS_v_OncomRelSpdThrshHi_in
                                                * Referenced by: '<S20>/Constant22'
                                                */
extern real32_T KfLCWS_v_OncomRelSpdThrshHi_out;/* Variable: KfLCWS_v_OncomRelSpdThrshHi_out
                                                 * Referenced by: '<S20>/Constant23'
                                                 */
extern int8_T KfLCWS_d_BSDLargerZone_FarDis;/* Variable: KfLCWS_d_BSDLargerZone_FarDis
                                             * Referenced by: '<S20>/Constant5'
                                             */
extern boolean_T KbLCWS_ObtFilter;     /* Variable: KbLCWS_ObtFilter
                                        * Referenced by: '<S22>/Constant21'
                                        */
extern boolean_T KbLCWS_ObtStaticIn;   /* Variable: KbLCWS_ObtStaticIn
                                        * Referenced by: '<S22>/Constant28'
                                        */
extern boolean_T KbLCWS_Switch;        /* Variable: KbLCWS_Switch
                                        * Referenced by: '<S20>/Constant21'
                                        */
extern boolean_T KbLCWS_curve;         /* Variable: KbLCWS_curve
                                        * Referenced by: '<S21>/Constant28'
                                        */

/* Model entry point functions */
extern void LCWS_subsystem_integrated_initialize(void);
extern void LCWS_subsystem_integrated_step(void);

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
 * '<Root>' : 'LCWS_subsystem_integrated'
 * '<S1>'   : 'LCWS_subsystem_integrated/LCWS_Subsystem'
 * '<S2>'   : 'LCWS_subsystem_integrated/LCWS_Subsystem/CalcLLCWEnabledSubsystem'
 * '<S3>'   : 'LCWS_subsystem_integrated/LCWS_Subsystem/CalcRLCWEnabledSubsystem'
 * '<S4>'   : 'LCWS_subsystem_integrated/LCWS_Subsystem/Dtmn_Subsystem'
 * '<S5>'   : 'LCWS_subsystem_integrated/LCWS_Subsystem/input_Subsystem'
 * '<S6>'   : 'LCWS_subsystem_integrated/LCWS_Subsystem/output_Subsystem'
 * '<S7>'   : 'LCWS_subsystem_integrated/LCWS_Subsystem/CalcLLCWEnabledSubsystem/Calc_LBSWFunction'
 * '<S8>'   : 'LCWS_subsystem_integrated/LCWS_Subsystem/CalcLLCWEnabledSubsystem/Calc_LCVWFunction'
 * '<S9>'   : 'LCWS_subsystem_integrated/LCWS_Subsystem/CalcLLCWEnabledSubsystem/DtmnWarningChart'
 * '<S10>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/CalcRLCWEnabledSubsystem/CalcRBSWFunction'
 * '<S11>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/CalcRLCWEnabledSubsystem/CalcRCVWFunction'
 * '<S12>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/CalcRLCWEnabledSubsystem/DtmnWarningChart'
 * '<S13>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/Dtmn_Subsystem/Compare To Constant'
 * '<S14>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/Dtmn_Subsystem/Compare To Constant1'
 * '<S15>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/Dtmn_Subsystem/Compare To Zero'
 * '<S16>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/Dtmn_Subsystem/Compare To Zero1'
 * '<S17>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/Dtmn_Subsystem/Compare To Zero2'
 * '<S18>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/Dtmn_Subsystem/Compare To Zero3'
 * '<S19>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/Dtmn_Subsystem/DtmnChart'
 * '<S20>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/input_Subsystem/Calibration_Subsystem'
 * '<S21>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/input_Subsystem/CvrtInput_Subsystem'
 * '<S22>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/input_Subsystem/CvrtObtVecFunctionEnabled'
 * '<S23>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/input_Subsystem/CvrtInput_Subsystem/Compare To Constant'
 * '<S24>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/input_Subsystem/CvrtInput_Subsystem/Compare To Constant1'
 * '<S25>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/input_Subsystem/CvrtObtVecFunctionEnabled/CvrtObtVecFunction'
 * '<S26>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/input_Subsystem/CvrtObtVecFunctionEnabled/CvrtObtVecFunction1'
 * '<S27>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/input_Subsystem/CvrtObtVecFunctionEnabled/ObserveObtVecFunction1'
 * '<S28>'  : 'LCWS_subsystem_integrated/LCWS_Subsystem/input_Subsystem/CvrtObtVecFunctionEnabled/ObserveObtVecFunction2'
 */

/*-
 * Requirements for '<Root>': LCWS_subsystem_integrated
 */
#endif                                 /* RTW_HEADER_LCWS_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
