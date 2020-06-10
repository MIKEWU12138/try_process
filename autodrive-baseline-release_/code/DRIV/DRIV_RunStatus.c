/*
 * File: DRIV_RunStatus.c
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

#include "DRIV_RunStatus.h"

/* Include model header file for global data */
#include "DRIV_subsystem_integrated.h"
#include "DRIV_subsystem_integrated_private.h"

/* Named constants for Chart: '<S32>/Chart' */
#define DRIV_su_IN_NO_ACTIVE_CHILD_e4fj ((uint8_T)0U)
#define DRIV_subsystem_i_IN_Raised_fwit ((uint8_T)3U)
#define DRIV_subsystem_in_IN_Delay_pspz ((uint8_T)1U)
#define DRIV_subsystem_int_IN_INIT_kkhb ((uint8_T)2U)

/* Named constants for Chart: '<S33>/Chart' */
#define DRIV_su_IN_NO_ACTIVE_CHILD_kktm ((uint8_T)0U)
#define DRIV_subsystem_i_IN_Raised_hfn4 ((uint8_T)3U)
#define DRIV_subsystem_in_IN_Delay_aqht ((uint8_T)1U)
#define DRIV_subsystem_int_IN_INIT_md5n ((uint8_T)2U)

/* Named constants for Chart: '<S34>/Chart' */
#define DRIV_su_IN_NO_ACTIVE_CHILD_kjr0 ((uint8_T)0U)
#define DRIV_subsystem_i_IN_Raised_nxbf ((uint8_T)3U)
#define DRIV_subsystem_in_IN_Delay_h3xx ((uint8_T)1U)
#define DRIV_subsystem_int_IN_INIT_ihzb ((uint8_T)2U)

/* Named constants for Chart: '<S85>/Chart' */
#define DRIV_su_IN_NO_ACTIVE_CHILD_cmbc ((uint8_T)0U)
#define DRIV_subsystem_i_IN_Raised_la3x ((uint8_T)3U)
#define DRIV_subsystem_in_IN_Delay_pgip ((uint8_T)1U)
#define DRIV_subsystem_int_IN_INIT_homc ((uint8_T)2U)

/* Output and update for atomic system: '<S30>/DtrmnDRIV_TargetSpeed' */
void DtrmnDRIV_TargetSpeed(void)
{
  if (VbDRIV_ACCMainSwitch &&
      (!DRIV_subsystem_integrated_B.VbDRIV_EnableAutoDrive))
  {
    /* Update for Inport: '<Root>/EGMO_DataBus' */
    if (8.3333333333333339 > ((real_T)VsEGMO_DataBus.motion.linear_velocity))
    {
      VfDRIV_ACCDriveSetSpeed = 8.33333302F;
    }
    else
    {
      VfDRIV_ACCDriveSetSpeed = VsEGMO_DataBus.motion.linear_velocity;
    }

    /* End of Update for Inport: '<Root>/EGMO_DataBus' */
  }
  else if (((uint32_T)DRIV_subsystem_integrated_B.SignalConversion) ==
           ACCS_mode_on)
  {
    if (VbDRIV_ACCResumeSwitch &&
        (!DRIV_subsystem_integrated_B.VbLCC_ButtonActivate))
    {
      VfDRIV_ACCDriveSetSpeed =
        DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o +
        KfACCS_v_TapUpDelta;
    }
    else if (DRIV_subsystem_integrated_B.Gain > KfACCS_t_SwitchLongPressThrsh)
    {
      VfDRIV_ACCDriveSetSpeed =
        DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o +
        KfACCS_v_TapUpDeltaLongPress;
    }
    else if ((DRIV_subsystem_integrated_B.FinalSwitch_be4y) &&
             (!DRIV_subsystem_integrated_B.VbACC_ButtonActivate))
    {
      VfDRIV_ACCDriveSetSpeed =
        DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o -
        KfACCS_v_TapDownDelta;
    }
    else if (DRIV_subsystem_integrated_B.Switch2 > KfACCS_t_SwitchLongPressThrsh)
    {
      VfDRIV_ACCDriveSetSpeed =
        DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o -
        KfACCS_v_TapDownDeltaLongPress;
    }
    else
    {
      VfDRIV_ACCDriveSetSpeed =
        DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o;
    }
  }
  else if (!VbDRIV_ACCMainSwitch)
  {
    VfDRIV_ACCDriveSetSpeed = 0.0F;
  }
  else
  {
    VfDRIV_ACCDriveSetSpeed =
      DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o;
  }
}

/* Output and update for atomic system: '<S30>/DtrmnDRIV_TargetTimeGap' */
void DtrmnDRIV_TargetTimeGap(void)
{
  uint8_T rtb_UnitDelay1_gjno;

  /* UnitDelay: '<S37>/Unit Delay1' */
  rtb_UnitDelay1_gjno = VfDRIV_ACCTimeGap;

  /* Switch: '<S37>/Switch3' incorporates:
   *  Constant: '<S37>/Constant2'
   *  Logic: '<S37>/Logical Operator5'
   */
  if (!VbDRIV_ACCMainSwitch)
  {
    /* Switch: '<S37>/Switch2' incorporates:
     *  Constant: '<S44>/Constant'
     *  Logic: '<S37>/Logical Operator4'
     *  RelationalOperator: '<S37>/Relational Operator'
     */
    if ((DRIV_subsystem_integrated_B.SignalConversion == ACCS_mode_on) &&
        VbDRIV_ACCMainSwitch)
    {
      /* Switch: '<S37>/Switch' incorporates:
       *  Constant: '<S37>/Constant'
       *  Logic: '<S37>/Logical Operator'
       *  Logic: '<S37>/Logical Operator1'
       *  Logic: '<S37>/Logical Operator2'
       *  Logic: '<S37>/Logical Operator3'
       *  Sum: '<S37>/Add'
       *  Switch: '<S37>/Switch1'
       *  UnitDelay: '<S37>/Unit Delay1'
       *  UnitDelay: '<S37>/Unit Delay2'
       *  UnitDelay: '<S37>/Unit Delay23'
       */
      if ((DRIV_subsystem_integrated_B.FinalSwitch_a45b) &&
          (!DRIV_subsystem_integrated_DW.UnitDelay23_DSTATE_j5wv))
      {
        rtb_UnitDelay1_gjno = (uint8_T)(((uint32_T)VfDRIV_ACCTimeGap) +
          ((uint32_T)((uint8_T)1U)));
      }
      else
      {
        if ((DRIV_subsystem_integrated_B.FinalSwitch) &&
            (!DRIV_subsystem_integrated_DW.UnitDelay2_DSTATE_gngc))
        {
          /* Switch: '<S37>/Switch1' incorporates:
           *  Constant: '<S37>/Constant1'
           *  Sum: '<S37>/Subtract'
           *  UnitDelay: '<S37>/Unit Delay1'
           */
          rtb_UnitDelay1_gjno = (uint8_T)(VfDRIV_ACCTimeGap - ((uint8_T)1U));
        }
      }

      /* End of Switch: '<S37>/Switch' */
    }

    /* End of Switch: '<S37>/Switch2' */
  }
  else
  {
    rtb_UnitDelay1_gjno = ((uint8_T)4U);
  }

  /* End of Switch: '<S37>/Switch3' */

  /* Saturate: '<S37>/Saturation' */
  if (rtb_UnitDelay1_gjno > ((uint8_T)6U))
  {
    VfDRIV_ACCTimeGap = ((uint8_T)6U);
  }
  else if (rtb_UnitDelay1_gjno < ((uint8_T)4U))
  {
    VfDRIV_ACCTimeGap = ((uint8_T)4U);
  }
  else
  {
    VfDRIV_ACCTimeGap = rtb_UnitDelay1_gjno;
  }

  /* End of Saturate: '<S37>/Saturation' */

  /* Update for UnitDelay: '<S37>/Unit Delay23' */
  DRIV_subsystem_integrated_DW.UnitDelay23_DSTATE_j5wv =
    DRIV_subsystem_integrated_B.FinalSwitch_a45b;

  /* Update for UnitDelay: '<S37>/Unit Delay2' */
  DRIV_subsystem_integrated_DW.UnitDelay2_DSTATE_gngc =
    DRIV_subsystem_integrated_B.FinalSwitch;
}

