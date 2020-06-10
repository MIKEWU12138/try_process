/*
 * File: ALCA_Dtrm_dcsn_info.h
 *
 * Code generated for Simulink model 'ALCA_subsystem_integrated'.
 *
 * Model version                  : 1.6591
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 17:34:22 2020
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

#ifndef RTW_HEADER_ALCA_Dtrm_dcsn_info_h_
#define RTW_HEADER_ALCA_Dtrm_dcsn_info_h_
#ifndef ALCA_subsystem_integrated_COMMON_INCLUDES_
# define ALCA_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ALCA_subsystem_integrated_COMMON_INCLUDES_ */

#include "ALCA_subsystem_integrated_types.h"

extern void ALCA_s_ALCA_Dtrm_dcsn_info_Init(void);
extern void ALCA__ALCA_Dtrm_dcsn_info_Reset(void);
extern void ALCA_subsys_ALCA_Dtrm_dcsn_info(boolean_T rtu_reset_lc_req,
  EnumALCA_state rtu_pre_state, ALCA_DcsnInfo *rty_dcsn_info);

#endif                                 /* RTW_HEADER_ALCA_Dtrm_dcsn_info_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
