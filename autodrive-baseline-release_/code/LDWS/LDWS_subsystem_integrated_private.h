/*
 * File: LDWS_subsystem_integrated_private.h
 *
 * Code generated for Simulink model 'LDWS_subsystem_integrated'.
 *
 * Model version                  : 1.384
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 11:19:43 2020
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

#ifndef RTW_HEADER_LDWS_subsystem_integrated_private_h_
#define RTW_HEADER_LDWS_subsystem_integrated_private_h_
#include "rtwtypes.h"
#include "LDWS_subsystem_integrated.h"

/* Imported (extern) block signals */
extern DCSN_DataBus VsDCSN_DataBus;    /* '<Root>/DCSN_DataBus' */
extern EGMO_DataBus VsEGMO_DataBus;    /* '<Root>/EGMO_DataBus' */
extern COMM_CANR_Databus VsCOMM_CANR_Databus;/* '<Root>/COMM_CANR_Databus' */
extern MPFU_DataBus VsMPFU_DataBus;    /* '<Root>/MPFU_DataBus' */
extern void LDWS_subsystem_integrated_Init(void);
extern void LDWS__LDWS_subsystem_integrated(void);

#endif                                 /* RTW_HEADER_LDWS_subsystem_integrated_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