/*
 * Output and update for atomic system:
 *    '<S30>/SwitchDebounce'
 *    '<S30>/SwitchDebounce1'
 *    '<S30>/SwitchDebounce2'
 *    '<S30>/SwitchDebounce3'
 *    '<S30>/SwitchDebounce4'
 *    '<S30>/SwitchDebounce5'
 */
void DRIV_subsystem_i_SwitchDebounce(boolean_T rtu_SwitchRaw, boolean_T
  rtu_SwitchRaw_Old, uint8_T rtu_debounceThrsh, boolean_T rtu_FinalSwitch_Old,
  uint8_T rtu_SwitchSampleCnt_Old, boolean_T *rty_FinalSwitch, uint8_T
  *rty_SwitchSampleCnt)
{
  *rty_FinalSwitch = rtu_SwitchRaw;
  *rty_SwitchSampleCnt = rtu_SwitchSampleCnt_Old;
  if (rtu_SwitchRaw != rtu_SwitchRaw_Old)
  {
    *rty_SwitchSampleCnt = 0U;
  }
  else if (rtu_SwitchSampleCnt_Old < rtu_debounceThrsh)
  {
    *rty_SwitchSampleCnt = (uint8_T)(((uint32_T)rtu_SwitchSampleCnt_Old) + 1U);
  }
  else
  {
    *rty_FinalSwitch = rtu_FinalSwitch_Old;
  }
}

