/*
 * File: LCAS_subsystem_integrated.h
 *
 * Code generated for Simulink model 'LCAS_subsystem_integrated'.
 *
 * Model version                  : 1.452
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Jun  8 17:13:10 2020
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

#ifndef RTW_HEADER_LCAS_subsystem_integrated_h_
#define RTW_HEADER_LCAS_subsystem_integrated_h_
#include <math.h>
#include <string.h>
#ifndef LCAS_subsystem_integrated_COMMON_INCLUDES_
# define LCAS_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LCAS_subsystem_integrated_COMMON_INCLUDES_ */

#include "LCAS_subsystem_integrated_types.h"

/* Macros for accessing real-time model data structure */

/* Block signals (auto storage) */
typedef struct
{
  real32_T vec_L[220];                 /* '<S20>/Data Type Conversion' */
  real32_T vec_R[220];                 /* '<S20>/Data Type Conversion1' */
  int32_T cvwR_ID;                     /* '<S3>/CalcRCVWFunction' */
  int32_T cvwL_ID;                     /* '<S2>/Calc_LCVWFunction' */
  uint16_T num_L;                      /* '<S20>/CvrtObtVecFunction' */
  uint16_T num_R;                      /* '<S20>/CvrtObtVecFunction' */
  boolean_T enable;                    /* '<S4>/DtmnChart' */
  EnumLCAS_Active_Status active_status;/* '<S4>/DtmnChart' */
  EnumLCAS_Warning_Status right_warning_status;/* '<S3>/DtmnWarningChart' */
  EnumLCAS_Warning_Status left_warning_status;/* '<S2>/DtmnWarningChart' */
}
B_LCAS_subsystem_integrated_T;

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
  uint8_T is_c3_LCAS_subsystem_integrated;/* '<S4>/DtmnChart' */
  uint8_T is_NoError;                  /* '<S4>/DtmnChart' */
  uint8_T is_On;                       /* '<S4>/DtmnChart' */
  uint8_T is_c4_LCAS_subsystem_integrated;/* '<S3>/DtmnWarningChart' */
  uint8_T is_UnSafe;                   /* '<S3>/DtmnWarningChart' */
  uint8_T is_c12_LCAS_subsystem_integrate;/* '<S2>/DtmnWarningChart' */
  uint8_T is_UnSafe_jdaq;              /* '<S2>/DtmnWarningChart' */
  boolean_T LCAS_CvrtObtVecFunctionEnabled_;/* '<S5>/LCAS_CvrtObtVecFunctionEnabled' */
  boolean_T DtmnLCAEnabledSubsystem_MODE;/* '<S1>/DtmnLCAEnabledSubsystem' */
  boolean_T CalcRLCAEnabledSubsystem_MODE;/* '<S1>/CalcRLCAEnabledSubsystem' */
  boolean_T CalcLLCAEnabledSubsystem_MODE;/* '<S1>/CalcLLCAEnabledSubsystem' */
}
DW_LCAS_subsystem_integrated_T;

/* Real-time Model Data Structure */
struct tag_RTM_LCAS_subsystem_integr_T
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
extern B_LCAS_subsystem_integrated_T LCAS_subsystem_integrated_B;

/* Block states (auto storage) */
extern DW_LCAS_subsystem_integrated_T LCAS_subsystem_integrated_DW;

/* External data declarations for dependent source files */
extern const LCAS_DataBus LCAS_subsystem_integrated_rtZLCAS_DataBus;/* LCAS_DataBus ground */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern LCAS_DataBus VsLCAS_DataBus;    /* '<S6>/Bus_Creator' */
extern real32_T VfLCAS_curvature;      /* '<S19>/Gain2' */
extern real32_T VfLCAS_speed_in;       /* '<S19>/Gain1' */
extern real32_T VaLCAS_Obt[16];        /* '<S20>/ObserveObtVecFunction2' */
extern int32_T ViLCAS_cvwR_ID;         /* '<S3>/Gain1' */
extern int32_T ViLCAS_cvwL_ID;         /* '<S2>/Gain1' */
extern uint16_T VnLCAS_num_R;          /* '<S20>/Gain1' */
extern uint16_T VnLCAS_num_L;          /* '<S20>/Gain2' */
extern uint8_T VfLCAS_gear_in;         /* '<S19>/Gain3' */
extern uint8_T ViLCAS_cvwR;            /* '<S3>/Gain4' */
extern uint8_T ViLCAS_cvwL;            /* '<S2>/Gain3' */
extern EnumLCAS_Active_Status VeLCAS_active_status;/* '<S6>/Rate Transition2' */
extern EnumLCAS_Warning_Status VeLCAS_right_warning_status_out;/* '<S6>/Rate Transition1' */
extern EnumLCAS_Warning_Status VeLCAS_left_warning_status_out;/* '<S6>/Rate Transition' */
extern EnumLCAS_Warning_Status VeLCAS_right_warning_status;/* '<S3>/Rate Transition' */
extern EnumLCAS_Warning_Status VeLCAS_left_warning_status;/* '<S2>/Rate Transition' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T KfLCAS_Ang_DisbleStrAngleThrshMax;/* Variable: KfLCAS_Ang_DisbleStrAngleThrshMax
                                                   * Referenced by: '<S18>/Constant7'
                                                   */
