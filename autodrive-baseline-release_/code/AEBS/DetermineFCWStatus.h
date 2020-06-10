/*
 * File: DetermineFCWStatus.h
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

#ifndef RTW_HEADER_DetermineFCWStatus_h_
#define RTW_HEADER_DetermineFCWStatus_h_
#ifndef AEBS_subsystem_integrated_COMMON_INCLUDES_
# define AEBS_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* AEBS_subsystem_integrated_COMMON_INCLUDES_ */

#include "AEBS_subsystem_integrated_types.h"

extern void A_CheckAEBS_SystemOverride_c3e4(void);
extern void AEBS_subsys_DtrmnFCW_State_Init(void);
extern void AEBS_subsystem_i_DtrmnFCW_State(void);
extern void AEBS_su_DetermineFCWStatus_Init(void);
extern void AEBS_subsyst_DetermineFCWStatus(void);

#endif                                 /* RTW_HEADER_DetermineFCWStatus_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
