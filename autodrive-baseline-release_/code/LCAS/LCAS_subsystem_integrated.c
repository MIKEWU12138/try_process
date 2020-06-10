/*
 * File: LCAS_subsystem_integrated.c
 *
 * Code generated for Simulink model 'LCAS_subsystem_integrated'.
 *
 * Model version                  : 1.452
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Jun  8 17:13:10 2020
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

#include "LCAS_subsystem_integrated.h"
#include "LCAS_subsystem_integrated_private.h"
#include "mul_s32_loSR.h"
#include "norm_TbqwX7rn.h"
#include "repos_fcn_FfRCHIAA.h"
#include "rt_roundf.h"

/* Named constants for Chart: '<S2>/DtmnWarningChart' */
#define LCAS_subs_IN_Warning_left1level ((uint8_T)1U)
#define LCAS_subs_IN_Warning_left2level ((uint8_T)2U)
#define LCAS_subsyst_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define LCAS_subsystem_integr_IN_UnSafe ((uint8_T)2U)
#define LCAS_subsystem_integrat_IN_Safe ((uint8_T)1U)

/* Named constants for Chart: '<S3>/DtmnWarningChart' */
#define LCAS_subsystem_IN_Warning1level ((uint8_T)1U)
#define LCAS_subsystem_IN_Warning2level ((uint8_T)2U)

/* Named constants for Chart: '<S4>/DtmnChart' */
#define LCAS_subsystem_in_IN_SELF_CHECK ((uint8_T)3U)
#define LCAS_subsystem_inte_IN_Inactive ((uint8_T)2U)
#define LCAS_subsystem_integ_IN_NoError ((uint8_T)2U)
#define LCAS_subsystem_integr_IN_Active ((uint8_T)1U)
#define LCAS_subsystem_integra_IN_ERROR ((uint8_T)1U)
#define LCAS_subsystem_integrate_IN_Off ((uint8_T)1U)
#define LCAS_subsystem_integrated_IN_On ((uint8_T)2U)

const LCAS_DataBus LCAS_subsystem_integrated_rtZLCAS_DataBus =
{
  0,                                   /* cvwL_ID */
  0,                                   /* cvwR_ID */
  LCAS_NONE,                           /* active_status */
  LCAS_NO_WARNING,                     /* left_warning_status */
  LCAS_NO_WARNING                      /* right_warning_status */
} ;                                    /* LCAS_DataBus ground */

/* Exported block signals */
LCAS_DataBus VsLCAS_DataBus;           /* '<S6>/Bus_Creator' */
real32_T VfLCAS_curvature;             /* '<S19>/Gain2' */
real32_T VfLCAS_speed_in;              /* '<S19>/Gain1' */
real32_T VaLCAS_Obt[16];               /* '<S20>/ObserveObtVecFunction2' */
int32_T ViLCAS_cvwR_ID;                /* '<S3>/Gain1' */
int32_T ViLCAS_cvwL_ID;                /* '<S2>/Gain1' */
uint16_T VnLCAS_num_R;                 /* '<S20>/Gain1' */
uint16_T VnLCAS_num_L;                 /* '<S20>/Gain2' */
uint8_T VfLCAS_gear_in;                /* '<S19>/Gain3' */
uint8_T ViLCAS_cvwR;                   /* '<S3>/Gain4' */
uint8_T ViLCAS_cvwL;                   /* '<S2>/Gain3' */
EnumLCAS_Active_Status VeLCAS_active_status;/* '<S6>/Rate Transition2' */
EnumLCAS_Warning_Status VeLCAS_right_warning_status_out;/* '<S6>/Rate Transition1' */
EnumLCAS_Warning_Status VeLCAS_left_warning_status_out;/* '<S6>/Rate Transition' */
EnumLCAS_Warning_Status VeLCAS_right_warning_status;/* '<S3>/Rate Transition' */
EnumLCAS_Warning_Status VeLCAS_left_warning_status;/* '<S2>/Rate Transition' */
#pragma section ".cal" 
/* Exported block parameters */
real32_T KfLCAS_Ang_DisbleStrAngleThrshMax = 0.8F;/* Variable: KfLCAS_Ang_DisbleStrAngleThrshMax
                                                   * Referenced by: '<S18>/Constant7'
                                                   */
real32_T KfLCAS_Ang_EnbleStrAngleThrshMax = 0.5F;/* Variable: KfLCAS_Ang_EnbleStrAngleThrshMax
                                                  * Referenced by: '<S18>/Constant6'
                                                  */
real32_T KfLCAS_c_DisbleCurveThrshMax = 0.0125F;/* Variable: KfLCAS_c_DisbleCurveThrshMax
                                                 * Referenced by: '<S18>/Constant20'
                                                 */
real32_T KfLCAS_c_EnbleCurveThrshMax = 0.0111111114F;/* Variable: KfLCAS_c_EnbleCurveThrshMax
                                                      * Referenced by: '<S18>/Constant19'
                                                      */
real32_T KfLCAS_d_CVLargerZone_FrontDis = 1.0F;/* Variable: KfLCAS_d_CVLargerZone_FrontDis
                                                * Referenced by: '<S18>/Constant12'
                                                */
real32_T KfLCAS_d_CVLargerZone_NearDis = 0.0F;/* Variable: KfLCAS_d_CVLargerZone_NearDis
                                               * Referenced by: '<S18>/Constant3'
                                               */
real32_T KfLCAS_d_CVZone_FarDis = 4.0F;/* Variable: KfLCAS_d_CVZone_FarDis
                                        * Referenced by: '<S18>/Constant4'
                                        */
real32_T KfLCAS_d_CVZone_FrontDis = 2.0F;/* Variable: KfLCAS_d_CVZone_FrontDis
                                          * Referenced by: '<S18>/Constant11'
                                          */
real32_T KfLCAS_d_CVZone_NearDis = 0.3F;/* Variable: KfLCAS_d_CVZone_NearDis
                                         * Referenced by: '<S18>/Constant2'
                                         */
real32_T KfLCAS_d_VehCenterFront = 3.33F;/* Variable: KfLCAS_d_VehCenterFront
                                          * Referenced by: '<S18>/Constant29'
                                          */
real32_T KfLCAS_d_VehCenterRear = 0.805F;/* Variable: KfLCAS_d_VehCenterRear
                                          * Referenced by: '<S18>/Constant28'
                                          */
real32_T KfLCAS_d_VehLenth = 4.0F;     /* Variable: KfLCAS_d_VehLenth
                                        * Referenced by: '<S18>/Constant'
                                        */
real32_T KfLCAS_d_VehWidth = 2.5F;     /* Variable: KfLCAS_d_VehWidth
                                        * Referenced by: '<S18>/Constant1'
                                        */
real32_T KfLCAS_r_ObtWidthProportion = 0.0F;/* Variable: KfLCAS_r_ObtWidthProportion
                                             * Referenced by: '<S18>/Constant25'
                                             */
real32_T KfLCAS_t_TTCLargerThrsh_LowLevel = 4.0F;/* Variable: KfLCAS_t_TTCLargerThrsh_LowLevel
                                                  * Referenced by: '<S18>/Constant14'
                                                  */
real32_T KfLCAS_t_TTCThrshLowLevel = 3.5F;/* Variable: KfLCAS_t_TTCThrshLowLevel
                                           * Referenced by: '<S18>/Constant13'
                                           */
real32_T KfLCAS_t_WarnSustainedTime = 2.0F;/* Variable: KfLCAS_t_WarnSustainedTime
                                            * Referenced by: '<S18>/Constant8'
                                            */
real32_T KfLCAS_v_DisbleVehSpdThrshHi = 53.0F;/* Variable: KfLCAS_v_DisbleVehSpdThrshHi
                                               * Referenced by: '<S18>/Constant27'
                                               */
real32_T KfLCAS_v_DisbleVehSpdThrshLo = -2.0F;/* Variable: KfLCAS_v_DisbleVehSpdThrshLo
                                               * Referenced by: '<S18>/Constant18'
                                               */
real32_T KfLCAS_v_EnbleVehSpdThrshHi = 50.0F;/* Variable: KfLCAS_v_EnbleVehSpdThrshHi
                                              * Referenced by: '<S18>/Constant26'
                                              */
real32_T KfLCAS_v_EnbleVehSpdThrshLo = -1.0F;/* Variable: KfLCAS_v_EnbleVehSpdThrshLo
                                              * Referenced by: '<S18>/Constant17'
                                              */
real32_T KfLCAS_v_LatSpdThr = 20.0F;   /* Variable: KfLCAS_v_LatSpdThr
                                        * Referenced by: '<S18>/Constant24'
                                        */
real32_T KfLCAS_v_staticSpdThr = 1.0F; /* Variable: KfLCAS_v_staticSpdThr
                                        * Referenced by: '<S18>/Constant9'
                                        */
int8_T KfLCAS_d_CVLargerZone_FarDis = 5;/* Variable: KfLCAS_d_CVLargerZone_FarDis
                                         * Referenced by: '<S18>/Constant5'
                                         */
boolean_T KbLCAS_Sensor_Error = 0;     /* Variable: KbLCAS_Sensor_Error
                                        * Referenced by: '<S4>/Constant28'
                                        */