extern real32_T KfLCAS_Ang_EnbleStrAngleThrshMax;/* Variable: KfLCAS_Ang_EnbleStrAngleThrshMax
                                                  * Referenced by: '<S18>/Constant6'
                                                  */
extern real32_T KfLCAS_c_DisbleCurveThrshMax;/* Variable: KfLCAS_c_DisbleCurveThrshMax
                                              * Referenced by: '<S18>/Constant20'
                                              */
extern real32_T KfLCAS_c_EnbleCurveThrshMax;/* Variable: KfLCAS_c_EnbleCurveThrshMax
                                             * Referenced by: '<S18>/Constant19'
                                             */
extern real32_T KfLCAS_d_CVLargerZone_FrontDis;/* Variable: KfLCAS_d_CVLargerZone_FrontDis
                                                * Referenced by: '<S18>/Constant12'
                                                */
extern real32_T KfLCAS_d_CVLargerZone_NearDis;/* Variable: KfLCAS_d_CVLargerZone_NearDis
                                               * Referenced by: '<S18>/Constant3'
                                               */
extern real32_T KfLCAS_d_CVZone_FarDis;/* Variable: KfLCAS_d_CVZone_FarDis
                                        * Referenced by: '<S18>/Constant4'
                                        */
extern real32_T KfLCAS_d_CVZone_FrontDis;/* Variable: KfLCAS_d_CVZone_FrontDis
                                          * Referenced by: '<S18>/Constant11'
                                          */
extern real32_T KfLCAS_d_CVZone_NearDis;/* Variable: KfLCAS_d_CVZone_NearDis
                                         * Referenced by: '<S18>/Constant2'
                                         */
extern real32_T KfLCAS_d_VehCenterFront;/* Variable: KfLCAS_d_VehCenterFront
                                         * Referenced by: '<S18>/Constant29'
                                         */
extern real32_T KfLCAS_d_VehCenterRear;/* Variable: KfLCAS_d_VehCenterRear
                                        * Referenced by: '<S18>/Constant28'
                                        */
extern real32_T KfLCAS_d_VehLenth;     /* Variable: KfLCAS_d_VehLenth
                                        * Referenced by: '<S18>/Constant'
                                        */
extern real32_T KfLCAS_d_VehWidth;     /* Variable: KfLCAS_d_VehWidth
                                        * Referenced by: '<S18>/Constant1'
                                        */
extern real32_T KfLCAS_r_ObtWidthProportion;/* Variable: KfLCAS_r_ObtWidthProportion
                                             * Referenced by: '<S18>/Constant25'
                                             */
extern real32_T KfLCAS_t_TTCLargerThrsh_LowLevel;/* Variable: KfLCAS_t_TTCLargerThrsh_LowLevel
                                                  * Referenced by: '<S18>/Constant14'
                                                  */
extern real32_T KfLCAS_t_TTCThrshLowLevel;/* Variable: KfLCAS_t_TTCThrshLowLevel
                                           * Referenced by: '<S18>/Constant13'
                                           */
extern real32_T KfLCAS_t_WarnSustainedTime;/* Variable: KfLCAS_t_WarnSustainedTime
                                            * Referenced by: '<S18>/Constant8'
                                            */
extern real32_T KfLCAS_v_DisbleVehSpdThrshHi;/* Variable: KfLCAS_v_DisbleVehSpdThrshHi
                                              * Referenced by: '<S18>/Constant27'
                                              */
extern real32_T KfLCAS_v_DisbleVehSpdThrshLo;/* Variable: KfLCAS_v_DisbleVehSpdThrshLo
                                              * Referenced by: '<S18>/Constant18'
                                              */
extern real32_T KfLCAS_v_EnbleVehSpdThrshHi;/* Variable: KfLCAS_v_EnbleVehSpdThrshHi
                                             * Referenced by: '<S18>/Constant26'
                                             */
extern real32_T KfLCAS_v_EnbleVehSpdThrshLo;/* Variable: KfLCAS_v_EnbleVehSpdThrshLo
                                             * Referenced by: '<S18>/Constant17'
                                             */
extern real32_T KfLCAS_v_LatSpdThr;    /* Variable: KfLCAS_v_LatSpdThr
                                        * Referenced by: '<S18>/Constant24'
                                        */