/* Output and update for atomic system: '<S28>/DtrmnDRIV_ACC_Switch' */
void DtrmnDRIV_ACC_Switch(void)
{
  boolean_T rtb_UnitDelay20;
  boolean_T rtb_UnitDelay13;
  boolean_T rtb_UnitDelay;
  uint8_T rtb_UnitDelay1_mfip;
  boolean_T rtb_UnitDelay17;
  boolean_T rtb_UnitDelay8;
  uint8_T rtb_UnitDelay10;
  boolean_T rtb_UnitDelay18;
  boolean_T rtb_UnitDelay11;
  uint8_T rtb_UnitDelay9;
  boolean_T rtb_UnitDelay15;
  boolean_T rtb_UnitDelay5;
  uint8_T rtb_UnitDelay4;
  boolean_T rtb_UnitDelay16;
  boolean_T rtb_UnitDelay6;
  uint8_T rtb_UnitDelay7;
  boolean_T rtb_UnitDelay14;
  boolean_T rtb_UnitDelay2_dxyf;
  uint8_T rtb_UnitDelay3;
  boolean_T rtb_FinalSwitch;
  uint8_T rtb_SwitchSampleCnt_o22k;
  uint8_T rtb_SwitchSampleCnt_nwf4;
  uint8_T rtb_SwitchSampleCnt;
  uint8_T rtb_SwitchSampleCnt_dtlq;
  uint8_T rtb_SwitchSampleCnt_ny03;
  uint8_T rtb_SwitchSampleCnt_mhl0;

  /* UnitDelay: '<S30>/Unit Delay13' */
  rtb_UnitDelay13 = DRIV_subsystem_integrated_DW.UnitDelay13_DSTATE;

  /* UnitDelay: '<S30>/Unit Delay' */
  rtb_UnitDelay = DRIV_subsystem_integrated_DW.UnitDelay_DSTATE_hbb3;

  /* UnitDelay: '<S30>/Unit Delay1' */
  rtb_UnitDelay1_mfip = DRIV_subsystem_integrated_DW.UnitDelay1_DSTATE_cjxq;

  /* MATLAB Function: '<S30>/SwitchDebounce' incorporates:
   *  Constant: '<S30>/Constant11'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_i_SwitchDebounce
    (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain, rtb_UnitDelay13,
     KcDRIV_ACCSMainSwitchDebounceThrsh, rtb_UnitDelay, rtb_UnitDelay1_mfip,
     &rtb_FinalSwitch, &rtb_SwitchSampleCnt_o22k);

  /* MATLAB Function: '<S30>/ACC_MainSwitch' incorporates:
   *  UnitDelay: '<S30>/Unit Delay12'
   *  UnitDelay: '<S30>/Unit Delay20'
   */
  rtb_UnitDelay20 = (rtb_FinalSwitch &&
                     (!DRIV_subsystem_integrated_DW.UnitDelay12_DSTATE));
  VbDRIV_ACCMainSwitch = ((rtb_UnitDelay20 && VbDRIV_ACCMainSwitch) ||
    ((!(rtb_UnitDelay20 && (!VbDRIV_ACCMainSwitch))) && VbDRIV_ACCMainSwitch));

  /* UnitDelay: '<S30>/Unit Delay17' */
  rtb_UnitDelay17 = DRIV_subsystem_integrated_DW.UnitDelay17_DSTATE;

  /* UnitDelay: '<S30>/Unit Delay8' */
  rtb_UnitDelay8 = DRIV_subsystem_integrated_B.FinalSwitch_a45b;

  /* UnitDelay: '<S30>/Unit Delay10' */
  rtb_UnitDelay10 = DRIV_subsystem_integrated_DW.UnitDelay10_DSTATE;

  /* MATLAB Function: '<S30>/SwitchDebounce4' incorporates:
   *  Constant: '<S30>/Constant15'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_i_SwitchDebounce
    (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapPlus, rtb_UnitDelay17,
     KcDRIV_ACCSTimeGapPlusDebounceThrsh, rtb_UnitDelay8, rtb_UnitDelay10,
     &DRIV_subsystem_integrated_B.FinalSwitch_a45b, &rtb_SwitchSampleCnt_nwf4);

  /* UnitDelay: '<S30>/Unit Delay18' */
  rtb_UnitDelay18 = DRIV_subsystem_integrated_DW.UnitDelay18_DSTATE;

  /* UnitDelay: '<S30>/Unit Delay11' */
  rtb_UnitDelay11 = DRIV_subsystem_integrated_B.FinalSwitch;

  /* UnitDelay: '<S30>/Unit Delay9' */
  rtb_UnitDelay9 = DRIV_subsystem_integrated_DW.UnitDelay9_DSTATE;

  /* MATLAB Function: '<S30>/SwitchDebounce5' incorporates:
   *  Constant: '<S30>/Constant16'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_i_SwitchDebounce
    (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapMinus, rtb_UnitDelay18,
     KcDRIV_ACCSTimeGapMinusDebounceThrsh, rtb_UnitDelay11, rtb_UnitDelay9,
     &DRIV_subsystem_integrated_B.FinalSwitch, &rtb_SwitchSampleCnt);

  /* Outputs for Atomic SubSystem: '<S30>/DtrmnDRIV_TargetTimeGap' */
  DtrmnDRIV_TargetTimeGap();

  /* End of Outputs for SubSystem: '<S30>/DtrmnDRIV_TargetTimeGap' */

  /* Logic: '<S30>/Logical Operator' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_UnitDelay20 = (((VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwValid) &&
                      (VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch))
                     && VbDRIV_ACCMainSwitch);

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant'
   *  Constant: '<S30>/Constant10'
   */
  if (rtb_UnitDelay20)
  {
    DRIV_subsystem_integrated_B.VfDRIV_ACCTimeGap_a2ct = VfDRIV_ACCTimeGap;
  }
  else
  {
    DRIV_subsystem_integrated_B.VfDRIV_ACCTimeGap_a2ct = ((uint8_T)4U);
  }

  if (rtb_UnitDelay20)
  {
    DRIV_subsystem_integrated_B.VbDRIV_ACCMainSwitch_nbff = VbDRIV_ACCMainSwitch;
  }
  else
  {
    DRIV_subsystem_integrated_B.VbDRIV_ACCMainSwitch_nbff = false;
  }

  /* UnitDelay: '<S30>/Unit Delay15' */
  rtb_UnitDelay15 = DRIV_subsystem_integrated_DW.UnitDelay15_DSTATE;

  /* UnitDelay: '<S30>/Unit Delay5' */
  rtb_UnitDelay5 = VbDRIV_ACCResumeSwitch;

  /* UnitDelay: '<S30>/Unit Delay4' */
  rtb_UnitDelay4 = DRIV_subsystem_integrated_DW.UnitDelay4_DSTATE;

  /* MATLAB Function: '<S30>/SwitchDebounce2' incorporates:
   *  Constant: '<S30>/Constant13'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_i_SwitchDebounce
    (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwResume, rtb_UnitDelay15,
     KcDRIV_ACCSResumeSwitchDebounceThrsh, rtb_UnitDelay5, rtb_UnitDelay4,
     &VbDRIV_ACCResumeSwitch, &rtb_SwitchSampleCnt_dtlq);

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant5'
   */
  if (rtb_UnitDelay20)
  {
    DRIV_subsystem_integrated_B.VbDRIV_ACCResumeSwitch_i0xk =
      VbDRIV_ACCResumeSwitch;
  }
  else
  {
    DRIV_subsystem_integrated_B.VbDRIV_ACCResumeSwitch_i0xk = false;
  }

  /* Switch: '<S30>/Switch1' incorporates:
   *  Constant: '<S30>/Constant17'
   *  Constant: '<S30>/Constant18'
   *  Sum: '<S30>/Add'
   *  UnitDelay: '<S30>/Unit Delay19'
   */
  if (VbDRIV_ACCResumeSwitch)
  {
    DRIV_subsystem_integrated_B.Gain =
      DRIV_subsystem_integrated_DW.UnitDelay19_DSTATE + 0.01F;
  }
  else
  {
    DRIV_subsystem_integrated_B.Gain = 0.0F;
  }

  /* End of Switch: '<S30>/Switch1' */

  /* UnitDelay: '<S30>/Unit Delay22' */
  DRIV_subsystem_integrated_B.VbDRIV_EnableAutoDrive =
    DRIV_subsystem_integrated_DW.UnitDelay22_DSTATE;

  /* UnitDelay: '<S30>/Unit Delay23' */
  DRIV_subsystem_integrated_B.VbLCC_ButtonActivate =
    DRIV_subsystem_integrated_DW.UnitDelay23_DSTATE;

  /* UnitDelay: '<S30>/Unit Delay16' */
  rtb_UnitDelay16 = DRIV_subsystem_integrated_DW.UnitDelay16_DSTATE;

  /* UnitDelay: '<S30>/Unit Delay6' */
  rtb_UnitDelay6 = DRIV_subsystem_integrated_B.FinalSwitch_be4y;

  /* UnitDelay: '<S30>/Unit Delay7' */
  rtb_UnitDelay7 = DRIV_subsystem_integrated_DW.UnitDelay7_DSTATE;

  /* MATLAB Function: '<S30>/SwitchDebounce3' incorporates:
   *  Constant: '<S30>/Constant14'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_i_SwitchDebounce
    (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwSet, rtb_UnitDelay16,
     KcDRIV_ACCSSetSwitchDebounceThrsh, rtb_UnitDelay6, rtb_UnitDelay7,
     &DRIV_subsystem_integrated_B.FinalSwitch_be4y, &rtb_SwitchSampleCnt_ny03);

  /* UnitDelay: '<S30>/Unit Delay24' */
  DRIV_subsystem_integrated_B.VbACC_ButtonActivate =
    DRIV_subsystem_integrated_DW.UnitDelay24_DSTATE;

  /* Switch: '<S30>/Switch2' incorporates:
   *  Constant: '<S30>/Constant19'
   *  Constant: '<S30>/Constant20'
   *  Sum: '<S30>/Add1'
   *  UnitDelay: '<S30>/Unit Delay21'
   */
  if (DRIV_subsystem_integrated_B.FinalSwitch_be4y)
  {
    DRIV_subsystem_integrated_B.Switch2 += 0.01F;
  }
  else
  {
    DRIV_subsystem_integrated_B.Switch2 = 0.0F;
  }

  /* End of Switch: '<S30>/Switch2' */

  /* UnitDelay: '<S30>/Unit Delay14' */
  rtb_UnitDelay14 = DRIV_subsystem_integrated_DW.UnitDelay14_DSTATE;

  /* UnitDelay: '<S30>/Unit Delay2' */
  rtb_UnitDelay2_dxyf = VbDRIV_ACCCancelSwitch;

  /* UnitDelay: '<S30>/Unit Delay3' */
  rtb_UnitDelay3 = DRIV_subsystem_integrated_DW.UnitDelay3_DSTATE;

  /* MATLAB Function: '<S30>/SwitchDebounce1' incorporates:
   *  Constant: '<S30>/Constant12'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_i_SwitchDebounce
    (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwCancel, rtb_UnitDelay14,
     KcDRIV_ACCSCancelSwitchDebounceThrsh, rtb_UnitDelay2_dxyf, rtb_UnitDelay3,
     &VbDRIV_ACCCancelSwitch, &rtb_SwitchSampleCnt_mhl0);

  /* UnitDelay: '<S30>/Unit Delay25' */
  DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o =
    DRIV_subsystem_integrated_DW.UnitDelay25_DSTATE;

  /* MATLAB Function: '<S30>/DtrmnDRIV_TargetSpeed' */
  DtrmnDRIV_TargetSpeed();

  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Constant8'
   *  Constant: '<S30>/Constant9'
   */
  if (rtb_UnitDelay20)
  {
    DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o =
      VfDRIV_ACCDriveSetSpeed;
  }
  else
  {
    DRIV_subsystem_integrated_B.VfDRIV_ACCDriveSetSpeed_jz5o = 0.0F;
  }

  if (rtb_UnitDelay20)
  {
    DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt =
      VbDRIV_ACCCancelSwitch;
  }
  else
  {
    DRIV_subsystem_integrated_B.VbDRIV_ACCCancelSwitch_juwt = false;
  }

  /* Update for UnitDelay: '<S30>/Unit Delay13' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_integrated_DW.UnitDelay13_DSTATE =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain;

  /* Update for UnitDelay: '<S30>/Unit Delay' */
  DRIV_subsystem_integrated_DW.UnitDelay_DSTATE_hbb3 = rtb_FinalSwitch;

  /* Update for UnitDelay: '<S30>/Unit Delay1' */
  DRIV_subsystem_integrated_DW.UnitDelay1_DSTATE_cjxq = rtb_SwitchSampleCnt_o22k;

  /* Update for UnitDelay: '<S30>/Unit Delay12' */
  DRIV_subsystem_integrated_DW.UnitDelay12_DSTATE = rtb_FinalSwitch;

  /* Update for UnitDelay: '<S30>/Unit Delay17' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_integrated_DW.UnitDelay17_DSTATE =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapPlus;

  /* Update for UnitDelay: '<S30>/Unit Delay10' */
  DRIV_subsystem_integrated_DW.UnitDelay10_DSTATE = rtb_SwitchSampleCnt_nwf4;

  /* Update for UnitDelay: '<S30>/Unit Delay18' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_integrated_DW.UnitDelay18_DSTATE =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapMinus;

  /* Update for UnitDelay: '<S30>/Unit Delay9' */
  DRIV_subsystem_integrated_DW.UnitDelay9_DSTATE = rtb_SwitchSampleCnt;

  /* Update for UnitDelay: '<S30>/Unit Delay15' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_integrated_DW.UnitDelay15_DSTATE =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwResume;

  /* Update for UnitDelay: '<S30>/Unit Delay4' */
  DRIV_subsystem_integrated_DW.UnitDelay4_DSTATE = rtb_SwitchSampleCnt_dtlq;

  /* Update for UnitDelay: '<S30>/Unit Delay19' */
  DRIV_subsystem_integrated_DW.UnitDelay19_DSTATE =
    DRIV_subsystem_integrated_B.Gain;

  /* Update for UnitDelay: '<S30>/Unit Delay22' */
  DRIV_subsystem_integrated_DW.UnitDelay22_DSTATE = VbDRIV_ACCMainSwitch;

  /* Update for UnitDelay: '<S30>/Unit Delay23' */
  DRIV_subsystem_integrated_DW.UnitDelay23_DSTATE = VbDRIV_ACCResumeSwitch;

  /* Update for UnitDelay: '<S30>/Unit Delay16' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_integrated_DW.UnitDelay16_DSTATE =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwSet;

  /* Update for UnitDelay: '<S30>/Unit Delay7' */
  DRIV_subsystem_integrated_DW.UnitDelay7_DSTATE = rtb_SwitchSampleCnt_ny03;

  /* Update for UnitDelay: '<S30>/Unit Delay24' */
  DRIV_subsystem_integrated_DW.UnitDelay24_DSTATE =
    DRIV_subsystem_integrated_B.FinalSwitch_be4y;

  /* Update for UnitDelay: '<S30>/Unit Delay14' incorporates:
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  DRIV_subsystem_integrated_DW.UnitDelay14_DSTATE =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwCancel;

  /* Update for UnitDelay: '<S30>/Unit Delay3' */
  DRIV_subsystem_integrated_DW.UnitDelay3_DSTATE = rtb_SwitchSampleCnt_mhl0;

  /* Update for UnitDelay: '<S30>/Unit Delay25' */
  DRIV_subsystem_integrated_DW.UnitDelay25_DSTATE = VfDRIV_ACCDriveSetSpeed;
}

