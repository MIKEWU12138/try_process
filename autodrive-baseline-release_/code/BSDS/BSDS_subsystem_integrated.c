/*
 * File: BSDS_subsystem_integrated.c
 *
 * Code generated for Simulink model 'BSDS_subsystem_integrated'.
 *
 * Model version                  : 1.461
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Mon Jun  8 17:01:06 2020
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

#include "BSDS_subsystem_integrated.h"
#include "BSDS_subsystem_integrated_private.h"
#include "mul_s32_loSR.h"
#include "repos_fcn_FfRCHIAA.h"
#include "rt_roundf.h"

/* Named constants for Chart: '<S2>/DtmnWarningChart' */
#define BSDS_subs_IN_Warning_left1level ((uint8_T)1U)
#define BSDS_subs_IN_Warning_left2level ((uint8_T)2U)
#define BSDS_subsyst_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define BSDS_subsystem_integr_IN_UnSafe ((uint8_T)2U)
#define BSDS_subsystem_integrat_IN_Safe ((uint8_T)1U)

/* Named constants for Chart: '<S3>/DtmnWarningChart' */
#define BSDS_subsystem_IN_Warning1level ((uint8_T)1U)
#define BSDS_subsystem_IN_Warning2level ((uint8_T)2U)

/* Named constants for Chart: '<S4>/DtmnChart' */
#define BSDS_subsystem_in_IN_SELF_CHECK ((uint8_T)3U)
#define BSDS_subsystem_inte_IN_Inactive ((uint8_T)2U)
#define BSDS_subsystem_integ_IN_NoError ((uint8_T)2U)
#define BSDS_subsystem_integr_IN_Active ((uint8_T)1U)
#define BSDS_subsystem_integra_IN_ERROR ((uint8_T)1U)
#define BSDS_subsystem_integrate_IN_Off ((uint8_T)1U)
#define BSDS_subsystem_integrated_IN_On ((uint8_T)2U)

const BSDS_DataBus BSDS_subsystem_integrated_rtZBSDS_DataBus =
{
  0,                                   /* bswL_ID */
  0,                                   /* bswR_ID */
  BSDS_NONE,                           /* active_status */
  BSDS_NO_WARNING,                     /* left_warning_status */
  BSDS_NO_WARNING                      /* right_warning_status */
} ;                                    /* BSDS_DataBus ground */

/* Exported block signals */
BSDS_DataBus VsBSDS_DataBus;           /* '<S6>/Bus_Creator' */
real32_T VfBSDS_curvature;             /* '<S19>/Gain2' */
real32_T VfBSDS_speed_in;              /* '<S19>/Gain1' */
real32_T VfBSDS_veh_vx;                /* '<S20>/Gain4' */
real32_T VaLCWS_Obt[33];               /* '<S20>/ObserveObtVecFunction2' */
real32_T VaLCWS_x_in[10];              /* '<S20>/ObserveObtVecFunction' */
real32_T VaLCWS_y_in[10];              /* '<S20>/ObserveObtVecFunction' */
real32_T VaLCWS_heading_in[10];        /* '<S20>/ObserveObtVecFunction' */
real32_T VaLCWS_Vx_in[10];             /* '<S20>/ObserveObtVecFunction' */
real32_T VaLCWS_Vy_in[10];             /* '<S20>/ObserveObtVecFunction' */
real32_T VaLCWS_obt_lenth_in[10];      /* '<S20>/ObserveObtVecFunction' */
real32_T VaLCWS_obt_width_in[10];      /* '<S20>/ObserveObtVecFunction' */
real32_T VaLCWS_nearest_point_rel_x_in[10];/* '<S20>/ObserveObtVecFunction' */
real32_T VaLCWS_nearest_point_rel_y_in[10];/* '<S20>/ObserveObtVecFunction' */
int32_T VaLCWS_id_in[10];              /* '<S20>/ObserveObtVecFunction' */
int32_T ViBSDS_bswR_ID;                /* '<S3>/Gain2' */
int32_T ViBSDS_bswL_ID;                /* '<S2>/Gain' */
uint16_T VnLCWS_num_R;                 /* '<S20>/Gain1' */
uint16_T VnLCWS_num_L;                 /* '<S20>/Gain2' */
uint16_T VnLCWS_num_in;                /* '<S20>/Gain3' */
int8_T VaLCWS_position_zone_in[10];    /* '<S20>/ObserveObtVecFunction' */
int8_T VaLCWS_orientation_in[10];      /* '<S20>/ObserveObtVecFunction' */
int8_T VaLCWS_motion_status_in[10];    /* '<S20>/ObserveObtVecFunction' */
uint8_T VfBSDS_gear_in;                /* '<S19>/Gain3' */
uint8_T VaLCWS_type_in[10];            /* '<S20>/ObserveObtVecFunction' */
uint8_T ViBSDS_bswR;                   /* '<S3>/Gain3' */
uint8_T ViBSDS_bswL;                   /* '<S2>/Gain2' */
boolean_T VeBSDS_LturnON;              /* '<S19>/Rate Transition2' */
boolean_T VeBSDS_RturnON;              /* '<S19>/Rate Transition1' */
EnumBSDS_Active_Status VeBSDS_active_status;/* '<S6>/Rate Transition2' */
EnumBSDS_Warning_Status VeBSDS_right_warning_status_out;/* '<S6>/Rate Transition1' */
EnumBSDS_Warning_Status VeBSDS_left_warning_status_out;/* '<S6>/Rate Transition' */
EnumBSDS_Warning_Status VeBSDS_right_warning_status;/* '<S3>/Rate Transition' */
EnumBSDS_Warning_Status VeBSDS_left_warning_status;/* '<S2>/Rate Transition' */
EnumBSDS_warningArea ViBSDS_bswLL;     /* '<S2>/Rate Transition1' */
 #pragma section ".cal" 
/* Exported block parameters */
real32_T KfBSDS_Ang_DisbleStrAngleThrshMax = 3.8F;/* Variable: KfBSDS_Ang_DisbleStrAngleThrshMax
                                                   * Referenced by: '<S18>/Constant12'
                                                   */
real32_T KfBSDS_Ang_EnbleStrAngleThrshMax = 3.14159274F;/* Variable: KfBSDS_Ang_EnbleStrAngleThrshMax
                                                         * Referenced by: '<S18>/Constant11'
                                                         */
real32_T KfBSDS_c_DisbleCurveThrshMax = 0.0125F;/* Variable: KfBSDS_c_DisbleCurveThrshMax
                                                 * Referenced by: '<S18>/Constant20'
                                                 */
real32_T KfBSDS_c_EnbleCurveThrshMax = 0.0111111114F;/* Variable: KfBSDS_c_EnbleCurveThrshMax
                                                      * Referenced by: '<S18>/Constant19'
                                                      */
real32_T KfBSDS_d_BSDLargerZone_BackDis = 6.0F;/* Variable: KfBSDS_d_BSDLargerZone_BackDis
                                                * Referenced by: '<S18>/Constant9'
                                                */
real32_T KfBSDS_d_BSDLargerZone_FarDis = 5.0F;/* Variable: KfBSDS_d_BSDLargerZone_FarDis
                                               * Referenced by: '<S18>/Constant5'
                                               */
real32_T KfBSDS_d_BSDLargerZone_FrontDis = 0.0F;/* Variable: KfBSDS_d_BSDLargerZone_FrontDis
                                                 * Referenced by: '<S18>/Constant7'
                                                 */
real32_T KfBSDS_d_BSDLargerZone_NearDis = 0.0F;/* Variable: KfBSDS_d_BSDLargerZone_NearDis
                                                * Referenced by: '<S18>/Constant3'
                                                */
real32_T KfBSDS_d_BSDZone_BackDis = 5.0F;/* Variable: KfBSDS_d_BSDZone_BackDis
                                          * Referenced by: '<S18>/Constant8'
                                          */
real32_T KfBSDS_d_BSDZone_Eye95Dis = 0.7F;/* Variable: KfBSDS_d_BSDZone_Eye95Dis
                                           * Referenced by: '<S18>/Constant10'
                                           */
real32_T KfBSDS_d_BSDZone_FarDis = 4.0F;/* Variable: KfBSDS_d_BSDZone_FarDis
                                         * Referenced by: '<S18>/Constant4'
                                         */
real32_T KfBSDS_d_BSDZone_FrontDis = 0.7F;/* Variable: KfBSDS_d_BSDZone_FrontDis
                                           * Referenced by: '<S18>/Constant6'
                                           */
real32_T KfBSDS_d_BSDZone_NearDis = 0.3F;/* Variable: KfBSDS_d_BSDZone_NearDis
                                          * Referenced by: '<S18>/Constant2'
                                          */
real32_T KfBSDS_d_VehCenterFront = 3.33F;/* Variable: KfBSDS_d_VehCenterFront
                                          * Referenced by: '<S18>/Constant29'
                                          */
real32_T KfBSDS_d_VehCenterRear = 0.805F;/* Variable: KfBSDS_d_VehCenterRear
                                          * Referenced by: '<S18>/Constant28'
                                          */
real32_T KfBSDS_d_VehLenth = 4.0F;     /* Variable: KfBSDS_d_VehLenth
                                        * Referenced by: '<S18>/Constant'
                                        */
