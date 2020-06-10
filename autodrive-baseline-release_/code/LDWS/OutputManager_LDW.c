/*
 * File: OutputManager_LDW.c
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

#include "OutputManager_LDW.h"

/* Include model header file for global data */
#include "LDWS_subsystem_integrated.h"
#include "LDWS_subsystem_integrated_private.h"

/* System initialize for atomic system: '<S1>/OutputManager_LDW' */
void LDWS_sub_OutputManager_LDW_Init(void)
{
  /* SystemInitialize for Merge: '<S5>/Merge' */
  VbLDWS_WrnSt = false;

  /* SystemInitialize for Merge: '<S5>/Merge1' */
  VeLDWS_WrnSd = LDWS_NoWarn;
}

/* Output and update for atomic system: '<S1>/OutputManager_LDW' */
void LDWS_subsyste_OutputManager_LDW(void)
{
  int8_T rtAction;
  boolean_T tmp;
  boolean_T tmp_0;

  /* Truth Table: '<S5>/Truth Table' */
  /*  Example condition 1 */
  /*  Example condition 2 */
  tmp = !VbLDWS_RdEnblRi;
  tmp_0 = !VbLDWS_RdEnblLe;
  if (tmp_0 && tmp)
  {
    VeLDWS_LaDetecSt = LDWS_NotAvl;
  }
  else if (VbLDWS_RdEnblLe && tmp)
  {
    VeLDWS_LaDetecSt = LDWS_LeAvl;
  }
  else if (tmp_0 && VbLDWS_RdEnblRi)
  {
    VeLDWS_LaDetecSt = LDWS_RiAvl;
  }
  else
  {
    /*  Default */
    VeLDWS_LaDetecSt = LDWS_BothAvl;
  }

  /* End of Truth Table: '<S5>/Truth Table' */

  /* SwitchCase: '<S5>/Switch Case' incorporates:
   *  Constant: '<S5>/Constant6'
   *  Inport: '<S28>/In1'
   */
  rtAction = -1;
  switch (LDWS_subsystem_integrated_B.Warn_Manager_Status)
  {
   case WarnLe:
    rtAction = 0;
    break;

   case WarnRi:
    rtAction = 1;
    break;

   case Avl:
   case NotAvl:
   case SuppLe:
   case SuppRi:
    rtAction = 2;
    break;

   default:
    /* no actions */
    break;
  }

  switch (rtAction)
  {
   case 0:
    /* Outputs for IfAction SubSystem: '<S5>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* SignalConversion: '<S26>/OutportBufferForOut1' incorporates:
     *  Constant: '<S26>/Constant'
     */
    VbLDWS_WrnSt = true;

    /* SignalConversion: '<S26>/OutportBufferForOut2' incorporates:
     *  Constant: '<S26>/Constant3'
     */
    VeLDWS_WrnSd = LDWS_WarnLe;

    /* End of Outputs for SubSystem: '<S5>/Switch Case Action Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S5>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* SignalConversion: '<S27>/OutportBufferForOut1' incorporates:
     *  Constant: '<S27>/Constant1'
     */
    VbLDWS_WrnSt = true;

    /* SignalConversion: '<S27>/OutportBufferForOut2' */
    VeLDWS_WrnSd = LDWS_subsystem_integrate_ConstB.In1;

    /* End of Outputs for SubSystem: '<S5>/Switch Case Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S5>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* SignalConversion: '<S28>/OutportBufferForOut1' incorporates:
     *  Constant: '<S28>/Constant2'
     */
    VbLDWS_WrnSt = false;
    VeLDWS_WrnSd = LDWS_NoWarn;

    /* End of Outputs for SubSystem: '<S5>/Switch Case Action Subsystem2' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S5>/Switch Case' */

  /* Inport: '<S5>/SysSt' */
  VsLDWS_DataBus.LDWS_system_st = VeLDWS_SysSt;

  /* Inport: '<S5>/OnStateSt' */
  VsLDWS_DataBus.LDWS_on_state_st = VeLDWS_OnStateSt;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
