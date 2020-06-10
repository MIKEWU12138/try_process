/*
 * File: ALCA_InputDataProcess.h
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

#ifndef RTW_HEADER_ALCA_InputDataProcess_h_
#define RTW_HEADER_ALCA_InputDataProcess_h_
#ifndef ALCA_subsystem_integrated_COMMON_INCLUDES_
# define ALCA_subsystem_integrated_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#endif                                 /* ALCA_subsystem_integrated_COMMON_INCLUDES_ */

#include "ALCA_subsystem_integrated_types.h"

/* Child system includes */
#include "ALCA_Dtrm_dcsn_info.h"
#include "ALCA_Dtrm_mpfu_info.h"
#include "rt_sys_ALCA_subsystem_integrated_10.h"

extern void ALCA_subsystem_inte_DividByZero(real32_T rtu_u, real32_T *rty_y);
extern void ALCA_ALCA_InputDataProcess_Init(void);
extern void ALC_ALCA_InputDataProcess_Reset(void);
extern void ALC_ALCA_InputDataProcess_Start(void);
extern void ALCA_subs_ALCA_InputDataProcess(boolean_T rtu_reset_lc_req,
  EnumALCA_state rtu_pre_state, boolean_T rtu_touched_new_lane, ALCA_DcsnInfo
  *rty_dcsn_info, ALCA_VehState *rty_veh_state, uint8_T *rty_fault,
  ALCA_MPFU_Info *rty_mpfu_info);

#endif                                 /* RTW_HEADER_ALCA_InputDataProcess_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
