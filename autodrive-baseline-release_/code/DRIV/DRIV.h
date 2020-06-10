/*
 * File: DRIV.h
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

#ifndef RTW_HEADER_DRIV_h_
#define RTW_HEADER_DRIV_h_
#ifndef DRIV_subsystem_integrated_COMMON_INCLUDES_
# define DRIV_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DRIV_subsystem_integrated_COMMON_INCLUDES_ */

#include "DRIV_subsystem_integrated_types.h"

/* Child system includes */
#include "DRIV_RunStatus.h"
#include "DRIV_SignalInput.h"
#include "DRIV_SignalOutput.h"

extern void DRIV_subsystem_integr_DRIV_Init(void);
extern void DRIV_subsystem_integ_DRIV_Start(void);
extern void DRIV_subsystem_integrated_DRIV(void);

#endif                                 /* RTW_HEADER_DRIV_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