boolean_T KbLCAS_Sensor_Work = 1;      /* Variable: KbLCAS_Sensor_Work
                                        * Referenced by: '<S4>/Constant3'
                                        */
boolean_T KbLCAS_Switch = 0;           /* Variable: KbLCAS_Switch
                                        * Referenced by: '<S18>/Constant21'
                                        */
boolean_T KbLCAS_configLCA = 0;        /* Variable: KbLCAS_configLCA
                                        * Referenced by: '<S18>/Constant30'
                                        */
boolean_T KbLCAS_curve = 0;            /* Variable: KbLCAS_curve
                                        * Referenced by: '<S19>/Constant28'
                                        */
#pragma section 
/* Block signals (auto storage) */
B_LCAS_subsystem_integrated_T LCAS_subsystem_integrated_B;

/* Block states (auto storage) */
DW_LCAS_subsystem_integrated_T LCAS_subsystem_integrated_DW;

/* Real-time model */
RT_MODEL_LCAS_subsystem_integ_T LCAS_subsystem_integrated_M_;
RT_MODEL_LCAS_subsystem_integ_T *const LCAS_subsystem_integrated_M =
  &LCAS_subsystem_integrated_M_;

/* Model step function */
void LCAS_subsystem_integrated_step(void)
{
  uint8_T CVW;
  real32_T x;
  real32_T y;
  real32_T ttc;
  real32_T CV_near1;
  real32_T CV_near2;
  real32_T CV_far1;
  real32_T CV_front2;
  uint16_T num_L;
  uint16_T num_R;
  real32_T vec_L[220];
  real32_T vec_R[220];
  real32_T vec_L_out_data[220];
  real32_T vec_R_out_data[220];
  uint16_T b;
  uint16_T i;
  real32_T rtb_curvature;
  real32_T rtb_vec_L_out[220];
  real32_T rtb_vec_R_out[220];
  EnumLCAS_Active_Status rtb_active_status;
  EnumLCAS_Warning_Status rtb_left_warning_status;
  EnumLCAS_Warning_Status rtb_right_warning_status;
  real32_T rtb_KfLCAS_d_VehCenterRear;
  boolean_T work;
  boolean_T rtb_LogicalOperator_ojv3;
  boolean_T rtb_LogicalOperator2;
  real32_T rtb_curvature_l5cv;
  uint32_T elapsedTicks_cdpc;
  real32_T x_0[2];
  int32_T loop_ub;
  int32_T vec_L_out_size[2];
  int32_T vec_R_out_size[2];
  real_T tmp;
  boolean_T exitg1;

  /* Outputs for Atomic SubSystem: '<Root>/LCAS_Subsystem' */
  /* Outputs for Atomic SubSystem: '<S1>/LCAS_input_Subsystem' */
  /* Switch: '<S19>/Switch1' incorporates:
   *  Constant: '<S19>/Constant28'
   *  Constant: '<S19>/Constant4'
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  if (KbLCAS_curve)
  {
    rtb_curvature = VsEGMO_DataBus.motion.curvature;
  }
  else
  {
    rtb_curvature = 0.0F;
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Outputs for Enabled SubSystem: '<S5>/LCAS_CvrtObtVecFunctionEnabled' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  /* Logic: '<S19>/Logical Operator1' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant5'
   *  Constant: '<S23>/Constant'
   *  DataTypeConversion: '<S20>/Data Type Conversion'
   *  DataTypeConversion: '<S20>/Data Type Conversion1'
   *  Inport: '<Root>/VsOBFU_DataBus'
   *  Logic: '<S19>/Logical Operator'
   *  RelationalOperator: '<S23>/Compare'
   */
  if (((true) && (VsOBFU_DataBus.num_obstacles >= ((uint16_T)1U))) && (!false))
  {
    if (!LCAS_subsystem_integrated_DW.LCAS_CvrtObtVecFunctionEnabled_)
    {
      LCAS_subsystem_integrated_DW.LCAS_CvrtObtVecFunctionEnabled_ = true;
    }

    /* MATLAB Function: '<S20>/CvrtObtVecFunction' incorporates:
     *  Constant: '<S18>/Constant9'
     *  Constant: '<S19>/Constant1'
     *  Inport: '<Root>/VsEGMO_DataBus'
     */
    num_L = 0U;
    num_R = 0U;
    LCAS_subsystem_integrated_DW.SFunction_DIMS2[0] = 20;
    LCAS_subsystem_integrated_DW.SFunction_DIMS2[1] = 11;
    LCAS_subsystem_integrated_DW.SFunction_DIMS3[0] = 20;
    LCAS_subsystem_integrated_DW.SFunction_DIMS3[1] = 11;
    memset(&vec_L[0], 0, 220U * (sizeof(real32_T)));
    memset(&vec_R[0], 0, 220U * (sizeof(real32_T)));
    memset(&rtb_vec_L_out[0], 0, 220U * (sizeof(real32_T)));
    memset(&rtb_vec_R_out[0], 0, 220U * (sizeof(real32_T)));
    if (((int32_T)VsOBFU_DataBus.num_obstacles) > 1)
    {
      if (((int32_T)VsOBFU_DataBus.num_obstacles) < 128)
      {
        b = VsOBFU_DataBus.num_obstacles;
      }
      else
      {
        b = 128U;
      }

      for (i = 1U; i <= b; i = (uint16_T)(((uint32_T)i) + 1U))
      {
        if ((VsEGMO_DataBus.motion.velocity_rel.x + VsOBFU_DataBus.obstacles
             [((int32_T)i) - 1].velocity_rel.x) > KfLCAS_v_staticSpdThr)
        {
          if ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].nearest_point_rel.x <
               10.0F) && (((int32_T)num_L) < 20))
          {
            tmp = (real_T)((real32_T)fabs((real_T)rtb_curvature));
            if ((tmp > 0.001) || ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                                   nearest_point_rel.y > 0.0F) && (tmp <= 0.001)))
            {
              loop_ub = ((int32_T)num_L) + 1;
              if (loop_ub < 20)
              {
                num_L = (uint16_T)loop_ub;
              }
              else
              {
                num_L = 20U;
              }

              vec_L[((int32_T)num_L) - 1] = (real32_T)VsOBFU_DataBus.obstacles
                [((int32_T)i) - 1].id;
              vec_L[((int32_T)num_L) + 19] = VsOBFU_DataBus.obstacles[((int32_T)
                i) - 1].center_point_rel.x;
              vec_L[((int32_T)num_L) + 39] = VsOBFU_DataBus.obstacles[((int32_T)
                i) - 1].center_point_rel.y;
              vec_L[((int32_T)num_L) + 59] = VsOBFU_DataBus.obstacles[((int32_T)
                i) - 1].heading_rel;
              vec_L[((int32_T)num_L) + 79] = (real32_T)sqrt((real_T)((real32_T)
                ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x *
                  VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x) +
                 (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.y *
                  VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.y))));
              vec_L[((int32_T)num_L) + 99] = VsOBFU_DataBus.obstacles[((int32_T)
                i) - 1].length;
              vec_L[((int32_T)num_L) + 119] = VsOBFU_DataBus.obstacles[((int32_T)
                i) - 1].width;
              vec_L[((int32_T)num_L) + 139] = (real32_T)
                ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x <
                  0.0F) ? 1 : 0);
              vec_L[((int32_T)num_L) + 159] = VsOBFU_DataBus.obstacles[((int32_T)
                i) - 1].nearest_point_rel.x;
              vec_L[((int32_T)num_L) + 179] = VsOBFU_DataBus.obstacles[((int32_T)
                i) - 1].nearest_point_rel.y;
              vec_L[((int32_T)num_L) + 199] = VsOBFU_DataBus.obstacles[((int32_T)
                i) - 1].velocity_rel.y;
            }
          }

          if (((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].nearest_point_rel.x <
                10.0F) && (((int32_T)num_R) < 20)) && ((((real_T)((real32_T)fabs
                  ((real_T)rtb_curvature))) > 0.001) ||
               ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].nearest_point_rel.y <
                 0.0F) && (((real_T)((real32_T)fabs((real_T)rtb_curvature))) <=
                           0.001))))
          {
            loop_ub = ((int32_T)num_R) + 1;
            if (loop_ub < 20)
            {
              num_R = (uint16_T)loop_ub;
            }
            else
            {
              num_R = 20U;
            }

            vec_R[((int32_T)num_R) - 1] = (real32_T)VsOBFU_DataBus.obstacles
              [((int32_T)i) - 1].id;
            vec_R[((int32_T)num_R) + 19] = VsOBFU_DataBus.obstacles[((int32_T)i)
              - 1].center_point_rel.x;
            vec_R[((int32_T)num_R) + 39] = VsOBFU_DataBus.obstacles[((int32_T)i)
              - 1].center_point_rel.y;
            vec_R[((int32_T)num_R) + 59] = VsOBFU_DataBus.obstacles[((int32_T)i)
              - 1].heading_rel;
            vec_R[((int32_T)num_R) + 79] = (real32_T)sqrt((real_T)((real32_T)
              ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x *
                VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x) +
               (VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.y *
                VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.y))));
            vec_R[((int32_T)num_R) + 99] = VsOBFU_DataBus.obstacles[((int32_T)i)
              - 1].length;
            vec_R[((int32_T)num_R) + 119] = VsOBFU_DataBus.obstacles[((int32_T)i)
              - 1].width;
            vec_R[((int32_T)num_R) + 139] = (real32_T)
              ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].velocity_rel.x < 0.0F)
               ? 1 : 0);
            vec_R[((int32_T)num_R) + 159] = VsOBFU_DataBus.obstacles[((int32_T)i)
              - 1].nearest_point_rel.x;
            vec_R[((int32_T)num_R) + 179] = VsOBFU_DataBus.obstacles[((int32_T)i)
              - 1].nearest_point_rel.y;
            vec_R[((int32_T)num_R) + 199] = VsOBFU_DataBus.obstacles[((int32_T)i)
              - 1].velocity_rel.y;
          }
        }
      }

      if (!false)
      {
        memset(&vec_L[140], 0, 20U * (sizeof(real32_T)));
        memset(&vec_R[140], 0, 20U * (sizeof(real32_T)));
      }

      repos_fcn_FfRCHIAA(num_L, num_R, rtb_curvature, vec_L, vec_R,
                         vec_L_out_data, vec_L_out_size, vec_R_out_data,
                         vec_R_out_size);
      LCAS_subsystem_integrated_DW.SFunction_DIMS2[0] = vec_L_out_size[0];
      LCAS_subsystem_integrated_DW.SFunction_DIMS2[1] = vec_L_out_size[1];
      loop_ub = vec_L_out_size[0] * vec_L_out_size[1];
      if (0 <= (loop_ub - 1))
      {
        memcpy(&rtb_vec_L_out[0], &vec_L_out_data[0], ((uint32_T)loop_ub) *
               (sizeof(real32_T)));
      }

      LCAS_subsystem_integrated_DW.SFunction_DIMS3[0] = vec_R_out_size[0];
      LCAS_subsystem_integrated_DW.SFunction_DIMS3[1] = vec_R_out_size[1];
      loop_ub = vec_R_out_size[0] * vec_R_out_size[1];
      if (0 <= (loop_ub - 1))
      {
        memcpy(&rtb_vec_R_out[0], &vec_R_out_data[0], ((uint32_T)loop_ub) *
               (sizeof(real32_T)));
      }
    }

    LCAS_subsystem_integrated_B.num_L = num_L;
    LCAS_subsystem_integrated_B.num_R = num_R;

    /* End of MATLAB Function: '<S20>/CvrtObtVecFunction' */

    /* DataTypeConversion: '<S20>/Data Type Conversion' */
    LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] =
      LCAS_subsystem_integrated_DW.SFunction_DIMS2[0];
    LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[1] =
      LCAS_subsystem_integrated_DW.SFunction_DIMS2[1];
    loop_ub = LCAS_subsystem_integrated_DW.SFunction_DIMS2[0] *
      LCAS_subsystem_integrated_DW.SFunction_DIMS2[1];
    if (0 <= (loop_ub - 1))
    {
      memcpy(&LCAS_subsystem_integrated_B.vec_L[0], &rtb_vec_L_out[0],
             ((uint32_T)loop_ub) * (sizeof(real32_T)));
    }

    /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
     *  DataTypeConversion: '<S20>/Data Type Conversion'
     */
    LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] =
      LCAS_subsystem_integrated_DW.SFunction_DIMS3[0];
    LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[1] =
      LCAS_subsystem_integrated_DW.SFunction_DIMS3[1];
    loop_ub = LCAS_subsystem_integrated_DW.SFunction_DIMS3[0] *
      LCAS_subsystem_integrated_DW.SFunction_DIMS3[1];
    if (0 <= (loop_ub - 1))
    {
      memcpy(&LCAS_subsystem_integrated_B.vec_R[0], &rtb_vec_R_out[0],
             ((uint32_T)loop_ub) * (sizeof(real32_T)));
    }

    /* MATLAB Function: '<S20>/ObserveObtVecFunction2' incorporates:
     *  DataTypeConversion: '<S20>/Data Type Conversion1'
     */
    memset(&VaLCAS_Obt[0], 0, (sizeof(real32_T)) << 4U);
    if (((int32_T)LCAS_subsystem_integrated_B.num_L) >= 1)
    {
      if (4 < ((int32_T)LCAS_subsystem_integrated_B.num_L))
      {
        b = 4U;
      }
      else
      {
        b = LCAS_subsystem_integrated_B.num_L;
      }

      for (i = 1U; i <= b; i = (uint16_T)(((uint32_T)i) + 1U))
      {
        loop_ub = ((int32_T)i) - 1;
        VaLCAS_Obt[loop_ub] = LCAS_subsystem_integrated_B.vec_L[loop_ub];
        VaLCAS_Obt[((int32_T)i) + 3] = LCAS_subsystem_integrated_B.vec_L
          [(((int32_T)i) +
            (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 8)) - 1];
        VaLCAS_Obt[((int32_T)i) + 7] = LCAS_subsystem_integrated_B.vec_L
          [(((int32_T)i) +
            (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 9)) - 1];
        VaLCAS_Obt[((int32_T)i) + 11] = LCAS_subsystem_integrated_B.vec_L
          [(((int32_T)i) +
            (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 10)) - 1];
      }
    }

    /* End of MATLAB Function: '<S20>/ObserveObtVecFunction2' */

    /* Gain: '<S20>/Gain1' */
    VnLCAS_num_R = (uint16_T)((((uint32_T)((uint16_T)32768U)) * ((uint32_T)
      LCAS_subsystem_integrated_B.num_R)) >> 15);

    /* Gain: '<S20>/Gain2' */
    VnLCAS_num_L = (uint16_T)((((uint32_T)((uint16_T)32768U)) * ((uint32_T)
      LCAS_subsystem_integrated_B.num_L)) >> 15);
  }
  else
  {
    if (LCAS_subsystem_integrated_DW.LCAS_CvrtObtVecFunctionEnabled_)
    {
      LCAS_subsystem_integrated_DW.LCAS_CvrtObtVecFunctionEnabled_ = false;
    }
  }

  /* End of Logic: '<S19>/Logical Operator1' */
  /* End of Outputs for SubSystem: '<S5>/LCAS_CvrtObtVecFunctionEnabled' */

  /* Constant: '<S18>/Constant28' */
  rtb_KfLCAS_d_VehCenterRear = KfLCAS_d_VehCenterRear;

  /* Gain: '<S19>/Gain2' incorporates:
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  VfLCAS_curvature = 1.0F * VsEGMO_DataBus.motion.curvature;

  /* Switch: '<S19>/Switch' incorporates:
   *  Inport: '<Root>/VsEGMO_DataBus'
   *  Inport: '<Root>/VsMPFU_DataBus'
   */
  if (VsMPFU_DataBus.curvature.is_valid)
  {
    rtb_curvature_l5cv = VsMPFU_DataBus.curvature.value;
  }
  else
  {
    rtb_curvature_l5cv = VsEGMO_DataBus.motion.curvature;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Gain: '<S19>/Gain1' incorporates:
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   *  SignalConversion: '<S19>/TmpSignal ConversionAtBus Selector1Outport4'
   */
  VfLCAS_speed_in = 1.0F *
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;

  /* Gain: '<S19>/Gain3' incorporates:
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   *  SignalConversion: '<S19>/TmpSignal ConversionAtBus Selector1Outport5'
   */
  VfLCAS_gear_in = (uint8_T)((((uint32_T)((uint8_T)128U)) * ((uint32_T)
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition)) >> 7);

  /* End of Outputs for SubSystem: '<S1>/LCAS_input_Subsystem' */

  /* Outputs for Enabled SubSystem: '<S1>/DtmnLCAEnabledSubsystem' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Constant: '<S18>/Constant30' */
  if (KbLCAS_configLCA)
  {
    if (!LCAS_subsystem_integrated_DW.DtmnLCAEnabledSubsystem_MODE)
    {
      /* SystemReset for Chart: '<S4>/DtmnChart' */
      LCAS_subsystem_integrated_DW.is_NoError = LCAS_subsyst_IN_NO_ACTIVE_CHILD;
      LCAS_subsystem_integrated_DW.is_On = LCAS_subsyst_IN_NO_ACTIVE_CHILD;

      /* Chart: '<S4>/DtmnChart' */
      LCAS_subsystem_integrated_DW.is_c3_LCAS_subsystem_integrated =
        LCAS_subsystem_in_IN_SELF_CHECK;
      LCAS_subsystem_integrated_DW.DtmnLCAEnabledSubsystem_MODE = true;
    }

    /* Logic: '<S4>/Logical Operator4' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Constant2'
     *  Constant: '<S4>/Constant3'
     */
    work = ((KbLCAS_Sensor_Work && (1.0 != 0.0)) && (1.0 != 0.0));

    /* Chart: '<S4>/DtmnChart' incorporates:
     *  Abs: '<S19>/Abs'
     *  BusCreator: '<S18>/Bus Creator1'
     *  Constant: '<S11>/Constant'
     *  Constant: '<S12>/Constant'
     *  Constant: '<S18>/Constant17'
     *  Constant: '<S18>/Constant18'
     *  Constant: '<S18>/Constant19'
     *  Constant: '<S18>/Constant20'
     *  Constant: '<S18>/Constant21'
     *  Constant: '<S18>/Constant26'
     *  Constant: '<S18>/Constant27'
     *  Constant: '<S18>/Constant6'
     *  Constant: '<S18>/Constant7'
     *  Constant: '<S19>/Constant5'
     *  Constant: '<S4>/Constant28'
     *  Constant: '<S4>/Constant4'
     *  Constant: '<S4>/Constant5'
     *  Inport: '<Root>/VsCOMM_CANR_Databus'
     *  Logic: '<S4>/Logical Operator1'
     *  Logic: '<S4>/Logical Operator3'
     *  Logic: '<S4>/Logical Operator5'
     *  RelationalOperator: '<S11>/Compare'
     *  RelationalOperator: '<S12>/Compare'
     *  RelationalOperator: '<S4>/Relational Operator'
     *  RelationalOperator: '<S4>/Relational Operator1'
     *  RelationalOperator: '<S4>/Relational Operator2'
     *  RelationalOperator: '<S4>/Relational Operator3'
     *  RelationalOperator: '<S4>/Relational Operator4'
     *  RelationalOperator: '<S4>/Relational Operator5'
     *  RelationalOperator: '<S4>/Relational Operator6'
     *  RelationalOperator: '<S4>/Relational Operator7'
     *  SignalConversion: '<S19>/TmpSignal ConversionAtBus Selector1Outport4'
     *  SignalConversion: '<S19>/TmpSignal ConversionAtBus Selector1Outport5'
     */
    switch (LCAS_subsystem_integrated_DW.is_c3_LCAS_subsystem_integrated)
    {
     case LCAS_subsystem_integra_IN_ERROR:
      LCAS_subsystem_integrated_B.enable = false;
      LCAS_subsystem_integrated_B.active_status = LCAS_ERROR;
      break;

     case LCAS_subsystem_integ_IN_NoError:
      if (((uint32_T)LCAS_subsystem_integrated_DW.is_NoError) ==
          LCAS_subsystem_integrate_IN_Off)
      {
        LCAS_subsystem_integrated_B.enable = false;
        LCAS_subsystem_integrated_B.active_status = LCAS_OFF;
      }
      else if (((uint32_T)LCAS_subsystem_integrated_DW.is_On) ==
               LCAS_subsystem_integr_IN_Active)
      {
        LCAS_subsystem_integrated_B.enable = true;
        LCAS_subsystem_integrated_B.active_status = LCAS_ACTIVE;
      }
      else
      {
        LCAS_subsystem_integrated_B.enable = false;
        LCAS_subsystem_integrated_B.active_status = LCAS_INACTIVE;
      }
      break;

     default:
      LCAS_subsystem_integrated_B.enable = false;
      LCAS_subsystem_integrated_B.active_status = LCAS_SELF_CHECK;
      break;
    }

    switch (LCAS_subsystem_integrated_DW.is_c3_LCAS_subsystem_integrated)
    {
     case LCAS_subsystem_integra_IN_ERROR:
      if ((!((KbLCAS_Sensor_Error || (0.0 != 0.0)) || (0.0 != 0.0))) && work)
      {
        LCAS_subsystem_integrated_DW.is_c3_LCAS_subsystem_integrated =
          LCAS_subsystem_integ_IN_NoError;
        LCAS_subsystem_integrated_DW.is_NoError =
          LCAS_subsystem_integrate_IN_Off;
      }
      break;

     case LCAS_subsystem_integ_IN_NoError:
      if ((!work) || ((KbLCAS_Sensor_Error || (0.0 != 0.0)) || (0.0 != 0.0)))
      {
        LCAS_subsystem_integrated_DW.is_NoError =
          LCAS_subsyst_IN_NO_ACTIVE_CHILD;
        LCAS_subsystem_integrated_DW.is_On = LCAS_subsyst_IN_NO_ACTIVE_CHILD;
        LCAS_subsystem_integrated_DW.is_c3_LCAS_subsystem_integrated =
          LCAS_subsystem_integra_IN_ERROR;
      }
      else if (((uint32_T)LCAS_subsystem_integrated_DW.is_NoError) ==
               LCAS_subsystem_integrate_IN_Off)
      {
        /* Outputs for Atomic SubSystem: '<S1>/LCAS_input_Subsystem' */
        if ((true) && KbLCAS_Switch)
        {
          LCAS_subsystem_integrated_DW.is_NoError =
            LCAS_subsystem_integrated_IN_On;
          LCAS_subsystem_integrated_DW.is_On = LCAS_subsystem_inte_IN_Inactive;
        }

        /* End of Outputs for SubSystem: '<S1>/LCAS_input_Subsystem' */
      }
      else
      {
        /* Outputs for Atomic SubSystem: '<S1>/LCAS_input_Subsystem' */
        if ((!true) || (!KbLCAS_Switch))
        {
          LCAS_subsystem_integrated_DW.is_On = LCAS_subsyst_IN_NO_ACTIVE_CHILD;
          LCAS_subsystem_integrated_DW.is_NoError =
            LCAS_subsystem_integrate_IN_Off;
        }
        else if (((uint32_T)LCAS_subsystem_integrated_DW.is_On) ==
                 LCAS_subsystem_integr_IN_Active)
        {
          if (((((rtb_curvature > KfLCAS_c_DisbleCurveThrshMax) ||
                 (VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed <
                  KfLCAS_v_DisbleVehSpdThrshLo)) ||
                (VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed >
                 KfLCAS_v_DisbleVehSpdThrshHi)) ||
               (VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition
                != ((uint8_T)1U))) || (((real32_T)fabs((real_T)
                 VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle)) >
               KfLCAS_Ang_DisbleStrAngleThrshMax))
          {
            LCAS_subsystem_integrated_DW.is_On = LCAS_subsystem_inte_IN_Inactive;
          }
        }
        else
        {
          if (((((VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed >=
                  KfLCAS_v_EnbleVehSpdThrshLo) &&
                 (VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed <
                  KfLCAS_v_EnbleVehSpdThrshHi)) &&
                (VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition
                 == ((uint8_T)1U))) && (rtb_curvature <
                KfLCAS_c_EnbleCurveThrshMax)) && (((real32_T)fabs((real_T)
                 VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle)) <
               KfLCAS_Ang_EnbleStrAngleThrshMax))
          {
            LCAS_subsystem_integrated_DW.is_On = LCAS_subsystem_integr_IN_Active;
          }
        }

        /* End of Outputs for SubSystem: '<S1>/LCAS_input_Subsystem' */
      }
      break;

     default:
      if ((KbLCAS_Sensor_Error || (0.0 != 0.0)) || (0.0 != 0.0))
      {
        LCAS_subsystem_integrated_DW.is_c3_LCAS_subsystem_integrated =
          LCAS_subsystem_integra_IN_ERROR;
      }
      else
      {
        if (work)
        {
          LCAS_subsystem_integrated_DW.is_c3_LCAS_subsystem_integrated =
            LCAS_subsystem_integ_IN_NoError;
          LCAS_subsystem_integrated_DW.is_NoError =
            LCAS_subsystem_integrate_IN_Off;
        }
      }
      break;
    }

    /* Logic: '<S4>/Logical Operator' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S14>/Constant'
     *  RelationalOperator: '<S13>/Compare'
     *  RelationalOperator: '<S14>/Compare'
     */
    rtb_LogicalOperator_ojv3 = ((LCAS_subsystem_integrated_B.num_L != ((uint16_T)
      0U)) || (LCAS_subsystem_integrated_B.num_R != ((uint16_T)0U)));

    /* Logic: '<S4>/Logical Operator2' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S16>/Constant'
     *  RelationalOperator: '<S15>/Compare'
     *  RelationalOperator: '<S16>/Compare'
     */
    rtb_LogicalOperator2 = ((LCAS_subsystem_integrated_B.num_L == ((uint16_T)0U))
      && (LCAS_subsystem_integrated_B.num_R == ((uint16_T)0U)));
  }
  else
  {
    if (LCAS_subsystem_integrated_DW.DtmnLCAEnabledSubsystem_MODE)
    {
      LCAS_subsystem_integrated_DW.DtmnLCAEnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/DtmnLCAEnabledSubsystem' */

  /* Outputs for Enabled SubSystem: '<S1>/CalcLLCAEnabledSubsystem' incorporates:
   *  EnablePort: '<S2>/LLCWEnable'
   */
  if (LCAS_subsystem_integrated_B.enable)
  {
    if (!LCAS_subsystem_integrated_DW.CalcLLCAEnabledSubsystem_MODE)
    {
      /* SystemReset for Chart: '<S2>/DtmnWarningChart' */
      LCAS_subsystem_integrated_DW.is_UnSafe_jdaq =
        LCAS_subsyst_IN_NO_ACTIVE_CHILD;
      LCAS_subsystem_integrated_DW.temporalCounter_i1_hmm3 = 0U;

      /* Chart: '<S2>/DtmnWarningChart' */
      LCAS_subsystem_integrated_DW.is_c12_LCAS_subsystem_integrate =
        LCAS_subsystem_integrat_IN_Safe;

      /* Enable for Chart: '<S2>/DtmnWarningChart' */
      LCAS_subsystem_integrated_DW.previousTicks_mdx3 =
        LCAS_subsystem_integrated_M->Timing.clockTick0;
      LCAS_subsystem_integrated_DW.CalcLLCAEnabledSubsystem_MODE = true;
    }

    /* MATLAB Function: '<S2>/Calc_LCVWFunction' incorporates:
     *  BusCreator: '<S18>/Bus Creator'
     *  Constant: '<S18>/Constant11'
     *  Constant: '<S18>/Constant12'
     *  Constant: '<S18>/Constant2'
     *  Constant: '<S18>/Constant3'
     *  Constant: '<S18>/Constant4'
     *  Constant: '<S18>/Constant5'
     */
    CVW = 4U;
    LCAS_subsystem_integrated_B.cvwL_ID = 0;

    /* Outputs for Atomic SubSystem: '<S1>/LCAS_input_Subsystem' */
    rtb_curvature = KfLCAS_d_CVZone_FrontDis;
    CV_front2 = KfLCAS_d_CVLargerZone_FrontDis;
    CV_near1 = KfLCAS_d_CVZone_NearDis;
    CV_near2 = KfLCAS_d_CVLargerZone_NearDis;
    CV_far1 = KfLCAS_d_CVZone_FarDis;
    loop_ub = (int32_T)KfLCAS_d_CVLargerZone_FarDis;
    if (((((KfLCAS_d_CVZone_FrontDis > 3.0F) || (KfLCAS_d_CVZone_FrontDis < 0.0F))
          || (KfLCAS_d_CVLargerZone_FrontDis > 3.0F)) ||
         (KfLCAS_d_CVLargerZone_FrontDis < 0.0F)) ||
        (KfLCAS_d_CVLargerZone_FrontDis >= KfLCAS_d_CVZone_FrontDis))
    {
      rtb_curvature = 2.0F;
      CV_front2 = 1.0F;
    }

    if (((((KfLCAS_d_CVZone_NearDis < -0.5F) || (KfLCAS_d_CVZone_NearDis > 0.5F))
          || (KfLCAS_d_CVLargerZone_NearDis < -0.5F)) ||
         (KfLCAS_d_CVLargerZone_NearDis > 0.5F)) ||
        (KfLCAS_d_CVLargerZone_NearDis >= KfLCAS_d_CVZone_NearDis))
    {
      CV_near1 = 0.3F;
      CV_near2 = 0.0F;
    }

    if (((((KfLCAS_d_CVZone_FarDis < 3.0F) || (KfLCAS_d_CVZone_FarDis > 6.0F)) ||
          (KfLCAS_d_CVLargerZone_FarDis < 3)) || (KfLCAS_d_CVLargerZone_FarDis >
          6)) || (((real32_T)KfLCAS_d_CVLargerZone_FarDis) <=
                  KfLCAS_d_CVZone_FarDis))
    {
      CV_far1 = 4.0F;
      loop_ub = 5;
    }

    /* End of Outputs for SubSystem: '<S1>/LCAS_input_Subsystem' */
    if (!((LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] == 0) ||
          (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[1] == 0)))
    {
      if (((int32_T)LCAS_subsystem_integrated_B.num_L) <
          LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0])
      {
        b = LCAS_subsystem_integrated_B.num_L;
      }
      else
      {
        b = (uint16_T)LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0];
      }

      i = 1U;
      exitg1 = false;
      while ((!exitg1) && (i <= b))
      {
        x = LCAS_subsystem_integrated_B.vec_L[(((int32_T)i) +
          (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 8)) - 1] -
          KfLCAS_d_VehCenterFront;
        y = LCAS_subsystem_integrated_B.vec_L[(((int32_T)i) +
          (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 9)) - 1];
        if (LCAS_subsystem_integrated_B.vec_L[(((int32_T)i) +
             (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 10)) -
            1] < (-KfLCAS_v_LatSpdThr))
        {
          y = LCAS_subsystem_integrated_B.vec_L[(((int32_T)i) +
            (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 9)) - 1]
            - (LCAS_subsystem_integrated_B.vec_L[(((int32_T)i) +
                (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6))
               - 1] * KfLCAS_r_ObtWidthProportion);
        }

        if (LCAS_subsystem_integrated_B.vec_L[(((int32_T)i) +
             (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 10)) -
            1] > KfLCAS_v_LatSpdThr)
        {
          y += LCAS_subsystem_integrated_B.vec_L[(((int32_T)i) +
            (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6)) - 1]
            * KfLCAS_r_ObtWidthProportion;
        }

        ttc = 100.0F;
        if (((real_T)LCAS_subsystem_integrated_B.vec_L[(((int32_T)i) +
              (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 4)) -
             1]) > 0.001)
        {
          x_0[0] = x + KfLCAS_d_VehLenth;
          x_0[1] = y;
          ttc = norm_TbqwX7rn(x_0) / LCAS_subsystem_integrated_B.vec_L
            [(((int32_T)i) +
              (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 4)) -
            1];
        }

        if ((((x < ((-rtb_curvature) - KfLCAS_d_VehLenth)) && (y > (CV_near1 +
                (KfLCAS_d_VehWidth * 0.5F)))) && (y < (CV_far1 +
               (KfLCAS_d_VehWidth * 0.5F)))) && (ttc < KfLCAS_t_TTCThrshLowLevel))
        {
          CVW = 1U;
          rtb_curvature = rt_roundf(LCAS_subsystem_integrated_B.vec_L[((int32_T)
            i) - 1]);
          if (rtb_curvature < 2.14748365E+9F)
          {
            if (rtb_curvature >= -2.14748365E+9F)
            {
              LCAS_subsystem_integrated_B.cvwL_ID = (int32_T)rtb_curvature;
            }
            else
            {
              LCAS_subsystem_integrated_B.cvwL_ID = MIN_int32_T;
            }
          }
          else
          {
            LCAS_subsystem_integrated_B.cvwL_ID = MAX_int32_T;
          }

          exitg1 = true;
        }
        else
        {
          i = (uint16_T)(((uint32_T)i) + 1U);
        }
      }

      if (((int32_T)CVW) != 1)
      {
        if (((int32_T)LCAS_subsystem_integrated_B.num_L) <
            LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0])
        {
          num_L = LCAS_subsystem_integrated_B.num_L;
        }
        else
        {
          num_L = (uint16_T)
            LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0];
        }

        num_R = 1U;
        exitg1 = false;
        while ((!exitg1) && (num_R <= num_L))
        {
          x = LCAS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
            (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 8)) - 1]
            - KfLCAS_d_VehCenterFront;
          y = LCAS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
            (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 9)) - 1];
          if (LCAS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
               (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 10))
              - 1] < (-KfLCAS_v_LatSpdThr))
          {
            y = LCAS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
              (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 9)) -
              1] - (LCAS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
                     (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] *
                      6)) - 1] * KfLCAS_r_ObtWidthProportion);
          }

          if (LCAS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
               (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 10))
              - 1] > KfLCAS_v_LatSpdThr)
          {
            y += LCAS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
              (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 6)) -
              1] * KfLCAS_r_ObtWidthProportion;
          }

          ttc = 100.0F;
          if (((real_T)LCAS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
                (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 4))
               - 1]) > 0.001)
          {
            x_0[0] = x + KfLCAS_d_VehLenth;
            x_0[1] = y;
            ttc = norm_TbqwX7rn(x_0) / LCAS_subsystem_integrated_B.vec_L
              [(((int32_T)num_R) +
                (LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 4))
              - 1];
          }

          if ((((x < ((-CV_front2) - KfLCAS_d_VehLenth)) && (y > (CV_near2 +
                  (KfLCAS_d_VehWidth * 0.5F)))) && (y < (((real32_T)loop_ub) +
                 (KfLCAS_d_VehWidth * 0.5F)))) && (ttc <
               KfLCAS_t_TTCLargerThrsh_LowLevel))
          {
            CVW = 2U;
            rtb_curvature = rt_roundf(LCAS_subsystem_integrated_B.vec_L
              [((int32_T)num_R) - 1]);
            if (rtb_curvature < 2.14748365E+9F)
            {
              if (rtb_curvature >= -2.14748365E+9F)
              {
                LCAS_subsystem_integrated_B.cvwL_ID = (int32_T)rtb_curvature;
              }
              else
              {
                LCAS_subsystem_integrated_B.cvwL_ID = MIN_int32_T;
              }
            }
            else
            {
              LCAS_subsystem_integrated_B.cvwL_ID = MAX_int32_T;
            }

            exitg1 = true;
          }
          else
          {
            num_R = (uint16_T)(((uint32_T)num_R) + 1U);
          }
        }
      }
    }

    /* Gain: '<S2>/Gain1' */
    ViLCAS_cvwL_ID = mul_s32_loSR(1073741824,
      LCAS_subsystem_integrated_B.cvwL_ID, 30U);

    /* Gain: '<S2>/Gain3' incorporates:
     *  MATLAB Function: '<S2>/Calc_LCVWFunction'
     */
    ViLCAS_cvwL = (uint8_T)((((uint32_T)((uint8_T)128U)) * ((uint32_T)CVW)) >> 7);

    /* Chart: '<S2>/DtmnWarningChart' incorporates:
     *  Constant: '<S18>/Constant8'
     *  Constant: '<S21>/Constant'
     *  Inport: '<Root>/VsCOMM_CANR_Databus'
     *  MATLAB Function: '<S2>/Calc_LCVWFunction'
     *  RelationalOperator: '<S21>/Compare'
     */
    if (((uint32_T)LCAS_subsystem_integrated_DW.is_c12_LCAS_subsystem_integrate)
        == LCAS_subsystem_integrat_IN_Safe)
    {
      LCAS_subsystem_integrated_B.left_warning_status = LCAS_NO_WARNING;
    }
    else if (((uint32_T)LCAS_subsystem_integrated_DW.is_UnSafe_jdaq) ==
             LCAS_subs_IN_Warning_left1level)
    {
      LCAS_subsystem_integrated_B.left_warning_status = LCAS_WARNING_LOW_LEVEL;
    }
    else
    {
      LCAS_subsystem_integrated_B.left_warning_status = LCAS_WARNING_HIGH_LEVEL;
    }

    elapsedTicks_cdpc = LCAS_subsystem_integrated_M->Timing.clockTick0 -
      LCAS_subsystem_integrated_DW.previousTicks_mdx3;
    LCAS_subsystem_integrated_DW.previousTicks_mdx3 =
      LCAS_subsystem_integrated_M->Timing.clockTick0;
    LCAS_subsystem_integrated_DW.temporalCounter_i1_hmm3 += elapsedTicks_cdpc;
    if (((uint32_T)LCAS_subsystem_integrated_DW.is_c12_LCAS_subsystem_integrate)
        == LCAS_subsystem_integrat_IN_Safe)
    {
      if (((uint32_T)CVW) == WARNING_S_AREA)
      {
        LCAS_subsystem_integrated_DW.is_c12_LCAS_subsystem_integrate =
          LCAS_subsystem_integr_IN_UnSafe;
        LCAS_subsystem_integrated_DW.temporalCounter_i1_hmm3 = 0U;
        LCAS_subsystem_integrated_DW.is_UnSafe_jdaq =
          LCAS_subs_IN_Warning_left1level;
      }
    }
    else if ((((((uint32_T)CVW) != WARNING_S_AREA) && (((uint32_T)CVW) !=
                WARNING_L_AREA)) && (((real32_T)
                LCAS_subsystem_integrated_DW.temporalCounter_i1_hmm3) >=
               (KfLCAS_t_WarnSustainedTime * 100.0F))) || ((((uint32_T)CVW) ==
               NO_WARNING_AREA) && (((real32_T)
                LCAS_subsystem_integrated_DW.temporalCounter_i1_hmm3) >=
               (KfLCAS_t_WarnSustainedTime * 100.0F))))
    {
      LCAS_subsystem_integrated_DW.is_UnSafe_jdaq =
        LCAS_subsyst_IN_NO_ACTIVE_CHILD;
      LCAS_subsystem_integrated_DW.is_c12_LCAS_subsystem_integrate =
        LCAS_subsystem_integrat_IN_Safe;
    }
    else if (((uint32_T)LCAS_subsystem_integrated_DW.is_UnSafe_jdaq) ==
             LCAS_subs_IN_Warning_left1level)
    {
      /* Outputs for Atomic SubSystem: '<S1>/LCAS_input_Subsystem' */
      if (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState == true)
      {
        LCAS_subsystem_integrated_DW.is_UnSafe_jdaq =
          LCAS_subs_IN_Warning_left2level;
      }

      /* End of Outputs for SubSystem: '<S1>/LCAS_input_Subsystem' */
    }
    else
    {
      /* Outputs for Atomic SubSystem: '<S1>/LCAS_input_Subsystem' */
      if (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState != true)
      {
        LCAS_subsystem_integrated_DW.is_UnSafe_jdaq =
          LCAS_subs_IN_Warning_left1level;
      }

      /* End of Outputs for SubSystem: '<S1>/LCAS_input_Subsystem' */
    }

    /* RateTransition: '<S2>/Rate Transition' */
    VeLCAS_left_warning_status = LCAS_subsystem_integrated_B.left_warning_status;
  }
  else
  {
    if (LCAS_subsystem_integrated_DW.CalcLLCAEnabledSubsystem_MODE)
    {
      /* Disable for Chart: '<S2>/DtmnWarningChart' */
      elapsedTicks_cdpc = LCAS_subsystem_integrated_M->Timing.clockTick0 -
        LCAS_subsystem_integrated_DW.previousTicks_mdx3;
      LCAS_subsystem_integrated_DW.previousTicks_mdx3 =
        LCAS_subsystem_integrated_M->Timing.clockTick0;

      /* Chart: '<S2>/DtmnWarningChart' */
      LCAS_subsystem_integrated_DW.temporalCounter_i1_hmm3 += elapsedTicks_cdpc;
      LCAS_subsystem_integrated_DW.CalcLLCAEnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/CalcLLCAEnabledSubsystem' */

  /* Outputs for Enabled SubSystem: '<S1>/CalcRLCAEnabledSubsystem' incorporates:
   *  EnablePort: '<S3>/RLCWEnable'
   */
  if (LCAS_subsystem_integrated_B.enable)
  {
    if (!LCAS_subsystem_integrated_DW.CalcRLCAEnabledSubsystem_MODE)
    {
      /* SystemReset for Chart: '<S3>/DtmnWarningChart' */
      LCAS_subsystem_integrated_DW.is_UnSafe = LCAS_subsyst_IN_NO_ACTIVE_CHILD;
      LCAS_subsystem_integrated_DW.temporalCounter_i1 = 0U;

      /* Chart: '<S3>/DtmnWarningChart' */
      LCAS_subsystem_integrated_DW.is_c4_LCAS_subsystem_integrated =
        LCAS_subsystem_integrat_IN_Safe;

      /* Enable for Chart: '<S3>/DtmnWarningChart' */
      LCAS_subsystem_integrated_DW.previousTicks =
        LCAS_subsystem_integrated_M->Timing.clockTick0;
      LCAS_subsystem_integrated_DW.CalcRLCAEnabledSubsystem_MODE = true;
    }

    /* MATLAB Function: '<S3>/CalcRCVWFunction' incorporates:
     *  BusCreator: '<S18>/Bus Creator'
     *  Constant: '<S18>/Constant11'
     *  Constant: '<S18>/Constant12'
     *  Constant: '<S18>/Constant2'
     *  Constant: '<S18>/Constant3'
     *  Constant: '<S18>/Constant4'
     *  Constant: '<S18>/Constant5'
     */
    CVW = 4U;
    LCAS_subsystem_integrated_B.cvwR_ID = 0;

    /* Outputs for Atomic SubSystem: '<S1>/LCAS_input_Subsystem' */
    rtb_curvature = KfLCAS_d_CVZone_FrontDis;
    CV_front2 = KfLCAS_d_CVLargerZone_FrontDis;
    CV_near1 = KfLCAS_d_CVZone_NearDis;
    CV_near2 = KfLCAS_d_CVLargerZone_NearDis;
    CV_far1 = KfLCAS_d_CVZone_FarDis;
    loop_ub = (int32_T)KfLCAS_d_CVLargerZone_FarDis;
    if (((((KfLCAS_d_CVZone_FrontDis > 3.0F) || (KfLCAS_d_CVZone_FrontDis < 0.0F))
          || (KfLCAS_d_CVLargerZone_FrontDis > 3.0F)) ||
         (KfLCAS_d_CVLargerZone_FrontDis < 0.0F)) ||
        (KfLCAS_d_CVLargerZone_FrontDis >= KfLCAS_d_CVZone_FrontDis))
    {
      rtb_curvature = 2.0F;
      CV_front2 = 1.0F;
    }

    if (((((KfLCAS_d_CVZone_NearDis < 0.0F) || (KfLCAS_d_CVZone_NearDis > 0.5F))
          || (KfLCAS_d_CVLargerZone_NearDis < 0.0F)) ||
         (KfLCAS_d_CVLargerZone_NearDis > 0.5F)) ||
        (KfLCAS_d_CVLargerZone_NearDis >= KfLCAS_d_CVZone_NearDis))
    {
      CV_near1 = 0.3F;
      CV_near2 = 0.1F;
    }

    if (((((KfLCAS_d_CVZone_FarDis < 3.0F) || (KfLCAS_d_CVZone_FarDis > 6.0F)) ||
          (KfLCAS_d_CVLargerZone_FarDis < 3)) || (KfLCAS_d_CVLargerZone_FarDis >
          6)) || (((real32_T)KfLCAS_d_CVLargerZone_FarDis) <=
                  KfLCAS_d_CVZone_FarDis))
    {
      CV_far1 = 4.0F;
      loop_ub = 5;
    }

    /* End of Outputs for SubSystem: '<S1>/LCAS_input_Subsystem' */
    if (!((LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] == 0) ||
          (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[1] == 0)))
    {
      if (((int32_T)LCAS_subsystem_integrated_B.num_R) <
          LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0])
      {
        b = LCAS_subsystem_integrated_B.num_R;
      }
      else
      {
        b = (uint16_T)LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0];
      }

      i = 1U;
      exitg1 = false;
      while ((!exitg1) && (i <= b))
      {
        x = LCAS_subsystem_integrated_B.vec_R[(((int32_T)i) +
          (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 8)) - 1]
          - KfLCAS_d_VehCenterFront;
        y = LCAS_subsystem_integrated_B.vec_R[(((int32_T)i) +
          (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 9)) - 1];
        if (LCAS_subsystem_integrated_B.vec_R[(((int32_T)i) +
             (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 10)) -
            1] < (-KfLCAS_v_LatSpdThr))
        {
          y = LCAS_subsystem_integrated_B.vec_R[(((int32_T)i) +
            (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 9)) - 1]
            - (LCAS_subsystem_integrated_B.vec_R[(((int32_T)i) +
                (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6))
               - 1] * KfLCAS_r_ObtWidthProportion);
        }

        if (LCAS_subsystem_integrated_B.vec_R[(((int32_T)i) +
             (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 10)) -
            1] > KfLCAS_v_LatSpdThr)
        {
          y += LCAS_subsystem_integrated_B.vec_R[(((int32_T)i) +
            (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6)) - 1]
            * KfLCAS_r_ObtWidthProportion;
        }

        ttc = 100.0F;
        if (((real_T)LCAS_subsystem_integrated_B.vec_R[(((int32_T)i) +
              (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 4)) -
             1]) > 0.001)
        {
          x_0[0] = x + KfLCAS_d_VehLenth;
          x_0[1] = y;
          ttc = norm_TbqwX7rn(x_0) / LCAS_subsystem_integrated_B.vec_R
            [(((int32_T)i) +
              (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 4)) -
            1];
        }

        if ((((x < ((-rtb_curvature) - KfLCAS_d_VehLenth)) && (y > ((-CV_far1) -
                (KfLCAS_d_VehWidth * 0.5F)))) && (y < ((-CV_near1) -
               (KfLCAS_d_VehWidth * 0.5F)))) && (ttc < KfLCAS_t_TTCThrshLowLevel))
        {
          CVW = 1U;
          rtb_curvature = rt_roundf(LCAS_subsystem_integrated_B.vec_R[((int32_T)
            i) - 1]);
          if (rtb_curvature < 2.14748365E+9F)
          {
            if (rtb_curvature >= -2.14748365E+9F)
            {
              LCAS_subsystem_integrated_B.cvwR_ID = (int32_T)rtb_curvature;
            }
            else
            {
              LCAS_subsystem_integrated_B.cvwR_ID = MIN_int32_T;
            }
          }
          else
          {
            LCAS_subsystem_integrated_B.cvwR_ID = MAX_int32_T;
          }

          exitg1 = true;
        }
        else
        {
          i = (uint16_T)(((uint32_T)i) + 1U);
        }
      }

      if (((int32_T)CVW) != 1)
      {
        if (((int32_T)LCAS_subsystem_integrated_B.num_R) <
            LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0])
        {
          num_L = LCAS_subsystem_integrated_B.num_R;
        }
        else
        {
          num_L = (uint16_T)
            LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0];
        }

        num_R = 1U;
        exitg1 = false;
        while ((!exitg1) && (num_R <= num_L))
        {
          x = LCAS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
            (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 8)) - 1]
            - KfLCAS_d_VehCenterFront;
          y = LCAS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
            (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 9)) - 1];
          if (LCAS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
               (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 10))
              - 1] < (-KfLCAS_v_LatSpdThr))
          {
            y = LCAS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
              (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 9)) -
              1] - (LCAS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
                     (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] *
                      6)) - 1] * KfLCAS_r_ObtWidthProportion);
          }

          if (LCAS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
               (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 10))
              - 1] > KfLCAS_v_LatSpdThr)
          {
            y += LCAS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
              (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 6)) -
              1] * KfLCAS_r_ObtWidthProportion;
          }

          ttc = 100.0F;
          if (((real_T)LCAS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
                (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 4))
               - 1]) > 0.001)
          {
            x_0[0] = x + KfLCAS_d_VehLenth;
            x_0[1] = y;
            ttc = norm_TbqwX7rn(x_0) / LCAS_subsystem_integrated_B.vec_R
              [(((int32_T)num_R) +
                (LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 4))
              - 1];
          }

          if ((((x < ((-CV_front2) - KfLCAS_d_VehLenth)) && (y > ((-((real32_T)
                    loop_ub)) - (KfLCAS_d_VehWidth * 0.5F)))) && (y <
                ((-CV_near2) - (KfLCAS_d_VehWidth * 0.5F)))) && (ttc <
               KfLCAS_t_TTCLargerThrsh_LowLevel))
          {
            CVW = 2U;
            rtb_curvature = rt_roundf(LCAS_subsystem_integrated_B.vec_R
              [((int32_T)num_R) - 1]);
            if (rtb_curvature < 2.14748365E+9F)
            {
              if (rtb_curvature >= -2.14748365E+9F)
              {
                LCAS_subsystem_integrated_B.cvwR_ID = (int32_T)rtb_curvature;
              }
              else
              {
                LCAS_subsystem_integrated_B.cvwR_ID = MIN_int32_T;
              }
            }
            else
            {
              LCAS_subsystem_integrated_B.cvwR_ID = MAX_int32_T;
            }

            exitg1 = true;
          }
          else
          {
            num_R = (uint16_T)(((uint32_T)num_R) + 1U);
          }
        }
      }
    }

    /* Gain: '<S3>/Gain1' */
    ViLCAS_cvwR_ID = mul_s32_loSR(1073741824,
      LCAS_subsystem_integrated_B.cvwR_ID, 30U);

    /* Gain: '<S3>/Gain4' incorporates:
     *  MATLAB Function: '<S3>/CalcRCVWFunction'
     */
    ViLCAS_cvwR = (uint8_T)((((uint32_T)((uint8_T)128U)) * ((uint32_T)CVW)) >> 7);

    /* Chart: '<S3>/DtmnWarningChart' incorporates:
     *  Constant: '<S18>/Constant8'
     *  Constant: '<S22>/Constant'
     *  Inport: '<Root>/VsCOMM_CANR_Databus'
     *  MATLAB Function: '<S3>/CalcRCVWFunction'
     *  RelationalOperator: '<S22>/Compare'
     */
    if (((uint32_T)LCAS_subsystem_integrated_DW.is_c4_LCAS_subsystem_integrated)
        == LCAS_subsystem_integrat_IN_Safe)
    {
      LCAS_subsystem_integrated_B.right_warning_status = LCAS_NO_WARNING;
    }
    else if (((uint32_T)LCAS_subsystem_integrated_DW.is_UnSafe) ==
             LCAS_subsystem_IN_Warning1level)
    {
      LCAS_subsystem_integrated_B.right_warning_status = LCAS_WARNING_LOW_LEVEL;
    }
    else
    {
      LCAS_subsystem_integrated_B.right_warning_status = LCAS_WARNING_HIGH_LEVEL;
    }

    elapsedTicks_cdpc = LCAS_subsystem_integrated_M->Timing.clockTick0 -
      LCAS_subsystem_integrated_DW.previousTicks;
    LCAS_subsystem_integrated_DW.previousTicks =
      LCAS_subsystem_integrated_M->Timing.clockTick0;
    LCAS_subsystem_integrated_DW.temporalCounter_i1 += elapsedTicks_cdpc;
    if (((uint32_T)LCAS_subsystem_integrated_DW.is_c4_LCAS_subsystem_integrated)
        == LCAS_subsystem_integrat_IN_Safe)
    {
      if (((uint32_T)CVW) == WARNING_S_AREA)
      {
        LCAS_subsystem_integrated_DW.is_c4_LCAS_subsystem_integrated =
          LCAS_subsystem_integr_IN_UnSafe;
        LCAS_subsystem_integrated_DW.temporalCounter_i1 = 0U;
        LCAS_subsystem_integrated_DW.is_UnSafe = LCAS_subsystem_IN_Warning1level;
      }
    }
    else if ((((((uint32_T)CVW) != WARNING_S_AREA) && (((uint32_T)CVW) !=
                WARNING_L_AREA)) && (((real32_T)
                LCAS_subsystem_integrated_DW.temporalCounter_i1) >=
               (KfLCAS_t_WarnSustainedTime * 100.0F))) || ((((uint32_T)CVW) ==
               NO_WARNING_AREA) && (((real32_T)
                LCAS_subsystem_integrated_DW.temporalCounter_i1) >=
               (KfLCAS_t_WarnSustainedTime * 100.0F))))
    {
      LCAS_subsystem_integrated_DW.is_UnSafe = LCAS_subsyst_IN_NO_ACTIVE_CHILD;
      LCAS_subsystem_integrated_DW.is_c4_LCAS_subsystem_integrated =
        LCAS_subsystem_integrat_IN_Safe;
    }
    else if (((uint32_T)LCAS_subsystem_integrated_DW.is_UnSafe) ==
             LCAS_subsystem_IN_Warning1level)
    {
      /* Outputs for Atomic SubSystem: '<S1>/LCAS_input_Subsystem' */
      if (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState == true)
      {
        LCAS_subsystem_integrated_DW.is_UnSafe = LCAS_subsystem_IN_Warning2level;
      }

      /* End of Outputs for SubSystem: '<S1>/LCAS_input_Subsystem' */
    }
    else
    {
      /* Outputs for Atomic SubSystem: '<S1>/LCAS_input_Subsystem' */
      if (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState != true)
      {
        LCAS_subsystem_integrated_DW.is_UnSafe = LCAS_subsystem_IN_Warning1level;
      }

      /* End of Outputs for SubSystem: '<S1>/LCAS_input_Subsystem' */
    }

    /* RateTransition: '<S3>/Rate Transition' */
    VeLCAS_right_warning_status =
      LCAS_subsystem_integrated_B.right_warning_status;
  }
  else
  {
    if (LCAS_subsystem_integrated_DW.CalcRLCAEnabledSubsystem_MODE)
    {
      /* Disable for Chart: '<S3>/DtmnWarningChart' */
      elapsedTicks_cdpc = LCAS_subsystem_integrated_M->Timing.clockTick0 -
        LCAS_subsystem_integrated_DW.previousTicks;
      LCAS_subsystem_integrated_DW.previousTicks =
        LCAS_subsystem_integrated_M->Timing.clockTick0;

      /* Chart: '<S3>/DtmnWarningChart' */
      LCAS_subsystem_integrated_DW.temporalCounter_i1 += elapsedTicks_cdpc;
      LCAS_subsystem_integrated_DW.CalcRLCAEnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/CalcRLCAEnabledSubsystem' */

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  Constant: '<S19>/Constant'
   *  Logic: '<S6>/Logical Operator'
   */
  work = ((false) || (!LCAS_subsystem_integrated_B.enable));

  /* Switch: '<S6>/Switch9' incorporates:
   *  Constant: '<S6>/Constant9'
   */
  if (work)
  {
    VsLCAS_DataBus.cvwR_ID = 0;
  }
  else
  {
    VsLCAS_DataBus.cvwR_ID = LCAS_subsystem_integrated_B.cvwR_ID;
  }

  /* End of Switch: '<S6>/Switch9' */

  /* Switch: '<S6>/Switch7' incorporates:
   *  Constant: '<S6>/Constant7'
   */
  if (work)
  {
    VsLCAS_DataBus.cvwL_ID = 0;
  }
  else
  {
    VsLCAS_DataBus.cvwL_ID = LCAS_subsystem_integrated_B.cvwL_ID;
  }

  /* End of Switch: '<S6>/Switch7' */

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S18>/Constant30'
   *  Constant: '<S6>/Constant1'
   */
  if (KbLCAS_configLCA)
  {
    rtb_active_status = LCAS_subsystem_integrated_B.active_status;
  }
  else
  {
    rtb_active_status = LCAS_NONE;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Constant4'
   */
  if (work)
  {
    rtb_left_warning_status = LCAS_NO_WARNING;
  }
  else
  {
    rtb_left_warning_status = LCAS_subsystem_integrated_B.left_warning_status;
  }

  /* End of Switch: '<S6>/Switch4' */

  /* Switch: '<S6>/Switch5' incorporates:
   *  Constant: '<S6>/Constant5'
   */
  if (work)
  {
    rtb_right_warning_status = LCAS_NO_WARNING;
  }
  else
  {
    rtb_right_warning_status = LCAS_subsystem_integrated_B.right_warning_status;
  }

  /* End of Switch: '<S6>/Switch5' */

  /* BusCreator: '<S6>/Bus_Creator' */
  VsLCAS_DataBus.active_status = rtb_active_status;
  VsLCAS_DataBus.left_warning_status = rtb_left_warning_status;
  VsLCAS_DataBus.right_warning_status = rtb_right_warning_status;

  /* RateTransition: '<S6>/Rate Transition1' */
  VeLCAS_right_warning_status_out = rtb_right_warning_status;

  /* RateTransition: '<S6>/Rate Transition' */
  VeLCAS_left_warning_status_out = rtb_left_warning_status;

  /* RateTransition: '<S6>/Rate Transition2' */
  VeLCAS_active_status = rtb_active_status;

  /* End of Outputs for SubSystem: '<Root>/LCAS_Subsystem' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  LCAS_subsystem_integrated_M->Timing.clockTick0++;
  if (!LCAS_subsystem_integrated_M->Timing.clockTick0)
  {
    LCAS_subsystem_integrated_M->Timing.clockTickH0++;
  }
}

/* Model initialize function */
void LCAS_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)LCAS_subsystem_integrated_M, 0,
                sizeof(RT_MODEL_LCAS_subsystem_integ_T));

  /* block I/O */
  (void) memset(((void *) &LCAS_subsystem_integrated_B), 0,
                sizeof(B_LCAS_subsystem_integrated_T));

  {
    LCAS_subsystem_integrated_B.active_status = LCAS_NONE;
    LCAS_subsystem_integrated_B.right_warning_status = LCAS_NO_WARNING;
    LCAS_subsystem_integrated_B.left_warning_status = LCAS_NO_WARNING;
  }

  /* exported global signals */
  VsLCAS_DataBus = LCAS_subsystem_integrated_rtZLCAS_DataBus;
  VfLCAS_curvature = 0.0F;
  VfLCAS_speed_in = 0.0F;

  {
    int32_T i;
    for (i = 0; i < 16; i++)
    {
      VaLCAS_Obt[i] = 0.0F;
    }
  }

  ViLCAS_cvwR_ID = 0;
  ViLCAS_cvwL_ID = 0;
  VnLCAS_num_R = ((uint16_T)0U);
  VnLCAS_num_L = ((uint16_T)0U);
  VfLCAS_gear_in = 0U;
  ViLCAS_cvwR = ((uint8_T)0U);
  ViLCAS_cvwL = ((uint8_T)0U);
  VeLCAS_active_status = LCAS_NONE;
  VeLCAS_right_warning_status_out = LCAS_NO_WARNING;
  VeLCAS_left_warning_status_out = LCAS_NO_WARNING;
  VeLCAS_right_warning_status = LCAS_NO_WARNING;
  VeLCAS_left_warning_status = LCAS_NO_WARNING;

  /* states (dwork) */
  (void) memset((void *)&LCAS_subsystem_integrated_DW, 0,
                sizeof(DW_LCAS_subsystem_integrated_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/LCAS_Subsystem' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/LCAS_input_Subsystem' */
  /* SystemInitialize for Enabled SubSystem: '<S5>/LCAS_CvrtObtVecFunctionEnabled' */
  /* SystemInitialize for Outport: '<S20>/vec_L' */
  LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] = 0;

  /* SystemInitialize for Outport: '<S20>/vec_R' */
  LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] = 0;

  /* SystemInitialize for Outport: '<S20>/vec_L' */
  LCAS_subsystem_integrated_DW.DataTypeConversion_DIMS1[1] = 0;

  /* SystemInitialize for Outport: '<S20>/vec_R' */
  LCAS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[1] = 0;

  /* End of SystemInitialize for SubSystem: '<S5>/LCAS_CvrtObtVecFunctionEnabled' */
  /* End of SystemInitialize for SubSystem: '<S1>/LCAS_input_Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/DtmnLCAEnabledSubsystem' */
  /* SystemInitialize for Chart: '<S4>/DtmnChart' */
  LCAS_subsystem_integrated_DW.is_NoError = LCAS_subsyst_IN_NO_ACTIVE_CHILD;
  LCAS_subsystem_integrated_DW.is_On = LCAS_subsyst_IN_NO_ACTIVE_CHILD;

  /* Chart: '<S4>/DtmnChart' */
  LCAS_subsystem_integrated_DW.is_c3_LCAS_subsystem_integrated =
    LCAS_subsystem_in_IN_SELF_CHECK;

  /* End of SystemInitialize for SubSystem: '<S1>/DtmnLCAEnabledSubsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/CalcLLCAEnabledSubsystem' */
  /* SystemInitialize for Chart: '<S2>/DtmnWarningChart' */
  LCAS_subsystem_integrated_DW.is_UnSafe_jdaq = LCAS_subsyst_IN_NO_ACTIVE_CHILD;
  LCAS_subsystem_integrated_DW.temporalCounter_i1_hmm3 = 0U;
  LCAS_subsystem_integrated_DW.previousTicks_mdx3 = 0U;

  /* Chart: '<S2>/DtmnWarningChart' */
  LCAS_subsystem_integrated_DW.is_c12_LCAS_subsystem_integrate =
    LCAS_subsystem_integrat_IN_Safe;

  /* End of SystemInitialize for SubSystem: '<S1>/CalcLLCAEnabledSubsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/CalcRLCAEnabledSubsystem' */
  /* SystemInitialize for Chart: '<S3>/DtmnWarningChart' */
  LCAS_subsystem_integrated_DW.is_UnSafe = LCAS_subsyst_IN_NO_ACTIVE_CHILD;
  LCAS_subsystem_integrated_DW.temporalCounter_i1 = 0U;
  LCAS_subsystem_integrated_DW.previousTicks = 0U;

  /* Chart: '<S3>/DtmnWarningChart' */
  LCAS_subsystem_integrated_DW.is_c4_LCAS_subsystem_integrated =
    LCAS_subsystem_integrat_IN_Safe;

  /* End of SystemInitialize for SubSystem: '<S1>/CalcRLCAEnabledSubsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/LCAS_Subsystem' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
