/*
 * File: comm_receive.c
 *
 * Code generated for Simulink model 'COMM_subsystem_integrated'.
 *
 * Model version                  : 1.1787
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Jun 10 09:20:56 2020
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

#include "comm_receive.h"

/* Include model header file for global data */
#include "COMM_subsystem_integrated.h"
#include "COMM_subsystem_integrated_private.h"

/* Forward declaration for local functions */
static void COMM_s_MedianFilterCG_resetImpl(dsp_private_MedianFilterCG_CO_T *obj);
static void C_MedianFilterCG_trickleDownMax(dsp_private_MedianFilterCG_CO_T *obj,
  real32_T i);
static void C_MedianFilterCG_trickleDownMin(dsp_private_MedianFilterCG_CO_T *obj,
  real32_T i);

/*
 * Output and update for action system:
 *    '<S1>/Switch Case Action Subsystem'
 *    '<S1>/Switch Case Action Subsystem1'
 *    '<S1>/Switch Case Action Subsystem2'
 *    '<S1>/Switch Case Action Subsystem6'
 */
void COMM__SwitchCaseActionSubsystem(COMM_Bus_VEH_Config *rty_Out1)
{
  /* BusCreator: '<S8>/Bus Creator' incorporates:
   *  Constant: '<S8>/Constant'
   *  Constant: '<S8>/Constant1'
   *  Constant: '<S8>/Constant10'
   *  Constant: '<S8>/Constant11'
   *  Constant: '<S8>/Constant12'
   *  Constant: '<S8>/Constant13'
   *  Constant: '<S8>/Constant14'
   *  Constant: '<S8>/Constant15'
   *  Constant: '<S8>/Constant2'
   *  Constant: '<S8>/Constant3'
   *  Constant: '<S8>/Constant4'
   *  Constant: '<S8>/Constant5'
   *  Constant: '<S8>/Constant6'
   *  Constant: '<S8>/Constant7'
   *  Constant: '<S8>/Constant8'
   *  Constant: '<S8>/Constant9'
   */
  rty_Out1->VfCOMM_VEH_MinTurnRadius = 4.98F;
  rty_Out1->VfCOMM_VEH_AngOrigin2FrontWheel = 0.3333579F;
  rty_Out1->VfCOMM_VEH_YawInertia_Z = 2388.7F;
  rty_Out1->VfCOMM_VEH_DisOrigin2FrontWheel = 2490.0F;
  rty_Out1->VfCOMM_VEH_DisOrigin2End = 810.0F;
  rty_Out1->VfCOMM_VEH_DisOrigin2RearAxle = 0.0F;
  rty_Out1->VfCOMM_VEH_DisOrigin2Head = 3320.0F;
  rty_Out1->VfCOMM_VEH_Width = 1730.0F;
  rty_Out1->VfACCS_VEH_WheelDiameter = 316.0F;
  rty_Out1->VfCOMM_VEH_Length = 4130.0F;
  rty_Out1->VfCOMM_VEH_StiffnessRear = 1298.60498F;
  rty_Out1->VfCOMM_VEH_StiffnessFront = 1298.60498F;
  rty_Out1->VfCOMM_VEH_DisLeft2Right = 1750.0F;
  rty_Out1->VfCOMM_VEH_DisCentorid2Front = 1121.0F;
  rty_Out1->VfCOMM_VEH_Mass = 1264.0F;
  rty_Out1->VfCOMM_VEH_DisFront2Rear = 2490.0F;
}

static void COMM_s_MedianFilterCG_resetImpl(dsp_private_MedianFilterCG_CO_T *obj)
{
  real32_T cnt1;
  real32_T cnt2;
  int32_T i;

  /* Start for MATLABSystem: '<S17>/Median Filter1' */
  for (i = 0; i < 5; i++)
  {
    obj->pBuf[i] = 0.0F;
    obj->pPos[i] = 0.0F;
    obj->pHeap[i] = 0.0F;
  }

  obj->pWinLen = 5.0F;
  obj->pIdx = obj->pWinLen;
  obj->pMidHeap = (real32_T)ceil((real_T)((real32_T)((obj->pWinLen + 1.0F) /
    2.0F)));
  cnt1 = (obj->pWinLen - 1.0F) / 2.0F;
  if (cnt1 < 0.0F)
  {
    obj->pMinHeapLength = (real32_T)ceil((real_T)cnt1);
  }
  else
  {
    obj->pMinHeapLength = (real32_T)floor((real_T)cnt1);
  }

  cnt1 = obj->pWinLen / 2.0F;
  if (cnt1 < 0.0F)
  {
    obj->pMaxHeapLength = (real32_T)ceil((real_T)cnt1);
  }
  else
  {
    obj->pMaxHeapLength = (real32_T)floor((real_T)cnt1);
  }

  cnt1 = 1.0F;
  cnt2 = obj->pWinLen;
  for (i = 0; i < 5; i++)
  {
    if (((int32_T)((real32_T)fmod((real_T)((real32_T)(5.0F + (-((real32_T)i)))),
           2.0))) == 0)
    {
      obj->pPos[(5 - i) - 1] = cnt1;
      cnt1++;
    }
    else
    {
      obj->pPos[(5 - i) - 1] = cnt2;
      cnt2--;
    }

    obj->pHeap[((int32_T)obj->pPos[(5 - i) - 1]) - 1] = 5.0F + (-((real32_T)i));
  }

  /* End of Start for MATLABSystem: '<S17>/Median Filter1' */
}

static void C_MedianFilterCG_trickleDownMax(dsp_private_MedianFilterCG_CO_T *obj,
  real32_T i)
{
  real32_T temp;
  real32_T u;
  real32_T ind2;
  int32_T temp_tmp;
  boolean_T exitg1;
  exitg1 = false;
  while ((!exitg1) && (i >= (-obj->pMaxHeapLength)))
  {
    if (((i < -1.0F) && (i > (-obj->pMaxHeapLength))) && (obj->pBuf[((int32_T)
          obj->pHeap[((int32_T)((real32_T)(i + obj->pMidHeap))) - 1]) - 1] <
         obj->pBuf[((int32_T)obj->pHeap[((int32_T)((real32_T)((i - 1.0F) +
             obj->pMidHeap))) - 1]) - 1]))
    {
      i--;
    }

    u = i / 2.0F;
    if (u < 0.0F)
    {
      u = (real32_T)ceil((real_T)u);
    }
    else
    {
      u = (real32_T)floor((real_T)u);
    }

    ind2 = i + obj->pMidHeap;
    if (!(obj->pBuf[((int32_T)obj->pHeap[((int32_T)((real32_T)(u + obj->pMidHeap)))
                     - 1]) - 1] < obj->pBuf[((int32_T)obj->pHeap[((int32_T)ind2)
          - 1]) - 1]))
    {
      exitg1 = true;
    }
    else
    {
      u = i / 2.0F;
      if (u < 0.0F)
      {
        u = (real32_T)ceil((real_T)u);
      }
      else
      {
        u = (real32_T)floor((real_T)u);
      }

      u += obj->pMidHeap;
      temp_tmp = ((int32_T)u) - 1;
      temp = obj->pHeap[temp_tmp];
      obj->pHeap[temp_tmp] = obj->pHeap[((int32_T)ind2) - 1];
      obj->pHeap[((int32_T)ind2) - 1] = temp;
      obj->pPos[((int32_T)obj->pHeap[((int32_T)u) - 1]) - 1] = u;
      obj->pPos[((int32_T)obj->pHeap[((int32_T)ind2) - 1]) - 1] = ind2;
      i *= 2.0F;
    }
  }
}

static void C_MedianFilterCG_trickleDownMin(dsp_private_MedianFilterCG_CO_T *obj,
  real32_T i)
{
  real32_T temp;
  real32_T u;
  real32_T ind1;
  int32_T tmp;
  boolean_T exitg1;
  exitg1 = false;
  while ((!exitg1) && (i <= obj->pMinHeapLength))
  {
    if (((i > 1.0F) && (i < obj->pMinHeapLength)) && (obj->pBuf[((int32_T)
          obj->pHeap[((int32_T)((real32_T)((i + 1.0F) + obj->pMidHeap))) - 1]) -
         1] < obj->pBuf[((int32_T)obj->pHeap[((int32_T)((real32_T)(i +
             obj->pMidHeap))) - 1]) - 1]))
    {
      i++;
    }

    u = i / 2.0F;
    if (u < 0.0F)
    {
      u = (real32_T)ceil((real_T)u);
    }
    else
    {
      u = (real32_T)floor((real_T)u);
    }

    ind1 = i + obj->pMidHeap;
    if (!(obj->pBuf[((int32_T)obj->pHeap[((int32_T)ind1) - 1]) - 1] < obj->pBuf
          [((int32_T)obj->pHeap[((int32_T)((real32_T)(u + obj->pMidHeap))) - 1])
          - 1]))
    {
      exitg1 = true;
    }
    else
    {
      u = i / 2.0F;
      if (u < 0.0F)
      {
        u = (real32_T)ceil((real_T)u);
      }
      else
      {
        u = (real32_T)floor((real_T)u);
      }

      u += obj->pMidHeap;
      temp = obj->pHeap[((int32_T)ind1) - 1];
      tmp = ((int32_T)u) - 1;
      obj->pHeap[((int32_T)ind1) - 1] = obj->pHeap[tmp];
      obj->pHeap[tmp] = temp;
      obj->pPos[((int32_T)obj->pHeap[((int32_T)ind1) - 1]) - 1] = ind1;
      obj->pPos[((int32_T)obj->pHeap[((int32_T)u) - 1]) - 1] = u;
      i *= 2.0F;
    }
  }
}

/*
 * System initialize for atomic system:
 *    'synthesized block'
 *    'synthesized block'
 *    'synthesized block'
 *    'synthesized block'
 *    'synthesized block'
 */
void COMM_subsyst_MedianFilter1_Init(DW_MedianFilter1_COMM_subsyst_T *localDW)
{
  /* Start for MATLABSystem: '<S17>/Median Filter1' */
  if (localDW->obj.pMID.isInitialized == 1)
  {
    COMM_s_MedianFilterCG_resetImpl(&localDW->obj.pMID);
  }

  /* End of Start for MATLABSystem: '<S17>/Median Filter1' */
}

/*
 * Start for atomic system:
 *    'synthesized block'
 *    'synthesized block'
 *    'synthesized block'
 *    'synthesized block'
 *    'synthesized block'
 */
void COMM_subsys_MedianFilter1_Start(DW_MedianFilter1_COMM_subsyst_T *localDW)
{
  dsp_MedianFilter_COMM_subsyst_T *obj;

  /* Start for MATLABSystem: '<S17>/Median Filter1' */
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->objisempty = true;
  obj = &localDW->obj;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  obj->pMID.isInitialized = 0;
}

/*
 * Output and update for atomic system:
 *    'synthesized block'
 *    'synthesized block'
 *    'synthesized block'
 *    'synthesized block'
 *    'synthesized block'
 */
void COMM_subsystem_in_MedianFilter1(real32_T rtu_0,
  B_MedianFilter1_COMM_subsyste_T *localB, DW_MedianFilter1_COMM_subsyst_T
  *localDW)
{
  dsp_MedianFilter_COMM_subsyst_T *obj;
  dsp_private_MedianFilterCG_CO_T *obj_0;
  real32_T vprev;
  real32_T p;
  boolean_T flag;
  real32_T temp;
  int32_T vprev_tmp;
  real32_T flag_tmp;
  real32_T tmp;
  boolean_T exitg1;

  /* Start for MATLABSystem: '<S17>/Median Filter1' */
  obj = &localDW->obj;
  obj_0 = &localDW->obj.pMID;
  if (obj->pMID.isInitialized != 1)
  {
    obj->pMID.isInitialized = 1;
    COMM_s_MedianFilterCG_resetImpl(&obj->pMID);
  }

  vprev_tmp = ((int32_T)obj->pMID.pIdx) - 1;
  vprev = obj->pMID.pBuf[vprev_tmp];
  vprev_tmp = ((int32_T)obj->pMID.pIdx) - 1;
  obj->pMID.pBuf[vprev_tmp] = rtu_0;
  vprev_tmp = ((int32_T)obj->pMID.pIdx) - 1;
  p = obj->pMID.pPos[vprev_tmp];
  obj->pMID.pIdx++;
  if (obj->pMID.pIdx == (obj->pMID.pWinLen + 1.0F))
  {
    obj->pMID.pIdx = 1.0F;
  }

  if (p > obj->pMID.pMidHeap)
  {
    if (vprev < rtu_0)
    {
      vprev = p - obj->pMID.pMidHeap;
      C_MedianFilterCG_trickleDownMin(&obj->pMID, vprev * 2.0F);
    }
    else
    {
      vprev = p - obj->pMID.pMidHeap;
      exitg1 = false;
      while ((!exitg1) && (vprev > 0.0F))
      {
        flag_tmp = vprev + obj_0->pMidHeap;
        p = (real32_T)floor((real_T)((real32_T)(vprev / 2.0F)));
        temp = p + obj_0->pMidHeap;
        flag = (obj_0->pBuf[((int32_T)obj_0->pHeap[((int32_T)flag_tmp) - 1]) - 1]
                < obj_0->pBuf[((int32_T)obj_0->pHeap[((int32_T)temp) - 1]) - 1]);
        if (!flag)
        {
          exitg1 = true;
        }
        else
        {
          tmp = vprev + obj_0->pMidHeap;
          flag_tmp = ((real32_T)floor((real_T)((real32_T)(vprev / 2.0F)))) +
            obj_0->pMidHeap;
          temp = obj_0->pHeap[((int32_T)tmp) - 1];
          obj_0->pHeap[((int32_T)tmp) - 1] = obj_0->pHeap[((int32_T)flag_tmp) -
            1];
          obj_0->pHeap[((int32_T)flag_tmp) - 1] = temp;
          obj_0->pPos[((int32_T)obj_0->pHeap[((int32_T)tmp) - 1]) - 1] = tmp;
          obj_0->pPos[((int32_T)obj_0->pHeap[((int32_T)flag_tmp) - 1]) - 1] =
            flag_tmp;
          vprev = p;
        }
      }

      if (vprev == 0.0F)
      {
        C_MedianFilterCG_trickleDownMax(&obj->pMID, -1.0F);
      }
    }
  }
  else if (p < obj->pMID.pMidHeap)
  {
    if (rtu_0 < vprev)
    {
      vprev = p - obj->pMID.pMidHeap;
      C_MedianFilterCG_trickleDownMax(&obj->pMID, vprev * 2.0F);
    }
    else
    {
      vprev = p - obj->pMID.pMidHeap;
      exitg1 = false;
      while ((!exitg1) && (vprev < 0.0F))
      {
        p = vprev / 2.0F;
        if (p < 0.0F)
        {
          p = (real32_T)ceil((real_T)p);
        }
        else
        {
          p = -0.0F;
        }

        flag_tmp = vprev + obj_0->pMidHeap;
        flag = (obj_0->pBuf[((int32_T)obj_0->pHeap[((int32_T)((real32_T)(p +
                    obj_0->pMidHeap))) - 1]) - 1] < obj_0->pBuf[((int32_T)
                 obj_0->pHeap[((int32_T)flag_tmp) - 1]) - 1]);
        if (!flag)
        {
          exitg1 = true;
        }
        else
        {
          p = vprev / 2.0F;
          if (p < 0.0F)
          {
            p = (real32_T)ceil((real_T)p);
          }
          else
          {
            p = -0.0F;
          }

          p += obj_0->pMidHeap;
          flag_tmp = vprev + obj_0->pMidHeap;
          vprev_tmp = ((int32_T)p) - 1;
          temp = obj_0->pHeap[vprev_tmp];
          obj_0->pHeap[vprev_tmp] = obj_0->pHeap[((int32_T)flag_tmp) - 1];
          obj_0->pHeap[((int32_T)flag_tmp) - 1] = temp;
          obj_0->pPos[((int32_T)obj_0->pHeap[((int32_T)p) - 1]) - 1] = p;
          obj_0->pPos[((int32_T)obj_0->pHeap[((int32_T)flag_tmp) - 1]) - 1] =
            flag_tmp;
          p = vprev / 2.0F;
          if (p < 0.0F)
          {
            vprev = (real32_T)ceil((real_T)p);
          }
          else
          {
            vprev = -0.0F;
          }
        }
      }

      if (vprev == 0.0F)
      {
        C_MedianFilterCG_trickleDownMin(&obj->pMID, 1.0F);
      }
    }
  }
  else
  {
    if (obj->pMID.pMaxHeapLength != 0.0F)
    {
      C_MedianFilterCG_trickleDownMax(&obj->pMID, -1.0F);
    }

    if (obj->pMID.pMinHeapLength > 0.0F)
    {
      C_MedianFilterCG_trickleDownMin(&obj->pMID, 1.0F);
    }
  }

  /* MATLABSystem: '<S17>/Median Filter1' */
  localB->MedianFilter1 = obj->pMID.pBuf[((int32_T)obj->pMID.pHeap[((int32_T)
    obj->pMID.pMidHeap) - 1]) - 1];
}

/* System initialize for atomic system: '<Root>/Receive' */
void COMM_subsystem_int_Receive_Init(void)
{
  /* SystemInitialize for IfAction SubSystem: '<S1>/iEV7S_New' */
  COMM_subsyst_MedianFilter1_Init(&COMM_subsystem_integrated_DW.MedianFilter1);

  /* End of SystemInitialize for SubSystem: '<S1>/iEV7S_New' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/iVISTA_New' */
  COMM_subsyst_MedianFilter1_Init
    (&COMM_subsystem_integrated_DW.MedianFilter1_pnae);

  /* End of SystemInitialize for SubSystem: '<S1>/iVISTA_New' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/ICPV New' */
  COMM_subsyst_MedianFilter1_Init
    (&COMM_subsystem_integrated_DW.MedianFilter1_pnaev);

  /* End of SystemInitialize for SubSystem: '<S1>/ICPV New' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/USdemo New' */
  COMM_subsyst_MedianFilter1_Init
    (&COMM_subsystem_integrated_DW.MedianFilter1_pnaevv);

  /* End of SystemInitialize for SubSystem: '<S1>/USdemo New' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/FAW New' */
  COMM_subsyst_MedianFilter1_Init
    (&COMM_subsystem_integrated_DW.MedianFilter1_pnaevvf);

  /* End of SystemInitialize for SubSystem: '<S1>/FAW New' */
}

