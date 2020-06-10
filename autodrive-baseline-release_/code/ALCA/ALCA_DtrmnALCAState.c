/*
 * File: ALCA_DtrmnALCAState.c
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

#include "ALCA_DtrmnALCAState.h"

/* Include model header file for global data */
#include "ALCA_subsystem_integrated.h"
#include "ALCA_subsystem_integrated_private.h"

/* Named constants for Chart: '<S10>/ALCA_StateFlow' */
#define ALCA_su_IN_NO_ACTIVE_CHILD_a5x0 ((uint8_T)0U)
#define ALCA_subsystem_int_IN_Activated ((uint8_T)2U)
#define ALCA_subsystem_inte_IN_Handover ((uint8_T)4U)
#define ALCA_subsystem_integ_IN_Standby ((uint8_T)5U)
#define ALCA_subsystem_integ_IN_Waiting ((uint8_T)6U)
#define ALCA_subsystem_integr_IN_Finish ((uint8_T)3U)
#define ALCA_subsystem_integra_IN_Abort ((uint8_T)1U)
#define ALCA_subsystem_integrate_IN_OFF ((uint8_T)1U)
#define ALCA_subsystem_integrated_IN_ON ((uint8_T)2U)

/* Forward declaration for local functions */
static void ALCA_subsystem_integrated_ON(const boolean_T *LogicalOperator, const
  boolean_T *LogicalOperator1, const ALCA_DcsnInfo *rtu_dcsn_info, boolean_T
  rtu_lc_accept, EnumALCA_interrupt_type rtu_interrupt_type, EnumALCA_state
  *rty_alca_state, boolean_T *rty_reset_change_lane_req, uint8_T
  *rty_interrupt_action);

