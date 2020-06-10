/*
 * File: comm_transmit.h
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

#ifndef RTW_HEADER_comm_transmit_h_
#define RTW_HEADER_comm_transmit_h_
#include <math.h>
#ifndef COMM_subsystem_integrated_COMMON_INCLUDES_
# define COMM_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "can_message.h"
#endif                                 /* COMM_subsystem_integrated_COMMON_INCLUDES_ */

#include "COMM_subsystem_integrated_types.h"
#include "rt_nonfinite.h"

extern void COMM_subsystem_integrated_GearN(uint8_T *rty_Out1);
extern void COMM_subsystem_in_Transmit_Init(void);
extern void COMM_subsystem_i_Transmit_Const(void);
extern void COMM_subsystem_integra_Transmit(void);

#endif                                 /* RTW_HEADER_comm_transmit_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
