/*
 * File: DRIV_SignalInput.h
 *
 * Code generated for Simulink model 'DRIV_subsystem_integrated'.
 *
 * Model version                  : 1.1200
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 08:50:22 2020
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

#ifndef RTW_HEADER_DRIV_SignalInput_h_
#define RTW_HEADER_DRIV_SignalInput_h_
#include <math.h>
#ifndef DRIV_subsystem_integrated_COMMON_INCLUDES_
# define DRIV_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DRIV_subsystem_integrated_COMMON_INCLUDES_ */

#include "DRIV_subsystem_integrated_types.h"

extern void DRIV_subsystem_inte_DividByZero(real32_T rtu_u, real32_T *rty_y);
extern void DRIV_subsystem_integ_Chart_Init(void);
extern void DRIV_subsystem_integrated_Chart(void);
extern void DRIV_subsystem__Chart_nymd_Init(void);
extern void DRIV_subsystem_integ_Chart_fth3(void);
extern void DRIV_subsystem__Chart_ntlf_Init(void);
extern void DRIV_subsystem_integ_Chart_gtd4(void);
extern void CheckDRIV_SignalInput_Init(void);
extern void CheckDRIV_SignalInput(void);

#endif                                 /* RTW_HEADER_DRIV_SignalInput_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