/* Start for atomic system: '<Root>/Receive' */
void COMM_subsystem_in_Receive_Start(void)
{
  /* Start for IfAction SubSystem: '<S1>/iEV7S_New' */

  /* Start for S-Function (scanunpack): '<S17>/ABS_FrP01_RollingCounter' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S17>/ABS_FrP01_RollingCounter -----------------*/

  /* Start for S-Function (scanunpack): '<S17>/ESC_FrP01' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S17>/ESC_FrP01 -----------------*/

  /* Start for S-Function (scanunpack): '<S17>/Veh_MCCU_01' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S17>/Veh_MCCU_01 -----------------*/
  COMM_subsys_MedianFilter1_Start(&COMM_subsystem_integrated_DW.MedianFilter1);

  /* Start for S-Function (scanunpack): '<S17>/VCU_HSC_FrP07' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S17>/VCU_HSC_FrP07 -----------------*/

  /* Start for S-Function (scanunpack): '<S17>/EPS_02_SteeringTorque' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S17>/EPS_02_SteeringTorque -----------------*/

  /* Start for S-Function (scanunpack): '<S17>/ESC_FrP01_YawRate' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S17>/ESC_FrP01_YawRate -----------------*/

  /* End of Start for SubSystem: '<S1>/iEV7S_New' */

  /* Start for IfAction SubSystem: '<S1>/iVISTA_New' */

  /* Start for S-Function (scanunpack): '<S18>/ABS_FrP01_RollingCounter' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S18>/ABS_FrP01_RollingCounter -----------------*/

  /* Start for S-Function (scanunpack): '<S18>/ESC_FrP01_BrkPress_AccValue' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S18>/ESC_FrP01_BrkPress_AccValue -----------------*/

  /* Start for S-Function (scanunpack): '<S18>/Veh_MCCU_01' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S18>/Veh_MCCU_01 -----------------*/
  COMM_subsys_MedianFilter1_Start
    (&COMM_subsystem_integrated_DW.MedianFilter1_pnae);

  /* Start for S-Function (scanunpack): '<S18>/VCU_FrP07_AccPed' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S18>/VCU_FrP07_AccPed -----------------*/

  /* Start for S-Function (scanunpack): '<S18>/EPS_02_SteeringTorque' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S18>/EPS_02_SteeringTorque -----------------*/

  /* Start for S-Function (scanunpack): '<S18>/VCU_EVCAN_F08_DriveMode' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S18>/VCU_EVCAN_F08_DriveMode -----------------*/

  /* Start for S-Function (scanunpack): '<S18>/ESC_FrP01_YawRate' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S18>/ESC_FrP01_YawRate -----------------*/

  /* End of Start for SubSystem: '<S1>/iVISTA_New' */

  /* Start for IfAction SubSystem: '<S1>/ICPV New' */

  /* Start for S-Function (scanunpack): '<S5>/VCU_ICPV_CAN_00' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU_ICPV_CAN_00 -----------------*/

  /* Start for S-Function (scanunpack): '<S5>/VCU_ICPV_CAN_01' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU_ICPV_CAN_01 -----------------*/

  /* Start for S-Function (scanunpack): '<S5>/VCU_ICPV_CAN_03' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU_ICPV_CAN_03 -----------------*/

  /* Start for S-Function (scanunpack): '<S5>/VCU_ICPV_CAN' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU_ICPV_CAN -----------------*/

  /* Start for S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_00' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU1_ICPV_CAN_00 -----------------*/

  /* Start for S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_01' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU1_ICPV_CAN_01 -----------------*/

  /* Start for S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_02' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU1_ICPV_CAN_02 -----------------*/

  /* Start for S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_03' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU1_ICPV_CAN_03 -----------------*/

  /* Start for S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_04' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU1_ICPV_CAN_04 -----------------*/

  /* Start for S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_05' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU1_ICPV_CAN_05 -----------------*/

  /* Start for S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_06' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU1_ICPV_CAN_06 -----------------*/
  COMM_subsys_MedianFilter1_Start
    (&COMM_subsystem_integrated_DW.MedianFilter1_pnaev);

  /* Start for S-Function (scanunpack): '<S5>/VCU_ICPV_CAN_02' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU_ICPV_CAN_02 -----------------*/

  /* Start for S-Function (scanunpack): '<S5>/PCU_ICPV_CAN' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/PCU_ICPV_CAN -----------------*/

  /* Start for S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_1' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S5>/VCU1_ICPV_CAN_1 -----------------*/

  /* End of Start for SubSystem: '<S1>/ICPV New' */

  /* Start for IfAction SubSystem: '<S1>/HZBus_NewMatrix New' */

  /* Start for S-Function (scanunpack): '<S4>/Vehicle_Message_1' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S4>/Vehicle_Message_1 -----------------*/

  /* Start for S-Function (scanunpack): '<S4>/ESC_Message' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S4>/ESC_Message -----------------*/

  /* Start for S-Function (scanunpack): '<S4>/Vehicle_Message_2' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S4>/Vehicle_Message_2 -----------------*/

  /* Start for S-Function (scanunpack): '<S4>/EBS_WheelSpeed' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S4>/EBS_WheelSpeed -----------------*/

  /* End of Start for SubSystem: '<S1>/HZBus_NewMatrix New' */

  /* Start for IfAction SubSystem: '<S1>/USdemo New' */

  /* Start for S-Function (scanunpack): '<S15>/BUS_BCUState' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S15>/BUS_BCUState -----------------*/

  /* Start for S-Function (scanunpack): '<S15>/BUS_BCUState1' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S15>/BUS_BCUState1 -----------------*/

  /* Start for S-Function (scanunpack): '<S15>/BUS_BCUState2' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S15>/BUS_BCUState2 -----------------*/

  /* Start for S-Function (scanunpack): '<S15>/BUS_BCUState3' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S15>/BUS_BCUState3 -----------------*/

  /* Start for S-Function (scanunpack): '<S15>/BUS_BCUState4' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S15>/BUS_BCUState4 -----------------*/

  /* Start for S-Function (scanunpack): '<S15>/BUS_BCUState5' incorporates:
   *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
   */

  /*-----------S-Function Block: <S15>/BUS_BCUState5 -----------------*/
  COMM_subsys_MedianFilter1_Start
    (&COMM_subsystem_integrated_DW.MedianFilter1_pnaevv);

  /* End of Start for SubSystem: '<S1>/USdemo New' */

  /* Start for IfAction SubSystem: '<S1>/FAW New' */
  COMM_subsys_MedianFilter1_Start
    (&COMM_subsystem_integrated_DW.MedianFilter1_pnaevvf);

  /* End of Start for SubSystem: '<S1>/FAW New' */
}