/* Function for Chart: '<S10>/ALCA_StateFlow' */
static void ALCA_subsystem_integrated_ON(const boolean_T *LogicalOperator, const
  boolean_T *LogicalOperator1, const ALCA_DcsnInfo *rtu_dcsn_info, boolean_T
  rtu_lc_accept, EnumALCA_interrupt_type rtu_interrupt_type, EnumALCA_state
  *rty_alca_state, boolean_T *rty_reset_change_lane_req, uint8_T
  *rty_interrupt_action)
{
  /* Chart: '<S10>/ALCA_StateFlow' incorporates:
   *  Constant: '<S10>/Constant4'
   */
  if (!rtu_dcsn_info->alca_enable)
  {
    ALCA_subsystem_integrated_DW.is_ON = ALCA_su_IN_NO_ACTIVE_CHILD_a5x0;
    ALCA_subsystem_integrated_DW.is_c1_ALCA_subsystem_integrated =
      ALCA_subsystem_integrate_IN_OFF;
    *rty_alca_state = ALCA_state_OFF;
  }
  else
  {
    switch (ALCA_subsystem_integrated_DW.is_ON)
    {
     case ALCA_subsystem_integra_IN_Abort:
      if (VbALCA_LC_Complete)
      {
        *rty_reset_change_lane_req = true;
        ALCA_subsystem_integrated_DW.is_ON = ALCA_subsystem_integr_IN_Finish;
        ALCA_subsystem_integrated_DW.time_wait = 0.0F;
        *rty_alca_state = ALCA_state_Finish;
      }
      else
      {
        *rty_alca_state = ALCA_state_Abort;
      }
      break;

     case ALCA_subsystem_int_IN_Activated:
      if (VbALCA_LC_Complete)
      {
        *rty_reset_change_lane_req = true;
        ALCA_subsystem_integrated_DW.is_ON = ALCA_subsystem_integr_IN_Finish;
        ALCA_subsystem_integrated_DW.time_wait = 0.0F;
        *rty_alca_state = ALCA_state_Finish;
      }
      else if (KbALCA_EnblInterrupt && (((int32_T)(*rty_interrupt_action)) == 3))
      {
        ALCA_subsystem_integrated_DW.is_ON = ALCA_subsystem_inte_IN_Handover;
        *rty_alca_state = ALCA_state_Handover;
        ALCA_subsystem_integrated_DW.time_wait = 0.0F;
      }
      else if (KbALCA_EnblInterrupt && (((int32_T)(*rty_interrupt_action)) == 1))
      {
        ALCA_subsystem_integrated_DW.is_ON = ALCA_subsystem_integra_IN_Abort;
        *rty_alca_state = ALCA_state_Abort;
      }
      else if ((KbALCA_EnblInterrupt && (((int32_T)(*rty_interrupt_action)) == 2))
               || ((!KbALCA_EnblInterrupt) &&
                   ((rtu_dcsn_info->change_lane_cancel) || (!rtu_lc_accept))))
      {
        *rty_reset_change_lane_req = true;
        ALCA_subsystem_integrated_DW.is_ON = ALCA_subsystem_integ_IN_Standby;
        *rty_alca_state = ALCA_state_Standby;
      }
      else
      {
        *rty_alca_state = ALCA_state_Activated;
      }
      break;

     case ALCA_subsystem_integr_IN_Finish:
      if ((ALCA_subsystem_integrated_DW.time_wait > KfALCA_t_ExitFinishDelay) ||
          (rtu_dcsn_info->change_lane_cancel))
      {
        *rty_reset_change_lane_req = true;
        ALCA_subsystem_integrated_DW.is_ON = ALCA_subsystem_integ_IN_Standby;
        *rty_alca_state = ALCA_state_Standby;
      }
      else
      {
        *rty_alca_state = ALCA_state_Finish;
        ALCA_subsystem_integrated_DW.time_wait += KfALCA_t_PeriodFunctionCall;
      }
      break;

     case ALCA_subsystem_inte_IN_Handover:
      if (((((rtu_dcsn_info->change_lane_cancel) && (((uint32_T)
               rtu_interrupt_type) != ALCA_interrupt_type_driver_cancel)) ||
            (false)) || VbALCA_LC_Complete) ||
          (ALCA_subsystem_integrated_DW.time_wait > KfALCA_t_ExitHandoverDelay))
      {
        *rty_reset_change_lane_req = true;
        ALCA_subsystem_integrated_DW.is_ON = ALCA_subsystem_integ_IN_Standby;
        *rty_alca_state = ALCA_state_Standby;
      }
      else
      {
        *rty_alca_state = ALCA_state_Handover;
        ALCA_subsystem_integrated_DW.time_wait += KfALCA_t_PeriodFunctionCall;
        if (rtu_lc_accept || (((int32_T)(*rty_interrupt_action)) == 0))
        {
          ALCA_subsystem_integrated_DW.time_wait = 0.0F;
        }
      }
      break;

     case ALCA_subsystem_integ_IN_Standby:
      if (rtu_lc_accept)
      {
        ALCA_subsystem_integrated_DW.is_ON = ALCA_subsystem_int_IN_Activated;
        *rty_alca_state = ALCA_state_Activated;
      }
      else if ((rtu_dcsn_info->change_lane_req) && (*LogicalOperator1))
      {
        ALCA_subsystem_integrated_DW.is_ON = ALCA_subsystem_integ_IN_Waiting;
        *rty_alca_state = ALCA_state_Waiting;
        ALCA_subsystem_integrated_DW.time_wait = 0.0F;
      }
      else
      {
        *rty_reset_change_lane_req = false;
        *rty_alca_state = ALCA_state_Standby;
        if ((rtu_dcsn_info->change_lane_req) && (*LogicalOperator))
        {
          *rty_reset_change_lane_req = true;
        }
      }
      break;

     default:
      if ((ALCA_subsystem_integrated_DW.time_wait > KfALCA_t_ExitWaitingDelay) ||
          (rtu_dcsn_info->change_lane_cancel))
      {
        *rty_reset_change_lane_req = true;
        ALCA_subsystem_integrated_DW.is_ON = ALCA_subsystem_integ_IN_Standby;
        *rty_alca_state = ALCA_state_Standby;
      }
      else if (rtu_lc_accept)
      {
        ALCA_subsystem_integrated_DW.is_ON = ALCA_subsystem_int_IN_Activated;
        *rty_alca_state = ALCA_state_Activated;
      }
      else
      {
        *rty_alca_state = ALCA_state_Waiting;
        ALCA_subsystem_integrated_DW.time_wait += KfALCA_t_PeriodFunctionCall;
      }
      break;
    }
  }

  /* End of Chart: '<S10>/ALCA_StateFlow' */
}