real32_T KfBSDS_d_VehWidth = 2.5F;     /* Variable: KfBSDS_d_VehWidth
                                        * Referenced by: '<S18>/Constant1'
                                        */
real32_T KfBSDS_r_ObtWidthProportion = 0.0F;/* Variable: KfBSDS_r_ObtWidthProportion
                                             * Referenced by: '<S18>/Constant25'
                                             */
real32_T KfBSDS_t_WarnSustainedTime = 2.0F;/* Variable: KfBSDS_t_WarnSustainedTime
                                            * Referenced by: '<S18>/Constant13'
                                            */
real32_T KfBSDS_v_DisbleVehSpdThrshHi = 53.0F;/* Variable: KfBSDS_v_DisbleVehSpdThrshHi
                                               * Referenced by: '<S18>/Constant27'
                                               */
real32_T KfBSDS_v_DisbleVehSpdThrshLo = -2.0F;/* Variable: KfBSDS_v_DisbleVehSpdThrshLo
                                               * Referenced by: '<S18>/Constant18'
                                               */
real32_T KfBSDS_v_EnbleVehSpdThrshHi = 50.0F;/* Variable: KfBSDS_v_EnbleVehSpdThrshHi
                                              * Referenced by: '<S18>/Constant26'
                                              */
real32_T KfBSDS_v_EnbleVehSpdThrshLo = -1.0F;/* Variable: KfBSDS_v_EnbleVehSpdThrshLo
                                              * Referenced by: '<S18>/Constant17'
                                              */
real32_T KfBSDS_v_LatSpdThr = 20.0F;   /* Variable: KfBSDS_v_LatSpdThr
                                        * Referenced by: '<S18>/Constant24'
                                        */
real32_T KfBSDS_v_OncomRelSpdThrshHi_in = 4.0F;/* Variable: KfBSDS_v_OncomRelSpdThrshHi_in
                                                * Referenced by: '<S18>/Constant22'
                                                */
real32_T KfBSDS_v_OncomRelSpdThrshHi_out = 5.0F;/* Variable: KfBSDS_v_OncomRelSpdThrshHi_out
                                                 * Referenced by: '<S18>/Constant23'
                                                 */
real32_T KfBSDS_v_staticSpdThr = 1.0F; /* Variable: KfBSDS_v_staticSpdThr
                                        * Referenced by: '<S18>/Constant14'
                                        */
boolean_T KbBSDS_Sensor_Error = 0;     /* Variable: KbBSDS_Sensor_Error
                                        * Referenced by: '<S4>/Constant28'
                                        */
boolean_T KbBSDS_Sensor_Work = 1;      /* Variable: KbBSDS_Sensor_Work
                                        * Referenced by: '<S4>/Constant3'
                                        */
boolean_T KbBSDS_Switch = 0;           /* Variable: KbBSDS_Switch
                                        * Referenced by: '<S18>/Constant21'
                                        */
boolean_T KbBSDS_configBSD = 0;        /* Variable: KbBSDS_configBSD
                                        * Referenced by: '<S18>/Constant30'
                                        */
boolean_T KbBSDS_curve = 0;            /* Variable: KbBSDS_curve
                                        * Referenced by: '<S19>/Constant28'
                                        */
 #pragma section 
/* Block signals (auto storage) */
B_BSDS_subsystem_integrated_T BSDS_subsystem_integrated_B;

/* Block states (auto storage) */
DW_BSDS_subsystem_integrated_T BSDS_subsystem_integrated_DW;

/* Real-time model */
RT_MODEL_BSDS_subsystem_integ_T BSDS_subsystem_integrated_M_;
RT_MODEL_BSDS_subsystem_integ_T *const BSDS_subsystem_integrated_M =
  &BSDS_subsystem_integrated_M_;

