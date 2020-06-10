/*
 * File: OutputManager_LKA.c
 *
 * Code generated for Simulink model 'LKAS_subsystem_integrated'.
 *
 * Model version                  : 1.102
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Tue Jun  9 11:05:35 2020
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

#include "OutputManager_LKA.h"

/* Include model header file for global data */
#include "LKAS_subsystem_integrated.h"
#include "LKAS_subsystem_integrated_private.h"

/* Output and update for atomic system: '<S4>/OutputManager_LKA' */
void LKAS_subsyste_OutputManager_LKA(void)
{
  /* SignalConversion: '<S11>/BusConversion_InsertedFor_LKAS_InternalOutput_at_inport_0' */
  LKAS_subsystem_integrated_B.IntvTyp_sLKA_pzex =
    LKAS_subsystem_integrated_B.IntvTyp_sLKA;

  /* SignalConversion: '<S11>/BusConversion_InsertedFor_LKAS_InternalOutput_at_inport_0' */
  LKAS_subsystem_integrated_B.CtrlRef_sLKA_ly5n =
    LKAS_subsystem_integrated_B.CtrlRef_sLKA_jpit;

  /* SignalConversion: '<S11>/BusConversion_InsertedFor_LKAS_InternalOutput_at_inport_0' */
  LKAS_subsystem_integrated_B.IntvSide_sLKA_k4lx =
    LKAS_subsystem_integrated_B.IntvSide_sLKA;

  /* SignalConversion: '<S11>/BusConversion_InsertedFor_LKAS_InternalOutput_at_inport_0' */
  LKAS_subsystem_integrated_B.IsIntvCompleted_sLKA_a1kj = VbLKAS_IsIntvCompleted;

  /* RelationalOperator: '<S111>/Relational Operator' incorporates:
   *  Constant: '<S112>/Constant'
   */
  VbLKAS_Intv_Request = (LKAS_Intv == LKAS_subsystem_integrated_B.IntvMgrSt_sLKA);

  /* SignalConversion: '<S111>/Signal Conversion' */
  VsLKAS_DataBus.Intv_Request = VbLKAS_Intv_Request;

  /* BusCreator: '<S111>/Bus Creator' */
  VsLKAS_DataBus.SteerData = LKAS_subsystem_integrated_B.Add3;
  VsLKAS_DataBus.IntvTyp_sLKA = LKAS_subsystem_integrated_B.IntvTyp_sLKA;
  VsLKAS_DataBus.IntvSide_sLKA = LKAS_subsystem_integrated_B.IntvSide_sLKA;
  VsLKAS_DataBus.IntvMgrSt_sLKA = LKAS_subsystem_integrated_B.IntvMgrSt_sLKA;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