/* System initialize for atomic system: '<S3>/ALCA_DtrmnALCAState' */
void ALCA_s_ALCA_DtrmnALCAState_Init(void)
{
  /* SystemInitialize for Chart: '<S10>/ALCA_StateFlow' */
  ALCA_subsystem_integrated_DW.is_ON = ALCA_su_IN_NO_ACTIVE_CHILD_a5x0;
  ALCA_subsystem_integrated_DW.is_active_c1_ALCA_subsystem_int = 0U;
  ALCA_subsystem_integrated_DW.is_c1_ALCA_subsystem_integrated =
    ALCA_su_IN_NO_ACTIVE_CHILD_a5x0;
}

/* System reset for atomic system: '<S3>/ALCA_DtrmnALCAState' */
void ALCA__ALCA_DtrmnALCAState_Reset(void)
{
  /* SystemReset for Chart: '<S10>/ALCA_StateFlow' */
  ALCA_subsystem_integrated_DW.is_ON = ALCA_su_IN_NO_ACTIVE_CHILD_a5x0;
  ALCA_subsystem_integrated_DW.is_active_c1_ALCA_subsystem_int = 0U;
  ALCA_subsystem_integrated_DW.is_c1_ALCA_subsystem_integrated =
    ALCA_su_IN_NO_ACTIVE_CHILD_a5x0;
}

/* Start for atomic system: '<S3>/ALCA_DtrmnALCAState' */
void ALCA__ALCA_DtrmnALCAState_Start(void)
{
  /* Start for DataStoreMemory: '<S10>/KbALCA_EnblInterrupt' */
  ALCA_subsystem_integrated_DW.KbALCA_EnblInterrupt_hmoa = KbALCA_EnblInterrupt;
}