extern real32_T KfLCAS_v_staticSpdThr; /* Variable: KfLCAS_v_staticSpdThr
                                        * Referenced by: '<S18>/Constant9'
                                        */
extern int8_T KfLCAS_d_CVLargerZone_FarDis;/* Variable: KfLCAS_d_CVLargerZone_FarDis
                                            * Referenced by: '<S18>/Constant5'
                                            */
extern boolean_T KbLCAS_Sensor_Error;  /* Variable: KbLCAS_Sensor_Error
                                        * Referenced by: '<S4>/Constant28'
                                        */
extern boolean_T KbLCAS_Sensor_Work;   /* Variable: KbLCAS_Sensor_Work
                                        * Referenced by: '<S4>/Constant3'
                                        */
extern boolean_T KbLCAS_Switch;        /* Variable: KbLCAS_Switch
                                        * Referenced by: '<S18>/Constant21'
                                        */
extern boolean_T KbLCAS_configLCA;     /* Variable: KbLCAS_configLCA
                                        * Referenced by: '<S18>/Constant30'
                                        */
extern boolean_T KbLCAS_curve;         /* Variable: KbLCAS_curve
                                        * Referenced by: '<S19>/Constant28'
                                        */

/* Model entry point functions */
extern void LCAS_subsystem_integrated_initialize(void);
extern void LCAS_subsystem_integrated_step(void);

/* Real-time Model object */
extern RT_MODEL_LCAS_subsystem_integ_T *const LCAS_subsystem_integrated_M;

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
 * '<Root>' : 'LCAS_subsystem_integrated'
 * '<S1>'   : 'LCAS_subsystem_integrated/LCAS_Subsystem'
 * '<S2>'   : 'LCAS_subsystem_integrated/LCAS_Subsystem/CalcLLCAEnabledSubsystem'
 * '<S3>'   : 'LCAS_subsystem_integrated/LCAS_Subsystem/CalcRLCAEnabledSubsystem'
 * '<S4>'   : 'LCAS_subsystem_integrated/LCAS_Subsystem/DtmnLCAEnabledSubsystem'
 * '<S5>'   : 'LCAS_subsystem_integrated/LCAS_Subsystem/LCAS_input_Subsystem'
 * '<S6>'   : 'LCAS_subsystem_integrated/LCAS_Subsystem/LCAS_output_Subsystem'
 * '<S7>'   : 'LCAS_subsystem_integrated/LCAS_Subsystem/CalcLLCAEnabledSubsystem/Calc_LCVWFunction'
 * '<S8>'   : 'LCAS_subsystem_integrated/LCAS_Subsystem/CalcLLCAEnabledSubsystem/DtmnWarningChart'
 * '<S9>'   : 'LCAS_subsystem_integrated/LCAS_Subsystem/CalcRLCAEnabledSubsystem/CalcRCVWFunction'
 * '<S10>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/CalcRLCAEnabledSubsystem/DtmnWarningChart'
 * '<S11>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/DtmnLCAEnabledSubsystem/Compare To Constant'
 * '<S12>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/DtmnLCAEnabledSubsystem/Compare To Constant1'
 * '<S13>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/DtmnLCAEnabledSubsystem/Compare To Zero'
 * '<S14>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/DtmnLCAEnabledSubsystem/Compare To Zero1'
 * '<S15>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/DtmnLCAEnabledSubsystem/Compare To Zero2'
 * '<S16>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/DtmnLCAEnabledSubsystem/Compare To Zero3'
 * '<S17>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/DtmnLCAEnabledSubsystem/DtmnChart'
 * '<S18>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/LCAS_input_Subsystem/LCAS_Calibration_Subsystem'
 * '<S19>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/LCAS_input_Subsystem/LCAS_CvrtInput_Subsystem'
 * '<S20>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/LCAS_input_Subsystem/LCAS_CvrtObtVecFunctionEnabled'
 * '<S21>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/LCAS_input_Subsystem/LCAS_CvrtInput_Subsystem/Compare To Constant'
 * '<S22>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/LCAS_input_Subsystem/LCAS_CvrtInput_Subsystem/Compare To Constant1'
 * '<S23>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/LCAS_input_Subsystem/LCAS_CvrtInput_Subsystem/Compare To Constant2'
 * '<S24>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/LCAS_input_Subsystem/LCAS_CvrtObtVecFunctionEnabled/CvrtObtVecFunction'
 * '<S25>'  : 'LCAS_subsystem_integrated/LCAS_Subsystem/LCAS_input_Subsystem/LCAS_CvrtObtVecFunctionEnabled/ObserveObtVecFunction2'
 */

/*-
 * Requirements for '<Root>': LCAS_subsystem_integrated
 */
#endif                                 /* RTW_HEADER_LCAS_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