/* Model step function */
void BSDS_subsystem_integrated_step(void)
{
  uint8_T BSW;
  real32_T x;
  real32_T BSD_near1;
  real32_T BSD_near2;
  real32_T BSD_far1;
  real32_T BSD_far2;
  real32_T BSD_front2;
  real32_T BSD_back1;
  real32_T BSD_back2;
  uint16_T num_L;
  uint16_T num_R;
  real32_T vec_L[220];
  real32_T vec_R[220];
  real32_T vec_L_out_data[220];
  real32_T vec_R_out_data[220];
  uint16_T b;
  uint16_T i;
  boolean_T rtb_Compare_dzlo;
  real32_T rtb_curvature;
  real32_T rtb_vec_L_out[220];
  real32_T rtb_vec_R_out[220];
  EnumBSDS_Active_Status rtb_active_status;
  EnumBSDS_Warning_Status rtb_left_warning_status;
  EnumBSDS_Warning_Status rtb_right_warning_status;
  real32_T rtb_KfBSDS_v_LatSpdThr;
  real32_T rtb_KfBSDS_r_ObtWidthProportion;
  real32_T rtb_KfBSDS_d_VehCenterRear;
  boolean_T Compare;
  boolean_T work;
  boolean_T rtb_LogicalOperator_ojv3;
  boolean_T rtb_LogicalOperator2;
  real32_T rtb_curvature_l5cv;
  uint32_T elapsedTicks_cdpc;
  int32_T i_0;
  real32_T tmp_data[11];
  int32_T i_1;
  int32_T vec_L_out_size[2];
  int32_T vec_R_out_size[2];
  int8_T tmp;
  real_T tmp_0;
  boolean_T exitg1;

  /* Outputs for Atomic SubSystem: '<Root>/BSDS_Subsystem' */
  /* Outputs for Atomic SubSystem: '<S1>/input_Subsystem' */
  /* Switch: '<S19>/Switch1' incorporates:
   *  Constant: '<S19>/Constant28'
   *  Constant: '<S19>/Constant4'
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  if (KbBSDS_curve)
  {
    rtb_curvature = VsEGMO_DataBus.motion.curvature;
  }
  else
  {
    rtb_curvature = 0.0F;
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Outputs for Enabled SubSystem: '<S5>/CvrtObtVecFunctionEnabled' incorporates:
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
    if (!BSDS_subsystem_integrated_DW.CvrtObtVecFunctionEnabled_MODE)
    {
      BSDS_subsystem_integrated_DW.CvrtObtVecFunctionEnabled_MODE = true;
    }

    /* MATLAB Function: '<S20>/CvrtObtVecFunction' incorporates:
     *  Constant: '<S18>/Constant14'
     *  Constant: '<S19>/Constant1'
     *  Inport: '<Root>/VsEGMO_DataBus'
     */
    num_L = 0U;
    num_R = 0U;
    BSDS_subsystem_integrated_DW.SFunction_DIMS2[0] = 20;
    BSDS_subsystem_integrated_DW.SFunction_DIMS2[1] = 11;
    BSDS_subsystem_integrated_DW.SFunction_DIMS3[0] = 20;
    BSDS_subsystem_integrated_DW.SFunction_DIMS3[1] = 11;
    memset(&vec_L[0], 0, 220U * (sizeof(real32_T)));
    memset(&vec_R[0], 0, 220U * (sizeof(real32_T)));
    memset(&rtb_vec_L_out[0], 0, 220U * (sizeof(real32_T)));
    memset(&rtb_vec_R_out[0], 0, 220U * (sizeof(real32_T)));
    if (((int32_T)VsOBFU_DataBus.num_obstacles) >= 1)
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
             [((int32_T)i) - 1].velocity_rel.x) > KfBSDS_v_staticSpdThr)
        {
          if ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].nearest_point_rel.x <
               15.0F) && (((int32_T)num_L) < 20))
          {
            tmp_0 = (real_T)((real32_T)fabs((real_T)rtb_curvature));
            if ((tmp_0 > 0.001) || ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
                  nearest_point_rel.y > 0.0F) && (tmp_0 <= 0.001)))
            {
              i_1 = ((int32_T)num_L) + 1;
              if (i_1 < 20)
              {
                num_L = (uint16_T)i_1;
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
                15.0F) && (((int32_T)num_R) < 20)) && ((((real_T)((real32_T)fabs
                  ((real_T)rtb_curvature))) > 0.001) ||
               ((VsOBFU_DataBus.obstacles[((int32_T)i) - 1].nearest_point_rel.y <
                 0.0F) && (((real_T)((real32_T)fabs((real_T)rtb_curvature))) <=
                           0.001))))
          {
            i_1 = ((int32_T)num_R) + 1;
            if (i_1 < 20)
            {
              num_R = (uint16_T)i_1;
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
      BSDS_subsystem_integrated_DW.SFunction_DIMS2[0] = vec_L_out_size[0];
      BSDS_subsystem_integrated_DW.SFunction_DIMS2[1] = vec_L_out_size[1];
      i_0 = vec_L_out_size[0] * vec_L_out_size[1];
      if (0 <= (i_0 - 1))
      {
        memcpy(&rtb_vec_L_out[0], &vec_L_out_data[0], ((uint32_T)i_0) * (sizeof
                (real32_T)));
      }

      BSDS_subsystem_integrated_DW.SFunction_DIMS3[0] = vec_R_out_size[0];
      BSDS_subsystem_integrated_DW.SFunction_DIMS3[1] = vec_R_out_size[1];
      i_0 = vec_R_out_size[0] * vec_R_out_size[1];
      if (0 <= (i_0 - 1))
      {
        memcpy(&rtb_vec_R_out[0], &vec_R_out_data[0], ((uint32_T)i_0) * (sizeof
                (real32_T)));
      }
    }

    BSDS_subsystem_integrated_B.num_L = num_L;
    BSDS_subsystem_integrated_B.num_R = num_R;

    /* End of MATLAB Function: '<S20>/CvrtObtVecFunction' */

    /* DataTypeConversion: '<S20>/Data Type Conversion' */
    BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] =
      BSDS_subsystem_integrated_DW.SFunction_DIMS2[0];
    BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[1] =
      BSDS_subsystem_integrated_DW.SFunction_DIMS2[1];
    i_0 = BSDS_subsystem_integrated_DW.SFunction_DIMS2[0] *
      BSDS_subsystem_integrated_DW.SFunction_DIMS2[1];
    if (0 <= (i_0 - 1))
    {
      memcpy(&BSDS_subsystem_integrated_B.vec_L[0], &rtb_vec_L_out[0],
             ((uint32_T)i_0) * (sizeof(real32_T)));
    }

    /* DataTypeConversion: '<S20>/Data Type Conversion1' incorporates:
     *  DataTypeConversion: '<S20>/Data Type Conversion'
     */
    BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] =
      BSDS_subsystem_integrated_DW.SFunction_DIMS3[0];
    BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[1] =
      BSDS_subsystem_integrated_DW.SFunction_DIMS3[1];
    i_0 = BSDS_subsystem_integrated_DW.SFunction_DIMS3[0] *
      BSDS_subsystem_integrated_DW.SFunction_DIMS3[1];
    if (0 <= (i_0 - 1))
    {
      memcpy(&BSDS_subsystem_integrated_B.vec_R[0], &rtb_vec_R_out[0],
             ((uint32_T)i_0) * (sizeof(real32_T)));
    }

    /* MATLAB Function: '<S20>/ObserveObtVecFunction2' incorporates:
     *  DataTypeConversion: '<S20>/Data Type Conversion1'
     */
    memset(&VaLCWS_Obt[0], 0, 33U * (sizeof(real32_T)));
    if (((int32_T)BSDS_subsystem_integrated_B.num_L) >= 1)
    {
      if (3 < ((int32_T)BSDS_subsystem_integrated_B.num_L))
      {
        b = 3U;
      }
      else
      {
        b = BSDS_subsystem_integrated_B.num_L;
      }

      for (i = 1U; i <= b; i = (uint16_T)(((uint32_T)i) + 1U))
      {
        i_0 = BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[1];
        for (i_1 = 0; i_1 < i_0; i_1++)
        {
          tmp_data[i_1] = BSDS_subsystem_integrated_B.vec_L[(((int32_T)i) +
            (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * i_1)) -
            1];
        }

        for (i_1 = 0; i_1 < 11; i_1++)
        {
          VaLCWS_Obt[(((int32_T)i) + (3 * i_1)) - 1] = tmp_data[i_1];
        }
      }
    }

    /* End of MATLAB Function: '<S20>/ObserveObtVecFunction2' */

    /* Gain: '<S20>/Gain1' */
    VnLCWS_num_R = (uint16_T)((((uint32_T)((uint16_T)32768U)) * ((uint32_T)
      BSDS_subsystem_integrated_B.num_R)) >> 15);

    /* Gain: '<S20>/Gain2' */
    VnLCWS_num_L = (uint16_T)((((uint32_T)((uint16_T)32768U)) * ((uint32_T)
      BSDS_subsystem_integrated_B.num_L)) >> 15);

    /* MATLAB Function: '<S20>/ObserveObtVecFunction' */
    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_position_zone_in[i_0] = 0;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_id_in[i_0] = 0;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_x_in[i_0] = 0.0F;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_y_in[i_0] = 0.0F;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_heading_in[i_0] = 0.0F;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_Vx_in[i_0] = 0.0F;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_Vy_in[i_0] = 0.0F;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_obt_lenth_in[i_0] = 0.0F;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_obt_width_in[i_0] = 0.0F;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_orientation_in[i_0] = 0;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_motion_status_in[i_0] = 0;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_nearest_point_rel_x_in[i_0] = 0.0F;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_nearest_point_rel_y_in[i_0] = 0.0F;
    }

    for (i_0 = 0; i_0 < 10; i_0++)
    {
      VaLCWS_type_in[i_0] = 0U;
    }

    if (((int32_T)VsOBFU_DataBus.num_obstacles) < 10)
    {
      b = VsOBFU_DataBus.num_obstacles;
    }
    else
    {
      b = 10U;
    }

    for (i = 1U; i <= b; i = (uint16_T)(((uint32_T)i) + 1U))
    {
      i_0 = ((int32_T)i) - 1;
      VaLCWS_position_zone_in[i_0] = VsOBFU_DataBus.obstacles[i_0].position_zone;
      VaLCWS_id_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].id;
      VaLCWS_x_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
        center_point_rel.x;
      VaLCWS_y_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
        center_point_rel.y;
      VaLCWS_heading_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
        heading_rel;
      VaLCWS_Vx_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
        velocity_rel.x;
      VaLCWS_Vy_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
        velocity_rel.y;
      VaLCWS_obt_lenth_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
        length;
      VaLCWS_obt_width_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
        width;
      VaLCWS_orientation_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
        motion_orientation;
      VaLCWS_motion_status_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].
        motion_status;
      VaLCWS_nearest_point_rel_x_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i)
        - 1].nearest_point_rel.x;
      VaLCWS_nearest_point_rel_y_in[i_0] = VsOBFU_DataBus.obstacles[((int32_T)i)
        - 1].nearest_point_rel.y;
      tmp = VsOBFU_DataBus.obstacles[((int32_T)i) - 1].type;
      if (tmp < 0)
      {
        tmp = 0;
      }

      VaLCWS_type_in[i_0] = (uint8_T)tmp;
    }

    /* End of MATLAB Function: '<S20>/ObserveObtVecFunction' */

    /* Gain: '<S20>/Gain3' */
    VnLCWS_num_in = (uint16_T)((((uint32_T)((uint16_T)32768U)) * ((uint32_T)
      VsOBFU_DataBus.num_obstacles)) >> 15);

    /* Gain: '<S20>/Gain4' incorporates:
     *  Inport: '<Root>/VsEGMO_DataBus'
     */
    VfBSDS_veh_vx = 1.0F * VsEGMO_DataBus.motion.velocity_rel.x;
  }
  else
  {
    if (BSDS_subsystem_integrated_DW.CvrtObtVecFunctionEnabled_MODE)
    {
      BSDS_subsystem_integrated_DW.CvrtObtVecFunctionEnabled_MODE = false;
    }
  }

  /* End of Logic: '<S19>/Logical Operator1' */
  /* End of Outputs for SubSystem: '<S5>/CvrtObtVecFunctionEnabled' */

  /* Constant: '<S18>/Constant24' */
  rtb_KfBSDS_v_LatSpdThr = KfBSDS_v_LatSpdThr;

  /* Constant: '<S18>/Constant25' */
  rtb_KfBSDS_r_ObtWidthProportion = KfBSDS_r_ObtWidthProportion;

  /* Constant: '<S18>/Constant28' */
  rtb_KfBSDS_d_VehCenterRear = KfBSDS_d_VehCenterRear;

  /* Gain: '<S19>/Gain2' incorporates:
   *  Inport: '<Root>/VsEGMO_DataBus'
   */
  VfBSDS_curvature = 1.0F * VsEGMO_DataBus.motion.curvature;

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

  /* RelationalOperator: '<S21>/Compare' incorporates:
   *  Constant: '<S21>/Constant'
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   */
  Compare = (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_LeftTurningLightState == true);

  /* RateTransition: '<S19>/Rate Transition2' */
  VeBSDS_LturnON = Compare;

  /* RelationalOperator: '<S22>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   */
  rtb_Compare_dzlo = (VsCOMM_CANR_Databus.COMM_RX_BCM.BCM_RightTurningLightState
                      == true);

  /* RateTransition: '<S19>/Rate Transition1' */
  VeBSDS_RturnON = rtb_Compare_dzlo;

  /* Gain: '<S19>/Gain1' incorporates:
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   *  SignalConversion: '<S19>/TmpSignal ConversionAtBus Selector1Outport4'
   */
  VfBSDS_speed_in = 1.0F *
    VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed;

  /* Gain: '<S19>/Gain3' incorporates:
   *  Inport: '<Root>/VsCOMM_CANR_Databus'
   *  SignalConversion: '<S19>/TmpSignal ConversionAtBus Selector1Outport5'
   */
  VfBSDS_gear_in = (uint8_T)((((uint32_T)((uint8_T)128U)) * ((uint32_T)
    VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition)) >> 7);

  /* End of Outputs for SubSystem: '<S1>/input_Subsystem' */

  /* Outputs for Enabled SubSystem: '<S1>/DtmnEnabledSubsystem' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* Constant: '<S18>/Constant30' */
  if (KbBSDS_configBSD)
  {
    if (!BSDS_subsystem_integrated_DW.DtmnEnabledSubsystem_MODE)
    {
      /* SystemReset for Chart: '<S4>/DtmnChart' */
      BSDS_subsystem_integrated_DW.is_NoError = BSDS_subsyst_IN_NO_ACTIVE_CHILD;
      BSDS_subsystem_integrated_DW.is_On = BSDS_subsyst_IN_NO_ACTIVE_CHILD;

      /* Chart: '<S4>/DtmnChart' */
      BSDS_subsystem_integrated_DW.is_c3_BSDS_subsystem_integrated =
        BSDS_subsystem_in_IN_SELF_CHECK;
      BSDS_subsystem_integrated_DW.DtmnEnabledSubsystem_MODE = true;
    }

    /* Logic: '<S4>/Logical Operator4' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Constant: '<S4>/Constant2'
     *  Constant: '<S4>/Constant3'
     */
    work = ((KbBSDS_Sensor_Work && (1.0 != 0.0)) && (1.0 != 0.0));

    /* Chart: '<S4>/DtmnChart' incorporates:
     *  Abs: '<S19>/Abs'
     *  BusCreator: '<S18>/Bus Creator1'
     *  Constant: '<S11>/Constant'
     *  Constant: '<S12>/Constant'
     *  Constant: '<S18>/Constant11'
     *  Constant: '<S18>/Constant12'
     *  Constant: '<S18>/Constant17'
     *  Constant: '<S18>/Constant18'
     *  Constant: '<S18>/Constant19'
     *  Constant: '<S18>/Constant20'
     *  Constant: '<S18>/Constant21'
     *  Constant: '<S18>/Constant26'
     *  Constant: '<S18>/Constant27'
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
    switch (BSDS_subsystem_integrated_DW.is_c3_BSDS_subsystem_integrated)
    {
     case BSDS_subsystem_integra_IN_ERROR:
      BSDS_subsystem_integrated_B.enable = false;
      BSDS_subsystem_integrated_B.active_status = BSDS_ERROR;
      break;

     case BSDS_subsystem_integ_IN_NoError:
      if (((uint32_T)BSDS_subsystem_integrated_DW.is_NoError) ==
          BSDS_subsystem_integrate_IN_Off)
      {
        BSDS_subsystem_integrated_B.enable = false;
        BSDS_subsystem_integrated_B.active_status = BSDS_OFF;
      }
      else if (((uint32_T)BSDS_subsystem_integrated_DW.is_On) ==
               BSDS_subsystem_integr_IN_Active)
      {
        BSDS_subsystem_integrated_B.enable = true;
        BSDS_subsystem_integrated_B.active_status = BSDS_ACTIVE;
      }
      else
      {
        BSDS_subsystem_integrated_B.enable = false;
        BSDS_subsystem_integrated_B.active_status = BSDS_INACTIVE;
      }
      break;

     default:
      BSDS_subsystem_integrated_B.enable = false;
      BSDS_subsystem_integrated_B.active_status = BSDS_SELF_CHECK;
      break;
    }

    switch (BSDS_subsystem_integrated_DW.is_c3_BSDS_subsystem_integrated)
    {
     case BSDS_subsystem_integra_IN_ERROR:
      if ((!((KbBSDS_Sensor_Error || (0.0 != 0.0)) || (0.0 != 0.0))) && work)
      {
        BSDS_subsystem_integrated_DW.is_c3_BSDS_subsystem_integrated =
          BSDS_subsystem_integ_IN_NoError;
        BSDS_subsystem_integrated_DW.is_NoError =
          BSDS_subsystem_integrate_IN_Off;
      }
      break;

     case BSDS_subsystem_integ_IN_NoError:
      if ((!work) || ((KbBSDS_Sensor_Error || (0.0 != 0.0)) || (0.0 != 0.0)))
      {
        BSDS_subsystem_integrated_DW.is_NoError =
          BSDS_subsyst_IN_NO_ACTIVE_CHILD;
        BSDS_subsystem_integrated_DW.is_On = BSDS_subsyst_IN_NO_ACTIVE_CHILD;
        BSDS_subsystem_integrated_DW.is_c3_BSDS_subsystem_integrated =
          BSDS_subsystem_integra_IN_ERROR;
      }
      else if (((uint32_T)BSDS_subsystem_integrated_DW.is_NoError) ==
               BSDS_subsystem_integrate_IN_Off)
      {
        /* Outputs for Atomic SubSystem: '<S1>/input_Subsystem' */
        if ((true) && KbBSDS_Switch)
        {
          BSDS_subsystem_integrated_DW.is_NoError =
            BSDS_subsystem_integrated_IN_On;
          BSDS_subsystem_integrated_DW.is_On = BSDS_subsystem_inte_IN_Inactive;
        }

        /* End of Outputs for SubSystem: '<S1>/input_Subsystem' */
      }
      else
      {
        /* Outputs for Atomic SubSystem: '<S1>/input_Subsystem' */
        if ((!true) || (!KbBSDS_Switch))
        {
          BSDS_subsystem_integrated_DW.is_On = BSDS_subsyst_IN_NO_ACTIVE_CHILD;
          BSDS_subsystem_integrated_DW.is_NoError =
            BSDS_subsystem_integrate_IN_Off;
        }
        else if (((uint32_T)BSDS_subsystem_integrated_DW.is_On) ==
                 BSDS_subsystem_integr_IN_Active)
        {
          if (((((rtb_curvature > KfBSDS_c_DisbleCurveThrshMax) ||
                 (VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed <
                  KfBSDS_v_DisbleVehSpdThrshLo)) ||
                (VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed >
                 KfBSDS_v_DisbleVehSpdThrshHi)) ||
               (VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition
                != ((uint8_T)1U))) || (((real32_T)fabs((real_T)
                 VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle)) >
               KfBSDS_Ang_DisbleStrAngleThrshMax))
          {
            BSDS_subsystem_integrated_DW.is_On = BSDS_subsystem_inte_IN_Inactive;
          }
        }
        else
        {
          if (((((VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed >=
                  KfBSDS_v_EnbleVehSpdThrshLo) &&
                 (VsCOMM_CANR_Databus.COMM_RX_VehicleDynamics.VDC_VehicleSpeed <
                  KfBSDS_v_EnbleVehSpdThrshHi)) &&
                (VsCOMM_CANR_Databus.COMM_RX_Transmission.TCU_ActualGearPosition
                 == ((uint8_T)1U))) && (rtb_curvature <
                KfBSDS_c_EnbleCurveThrshMax)) && (((real32_T)fabs((real_T)
                 VsCOMM_CANR_Databus.COMM_RX_Steering.EPS_ActualSteeringAngle)) <
               KfBSDS_Ang_EnbleStrAngleThrshMax))
          {
            BSDS_subsystem_integrated_DW.is_On = BSDS_subsystem_integr_IN_Active;
          }
        }

        /* End of Outputs for SubSystem: '<S1>/input_Subsystem' */
      }
      break;

     default:
      if ((KbBSDS_Sensor_Error || (0.0 != 0.0)) || (0.0 != 0.0))
      {
        BSDS_subsystem_integrated_DW.is_c3_BSDS_subsystem_integrated =
          BSDS_subsystem_integra_IN_ERROR;
      }
      else
      {
        if (work)
        {
          BSDS_subsystem_integrated_DW.is_c3_BSDS_subsystem_integrated =
            BSDS_subsystem_integ_IN_NoError;
          BSDS_subsystem_integrated_DW.is_NoError =
            BSDS_subsystem_integrate_IN_Off;
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
    rtb_LogicalOperator_ojv3 = ((BSDS_subsystem_integrated_B.num_L != ((uint16_T)
      0U)) || (BSDS_subsystem_integrated_B.num_R != ((uint16_T)0U)));

    /* Logic: '<S4>/Logical Operator2' incorporates:
     *  Constant: '<S15>/Constant'
     *  Constant: '<S16>/Constant'
     *  RelationalOperator: '<S15>/Compare'
     *  RelationalOperator: '<S16>/Compare'
     */
    rtb_LogicalOperator2 = ((BSDS_subsystem_integrated_B.num_L == ((uint16_T)0U))
      && (BSDS_subsystem_integrated_B.num_R == ((uint16_T)0U)));
  }
  else
  {
    if (BSDS_subsystem_integrated_DW.DtmnEnabledSubsystem_MODE)
    {
      BSDS_subsystem_integrated_DW.DtmnEnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/DtmnEnabledSubsystem' */

  /* Outputs for Enabled SubSystem: '<S1>/CalcLBSDEnabledSubsystem' incorporates:
   *  EnablePort: '<S2>/LLCWEnable'
   */
  if (BSDS_subsystem_integrated_B.enable)
  {
    if (!BSDS_subsystem_integrated_DW.CalcLBSDEnabledSubsystem_MODE)
    {
      /* SystemReset for Chart: '<S2>/DtmnWarningChart' */
      BSDS_subsystem_integrated_DW.is_UnSafe_jdaq =
        BSDS_subsyst_IN_NO_ACTIVE_CHILD;
      BSDS_subsystem_integrated_DW.temporalCounter_i1_hmm3 = 0U;

      /* Chart: '<S2>/DtmnWarningChart' */
      BSDS_subsystem_integrated_DW.is_c12_BSDS_subsystem_integrate =
        BSDS_subsystem_integrat_IN_Safe;

      /* Enable for Chart: '<S2>/DtmnWarningChart' */
      BSDS_subsystem_integrated_DW.previousTicks_mdx3 =
        BSDS_subsystem_integrated_M->Timing.clockTick0;
      BSDS_subsystem_integrated_DW.CalcLBSDEnabledSubsystem_MODE = true;
    }

    /* MATLAB Function: '<S2>/Calc_LBSWFunction' incorporates:
     *  BusCreator: '<S18>/Bus Creator'
     *  Constant: '<S18>/Constant10'
     *  Constant: '<S18>/Constant2'
     *  Constant: '<S18>/Constant3'
     *  Constant: '<S18>/Constant4'
     *  Constant: '<S18>/Constant5'
     *  Constant: '<S18>/Constant6'
     *  Constant: '<S18>/Constant7'
     *  Constant: '<S18>/Constant8'
     *  Constant: '<S18>/Constant9'
     */
    BSW = 4U;
    BSDS_subsystem_integrated_B.bswL_ID = 0;

    /* Outputs for Atomic SubSystem: '<S1>/input_Subsystem' */
    rtb_curvature = KfBSDS_d_BSDZone_FrontDis;
    BSD_front2 = KfBSDS_d_BSDLargerZone_FrontDis;
    BSD_near1 = KfBSDS_d_BSDZone_NearDis;
    BSD_near2 = KfBSDS_d_BSDLargerZone_NearDis;
    BSD_far1 = KfBSDS_d_BSDZone_FarDis;
    BSD_far2 = KfBSDS_d_BSDLargerZone_FarDis;
    BSD_back1 = KfBSDS_d_BSDZone_BackDis;
    BSD_back2 = KfBSDS_d_BSDLargerZone_BackDis;
    if (((((KfBSDS_d_BSDZone_FrontDis < 0.0F) || (KfBSDS_d_BSDZone_FrontDis >
            KfBSDS_d_BSDZone_Eye95Dis)) || (KfBSDS_d_BSDLargerZone_FrontDis <
           -1.0F)) || (KfBSDS_d_BSDLargerZone_FrontDis >
                       KfBSDS_d_BSDZone_Eye95Dis)) ||
        (KfBSDS_d_BSDLargerZone_FrontDis >= KfBSDS_d_BSDZone_FrontDis))
    {
      rtb_curvature = 1.0F;
      BSD_front2 = 0.0F;
    }

    if (((((KfBSDS_d_BSDZone_NearDis < -0.5F) || (KfBSDS_d_BSDZone_NearDis >
            0.5F)) || (KfBSDS_d_BSDLargerZone_NearDis < -0.5F)) ||
         (KfBSDS_d_BSDLargerZone_NearDis > 0.5F)) ||
        (KfBSDS_d_BSDLargerZone_NearDis >= KfBSDS_d_BSDZone_NearDis))
    {
      BSD_near1 = 0.3F;
      BSD_near2 = 0.0F;
    }

    if (((((KfBSDS_d_BSDZone_FarDis < 3.0F) || (KfBSDS_d_BSDZone_FarDis > 6.0F))
          || (KfBSDS_d_BSDLargerZone_FarDis < 3.0F)) ||
         (KfBSDS_d_BSDLargerZone_FarDis > 6.0F)) ||
        (KfBSDS_d_BSDLargerZone_FarDis <= KfBSDS_d_BSDZone_FarDis))
    {
      BSD_far1 = 4.0F;
      BSD_far2 = 5.0F;
    }

    if (((((KfBSDS_d_BSDZone_BackDis < 3.0F) || (KfBSDS_d_BSDZone_BackDis >
            30.0F)) || (KfBSDS_d_BSDLargerZone_BackDis < 3.0F)) ||
         (KfBSDS_d_BSDLargerZone_BackDis > 30.0F)) ||
        (KfBSDS_d_BSDLargerZone_BackDis <= KfBSDS_d_BSDZone_BackDis))
    {
      BSD_back1 = 5.0F;
      BSD_back2 = 6.0F;
    }

    /* End of Outputs for SubSystem: '<S1>/input_Subsystem' */
    if (!((BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] == 0) ||
          (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[1] == 0)))
    {
      if (((int32_T)BSDS_subsystem_integrated_B.num_L) <
          BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0])
      {
        b = BSDS_subsystem_integrated_B.num_L;
      }
      else
      {
        b = (uint16_T)BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0];
      }

      i = 1U;
      exitg1 = false;
      while ((!exitg1) && (i <= b))
      {
        x = BSDS_subsystem_integrated_B.vec_L[(((int32_T)i) +
          (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 8)) - 1] -
          KfBSDS_d_VehCenterFront;
        if (((((x > ((-KfBSDS_d_VehLenth) - BSD_back1)) && (x < (-rtb_curvature)))
              && (BSDS_subsystem_integrated_B.vec_L[(((int32_T)i) +
                (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 9))
                  - 1] > (BSD_near1 + (KfBSDS_d_VehWidth * 0.5F)))) &&
             (BSDS_subsystem_integrated_B.vec_L[(((int32_T)i) +
               (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 9)) -
              1] < (BSD_far1 + (KfBSDS_d_VehWidth * 0.5F)))) &&
            ((BSDS_subsystem_integrated_B.vec_L[(((int32_T)i) +
               (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 7)) -
              1] != 1.0F) || ((BSDS_subsystem_integrated_B.vec_L[(((int32_T)i) +
                (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 7))
                               - 1] == 1.0F) && (((real32_T)fabs((real_T)
                 BSDS_subsystem_integrated_B.vec_L[(((int32_T)i) +
                  (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 4))
                 - 1])) < KfBSDS_v_OncomRelSpdThrshHi_in))))
        {
          BSW = 1U;
          rtb_curvature = rt_roundf(BSDS_subsystem_integrated_B.vec_L[((int32_T)
            i) - 1]);
          if (rtb_curvature < 2.14748365E+9F)
          {
            if (rtb_curvature >= -2.14748365E+9F)
            {
              BSDS_subsystem_integrated_B.bswL_ID = (int32_T)rtb_curvature;
            }
            else
            {
              BSDS_subsystem_integrated_B.bswL_ID = MIN_int32_T;
            }
          }
          else
          {
            BSDS_subsystem_integrated_B.bswL_ID = MAX_int32_T;
          }

          exitg1 = true;
        }
        else
        {
          i = (uint16_T)(((uint32_T)i) + 1U);
        }
      }

      if (((int32_T)BSW) != 1)
      {
        if (((int32_T)BSDS_subsystem_integrated_B.num_L) <
            BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0])
        {
          num_L = BSDS_subsystem_integrated_B.num_L;
        }
        else
        {
          num_L = (uint16_T)
            BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0];
        }

        num_R = 1U;
        exitg1 = false;
        while ((!exitg1) && (num_R <= num_L))
        {
          x = BSDS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
            (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 8)) - 1]
            - KfBSDS_d_VehCenterFront;
          if (((((x > ((-KfBSDS_d_VehLenth) - BSD_back2)) && (x < (-BSD_front2)))
                && (BSDS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
                  (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 9))
                    - 1] > (BSD_near2 + (KfBSDS_d_VehWidth * 0.5F)))) &&
               (BSDS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
                 (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 9))
                - 1] < (BSD_far2 + (KfBSDS_d_VehWidth * 0.5F)))) &&
              ((BSDS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
                 (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 7))
                - 1] != 1.0F) || ((BSDS_subsystem_integrated_B.vec_L[(((int32_T)
                   num_R) +
                  (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] * 7))
                 - 1] == 1.0F) && (((real32_T)fabs((real_T)
                   BSDS_subsystem_integrated_B.vec_L[(((int32_T)num_R) +
                    (BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] *
                     4)) - 1])) < KfBSDS_v_OncomRelSpdThrshHi_out))))
          {
            BSW = 2U;
            rtb_curvature = rt_roundf(BSDS_subsystem_integrated_B.vec_L
              [((int32_T)num_R) - 1]);
            if (rtb_curvature < 2.14748365E+9F)
            {
              if (rtb_curvature >= -2.14748365E+9F)
              {
                BSDS_subsystem_integrated_B.bswL_ID = (int32_T)rtb_curvature;
              }
              else
              {
                BSDS_subsystem_integrated_B.bswL_ID = MIN_int32_T;
              }
            }
            else
            {
              BSDS_subsystem_integrated_B.bswL_ID = MAX_int32_T;
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

    /* RateTransition: '<S2>/Rate Transition1' incorporates:
     *  MATLAB Function: '<S2>/Calc_LBSWFunction'
     */
    ViBSDS_bswLL = (EnumBSDS_warningArea)BSW;

    /* Gain: '<S2>/Gain' */
    ViBSDS_bswL_ID = mul_s32_loSR(1073741824,
      BSDS_subsystem_integrated_B.bswL_ID, 30U);

    /* Gain: '<S2>/Gain2' incorporates:
     *  MATLAB Function: '<S2>/Calc_LBSWFunction'
     */
    ViBSDS_bswL = (uint8_T)((((uint32_T)((uint8_T)128U)) * ((uint32_T)BSW)) >> 7);

    /* Chart: '<S2>/DtmnWarningChart' incorporates:
     *  Constant: '<S18>/Constant13'
     *  MATLAB Function: '<S2>/Calc_LBSWFunction'
     */
    if (((uint32_T)BSDS_subsystem_integrated_DW.is_c12_BSDS_subsystem_integrate)
        == BSDS_subsystem_integrat_IN_Safe)
    {
      BSDS_subsystem_integrated_B.left_warning_status = BSDS_NO_WARNING;
    }
    else if (((uint32_T)BSDS_subsystem_integrated_DW.is_UnSafe_jdaq) ==
             BSDS_subs_IN_Warning_left1level)
    {
      BSDS_subsystem_integrated_B.left_warning_status = BSDS_WARNING_LOW_LEVEL;
    }
    else
    {
      BSDS_subsystem_integrated_B.left_warning_status = BSDS_WARNING_HIGH_LEVEL;
    }

    elapsedTicks_cdpc = BSDS_subsystem_integrated_M->Timing.clockTick0 -
      BSDS_subsystem_integrated_DW.previousTicks_mdx3;
    BSDS_subsystem_integrated_DW.previousTicks_mdx3 =
      BSDS_subsystem_integrated_M->Timing.clockTick0;
    BSDS_subsystem_integrated_DW.temporalCounter_i1_hmm3 += elapsedTicks_cdpc;
    if (((uint32_T)BSDS_subsystem_integrated_DW.is_c12_BSDS_subsystem_integrate)
        == BSDS_subsystem_integrat_IN_Safe)
    {
      if (((uint32_T)BSW) == WARNING_S_AREA)
      {
        BSDS_subsystem_integrated_DW.is_c12_BSDS_subsystem_integrate =
          BSDS_subsystem_integr_IN_UnSafe;
        BSDS_subsystem_integrated_DW.temporalCounter_i1_hmm3 = 0U;
        BSDS_subsystem_integrated_DW.is_UnSafe_jdaq =
          BSDS_subs_IN_Warning_left1level;
      }
    }
    else if ((((((uint32_T)BSW) != WARNING_S_AREA) && (((uint32_T)BSW) !=
                WARNING_L_AREA)) && (((real32_T)
                BSDS_subsystem_integrated_DW.temporalCounter_i1_hmm3) >=
               (KfBSDS_t_WarnSustainedTime * 100.0F))) || ((((uint32_T)BSW) ==
               NO_WARNING_AREA) && (((real32_T)
                BSDS_subsystem_integrated_DW.temporalCounter_i1_hmm3) >=
               (KfBSDS_t_WarnSustainedTime * 100.0F))))
    {
      BSDS_subsystem_integrated_DW.is_UnSafe_jdaq =
        BSDS_subsyst_IN_NO_ACTIVE_CHILD;
      BSDS_subsystem_integrated_DW.is_c12_BSDS_subsystem_integrate =
        BSDS_subsystem_integrat_IN_Safe;
    }
    else if (((uint32_T)BSDS_subsystem_integrated_DW.is_UnSafe_jdaq) ==
             BSDS_subs_IN_Warning_left1level)
    {
      if (Compare)
      {
        BSDS_subsystem_integrated_DW.is_UnSafe_jdaq =
          BSDS_subs_IN_Warning_left2level;
      }
    }
    else
    {
      if (!Compare)
      {
        BSDS_subsystem_integrated_DW.is_UnSafe_jdaq =
          BSDS_subs_IN_Warning_left1level;
      }
    }

    /* RateTransition: '<S2>/Rate Transition' */
    VeBSDS_left_warning_status = BSDS_subsystem_integrated_B.left_warning_status;
  }
  else
  {
    if (BSDS_subsystem_integrated_DW.CalcLBSDEnabledSubsystem_MODE)
    {
      /* Disable for Chart: '<S2>/DtmnWarningChart' */
      elapsedTicks_cdpc = BSDS_subsystem_integrated_M->Timing.clockTick0 -
        BSDS_subsystem_integrated_DW.previousTicks_mdx3;
      BSDS_subsystem_integrated_DW.previousTicks_mdx3 =
        BSDS_subsystem_integrated_M->Timing.clockTick0;

      /* Chart: '<S2>/DtmnWarningChart' */
      BSDS_subsystem_integrated_DW.temporalCounter_i1_hmm3 += elapsedTicks_cdpc;
      BSDS_subsystem_integrated_DW.CalcLBSDEnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/CalcLBSDEnabledSubsystem' */

  /* Outputs for Enabled SubSystem: '<S1>/CalcRBSDEnabledSubsystem' incorporates:
   *  EnablePort: '<S3>/RLCWEnable'
   */
  if (BSDS_subsystem_integrated_B.enable)
  {
    if (!BSDS_subsystem_integrated_DW.CalcRBSDEnabledSubsystem_MODE)
    {
      /* SystemReset for Chart: '<S3>/DtmnWarningChart' */
      BSDS_subsystem_integrated_DW.is_UnSafe = BSDS_subsyst_IN_NO_ACTIVE_CHILD;
      BSDS_subsystem_integrated_DW.temporalCounter_i1 = 0U;

      /* Chart: '<S3>/DtmnWarningChart' */
      BSDS_subsystem_integrated_DW.is_c4_BSDS_subsystem_integrated =
        BSDS_subsystem_integrat_IN_Safe;

      /* Enable for Chart: '<S3>/DtmnWarningChart' */
      BSDS_subsystem_integrated_DW.previousTicks =
        BSDS_subsystem_integrated_M->Timing.clockTick0;
      BSDS_subsystem_integrated_DW.CalcRBSDEnabledSubsystem_MODE = true;
    }

    /* MATLAB Function: '<S3>/CalcRBSWFunction' incorporates:
     *  BusCreator: '<S18>/Bus Creator'
     *  Constant: '<S18>/Constant10'
     *  Constant: '<S18>/Constant2'
     *  Constant: '<S18>/Constant3'
     *  Constant: '<S18>/Constant4'
     *  Constant: '<S18>/Constant5'
     *  Constant: '<S18>/Constant6'
     *  Constant: '<S18>/Constant7'
     *  Constant: '<S18>/Constant8'
     *  Constant: '<S18>/Constant9'
     */
    BSW = 4U;
    BSDS_subsystem_integrated_B.bswR_ID = 0;

    /* Outputs for Atomic SubSystem: '<S1>/input_Subsystem' */
    rtb_curvature = KfBSDS_d_BSDZone_FrontDis;
    BSD_front2 = KfBSDS_d_BSDLargerZone_FrontDis;
    BSD_near1 = KfBSDS_d_BSDZone_NearDis;
    BSD_near2 = KfBSDS_d_BSDLargerZone_NearDis;
    BSD_far1 = KfBSDS_d_BSDZone_FarDis;
    BSD_far2 = KfBSDS_d_BSDLargerZone_FarDis;
    BSD_back1 = KfBSDS_d_BSDZone_BackDis;
    BSD_back2 = KfBSDS_d_BSDLargerZone_BackDis;
    if (((((KfBSDS_d_BSDZone_FrontDis < 0.0F) || (KfBSDS_d_BSDZone_FrontDis >
            KfBSDS_d_BSDZone_Eye95Dis)) || (KfBSDS_d_BSDLargerZone_FrontDis <
           -1.0F)) || (KfBSDS_d_BSDLargerZone_FrontDis >
                       KfBSDS_d_BSDZone_Eye95Dis)) ||
        (KfBSDS_d_BSDLargerZone_FrontDis >= KfBSDS_d_BSDZone_FrontDis))
    {
      rtb_curvature = 1.0F;
      BSD_front2 = 0.0F;
    }

    if (((((KfBSDS_d_BSDZone_NearDis < -0.5F) || (KfBSDS_d_BSDZone_NearDis >
            0.5F)) || (KfBSDS_d_BSDLargerZone_NearDis < -0.5F)) ||
         (KfBSDS_d_BSDLargerZone_NearDis > 0.5F)) ||
        (KfBSDS_d_BSDLargerZone_NearDis >= KfBSDS_d_BSDZone_NearDis))
    {
      BSD_near1 = 0.3F;
      BSD_near2 = 0.0F;
    }

    if (((((KfBSDS_d_BSDZone_FarDis < 3.0F) || (KfBSDS_d_BSDZone_FarDis > 6.0F))
          || (KfBSDS_d_BSDLargerZone_FarDis < 3.0F)) ||
         (KfBSDS_d_BSDLargerZone_FarDis > 6.0F)) ||
        (KfBSDS_d_BSDLargerZone_FarDis <= KfBSDS_d_BSDZone_FarDis))
    {
      BSD_far1 = 4.0F;
      BSD_far2 = 5.0F;
    }

    if (((((KfBSDS_d_BSDZone_BackDis < 3.0F) || (KfBSDS_d_BSDZone_BackDis >
            30.0F)) || (KfBSDS_d_BSDLargerZone_BackDis < 3.0F)) ||
         (KfBSDS_d_BSDLargerZone_BackDis > 30.0F)) ||
        (KfBSDS_d_BSDLargerZone_BackDis <= KfBSDS_d_BSDZone_BackDis))
    {
      BSD_back1 = 5.0F;
      BSD_back2 = 6.0F;
    }

    /* End of Outputs for SubSystem: '<S1>/input_Subsystem' */
    if (!((BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] == 0) ||
          (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[1] == 0)))
    {
      if (((int32_T)BSDS_subsystem_integrated_B.num_R) <
          BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0])
      {
        b = BSDS_subsystem_integrated_B.num_R;
      }
      else
      {
        b = (uint16_T)BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0];
      }

      i = 1U;
      exitg1 = false;
      while ((!exitg1) && (i <= b))
      {
        x = BSDS_subsystem_integrated_B.vec_R[(((int32_T)i) +
          (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 8)) - 1]
          - KfBSDS_d_VehCenterFront;
        if (((((x > ((-KfBSDS_d_VehLenth) - BSD_back1)) && (x < (-rtb_curvature)))
              && (BSDS_subsystem_integrated_B.vec_R[(((int32_T)i) +
                (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 9))
                  - 1] > ((-BSD_far1) - (KfBSDS_d_VehWidth * 0.5F)))) &&
             (BSDS_subsystem_integrated_B.vec_R[(((int32_T)i) +
               (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 9))
              - 1] < ((-BSD_near1) - (KfBSDS_d_VehWidth * 0.5F)))) &&
            ((BSDS_subsystem_integrated_B.vec_R[(((int32_T)i) +
               (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 7))
              - 1] != 1.0F) || ((BSDS_subsystem_integrated_B.vec_R[(((int32_T)i)
                + (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 7))
               - 1] == 1.0F) && (((real32_T)fabs((real_T)
                 BSDS_subsystem_integrated_B.vec_R[(((int32_T)i) +
                  (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 4))
                 - 1])) < KfBSDS_v_OncomRelSpdThrshHi_in))))
        {
          BSW = 1U;
          rtb_curvature = rt_roundf(BSDS_subsystem_integrated_B.vec_R[((int32_T)
            i) - 1]);
          if (rtb_curvature < 2.14748365E+9F)
          {
            if (rtb_curvature >= -2.14748365E+9F)
            {
              BSDS_subsystem_integrated_B.bswR_ID = (int32_T)rtb_curvature;
            }
            else
            {
              BSDS_subsystem_integrated_B.bswR_ID = MIN_int32_T;
            }
          }
          else
          {
            BSDS_subsystem_integrated_B.bswR_ID = MAX_int32_T;
          }

          exitg1 = true;
        }
        else
        {
          i = (uint16_T)(((uint32_T)i) + 1U);
        }
      }

      if (((int32_T)BSW) != 1)
      {
        if (((int32_T)BSDS_subsystem_integrated_B.num_R) <
            BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0])
        {
          num_L = BSDS_subsystem_integrated_B.num_R;
        }
        else
        {
          num_L = (uint16_T)
            BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0];
        }

        num_R = 1U;
        exitg1 = false;
        while ((!exitg1) && (num_R <= num_L))
        {
          x = BSDS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
            (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 8)) - 1]
            - KfBSDS_d_VehCenterFront;
          if (((((x > ((-KfBSDS_d_VehLenth) - BSD_back2)) && (x < (-BSD_front2)))
                && (BSDS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
                  (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 9))
                    - 1] > ((-BSD_far2) - (KfBSDS_d_VehWidth * 0.5F)))) &&
               (BSDS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
                 (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 9))
                - 1] < ((-BSD_near2) - (KfBSDS_d_VehWidth * 0.5F)))) &&
              ((BSDS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
                 (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 7))
                - 1] != 1.0F) || ((BSDS_subsystem_integrated_B.vec_R[(((int32_T)
                   num_R) +
                  (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] * 7))
                 - 1] == 1.0F) && (((real32_T)fabs((real_T)
                   BSDS_subsystem_integrated_B.vec_R[(((int32_T)num_R) +
                    (BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] *
                     4)) - 1])) < KfBSDS_v_OncomRelSpdThrshHi_out))))
          {
            BSW = 2U;
            rtb_curvature = rt_roundf(BSDS_subsystem_integrated_B.vec_R
              [((int32_T)num_R) - 1]);
            if (rtb_curvature < 2.14748365E+9F)
            {
              if (rtb_curvature >= -2.14748365E+9F)
              {
                BSDS_subsystem_integrated_B.bswR_ID = (int32_T)rtb_curvature;
              }
              else
              {
                BSDS_subsystem_integrated_B.bswR_ID = MIN_int32_T;
              }
            }
            else
            {
              BSDS_subsystem_integrated_B.bswR_ID = MAX_int32_T;
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

    /* Gain: '<S3>/Gain2' */
    ViBSDS_bswR_ID = mul_s32_loSR(1073741824,
      BSDS_subsystem_integrated_B.bswR_ID, 30U);

    /* Gain: '<S3>/Gain3' incorporates:
     *  MATLAB Function: '<S3>/CalcRBSWFunction'
     */
    ViBSDS_bswR = (uint8_T)((((uint32_T)((uint8_T)128U)) * ((uint32_T)BSW)) >> 7);

    /* Chart: '<S3>/DtmnWarningChart' incorporates:
     *  Constant: '<S18>/Constant13'
     *  DataTypeConversion: '<S3>/Data_Type_Conversion3'
     *  MATLAB Function: '<S3>/CalcRBSWFunction'
     */
    if (((uint32_T)BSDS_subsystem_integrated_DW.is_c4_BSDS_subsystem_integrated)
        == BSDS_subsystem_integrat_IN_Safe)
    {
      BSDS_subsystem_integrated_B.right_warning_status = BSDS_NO_WARNING;
    }
    else if (((uint32_T)BSDS_subsystem_integrated_DW.is_UnSafe) ==
             BSDS_subsystem_IN_Warning1level)
    {
      BSDS_subsystem_integrated_B.right_warning_status = BSDS_WARNING_LOW_LEVEL;
    }
    else
    {
      BSDS_subsystem_integrated_B.right_warning_status = BSDS_WARNING_HIGH_LEVEL;
    }

    elapsedTicks_cdpc = BSDS_subsystem_integrated_M->Timing.clockTick0 -
      BSDS_subsystem_integrated_DW.previousTicks;
    BSDS_subsystem_integrated_DW.previousTicks =
      BSDS_subsystem_integrated_M->Timing.clockTick0;
    BSDS_subsystem_integrated_DW.temporalCounter_i1 += elapsedTicks_cdpc;
    if (((uint32_T)BSDS_subsystem_integrated_DW.is_c4_BSDS_subsystem_integrated)
        == BSDS_subsystem_integrat_IN_Safe)
    {
      if (((uint32_T)BSW) == WARNING_S_AREA)
      {
        BSDS_subsystem_integrated_DW.is_c4_BSDS_subsystem_integrated =
          BSDS_subsystem_integr_IN_UnSafe;
        BSDS_subsystem_integrated_DW.temporalCounter_i1 = 0U;
        BSDS_subsystem_integrated_DW.is_UnSafe = BSDS_subsystem_IN_Warning1level;
      }
    }
    else if ((((((uint32_T)BSW) != WARNING_S_AREA) && (((uint32_T)BSW) !=
                WARNING_L_AREA)) && (((real32_T)
                BSDS_subsystem_integrated_DW.temporalCounter_i1) >=
               (KfBSDS_t_WarnSustainedTime * 100.0F))) || ((((uint32_T)BSW) ==
               NO_WARNING_AREA) && (((real32_T)
                BSDS_subsystem_integrated_DW.temporalCounter_i1) >=
               (KfBSDS_t_WarnSustainedTime * 100.0F))))
    {
      BSDS_subsystem_integrated_DW.is_UnSafe = BSDS_subsyst_IN_NO_ACTIVE_CHILD;
      BSDS_subsystem_integrated_DW.is_c4_BSDS_subsystem_integrated =
        BSDS_subsystem_integrat_IN_Safe;
    }
    else if (((uint32_T)BSDS_subsystem_integrated_DW.is_UnSafe) ==
             BSDS_subsystem_IN_Warning1level)
    {
      if (rtb_Compare_dzlo)
      {
        BSDS_subsystem_integrated_DW.is_UnSafe = BSDS_subsystem_IN_Warning2level;
      }
    }
    else
    {
      if (!rtb_Compare_dzlo)
      {
        BSDS_subsystem_integrated_DW.is_UnSafe = BSDS_subsystem_IN_Warning1level;
      }
    }

    /* RateTransition: '<S3>/Rate Transition' */
    VeBSDS_right_warning_status =
      BSDS_subsystem_integrated_B.right_warning_status;
  }
  else
  {
    if (BSDS_subsystem_integrated_DW.CalcRBSDEnabledSubsystem_MODE)
    {
      /* Disable for Chart: '<S3>/DtmnWarningChart' */
      elapsedTicks_cdpc = BSDS_subsystem_integrated_M->Timing.clockTick0 -
        BSDS_subsystem_integrated_DW.previousTicks;
      BSDS_subsystem_integrated_DW.previousTicks =
        BSDS_subsystem_integrated_M->Timing.clockTick0;

      /* Chart: '<S3>/DtmnWarningChart' */
      BSDS_subsystem_integrated_DW.temporalCounter_i1 += elapsedTicks_cdpc;
      BSDS_subsystem_integrated_DW.CalcRBSDEnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/CalcRBSDEnabledSubsystem' */

  /* Logic: '<S6>/Logical Operator1' incorporates:
   *  Constant: '<S19>/Constant'
   *  Logic: '<S6>/Logical Operator'
   */
  Compare = ((false) || (!BSDS_subsystem_integrated_B.enable));

  /* Switch: '<S6>/Switch8' incorporates:
   *  Constant: '<S6>/Constant8'
   */
  if (Compare)
  {
    VsBSDS_DataBus.bswR_ID = 0;
  }
  else
  {
    VsBSDS_DataBus.bswR_ID = BSDS_subsystem_integrated_B.bswR_ID;
  }

  /* End of Switch: '<S6>/Switch8' */

  /* Switch: '<S6>/Switch6' incorporates:
   *  Constant: '<S6>/Constant6'
   */
  if (Compare)
  {
    VsBSDS_DataBus.bswL_ID = 0;
  }
  else
  {
    VsBSDS_DataBus.bswL_ID = BSDS_subsystem_integrated_B.bswL_ID;
  }

  /* End of Switch: '<S6>/Switch6' */

  /* Switch: '<S6>/Switch1' incorporates:
   *  Constant: '<S18>/Constant30'
   *  Constant: '<S6>/Constant1'
   */
  if (KbBSDS_configBSD)
  {
    rtb_active_status = BSDS_subsystem_integrated_B.active_status;
  }
  else
  {
    rtb_active_status = BSDS_NONE;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Switch: '<S6>/Switch4' incorporates:
   *  Constant: '<S6>/Constant4'
   */
  if (Compare)
  {
    rtb_left_warning_status = BSDS_NO_WARNING;
  }
  else
  {
    rtb_left_warning_status = BSDS_subsystem_integrated_B.left_warning_status;
  }

  /* End of Switch: '<S6>/Switch4' */

  /* Switch: '<S6>/Switch5' incorporates:
   *  Constant: '<S6>/Constant5'
   */
  if (Compare)
  {
    rtb_right_warning_status = BSDS_NO_WARNING;
  }
  else
  {
    rtb_right_warning_status = BSDS_subsystem_integrated_B.right_warning_status;
  }

  /* End of Switch: '<S6>/Switch5' */

  /* BusCreator: '<S6>/Bus_Creator' */
  VsBSDS_DataBus.active_status = rtb_active_status;
  VsBSDS_DataBus.left_warning_status = rtb_left_warning_status;
  VsBSDS_DataBus.right_warning_status = rtb_right_warning_status;

  /* RateTransition: '<S6>/Rate Transition1' */
  VeBSDS_right_warning_status_out = rtb_right_warning_status;

  /* RateTransition: '<S6>/Rate Transition' */
  VeBSDS_left_warning_status_out = rtb_left_warning_status;

  /* RateTransition: '<S6>/Rate Transition2' */
  VeBSDS_active_status = rtb_active_status;

  /* End of Outputs for SubSystem: '<Root>/BSDS_Subsystem' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  BSDS_subsystem_integrated_M->Timing.clockTick0++;
  if (!BSDS_subsystem_integrated_M->Timing.clockTick0)
  {
    BSDS_subsystem_integrated_M->Timing.clockTickH0++;
  }
}

/* Model initialize function */
void BSDS_subsystem_integrated_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)BSDS_subsystem_integrated_M, 0,
                sizeof(RT_MODEL_BSDS_subsystem_integ_T));

  /* block I/O */
  (void) memset(((void *) &BSDS_subsystem_integrated_B), 0,
                sizeof(B_BSDS_subsystem_integrated_T));

  {
    BSDS_subsystem_integrated_B.active_status = BSDS_NONE;
    BSDS_subsystem_integrated_B.right_warning_status = BSDS_NO_WARNING;
    BSDS_subsystem_integrated_B.left_warning_status = BSDS_NO_WARNING;
  }

  /* exported global signals */
  VsBSDS_DataBus = BSDS_subsystem_integrated_rtZBSDS_DataBus;
  VfBSDS_curvature = 0.0F;
  VfBSDS_speed_in = 0.0F;
  VfBSDS_veh_vx = 0.0F;

  {
    int32_T i;
    for (i = 0; i < 33; i++)
    {
      VaLCWS_Obt[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_x_in[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_y_in[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_heading_in[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_Vx_in[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_Vy_in[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_obt_lenth_in[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_obt_width_in[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_nearest_point_rel_x_in[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_nearest_point_rel_y_in[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_id_in[i] = 0;
    }
  }

  ViBSDS_bswR_ID = 0;
  ViBSDS_bswL_ID = 0;
  VnLCWS_num_R = ((uint16_T)0U);
  VnLCWS_num_L = ((uint16_T)0U);
  VnLCWS_num_in = 0U;

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_position_zone_in[i] = 0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_orientation_in[i] = 0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_motion_status_in[i] = 0;
    }
  }

  VfBSDS_gear_in = 0U;

  {
    int32_T i;
    for (i = 0; i < 10; i++)
    {
      VaLCWS_type_in[i] = 0U;
    }
  }

  ViBSDS_bswR = ((uint8_T)0U);
  ViBSDS_bswL = ((uint8_T)0U);
  VeBSDS_LturnON = false;
  VeBSDS_RturnON = false;
  VeBSDS_active_status = BSDS_NONE;
  VeBSDS_right_warning_status_out = BSDS_NO_WARNING;
  VeBSDS_left_warning_status_out = BSDS_NO_WARNING;
  VeBSDS_right_warning_status = BSDS_NO_WARNING;
  VeBSDS_left_warning_status = BSDS_NO_WARNING;
  ViBSDS_bswLL = WARNING_HLEVEL_AREA;

  /* states (dwork) */
  (void) memset((void *)&BSDS_subsystem_integrated_DW, 0,
                sizeof(DW_BSDS_subsystem_integrated_T));

  /* SystemInitialize for Atomic SubSystem: '<Root>/BSDS_Subsystem' */
  /* SystemInitialize for Atomic SubSystem: '<S1>/input_Subsystem' */
  /* SystemInitialize for Enabled SubSystem: '<S5>/CvrtObtVecFunctionEnabled' */
  /* SystemInitialize for Outport: '<S20>/vec_L' */
  BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[0] = 0;

  /* SystemInitialize for Outport: '<S20>/vec_R' */
  BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[0] = 0;

  /* SystemInitialize for Outport: '<S20>/vec_L' */
  BSDS_subsystem_integrated_DW.DataTypeConversion_DIMS1[1] = 0;

  /* SystemInitialize for Outport: '<S20>/vec_R' */
  BSDS_subsystem_integrated_DW.DataTypeConversion1_DIMS1[1] = 0;

  /* End of SystemInitialize for SubSystem: '<S5>/CvrtObtVecFunctionEnabled' */
  /* End of SystemInitialize for SubSystem: '<S1>/input_Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/DtmnEnabledSubsystem' */
  /* SystemInitialize for Chart: '<S4>/DtmnChart' */
  BSDS_subsystem_integrated_DW.is_NoError = BSDS_subsyst_IN_NO_ACTIVE_CHILD;
  BSDS_subsystem_integrated_DW.is_On = BSDS_subsyst_IN_NO_ACTIVE_CHILD;

  /* Chart: '<S4>/DtmnChart' */
  BSDS_subsystem_integrated_DW.is_c3_BSDS_subsystem_integrated =
    BSDS_subsystem_in_IN_SELF_CHECK;

  /* End of SystemInitialize for SubSystem: '<S1>/DtmnEnabledSubsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/CalcLBSDEnabledSubsystem' */
  /* SystemInitialize for Chart: '<S2>/DtmnWarningChart' */
  BSDS_subsystem_integrated_DW.is_UnSafe_jdaq = BSDS_subsyst_IN_NO_ACTIVE_CHILD;
  BSDS_subsystem_integrated_DW.temporalCounter_i1_hmm3 = 0U;
  BSDS_subsystem_integrated_DW.previousTicks_mdx3 = 0U;

  /* Chart: '<S2>/DtmnWarningChart' */
  BSDS_subsystem_integrated_DW.is_c12_BSDS_subsystem_integrate =
    BSDS_subsystem_integrat_IN_Safe;

  /* End of SystemInitialize for SubSystem: '<S1>/CalcLBSDEnabledSubsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S1>/CalcRBSDEnabledSubsystem' */
  /* SystemInitialize for Chart: '<S3>/DtmnWarningChart' */
  BSDS_subsystem_integrated_DW.is_UnSafe = BSDS_subsyst_IN_NO_ACTIVE_CHILD;
  BSDS_subsystem_integrated_DW.temporalCounter_i1 = 0U;
  BSDS_subsystem_integrated_DW.previousTicks = 0U;

  /* Chart: '<S3>/DtmnWarningChart' */
  BSDS_subsystem_integrated_DW.is_c4_BSDS_subsystem_integrated =
    BSDS_subsystem_integrat_IN_Safe;

  /* End of SystemInitialize for SubSystem: '<S1>/CalcRBSDEnabledSubsystem' */
  /* End of SystemInitialize for SubSystem: '<Root>/BSDS_Subsystem' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