/* Output and update for atomic system: '<S3>/ALCA_DtrmnALCAState' */
void ALCA_subsys_ALCA_DtrmnALCAState(const ALCA_DcsnInfo *rtu_dcsn_info,
  boolean_T rtu_lc_accept, EnumALCA_not_fulfill_reason
  rtu_odd_not_fulfill_reason, boolean_T rtu_touched_new_lane, boolean_T
  rtu_interrupt, EnumALCA_interrupt_type rtu_interrupt_type, const ALCA_VehState
  *rtu_veh_state, const ALCA_MPFU_Info *rtu_mpfu_info, boolean_T
  *rty_alca_request, EnumALCA_state *rty_alca_state, boolean_T
  *rty_reset_change_lane_req, uint8_T *rty_interrupt_action)
{
  boolean_T LogicalOperator;
  boolean_T LogicalOperator1;

  /* DataStoreWrite: '<S37>/MemStoreWrite_AgDataAndADataDlyInSnsrFusn11' incorporates:
   *  Constant: '<S37>/Constant11'
   */
  ALCA_subsystem_integrated_DW.KbALCA_EnblInterrupt_hmoa = KbALCA_EnblInterrupt;

  /* MATLAB Function: '<S10>/ALCA_Dtrmn_interrupt_action' incorporates:
   *  Constant: '<S10>/Constant10'
   *  Constant: '<S10>/Constant6'
   *  Constant: '<S10>/Constant7'
   *  Constant: '<S10>/Constant9'
   */
  ALC_ALCA_Dtrmn_interrupt_action(rtu_touched_new_lane, rtu_interrupt,
    rtu_mpfu_info, rtu_veh_state, rtu_interrupt_type,
    KaALCA_AXIS_RelativeSpeedHost2Obstacle, KaALCA_AXIS_VehSpeed,
    KtALCA_d_RangeFrontOfCheckObstacle, KtALCA_d_RangeRearOfCheckObstacle,
    rty_interrupt_action);

  /* Logic: '<S35>/Logical Operator' incorporates:
   *  Constant: '<S39>/Constant'
   *  Constant: '<S40>/Constant'
   *  Constant: '<S41>/Constant'
   *  Constant: '<S44>/Constant'
   *  Constant: '<S45>/Constant'
   *  RelationalOperator: '<S35>/Relational Operator1'
   *  RelationalOperator: '<S35>/Relational Operator2'
   *  RelationalOperator: '<S35>/Relational Operator3'
   *  RelationalOperator: '<S35>/Relational Operator4'
   *  RelationalOperator: '<S35>/Relational Operator5'
   */
  LogicalOperator = (((((rtu_odd_not_fulfill_reason ==
    ALCA_not_fulfill_reason_no_lane) || (rtu_odd_not_fulfill_reason ==
    ALCA_not_fulfill_reason_mpfu_reject)) || (rtu_odd_not_fulfill_reason ==
    ALCA_not_fulfill_reason_dangerous_conditions)) ||
                      (rtu_odd_not_fulfill_reason ==
                       ALCA_not_fulfill_reason_system_error)) ||
                     (rtu_odd_not_fulfill_reason ==
                      ALCA_not_fulfill_reason_too_often));

  /* Logic: '<S35>/Logical Operator1' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant'
   *  Constant: '<S46>/Constant'
   *  RelationalOperator: '<S35>/Relational Operator7'
   *  RelationalOperator: '<S35>/Relational Operator8'
   *  RelationalOperator: '<S35>/Relational Operator9'
   */
  LogicalOperator1 = (((rtu_odd_not_fulfill_reason ==
                        ALCA_not_fulfill_reason_has_obstacle) ||
                       (rtu_odd_not_fulfill_reason ==
                        ALCA_not_fulfill_reason_low_speed)) ||
                      (rtu_odd_not_fulfill_reason ==
                       ALCA_not_fulfill_reason_high_speed));

  /* Chart: '<S10>/ALCA_StateFlow' */
  if (((uint32_T)ALCA_subsystem_integrated_DW.is_active_c1_ALCA_subsystem_int) ==
      0U)
  {
    ALCA_subsystem_integrated_DW.is_active_c1_ALCA_subsystem_int = 1U;
    ALCA_subsystem_integrated_DW.is_c1_ALCA_subsystem_integrated =
      ALCA_subsystem_integrate_IN_OFF;
    *rty_alca_state = ALCA_state_OFF;
  }
  else if (((uint32_T)
            ALCA_subsystem_integrated_DW.is_c1_ALCA_subsystem_integrated) ==
           ALCA_subsystem_integrate_IN_OFF)
  {
    if (rtu_dcsn_info->alca_enable)
    {
      ALCA_subsystem_integrated_DW.is_c1_ALCA_subsystem_integrated =
        ALCA_subsystem_integrated_IN_ON;
      ALCA_subsystem_integrated_DW.is_ON = ALCA_subsystem_integ_IN_Standby;
      *rty_alca_state = ALCA_state_Standby;
    }
    else
    {
      *rty_alca_state = ALCA_state_OFF;
    }
  }
  else
  {
    ALCA_subsystem_integrated_ON(&LogicalOperator, &LogicalOperator1,
      rtu_dcsn_info, rtu_lc_accept, rtu_interrupt_type, rty_alca_state,
      rty_reset_change_lane_req, rty_interrupt_action);
  }

  /* End of Chart: '<S10>/ALCA_StateFlow' */

  /* Switch: '<S34>/Switch' incorporates:
   *  Constant: '<S34>/Constant1'
   *  Constant: '<S34>/Constant2'
   *  Constant: '<S34>/Constant5'
   *  Constant: '<S34>/Constant6'
   *  Constant: '<S34>/Constant7'
   *  Logic: '<S34>/Logical Operator'
   *  RelationalOperator: '<S34>/Relational Operator'
   *  RelationalOperator: '<S34>/Relational Operator1'
   *  RelationalOperator: '<S34>/Relational Operator2'
   */
  if ((((*rty_alca_state) == ALCA_state_Activated) || ((*rty_alca_state) ==
        ALCA_state_Abort)) || ((*rty_alca_state) == ALCA_state_Handover))
  {
    *rty_alca_request = true;
  }
  else
  {
    *rty_alca_request = false;
  }

  /* End of Switch: '<S34>/Switch' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