/* System initialize for atomic system: '<S32>/Chart' */
void DRIV_subsystem__Chart_n3en_Init(void)
{
  DRIV_subsystem_integrated_DW.temporalCounter_i1_klcu = 0U;
  DRIV_subsystem_integrated_DW.is_active_c1_DRIV_subsystem_int = 0U;
  DRIV_subsystem_integrated_DW.is_c1_DRIV_subsystem_integrated =
    DRIV_su_IN_NO_ACTIVE_CHILD_e4fj;
}

/* Output and update for atomic system: '<S32>/Chart' */
void DRIV_subsystem_integ_Chart_i1ry(void)
{
  uint8_T rtb_state;

  /* Chart: '<S32>/Chart' incorporates:
   *  Constant: '<S5>/Constant5'
   */
  if (((uint32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_klcu) < 65535U)
  {
    DRIV_subsystem_integrated_DW.temporalCounter_i1_klcu = (uint16_T)((int32_T)
      (((int32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_klcu) + 1));
  }

  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c1_DRIV_subsystem_int) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c1_DRIV_subsystem_int = 1U;
    DRIV_subsystem_integrated_DW.is_c1_DRIV_subsystem_integrated =
      DRIV_subsystem_int_IN_INIT_kkhb;
    DRIV_subsystem_integrated_B.y_iwrs = false;
    rtb_state = 1U;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c1_DRIV_subsystem_integrated)
    {
     case DRIV_subsystem_in_IN_Delay_pspz:
      if (!KbDRIV_Default_EnableAutoDrive)
      {
        DRIV_subsystem_integrated_DW.is_c1_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_INIT_kkhb;
        DRIV_subsystem_integrated_B.y_iwrs = false;
        rtb_state = 1U;
      }
      else if (DRIV_subsystem_integrated_DW.temporalCounter_i1_klcu >=
               ((uint16_T)DRIV_subsystem_integrated_B.Gain))
      {
        DRIV_subsystem_integrated_DW.is_c1_DRIV_subsystem_integrated =
          DRIV_subsystem_i_IN_Raised_fwit;
        DRIV_subsystem_integrated_B.y_iwrs = true;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_iwrs = false;
        rtb_state = 2U;
      }
      break;

     case DRIV_subsystem_int_IN_INIT_kkhb:
      if (KbDRIV_Default_EnableAutoDrive)
      {
        DRIV_subsystem_integrated_DW.is_c1_DRIV_subsystem_integrated =
          DRIV_subsystem_in_IN_Delay_pspz;
        DRIV_subsystem_integrated_DW.temporalCounter_i1_klcu = 0U;
        DRIV_subsystem_integrated_B.y_iwrs = false;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_iwrs = false;
        rtb_state = 1U;
      }
      break;

     default:
      if (!KbDRIV_Default_EnableAutoDrive)
      {
        DRIV_subsystem_integrated_DW.is_c1_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_INIT_kkhb;
        DRIV_subsystem_integrated_B.y_iwrs = false;
        rtb_state = 1U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_iwrs = true;
        rtb_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S32>/Chart' */
}

/* System initialize for atomic system: '<S28>/RisingEdgeDelay1' */
void DRIV_subs_RisingEdgeDelay1_Init(void)
{
  /* SystemInitialize for Chart: '<S33>/Chart' */
  DRIV_subsystem_integrated_DW.temporalCounter_i1_lw4o = 0U;
  DRIV_subsystem_integrated_DW.is_active_c2_DRIV_subsystem_int = 0U;
  DRIV_subsystem_integrated_DW.is_c2_DRIV_subsystem_integrated =
    DRIV_su_IN_NO_ACTIVE_CHILD_kktm;
}

/* Output and update for atomic system: '<S28>/RisingEdgeDelay1' */
void DRIV_subsystem_RisingEdgeDelay1(void)
{
  uint8_T rtb_state;

  /* Chart: '<S33>/Chart' incorporates:
   *  Gain: '<S33>/Gain'
   */
  if (((uint32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_lw4o) < 65535U)
  {
    DRIV_subsystem_integrated_DW.temporalCounter_i1_lw4o = (uint16_T)((int32_T)
      (((int32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_lw4o) + 1));
  }

  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c2_DRIV_subsystem_int) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c2_DRIV_subsystem_int = 1U;
    DRIV_subsystem_integrated_DW.is_c2_DRIV_subsystem_integrated =
      DRIV_subsystem_int_IN_INIT_md5n;
    DRIV_subsystem_integrated_B.y_ddol = false;
    rtb_state = 1U;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c2_DRIV_subsystem_integrated)
    {
     case DRIV_subsystem_in_IN_Delay_aqht:
      if (!DRIV_subsystem_integrated_B.SignalConversion1)
      {
        DRIV_subsystem_integrated_DW.is_c2_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_INIT_md5n;
        DRIV_subsystem_integrated_B.y_ddol = false;
        rtb_state = 1U;
      }
      else if (DRIV_subsystem_integrated_DW.temporalCounter_i1_lw4o >=
               ((uint16_T)((real32_T)(100.0F * DRIV_subsystem_integrated_B.Gain))))
      {
        DRIV_subsystem_integrated_DW.is_c2_DRIV_subsystem_integrated =
          DRIV_subsystem_i_IN_Raised_hfn4;
        DRIV_subsystem_integrated_B.y_ddol = true;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_ddol = false;
        rtb_state = 2U;
      }
      break;

     case DRIV_subsystem_int_IN_INIT_md5n:
      if (DRIV_subsystem_integrated_B.SignalConversion1)
      {
        DRIV_subsystem_integrated_DW.is_c2_DRIV_subsystem_integrated =
          DRIV_subsystem_in_IN_Delay_aqht;
        DRIV_subsystem_integrated_DW.temporalCounter_i1_lw4o = 0U;
        DRIV_subsystem_integrated_B.y_ddol = false;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_ddol = false;
        rtb_state = 1U;
      }
      break;

     default:
      if (!DRIV_subsystem_integrated_B.SignalConversion1)
      {
        DRIV_subsystem_integrated_DW.is_c2_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_INIT_md5n;
        DRIV_subsystem_integrated_B.y_ddol = false;
        rtb_state = 1U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_ddol = true;
        rtb_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S33>/Chart' */
}

/* System initialize for atomic system: '<S34>/Chart' */
void DRIV_subsystem__Chart_nkf4_Init(void)
{
  DRIV_subsystem_integrated_DW.temporalCounter_i1_kn0e = 0U;
  DRIV_subsystem_integrated_DW.is_active_c15_DRIV_subsystem_in = 0U;
  DRIV_subsystem_integrated_DW.is_c15_DRIV_subsystem_integrate =
    DRIV_su_IN_NO_ACTIVE_CHILD_kjr0;
}

/* Output and update for atomic system: '<S34>/Chart' */
void DRIV_subsystem_integ_Chart_absx(void)
{
  uint8_T rtb_state;

  /* Chart: '<S34>/Chart' */
  if (((uint32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_kn0e) < 65535U)
  {
    DRIV_subsystem_integrated_DW.temporalCounter_i1_kn0e = (uint16_T)((int32_T)
      (((int32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_kn0e) + 1));
  }

  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c15_DRIV_subsystem_in) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c15_DRIV_subsystem_in = 1U;
    DRIV_subsystem_integrated_DW.is_c15_DRIV_subsystem_integrate =
      DRIV_subsystem_int_IN_INIT_ihzb;
    DRIV_subsystem_integrated_B.y_k4sv = false;
    rtb_state = 1U;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c15_DRIV_subsystem_integrate)
    {
     case DRIV_subsystem_in_IN_Delay_h3xx:
      if (!DRIV_subsystem_integrated_B.VbACC_ButtonActivate)
      {
        DRIV_subsystem_integrated_DW.is_c15_DRIV_subsystem_integrate =
          DRIV_subsystem_int_IN_INIT_ihzb;
        DRIV_subsystem_integrated_B.y_k4sv = false;
        rtb_state = 1U;
      }
      else if (DRIV_subsystem_integrated_DW.temporalCounter_i1_kn0e >=
               ((uint16_T)DRIV_subsystem_integrated_B.Gain))
      {
        DRIV_subsystem_integrated_DW.is_c15_DRIV_subsystem_integrate =
          DRIV_subsystem_i_IN_Raised_nxbf;
        DRIV_subsystem_integrated_B.y_k4sv = true;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_k4sv = false;
        rtb_state = 2U;
      }
      break;

     case DRIV_subsystem_int_IN_INIT_ihzb:
      if (DRIV_subsystem_integrated_B.VbACC_ButtonActivate)
      {
        DRIV_subsystem_integrated_DW.is_c15_DRIV_subsystem_integrate =
          DRIV_subsystem_in_IN_Delay_h3xx;
        DRIV_subsystem_integrated_DW.temporalCounter_i1_kn0e = 0U;
        DRIV_subsystem_integrated_B.y_k4sv = false;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_k4sv = false;
        rtb_state = 1U;
      }
      break;

     default:
      if (!DRIV_subsystem_integrated_B.VbACC_ButtonActivate)
      {
        DRIV_subsystem_integrated_DW.is_c15_DRIV_subsystem_integrate =
          DRIV_subsystem_int_IN_INIT_ihzb;
        DRIV_subsystem_integrated_B.y_k4sv = false;
        rtb_state = 1U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y_k4sv = true;
        rtb_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S34>/Chart' */
}

/* System initialize for atomic system: '<S85>/Chart' */
void DRIV_subsystem__Chart_nlhm_Init(void)
{
  DRIV_subsystem_integrated_DW.temporalCounter_i1_oc2i = 0U;
  DRIV_subsystem_integrated_DW.is_active_c9_DRIV_subsystem_int = 0U;
  DRIV_subsystem_integrated_DW.is_c9_DRIV_subsystem_integrated =
    DRIV_su_IN_NO_ACTIVE_CHILD_cmbc;
}

/* Output and update for atomic system: '<S85>/Chart' */
void DRIV_subsystem_integ_Chart_hsbz(void)
{
  uint8_T rtb_state;

  /* Chart: '<S85>/Chart' */
  if (((uint32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_oc2i) < 65535U)
  {
    DRIV_subsystem_integrated_DW.temporalCounter_i1_oc2i = (uint16_T)((int32_T)
      (((int32_T)DRIV_subsystem_integrated_DW.temporalCounter_i1_oc2i) + 1));
  }

  if (((uint32_T)DRIV_subsystem_integrated_DW.is_active_c9_DRIV_subsystem_int) ==
      0U)
  {
    DRIV_subsystem_integrated_DW.is_active_c9_DRIV_subsystem_int = 1U;
    DRIV_subsystem_integrated_DW.is_c9_DRIV_subsystem_integrated =
      DRIV_subsystem_int_IN_INIT_homc;
    DRIV_subsystem_integrated_B.y = false;
    rtb_state = 1U;
  }
  else
  {
    switch (DRIV_subsystem_integrated_DW.is_c9_DRIV_subsystem_integrated)
    {
     case DRIV_subsystem_in_IN_Delay_pgip:
      if (!DRIV_subsystem_integrated_B.VbACC_ButtonActivate)
      {
        DRIV_subsystem_integrated_DW.is_c9_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_INIT_homc;
        DRIV_subsystem_integrated_B.y = false;
        rtb_state = 1U;
      }
      else if (DRIV_subsystem_integrated_DW.temporalCounter_i1_oc2i >=
               ((uint16_T)DRIV_subsystem_integrated_B.Gain))
      {
        DRIV_subsystem_integrated_DW.is_c9_DRIV_subsystem_integrated =
          DRIV_subsystem_i_IN_Raised_la3x;
        DRIV_subsystem_integrated_B.y = true;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y = false;
        rtb_state = 2U;
      }
      break;

     case DRIV_subsystem_int_IN_INIT_homc:
      if (DRIV_subsystem_integrated_B.VbACC_ButtonActivate)
      {
        DRIV_subsystem_integrated_DW.is_c9_DRIV_subsystem_integrated =
          DRIV_subsystem_in_IN_Delay_pgip;
        DRIV_subsystem_integrated_DW.temporalCounter_i1_oc2i = 0U;
        DRIV_subsystem_integrated_B.y = false;
        rtb_state = 2U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y = false;
        rtb_state = 1U;
      }
      break;

     default:
      if (!DRIV_subsystem_integrated_B.VbACC_ButtonActivate)
      {
        DRIV_subsystem_integrated_DW.is_c9_DRIV_subsystem_integrated =
          DRIV_subsystem_int_IN_INIT_homc;
        DRIV_subsystem_integrated_B.y = false;
        rtb_state = 1U;
      }
      else
      {
        DRIV_subsystem_integrated_B.y = true;
        rtb_state = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S85>/Chart' */
}

/* System initialize for atomic system: '<S1>/DtrmnDRIV_RunStatus' */
void DtrmnDRIV_RunStatus_Init(void)
{
  /* SystemInitialize for Chart: '<S85>/Chart' */
  DRIV_subsystem__Chart_nlhm_Init();

  /* SystemInitialize for IfAction SubSystem: '<S48>/DRIV_LC_Intention_Judge' */
  DRIV_LC_Intention_Judge_Init();

  /* End of SystemInitialize for SubSystem: '<S48>/DRIV_LC_Intention_Judge' */

  /* SystemInitialize for Chart: '<S32>/Chart' */
  DRIV_subsystem__Chart_n3en_Init();

  /* SystemInitialize for Atomic SubSystem: '<S28>/RisingEdgeDelay1' */
  DRIV_subs_RisingEdgeDelay1_Init();

  /* End of SystemInitialize for SubSystem: '<S28>/RisingEdgeDelay1' */

  /* SystemInitialize for Chart: '<S34>/Chart' */
  DRIV_subsystem__Chart_nkf4_Init();
}

/* Start for atomic system: '<S1>/DtrmnDRIV_RunStatus' */
void DtrmnDRIV_RunStatus_Start(void)
{
  /* Start for DataStoreMemory: '<S48>/Data Store Memory' */
  DRIV_subsystem_integrated_DW.KfDRIV_w_LaneWidthMax_cdo4 =
    KfDRIV_w_LaneWidthMax;

  /* Start for DataStoreMemory: '<S48>/KfDRIV_d_TouchedNewLaneDist' */
  DRIV_subsystem_integrated_DW.KfDRIV_d_TouchedNewLaneDis_mmyg =
    KfDRIV_d_TouchedNewLaneDist;
}

/* Output and update for atomic system: '<S1>/DtrmnDRIV_RunStatus' */
void DtrmnDRIV_RunStatus(void)
{
  int_T idxDelay;
  boolean_T rtb_LogicalOperator1_b2zg;
  real32_T VbDRIV_Norm_driving_tmp;
  real32_T Gain_tmp;

  /* Outputs for Atomic SubSystem: '<S28>/DtrmnDRIV_ACC_Switch' */
  DtrmnDRIV_ACC_Switch();

  /* End of Outputs for SubSystem: '<S28>/DtrmnDRIV_ACC_Switch' */

  /* DataStoreWrite: '<S48>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn2' incorporates:
   *  Constant: '<S48>/Constant5'
   */
  DRIV_subsystem_integrated_DW.KfDRIV_w_LaneWidthMax_cdo4 =
    KfDRIV_w_LaneWidthMax;

  /* RelationalOperator: '<S80>/Relational Operator8' incorporates:
   *  Constant: '<S80>/Constant8'
   */
  DRIV_subsystem_integrated_B.VbACC_ButtonActivate = (VfDRIV_Steer_Torque_Filter
    <= kfDRIV_M_TorqueOverrideThreshold_Auto);

  /* Gain: '<S85>/Gain' incorporates:
   *  Constant: '<S80>/Constant10'
   */
  DRIV_subsystem_integrated_B.Gain = 100.0F * KfDRIV_t_WaitTimeDriverDistracted;

  /* Chart: '<S85>/Chart' */
  DRIV_subsystem_integ_Chart_hsbz();

  /* Product: '<S79>/Divide1' incorporates:
   *  Abs: '<S79>/Abs'
   *  Constant: '<S79>/Constant'
   *  Constant: '<S79>/Constant2'
   *  Delay: '<S79>/Delay1'
   *  Product: '<S79>/Product'
   *  Sum: '<S79>/Subtract'
   */
  VfDRIV_Steer_Torque_Rate = ((real32_T)fabs((real_T)((real32_T)
    (VfDRIV_Steer_Torque_Filter - DRIV_subsystem_integrated_DW.Delay1_DSTATE[0]))))
    / (kfDRIV_t_PeriodFunctionCall * 20.0F);

  /* Logic: '<S29>/Logical Operator1' incorporates:
   *  DataTypeConversion: '<S29>/Data Type Conversion1'
   *  DataTypeConversion: '<S29>/Data Type Conversion2'
   *  Inport: '<Root>/COMM_CANR_Databus'
   */
  rtb_LogicalOperator1_b2zg =
    ((VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState) ||
     (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState));

  /* Abs: '<S79>/Abs5' incorporates:
   *  Abs: '<S80>/Abs'
   *  Abs: '<S81>/Abs1'
   *  Abs: '<S81>/Abs5'
   */
  VbDRIV_Norm_driving_tmp = (real32_T)fabs((real_T)VfDRIV_Steer_Torque_Filter);

  /* Logic: '<S79>/Logical Operator1' incorporates:
   *  Abs: '<S79>/Abs5'
   *  Constant: '<S79>/Constant1'
   *  Constant: '<S79>/Constant6'
   *  Logic: '<S79>/Logical Operator4'
   *  RelationalOperator: '<S79>/Relational Operator1'
   *  RelationalOperator: '<S79>/Relational Operator6'
   */
  VbDRIV_Norm_driving = (((VbDRIV_Norm_driving_tmp >
    kfDRIV_M_TorqueOverrideThreshold) && (VfDRIV_Steer_Torque_Rate >
    kfDRIV_TorqueRateThreshold)) || rtb_LogicalOperator1_b2zg);

  /* Logic: '<S81>/Logical Operator4' incorporates:
   *  Constant: '<S81>/Constant7'
   *  Constant: '<S81>/Constant8'
   *  Constant: '<S87>/Constant'
   *  Logic: '<S81>/Logical Operator5'
   *  Logic: '<S81>/Logical Operator6'
   *  RelationalOperator: '<S81>/Relational Operator1'
   *  RelationalOperator: '<S81>/Relational Operator4'
   *  RelationalOperator: '<S81>/Relational Operator7'
   */
  VbDRIV_Driver_Take_Over = (((VbDRIV_Norm_driving_tmp >
    kfDRIV_M_TorqueOverrideThreshold_LCC) &&
    (DRIV_subsystem_integrated_B.SignalConversion1)) ||
    ((VbDRIV_Norm_driving_tmp > kfDRIV_M_TorqueOverrideThreshold_ACC) &&
     (DRIV_subsystem_integrated_B.SignalConversion == ACCS_mode_on)));

  /* Logic: '<S80>/Logical Operator5' incorporates:
   *  Constant: '<S80>/Constant1'
   *  Constant: '<S80>/Constant2'
   *  Constant: '<S80>/Constant3'
   *  Constant: '<S80>/Constant5'
   *  Constant: '<S83>/Constant'
   *  Constant: '<S84>/Constant'
   *  Inport: '<Root>/COMM_CANR_Databus'
   *  Logic: '<S80>/Logical Operator1'
   *  Logic: '<S80>/Logical Operator15'
   *  Logic: '<S80>/Logical Operator16'
   *  Logic: '<S80>/Logical Operator17'
   *  Logic: '<S80>/Logical Operator2'
   *  Logic: '<S80>/Logical Operator4'
   *  Logic: '<S80>/Logical Operator6'
   *  Logic: '<S80>/Logical Operator8'
   *  RelationalOperator: '<S80>/Relational Operator1'
   *  RelationalOperator: '<S80>/Relational Operator3'
   *  RelationalOperator: '<S80>/Relational Operator4'
   *  RelationalOperator: '<S80>/Relational Operator5'
   *  RelationalOperator: '<S80>/Relational Operator6'
   *  RelationalOperator: '<S80>/Relational Operator7'
   */
  VbDRIV_Driver_Distracted = ((((DRIV_subsystem_integrated_B.y) &&
    (!((DRIV_subsystem_integrated_B.SignalConversion1) ||
       (DRIV_subsystem_integrated_B.SignalConversion == ACCS_mode_on)))) ||
    (((((VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition == 0.0F)
        || (VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition ==
            0.0F)) || ((rtb_LogicalOperator1_b2zg ? 1 : 0) == 0)) &&
      (VbDRIV_Norm_driving_tmp < kfDRIV_M_TorqueThreshold_Distracted)) &&
     (!((DRIV_subsystem_integrated_B.SignalConversion1) ||
        (DRIV_subsystem_integrated_B.SignalConversion == ACCS_mode_on))))) ||
    (DRIV_subsystem_integrate_ConstB.LogicalOperator7));

  /* Logic: '<S49>/Logical Operator2' incorporates:
   *  Logic: '<S49>/Logical Operator1'
   *  Logic: '<S49>/Logical Operator13'
   */
  VbDIRV_Override_Steering = ((VbDRIV_Norm_driving || VbDRIV_Driver_Take_Over) &&
    (!VbDRIV_Driver_Distracted));

  /* DataStoreWrite: '<S48>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn1' incorporates:
   *  Constant: '<S48>/Constant8'
   */
  DRIV_subsystem_integrated_DW.KfDRIV_d_TouchedNewLaneDis_mmyg =
    KfDRIV_d_TouchedNewLaneDist;

  /* If: '<S48>/If' */
  if (VbDIRV_Override_Steering)
  {
    /* Outputs for IfAction SubSystem: '<S48>/DRIV_LC_Intention_Judge' incorporates:
     *  ActionPort: '<S50>/Action Port'
     */
    DRIV_LC_Intention_Judge();

    /* End of Outputs for SubSystem: '<S48>/DRIV_LC_Intention_Judge' */
  }
  else
  {
    /* Outputs for IfAction SubSystem: '<S48>/DRIV_OverrideSteer_DefaultData' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    DRIV_OverrideSteerDefaultData();

    /* End of Outputs for SubSystem: '<S48>/DRIV_OverrideSteer_DefaultData' */
  }

  /* End of If: '<S48>/If' */

  /* Product: '<S28>/Product2' incorporates:
   *  Constant: '<S28>/Constant6'
   *  Constant: '<S28>/Constant7'
   *  Product: '<S28>/Product'
   */
  VbDRIV_Norm_driving_tmp = kfDRIV_t_PeriodFunctionCall * ((real32_T)
    kfDRIV_DelayLoopGain);

  /* Gain: '<S32>/Gain' incorporates:
   *  Gain: '<S34>/Gain'
   *  Product: '<S28>/Product2'
   */
  Gain_tmp = 100.0F * VbDRIV_Norm_driving_tmp;
  DRIV_subsystem_integrated_B.Gain = Gain_tmp;

  /* Chart: '<S32>/Chart' */
  DRIV_subsystem_integ_Chart_i1ry();

  /* Product: '<S28>/Product' */
  DRIV_subsystem_integrated_B.Gain = VbDRIV_Norm_driving_tmp;

  /* Outputs for Atomic SubSystem: '<S28>/RisingEdgeDelay1' */
  DRIV_subsystem_RisingEdgeDelay1();

  /* End of Outputs for SubSystem: '<S28>/RisingEdgeDelay1' */

  /* RelationalOperator: '<S28>/Relational Operator4' incorporates:
   *  Constant: '<S31>/Constant'
   */
  DRIV_subsystem_integrated_B.VbACC_ButtonActivate =
    (DRIV_subsystem_integrated_B.SignalConversion == ACCS_mode_on);

  /* Gain: '<S34>/Gain' */
  DRIV_subsystem_integrated_B.Gain = Gain_tmp;

  /* Chart: '<S34>/Chart' */
  DRIV_subsystem_integ_Chart_absx();

  /* SignalConversion: '<S28>/Signal Conversion3' */
  DRIV_subsystem_integrated_B.VbACC_ButtonActivate =
    DRIV_subsystem_integrated_B.y_k4sv;

  /* SignalConversion: '<S28>/Signal Conversion1' */
  DRIV_subsystem_integrated_B.VbLCC_ButtonActivate =
    DRIV_subsystem_integrated_B.y_ddol;

  /* SignalConversion: '<S28>/Signal Conversion2' */
  DRIV_subsystem_integrated_B.VbDRIV_EnableAutoDrive =
    DRIV_subsystem_integrated_B.y_iwrs;

  /* Update for Delay: '<S79>/Delay1' */
  for (idxDelay = 0; idxDelay < 19; idxDelay++)
  {
    DRIV_subsystem_integrated_DW.Delay1_DSTATE[idxDelay] =
      DRIV_subsystem_integrated_DW.Delay1_DSTATE[idxDelay + 1];
  }

  DRIV_subsystem_integrated_DW.Delay1_DSTATE[19] = VfDRIV_Steer_Torque_Filter;

  /* End of Update for Delay: '<S79>/Delay1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
