/*
 * File: AEBD_subsystem_integrated.h
 *
 * Code generated for Simulink model 'AEBD_subsystem_integrated'.
 *
 * Model version                  : 1.82
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sat May  9 18:53:22 2020
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

#ifndef RTW_HEADER_AEBD_subsystem_integrated_h_
#define RTW_HEADER_AEBD_subsystem_integrated_h_
#include <math.h>
#include <string.h>
#ifndef AEBD_subsystem_integrated_COMMON_INCLUDES_
# define AEBD_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* AEBD_subsystem_integrated_COMMON_INCLUDES_ */

#include "AEBD_subsystem_integrated_types.h"

/* Macros for accessing real-time model data structure */

/* Block states (auto storage) for system '<Root>' */
typedef struct
{
  uint16_T error_count;                /* '<S1>/Dtrmn_AEBD_Function' */
  uint8_T delay_time;                  /* '<S1>/Dtrmn_AEBD_Function' */
  boolean_T AEBD_Error;                /* '<S1>/Dtrmn_AEBD_Function' */
}
DW_AEBD_subsystem_integrated_T;

/* Block states (auto storage) */
extern DW_AEBD_subsystem_integrated_T AEBD_subsystem_integrated_DW;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real32_T VfAEBD_AEB_a;          /* '<S1>/Rate Transition3' */
extern uint16_T VcAEBD_ErrorCount;     /* '<S1>/Dtrmn_AEBD_Function' */
extern uint8_T VfAEBD_t_DelayTime;     /* '<S1>/Dtrmn_AEBD_Function' */
extern boolean_T VbAEBD_Error;         /* '<S1>/Dtrmn_AEBD_Function' */
extern boolean_T VbAEBD_Suppress;      /* '<S1>/Rate Transition' */
extern boolean_T VbAEBD_Pedoff;        /* '<S1>/Rate Transition1' */
extern boolean_T VbAEBD_AEBaError;     /* '<S1>/Rate Transition4' */
extern boolean_T VbAEBD_AEBrequest;    /* '<S1>/Rate Transition2' */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real32_T KfAEBD_a_AccelDeviation;/* Variable: KfAEBD_a_AccelDeviation
                                         * Referenced by: '<S1>/Constant6'
                                         */
extern uint16_T KcAEBD_ErrorCountThrsh;/* Variable: KcAEBD_ErrorCountThrsh
                                        * Referenced by: '<S1>/Constant8'
                                        */
extern uint8_T KfAEBD_t_WaitTimeThrsh; /* Variable: KfAEBD_t_WaitTimeThrsh
                                        * Referenced by: '<S1>/Constant7'
                                        */
extern boolean_T KbAEBD_ADCU_CANError; /* Variable: KbAEBD_ADCU_CANError
                                        * Referenced by: '<S1>/Constant10'
                                        */
extern boolean_T KbAEBD_AccelerationSensorError;/* Variable: KbAEBD_AccelerationSensorError
                                                 * Referenced by: '<S1>/Constant9'
                                                 */
extern boolean_T KbAEBD_ESCError;      /* Variable: KbAEBD_ESCError
                                        * Referenced by: '<S1>/Constant11'
                                        */
extern boolean_T KbAEBD_ErrorClear;    /* Variable: KbAEBD_ErrorClear
                                        * Referenced by: '<S1>/Constant12'
                                        */

/* Model entry point functions */
extern void AEBD_subsystem_integrated_initialize(void);
extern void AEBD_subsystem_integrated_step(void);

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
 * '<Root>' : 'AEBD_subsystem_integrated'
 * '<S1>'   : 'AEBD_subsystem_integrated/AEBD_Subsystem'
 * '<S2>'   : 'AEBD_subsystem_integrated/AEBD_Subsystem/Compare To Constant'
 * '<S3>'   : 'AEBD_subsystem_integrated/AEBD_Subsystem/Dtrmn_AEBD_Function'
 */

/*-
 * Requirements for '<Root>': AEBD_subsystem_integrated
 */
#endif                                 /* RTW_HEADER_AEBD_subsystem_integrated_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
