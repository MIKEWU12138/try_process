/*
 * File: comm_receive.h
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

#ifndef RTW_HEADER_comm_receive_h_
#define RTW_HEADER_comm_receive_h_
#include <math.h>
#ifndef COMM_subsystem_integrated_COMMON_INCLUDES_
# define COMM_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "can_message.h"
#endif                                 /* COMM_subsystem_integrated_COMMON_INCLUDES_ */

#include "COMM_subsystem_integrated_types.h"

/* Block signals for system '<S17>/Median Filter1' */
typedef struct
{
  real32_T MedianFilter1;              /* '<S17>/Median Filter1' */
}
B_MedianFilter1_COMM_subsyste_T;

/* Block states (auto storage) for system '<S17>/Median Filter1' */
typedef struct
{
  dsp_MedianFilter_COMM_subsyst_T obj; /* '<S17>/Median Filter1' */
  boolean_T objisempty;                /* '<S17>/Median Filter1' */
}
DW_MedianFilter1_COMM_subsyst_T;

extern void COMM__SwitchCaseActionSubsystem(COMM_Bus_VEH_Config *rty_Out1);
extern void COMM_subsyst_MedianFilter1_Init(DW_MedianFilter1_COMM_subsyst_T
  *localDW);
extern void COMM_subsys_MedianFilter1_Start(DW_MedianFilter1_COMM_subsyst_T
  *localDW);
extern void COMM_subsystem_in_MedianFilter1(real32_T rtu_0,
  B_MedianFilter1_COMM_subsyste_T *localB, DW_MedianFilter1_COMM_subsyst_T
  *localDW);
extern void COMM_subsystem_int_Receive_Init(void);
extern void COMM_subsystem_in_Receive_Start(void);
extern void COMM_subsystem_integrat_Receive(void);

#endif                                 /* RTW_HEADER_comm_receive_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
