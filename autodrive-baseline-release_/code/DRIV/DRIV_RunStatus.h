/*
 * File: DRIV_RunStatus.h
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

#ifndef RTW_HEADER_DRIV_RunStatus_h_
#define RTW_HEADER_DRIV_RunStatus_h_
#include <math.h>
#ifndef DRIV_subsystem_integrated_COMMON_INCLUDES_
# define DRIV_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* DRIV_subsystem_integrated_COMMON_INCLUDES_ */

#include "DRIV_subsystem_integrated_types.h"

/* Child system includes */
#include "DRIV_LC_Intention_Judge.h"
#include "DRIV_OverrideSteerDefaultData.h"

extern void DRIV_subsystem_i_SwitchDebounce(boolean_T rtu_SwitchRaw, boolean_T
  rtu_SwitchRaw_Old, uint8_T rtu_debounceThrsh, boolean_T rtu_FinalSwitch_Old,
  uint8_T rtu_SwitchSampleCnt_Old, boolean_T *rty_FinalSwitch, uint8_T
  *rty_SwitchSampleCnt);
extern void DtrmnDRIV_TargetSpeed(void);
extern void DtrmnDRIV_TargetTimeGap(void);
extern void DtrmnDRIV_ACC_Switch(void);
extern void DRIV_subsystem__Chart_n3en_Init(void);
extern void DRIV_subsystem_integ_Chart_i1ry(void);
extern void DRIV_subs_RisingEdgeDelay1_Init(void);
extern void DRIV_subsystem_RisingEdgeDelay1(void);
extern void DRIV_subsystem__Chart_nkf4_Init(void);
extern void DRIV_subsystem_integ_Chart_absx(void);
extern void DRIV_subsystem__Chart_nlhm_Init(void);
extern void DRIV_subsystem_integ_Chart_hsbz(void);
extern void DtrmnDRIV_RunStatus_Init(void);
extern void DtrmnDRIV_RunStatus_Start(void);
extern void DtrmnDRIV_RunStatus(void);

#endif                                 /* RTW_HEADER_DRIV_RunStatus_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
