/*
 * File: LCWS_subsystem_integrated_private.h
 *
 * Code generated for Simulink model 'LCWS_subsystem_integrated'.
 *
 * Model version                  : 1.375
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Sun Apr 26 21:11:09 2020
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

#ifndef RTW_HEADER_LCWS_subsystem_integrated_private_h_
#define RTW_HEADER_LCWS_subsystem_integrated_private_h_
#include "rtwtypes.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Imported (extern) block signals */
extern DCSN_DataBus VsDCSN_DataBus;    /* '<Root>/VsDCSN_DataBus' */
extern COMM_Bus_FedBck_in VsCOMM_JAC_Bus_FedBck_Data;/* '<Root>/VsCOMM_JAC_Bus_FedBck_Data' */
extern EGMO_DataBus VsEGMO_DataBus;    /* '<Root>/VsEGMO_DataBus' */
extern OBFU_DataBus VsOBFU_DataBus;    /* '<Root>/VsOBFU_DataBus' */
extern MPFU_DataBus VsMPFU_DataBus;    /* '<Root>/VsMPFU_DataBus' */

#endif                                 /* RTW_HEADER_LCWS_subsystem_integrated_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
