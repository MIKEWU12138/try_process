/*
 * File: lccs_control.h
 *
 * Code generated for Simulink model 'LCCS_subsystem_integrated'.
 *
 * Model version                  : 1.2176
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 09:42:58 2020
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

#ifndef RTW_HEADER_lccs_control_h_
#define RTW_HEADER_lccs_control_h_
#ifndef LCCS_subsystem_integrated_COMMON_INCLUDES_
# define LCCS_subsystem_integrated_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* LCCS_subsystem_integrated_COMMON_INCLUDES_ */

#include "LCCS_subsystem_integrated_types.h"

/* Child system includes */
#include "lccs_center_trace.h"
#include "lccs_control_error.h"
#include "lccs_control_main.h"
#include "lccs_control_output.h"
#include "lccs_lane_center.h"
#include "lccs_lane_marker.h"
#include "lccs_lateral_shift.h"
#include "lccs_signal_processing.h"
#include "lccs_signal_rationality.h"

extern void LCCS_subsystem_integr_LCCS_Init(void);
extern void LCCS_subsystem_integrated_LCCS(void);

#endif                                 /* RTW_HEADER_lccs_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