/* Output and update for atomic system: '<Root>/Receive' */
void COMM_subsystem_integrat_Receive(void)
{
  /* local block i/o variables */
  real32_T rtb_Gain1_nyrf;
  real32_T rtb_DataTypeConversion;
  real32_T rtb_Product1;
  real32_T rtb_DataTypeConversion6;
  real32_T rtb_DataTypeConversion7;
  uint8_T rtb_Merge_jkuf;
  real_T rtb_Gain1;
  uint8_T rtb_middle_door_open;
  uint8_T rtb_Merge_eeee;
  COMM_Bus_VEH_Config rtb_Merge1;

  /* SwitchCase: '<S1>/Switch Case1' incorporates:
   *  Constant: '<S1>/Constant'
   */
  switch (KeCOMM_VehicleCANbusConfig)
  {
   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    COMM__SwitchCaseActionSubsystem(&rtb_Merge1);

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    COMM__SwitchCaseActionSubsystem(&rtb_Merge1);

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem1' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S10>/Action Port'
     */
    COMM__SwitchCaseActionSubsystem(&rtb_Merge1);

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem2' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem3' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* BusCreator: '<S11>/Bus Creator' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant1'
     *  Constant: '<S11>/Constant10'
     *  Constant: '<S11>/Constant11'
     *  Constant: '<S11>/Constant12'
     *  Constant: '<S11>/Constant13'
     *  Constant: '<S11>/Constant14'
     *  Constant: '<S11>/Constant15'
     *  Constant: '<S11>/Constant2'
     *  Constant: '<S11>/Constant3'
     *  Constant: '<S11>/Constant4'
     *  Constant: '<S11>/Constant5'
     *  Constant: '<S11>/Constant6'
     *  Constant: '<S11>/Constant7'
     *  Constant: '<S11>/Constant8'
     *  Constant: '<S11>/Constant9'
     */
    rtb_Merge1.VfCOMM_VEH_MinTurnRadius = 9.3F;
    rtb_Merge1.VfCOMM_VEH_AngOrigin2FrontWheel = 0.216420829F;
    rtb_Merge1.VfCOMM_VEH_YawInertia_Z = 34802.6F;
    rtb_Merge1.VfCOMM_VEH_DisOrigin2FrontWheel = 4650.0F;
    rtb_Merge1.VfCOMM_VEH_DisOrigin2End = 915.0F;
    rtb_Merge1.VfCOMM_VEH_DisOrigin2RearAxle = 0.0F;
    rtb_Merge1.VfCOMM_VEH_DisOrigin2Head = 6000.0F;
    rtb_Merge1.VfCOMM_VEH_Width = 2500.0F;
    rtb_Merge1.VfACCS_VEH_WheelDiameter = 1050.0F;
    rtb_Merge1.VfCOMM_VEH_Length = 6915.0F;
    rtb_Merge1.VfCOMM_VEH_StiffnessRear = 3733.1F;
    rtb_Merge1.VfCOMM_VEH_StiffnessFront = 3733.1F;
    rtb_Merge1.VfCOMM_VEH_DisLeft2Right = 2050.0F;
    rtb_Merge1.VfCOMM_VEH_DisCentorid2Front = 2000.0F;
    rtb_Merge1.VfCOMM_VEH_Mass = 25000.0F;
    rtb_Merge1.VfCOMM_VEH_DisFront2Rear = 4650.0F;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem3' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem4' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* BusCreator: '<S12>/Bus Creator' incorporates:
     *  Constant: '<S12>/Constant'
     *  Constant: '<S12>/Constant1'
     *  Constant: '<S12>/Constant10'
     *  Constant: '<S12>/Constant11'
     *  Constant: '<S12>/Constant12'
     *  Constant: '<S12>/Constant13'
     *  Constant: '<S12>/Constant14'
     *  Constant: '<S12>/Constant15'
     *  Constant: '<S12>/Constant2'
     *  Constant: '<S12>/Constant3'
     *  Constant: '<S12>/Constant4'
     *  Constant: '<S12>/Constant5'
     *  Constant: '<S12>/Constant6'
     *  Constant: '<S12>/Constant7'
     *  Constant: '<S12>/Constant8'
     *  Constant: '<S12>/Constant9'
     */
    rtb_Merge1.VfCOMM_VEH_MinTurnRadius = 9.0F;
    rtb_Merge1.VfCOMM_VEH_AngOrigin2FrontWheel = 0.0F;
    rtb_Merge1.VfCOMM_VEH_YawInertia_Z = 30782.4F;
    rtb_Merge1.VfCOMM_VEH_DisOrigin2FrontWheel = 0.0F;
    rtb_Merge1.VfCOMM_VEH_DisOrigin2End = 4500.0F;
    rtb_Merge1.VfCOMM_VEH_DisOrigin2RearAxle = 4500.0F;
    rtb_Merge1.VfCOMM_VEH_DisOrigin2Head = 2100.0F;
    rtb_Merge1.VfCOMM_VEH_Width = 2400.0F;
    rtb_Merge1.VfACCS_VEH_WheelDiameter = 838.3F;
    rtb_Merge1.VfCOMM_VEH_Length = 8540.0F;
    rtb_Merge1.VfCOMM_VEH_StiffnessRear = 3733.1F;
    rtb_Merge1.VfCOMM_VEH_StiffnessFront = 3733.1F;
    rtb_Merge1.VfCOMM_VEH_DisLeft2Right = 1950.0F;
    rtb_Merge1.VfCOMM_VEH_DisCentorid2Front = 3105.0F;
    rtb_Merge1.VfCOMM_VEH_Mass = 13500.0F;
    rtb_Merge1.VfCOMM_VEH_DisFront2Rear = 4500.0F;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem4' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem5' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    /* BusCreator: '<S13>/Bus Creator' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S13>/Constant1'
     *  Constant: '<S13>/Constant10'
     *  Constant: '<S13>/Constant11'
     *  Constant: '<S13>/Constant12'
     *  Constant: '<S13>/Constant13'
     *  Constant: '<S13>/Constant14'
     *  Constant: '<S13>/Constant15'
     *  Constant: '<S13>/Constant2'
     *  Constant: '<S13>/Constant3'
     *  Constant: '<S13>/Constant4'
     *  Constant: '<S13>/Constant5'
     *  Constant: '<S13>/Constant6'
     *  Constant: '<S13>/Constant7'
     *  Constant: '<S13>/Constant8'
     *  Constant: '<S13>/Constant9'
     */
    rtb_Merge1.VfCOMM_VEH_MinTurnRadius = 7.138F;
    rtb_Merge1.VfCOMM_VEH_AngOrigin2FrontWheel = 0.239110112F;
    rtb_Merge1.VfCOMM_VEH_YawInertia_Z = 10000.0F;
    rtb_Merge1.VfCOMM_VEH_DisOrigin2FrontWheel = 3569.0F;
    rtb_Merge1.VfCOMM_VEH_DisOrigin2End = 1.0F;
    rtb_Merge1.VfCOMM_VEH_DisOrigin2RearAxle = 0.0F;
    rtb_Merge1.VfCOMM_VEH_DisOrigin2Head = 1.0F;
    rtb_Merge1.VfCOMM_VEH_Width = 2017.0F;
    rtb_Merge1.VfACCS_VEH_WheelDiameter = 850.0F;
    rtb_Merge1.VfCOMM_VEH_Length = 5817.0F;
    rtb_Merge1.VfCOMM_VEH_StiffnessRear = 1.0F;
    rtb_Merge1.VfCOMM_VEH_StiffnessFront = 1.0F;
    rtb_Merge1.VfCOMM_VEH_DisLeft2Right = 1750.0F;
    rtb_Merge1.VfCOMM_VEH_DisCentorid2Front = 1.0F;
    rtb_Merge1.VfCOMM_VEH_Mass = 1.0F;
    rtb_Merge1.VfCOMM_VEH_DisFront2Rear = 3569.0F;

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem5' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Switch Case Action Subsystem6' incorporates:
     *  ActionPort: '<S14>/Action Port'
     */
    COMM__SwitchCaseActionSubsystem(&rtb_Merge1);

    /* End of Outputs for SubSystem: '<S1>/Switch Case Action Subsystem6' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case1' */

  /* Switch: '<S1>/Switch' incorporates:
   *  BusCreator: '<S7>/Bus Creator'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant1'
   *  Constant: '<S7>/Constant10'
   *  Constant: '<S7>/Constant11'
   *  Constant: '<S7>/Constant12'
   *  Constant: '<S7>/Constant13'
   *  Constant: '<S7>/Constant14'
   *  Constant: '<S7>/Constant15'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant3'
   *  Constant: '<S7>/Constant4'
   *  Constant: '<S7>/Constant5'
   *  Constant: '<S7>/Constant6'
   *  Constant: '<S7>/Constant7'
   *  Constant: '<S7>/Constant8'
   *  Constant: '<S7>/Constant9'
   */
  if (KbCOMM_VEH_UseNewConfig)
  {
    VsCOMM_VEH_Config.VfCOMM_VEH_MinTurnRadius = KfCOMM_d_VEH_MinTurnRadius;
    VsCOMM_VEH_Config.VfCOMM_VEH_AngOrigin2FrontWheel =
      KfCOMM_Ang_VEH_AngOrigin2FrontWheel;
    VsCOMM_VEH_Config.VfCOMM_VEH_YawInertia_Z = KfCOMM_VEH_YawInertia_Z;
    VsCOMM_VEH_Config.VfCOMM_VEH_DisOrigin2FrontWheel =
      KfCOMM_d_VEH_DisOrigin2FrontWheel;
    VsCOMM_VEH_Config.VfCOMM_VEH_DisOrigin2End = KfCOMM_d_VEH_DisOrigin2End;
    VsCOMM_VEH_Config.VfCOMM_VEH_DisOrigin2RearAxle =
      KfCOMM_d_VEH_DisOrigin2RearAxle;
    VsCOMM_VEH_Config.VfCOMM_VEH_DisOrigin2Head = KfCOMM_d_VEH_DisOrigin2Head;
    VsCOMM_VEH_Config.VfCOMM_VEH_Width = KfCOMM_d_VEH_Width;
    VsCOMM_VEH_Config.VfACCS_VEH_WheelDiameter = KfACCS_d_VEH_WheelDiameter;
    VsCOMM_VEH_Config.VfCOMM_VEH_Length = KfCOMM_d_VEH_Length;
    VsCOMM_VEH_Config.VfCOMM_VEH_StiffnessRear = KfCOMM_VEH_StiffnessRear;
    VsCOMM_VEH_Config.VfCOMM_VEH_StiffnessFront = KfCOMM_VEH_StiffnessFront;
    VsCOMM_VEH_Config.VfCOMM_VEH_DisLeft2Right = KfCOMM_d_VEH_DisLeft2Right;
    VsCOMM_VEH_Config.VfCOMM_VEH_DisCentorid2Front =
      KfCOMM_d_VEH_DisCentorid2Front;
    VsCOMM_VEH_Config.VfCOMM_VEH_Mass = KfCOMM_VEH_Mass;
    VsCOMM_VEH_Config.VfCOMM_VEH_DisFront2Rear = KfCOMM_d_VEH_DisFront2Rear;
  }
  else
  {
    VsCOMM_VEH_Config = rtb_Merge1;
  }

  /* End of Switch: '<S1>/Switch' */

  /* SwitchCase: '<S1>/Switch Case2' incorporates:
   *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_0'
   *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_1'
   *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_2'
   *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_3'
   *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_4'
   *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_5'
   *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_6'
   *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_7'
   *  Constant: '<S1>/CTRL_VehicleCANbusConfig1'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant10'
   *  Constant: '<S6>/Constant100'
   *  Constant: '<S6>/Constant101'
   *  Constant: '<S6>/Constant102'
   *  Constant: '<S6>/Constant103'
   *  Constant: '<S6>/Constant104'
   *  Constant: '<S6>/Constant105'
   *  Constant: '<S6>/Constant106'
   *  Constant: '<S6>/Constant108'
   *  Constant: '<S6>/Constant109'
   *  Constant: '<S6>/Constant11'
   *  Constant: '<S6>/Constant110'
   *  Constant: '<S6>/Constant112'
   *  Constant: '<S6>/Constant113'
   *  Constant: '<S6>/Constant114'
   *  Constant: '<S6>/Constant115'
   *  Constant: '<S6>/Constant116'
   *  Constant: '<S6>/Constant117'
   *  Constant: '<S6>/Constant118'
   *  Constant: '<S6>/Constant119'
   *  Constant: '<S6>/Constant12'
   *  Constant: '<S6>/Constant120'
   *  Constant: '<S6>/Constant121'
   *  Constant: '<S6>/Constant122'
   *  Constant: '<S6>/Constant123'
   *  Constant: '<S6>/Constant124'
   *  Constant: '<S6>/Constant127'
   *  Constant: '<S6>/Constant129'
   *  Constant: '<S6>/Constant13'
   *  Constant: '<S6>/Constant138'
   *  Constant: '<S6>/Constant139'
   *  Constant: '<S6>/Constant14'
   *  Constant: '<S6>/Constant140'
   *  Constant: '<S6>/Constant141'
   *  Constant: '<S6>/Constant142'
   *  Constant: '<S6>/Constant143'
   *  Constant: '<S6>/Constant144'
   *  Constant: '<S6>/Constant145'
   *  Constant: '<S6>/Constant146'
   *  Constant: '<S6>/Constant147'
   *  Constant: '<S6>/Constant148'
   *  Constant: '<S6>/Constant149'
   *  Constant: '<S6>/Constant15'
   *  Constant: '<S6>/Constant150'
   *  Constant: '<S6>/Constant151'
   *  Constant: '<S6>/Constant152'
   *  Constant: '<S6>/Constant153'
   *  Constant: '<S6>/Constant154'
   *  Constant: '<S6>/Constant155'
   *  Constant: '<S6>/Constant156'
   *  Constant: '<S6>/Constant157'
   *  Constant: '<S6>/Constant158'
   *  Constant: '<S6>/Constant159'
   *  Constant: '<S6>/Constant160'
   *  Constant: '<S6>/Constant162'
   *  Constant: '<S6>/Constant164'
   *  Constant: '<S6>/Constant165'
   *  Constant: '<S6>/Constant166'
   *  Constant: '<S6>/Constant167'
   *  Constant: '<S6>/Constant168'
   *  Constant: '<S6>/Constant169'
   *  Constant: '<S6>/Constant170'
   *  Constant: '<S6>/Constant171'
   *  Constant: '<S6>/Constant172'
   *  Constant: '<S6>/Constant173'
   *  Constant: '<S6>/Constant174'
   *  Constant: '<S6>/Constant175'
   *  Constant: '<S6>/Constant176'
   *  Constant: '<S6>/Constant177'
   *  Constant: '<S6>/Constant178'
   *  Constant: '<S6>/Constant179'
   *  Constant: '<S6>/Constant180'
   *  Constant: '<S6>/Constant181'
   *  Constant: '<S6>/Constant182'
   *  Constant: '<S6>/Constant183'
   *  Constant: '<S6>/Constant184'
   *  Constant: '<S6>/Constant185'
   *  Constant: '<S6>/Constant186'
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant204'
   *  Constant: '<S6>/Constant3'
   *  Constant: '<S6>/Constant4'
   *  Constant: '<S6>/Constant5'
   *  Constant: '<S6>/Constant6'
   *  Constant: '<S6>/Constant7'
   *  Constant: '<S6>/Constant8'
   *  Constant: '<S6>/Constant83'
   *  Constant: '<S6>/Constant84'
   *  Constant: '<S6>/Constant85'
   *  Constant: '<S6>/Constant86'
   *  Constant: '<S6>/Constant87'
   *  Constant: '<S6>/Constant88'
   *  Constant: '<S6>/Constant89'
   *  Constant: '<S6>/Constant9'
   *  Constant: '<S6>/Constant90'
   *  Constant: '<S6>/Constant91'
   *  Constant: '<S6>/Constant92'
   *  Constant: '<S6>/Constant93'
   *  Constant: '<S6>/Constant94'
   *  Constant: '<S6>/Constant95'
   *  Constant: '<S6>/Constant96'
   *  Constant: '<S6>/Constant97'
   *  Constant: '<S6>/Constant98'
   *  Constant: '<S6>/Constant99'
   *  Inport: '<S16>/FedBck_in_Inport_1'
   */
  switch (KeCOMM_VehicleCANbusConfig)
  {
   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/iEV7S_New' incorporates:
     *  ActionPort: '<S17>/Action Port'
     */
    /* S-Function (scanunpack): '<S17>/ABS_FrP01_RollingCounter' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S17>/ABS_FrP01_RollingCounter' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.ID !=
           INVALID_CAN_ID) )
      {
        if ((810U == VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 56
             *  length                  = 16
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                uint32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (uint32_T) (unpackedValue);
                  }
                }

                {
                  uint32_T result = (uint32_T) outValue;
                  COMM_subsystem_integrated_B.ABS_FrP01_RollingCounter_o_nlod =
                    result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 40
             *  length                  = 16
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                uint32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (uint32_T) (unpackedValue);
                  }
                }

                {
                  uint32_T result = (uint32_T) outValue;
                  COMM_subsystem_integrated_B.ABS_FrP01_RollingCounter_o_hv3k =
                    result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 25
             *  length                  = 15
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.05625
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S17>/ESC_FrP01' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S17>/ESC_FrP01' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.ID !=
           INVALID_CAN_ID) )
      {
        if ((603U == VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 8
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.209
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = result * 0.209F;
                  COMM_subsystem_integrated_B.ESC_FrP01_o1 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 0
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = SIGNED
             *  factor                  = 0.209
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    int8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = (int8_T) tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.209;
                  COMM_subsystem_integrated_B.ESC_FrP01_o2 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 32
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  COMM_subsystem_integrated_B.ESC_FrP01_o3 = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S17>/Veh_MCCU_01' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S17>/Veh_MCCU_01' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.ID !=
           INVALID_CAN_ID) )
      {
        if ((195U == VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 12
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 2.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 2.0;
                  COMM_subsystem_integrated_B.Decs_FedBck_BrkPedSts_nttx =
                    result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 47
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Decs_FedBck_Drivemod_mpet = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 24
             *  length                  = 3
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                uint8_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (uint8_T) (unpackedValue);
                  }
                }

                {
                  uint8_T result = (uint8_T) outValue;
                  COMM_subsystem_integrated_B.Decs_FedBck_EPBstate_hzkd = result;
                }
              }
            }

            /* --------------- START Unpacking signal 3 ------------------
             *  startBit                = 33
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */

            /* --------------- START Unpacking signal 4 ------------------
             *  startBit                = 45
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Decs_FedBck_ESCmod_gpcj = result;
                }
              }
            }

            /* --------------- START Unpacking signal 5 ------------------
             *  startBit                = 35
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Decs_FedBck_GearValue_du1v =
                    result;
                }
              }
            }

            /* --------------- START Unpacking signal 6 ------------------
             *  startBit                = 37
             *  length                  = 3
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<2);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Decs_FedBck_Keystate_cil1 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 7 ------------------
             *  startBit                = 28
             *  length                  = 14
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.1
             *  offset                  = -550.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<13);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.1) + -550.0;
                  COMM_subsystem_integrated_B.Decs_FedBck_StrAngle_jsjb = result;
                }
              }
            }

            /* --------------- START Unpacking signal 8 ------------------
             *  startBit                = 62
             *  length                  = 15
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.05625
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_2_ID__195.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<14);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.05625;
                  COMM_subsystem_integrated_B.Decs_FedBck_VehSpd_nhc2 = result;
                }
              }
            }
          }
        }
      }
    }

    /* DataTypeConversion: '<S17>/Data Type Conversion7' */
    rtb_DataTypeConversion7 = (real32_T)
      COMM_subsystem_integrated_B.Decs_FedBck_StrAngle_jsjb;
    COMM_subsystem_in_MedianFilter1(rtb_DataTypeConversion7,
      &COMM_subsystem_integrated_B.MedianFilter1,
      &COMM_subsystem_integrated_DW.MedianFilter1);

    /* S-Function (scanunpack): '<S17>/VCU_HSC_FrP07' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S17>/VCU_HSC_FrP07' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID_1640.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID_1640.ID !=
           INVALID_CAN_ID) )
      {
        if ((1640U == VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID_1640.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID_1640.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 16
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.5
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = result * 0.5F;
                  COMM_subsystem_integrated_B.AccPed_dvek = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S17>/EPS_02_SteeringTorque' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S17>/EPS_02_SteeringTorque' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__421.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__421.ID !=
           INVALID_CAN_ID) )
      {
        if ((421U == VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__421.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__421.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 0
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.1
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = result * 0.1F;
                  COMM_subsystem_integrated_B.EPS_SteeringTorqueAct_bnll =
                    result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S17>/ESC_FrP01_YawRate' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S17>/ESC_FrP01_YawRate' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.ID !=
           INVALID_CAN_ID) )
      {
        if ((304U == VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 20
             *  length                  = 12
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.07975
             *  offset                  = -163.328
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_1_Receive__CAN_0_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<11);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.07975) + -163.328;
                  COMM_subsystem_integrated_B.ESC_FrP01_YawRate_jnwb = result;
                }
              }
            }
          }
        }
      }
    }

    /* BusAssignment: '<S17>/Bus Assignment1' incorporates:
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_0'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_1'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_2'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_3'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_4'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_5'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_6'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_7'
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/Constant10'
     *  Constant: '<S6>/Constant100'
     *  Constant: '<S6>/Constant101'
     *  Constant: '<S6>/Constant102'
     *  Constant: '<S6>/Constant103'
     *  Constant: '<S6>/Constant104'
     *  Constant: '<S6>/Constant105'
     *  Constant: '<S6>/Constant106'
     *  Constant: '<S6>/Constant108'
     *  Constant: '<S6>/Constant109'
     *  Constant: '<S6>/Constant11'
     *  Constant: '<S6>/Constant110'
     *  Constant: '<S6>/Constant112'
     *  Constant: '<S6>/Constant113'
     *  Constant: '<S6>/Constant114'
     *  Constant: '<S6>/Constant115'
     *  Constant: '<S6>/Constant116'
     *  Constant: '<S6>/Constant117'
     *  Constant: '<S6>/Constant118'
     *  Constant: '<S6>/Constant119'
     *  Constant: '<S6>/Constant12'
     *  Constant: '<S6>/Constant120'
     *  Constant: '<S6>/Constant121'
     *  Constant: '<S6>/Constant122'
     *  Constant: '<S6>/Constant123'
     *  Constant: '<S6>/Constant124'
     *  Constant: '<S6>/Constant127'
     *  Constant: '<S6>/Constant129'
     *  Constant: '<S6>/Constant13'
     *  Constant: '<S6>/Constant138'
     *  Constant: '<S6>/Constant139'
     *  Constant: '<S6>/Constant14'
     *  Constant: '<S6>/Constant140'
     *  Constant: '<S6>/Constant141'
     *  Constant: '<S6>/Constant142'
     *  Constant: '<S6>/Constant143'
     *  Constant: '<S6>/Constant144'
     *  Constant: '<S6>/Constant145'
     *  Constant: '<S6>/Constant146'
     *  Constant: '<S6>/Constant147'
     *  Constant: '<S6>/Constant148'
     *  Constant: '<S6>/Constant149'
     *  Constant: '<S6>/Constant15'
     *  Constant: '<S6>/Constant150'
     *  Constant: '<S6>/Constant151'
     *  Constant: '<S6>/Constant152'
     *  Constant: '<S6>/Constant153'
     *  Constant: '<S6>/Constant154'
     *  Constant: '<S6>/Constant155'
     *  Constant: '<S6>/Constant156'
     *  Constant: '<S6>/Constant157'
     *  Constant: '<S6>/Constant158'
     *  Constant: '<S6>/Constant159'
     *  Constant: '<S6>/Constant160'
     *  Constant: '<S6>/Constant162'
     *  Constant: '<S6>/Constant164'
     *  Constant: '<S6>/Constant165'
     *  Constant: '<S6>/Constant166'
     *  Constant: '<S6>/Constant167'
     *  Constant: '<S6>/Constant168'
     *  Constant: '<S6>/Constant169'
     *  Constant: '<S6>/Constant170'
     *  Constant: '<S6>/Constant171'
     *  Constant: '<S6>/Constant172'
     *  Constant: '<S6>/Constant173'
     *  Constant: '<S6>/Constant174'
     *  Constant: '<S6>/Constant175'
     *  Constant: '<S6>/Constant176'
     *  Constant: '<S6>/Constant177'
     *  Constant: '<S6>/Constant178'
     *  Constant: '<S6>/Constant179'
     *  Constant: '<S6>/Constant180'
     *  Constant: '<S6>/Constant181'
     *  Constant: '<S6>/Constant182'
     *  Constant: '<S6>/Constant183'
     *  Constant: '<S6>/Constant184'
     *  Constant: '<S6>/Constant185'
     *  Constant: '<S6>/Constant186'
     *  Constant: '<S6>/Constant2'
     *  Constant: '<S6>/Constant204'
     *  Constant: '<S6>/Constant3'
     *  Constant: '<S6>/Constant4'
     *  Constant: '<S6>/Constant5'
     *  Constant: '<S6>/Constant6'
     *  Constant: '<S6>/Constant7'
     *  Constant: '<S6>/Constant8'
     *  Constant: '<S6>/Constant83'
     *  Constant: '<S6>/Constant84'
     *  Constant: '<S6>/Constant85'
     *  Constant: '<S6>/Constant86'
     *  Constant: '<S6>/Constant87'
     *  Constant: '<S6>/Constant88'
     *  Constant: '<S6>/Constant89'
     *  Constant: '<S6>/Constant9'
     *  Constant: '<S6>/Constant90'
     *  Constant: '<S6>/Constant91'
     *  Constant: '<S6>/Constant92'
     *  Constant: '<S6>/Constant93'
     *  Constant: '<S6>/Constant94'
     *  Constant: '<S6>/Constant95'
     *  Constant: '<S6>/Constant96'
     *  Constant: '<S6>/Constant97'
     *  Constant: '<S6>/Constant98'
     *  Constant: '<S6>/Constant99'
     *  DataTypeConversion: '<S17>/Data Type Conversion1'
     */
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch = true;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips = ((uint16_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwCancel = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwResume = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwSet = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapPlus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapMinus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwLimitMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriveMode = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBelt = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBeltValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_TurningLightEcho = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LowBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_HighBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_PassengerDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearRightDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearLeftDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_FrontHoodStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BackTrunkStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_WiperSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_ControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_TCSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_ABSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeAirTankPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_BrakePedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_TargetBrakePedalEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPress = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPressValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_AutoholdStatus = true;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ParkingControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SwitchStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_StartStopStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeedValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalOverride = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineState = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CoolantLevelLow = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowerControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_DriverDemandTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_ActualEngineTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineOilPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineCoolantTemperature = 0;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CatalystTankLevel = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_TargetAccelPedalPostionEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowertrainFaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_BatterySOC = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorActualTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_EngineTorqueLoss = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorqueValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LDW = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringModeEcho = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_TargetSteeringAngleEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringAngleRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_FaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOffWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOnWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_TargetGearPositionEcho =
      ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ShiftLevelPosition = ((uint8_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition = ((uint8_T)
      20U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearRatio = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRateValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FR = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FL = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FRValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FLValid = true;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RL = 1U;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RR = 1U;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState =
      (COMM_subsystem_integrated_B.Decs_FedBck_Keystate_cil1 != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus =
      COMM_subsystem_integrated_B.Decs_FedBck_EPBstate_hzkd;

    /* Switch: '<S17>/Switch1' */
    if (COMM_subsystem_integrated_B.Decs_FedBck_BrkPedSts_nttx > 0.0)
    {
      /* BusAssignment: '<S17>/Bus Assignment1' incorporates:
       *  Constant: '<S17>/Constant3'
       */
      VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = false;
    }
    else
    {
      /* BusAssignment: '<S17>/Bus Assignment1' incorporates:
       *  Constant: '<S17>/Constant4'
       */
      VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = true;
    }

    /* End of Switch: '<S17>/Switch1' */

    /* BusAssignment: '<S17>/Bus Assignment1' incorporates:
     *  DataTypeConversion: '<S17>/Data Type Conversion10'
     *  DataTypeConversion: '<S17>/Data Type Conversion6'
     *  Gain: '<S17>/Gain'
     *  Gain: '<S17>/Gain3'
     *  Inport: '<Root>/VsDCSN_DataBus'
     */
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle = (-1.0F) *
      COMM_subsystem_integrated_B.MedianFilter1.MedianFilter1;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = (real32_T)
      ((real_T)(0.27777777777777779 *
                COMM_subsystem_integrated_B.Decs_FedBck_VehSpd_nhc2));
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC =
      VsDCSN_DataBus.EnablingFlags_Group.steer_ctrl_enable;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeControlResponse =
      (COMM_subsystem_integrated_B.Decs_FedBck_ESCmod_gpcj != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus =
      (COMM_subsystem_integrated_B.Decs_FedBck_Drivemod_mpet != 0.0);

    /* SwitchCase: '<S17>/Switch Case' */
    if (((int32_T)COMM_subsystem_integrated_B.Decs_FedBck_GearValue_du1v) == 2)
    {
      /* Outputs for IfAction SubSystem: '<S17>/GearR' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      /* BusAssignment: '<S17>/Bus Assignment1' incorporates:
       *  Constant: '<S34>/Constant'
       *  SignalConversion: '<S34>/OutportBufferForOut1'
       */
      VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition =
        ((uint8_T)13U);

      /* End of Outputs for SubSystem: '<S17>/GearR' */
    }
    else
    {
      /* Outputs for IfAction SubSystem: '<S17>/GearNorD' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      /* BusAssignment: '<S17>/Bus Assignment1' incorporates:
       *  DataTypeConversion: '<S33>/Data Type Conversion3'
       */
      VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition = (uint8_T)
        COMM_subsystem_integrated_B.Decs_FedBck_GearValue_du1v;

      /* End of Outputs for SubSystem: '<S17>/GearNorD' */
    }

    /* End of SwitchCase: '<S17>/Switch Case' */

    /* BusAssignment: '<S17>/Bus Assignment1' incorporates:
     *  Constant: '<S17>/CTRL_VehicleCANbusConfig2'
     *  Constant: '<S17>/CTRL_VehicleCANbusConfig3'
     *  DataTypeConversion: '<S17>/Data Type Conversion3'
     *  Gain: '<S17>/Gain4'
     *  Inport: '<Root>/VbHWIO_ACC_CancelSwitch'
     *  Inport: '<Root>/VbHWIO_ACC_MainSwitch'
     *  Inport: '<Root>/VbHWIO_ACC_ResumeSwitch'
     *  Inport: '<Root>/VbHWIO_ACC_SetSwitch'
     *  Inport: '<Root>/VbHWIO_ACC_TimeGapMinus'
     *  Inport: '<Root>/VbHWIO_ACC_TimeGapPlus'
     *  Inport: '<Root>/VbHWIO_DriverModeComd'
     *  Inport: '<Root>/VbHWIO_LeftTurningLightState'
     *  Inport: '<Root>/VbHWIO_RightTurningLightState'
     *  Product: '<S17>/Product1'
     *  Sum: '<S17>/Add1'
     */
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition =
      COMM_subsystem_integrated_B.AccPed_dvek;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque =
      COMM_subsystem_integrated_B.EPS_SteeringTorqueAct_bnll;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch =
      VbHWIO_DriverModeComd;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration =
      KfCOMM_a_VCULongAccOffset + (((real32_T)
      COMM_subsystem_integrated_B.ESC_FrP01_o2) * KfCOMM_r_VCULongAccSlope);
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration =
      COMM_subsystem_integrated_B.ESC_FrP01_o1;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPress =
      COMM_subsystem_integrated_B.ESC_FrP01_o3;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate = (real32_T)((real_T)
      (0.017453292519943295 * COMM_subsystem_integrated_B.ESC_FrP01_YawRate_jnwb));
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RL =
      COMM_subsystem_integrated_B.ABS_FrP01_RollingCounter_o_nlod;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RR =
      COMM_subsystem_integrated_B.ABS_FrP01_RollingCounter_o_hv3k;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState =
      VbHWIO_LeftTurningLightState;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState =
      VbHWIO_RightTurningLightState;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwCancel = VbHWIO_ACC_CancelSwitch;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwResume = VbHWIO_ACC_ResumeSwitch;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwSet = VbHWIO_ACC_SetSwitch;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapPlus =
      VbHWIO_ACC_TimeGapPlus;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapMinus =
      VbHWIO_ACC_TimeGapMinus;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain = VbHWIO_ACC_MainSwitch;

    /* End of Outputs for SubSystem: '<S1>/iEV7S_New' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/iVISTA_New' incorporates:
     *  ActionPort: '<S18>/Action Port'
     */
    /* S-Function (scanunpack): '<S18>/ABS_FrP01_RollingCounter' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S18>/ABS_FrP01_RollingCounter' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.ID !=
           INVALID_CAN_ID) )
      {
        if ((810U == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 56
             *  length                  = 16
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                uint32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (uint32_T) (unpackedValue);
                  }
                }

                {
                  uint32_T result = (uint32_T) outValue;
                  COMM_subsystem_integrated_B.ABS_FrP01_RollingCounter_o1 =
                    result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 40
             *  length                  = 16
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                uint32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__810.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (uint32_T) (unpackedValue);
                  }
                }

                {
                  uint32_T result = (uint32_T) outValue;
                  COMM_subsystem_integrated_B.ABS_FrP01_RollingCounter_o2 =
                    result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 25
             *  length                  = 15
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.05625
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S18>/ESC_FrP01_BrkPress_AccValue' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S18>/ESC_FrP01_BrkPress_AccValue' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.ID !=
           INVALID_CAN_ID) )
      {
        if ((603U == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 8
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.209
             *  offset                  = -26.75
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = (result * 0.209F) + -26.75F;
                  COMM_subsystem_integrated_B.ESC_FrP01_BrkPress_AccValue_o1 =
                    result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 0
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.209
             *  offset                  = -22.363
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.209) + -22.363;
                  COMM_subsystem_integrated_B.ESC_FrP01_BrkPress_AccValue_o2 =
                    result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 32
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__603.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  COMM_subsystem_integrated_B.ESC_FrP01_BrkPress_AccValue_o3 =
                    result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S18>/Veh_MCCU_01' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S18>/Veh_MCCU_01' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.ID !=
           INVALID_CAN_ID) )
      {
        if ((195U == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 12
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 2.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 2.0;
                  COMM_subsystem_integrated_B.Decs_FedBck_BrkPedSts = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 47
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Decs_FedBck_Drivemod = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 24
             *  length                  = 3
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                uint8_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (uint8_T) (unpackedValue);
                  }
                }

                {
                  uint8_T result = (uint8_T) outValue;
                  COMM_subsystem_integrated_B.Decs_FedBck_EPBstate = result;
                }
              }
            }

            /* --------------- START Unpacking signal 3 ------------------
             *  startBit                = 33
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Decs_FedBck_EPSmod = result;
                }
              }
            }

            /* --------------- START Unpacking signal 4 ------------------
             *  startBit                = 45
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Decs_FedBck_ESCmod = result;
                }
              }
            }

            /* --------------- START Unpacking signal 5 ------------------
             *  startBit                = 35
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Decs_FedBck_GearValue = result;
                }
              }
            }

            /* --------------- START Unpacking signal 6 ------------------
             *  startBit                = 37
             *  length                  = 3
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<2);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Decs_FedBck_Keystate = result;
                }
              }
            }

            /* --------------- START Unpacking signal 7 ------------------
             *  startBit                = 28
             *  length                  = 14
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.1
             *  offset                  = -550.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<13);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.1) + -550.0;
                  COMM_subsystem_integrated_B.Decs_FedBck_StrAngle = result;
                }
              }
            }

            /* --------------- START Unpacking signal 8 ------------------
             *  startBit                = 62
             *  length                  = 15
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.05625
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__195.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<14);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.05625;
                  COMM_subsystem_integrated_B.Decs_FedBck_VehSpd = result;
                }
              }
            }
          }
        }
      }
    }

    /* DataTypeConversion: '<S18>/Data Type Conversion6' */
    rtb_DataTypeConversion6 = (real32_T)
      COMM_subsystem_integrated_B.Decs_FedBck_StrAngle;
    COMM_subsystem_in_MedianFilter1(rtb_DataTypeConversion6,
      &COMM_subsystem_integrated_B.MedianFilter1_pnae,
      &COMM_subsystem_integrated_DW.MedianFilter1_pnae);

    /* S-Function (scanunpack): '<S18>/VCU_FrP07_AccPed' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S18>/VCU_FrP07_AccPed' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1640.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1640.ID !=
           INVALID_CAN_ID) )
      {
        if ((1640U == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1640.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1640.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 16
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.5
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = result * 0.5F;
                  COMM_subsystem_integrated_B.AccPed = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S18>/EPS_02_SteeringTorque' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S18>/EPS_02_SteeringTorque' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__421.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__421.ID !=
           INVALID_CAN_ID) )
      {
        if ((421U == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__421.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__421.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 0
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.1
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__421.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = result * 0.1F;
                  COMM_subsystem_integrated_B.EPS_SteeringTorqueAct = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S18>/VCU_EVCAN_F08_DriveMode' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S18>/VCU_EVCAN_F08_DriveMode' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1659.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1659.ID !=
           INVALID_CAN_ID) )
      {
        if ((1659U == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1659.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1659.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 54
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1659.Data
                            [6]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID_1659.Data
                            [6]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.DriverModeComd = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S18>/ESC_FrP01_YawRate' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S18>/ESC_FrP01_YawRate' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.ID !=
           INVALID_CAN_ID) )
      {
        if ((304U == VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 20
             *  length                  = 12
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.07975
             *  offset                  = -163.328
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_2_Receive__CAN_2_ID__304.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<11);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.07975) + -163.328;
                  COMM_subsystem_integrated_B.ESC_FrP01_YawRate = result;
                }
              }
            }
          }
        }
      }
    }

    /* BusAssignment: '<S18>/Bus Assignment1' incorporates:
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_0'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_1'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_2'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_3'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_4'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_5'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_6'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_7'
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/Constant10'
     *  Constant: '<S6>/Constant100'
     *  Constant: '<S6>/Constant101'
     *  Constant: '<S6>/Constant102'
     *  Constant: '<S6>/Constant103'
     *  Constant: '<S6>/Constant104'
     *  Constant: '<S6>/Constant105'
     *  Constant: '<S6>/Constant106'
     *  Constant: '<S6>/Constant108'
     *  Constant: '<S6>/Constant109'
     *  Constant: '<S6>/Constant11'
     *  Constant: '<S6>/Constant110'
     *  Constant: '<S6>/Constant112'
     *  Constant: '<S6>/Constant113'
     *  Constant: '<S6>/Constant114'
     *  Constant: '<S6>/Constant115'
     *  Constant: '<S6>/Constant116'
     *  Constant: '<S6>/Constant117'
     *  Constant: '<S6>/Constant118'
     *  Constant: '<S6>/Constant119'
     *  Constant: '<S6>/Constant12'
     *  Constant: '<S6>/Constant120'
     *  Constant: '<S6>/Constant121'
     *  Constant: '<S6>/Constant122'
     *  Constant: '<S6>/Constant123'
     *  Constant: '<S6>/Constant124'
     *  Constant: '<S6>/Constant127'
     *  Constant: '<S6>/Constant129'
     *  Constant: '<S6>/Constant13'
     *  Constant: '<S6>/Constant138'
     *  Constant: '<S6>/Constant139'
     *  Constant: '<S6>/Constant14'
     *  Constant: '<S6>/Constant140'
     *  Constant: '<S6>/Constant141'
     *  Constant: '<S6>/Constant142'
     *  Constant: '<S6>/Constant143'
     *  Constant: '<S6>/Constant144'
     *  Constant: '<S6>/Constant145'
     *  Constant: '<S6>/Constant146'
     *  Constant: '<S6>/Constant147'
     *  Constant: '<S6>/Constant148'
     *  Constant: '<S6>/Constant149'
     *  Constant: '<S6>/Constant15'
     *  Constant: '<S6>/Constant150'
     *  Constant: '<S6>/Constant151'
     *  Constant: '<S6>/Constant152'
     *  Constant: '<S6>/Constant153'
     *  Constant: '<S6>/Constant154'
     *  Constant: '<S6>/Constant155'
     *  Constant: '<S6>/Constant156'
     *  Constant: '<S6>/Constant157'
     *  Constant: '<S6>/Constant158'
     *  Constant: '<S6>/Constant159'
     *  Constant: '<S6>/Constant160'
     *  Constant: '<S6>/Constant162'
     *  Constant: '<S6>/Constant164'
     *  Constant: '<S6>/Constant165'
     *  Constant: '<S6>/Constant166'
     *  Constant: '<S6>/Constant167'
     *  Constant: '<S6>/Constant168'
     *  Constant: '<S6>/Constant169'
     *  Constant: '<S6>/Constant170'
     *  Constant: '<S6>/Constant171'
     *  Constant: '<S6>/Constant172'
     *  Constant: '<S6>/Constant173'
     *  Constant: '<S6>/Constant174'
     *  Constant: '<S6>/Constant175'
     *  Constant: '<S6>/Constant176'
     *  Constant: '<S6>/Constant177'
     *  Constant: '<S6>/Constant178'
     *  Constant: '<S6>/Constant179'
     *  Constant: '<S6>/Constant180'
     *  Constant: '<S6>/Constant181'
     *  Constant: '<S6>/Constant182'
     *  Constant: '<S6>/Constant183'
     *  Constant: '<S6>/Constant184'
     *  Constant: '<S6>/Constant185'
     *  Constant: '<S6>/Constant186'
     *  Constant: '<S6>/Constant2'
     *  Constant: '<S6>/Constant204'
     *  Constant: '<S6>/Constant3'
     *  Constant: '<S6>/Constant4'
     *  Constant: '<S6>/Constant5'
     *  Constant: '<S6>/Constant6'
     *  Constant: '<S6>/Constant7'
     *  Constant: '<S6>/Constant8'
     *  Constant: '<S6>/Constant83'
     *  Constant: '<S6>/Constant84'
     *  Constant: '<S6>/Constant85'
     *  Constant: '<S6>/Constant86'
     *  Constant: '<S6>/Constant87'
     *  Constant: '<S6>/Constant88'
     *  Constant: '<S6>/Constant89'
     *  Constant: '<S6>/Constant9'
     *  Constant: '<S6>/Constant90'
     *  Constant: '<S6>/Constant91'
     *  Constant: '<S6>/Constant92'
     *  Constant: '<S6>/Constant93'
     *  Constant: '<S6>/Constant94'
     *  Constant: '<S6>/Constant95'
     *  Constant: '<S6>/Constant96'
     *  Constant: '<S6>/Constant97'
     *  Constant: '<S6>/Constant98'
     *  Constant: '<S6>/Constant99'
     *  DataTypeConversion: '<S18>/Data Type Conversion1'
     */
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch = true;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips = ((uint16_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwCancel = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwResume = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwSet = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapPlus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapMinus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwLimitMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriveMode = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBelt = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBeltValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_TurningLightEcho = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LowBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_HighBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_PassengerDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearRightDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearLeftDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_FrontHoodStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BackTrunkStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_WiperSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_ControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_TCSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_ABSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeAirTankPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_BrakePedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_TargetBrakePedalEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPress = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPressValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_AutoholdStatus = true;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ParkingControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SwitchStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_StartStopStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeedValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalOverride = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineState = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CoolantLevelLow = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowerControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_DriverDemandTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_ActualEngineTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineOilPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineCoolantTemperature = 0;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CatalystTankLevel = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_TargetAccelPedalPostionEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowertrainFaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_BatterySOC = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorActualTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_EngineTorqueLoss = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorqueValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LDW = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringModeEcho = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_TargetSteeringAngleEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringAngleRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_FaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOffWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOnWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_TargetGearPositionEcho =
      ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ShiftLevelPosition = ((uint8_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition = ((uint8_T)
      20U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearRatio = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRateValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FR = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FL = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FRValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FLValid = true;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RL = 1U;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RR = 1U;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState =
      (COMM_subsystem_integrated_B.Decs_FedBck_Keystate != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus =
      COMM_subsystem_integrated_B.Decs_FedBck_EPBstate;

    /* Switch: '<S18>/Switch1' */
    if (COMM_subsystem_integrated_B.Decs_FedBck_BrkPedSts > 0.0)
    {
      /* BusAssignment: '<S18>/Bus Assignment1' incorporates:
       *  Constant: '<S18>/Constant2'
       */
      VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = false;
    }
    else
    {
      /* BusAssignment: '<S18>/Bus Assignment1' incorporates:
       *  Constant: '<S18>/Constant3'
       */
      VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = true;
    }

    /* End of Switch: '<S18>/Switch1' */

    /* BusAssignment: '<S18>/Bus Assignment1' incorporates:
     *  DataTypeConversion: '<S18>/Data Type Conversion10'
     *  DataTypeConversion: '<S18>/Data Type Conversion4'
     *  DataTypeConversion: '<S18>/Data Type Conversion5'
     *  Gain: '<S18>/Gain1'
     */
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle =
      COMM_subsystem_integrated_B.MedianFilter1_pnae.MedianFilter1;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = (real32_T)
      ((real_T)(0.27777777777777779 *
                COMM_subsystem_integrated_B.Decs_FedBck_VehSpd));
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC =
      (COMM_subsystem_integrated_B.Decs_FedBck_EPSmod != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeControlResponse =
      (COMM_subsystem_integrated_B.Decs_FedBck_ESCmod != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus =
      (COMM_subsystem_integrated_B.Decs_FedBck_Drivemod != 0.0);

    /* SwitchCase: '<S18>/Switch Case' */
    if (((int32_T)COMM_subsystem_integrated_B.Decs_FedBck_GearValue) == 2)
    {
      /* Outputs for IfAction SubSystem: '<S18>/GearR' incorporates:
       *  ActionPort: '<S36>/Action Port'
       */
      /* BusAssignment: '<S18>/Bus Assignment1' incorporates:
       *  Constant: '<S36>/Constant'
       *  SignalConversion: '<S36>/OutportBufferForOut1'
       */
      VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition =
        ((uint8_T)13U);

      /* End of Outputs for SubSystem: '<S18>/GearR' */
    }
    else
    {
      /* Outputs for IfAction SubSystem: '<S18>/GearNorD' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      /* BusAssignment: '<S18>/Bus Assignment1' incorporates:
       *  DataTypeConversion: '<S35>/Data Type Conversion3'
       */
      VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition = (uint8_T)
        COMM_subsystem_integrated_B.Decs_FedBck_GearValue;

      /* End of Outputs for SubSystem: '<S18>/GearNorD' */
    }

    /* End of SwitchCase: '<S18>/Switch Case' */

    /* BusAssignment: '<S18>/Bus Assignment1' incorporates:
     *  Constant: '<S18>/CTRL_VehicleCANbusConfig2'
     *  Constant: '<S18>/CTRL_VehicleCANbusConfig3'
     *  DataTypeConversion: '<S18>/Data Type Conversion3'
     *  Gain: '<S18>/Gain3'
     *  Inport: '<Root>/VbHWIO_ACC_CancelSwitch'
     *  Inport: '<Root>/VbHWIO_ACC_MainSwitch'
     *  Inport: '<Root>/VbHWIO_ACC_ResumeSwitch'
     *  Inport: '<Root>/VbHWIO_ACC_SetSwitch'
     *  Inport: '<Root>/VbHWIO_ACC_TimeGapMinus'
     *  Inport: '<Root>/VbHWIO_ACC_TimeGapPlus'
     *  Inport: '<Root>/VbHWIO_DriverModeComd'
     *  Inport: '<Root>/VbHWIO_LeftTurningLightState'
     *  Inport: '<Root>/VbHWIO_RightTurningLightState'
     *  Logic: '<S18>/Logical Operator1'
     *  Product: '<S18>/Product1'
     *  Sum: '<S18>/Add1'
     */
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition =
      COMM_subsystem_integrated_B.AccPed;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque =
      COMM_subsystem_integrated_B.EPS_SteeringTorqueAct;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch =
      ((COMM_subsystem_integrated_B.DriverModeComd != 0.0) ||
       VbHWIO_DriverModeComd);
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration =
      KfCOMM_a_VCULongAccOffset + (((real32_T)
      COMM_subsystem_integrated_B.ESC_FrP01_BrkPress_AccValue_o2) *
      KfCOMM_r_VCULongAccSlope);
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration =
      COMM_subsystem_integrated_B.ESC_FrP01_BrkPress_AccValue_o1;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPress =
      COMM_subsystem_integrated_B.ESC_FrP01_BrkPress_AccValue_o3;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate = (real32_T)((real_T)
      (0.017453292519943295 * COMM_subsystem_integrated_B.ESC_FrP01_YawRate));
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RL =
      COMM_subsystem_integrated_B.ABS_FrP01_RollingCounter_o1;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RR =
      COMM_subsystem_integrated_B.ABS_FrP01_RollingCounter_o2;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState =
      VbHWIO_LeftTurningLightState;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState =
      VbHWIO_RightTurningLightState;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwCancel = VbHWIO_ACC_CancelSwitch;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwResume = VbHWIO_ACC_ResumeSwitch;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwSet = VbHWIO_ACC_SetSwitch;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapPlus =
      VbHWIO_ACC_TimeGapPlus;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapMinus =
      VbHWIO_ACC_TimeGapMinus;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain = VbHWIO_ACC_MainSwitch;

    /* End of Outputs for SubSystem: '<S1>/iVISTA_New' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S1>/ICPV New' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* S-Function (scanunpack): '<S5>/VCU_ICPV_CAN_00' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU_ICPV_CAN_00' */
      if ((7 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.ID !=
           INVALID_CAN_ID) )
      {
        if ((520U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 28
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU_ICPV_ATOModFb = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 0
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  COMM_subsystem_integrated_B.VCU_ICPV_AccPelPosFb = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 24
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU_ICPV_AccPelSta = result;
                }
              }
            }

            /* --------------- START Unpacking signal 3 ------------------
             *  startBit                = 8
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  COMM_subsystem_integrated_B.VCU_ICPV_BrkPelPosFb = result;
                }
              }
            }

            /* --------------- START Unpacking signal 4 ------------------
             *  startBit                = 26
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU_ICPV_BrkPelSta = result;
                }
              }
            }

            /* --------------- START Unpacking signal 5 ------------------
             *  startBit                = 16
             *  length                  = 3
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                uint8_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__520.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (uint8_T) (unpackedValue);
                  }
                }

                {
                  uint8_T result = (uint8_T) outValue;
                  COMM_subsystem_integrated_B.VCU_ICPV_TgtSftFb = result;
                }
              }
            }

            /* --------------- START Unpacking signal 6 ------------------
             *  startBit                = 48
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S5>/VCU_ICPV_CAN_01' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU_ICPV_CAN_01' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__280.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__280.ID !=
           INVALID_CAN_ID) )
      {
        if ((280U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__280.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__280.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 5
             *  length                  = 3
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                uint8_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__280.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__280.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__280.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<2);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (uint8_T) (unpackedValue);
                  }
                }

                {
                  uint8_T result = (uint8_T) outValue;
                  COMM_subsystem_integrated_B.VCU_ICPV_CruiseControlSts = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 10
             *  length                  = 1
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__280.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU_ICPV_CruiseSwitchSts = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 61
             *  length                  = 3
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                uint8_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__280.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__280.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__280.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<2);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (uint8_T) (unpackedValue);
                  }
                }

                {
                  uint8_T result = (uint8_T) outValue;
                  COMM_subsystem_integrated_B.VCU_ICPV_EPBSysVCU = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S5>/VCU_ICPV_CAN_03' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU_ICPV_CAN_03' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.ID !=
           INVALID_CAN_ID) )
      {
        if ((1640U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 16
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.5
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = result * 0.5F;
                  COMM_subsystem_integrated_B.VUC_ICPV_AccPed = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 0
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.5
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1640.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = result * 0.5F;
                  COMM_subsystem_integrated_B.VUC_ICPV_BrkPed = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S5>/VCU_ICPV_CAN' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU_ICPV_CAN' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1560.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1560.ID !=
           INVALID_CAN_ID) )
      {
        if ((1560U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1560.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1560.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 0
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1560.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID_1560.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU_IPCV_BrkLgtSts = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_00' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_00' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__717.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__717.ID !=
           INVALID_CAN_ID) )
      {
        if ((717U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__717.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__717.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 49
             *  length                  = 1
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__717.Data
                            [6]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_BackDoorSts = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 56
             *  length                  = 1
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__717.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_DrvDoorStatus = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 52
             *  length                  = 1
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__717.Data
                            [6]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_HeadLampHighBeam =
                    result;
                }
              }
            }

            /* --------------- START Unpacking signal 3 ------------------
             *  startBit                = 47
             *  length                  = 1
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__717.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_HeadLampLowBeam = result;
                }
              }
            }

            /* --------------- START Unpacking signal 4 ------------------
             *  startBit                = 57
             *  length                  = 1
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__717.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_PsgDoorStatus = result;
                }
              }
            }

            /* --------------- START Unpacking signal 5 ------------------
             *  startBit                = 59
             *  length                  = 1
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__717.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_RLDoorStatus = result;
                }
              }
            }

            /* --------------- START Unpacking signal 6 ------------------
             *  startBit                = 58
             *  length                  = 1
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__717.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_RRDoorStatus = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_01' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_01' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.ID !=
           INVALID_CAN_ID) )
      {
        if ((421U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 49
             *  length                  = 15
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 4.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<14);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = result * 4.0F;
                  COMM_subsystem_integrated_B.VCU1_ICPV_StrAngleSpd = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 19
             *  length                  = 3
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__421.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<2);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_StrAngleSpdDir = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_02' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_02' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.ID !=
           INVALID_CAN_ID) )
      {
        if ((570U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 56
             *  length                  = 13
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_ESCWhlFLSpd = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 53
             *  length                  = 13
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<12);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_ESCWhlFRSpd = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 34
             *  length                  = 13
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<12);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_ESCWhlRLSpd = result;
                }
              }
            }

            /* --------------- START Unpacking signal 3 ------------------
             *  startBit                = 31
             *  length                  = 13
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__570.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<12);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_ESCWhlRRSpd = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_03' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_03' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.ID !=
           INVALID_CAN_ID) )
      {
        if ((517U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 24
             *  length                  = 10
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.01
             *  offset                  = -1.27
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = (result * 0.01F) + -1.27F;
                  COMM_subsystem_integrated_B.VCU1_ICPV_LongAcc = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 8
             *  length                  = 16
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.01
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__517.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = result * 0.01F;
                  COMM_subsystem_integrated_B.VCU1_ICPV_YawRate = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_04' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_04' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.ID !=
           INVALID_CAN_ID) )
      {
        if ((810U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 25
             *  length                  = 15
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.0563
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__810.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<14);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.0563;
                  COMM_subsystem_integrated_B.VCU1_ICPV_VehSpd = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_05' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_05' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__683.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__683.ID !=
           INVALID_CAN_ID) )
      {
        if ((683U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__683.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__683.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 32
             *  length                  = 1
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__683.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_DirIndicationLH = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 33
             *  length                  = 1
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__683.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_DirIndicationRH = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_06' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_06' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.ID !=
           INVALID_CAN_ID) )
      {
        if ((419U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 21
             *  length                  = 3
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<2);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_EPSDir = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 16
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU1_ICPV_EPSMODE = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 40
             *  length                  = 15
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.1
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.1;
                  COMM_subsystem_integrated_B.VCU1_ICPV_StrAngle = result;
                }
              }
            }

            /* --------------- START Unpacking signal 3 ------------------
             *  startBit                = 56
             *  length                  = 15
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.1
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID__419.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = result * 0.1F;
                  COMM_subsystem_integrated_B.VCU1_ICPV_StrAngleFb = result;
                }
              }
            }
          }
        }
      }
    }

    /* Switch: '<S5>/Switch2' incorporates:
     *  Constant: '<S5>/Constant4'
     *  Constant: '<S5>/Constant5'
     */
    if (COMM_subsystem_integrated_B.VCU1_ICPV_EPSDir > 0.0)
    {
      rtb_Gain1 = 1.0;
    }
    else
    {
      rtb_Gain1 = (-1.0);
    }

    /* End of Switch: '<S5>/Switch2' */

    /* Product: '<S5>/Product1' */
    rtb_Product1 = (real32_T)((real_T)
      (COMM_subsystem_integrated_B.VCU1_ICPV_StrAngle * rtb_Gain1));
    COMM_subsystem_in_MedianFilter1(rtb_Product1,
      &COMM_subsystem_integrated_B.MedianFilter1_pnaev,
      &COMM_subsystem_integrated_DW.MedianFilter1_pnaev);

    /* S-Function (scanunpack): '<S5>/VCU_ICPV_CAN_02' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU_ICPV_CAN_02' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__273.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__273.ID !=
           INVALID_CAN_ID) )
      {
        if ((273U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__273.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__273.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 52
             *  length                  = 4
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__273.Data
                            [6]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__273.Data
                            [6]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__273.Data
                            [6]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__273.Data
                            [6]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<3);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.VCU_ICPV_VCUGearLevPos = result;
                }
              }
            }
          }
        }
      }
    }

    /* SwitchCase: '<S5>/Switch Case' */
    switch ((int32_T)COMM_subsystem_integrated_B.VCU_ICPV_VCUGearLevPos)
    {
     case 0:
      /* Outputs for IfAction SubSystem: '<S5>/Invalid' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      /* SignalConversion: '<S31>/OutportBufferForOut1' incorporates:
       *  Constant: '<S31>/Constant'
       */
      rtb_Merge_jkuf = ((uint8_T)15U);

      /* End of Outputs for SubSystem: '<S5>/Invalid' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S5>/GearP' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      /* SignalConversion: '<S29>/OutportBufferForOut1' incorporates:
       *  Constant: '<S29>/Constant'
       */
      rtb_Merge_jkuf = ((uint8_T)14U);

      /* End of Outputs for SubSystem: '<S5>/GearP' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S5>/GearR' incorporates:
       *  ActionPort: '<S30>/Action Port'
       */
      /* SignalConversion: '<S30>/OutportBufferForOut1' incorporates:
       *  Constant: '<S30>/Constant'
       */
      rtb_Merge_jkuf = ((uint8_T)13U);

      /* End of Outputs for SubSystem: '<S5>/GearR' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<S5>/GearN' incorporates:
       *  ActionPort: '<S28>/Action Port'
       */
      /* SignalConversion: '<S28>/OutportBufferForOut1' incorporates:
       *  Constant: '<S28>/Constant'
       */
      rtb_Merge_jkuf = ((uint8_T)0U);

      /* End of Outputs for SubSystem: '<S5>/GearN' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S5>/default' incorporates:
       *  ActionPort: '<S32>/Action Port'
       */
      /* SignalConversion: '<S32>/OutportBufferForOut1' incorporates:
       *  Constant: '<S32>/Constant'
       */
      rtb_Merge_jkuf = ((uint8_T)1U);

      /* End of Outputs for SubSystem: '<S5>/default' */
      break;
    }

    /* End of SwitchCase: '<S5>/Switch Case' */

    /* BusAssignment: '<S5>/Bus Assignment1' incorporates:
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_0'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_1'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_2'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_3'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_4'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_5'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_6'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_7'
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/Constant10'
     *  Constant: '<S6>/Constant100'
     *  Constant: '<S6>/Constant101'
     *  Constant: '<S6>/Constant102'
     *  Constant: '<S6>/Constant103'
     *  Constant: '<S6>/Constant104'
     *  Constant: '<S6>/Constant105'
     *  Constant: '<S6>/Constant106'
     *  Constant: '<S6>/Constant108'
     *  Constant: '<S6>/Constant109'
     *  Constant: '<S6>/Constant11'
     *  Constant: '<S6>/Constant110'
     *  Constant: '<S6>/Constant112'
     *  Constant: '<S6>/Constant113'
     *  Constant: '<S6>/Constant114'
     *  Constant: '<S6>/Constant115'
     *  Constant: '<S6>/Constant116'
     *  Constant: '<S6>/Constant117'
     *  Constant: '<S6>/Constant118'
     *  Constant: '<S6>/Constant119'
     *  Constant: '<S6>/Constant12'
     *  Constant: '<S6>/Constant120'
     *  Constant: '<S6>/Constant121'
     *  Constant: '<S6>/Constant122'
     *  Constant: '<S6>/Constant123'
     *  Constant: '<S6>/Constant124'
     *  Constant: '<S6>/Constant127'
     *  Constant: '<S6>/Constant129'
     *  Constant: '<S6>/Constant13'
     *  Constant: '<S6>/Constant138'
     *  Constant: '<S6>/Constant139'
     *  Constant: '<S6>/Constant14'
     *  Constant: '<S6>/Constant140'
     *  Constant: '<S6>/Constant141'
     *  Constant: '<S6>/Constant142'
     *  Constant: '<S6>/Constant143'
     *  Constant: '<S6>/Constant144'
     *  Constant: '<S6>/Constant145'
     *  Constant: '<S6>/Constant146'
     *  Constant: '<S6>/Constant147'
     *  Constant: '<S6>/Constant148'
     *  Constant: '<S6>/Constant149'
     *  Constant: '<S6>/Constant15'
     *  Constant: '<S6>/Constant150'
     *  Constant: '<S6>/Constant151'
     *  Constant: '<S6>/Constant152'
     *  Constant: '<S6>/Constant153'
     *  Constant: '<S6>/Constant154'
     *  Constant: '<S6>/Constant155'
     *  Constant: '<S6>/Constant156'
     *  Constant: '<S6>/Constant157'
     *  Constant: '<S6>/Constant158'
     *  Constant: '<S6>/Constant159'
     *  Constant: '<S6>/Constant160'
     *  Constant: '<S6>/Constant162'
     *  Constant: '<S6>/Constant164'
     *  Constant: '<S6>/Constant165'
     *  Constant: '<S6>/Constant166'
     *  Constant: '<S6>/Constant167'
     *  Constant: '<S6>/Constant168'
     *  Constant: '<S6>/Constant169'
     *  Constant: '<S6>/Constant170'
     *  Constant: '<S6>/Constant171'
     *  Constant: '<S6>/Constant172'
     *  Constant: '<S6>/Constant173'
     *  Constant: '<S6>/Constant174'
     *  Constant: '<S6>/Constant175'
     *  Constant: '<S6>/Constant176'
     *  Constant: '<S6>/Constant177'
     *  Constant: '<S6>/Constant178'
     *  Constant: '<S6>/Constant179'
     *  Constant: '<S6>/Constant180'
     *  Constant: '<S6>/Constant181'
     *  Constant: '<S6>/Constant182'
     *  Constant: '<S6>/Constant183'
     *  Constant: '<S6>/Constant184'
     *  Constant: '<S6>/Constant185'
     *  Constant: '<S6>/Constant186'
     *  Constant: '<S6>/Constant2'
     *  Constant: '<S6>/Constant204'
     *  Constant: '<S6>/Constant3'
     *  Constant: '<S6>/Constant4'
     *  Constant: '<S6>/Constant5'
     *  Constant: '<S6>/Constant6'
     *  Constant: '<S6>/Constant7'
     *  Constant: '<S6>/Constant8'
     *  Constant: '<S6>/Constant83'
     *  Constant: '<S6>/Constant84'
     *  Constant: '<S6>/Constant85'
     *  Constant: '<S6>/Constant86'
     *  Constant: '<S6>/Constant87'
     *  Constant: '<S6>/Constant88'
     *  Constant: '<S6>/Constant89'
     *  Constant: '<S6>/Constant9'
     *  Constant: '<S6>/Constant90'
     *  Constant: '<S6>/Constant91'
     *  Constant: '<S6>/Constant92'
     *  Constant: '<S6>/Constant93'
     *  Constant: '<S6>/Constant94'
     *  Constant: '<S6>/Constant95'
     *  Constant: '<S6>/Constant96'
     *  Constant: '<S6>/Constant97'
     *  Constant: '<S6>/Constant98'
     *  Constant: '<S6>/Constant99'
     *  DataTypeConversion: '<S5>/Data Type Conversion1'
     *  DataTypeConversion: '<S5>/Data Type Conversion2'
     *  DataTypeConversion: '<S5>/Data Type Conversion3'
     *  DataTypeConversion: '<S5>/Data Type Conversion4'
     */
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch = true;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips = ((uint16_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwCancel = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwResume = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwSet = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapPlus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapMinus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwLimitMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriveMode = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBelt = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBeltValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_TurningLightEcho = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LowBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_HighBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_PassengerDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearRightDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearLeftDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_FrontHoodStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BackTrunkStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_WiperSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_ControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_TCSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_ABSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeAirTankPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_BrakePedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_TargetBrakePedalEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPress = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPressValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_AutoholdStatus = true;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ParkingControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SwitchStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_StartStopStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeedValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalOverride = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineState = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CoolantLevelLow = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowerControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_DriverDemandTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_ActualEngineTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineOilPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineCoolantTemperature = 0;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CatalystTankLevel = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_TargetAccelPedalPostionEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowertrainFaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_BatterySOC = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorActualTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_EngineTorqueLoss = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorqueValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LDW = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringModeEcho = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_TargetSteeringAngleEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringAngleRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_FaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOffWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOnWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_TargetGearPositionEcho =
      ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ShiftLevelPosition = ((uint8_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition = ((uint8_T)
      20U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearRatio = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRateValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FR = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FL = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FRValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FLValid = true;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RL = 1U;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RR = 1U;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalValid =
      (COMM_subsystem_integrated_B.VCU_ICPV_AccPelSta != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_BrakePedalValid =
      (COMM_subsystem_integrated_B.VCU_ICPV_BrkPelSta != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus =
      (COMM_subsystem_integrated_B.VCU_ICPV_ATOModFb != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_TargetGearPositionEcho =
      COMM_subsystem_integrated_B.VCU_ICPV_TgtSftFb;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_TargetBrakePedalEcho =
      COMM_subsystem_integrated_B.VCU_ICPV_BrkPelPosFb;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_TargetAccelPedalPostionEcho =
      COMM_subsystem_integrated_B.VCU_ICPV_AccPelPosFb;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus =
      COMM_subsystem_integrated_B.VCU_ICPV_EPBSysVCU;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain =
      (COMM_subsystem_integrated_B.VCU_ICPV_CruiseSwitchSts != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseControlStatus =
      COMM_subsystem_integrated_B.VCU_ICPV_CruiseControlSts;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition =
      COMM_subsystem_integrated_B.VUC_ICPV_AccPed;

    /* Switch: '<S5>/Switch3' */
    if (COMM_subsystem_integrated_B.VUC_ICPV_BrkPed > 0.0F)
    {
      /* BusAssignment: '<S5>/Bus Assignment1' incorporates:
       *  Constant: '<S5>/Constant6'
       *  DataTypeConversion: '<S5>/Data Type Conversion17'
       */
      VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = (((int32_T)
        ((uint8_T)1U)) != 0);
    }
    else
    {
      /* BusAssignment: '<S5>/Bus Assignment1' incorporates:
       *  Constant: '<S5>/Constant7'
       *  DataTypeConversion: '<S5>/Data Type Conversion17'
       */
      VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = (((int32_T)
        ((uint8_T)0U)) != 0);
    }

    /* End of Switch: '<S5>/Switch3' */

    /* BusAssignment: '<S5>/Bus Assignment1' incorporates:
     *  DataTypeConversion: '<S5>/Data Type Conversion10'
     *  DataTypeConversion: '<S5>/Data Type Conversion11'
     *  DataTypeConversion: '<S5>/Data Type Conversion12'
     *  DataTypeConversion: '<S5>/Data Type Conversion13'
     *  DataTypeConversion: '<S5>/Data Type Conversion14'
     *  DataTypeConversion: '<S5>/Data Type Conversion15'
     *  DataTypeConversion: '<S5>/Data Type Conversion16'
     *  DataTypeConversion: '<S5>/Data Type Conversion5'
     *  DataTypeConversion: '<S5>/Data Type Conversion6'
     *  DataTypeConversion: '<S5>/Data Type Conversion7'
     *  DataTypeConversion: '<S5>/Data Type Conversion8'
     *  DataTypeConversion: '<S5>/Data Type Conversion9'
     *  Gain: '<S5>/Gain'
     */
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus =
      (COMM_subsystem_integrated_B.VCU_IPCV_BrkLgtSts != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverDoorStatus =
      (COMM_subsystem_integrated_B.VCU1_ICPV_DrvDoorStatus != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_PassengerDoorStatus =
      (COMM_subsystem_integrated_B.VCU1_ICPV_PsgDoorStatus != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearRightDoorStatus =
      (COMM_subsystem_integrated_B.VCU1_ICPV_RRDoorStatus != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearLeftDoorStatus =
      (COMM_subsystem_integrated_B.VCU1_ICPV_RLDoorStatus != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BackTrunkStatus =
      (COMM_subsystem_integrated_B.VCU1_ICPV_BackDoorSts != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_HighBeamSwitch =
      (COMM_subsystem_integrated_B.VCU1_ICPV_HeadLampHighBeam != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LowBeamSwitch =
      (COMM_subsystem_integrated_B.VCU1_ICPV_HeadLampLowBeam != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringAngleRate =
      COMM_subsystem_integrated_B.VCU1_ICPV_StrAngleSpd;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FL =
      COMM_subsystem_integrated_B.VCU1_ICPV_ESCWhlFLSpd;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FR =
      COMM_subsystem_integrated_B.VCU1_ICPV_ESCWhlFRSpd;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1 =
      COMM_subsystem_integrated_B.VCU1_ICPV_ESCWhlRLSpd;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1 =
      COMM_subsystem_integrated_B.VCU1_ICPV_ESCWhlRRSpd;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration =
      COMM_subsystem_integrated_B.VCU1_ICPV_LongAcc;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate =
      COMM_subsystem_integrated_B.VCU1_ICPV_YawRate;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = (real32_T)
      ((real_T)(0.27777777777777779 *
                COMM_subsystem_integrated_B.VCU1_ICPV_VehSpd));
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState =
      (COMM_subsystem_integrated_B.VCU1_ICPV_DirIndicationLH != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState =
      (COMM_subsystem_integrated_B.VCU1_ICPV_DirIndicationRH != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_TargetSteeringAngleEcho =
      COMM_subsystem_integrated_B.VCU1_ICPV_StrAngleFb;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle =
      COMM_subsystem_integrated_B.MedianFilter1_pnaev.MedianFilter1;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC =
      (COMM_subsystem_integrated_B.VCU1_ICPV_EPSMODE != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition =
      rtb_Merge_jkuf;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_TurningLightEcho =
      (COMM_subsystem_integrated_B.VCU1_ICPV_StrAngleSpdDir != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition =
      COMM_subsystem_integrated_B.VUC_ICPV_BrkPed;

    /* S-Function (scanunpack): '<S5>/PCU_ICPV_CAN' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/PCU_ICPV_CAN' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__530.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__530.ID !=
           INVALID_CAN_ID) )
      {
        if ((530U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__530.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_2_ID__530.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 60
             *  length                  = 2
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_1' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S5>/VCU1_ICPV_CAN_1' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID_1638.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID_1638.ID !=
           INVALID_CAN_ID) )
      {
        if ((1638U == VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID_1638.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_3_Receive__CAN_0_ID_1638.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 0
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 8
             *  length                  = 8
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */
          }
        }
      }
    }

    /* End of Outputs for SubSystem: '<S1>/ICPV New' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S1>/HZBus_NewMatrix New' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* S-Function (scanunpack): '<S4>/Vehicle_Message_1' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S4>/Vehicle_Message_1' */
      if ((8 ==
           VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.ID !=
           INVALID_CAN_ID) )
      {
        if ((201434535U ==
             VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.ID) &&
            (1U ==
             VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 8
             *  length                  = 2
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Vehicle_Message_1_o1 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 11
             *  length                  = 1
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Vehicle_Message_1_o2 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 6
             *  length                  = 2
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<1);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Vehicle_Message_1_o3 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 3 ------------------
             *  startBit                = 10
             *  length                  = 1
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */

            /* --------------- START Unpacking signal 4 ------------------
             *  startBit                = 32
             *  length                  = 16
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Vehicle_Message_1_o5 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 5 ------------------
             *  startBit                = 3
             *  length                  = 3
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<2);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Vehicle_Message_1_o6 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 6 ------------------
             *  startBit                = 0
             *  length                  = 3
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201434535.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Vehicle_Message_1_o7 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 7 ------------------
             *  startBit                = 16
             *  length                  = 16
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S4>/ESC_Message' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S4>/ESC_Message' */
      if ((8 ==
           VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.ID !=
           INVALID_CAN_ID) )
      {
        if ((418384139U ==
             VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.ID) &&
            (1U ==
             VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 40
             *  length                  = 16
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.000488
             *  offset                  = -15.678
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.000488) + -15.678;
                  COMM_subsystem_integrated_B.ESC_Message_o1 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 56
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.1
             *  offset                  = -12.5
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [7]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.1) + -12.5;
                  COMM_subsystem_integrated_B.ESC_Message_o2 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 22
             *  length                  = 2
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */

            /* --------------- START Unpacking signal 3 ------------------
             *  startBit                = 0
             *  length                  = 16
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.0009765
             *  offset                  = -31.374
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.0009765) + -31.374;
                  COMM_subsystem_integrated_B.ESC_Message_o4 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 4 ------------------
             *  startBit                = 16
             *  length                  = 6
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = -32.0
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */

            /* --------------- START Unpacking signal 5 ------------------
             *  startBit                = 24
             *  length                  = 16
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.000122
             *  offset                  = -3.92
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_418384139.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.000122) + -3.92;
                  COMM_subsystem_integrated_B.ESC_Message_o6 = result;
                }
              }
            }
          }
        }
      }
    }

    /* Gain: '<S4>/Gain1' */
    rtb_Gain1 = 57.295779513082323 * COMM_subsystem_integrated_B.ESC_Message_o4;

    /* S-Function (scanunpack): '<S4>/Vehicle_Message_2' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S4>/Vehicle_Message_2' */
      if ((8 ==
           VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.ID !=
           INVALID_CAN_ID) )
      {
        if ((201443255U ==
             VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.ID) &&
            (1U ==
             VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 32
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.4
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.4;
                  COMM_subsystem_integrated_B.Vehicle_Message_2_o1 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 3
             *  length                  = 1
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Vehicle_Message_2_o2 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 24
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.4
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.4;
                  COMM_subsystem_integrated_B.Vehicle_Message_2_o3 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 3 ------------------
             *  startBit                = 40
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Vehicle_Message_2_o4 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 4 ------------------
             *  startBit                = 8
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [1]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Vehicle_Message_2_o5 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 5 ------------------
             *  startBit                = 0
             *  length                  = 1
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Vehicle_Message_2_o6 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 6 ------------------
             *  startBit                = 1
             *  length                  = 1
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.Vehicle_Message_2_o7 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 7 ------------------
             *  startBit                = 2
             *  length                  = 1
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */

            /* --------------- START Unpacking signal 8 ------------------
             *  startBit                = 16
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.5
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_201443255.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.5;
                  COMM_subsystem_integrated_B.Vehicle_Message_2_o9 = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S4>/EBS_WheelSpeed' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S4>/EBS_WheelSpeed' */
      if ((8 ==
           VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.ID !=
           INVALID_CAN_ID) )
      {
        if ((419348235U ==
             VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.ID) &&
            (1U ==
             VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 16
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.0625
             *  offset                  = -7.8125
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [2]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.0625) + -7.8125;
                  COMM_subsystem_integrated_B.EBS_WheelSpeed_o1 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 24
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.0625
             *  offset                  = -7.8125
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.0625) + -7.8125;
                  COMM_subsystem_integrated_B.EBS_WheelSpeed_o2 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 32
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.0625
             *  offset                  = -7.8125
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.0625) + -7.8125;
                  COMM_subsystem_integrated_B.EBS_WheelSpeed_o3 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 3 ------------------
             *  startBit                = 48
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.0625
             *  offset                  = -7.8125
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */

            /* --------------- START Unpacking signal 4 ------------------
             *  startBit                = 40
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.0625
             *  offset                  = -7.8125
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_6_Receive__CAN_4_ID_419348235.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.0625) + -7.8125;
                  COMM_subsystem_integrated_B.EBS_WheelSpeed_o5 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 5 ------------------
             *  startBit                = 56
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.0625
             *  offset                  = -7.8125
             * -----------------------------------------------------------------------*/
            /*
             * Signal is not connected or connected to terminator.
             * No unpacking code generated.
             */
          }
        }
      }
    }

    /* MATLAB Function: '<S4>/DoorStatusRemapping' */
    switch ((int32_T)COMM_subsystem_integrated_B.Vehicle_Message_2_o4)
    {
     case 0:
      rtb_Merge_jkuf = 0U;
      rtb_middle_door_open = 0U;
      break;

     case 1:
      rtb_Merge_jkuf = 1U;
      rtb_middle_door_open = 0U;
      break;

     case 2:
      rtb_Merge_jkuf = 0U;
      rtb_middle_door_open = 1U;
      break;

     case 3:
      rtb_Merge_jkuf = 1U;
      rtb_middle_door_open = 1U;
      break;

     default:
      rtb_Merge_jkuf = 2U;
      rtb_middle_door_open = 2U;
      break;
    }

    /* End of MATLAB Function: '<S4>/DoorStatusRemapping' */

    /* SwitchCase: '<S4>/Switch Case' */
    switch ((int32_T)COMM_subsystem_integrated_B.Vehicle_Message_2_o5)
    {
     case 1:
      /* Outputs for IfAction SubSystem: '<S4>/GearN' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      /* SignalConversion: '<S25>/OutportBufferForOut1' incorporates:
       *  Constant: '<S25>/Constant'
       */
      rtb_Merge_eeee = ((uint8_T)0U);

      /* End of Outputs for SubSystem: '<S4>/GearN' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<S4>/GearD' incorporates:
       *  ActionPort: '<S24>/Action Port'
       */
      /* SignalConversion: '<S24>/OutportBufferForOut1' incorporates:
       *  Constant: '<S24>/Constant'
       */
      rtb_Merge_eeee = ((uint8_T)1U);

      /* End of Outputs for SubSystem: '<S4>/GearD' */
      break;

     case 4:
      /* Outputs for IfAction SubSystem: '<S4>/GearR' incorporates:
       *  ActionPort: '<S26>/Action Port'
       */
      /* SignalConversion: '<S26>/OutportBufferForOut1' incorporates:
       *  Constant: '<S26>/Constant'
       */
      rtb_Merge_eeee = ((uint8_T)13U);

      /* End of Outputs for SubSystem: '<S4>/GearR' */
      break;

     default:
      /* Outputs for IfAction SubSystem: '<S4>/default' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      /* SignalConversion: '<S27>/OutportBufferForOut1' incorporates:
       *  Constant: '<S27>/Constant'
       */
      rtb_Merge_eeee = ((uint8_T)15U);

      /* End of Outputs for SubSystem: '<S4>/default' */
      break;
    }

    /* End of SwitchCase: '<S4>/Switch Case' */

    /* BusAssignment: '<S4>/Bus Assignment1' incorporates:
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_0'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_1'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_2'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_3'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_4'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_5'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_6'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_7'
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/Constant10'
     *  Constant: '<S6>/Constant100'
     *  Constant: '<S6>/Constant101'
     *  Constant: '<S6>/Constant102'
     *  Constant: '<S6>/Constant103'
     *  Constant: '<S6>/Constant104'
     *  Constant: '<S6>/Constant105'
     *  Constant: '<S6>/Constant106'
     *  Constant: '<S6>/Constant108'
     *  Constant: '<S6>/Constant109'
     *  Constant: '<S6>/Constant11'
     *  Constant: '<S6>/Constant110'
     *  Constant: '<S6>/Constant112'
     *  Constant: '<S6>/Constant113'
     *  Constant: '<S6>/Constant114'
     *  Constant: '<S6>/Constant115'
     *  Constant: '<S6>/Constant116'
     *  Constant: '<S6>/Constant117'
     *  Constant: '<S6>/Constant118'
     *  Constant: '<S6>/Constant119'
     *  Constant: '<S6>/Constant12'
     *  Constant: '<S6>/Constant120'
     *  Constant: '<S6>/Constant121'
     *  Constant: '<S6>/Constant122'
     *  Constant: '<S6>/Constant123'
     *  Constant: '<S6>/Constant124'
     *  Constant: '<S6>/Constant127'
     *  Constant: '<S6>/Constant129'
     *  Constant: '<S6>/Constant13'
     *  Constant: '<S6>/Constant138'
     *  Constant: '<S6>/Constant139'
     *  Constant: '<S6>/Constant14'
     *  Constant: '<S6>/Constant140'
     *  Constant: '<S6>/Constant141'
     *  Constant: '<S6>/Constant142'
     *  Constant: '<S6>/Constant143'
     *  Constant: '<S6>/Constant144'
     *  Constant: '<S6>/Constant145'
     *  Constant: '<S6>/Constant146'
     *  Constant: '<S6>/Constant147'
     *  Constant: '<S6>/Constant148'
     *  Constant: '<S6>/Constant149'
     *  Constant: '<S6>/Constant15'
     *  Constant: '<S6>/Constant150'
     *  Constant: '<S6>/Constant151'
     *  Constant: '<S6>/Constant152'
     *  Constant: '<S6>/Constant153'
     *  Constant: '<S6>/Constant154'
     *  Constant: '<S6>/Constant155'
     *  Constant: '<S6>/Constant156'
     *  Constant: '<S6>/Constant157'
     *  Constant: '<S6>/Constant158'
     *  Constant: '<S6>/Constant159'
     *  Constant: '<S6>/Constant160'
     *  Constant: '<S6>/Constant162'
     *  Constant: '<S6>/Constant164'
     *  Constant: '<S6>/Constant165'
     *  Constant: '<S6>/Constant166'
     *  Constant: '<S6>/Constant167'
     *  Constant: '<S6>/Constant168'
     *  Constant: '<S6>/Constant169'
     *  Constant: '<S6>/Constant170'
     *  Constant: '<S6>/Constant171'
     *  Constant: '<S6>/Constant172'
     *  Constant: '<S6>/Constant173'
     *  Constant: '<S6>/Constant174'
     *  Constant: '<S6>/Constant175'
     *  Constant: '<S6>/Constant176'
     *  Constant: '<S6>/Constant177'
     *  Constant: '<S6>/Constant178'
     *  Constant: '<S6>/Constant179'
     *  Constant: '<S6>/Constant180'
     *  Constant: '<S6>/Constant181'
     *  Constant: '<S6>/Constant182'
     *  Constant: '<S6>/Constant183'
     *  Constant: '<S6>/Constant184'
     *  Constant: '<S6>/Constant185'
     *  Constant: '<S6>/Constant186'
     *  Constant: '<S6>/Constant2'
     *  Constant: '<S6>/Constant204'
     *  Constant: '<S6>/Constant3'
     *  Constant: '<S6>/Constant4'
     *  Constant: '<S6>/Constant5'
     *  Constant: '<S6>/Constant6'
     *  Constant: '<S6>/Constant7'
     *  Constant: '<S6>/Constant8'
     *  Constant: '<S6>/Constant83'
     *  Constant: '<S6>/Constant84'
     *  Constant: '<S6>/Constant85'
     *  Constant: '<S6>/Constant86'
     *  Constant: '<S6>/Constant87'
     *  Constant: '<S6>/Constant88'
     *  Constant: '<S6>/Constant89'
     *  Constant: '<S6>/Constant9'
     *  Constant: '<S6>/Constant90'
     *  Constant: '<S6>/Constant91'
     *  Constant: '<S6>/Constant92'
     *  Constant: '<S6>/Constant93'
     *  Constant: '<S6>/Constant94'
     *  Constant: '<S6>/Constant95'
     *  Constant: '<S6>/Constant96'
     *  Constant: '<S6>/Constant97'
     *  Constant: '<S6>/Constant98'
     *  Constant: '<S6>/Constant99'
     *  DataTypeConversion: '<S4>/Data Type Conversion10'
     *  DataTypeConversion: '<S4>/Data Type Conversion11'
     *  DataTypeConversion: '<S4>/Data Type Conversion12'
     *  DataTypeConversion: '<S4>/Data Type Conversion21'
     *  DataTypeConversion: '<S4>/Data Type Conversion22'
     *  DataTypeConversion: '<S4>/Data Type Conversion24'
     *  DataTypeConversion: '<S4>/Data Type Conversion25'
     *  DataTypeConversion: '<S4>/Data Type Conversion26'
     *  DataTypeConversion: '<S4>/Data Type Conversion27'
     *  DataTypeConversion: '<S4>/Data Type Conversion28'
     *  DataTypeConversion: '<S4>/Data Type Conversion29'
     *  DataTypeConversion: '<S4>/Data Type Conversion30'
     *  DataTypeConversion: '<S4>/Data Type Conversion31'
     *  DataTypeConversion: '<S4>/Data Type Conversion32'
     *  DataTypeConversion: '<S4>/Data Type Conversion4'
     *  DataTypeConversion: '<S4>/Data Type Conversion6'
     *  DataTypeConversion: '<S4>/Data Type Conversion9'
     *  Gain: '<S4>/Gain = 1//3.6_5'
     *  Gain: '<S4>/Gain = 1//3.6_6'
     *  Gain: '<S4>/Gain = 1//3.6_7'
     *  Gain: '<S4>/Gain = 1//3.6_8'
     *  Gain: '<S4>/Gain = 1//3.6_9'
     */
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch = true;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips = ((uint16_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwCancel = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwResume = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwSet = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapPlus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapMinus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwLimitMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriveMode = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBelt = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBeltValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_TurningLightEcho = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LowBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_HighBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_PassengerDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearRightDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearLeftDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_FrontHoodStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BackTrunkStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_WiperSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_ControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_TCSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_ABSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeAirTankPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_BrakePedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_TargetBrakePedalEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPress = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPressValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_AutoholdStatus = true;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ParkingControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SwitchStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_StartStopStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeedValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalOverride = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineState = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CoolantLevelLow = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowerControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_DriverDemandTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_ActualEngineTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineOilPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineCoolantTemperature = 0;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CatalystTankLevel = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_TargetAccelPedalPostionEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowertrainFaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_BatterySOC = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorActualTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_EngineTorqueLoss = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorqueValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LDW = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringModeEcho = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_TargetSteeringAngleEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringAngleRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_FaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOffWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOnWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_TargetGearPositionEcho =
      ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ShiftLevelPosition = ((uint8_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition = ((uint8_T)
      20U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearRatio = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRateValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FR = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FL = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FRValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FLValid = true;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RL = 1U;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RR = 1U;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus =
      (COMM_subsystem_integrated_B.Vehicle_Message_1_o1 != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle = (real32_T)
      rtb_Gain1;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_TargetSteeringAngleEcho = (real32_T)
      rtb_Gain1;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_TargetAccelPedalPostionEcho =
      (real32_T)COMM_subsystem_integrated_B.Vehicle_Message_2_o1;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition = (real32_T)
      COMM_subsystem_integrated_B.Vehicle_Message_2_o1;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_TargetBrakePedalEcho = (real32_T)
      COMM_subsystem_integrated_B.Vehicle_Message_2_o3;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition = (real32_T)
      COMM_subsystem_integrated_B.Vehicle_Message_2_o3;
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_TargetGearPositionEcho =
      rtb_Merge_eeee;
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition =
      rtb_Merge_eeee;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = (real32_T)
      ((real_T)(0.27777777777777779 *
                COMM_subsystem_integrated_B.Vehicle_Message_2_o9));
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration = (real32_T)
      COMM_subsystem_integrated_B.ESC_Message_o2;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration =
      (real32_T)COMM_subsystem_integrated_B.ESC_Message_o1;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1 = (real32_T)
      ((real_T)(0.27777777777777779 *
                COMM_subsystem_integrated_B.EBS_WheelSpeed_o5));
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1 = (real32_T)
      ((real_T)(0.27777777777777779 *
                COMM_subsystem_integrated_B.EBS_WheelSpeed_o3));
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FR = (real32_T)
      ((real_T)(0.27777777777777779 *
                COMM_subsystem_integrated_B.EBS_WheelSpeed_o2));
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FL = (real32_T)
      ((real_T)(0.27777777777777779 *
                COMM_subsystem_integrated_B.EBS_WheelSpeed_o1));
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus =
      (COMM_subsystem_integrated_B.Vehicle_Message_2_o2 != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch =
      (COMM_subsystem_integrated_B.Vehicle_Message_1_o3 != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState =
      (COMM_subsystem_integrated_B.Vehicle_Message_2_o6 != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState =
      (COMM_subsystem_integrated_B.Vehicle_Message_2_o7 != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate = (real32_T)
      COMM_subsystem_integrated_B.ESC_Message_o6;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus = (uint8_T)
      COMM_subsystem_integrated_B.Vehicle_Message_1_o6;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState =
      (COMM_subsystem_integrated_B.Vehicle_Message_1_o7 != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPress = (real32_T)
      COMM_subsystem_integrated_B.Vehicle_Message_1_o5;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_PassengerDoorStatus = (((int32_T)
      rtb_Merge_jkuf) != 0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearRightDoorStatus = (((int32_T)
      rtb_middle_door_open) != 0);
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_SystemFaultStatus = (uint8_T)
      COMM_subsystem_integrated_B.Vehicle_Message_1_o2;

    /* End of Outputs for SubSystem: '<S1>/HZBus_NewMatrix New' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S1>/USdemo New' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* S-Function (scanunpack): '<S15>/BUS_BCUState' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S15>/BUS_BCUState' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__820.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__820.ID !=
           INVALID_CAN_ID) )
      {
        if ((820U == VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__820.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__820.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 30
             *  length                  = 1
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__820.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.BUS_BCUState_o1 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 31
             *  length                  = 1
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__820.Data
                            [3]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.BUS_BCUState_o2 = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S15>/BUS_BCUState1' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S15>/BUS_BCUState1' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.ID !=
           INVALID_CAN_ID) )
      {
        if ((544U == VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 6
             *  length                  = 1
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 1.0
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Data
                            [0]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<0);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  COMM_subsystem_integrated_B.BUS_BCUState1_o1 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 8
             *  length                  = 11
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.0078125
             *  offset                  = -8.0
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__544.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = (result * 0.0078125F) + -8.0F;
                  COMM_subsystem_integrated_B.BUS_BCUState1_o2 = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S15>/BUS_BCUState2' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S15>/BUS_BCUState2' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.ID !=
           INVALID_CAN_ID) )
      {
        if ((332U == VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 32
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.08
             *  offset                  = -10.24
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [4]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = (result * 0.08F) + -10.24F;
                  COMM_subsystem_integrated_B.BUS_BCUState2_o1 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 40
             *  length                  = 8
             *  desiredSignalByteLayout = LITTLEENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.08
             *  offset                  = -10.24
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint8_T unpackedValue = 0;

                    {
                      uint8_T tempValue = (uint8_T) (0);

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint8_T)((uint8_T)((uint8_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [5]) & (uint8_T)( (uint8_T) (1)<< 7)) >> 7)<<7);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = (result * 0.08F) + -10.24F;
                  COMM_subsystem_integrated_B.BUS_BCUState2_o2 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 8
             *  length                  = 16
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.01
             *  offset                  = -327.68
             * -----------------------------------------------------------------------*/
            {
              {
                real32_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__332.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real32_T) (unpackedValue);
                  }
                }

                {
                  real32_T result = (real32_T) outValue;
                  result = (result * 0.01F) + -327.68F;
                  COMM_subsystem_integrated_B.BUS_BCUState2_o3 = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S15>/BUS_BCUState3' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S15>/BUS_BCUState3' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.ID !=
           INVALID_CAN_ID) )
      {
        if ((344U == VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 8
             *  length                  = 14
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.5
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.5;
                  COMM_subsystem_integrated_B.BUS_BCUState3_o1 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 1 ------------------
             *  startBit                = 24
             *  length                  = 14
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.5
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [3]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [2]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.5;
                  COMM_subsystem_integrated_B.BUS_BCUState3_o2 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 2 ------------------
             *  startBit                = 40
             *  length                  = 14
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.5
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.5;
                  COMM_subsystem_integrated_B.BUS_BCUState3_o3 = result;
                }
              }
            }

            /* --------------- START Unpacking signal 3 ------------------
             *  startBit                = 56
             *  length                  = 14
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.5
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [7]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__344.Data
                            [6]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.5;
                  COMM_subsystem_integrated_B.BUS_BCUState3_o4 = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S15>/BUS_BCUState4' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S15>/BUS_BCUState4' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.ID !=
           INVALID_CAN_ID) )
      {
        if ((284U == VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 40
             *  length                  = 16
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.0078125
             *  offset                  = 0.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [5]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<14);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__284.Data
                            [4]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<15);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = result * 0.0078125;
                  COMM_subsystem_integrated_B.BUS_BCUState4 = result;
                }
              }
            }
          }
        }
      }
    }

    /* S-Function (scanunpack): '<S15>/BUS_BCUState5' incorporates:
     *  Inport: '<Root>/VsCOMM_CAN_Data_Receive'
     */
    {
      /* S-Function (scanunpack): '<S15>/BUS_BCUState5' */
      if ((8 == VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Length) &&
          (VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.ID !=
           INVALID_CAN_ID) )
      {
        if ((258U == VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.ID)
            && (0U ==
                VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Extended)
            )
        {
          {
            /* --------------- START Unpacking signal 0 ------------------
             *  startBit                = 8
             *  length                  = 14
             *  desiredSignalByteLayout = BIGENDIAN
             *  dataType                = UNSIGNED
             *  factor                  = 0.5
             *  offset                  = -2048.0
             * -----------------------------------------------------------------------*/
            {
              {
                real64_T outValue = 0;

                {
                  {
                    uint16_T unpackedValue = 0;

                    {
                      uint16_T tempValue = (uint16_T) (0);

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<0);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<1);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<2);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<3);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<4);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<5);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 6)) >> 6)<<6);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [1]) & (uint16_T)( (uint16_T) (1)<< 7)) >> 7)<<7);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 0)) >> 0)<<8);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 1)) >> 1)<<9);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 2)) >> 2)<<10);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 3)) >> 3)<<11);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 4)) >> 4)<<12);
                      }

                      {
                        tempValue = tempValue | (uint16_T)((uint16_T)((uint16_T)
                          ((VsCOMM_CAN_Data_Receive.Config_7_Receive__CAN_2_ID__258.Data
                            [0]) & (uint16_T)( (uint16_T) (1)<< 5)) >> 5)<<13);
                      }

                      unpackedValue = tempValue;
                    }

                    outValue = (real64_T) (unpackedValue);
                  }
                }

                {
                  real64_T result = (real64_T) outValue;
                  result = (result * 0.5) + -2048.0;
                  COMM_subsystem_integrated_B.BUS_BCUState5 = result;
                }
              }
            }
          }
        }
      }
    }

    /* DataTypeConversion: '<S15>/Data Type Conversion' */
    rtb_DataTypeConversion = (real32_T)COMM_subsystem_integrated_B.BUS_BCUState5;
    COMM_subsystem_in_MedianFilter1(rtb_DataTypeConversion,
      &COMM_subsystem_integrated_B.MedianFilter1_pnaevv,
      &COMM_subsystem_integrated_DW.MedianFilter1_pnaevv);

    /* BusAssignment: '<S15>/Bus Assignment1' incorporates:
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_0'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_1'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_2'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_3'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_4'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_5'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_6'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_7'
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/Constant10'
     *  Constant: '<S6>/Constant100'
     *  Constant: '<S6>/Constant101'
     *  Constant: '<S6>/Constant102'
     *  Constant: '<S6>/Constant103'
     *  Constant: '<S6>/Constant104'
     *  Constant: '<S6>/Constant105'
     *  Constant: '<S6>/Constant106'
     *  Constant: '<S6>/Constant108'
     *  Constant: '<S6>/Constant109'
     *  Constant: '<S6>/Constant11'
     *  Constant: '<S6>/Constant110'
     *  Constant: '<S6>/Constant112'
     *  Constant: '<S6>/Constant113'
     *  Constant: '<S6>/Constant114'
     *  Constant: '<S6>/Constant115'
     *  Constant: '<S6>/Constant116'
     *  Constant: '<S6>/Constant117'
     *  Constant: '<S6>/Constant118'
     *  Constant: '<S6>/Constant119'
     *  Constant: '<S6>/Constant12'
     *  Constant: '<S6>/Constant120'
     *  Constant: '<S6>/Constant121'
     *  Constant: '<S6>/Constant122'
     *  Constant: '<S6>/Constant123'
     *  Constant: '<S6>/Constant124'
     *  Constant: '<S6>/Constant127'
     *  Constant: '<S6>/Constant129'
     *  Constant: '<S6>/Constant13'
     *  Constant: '<S6>/Constant138'
     *  Constant: '<S6>/Constant139'
     *  Constant: '<S6>/Constant14'
     *  Constant: '<S6>/Constant140'
     *  Constant: '<S6>/Constant141'
     *  Constant: '<S6>/Constant142'
     *  Constant: '<S6>/Constant143'
     *  Constant: '<S6>/Constant144'
     *  Constant: '<S6>/Constant145'
     *  Constant: '<S6>/Constant146'
     *  Constant: '<S6>/Constant147'
     *  Constant: '<S6>/Constant148'
     *  Constant: '<S6>/Constant149'
     *  Constant: '<S6>/Constant15'
     *  Constant: '<S6>/Constant150'
     *  Constant: '<S6>/Constant151'
     *  Constant: '<S6>/Constant152'
     *  Constant: '<S6>/Constant153'
     *  Constant: '<S6>/Constant154'
     *  Constant: '<S6>/Constant155'
     *  Constant: '<S6>/Constant156'
     *  Constant: '<S6>/Constant157'
     *  Constant: '<S6>/Constant158'
     *  Constant: '<S6>/Constant159'
     *  Constant: '<S6>/Constant160'
     *  Constant: '<S6>/Constant162'
     *  Constant: '<S6>/Constant164'
     *  Constant: '<S6>/Constant165'
     *  Constant: '<S6>/Constant166'
     *  Constant: '<S6>/Constant167'
     *  Constant: '<S6>/Constant168'
     *  Constant: '<S6>/Constant169'
     *  Constant: '<S6>/Constant170'
     *  Constant: '<S6>/Constant171'
     *  Constant: '<S6>/Constant172'
     *  Constant: '<S6>/Constant173'
     *  Constant: '<S6>/Constant174'
     *  Constant: '<S6>/Constant175'
     *  Constant: '<S6>/Constant176'
     *  Constant: '<S6>/Constant177'
     *  Constant: '<S6>/Constant178'
     *  Constant: '<S6>/Constant179'
     *  Constant: '<S6>/Constant180'
     *  Constant: '<S6>/Constant181'
     *  Constant: '<S6>/Constant182'
     *  Constant: '<S6>/Constant183'
     *  Constant: '<S6>/Constant184'
     *  Constant: '<S6>/Constant185'
     *  Constant: '<S6>/Constant186'
     *  Constant: '<S6>/Constant2'
     *  Constant: '<S6>/Constant204'
     *  Constant: '<S6>/Constant3'
     *  Constant: '<S6>/Constant4'
     *  Constant: '<S6>/Constant5'
     *  Constant: '<S6>/Constant6'
     *  Constant: '<S6>/Constant7'
     *  Constant: '<S6>/Constant8'
     *  Constant: '<S6>/Constant83'
     *  Constant: '<S6>/Constant84'
     *  Constant: '<S6>/Constant85'
     *  Constant: '<S6>/Constant86'
     *  Constant: '<S6>/Constant87'
     *  Constant: '<S6>/Constant88'
     *  Constant: '<S6>/Constant89'
     *  Constant: '<S6>/Constant9'
     *  Constant: '<S6>/Constant90'
     *  Constant: '<S6>/Constant91'
     *  Constant: '<S6>/Constant92'
     *  Constant: '<S6>/Constant93'
     *  Constant: '<S6>/Constant94'
     *  Constant: '<S6>/Constant95'
     *  Constant: '<S6>/Constant96'
     *  Constant: '<S6>/Constant97'
     *  Constant: '<S6>/Constant98'
     *  Constant: '<S6>/Constant99'
     *  DataTypeConversion: '<S15>/Data Type Conversion1'
     *  DataTypeConversion: '<S15>/Data Type Conversion2'
     *  DataTypeConversion: '<S15>/Data Type Conversion3'
     *  DataTypeConversion: '<S15>/Data Type Conversion4'
     *  Gain: '<S15>/Gain = 1//3.6_5'
     *  Gain: '<S15>/Gain = 1//3.6_6'
     *  Gain: '<S15>/Gain = 1//3.6_7'
     *  Gain: '<S15>/Gain = 1//3.6_8'
     *  Gain: '<S15>/Gain = 1//3.6_9'
     *  Gain: '<S15>/Gain1'
     */
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch = true;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips = ((uint16_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwCancel = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwResume = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwSet = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapPlus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapMinus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwLimitMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriveMode = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBelt = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBeltValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_TurningLightEcho = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LowBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_HighBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_PassengerDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearRightDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearLeftDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_FrontHoodStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BackTrunkStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_WiperSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_ControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_TCSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_ABSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeAirTankPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_BrakePedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_TargetBrakePedalEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPress = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPressValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_AutoholdStatus = true;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ParkingControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SwitchStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_StartStopStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeedValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalOverride = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineState = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CoolantLevelLow = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowerControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_DriverDemandTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_ActualEngineTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineOilPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineCoolantTemperature = 0;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CatalystTankLevel = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_TargetAccelPedalPostionEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowertrainFaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_BatterySOC = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorActualTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_EngineTorqueLoss = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorqueValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LDW = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringModeEcho = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_TargetSteeringAngleEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringAngleRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_FaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOffWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOnWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_TargetGearPositionEcho =
      ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ShiftLevelPosition = ((uint8_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition = ((uint8_T)
      20U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearRatio = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRateValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FR = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FL = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FRValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FLValid = true;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RL = 1U;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RR = 1U;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch =
      COMM_subsystem_integrate_ConstB.DataTypeConversion6;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus =
      (COMM_subsystem_integrated_B.BUS_BCUState1_o1 != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC =
      (COMM_subsystem_integrated_B.BUS_BCUState1_o1 != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle = (-1.0F) *
      COMM_subsystem_integrated_B.MedianFilter1_pnaevv.MedianFilter1;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque =
      COMM_subsystem_integrated_B.BUS_BCUState1_o2;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState =
      (COMM_subsystem_integrated_B.BUS_BCUState_o2 != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState =
      (COMM_subsystem_integrated_B.BUS_BCUState_o1 != 0.0);
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = (real32_T)
      ((real_T)(0.27777777777777779 * COMM_subsystem_integrated_B.BUS_BCUState4));
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration =
      COMM_subsystem_integrated_B.BUS_BCUState2_o1;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration =
      COMM_subsystem_integrated_B.BUS_BCUState2_o2;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate =
      COMM_subsystem_integrated_B.BUS_BCUState2_o3;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FL = (real32_T)
      ((real_T)(0.27777777777777779 *
                COMM_subsystem_integrated_B.BUS_BCUState3_o1));
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FR = (real32_T)
      ((real_T)(0.27777777777777779 *
                COMM_subsystem_integrated_B.BUS_BCUState3_o2));
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1 = (real32_T)
      ((real_T)(0.27777777777777779 *
                COMM_subsystem_integrated_B.BUS_BCUState3_o3));
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1 = (real32_T)
      ((real_T)(0.27777777777777779 *
                COMM_subsystem_integrated_B.BUS_BCUState3_o4));

    /* End of Outputs for SubSystem: '<S1>/USdemo New' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S1>/FAW New' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Gain: '<S3>/Gain1' incorporates:
     *  Inport: '<Root>/VsCOMM_FAW_VEH_RX_Data'
     */
    rtb_Gain1_nyrf = (-1.0F) *
      VsCOMM_FAW_VEH_RX_Data.R21.Absolute_Steering_Position;
    COMM_subsystem_in_MedianFilter1(rtb_Gain1_nyrf,
      &COMM_subsystem_integrated_B.MedianFilter1_pnaevvf,
      &COMM_subsystem_integrated_DW.MedianFilter1_pnaevvf);

    /* BusAssignment: '<S3>/Bus Assignment1' incorporates:
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_0'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_1'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_2'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_3'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_4'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_5'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_6'
     *  BusCreator: '<S6>/BusConversion_InsertedFor_Bus Creator16_at_inport_7'
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/Constant10'
     *  Constant: '<S6>/Constant100'
     *  Constant: '<S6>/Constant101'
     *  Constant: '<S6>/Constant102'
     *  Constant: '<S6>/Constant103'
     *  Constant: '<S6>/Constant104'
     *  Constant: '<S6>/Constant105'
     *  Constant: '<S6>/Constant106'
     *  Constant: '<S6>/Constant108'
     *  Constant: '<S6>/Constant109'
     *  Constant: '<S6>/Constant11'
     *  Constant: '<S6>/Constant110'
     *  Constant: '<S6>/Constant112'
     *  Constant: '<S6>/Constant113'
     *  Constant: '<S6>/Constant114'
     *  Constant: '<S6>/Constant115'
     *  Constant: '<S6>/Constant116'
     *  Constant: '<S6>/Constant117'
     *  Constant: '<S6>/Constant118'
     *  Constant: '<S6>/Constant119'
     *  Constant: '<S6>/Constant12'
     *  Constant: '<S6>/Constant120'
     *  Constant: '<S6>/Constant121'
     *  Constant: '<S6>/Constant122'
     *  Constant: '<S6>/Constant123'
     *  Constant: '<S6>/Constant124'
     *  Constant: '<S6>/Constant127'
     *  Constant: '<S6>/Constant129'
     *  Constant: '<S6>/Constant13'
     *  Constant: '<S6>/Constant138'
     *  Constant: '<S6>/Constant139'
     *  Constant: '<S6>/Constant14'
     *  Constant: '<S6>/Constant140'
     *  Constant: '<S6>/Constant141'
     *  Constant: '<S6>/Constant142'
     *  Constant: '<S6>/Constant143'
     *  Constant: '<S6>/Constant144'
     *  Constant: '<S6>/Constant145'
     *  Constant: '<S6>/Constant146'
     *  Constant: '<S6>/Constant147'
     *  Constant: '<S6>/Constant148'
     *  Constant: '<S6>/Constant149'
     *  Constant: '<S6>/Constant15'
     *  Constant: '<S6>/Constant150'
     *  Constant: '<S6>/Constant151'
     *  Constant: '<S6>/Constant152'
     *  Constant: '<S6>/Constant153'
     *  Constant: '<S6>/Constant154'
     *  Constant: '<S6>/Constant155'
     *  Constant: '<S6>/Constant156'
     *  Constant: '<S6>/Constant157'
     *  Constant: '<S6>/Constant158'
     *  Constant: '<S6>/Constant159'
     *  Constant: '<S6>/Constant160'
     *  Constant: '<S6>/Constant162'
     *  Constant: '<S6>/Constant164'
     *  Constant: '<S6>/Constant165'
     *  Constant: '<S6>/Constant166'
     *  Constant: '<S6>/Constant167'
     *  Constant: '<S6>/Constant168'
     *  Constant: '<S6>/Constant169'
     *  Constant: '<S6>/Constant170'
     *  Constant: '<S6>/Constant171'
     *  Constant: '<S6>/Constant172'
     *  Constant: '<S6>/Constant173'
     *  Constant: '<S6>/Constant174'
     *  Constant: '<S6>/Constant175'
     *  Constant: '<S6>/Constant176'
     *  Constant: '<S6>/Constant177'
     *  Constant: '<S6>/Constant178'
     *  Constant: '<S6>/Constant179'
     *  Constant: '<S6>/Constant180'
     *  Constant: '<S6>/Constant181'
     *  Constant: '<S6>/Constant182'
     *  Constant: '<S6>/Constant183'
     *  Constant: '<S6>/Constant184'
     *  Constant: '<S6>/Constant185'
     *  Constant: '<S6>/Constant186'
     *  Constant: '<S6>/Constant2'
     *  Constant: '<S6>/Constant204'
     *  Constant: '<S6>/Constant3'
     *  Constant: '<S6>/Constant4'
     *  Constant: '<S6>/Constant5'
     *  Constant: '<S6>/Constant6'
     *  Constant: '<S6>/Constant7'
     *  Constant: '<S6>/Constant8'
     *  Constant: '<S6>/Constant83'
     *  Constant: '<S6>/Constant84'
     *  Constant: '<S6>/Constant85'
     *  Constant: '<S6>/Constant86'
     *  Constant: '<S6>/Constant87'
     *  Constant: '<S6>/Constant88'
     *  Constant: '<S6>/Constant89'
     *  Constant: '<S6>/Constant9'
     *  Constant: '<S6>/Constant90'
     *  Constant: '<S6>/Constant91'
     *  Constant: '<S6>/Constant92'
     *  Constant: '<S6>/Constant93'
     *  Constant: '<S6>/Constant94'
     *  Constant: '<S6>/Constant95'
     *  Constant: '<S6>/Constant96'
     *  Constant: '<S6>/Constant97'
     *  Constant: '<S6>/Constant98'
     *  Constant: '<S6>/Constant99'
     *  DataTypeConversion: '<S3>/Data Type Conversion3'
     *  DataTypeConversion: '<S3>/Data Type Conversion6'
     *  Inport: '<Root>/VbHWIO_DriverModeComd'
     *  Inport: '<Root>/VsCOMM_FAW_VEH_RX_Data'
     */
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch = true;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips = ((uint16_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwCancel = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwResume = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwSet = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapPlus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapMinus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwLimitMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriveMode = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBelt = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBeltValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_TurningLightEcho = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LowBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_HighBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_PassengerDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearRightDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearLeftDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_FrontHoodStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BackTrunkStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_WiperSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_ControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_TCSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_ABSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeAirTankPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_BrakePedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_TargetBrakePedalEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPress = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPressValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_AutoholdStatus = true;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ParkingControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SwitchStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_StartStopStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeedValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalOverride = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineState = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CoolantLevelLow = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowerControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_DriverDemandTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_ActualEngineTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineOilPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineCoolantTemperature = 0;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CatalystTankLevel = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_TargetAccelPedalPostionEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowertrainFaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_BatterySOC = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorActualTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_EngineTorqueLoss = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorqueValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LDW = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringModeEcho = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_TargetSteeringAngleEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringAngleRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_FaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOffWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOnWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_TargetGearPositionEcho =
      ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ShiftLevelPosition = ((uint8_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition = ((uint8_T)
      20U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearRatio = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRateValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FR = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FL = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FRValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FLValid = true;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RL = 1U;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RR = 1U;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch =
      VbHWIO_DriverModeComd;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus =
      (((int32_T)VsCOMM_FAW_VEH_RX_Data.R01.VCU_Mode) != 0);
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_BrakePedalValid = (((int32_T)
      VsCOMM_FAW_VEH_RX_Data.R01.Manual_Brake_Switch) != 0);
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition =
      VsCOMM_FAW_VEH_RX_Data.R01.Manual_Accelerator_Pedal;

    /* If: '<S3>/If' incorporates:
     *  Inport: '<Root>/VsCOMM_FAW_VEH_RX_Data'
     */
    if (VsCOMM_FAW_VEH_RX_Data.R10.Current_Gear < 0)
    {
      /* Outputs for IfAction SubSystem: '<S3>/Reverse' incorporates:
       *  ActionPort: '<S22>/Action Port'
       */
      /* BusAssignment: '<S3>/Bus Assignment1' incorporates:
       *  Constant: '<S22>/Constant'
       *  SignalConversion: '<S22>/OutportBufferForOut1'
       */
      VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition =
        ((uint8_T)13U);

      /* End of Outputs for SubSystem: '<S3>/Reverse' */
    }
    else if (VsCOMM_FAW_VEH_RX_Data.R10.Current_Gear == 0)
    {
      /* Outputs for IfAction SubSystem: '<S3>/Neutral' incorporates:
       *  ActionPort: '<S20>/Action Port'
       */
      /* BusAssignment: '<S3>/Bus Assignment1' incorporates:
       *  Constant: '<S20>/Constant'
       *  SignalConversion: '<S20>/OutportBufferForOut1'
       */
      VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition =
        ((uint8_T)0U);

      /* End of Outputs for SubSystem: '<S3>/Neutral' */
    }
    else if (VsCOMM_FAW_VEH_RX_Data.R10.Current_Gear == 126)
    {
      /* Outputs for IfAction SubSystem: '<S3>/Park' incorporates:
       *  ActionPort: '<S21>/Action Port'
       */
      /* BusAssignment: '<S3>/Bus Assignment1' incorporates:
       *  Constant: '<S21>/Constant'
       *  SignalConversion: '<S21>/OutportBufferForOut1'
       */
      VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition =
        ((uint8_T)14U);

      /* End of Outputs for SubSystem: '<S3>/Park' */
    }
    else
    {
      /* Outputs for IfAction SubSystem: '<S3>/Drive' incorporates:
       *  ActionPort: '<S19>/Action Port'
       */
      /* BusAssignment: '<S3>/Bus Assignment1' incorporates:
       *  Constant: '<S19>/Constant'
       *  SignalConversion: '<S19>/OutportBufferForOut1'
       */
      VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition =
        ((uint8_T)1U);

      /* End of Outputs for SubSystem: '<S3>/Drive' */
    }

    /* End of If: '<S3>/If' */

    /* BusAssignment: '<S3>/Bus Assignment1' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion10'
     *  DataTypeConversion: '<S3>/Data Type Conversion11'
     *  DataTypeConversion: '<S3>/Data Type Conversion12'
     *  DataTypeConversion: '<S3>/Data Type Conversion4'
     *  DataTypeConversion: '<S3>/Data Type Conversion7'
     *  DataTypeConversion: '<S3>/Data Type Conversion8'
     *  DataTypeConversion: '<S3>/Data Type Conversion9'
     *  Gain: '<S3>/Gain = 1//3.6_5'
     *  Gain: '<S3>/Gain = 1//3.6_6'
     *  Gain: '<S3>/Gain = 1//3.6_7'
     *  Gain: '<S3>/Gain = 1//3.6_8'
     *  Gain: '<S3>/Gain = 1//3.6_9'
     *  Inport: '<Root>/VsCOMM_FAW_VEH_RX_Data'
     */
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = 0.277777791F *
      VsCOMM_FAW_VEH_RX_Data.R14.Wheel_based_vehicle_speed;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate =
      VsCOMM_FAW_VEH_RX_Data.R19.Yaw_Rate;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration =
      VsCOMM_FAW_VEH_RX_Data.R19.Longitudinal_Acceleration;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle =
      COMM_subsystem_integrated_B.MedianFilter1_pnaevvf.MedianFilter1;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC =
      (((int32_T)VsCOMM_FAW_VEH_RX_Data.R21.Actual_Mode) != 0);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque =
      VsCOMM_FAW_VEH_RX_Data.R20.Column_Torque;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus =
      VsCOMM_FAW_VEH_RX_Data.R14.Parking_Brake_Switch;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus = (((int32_T)
      VsCOMM_FAW_VEH_RX_Data.R29.Rear_brake_lamp_status) != 0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState = (((int32_T)
      VsCOMM_FAW_VEH_RX_Data.R28.Left_turnning_light_state) != 0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState = (((int32_T)
      VsCOMM_FAW_VEH_RX_Data.R28.Right_turnning_light_state) != 0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LowBeamSwitch = (((int32_T)
      VsCOMM_FAW_VEH_RX_Data.R28.Low_beam_light_state) != 0);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_HighBeamSwitch = (((int32_T)
      VsCOMM_FAW_VEH_RX_Data.R28.High_beam_light_state) != 0);
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition =
      VsCOMM_FAW_VEH_RX_Data.R16.Brake_Pedal_Position;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FL = 0.277777791F
      * VsCOMM_FAW_VEH_RX_Data.R17.Relative_Speed_FA_Leftwheel;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FR = 0.277777791F
      * VsCOMM_FAW_VEH_RX_Data.R17.Relative_Speed_RA_RightWheel;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1 =
      0.277777791F * VsCOMM_FAW_VEH_RX_Data.R17.Relative_Speed_RA1_Leftwheel;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1 =
      0.277777791F * VsCOMM_FAW_VEH_RX_Data.R17.Relative_Speed_RA1_Rightwheel;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState =
      VsCOMM_FAW_VEH_RX_Data.R20.Ignition_State;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOffWheelDetected =
      VsCOMM_FAW_VEH_RX_Data.R20.Hands_off_Detected;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOnWheelDetected =
      VsCOMM_FAW_VEH_RX_Data.R20.Hands_on_Detcted;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips =
      VsCOMM_FAW_VEH_RX_Data.R01.Auto_To_Manual_Tips;
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearRatio =
      VsCOMM_FAW_VEH_RX_Data.R10.Actual_Gear_Ratio;

    /* End of Outputs for SubSystem: '<S1>/FAW New' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/demo New' incorporates:
     *  ActionPort: '<S16>/Action Port'
     */
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch = true;
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips = ((uint16_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwCancel = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwResume = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwSet = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapPlus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapMinus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwLimitMain = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriveMode = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBelt = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBeltValid = true;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_TurningLightEcho = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LowBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_HighBeamSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_PassengerDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearRightDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearLeftDoorStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_FrontHoodStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BackTrunkStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_WiperSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_ControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_TCSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_ABSActive = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeAirTankPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_BrakePedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_TargetBrakePedalEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPress = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPressValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_AutoholdStatus = true;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SystemFaultStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ParkingControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SwitchStatus = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_StartStopStatus = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeedValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalOverride = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineState = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CoolantLevelLow = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowerControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_DriverDemandTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_ActualEngineTorque = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineOilPressure = ((uint16_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineCoolantTemperature = 0;
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CatalystTankLevel = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_TargetAccelPedalPostionEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowertrainFaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_BatterySOC = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorActualTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_EngineTorqueLoss = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorqueValid = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LDW = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringModeEcho = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_TargetSteeringAngleEcho = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringAngleRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_FaultLevel = ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOffWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOnWheelDetected = false;
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_TargetGearPositionEcho =
      ((uint8_T)0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ShiftLevelPosition = ((uint8_T)
      0U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition = ((uint8_T)
      20U);
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearRatio = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRateValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAccelerationValid =
      false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2 = 0.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FR = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FL = 1.0F;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2Valid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FRValid = false;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FLValid = true;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RL = 1U;
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RR = 1U;

    /* End of Outputs for SubSystem: '<S1>/demo New' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case2' */

  /* SignalConversion: '<S1>/Signal Conversion133' */
  VeCOMM_TCU_TargetGearPositionEcho =
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_TargetGearPositionEcho;

  /* SignalConversion: '<S1>/Signal Conversion134' */
  VeCOMM_TCU_ShiftLevelPosition =
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ShiftLevelPosition;

  /* SignalConversion: '<S1>/Signal Conversion135' */
  VeCOMM_TCU_ActualGearPosition =
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition;

  /* SignalConversion: '<S1>/Signal Conversion136' */
  VfCOMM_TCU_ActualGearRatio =
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearRatio;

  /* SignalConversion: '<S1>/Signal Conversion137' */
  VbCOMM_VDC_YawRateValid =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRateValid;

  /* SignalConversion: '<S1>/Signal Conversion138' */
  VbCOMM_VDC_LongAccelerationValid =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAccelerationValid;

  /* SignalConversion: '<S1>/Signal Conversion139' */
  VbCOMM_EPS_SteeringWheelTorqueValid =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorqueValid;

  /* SignalConversion: '<S1>/Signal Conversion140' */
  VbCOMM_VDC_LateralAccelerationValid =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAccelerationValid;

  /* SignalConversion: '<S1>/Signal Conversion141' */
  VfCOMM_VDC_YawRate = VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_YawRate;

  /* SignalConversion: '<S1>/Signal Conversion142' */
  VfCOMM_VDC_VehicleSpeed =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;

  /* SignalConversion: '<S1>/Signal Conversion143' */
  VfCOMM_VDC_WheelSpeed_RR1 =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1;

  /* SignalConversion: '<S1>/Signal Conversion144' */
  VfCOMM_VDC_LongAcceleration =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LongAcceleration;

  /* SignalConversion: '<S1>/Signal Conversion145' */
  VfCOMM_VDC_LateralAcceleration =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_LateralAcceleration;

  /* SignalConversion: '<S1>/Signal Conversion146' */
  VfCOMM_VDC_WheelSpeed_RR2 =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2;

  /* SignalConversion: '<S1>/Signal Conversion147' */
  VfCOMM_VDC_WheelSpeed_RL1 =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1;

  /* SignalConversion: '<S1>/Signal Conversion148' */
  VfCOMM_VDC_WheelSpeed_RL2 =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2;

  /* SignalConversion: '<S1>/Signal Conversion149' */
  VbCOMM_EPS_SteeringControlResponse_LDW =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LDW;

  /* SignalConversion: '<S1>/Signal Conversion150' */
  VbCOMM_EPS_SteeringControlResponse_LCC =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringControlResponse_LCC;

  /* SignalConversion: '<S1>/Signal Conversion151' */
  VeCOMM_EPS_SteeringModeEcho =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringModeEcho;

  /* SignalConversion: '<S1>/Signal Conversion153' */
  VfCOMM_EPS_TargetSteeringAngleEcho =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_TargetSteeringAngleEcho;

  /* SignalConversion: '<S1>/Signal Conversion154' */
  VfCOMM_EPS_ActualSteeringAngle =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle;

  /* SignalConversion: '<S1>/Signal Conversion155' */
  VfCOMM_EPS_SteeringAngleRate =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringAngleRate;

  /* SignalConversion: '<S1>/Signal Conversion156' */
  VfCOMM_VDC_WheelSpeed_FR =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FR;

  /* SignalConversion: '<S1>/Signal Conversion157' */
  VfCOMM_VDC_WheelSpeed_FL =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FL;

  /* SignalConversion: '<S1>/Signal Conversion158' */
  VbCOMM_VDC_WheelSpeed_RR1Valid =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR1Valid;

  /* SignalConversion: '<S1>/Signal Conversion159' */
  VbCOMM_VDC_WheelSpeed_RR2Valid =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RR2Valid;

  /* SignalConversion: '<S1>/Signal Conversion160' */
  VbCOMM_VDC_WheelSpeed_RL1Valid =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL1Valid;

  /* SignalConversion: '<S1>/Signal Conversion161' */
  VbCOMM_VDC_WheelSpeed_FLValid =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FLValid;

  /* SignalConversion: '<S1>/Signal Conversion162' */
  VbCOMM_VDC_WheelSpeed_RL2Valid =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_RL2Valid;

  /* SignalConversion: '<S1>/Signal Conversion163' */
  VbCOMM_VDC_WheelSpeed_FRValid =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelSpeed_FRValid;

  /* SignalConversion: '<S1>/Signal Conversion164' */
  VfCOMM_VDC_WheelEncoderCounter_RL =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RL;

  /* SignalConversion: '<S1>/Signal Conversion165' */
  VfCOMM_VDC_WheelEncoderCounter_RR =
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_WheelEncoderCounter_RR;

  /* SignalConversion: '<S1>/Signal Conversion203' */
  VeCOMM_EMS_StartStopStatus =
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_StartStopStatus;

  /* SignalConversion: '<S1>/Signal Conversion204' */
  VbCOMM_EMS_EngineSpeedValid =
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeedValid;

  /* SignalConversion: '<S1>/Signal Conversion205' */
  VfCOMM_VCU_VirtualAccelPedalPosition =
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalPosition;

  /* SignalConversion: '<S1>/Signal Conversion206' */
  VbCOMM_VCU_VirtualAccelPedalValid =
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_VirtualAccelPedalValid;

  /* SignalConversion: '<S1>/Signal Conversion208' */
  VbCOMM_VCU_AccelPedalOverride =
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalOverride;

  /* SignalConversion: '<S1>/Signal Conversion209' */
  VeCOMM_EMS_EngineState = VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineState;

  /* SignalConversion: '<S1>/Signal Conversion210' */
  VfCOMM_EMS_EngineSpeed = VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineSpeed;

  /* SignalConversion: '<S1>/Signal Conversion211' */
  VfCOMM_PCU_DriverDemandTorque =
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_DriverDemandTorque;

  /* SignalConversion: '<S1>/Signal Conversion212' */
  VbCOMM_EMS_CoolantLevelLow =
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CoolantLevelLow;

  /* SignalConversion: '<S1>/Signal Conversion213' */
  VbCOMM_PCU_PowerControlResponse =
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowerControlResponse;

  /* SignalConversion: '<S1>/Signal Conversion214' */
  VfCOMM_PCU_ActualEngineTorque =
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_ActualEngineTorque;

  /* SignalConversion: '<S1>/Signal Conversion215' */
  VfCOMM_EMS_EngineOilPressure =
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineOilPressure;

  /* SignalConversion: '<S1>/Signal Conversion216' */
  VfCOMM_EMS_EngineCoolantTemperature =
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_EngineCoolantTemperature;

  /* SignalConversion: '<S1>/Signal Conversion224' */
  VfCOMM_EMS_CatalystTankLevel =
    VsCOMM_CANR_Databus.COMM_RX_Power.EMS_CatalystTankLevel;

  /* SignalConversion: '<S1>/Signal Conversion225' */
  VfCOMM_VCU_ActualAccelPedalPosition =
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_ActualAccelPedalPosition;

  /* SignalConversion: '<S1>/Signal Conversion226' */
  VbCOMM_VCU_AccelPedalValid =
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_AccelPedalValid;

  /* SignalConversion: '<S1>/Signal Conversion227' */
  VfCOMM_VCU_TargetAccelPedalPostionEcho =
    VsCOMM_CANR_Databus.COMM_RX_Power.VCU_TargetAccelPedalPostionEcho;

  /* SignalConversion: '<S1>/Signal Conversion228' */
  VeCOMM_PCU_PowertrainFaultLevel =
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_PowertrainFaultLevel;

  /* SignalConversion: '<S1>/Signal Conversion229' */
  VfCOMM_PCU_BatterySOC = VsCOMM_CANR_Databus.COMM_RX_Power.PCU_BatterySOC;

  /* SignalConversion: '<S1>/Signal Conversion230' */
  VfCOMM_PCU_MotorSpeed = VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorSpeed;

  /* SignalConversion: '<S1>/Signal Conversion231' */
  VfCOMM_PCU_MotorActualTorque =
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_MotorActualTorque;

  /* SignalConversion: '<S1>/Signal Conversion232' */
  VfCOMM_PCU_EngineTorqueLoss =
    VsCOMM_CANR_Databus.COMM_RX_Power.PCU_EngineTorqueLoss;

  /* SignalConversion: '<S1>/Signal Conversion233' */
  VeCOMM_EPS_FaultLevel = VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_FaultLevel;

  /* SignalConversion: '<S1>/Signal Conversion234' */
  VfCOMM_EPS_SteeringWheelTorque =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_SteeringWheelTorque;

  /* SignalConversion: '<S1>/Signal Conversion235' */
  VbCOMM_EPS_HandsOnWheelDetected =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOnWheelDetected;

  /* SignalConversion: '<S1>/Signal Conversion236' */
  VbCOMM_EPS_HandsOffWheelDetected =
    VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_HandsOffWheelDetected;

  /* SignalConversion: '<S1>/Signal Conversion29' */
  VbCOMM_VCU_AutodriveMainSwitch =
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveMainSwitch;

  /* SignalConversion: '<S1>/Signal Conversion30' */
  VeCOMM_VCU_AutoToManualTips =
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutoToManualTips;

  /* SignalConversion: '<S1>/Signal Conversion31' */
  VbCOMM_BCM_CruiseSwLimitMain =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwLimitMain;

  /* SignalConversion: '<S1>/Signal Conversion32' */
  VbCOMM_BCM_DriverSeatBelt = VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBelt;

  /* SignalConversion: '<S1>/Signal Conversion33' */
  VeCOMM_BCM_CruiseControlStatus =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseControlStatus;

  /* SignalConversion: '<S1>/Signal Conversion34' */
  VbCOMM_BCM_DriverSeatBeltValid =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverSeatBeltValid;

  /* SignalConversion: '<S1>/Signal Conversion35' */
  VbCOMM_BCM_TurningLightEcho =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_TurningLightEcho;

  /* SignalConversion: '<S1>/Signal Conversion36' */
  VbCOMM_BCM_LowBeamSwitch = VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LowBeamSwitch;

  /* SignalConversion: '<S1>/Signal Conversion37' */
  VbCOMM_BCM_HighBeamSwitch = VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_HighBeamSwitch;

  /* SignalConversion: '<S1>/Signal Conversion38' */
  VbCOMM_BCM_BrakeLightStatus =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BrakeLightStatus;

  /* SignalConversion: '<S1>/Signal Conversion39' */
  VbCOMM_BCM_LeftTurningLightState =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState;

  /* SignalConversion: '<S1>/Signal Conversion40' */
  VbCOMM_BCM_RightTurningLightState =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState;

  /* SignalConversion: '<S1>/Signal Conversion41' */
  VbCOMM_VCU_AutodriveActiveStatus =
    VsCOMM_CANR_Databus.COMM_RX_AutodriveMode.VCU_AutodriveActiveStatus;

  /* SignalConversion: '<S1>/Signal Conversion42' */
  VbCOMM_BCM_IgnitionKeyState =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_IgnitionKeyState;

  /* SignalConversion: '<S1>/Signal Conversion43' */
  VbCOMM_BCM_DriverDoorStatus =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriverDoorStatus;

  /* SignalConversion: '<S1>/Signal Conversion44' */
  VbCOMM_BCM_PassengerDoorStatus =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_PassengerDoorStatus;

  /* SignalConversion: '<S1>/Signal Conversion45' */
  VbCOMM_BCM_FrontHoodStatus =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_FrontHoodStatus;

  /* SignalConversion: '<S1>/Signal Conversion46' */
  VbCOMM_BCM_RearRightDoorStatus =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearRightDoorStatus;

  /* SignalConversion: '<S1>/Signal Conversion47' */
  VbCOMM_BCM_RearLeftDoorStatus =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RearLeftDoorStatus;

  /* SignalConversion: '<S1>/Signal Conversion48' */
  VbCOMM_BCM_BackTrunkStatus =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_BackTrunkStatus;

  /* SignalConversion: '<S1>/Signal Conversion49' */
  VbCOMM_BCM_WiperSwitch = VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_WiperSwitch;

  /* SignalConversion: '<S1>/Signal Conversion50' */
  VbCOMM_BCM_ControlResponse =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_ControlResponse;

  /* SignalConversion: '<S1>/Signal Conversion51' */
  VbCOMM_BCM_CruiseSwValid = VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwValid;

  /* SignalConversion: '<S1>/Signal Conversion52' */
  VbCOMM_BCM_CruiseSwResume = VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwResume;

  /* SignalConversion: '<S1>/Signal Conversion53' */
  VbCOMM_BCM_CruiseSwSet = VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwSet;

  /* SignalConversion: '<S1>/Signal Conversion54' */
  VbCOMM_BCM_CruiseSwTimeGapPlus =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapPlus;

  /* SignalConversion: '<S1>/Signal Conversion55' */
  VbCOMM_BCM_CruiseSwTimeGapMinus =
    VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwTimeGapMinus;

  /* SignalConversion: '<S1>/Signal Conversion56' */
  VbCOMM_BCM_CruiseSwMain = VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_CruiseSwMain;

  /* SignalConversion: '<S1>/Signal Conversion57' */
  VeCOMM_BCM_DriveMode = VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_DriveMode;

  /* SignalConversion: '<S1>/Signal Conversion58' */
  VbCOMM_ESP_TCSActive = VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_TCSActive;

  /* SignalConversion: '<S1>/Signal Conversion59' */
  VbCOMM_ESP_ABSActive = VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_ABSActive;

  /* SignalConversion: '<S1>/Signal Conversion60' */
  VeCOMM_ESP_SystemFaultStatus =
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_SystemFaultStatus;

  /* SignalConversion: '<S1>/Signal Conversion61' */
  VbCOMM_EPB_AutoholdStatus =
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_AutoholdStatus;

  /* SignalConversion: '<S1>/Signal Conversion62' */
  VeCOMM_EPB_SystemFaultStatus =
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SystemFaultStatus;

  /* SignalConversion: '<S1>/Signal Conversion63' */
  VeCOMM_EPB_ActualControlStatus =
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ActualControlStatus;

  /* SignalConversion: '<S1>/Signal Conversion64' */
  VbCOMM_EPB_ParkingControlResponse =
    VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_ParkingControlResponse;

  /* SignalConversion: '<S1>/Signal Conversion65' */
  VbCOMM_EPB_SwitchStatus = VsCOMM_CANR_Databus.COMM_RX_Parking.EPB_SwitchStatus;

  /* SignalConversion: '<S1>/Signal Conversion70' */
  VfCOMM_ESP_BrakeAirTankPressure =
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeAirTankPressure;

  /* SignalConversion: '<S1>/Signal Conversion80' */
  VbCOMM_VCU_BrakePedalValid =
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_BrakePedalValid;

  /* SignalConversion: '<S1>/Signal Conversion81' */
  VbCOMM_ESP_BrakeControlResponse =
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_BrakeControlResponse;

  /* SignalConversion: '<S1>/Signal Conversion82' */
  VfCOMM_VCU_TargetBrakePedalEcho =
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_TargetBrakePedalEcho;

  /* SignalConversion: '<S1>/Signal Conversion83' */
  VfCOMM_VCU_ActualBrakePedalPosition =
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalPosition;

  /* SignalConversion: '<S1>/Signal Conversion84' */
  VbCOMM_VCU_ActualBrakePedalSwitch =
    VsCOMM_CANR_Databus.COMM_RX_Brake.VCU_ActualBrakePedalSwitch;

  /* SignalConversion: '<S1>/Signal Conversion85' */
  VfCOMM_ESP_MasterCylinderPress =
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPress;

  /* SignalConversion: '<S1>/Signal Conversion86' */
  VbCOMM_ESP_MasterCylinderPressValid =
    VsCOMM_CANR_Databus.COMM_RX_Brake.ESP_MasterCylinderPressValid;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
