/*
 * File: ALCA_DtrmnALCAState.h
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

#ifndef RTW_HEADER_ALCA_DtrmnALCAState_h_
#define RTW_HEADER_ALCA_DtrmnALCAState_h_
#ifndef ALCA_subsystem_integrated_COMMON_INCLUDES_
# define ALCA_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ALCA_subsystem_integrated_COMMON_INCLUDES_ */

#include "ALCA_subsystem_integrated_types.h"

/* Child system includes */
#include "ALCA_Dtrmn_interrupt_action.h"

extern void ALCA_s_ALCA_DtrmnALCAState_Init(void);
extern void ALCA__ALCA_DtrmnALCAState_Reset(void);
extern void ALCA__ALCA_DtrmnALCAState_Start(void);
extern void ALCA_subsys_ALCA_DtrmnALCAState(const ALCA_DcsnInfo *rtu_dcsn_info,
  boolean_T rtu_lc_accept, EnumALCA_not_fulfill_reason
  rtu_odd_not_fulfill_reason, boolean_T rtu_touched_new_lane, boolean_T
  rtu_interrupt, EnumALCA_interrupt_type rtu_interrupt_type, const ALCA_VehState
  *rtu_veh_state, const ALCA_MPFU_Info *rtu_mpfu_info, boolean_T
  *rty_alca_request, EnumALCA_state *rty_alca_state, boolean_T
  *rty_reset_change_lane_req, uint8_T *rty_interrupt_action);

#endif                                 /* RTW_HEADER_ALCA_DtrmnALCAState_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
